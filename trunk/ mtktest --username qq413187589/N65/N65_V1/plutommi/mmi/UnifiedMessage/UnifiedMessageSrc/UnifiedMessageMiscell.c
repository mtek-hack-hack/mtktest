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
 * UnifiedMessageMiscell.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements miscell utilities for Unified Message application.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_UNIFIED_MESSAGE_MISCELL_C
#define _MMI_UNIFIED_MESSAGE_MISCELL_C

#ifdef __MMI_UNIFIED_MESSAGE__

#include "FileManagerGProt.h"
#include "FileMgr.h"
#include "Fmt_struct.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"

/* micha1230 */
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "Conversions.h"


#include "CommonScreens.h"
#include "SettingProfile.h"
#include "PhoneBookGprot.h"

#include "wgui_status_icons.h"
#include "gpioInc.h"
#include "MessagesresourceData.h"
#include "MessagesMiscell.h"
#include "SmsGuiInterfaceProt.h"
#include "SmsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "mmi_msg_context.h"
#include "CallManagementGprot.h"
#include "AlarmFrameworkProt.h"
#include "NetworkSetupDefs.h"

#include "SMSApi.h"
#include "SMSStruct.h"

#include "wapadp.h"

#include "UnifiedMessageResDef.h"
#include "UnifiedMessageGProt.h"
#include "UnifiedMessageProt.h"

#ifdef __MMI_MMS_2__
#include "MMSAppGprot.h"
#endif /* __MMI_MMS_2__ */
#ifdef __MMI_UNIFIED_COMPOSER__
#include "UnifiedComposerGProt.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

extern msg_context_struct g_msg_cntx;
extern msg_msgbox_info_struct msgbox_info;


