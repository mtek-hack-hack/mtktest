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
 * BrowserSettings.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contain the function definations for logical implementation 
 *   of browser settings.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERSETTINGS_C
#define MMI_BROWSERSETTINGS_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserGprots.h"
#include "BrowserSettings.h"
#include "PushInboxProts.h"
/*  Include: NVRAM header file */
#include "DateTimeGprot.h"


extern U8  gBrwTimeoutValue[(BRW_TIME_OUT_LEN + 1) * ENCODING_LENGTH];
S32 g_brw_preferences[BROWSER_PREFERENCES_ITEM_COUNT];
extern kal_uint8 const WAP_CUSTOM_CFG_DEFAULT_USER_DEFINED_HOMEPAGE[];


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_nvram_data_init
 * DESCRIPTION
 *  Function to read settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_nvram_data_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_settings_read_homepage_settings();
	mmi_brw_settings_read_browser_options();
	mmi_brw_settings_read_browser_preferences();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_read_homepage_settings
 * DESCRIPTION
 *  Function to read settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_read_homepage_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BRW_SETTINGS_HOMEPAGE, &(g_brw_cntx.homepage_settings_index), DS_BYTE, &error);
    if (g_brw_cntx.homepage_settings_index == 0xFF)
    {
        g_brw_cntx.homepage_settings_index = WAP_CUSTOM_CFG_DEFAULT_HOMEPAGE;
        WriteValue(NVRAM_BRW_SETTINGS_HOMEPAGE, &(g_brw_cntx.homepage_settings_index), DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_read_browser_preferences
 * DESCRIPTION
 *  Function to read settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_read_browser_preferences(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BRW_PAGE_TIME_OUT_VALUE, &(g_brw_cntx.timeout_value), DS_SHORT, &error);
    if (g_brw_cntx.timeout_value == 0xFFFF)
    {
        g_brw_cntx.timeout_value = WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT;
        WriteValue(NVRAM_BRW_PAGE_TIME_OUT_VALUE, &(g_brw_cntx.timeout_value), DS_SHORT, &error);
    }

    ReadValue(NVRAM_BRW_SHOW_IMAGE_MODE, &(g_brw_cntx.show_images_status), DS_BYTE, &error);
    if (g_brw_cntx.show_images_status == 0xFF)
    {
        g_brw_cntx.show_images_status = WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGE;
        WriteValue(NVRAM_BRW_SHOW_IMAGE_MODE, &(g_brw_cntx.show_images_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_SHOW_VIDEO, &(g_brw_cntx.show_videos_status), DS_BYTE, &error);
    if (g_brw_cntx.show_videos_status == 0xFF)
    {
        g_brw_cntx.show_videos_status = WAP_CUSTOM_CFG_DEFAULT_SHOW_VIDEO;
        WriteValue(NVRAM_BRW_SETTINGS_SHOW_VIDEO, &(g_brw_cntx.show_videos_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_PLAY_SOUND, &(g_brw_cntx.play_sounds_status), DS_BYTE, &error);
    if (g_brw_cntx.play_sounds_status == 0xFF)
    {
        g_brw_cntx.play_sounds_status = WAP_CUSTOM_CFG_DEFAULT_PLAY_SOUND;
        WriteValue(NVRAM_BRW_SETTINGS_PLAY_SOUND, &(g_brw_cntx.play_sounds_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA, &(g_brw_cntx.load_unknown_media_status), DS_BYTE, &error);
    if (g_brw_cntx.load_unknown_media_status == 0xFF)
    {
        g_brw_cntx.load_unknown_media_status = WAP_CUSTOM_CFG_DEFAULT_LOAD_UNKOWN_MEDIA;
        WriteValue(NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA, &(g_brw_cntx.load_unknown_media_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_CSS, &(g_brw_cntx.css_status), DS_BYTE, &error);
    if (g_brw_cntx.css_status == 0xFF)
    {
        g_brw_cntx.css_status = WAP_CUSTOM_CFG_DEFAULT_CSS;
        WriteValue(NVRAM_BRW_SETTINGS_CSS, &(g_brw_cntx.css_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_SCRIPTS, &(g_brw_cntx.script_status), DS_BYTE, &error);
    if (g_brw_cntx.script_status == 0xFF)
    {
        g_brw_cntx.script_status = WAP_CUSTOM_CFG_DEFAULT_SCRIPTS;
        WriteValue(NVRAM_BRW_SETTINGS_SCRIPTS, &(g_brw_cntx.script_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_CACHE, &(g_brw_cntx.cache_status), DS_BYTE, &error);
    if (g_brw_cntx.cache_status == 0xFF)
    {
        g_brw_cntx.cache_status = WAP_CUSTOM_CFG_DEFAULT_CACHE;
        WriteValue(NVRAM_BRW_SETTINGS_CACHE, &(g_brw_cntx.cache_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_COOKIE, &(g_brw_cntx.cookie_status), DS_BYTE, &error);
    if (g_brw_cntx.cookie_status == 0xFF)
    {
        g_brw_cntx.cookie_status = WAP_CUSTOM_CFG_DEFAULT_COOKIE;
        WriteValue(NVRAM_BRW_SETTINGS_COOKIE, &(g_brw_cntx.cookie_status), DS_BYTE, &error);
    }

#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
    ReadValue(NVRAM_BRW_SETTINGS_SHORTCUTS, &(g_brw_cntx.shortcuts_status), DS_BYTE, &error);
    if (g_brw_cntx.shortcuts_status == 0xFF)
    {
        g_brw_cntx.shortcuts_status = WAP_CUSTOM_CFG_DEFAULT_SHORTCUTS;
        WriteValue(NVRAM_BRW_SETTINGS_SHORTCUTS, &(g_brw_cntx.shortcuts_status), DS_BYTE, &error);
    }
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */

    ReadValue(NVRAM_BRW_SETTINGS_SECURITY_WARNINGS, &(g_brw_cntx.security_warnings_status), DS_BYTE, &error);
    if (g_brw_cntx.security_warnings_status == 0xFF)
    {
        g_brw_cntx.security_warnings_status = WAP_CUSTOM_CFG_DEFAULT_SECURITY_WARNINGS;
        WriteValue(NVRAM_BRW_SETTINGS_SECURITY_WARNINGS, &(g_brw_cntx.security_warnings_status), DS_BYTE, &error);
    }

#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
    ReadValue(NVRAM_BRW_SETTINGS_SEND_DEVICE_ID, &(g_brw_cntx.send_device_id_status), DS_BYTE, &error);
    if (g_brw_cntx.send_device_id_status == 0xFF)
    {
        g_brw_cntx.send_device_id_status = WAP_CUSTOM_CFG_DEFAULT_SEND_DEVICE_ID;
        WriteValue(NVRAM_BRW_SETTINGS_SEND_DEVICE_ID, &(g_brw_cntx.send_device_id_status), DS_BYTE, &error);
    }
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_read_browser_options
 * DESCRIPTION
 *  Function to read settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_read_browser_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BRW_SETTINGS_RENDER_MODE, &(g_brw_cntx.rendering_mode), DS_BYTE, &error);
    if (g_brw_cntx.rendering_mode == 0xFF)
    {
        g_brw_cntx.rendering_mode = WAP_CUSTOM_CFG_DEFAULT_RENDER_MODE;
        WriteValue(NVRAM_BRW_SETTINGS_RENDER_MODE, &(g_brw_cntx.rendering_mode), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_NAVIGATE_MODE, &(g_brw_cntx.navigation_mode), DS_BYTE, &error);
    if (g_brw_cntx.navigation_mode == 0xFF)
    {
        g_brw_cntx.navigation_mode = WAP_CUSTOM_CFG_DEFAULT_NAVIGATE_MODE;
        WriteValue(NVRAM_BRW_SETTINGS_NAVIGATE_MODE, &(g_brw_cntx.navigation_mode), DS_BYTE, &error);
    }

#ifdef  BAM_CFG_SUI_ZOOM_ENABLED
    ReadValue(NVRAM_BRW_SETTINGS_FONT_SIZE, &(g_brw_cntx.font_size), DS_BYTE, &error);
    if (g_brw_cntx.font_size == 0xFF)
    {
        g_brw_cntx.font_size = WAP_CUSTOM_CFG_DEFAULT_FONT_SIZE;
        WriteValue(NVRAM_BRW_SETTINGS_FONT_SIZE, &(g_brw_cntx.font_size), DS_BYTE, &error);
    }
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */

    ReadValue(NVRAM_BRW_SETTINGS_THUMBNAIL, &(g_brw_cntx.thumbnail_status), DS_BYTE, &error);
    if (g_brw_cntx.thumbnail_status == 0xFF)
    {
        g_brw_cntx.thumbnail_status = WAP_CUSTOM_CFG_DEFAULT_THUMBNAIL;
        WriteValue(NVRAM_BRW_SETTINGS_THUMBNAIL, &(g_brw_cntx.thumbnail_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_SCREEN_SIZE, &(g_brw_cntx.screen_size_status), DS_BYTE, &error);
    if (g_brw_cntx.screen_size_status == 0xFF)
    {
        g_brw_cntx.screen_size_status = WAP_CUSTOM_CFG_DEFAULT_SCREEN_SIZE;
        WriteValue(NVRAM_BRW_SETTINGS_SCREEN_SIZE, &(g_brw_cntx.screen_size_status), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX, &(g_brw_cntx.encoding_method_index), DS_BYTE, &error);
    if (g_brw_cntx.encoding_method_index == 0xFF)
    {
        g_brw_cntx.encoding_method_index = WAP_CUSTOM_CFG_DEFAULT_ENCODE_METHOD_INDEX;
        WriteValue(NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX, &(g_brw_cntx.encoding_method_index), DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_preferences_set_default
 * DESCRIPTION
*  Function to set default browser preferences in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_preferences_set_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_brw_cntx.timeout_value = WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT;
    WriteValue(NVRAM_BRW_PAGE_TIME_OUT_VALUE, &(g_brw_cntx.timeout_value), DS_SHORT, &error);

    g_brw_cntx.show_images_status = WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGE;
    WriteValue(NVRAM_BRW_SHOW_IMAGE_MODE, &(g_brw_cntx.show_images_status), DS_BYTE, &error);

    g_brw_cntx.show_videos_status = WAP_CUSTOM_CFG_DEFAULT_SHOW_VIDEO;
    WriteValue(NVRAM_BRW_SETTINGS_SHOW_VIDEO, &(g_brw_cntx.show_videos_status), DS_BYTE, &error);

    g_brw_cntx.play_sounds_status = WAP_CUSTOM_CFG_DEFAULT_PLAY_SOUND;
    WriteValue(NVRAM_BRW_SETTINGS_PLAY_SOUND, &(g_brw_cntx.play_sounds_status), DS_BYTE, &error);

    g_brw_cntx.load_unknown_media_status = WAP_CUSTOM_CFG_DEFAULT_LOAD_UNKOWN_MEDIA;
    WriteValue(NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA, &(g_brw_cntx.load_unknown_media_status), DS_BYTE, &error);

    g_brw_cntx.css_status = WAP_CUSTOM_CFG_DEFAULT_CSS;
    WriteValue(NVRAM_BRW_SETTINGS_CSS, &(g_brw_cntx.css_status), DS_BYTE, &error);

    g_brw_cntx.script_status = WAP_CUSTOM_CFG_DEFAULT_SCRIPTS;
    WriteValue(NVRAM_BRW_SETTINGS_SCRIPTS, &(g_brw_cntx.script_status), DS_BYTE, &error);

    g_brw_cntx.cache_status = WAP_CUSTOM_CFG_DEFAULT_CACHE;
    WriteValue(NVRAM_BRW_SETTINGS_CACHE, &(g_brw_cntx.cache_status), DS_BYTE, &error);

    g_brw_cntx.cookie_status = WAP_CUSTOM_CFG_DEFAULT_COOKIE;
    WriteValue(NVRAM_BRW_SETTINGS_COOKIE, &(g_brw_cntx.cookie_status), DS_BYTE, &error);

#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
    g_brw_cntx.shortcuts_status = WAP_CUSTOM_CFG_DEFAULT_SHORTCUTS;
    WriteValue(NVRAM_BRW_SETTINGS_SHORTCUTS, &(g_brw_cntx.shortcuts_status), DS_BYTE, &error);
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */

    g_brw_cntx.security_warnings_status = WAP_CUSTOM_CFG_DEFAULT_SECURITY_WARNINGS;
    WriteValue(NVRAM_BRW_SETTINGS_SECURITY_WARNINGS, &(g_brw_cntx.security_warnings_status), DS_BYTE, &error);

#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
    g_brw_cntx.send_device_id_status = WAP_CUSTOM_CFG_DEFAULT_SEND_DEVICE_ID;
    WriteValue(NVRAM_BRW_SETTINGS_SEND_DEVICE_ID, &(g_brw_cntx.send_device_id_status), DS_BYTE, &error);
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_options_set_default
 * DESCRIPTION
 *  Function to set default browser options in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_options_set_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_brw_cntx.rendering_mode = WAP_CUSTOM_CFG_DEFAULT_RENDER_MODE;
    WriteValue(NVRAM_BRW_SETTINGS_RENDER_MODE, &(g_brw_cntx.rendering_mode), DS_BYTE, &error);

    g_brw_cntx.navigation_mode = WAP_CUSTOM_CFG_DEFAULT_NAVIGATE_MODE;
    WriteValue(NVRAM_BRW_SETTINGS_NAVIGATE_MODE, &(g_brw_cntx.navigation_mode), DS_BYTE, &error);

#ifdef  BAM_CFG_SUI_ZOOM_ENABLED
    g_brw_cntx.font_size = WAP_CUSTOM_CFG_DEFAULT_FONT_SIZE;
    WriteValue(NVRAM_BRW_SETTINGS_FONT_SIZE, &(g_brw_cntx.font_size), DS_BYTE, &error);
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */

    g_brw_cntx.thumbnail_status = WAP_CUSTOM_CFG_DEFAULT_THUMBNAIL;
    WriteValue(NVRAM_BRW_SETTINGS_THUMBNAIL, &(g_brw_cntx.thumbnail_status), DS_BYTE, &error);

    g_brw_cntx.screen_size_status = WAP_CUSTOM_CFG_DEFAULT_SCREEN_SIZE;
    WriteValue(NVRAM_BRW_SETTINGS_SCREEN_SIZE, &(g_brw_cntx.screen_size_status), DS_BYTE, &error);

    g_brw_cntx.encoding_method_index = WAP_CUSTOM_CFG_DEFAULT_ENCODE_METHOD_INDEX;
    WriteValue(NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX, &(g_brw_cntx.encoding_method_index), DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_homepage_settings
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_homepage_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_SETTINGS_HOMEPAGE, &(g_brw_cntx.homepage_settings_index), DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_rendering_mode_value
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_rendering_mode_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_SETTINGS_RENDER_MODE, &(g_brw_cntx.rendering_mode), DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_navigation_mode_value
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_navigation_mode_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_SETTINGS_NAVIGATE_MODE, &(g_brw_cntx.navigation_mode), DS_BYTE, &error);
}


#ifdef  BAM_CFG_SUI_ZOOM_ENABLED
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_font_size_value
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_font_size_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_SETTINGS_FONT_SIZE, &(g_brw_cntx.font_size), DS_BYTE, &error);
}
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_thumbnail_status
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_thumbnail_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_SETTINGS_THUMBNAIL, &(g_brw_cntx.thumbnail_status), DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_screen_size_status
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_screen_size_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_SETTINGS_SCREEN_SIZE, &(g_brw_cntx.screen_size_status), DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_encoding_method_index
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_encoding_method_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX, &(g_brw_cntx.encoding_method_index), DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_browser_preferences
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_browser_preferences(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_PAGE_TIME_OUT_VALUE, &(g_brw_cntx.timeout_value), DS_SHORT, &error);

    WriteValue(NVRAM_BRW_SHOW_IMAGE_MODE, &(g_brw_cntx.show_images_status), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_SETTINGS_SHOW_VIDEO, &(g_brw_cntx.show_videos_status), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_SETTINGS_PLAY_SOUND, &(g_brw_cntx.play_sounds_status), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA, &(g_brw_cntx.load_unknown_media_status), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_SETTINGS_CSS, &(g_brw_cntx.css_status), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_SETTINGS_SCRIPTS, &(g_brw_cntx.script_status), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_SETTINGS_CACHE, &(g_brw_cntx.cache_status), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_SETTINGS_COOKIE, &(g_brw_cntx.cookie_status), DS_BYTE, &error);

#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
    WriteValue(NVRAM_BRW_SETTINGS_SHORTCUTS, &(g_brw_cntx.shortcuts_status), DS_BYTE, &error);
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */

    WriteValue(NVRAM_BRW_SETTINGS_SECURITY_WARNINGS, &(g_brw_cntx.security_warnings_status), DS_BYTE, &error);

#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
    WriteValue(NVRAM_BRW_SETTINGS_SEND_DEVICE_ID, &(g_brw_cntx.send_device_id_status), DS_BYTE, &error);
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_update_thumbnail_status
 * DESCRIPTION
 *  This function is used for changing the thumbnail status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_update_thumbnail_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_cntx.thumbnail_status)
    {
        g_brw_cntx.thumbnail_status = MMI_FALSE;
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*)GetString(STR_GLOBAL_OFF));
    }
    else
    {
        g_brw_cntx.thumbnail_status = MMI_TRUE;
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*)GetString(STR_GLOBAL_ON));
    }
	RedrawCategoryFunction();
	mmi_brw_settings_write_thumbnail_status();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_thumbnail,
		g_brw_cntx.thumbnail_status,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_update_screen_size
 * DESCRIPTION
 *  This function is used for changing the screen size value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_update_screen_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_cntx.screen_size_status)
    {
        g_brw_cntx.screen_size_status = MMI_FALSE;
        ChangeLeftSoftkey(STR_ID_BRW_FULL, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*)GetString(STR_ID_BRW_NORMAL));
    }
    else
    {
        g_brw_cntx.screen_size_status = MMI_TRUE;
        ChangeLeftSoftkey(STR_ID_BRW_NORMAL, 0);
        mmi_ucs2cpy((S8*) hintData[GetHighlightedItem()], (S8*)GetString(STR_ID_BRW_FULL));
    }
	RedrawCategoryFunction();
	mmi_brw_settings_write_screen_size_status();
	mmi_brw_settings_resize_screen_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_cache
 * DESCRIPTION
 *  This function is used for clearing the cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_settings_clear_data_req(WPS_CLEAR_CACHE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_cookie
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_cookie(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_settings_clear_data_req(WPS_CLEAR_COOKIES_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_auth_info
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_auth_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_settings_clear_data_req(WPS_CLEAR_AUTH_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_activate
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.homepage_settings_index = BRW_USER_DEFINED_HOMEPAGE;
	
	mmi_brw_settings_write_homepage_settings();

	DeleteUptoScrID(SCR_ID_BRW_HOMEPAGE_SETTINGS);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        (U16) IMG_GLOBAL_ACTIVATED,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) (SUCCESS_TONE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_activate
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.homepage_settings_index = BRW_ACTIVE_PROFILE_HOMEPAGE;
	
	mmi_brw_settings_write_homepage_settings();

	DeleteUptoScrID(SCR_ID_BRW_HOMEPAGE_SETTINGS);

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        (U16) IMG_GLOBAL_ACTIVATED,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) (SUCCESS_TONE));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_set_current_page_as_user_defined_homepage
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_set_current_page_as_user_defined_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.document_info_p)
	{
		mmi_brw_settings_set_user_defined_homepage((U8*)g_brw_cntx.document_info_p->url);
	}
	else
	{
		mmi_brw_settings_set_user_defined_homepage(NULL);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_set_blank_as_user_defined_homepage
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_set_blank_as_user_defined_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_settings_set_user_defined_homepage((U8*) BRW_BLANK_HOMEPAGE_URL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_push_settings
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_push_settings(void)
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
 *  mmi_brw_settings_rendering_modes_standard
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_standard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.rendering_mode = wap_bam_setting_val_rend_normal;
    mmi_brw_settings_write_rendering_mode_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_rendering,
		g_brw_cntx.rendering_mode,NULL);
	if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
	}
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_text_wrap
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_text_wrap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.rendering_mode = wap_bam_setting_val_rend_wrap;
    mmi_brw_settings_write_rendering_mode_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_rendering,
		g_brw_cntx.rendering_mode,NULL);
	if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
	}
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_screen_optimized
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_screen_optimized(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.rendering_mode = wap_bam_setting_val_rend_narrow;
    mmi_brw_settings_write_rendering_mode_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_rendering,
		g_brw_cntx.rendering_mode,NULL);
	if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
	}
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_text_only
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_text_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.rendering_mode = wap_bam_setting_val_rend_text;
    mmi_brw_settings_write_rendering_mode_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_rendering,
		g_brw_cntx.rendering_mode,NULL);
	if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
	}
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_four_way
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_four_way(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.navigation_mode = wap_bam_setting_val_nav_4_way;
    mmi_brw_settings_write_navigation_mode_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_navigation,
		g_brw_cntx.navigation_mode,NULL);
	if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
	}
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_two_way
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_two_way(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.navigation_mode = wap_bam_setting_val_nav_2_way;
    mmi_brw_settings_write_navigation_mode_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_navigation,
		g_brw_cntx.navigation_mode,NULL);
	if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
	}
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_scrolling
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_scrolling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.navigation_mode = wap_bam_setting_val_nav_scroll;
    mmi_brw_settings_write_navigation_mode_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_navigation,
		g_brw_cntx.navigation_mode,NULL);
	if(IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		DeleteUptoScrID(SCR_ID_BRW_BROWSER_MAIN);
	}
    GoBackHistory();
}


#ifdef  BAM_CFG_SUI_ZOOM_ENABLED
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_small
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_small(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.font_size = BRW_FONT_SIZE_SMALL;
    mmi_brw_settings_write_font_size_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_zoom,
		g_brw_cntx.font_size,NULL);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_medium
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_medium(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.font_size = BRW_FONT_SIZE_MEDIUM;
    mmi_brw_settings_write_font_size_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_zoom,
		g_brw_cntx.font_size,NULL);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_large
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_large(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.font_size = BRW_FONT_SIZE_LARGE;
    mmi_brw_settings_write_font_size_value();
	mmi_brw_settings_change_setting_value_req(wap_bam_setting_value_type_int, wap_bam_setting_id_zoom,
		g_brw_cntx.font_size,NULL);
    GoBackHistory();
}
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_update_encoding_method
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_update_encoding_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.encoding_method_index = GetHighlightedItem();
	mmi_brw_settings_write_encoding_method_index();
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_preferences_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_preferences_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DeleteScreenIfPresent(SCR_ID_BRW_BROWSER_PREFERENCES);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_show_profile_list
 * DESCRIPTION
 *  To display the profile list
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_show_profile_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_prof_pre_entry_show_profile_list_menu(BRW_PROF_BROWSER_PROFILE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_preferences_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_preferences_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16	time_out_val;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	time_out_val = mmi_brw_convert_unicode_string_to_int(gBrwTimeoutValue);

    if (time_out_val < BRW_TIME_OUT_MIN_VAL || time_out_val > BRW_TIME_OUT_MAX_VAL)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_BRW_INVAL_TIMEOUT),
            (U16) IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) (ERROR_TONE));
        return;
    }
    g_brw_cntx.timeout_value = time_out_val;

	mmi_brw_settings_browser_preferences_read_inline_struct();
	mmi_brw_settings_write_browser_preferences();

	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_PREFERENCES);
	mmi_brw_entry_browser_busy_screen();

	g_brw_cntx.brw_launching_pad = BRW_LPD_SETTINGS_PREF;
	mmi_brw_settings_set_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_restore_browser_settings
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_restore_browser_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_SETTINGS);
	mmi_brw_entry_browser_busy_screen();

	mmi_brw_settings_browser_preferences_set_default();
	mmi_brw_settings_browser_options_set_default();

