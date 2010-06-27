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
 * VRSINameDial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the name dial function of VRSI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSINAMEDIAL_C
#define _MMI_VRSINAMEDIAL_C

#if defined(__MMI_VRSI__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "nvram_user_defs.h"
/* ... Add More MMI header */

#include "med_global.h"
#include "med_main.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "VRSIType.h"
#include "VRSIProt.h"
#include "VRSIResDef.h"
#include "MainMenuDef.h"

#include "PhonebookDef.h"
#include "PhonebookTypes.h"
#include "PhonebookProt.h"
#include "PhonebookGprot.h"
#include "CallManagementGprot.h"
#include "gpioInc.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "UCMGProt.h"
#include "MTPNP_PFAL_CC.h"
#endif  /*__MMI_DUAL_SIM_MASTER__*/

/*  Include: PS header file */
/* ... Add More PS header */

/* 
 * Typedef 
 */

/* 
 * Define
 */

/* 
 * Local Variable
 */

/* 
 * Local Function
 */

/* 
 * Global Variable
 */
extern U16 PhoneBookEntryCount;
extern U16 g_phb_name_index[];
extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[MAX_PB_ENTRIES];

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
extern PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
#endif 

/* 
 * Global Function
 */
#ifdef __GEMINI__
extern kal_bool is_sim_replaced(kal_uint8 simInterface);
#else
extern kal_bool is_sim_replaced(void);
#endif

#define MMI_VRSI_NDIAL_CENTRAL


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_phb_ready
 * DESCRIPTION
 *  Check if phonebook ready to add..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vrsi_ndial_central_phb_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if(MTPNP_PFAL_Phb_IsReady()==MTPNP_TRUE)
