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
 * nvram_handler_tst.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is tst handler function of NVRAM module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"        /* Basic data type */

#include <stdio.h>

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
#include "nvram_user_defs.h"

#include "nvram_interface.h"
#include "nvram_handler_read.h"
#include "nvram_handler_tst.h"

#include "tst_sap.h"

/* Exception */
#include "ex_item.h"

/* Statistics */
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "tst_buff_pool.h"
#include "sysconf_statistics.h"

#include "stack_types.h"
#include "task_config.h"
extern task_info_struct *task_info_g;
extern kal_internal_hisrid kal_hisr_ptrs_g[KAL_MAX_NUM_HISRS];
extern kal_bool nvram_read_system_record(kal_uint8 *buffer, kal_uint16 size);

/* #define __VM_TEST__ */

#undef  _FILE_CODE_
#define _FILE_CODE_ _NVRAM_TST_C_

/* extern kal_uint8 vm_case; */
extern kal_uint32 KALTotalTasks;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__HW_CHE__) */ 


/*****************************************************************************
 * FUNCTION
 *  nvram_tst_handler
 * DESCRIPTION
 *  This is nvram_tst_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_tst_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_NVRAM_TST);

    ASSERT(tst_inject != NULL);

    if (!nvram_ptr->dev_broken && nvram_ptr->state == NVRAM_STATE_READY)
    {
    #if NVRAM_COMMENT
        if (strcmp((kal_char*) tst_inject->string, "test_buffer") == 0)
        {
            if (tst_inject->index == 1) /* get */
            {
                kal_uint16 size = 0;
                kal_uint8 *buffer = NULL;
                
                nvram_get_shadow_buffer(NVRAM_EF_FM_RECORD_LID, &size, &buffer);
                kal_mem_set(buffer, 0xAA ,size);
            }
            else if (tst_inject->index == 0) /* free */
            {
                nvram_free_shadow_buffer(NVRAM_EF_FM_RECORD_LID);
            }
        }
        else 
    #endif
    #ifdef __SECURITY_OTP__
        if (strcmp((kal_char*) tst_inject->string, "otp_start")==0)
        {
            extern kal_uint32 nvram_otp_size;
            extern void nvram_otp_construct(void);
            nvram_otp_size = tst_inject->index * 10;
            nvram_otp_construct();
        }
        else
    #endif /* __SECURITY_OTP__ */
        if (strcmp((kal_char*) tst_inject->string, "ex_reset") == 0)
        {
            ltable_entry_struct *ldi;

            nvram_get_data_item(ldi, NVRAM_EF_SYS_EXCEPTION_LID);

/* __GEMINI__ */
            if (nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records) == KAL_TRUE)
