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
 *
 * Filename:
 * ---------
 *	wap_um.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for WAP UM interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stack_types.h"
#include "task_config.h"

#include "msm_env.h"

#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_cmmn.h"

#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"
#include "mea_def.h"
#include "mea_if.h"
#include "bra_if.h"
#include "wap.h"
#include "wap_ps_struct.h"
#include "Widget_extension.h"
#include "UnifiedMessageGProt.h"

#ifdef __UNIFIED_MSG_SUPPORT__
extern int msm_get_module_status(MSF_UINT8 modId);
extern MSF_BOOL getMmsMsgSubAddr(MSF_UINT8 modId,MmsMsgId msgId, char** subject, char** address,int MaxBufSize);
extern MeaAddrType meaGetAddrType(const char *addr);
extern char * meaLookupNameFromPHB(char *number);
extern ctk_image_id createImgList(int suffix, MSF_BOOL read, MSF_BOOL forwardLock, MmsPriority prio, MSF_BOOL isJSR);
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
extern MSF_BOOL smaIsRunning(void);
extern void wap_um_highlight_mms_message_ind(kal_uint32 msg_id, MeaFolder mea_box);
#ifdef __USB_IN_NORMAL_MODE__
extern kal_bool is_mms_storage_exported_to_pc(void);
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
#endif
/*************************************************************************
* FUNCTION
*	wap_translate_um_folder_2_mea_folder
* DESCRIPTION
*  This function is used to convert UM folder definition to MEA folder definition
*
* CALLS
*
* PARAMETERS
* box
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
MeaFolder wap_translate_um_folder_2_mea_folder(UmMsgBoxType box)
{
    MeaFolder folder = MEA_FOLDER_NONE;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if(box & UM_MSG_BOX_TYPE_ARCHIVE)
    {
        folder |= MEA_FOLDER_ARCHIVE;
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    if(box & UM_MSG_BOX_TYPE_INBOX)
    {
        folder |= MEA_FOLDER_INBOX;
    }

    if(box & UM_MSG_BOX_TYPE_SENT)
    {
        folder |= MEA_FOLDER_SENT;
    }

    if(box & UM_MSG_BOX_TYPE_UNSENT)
    {
        folder |= MEA_FOLDER_OUTBOX;
    }

    if(box & UM_MSG_BOX_TYPE_DRAFT)
    {
        folder |= MEA_FOLDER_DRAFTS;
    }

    return folder;
}

/*************************************************************************
* FUNCTION
*	wap_translate_mea_folder_2_um_folder
* DESCRIPTION
*  This function is used to convert MEA folder definition to UM folder definition
*
* CALLS
*
* PARAMETERS
* box
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
UmMsgBoxType wap_translate_mea_folder_2_um_folder(MeaFolder folder)
{
    UmMsgBoxType box = 0;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if(folder & MEA_FOLDER_ARCHIVE)
    {
        box |= UM_MSG_BOX_TYPE_ARCHIVE;
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    if(folder & MEA_FOLDER_INBOX)
    {
        box |= UM_MSG_BOX_TYPE_INBOX;
    }

    if(folder & MEA_FOLDER_SENT)
    {
        box |= UM_MSG_BOX_TYPE_SENT;
    }

    if(folder & MEA_FOLDER_OUTBOX)
    {
        box |= UM_MSG_BOX_TYPE_UNSENT;
    }

    if(folder & MEA_FOLDER_DRAFTS)
    {
        box |= UM_MSG_BOX_TYPE_DRAFT;
    }

    return box;
}


/*****************************************************************************
 * FUNCTION
 *  wap_um_highlight_mms_message_ind
 * DESCRIPTION
 *  Function to send information to UM about the currently highlighted item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_highlight_mms_message_ind(kal_uint32 msg_id, MeaFolder mea_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mmi_um_highlight_msg_ind_struct *mms_highlight_ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mms_highlight_ind_p = (mmi_um_highlight_msg_ind_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_highlight_msg_ind_struct), TD_RESET);
    mms_highlight_ind_p->msg_type = UM_MSG_TYPE_MMS;
    mms_highlight_ind_p->msg_box_type = wap_translate_mea_folder_2_um_folder(mea_box);
    mms_highlight_ind_p->msg_index = msg_id;

    /* Prepare response structure */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id	= MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND;

    /* Send Response to MMI Queue */
    ilm_ptr->local_para_ptr	= (local_para_struct *) mms_highlight_ind_p;
    ilm_ptr->peer_buff_ptr 	= NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_refresh_ind
