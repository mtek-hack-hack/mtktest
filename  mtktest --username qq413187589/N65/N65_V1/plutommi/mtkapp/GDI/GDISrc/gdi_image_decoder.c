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
 *  gdi_image_decoder.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image decoder. Decode in media task' time. Non-blocking.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "gdc_include.h"

/* callback function */
static void (*gdi_image_decoder_result_callback) (GDI_RESULT decoder_result, gdi_handle handle) = NULL;

/*****************************************************************************
 * FUNCTION
 *  gdi_image_decoder_create
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_decoder_create(
            S32 max_img_width,
            S32 max_img_height,
            void (*result_callback_ptr) (GDI_RESULT decoder_result, gdi_handle handle))
{
    GDI_ENTER_CRITICAL_SECTION(void)
        
    gdi_image_decoder_result_callback = result_callback_ptr;
    GDI_RETURN(GDI_SUCCEED);

    GDI_EXIT_CRITICAL_SECTION(void)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_decoder_free
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_decoder_free(void)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_decoder_free)
    gdi_image_decoder_result_callback = NULL;
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_decoder_free)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_decoder_decode_file
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_decoder_decode_file(
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            BOOL is_blt,
            S8 *image_name,
            gdi_handle *handle_ptr)
{
    gdi_nb_set_blt(is_blt,FALSE);
    gdi_nb_set_done_callback(gdi_image_decoder_result_callback);

    return gdc_job_add_image(
                        GDI_IMAGE_SRC_FROM_FILE,
                        (U8*) image_name, GDI_IMAGE_TYPE_INVALID,0,
                        offset_x,offset_y,
                        width,height,
                        0,0,
                        0,
                        handle_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_decoder_stop
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_decoder_stop(gdi_handle handle)
{
    return gdc_job_del_image(handle);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_decoder_stop_all
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_decoder_stop_all(void)
{
    return gdc_job_del_all();
}