#else  /* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {
        return TRUE;
    }

    DisplayPopup(
        (PU8) GetString(STR_ID_VRSI_PROCESSING),
        IMG_GLOBAL_ERROR,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_add_all
 * DESCRIPTION
 *  This function add all dynamic central command for name dial.
 * PARAMETERS
 *  msg     [IN]        protocol handler callback message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_add_all(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, tag_num, add_count;
    U16 *name_list[MMI_VRSI_MAX_ADD_ENTRY];
    S32 long_list[MMI_VRSI_MAX_ADD_ENTRY];
    U8 is_name_list[MMI_VRSI_MAX_ADD_ENTRY];
    U16 id_list[MMI_VRSI_MAX_ADD_ENTRY];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort while adding central command. Will close engine in abort function, so return directly. */
    if (g_vrsi_cntx.vrsi_state != MMI_VRSI_STATE_ADDING_CMD)
    {
        return;
    }

    /* Phonebook not ready to be added. */
#ifdef __MMI_DUAL_SIM_MASTER__
    if(MTPNP_PFAL_Phb_IsReady()==MTPNP_FALSE)
#else  /* __MMI_DUAL_SIM_MASTER__ */
    if (!g_phb_cntx.phb_ready || g_phb_cntx.processing)
#endif   /* __MMI_DUAL_SIM_MASTER__ */
    {
        DisplayPopup(
            (PU8) GetString(STR_PROCESSING_PHONEBOOK),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        g_vrsi_cntx.vrsi_state = MMI_VRSI_STATE_CMD_NOT_READY;
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
        mdi_audio_vrsi_close();
        return;
    }

    add_count = g_vrsi_cntx.central_count;

    if (add_count < PhoneBookEntryCount)
    {
        tag_num =
            ((PhoneBookEntryCount - add_count) <
             MMI_VRSI_MAX_ADD_ENTRY) ? (PhoneBookEntryCount - add_count) : MMI_VRSI_MAX_ADD_ENTRY;

        for (i = 0; i < tag_num; i++)
        {
            name_list[i] = (U16*) PhoneBook[g_phb_name_index[i + add_count]].alpha_id.name;
            long_list[i] = g_phb_name_index[i + add_count];
            is_name_list[i] = TRUE;
        }

        /* Get session id for each add operation */
        g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

        /* Add SI tags */
        media_aud_vrsi_add_tags(
            MOD_MMI,
            g_vrsi_cntx.session_id,
            (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
            tag_num,
            name_list,
            long_list,
            is_name_list,
            id_list);

        add_count += tag_num;

        /* Print add fail messages. */
        mmi_vrsi_init_central_count_fail(tag_num, id_list, long_list);
    }

    g_vrsi_cntx.central_count = add_count;

    /* More central command to add */
    if (add_count < PhoneBookEntryCount)
    {
        mmi_vrsi_init_central_add_req();
    }
    else
    {
        mmi_vrsi_ndial_central_add_done();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_add_done
 * DESCRIPTION
 *  This function clear flag and add central command for next application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_add_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.central_count = 0;
    SetProtocolEventHandler(mmi_vrsi_scut_central_add_all, PRT_MMI_VRSI_ADD_CENTRAL_REQ);
    mmi_vrsi_init_central_add_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_add_single
 * DESCRIPTION
 *  This function add single dynamic central command for name dial.
 * PARAMETERS
 *  store_index     [IN]        index for command
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_add_single(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name_list[1];
    S32 long_list[1];
    U8 is_name_list[1];
    U16 id_list[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_vrsi_ndial_central_check_state_and_start())
    {
        return;
    }

    name_list[0] = (U16*) PhoneBook[store_index].alpha_id.name;
    long_list[0] = store_index;
    is_name_list[0] = TRUE;

    /* Get session id for each add operation */
    g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();

    media_aud_vrsi_add_tags(
        MOD_MMI,
        g_vrsi_cntx.session_id,
        (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
        1,
        name_list,
        long_list,
        is_name_list,
        id_list);

    mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    mdi_audio_vrsi_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_delete_single
 * DESCRIPTION
 *  This function delete single dynamic central command for name dial.
 * PARAMETERS
 *  store_index     [IN]        index for command
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_delete_single(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id[10]; /* delete at most 10 tags at one time, but there should be at most 2 tags (SI+SD) for one entry */
    S32 result;
    U16 tag_num = 0;
    kal_bool get_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete SD tag mapping table in NVRAM */
#if defined(__MMI_VRSI_TRAIN_TAG__)
    mmi_vrsi_train_util_del_tag(MMI_VRSI_APP_DIAL, store_index);
#endif 

    if (!mmi_vrsi_ndial_central_check_state_and_start())
    {
        return;
    }

    result = media_aud_vrsi_query_all_tag_ids(
                (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
                store_index,
                10,
                tag_id,
                &tag_num,
                &get_all);

    if (result != MED_RES_VRSI_OK)
    {
        mdi_audio_vrsi_close();
        return;
    }

    if (tag_num > 0)
    {
        media_aud_vrsi_del_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1], tag_num, tag_id);
    }

    mdi_audio_vrsi_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_change_single
 * DESCRIPTION
 *  This function change single dynamic central command for name dial.
 * PARAMETERS
 *  store_index     [IN]        index for command
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_change_single(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id[10]; /* delete at most 10 tags at one time, but there should be at most 2 tags (SI+SD) for one entry */
    S32 result;
    U16 tag_num = 0;
    kal_bool get_all;
    U16 *name_list[1];
    S32 long_list[1];
    U8 is_name_list[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_vrsi_ndial_central_check_state_and_start())
    {
        return;
    }

    result = media_aud_vrsi_query_all_tag_ids(
                (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
                store_index,
                10,
                tag_id,
                &tag_num,
                &get_all);

    /* Delete SI tag but Keep SD tag */
    if ((result == MED_RES_VRSI_OK) && (tag_num > 0))
    {
        /* Remove SD tag from list before deleting */
    #if defined(__MMI_VRSI_TRAIN_TAG__)
        U16 sd_tag_id;
        U16 i, j;

        mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_DIAL, store_index, &sd_tag_id);

        for (i = 0; i < tag_num; i++)
        {
            if (tag_id[i] == sd_tag_id)
            {
                for (j = i; j < tag_num; j++)
                {
                    tag_id[j] = tag_id[j + 1];
                }
                tag_num--;
            }
        }
    #endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

        /* Delete SI tags */
        if (tag_num > 0)
        {
            media_aud_vrsi_del_tags(MOD_MMI, (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1], tag_num, tag_id);
        }
    }

    /* Add SI tag back */
    name_list[0] = (U16*) PhoneBook[store_index].alpha_id.name;
    long_list[0] = store_index;
    is_name_list[0] = TRUE;

    /* Get session id for add operation */
    g_vrsi_cntx.session_id = mdi_audio_vrsi_new_session_id();
    media_aud_vrsi_add_tags(
        MOD_MMI,
        g_vrsi_cntx.session_id,
        (U8*) g_vrsi_grammar[MMI_VRSI_GRAMMAR_1],
        1,
        name_list,
        long_list,
        is_name_list,
        tag_id);

    mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    mdi_audio_vrsi_close();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_check_state_and_start
 * DESCRIPTION
 *  This function check VRSI engine state before add/delete/change.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vrsi_ndial_central_check_state_and_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not initialized, wait for vrsi to add all central command. */
    if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_CMD_NOT_READY)
    {
        return FALSE;
    }
    /*
     * Initializing, or Pause by other application ,
     * abort initial procedure and re-all all central command later.
     */
    else if (g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_CMD ||
             g_vrsi_cntx.vrsi_state == MMI_VRSI_STATE_ADDING_PAUSE)
    {
        mmi_vrsi_init_central_abort();
        /* mmi_vrsi_init_central_add_all(); */
        return FALSE;
    }

    /* Should be in idle state here. init SI engine to add command */
    result = mdi_audio_vrsi_init(mmi_vrsi_mdi_callback_hdlr);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_VRSI_FUNC_MDI_INIT_RESULT, result);

    if (result != MED_RES_OK)
    {
        return FALSE;
    }

    return TRUE;
}

#if defined(__MMI_VRSI_TRAIN_TAG__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_check_sim_change
 * DESCRIPTION
 *  This function check SIM change while enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vrsi_ndial_central_check_sim_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.sdtag_sync == 0)    /* Not confirm yet. */
    {
    #ifdef __GEMINI__
        if (is_sim_replaced(0) || is_sim_replaced(1))
    #else
        if (is_sim_replaced())
    #endif
        {
            if (mmi_vrsi_ndial_central_count_tag_in_sim() > 0)
            {
                DisplayConfirm(
                    STR_GLOBAL_YES,
                    IMG_GLOBAL_YES,
                    STR_GLOBAL_NO,
                    IMG_GLOBAL_NO,
                    get_string(STR_ID_VRSI_REFRESH_SIM),
                    IMG_GLOBAL_QUESTION,
                    WARNING_TONE);

                SetLeftSoftkeyFunction(mmi_vrsi_ndial_central_delete_sd_tag_in_sim, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_vrsi_ndial_central_add_after_check, KEY_EVENT_UP);

                return TRUE;
            }
        }
    }

    g_vrsi_cntx.sdtag_sync = 1;
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_count_tag_in_sim
 * DESCRIPTION
 *  This function get the SD tags associate to SIM card.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_vrsi_ndial_central_count_tag_in_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == MMI_VRSI_APP_DIAL) &&
            (tag_list[i].tag_long >= MAX_PB_PHONE_ENTRIES) && (tag_list[i].tag_long < MAX_PB_ENTRIES))
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_delete_sd_tag_in_sim
 * DESCRIPTION
 *  This function delete all SD tags associate to SIM card
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_delete_sd_tag_in_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i, tag_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read out mapping table and build ID list */
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if ((tag_list[i].app_id == MMI_VRSI_APP_DIAL) && (tag_list[i].tag_long >= MAX_PB_PHONE_ENTRIES) &&
            (tag_list[i].tag_long <= MAX_PB_ENTRIES))
        {
            memset(&tag_list[i], 0xff, sizeof(vrsi_sd_tag_struct));
            tag_num++;
        }
    }

    /* delete mapping table only, the tag in engine will be deleted later when sync with engine */
    if (tag_num > 0)
    {
        /* Delete mapping in NVRAM */
        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);
    }

    /* Continue to add all central command */
    mmi_vrsi_ndial_central_add_after_check();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_add_after_check
 * DESCRIPTION
 *  This function add central command after SIM change check.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_add_after_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.sdtag_sync = 1;

    GoBackHistory();
    mmi_vrsi_init_central_add_all();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_central_update_sd_mapping
 * DESCRIPTION
 *  This function update NVRAM mapping table according to phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_central_update_sd_mapping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrsi_sd_tag_struct tag_list[MMI_VRSI_MAX_SD_TAG];
    S16 pError;
    U16 i;
    U8 has_mapping = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_VRSI_TAG_LID, 1, (void*)tag_list, MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct), &pError);

    for (i = 0; i < MMI_VRSI_MAX_SD_TAG; i++)
    {
        if (tag_list[i].app_id == MMI_VRSI_APP_DIAL)
        {
            if (!mmi_phb_util_check_entry_exist(tag_list[i].tag_long))
            {
                memset(&tag_list[i], 0xff, sizeof(vrsi_sd_tag_struct));
                has_mapping = 1;
            }
        }
    }

    if (has_mapping)
    {
        WriteRecord(
            NVRAM_EF_VRSI_TAG_LID,
            1,
            (void*)tag_list,
            MMI_VRSI_MAX_SD_TAG * sizeof(vrsi_sd_tag_struct),
            &pError);
    }

}
#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ 

