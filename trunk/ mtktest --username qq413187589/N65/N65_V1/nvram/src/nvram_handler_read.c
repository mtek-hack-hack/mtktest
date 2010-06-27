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
 * nvram_handler_read.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is read handler function of NVRAM module.
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "stdio.h"
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "nvram_trc.h"

#include "nvram.h"

/* Prerequisite of nvram_context.h */
#include "custom_nvram_sec.h"
#include "nvram_defs.h"
#include "nvram_drval_fat.h"
#include "nvram_context.h"

#include "nvram_ilm.h"

#include "nvram_io.h"
#include "nvram_handler_read.h"
#include "nvram_user_defs.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _NVRAM_READ_C_

/***************************************************************************** 
* Global Function
*****************************************************************************/
void nvram_read_confirm
    (module_type dest_id,
     nvram_errno_enum result, nvram_read_req_struct *nvram_read_req, kal_uint16 size, peer_buff_struct *peer_buf_ptr);


/*****************************************************************************
 * FUNCTION
 *  nvram_read_handler
 * DESCRIPTION
 *  This is nvram_read_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_read_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_req_struct *nvram_read_req = (nvram_read_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(nvram_read_req != NULL);

    kal_trace(TRACE_FUNC, FUNC_NVRAM_READ);

    if (nvram_ptr->state == NVRAM_STATE_READY)
    {
        ltable_entry_struct *ldi;

      /**
       * Invalid input paramters.
       * file_idx / LID : 1 ~ (total_LID - 1)
       * para / section: 1 ~ total_records
       */
        if (!NVRAM_IS_LID_VALID(nvram_read_req->file_idx))
        {
            nvram_read_confirm(
                ilm_ptr->src_mod_id,
                NVRAM_IO_ERRNO_INVALID_LID,
                nvram_read_req,
                (kal_uint16) NVRAM_INVALID_VALUE,
                NULL);
            return;
        }

        nvram_get_data_item(ldi, nvram_read_req->file_idx);

        if ((nvram_read_req->para < 1) ||
    #ifdef __NVRAM_COMPOSED_SUPPORT__
            ((ldi->category & NVRAM_CATEGORY_COMPOSED) &&
             (nvram_read_req->para > nvram_ptr->ltable.table[ldi->device]->total_records)) ||
    #endif /* __NVRAM_COMPOSED_SUPPORT__ */ 
            (nvram_read_req->para > ldi->total_records))
        {
            nvram_read_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_RECORD, nvram_read_req, (kal_uint16) NVRAM_INVALID_VALUE, NULL);     /* nvram_read_confirm */
            return;
        }
        else
        {
            peer_buff_struct *peer_buf_ptr;
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;

            if (!(ldi->attr & NVRAM_ATTR_MULTIREC_READ) ||
        #ifdef __MULTI_BOOT__
                (FACTORY_BOOT == stack_query_boot_mode()) ||    /* META won't multi-read */
        #endif 
                (ilm_ptr->src_mod_id == MOD_NVRAM)  /* TST handler */
                )
                nvram_read_req->rec_amount = 1;
            else
            {

                if (nvram_read_req->para + nvram_read_req->rec_amount -1 > ldi->total_records)
                {
                    nvram_read_req->rec_amount = ldi->total_records - nvram_read_req->para + 1;
                }

                if (nvram_read_req->rec_amount * (ldi->size + NVRAM_CHKSUM_SIZE) > MAX_NVRAM_RECORD_SIZE)
                {
                    nvram_read_req->rec_amount = MAX_NVRAM_RECORD_SIZE / (ldi->size + NVRAM_CHKSUM_SIZE + 1);
                }
            }

            if ((pdu_length = (ldi->size * nvram_read_req->rec_amount)) & 1)
            {
                pdu_length += 1;
            }

            peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);

            ASSERT(peer_buf_ptr != NULL);

            pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);

            ASSERT(pdu_ptr != NULL);

        #if defined(__SHADOW_SUPPORT_SB__)
            if ((ldi->category & NVRAM_CATEGORY_SHADOW) && (NORMAL_BOOT == stack_query_boot_mode()))
            {
                shadow_ltable_struct *shadow_entry = &shadow_ltable[ldi->record_ID];

                kal_mem_cpy(
                    pdu_ptr,
                    shadow_entry->offset + ((nvram_read_req->para - 1) * ldi->size),
                    (nvram_read_req->rec_amount * ldi->size));

                nvram_read_confirm(
                    ilm_ptr->src_mod_id,
                    NVRAM_ERRNO_SUCCESS,
                    nvram_read_req,
                    ldi->size * nvram_read_req->rec_amount,
                    peer_buf_ptr);

                nvram_flush_shadow();
            }
            else
        #elif defined(__SHADOW_SUPPORT_MS__)
            if (USBMS_BOOT == stack_query_boot_mode())
            {
                shadow_ltable_struct *shadow_entry = &shadow_ltable[ldi->record_ID];

                if (ldi->category & NVRAM_CATEGORY_SHADOW_MS)
                {
                    kal_mem_cpy(
                        pdu_ptr,
                        shadow_entry->offset + ((nvram_read_req->para - 1) * ldi->size),
                        (nvram_read_req->rec_amount * ldi->size));
                }
                else
                {
                    /* handle by nvram_io layer */
                    nvram_read_data_item(ldi, nvram_read_req->para, nvram_read_req->rec_amount, pdu_ptr, pdu_length);   /* nvram_read_data_item */
                }

                nvram_read_confirm(
                    ilm_ptr->src_mod_id,
                    NVRAM_ERRNO_SUCCESS,
                    nvram_read_req,
                    ldi->size * nvram_read_req->rec_amount,
                    peer_buf_ptr);

            }
            else
        #endif 
            {
                nvram_read_confirm(
                    ilm_ptr->src_mod_id,
                    nvram_read_data_item(ldi, nvram_read_req->para, nvram_read_req->rec_amount, pdu_ptr, pdu_length),       /* nvram_read_data_item */
                    nvram_read_req,
                    (kal_uint16) (ldi->size * nvram_read_req->rec_amount),
                    peer_buf_ptr);  /* nvram_read_confirm */
            }
        }
    }
    else    /* State error */
    {
        kal_trace(TRACE_ERROR, ERROR_NVRAM_STATE);

        nvram_read_confirm(
            ilm_ptr->src_mod_id,
            NVRAM_ERRNO_FAIL,
            nvram_read_req,
            (kal_uint16) NVRAM_INVALID_VALUE,
            NULL);
    }
}   /* end of nvram_read_handler */


/*****************************************************************************
 * FUNCTION
 *  nvram_read_confirm
 * DESCRIPTION
 *  This is nvram_read_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id             [IN]        
 *  result              [IN]        
 *  nvram_read_req      [?]         
 *  size                [IN]        
 *  peer_buf_ptr        [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
/** Could not be static because the nvram should send a read_confirm
 *  Message to L1 at nvram init, that will call this function
 */
void nvram_read_confirm
    (module_type dest_id,
     nvram_errno_enum result, nvram_read_req_struct *nvram_read_req, kal_uint16 size, peer_buff_struct *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *nvram_read_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((peer_buf_ptr != NULL) && (peer_buf_ptr->pdu_len != 0))
    {
        kal_uint8 *ptr = (kal_uint8*) peer_buf_ptr;

        kal_trace(
            TRACE_FUNC,
            FUNC_NVRAM_READ_CNF,
            result,
            nvram_read_req->file_idx,
            nvram_read_req->para,
            ptr[6],
            ptr[6 + peer_buf_ptr->pdu_len - 1]);
    }
    else
    {
        kal_trace(TRACE_FUNC, FUNC_NVRAM_READ_CNF, result, nvram_read_req->file_idx, nvram_read_req->para, 0xFF, 0xFF);
    }

    nvram_read_cnf = (nvram_read_cnf_struct*) construct_local_para(sizeof(nvram_read_cnf_struct), TD_CTRL);
    ASSERT(nvram_read_cnf != NULL);

    nvram_read_cnf->result = result;
    nvram_read_cnf->file_idx = nvram_read_req->file_idx;
    nvram_read_cnf->para = nvram_read_req->para;
    nvram_read_cnf->length = size;
    nvram_read_cnf->access_id = nvram_read_req->access_id;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_READ_CNF, nvram_read_cnf, peer_buf_ptr);

    return;
}   /* end of nvram_read_confirm */

