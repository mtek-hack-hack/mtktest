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
 * gdc_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is entry point of GDI Command Executor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* KAL - RTOS Abstraction Layer */
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

#include "stack_config.h"
#include "task_main_func.h"
#include "stack_timer.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stack_init.h"
#include "stacklib.h"
#include "event_shed.h"

#include "gdi_internal.h"
#include "gdc_include.h"

#include "ucs2prot.h"
#include "eventsgprot.h"

#ifdef __MMI_TVOUT__
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif

extern kal_taskid kal_get_current_thread_ID(void);

typedef struct gdc_job_struct
{
    gdc_job_flag_enum   flag;
    U32                 serial;
    
    gdi_image_src_enum  src_type;
    U8*                 img_src; /* file_handle or point to data */
    U16                 img_filename[FS_MAX_PATH];
    S32                 img_size;
    U8                  img_type;
    U8                  img_flag;/* used for image codec */
    U32                 frame_pos;
    gdi_handle          layer_handle;/* output layer*/
    gdi_handle          lcd_handle;  /* output lcd*/ 
    gdi_handle          anim_handle; /* remember anim handler */
    S32                 x,y;
    S32                 width,height; /* output size , or 0 = original size */
    S32                 clipx1,clipy1,clipx2,clipy2;
    S32                 anim_count;

    void                (*before_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*after_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*last_frame)(GDI_RESULT result);
    void                (*done)(GDI_RESULT result,gdi_handle handle);
} gdc_job_struct;

struct
{
    kal_eventgrpid  job_event;

    U32 current_serial;
    kal_mutexid mutex;
    
    gdc_job_struct job[GDC_MAX_JOB];
    U32 job_sum;
    
    /* predefine parameters */
    gdc_job_flag_enum   job_flag;
    S32                 anim_count;
    void                (*before_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*after_draw)(GDI_RESULT result,gdi_handle handle);
    void                (*last_frame)(GDI_RESULT result);
    void                (*done)(GDI_RESULT result,gdi_handle handle);
    
} gdc_context;
kal_taskid gdc_thread_id;

typedef void (*GDC_CALLBACK_FUNC)(GDI_RESULT result,gdi_handle handle);
typedef struct
{
    LOCAL_PARA_HDR
    GDC_CALLBACK_FUNC callback;
    GDI_RESULT result;
    gdi_handle handle;
} gdc_msg_dispatch_struct;

#define WAIT_JOB_EVENT()    do{\
                                kal_uint32 event;\
                                kal_retrieve_eg_events(gdc_context.job_event, 1,KAL_OR_CONSUME, &event, KAL_SUSPEND);\
                            } while(0)

#define SET_JOB_EVENT()     do{\
                                kal_set_eg_events(gdc_context.job_event, 1,KAL_OR);\
                            } while(0)


/*****************************************************************************
 * FUNCTION
 *  gdc_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool gdc_init(task_indx_type task_indx)
{
    memset(&gdc_context,0,sizeof(gdc_context));
    gdc_context.anim_count = -1;
    
    gdc_context.mutex = kal_create_mutex("GDC");
	gdc_context.job_event = kal_create_event_group("gdc job");
   
    return KAL_TRUE;
}   /* end of gdc_reset */

/*****************************************************************************
 * FUNCTION
 *  gdc_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool gdc_reset(task_indx_type task_indx)
{
    return KAL_TRUE;
}   /* end of gdc_reset */


gdc_job_struct *gdc_job_get_by_flag(gdc_job_flag_enum flag,gdc_job_flag_enum flag_check_value)
{
    int i;
    gdc_job_struct *job = NULL;
    
    if(gdc_context.job_sum || flag_check_value == 0)
    for(i=0;i<GDC_MAX_JOB;i++)
        if((gdc_context.job[i].flag & flag) == flag_check_value)
        {
            job = &(gdc_context.job[i]);
            break;
        }
        
    return job;
}
gdc_job_struct *gdc_job_get_by_serial(U32 serial)
{
    int i;
    gdc_job_struct *job = NULL;

    if(gdc_context.job_sum)
    for(i=0;i<GDC_MAX_JOB;i++)
        if(gdc_context.job[i].serial == serial)
        {
            job = &(gdc_context.job[i]);
            break;
        }
        
    return job;
}

/*****************************************************************************
 * FUNCTION
 *  gdc_job_set_parameter
 * DESCRIPTION
 *
 *****************************************************************************/
void gdc_job_set_parameter(
                            gdc_job_flag_enum job_flag,
                            S32 anim_count,
                            void (*before_draw)(GDI_RESULT result,gdi_handle handle),
                            void (*after_draw)(GDI_RESULT result,gdi_handle handle),
                            void (*last_frame)(GDI_RESULT result),
                            void (*done)(GDI_RESULT result,gdi_handle handle))
{
    GDI_ENTER_CRITICAL_SECTION(gdc_job_set_parameter);
    gdc_context.job_flag        |= job_flag;
    if(anim_count >0 )  gdc_context.anim_count      = anim_count;
    if(before_draw)     gdc_context.before_draw     = before_draw;
    if(after_draw)      gdc_context.after_draw      = after_draw;
    if(last_frame)      gdc_context.last_frame      = last_frame;
    if(done)            gdc_context.done            = done;
    GDI_EXIT_CRITICAL_SECTION(gdc_job_set_parameter);
}

/*****************************************************************************
 * FUNCTION
 *  gdc_image_codec
 * DESCRIPTION
 *
 *****************************************************************************/
GDI_RESULT gdc_job_add_image(
                            gdi_image_src_enum src_type,
                            U8 *img_src,
                            U8 img_type,
                            S32 img_size,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            U32 img_flag,
                            U32 frame_pos,
                            gdc_job_flag_enum job_flag,
                            gdi_handle *job_handle)
{
    GDI_ENTER_CRITICAL_SECTION(gdc_job_add_image)
	{
        GDI_RESULT ret= GDI_FAILED;
        gdc_job_struct *job;
            
        if(job_handle)  *job_handle = 0;

        do
        {
            // filename is large than FS_MAX_PATH chars
            if(src_type == GDI_IMAGE_SRC_FROM_FILE && mmi_ucs2strlen((S8*) img_src) > FS_MAX_PATH-1)
                break;
            
            job = gdc_job_get_by_flag(GDC_JOB_IS_USED,0);
            if(job==NULL) 
				break; // no free job item can be insert

            memset(job,0,sizeof(gdc_job_struct));

            // generate non-zero serial number
            gdc_context.current_serial++; 
            if(gdc_context.current_serial==0) gdc_context.current_serial++;
            
            job->serial         = gdc_context.current_serial;
            job->src_type       = src_type;

            if(src_type == GDI_IMAGE_SRC_FROM_FILE)
            {
                job->img_src    = (U8*)job->img_filename;
                mmi_ucs2ncpy((S8*)job->img_src,(S8*)img_src,FS_MAX_PATH-1);
            }
            else
            {
                job->img_src    = img_src;
            }
            job->img_size       = img_size;
            job->img_type       = img_type;
            job->img_flag       = img_flag;
            job->frame_pos      = frame_pos;
            job->x              = x;
            job->y              = y;
            job->width          = w;
            job->height         = h;
            job->clipx1         = gdi_act_layer->clipx1;
            job->clipy1         = gdi_act_layer->clipy1;
            job->clipx2         = gdi_act_layer->clipx2;
            job->clipy2         = gdi_act_layer->clipy2;
            job->anim_count     = gdc_context.anim_count;
            gdi_lcd_get_active(&job->lcd_handle);
            gdi_layer_get_active(&job->layer_handle);

            job->flag           = gdc_context.job_flag | job_flag | GDC_JOB_IS_USED;
            gdc_context.job_sum++;
            
            job->before_draw    = gdc_context.before_draw;
            job->after_draw     = gdc_context.after_draw;
            job->last_frame     = gdc_context.last_frame;
            job->done           = gdc_context.done;

            ret = GDI_SUCCEED;
            
            if(job_handle)  *job_handle = gdc_context.current_serial;

            SET_JOB_EVENT();
        }while(0);

        gdc_context.job_flag    = 0;
        gdc_context.before_draw = NULL;
        gdc_context.after_draw  = NULL;
        gdc_context.last_frame  = NULL;
        gdc_context.done        = NULL;
        gdc_context.anim_count = -1;

        GDI_RETURN(ret);
	}
    GDI_EXIT_CRITICAL_SECTION(gdc_job_add_image)
}