/* __GEMINI__ */
            {
                /* Do Something... */
                kal_print("Nvram: Exception record clear complete!\n");
            }
            else
            {
                /* Do Something... */
                kal_print("Nvram: Error to clear Exception record!\n");
            }
        }
        else if (strcmp((kal_char*) tst_inject->string, "ex_fetch") == 0)
        {
            kal_uint8 i;
            ltable_entry_struct *ldi;
            peer_buff_struct *peer_buf_ptr;
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;
            nvram_read_req_struct *local_data;
            nvram_errno_enum ret;
            kal_char msg_dump_buf[64];

            nvram_get_data_item(ldi, NVRAM_EF_SYS_EXCEPTION_LID);

            if ((kal_uint8*) tst_inject->index == 0)
            {
                /* Get ALL Exception Records */
                for (i = 1; i <= NVRAM_EF_SYS_EXCEPTION_TOTAL; i++)
                {
                    local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
                    local_data->access_id = 0;
                    local_data->file_idx = (NVRAM_EF_SYS_EXCEPTION_LID);
                    local_data->para = i;

                    pdu_length = ldi->size;
                    peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                    pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);

                    ret = nvram_read_data_item(ldi, i, 1, pdu_ptr, pdu_length); /* multi-rec read support */

                    if (((EX_LOG_T*) pdu_ptr)->header.ex_nvram == 0xFF)
                    {
                        sprintf(msg_dump_buf, "Nvram: Total %d Exceptions Vaild!", (i - 1));
                        kal_print(msg_dump_buf);
                        free_peer_buff(peer_buf_ptr);
                        free_local_para((struct local_para_struct*)local_data);

                        break;
                    }

                    nvram_read_confirm(MOD_NVRAM, ret, local_data, ldi->size, peer_buf_ptr);

                }

            }
            else if ((kal_uint8) tst_inject->index <= NVRAM_EF_SYS_EXCEPTION_TOTAL)
            {
                /* Get Certain Exception Records */
                local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
                local_data->access_id = 0;
                local_data->file_idx = (NVRAM_EF_SYS_EXCEPTION_LID);
                local_data->para = (kal_uint8) tst_inject->index;

                pdu_length = ldi->size;
                peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);

                ret = nvram_read_data_item(ldi, (kal_uint8) tst_inject->index, 1, pdu_ptr, pdu_length); /* multi-rec read support */
                if (((EX_LOG_T*) pdu_ptr)->header.ex_nvram == 0xFF)
                {
                    sprintf(msg_dump_buf, "Nvram: Exception #%d is Invaild!", (kal_uint8) tst_inject->index);
                    kal_print(msg_dump_buf);
                    free_peer_buff(peer_buf_ptr);
                    free_local_para((struct local_para_struct*)local_data);
                }
                else
                {

                    nvram_read_confirm(MOD_NVRAM, ret, local_data, ldi->size, peer_buf_ptr);
                }

            }
            else
            {
                /* Out of Range */
                kal_print("NVRAM: Get Exception record number out of range!");
            }
        }
        else if (strcmp((kal_char*) tst_inject->string, "stat_checked") == 0)
        {
            ltable_entry_struct *ldi;
            stack_statistics_struct *stat_ptr;
            nvram_errno_enum ret;

            /* Dynamically allocates buffer, otherwise stack could overflow. */
            stat_ptr = (stack_statistics_struct*) get_ctrl_buffer(NVRAM_EF_SYS_STATISTICS_SIZE);

            nvram_get_data_item(ldi, NVRAM_EF_SYS_STATISTICS_LID);

            /* Read statistaics data item */
            ret = nvram_read_data_item(ldi, 1, 1, (kal_uint8*) stat_ptr, NVRAM_EF_SYS_STATISTICS_SIZE);        /* multi-rec read support */
            if ((ret == NVRAM_IO_ERRNO_OK) || (ret == NVRAM_IO_ERRNO_INIT))
            {
                stat_ptr->stack_stats_status = STACK_STATS_NONE;
                nvram_write_data_item(ldi, 1, (kal_uint8*) stat_ptr, KAL_FALSE);
            }

            free_ctrl_buffer(stat_ptr);
        }
        else if (strcmp((kal_char*) tst_inject->string, "stat_reset") == 0)
        {
            ltable_entry_struct *ldi;

            nvram_get_data_item(ldi, NVRAM_EF_SYS_EXCEPTION_LID);

/* __GEMINI__ */
            if (nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records) == KAL_TRUE)
