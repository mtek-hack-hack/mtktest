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
 *	dt_aux_msg_hdlr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for helping functions for message handlers.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/


 #define DT_AUX_MSG_HDLR_C

#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "app_buff_alloc.h"
#include "stack_timer.h"
#include "event_shed.h"



#include "dt_common_enum.h"
#include "uart_sw.h"
#include "dt_context.h"
#include "l4c2dt_struct.h"
#include "dt_utility.h"

/*****************************************************************************
* FUNCTION
*  dt_send_msg_to_l4c
*
* DESCRIPTION
*   This is dt_send_msg_to_l4c function of L4C module.
*   send msg to csmss module
*
* PARAMETERS
*  msg_name    IN    msg id to be sent
*  param_ptr   IN    local parameter of the msg to be sent
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
void dt_send_msg_to_l4c (msg_type msg_name, void *param_ptr)
{
   ilm_struct *ilm_ptr = NULL;

   /* First allocate a memory for an interlayer message structure */
   ilm_ptr = allocate_ilm( MOD_DT );

   ilm_ptr->msg_id = (kal_uint16) msg_name;/* Set the message id */
   ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message to be
                            sent to TCM. Hence this field is null.*/
   ilm_ptr->local_para_ptr = (local_para_struct *)param_ptr;
  
   #ifdef __GEMINI__
   SEND_ILM( MOD_DT, DT_PTR->src_mod_id, DT_L4C_SAP, ilm_ptr);
   #else
   SEND_ILM( MOD_DT, MOD_L4C, DT_L4C_SAP, ilm_ptr);
   #endif

   return;
}

void dt_send_l4c_uart_transfer_ind(void)
{
    l4cdt_uart_transfer_ind_struct *dt_uart_transfer_ind_ptr;

    dt_uart_transfer_ind_ptr = (l4cdt_uart_transfer_ind_struct *)
				construct_local_para(
					(kal_uint16)sizeof(l4cdt_uart_transfer_ind_struct),
                    TD_CTRL);

    dt_uart_transfer_ind_ptr->port = DT_PTR->transfered_port;
    
    dt_send_msg_to_l4c(MSG_ID_L4CDT_UART_TRANSFER_IND, dt_uart_transfer_ind_ptr);
   
} /* end of dt_send_l4c_uart_transfer_ind */

void dt_send_l4c_download_cnf(kal_uint16 cause)
{
    l4cdt_download_cnf_struct *dt_download_cnf_ptr;

    dt_download_cnf_ptr = (l4cdt_download_cnf_struct *)
				construct_local_para(
					(kal_uint16)sizeof(l4cdt_download_cnf_struct),
                    TD_CTRL);
    
    dt_download_cnf_ptr->cause = cause;

    dt_clear_uart_queue();
	
    dt_send_msg_to_l4c(MSG_ID_L4CDT_DOWNLOAD_CNF, dt_download_cnf_ptr);
   
} /* end of dt_send_l4c_download_cnf */


void dt_send_l4c_upload_cnf(kal_uint16 cause)
{
    l4cdt_upload_cnf_struct *dt_upload_cnf_ptr;

    dt_upload_cnf_ptr = (l4cdt_upload_cnf_struct *)
				construct_local_para(
					(kal_uint16)sizeof(l4cdt_upload_cnf_struct),
                    TD_CTRL);
    
    dt_upload_cnf_ptr->cause = cause;

    dt_clear_uart_queue();
			
    dt_send_msg_to_l4c(MSG_ID_L4CDT_UPLOAD_CNF, dt_upload_cnf_ptr);
   
} /* end of dt_send_l4c_upload_cnf */

void dt_send_l4c_filelist_cnf(kal_uint16 cause)
{
    l4cdt_filelist_cnf_struct *dt_filelist_cnf_ptr;

    dt_filelist_cnf_ptr = (l4cdt_filelist_cnf_struct *)
				construct_local_para(
					(kal_uint16)sizeof(l4cdt_filelist_cnf_struct),
                    TD_CTRL);
    
    dt_filelist_cnf_ptr->cause = cause;

    dt_clear_uart_queue();
	
    dt_send_msg_to_l4c(MSG_ID_L4CDT_FILELIST_CNF, dt_filelist_cnf_ptr);
   
} /* end of dt_send_l4c_upload_cnf */



