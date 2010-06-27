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
#include "svg_vpath.h"
#include "svg_parser.h"


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_font(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret;
    svg_element_t *e;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_element_create(ret_element, SVG_ELEMENT_TYPE_FONT);
    e = *ret_element;

    svg_attr_get_length(&(e->X.font.horiz_origin_x), attr, (U8*) "horiz-origin-x", (U8*) "0", TRUE);
    svg_attr_get_length(&(e->X.font.horiz_origin_y), attr, (U8*) "horiz-origin-y", (U8*) "0", FALSE);
    svg_attr_get_length(&(e->X.font.horiz_adv_x), attr, (U8*) "horiz-adv-x", (U8*) "0", TRUE);

    svg_attr_get_length(&(e->X.font.vert_origin_x), attr, (U8*) "vert-origin-x", (U8*) "0", TRUE);
    svg_attr_get_length(&(e->X.font.vert_origin_y), attr, (U8*) "vert-origin-y", (U8*) "0", FALSE);
    svg_attr_get_length(&(e->X.font.vert_adv_y), attr, (U8*) "vert-adv-y", (U8*) "0", FALSE);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_font_face
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_font_face(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_element_t *e = svg_parser_container_top();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (e->type == SVG_ELEMENT_TYPE_FONT)
    {
        U8 *data;

        /* font_family */
        if (svg_attr_get_string(attr, (U8*) "font-family", &data, (U8*) "") == SVG_OK)
        {
            U8 *ret_id;

            svg_hash_add(svg_context->font_family, data, e, &ret_id);   /* add into hash */
            e->X.font.font_family = ret_id;
        }

        /* units-per-em */
        if (svg_attr_get_string(attr, (U8*) "units-per-em", &data, (U8*) "1000") == SVG_OK)
        {
            e->X.font.units_per_em = svg_strtod(data, &data);
        }

        /* ascent */
        if (svg_attr_get_string(attr, (U8*) "ascent", &data, (U8*) "0") == SVG_OK)
        {
            e->X.font.ascent = svg_strtod(data, &data);
        }

        /* descent */
        if (svg_attr_get_string(attr, (U8*) "descent", &data, (U8*) "0") == SVG_OK)
        {
            e->X.font.descent = svg_strtod(data, &data);
        }

    }
    return SVG_FAIL;    /* we don't need this element insert to SVG TREE */
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_hkern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_hkern(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_element_t *e = svg_parser_container_top();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (e->type == SVG_ELEMENT_TYPE_FONT)
    {
        U8 *data;
        U8 key[4];
        S32 k = 0;

        /* g1 */
        if (svg_attr_get_string(attr, (U8*) "g1", &data, (U8*) "") == SVG_OK)
        {
            svg_element_t *g = (svg_element_t*) svg_hash_find(e->X.font.glyph_name_hash, data, NULL);

            if (g)
            {
                memcpy(key, g->X.glyph.ucs2, 2);
            }
        }

        /* g2 */
        if (svg_attr_get_string(attr, (U8*) "g2", &data, (U8*) "") == SVG_OK)
        {
            svg_element_t *g = (svg_element_t*) svg_hash_find(e->X.font.glyph_name_hash, data, NULL);

            if (g)
            {
                memcpy(key + 2, g->X.glyph.ucs2, 2);
            }
        }

        /* k */
        if (svg_attr_get_string(attr, (U8*) "k", &data, (U8*) "0") == SVG_OK)
        {
            k = (S32) svg_strtod(data, &data);
        }

        if ((key[0] || key[1]) && (key[2] || key[3]))
        {
            if (e->X.font.hkern_hash == NULL)
            {
                e->X.font.hkern_hash = svg_hash_create(4);
            }

            svg_hash_add_raw(e->X.font.hkern_hash, key, 4, (void*)k, NULL, NULL);
        }
    }
    return SVG_FAIL;    /* we don't need this element insert to SVG TREE */

}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_glyph_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_glyph_internal(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data;
    svg_enum ret;
    svg_element_t *e;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_element_create(ret_element, SVG_ELEMENT_TYPE_GLYPH);
    e = *ret_element;

    if (svg_attr_get_string(attr, (U8*) "d", &data, (U8*) "") == SVG_OK)
    {
        e->X.glyph.path_data = svg_const_pool(data);
    }

    svg_attr_get_length(&(e->X.glyph.horiz_origin_x), attr, (U8*) "horiz-origin-x", (U8*) "-1", TRUE);
    svg_attr_get_length(&(e->X.glyph.horiz_origin_y), attr, (U8*) "horiz-origin-y", (U8*) "-1", FALSE);
    svg_attr_get_length(&(e->X.glyph.horiz_adv_x), attr, (U8*) "horiz-adv-x", (U8*) "-1", TRUE);

    svg_attr_get_length(&(e->X.glyph.vert_origin_x), attr, (U8*) "vert-origin-x", (U8*) "-1", TRUE);
    svg_attr_get_length(&(e->X.glyph.vert_origin_y), attr, (U8*) "vert-origin-y", (U8*) "-1", FALSE);
    svg_attr_get_length(&(e->X.glyph.vert_adv_y), attr, (U8*) "vert-adv-y", (U8*) "-1", FALSE);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_missing_glyph
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_missing_glyph(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_element_t *e = svg_parser_container_top();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (e->type == SVG_ELEMENT_TYPE_FONT)
    {
        if (svg_parser_element_glyph_internal(ret_element, attr) == SVG_OK)
        {
            e->X.font.miss_glyph = *ret_element;
        }
    }
    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_glyph
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_glyph(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_element_t *e = svg_parser_container_top();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (e->type == SVG_ELEMENT_TYPE_FONT)
    {
        U8 *data;

        if (svg_parser_element_glyph_internal(ret_element, attr) == SVG_OK)
        {
            if (svg_attr_get_string(attr, (U8*) "unicode", &data, (U8*) "") == SVG_OK)
            {
                U8 *ucs2;
                U32 ucs2_len;

                if (e->X.font.glyph_hash == NULL)
                {
                    e->X.font.glyph_hash = svg_hash_create(4);
                }

                ucs2 = svg_const_pool_utf82ucs2(data, &ucs2_len);
                (*ret_element)->X.glyph.ucs2 = ucs2;
                svg_hash_add_raw(
                    e->X.font.glyph_hash,
                    ucs2,
                    ucs2_len,       /* key */
                    *ret_element,   /* data */
                    NULL,
                    NULL);
            }
            if (svg_attr_get_string(attr, (U8*) "glyph-name", &data, (U8*) "") == SVG_OK)
            {
                if (e->X.font.glyph_name_hash == NULL)
                {
                    e->X.font.glyph_name_hash = svg_hash_create(4);
                }
                svg_hash_add(e->X.font.glyph_name_hash, data, *ret_element, &((*ret_element)->X.glyph.name));
            }
        }
    }
    return SVG_OK;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */

