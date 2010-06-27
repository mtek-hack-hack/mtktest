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
 * med_utility.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes common used functions of media task.
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

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
/* Buffer Management */
#include "app_buff_alloc.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
/* for tst inject message */
#include "tst_sap.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_main.h"
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "fat_fs.h"
#include "med_smalloc.h"
#include "med_utility.h"
#include "med_trc.h"

#if defined(__DRM_V02__)
#include "Drm_gprot.h"
#endif

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
}
timer_table_struct;

timer_table_struct med_timer_table[MAX_NUM_OF_MED_TIMER];
kal_mutexid med_mem_mutex;

#if defined(__SW_JPEG_CODEC_SUPPORT__)
kal_mutexid med_stack_mem_mutex;
#endif

#if 1 //ndef MED_LOW /*Always turn on this utility*/

const kal_uint8 utf8_bytes_per_char[16] = 
{
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 2, 2, 3, 4
};


/*****************************************************************************
 * FUNCTION
 *  med_util_utf8_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [?]         
 *  dest_size       [IN]        (>=4)
 *  src             [?]         
 *  src_size        [IN]        (>=1) it is used to prevent from infinte loop when src data are not utf8
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 med_util_utf8_to_ucs2(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cnt, c;
    kal_uint16 ucs2;
    kal_uint32 dest_count = 0;
    kal_uint32 src_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_size -= ((dest_size % 2) + 2); /* make it a even number + null terminator */

    while (dest_count < dest_size && src_count < src_size && (c = *src))
    {
        cnt = utf8_bytes_per_char[c >> 4];
        switch (cnt)
        {
            case 1:
                dest[dest_count] = c;
                dest[dest_count + 1] = 0;
                dest_count += 2;
                src++;
                src_count++;
                break;
            case 2:
                ucs2 = ((kal_uint16) (c & 0x1F) << 6) | (kal_uint16) (src[1] & 0x3F);
                dest[dest_count] = ucs2 & 0xFF;
                dest[dest_count + 1] = ucs2 >> 8;
                dest_count += 2;
                src += 2;
                src_count += 2;
                break;
            case 3:
                ucs2 =
                    ((kal_uint16) (c & 0x0F) << 12) | ((kal_uint16) (src[1] & 0x3F) << 6) | (kal_uint16) (src[2] &
                                                                                                          0x3F);
                dest[dest_count] = ucs2 & 0xFF;
                dest[dest_count + 1] = ucs2 >> 8;
                dest_count += 2;
                src += 3;
                src_count += 3;
                break;
            case 4:
                src += 4;   /* skip it since we don't support UCS4 */
                src_count += 4;
                break;
            case 0:
                src++;      /* something wrong with the src, skip it */
                src_count++;
                break;
        }
    }
    dest[dest_count] = 0;
    dest[dest_count + 1] = 0;
    return dest_count + 2;
}


/*****************************************************************************
 * FUNCTION
 *  med_util_ucs2_to_utf8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [?]         
 *  dest_size       [IN]        (>=1)
 *  src             [?]         
 *  src_size        [IN]        (>=2)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 med_util_ucs2_to_utf8(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 lb, hb;
    kal_uint32 dest_count = 0;
    kal_uint32 src_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_size -= 1; /* one byte space for null terminator */

    lb = src[0];
    hb = src[1];
    while (dest_count < dest_size && src_count < src_size &&    /* not exceed limited size */
           (lb != 0 || hb != 0))    /* src does not encounter null terminator */
    {
        if (hb == 0 && (lb & 0x80) == 0)
        {
            dest[dest_count++] = lb;
        }
        else
        {
            if (hb & 0xF8 == 0)
            {
                dest[dest_count++] = 0xC0 | (hb << 2) | (lb >> 6);
            }
            else
            {
                dest[dest_count++] = 0xE0 | (hb >> 4);
                dest[dest_count++] = 0x80 | ((hb & 0x0F) << 2) | (lb >> 6);
            }
            dest[dest_count++] = 0x80 | (lb & 0x3F);
        }
        src_count += 2;
        lb = src[src_count];
        hb = src[src_count + 1];
    }
    dest[dest_count] = 0;
    return dest_count + 1;
}

#endif /* MED_LOW */ 


/*****************************************************************************
 * FUNCTION
 *  med_utility_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_utility_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_NUM_OF_MED_TIMER; i++)
    {
        med_timer_table[i].event_id = NULL;
    }

    /* init internal memory */
    med_set_int_memory_pool((unsigned char*)med_context_p->int_mem_p, MED_INT_MEM_SIZE);

    /* init external memory */
    med_set_ext_memory_pool((unsigned char*)med_context_p->ext_mem_p, MED_EXT_MEM_SIZE);

    med_mem_mutex = kal_create_mutex("MED MEM");
#if defined(__SW_JPEG_CODEC_SUPPORT__)
    med_stack_mem_mutex = kal_create_mutex("MED STACK MEM");
#endif
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  med_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_timer_expiry_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *stack_timer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_timer_ptr = (stack_timer_struct*) ilm_ptr->local_para_ptr;

    if (stack_timer_ptr->timer_indx == MED_BASE_TIMER_ID)
    {
        /* Check if the base timer is stopped or not */
        if (stack_is_time_out_valid(&med_context_p->base_timer))
        {
            /* Execute event's timeout handler */
            evshed_timer_handler(med_context_p->event_scheduler_ptr);
        }
        /* Should be paired with stack_is_time_out_valid() */
        stack_process_time_out(&med_context_p->base_timer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_get_buffer_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_get_buffer_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_get_buffer_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_get_buffer_req_struct*) ilm_ptr->local_para_ptr;

    if (req_p->location == 0)
    {
        *(req_p->buffer_p) = med_alloc_int_mem(req_p->buffer_size);
    }
    else
    {
        *(req_p->buffer_p) = med_alloc_ext_mem(req_p->buffer_size);
    }

    MED_SET_EVENT(MED_EVT_GET_BUFFER);
}


/*****************************************************************************
 * FUNCTION
 *  med_free_buffer_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_buffer_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_free_buffer_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_free_buffer_req_struct*) ilm_ptr->local_para_ptr;
    if (req_p->location == 0)
    {
        med_free_int_mem(req_p->buffer_p);
    }
    else
    {
        med_free_ext_mem(req_p->buffer_p);
    }

    MED_SET_EVENT(MED_EVT_FREE_BUFFER);
}


/*****************************************************************************
 * FUNCTION
 *  med_start_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [?]         
 *  time_out            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_start_base_timer(void *base_timer_ptr, kal_uint32 time_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_start_timer((stack_timer_struct*) base_timer_ptr, MED_BASE_TIMER_ID, time_out);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  med_stop_base_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base_timer_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_stop_base_timer(void *base_timer_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_stop_timer((stack_timer_struct*) base_timer_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  med_timer_expiry_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *timer_id = (kal_uint8*) arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32) timer_id < (kal_uint32) MAX_NUM_OF_MED_TIMER)
    {
        med_timer_table[(kal_uint32) (timer_id)].event_id = NULL;
        (med_timer_table[(kal_uint32) (timer_id)].callback_func) (med_timer_table[(kal_uint32) (timer_id)].arg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id            [IN]        
 *  period              [IN]        
 *  timer_expiry        [IN]        
 *  arg                 [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void med_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 temp = (period * 7) >> 5;    /* ~= x 1/4.615 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp == 0)
    {
        temp = 1;
    }
    med_timer_table[timer_id].callback_func = timer_expiry;
    med_timer_table[timer_id].arg = arg;
    med_timer_table[timer_id].event_id = evshed_set_event(
                                            med_context_p->event_scheduler_ptr,
                                            (kal_timer_func_ptr) med_timer_expiry_callback,
                                            (void*)timer_id,
                                            temp /** KAL_TICKS_10_MSEC */ );
}


