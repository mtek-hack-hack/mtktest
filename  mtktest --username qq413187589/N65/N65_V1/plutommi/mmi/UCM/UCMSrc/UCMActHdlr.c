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
 *  UCMActHdlr.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template source file
 *
 * Author:
 * -------
 * -------
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
#include "MMI_include.h"

#ifdef __MMI_UCM__
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "DateTimeGprot.h"

#include "App_datetime.h"
#include "AudioInc.h"
#include "CallManagementGprot.h"
#include "gpioInc.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "ProfileGprots.h"
#include "wgui_status_icons.h"
#include "PhoneBookGprot.h"
#include "BGSoundGProt.h"
#include "IdleAppProt.h"

#include "UCMResDef.h"
#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMProt.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_CC_UCM.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_VIDEO_TELEPHONY__
#include "VTResDef.h"
#include "VTGProt.h"
#include "VTProt.h"
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif

#ifdef __MMI_CH_QUICK_END__
#include "CallsGProts.h"
#endif /* __MMI_CH_QUICK_END__ */

extern void reset_call_cost_UI(void);
extern void show_call_cost_UI(PU8 symbol, PU8 value);


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pre_send_req
 * DESCRIPTION
 *  General function to prepare sending data for call applications.
 * PARAMETERS
 *  op_code         [IN]            Operation code
 *  first_ptr       [IN]            First call, usually the current active call
 *  other_ptr       [IN]            Other call, valid for compound operation
 *  dial_ptr        [IN]            Dial information, valid for MMI_UCM_DIAL and MMI_UCM_HOLD_AND_DIAL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_pre_send_req(mmi_ucm_act_opcode_enum op_code, mmi_ucm_id_info_struct *first_ptr, mmi_ucm_id_info_struct *other_ptr, mmi_ucm_dial_info_struct *dial_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_single_call_struct singleReq;
    mmi_ucm_multiple_call_struct multipleReq;
    mmi_ucm_dial_req_struct dialReq;
    mmi_ucm_hold_n_dial_req_struct holdndialReq;
    mmi_ucm_conf_req_struct confReq;
    mmi_ucm_split_req_struct splitReq;
    mmi_ucm_cd_or_ct_req_struct cdctReq;
    mmi_ucm_end_conf_req_struct endconfReq;
    mmi_ucm_end_all_req_struct endallReq;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_code)
    {
        case MMI_UCM_DIAL:
            memset(&dialReq, 0, sizeof(mmi_ucm_dial_req_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                dialReq.source_id = LMMI_SRC;

                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                dialReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }            
            dialReq.module_id = dial_ptr->module_id; 
            memcpy(dialReq.num_uri, dial_ptr->dial_num.num_uri, MMI_UCM_MAX_NUM_URI_LEN);
            mmi_ucm_send_req(op_code, first_ptr->call_type, &dialReq);
            break;
        case MMI_UCM_HOLD_AND_DIAL:
            memset(&holdndialReq, 0, sizeof(mmi_ucm_hold_n_dial_req_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                holdndialReq.source_id = LMMI_SRC;

                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                holdndialReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }            
            holdndialReq.module_id = dial_ptr->module_id;
            holdndialReq.held_uid.call_type = first_ptr->call_type;
            holdndialReq.held_uid.group_id = first_ptr->group_id;
            holdndialReq.held_uid.call_id = first_ptr->call_id;
            memcpy(holdndialReq.num_uri, dial_ptr->dial_num.num_uri, MMI_UCM_MAX_NUM_URI_LEN);
            mmi_ucm_send_req(op_code, first_ptr->call_type, &holdndialReq);
            break;
        case MMI_UCM_ACCEPT:
        case MMI_UCM_HOLD:
        case MMI_UCM_RETRIEVE:        
        case MMI_UCM_END_SINGLE:
        case MMI_UCM_FORCE_RELEASE:
        case MMI_UCM_AUTO_REJECT:
            memset(&singleReq, 0, sizeof(mmi_ucm_single_call_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                singleReq.source_id = LMMI_SRC;
                
                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                singleReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }  
            singleReq.action_uid.call_type = first_ptr->call_type;
            singleReq.action_uid.group_id = first_ptr->group_id;
            singleReq.action_uid.call_id = first_ptr->call_id;
            mmi_ucm_send_req(op_code, first_ptr->call_type, &singleReq);
            break;
        case MMI_UCM_HOLD_AND_ACCEPT:
        case MMI_UCM_SWAP:
        case MMI_UCM_EXPLICT_CALL_TRANSFER:
        case MMI_UCM_END_ACTIVE_AND_RETRIEVE:
        case MMI_UCM_END_ACTIVE_AND_ACCEPT:
            memset(&multipleReq, 0, sizeof(mmi_ucm_multiple_call_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                multipleReq.source_id = LMMI_SRC;

                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                multipleReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }
            multipleReq.active_uid.call_type = other_ptr->call_type;
            multipleReq.active_uid.group_id = other_ptr->group_id;
            multipleReq.active_uid.call_id = other_ptr->call_id;
            multipleReq.other_uid.call_type = first_ptr->call_type;
            multipleReq.other_uid.group_id = first_ptr->group_id;
            multipleReq.other_uid.call_id = first_ptr->call_id;
            mmi_ucm_send_req(op_code, first_ptr->call_type, &multipleReq);
            break;
        case MMI_UCM_CONFERENCE:
            memset(&confReq, 0, sizeof(mmi_ucm_conf_req_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                confReq.source_id = LMMI_SRC;

                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                confReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }
            confReq.active_group = first_ptr->group_id;
            confReq.held_group = other_ptr->group_id;
            mmi_ucm_send_req(op_code, first_ptr->call_type, &confReq);
            break;
        case MMI_UCM_SPLIT:
            memset(&splitReq, 0, sizeof(mmi_ucm_split_req_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                splitReq.source_id = LMMI_SRC;

                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                splitReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }
            splitReq.active_group = first_ptr->group_id;
            splitReq.split_call = first_ptr->call_id;
            mmi_ucm_send_req(op_code, first_ptr->call_type, &splitReq);
            break;
        case MMI_UCM_DEFLECT:
        case MMI_UCM_TRANSFER:
            memset(&cdctReq, 0, sizeof(mmi_ucm_cd_or_ct_req_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                cdctReq.source_id = LMMI_SRC;

                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                cdctReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }
            cdctReq.action_uid.call_type = first_ptr->call_type;
            cdctReq.action_uid.group_id = first_ptr->group_id;
            cdctReq.action_uid.call_id = first_ptr->call_id;
            memcpy(cdctReq.num_uri, dial_ptr->dial_num.num_uri, MMI_UCM_MAX_NUM_URI_LEN);
            mmi_ucm_send_req(op_code, first_ptr->call_type, &cdctReq);
            break;
        case MMI_UCM_END_CONFERENCE:
            memset(&endconfReq, 0, sizeof(mmi_ucm_end_conf_req_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                endconfReq.source_id = LMMI_SRC;

                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                endconfReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }
            endconfReq.action_group = first_ptr->group_id;
            mmi_ucm_send_req(op_code, first_ptr->call_type, &endconfReq);
            break;
        case MMI_UCM_END_ALL:
            memset(&endallReq, 0, sizeof(mmi_ucm_end_all_req_struct));
            /* source id of csd / data call must be LMMI, because L4C cannot handle RMMI case */
            if (first_ptr->call_type & MMI_UCM_CALL_TYPE_DATA_CSD_ALL)
            {
                endallReq.source_id = LMMI_SRC;

                if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
                    (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
                {
                    g_ucm_p->call_misc.no_rcode_count++;
                }
            }
            else
            {
                endallReq.source_id = g_ucm_p->call_misc.l4c_info.l4c_source;
            }
            mmi_ucm_send_req(op_code, first_ptr->call_type, &endallReq);
            break;
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_send_req
 * DESCRIPTION
 *  General function to send data to call applications.
 * PARAMETERS
 *  op_code         [IN]            Operation code
 *  call_type       [IN]            Call type
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_send_req(mmi_ucm_act_opcode_enum op_code, mmi_ucm_call_type_enum call_type, void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_code)
    {
        case MMI_UCM_DIAL:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_DIAL, act_struct);
            }            
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_DIAL, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_DIAL, act_struct);
            }
        #endif /* __MMI_VOIP__ */        
        #ifdef __MMI_VIDEO_TELEPHONY__
            else if (call_type == MMI_UCM_VIDEO_CALL_TYPE)
            {
                mmi_vt_ucm_act_req(MMI_UCM_DIAL, act_struct);
            }
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_HOLD_AND_DIAL:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_HOLD_AND_DIAL, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_HOLD_AND_DIAL, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_HOLD_AND_DIAL, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
        
        case MMI_UCM_ACCEPT:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_ACCEPT, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_ACCEPT, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_ACCEPT, act_struct);
            }
        #endif /* __MMI_VOIP__ */
        #ifdef __MMI_VIDEO_TELEPHONY__
            else if (call_type == MMI_UCM_VIDEO_CALL_TYPE)
            {
                mmi_vt_ucm_act_req(MMI_UCM_ACCEPT, act_struct);
            }
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_HOLD_AND_ACCEPT:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_HOLD_AND_ACCEPT, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_HOLD_AND_ACCEPT, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_HOLD_AND_ACCEPT, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_HOLD:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_HOLD, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_HOLD, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_HOLD, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_RETRIEVE:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_RETRIEVE, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_RETRIEVE, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_RETRIEVE, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_SWAP:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_SWAP, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_SWAP, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_SWAP, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_CONFERENCE:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_CONFERENCE, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_CONFERENCE, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_CONFERENCE, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_SPLIT:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_SPLIT, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_SPLIT, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_SPLIT, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_DEFLECT:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_DEFLECT, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_DEFLECT, act_struct);                
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_TRANSFER:
        #ifdef __MMI_VOIP__
            if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_TRANSFER, act_struct);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_END_SINGLE:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_END_SINGLE, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_END_SINGLE, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_END_SINGLE, act_struct);
            }
        #endif /* __MMI_VOIP__ */
        #ifdef __MMI_VIDEO_TELEPHONY__
            else if (call_type == MMI_UCM_VIDEO_CALL_TYPE)
            {
                mmi_vt_ucm_act_req(MMI_UCM_END_SINGLE, act_struct);
            }
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_END_CONFERENCE:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_END_CONFERENCE, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_END_CONFERENCE, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_END_CONFERENCE, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_END_ALL:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_END_ALL, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_END_ALL, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_END_ALL, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_FORCE_RELEASE:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_FORCE_RELEASE, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_FORCE_RELEASE, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_FORCE_RELEASE, act_struct);
            }
        #endif /* __MMI_VOIP__ */
        #ifdef __MMI_VIDEO_TELEPHONY__
            else if (call_type == MMI_UCM_VIDEO_CALL_TYPE)
            {
                mmi_vt_ucm_act_req(MMI_UCM_FORCE_RELEASE, act_struct);
            }
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_AUTO_REJECT:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_AUTO_REJECT, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_AUTO_REJECT, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_AUTO_REJECT, act_struct);
            }
        #endif /* __MMI_VOIP__ */
        #ifdef __MMI_VIDEO_TELEPHONY__
            else if (call_type == MMI_UCM_VIDEO_CALL_TYPE)
            {
                mmi_vt_ucm_act_req(MMI_UCM_AUTO_REJECT, act_struct);
            }
        #endif /* __MMI_VIDEO_TELEPHONY__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_EXPLICT_CALL_TRANSFER:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_EXPLICT_CALL_TRANSFER, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_EXPLICT_CALL_TRANSFER, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_END_ACTIVE_AND_RETRIEVE:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_END_ACTIVE_AND_RETRIEVE, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_END_ACTIVE_AND_RETRIEVE, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_END_ACTIVE_AND_ACCEPT:
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_END_ACTIVE_AND_ACCEPT, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__                        
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_END_ACTIVE_AND_ACCEPT, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_START_DTMF:

            g_ucm_p->call_misc.dtmf.digit = ((mmi_ucm_dtmf_struct*)act_struct)->digit;
            g_ucm_p->call_misc.dtmf.call_type = call_type;
            g_ucm_p->call_misc.is_dtmf_start = MMI_TRUE;
            
            if(call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_START_DTMF, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if(call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_START_DTMF, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_START_DTMF, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        case MMI_UCM_STOP_DTMF:
            
            g_ucm_p->call_misc.is_dtmf_start = MMI_FALSE;
            
            if (call_type & MMI_UCM_SIM1_CALL_TYPE_ALL)
            {
                mmi_gsm_ucm_act_req(MMI_UCM_STOP_DTMF, act_struct);
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
            {
                MTPNP_PFAL_ucm_act_req(MMI_UCM_STOP_DTMF, act_struct);
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        #ifdef __MMI_VOIP__
            else if (call_type == MMI_UCM_VOIP_CALL_TYPE)
            {
                mmi_voip_ucm_act_req(MMI_UCM_STOP_DTMF, act_struct);
            }
        #endif /* __MMI_VOIP__ */
            else
            {
                MMI_ASSERT(0);
            }
            break;
            
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_send_msg
 * DESCRIPTION
 *  General function to send message to other task.
 * PARAMETERS
 *  module_src      [IN]            Source module
 *  module_dest     [IN]            Destination module
 *  msg_id          [IN]            Message id
 *  local_para      [IN]            Local parameter
 *  peer_buff       [IN]            Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_send_msg(module_type module_src, module_type module_dest, U16 msg_id, void *local_para, void *peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = module_src;
    Message.oslDestId = module_dest;
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = local_para;
    Message.oslPeerBuffPtr = peer_buff;

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dispatch_rsp
 * DESCRIPTION
 *  Dispatch response coming from call applications.
 * PARAMETERS
 *  op_code         [IN]            Operation code
 *  call_type       [IN]            Call type
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dispatch_rsp(mmi_ucm_act_opcode_enum op_code, mmi_ucm_call_type_enum call_type, void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_code)
    {
        case MMI_UCM_DIAL:
        case MMI_UCM_HOLD_AND_DIAL:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_rsp] DIAL_ACT_RSP\n");
            mmi_ucm_dial_act_rsp(act_struct);
            break;
        case MMI_UCM_ACCEPT:
        case MMI_UCM_HOLD_AND_ACCEPT:
        case MMI_UCM_END_ACTIVE_AND_ACCEPT:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_rsp] ACCEPT_ACT_RSP\n");
            mmi_ucm_accept_act_rsp(act_struct);
            break;
        case MMI_UCM_HOLD:
        case MMI_UCM_RETRIEVE:
        case MMI_UCM_SWAP:
        case MMI_UCM_CONFERENCE:
        case MMI_UCM_SPLIT:
        case MMI_UCM_DEFLECT:
        case MMI_UCM_TRANSFER:            
        case MMI_UCM_EXPLICT_CALL_TRANSFER:
        case MMI_UCM_END_ACTIVE_AND_RETRIEVE:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_rsp] ACT_RSP\n");
            mmi_ucm_act_rsp(act_struct);
            break;
        case MMI_UCM_END_SINGLE:
        case MMI_UCM_END_CONFERENCE:
        case MMI_UCM_END_ALL:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_rsp] END_ACT_RSP\n");
            mmi_ucm_end_act_rsp(act_struct);
            break;
        case MMI_UCM_FORCE_RELEASE: /* no response */
        case MMI_UCM_AUTO_REJECT: /* no response */
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_act_rsp
 * DESCRIPTION
 *  Handler for dial action response. No success popup but screen will adjust.
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dial_act_rsp(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 groupIndex = 0, callIndex = 0;
    mmi_ucm_id_info_struct actionId;
    mmi_ucm_dial_act_rsp_struct *rsp = (mmi_ucm_dial_act_rsp_struct*)act_struct;
    U8 tone_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->mo_info.is_wait_dial = FALSE;
    if (rsp->result_info.result == TRUE)
    {
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {
            if (g_ucm_p->call_misc.no_rcode_count == 0)
            {
                PRINT_INFORMATION("\n[mmi_ucm_dial_act_rsp] Dial OK!\n");
                mmi_ucm_at_general_req(g_ucm_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, MMI_UCM_INVALID_ID, &g_ucm_p->call_misc.l4c_info);
                memset(&g_ucm_p->call_misc.l4c_info, 0, sizeof(mmi_ucm_l4c_info_struct));
                g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
            }
            else
            {
                g_ucm_p->call_misc.no_rcode_count--;
            }
        }

        /* update invalid id entry */
        mmi_ucm_sync_call_list(rsp->call_list);

        memcpy(&g_ucm_p->mo_mt_display, &rsp->alert_info, sizeof(mmi_ucm_ring_info_struct));

        mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_COMP_PROCESS_STATE);
        if (mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0)
        {
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            callIndex = g_ucm_p->call_misc.index_list[0].call_index;
            mmi_ucm_set_process_state(groupIndex, -1, MMI_UCM_WAIT_PROCESS_STATE, MMI_UCM_DO_PROCESS_STATE);
            actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
            actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
            actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;
            mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, &g_ucm_p->mo_info);
        }
        else
        {
            mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
            /* go back to outgoing screen with updated information */
            mmi_ucm_go_back_screen_check();
        }

        if (g_ucm_p->call_list.num_group == 1)
        {
            AlmDisableExpiryHandler();
            /* do not suspend background audio for csd call */
            if (mmi_ucm_app_outgoing_call(MMI_UCM_CSD_CALL_TYPE_ALL) == 0)
            {
                mdi_audio_suspend_background_play();
            }
        }                
    }
    else
    {
        /* no matter what the no_rcode_count is, send back the result code because the action terminated */
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {
            PRINT_INFORMATION("\n[mmi_ucm_dial_act_rsp] Dial Fail!\n");
            mmi_ucm_at_general_req(g_ucm_p->call_misc.curr_module, RMMI_UCM_RCODE_NO_CARRIER, MMI_UCM_INVALID_ID, &g_ucm_p->call_misc.l4c_info);
            memset(&g_ucm_p->call_misc.l4c_info, 0, sizeof(mmi_ucm_l4c_info_struct));
            g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
            g_ucm_p->call_misc.no_rcode_count = 0;
        }
        
        /* clear invalid id entry */
        mmi_ucm_sync_call_list(rsp->call_list);
        
        if (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0)
        {
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            /* call application does not have this call yet, so cannot rely on call list of call application */
            if (g_ucm_p->call_list.group_info[groupIndex].call_info[0].proc_state == MMI_UCM_WAIT_PROCESS_STATE)
            {
                g_ucm_p->call_list.group_info[groupIndex].num_call--;
                g_ucm_p->call_list.num_group--;
                mmi_ucm_reset_group_entry(groupIndex);
            }
        }
        
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_WAIT_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);

        if (rsp->result_info.error_msg != NULL) /* ss does not have error message */
        {
            tone_id = mmi_ucm_get_error_tone();
            
            DisplayPopup(
                rsp->result_info.error_msg,
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                tone_id);
        }        

        /* go back to corresponding screen */
        mmi_ucm_go_back_screen_check();
    }

    mmi_phb_call_set_dial_from_list(MMI_PHB_NONE);  /* reset dial from phonebook flag */
    CHISTSetDialFromCallLogFlag(0);                 /* reset dial from call history flag */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_accept_act_rsp
 * DESCRIPTION
 *  Handler for accept action response. No success popup but screen will adjust.
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_accept_act_rsp(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 groupIndex = 0, callIndex = 0;
    mmi_ucm_id_info_struct actionId;
    mmi_ucm_act_rsp_struct *rsp = (mmi_ucm_act_rsp_struct*)act_struct;
#ifdef __MMI_CH_QUICK_END__
    U16 quickEndDuration = CHISTGetQuickEndTime();
#endif /* __MMI_CH_QUICK_END__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result_info.result == TRUE &&
        mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1)
    {
        /* received call log */        
        groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
        DTGetRTCTime(&g_ucm_p->call_list.group_info[groupIndex].call_info[0].start_time);        
        /* do not log call history for SAT call */
        if (g_ucm_p->call_list.group_info[groupIndex].call_info[0].module_id != MMI_UCM_FROM_SAT)
        {
            mmi_ucm_log_call_history(groupIndex, 0, TRUE);
        }

        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {
            if (g_ucm_p->call_misc.no_rcode_count == 0)
            {
                PRINT_INFORMATION("\n[mmi_ucm_accept_act_rsp] Accept OK!\n");
                mmi_ucm_at_general_req(g_ucm_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
                memset(&g_ucm_p->call_misc.l4c_info, 0, sizeof(mmi_ucm_l4c_info_struct));
                g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
            }
            else
            {
                g_ucm_p->call_misc.no_rcode_count--;
            }
        }

        mmi_ucm_sync_call_list(rsp->call_list);

        mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_COMP_PROCESS_STATE);
        if (mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0)
        {
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            callIndex = g_ucm_p->call_misc.index_list[0].call_index;
            mmi_ucm_set_process_state(groupIndex, -1, MMI_UCM_WAIT_PROCESS_STATE, MMI_UCM_DO_PROCESS_STATE);
            actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
            actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
            actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;
            mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, &g_ucm_p->mo_info);
        }
        else
        {
            mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);            
            mmi_ucm_go_back_screen_check();
        }

