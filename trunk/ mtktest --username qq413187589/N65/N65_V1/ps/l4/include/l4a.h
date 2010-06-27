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
 *	l4a.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4A used.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _L4A_H_
#define _L4A_H_

/////////////////////////////////////////
#define DISABLE_MSG_ID_MMI_EQ_PLAY_AUDIO_RSP
#define DISABLE_MSG_ID_MMI_EQ_STOP_AUDIO_RSP
#define DISABLE_MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP
#define DISABLE_MSG_ID_MMI_EQ_SET_MUTE_RSP
#define DISABLE_MSG_ID_MMI_CC_START_DTMF_RSP
#define DISABLE_MSG_ID_MMI_CC_STOP_DTMF_RSP
#define DISABLE_MSG_ID_MMI_PHB_STARTUP_READ_NEXT_RSP
#define DISABLE_MSG_ID_MMI_EQ_PLAY_PATTERN_RSP
#define DISABLE_MSG_ID_MMI_CC_REL_COMP_RSP
#define DISABLE_MSG_ID_MMI_SAT_EVDL_IDLE_SCREEN_AVAILABLE_RSP



#include "keypad_sw.h"
typedef kal_bool (*drv_get_key_func)(kbd_data *);

#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#ifdef __MCD__

    
	#ifdef __SAT__
	#include "ps2sat_struct.h"
	#include "mcd_ps2sat_peer.h"
	#endif

	#include "med_struct.h"

	#ifdef __MOD_SMU__
	#include "ps2sim_struct.h"
	#include "sim_common_enums.h"
	#include "smu_common_enums.h"
	#include "l4c2smu_struct.h"
	#endif
	#include "csmss_common_enums.h"

	#include "mcd_l4_common.h"
	#include "l4c_common_enum.h"
	#include "rmmi_common_enum.h"
	#include "rmmi_context.h"
	#include "l4c_rspfmttr.h"
	#include "l4c_context.h"

	#include "l4c_aux_struct.h"

	#ifdef __MOD_CSM__
	#include "l4_defs.h"
	#include "mcd_ss_parameters.h"
	#include "l4c_common_enum.h"
#include "csmcc_enums.h"
#include "csmcc_common_enums.h"
#include "ps2sat_struct.h"
#include "l4c2csm_cc_struct.h"

	#include "l4c2csm_ss_struct.h"
	#include "Csmcc_common_enums.h"
	#include "csmcc_enums.h"
	#include "Csmcc_bc_types.h"
	#include "mcd_ss_tcapmessages.h"
	#include "mncc_struct.h"
	#include "csmcc_defs.h"
	#include "Csmcc_types.h"
	#include "csmcc_atfunc.h"
	#include "l4c_cc_cmd.h"
	#include "l4c_ciss_cmd.h"
	#include "L4c_ss_parse.h"
	#endif

	#include "l4c_data_cmd.h"

	#ifdef __MOD_UEM__
	#include "device.h"
	#include "keypad_sw.h"
	#include "l4c2uem_struct.h"
	#include "mcd_uem_peer.h"
	#include "uart_sw.h"
	#include "l4c_eq_cmd.h"
	#include "l4c_tst.h"
	#endif

	#ifdef __MOD_RAC__
	#include "l4c_nw_cmd.h"
	#include "l4crac_enums.h"
	#include "mcd_l3_inc_struct.h"
	#endif

	#ifdef __MOD_PHB__
	#include "l4c_phb_cmd.h"
	#include "L4c2phb_enums.h"
	#endif

	#ifdef __MOD_SMSAL__
	#include "mcd_l4c2smsal_peer.h"
	#include "l4c2smsal_struct.h"
	#include "Smsal_l4c_defs.h"
	#include "Smsal_l4c_enum.h"
	#include "l4c_sms_cmd.h"
	#include "smsal_defs.h"
	#endif

	#ifdef __MOD_SMU__
	#include "l4c_sim_cmd.h"
	#endif

	#ifdef __MOD_TCM__
	#include "l4c2abm_struct.h"
	#include "l4c2tcm_struct.h"
	#include "mcd_l3_inc_struct.h"
	#include "mcd_l3_inc_gprs_struct.h"
	#include "mmi_l3_enums.h"
	#include "mmi_sm_enums.h"
	#include "l3_inc_enums.h"
	#include "tcm_common_enums.h"
	#include "ppp_l4_enums.h"
	#include "tcm_common.h"
	#include "l4c2tcm_func.h"
