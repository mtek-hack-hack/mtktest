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
 * EmailAppMain.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements main utilities for Email application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : EmailAppMain.c

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : 30-01-2004

**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_EMAILAPPMAIN_C
#define _MMI_EMAILAPPMAIN_C

#ifdef __MMI_EMAIL__

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif
#include "EmailAppProt.h"
#include "EmailAppGProt.h"
#include "EmailAppResDef.h"
#include "ConnectManageGProt.h"

mmi_email_context_struct g_email_cntx;  /* global context of email */
mmi_email_context_struct *email_p = &g_email_cntx;
#ifdef __MMI_WLAN_FEATURES__
BOOL email_register_wlan_notifier = MMI_FALSE;
#endif
kal_uint8 app_cbm_id = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_email_init
 * DESCRIPTION
 *  Initialize Email application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_cbm_id == 0)
    {
        app_cbm_id = always_ask_register_app_id(STR_EMAIL_MAIN_ID);
    }
    mmi_email_init_hilite_hdlr();   /* highlight handler */
    mmi_email_init_protocol_hdlr(); /* protocol event handler */
    mmi_email_util_folder_init(MMI_TRUE);   /* mmi initailize just to delete the useless temporary file */
    mmi_email_ps_init_req();        /* initialize email module */
#ifdef __MMI_WLAN_FEATURES__
    if (!email_register_wlan_notifier)
    {
        mmi_wlan_add_event_notify_hdlr(mmi_email_wlan_hdlr);
        email_register_wlan_notifier = MMI_TRUE;
    }
#endif
#ifdef __USB_IN_NORMAL_MODE__
    /* the temporary folder will be deleted exactly once to ensure there is no dangling file in the temporary folder */
    if (mmi_usb_is_in_mass_storage_mode() &&
        ((email_p->main_info.ready_state & EMAIL_CLEAR_BUFF_DONE) == EMAIL_CLEAR_BUFF_DONE))
    {
        /* 
         * if it is reinit by usb normal mode and the folder has been deleted before (at least one email_init procedure successful before),
         * do not delete the temporary folder again because the folder may contain composed email attachment
         */
    }
    else
#endif /* __USB_IN_NORMAL_MODE__ */ 
    {
        email_p->main_info.ready_state |= EMAIL_CLEAR_BUFF_DONE;
        
        /* create dir again */
        mmi_email_util_create_working_dir();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_deinit
 * DESCRIPTION
 *  Deinitialize Email application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset EMAIL_PS_INIT_DONE bit but keep EMAIL_CLEAR_BUFF_DONE bit */
    email_p->main_info.ready_state = (email_p->main_info.ready_state >> 1) << 1;
    mmi_email_ps_deinit_req();  /* de-initialize email module */
}

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  mmi_email_check_to_deinit
 * DESCRIPTION
 *  A check function provided to usb normal mode before calling deinit function
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means email has to deinit; FALSE means email doesn't need to deinit
 *****************************************************************************/
U8 mmi_email_check_to_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filePath[20];
    S8 drive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef APP_STORAGE_IN_SYS_DRV
    /* Invisible NOR only */
    drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
#else /* APP_STORAGE_IN_SYS_DRV */ 
    /* Order: 1. Visible NOR 2. Invisible NOR */
    drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
#endif /* APP_STORAGE_IN_SYS_DRV */ 
    sprintf(filePath, "%c:\\@email\\", drive);
    /* no sim is inserted or email drive is not exported, email must not have to deinit */
    if ((email_p->main_info.ready_state == EMAIL_READY) && mmi_usb_check_path_exported(filePath))
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
 *  mmi_email_check_to_init
 * DESCRIPTION
 *  A check function provided to usb normal mode before calling init function
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means email has to init; FALSE means email doesn't need to init
 *****************************************************************************/
U8 mmi_email_check_to_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filePath[20];
    S8 drive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef APP_STORAGE_IN_SYS_DRV
    /* Invisible NOR only */
    drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
#else /* APP_STORAGE_IN_SYS_DRV */ 
    /* Order: 1. Visible NOR 2. Invisible NOR */
    drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
#endif /* APP_STORAGE_IN_SYS_DRV */ 
    sprintf(filePath, "%c:\\@email\\", drive);
    /* no sim is inserted or email drive is not exported, email must not have to deinit */
    if ((email_p->main_info.ready_state != EMAIL_READY) && mmi_usb_check_path_exported(filePath))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_stop_cause
 * DESCRIPTION
 *  Get stop cause of Email.
 * PARAMETERS
 *  void
 * RETURNS
 *  Stop cause of Email
 *****************************************************************************/
U8 mmi_email_util_get_stop_cause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_p->main_info.stop_cause;
}


#ifdef __MMI_WLAN_FEATURES__


/*****************************************************************************
 * FUNCTION
 *  mmi_email_wlan_hdlr
 * DESCRIPTION
 *  Get the wlan status.
 * PARAMETERS
 *  status          [IN]            wlan status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_wlan_hdlr(U16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((status == DTCNT_BEARER_STATE_CONNECTED) || (status == DTCNT_BEARER_STATE_INITIALIZED))
    {
        email_p->misc_info.is_wlan_valid = MMI_TRUE;
    }
    else if (status == DTCNT_BEARER_STATE_INACTIVE)
    {
        email_p->misc_info.is_wlan_valid = MMI_FALSE;
    }
    mmi_email_bearer_status_show_icon();
}
#endif /* __MMI_WLAN_FEATURES__ */ 

#endif /* __MMI_EMAIL__ */ 
#endif /* _MMI_EMAILAPPMAIN_C */ 