#ifdef __MMI_CH_QUICK_END__
        if (IsMyTimerExist(CM_AUTO_QUICK_END_TIMER) == FALSE &&
            quickEndDuration > 0 && 
            mmi_ucm_app_active_call(MMI_UCM_VOICE_CALL_TYPE_ALL) > 0 &&
            mmi_ucm_emergency_call_present() == MMI_FALSE)
        {    
            PRINT_INFORMATION("QuickEndTime:%d",quickEndDuration);
            StartTimer(CM_AUTO_QUICK_END_TIMER, (quickEndDuration * 1000), mmi_ucm_auto_quick_end);
        }
#endif /* __MMI_CH_QUICK_END__ */
    }
    else
    {
        /* no matter what the no_rcode_count is, send back the result code because the action terminated */
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {
            PRINT_INFORMATION("\n[mmi_ucm_accept_act_rsp] Accept Fail!\n");
            mmi_ucm_at_general_req(g_ucm_p->call_misc.curr_module, RMMI_UCM_RCODE_NO_CARRIER, MMI_UCM_INVALID_ID, &g_ucm_p->call_misc.l4c_info);
            memset(&g_ucm_p->call_misc.l4c_info, 0, sizeof(mmi_ucm_l4c_info_struct));
            g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
            g_ucm_p->call_misc.no_rcode_count = 0;
        }

        mmi_ucm_sync_call_list(rsp->call_list);

        if (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0)
        {
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            /* call application does not have this call yet, so cannot rely on call list of call application */
            if (g_ucm_p->call_list.group_info[groupIndex].call_info[0].proc_state == MMI_UCM_WAIT_PROCESS_STATE)
            {
                g_ucm_p->call_list.group_info[groupIndex].num_call--;
                g_ucm_p->call_list.num_group--;
                mmi_ucm_reset_group_entry(groupIndex);
            }
        }

        mmi_ucm_set_process_state(-1, -1, MMI_UCM_WAIT_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);

        if (rsp->result_info.result == MMI_FALSE)
        {
            DisplayPopup(
                rsp->result_info.error_msg,
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE_IN_CALL);
        }
        else
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE_IN_CALL);
        }
        
        /* go back to corresponding screen */
        mmi_ucm_go_back_screen_check();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_act_rsp
 * DESCRIPTION
 *  Handler for end action response. No success popup and screen will not adjust.
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_act_rsp(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 groupIndex = 0, callIndex = 0;
    mmi_ucm_id_info_struct actionId;
    mmi_ucm_act_rsp_struct *rsp = (mmi_ucm_act_rsp_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result_info.result == TRUE)
    {
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {            
            if (g_ucm_p->call_misc.no_rcode_count == 0)
            {
#if defined(NOKE_DEBUG)
                noke_dbg_printf("call_misc.no_rcode_count == 0\n");
#endif
                PRINT_INFORMATION("\n[mmi_ucm_end_act_rsp] Release OK!\n");
                mmi_ucm_at_general_req(g_ucm_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, MMI_UCM_INVALID_ID, &g_ucm_p->call_misc.l4c_info);
                memset(&g_ucm_p->call_misc.l4c_info, 0, sizeof(mmi_ucm_l4c_info_struct));
                g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
            }
            else
            {
#if defined(NOKE_DEBUG)
                noke_dbg_printf("call_misc.no_rcode_count != 0\n");
#endif
                g_ucm_p->call_misc.no_rcode_count--;
            }
        }

#if defined(NOKE_DEBUG)
        noke_dbg_printf("BEFOR mmi_ucm_sync_call_list\n");
#endif
        mmi_ucm_sync_call_list(rsp->call_list);

#if defined(NOKE_DEBUG)
        noke_dbg_printf("BEFOR mmi_ucm_set_process_state\n");
#endif
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_COMP_PROCESS_STATE);

#if defined(NOKE_DEBUG)
        noke_dbg_printf("END mmi_ucm_set_process_state\n");
#endif
        if (mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0)
        {
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            callIndex = g_ucm_p->call_misc.index_list[0].call_index;

            mmi_ucm_set_process_state(groupIndex, -1, MMI_UCM_WAIT_PROCESS_STATE, MMI_UCM_DO_PROCESS_STATE);
            
            actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
            actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
            actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;

            mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, &g_ucm_p->mo_info);
        }
        else
        {
            mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
            
            if (g_ucm_p->mo_info.is_wait_dial == TRUE)
            {
                PRINT_INFORMATION("\n[mmi_ucm_end_act_rsp] Dial SOS Now\n");
                mmi_ucm_dial_action();
            }
        }
    }
    else
    {
        /* no matter what the no_rcode_count is, send back the result code because the action terminated */
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {
            PRINT_INFORMATION("\n[mmi_ucm_end_act_rsp] Release Fail!\n");
            mmi_ucm_at_general_req(g_ucm_p->call_misc.curr_module, RMMI_UCM_RCODE_ERROR, MMI_UCM_INVALID_ID, &g_ucm_p->call_misc.l4c_info);
            memset(&g_ucm_p->call_misc.l4c_info, 0, sizeof(mmi_ucm_l4c_info_struct));
            g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
            g_ucm_p->call_misc.no_rcode_count = 0;
        }

        mmi_ucm_sync_call_list(rsp->call_list);

        if (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0)
        {
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            /* call application does not have this call yet, so cannot rely on call list of call application */
            if (g_ucm_p->call_list.group_info[groupIndex].call_info[0].proc_state == MMI_UCM_WAIT_PROCESS_STATE)
            {
                g_ucm_p->call_list.group_info[groupIndex].num_call--;
                g_ucm_p->call_list.num_group--;
                mmi_ucm_reset_group_entry(groupIndex);
            }
        }

        mmi_ucm_set_process_state(-1, -1, MMI_UCM_WAIT_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);

        if (g_ucm_p->mo_info.is_wait_dial == TRUE)
        {
            PRINT_INFORMATION("\n[mmi_ucm_end_act_rsp] Reset Wait Dial Flag\n");
            g_ucm_p->mo_info.is_wait_dial = FALSE;
        }
        
        DisplayPopup(
            rsp->result_info.error_msg,
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE_IN_CALL);
        
        /* go back to corresponding screen */
        mmi_ucm_go_back_screen_check();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_act_rsp
 * DESCRIPTION
 *  Handler for general action response, such as hold, retrieve...etc.
 *  Show success popup and screen will adjust.
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_act_rsp(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 groupIndex = 0, callIndex = 0;
    mmi_ucm_id_info_struct actionId;
    mmi_ucm_act_rsp_struct *rsp = (mmi_ucm_act_rsp_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result_info.result == TRUE)
    {
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {
            if (g_ucm_p->call_misc.no_rcode_count == 0)
            {
                PRINT_INFORMATION("\n[mmi_ucm_act_rsp] %d Action Ok!\n", g_ucm_p->call_misc.curr_action);
                mmi_ucm_at_general_req(g_ucm_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, MMI_UCM_INVALID_ID, &g_ucm_p->call_misc.l4c_info);
                memset(&g_ucm_p->call_misc.l4c_info, 0, sizeof(mmi_ucm_l4c_info_struct));
                g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
            }
            else
            {
                g_ucm_p->call_misc.no_rcode_count--;
            }
        }
        
        mmi_ucm_sync_call_list(rsp->call_list);

        mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_COMP_PROCESS_STATE);
        if (mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0)
        {
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            callIndex = g_ucm_p->call_misc.index_list[0].call_index;
            mmi_ucm_set_process_state(groupIndex, -1, MMI_UCM_WAIT_PROCESS_STATE, MMI_UCM_DO_PROCESS_STATE);
            actionId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
            actionId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
            actionId.call_id = g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].call_id;
            mmi_ucm_pre_send_req(g_ucm_p->call_list.group_info[groupIndex].call_info[callIndex].act_type, &actionId, NULL, &g_ucm_p->mo_info);
        }
        else
        {
            mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);            
            DisplayPopup(
                (U8*)GetString(mmi_ucm_get_act_rsp_string_id(g_ucm_p->call_misc.curr_action)),
                IMG_GLOBAL_ACTIVATED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE_IN_CALL);

            mmi_ucm_go_back_screen_check();
        }        
    }
    else
    {
        /* no matter what the no_rcode_count is, send back the result code because the action terminated */
        if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
            (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
        {
            PRINT_INFORMATION("\n[mmi_ucm_act_rsp] %d Action Fail!\n", g_ucm_p->call_misc.curr_action);
            mmi_ucm_at_general_req(g_ucm_p->call_misc.curr_module, RMMI_UCM_RCODE_ERROR, MMI_UCM_INVALID_ID, &g_ucm_p->call_misc.l4c_info);
            memset(&g_ucm_p->call_misc.l4c_info, 0, sizeof(mmi_ucm_l4c_info_struct));
            g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
            g_ucm_p->call_misc.no_rcode_count = 0;
        }

        mmi_ucm_sync_call_list(rsp->call_list);
        
        if (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0)
        {
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            /* call application does not have this call yet, so cannot rely on call list of call application */
            if (g_ucm_p->call_list.group_info[groupIndex].call_info[0].proc_state == MMI_UCM_WAIT_PROCESS_STATE)
            {
                g_ucm_p->call_list.group_info[groupIndex].num_call--;
                g_ucm_p->call_list.num_group--;
                mmi_ucm_reset_group_entry(groupIndex);
            }
        }

        mmi_ucm_set_process_state(-1, -1, MMI_UCM_WAIT_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_DO_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);
        mmi_ucm_set_process_state(-1, -1, MMI_UCM_COMP_PROCESS_STATE, MMI_UCM_IDLE_PROCESS_STATE);

        DisplayPopup(
            rsp->result_info.error_msg,
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE_IN_CALL);

        /* go back to corresponding screen */
        mmi_ucm_go_back_screen_check();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dispatch_ind
 * DESCRIPTION
 *  Dispatch indication coming from call applications.
 * PARAMETERS
 *  op_code         [IN]            Operation code
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dispatch_ind(mmi_ucm_ind_opcode_enum op_code, void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_code)
    {
        case MMI_UCM_SYNC_CALL_LIST:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] SYNC_CALL_LIST\n");
            mmi_ucm_sync_call_list(act_struct);
            mmi_ucm_go_back_screen_check();
            break;
        case MMI_UCM_ALERT_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] ALERT_IND\n");
            mmi_ucm_alert_ind(act_struct);
            break;
        case MMI_UCM_CONNECT_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] CONNECT_IND\n");
            mmi_ucm_connect_ind(act_struct);
            break;
        case MMI_UCM_NOTIFY_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] NOTIFY_IND\n");
            mmi_ucm_notify_ind(act_struct);
            break;
        case MMI_UCM_SESSION_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] SESSION_IND\n");
            mmi_ucm_session_ind(act_struct);
            break;
        case MMI_UCM_SPEECH_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] SPEECH_IND\n");
            mmi_ucm_speech_ind(act_struct);
            break;
        case MMI_UCM_DIAL_REQ_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] DIAL_REQ_IND\n");
            mmi_ucm_dial_req_ind(act_struct);
            break;
        case MMI_UCM_RING_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] RING_IND\n");
            mmi_ucm_ring_ind(act_struct);
            break;
        case MMI_UCM_RELEASE_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] RELEASE_IND\n");
            mmi_ucm_release_ind(act_struct);
            break;
        case MMI_UCM_CALL_COST_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] CALL_COST_IND\n");
            mmi_ucm_call_cost_ind(act_struct);
            break;
        case MMI_UCM_AUTO_REDIAL_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] AUTO_REDIAL_IND\n");
            mmi_ucm_auto_redial_ind(act_struct);
            break;
        case MMI_UCM_START_PROCESSING_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] START_PROCESSING_IND\n");
            mmi_ucm_start_processing_ind(act_struct);
            break;
        case MMI_UCM_STOP_PROCESSING_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] STOP_PROCESSING_IND\n");
            mmi_ucm_stop_processing_ind(act_struct);
            break;
        case MMI_UCM_ANSWER_REQ_IND:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_ind] ANSWER_REQ_IND\n");
            mmi_ucm_answer_req_ind(act_struct);
            break;
        default:
            MMI_ASSERT(0); /* not valid op_code */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sync_call_list
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_sync_call_list(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, m = 0;
    mmi_ucm_index_info_struct indexList;
    mmi_ucm_call_entry_struct *confCall = NULL;
    mmi_ucm_sync_call_list_struct *ind = (mmi_ucm_sync_call_list_struct*)act_struct;
    S32 confCall_index = 0;
    U8 confCall_count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    confCall = OslMalloc(sizeof(mmi_ucm_call_entry_struct) * MMI_UCM_MAX_NUM_INDEX);
    memset(confCall, 0, sizeof(mmi_ucm_call_entry_struct) * MMI_UCM_MAX_NUM_INDEX);
    
    i = 0;
    while (i < g_ucm_p->call_list.num_group)
    {
        j = 0;
        while (j < g_ucm_p->call_list.group_info[i].num_call)
        {
            for (m = 0; m < ind->total_num; m++)
            {
                /* replace invalid id to valid id for outgoing call */
                if ((g_ucm_p->call_list.group_info[i].call_type == ind->call_info[m].uid_info.call_type) && 
                    (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_OUTGOING_STATE) && 
                    (ind->call_info[m].call_state == MMI_UCM_OUTGOING_STATE))
                {
                    g_ucm_p->call_list.group_info[i].group_id = ind->call_info[m].uid_info.group_id;
                    g_ucm_p->call_list.group_info[i].call_info[j].call_id = ind->call_info[m].uid_info.call_id;
                    memcpy(&g_ucm_p->call_list.group_info[i].call_info[j].remote_info, &ind->call_info[m].remote_info, sizeof(mmi_ucm_remote_info_struct));
                    break;
                }
                if ((g_ucm_p->call_list.group_info[i].call_type & ind->call_type) && 
                    (g_ucm_p->call_list.group_info[i].group_id == ind->call_info[m].uid_info.group_id) && 
                    (g_ucm_p->call_list.group_info[i].call_info[j].call_id == ind->call_info[m].uid_info.call_id))
                {
                    /* update the entry in ucm call list */
                    if (g_ucm_p->call_list.group_info[i].call_type != ind->call_info[m].uid_info.call_type)
                    {
                        PRINT_INFORMATION("\n[mmi_ucm_sync_call_list] Emergency Data Call => Emergency Voice Call\n");
                        PRINT_INFORMATION("\n[mmi_ucm_sync_call_list] Original Call Type: %d, New Call Type: %d\n", g_ucm_p->call_list.group_info[i].call_type, ind->call_info[m].uid_info.call_type);
                    }
                    g_ucm_p->call_list.group_info[i].call_type = ind->call_info[m].uid_info.call_type; /* emergency data call to emergency voice call */
                    g_ucm_p->call_list.group_info[i].call_state = ind->call_info[m].call_state;
                    memcpy(&g_ucm_p->call_list.group_info[i].call_info[j].remote_info, &ind->call_info[m].remote_info, sizeof(mmi_ucm_remote_info_struct));
                    break;
                }
            }
            if ((m == ind->total_num) && (g_ucm_p->call_list.group_info[i].call_type & ind->call_type))
            {
                /* delete the entry in ucm call list */
                g_ucm_p->call_list.group_info[i].num_call--;
                if (g_ucm_p->call_list.group_info[i].num_call == 0) /* delete from group entry */
                {
                    g_ucm_p->call_list.num_group--;
                    /* store the call entry for conference or split action, because most of the information should not change */
                    if ((g_ucm_p->call_misc.curr_action == MMI_UCM_CONFERENCE) || (g_ucm_p->call_misc.curr_action == MMI_UCM_SPLIT))
                    {                        
                        memcpy(&confCall[confCall_count], &g_ucm_p->call_list.group_info[i].call_info[0], sizeof(mmi_ucm_call_entry_struct));
                        confCall_count++;
                    }
                    for (m = i; m < g_ucm_p->call_list.num_group; m++)
                    {
                        memcpy(&g_ucm_p->call_list.group_info[m], &g_ucm_p->call_list.group_info[m + 1], sizeof(mmi_ucm_group_entry_struct));
                    }
                    mmi_ucm_reset_group_entry(m);
                    if (m != i) /* enter for loop to move group list */
                    {
                        i--;
                    }
                }
                else /* delete from call entry */
                {
                    /* store the actual time for conference or split action, because the group id will change */
                    if ((g_ucm_p->call_misc.curr_action == MMI_UCM_CONFERENCE) || (g_ucm_p->call_misc.curr_action == MMI_UCM_SPLIT))
                    {
                        memcpy(&confCall[confCall_count], &g_ucm_p->call_list.group_info[i].call_info[j], sizeof(mmi_ucm_call_entry_struct));
                        confCall_count++;
                    }
                    for (m = j; m < g_ucm_p->call_list.group_info[i].num_call; m++)
                    {
                        memcpy(&g_ucm_p->call_list.group_info[i].call_info[m], &g_ucm_p->call_list.group_info[i].call_info[m + 1], sizeof(mmi_ucm_call_entry_struct));
                    }
                    mmi_ucm_reset_call_entry(i, m);
                    if (m != j) /* enter for loop to move call list */
                    {
                        j--;
                    }
                }
            }
            j++;
        }
        i++;
    }

    MMI_ASSERT(confCall_count <= MMI_UCM_MAX_NUM_INDEX);
        
    for (m = 0; m < ind->total_num; m++)
    {
        memset(&indexList, -1, sizeof(mmi_ucm_index_info_struct));
        mmi_ucm_search_call_list(ind->call_info[m], &indexList);
        if ((indexList.group_index != -1) && (indexList.call_index == -1)) /* add to call entry */
        {
            i = indexList.group_index;
            j = g_ucm_p->call_list.group_info[indexList.group_index].num_call;
            if (g_ucm_p->call_list.group_info[i].num_call < MMI_UCM_MAX_NUM_INDEX)
            {
                if ((g_ucm_p->call_misc.curr_action == MMI_UCM_CONFERENCE) || (g_ucm_p->call_misc.curr_action == MMI_UCM_SPLIT))
                {
                    confCall_index = mmi_ucm_get_call_index_by_call_id(confCall, confCall_count, ind->call_info[m].uid_info.call_id);
                    if (confCall_index >= 0)
                    {
                        memcpy(&g_ucm_p->call_list.group_info[i].call_info[j], &confCall[confCall_index], sizeof(mmi_ucm_call_entry_struct));
                    }
                }
                g_ucm_p->call_list.group_info[i].call_info[j].call_id = ind->call_info[m].uid_info.call_id;
                memcpy(&g_ucm_p->call_list.group_info[i].call_info[j].remote_info, &ind->call_info[m].remote_info, sizeof(mmi_ucm_remote_info_struct));
                if (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_OUTGOING_STATE)
                {
                    g_ucm_p->call_list.group_info[i].call_info[j].call_origin = MMI_UCM_MO_ORIGIN;
                }
                else if (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_INCOMING_STATE)
                {
                    g_ucm_p->call_list.group_info[i].call_info[j].call_origin = MMI_UCM_MT_ORIGIN;
                }
                g_ucm_p->call_list.group_info[i].num_call++;
            }
            else
            {
                MMI_ASSERT(0); /* no empty call entry to add */
            }
        }
        else if ((indexList.group_index == -1) && (indexList.call_index == -1)) /* add to group entry */
        {
            i = g_ucm_p->call_list.num_group;
            if (g_ucm_p->call_list.num_group < MMI_UCM_MAX_NUM_TAB)
            {
                if ((g_ucm_p->call_misc.curr_action == MMI_UCM_CONFERENCE) || (g_ucm_p->call_misc.curr_action == MMI_UCM_SPLIT))
                {
                    confCall_index = mmi_ucm_get_call_index_by_call_id(confCall, confCall_count, ind->call_info[m].uid_info.call_id);
                    if (confCall_index >= 0)
                    {
                        memcpy(&g_ucm_p->call_list.group_info[i].call_info[0], &confCall[confCall_index], sizeof(mmi_ucm_call_entry_struct));
                    }
                }
                g_ucm_p->call_list.group_info[i].group_id = ind->call_info[m].uid_info.group_id;
                g_ucm_p->call_list.group_info[i].call_type = ind->call_info[m].uid_info.call_type;
                g_ucm_p->call_list.group_info[i].call_state = ind->call_info[m].call_state;
                g_ucm_p->call_list.group_info[i].call_info[0].call_id = ind->call_info[m].uid_info.call_id;
                memcpy(&g_ucm_p->call_list.group_info[i].call_info[0].remote_info, &ind->call_info[m].remote_info, sizeof(mmi_ucm_remote_info_struct));
                if (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_OUTGOING_STATE)
                {
                    g_ucm_p->call_list.group_info[i].call_info[0].call_origin = MMI_UCM_MO_ORIGIN;
                }
                else if (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_INCOMING_STATE)
                {
                    g_ucm_p->call_list.group_info[i].call_info[0].call_origin = MMI_UCM_MT_ORIGIN;
                }
                g_ucm_p->call_list.group_info[i].num_call++;
                g_ucm_p->call_list.num_group++;
            }
            else
            {
                MMI_ASSERT(0); /* no empty group entry to add */
            }
        }
    }

    /* debug purpose */    
    PRINT_INFORMATION("\n[mmi_ucm_sync_call_list] Total Group: %d\n", g_ucm_p->call_list.num_group);
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
        {
            PRINT_INFORMATION("\n[mmi_ucm_sync_call_list] Group Index: %d, Group Id: %d, Num of Call: %d,  Call Type: %d, Call State: %d, Call Id: %d\n",
                                i, 
                                g_ucm_p->call_list.group_info[i].group_id ,
                                g_ucm_p->call_list.group_info[i].num_call,
                                g_ucm_p->call_list.group_info[i].call_type,
                                g_ucm_p->call_list.group_info[i].call_state, 
                                g_ucm_p->call_list.group_info[i].call_info[j].call_id);
        }
    }