/*****************************************************************************
 * FUNCTION
 *  med_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_stop_timer(kal_uint8 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (med_timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(med_context_p->event_scheduler_ptr, &(med_timer_table[timer_id].event_id));
        med_timer_table[timer_id].event_id = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  med_alloc_int_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *med_alloc_int_mem_ext(kal_int32 size,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p ;
    kal_prompt_trace(MOD_MED,"get internal buffer from: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    p = (void*)med_int_smalloc((size_type) size);
    kal_give_mutex(med_mem_mutex);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL)
    {
        ASSERT(p != NULL);
    }
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  med_free_int_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_int_mem_ext(void **pointer,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED,"free internal buffer from: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    med_int_sfree((address_t) * pointer);
    *pointer = NULL;
    kal_give_mutex(med_mem_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  med_alloc_ext_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *med_alloc_ext_mem_ext(kal_int32 size,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED,"get external buffer from: %s, %d",file_p,line_p);
    if (size == 0)
    {
        return NULL;
    }
    kal_take_mutex(med_mem_mutex);
    p = (void*)med_ext_smalloc((size_type) size);
    kal_give_mutex(med_mem_mutex);
    //if(p==NULL)
    //{
    //ASSERT(p!=NULL);
    //}
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  med_free_ext_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_free_ext_mem_ext(void **pointer,char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MED,"free external buffer from: %s, %d",file_p,line_p);
    kal_take_mutex(med_mem_mutex);
    med_ext_sfree((address_t) * pointer);
    kal_give_mutex(med_mem_mutex);
    *pointer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  med_check_disc_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_name        [?]         
 *  free_byte       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 med_check_disc_space(kal_wchar *dir_name, kal_int32 free_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    FS_DiskInfo disc_info;
    kal_wchar dir[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(dir, 0, 6);
    kal_mem_cpy(dir, dir_name, 4);
    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE))
    {
        if ((disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector) < free_byte)
        {
            return MED_RES_DISC_FULL;
        }
        else
        {
            return MED_RES_OK;
        }
    }
    else
    {
        return MED_RES_NO_DISC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_get_media_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 med_get_media_type(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *p;
    kal_wchar temp[6];
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = file_name + kal_wstrlen(file_name) - 5;

    kal_mem_cpy(temp, p, 2 * 6);

    for (i = 0; i < 5; i++)
    {
        if (temp[i] >= 97 /* 'a' */  && temp[i] <= 122 /* 'z' */ )
        {
            temp[i] -= 32 /* ('a'-'A') */ ;
        }
    }

    p = &temp[2];
    if (kal_wstrcmp(p, L".VM") == 0)
    {
        return MED_TYPE_GSM_EFR;
    }
#ifdef AU_DECODE
    if (kal_wstrcmp(p, L".AU") == 0)
    {
        return MED_TYPE_AU;
    }
#endif /* AU_DECODE */ 

    p = &temp[1];
    if (kal_wstrcmp(p, L".IMY") == 0)
    {
        return MED_TYPE_IMELODY;
    }
    if (kal_wstrcmp(p, L".MID") == 0)
    {
        return MED_TYPE_SMF;
    }
    if (kal_wstrcmp(p, L".WAV") == 0)
    {
        return MED_TYPE_WAV;
    }
#if defined(YAMAHA_MA3)
    if (kal_wstrcmp(p, L".MMF") == 0)
    {
        return MED_TYPE_MMF;
    }
#endif /* defined(YAMAHA_MA3)*/ 
    if (kal_wstrcmp(p, L".PCM") == 0)
    {
        return MED_TYPE_PCM_8K;
    }
    if (kal_wstrcmp(p, L".DVI") == 0)
    {
        return MED_TYPE_DVI_ADPCM;
    }
#ifndef MT6205B
#ifdef DAF_DECODE
    if (kal_wstrcmp(p, L".MP3") == 0)
    {
        return MED_TYPE_DAF;
    }
#endif /* DAF_DECODE */ 
    if (kal_wstrcmp(p, L".MP2") == 0)
    {
        return MED_TYPE_MUSICAM;
    }
    if (kal_wstrcmp(p, L".AMR") == 0)
    {
        return MED_TYPE_AMR;
    }
#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
    if (kal_wstrcmp(p, L".AWB") == 0)
    {
        return MED_TYPE_AMR_WB;
    }
#endif /* defined(AMRWB_DECODE) || defined(AMRWB_ENCODE) */ 
#ifdef AAC_DECODE
    if (kal_wstrcmp(p, L".AAC") == 0)
    {
        return MED_TYPE_AAC;
    }
    if (kal_wstrcmp(p, L".M4A") == 0)
    {
        return MED_TYPE_M4A;
    }
