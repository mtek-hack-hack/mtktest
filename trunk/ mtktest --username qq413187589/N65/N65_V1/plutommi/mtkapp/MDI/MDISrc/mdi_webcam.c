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
 *  mdi_webcam.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Webcam sensor related interface
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
 *============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_WEBCAM__

#ifdef __MTK_TARGET__
   /* 
    * - For PC Simulator and MoDis, do not call media's webcam functions 
    * - For Target, call media's cam functions.
    */
#define MDI_WEBCAM_DRIVER_AVAIALBE
#endif /* __MTK_TARGET__ */ 

/***************************************************************************** 
* Include
*****************************************************************************/
#include "stdC.h"       /* standard inc */
#include "MMIDataType.h"    /* MMI Data type */
#include "debuginitdef.h"       /* MMI_ASSERT */
#include "EventsGprot.h"        /* event hadnling */

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_webcam.h"

#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
#include "med_global.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_WEBCAM_JPG_COUNT     (5)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    S32 start_seq_num;
    BOOL is_pause_jpeg_size_set;
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    webcam_default_jpeg_file_info jpg_file_info[MDI_WEBCAM_JPG_COUNT];
#endif 
} mdi_webcam_cntx_struct;

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mdi_webcam_cntx_struct g_mdi_webcam_cntx;
void (*mdi_webcam_event_callback_funcptr) (MDI_RESULT, BOOL) = NULL;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mdi_webcam_start_result_hdlr(void *msg_ptr);
static void mdi_webcam_abort_indication_hdlr(void *msg_ptr);


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_init
 * DESCRIPTION
 *  init
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_init(void)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MDI_WEBCAM_JPG_COUNT; i++)
    {
        g_mdi_webcam_cntx.jpg_file_info[i].start_addr = NULL;
    }
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    g_mdi_webcam_cntx.start_seq_num = 0;
    g_mdi_webcam_cntx.is_pause_jpeg_size_set = FALSE;

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_set_pause_jpeg_file
 * DESCRIPTION
 *  set jpeg file which will be used when pause.
 * PARAMETERS
 *  idx                 [IN]        Idx
 *  jpeg_file_ptr       [IN]        Jpeg file data pointer
 *  file_length         [IN]        
 *  width               [IN]        Image width
 *  height              [IN]        Image height
 *  file_len(?)         [IN]        File length
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_set_pause_jpeg_file(U16 idx, PU8 jpeg_file_ptr, U32 file_length, S32 width, S32 height)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_webcam_cntx.is_pause_jpeg_size_set = TRUE;

    ASSERT(MDI_WEBCAM_JPG_COUNT > idx); /* id exceed entry slot */

    g_mdi_webcam_cntx.jpg_file_info[idx].start_addr = jpeg_file_ptr;
    g_mdi_webcam_cntx.jpg_file_info[idx].size = file_length;
    g_mdi_webcam_cntx.jpg_file_info[idx].width = width;
    g_mdi_webcam_cntx.jpg_file_info[idx].height = height;

    media_webcam_set_default_jpeg_size(idx, file_length);
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_start
 * DESCRIPTION
 *  start webcam
 * PARAMETERS
 *  rotate              [IN]        Preview rotate
 *  banding             [IN]        Banding
 *  event_callback      [IN]        Webcam event callback
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_start(U16 rotate, U16 banding, mdi_webcam_event_callback event_callback)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_start_req_struct start_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[MDI_WEBCAM] mdi_webcam_start()");

    /* check if size is set or not */
    MMI_ASSERT(g_mdi_webcam_cntx.is_pause_jpeg_size_set);
    MMI_ASSERT(event_callback != NULL);

    SetProtocolEventHandler(mdi_webcam_start_result_hdlr, MSG_ID_MEDIA_WEBCAM_START_CNF);
    SetProtocolEventHandler(mdi_webcam_abort_indication_hdlr, MSG_ID_MEDIA_WEBCAM_ABORT_IND);

    start_data.banding = banding;
    start_data.rotate = rotate + CAM_IMAGE_NORMAL;
    start_data.seq_num = g_mdi_webcam_cntx.start_seq_num;

    mdi_webcam_event_callback_funcptr = event_callback;

    ret = media_webcam_start(MOD_MMI, &start_data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_stop
 * DESCRIPTION
 *  stop webcam
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_stop(void)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[MDI_WEBCAM] mdi_webcam_stop()");

    g_mdi_webcam_cntx.start_seq_num++;
    media_webcam_stop(MOD_MMI);
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_pause
 * DESCRIPTION
 *  pause webcam
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_pause(void)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_pause_req_struct data;
    S32 i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[MDI_WEBCAM] mdi_webcam_pause()");

    data.no_of_jpeg_files = 0;
    for (i = 0; i < MDI_WEBCAM_JPG_COUNT; i++)
    {
        if (g_mdi_webcam_cntx.jpg_file_info[i].start_addr != NULL)
        {
            data.no_of_jpeg_files++;
        }
    }

    data.file_info = (webcam_default_jpeg_file_info*) g_mdi_webcam_cntx.jpg_file_info;

    ret = media_webcam_pause(MOD_MMI, (void*)&data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_resume
 * DESCRIPTION
 *  resume webcam
 * PARAMETERS
 *  rotate      [IN]        Preview rotate
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_resume(U16 rotate)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_resume_req_struct resume_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[MDI_WEBCAM] mdi_webcam_resume()");

    resume_data.rotate = rotate + CAM_IMAGE_NORMAL;
    ret = media_webcam_resume(MOD_MMI, &resume_data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }    
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_rotate
 * DESCRIPTION
 *  rotate webcam preview
 * PARAMETERS
 *  rotate      [IN]        Preview rotate
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_rotate(U16 rotate)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_rotate_req_struct rotate_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rotate_data.rotate = rotate + CAM_IMAGE_NORMAL;
    ret = media_webcam_rotate(MOD_MMI, &rotate_data);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }    
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_capture
 * DESCRIPTION
 *  notify PC to capture the image
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    ret = media_webcam_capture(MOD_MMI);
    if (ret != MED_RES_OK)
    {
        return MDI_RES_WEBCAM_ERR_FAILED;
    }
    else
    {
        return MDI_RES_WEBCAM_SUCCEED;
    }
#endif 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_get_pause_jpeg_count
 * DESCRIPTION
 *  get pause jpeg file count
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mdi_webcam_get_pause_jpeg_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    return (U16) media_webcam_get_resolution_num();
#else 
    return 0;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_get_pause_jpeg_info
 * DESCRIPTION
 *  get pause jpeg file count
 * PARAMETERS
 *  idx                 [IN]        Index
 *  image_width         [OUT]       Image width
 *  image_height        [OUT]       Image height
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_webcam_get_pause_jpeg_info(U16 idx, S32 *image_width, S32 *image_height)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 drv_img_width;
    U16 drv_img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_webcam_get_resolution_dimension(idx, (U16*) & drv_img_width, (U16*) & drv_img_height);

    *image_width = drv_img_width;
    *image_height = drv_img_height;
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

    return MDI_RES_WEBCAM_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_start_result_hdlr
 * DESCRIPTION
 *  webcam start result handler
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_webcam_start_result_hdlr(void *msg_ptr)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_start_cnf_struct *start_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[MDI_WEBCAM] mdi_webcam_start_result_hdlr()");

    start_data_ptr = (media_webcam_start_cnf_struct*) msg_ptr;

    if (start_data_ptr->seq_num != g_mdi_webcam_cntx.start_seq_num)
    {
        /* cant match, means already stopped */
        return;
    }

    if (mdi_webcam_event_callback_funcptr != NULL)
    {
        if (start_data_ptr->result == MED_RES_OK)
        {
            mdi_webcam_event_callback_funcptr(MDI_RES_WEBCAM_SUCCEED, start_data_ptr->camera_workable);
        }
        else
        {
            mdi_webcam_event_callback_funcptr(MDI_RES_WEBCAM_ERR_FAILED, start_data_ptr->camera_workable);
        }
    }
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_webcam_abort_indication_hdlr
 * DESCRIPTION
 *  webcam abort indication from driver
 * PARAMETERS
 *  msg_ptr     [IN]        Message pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_webcam_abort_indication_hdlr(void *msg_ptr)
{
#ifdef MDI_WEBCAM_DRIVER_AVAIALBE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_webcam_abort_ind_struct *abort_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[MDI_WEBCAM] mdi_webcam_abort_indication_hdlr()");

    abort_data_ptr = (media_webcam_abort_ind_struct*) msg_ptr;

    if (abort_data_ptr->seq_num != g_mdi_webcam_cntx.start_seq_num)
    {
        /* cant match, means already stopped */
        return;
    }

    if (mdi_webcam_event_callback_funcptr != NULL)
    {
        mdi_webcam_event_callback_funcptr(MDI_RES_WEBCAM_DRV_ABORT, KAL_TRUE);
    }
#endif /* MDI_WEBCAM_DRIVER_AVAIALBE */ 

}

#endif /* __MMI_WEBCAM__ */ 