//	#ifdef __TCPIP__
#include "l4c2abm_struct.h"
//#endif /* __TCPIP__ */
	#include "l4c_gprs_cmd.h"
	#endif /* __MOD_TCM__ */

	#ifdef __EM_MODE__
	#include "em_struct.h"
	#include "l4c_em.h"
	#endif

#else

	#include "med_struct.h"

	#ifdef __SAT__
	#include "ps2sat_struct.h"
	#include "ps2sat_peer_struct.h"
	#endif


	#ifdef __MOD_SMU__
	#include "ps2sim_struct.h"
	#include "sim_common_enums.h"
	#include "smu_common_enums.h"
	#include "l4c2smu_struct.h"
	#endif
	#include "csmss_common_enums.h"

	#include "l4_common_struct.h"
	#include "l4c_common_enum.h"
	#include "rmmi_common_enum.h"
	#include "rmmi_context.h"
	#include "l4c_rspfmttr.h"
	#include "l4c_context.h"

	#include "l4c_aux_struct.h"

	#ifdef __MOD_CSM__
	#include "l4_defs.h"
	#include "ss_parameters.h"
	#include "l4c_common_enum.h"
#include "csmcc_enums.h"
#include "csmcc_common_enums.h"
#include "ps2sat_struct.h"
#include "l4c2csm_cc_struct.h"

	#include "l4c2csm_ss_struct.h"
	#include "Csmcc_common_enums.h"
	#include "csmcc_enums.h"
	#include "Csmcc_bc_types.h"
	#include "ss_tcapmessages.h"
	#include "mncc_struct.h"
	#include "csmcc_defs.h"
	#include "Csmcc_types.h"
	#include "csmcc_atfunc.h"
	#include "l4c_cc_cmd.h"
	#include "l4c_ciss_cmd.h"
	#include "L4c_ss_parse.h"
	#endif

	#include "l4c_data_cmd.h"

	#ifdef __MOD_UEM__
	#include "device.h"
	#include "keypad_sw.h"
	#include "l4c2uem_struct.h"
	#include "uem_peer_struct.h"
	#include "l4c_eq_cmd.h"
	#endif

	#ifdef __MOD_RAC__
	#include "l4c_nw_cmd.h"
	#include "l4crac_enums.h"
	#endif

	#ifdef __MOD_PHB__
	#include "l4c_phb_cmd.h"
	#include "L4c2phb_enums.h"
	#endif

	#ifdef __MOD_SMSAL__
	#include "l4c2smsal_peer_struct.h"
	#include "l4c2smsal_struct.h"
	#include "Smsal_l4c_defs.h"
	#include "Smsal_l4c_enum.h"
	#include "l4c_sms_cmd.h"
	#include "smsal_defs.h"
	#endif

	#ifdef __MOD_SMU__
	#include "l4c_sim_cmd.h"
	#endif

	#ifdef __MOD_TCM__
	#include "l4c2tcm_struct.h"
	#include "l3_inc_struct.h"
	#include "mmi_l3_enums.h"
	#include "mmi_sm_enums.h"
	#include "l3_inc_enums.h"
	#include "tcm_common_enums.h"
	#include "ppp_l4_enums.h"
	#include "tcm_common.h"
	#include "l4c2tcm_func.h"
	//#ifdef __TCPIP__
#include "l4c2abm_struct.h"
//#endif /* __TCPIP__ */
	#include "l4c_gprs_cmd.h"
	#endif /* __MOD_TCM__ */

	#ifdef __EM_MODE__
	#include "em_struct.h"
	#include "l4c_em.h"
	#endif

	
#endif
#include "l4c_msghdlr.h"
#include "rmmi_bt.h"
#include "rmmi_common_enum.h"
#include "phb_defs.h"
#include "mmi_msg_struct.h"
#include "l4c_utility.h"

/******************************************************************************************
 * define
 ******************************************************************************************/
typedef kal_bool (*L4A_BOOL_FUNCTION)();
typedef void (*L4A_VOID_FUNCTION)();

/*
extern const msg_type l4a_rsp_table[MSG_ID_MMI_MESSAGE_SUM];
extern const L4A_BOOL_FUNCTION l4a_req_ft[];
extern const L4A_VOID_FUNCTION l4a_send_msg_ft[];
*/

extern const L4A_VOID_FUNCTION l4a_recv_msg_ft[];


extern void l4c_init_lmmi(void);
//extern void l4a_sendmsg(module_type src,module_type dest,msg_type msg,...);
extern void l4a_sendmsg_ilm(module_type src,module_type dest,msg_type msg,void *param);
extern void l4a_recvmsg(ilm_struct *ilm_ptr);

#endif


