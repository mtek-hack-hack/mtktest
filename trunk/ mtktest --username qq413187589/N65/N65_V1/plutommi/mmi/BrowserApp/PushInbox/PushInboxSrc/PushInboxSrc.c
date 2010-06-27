
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
 * PushInboxSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for UI handling for the profile handler
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

#define __NEWSIMULATOR

#include "MMI_include.h"



#include "Wgui_status_icons.h"

#include "CommonScreens.h"


#include "SMSGuiInterfaceType.h"
#include "SMSGuiInterfaceProt.h"
#include "PushInboxResDef.h"
#include "PushInboxProts.h"
#include "IdleAppDef.h"
#include "ProfileHandlerResDef.h"
#include "BrowserGprots.h"
#include "custom_nvram_editor_data_item.h"

#include "Nvram_enums.h"

#include "ProtocolEvents.h"
#include "DateTimeGprot.h"
#include "SettingProfile.h"
// #include "Types.h"
#include "time.h"
#include "MessagesResourceData.h"
#include "Wap.h"
#include "gpioInc.h"

#include "stack_types.h"

#include "SMSApi.h"
#include "smsal_l4c_enum.h"
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif
#include "wapadp.h"

#undef __NEWSIMULATOR
#ifdef __MMI_BROWSER_2__


push_msg_ind_queue_struct *new_phs_msg_queue = NULL;
push_msg_ind_queue_struct *curr_push_msg = NULL;

push_dlg_queue_struct *g_new_phs_dlg_queue = NULL;
push_service_dlg_struct *g_service_dlg = NULL;

wap_pmg_get_msg_cnf_struct *g_push_msg_rsp_data = NULL;
pmg_detailed_msg_struct *g_new_msg_data = NULL;
global_push_inbox_msg_struct *g_push_inbox_msg_buffer[MAX_PUSH_MSG] = {NULL};

static S8 *g_push_msg_rsp_href = NULL;
static U8 *g_message_buffer = NULL;
static U8 *g_new_msg_href = NULL;
static U8 *g_new_sl_href = NULL;

static pBOOL g_push_high_priority_flag = FALSE;
static pBOOL g_push_inbox_entry_flag = FALSE;
static pBOOL g_push_free_gui_buffer_flag = FALSE;
static pBOOL g_push_entry_validation_flag = FALSE;
static pBOOL g_psh_boot_up_flag = FALSE;
static pBOOL g_idle_callback = FALSE;
/* static varaibles declaration */
static U8 push_mempool_g[PUSH_MAX_MEM_SIZE];
static KAL_ADM_ID push_admid_g;
static S32 push_mempool_max_alloc;
static S32 push_mempool_total_left;

#ifdef __MMI_EMAIL_
	extern void mmi_email_app_send_cont(const S8* cont);  /*to send UCS2 string as email's content*/
#endif
extern pBOOL isInCall(void);
extern pBOOL mmi_bootup_is_sim_valid(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_inbox_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_inbox_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    push_admid_g = kal_adm_create((void*)push_mempool_g, (kal_uint32) PUSH_MAX_MEM_SIZE, NULL, (kal_bool) KAL_FALSE);

    push_mempool_max_alloc = kal_adm_get_max_alloc_size(push_admid_g);
    push_mempool_total_left = kal_adm_get_total_left_size(push_admid_g);

    SetProtocolEventHandler((PsFuncPtr) mmi_brw_push_new_msg_ind, MSG_ID_WAP_PMG_NEW_MSG_IND);
    SetProtocolEventHandler(mmi_brw_push_msg_delete_ind, MSG_ID_WAP_PMG_DELETE_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_brw_push_replace_msg_ind, MSG_ID_WAP_PMG_REPLACE_IND);
	 SetProtocolEventHandler(mmi_brw_push_storage_full_ind,MSG_ID_WAP_PMG_DLG_PUSH_STORAGE_FULL_IND);
    SetProtocolEventHandler(mmi_brw_push_msg_count_rsp, MSG_ID_WAP_PMG_MSG_COUNT_CNF);
    SetProtocolEventHandler(mmi_brw_push_msg_list_rsp, MSG_ID_WAP_PMG_MSG_LIST_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_brw_push_get_msg_rsp, MSG_ID_WAP_PMG_GET_MSG_CNF);
    SetProtocolEventHandler(mmi_brw_push_delete_msg_rsp, MSG_ID_WAP_PMG_DELETE_MSG_CNF);
    SetProtocolEventHandler(mmi_brw_push_delete_all_msg_rsp, MSG_ID_WAP_PMG_DELETE_ALL_CNF);
    SetProtocolEventHandler(mmi_brw_push_update_msg_rsp, MSG_ID_WAP_PMG_UPDATE_MSG_CNF);
    SetProtocolEventHandler(mmi_brw_push_config_msg_cnf, MSG_ID_WAP_PMG_CONFIG_CNF);
	SetProtocolEventHandler(mmi_brw_push_service_dlg_confirm_req, MSG_ID_WAP_PMG_DLG_SIA_CONFIRM_REQ);
	SetProtocolEventHandler(mmi_brw_push_service_dlg_unknown_addr_req, MSG_ID_WAP_PMG_DLG_UNKNOWN_ADDR_REQ);

#ifdef __MMI_UNIFIED_MESSAGE__
    /* SetProtocolEventHandler(mmi_push_um_delete_all_res,MSG_ID_MMI_UM_DELETE_ALL_RES); */
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_READ, mmi_brw_um_push_read_highlight_hdlr);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_GOTO, mmi_brw_push_goto_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_ADD_TO_TRUST_LIST, mmi_brw_push_add_to_trust_list_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_ADD_HOMEPAGE, mmi_brw_push_add_homepage_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_SEND_BY, mmi_brw_push_send_by_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_DELETE, mmi_brw_push_delete_highlight_hdlr);
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ 	
	SetHiliteHandler(MENU_ID_PUSH_UM_COMPILE_OPTION_MSG_DELETE, mmi_brw_um_compile_option_delete_highlight_hdlr);
#endif
#ifdef __MMI_VBOOKMARK__
	SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_ADD_BOOKMARK,mmi_brw_push_add_bookmark_highlight_hdlr);