#ifdef __BT_SUPPORT__
    if (ind->call_type & MMI_UCM_VOICE_CALL_TYPE_ALL)
    {
        if (g_ucm_p->call_misc.is_delay_ciev == FALSE)
        {
            mmi_ucm_sync_call_state_to_headset();
        }
        else
        {
            g_ucm_p->call_misc.is_delay_ciev = FALSE;
        }
    }
#endif /* __BT_SUPPORT__ */

    OslMfree(confCall);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_alert_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_alert_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_alert_ind_struct *ind = (mmi_ucm_alert_ind_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind->local_gen == TRUE)
    {
        mmi_ucm_play_inband_tone();
    }
#ifdef __BT_SUPPORT__
    mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_ALERT);
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_ALERT);
#endif
#endif /* __BT_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_connect_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_connect_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 groupIndex = 0;
    mmi_ucm_index_info_struct index;
    mmi_ucm_connect_ind_struct *ind = (mmi_ucm_connect_ind_struct*)act_struct;
#ifdef __MMI_CH_QUICK_END__
    U16 quickEndDuration = CHISTGetQuickEndTime();
#endif /* __MMI_CH_QUICK_END__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_stop_inband_tone();
    
    /* dialed call log */
    MMI_ASSERT(mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1);
    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
    DTGetRTCTime(&g_ucm_p->call_list.group_info[groupIndex].call_info[0].start_time);
    /* do not log call history for SAT call */
    if (g_ucm_p->call_list.group_info[groupIndex].call_info[0].module_id != MMI_UCM_FROM_SAT)
    {
        mmi_ucm_log_call_history(groupIndex, 0, TRUE);
    }

    mmi_ucm_sync_call_list(ind->call_list);    

    memset(&index, 0, sizeof(mmi_ucm_index_info_struct));

    MMI_ASSERT(mmi_ucm_get_index_by_id(&ind->uid_info, &index));

    mmi_ucm_go_back_screen_check();

    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) == 1)
    {
    #ifdef __MMI_CONNECT_NOTICE__
        /* play connect notice according to user defined style */
        mmi_ucm_play_connect_notice();
    #else /* __MMI_CONNECT_NOTICE__ */ 
        playRequestedTone(CONNECT_TONE);
    #endif /* __MMI_CONNECT_NOTICE__ */ 
    }

