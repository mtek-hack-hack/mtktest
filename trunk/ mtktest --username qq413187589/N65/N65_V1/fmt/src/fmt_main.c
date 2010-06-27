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
 *
 * Filename:
 * ---------
 * fmt_main.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#define FMT_MAIN_C

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

#include "App_features.h"
#include "msdc_def.h"
#include "msdc_lsd.h"
#include "fat_fs.h"
#ifdef __DRM_MTK__
#include "drm_gprot.h"
#include "drm_core_prot.h"
#endif

#include "fmt_def.h"
#include "fmt_main.h"
#include "fmt_struct.h"

#ifdef __OTG_ENABLE__
#include "usb_host_ms_if.h"
#endif 

#if defined(__FOTA_ENABLE__) && defined(__MTK_TARGET__)
#include "fota.h"
#endif /* defined(__FOTA_ENABLE__) && defined(__MTK_TARGET__) */

#if defined(__FS_CARD_SUPPORT__)
#include "msdc_def.h"    
#endif

#ifndef FMT_NOT_PRESENT

static T_MSDC_CARD fmt_msdc_type = UNKNOWN_CARD;
static fmt_msdc_state_enum fmt_msdc_present = FMT_MSDC_STATE_UNINIT;
static kal_bool fmt_need_abort = KAL_FALSE;

#if defined(__FOTA_ENABLE__) && !defined(__MTK_TARGET__)
FS_HANDLE g_fhandle;
#endif /* defined(__FOTA_ENABLE__) && !defined(__MTK_TARGET__) */

#ifdef __FS_CHECKDRIVE_SUPPORT__
#ifdef __MTK_TARGET__
__align(4)
#endif
     static kal_uint8 g_fmt_buffer[FMT_MAX_BUFFER_SIZE];
#endif /* __FS_CHECKDRIVE_SUPPORT__ */ 

     extern fmgr_filter_struct fmgr_filter[];

#ifdef MMS_SUPPORT
     extern int wap_is_init(void);
#endif 


/*****************************************************************************
 * FUNCTION
 *  fmt_create
 * DESCRIPTION
 *  fmt task create function
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
     kal_bool fmt_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct fmt_handler_info = 
    {
        fmt_task_main,  /* task entry function */
        fmt_init,       /* task initialization function */
        NULL,           /* task configuration function */
        fmt_reset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & fmt_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_task_main
 * DESCRIPTION
 *  fmt task main loop
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    fmt_init_drive();

    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        fmt_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmt_init
 * DESCRIPTION
 *  fmt task init handler
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool fmt_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_reset
 * DESCRIPTION
 *  fmt task reset handler
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool fmt_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_init_drive
 * DESCRIPTION
 *  fmt task message dispatcher
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_init_drive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo info;
    kal_uint8 path[10];
    int phone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phone = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    memset(path, 0, 10);

    if (phone >= FS_NO_ERROR)
    {
        kal_wsprintf((WCHAR*) path, "%c:\\", phone);

        FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_FREE_SPACE);
    }
    
#if defined(__FS_CARD_SUPPORT__)
//#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) || defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__) || defined (MILAN_BB)
    fmt_msdc_type = SD_CARD;
#if 0
/* under construction !*/
#endif /* 0 */ 
    {
        int card;

        /* default: fs will mount the card drive */
        fmt_msdc_present = FMT_MSDC_STATE_PLUG_IN;

        card = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if (card >= FS_NO_ERROR)
        {
            memset(path, 0, 10);
            kal_wsprintf((WCHAR*) path, "%c:\\", card);

            FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_FREE_SPACE);
        }
    }
//#endif /* defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) || defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__) || defined (MILAN_BB) */ 
#endif /* __FS_CARD_SUPPORT__ */

#if defined(MT6223P) && defined(__FS_CARD_SUPPORT__)
     /* default for mt6223p: fs will not mount the card drive */
     fmt_msdc_present = FMT_MSDC_STATE_UNINIT;
     
     NotifyFMTWhenCardPresent();
#endif

}