#endif
    
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_DELETE_ALL, mmi_brw_push_delete_all_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL, mmi_brw_push_send_by_email_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_SMS, mmi_brw_push_send_by_sms_highlight_hdlr);
    SetHiliteHandler(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS, mmi_brw_push_send_by_mms_highlight_hdlr);


    mmi_brw_phs_get_setting_from_nvram();
    StartTimer(BRW_PSH_INIT_TIMER, 1000, mmi_brw_phs_get_unread_msg_count);

    g_push_cntx.arrived_service_msg = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_phs_get_unread_msg_count
 * DESCRIPTION
 *  Get the unread message count at boot up to show status icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_phs_get_unread_msg_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	 U8 index = 0;	
	 U8 trustaddr_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_is_ready())
    {
        wap_pmg_msg_count_req_struct *local_data;

        local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

        local_data->transID = PUSH_INIT_UNREAD_COUNT_ID;
        local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
        local_data->isRead = WAP_PMG_PARAM_NO;
        local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
        local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

        g_psh_boot_up_flag = TRUE;
        mmi_brw_push_get_pmg_count_req(local_data);
		mmi_brw_psh_get_trust_list_count();

		if (g_push_cntx.trust_addr_count > 0)
		{
			while (index < g_push_cntx.trust_addr_count)
			{
				if ((g_push_cntx.trust_addr_count - index) < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE)
				{
					trustaddr_count = g_push_cntx.trust_addr_count - index;
					mmi_brw_push_send_trust_list(index, trustaddr_count);
					index = g_push_cntx.trust_addr_count;
				}
				else
				{
					mmi_brw_push_send_trust_list(index, WAP_PMG_MAX_MSG_ADDR_LIST_SIZE);
					index = index + WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
				}
			}
		}

        mmi_brw_push_stop_timer();
    }
    else
    {
        mmi_brw_push_stop_timer();
        StartTimer(BRW_PSH_INIT_TIMER, 1000, mmi_brw_phs_get_unread_msg_count);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_send_trust_list
 * DESCRIPTION
 *  send the trust list to service layer
 * PARAMETERS
 *  Index , count
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_send_trust_list(U8 index, U8 count)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
	wap_pmg_trust_addr_list_req_struct *local_data;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_TRUST_ADDR_LIST_REQ;

    local_data = (wap_pmg_trust_addr_list_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_trust_addr_list_req_struct));

    local_data->trans_id = 0;
	 local_data->size = count; 
	 local_data->segment = index/WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
	  
	 for (i = 0; i < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE; i++)
	 {
		 memset(local_data->addresses[i].addr,'\0',WAP_PMG_MAX_ADDR_CHARS+1);
		 local_data->addresses[i].addr_type = 0;
	 }

	 for (i = 0; i < count; i++)
	{
		local_data->addresses[i].addr_type
                    = push_setting_data->trust_addr_arr[index].addr_type;
        strcpy(
            (S8*) local_data->addresses[i].addr,
            (S8*) push_setting_data->trust_addr_arr[index].addr);

		index++;
	}		
    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_stop_timer
 * DESCRIPTION
 *  Stop the timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BRW_PSH_INIT_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_push_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_push_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(push_admid_g, (kal_uint32) size);
    push_mempool_max_alloc = kal_adm_get_max_alloc_size(push_admid_g);
    push_mempool_total_left = kal_adm_get_total_left_size(push_admid_g);

    ASSERT(ptr);

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_push_mfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_mfree(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(push_admid_g, ptr);
    push_mempool_max_alloc = kal_adm_get_max_alloc_size(push_admid_g);
    push_mempool_total_left = kal_adm_get_total_left_size(push_admid_g);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_new_queue_entry
 * DESCRIPTION
 *	A new push msg entry to queue for display at idle screen
 * PARAMETERS
 *  data        [IN]    
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_brw_push_new_queue_entry(pmg_detailed_msg_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *new_push_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
        return -1;

    new_push_msg = (push_msg_ind_queue_struct*) OslMalloc(sizeof(push_msg_ind_queue_struct));
    if (new_push_msg == NULL)
    {
        return -1;
    }

    new_push_msg->data.msgID = data->msgID;
    new_push_msg->data.msgType = data->msgType;
    new_push_msg->data.priority = data->priority;
    new_push_msg->data.trust_addr_type = data->smsc.addr_type;

    memset(new_push_msg->data.addr, '\0', WAP_PMG_MAX_ADDR_CHARS + 1);
    strncpy((S8*) new_push_msg->data.addr, (S8*) data->smsc.addr, WAP_PMG_MAX_ADDR_CHARS);

    new_push_msg->next = NULL;
    if (mmi_brw_push_check_duplicate_msg(new_push_msg))
    {
        return 0;
    }
    else
    {
        mmi_brw_push_push_entry(new_push_msg);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_check_duplicate_msg
 * DESCRIPTION
 *  Checks for duplicate message in the queue.
 * PARAMETERS
 *  push_msg        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_brw_push_check_duplicate_msg(push_msg_ind_queue_struct *push_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *push_msg_search = new_phs_msg_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (push_msg_search != NULL)
    {
        if (push_msg->data.msgID == push_msg_search->data.msgID)
        {
            push_msg_search->data.msgID = push_msg->data.msgID;
            push_msg_search->data.msgType = push_msg->data.msgType;
            push_msg_search->data.priority = push_msg->data.priority;

            return TRUE;
        }
        push_msg_search = push_msg_search->next;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_push_entry
 * DESCRIPTION
 *  Push the new entry to stack.
 * PARAMETERS
 *  new_push_msg        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_brw_push_push_entry(push_msg_ind_queue_struct *new_push_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *tail = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_push_msg == NULL)
        return -1;

    tail = mmi_brw_push_get_last_item();
    if (tail == NULL)
    {
        new_phs_msg_queue = new_push_msg;
    }
    else
    {
        tail->next = new_push_msg;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_get_last_item
 * DESCRIPTION
 *  Get the last item from the queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
push_msg_ind_queue_struct *mmi_brw_push_get_last_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *push_msg_rear = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    push_msg_rear = new_phs_msg_queue;

    if (push_msg_rear == NULL)
    {
        return NULL;
    }

    while (push_msg_rear->next != NULL)
    {
        push_msg_rear = push_msg_rear->next;
    }
    push_msg_rear->next = NULL;

    return push_msg_rear;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_pop_entry
 * DESCRIPTION
 *  Get the entry from the front of the queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
push_msg_ind_queue_struct *mmi_brw_push_pop_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *push_msg_front = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_phs_msg_queue == NULL)
    {
        return NULL;
    }

    push_msg_front = new_phs_msg_queue;

    if (new_phs_msg_queue->next != NULL)
    {
        new_phs_msg_queue = new_phs_msg_queue->next;
    }
    else
    {
        new_phs_msg_queue = NULL;
    }

    push_msg_front->next = NULL;

    return push_msg_front;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_free_queue_entry
 * DESCRIPTION
 *  Free the memory held by push msg.
 * PARAMETERS
 *  the_item        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_free_queue_entry(push_msg_ind_queue_struct *the_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (the_item != NULL)
    {
        OslMfree(the_item);
        the_item = NULL;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_last_msg_from_queue
 * DESCRIPTION
 *  Delete the last msg from the queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_last_msg_from_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *push_entry = new_phs_msg_queue;
    push_msg_ind_queue_struct *last_push_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_phs_msg_queue->next == NULL)
    {
        OslMfree(new_phs_msg_queue);
        new_phs_msg_queue = NULL;
        return;
    }
    while (push_entry->next != NULL)
    {
        last_push_entry = push_entry;
        push_entry = push_entry->next;
    }

    last_push_entry->next = push_entry->next;
    OslMfree(push_entry);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_msg_from_queue
 * DESCRIPTION
 *  Delete the msg from the queue.
 * PARAMETERS
 *  msgID       [IN]        
 * RETURNS
 * pBOOL 
 *****************************************************************************/
pBOOL mmi_brw_push_delete_msg_from_queue(S32 msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *push_element = NULL, *prev_push_element = NULL;
   // wap_pmg_delete_msg_req_struct delete_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_push_element = push_element = new_phs_msg_queue;

//	delete_msg.transID = NEW_MSG_DEL_ID;
   // delete_msg.msgID = msgID;

    if (push_element != NULL)
    {
        if (push_element->data.msgID == msgID)
        {
            if (push_element->next == NULL)
            {
                OslMfree(new_phs_msg_queue);
                new_phs_msg_queue = NULL;
              //  mmi_brw_push_send_delete_msg_req(&delete_msg);
                return TRUE;
            }
            else
            {
                new_phs_msg_queue = new_phs_msg_queue->next;
                OslMfree(push_element);
               // mmi_brw_push_send_delete_msg_req(&delete_msg);
                return TRUE;
            }
        }

        while (push_element != NULL)
        {
            if (push_element->data.msgID == msgID)
            {
                prev_push_element->next = push_element->next;
                OslMfree(push_element);
               // mmi_brw_push_send_delete_msg_req(&delete_msg);
                return TRUE;
            }
            prev_push_element = push_element;
            push_element = push_element->next;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_replace_msg_from_queue
 * DESCRIPTION
 *  Replace the msg in queue .This API is called wrt relace ind.
 * PARAMETERS
 *  replace_msg_ind     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_brw_push_replace_msg_from_queue(wap_pmg_replace_ind_struct *replace_msg_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *push_element = new_phs_msg_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (push_element != NULL)
    {
        if (push_element->data.msgID == replace_msg_ind->msgData.msgID)
        {
            push_element->data.msgID = replace_msg_ind->msgData.msgID;
            push_element->data.msgType = replace_msg_ind->msgData.msgType;
            push_element->data.priority = replace_msg_ind->msgData.priority;
            push_element->data.trust_addr_type = replace_msg_ind->msgData.smsc.addr_type;

            memset(push_element->data.addr, '\0', sizeof(push_element->data.addr));
            strncpy((S8*) push_element->data.addr, (S8*) replace_msg_ind->msgData.smsc.addr, 129);

            return TRUE;
        }
        push_element = push_element->next;
    }

    return FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_free_sl_from_queue
 * DESCRIPTION
 *  Free all the SL entry from the queue
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_brw_push_free_sl_from_queue(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *push_queue = new_phs_msg_queue ,*push_element = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	push_element = push_queue;

	while (push_queue != NULL)
	{
		if (push_queue->data.msgType == WAP_PMG_MSGTYPE_SL)
		{
			if (push_queue->next != NULL)
			{
				push_msg_ind_queue_struct *temp = NULL;
				push_queue->data.msgID = push_queue->next->data.msgID;
				push_queue->data.msgType = push_queue->next->data.msgType;
				push_queue->data.priority = push_queue->next->data.priority;
				push_queue->data.trust_addr_type = push_queue->next->data.trust_addr_type;

				memset(push_queue->data.addr, '\0', sizeof(push_queue->data.addr));
				strncpy((S8*) push_queue->data.addr, (S8*) push_queue->next->data.addr, 129);

				temp = push_queue->next;
				push_queue->next = push_queue->next->next;

				OslMfree(temp);
				temp = NULL;

			}
			else
			{
				OslMfree(push_queue);
				if (push_element == push_queue)
				{
					new_phs_msg_queue = NULL;
					push_queue = NULL;
				}
				else
				{
					while (1)
					{
						if (push_element->next == push_queue)
						{
							push_element->next = NULL;
							push_queue = NULL;
							break;
						}
						else
						{
							push_element = push_element->next;
						}
					}
				}
			}
		}
		else
		{
			push_queue = push_queue->next;
		}
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_add_new_msg_at_front_inbox_buffer
 * DESCRIPTION
 *  Insert the new push message at 0th entry in push inbox buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_brw_push_add_new_msg_at_front_inbox_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;

      /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  count = g_push_cntx.push_msg_count;
	while (g_push_inbox_msg_buffer[count] != NULL)
	{
		count++;
	}

    if (count < MAX_PUSH_MSG /* && push_mempool_total_left > sizeof(global_push_inbox_msg_struct) */ )
    {
        if (g_push_inbox_msg_buffer[count] == NULL)
        {
            g_push_inbox_msg_buffer[count] = (global_push_inbox_msg_struct*) mmi_push_malloc
                (sizeof(global_push_inbox_msg_struct));
        }
        for (; count != 0; count--)
        {
            /* g_push_inbox_msg_buffer[count-1]->index++; */
            memcpy(
                g_push_inbox_msg_buffer[count],
                g_push_inbox_msg_buffer[count - 1],
                sizeof(global_push_inbox_msg_struct));
            /* g_push_inbox_msg_buffer[count] =  g_push_inbox_msg_buffer[count-1]; */
        }

        /* mmi_push_mfree(g_push_inbox_msg_buffer[0]);
           g_push_inbox_msg_buffer[0] = NULL;
           
           g_push_inbox_msg_buffer[0] = (global_push_inbox_msg_struct *)mmi_push_malloc
           (sizeof(global_push_inbox_msg_struct)); */

        g_push_inbox_msg_buffer[0]->data.msgID = g_new_msg_data->msgID;
        g_push_inbox_msg_buffer[0]->data.msgType = g_new_msg_data->msgType;
        g_push_inbox_msg_buffer[0]->data.created = g_new_msg_data->created;
        g_push_inbox_msg_buffer[0]->data.expired = g_new_msg_data->expired;
        g_push_inbox_msg_buffer[0]->data.priority = g_new_msg_data->priority;
        g_push_inbox_msg_buffer[0]->data.textType = g_new_msg_data->textType;
        g_push_inbox_msg_buffer[0]->data.read = g_new_msg_data->read;
        /* g_push_inbox_msg_buffer[0]->index = 0; */

        memset(g_push_inbox_msg_buffer[0]->data.href, '\0', WAP_PMG_MAX_MSG_LIST_HREF_CHARS + 1);
        if (g_new_msg_href && strcmp((S8*) g_new_msg_href, "") != 0)
        {
            strncpy(
                (S8*) g_push_inbox_msg_buffer[0]->data.href,
                (S8*) g_new_msg_href,
                WAP_PMG_MAX_MSG_LIST_HREF_CHARS);
        }
        memset(g_push_inbox_msg_buffer[0]->data.text, '\0', WAP_PMG_MAX_MSG_LIST_TEXT_CHARS + 1);
        if (g_push_inbox_msg_buffer[0]->data.textType == WAP_PMG_STRTYPE_ASCII)
        {
            /*    ucs2_msg = (PS8) OslMalloc((32+1)*ENCODING_LENGTH);
               if (ucs2_msg != NULL)
               {
               mmi_asc_n_to_ucs2 ((S8*)ucs2_msg,(S8*)g_new_msg_data->text,PMG_MAX_MSG_LIST_TEXT_CHARS+2);
               }
               mmi_ucs2ncpy((S8*)msg_data.data.text,(S8*)ucs2_msg,PMG_MAX_MSG_LIST_TEXT_CHARS+2);
               OslMfree(ucs2_msg);
               ucs2_msg = NULL; */

            strncpy(
                (S8*) g_push_inbox_msg_buffer[0]->data.text,
                (S8*) g_new_msg_data->text,
                WAP_PMG_MAX_MSG_LIST_TEXT_CHARS);

        }
        else if (g_push_inbox_msg_buffer[0]->data.textType == WAP_PMG_STRTYPE_UCS2)
        {
            mmi_ucs2ncpy(
                (S8*) g_push_inbox_msg_buffer[0]->data.text,
                (S8*) g_new_msg_data->text,
                WAP_PMG_MAX_MSG_LIST_TEXT_CHARS / 2);
        }

        //   memcpy (g_push_inbox_msg_buffer[0],&msg_data,sizeof(msg_data));
        //   g_push_inbox_msg_buffer[0] = &msg_data;
        g_push_free_gui_buffer_flag = TRUE;

        g_push_cntx.push_msg_count++;
        g_push_cntx.push_msg_index++;

        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_msg_from_inbox_buffer
 * DESCRIPTION
 *  Delete the msg from the push inbox buffer based on msg ID.
 * PARAMETERS
 *  msgID       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_brw_push_delete_msg_from_inbox_buffer(S32 msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	pBOOL free_buffer = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_free_gui_buffer_flag = FALSE;

    if (g_push_inbox_msg_buffer[0] != NULL)
    {
        for (i = 0; i < g_push_cntx.push_msg_count; i++)
        {
            if (g_push_inbox_msg_buffer[i]->data.msgID == msgID)
            {
                if (g_push_cntx.push_msg_count == 1)
                {
                    mmi_push_mfree(g_push_inbox_msg_buffer[i]);
                    g_push_inbox_msg_buffer[i] = NULL;
                    g_push_cntx.push_msg_count = 0;
                    return TRUE;
                }
                else if (i == g_push_cntx.push_msg_count - 1)
                {
                    mmi_push_mfree(g_push_inbox_msg_buffer[i]);
                    g_push_inbox_msg_buffer[i] = NULL;
                    g_push_cntx.push_msg_index--;
                    g_push_cntx.push_msg_count--;

                    g_push_free_gui_buffer_flag = TRUE;
                    return TRUE;
                }
                else
                {
                    if (i < g_push_cntx.push_msg_index)
                    {
                        g_push_cntx.push_msg_index--;
                        g_push_free_gui_buffer_flag = TRUE;
                    }
                    while (i < g_push_cntx.push_msg_count - 1)
                    {
                        if (free_buffer == FALSE)
						{
							mmi_push_mfree(g_push_inbox_msg_buffer[i]);
							g_push_inbox_msg_buffer[i] = NULL;
							free_buffer = TRUE;
						}
                        g_push_inbox_msg_buffer[i] = g_push_inbox_msg_buffer[i + 1];
                        i++;
                    }
                    g_push_inbox_msg_buffer[i] = NULL;
                    g_push_cntx.push_msg_count--;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_replace_msg_from_inbox_buffer
 * DESCRIPTION
 *  Replace the msg in the buffer corresponds to the msgID.
 * PARAMETERS
 *  replace_msg_ind     [IN]     
 *  href                [IN]     
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_brw_push_replace_msg_from_inbox_buffer(wap_pmg_replace_ind_struct *replace_msg_ind, U8 *href)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_push_cntx.push_msg_count; i++)
    {
        if (g_push_inbox_msg_buffer[i]->data.msgID == replace_msg_ind->msgData.msgID)
        {
            if (replace_msg_ind->msgData.msgType == WAP_PMG_MSGTYPE_SI)
            {
                if ((href && strcmp((S8*) href, "") == 0) ||
                    (replace_msg_ind->msgData.text && replace_msg_ind->msgData.text[0] == '\0'))
                {
                    wap_pmg_delete_msg_req_struct delete_msg;

                    delete_msg.transID = NEW_MSG_DEL_ID;
                    delete_msg.msgID = replace_msg_ind->msgData.msgID;

                    mmi_brw_push_delete_msg_from_inbox_buffer(g_push_inbox_msg_buffer[i]->data.msgID);
                    mmi_brw_push_send_delete_msg_req(&delete_msg);

                    return FALSE;
                }
            }

            g_push_inbox_msg_buffer[i]->data.msgID = replace_msg_ind->msgData.msgID;
            g_push_inbox_msg_buffer[i]->data.msgType = replace_msg_ind->msgData.msgType;
            g_push_inbox_msg_buffer[i]->data.created = replace_msg_ind->msgData.created;
            g_push_inbox_msg_buffer[i]->data.expired = replace_msg_ind->msgData.expired;
            g_push_inbox_msg_buffer[i]->data.priority = replace_msg_ind->msgData.priority;
            g_push_inbox_msg_buffer[i]->data.textType = replace_msg_ind->msgData.textType;
            g_push_inbox_msg_buffer[i]->data.read = replace_msg_ind->msgData.read;

            memset(g_push_inbox_msg_buffer[i]->data.href, '\0', WAP_PMG_MAX_MSG_LIST_HREF_CHARS + 1);
            strncpy((S8*) g_push_inbox_msg_buffer[i]->data.href, (S8*) href, WAP_PMG_MAX_MSG_LIST_HREF_CHARS);

            if (replace_msg_ind->msgData.textType == WAP_PMG_STRTYPE_ASCII)
            {
                /* ucs2_msg = (PS8) OslMalloc((32+1)*ENCODING_LENGTH);
                   if (ucs2_msg != NULL)
                   {
                   mmi_asc_n_to_ucs2 ((S8*)ucs2_msg,(S8*)replace_msg_ind->msgData.text,PMG_MAX_MSG_LIST_TEXT_CHARS+2);
                   }
                   mmi_ucs2ncpy((S8*)g_push_inbox_msg_buffer[i]->data.text,(S8*)ucs2_msg,
                   PMG_MAX_MSG_LIST_TEXT_CHARS+2); */
                strncpy(
                    (S8*) g_push_inbox_msg_buffer[i]->data.text,
                    (S8*) replace_msg_ind->msgData.text,
                    WAP_PMG_MAX_MSG_LIST_TEXT_CHARS);
                //     OslMfree(ucs2_msg);
                //     ucs2_msg = NULL;
            }
            else if (replace_msg_ind->msgData.textType == WAP_PMG_STRTYPE_UCS2)
            {
                mmi_ucs2ncpy(
                    (S8*) g_push_inbox_msg_buffer[i]->data.text,
                    (S8*) replace_msg_ind->msgData.text,
                    WAP_PMG_MAX_MSG_LIST_TEXT_CHARS / 2);
            }

            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_new_msg_ind
 * DESCRIPTION
 *  Get the new msg indication from the service layer.It sets the global data (g_new_msg_data & g_new_msg_href)
	to the new arrived message data.

	In case of UM it pass the data to UM .
 * PARAMETERS
 *  local_param     [IN]         
 *  mod_id          [IN]        
 *  ilm             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_new_msg_ind(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE *ilm_info = (MYQUEUE*) ilm;
    wap_pmg_new_msg_ind_struct *data = (wap_pmg_new_msg_ind_struct*) local_param;
    U16 pdu_length = 0;

    U8 *local_href = NULL;

 //   wap_pmg_msg_count_req_struct *local_data;

#ifdef __MMI_UNIFIED_MESSAGE__
    wap_pmg_delete_msg_req_struct delete_msg;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (g_new_msg_data == NULL)
    {
        g_new_msg_data = (pmg_detailed_msg_struct*) OslMalloc(sizeof(pmg_detailed_msg_struct));
        if (g_new_msg_data == NULL)
        {
            MMI_ASSERT(0);
        }
    }

    g_new_msg_data->msgID = data->msgData.msgID;
    g_new_msg_data->msgType = data->msgData.msgType;
    g_new_msg_data->created = data->msgData.created;
    g_new_msg_data->expired = data->msgData.expired;
    g_new_msg_data->priority = data->msgData.priority;
    g_new_msg_data->textType = data->msgData.textType;
    g_new_msg_data->read = data->msgData.read;
    g_new_msg_data->hasInfo = data->msgData.hasInfo;

    memset((S8*) g_new_msg_data->text, '\0', sizeof(g_new_msg_data->text));
    if (g_new_msg_data->textType == WAP_PMG_STRTYPE_ASCII)
    {
        strcpy((S8*) g_new_msg_data->text, (S8*) data->msgData.text);
    }
    else
    {
        mmi_ucs2cpy((S8*) g_new_msg_data->text, (S8*) data->msgData.text);
    }

    if (data->msgData.smsc.addr != NULL || data->msgData.smsc.addr[0] != '\0')
    {
        g_new_msg_data->smsc.addr_type = data->msgData.smsc.addr_type;
        strcpy((S8*) g_new_msg_data->smsc.addr, (S8*) data->msgData.smsc.addr);
    }
    /* g_new_msg_href = (U8 *) data->oslPeerBuffPtr; */

    if (ilm_info->peer_buff_ptr != NULL)
    {
        local_href = get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length);
        if (g_new_msg_href == NULL)
        {
            g_new_msg_href = (U8*) OslMalloc(WAP_PMG_MAX_MSG_LIST_HREF_CHARS + 1);
            if (g_new_msg_href == NULL)
            {
                MMI_ASSERT(0);
            }
        }
        memset((S8*) g_new_msg_href, '\0', WAP_PMG_MAX_MSG_LIST_HREF_CHARS + 1);
        strncpy((S8*) g_new_msg_href, (S8*) local_href, WAP_PMG_MAX_MSG_LIST_HREF_CHARS);
    }
    else
    {
        if (g_new_msg_href != NULL)
        {
            OslMfree(g_new_msg_href);
            g_new_msg_href = NULL;
        }
    }

#ifndef __MMI_UNIFIED_MESSAGE__

    if (g_new_msg_data != NULL)
    {
		mmi_brw_push_count_req_during_new_msg_ind();
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    if (push_setting_data->push_enable_flag != PUSH_ENABLE_OFF)
    {
		switch(g_new_msg_data->msgType)
        {
			case WAP_PMG_MSGTYPE_SL:
			if (g_new_msg_href && strcmp((S8*) g_new_msg_href, "") != 0)
			{
				switch(push_setting_data->sl_setting_flag)
				{
					case PUSH_SL_SETTING_NEVER:

            goto delete_msg;
						break;

					case PUSH_SL_SETTING_WITHOUT_CONFIRM:
					
						if (g_new_msg_data->priority == WAP_PMG_MSGPRIO_HIGH)
						{
							mmi_brw_push_count_req_during_new_msg_ind();
							return;
						}
						else
						{
							mmi_brw_um_push_process_new_msg_ind(data);	
							return;
						}
						break;

					case PUSH_SL_SETTING_CONFIRM:
												
						mmi_brw_um_push_process_new_msg_ind(data);
						return;
				}
			}
			else
			{
				goto delete_msg;
			}

			case WAP_PMG_MSGTYPE_SI:
				if ((g_new_msg_href && strcmp((S8*) g_new_msg_href, "") != 0) ||
						(g_new_msg_data->text && g_new_msg_data->text[0] != '\0'))
				{
				switch (g_new_msg_data->priority)
				{
					case WAP_PMG_MSGPRIO_HIGH: 
							
						mmi_brw_push_count_req_during_new_msg_ind();
						break;

					case WAP_PMG_MSGPRIO_MEDIUM: 
					case WAP_PMG_MSGPRIO_LOW:

						mmi_brw_um_push_process_new_msg_ind(data);
						break;
					/*
					case WAP_PMG_MSGPRIO_LOW:
						ShowStatusIcon(STATUS_ICON_WAP);
						UpdateStatusIcons();
						mmi_um_refresh_msg_ind();
						break;*/
				}
		}
				else
        {
            goto delete_msg;
        }
		}
	}
    else
    {
      delete_msg:

        delete_msg.transID = NEW_MSG_DEL_ID;
        delete_msg.msgID = g_new_msg_data->msgID;
        mmi_brw_push_send_delete_msg_req(&delete_msg);
        return;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
        }
#ifdef __MMI_UNIFIED_MESSAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_um_push_process_new_msg_ind
 * DESCRIPTION
 * This API send the new msg ind to UM.  
 * PARAMETERS.
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_um_push_process_new_msg_ind(wap_pmg_new_msg_ind_struct *data)
{
/*	if (push_setting_data->sl_setting_flag == PUSH_SL_SETTING_NEVER &&
            g_new_msg_data->msgType == WAP_PMG_MSGTYPE_SL)
    {
        goto delete_msg;
    }*/
	wap_pmg_delete_msg_req_struct delete_msg;
	MYQUEUE Message;
	mmi_um_new_msg_ind_struct um_msg_data;

    if (push_setting_data->trust_setting_flag == PUSH_TRUST_SETTING_ALWAYS
		&& !mmi_brw_push_construct_msg_for_validation())
            {
            delete_msg.transID = NEW_MSG_DEL_ID;
			delete_msg.msgID = g_new_msg_data->msgID;
			mmi_brw_push_send_delete_msg_req(&delete_msg);
                        return;
            }
        um_msg_data.ref_count = data->ref_count;
        um_msg_data.msg_len = data->msg_len;
        um_msg_data.msg_type = g_new_msg_data->msgType;
        um_msg_data.msg_index = g_new_msg_data->msgID;
        um_msg_data.timestamp = g_new_msg_data->created;
        um_msg_data.msg_box_type = UM_MSG_TYPE_WAP_PUSH;

        /* mmi_push_um_new_msg_ind(&um_msg_data); */
        ShowStatusIcon(STATUS_ICON_WAP);
        UpdateStatusIcons();

        if (GetActiveScreenId() != IDLE_SCREEN_ID)
        {
            if (g_push_inbox_entry_flag == TRUE)
            {
                mmi_brw_push_add_new_msg_at_front_inbox_buffer();
            }
            if (g_new_msg_data->msgType == WAP_PMG_MSGTYPE_SI && g_new_msg_data->priority == WAP_PMG_MSGPRIO_LOW)
            {
                if (SCR_ID_PUSH_INBOX == GetActiveScreenId())
                {
                    mmi_brw_push_new_push_msg_popup();
                }
            }
            else
            {
                mmi_brw_push_new_push_msg_popup();
            }
        }

	if (g_new_msg_data->msgType == WAP_PMG_MSGTYPE_SI &&
		g_new_msg_data->priority == WAP_PMG_MSGPRIO_LOW)
	{
		mmi_um_refresh_msg_ind();
	}
	else
	{
        mmi_push_um_new_msg_ind(&um_msg_data);
	}
	if (g_new_msg_data != NULL)
	{
		 OslMfree(g_new_msg_data);
		 g_new_msg_data = NULL;
	}
	if (g_new_msg_href != NULL)
	{
		 OslMfree(g_new_msg_href);
		 g_new_msg_href = NULL;
	}

	Message.oslSrcId = MOD_MMI;
   Message.oslDestId = MOD_WAP;
   Message.oslMsgId = MSG_ID_WAP_PMG_NEW_MSG_RSP;

   Message.oslDataPtr = (oslParaType*) NULL;
   Message.oslPeerBuffPtr = NULL;
   OslMsgSendExtQueue(&Message);
   PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[PushInboxSrc.c] mmi_brw_um_push_process_new_msg_ind \n");

    }
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_construct_msg_for_validation
 * DESCRIPTION
 *    
 * PARAMETERS.
 *  pBOOL
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_brw_push_construct_msg_for_validation(void)
{
	push_msg_ind_queue_struct *new_push_msg = NULL;

    new_push_msg = (push_msg_ind_queue_struct*) OslMalloc(sizeof(push_msg_ind_queue_struct));
    if (new_push_msg == NULL)
    {
        MMI_ASSERT(new_push_msg);
    }
    new_push_msg->data.msgID = g_new_msg_data->msgID;
    new_push_msg->data.msgType = g_new_msg_data->msgType;
    new_push_msg->data.priority = g_new_msg_data->priority;
	new_push_msg->data.trust_addr_type = g_new_msg_data->smsc.addr_type;

    memset(new_push_msg->data.addr, '\0', WAP_PMG_MAX_ADDR_CHARS + 1);
	strncpy((S8*) new_push_msg->data.addr, (S8*) g_new_msg_data->smsc.addr, WAP_PMG_MAX_ADDR_CHARS);

    new_push_msg->next = NULL;
    if (mmi_brw_push_validate_trust_list(new_push_msg) == FALSE)
    {
        OslMfree(new_push_msg);
		new_push_msg = NULL;
		return FALSE;
    }
    OslMfree(new_push_msg);
	new_push_msg = NULL;
	return TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_count_req_during_new_msg_ind
 * DESCRIPTION
 * This API req for message count when new msg indication comes in both UM and NON-UM.   
 * PARAMETERS.
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_count_req_during_new_msg_ind(void)
    {
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_pmg_msg_count_req_struct *local_data = NULL;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

    local_data->transID = PUSH_NEW_MSG_PROCESS_ID;
    local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->isRead = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

    mmi_brw_push_get_pmg_count_req(local_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_process_new_msg
 * DESCRIPTION
 * After unread msg count rsp ,it insert the new msg to queue to display at idle screen.   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_process_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_pmg_delete_msg_req_struct delete_msg;
	 MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_msg.transID = NEW_MSG_DEL_ID;
    delete_msg.msgID = g_new_msg_data->msgID;

    if (push_setting_data->push_enable_flag == PUSH_ENABLE_OFF)
    {
        mmi_brw_push_send_delete_msg_req(&delete_msg);
        return;
    }
	else if (push_setting_data->trust_setting_flag == PUSH_TRUST_SETTING_ALWAYS && 
			!mmi_brw_push_construct_msg_for_validation())
    {
        mmi_brw_push_send_delete_msg_req(&delete_msg);
        return;
    }
    else if (push_setting_data->sl_setting_flag == PUSH_SL_SETTING_NEVER &&
             g_new_msg_data->msgType == WAP_PMG_MSGTYPE_SL)
    {
        mmi_brw_push_send_delete_msg_req(&delete_msg);
        return;
    }
	else if (g_push_cntx.push_msg_count >= MAX_PUSH_MSG)
    {
        mmi_brw_push_send_delete_msg_req(&delete_msg);
        return;
    }

    switch (g_new_msg_data->msgType)
    {
        case WAP_PMG_MSGTYPE_SL:

            if (g_new_msg_href && strcmp((S8*) g_new_msg_href, "") != 0)
            {
                if (mmi_brw_push_new_queue_entry(g_new_msg_data) == 0)
                {
					if (GetActiveScreenId() == IDLE_SCREEN_ID && 
						g_new_msg_data->priority == WAP_PMG_MSGPRIO_HIGH &&
						push_setting_data->sl_setting_flag == PUSH_SL_SETTING_WITHOUT_CONFIRM)
					{
						TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
							PlayMessageArrivalTone();
					}
                    mmi_brw_push_handle_new_msg_display();
                }
            }
            else
            {
                mmi_brw_push_send_delete_msg_req(&delete_msg);
            }
            break;

        case WAP_PMG_MSGTYPE_SI:
            if ((g_new_msg_href && strcmp((S8*) g_new_msg_href, "") != 0) ||
                (g_new_msg_data->text && g_new_msg_data->text[0] != '\0'))
            {
                if (mmi_brw_push_new_queue_entry(g_new_msg_data) == 0)
                {
                    
					if (GetActiveScreenId() == IDLE_SCREEN_ID && 
						g_new_msg_data->priority == WAP_PMG_MSGPRIO_HIGH)
					{
						TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
								PlayMessageArrivalTone();
							}
					                    mmi_brw_push_handle_new_msg_display();
                }
            }
            else
            {
                mmi_brw_push_send_delete_msg_req(&delete_msg);
            }
            break;
    }
    if (g_new_msg_data != NULL)
    {
        OslMfree(g_new_msg_data);
        g_new_msg_data = NULL;
    }
    if (g_new_msg_href != NULL)
    {
        OslMfree(g_new_msg_href);
        g_new_msg_href = NULL;
    }

	 Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_NEW_MSG_RSP;

    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_handle_new_msg_display
 * DESCRIPTION
 *  This API validates the msg on different screen .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_handle_new_msg_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* switch (GetActiveScreenId())
       {
       case IDLE_SCREEN_ID:
       if (mmi_brw_push_new_queue_entry (g_new_msg_data) == 0)
       {
       mmi_brw_push_entry_new_push_msg_ind();
       }
       break;
       
       case SCR_ID_PUSH_INBOX: 
       mmi_brw_push_validate_msg_on_push_inbox_screen();
       break;
       
       default:
       mmi_brw_push_validate_msg_on_other_screen();
       break;
       } */

    if (GetActiveScreenId() == IDLE_SCREEN_ID)
    {
        if (IsKeyPadLockState() == 0)
		{
        mmi_brw_push_entry_new_push_msg_ind();
        }
		else
		{
			EntryIdleScreen();
        return;
    }
	}
    else if (IsScreenPresent(SCR_ID_PUSH_INBOX) || SCR_ID_PUSH_INBOX == GetActiveScreenId())
    {
        mmi_brw_push_validate_msg_on_push_inbox_screen();
        return;
    }
    else
    {
        mmi_brw_push_validate_msg_on_other_screen();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_validate_msg_on_other_screen
 * DESCRIPTION
 *  This API validates the msg on all screens except Push Inbox & Idle screen and updates the status icon 
	& depending on the priority it shows the new msg ind popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_validate_msg_on_other_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_pmg_delete_msg_req_struct delete_msg;
    push_msg_ind_queue_struct *last_push_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_push_msg = mmi_brw_push_get_last_item();

	 if (last_push_msg->data.msgType == WAP_PMG_MSGTYPE_SI && last_push_msg->data.priority == WAP_PMG_MSGPRIO_LOW)
	{
		ShowStatusIcon(STATUS_ICON_WAP);
		UpdateStatusIcons();
		#ifdef __MMI_UNIFIED_MESSAGE__
			mmi_um_refresh_msg_ind();			
		#endif
	}
	else
	{
		mmi_brw_push_new_push_msg_popup();
	}
/*
    if (push_setting_data->trust_setting_flag == PUSH_TRUST_SETTING_ALWAYS)
    {
        if (mmi_brw_push_validate_trust_list(last_push_msg) == TRUE)
        {
            if (last_push_msg->data.msgType == WAP_PMG_MSGTYPE_SI &&
                last_push_msg->data.priority == WAP_PMG_MSGPRIO_LOW)
            {
                ShowStatusIcon(STATUS_ICON_WAP);
                UpdateStatusIcons();
#ifdef __MMI_UNIFIED_MESSAGE__
				mmi_um_refresh_msg_ind();			
#endif
            }
            else
            {
                mmi_brw_push_new_push_msg_popup();
            }
            // mmi_brw_push_new_push_msg_popup(); 
        }
        else
        {
            delete_msg.transID = NEW_MSG_DEL_ID;
            delete_msg.msgID = last_push_msg->data.msgID;
            mmi_brw_delete_last_msg_from_queue();
            mmi_brw_push_send_delete_msg_req(&delete_msg);
        }
    }
    else
    {
        if (last_push_msg->data.msgType == WAP_PMG_MSGTYPE_SI && last_push_msg->data.priority == WAP_PMG_MSGPRIO_LOW)
        {
            ShowStatusIcon(STATUS_ICON_WAP);
            UpdateStatusIcons();
#ifdef __MMI_UNIFIED_MESSAGE__
				mmi_um_refresh_msg_ind();			
#endif
        }
        else
        {
            mmi_brw_push_new_push_msg_popup();
        }
        // mmi_brw_push_new_push_msg_popup(); 
    }
	*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_validate_msg_on_push_inbox_screen
 * DESCRIPTION
 *  This API validates the msg ,if push inbox screen is present.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_validate_msg_on_push_inbox_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_pmg_delete_msg_req_struct delete_msg;
    push_msg_ind_queue_struct *last_push_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_push_msg = mmi_brw_push_get_last_item();

    delete_msg.transID = NEW_MSG_DEL_ID;
    delete_msg.msgID = last_push_msg->data.msgID;

	if (mmi_brw_push_add_new_msg_at_front_inbox_buffer() == TRUE)
    {
        if (last_push_msg->data.msgType == WAP_PMG_MSGTYPE_SI &&
            last_push_msg->data.priority == WAP_PMG_MSGPRIO_LOW)
        {
            ShowStatusIcon(STATUS_ICON_WAP);
            UpdateStatusIcons();
            if (SCR_ID_PUSH_INBOX == GetActiveScreenId())
            {
                mmi_brw_push_new_push_msg_popup();
            }
        }
        else
        {
            mmi_brw_push_new_push_msg_popup();
        }
    }
    else
    {
        mmi_brw_push_send_delete_msg_req(&delete_msg);
    }
//	mmi_brw_delete_last_msg_from_queue(); (MAUI_00036260: this may create some issue for Bug fixed )
/*
    switch (push_setting_data->trust_setting_flag)
    {
        case PUSH_TRUST_SETTING_DISABLE:

            if (mmi_brw_push_add_new_msg_at_front_inbox_buffer() == TRUE)
            {
                if (last_push_msg->data.msgType == WAP_PMG_MSGTYPE_SI &&
                    last_push_msg->data.priority == WAP_PMG_MSGPRIO_LOW)
                {
                    ShowStatusIcon(STATUS_ICON_WAP);
                    UpdateStatusIcons();
                    if (SCR_ID_PUSH_INBOX == GetActiveScreenId())
                    {
                        mmi_brw_push_new_push_msg_popup();
                    }
                }
                else
                {
                    mmi_brw_push_new_push_msg_popup();
                }
            }
            else
            {
                mmi_brw_push_send_delete_msg_req(&delete_msg);
                           }
            break;

        case PUSH_TRUST_SETTING_ALWAYS:

            if (mmi_brw_push_validate_trust_list(last_push_msg) == TRUE)
            {
                if (mmi_brw_push_add_new_msg_at_front_inbox_buffer() == TRUE)
                {
                    if (last_push_msg->data.msgType == WAP_PMG_MSGTYPE_SI &&
                        last_push_msg->data.priority == WAP_PMG_MSGPRIO_LOW)
                    {
                        ShowStatusIcon(STATUS_ICON_WAP);
                        UpdateStatusIcons();
                        if (SCR_ID_PUSH_INBOX == GetActiveScreenId())
                        {
                            mmi_brw_push_new_push_msg_popup();
                        }
                    }
                    else
                    {
                        mmi_brw_push_new_push_msg_popup();
                    }
                                    }
                else
                {
                    mmi_brw_push_send_delete_msg_req(&delete_msg);
                                    }
            }
            else
            {
                mmi_brw_push_send_delete_msg_req(&delete_msg);
            }
            break;

        case PUSH_TRUST_SETTING_ALWAYS_ASK:

            if (mmi_brw_push_validate_trust_list(last_push_msg) == TRUE)
            {
                mmi_brw_push_add_new_msg_at_front_inbox_buffer();
                mmi_brw_push_new_push_msg_popup();
            }
            else
            {
                if (g_push_cntx.push_msg_count < MAX_PUSH_MSG)
                {
                    mmi_brw_push_entry_invalid_service_msg_on_pushinbox();
                }
            }
            break;
    }
    mmi_brw_delete_last_msg_from_queue();
	*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_free_msg_buffer
 * DESCRIPTION
 *  This API frees the memory occupied by push inbox buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_free_msg_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_push_inbox_msg_buffer[i] != NULL && i < MAX_PUSH_MSG)
    {
        mmi_push_mfree(g_push_inbox_msg_buffer[i]);
        g_push_inbox_msg_buffer[i] = NULL;
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_invalid_service_msg_on_pushinbox
 * DESCRIPTION
 *  This API shows the invalid msg screen .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_invalid_service_msg_on_pushinbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_INVALID_PUSH_MESSAGE, NULL, mmi_brw_push_entry_invalid_service_msg_on_pushinbox, NULL);
    ShowStatusIcon(STATUS_ICON_WAP);

    ShowCategory154Screen(
        0,
        0,
        STR_GLOBAL_ACCEPT,
        0,
        STR_GLOBAL_DISCARD,
        0,
        (PU8) GetString(STR_ID_PUSH_VALIDATION_FAIL_NEW_MSG),
        0,
        IMG_GLOBAL_INFO,
        NULL);

    SetLeftSoftkeyFunction(mmi_brw_push_accept_msg_push_inbox, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_push_delete_msg_push_inbox, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_accept_msg_push_inbox
 * DESCRIPTION
 *  If user accepts the invalid msg then msg will be placed at 0th entry in the push inbox buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_accept_msg_push_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_msg_ind_queue_struct *delete_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntx.push_msg_index = 0;
    if (g_push_entry_validation_flag == FALSE)
    {
        mmi_brw_push_add_new_msg_at_front_inbox_buffer();
    }
    else
    {
        g_push_entry_validation_flag = FALSE;
    }

    while (new_phs_msg_queue != NULL)
    {
        delete_msg = new_phs_msg_queue;
        new_phs_msg_queue = new_phs_msg_queue->next;
        OslMfree(delete_msg);
        delete_msg = NULL;
    }

    /* mmi_brw_push_pre_entry_inbox(); */
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_msg_push_inbox
 * DESCRIPTION
 *  this API delets the selected push msg from the inbox buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_msg_push_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_pmg_delete_msg_req_struct delete_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_msg.transID = INVALID_MSG_INBOX_DEL_ID;
    delete_msg.msgID = curr_push_msg->data.msgID;

    mmi_brw_push_free_queue_entry(curr_push_msg);
    mmi_brw_push_send_delete_msg_req(&delete_msg);

}

/* void mmi_brw_push_delete_last_msg(void)
   {
   mmi_brw_push_send_delete_msg_req(curr_push_msg->data.msgID);
   mmi_brw_delete_last_msg_from_queue();
   GoBackHistory();
   } */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_new_push_msg_ind
 * DESCRIPTION
 *  used for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_brw_push_new_push_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* g_psh_idle_screen_cb = FALSE; */
     PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[PushInboxSrc.c] mmi_brw_push_new_push_msg_ind() from idle scr callback \n");
    if (new_phs_msg_queue != NULL)
    {
        /* g_psh_idle_screen_cb = TRUE; */
		g_idle_callback = TRUE;
        return 1;
    }
    /* HideStatusIcon(STATUS_ICON_WAP); */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_new_push_msg_ind
 * DESCRIPTION
 *  Entry Function to display screen for push message arrived indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_new_push_msg_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 strid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strid = STR_ID_PUSH_SERVICE_MESSAGE_RCVD;

    GetCurrEndKeyDownHandler();

    if (IsKeyPadLockState() == 0)
    {
        mmi_brw_push_new_push_msg_ind_on_idlescreen();   
    }
    else    /* keypad is locked */
    {
		EntryNewScreen(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND, NULL, NULL, NULL);

		ShowStatusIcon(STATUS_ICON_WAP);
		UpdateStatusIcons();

		ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) GetString(strid),
            (PU8) NULL,
            IMG_NEW_MESSAGE_NOTIFICATION_MSG,
            NULL);

        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_new_push_msg_ind_on_idlescreen
 * DESCRIPTION
 *  Entry Function to display screen for push message arrived indication
 *  on idle-screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_new_push_msg_ind_on_idlescreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //   wap_pmg_delete_msg_req_struct delete_msg;

    curr_push_msg = mmi_brw_push_pop_entry();

 /*   delete_msg.transID = NEW_MSG_DEL_ID;
    delete_msg.msgID = curr_push_msg->data.msgID;

    if (push_setting_data->push_enable_flag == PUSH_ENABLE_OFF)
    {
        mmi_brw_push_free_queue_entry(curr_push_msg);
             while (new_phs_msg_queue != NULL)
        {
            push_msg_ind_queue_struct *del_entry = new_phs_msg_queue;

            new_phs_msg_queue = new_phs_msg_queue->next;
            OslMfree(del_entry);
            del_entry = NULL;
        }
        mmi_brw_push_send_delete_msg_req(&delete_msg);
    }
    else
    {*/
        mmi_brw_push_validate_service_msg();
   // }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_validate_service_msg
 * DESCRIPTION
 *  This API validates the push msg depending on the trust setting type.It will validate only if trust setting 
	is selected as Always or Always Ask.
	Currently Always Ask is being disabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_validate_service_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_pmg_delete_msg_req_struct delete_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_msg.transID = NEW_MSG_DEL_ID;
    delete_msg.msgID = curr_push_msg->data.msgID;

    switch (push_setting_data->trust_setting_flag)
    {
        case PUSH_TRUST_SETTING_DISABLE:
            mmi_brw_push_entry_new_service_msg();
            break;

        case PUSH_TRUST_SETTING_ALWAYS:

            if (mmi_brw_push_validate_trust_list(curr_push_msg) == TRUE)
            {
                mmi_brw_push_entry_new_service_msg();
            }
            else
            {
                mmi_brw_push_free_queue_entry(curr_push_msg);
                mmi_brw_push_send_delete_msg_req(&delete_msg);
            }
            break;

        case PUSH_TRUST_SETTING_ALWAYS_ASK:

            if (mmi_brw_push_validate_trust_list(curr_push_msg) == TRUE)
            {
                mmi_brw_push_entry_new_service_msg();
            }
            else
            {
                mmi_brw_push_entry_invalid_service_msg();
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_invalid_service_msg
 * DESCRIPTION
 *  This API show the invalid msg screen on idle screen ,if trust list validation fails.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_invalid_service_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_INVALID_PUSH_MESSAGE, NULL, mmi_brw_push_entry_invalid_service_msg, NULL);
    ShowStatusIcon(STATUS_ICON_WAP);
    ShowCategory154Screen(
        0,
        0,
        STR_GLOBAL_ACCEPT,
        0,
        STR_GLOBAL_DISCARD,
        0,
        (PU8) GetString(STR_ID_PUSH_VALIDATION_FAIL_NEW_MSG),
        0,
        IMG_GLOBAL_INFO,
        NULL);

    SetLeftSoftkeyFunction(mmi_brw_push_read_arrived_service_message, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_push_delete_invalid_msg, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_new_service_msg
 * DESCRIPTION
 *  This API shows the new service msg ind screen/display service msg directly/load the URL directly, depending 
	on the push setting,message type & message priority.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_new_service_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_high_priority_flag = FALSE;

    ShowStatusIcon(STATUS_ICON_WAP);
	UpdateStatusIcons();

    switch (curr_push_msg->data.msgType)
    {
        case WAP_PMG_MSGTYPE_SI:

            if (curr_push_msg->data.priority == WAP_PMG_MSGPRIO_HIGH)
            {
                g_push_high_priority_flag = TRUE;
                mmi_brw_push_read_arrived_service_message();
            }
            else if (curr_push_msg->data.priority == WAP_PMG_MSGPRIO_MEDIUM)
            {
                EntryNewScreen(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND, NULL, mmi_brw_push_entry_new_service_msg, NULL);
                ShowStatusIcon(STATUS_ICON_WAP);
                ShowCategory154Screen(
                    0,
                    0,
                    STR_GLOBAL_READ,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (PU8) GetString(STR_ID_PUSH_SERVICE_MESSAGE_RCVD),
                    0,
                    IMG_GLOBAL_INFO,
                    NULL);

                SetLeftSoftkeyFunction(mmi_brw_push_read_arrived_service_message, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_brw_push_rsk_handling, KEY_EVENT_UP);
            }
            else if (curr_push_msg->data.priority == WAP_PMG_MSGPRIO_LOW)
            {
                mmi_brw_push_free_queue_entry(curr_push_msg);
                //       EntryNewScreen(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND, NULL, NULL, NULL);
                //       DisplayIdleScreen();
                EntryIdleScreen();

            }
            break;

        case WAP_PMG_MSGTYPE_SL:

            if (push_setting_data->sl_setting_flag == PUSH_SL_SETTING_WITHOUT_CONFIRM
                && curr_push_msg->data.priority == WAP_PMG_MSGPRIO_HIGH)
            {
              /*  wap_pmg_msg_count_req_struct *local_data;

                local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

                local_data->transID = PUSH_SL_HIGH_UNREAD_COUNT_ID;
                local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
                local_data->isRead = WAP_PMG_PARAM_NO;
                local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
                local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

				if (g_new_sl_href == NULL)
               {
					g_new_sl_href = (U8*) OslMalloc(WAP_PMG_MAX_MSG_LIST_HREF_CHARS + 1);
				}

				memset((S8*)g_new_sl_href,'\0',WAP_PMG_MAX_MSG_LIST_HREF_CHARS + 1);
				strncpy((S8*)g_new_sl_href,(S8*)g_new_msg_href,WAP_PMG_MAX_MSG_LIST_HREF_CHARS);

				g_push_cntx.sl_msgID = g_new_msg_data->msgID;
                mmi_brw_push_get_pmg_count_req(local_data);*/

				mmi_brw_push_get_msg_from_service_layer(curr_push_msg->data.msgID,SL_HIGH_DISP_ID);
				mmi_brw_push_free_queue_entry(curr_push_msg);
            }
            else   
            {
#ifndef __MMI_UNIFIED_MESSAGE__
                EntryNewScreen(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND, NULL, mmi_brw_push_entry_new_service_msg, NULL);
                ShowStatusIcon(STATUS_ICON_WAP);
                ShowCategory154Screen(
                    0,
                    0,
                    STR_GLOBAL_READ,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (PU8) GetString(STR_ID_PUSH_SERVICE_MESSAGE_RCVD),
                    0,
                    IMG_GLOBAL_INFO,
                    NULL);

                SetLeftSoftkeyFunction(mmi_brw_push_read_arrived_service_message, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_brw_push_rsk_handling, KEY_EVENT_UP);
           
#else
			mmi_um_new_msg_ind_struct um_msg_data;
			um_msg_data.ref_count = 0;
			um_msg_data.msg_len = 0;
			um_msg_data.msg_type = curr_push_msg->data.msgType;
			um_msg_data.msg_index = curr_push_msg->data.msgID;
			um_msg_data.timestamp = 0;

			um_msg_data.msg_box_type = UM_MSG_TYPE_WAP_PUSH;
			mmi_push_um_new_msg_ind(&um_msg_data);
              mmi_brw_push_free_queue_entry(curr_push_msg);
			  mmi_brw_push_free_sl_from_queue();
#endif
            }
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_load_sl_high
 * DESCRIPTION
 *  This API loads the URL ,if the Push msg is of the Execute-High and SL setting is 
	set to without confirm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_load_sl_high(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_load_url((U8*)g_new_sl_href);
	OslMfree(g_new_sl_href);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_rsk_handling
 * DESCRIPTION
 *  It frees the memory occupied for the current push msg for which indication screen is shown at idle one.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_rsk_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_push_free_queue_entry(curr_push_msg);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_read_arrived_service_message
 * DESCRIPTION
 *  It displays the current push message content.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_read_arrived_service_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntx.arrived_service_msg = TRUE;
    mmi_brw_push_get_msg_from_service_layer(curr_push_msg->data.msgID,GENERAL_MSG_ID);
    mmi_brw_push_free_queue_entry(curr_push_msg);
    /* HideStatusIcon(STATUS_ICON_WAP); */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_invalid_msg
 * DESCRIPTION
 *  It send the request for delete the push from service layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_invalid_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_pmg_delete_msg_req_struct delete_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_msg.transID = NEW_MSG_IDLE_SCR_DEL_ID;
    delete_msg.msgID = curr_push_msg->data.msgID;

    mmi_brw_push_free_queue_entry(curr_push_msg);
    mmi_brw_push_send_delete_msg_req(&delete_msg);

    HideStatusIcon(STATUS_ICON_WAP);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_new_push_msg_popup
 * DESCRIPTION
 *  It shows the new message popup for the push when user is not in idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_new_push_msg_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
       ShowStatusIcon(STATUS_ICON_WAP);
    UpdateStatusIcons();
    /* mmi_msg_entry_new_msg_popup(MSG_NEW_PUSH); */
	if (!isInCall())
	{
		TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
		EntryNewScreen(SCR_ID_BRW_WAP_PUSH_POPUP_DUMMY_SCREEN, NULL, NULL, NULL);
    mmi_msg_entry_new_msg_popup(MSG_BRW_NEW_PUSH);
}
#ifdef __MMI_UNIFIED_MESSAGE__
	else
	{
		mmi_um_refresh_msg_ind();
	}
#endif
}

extern U8 mmi_prov_convert_proxy_ipstring_to_array(U8 *parm_element_p, U8 *proxy_ip_p);


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_validate_trust_list
 * DESCRIPTION
 *  This api validates the push msg against the trust list and return the status to calling function.
	
 * PARAMETERS
 *  pushMsg     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_brw_push_validate_trust_list(push_msg_ind_queue_struct *pushMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count, proxy_ip1[4], proxy_ip2[4], i = 0;
    pBOOL match_found = FALSE;
    S8 temp_addr[WAP_PMG_MAX_ADDR_CHARS + 1] = {0};
	U8 *phone_addr_p = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	strncpy((S8*) temp_addr, (S8*) pushMsg->data.addr, WAP_PMG_MAX_ADDR_CHARS);

    if (pushMsg->data.trust_addr_type == WAP_PMG_ADDR_IP)
    {
       // strncpy((S8*) temp_addr, (S8*) pushMsg->data.addr, WAP_PMG_MAX_ADDR_CHARS);
        if (mmi_prov_convert_proxy_ipstring_to_array((U8*) temp_addr, proxy_ip1) == 1)
        {
            return match_found;
        }
    }

    for (count = 0; count < NVRAM_PUSH_TRUST_ADDR_LIST_MAX; count++)
    {
        /* if (strcmp((S8*)pushMsg->data.addr, (S8*)push_setting_data->trust_addr_arr[count].addr) ==0 
           && pushMsg->data.trust_addr_type == push_setting_data->trust_addr_arr[count].addr_type)
           {
           return TRUE;
           } */

        if (pushMsg->data.trust_addr_type == push_setting_data->trust_addr_arr[count].addr_type)
        {
            switch (pushMsg->data.trust_addr_type)
            {
                case WAP_PMG_ADDR_PHONE:

					phone_addr_p = pushMsg->data.addr;

					while (*phone_addr_p == '0' && i <= WAP_PMG_MAX_ADDR_CHARS)
					{
						phone_addr_p++;
						i++;
					}
					if (strcmp((S8*) phone_addr_p, (S8*) push_setting_data->trust_addr_arr[count].addr) == 0)
                    {
                        match_found = TRUE;
                        /* return match_found; */
                    }
                 /*   if (atoi((const char*)push_setting_data->trust_addr_arr[count].addr) == atoi((const char*)pushMsg->data.addr))
                    {
                        match_found = TRUE;*/
                        /* return match_found; }*/
                    
                    break;

                case WAP_PMG_ADDR_IP:

                    /* mmi_prov_convert_proxy_ipstring_to_array(pushMsg->data.addr,proxy_ip1); */
                    memset((S8*) temp_addr, '\0', WAP_PMG_MAX_ADDR_CHARS + 1);
                    strncpy(
                        (S8*) temp_addr,
                        (S8*) push_setting_data->trust_addr_arr[count].addr,
                        WAP_PMG_MAX_ADDR_CHARS);
                    mmi_prov_convert_proxy_ipstring_to_array((U8*) temp_addr, proxy_ip2);

                    for (i = 0; i < 4; i++)
                    {
                        if (proxy_ip1[i] != proxy_ip2[i])
                        {
                            match_found = FALSE;
                            break;
                        }
                        else
                        {
                            match_found = TRUE;
                            /* return match_found; */
                        }
                    }
                    break;

                case WAP_PMG_ADDR_TEXT:

                    if (strcmp((S8*) pushMsg->data.addr, (S8*) push_setting_data->trust_addr_arr[count].addr) == 0)
                    {
                        match_found = TRUE;
                        /* return match_found; */
                    }
                    break;
            }

            if (match_found == TRUE)
            {
                return match_found;
            }
        }
    }
    return match_found;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_replace_msg_ind
 * DESCRIPTION
 *  replace indication sent by service layer.
 * PARAMETERS
 *  local_param     [IN]         
 *  mod_id          [IN]        
 *  ilm             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_replace_msg_ind(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE *ilm_info = (MYQUEUE*) ilm;
    wap_pmg_replace_ind_struct *replace_msg_ind = (wap_pmg_replace_ind_struct*) local_param;
    wap_pmg_delete_msg_req_struct delete_msg;

    U16 pdu_length = 0;
    U8 *href = NULL;
    pBOOL status = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    delete_msg.transID = NEW_MSG_DEL_ID;
    delete_msg.msgID = replace_msg_ind->msgID;
    if (ilm_info->peer_buff_ptr != NULL)
    {
        href = get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length);
    }
    else
    {
        href = NULL;
    }

    if (push_setting_data->push_enable_flag != PUSH_ENABLE_OFF)
    {
        if (g_push_inbox_entry_flag == TRUE)
        {
            status = mmi_brw_push_replace_msg_from_inbox_buffer(replace_msg_ind, href);

            if (status == TRUE)
            {
                if (SCR_ID_PUSH_INBOX == GetActiveScreenId())
                {
                    ShowStatusIcon(STATUS_ICON_WAP);
					UpdateStatusIcons();
                    DisplayPopup(
                        (PU8) GetString(STR_ID_PUSH_INBOX_MODIFIED),
                        IMG_GLOBAL_WARNING,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                    return;
                }
				else
                {
					mmi_brw_push_add_msg_to_queue(replace_msg_ind, href);	
                }
            }
        }
            #ifdef __MMI_UNIFIED_MESSAGE__
        else
        {
            mmi_brw_push_um_handle_replace_ind (replace_msg_ind, href);
			return;
            }
        }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            if (new_phs_msg_queue != NULL)
            {
                status = mmi_brw_push_replace_msg_from_queue(replace_msg_ind);
                if (status == TRUE)
                {
                    if (replace_msg_ind->msgType == WAP_PMG_MSGTYPE_SI &&
                        replace_msg_ind->msgData.priority == WAP_PMG_MSGPRIO_LOW)
                    {
                        ShowStatusIcon(STATUS_ICON_WAP);
						UpdateStatusIcons();
                    }
                    else
            {
                mmi_brw_push_new_push_msg_popup();
            }
                    return;
                }
            else
            {
					mmi_brw_push_handle_replace_ind_as_new_msg(replace_msg_ind, href);
                }
            }
            else
            {
				mmi_brw_push_handle_replace_ind_as_new_msg(replace_msg_ind, href);   
            }
             }
    }

#endif /* __MMI_UNIFIED_MESSAGE__ */
    else
    {
        mmi_brw_push_send_delete_msg_req(&delete_msg);
    }
}
#ifdef __MMI_UNIFIED_MESSAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_um_handle_replace_ind
 * DESCRIPTION
 *  D
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_um_handle_replace_ind(wap_pmg_replace_ind_struct *replace_msg_ind,
											U8 *href)
                {
    mmi_um_new_msg_ind_struct um_msg_data;
	wap_pmg_delete_msg_req_struct delete_msg;

	um_msg_data.ref_count = replace_msg_ind->ref_count;
    um_msg_data.msg_len = replace_msg_ind->msg_len;
    um_msg_data.msg_type = replace_msg_ind->msgData.msgType;
    um_msg_data.msg_index = replace_msg_ind->msgData.msgID;
    um_msg_data.timestamp = replace_msg_ind->msgData.created;
    um_msg_data.msg_box_type = UM_MSG_TYPE_WAP_PUSH;

	delete_msg.transID = NEW_MSG_DEL_ID;
	delete_msg.msgID = replace_msg_ind->msgID;
	
                    switch (replace_msg_ind->msgType)
                    {
		case WAP_PMG_MSGTYPE_SI:

			if ((href && strcmp((S8*) href, "") != 0) ||
						(replace_msg_ind->msgData.text && replace_msg_ind->msgData.text[0] != '\0'))
                            {
				switch (replace_msg_ind->msgData.priority)
                            {
					case WAP_PMG_MSGPRIO_LOW:

							ShowStatusIcon(STATUS_ICON_WAP);
							UpdateStatusIcons();
							mmi_um_refresh_msg_ind();
							return;

					case WAP_PMG_MSGPRIO_MEDIUM:

							ShowStatusIcon(STATUS_ICON_WAP);
							UpdateStatusIcons();
							if (IDLE_SCREEN_ID != GetActiveScreenId())
                                {
                                    mmi_brw_push_new_push_msg_popup();
                                }
							mmi_push_um_new_msg_ind(&um_msg_data);
							return;
					
					case WAP_PMG_MSGPRIO_HIGH:

							mmi_brw_um_sisl_high_handling(replace_msg_ind,href);
							return;
				}
                            }
                            else
                            {
                                mmi_brw_push_send_delete_msg_req(&delete_msg);
                            }

		case WAP_PMG_MSGTYPE_SL :
				
			if (push_setting_data->sl_setting_flag != PUSH_SL_SETTING_NEVER &&
				href && strcmp((S8*) href, "") != 0)
                            {
				switch(push_setting_data->sl_setting_flag)
                                {

					case PUSH_SL_SETTING_WITHOUT_CONFIRM:
						if (replace_msg_ind->msgData.priority == WAP_PMG_MSGPRIO_HIGH)
                            {
							if (href && strcmp((S8*) href, "") != 0)
                                {
								mmi_brw_um_sisl_high_handling(replace_msg_ind,href);
							}
							return;
						}
						
					case PUSH_SL_SETTING_CONFIRM:
						if (href && strcmp((S8*) href, "") != 0)
                                    {
                                        ShowStatusIcon(STATUS_ICON_WAP);
                                        UpdateStatusIcons();
							if (IDLE_SCREEN_ID != GetActiveScreenId())
                                    {
                                        mmi_brw_push_new_push_msg_popup();
                                    }
							mmi_push_um_new_msg_ind(&um_msg_data);
						}
						break;
                                }
                            }
                            else
                            {
                                mmi_brw_push_send_delete_msg_req(&delete_msg);
                            }
                                     }
        }
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_handle_replace_ind_as_new_msg
 * DESCRIPTION
 *  Delete Ind sent by service layer.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_um_sisl_high_handling (wap_pmg_replace_ind_struct *replace_msg_ind,
											U8 *href)
        {
	pBOOL status = FALSE;

            if (new_phs_msg_queue != NULL)
            {
                status = mmi_brw_push_replace_msg_from_queue(replace_msg_ind);
                if (status == TRUE)
                {
                                    ShowStatusIcon(STATUS_ICON_WAP);
			UpdateStatusIcons();
			if (IDLE_SCREEN_ID != GetActiveScreenId())
                    {
                        mmi_brw_push_new_push_msg_popup();
                    }
                                  return;
                }
                else
                {
			goto add_newMsg;
                }
            }
            else
            {
		add_newMsg:

		if (mmi_brw_push_handle_replace_ind_as_new_msg(replace_msg_ind, href)
				== TRUE)
		{
			mmi_um_refresh_msg_ind();
		}
		return;
	}
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_handle_replace_ind_as_new_msg
 * DESCRIPTION
 *  Delete Ind sent by service layer.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_push_handle_replace_ind_as_new_msg (wap_pmg_replace_ind_struct *replace_msg_ind,
											U8 *href)
{
	wap_pmg_delete_msg_req_struct delete_msg;

	delete_msg.transID = NEW_MSG_DEL_ID;
    delete_msg.msgID = replace_msg_ind->msgID;
                   
                switch (replace_msg_ind->msgType)
                {
                    case WAP_PMG_MSGTYPE_SL:

                        if (href && strcmp((S8*) href, "") != 0)
                        {
                            if (mmi_brw_push_new_queue_entry(&replace_msg_ind->msgData) == 0)
                            {
                    if (GetActiveScreenId() == IDLE_SCREEN_ID && 
						replace_msg_ind->msgData.priority == WAP_PMG_MSGPRIO_HIGH &&
						push_setting_data->sl_setting_flag == PUSH_SL_SETTING_WITHOUT_CONFIRM)
					{
						TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
						PlayMessageArrivalTone();
					}
                                mmi_brw_push_handle_new_msg_display();
                            }
                        }
                        else
                        {
                            mmi_brw_push_send_delete_msg_req(&delete_msg);
				return FALSE;
                        }
                        break;

                    case WAP_PMG_MSGTYPE_SI:
                        if ((href && strcmp((S8*) href, "") != 0) ||
                            (replace_msg_ind->msgData.text && replace_msg_ind->msgData.text[0] != '\0'))
                        {
                            if (mmi_brw_push_new_queue_entry(&replace_msg_ind->msgData) == 0)
                            {
                    if (GetActiveScreenId() == IDLE_SCREEN_ID && 
						replace_msg_ind->msgData.priority == WAP_PMG_MSGPRIO_HIGH)
					{
						TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
						PlayMessageArrivalTone();
					}
                                mmi_brw_push_handle_new_msg_display();
                            }
                        }
                        else
                        {
                            mmi_brw_push_send_delete_msg_req(&delete_msg);
				return FALSE;
                        }
                        break;
                }
	return TRUE;
            }
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_add_msg_to_queue
 * DESCRIPTION
 *  Delete Ind sent by service layer.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_add_msg_to_queue (wap_pmg_replace_ind_struct *replace_msg_ind,
							  U8 *href)
{
	wap_pmg_delete_msg_req_struct delete_msg;

	delete_msg.transID = NEW_MSG_DEL_ID;
    delete_msg.msgID = replace_msg_ind->msgID;
	
	switch (replace_msg_ind->msgType)
    {
        case WAP_PMG_MSGTYPE_SL:

            if (href && strcmp((S8*) href, "") != 0)
            {
                if (mmi_brw_push_new_queue_entry(&replace_msg_ind->msgData) == 0)
                {
                    mmi_brw_push_new_push_msg_popup();
        }
    }
            else
            {
                mmi_brw_push_send_delete_msg_req(&delete_msg);
}
            break;

        case WAP_PMG_MSGTYPE_SI:
            if ((href && strcmp((S8*) href, "") != 0) ||
                (replace_msg_ind->msgData.text && replace_msg_ind->msgData.text[0] != '\0'))
            {
                if (mmi_brw_push_new_queue_entry(&replace_msg_ind->msgData) == 0)
                {
                    if (replace_msg_ind->msgData.priority == WAP_PMG_MSGPRIO_LOW)
                    {
                        ShowStatusIcon(STATUS_ICON_WAP);
                        UpdateStatusIcons();
                    }
                    else
                    {
                        mmi_brw_push_new_push_msg_popup();
                    }
                    /* mmi_brw_push_new_push_msg_popup(); */
                }
            }
            else
            {
                mmi_brw_push_send_delete_msg_req(&delete_msg);
            }
            break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_msg_delete_ind
 * DESCRIPTION
 *  Delete Ind sent by service layer.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_msg_delete_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* MYQUEUE *data; */
    wap_pmg_delete_ind_struct *delete_msg_ind = (wap_pmg_delete_ind_struct*) msg;
    wap_pmg_msg_count_req_struct *local_data = NULL;

    pBOOL status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* data = (MYQUEUE *)msg; */

    /* delete_msg_ind = (wap_pmg_delete_ind_struct *)data->oslDataPtr; */

    if (push_setting_data->push_enable_flag != PUSH_ENABLE_OFF)
    {
        status = mmi_brw_push_delete_msg_from_inbox_buffer(delete_msg_ind->msgID);
        if (g_push_inbox_entry_flag == TRUE)
        {
            /* status = mmi_brw_push_delete_msg_from_inbox_buffer(delete_msg_ind->msgID); */

            if (status == TRUE)
            {
                if (SCR_ID_PUSH_INBOX == GetActiveScreenId())
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_PUSH_INBOX_MODIFIED),
                        IMG_GLOBAL_WARNING,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        ERROR_TONE);
                }
            }
        }
 /*   #ifdef __MMI_UNIFIED_MESSAGE__
    }
    #else *//* __MMI_UNIFIED_MESSAGE__ */ 
        else
        {
            if (new_phs_msg_queue != NULL)
            {
                status = mmi_brw_push_delete_msg_from_queue(delete_msg_ind->msgID);
            }
#ifdef __MMI_UNIFIED_MESSAGE__
			mmi_um_refresh_msg_ind();
#endif
        }
    }

    //#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

    local_data->transID = PUSH_DELIND_UNREAD_COUNT_ID;
    local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->isRead = WAP_PMG_PARAM_NO;
    local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

    mmi_brw_push_get_pmg_count_req(local_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_send_delete_msg_req
 * DESCRIPTION
 *  Delete msg request to service layer.
 * PARAMETERS
 *  delete_msg      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_send_delete_msg_req(wap_pmg_delete_msg_req_struct *delete_msg)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_delete_msg_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_DELETE_MSG_REQ;

    local_data = (wap_pmg_delete_msg_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_delete_msg_req_struct));

    local_data->transID = delete_msg->transID;
    local_data->msgID = delete_msg->msgID;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    /* mmi_brw_push_send_delete_msg_rsp(local_data->transID); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_msg_rsp
 * DESCRIPTION
 *  Delete message response from service layer.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* MYQUEUE *data; */
    wap_pmg_delete_msg_cnf_struct *delete_msg_rsp = (wap_pmg_delete_msg_cnf_struct*) msg;
	wap_pmg_msg_count_req_struct *local_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* data = (MYQUEUE *)msg; */

    /* delete_msg_rsp = (wap_pmg_delete_msg_cnf_struct *)data->oslDataPtr; */

    if (delete_msg_rsp->status == WAP_PMG_STATUS_OK)
    {
        switch (delete_msg_rsp->transID)
        {
            case NEW_MSG_DEL_ID:
                break;

            case NEW_MSG_IDLE_SCR_DEL_ID:

                if (IDLE_SCREEN_ID != GetActiveScreenId())
                {
                    DisplayIdleScreen();
                }
                break;

            case NEW_MSG_OPTION_DEL_ID:

                local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

				local_data->transID = NEW_MSG_OPTION_DEL_ID;
				local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
				local_data->isRead = WAP_PMG_PARAM_NO;
				local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
				local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

				mmi_brw_push_get_pmg_count_req(local_data);
                break;

            case INBOX_MSG_DEL_ID:

                DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
                DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
                DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
				DeleteScreenIfPresent(SCR_ID_UM_MESSAGE_OPTIONS);
				DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);
                break;

			case UM_MSG_LIST_DEL_ID:

				DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
                DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
                DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
             
                DeleteScreenIfPresent(SCR_ID_UM_MESSAGE_OPTIONS);
				DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);

				local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

				local_data->transID = UM_LIST_MSG_COUNT_ID;
				local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
				local_data->isRead = WAP_PMG_PARAM_NO;
				local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
				local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

				mmi_brw_push_get_pmg_count_req(local_data);
                
                break;

            case INVALID_MSG_INBOX_DEL_ID:

                curr_push_msg = mmi_brw_push_pop_entry();
                if (curr_push_msg != NULL)
                {
                    if (mmi_brw_push_validate_trust_list(curr_push_msg) == FALSE)
                    {
                        wap_pmg_delete_msg_req_struct delete_msg;

                        delete_msg.transID = INVALID_MSG_INBOX_DEL_ID;
                        delete_msg.msgID = curr_push_msg->data.msgID;

                        mmi_brw_push_free_queue_entry(curr_push_msg);
                        mmi_brw_push_send_delete_msg_req(&delete_msg);
                    }
                }
                else
                {
                    GoBackHistory();
                }
                break;
        }
    }
    else
    {

        DisplayPopup(
            (PU8) GetString(STR_ID_PUSH_MSG_NOT_AVAILABLE),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
		DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);

        if (delete_msg_rsp->transID == NEW_MSG_OPTION_DEL_ID)
        {
            DisplayIdleScreen();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_all_msg_req
 * DESCRIPTION
 *  Delete All request to service layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_all_msg_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_delete_all_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_DELETE_ALL_REQ;

    local_data = (wap_pmg_delete_all_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_delete_all_req_struct));

    local_data->transID = 0;
    local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_all_msg_rsp
 * DESCRIPTION
 * Delete All response from service layer. 
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_all_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE *data; */
    wap_pmg_delete_all_cnf_struct *delete_all_data = (wap_pmg_delete_all_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* data = (MYQUEUE *)msg; */

    /* delete_all_data = (wap_pmg_delete_all_cnf_struct *)data->oslDataPtr; */

    if (delete_all_data->status == WAP_PMG_STATUS_OK)
    {
        DisplayPopup(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);

        DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
        DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        DeleteScreenIfPresent(SCR_ID_UM_MESSAGE_OPTIONS);
    #endif 
    //    GoBackHistory();
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_storage_full_ind
 * DESCRIPTION
 *  PUSH STORAGE FULL POPUP DISPLAY.
 * PARAMETERS
 *  msgID       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_storage_full_ind(void *msg)
{
	DisplayPopup(
    (PU8) GetString(STR_ID_PUSH_STORAGE_FULL),
    IMG_GLOBAL_WARNING,
    1,
    UI_POPUP_NOTIFYDURATION_TIME,
    WARNING_TONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_get_msg_from_service_layer
 * DESCRIPTION
 *  get push message content request from service layer by sending the msgID .
 * PARAMETERS
 *  msgID       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_get_msg_from_service_layer(S16 msgID, push_transID_enum trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_get_msg_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_GET_MSG_REQ;

    local_data = (wap_pmg_get_msg_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_get_msg_req_struct));

    local_data->transID = trans_id;
    local_data->msgID = msgID;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    /* mmi_brw_send_msg_rsp(msgID); //temporary call for UT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_get_msg_rsp
 * DESCRIPTION
 *  Received push msg content response from service layer.
 * PARAMETERS
 *  local_param     [IN]         
 *  mod_id          [IN]        
 *  ilm             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_get_msg_rsp(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE *ilm_info = (MYQUEUE*) ilm;
    U16 pdu_length = 0;

    wap_pmg_get_msg_cnf_struct *local_data = NULL;
    U8 *local_href = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show message contents */

    //      g_push_msg_rsp_data = NULL;
    //      g_push_msg_rsp_href=NULL;

    /* data = (MYQUEUE *)msg; */

    local_data = (wap_pmg_get_msg_cnf_struct*) local_param;
    if (g_push_msg_rsp_data == NULL)
    {
        g_push_msg_rsp_data = (wap_pmg_get_msg_cnf_struct*) OslMalloc(sizeof(wap_pmg_get_msg_cnf_struct));
    }

    g_push_msg_rsp_data->ref_count = local_data->ref_count;
    g_push_msg_rsp_data->msg_len = local_data->msg_len;
    g_push_msg_rsp_data->transID = local_data->transID;
    g_push_msg_rsp_data->status = local_data->status;
    g_push_msg_rsp_data->msgData = local_data->msgData;

    if (ilm_info->peer_buff_ptr != NULL)
    {
        local_href = get_pdu_ptr(ilm_info->peer_buff_ptr, &pdu_length);

        if (g_push_msg_rsp_href == NULL)
        {
            g_push_msg_rsp_href = (S8*) OslMalloc(WAP_PMG_MAX_MSG_HREF_CHARS + 1);
            if (g_push_msg_rsp_href == NULL)
            {
                MMI_ASSERT(0);
            }
        }
        strncpy((S8*) g_push_msg_rsp_href, (S8*) local_href, WAP_PMG_MAX_MSG_HREF_CHARS);
    }
    else
    {
        if (g_push_msg_rsp_href != NULL)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[PushInboxSrc.c] mmi_brw_push_get_msg_rsp ilm_info->peer_buff_ptr = NULL \n");
            OslMfree(g_push_msg_rsp_href);
            g_push_msg_rsp_href = NULL;
        }
    }

    mmi_brw_push_handle_get_msg_rsp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_handle_get_msg_rsp
 * DESCRIPTION
 *  According to push msg content response sent by serivce layer,it process the staus icons,read status etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_handle_get_msg_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_pmg_update_msg_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_msg_rsp_data->status == WAP_PMG_STATUS_OK)
    {
		switch(g_push_msg_rsp_data->transID)
		{
			case GENERAL_MSG_ID:
				
        if (g_push_msg_rsp_data->msgData.read == 0)
        {
            local_data = (wap_pmg_update_msg_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_update_msg_req_struct));

			local_data->transID = PUSH_MSG_UPDATE_ID;
			local_data->msgID = g_push_msg_rsp_data->msgData.msgID;
			local_data->read = WAP_PMG_PARAM_YES;

			mmi_brw_push_update_msg_req(local_data);
        }
        else
        {
            mmi_brw_push_pre_entry_display_service_message();
            g_push_high_priority_flag = FALSE;
        }
				break;
			case SL_HIGH_DISP_ID:

				if (g_push_msg_rsp_data->msgData.read == 0)
				{
					local_data = (wap_pmg_update_msg_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_update_msg_req_struct));

					local_data->transID = SL_HIGH_UPDATE_ID;
					local_data->msgID = g_push_msg_rsp_data->msgData.msgID;
					local_data->read = WAP_PMG_PARAM_YES;

					mmi_brw_push_update_msg_req(local_data);
				}
				break;
		}
    }
    else
    {
        if (g_push_high_priority_flag == FALSE)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PUSH_MSG_NOT_AVAILABLE),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else
        {
            g_push_high_priority_flag = FALSE;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_update_msg_req
 * DESCRIPTION
 *  request for updation of read flag to service layer for the selected message or message being displayed directly on
	idle screen depending on its priority.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_update_msg_req(wap_pmg_update_msg_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
   // wap_pmg_update_msg_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_UPDATE_MSG_REQ;

  /*  local_data = (wap_pmg_update_msg_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_update_msg_req_struct));

    local_data->transID = 0;
    local_data->msgID = g_push_msg_rsp_data->msgData.msgID;
    local_data->read = WAP_PMG_PARAM_YES;*/

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    /* mmi_brw_push_send_update_msg_response(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_update_msg_rsp
 * DESCRIPTION
 *  Updation of read flag sent by service layer.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_update_msg_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE *data; */
    wap_pmg_update_msg_cnf_struct *msg_status = (wap_pmg_update_msg_cnf_struct*) msg;
	wap_pmg_msg_count_req_struct *local_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* data = (MYQUEUE *)msg; */

    /* msg_status = (wap_pmg_update_msg_cnf_struct *)data->oslDataPtr; */
	switch (msg_status->transID)
	{
		case PUSH_MSG_UPDATE_ID:

    if (msg_status->status == WAP_PMG_STATUS_OK)
    {
        if (SCR_ID_PUSH_INBOX == GetActiveScreenId())
        {
            g_push_inbox_msg_buffer[g_push_cntx.push_msg_index]->data.read = 1;
        }
        mmi_brw_push_pre_entry_display_service_message();
        g_push_high_priority_flag = FALSE;
    }
    else
    {
        if (g_push_high_priority_flag == FALSE)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PUSH_MSG_NOT_AVAILABLE),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
        }
        else
        {
            g_push_high_priority_flag = FALSE;
        }
    }
			break;

		case SL_HIGH_UPDATE_ID:

            local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

            local_data->transID = PUSH_SL_HIGH_UNREAD_COUNT_ID;
            local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
            local_data->isRead = WAP_PMG_PARAM_NO;
            local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
            local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

			mmi_brw_push_get_pmg_count_req(local_data);
			break;
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_config_msg_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_config_msg_cnf(void *msg)
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
 *  mmi_brw_push_pre_entry_display_service_message
 * DESCRIPTION
 *  Pre entry function to display push content.It request the number of unread message from 
	the serivce layer to update status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_pre_entry_display_service_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // #ifndef __MMI_UNIFIED_MESSAGE__
    wap_pmg_msg_count_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

    local_data->transID = PUSH_MSG_DISPLAY_UNREAD_COUNT_ID;
    local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->isRead = WAP_PMG_PARAM_NO;
    local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

    mmi_brw_push_get_pmg_count_req(local_data);
    //#else 
    //      mmi_brw_push_entry_display_service_message();
    //#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_display_service_message
 * DESCRIPTION
 *  This API displays the push message content.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_display_service_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8 *message_buffer = NULL; */

    EntryNewScreen(
        SCR_ID_BRW_READ_SERVICE_MESSAGE,
        mmi_brw_push_exit_display_service_message,
        mmi_brw_push_entry_display_service_message,
        NULL);

    /* HideStatusIcon(STATUS_ICON_WAP); */
    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_READ_SERVICE_MESSAGE);

    g_message_buffer = (U8*) mmi_brw_push_create_display_format();

    buffer_size = mmi_ucs2strlen((PS8) g_message_buffer);

    ShowCategory74Screen(
        STR_ID_PUSH_MESSAGE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_message_buffer,
        buffer_size,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_brw_push_entry_display_service_message_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(display_service_msg_rsk_handling, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_push_end_key_handling, KEY_END, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_exit_display_service_message
 * DESCRIPTION
 *  On the exit of content display screen ,it frees the message buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_exit_display_service_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_message_buffer)
    {
        OslMfree(g_message_buffer);
        g_message_buffer = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  display_service_msg_rsk_handling
 * DESCRIPTION
 * 	If Push message is being read from Idle screen,then pressing of RSK will display idle screen.
	It will free the memory occupied by g_push_msg_rsp_href & g_push_msg_rsp_data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void display_service_msg_rsk_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (g_idle_callback == TRUE)
	{
		g_idle_callback = FALSE;
	}

    if (g_push_msg_rsp_href != NULL)
    {
        OslMfree(g_push_msg_rsp_href);
        g_push_msg_rsp_href = NULL;
    }
    if (g_push_msg_rsp_data != NULL)
    {
        OslMfree(g_push_msg_rsp_data);
        g_push_msg_rsp_data = NULL;
    }
    if (g_push_cntx.arrived_service_msg == TRUE)
    {
        g_push_cntx.arrived_service_msg = FALSE;
        DisplayIdleScreen();
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_display_service_message_option
 * DESCRIPTION
 *  Display option for selected push msg.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_display_service_message_option(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 uc_list_of_items[7];
    U8 *gui_buffer;
    S32 num_of_items;

    U16 menuID = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS,
        NULL,
        mmi_brw_push_entry_display_service_message_option,
        NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);

#ifndef __MMI_UNIFIED_MESSAGE__
    if (g_push_cntx.arrived_service_msg == TRUE)
    {
        if (g_push_msg_rsp_href == NULL || strcmp(g_push_msg_rsp_href, "") == 0)
        {
            menuID = MENU_ID_PUSH_MESSAGE_OPTION_3;
        }
        else
        {
            menuID = MENU_ID_PUSH_MESSAGE_OPTION_1;
        }
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (g_push_inbox_entry_flag == FALSE)
    {
        if (g_push_msg_rsp_href == NULL || strcmp(g_push_msg_rsp_href, "") == 0)
        {
            menuID = MENU_ID_PUSH_MESSAGE_OPTION_3;
        }
        else
        {
            if (!isInCall())
			{
            menuID = MENU_ID_PUSH_MESSAGE_OPTION_1;
        }
			else
			{
				menuID = MENU_ID_PUSH_MESSAGE_OPTION_ISINCALL_1;
			}
        }
    }
#else /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */ 
    if (g_push_inbox_entry_flag == FALSE)
    {
        if (g_push_msg_rsp_href == NULL || strcmp(g_push_msg_rsp_href, "") == 0)
        {
            menuID = MENU_ID_PUSH_MESSAGE_OPTION_4;
        }
        else
        {
            if (!isInCall())
			{
            menuID = MENU_ID_PUSH_MESSAGE_OPTION_2;
        }
			else
			{
				menuID = MENU_ID_PUSH_MESSAGE_OPTION_ISINCALL_2;
			}
        }
    }
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */ 
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    /* else
       {
       #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
       menuID = MENU_ID_PUSH_MESSAGE_OPTION_1;
       #else 
       menuID = MENU_ID_PUSH_MESSAGE_OPTION_2;
       #endif
       } */
    if (g_push_inbox_entry_flag == TRUE)
    {
        if (g_push_msg_rsp_href == NULL || strcmp(g_push_msg_rsp_href, "") == 0)
        {
            menuID = MENU_ID_PUSH_MESSAGE_OPTION_4;
        }
        else
        {
            if (!isInCall())
			{
            menuID = MENU_ID_PUSH_MESSAGE_OPTION_2;
        }
			else
			{
				menuID = MENU_ID_PUSH_MESSAGE_OPTION_ISINCALL_2;
			}
        }
    }
    /* if (g_push_msg_rsp_href == NULL || strcmp(g_push_msg_rsp_href,"") ==0)
       {
       // menuID = MENU_ID_PUSH_MESSAGE_OPTION_1;
       } */

    num_of_items = GetNumOfChild(menuID);
    GetSequenceStringIds(menuID, uc_list_of_items);
    SetParentHandler(menuID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        uc_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(dispaly_service_msg_option_rsk_handling, KEY_EVENT_UP);
    SetKeyHandler(dispaly_service_msg_option_rsk_handling, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_brw_push_end_key_handling, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  dispaly_service_msg_option_rsk_handling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dispaly_service_msg_option_rsk_handling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (g_push_cntx.arrived_service_msg == TRUE)
       {
       g_push_cntx.arrived_service_msg = FALSE;
       DisplayIdleScreen();
       }
       else
       { */
    GoBackHistory();
    /* } */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_create_display_format
 * DESCRIPTION
 *  It creates the display format for the push message content.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
PS8 mmi_brw_push_create_display_format(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 message_length = 0;
    S16 message_href_length = 0;
    S16 meassage_body_length = 0;
	S16 from_addr_length = 0;
//	S16 smsc_addr_length = 0;


    PS8 ucs2_message_buffer = NULL;
    S8 ucs2_time_string[SI_DATE_N_TIME_STRING_LENGTH] = {0};

    PS8 ucs2_msg = NULL, ucs2_href = NULL;
    U32 local_time;

    MYTIME time = {0};
    //      applib_time_struct time= {0};
    //  SI_TIME sisl_received_time = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*** Validation address and Sender's address will get displayed for both SI & SL push ****/

	/*if (g_push_msg_rsp_data->msgData.smsc.addr != NULL && g_push_msg_rsp_data->msgData.smsc.addr[0] != '\0')
	{
		smsc_addr_length = strlen((const S8*)g_push_msg_rsp_data->msgData.smsc.addr);
		smsc_addr_length = (smsc_addr_length + 1) * ENCODING_LENGTH;
		message_length += smsc_addr_length + mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_VALIDATION_ADDR));
	}*/
	if (g_push_msg_rsp_data->msgData.from.addr != NULL && g_push_msg_rsp_data->msgData.from.addr[0] != '\0')
	{
		from_addr_length = strlen((const S8*)g_push_msg_rsp_data->msgData.from.addr);
		from_addr_length = (from_addr_length + 1) * ENCODING_LENGTH;
		message_length += from_addr_length + mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_SENDER_ADDR));
	}
    if (g_push_msg_rsp_data->msgData.msgType == WAP_PMG_MSGTYPE_SI)
    {
        if (g_push_msg_rsp_data->msgData.text != NULL)
        {
            if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_ASCII)
            {
                meassage_body_length = strlen((const S8*)g_push_msg_rsp_data->msgData.text);
                meassage_body_length = (meassage_body_length + 1) * ENCODING_LENGTH;
            }
            else
            {
                meassage_body_length = mmi_ucs2strlen((const S8*)g_push_msg_rsp_data->msgData.text);
            }
        }

        if (g_push_msg_rsp_href != NULL)
        {
            message_href_length = strlen((const S8*)g_push_msg_rsp_href);
            message_href_length = (message_href_length + 1) * ENCODING_LENGTH;
        }

        /* Calculate the length of the message */
        message_length += message_href_length + meassage_body_length +
            SI_DATE_N_TIME_STRING_LENGTH +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_CREATED_TIME)) +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_EXPIRY_TIME)) +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_PRIORITY)) +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_PUSH_MESSAGE)) +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_PUSH_URL));

		
        ucs2_message_buffer = (PS8) OslMalloc((message_length + 1) * ENCODING_LENGTH);
        /* todo : check null value */
		  if (0 != from_addr_length)
			{
				mmi_ucs2cpy((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_SENDER_ADDR));
				mmi_ucs2cat(ucs2_message_buffer, "\n");

				ucs2_msg = (PS8) OslMalloc(from_addr_length);
				mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_push_msg_rsp_data->msgData.from.addr);
				mmi_ucs2cat((S8*) ucs2_message_buffer, ucs2_msg);
				mmi_ucs2cat(ucs2_message_buffer, "\n");
				mmi_ucs2cat(ucs2_message_buffer, "\n");
				OslMfree(ucs2_msg);
			}
        mmi_ucs2cat(ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_CREATED_TIME));
        mmi_ucs2cat(ucs2_message_buffer, "\n");

       // local_time = mmi_brw_push_get_utc_local_time(g_push_msg_rsp_data->msgData.created);
		local_time = g_push_msg_rsp_data->msgData.created;
        /* applib_dt_utc_sec_2_mytime(local_time, &time, MMI_TRUE); */
        mmi_dt_utc_sec_2_mytime((U32) local_time, &time, MMI_TRUE);

        mmi_brw_push_create_ucs2_time_format_string(&time, ucs2_time_string);

        mmi_ucs2cat(ucs2_message_buffer, ucs2_time_string);
        mmi_ucs2cat(ucs2_message_buffer, "\n");
		  mmi_ucs2cat(ucs2_message_buffer, "\n");

        if (g_push_msg_rsp_data->msgData.expired != 0)
        {
            mmi_ucs2cat(ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_EXPIRY_TIME));
            mmi_ucs2cat(ucs2_message_buffer, "\n");

           // local_time = mmi_brw_push_get_utc_local_time(g_push_msg_rsp_data->msgData.expired);
			local_time = g_push_msg_rsp_data->msgData.expired;
            mmi_dt_utc_sec_2_mytime((U32) local_time, &time, MMI_TRUE);
            mmi_brw_push_create_ucs2_time_format_string(&time, ucs2_time_string);

            mmi_ucs2cat(ucs2_message_buffer, ucs2_time_string);
            mmi_ucs2cat(ucs2_message_buffer, "\n");
				mmi_ucs2cat(ucs2_message_buffer, "\n");
        }

        mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_PRIORITY));
        mmi_ucs2cat(ucs2_message_buffer, "\n");

        if (g_push_msg_rsp_data->msgData.priority == WAP_PMG_MSGPRIO_LOW)
        {
            mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_PRIORITY_LOW));
             }
        else if (g_push_msg_rsp_data->msgData.priority == WAP_PMG_MSGPRIO_MEDIUM)
        {
            mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_PRIORITY_MEDIUM));
        }
        else if (g_push_msg_rsp_data->msgData.priority == WAP_PMG_MSGPRIO_HIGH)
        {
            mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_PRIORITY_HIGH));
                 }
		  mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");
		  mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");

        if (0 != message_href_length)
        {
            mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_PUSH_URL));
            mmi_ucs2cat(ucs2_message_buffer, "\n");

            ucs2_href = (PS8) OslMalloc(message_href_length);
            if (ucs2_href != NULL)
            {
                mmi_asc_to_ucs2((S8*) ucs2_href, (S8*) g_push_msg_rsp_href);
            }
            mmi_ucs2cat((S8*) ucs2_message_buffer, ucs2_href);
            mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");
				mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");
            OslMfree(ucs2_href);
        }

        if (0 != meassage_body_length)
        {
            mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_PUSH_MESSAGE));
            mmi_ucs2cat(ucs2_message_buffer, "\n");
            if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_ASCII)
            {
                ucs2_msg = (PS8) OslMalloc(meassage_body_length);
                if (ucs2_msg != NULL)
                {
                    mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_push_msg_rsp_data->msgData.text);
                }
                mmi_ucs2cat((S8*) ucs2_message_buffer, ucs2_msg);
                OslMfree(ucs2_msg);

            }
            else if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_UCS2)
            {
                mmi_ucs2cat((S8*) ucs2_message_buffer, (S8*) g_push_msg_rsp_data->msgData.text);
            }
			mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");
			mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");
        }
    }

    else if (g_push_msg_rsp_data->msgData.msgType == WAP_PMG_MSGTYPE_SL)
    {
        if (g_push_msg_rsp_href != NULL)
        {
            message_href_length = strlen((const S8*)g_push_msg_rsp_href);
            message_href_length = (message_href_length + 1) * ENCODING_LENGTH;
        }

        message_length += message_href_length +
            SI_DATE_N_TIME_STRING_LENGTH +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_CREATED_TIME)) +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_BRW_PUSH_PRIORITY)) +
            mmi_ucs2strlen((const S8*)GetString(STR_ID_PUSH_URL));

        ucs2_message_buffer = (PS8) OslMalloc((message_length + 1) * ENCODING_LENGTH);

		  if (0 != from_addr_length)
			{
				mmi_ucs2cpy((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_SENDER_ADDR));
				mmi_ucs2cat(ucs2_message_buffer, "\n");

				ucs2_msg = (PS8) OslMalloc(from_addr_length);
				mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_push_msg_rsp_data->msgData.from.addr);
				mmi_ucs2cat((S8*) ucs2_message_buffer, ucs2_msg);
				mmi_ucs2cat(ucs2_message_buffer, "\n");
				mmi_ucs2cat(ucs2_message_buffer, "\n");
				OslMfree(ucs2_msg);
			}

        mmi_ucs2cat(ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_CREATED_TIME));
        mmi_ucs2cat(ucs2_message_buffer, "\n");
     //   local_time = mmi_brw_push_get_utc_local_time(g_push_msg_rsp_data->msgData.created);
		local_time = g_push_msg_rsp_data->msgData.created;
        mmi_dt_utc_sec_2_mytime((U32) local_time, &time, MMI_TRUE);
        mmi_brw_push_create_ucs2_time_format_string(&time, ucs2_time_string);

        mmi_ucs2cat(ucs2_message_buffer, ucs2_time_string);
        mmi_ucs2cat(ucs2_message_buffer, "\n");
		  mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");

        mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_PRIORITY));
        mmi_ucs2cat(ucs2_message_buffer, "\n");

        if (g_push_msg_rsp_data->msgData.priority == WAP_PMG_MSGPRIO_LOW)
        {
            mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_PRIORITY_LOW));
                   }
        else if (g_push_msg_rsp_data->msgData.priority == WAP_PMG_MSGPRIO_HIGH)
        {
            mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_PRIORITY_HIGH));
                  }
		  mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");
		  mmi_ucs2cat((S8*) ucs2_message_buffer, "\n");

        mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_PUSH_URL));
        mmi_ucs2cat(ucs2_message_buffer, "\n");

        ucs2_href = (PS8) OslMalloc(message_href_length);
        if (ucs2_href != NULL)
        {
            mmi_asc_to_ucs2((S8*) ucs2_href, (S8*) g_push_msg_rsp_href);
        mmi_ucs2cat((S8*) ucs2_message_buffer, ucs2_href);
			
		  mmi_ucs2cat(ucs2_message_buffer, "\n");
			mmi_ucs2cat(ucs2_message_buffer, "\n");
        OslMfree(ucs2_href);
    }
		else
		{
			MMI_ASSERT(0);
		}
    }

    else
    {
        /* error */
    }

