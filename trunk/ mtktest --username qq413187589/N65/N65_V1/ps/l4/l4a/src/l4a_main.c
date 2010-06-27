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
 *	l4a_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4A.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifdef __MOD_L4A__

#include <stdarg.h>
#include "kal_release.h"      	/* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "app_buff_alloc.h"
#include "stack_timer.h"
#include "event_shed.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "custom_config.h"

#include "l4a.h"
/*
* FUNCTION                                                            
*	l4a_recvmsg
* DESCRIPTION                                                           
*   process the ilm message which is passed by L4C
*
* CALLS  
*	l4c_main()
* PARAMETERS
* RETURNS
*	none
* GLOBALS AFFECTED
*   none
 */


void l4a_recvmsg(ilm_struct *ilm_ptr)
{
	if(ilm_ptr->msg_id>=MSG_ID_L4A_CODE_BEGIN
	&& ilm_ptr->msg_id< MSG_ID_L4A_CODE_END)
	{
		kal_uint8 src_id=LMMI_SRC;

		if(ilm_ptr->src_mod_id == MOD_WAP) src_id = WAP_SRC;

		l4a_recv_msg_ft[ilm_ptr->msg_id - MSG_ID_L4A_CODE_BEGIN]
			(ilm_ptr->src_mod_id,src_id,ilm_ptr->msg_id,ilm_ptr->local_para_ptr);
	}
}


/*
* FUNCTION                                                            
*	l4a_sendmsg
* DESCRIPTION                                                           
*   1. call l4a_send_msg_ft[] to pack several parameters into an ilm message structure.
*   2. l4a_send_msg_ft[] will call l4a_sengmsg_ilm to send this ilm message out.
*
* CALLS  
*	everyone who want send message to MMI or L4A
* PARAMETERS
*   src: source module 
*   dest: destination module
*   msg: defined in mmi_sap.h
*   ...: message parameter
* RETURNS
*	none
* GLOBALS AFFECTED
*   none
 */

/*
void l4a_sendmsg(module_type src,module_type dest,msg_type msg,...)
{
	va_list args;
	va_start(args, msg);

	if(msg>=MSG_ID_L4A_CODE_BEGIN
	&& msg< MSG_ID_L4A_CODE_END)
	l4a_send_msg_ft[msg - MSG_ID_L4A_CODE_BEGIN] (src,dest,msg,args); // will call l4a_sendmsg_ilm
}
*/

/*
* FUNCTION                                                            
*	l4a_sendmsg_ilm
* DESCRIPTION                                                           
*   get an ilm structure and send to dest module.
*
* CALLS  
*	l4a_send_msg_ft[]
* PARAMETERS
* 	src: source module
* 	dest: destination module
* 	msg: message id which is defined in mmi_sap.h
* 	param: an ilm message structure pointer
* RETURNS
*	none
* GLOBALS AFFECTED
*   none
*/
void l4a_sendmsg_ilm(module_type src,module_type dest,msg_type msg,void *param)
{
	ilm_struct *ilm_ptr = NULL;

	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm( src );

	ilm_ptr->msg_id = (kal_uint16) msg;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)param;

	SEND_ILM(src,dest,MMI_L4C_SAP,ilm_ptr);
}
#endif					 


