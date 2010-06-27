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
 *  VoIPUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MTK_TARGET__
#include <windows.h>
#endif
#include "MMI_include.h"
#include "MMI_features.h"

#ifdef __MMI_VOIP__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "CallManagementGprot.h"
#include "CallsGProts.h"
#include "Conversions.h"
#include "DateTimeGprot.h"
#include "FileManagerGProt.h"
#include "gpioInc.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "ProfilesDefs.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#include "app2soc_struct.h"
#include "soc_api.h"
#include "med_struct.h"
#include "rtp_api.h"

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"

const U8 sipUri[10] = { 's', '\0', 'i', '\0', 'p', '\0', ':', '\0', '\0', '\0' }; /* sip: */
const U8 telUri[10] = { 't', '\0', 'e', '\0', 'l', '\0', ':', '\0', '\0', '\0' }; /* tel: */
const U8 anonyUri[30] = { 's', '\0', 'i', '\0', 'p', '\0', ':', '\0', 'a', '\0', 'n', '\0', 'o', '\0', 'n', '\0', 'y', '\0', 'm', '\0', 'o', '\0', 'u', '\0', 's', '\0', '@', '\0', '\0', '\0' }; /* sip: anonymous@ */
const U8 sosUri[8] = { 's', '\0', 'o', '\0', 's', '\0', '\0', '\0' }; /* sos */
const U8 sos112[8] = { '1', '\0', '1', '\0', '2', '\0', '\0', '\0' }; /* 112 */
const U8 sos911[8] = { '9', '\0', '1', '\0', '1', '\0', '\0', '\0' }; /* 911 */
const U8 zeroIp[8] = { '0', '\0', '0', '\0', '0', '\0', '\0', '\0' }; /* 000 */
const U16 VoIPDTMFDigits[MMI_VOIP_MAX_NUM_DIGITS] = 
{
    KEY_1, KEY_2, KEY_3,
    KEY_4, KEY_5, KEY_6,
    KEY_7, KEY_8, KEY_9,
    KEY_STAR, KEY_0, KEY_POUND
};

