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
 * aud_ctm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes CTM service functions
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_CTM_MOD__

#define CTM_TEXT_CONVERT_BUF_SIZE (CTM_SEND_TEXT_CHAR_MAX_NUM * 3 + 1)
typedef enum
{
    AUD_CTM_DIRECT_MODE,
    AUD_CTM_BAUDOT_MODE,
    AUD_CTM_HCO_MODE,
    AUD_CTM_VCO_MODE
} aud_ctm_interface_enum;

aud_ctm_context_struct aud_ctm_ctx;

extern const kal_uint8 utf8_bytes_per_char[16]; /* defined in aud_utility.c */
#ifdef __MED_RTP_MOD__
extern kal_uint8 voip_curr_encoding_or_decoding(void); /* To check if rtp is running */
#endif /*__MED_RTP_MOD__*/

/*****************************************************************************
 * FUNCTION
 *  aud_ctm_send_text_req_queue_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_queue       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_send_text_req_queue_init(aud_ctm_send_text_req_queue_struct *req_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_queue->head = req_queue->tail = 0;
    memset(req_queue->queue, 0, CTM_MAX_SEND_REQ_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_send_text_req_queue_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_queue       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_ctm_send_text_req_queue_full(aud_ctm_send_text_req_queue_struct *req_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 head, tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    head = req_queue->head;
    tail = req_queue->tail;
    if (tail < head)
    {
        return (head - tail == 1);
    }

    return (tail - head == CTM_MAX_SEND_REQ_NUM - 1);
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_send_text_req_queue_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_queue       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_ctm_send_text_req_queue_count(aud_ctm_send_text_req_queue_struct *req_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 head, tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    head = req_queue->head;
    tail = req_queue->tail;

    if (tail < head)
    {
        tail += CTM_MAX_SEND_REQ_NUM;
    }

    return tail - head;
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_send_text_req_queue_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_queue       [?]         
 *  req_no          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_ctm_send_text_req_queue_add(aud_ctm_send_text_req_queue_struct *req_queue, kal_uint16 req_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_ctm_send_text_req_queue_full(req_queue))
    {
        return KAL_FALSE;
    }

    req_queue->queue[req_queue->tail++] = req_no;
    if (req_queue->tail >= CTM_MAX_SEND_REQ_NUM)
    {
        req_queue->tail = 0;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_send_text_req_queue_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_queue       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_ctm_send_text_req_queue_del(aud_ctm_send_text_req_queue_struct *req_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_queue->tail == req_queue->head)
    {
        return KAL_FALSE;
    }

    if (++req_queue->head >= CTM_MAX_SEND_REQ_NUM)
    {
        req_queue->head = 0;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_send_text_req_queue_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_queue       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 *aud_ctm_send_text_req_queue_head(aud_ctm_send_text_req_queue_struct *req_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_queue->head == req_queue->tail)
    {
        return NULL;
    }
    return &(req_queue->queue[req_queue->head]);
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_read_text_from_recv_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                [?]         
 *  max_num_of_char     [IN]        
 *  more_data           [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 aud_ctm_read_text_from_recv_buf(kal_uint8 *dest, kal_uint16 max_num_of_char, kal_bool *more_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 recv_bytes, left_count;
    kal_uint8 text_bytes;
    kal_uint8 text[3];
    kal_bool align;
    kal_wchar ucs2 = 0;
    kal_uint16 num_of_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *more_data = KAL_FALSE;

    /* get the first byte of the utf8 char */
    if (aud_ctm_ctx.more_recv_utf8_byte)
    {
        /* from previous read cache */
        text[0] = aud_ctm_ctx.first_recv_utf8_byte;

        /* clear cache */
        aud_ctm_ctx.first_recv_utf8_byte = 0;
        aud_ctm_ctx.more_recv_utf8_byte = KAL_FALSE;
    }
    else
    {
        /* from l1audio text buffer */
        recv_bytes = L1Ctm_RxGetText((kal_uint8*) text, 1, &left_count);
        if (recv_bytes == 0)
        {
            return 0;
        }
    }

    CTM_READ_TEXT_TRACE1(aud_ctm_ctx.first_recv_utf8_byte, aud_ctm_ctx.more_recv_utf8_byte, text[0])
        /* get the rest of bytes of the utf8 char */
        for (num_of_char = 0; num_of_char < max_num_of_char; num_of_char++)
    {
        CTM_VALUE_TRACE(num_of_char)
            /* skip utf8 - 4 bytes char or non-utf8 data & align with the begin of utf8 - 1, 2, 3 bytes char */
            for (align = KAL_FALSE; !align;)
        {
            /* check utf8 char size, if it's non-utf8 data, its size will be 0 */
            text_bytes = utf8_bytes_per_char[text[0] >> 4];

            CTM_READ_TEXT_TRACE2(text[0], text_bytes, num_of_char)
                /* skip utf8 - 4 bytes char */
                switch (text_bytes)
            {
                case 1:
                case 2:
                case 3:
                    align = KAL_TRUE;
                    break;
                case 4:
                    /* get the rest 3 bytes char */
                    recv_bytes = L1Ctm_RxGetText((kal_uint8*) text, 3, &left_count);
                    if (recv_bytes < 3)
                    {
                        return num_of_char;
                    }
                    /* continue to get next byte */
                case 0:
                    /* get next byte */
                    recv_bytes = L1Ctm_RxGetText((kal_uint8*) text, 1, &left_count);
                    if (recv_bytes == 0)
                    {
                        return num_of_char;
                    }
                    break;
            }
        }

        text_bytes--;
        if (text_bytes != 0)
        {
            L1Ctm_RxGetText((kal_uint8*) text, 0, &left_count);
            if (left_count < (kal_uint32) text_bytes)
            {
                /* set cache */
                aud_ctm_ctx.more_recv_utf8_byte = KAL_TRUE;
                aud_ctm_ctx.first_recv_utf8_byte = text[0];
                return num_of_char;
            }
            recv_bytes = L1Ctm_RxGetText((kal_uint8*) text + 1, (kal_uint32) text_bytes, &left_count);
            ASSERT(recv_bytes == (kal_uint32) text_bytes);
        }

        switch (text_bytes)
        {
            case 0:
                ucs2 = (kal_wchar) text[0];
                break;
            case 1:
                ucs2 = ((kal_uint16) (text[0] & 0x1F) << 6) | (kal_uint16) (text[1] & 0x3F);
                break;
            case 2:
                ucs2 =
                    ((kal_uint16) (text[0] & 0x0F) << 12) | ((kal_uint16) (text[1] & 0x3F) << 6) | (kal_uint16) (text[2] & 0x3F);
                break;
            default:
                ASSERT(0);
                break;
        }

        CTM_VALUE_TRACE(ucs2) dest[num_of_char << 1] = (kal_uint8) (ucs2 & 0xFF);
        dest[(num_of_char << 1) + 1] = (kal_uint8) (ucs2 >> 8);

        /* get next byte from l1audio text buffer */
        recv_bytes = L1Ctm_RxGetText((kal_uint8*) text, 1, &left_count);
        if (recv_bytes == 0)
        {
            return num_of_char + 1;
        }
    }

    *more_data = KAL_TRUE;
    return num_of_char;
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_ctm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTM_ENTER_STATE(AUD_CTM_STATE_IDLE);
    aud_ctm_ctx.first_recv_utf8_byte = 0;
    aud_ctm_ctx.more_recv_utf8_byte = KAL_FALSE;
    aud_ctm_ctx.unsent_count = 0;
    aud_ctm_send_text_req_queue_init(&aud_ctm_ctx.send_req_queue);
    aud_ctm_ctx.buf_p = NULL;
    aud_ctm_ctx.ucs2_utf8_buf_p = NULL;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_set_speech_vol_and_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_ctm_set_speech_vol_and_path(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 input_fir_index = 0, output_fir_index = 0;
    kal_uint8 input_device  = 0, output_device = 0;
    kal_uint8 volume_gain, volume_level;
    kal_bool on = ((aud_ctm_ctx.state != AUD_CTM_STATE_IDLE) && (aud_ctm_ctx.mode != DIRECT_MODE));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* set speech output volume, device & fir coeff */
    if (on && aud_ctm_ctx.mode != AUD_CTM_HCO_MODE)
    {
        output_device = AUDIO_DEVICE_SPEAKER2;
        output_fir_index = -1;
        volume_gain = aud_ctm_ctx.output_vol;
        aud_speech_set_output_device(custom_cfg_hw_aud_output_path(output_device));
        aud_speech_set_output_volume(volume_gain, 0);
    }
    else
    {
        /* Don't set speech output path if bluetooth connected, just assign output FIR */    
    #ifdef __MED_BT_HFP_MOD__
        if (aud_bt_hfp_is_audio_path_on())
        {
            output_fir_index = 3;
        }
        else
    #endif /* __MED_BT_HFP_MOD__ */
        {
            switch (audio_mode)
            {
                case AUD_MODE_NORMAL:
                    output_device = AUDIO_DEVICE_SPEAKER;
                #ifdef __MED_RTP_MOD__
                    if(voip_curr_encoding_or_decoding())
                    {
                        output_fir_index = 4;
                    }
                    else
                #endif /*__MED_RTP_MOD__*/
                    {
                        output_fir_index = aud_context_p->audio_param.selected_FIR_output_index;
                    }
                    break;
                case AUD_MODE_HEADSET:
                    output_device = AUDIO_DEVICE_SPEAKER2;
                    output_fir_index = 1;
                    break;
                case AUD_MODE_LOUDSPK:
                    output_device = AUDIO_DEVICE_LOUDSPEAKER;
                #ifdef __MED_RTP_MOD__
                    if(voip_curr_encoding_or_decoding())
                    {
                        output_fir_index = 5;
                    }
                    else
                #endif /*__MED_RTP_MOD__*/
                    {
                        output_fir_index = 2;
                    }
                    break;
                default:
                    ASSERT(0);
                    break;
            }
            volume_level = aud_get_volume_level(audio_mode, AUD_VOLUME_SPH);
            volume_gain = aud_get_volume_gain(audio_mode, AUD_VOLUME_SPH, volume_level);

            aud_speech_set_output_device(custom_cfg_hw_aud_output_path(output_device));
            aud_speech_set_output_volume(volume_gain, 0);
        }
    }

    /* set speech input volume, device & fir */
    if (on && aud_ctm_ctx.mode != AUD_CTM_VCO_MODE)
    {
        input_device = AUDIO_DEVICE_MIC2;
        input_fir_index = -1;
        volume_gain = aud_ctm_ctx.input_vol;
    }
    else
    {
        switch (audio_mode)
        {
            case AUD_MODE_NORMAL:
                input_device = AUDIO_DEVICE_MIC1;
            #ifdef __MED_RTP_MOD__
                if(voip_curr_encoding_or_decoding())
                {
                    input_fir_index = 4;
                }
                else
            #endif /*__MED_RTP_MOD__*/
                {
                    input_fir_index = 0;
                }
                break;
            case AUD_MODE_HEADSET:
                input_device = AUDIO_DEVICE_MIC2;
                input_fir_index = 1;
                break;
            case AUD_MODE_LOUDSPK:
                input_device = AUDIO_DEVICE_MIC1;
            #ifdef __MED_RTP_MOD__
                if(voip_curr_encoding_or_decoding())
                {
                    input_fir_index = 5;
                }
                else
            #endif /*__MED_RTP_MOD__*/
                {
                    input_fir_index = 2;
                }
                break;
            default:
                ASSERT(0);
                break;                
        }
        volume_level = aud_get_volume_level(audio_mode, AUD_VOLUME_MIC);
        volume_gain = aud_get_volume_gain(audio_mode, AUD_VOLUME_MIC, volume_level);
    }
    aud_mic_set_device(custom_cfg_hw_aud_input_path(input_device));
    aud_mic_set_volume(volume_gain, volume_gain);

    /* Input path is not important for BT mode, just set FIR co-efficient */    
#ifdef __MED_BT_HFP_MOD__
    if (aud_bt_hfp_is_audio_path_on())
    {
        input_fir_index = 3;
    }
#endif /* __MED_BT_HFP_MOD__ */

    /* set speech FIR coefficient */
    aud_speech_set_fir_coefficient(input_fir_index, output_fir_index);

    return on;
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 *  param       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_event_callback(L1Ctm_Event event, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_event_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case CTM_MO_SUCCESS:
        case CTM_MO_FAIL:
        case CTM_MT_DETECTED:
        case CTM_CHAR_SENT:
        case CTM_CHAR_RECEIVED:
            ind_p = (media_ctm_event_ind_struct*) construct_local_para(sizeof(media_ctm_event_ind_struct), TD_CTRL);
            ind_p->event = event;
            aud_send_ilm(MOD_MED, MSG_ID_MEDIA_CTM_EVENT_IND, ind_p, NULL);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_event_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_event_ind_struct *ind_p = (media_ctm_event_ind_struct*) ilm_ptr->local_para_ptr;
    kal_uint16 *send_num_p;
    kal_uint16 num_of_char;
    kal_bool more_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTM_FUNC_ENTRY(AUD_CTM_EVENT_IND_HDLR)
        CTM_STATE_TRACE(aud_ctm_ctx.state) CTM_VALUE_TRACE(ind_p->event) switch (ind_p->event)
    {
        case CTM_MO_SUCCESS:
            if (aud_ctm_ctx.state == AUD_CTM_STATE_CONNECTING)
            {
                CTM_ENTER_STATE(AUD_CTM_STATE_CONNECTED);
                aud_send_ctm_connect_cnf(aud_ctm_ctx.src_mod_id, MED_RES_OK);
            }
            break;
        case CTM_MO_FAIL:
            if (aud_ctm_ctx.state == AUD_CTM_STATE_CONNECTING)
            {
                CTM_ENTER_STATE(AUD_CTM_STATE_READY);
                aud_send_ctm_connect_cnf(aud_ctm_ctx.src_mod_id, MED_RES_FAIL);
            }
            break;
        case CTM_MT_DETECTED:
            if (aud_ctm_ctx.state == AUD_CTM_STATE_READY || aud_ctm_ctx.state == AUD_CTM_STATE_CONNECTING)
            {
                CTM_ENTER_STATE(AUD_CTM_STATE_CONNECTED);
                aud_send_ctm_connected_ind(aud_ctm_ctx.src_mod_id);
            }
            break;
        case CTM_CHAR_SENT:
            if (aud_ctm_ctx.state == AUD_CTM_STATE_SENDING)
            {
                send_num_p = aud_ctm_send_text_req_queue_head(&aud_ctm_ctx.send_req_queue);
                ASSERT(send_num_p != NULL && *send_num_p != 0);

                CTM_VALUES_TRACE(
                    aud_ctm_ctx.unsent_count,
                    aud_ctm_send_text_req_queue_count(&aud_ctm_ctx.send_req_queue),
                    *send_num_p) if (--aud_ctm_ctx.unsent_count == 0)
                    CTM_ENTER_STATE(AUD_CTM_STATE_CONNECTED);
                (*send_num_p)--;
                if (*send_num_p == 0)
                {
                    aud_ctm_send_text_req_queue_del(&aud_ctm_ctx.send_req_queue);
                    aud_send_ctm_send_text_cnf(aud_ctm_ctx.src_mod_id, MED_RES_OK);
                }
            }
            break;
        case CTM_CHAR_RECEIVED:
            if (aud_ctm_ctx.state == AUD_CTM_STATE_SENDING || aud_ctm_ctx.state == AUD_CTM_STATE_CONNECTED)
            {
                do
                {
                    num_of_char = aud_ctm_read_text_from_recv_buf(
                                    aud_ctm_ctx.ucs2_utf8_buf_p,
                                    CTM_SEND_TEXT_CHAR_MAX_NUM,
                                    &more_data);
                    if (num_of_char != 0)
                    {
                        aud_send_ctm_recv_text_ind(aud_ctm_ctx.src_mod_id, num_of_char, aud_ctm_ctx.ucs2_utf8_buf_p);
                    }
                } while (more_data);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_close_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_close_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTM_STATE_TRACE(aud_ctm_ctx.state) if (aud_ctm_ctx.state != AUD_CTM_STATE_IDLE)
    {
        CTM_ENTER_STATE(AUD_CTM_STATE_IDLE);
        aud_ctm_ctx.first_recv_utf8_byte = 0;
        aud_ctm_ctx.more_recv_utf8_byte = KAL_FALSE;
        aud_ctm_ctx.unsent_count = 0;
        aud_ctm_send_text_req_queue_init(&aud_ctm_ctx.send_req_queue);

        L1Ctm_Close();

        if (aud_ctm_ctx.buf_p != NULL)
        {
            med_free_ext_mem((void **)&aud_ctm_ctx.buf_p);
        }

        if (aud_ctm_ctx.ucs2_utf8_buf_p != NULL)
        {
            med_free_ext_mem((void **)&aud_ctm_ctx.ucs2_utf8_buf_p);
        }

        /* restore speech input & output path / volume */
        aud_ctm_set_speech_vol_and_path(aud_context_p->audio_mode);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_open_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_open_req_struct *req = (media_ctm_open_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint32 buf_len;
    kal_uint8 result, ctm_inferface;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTM_FUNC_ENTRY(AUD_CTM_OPEN_REQ_HDLR) if (aud_context_p->speech_on)
    {
        /* close up if possible */
        aud_ctm_close_up();

        /* check memory requirement */
        buf_len = L1Ctm_GetMemReq();

        /* alloc from ext mem */
        aud_ctm_ctx.buf_p = (kal_uint8*) med_alloc_ext_mem(buf_len);
        ASSERT(aud_ctm_ctx.buf_p != NULL);

        aud_ctm_ctx.ucs2_utf8_buf_p = (kal_uint8*) med_alloc_ext_mem(CTM_TEXT_CONVERT_BUF_SIZE);
        ASSERT(aud_ctm_ctx.ucs2_utf8_buf_p != NULL);

        /* update state to ready state */
        CTM_ENTER_STATE(AUD_CTM_STATE_READY);
        aud_ctm_ctx.src_mod_id = ilm_ptr->src_mod_id;
        aud_ctm_ctx.mode = ctm_inferface = req->ctm_interface;

        /* call l1audio ctm open */
        if (ctm_inferface > AUD_CTM_BAUDOT_MODE)
        {
            ctm_inferface = AUD_CTM_BAUDOT_MODE;
        }
        L1Ctm_Open(ctm_inferface, aud_ctm_event_callback, aud_ctm_ctx.buf_p, buf_len, (CTM_Param*) & req->ctm_param);

        aud_ctm_ctx.input_vol = req->ctm_param.input_vol;
        aud_ctm_ctx.output_vol = req->ctm_param.output_vol;

        aud_ctm_set_speech_vol_and_path(aud_context_p->audio_mode);

        result = MED_RES_OK;
    }
    else
    {
        result = MED_RES_FAIL;
    }

    /* send a confirm message back to caller */
    aud_send_ctm_open_cnf(ilm_ptr->src_mod_id, result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_close_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTM_FUNC_ENTRY(AUD_CTM_CLOSE_REQ_HDLR)
        /* close up if possible */
        aud_ctm_close_up();

    /* send a confirm message back to caller */
    aud_send_ctm_close_cnf(ilm_ptr->src_mod_id, MED_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_connect_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_connect_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTM_FUNC_ENTRY(AUD_CTM_CONNECT_REQ_HDLR)
        CTM_STATE_TRACE(aud_ctm_ctx.state) if (aud_ctm_ctx.state != AUD_CTM_STATE_READY)
        aud_send_ctm_connect_cnf(ilm_ptr->src_mod_id, MED_RES_FAIL);
    else
    {
        if (aud_ctm_ctx.mode == DIRECT_MODE)
        {
            aud_ctm_ctx.src_mod_id = ilm_ptr->src_mod_id;
            CTM_ENTER_STATE(AUD_CTM_STATE_CONNECTING);
            L1Ctm_StartNegotiation();
        }
        else
        {
            aud_send_ctm_connect_cnf(ilm_ptr->src_mod_id, MED_RES_FAIL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_send_text_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_send_text_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_ctm_send_text_req_struct *req_p = (media_ctm_send_text_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint32 text_bytes;
    kal_uint32 sent_bytes;
    kal_uint32 left_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CTM_FUNC_ENTRY(AUD_CTM_SEND_TEXT_REQ_HDLR) CTM_STATE_TRACE(aud_ctm_ctx.state) if (aud_ctm_ctx.mode != DIRECT_MODE)
    {
        aud_send_ctm_connect_cnf(ilm_ptr->src_mod_id, MED_RES_FAIL);
        return;
    }

    switch (aud_ctm_ctx.state)
    {
        case AUD_CTM_STATE_CONNECTED:
            ASSERT(aud_ctm_send_text_req_queue_count(&aud_ctm_ctx.send_req_queue) == 0);
            if (aud_ctm_ctx.mode == DIRECT_MODE)
            {
                CTM_ENTER_STATE(AUD_CTM_STATE_SENDING);
            }
            else
            {
                aud_send_ctm_send_text_cnf(ilm_ptr->src_mod_id, MED_RES_FAIL);
            }
        case AUD_CTM_STATE_SENDING:
            if (aud_ctm_ctx.mode == DIRECT_MODE)
            {
                if (aud_ctm_send_text_req_queue_full(&aud_ctm_ctx.send_req_queue))
                {
                    aud_send_ctm_send_text_cnf(ilm_ptr->src_mod_id, MED_RES_FAIL);
                }
                else
                {
                    aud_ctm_ctx.src_mod_id = ilm_ptr->src_mod_id;
                    /* convert ucs2 to utf8 */
                    text_bytes =
                        (kal_uint32) med_util_ucs2_to_utf8(
                                        aud_ctm_ctx.ucs2_utf8_buf_p,
                                        CTM_TEXT_CONVERT_BUF_SIZE,
                                        (kal_uint8*) req_p->text,
                                        (kal_uint32) req_p->num_of_char * 2) - 1;

                    CTM_VALUES_TRACE(
                        aud_ctm_ctx.unsent_count,
                        aud_ctm_send_text_req_queue_count(&aud_ctm_ctx.send_req_queue),
                        text_bytes) aud_ctm_ctx.unsent_count += (kal_uint16) text_bytes;
                    aud_ctm_send_text_req_queue_add(&aud_ctm_ctx.send_req_queue, (kal_uint16) text_bytes);

                    /* fill utf8 text to l1audio ctm Tx text buffer */
                    sent_bytes = L1Ctm_TxPutText(aud_ctm_ctx.ucs2_utf8_buf_p, text_bytes, &left_count);
                    ASSERT(sent_bytes == text_bytes);
                }
            }
            else
            {
                aud_send_ctm_send_text_cnf(ilm_ptr->src_mod_id, MED_RES_FAIL);
            }
            break;
        default:
            aud_send_ctm_send_text_cnf(ilm_ptr->src_mod_id, MED_RES_FAIL);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_ctm_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ctm_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_CTM_EVENT_IND:
            aud_ctm_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CTM_OPEN_REQ:
            aud_ctm_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CTM_CLOSE_REQ:
            aud_ctm_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CTM_CONNECT_REQ:
            aud_ctm_connect_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_CTM_SEND_TEXT_REQ:
            aud_ctm_send_text_req_hdlr(ilm_ptr);
            break;
        default:
            ASSERT(0);
    }
}
#endif /* __MED_CTM_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