#ifdef __MMI_CH_QUICK_END__
    if (IsMyTimerExist(CM_AUTO_QUICK_END_TIMER) == FALSE &&
        quickEndDuration > 0 && 
        mmi_ucm_app_active_call(MMI_UCM_VOICE_CALL_TYPE_ALL) > 0 &&
        mmi_ucm_emergency_call_present() == MMI_FALSE)
        {    
            PRINT_INFORMATION("QuickEndTime:%d",quickEndDuration);
            StartTimer(CM_AUTO_QUICK_END_TIMER, (quickEndDuration * 1000), mmi_ucm_auto_quick_end);
        }
#endif /* __MMI_CH_QUICK_END__ */
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_notify_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_notify_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_notify_ind_struct *ind = (mmi_ucm_notify_ind_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        ind->disp_msg,
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE_IN_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_session_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_session_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_session_ind_struct *ind = (mmi_ucm_session_ind_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind->session_switch == TRUE) /* turn on session */
    {
        if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_NONE)
        {
            /* session is occupied, cannot turn on directly */
            if (mdi_audio_speech_get_app_id() != ind->session_type)
            {
                if (g_ucm_p->call_misc.is_speech == TRUE)
                {
                    /* turn off speech before session off */
                #ifdef __MMI_VOIP__
                    if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_VOIP)
                    {
                        mmi_voip_ucm_suspend_rtp();
                    }
                    else
                #endif /* __MMI_VOIP__ */
                    {
                        mdi_audio_speech_codec_stop();
                    }
                }
            #ifdef __CTM_SUPPORT__
                mmi_gsm_ctm_open(FALSE);
            #endif /*__CTM_SUPPORT__*/
                mdi_audio_speech_session_stop(mdi_audio_speech_get_app_id());
                mdi_audio_speech_session_start(ind->session_type);
            #ifdef __MMI_BT_PROFILE__
                mmi_profiles_bt_call_start_callback();
            #endif
            }
        }
        else /* session is not occupied, turn on directly */
        {
            mdi_audio_speech_session_start(ind->session_type);
        #ifdef __MMI_BT_PROFILE__
            mmi_profiles_bt_call_start_callback();
        #endif
        }
    }
    else /* turn off session */
    {
        if (mdi_audio_speech_get_app_id() == ind->session_type)
        {
            /* speech should turn off before session off */
            MMI_ASSERT(g_ucm_p->call_misc.is_speech == FALSE);
            mdi_audio_speech_session_stop(ind->session_type);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_speech_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_speech_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_speech_ind_struct *ind = (mmi_ucm_speech_ind_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ind->call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) ||
    #ifdef __MMI_VIDEO_TELEPHONY__
        ind->call_type == MMI_UCM_VIDEO_CALL_TYPE ||
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        MMI_FALSE)
    {
        if ((ind->local_switch == TRUE) || (ind->remote_switch == TRUE)) /* speech on */
        {
            if (mdi_audio_speech_get_app_id() != ind->session_type)
            {
                if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_NONE)
                {
                    /* stop codec / encode / decode, stop other session and start the session */
                #ifdef __MMI_VOIP__
                    if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_VOIP)
                    {
                        mmi_voip_ucm_suspend_rtp();
                    }
                    else
                #endif /* __MMI_VOIP__ */
                    {
                        mdi_audio_speech_codec_stop();
                    }
                #ifdef __CTM_SUPPORT__
                    mmi_gsm_ctm_open(FALSE);
                #endif /*__CTM_SUPPORT__*/
                    mdi_audio_speech_session_stop(mdi_audio_speech_get_app_id());                    
                }
                mdi_audio_speech_session_start(ind->session_type);
            }
            mdi_audio_speech_codec_start();
            g_ucm_p->call_misc.is_speech = TRUE;
        #ifdef __CTM_SUPPORT__
            mmi_gsm_ctm_open(TRUE);
        #endif /*__CTM_SUPPORT__*/
        }
        else /* speech off */
        {
            if (mdi_audio_speech_get_app_id() == ind->session_type)
            {
            #ifdef __CTM_SUPPORT__
                mmi_gsm_ctm_open(FALSE);
            #endif /*__CTM_SUPPORT__*/
                mdi_audio_speech_codec_stop();
                g_ucm_p->call_misc.is_speech = FALSE;
            }
        }
    }