const mmi_voip_error_string_struct g_voip_error_table[] = 
{
    {VOIP_UNSPECIFIED_ERROR, STR_ID_VOIP_UNKNOWN_ERROR},
    {VOIP_NOT_REGISTERED, STR_ID_VOIP_NOT_REGISTER},
    {VOIP_ALREADY_REGISTERED, STR_ID_VOIP_ALREADY_REGISTER},
    {VOIP_INVALID_PARAM, STR_ID_VOIP_INVALID_PARAMETER},
    {VOIP_CREATE_UAC_ERROR, STR_ID_VOIP_SIP_ERROR},
    {VOIP_GET_ADDR_FAILED, STR_ID_VOIP_INVALID_URI},
    {VOIP_CALL_ABORT_LOCALLY, STR_ID_VOIP_CALL_END},
    {VOIP_RECV_BYE, STR_ID_VOIP_CALL_END},
    {VOIP_INCORRECT_CALL_STATE, STR_ID_VOIP_ACTION_INVALID},
    {VOIP_BEARER_DISCONNECTED, STR_ID_VOIP_NETWORK_DOWN},
    {VOIP_ABORT_FAILED, STR_ID_VOIP_CALL_END},
    {VOIP_CALL_NOT_EXIST, STR_ID_VOIP_CALL_NOT_EXIST},
    {VOIP_INVALID_URI, STR_ID_VOIP_INVALID_URI},
    {VOIP_SWAP_FAILED, STR_ID_VOIP_SWAP_FAIL},
    {VOIP_SWAP_PARTIAL_FAILED, STR_ID_VOIP_SWAP_FAIL},
    {VOIP_TRANSFER_FAILED, STR_ID_VOIP_TRANSFER_FAIL},
    {VOIP_MERGE_FAILED, STR_ID_VOIP_CONFERENCE_FAIL},
    {VOIP_MERGE_PARTIAL_FAILED, STR_ID_VOIP_CONFERENCE_FAIL},
    {VOIP_NAT_FAILED, STR_ID_VOIP_NAT_ERROR},
    {VOIP_TEMPORARY_BUSY, STR_ID_VOIP_ACTION_CONFLICT},
    {VOIP_UNSUPPORTED_NAT_TYPE, STR_ID_VOIP_NAT_ERROR},
    {VOIP_NETWORK_ERROR, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_BUSY, STR_ID_VOIP_ACTION_CONFLICT},
    {VOIP_INVALID_CALL_REQ, STR_ID_VOIP_ACTION_INVALID},
    {VOIP_PARTIAL_FAILED, STR_ID_VOIP_UNKNOWN_ERROR},
    {VOIP_REREGISTER_FAILED, STR_ID_VOIP_REGISTER_FAIL},
    {VOIP_SDP_MISMATCHED, STR_ID_VOIP_SDP_ERROR},
    {VOIP_DNS_ERROR, STR_ID_VOIP_DNS_ERROR},
    {VOIP_NO_RESOURCE, STR_ID_VOIP_UNKNOWN_ERROR},
    {VOIP_SIP_FS_ERROR, STR_ID_VOIP_UNKNOWN_ERROR},
    {VOIP_DHCP_ERROR, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_SIP_300_MULTIPLE_CHOICES, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_SIP_301_MOVED_PERMANENTLY, STR_ID_VOIP_NUMBER_MOVE},
    {VOIP_SIP_302_MOVED_TEMPORARILY, STR_ID_VOIP_NUMBER_MOVE},
    {VOIP_SIP_305_USE_PROXY, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_400_BAD_REQUEST, STR_ID_VOIP_ACTION_INVALID},
    {VOIP_SIP_401_UNAUTHORIZED, STR_ID_VOIP_AUTHENTICATION_FAIL},
    {VOIP_SIP_403_FORBIDDEN, STR_ID_VOIP_ACTION_FORBIDDEN},
    {VOIP_SIP_404_NOT_FOUND, STR_ID_VOIP_USER_NOT_FOUND},
    {VOIP_SIP_405_METHOD_NOT_ALLOW, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_406_NOT_ACCEPTABLE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_407_PROXY_AUTH_REQUIRED, STR_ID_VOIP_AUTHENTICATION_FAIL},
    {VOIP_SIP_408_REQUEST_TIMEOUT, STR_ID_VOIP_REQUEST_TIMEOUT},
    {VOIP_SIP_412_CONDITIONAL_REQ_FAIL, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_422_INTERVAL_TOO_BRIEF, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_423_INTERVAL_TOO_BRIEF, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_478_UNRESOLVEABLE_DEST, STR_ID_VOIP_USER_NOT_FOUND},
    {VOIP_SIP_480_TEMP_UNAVAILABLE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_481_CALL_TRANS_NOT_EXIST, STR_ID_VOIP_CALL_NOT_EXIST},
    {VOIP_SIP_484_ADDRESS_INCOMPLETE, STR_ID_VOIP_USER_NOT_FOUND},
    {VOIP_SIP_486_BUSY_HERE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_487_REQ_TERMINATED, STR_ID_VOIP_CALL_END},
    {VOIP_SIP_488_NOT_ACCEPTABLE_HERE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_491_REQUEST_PENDING, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_499_UNRESOLVEABLE_DEST, STR_ID_VOIP_USER_NOT_FOUND},
    {VOIP_SIP_500_SERVER_INT_ERROR, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_SIP_503_SERVICE_UNAVAILABLE, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_SIP_600_BUSY_EVERYWHERE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_603_DECLINE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_606_NOT_ACCEPTABLE, STR_ID_VOIP_USER_BUSY},
    {0, STR_ID_VOIP_UNKNOWN_ERROR}
};


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_set_processing_parameter
 * DESCRIPTION
 *  Set processing screen parameter.
 * PARAMETERS
 *  titleStr            [IN]        Title string
 *  bodyStr             [IN]        Body string
 *  animationImg        [IN]        Animation image
 *  lskStr              [IN]        LSK display string
 *  lskFunc             [IN]        LSK function pointer
 *  rskStr              [IN]        RSK display string
 *  rskFunc             [IN]        RSK function pointer
 *  sendFunc            [IN]        SEND key function pointer
 *  endFunc             [IN]        END key function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_set_processing_parameter(
        U16 titleStr,
        U16 bodyStr,
        U16 animationImg,
        U16 lskStr,
        FuncPtr lskFunc,
        U16 rskStr,
        FuncPtr rskFunc,
        FuncPtr sendFunc,
        FuncPtr endFunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->proc_scr_info.title_string = titleStr;
    g_voip_cntx_p->proc_scr_info.body_string = bodyStr;
    g_voip_cntx_p->proc_scr_info.animation_image = animationImg;
    g_voip_cntx_p->proc_scr_info.lsk_string = lskStr;
    g_voip_cntx_p->proc_scr_info.lsk_funcPtr = lskFunc;
    g_voip_cntx_p->proc_scr_info.rsk_string = rskStr;
    g_voip_cntx_p->proc_scr_info.rsk_funcPtr = rskFunc;
    g_voip_cntx_p->proc_scr_info.send_funcPtr = sendFunc;
    g_voip_cntx_p->proc_scr_info.end_funcPtr = endFunc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_processing_screen
 * DESCRIPTION
 *  General entry function of processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_processing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_PROCESSING, NULL, mmi_voip_entry_processing_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_PROCESSING);
    ShowCategory66Screen(
        g_voip_cntx_p->proc_scr_info.title_string,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->proc_scr_info.lsk_string,
        IMG_GLOBAL_OK,
        g_voip_cntx_p->proc_scr_info.rsk_string,
        IMG_GLOBAL_BACK,
        (U8*) GetString(g_voip_cntx_p->proc_scr_info.body_string),
        g_voip_cntx_p->proc_scr_info.animation_image,
        NULL);
    SetLeftSoftkeyFunction(g_voip_cntx_p->proc_scr_info.lsk_funcPtr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(g_voip_cntx_p->proc_scr_info.rsk_funcPtr, KEY_EVENT_UP);
    SetKeyHandler(g_voip_cntx_p->proc_scr_info.send_funcPtr, KEY_SEND, KEY_EVENT_DOWN);
    SetKeyHandler(g_voip_cntx_p->proc_scr_info.end_funcPtr, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_validate_port
 * DESCRIPTION
 *  Validate port. 0~65535 is a valid range of port.
 * PARAMETERS
 *  unicodePort     [IN]        Port string in unicode
 * RETURNS
 *  TRUE means port number is valid; FALSE means port number is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_validate_port(U8 *unicodePort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 portNumber = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    portNumber = gui_atoi((UI_string_type) unicodePort);
    if ((portNumber >= 0) && (portNumber <= 65535))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_validate_uri
 * DESCRIPTION
 *  Validate uri. Only one @ can appear in the uri.
 *  The @ cannot in the beginning of the uri,
 *  and cannot in the end of the uri, either.
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  TRUE means uri is valid; FALSE means uri is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_validate_uri(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *lowercaseUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 count = 0;
    S8 foundAt = 0;
    U8 charUnit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(lowercaseUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_voip_convert_uri_lower_case(unicodeUri, lowercaseUri);

    if ((mmi_ucs2strlen((S8*)lowercaseUri) == 0) ||
        (!mmi_ucs2cmp((S8*)lowercaseUri, (S8*)sipUri)) ||
        (!mmi_ucs2cmp((S8*)lowercaseUri, (S8*)telUri)))
    {
        OslMfree(lowercaseUri);
        return TRUE;
    }
    while (unicodeUri[count] != '\0' || unicodeUri[count + 1] != '\0')
    {
        if (unicodeUri[count] > 0x7e || unicodeUri[count + 1] > 0x7e)
        {
            OslMfree(lowercaseUri);
            return FALSE;
        }
        charUnit = unicodeUri[count];
        switch (charUnit)
        {
            case '@':
            {
                foundAt++;
                if (count == 0) /* @xxxxx */
                {
                    OslMfree(lowercaseUri);
                    return FALSE;
                }
                else if (foundAt > 1)
                {
                    OslMfree(lowercaseUri);
                    return FALSE;
                }
                else if (unicodeUri[count + 2] == '\0' && unicodeUri[count + 3] == '\0')
                {
                    OslMfree(lowercaseUri);
                    return FALSE; /* xxxx@ */
                }
                else
                {
                    break;
                }
            }
            case ',':
            case ';':
            case '<':
            case '>':
            case '[':
            case ']':
            case '"':
            case ')':
            case '(':
                OslMfree(lowercaseUri);
                return FALSE;
            default:
                break;
        }
        count += 2;
    }
    if (foundAt == 1)
    {
        OslMfree(lowercaseUri);
        return TRUE;
    }
    OslMfree(lowercaseUri);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_validate_ip
 * DESCRIPTION
 *  Validate ip. 0.0.0.0 is not a valid ip.
 * PARAMETERS
 *  ip1     [IN]        First number in the ip format
 *  ip2     [IN]        Second number in the ip format
 *  ip3     [IN]        Third number in the ip format
 *  ip4     [IN]        Fourth number in the ip format
 * RETURNS
 *  TRUE means ip address is valid; FALSE means ip address is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_validate_ip(U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gui_atoi((UI_string_type) ip1) != 0) ||
        (gui_atoi((UI_string_type) ip2) != 0) ||
        (gui_atoi((UI_string_type) ip3) != 0) || 
        (gui_atoi((UI_string_type) ip4) != 0))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_validate_dtmf
 * DESCRIPTION
 *  Validate dtmf key. Valide dtmf key is defined in VoIPDTMFDigits array.
 * PARAMETERS
 *  dtmfKey     [IN]        
 * RETURNS
 *  TRUE means dtmf key is valid; FALSE means dtmf key is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_validate_dtmf(U16 dtmfKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VOIP_MAX_NUM_DIGITS; i++)
    {
        if (dtmfKey == VoIPDTMFDigits[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_parse_uri
 * DESCRIPTION
 *  Make sure the uri has sip: and domain name.
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_parse_uri(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *lowercaseUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 sipLen = 0, telLen = 0, count = 0;
    S8 foundAt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(lowercaseUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_voip_convert_uri_lower_case(unicodeUri, lowercaseUri);

    sipLen = mmi_ucs2strlen((S8*)sipUri);    /* number of characters */
    telLen = mmi_ucs2strlen((S8*)telUri);    /* number of characters */

    if ((mmi_ucs2ncmp((S8*)lowercaseUri, (S8*)sipUri, sipLen)) && (mmi_ucs2ncmp((S8*)lowercaseUri, (S8*)telUri, telLen)))     /* no prefix sip: and tel: */
    {
        mmi_voip_append_uri_prefix(unicodeUri);
    }
    while (unicodeUri[count] != '\0' || unicodeUri[count + 1] != '\0')
    {
        if (unicodeUri[count] == '@')
        {
            foundAt = 1;
            break;
        }
        count += 2;
    }
    if (foundAt == 0)
    {
        mmi_voip_append_uri_domain(unicodeUri);
    }

    OslMfree(lowercaseUri);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_convert_uri_star_n_pound
 * DESCRIPTION
 *  Convert uri string %23 as # and %2A as *.
 * PARAMETERS
 *  asciiSrc      [IN/OUT]            Source uri string in ascii
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_convert_uri_star_n_pound(U8 *asciiSrc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    U8 *asciiDest = OslMalloc(VOIP_URI_LEN);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = 0; i < strlen((S8*)asciiSrc); i++)
    {
        if ((asciiSrc[i] == '%') && (asciiSrc[i + 1] == '2') && (asciiSrc[i + 2] == '3'))
        {
            asciiDest[j++] = '#';
            asciiDest[j] = '\0';
            i += 2;
        }
        else if ((asciiSrc[i] == '%') && (asciiSrc[i + 1] == '2') && (asciiSrc[i + 2] == 'A'))
        {
            asciiDest[j++] = '*';
            asciiDest[j] = '\0';
            i += 2;
        }
        else /* normal case */
        {
            asciiDest[j++] = asciiSrc[i];
            asciiDest[j] = '\0';
        }
    }
    memset(asciiSrc, 0, VOIP_URI_LEN);
    strncpy((S8*)asciiSrc, (S8*)asciiDest, VOIP_URI_LEN);
    OslMfree(asciiDest);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_convert_uri_lower_case
 * DESCRIPTION
 *  Convert uri string to lower case.
 * PARAMETERS
 *  unicodeSrc      [IN]            Source uri string in unicode
 *  unicodeDest     [IN/OUT]        Destination uri string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_convert_uri_lower_case(U8 *unicodeSrc, U8 *unicodeDest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (unicodeSrc[count] != '\0' || unicodeSrc[count + 1] != '\0')
    {
        if ((unicodeSrc[count] >= 'A') && (unicodeSrc[count] <= 'Z'))
        {
            unicodeDest[count] = unicodeSrc[count] + ('a' - 'A');
        }
        else
        {
            unicodeDest[count] = unicodeSrc[count];
        }
        count += 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_append_uri_prefix
 * DESCRIPTION
 *  Append sip: in front of the uri.
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_append_uri_prefix(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sipLen = 0;
    U8 *noprefixUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(noprefixUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_ucs2ncpy((S8*)noprefixUri, (S8*)unicodeUri, VOIP_URI_LEN);
    memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    sipLen = mmi_ucs2strlen((S8*)sipUri);
    mmi_ucs2ncpy((S8*)unicodeUri, (S8*)sipUri, sipLen);
    mmi_ucs2ncpy((S8*)unicodeUri + sipLen * ENCODING_LENGTH, (S8*)noprefixUri, ((VOIP_URI_LEN - 1) - sipLen));
    OslMfree(noprefixUri);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_append_uri_domain
 * DESCRIPTION
 *  Append domain name in back of the uri.
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_append_uri_domain(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeProf = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;
    S8 foundAt = 0;
    S32 count = 0, uriLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(unicodeProf, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)unicodeProf,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username,
        VOIP_URI_LEN);
    while (unicodeProf[count] != '\0' || unicodeProf[count + 1] != '\0')
    {
        if (unicodeProf[count] == '@')
        {
            foundAt = 1;
            break;
        }
        count += 2;
    }
    if (foundAt == 1)
    {
        uriLen = mmi_ucs2strlen((S8*)unicodeUri);
        mmi_ucs2ncpy(
            (S8*)unicodeUri + uriLen * ENCODING_LENGTH,
            (S8*)unicodeProf + count,
            ((VOIP_URI_LEN - 1) - uriLen));
    }
    OslMfree(unicodeProf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_add_to_call_list
 * DESCRIPTION
 *  Add specific call to call list.
 * PARAMETERS
 *  fileName            [IN]            Voip cc call list file, path included
 *  callId              [IN]            Call id
 *  dialogId            [IN]            Dialog id
 *  currState           [IN]            Current state, either MMI_VOIP_OUTGOING_STATE or MMI_VOIP_INCOMING_STATE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_add_to_call_list(U16 *fileName, S32 callId, S32 dialogId, mmi_voip_call_state_enum currState)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle = 0;
    U32 fileLen = 0;
    S32 i = 0, result = 0;
    voip_call_struct callList;
    S32 freeTab = g_voip_cntx_p->call_misc_info.currfreeTab;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fileHandle = FS_Open(fileName, FS_READ_ONLY);
    if (fileHandle < 0)
    {
        MMI_ASSERT(fileHandle >= 0);
    }
    for (i = 0; i <= callId; i++)
    {
        result = FS_Read(fileHandle, &callList, sizeof(voip_call_struct), &fileLen);
        if (result != FS_NO_ERROR)
        {
            MMI_ASSERT(result == FS_NO_ERROR);
        }
    }
    FS_Close(fileHandle);

    if (freeTab != -1)
    {
        g_voip_cntx_p->call_list_info.call_info[freeTab].callId = callId;
        g_voip_cntx_p->call_list_info.call_info[freeTab].currState = currState;
        if (g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_OUTGOING_STATE)
        {
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].callOrigin = MMI_VOIP_MO_ORIGIN;
        }
        else if (g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_INCOMING_STATE)
        {
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].callOrigin = MMI_VOIP_MT_ORIGIN;
        }
        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].dialogId = dialogId;
        memset(
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].appName,
            0,
            (VOIP_DISP_NAME_LEN * sizeof(U16)));
        if (g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_OUTGOING_STATE)
        {
            mmi_voip_get_outgoing_disp_name(
                MMI_VOIP_PHB|MMI_VOIP_HISTORY|MMI_VOIP_SOS, 
                g_voip_cntx_p->call_misc_info.dispUri, /* for display emergency number string */
                (U8*)g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].appName, 
                VOIP_DISP_NAME_LEN);
        }
        memset(
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].dispName,
            0,
            (VOIP_DISP_NAME_LEN * sizeof(U16)));
        mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char*)callList.dialog[dialogId].user_addr.disp_name,
            (char*)g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].dispName,
            (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
        memset(g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].remoteUri, 0, VOIP_URI_LEN);
        memcpy(
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].remoteUri,
            callList.dialog[dialogId].user_addr.uri,
            VOIP_URI_LEN);
        mmi_voip_convert_uri_star_n_pound(g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].remoteUri);
        /* copy sdp info */
        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].rtpHandle = -1; /* rtp is not created yet */
        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].isMixer = FALSE;
        memcpy(
            &g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].sdp_info,
            &callList.dialog[dialogId].sdp_info,
            sizeof(voip_sdp_struct));
        g_voip_cntx_p->call_list_info.call_info[freeTab].numDialog++;
        g_voip_cntx_p->call_list_info.numTotal++;
        g_voip_cntx_p->call_misc_info.currfreeTab++;
        if (g_voip_cntx_p->call_misc_info.currfreeTab == MMI_VOIP_MAX_NUM_CALL)
        {
            g_voip_cntx_p->call_misc_info.currfreeTab = -1; /* call capacity full */
        }
    }
    else
    {
        MMI_ASSERT(0);  /* no available call entry */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_del_from_call_list
 * DESCRIPTION
 *  Delete specific call from call list.
 * PARAMETERS
 *  callId              [IN]            Call id
 *  dialogId            [IN]            Dialog id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_del_from_call_list(S32 callId, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0, i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callIndex = mmi_voip_get_call_index(callId);
    if (callIndex != -1)
    {
        dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
        if (dialogIndex == 0)
        {
            g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog--;
            if (g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 0)
            {
                /* reset call info */
                mmi_voip_remove_mixer_before_close(callIndex);
                if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                {
                #ifdef __MMI_UCM__
                    mmi_voip_ucm_speech_ind(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle, FALSE, FALSE);
                #endif
                    mmi_voip_close_rtp(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle);
                }
                memset(&g_voip_cntx_p->call_list_info.call_info[callIndex], 0, sizeof(mmi_voip_call_struct));
                g_voip_cntx_p->call_list_info.call_info[callIndex].callId = -1;
                for (i = 0; i < VOIP_MAX_NUM_DIALOG; i++)
                {
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].dialogId = -1;
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].rtpHandle = -1;
                }
                g_voip_cntx_p->call_list_info.numTotal--;
                /* if currfreeTab is 0 already, it means the call was not connected but is disconnected now.
                   therefore, no need to decrease currfreeTab */
                if (g_voip_cntx_p->call_misc_info.currfreeTab > 0)
                {
                    g_voip_cntx_p->call_misc_info.currfreeTab--;
                }
                /* when reaching call capacity, currfreeTab is set to -1 already.
                   therefore, currfreeTab has to set to 3 when call entry is available */
                else if (g_voip_cntx_p->call_misc_info.currfreeTab == -1)
                {
                    g_voip_cntx_p->call_misc_info.currfreeTab = MMI_VOIP_MAX_NUM_CALL - 1;
                }
            }
            else    /* g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 1 */
            {
                /* move dialog 1 to dialog 0 */
                mmi_voip_remove_mixer_before_close(callIndex);
                if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                {
                #ifdef __MMI_UCM__
                    mmi_voip_ucm_speech_ind(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle, FALSE, FALSE);
                #endif
                    mmi_voip_close_rtp(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle);
                }
                memcpy(
                    &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[0],
                    &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[1],
                    sizeof(mmi_voip_dialog_struct));
                memset(
                    &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[1],
                    0,
                    sizeof(mmi_voip_dialog_struct));
                g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[1].dialogId = -1;
                g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[1].rtpHandle = -1;
            }
        }
        else if (dialogIndex == 1)
        {
            g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog--;
            if (g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 0)
            {
                /* reset call info */
                mmi_voip_remove_mixer_before_close(callIndex);
                if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                {
                #ifdef __MMI_UCM__
                    mmi_voip_ucm_speech_ind(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle, FALSE, FALSE);
                #endif
                    mmi_voip_close_rtp(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle);
                }
                memset(&g_voip_cntx_p->call_list_info.call_info[callIndex], 0, sizeof(mmi_voip_call_struct));
                g_voip_cntx_p->call_list_info.call_info[callIndex].callId = -1;
                for (i = 0; i < VOIP_MAX_NUM_DIALOG; i++)
                {
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].dialogId = -1;
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].rtpHandle = -1;
                }
                g_voip_cntx_p->call_list_info.numTotal--;
                /* if currfreeTab is 0 already, it means the call was not connected but is disconnected now.
                   therefore, no need to decrease currfreeTab */
                if (g_voip_cntx_p->call_misc_info.currfreeTab > 0)
                {
                    g_voip_cntx_p->call_misc_info.currfreeTab--;
                }
                /* when reaching call capacity, currfreeTab is set to -1 already.
                   therefore, currfreeTab has to set to 3 when call entry is available */
                else if (g_voip_cntx_p->call_misc_info.currfreeTab == -1)
                {
                    g_voip_cntx_p->call_misc_info.currfreeTab = MMI_VOIP_MAX_NUM_CALL - 1;
                }
            }
            else    /* numDialog == 1 */
            {
                /* reset dialog info */
                mmi_voip_remove_mixer_before_close(callIndex);
                if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                {
                #ifdef __MMI_UCM__
                    mmi_voip_ucm_speech_ind(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle, FALSE, FALSE);
                #endif
                    mmi_voip_close_rtp(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle);
                }
                memset(
                    &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex],
                    0,
                    sizeof(mmi_voip_dialog_struct));
                g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dialogId = -1;
                g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle = -1;
            }
        }
        /* rearrange call list */
        if (g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 0)
        {
            for (i = callIndex; i < (MMI_VOIP_MAX_NUM_CALL - 1); i++)
            {
                memcpy(
                    &g_voip_cntx_p->call_list_info.call_info[i],
                    &g_voip_cntx_p->call_list_info.call_info[i + 1],
                    sizeof(mmi_voip_call_struct));
                memset(&g_voip_cntx_p->call_list_info.call_info[i + 1], 0, sizeof(mmi_voip_call_struct));
                g_voip_cntx_p->call_list_info.call_info[i + 1].callId = -1;
                for (j = 0; j < VOIP_MAX_NUM_DIALOG; j++)
                {
                    g_voip_cntx_p->call_list_info.call_info[i + 1].dialog_info[j].dialogId = -1;
                    g_voip_cntx_p->call_list_info.call_info[i + 1].dialog_info[j].rtpHandle = -1;

                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_call_list
 * DESCRIPTION
 *  Update mmi call list.
 * PARAMETERS
 *  fileName            [IN]            Voip cc call list file, path included
 *  isConf              [IN]            Display popup or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_call_list(U16 *fileName, MMI_BOOL isConf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.numHeld = 0;  /* re-calculate number of held call */
    mmi_voip_update_to_del_call_list(fileName, isConf);
    mmi_voip_update_to_add_call_list(fileName, isConf);
    mmi_voip_switch_session(MMI_VOIP_IDLE_STATE);
    FS_Delete(fileName);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_to_del_call_list
 * DESCRIPTION
 *  First pass of updating call list from voip cc to mmi.
 *  Delete mmi call list entry that voip cc call list does not have.
 * PARAMETERS
 *  fileName            [IN]            Voip cc call list file, path included
 *  isConf              [IN]            Display popup or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_to_del_call_list(U16 *fileName, MMI_BOOL isConf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle = 0;
    U32 fileLen = 0;
    S32 result = 0;
    voip_call_struct callList;
    S32 i = 0, j = 0, m = 0, n = 0, callId = 0, dialogId = 0;
    MYTIME currTime, duration;
    U8 popupStr[MAX_SUB_MENU_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < MMI_VOIP_MAX_NUM_CALL)
    {
        callId = g_voip_cntx_p->call_list_info.call_info[i].callId;
        if (callId != -1)
        {
            fileHandle = FS_Open(fileName, FS_READ_ONLY);
            if (fileHandle < 0)
            {
                MMI_ASSERT(fileHandle >= 0);
            }

            for (j = 0; j < g_voip_cntx_p->call_list_info.maxnumCall; j++)
            {
                result = FS_Read(fileHandle, &callList, sizeof(voip_call_struct), &fileLen);
                if (result != FS_NO_ERROR)
                {
                    MMI_ASSERT(result == FS_NO_ERROR);
                }

                if ((callList.is_bk_call == FALSE) && (callList.call_state != VOIP_CALL_STATE_TERMINATED) &&
                    (callList.call_id == callId))
                {
                    while (m < VOIP_MAX_NUM_DIALOG)
                    {
                        dialogId = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dialogId;
                        if (dialogId != -1)
                        {
                            for (n = 0; n < VOIP_MAX_NUM_DIALOG; n++)
                            {
                                if ((callList.dialog[n].in_use == TRUE) && (callList.dialog[n].dialog_id == dialogId))
                                {
                                    /* update call info */
                                    g_voip_cntx_p->call_list_info.call_info[i].currState = mmi_voip_get_call_state_enum(callList.dialog[n].dialog_state);
                                    if ((g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLD_STATE) && (m == 0))      /* only update held call count according to the first dialog */
                                    {
                                        g_voip_cntx_p->call_list_info.numHeld++;
                                    }
                                    else if (g_voip_cntx_p->call_list_info.call_info[i].currState ==
                                             MMI_VOIP_OUTGOING_STATE)
                                    {
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].callOrigin =
                                            MMI_VOIP_MO_ORIGIN;
                                    }
                                    else if (g_voip_cntx_p->call_list_info.call_info[i].currState ==
                                             MMI_VOIP_INCOMING_STATE)
                                    {
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].callOrigin =
                                            MMI_VOIP_MT_ORIGIN;
                                    }
                                    /* outgoing call or incoming call doesn't have the info of sdp yet */
                                    if ((g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_ACTIVE_STATE) || 
                                        (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLD_STATE))
                                    {
                                        if (g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle == -1)
                                        {
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle = mmi_voip_create_rtp(&callList.dialog[n].sdp_info);
                                        }
                                        else if (mmi_voip_is_addr_change
                                                 (&g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].sdp_info,
                                                  &callList.dialog[n].sdp_info))
                                        {
                                            mmi_voip_remove_mixer_before_close(i);
                                        #ifdef __MMI_UCM__
                                            mmi_voip_ucm_speech_ind(g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle, FALSE, FALSE);
                                        #endif
                                            mmi_voip_close_rtp(g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle);
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle = mmi_voip_create_rtp(&callList.dialog[n].sdp_info);
                                        }
                                        memcpy(
                                            &g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].sdp_info,
                                            &callList.dialog[n].sdp_info,
                                            sizeof(voip_sdp_struct));
                                        mmi_voip_switch_rtp(FALSE, callId, dialogId);
                                        if (!mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].startTime))
                                        {
                                            DTGetRTCTime(&currTime);
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].startTime = currTime;
                                        }
                                    }
                                    memset(
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dispName,
                                        0,
                                        (VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    mmi_chset_convert(
                                        MMI_CHSET_UTF8,
                                        MMI_CHSET_UCS2,
                                        (char*)callList.dialog[n].user_addr.disp_name,
                                        (char*)g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dispName,
                                        (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    /* it could be a transfer case if uri changes, need to update appName */
                                    if (strncmp(
                                        (S8*)g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri, 
                                        (S8*)callList.dialog[n].user_addr.uri, 
                                        VOIP_URI_LEN))
                                    {
                                        memset(
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].appName, 
                                            0, 
                                            (VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    }
                                    memset(
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri,
                                        0,
                                        VOIP_URI_LEN);
                                    memcpy(
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri,
                                        callList.dialog[n].user_addr.uri,
                                        VOIP_URI_LEN);
                                    mmi_voip_convert_uri_star_n_pound(g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri);
                                    break;
                                }
                            }
                            m++;
                            if (n == VOIP_MAX_NUM_DIALOG)   /* delete dialog entry */
                            {
                                if (mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].startTime))
                                {
                                    memset(&duration, 0, sizeof(MYTIME));
                                    mmi_voip_log_call_end_time(callId, dialogId, &duration);
                                    memset(popupStr, 0, MAX_SUB_MENU_SIZE);
                                    mmi_voip_get_call_end_string(&duration, popupStr);
                                }
                                else
                                {
                                    memset(popupStr, 0, MAX_SUB_MENU_SIZE);
                                    mmi_ucs2cpy((S8*)popupStr, GetString(STR_ID_VOIP_CALL_END));
                                    MMI_ASSERT(popupStr[MAX_SUB_MENU_SIZE - 2] == '\0' && popupStr[MAX_SUB_MENU_SIZE - 1] == '\0');
                                }
                                if (isConf == TRUE)
                                {
                                    /* store actual call origin and actual start time for merge call or split call */
                                    g_voip_cntx_p->call_misc_info.actualOrigin =
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].callOrigin;
                                    g_voip_cntx_p->call_misc_info.actualTime =
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].startTime;
                                }
                                else    /* isConf == FALSE */
                                {
                                    /* do not log background reject call to call history and popup call end */
                                    if (g_voip_cntx_p->call_list_info.bkrejCId != callId)
                                    {
                                    #ifndef __MMI_UCM__
                                        /* outgoing call or incoming call doesn't have call duration */
                                        if (!mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].startTime))
                                        {
                                            mmi_voip_log_call_history(
                                                callId,
                                                dialogId,
                                                g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].callOrigin,
                                                FALSE);
                                        }
                                        else
                                        {
                                            mmi_voip_log_call_duration(
                                                callId,
                                                dialogId,
                                                g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].callOrigin);
                                        }
                                        mmi_voip_entry_popup(popupStr, IMG_ID_VOIP_CALL_ENDED);
                                    #endif
                                    }
                                    else
                                    {
                                        PRINT_INFORMATION("\n[mmi_voip_update_to_del_call_list] It is possible\n");
                                    }
                                }
                                mmi_voip_del_from_call_list(callId, dialogId);
                                m--;
                            }
                        }
                        else    /* dialogId == -1, break the loop because mmi call list is sorted */
                        {
                            break;
                        }
                    }
                    m = 0;  /* reset m to check next call id's dialog */
                    break;
                }
            }
            i++;
            if (j == g_voip_cntx_p->call_list_info.maxnumCall)  /* delete call entry */
            {
                /* dialogId is invalid at the moment, so get the first dialog id to show call end popup */
                dialogId = g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].dialogId;
                if (mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].startTime))
                {
                    memset(&duration, 0, sizeof(MYTIME));
                    mmi_voip_log_call_end_time(callId, dialogId, &duration);
                    memset(popupStr, 0, MAX_SUB_MENU_SIZE);
                    mmi_voip_get_call_end_string(&duration, popupStr);
                }
                else    /* outgoing call or incoming call */
                {
                    memset(popupStr, 0, MAX_SUB_MENU_SIZE);
                    mmi_ucs2cpy((S8*)popupStr, GetString(STR_ID_VOIP_CALL_END));
                    MMI_ASSERT(popupStr[MAX_SUB_MENU_SIZE - 2] == '\0' && popupStr[MAX_SUB_MENU_SIZE - 1] == '\0');
                }
                if (isConf == TRUE)
                {
                    /* store actual call origin and actual start time for merge call or split call */
                    g_voip_cntx_p->call_misc_info.actualOrigin =
                        g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].callOrigin;
                    g_voip_cntx_p->call_misc_info.actualTime =
                        g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].startTime;
                }
                else    /* isConf == FALSE */
                {
                    /* do not log background reject call to call history and popup call end */
                    if (g_voip_cntx_p->call_list_info.bkrejCId != callId)
                    {
                    #ifndef __MMI_UCM__
                        /* outgoing call or incoming call doesn't have call duration */
                        if (!mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].startTime))
                        {
                            mmi_voip_log_call_history(
                                callId,
                                dialogId,
                                g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].callOrigin,
                                FALSE);
                        }
                        else
                        {
                            mmi_voip_log_call_duration(
                                callId,
                                dialogId,
                                g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].callOrigin);
                        }
                        mmi_voip_entry_popup(popupStr, IMG_ID_VOIP_CALL_ENDED);
                    #endif
                    }
                    else
                    {
                        PRINT_INFORMATION("\n[mmi_voip_update_to_del_call_list] It is possible\n");
                    }
                }
                mmi_voip_del_from_call_list(callId, dialogId);
                i--;
            }
            FS_Close(fileHandle);
        }
        else    /* callId == -1, break the loop because mmi call list is sorted */
        {
            break;
        }
    }
    i = 0;  /* reset i */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_to_add_call_list
 * DESCRIPTION
 *  Second pass of updating call list from voip cc to mmi.
 *  Add mmi call list entry that mmi call list does not have.
 * PARAMETERS
 *  fileName            [IN]            Voip cc call list file, path included
 *  isConf              [IN]            Display popup or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_to_add_call_list(U16 *fileName, MMI_BOOL isConf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle = 0;
    U32 fileLen = 0;
    S32 result = 0;
    voip_call_struct callList;
    S32 i = 0, j = 0, m = 0, n = 0, callId = 0, dialogId = 0, freeTab = 0;
    MYTIME currTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fileHandle = FS_Open(fileName, FS_READ_ONLY);
    if (fileHandle < 0)
    {
        MMI_ASSERT(fileHandle >= 0);
    }

    for (j = 0; j < g_voip_cntx_p->call_list_info.maxnumCall; j++)
    {
        result = FS_Read(fileHandle, &callList, sizeof(voip_call_struct), &fileLen);
        if (result != FS_NO_ERROR)
        {
            MMI_ASSERT(result == FS_NO_ERROR);
        }

        if ((callList.is_bk_call == FALSE) && 
            ((callList.call_state == VOIP_CALL_STATE_CONFIRMED) ||  
            (callList.call_state == VOIP_CALL_STATE_ACCEPTING))) /* accept call complete before remote ack */
        {
            for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
            {
                callId = g_voip_cntx_p->call_list_info.call_info[i].callId;
                if (callList.call_id == callId)
                {
                    for (n = 0; n < VOIP_MAX_NUM_DIALOG; n++)
                    {
                        if (callList.dialog[n].in_use == TRUE)
                        {
                            for (m = 0; m < VOIP_MAX_NUM_DIALOG; m++)
                            {
                                dialogId = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dialogId;
                                if (callList.dialog[n].dialog_id == dialogId)
                                {
                                    break;
                                }
                            }
                            if (m == VOIP_MAX_NUM_DIALOG)   /* add dialog entry */
                            {
                                for (m = 0; m < VOIP_MAX_NUM_DIALOG; m++)
                                {
                                    if (g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dialogId == -1)
                                    {
                                        g_voip_cntx_p->call_list_info.call_info[i].numDialog++;
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dialogId =
                                            callList.dialog[n].dialog_id;
                                        if ((g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_ACTIVE_STATE) || 
                                            (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLD_STATE))
                                        {
                                            if (g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle == -1)
                                            {
                                                g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle = mmi_voip_create_rtp(&callList.dialog[n].sdp_info);
                                            }
                                            memcpy(
                                                &g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].sdp_info,
                                                &callList.dialog[n].sdp_info,
                                                sizeof(voip_sdp_struct));
                                            mmi_voip_switch_rtp(FALSE, callList.call_id, callList.dialog[n].dialog_id);
                                            if (!mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].startTime))
                                            {
                                                DTGetRTCTime(&currTime);
                                                g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].startTime = currTime;
                                            }
                                        }
                                        memset(
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dispName,
                                            0,
                                            (VOIP_DISP_NAME_LEN * sizeof(U16)));
                                        mmi_chset_convert(
                                            MMI_CHSET_UTF8,
                                            MMI_CHSET_UCS2,
                                            (char*)callList.dialog[n].user_addr.disp_name,
                                            (char*)g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dispName,
                                            (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
                                        /* it could be a transfer case if uri changes, need to update appName */
                                        if (strncmp(
                                            (S8*)g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri, 
                                            (S8*)callList.dialog[n].user_addr.uri, 
                                            VOIP_URI_LEN))
                                        {
                                            memset(
                                                g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].appName, 
                                                0, 
                                                (VOIP_DISP_NAME_LEN * sizeof(U16)));
                                        }
                                        memset(
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri,
                                            0,
                                            VOIP_URI_LEN);
                                        memcpy(
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri,
                                            callList.dialog[n].user_addr.uri,
                                            VOIP_URI_LEN);
                                        mmi_voip_convert_uri_star_n_pound(g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri);
                                        if (isConf == TRUE)
                                        {
                                            /* update mixer's information for the other dialog */
                                            mmi_voip_switch_rtp(
                                                FALSE,
                                                g_voip_cntx_p->call_list_info.call_info[i].callId,
                                                g_voip_cntx_p->call_list_info.call_info[i].dialog_info[0].dialogId);
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].callOrigin =
                                                g_voip_cntx_p->call_misc_info.actualOrigin;
                                            g_voip_cntx_p->call_misc_info.actualOrigin = MMI_VOIP_NONE_ORIGIN;
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].startTime =
                                                g_voip_cntx_p->call_misc_info.actualTime;
                                            memset(&g_voip_cntx_p->call_misc_info.actualTime, 0, sizeof(MYTIME));
                                        }
                                        break;
                                    }
                                }
                                if (m == VOIP_MAX_NUM_DIALOG)
                                {
                                    MMI_ASSERT(0);  /* no available dialog entry */
                                }
                            }
                        }
                    }
                    break;
                }
            }
            if (i == MMI_VOIP_MAX_NUM_CALL) /* add call entry */
            {
                freeTab = g_voip_cntx_p->call_misc_info.currfreeTab;
                if (freeTab != -1)
                {
                    for (n = 0; n < VOIP_MAX_NUM_DIALOG; n++)
                    {
                        if (callList.dialog[n].in_use == TRUE)
                        {
                            g_voip_cntx_p->call_list_info.call_info[freeTab].callId = callList.call_id;
                            g_voip_cntx_p->call_list_info.call_info[freeTab].currState = mmi_voip_get_call_state_enum(callList.dialog[n].dialog_state);
                            for (m = 0; m < VOIP_MAX_NUM_DIALOG; m++)
                            {
                                if ((g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_HOLD_STATE) && (m == 0))    /* only update held call count according to the first dialog */
                                {
                                    g_voip_cntx_p->call_list_info.numHeld++;
                                }
                                if (g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].dialogId == -1)
                                {
                                    g_voip_cntx_p->call_list_info.call_info[freeTab].numDialog++;
                                    g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].dialogId =
                                        callList.dialog[n].dialog_id;
                                    if ((g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_ACTIVE_STATE) ||
                                        (g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_HOLD_STATE))
                                    {
                                        if (g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].rtpHandle == -1)
                                        {
                                            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].rtpHandle = mmi_voip_create_rtp(&callList.dialog[n].sdp_info);
                                        }
                                        memcpy(
                                            &g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].sdp_info,
                                            &callList.dialog[n].sdp_info,
                                            sizeof(voip_sdp_struct));
                                        mmi_voip_switch_rtp(FALSE, callList.call_id, callList.dialog[n].dialog_id);
                                        if (!mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].startTime))
                                        {
                                            DTGetRTCTime(&currTime);
                                            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].startTime = currTime;
                                        }
                                    }
                                    memset(
                                        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].dispName,
                                        0,
                                        (VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    mmi_chset_convert(
                                        MMI_CHSET_UTF8,
                                        MMI_CHSET_UCS2,
                                        (char*)callList.dialog[n].user_addr.disp_name,
                                        (char*)g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].dispName,
                                        (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    /* it could be a transfer case if uri changes, need to update appName */
                                    if (strncmp(
                                        (S8*)g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].remoteUri, 
                                        (S8*)callList.dialog[n].user_addr.uri, 
                                        VOIP_URI_LEN))
                                    {
                                        memset(
                                            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].appName, 
                                            0, 
                                            (VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    }
                                    memset(
                                        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].remoteUri,
                                        0,
                                        VOIP_URI_LEN);
                                    memcpy(
                                        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].remoteUri,
                                        callList.dialog[n].user_addr.uri,
                                        VOIP_URI_LEN);
                                    mmi_voip_convert_uri_star_n_pound(g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].remoteUri);
                                    if (isConf == TRUE)
                                    {
                                        /* update mixer's information for the other dialog */
                                        mmi_voip_switch_rtp(
                                            FALSE,
                                            g_voip_cntx_p->call_list_info.call_info[freeTab].callId,
                                            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].dialogId);
                                        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].callOrigin =
                                            g_voip_cntx_p->call_misc_info.actualOrigin;
                                        g_voip_cntx_p->call_misc_info.actualOrigin = MMI_VOIP_NONE_ORIGIN;
                                        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[m].startTime =
                                            g_voip_cntx_p->call_misc_info.actualTime;
                                        memset(&g_voip_cntx_p->call_misc_info.actualTime, 0, sizeof(MYTIME));
                                    }
                                    break;
                                }
                            }
                            if (m == VOIP_MAX_NUM_DIALOG)
                            {
                                MMI_ASSERT(0);  /* no available dialog entry */
                            }
                            g_voip_cntx_p->call_list_info.numTotal++;
                            g_voip_cntx_p->call_misc_info.currfreeTab++;
                            if (g_voip_cntx_p->call_misc_info.currfreeTab == MMI_VOIP_MAX_NUM_CALL)
                            {
                                g_voip_cntx_p->call_misc_info.currfreeTab = -1; /* call capacity full */
                            }
                        }
                    }
                }
                else
                {
                    /* do not assert in case four calls + one will-be-bk-reject call */
                    PRINT_INFORMATION("\n[mmi_voip_update_to_add_call_list] No Available Call Entry, Ignore and Wait to Background Reject\n");
                }
            }
        }
    }
    FS_Close(fileHandle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_summary_string
 * DESCRIPTION
 *  Prepare current status display string.
 * PARAMETERS
 *  unicodeStr          [IN/OUT]            Current status string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_summary_string(U8 *unicodeStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 profIndex = 0;
    U8 colon[4] = { ':', '\0', '\0', '\0' }; /* : */
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    U8 slash[4] = { '/', '\0', '\0', '\0' }; /* / */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Login/Logout: */
    mmi_ucs2cpy((S8*)unicodeStr, GetString(STR_ID_VOIP_LOGIN));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)slash);
    mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_LOGOUT));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
    mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    
    profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;
    if (profIndex != -1)
    {
        if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
        {
            mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_REGISTER));
            mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
            mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        }
        else
        {
            mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_NOT_REGISTER));
            mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
            mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        }
        
        mmi_voip_update_prof_common_cache_to_disp(profIndex);
        /* Profile Name: */
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_COMMON_PROFNAME));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.profileName);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);

        mmi_voip_update_prof_acct_cache_to_disp(profIndex);
        /* SIP Server/SIP Port: */
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_ACCOUNT_SIPSERVER));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)slash);
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_ACCOUNT_SIPPORT));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);

        /* Username: */
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_USERNAME));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);

        /* Display Name: */
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_ACCOUNT_DISPNAME));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.displayName);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    }
    else
    {
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_NO_ACTIVATED_PROFILE));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    }    
    
    MMI_ASSERT(unicodeStr[MAX_SUB_MENUS * MAX_SUB_MENU_SIZE - 1] == '\0');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_call_state_enum
 * DESCRIPTION
 *  Map voip cc dialog state to mmi call state.
 * PARAMETERS
 *  state           [IN]            Voip cc dialog state
 * RETURNS
 *  MMI call state.
 *****************************************************************************/
mmi_voip_call_state_enum mmi_voip_get_call_state_enum(voip_dlg_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case VOIP_DLG_STATE_TERMINATED:
            return MMI_VOIP_IDLE_STATE;
        case VOIP_DLG_STATE_MO:
            return MMI_VOIP_OUTGOING_STATE;
        case VOIP_DLG_STATE_MT:
            return MMI_VOIP_INCOMING_STATE;
        case VOIP_DLG_STATE_WAIT_ACK: /* accept call complete before remote ack */
        case VOIP_DLG_STATE_ACTIVE:
            return MMI_VOIP_ACTIVE_STATE;
        case VOIP_DLG_STATE_HOLD:
            return MMI_VOIP_HOLD_STATE;
        case VOIP_DLG_STATE_TRANSFERING:
        case VOIP_DLG_STATE_TRANSFEREE:
            return MMI_VOIP_TRANSFER_STATE;
        case VOIP_DLG_STATE_TERMINATING:
            return MMI_VOIP_DISCONNECTING_STATE;
        default:
            return MMI_VOIP_CALL_STATE_TOTAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_call_end_string
 * DESCRIPTION
 *  Append string "Call End" in front of call duration.
 * PARAMETERS
 *  duration            [IN]            Duration of the call
 *  unicodeStr          [IN/OUT]        Call end string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_call_end_string(MYTIME *duration, U8 *unicodeStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    U8 *timeStr = OslMalloc(32);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) unicodeStr, GetString(STR_ID_VOIP_CALL_END));
    mmi_ucs2cat((S8*) unicodeStr, (S8*) newline);
    duration_string(duration, (UI_string_type) timeStr, DT_ACTIVE_CALL_SCREEN);
    mmi_ucs2cat((S8*) unicodeStr, (S8*) timeStr);

    OslMfree(timeStr);

    MMI_ASSERT(unicodeStr[MAX_SUB_MENU_SIZE - 2] == '\0' && unicodeStr[MAX_SUB_MENU_SIZE - 1] == '\0');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_dtmf_keycode_enum
 * DESCRIPTION
 *  Map mmi dtmf key to rtp dtmf key.
 * PARAMETERS
 *  keyCode         [IN]            Mmi dtmf key
 * RETURNS
 *  RTP dtmf key.
 *****************************************************************************/