/*	if (0 != smsc_addr_length)
	{
		mmi_ucs2cat((S8*) ucs2_message_buffer, GetString(STR_ID_BRW_PUSH_VALIDATION_ADDR));
		mmi_ucs2cat(ucs2_message_buffer, "\n");

		ucs2_msg = (PS8) OslMalloc(smsc_addr_length);
		mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_push_msg_rsp_data->msgData.smsc.addr);
		mmi_ucs2cat((S8*) ucs2_message_buffer, ucs2_msg);
        OslMfree(ucs2_msg);
	}*/

    return ucs2_message_buffer;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_get_utc_local_time
 * DESCRIPTION
 *  This API retirn the current local time in UTC format.
 * PARAMETERS
 *  timeSecs        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_brw_push_get_utc_local_time(U32 timeSecs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FLOAT tz;
    U32 tzdiff = 0, local_time = 0;

    /* MYTIME t; */
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tz = mmi_dt_get_tz();
    if (tz < 0)
    {
        time = applib_conv_tz_to_mytime(tz * (-1));
    }
    else
    {
        time = applib_conv_tz_to_mytime(tz);
    }
    tzdiff = time.nHour * 3600 + time.nMin * 60 + time.nSec;

    if (tz > 0)
    {
        local_time = timeSecs + tzdiff;
    }
    else
    {
        local_time = timeSecs - tzdiff;
    }

    return local_time;
    /* mmi_dt_utc_sec_2_mytime(local_time, &result, MMI_TRUE); */
    /* applib_dt_utc_sec_2_mytime(local_time, &result, MMI_TRUE); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_create_ucs2_time_format_string
 * DESCRIPTION
 *  This API converts the time into UCS2 format.
 * PARAMETERS
 *  time                    [IN]         
 *  ucs2_time_string        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_create_ucs2_time_format_string(MYTIME *time, PS8 ucs2_time_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type temp_time_buffer[20] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    date_string(time, temp_time_buffer, DT_IDLE_SCREEN);

    mmi_ucs2ncpy((S8*) ucs2_time_string, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));

    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) " ", 1);

    time_string(time, temp_time_buffer, DT_IDLE_SCREEN);

    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));

    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) "\0", 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_pre_entry_inbox_validation
 * DESCRIPTION
 * This API validates the push message resides in the queue before entering to push inbox. 
	Note: Queue is a list of message to be displayed at idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_pre_entry_inbox_validation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #ifndef __MMI_UNIFIED_MESSAGE__
    if (push_setting_data->trust_setting_flag == PUSH_TRUST_SETTING_ALWAYS_ASK && new_phs_msg_queue != NULL)
    {
        while ((curr_push_msg = mmi_brw_push_pop_entry()) != NULL)
        {
            if (mmi_brw_push_validate_trust_list(curr_push_msg) == FALSE)
            {
                g_push_entry_validation_flag = TRUE;
                mmi_brw_push_entry_invalid_service_msg_on_pushinbox();
                return;
            }
        }
        goto inbox;
    }
    /* else
       //#endif
       { */
  inbox:
    g_push_cntx.push_msg_index = 0;
    mmi_brw_push_pre_entry_inbox();
    return;
    /* } */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_pre_entry_inbox
 * DESCRIPTION
 *  Pre entry function to push inbox.It request for the number of message from service layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_pre_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_pmg_msg_count_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_push_entry_processing_generic();
    DeleteScreenIfPresent(SCR_ID_PUSH_INBOX);

    /* mmi_brw_push_free_msg_buffer(); */
    DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
    DeleteScreenIfPresent(SCR_ID_BRW_INVALID_PUSH_MESSAGE);

#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    DeleteScreenIfPresent(SCR_ID_UM_MESSAGE_OPTIONS);
#endif 

    local_data = (wap_pmg_msg_count_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));

    local_data->transID = PUSH_INBOX_MSG_COUNT_ID;
    local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->isRead = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;

    mmi_brw_push_get_pmg_count_req(local_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_get_pmg_count_req
 * DESCRIPTION
 *  Push msg count request to service layer.
 * PARAMETERS
 *  local_data      [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_get_pmg_count_req(wap_pmg_msg_count_req_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /* wap_pmg_msg_count_req_struct *local_data; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_MSG_COUNT_REQ;

    /* local_data = (wap_pmg_msg_count_req_struct*)
       OslConstructDataPtr(sizeof(wap_pmg_msg_count_req_struct));
       
       local_data->transID = data->transID;  
       local_data->msgType = data->msgType;
       local_data->isRead = data->isRead;
       local_data->isExpired = data->isExpired;
       local_data->hasInfo = data->hasInfo; */

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    /* mmi_brw_push_msg_send_count_response(); // */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_msg_count_rsp
 * DESCRIPTION
 *  Push msg count response from service layer.
 * PARAMETERS 
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_msg_count_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* MYQUEUE *data; */
    wap_pmg_msg_count_cnf_struct *msg_rsp = (wap_pmg_msg_count_cnf_struct*) msg;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (msg_rsp->transID)
    {
        case PUSH_INIT_UNREAD_COUNT_ID:

            mmi_brw_push_handle_status_icons(msg_rsp->msgCount);
            if (g_psh_boot_up_flag == TRUE)
            {
                g_psh_boot_up_flag = FALSE;
                mmi_brw_push_send_config_ind();
            }
            break;

		case PUSH_DELIND_UNREAD_COUNT_ID:

			mmi_brw_push_handle_status_icons(msg_rsp->msgCount);
			if (IDLE_SCREEN_ID == GetActiveScreenId())
			{
				EntryIdleScreen();
			}
            break;

        case PUSH_SL_HIGH_UNREAD_COUNT_ID:

            mmi_brw_push_handle_status_icons(msg_rsp->msgCount);
			LoadPushUrl();
            break;

        case PUSH_MSG_DISPLAY_UNREAD_COUNT_ID:

            mmi_brw_push_handle_status_icons(msg_rsp->msgCount);
            mmi_brw_push_entry_display_service_message();
            break;

        case PUSH_INBOX_MSG_COUNT_ID:

            g_push_cntx.push_msg_count = msg_rsp->msgCount;

            if (g_push_cntx.push_msg_count == 0)
            {
                DisplayPopup(
                    (U8*) GetString(STR_GLOBAL_EMPTY),
                    IMG_GLOBAL_EMPTY,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) EMPTY_LIST_TONE);

                DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);
                /* DisplayIdleScreen(); */
                return;

            }
            else
            {

                if (g_push_cntx.push_msg_count < MAX_PUSH_MSG)
                {
                    /* g_push_cntx.start_index = 0; */
                    mmi_brw_push_msg_list_req(0, g_push_cntx.push_msg_count);
                }
                else
                {
                    g_push_cntx.push_msg_count = MAX_PUSH_MSG;
                    mmi_brw_push_msg_list_req(0, MAX_PUSH_MSG);
                }
            }
            break;

        case PUSH_NEW_MSG_PROCESS_ID:
            g_push_cntx.push_msg_count = msg_rsp->msgCount;
            if (g_push_cntx.push_msg_count != 0)
            {
                g_push_cntx.push_msg_count--;
            }
            mmi_brw_push_process_new_msg();
            break;

		case UM_LIST_MSG_COUNT_ID:
			mmi_brw_push_handle_status_icons(msg_rsp->msgCount);
			break;

		case NEW_MSG_OPTION_DEL_ID:
			mmi_brw_push_handle_status_icons(msg_rsp->msgCount);

			DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);

            DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
            DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
            DeleteScreenIfPresent(SCR_ID_BRW_INVALID_PUSH_MESSAGE);
            DeleteScreenIfPresent(SCR_ID_BRW_NEW_PUSH_MESSAGE_IND);
			DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);
			break;

    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_handle_status_icons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  unread_count     [IN]        
 *  num_item        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_handle_status_icons(S32 unread_count)
{
	if (unread_count != 0)
    {
        ShowStatusIcon(STATUS_ICON_WAP);
        UpdateStatusIcons();
    }
    else
    {
        HideStatusIcon(STATUS_ICON_WAP);
        UpdateStatusIcons();
    }
	return;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_send_config_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_send_config_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
	 wap_pmg_config_req_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
	
	  Message.oslSrcId = MOD_MMI;
     Message.oslDestId = MOD_WAP;
     Message.oslMsgId = MSG_ID_WAP_PMG_CONFIG_REQ;

     local_data = (wap_pmg_config_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_config_req_struct));

     if (push_setting_data->push_enable_flag != PUSH_ENABLE_OFF)
     {
         local_data->wapPushEnabled = 1;
     }
     else
     {
         local_data->wapPushEnabled = 0;
     }
     if (push_setting_data->sl_setting_flag == PUSH_SL_SETTING_NEVER)
     {
         local_data->slEnabled = 0;
     }
     else
     {
         local_data->slEnabled = 1;
     }
	  if (push_setting_data->trust_setting_flag == PUSH_TRUST_SETTING_DISABLE)
	  {
		  local_data->trustEnabled = 0;
	  }
	  else
	  {
		 local_data->trustEnabled = 1;
	  }
     Message.oslDataPtr = (oslParaType*) local_data;
     Message.oslPeerBuffPtr = NULL;
     OslMsgSendExtQueue(&Message);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_msg_list_req
 * DESCRIPTION
 *  Push message list request to service layer.
 * PARAMETERS
 *  start_index     [IN]        
 *  num_item        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_msg_list_req(S32 start_index, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_msg_list_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_MSG_LIST_REQ;

    local_data = (wap_pmg_msg_list_req_struct*) OslConstructDataPtr(sizeof(wap_pmg_msg_list_req_struct));

    local_data->transID = 0;
    local_data->msgType = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->isRead = WAP_PMG_PARAM_NOT_SPECIFIED;
    /* local_data->isRead = WAP_PMG_PARAM_YES | WAP_PMG_PARAM_NO; */
    local_data->isExpired = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->hasInfo = WAP_PMG_PARAM_NOT_SPECIFIED;
    local_data->startFrom = start_index;
    local_data->size = num_item;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    /* mmi_brw_push_send_msg_list_response(local_data->startFrom, local_data->size); //Temporary called for UT */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_msg_list_rsp
 * DESCRIPTION
 * Push message list response from service layer. 
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_msg_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* MYQUEUE *data; */
    wap_pmg_msg_list_cnf_struct *msg_list = (wap_pmg_msg_list_cnf_struct*) msg;
    U8 i;
    static S16 buffer_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* data = (MYQUEUE *)msg; */

    /* msg_list = (wap_pmg_msg_list_cnf_struct *) data->oslDataPtr; */

    if (msg_list->size != 0)
    {
        for (i = 0; i < msg_list->size; i++)
        {
            if (g_push_inbox_msg_buffer[buffer_index] == NULL)
            {
                g_push_inbox_msg_buffer[buffer_index] =
                    (global_push_inbox_msg_struct*) mmi_push_malloc(sizeof(global_push_inbox_msg_struct));
            }
            if (g_push_inbox_msg_buffer[buffer_index] != NULL)
            {
                g_push_inbox_msg_buffer[buffer_index]->data.msgID = msg_list->msgListData[i].msgID;
                g_push_inbox_msg_buffer[buffer_index]->data.msgType = msg_list->msgListData[i].msgType;
                g_push_inbox_msg_buffer[buffer_index]->data.created = msg_list->msgListData[i].created;
                g_push_inbox_msg_buffer[buffer_index]->data.expired = msg_list->msgListData[i].expired;
                g_push_inbox_msg_buffer[buffer_index]->data.priority = msg_list->msgListData[i].priority;
                g_push_inbox_msg_buffer[buffer_index]->data.textType = msg_list->msgListData[i].textType;
                g_push_inbox_msg_buffer[buffer_index]->data.read = msg_list->msgListData[i].read;

                memset(g_push_inbox_msg_buffer[buffer_index]->data.href, '\0', WAP_PMG_MAX_MSG_LIST_HREF_CHARS + 1);
                memset(g_push_inbox_msg_buffer[buffer_index]->data.text, '\0', WAP_PMG_MAX_MSG_LIST_TEXT_CHARS + 2);

                strcpy((S8*) g_push_inbox_msg_buffer[buffer_index]->data.href, (S8*) msg_list->msgListData[i].href);

                if (g_push_inbox_msg_buffer[buffer_index]->data.textType == WAP_PMG_STRTYPE_ASCII)
                {
                    strcpy(
                        (S8*) g_push_inbox_msg_buffer[buffer_index]->data.text,
                        (S8*) msg_list->msgListData[i].text);
                }
                else if (g_push_inbox_msg_buffer[buffer_index]->data.textType == WAP_PMG_STRTYPE_UCS2)
                {
                    mmi_ucs2cpy(
                        (S8*) g_push_inbox_msg_buffer[buffer_index]->data.text,
                        (S8*) msg_list->msgListData[i].text);
                }
                //                g_push_inbox_msg_buffer[buffer_index]->index = g_push_cntx.start_index + i;
                //     g_push_inbox_msg_buffer[buffer_index]->index = buffer_index;
            }

            buffer_index++;
        }
    }

    if (msg_list->more != 0)
    {
        mmi_brw_push_msg_list_req(msg_list->more, msg_list->sizeRemain);
    }
    else
    {
        mmi_brw_push_handle_pshmsg_get_msg_list_rsp();
        buffer_index = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_handle_pshmsg_get_msg_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_handle_pshmsg_get_msg_list_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_push_entry_inbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_inbox
 * DESCRIPTION
 *  Entry function for Push Inbox.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numItems = 0;

    U8 *guiBuffer;
#ifdef __MMI_UNIFIED_MESSAGE__	

	mmi_um_cancel_new_msg_ind_struct *um_local_data = NULL;
	MYQUEUE Message;

#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numItems = g_push_cntx.push_msg_count;

#ifdef __MMI_UNIFIED_MESSAGE__	

	Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND;

	um_local_data = (mmi_um_cancel_new_msg_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_cancel_new_msg_ind_struct));

	um_local_data->msg_type = UM_MSG_TYPE_WAP_PUSH;
	um_local_data->msg_box_type = UM_MSG_BOX_TYPE_INBOX;

	Message.oslDataPtr = (oslParaType*) um_local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

#endif
    numItems = g_push_cntx.push_msg_count;

    while (new_phs_msg_queue != NULL)
    {
        push_msg_ind_queue_struct *msg_data = new_phs_msg_queue;

        new_phs_msg_queue = new_phs_msg_queue->next;
        OslMfree(msg_data);
        msg_data = NULL;
    }

    if (numItems == 0)
    {
        g_push_inbox_entry_flag = FALSE;
		HideStatusIcon(STATUS_ICON_WAP);
		UpdateStatusIcons();
        DisplayPopup(
            (PU8) GetString(STR_ID_PUSH_INBOX_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
    else
    {

        EntryNewScreen(SCR_ID_PUSH_INBOX, NULL, mmi_brw_push_entry_inbox, NULL);

        DeleteScreenIfPresent(SCR_ID_PUSH_PROCESSING);

        if (g_push_cntx.push_msg_index >= numItems)
        {
            g_push_cntx.push_msg_index = numItems - 1;
        }
        g_push_inbox_entry_flag = TRUE;

        guiBuffer = GetCurrGuiBuffer(SCR_ID_PUSH_INBOX);

        if (g_push_free_gui_buffer_flag == TRUE)
        {
            guiBuffer = NULL;
            g_push_free_gui_buffer_flag = FALSE;
        }

        RegisterHighlightHandler(mmi_brw_push_hilite_msg_index);

        ShowCategory184Screen(
            STR_ID_PUSH_INBOX,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_READ,
            0,
            STR_GLOBAL_BACK,
            0,
            numItems,
            mmi_brw_push_inbox_list_get_item,
            0,
            g_push_cntx.push_msg_index,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_brw_push_entry_msg, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_push_entry_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(rsk_handling_push_inbox_list, KEY_EVENT_UP);
        SetKeyHandler(rsk_handling_push_inbox_list, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  rsk_handling_push_inbox_list
 * DESCRIPTION
 *  RSK handling for push inbox screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void rsk_handling_push_inbox_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_inbox_entry_flag = FALSE;
    mmi_brw_push_free_msg_buffer();
    /* HideStatusIcon(STATUS_ICON_WAP); */
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_msg
 * DESCRIPTION
 *  Request for the content of selected message in push inbox.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 msgID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S16 index;
       
       index = g_push_cntx.push_msg_index - g_push_cntx.start_index;
       
       if (index < 0)
       {
       MMI_ASSERT(0);
       } */

    msgID = g_push_inbox_msg_buffer[g_push_cntx.push_msg_index]->data.msgID;

    mmi_brw_push_get_msg_from_service_layer(msgID,GENERAL_MSG_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_inbox_list_get_item
 * DESCRIPTION
 *  Callback used by push inbox category screen to get push message dynamically.
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_brw_push_inbox_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 rcvd_message_href_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index > MAX_PUSH_MSG - 1))
    {
        return FALSE;
    }

    if (g_push_inbox_msg_buffer[item_index]->data.msgType == WAP_PMG_MSGTYPE_SI)
    {
        if (g_push_inbox_msg_buffer[item_index]->data.text[0] != '\0')
        {
            if (g_push_inbox_msg_buffer[item_index]->data.textType == WAP_PMG_STRTYPE_ASCII)
            {
                S8 ucs2_string[(32 + 1) * ENCODING_LENGTH];

                memset(ucs2_string, 0, sizeof(ucs2_string));

                mmi_asc_to_ucs2((S8*) ucs2_string, (S8*) g_push_inbox_msg_buffer[item_index]->data.text);

                rcvd_message_href_len = mmi_ucs2strlen((S8*) ucs2_string);

                if (rcvd_message_href_len > MAX_SUBMENU_CHARACTERS - 1)
                {
                    mmi_ucs2ncpy((S8*) str_buff, (S8*) ucs2_string, MAX_SUBMENU_CHARACTERS - 3);
                    mmi_ucs2cat((S8*) str_buff, ".\0.\0.\0");
                }
                else
                {
                    mmi_ucs2cpy((S8*) str_buff, (S8*) ucs2_string);
                }

            }
            else if (g_push_inbox_msg_buffer[item_index]->data.textType == WAP_PMG_STRTYPE_UCS2)
            {
                rcvd_message_href_len = mmi_ucs2strlen((S8*) g_push_inbox_msg_buffer[item_index]->data.text);

                if (rcvd_message_href_len > MAX_SUBMENU_CHARACTERS - 1)
                {
                    mmi_ucs2ncpy(
                        (S8*) str_buff,
                        (S8*) g_push_inbox_msg_buffer[item_index]->data.text,
                        MAX_SUBMENU_CHARACTERS - 3);
                    mmi_ucs2cat((S8*) str_buff, ".\0.\0.\0");
                }
                else
                {
                    mmi_ucs2cpy((S8*) str_buff, (S8*) g_push_inbox_msg_buffer[item_index]->data.text);
                }
            }
        }

        else
        {

            S8 ucs2_href[(48 + 1) * ENCODING_LENGTH];

            memset(ucs2_href, 0, sizeof(ucs2_href));

            mmi_asc_to_ucs2((S8*) ucs2_href, (S8*) g_push_inbox_msg_buffer[item_index]->data.href);
            rcvd_message_href_len = mmi_ucs2strlen((S8*) ucs2_href);

            if (rcvd_message_href_len > MAX_SUBMENU_CHARACTERS - 1)
            {
                mmi_ucs2ncpy((S8*) str_buff, (S8*) ucs2_href, MAX_SUBMENU_CHARACTERS - 3);

                mmi_ucs2cat((S8*) str_buff, ".\0.\0.\0");
            }
            else
            {
                mmi_ucs2cpy((S8*) str_buff, (S8*) ucs2_href);
            }
        }

        if (g_push_inbox_msg_buffer[item_index]->data.read == 0)
        {
            if (g_push_inbox_msg_buffer[item_index]->data.expired == 0 ||
                g_push_inbox_msg_buffer[item_index]->data.expired > (S32) push_get_current_utc_time())
            {
                *img_buff_p = get_image(IMG_ID_BRW_PUSH_UNREAD);
                /* *img_buff_p = get_image(WAP_IMAGE_SW_PUSH_UREAD); */
            }
            else
            {
                *img_buff_p = get_image(IMG_ID_BRW_PUSH_EXPIRED_UNREAD);
                /* *img_buff_p = get_image(WAP_IMAGE_SW_PUSH_EUREAD); */
            }
        }
        else
        {
            if (g_push_inbox_msg_buffer[item_index]->data.expired == 0 ||
                g_push_inbox_msg_buffer[item_index]->data.expired > (S32) push_get_current_utc_time())
            {
                *img_buff_p = get_image(IMG_ID_BRW_PUSH_READ);
                /* *img_buff_p = get_image(WAP_IMAGE_SW_PUSH_READ); */
            }
            else
            {
                *img_buff_p = get_image(IMG_ID_BRW_PUSH_EXPIRED_READ);
                /* *img_buff_p = get_image(WAP_IMAGE_SW_PUSH_EREAD); */
            }
        }

    }
    else if (g_push_inbox_msg_buffer[item_index]->data.msgType == WAP_PMG_MSGTYPE_SL)
    {
        S8 ucs2_href[(48 + 1) * ENCODING_LENGTH];

        memset(ucs2_href, 0, sizeof(ucs2_href));

        mmi_asc_to_ucs2((S8*) ucs2_href, (S8*) g_push_inbox_msg_buffer[item_index]->data.href);
        rcvd_message_href_len = mmi_ucs2strlen((S8*) ucs2_href);

        if (rcvd_message_href_len > MAX_SUBMENU_CHARACTERS - 1)
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) ucs2_href, MAX_SUBMENU_CHARACTERS - 3);

            mmi_ucs2cat((S8*) str_buff, ".\0.\0.\0");
        }
        else
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) ucs2_href);
        }

        if (g_push_inbox_msg_buffer[item_index]->data.read == 0)
        {
            *img_buff_p = get_image(IMG_ID_BRW_PUSH_UNREAD);
            /* *img_buff_p = get_image(WAP_IMAGE_SW_PUSH_UREAD); */
        }
        else
        {
            *img_buff_p = get_image(IMG_ID_BRW_PUSH_READ);
            /* *img_buff_p = get_image(WAP_IMAGE_SW_PUSH_READ); */
        }

    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_processing_generic
 * DESCRIPTION
 *  This API shows the progressing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PUSH_PROCESSING, NULL, mmi_brw_push_entry_processing_generic, NULL);

    ShowCategory8Screen(
        STR_ID_PUSH_INBOX,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        STR_ID_PUSH_MSG_LOADING,
        IMG_GLOBAL_PROGRESS,
        NULL);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  push_get_current_utc_time
 * DESCRIPTION
 *  This API returns the current UTC time.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 push_get_current_utc_time(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timeSecs;

#ifndef __MTK_TARGET__
    time_t ltime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timeSecs = (U32) time(&ltime);
#else /* __MTK_TARGET__ */ 
    t_rtc rtc;
    struct tm when;

    RTC_GetTime(&rtc);
    when.tm_sec = rtc.rtc_sec;
    when.tm_min = rtc.rtc_min;
    when.tm_hour = rtc.rtc_hour;
    when.tm_mday = rtc.rtc_day;
    when.tm_mon = rtc.rtc_mon - 1;
    when.tm_year = rtc.rtc_year + 100;
    when.tm_isdst = 0;
    timeSecs = (U32) mktime(&when);
#endif /* __MTK_TARGET__ */ 

    timeSecs = applib_dt_sec_utc_to_local(timeSecs);
    return timeSecs;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_hilite_msg_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_hilite_msg_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntx.push_msg_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_goto_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Goto Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_goto_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_push_goto_url, KEY_EVENT_UP);
 //   SetKeyHandler(mmi_brw_push_goto_url, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_add_to_trust_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Add To Trust List option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_add_to_trust_list_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_push_add_to_trust_list, KEY_EVENT_UP);
  //  SetKeyHandler(mmi_brw_push_add_to_trust_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_add_homepage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Add Homepage option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_add_homepage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_push_set_as_homepage, KEY_EVENT_UP);
  //  SetKeyHandler(mmi_brw_push_set_as_homepage, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_send_by_highlight_hdlr
 * DESCRIPTION
 * Highlight handler for Send By option. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_send_by_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_psh_entry_send_by_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_psh_entry_send_by_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Delete option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_push_delete_msg_from_inbox, KEY_EVENT_UP);
   // SetKeyHandler(mmi_brw_push_delete_msg_from_inbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ 
