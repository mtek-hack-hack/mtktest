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
 *   aud_rec_low.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to record audio in lower priority task(MED-V) other than med task
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

#ifndef MED_V_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "fat_fs.h"
#include "custom_nvram_editor_data_item.h"

/* local include */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_v_struct.h"
#include "med_v_context.h"
#include "med_v_main.h"
#include "aud_main.h"
#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif

typedef struct
{
    kal_uint8 state;
}med_v_aud_rec_context_struct;

/* 
 * Local Variable
 */
med_v_aud_rec_context_struct medv_aud_rec;
med_v_aud_rec_context_struct *medv_aud_rec_p = &medv_aud_rec;


/* 
 *  The following section is running under MED-V task
 */

/*****************************************************************************
 * FUNCTION
 *  med_v_aud_send_record_stop_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void  
 *****************************************************************************/
void med_v_aud_send_record_stop_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(MOD_MED_V);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;
    ilm_ptr->sap_id = MED_V_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_V_AUDIO_STOP_RECORD_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  med_v_aud_send_record_pause_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void  
 *****************************************************************************/
void med_v_aud_send_record_pause_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    media_v_audio_record_pause_cnf_struct *ind_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_v_audio_record_pause_cnf_struct*)
             construct_local_para(sizeof(media_v_audio_record_pause_cnf_struct), TD_CTRL);
    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;    
    ilm_ptr->sap_id = MED_V_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_V_AUDIO_PAUSE_RECORD_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);    
}


/*****************************************************************************
 * FUNCTION
 *  med_v_aud_send_record_resume_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void  
 *****************************************************************************/
void med_v_aud_send_record_resume_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    media_v_audio_record_resume_cnf_struct *ind_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_v_audio_record_resume_cnf_struct*)
             construct_local_para(sizeof(media_v_audio_record_resume_cnf_struct), TD_CTRL);
    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;    
    ilm_ptr->sap_id = MED_V_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_V_AUDIO_RESUME_RECORD_CNF;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);    
}


/*****************************************************************************
 * FUNCTION
 *  med_v_aud_send_record_error_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void  
 *****************************************************************************/
void med_v_aud_send_record_error_ind(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    media_v_audio_record_error_ind_struct *ind_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_v_audio_record_error_ind_struct*) 
             construct_local_para(sizeof(media_v_audio_record_error_ind_struct), TD_CTRL);
    ind_p->result = result;

    ilm_ptr = allocate_ilm(MOD_MED_V);
    ilm_ptr->src_mod_id = MOD_MED_V;
    ilm_ptr->dest_mod_id = MOD_MED;    
    ilm_ptr->sap_id = MED_V_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MEDIA_V_AUDIO_RECORD_ERROR_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  med_v_aud_record_init
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_aud_record_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    medv_aud_rec_p->state = AUD_MEDIA_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  med_v_aud_start_record_req_hdlr
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_aud_start_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(MED_V_AUD_START_RECORD_REQ_HDLR, medv_aud_rec_p->state);

    medv_aud_rec_p->state = AUD_MEDIA_RECORD;
}


/*****************************************************************************
 * FUNCTION
 *  med_v_aud_stop_record_req_hdlr
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_aud_stop_record_req_hdlr(ilm_struct *ilm_ptr_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(MED_V_AUD_STOP_RECORD_REQ_HDLR, medv_aud_rec_p->state);

    medv_aud_rec_p->state = AUD_MEDIA_IDLE;
    med_v_aud_send_record_stop_cnf();
}


/*****************************************************************************
 * FUNCTION
 *  med_v_aud_pause_record_req_hdlr
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_aud_pause_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_int32 result;
    kal_uint8 res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(MED_V_AUD_PAUSE_RECORD_REQ_HDLR, medv_aud_rec_p->state);

    if(medv_aud_rec_p->state == AUD_MEDIA_RECORD)
    {
        res = aud_get_res(Media_Pause());

        /* Write the remaining data to file */
        Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
        ASSERT(aud_context_p->buf_p != NULL);
        //ASSERT(aud_context_p->buf_len <= AUD_RING_BUFFER_LEN);

        result = FS_Write(
                    aud_context_p->current_file_handle,
                    aud_context_p->buf_p,
                    aud_context_p->buf_len * 2,
                    &len);

        /* update offset */
        aud_context_p->offset += len;

        Media_ReadDataDone(len >> 1);
        AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1);
        AUD_VALUE_TRACE(result, -1, -1);

        if (result == MED_RES_OK)
        {
            medv_aud_rec_p->state = AUD_MEDIA_RECORD_PAUSED;
            med_v_aud_send_record_pause_cnf(MED_RES_OK);
        }
        else
        {
            /* inform L1AUD to stop recording process */
            Media_Stop();

            /* close record file*/
            aud_close_record_file();

            /* delete empty file */
            if (aud_context_p->offset == 0)
            {
                FS_Delete(aud_context_p->current_file_name);
            }

            if (result == FS_DISK_FULL)
            {
                res = MED_RES_DISC_FULL;
            }
            else
            {
                res = MED_RES_FAIL;
            }

            /* enter AUD_MEDIA_IDLE state */
            medv_aud_rec_p->state = AUD_MEDIA_IDLE;
            med_v_aud_send_record_pause_cnf(res);
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_v_aud_resume_record_req_hdlr
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_aud_resume_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(MED_V_AUD_RESUME_RECORD_REQ_HDLR, medv_aud_rec_p->state);

    if(medv_aud_rec_p->state == AUD_MEDIA_RECORD_PAUSED)
    {
        /* start to resume */
        res = aud_get_res((kal_uint8) Media_Resume());

        if (res == MED_RES_OK)
        {
            /* enter AUD_MEDIA_RECORD state */
            medv_aud_rec_p->state = AUD_MEDIA_RECORD;
        }
        else
        {
            /* enter AUD_MEDIA_IDLE state */
            medv_aud_rec_p->state = AUD_MEDIA_IDLE;
        }
        med_v_aud_send_record_resume_cnf(res);
    }        
}



