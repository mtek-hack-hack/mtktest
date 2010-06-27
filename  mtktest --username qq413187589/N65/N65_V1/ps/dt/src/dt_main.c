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
 *	dt_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the functions to dispatch messages to
 *   appropriate handlers.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *
 *******************************************************************************/
 
#define   DT_MAIN_C

#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"
#include "event_shed.h"
#include "stack_config.h"

#include "dt_common_enum.h"
#include "dt_context.h"

#include "dt_msg_hdlr.h"
#include "dt_analyzer.h"
#include "dt_trc.h"

/*****************************************************************************
 * FUNCTION
 *  dt_main
 * DESCRIPTION
 *  This routine gets the Inter Layer message and calls the appropriate
 *  function handler.
 *
 * PARAMETERS
 *  ilm_ptr IN/OUT
 * RETURNS
 *  kal_bool
 * GLOBALS AFFECTED
 *  None
 *****************************************************************************/
 
void dt_main(ilm_struct *ilm_ptr) 
{

    switch (ilm_ptr->msg_id)
    {

        case MSG_ID_L4CDT_DOWNLOAD_REQ:
        l4cdt_download_req_hdlr((local_para_struct*)ilm_ptr->local_para_ptr,
                                 ilm_ptr->peer_buff_ptr);
        break;

        case MSG_ID_L4CDT_UPLOAD_REQ:
        l4cdt_upload_req_hdlr((local_para_struct*)ilm_ptr->local_para_ptr,
                             ilm_ptr->peer_buff_ptr);
        break;
        
	 case MSG_ID_L4CDT_FILELIST_REQ:
        l4cdt_filelist_req_hdlr((local_para_struct*)ilm_ptr->local_para_ptr,
                                 ilm_ptr->peer_buff_ptr);
        break;
		
        case MSG_ID_L4CDT_UART_TRANSFER_REQ:
        l4cdt_uart_transfer_req_hdlr((local_para_struct*)ilm_ptr->local_para_ptr,
                             ilm_ptr->peer_buff_ptr);        
        break;
        
        case MSG_ID_UART_READY_TO_READ_IND:
        dt_uart_ready_to_read_ind_hdlr((local_para_struct*)ilm_ptr->local_para_ptr,
                             ilm_ptr->peer_buff_ptr);
        break;

        case MSG_ID_UART_READY_TO_WRITE_IND:
        dt_uart_ready_to_write_ind_hdlr((local_para_struct*)ilm_ptr->local_para_ptr,
                             ilm_ptr->peer_buff_ptr);
        break;
        
        case MSG_ID_UART_PLUGOUT_IND:
        dt_usb_plugout_ind_hdlr((local_para_struct*)ilm_ptr->local_para_ptr,
                             ilm_ptr->peer_buff_ptr);
        break;        

        case MSG_ID_TIMER_EXPIRY:
        dt_timer_expiry_hdlr(ilm_ptr);
        break;  
        
        default:
        /* Inform that Unknow Message is received */
        kal_trace(TRACE_ERROR,ERROR_DT_INVALID_MSG);
        break;
    }

    if (DT_PTR->uart_input_queue.length > 0)
    {
    	dt_process_one_cmd();
    }

}	/* End of dt_main */