void mmi_brw_um_compile_option_delete_highlight_hdlr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_push_um_inbox_option_delete_msg, KEY_EVENT_UP);
  //  SetKeyHandler(mmi_brw_push_um_inbox_option_delete_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_all_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Delete All option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_all_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_push_delete_all_msg_from_inbox, KEY_EVENT_UP);
 //   SetKeyHandler(mmi_brw_push_delete_all_msg_from_inbox, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_send_by_sms_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Send by SMS option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_send_by_sms_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_send_by_sms, KEY_EVENT_UP);
  //  SetKeyHandler(mmi_brw_send_by_sms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_send_by_email_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Send by Email option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_send_by_email_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_send_by_email, KEY_EVENT_UP);
//    SetKeyHandler(mmi_brw_send_by_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_send_by_mms_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Send by MMS option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_send_by_mms_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_send_by_mms, KEY_EVENT_UP);
 //   SetKeyHandler(mmi_brw_send_by_mms, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_add_to_trust_list
 * DESCRIPTION
 *  This API adds the push msg sender's address to Trust List.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_add_to_trust_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	 S16 error;
	 U8 index = 0, i;
	 U8 trustaddr_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_psh_get_trust_list_count();

	for (i = 0; i < g_push_cntx.trust_addr_count; i++)
	{
		if (strcmp((S8*)g_push_msg_rsp_data->msgData.smsc.addr,
					(S8*)push_setting_data->trust_addr_arr[i].addr) == 0)
		{
			DisplayPopup(
            (PU8) GetString(STR_ID_PUSH_SAME_ITEM_EXIST),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
			return;
		}
	}

    if (g_push_cntx.trust_addr_count == NVRAM_PUSH_TRUST_ADDR_LIST_MAX)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_PUSH_TRUST_LIST_FULL),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
            switch (g_push_msg_rsp_data->msgData.smsc.addr_type)
        {

            case WAP_PMG_ADDR_PHONE:
            case WAP_PMG_ADDR_IP:
            case WAP_PMG_ADDR_TEXT:

                push_setting_data->trust_addr_arr[g_push_cntx.trust_addr_count].addr_type
                    = g_push_msg_rsp_data->msgData.smsc.addr_type;

                strcpy(
                    (S8*) push_setting_data->trust_addr_arr[g_push_cntx.trust_addr_count].addr,
                    (S8*) g_push_msg_rsp_data->msgData.smsc.addr);

				g_push_cntx.trust_addr_count++;
	
				while (index < g_push_cntx.trust_addr_count)
				{
					if ((g_push_cntx.trust_addr_count - index) < WAP_PMG_MAX_MSG_ADDR_LIST_SIZE)
					{
						trustaddr_count = g_push_cntx.trust_addr_count - index; 
						mmi_brw_push_send_trust_list(index, trustaddr_count);
						index = g_push_cntx.trust_addr_count;
					}
					else
					{
						mmi_brw_push_send_trust_list(index, WAP_PMG_MAX_MSG_ADDR_LIST_SIZE);
						index = index + WAP_PMG_MAX_MSG_ADDR_LIST_SIZE;
					}
				}
			
                WriteRecord(NVRAM_EF_PUSH_SETTING_LID, 1, push_setting_data, sizeof(nvram_push_setting_struct), &error);

                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    SUCCESS_TONE);
                break;

            default:

                DisplayPopup(
                    (PU8) GetString(STR_ID_PUSH_VALIDATION_FAIL_NEW_MSG),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                break;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_msg_from_inbox
 * DESCRIPTION
 *  This API Shows the confirmation screen for selection of delete option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_msg_from_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 str[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(DeletePushMsg, KEY_EVENT_UP);
  //  SetKeyHandler(DeletePushMsg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
  //  SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  DeletePushMsg
 * DESCRIPTION
 *  This API deletes the message from the push inbox buffer and send the delete request to service layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeletePushMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_pmg_delete_msg_req_struct delete_msg;
    pBOOL status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_push_cntx.arrived_service_msg == TRUE)
    {
        delete_msg.transID = NEW_MSG_OPTION_DEL_ID;
        g_push_cntx.arrived_service_msg = FALSE;
    }
    else
    {
        delete_msg.transID = INBOX_MSG_DEL_ID;
    }

    delete_msg.msgID = g_push_msg_rsp_data->msgData.msgID;

	if (new_phs_msg_queue != NULL)
	{
		mmi_brw_push_delete_msg_from_queue(g_push_msg_rsp_data->msgData.msgID);
	}

    if (g_push_inbox_entry_flag == TRUE)
    {
        status = mmi_brw_push_delete_msg_from_inbox_buffer(g_push_msg_rsp_data->msgData.msgID);
            }

	mmi_brw_push_entry_processing_generic();
    mmi_brw_push_send_delete_msg_req(&delete_msg);

}
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_um_inbox_option_delete_msg
 * DESCRIPTION
 *  This API Shows the confirmation screen for selection of delete option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_um_inbox_option_delete_msg(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 str[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(DeleteUMMsg, KEY_EVENT_UP);
    SetKeyHandler(DeleteUMMsg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }

void DeleteUMMsg(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	wap_pmg_delete_msg_req_struct delete_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	delete_msg.transID = UM_MSG_LIST_DEL_ID;
	delete_msg.msgID = g_push_cntx.um_msgID;
	mmi_brw_push_entry_processing_generic();
	mmi_brw_push_send_delete_msg_req(&delete_msg);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_delete_all_msg_from_inbox
 * DESCRIPTION
 *  This API Shows the confirmation screen for selection of Delete All option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_delete_all_msg_from_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str[26];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE_ALL));

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(DeleteAllPushMsg, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
   

/*****************************************************************************
 * FUNCTION
 *  DeleteAllPushMsg
 * DESCRIPTION
 *  This API delete all the message from the push inbox buffer and send the delete all request to service layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteAllPushMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
	 push_msg_ind_queue_struct *delete_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HideStatusIcon(STATUS_ICON_WAP);
	UpdateStatusIcons();

    if (g_push_inbox_entry_flag == TRUE)
    {
        g_push_inbox_entry_flag = FALSE;
        /* HideStatusIcon(STATUS_ICON_WAP); */
        for (i = 0; i < g_push_cntx.push_msg_count; i++)
        {
            mmi_push_mfree(g_push_inbox_msg_buffer[i]);
            g_push_inbox_msg_buffer[i] = NULL;
        }
        g_push_cntx.push_msg_count = 0;
        mmi_brw_push_delete_all_msg_req();
        return;
    }
	while (new_phs_msg_queue != NULL)
    {
        delete_msg = new_phs_msg_queue;
        new_phs_msg_queue = new_phs_msg_queue->next;
        OslMfree(delete_msg);
        delete_msg = NULL;
    }
#ifdef __MMI_UNIFIED_MESSAGE__
    SetProtocolEventHandler(mmi_push_um_delete_all_res, MSG_ID_MMI_UM_DELETE_ALL_RES);
    mmi_push_um_delete_all_ind();
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}
#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_add_to_bookmark
 * DESCRIPTION
 *  This API send the URL associated with the push msg to browser bookmark interface.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_add_bookmark_highlight_hdlr(void)
{
	 ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_push_add_to_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_push_add_to_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_add_to_bookmark
 * DESCRIPTION
 *  This API send the URL associated with the push msg to browser bookmark interface.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 ucs2_href[(WAP_PMG_MAX_MSG_HREF_CHARS+1)*ENCODING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_asc_n_to_ucs2((S8*)ucs2_href,g_push_msg_rsp_href,strlen(g_push_msg_rsp_href));
	wap_start_browser(WAP_BROWSER_ADD_BOOKMARK, (U8*)ucs2_href);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_set_as_homepage
 * DESCRIPTION
 *  This API send the URL associated with the push msg to browser homepage interface.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_set_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_set_as_homepage((U8*)g_push_msg_rsp_href);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_goto_url
 * DESCRIPTION
 *  This API send the URL associated with the push msg to browser load url interface.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_goto_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	 S8 str[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (g_push_msg_rsp_data->msgData.expired != 0 && 
		g_push_msg_rsp_data->msgData.expired < (S32) push_get_current_utc_time())
	{
		
		mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_ID_BRW_PUSH_MESSAGE_EXPIRED));

		DisplayConfirm(
			STR_GLOBAL_YES,
			IMG_GLOBAL_YES,
			STR_GLOBAL_NO,
			IMG_GLOBAL_NO,
			(UI_string_type) str,
			IMG_GLOBAL_QUESTION,
			WARNING_TONE);

		SetLeftSoftkeyFunction(LoadPushUrl, KEY_EVENT_UP);
		SetKeyHandler(LoadPushUrl, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
		SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
	}
	else
	{
    mmi_brw_load_url((U8*)g_push_msg_rsp_href);
}
}
/*****************************************************************************
 * FUNCTION
 *  LoadPushUrl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LoadPushUrl(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(g_push_msg_rsp_href);
		mmi_brw_load_url((U8*)g_push_msg_rsp_href);
	if (g_idle_callback == TRUE)
	{
		g_idle_callback = FALSE;
}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_by_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_by_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	PS8 ucs2_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	ucs2_data = mmi_brw_push_construct_send_by_data();
	if (ucs2_data != NULL)
	{
#ifdef __MMI_EMAIL__
		mmi_email_app_send_cont(ucs2_data);
#endif
		OslMfree(ucs2_data);
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_by_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_by_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	S8 *ucs2_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef MMS_SUPPORT
       extern void mms_text_insert_hdlr(char *subject, unsigned int subject_len, char *text, unsigned int text_len);
    #endif

	while (1)
	{
		if(mmi_bootup_is_sim_valid())
		{
	ucs2_data = mmi_brw_push_construct_send_by_data();

	if (ucs2_data != NULL)
	{
		mms_text_insert_hdlr(NULL,0,ucs2_data,mmi_ucs2strlen(ucs2_data));
		OslMfree(ucs2_data);
	}
			break;
		}
		else
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_PUSH_INVALID_SIM), 
				IMG_GLOBAL_WARNING, 
				1, 
				1000,
				WARNING_TONE);
			break;
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_send_by_sms
 * DESCRIPTION
 *  This API send the push msg href and text to SMS editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_send_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_api_entry_write_struct smsData;
  /*  S16 message_length = 0;
    S16 message_href_length = 0;
    S16 meassage_body_length = 0;
    PS8 ucs2_msg = NULL, ucs2_href = NULL;

    S8 ucs2_str[20];*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&smsData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

    smsData.dcs = SMSAL_UCS2_DCS;
    /* insert content to SMS editor */

  /*  if (g_push_msg_rsp_data->msgData.text != NULL)
    {
        if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_ASCII)
        {
            meassage_body_length = strlen((const S8*)g_push_msg_rsp_data->msgData.text);
            meassage_body_length = (meassage_body_length + 1) * ENCODING_LENGTH;
        }
        else
        {
            meassage_body_length = mmi_ucs2strlen((const S8*)g_push_msg_rsp_data->msgData.text);
        }
    }

    if (g_push_msg_rsp_href != NULL)
    {
        message_href_length = strlen((const S8*)g_push_msg_rsp_href);
        message_href_length = (message_href_length + 1) * ENCODING_LENGTH;
    }

    message_length = message_href_length + meassage_body_length + 100;
    smsData.string = (PS8) OslMalloc((message_length + 1) * ENCODING_LENGTH);

    if (0 != message_href_length)
    {
        mmi_ucs2cpy((S8*) smsData.string, GetString(STR_ID_PUSH_URL));
        mmi_asc_to_ucs2((S8*) ucs2_str, " ");
        mmi_ucs2cat(smsData.string, ucs2_str);

        ucs2_href = (PS8) OslMalloc(message_href_length);
        if (ucs2_href != NULL)
        {
            mmi_asc_to_ucs2((S8*) ucs2_href, (S8*) g_push_msg_rsp_href);
        }
        mmi_ucs2cat((S8*) smsData.string, ucs2_href);
        mmi_asc_to_ucs2((S8*) ucs2_str, " ");
        mmi_ucs2cat(smsData.string, ucs2_str);
        OslMfree(ucs2_href);
    }

    if (0 != meassage_body_length)
    {
        if (0 != message_href_length)
        {
            mmi_ucs2cat((S8*) smsData.string, GetString(STR_ID_PUSH_MESSAGE));
        }
        else
        {
            mmi_ucs2cpy((S8*) smsData.string, GetString(STR_ID_PUSH_MESSAGE));
        }
        mmi_asc_to_ucs2((S8*) ucs2_str, " ");
        mmi_ucs2cat(smsData.string, ucs2_str);

        if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_ASCII)
        {
            ucs2_msg = (PS8) OslMalloc(meassage_body_length);
            if (ucs2_msg != NULL)
            {
                mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_push_msg_rsp_data->msgData.text);
            }
            mmi_ucs2cat((S8*) smsData.string, ucs2_msg);
            OslMfree(ucs2_msg);

        }
        else if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_UCS2)
        {
            mmi_ucs2cat((S8*) smsData.string, (S8*) g_push_msg_rsp_data->msgData.text);
        }
    }*/

    /* smsData.string = malloc(...) */
	 if(mmi_bootup_is_sim_valid())
	 {
	smsData.string = mmi_brw_push_construct_send_by_data();
    smsData.stringlength = mmi_ucs2strlen((const S8*)(smsData.string));
    smsData.flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;

    /* add recipient */
    smsData.ascii_addr = NULL;

    mmi_frm_sms_api_entry_write_msg(&smsData);
	 }
	 else
	 {
		DisplayPopup(
			(PU8) GetString(STR_ID_PUSH_INVALID_SIM), 
			IMG_GLOBAL_DELETED, 
			1, 
			1000,
			SUCCESS_TONE);
	 }

    if (smsData.string)
        OslMfree(smsData.string);
    if (smsData.ascii_addr)
        OslMfree(smsData.ascii_addr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_construct_send_by_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  PS8
 *****************************************************************************/
S8	*mmi_brw_push_construct_send_by_data(void)
{
	S16 message_length = 0;
    S16 message_href_length = 0;
    S16 meassage_body_length = 0;
    PS8 ucs2_msg = NULL, ucs2_href = NULL, ucs2_data = NULL;

    S8 ucs2_str[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_push_msg_rsp_data->msgData.text != NULL)
    {
        if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_ASCII)
        {
            meassage_body_length = strlen((const S8*)g_push_msg_rsp_data->msgData.text);
            meassage_body_length = (meassage_body_length + 1) * ENCODING_LENGTH;
        }
        else
        {
            meassage_body_length = mmi_ucs2strlen((const S8*)g_push_msg_rsp_data->msgData.text);
        }
}

    if (g_push_msg_rsp_href != NULL)
    {
        message_href_length = strlen((const S8*)g_push_msg_rsp_href);
        message_href_length = (message_href_length + 1) * ENCODING_LENGTH;
    }

    message_length = message_href_length + meassage_body_length + 100;
    ucs2_data = (PS8) OslMalloc((message_length + 1) * ENCODING_LENGTH);

    if (0 != message_href_length)
    {
        mmi_ucs2cpy((S8*) ucs2_data, GetString(STR_ID_PUSH_URL));
        mmi_asc_to_ucs2((S8*) ucs2_str, "\n");
        mmi_ucs2cat(ucs2_data, ucs2_str);

        ucs2_href = (PS8) OslMalloc(message_href_length);
        if (ucs2_href != NULL)
        {
            mmi_asc_to_ucs2((S8*) ucs2_href, (S8*) g_push_msg_rsp_href);
        }
        mmi_ucs2cat((S8*) ucs2_data, ucs2_href);
        mmi_asc_to_ucs2((S8*) ucs2_str, "\n");
        mmi_ucs2cat(ucs2_data, ucs2_str);
        OslMfree(ucs2_href);
    }

    if (0 != meassage_body_length)
    {
        if (0 != message_href_length)
        {
            mmi_ucs2cat((S8*) ucs2_data, GetString(STR_ID_PUSH_MESSAGE));
        }
        else
        {
            mmi_ucs2cpy((S8*) ucs2_data, GetString(STR_ID_PUSH_MESSAGE));
        }
        mmi_asc_to_ucs2((S8*) ucs2_str, "\n");
        mmi_ucs2cat(ucs2_data, ucs2_str);

        if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_ASCII)
        {
            ucs2_msg = (PS8) OslMalloc(meassage_body_length);
            if (ucs2_msg != NULL)
            {
                mmi_asc_to_ucs2((S8*) ucs2_msg, (S8*) g_push_msg_rsp_data->msgData.text);
            }
            mmi_ucs2cat((S8*) ucs2_data, ucs2_msg);
            OslMfree(ucs2_msg);

        }
        else if (g_push_msg_rsp_data->msgData.textType == WAP_PMG_STRTYPE_UCS2)
        {
            mmi_ucs2cat((S8*) ucs2_data, (S8*) g_push_msg_rsp_data->msgData.text);
        }
    }

	return ucs2_data;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_psh_entry_send_by_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_psh_entry_send_by_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 list_of_items[3];
    U8 *gui_buffer;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SEND_BY_OPTIONS, NULL, mmi_brw_psh_entry_send_by_option, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_SEND_BY_OPTIONS);

    //      mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL);
    //      mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_MMS);

#ifndef __MMI_EMAIL__
    mmi_frm_hide_menu_item(MENU_ID_PUSH_SERVICE_MSG_SEND_BY_EMAIL);     
#endif /* __MMI_EMAIL__ */ 

    num_of_items = GetNumOfChild_Ext(MENU_ID_PUSH_SERVICE_MSG_SEND_BY);
    GetSequenceStringIds_Ext(MENU_ID_PUSH_SERVICE_MSG_SEND_BY, list_of_items);
    SetParentHandler(MENU_ID_PUSH_SERVICE_MSG_SEND_BY);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_PUSH_INBOX_SERVICE_MESSAGE_SEND_BY,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_free_memory
 * DESCRIPTION
 *  This API frees memory occupied by push inbox buffer,push message content buffer and push message href buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[PushInboxSrc.c] mmi_brw_push_free_memory \n");

    mmi_brw_push_free_msg_buffer();

	if (g_push_inbox_entry_flag == TRUE)
	{
		DeleteScreenIfPresent(SCR_ID_BRW_SEND_BY_OPTIONS);
		DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
		DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
		DeleteScreenIfPresent(SCR_ID_PUSH_INBOX);
                g_push_inbox_entry_flag = FALSE;
	}

    /* if (g_new_msg_data != NULL)
       {
       OslMfree(g_new_msg_data);
       g_new_msg_data = NULL;
       }
       if (g_new_msg_href != NULL)
       {
       OslMfree(g_new_msg_href);
       g_new_msg_href = NULL;
       } */