* DESCRIPTION
*  This function is used to send mms refresh signal to MMI task for refreshing UM screen
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_refresh_ind(MeaFolder folder)
{
    UmMsgBoxType box = wap_translate_mea_folder_2_um_folder(folder);
    ilm_struct *ilm_ptr = NULL;
    mmi_um_refresh_ind_struct *um_refresh_ind = NULL;

    if(box)
    {
        um_refresh_ind = (mmi_um_refresh_ind_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_refresh_ind_struct), TD_RESET);
        um_refresh_ind->msg_type = UM_MSG_TYPE_MMS;
        um_refresh_ind->msg_box_type = box;
    
        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->msg_id			= MSG_ID_MMI_UM_REFRESH_IND;
        ilm_ptr->local_para_ptr	= (local_para_struct *) um_refresh_ind;
        ilm_ptr->peer_buff_ptr 	= NULL;
        SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    }
}


/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_ready_ind
* DESCRIPTION
*  This function is used to send mms ready signal to MMI task for enter unified message
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_ready_ind(void)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   mmi_um_ready_ind_struct *um_ready_ind = NULL;

   um_ready_ind = (mmi_um_ready_ind_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_ready_ind_struct), TD_RESET);
   um_ready_ind->result = (kal_bool) KAL_TRUE;
   um_ready_ind->msg_type = UM_MSG_TYPE_MMS;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_READY_IND;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_ready_ind;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_get_msg_num_rsp
* DESCRIPTION
*  This function is used to send mms message number signal to MMI task
*
* CALLS
*
* PARAMETERS
*  inboxUnread
*  inboxRead
*  unsent
*  sent
*  draft
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_get_msg_num_rsp(MSF_UINT16 inboxUnread, MSF_UINT16 inboxRead, MSF_UINT16 unsent, MSF_UINT16 sent, MSF_UINT16 draft
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__									  
									  , MSF_UINT16 archive
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/   									  
									  )
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   mmi_um_get_msg_num_rsp_struct *um_get_msg_num_rsp = NULL;

   um_get_msg_num_rsp = (mmi_um_get_msg_num_rsp_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_get_msg_num_rsp_struct), TD_RESET);
   um_get_msg_num_rsp->result = KAL_TRUE;
   um_get_msg_num_rsp->msg_type = UM_MSG_TYPE_MMS;
   um_get_msg_num_rsp->inbox_unread_msg_number = inboxUnread;
   um_get_msg_num_rsp->inbox_read_msg_number = inboxRead;
   um_get_msg_num_rsp->unsent_msg_number = unsent;
   um_get_msg_num_rsp->sent_msg_number = sent;
   um_get_msg_num_rsp->draft_msg_number = draft;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
   um_get_msg_num_rsp->archive_msg_number = archive;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_GET_MSG_NUM_RSP;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_get_msg_num_rsp;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_get_msg_list_rsp
* DESCRIPTION
*  This function is used to send mms list signal to MMI task
*
* CALLS
*
* PARAMETERS
*  result
*  folder
*  start
*  num
*  list
*  more
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_get_msg_list_rsp(MSF_BOOL result, MeaFolder folder, 
    MSF_UINT16 start, const MmsListOfProperties *list)
{

    int i = 0;
    MSF_UINT32 returnNo = 0;
    MSF_BOOL more = FALSE;
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   mmi_um_get_list_rsp_struct *um_get_msg_list_rsp = NULL;

   um_get_msg_list_rsp = (mmi_um_get_list_rsp_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_get_list_rsp_struct), TD_RESET);
   um_get_msg_list_rsp->result = (kal_bool)result;
   um_get_msg_list_rsp->msg_type = UM_MSG_TYPE_MMS;
   um_get_msg_list_rsp->msg_box_type = wap_translate_mea_folder_2_um_folder(folder);
   um_get_msg_list_rsp->start_entry = start;

    if(start + MMI_UM_MAX_GET_LIST_MSG_NUMBER < list->noOfElements)
    {
        returnNo = MMI_UM_MAX_GET_LIST_MSG_NUMBER;
        more = TRUE;
    }
    else
    {
        returnNo = list->noOfElements - start;
        more = FALSE;
    }

    memset(um_get_msg_list_rsp->list_info, 0x00, sizeof(mmi_um_list_info_struct) * MMI_UM_MAX_GET_LIST_MSG_NUMBER);
    for( i = 0; i < returnNo; i++)
    {
        um_get_msg_list_rsp->list_info[i].msg_index = start + i;
        um_get_msg_list_rsp->list_info[i].timestamp = list->msgPropertyList[start + i].msgFolderInfo.date;
    }

   um_get_msg_list_rsp->msg_number = returnNo;
   um_get_msg_list_rsp->more = (kal_bool)more;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_GET_LIST_RSP;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_get_msg_list_rsp;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_get_msg_info_rsp