/*****************************************************************************
 * FUNCTION
 *  fmt_main
 * DESCRIPTION
 *  fmt task message dispatcher
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
    #ifdef __OTG_ENABLE__
        case MSG_ID_OTG_MS_INSERT_IND:
            fmt_otg_insert_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_OTG_MS_REMOVE_IND:
            fmt_otg_remove_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_OTG_DISPLAY_IND:
            fmt_otg_display_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_OTG_CARD_DETECT_IND:
            fmt_otg_card_detect_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* __OTG_ENABLE__ */ 

    #ifdef __FS_CARD_SUPPORT__
        case MSG_ID_MSDC_CARD_DETECT_IND:
            fmt_card_detect_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MMI_FMT_UNMOUNT_REQ:
            fmt_unmount_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* __FS_CARD_SUPPORT__ */ 
    #ifdef __FS_MOVE_SUPPORT__
        case MSG_ID_MMI_FMT_COPY_REQ:
            fmt_copy_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* __FS_MOVE_SUPPORT__ */ 
        case MSG_ID_MMI_FMT_FORMAT_REQ:
            fmt_format_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MMI_FMT_FORMAT_RSP:
            fmt_format_done_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #ifdef __FS_CHECKDRIVE_SUPPORT__
        case MSG_ID_MMI_FMT_CHECK_DRIVE_REQ:
            fmt_check_drive_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* __FS_CHECKDRIVE_SUPPORT__ */ 
        case MSG_ID_MMI_FMT_DELETE_REQ:
            fmt_delete_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #ifdef __DRM_MTK__
        case MSG_ID_MMI_FMT_DELETE_RO_REQ:
            fmt_delete_ro_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* __DRM_MTK__ */             
        case MSG_ID_MMI_FMT_GET_MSDC_STATUS_REQ:
            fmt_get_msdc_status_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #ifdef __SIM_PLUS__
        case MSG_ID_SIM_PLUS_DETECT_IND:
            fmt_sim_plus_detect_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif

    #if defined(__FOTA_ENABLE__)
        case MSG_ID_MMI_FMT_FOTA_INIT_REQ:
            fmt_fota_init_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MMI_FMT_FOTA_WRITE_DATA_REQ:
            fmt_fota_write_data_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
        case MSG_ID_MMI_FMT_FOTA_FINALIZE_REQ:
            fmt_fota_finalize_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
            break;
    #endif /* defined(__FOTA_ENABLE__)*/
        default:
            break;
    }
}

#ifdef __OTG_ENABLE__


/*****************************************************************************
 * FUNCTION
 *  fmt_otg_card_detect_hdlr
 * DESCRIPTION
 *  msdc detect message handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_otg_card_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    fmt_mmi_msdc_ind_struct *param_ptr = NULL;
    usb_host_ms_media_struct *ms_ind;
    kal_uint32 *media_array;
    kal_int32 fs_ret;
    kal_uint8 media_size;
    kal_uint8 index;
    kal_int32 result = FS_NO_ERROR;
    kal_uint8 media_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ms_ind = (usb_host_ms_media_struct*) local_para_ptr;
    media_array = (kal_uint32*) & ms_ind->media_array;
    media_size = ms_ind->media_size;

    for (index = 0; index < media_size; index++)
    {
        if (media_array[index] != 0)
        {
            fs_ret = FS_TestMSDC((void*)media_array[index]);
            kal_prompt_trace(MOD_FMT, "fmt call FS_TestMSDC get (%d)\n", fs_ret);
            
            if (fs_ret < FS_NO_ERROR)
            {
                result = fs_ret;
            }
            media_num++;
        }
    }

    //Assert((media_size == 0) && (media_num == 0));

    ilm_ptr = allocate_ilm(MOD_FMT);
    param_ptr = (fmt_mmi_msdc_ind_struct*) construct_local_para(sizeof(fmt_mmi_msdc_ind_struct), TD_CTRL);
    param_ptr->type = SD_CARD;
    param_ptr->cause = fs_ret;

    if (media_num == 1)
    {
        if (fs_ret >= FS_NO_ERROR)
        {
            ilm_ptr->msg_id = MSG_ID_FMT_MMI_CARD_PLUG_IN_IND;
            fmt_msdc_present = FMT_MSDC_STATE_PLUG_IN;
            
        }
        else
        {
            ilm_ptr->msg_id = MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND;
            fmt_msdc_present = FMT_MSDC_STATE_PLUG_OUT;
        }
    }
    else
    {
        /* First allocate a memory for an interlayer message structure */
        if (result == FS_NO_ERROR)
        {
            ilm_ptr->msg_id = MSG_ID_FMT_MMI_CARD_PLUG_IN_IND;
            fmt_msdc_present = FMT_MSDC_STATE_PLUG_IN;
        }
        else
        {
            ilm_ptr->msg_id = MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND;
            fmt_msdc_present = FMT_MSDC_STATE_PLUG_OUT;
        }
    }

    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
}
#endif /* __OTG_ENABLE__ */ 

