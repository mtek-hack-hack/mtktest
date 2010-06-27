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
 *   wps_if.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements WPS module interface function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "msf_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_errc.h"
#include "msf_wid.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_lib.h"
#include "stk_if.h"
#include "wps_if.h"

#ifdef WPS_SUPPORT
/*
 * Convert signals owned by the WPS module.
 * Conversion is from signal buffer to signal structs (see above).
 */


/*****************************************************************************
 * FUNCTION
 *  wps_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  module      [IN]        
 *  signal      [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *wps_convert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_dcvt_t cvt_obj;
    void *user_data;
    MSF_UINT16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
    {
        return NULL;
    }

    user_data = MSF_SIGNAL_GET_USER_DATA(buffer, &length);
    if ((user_data == NULL) || (length == 0))
    {
        return NULL;
    }

    msf_dcvt_init(&cvt_obj, MSF_DCVT_DECODE, user_data, length, module);

    switch (signal)
    {
        case WPS_SIG_CONFIGURE_CHANNEL:
        {
            stk_configure_channel_t *p;

            p = MSF_MEM_ALLOCTYPE(module, stk_configure_channel_t);
            stk_cvt_configure_channel(&cvt_obj, p);
            return (void*)p;
        }

        case WPS_SIG_CONFIGURE_PROXY_CHANNEL:
        {
            stk_configure_proxy_channel_t *p;

            p = MSF_MEM_ALLOCTYPE(module, stk_configure_proxy_channel_t);
            stk_cvt_configure_proxy_channel(&cvt_obj, p);
            return (void*)p;
        }

        case WPS_SIG_REMOVE_CHANNEL:
        {
            stk_remove_channel_t *p;

            p = MSF_MEM_ALLOCTYPE(module, stk_remove_channel_t);
            stk_cvt_remove_channel(&cvt_obj, p);
            return (void*)p;
        }

        case WPS_SIG_HTTP_REQUEST:
        {
            stk_http_request_t *p;

            p = MSF_MEM_ALLOCTYPE(module, stk_http_request_t);
            stk_cvt_http_request(&cvt_obj, p);
            return (void*)p;
        }

        case WPS_SIG_CANCEL_REQUEST:
        {
            stk_cancel_request_t *p;

            p = MSF_MEM_ALLOCTYPE(module, stk_cancel_request_t);
            stk_cvt_cancel_request(&cvt_obj, p);
            return (void*)p;
        }

        case WPS_SIG_CLEAR:
        {
            stk_clear_t *p;

            p = MSF_MEM_ALLOCTYPE(module, stk_clear_t);
            stk_cvt_clear(&cvt_obj, p);
            return (void*)p;
        }
        case WPS_SIG_HTTP_AUTH_INDICATION:
        {
            wps_http_auth_ind_t *p;

            p = MSF_MEM_ALLOCTYPE(module, wps_http_auth_ind_t);
            msf_dcvt_int32(&cvt_obj, &(p->requestId));
            msf_dcvt_int32(&cvt_obj, &(p->authType));
            msf_dcvt_string(&cvt_obj, &(p->realm));
            msf_dcvt_string(&cvt_obj, &(p->username));
            msf_dcvt_int32(&cvt_obj, &(p->warnings));
            return (void*)p;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wps_destruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  module      [IN]        
 *  signal      [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_destruct(MSF_UINT8 module, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/**********************************************************************
 * Signal-sending functions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  WPSif_configureChannel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                     [IN]        
 *  channelId               [IN]        
 *  connectionType          [IN]        
 *  networkAccountId        [IN]        
 *  timeOut                 [IN]        
 *  options                 [IN]        
 *  staticHeaders           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
WPSif_configureChannel(
    MSF_UINT8 src,
    int channelId,
    int connectionType,
    MSF_INT32 networkAccountId,
    int timeOut,
    int options,
    const char *staticHeaders)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stk_configure_channel_t ch;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch.channelId = (MSF_INT16) channelId;
    ch.connectionType = (MSF_INT16) connectionType;
    ch.networkAccountId = (MSF_INT32) networkAccountId;
    ch.timeOut = (MSF_INT16) timeOut;
    ch.options = (MSF_INT16) options;
    ch.staticHeaders = (char*)staticHeaders;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    stk_cvt_configure_channel(&cvt_obj, &ch);
    length = (MSF_UINT16) cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(WPS_SIG_CONFIGURE_CHANNEL, src, MSF_MODID_WPS, length);
    if (signal_buffer != NULL)
    {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, src);
        stk_cvt_configure_channel(&cvt_obj, &ch);

        MSF_SIGNAL_SEND(signal_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WPSif_configureProxyChannel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                     [IN]        
 *  channelId               [IN]        
 *  connectionType          [IN]        
 *  networkAccountId        [IN]        
 *  timeOut                 [IN]        
 *  proxyAddress            [?]         
 *  securePort              [IN]        
 *  userName                [IN]        
 *  password                [IN]        
 *  realm                   [IN]        
 *  options                 [IN]        
 *  staticHeaders           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
WPSif_configureProxyChannel(
    MSF_UINT8 src,
    int channelId,
    int connectionType,
    MSF_INT32 networkAccountId,
    int timeOut,
    msf_sockaddr_t *proxyAddress,
    int securePort,
    const char *userName,
    const char *password,
    const char *realm,
    int options,
    const char *staticHeaders)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stk_configure_proxy_channel_t ch;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch.channelId = (MSF_INT16) channelId;
    ch.connectionType = (MSF_INT16) connectionType;
    ch.networkAccountId = (MSF_INT32) networkAccountId;
    ch.timeOut = (MSF_INT16) timeOut;
    ch.proxyAddress = *proxyAddress;
    ch.securePort = (MSF_UINT16) securePort;
    ch.userName = (char*)userName;
    ch.password = (char*)password;
    ch.realm = (char*)realm;
    ch.options = (MSF_INT16) options;
    ch.staticHeaders = (char*)staticHeaders;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    stk_cvt_configure_proxy_channel(&cvt_obj, &ch);
    length = (MSF_UINT16) cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(WPS_SIG_CONFIGURE_PROXY_CHANNEL, src, MSF_MODID_WPS, length);
    if (signal_buffer != NULL)
    {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, src);
        stk_cvt_configure_proxy_channel(&cvt_obj, &ch);

        MSF_SIGNAL_SEND(signal_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WPSif_removeChannel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src             [IN]        
 *  channelId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WPSif_removeChannel(MSF_UINT8 src, int channelId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stk_remove_channel_t ch;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch.channelId = (MSF_INT16) channelId;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    stk_cvt_remove_channel(&cvt_obj, &ch);
    length = (MSF_UINT16) cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(WPS_SIG_REMOVE_CHANNEL, src, MSF_MODID_WPS, length);
    if (signal_buffer != NULL)
    {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, src);
        stk_cvt_remove_channel(&cvt_obj, &ch);

        MSF_SIGNAL_SEND(signal_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WPSif_httpRequest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                 [IN]        
 *  channelId           [IN]        
 *  requestId           [IN]        
 *  url                 [IN]        
 *  method              [IN]        
 *  options             [IN]        
 *  headers             [IN]        
 *  replyFileName       [IN]        
 *  replyFileSize       [IN]        
 *  numEntries          [IN]        
 *  content             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void
WPSif_httpRequest(
    MSF_UINT8 src,
    int channelId,
    int requestId,
    const char *url,
    int method,
    int options,
    const char *headers,
    const char *replyFileName,
    long replyFileSize,
    int numEntries,
    stk_content_t *content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stk_http_request_t req;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.channelId = (MSF_INT16) channelId;
    req.requestId = (MSF_INT16) requestId;
    req.url = (char*)url;
    req.method = (MSF_INT16) method;
    req.options = (MSF_INT16) options;
    req.headers = (char*)headers;
    req.replyFileName = (char*)replyFileName;
    req.replyFileSize = (MSF_INT32) replyFileSize;
    req.numEntries = (MSF_INT16) numEntries;
    req.content = content;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    stk_cvt_http_request(&cvt_obj, &req);
    length = (MSF_UINT16) cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(WPS_SIG_HTTP_REQUEST, src, MSF_MODID_WPS, length);
    if (signal_buffer != NULL)
    {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, src);
        stk_cvt_http_request(&cvt_obj, &req);

        MSF_SIGNAL_SEND(signal_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WPSif_cancelRequest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src             [IN]        
 *  requestId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WPSif_cancelRequest(MSF_UINT8 src, int requestId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stk_cancel_request_t can;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    can.requestId = (MSF_INT16) requestId;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    stk_cvt_cancel_request(&cvt_obj, &can);
    length = (MSF_UINT16) cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(WPS_SIG_CANCEL_REQUEST, src, MSF_MODID_WPS, length);
    if (signal_buffer != NULL)
    {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
        stk_cvt_cancel_request(&cvt_obj, &can);

        MSF_SIGNAL_SEND(signal_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WPSif_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src             [IN]        
 *  operation       [IN]        
 *  url             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WPSif_clear(MSF_UINT8 src, int operation, const char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stk_clear_t clr;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clr.operation = (MSF_INT16) operation;
    clr.url = (char*)url;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    stk_cvt_clear(&cvt_obj, &clr);
    length = (MSF_UINT16) cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(WPS_SIG_CLEAR, src, MSF_MODID_WPS, length);
    if (signal_buffer != NULL)
    {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
        stk_cvt_clear(&cvt_obj, &clr);

        MSF_SIGNAL_SEND(signal_buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WPSif_httpAuthIndication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src             [IN]        
 *  requestId       [IN]        
 *  authType        [IN]        
 *  realm           [IN]        
 *  username        [IN]        
 *  warnings        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
WPSif_httpAuthIndication(
    MSF_UINT8 src,
    int requestId,
    int authType,
    const char *realm,
    const char *username,
    int warnings)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_ind_t auth;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    auth.requestId = (MSF_INT32) requestId;
    auth.authType = (MSF_INT32) authType;
    auth.realm = (char*)realm;
    auth.username = (char*)username;
    auth.warnings = (MSF_INT32) warnings;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    msf_dcvt_int32(&cvt_obj, &(auth.requestId));
    msf_dcvt_int32(&cvt_obj, &(auth.authType));
    msf_dcvt_string(&cvt_obj, &(auth.realm));
    msf_dcvt_string(&cvt_obj, &(auth.username));
    msf_dcvt_int32(&cvt_obj, &(auth.warnings));

    length = (MSF_UINT16) cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE(WPS_SIG_HTTP_AUTH_INDICATION, src, MSF_MODID_WPS, length);
    if (signal_buffer != NULL)
    {
        user_data = MSF_SIGNAL_GET_USER_DATA(signal_buffer, &length);
        msf_dcvt_init(&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
        msf_dcvt_int32(&cvt_obj, &(auth.requestId));
        msf_dcvt_int32(&cvt_obj, &(auth.authType));
        msf_dcvt_string(&cvt_obj, &(auth.realm));
        msf_dcvt_string(&cvt_obj, &(auth.username));
        msf_dcvt_int32(&cvt_obj, &(auth.warnings));
        MSF_SIGNAL_SEND(signal_buffer);
    }
}

#endif /* WPS_SUPPORT */ 