void gdc_progress_blt_callback(void *arg, S32 x1,S32 y1,S32 x2,S32 y2)
{
    gdc_job_struct *job = (gdc_job_struct*) arg;
    if(job == NULL) return;
    
    if(gdi_fast_mutex_is_owner())
        gdi_lcd_repaint(x1,y1,x2,y2);
    else
        job = NULL;
}

void gdc_process_job(void)
{
    GDI_RESULT ret = GDI_FAILED;
    GDI_ENTER_CRITICAL_SECTION(gdc_process_job)
    do
    {
        gdi_handle old_lcd_handle, old_layer_handle;
        gdc_job_struct *job = gdc_job_get_by_flag(GDC_JOB_IS_USED,GDC_JOB_IS_USED);
        
        if(job==NULL) break; /* no job are waiting */

        // push current LCD , and set to new LCD
        gdi_lcd_get_active(&old_lcd_handle);
        gdi_lcd_set_active(job->lcd_handle);
        
        //push the current layer of the new LCD 
        gdi_layer_get_active(&old_layer_handle);
        #ifdef __MMI_TVOUT__
        if (GDI_LCD->lcd_type == GDI_LCD_TYPE_TVOUT)
            gdi_layer_set_active(mdi_tvout_get_and_dupe_active_layer());
        else
        #endif
            gdi_layer_set_active(job->layer_handle);

        if((job->flag & GDC_JOB_IS_PROGRESS_BLT))
            gdi_image_set_progress_callback(gdc_progress_blt_callback,(void*)job);

        // set the clipping area
        gdi_layer_push_clip();
        gdi_layer_set_clip( job->clipx1,job->clipy1,job->clipx2,job->clipy2);

        if(job->before_draw)
            job->before_draw(GDI_SUCCEED,(gdi_handle) job->serial);
            //gdc_msg_send_callback_req((void*)job->before_draw,GDI_SUCCEED,(gdi_handle)job->serial);
        
        if(job->flag& GDC_JOB_IS_ANIM) // call animate API
        {
            if(job->last_frame)
            {
                gdi_anim_set_last_frame_callback(job->last_frame);
            }
            ret = gdi_anim_codec_draw_internal(
                                job->src_type,
                                job->img_src,job->img_type,job->img_size,
                                job->x,job->y,
                                job->width,job->height,
                                job->img_flag,
                                &job->anim_handle,
                                job->frame_pos,
                                job->anim_count);
            gdi_anim_set_job_handle(job->anim_handle,(gdi_handle)job->serial);
        }
        else// call  image API
        {
            ret = gdi_image_codec_draw(
                                job->src_type,
                                job->img_src,job->img_type,job->img_size,
                                job->x,job->y,
                                job->width,job->height,
                                job->img_flag,
                                job->frame_pos);
        }
        
        if(job->after_draw)
            job->after_draw(ret,(gdi_handle) job->serial);
            //gdc_msg_send_callback_req((void*)job->after_draw,ret,(gdi_handle)job->serial);
        
        // output to lcd if need
        if(ret >= GDI_SUCCEED)
        if((job->flag & GDC_JOB_IS_NO_BLT)==0)
        {
            S32 x1,y1,x2,y2;
            gdi_image_get_update_area(&x1,&y1,&x2,&y2);
            gdi_lcd_repaint(x1,y1,x2,y2);
        }

        gdi_layer_pop_clip(); // restore old clip
        gdi_layer_set_active(old_layer_handle); // restore layer of this new LCD
        gdi_lcd_set_active(old_lcd_handle); // restore to old LCD

        if(ret != GDI_ERR_NB_ABORT) // non-blocking abort should not remove this job.
        {
            job->flag =0;
            gdc_context.job_sum--;

            if(job->done)
                gdc_msg_send_callback_req((void*)job->done,ret,(gdi_handle)job->serial);
        }
    } while(0);
    GDI_EXIT_CRITICAL_SECTION(gdc_process_job)
}
GDI_RESULT gdc_job_del_image(gdi_handle job_handle)
{
    GDI_RESULT ret = GDI_FAILED;
    
    gdi_image_set_abort(TRUE);
    
    GDI_ENTER_CRITICAL_SECTION(gdc_job_del_image)
    if(job_handle)
    {
        gdc_job_struct *item;
        item = gdc_job_get_by_serial((U32)job_handle);
        if(item && (item->flag&GDC_JOB_IS_USED))
        {
            item->flag = 0;
            gdc_context.job_sum--;
            /* we also need to stop animate with this job_handle */
            gdi_anim_stop_by_job_handle((gdi_handle)item->serial);
            
            ret = GDI_SUCCEED;
        }
    }
    gdi_image_set_abort(FALSE);
    GDI_RETURN(ret);
    GDI_EXIT_CRITICAL_SECTION(gdc_job_del_image)
}

