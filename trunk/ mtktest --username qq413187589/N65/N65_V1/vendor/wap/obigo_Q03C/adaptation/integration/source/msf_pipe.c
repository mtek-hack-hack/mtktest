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
 * msf_pipe.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating WAP Pipe APIs.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_mem.h"
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "app_buff_alloc.h"

#include "stdarg.h"
#include "stdio.h"

#include "msf_cfg.h"
#include "msm_int.h"
#include "msf_env.h"

#define PIPEDBG_(x)     /* empty */

extern void widget_pipeNotify(MSF_UINT8 modId, int handle, int eventType);

#define MAX_NAME_PIPE_NUM          (5 + 1)
#define MAX_NAME_PIPE_SIZE         (1024)     /* minus 12 is for fining tune to use only 512-size rather 1024-size */
#define HDI_PIPE_POOL(X)           (HDIa_pipe_cntx.pipe_pool[X])
#define HDI_FROM_WH_TO_RH(h)       ((h+1)*10)   /* write handle -> read handle */
#define HDI_FROM_RH_TO_WH(h)       (h/10-1)     /* read handle -> write handle */
#define HDI_RH_LOW                 (10)
#define HDI_RH_HIGH                (MAX_NAME_PIPE_NUM*10)

typedef struct
{
    /* stuff for named pipe */
    kal_char *name;
    kal_uint8 w_mod_id;     /* module id of writer */
    kal_uint8 r_mod_id;     /* module id of reader */
    kal_uint8 is_del_postponed;
    kal_uint8 is_w_open;    /* is writer side open */
    kal_int8 is_r_open;     /* is reader side open */
    kal_uint8 is_write_delay;
    kal_uint8 is_read_delay;

    /* stuff for circular queue */
    kal_uint8 queue[MAX_NAME_PIPE_SIZE];
    unsigned int head;
    unsigned int tail;
    kal_uint8 is_full;
    kal_uint8 is_closed_error;

} name_pipe_struct;

typedef struct
{
    name_pipe_struct *pipe_pool[MAX_NAME_PIPE_NUM];

} HDIa_pipe_cntx_struct;

