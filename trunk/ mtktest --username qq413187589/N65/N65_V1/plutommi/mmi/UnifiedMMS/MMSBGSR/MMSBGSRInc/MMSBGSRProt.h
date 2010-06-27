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
 *  MMSBGSRProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file local API's Variables and the local context for MMS BGSR Application
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#ifndef __MMI_BGSR_PROT_H_
#define __MMI_BGSR_PROT_H_

#include "MMI_features.h"

#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "custom_wap_config.h"
#include "bam_struct.h"
#include "MMSBGSRGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#define MMI_MMS_BGSR_MAX_MSG_NUM    100
#define MMI_MMS_BGSR_ADM_MEM_SIZE 1000 /*  MMI_MMS_BGSR_MAX_MSG_NUM *           \
                                       (sizeof(mmi_mms_bgsr_msg_struct))    \
                                       + sizeof(mmi_mms_bgsr_context_struct)*/

/***************************************************************************** 
* Typedef
*****************************************************************************/

typedef struct
{
    KAL_ADM_ID              mem_pool_id; /* ADM pool ID */
    kal_uint32              mmi_mms_bgsr_retry_timer;
    kal_uint32              mmi_mms_bgsr_send_msg_id;
    kal_uint32              mmi_mms_bgsr_download_msg_id;
    kal_uint8               mmi_mms_bgsr_retrieval_setting;
    mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_send_q;
    mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_send_fail_q;
    mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_download_q;
    mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_download_fail_q;
    mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_free_q;
} mmi_mms_bgsr_context_struct;



extern mmi_mms_bgsr_context_struct g_mmi_mms_bgsr_context;
extern mmi_mms_bgsr_context_struct *mmi_mms_bgsr_p;
extern kal_uint8 mmi_mms_bgsr_adm_mem[MMI_MMS_BGSR_ADM_MEM_SIZE];
extern mmi_mms_bgsr_msg_struct mmi_mms_bgsr_msg_struct_array[MMI_MMS_BGSR_MAX_MSG_NUM];


/***************************************************************************** 
* Function Declaration
*****************************************************************************/

void mmi_mms_bgsr_init(void);
mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_extract_q (
                                    kal_uint32 msg_id, 
                                    mmi_mms_bgsr_msg_struct **queue);
mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_get_q( 
                                    kal_uint32 msg_id, 
                                    mmi_mms_bgsr_msg_struct* queue );
BOOL mmi_mms_bgsr_find_q(kal_uint32 msg_id, 
                                        mmi_mms_bgsr_msg_struct* queue, 
                                        mmi_mms_bgsr_msg_struct* fail_q);
void mmi_mms_bgsr_enqueue(mmi_mms_bgsr_msg_struct *msg, 
                                            mmi_mms_bgsr_msg_struct **queue);
mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_delete_queue( 
                                    mmi_mms_bgsr_msg_struct **queue, 
                                    kal_uint32 except_msg_id );
void mmi_mms_bgsr_init_context(void);
void mmi_mms_bgsr_create_adm_mem(void);
void mmi_mms_bgsr_set_protocol_event_handler(void);
void mmi_mms_bgsr_send_mms_req( mmi_mms_bgsr_msg_struct *msg );
void mmi_mms_bgsr_abort_send_mms_req(kal_uint32 msg_id);
void mmi_mms_bgsr_delete_mms_req(kal_uint32 msg_id);
void mmi_mms_bgsr_save_mms_req(kal_uint32 msg_id, kal_uint16 folder);
void mmi_mms_bgsr_download_mms_req( mmi_mms_bgsr_msg_struct *msg );
void mmi_mms_bgsr_abort_download_mms_req(kal_uint32 msg_id);
void mmi_mms_bgsr_show_mms_status_icon(const mmi_mms_bgsr_indicator_type_enum status);
void mmi_mms_bgsr_action_fsm (mmi_mms_bgsr_action_type_enum action,
                                        void *rsp,
                                        kal_uint16 *text);
kal_uint16 mmi_mms_bgsr_translate_msg_id_to_nvram_ind(kal_uint32 msg_id);
kal_uint8 mmi_mms_bgsr_check_popup(void);
void mmi_mms_bgsr_get_mem_status_req(void);
kal_uint8 mmi_mms_bgsr_is_sync(void);
kal_uint32 mmi_mms_bgsr_get_free_space(void);
void mmi_mms_bgsr_timeout_procedure(void);
void mmi_mms_bgsr_init_msg_array(void);
void mmi_mms_bgsr_timeout_procedure(void);
kal_uint8 mmi_mms_bgsr_is_ready(void);
void mmi_mms_bgsr_sync(void);
kal_uint8 mmi_mms_bgsr_mms_is_exported(void);
void mmi_mms_bgsr_echo_current_info(void);

#endif /* __MMI_BGSR_PROT_H_ */ 