#ifdef __FS_CARD_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  fmt_card_detect_hdlr
 * DESCRIPTION
 *  msdc detect message handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_card_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_mmi_msdc_ind_struct *param_ptr = NULL;
    msdc_card_detect_ind_struct *msg_ptr;
    ilm_struct *ilm_ptr = NULL;
    kal_int32 fs_ret = FS_NO_ERROR;
    kal_uint32 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* scan queue for multiple detect ind */
    msg_ptr = (msdc_card_detect_ind_struct*) local_para_ptr;

#if defined(MT6223P)
    MSDC_unsealMountOperation();
#endif
    
    fs_ret = FS_TestMSDC((void*)msg_ptr->media_array);
    fmt_msdc_type = SD_CARD;

    /* First allocate a memory for an interlayer message structure */
		
    if (fs_ret == FS_NO_ERROR)
    {
        if (fmt_msdc_present == FMT_MSDC_STATE_PLUG_IN)
        {
            /* Strange !? Plug-in Twice ?! */
            return;
        }
        msg_id = MSG_ID_FMT_MMI_CARD_PLUG_IN_IND;
        fmt_msdc_present = FMT_MSDC_STATE_PLUG_IN;
    }
    else
    {
        if (fmt_msdc_present == FMT_MSDC_STATE_PLUG_OUT)
        {
            /* Already Plug-Out , Early Return */
            return;
        }
        msg_id = MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND;
        fmt_msdc_present = FMT_MSDC_STATE_PLUG_OUT;
    }

#ifdef __J2ME__
    ilm_ptr = allocate_ilm(MOD_FMT);
    param_ptr = (fmt_mmi_msdc_ind_struct *)construct_local_para
                 (sizeof (fmt_mmi_msdc_ind_struct), TD_CTRL);

    param_ptr->type = fmt_msdc_type;
    param_ptr->cause = fs_ret;

    ilm_ptr->msg_id = msg_id;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr =  (local_para_struct *)param_ptr;

    SEND_ILM( MOD_FMT, MOD_JASYN, MMI_L4C_SAP, ilm_ptr);
#endif /* __J2ME__ */ 

    if (fs_ret == FS_NO_ERROR)
    {
        int card;
        kal_uint8 path[10];
        FS_DiskInfo info;

        card = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

        if (card >= FS_NO_ERROR)
        {
            kal_wsprintf((WCHAR*) path, "%c:\\", card);

            FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        }
    }

    kal_prompt_trace(MOD_FMT, "FS return: %d\n", fs_ret);

    ilm_ptr = allocate_ilm(MOD_FMT);
    param_ptr = (fmt_mmi_msdc_ind_struct *)construct_local_para
                  (sizeof (fmt_mmi_msdc_ind_struct), TD_CTRL);

    param_ptr->type = fmt_msdc_type;
    param_ptr->cause = fs_ret;

    ilm_ptr->msg_id = msg_id;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    SEND_ILM( MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_unmount_hdlr
 * DESCRIPTION
 *  unmount request handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_unmount_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_unmount_req_strcut *msg_ptr;
    mmi_fmt_unmount_rsp_strcut *param_ptr;
    ilm_struct *ilm_ptr = NULL;
    kal_int32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_fmt_unmount_req_strcut*) local_para_ptr;

    fs_ret = FS_CloseMSDC(msg_ptr->index, msg_ptr->mode);

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_FMT);

    param_ptr = (mmi_fmt_unmount_rsp_strcut*) construct_local_para(sizeof(mmi_fmt_unmount_rsp_strcut), TD_CTRL);

    param_ptr->result = fs_ret;

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_UNMOUNT_RSP;

    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);

    return;
}

#endif /* __FS_CARD_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  fmt_get_msdc_status_hdlr
 * DESCRIPTION
 *  msdc status request handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_get_msdc_status_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_get_msdc_status_rsp_strcut *param_ptr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_FMT);

    param_ptr = (mmi_fmt_get_msdc_status_rsp_strcut*) construct_local_para
        (sizeof(mmi_fmt_get_msdc_status_rsp_strcut), TD_CTRL);

    param_ptr->present = fmt_msdc_present;
    param_ptr->type = fmt_msdc_type;

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_GET_MSDC_STATUS_RSP;

    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);

    return;
}