rtp_dtmf_code_enum mmi_voip_get_dtmf_keycode_enum(U16 *keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (*keyCode)
    {
        case KEY_0:
            return RTP_DTMF_CODE_0;
        case KEY_1:
            return RTP_DTMF_CODE_1;
        case KEY_2:
            return RTP_DTMF_CODE_2;
        case KEY_3:
            return RTP_DTMF_CODE_3;
        case KEY_4:
            return RTP_DTMF_CODE_4;
        case KEY_5:
            return RTP_DTMF_CODE_5;
        case KEY_6:
            return RTP_DTMF_CODE_6;
        case KEY_7:
            return RTP_DTMF_CODE_7;
        case KEY_8:
            return RTP_DTMF_CODE_8;
        case KEY_9:
            return RTP_DTMF_CODE_9;
        case KEY_STAR:
            return RTP_DTMF_CODE_STAR;
        case KEY_POUND:
            return RTP_DTMF_CODE_HASH;
        default:
            return RTP_DTMF_CODE_TOTAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_error_cause
 * DESCRIPTION
 *  Map voip cc error cause to mmi error string.
 * PARAMETERS
 *  result          [IN]            Major result
 *  cause           [IN]            Minor cause
 * RETURNS
 *  String id of the error.
 *****************************************************************************/
U16 mmi_voip_get_error_cause(U8 result, S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case VOIP_ERROR:        /* failure happens in VoIP task */
        case VOIP_SIP_ERROR:    /* failure happens in SIP task */
        case VOIP_NAT_ERROR:    /* NAT related error */
            return mmi_voip_get_error_string(cause);
        case VOIP_FS_ERROR:     /* file system related error */
            return GetFileSystemErrorString(cause);
        default:
            return STR_ID_VOIP_UNKNOWN_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_error_string
 * DESCRIPTION
 *  Look up error table to get corresponding error string.
 * PARAMETERS
 *  cause           [IN]            Error cause
 * RETURNS
 *  String id of the error.
 *****************************************************************************/
U16 mmi_voip_get_error_string(S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, totalEntry = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totalEntry = sizeof(g_voip_error_table) / sizeof(mmi_voip_error_string_struct);

    for (i = 0; i < totalEntry; i++)
    {
        if (g_voip_error_table[i].errorNo == cause)
        {
            return g_voip_error_table[i].errorStr;
        }
    }
    return STR_ID_VOIP_UNKNOWN_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_set_outgoing_origin_app
 * DESCRIPTION
 *  Put phonebook or call history structure to g_voip_cntx_p->call_originapp_info.
 * PARAMETERS
 *  moOrigin        [IN]            Outgoing call origin, either MMI_VOIP_PHB or MMI_VOIP_HISTORY
 * RETURNS
 *  TRUE means outgoing call does dial from phonebook or call history; 
 *  FALSE means outgoing call neither dial from phonebook nor call history.
 *****************************************************************************/
MMI_BOOL mmi_voip_set_outgoing_origin_app(mmi_voip_mo_origin_enum moOrigin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PHB_VOIP_INTERFACE phbData;
    LOG_CALL logData;
    S32 uriLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (moOrigin)
    {
        case MMI_VOIP_PHB:
            phbData = mmi_phb_call_get_data_for_voip(g_voip_cntx_p->call_misc_info.dispUri, TRUE);
            if (phbData.dialInList == MMI_PHB_PHONEBOOK)
            {
                memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
                g_voip_cntx_p->call_originapp_info.moOrgin = MMI_VOIP_PHB;
                uriLen = (VOIP_DISP_NAME_LEN > mmi_ucs2strlen((S8*)phbData.name)) ?
                    (mmi_ucs2strlen((S8*)phbData.name)) : (VOIP_DISP_NAME_LEN - 1);
                mmi_ucs2ncpy((S8*)g_voip_cntx_p->call_originapp_info.dispName, (S8*)phbData.name, uriLen);
                mmi_ucs2_n_to_asc((S8*)g_voip_cntx_p->call_originapp_info.remoteUri, (S8*)phbData.uri, (VOIP_URI_LEN * ENCODING_LENGTH));
                return TRUE;
            }
            break;
        case MMI_VOIP_HISTORY:
            if (CHISTGetDialFromCallLogFlag() != 0)
            {
                memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
                CHISTGetCallLogName(&logData);
                g_voip_cntx_p->call_originapp_info.moOrgin = MMI_VOIP_HISTORY;
                uriLen = (VOIP_DISP_NAME_LEN > mmi_ucs2strlen((S8*)logData.pbName)) ?
                    (mmi_ucs2strlen((S8*)logData.pbName)) : (VOIP_DISP_NAME_LEN - 1);
                mmi_ucs2ncpy((S8*)g_voip_cntx_p->call_originapp_info.dispName, (S8*)logData.pbName, uriLen);
                mmi_ucs2_n_to_asc((S8*)g_voip_cntx_p->call_originapp_info.remoteUri, (S8*)logData.number, (VOIP_URI_LEN * ENCODING_LENGTH));
                return TRUE;
            }
            break;
        default:
            return FALSE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_outgoing_disp_name
 * DESCRIPTION
 *  Determine to show display name or not for outgoing call.
 * PARAMETERS
 *  moOrigin        [IN]            Outgoing call origin
 *  unicodeSrc      [IN]            Source uri string in unicode
 *  unicodeDest     [IN/OUT]        Destination uri string in unicode
 *  destLen         [IN]            Destination uri string length
 * RETURNS
 *  TRUE means outgoing call should show display name; 
 *  FALSE means outgoing call should not show display name.
 *****************************************************************************/
MMI_BOOL mmi_voip_get_outgoing_disp_name(U8 moOrigin, U8* unicodeSrc, U8* unicodeDest, U8 destLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 uriLen = 0;
    MMI_BOOL ret = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((moOrigin & MMI_VOIP_SOS) == MMI_VOIP_SOS)
    {
        if ((!mmi_ucs2cmp((S8*)unicodeSrc, (S8*)sos112)) || 
            (!mmi_ucs2cmp((S8*)unicodeSrc, (S8*)sos911)) ||
            (!mmi_ucs2cmp((S8*)unicodeSrc, (S8*)GetString(STR_ID_VOIP_EMERGENCY_NUM))))
        {
            uriLen = (destLen > mmi_ucs2strlen((S8*)GetString(STR_ID_VOIP_EMERGENCY_NUM))) ? 
                (mmi_ucs2strlen((S8*)GetString(STR_ID_VOIP_EMERGENCY_NUM))) : (destLen - 1);
            
            memset(unicodeDest, 0, (destLen * ENCODING_LENGTH));
            mmi_ucs2ncpy((S8*)unicodeDest, (S8*)GetString(STR_ID_VOIP_EMERGENCY_NUM), uriLen);
            ret = TRUE;
        }
    }
    if ((moOrigin & MMI_VOIP_HISTORY) == MMI_VOIP_HISTORY)
    {
        /* ensure the name from call history is not empty */
        if ((g_voip_cntx_p->call_originapp_info.moOrgin == MMI_VOIP_HISTORY) && 
            (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_originapp_info.dispName)))
        {
            uriLen = (destLen >= VOIP_DISP_NAME_LEN) ? (VOIP_DISP_NAME_LEN) : (destLen - 1);

            memset(unicodeDest, 0, (destLen * ENCODING_LENGTH));
            mmi_ucs2ncpy((S8*)unicodeDest, (S8*)g_voip_cntx_p->call_originapp_info.dispName, uriLen);
            ret = TRUE;
        }
    }
    if ((moOrigin & MMI_VOIP_PHB) == MMI_VOIP_PHB)
    {        
        /* ensure the name from phonebook is not empty */
        if ((g_voip_cntx_p->call_originapp_info.moOrgin == MMI_VOIP_PHB) && 
            (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_originapp_info.dispName)))
        {
            uriLen = (destLen >= VOIP_DISP_NAME_LEN) ? (VOIP_DISP_NAME_LEN) : (destLen - 1);

            memset(unicodeDest, 0, (destLen * ENCODING_LENGTH));
            mmi_ucs2ncpy((S8*)unicodeDest, (S8*)g_voip_cntx_p->call_originapp_info.dispName, uriLen);
            ret = TRUE;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_redial_string
 * DESCRIPTION
 *  Prepare redial display string.
 * PARAMETERS
 *  unicodeStr          [IN/OUT]            Redial string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_redial_string(U8 *unicodeStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    U8 *asciinumStr = OslMalloc(16);
    U8 *unicodenumStr = OslMalloc(32);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(asciinumStr, 0, 16);
    sprintf((S8*)asciinumStr, "%d / %d", (g_voip_cntx_p->call_redial_info.currAttempt + 1), g_voip_cntx_p->call_redial_info.maxAttempt);
    memset(unicodenumStr, 0, 32);
    mmi_asc_to_ucs2((S8*)unicodenumStr, (S8*)asciinumStr);
    mmi_ucs2cpy((S8*)unicodeStr, (S8*)unicodenumStr);
    mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_TIME_UNIT));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    
    OslMfree(asciinumStr);
    OslMfree(unicodenumStr);

    MMI_ASSERT(unicodeStr[MMI_VOIP_MAX_STRING_LEN - 1] == '\0');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_mwi_state_enum
 * DESCRIPTION
 *  Map voip cc message waiting type to mmi message waiting string.
 * PARAMETERS
 *  state           [IN]            Message waiting type
 * RETURNS
 *  String id of message waiting.
 *****************************************************************************/
U16 mmi_voip_get_mwi_state_enum(voip_mwi_type_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case VOIP_MWI_VOICE:
            return STR_ID_VOIP_VOICE_MESSAGE;
        case VOIP_MWI_FAX:
            return STR_ID_VOIP_FAX_MESSAGE;
        case VOIP_MWI_PAGER:
            return STR_ID_VOIP_PAGER_MESSAGE;
        case VOIP_MWI_MM:
            return STR_ID_VOIP_MULTIMEDIA_MESSAGE;
        case VOIP_MWI_TEXT:
            return STR_ID_VOIP_TEXT_MESSAGE;
        default:
            return STR_ID_VOIP_UNKNOWN_MESSAGE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_mwi_string
 * DESCRIPTION
 *  Prepare message waiting display string.
 * PARAMETERS
 *  unicodeStr          [IN/OUT]            Message waiting string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_mwi_string(U8 *unicodeStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    U8 *asciinumStr = OslMalloc(16);
    U8 *unicodenumStr = OslMalloc(32);
    U32 newMsg = 0, totalMsg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*)unicodeStr, GetString(STR_ID_VOIP_NEW_MESSAGE));
    mmi_ucs2cat((S8*)unicodeStr, (S8*) newline);
    newMsg = g_voip_cntx_p->msg_waiting_info.mwiMsg.newmsgs;
    totalMsg = g_voip_cntx_p->msg_waiting_info.mwiMsg.newmsgs + g_voip_cntx_p->msg_waiting_info.mwiMsg.oldmsgs;
    memset(asciinumStr, 0, 16);
    sprintf((S8*)asciinumStr, "%d / %d", newMsg, totalMsg);
    memset(unicodenumStr, 0, 32);
    mmi_asc_to_ucs2((S8*)unicodenumStr, (S8*)asciinumStr);
    mmi_ucs2cat((S8*)unicodeStr, (S8*)unicodenumStr);
    mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_MSG_UNIT));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);

    mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_URGENT_MESSAGE));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    if (g_voip_cntx_p->msg_waiting_info.mwiMsg.is_urgent_present == TRUE)
    {
        newMsg = g_voip_cntx_p->msg_waiting_info.mwiMsg.new_urgentmsgs;
        totalMsg =
            g_voip_cntx_p->msg_waiting_info.mwiMsg.new_urgentmsgs +
            g_voip_cntx_p->msg_waiting_info.mwiMsg.old_urgentmsgs;
        memset(asciinumStr, 0, 16);
        sprintf((S8*)asciinumStr, "%d / %d", newMsg, totalMsg);
        memset(unicodenumStr, 0, 32);
        mmi_asc_to_ucs2((S8*)unicodenumStr, (S8*)asciinumStr);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)unicodenumStr);
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_MSG_UNIT));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    }
    else
    {
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_NOT_SUPPORT));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    }
    
    OslMfree(asciinumStr);
    OslMfree(unicodenumStr);
    
    MMI_ASSERT(unicodeStr[MMI_VOIP_MAX_STRING_LEN - 1] == '\0');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_idle_state
 * DESCRIPTION
 *  Check if it is in the idle screen or screen saver.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means it is in idle screen or screen saver;
 *  FALSE means it is not in idle screen or screen saver.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_idle_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.IsOnIdleScreen || g_idle_context.ScreenSaverRunFlag)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_keypad_lock_state
 * DESCRIPTION
 *  Check if keypad is locked.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means it is in keypad lock; FALSE means it is not in keypad lock.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_keypad_lock_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_empty_profile
 * DESCRIPTION
 *  Check if the specific profile is empty.
 * PARAMETERS
 *  profIndex       [IN]        Index of intended to check profile
 * RETURNS
 *  TRUE means the specific profile is empty;
 *  FALSE means the specific profile is not empty.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_empty_profile(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_update_prof_common_cache_to_disp(profIndex);
    /* profile name is not default profile name, the profile is not empty */
    if (mmi_ucs2cmp(
            (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.profileName, 
            (S8*)GetString(STR_ID_VOIP_PROF_COMMON_PROF1 + profIndex)))
    {
        return FALSE;
    }
    /* voice mail server is not empty and is not "sip:", the profile is not empty */
    if (mmi_ucs2cmp(
            (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName, 
            (S8*)sipUri))
    {
        return FALSE;
    }

    mmi_voip_update_prof_acct_cache_to_disp(profIndex);
    if ((mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.displayName)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.authName)))
    {
        return FALSE;
    }
    /* port is not 5060, the profile is not empty */
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.sipPort != 5060)
    {
        return FALSE;
    }
    /* username is not empty and is not "sip:", the profile is not empty */
    if (mmi_ucs2cmp(
            (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username, 
            (S8*)sipUri))
    {
        return FALSE;
    }
    
    mmi_voip_update_prof_outbound_cache_to_disp(profIndex);
    if ((mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password)))
    {
        return FALSE;
    }
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.port != 0)
    {
        return FALSE;
    }

    mmi_voip_update_prof_register_cache_to_disp(profIndex);
    if ((mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password)))
    {
        return FALSE;
    }
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.port != 0)
    {
        return FALSE;
    }

    mmi_voip_update_prof_nat_cache_to_disp(profIndex);
    if ((mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)))
    {
        return FALSE;
    }
    if ((g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[0] != 0) || 
        (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[1] != 0) || 
        (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[2] != 0) || 
        (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[3] != 0))
    {
        return FALSE;
    }
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.stunPort != 3478)
    {
        return FALSE;
    }
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.refInterval != 0)
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_owner_number
 * DESCRIPTION
 *  Check if two strings are the same, regardless of the difference of capital or lowercase.
 * PARAMETERS
 *  unicodeSrc1         [IN]            String 1 in unicode
 *  unicodeSrc2         [IN]            String 2 in unicode
 * RETURNS
 *  TRUE means lowercase of the two strings are the same;
 *  FALSE means lowercase of the two strings are different.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_owner_number(U8 *unicodeSrc1, U8 *unicodeSrc2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *lowercaseSrc1 = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    U8 *lowercaseSrc2 = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(lowercaseSrc1, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_voip_convert_uri_lower_case(unicodeSrc1, lowercaseSrc1);
    memset(lowercaseSrc2, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_voip_convert_uri_lower_case(unicodeSrc2, lowercaseSrc2);
    if (!mmi_ucs2cmp((S8*)lowercaseSrc1, (S8*)lowercaseSrc2))
    {
        OslMfree(lowercaseSrc1);
        OslMfree(lowercaseSrc2);
        return TRUE;
    }
    else
    {
        OslMfree(lowercaseSrc1);
        OslMfree(lowercaseSrc2);
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_sos_number
 * DESCRIPTION
 *  Check if given uri is an emergency number, including 112, 911, sos...etc,
 *  regardless of the difference of capital or lowercase.
 * PARAMETERS
 *  unicodeUri         [IN]            Uri string in unicode
 * RETURNS
 *  TRUE means it is an emergency number;
 *  FALSE means it is not an emergency number.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_sos_number(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *copyUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    U8 *sipsosStr = OslMalloc(32);
    U8 asciiatStr[2], unicodeatStr[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(copyUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_ucs2ncpy((S8*)copyUri, (S8*)unicodeUri, VOIP_URI_LEN);
    mmi_voip_parse_uri(copyUri); /* do not modify unicodeUri directly because unicodeUri could be an empty uri */
    mmi_voip_convert_uri_lower_case(copyUri, copyUri);

    memset(asciiatStr, 0, 2);
    sprintf((S8*)asciiatStr, "@");
    memset(unicodeatStr, 0, 4);
    mmi_asc_to_ucs2((S8*)unicodeatStr, (S8*)asciiatStr);

    memset(sipsosStr, 0, 32);
    mmi_ucs2ncpy((S8*)sipsosStr, (S8*)sipUri, mmi_ucs2strlen((S8*)sipUri));
    mmi_ucs2ncat((S8*)sipsosStr, (S8*)sos112, mmi_ucs2strlen((S8*)sos112));
    mmi_ucs2cat((S8*)sipsosStr, (S8*)unicodeatStr);
    
    if (!mmi_ucs2ncmp((S8*)copyUri, (S8*)sipsosStr, mmi_ucs2strlen((S8*)sipsosStr)))
    {
        PRINT_INFORMATION("\n[mmi_voip_is_sos_number] Detect sip:112@ Pattern!\n");
        g_voip_cntx_p->call_misc_info.isSOS = TRUE;
    }

    memset(sipsosStr, 0, 32);
    mmi_ucs2ncpy((S8*)sipsosStr, (S8*)sipUri, mmi_ucs2strlen((S8*)sipUri));
    mmi_ucs2ncat((S8*)sipsosStr, (S8*)sos911, mmi_ucs2strlen((S8*)sos911));
    mmi_ucs2cat((S8*)sipsosStr, (S8*)unicodeatStr);

    if (!mmi_ucs2ncmp((S8*)copyUri, (S8*)sipsosStr, mmi_ucs2strlen((S8*)sipsosStr)))
    {
        PRINT_INFORMATION("\n[mmi_voip_is_sos_number] Detect sip:911@ Pattern!\n");
        g_voip_cntx_p->call_misc_info.isSOS = TRUE;
    }
    
    memset(sipsosStr, 0, 32);
    mmi_ucs2ncpy((S8*)sipsosStr, (S8*)sipUri, mmi_ucs2strlen((S8*)sipUri));
    mmi_ucs2ncat((S8*)sipsosStr, (S8*)sosUri, mmi_ucs2strlen((S8*)sosUri));
    mmi_ucs2cat((S8*)sipsosStr, (S8*)unicodeatStr);

    if (!mmi_ucs2ncmp((S8*)copyUri, (S8*)sipsosStr, mmi_ucs2strlen((S8*)sipsosStr)))
    {
        PRINT_INFORMATION("\n[mmi_voip_is_sos_number] Detect sip:sos@ Pattern!\n");
        g_voip_cntx_p->call_misc_info.isSOS = TRUE;
    }
    
    OslMfree(copyUri);
    OslMfree(sipsosStr);
    
    if (g_voip_cntx_p->call_misc_info.isSOS == TRUE)
    {
        memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_ucs2cpy((S8*)unicodeUri, (S8*)sos112);
        g_voip_cntx_p->call_misc_info.isSOS = FALSE;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_codec_compatible
 * DESCRIPTION
 *  Check if held call's codec is allowed to merge to active call before merging call.
 * PARAMETERS
 *  codecList               [IN]            Supported codec list of the held call.
 *  firstcodecOnly          [IN]            Only compare to the first codec in codec list.
 * RETURNS
 *  TRUE means the codecs are compatible to merge;
 *  FALSE means the codecs are not compatible to merge.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_codec_compatible(voip_codec_enum *codecList, MMI_BOOL firstcodecOnly)
{
#ifdef __MMI_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 codecSupport = 0, localCodec = 0;
    med_voip_codec_cap_struct codecDetail;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    voip_get_codec_cap(VOIP_ENCODE_DECODE, &codecSupport, &codecDetail);
    if (firstcodecOnly == TRUE)
    {
        /* current held call in-use codec must in the codec support list 
           so that two calls can be merged */
        if ((codecSupport & codecList[0]) != 0)
        {
            return TRUE;
        }
    }
    else
    {
        for (i = 0; i < VOIP_MAX_NUM_CODEC; i++)
        {
            localCodec |= codecList[i];
        }
        if ((codecSupport & localCodec) != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
#else
    /* always return true for modis and pc simulator */
    return TRUE;
#endif /* __MMI_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_addr_change
 * DESCRIPTION
 *  Check if sdp address or port is changed.
 * PARAMETERS
 *  mmiSdp          [IN]            Sdp in mmi, which represents last sdp info.
 *  voipSdp         [IN]            Sdp in voip cc, which represents current sdp info.
 * RETURNS
 *  TRUE means the sdp addr or port is changed;
 *  FALSE means the sdp addr and port is not changed.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_addr_change(voip_sdp_struct *mmiSdp, voip_sdp_struct *voipSdp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((strncmp((S8*) mmiSdp->local_addr, (S8*) voipSdp->local_addr, VOIP_MAX_IP_SEG_LEN)) ||
        (strncmp((S8*) mmiSdp->remote_addr, (S8*) voipSdp->remote_addr, VOIP_MAX_IP_SEG_LEN)) ||
        (mmiSdp->local_rtp_port != voipSdp->local_rtp_port) ||
        (mmiSdp->remote_rtp_port != voipSdp->remote_rtp_port) ||
        (mmiSdp->local_rtcp_port != voipSdp->local_rtcp_port) ||
        (mmiSdp->remote_rtcp_port != voipSdp->remote_rtcp_port))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_play_inbandtone
 * DESCRIPTION
 *  Start playing inband tone for outgoing call.
 *  It should be called after outgoing call screen displays.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_play_inbandtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_suspend_background_play();
    AudioPlayReq(TONE_RINGING_CALL_GSM, DEVICE_AUDIO_PLAY_INFINITE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_stop_inbandtone
 * DESCRIPTION
 *  Stop playing inband tone for outgoing call.
 *  It should be called before outgoing call screen disappears.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_stop_inbandtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioStopReq(TONE_RINGING_CALL_GSM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_play_incoming_tone
 * DESCRIPTION
 *  Determine to play ring tone or waiting tone for incoming call.
 *  It should be called after incoming call screen displays.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_play_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callId = mmi_voip_get_incoming_call_id();
    if (callId != -1)
    {
        if (g_voip_cntx_p->call_misc_info.playTone == MMI_VOIP_NONE)
        {
            if ((g_voip_cntx_p->call_list_info.numTotal == 1) && (GetTotalCallCount() == 0))
            {
                mdi_audio_suspend_background_play();
                mmi_voip_play_ringtone();
            }
            else
            {
                mdi_audio_suspend_background_play();
                mmi_voip_play_waitingtone();
            }
        }
        else if (g_voip_cntx_p->call_misc_info.playTone == MMI_VOIP_WAITING_TONE)
        {
            if ((g_voip_cntx_p->call_list_info.numTotal == 1) && (GetTotalCallCount() == 0))
            {
                mdi_audio_suspend_background_play();
                mmi_voip_play_ringtone();
            }
            else
            {
                /* do not replay waitingtone */
            }
        }
        else /* g_voip_cntx_p->call_misc_info.playTone == MMI_VOIP_RING_TONE */
        {
            /* do not replay ringtone */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_stop_incoming_tone
 * DESCRIPTION
 *  Determine to stop ring tone or waiting tone for incoming call.
 *  It should be called after incoming call screen disappears.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_stop_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_stop_ringtone();
    mmi_voip_stop_waitingtone();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_play_ringtone
 * DESCRIPTION
 *  Start playing ring tone for incoming call.
 *  It should be called after incoming call screen displays.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_play_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_misc_info.playTone = MMI_VOIP_RING_TONE;
    /* store alert type in playing ringtone for stopping ringtone later on. 
       it is to prevent alert type change in-call by bluetooth profile */
    g_voip_cntx_p->call_alert_info.alertType = GetMtCallAlertTypeEnum();
    g_voip_cntx_p->call_alert_info.ringtoneId = GetRingToneID();
    switch (g_voip_cntx_p->call_alert_info.alertType)
    {
        case MMI_RING:
            AudioPlayToneWithCallBack(g_voip_cntx_p->call_alert_info.ringtoneId, GetRingTypeEnum(), INCOMING_CALL_TONE);
            break;
        case MMI_VIBRATION_ONLY:
            VibratorOn();
            break;
        case MMI_VIBRATION_AND_RING:
            VibratorOn();
            AudioPlayToneWithCallBack(g_voip_cntx_p->call_alert_info.ringtoneId, GetRingTypeEnum(), INCOMING_CALL_TONE);
            break;
        case MMI_VIBRATION_THEN_RING:
            VibratorOn();
            StartTimer(CM_ALERT_NOTIFYDURATION_TIMER, VIB_THEN_RING_DURATION, mmi_voip_play_vibration_then_ring);
            break;
        case MMI_ALERT_NONE:
        case MMI_SILENT:
            break;
        default: /* set default as MMI_RING */
            AudioPlayToneWithCallBack(g_voip_cntx_p->call_alert_info.ringtoneId, GetRingTypeEnum(), INCOMING_CALL_TONE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_stop_ringtone
 * DESCRIPTION
 *  Stop playing ring tone for incoming call.
 *  It should be called before incoming call screen disappears.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_stop_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_misc_info.playTone = MMI_VOIP_NONE;
    switch (g_voip_cntx_p->call_alert_info.alertType)
    {
        case MMI_RING:
            if (g_voip_cntx_p->call_alert_info.ringtoneId < MAX_TONE_ID)
            {
                AudioStopReq(g_voip_cntx_p->call_alert_info.ringtoneId);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
        case MMI_VIBRATION_ONLY:
            VibratorOff();
            break;
        case MMI_VIBRATION_AND_RING:
            VibratorOff();
            if (g_voip_cntx_p->call_alert_info.ringtoneId < MAX_TONE_ID)
            {
                AudioStopReq(g_voip_cntx_p->call_alert_info.ringtoneId);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
        case MMI_VIBRATION_THEN_RING:
            StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
            VibratorOff();
            if (g_voip_cntx_p->call_alert_info.ringtoneId < MAX_TONE_ID)
            {
                AudioStopReq(g_voip_cntx_p->call_alert_info.ringtoneId);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
        case MMI_ALERT_NONE:
        case MMI_SILENT:
            break;
        default: /* set default as MMI_RING */
            if (g_voip_cntx_p->call_alert_info.ringtoneId < MAX_TONE_ID)
            {
                AudioStopReq(g_voip_cntx_p->call_alert_info.ringtoneId);
            }
            else
            {
                mdi_audio_stop_all();
            }            
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_play_vibration_then_ring
 * DESCRIPTION
 *  Start playing ring tone after vibration timer is expired.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_play_vibration_then_ring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
    VibratorOff();
    AudioPlayToneWithCallBack(g_voip_cntx_p->call_alert_info.ringtoneId, GetRingTypeEnum(), INCOMING_CALL_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_play_waitingtone
 * DESCRIPTION
 *  Start playing waiting tone for incoming call.
 *  It should be called after incoming call screen displays.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_play_waitingtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_misc_info.playTone = MMI_VOIP_WAITING_TONE;
    AudioPlayToneWithCallBack(TONE_CALL_WAITING, GetRingTypeEnum(), INCOMING_CALL_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_stop_waitingtone
 * DESCRIPTION
 *  Stop playing waiting tone for incoming call.
 *  It should be called before incoming call screen disappears.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_stop_waitingtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_misc_info.playTone = MMI_VOIP_NONE;
    AudioStopReq(TONE_CALL_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_play_droptone
 * DESCRIPTION
 *  Start playing call drop tone for call end.
 *  It should be called after the last call end popup displays.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_play_droptone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_suspend_background_play();
    AudioPlayReq(TONE_RADIO_NA, DEVICE_AUDIO_PLAY_ONCE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_stop_droptone
 * DESCRIPTION
 *  Stop playing call drop tone for call end.
 *  It should be called before last call end popup disappears.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_stop_droptone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioStopReq(TONE_RADIO_NA);
}
#endif /* __MMI_VOIP__ */