HDIa_pipe_cntx_struct HDIa_pipe_cntx;


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_pipeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < MAX_NAME_PIPE_NUM; i++)
    {
        HDI_PIPE_POOL(i) = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  name_pipe_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p           [?]         
 *  buf         [?]         
 *  bufSize     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void name_pipe_write(name_pipe_struct *p, void *buf, long bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((p->tail + bufSize) <= MAX_NAME_PIPE_SIZE)
    {
        kal_mem_cpy(&p->queue[p->tail], (kal_uint8*) buf, bufSize);
    }
    else
    {
        long len = MAX_NAME_PIPE_SIZE - p->tail;

        kal_mem_cpy(&p->queue[p->tail], (kal_uint8*) buf, len);
        kal_mem_cpy(p->queue, (kal_uint8*) buf + len, bufSize - len);
    }

    p->tail = (p->tail + bufSize) % MAX_NAME_PIPE_SIZE;
    if (p->head == p->tail)
    {
        p->is_full = KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  name_pipe_occupied_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int name_pipe_occupied_bytes(name_pipe_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (p->is_full) ? MAX_NAME_PIPE_SIZE : ((p->tail + MAX_NAME_PIPE_SIZE - p->head) % MAX_NAME_PIPE_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  name_pipe_remaining_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int name_pipe_remaining_bytes(name_pipe_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MAX_NAME_PIPE_SIZE - name_pipe_occupied_bytes(p));
}


/*****************************************************************************
 * FUNCTION
 *  name_pipe_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p           [?]         
 *  buf         [?]         
 *  bufSize     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void name_pipe_read(name_pipe_struct *p, void *buf, long bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((p->head + bufSize) <= MAX_NAME_PIPE_SIZE)
    {
        kal_mem_cpy((kal_uint8*) buf, &p->queue[p->head], bufSize);
    }
    else
    {
        long len = MAX_NAME_PIPE_SIZE - p->head;

        kal_mem_cpy((kal_uint8*) buf, &p->queue[p->head], len);
        kal_mem_cpy((kal_uint8*) buf + len, p->queue, bufSize - len);
    }

    p->head = (p->head + bufSize) % MAX_NAME_PIPE_SIZE;
    p->is_full = KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  find_name_pipe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [IN]        
 *  indx        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool find_name_pipe(const char *name, kal_uint8 *indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check whether a pipe already exist with this name */
    for (i = 1; i < MAX_NAME_PIPE_NUM; i++)
    {
        if (HDI_PIPE_POOL(i) != NULL)
        {
            if (strcmp(name, HDI_PIPE_POOL(i)->name) == 0)
            {
                if (indx)
                {
                    *indx = i;
                }
                break;
            }
        }
    }

    if (i < MAX_NAME_PIPE_NUM)  /* this pipe already existed */
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  is_reader_handle_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool is_reader_handle_valid(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int wh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((handle < HDI_RH_LOW) || (handle > HDI_RH_HIGH) || ((handle % 10) != 0))
    {
        return KAL_FALSE;
    }

    wh = HDI_FROM_RH_TO_WH(handle);

    if ((HDI_PIPE_POOL(wh) == NULL) || (HDI_PIPE_POOL(wh)->is_r_open == KAL_FALSE))
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  is_writer_handle_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool is_writer_handle_valid(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((handle < 0) || (handle >= MAX_NAME_PIPE_NUM) ||
        (HDI_PIPE_POOL(handle) == NULL) || (HDI_PIPE_POOL(handle)->is_w_open == KAL_FALSE))
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

/**********************************************************************
 * HDI Pipe Funktions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfUid      [IN]        
 *  name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeCreate(MSF_UINT8 msfUid, const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    name_pipe_struct *pipe;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        return HDI_PIPE_ERROR_INVALID_PARAM;
    }

    PIPEDBG_(("pipeCreate: modid=%d, name=%s\n", msfUid, name));

    /* check whether a pipe already exist with this name */
    if (find_name_pipe(name, NULL) == KAL_TRUE)
    {
        return HDI_PIPE_ERROR_EXISTS;
    }

    for (i = 1; i < MAX_NAME_PIPE_NUM + 1; i++)
    {
        if (HDI_PIPE_POOL(i) == NULL)
        {
            break;
        }
    }

    if (i >= MAX_NAME_PIPE_NUM)
    {
        return HDI_PIPE_ERROR_RESOURCE_LIMIT;
    }

    HDI_PIPE_POOL(i) = (name_pipe_struct*) MSF_MEM_ALLOC(MSF_MODID_MSM, sizeof(name_pipe_struct));

    pipe = HDI_PIPE_POOL(i);

    /* initialize the pipe content */
    pipe->w_mod_id = msfUid;
    pipe->head = 0;
    pipe->tail = 0;
    pipe->is_full = KAL_FALSE;
    pipe->is_w_open = KAL_TRUE; /* writer create this pipe, implicitly open */
    pipe->is_r_open = -1;
    pipe->is_del_postponed = KAL_FALSE;
    pipe->is_write_delay = KAL_FALSE;
    pipe->is_read_delay = KAL_FALSE;
    pipe->is_closed_error = KAL_FALSE;

    pipe->name = (kal_char*) MSF_MEM_ALLOC(MSF_MODID_MSM, MAX_HDI_FILE_NAME_SIZE);
    strcpy(pipe->name, name);

    return i;
}   /* end of HDIa_pipeCreate */


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeOpen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msfUid      [IN]        
 *  name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeOpen(MSF_UINT8 msfUid, const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 indx;
    name_pipe_struct *pipe;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        return HDI_PIPE_ERROR_INVALID_PARAM;
    }

    PIPEDBG_(("pipeOpen: modid=%d, name=%s\n", msfUid, name));

    /* check whether a pipe already exist with this name */
    if (find_name_pipe(name, &indx) == KAL_FALSE)
    {
        return HDI_PIPE_ERROR_NOT_FOUND;
    }

    pipe = HDI_PIPE_POOL(indx);

    if (pipe->is_r_open == KAL_TRUE)
    {
        return HDI_PIPE_ERROR_IS_OPEN;
    }

    pipe->is_r_open = KAL_TRUE;
    pipe->r_mod_id = msfUid;

    return HDI_FROM_WH_TO_RH(indx);

}   /* end of HDIa_pipeOpen */


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeDelete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeDelete(const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 indx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        return HDI_PIPE_ERROR_NOT_FOUND;
    }

    /* check whether a pipe already exist with this name */
    if (find_name_pipe(name, &indx) == KAL_FALSE)
    {
        return HDI_PIPE_ERROR_NOT_FOUND;
    }

    PIPEDBG_(("pipeDelete: name=%s\n", name));
    
    if ((HDI_PIPE_POOL(indx)->is_w_open == KAL_TRUE) || (HDI_PIPE_POOL(indx)->is_r_open == KAL_TRUE))
    {
        PIPEDBG_(("pipeDelete: postponed\n"));
        
        HDI_PIPE_POOL(indx)->is_del_postponed = KAL_TRUE;

        /*
         * in some abnormal cases, reader doesn't open and 
         * * delete the pipe directly, we mark the reader closed
         * * so that when writer polls, we can notify writer that pipe is closed.
         */
        HDI_PIPE_POOL(indx)->is_r_open = KAL_FALSE;

        /* reader already deleted this pipe */
        if (HDI_PIPE_POOL(indx)->is_w_open == KAL_TRUE && HDI_PIPE_POOL(indx)->is_write_delay == KAL_TRUE)
        {
            /* notify writer */
            HDIc_pipeNotify(HDI_PIPE_POOL(indx)->w_mod_id, indx, HDI_PIPE_EVENT_CLOSED);
        }

        /* writer already deleted this pipe */
        if (HDI_PIPE_POOL(indx)->is_r_open == KAL_TRUE && HDI_PIPE_POOL(indx)->is_read_delay == KAL_TRUE)
        {
            /* notify reader */
            HDIc_pipeNotify(HDI_PIPE_POOL(indx)->r_mod_id, indx, HDI_PIPE_EVENT_CLOSED);
        }

        return 0;
    }

    MSF_MEM_FREE(MSF_MODID_MSM, HDI_PIPE_POOL(indx)->name);
    MSF_MEM_FREE(MSF_MODID_MSM, HDI_PIPE_POOL(indx));
    HDI_PIPE_POOL(indx) = NULL;

    return 0;

}   /* end of HDIa_pipeDelete */

/* 
 * in order to save the memory which keeps the pipe name in reader
 * provide a function to delete a pipe by handle rather a pipe name 
 * 
 * caller shall ensure the "handle" is valid.  
 */


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeDeleteByHandle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeDeleteByHandle(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_reader_handle_valid(handle) == KAL_TRUE)
    {
        PIPEDBG_(("HDIa_pipeDeleteByHandle: by reader handle=%d\n", handle));
        h = HDI_FROM_RH_TO_WH(handle);
        HDI_PIPE_POOL(h)->is_r_open = KAL_FALSE;
    }
    else if (is_writer_handle_valid(handle) == KAL_TRUE)
    {
        PIPEDBG_(("HDIa_pipeDeleteByHandle: by writer handle=%d\n", handle));
        h = handle;
        HDI_PIPE_POOL(h)->is_w_open = KAL_FALSE;
    }
    else
    {
        PIPEDBG_(("HDIa_pipeDeleteByHandle: invalid handle=%d\n", handle));
        return HDI_PIPE_ERROR_BAD_HANDLE;
    }

    return HDIa_pipeDelete(HDI_PIPE_POOL(h)->name);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeClose(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_reader_handle_valid(handle) == KAL_TRUE)
    {
        PIPEDBG_(("pipeClose: by reader handle=%d\n", handle));
        h = HDI_FROM_RH_TO_WH(handle);

        HDI_PIPE_POOL(h)->is_r_open = KAL_FALSE;

        /* reader already deleted this pipe */
        if (HDI_PIPE_POOL(h)->is_del_postponed == KAL_TRUE &&
            HDI_PIPE_POOL(h)->is_w_open == KAL_TRUE && HDI_PIPE_POOL(h)->is_write_delay == KAL_TRUE)
        {
            /* notify writer */
            HDIc_pipeNotify(HDI_PIPE_POOL(h)->w_mod_id, h, HDI_PIPE_EVENT_CLOSED);
        }

    }
    else if (is_writer_handle_valid(handle) == KAL_TRUE)
    {
        PIPEDBG_(("pipeClose: by writer handle=%d\n", handle));
        h = handle;
        HDI_PIPE_POOL(h)->is_w_open = KAL_FALSE;

        if (HDI_PIPE_POOL(h)->is_r_open == KAL_TRUE && HDI_PIPE_POOL(h)->is_read_delay == KAL_TRUE)
        {
            /* notify reader */
            HDIc_pipeNotify(HDI_PIPE_POOL(h)->r_mod_id, HDI_FROM_WH_TO_RH(h), HDI_PIPE_EVENT_CLOSED);
        }

    }
    else
    {
        PIPEDBG_(("pipeClose: invalid handle=%d\n", handle));
        return HDI_PIPE_ERROR_BAD_HANDLE;
    }

    if ((HDI_PIPE_POOL(h) != NULL) &&   /* widget_pipeNotify may delete this pipe */
        (HDI_PIPE_POOL(h)->is_del_postponed) &&
        (HDI_PIPE_POOL(h)->is_w_open == KAL_FALSE) &&
        (HDI_PIPE_POOL(h)->is_r_open == KAL_FALSE || HDI_PIPE_POOL(h)->is_r_open == -1))
    {
        HDIa_pipeDelete(HDI_PIPE_POOL(h)->name);
    }

    return 0;

}   /* end of HDIa_pipeClose */


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeClose
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeCloseError(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_reader_handle_valid(handle) == KAL_TRUE)
    {
        PIPEDBG_(("pipeClose: by reader handle=%d\n", handle));
        h = HDI_FROM_RH_TO_WH(handle);

        HDI_PIPE_POOL(h)->is_r_open = KAL_FALSE;
        HDI_PIPE_POOL(h)->is_closed_error = KAL_TRUE;

        /* reader already deleted this pipe */
        if (HDI_PIPE_POOL(h)->is_del_postponed == KAL_TRUE &&
            HDI_PIPE_POOL(h)->is_w_open == KAL_TRUE && HDI_PIPE_POOL(h)->is_write_delay == KAL_TRUE)
        {
            /* notify writer */
            HDIc_pipeNotify(HDI_PIPE_POOL(h)->w_mod_id, h, HDI_PIPE_EVENT_CLOSED_ERROR);
        }

    }
    else if (is_writer_handle_valid(handle) == KAL_TRUE)
    {
        PIPEDBG_(("pipeClose: by writer handle=%d\n", handle));
        h = handle;
        HDI_PIPE_POOL(h)->is_w_open = KAL_FALSE;
        HDI_PIPE_POOL(h)->is_closed_error = KAL_TRUE;

        if (HDI_PIPE_POOL(h)->is_r_open == KAL_TRUE && HDI_PIPE_POOL(h)->is_read_delay == KAL_TRUE)
        {
            /* notify reader */
            HDIc_pipeNotify(HDI_PIPE_POOL(h)->r_mod_id, HDI_FROM_WH_TO_RH(h), HDI_PIPE_EVENT_CLOSED_ERROR);
        }

    }
    else
    {
        PIPEDBG_(("pipeClose: invalid handle=%d\n", handle));
        return HDI_PIPE_ERROR_BAD_HANDLE;
    }

    if ((HDI_PIPE_POOL(h) != NULL) &&   /* widget_pipeNotify may delete this pipe */
        (HDI_PIPE_POOL(h)->is_del_postponed) &&
        (HDI_PIPE_POOL(h)->is_w_open == KAL_FALSE) &&
        (HDI_PIPE_POOL(h)->is_r_open == KAL_FALSE || HDI_PIPE_POOL(h)->is_r_open == -1))
    {
        HDIa_pipeDelete(HDI_PIPE_POOL(h)->name);
    }

    return 0;

}   /* end of HDIa_pipeCloseError */


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeRead
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [?]         
 *  bufSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_pipeRead(int handle, void *buf, long bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int wh;
    int occupy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buf == NULL)
    {
        return HDI_PIPE_ERROR_INVALID_PARAM;
    }
    
    /* Handle the case that BRS calls HDIa_pipeRead() and the input parameter "bufSize" is 0 */
    if (bufSize == 0)
	{
		return 0;
	}

    if (is_reader_handle_valid(handle) == KAL_FALSE)
    {
        return HDI_PIPE_ERROR_BAD_HANDLE;
    }

    wh = HDI_FROM_RH_TO_WH(handle);

    occupy = name_pipe_occupied_bytes(HDI_PIPE_POOL(wh));

    if (occupy > 0)
    {
        if (occupy > bufSize)
        {
            occupy = bufSize;
        }

        PIPEDBG_(("pipeRead: handle=%d %d bytes\n", handle, occupy));
        name_pipe_read(HDI_PIPE_POOL(wh), buf, occupy);

        if (HDI_PIPE_POOL(wh)->is_write_delay == KAL_TRUE)
        {
            HDI_PIPE_POOL(wh)->is_write_delay = KAL_FALSE;

            HDIc_pipeNotify(HDI_PIPE_POOL(wh)->w_mod_id, wh, HDI_PIPE_EVENT_WRITE);
        }
        return occupy;
    }
    else
    {
        if (HDI_PIPE_POOL(wh)->is_w_open == KAL_FALSE)
        {
            if(HDI_PIPE_POOL(wh)->is_closed_error)
                return HDI_PIPE_ERROR_CLOSED_ERROR;
            else
                return HDI_PIPE_ERROR_CLOSED;
        }
        else
        {
            return HDI_PIPE_ERROR_DELAYED;
        }
    }

}   /* end of HDIa_pipeRead */


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeWrite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [?]         
 *  bufSize     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