#define MMI_VRSI_NDIAL_COMMON


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_get_index
 * DESCRIPTION
 *  This function get the current highlight index
 * PARAMETERS
 *  nIndex      [IN]        current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_get_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.active_index = (U16) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_rcg_grammar1_result
 * DESCRIPTION
 *  This function handle the recognition result for grammar 1 in name dial scenario
 * PARAMETERS
 *  tag_num         [IN]        result tag number
 *  long_list       [IN]        result index list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_rcg_grammar1_result(U16 tag_num, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Single Record */
    if (tag_num == 1)
    {
        store_index = (U16) long_list[0];
        g_vrsi_cntx.long_list[0] = store_index;

        /* Not a phonebook entry */
        if ((store_index >= MAX_PB_ENTRIES) || !mmi_phb_util_check_entry_exist(store_index))
        {
            /* Play prompt TTS for not found */
            mmi_vrsi_util_play_tts((U16*) GetString(STR_ID_VRSI_RCG_NOT_FOUND), mmi_vrsi_entry_rcg);
            return;
        }

        /* Post Command Selected */
        if (g_vrsi_cntx.post_cmd != 0)
        {
            mmi_vrsi_ndial_pre_confirm_dial(g_vrsi_cntx.post_cmd);
        }
        else    /* Multiple Number */
        {
            g_vrsi_cntx.retry = 0;
            g_vrsi_cntx.active_index = 0;
            mmi_vrsi_entry_ndial_multiple_number();
        }
    }
    /* Multiple Record */
    else if (tag_num > 1)
    {
        g_vrsi_cntx.long_list_num = (tag_num < MMI_VRSI_MAX_RCG_RESULT) ? tag_num : MMI_VRSI_MAX_RCG_RESULT;

        for (i = 0; (i < g_vrsi_cntx.long_list_num) && (i < MMI_VRSI_MAX_RCG_RESULT); i++)
        {
            g_vrsi_cntx.long_list[i] = (U16) long_list[i];
        }

        g_vrsi_cntx.retry = 0;
        g_vrsi_cntx.active_index = 0;
        mmi_vrsi_entry_ndial_multiple_record();
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_rcg_grammar1_result_check
 * DESCRIPTION
 *  This function check the recognition result for grammar 1 in name dial scenario
 * PARAMETERS
 *  tag_num         [IN]        result tag number
 *  long_list       [IN]        result index list
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_vrsi_ndial_rcg_grammar1_result_check(U16 tag_num, S32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U16 *index_list;
    U16 pos, temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_list = OslMalloc(sizeof(U16) * tag_num);
    memset(index_list, 0xff, sizeof(U16) * tag_num);

    /* Build phonebook sorting index list */
    for (i = 0; i < tag_num; i++)
    {
        for (j = 0; j < PhoneBookEntryCount; j++)
        {
            if (g_phb_name_index[j] == long_list[i])
            {
                index_list[i] = j;
                break;
            }
        }
    }

    /* Sort result */
    pos = 0;
    while (pos < tag_num)
    {
        for (i = (pos + 1); i < tag_num; i++)
            if (index_list[pos] > index_list[i])
            {
                temp = index_list[pos];
                index_list[pos] = index_list[i];
                index_list[i] = temp;
            }
        pos++;
    }

    /* Count and assign valid item */
    temp = 0;
    for (i = 0; i < tag_num; i++)
        if (index_list[i] != 0xffff)
        {
            long_list[i] = g_phb_name_index[index_list[i]];
            temp++;
        }

    OslMfree(index_list);
    return temp;
}

#define MMI_VRSI_NDIAL_MULTIPLE_NUMBER


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_multiple_number
 * DESCRIPTION
 *  Entry multiple number screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_multiple_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    U8 loc_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, (S8*) PhoneBook[g_vrsi_cntx.long_list[0]].alpha_id.name);
    loc_count = mmi_vrsi_ndial_multiple_number_show_data(str_prompt);

    if (!loc_count)
    {
        mmi_vrsi_ndial_no_number_prompt();
        return;
    }
    else if (loc_count == 1)
    {
        g_vrsi_cntx.retry = 0;
        mmi_vrsi_entry_ndial_confirm_dial();
        return;
    }

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_NAME_DIAL_MULTI_NUM, mmi_vrsi_exit_ndial_multiple_number, NULL, NULL);

    RegisterHighlightHandler(mmi_vrsi_entry_ndial_get_index);

    ShowCategory53Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_DIAL,
        0,
        STR_GLOBAL_ABORT,
        0,
        loc_count,
        subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        g_vrsi_cntx.active_index,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_SEND, KEY_EVENT_UP);

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_2;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NAME_DIAL;

    mmi_vrsi_ndial_multiple_number_prompt(str_prompt);

    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ndial_multiple_number
 * DESCRIPTION
 *  Exit multiple number screen. Close engine if next screen is not in scenario.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ndial_multiple_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if ((scr_id == SCR_ID_VRSI_RCG_MAIN) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_NUM) || (scr_id == SCR_ID_VRSI_NAME_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_multiple_number_in_history
 * DESCRIPTION
 *  Entry multiple number screen after retry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_multiple_number_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    U8 loc_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, (S8*) PhoneBook[g_vrsi_cntx.long_list[0]].alpha_id.name);
    loc_count = mmi_vrsi_ndial_multiple_number_show_data(str_prompt);

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_NAME_DIAL_MULTI_NUM_IN_HISTORY, NULL, NULL, NULL);

    RegisterHighlightHandler(mmi_vrsi_entry_ndial_get_index);

    ShowCategory53Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_DIAL,
        0,
        STR_GLOBAL_ABORT,
        0,
        loc_count,
        subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        g_vrsi_cntx.active_index,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_ndial_multiple_number_pre_confirm, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_number_pre_confirm
 * DESCRIPTION
 *  Pre comfirm for select one of multilple number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_number_pre_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get post command */
    if (g_vrsi_cntx.loc_num[0] && (g_vrsi_cntx.active_index == i++))
    {
        g_vrsi_cntx.post_cmd = VRSI_CMD2_MOBILE;
    }
    if (g_vrsi_cntx.loc_num[1] && (g_vrsi_cntx.active_index == i++))
    {
        g_vrsi_cntx.post_cmd = VRSI_CMD2_HOME;
    }
    if (g_vrsi_cntx.loc_num[2] && (g_vrsi_cntx.active_index == i++))
    {
        g_vrsi_cntx.post_cmd = VRSI_CMD2_BUSINESS;
    }
    if (g_vrsi_cntx.loc_num[3] && (g_vrsi_cntx.active_index == i++))
    {
        g_vrsi_cntx.post_cmd = VRSI_CMD2_FAX;
    }

    /* Enter screen from screen not in VR session, so init engine again. */
    scr_id = GetActiveScreenId();
    if (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_NUM_IN_HISTORY)
    {
        mmi_vrsi_rcg_init(NULL);
    }
    else
    {
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    }

    g_vrsi_cntx.retry = 0;
    mmi_vrsi_entry_ndial_confirm_dial();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_number_show_data
 * DESCRIPTION
 *  Prompt string for multiple number
 * PARAMETERS
 *  str_prompt      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vrsi_ndial_multiple_number_show_data(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S16 pError;
    S8 number_buff[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U16 len;
    U8 loc_count = 0;
    U8 post_cmd = VRSI_CMD2_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vrsi_cntx.loc_num, 0, 4);

    store_index = g_vrsi_cntx.long_list[0];

    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT));

    mmi_phb_convert_to_digit((U8*) number_buff, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    if ((len = strlen(number_buff)) > 0)
    {
        g_vrsi_cntx.loc_num[0] = 1;

        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE));
        mmi_ucs2ncpy(
            (S8*) subMenuData[loc_count],
            GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE),
            MAX_SUBMENU_CHARACTERS);
        if (len <= MAX_SUBMENU_CHARACTERS)
        {
            mmi_asc_n_to_ucs2((S8*) hintData[loc_count], number_buff, len + 1);
            hintDataPtrs[loc_count] = hintData[loc_count];
        }
        loc_count++;
        post_cmd = VRSI_CMD2_MOBILE;
    }

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    if (store_index < MAX_PB_PHONE_ENTRIES)
    {
        /* Read Optional Number Fields */
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);

        if ((len = strlen((S8*) PhoneBookOptionalFields.homeNumber)) > 0)
        {
            g_vrsi_cntx.loc_num[1] = 1;

            mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_HOME));
            mmi_ucs2ncpy(
                (S8*) subMenuData[loc_count],
                GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_HOME),
                MAX_SUBMENU_CHARACTERS);
            if (len <= MAX_SUBMENU_CHARACTERS)
            {
                mmi_asc_n_to_ucs2((S8*) hintData[loc_count], (S8*) PhoneBookOptionalFields.homeNumber, len + 1);
                hintDataPtrs[loc_count] = hintData[loc_count];
            }
            loc_count++;
            post_cmd = VRSI_CMD2_HOME;
        }
        if ((len = strlen((S8*) PhoneBookOptionalFields.officeNumber)) > 0)
        {
            g_vrsi_cntx.loc_num[2] = 1;

            mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE));
            mmi_ucs2ncpy(
                (S8*) subMenuData[loc_count],
                GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE),
                MAX_SUBMENU_CHARACTERS);
            if (len <= MAX_SUBMENU_CHARACTERS)
            {
                mmi_asc_n_to_ucs2((S8*) hintData[loc_count], (S8*) PhoneBookOptionalFields.officeNumber, len + 1);
                hintDataPtrs[loc_count] = hintData[loc_count];
            }
            loc_count++;
            post_cmd = VRSI_CMD2_BUSINESS;
        }
        if ((len = strlen((S8*) PhoneBookOptionalFields.faxNumber)) > 0)
        {
            g_vrsi_cntx.loc_num[3] = 1;

            mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_FAX));
            mmi_ucs2ncpy(
                (S8*) subMenuData[loc_count],
                GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_FAX),
                MAX_SUBMENU_CHARACTERS);
            if (len <= MAX_SUBMENU_CHARACTERS)
            {
                mmi_asc_n_to_ucs2((S8*) hintData[loc_count], (S8*) PhoneBookOptionalFields.faxNumber, len + 1);
                hintDataPtrs[loc_count] = hintData[loc_count];
            }
            loc_count++;
            post_cmd = VRSI_CMD2_FAX;
        }
    }
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_CANCEL));

    /* Assign post command for dial if there are only one number */
    if (loc_count == 1)
    {
        g_vrsi_cntx.post_cmd = post_cmd;
    }

    return loc_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_number_prompt
 * DESCRIPTION
 *  Prompt string for multiple number
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompt string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_number_prompt(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_DIAL,
                store_index,
                mmi_vrsi_ndial_multiple_number_prompt2);

    if (result == MED_RES_OK)
    {
        return;
    }

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_number_prompt2
 * DESCRIPTION
 *  Prompt string for multiple number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_number_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_prompt, 0, 2);
    mmi_vrsi_ndial_multiple_number_show_data(str_prompt);

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}