* DESCRIPTION
*  This function is used to send mms info signal to MMI task
*
* CALLS
*
* PARAMETERS
*  result
*  folder
*  start
*  num
*  list
*  more
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_get_msg_info_rsp(MSF_BOOL result, MeaFolder folder, 
    MSF_UINT16 start, MSF_UINT16 max, const MmsListOfProperties *list)
{

    int i = 0;
    char *subject=NULL, *address=NULL;
    MSF_UINT32 returnNo = MIN(max, MMI_UM_MAX_GET_MSG_INFO_NUMBER);  /* in case */
    ilm_struct *ilm_ptr = NULL;
    mmi_um_get_msg_info_rsp_struct *um_get_msg_info_rsp = NULL;
 
    um_get_msg_info_rsp = (mmi_um_get_msg_info_rsp_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_get_msg_info_rsp_struct), TD_RESET);
    um_get_msg_info_rsp->result = (kal_bool)result;
    um_get_msg_info_rsp->msg_type = UM_MSG_TYPE_MMS;
    um_get_msg_info_rsp->msg_box_type = wap_translate_mea_folder_2_um_folder(folder);
    um_get_msg_info_rsp->start_entry = start;

    returnNo = (returnNo < list->noOfElements - start)? returnNo : (list->noOfElements - start);
    memset(um_get_msg_info_rsp->msg_info, 0x00, sizeof(mmi_um_msg_info_struct) * MMI_UM_MAX_GET_MSG_INFO_NUMBER);

    for( i = 0; i < returnNo; i++)
    {
        MmsMessageFolderInfo *msgInfo = &list->msgPropertyList[start + i].msgFolderInfo;
        MeaAddrType addrType = MEA_ADDR_TYPE_NONE;
        char *name = NULL;
        
        um_get_msg_info_rsp->msg_info[i].msg_index = start + i;
        um_get_msg_info_rsp->msg_info[i].timestamp = msgInfo->date;
        getMmsMsgSubAddr(MSF_MODID_MEA, msgInfo->msgId, &subject, &address, 250);
        addrType = meaGetAddrType(address);
        
        /* address */
        if (MEA_ADDR_TYPE_PLMN == addrType)
        {
            um_get_msg_info_rsp->msg_info[i].address_type = UM_ADDR_TYPE_PHONE_NUMBER;
            name = meaLookupNameFromPHB(address);
        }
        else if (MEA_ADDR_TYPE_EMAIL == addrType)
        {
            um_get_msg_info_rsp->msg_info[i].address_type = UM_ADDR_TYPE_EMAIL_ADDRESS;
        }

        if(name != NULL)
        {
            um_get_msg_info_rsp->msg_info[i].address_length = strlen(name);
            widget_utf8_to_ucs2_string((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].address, (MMI_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar), (const kal_uint8 *)name);
            MSF_MEM_FREE(MSF_MODID_MEA, name);
        }
        else if(address != NULL)
        {
            um_get_msg_info_rsp->msg_info[i].address_length = strlen(address);
            widget_utf8_to_ucs2_string((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].address, (MMI_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar), (const kal_uint8 *)address);
        }
        MSF_MEM_FREE(MSF_MODID_MEA, address);

        /* subject */
        if(subject != NULL)
        {
            widget_utf8_to_ucs2_string((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].subject, (MMI_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar), (const kal_uint8 *)subject);
            um_get_msg_info_rsp->msg_info[i].subject_length = widget_ucs2_length((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].subject);
            MSF_MEM_FREE(MSF_MODID_MEA, subject);
        }
        else if(msgInfo->suffix == MMS_SUFFIX_DELIVERYREPORT)
        {
            char *drSubject = (char *)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_DELIV_REPORT);
            um_get_msg_info_rsp->msg_info[i].subject_length = widget_ucs2_length((kal_uint8 *)drSubject);
            widget_ucs2_strncpy((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].subject, (kal_uint8 *)drSubject, (MMI_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
        }
        else if(msgInfo->suffix == MMS_SUFFIX_READREPORT)
        {
            char *rrSubject = (char *)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_READ_REPORT);
            um_get_msg_info_rsp->msg_info[i].subject_length = widget_ucs2_length((kal_uint8 *)rrSubject);
            widget_ucs2_strncpy((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].subject, (kal_uint8 *)rrSubject, (MMI_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
        }
        
        /* icon */
        um_get_msg_info_rsp->msg_info[i].icon_id = createImgList(msgInfo->suffix, msgInfo->read, msgInfo->forwardLock, msgInfo->priority, mmcIsJSRMsg(msgInfo->msgId));
    }

   um_get_msg_info_rsp->msg_number = returnNo;

   ilm_ptr = allocate_ilm(MOD_WAP);  /* meaLookupNameFromPHB would allocate ilm, so we do it here */
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_GET_MSG_INFO_RSP;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_get_msg_info_rsp;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);

}