long HDIa_pipeWrite(int handle, void *buf, long bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int remain;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_writer_handle_valid(handle) == KAL_FALSE)
    {
        return HDI_PIPE_ERROR_BAD_HANDLE;
    }

    if (HDI_PIPE_POOL(handle)->is_r_open == KAL_FALSE && HDI_PIPE_POOL(handle)->is_del_postponed == KAL_TRUE)
    {
        if(HDI_PIPE_POOL(handle)->is_closed_error)
            return HDI_PIPE_ERROR_CLOSED_ERROR;
        else
            return HDI_PIPE_ERROR_CLOSED;
    }

    remain = name_pipe_remaining_bytes(HDI_PIPE_POOL(handle));

    if (remain > 0)
    {
        if ((HDI_PIPE_POOL(handle)->is_r_open == KAL_FALSE) && (HDI_PIPE_POOL(handle)->is_del_postponed))
        {
            if(HDI_PIPE_POOL(handle)->is_closed_error)
                return HDI_PIPE_ERROR_CLOSED_ERROR;
            else
                return HDI_PIPE_ERROR_CLOSED;
        }

        if (remain > bufSize)
        {
            remain = bufSize;
        }

        PIPEDBG_(("pipeWrite: handle=%d %d bytes\n", handle, remain));
        name_pipe_write(HDI_PIPE_POOL(handle), buf, remain);

        if (HDI_PIPE_POOL(handle)->is_read_delay == KAL_TRUE)
        {
            HDI_PIPE_POOL(handle)->is_read_delay = KAL_FALSE;

            HDIc_pipeNotify(HDI_PIPE_POOL(handle)->r_mod_id, HDI_FROM_WH_TO_RH(handle), HDI_PIPE_EVENT_READ);
        }

        return remain;
    }
    else
    {

        return HDI_PIPE_ERROR_DELAYED;
    }

}   /* end of HDIa_pipeWrite */


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipePoll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipePoll(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_reader_handle_valid(handle) == KAL_TRUE)
    {
        /* reader */
        int h = HDI_FROM_RH_TO_WH(handle);

        /* check whether writer is close */
        if (HDI_PIPE_POOL(h)->is_w_open == KAL_FALSE)
        {
            HDIc_pipeNotify(HDI_PIPE_POOL(h)->r_mod_id, handle, HDI_PIPE_EVENT_CLOSED);
        }
        else
        {
            HDI_PIPE_POOL(h)->is_read_delay = KAL_TRUE;
        }
        return 0;
    }
    else if (is_writer_handle_valid(handle) == KAL_TRUE)
    {
        /* writer */

        /* check whether reader is close */
        if (HDI_PIPE_POOL(handle)->is_r_open != -1 && HDI_PIPE_POOL(handle)->is_r_open == KAL_FALSE &&
            HDI_PIPE_POOL(handle)->is_del_postponed == KAL_TRUE)
        {
            HDIc_pipeNotify(HDI_PIPE_POOL(handle)->w_mod_id, handle, HDI_PIPE_EVENT_CLOSED);
        }
        else
        {
            HDI_PIPE_POOL(handle)->is_write_delay = KAL_TRUE;
        }
        return 0;
    }

    return HDI_PIPE_ERROR_BAD_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  isOpen          [?]         
 *  available       [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_pipeStatus(int handle, int *isOpen, long *available)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_reader_handle_valid(handle) == KAL_TRUE)
    {
        /* reader */
        int h = HDI_FROM_RH_TO_WH(handle);

        if (isOpen)
        {
            *isOpen = HDI_PIPE_POOL(h)->is_w_open;
        }

        if (available)
        {
            *available = name_pipe_occupied_bytes(HDI_PIPE_POOL(h));
        }

        return 0;

    }
    else if (is_writer_handle_valid(handle) == KAL_TRUE)
    {
        /* writer */

        if (isOpen)
        {
            if (HDI_PIPE_POOL(handle)->is_r_open == KAL_TRUE)
            {
                *isOpen = KAL_TRUE;
            }
            else
            {
                *isOpen = KAL_FALSE;
            }
        }

        if (available)
        {
            *available = name_pipe_remaining_bytes(HDI_PIPE_POOL(handle));
        }

        return 0;
    }

    return HDI_PIPE_ERROR_BAD_HANDLE;

}   /* end of HDIa_pipeStatus */