/*** ritesh started 07/09/07 *****/
	mmi_brw_prof_set_default_setting(BRW_PROF_BROWSER_PROFILE);
//	mmi_brw_psh_set_default_setting();

	g_brw_cntx.brw_launching_pad = BRW_LPD_RESTORE_BRW_SETTINGS;
	mmi_brw_settings_set_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_get_user_defined_homepage
 * DESCRIPTION
 *  This function is used for getting the user defined homepage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_get_user_defined_homepage(U8* strHomepage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_asc_to_ucs2((S8*)strHomepage, (S8*)g_brw_cntx.user_defined_hmpage_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_set_user_defined_homepage
 * DESCRIPTION
 *  This function is used for setting the user defined homepage value
 * PARAMETERS
 *  strHomepage		[IN]		It is an ascii string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_set_user_defined_homepage(U8* strHomepage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	strcpy((S8*)g_brw_cntx.user_defined_hmpage_url, (S8*)strHomepage);
	mmi_brw_settings_write_user_defined_homepage();
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        (U16) IMG_GLOBAL_ACTIVATED,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) (SUCCESS_TONE));
	DeleteUptoScrID(SCR_ID_BRW_USER_DEFINED_HOMEPAGE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_set_active_profile_homepage
 * DESCRIPTION
 *  This function is used for setting the active profile homepage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_set_active_profile_homepage(U8* strHomepage)
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
 *  mmi_brw_settings_user_defined_hmpage_save
 * DESCRIPTION
 *  This function is used for setting the active profile homepage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 url[BRW_MAX_URL_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2_to_asc((S8*)url,(S8*)g_brw_current_url);

	if( mmi_brw_stricmp((S8*)BRW_BLANK_HOMEPAGE_URL, (S8*)url) && 
		(mmi_brw_validate_url((PU8) g_brw_current_url) < 0)
	   )
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);	
		DeleteUptoScrID(SCR_ID_BRW_USER_DEFINED_HOMEPAGE);
		return;
	}

	mmi_brw_settings_set_user_defined_homepage((U8*)url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_save
 * DESCRIPTION
 *  This function is used for setting the active profile homepage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 url[BRW_MAX_URL_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_validate_url((PU8) g_brw_current_url) < 0)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);	
		DeleteUptoScrID(SCR_ID_BRW_ACTIVE_PROFILE_HOMEPAGE);
		return;
	}
	
	mmi_ucs2_to_asc((S8*)url,(S8*)g_brw_current_url);
	mmi_brw_prof_wap_set_homepage((S8*)url);
	DisplayPopup(
		(PU8) GetString(STR_GLOBAL_DONE), 
		IMG_GLOBAL_ACTIVATED, 
		1, 
		UI_POPUP_NOTIFYDURATION_TIME, 
		SUCCESS_TONE);
	DeleteUptoScrID(SCR_ID_BRW_ACTIVE_PROFILE_HOMEPAGE);
}


