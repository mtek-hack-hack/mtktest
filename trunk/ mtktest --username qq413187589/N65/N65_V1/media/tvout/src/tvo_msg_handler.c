/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2003
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   tvo_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of tvout module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MED_NOT_PRESENT

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
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_smalloc.h"
#include "tvo_main.h"
#include "aud_main.h"
#include "fat_fs.h"

#ifdef __TVO_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_TVO_MOD__
#include "tv_out.h"
#include "tvo_main.h"

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  tvo_tv_detect_check
 * DESCRIPTION
 *  This function is to check the tv state.
 * PARAMETERS
 *  arg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_tv_detect_check(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tvo_context_p->state)
    {
        case TVO_READY:
            tvo_context_p->tv_connected = tv_set_detection();
            TVO_VALUE_TRACE(tvo_context_p->tv_connected, tvo_context_p->state, __LINE__);
            /* start a timer to periodically check TV connect status */
            if (!tvo_context_p->tv_connected)
            {
                med_start_timer(TVO_CONNECT_POLLING_TIMER, TVO_TV_DETECT_PERIOD, tvo_tv_detect_check, 0);
            }
            break;
        case TVO_UPDATE:
            tvo_context_p->tv_connected = tv_set_detection();
            TVO_VALUE_TRACE(tvo_context_p->tv_connected, tvo_context_p->state, __LINE__);
            /* start a timer to periodically check TV connect status */
            if (!tvo_context_p->tv_connected)
            {
                med_start_timer(TVO_CONNECT_POLLING_TIMER, TVO_TV_DETECT_PERIOD, tvo_tv_detect_check, 0);
            }
            else
            {
                enable_tv_output(KAL_TRUE);
                aud_set_tv_out_aud_path(KAL_TRUE);
            }

            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  tvo_av_cable_detect_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the av cable detected indication.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_av_cable_detect_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_av_cable_detect_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_tvo_av_cable_detect_ind_struct*) ilm_ptr->local_para_ptr;

    if (ind_p->result == 1) /* plug-in */
    {
        switch (tvo_context_p->state)
        {
            case TVO_IDLE:
            {
                init_tv();

                tvo_context_p->tv_connected = tv_set_detection();
                TVO_VALUE_TRACE(tvo_context_p->tv_connected, tvo_context_p->state, __LINE__);
                /* send message to inform MMI that TV is connected */
                tvo_send_tv_connect_ind(KAL_TRUE);
                /* start a timer to periodically check TV connect status */
                if (!tvo_context_p->tv_connected)
                {
                    med_start_timer(TVO_CONNECT_POLLING_TIMER, TVO_TV_DETECT_PERIOD, tvo_tv_detect_check, 0);
                }
                TVO_ENTER_STATE(TVO_READY);
                aud_set_tv_out_aud_path(KAL_TRUE);
                break;
            }
            default:
                break;
        }
    }
    else    /* plug-out */
    {
        switch (tvo_context_p->state)
        {
            case TVO_READY:
            {
                deinit_tv();
                med_stop_timer(TVO_CONNECT_POLLING_TIMER);
                /* send message to inform MMI that TV is disconnected */
                tvo_send_tv_connect_ind(KAL_FALSE);
                TVO_ENTER_STATE(TVO_IDLE);
                aud_set_tv_out_aud_path(KAL_FALSE);
                break;
            }
            case TVO_UPDATE:
            {
                deinit_tv();
                med_stop_timer(TVO_CONNECT_POLLING_TIMER);
                /* send message to inform MMI that TV is disconnected */
                tvo_send_tv_connect_ind(KAL_FALSE);
                TVO_ENTER_STATE(TVO_IDLE);
                aud_set_tv_out_aud_path(KAL_FALSE);
                break;
            }
            default:
                break;
        }
        tvo_context_p->tv_connected = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  tvo_start_req_hdlr
 * DESCRIPTION
 *  This function is to start tv output.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_start_req_struct *req_p;
    tv_output_para_struct tv_para;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_tvo_start_req_struct*) ilm_ptr->local_para_ptr;

    tvo_context_p->src_mod = ilm_ptr->src_mod_id;

    tvo_context_p->tv_output_mode = req_p->tv_output_mode;
    tvo_context_p->tv_output_format = req_p->tv_output_format;
    tvo_context_p->tv_output_width = req_p->tv_output_width;
    tvo_context_p->tv_output_height = req_p->tv_output_height;
    switch (tvo_context_p->state)
    {
        case TVO_IDLE:
            result = MED_RES_BUSY;
            break;
        case TVO_READY:
        {
            init_tv();

            tv_para.tv_output_mode = tvo_context_p->tv_output_mode;
            tv_para.tv_output_format = tvo_context_p->tv_output_format;
            tv_para.tv_output_offset_x = 30;
            tv_para.tv_output_offset_y = 21;
            set_tv_output_mode(&tv_para);
            if (tvo_context_p->tv_output_mode == MED_TV_OUT_MODE2 || tvo_context_p->tv_output_mode == MED_TV_OUT_MODE3)
            {
                tvo_context_p->tv_output_buffer_size =
                    (tvo_context_p->tv_output_width * tvo_context_p->tv_output_height * 3) >> 1;
                set_tv_output_data_format(TV_DATA_YUV420);
                set_tv_src_size(TV_OUT_OWNER_MMI, tvo_context_p->tv_output_width, tvo_context_p->tv_output_height);
            }
            else
            {
                tvo_context_p->tv_output_buffer_size =
                    (tvo_context_p->tv_output_width * tvo_context_p->tv_output_height * 2);
                set_tv_output_data_format(TV_DATA_RGB565);
                set_tv_src_size(TV_OUT_OWNER_MMI, tvo_context_p->tv_output_width, tvo_context_p->tv_output_height);
            }
        #if (!defined(MT6228_EVB) && !defined(MT6229_EVB))
            if (tvo_context_p->tv_connected)
        #endif 
            {
                enable_tv_output(KAL_TRUE);
                aud_set_tv_out_aud_path(KAL_TRUE);
            }
            tvo_context_p->tv_output = KAL_TRUE;
            TVO_ENTER_STATE(TVO_UPDATE);
            result = MED_RES_OK;
            break;
        }
        default:
            result = MED_RES_BUSY;
            break;
    }
    tvo_set_result(result);
    TVO_SET_EVENT(TVO_EVT_START);

}