/*****************************************************************************
 * FUNCTION
 *  mmi_um_init_context
 * DESCRIPTION
 *  Initialize Unified Message context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.support_type = UM_MSG_TYPE_SMS | UM_MSG_TYPE_MMS | UM_MSG_TYPE_WAP_PUSH;
    g_um_p->main.ready_type = 0;
    g_um_p->main.state = UM_STATE_IDLE;
    g_um_p->main.is_skip_write_menu = KAL_FALSE;
    g_um_p->main.pending_req_type = 0;
    g_um_p->main.is_new_msg = KAL_FALSE;
    g_um_p->main.is_ready_for_new_msg = KAL_FALSE;
    g_um_p->main.main_index = 0;
    g_um_p->main.is_reset_folder_info = KAL_TRUE;
    g_um_p->main.is_refresh = KAL_FALSE;
    g_um_p->folder.is_highlight_change_needed = KAL_FALSE;
    g_um_p->folder.current_msg_box = 0;
    g_um_p->main.is_new_msg_comes_in_idle = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_re_enter_um_screen
 * DESCRIPTION
 *  re-enter um screen 
 * PARAMETERS
 *  res         [IN]        
 *  type        [IN]        
 *  result : KAL_TRUE means ready; KAL_FALSE means initialization failure(?)
 *  msg_type : Type of ready message(?)
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_um_re_enter_um_screen(void)
{
    U16 current_screen_id = GetExitScrnID();
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"mmi_um_re_enter_um_screen current_screen_id= %d -------*\n", current_screen_id);

    switch (current_screen_id)
    {
            case (SCR_ID_UM_MAIN):
            {
                mmi_um_pre_entry_main();  
                DeleteScreenIfPresent(SCR_ID_UM_MAIN);
            }
            break;
            
            case (SCR_ID_UM_INBOX):
            case (SCR_ID_UM_UNSENT):
            case (SCR_ID_UM_SENT):
            case (SCR_ID_UM_DRAFT):
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case (SCR_ID_UM_ARCHIVE):
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            case (SCR_ID_UM_SIM):
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
            {
                mmi_um_entry_folder();
                DeleteScreenIfPresent(SCR_ID_UM_INBOX);
                DeleteScreenIfPresent(SCR_ID_UM_UNSENT);
                DeleteScreenIfPresent(SCR_ID_UM_SENT);
                DeleteScreenIfPresent(SCR_ID_UM_DRAFT);
                DeleteScreenIfPresent(SCR_ID_UM_ARCHIVE);
                DeleteScreenIfPresent(SCR_ID_UM_SIM);
            }
            break;

            case (SCR_ID_UM_DELETE_FOLDER):
            {
                mmi_um_pre_entry_delete_folder();
                DeleteScreenIfPresent(SCR_ID_UM_DELETE_FOLDER);
            }
            break;            

            case (SCR_ID_UM_TEMPLATE):
            {
                mmi_um_entry_template();

                DeleteScreenIfPresent(SCR_ID_UM_TEMPLATE);
            }
            break;

            case (SCR_ID_UM_SETTING):
            {
                mmi_um_entry_setting();
                DeleteScreenIfPresent(SCR_ID_UM_SETTING);
            }
            break;
            
            default:
            {
                
            }
            break;
    }/*switch*/

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_ready_ind
 * DESCRIPTION
 *  Handle msg ready indication
 * PARAMETERS
 *  res         [IN]        
 *  type        [IN]        
 *  result : KAL_TRUE means ready; KAL_FALSE means initialization failure(?)
 *  msg_type : Type of ready message(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_ready_ind(kal_bool res, UmMsgType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = res;
    UmMsgType msg_type = type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_ASSERT(result); */

    MMI_ASSERT(mmi_um_check_support_type(msg_type));

    if (result)
    {
        g_um_p->main.ready_type |= msg_type;
    }
    else
    {
        g_um_p->main.ready_type &= ~(msg_type);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "mmi_um_ready_ind  F, maybe mms terminate %d -------*\n", msg_type);
        
        g_um_p->main.pending_req_type =0;
        g_um_p->main.state = UM_STATE_IDLE;
        mmi_um_re_enter_um_screen();

#ifdef __MMI_UNIFIED_COMPOSER__
        mmi_uc_delete_all_uc_screens();
        mmi_uc_reset_msg();
#endif /*__MMI_UNIFIED_COMPOSER__*/
    }

    if (mmi_um_check_ready())
    {
        switch (g_um_p->main.state)
        {
            case UM_STATE_ENTRY_MAIN_MENU:
            {
                if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
                {
                    mmi_um_pre_entry_main();
                }
                else if (IsScreenPresent(SCR_ID_UM_PROCESSING))
                {
                    HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_MAIN, mmi_um_pre_entry_main);
                }
                break;
            }

            case UM_STATE_ENTRY_INBOX:
            {
                if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
                {
                    mmi_um_pre_entry_inbox();
                }
                else if (IsScreenPresent(SCR_ID_UM_PROCESSING))
                {
                    HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_INBOX, mmi_um_pre_entry_inbox);
                }
                break;
            }

            case UM_STATE_ENTRY_UNSENT:
            {
                if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
                {
                    mmi_um_pre_entry_unsent();
                }
                else if (IsScreenPresent(SCR_ID_UM_PROCESSING))
                {
                    HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_UNSENT, mmi_um_pre_entry_unsent);
                }
                break;
            }

            case UM_STATE_ENTRY_SENT:
            {
                if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
                {
                    mmi_um_pre_entry_sent();
                }
                else if (IsScreenPresent(SCR_ID_UM_PROCESSING))
                {
                    HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_SENT, mmi_um_pre_entry_sent);
                }
                break;
            }

            case UM_STATE_ENTRY_DRAFT:
            {
                if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
                {
                    mmi_um_pre_entry_draft();
                }
                else if (IsScreenPresent(SCR_ID_UM_PROCESSING))
                {
                    HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_DRAFT, mmi_um_pre_entry_draft);
                }
                break;
            }

        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case UM_STATE_ENTRY_ARCHIVE:
            {
                if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
                {
                    mmi_um_pre_entry_archive();
                }
                else if (IsScreenPresent(SCR_ID_UM_PROCESSING))
                {
                    HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_ARCHIVE, mmi_um_pre_entry_archive);
                }
                break;
            }
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            case UM_STATE_ENTRY_SIM:
            {
                if (GetExitScrnID() == SCR_ID_UM_PROCESSING)
                {
                    mmi_um_pre_entry_simbox();
                }
                else if (IsScreenPresent(SCR_ID_UM_PROCESSING))
                {
                    HistoryReplace(SCR_ID_UM_PROCESSING, SCR_ID_UM_SIM, mmi_um_pre_entry_simbox);
                }
                break;
            }
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

            default:
                /* Do nothing */
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_check_support_type
 * DESCRIPTION
 *  Check if UM supports the msg type.
 * PARAMETERS
 *  type        [IN]        msg type
 * RETURNS
 *  TRUE: UM supports the msg type. Otherwise FALSE.
 *****************************************************************************/