#if defined (WAP_SEC_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of trusted certificates
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  TRUE, if successfull otherwise FALSE
 *****************************************************************************/
pBOOL mmi_brw_security_settings_trusted_certificates_list_get_item(S32 item_index, UI_string_type str_buff, 
												 PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_utf8_to_ucs2_string((U8*) str_buff, MAX_SUB_MENU_SIZE, (U8*)g_brw_cntx.trusted_cert_list_p[item_index].cert.issuer);
	//*img_buff_p = get_image(gIndexIconsImageList[item_index]);	
	*img_buff_p = get_image(IMG_ID_BRW_TRUSTED_CERTS);	

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_delete
 * DESCRIPTION
 *  Deletes the selected recent page from the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_security_settings_trusted_certificates_delete_req(
		g_brw_cntx.trusted_cert_ids.cert_ids[g_brw_cntx.index_highlighted_item]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_session_info_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_session_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_SESSION_INFO);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wps_sec_get_session_info_req_struct*) OslConstructDataPtr(sizeof(wps_sec_get_session_info_req_struct));

	myMsgPtr->channel_id = 0;
	mmi_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_GET_SESSION_INFO_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_current_certificate_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_current_certificate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_CURRENT_CERTIFICATE);
	mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wps_sec_get_current_cert_req_struct*) OslConstructDataPtr(sizeof(wps_sec_get_current_cert_req_struct));
	myMsgPtr->channel_id = 0;

	mmi_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_GET_CURRENT_CERT_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_list_free_memory
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_list_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_mfree(g_brw_cntx.trusted_cert_list_p);
	g_brw_cntx.trusted_cert_list_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_trusted_certificate_ids_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_trusted_certificate_ids_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_ids_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_TRUSTED_CERTIFICATES);
	mmi_brw_entry_browser_busy_screen();

	/*deleting the internediate screens if any*/
	DeleteNScrId(SCR_ID_BRW_TRUSTED_CERTIFICATES);

    myMsgPtr = (wps_sec_get_cert_ids_req_struct*) OslConstructDataPtr(sizeof(wps_sec_get_cert_ids_req_struct));
	myMsgPtr->cert_options = WPS_SEC_GET_ROOT_CERT;

	/*de-allocating the memory*/
	mmi_brw_security_settings_trusted_certificates_list_free_memory();	

	mmi_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_GET_CERT_IDS_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_trusted_certificate_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_trusted_certificate_req(U32 cert_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wps_sec_get_cert_req_struct*) OslConstructDataPtr(sizeof(wps_sec_get_cert_req_struct));
	myMsgPtr->cert_id = cert_id;

	mmi_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_GET_CERT_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_session_info_str
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_session_info_str(U8* msg_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8	temp_str[BRW_SESSION_INFO_STR_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(temp_str, 0, BRW_SESSION_INFO_STR_LEN+1);

	sprintf((S8*) temp_str, "Key Exchange Alg : %d\nBulk Encryption Alg : %d\nHash Alg : %d\nSecurity Conn. type : %d", 
		g_brw_cntx.session_info_p->key_exchange_alg, g_brw_cntx.session_info_p->blk_encrypt_alg,
		g_brw_cntx.session_info_p->hash_alg, g_brw_cntx.session_info_p->sec_conn_type);

	mmi_asc_n_to_ucs2((S8*)msg_str, (S8*)temp_str, BRW_SESSION_INFO_STR_LEN+1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_trusted_certificate_str
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_trusted_certificate_str(U32 index, U8* msg_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8	temp_str[BRW_CURRENT_CERT_STR_LEN+1];
	U8	valid_not_before[20];
	U8	valid_not_after[20];
	S32 local_time_in_sec;
	applib_time_struct time_obj;
	U8 *serial_num_hex_p;
	U16 pos;
	U16 serial_num_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(strlen((S8*)g_brw_cntx.trusted_cert_list_p[index].cert.serial_num));

	memset(temp_str, 0, BRW_CURRENT_CERT_STR_LEN+1);

	local_time_in_sec = applib_dt_sec_utc_to_local(g_brw_cntx.trusted_cert_list_p[index].cert.not_before);
	applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
	sprintf((S8*) valid_not_before, "%d/%d/%d", time_obj.nMonth, time_obj.nDay, time_obj.nYear);

	local_time_in_sec = applib_dt_sec_utc_to_local(g_brw_cntx.trusted_cert_list_p[index].cert.not_after);
	applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
	sprintf((S8*) valid_not_after, "%d/%d/%d", time_obj.nMonth, time_obj.nDay, time_obj.nYear);

	/*hexadecimal representation of a string takes thrice the number of bytes as the actual string*/
	serial_num_len = strlen((S8*)g_brw_cntx.trusted_cert_list_p[index].cert.serial_num);
	serial_num_hex_p = OslMalloc((serial_num_len * 3) + 1);
	for(pos = 0; pos < serial_num_len; pos++)
	{
		sprintf((S8*) temp_str, "%x ", g_brw_cntx.trusted_cert_list_p[index].cert.serial_num[pos]);
		if(strlen((S8*)temp_str) < 3)
		{
			sprintf((S8*) temp_str, "0%x ", g_brw_cntx.trusted_cert_list_p[index].cert.serial_num[pos]);
		}
		if(pos == 0)
		{
			strcpy((S8*)serial_num_hex_p, (S8*)temp_str);
		}
		else
		{
			strcat((S8*)serial_num_hex_p, (S8*)temp_str);
		}
	}
	
	sprintf((S8*) temp_str, "Issuer :\n%s\n\nValid Not Before :\n%s\n\nValid Not After :\n%s\n\nSerial Number :\n%s\n"
		"\nSig Alg Name :\n%s\n\nSubject :\n%s\n\nType :\n%d\n\nVersion :\n%d\n", 
		g_brw_cntx.trusted_cert_list_p[index].cert.issuer, valid_not_before, valid_not_after,
		serial_num_hex_p, g_brw_cntx.trusted_cert_list_p[index].cert.sig_alg_name, 
		g_brw_cntx.trusted_cert_list_p[index].cert.subject, g_brw_cntx.trusted_cert_list_p[index].cert.type, 
		g_brw_cntx.trusted_cert_list_p[index].cert.version);

	mmi_asc_n_to_ucs2((S8*)msg_str, (S8*)temp_str, BRW_CURRENT_CERT_STR_LEN+1);

	OslMfree(serial_num_hex_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_get_current_cert_str
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_get_current_cert_str(U8* msg_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8	temp_str[BRW_CURRENT_CERT_STR_LEN+1];
	U8	valid_not_before[20];
	U8	valid_not_after[20];
	S32 local_time_in_sec;
	applib_time_struct time_obj;
	U8 *serial_num_hex_p;
	U16 pos;
	U16 serial_num_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(temp_str, 0, BRW_CURRENT_CERT_STR_LEN+1);

	local_time_in_sec = applib_dt_sec_utc_to_local(g_brw_cntx.current_cert_p->not_before);
	applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
	sprintf((S8*) valid_not_before, "%d/%d/%d", time_obj.nMonth, time_obj.nDay, time_obj.nYear);

	local_time_in_sec = applib_dt_sec_utc_to_local(g_brw_cntx.current_cert_p->not_after);
	applib_dt_utc_sec_2_mytime(local_time_in_sec, &time_obj, MMI_FALSE);
	sprintf((S8*) valid_not_after, "%d/%d/%d", time_obj.nMonth, time_obj.nDay, time_obj.nYear);

	/*hexadecimal representation of a string takes thrice the number of bytes as the actual string*/
	serial_num_len = strlen((S8*)g_brw_cntx.current_cert_p->serial_num);
	serial_num_hex_p = OslMalloc((serial_num_len * 3) + 1);
	for(pos = 0; pos < serial_num_len; pos++)
	{
		sprintf((S8*) temp_str, "%x ", g_brw_cntx.current_cert_p->serial_num[pos]);
		if(strlen((S8*)temp_str) < 3)
		{
			sprintf((S8*) temp_str, "0%x ", g_brw_cntx.current_cert_p->serial_num[pos]);
		}
		if(pos == 0)
		{
			strcpy((S8*)serial_num_hex_p, (S8*)temp_str);
		}
		else
		{
			strcat((S8*)serial_num_hex_p, (S8*)temp_str);
		}
	}

	sprintf((S8*) temp_str, "Issuer :\n%s\n\nValid Not Before :\n%s\n\nValid Not After :\n%s\n\nSerial Number :\n%s\n"
		"\nSig Alg Name :\n%s\n\nSubject :\n%s\n\nType :\n%d\n\nVersion :\n%d\n", 
		g_brw_cntx.current_cert_p->issuer, valid_not_before, valid_not_after,
		serial_num_hex_p, g_brw_cntx.current_cert_p->sig_alg_name, g_brw_cntx.current_cert_p->subject,
		g_brw_cntx.current_cert_p->type, g_brw_cntx.current_cert_p->version);

	mmi_asc_n_to_ucs2((S8*)msg_str, (S8*)temp_str, BRW_CURRENT_CERT_STR_LEN+1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_copy_trusted_certificate
 * DESCRIPTION
 *  Function to copy the trusted certificate contents
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_copy_trusted_certificate(wps_sec_cert_content_struct* dest_p, wps_sec_cert_content_struct* src_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	size = sizeof(src_p->issuer);
	strncpy((S8*)dest_p->issuer, (S8*)src_p->issuer, size);
	dest_p->issuer[size - 1] = '\0';

	dest_p->issuer_len = src_p->issuer_len;
	dest_p->not_after = src_p->not_after;
	dest_p->not_before = src_p->not_before;

	size = sizeof(src_p->serial_num);
	strcpy((S8*)dest_p->serial_num, (S8*)src_p->serial_num);
	dest_p->serial_num[size - 1] = '\0';

	dest_p->serial_num_len = src_p->serial_num_len;

	size = sizeof(src_p->sig_alg_name);
	strcpy((S8*)dest_p->sig_alg_name, (S8*)src_p->sig_alg_name);
	dest_p->sig_alg_name[size - 1] = '\0';

	dest_p->sig_alg_name_len = src_p->sig_alg_name_len;

	size = sizeof(src_p->subject);
	strcpy((S8*)dest_p->subject, (S8*)src_p->subject);
	dest_p->subject[size - 1] = '\0';

	dest_p->subject_len = src_p->subject_len;
	dest_p->type = src_p->type;
	dest_p->version = src_p->version;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_copy_current_certificate
 * DESCRIPTION
 *  Function to copy the current certificate contents
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_copy_current_certificate(wps_sec_get_current_cert_rsp_struct* dest_p, 
														wps_sec_get_current_cert_rsp_struct* src_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	dest_p->channel_id		= src_p->channel_id;
	dest_p->result			= src_p->result;

	size = sizeof(src_p->issuer);
	strncpy((S8*)dest_p->issuer, (S8*)src_p->issuer, size);
	dest_p->issuer[size - 1] = '\0';

	dest_p->issuer_len = src_p->issuer_len;
	dest_p->not_after = src_p->not_after;
	dest_p->not_before = src_p->not_before;

	size = sizeof(src_p->serial_num);
	strcpy((S8*)dest_p->serial_num, (S8*)src_p->serial_num);
	dest_p->serial_num[size - 1] = '\0';

	dest_p->serial_num_len = src_p->serial_num_len;

	size = sizeof(src_p->sig_alg_name);
	strcpy((S8*)dest_p->sig_alg_name, (S8*)src_p->sig_alg_name);
	dest_p->sig_alg_name[size - 1] = '\0';

	dest_p->sig_alg_name_len = src_p->sig_alg_name_len;

	size = sizeof(src_p->subject);
	strcpy((S8*)dest_p->subject, (S8*)src_p->subject);
	dest_p->subject[size - 1] = '\0';

	dest_p->subject_len = src_p->subject_len;
	dest_p->type = src_p->type;
	dest_p->version = src_p->version;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_delete_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_delete_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_delete_ca_cert_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wps_sec_delete_ca_cert_req_struct*) OslConstructDataPtr(sizeof(wps_sec_delete_ca_cert_req_struct));
	myMsgPtr->idx = index;

	mmi_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_DELETE_CA_CERT_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_pre_entry_options
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_cntx.index_highlighted_item = GetHighlightedItem();
	mmi_brw_security_settings_trusted_certificates_entry_options();
}
#endif /*WAP_SEC_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_resize_screen_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_resize_screen_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_resize_window_req_struct *myMsgPtr;
    GDI_HANDLE title_layer = 0;
    GDI_HANDLE bottom_layer = 0;
    U32 x=0;
    U32 y=0;
    U32 w=0;
    U32 h=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_resize_window_req_struct*) OslConstructDataPtr(sizeof(wap_bam_resize_window_req_struct));

	Cat431GetScreenInfo(g_brw_cntx.screen_size_status,&x,&y,&w,&h,&title_layer,&bottom_layer);

	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->is_full_screen = (kal_bool)g_brw_cntx.screen_size_status;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->window_position_x  = x;
	myMsgPtr->window_position_y  = y;
	myMsgPtr->window_size_height = h;
	myMsgPtr->window_size_width  = w;
	myMsgPtr->category_lyr_a_hndl = title_layer;
	myMsgPtr->category_lyr_b_hndl = bottom_layer;

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_RESIZE_WINDOW_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_set_profile_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_set_profile_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_set_profile_req_struct *myMsgPtr;
	nvram_profile_content_struct *currProfStruct;
	U8	current_hmpage[(BRW_MAX_URL_LENGTH+1) * ENCODING_LENGTH];
	U32 length;
#ifdef __MTK_TARGET__
	U8 temp_proxy_ip[50];
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	currProfStruct = (nvram_profile_content_struct *)mmi_brw_prof_get_activated_wap_profile();

    myMsgPtr = (wap_bam_set_profile_req_struct*) OslConstructDataPtr(sizeof(wap_bam_set_profile_req_struct));
    myMsgPtr->profile = (wap_bam_profile_setting_t*) OslConstructDataPtr(sizeof(wap_bam_profile_setting_t));
	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->request_id  = 0;

	memset(myMsgPtr->profile->int_value_table, -1, wap_bam_setting_id_total * sizeof(kal_int32));
	memset(myMsgPtr->profile->str_value_table, 0, wap_bam_setting_id_total * sizeof(char *));

	if(g_brw_cntx.homepage_settings_index == BRW_USER_DEFINED_HOMEPAGE)
	{
		mmi_asc_to_ucs2((S8*)current_hmpage, (S8*)g_brw_cntx.user_defined_hmpage_url);
	}
	else
	{
		mmi_asc_to_ucs2((S8*)current_hmpage, (S8*)currProfStruct->url);
	}

	myMsgPtr->profile->int_value_table[wap_bam_setting_id_images] = g_brw_cntx.show_images_status;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_movies] = g_brw_cntx.show_videos_status;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_sounds] = g_brw_cntx.play_sounds_status;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_history] = BRW_RECENT_PAGES_COUNT;
#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_shortcuts] = g_brw_cntx.shortcuts_status;
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_rendering] = g_brw_cntx.rendering_mode;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_thumbnail] = g_brw_cntx.thumbnail_status;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_css] = g_brw_cntx.css_status;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_script] = g_brw_cntx.script_status;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_cache] = g_brw_cntx.cache_status;
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_sec_warning] = g_brw_cntx.security_warnings_status;
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */
#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_imei] = g_brw_cntx.send_device_id_status;
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_no_mime] = g_brw_cntx.load_unknown_media_status;
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_zoom] = g_brw_cntx.font_size;
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_navigation] = g_brw_cntx.navigation_mode;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_cookies] = g_brw_cntx.cookie_status;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_account] = currProfStruct->data_account_primary_id;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_type] = currProfStruct->conn_type;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_addr_type] = wap_bam_setting_val_conn_addr_type_ipv4;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_port] = currProfStruct->proxy_port;
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_timeout] = g_brw_cntx.timeout_value;

	if(mmi_ucs2strlen((S8*)current_hmpage))
	{
		length = (mmi_ucs2strlen((S8*)current_hmpage)+1) * ENCODING_LENGTH;
		myMsgPtr->profile->str_value_table[wap_bam_setting_id_homepage] = OslMalloc(length * sizeof(U8));
		mmi_chset_ucs2_to_utf8_string(
			(U8*)myMsgPtr->profile->str_value_table[wap_bam_setting_id_homepage], length, (U8*)current_hmpage);
	}
	else
	{
		myMsgPtr->profile->str_value_table[wap_bam_setting_id_homepage] = NULL;
	}


	/* Proxy IP */
