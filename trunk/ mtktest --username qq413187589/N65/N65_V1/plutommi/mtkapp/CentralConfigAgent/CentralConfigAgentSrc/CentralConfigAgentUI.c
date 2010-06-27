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
 *  CentralConfigAgentUI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA UI Related Codes
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

#ifdef __MMI_CCA_SUPPORT__

/**************************************************************/
/**********************  Header Files *************************/
/**************************************************************/

#include "CentralConfigAgentGProt.h"

//#include "Wgui.h"
#include "commonscreens.h"
#include "SettingProfile.h"


#include "SmsGuiInterfaceType.h"
#include "SmsGuiInterfaceProt.h"

#include "gpioInc.h"    /* TurnOnBacklight */ 




/*****************************************************************/
/******* Constants / Structure / Variables Declaration ***********/
/*****************************************************************/
#define CCA_UI_POPUP_DURATION   2000
#define CCA_MAX_PREINFO_SIZE    400
#define CCA_MAX_POSTINFO_SIZE   400
#define CCA_MAX_AUTH_INPUT_SIZE CCA_MAX_PIN_CHARS+1

static U8 cca_preinfo_content[CCA_MAX_PREINFO_SIZE];
static U8 cca_postinfo_content[CCA_MAX_POSTINFO_SIZE];
static U8 cca_auth_input_buffer[CCA_MAX_AUTH_INPUT_SIZE * ENCODING_LENGTH];

static mmi_cca_source_ui_new_setting_ind_struct *cca_new_setting_ind = 0;
static U8 mmi_cca_is_setting_aborted = FALSE;

typedef struct cca_ui_auth_state_struct {
    struct cca_ui_auth_state_struct *next;
    S32 transID;
    S32 maxAttempts;
    S32 count;
} cca_ui_auth_state_struct;

static cca_ui_auth_state_struct *cca_auth_state_head = 0;
static int   cca_disable_popup = 0;



static int mmi_cca_is_allow_popup(void);
static void mmi_cca_reset_new_setting_ind_context(void);
static void mmi_cca_show_setting_is_abort_message(void);