/*****************************************************************************
 * FUNCTION
 *  aud_media_read_data_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the audio read data indication.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_v_aud_read_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_v_audio_read_data_ind_struct *msg_p;
    kal_uint32 len, prev_len;
    kal_int32 result;
    kal_uint8 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(MED_V_AUD_READ_DATA_IND_HDLR, medv_aud_rec_p->state);

    msg_p = (media_v_audio_read_data_ind_struct*) ilm_ptr->local_para_ptr;

    switch (medv_aud_rec_p->state)
    {
        case AUD_MEDIA_RECORD:
        {
            if (msg_p->event == MEDIA_DATA_NOTIFICATION)
            {
                Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));

                ASSERT(aud_context_p->buf_p != NULL);
                //ASSERT(aud_context_p->buf_len <= AUD_RING_BUFFER_LEN);

                /* Check if total record data exceed size limit */
                if(aud_context_p->size_limit > 0)
                {
                    result = FS_GetFileSize(aud_context_p->current_file_handle, &len);
                    AUD_VALUE_TRACE(result, -1, __LINE__);
                    AUD_VALUE_TRACE(aud_context_p->size_limit, len, aud_context_p->buf_len * 2);
                    
                    if((result == FS_NO_ERROR) &&
                       ((len + aud_context_p->buf_len * 2) > aud_context_p->size_limit))
                    {
                        goto write_file_error;
                    }
                }

                /* Check if total record time exceed time limit */
                if(aud_context_p->time_limit > 0)
                {
                    kal_uint32 record_time;

                    record_time = Media_GetRecordedTime();
                    AUD_VALUE_TRACE(record_time, -1, __LINE__);
                    if(record_time > (aud_context_p->time_limit * 1000))
                    {
                        result = FS_NO_ERROR;
                        goto write_file_error;                        
                    }
                }
                
                result = FS_Write(
                            aud_context_p->current_file_handle,
                            aud_context_p->buf_p,
                            aud_context_p->buf_len * 2,
                            &len);
                /* update offset */
                aud_context_p->offset += len;
                prev_len = len;

                Media_ReadDataDone(len >> 1);
                AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1);
                AUD_VALUE_TRACE(result, -1, -1);

                /* It's fine to encounter ring buffer boundary here, it will get twice when stop record .
                   So no need to get buffer twice here */

                if (result != FS_NO_ERROR)
                {
                    /* Reset previous write data */
                    if(prev_len > 0)
                    {
                        FS_Seek(aud_context_p->current_file_handle, (int)-prev_len, FS_FILE_CURRENT);
                        FS_Truncate(aud_context_p->current_file_handle);
                    }
                
                    goto write_file_error;
                }
            }
            else if (msg_p->event == MEDIA_ERROR)
            {
            	/* Assign any error cause to return */
                result = FS_ERROR_RESERVED;
                goto write_file_error;
            }

            return;
            break;
        }
        default:
        {
            return;
            break;
        }
    }

write_file_error:
    /* inform L1AUD to stop recording process */
    Media_Stop();

    /* Restore input source when stop recording */
    L1SP_SetInputSource(aud_context_p->input_device);

    /* close record file, add header if wav */
    res = aud_close_record_file();

    if (aud_context_p->offset == 0)
    {
        FS_HANDLE fh;
        kal_uint32 len = 0;

        /* Check if empty file, if yes delete it */
        fh = FS_Open(aud_context_p->current_file_name, FS_READ_ONLY | FS_NOBUSY_CHECK_MODE);

        if(fh >= 0)
        {
            FS_GetFileSize(fh, &len);
            FS_Close(fh);

            if(len == 0)
            {
                FS_Delete(aud_context_p->current_file_name);
            }
        }
    }

    /* enter AUD_MEDIA_IDLE state */
    medv_aud_rec_p->state = AUD_MEDIA_IDLE;

    /* Send indication message to MED */
    if (result == FS_DISK_FULL)
    {
        med_v_aud_send_record_error_ind(MED_RES_DISC_FULL);
    }
    else if(result == FS_NO_ERROR)
    {
        med_v_aud_send_record_error_ind(MED_RES_OK);
    }    
    else
    {
        med_v_aud_send_record_error_ind(MED_RES_ERROR);
    }
}


#endif /* #ifndef MED_V_NOT_PRESENT */

