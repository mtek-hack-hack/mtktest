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
 * PushInboxCommonAPIs.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains all JDI wrappers.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_PUSHINBOXCOMMONAPI_C
#define _MMI_PUSHINBOXCOMMONAPI_C


#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "OrganizerDef.h"
#include "DateTimeGprot.h"

#include "settingGprots.h"

#include "wgui_status_icons.h"


#include "ddl.h"
#include "jcal.h"
#include "jdd_memapi.h"
#include "browserlayout.h"
#include "jdi_servicehandler.h"
#include "jdi_browserinterface.h"
#include "fsm.h"
#include "IdleAppDef.h"

#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JBrowserMMIGprots.h"

#include "JPushInboxCommonAPIs.h"

#define JDI_TO_MMI(ret_code) ret_code


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_push_statistics
 * DESCRIPTION
 *  Function to get the count of total and unread messages
 * PARAMETERS
 *  total_msg       [OUT]       Total number of messages
 *  unread_msg      [OUT]       Count of unread messages
 * RETURNS
 *  0 i.e. JC_OK in case of sucess.
 *  error-code in case of error
 *****************************************************************************/
U32 mmi_brw_get_push_statistics(U32 *total_msg, U32 *unread_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JDI_TO_MMI(jdi_BrowserPushGetStatistics(g_mmi_brw_pbrowser_ctxt, total_msg, unread_msg));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_push_servicelist
 * DESCRIPTION
 *  Function to get pointer to list of push messages.
 * PARAMETERS
 *  service_value_base      [OUT]       Pointer to list of push messages.
 * RETURNS
 *  0 i.e. JC_OK in case of sucess.
 *  error-code in case of error
 *****************************************************************************/
U32 mmi_brw_get_push_servicelist(SERVICE_VALUE **service_value_base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JDI_TO_MMI(jdi_BrowserPushGetServiceList(g_mmi_brw_pbrowser_ctxt, service_value_base));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_push_msg
 * DESCRIPTION
 *  Function to delete a push message.
 * PARAMETERS
 *  pos     [IN]        Index of push messages in jataayu list.
 * RETURNS
 *  0 i.e. JC_OK in case of sucess.
 *  error-code in case of error
 *****************************************************************************/
U32 mmi_brw_delete_push_msg(U32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JDI_TO_MMI(jdi_BrowserPushServiceDeleteEntry(g_mmi_brw_pbrowser_ctxt, pos));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_save_current_push_info
 * DESCRIPTION
 *  Function to save current push context.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 i.e. JC_OK in case of sucess.
 *  error-code in case of error
 *****************************************************************************/
U32 mmi_brw_save_current_push_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JDI_TO_MMI(jdi_BrowserPushSaveCurrentInfo(g_mmi_brw_pbrowser_ctxt));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_read_status
 * DESCRIPTION
 *  Function to set read status of a push message.
 * PARAMETERS
 *  is_read                 [IN]        Boolean value to set read status(1 for read, 0 for unread).
 *  service_value_base      [IN]        Pointer to a node in jataayu list for which the
 * RETURNS
 *  0 i.e. JC_OK in case of sucess.
 *  error-code in case of error
 *****************************************************************************/
U32 mmi_brw_set_read_status(pBOOL is_read, SERVICE_VALUE *service_value_base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JDI_TO_MMI(jdi_BrowserPushSetReadStatus(g_mmi_brw_pbrowser_ctxt, is_read, service_value_base));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_enable_push_Message
 * DESCRIPTION
 *  Function to enable or disable push message.
 * PARAMETERS
 *  is_enable_push      [IN]        Boolean value to enable or disable(1 for enable, 0 for disable).
 * RETURNS
 *  0 i.e. JC_OK in case of sucess.
 *  error-code in case of error
 *****************************************************************************/
U32 mmi_brw_enable_push_Message(pBOOL is_enable_push)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JDI_TO_MMI(jdi_BrowserEnablePushHandling(g_mmi_brw_pbrowser_ctxt, is_enable_push));
}

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* _MMI_PUSHINBOXCOMMONAPI_C */ 

