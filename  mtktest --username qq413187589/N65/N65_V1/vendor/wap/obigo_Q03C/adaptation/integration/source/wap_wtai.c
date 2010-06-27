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
 * wap_create.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for WTAI function integration with Teleca Solution
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#define _FILE_CODE_  _WAP_WTAI_C_

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "app_buff_alloc.h"
#include "stack_buff_alloc.h"

#include "l4a.h"
#include "l3_inc_enums.h"
#include "soc_api.h"
#include "wap.h"
#include "app2soc_struct.h"     /* interface with application */

#include "msf_log.h"

#include "msf_int.h"
#include "msf_wid.h"
#include "msf_lib.h"
#include "msf_env.h"
#include "msf_chrs.h"

#include "bra_cfg.h"
#include "bra_int.h"
#include "bra_str.h"
#include "bra_if.h"
#include "widget_extension.h"
#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif







typedef enum
{
    WTAI_NULL,
    WTAI_MAKE_CALL_REQ,
    WTAI_WAIT_CALL_RSP
} wtai_state_enum;

typedef struct wtai_info_struct
{
    wtai_state_enum state;
    kal_uint16 Id;
    kal_uint8 modId;
    char *number;
    kal_uint8 idx;
    kal_uint8 sim_id;
} wtai_info_struct;

wtai_info_struct wtai_info;


void wtai_dial_call_req_hdlr(void);


static void wtai_send_wap_message_to_l4c(int sim_id, ilm_struct* ilm_ptr);
static void wtai_send_make_call_req(void);

#ifdef BRA_CFG_DUAL_SIM
static void wtai_handle_select_sim_result(int result, int sim_id);
#endif


extern void wap_disc_bearer_by_id(MSF_INT32 networkAccountID);


/*****************************************************************************
 * FUNCTION
 *  wtai_send_wap_message_to_l4c
 * DESCRIPTION
 *  This function is used to send message to L4C
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wtai_send_wap_message_to_l4c(int sim_id, ilm_struct* ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__
#ifdef BRA_CFG_DUAL_SIM

    if (sim_id == BRA_SIM_ID_SIM1)
    {
        SEND_ILM(MOD_WAP, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
    }
    else
    {
        SEND_ILM(MOD_WAP, MOD_L4C_2, MMI_L4C_SAP, ilm_ptr);
    }
    return;

#endif /* BRA_CFG_DUAL_SIM */
#endif /* __GEMINI__ */

    SEND_ILM(MOD_WAP, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wtai_telMakeCall
 * DESCRIPTION
 *  This function is used to implement WTAPublic.makeCall(number)
 * CALLS
 *  
 * PARAMETERS
 *  modId       [IN]
 *  sim_id      [IN]  1: SIM1 call; 2: SIM2 call; other: show select SIM menu
 *  telId       [IN]        
 *  number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wtai_telMakeSimCall(MSF_UINT8 modId, int sim_id, MSF_UINT16 telId, const char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
         WTAI_TEL_MAKE_CALL, "BRA: wtai_telMakeCall: modid=%d, telId=%d, number=%s",
         modId, telId, number == NULL ? "NULL" : number));

    if (number == NULL)
    {
        HDIc_telMakeCallResponse(modId, telId, HDI_TEL_ERROR_INVALID);
        HDIa_widgetExtShowPopup(
            MSF_MODID_MSM,
            MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_SAS_ERROR_FULL),
            MsfError,
            0);
        return;
    }

    /* save call number and telId */
    wtai_info.modId = modId;
    wtai_info.Id = telId;
    wtai_info.sim_id = 0;
    wtai_info.number = get_ctrl_buffer((kal_uint16) (strlen(number) + 1));
    strcpy(wtai_info.number, (const char*)number);


#ifdef BRA_CFG_DUAL_SIM
    if (sim_id == 1 || sim_id == 2)
    {
        if (sim_id == 1)
            wtai_info.sim_id = BRA_SIM_ID_SIM1;
        else 
            wtai_info.sim_id = BRA_SIM_ID_SIM2;
        wtai_send_make_call_req();
    }
    else
    {
        bra_sim_create_wtai_select_sim_menu(wtai_handle_select_sim_result);
    }
#else

    wtai_send_make_call_req();

#endif /* BRA_CFG_DUAL_SIM */
}


/*****************************************************************************
 * FUNCTION
 *  wtai_telMakeCall
 * DESCRIPTION
 *  This function is used to implement WTAPublic.makeCall(number)
 * CALLS, it will always show select SIM menu in dual SIM mode
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  telId       [IN]        
 *  number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wtai_telMakeCall(MSF_UINT8 modId, MSF_UINT16 telId, const char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wtai_telMakeSimCall(modId, 0, telId, number);    
}


#ifdef BRA_CFG_DUAL_SIM
/*****************************************************************************
 * FUNCTION
 *  wtai_handle_select_sim_result
 * DESCRIPTION
 *  This function is used to handle the select SIM result
 * CALLS
 *  
 * PARAMETERS
 *  result      [IN]        
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wtai_handle_select_sim_result(int result, int sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
         WTAI_HANDLE_SELECT_SIM_RESULT, "BRA: wtai_handle_select_sim_result: result=%d, sim_id=%d",
         result, sim_id));

   if (result == 0) /* cancel */
    {
        HDIc_telMakeCallResponse(wtai_info.modId, wtai_info.Id, HDI_TEL_ERROR_UNSPECIFIED);
        wtai_info.modId = MOD_NIL;
        wtai_info.Id = 0;
        if (wtai_info.number != NULL)
        {
            free_ctrl_buffer(wtai_info.number);
            wtai_info.number = NULL;
        }
    }
    else
    {
        if(sim_id == BRA_SIM_ID_NO_SIM)
            sim_id = BRA_SIM_ID_SIM1;
        wtai_info.sim_id = (kal_uint8)sim_id;
        wtai_send_make_call_req();
    }
}
#endif /* BRA_CFG_DUAL_SIM */ 


/*****************************************************************************
 * FUNCTION
 *  wtai_send_make_call_req
 * DESCRIPTION
 *  This function is used to send make call request 
 * CALLS
 *  
 * PARAMETERS
 *  sim_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wtai_send_make_call_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update wap state */
    
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
          WTAI_SEND_MAKE_CALL_REQ, "BRA: wtai_send_make_call_req: status=%d, bearer=%d, net id=%d",
          wtai_info.state, BRAa_getBearerType(), BRAif_getNetAccId()));

    wtai_info.state = WTAI_MAKE_CALL_REQ;

    if (BRAa_getBearerType() == SOC_CSD)
    {
        /* disconnect bearer if exists first, and make call after call is cleared */
        wap_disc_bearer_by_id((MSF_INT32)BRAif_getNetAccId());
    }
    else
    {
        wtai_dial_call_req_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wtai_dial_call_req_hdlr
 * DESCRIPTION
 *  This function is used to dial MO call after CSD call disconnect
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wtai_dial_call_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wtai_info.state == WTAI_MAKE_CALL_REQ)
    {
        /* send MMI dial request indication and initiate a MO call */
        ilm_struct *ilm_ptr = NULL;
        wap_dial_req_struct *dial_req_ptr = (wap_dial_req_struct*) construct_local_para
            ((kal_uint16) sizeof(wap_dial_req_struct), TD_CTRL);

        if (wtai_info.number[0] == '+')
        {
            dial_req_ptr->dest.type = CSMCC_INTERNATIONAL_ADDR;
            strcpy((char*)dial_req_ptr->dest.number, (const char*)(wtai_info.number + 1));
            dial_req_ptr->dest.length = strlen((const char*)wtai_info.number) - 1;
        }
        else
        {
            dial_req_ptr->dest.type = CSMCC_DEFAULT_ADDR_TYPE;
            strcpy((char*)dial_req_ptr->dest.number, (const char*)wtai_info.number);
            dial_req_ptr->dest.length = strlen((const char*)wtai_info.number);
        }
        dial_req_ptr->redial_count = 0;
        dial_req_ptr->call_type = CSMCC_VOICE_CALL;
        dial_req_ptr->clir_flag = CSMCC_INVALID_CLIR_INFO;

        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->local_para_ptr = (local_para_struct*) dial_req_ptr;
        ilm_ptr->msg_id = MSG_ID_WAP_DIAL_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        
        wtai_send_wap_message_to_l4c(wtai_info.sim_id, ilm_ptr);
        wtai_info.state = WTAI_WAIT_CALL_RSP;
    }

    if (wtai_info.number != NULL)
    {
        free_ctrl_buffer(wtai_info.number);
        wtai_info.number = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wtai_dial_call_rsp_hdlr
 * DESCRIPTION
 *  This function is used to handle dial call resopnse triggered by WTAI
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wtai_dial_call_rsp_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_dial_rsp_struct *dial_rsp_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dial_rsp_ptr = (wap_dial_rsp_struct*) ilm_ptr->local_para_ptr;

    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        WTAI_DIAL_CALL_RSP_HDLR, "BRA: wtai_dial_call_rsp_hdlr: call status=%d, ret=%d, cause=%d",
        wtai_info.state, dial_rsp_ptr->result.flag, dial_rsp_ptr->result.cause));

    if (wtai_info.state != WTAI_WAIT_CALL_RSP)
    {
        return;
    }

    if (dial_rsp_ptr->result.flag == L4C_OK)
    {
        HDIc_telMakeCallResponse(wtai_info.modId, wtai_info.Id, HDI_TEL_OK);
    }
    else
    {
        int result;

        /* analysis result */
        switch (dial_rsp_ptr->result.cause)
        {
            case CM_USER_BUSY:
                result = HDI_TEL_ERROR_CALLED_PARTY_IS_BUSY;
                break;
            case CM_NO_CIRCUIT_CHANNEL_AVAIL:
            case CM_TEMPORARY_FAILURE:
            case CM_REQUESTED_CKT_CHANEL_NOT_AVIL:
            case CM_RESOURCE_UNAVAIL_UNSPECIFIED:
                result = HDI_TEL_ERROR_NETWORK_NOT_AVAILABLE;
                break;
            case CM_NO_ANSWER_ON_ALERT:
                result = HDI_TEL_ERROR_CALLED_PARTY_NO_ANSWER;
                break;
            case CM_UNASSIGNED_NUM:
                result = HDI_TEL_ERROR_INVALID;
                break;
            default:
                result = HDI_TEL_ERROR_UNSPECIFIED;
                break;
        }

        HDIc_telMakeCallResponse(wtai_info.modId, wtai_info.Id, result);

        if (dial_rsp_ptr->result.flag == L4C_ERROR)
        {
            if(dial_rsp_ptr->result.cause == L4C_NO_CAUSE)
            {
                HDIa_widgetExtShowPopup(
                    MSF_MODID_MSM,
                    MSF_WIDGET_STRING_GET_PREDEFINED(SMA_STR_ID_CALL_FAILED),
                    MsfError,
                    0);
            }
            else if (dial_rsp_ptr->result.cause == L4C_CMD_CONFLICT)
            {
                HDIa_widgetExtShowPopup(
                MSF_MODID_MSM,
                MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_CALL_CONFLICT),
                MsfError,
                0);
            }
        }   
    }
}


/*****************************************************************************
 * FUNCTION
 *  wtai_telSendDtmf
 * DESCRIPTION
 *  This function is used to implement WTAPublic.sendDTMF(dtmf)
 * CALLS
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  telId       [IN]        
 *  dtmf        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wtai_telSendDtmf(MSF_UINT8 modId, MSF_UINT16 telId, const char *dtmf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern pBOOL isInCall(void);
    extern unsigned short GetWapCallPresent(void);

    ilm_struct *ilm_ptr = NULL;
    wap_start_dtmf_req_struct *dtmf_ptr;

    if (dtmf == NULL)
    {
        HDIc_telSendDtmfResponse(modId, telId, HDI_TEL_ERROR_INVALID);
        return;
    }

    if (!isInCall() || GetWapCallPresent())
    {
        HDIc_telSendDtmfResponse(modId, telId, HDI_TEL_ERROR_NO_ACTIVE_CONNECTION);
        BRAif_showDialog(MsfError, BRA_STR_NEED_ACTIVE_VOICE_CALL);
        return;
    }

    dtmf_ptr = (wap_start_dtmf_req_struct*) construct_local_para
        ((kal_uint16) sizeof(wap_start_dtmf_req_struct), TD_CTRL);

    wtai_info.Id = telId;
    wtai_info.modId = modId;
    wtai_info.number = get_ctrl_buffer((kal_uint16) (strlen(dtmf) + 1));
    strcpy(wtai_info.number, (const char*)dtmf);
    wtai_info.idx = 0;
    dtmf_ptr->digit = wtai_info.number[wtai_info.idx++];

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) dtmf_ptr;
    ilm_ptr->msg_id = MSG_ID_WAP_START_DTMF_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_L4C, MMI_L4C_SAP, ilm_ptr);

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->msg_id = MSG_ID_WAP_STOP_DTMF_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wtai_send_dtmf_rsp_hdlr
 * DESCRIPTION
 *  This function is used to handle send dtmf resopnse triggered by WTAI
 * CALLS
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wtai_send_dtmf_rsp_hdlr(local_para_struct *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* wap_start_dtmf_rsp_struct *rsp_ptr = (wap_start_dtmf_rsp_struct*)local_para_ptr;
       if(rsp_ptr->result == KAL_FALSE)
       {
       HDIc_telSendDtmfResponse (wtai_info.modId,
       wtai_info.Id, 
       HDI_TEL_ERROR_UNSPECIFIED);
       }
       else
       { */
    if (wtai_info.idx < strlen(wtai_info.number))
    {
        ilm_struct *ilm_ptr = NULL;
        wap_start_dtmf_req_struct *dtmf_ptr;

        dtmf_ptr = (wap_start_dtmf_req_struct*) construct_local_para
            ((kal_uint16) sizeof(wap_start_dtmf_req_struct), TD_CTRL);

        dtmf_ptr->digit = wtai_info.number[wtai_info.idx++];

        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->local_para_ptr = (local_para_struct*) dtmf_ptr;
        ilm_ptr->msg_id = MSG_ID_WAP_START_DTMF_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        SEND_ILM(MOD_WAP, MOD_L4C, MMI_L4C_SAP, ilm_ptr);

        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->local_para_ptr = NULL;
        ilm_ptr->msg_id = MSG_ID_WAP_STOP_DTMF_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        SEND_ILM(MOD_WAP, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
    }
    else
    {
        free_ctrl_buffer(wtai_info.number);
        wtai_info.number = NULL;
        HDIc_telSendDtmfResponse(wtai_info.modId, wtai_info.Id, HDI_TEL_OK);
    }
    /* } */
}


/*****************************************************************************
 * FUNCTION
 *  wtai_pbAddEntry
 * DESCRIPTION
 *  This function is used to implement WTAPublic.addPBEntry(number, name)
 * CALLS
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  pbId        [IN]        
 *  name        [IN]        
 *  number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wtai_pbAddEntry(MSF_UINT8 modId, MSF_UINT16 pbId, const char *name, const char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int                         i;
    int                         len;
    int                         has_utf8 = 0;
    ilm_struct                  *ilm_ptr = NULL;
    wap_set_entry_req_struct    *set_entry_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL || number == NULL)
    {
        HDIc_pbAddEntryResponse(modId, pbId, HDI_PB_ERROR_INVALID);
        return;
    }

    set_entry_ptr = (wap_set_entry_req_struct*) construct_local_para
        ((kal_uint16) sizeof(wap_set_entry_req_struct), TD_CTRL);

    wtai_info.Id = pbId;
    wtai_info.modId = modId;

    set_entry_ptr->type = PHB_PHONEBOOK;
    set_entry_ptr->no_data = 1;
    set_entry_ptr->list.storage = PHB_NVRAM;
    set_entry_ptr->list.index = 0xffff;
    set_entry_ptr->list.record_index = 0xffff;
    if (number[0] == '+')
    {
        set_entry_ptr->list.tel.type = CSMCC_INTERNATIONAL_ADDR;
        set_entry_ptr->list.tel.length = strlen(number + 1);
        strcpy((char*)&(set_entry_ptr->list.tel.number), (const char*)number + 1);
    }
    else
    {
        set_entry_ptr->list.tel.type = CSMCC_DEFAULT_ADDR_TYPE;
        set_entry_ptr->list.tel.length = strlen(number);
        strcpy((char*)&(set_entry_ptr->list.tel.number), (const char*)number);
    }

    len = strlen((const char*)name);
    for (i = 0; i < len; i++)
    {
        if (!(name[i] > 0 && name[i] <= 127))
        {
            has_utf8 = 1;            
            break;
        }
    }
    if (has_utf8 == 0)
    {
        /* ASCII */
        set_entry_ptr->list.alpha_id.name_length = strlen(name);
        set_entry_ptr->list.alpha_id.name_dcs = PHB_ASCII;
        strcpy((char*)&(set_entry_ptr->list.alpha_id.name), (const char*)name);
        
        set_entry_ptr->list.alpha_id.name[30] = 0xFF;
        set_entry_ptr->list.alpha_id.name[31] = 0;
        for (i=0; i<set_entry_ptr->list.alpha_id.name_length; i++)
        {
            if (set_entry_ptr->list.alpha_id.name[i] == 0xFF)
            {
                set_entry_ptr->list.alpha_id.name_length = i;
                memset(set_entry_ptr->list.alpha_id.name+i+1, 0, (32-i-1)*sizeof(char));
            }
        }
    }
    else
    {
        /* UTF8,convert to UCS2 */
        long srcLen = strlen(name);
        long dstLen = 30;
        kal_uint8 i;

        set_entry_ptr->list.alpha_id.name_dcs = PHB_UCS2;
        msf_charset_utf8_to_ucs2be(name, &srcLen, (char*)(set_entry_ptr->list.alpha_id.name), &dstLen);
        set_entry_ptr->list.alpha_id.name_length = dstLen;
        
        set_entry_ptr->list.alpha_id.name[28] = 0xFF;
        set_entry_ptr->list.alpha_id.name[29] = 0xFF;
        set_entry_ptr->list.alpha_id.name[30] = 0;
        set_entry_ptr->list.alpha_id.name[31] = 0;
        for (i=0; i<set_entry_ptr->list.alpha_id.name_length; i+=2)
        {
            if (set_entry_ptr->list.alpha_id.name[i] == 0xFF && set_entry_ptr->list.alpha_id.name[i+1] == 0xFF)
            {
                set_entry_ptr->list.alpha_id.name_length = i;
                memset(set_entry_ptr->list.alpha_id.name+i+2, 0, (32-i-2)*sizeof(char));
            }
        }
    }

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) set_entry_ptr;
    ilm_ptr->msg_id = MSG_ID_WAP_SET_ENTRY_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wtai_phb_add_entry_rsp_hdlr
 * DESCRIPTION
 *  This function is used to handle add phb entry response triggered by WTAI
 * CALLS
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wtai_phb_add_entry_rsp_hdlr(local_para_struct *local_para_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result;
    wap_set_entry_rsp_struct *rsp_ptr = (wap_set_entry_rsp_struct*) local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_ptr->result.flag == L4C_OK)
    {
      HDIc_pbAddEntryResponse(wtai_info.modId, wtai_info.Id, HDI_PB_OK);
    }
    else
    {
        switch (rsp_ptr->result.cause)
        {
            case PHB_ERRNO_FAIL:
            case PHB_ERRNO_BUSY:
            case PHB_ERRNO_NOT_SUPPORT:
            case PHB_ERRNO_NOT_READY:
                result = HDI_PB_ERROR_UNSPECIFIED;
                break;
        }
        HDIc_pbAddEntryResponse(wtai_info.modId, wtai_info.Id, HDI_PB_ERROR_UNSPECIFIED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_disc_bearer
 * DESCRIPTION
 *  This function is used to disconnect bearer connection
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_disc_bearer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* TBD : check if any other application is using */

    /* disconnect bearer comm. if exists */
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->msg_id = MSG_ID_APP_SOC_DEACTIVATE_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_SOC, SOC_APP_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_disc_bearer_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  networkAccountID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_disc_bearer_by_id(MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    app_soc_deactivate_req_struct *deactivate_req_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    deactivate_req_ptr = (app_soc_deactivate_req_struct*) construct_local_para
        ((kal_uint16) sizeof(app_soc_deactivate_req_struct), TD_CTRL);
    deactivate_req_ptr->account_id = networkAccountID;
    /* disconnect bearer comm. if exists */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) deactivate_req_ptr;
    ilm_ptr->msg_id = MSG_ID_APP_SOC_DEACTIVATE_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_SOC, SOC_APP_SAP, ilm_ptr);
}

