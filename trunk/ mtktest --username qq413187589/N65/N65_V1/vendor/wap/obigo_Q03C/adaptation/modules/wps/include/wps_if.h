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
 *   wps_if.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares WPS module interface function prototype
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

/* Signals sent to the WPS */
#define WPS_SIG_CONFIGURE_CHANNEL                 ((MSF_MODID_WPS << 8) + 0x01)
#define WPS_SIG_CONFIGURE_PROXY_CHANNEL           ((MSF_MODID_WPS << 8) + 0x02)
#define WPS_SIG_REMOVE_CHANNEL                    ((MSF_MODID_WPS << 8) + 0x03)
#define WPS_SIG_HTTP_REQUEST                      ((MSF_MODID_WPS << 8) + 0x04)
#define WPS_SIG_CANCEL_REQUEST                    ((MSF_MODID_WPS << 8) + 0x05)
#define WPS_SIG_CLEAR                             ((MSF_MODID_WPS << 8) + 0x06)
#define WPS_SIG_HTTP_AUTH_INDICATION              ((MSF_MODID_WPS << 8) + 0x07)

extern void *wps_convert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer);

extern void wps_destruct(MSF_UINT8 module, MSF_UINT16 signal, void *p);

void
WPSif_configureChannel(
    MSF_UINT8 src,
    int channelId,
    int connectionType,
    MSF_INT32 networkAccountId,
    int timeOut,
    int options,
    const char *staticHeaders);

/*
 * Configure a channel over which to send HTTP requests, via a proxy.
 */
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
    const char *staticHeaders);

/*
 * Remove a previously configured channel.
 */
extern void WPSif_removeChannel(MSF_UINT8 src, int channelId);

/*
 * Send a HTTP request, using a previously configured channel.
 */
extern void
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
    stk_content_t *content);

/*
 * Cancel a HTTP request.
 */
extern void WPSif_cancelRequest(MSF_UINT8 src, int requestId);

/*
 * Clears items in the STK that are shared by all users
 */
extern void WPSif_clear(MSF_UINT8 src, int operation, const char *url);

/*
 * Notify HTTP authentication reqest
 */

typedef struct
{
    MSF_INT32 requestId;
    MSF_INT32 authType;
    char *realm;
    char *username;
    MSF_INT32 warnings;
} wps_http_auth_ind_t;

extern void
WPSif_httpAuthIndication(
    MSF_UINT8 src,
    int requestId,
    int authType,
    const char *realm,
    const char *username,
    int warnings);

