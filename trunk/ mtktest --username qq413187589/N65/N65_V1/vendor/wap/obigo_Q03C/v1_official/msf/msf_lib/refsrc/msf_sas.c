/*
* Copyright (C) Obigo AB, 2002-2005.
* All rights reserved.
*
* This software is covered by the license agreement between
* the end user and Obigo AB, and may be 
* used and copied only in accordance with the terms of the 
* said agreement.
*
* Obigo AB assumes no responsibility or 
* liability for any errors or inaccuracies in this software, 
* or any consequential, incidental or indirect damage arising
* out of the use of the software.
*
*/
/*
* msf_dlg.c
*
* Dialog package:
* 
*
* Created by Simon Magnusson, May 30 2003.
*
* Revision  history:
*
* 
*/

#include "msf_core.h"
#include "msf_log.h"
#include "msf_wid.h"
#include "msf_lib.h"
#include "msf_mem.h"
#include "msf_pck.h"
#include "msf_sas.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_env.h"

#include "widget.h"
#include "widget_extension.h"
#include "fs_type.h"
#include "fat_fs.h"
#include "dlagentdef.h"

/**********************************************************************
* Configuration
**********************************************************************/

/**********************************************************************
* Defines 
**********************************************************************/

#define MSF_SAS_STATE_NULL 1
#define MSF_SAS_STATE_DOWNLOADING 2
#define MSF_SAS_STATE_MESSAGE_WAIT 3
#define MSF_SAS_STATE_FINISHED 4

#define MSF_SAS_ERROR_SAVE_FAILED 1
#define MSF_SAS_ERROR_DISK_FULL 2
#define MSF_SAS_ERROR_CONNECTION_CLOSED 3
#define MSF_SAS_ERROR_USER_CANCELLED 4

#define MSF_SAS_BUFFER_SIZE 2048

typedef struct msf_sas_action_st {
    struct msf_sas_action_st   *next;
    MsfActionHandle             handle;
} msf_sas_action_t;

typedef struct msf_sas_window_st {
    struct msf_sas_window_st     *next;
    MsfWindowHandle               handle;
    msf_sas_action_t             *action;
} msf_sas_window_t;

typedef struct msf_sas_op_st {
    struct msf_sas_op_st  *next;
    MSF_INT32              id;          /* operation identifier */
    int                    state;
    void                  *priv_data;
    long                   status;    /* status of operation */
    char                  *mime_type;
    char                  *file_name;
    char                  *dst_posix; /*file_name dest in posix format*/
    int                    data_type;
    void                  *data;
    long                   data_len;
    char                  *pathname;
    msf_sas_window_t      *window;
    MsfScreenHandle        screen;
    int                    download_size;
    int                    file_handle;
    int                    pipe_handle;
    char                   buffer[MSF_SAS_BUFFER_SIZE];
    int                    buffer_tail;
} msf_sas_op_t;

typedef struct msf_sas_handle_st {
    MSF_UINT8                  modid;
    msf_sas_op_t              *op;
} msf_sas_handle_t;

/**********************************************************************
* Local functions
**********************************************************************/
static msf_sas_op_t *
find_op_by_id (msf_sas_handle_t *handle, MSF_INT32 id)
{
    msf_sas_op_t *op = handle->op;

    while (op) {
        if (op->id == id)
            return op;
        op = op->next;
    }
    return NULL;
}

static msf_sas_action_t *
get_new_action (msf_sas_handle_t *handle, msf_sas_window_t *window)
{
    msf_sas_action_t *action = MSF_MEM_ALLOCTYPE (handle->modid, msf_sas_action_t);

    action->handle = 0;

    /* insert new action first in list */
    action->next = window->action;
    window->action = action;
    return action;
}

static void
free_sas_action(msf_sas_handle_t *handle, msf_sas_window_t *window, msf_sas_action_t *action)
{
    msf_sas_action_t *temp_action = window->action;
    msf_sas_action_t *prev_action = NULL;

    /*Remove action*/
    while (temp_action != action) {
        prev_action = temp_action;
        temp_action = temp_action->next;
    }
    if (prev_action)
        prev_action->next = action->next;
    else
        window->action = action->next;

    /* Free action*/
    MSF_WIDGET_REMOVE (window->handle, action->handle); 
    MSF_WIDGET_RELEASE(action->handle); 
    MSF_MEM_FREE(handle->modid, action);

}

static msf_sas_window_t *
get_new_window (msf_sas_handle_t *handle, msf_sas_op_t *op)
{
    msf_sas_window_t *window = MSF_MEM_ALLOCTYPE (handle->modid, msf_sas_window_t);

    window->handle = 0;
    window->action = NULL;

    /* insert new window first in list */
    window->next = op->window;
    op->window = window;
    return window;
}