/*****************************************************************************
 * FUNCTION
 *  HDIa_pipeCloseAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_pipeCloseAll(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < MAX_NAME_PIPE_NUM; i++)
    {
        if (HDI_PIPE_POOL(i) != NULL)
        {
            if (HDI_PIPE_POOL(i)->w_mod_id == modId)
            {
                /* writer side: close */
                HDIa_pipeClose(i);
            }
            else if (HDI_PIPE_POOL(i)->r_mod_id == modId)
            {
                /* reader side: close/delete */
                HDIa_pipeClose(HDI_FROM_WH_TO_RH(i));
                HDIa_pipeDelete(HDI_PIPE_POOL(i)->name);
            }
        }
    }   /* for */

}   /* end of HDIa_pipeCloseAll */

#ifdef HDI_PIPE_UT

/* 
 * the following functions are used for testing HDI Pipe API
 */

#define HDIa_pipePrint kal_printf

/*
 * PipeUT1 : basic pipe function
 * * w: writer
 * * r: reader
 * * create (w), open(r), write(5), read(5), write(5), write(5), read(10)
 * * close(w), close(r), delete(r)
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 buf[100];
    int n;
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    r_handle = HDIa_pipeOpen(1, "abc");

    HDIa_pipePrint("write %d bytes\n", HDIa_pipeWrite(w_handle, "test1", 5));

    n = HDIa_pipeRead(r_handle, buf, 5);
    buf[n] = '\0';
    HDIa_pipePrint("read %d bytes: %s\n", n, buf);

    HDIa_pipePrint("write %d\n", HDIa_pipeWrite(w_handle, "test2", 5));

    HDIa_pipePrint("write %d\n", HDIa_pipeWrite(w_handle, "test3", 5));

    n = HDIa_pipeRead(r_handle, buf, 10);
    buf[n] = '\0';
    HDIa_pipePrint("read %d bytes: %s\n", n, buf);

    HDIa_pipeClose(w_handle);
    HDIa_pipeClose(r_handle);

    HDIa_pipeDelete("abc");

}   /* end of PipeUT1 */

/*
 * PipeUT2 : make pipe full
 * * w: writer
 * * r: reader
 * * create (w), open(r), write(500), write(1), poll(w),
 * * read(100), write(5), close(w), close(r), delete(r)
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint8 buf[MAX_NAME_PIPE_SIZE];
    int n;
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    r_handle = HDIa_pipeOpen(1, "abc");

    for (i = 0; i < MAX_NAME_PIPE_SIZE; i++)
    {
        buf[i] = (kal_uint8) i;
    }

    /* make pipe full */
    HDIa_pipePrint("write %d bytes\n", HDIa_pipeWrite(w_handle, buf, MAX_NAME_PIPE_SIZE));

    /* cannot write due to pipe full */
    HDIa_pipePrint("write %d bytes\n", HDIa_pipeWrite(w_handle, "a", 1));

    /* writer wait notifications */
    HDIa_pipePoll(w_handle);

    n = HDIa_pipeRead(r_handle, buf, 100);
    buf[n] = '\0';
    HDIa_pipePrint("read %d bytes: %s\n", n, buf);

    HDIa_pipePrint("write %d\n", HDIa_pipeWrite(w_handle, "test2", 5));

    HDIa_pipeClose(w_handle);
    HDIa_pipeClose(r_handle);

    HDIa_pipeDelete("abc");

}   /* end of PipeUT2 */

/*
 * PipeUT3 : reader reads pipe, at that pipe, pipe has no data
 * * w: writer
 * * r: reader
 * * create (w), open(r), write(500), write(1), poll(w),
 * * read(100), write(5), close(w), close(r), delete(r)
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 buf[100];
    int n;
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    r_handle = HDIa_pipeOpen(1, "abc");

    /* read no data */
    n = HDIa_pipeRead(r_handle, buf, 100);

    if (n == HDI_PIPE_ERROR_DELAYED)
    {
        /* writer wait notifications */
        HDIa_pipePoll(r_handle);
    }

    HDIa_pipePrint("write %d bytes\n", HDIa_pipeWrite(w_handle, "abc", 3));

    n = HDIa_pipeRead(r_handle, buf, 100);

    ASSERT(n == 3);

    buf[n] = '\0';
    HDIa_pipePrint("read %d bytes: %s\n", n, buf);

    HDIa_pipeClose(w_handle);
    HDIa_pipeClose(r_handle);

    HDIa_pipeDelete("abc");

}   /* end of PipeUT3 */

/*
 * PipeUT4 : Postpone to delete pipe
 * * w: writer
 * * r: reader
 * * create (w), open(r), write, read, close(r), delete(r), close(w)
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 buf[100];
    int n;
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    r_handle = HDIa_pipeOpen(1, "abc");

    HDIa_pipePrint("write %d bytes\n", HDIa_pipeWrite(w_handle, "abc", 3));

    n = HDIa_pipeRead(r_handle, buf, 100);

    ASSERT(n == 3);

    buf[n] = '\0';
    HDIa_pipePrint("read %d bytes: %s\n", n, buf);

    HDIa_pipeClose(r_handle);

    HDIa_pipeDelete("abc");

    HDIa_pipeClose(w_handle);

}   /* end of PipeUT4 */

