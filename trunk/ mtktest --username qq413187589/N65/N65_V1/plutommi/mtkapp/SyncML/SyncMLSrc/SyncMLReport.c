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
 *    SyncMLReport.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#include "ProtocolEvents.h"
#include "App_mine.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"
#include "ToDoListDef.h"
#include "ToDoListEnum.h"
#include "CommonScreens.h"
#include "gui_inputs.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"


/*
 * Local Variable
 */
U8 syncml_display_info[1024];


/*
 * Global Variable
 */
extern syncml_context_struct g_syncml_context;


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_sync_report
 * DESCRIPTION
 *  Initialize global variables for sync report
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_sync_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.db_sync_result = 0;
    memset(&g_syncml_context.contact_ok_cnt[0], 0, 3 * sizeof(U16));
    g_syncml_context.contact_ng_cnt = 0;
    memset(&g_syncml_context.calendar_ok_cnt[0], 0, 3 * sizeof(U16));
    g_syncml_context.calendar_ng_cnt = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_database_sync_fail
 * DESCRIPTION
 *  Set database sync error flag
 * PARAMETERS
 *  db_type      [IN]            database type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_database_sync_fail(U8 db_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.db_sync_result |= db_type; /* SYNCML_DB_PHONEBOOK or SYNCML_DB_TODOLIST */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_report
 * DESCRIPTION
 *  Sync report entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sync_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 temp_line[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     *  (Title) Sync Report
     *
     *  Contact done/unfinished
     *  Add: 5
     *  Replace: 4
     *  Delete: 3
     *  Error: 2
     *
     *  Calendar done/unfinished
     *  ...
     */

    EntryNewScreen(SCR_ID_SYNC_REPORT, NULL, mmi_syncml_entry_sync_report, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_REPORT);

    /*
     * mmi_ucs2cpy((PS8) syncml_display_info, (PS8) L"Sync done\n");
     * mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
     */

    mmi_ucs2cpy((PS8)syncml_display_info, (PS8)L""); /* reset string */
    if (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK)
    {
        if (g_syncml_context.db_sync_result & SYNCML_DB_PHONEBOOK)
        {
            mmi_ucs2cpy((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_CON_NG));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_CON_CK));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
        }
        else
        {
            mmi_ucs2cpy((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_CON_OK));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_CLIENT));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_ADD));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.contact_ok_cnt[0]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_REPLACE));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.contact_ok_cnt[1]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_DELETE));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.contact_ok_cnt[2]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_ERROR));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.contact_ng_cnt);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_SERVER));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_ADD));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.svr_contact_ok_cnt[0]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_REPLACE));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.svr_contact_ok_cnt[1]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_DELETE));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.svr_contact_ok_cnt[2]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_ERROR));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.svr_contact_ng_cnt);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (mmi_ucs2cmp((PS8)syncml_display_info, (PS8)L"") != 0)
    {
        mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
    }

    if (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST)
    {
        if (g_syncml_context.db_sync_result & SYNCML_DB_TODOLIST)
        {
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_CAL_NG));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_CAL_CK));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
        }
        else
        {
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_CAL_OK));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_CLIENT));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_ADD));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.calendar_ok_cnt[0]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_REPLACE));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.calendar_ok_cnt[1]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_DELETE));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.calendar_ok_cnt[2]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_ERROR));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.calendar_ng_cnt);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_SERVER));
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) L"\n");
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_ADD));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.svr_calendar_ok_cnt[0]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_ID_SYNC_REPORT_REPLACE));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.svr_calendar_ok_cnt[1]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_DELETE));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.svr_calendar_ok_cnt[2]);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8) get_string(STR_GLOBAL_ERROR));
            kal_wsprintf((PU16) temp_line, ": %d\n", g_syncml_context.svr_calendar_ng_cnt);
            mmi_ucs2cat((PS8) syncml_display_info, (PS8)temp_line);
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    ShowCategory74Screen(
        STR_ID_SYNC_REPORT,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
#endif
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) syncml_display_info,
        mmi_ucs2strlen((const S8*)syncml_display_info),
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_change_sync_report_status
 * DESCRIPTION
 *  Switch sync report status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_change_sync_report_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    g_syncml_context.sync_report_status = (g_syncml_context.sync_report_status != 0) ? 0 : 1;
    mmi_syncml_update_settings_to_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_sync_report
 * DESCRIPTION
 *  "Sync Report" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_sync_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.sync_report_status)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_syncml_change_sync_report_status, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_syncml_change_sync_report_status, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_hint_sync_report
 * DESCRIPTION
 *  "Sync Report" menu hint handler
 * PARAMETERS
 *  index       [IN]            hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_hint_sync_report(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.sync_report_status)
    { 
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


#endif /* __SYNCML_SUPPORT__ */