#ifdef __MMI_VOIP__
    else if (ind->call_type == MMI_UCM_VOIP_CALL_TYPE)
    {
        if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_VOIP)
        {
            if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_NONE)
            {
                /* stop codec / encode / decode, stop other session and start the session */
                mdi_audio_speech_codec_stop();
                g_ucm_p->call_misc.is_speech = FALSE;
            #ifdef __CTM_SUPPORT__
                mmi_gsm_ctm_open(FALSE);
            #endif /*__CTM_SUPPORT__*/
                mdi_audio_speech_session_stop(mdi_audio_speech_get_app_id());
            }
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_VOIP);
        }
        if ((ind->local_switch == FALSE) && (ind->remote_switch == FALSE))
        {
            mmi_voip_ucm_control_rtp(ind->rtp_handle, ind->local_switch, ind->remote_switch);
            g_ucm_p->call_misc.is_speech = FALSE;
        }
        else
        {
            mmi_voip_ucm_control_rtp(ind->rtp_handle, ind->local_switch, ind->remote_switch);
            g_ucm_p->call_misc.is_speech = TRUE;
        }
    }
#endif /* __MMI_VOIP__ */

#ifdef __MMI_BG_SOUND_EFFECT__
    if (g_ucm_p->call_misc.is_speech == TRUE &&
        mmi_ucm_emergency_call_present() == FALSE)
    {
        PRINT_INFORMATION(("\n[mmi_ucm_speech_ind] mmi_bgsnd_common_mtmo_play_sound \n"));
        mmi_bgsnd_common_mtmo_play_sound();
    }
    else
    {
        PRINT_INFORMATION(("\n[mmi_ucm_speech_ind] mmi_bgsnd_util_stop_play_sound \n"));
        mmi_bgsnd_util_stop_play_sound();
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_req_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dial_req_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_ring_ind_struct *ind = (mmi_ucm_ring_ind_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_is_busy() == FALSE &&
        mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL | MMI_UCM_VIDEO_CALL_TYPE | MMI_UCM_VOIP_CALL_TYPE) == 0)
    {
        mmi_ucm_sync_call_list(ind->call_list);
        
        memcpy(&g_ucm_p->mo_mt_display, &ind->alert_info, sizeof(mmi_ucm_ring_info_struct));

        if (!IsScreenPresent(SCR_ID_UCM_MARKER))
        {
            mmi_ucm_entry_marker();
        }
        /* go back to outgoing screen with updated information */
        mmi_ucm_entry_outgoing_call();

        if (g_ucm_p->call_list.num_group == 1)
        {
            AlmDisableExpiryHandler();
            /* do not suspend background audio for csd call */
            if (mmi_ucm_app_outgoing_call(MMI_UCM_CSD_CALL_TYPE_ALL) == 0)
            {
                mdi_audio_suspend_background_play();
            }            
        }

        /* abort auto redial if necessary */
        if (IsScreenPresent(SCR_ID_UCM_AUTO_REDIAL))
        {
            StopTimer(UCM_AUTO_REDIAL_TIMER);
            ClearDelScrnIDCallbackHandler(SCR_ID_UCM_AUTO_REDIAL, NULL);
            DeleteScreenIfPresent(SCR_ID_UCM_AUTO_REDIAL);
            if (g_ucm_p->auto_redial.abort_hdlr)
            {
                g_ucm_p->auto_redial.abort_hdlr();                
            }
            memset(&g_ucm_p->auto_redial, 0, sizeof(mmi_ucm_auto_redial_struct));
        }
    }
    else /* the auto reject call is not in the call list */
    {
        /* auto reject */
        mmi_ucm_pre_send_req(MMI_UCM_AUTO_REJECT, &(ind->uid_info), NULL, NULL);
        mmi_ucm_pre_send_req(MMI_UCM_FORCE_RELEASE, &(ind->uid_info), NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_answer_req_ind
 * DESCRIPTION
 *  Answer reqeust indication
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_answer_req_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_answer_req_ind_struct *ind = (mmi_ucm_answer_req_ind_struct*)act_struct;
    S32 groupIndex = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_ucm_is_pending_action() == FALSE &&
        mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) == 0 &&
        mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) == 0 &&
        mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1)
    {
        mmi_ucm_stop_incoming_tone();

        mmi_ucm_set_processing_parameter(
            STR_ID_UCM_ANSWER,
            STR_ID_UCM_PROCESSING,
            IMG_GLOBAL_PROGRESS,
            0,
            0,
            0,
            0,
            0,
            0);
        
        mmi_ucm_entry_processing_screen();
    
        /* received call log */        
        groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
        DTGetRTCTime(&g_ucm_p->call_list.group_info[groupIndex].call_info[0].start_time);
        
        /* do not log call history for SAT call */
        if (g_ucm_p->call_list.group_info[groupIndex].call_info[0].module_id != MMI_UCM_FROM_SAT)
        {
            mmi_ucm_log_call_history(groupIndex, 0, TRUE);
        }

        mmi_ucm_sync_call_list(ind->call_list);
        mmi_ucm_go_back_screen_check();

    }
    else
    {
        /* auto reject */
        mmi_ucm_pre_send_req(MMI_UCM_AUTO_REJECT, &(ind->uid_info), NULL, NULL);
        mmi_ucm_pre_send_req(MMI_UCM_FORCE_RELEASE, &(ind->uid_info), NULL, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_ring_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_ring_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_index_info_struct index;
    MMI_ANSWERING_MODE ansMode;
    mmi_ucm_ring_ind_struct *ind = (mmi_ucm_ring_ind_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* when AT is disconnecting call, it cannot be interrupted by incoming call */
    if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_IDLE) &&
        (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0) && 
        (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0) &&
        (mmi_ucm_emergency_call_present() == FALSE))
    {
        mmi_ucm_sync_call_list(ind->call_list);

        memset(&index, 0, sizeof(mmi_ucm_index_info_struct));
        
        MMI_ASSERT(mmi_ucm_get_index_by_id(&ind->uid_info, &index));
        memcpy(&g_ucm_p->mo_mt_display, &ind->alert_info, sizeof(mmi_ucm_ring_info_struct));
        memcpy(&g_ucm_p->call_misc.l4c_info, &ind->l4c_info, sizeof(mmi_ucm_l4c_info_struct));

        if (!IsScreenPresent(SCR_ID_UCM_MARKER))
        {
            mmi_ucm_entry_marker();
        }

        mdi_audio_stop_all();

        /* go back to incoming screen with updated information */
        mmi_ucm_entry_incoming_call();

        AlmDisableExpiryHandler();

        if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) == 1)
        {
            mdi_audio_disable_background_play(); /* only disable background play but not suspend ringtone play */
        }

        /* auto answer is only applicable to the first incoming call */
        memcpy(&ansMode, GetAnsweringMode(), sizeof(MMI_ANSWERING_MODE));
        if ((ansMode.automatic == TRUE) && (g_ucm_p->call_list.num_group == 1))
        {
            StartTimer(UCM_AUTO_ANSWER_TIMER, UI_POPUP_NOTIFYDURATION_TIME_2000, mmi_ucm_incoming_call_sendkey);
        }

        /* reset wait dial flag to prevent MO & MT collision */
        if (g_ucm_p->mo_info.is_wait_dial == TRUE)
        {
            g_ucm_p->mo_info.is_wait_dial = FALSE;
            DisplayPopup(
                (U8*)GetString(STR_ID_UCM_CALL_ABORT),
                IMG_GLOBAL_UNFINISHED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE_IN_CALL);
        }
        
        /* abort auto redial if necessary */
        if (IsScreenPresent(SCR_ID_UCM_AUTO_REDIAL))
        {
            StopTimer(UCM_AUTO_REDIAL_TIMER);
            ClearDelScrnIDCallbackHandler(SCR_ID_UCM_AUTO_REDIAL, NULL);
            DeleteScreenIfPresent(SCR_ID_UCM_AUTO_REDIAL);
            if (g_ucm_p->auto_redial.abort_hdlr)
            {
                g_ucm_p->auto_redial.abort_hdlr();                
            }
            memset(&g_ucm_p->auto_redial, 0, sizeof(mmi_ucm_auto_redial_struct));
        }
    }
    else /* the auto reject call is not in the call list */
    {
        /* auto reject */
        mmi_ucm_pre_send_req(MMI_UCM_AUTO_REJECT, &(ind->uid_info), NULL, NULL);
        mmi_ucm_pre_send_req(MMI_UCM_FORCE_RELEASE, &(ind->uid_info), NULL, NULL);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_release_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_release_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ANSWERING_MODE ansMode;
    mmi_ucm_index_info_struct index;
    mmi_ucm_l4c_info_struct *l4cPtr = NULL;
    mmi_ucm_release_ind_struct *ind = (mmi_ucm_release_ind_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_ucm_release_ind] Release Group Id: %d, Call Id: %d\n", ind->uid_info.group_id, ind->uid_info.call_id);

    /* It is normal in auto reject case. */
    if (mmi_ucm_get_index_by_id(&ind->uid_info, &index) == FALSE)
    {
        U32 i = 0;
        U32 j = 0;

        PRINT_INFORMATION("\n[mmi_ucm_release_ind] ERROR! UID is not match! It's only normal in auto reject case!\n");
        PRINT_INFORMATION("\n[mmi_ucm_release_ind] Total Group: %d\n", g_ucm_p->call_list.num_group);
        for (i = 0; i < g_ucm_p->call_list.num_group; i++)
        {
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
            {
                PRINT_INFORMATION("\n[mmi_ucm_release_ind] Group Index: %d, Group Id: %d, Num of Call: %d,  Call Type: %d, Call State: %d, Call Id: %d\n",
                                    i, 
                                    g_ucm_p->call_list.group_info[i].group_id ,
                                    g_ucm_p->call_list.group_info[i].num_call,
                                    g_ucm_p->call_list.group_info[i].call_type,
                                    g_ucm_p->call_list.group_info[i].call_state, 
                                    g_ucm_p->call_list.group_info[i].call_info[j].call_id);
            }
        }
        return;
    }

    mmi_ucm_stop_inband_tone();
    mmi_ucm_stop_incoming_tone();
    memcpy(&ansMode, GetAnsweringMode(), sizeof(MMI_ANSWERING_MODE));
    if (ansMode.automatic == TRUE)
    {
        StopTimer(UCM_AUTO_ANSWER_TIMER);
    }

    if (mmi_dt_is_valid(&g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time))
    {
        DTGetRTCTime(&g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].end_time);
        applib_get_time_difference_ext(
            (applib_time_struct*)&g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].end_time, 
            (applib_time_struct*)&g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time, 
            (applib_time_struct*)&g_ucm_p->call_end.call_duration);
        /* do not log call duration for SAT call */
        if (g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id != MMI_UCM_FROM_SAT)
        {
            mmi_ucm_log_call_duration(index.group_index, index.call_index);
        }
    }
    else
    {
        memset(&g_ucm_p->call_end.call_duration, 0, sizeof(MYTIME));

        /* do not log call history for SAT call */
        if (g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id != MMI_UCM_FROM_SAT)
        {
            if (g_ucm_p->call_list.group_info[index.group_index].call_state == MMI_UCM_OUTGOING_STATE)
            {
                DTGetRTCTime(&g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time);
                mmi_ucm_log_call_history(index.group_index, index.call_index, FALSE);
            }
            else if (g_ucm_p->call_list.group_info[index.group_index].call_state == MMI_UCM_INCOMING_STATE)
            {
                mmi_ucm_log_call_history(index.group_index, index.call_index, FALSE);
            }
            else
            {
                MMI_ASSERT(0); /* should either outgoing call or incoming call */
            }
        }
    }
    
    if ((g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C) ||
        (g_ucm_p->call_misc.curr_module == MMI_UCM_FROM_L4C_SIM2))
    {
        PRINT_INFORMATION("\n[mmi_ucm_release_ind] Delay CIEV until ACT_RSP\n");
        g_ucm_p->call_misc.is_delay_ciev = TRUE;
    }
    else if ((g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id == MMI_UCM_FROM_L4C) ||
             (g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id == MMI_UCM_FROM_L4C_SIM2))
    {
        PRINT_INFORMATION("\n[mmi_ucm_release_ind] Release AT Initial Call\n");
        l4cPtr = OslMalloc(sizeof(mmi_ucm_l4c_info_struct));
        memset(l4cPtr, 0, sizeof(mmi_ucm_l4c_info_struct));
        l4cPtr->l4c_source = g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].l4c_source;
        mmi_ucm_at_general_req(
            g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id, 
            RMMI_UCM_RCODE_NO_CARRIER, 
            g_ucm_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id, 
            l4cPtr);
        OslMfree(l4cPtr);
    }

    g_ucm_p->call_end.disp_msg = ind->disp_msg;
    g_ucm_p->call_end.image_id = ind->image_id;
    g_ucm_p->call_end.tone_id = ind->tone_id;

    mmi_ucm_sync_call_list(ind->call_list);
    
    mmi_ucm_entry_call_end();
    
    mmi_ucm_go_back_screen_check();

    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) == 0)
    {
        if (g_ucm_p->call_misc.is_mute == TRUE)
        {
            g_ucm_p->call_misc.is_mute = FALSE;
            MuteOffMicrophone();
            HideStatusIcon(STATUS_ICON_MUTE);
            UpdateStatusIcons();
        }
        if (g_ucm_p->call_misc.is_loud == TRUE)
        {
            g_ucm_p->call_misc.is_loud = FALSE;
            DisbleHandsFree();
            SetLoudSpeaker(FALSE);
        }
        #ifdef __MMI_BT_PROFILE__
            PRINT_INFORMATION("\n[mmi_ucm_release_ind] SCO Ends\n");
            mmi_profiles_bt_call_end_callback();
        #endif /* __MMI_BT_PROFILE__ */

        g_ucm_p->call_misc.is_dtmf= TRUE;

    #ifdef __MMI_BG_SOUND_EFFECT__
        PRINT_INFORMATION(("\n[mmi_ucm_release_ind] mmi_bgsnd_util_delete_end_call_screen \n"));
        mmi_bgsnd_util_delete_end_call_screen();
    #endif /* __MMI_BG_SOUND_EFFECT__ */

        /* resume background play when there is no call or only csd call*/
        mdi_audio_resume_background_play();
        AlmEnableExpiryHandler();

#ifdef __MMI_CH_QUICK_END__
        StopTimer(CM_AUTO_QUICK_END_TIMER);
#endif /* __MMI_CH_QUICK_END__ */

    }
    
    /* hide GSM cipher status icon when there is no GSM call */
    if (mmi_ucm_app_total_call(MMI_UCM_SIM1_CALL_TYPE_ALL) == 0)
    {
    #ifdef _NETWORK_CIPHER_SUPPORT_
        HideStatusIcon(STATUS_ICON_NETWORK_CIPHER_GSM);
        UpdateStatusIcons();
    #endif /* _NETWORK_CIPHER_SUPPORT_ */
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_ucm_app_total_call(MMI_UCM_SIM2_CALL_TYPE_ALL) == 0)
    {
    #ifdef _NETWORK_CIPHER_SUPPORT_
        HideStatusIcon(STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM);
        UpdateStatusIcons();
    #endif /* _NETWORK_CIPHER_SUPPORT_ */
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_cost_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_call_cost_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_call_cost_struct *ind = (mmi_ucm_call_cost_struct*)act_struct;
    U16 symbol_len = mmi_ucs2strlen((S8*)ind->symbol);
    U16 cost_len = mmi_ucs2strlen((S8*)ind->cost);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_p->call_cost, 0, sizeof(mmi_ucm_call_cost_cntx_struct));

    memcpy(&g_ucm_p->call_cost.uid_info, &ind->uid_info, sizeof(mmi_ucm_id_info_struct));

    if (symbol_len)
    {
        mmi_ucs2ncpy((S8*)g_ucm_p->call_cost.symbol, (S8*)ind->symbol, MMI_UCM_CALL_COST_UNIT_DIGITS);
    }

    if (cost_len)
    {
        mmi_ucs2ncpy((S8*)g_ucm_p->call_cost.cost, (S8*)ind->cost, MMI_UCM_CALL_COST_COST_DIGITS);
    }

    /* go back to in-call screen with updated information */    
    if (GetExitScrnID() == SCR_ID_UCM_IN_CALL)
    {
        reset_call_cost_UI();
        show_call_cost_UI(ind->symbol, ind->cost);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_redial_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_redial_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_auto_redial_struct *ind = (mmi_ucm_auto_redial_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&g_ucm_p->auto_redial, ind, sizeof(mmi_ucm_auto_redial_struct));
    
    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) == 0)
    {
        if (GetExitScrnID() == SCR_ID_UCM_CALL_END)
        {
            mmi_ucm_add_auto_redial_to_history();
            SetDelScrnIDCallbackHandler(SCR_ID_UCM_AUTO_REDIAL, (HistoryDelCBPtr) mmi_ucm_auto_redial_delete_callback);
        }
        else
        {
            mmi_ucm_entry_auto_redial();
        }
        StartTimer(UCM_AUTO_REDIAL_TIMER, g_ucm_p->auto_redial.time * UI_POPUP_NOTIFYDURATION_TIME, mmi_ucm_auto_redial_timeout_handler);
    }
    else
    {
        if (g_ucm_p->auto_redial.abort_hdlr)
        {
            g_ucm_p->auto_redial.abort_hdlr();
            memset(&g_ucm_p->auto_redial, 0, sizeof(mmi_ucm_auto_redial_struct));            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_start_processing_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_start_processing_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_start_processing_struct *ind = (mmi_ucm_start_processing_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: mark the call as processing
    
    mmi_ucm_set_processing_parameter_with_body_string_p(
        STR_ID_UCM_PROCESSING,
        ind->content,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        0);

    mmi_ucm_entry_processing_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_processing_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_processing_ind(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_stop_processing_struct *ind = (mmi_ucm_stop_processing_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind->disp_msg != NULL) /* release call will have release_ind to show call end popup */
    {
        DisplayPopup(
            ind->disp_msg,
            ind->image_id,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8)ind->tone_id);
    }    
    
    mmi_ucm_go_back_screen_check();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dispatch_cnf
 * DESCRIPTION
 *  Dispatch confirm coming from call applications.
 * PARAMETERS
 *  op_code         [IN]            Operation code
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  TRUE means the confirm screen is displayed / cancelled; 
 *  FALSE means the confirm screen cannot be displayed / cancelled.
 *****************************************************************************/
MMI_BOOL mmi_ucm_dispatch_cnf(mmi_ucm_cnf_opcode_enum op_code, void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_display_cnf_struct *cnf = (mmi_ucm_display_cnf_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_code)
    {
        case MMI_UCM_DISPLAY_CNF:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_cnf] DISPLAY_CNF\n");
            if (!IsScreenPresent(SCR_ID_UCM_CONFIRM))
            {
                if (cnf->disp_condition & MMI_UCM_DISP_OUTGOING)
                {                    
                    PRINT_INFORMATION("\n[mmi_ucm_dispatch_cnf] Do Not Check Outgoing State\n");
                    if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                        (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                        (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                        (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0) && 
                        (mmi_ucm_emergency_call_present() == FALSE))
                    {
                        mmi_ucm_display_cnf(act_struct);
                        return TRUE;
                    }
                }
                else if (cnf->disp_condition & MMI_UCM_DISP_INCOMING)
                {                
                    PRINT_INFORMATION("\n[mmi_ucm_dispatch_cnf] Do Not Check Incoming State\n");
                    if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                        (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                        (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                        (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0) && 
                        (mmi_ucm_emergency_call_present() == FALSE))
                    {
                        mmi_ucm_display_cnf(act_struct);
                        return TRUE;
                    }
                }
                else
                {
                    if (mmi_ucm_is_busy() == FALSE)
                    {
                        mmi_ucm_display_cnf(act_struct);
                        return TRUE;
                    }
                }
            }            
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_cnf] Cannot Show Display Confirm\n");
            return FALSE;
            break;
        case MMI_UCM_CANCEL_CNF:
            PRINT_INFORMATION("\n[mmi_ucm_dispatch_cnf] CANCEL_CNF\n");
            mmi_ucm_cancel_cnf(act_struct);
            return TRUE;
            break;
        default:
            MMI_ASSERT(0); /* not valid op_code */
            return FALSE;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_display_cnf
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_display_cnf(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_display_cnf_struct *cnf = (mmi_ucm_display_cnf_struct*)act_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->cnf_scr.content != NULL)
    {
        OslMfree(g_ucm_p->cnf_scr.content);
        g_ucm_p->cnf_scr.content = NULL;
    }

    memcpy (&g_ucm_p->cnf_scr, cnf, sizeof(mmi_ucm_display_cnf_struct ));
    g_ucm_p->cnf_scr.content = OslMalloc((mmi_ucs2strlen((S8*)cnf->content) + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*)g_ucm_p->cnf_scr.content, (S8*)cnf->content);
    
    mmi_ucm_entry_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_cancel_cnf
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_cancel_cnf(void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UCM_CONFIRM))
    {
        PRINT_INFORMATION("\n[mmi_ucm_cancel_cnf] process \n");

        /* delete confirm screen */
        DeleteScreenIfPresent(SCR_ID_UCM_CONFIRM);

        if (SCR_CONFIRM_SCREEN == GetExitScrnID())
        {
            PRINT_INFORMATION("\n[mmi_ucm_cancel_cnf] go_back_screen \n");
            
            mmi_ucm_set_processing_parameter(
                    STR_ID_UCM_PROCESSING,
                    STR_ID_UCM_PROCESSING,
                    IMG_GLOBAL_PROGRESS,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0);
           
            mmi_ucm_entry_processing_screen();

            mmi_ucm_go_back_screen_check();
        }
    }
    else
    {
        PRINT_INFORMATION("\n[mmi_ucm_cancel_cnf] Ignore \n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_master_at_req_ind
 * DESCRIPTION
 *  Dispatch protocol handlers from master side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_master_at_req_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_at_req_ind(MMI_UCM_FROM_L4C, inMsg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_slave_at_req_ind
 * DESCRIPTION
 *  Dispatch protocol handlers from slave side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_slave_at_req_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_at_req_ind(MMI_UCM_FROM_L4C_SIM2, inMsg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_at_req_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_at_req_ind(mmi_ucm_module_origin_enum moduleId, void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, groupIndex = 0, callIndex = 0, numIncoming = 0;
    U8 *unicodeNum = NULL;
    U8 *asciiNum = NULL;
    mmi_ucm_call_type_enum callType;
    mmi_ucm_id_info_struct uniqueId;
    mmi_ucm_index_info_struct indexList;
    mmi_ucm_at_req_ind_struct *msgInd = (mmi_ucm_at_req_ind_struct*)inMsg;
    MMI_BOOL result = MMI_FALSE;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msgInd->action)
    {
        case RMMI_UCM_ATD:
        case RMMI_UCM_BLDN:
        case RMMI_UCM_BLDN_2:
            if (msgInd->action == RMMI_UCM_BLDN)
            {
                callType = MMI_UCM_VOICE_CALL_TYPE;
            }
            else if (msgInd->action == RMMI_UCM_BLDN_2)
            {
                callType = MMI_UCM_VOICE_CALL_TYPE_SIM2;
            }
            else
            {
                if (moduleId == MMI_UCM_FROM_L4C)
                {
                    callType = MMI_UCM_VOICE_CALL_TYPE;
                }
                else
                {                    
                    callType = MMI_UCM_VOICE_CALL_TYPE_SIM2;
                }
            }
            MMI_ASSERT(msgInd->number[msgInd->length] == '\0');
            if (((mmi_ucm_is_sos_number(callType, msgInd->number) == TRUE) && (mmi_ucm_emergency_call_present() == FALSE)) || 
                ((mmi_ucm_is_busy() == FALSE) && (mmi_ucm_dial_option() == TRUE)))
            {
                g_ucm_p->call_misc.curr_module = moduleId;
                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                unicodeNum = OslMalloc((msgInd->length + 1) * ENCODING_LENGTH); /* length carried by AT does not include null terminator */
                memset(unicodeNum, 0, ((msgInd->length + 1) * ENCODING_LENGTH));
                mmi_asc_n_to_ucs2((S8*)unicodeNum, (S8*)msgInd->number, msgInd->length);
                if (!mmi_ucm_app_make_call_with_source(moduleId, callType, unicodeNum))
                {
                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_ATD_NOT_ALLOWED);
                    g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
                    g_ucm_p->call_misc.l4c_info.l4c_source = LMMI_SRC;
                }
                OslMfree(unicodeNum);
            }
            else
            {
                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_ATD_NOT_ALLOWED);
            }
            break;
            
        case RMMI_UCM_MEM_DIAL:
        case RMMI_UCM_MEM_DIAL_2:
        
            asciiNum = OslMalloc(MMI_UCM_MAX_NUM_URI_LEN + 1);
            memset(asciiNum, 0, (MMI_UCM_MAX_NUM_URI_LEN + 1));
            
            unicodeNum = OslMalloc((MMI_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);            
            memset(unicodeNum, 0, ((MMI_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH));
            
            if (msgInd->action == RMMI_UCM_MEM_DIAL)
            {
                callType = MMI_UCM_VOICE_CALL_TYPE;
                result = mmi_phb_get_num_by_sim_index(SIM1, msgInd->number[0], (S8*)unicodeNum, (U16)MMI_UCM_MAX_NUM_URI_LEN);
            }
            else if (msgInd->action == RMMI_UCM_MEM_DIAL_2)
            {
                callType = MMI_UCM_VOICE_CALL_TYPE_SIM2;
                result = mmi_phb_get_num_by_sim_index(SIM2, msgInd->number[0], (S8*)unicodeNum, (U16)MMI_UCM_MAX_NUM_URI_LEN);
            }
            else
            {
                MMI_ASSERT(0);
            }
            
            if (result == MMI_TRUE)
            {
                mmi_ucs2_n_to_asc((S8*)asciiNum, (S8*)unicodeNum, MMI_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);

                if (((mmi_ucm_is_sos_number(callType, (U8*)asciiNum) == TRUE) && (mmi_ucm_emergency_call_present() == FALSE)) || 
                    ((mmi_ucm_is_busy() == FALSE) && (mmi_ucm_dial_option() == TRUE)))
                {
                    g_ucm_p->call_misc.curr_module = moduleId;
                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);

                    if (!mmi_ucm_app_make_call_with_source(moduleId, callType, unicodeNum))
                    {
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_ATD_NOT_ALLOWED);
                        g_ucm_p->call_misc.curr_module = MMI_UCM_FROM_IDLE;
                        g_ucm_p->call_misc.l4c_info.l4c_source = LMMI_SRC;
                    }
                }
                else
                {
                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_ATD_NOT_ALLOWED);
                }
            }
            else
            {
                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_NUM_EXIST);
            }
            
            OslMfree(asciiNum);
            OslMfree(unicodeNum);
            break;
            
        case RMMI_UCM_ATH:         
        case RMMI_UCM_CHUP:
            if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0))
            {
                if (mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list))
                {
                    g_ucm_p->call_misc.curr_module = moduleId;
                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                    groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* incoming call index */
                    mmi_ucm_end_single_action_with_index(groupIndex, 0);
                }
                else if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list))
                {
                    g_ucm_p->call_misc.curr_module = moduleId;
                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                    groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* outgoing call index */
                    mmi_ucm_end_single_action_with_index(groupIndex, 0);
                }
                else if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                {
                    groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* active call index */
                    if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                    {
                        g_ucm_p->call_misc.curr_module = moduleId;
                        g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                        callIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                        mmi_ucm_end_active_and_retrieve_action_with_index(callIndex);
                    }
                    else if (g_ucm_p->call_list.group_info[groupIndex].num_call == 1)
                    {
                        g_ucm_p->call_misc.curr_module = moduleId;
                        g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                        mmi_ucm_end_single_action_with_index(groupIndex, 0);
                    }
                    else if (g_ucm_p->call_list.group_info[groupIndex].num_call > 1)
                    {
                        g_ucm_p->call_misc.curr_module = moduleId;
                        g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                        mmi_ucm_end_conference_action_with_index(groupIndex);
                    }
                }
                else if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                {
                    groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                    if (g_ucm_p->call_list.group_info[groupIndex].num_call == 1)
                    {
                        g_ucm_p->call_misc.curr_module = moduleId;
                        g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                        mmi_ucm_end_single_action_with_index(groupIndex, 0);
                    }
                    else if (g_ucm_p->call_list.group_info[groupIndex].num_call > 1)
                    {
                        g_ucm_p->call_misc.curr_module = moduleId;
                        g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                        mmi_ucm_end_conference_action_with_index(groupIndex);
                    }
                }
                else
                {
                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HANGUP);
                }
            }
            else
            {
                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_ATH_NOT_ALLOWED);
            }
            break;
        case RMMI_UCM_ATA:
            if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0))
            {
                /* RMMI_UCM_ATA cannot answer waiting call */
                numIncoming = mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
                if ((numIncoming != 0) && (numIncoming == mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL)))
                {
                    if (mmi_ucm_answer_option() == TRUE)
                    {
                        g_ucm_p->call_misc.curr_module = moduleId;
                        g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                        mmi_ucm_incoming_call_sendkey();
                    }
                    else
                    {
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_ATA_NOT_ALLOWED);
                    }
                }
                else
                {
                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_ANSWER);
                }
            }
            else
            {
                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_ATA_NOT_ALLOWED);
            }
            break;
        case RMMI_UCM_CHLD:
            if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
                (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0))
            {
                switch(msgInd->opcode)
                {
                    case CSMCC_REL_HELD_OR_UDUB:
                        /* release waiting call */
                        if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list)) || 
                            (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list)))
                        {
                            if (mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* incoming call index */
                                mmi_ucm_end_single_action_with_index(groupIndex, 0);
                            }
                            else
                            {
                                mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                                if ((g_ucm_p->call_list.group_info[groupIndex].call_state == MMI_UCM_HOLD_STATE) && (g_ucm_p->call_list.group_info[groupIndex].num_call == 1))
                                {
                                    g_ucm_p->call_misc.curr_module = moduleId;
                                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                    mmi_ucm_end_single_action_with_index(groupIndex, 0);
                                }
                                else if ((g_ucm_p->call_list.group_info[groupIndex].call_state == MMI_UCM_HOLD_STATE) && (g_ucm_p->call_list.group_info[groupIndex].num_call > 1))
                                {
                                    g_ucm_p->call_misc.curr_module = moduleId;
                                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                    mmi_ucm_end_conference_action_with_index(groupIndex);
                                }
                                else
                                {
                                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                                }
                            }
                        }
                        else /* release held call */
                        {
                            mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list);
                            groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                            if ((g_ucm_p->call_list.group_info[groupIndex].call_state == MMI_UCM_HOLD_STATE) && (g_ucm_p->call_list.group_info[groupIndex].num_call == 1))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_end_single_action_with_index(groupIndex, 0);
                            }
                            else if ((g_ucm_p->call_list.group_info[groupIndex].call_state == MMI_UCM_HOLD_STATE) && (g_ucm_p->call_list.group_info[groupIndex].num_call > 1))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_end_conference_action_with_index(groupIndex);
                            }
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        break;
                    case CSMCC_REL_ACTIVE_AND_ACCEPT:
                        if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                        {
                            if (mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_end_active_and_accept_action();
                            }
                            else if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                                mmi_ucm_end_active_and_retrieve_action_with_index(groupIndex);
                            }
                            else
                            {
                                mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                                if (g_ucm_p->call_list.group_info[groupIndex].num_call == 1)
                                {
                                    g_ucm_p->call_misc.curr_module = moduleId;
                                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                    mmi_ucm_end_single_action_with_index(groupIndex, 0);
                                }
                                else if (g_ucm_p->call_list.group_info[groupIndex].num_call > 1)
                                {
                                    g_ucm_p->call_misc.curr_module = moduleId;
                                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                    mmi_ucm_end_conference_action_with_index(groupIndex);
                                }
                            }
                        }
                        else if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0)
                        {
                            /* RMMI_UCM_CHLD: CSMCC_REL_ACTIVE_AND_ACCEPT can only answer waiting call */
                            numIncoming = mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
                            if ((numIncoming != 0) && (numIncoming != mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL)))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_accept_action();
                            }
                            else if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                                mmi_ucm_retrieve_action_with_index(groupIndex);
                            }
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                            }
                        }
                        else
                        {
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_REL);
                        }
                        break;
                    case CSMCC_REL_SPECIFIC_CALL:
                        groupIndex = -1;
                        callIndex = -1;
                        for (i = 0; i < g_ucm_p->call_list.num_group; i++)
                        {
                            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
                            {
                                if ((g_ucm_p->call_list.group_info[i].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) && 
                                    (g_ucm_p->call_list.group_info[i].call_info[j].call_id == msgInd->call_id))
                                {
                                    groupIndex = i;
                                    callIndex = j;
                                    break;
                                }
                            }
                        }
                        if ((groupIndex != -1) && (callIndex != -1))
                        {
                            g_ucm_p->call_misc.curr_module = moduleId;
                            g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                            mmi_ucm_end_single_action_with_index(groupIndex, callIndex);
                        }
                        else
                        {
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                        }
                        break;
                    case CSMCC_HOLD_ACTIVE_AND_ACCEPT:
                        if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                        {
                            /* 1A1H1W, cannot accept 1W but can swap 1A1H */
                            if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                                mmi_ucm_swap_action_with_index(groupIndex, -1);
                            }
                            else if (mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_hold_and_accept_action();
                            }
                            else
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                                mmi_ucm_hold_action_with_index(groupIndex);
                            }
                        }
                        else if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0)
                        {
                            /* RMMI_UCM_CHLD: CSMCC_HOLD_ACTIVE_AND_ACCEPT can only answer waiting call */
                            numIncoming = mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
                            if ((numIncoming != 0) && (numIncoming != mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL)))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_accept_action();
                            }
                            else if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                                mmi_ucm_retrieve_action_with_index(groupIndex);
                            }
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                            }
                        }
                        else
                        {
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HOLD);
                        }
                        break;
                    case CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL:
                        if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                        {
                            groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* active call index */
                            uniqueId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
                            uniqueId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
                            uniqueId.call_id = msgInd->call_id;
                            if((msgInd->call_id != MMI_UCM_INVALID_ID) && (mmi_ucm_get_index_by_id(&uniqueId, &indexList) == TRUE))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_split_action_with_index(indexList.group_index, indexList.call_index);
                            }
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                            }
                        }
                        else
                        {
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                        }
                        break;
                    case CSMCC_ADD_HELD_CALL:
                        if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list))
                        {
                            if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                                mmi_ucm_conference_action_with_index(groupIndex, -1);
                            }
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_CONFERENCE);
                            }
                        }
                    #ifdef __MMI_DUAL_SIM_MASTER__
                        else if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list))
                        {
                            if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                                mmi_ucm_conference_action_with_index(groupIndex, -1);
                            }
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_CONFERENCE);
                            }
                        }
                    #endif /* __MMI_DUAL_SIM_MASTER__ */
                        else
                        {
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_CONFERENCE);
                        }
                        break;
                    case CSMCC_EXPLICIT_CALL_TRANSFER:
                        if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE, g_ucm_p->call_misc.index_list) == 1)
                        {
                            if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) || 
                                (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == 1))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_explict_call_transfer_action();
                            }
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_ECT);
                            }
                        }
                    #ifdef __MMI_DUAL_SIM_MASTER__
                        else if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, g_ucm_p->call_misc.index_list) == 1)
                        {
                            if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) || 
                                (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == 1))
                            {
                                g_ucm_p->call_misc.curr_module = moduleId;
                                g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                mmi_ucm_explict_call_transfer_action();
                            }
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_ECT);
                            }
                        }
                    #endif /* __MMI_DUAL_SIM_MASTER__ */                       
                        else if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) && 
                                (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE, FALSE, g_ucm_p->call_misc.index_list) == 1))
                        {
                            g_ucm_p->call_misc.curr_module = moduleId;
                            g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                            mmi_ucm_explict_call_transfer_action();
                        }
                    #ifdef __MMI_DUAL_SIM_MASTER__
                        else if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == MMI_UCM_MAX_ACTIVE_TAB) && 
                                (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_SIM2, FALSE, g_ucm_p->call_misc.index_list) == 1))
                        {
                            g_ucm_p->call_misc.curr_module = moduleId;
                            g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                            mmi_ucm_explict_call_transfer_action();
                        }
                    #endif /* __MMI_DUAL_SIM_MASTER__ */                       
                        else
                        {
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_ECT);
                        }
                        break;
                    case CSMCC_ACTIVATE_CCBS_CALL:                        
                        mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_CHLD_NOT_ALLOWED);
                        break;
                    case CSMCC_REL_SPECIFIC_ACTIVE_CALL:
                        if (mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
                        {
                            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
                            uniqueId.call_type = g_ucm_p->call_list.group_info[groupIndex].call_type;
                            uniqueId.group_id = g_ucm_p->call_list.group_info[groupIndex].group_id;
                            uniqueId.call_id = msgInd->call_id;
                            if((msgInd->call_id != MMI_UCM_INVALID_ID) && (mmi_ucm_get_index_by_id(&uniqueId, &indexList) == TRUE))
                            {
                                if ((msgInd->cmd_from_bt == TRUE) &&
                                    (g_ucm_p->call_list.group_info[groupIndex].num_call == 1) && 
                                    (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list)))
                                {
                                    g_ucm_p->call_misc.curr_module = moduleId;
                                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                    groupIndex = g_ucm_p->call_misc.index_list[0].group_index; /* held call index */
                                    mmi_ucm_end_active_and_retrieve_action_with_index(groupIndex);
                                }
                                else
                                {
                                    g_ucm_p->call_misc.curr_module = moduleId;
                                    g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                                    mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                                    mmi_ucm_end_single_action_with_index(indexList.group_index, indexList.call_index);
                                }
                            }                            
                            else
                            {
                                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                            }
                        }
                        else
                        {
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_INVALID_CALLID);
                        }
                        break;
                    case CSMCC_REL_ALL:
                        if (mmi_ucm_app_total_call(MMI_UCM_VOICE_CALL_TYPE_ALL))
                        {
                            g_ucm_p->call_misc.curr_module = moduleId;
                            g_ucm_p->call_misc.l4c_info.l4c_source = msgInd->source_id;
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, TRUE, RMMI_UCM_CAUSE_NONE);
                            mmi_ucm_end_all_action_with_type(MMI_UCM_VOICE_CALL_TYPE_ALL);
                        }
                        else
                        {
                            mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_NO_CALL_TO_HANGUP);
                        }
                        break;						
                    default:
                        MMI_ASSERT(0); /* not valid op_code */
                        break;
                }
            }
            else
            {
                mmi_ucm_at_res_req(moduleId, msgInd->source_id, FALSE, RMMI_UCM_CAUSE_CHLD_NOT_ALLOWED);
            }
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_at_res_req
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_at_res_req(mmi_ucm_module_origin_enum moduleId, U8 source, U8 result, U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_at_res_req_struct *msgReq;
    msgReq = (mmi_ucm_at_res_req_struct*)OslConstructDataPtr(sizeof(mmi_ucm_at_res_req_struct));
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq->source_id = source;
    msgReq->result = result;
    msgReq->cause = cause;

    if (moduleId == MMI_UCM_FROM_L4C)
    {
        mmi_ucm_send_msg(MOD_MMI, MOD_L4C, MSG_ID_MMI_UCM_AT_RES_REQ, msgReq, NULL);
    }
    else if (moduleId == MMI_UCM_FROM_L4C_SIM2)
    {
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_ucm_send_msg(MOD_MMI, MOD_L4C_2, MSG_ID_MMI_UCM_AT_RES_REQ, msgReq, NULL);
    #else /* __MMI_DUAL_SIM_SINGLE_CALL__ */
        OslFreeDataPtr(msgReq);
        MMI_ASSERT(0);
    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_at_general_req
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  type            [IN]            Indicator type
 *  callId          [IN]            Call id
 *  l4c_info        [IN]            L4C info that needs to bypass by UCM
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_at_general_req(mmi_ucm_module_origin_enum moduleId, U8 type, U8 callId, mmi_ucm_l4c_info_struct *l4c_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_general_rcode_req_struct *msgReq;
    msgReq = (mmi_ucm_general_rcode_req_struct*)OslConstructDataPtr(sizeof(mmi_ucm_general_rcode_req_struct));
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq->source_id = l4c_info->l4c_source;
    msgReq->type = type;
    msgReq->call_id = callId;
    msgReq->call_type = l4c_info->l4c_type;
    memcpy(&msgReq->number, &l4c_info->l4c_number, sizeof(l4c_number_struct));

    if (moduleId == MMI_UCM_FROM_L4C)
    {
        mmi_ucm_send_msg(MOD_MMI, MOD_L4C, MSG_ID_MMI_UCM_GENERAL_RCODE_REQ, msgReq, NULL);
    }
    else if (moduleId == MMI_UCM_FROM_L4C_SIM2)
    {
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_ucm_send_msg(MOD_MMI, MOD_L4C_2, MSG_ID_MMI_UCM_GENERAL_RCODE_REQ, msgReq, NULL);
    #else /* __MMI_DUAL_SIM_SINGLE_CALL__ */
        OslFreeDataPtr(msgReq);
        MMI_ASSERT(0);
    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
    }
    else
    {
        MMI_ASSERT(0);
    }
}


#ifdef __BT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_handfree_ciev_req
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  type            [IN]            Indicator type
 *  event           [IN]            Event value
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_bt_handfree_ciev_req(mmi_ucm_module_origin_enum moduleId, U8 type, U8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_hf_ciev_rcode_req_struct *msgReq;
    msgReq = (mmi_ucm_hf_ciev_rcode_req_struct*)OslConstructDataPtr(sizeof(mmi_ucm_hf_ciev_rcode_req_struct));
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION("\n[mmi_ucm_bt_handfree_ciev_req] HandFree CIEV: %d, %d\n", type, event);
    msgReq->ind_type = type;
    msgReq->event= event;

    if (moduleId == MMI_UCM_FROM_L4C)
    {
        mmi_ucm_send_msg(MOD_MMI, MOD_L4C, MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ, msgReq, NULL);
    }
    else if (moduleId == MMI_UCM_FROM_L4C_SIM2)
    {
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_ucm_send_msg(MOD_MMI, MOD_L4C_2, MSG_ID_MMI_UCM_HF_CIEV_RCODE_REQ, msgReq, NULL);
    #else /* __MMI_DUAL_SIM_SINGLE_CALL__ */
        OslFreeDataPtr(msgReq);
        MMI_ASSERT(0);
    #endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */    
    }
    else
    {
        MMI_ASSERT(0);
    }
}
#endif /* __BT_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_master_service_ind_hdlr
 * DESCRIPTION
 *  Dispatch protocol handlers from master side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_master_service_ind_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_mmrr_service_status_ind_struct *msgInd = (mmi_nw_mmrr_service_status_ind_struct*)inMsg;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInd->service_status)
    {
        g_ucm_p->call_misc.nw_service_status = (g_ucm_p->call_misc.nw_service_status | MMI_UCM_SIM1_ACTIVE);
    }
    else
    {
        g_ucm_p->call_misc.nw_service_status = (g_ucm_p->call_misc.nw_service_status & (~MMI_UCM_SIM1_ACTIVE));
    }

    PRINT_INFORMATION("\n[mmi_ucm_master_service_ind_hdlr] nw_service_status: %d \n", g_ucm_p->call_misc.nw_service_status);
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_slave_service_ind_hdlr
 * DESCRIPTION
 *  Dispatch protocol handlers from slave side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_slave_service_ind_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_mmrr_service_status_ind_struct *msgInd = (mmi_nw_mmrr_service_status_ind_struct*)inMsg;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInd->service_status)
    {
        g_ucm_p->call_misc.nw_service_status = (g_ucm_p->call_misc.nw_service_status | MMI_UCM_SIM2_ACTIVE);
    }
    else
    {
        g_ucm_p->call_misc.nw_service_status = (g_ucm_p->call_misc.nw_service_status & (~MMI_UCM_SIM2_ACTIVE));
    }

    PRINT_INFORMATION("\n[mmi_ucm_slave_service_ind_hdlr] nw_service_status: %d \n", g_ucm_p->call_misc.nw_service_status);

}
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MMI_UCM__ */