static void
free_sas_window(msf_sas_handle_t *handle, msf_sas_op_t *op, msf_sas_window_t *window)
{
    msf_sas_window_t *temp_window = op->window;
    msf_sas_window_t *prev_window = NULL;

    /*Remove window*/

    while (temp_window != window) {
        prev_window = temp_window;
        temp_window = temp_window->next;
    }
    if (prev_window)
        prev_window->next = window->next;
    else
        op->window = window->next;

    /*Free window*/

    while (window->action)
        free_sas_action(handle, window, window->action);

    MSF_WIDGET_REMOVE (op->screen, window->handle); 
    MSF_WIDGET_RELEASE(window->handle);
    MSF_MEM_FREE(handle->modid, window);

}

static msf_sas_op_t *
get_new_op (msf_sas_handle_t *handle)
{
    static int msf_sas_uniq_id = 1;

    msf_sas_op_t *op = MSF_MEM_ALLOCTYPE (handle->modid, msf_sas_op_t);

    op->id = msf_sas_uniq_id++;
    op->state = 0;
    op->status = MSF_SAS_RETURN_NOT_AVAILABLE;
    op->mime_type = NULL;
    op->file_name = NULL;
    op->dst_posix = NULL;
    op->data_type = 0;
    op->data = NULL;
    op->data_len = 0;
    op->pathname = NULL;
    op->priv_data = NULL;
    op->window = 0;
    op->screen = 0;
    op->file_handle = 0;
    op->pipe_handle = 0;
    op->download_size = 0;
    memset(op->buffer, 0, MSF_SAS_BUFFER_SIZE);
    op->buffer_tail = 0;

    /* insert new operation first in list */
    op->next = handle->op;
    handle->op = op;

    return op;
}

static void
free_sas_op(msf_sas_handle_t *handle, msf_sas_op_t *op)
{
    msf_sas_op_t *temp_op = handle->op;
    msf_sas_op_t *prev_op = NULL;

    /*Remove op*/

    while (temp_op != op) {
        prev_op = temp_op;
        temp_op = temp_op->next;
    }
    if (prev_op)
        prev_op->next = op->next;
    else
        handle->op = op->next;

    /*Free op*/

    while (op->window)
        free_sas_window (handle, op, op->window);

    if(op->data_type == MsfResourceFile)
    {
        HDIa_widgetExtCloseTransitionAnimation();      
    }
    
    MSF_MEM_FREE (handle->modid, op->mime_type);
    MSF_MEM_FREE (handle->modid, op->file_name);
    MSF_MEM_FREE (handle->modid, op->dst_posix);
    MSF_MEM_FREE (handle->modid, op->pathname);
    MSF_MEM_FREE (handle->modid, op);
    op = NULL;
}

static int write_to_buffer(msf_sas_handle_t *handle, msf_sas_op_t *op, char *buf, unsigned int size)
{
    unsigned int bytes_to_write, bytes_written;
    int ret;
    
    if(!buf || size == 0)
        return -1;

    bytes_to_write = (op->buffer_tail + size <= MSF_SAS_BUFFER_SIZE) ? size : MSF_SAS_BUFFER_SIZE - op->buffer_tail;
    memcpy(op->buffer + op->buffer_tail, buf, bytes_to_write);
    op->buffer_tail = (op->buffer_tail + bytes_to_write) % MSF_SAS_BUFFER_SIZE;
    
    if(op->buffer_tail == 0)
    {
        ret = FS_Write(op->file_handle, op->buffer, MSF_SAS_BUFFER_SIZE, (UINT*) &bytes_written);

        if (ret != FS_NO_ERROR)
        {
            return -1;
        }
    }

    if(size > bytes_to_write)
    {
        return write_to_buffer(handle, op, buf + bytes_to_write, size - bytes_to_write);
    }

    return 0;
}

static int flush_buffer(msf_sas_handle_t *handle, msf_sas_op_t *op)
{
    unsigned int bytes_written;
    int ret;

    if(op->buffer_tail > 0)
    {
        ret = FS_Write(op->file_handle, op->buffer, op->buffer_tail, (UINT*) &bytes_written);

        if (ret != FS_NO_ERROR)
        {
            return -1;
        }
    }
	return 0;
}

static void
msf_sas_progressbar_cancel_hdlr(ctk_screen_handle scrid)
{
    MsfWindowHandle window = HDIa_widgetCtkGetWindow(scrid);

    HDIc_widgetAction(_H(window)->module_id, window, 0);
    widget_send_update_event_to_wap();
}

static void
msf_sas_create_error_dialog (msf_sas_handle_t* handle, msf_sas_op_t *op, MsfStringHandle message)
{  
    MsfPosition                   null_pos = {0, 0};
    msf_sas_window_t             *message_window = get_new_window (handle, op);
    msf_sas_action_t             *action_ok = get_new_action(handle, message_window);

    message_window->handle = MSF_WIDGET_DIALOG_CREATE (handle->modid, 
        message,
        MsfError,
        0, 0, 0);

    MSF_WIDGET_SET_TITLE (message_window->handle, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_SAS_ERROR_TITLE));
    MSF_WIDGET_WINDOW_SET_PROPERTIES (message_window->handle,MSF_WINDOW_PROPERTY_TITLE);

    /* Create an Ok action. */
    action_ok->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
        MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
    MSF_WIDGET_ADD_ACTION (message_window->handle, action_ok->handle);

    MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, message_window->handle,
        &null_pos, 0, 0);

    MSF_WIDGET_SET_IN_FOCUS (op->screen, 1);
    MSF_WIDGET_SET_IN_FOCUS (message_window->handle, 1);
    HDIa_widgetExtPaintDirectly();
}

static void
msf_sas_update_progressbar(msf_sas_handle_t* handle, msf_sas_op_t *op);

static void
msf_sas_create_progressbar (msf_sas_handle_t* handle, msf_sas_op_t *op)
{  
    msf_sas_window_t *bar_window = get_new_window (handle, op);
    msf_sas_action_t *action_cancel = get_new_action(handle, bar_window);

    extern kal_bool widget_allow_create_new_MMI_screen(void);
    ctk_screen_handle screen_id;
    MsfPosition pos = {0, 0};

    if (widget_allow_create_new_MMI_screen() == KAL_FALSE)
    {
        ASSERT(0);
        return;
    }

    bar_window->handle = HDIa_widgetExtCreateProgressView(handle->modid, MSF_STR_ID_SAS_BAR_TITLE, WAP_IMAGE_WAP_LOGO, KAL_TRUE);
    msf_sas_update_progressbar(handle, op);
    
    /* Create a Cancel action. */
    action_cancel->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
        MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_SAS_ACTION_CANCEL), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
    /* MSF_WIDGET_ADD_ACTION (bar_window->handle, action_cancel->handle); */

    HDIa_widgetScreenAddWindow(op->screen, bar_window->handle, &pos, 0, 0);

    screen_id = HDIa_widgetCtkGetScreenHandle(bar_window->handle);

    ctk_screen_addRSK_UA(screen_id, STR_GLOBAL_CANCEL, 0, NULL, msf_sas_progressbar_cancel_hdlr, KAL_TRUE);

    HDIa_widgetSetInFocus(op->screen, TRUE);
    HDIa_widgetSetInFocus(bar_window->handle, TRUE);
    HDIa_widgetExtPaintDirectly();
    return;
}

static void
msf_sas_update_progressbar(msf_sas_handle_t* handle, msf_sas_op_t *op)
{
    char buffer[36], buffer2[36], buffer3[128];
    kal_uint8 *buf, *filename;
    static int percent;
    int dealloc_required = 0;
    int a, b, len;

    if (op->download_size < 1024)
    {
        sprintf(buffer, "%dBytes", op->download_size);
    }
    else if (op->download_size < 1024 * 1024)  /* display in (kb) */
    {
        a = op->download_size / 1024;
        sprintf(buffer, "%dKB", a);
    }
    else
    {
        a = op->download_size / (1024 * 1024);
        b = ((op->download_size * 10) / (1024 * 1024)) % 10;
        sprintf(buffer, "%d.%dMB", a, b);
    }

    if(op->data_len > 0)
    {
        if (op->data_len < 1024)
        {
            sprintf(buffer2, "%dBytes", (int)op->data_len);
        }
        else if (op->data_len < 1024 * 1024)  /* display in (kb) */
        {
            a = op->data_len / 1024;
            sprintf(buffer2, "%dKB", a);
        }
        else
        {
            a = op->data_len / (1024 * 1024);
            b = ((op->data_len * 10) / (1024 * 1024)) % 10;
            sprintf(buffer2, "%d.%dMB", a, b);
        }
        sprintf(buffer3, "%s / %s", buffer, buffer2);
    }
    else
    {
        strcpy(buffer3, buffer);
    }

    if (op->download_size > 0)
    {
        len = widget_utf8_to_ucs2_length_in_bytes((const kal_uint8 *)buffer3) + ENCODING_LENGTH;
        buf = MSF_MEM_ALLOC(handle->modid, len);
        widget_utf8_to_ucs2_string(buf, len, (const kal_uint8*)buffer3);
        dealloc_required = TRUE;
    }
    else
    {
        buf = (kal_uint8*) HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_CONNECTING);
    }

    if (op->data_len > 0 && op->download_size <= op->data_len)
    {
        percent = op->download_size * 100 / op->data_len;
    }
    else if (op->download_size == 0)
    {
        percent = 0;
    }
    else
    {
        percent += 20;
        if(percent > 100)
            percent = 0;
    }

    len = widget_utf8_to_ucs2_length_in_bytes((const kal_uint8 *)op->dst_posix) + ENCODING_LENGTH;
    filename = MSF_MEM_ALLOC(handle->modid, len);
    widget_utf8_to_ucs2_string(filename, len, (const kal_uint8*)op->dst_posix);

    HDIa_widgetExtSetProgressPercentage(
        op->window->handle,
        percent,
        filename,
        buf);
    MSF_MEM_FREE(handle->modid, filename);

    if(dealloc_required)
    {
        MSF_MEM_FREE(handle->modid, buf);
    }
}

static int
msf_sas_read_pipe_data(msf_sas_handle_t* handle, msf_sas_op_t *op)
{
    int bufsize = 1024;
    char *buf = MSF_MEM_ALLOC(handle->modid, bufsize);

    int bytes_read;
    long available;
    int isOpen;
    int ret;

    do
    {
        bytes_read = MSF_PIPE_READ(op->pipe_handle, buf, bufsize);
        op->download_size += bytes_read;

        if (bytes_read > 0)
        {
            ret = write_to_buffer(handle, op, buf, bytes_read);

            if (ret != 0)
            {
                msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_SAS_ERROR_FULL));
                op->state = MSF_SAS_STATE_MESSAGE_WAIT;
                MSF_MEM_FREE(handle->modid, buf);                
                return MSF_PACKAGE_SIGNAL_HANDLED;
            }
        }
    } while (bytes_read >= 0);

    MSF_MEM_FREE(handle->modid, buf);                

    if (bytes_read == MSF_PIPE_ERROR_DELAYED)
    {
        MSF_PIPE_POLL(op->pipe_handle);
    }
    else if(bytes_read == MSF_PIPE_ERROR_CLOSED)
    {
        flush_buffer(handle, op);
        MSF_PIPE_CLOSE(op->pipe_handle);
        MSF_PIPE_DELETE(op->pathname);
        op->state = MSF_SAS_STATE_FINISHED;
        op->status = MSF_SAS_RETURN_OK;
        return MSF_PACKAGE_OPERATION_COMPLETE;
    }
    else if(bytes_read == MSF_PIPE_ERROR_CLOSED_ERROR || MSF_PIPE_STATUS(op->pipe_handle, &isOpen, &available) != 0)
    {
        MSF_PIPE_CLOSE(op->pipe_handle);
        MSF_PIPE_DELETE(op->pathname);
        msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_CONNECTION_FAILED));
        op->state = MSF_SAS_STATE_MESSAGE_WAIT;
        return MSF_PACKAGE_SIGNAL_HANDLED;
    }

    op->state = MSF_SAS_STATE_DOWNLOADING;
    return MSF_PACKAGE_SIGNAL_HANDLED;
}

static int
msf_sas_handle_pipe_notify(msf_sas_handle_t *handle, msf_sas_op_t *op, int event_type)
{
	static int update_count = 0;
    int res;

    switch (event_type)
    {
    case MSF_PIPE_EVENT_READ:
        res = msf_sas_read_pipe_data(handle, op);
		if(res == MSF_PACKAGE_OPERATION_COMPLETE || (++update_count % 10 == 0)) {
			msf_sas_update_progressbar(handle, op);
		}
        break;
    case MSF_PIPE_EVENT_CLOSED:
        flush_buffer(handle, op);
        MSF_PIPE_CLOSE(op->pipe_handle);
        MSF_PIPE_DELETE(op->pathname);
        op->state = MSF_SAS_STATE_FINISHED;
        op->status = MSF_SAS_RETURN_OK;
        res = MSF_PACKAGE_OPERATION_COMPLETE;
        break;
    case MSF_PIPE_EVENT_CLOSED_ERROR:
        MSF_PIPE_CLOSE(op->pipe_handle);
        MSF_PIPE_DELETE(op->pathname);
        msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_CONNECTION_FAILED));
        op->status = MSF_SAS_RETURN_ERROR;
        op->state = MSF_SAS_STATE_MESSAGE_WAIT;
        res = MSF_PACKAGE_SIGNAL_HANDLED;
        break;
    default:
        res = MSF_PACKAGE_SIGNAL_NOT_HANDLED;
        break;
    }
    return res;
}

static int
is_disk_space_enough(const char *file_name, MSF_UINT32 size)
{
    kal_int32 result;
    FS_DiskInfo diskinfo;
    kal_uint8 *path;

    path = HDI_FileNameTranslate(file_name);

    result = FS_GetDiskInfo((WCHAR *)path, &diskinfo, FS_DI_FREE_SPACE);

    HDI_FileNameFree(path);

    if(result < 0)
        return result;

    return (diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector) >= size;
}

static void
msf_sas_send_dl_ind(MSF_UINT8 mod_src, MSF_UINT8 data_type, const char *url, const char *mime_type, const kal_uint8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    mmi_da_dispatch_file_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (mmi_da_dispatch_file_req_struct*) construct_local_para(sizeof(mmi_da_dispatch_file_req_struct), TD_RESET);
    p->mime_type = 0;
    p->mime_subtype = 0;

    memset(p->url, 0, sizeof(p->url));

    if (mod_src == MSF_MODID_PHS)
    {
        p->action = MMI_DA_PUSH;
    }
    else if (mod_src == MSF_MODID_SMA || mod_src == MSF_MODID_MEA)
    {
        p->action = MMI_DA_SAVE_AS;
        strcpy((char *)p->url, "mms://");
    }
    else if (data_type == MsfResourceFile)
    {
        p->action = MMI_DA_SAVE_AS;
    }
    else
    {
        p->action = MMI_DA_WAP_DOWNLOAD;

        if (strlen(url) > 0)
        {
            strncpy((char *)p->url, url, strlen(url) > sizeof(p->url) ? sizeof(p->url) : strlen(url));
        }
        else
        {
            strcpy((char *)p->url, "http://");
        }
    }

    memset(p->filepath, 0, sizeof(p->filepath));
    widget_ucs2_strcpy((kal_uint8*) p->filepath, (const kal_uint8*)file_name);

    strcpy((char *)p->mime_type_string, (const char*)mime_type);

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_DA_DISPATCH_FILE_REQ;  /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return;
}