/*	if (g_idle_callback == FALSE)
	{
    if (g_push_msg_rsp_data != NULL)
    {
        OslMfree(g_push_msg_rsp_data);
        g_push_msg_rsp_data = NULL;
    }
    if (g_push_msg_rsp_href != NULL)
    {
        OslMfree(g_push_msg_rsp_href);
        g_push_msg_rsp_href = NULL;
    }
	}
	else
	{
		g_idle_callback = FALSE;
	}*/
/*	 if (IsScreenPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE) 
		 || GetActiveScreenId() == SCR_ID_BRW_READ_SERVICE_MESSAGE)
	 {
		 DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
       DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
		 DeleteScreenIfPresent(SCR_ID_PUSH_INBOX);
		 DeleteScreenIfPresent(SCR_ID_UM_MESSAGE_OPTIONS);
		 GoBackHistory();
	//	 DisplayIdleScreen();
	// }*/
	 }
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_end_key_handling
 * DESCRIPTION
 *  This API frees memory occupied by push inbox buffer,push message content buffer and push message href buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_end_key_handling(void)
{
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[PushInboxSrc.c] mmi_brw_push_end_key_handling \n");

	mmi_brw_push_free_msg_buffer();
    g_push_inbox_entry_flag = FALSE;
	g_push_cntx.arrived_service_msg = FALSE;

	if (g_idle_callback == TRUE)
	{
		g_idle_callback = FALSE;
	}
  
    if (g_push_msg_rsp_data != NULL)
    {
        OslMfree(g_push_msg_rsp_data);
        g_push_msg_rsp_data = NULL;
    }
    if (g_push_msg_rsp_href != NULL)
    {
        OslMfree(g_push_msg_rsp_href);
        g_push_msg_rsp_href = NULL;
    }
	DisplayIdleScreen();
}
/***** unified message section ****/
#ifdef __MMI_UNIFIED_MESSAGE__