/*****************************************************************/
/******************  External functions / variables **************/
/*****************************************************************/
extern S32 mmi_ucs2strlen(const S8 *arrOut);
extern S8 *mmi_ucs2cpy(S8 *strDestination, const S8 *strSource);
extern U16 mmi_asc_to_ucs2(S8 *pOutBuffer, S8 *pInBuffer);
extern S32 mmi_ucs2strlen(const S8 *arrOut);
extern int isInCall(void);
extern U16 GetCmMarkerScrnID(void);
extern pBOOL GetWapCallPresent(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_detach_auth_state
 * DESCRIPTION
 *  detach and return auth state of matching transID from list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
cca_ui_auth_state_struct* mmi_cca_ui_detach_auth_state(S32 transID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_ui_auth_state_struct *crtstate;
    cca_ui_auth_state_struct *prevstate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    crtstate = cca_auth_state_head;
    prevstate = 0;
    while(crtstate)
    {
        if (crtstate->transID == transID)
        {
            if (prevstate)
                prevstate->next = crtstate->next;
            else
                cca_auth_state_head = crtstate->next;
            break;
        }
        prevstate = crtstate;
        crtstate = crtstate->next;
    }
    if (crtstate)
        crtstate->next = 0;
    return crtstate;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_match_auth_state
 * DESCRIPTION
 *  return the auth state with matching transID, or create and add a new auth state struct to list
 *  the matched (or created) auth state object will be moved to first in list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
cca_ui_auth_state_struct* mmi_cca_ui_match_auth_state(S32 transID, S32 maxAttempts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_ui_auth_state_struct *crtstate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    crtstate = mmi_cca_ui_detach_auth_state(transID);

    if (!crtstate)
    {
        crtstate = mmi_cca_malloc_type(cca_ui_auth_state_struct);
        memset(crtstate, 0, sizeof(cca_ui_auth_state_struct));

        crtstate->transID = transID;
        crtstate->maxAttempts = maxAttempts;
    }

    crtstate->next = cca_auth_state_head;
    cca_auth_state_head = crtstate;

    return cca_auth_state_head;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_remove_auth_state
 * DESCRIPTION
 *  remove and free the auth state object matching specified transID from list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_remove_auth_state(S32 transID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_ui_auth_state_struct *crtstate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((crtstate=mmi_cca_ui_detach_auth_state(transID)) != 0)
        mmi_cca_mfree(crtstate);
}

static void
mmi_cca_ui_insert_screen_before_call_marker(U16 scrnID, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history hist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&hist, 0, sizeof(history));

    hist.scrnID = scrnID;
	hist.entryFuncPtr = entryFuncPtr;

	InsertHistoryBeforeThisScrnReference(GetCmMarkerScrnID(), &hist);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_entry_progressing
 * DESCRIPTION
 *  Entry Progressing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_entry_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guibuff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (isInCall() && IsScreenPresent(GetCmMarkerScrnID()))
    {
        mmi_cca_ui_insert_screen_before_call_marker(SCR_ID_CCA_PROGRESS, mmi_cca_ui_entry_progressing);
        return;
    }

    EntryNewScreen(SCR_ID_CCA_PROGRESS, NULL, mmi_cca_ui_entry_progressing, NULL);

    guibuff = GetCurrGuiBuffer(SCR_ID_CCA_PROGRESS);

    ShowCategory66Screen(
        STR_ID_CCA_PROGRESS_TITLE,
        IMG_ID_CCA_MAIN_ICON, 
        0, 
        0, 
        0, 
        0, 
        (U8*)get_string(STR_ID_CCA_PROGRESS_CONTENT),
        IMG_GLOBAL_PROGRESS,
        guibuff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_entry_settings_info
 * DESCRIPTION
 *  Entry Settings Info (construct info)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_entry_settings_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const cca_app_config_struct *crtConfig;
    S32 i;
    U8 isAppInterests, anyAppInterests;
    cca_iterator_struct *iter_datalist;
    U8 *crtAppName;
    S32 preinfo_len;
    U8 *preinfo_content_res;
    U8 preinfo_content_entry_pre_ascii[] = "\n * ";
    U8 preinfo_content_entry_pre_ucs2[10];
    cca_status_enum status;
    cca_core_data_struct *dataobj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    preinfo_len = 0;
    kal_mem_set(cca_preinfo_content, 0, sizeof(cca_preinfo_content));

    MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_UI_ENTRY_SETTINGS_INFO);
    
    preinfo_content_res = (U8*)get_string(STR_ID_CCA_PREINFO_CONTENT);
    preinfo_len = mmi_ucs2strlen((const S8*)preinfo_content_res);
    mmi_ucs2cpy((S8*)cca_preinfo_content, (const S8*)preinfo_content_res);

    mmi_asc_to_ucs2((S8*)preinfo_content_entry_pre_ucs2, (S8*)preinfo_content_entry_pre_ascii);

    
    iter_datalist = mmi_cca_oma_construct_appcheck_datalist(cca_context_g.hConfig);
    if (!iter_datalist)
    {
        mmi_cca_ui_handle_memfull();
        mmi_cca_configure_complete();
        return;
    }

    anyAppInterests = 0;
    while (1)
    {
        crtConfig = &(cca_app_config_g[i]);

        MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_CHECK_APP_CONFIG_ID,  i, crtConfig->config_id);
    
        if (crtConfig->config_id==0xFFFF)
            break;

        isAppInterests = 0;

        /* ensure level 1 node symbols are defined in APP's config (skip this app if none are found) */
        status = mmi_cca_doc_get_nodedata_by_param(iter_datalist, CCA_NS_L1NODEID, &dataobj);
        if (status == CCA_STATUS_OK)
        {
            S32 dtidx = 0;
            for ( ; dtidx < dataobj->size; dtidx++)
                if (mmi_cca_oma_is_node_symbol_exist((U16)(dataobj->values.i[dtidx]), crtConfig->l1node_symbols, crtConfig->num_l1node_symbols))
                    break;
            if (dtidx >= dataobj->size)
            {
                MMI_TRACE(CCA_TRACE_WARNING, MMI_CCA_CHECK_APP_L1NODE_NOT_FOUND, i, crtConfig->config_id);
                i++;
                continue;
            }
        }

        /* check if AppCheck callback exists */
        if (crtConfig->fpAppCheckDoc)
        {
            mmi_cca_iterator_restart(iter_datalist);
            if (crtConfig->fpAppCheckDoc(crtConfig->config_id, cca_context_g.hConfig, iter_datalist) == CCA_STATUS_OK)
                isAppInterests = 1;
            else
            {
                MMI_TRACE(CCA_TRACE_WARNING, MMI_CCA_CHECK_APP_APPCHECK_FAIL, i, crtConfig->config_id);
                i++;
                continue;
            }
        }

        /* check if AppID is defined */
        if (!isAppInterests && crtConfig->num_appids>0 && crtConfig->appids)
        {
            status = mmi_cca_oma_doc_contains_appid(cca_context_g.hConfig, crtConfig->appids, crtConfig->num_appids);
            if (status == CCA_STATUS_MEMFULL)
            {
                //mmi_cca_doc_datalist_release((cca_doc_node_datalist_struct*)(iter_datalist->head_node->next), 1);
                mmi_cca_doc_datalist_release((cca_doc_node_datalist_struct*)(iter_datalist->head_node), 1);
                mmi_cca_iterator_release(iter_datalist);
                mmi_cca_configure_complete();
                return;
            }

            isAppInterests = (status==CCA_STATUS_OK);

            if (!isAppInterests)
            {
                MMI_TRACE(CCA_TRACE_WARNING, MMI_CCA_CHECK_APP_APPID_NOT_FOUND, i, crtConfig->config_id);
            }

            MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_CHECK_APP_CHECK_STATUS, i, crtConfig->config_id, (status==CCA_STATUS_OK));
        }
        else
        {
            isAppInterests = 1;

            MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_CHECK_APP_CHECK_STATUS, i, crtConfig->config_id, 2);
            MMI_TRACE(CCA_TRACE_WARNING, MMI_CCA_CHECK_APP_APPID_NOT_DEFINED);
        }

        /* add APP name to settings info if it interested in this prov doc */
        if (isAppInterests)
        {
            ASSERT(cca_context_g.numApp < CCA_MAX_APPS);
            MMI_TRACE(CCA_TRACE_INFO, MMI_CCA_CHECK_APP_INCLUDED_APPNUM, i, crtConfig->config_id, cca_context_g.numApp);
    
            mmi_cca_new_config_result(crtConfig->config_id, CCA_STATUS_SETTING_SKIPPED);

            crtAppName = (U8*)get_string(mmi_cca_get_app_names(crtConfig->config_id));
            mmi_ucs2cpy((S8*)(cca_preinfo_content+((preinfo_len-1)*2)), (const S8*)preinfo_content_entry_pre_ucs2);
            preinfo_len += 4;
            //mmi_asc_to_ucs2((S8*)(cca_preinfo_content+((preinfo_len-1)*2)), (S8*)crtAppName);
            mmi_ucs2cpy((S8*)(cca_preinfo_content+((preinfo_len-1)*2)), (const S8*)crtAppName);
            preinfo_len += mmi_ucs2strlen((const S8*)crtAppName);
            anyAppInterests = 1;
        }
        i++;
    }

    /* release iterator and its data --> can remove the datalist release when iterator deep delete is implemented!*/
    //mmi_cca_doc_datalist_release((cca_doc_node_datalist_struct*)(iter_datalist->head_node->next), 1);
    mmi_cca_doc_datalist_release((cca_doc_node_datalist_struct*)(iter_datalist->head_node), 1);
    mmi_cca_iterator_release(iter_datalist);

    if (anyAppInterests)
        mmi_cca_ui_show_settings_info_screen();
    else
    {
        kal_mem_set(cca_preinfo_content, 0, sizeof(cca_preinfo_content));
        mmi_cca_ui_show_popup(STR_ID_CCA_NOAPP, IMG_GLOBAL_INFO);
        DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
        mmi_cca_configure_complete();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_show_settings_info_screen
 * DESCRIPTION
 *  Show Settings Info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_show_settings_info_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (isInCall() && IsScreenPresent(GetCmMarkerScrnID()))
    {
        if (IsScreenPresent(SCR_ID_CCA_PROGRESS))
            HistoryReplace(SCR_ID_CCA_PROGRESS, SCR_ID_CCA_PRE_INFO, mmi_cca_ui_show_settings_info_screen);
        else 
            mmi_cca_ui_insert_screen_before_call_marker(SCR_ID_CCA_PRE_INFO, mmi_cca_ui_show_settings_info_screen);
        return;
    }

    EntryNewScreen(SCR_ID_CCA_PRE_INFO, NULL, mmi_cca_ui_show_settings_info_screen, NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_CCA_PRE_INFO, (HistoryDelCBPtr)mmi_cca_ui_handle_settings_info_historydel);

    ShowCategory74Screen(
        STR_ID_CCA_PREINFO_TITLE,
        IMG_ID_CCA_MAIN_ICON, 
        STR_GLOBAL_INSTALL, 
        IMG_GLOBAL_OK, 
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK, 
        (U8*)cca_preinfo_content,
        (S32)CCA_MAX_PREINFO_SIZE,
        NULL);
    
    SetRightSoftkeyFunction(mmi_cca_ui_handle_settings_info_rsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_cca_ui_handle_settings_info_rsk, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_cca_ui_handle_settings_info_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_cca_ui_handle_settings_info_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_settings_info_rsk
 * DESCRIPTION
 *  Settings Info RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_settings_info_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_show_abort(mmi_cca_ui_handle_settings_info_abort);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_settings_info_abort
 * DESCRIPTION
 *  Settings Info RSK ABORT handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_settings_info_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(cca_preinfo_content, 0, sizeof(cca_preinfo_content));
    SetDelScrnIDCallbackHandler(SCR_ID_CCA_PRE_INFO, NULL);

    mmi_cca_configure_complete();
    DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_CCA_PRE_INFO);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_settings_info_lsk
 * DESCRIPTION
 *  Settings Info LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_settings_info_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(cca_preinfo_content, 0, sizeof(cca_preinfo_content));
    SetDelScrnIDCallbackHandler(SCR_ID_CCA_PRE_INFO, NULL);

    if (IsScreenPresent(SCR_ID_CCA_PROGRESS))
        GoBackHistory();
    else
    {
        mmi_cca_ui_entry_progressing();
        DeleteScreenIfPresent(SCR_ID_CCA_PRE_INFO);
    }

    mmi_cca_oma_new_doc_continue();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_settings_info_historydel
 * DESCRIPTION
 *  Settings Info Delete Notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_cca_ui_handle_settings_info_historydel(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(cca_preinfo_content, 0, sizeof(cca_preinfo_content));
    mmi_cca_configure_complete();

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_entry_summary_report
 * DESCRIPTION
 *  Entry Summary Report screen (construct info)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_entry_summary_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 report_len;
    //U8 report_content[CCA_MAX_POSTINFO_SIZE];
    U8 report_content_entry_post_ascii[] = ":\n  ";
    U8 report_content_newline_ascii[] = "\n\n";
    U8 report_content_entry_post_ucs2[12];
    U8 report_content_newline_ucs2[8];
    U8 *crtAppName;
    U8 *strDone;
    U8 *strInvalid;
    U8 *strSkipped;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_cca_ui_show_popup(STR_GLOBAL_DONE, IMG_GLOBAL_ACTIVATED);


    strDone = (U8*)get_string(STR_ID_CCA_CONFIGURED);
    strInvalid = (U8*)get_string(STR_ID_CCA_INVALID_SETTING);
    strSkipped = (U8*)get_string(STR_ID_CCA_SETTING_SKIPPED);

    mmi_asc_to_ucs2((S8*)report_content_entry_post_ucs2, (S8*)report_content_entry_post_ascii);
    mmi_asc_to_ucs2((S8*)report_content_newline_ucs2, (S8*)report_content_newline_ascii);
    memset(cca_postinfo_content, 0, sizeof(cca_postinfo_content));
    report_len = 0;
    for (i=0; i<cca_context_g.numApp; i++)
    {
        crtAppName = (U8*)get_string(mmi_cca_get_app_names(cca_context_g.configResult[i].config_id));
        mmi_ucs2cpy((S8*)cca_postinfo_content+(report_len*2), (const S8*)crtAppName);
        report_len += mmi_ucs2strlen((const S8*)crtAppName);

        mmi_ucs2cpy((S8*)cca_postinfo_content+(report_len*2), (const S8*)report_content_entry_post_ucs2);
        report_len += mmi_ucs2strlen((const S8*)report_content_entry_post_ucs2);

        switch (cca_context_g.configResult[i].result)
        {
            case CCA_STATUS_OK:
                mmi_ucs2cpy((S8*)cca_postinfo_content+(report_len*2), (const S8*)strDone);
                report_len += mmi_ucs2strlen((const S8*)strDone);
                break;
            case CCA_STATUS_INVALID_SETTING:
                mmi_ucs2cpy((S8*)cca_postinfo_content+(report_len*2), (const S8*)strInvalid);
                report_len += mmi_ucs2strlen((const S8*)strInvalid);
                break;
            case CCA_STATUS_SETTING_SKIPPED:
            default:
                mmi_ucs2cpy((S8*)cca_postinfo_content+(report_len*2), (const S8*)strSkipped);
                report_len += mmi_ucs2strlen((const S8*)strSkipped);
                break;
        }
        mmi_ucs2cpy((S8*)cca_postinfo_content+(report_len*2), (const S8*)report_content_newline_ucs2);
        report_len += mmi_ucs2strlen((const S8*)report_content_newline_ucs2);
    }

    mmi_cca_ui_show_summary_report_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_show_summary_report_screen
 * DESCRIPTION
 *  Show Summary Report screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_show_summary_report_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && IsScreenPresent(GetCmMarkerScrnID()))
    {
        if (IsScreenPresent(SCR_ID_CCA_PROGRESS))
            HistoryReplace(SCR_ID_CCA_PROGRESS, SCR_ID_CCA_POST_INFO, mmi_cca_ui_show_summary_report_screen);
        else
            mmi_cca_ui_insert_screen_before_call_marker(SCR_ID_CCA_POST_INFO, mmi_cca_ui_show_summary_report_screen);
        return;
    }

    EntryNewScreen(SCR_ID_CCA_POST_INFO, NULL, mmi_cca_ui_show_summary_report_screen, NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_CCA_POST_INFO, (HistoryDelCBPtr)mmi_cca_ui_handle_summary_report_historydel);

    ShowCategory74Screen(
        STR_ID_CCA_POSTINFO_TITLE,
        IMG_ID_CCA_MAIN_ICON, 
        STR_GLOBAL_OK, 
        IMG_GLOBAL_OK, 
        0,
        0, //U16 right_softkey_icon,
        (U8*)cca_postinfo_content,
        (S32)CCA_MAX_POSTINFO_SIZE,
        NULL);

    DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
    
    SetLeftSoftkeyFunction(mmi_cca_ui_handle_summary_report_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_cca_ui_handle_summary_report_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_summary_report_lsk
 * DESCRIPTION
 *  Handle Summary Report screen LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_summary_report_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(cca_postinfo_content, 0, sizeof(cca_postinfo_content));
    SetDelScrnIDCallbackHandler(SCR_ID_CCA_POST_INFO, NULL);

    mmi_cca_configure_complete();
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_summary_report_historydel
 * DESCRIPTION
 *  Handle Summary Report screen Delete Notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_cca_ui_handle_summary_report_historydel(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(cca_postinfo_content, 0, sizeof(cca_postinfo_content));
    mmi_cca_configure_complete();

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_memfull
 * DESCRIPTION
 *  Handle memory full scenario (ie, show MemFull popup)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_memfull(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_show_popup(STR_ID_CCA_MEMFULL, IMG_GLOBAL_ERROR);
    DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_common_cancel
 * DESCRIPTION
 *  Show abort/cancel confirmation screen with text specified by text_str_id
 *  function triggers cancel_cb when dialog's LSK has been pressed
 * PARAMETERS
 *  text_str_id     [in]
 *  cancel_cb       [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_common_cancel(U16 text_str_id, void (*cancel_cb)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DisplayConfirm(
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        (UI_string_type)get_string(text_str_id),
        (MMI_ID_TYPE)IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(cancel_cb, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_cca_ui_handle_abort_rsk, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_show_abort
 * DESCRIPTION
 *  Show abort confirmation screen
 * PARAMETERS
 *  abort_cb    [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_show_abort(void (*abort_cb)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel((U16)STR_ID_CCA_ABORT_ASK, abort_cb);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_abort_rsk
 * DESCRIPTION
 *  Handle abort confirmation screen RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_abort_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}








/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_show_popup
 * DESCRIPTION
 *  Show popup
 * PARAMETERS
 *  strid       [in]
 *  imgid       [in]
 *  duration    [in]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_show_popup(U16 strid, U16 imgid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (isInCall() && !GetWapCallPresent() && IsScreenPresent(GetCmMarkerScrnID()))
    {
        MMI_TRACE(CCA_TRACE_WARNING, MMI_CCA_UI_SHOW_POPUP_IN_CALL, strid, imgid);

        return;
    }

    if (!mmi_cca_is_allow_popup())
        return;

    DisplayPopup(
        (U8*)get_string(strid),
        imgid,
        0,  // imageOnBottom --> not used
        CCA_UI_POPUP_DURATION,
        ERROR_TONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_idle_check
 * DESCRIPTION
 *  Check whether CCA needs to display any popup/confirmation on idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_cca_idle_check(void)
{
    return (cca_new_setting_ind != NULL || mmi_cca_is_setting_aborted != 0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_entry_idle_screen
 * DESCRIPTION
 *  Entry IDLE Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_entry_idle_screen(void)
{
    if (cca_new_setting_ind || mmi_cca_is_setting_aborted)
    {
        mmi_cca_ui_entry_new_setting_conf_screen();
    }
    mmi_cca_is_setting_aborted = FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_entry_new_setting_conf_screen
 * DESCRIPTION
 *  Show accept New Setting confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_entry_new_setting_conf_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msgStr[250];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cca_new_setting_ind->sim_id == MMI_CCA_SIM_ID_SIM1)
        mmi_ucs2cpy((S8*)msgStr, (S8*)GetString(STR_ID_CCA_INSTALL_NEW_SIM1_SETTING));
    else if (cca_new_setting_ind->sim_id == MMI_CCA_SIM_ID_SIM2)
        mmi_ucs2cpy((S8*)msgStr, (S8*)GetString(STR_ID_CCA_INSTALL_NEW_SIM2_SETTING));
    else
        mmi_ucs2cpy((S8*)msgStr, (S8*)GetString(STR_ID_CCA_NEW_SETTING_CONF_CONTENT));

    if (!mmi_cca_is_setting_aborted)
        EntryNewScreen(SCR_ID_CCA_NEW_SETTING_CONF, mmi_cca_ui_exit_new_setting_conf_screen, NULL, NULL);

    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        ShowCategory154Screen(
            STR_ID_CCA_NEW_SETTING_CONF_TITLE,
            IMG_ID_CCA_MAIN_ICON, 
            STR_GLOBAL_INSTALL,
            IMG_GLOBAL_OK, 
            STR_GLOBAL_CANCEL,
            IMG_GLOBAL_BACK, 
            (U8*)msgStr,
            0,  
            IMG_GLOBAL_QUESTION,
            NULL);

        if (mmi_cca_is_setting_aborted)
        {
            SetRightSoftkeyFunction(mmi_cca_show_setting_is_abort_message, KEY_EVENT_UP);
            SetKeyHandler(mmi_cca_show_setting_is_abort_message, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            
            SetLeftSoftkeyFunction(mmi_cca_show_setting_is_abort_message, KEY_EVENT_UP);
            SetKeyHandler(mmi_cca_show_setting_is_abort_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_cca_show_setting_is_abort_message, KEY_END, KEY_EVENT_DOWN);
        }
        else
        {
            SetRightSoftkeyFunction(mmi_cca_ui_handle_new_setting_conf_rsk, KEY_EVENT_UP);
            SetKeyHandler(mmi_cca_ui_handle_new_setting_conf_rsk, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            
            SetLeftSoftkeyFunction(mmi_cca_ui_handle_new_setting_conf_lsk, KEY_EVENT_UP);
            SetKeyHandler(mmi_cca_ui_handle_new_setting_conf_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            SetKeyHandler(mmi_cca_ui_handle_new_setting_conf_abort, KEY_END, KEY_EVENT_DOWN);
        }
    }
    else
    {
        ShowCategory154Screen(
            STR_ID_CCA_NEW_SETTING_CONF_TITLE,
            IMG_ID_CCA_MAIN_ICON, 
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*)msgStr,
            0,  //U8* message2
            IMG_GLOBAL_QUESTION,
            NULL);
    }
    if (mmi_cca_is_setting_aborted)
    {
        mmi_cca_show_setting_is_abort_message();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_new_setting_conf_lsk
 * DESCRIPTION
 *  Handle New Setting confirmation screen LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_new_setting_conf_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetDelScrnIDCallbackHandler(SCR_ID_CCA_NEW_SETTING_CONF, NULL);

    ASSERT(cca_new_setting_ind);
    mmi_cca_send_source_ui_new_setting_rsp(cca_new_setting_ind->trans_id, 
        cca_new_setting_ind->sim_id, CCA_STATUS_OK);
    mmi_cca_mfree(cca_new_setting_ind);
    cca_new_setting_ind = 0;
    
    if (IsScreenPresent(SCR_ID_CCA_PROGRESS))
        GoBackHistory();
    else
    {
        mmi_cca_ui_entry_progressing();
        DeleteScreenIfPresent(SCR_ID_CCA_NEW_SETTING_CONF);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_new_setting_conf_rsk
 * DESCRIPTION
 *  Handle New Setting confirmation screen RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_new_setting_conf_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_show_abort(mmi_cca_ui_handle_new_setting_conf_abort);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_new_setting_conf_abort
 * DESCRIPTION
 *  Handle abort New Setting confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_new_setting_conf_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetDelScrnIDCallbackHandler(SCR_ID_CCA_NEW_SETTING_CONF, NULL);

    ASSERT(cca_new_setting_ind);
    mmi_cca_send_source_ui_new_setting_rsp(cca_new_setting_ind->trans_id,
        cca_new_setting_ind->sim_id, CCA_STATUS_FAIL);
    mmi_cca_mfree(cca_new_setting_ind);
    cca_new_setting_ind = 0;

    DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_CCA_NEW_SETTING_CONF);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_exit_new_setting_conf_screen
 * DESCRIPTION
 *  Handle Exiting New Setting confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_exit_new_setting_conf_screen(void)
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
 *  mmi_cca_ui_entry_auth_screen
 * DESCRIPTION
 *  Entry PIN authentication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_entry_auth_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL, *inputBuffer = NULL;
    U16 inputBufferSize = 0, titleId = 0, imgId = 0, numItems = 0;
    S32 i = 0;
    U16 iconList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall()&& IsScreenPresent(GetCmMarkerScrnID()))
    {
        if (IsScreenPresent(SCR_ID_CCA_PROGRESS))
            HistoryReplace(SCR_ID_CCA_PROGRESS, SCR_ID_CCA_AUTH, mmi_cca_ui_entry_auth_screen);
        else
            mmi_cca_ui_insert_screen_before_call_marker(SCR_ID_CCA_AUTH, mmi_cca_ui_entry_auth_screen);
        return;
    }

    EntryNewScreen(SCR_ID_CCA_AUTH, mmi_cca_ui_exit_auth_screen, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CCA_AUTH);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_CCA_AUTH, &inputBufferSize);

    titleId = STR_ID_CCA_AUTH_TITLE;
	//imgId = 0;
    numItems = 2;
    //memset(cca_auth_input_buffer, 0, sizeof(cca_auth_input_buffer));

    /* Password caption */
    SetInlineItemCaption(
        wgui_inline_items + 0,
        (U8*) GetString(STR_ID_CCA_AUTH_CONTENT));

    /* Password */
    SetInlineItemActivation(wgui_inline_items + 1, INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        wgui_inline_items + 1,
        cca_auth_input_buffer,
        CCA_MAX_AUTH_INPUT_SIZE,
        INPUT_TYPE_NUMERIC_PASSWORD);
    //RightJustifyInlineItem(wgui_inline_items + 1);
    EnableInlineItemBoundary(wgui_inline_items + 1);
    //DisableInlineItemHighlight(wgui_inline_items + 1);
    EnableInlineItem(wgui_inline_items+1, 1);

    for (i = 0; i < numItems; i++)
    {
        if (i % 2)
        {
            iconList[i] = 0;
        }
        else
        {
            iconList[i] = imgId + (i / 2);
        }
    }
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, numItems, inputBuffer);
    }
    
    SetDelScrnIDCallbackHandler(SCR_ID_CCA_AUTH, (HistoryDelCBPtr)mmi_cca_ui_handle_auth_abort);
    SetCategory57ScreenRSKClear();
    ShowCategory57Screen(
        titleId,
        IMG_ID_CCA_MAIN_ICON, 
        STR_GLOBAL_SUBMIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        numItems,
        iconList,
        wgui_inline_items,
        0,
        NULL /* guiBuffer */);
    SetCategory57LeftSoftkeyFunction(mmi_cca_ui_handle_auth_lsk);
    //SetCategory57RightSoftkeyFunctions(mmi_cca_ui_handle_auth_rsk, mmi_cca_ui_handle_auth_rsk);
    SetCategory57RightSoftkeyFunctions(mmi_cca_ui_handle_auth_lsk, mmi_cca_ui_handle_auth_rsk);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_exit_auth_screen
 * DESCRIPTION
 *  Exit function of PIN authentication screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_exit_auth_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBuffSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_CCA_AUTH;
    h.entryFuncPtr = mmi_cca_ui_entry_auth_screen;
    GetCategoryHistory(h.guiBuffer);
    GetCategory57Data(h.inputBuffer);
    inputBuffSize = (U16) GetCategory57DataSize();
    AddNHistory(h, inputBuffSize);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_auth_lsk
 * DESCRIPTION
 *  Handle PIN authentication screen LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_auth_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pin_ascii[CCA_MAX_AUTH_INPUT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_ID_CCA_AUTH, NULL);

    if (mmi_ucs2strlen((const S8*)cca_auth_input_buffer) == 0)
    {
        mmi_cca_ui_show_popup(STR_ID_CCA_PIN_EMPTY, IMG_GLOBAL_ERROR);
        return;
    }

    cca_auth_state_head->count++;

    mmi_ucs2_to_asc((S8*)pin_ascii, (S8*)cca_auth_input_buffer);

    ASSERT(cca_auth_state_head);
    mmi_cca_send_source_ui_auth_rsp(cca_auth_state_head->transID, (S8*)pin_ascii, CCA_STATUS_OK);
    //GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_auth_rsk
 * DESCRIPTION
 *  Handle PIN authentication screen RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_auth_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_show_abort(mmi_cca_ui_handle_auth_abort);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_auth_abort
 * DESCRIPTION
 *  Handle abort auth screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_ui_handle_auth_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_ID_CCA_AUTH, NULL);

    ASSERT(cca_auth_state_head);
    mmi_cca_send_source_ui_auth_rsp(cca_auth_state_head->transID, 0, CCA_STATUS_ABORT);
    mmi_cca_ui_remove_auth_state(cca_auth_state_head->transID);

    DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
    DeleteScreenIfPresent(SCR_ID_CCA_AUTH);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_ui_handle_auth_historydel
 * DESCRIPTION
 *  Handle auth screen Delete Notify
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_cca_ui_handle_auth_historydel(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cca_auth_state_head);
    mmi_cca_send_source_ui_auth_rsp(cca_auth_state_head->transID, 0, CCA_STATUS_ABORT);
    mmi_cca_ui_remove_auth_state(cca_auth_state_head->transID);
    return FALSE;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_cca_source_ui_invalid_setting_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_source_ui_invalid_setting_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_invalid_setting_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_source_ui_invalid_setting_ind_struct*)msg;

    data->sim_id = mmi_cca_revise_sim_id(data->sim_id);

    switch (data->status)
    {
        case CCA_STATUS_FAIL:
            if (mmi_cca_is_allow_popup())
                mmi_cca_ui_show_popup(STR_ID_CCA_INVALID_SETTING, IMG_GLOBAL_ERROR);
            break;

        case CCA_STATUS_UNSUPPORTED_SETTING:
            if (mmi_cca_is_allow_popup())
                mmi_cca_ui_show_popup(STR_ID_CCA_UNSUPPORTED_SETTING, IMG_GLOBAL_ERROR);
            break;

        case CCA_STATUS_CORRUPTED_SETTING:
            if (mmi_cca_is_allow_popup())
                mmi_cca_ui_show_popup(STR_ID_CCA_CORRUPTED_SETTING, IMG_GLOBAL_ERROR);
            break;

        case CCA_STATUS_MISSING_DATA:
            if (mmi_cca_is_allow_popup())
                mmi_cca_ui_show_popup(STR_ID_CCA_MISSING_DATA, IMG_GLOBAL_ERROR);
            break;

		case CCA_STATUS_MEMFULL:
            mmi_cca_ui_handle_memfull();
            break;

        default:
            if (mmi_cca_is_allow_popup())
                mmi_cca_ui_show_popup(STR_ID_CCA_INVALID_SETTING, IMG_GLOBAL_ERROR);
            break;
    }
    DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_source_ui_new_setting_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_source_ui_new_setting_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_new_setting_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_source_ui_new_setting_ind_struct*)msg;

    data->sim_id = mmi_cca_revise_sim_id(data->sim_id);

    ASSERT(!cca_new_setting_ind);
    cca_new_setting_ind = mmi_cca_malloc_type(mmi_cca_source_ui_new_setting_ind_struct);
    kal_mem_cpy(cca_new_setting_ind, data, sizeof(mmi_cca_source_ui_new_setting_ind_struct));

    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME); 

    if (GetActiveScreenId() != IDLE_SCREEN_ID)
    {
        /* should add sim id to this API */
        if (mmi_cca_is_allow_popup())
        {
            if (data->sim_id == MMI_CCA_SIM_ID_SIM2)
            {
#ifdef __MMI_DUAL_SIM_MASTER__
                mmi_msg_set_msg_type_as_slave();
#endif
            }
            mmi_msg_entry_new_msg_popup(MSG_NEW_CCA_SETTING);
        }
    }
    else
    {
        EntryIdleScreen();
        PlayMessageArrivalTone();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_source_ui_auth_ind_hdlr
 * DESCRIPTION
 *  PRT_MMI_CCA_SOURCE_UI_AUTH_IND handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_source_ui_auth_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_auth_ind_struct *data;
    cca_ui_auth_state_struct *authstate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_cca_source_ui_auth_ind_struct*)msg;

    /*typedef struct cca_ui_auth_state_struct {
    struct cca_ui_auth_state_struct *next;
    S32 transID;
    S32 maxAttempts;
    S32 count;
    } cca_ui_auth_state_struct;*/

    /*LOCAL_PARA_HDR
    S32 trans_id;
    U16 spec_id;
    S32 max_attempts;  0=unlimited
    cca_status_enum status; CCA_STATUS_OK, CCA_STATUS_FAIL*/

    authstate = mmi_cca_ui_match_auth_state(data->trans_id, data->max_attempts);

    /* configuration source requested to abort authentication input, no signal sent to source */
    if (data->status == CCA_STATUS_ABORT)
    {
        mmi_cca_ui_show_popup(STR_ID_CCA_PIN_NO_MORE_RETRY, IMG_GLOBAL_ERROR);
        DeleteScreenIfPresent(SCR_ID_CCA_AUTH);
        DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
        mmi_cca_ui_remove_auth_state(authstate->transID);
        return;
    }

    /* authentication succeeded, release auth state */
    if (authstate->count>0 && data->status==CCA_STATUS_OK)
    {
        //DeleteScreenIfPresent(SCR_ID_CCA_AUTH);
        //DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
        if (IsScreenPresent(SCR_ID_CCA_PROGRESS))
        {
            if (!isInCall() || !IsScreenPresent(GetCmMarkerScrnID()))
                GoBackHistory();
        }
        else
        {
            mmi_cca_ui_entry_progressing();
            DeleteScreenIfPresent(SCR_ID_CCA_AUTH);
        }
        mmi_cca_ui_remove_auth_state(authstate->transID);
        return;
    }

    /* no more retries, show popup, release auth state */
    if (authstate->maxAttempts && authstate->count>=authstate->maxAttempts && data->status==CCA_STATUS_FAIL)
    {
        mmi_cca_ui_show_popup(STR_ID_CCA_PIN_NO_MORE_RETRY, IMG_GLOBAL_ERROR);
        DeleteScreenIfPresent(SCR_ID_CCA_AUTH);
        DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
        mmi_cca_send_source_ui_auth_rsp(authstate->transID, 0, CCA_STATUS_ABORT);
        mmi_cca_ui_remove_auth_state(authstate->transID);
        return;
    }

    memset(cca_auth_input_buffer, 0, sizeof(cca_auth_input_buffer));
    /* retry attempts */
    if (authstate->count>0 && data->status==CCA_STATUS_FAIL)
    {
        mmi_cca_ui_show_popup(STR_ID_CCA_PIN_RETRY, IMG_GLOBAL_ERROR);
        return;
    }

    /* first attempt */
    mmi_cca_ui_entry_auth_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_allow_popup
 * DESCRIPTION
 *  enable or disable to show the new setting or invalid setting popup on some
 *  application, such as video recorder or player, swFlash etc.
 * PARAMETERS
 *  allowed 0: enable; other disable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_allow_popup(U8 allowed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (allowed == 0)
        cca_disable_popup++;
    else
        cca_disable_popup--;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_is_allow_popup
 * DESCRIPTION
 *  check if allow to show the popup message
 * PARAMETERS
 *  allowed 0: enable; other disable
 * RETURNS
 *  void
 *****************************************************************************/
static int mmi_cca_is_allow_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (cca_disable_popup < 0)  
        cca_disable_popup = 0;
    return cca_disable_popup == 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_reset_new_setting_ind_context
 * DESCRIPTION
 *  reset the new setting indication context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cca_reset_new_setting_ind_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (cca_new_setting_ind)
    {
        mmi_cca_mfree(cca_new_setting_ind);
        cca_new_setting_ind = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_source_ui_new_setting_rsp_hdlr
 * DESCRIPTION
 *  MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cca_source_ui_new_setting_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_source_ui_new_setting_rsp_struct *data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    data = (mmi_cca_source_ui_new_setting_rsp_struct*)msg;

    if (data->response == CCA_STATUS_OK)
        return;

    mmi_cca_is_setting_aborted = TRUE;
    mmi_cca_reset_new_setting_ind_context();

    if (GetActiveScreenId() == IDLE_SCREEN_ID)
    {
         EntryIdleScreen();
    }
    else if (GetExitScrnID() == SCR_ID_CCA_NEW_SETTING_CONF || 
        GetExitScrnID() == SCR_ID_CCA_PROGRESS)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_CCA_NEW_SETTING_CONF);
        DeleteScreenIfPresent(SCR_ID_CCA_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cca_show_setting_is_abort_message
 * DESCRIPTION
 *  show "Setting is abort" message
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cca_show_setting_is_abort_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_show_popup(STR_ID_CCA_IS_SETTING_ABORTED, IMG_GLOBAL_ERROR);
}


#endif  /* __MMI_CCA_SUPPORT__ */