#ifdef __MTK_TARGET__
		sprintf((char *)temp_proxy_ip,"%d.%d.%d.%d",currProfStruct->proxy_ip[0], currProfStruct->proxy_ip[1],
			currProfStruct->proxy_ip[2], currProfStruct->proxy_ip[3]);
		length = strlen((const char *)temp_proxy_ip)+1;
		myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_addr] = OslMalloc(length * sizeof(U8));
		strcpy((char *)myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_addr], (const char *)temp_proxy_ip);
#else
		length = strlen((S8*)"0.0.0.0")+1;
		myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_addr] = OslMalloc( length * ENCODING_LENGTH * sizeof(U8));
		strcpy((S8*)myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_addr], (S8*)"0.0.0.0");
#endif

	if(strlen((S8*)currProfStruct->password))
	{
		length = strlen((S8*)currProfStruct->password) + 1;
		myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_pwd] = OslMalloc(length * sizeof(U8));
		strcpy((S8*)myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_pwd], (S8*)currProfStruct->password);
	}
	else
	{
		myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_pwd] = NULL;
	}

	if(strlen((S8*)currProfStruct->username))
	{
		length = strlen((S8*)currProfStruct->username) + 1;
		myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_user] = OslMalloc(length * sizeof(U8));
		strcpy((S8*)myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_user], (S8*)currProfStruct->username);
	}
	else
	{
		myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_user] = NULL;
	}


	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_SET_PROFILE_REQ, myMsgPtr, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_preferences_read_inline_struct
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of complete
 *  trusted certificates list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_preferences_read_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/****************** Time Out ******************/
	mmi_brw_convert_int_to_unicode_string(gBrwTimeoutValue, (U32) g_brw_cntx.timeout_value);
	/****************** Time Out ******************/

	/****************** Show Images ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT] == BRW_PREF_NEVER_INDEX)
	{
		g_brw_cntx.show_images_status = wap_bam_setting_val_images_never;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT] == BRW_PREF_ALWAYS_INDEX)
	{
		g_brw_cntx.show_images_status = wap_bam_setting_val_images_always;
	}
	/****************** Show Images ******************/

	/****************** Show Videos ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT] == BRW_PREF_NEVER_INDEX)
	{
		g_brw_cntx.show_videos_status = wap_bam_setting_val_movies_never;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT] == BRW_PREF_ALWAYS_INDEX)
	{
		g_brw_cntx.show_videos_status = wap_bam_setting_val_movies_always;
	}
	/****************** Show Videos ******************/

	/****************** Play Sounds ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT] == BRW_PREF_NEVER_INDEX)
	{
		g_brw_cntx.play_sounds_status = wap_bam_setting_val_sounds_never;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT] == BRW_PREF_ALWAYS_INDEX)
	{
		g_brw_cntx.play_sounds_status = wap_bam_setting_val_sounds_always;
	}
	/****************** Play Sounds ******************/

	/****************** Load Unknown Media ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT] == BRW_PREF_NEVER_INDEX)
	{
		g_brw_cntx.load_unknown_media_status = wap_bam_setting_val_no_mime_never;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT] == BRW_PREF_ALWAYS_INDEX)
	{
		g_brw_cntx.load_unknown_media_status = wap_bam_setting_val_no_mime_always;
	}
	/****************** Load Unknown Media ******************/

	/****************** CSS ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_CSS_SELECT] == BRW_PREF_DISABLE_INDEX)
	{
		g_brw_cntx.css_status = wap_bam_setting_val_css_disable;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_CSS_SELECT] == BRW_PREF_ENABLE_INDEX)
	{
		g_brw_cntx.css_status = wap_bam_setting_val_css_enable;
	}
	/****************** CSS ******************/

	/****************** Script ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_SCRIPT_SELECT] == BRW_PREF_DISABLE_INDEX)
	{
		g_brw_cntx.script_status = wap_bam_setting_val_script_disable;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_SCRIPT_SELECT] == BRW_PREF_ENABLE_INDEX)
	{
		g_brw_cntx.script_status = wap_bam_setting_val_script_enable;
	}
	/****************** Script ******************/

	/****************** Cache ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_CACHE_SELECT] == BRW_PREF_DISABLE_INDEX)
	{
		g_brw_cntx.cache_status = wap_bam_setting_val_cache_disable;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_CACHE_SELECT] == BRW_PREF_ENABLE_INDEX)
	{
		g_brw_cntx.cache_status = wap_bam_setting_val_cache_enable;
	}
	/****************** Cache ******************/

	/****************** Cookie ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_COOKIE_SELECT] == BRW_PREF_DISABLE_INDEX)
	{
		g_brw_cntx.cookie_status = wap_bam_setting_val_cookies_disable;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_COOKIE_SELECT] == BRW_PREF_ENABLE_INDEX)
	{
		g_brw_cntx.cookie_status = wap_bam_setting_val_cookies_enable;
	}
	/****************** Cookie ******************/