/*
 * PipeUT5 : Create a existing pipe
 * * w: writer
 * * r: reader
 * * create a pipe named "abc", create a pipe named "abc"
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int w_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    ASSERT(w_handle >= 0);  /* create success */

    w_handle = HDIa_pipeCreate(0, "abc");

    ASSERT(w_handle == HDI_PIPE_ERROR_EXISTS);  /* create fail */

}   /* end of PipeUT5 */

/*
 * PipeUT6 : Reader opens an opened pipe
 * * w: writer
 * * r: reader
 * * create(w), open(r), open(r)
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT6
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    ASSERT(w_handle >= 0);  /* create success */

    r_handle = HDIa_pipeOpen(1, "abc");

    ASSERT(r_handle >= 0);  /* open success */

    r_handle = HDIa_pipeOpen(1, "abc");

    ASSERT(r_handle == HDI_PIPE_ERROR_IS_OPEN); /* already opened */

}   /* end of PipeUT6 */

/*
 * PipeUT7 : Create too many pipes
 * * w: writer
 * * create, create, ...
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT7
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT7(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int n;
    int w_handle;
    kal_char pipe_name[5][10] = { "name1", "name2", "name3", "name4", "name5" };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (n = 0; n < MAX_NAME_PIPE_NUM; n++)
    {
        w_handle = HDIa_pipeCreate(0, pipe_name[n]);
        ASSERT(w_handle >= 0);  /* create success */
    }

    w_handle = HDIa_pipeCreate(0, pipe_name[n]);
    ASSERT(w_handle == HDI_PIPE_ERROR_RESOURCE_LIMIT);  /* create fail */

}   /* end of PipeUT7 */

/*
 * PipeUT8 : Writer waits to write, reader closes the pipe
 * * w: writer
 * * r: reader
 * * create (w), open(r), write(500), write(1), poll(w),
 * * close(r), delete(r), close(w) 
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT8(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int n;
    kal_uint16 i;
    kal_uint8 buf[MAX_NAME_PIPE_SIZE];
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    r_handle = HDIa_pipeOpen(1, "abc");

    for (i = 0; i < MAX_NAME_PIPE_SIZE; i++)
    {
        buf[i] = (kal_uint8) i;
    }

    /* make pipe full */
    HDIa_pipePrint("write %d bytes\n", HDIa_pipeWrite(w_handle, buf, MAX_NAME_PIPE_SIZE));

    /* cannot write due to pipe full */
    n = HDIa_pipeWrite(w_handle, "a", 1);
    ASSERT(n == HDI_PIPE_ERROR_DELAYED);

    /* writer wait notifications */
    HDIa_pipePoll(w_handle);

    HDIa_pipeClose(r_handle);

    HDIa_pipeDelete("abc");

    HDIa_pipeClose(w_handle);

}   /* end of PipeUT8 */