/*****************************************************************************
 * FUNCTION
 *  tvo_stop_req_hdlr
 * DESCRIPTION
 *  This function is to stop tv output.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tvo_context_p->src_mod = ilm_ptr->src_mod_id;

    switch (tvo_context_p->state)
    {
        case TVO_READY:
        {
            tvo_context_p->tv_output = KAL_FALSE;
            TVO_ENTER_STATE(TVO_IDLE);
            break;
        }
        case TVO_UPDATE:
        {
            enable_tv_output(KAL_FALSE);
            aud_set_tv_out_aud_path(KAL_FALSE);            
            tvo_context_p->tv_output = KAL_FALSE;
            TVO_ENTER_STATE(TVO_READY);
            break;
        }
        default:
            break;
    }

    TVO_SET_EVENT(TVO_EVT_STOP);

}


/*****************************************************************************
 * FUNCTION
 *  tvo_set_mode_req_hdlr
 * DESCRIPTION
 *  This function is to set tv output mode.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_set_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_set_mode_req_struct *req_p;
    tv_output_para_struct tv_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_tvo_set_mode_req_struct*) ilm_ptr->local_para_ptr;

    tvo_context_p->src_mod = ilm_ptr->src_mod_id;

    tvo_context_p->tv_output_mode = req_p->tv_output_mode;
    tvo_context_p->tv_output_format = req_p->tv_output_format;
    tvo_context_p->tv_output_width = req_p->tv_output_width;
    tvo_context_p->tv_output_height = req_p->tv_output_height;
    if (tvo_context_p->tv_vertical_fileter != req_p->tv_output_vertical_filter)
    {
        tvo_context_p->tv_vertical_fileter = req_p->tv_output_vertical_filter;
        enable_tv_vertical_interpolation(tvo_context_p->tv_vertical_fileter);
    }

    tv_para.tv_output_mode = tvo_context_p->tv_output_mode;
    tv_para.tv_output_format = tvo_context_p->tv_output_format;
    tv_para.tv_output_offset_x = 30;
    tv_para.tv_output_offset_y = 21;
    set_tv_output_mode(&tv_para);
    if (tvo_context_p->tv_output_mode == MED_TV_OUT_MODE2 || tvo_context_p->tv_output_mode == MED_TV_OUT_MODE3)
    {
        tvo_context_p->tv_output_buffer_size =
            (tvo_context_p->tv_output_width * tvo_context_p->tv_output_height * 3) >> 1;
        set_tv_output_data_format(TV_DATA_YUV420);
        set_tv_src_size(TV_OUT_OWNER_MMI, tvo_context_p->tv_output_width, tvo_context_p->tv_output_height);
    }
    else
    {
        tvo_context_p->tv_output_buffer_size = (tvo_context_p->tv_output_width * tvo_context_p->tv_output_height * 2);
        set_tv_output_data_format(TV_DATA_RGB565);
        set_tv_src_size(TV_OUT_OWNER_MMI, tvo_context_p->tv_output_width, tvo_context_p->tv_output_height);
    }

    TVO_SET_EVENT(TVO_EVT_SET_MODE);

}


/*****************************************************************************
 * FUNCTION
 *  tvo_set_param_req_hdlr
 * DESCRIPTION
 *  This function is to set tv out parameters.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void tvo_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_tvo_set_param_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_tvo_set_param_req_struct*) ilm_ptr->local_para_ptr;

    tvo_context_p->src_mod = ilm_ptr->src_mod_id;

    switch (req_p->type)
    {
       case MED_TV_PARAM_Y_COMP:
       case MED_TV_PARAM_U_COMP:
       case MED_TV_PARAM_V_COMP:
       {
          set_tv_parameter(req_p->type, req_p->para);
       }
       break;

       case MED_TV_PARAM_AUD_PATH:
       {
            /* set audio path */
            if (req_p->para == MED_TV_PARAM_AUD_PATH_BOTH)
            {
                aud_set_tv_out_param(KAL_TRUE);
            }
            else if (req_p->para == MED_TV_PARAM_AUD_PATH_TV)
            {
                aud_set_tv_out_param(KAL_FALSE);
            }
       }
       break;
    }     

}

#endif /* __MED_TVO_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

