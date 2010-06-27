/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_wap_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains WAP/MMS configuration default value. 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"        /* Basic data type */
#include "custom_wap_config.h"
#include "MMI_features.h"

#ifdef JATAAYU_SUPPORT
/********************************* WAP Browser *************************************/
/*
 * This array is used to store those non markup-language content-types.
 * *  For accpeted markup-language content-types will be automatically inserted by your WAP feature, WAP1.2.1 or WAP2.0
 * *  For WAP1.2.1, "application/vnd.wap.wmlc", "application/vnd.wap.wmlscriptc" and "text/vnd.wap.wml"
 * *  For WAP2.0, "text/html", "application/xhtml+xml; profile=http://www.wapforum.org/xhtml" and "application/vnd.wap.xhtml+xml"
 */
static const char *const g_BrowserAcceptContentType[] = 
{
    "image/vnd.wap.wbmp",
    "image/gif",
    "image/bmp",
    "audio/imelody",
    "audio/midi",
    "audio/wav",
    "application/vnd.wap.wtls-ca-certificate",
    "application/x-x509-ca-cert",
    "application/vnd.wap.hashed-certificate",
    "application/vnd.wap.signed-certificate",
    "text/css",
    "*/*",
    NULL
};

static const char *const g_BrowserAcceptCharset[] = 
{
    "utf-8",
    "iso-8859-1",
	"us-ascii",
	"iso-10646-ucs-2",
    NULL
};

static const char *const g_BrowserLanguageType[] = 
{
    "English",
    NULL
};

static const char *const g_MMSAcceptContentType[] = 
{
    "application/vnd.wap.mms-message",
    "application/smil",
    "application/vnd.wap.multipart.related",
    "application/vnd.wap.multipart.mixed",
#if defined(JPG_DECODE)
    "image/jpeg",    
#endif    
    "image/gif",
    "image/bmp",
    "image/vnd.wap.wbmp",
#if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)    
    "image/png",
#endif    
    "audio/midi",
    "audio/x-midi",
    "audio/sp-midi",
    "audio/x-wav",
    "audio/imelody",
    "text/x-imelody",
    "audio/wav",
    "audio/amr",
#if defined(AMRWB_DECODE)    
    "audio/amr-wb",
#endif    
#if defined(AAC_DECODE)
    "audio/aac",
#endif
#if defined(WMA_DECODE)
    "audio/wma",
#endif    
#if defined(MP4_CODEC) && defined(AAC_DECODE)    
    "audio/m4a",
#endif    
#if defined(DAF_DECODE)    
    "audio/mp3",
    "audio/mpeg",
#endif
    "audio/vnd.qcelp",  
#if defined(__DRM_SUPPORT__)    
    "application/vnd.oma.drm.message",
    "application/vnd.oma.drm.content",
    "application/vnd.oma.drm.rights+xml",
    "application/vnd.oma.drm.rights+wbxml",
#endif    
    "text/plain",
    "application/vnd.wap.hashed-certificate",
    "application/vnd.wap.signed-certificate",
    "application/vnd.wap.wtls_ca_certificate",
    "application/x_x509_ca_cert",
    "application/vnd.wap.xhtml+xml",
    "application/vnd.wap.wmlc",
    "application/vnd.wap.wmlscriptc",
    "text/vnd.wap.wml",
    "text/html",
    "text/css",
    "text/vnd.wap.connectivity-xml",
    "application/x-x509-user-cert",
    "application/vnd.wap.connectivity-wbxml",    
#if defined(MP4_CODEC) || defined(__SF_MP4_SUPPORT__)
    "video/3gp",
    "video/3gpp",
    "video/3gpp2",    
    "video/mp4",
    "video/mpeg",
#endif
#if defined(MJPG_SUPPORT)
    "video/x-msvideo",
    "video/avi",
#endif
#if defined(__J2ME__)
    "application/java-vm",
    "application/java-archive",
    "text/vnd.sun.j2me.app-descriptor",
#endif    
#if defined(__MMI_VCALENDAR__)
    "text/x-vCalendar",
#endif
#if defined(__MMI_VCARD__)
    "text/x-vCard",
#endif    
    NULL
};

static const char *const g_MMSAcceptCharset[] = 
{
    "utf-8",
    "iso-8859-1",
    "us-ascii",
    "iso-10646-ucs-2",
    NULL
};

static const char *const g_MMSLanguageType[] = 
{
    NULL
};


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_max_cache_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_browser_max_cache_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) WAP_CUSTOM_CFG_MAX_CACHE_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_max_cookies_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_browser_max_cookies_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) WAP_CUSTOM_CFG_MAX_COOKIES_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_max_push_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_browser_max_push_msg_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint16) WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_ua_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_ua_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)WAP_CUSTOM_CFG_DEFAULT_UA_HEADER;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_ua_prof_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_ua_prof_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_charset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_charset(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserAcceptCharset[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserAcceptCharset[i];
        }
        i++;
    }
    return NULL;

}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_content_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_content_type(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserAcceptContentType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserAcceptContentType[i];
        }
        i++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_language(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserLanguageType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserLanguageType[i];
        }
        i++;
    }
    return NULL;
}

/********************************* MMS Client *************************************/


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_uint8 global_mms_version;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 0: EM_MMS_VERSION_DEFAULT, 1: EM_MMS_VERSION_10, 2: EM_MMS_VERSION_11,  3: EM_MMS_VERSION_MAX */
    if (global_mms_version == 0)
    {
        return (kal_uint8) WAP_CUSTOM_CFG_MMS_VERSION;
    }
    else
    {
        return global_mms_version;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_slides
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_slides(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 max_slides_no = (kal_uint8) WAP_CUSTOM_CFG_MAX_MMS_SLIDES;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (max_slides_no == 0)
    {
        return 1;
    }
    else
    {
        return max_slides_no;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return wap_custom_get_max_mms_slides();  
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_user_agent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_user_agent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_ua_prof_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_ua_prof_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)WAP_CUSTOM_CFG_DEFAULT_MMS_UA_PROF_URL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_accept_content_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_accept_content_type(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_MMSAcceptContentType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_MMSAcceptContentType[i];
        }
        i++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_accept_charset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_accept_charset(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_MMSAcceptCharset[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserAcceptCharset[i];
        }
        i++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_accept_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_accept_language(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_MMSLanguageType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_MMSLanguageType[i];
        }
        i++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_msg_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_warning_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_warning_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_get_retry_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_get_retry_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_GET_TIMEOUT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_get_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_get_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) WAP_CUSTOM_CFG_MAX_MMS_GET_RETRY;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_retry_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_retry_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_POST_TIMEOUT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_msg_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_msg_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) WAP_CUSTOM_CFG_MAX_MMS_POST_MSG_RETRY;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_pdu_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_pdu_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) WAP_CUSTOM_CFG_MAX_MMS_POST_PDU_RETRY;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8) WAP_CUSTOM_CFG_MAX_MMS_ADDRESS;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8) WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT;
}
#endif /* JATAAYU_SUPPORT */ 

#ifdef OBIGO_Q03C
/* __CUSTPACK_MULTIBIN     Johnnie   BEGIN */
wap_custpack_header custpack_wap_default = 
{
    0,
    &wap_profile_default,
    &mms_profile_default,
    &wap_bkm_default,
    &wap_root_ca_default,
    &wap_config_default,
    &mms_config_default
};


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_wap_prof_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_wap_prof_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_PROFILE_DEFAULT->n_wap_profiles;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_prof_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_prof_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_PROFILE_DEFAULT->n_mms_profiles;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_cache_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_cache_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_CONFIG_DEFAULT->max_cache_size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_bookmark_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_bookmark_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_BKM_DEFAULT->max_n_bkms;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_trustList_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_trustList_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_TRUSTLIST_DEFAULT->max_n_trustLists;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_ua_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_ua_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)(CUST_WAP_CONFIG_DEFAULT->ua_header);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_ua_prof_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_ua_prof_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)(CUST_WAP_CONFIG_DEFAULT->ua_prof_url);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_default_browse_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_default_browse_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_CONFIG_DEFAULT->browse_timeout;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_push_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_push_msg_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_CONFIG_DEFAULT->max_n_push_msg;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_set_push_enable_push
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_set_push_enable_push(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_CONFIG_DEFAULT->set_push_enable_push;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_set_push_trust_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_set_push_trust_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_CONFIG_DEFAULT->set_push_trust_setting;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_set_push_SL_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_set_push_SL_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_WAP_CONFIG_DEFAULT->set_push_SL_setting;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_user_agent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_user_agent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)(CUST_MMS_CONFIG_DEFAULT->ua_header);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->max_n_mms_msg;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_msg_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->max_mms_size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_warning_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_warning_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->max_n_msg_warning;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_get_retry_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_get_retry_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM__
    if (CUST_MMS_CONFIG_DEFAULT->get_timeout <= 600) /*60 seconds*/
    {
        /*When dual sim feature is turned on, we need more time to establish bearer.*/
        return 600;    
    }
    else
    {
        return CUST_MMS_CONFIG_DEFAULT->get_timeout;
    }        
#else
    return CUST_MMS_CONFIG_DEFAULT->get_timeout;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_get_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_get_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (CUST_MMS_CONFIG_DEFAULT->max_n_get_retry + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_retry_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_retry_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->post_timeout;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_msg_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_msg_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (CUST_MMS_CONFIG_DEFAULT->max_n_post_msg_retry + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_pdu_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_pdu_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (CUST_MMS_CONFIG_DEFAULT->max_n_post_pdu_retry + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_slide_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_mms_slide_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->slide_duration;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_immed_retrieval_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_immed_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->immed_retrieval_mode;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_roam_retrieval_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_roam_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->roam_retrieval_mode;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_allow_advertimsement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_allow_advertimsement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->allow_advertimsement;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_allow_anonymous
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_allow_anonymous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->allow_anonymous;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_req_delivery_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_req_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->req_delivery_report;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_req_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_req_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->req_read_report;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_send_delivery_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_send_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->send_delivery_report;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_send_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_send_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->send_read_report;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->mms_version;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->max_n_slide;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->max_n_address;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return CUST_MMS_CONFIG_DEFAULT->max_n_attachment;
}

/* __CUSTPACK_MULTIBIN     Johnnie   END */

#endif /* OBIGO_Q03C */ 

#ifdef OBIGO_Q05A
/********************************* WAP Browser *************************************/
/*
 * This array is used to store those non markup-language content-types.
 * *  For accpeted markup-language content-types will be automatically inserted by your WAP feature, WAP1.2.1 or WAP2.0
 * *  For WAP1.2.1, "application/vnd.wap.wmlc", "application/vnd.wap.wmlscriptc" and "text/vnd.wap.wml"
 * *  For WAP2.0, "text/html", "application/xhtml+xml; profile=http://www.wapforum.org/xhtml" and "application/vnd.wap.xhtml+xml"
 */
static const char *const g_BrowserAcceptContentType[] = 
{
    "image/vnd.wap.wbmp",
    "image/gif",
    "image/bmp",
    "audio/imelody",
    "audio/midi",
    "audio/wav",
    "application/vnd.wap.wtls-ca-certificate",
    "application/x-x509-ca-cert",
    "application/vnd.wap.hashed-certificate",
    "application/vnd.wap.signed-certificate",
    "text/css",
    "*/*",
    NULL
};

static const char *const g_BrowserAcceptCharset[] = 
{
    "utf-8",
    "iso-8859-1",
	"us-ascii",
	"iso-10646-ucs-2",
    NULL
};

static const char *const g_BrowserLanguageType[] = 
{
    "English",
    NULL
};

static const char *const g_MMSAcceptContentType[] = 
{
    "application/vnd.wap.mms-message",
    "image/jpeg",
    "image/bmp",
    "image/gif",
    "image/vnd.wap.wbmp",
    "image/png",
    "audio/imelody",
    "audio/midi",
    "text/x-imelody",
    "audio/wav",
    "audio/mid",
    "audio/amr",
    "audio/vnd.qcelp",
    "audio/midi",
    "audio/sp-midi",
    "audio/mpeg",
    "video/mp4",
    "video/mpeg",
    "video/wmv",
    "video/3gpp",
    "video/dat",
    "video/3gpp2",
    "text/x-vCalendar",
    "text/x-vCard",
    "application/vnd.wap.multipart.related",
    "application/vnd.wap.multipart.mixed",
    "application/vnd.oma.drm.message",
    "application/vnd.oma.drm.content",
    "application/vnd.oma.drm.rights+xml",
    "application/vnd.oma.drm.rights+wbxml",
    "text/plain",
    "application/vnd.wap.hashed-certificate",
    "application/vnd.wap.signed-certificate",
    "application/vnd.wap.wtls_ca_certificate",
    "application/x_x509_ca_cert",
    "application/vnd.wap.xhtml+xml",
    "application/vnd.wap.wmlc",
    "application/vnd.wap.wmlscriptc",
    "text/vnd.wap.wml",
    "text/html",
    NULL
};

static const char *const g_MMSAcceptCharset[] = 
{
    "utf-8",
    "iso-8859-1",
    "us-ascii",
    "iso-10646-ucs-2",
    NULL
};

static const char *const g_MMSLanguageType[] = 
{
    NULL
};

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_version(void)
{
    return WAP_CUSTOM_CFG_MMS_VERSION;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_user_agent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_user_agent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8)WAP_CUSTOM_CFG_MAX_MMS_SLIDES;
    
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8)WAP_CUSTOM_CFG_MAX_MMS_ADDRESS;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8)WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_msg_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32)WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_charset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_charset(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserAcceptCharset[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserAcceptCharset[i];
        }
        i++;
    }
    return NULL;

}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_content_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_content_type(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserAcceptContentType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserAcceptContentType[i];
        }
        i++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_language(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserLanguageType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserLanguageType[i];
        }
        i++;
    }
    return NULL;
}
#endif /* OBIGO_Q05A */

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_cache_push_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_cache_push_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_CACHE_PUSH_NUM;
}