#ifdef __FS_MOVE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  fmt_copy_hdlr
 * DESCRIPTION
 *  copy request handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_copy_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_req_strcut *msg_ptr;
    mmi_fmt_copy_rsp_strcut *param_ptr;
    ilm_struct *ilm_ptr = NULL;
    kal_int32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_fmt_copy_req_strcut*) local_para_ptr;
    fmt_need_abort = KAL_FALSE;

    if (msg_ptr->action == FMT_COPY)
    {
        fs_ret = FS_Move((WCHAR*) msg_ptr->src_file, (WCHAR*) msg_ptr->dest_file, FS_MOVE_COPY, fmt_copy_rsp_hdlr, NULL, 0);
    }
    else
    {
        fs_ret = FS_Move((WCHAR*) msg_ptr->src_file, (WCHAR*) msg_ptr->dest_file, FS_MOVE_KILL, fmt_copy_rsp_hdlr, NULL, 0);
    }

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_FMT);

    param_ptr = (mmi_fmt_copy_rsp_strcut*) construct_local_para(sizeof(mmi_fmt_copy_rsp_strcut), TD_CTRL);

    param_ptr->result = fs_ret;

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_COPY_RSP;

    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_copy_rsp_hdlr
 * DESCRIPTION
 *  call back function for FS_Move
 * PARAMETERS
 *  action          [IN]        
 *  total           [IN]        
 *  completed       [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int fmt_copy_rsp_hdlr(int action, UINT total, UINT completed, UINT handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fmt_need_abort == KAL_TRUE)
    {
        if (handle > 0)
        {
            fmt_need_abort = KAL_FALSE;
            FS_Abort(handle);
        }
    }
    else
    {
        /* send message to MMI to show progress */
    }
    return KAL_TRUE;
}
#endif /* __FS_MOVE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  fmt_abort_copy
 * DESCRIPTION
 *  abort copy by MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_abort_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmt_need_abort = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_get_abort_copy
 * DESCRIPTION
 *  abort copy by MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool fmt_get_abort_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return fmt_need_abort;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_format_hdlr
 * DESCRIPTION
 *  format request handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_format_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_format_req_strcut *msg_ptr;
    ilm_struct *ilm_ptr = NULL;
    kal_int32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_fmt_format_req_strcut*) local_para_ptr;

    if (msg_ptr->drive != 0)
    {
    #if (defined (MMS_SUPPORT) && !defined (APP_STORAGE_IN_SYS_DRV))
        kal_int32 ch;

        ch = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        /* not allow format public drive before WAP ready */
        if ((ch != msg_ptr->drive) && wap_is_init() == KAL_TRUE)
        {
            fs_ret = FS_DEVICE_BUSY;
        }
        else
    #endif /* (defined (MMS_SUPPORT) && !defined (APP_STORAGE_IN_SYS_DRV)) */ 
        {
            kal_uint8 drive[20];

            kal_wsprintf((WCHAR*) drive, "\\\\.\\%c:", msg_ptr->drive);
            fs_ret = FS_GeneralFormat((WCHAR*) drive, msg_ptr->level, NULL);
        }
    }
    else
    {
        fs_ret = FS_DRIVE_NOT_FOUND;
    }

#if defined(__FS_CARD_SUPPORT__)
    if (fs_ret  >= FS_NO_ERROR)
    {
        int card;
        kal_uint8 path[10];
        FS_DiskInfo info;

        card = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

        if (card >= FS_NO_ERROR)
        {
            kal_wsprintf((WCHAR*) path, "%c:\\", card);

            FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        }
    }
#endif /* defined(__FS_CARD_SUPPORT__) */

#ifdef WAP_SUPPORT
    if (fs_ret >= FS_NO_ERROR && is_app_present(APP_WAP))
    {
        mmi_fmt_format_req_strcut *param_ptr;

        /* First allocate a memory for an interlayer message structure */
        ilm_ptr = allocate_ilm(MOD_FMT);

        param_ptr = (mmi_fmt_format_req_strcut*) construct_local_para(sizeof(mmi_fmt_format_req_strcut), TD_CTRL);

        param_ptr->drive = msg_ptr->drive;
        param_ptr->level = msg_ptr->level;

        ilm_ptr->msg_id = MSG_ID_MMI_FMT_FORMAT_REQ;

        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

        SEND_ILM(MOD_FMT, MOD_WAP, MMI_L4C_SAP, ilm_ptr);
    }
    else
#endif /* WAP_SUPPORT */ 
    {
        mmi_fmt_format_rsp_strcut *param_ptr;

    #ifdef __IMPS__
        {
            /* Send format response to IMPS. */
            /* First allocate a memory for an interlayer message structure */
            ilm_ptr = allocate_ilm(MOD_FMT);

            param_ptr = (mmi_fmt_format_rsp_strcut*) construct_local_para(sizeof(mmi_fmt_format_rsp_strcut), TD_CTRL);
    
            param_ptr->result = fs_ret;
    
            ilm_ptr->msg_id = MSG_ID_MMI_FMT_FORMAT_RSP;
    
            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;
    
            SEND_ILM(MOD_FMT, MOD_IMPS, MMI_L4C_SAP, ilm_ptr);
        }
    #endif /* __IMPS__ */

        {
            /* First allocate a memory for an interlayer message structure */
            ilm_ptr = allocate_ilm(MOD_FMT);

            param_ptr = (mmi_fmt_format_rsp_strcut*) construct_local_para(sizeof(mmi_fmt_format_rsp_strcut), TD_CTRL);

            param_ptr->result = fs_ret;

            ilm_ptr->msg_id = MSG_ID_MMI_FMT_FORMAT_RSP;

            ilm_ptr->peer_buff_ptr = NULL;
            ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

            SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
        }

    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_format_done_hdlr
 * DESCRIPTION
 *  format done handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_format_done_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_format_rsp_strcut *msg_ptr;
    mmi_fmt_format_rsp_strcut *param_ptr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_fmt_format_rsp_strcut*) local_para_ptr;

#ifdef __IMPS__
    {
        /* Send format response to IMPS. */
        /* First allocate a memory for an interlayer message structure */
        ilm_ptr = allocate_ilm(MOD_FMT);

        param_ptr = (mmi_fmt_format_rsp_strcut*) construct_local_para(sizeof(mmi_fmt_format_rsp_strcut), TD_CTRL);

        param_ptr->result = msg_ptr->result;

        ilm_ptr->msg_id = MSG_ID_MMI_FMT_FORMAT_RSP;

        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

        SEND_ILM(MOD_FMT, MOD_IMPS, MMI_L4C_SAP, ilm_ptr);
    }
#endif /* __IMPS__ */

    {
        /* First allocate a memory for an interlayer message structure */
        ilm_ptr = allocate_ilm(MOD_FMT);

        param_ptr = (mmi_fmt_format_rsp_strcut*) construct_local_para(sizeof(mmi_fmt_format_rsp_strcut), TD_CTRL);

        param_ptr->result = msg_ptr->result;

        ilm_ptr->msg_id = MSG_ID_MMI_FMT_FORMAT_RSP;

        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

        SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
    }


    return;
}

