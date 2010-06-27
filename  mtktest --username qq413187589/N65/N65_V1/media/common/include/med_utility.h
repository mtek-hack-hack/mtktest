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
 * med_utility.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of utiltiy of media task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _MED_UTILITY_H
#define _MED_UTILITY_H

#define MED_BASE_TIMER_ID 0x0000

/* aud  timer ids on event scheduler */
typedef enum
{
    AUD_TIMER_CRESCENDO = 0,
    CAM_POWER_DOWN_DELAY_TIMER = 1,
    CAM_POWER_UP_TIMER = 2,
    CAM_READY_POLLING_TIMER = 3,
    IMAGE_CODEC_RETRY_TIMER = 4,
    VID_FRAME_TIMER = 5,
    TVO_CONNECT_POLLING_TIMER = 6,
    CAM_BARCODE_DECODE_TIMER = 7,
    VID_PDL_BUFFERING_TIMER = 8,    
    RTP_DTMF_TIMER = 9,
    RTP_SIMU_TIMER = 10,
    RTP_DTMF_TIMEOUT_TIMER = 11,
    STREAM_DL_TIMEOUT_TIMER = 12,    
    STREAM_GET_PLAY_TIME_TIMER = 13,
    STREAM_DUMMY_TIMER = 14,
    VID_STOP_TIME_TIMER = 15,
    CAM_XENON_FLASH_CHECK_TIMER = 16,
    RTP_DATA_TIMEOUT_TIMER = 17,
    VCALL_PEER_VIDEO_TIMER = 18,
    VCALL_DECODE_RECOVER_TIMER = 19,    
    VCALL_IMAGE_UPDATE_TIMER = 20,    
    AUD_BT_SET_PATH_TIMER = 21,
    MAX_NUM_OF_MED_TIMER
}
med_timer_enum;

/* aud timer periods */
#define AUD_TIMER_PERIOD 2000

extern void *med_alloc_int_mem_ext(kal_int32 size,char* file_p, long line_p);
extern void *med_alloc_ext_mem_ext(kal_int32 size,char* file_p, long line_p);
extern void med_free_int_mem_ext(void **pointer,char* file_p, long line_p);
extern void med_free_ext_mem_ext(void **pointer,char* file_p, long line_p);

#define med_alloc_ext_mem(size)\
    med_alloc_ext_mem_ext(size,__FILE__,__LINE__)
#define med_alloc_int_mem(size)\
    med_alloc_int_mem_ext(size,__FILE__,__LINE__)
#define med_free_int_mem(pointer)\
    med_free_int_mem_ext(pointer,__FILE__,__LINE__)
#define med_free_ext_mem(pointer)\
    med_free_ext_mem_ext(pointer,__FILE__,__LINE__)


/*==== Functions =====*/

extern kal_bool med_utility_init(void);
extern kal_int32 med_util_utf8_to_ucs2(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size);
extern kal_int32 med_util_ucs2_to_utf8(kal_uint8 *dest, kal_uint32 dest_size, kal_uint8 *src, kal_uint32 src_size);
extern void med_start_base_timer(void *base_timer_ptr, kal_uint32 time_out);
extern void med_stop_base_timer(void *base_timer_ptr);
extern void med_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void med_stop_timer(kal_uint8 timer_id);
extern kal_int32 med_check_disc_space(kal_wchar *dir_name, kal_int32 free_byte);
extern kal_int16 med_get_media_type(kal_wchar *file_name);
extern kal_bool med_retrieve_file_path(kal_wchar *file_name, kal_wchar *path);
extern kal_bool med_remove_file_name(kal_wchar *file_name);
extern void med_debug_print_result(kal_int32 result, kal_uint32 line);
#if defined(__SW_JPEG_CODEC_SUPPORT__)
extern void med_get_med_int_stack_mem(kal_uint32* address);
extern void med_free_med_int_stack_mem(void);
#endif
/* crc */
extern kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length);

#endif /* _MED_UTILITY_H */ 

#endif /* MED_NOT_PRESENT */ 