static void
handle_buffer_content(msf_sas_handle_t* handle, msf_sas_op_t *op)
{
    int file_handle;
    int size_remain;
    int bytes_written;
    int size;

    if(!op->data)
    {
        msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_SAVE_AS_FAIL));
        op->state = MSF_SAS_STATE_MESSAGE_WAIT;
        return;
    }

    FS_Delete((WCHAR *)op->file_name);

    file_handle = FS_Open((WCHAR *)op->file_name, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);

    if (file_handle <= 0)
    {
        msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_SAVE_AS_FAIL));
        op->state = MSF_SAS_STATE_MESSAGE_WAIT;
        return;
    }

    size_remain = op->data_len;
    bytes_written = 0;

    while (size_remain > 0)
    {
        if (FS_Write(file_handle, (void *)(op->data), size_remain, (UINT*) & size) != FS_NO_ERROR)
        {
            msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_SAVE_AS_FAIL));
            op->state = MSF_SAS_STATE_MESSAGE_WAIT;
            return;
        }
        if (size <= 0)
        {
            break;
        }
    }

    op->status = MSF_SAS_RETURN_OK;
    op->state = MSF_SAS_STATE_FINISHED;
    return;
}


static void
handle_file_content(msf_sas_handle_t* handle, msf_sas_op_t *op)
{
    int ret;
    kal_uint8 *src;

    if(!op->pathname)
    {
        msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_SAVE_AS_FAIL));
        op->state = MSF_SAS_STATE_MESSAGE_WAIT;
        return;
    }

    src = HDI_FileNameTranslate(op->pathname);
    
    if(handle->modid == MSF_MODID_MEA || handle->modid == MSF_MODID_SMA)
    {
        HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_TRUE);
    }
    else
    {
        HDIa_widgetExtDisplayTransitionAnimationNoEnd(KAL_FALSE);
    }
    ret = FS_Move((const WCHAR *)src, (const WCHAR *)op->file_name, FS_MOVE_COPY | FS_MOVE_OVERWRITE, 0, NULL, 0);

    HDI_FileNameFree(src);

    if (ret != FS_NO_ERROR)
    {
        if(ret == FS_ROOT_DIR_FULL || ret == FS_DISK_FULL)
        {
            HDIa_widgetExtShowPopup(
    			handle->modid,
                HDIa_widgetStringGetPredefined(MSF_STR_ID_SAS_ERROR_FULL),
                MsfError,
                0);
        }
        else
        {
            HDIa_widgetExtShowPopup(
    			handle->modid,
                HDIa_widgetStringGetPredefined(BRA_STR_ID_SAVE_AS_FAIL),
                MsfError,
                0);
        }
		op->status = MSF_SAS_RETURN_ERROR;
		op->state = MSF_SAS_STATE_FINISHED;
    }
	else
	{
		op->status = MSF_SAS_RETURN_OK;
		op->state = MSF_SAS_STATE_FINISHED;
	}
    return;

}


static void
handle_pipe_content(msf_sas_handle_t* handle, msf_sas_op_t *op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int file_handle;
    int pipe_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Delete((WCHAR *)op->file_name);

    file_handle = FS_Open((WCHAR *)op->file_name, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);

    if (file_handle <= 0)
    {
        msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_SAVE_AS_FAIL));
        op->state = MSF_SAS_STATE_MESSAGE_WAIT;
        return;
    }

    pipe_handle = MSF_PIPE_OPEN(handle->modid, op->pathname);
    if (pipe_handle < 0)
    {
        FS_Close(file_handle);
        FS_Delete((WCHAR *)op->file_name);

        msf_sas_create_error_dialog (handle, op, MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_CONNECTION_FAILED));
        op->state = MSF_SAS_STATE_MESSAGE_WAIT;
        return;
    }

    op->file_handle = file_handle;
    op->pipe_handle = pipe_handle;

    msf_sas_read_pipe_data(handle, op);

    if(op->state == MSF_SAS_STATE_DOWNLOADING)
    {
        msf_sas_create_progressbar(handle, op);
    }
    
    return;
}

static int
msf_sas_handle_widget_action (msf_sas_handle_t *handle, MSF_INT32 *id, MsfWindowHandle window_handle, MsfActionHandle action_handle)
{
    msf_sas_op_t *op = handle->op;
    msf_sas_op_t *found_op = NULL;
    msf_sas_window_t *found_window = NULL;

    while (op && (!found_op)) {
        msf_sas_window_t *window = op->window;
        while (window && (!found_window)) {
            if (window->handle == window_handle) {
                found_op = op;
                found_window = window;
                *id = op->id;
            }
            window = window->next;
        }
        op = op->next;
    }
    if (found_op) 
    {
        int actionType;
        int priority;
        switch (found_op->state)
        {
        case MSF_SAS_STATE_MESSAGE_WAIT:
            MSF_WIDGET_ACTION_GET_ATTR(action_handle, &actionType, &priority);
            if (actionType == MsfOk){
                free_sas_window(handle, found_op, found_window);
                found_op->state = MSF_SAS_STATE_FINISHED;
                found_op->status = MSF_SAS_RETURN_ERROR;
                return MSF_PACKAGE_OPERATION_COMPLETE;
            }
            break;
        case MSF_SAS_STATE_DOWNLOADING:
            found_op->status = MSF_SAS_RETURN_CANCELLED;
            free_sas_window(handle, found_op, found_window);
            found_op->state = MSF_SAS_STATE_FINISHED;
            return MSF_PACKAGE_OPERATION_COMPLETE;        
        }
        return MSF_PACKAGE_SIGNAL_HANDLED;
    }
    return MSF_PACKAGE_SIGNAL_NOT_HANDLED;
}

/**********************************************************************
* Global functions
**********************************************************************/

/*
* Initialise the save as package.
* Returns a handle if success, otherwise returns NULL.
*/
msf_pck_handle_t*
msf_sas_init (MSF_UINT8 modid)
{
    msf_sas_handle_t *h = MSF_MEM_ALLOCTYPE (modid, msf_sas_handle_t);

    if (h) {
        h->modid = modid;
        h->op = NULL;
    }

    return (msf_pck_handle_t*)h;
}

/*
* Runs the save as package. When the module receives a signal that is
* defined by MSF, the module must call this function because the
* dialog package might be the receiver.
*
* Returns:
*    MSF_PACKAGE_SIGNAL_NOT_HANDLED
*      The signal was not handled by the package, the calling module
*      must process the signal by itself.
*    MSF_PACKAGE_SIGNAL_HANDLED
*      The signal was handled by the package.
*    MSF_PACKAGE_OPERATION_COMPLETE
*      The signal was handled by the package and the save as operation is 
*      finished. In this case the id parameter indicates which operation that 
*      is finished. 
*/
int
msf_sas_handle_signal (msf_pck_handle_t* handle, MSF_UINT16 signal, void* p,
                       MSF_INT32* id)
{
    msf_sas_handle_t* sas_handle = (msf_sas_handle_t*)handle;
    msf_sas_op_t *op;

    int res;

    if (!handle)
        return MSF_PACKAGE_SIGNAL_NOT_HANDLED;

    if (!(sas_handle->op))
        return MSF_PACKAGE_SIGNAL_NOT_HANDLED;

    op = sas_handle->op;

    switch(signal)
    {
    case MSF_SIG_PIPE_NOTIFY:
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, sas_handle->modid, MSF_SAS_B55FC5D106FA99EEF0F20A8DB7FDBD9D, "MSF_SAS: Received MSF_SIG_PIPE_NOTIFY\n"));
        {
            msf_pipe_notify_t *pipe_notify = (msf_pipe_notify_t*) p;
            while (op && op->pipe_handle != pipe_notify->handle)
                op = op->next;
            if(!op)
                return MSF_PACKAGE_SIGNAL_NOT_HANDLED;
            *id = op->id;
            if (op->status != MSF_SAS_RETURN_NOT_AVAILABLE)
            {
                return MSF_PACKAGE_OPERATION_COMPLETE;
            }
            res = msf_sas_handle_pipe_notify(sas_handle, sas_handle->op, pipe_notify->eventType);
        }
        break;
    case MSF_SIG_WIDGET_ACTION:
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, sas_handle->modid, MSF_SAS_F672EBA75978EC511242615FB9464C81, "MSF_SAS: Received MSF_SIG_WIDGET_ACTION\n"));
        {
            msf_widget_action_t *action = (msf_widget_action_t *) p;

            res = msf_sas_handle_widget_action (sas_handle, id, action->handle, action->action);

        }
        break;
    default:
        res = MSF_PACKAGE_SIGNAL_NOT_HANDLED;
        break;
    }
    return res;
}

/*
* Set private data connected to a specific save as operation. The private 
* data might be used by the module to indicate which sub module that started 
* the save as operation. This function may be called after a
* msf_sas_create_xxx function has been called.
* Returns TRUE if success, otherwise FALSE.
*/
int
msf_sas_set_private_data (msf_pck_handle_t* handle, MSF_INT32 id, void* p)
{
    msf_sas_handle_t* sas_handle = (msf_sas_handle_t*)handle;
    msf_sas_op_t *op = find_op_by_id (sas_handle, id);
    if (!op)
        return FALSE;
    op->priv_data = p;
    return TRUE;
}