#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
	/****************** Shortcuts ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT] == BRW_PREF_DISABLE_INDEX)
	{
		g_brw_cntx.shortcuts_status = wap_bam_setting_val_shortcuts_disable;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT] == BRW_PREF_ENABLE_INDEX)
	{
		g_brw_cntx.shortcuts_status = wap_bam_setting_val_shortcuts_enable;
	}
	/****************** Shortcuts ******************/
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */

#ifdef  BRW_SECURITY_WARNINGS_SUPPORT
	/****************** Security Warnings ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT] == BRW_PREF_DISABLE_INDEX)
	{
		g_brw_cntx.security_warnings_status = wap_bam_setting_val_sec_warning_disable;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT] == BRW_PREF_ENABLE_INDEX)
	{
		g_brw_cntx.security_warnings_status = wap_bam_setting_val_sec_warning_enable;
	}
	/****************** Security Warnings ******************/
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */

#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
	/****************** Send Device ID ******************/
	if(g_brw_preferences[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT] == BRW_PREF_DISABLE_INDEX)
	{
		g_brw_cntx.send_device_id_status = wap_bam_setting_val_imei_disable;
	}
	else if(g_brw_preferences[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT] == BRW_PREF_ENABLE_INDEX)
	{
		g_brw_cntx.send_device_id_status = wap_bam_setting_val_imei_enable;
	}
	/****************** Send Device ID ******************/
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_change_setting_value_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_change_setting_value_req(U8 data_type, U32 setting_id, U32 value_i, U8* value_bv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_change_setting_value_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_change_setting_value_req_struct*) OslConstructDataPtr(sizeof(wap_bam_change_setting_value_req_struct));
	myMsgPtr->source_id = BRW_APPLICATION_ID;
	myMsgPtr->instance_id = g_brw_cntx.brw_instance_id;
	myMsgPtr->type  = data_type;
	myMsgPtr->setting_id  = setting_id;
	myMsgPtr->value_i  = value_i;
	if(value_bv)
	{
		mmi_chset_ucs2_to_utf8_string((U8*)myMsgPtr->value_bv,WAP_BAM_MAX_SETTING_STR_VALUE_LEN + 1,(U8*)value_bv);
	}

	mmi_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_CHANGE_SETTING_VALUE_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_read_user_defined_homepage
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_read_user_defined_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID,
        1,
        &g_brw_cntx.user_defined_hmpage_url,
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_SIZE,
        &NvramError);
	
    if(!strlen((S8*)g_brw_cntx.user_defined_hmpage_url))
    {
        strcpy((S8*)g_brw_cntx.user_defined_hmpage_url, (S8*)WAP_CUSTOM_CFG_DEFAULT_USER_DEFINED_HOMEPAGE);
        mmi_brw_settings_write_user_defined_homepage();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_write_user_defined_homepage
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_write_user_defined_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID,
        1,
        &g_brw_cntx.user_defined_hmpage_url,
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_SIZE,
        &NvramError);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_get_active_profile_homepage
 * DESCRIPTION
 *  This function is used for getting the user defined homepage value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_get_active_profile_homepage(U8* strHomepage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	nvram_profile_content_struct *currProfStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	currProfStruct = (nvram_profile_content_struct *)mmi_brw_prof_get_activated_wap_profile();
	mmi_asc_to_ucs2((S8*)strHomepage, (S8*)currProfStruct->url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_data_req
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_data_req(U8 operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*showing the busy screen*/
	mmi_brw_busy_screen_set_title_string_id(STR_ID_BRW_BROWSER_OPTIONS);
    mmi_brw_entry_browser_busy_screen();

    myMsgPtr = (wps_clear_req_struct*) OslConstructDataPtr(sizeof(wps_clear_req_struct));
	myMsgPtr->channel_id = 0;
	myMsgPtr->request_id = 0;
	myMsgPtr->operation  = operation;

	mmi_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_CLEAR_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_encoding_methods_initialize_list
 * DESCRIPTION
 *  Entry function for encoding methods
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_encoding_methods_initialize_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 num_of_charsets;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	num_of_charsets = bam_get_total_charset_num();
	MMI_ASSERT(num_of_charsets);	

	if(g_brw_cntx.charset_list_p)
	{
		mmi_brw_settings_encoding_methods_free_memory();
	}
	
	g_brw_cntx.charset_list_p = OslMalloc(num_of_charsets*sizeof(bam_charset_name_id_t));

	bam_get_all_charsets(g_brw_cntx.charset_list_p);
	
	/*replacing the framework provided Ascii charset with Auto-select option
	so that it will be in sync with core*/
	g_brw_cntx.charset_list_p[0].id = WAP_BAM_UNKNOWN_CHARSET;
	g_brw_cntx.charset_list_p[0].name_id = STR_ID_BRW_CHARSET_AUTO_SELECT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_encoding_methods_free_memory
 * DESCRIPTION
 *  Entry function for encoding methods
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_encoding_methods_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_cntx.charset_list_p)
	{
	OslMfree(g_brw_cntx.charset_list_p);
	g_brw_cntx.charset_list_p = NULL;
}
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSETTINGS_C */ 