#endif /* AAC_DECODE */ 
#if defined(MED_PURE_AUDIO)
    if (kal_wstrcmp(p, L".MP4") == 0)
    {
        return MED_TYPE_MP4;
    }
    if (kal_wstrcmp(p, L".3GP") == 0)
    {
        return MED_TYPE_3GP;
    }
#endif /* #if defined(MED_PURE_AUDIO) */ 
#if defined(JPG_DECODE) || defined(JPG_ENCODE)
    if (kal_wstrcmp(p, L".JPG") == 0)
    {
        return MED_TYPE_JPG;
    }
#endif /* defined(JPG_DECODE) || defined(JPG_ENCODE) */ 
#if defined(GIF_DECODE)
    if (kal_wstrcmp(p, L".JPG") == 0)
    {
        return MED_TYPE_GIF;
    }
#endif /* defined(GIF_DECODE) */ 
#ifdef AIFF_DECODE
    if (kal_wstrcmp(p, L".AIF") == 0)
    {
        return MED_TYPE_AIFF;
    }
#endif /* AIFF_DECODE */
#ifdef AU_DECODE
    if (kal_wstrcmp(p, L".SND") == 0)
    {
        return MED_TYPE_AU;
    }
#endif /* AU_DECODE */

#ifdef __MED_VR_MOD__
    if (kal_wstrcmp(p, L".VRD") == 0)
    {
        return MED_TYPE_VR;
    }
#endif /* __MED_VR_MOD__ */ 

#ifdef WMA_DECODE
    if (kal_wstrcmp(p, L".WMA") == 0)
    {
        return MED_TYPE_WMA;
    }
#endif /* WMA_DECODE */ 

#if defined(__DRM_V02__)
    if (kal_wstrcmp(p, L".ODF") == 0)
    {
        /* Make sure it is not multi-part ODF */
        if (!DRM_is_archive(NULL, file_name ))
        {
            kal_char *ext_name;
            kal_wchar temp_file_name[10];
            
            /* Single part ODF , get single part ODF content extension name */
            ext_name = DRM_get_content_ext(NULL, file_name);
            if(ext_name != NULL)
            {
                kal_wsprintf(temp_file_name, "A.%s", ext_name);
                return med_get_media_type(temp_file_name);
            }
            else
            {
                return MED_TYPE_NONE;
            }
        }
    }
#endif /* defined(__DRM_V02__) */

    p = &temp[0];
#ifdef AIFF_DECODE
    if (kal_wstrcmp(p, L".AIFF") == 0 || kal_wstrcmp(p, L".AIFC") == 0)
    {
        return MED_TYPE_AIFF;
    }
#endif /* AIFF_DECODE */
    if (kal_wstrcmp(p, L".MIDI") == 0)
    {
        return MED_TYPE_SMF;
    }
#endif /* MT6205B */ 

    return MED_TYPE_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  med_retrieve_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 *  path            [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_retrieve_file_path(kal_wchar *file_name, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy(path, file_name);
    p = path + kal_wstrlen(path);
    while (p > path)
    {
        if (*p == L'\\')
        {
            *(p + 1) = 0;
            return KAL_TRUE;
        }
        p--;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  med_remove_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_remove_file_name(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = file_name + kal_wstrlen(file_name);
    while (p > file_name)
    {
        if (*p == L'\\')
        {
            *(p + 1) = 0;
            return KAL_TRUE;
        }
        p--;
    }
    return KAL_FALSE;
}

/* crc */

static kal_uint32 const crc_table[256] = 
{
    0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL,
    0x076dc419L, 0x706af48fL, 0xe963a535L, 0x9e6495a3L,
    0x0edb8832L, 0x79dcb8a4L, 0xe0d5e91eL, 0x97d2d988L,
    0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L, 0x90bf1d91L,
    0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
    0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L,
    0x136c9856L, 0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL,
    0x14015c4fL, 0x63066cd9L, 0xfa0f3d63L, 0x8d080df5L,

    0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L, 0xa2677172L,
    0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
    0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L,
    0x32d86ce3L, 0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L,
    0x26d930acL, 0x51de003aL, 0xc8d75180L, 0xbfd06116L,
    0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L, 0xb8bda50fL,
    0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
    0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL,

    0x76dc4190L, 0x01db7106L, 0x98d220bcL, 0xefd5102aL,
    0x71b18589L, 0x06b6b51fL, 0x9fbfe4a5L, 0xe8b8d433L,
    0x7807c9a2L, 0x0f00f934L, 0x9609a88eL, 0xe10e9818L,
    0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
    0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL,
    0x6c0695edL, 0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L,
    0x65b0d9c6L, 0x12b7e950L, 0x8bbeb8eaL, 0xfcb9887cL,
    0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L, 0xfbd44c65L,

    0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
    0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL,
    0x4369e96aL, 0x346ed9fcL, 0xad678846L, 0xda60b8d0L,
    0x44042d73L, 0x33031de5L, 0xaa0a4c5fL, 0xdd0d7cc9L,
    0x5005713cL, 0x270241aaL, 0xbe0b1010L, 0xc90c2086L,
    0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
    0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L,
    0x59b33d17L, 0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL,

    0xedb88320L, 0x9abfb3b6L, 0x03b6e20cL, 0x74b1d29aL,
    0xead54739L, 0x9dd277afL, 0x04db2615L, 0x73dc1683L,
    0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
    0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L,
    0xf00f9344L, 0x8708a3d2L, 0x1e01f268L, 0x6906c2feL,
    0xf762575dL, 0x806567cbL, 0x196c3671L, 0x6e6b06e7L,
    0xfed41b76L, 0x89d32be0L, 0x10da7a5aL, 0x67dd4accL,
    0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,

    0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L,
    0xd1bb67f1L, 0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL,
    0xd80d2bdaL, 0xaf0a1b4cL, 0x36034af6L, 0x41047a60L,
    0xdf60efc3L, 0xa867df55L, 0x316e8eefL, 0x4669be79L,
    0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
    0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL,
    0xc5ba3bbeL, 0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L,
    0xc2d7ffa7L, 0xb5d0cf31L, 0x2cd99e8bL, 0x5bdeae1dL,

    0x9b64c2b0L, 0xec63f226L, 0x756aa39cL, 0x026d930aL,
    0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
    0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L,
    0x92d28e9bL, 0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L,
    0x86d3d2d4L, 0xf1d4e242L, 0x68ddb3f8L, 0x1fda836eL,
    0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L, 0x18b74777L,
    0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
    0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L,

    0xa00ae278L, 0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L,
    0xa7672661L, 0xd06016f7L, 0x4969474dL, 0x3e6e77dbL,
    0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L, 0x37d83bf0L,
    0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
    0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L,
    0xbad03605L, 0xcdd70693L, 0x54de5729L, 0x23d967bfL,
    0xb3667a2eL, 0xc4614ab8L, 0x5d681b02L, 0x2a6f2b94L,
    0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL, 0x2d02ef8dL
};

/*
 * NAME: crc->calculate()
 * DESCRIPTION:   compute CRC-32 value (ISO 3309)
 */


/*****************************************************************************
 * FUNCTION
 *  med_crc_calculate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]        
 *  length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    register kal_uint32 crc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (crc = 0xffffffffL; length >= 8; length -= 8)
    {
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
    }

    switch (length)
    {
        case 7:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 6:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 5:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 4:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 3:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 2:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 1:
            crc = crc_table[(crc ^ *data++) & 0xff] ^ (crc >> 8);
        case 0:
            break;
    }

    return crc ^ 0xffffffffL;
}



/*****************************************************************************
 * FUNCTION
 *  med_debug_print_result
 * DESCRIPTION
 *  print result to trace
 * PARAMETERS
 *  result        [IN]      result  
 * RETURNS
 *  void 
 *****************************************************************************/
void med_debug_print_result(kal_int32 result, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#define SWITCH_CASE_RESULT_MACRO(__RES_NAME__)\
    case MED_RES_##__RES_NAME__:\
        kal_trace(TRACE_GROUP_4, MED_TRC_RES_##__RES_NAME__, line);\
        break;
    
    switch(result)
    {
        SWITCH_CASE_RESULT_MACRO(OK);                       /* 0 */
        SWITCH_CASE_RESULT_MACRO(FAIL);                     
        SWITCH_CASE_RESULT_MACRO(BUSY);                 
        SWITCH_CASE_RESULT_MACRO(DISC_FULL);        
        SWITCH_CASE_RESULT_MACRO(OPEN_FILE_FAIL);   
        SWITCH_CASE_RESULT_MACRO(END_OF_FILE);       
        SWITCH_CASE_RESULT_MACRO(TERMINATED);
        SWITCH_CASE_RESULT_MACRO(BAD_FORMAT);
        SWITCH_CASE_RESULT_MACRO(INVALID_FORMAT);
        SWITCH_CASE_RESULT_MACRO(ERROR);
        SWITCH_CASE_RESULT_MACRO(NO_DISC);                  /* 10 */
        SWITCH_CASE_RESULT_MACRO(NOT_ENOUGH_SPACE);
        SWITCH_CASE_RESULT_MACRO(INVALID_HANDLE);
        SWITCH_CASE_RESULT_MACRO(NO_HANDLE);
        SWITCH_CASE_RESULT_MACRO(RESUME);
        SWITCH_CASE_RESULT_MACRO(BLOCKED);
        SWITCH_CASE_RESULT_MACRO(MEM_INSUFFICIENT);
        SWITCH_CASE_RESULT_MACRO(BUFFER_INSUFFICIENT);
        SWITCH_CASE_RESULT_MACRO(FILE_EXIST);
        SWITCH_CASE_RESULT_MACRO(WRITE_PROTECTION);
        SWITCH_CASE_RESULT_MACRO(PARAM_ERROR);              /* 20 */
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_CHANNEL);
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_FREQ);
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_TYPE);
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_OPERATION);
        SWITCH_CASE_RESULT_MACRO(PARSER_ERROR);
        SWITCH_CASE_RESULT_MACRO(VIDEO_ERROR); 
        SWITCH_CASE_RESULT_MACRO(AUDIO_ERROR); 
        SWITCH_CASE_RESULT_MACRO(FSAL_ERROR);  
        SWITCH_CASE_RESULT_MACRO(MP4_PRODUCER_ERROR);
        SWITCH_CASE_RESULT_MACRO(MP4_SAMPLEDATA_ERROR);     /* 30 */
        SWITCH_CASE_RESULT_MACRO(MP4_NO_VIDEO_TRACK);  
        SWITCH_CASE_RESULT_MACRO(MP4_NO_AUDIO_TRACK);  
        SWITCH_CASE_RESULT_MACRO(ID_MISMATCH);
        SWITCH_CASE_RESULT_MACRO(ID_EXIST);
        SWITCH_CASE_RESULT_MACRO(TRAINING_CONTINUE);
        SWITCH_CASE_RESULT_MACRO(NO_SOUND);
        SWITCH_CASE_RESULT_MACRO(TOO_SIMILAR);
        SWITCH_CASE_RESULT_MACRO(TOO_DIFFERENT);
        SWITCH_CASE_RESULT_MACRO(NO_MATCH);
        SWITCH_CASE_RESULT_MACRO(SPEAK_TOO_LONG);        
        SWITCH_CASE_RESULT_MACRO(SPEAK_TOO_SHORT);          /* 40 */
        SWITCH_CASE_RESULT_MACRO(AUDIO_END);
        SWITCH_CASE_RESULT_MACRO(VIDEO_END);
        SWITCH_CASE_RESULT_MACRO(VIDEO_IMAGE_TOO_LARGE);
        SWITCH_CASE_RESULT_MACRO(VIDEO_FILE_TOO_LARGE);
        SWITCH_CASE_RESULT_MACRO(VIDEO_FRAME_RATE_TOO_HIGH);
        SWITCH_CASE_RESULT_MACRO(VIDEO_SEEK_PARTIAL_DONE);
        SWITCH_CASE_RESULT_MACRO(VRSI_OK);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_UNINITIALIZED);   
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_BUSY);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_MEM_INSUFFICIENT);  /* 50 */
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_DATA_ERROR);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_LIBRARY_CORRUPT);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_BAD_GRAMMAR);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_LANG_NOT_SUPPORT);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_NO_MATCH_TAG);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_TTS_TOO_LONG);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_SESSION);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_NO_SOUND);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_CMD_TRN_FAIL);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_CMD_RCG_FAIL);    /* 60 */
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_DGT_RCG_FAIL);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_DGT_ADP_FAIL);
        SWITCH_CASE_RESULT_MACRO(VRSI_ERR_UNKNOWN);
        SWITCH_CASE_RESULT_MACRO(STOP_FM_RECORD);
        SWITCH_CASE_RESULT_MACRO(UNSUPPORTED_SPEED);        
        SWITCH_CASE_RESULT_MACRO(A2DP_CLOSE);              
        SWITCH_CASE_RESULT_MACRO(A2DP_DISCOVER_SEP_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_GET_SEP_CAP_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_NO_MATCH_CAP);        /* 70 */
        SWITCH_CASE_RESULT_MACRO(A2DP_CONFIG_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_RECONFIG_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_OPEN_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_START_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(A2DP_PAUSE_STREAM_FAIL);
        SWITCH_CASE_RESULT_MACRO(HFP_CLOSE);
        SWITCH_CASE_RESULT_MACRO(IMG_DECODE_TIME_OUT);
        SWITCH_CASE_RESULT_MACRO(ROOT_DIR_FULL);
        SWITCH_CASE_RESULT_MACRO(BR_IMAGE_ERROR);           
        SWITCH_CASE_RESULT_MACRO(BR_MODULE_ERROR);          /* 80 */
        SWITCH_CASE_RESULT_MACRO(BR_OUT_OF_MEMORY);
        SWITCH_CASE_RESULT_MACRO(BR_OVER_VERSION);
        SWITCH_CASE_RESULT_MACRO(PDL_AUDIO_UNDERFLOW);      
        SWITCH_CASE_RESULT_MACRO(PDL_VIDEO_UNDERFLOW);
        SWITCH_CASE_RESULT_MACRO(STREAM_BEARER_DISCONNECTED);   /* 85 */
        SWITCH_CASE_RESULT_MACRO(STREAM_INVALID_SDP);          
        SWITCH_CASE_RESULT_MACRO(STREAM_RTSP_SET_CHANNEL_FAIL);
        SWITCH_CASE_RESULT_MACRO(STREAM_RTSP_REQUEST_FAIL);
        SWITCH_CASE_RESULT_MACRO(STREAM_PLAY_FINISH);        
        SWITCH_CASE_RESULT_MACRO(STREAM_BUFFER_UNDERFLOW);      /* 90 */
        SWITCH_CASE_RESULT_MACRO(STREAM_BUFFER_OVERFLOW);
        SWITCH_CASE_RESULT_MACRO(STREAM_INVALID_RESOLUTION);  
        SWITCH_CASE_RESULT_MACRO(STREAM_STOP_TIMEOUT);        
        SWITCH_CASE_RESULT_MACRO(VDOEDT_ENCODE_FAIL);       
        SWITCH_CASE_RESULT_MACRO(DECODER_NOT_SUPPORT);      
        SWITCH_CASE_RESULT_MACRO(REACH_STOP_TIME);          
        default:
            kal_trace(TRACE_GROUP_4, MED_TRC_RES_UNKNOWN_ENUM, result, line);
            break;
    }
}  
#if defined(__SW_JPEG_CODEC_SUPPORT__)   
/*****************************************************************************
 * FUNCTION
 *  med_get_med_int_stack_mem
 * DESCRIPTION
 *  print result to trace
 * PARAMETERS
 *  result        [IN]      result  
 * RETURNS
 *  void 
 *****************************************************************************/
void med_get_med_int_stack_mem(kal_uint32* address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    kal_take_mutex(med_stack_mem_mutex);
    *address = (kal_uint32)med_context_p->int_stack_mem_p;
}

/*****************************************************************************
 * FUNCTION
 *  med_free_med_int_stack_mem
 * DESCRIPTION
 *  print result to trace
 * PARAMETERS
 *  result        [IN]      result  
 * RETURNS
 *  void 
 *****************************************************************************/
void med_free_med_int_stack_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_give_mutex(med_stack_mem_mutex);
}
#endif /* defined(__SW_JPEG_CODEC_SUPPORT__)*/


#endif /* MED_NOT_PRESENT */ 

