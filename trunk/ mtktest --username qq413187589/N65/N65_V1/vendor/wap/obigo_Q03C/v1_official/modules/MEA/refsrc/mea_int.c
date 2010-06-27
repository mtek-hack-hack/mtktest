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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*!\file mea_int.c
 * Reference implementation for the mea_int.h adapter functions.
 */

/* MSF */
#include "msf_int.h"
#include "msf_log.h"
#include "msf_mem.h"
#include "msf_lib.h"

/* MEA */
#include "mea_int.h"
#include "mea_env.h"
#include "mamem.h"
#include "mea_def.h" // for UCS2_ENCODING_LENGTH
#include "mea_cfg.h"

/* others */
//#include "kal_non_specific_general_types.h"
#include "widget_extension.h"
#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGprot.h"
#include "mms_def.h"
#include "maintsig.h"
#include "mamh.h"
#include "mamv.h"
#include "wap.h"
#include "mauidia.h"
#include "mauicmn.h"
#include "msf_wid.h"
#include "mms_aApp.h"
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
/*! \file mea_int.c
 *  \brief Reference implementation for the mea_int.h adaptor functions.
 */

/******************************************************************************
 * Constants
 *****************************************************************************/
#ifdef __MMI_MMS_BGSR_SUPPORT__
kal_uint8   mmi_mms_bgsr_op;
kal_uint32  mmi_mms_bgsr_op_msg_id;
kal_uint32  mmi_mms_bgsr_download_msg_id;
kal_uint32  mmi_mms_bgsr_send_msg_id;
kal_uint8   mmi_mms_bgsr_result;
void mmi_mms_bgsr_get_msg_info_cb(U32 msg_id, mmi_mms_bgsr_msg_info_struct *msg_info);
void mmi_mms_bgsr_change_msg_cb(U32 msg_id, U8 result);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
extern char * meaLookupNameFromPHB(char * number);
extern MSF_BOOL mmcIsRecvMMSForJava(MSF_UINT32 msgId);

/*! \brief
 *
 *****************************************************************************/
void MEAa_pbLaunch(MSF_UINT16 id)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MEA_INT_81A5E807A55C6AEABE3EAEC0FC4C4A81, "(%s) (%d) MEAa_pbLaunch id = %d\n", __FILE__, __LINE__, id));

}

/*! \brief
 *
 *****************************************************************************/
void MEAa_pbCancel(void)
{
    /* Note, this is only for testing purposes. Connectors shall not normally
       be called from adaptors */
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MEA_INT_FFF817A0D8F2D1540D4103AC8C4D552F, "(%s) (%d) MEAa_phCancel\n", __FILE__, __LINE__));
}

/*! \brief
 *
 *****************************************************************************/
void MEAa_pbLookupName(MSF_UINT16 instanceId, MSF_UINT8 type, void *value)
{
    const char *name = NULL;
    MeaPbItem *item = NULL;
    MSF_UINT8 result = MEA_PB_LOOKUP_RESULT_OK;
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MEA_INT_48DC831AD0DE65B05A76F2F0DCF4F66F, "(%s) (%d) MEAa_pbLookupEntry instanceId = %d, type = %d, value = "
        "\"%s\"\n", __FILE__, __LINE__, instanceId, type, value));
	//PHB Jo 030813
	
    name = meaLookupNameFromPHB(value);

    if (name != NULL)
    {
        if (NULL == (item = MEA_ALLOC(sizeof(MeaPbItem))))
        {
            (void)MEAc_pbLookupNameRsp(MEA_PB_LOOKUP_RESULT_ERROR, instanceId, 
                item);
            return;
        }
        memset(item, 0, sizeof(MeaPbItem));
        /*lint -e{605} */
        item->name      = (char *)name;
        item->type      = (MeaPbAddrType)type;
        item->addr      = value;
    }
	else
	{
		result = MEA_PB_LOOKUP_RESULT_NO_HIT;
	}
    (void)MEAc_pbLookupNameRsp(result, instanceId, item);
    if (NULL != item)
    {
        /*lint -e{774} */
        MEA_FREE(item);
    }
}

#ifdef __MMI_MMS_BGSR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  MEAa_sendMessageReq
 * DESCRIPTION
 *  handle wap task to send the message 
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MEAa_chagneMessageReq(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */


    param = (mmi_mms_bgsr_msg_struct *)p;
    mmi_mms_bgsr_op = param->op;
    mmi_mms_bgsr_op_msg_id = param->msg_id;
    mmi_mms_bgsr_change_msg_notify( param->msg_id, 
                                    param->op, 
                                    param->folder,
                                    mmi_mms_bgsr_change_msg_cb);
    MSF_MEM_FREE(MSF_MODID_WIDGET, param);

}
/*****************************************************************************
 * FUNCTION
 *  MEAa_sendMessageReq
 * DESCRIPTION
 *  handle wap task to send the message 
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MEAa_sendMessageReq(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */


    param = (mmi_mms_bgsr_msg_struct *)p;

    mmi_mms_bgsr_send_req(param->msg_id,
                          param->is_rr,
                          param->send_setting);
    MSF_MEM_FREE(MSF_MODID_WIDGET, param);
}


/*****************************************************************************
 * FUNCTION
 *  MEAa_cancelSendMessageReq
 * DESCRIPTION
 *  handle wap task to cancel send the message 
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MEAa_cancelSendMessageReq(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    param = (mmi_mms_bgsr_msg_struct *)p;

    mmi_mms_bgsr_cancel_send_req(param->msg_id);
    MSF_MEM_FREE(MSF_MODID_WIDGET, param);
}


/*****************************************************************************
 * FUNCTION
 *  MEAa_downloadMessageReq
 * DESCRIPTION
 *  handle wap task to download the message 
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MEAa_downloadMessageReq(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    param = (mmi_mms_bgsr_msg_struct *)p;

    mmi_mms_bgsr_download_req(param->msg_id,
                              param->expire_time,
                              param->size);

    MSF_MEM_FREE(MSF_MODID_WIDGET, param);
}


/*****************************************************************************
 * FUNCTION
 *  MEAa_cancelDownloadMessageReq
 * DESCRIPTION
 *  handle wap task to cancel download the message 
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MEAa_cancelDownloadMessageReq(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    param = (mmi_mms_bgsr_msg_struct *)p;

    mmi_mms_bgsr_cancel_download_req(param->msg_id);
    MSF_MEM_FREE(MSF_MODID_WIDGET, param);
}


/*****************************************************************************
 * FUNCTION
 *  MEAa_getMessageInfo
 * DESCRIPTION
 *  handle wap task to get message info 
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MEAa_getMessageInfo(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_info_struct *param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    param = (mmi_mms_bgsr_msg_info_struct *)p;
    mmi_mms_bgsr_get_msg_info(param->msg_id, param, mmi_mms_bgsr_get_msg_info_cb);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_msg_info_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath      [IN]
 * RETURNS
 *  file size
 *****************************************************************************/
void mmi_mms_bgsr_change_msg_cb(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */
    
    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_ASSERT(msg_id == mmi_mms_bgsr_op_msg_id);
    mmi_mms_bgsr_result = result;
    switch(mmi_mms_bgsr_op)
    {
        case MMI_MMS_BGSR_OP_CANCEL_ALL_INBOX:
        {
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_CANCEL_ALL_INBOX_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr	= NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        case MMI_MMS_BGSR_OP_MOVE_TO_FOLDER:
        {
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_MOVE_TO_FOLDER_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr	= NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        case MMI_MMS_BGSR_OP_DELETE:
        {
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_DELETE_MSG_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr	= NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        case MMI_MMS_BGSR_OP_DELETE_ALL_INBOX:
        {
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_DELETE_ALL_INBOX_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr	= NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
        case MMI_MMS_BGSR_OP_DELETE_ALL_OUTBOX:            
        {
            ilm_ptr = allocate_ilm(MOD_MMI);
            ilm_ptr->msg_id = MSG_ID_MMS_BGSR_DELETE_ALL_OUTBOX_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr	= NULL;

            SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
            break;
        }
    }
	return;
    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_msg_info_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath      [IN]
 * RETURNS
 *  file size
 *****************************************************************************/
void mmi_mms_bgsr_get_msg_info_cb(U32 msg_id, mmi_mms_bgsr_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    struct ilm_struct *ilm_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_NAV_ACTIVATE_BGSR_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr	= NULL;
    
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    return;
    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_send_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath      [IN]
 * RETURNS
 *  file size
 *****************************************************************************/
void mmi_mms_send_rsp_callback(U32 msg_id, U8 result, U16 *text)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    mmi_mms_bgsr_result = result;
    mmi_mms_bgsr_send_msg_id = msg_id;
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_SEND_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
	return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_cancel_send_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath      [IN]
 * RETURNS
 *  file size
 *****************************************************************************/
void mmi_mms_cancel_send_rsp_callback(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    mmi_mms_bgsr_result = result;
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_CANCEL_SEND_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_download_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath      [IN]
 * RETURNS
 *  file size
 *****************************************************************************/
void mmi_mms_download_rsp_callback(U32 msg_id, U8 result, U16 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    mmi_mms_bgsr_result = result;    
    mmi_mms_bgsr_download_msg_id = msg_id;
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_DOWNLOAD_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
	return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_cancel_download_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath      [IN]
 * RETURNS
 *  file size
 *****************************************************************************/
void mmi_mms_cancel_download_rsp_callback(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    mmi_mms_bgsr_result = result;
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_MMS_BGSR_CANCEL_DOWNLOAD_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  wap_bgsr_msg_hdlr
 * DESCRIPTION
 *  Message Handler for primitives from BGSR
 * PARAMETERS
 *  ilm_ptr     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void wap_bgsr_msg_hdlr(ilm_struct *ilm_ptr)
{
    switch(ilm_ptr->msg_id)
    {
        case    MSG_ID_MMS_BGSR_CANCEL_SEND_RSP:
        case    MSG_ID_MMS_BGSR_CANCEL_DOWNLOAD_RSP:
        case    MSG_ID_MMS_BGSR_CANCEL_ALL_INBOX_RSP:
          meaDeleteMvStatusView();
#ifdef __UNIFIED_MSG_SUPPORT__
            /* for notification prop/Dr/Rr screen (option menu is from these screen)*/
            (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
#endif
            /* Bring down the navigation menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);

            (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
            MEA_FOLDER_NONE);
            
            break;
        case    MSG_ID_MMS_BGSR_SEND_RSP:
          meaDeleteMvStatusView();
#ifdef __UNIFIED_MSG_SUPPORT__
            /* for notification prop/Dr/Rr screen (option menu is from these screen)*/
            (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE, mmi_mms_bgsr_send_msg_id);
#endif
            /* Bring down the navigation menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);

            (void)MEA_SIGNAL_SENDTO_IUU(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
            MEA_FOLDER_NONE, mmi_mms_bgsr_send_msg_id, mmi_mms_bgsr_result);
            
            break;
        case    MSG_ID_MMS_BGSR_DOWNLOAD_RSP:
#ifdef MMS_SUPPORT
            mmcIsRecvMMSForJava(mmi_mms_bgsr_download_msg_id);
#endif            
#ifdef MMS_FILE_PROTECT_SUPPORT
            if (genChkSumFile(mmi_mms_bgsr_download_msg_id)==MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE)
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_NO_PERSISTENT_STORAGE), MEA_DIALOG_ERROR);
                fldrMgrDeleteMessage(mmi_mms_bgsr_download_msg_id);
            }
#endif /* MMS_FILE_PROTECT_SUPPORT */
          meaDeleteMvStatusView(); 
#ifdef __UNIFIED_MSG_SUPPORT__
            /* for notification prop/Dr/Rr screen (option menu is from these screen)*/
            (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE, mmi_mms_bgsr_download_msg_id);
#endif
            /* Bring down the navigation menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
            (void)MEA_SIGNAL_SENDTO_IUU(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
            MEA_FOLDER_NONE, mmi_mms_bgsr_download_msg_id, mmi_mms_bgsr_result);

            break;
        case    MSG_ID_MMS_BGSR_MOVE_TO_FOLDER_RSP:
            if(mmi_mms_bgsr_result == MMI_MMS_BGSR_RESULT_OK)
            {
                (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_BGSR_MOVE_TO_DRAFT_RSP, 
                0, mmi_mms_bgsr_op_msg_id);
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_BGSR_MOVE_TO_DRAFT_RSP, 
                1, mmi_mms_bgsr_op_msg_id);
            }
            break;
        case    MSG_ID_MMS_BGSR_NAV_ACTIVATE_BGSR_RSP:
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_ACTIVATE_BGSR_RSP);
                break;
            }
        case    MSG_ID_MMS_BGSR_DELETE_MSG_RSP:
            if(mmi_mms_bgsr_result == MMI_MMS_BGSR_RESULT_OK ||
               mmi_mms_bgsr_result == MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND )
            {
                (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_DELETE_MSG, 
                0, mmi_mms_bgsr_op_msg_id);
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_DELETE_MSG, 
                1, mmi_mms_bgsr_op_msg_id);
            }
            break;
        case    MSG_ID_MMS_BGSR_DELETE_ALL_INBOX_RSP:
#ifdef __UNIFIED_MSG_SUPPORT__
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_UM_DELETE_ALL_MSG_REQ, 
            0, MEA_FOLDER_INBOX);
#else
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_DELETE_ALL_MSG, 
            0, MEA_FOLDER_INBOX);
#endif    
            break;
        case    MSG_ID_MMS_BGSR_DELETE_ALL_OUTBOX_RSP:
#ifdef __UNIFIED_MSG_SUPPORT__
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_UM_DELETE_ALL_MSG_REQ, 
            0, MEA_FOLDER_OUTBOX);
#else
            (void)MEA_SIGNAL_SENDTO_UU(MEA_MH_FSM, MEA_SIG_MH_DELETE_ALL_MSG, 
            0, MEA_FOLDER_OUTBOX);
#endif    
            break;
        default:
			break;
    }   
}


#endif /*__MMI_MMS_BGSR_SUPPORT__*/
