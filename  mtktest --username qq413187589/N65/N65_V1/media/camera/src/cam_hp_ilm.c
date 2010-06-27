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
 *	cam_hp_ilm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes send-ilm related critical funcions of camera module.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#ifndef MED_C_NOT_PRESENT


/*==== INCLUDES ===========*/

/* system includes */
#include "kal_release.h" 
#include "kal_trace.h"
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"          /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"         /* Task creation */
#include "app_buff_alloc.h"        /* Declaration of buffer management API */
#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"          /* Event scheduler */
#include "stack_timer.h"         /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_api.h"

#include "med_c_struct.h"
#include "med_c_context.h"

#ifdef __MED_CAM_MOD__

#include "cam_main.h"

/*************************************************************************
* FUNCTION
*   cam_hp_send_event_ind
*
* DESCRIPTION
*   This function is to send camera event indication message. 
*
* PARAMETERS
*   kal_uint8 event
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void cam_hp_send_event_ind(kal_uint8 event, kal_uint8 cause)
{
   media_cam_event_ind_struct *ind_p;
   ilm_struct       *ilm_ptr = NULL;

   /* send indication message to L4 */
   ind_p = (media_cam_event_ind_struct*)
            construct_local_para(sizeof(media_cam_event_ind_struct), TD_CTRL);  

   ind_p->event = event;
   ind_p->cause = cause;
   
   ilm_ptr = allocate_ilm(MOD_VISUAL_HISR);
   ilm_ptr->src_mod_id = MOD_VISUAL_HISR;
   ilm_ptr->dest_mod_id = MOD_MED_C;
   ilm_ptr->sap_id = MED_C_SAP;
   
   ilm_ptr->msg_id = (msg_type)MSG_ID_MEDIA_C_CAM_EVENT_IND;
   ilm_ptr->local_para_ptr = (local_para_struct*)ind_p;
   ilm_ptr->peer_buff_ptr = NULL;

   msg_send_ext_queue(ilm_ptr);

}
#endif /* __MED_CAM_MOD__ */


#endif /* MED_C_NOT_PRESENT */