#ifdef __FS_CHECKDRIVE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  fmt_check_drive_hdlr
 * DESCRIPTION
 *  check drive request handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_check_drive_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_check_drive_req_strcut *msg_ptr;
    mmi_fmt_check_drive_rsp_strcut *param_ptr;
    ilm_struct *ilm_ptr = NULL;
    kal_int32 fs_ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_fmt_check_drive_req_strcut*) local_para_ptr;

    if (msg_ptr->drive != 0)
    {
        //#ifdef APPMEM_SUPPORT 
        //kal_uint8 *buffer;
        /*kal_int32 len;

        len = FS_GetCheckBufferSize(msg_ptr->drive);
        if (len > FMT_MAX_BUFFER_SIZE)
        {
            len = FMT_MAX_BUFFER_SIZE;
        }*/
        /* buffer = kal_app_mem_alloc(len, KAL_APPMEM_FUNC, MOD_FMT);
           if (buffer == NULL)
           fs_ret = FS_FAIL_GET_MEM;
           else */
        {
            fs_ret = FS_CheckDrive(msg_ptr->drive, g_fmt_buffer, FMT_MAX_BUFFER_SIZE);
            /* kal_app_mem_free (buffer); */
        }
        // #endif
    }
    else
    {
        fs_ret = FS_DRIVE_NOT_FOUND;
    }

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_FMT);

    param_ptr = (mmi_fmt_check_drive_rsp_strcut*) construct_local_para
        (sizeof(mmi_fmt_check_drive_rsp_strcut), TD_CTRL);

    param_ptr->result = fs_ret;

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_CHECK_DRIVE_RSP;

    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);

    return;
}
#endif /* __FS_CHECKDRIVE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  fmt_delete_hdlr
 * DESCRIPTION
 *  delete request handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_delete_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_delete_req_strcut *msg_ptr;
    mmi_fmt_delete_rsp_strcut *param_ptr;
    ilm_struct *ilm_ptr = NULL;
    kal_int32 fs_ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (mmi_fmt_delete_req_strcut*) local_para_ptr;

    if (msg_ptr->type == FS_RECURSIVE_TYPE)
    {
        fs_ret = FS_XDelete((WCHAR*) msg_ptr->path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    }
    else if (msg_ptr->type == FS_DIR_TYPE)
    {
        if (FMGR_FILTER_IS_SET(((FMGR_FILTER*) (msg_ptr->filter)), FMGR_TYPE_ALL))
        {
            fs_ret = FS_XDelete((WCHAR*) msg_ptr->path, FS_FILE_TYPE, NULL, 0);
        }
        else
        {
            fs_ret = fmt_delete_by_filter_hdlr(msg_ptr->path, (FMGR_FILTER*) msg_ptr->filter);
        }
    }
    else if (msg_ptr->type == FS_FILE_TYPE)
    {
        fs_ret = FS_Delete((WCHAR*) msg_ptr->path);
    }

    fmt_need_abort = KAL_FALSE;
    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_FMT);

    param_ptr = (mmi_fmt_delete_rsp_strcut*) construct_local_para(sizeof(mmi_fmt_delete_rsp_strcut), TD_CTRL);

    param_ptr->result = fs_ret;

    param_ptr->callback = msg_ptr->callback;

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_DELETE_RSP;

    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_delete_by_filter_hdlr
 * DESCRIPTION
 *  delete file according to filter
 * PARAMETERS
 *  path            [?]     
 *  filter_mask     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 fmt_delete_by_filter_hdlr(kal_uint8 *path, FMGR_FILTER *filter_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    FS_DOSDirEntry file_info;
    kal_uint8 file_name[40];
    kal_int32 fs_ret;
    kal_uint8 i;
    kal_bool file_read_only = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcat((WCHAR*) path, (WCHAR*) L"*.*");
    handle = FS_FindFirst((WCHAR*) path, 0, 0, &file_info, (WCHAR*) file_name, 40);
    if (handle < 0)
    {
        return FS_NO_ERROR;
    }

    mmi_fmgr_remove_last_dir((kal_char*) path);

    fs_ret = FS_SetCurrentDir((WCHAR*) path);
    if (fs_ret < 0)
    {
        FS_FindClose(handle);
        return fs_ret;
    }

    while (1)
    {
        for (i = 0; i < FMGR_MAX_FILTER_COUNT; i++)
        {
            if (FMGR_FILTER_IS_SET(filter_mask, fmgr_filter[i].type))
            {
                if ( (strncmp((char*)file_info.Extension, (char*)fmgr_filter[i].ext, 3) == 0) ||
                	    ((strlen((char*)fmgr_filter[i].ext) == 2) && 
                	     (strncmp((char*)file_info.Extension, (char*)fmgr_filter[i].ext, 2) == 0 )))
                {
                    fs_ret = FS_Delete((WCHAR*) file_name);
                    if (fs_ret != FS_READ_ONLY_ERROR)
                    {
                        if (fs_ret < 0)
                        {
                            kal_wstrncpy((kal_wchar*)file_name, (kal_wchar*)path, 3);
                            FS_SetCurrentDir((kal_wchar*)file_name);
                            FS_FindClose(handle);
                            return fs_ret;
                        }
                    }
                    else
                    {
                        file_read_only = KAL_TRUE;
                    }
                    break;
                }
            }
        }

        fs_ret = FS_FindNext(handle, &file_info, (WCHAR*) file_name, 40);
        if (fs_ret < 0 || fmt_need_abort == KAL_TRUE)
        {
            break;
        }
    }

    FS_FindClose(handle);

    kal_wstrncpy((kal_wchar*)file_name, (kal_wchar*)path, 3);
    FS_SetCurrentDir((kal_wchar*)file_name);

    if (file_read_only == KAL_TRUE)
    {
        return FS_READ_ONLY_ERROR;
    }
    else
    {
        return FS_NO_ERROR;
    }
}