#define MMI_VRSI_NDIAL_MULTIPLE_RECORD


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_multiple_record
 * DESCRIPTION
 *  Entry function for multiple duplicated record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_multiple_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *name_ptr[MMI_VRSI_MAX_RCG_RESULT];
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare hint data */
    mmi_vrsi_ndial_multiple_record_show_hint(name_ptr);

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD, mmi_vrsi_exit_ndial_multiple_record, NULL, NULL);

    RegisterHighlightHandler(mmi_vrsi_entry_ndial_get_index);

    ShowCategory53Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_ABORT,
        0,
        g_vrsi_cntx.long_list_num,
        name_ptr,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        g_vrsi_cntx.active_index,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_SEND, KEY_EVENT_UP);

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_3;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NAME_DIAL;

    /*Play first prompt only*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_GRAMMAR3_PROMPT));
    mmi_vrsi_util_play_tts((U16*) str_prompt,
    mmi_vrsi_ndial_multiple_record_prompt2);
    
    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ndial_multiple_record
 * DESCRIPTION
 *  Exit function for multiple duplicated record, will exit VR session if next screen is not
 *  In vr scenario
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ndial_multiple_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if ((scr_id == SCR_ID_VRSI_RCG_MAIN) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD) ||
        (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_NUM) || (scr_id == SCR_ID_VRSI_NAME_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_multiple_record_in_history
 * DESCRIPTION
 *  Entry function for multiple duplicated record after retry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_multiple_record_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *name_ptr[MMI_VRSI_MAX_RCG_RESULT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare hint data */
    mmi_vrsi_ndial_multiple_record_show_hint(name_ptr);

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD_IN_HISTORY, NULL, NULL, NULL);

    RegisterHighlightHandler(mmi_vrsi_entry_ndial_get_index);

    ShowCategory53Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_ABORT,
        0,
        g_vrsi_cntx.long_list_num,
        name_ptr,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        g_vrsi_cntx.active_index,
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsi_ndial_multiple_record_to_single_record, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_to_single_record
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_to_single_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 long_list[1];
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Enter screen from screen not in VR session, so init engine again. */
    scr_id = GetActiveScreenId();
    if (scr_id == SCR_ID_VRSI_NAME_DIAL_MULTI_RECORD_IN_HISTORY)
    {
        mmi_vrsi_rcg_init(NULL);
    }
    else
    {
        mdi_audio_vrsi_stop(g_vrsi_cntx.session_id);
    }

    long_list[0] = g_vrsi_cntx.long_list[g_vrsi_cntx.active_index];
    mmi_vrsi_ndial_rcg_grammar1_result(1, long_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_show_data
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompt message string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_show_data(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare prompt string */
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_GRAMMAR3_PROMPT));
    mmi_ucs2cat(str_prompt, (S8*) PhoneBook[g_vrsi_cntx.long_list[0]].alpha_id.name);
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR3_PROMPT_SELECT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_show_hint
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  name_ptr        [IN/OUT]        hint pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_show_hint(U8 **name_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 store_index;
    S8 number_buff[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prepare hint list data */
    for (i = 0; i < g_vrsi_cntx.long_list_num; i++)
    {
        store_index = g_vrsi_cntx.long_list[i];

        name_ptr[i] = PhoneBook[store_index].alpha_id.name;
        mmi_phb_convert_get_ucs2_number(number_buff, store_index);
        mmi_ucs2ncpy((S8*) hintData[i], number_buff, MAX_SUBMENU_CHARACTERS);
        hintDataPtrs[i] = hintData[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_prompt2
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    S32 result;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_DIAL,
                store_index,
                mmi_vrsi_ndial_multiple_record_prompt3);

    if (result == MED_RES_OK)
    {
        return;
    }

    /* Play SI instead */
    mmi_ucs2cat(str_prompt, (S8*) PhoneBook[store_index].alpha_id.name);

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_ndial_multiple_record_prompt3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_multiple_record_prompt3
 * DESCRIPTION
 *  Prompt message for multiple record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_multiple_record_prompt3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR3_PROMPT_SELECT));

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}

