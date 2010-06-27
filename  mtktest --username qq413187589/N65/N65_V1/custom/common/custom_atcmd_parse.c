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
 * Filename:
 * ---------
 * custom_atcmd_parse.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for parsing general proprietary AT command.
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define RMMI_PARSER_C

#include "kal_non_specific_general_types.h"


#include <stdio.h>
#include <string.h>
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "app_buff_alloc.h"
#include "stack_timer.h"
#include "event_shed.h"
#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "uart_sw.h"

#ifdef __BTMTK__
#include "Bluetooth_struct.h"
#endif

#ifndef __L1_STANDALONE__
extern kal_bool tst_process_pc_command_from_ATCmd(kal_int32 len, kal_uint8 *param);
#endif

/*****************************************************************************
* FUNCTION
*  	rmmi_general_command_parsing()
* DESCRIPTION
*   	This function should parse general proprietary AT command request.
*     Each owner should maintain and modify the code.
* PARAMETERS
*   	kal_uint32 op 
*	kal_uint32 data_len 
*	kal_uint8 *data_str
* RETURNS
*	KAL_TRUE or KAL_FALSE
*****************************************************************************/
kal_bool rmmi_general_command_parsing(kal_uint32 op, 
												kal_uint32 data_len, 
												kal_uint8 *data_str)
{
	kal_bool ret_val = KAL_FALSE;
	
	switch(op)
	{
		case 1: /*mtk00924_060626: for LCM calibration*/
		{
			#ifndef __L1_STANDALONE__
			ret_val = tst_process_pc_command_from_ATCmd(data_len, data_str);
			#endif
			break;
		}
		case 2: /* add by stanley 2006-07-03*/
		{
#if  defined(__BTMTK__)
			bt_test_cmd_req_struct  *param_ptr;
			param_ptr = (bt_test_cmd_req_struct *)construct_local_para(
															(kal_uint16)sizeof(bt_test_cmd_req_struct),
															TD_CTRL);   

			kal_mem_cpy(param_ptr->test_cmd_content, data_str, data_len);
			l4c_send_msg_to_bt(MSG_ID_BT_TEST_CMD_REQ, param_ptr);	 
			ret_val = KAL_TRUE;
#endif
		}

		
		
/************************sample code begin************************/			
//		case op: /*owner_date: purpose*/
//		{
//			/*call proprietary parsing function here and AT will give result  */
//			/*code OK/ERROR according to return value of parsing function*/	
//
//			break;
//		}
/************************sample code end*************************/

		default:
			break;	
	}
	return ret_val;
}