/*
 * PipeUT9 : Reader waits to read, writer closes the pipe
 * * w: writer
 * * r: reader
 * * create (w), open(r), read, poll(r),
 * * close(w), close(r), delete(r)
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT9
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT9(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int n;
    kal_uint8 buf[MAX_NAME_PIPE_SIZE];
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    r_handle = HDIa_pipeOpen(1, "abc");

    /* read no data */
    n = HDIa_pipeRead(r_handle, buf, 100);

    ASSERT(n == HDI_PIPE_ERROR_DELAYED);

    /* writer wait notifications */
    HDIa_pipePoll(r_handle);

    HDIa_pipeClose(w_handle);

    HDIa_pipeClose(r_handle);

    HDIa_pipeDelete("abc");

}   /* end of PipeUT9 */

/*
 * PipeUT10 : Reader closes the pipe, Writer writes the pipe
 * * w: writer
 * * r: reader
 * * create (w), open(r), close(r), delete(r), write, close(w)
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT10
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT10(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int n;
    kal_uint8 buf[MAX_NAME_PIPE_SIZE];
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    r_handle = HDIa_pipeOpen(1, "abc");

    HDIa_pipeClose(r_handle);

    HDIa_pipeDelete("abc");

    n = HDIa_pipeWrite(w_handle, buf, 100);

    ASSERT(n == HDI_PIPE_ERROR_CLOSED);

    HDIa_pipeClose(w_handle);

}   /* end of PipeUT10 */

/*
 * PipeUT11 : Writer closes the pipe, reader reads the pipe 
 * * w: writer
 * * r: reader
 * * create (w), open(r), close(w), read, close(w), delete(r)
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT11
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT11(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int n;
    kal_uint8 buf[MAX_NAME_PIPE_SIZE];
    int w_handle, r_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle = HDIa_pipeCreate(0, "abc");

    r_handle = HDIa_pipeOpen(1, "abc");

    HDIa_pipeClose(w_handle);

    n = HDIa_pipeRead(r_handle, buf, 100);

    ASSERT(n == HDI_PIPE_ERROR_CLOSED);

    HDIa_pipeClose(r_handle);

    HDIa_pipeDelete("abc");

}   /* end of PipeUT11 */

/*
 * PipeUT12 : CloseAll 
 * * w: writer
 * * r: reader
 * * create pipe1, create pipe2 by module A
 * * open(r) pipe1, open pipe2 by module B,
 * * closeall(w) by module A
 * * closeall(r) by module B
 */


/*****************************************************************************
 * FUNCTION
 *  PipeUT12
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT12(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int w_handle1, r_handle1;
    int w_handle2, r_handle2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle1 = HDIa_pipeCreate(0, "pipe1");
    w_handle2 = HDIa_pipeCreate(0, "pipe2");

    r_handle1 = HDIa_pipeOpen(1, "pipe1");
    r_handle2 = HDIa_pipeOpen(1, "pipe2");

    HDIa_pipeCloseAll(0);

    HDIa_pipeCloseAll(1);

}   /* end of PipeUT12 */

/* HDIa_pipeDeleteByHandle */


/*****************************************************************************
 * FUNCTION
 *  PipeUT13
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT13(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int w_handle1, r_handle1;
    int w_handle2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle1 = HDIa_pipeCreate(0, "pipe1");
    w_handle2 = HDIa_pipeCreate(0, "pipe2");

    r_handle1 = HDIa_pipeOpen(1, "pipe1");

    HDIa_pipeClose(w_handle1);
    HDIa_pipeDeleteByHandle(r_handle1); /* delete by reader */

    HDIa_pipeDeleteByHandle(w_handle2); /* delete by writer */

}

/* after creating, reader delete the pipe directly */


/*****************************************************************************
 * FUNCTION
 *  PipeUT14
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT14(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int w_handle1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle1 = HDIa_pipeCreate(0, "pipe1");

    HDIa_pipeWrite(w_handle1, "abc", 3);

    /* reader close */
    HDIa_pipeDelete("pipe1");

    HDIa_pipeWrite(w_handle1, "abc", 3);

    HDIa_pipeClose(w_handle1);
}

/* after creating, writer delete the pipe directly */


/*****************************************************************************
 * FUNCTION
 *  PipeUT15
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PipeUT15(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int w_handle1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w_handle1 = HDIa_pipeCreate(0, "pipe1");

    HDIa_pipeDelete("pipe1");

}

#endif /* HDI_PIPE_UT */ 

