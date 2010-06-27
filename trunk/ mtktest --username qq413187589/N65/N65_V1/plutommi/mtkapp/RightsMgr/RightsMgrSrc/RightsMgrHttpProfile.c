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

/*******************************************************************************
 * Filename:
 * ---------
 *  RightsMgrHttpProfile.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Http Profile screen of Rights Manager
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_RMGR__

#include "custom_mmi_default_value.h"
#include "RightsMgrProt.h"

#include "CommonScreens.h"
#include "SettingProfile.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static void mmi_rmgr_http_profile_done_go_back_to_rmgr_main(void);
static void mmi_rmgr_http_profile_entry_done(void);
static void mmi_rmgr_http_profile_highlight_hdlr(S32 menu_idx);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_http_profile_done_go_back_to_rmgr_main
 * DESCRIPTION
 *  Go back to RMGR main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_http_profile_done_go_back_to_rmgr_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_RMGR_MAIN))
    {
        GoBackToHistory(SCR_ID_RMGR_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_http_profile_entry_done
 * DESCRIPTION
 *  Entry function of http profile done screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_http_profile_entry_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->http_profile_idx = mmi_rmgr_p->http_profile_hilite_idx;
    DisplayPopupCallBack(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE,
        mmi_rmgr_http_profile_done_go_back_to_rmgr_main);

    DeleteScreenIfPresent(SCR_ID_RMGR_HTTP_PROFILE_MAIN);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_http_profile_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of the http profile main screen
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_http_profile_highlight_hdlr(S32 menu_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->http_profile_hilite_idx = menu_idx;
}

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_http_profile_entry_main
 * DESCRIPTION
 *  Entry function of http profile main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_http_profile_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_HTTP_PROFILE_MAIN, NULL, mmi_rmgr_http_profile_entry_main, NULL);

    for (i = 0; i < MMI_RMGR_MAX_HTTP_PROFILE_NUM; i++)
    {
        subMenuDataPtrs[i] = (U8*) L"<http>";
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_HTTP_PROFILE_MAIN);

    RegisterHighlightHandler(mmi_rmgr_http_profile_highlight_hdlr);

    /* set high item as current http profile setting */
    mmi_rmgr_p->http_profile_hilite_idx = mmi_rmgr_p->http_profile_idx;

    ShowCategory36Screen(
        STR_ID_RMGR,
        IMG_ID_RMGR_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_RMGR_MAX_HTTP_PROFILE_NUM,
        subMenuDataPtrs,
        mmi_rmgr_p->http_profile_hilite_idx,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_rmgr_http_profile_entry_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* __MMI_RMGR__ */ 