/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_delete_folder_rsp
* DESCRIPTION
*  This function is used to send delete folder signal to MMI task
*
* CALLS
*
* PARAMETERS
* result
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_delete_folder_rsp(MSF_BOOL result)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   mmi_um_delete_folder_rsp_struct *um_delete_folder_rsp = NULL;

   um_delete_folder_rsp = (mmi_um_delete_folder_rsp_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_delete_folder_rsp_struct), TD_RESET);
   um_delete_folder_rsp->msg_type = UM_MSG_TYPE_MMS;
   um_delete_folder_rsp->result = (kal_bool)result;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_DELETE_FOLDER_RSP;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_delete_folder_rsp;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_new_msg_ind
* DESCRIPTION
*  This function is used to send new mms arrival signal to MMI task for informing user
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_new_msg_ind(kal_uint32 timestamp)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   mmi_um_new_msg_ind_struct *um_new_msg_ind = NULL;

   um_new_msg_ind = (mmi_um_new_msg_ind_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_new_msg_ind_struct), TD_RESET);
   um_new_msg_ind->msg_type = UM_MSG_TYPE_MMS;
   um_new_msg_ind->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
   um_new_msg_ind->msg_index = 0;
   um_new_msg_ind->timestamp = timestamp;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_NEW_MSG_IND;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_new_msg_ind;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_delete_all_ind
* DESCRIPTION
*  This function is used to send new mms arrival signal to MMI task for informing user
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_delete_all_ind(MeaFolder folder)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   mmi_um_delete_all_ind_struct *um_delete_all_ind = NULL;

   um_delete_all_ind = (mmi_um_delete_all_ind_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_delete_all_ind_struct), TD_RESET);
   um_delete_all_ind->msg_type = UM_MSG_TYPE_MMS;
   um_delete_all_ind->msg_box_type = wap_translate_mea_folder_2_um_folder(folder);
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_DELETE_ALL_IND;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_delete_all_ind;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_um_mms_msg_hdlr
* DESCRIPTION
*  This function is used to handle signal passed from UM to WAP for MMS
*
* CALLS
*
* PARAMETERS
* ilm_ptr
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_um_mms_msg_hdlr(ilm_struct *ilm_ptr)
{
    if(msm_get_module_status (MSF_MODID_MEA) != MODULE_STATUS_ACTIVE)
    {
        MSMc_startModule(MSF_MODID_MEA, NULL);
        return;
    }
    	
    switch(ilm_ptr->msg_id)
    {
        case MSG_ID_MMI_UM_GET_MSG_NUM_REQ:
        {
            MEAif_getMessageNumber(MSF_MODID_MSM);
            break;
        }

        case MSG_ID_MMI_UM_GET_LIST_REQ:
        {
            mmi_um_get_list_req_struct *local_data = (mmi_um_get_list_req_struct *) ilm_ptr->local_para_ptr;
            MeaFolder folder = wap_translate_um_folder_2_mea_folder(local_data->msg_box_type);
            if(folder != MEA_FOLDER_NONE)
            {
                MEAif_getMessageList(MSF_MODID_MSM, folder, local_data->start_entry);
            }
            break;
        }

        case MSG_ID_MMI_UM_GET_MSG_INFO_REQ:
        {
            mmi_um_get_msg_info_req_struct *local_data = (mmi_um_get_msg_info_req_struct *) ilm_ptr->local_para_ptr;
            MeaFolder folder = wap_translate_um_folder_2_mea_folder(local_data->msg_box_type);
            if(folder != MEA_FOLDER_NONE)
            {
                MEAif_getMessageInfo(MSF_MODID_MSM, folder, local_data->start_entry, local_data->msg_number);
            }
            break;
        }

        case MSG_ID_MMI_UM_DELETE_FOLDER_REQ:
        {
#ifdef __USB_IN_NORMAL_MODE__
            if(mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
            {
                wap_send_mmi_mms_delete_folder_rsp(FALSE);
            }
            else
#endif
            {
                mmi_um_delete_folder_req_struct *local_data = (mmi_um_delete_folder_req_struct *) ilm_ptr->local_para_ptr;
                MeaFolder folder = wap_translate_um_folder_2_mea_folder(local_data->msg_box_type);
                if(folder != MEA_FOLDER_NONE)
                {
                    MEAif_deleteFolder(MSF_MODID_MSM, folder);
                }
            }
            break;
        }

        case MSG_ID_MMI_UM_DELETE_ALL_RES:
        {
            break;
        }
        
        default:
			break;
    }
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_push_ready_ind
* DESCRIPTION                                                           
*  This function is used to send WAP push inbox ready indication to MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void wap_um_push_ready_ind(void)
{
    ilm_struct *ilm_ptr = NULL;
    mmi_um_ready_ind_struct *ready_ind = (mmi_um_ready_ind_struct*)construct_local_para
        ((kal_uint16)sizeof(mmi_um_ready_ind_struct), TD_RESET);		      

    /* fill local parameter */
    ready_ind->result = KAL_TRUE;
    ready_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*)ready_ind;
    ilm_ptr->msg_id         = MSG_ID_MMI_UM_READY_IND;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr)
}

/*************************************************************************
* FUNCTION                                                            
*	wap_um_new_push_msg_ind
* DESCRIPTION                                                           
*  This function is used to send WAP new push message indication to MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void wap_um_new_push_msg_ind(int msg_index, unsigned int timestamp)
{
    ilm_struct *ilm_ptr = NULL;
    mmi_um_new_msg_ind_struct *new_msg_ind = (mmi_um_new_msg_ind_struct*)construct_local_para
        ((kal_uint16)sizeof(mmi_um_new_msg_ind_struct), TD_RESET);		      

    /* fill local parameter */
    new_msg_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;
    new_msg_ind->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
    new_msg_ind->msg_index = msg_index;
    new_msg_ind->timestamp = timestamp;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*)new_msg_ind;
    ilm_ptr->msg_id         = MSG_ID_MMI_UM_NEW_MSG_IND;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr)  
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_cancel_new_push_msg_ind
* DESCRIPTION                                                           
*  This function is used to send WAP cancel new push message indication to MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void wap_um_cancel_new_push_msg_ind(void)
{
    ilm_struct *ilm_ptr = NULL;
    mmi_um_cancel_new_msg_ind_struct *cancel_new_msg_ind = (mmi_um_cancel_new_msg_ind_struct*)construct_local_para
        ((kal_uint16)sizeof(mmi_um_cancel_new_msg_ind_struct), TD_RESET);		      

    /* fill local parameter */
    cancel_new_msg_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;
    cancel_new_msg_ind->msg_box_type = UM_MSG_BOX_TYPE_INBOX;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*)cancel_new_msg_ind;
    ilm_ptr->msg_id         = MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr)  
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_get_push_msg_num_req
* DESCRIPTION                                                           
*  This function is used to handle get push message number request from unified message MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
static void wap_um_get_push_msg_num_req(local_para_struct *p)
{
    BRAif_getPushMsgNumber();
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_new_push_msg_ind
* DESCRIPTION                                                           
*  This function is used to send push message number response to MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void wap_um_get_push_msg_num_rsp(int read, int unread)
{
    ilm_struct *ilm_ptr = NULL;
    mmi_um_get_msg_num_rsp_struct *msg_num_rsp = (mmi_um_get_msg_num_rsp_struct*)construct_local_para
        ((kal_uint16)sizeof(mmi_um_get_msg_num_rsp_struct), TD_RESET);		      

    /* fill local parameter */
    msg_num_rsp->result = KAL_TRUE;
    msg_num_rsp->msg_type = UM_MSG_TYPE_WAP_PUSH;
    msg_num_rsp->inbox_unread_msg_number = (kal_uint16)unread;
    msg_num_rsp->inbox_read_msg_number = (kal_uint16)read;
	 msg_num_rsp->unsent_msg_number = 0; // useless for wap push, just fill 0 
	 msg_num_rsp->sent_msg_number = 0; // useless for wap push, just fill 0 
	 msg_num_rsp->draft_msg_number = 0; // useless for wap push, just fill 0
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ /* Added by Tony. Please Dennis help to check in. */
    msg_num_rsp->archive_msg_number = 0;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*)msg_num_rsp;
    ilm_ptr->msg_id         = MSG_ID_MMI_UM_GET_MSG_NUM_RSP;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr)  
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_get_push_msg_list_rsp
* DESCRIPTION                                                           
*  This function is used to send push message list response to MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void wap_um_get_push_msg_list_rsp(int startFromMsg, int msg_count, unsigned int *time)
{
    int i;
    ilm_struct *ilm_ptr = NULL;
    mmi_um_get_list_rsp_struct *list_rsp = (mmi_um_get_list_rsp_struct*)construct_local_para
        ((kal_uint16)sizeof(mmi_um_get_list_rsp_struct), TD_RESET);		      

    /* fill local parameter */
    list_rsp->result = KAL_TRUE;
    list_rsp->msg_type = UM_MSG_TYPE_WAP_PUSH;
    list_rsp->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
    list_rsp->start_entry = (kal_uint16)startFromMsg;
   
    /* msg_count means all push message count here, so must subtract start entry */
    msg_count -= startFromMsg; 
    if(msg_count < 0) 
        msg_count = 0;   
    /* fill msg_number with MMI_UM_MAX_GET_LIST_MSG_NUMBER if msg_count > MMI_UM_MAX_GET_LIST_MSG_NUMBER */
    list_rsp->msg_number = (kal_uint16)((msg_count>MMI_UM_MAX_GET_LIST_MSG_NUMBER)?MMI_UM_MAX_GET_LIST_MSG_NUMBER:msg_count);
    for(i = 0; i < list_rsp->msg_number; i++)
    {
        list_rsp->list_info[i].msg_index = (kal_uint16)(i+startFromMsg);
        /* seconds since 1/1 1970, GMT */
        list_rsp->list_info[i].timestamp = (kal_uint32)(*(time+i+startFromMsg));
    }
    list_rsp->more = (kal_bool)((msg_count>MMI_UM_MAX_GET_LIST_MSG_NUMBER)?KAL_TRUE:FALSE);

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*)list_rsp;
    ilm_ptr->msg_id         = MSG_ID_MMI_UM_GET_LIST_RSP;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr)  
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_get_push_msg_list_req
* DESCRIPTION                                                           
*  This function is used to handle get push message list request from unified message MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
static void wap_um_get_push_msg_list_req(local_para_struct *p)
{ 
    mmi_um_get_list_req_struct *list_req = (mmi_um_get_list_req_struct*)p;
    if(list_req->msg_box_type == UM_MSG_BOX_TYPE_INBOX)
    {
        BRAif_getPushMsgList((MSF_UINT16)(list_req->start_entry));
    }
    else
    {
        wap_um_get_push_msg_list_rsp(0, 0, NULL);
    }        
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_get_push_msg_info_req
* DESCRIPTION                                                           
*  This function is used to handle get push message info request from unified message MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
static void wap_um_get_push_msg_info_req(local_para_struct *p)
{
    mmi_um_get_msg_info_req_struct *msg_info_req = (mmi_um_get_msg_info_req_struct *)p;
    BRAif_getPushMsgInfo((MSF_UINT16)(msg_info_req->start_entry), (MSF_UINT16)(msg_info_req->msg_number));
}

/*************************************************************************
* FUNCTION                                                            
*	wap_um_get_push_msg_info_rsp
* DESCRIPTION                                                           
*  This function is used to send push message info response to MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void wap_um_get_push_msg_info_rsp(int startFromMsg, int numberOfMsg, int msg_count, 
                unsigned int *time, unsigned char **subject, unsigned char **address, unsigned int *icon_id)
{
    int i;
    ilm_struct *ilm_ptr = NULL;
    mmi_um_get_msg_info_rsp_struct *msg_info_rsp = (mmi_um_get_msg_info_rsp_struct*)construct_local_para
        ((kal_uint16)sizeof(mmi_um_get_msg_info_rsp_struct), TD_RESET);		      

    /* fill local parameter */
    msg_info_rsp->result = KAL_TRUE;
    msg_info_rsp->msg_type = UM_MSG_TYPE_WAP_PUSH;
    msg_info_rsp->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
    msg_info_rsp->start_entry = (kal_uint16)startFromMsg;
    /* msg_count means all push message count here, so must subtract start entry */
    msg_count -= startFromMsg;
    if(msg_count < 0) 
        msg_count = 0;   
    /* fill msg_number with numberOfMsg if msg_count > numberOfMsg */
    msg_info_rsp->msg_number = (kal_uint16)((msg_count>numberOfMsg)?numberOfMsg:msg_count);
    for(i = 0; i < msg_info_rsp->msg_number; i++)
    {
        msg_info_rsp->msg_info[i].msg_index = (kal_uint16)(i+startFromMsg);
        /* seconds since 1/1 1970, GMT */
        msg_info_rsp->msg_info[i].timestamp = (kal_uint32)(*(time+i+startFromMsg));
        msg_info_rsp->msg_info[i].address_type = UM_ADDR_TYPE_PHONE_NUMBER;
        /* convert UTF-8 address into UCS2 */
        if((*(address+i+startFromMsg)) == NULL)
        {
          msg_info_rsp->msg_info[i].address_length = 0;
        }
        else
        {
          msg_info_rsp->msg_info[i].address_length = (kal_uint8)widget_utf8_to_ucs2_string((kal_uint8 *)(msg_info_rsp->msg_info[i].address), MMI_UM_MAX_ADDR_LEN, (const kal_uint8*)(*(address+i+startFromMsg)));
        }
        /* convert UTF-8 subject into UCS2 */
        if((*(subject+i+startFromMsg)) == NULL)
        {
          msg_info_rsp->msg_info[i].subject_length = 0;
        }
        else
        {
        msg_info_rsp->msg_info[i].subject_length = (kal_uint8)widget_utf8_to_ucs2_string((kal_uint8 *)(msg_info_rsp->msg_info[i].subject), MMI_UM_MAX_SUBJECT_LEN, (const kal_uint8*)(*(subject+i+startFromMsg)));
        }        
        msg_info_rsp->msg_info[i].icon_id = (kal_uint16)(*(icon_id+i+startFromMsg));
    }

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*)msg_info_rsp;
    ilm_ptr->msg_id         = MSG_ID_MMI_UM_GET_MSG_INFO_RSP;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr)  
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_del_push_msg_inbox_rsp
* DESCRIPTION                                                           
*  This function is used to send push inbox deletion response to MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void wap_um_del_push_msg_inbox_rsp(void)
{
    ilm_struct *ilm_ptr = NULL;
    mmi_um_delete_folder_rsp_struct *del_folder_rsp = (mmi_um_delete_folder_rsp_struct*)construct_local_para
        ((kal_uint16)sizeof(mmi_um_delete_folder_rsp_struct), TD_RESET);		      

    /* fill local parameter */
    del_folder_rsp->msg_type = UM_MSG_TYPE_WAP_PUSH;
    del_folder_rsp->result = KAL_TRUE;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*)del_folder_rsp;
    ilm_ptr->msg_id         = MSG_ID_MMI_UM_DELETE_FOLDER_RSP;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr) 
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_del_push_msg_inbox_req
* DESCRIPTION                                                           
*  This function is used to handle delete push inbox request from unified message MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
static void wap_um_del_push_msg_inbox_req(local_para_struct *p)
{
    mmi_um_delete_folder_req_struct *delete_folder_req = (mmi_um_delete_folder_req_struct*)p;
    
    if((delete_folder_req->msg_box_type & UM_MSG_BOX_TYPE_INBOX) != 0)
    {
        BRAif_delPushMsgInbox();
    }
    else
    {
    	/* send response anyway because push only has inbox */
    	wap_um_del_push_msg_inbox_rsp();
    }
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_del_all_inbox_ind
* DESCRIPTION                                                           
*  This function is used to send delete inbox indication to MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
void wap_um_del_all_inbox_ind(void)
{
    ilm_struct *ilm_ptr = NULL;
    mmi_um_delete_all_ind_struct *del_all_ind = (mmi_um_delete_all_ind_struct*)construct_local_para
        ((kal_uint16)sizeof(mmi_um_delete_all_ind_struct), TD_RESET);		      

    /* fill local parameter */
    del_all_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;
    del_all_ind->msg_box_type = UM_MSG_BOX_TYPE_INBOX;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*)del_all_ind;
    ilm_ptr->msg_id         = MSG_ID_MMI_UM_DELETE_ALL_IND;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr) 
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_del_all_inbox_res
* DESCRIPTION                                                           
*  This function is used to handle delete all inbox response from unified message MMI
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
static void wap_um_del_all_inbox_res(local_para_struct *p)
{
    BRAif_destroyUI();
}


