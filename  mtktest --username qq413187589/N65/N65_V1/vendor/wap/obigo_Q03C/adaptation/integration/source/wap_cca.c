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
 *  wap_cca.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA's Configuration Source, and handling of CCA document queuing and forwarding mechanism.
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
 ****************************************************************************/
#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stack_types.h"
#include "task_config.h"

#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_cmmn.h"

#include "wap.h"
#include "wap_ps_struct.h"
#include "Widget_extension.h"
#include "CentralConfigAgentGProt.h"


#define WAP_CCA_MAX_CONFIG_DOC  10
#define WAP_CCA_STATE_IDLE  0
#define WAP_CCA_STATE_WAIT  1


typedef struct
{
    MSF_UINT16 spec_id;
    MSF_UINT16 sim_id;
    MSF_INT32 hConfig;
} wap_cca_config_doc_t;

static wap_cca_config_doc_t wap_cca_config_doc_queue[WAP_CCA_MAX_CONFIG_DOC];
static MSF_INT32 wap_cca_doc_queue_count = 0;
static MSF_UINT8 wap_cca_state = WAP_CCA_STATE_IDLE;


void wap_cca_send_next_new_doc(void);


/*****************************************************************************
 * FUNCTION
 *  wap_cca_config_doc_remove_first
 * DESCRIPTION
 *  Remove top CCA document from queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_cca_config_doc_remove_first(void)
{
    MSF_INT32 i;

    if (!wap_cca_doc_queue_count)
        return;

    for (i=0; i<wap_cca_doc_queue_count-1; i++)
    {
        wap_cca_config_doc_queue[i].spec_id = wap_cca_config_doc_queue[i+1].spec_id;
        wap_cca_config_doc_queue[i].sim_id = wap_cca_config_doc_queue[i+1].sim_id;
        wap_cca_config_doc_queue[i].hConfig = wap_cca_config_doc_queue[i+1].hConfig;
    }

    wap_cca_doc_queue_count--;
    wap_cca_config_doc_queue[wap_cca_doc_queue_count].spec_id = 0xFFFF;
    wap_cca_config_doc_queue[wap_cca_doc_queue_count].sim_id = 0xFFFF;
    wap_cca_config_doc_queue[wap_cca_doc_queue_count].hConfig = 0;
}

/*****************************************************************************
 * FUNCTION
 *  wap_cca_register_new_doc
 * DESCRIPTION
 *  API for PRS to use to register and forward a converted configuration document to CCA.
 * PARAMETERS
 *  spec_id     [in]
 *  sim_id      [in]
 *  hConfig     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void wap_cca_register_new_doc(MSF_UINT16 spec_id, MSF_UINT16 sim_id, MSF_INT32 hConfig)
{
    if (wap_cca_doc_queue_count >= WAP_CCA_MAX_CONFIG_DOC)
        return;

    wap_cca_config_doc_queue[wap_cca_doc_queue_count].spec_id = spec_id;
    wap_cca_config_doc_queue[wap_cca_doc_queue_count].sim_id = sim_id;
    wap_cca_config_doc_queue[wap_cca_doc_queue_count].hConfig = hConfig;
    wap_cca_doc_queue_count++;

    wap_cca_send_next_new_doc();
}

/*****************************************************************************
 * FUNCTION
 *  wap_cca_send_next_new_doc
 * DESCRIPTION
 *  Attempts to send next document in queue to CCA if available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_cca_send_next_new_doc(void)
{
    ilm_struct *ilm_ptr;
    mmi_cca_source_new_doc_ind_struct *new_doc_ind = NULL;

    if (wap_cca_state!=WAP_CCA_STATE_IDLE || !wap_cca_doc_queue_count)
        return;

    ilm_ptr = allocate_ilm(MOD_WAP);

    new_doc_ind = (mmi_cca_source_new_doc_ind_struct*)construct_local_para((kal_uint16)sizeof(mmi_cca_source_new_doc_ind_struct), 0);
    new_doc_ind->spec_id = (U16)(wap_cca_config_doc_queue[0].spec_id);
    new_doc_ind->sim_id = (U16)(wap_cca_config_doc_queue[0].sim_id);
    new_doc_ind->hConfig = (S32)(wap_cca_config_doc_queue[0].hConfig);
   
    ilm_ptr->msg_id			= MSG_ID_MMI_CCA_SOURCE_NEW_DOC_IND;
    ilm_ptr->local_para_ptr	= (local_para_struct *)new_doc_ind;
    ilm_ptr->peer_buff_ptr 	= NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, 0, ilm_ptr);

    wap_cca_state = WAP_CCA_STATE_WAIT;
    wap_cca_config_doc_remove_first();
}

/*****************************************************************************
 * FUNCTION
 *  wap_cca_msg_hdlr
 * DESCRIPTION
 *  Message Handler for primitives from CCA
 * PARAMETERS
 *  ilm_ptr     [in]
 * RETURNS
 *  void
 *****************************************************************************/
void wap_cca_msg_hdlr(ilm_struct *ilm_ptr)
{
    switch(ilm_ptr->msg_id)
    {
        case MSG_ID_MMI_CCA_SOURCE_NEW_DOC_RSP:
            wap_cca_state = WAP_CCA_STATE_IDLE;
            wap_cca_send_next_new_doc();
            break;

        default:
			break;
    }   
}