#define MMI_VRSI_NDIAL_CONFIRM


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_pre_confirm_dial
 * DESCRIPTION
 *  confirm dial location before dial
 * PARAMETERS
 *  dial_loc        [IN]        select location
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_pre_confirm_dial(U8 dial_loc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S8 number_buff[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    S16 pError;
    U8 confirm_dial = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    if (g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE)
    {
        mmi_phb_convert_get_ucs2_number((S8*) number_buff, store_index);

        if (strlen(number_buff))
        {
            confirm_dial = 1;
        }
    }

    if (store_index < MAX_PB_PHONE_ENTRIES)
    {
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        if (g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME)
        {
            ReadRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (store_index + 1),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);
            if (strlen((S8*) PhoneBookOptionalFields.homeNumber))
            {
                confirm_dial = 1;
            }
        }
        else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS)
        {
            ReadRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (store_index + 1),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);
            if (strlen((S8*) PhoneBookOptionalFields.officeNumber))
            {
                confirm_dial = 1;
            }
        }
        else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX)
        {
            ReadRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (store_index + 1),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);
            if (strlen((S8*) PhoneBookOptionalFields.faxNumber))
            {
                confirm_dial = 1;
            }
        }
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
    }

    if (confirm_dial)
    {
        g_vrsi_cntx.retry = 0;
        mmi_vrsi_entry_ndial_confirm_dial();
    }
    else
    {
        mmi_vrsi_ndial_no_number_prompt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_confirm_dial
 * DESCRIPTION
 *  entry function of confirm dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_confirm_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_ndial_confirm_dial_show_data(str_prompt);

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_NAME_DIAL_CONFIRM, mmi_vrsi_exit_ndial_confirm_dial, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        0,                  /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_dial_entry, KEY_EVENT_UP);
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_vrsi_ndial_dial_entry,KEY_EVENT_UP);
#else   /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_vrsi_ndial_dial_entry, KEY_SEND, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    g_vrsi_cntx.curr_grammar = MMI_VRSI_GRAMMAR_4;  /* Assign grammar for rcg result callback */
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_NAME_DIAL;

    /*Play first prompt only*/
    mmi_vrsi_ndial_confirm_dial_show_data1(str_prompt);
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_ndial_confirm_dial_prompt2);

    g_vrsi_cntx.retry++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_exit_ndial_confirm_dial
 * DESCRIPTION
 *  exit function for confirm dial. Will exit VR session if next screen is not in VR session.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_exit_ndial_confirm_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if ((scr_id == SCR_ID_VRSI_RCG_MAIN) || /* Speak command again */
        (scr_id == SCR_ID_VRSI_NAME_DIAL_CONFIRM))
    {
        return;
    }
    else
    {
        mmi_vrsi_rcg_close();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_entry_ndial_confirm_dial_in_history
 * DESCRIPTION
 *  entry function of confirm dial screen after retry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_entry_ndial_confirm_dial_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_ndial_confirm_dial_show_data(str_prompt);

    TurnOnBacklight(1);

    EntryNewScreen(SCR_ID_VRSI_NAME_DIAL_CONFIRM_IN_HISTORY, NULL, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_VRSI_APP,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_ABORT,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_prompt,   /* message string */
        0,                  /* icon id */
        NULL);

    SetRightSoftkeyFunction(mmi_vrsi_rcg_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsi_ndial_dial_entry, KEY_EVENT_UP);
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(mmi_vrsi_ndial_dial_entry,KEY_EVENT_UP);
#else   /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(mmi_vrsi_ndial_dial_entry, KEY_SEND, KEY_EVENT_UP);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_show_data
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompr string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_show_data(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsi_ndial_confirm_dial_show_data1(str_prompt);
    mmi_vrsi_ndial_confirm_dial_show_data2(str_prompt);
    mmi_vrsi_ndial_confirm_dial_show_data3(str_prompt);

    /* Replace \r\n as space to avoid show oversize on screen. */
    for (i = 0; i < (MAX_PB_NAME_LENGTH + 59) * ENCODING_LENGTH; i = i + 2)
    {
        if (str_prompt[i] == 0x0D && str_prompt[i + 1] == 0x00 &&
            str_prompt[i + 2] == 0x0A && str_prompt[i + 3] == 0x00)
        {
            str_prompt[i] = 0x20;
            str_prompt[i + 2] = 0x20;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_show_data1
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompr string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_show_data1(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(str_prompt, GetString(STR_ID_VRSI_DIAL_PROMPT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_show_data2
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompr string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_show_data2(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];
    mmi_ucs2cat(str_prompt, (S8*) PhoneBook[store_index].alpha_id.name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_show_data3
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompr string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_show_data3(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_HOME));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_FAX));
    }

    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR4_PROMPT));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_prompt2
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    S32 result;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(MMI_VRSI_GRAMMAR_1, MMI_VRSI_APP_DIAL, store_index, mmi_vrsi_ndial_confirm_dial_prompt3);

    if (result == MED_RES_OK)
    {
        return;
    }

    /* Play SI instead */
    mmi_ucs2cat(str_prompt, (S8*) PhoneBook[store_index].alpha_id.name);

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_ndial_confirm_dial_prompt3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_confirm_dial_prompt3
 * DESCRIPTION
 *  prompt message of confirm dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_confirm_dial_prompt3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_prompt, 0, 2);
    mmi_vrsi_ndial_confirm_dial_show_data3(str_prompt);

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_rcg_start_command);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_no_number_show_data
 * DESCRIPTION
 *  prompt message for no number to dial.
 * PARAMETERS
 *  str_prompt      [IN/OUT]        prompt string.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_no_number_show_data(S8 *str_prompt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_MOBILE));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_HOME));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_OFFICE));
    }
    else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX)
    {
        mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_GRAMMAR2_PROMPT_FAX));
    }

    mmi_ucs2cat(str_prompt, GetString(STR_ID_VRSI_TTS_NUMBER_NO_DATA));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_no_number_prompt
 * DESCRIPTION
 *  prompt message for no number to dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_no_number_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.curr_scenario = VRSI_CMD1_EXIT;

    /* Play SD tag if exists. */
    result = mmi_vrsi_util_play_name_tag(
                MMI_VRSI_GRAMMAR_1,
                MMI_VRSI_APP_DIAL,
                g_vrsi_cntx.long_list[0],
                mmi_vrsi_ndial_no_number_prompt2);

    if (result == MED_RES_OK)
    {
        return;
    }

    mmi_ucs2cpy(str_prompt, (S8*) PhoneBook[g_vrsi_cntx.long_list[0]].alpha_id.name);
    mmi_vrsi_ndial_no_number_show_data(str_prompt);

    /* Play prompt TTS */
    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_no_number_prompt2
 * DESCRIPTION
 *  prompt message for no number to dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_no_number_prompt2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_prompt[(MAX_PB_NAME_LENGTH + 60) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str_prompt, 0, 2);
    mmi_vrsi_ndial_no_number_show_data(str_prompt);

    mmi_vrsi_util_play_tts((U16*) str_prompt, mmi_vrsi_entry_rcg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_dial_entry
 * DESCRIPTION
 *  Entry function for no number to dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_dial_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S8 number_buff[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    store_index = g_vrsi_cntx.long_list[0];

    memset(number_buff, 0, 2);

    if (g_vrsi_cntx.post_cmd == 0 || g_vrsi_cntx.post_cmd == VRSI_CMD2_MOBILE)
    {
        mmi_phb_convert_get_ucs2_number((S8*) number_buff, store_index);
    }

    if (store_index < MAX_PB_PHONE_ENTRIES)
    {
    #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
        /* Read Optional Number Fields */
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);

        if (g_vrsi_cntx.post_cmd == VRSI_CMD2_HOME)
        {
            mmi_asc_to_ucs2(number_buff, (S8*) PhoneBookOptionalFields.homeNumber);
        }
        else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_BUSINESS)
        {
            mmi_asc_to_ucs2(number_buff, (S8*) PhoneBookOptionalFields.officeNumber);
        }
        else if (g_vrsi_cntx.post_cmd == VRSI_CMD2_FAX)
        {
            mmi_asc_to_ucs2(number_buff, (S8*) PhoneBookOptionalFields.faxNumber);
        }
    #endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
    }

    if (mmi_ucs2strlen(number_buff))
    {
        U16 i = 0;

        /* simulate the behavior as dial from phonebook list */
        for (i = 0; i < PhoneBookEntryCount; i++)
            if (g_phb_name_index[i] == store_index)
            {
                break;
            }

        g_phb_cntx.dial_from_list = MMI_PHB_PHONEBOOK;
        g_phb_cntx.active_index = i;

        /* close recognition precedure before make call */
        mmi_vrsi_rcg_close();
        
	#ifdef __MMI_DUAL_SIM_MASTER__
		mmi_ucm_app_entry_dial_option((U8*)number_buff,NULL,NULL);
	#else 
        MakeCall(number_buff);
	#endif /*__MMI_DUAL_SIM_MASTER__*/        
    }
    else
    {
        mmi_vrsi_ndial_no_number_prompt();
    }
}