#ifdef __DRM_MTK__
/*****************************************************************************
 * FUNCTION
 *  fmt_delete_ro_hdlr
 * DESCRIPTION
 *  delete file according to filter
 * PARAMETERS
 *  path            [?]     
 *  filter_mask     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_delete_ro_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_delete_rsp_strcut *param_ptr;
    ilm_struct *ilm_ptr = NULL;   
    drm_rights_struct rights;
    FS_HANDLE handle, fh;
    FS_DOSDirEntry file_info;    
    kal_uint8 file_name[40];
    kal_int32 fs_ret;
    kal_uint32 len;
    kal_uint8 permission;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = FS_FindFirst((WCHAR*) L"Z:\\@DRM_ro\\*.*", 0, 0, &file_info, (WCHAR*) file_name, 40);
    if (handle < 0)
    {
        fs_ret = handle;
    }
    else
    {
        fs_ret = FS_SetCurrentDir((WCHAR*) L"Z:\\@DRM_ro\\");
        if (fs_ret >= 0)
        {
            while (1)
            {
                fh = FS_Open((WCHAR*) file_name, FS_READ_WRITE);
                if (fh >= FS_NO_ERROR)
                {
                        memset(&rights, 0, sizeof(drm_rights_struct));
                        fs_ret = FS_Read(fh, &rights, sizeof(drm_rights_struct), &len);
                        FS_Close (fh);
                        permission = DRM_get_permission (NULL, rights.mime_type);
                        if (drm_core_check_rights (&rights, permission) == KAL_FALSE &&
                            drm_core_rights_in_future(&rights, permission) == KAL_FALSE)
                        {
                             FS_Delete ((WCHAR*) file_name);
                        }
                }

                fs_ret = FS_FindNext(handle, &file_info, (WCHAR*) file_name, 40);
                if (fs_ret < 0)
                {
                    fs_ret = 0;
                    break;
                }
            }
        }
        FS_FindClose(handle);
    }
    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_FMT);

    param_ptr = (mmi_fmt_delete_rsp_strcut*) construct_local_para(sizeof(mmi_fmt_delete_rsp_strcut), TD_CTRL);

    param_ptr->result = fs_ret;

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_DELETE_RO_RSP;

    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
    
    return;    
}
#endif

#ifdef __OTG_ENABLE__

extern kal_uint8 USBHost_Media_Handle[];
extern FS_Driver FS_OTGDrv;


/*****************************************************************************
 * FUNCTION
 *  fmt_otg_insert_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_otg_insert_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fs_ret;
    void *array[10];
    int i, done;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* IT's hard code HERE */
    for (i = 0; i < 4; i++)
    {
        array[i] = &(USBHost_Media_Handle[i]);
    }
    fs_ret = FS_ConfigExtDevice(FS_SETUP_EXT_DEVICE, &FS_OTGDrv, 4, array, &done);
    kal_prompt_trace(MOD_FMT, "fmt call FS_ConfigExtDevice get (%d), done = %d \n", fs_ret, done);
}


/*****************************************************************************
 * FUNCTION
 *  fmt_otg_remove_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_otg_remove_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fs_ret;
    void *array[10];
    int i, done;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* IT's hard code HERE */
    for (i = 0; i < 4; i++)
    {
        array[i] = &(USBHost_Media_Handle[i]);
    }
    fs_ret = FS_ConfigExtDevice(FS_RELEASE_EXT_DEVICE, &FS_OTGDrv, 4, array, &done);
    kal_prompt_trace(MOD_FMT, "fmt call FS_ConfigExtDevice get (%d), done = %d \n", fs_ret, done);
}


/*****************************************************************************
 * FUNCTION
 *  fmt_otg_display_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_otg_display_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hold_local_para(local_para_ptr);

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_MMI_OTG_DISPLAY_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = local_para_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
}
#endif /* __OTG_ENABLE__ */ 