GDI_RESULT gdc_job_del_all(void)
{
    gdi_image_set_abort(TRUE);
    
    GDI_ENTER_CRITICAL_SECTION(gdc_job_del_all)
    int i;
    for(i=0;i<GDC_MAX_JOB;i++)
    {
        gdc_context.job[i].flag = 0;
    }
    gdc_context.job_sum=0;
    
    gdi_anim_stop_by_all_job_handle();
    gdi_image_set_abort(FALSE);
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdc_job_del_all)
}

void gdc_msg_dispatch(void *data)
{
    gdc_msg_dispatch_struct *msg = (gdc_msg_dispatch_struct*) data;
    GDI_DEBUG_ASSERT(msg->callback != NULL);
    msg->callback(msg->result,msg->handle);
}

void gdc_msg_send_callback_req(void* callback,GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdc_msg_dispatch_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler((PsFuncPtr) gdc_msg_dispatch, MSG_ID_MMI_GDC_IMG_CODEC_CALLBACK_IND);
    
    ind_p = (gdc_msg_dispatch_struct*)
        construct_local_para((U16)(sizeof(gdc_msg_dispatch_struct)), TD_CTRL);

    ind_p->callback = (GDC_CALLBACK_FUNC)callback;
    ind_p->result = result;
    ind_p->handle = handle;

    ilm_ptr = allocate_ilm(MOD_GDC);
    ilm_ptr->src_mod_id = MOD_GDC;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = GDC_SAP;

    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_GDC_IMG_CODEC_CALLBACK_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  gdc_task_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdc_task_main(task_entry_struct *task_entry_ptr)
{
	kal_uint32 my_index;

	kal_get_my_task_index(&my_index);
    stack_set_active_module_id( my_index, MOD_GDC);
    gdc_thread_id = kal_get_current_thread_ID();
    while (1)
    {
        while(gdc_context.job_sum)
        {
            gdc_process_job();
            kal_sleep_task(100);
        }
        WAIT_JOB_EVENT();        
    }
}
/*****************************************************************************
 * FUNCTION
 *  gdc_create
 * DESCRIPTION
 *
 *****************************************************************************/
kal_bool gdc_create(comptask_handler_struct **handle)
{
    static comptask_handler_struct gdc_handler_info = 
    {
        gdc_task_main, /* task entry function */
        gdc_init,      /* task initialization function */
        NULL,           /* task configuration function */
        gdc_reset,     /* task reset handler */
        NULL,           /* task termination handler */
    };
    *handle = (comptask_handler_struct*) & gdc_handler_info;
    return KAL_TRUE;
}