kal_bool mmi_um_check_support_type(UmMsgType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_type = type;
    U8 i = 0;
    U8 mask = 0x01;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < MMI_UM_MAX_SUPPORT_MSG_TYPE; i++, mask <<= 1)
    {
        if (((g_um_p->main.support_type) & mask) == msg_type)
        {
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_check_ready
 * DESCRIPTION
 *  Check if all msg types UM supports are ready
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: All msg types UM supports are ready. Otherwise FALSE.
 *****************************************************************************/
kal_bool mmi_um_check_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "[UM]mmi_um_check_ready support_type: %d ready_type: %d\n",
                         g_um_p->main.support_type, g_um_p->main.ready_type);
    if (g_um_p->main.support_type == g_um_p->main.ready_type)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_set_state
 * DESCRIPTION
 *  Set state of unified message application
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_set_state(U8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.state = state;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_insert_list_info
 * DESCRIPTION
 *  Insert msg folder information into list
 * PARAMETERS
 *  msg_type        [IN]        
 *  msg_number      [IN]        
 *  list_info       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_insert_list_info(UmMsgType msg_type, kal_uint16 msg_number, mmi_um_list_info_struct *list_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgType type = msg_type;
    kal_uint16 number = msg_number;
    mmi_um_list_info_struct *list = list_info;
    kal_uint16 um_list_index = 0;
    kal_uint16 add_list_index = 0;
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; add_list_index < number; add_list_index++)
    {
        for (; um_list_index < g_um_p->folder.msg_number_in_list; um_list_index++)
        {
            if (g_um_p->folder.msg_list[um_list_index].list_info.timestamp < list[add_list_index].timestamp)
            {
                break;
            }
        }

        for (i = g_um_p->folder.msg_number_in_list; i > um_list_index; i--)
        {
            memcpy(&g_um_p->folder.msg_list[i], &g_um_p->folder.msg_list[i - 1], sizeof(mmi_um_msg_box_info_struct));
        }

        g_um_p->folder.msg_list[um_list_index].msg_type = type;
        g_um_p->folder.msg_list[um_list_index].list_info.msg_index = list[add_list_index].msg_index;
        g_um_p->folder.msg_list[um_list_index].list_info.timestamp = list[add_list_index].timestamp;
        g_um_p->folder.msg_number_in_list++;
        um_list_index++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_insert_msg_info
 * DESCRIPTION
 *  Insert msg detail information into list
 * PARAMETERS
 *  msg_type            [IN]        
 *  msg_number          [IN]        
 *  msg_info_list       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_insert_msg_info(UmMsgType msg_type, kal_uint16 msg_number, mmi_um_msg_info_struct *msg_info_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgType type = msg_type;
    kal_uint16 number = msg_number;
    mmi_um_msg_info_struct *msg_info = msg_info_list;
    U16 i = 0;
    U16 temp_buffer_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < number; i++)
    {
        for (; temp_buffer_index < MMI_UM_MAX_MSG_PER_PAGE; temp_buffer_index++)
        {
            if (g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_type == type)
            {
                g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.msg_index = msg_info[i].msg_index;
                g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.timestamp = msg_info[i].timestamp;
                g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.address_type =
                    msg_info[i].address_type;

                if (msg_info[i].address_length > 0)
                {
                    g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.address_length =
                        msg_info[i].address_length;
                    mmi_ucs2ncpy(
                        (S8*) g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.address,
                        (S8*) msg_info[i].address,
                        msg_info[i].address_length);

                }
                else
                {
                    mmi_ucs2ncpy(
                        (S8*) g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.address,
                        (S8*) GetString(STR_OUTBOX_LIST_MESSAGE),
                        MMI_UM_MAX_SUBJECT_LEN);
                    g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.address_length = mmi_ucs2strlen((S8*) GetString(STR_OUTBOX_LIST_MESSAGE));
                }

                if (msg_info[i].subject_length > 0)
                {
                    g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.subject_length =
                        msg_info[i].subject_length;
                    mmi_ucs2ncpy(
                        (S8*) g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.subject,
                        (S8*) msg_info[i].subject,
                        msg_info[i].subject_length);
                }
                else
                {
                    mmi_ucs2ncpy(
                        (S8*) g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.subject,
                        (S8*) GetString(STR_UM_EMPTY_SUBJECT_ID),
                        MMI_UM_MAX_SUBJECT_LEN);
                    g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.subject_length = mmi_ucs2strlen((S8*) GetString(STR_UM_EMPTY_SUBJECT_ID));
                }

                g_um_p->get_msg_detail.temp_buffer[temp_buffer_index].msg_detail.icon_id = msg_info[i].icon_id;

                g_um_p->get_msg_detail.num_in_temp_buffer++;
                temp_buffer_index++;
                break;
            }
        }
    }

    MMI_ASSERT(i == number);

    if ((g_um_p->get_msg_detail.num_in_temp_buffer == MMI_UM_MAX_MSG_PER_PAGE) || (g_um_p->main.pending_req_type == 0))
    {
        mem_pool_struct uMemPool;
        mmi_um_msg_detail_struct *listMsgsStruct;
        mmi_um_msg_detail_struct *ptrs[MMI_UM_MAX_MSG_PER_PAGE];

        uMemPool.nMinId = g_um_p->mem_pool_info.not_avail_pool * MMI_UM_MAX_MSG_PER_PAGE;
        uMemPool.nMaxId = ((g_um_p->mem_pool_info.not_avail_pool + 1) * MMI_UM_MAX_MSG_PER_PAGE) - 1;

        listMsgsStruct =
            (mmi_um_msg_detail_struct*) mmi_mem_get_free_mem(&g_um_p->mem_pool_info.mem_container, &uMemPool);
        memset(
            listMsgsStruct,
            0,
            g_um_p->mem_pool_info.mem_container.unit_size * g_um_p->mem_pool_info.mem_container.unit_per_pool);

        /* fill data for each mail */
        for (i = 0; i < g_um_p->get_msg_detail.num_in_temp_buffer; i++)
        {
            listMsgsStruct[i].msg_detail.msg_index = g_um_p->get_msg_detail.temp_buffer[i].msg_detail.msg_index;
            listMsgsStruct[i].msg_detail.timestamp = g_um_p->get_msg_detail.temp_buffer[i].msg_detail.timestamp;
            listMsgsStruct[i].msg_detail.address_type = g_um_p->get_msg_detail.temp_buffer[i].msg_detail.address_type;
            listMsgsStruct[i].msg_detail.address_length =
                g_um_p->get_msg_detail.temp_buffer[i].msg_detail.address_length;

            mmi_ucs2ncpy(
                (S8*) listMsgsStruct[i].msg_detail.address,
                (S8*) g_um_p->get_msg_detail.temp_buffer[i].msg_detail.address,
                listMsgsStruct[i].msg_detail.address_length);

            listMsgsStruct[i].msg_detail.subject_length =
                g_um_p->get_msg_detail.temp_buffer[i].msg_detail.subject_length;

            mmi_ucs2ncpy(
                (S8*) listMsgsStruct[i].msg_detail.subject,
                (S8*) g_um_p->get_msg_detail.temp_buffer[i].msg_detail.subject,
                listMsgsStruct[i].msg_detail.subject_length);

            listMsgsStruct[i].msg_detail.icon_id = g_um_p->get_msg_detail.temp_buffer[i].msg_detail.icon_id;

            ptrs[i] = &listMsgsStruct[i];
        }

        uMemPool.unit_list = (void **)ptrs;

        mmi_mem_insert_pool(&g_um_p->mem_pool_info.mem_container, &uMemPool);

        g_um_p->get_msg_detail.num_in_temp_buffer = 0;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_is_list_ready
 * DESCRIPTION
 *  Function to check if list of items is ready to be displayed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_um_is_list_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mem_pool_ret_enum ret_result;

    mmi_um_msg_detail_struct *listMsgsStruct[MMI_UM_MAX_MSG_DETAIL_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_result = mmi_mem_get_values(
                    &g_um_p->mem_pool_info.mem_container,
                    (S16) g_um_p->mem_pool_info.start_index,
                    (S16) g_um_p->mem_pool_info.end_index,
                    (void **)listMsgsStruct,
                    &g_um_p->mem_pool_info.not_avail_pool);

    if (ret_result != MEM_CT_SUCCESS)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_free_container_pool
 * DESCRIPTION
 *  Free memory pool container and reset folder info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_free_container_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_um_p->mem_pool_info.mem_container.num_pool != -1)
    {
        mmi_mem_destroy_container(&g_um_p->mem_pool_info.mem_container);
        memset(&g_um_p->folder.msg_detail_list, 0, sizeof(mmi_um_msg_detail_struct));

        /* -1 to indicate no container now */
        g_um_p->mem_pool_info.mem_container.num_pool = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_reset_folder_info
 * DESCRIPTION
 *  Reset variales before entry a folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_reset_folder_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 totalPool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->folder.is_list_displayed = KAL_FALSE;

    /* g_um_p->folder.current_msg_index = 0; */

    mmi_um_free_container_pool();

    totalPool = MMI_UM_TOTAL_POOL + 1;

    /* create pool */
    mmi_mem_create_container(
        totalPool,
        MMI_UM_MAX_MSG_PER_PAGE,
        (void*)g_um_p->folder.msg_detail_list,
        sizeof(mmi_um_msg_detail_struct),
        &g_um_p->mem_pool_info.mem_container);

    g_um_p->mem_pool_info.start_index = 0;

    if (g_um_p->folder.msg_number_in_list < MAX_ASYNCDYNAMIC_ITEMS_BUFF)
    {
        g_um_p->mem_pool_info.end_index = g_um_p->folder.msg_number_in_list - 1;
    }
    else
    {
        g_um_p->mem_pool_info.end_index = MAX_ASYNCDYNAMIC_ITEMS_BUFF - 1;
    }

    g_um_p->mem_pool_info.not_avail_pool = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_skip_write_menu
 * DESCRIPTION
 *  Set the flag of skipping write menu
 * PARAMETERS
 *  operation       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_skip_write_menu(kal_bool operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.is_skip_write_menu = operation;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_new_msg_ind
 * DESCRIPTION
 *  Set the flag of new msg
 * PARAMETERS
 *  msg_type            [IN]        
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 *  timestamp           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_new_msg_ind(UmMsgType msg_type, UmMsgBoxType msg_box_type, kal_uint16 msg_index, kal_uint32 timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box_type == UM_MSG_BOX_TYPE_INBOX)
    {
        g_um_p->main.is_new_msg |= msg_type;
        g_um_p->main.is_ready_for_new_msg = KAL_FALSE;
    }

    TurnOnBacklight(1);

    if (IsMMIInIdleState() || GetExitScrnID() == SCR_ID_UM_NEW_MSG_IND)
    {
        PlayMessageArrivalTone();
        StartLEDPatternMessageIn();
        StartTimer(MESSAGES_SUBLCD_TIMER_ID, MESSAGES_SUBLCD_TIME_OUT, mmi_msg_callback_msg_sub_anm);
        ClearKeyEvents();

        g_um_p->main.is_new_msg_comes_in_idle = KAL_TRUE;

        mmi_um_pre_entry_new_msg_ind();

    }
    else if (IsScreenPresent(SCR_ID_UM_INBOX) || GetExitScrnID() == SCR_ID_UM_INBOX)
    {
        g_um_p->main.is_reset_folder_info = KAL_TRUE;

        if (msg_box_type == UM_MSG_BOX_TYPE_INBOX)
        {
            kal_uint32 cur_msg_timestamp =
                g_um_p->folder.msg_list[g_um_p->folder.current_msg_index].list_info.timestamp;

            if (cur_msg_timestamp <= timestamp)
            {
                (g_um_p->folder.current_msg_index)++;
            }
        }
    }

#ifdef __MMI_MMS_2__
    if(msg_type == UM_MSG_TYPE_MMS)
    {
        mmi_umms_entry_new_mms_hndlr(msg_box_type,msg_index);
    }
#endif /* __MMI_MMS_2__ */

}
/*****************************************************************************
 * FUNCTION
 *  mmi_um_search_position_in_um_list
 * DESCRIPTION
 *  find the posotion of this input message
 * PARAMETERS
 *  msg_type            [IN]        
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  the position
 *****************************************************************************/

U16 mmi_um_search_position_in_um_list(UmMsgType msg_type, kal_uint16 msg_index)
{
    int i = 0;
    U16 return_position = 0;

    for (; i < g_um_p->folder.msg_number_in_list; i++)
    {
        if (g_um_p->folder.msg_list[i].msg_type == msg_type)
        {
            if (g_um_p->folder.msg_list[i].list_info.msg_index == msg_index)
            {
                return_position = i;
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[UnifiedMessageMiscell.c] mmi_um_search_position_in_um_list  SUCCESS %d -------*\n", i);
                return return_position;
            }
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedMessageMiscell.c] mmi_um_search_position_in_um_list  NOT FOUND-------*\n");
    return 0; /*If can not find, default set highlight to the first position*/

}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_decided_by_um_ind
 * DESCRIPTION
 *  set msg to be highlighted, decided by UM
 * PARAMETERS
 *  msg_type            [IN]        
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_decided_by_um_ind(UmMsgType msg_type, UmMsgBoxType msg_box_type, kal_uint16 msg_index)
{
//should decide the new postion for HL here
    U16 found_pos = 0;
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UM] mmi_um_highlight_decided_by_um_ind msg_type: %d msgbox_type: %d msg_index: %d *\n",
                             msg_type, msg_box_type, msg_index);

    if (msg_box_type != g_um_p->folder.current_msg_box)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UM] mmi_um_highlight_decided_by_um_ind current_msg_box: %d *\n",
                             g_um_p->folder.current_msg_box);
        return;
    }    
    /*Find the position of this message*/
    found_pos = mmi_um_search_position_in_um_list(msg_type, msg_index);

    /*Decide the highlight*/
    if (found_pos < g_um_p->folder.current_msg_index) 
    {
        (g_um_p->folder.current_msg_index)--;
    }
    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_um_highlight_msg_ind
 * DESCRIPTION
 *  set msg to be highlighted
 * PARAMETERS
 *  msg_type            [IN]        
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_highlight_msg_ind(UmMsgType msg_type, UmMsgBoxType msg_box_type, kal_uint16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedMessageMiscell.c] mmi_um_highlight_msg_ind msg_type: %d msgbox_type: %d msg_index: %d *\n",
                         msg_type, msg_box_type, msg_index);

    if (msg_box_type != g_um_p->folder.current_msg_box)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedMessageMiscell.c] mmi_um_highlight_msg_ind current_msg_box: %d *\n",
                             g_um_p->folder.current_msg_box);
        return;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedMessageMiscell.c] mmi_um_highlight_msg_ind  SUCCESS-------*\n");

    g_um_p->folder.is_highlight_change_needed = KAL_TRUE;
    g_um_p->folder.msg_to_highlight.msg_type = msg_type;
    g_um_p->folder.msg_to_highlight.msg_index = msg_index;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_change_highlight
 * DESCRIPTION
 *  Change the highlight by message applications request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_change_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < g_um_p->folder.msg_number_in_list; i++)
    {
        if (g_um_p->folder.msg_list[i].msg_type == g_um_p->folder.msg_to_highlight.msg_type)
        {
            if (g_um_p->folder.msg_list[i].list_info.msg_index == g_um_p->folder.msg_to_highlight.msg_index)
            {
                g_um_p->folder.current_msg_index = i;
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*[UnifiedMessageMiscell.c] mmi_um_change_highlight  SUCCESS %d -------*\n", i);
                return;
            }
        }
    }

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedMessageMiscell.c] mmi_um_change_highlight  NOT FOUND-------*\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_set_highlight_msg
 * DESCRIPTION
 *  set highlighted msg
 * PARAMETERS
 *  list_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_set_highlight_msg(kal_uint16 list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedMessageMiscell.c] mmi_um_set_highlight_msg  index = %d -------*\n",
                         list_index);
    g_um_p->folder.current_msg_index = list_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_check_new_msg
 * DESCRIPTION
 *  check if new msg arrives
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mmi_um_check_new_msg()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY) /* WLAN only */ 
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedMessageMiscell.c] mmi_um_check_new_msg  WLAN only mode! -------*\n");
        
        return KAL_FALSE;    
    }
#endif /* __MMI_WLAN_FEATURES__ */
    return (kal_uint8) g_um_p->main.is_new_msg;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_current_msg_box_type
 * DESCRIPTION
 *  get the type of current msg box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
UmMsgBoxType mmi_um_get_current_msg_box_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_um_p->folder.current_msg_box;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_is_available
 * DESCRIPTION
 *  check if unified message is available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mmi_um_is_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if MMS and WAP push is available */
    if (!wap_is_message_resource_available())
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedMessageMiscell.c] mmi_um_is_available(), WAP is busy");

        return KAL_FALSE;
    }

    /* Check if SMS is available */
    if (IsMessagesReEntering())
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedMessageMiscell.c] mmi_um_is_available(), SMS is busy");

        return KAL_FALSE;
    }

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedMessageMiscell.c] mmi_um_is_available(), UM is available");

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_on_enter_idle_screen
 * DESCRIPTION
 *  reset context when entering idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_on_enter_idle_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_um_p->main.state = UM_STATE_IDLE;
    g_um_p->main.is_skip_write_menu = KAL_FALSE;
    g_um_p->main.main_index = 0;
    g_um_p->main.is_reset_folder_info = KAL_TRUE;
    g_um_p->folder.is_highlight_change_needed = KAL_FALSE;
    g_um_p->folder.current_msg_box = 0;
    g_um_p->folder.current_msg_index = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_handle_sim_refresh
 * DESCRIPTION
 *  handle sim refresh case
 * PARAMETERS
 *  msg_type            [IN]        
 *  popup_displayed     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_handle_sim_refresh(UmMsgType msg_type, kal_uint8 popup_displayed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_screen = GetExitScrnID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedMessageMiscell.c] mmi_um_handle_sim_refresh(), msg_type=%d, popup_displayed=%d",
                         msg_type, popup_displayed);

    if (!popup_displayed)
    {
        if (current_screen > SCR_ID_UM_START && current_screen < SCR_ID_UM_END)
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_SIM_REFRESH),
                IMG_GLOBAL_WARNING,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) WARNING_TONE);
        }
    }

    g_um_p->main.ready_type &= ~(msg_type);

    DeleteScreenIfPresent(SCR_ID_UM_MAIN);
    DeleteScreenIfPresent(SCR_ID_UM_WRITE_MSG);
    DeleteScreenIfPresent(SCR_ID_UM_DELETE_FOLDER);
    DeleteScreenIfPresent(SCR_ID_UM_TEMPLATE);
    DeleteScreenIfPresent(SCR_ID_UM_SETTING);
    DeleteScreenIfPresent(SCR_ID_UM_PROCESSING);
    DeleteScreenIfPresent(SCR_ID_UM_INBOX);
    DeleteScreenIfPresent(SCR_ID_UM_UNSENT);
    DeleteScreenIfPresent(SCR_ID_UM_SENT);
    DeleteScreenIfPresent(SCR_ID_UM_DRAFT);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    DeleteScreenIfPresent(SCR_ID_UM_ARCHIVE);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    g_um_p->main.is_new_msg = KAL_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_um_reset_folder_history_guibuffer
 * DESCRIPTION
 *  reset folder history gui buffer
 * PARAMETERS
 *  screen_id           [IN]        
 * RETURNS
 *  kal_bool 
 *****************************************************************************/