#define MMI_VRSI_NDIAL_TRAIN_CENTRAL
#if defined(__MMI_VRSI_TRAIN_TAG__)


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_train_list_pre_entry
 * DESCRIPTION
 *  Pre entry phonebook list to select an entry to train SD tags.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_train_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_vrsi_pre_entry_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsi_ndial_train_list_callback
 * DESCRIPTION
 *  Callback function for train SD tag after select an entry from phonebook.
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsi_ndial_train_list_callback(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag_loc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsi_cntx.long_name_ptr = (U16*) PhoneBook[store_index].alpha_id.name;
    g_vrsi_cntx.long_list[0] = store_index;
    g_vrsi_cntx.long_list_num = 1;

    g_vrsi_cntx.curr_app = MMI_VRSI_APP_DIAL;

    tag_loc = mmi_vrsi_train_util_get_id_and_loc(MMI_VRSI_APP_DIAL, store_index, NULL);

    /* Modify, Playback, or delete exists voice tag. */
    if (tag_loc < 0xff)
    {
        /* mmi_vrsi_entry_ndial_train_del(); */
        mmi_vrsi_entry_train_option_del();
    }
    /* No tag exists, add new tag */
    else
    {
        mmi_vrsi_entry_train_option_add();
    }

}

#endif /* defined(__MMI_VRSI_TRAIN_TAG__) */ /* #if defined(__MMI_VRSI_TRAIN_TAG__) */

#endif /* defined(__MMI_VRSI__) */ /* #if defined(__MMI_VRSI__) */
#endif /* _MMI_VRSINAMEDIAL_C */ /* #ifndef _MMI_VRSINAMEDIAL_C */

