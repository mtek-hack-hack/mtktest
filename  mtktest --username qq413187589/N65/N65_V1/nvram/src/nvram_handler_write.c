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
 * nvram_handler_write.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is write handler function of NVRAM module.
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
#include "stdio.h"
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */

#include "kal_trace.h"
#include "nvram_trc.h"

#include "nvram.h"

/* Prerequisite of nvram_context.h */
#include "custom_nvram_sec.h"
#include "nvram_defs.h"
#include "nvram_context.h"

#include "nvram_ilm.h"

#include "nvram_io.h"
#include "nvram_handler_write.h"
#include "nvram_user_defs.h"

#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */ 

#undef  _FILE_CODE_
#define _FILE_CODE_ _NVRAM_WRITE_C_

static void nvram_write_confirm(module_type dest_id, nvram_errno_enum result, nvram_write_req_struct *nvram_write_req);


/*****************************************************************************
 * FUNCTION
 *  nvram_write_handler
 * DESCRIPTION
 *  This is nvram_write_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_write_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_req_struct *nvram_write_req = (nvram_write_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_NVRAM_WRITE);

    ASSERT(nvram_write_req);

    if (nvram_ptr->state == NVRAM_STATE_READY)
    {

        ltable_entry_struct *ldi;

        kal_uint8 *pdu_ptr;
        kal_uint16 pdu_length;

        ASSERT(ilm_ptr->peer_buff_ptr != NULL);

        pdu_ptr = get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length);

        ASSERT(pdu_ptr != NULL);

        /**
        * Invalid input paramters.
        * file_idx / LID : 1 ~ (total_LID - 1)
        * para / section: 1 ~ total_records
        */
        if (!NVRAM_IS_LID_VALID(nvram_write_req->file_idx))
        {
            ASSERT(0);
            nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_LID, nvram_write_req);
            return;
        }

        nvram_get_data_item(ldi, nvram_write_req->file_idx);

        if ((nvram_write_req->para < 1) ||
    #ifdef __NVRAM_COMPOSED_SUPPORT__
            ((ldi->category & NVRAM_CATEGORY_COMPOSED) &&
             (nvram_write_req->para > nvram_ptr->ltable.table[ldi->device]->total_records)) ||
    #endif /* __NVRAM_COMPOSED_SUPPORT__ */ 
            (nvram_write_req->para > ldi->total_records))
        {
            nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_RECORD, nvram_write_req);
            return;
        }

        if (pdu_length != ldi->size)
        {
            nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_SIZE, nvram_write_req);
        }
        else
        {
        #if defined(__SHADOW_SUPPORT_SB__)
            if (NORMAL_BOOT == stack_query_boot_mode())
            {
                if (!(ldi->category & NVRAM_CATEGORY_SHADOW))
                {
                    kal_bool LID_NOT_IN_SHADOW = KAL_FALSE;
                    EXT_ASSERT(LID_NOT_IN_SHADOW, ldi->LID, 0, 0);
                }

                nvram_write_confirm(
                    ilm_ptr->src_mod_id,
                    nvram_add_shadow_request(ldi, nvram_write_req->para, pdu_ptr),
                    nvram_write_req);

                nvram_flush_shadow();
            }
            else
        #elif defined(__SHADOW_SUPPORT_MS__)    /* }{ */
            if (USBMS_BOOT == stack_query_boot_mode())
            {
                if (ldi->category & NVRAM_CATEGORY_SHADOW_MS)
                {
                    nvram_write_confirm(
                        ilm_ptr->src_mod_id,
                        nvram_add_shadow_request(ldi, nvram_write_req->para, pdu_ptr),
                        nvram_write_req);
                }
                else
                {
                    nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_OK, nvram_write_req);
                }

            }
            else
        #endif 
            if (ldi->attr & NVRAM_ATTR_RING)
            {
                kal_uint8 *index = (kal_uint8 *)get_ctrl_buffer(ldi->size);
                memset(index, 0, ldi->size);
                if (nvram_read_data_item(ldi, 1, 1, index, ldi->size) == NVRAM_IO_ERRNO_OK)
                {
                    nvram_write_req->para = (kal_uint16)index[0];

                    nvram_write_req->para++;
                   
                    if (nvram_write_req->para > ldi->total_records || nvram_write_req->para < 2)
                        nvram_write_req->para = 2;
                        
                    index[0] = (kal_uint8)nvram_write_req->para;

                    if (nvram_write_data_item(ldi, 1, index, KAL_FALSE) != NVRAM_IO_ERRNO_OK)
                    {
                        free_ctrl_buffer(index);
                        nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_WRONG_RINGLID, nvram_write_req);
                        return;
                    }   
                        
                    if (nvram_write_data_item(ldi, nvram_write_req->para, pdu_ptr, KAL_FALSE))
                    {    
                        free_ctrl_buffer(index);
                        nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_OK, nvram_write_req);
                        return;
                    }
                }
                free_ctrl_buffer(index);
                nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_WRONG_RINGLID, nvram_write_req);
   
            }
            else
            {
                nvram_write_confirm(
                    ilm_ptr->src_mod_id,
                    nvram_write_data_item(ldi, nvram_write_req->para, pdu_ptr, KAL_FALSE),
                    nvram_write_req);
            }
        }
    }
    /* State error */
    else
    {
        nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_FAIL, nvram_write_req);
    }
}   /* end of nvram_write_handler */


/*****************************************************************************
 * FUNCTION
 *  nvram_write_confirm
 * DESCRIPTION
 *  This is nvram_write_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id             [IN]        
 *  result              [IN]        
 *  nvram_write_req     [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_write_confirm(module_type dest_id, nvram_errno_enum result, nvram_write_req_struct *nvram_write_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *nvram_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_CNF, result);

    nvram_write_cnf = (nvram_write_cnf_struct*) construct_local_para(sizeof(nvram_write_cnf_struct), TD_CTRL);
    ASSERT(nvram_write_cnf != NULL);

    nvram_write_cnf->result = result;
    nvram_write_cnf->file_idx = nvram_write_req->file_idx;
    nvram_write_cnf->para = nvram_write_req->para;
    nvram_write_cnf->access_id = nvram_write_req->access_id;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_WRITE_CNF, nvram_write_cnf, NULL);

    return;
}   /* end of nvram_write_confirm */