/*
* Get private data connected to a specific save as operation. The private 
* data might be used by the module to indicate which sub module that has
* started the operation. This function may be called after 
* msf_sas_handle_signal returned MSF_PACKAGE_OPERATION_COMPLETE.
* If success returns the private data, otherwise returns MSF_PACKAGE_ERROR.
*/
void*
msf_sas_get_private_data (msf_pck_handle_t* handle, MSF_INT32 id)
{
    msf_sas_handle_t* sas_handle = (msf_sas_handle_t*)handle;
    msf_sas_op_t *op = find_op_by_id (sas_handle, id);
    if (!op)
        return NULL;
    return op->priv_data;
}


/*
* Terminates the save as package, release all resources allocated by
* this package. If there is any open dialogs, these dialog are
* deleted. Any private data must be released by the module itself.
* Returns TRUE  if success, otherwise FALSE.
*/
int
msf_sas_terminate (msf_pck_handle_t* handle)
{
    msf_sas_handle_t* sas_handle = (msf_sas_handle_t*)handle;

    while (sas_handle->op)
        free_sas_op(sas_handle, sas_handle->op);

    MSF_MEM_FREE(sas_handle->modid, sas_handle);

    return TRUE;
}

/**********************************************************************
* Delete 
**********************************************************************/

/*
* Deletes a created save as operation. Any private data is not released by 
* this function. The module call this function when the module of any
* reason must delete the operation before the finished state has been
* reached.
* Returns TRUE  if success, otherwise FALSE.
*/
int
msf_sas_delete (msf_pck_handle_t* handle, MSF_INT32 id)
{
    msf_sas_handle_t* sas_handle = (msf_sas_handle_t*)handle;
    msf_sas_op_t *op = find_op_by_id (sas_handle, id);

    if (!op)
        return FALSE;

    free_sas_op(sas_handle, op);
    return TRUE;
}

/*
* Get the result of a completed operation. The caller must
* call this function when msf_dlg_handle_signal has returned
* MSF_PACKAGE_OPERATION_COMPLETE for this specific dialog. This
* function also releases all allocated resources connected to the
* specific dialog , but only if the function is called when the
* operation is finished. Any private data associated with this 
* operation must be freed by the using module before this function
* is called.
* Returns TRUE if success, otherwise FALSE.
*/

int
msf_sas_get_result (msf_pck_handle_t  *handle,
                    MSF_INT32          id,
                    msf_pck_result_t  *result)
{
    msf_sas_handle_t          *sas_handle = (msf_sas_handle_t*)handle;
    msf_sas_op_t              *op;
    msf_sas_result_save_as_t  *res;

    if (!handle)
        return FALSE;

    op = find_op_by_id (sas_handle, id);
    if (op == NULL)
        return FALSE;

    result->type = MSF_SAS_TYPE;
    res = result->_u.data = MSF_MEM_ALLOCTYPE (sas_handle->modid, msf_sas_result_save_as_t);
    res->file_name = NULL;
    res->fn_posix  = NULL;
    res->result = op->status;

    if (op->status != MSF_SAS_RETURN_NOT_AVAILABLE)
    {
        if(op->file_handle)
            FS_Close(op->file_handle);
        
        if(op->pipe_handle)
        {
            MSF_PIPE_CLOSE(op->pipe_handle);
        }
        
        if (op->data_type == MSF_PCK_DATA_TYPE_PIPE)
        {
            MSF_PIPE_DELETE(op->pathname);
        }

        if (op->status != MSF_SAS_RETURN_OK)
        {
            if (op->file_name)
                FS_Delete((const WCHAR *)op->file_name);

            if (op->status == MSF_SAS_RETURN_CANCELLED)
            {
                HDIa_widgetExtShowPopup(sas_handle->modid, 
                    MSF_WIDGET_STRING_GET_PREDEFINED(BRA_STR_ID_SAS_OPERATION_CANCELED), 
                    MsfInfo,
                    0);
            }
        }
        else
        {
            extern kal_uint8 wap_status;
            extern char contentUrl[256];

            if (wap_status != WAP_RUNNING)
            {
                /* Obigo will return MSF_SAS_RETURN_OK when shutdown mobile suite, 
                * but the file might be truncated.
                */
                FS_Delete((const WCHAR *)op->file_name);
            }
            else
            {
                msf_sas_send_dl_ind(sas_handle->modid, op->data_type, contentUrl, op->mime_type, (const kal_uint8 *)op->file_name);
                res->file_name = msf_cmmn_strdup (sas_handle->modid, op->file_name);
                res->fn_posix = msf_cmmn_strdup (sas_handle->modid, op->dst_posix);
            }
        }
        free_sas_op(sas_handle, op);
    }
    return TRUE;
}

/*
* Free the storage allocated in the get result function
*
* Argument:
* result       Result data to be freed.
*
* Returns:     TRUE if success, otherwise FALSE. 
*/

