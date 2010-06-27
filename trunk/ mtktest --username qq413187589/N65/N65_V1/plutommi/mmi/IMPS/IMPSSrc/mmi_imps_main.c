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
 *  mmi_imps_main.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements main routines for IMPS application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_IMPS_MAIN_C
#define _MMI_IMPS_MAIN_C

#ifdef __MMI_IMPS__
/*  Include: MMI header file */

#include "CommonScreens.h"
#include "FileManagerGProt.h"


#include "wgui_inline_edit.h"

#include "mmi_imps_prot.h"
#include "mmi_imps_gprot.h"

/*  Include: PS header file */
/* ... Add More PS header */

mmi_imps_context_struct g_mmi_imps_cntx;
mmi_imps_context_struct *imps_p = &g_mmi_imps_cntx;

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


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_nvram
 * DESCRIPTION
 *  Init NVRAM data and some PS handlers right after power on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_init_ps_before_idle();
    mmi_imps_prof_read_nvram(IMPS_NVRAM_INIT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init
 * DESCRIPTION
 *  Init function for IMPS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_init_chat_hilite_hdlr();
    mmi_imps_init_common_hilite_hdlr();
    mmi_imps_init_contact_hilite_hdlr();
    mmi_imps_init_pa_hilite_hdlr();
    mmi_imps_init_prof_hilite_hdlr();

    mmi_imps_init_ps_pa_hdlr();
    mmi_imps_init_ps_gen_hdlr();
    
	mmi_imps_init_invite_icon_list();
	mmi_imps_init_mood_icon_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_reset_cntx
 * DESCRIPTION
 *  Reset context of IMPS application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_reset_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_cont_struct *cont;
    U8 ps_ready_state;  /* state to indicate if the PS is currently ready */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store ready state for resuming */
    ps_ready_state = imps_p->gen_info.ps_ready_state;

    /* reset global context */
    memset(&imps_p->gen_info, 0, sizeof(mmi_imps_general_info_struct));
    memset(&imps_p->chat_info, 0, sizeof(mmi_imps_chat_info_struct));
    memset(&imps_p->room_info, 0, sizeof(mmi_imps_room_info_struct));
    memset(&imps_p->invite_info, 0, sizeof(mmi_imps_invite_info_struct));

    /* store ready state for resuming */
    imps_p->gen_info.ps_ready_state = ps_ready_state;

    /* reset all contacts to REFRESH state */
    for (i = 1; i < IMPS_MAX_NO_CONT; i++)
    {
        cont = &imps_p->cont_info.cont_list[i];
        if (strlen((S8*) cont->id))
        {
            cont->comm_state = 0;
            cont->availability = IMPS_PA_USER_UNKNOWN;
        }
        else
        {
            break;
        }
    }
    /* reset state of group */
    for (i = 0; i < IMPS_MAX_NO_GROUP; i++)
    {
        imps_p->group_info.group_list[i].is_sync = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_notify_rac_ready
 * DESCRIPTION
 *  Function to indicate that the RAC is ready so that we can start auto-login
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_notify_rac_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.ps_ready_state |= IMPS_LOGIN_RAC_READY;
    mmi_imps_auto_login();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_notify_idle_reached
 * DESCRIPTION
 *  Notify IDLE screen is reached
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_notify_idle_reached(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.ps_ready_state |= IMPS_LOGIN_IDLE_REACHED;
    mmi_imps_auto_login();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_check_invite_in_idle
 * DESCRIPTION
 *  Check if there is any pending invite when go to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if there is some pending invitation; otherwise, FALSE.
 *****************************************************************************/
BOOL mmi_imps_check_invite_in_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->invite_info.reminder_flag)
    {
        if (g_keylock_context.gKeyPadLockFlag == 0)
        {
            mmi_imps_entry_invite_reminder();
        }
        else
        {
            mmi_imps_entry_invite_key_lokced(
                g_keylock_context.KeyLockLSKStringID,
                g_keylock_context.KeyLockLSKIconID,
                g_keylock_context.KeyLockRSKStringID,
                g_keylock_context.KeyLockRSKIconID);
        }

        return TRUE;
    }

    return FALSE;
}

#ifdef __MMI_IMPS_OTA__
/*****************************************************************************
 * FUNCTION
 *  mmi_imps_proc_cca_doc
 * DESCRIPTION
 *  Initialize IMPS ota and ready to handle CCA .
 * PARAMETERS
 *  config_id   [IN] used to show which application to configure
 *  hConfig     [IN] show handler of cca document
 * RETURNS
 *  void.
 *****************************************************************************/
void mmi_imps_proc_cca_doc(U16 config_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ota_init(config_id, hConfig);
    mmi_imps_handle_ota(config_id, hConfig);
}
#endif

#endif /* __MMI_IMPS__ */ /* #ifdef __MMI_IMPS__ */
#endif /* _MMI_IMPS_MAIN_C */ 

