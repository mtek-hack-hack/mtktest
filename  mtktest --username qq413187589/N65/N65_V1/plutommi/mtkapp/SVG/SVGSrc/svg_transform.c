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

#include "math.h"

#include "svg_internal.h"
#include "svg_transform.h"


/*****************************************************************************
 * FUNCTION
 *  svg_transform_identify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_identify(float dst[6])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst[0] = 1;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 1;
    dst[4] = 0;
    dst[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_copy(float dst[6], float src[6])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_multiply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?]     
 *  src1        [?]     
 *  src2        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_multiply(float dst[6], float src1[6], float src2[6])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float d0, d1, d2, d3, d4, d5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    d0 = src1[0] * src2[0] + src1[1] * src2[2];
    d1 = src1[0] * src2[1] + src1[1] * src2[3];
    d2 = src1[2] * src2[0] + src1[3] * src2[2];
    d3 = src1[2] * src2[1] + src1[3] * src2[3];
    d4 = src1[4] * src2[0] + src1[5] * src2[2] + src2[4];
    d5 = src1[4] * src2[1] + src1[5] * src2[3] + src2[5];
    dst[0] = d0;
    dst[1] = d1;
    dst[2] = d2;
    dst[3] = d3;
    dst[4] = d4;
    dst[5] = d5;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_invert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_invert(float dst[6], float src[6])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float r_det;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    r_det = 1.0 / (src[0] * src[3] - src[1] * src[2]);
    dst[0] = src[3] * r_det;
    dst[1] = -src[1] * r_det;
    dst[2] = -src[2] * r_det;
    dst[3] = src[0] * r_det;
    dst[4] = -src[4] * dst[0] - src[5] * dst[2];
    dst[5] = -src[4] * dst[1] - src[5] * dst[3];
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_flip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst_affine      [?]         
 *  src_affine      [?]         
 *  horz            [IN]        
 *  vert            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_flip(float dst_affine[6], float src_affine[6], int horz, int vert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst_affine[0] = horz ? -src_affine[0] : src_affine[0];
    dst_affine[1] = horz ? -src_affine[1] : src_affine[1];
    dst_affine[2] = vert ? -src_affine[2] : src_affine[2];
    dst_affine[3] = vert ? -src_affine[3] : src_affine[3];
    dst_affine[4] = horz ? -src_affine[4] : src_affine[4];
    dst_affine[5] = vert ? -src_affine[5] : src_affine[5];
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_scale
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]         
 *  sx      [IN]        
 *  sy      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_scale(float dst[6], float sx, float sy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst[0] = sx;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = sy;
    dst[4] = 0;
    dst[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_set_scale
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]         
 *  sx      [IN]        
 *  sy      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_set_scale(float dst[6], float sx, float sy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst[0] = sx;
    dst[3] = sy;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?]         
 *  theta       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_rotate(float dst[6], float theta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float s, c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s = sin(theta * M_PI / 180.0);
    c = cos(theta * M_PI / 180.0);
    dst[0] = c;
    dst[1] = s;
    dst[2] = -s;
    dst[3] = c;
    dst[4] = 0;
    dst[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_set_rotate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?]         
 *  theta       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_set_rotate(float dst[6], float theta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float s, c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s = sin(theta * M_PI / 180.0);
    c = cos(theta * M_PI / 180.0);
    dst[0] = c;
    dst[1] = s;
    dst[2] = -s;
    dst[3] = c;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_rotate_radian
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?]         
 *  theta       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_rotate_radian(float dst[6], float theta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float s, c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s = sin(theta);
    c = cos(theta);
    dst[0] = c;
    dst[1] = s;
    dst[2] = -s;
    dst[3] = c;
    dst[4] = 0;
    dst[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_shear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?]         
 *  theta       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_shear(float dst[6], float theta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = tan(theta * M_PI / 180.0);
    dst[0] = 1;
    dst[1] = 0;
    dst[2] = t;
    dst[3] = 1;
    dst[4] = 0;
    dst[5] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_translate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]         
 *  tx      [IN]        
 *  ty      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_translate(float dst[6], float tx, float ty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst[0] = 1;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 1;
    dst[4] = tx;
    dst[5] = ty;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_set_translate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]         
 *  tx      [IN]        
 *  ty      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_set_translate(float dst[6], float tx, float ty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst[4] = tx;
    dst[5] = ty;
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nx      [?]         
 *  ny      [?]         
 *  x       [IN]        
 *  y       [IN]        
 *  T       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void svg_transform_pos(float *nx, float *ny, float x, float y, float T[6])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *nx = T[0] * x + T[2] * y + T[4];
    *ny = T[1] * x + T[3] * y + T[5];
}


/*****************************************************************************
 * FUNCTION
 *  svg_transform_expansion
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]     
 * RETURNS
 *  
 *****************************************************************************/
float svg_transform_expansion(float src[6])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sqrt(fabs(src[0] * src[3] - src[1] * src[2]));
}


/*****************************************************************************
 * FUNCTION
 *  svg_style_parse_transform
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style       [?]     
 *  ptr         [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_style_parse_transform(svg_style_t *style, U8 *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float dst[6];
    U8 *data = (U8*) ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize to IDENTITY */
    svg_transform_identify(dst);

    while (*data)
    {
        float T[6];

        /* skip whitespace */
        while (*data == ' ' || *data == ',')
        {
            data++;
        }
        if (memcmp(data, "matrix", 6) == 0)
        {
            data += 6;
            while (*data == ' ' || *data == '(')
            {
                data++; /* skip whitespace, brace */
            }
            T[0] = svg_strtod(data, &data);
            while (*data == ' ' || *data == ',')
            {
                data++; /* skip whitespace */
            }
            T[1] = svg_strtod(data, &data);
            while (*data == ' ' || *data == ',')
            {
                data++; /* skip whitespace */
            }
            T[2] = svg_strtod(data, &data);
            while (*data == ' ' || *data == ',')
            {
                data++; /* skip whitespace */
            }
            T[3] = svg_strtod(data, &data);
            while (*data == ' ' || *data == ',')
            {
                data++; /* skip whitespace */
            }
            T[4] = svg_strtod(data, &data);
            while (*data == ' ' || *data == ',')
            {
                data++; /* skip whitespace */
            }
            T[5] = svg_strtod(data, &data);
            while (*data == ' ' || *data == ')')
            {
                data++; /* skip whitespace, brace */
            }

            svg_transform_multiply(dst, T, dst);
        }
        else if (memcmp(data, "translate", 9) == 0)
        {
            float a, b;

            data += 9;

            while (*data == ' ' || *data == '(')
            {
                data++; /* skip whitespace, brace */
            }
            a = svg_strtod(data, &data);
            while (*data == ' ' || *data == ',')
            {
                data++; /* skip whitespace */
            }
            b = svg_strtod(data, &data);
            while (*data == ' ' || *data == ')')
            {
                data++; /* skip whitespace, brace */
            }

            svg_transform_translate(T, a, b);
            svg_transform_multiply(dst, T, dst);
        }
        else if (memcmp(data, "scale", 5) == 0)
        {
            float a, b;

            data += 5;

            while (*data == ' ' || *data == '(')
            {
                data++; /* skip whitespace, brace */
            }
            a = svg_strtod(data, &data);
            while (*data == ' ' || *data == ',')
            {
                data++; /* skip whitespace */
            }
            if (*data == ')')
            {
                b = a;
            }
            else
            {
                b = svg_strtod(data, &data);
            }
            while (*data == ' ' || *data == ')')
            {
                data++; /* skip whitespace, brace */
            }

            svg_transform_scale(T, a, b);
            svg_transform_multiply(dst, T, dst);
        }
        else if (memcmp(data, "rotate", 6) == 0)
        {
            float angle;

            data += 6;

            while (*data == ' ' || *data == '(')
            {
                data++; /* skip whitespace, brace */
            }
            angle = svg_strtod(data, &data);
            while (*data == ' ' || *data == ')')
            {
                data++; /* skip whitespace, brace */
            }

            svg_transform_rotate(T, angle);
            svg_transform_multiply(dst, T, dst);
        }
        else if (memcmp(data, "skewX", 5) == 0)
        {
            float angle;

            data += 5;

            while (*data == ' ' || *data == '(')
            {
                data++; /* skip whitespace, brace */
            }
            angle = svg_strtod(data, &data);
            while (*data == ' ' || *data == ')')
            {
                data++; /* skip whitespace, brace */
            }

            svg_transform_shear(T, angle);
            svg_transform_multiply(dst, T, dst);
        }
        else if (memcmp(data, "skewY", 5) == 0)
        {
            float angle;

            data += 5;

            while (*data == ' ' || *data == '(')
            {
                data++; /* skip whitespace, brace */
            }
            angle = svg_strtod(data, &data);
            while (*data == ' ' || *data == ')')
            {
                data++; /* skip whitespace, brace */
            }

            svg_transform_shear(T, angle);
            T[1] = T[2];
            T[2] = 0;
            svg_transform_multiply(dst, T, dst);
        }
        else
        {
            return SVG_FAIL_TRANSFORM_FORMAT_ERROR;
        }
    }

    memcpy(style->transform, dst, sizeof(dst));
    return SVG_OK;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */

