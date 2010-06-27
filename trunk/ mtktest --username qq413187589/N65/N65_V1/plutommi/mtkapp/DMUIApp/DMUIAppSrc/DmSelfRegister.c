/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*	DmSelfRegister.c
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	This file for DM Self-Register application.
*
* Author:
* -------
*	Mude Lin (MBJ06016)
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*
*****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
#include "DmSelfRegisterProt.h"
#include "DmSelfRegisterGprot.h"


/* ... Add More MMI header */
#include "CommonScreens.h"
#include "ProtocolEvents.h"

/* ...Add MSG header */
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
/*  */
#include "customer_ps_inc.h"
#include "l4c2smsal_struct.h"
#include "smsal_l4c_enum.h"
/*  */
/*  */
/*  */
/*  */
/*  */

#include "nvram_user_defs.h"

/*Mude Lin Add For DM Self-Register*/
#include "Nvram_enums.h"
#include "Nvram_interface.h"

#include "DateTimeGprot.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"
#include "app_datetime.h"

#ifdef __GEMINI__
#include "mtpnp_ad_master_common_def.h"
#include "Mtpnp_ad_master_if.h"
#endif
#include "SimDetectionGprot.h"


#ifdef __GEMINI__
extern kal_bool is_sim_replaced(kal_uint8 simInterface);
#else /* __GEMINI__ */
extern kal_bool is_sim_replaced(void);
#endif /* __GEMINI__ */

static void mmi_dm_sr_handle_sms_ready_ind(void *dummy, module_type mod, U16 result);
static MMI_BOOL mmi_dm_sr_check_cmcc_sim_card(void);
static void mmi_dm_sr_send_sms_req(void);
static void mmi_dm_sr_send_sms_rsp(void *number, module_type mod, U16 result);
static void mmi_dm_sr_read_nvram(void);
static void mmi_dm_sr_write_nvram(void);
static void mmi_dm_sr_reg_port_req(void);
static void mmi_dm_sr_reg_port_rsp(void * first, module_type mod, U16 result);
static void mmi_dm_sr_check_ack_sms(void * data, module_type mode, U16 result);
static void mmi_dm_sr_get_imsi_req(void);
static void mmi_dm_sr_get_imsi_rsp(void *inMsg);
static void mmi_dm_sr_get_imei_req(void);
static void mmi_dm_sr_get_equip_info_req(U8 equip_id);
static void mmi_dm_sr_repeat_send_sms(void);
static void mmi_dm_sr_get_content_info_req(void);
static void mmi_dm_sr_get_content_info_rsp(void *inMsg);
static void mmi_dm_sr_get_sms_common_setting_req(void);
static void mmi_dm_sr_get_sms_common_settting_rsp(void *data, module_type mod, U16 result);
static void mmi_dm_sr_reset_sms_common_setting_req(void);
static void mmi_dm_sr_reset_sms_common_setting_rsp(void *data, module_type mod, U16 result);
static void mmi_dm_sr_resume_pre_sms_common_setting_req(void);
static void mmi_dm_sr_resume_pre_sms_common_setting_rsp(void *data, module_type mod, U16 result);

static mmi_dm_sr_info_struct dm_self_reg_info;

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_init
 * DESCRIPTION
 *  DM Self-Register Application Initialize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_sr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
    E_MTPNP_AD_SIMCARD_USABLE_SIDE usableSide = MTPNP_AD_Get_UsableSide();
#endif
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_init[Function]---*\n");
	memset(&dm_self_reg_info, 0, sizeof(mmi_dm_sr_info_struct));
	dm_self_reg_info.repeat_send_sms_times = DM_SR_REPEAT_TIMES;
#ifdef __GEMINI__
    if (mmi_bootup_is_sim_valid() && (usableSide == MTPNP_AD_DUALSIM_USABLE || usableSide == MTPNP_AD_SIMCARD1_USABLE))
    {
#endif /* __GEMINI__ */
	if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) != MMI_FRM_SMS_INVALID_INDEX)
	{
		mmi_dm_sr_get_imsi_req();
	}
	else
	{
		mmi_frm_sms_reg_interrupt_check(MOD_MMI, PRT_MSG_ID_MMI_SMS_READY_IND, mmi_dm_sr_handle_sms_ready_ind);
	}
#ifdef __GEMINI__
    }
#endif /* __GEMINI__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_content_info_req
 * DESCRIPTION
 *  DM Self-Register get sms content information request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_content_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 type = dm_self_reg_info.check_get_info_type;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_content_info_req[Function] type = %d---*\n", type);	
	switch (type)
	{			
		case DM_SR_GET_IMEI_REQ:
			mmi_dm_sr_get_imei_req();
			break;
			
		case DM_SR_GET_MANUFACTOR_REQ:
			mmi_dm_sr_get_equip_info_req(0);
			break;
			
		case DM_SR_GET_DEVICE_MODEL_REQ:
			mmi_dm_sr_get_equip_info_req(1);		
			break;
			
		case DM_SR_GET_SOFTWARE_VERSION_REQ:
			mmi_dm_sr_get_equip_info_req(2);		
			break;
			
		default:
			break;					
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_content_info_rsp
 * DESCRIPTION
 *  DM Self-Register get content information response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_content_info_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 type = dm_self_reg_info.check_get_info_type;
	U8 result = FALSE;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_content_info_rsp[Function] type = %d---*\n", type);	
	switch (type)
	{
		case DM_SR_GET_IMEI_REQ:
			{
    			mmi_nw_get_imei_rsp_struct *dataPtr = (mmi_nw_get_imei_rsp_struct*) inMsg;
    			ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);

			    if (dataPtr->result == 1)
			    {
			    	result = TRUE;
			        strcpy(dm_self_reg_info.IMEI_string, (S8*) dataPtr->imei);
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_content_info_rsp[Function] dm_self_reg_info.IMEI_string = %s---*\n", dm_self_reg_info.IMEI_string);				
			    }
			}
			break;
			
		case DM_SR_GET_MANUFACTOR_REQ:
			{
			    mmi_eq_get_equip_id_rsp_struct *data_ptr = (mmi_eq_get_equip_id_rsp_struct*) inMsg;
				ClearProtocolEventHandler(MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP);

			    if (data_ptr->result == 1)
			    {
                    result = TRUE;
			        strcpy(dm_self_reg_info.manufacture_name, (S8*)data_ptr->equip_id);
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_content_info_rsp[Function] dm_self_reg_info.manufacture_name = %s---*\n", dm_self_reg_info.manufacture_name);	
				}
			    else
			    {
			        MMI_ASSERT(0);
			    }
			}
			break;
			
		case DM_SR_GET_DEVICE_MODEL_REQ:
			{
				mmi_eq_get_equip_id_rsp_struct *data_ptr = (mmi_eq_get_equip_id_rsp_struct*) inMsg;
				ClearProtocolEventHandler(MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP);

			    if (data_ptr->result == 1)
			    {
                    result = TRUE;
					strcpy(dm_self_reg_info.device_model, (S8*)data_ptr->equip_id);
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_content_info_rsp[Function] dm_self_reg_info.device_model = %s---*\n", dm_self_reg_info.device_model);	
			    }
			    else
			    {
			        MMI_ASSERT(0);
			    }
			}
			break;
			
		case DM_SR_GET_SOFTWARE_VERSION_REQ:
			{
			    mmi_eq_get_equip_id_rsp_struct *data_ptr = (mmi_eq_get_equip_id_rsp_struct*) inMsg;
				ClearProtocolEventHandler(MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP);

			    if (data_ptr->result == 1)
			    {
                    result = TRUE;
					strcpy(dm_self_reg_info.software_version, (S8*)data_ptr->equip_id);
					PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_content_info_rsp[Function] dm_self_reg_info.software_version = %s---*\n", dm_self_reg_info.software_version);	
			    }
			    else
			    {
			        MMI_ASSERT(0);
			    }
			}
			break;
			
		default:
			break;					
	}

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_content_info_rsp[Function] result = %d---*\n", result);	

	if (result == TRUE)
	{
		dm_self_reg_info.check_get_info_type++;	

		if(dm_self_reg_info.check_get_info_type < DM_SR_GET_INFO_REQ_TOTAL)
		{
			mmi_dm_sr_get_content_info_req();
		}
		else if(dm_self_reg_info.check_get_info_type == DM_SR_GET_INFO_REQ_TOTAL)
		{
			mmi_dm_sr_reg_port_req();
		}
	}	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_imsi_req
 * DESCRIPTION
 *  DM Self-Register get imsi request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_imsi_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_imsi_req[Function]---*\n");
	SetProtocolEventHandler(mmi_dm_sr_get_imsi_rsp, MSG_ID_MMI_SMU_GET_IMSI_RSP);				
	mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, MSG_ID_MMI_SMU_GET_IMSI_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_imsi_rsp
 * DESCRIPTION
 *  DM Self-Register get imsi response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_imsi_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_smu_get_imsi_rsp_struct *local_data_p = (mmi_smu_get_imsi_rsp_struct*) inMsg;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_imsi_rsp[Function]---*\n");
	ClearProtocolEventHandler(MSG_ID_MMI_SMU_GET_IMSI_RSP);

    if (local_data_p->result == 1)
    {
        memcpy(dm_self_reg_info.IMSI_number, local_data_p->imsi, DM_SR_IMSI_SIZE);
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]dm_self_reg_get_imsi_rsp[Function] dm_self_reg_info.IMSI_number = %s---*\n", dm_self_reg_info.IMSI_number);	

		if (mmi_dm_sr_check_cmcc_sim_card() == MMI_TRUE)
		{
    		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_imsi_rsp[Function]is cmcc sim card---*\n");
			mmi_dm_sr_read_nvram();

        #ifdef __GEMINI__
			if (is_sim_replaced(0) || dm_self_reg_info.is_self_reg_succuss != TRUE)
        #else /* __GEMINI__ */
			if (is_sim_replaced() || dm_self_reg_info.is_self_reg_succuss != TRUE)
        #endif /* __GEMINI__ */
			{
				mmi_dm_sr_get_content_info_req();
			}
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_check_cmcc_sim_card
 * DESCRIPTION
 *  DM Self-Register check whether the sim card is CMCC 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static MMI_BOOL mmi_dm_sr_check_cmcc_sim_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8* tmp_imsi = dm_self_reg_info.IMSI_number;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_cmcc_sim_card[Function] address = %d, Address + 1 = %d ---*\n", dm_self_reg_info.IMSI_number, (dm_self_reg_info.IMSI_number + 1));	
		
	tmp_imsi++;
	if ((strncmp(tmp_imsi, DM_SR_CMCC_OP_NUM_1, DM_SR_OP_NUM_LEN) == 0) || 
		 (strncmp(tmp_imsi, DM_SR_CMCC_OP_NUM_2, DM_SR_OP_NUM_LEN) == 0))
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_imei_req
 * DESCRIPTION
 *  DM Self-Register get IMEI request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_imei_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_imei_req[Function]---*\n");
	SetProtocolEventHandler(mmi_dm_sr_get_content_info_rsp, MSG_ID_MMI_NW_GET_IMEI_RSP);				
	mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, MSG_ID_MMI_NW_GET_IMEI_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_equip_info_req
 * DESCRIPTION
 *  DM Self-Register get equip information request
 * PARAMETERS
 *  equip_id       [IN]        equip type(manufacture name, device model, software version)
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_equip_info_req(U8 equip_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_eq_get_equip_id_req_struct* data_ptr = NULL;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_equip_info_req[Function]: equip_id = %d---*\n", equip_id);
	data_ptr = (mmi_eq_get_equip_id_req_struct* )OslConstructDataPtr(sizeof(mmi_eq_get_equip_id_req_struct));
	data_ptr->equip_type = equip_id;

	SetProtocolEventHandler(mmi_dm_sr_get_content_info_rsp, MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP);
	mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ, (oslParaType*) data_ptr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_read_nvram
 * DESCRIPTION
 *  DM Self-Register read dm reigister status before and the register destination number from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
 	ReadValue(NVRAM_DM_SELF_REGISTER_RESULT, &dm_self_reg_info.is_self_reg_succuss, DS_BYTE, &error);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_read_nvram[Function] dm_self_reg_info.is_self_reg_succuss = %d---*\n", dm_self_reg_info.is_self_reg_succuss);
	ReadRecord(NVRAM_EF_DM_SR_NUMBER_LID, 1, &dm_self_reg_info.des_number, NVRAM_EF_DM_SR_NUMBER_SIZE, &error);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_read_nvram[Function] dm_self_reg_info.des_number = %s---*\n", dm_self_reg_info.des_number);	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_write_nvram
 * DESCRIPTION
 *  DM Self-Register write the register result to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_dm_sr_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_write_nvram[Begin]---*\n");	
    WriteValue(NVRAM_DM_SELF_REGISTER_RESULT, &dm_self_reg_info.is_self_reg_succuss, DS_BYTE, &error);
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_write_nvram[Function] dm_self_reg_info.is_self_reg_succuss = %d---*\n", dm_self_reg_info.is_self_reg_succuss);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_handle_sms_ready_ind
 * DESCRIPTION
 *  DM Self-Register Function
 * PARAMETERS
 *  dummy       [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_handle_sms_ready_ind(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_handle_sms_ready_ind[Function]---*\n");
	if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) != MMI_FRM_SMS_INVALID_INDEX)
	{
		mmi_dm_sr_get_imsi_req();
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_sms_common_setting_req
 * DESCRIPTION
 *  DM Self-Register get sms common setting (status report setting) request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_get_sms_common_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_sms_common_setting_req[Function]---*\n");	
    mmi_frm_sms_get_common_settings(mmi_dm_sr_get_sms_common_settting_rsp, MOD_MMI);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_sms_common_settting_rsp
 * DESCRIPTION
 *  DM Self-Register get sms common setting response
 * PARAMETERS
 *  data        [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_get_sms_common_settting_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *DrRp = (U8*) data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_sms_common_settting_rsp[Function]result = %d---*\n", result);	
	if (result == MMI_FRM_SMS_OK)
    {
        dm_self_reg_info.pre_delivery_repy_states[0] = DrRp[0];
        dm_self_reg_info.pre_delivery_repy_states[1] = DrRp[1];
		
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_get_sms_common_settting_rsp[Function]pre_delivery_repy_states[0] = %d---*\n", dm_self_reg_info.pre_delivery_repy_states[0]);			
		if (dm_self_reg_info.pre_delivery_repy_states[0] == 1)
		{
			dm_self_reg_info.is_need_reset_delivery_states = MMI_TRUE;
			mmi_dm_sr_reset_sms_common_setting_req();
		}
		else
		{
			dm_self_reg_info.is_need_reset_delivery_states = MMI_FALSE;
			mmi_dm_sr_send_sms_req();
		}
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_reset_sms_common_setting_req
 * DESCRIPTION
 *  DM Self-Register reset the sms common setting(No status report) request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_reset_sms_common_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 DeliveryRepyStates[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_reset_sms_common_setting_req[Function]---*\n");
	DeliveryRepyStates[0] = 0;
	DeliveryRepyStates[1] = dm_self_reg_info.pre_delivery_repy_states[1];
	mmi_frm_sms_set_common_settings(mmi_dm_sr_reset_sms_common_setting_rsp, MOD_MMI, DeliveryRepyStates);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_reset_sms_common_setting_rsp
 * DESCRIPTION
 *  DM Self-Register reset the sms common setting response
 * PARAMETERS
 *  data        [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_reset_sms_common_setting_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_reset_sms_common_setting_rsp[Function]result = %d---*\n", result);	
	if (result == MMI_FRM_SMS_OK)
	{
		mmi_dm_sr_send_sms_req();
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_resume_pre_sms_common_setting_req
 * DESCRIPTION
 *  DM Self-Register resume previous sms common setting request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_resume_pre_sms_common_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_resume_pre_sms_common_setting_req[Function]---*\n"); 	
	mmi_frm_sms_set_common_settings(mmi_dm_sr_resume_pre_sms_common_setting_rsp, MOD_MMI, dm_self_reg_info.pre_delivery_repy_states);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_resume_pre_sms_common_setting_rsp
 * DESCRIPTION
 *  DM Self-Register resume previous sms common setting response
 * PARAMETERS
 *  data        [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_resume_pre_sms_common_setting_rsp(void *data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_resume_pre_sms_common_setting_rsp[Function]result = %d---*\n", result);		
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_send_sms_req
 * DESCRIPTION
 *  DM Self-Register send the register sms request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_send_sms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = NULL;
	S8* content_buffer = NULL;
	U8 content_buf_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_send_sms_req[Function]---*\n"); 	
	sendData = (mmi_frm_sms_send_struct*) OslMalloc(sizeof(mmi_frm_sms_send_struct));
	assert(sendData);
	memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));
	
	sendData->srcport = DM_SR_SCR_PORT;
	sendData->desport = DM_SR_DES_PORT;
	strcpy((S8*)sendData->number, (S8*)dm_self_reg_info.des_number);

	content_buf_len = 3 + strlen(DM_SR_SMS_HEADER) + strlen(dm_self_reg_info.IMEI_string)
						+ strlen(dm_self_reg_info.manufacture_name) + strlen(dm_self_reg_info.device_model)
						+ strlen(dm_self_reg_info.software_version);

	if (content_buf_len > DM_SR_MAX_SMS_LEN)
	{
		return;
	}
	
	sendData->stringlength = content_buf_len;

	content_buffer = (S8*)OslMalloc(content_buf_len + 1);
	assert(content_buffer);
	
	strcpy(content_buffer, (S8*)DM_SR_SMS_HEADER);
	strcat(content_buffer, dm_self_reg_info.IMEI_string);
	strcat(content_buffer, "/");
	strcat(content_buffer, dm_self_reg_info.manufacture_name);
	strcat(content_buffer, "/");	
	strcat(content_buffer, dm_self_reg_info.device_model);
	strcat(content_buffer, "/");
	strcat(content_buffer, dm_self_reg_info.software_version);

	sendData->string = (S8*)OslMalloc((sendData->stringlength + 1) * 2);
	assert(sendData->string);
	
	mmi_asc_to_ucs2((PS8)sendData->string, content_buffer);
	sendData->dcs = SMSAL_8BIT_DCS;
	sendData->sendcheck =  MMI_FRM_SMS_NOT_ALLOW_EMPTY_SC | MMI_FRM_SMS_SCR;
	sendData->sendrequire = MMI_FRM_SMS_PORT;	

#ifdef __GEMINI__
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
#endif /* __GEMINI__ */

    mmi_frm_sms_send_sms(mmi_dm_sr_send_sms_rsp, MOD_MMI, sendData);

	OslMfree(content_buffer);
	OslMfree(sendData);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_send_sms_rsp
 * DESCRIPTION
 *  DM Self-Register send the register sms response
 * PARAMETERS
 *  data        [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_send_sms_rsp(void *number, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_send_sms_rsp[Function]result = %d---*\n", result); 
	if (result == MMI_FRM_SMS_OK)
	{
		if (dm_self_reg_info.is_need_reset_delivery_states == MMI_TRUE)
		{
			mmi_dm_sr_resume_pre_sms_common_setting_req();
		}
	}
	else
	{
		if (dm_self_reg_info.repeat_send_sms_times > 0)
		{
			StartTimer(DM_SR_REPEAT_TIMER_ID, DM_SR_REPEAT_SEND_SMS_TIME, mmi_dm_sr_repeat_send_sms);
		}	
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_repeat_send_sms
 * DESCRIPTION
 *  DM Self-Register repeat send the regiser sms if failed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_repeat_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_send_sms_rsp[Function]dm_self_reg_info.repeat_send_sms_times = %d---*\n", dm_self_reg_info.repeat_send_sms_times);	
    StopTimer(DM_SR_REPEAT_TIMER_ID);
	dm_self_reg_info.repeat_send_sms_times--;
	mmi_dm_sr_send_sms_req();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_reg_port_req
 * DESCRIPTION
 *  DM Self-Register register port (the register confirm sms which form the server) request 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_reg_port_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_reg_port_req[Function]---*\n"); 	
	mmi_frm_sms_reg_port(
    mmi_dm_sr_reg_port_rsp,
    MOD_MMI,
    DM_SR_DES_PORT,
    MMI_TRUE,
    MMI_FALSE,
    mmi_dm_sr_check_ack_sms);	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_reg_port_rsp
 * DESCRIPTION
 *  DM Self-Register register port response
 * PARAMETERS
 *  data        [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_reg_port_rsp(void * data, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_reg_port_rsp[Function]result = %d---*\n", result); 
	if (result == MMI_FRM_SMS_OK)
	{
		mmi_dm_sr_get_sms_common_setting_req();
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_check_ack_sms
 * DESCRIPTION
 *  DM Self-Register check the sms which the server confirm for the register sms whether register success
 * PARAMETERS
 *  data        [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_check_ack_sms(void * data, module_type mode, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_frm_sms_deliver_data_struct  *indata = (mmi_frm_sms_deliver_data_struct*)data; 
    mmi_frm_sms_deliver_data_struct *smsdata;
    U8 *msg_content;
	U8 msg_content_len = indata->message_len;
	U8 index;
	U8 c;
	S8 imei_number[DM_SR_IMEI_SIZE];
	U8 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] message len = %d---*\n", indata->message_len);

	if (msg_content_len > 0)
	{	
	 	msg_content = OslMalloc(indata->message_len + 1);
		assert(msg_content);
		smsdata = OslMalloc(sizeof(mmi_frm_sms_deliver_data_struct));
		assert(smsdata);
		index = mmi_frm_sms_get_data_index(MOD_MMI, (U16) indata->dest_port, 0);

	    while (index != MMI_FRM_SMS_INVALID_NUM)
	    {
	        if (mmi_frm_sms_check_data_complete(index))
	        {
	            break;
	        }

	        index++;
	        index = mmi_frm_sms_get_data_index(MOD_MMI, (U16) indata->dest_port, index);
	    }

	    if (index != MMI_FRM_SMS_INVALID_NUM)
	    {
	        mmi_frm_sms_get_data(index, smsdata, msg_content);
	        mmi_frm_sms_free_data(index);
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] c = %s---*\n", msg_content);
		}
		
		c = msg_content[0];
		
		/*Skip "IMEI:"*/
		while(c != ':' && i < msg_content_len)
		{
			c = msg_content[i++];
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] c = %c---*\n", c);				
		}
		
		if (i == msg_content_len)
		{
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] i = %d---*\n", i);	
			if (smsdata != NULL)
		    {
		        OslMfree(smsdata);
		        smsdata = NULL;
		    }
		    if (msg_content != NULL)
		    {
		        OslMfree(msg_content);
		        msg_content = NULL;
		    }
			return;
		}

		c = msg_content[i];	
		while (c != '/' && (i < msg_content_len) && (j < DM_SR_IMEI_SIZE))
		{
			imei_number[j++] = c;		
			c = msg_content[++i];
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] c = %c---*\n", c);				
		}

		imei_number[j] = '\0';	

		if (i == msg_content_len)
		{
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] i = %d---*\n", i);
		    if (smsdata != NULL)
		    {
		        OslMfree(smsdata);
		        smsdata = NULL;
		    }
		    if (msg_content != NULL)
		    {
		        OslMfree(msg_content);
		        msg_content = NULL;
		    }
			return;
		}

		c = msg_content[++i];
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] c = %c---*\n", c);	

		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] dm_self_reg_info.IMEI_string = %s---*\n", dm_self_reg_info.IMEI_string);
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] imei_number = %s---*\n", imei_number);

		if (strcmp(dm_self_reg_info.IMEI_string, imei_number) == 0)
		{
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*---[DM SR]mmi_dm_sr_check_ack_sms[Function] register result = %c---*\n", c);	
			if (c == '1')
			{
				dm_self_reg_info.is_self_reg_succuss = TRUE;
			}
			else
			{
				dm_self_reg_info.is_self_reg_succuss = FALSE;
			}
		}

		mmi_dm_sr_write_nvram();

	    if (smsdata != NULL)
	    {
	        OslMfree(smsdata);
	        smsdata = NULL;
	    }
	    if (msg_content != NULL)
	    {
	        OslMfree(msg_content);
	        msg_content = NULL;
	    }
	}
}

#endif /*__MMI_DM_SELF_REGISTER_SUPPORT__*/
