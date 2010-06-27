/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSMessageDispatch.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains dispatch function for various events handled by UC,UM or MMS Application
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
 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_include.h"

#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "ProtocolEvents.h"
#include "MMSMsgCommonProt.h"
#include "UnifiedMessageGProt.h"
#include "MMSAppGprot.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_init_dispatch_functions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_init_dispatch_functions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UNIFIED_MESSAGE__
    /* UM Primitives */
    SetProtocolEventHandler(mmi_umms_get_msg_num_rsp, PRT_MSG_ID_MMI_UM_GET_MSG_NUM_RSP);
    SetProtocolEventHandler(mmi_umms_get_list_info_rsp, PRT_MSG_ID_MMI_UM_GET_LIST_RSP);
    SetProtocolEventHandler(mmi_umms_get_msg_info_rsp, PRT_MSG_ID_MMI_UM_GET_MSG_INFO_RSP);
    SetProtocolEventHandler(mmi_umms_delete_folder_rsp, PRT_MSG_ID_MMI_UM_DELETE_FOLDER_RSP);
    SetProtocolEventHandler(mmi_umms_delete_all_rsp_frm_um, PRT_MSG_ID_MMI_UM_DELETE_ALL_IND);

    /*SetProtocolEventHandler(mmi_um_handle_ready_ind, PRT_MSG_ID_MMI_UM_READY_IND);*/
    /*SetProtocolEventHandler(mmi_um_handle_new_msg_ind, PRT_MSG_ID_MMI_UM_NEW_MSG_IND);*/
    /*SetProtocolEventHandler(mmi_um_handle_highlight_msg_ind, PRT_MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND);*/
    /*SetProtocolEventHandler(mmi_um_handle_refresh_ind, PRT_MSG_ID_MMI_UM_REFRESH_IND);*/
    /*SetProtocolEventHandler(mmi_um_handle_highlight_decided_by_UM_ind, PRT_MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND);*/
    /*SetProtocolEventHandler(mmi_um_handle_cancel_new_msg_ind, PRT_MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND);*/
#endif
 /* UC Primitives */
    SetProtocolEventHandler(mmi_umms_send_mms_ind_hndlr, MSG_ID_WAP_MMA_SEND_IND);
    SetProtocolEventHandler(mmi_umms_send_mms_rsp, MSG_ID_WAP_MMA_SEND_RSP);
    SetProtocolEventHandler(mmi_umms_delete_mms_rsp, MSG_ID_WAP_MMA_DELETE_RSP);
    SetProtocolEventHandler(mmi_umms_save_mms_rsp, MSG_ID_WAP_MMA_SAVE_RSP);
    SetProtocolEventHandler(mmi_umms_cancel_send_mms_rsp, MSG_ID_WAP_MMA_CANCEL_SEND_RSP);
    SetProtocolEventHandler(mmi_umms_get_content_rsp, MSG_ID_WAP_MMA_GET_CONTENT_RSP);
    SetProtocolEventHandler(mmi_umms_create_mms_rsp, MSG_ID_WAP_MMA_CREATE_RSP);

    /*SetProtocolEventHandler(mmi_uc_start_req, MSG_ID_WAP_MMA_UC_START_REQ);*/
    /*SetProtocolEventHandler(mmi_uc_get_mms_setting_rsp, MSG_ID_WAP_MMA_GET_SETTING_RSP);*/
    /*SetProtocolEventHandler(mmi_uc_preview_mms_rsp, MSG_ID_WAP_MMA_PREVIEW_RSP);*/

    
    /* MMA Prinitves */
    SetProtocolEventHandler(mmi_umms_set_readmark_rsp, MSG_ID_WAP_MMA_SET_READMARK_RSP);
    SetProtocolEventHandler(mmi_umms_handle_set_profile_rsp, MSG_ID_WAP_MMA_SET_PROFILE_RSP);

    SetProtocolEventHandler(mmi_umms_dispatch_get_memory_status_rsp, MSG_ID_WAP_MMA_GET_MEM_STATUS_RSP);
    SetProtocolEventHandler(mmi_umms_set_mms_setting_rsp, MSG_ID_WAP_MMA_SET_SETTING_RSP);
    SetProtocolEventHandler(mmi_umms_set_data_rsp, MSG_ID_WAP_MMA_SET_APP_DATA_RSP);

    SetProtocolEventHandler(mmi_umms_get_msg_id_list_rsp, MSG_ID_WAP_MMA_GET_MSG_LIST_RSP);
    SetProtocolEventHandler(mmi_umms_dispatch_get_msg_header_info_rsp, MSG_ID_WAP_MMA_GET_MSG_INFO_RSP);

    /* ADD FOR BGSR */
    SetProtocolEventHandler(mmi_umms_download_mms_rsp, MSG_ID_WAP_MMA_DOWNLOAD_RSP);
    SetProtocolEventHandler(mmi_umms_download_mms_ind_hdlr, MSG_ID_WAP_MMA_DOWNLOAD_IND);
    SetProtocolEventHandler(mmi_umms_abort_download_mms_rsp, MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP);    
    SetProtocolEventHandler(mmi_umms_msg_is_valid_rsp, MSG_ID_WAP_MMA_MSG_IS_VALID_RSP);        
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dispatch_get_msg_header_info_rsp
 * DESCRIPTION
 *  MSG_ID_WAP_MMA_SET_PROFILE_RSP primitive from MMA
 * PARAMETERS
 *  InMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dispatch_get_msg_header_info_rsp(void *InMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_mma_get_msg_info_rsp_struct *msgInfo = (wap_mma_get_msg_info_rsp_struct*) InMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(msgInfo->app_id)
	{
#if defined (__MMI_MMS_2__)	
	case MMA_APP_ID_MMS_APP:
		mmi_umms_get_msg_header_info_rsp(InMsg);
		break;
	case MMA_APP_ID_JSR:
		mmi_jsr_get_msg_info_rsp(InMsg);
		break;
#endif /*defined (__MMI_MMS_2__)	*/
	default:
		MMI_ASSERT(0);
		break;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_handle_set_profile_rsp
 * DESCRIPTION
 *  MSG_ID_WAP_MMA_SET_PROFILE_RSP primitive from MMA
 * PARAMETERS
 *  InMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_handle_set_profile_rsp(void *InMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_profile_rsp_struct *set_profile_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_profile_rsp = (wap_mma_set_profile_rsp_struct*) InMsg;
    switch (set_profile_rsp->app_id)
    {
#if defined (__MMI_MMS_2__)	    
        case MMA_APP_ID_SETTING:
            mmi_umms_set_current_profile_rsp(InMsg);
            break;
#endif /* __MMI_MMS_2__ */
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_dispatch_get_memory_status_rsp
 * DESCRIPTION
 *  MSG_ID_WAP_MMA_GET_MEM_STATUS_RSP primitive from MMA
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_dispatch_get_memory_status_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mem_status_rsp_struct *msg = (wap_mma_get_mem_status_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg->app_id)
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_get_mem_status_rsp(inMsg);
            break;        
#endif /*__MMI_MMS_BGSR_SUPPORT__*/            

#if defined (__MMI_MMS_2__)	    
        case MMA_APP_ID_SETTING:
            mmi_umms_get_memory_status_rsp(inMsg);
            break;
        case MMA_APP_ID_MMS_APP:
            mmi_umms_receive_memory_status_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_readmark_rsp
 * DESCRIPTION
 *  MSG_ID_WAP_MMA_SET_READMARK_RSP primitive from MMA
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_readmark_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_set_readmark_rsp_struct *msg = (wap_mma_set_readmark_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg->app_id)
    {
#if defined (__MMI_MMS_2__)    
        case MMA_APP_ID_VIEWER:
            mmi_mv_set_readmark_rsp(inMsg);
            break;
        case MMA_APP_ID_MMS_APP:
            mmi_umms_readmark_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/
        default:
            ASSERT(0);
            break;
    }

}

#ifdef __MMI_UNIFIED_MESSAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_num_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_num_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_num_rsp_struct *msg = (mmi_um_get_msg_num_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg->app_id)
    {
#if defined (__MMI_UNIFIED_MESSAGE__)
        case MMA_APP_ID_UM:
            mmi_um_get_msg_num_rsp(inMsg);
            break;
#endif /*__MMI_UNIFIED_MESSAGE__*/
#if defined (__MMI_MMS_2__) 
		case MMA_APP_ID_TEMPLATE:
            mmi_umms_get_templates_num_rsp(inMsg);
            break;
        case MMA_APP_ID_MMS_APP:
            mmi_umms_get_msg_number_rsp(inMsg);
            break;
        case MMA_APP_ID_JSR:
            mmi_jsr_get_msg_num_rsp(inMsg);
            break;
        case MMA_APP_ID_SETTING:
            mmi_umms_total_mms_num_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
        default:
            MMI_ASSERT(0); 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_list_info_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_list_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_list_rsp_struct *msg = (mmi_um_get_list_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg->app_id)
    {
#if defined (__MMI_UNIFIED_MESSAGE__)
        case MMA_APP_ID_UM:
            mmi_um_get_list_info_rsp(inMsg);
            break;
#endif /*__MMI_UNIFIED_MESSAGE__*/
#if defined (__MMI_MMS_2__)
        case MMA_APP_ID_TEMPLATE:
            mmi_ummi_get_template_list_info_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/
        default:
            MMI_ASSERT(0); 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_info_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_get_msg_info_rsp_struct *msg = (mmi_um_get_msg_info_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg->app_id)
    {
#if defined (__MMI_UNIFIED_MESSAGE__)
        case MMA_APP_ID_UM:
            mmi_um_get_msg_info_rsp(inMsg);
            break;
#endif /*__MMI_UNIFIED_MESSAGE__*/
#if defined (__MMI_MMS_2__)      
        case MMA_APP_ID_TEMPLATE:
            mmi_ummi_get_template_message_info_rsp(inMsg);
            break;
        case MMA_APP_ID_MMS_APP:
            /* mmi_umms_get_msg_header_info_rsp(inMsg); */
            break;
        case MMA_APP_ID_JSR:
            mmi_jsr_get_msg_info_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_folder_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_folder_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_delete_folder_rsp_struct *msg = (mmi_um_delete_folder_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg->app_id)
    {
#if defined (__MMI_UNIFIED_MESSAGE__)
        case MMA_APP_ID_UM:
            mmi_um_delete_folder_rsp(inMsg);
            break;
#endif /*__MMI_UNIFIED_MESSAGE__*/
#if defined (__MMI_MMS_2__)   
        case MMA_APP_ID_TEMPLATE:
            mmi_umms_delete_all_template_rsp(inMsg);
            break;
        case MMA_APP_ID_MMS_APP:
            mmi_umms_delete_all_user_def_template_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
        default:
            MMI_ASSERT(0);
            break;
    }
}
#endif /* defined (__MMI_UNIFIED_MESSAGE__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_mms_setting_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_mms_setting_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_setting_rsp_struct *set_rsp = (wap_mma_set_setting_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (set_rsp->app_id)
    {
#if defined (__MMI_MMS_2__)    
        case MMA_APP_ID_SETTING:
            mmi_umms_set_setting_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
        default:
            MMI_ASSERT(0); 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_content_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_content_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *contRsp = (wap_mma_get_content_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (contRsp->app_id)
    {
#if defined (__MMI_UNIFIED_COMPOSER__)
        case MMA_APP_ID_UC:
            mmi_uc_get_mms_content_rsp(inMsg);
            break;
#endif /* __MMI_UNIFIED_COMPOSER__ */
#if defined (__MMI_MMS_2__) 

        case MMA_APP_ID_TEMPLATE:
            mmi_umms_usr_def_templ_get_msg_content_rsp(inMsg);
            break;
        case MMA_APP_ID_MMS_APP:
            mmi_umms_receive_get_content_rsp(inMsg);
            break;
        case MMA_APP_ID_JSR:
            mmi_jsr_get_msg_content_rsp(inMsg);
            break;
        case MMA_APP_ID_VIEWER:
            mmi_mv_get_mms_content_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
        default:
            MMI_ASSERT(0);
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_create_mms_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_create_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *msg_rsp = (wap_mma_create_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#if defined (__MMI_UNIFIED_COMPOSER__)
        case MMA_APP_ID_UC:
            mmi_uc_create_mms_rsp(inMsg);
            break;
#endif /* __MMI_UNIFIED_COMPOSER__ */
#if defined (__MMI_MMS_2__)  
        case MMA_APP_ID_TEMPLATE:
            mmi_umms_create_template_mms_rsp(inMsg);
            break;
        case MMA_APP_ID_MMS_APP:
            mmi_umms_create_rsp(inMsg);
            break;
        case MMA_APP_ID_JSR:
            mmi_jsr_create_mms_msg_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_mms_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#if defined (__MMI_UNIFIED_COMPOSER__)
		case MMA_APP_ID_UC:
#if defined (__MMI_MMS_2__)
            mmi_umms_hndl_save_rsp_to_uc(inMsg);
#endif /* __MMI_MMS_2__ */            
            mmi_uc_save_mms_rsp(inMsg);
            break;
#endif /*(__MMI_UNIFIED_COMPOSER__)*/
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_save_mms_rsp(inMsg);
            break;        
#endif /*__MMI_MMS_BGSR_SUPPORT__*/            
#if defined (__MMI_MMS_2__)
        case MMA_APP_ID_TEMPLATE:
            mmi_umms_save_template_mms_rsp(inMsg);
            break;
        case MMA_APP_ID_MMS_APP:
            mmi_umms_get_save_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_mms_ind_hndlr
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_mms_ind_hndlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_ind_struct *msg_ind = (wap_mma_send_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_ind->app_id)
    {
#if defined (__MMI_UNIFIED_COMPOSER__)
		case MMA_APP_ID_UC:
            mmi_uc_send_mms_ind_hdlr(inMsg);
            break;
#endif /* __MMI_UNIFIED_COMPOSER__ */
#if defined (__MMI_MMS_2__)
        case MMA_APP_ID_MMS_APP:
            mmi_umms_get_send_ind(inMsg);
            break;
        case MMA_APP_ID_JSR:    /* do nothing in JSR */
            break;
#endif /*defined (__MMI_MMS_2__)*/
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_send_mms_ind_hdlr(inMsg);
            break;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
        default:
            MMI_ASSERT(0);
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_send_mms_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_send_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *msg_rsp = (wap_mma_send_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#if defined (__MMI_UNIFIED_COMPOSER__)
        case MMA_APP_ID_UC:
            mmi_uc_send_mms_rsp(inMsg);
            break;
#endif /* __MMI_UNIFIED_COMPOSER__ */
#if defined (__MMI_MMS_2__)    
        case MMA_APP_ID_MMS_APP:
            mmi_umms_send_rsp(inMsg);
            break;
        case MMA_APP_ID_JSR:
            mmi_jsr_send_msg_rsp(inMsg);
            break;
        case MMA_APP_ID_VIEWER:
            mmi_mv_send_read_report_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_send_mms_rsp(inMsg);
            break;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
        default:
            MMI_ASSERT(0);
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_all_rsp_frm_um
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_all_rsp_frm_um(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // mmi_um_delete_all_res_struct *msg_rsp = (mmi_um_delete_all_res_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_UNIFIED_MESSAGE__)    
    mmi_um_handle_delete_all_ind(inMsg);
#endif /* defined (__MMI_MMS_2__) */    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_delete_mms_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_delete_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#if defined (__MMI_UNIFIED_COMPOSER__)
        case MMA_APP_ID_UC:
            mmi_uc_delete_mms_rsp(inMsg);
            break;
#endif /* __MMI_UNIFIED_COMPOSER__ */
#if defined (__MMI_MMS_2__)   

        case MMA_APP_ID_MMS_APP:
            mmi_umms_get_msg_delete_rsp(inMsg);
            break;
        case MMA_APP_ID_JSR:
            mmi_jsr_delete_msg_rsp(inMsg);
            break;
        case MMA_APP_ID_TEMPLATE:
            mmi_umms_delete_template_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_delete_mms_rsp(inMsg);
            break;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/            
        default:
            MMI_ASSERT(0);
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_cancel_send_mms_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_cancel_send_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#if defined (__MMI_UNIFIED_COMPOSER__)
        case MMA_APP_ID_UC:
            mmi_uc_abort_send_mms_rsp(inMsg);
            break;
#endif /* __MMI_UNIFIED_COMPOSER__ */
#if defined (__MMI_MMS_2__)    
        case MMA_APP_ID_MMS_APP:
            mmi_umms_get_cancel_rsp(inMsg);
            break;
        case MMA_APP_ID_JSR:
            mmi_jsr_cancel_send_msg_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_abort_send_mms_rsp(inMsg);
            break;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/            
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_set_data_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_set_data_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_app_data_rsp_struct *msg_rsp = (wap_mma_set_app_data_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#if defined (__MMI_MMS_2__)    
        case MMA_APP_ID_MMS_APP:
            mmi_umms_lock_mode_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_msg_id_list_rsp
 * DESCRIPTION
 *  return list of message ID's
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_get_msg_id_list_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_list_rsp_struct *msgRsp = (wap_mma_get_msg_list_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msgRsp->app_id)
    {
#if defined (__MMI_MMS_2__)    
        case MMA_APP_ID_JSR:
            mmi_jsr_get_message_list_rsp(inMsg);
            break;
#endif /*defined (__MMI_MMS_2__)*/            
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_download_mms_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_download_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_download_mms_rsp(inMsg);
            break;        
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#if defined (__MMI_MMS_2__)	
		case MMA_APP_ID_MMS_APP:
			mmi_umms_get_download_rsp(inMsg);
			break;
#endif /* __MMI_MMS_2__ */
        default:
            MMI_ASSERT(0); 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_download_mms_ind_hdlr
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_download_mms_ind_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_download_mms_ind_hdlr(inMsg);
            break;        
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#if defined (__MMI_MMS_2__)	
		case MMA_APP_ID_MMS_APP:
			mmi_umms_get_download_ind(inMsg);
			break;
#endif /* __MMI_MMS_2__ */
        default:
            MMI_ASSERT(0); 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_abort_download_mms_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_abort_download_mms_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *msg_rsp = (wap_mma_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_abort_download_mms_rsp(inMsg);
            break;        
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#if defined (__MMI_MMS_2__)	
		case MMA_APP_ID_MMS_APP:
			mmi_umms_abort_download_rsp(inMsg);
			break;
#endif /* __MMI_MMS_2__ */
        default:
            MMI_ASSERT(0); 
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_msg_is_valid_rsp
 * DESCRIPTION
 *  Decode MSG_ID_ primitive from UM
 * PARAMETERS
 *  inMsg       [?]     
 *  finMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_msg_is_valid_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_msg_is_valid_rsp_struct *msg_rsp = (wap_mma_msg_is_valid_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_rsp->app_id)
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        case MMA_APP_ID_BGSR:
            mmi_mms_bgsr_msg_is_valid_rsp(inMsg);
            break;        
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
        default:
            MMI_ASSERT(0); 
            break;
    }

}