/*****************************************************************************
 * FUNCTION
 *  mmi_push_um_new_msg_ind
 * DESCRIPTION
 *  A new msg indication to UM module .
 * PARAMETERS
 *  um_msg_data     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_um_new_msg_ind(mmi_um_new_msg_ind_struct *um_msg_data)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_um_new_msg_ind_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (!isInCall())
	{
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_NEW_MSG_IND;

    local_data = (mmi_um_new_msg_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_new_msg_ind_struct));

    /* local_data = um_msg_data; */

    //local_data->ref_count = um_msg_data->ref_count;
    //      local_data->msg_len = um_msg_data->msg_len;
    local_data->msg_type = UM_MSG_TYPE_WAP_PUSH;
    local_data->msg_index = um_msg_data->msg_index;
    local_data->timestamp = um_msg_data->timestamp;
    local_data->msg_box_type = UM_MSG_BOX_TYPE_INBOX;


    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
	}
	else
	{
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[PushInboxSrc.c] Send mmi_um_refresh_msg_ind to Um from Push App \n");
		mmi_um_refresh_msg_ind();
	}
	if (g_idle_callback == TRUE)
	{
		g_idle_callback = FALSE;
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_um_refresh_msg_ind
 * DESCRIPTION
 *  refresh indication to UM module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_refresh_msg_ind(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_um_refresh_ind_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_REFRESH_IND;

    local_data = (mmi_um_refresh_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_refresh_ind_struct));

    local_data->msg_type = UM_MSG_TYPE_WAP_PUSH;
    local_data->msg_box_type = UM_MSG_BOX_TYPE_INBOX;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_push_um_delete_all_ind
 * DESCRIPTION
 *  Delete All indication to UM module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_um_delete_all_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_um_delete_all_ind_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_DELETE_ALL_IND;

    local_data = (mmi_um_delete_all_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_delete_all_ind_struct));

    local_data->msg_type = UM_MSG_TYPE_WAP_PUSH;
    local_data->msg_box_type = UM_MSG_BOX_TYPE_INBOX;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_push_um_delete_all_res
 * DESCRIPTION
 *  Delete All response from UM module.
 * PARAMETERS
 *  msg     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_um_delete_all_res(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* MYQUEUE *data; */
    mmi_um_delete_all_res_struct *res_data = (mmi_um_delete_all_res_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* data = (MYQUEUE *)msg; */

    /* res_data = (mmi_um_delete_all_res_struct *) data->oslDataPtr; */
    /* if (res_data->msg_type == UM_MSG_TYPE_WAP_PUSH && 
       res_data->result == KAL_TRUE) */
    if (res_data->result == KAL_TRUE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
        DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_BRW_READ_SERVICE_MESSAGE);
    #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
        DeleteScreenIfPresent(SCR_ID_UM_MESSAGE_OPTIONS);
    #endif 
        /* GoBackHistory(); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_push_handle_entry_msg_wap_push
 * DESCRIPTION
 * UM sends the msgID to push application to display the content. 
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_handle_entry_msg_wap_push(kal_uint16 msg_box_type, kal_uint16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box_type == UM_MSG_BOX_TYPE_INBOX)
    {
        g_push_cntx.arrived_service_msg = FALSE;
        g_push_cntx.um_msgID = msg_index;
        g_push_inbox_entry_flag = FALSE;
        mmi_brw_um_pre_entry_message_display();
        /* mmi_brw_push_get_msg_from_service_layer(msg_index); */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_um_pre_entry_message_display
 * DESCRIPTION
 *  Pre entry function before display.If UM compile list option is enabled the it show the option screen 
	else it request for the message content from service layer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_um_pre_entry_message_display(void)
{
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_um_message_display_option();
#else /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */ 
    mmi_brw_push_delete_msg_from_queue(g_push_cntx.um_msgID); // delete msg from the idle screen display queue
	mmi_brw_push_get_msg_from_service_layer(g_push_cntx.um_msgID,GENERAL_MSG_ID);
#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_um_message_display_option
 * DESCRIPTION
 *  In case of UM compile list option, option screen will be displayed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_um_message_display_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 uc_list_of_items[3];
    U8 *gui_buffer;
    S32 num_of_items;

     /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UM_MESSAGE_OPTIONS, NULL, mmi_brw_um_message_display_option, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_UM_MESSAGE_OPTIONS);

    num_of_items = GetNumOfChild(MENU_ID_PUSH_INBOX_OPTION);
    GetSequenceStringIds(MENU_ID_PUSH_INBOX_OPTION, uc_list_of_items);
    SetParentHandler(MENU_ID_PUSH_INBOX_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        uc_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_um_push_read_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for read option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_um_push_read_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_brw_um_disp_push_msg, KEY_EVENT_UP);
 //   SetKeyHandler(mmi_brw_um_disp_push_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_um_disp_push_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_um_disp_push_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_push_delete_msg_from_queue(g_push_cntx.um_msgID); // delete msg from the idle screen display queue
	mmi_brw_push_get_msg_from_service_layer(g_push_cntx.um_msgID,GENERAL_MSG_ID);
}
#endif /* __MMI_UNIFIED_MESSAGE__ */ 



/***** From here code started for service layer dialogue which push module will
display**************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_service_dlg_entry
 * DESCRIPTION
 *  Push the new service dialogue to queue
 * PARAMETERS
 *  push_service_dlg_struct        [IN]     
 * RETURNS
 *  S16
 *****************************************************************************/
S16 mmi_brw_push_service_dlg_entry(push_service_dlg_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_dlg_queue_struct *new_dlg_msg = NULL;
	S16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
        return -1;

    new_dlg_msg = (push_dlg_queue_struct*) OslMalloc(sizeof(push_dlg_queue_struct));
    
	if (new_dlg_msg == NULL)
    {
        return -1;
    }

	new_dlg_msg->msgData.numItems = data->numItems;

	if (data->numItems == 0)
	{
		mmi_ucs2cpy((S8*)new_dlg_msg->msgData.content,(S8*)data->content);
	}
	else
	{
		while (index < data->numItems)
		{
			if (data->items[index][0] != '\0')
			{
				mmi_ucs2cpy((S8*)new_dlg_msg->msgData.items[index],(S8*)data->items[index]);
			}
			else
			{
				memset((S8*)new_dlg_msg->msgData.items[index],'\0',WAP_PMG_DLG_MAX_ITEM_TEXT_SIZE);
			}
			index++;
		}
	}

	mmi_ucs2cpy((S8*)new_dlg_msg->msgData.title,(S8*)data->title);
	new_dlg_msg->msgData.trans_id = data->trans_id;
	new_dlg_msg->next = NULL;

    mmi_brw_push_push_service_dlg(new_dlg_msg);
    
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_push_service_dlg
 * DESCRIPTION
 *  Push the new entry to queue
 * PARAMETERS
 *  new_push_msg        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_brw_push_push_service_dlg(push_dlg_queue_struct *new_dlg_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_dlg_queue_struct *tail = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_dlg_msg == NULL)
        return -1;

    tail = mmi_brw_push_get_last_service_dlg();
    if (tail == NULL)
    {
        g_new_phs_dlg_queue = new_dlg_msg;
    }
    else
    {
        tail->next = new_dlg_msg;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_get_last_service_dlg
 * DESCRIPTION
 *  Get the last item from the queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
push_dlg_queue_struct *mmi_brw_push_get_last_service_dlg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_dlg_queue_struct *service_dlg_rear = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    service_dlg_rear = g_new_phs_dlg_queue;

    if (service_dlg_rear == NULL)
    {
        return NULL;
    }

    while (service_dlg_rear->next != NULL)
    {
        service_dlg_rear = service_dlg_rear->next;
    }
    service_dlg_rear->next = NULL;

    return service_dlg_rear;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_pop_service_dlg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
push_dlg_queue_struct *mmi_brw_push_pop_service_dlg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    push_dlg_queue_struct *service_dlg_front = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_new_phs_dlg_queue == NULL)
    {
        return NULL;
    }

    service_dlg_front = g_new_phs_dlg_queue;

    if (g_new_phs_dlg_queue->next != NULL)
    {
        g_new_phs_dlg_queue = g_new_phs_dlg_queue->next;
    }
    else
    {
        g_new_phs_dlg_queue = NULL;
    }

    service_dlg_front->next = NULL;

    return service_dlg_front;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_free_service_dlg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  the_item        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_free_service_dlg(push_dlg_queue_struct *the_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (the_item != NULL)
    {
        OslMfree(the_item);
        the_item = NULL;
    }
    return;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_service_dlg_confirm_req
 * DESCRIPTION
 * 
 * PARAMETERS
 * void *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_service_dlg_confirm_req(void *msg)
{
	S16 index = 0;
//	 U16 *popuptext = L"New Message";

	wap_pmg_dlg_sia_confirm_req_struct *data = (wap_pmg_dlg_sia_confirm_req_struct*) msg;
	
	push_service_dlg_struct *msgData = NULL;
	U8 popup_text[WAP_PMG_DLG_MAX_POPUP_SIZE];

	msgData = (push_service_dlg_struct *)OslMalloc(sizeof(push_service_dlg_struct));
		
	mmi_ucs2cpy((S8*)msgData->title,GetString(data->title));
	mmi_ucs2cpy((S8*)msgData->content,GetString(data->content));
	msgData->numItems = 0;
	msgData->trans_id = data->trans_id;
	
	while (index < WAP_PMG_DLG_MAX_SELECT_ITEMS)
	{
		memset((S8*)msgData->items[index],'\0',WAP_PMG_DLG_MAX_ITEM_TEXT_SIZE);
		index++;	
	}

	if (GetActiveScreenId() == IDLE_SCREEN_ID)
	{
		g_service_dlg = msgData;
		mmi_brw_push_entry_display_service_msg_cnf();
	}
	else
	{
		if (mmi_brw_push_service_dlg_entry(msgData) == 0 && !isInCall())
		{
		/*	mmi_ucs2cpy((S8*) popup_text, (S8*)popuptext);

			DisplayPopup(
			(PU8) popup_text,
			IMG_GLOBAL_WARNING,
			1,
			UI_POPUP_NOTIFYDURATION_TIME,
			WARNING_TONE);*/

			mmi_msg_entry_new_msg_popup(MSG_BRW_NEW_MESSAGE);
			OslMfree(msgData);
		}
		else
		{
			MMI_ASSERT(0);
		}
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_service_dlg_unknown_addr_req
 * DESCRIPTION
 * 
 * PARAMETERS
 * void *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_service_dlg_unknown_addr_req(void *msg)
{
	S16 index = 0;
	U8 *item_p = NULL;
//	U16 *popuptext = L"New Message";

	wap_pmg_dlg_unknown_addr_req_struct *data = (wap_pmg_dlg_unknown_addr_req_struct*) msg;
	
	push_service_dlg_struct *msgData = NULL;
	U8 popup_text[WAP_PMG_DLG_MAX_POPUP_SIZE];

	msgData = (push_service_dlg_struct *)OslMalloc(sizeof(push_service_dlg_struct));
		
	mmi_ucs2cpy((S8*)msgData->title,GetString(data->title));
	msgData->numItems = data->numItems;
	msgData->trans_id = data->trans_id;

	
	while (index < msgData->numItems)
	{
		mmi_ucs2cpy((S8*)msgData->items[index],(S8*)data->items[index]);
		index++;
	}

	item_p = msgData->content;
	memset((S8*)msgData->content,'\0',WAP_PMG_DLG_MAX_CONTENT_SIZE);
	item_p = NULL;

	if (GetActiveScreenId() == IDLE_SCREEN_ID)
	{
		g_service_dlg = msgData;
		mmi_brw_push_entry_service_unknown_addr();
	}
	else
	{
		if (mmi_brw_push_service_dlg_entry(msgData) == 0 && !isInCall())
		{
		/*	mmi_ucs2cpy((S8*) popup_text, (S8*)popuptext);

			DisplayPopup(
			(PU8) popup_text,
			IMG_GLOBAL_WARNING,
			1,
			UI_POPUP_NOTIFYDURATION_TIME,
			WARNING_TONE);*/	
			mmi_msg_entry_new_msg_popup(MSG_BRW_NEW_MESSAGE);
			OslMfree(msgData);
		}
		else
		{
			MMI_ASSERT(0);
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_service_dlg_idle_scr_cb
 * DESCRIPTION
 *  used for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_brw_push_service_dlg_idle_scr_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_new_phs_dlg_queue != NULL)
    {
        return 1;
    }
    return 0;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_fetch_dlg_from_queue
 * DESCRIPTION
 *  used for idle screen callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_fetch_dlg_from_queue(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	push_dlg_queue_struct *service_dlg_front = NULL;
	S16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	service_dlg_front = mmi_brw_push_pop_service_dlg();
	
	if (g_service_dlg == NULL)
	{
		g_service_dlg = (push_service_dlg_struct *)OslMalloc(sizeof(push_service_dlg_struct));
	}
	g_service_dlg->numItems = service_dlg_front->msgData.numItems;
	mmi_ucs2cpy((S8*) g_service_dlg->title,(S8*)service_dlg_front->msgData.title);
	g_service_dlg->trans_id = service_dlg_front->msgData.trans_id;

	if (g_service_dlg->numItems == 0)
	{
		mmi_ucs2cpy((S8*) g_service_dlg->content,(S8*)service_dlg_front->msgData.content);	
		mmi_brw_push_entry_display_service_msg_cnf();
	}
	else
	{
		while (index < g_service_dlg->numItems)
		{
			mmi_ucs2cpy((S8*)g_service_dlg->items[index],(S8*)service_dlg_front->msgData.items[index]);
			index++;
		}
		mmi_brw_push_entry_service_unknown_addr();
	}

	mmi_brw_push_free_service_dlg(service_dlg_front);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_display_service_msg_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_display_service_msg_cnf(void)
{

	/*----------------------------------------------------------------*/
	/*Local Variables                                                 */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PUSH_DISPALY_CONFIRMATION, NULL, mmi_brw_push_entry_display_service_msg_cnf, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_PUSH_DISPALY_CONFIRMATION);
	  
	
	ShowCategory74Screen(
        STR_ID_PUSH_MESSAGE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        g_service_dlg->content,
        mmi_ucs2strlen((S8*)g_service_dlg->content),
        gui_buffer);

	SetLeftSoftkeyFunction(display_service_cnf_lsk_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(display_service_cnf_rsk_handler, KEY_EVENT_UP);
    SetKeyHandler(display_service_cnf_endkey_handler, KEY_END, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  display_service_cnf_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void display_service_cnf_lsk_handler(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_dlg_sia_confirm_cnf_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_DLG_SIA_CONFIRM_CNF;

    local_data = (wap_pmg_dlg_sia_confirm_cnf_struct*) OslConstructDataPtr(sizeof(wap_pmg_dlg_sia_confirm_cnf_struct));

    local_data->trans_id = g_service_dlg->trans_id;
    local_data->keyPressed = WAP_PMG_DLG_KEY_LSK;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
	OslMfree(g_service_dlg);
	g_service_dlg = NULL;
	GoBackHistory();

}
/*****************************************************************************
 * FUNCTION
 *  display_service_cnf_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void display_service_cnf_rsk_handler(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_dlg_sia_confirm_cnf_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_DLG_SIA_CONFIRM_CNF;

    local_data = (wap_pmg_dlg_sia_confirm_cnf_struct*) OslConstructDataPtr(sizeof(wap_pmg_dlg_sia_confirm_cnf_struct));

    local_data->trans_id = g_service_dlg->trans_id;
    local_data->keyPressed = WAP_PMG_DLG_KEY_RSK;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
	OslMfree(g_service_dlg);
	g_service_dlg = NULL;
	GoBackHistory();
}
/*****************************************************************************
 * FUNCTION
 *  display_service_cnf_endkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void display_service_cnf_endkey_handler(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_dlg_sia_confirm_cnf_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_DLG_SIA_CONFIRM_CNF;

    local_data = (wap_pmg_dlg_sia_confirm_cnf_struct*) OslConstructDataPtr(sizeof(wap_pmg_dlg_sia_confirm_cnf_struct));

    local_data->trans_id = g_service_dlg->trans_id;
    local_data->keyPressed = WAP_PMG_DLG_KEY_ENDKEY;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
	OslMfree(g_service_dlg);
	g_service_dlg = NULL;
	GoBackHistory();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_push_service_unknown_addr_higlight_hldr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_push_service_unknown_addr_higlight_hldr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_push_cntx.unknown_addr_index = (U8) index;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_push_entry_service_unknown_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_push_entry_service_unknown_addr(void)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    S32 num_of_item = 0;
    S32 count;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PUSH_SERIVCE_UNKNOWN_ADDR, NULL, mmi_brw_push_entry_service_unknown_addr, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_PUSH_SERIVCE_UNKNOWN_ADDR);

    num_of_item = (S32 )g_service_dlg->numItems;

    RegisterHighlightHandler(mmi_push_service_unknown_addr_higlight_hldr);

    for (count = 0; count < num_of_item; count++)
    {
        memset((S8*) subMenuDataPtrs[count], 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[count], (S8*) g_service_dlg->items[count], MAX_SUBMENU_CHARACTERS);
    }
    
    ShowCategory353Screen(
        g_service_dlg->title,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_CANCEL,
        0,
        num_of_item,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetLeftSoftkeyFunction(service_unknown_addr_lsk_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(service_unknown_addr_rsk_handler, KEY_EVENT_UP);
    SetKeyHandler(service_unknown_addr_endkey_handler, KEY_END, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  service_unknown_addr_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void service_unknown_addr_lsk_handler(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_dlg_unknown_addr_cnf_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_DLG_UNKNOWN_ADDR_CNF;

    local_data = (wap_pmg_dlg_unknown_addr_cnf_struct*) OslConstructDataPtr(sizeof(wap_pmg_dlg_unknown_addr_cnf_struct));

    local_data->trans_id = g_service_dlg->trans_id;
    local_data->keyPressed = WAP_PMG_DLG_KEY_LSK;
	local_data->selectedIndex = g_push_cntx.unknown_addr_index;

	g_push_cntx.unknown_addr_index = -1;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
	OslMfree(g_service_dlg);
	g_service_dlg = NULL;
	GoBackHistory();
}
/*****************************************************************************
 * FUNCTION
 *  service_unknown_addr_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void service_unknown_addr_rsk_handler(void)
{
		/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_dlg_unknown_addr_cnf_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_DLG_UNKNOWN_ADDR_CNF;

    local_data = (wap_pmg_dlg_unknown_addr_cnf_struct*) OslConstructDataPtr(sizeof(wap_pmg_dlg_unknown_addr_cnf_struct));

    local_data->trans_id = g_service_dlg->trans_id;
    local_data->keyPressed = WAP_PMG_DLG_KEY_RSK;
	local_data->selectedIndex = g_push_cntx.unknown_addr_index;

	g_push_cntx.unknown_addr_index = -1;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
	OslMfree(g_service_dlg);
	g_service_dlg = NULL;
	GoBackHistory();
}
/*****************************************************************************
 * FUNCTION
 *  service_unknown_addr_endkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void service_unknown_addr_endkey_handler(void)
{
		/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    wap_pmg_dlg_unknown_addr_cnf_struct *local_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_PMG_DLG_UNKNOWN_ADDR_CNF;

    local_data = (wap_pmg_dlg_unknown_addr_cnf_struct*) OslConstructDataPtr(sizeof(wap_pmg_dlg_unknown_addr_cnf_struct));

    local_data->trans_id = g_service_dlg->trans_id;
    local_data->keyPressed = WAP_PMG_DLG_KEY_ENDKEY;
	local_data->selectedIndex = g_push_cntx.unknown_addr_index;

	g_push_cntx.unknown_addr_index = -1;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
	OslMfree(g_service_dlg);
	g_service_dlg = NULL;
	GoBackHistory();
}

/****** UT for SERVICE DIALOGUE ****/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif