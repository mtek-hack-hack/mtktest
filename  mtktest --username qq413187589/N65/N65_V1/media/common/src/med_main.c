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
 *   med_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of media task.
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
#ifdef ISP_SUPPORT
#include "camera_para.h"
#endif 

/* local include */
#include "med_global.h"
#include "med_status.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"

#include "aud_main.h"
#include "med_main.h"
#include "soc_api.h"

#ifdef __MED_VCALL_MOD__
#include "vcall.h"
#include "med_vt_struct.h"
#include "vcall_api.h"
#endif

#ifdef __MED_RTP_MOD__
#include "rtp.h"
#endif

#ifdef __MED_STREAM_MOD__
#include "stream_api.h"
#endif

#ifdef __MED_IMG_MOD__
#include "img_main.h"
#endif 
#ifdef __MED_CAM_MOD__
#include "cam_main.h"
#endif 
#if defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
#include "vid_main.h"
#endif 
#ifdef __MED_WEBCAM_MOD__
#include "webcam_main.h"
#endif 
#if defined (__MED_TVO_MOD__)
#include "tvo_main.h"
#endif 
#ifdef __MED_MTV_MOD__
#include "mtv_main.h"
#endif

/* global variables */
med_context_struct med_context;
med_context_struct *med_context_p = &med_context;

#ifdef __MTK_TARGET__
    #pragma arm section rwdata = "INTERNRW1", zidata = "INTERNZI1"
    __align(4)  kal_uint8 med_int_mem[MED_INT_MEM_SIZE];
    #pragma arm section rwdata , zidata

    #pragma arm section zidata = "LARGEPOOL_ZI"
    __align(4)     kal_uint8 med_ext_mem[MED_EXT_MEM_SIZE];
    #pragma arm section zidata

    #if defined(__SW_JPEG_CODEC_SUPPORT__)
         #pragma arm section rwdata = "INTERNRW2", zidata = "INTERNZI2"
         __align(4)  kal_uint8 med_int_stack_mem[MED_INT_STACK_MEM_SIZE];
         #pragma arm section rwdata , zidata
    #endif
#else
    kal_uint8 med_int_mem[MED_INT_MEM_SIZE];
    kal_uint8 med_ext_mem[MED_EXT_MEM_SIZE];
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
        __align(4)  kal_uint8 med_int_stack_mem[MED_INT_STACK_MEM_SIZE];
    #endif
#endif

/*==== FUNCTIONS ===========*/

extern void med_send_get_buffer_req(
               module_type src_mod_id,
               void **buffer_p,
               kal_uint32 buffer_size,
               kal_uint8 location);
extern void med_send_free_buffer_req(module_type src_mod_id, void **buffer_p, kal_uint8 location);
extern void med_timer_expiry_hdlr(ilm_struct *ilm_ptr);
extern void med_get_buffer_req_hdlr(ilm_struct *ilm_ptr);
extern void med_free_buffer_req_hdlr(ilm_struct *ilm_ptr);

/*****************************************************************************
 * FUNCTION
 *  med_nvram_read_data_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle nvram read data confirm.
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_nvram_read_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *parm_ptr = NULL;
    kal_uint16 pdu_len;
    kal_uint8 *pdu_ptr;
    kal_uint16 cnt, i;
    audio_param_struct *param_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MED_FUNC_ENTRY(MED_NVRAM_READ_DATA_CNF_HDLR) */

    parm_ptr = (nvram_read_cnf_struct*) local_para_ptr;
    pdu_ptr = get_pdu_ptr(peer_buff_ptr, &pdu_len);
    switch (parm_ptr->file_idx)
    {
        case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
            if (parm_ptr->length != sizeof(custom_acoustic_struct))
            {
                /* error reading length */
                ASSERT(parm_ptr->length != sizeof(custom_acoustic_struct)) return;
            }
            kal_mem_cpy(
                &(aud_context_p->acoustic_data),
                (custom_acoustic_struct*) pdu_ptr,
                sizeof(custom_acoustic_struct));

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            }
            break;

        case NVRAM_EF_AUDIO_PARAM_LID:
            if (parm_ptr->length != NVRAM_EF_AUDIO_PARAM_SIZE)
            {
                /* error reading length */
                ASSERT(parm_ptr->length != NVRAM_EF_AUDIO_PARAM_SIZE);
                return;
            }

            param_p = &(aud_context_p->audio_param);
            cnt = 0;
            for(i = 0; i < 6; i++)
            {
                kal_mem_cpy(&param_p->speech_input_FIR_coeffs[i][0], (pdu_ptr + cnt), (sizeof(kal_uint16) * SPEECH_FIR_COEFF_NUM));
                cnt += sizeof(kal_uint16) * SPEECH_FIR_COEFF_NUM;
            }
            for(i = 0; i < 6; i++)
            {
                kal_mem_cpy(&param_p->speech_output_FIR_coeffs[i][0], (pdu_ptr + cnt), (sizeof(kal_uint16) * SPEECH_FIR_COEFF_NUM));
                cnt += sizeof(kal_uint16) * SPEECH_FIR_COEFF_NUM;
            }
            kal_mem_cpy(&(param_p->selected_FIR_output_index), (pdu_ptr + cnt), sizeof(kal_uint16));
            cnt += sizeof(kal_uint16);
            kal_mem_cpy(param_p->speech_common_para, (pdu_ptr + cnt), sizeof(kal_uint16) * 12);
            cnt += sizeof(kal_uint16) * 12;
            kal_mem_cpy(param_p->speech_mode_para[0], (pdu_ptr + cnt), sizeof(kal_uint16) * 8);
            cnt += sizeof(kal_uint16) * 8;
            kal_mem_cpy(param_p->speech_mode_para[1], (pdu_ptr + cnt), sizeof(kal_uint16) * 8);
            cnt += sizeof(kal_uint16) * 8;
            kal_mem_cpy(param_p->speech_mode_para[2], (pdu_ptr + cnt), sizeof(kal_uint16) * 8);
            cnt += sizeof(kal_uint16) * 8;
            kal_mem_cpy(param_p->speech_mode_para[3], (pdu_ptr + cnt), sizeof(kal_uint16) * 8);
            cnt += sizeof(kal_uint16) * 8;
            kal_mem_cpy(param_p->speech_mode_para[4], (pdu_ptr + cnt), sizeof(kal_uint16) * 8);
            cnt += sizeof(kal_uint16) * 8;
            kal_mem_cpy(param_p->speech_mode_para[5], (pdu_ptr + cnt), sizeof(kal_uint16) * 8);
            cnt += sizeof(kal_uint16) * 8;
            kal_mem_cpy(param_p->speech_mode_para[6], (pdu_ptr + cnt), sizeof(kal_uint16) * 8);
            cnt += sizeof(kal_uint16) * 8;
            kal_mem_cpy(param_p->speech_mode_para[7], (pdu_ptr + cnt), sizeof(kal_uint16) * 8);
            cnt += sizeof(kal_uint16) * 8;
            kal_mem_cpy(&(param_p->max_swing), (pdu_ptr + cnt), sizeof(kal_uint16));
            cnt += sizeof(kal_uint16);
            kal_mem_cpy(param_p->Melody_FIR_Coeff_Tbl, (pdu_ptr + cnt), (sizeof(kal_int16) * MELODY_FIR_COEFF_NUM));
            cnt += sizeof(kal_int16) * MELODY_FIR_COEFF_NUM;
        #ifdef AUDIO_COMPENSATION_ENABLE
            for(i = 0; i < 2; i++)
            {
                kal_mem_cpy(&param_p->audio_compensation_coeff[i][0], (pdu_ptr + cnt), (sizeof(kal_uint16) * AUDIO_COMP_COEFF_NUM));
                cnt += sizeof(kal_uint16) * AUDIO_COMP_COEFF_NUM;
            }

            /* Set compensation filter to driver */
            Media_SetAudioCompensation(MEDIA_AUD_COMP_LOUDSPEAKER, param_p->audio_compensation_coeff[0]);
            Media_SetAudioCompensation(MEDIA_AUD_COMP_EARPHONE, param_p->audio_compensation_coeff[1]);
        #endif /* AUDIO_COMPENSATION_ENABLE */

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_set_startup_param();
            #ifdef ISP_SUPPORT
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CAMERA_PARA_LID, 0, 0);
            #else /* ISP_SUPPORT */ 
                aud_send_startup_cnf(MED_RES_OK);
                med_context_p->nvram_state = MED_POWERON_READING_NVRAM_FINISH;
            #endif /* ISP_SUPPORT */ 
            }
            else
            {
                ASSERT(med_context_p->nvram_state == MED_POWERON_READING_NVRAM);
            }
            break;
        #ifdef ISP_SUPPORT
        case NVRAM_EF_CAMERA_PARA_LID:
            /* set camera parameters to driver */
            set_camera_para((nvram_camera_para_struct*) pdu_ptr);

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if (defined(MT6219) || defined(MT6225)) 
                aud_send_startup_cnf(MED_RES_OK);
                med_context_p->nvram_state = MED_POWERON_READING_NVRAM_FINISH;
            #else /* (defined(MT6219)) */ /* not MT6219 */
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CAMERA_DEFECT_LID, 0, 0);
            #endif /* (defined(MT6219)) */ 
            }
            else
            {
                ASSERT(med_context_p->nvram_state == MED_POWERON_READING_NVRAM);
            }
            break;

        #if (!defined(MT6219) && !defined(MT6225))
        case NVRAM_EF_CAMERA_DEFECT_LID:
            #if (!defined(YUV_SENSOR_SUPPORT))
                /* set camera defect parameters to driver */
                set_camera_defect((nvram_camera_defect_struct*) pdu_ptr);
            #endif
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CAMERA_LENS_LID, 0, 0);
            }
            else
            {
                ASSERT(med_context_p->nvram_state == MED_POWERON_READING_NVRAM);
            }
            break;
        case NVRAM_EF_CAMERA_LENS_LID:
            #if (!defined(YUV_SENSOR_SUPPORT))
                /* set camera lens parameters to driver */
                set_camera_lens((nvram_camera_lens_struct*) pdu_ptr);
            #endif
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(MT6228)
                aud_send_startup_cnf(MED_RES_OK);
                med_context_p->nvram_state = MED_POWERON_READING_NVRAM_FINISH;
            #else /* defined(MT6228) */ 
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CAMERA_GAMMA_LID, 0, 0);
            #endif /* defined(MT6228) */ 
            }
            else
            {
                ASSERT(med_context_p->nvram_state == MED_POWERON_READING_NVRAM);
            }
            break;
        #if (!defined(MT6228))
        case NVRAM_EF_CAMERA_GAMMA_LID:
            #if (!defined(YUV_SENSOR_SUPPORT))
                /* set camera lens parameters to driver */
                set_camera_gamma((nvram_camera_gamma_struct*) pdu_ptr);
            #endif
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_startup_cnf(MED_RES_OK);
                med_context_p->nvram_state = MED_POWERON_READING_NVRAM_FINISH;
            }
            else
            {
                ASSERT(med_context_p->nvram_state == MED_POWERON_READING_NVRAM);
            }
        #endif /* (!defined(MT6228)) */ /* not Mt6228 */

        #endif /* (!defined(MT6219)) */ /* not MT6219 */

        #endif /* ISP_SUPPORT */ 
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_nvram_write_data_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle nvram write data confirm.
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_nvram_write_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *parm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parm_ptr = (nvram_write_cnf_struct*) local_para_ptr;

    /* MED_FUNC_ENTRY(MED_NVRAM_WRITE_DATA_CNF_HDLR) */

    switch (parm_ptr->file_idx)
    {
        case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
            aud_send_set_audio_profile_cnf(MED_RES_OK);
            break;
        case NVRAM_EF_AUDIO_PARAM_LID:
            aud_send_set_audio_param_cnf(MED_RES_OK);
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  med_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of media task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* start base timer */
    stack_init_timer(&med_context_p->base_timer, "MED Base Timer", MOD_MED);

    med_context_p->event_scheduler_ptr = new_evshed(
                                            &med_context_p->base_timer,
                                            med_start_base_timer,
                                            med_stop_base_timer,
                                            0,
                                            kal_evshed_get_mem,
                                            kal_evshed_free_mem,
                                            0);
    med_context_p->med_event = kal_create_event_group("med_events");

#ifdef __MED_CAM_MOD__
    cam_startup_hdlr(ilm_ptr);
#endif 
#ifdef __MED_IMG_MOD__
    img_startup_hdlr(ilm_ptr);
#endif 
#if defined (__MED_VID_MOD__)  || defined(__MED_MJPG_MOD__)
    vid_startup_hdlr(ilm_ptr);
#endif 
#ifdef __MED_WEBCAM_MOD__
    webcam_startup_hdlr(ilm_ptr);
#endif 
#if defined (__MED_TVO_MOD__)
    tvo_startup_hdlr(ilm_ptr);
#endif 

    aud_startup_hdlr(ilm_ptr);

    /* start to read nvram data for media task */
    aud_startup_read_nvram_data();

}


/*****************************************************************************
 * FUNCTION
 *  med_main
 * DESCRIPTION
 *  This function is main message dispatching function of media task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr->msg_id == MSG_ID_TIMER_EXPIRY)
    {
        med_timer_expiry_hdlr(ilm_ptr);
#if defined(__MED_MTV_MOD__)
        mtv_process_time_out((stack_timer_struct*)ilm_ptr->local_para_ptr);
#endif /* __MED_MTV_MOD__ */
    }
    else if (ilm_ptr->msg_id == MSG_ID_MED_STARTUP_REQ)
    {
        med_startup_hdlr(ilm_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_MEDIA_GET_BUFFER_REQ)
    {
        med_get_buffer_req_hdlr(ilm_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_MEDIA_FREE_BUFFER_REQ)
    {
        med_free_buffer_req_hdlr(ilm_ptr);
    }
#ifdef TST_HANDLER
    else if (ilm_ptr->msg_id == MSG_ID_TST_INJECT_STRING)
    {
        aud_tst_handler(ilm_ptr);
    }
#endif /* TST_HANDLER */ 
#ifdef __MED_CAM_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_CAM_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_CAM_CODE_END)
    {
        cam_main(ilm_ptr);
    }
#endif /* __MED_CAM_MOD__ */ 
#ifdef __MED_IMG_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_IMG_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_IMG_CODE_END)
    {
        img_main(ilm_ptr);
    }
#endif /* __MED_IMG_MOD__ */ 
#if defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
    else if (ilm_ptr->msg_id >= MSG_ID_MED_VID_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_VID_CODE_END)
    {
        vid_main(ilm_ptr);
    }
    else if (ilm_ptr->msg_id >= MSG_ID_MED_V_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_V_CODE_END)
    {
        vid_main(ilm_ptr);
    }
#endif /* defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 
#ifdef __MED_WEBCAM_MOD__
    else if ((ilm_ptr->msg_id >= MSG_ID_MED_WEBCAM_CODE_BEGIN &&
              ilm_ptr->msg_id <= MSG_ID_MED_WEBCAM_CODE_END) ||
             (ilm_ptr->msg_id >= MSG_ID_USB_MED_SET_CAMERA_ATTR_REQ && ilm_ptr->msg_id <= MSG_ID_USB_MED_STOP_CNF))
    {
        webcam_main(ilm_ptr);
    }
#endif /* __MED_WEBCAM_MOD__ */ 
#ifdef __MED_TVO_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_TVO_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_TVO_CODE_END)
    {
        tvo_main(ilm_ptr);
    }
#endif /* __MED_TVO_MOD__ */ 
    else if (ilm_ptr->msg_id == MSG_ID_NVRAM_READ_CNF)
    {
        med_nvram_read_data_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_NVRAM_WRITE_CNF)
    {
        med_nvram_write_data_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
#ifdef __MED_CTM_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_CTM_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_CTM_CODE_END)
    {
        aud_ctm_main(ilm_ptr);
    }
#endif /* __MED_CTM_MOD__ */ 
#ifdef __MED_RTP_MOD__
    else if ((ilm_ptr->msg_id >= MSG_ID_MED_RTP_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_RTP_CODE_END) ||
             (ilm_ptr->msg_id == MSG_ID_APP_SOC_NOTIFY_IND))
    {
        rtp_main(ilm_ptr);
    }
#endif /* __MED_RTP_MOD__ */
#ifdef __MED_STREAM_MOD__
    else if ((ilm_ptr->msg_id >= MSG_ID_MED_STREAM_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_STREAM_CODE_END) ||
             (ilm_ptr->msg_id >= RTSP_MSG_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_RTSP_CODE_END))
    {
        stream_main(ilm_ptr);
    }
#endif /* __MED_STREAM_MOD__ */
#ifdef __MED_VCALL_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_VCALL_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_VCALL_CODE_END ||
             ilm_ptr->msg_id >= MSG_ID_VT_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_VT_CODE_BEGIN + MSG_ID_VT_CODE_RANGE)
    {
        vcall_main(ilm_ptr);
    }
#endif /* __MED_VCALL_MOD__ */
#ifdef __MED_MTV_MOD__
    else if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_MTV_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_MTV_CODE_END) ||
             (ilm_ptr->msg_id >= MSG_ID_TDMB_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_TDMB_CODE_END))
    {
        mtv_main(ilm_ptr);
    }
#endif /* __MED_MTV_MOD__ */
    else
    {
        aud_main(ilm_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_task_main
 * DESCRIPTION
 *  This function is main function of media task.
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_task_main(task_entry_struct *task_entry_ptr)
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

    while (1)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        med_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }

}


/*****************************************************************************
 * FUNCTION
 *  med_init
 * DESCRIPTION
 *  This function is used to init media task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_context_p->int_mem_p = med_int_mem;
    med_context_p->ext_mem_p = med_ext_mem;

#if defined(__SW_JPEG_CODEC_SUPPORT__)
    med_context_p->int_stack_mem_p = med_int_stack_mem;
#endif

    if (!aud_init())
    {
        return KAL_FALSE;
    }

#ifdef __MED_IMG_MOD__
    if (!img_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_IMG_MOD__ */ 
#ifdef __MED_CAM_MOD__
    if (!cam_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_CAM_MOD__ */ 
#if defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
    if (!vid_init())
    {
        return KAL_FALSE;
    }
#endif /* defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 
#ifdef __MED_WEBCAM_MOD__
    if (!webcam_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_WEBCAM_MOD__ */ 
#if defined (__MED_TVO_MOD__)
    if (!tvo_init())
    {
        return KAL_FALSE;
    }
#endif /* defined (__MED_TVO_MOD__) */ 

    if (!med_utility_init())
    {
        return KAL_FALSE;
    }
#ifdef __MED_RTP_MOD__
    if (!rtp_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_RTP_MOD__ */
#ifdef __MED_STREAM_MOD__
    if (!stream_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_STREAM_MOD__ */
#ifdef __MED_VCALL_MOD__
    if (!vcall_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_VCALL_MOD__ */

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  med_reset
 * DESCRIPTION
 *  This function is used to reset media task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_reset(task_indx_type task_indx)
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
 *  med_create
 * DESCRIPTION
 *  This function is used to create media task configuration info.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct med_handler_info = 
    {
        med_task_main,  /* task entry function */
        med_init,       /* task initialization function */
        NULL,           /* task configuration function */
        med_reset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & med_handler_info;

    return KAL_TRUE;
}

#endif /* MED_NOT_PRESENT */ 