/* __GEMINI__ */                
            {
                kal_print("Nvram: Reset statistics succeded!\n");
            }
            else
            {
                kal_print("Nvram: Reset statistics failed!\n");
            }
        }
        else if (strcmp((kal_char*) tst_inject->string, "stat_fetch") == 0)
        {
            nvram_errno_enum ret;
            ltable_entry_struct *ldi;
            peer_buff_struct *peer_buf_ptr;
            kal_uint8 *pdu_ptr;
            kal_uint16 pdu_length;
            nvram_read_req_struct *local_data;
            stack_statistics_struct *stat_ptr;
            kal_char *msg_dump_buf;
            kal_uint8 i;

            nvram_get_data_item(ldi, NVRAM_EF_SYS_STATISTICS_LID);

            local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
            local_data->access_id = 0;
            local_data->file_idx = (NVRAM_EF_SYS_STATISTICS_LID);
            local_data->para = 1;

            pdu_length = ldi->size;
            peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
            pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);

            /* read statistics information from nvram */
            ret = nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length); /* multi-rec read support */
            /* Send read confirm primitive to nvram itself for catcher display raw data */
            nvram_read_confirm(MOD_NVRAM, ret, local_data, ldi->size, peer_buf_ptr);

            /* Show detail to catcher sys trace window */
            if (ret == NVRAM_IO_ERRNO_OK || ret == NVRAM_IO_ERRNO_INIT)
            {
                msg_dump_buf = (kal_char*) get_ctrl_buffer(128 * sizeof(kal_char));
                stat_ptr = get_ctrl_buffer(ldi->size);

                if (!msg_dump_buf || !stat_ptr)
                {
                    kal_print("Could not allocat ctrl buffer! Show statistics info detail abort!\n");
                    return;
                }
                /* stat_ptr = (stack_statistics_struct *)pdu_ptr; */
                kal_mem_cpy(stat_ptr, pdu_ptr, ldi->size);

                sprintf(msg_dump_buf, "[sysinfo] status = %u\n", stat_ptr->stack_stats_status);
                kal_print(msg_dump_buf);

                sprintf(msg_dump_buf, "[sysinfo] Max SysMem used = %u\n", stat_ptr->max_sys_mem_used);
                kal_print(msg_dump_buf);

                sprintf(msg_dump_buf, "[sysinfo] Max SysDbgMem used = %u\n", stat_ptr->max_sysdebug_mem_used);
                kal_print(msg_dump_buf);

                kal_print("[sysinfo] Max task stack used:\n");
                for (i = 0; i < KALTotalTasks; i += 5)
                {
                    sprintf(
                        msg_dump_buf,
                        "%2d: [%7s %4d][%7s %4d][%7s %4d][%7s %4d][%7s %4d]\n",
                        i,
                        ((i > KALTotalTasks ? NULL : task_info_g[i].task_id) == NULL ? "--" : task_info_g[i].task_name_ptr),
                        stat_ptr->max_task_stack_used[i],
                        ((i + 1 > KALTotalTasks ? NULL : task_info_g[i + 1].task_id) == NULL ? "--" : task_info_g[i + 1].task_name_ptr),
                        (i + 1 >= KALTotalTasks) ? 0 : stat_ptr->max_task_stack_used[(i + 1)],
                        ((i + 2 > KALTotalTasks ? NULL : task_info_g[i + 2].task_id) == NULL ? "--" : task_info_g[i + 2].task_name_ptr),
                        (i + 2 >= KALTotalTasks) ? 0 : stat_ptr->max_task_stack_used[(i + 2)],
                        ((i + 3 > KALTotalTasks ? NULL : task_info_g[i + 3].task_id) == NULL ? "--" : task_info_g[i + 3].task_name_ptr),
                        (i + 3 >= KALTotalTasks) ? 0 : stat_ptr->max_task_stack_used[(i + 3)],
                        ((i + 4 > KALTotalTasks ? NULL : task_info_g[i + 4].task_id) == NULL ? "--" : task_info_g[i + 4].task_name_ptr),
                        (i + 4 >= KALTotalTasks) ? 0 : stat_ptr->max_task_stack_used[(i + 4)]);
                    kal_print(msg_dump_buf);
                }
                /* Cylen modified, for changing HISR structure, 2004/9/3 */
            #ifdef DEBUG_KAL
                kal_print("[sysinfo] Max hisr stack used:\n");
                for (i = 0; i < KAL_MAX_NUM_HISRS; i += 5)
                {
                    sprintf(
                        msg_dump_buf,
                        "%2d: [%7s %4d][%7s %4d][%7s %4d][%7s %4d][%7s %4d]\n",
                        i,
                        kal_hisr_ptrs_g[i] == NULL ? "--" : kal_hisr_ptrs_g[i]->hisr_name,
                        stat_ptr->max_hisr_stack_used[i],
                        kal_hisr_ptrs_g[i + 1] == NULL ? "--" : kal_hisr_ptrs_g[i + 1]->hisr_name,
                        (i + 1) >= KAL_MAX_NUM_HISRS ? 0 : stat_ptr->max_hisr_stack_used[(i + 1)],
                        kal_hisr_ptrs_g[i + 2] == NULL ? "--" : kal_hisr_ptrs_g[i + 2]->hisr_name,
                        (i + 2) >= KAL_MAX_NUM_HISRS ? 0 : stat_ptr->max_hisr_stack_used[(i + 2)],
                        kal_hisr_ptrs_g[i + 3] == NULL ? "--" : kal_hisr_ptrs_g[i + 3]->hisr_name,
                        (i + 3) >= KAL_MAX_NUM_HISRS ? 0 : stat_ptr->max_hisr_stack_used[(i + 3)],
                        kal_hisr_ptrs_g[i + 4] == NULL ? "--" : kal_hisr_ptrs_g[i + 4]->hisr_name,
                        (i + 4) >= KAL_MAX_NUM_HISRS ? 0 : stat_ptr->max_hisr_stack_used[(i + 4)]);
                    kal_print(msg_dump_buf);
                }
            #endif /* DEBUG_KAL */ 
                /* Cylen end */

            #ifdef DEBUG_ITC
                kal_print("[sysinfo] Max task extq enqued:\n");
                for (i = 0; i < KALTotalTasks; i += 5)
                {
                    sprintf(
                        msg_dump_buf,
                        "%2d: [%7s %4d][%7s %4d][%7s %4d][%7s %4d][%7s %4d]\n",
                        i,
                        ((i > KALTotalTasks ? NULL : task_info_g[i].task_ext_qid) == NULL ? "--" : task_info_g[i].task_qname_ptr),
                        stat_ptr->max_task_extq_enqued[i],
                        ((i + 1 > KALTotalTasks ? NULL : task_info_g[i + 1].task_ext_qid) == NULL ? "--" : task_info_g[i + 1].task_qname_ptr),
                        (i + 1 >= KALTotalTasks) ? 0 : stat_ptr->max_task_extq_enqued[(i + 1)],
                        ((i + 2 > KALTotalTasks ? NULL : task_info_g[i + 2].task_ext_qid) == NULL ? "--" : task_info_g[i + 2].task_qname_ptr),
                        (i + 2 >= KALTotalTasks) ? 0 : stat_ptr->max_task_extq_enqued[(i + 2)],
                        ((i + 3 > KALTotalTasks ? NULL : task_info_g[i + 3].task_ext_qid) == NULL ? "--" : task_info_g[i + 3].task_qname_ptr),
                        (i + 3 >= KALTotalTasks) ? 0 : stat_ptr->max_task_extq_enqued[(i + 3)],
                        ((i + 4 > KALTotalTasks ? NULL : task_info_g[i + 4].task_ext_qid) == NULL ? "--" : task_info_g[i + 4].task_qname_ptr),
                        (i + 4 >= KALTotalTasks) ? 0 : stat_ptr->max_task_extq_enqued[(i + 4)]);

                    kal_print(msg_dump_buf);
                }
            #endif /* DEBUG_ITC */ 

            #ifdef DEBUG_BUF2
                kal_print("[sysinfo] Max ctrl buff num allocated:\n");
                kal_print("(8/16/32/64/128) / (256/512/1024/2048/4096) / (8192/16384/32768/65536)\n");
                for (i = 0; i < RPS_CREATED_CTRL_BUFF_POOLS; i += 5)
                {
                    sprintf(
                        msg_dump_buf,
                        "%2d: [%4d][%4d][%4d][%4d][%4d]\n",
                        i,
                        stat_ptr->max_ctrl_buff_num_allocated[i],
                        (i + 1) >= RPS_CREATED_CTRL_BUFF_POOLS ? 0 : stat_ptr->max_ctrl_buff_num_allocated[(i + 1)],
                        (i + 2) >= RPS_CREATED_CTRL_BUFF_POOLS ? 0 : stat_ptr->max_ctrl_buff_num_allocated[(i + 2)],
                        (i + 3) >= RPS_CREATED_CTRL_BUFF_POOLS ? 0 : stat_ptr->max_ctrl_buff_num_allocated[(i + 3)],
                        (i + 4) >= RPS_CREATED_CTRL_BUFF_POOLS ? 0 : stat_ptr->max_ctrl_buff_num_allocated[(i + 4)]);

                    kal_print(msg_dump_buf);
                }

                kal_print("[sysinfo] Max tst buff num allocated:\n");
                for (i = 0; i < RPS_CREATED_CTRL_BUFF_POOLS; i += 5)
                {
                    sprintf(
                        msg_dump_buf,
                        "%2d: [%4d][%4d][%4d][%4d][%4d]\n",
                        i,
                        stat_ptr->max_tst_buff_num_allocated[i],
                        (i + 1) >= RPS_CREATED_TST_BUFF_POOLS ? 0 : stat_ptr->max_tst_buff_num_allocated[(i + 1)],
                        (i + 2) >= RPS_CREATED_TST_BUFF_POOLS ? 0 : stat_ptr->max_tst_buff_num_allocated[(i + 2)],
                        (i + 3) >= RPS_CREATED_TST_BUFF_POOLS ? 0 : stat_ptr->max_tst_buff_num_allocated[(i + 3)],
                        (i + 4) >= RPS_CREATED_TST_BUFF_POOLS ? 0 : stat_ptr->max_tst_buff_num_allocated[(i + 4)]);
                    kal_print(msg_dump_buf);
                }
            #endif /* DEBUG_BUF2 */ 

                free_ctrl_buffer(msg_dump_buf);
                free_ctrl_buffer(stat_ptr);

            }
            else
            {
                kal_print("nvram_handler_tst: Get statistic information form nvram error!\n");
            }

        }
        else if (strcmp((kal_char*) tst_inject->string, "reset_all") == 0)
        {
            ltable_entry_struct *ldi;

            nvram_get_data_item(ldi, 0);

/* __GEMINI__ */            
            if (nvram_reset_data_items(NVRAM_RESET_ALL, ldi, 1, ldi->total_records) != KAL_TRUE)
/* __GEMINI__ */                
            {
                kal_print("Nvram: Reset all data item failed!\n");
            }
            else
            {
                kal_print("Nvram: All data item has been reset!\n");
            }

        }
        else if (strcmp((kal_char*) tst_inject->string, "reset_certain") == 0)
        {
            ltable_entry_struct *ldi;

            nvram_get_data_item(ldi, tst_inject->index);

/* __GEMINI__ */
            if (nvram_reset_data_items(NVRAM_RESET_CERTAIN, ldi, 1, ldi->total_records) != KAL_TRUE)
/* __GEMINI__ */                
            {
                kal_print("Nvram: Reset data item failed!\n");
            }
            else
            {
                kal_print("Nvram: Data item has been reset!\n");
            }

        }

        /* Belows are for internal debug testing only. >=) */
        else
        {
            /* Create a exception record manually by issuing a command from Catcher. */
            if (strcmp((kal_char*) tst_inject->string, "ex_create") == 0)
            {
                long *ex_data;

                /* Dynamically allocates buffer, otherwise stack could overflow. */
                ex_data = (long*)get_ctrl_buffer(NVRAM_EF_SYS_EXCEPTION_SIZE);

                kal_mem_set((kal_uint8*) ex_data, 0x5, NVRAM_EF_SYS_EXCEPTION_SIZE);
                nvram_write_exception(NVRAM_EF_SYS_EXCEPTION_SIZE, ex_data);

                free_ctrl_buffer(ex_data);
            }

            /* Update statistics manually by issuing a command from Catcher. */
            else if (strcmp((kal_char*) tst_inject->string, "stat_create") == 0)
            {
                ltable_entry_struct *ldi;
                stack_statistics_struct *stat_ptr;

                /* Dynamically allocates buffer, otherwise stack could overflow. */
                stat_ptr = (stack_statistics_struct*) get_ctrl_buffer(NVRAM_EF_SYS_STATISTICS_SIZE);
                kal_mem_set((kal_uint8*) stat_ptr, 0, NVRAM_EF_SYS_STATISTICS_SIZE);
                stat_ptr->stack_stats_status = STACK_STATS_UPDATE;

                nvram_get_data_item(ldi, NVRAM_EF_SYS_STATISTICS_LID);

                nvram_write_data_item(ldi, 1, (kal_uint8*) stat_ptr, KAL_FALSE);

                free_ctrl_buffer(stat_ptr);
            }

            /* Test On Demand >>==)) */
            else if (strcmp((kal_char*) tst_inject->string, "nvram_read") == 0)
            {
                nvram_read_req_struct *local_data;

                local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);
                local_data->access_id = 0;
                local_data->file_idx = (kal_uint8) tst_inject->index;
                local_data->para = 1;
                nvram_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, local_data, NULL);

            }
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __HW_CHE__ */ 
            else if (strcmp((kal_char*) tst_inject->string, "sw_lock") == 0)
            {
                nvram_set_lock_req_struct *local_data;

                local_data =
                    (nvram_set_lock_req_struct*) construct_local_para(sizeof(nvram_set_lock_req_struct), TD_CTRL);

                if ((kal_uint8) tst_inject->index == 1)
                {
                    /* Lock */
                    local_data->lock_en = NVRAM_LOCK_ENABLE;
                    nvram_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_SET_LOCK_REQ, local_data, NULL);
                }
                else if ((kal_uint8) tst_inject->index == 0)
                {
                    /* UnLock */
                    local_data->lock_en = NVRAM_LOCK_DISABLE;
                    nvram_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_SET_LOCK_REQ, local_data, NULL);
                }
                else if ((kal_uint8) tst_inject->index == 2)
                {
                    kal_uint8 second_buffer[NVRAM_EF_SYS_SIZE];

                    nvram_read_system_record(second_buffer, NVRAM_EF_SYS_SIZE);
                }

            }
            /* Error commands */
            else
            {
                kal_trace(TRACE_ERROR, ERROR_NVRAM_TST_INVALID_COMM);
            }
        }
    }
    /* State error */
    else
    {
        kal_trace(TRACE_STATE, STATE_NVRAM_NOT_READY);
    }

}   /* end of nvram_tst_handler */

