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
 * mmiapi_sms.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to dispatch the message
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== *******************************************************************************/

#include "MMI_include.h"

#define MMIAPI_USING_SMS
#define MMIAPI_USING_UI
#define MMIAPI_USING_BLOCKING
#include "mmiapi_struct.h"
#include "mmiapi.h"
#include "mmiapi_func.h"

#include "ems.h"
#include "wgui_ems.h"
#include "MessagesMiscell.h"
#include "Ucs2Prot.h"
#include "WrapperGprot.h"
#include "EMSMiscell.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"
#include "PhoneBookTypes.h"
#include "PhoneBookProt.h"

/******************************************************************************************************************
  *  SMS Sending
  *
  ******************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_send_rsp
 * DESCRIPTION
 *  this function will be called when SMS sent.
 * CALLS
 *  
 * PARAMETERS
 *  msgRsp      [?]         
 *  mod_src     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_send_rsp(void *msgRsp, module_type mod_src, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mod_src != MOD_NIL);

    if (!IS_BLOCKING(mod_src))
    {
        mmiapi_sms_send_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_send_rsp_struct);

        p->result = (kal_bool)(result == MMI_FRM_SMS_OK);

        SEND_MESSAGE(MOD_MMI, mod_src, (sap_type)0, MSG_ID_MMIAPI_SMS_SEND_RSP, p, NULL);
    }

    BLOCKING_BOOLEAN_RETURN_VALUE(mod_src, (kal_bool) (result == MMI_FRM_SMS_OK));
    BLOCKING_FINISH(mod_src);

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_send_req
 * DESCRIPTION
 *  mmiapi engine will use EMS library to pack data, and send SMS
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_send_req(mmiapi_sms_send_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);

    {
        mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
        U8 length = 0;

        memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
        sendData->dcs = (U8) msg->dcs;
        sendData->dcs_class = SMSAL_CLASS1;
        sendData->sendrequire |= MMI_FRM_SMS_CLASS;

        if (msg->port_number >= 0)
        {
            sendData->desport = msg->port_number;
            sendData->srcport = msg->port_number;
            sendData->sendrequire |= MMI_FRM_SMS_PORT;
        }

        /* the sending screen should not show because the blocking mechanism of JAVA */
        sendData->sendcheck |= MMI_FRM_SMS_SCR;

        /* Do not allow empty SC address  */
        sendData->sendcheck |= MMI_FRM_SMS_NOT_ALLOW_EMPTY_SC;

        if (msg->addr.type == CSMCC_INTERNATIONAL_ADDR)
        {
            sendData->number[length] = '+';
            length++;
        }
        memcpy((S8*) & (sendData->number[length]), (S8*) msg->addr.number, strlen((S8*) msg->addr.number));
        sendData->stringlength = msg->msg_length;
        sendData->string = OslMalloc((sendData->stringlength + 1) * ENCODING_LENGTH);
        memset((S8*) sendData->string, 0, (sendData->stringlength + 1) * ENCODING_LENGTH);
        /* mmi_ucs2ncpy((S8*)sendData->string, (S8*)msg->msg, sendData->stringlength); */
        memcpy((S8*) sendData->string, (S8*) msg->msg, sendData->stringlength * ENCODING_LENGTH);
        mmi_frm_sms_send_sms(mmiapi_sms_send_rsp, mod_src, sendData);
        OslMfree(sendData);
        free_ctrl_buffer(msg->msg);
    }
}

/******************************************************************************************************************
  *  SMS application data indicate
  *
  ******************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_ind
 * DESCRIPTION
 *  when incoming store to pool, mmiapi engine will call this function
 *  to send notify to user
 * CALLS
 *  
 * PARAMETERS
 *  msg             [?]         
 *  mod_dest        [IN]        
 *  serial          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_ind(void *msg, module_type mod_dest, U16 serial)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_deliver_data_struct *data = (mmi_frm_sms_deliver_data_struct*) msg;
    mmiapi_sms_ind_struct *p = NEW_LOCAL_PTR(mmiapi_sms_ind_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->serial = (int)serial;
    p->port_number = data->dest_port;
    p->dcs = (smsal_dcs_enum) data->dcs;

    if (mod_dest == MOD_MMI)
    {   /* Wilson, temp solution to send message to MMI itself. */
        SEND_MESSAGE(MOD_WAP, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_IND, p, NULL);
    }
    else
    {
        SEND_MESSAGE(MOD_MMI, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_IND, p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_ind_with_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  mod_dest        [IN]        
 *  port            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_ind_with_data(U8 *data, module_type mod_dest, int port)
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
 *  mmiapi_sms_check_incoming_msg_rsp
 * DESCRIPTION
 *  the mmiapi check incoming message response handler
 * CALLS
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_check_incoming_msg_rsp(module_type mod_dest, int result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmiapi_sms_check_incoming_msg_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_check_incoming_msg_rsp_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->result = result;

    SEND_MESSAGE(MOD_MMI, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_CHECK_INCOMING_MSG_RSP, p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_check_incoming_msg_req
 * DESCRIPTION
 *  user can check if the incoming message arrive or not.
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_check_incoming_msg_req(mmiapi_sms_check_incoming_msg_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = -1;

    kal_uint8 index = mmi_frm_sms_get_data_index(mod_src, (U16) msg->port_number, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);

    while (index != MMI_FRM_SMS_INVALID_NUM)
    {
        if (mmi_frm_sms_check_data_complete(index))
        {
            if ((!msg->only_new) || (!mmi_frm_sms_get_data_check(index)))
            {
                break;
            }
        }
        index++;
        index = mmi_frm_sms_get_data_index(mod_src, (U16) msg->port_number, index);
    }

    if (index != MMI_FRM_SMS_INVALID_NUM)
    {
        if (msg->only_new)
        {
            mmi_frm_sms_set_data_check(index, 1);
        }
        /* always return true to JAVA, do not check data coding scheme */
        result = (mmi_frm_sms_get_dcs(MMI_FRM_SMS_APP_DATA, index) == SMSAL_8BIT_DCS) ? 1 : 0;
        /* result=1; */
    }

    BLOCKING_INT_RETURN_VALUE(mod_src, result);

    if (!IS_BLOCKING(mod_src))
    {
        mmiapi_sms_check_incoming_msg_rsp(mod_src, result);
    }

    BLOCKING_FINISH(mod_src);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_timestamp_rsp
 * DESCRIPTION
 *  the mmiapi get incoming message timestamp response handler
 * CALLS
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 *  scts            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_timestamp_rsp(module_type mod_dest, kal_uint8 *scts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_get_incoming_msg_timestamp_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_get_incoming_msg_timestamp_rsp_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scts != NULL)
    {
        memcpy(p->scts, scts, 7);
    }

    SEND_MESSAGE(MOD_MMI, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_TIMESTAMP_RSP, p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_timestamp_req
 * DESCRIPTION
 *  fetch the message timestamp
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_timestamp_req(
        mmiapi_sms_get_incoming_msg_timestamp_req_struct *msg,
        module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = mmi_frm_sms_get_data_index(mod_src, (U16) msg->port_number, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);

    if (i != MMI_FRM_SMS_INVALID_NUM)
    {
        memcpy(BLOCKING_PTR_RETURN_VALUE(mod_src), mmi_frm_sms_get_timestamp(MMI_FRM_SMS_APP_DATA, i), 7);
        if (!IS_BLOCKING(mod_src))
        {
            mmiapi_sms_get_incoming_msg_timestamp_rsp(mod_src, mmi_frm_sms_get_timestamp(MMI_FRM_SMS_APP_DATA, i));
        }
    }
    else
    {
        if (!IS_BLOCKING(mod_src))
        {
            mmiapi_sms_get_incoming_msg_timestamp_rsp(mod_src, NULL);
        }
    }
    BLOCKING_FINISH(mod_src);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_address_rsp
 * DESCRIPTION
 *  the mmiapi get incoming message address response handler
 * CALLS
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 *  oa              [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_address_rsp(module_type mod_dest, l4_addr_bcd_struct *oa)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_get_incoming_msg_address_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_get_incoming_msg_address_rsp_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (oa != NULL)
    {
        p->incoming_address = *oa;
    }

    SEND_MESSAGE(MOD_MMI, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_ADDRESS_RSP, p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_address_req
 * DESCRIPTION
 *  fetch the message address
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_address_req(mmiapi_sms_get_incoming_msg_address_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = mmi_frm_sms_get_data_index(mod_src, (U16) msg->port_number, 0);
    l4c_number_struct *addr = OslMalloc(sizeof(l4c_number_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);

    if (i != MMI_FRM_SMS_INVALID_NUM)
    {
        l4_addr_bcd_struct *addr_bcd = OslMalloc(sizeof(l4_addr_bcd_struct));

        memcpy(
            BLOCKING_PTR_RETURN_VALUE(mod_src),
            mmi_frm_sms_get_address(MMI_FRM_SMS_APP_DATA, i),
            sizeof(l4c_number_struct));
        memcpy((S8*) addr, (S8*) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_DATA, i), sizeof(l4c_number_struct));
        addr_bcd->addr_bcd[0] = addr->type;
        addr_bcd->addr_length = mmi_phb_convert_to_bcd(&(addr_bcd->addr_bcd[1]), addr->number, MAX_CC_ADDR_LEN) + 1;
        if (!IS_BLOCKING(mod_src))
        {
            mmiapi_sms_get_incoming_msg_address_rsp(mod_src, addr_bcd);
        }
        OslMfree(addr_bcd);
    }
    else
    {
        if (!IS_BLOCKING(mod_src))
        {
            mmiapi_sms_get_incoming_msg_address_rsp(mod_src, NULL);
        }
    }
    BLOCKING_FINISH(mod_src);
    OslMfree(addr);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_rsp
 * DESCRIPTION
 *  the mmiapi get incoming message response handler
 * CALLS
 *  
 * PARAMETERS
 *  mod_dest        [IN]        
 *  msg             [?]         
 *  msg_len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_rsp(module_type mod_dest, kal_uint8 *msg, int msg_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_get_incoming_msg_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_get_incoming_msg_rsp_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p->message = msg;
    p->message_len = msg_len;

    if (mod_dest == MOD_MMI)
    {   /* Wilson, temp solution to send message to MMI itself. */
        SEND_MESSAGE(MOD_WAP, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_RSP, p, NULL);
    }
    else
    {
        SEND_MESSAGE(MOD_MMI, mod_dest, (sap_type)0, MSG_ID_MMIAPI_SMS_GET_INCOMING_MSG_RSP, p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_get_incoming_msg_req
 * DESCRIPTION
 *  fetch the message
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_get_incoming_msg_req(mmiapi_sms_get_incoming_msg_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MMI could only allocate 2K control buffer, so limit the max allocate buffer to 1600 here */
    int msg_data_len =
        ((MMI_FRM_SMS_MSG_LEN * g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) <
         (MMI_FRM_SMS_MSG_LEN * 10)) ? (MMI_FRM_SMS_MSG_LEN *
                                        g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) : (MMI_FRM_SMS_MSG_LEN * 10);
    kal_uint8 *msg_data = OslMalloc(msg_data_len);
    kal_uint8 index = mmi_frm_sms_get_data_index(mod_src, (U16) msg->port_number, 0);
    mmi_frm_sms_deliver_data_struct *data = OslMalloc(sizeof(mmi_frm_sms_deliver_data_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);

    memset((S8*) msg_data, 0, msg_data_len);

    while (index != MMI_FRM_SMS_INVALID_NUM)
    {
        if (mmi_frm_sms_check_data_complete(index))
        {
            break;
        }

        index++;
        index = mmi_frm_sms_get_data_index(mod_src, (U16) msg->port_number, index);
    }

    if (index != MMI_FRM_SMS_INVALID_NUM)
    {
        mmi_frm_sms_get_data(index, data, msg_data);
        msg_data_len = data->message_len;
        mmi_frm_sms_free_data(index);
    }

    BLOCKING_PTR_RETURN_VALUE(mod_src) = (void*)msg_data;
    BLOCKING_INT_RETURN_VALUE(mod_src, msg_data_len);

    if (!IS_BLOCKING(mod_src))
    {
        mmiapi_sms_get_incoming_msg_rsp(mod_src, msg_data, msg_data_len);
    }
    BLOCKING_FINISH(mod_src);
    OslMfree(data);
}

/******************************************************************************************************************
  *  SMS register port number
  *
  ******************************************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_register_port_rsp
 * DESCRIPTION
 *  this function will be called after L4C process the sms register port number request.
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_register_port_rsp(void *msg, module_type mod_src, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_BLOCKING(mod_src))
    {
        U16 cause = *(U16*) msg;
        mmiapi_sms_register_port_rsp_struct *p = NEW_LOCAL_PTR(mmiapi_sms_register_port_rsp_struct);

        p->result = (kal_bool)(result == MMI_FRM_SMS_OK);
        p->cause = cause;
        if (mod_src == MOD_MMI)
        {   /* Wilson, temp solution to send message to MMI itself. */
            SEND_MESSAGE(MOD_WAP, mod_src, (sap_type)0, MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP, p, NULL);
        }
        else
        {
           SEND_MESSAGE(MOD_MMI, mod_src, (sap_type)0, MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP, p, NULL);
        }
    }

    BLOCKING_BOOLEAN_RETURN_VALUE(mod_src, (kal_bool) (result == MMI_FRM_SMS_OK));
    BLOCKING_FINISH(mod_src);

}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_sms_register_port_req
 * DESCRIPTION
 *  mmiapi engine will send register port number request to L4C
 * CALLS
 *  
 * PARAMETERS
 *  msg         [?]         
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_sms_register_port_req(mmiapi_sms_register_port_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);
    if (!msg->enable)
    {
        if (msg->remove_reminder_data)
        {
            mmi_frm_sms_remove_data(mod_src, (U16) msg->port_number);
        }
    }
#if !(defined(__GEMINI__) && (!defined(__SINGLE_SIM_MMI_ONLY__)))
    mmi_frm_sms_reg_port(
        mmiapi_sms_register_port_rsp,
        mod_src,
        (U16) msg->port_number,
        (BOOL) msg->enable,
        FALSE,
        mmiapi_sms_ind);
#else /* !(defined(__GEMINI__) && (!defined(__SINGLE_SIM_MMI_ONLY__))) */
	if (msg->isSlave)
	{
	    mmi_frm_sms_reg_port_for_slave(
	        mmiapi_sms_register_port_rsp,
	        mod_src,
	        (U16) msg->port_number,
	        (BOOL) msg->enable,
	        FALSE,
	        mmiapi_sms_ind);		
	}
	else
	{
	    mmi_frm_sms_reg_port(
	        mmiapi_sms_register_port_rsp,
	        mod_src,
	        (U16) msg->port_number,
	        (BOOL) msg->enable,
	        FALSE,
	        mmiapi_sms_ind);	
	}
#endif /* (!defined( __GEMINI__) && !defined(__MERCURY_MASTER__)) */
}


