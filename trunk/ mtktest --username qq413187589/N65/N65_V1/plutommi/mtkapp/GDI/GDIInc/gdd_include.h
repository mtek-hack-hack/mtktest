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
 *  gdd_main.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI DAEMIN Entry.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
* $ Log $
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDD_INCLUDE_H_
#define _GDD_INCLUDE_H_

#define GDD_MAX_MSG_HANDLER 10

typedef enum
{
    GDD_TIMER_IMAGE_CODEC_TIMEOUT,
    GDD_TIMER_MAX_NUM
} gdd_timer_enum;


typedef enum
{
    GDD_EVENT_WAIT_DECODING = 1,
    GDD_EVENT_DUMMY
} gdd_event_enum;

typedef void (*gdd_msg_handler_func)(ilm_struct *ilm);

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void *arg;
} gdd_timer_table_struct;

typedef struct
{
    stack_timer_struct      base_timer;
    event_scheduler         *event_scheduler_ptr;
    kal_eventgrpid          event;
    gdd_timer_table_struct  timer_table[GDD_TIMER_MAX_NUM];
    msg_type                msg_handler_id[GDD_MAX_MSG_HANDLER];
    gdd_msg_handler_func    msg_handler[GDD_MAX_MSG_HANDLER];
    U32                     msg_count;
} gdd_context_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 header;
} gdd_img_codec_event_ind_struct;


extern gdd_context_struct gdd_context;

#define GDD_WAIT_EVENT(EVENT) do{\
                                 kal_uint32 event;\
                                 kal_retrieve_eg_events(gdd_context.event, EVENT,\
                                 KAL_OR_CONSUME, &event, KAL_SUSPEND);\
                                 }while(0)

#define GDD_SET_EVENT(EVENT) do{\
                              kal_set_eg_events(gdd_context.event, (EVENT),KAL_OR);\
                              } while(0)


extern void gdd_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void gdd_stop_timer(kal_uint8 timer_id);
extern void gdd_send_img_codec_ind(void* data,U32 size);
extern kal_bool gdd_register_msg_handler(msg_type msg,gdd_msg_handler_func func);
#endif /* _GDD_INCLUDE_H_ */ 