#ifdef __SIM_PLUS__
/*****************************************************************************
 * FUNCTION
 *  fmt_sim_plus_detect_hdlr
 * DESCRIPTION
 *  sim plus detect message handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_sim_plus_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msdc_card_detect_ind_struct *msg_ptr;
    ilm_struct *ilm_ptr = NULL;
    kal_int32 fs_ret = FS_NO_ERROR;
    kal_uint32 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* scan queue for multiple detect ind */
    msg_ptr = (msdc_card_detect_ind_struct*) local_para_ptr;
    fs_ret = FS_TestMSDC((void*)msg_ptr->media_array);
  		
    kal_prompt_trace(MOD_FMT, "FS return(SIM+): %d\n", fs_ret);

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_MMI_SIM_PLUS_DETECT_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = NULL;

    SEND_ILM( MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
    return;
}
#endif

#if defined(__FOTA_ENABLE__)
/*****************************************************************************
 * FUNCTION
 *  fmt_fota_init_hdlr
 * DESCRIPTION
 *  FOTA initialize handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_fota_init_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_fota_init_rsp_struct *param_ptr;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_FMT);

    param_ptr = (fmt_fota_init_rsp_struct*) construct_local_para
        (sizeof(fmt_fota_init_rsp_struct), TD_CTRL);

#ifdef __MTK_TARGET__
    param_ptr->result = FOTA_Initialize();
#else
    g_fhandle = FS_Open(L"c:\\test.txt", FS_CREATE_ALWAYS | FS_READ_WRITE );
    
    if (g_fhandle < FS_NO_ERROR)
    {
        FS_Close(g_fhandle);
        return ;
    }
    param_ptr->result = 0;    
#endif /* __MTK_TARGET__ */

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_FOTA_INIT_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    kal_prompt_trace(MOD_FMT, "fmt fota_init result = %d \n", param_ptr->result);

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_fota_write_data_hdlr
 * DESCRIPTION
 *  FOTA write data handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_fota_write_data_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_fota_write_data_req_struct *msg_ptr; 
    fmt_fota_write_data_rsp_struct *param_ptr;
    ilm_struct *ilm_ptr = NULL;

    kal_int32 write_result = 0;
    kal_uint32 write_len; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (fmt_fota_write_data_req_struct*) local_para_ptr;
    
    ilm_ptr = allocate_ilm(MOD_FMT);

    param_ptr = (fmt_fota_write_data_rsp_struct*) construct_local_para
        (sizeof(fmt_fota_write_data_rsp_struct), TD_CTRL);

#ifdef __MTK_TARGET__
    param_ptr->result = FOTA_WriteData(msg_ptr->length, msg_ptr->pkg_buffer);
#else
    if ((write_result = FS_Write(g_fhandle, msg_ptr->pkg_buffer, msg_ptr->length, (kal_uint32*) & write_len)) == FS_NO_ERROR)
    {
   	    param_ptr->result = 0;    
    }
    else
    {
        FS_Close(g_fhandle);
	    param_ptr->result = write_result;
    }
#endif /* #ifdef __MTK_TARGET__ */

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_FOTA_WRITE_DATA_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;

    kal_prompt_trace(MOD_FMT, "fmt fota_write_data result = %d \n", param_ptr->result);

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  fmt_fota_finalize_hdlr
 * DESCRIPTION
 *  FOTA finalize handler
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void fmt_fota_finalize_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_fota_finalize_req_struct *msg_ptr; 
    fmt_fota_finalize_rsp_struct *param_ptr;
    ilm_struct *ilm_ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = (fmt_fota_finalize_req_struct*) local_para_ptr;
        
    ilm_ptr = allocate_ilm(MOD_FMT);
    
    param_ptr = (fmt_fota_finalize_rsp_struct*) construct_local_para
        (sizeof(fmt_fota_finalize_rsp_struct), TD_CTRL);

#ifdef __MTK_TARGET__
    param_ptr->result = FOTA_Finalize();
#else
    FS_Close(g_fhandle);
    param_ptr->result = 0;
#endif /* __MTK_TARGET__ */

    ilm_ptr->msg_id = MSG_ID_MMI_FMT_FOTA_FINALIZE_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) param_ptr;
    kal_prompt_trace(MOD_FMT, "fmt fota_finalize result = %d \n", param_ptr->result);

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_L4C_SAP, ilm_ptr);
    return;
}

#endif /* defined(__FOTA_ENABLE__) */

#endif /* FMT_NOT_PRESENT */ 