kal_bool mmi_um_reset_folder_history_guibuffer(U16 screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode* history = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetHistoryPointer(screen_id, &history);

    if (history != NULL)
    {    
        if (history->guiBuffer != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*[UnifiedMessageMiscell.c] mmi_um_reset_folder_history_guibuffer(), screen_id=%d",
                                 screen_id);

            OslMfree(history->guiBuffer);
            history->guiBuffer = NULL;
        }
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_is_sending_num_msg
 * DESCRIPTION
 *  check if active screen is sending the messages to get counts
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mmi_um_is_sending_num_msg(void)
{
//    return g_um_p->main.is_ready_for_new_msg;
    if (GetExitScrnID() != SCR_ID_UM_NEW_MSG_DUMMY_IND)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_check_interrupt
 * DESCRIPTION
 *  check if there is an interrupt (incoming call ringing, outgoing call, or alarm playing).
 * PARAMETERS
 *  void
 * RETURNS
 *  1: interrupt existed, 0: interrupt not existed
 *****************************************************************************/
kal_bool mmi_um_check_interrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isIncomingCall())
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[UnifiedMessageMiscell.c] mmi_um_check_interrupt Incoming Call -------*\n");
        return MMI_TRUE;
    }
    else if (isOutgoingCall())
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[UnifiedMessageMiscell.c] mmi_um_check_interrupt Outgoing Call -------*\n");
        return MMI_TRUE;
    }
    else if (AlmIsTonePlaying())
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*-------[UnifiedMessageMiscell.c] mmi_um_check_interrupt Alarm -------*\n");
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_um_get_not_available_string_id
 * DESCRIPTION
 *  Get string ID for not available case
 * PARAMETERS
 *  void
 * RETURNS
 *  UM not available string ID
 *****************************************************************************/
kal_uint16 mmi_um_get_not_available_string_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint16)STR_UM_NOT_AVAILABLE;
}
    
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* _MMI_UNIFIED_MESSAGE_MISCELL_C */ 

