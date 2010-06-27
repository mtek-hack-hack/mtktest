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
 * nvram_handler_reset.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is reset handler function of NVRAM module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
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
#include "nvram_handler_reset.h"
#include "nvram_user_defs.h"

/* For FAT */
#include "fs_type.h"
#include "fat_fs.h"
#include "fs_func.h"/*__SECURITY_OTP__*/

static void nvram_reset_confirm(module_type dest_id, nvram_errno_enum result, nvram_reset_req_struct *nvram_reset_req);

static void nvram_set_lock_confirm(
                module_type dest_id,
                nvram_errno_enum result,
                nvram_set_lock_req_struct *nvram_set_lock_req);

extern kal_bool nvram_read_system_record(kal_uint8 *buffer, kal_uint16 size);

extern void nvram_set_lock_state(kal_uint8 *coded_version);


/*****************************************************************************
 * FUNCTION
 *  nvram_reset_handler
 * DESCRIPTION
 *  This is nvram_reset_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_reset_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;
    nvram_reset_req_struct *nvram_reset_req = (nvram_reset_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_NVRAM_RESET);

    ASSERT(nvram_reset_req != NULL);
    if (nvram_ptr->dev_broken)
    {
        nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_reset_req);
    }
    else
    {

        if (nvram_ptr->state == NVRAM_STATE_READY)
        {
        #ifdef __SHADOW_NVRAM__
            if (NORMAL_BOOT == stack_query_boot_mode())
            {
                if (!(nvram_reset_req->reset_category == NVRAM_RESET_CERTAIN) &&
                    !(nvram_reset_req->reset_category == NVRAM_RESET_FACTORY) &&
                    !(nvram_reset_req->reset_category == NVRAM_RESET_SHADOW))
                {
                    ASSERT(0);
                }
            }
        #endif /* __SHADOW_NVRAM__ */ 

/* __GEMINI__ */

            if (!(nvram_reset_req->reset_category & NVRAM_RESET_CERTAIN) &&
                !(nvram_reset_req->reset_category & NVRAM_RESET_DIFFERENCE))
            {
                nvram_reset_req->LID = 0;
            }

            nvram_get_data_item(ldi, nvram_reset_req->LID);

/* __GEMINI__ */
            if (nvram_reset_req->reset_category == NVRAM_RESET_CERTAIN)
            {
                if (!NVRAM_IS_LID_VALID(nvram_reset_req->LID))
                {
                    nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_LID, nvram_reset_req);
                }
                
                if (nvram_reset_req->rec_index < 1 ||
                    nvram_reset_req->rec_index > ldi->total_records ||
                    nvram_reset_req->rec_amount < 1 || 
                    (nvram_reset_req->rec_index + nvram_reset_req->rec_amount) > ldi->total_records)
                {
                    nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_RECORD, nvram_reset_req);                    
                }
            }

            if (nvram_reset_data_items(nvram_reset_req->reset_category, ldi, nvram_reset_req->rec_index, nvram_reset_req->rec_amount) == KAL_TRUE)
/* __GEMINI__ */                
            {
                nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_reset_req);
            }
            else
            {
                nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_FAIL, nvram_reset_req);
            }
        }
        /* State error */
        else
        {
            kal_trace(TRACE_FUNC, ERROR_NVRAM_STATE);

            nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_FAIL, nvram_reset_req);
        }
    }
}   /* end of nvram_reset_handler */


/*****************************************************************************
 * FUNCTION
 *  nvram_reset_confirm
 * DESCRIPTION
 *  This is nvram_reset_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id             [IN]        
 *  result              [IN]        
 *  nvram_reset_req     [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_reset_confirm(module_type dest_id, nvram_errno_enum result, nvram_reset_req_struct *nvram_reset_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_reset_cnf_struct *nvram_reset_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_NVRAM_RESET_CNF, result);

    nvram_reset_cnf = (nvram_reset_cnf_struct*) construct_local_para(sizeof(nvram_reset_cnf_struct), TD_CTRL);

    ASSERT(nvram_reset_cnf != NULL);

    nvram_reset_cnf->result = result;
    nvram_reset_cnf->access_id = nvram_reset_req->access_id;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_RESET_CNF, nvram_reset_cnf, NULL);

    return;
}   /* end of nvram_reset_confirm */


/*****************************************************************************
 * FUNCTION
 *  nvram_set_lock_handler
 * DESCRIPTION
 *  This is nvram_set_lock_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_set_lock_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool lock_state = nvram_ptr->lock;
    nvram_errno_enum result = NVRAM_ERRNO_FAIL;
    kal_uint8 sys_record[NVRAM_EF_SYS_SIZE];
    nvram_set_lock_req_struct *nvram_set_lock_req = (nvram_set_lock_req_struct*) ilm_ptr->local_para_ptr;
    ltable_entry_struct *ldi;
    NVRAM_FILE_NAME nvramname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nvram_ptr->dev_broken)
    {
        nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_INVALID, nvram_set_lock_req);
    }
    else
    {
        nvram_get_data_item(ldi, NVRAM_EF_SYS_LID);

        if ((nvram_set_lock_req->lock_en == NVRAM_LOCK_ENABLE && lock_state == KAL_TRUE) ||
            (nvram_set_lock_req->lock_en == NVRAM_LOCK_DISABLE && lock_state == KAL_FALSE))
        {
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_set_lock_req);
            return;
        }
        else if (nvram_set_lock_req->lock_en == NVRAM_LOCK_TEMP_DISABLE)
        {
            nvram_ptr->lock = KAL_FALSE;
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_set_lock_req);
            return;
        }
    #ifdef __SECURITY_OTP__
        else if (nvram_set_lock_req->lock_en == NVRAM_LOCK_OTP)
        {
            FS_OTPLock(FS_DEVICE_TYPE_NOR);
        }
    #endif /* __SECURITY_OTP__ */
        kal_mem_set(sys_record, 0, NVRAM_EF_SYS_SIZE);
        /* system record read error */
        if (nvram_read_system_record(sys_record, NVRAM_EF_SYS_SIZE) == KAL_FALSE)
        {
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_FAIL, nvram_set_lock_req);
            return;
        }

        if (nvram_set_lock_req->lock_en == NVRAM_LOCK_ENABLE)
        {
            kal_mem_cpy(sys_record + CODED_LOCK_PATTERN_OFFSET, NVRAM_LOCK_PATTERN_LOCKED, CODED_LOCK_PATTERN_SIZE);
        }
        else if (nvram_set_lock_req->lock_en == NVRAM_LOCK_DISABLE)
        {
            kal_mem_cpy(sys_record + CODED_LOCK_PATTERN_OFFSET, NVRAM_LOCK_PATTERN_UNLOCKED, CODED_LOCK_PATTERN_SIZE);
        }
        else
        {
            /* Invalid parameter */
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_INVALID, nvram_set_lock_req);
            return;
        }

        custom_nvram_encrypt(
            nvram_ptr->secret_key,
            sys_record + CODED_LOCK_PATTERN_OFFSET,
            CODED_LOCK_PATTERN_SIZE,
            (nvram_ptr->coded_version[9] - '0') * 10 + (nvram_ptr->coded_version[10] - '0'));

        /* The software lock must be unlocked temporarily to change system record lock state. */
        nvram_ptr->lock = KAL_FALSE;

        NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, 'a', ldi->fileverno);

        if (nvram_drv_fat_write((kal_uint8*) sys_record, nvramname, 1, NVRAM_EF_SYS_SIZE, ldi->attr & NVRAM_ATTR_MSP, KAL_FALSE) == NVRAM_DRV_OK)
        {
            result = NVRAM_ERRNO_SUCCESS;
        }

        NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, 'b', ldi->fileverno);

        if (nvram_drv_fat_write((kal_uint8*) sys_record, nvramname, 1, NVRAM_EF_SYS_SIZE, ldi->attr&NVRAM_ATTR_MSP, KAL_FALSE) == NVRAM_DRV_OK)
        {
            result = NVRAM_ERRNO_SUCCESS;
        }

        /* Restore lock state */
        nvram_ptr->lock = lock_state;

        nvram_set_lock_state((kal_uint8*) sys_record);
        nvram_set_lock_confirm(ilm_ptr->src_mod_id, result, nvram_set_lock_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  nvram_set_lock_confirm
 * DESCRIPTION
 *  This is nvram_set_lock_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id                 [IN]        
 *  result                  [IN]        
 *  nvram_set_lock_req      [?]         
 *  ilm_ptr(?)              [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_set_lock_confirm(
                module_type dest_id,
                nvram_errno_enum result,
                nvram_set_lock_req_struct *nvram_set_lock_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_set_lock_cnf_struct *nvram_set_lock_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_set_lock_cnf = (nvram_set_lock_cnf_struct*) construct_local_para(sizeof(nvram_set_lock_cnf_struct), TD_CTRL);

    nvram_set_lock_cnf->result = result;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_SET_LOCK_CNF, nvram_set_lock_cnf, NULL);

    return;

}