int
msf_sas_result_free(msf_pck_handle_t* handle, msf_pck_result_t* result)
{
    msf_sas_handle_t* sas_handle = (msf_sas_handle_t*)handle;

    if (!result)
        return FALSE;
    if (result->_u.data){
        if (result->type == MSF_SAS_TYPE){
            if (((msf_sas_result_save_as_t*)result->_u.data)->file_name)
                MSF_MEM_FREE( sas_handle->modid , ((msf_sas_result_save_as_t*)result->_u.data)->file_name);
            if (((msf_sas_result_save_as_t*)result->_u.data)->fn_posix)
                MSF_MEM_FREE( sas_handle->modid , ((msf_sas_result_save_as_t*)result->_u.data)->fn_posix);
            MSF_MEM_FREE( sas_handle->modid , ((msf_sas_result_save_as_t*)result->_u.data));
        }
        else
            return FALSE;
    }

    return TRUE;
}


/*
* Create a save as operation.
*
* Save as parameters:
*  file_name             Suggested user friendly name of the file.
*  mime_type             The mime type of file to save.
*  data_type             Tells if the data to save comes from a pipe, file or
*                        buffer. value must be one of the following constants:
*                          MSF_PCK_DATA_TYPE_FILE,
*                          MSF_PCK_DATA_TYPE_PIPE,
*                          MSF_PCK_DATA_TYPE_BUFFER
*  data                  The data that shall be written to file. This 
*                        parameter is only used when data comes from a 
*                        buffer.
*  data_len              The size of the data. This parameter is only used 
*                        when data comes from a buffer.
*  pathname              The name of the pipe or file. This parameter is only
*                        used when data comes from a pipe or a file.
*  screen                The screen that should be used for the dialog.
*  file_attrs            the file attributes that should be stored with the
*                        specified file.
*  bit_flag              MSF_SAS_ALLOW_OVERWRITE   -  if bit is set, the package will prompt
*                          the user about the replace and possibly replace the existing file.
*                        MSF_SAS_DO_NOT_SHOW_DIALOG   -  if bit is set, the package will not 
*                          allow the user to select position or name of the file to save, but
*                          the file will be saved to a temporary default position with a default
*                          name.
*                        MSM_SAS_NO_EXTERNAL_MEMORY - If this bit is set no folders on
*                          external memory will be possible to select as save destination.
* 
* Returns positive number denoting an id if ok and MSF_PACKAGE_ERROR otherwise.
*/
MSF_INT32
msf_sas_create_save_as (msf_pck_handle_t* handle,
                        const char* file_name,
                        const char* mime_type,
                        int   data_type,
                        void* data,
                        long  data_len,
                        const char *pathname,
                        const msf_pck_attr_list_t *file_attrs,
                        MsfScreenHandle screen,
                        MSF_INT32 bit_flag)
{
    msf_sas_handle_t* sas_handle = (msf_sas_handle_t*)handle;
    msf_sas_op_t      *op = get_new_op (sas_handle);

    op->data_type = data_type;
    op->data = data;
    op->data_len = data_len;
    op->screen = screen;

    op->mime_type = msf_cmmn_strdup (sas_handle->modid, mime_type);
    op->pathname = msf_cmmn_strdup (sas_handle->modid, pathname);
    op->dst_posix = msf_cmmn_strdup (sas_handle->modid, file_name);
    
    {
        char *path = WAP_DOWNLOAD_FOLDER;
        char *temp;
        char temp_ext[24] = "";
        kal_uint8 *dest_file;
        int r;

        msm_remove_files_under_dir(path);
        HDIa_fileMkDir(path);

        r = is_disk_space_enough(path , op->data_len);
        
        if(r < 0) /* File system error occurs. */
        {
    				HDIa_widgetExtShowPopup(
    					sas_handle->modid,
    					HDIa_widgetStringGetPredefined(MSF_STR_ID_DLG_SAVE_ERROR),
    					MsfError,
    					0);
    				op->status = MSF_SAS_RETURN_ERROR;
    				op->state = MSF_SAS_STATE_FINISHED;
            goto end;            
        }
        else if(r == 0)
        {
            // If there is no more space on public drive, see if we have memory card or not.
            sprintf(temp_ext, "%s%c:\\", HDI_EXTERNAL_PATH, FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE));
            if(is_disk_space_enough(temp_ext, op->data_len) <= 0)
            {
                HDIa_widgetExtShowPopup(
                    sas_handle->modid,
                    HDIa_widgetStringGetPredefined(MSF_STR_ID_SAS_ERROR_FULL),
                    MsfError,
                    0);
                op->status = MSF_SAS_RETURN_ERROR;
                op->state = MSF_SAS_STATE_FINISHED;
                goto end;
            }
            else
            {
                path = temp_ext;
            }
        }

        temp = msf_cmmn_strcat(sas_handle->modid, path, file_name);

        dest_file = HDI_FileNameTranslate(temp);

        MSF_MEM_FREE(sas_handle->modid, temp);

        op->file_name = (char *)widget_ucs2_strdup(sas_handle->modid, dest_file);

        HDI_FileNameFree(dest_file);
    }

    if(data_type == MsfResourceFile)
    {
        handle_file_content(handle, op);
    }
    else if(data_type == MsfResourceBuffer)
    {
        handle_buffer_content(handle, op);
    }
    else if(data_type == MsfResourcePipe)
    {
        handle_pipe_content(handle, op);
    }

end:
    return op->id;
}
