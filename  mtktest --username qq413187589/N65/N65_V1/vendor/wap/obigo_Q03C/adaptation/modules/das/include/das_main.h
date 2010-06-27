/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   das_main.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines definitions of download service module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/

#ifndef _das_main_h
#define _das_main_h

typedef enum
{
    DAS_STATUS_IDLE,
    DAS_STATUS_DOWNLOADING,
    DAS_STATUS_ABORTED,
    DAS_STATUS_WAITING,
    DAS_STATUS_COMPLETE,
    DAS_STATUS_PREFETCHING
} das_status_enum;

typedef enum
{
    DAS_ERR_SUCCESS,
    DAS_ERR_CREATE_FILE_FAILED,
    DAS_ERR_SAVE_FULL,
    DAS_ERR_SAVE_SIZE,
    DAS_ERR_DOWNLOAD_FAILED,
    DAS_ERR_CONNECTION_ABORT,
    DAS_ERR_USER_CANCELLED
} das_error_enum;

#define DAS_ALLOC(x)      MSF_MEM_ALLOC (MSF_MODID_DAS, x)
#define DAS_ALLOCTYPE(x)  MSF_MEM_ALLOCTYPE (MSF_MODID_DAS, x)
#define DAS_FREE(x)       MSF_MEM_FREE (MSF_MODID_DAS, x)

#define DAS_DL_BUFFER_SIZE 2048

typedef struct das_job_st
{
    struct das_job_st *next;
    MSF_INT32 id;
    MSF_INT32 cause;
    MSF_UINT8 status;
    char *mime_type;
    char *url;
    char *header;
    char *pipe_name;
    char *file_name;
    MSF_UINT32 download_size;
    MSF_UINT32 total_size;
    int pipe_handle;
    int file_handle;
    int indication_sent;
    char buffer[DAS_DL_BUFFER_SIZE];
    MSF_UINT32 buffer_tail;
    MSF_UINT32 seq_num;
} das_job_t;

extern jmp_buf das_jmpbuf;
extern int das_insideRun;
extern int das_wantsToRun;

extern void das_init(void);
extern void das_terminate(void);
extern void das_process(void);


extern das_job_t *das_find_job_by_session_id(int session_id);
extern int das_execute_commands(MSF_UINT8 mod_src, msf_module_execute_cmd_t *p);
extern int das_handle_pipe_notify(int handle, int event_type);
extern void das_abort_download(das_job_t * job, int cause);
extern void das_delete_job(das_job_t * job);
extern int das_read_pipe_data(das_job_t * job);
#endif