/*************************************************************************
* FUNCTION
*	wap_um_refresh_push_inbox_ind
* DESCRIPTION
*  This function is used to send push refresh signal to MMI task for refreshing UM screen
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_um_refresh_push_inbox_ind(void)
{
    ilm_struct *ilm_ptr = NULL;
    mmi_um_refresh_ind_struct *um_refresh_ind = NULL;

    um_refresh_ind = (mmi_um_refresh_ind_struct *) construct_local_para((kal_uint16)sizeof(mmi_um_refresh_ind_struct), TD_RESET);
    um_refresh_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;
    um_refresh_ind->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
    
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id			= MSG_ID_MMI_UM_REFRESH_IND;
    ilm_ptr->local_para_ptr	= (local_para_struct *) um_refresh_ind;
    ilm_ptr->peer_buff_ptr 	= NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*************************************************************************
* FUNCTION                                                            
*	wap_um_push_msg_hdlr
* DESCRIPTION                                                           
*  This function is the general unified message push inbox handler
* CALLS  
*                           
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
static void wap_um_push_msg_hdlr(ilm_struct *ilm_ptr)
{
    switch(ilm_ptr->msg_id)
    {
        case MSG_ID_MMI_UM_GET_MSG_NUM_REQ:
            wap_um_get_push_msg_num_req(ilm_ptr->local_para_ptr);
            break;
            
        case MSG_ID_MMI_UM_GET_LIST_REQ:
            wap_um_get_push_msg_list_req(ilm_ptr->local_para_ptr);
            break;
            
        case MSG_ID_MMI_UM_GET_MSG_INFO_REQ:
            wap_um_get_push_msg_info_req(ilm_ptr->local_para_ptr);
            break;
     
        case MSG_ID_MMI_UM_DELETE_FOLDER_REQ:
            wap_um_del_push_msg_inbox_req(ilm_ptr->local_para_ptr);
            break;

        case MSG_ID_MMI_UM_DELETE_ALL_RES:
            wap_um_del_all_inbox_res(ilm_ptr->local_para_ptr);
            break;
                    
        default:
			break;
    }   
}


/*************************************************************************
* FUNCTION
*	wap_um_msg_hdlr
* DESCRIPTION
*  This function is used to handle signal passed from UM to WAP
*
* CALLS
*
* PARAMETERS
* ilm_ptr
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_um_msg_hdlr(ilm_struct *ilm_ptr)
{
    mmi_um_generic_req_struct *p = NULL;

    if(ilm_ptr != NULL && ilm_ptr->local_para_ptr != NULL)
    {
        p = (mmi_um_generic_req_struct*)(ilm_ptr->local_para_ptr);
        
        if(p->msg_type == UM_MSG_TYPE_WAP_PUSH)
        {
            wap_um_push_msg_hdlr(ilm_ptr);
        }
        else if(p->msg_type == UM_MSG_TYPE_MMS)
        {
            wap_um_mms_msg_hdlr(ilm_ptr); 
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_highlight_decided_by_um_ind
 * DESCRIPTION
 *  send highlight need to change ind to UM when msg is deleted after sent
 * PARAMETERS
 *  msg_box_type        [IN]	UM box type
 *  msg_index			[IN]	the deleted msg index after sent 
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_send_highlight_decided_by_um_ind(MeaFolder mea_box, U16 msg_index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mmi_um_highlight_decided_by_UM_struct *mms_highlight_ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mms_highlight_ind_p = (mmi_um_highlight_decided_by_UM_struct *) 
    construct_local_para((kal_uint16)sizeof(mmi_um_highlight_msg_ind_struct), TD_RESET);
    mms_highlight_ind_p->msg_type = UM_MSG_TYPE_MMS;
    mms_highlight_ind_p->msg_box_type = wap_translate_mea_folder_2_um_folder(mea_box);
    mms_highlight_ind_p->msg_index = msg_index;

    /* Prepare response structure */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id	= MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND;

    /* Send Response to MMI Queue */
    ilm_ptr->local_para_ptr	= (local_para_struct *) mms_highlight_ind_p;
    ilm_ptr->peer_buff_ptr 	= NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

#endif
