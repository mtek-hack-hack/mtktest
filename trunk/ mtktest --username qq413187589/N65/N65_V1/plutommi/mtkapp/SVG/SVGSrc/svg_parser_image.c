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
 *  svg
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SVG tiny basic library
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#if defined(SVG_SUPPORT)


#include "svg_internal.h"
#include "svg_element.h"
#include "app_base64.h"
#include "ucs2prot.h"
#include "svg_work_buffer.h"

/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_image(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_element_create(ret_element, SVG_ELEMENT_TYPE_IMAGE);
    if (ret == SVG_OK)
    {
        U8 *data;
        svg_element_t *e = *ret_element;

        svg_attr_get_length(&(e->X.image.x), attr, (U8*) "x", (U8*) "0", TRUE);
        svg_attr_get_length(&(e->X.image.y), attr, (U8*) "y", (U8*) "0", FALSE);

        svg_attr_get_length(&(e->X.image.width), attr, (U8*) "width", (U8*) "0", TRUE);
        svg_attr_get_length(&(e->X.image.height), attr, (U8*) "height", (U8*) "0", FALSE);

        ret = svg_attr_get_string(attr, (U8*) "xlink:href", &data, (U8*) "");
        if (ret != SVG_OK)
        {
            svg_mem_free(e);
            return ret;
        }

        if (STRNCMP(data, "data:image/", 11) == 0)  /* embedded data */
        {
            U8 *pos;
            U32 image_length, src_len;

            e->X.image.is_from_file = FALSE;
            /* find the image type */
            if (STRNCMP(data + 11, "jpg", 3) == 0)
            {
                e->X.image.src_type = GDI_IMAGE_TYPE_JPG;
            }
            else if (STRNCMP(data + 11, "bmp", 3) == 0)
            {
                e->X.image.src_type = GDI_IMAGE_TYPE_BMP;
            }
            else if (STRNCMP(data + 11, "gif", 3) == 0)
            {
                e->X.image.src_type = GDI_IMAGE_TYPE_GIF;
            }
            else if (STRNCMP(data + 11, "png", 3) == 0)
            {
                e->X.image.src_type = GDI_IMAGE_TYPE_PNG;
            }
            else
            {
                svg_mem_free(e);    /* unknown image type */
                return SVG_FAIL;
            }

            /* find the data begin */
            pos = (U8*) STRSTR(data + 11, "base64,");
            if (pos == NULL)
            {
                /* this raw data is not encoding by base64 */
                svg_mem_free(e);
                return SVG_FAIL;
            }
            pos += 7;
            src_len = STRLEN(pos);
            /* process encoding */
            image_length = svg_base64_len(src_len);
            e->X.image.src = svg_mem_malloc(image_length);
            image_length = applib_base64_decode((char*)pos, src_len, (char*)e->X.image.src, image_length);
            e->X.image.src_len = image_length;
        }
        else
        {
            U16 *tmp_name = svg_wb_buffer;
            U16 *tmp_name1= (U16*)(((U8*)svg_wb_buffer)+svg_wb_buffer_size/2);

            e->X.image.is_from_file = TRUE;
			if(mmi_ucs2strlen((S8*)(svg_context->current_path))+strlen((char*)data)> 1024)
			{
                svg_mem_free(e);    /* unknown image type */
				return SVG_FAIL;
			}

            mmi_ucs2cpy((S8*) tmp_name, (S8*) svg_context->current_path);
            mmi_asc_to_ucs2((S8*) tmp_name1, (S8*) data);
            svg_fp_to_dos_slash(tmp_name1);
            svg_fp_concat_path(tmp_name, tmp_name1);

            e->X.image.src = svg_const_pool_raw((U8*) tmp_name, mmi_ucs2strlen((S8*) tmp_name) * 2 + 2);
        }
    }
    return ret;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */

