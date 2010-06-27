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

#include "ctype.h"

#include "svg_internal.h"
#include "svg_attribute.h"


/*****************************************************************************
 * FUNCTION
 *  svg_attr_get_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attributes          [IN]        
 *  name                [?]         
 *  value               [IN]        
 *  default_value       [?]         
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_attr_get_string(U8 **attributes, U8 *name, U8 **value, U8 *default_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *value = default_value;

    if (attributes == NULL)
    {
        return SVG_FAIL_ATTR_NOT_FOUND;
    }

    for (i = 0; attributes[i]; i += 2)
    {
        if (STRCMP(attributes[i], name) == 0)
        {
            *value = attributes[i + 1];
            return SVG_OK;
        }
    }

    return SVG_FAIL_ATTR_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  svg_attr_get_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length              [?]         
 *  attributes          [IN]        
 *  name                [?]         
 *  default_value       [?]         
 *  is_width            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_attr_get_length(float *length, U8 **attributes, U8 *name, U8 *default_value, BOOL is_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret;
    U8 *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_attr_get_string(attributes, name, &data, default_value);
    svg_to_length(length, data, is_width);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_to_length_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [?]         
 *  data            [?]         
 *  is_width        [IN]        
 *  data_used       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_to_length_internal(float *length, U8 *data, BOOL is_width, U8 **data_used)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float dpi, L;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_width)
    {
        dpi = svg_context->dpi_x;
        L = svg_context->width;
    }
    else
    {
        dpi = svg_context->dpi_y;
        L = svg_context->height;
    }

    *length = (float)svg_strtod(data, &data);
    for (; *data; data++)
    {
        if (*data == ',')
        {
            continue;
        }
        if (*data == ' ')
        {
            continue;
        }
        if (*data == ';')
        {
            continue;
        }
        break;
    }

    if (STRNCMP(data, "px", 2) == 0)    /* pixel */
    {
        ;
    }
    else if (STRNCMP(data, "pt", 2) == 0)
    {
        *length = *length * dpi / 72.0, data += 2;
    }
    else if (STRNCMP(data, "in", 2) == 0)
    {
        *length = *length * dpi, data += 2;
    }
    else if (STRNCMP(data, "cm", 2) == 0)
    {
        *length = *length * dpi / 2.54, data += 2;
    }
    else if (STRNCMP(data, "mm", 2) == 0)
    {
        *length = *length * dpi / 25.4, data += 2;
    }
    else if (STRNCMP(data, "pc", 2) == 0)
    {
        *length = *length * dpi / 6.0, data += 2;
    }
    else if (STRNCMP(data, "em", 2) == 0)
    {
        *length = *length * svg_context->font_size, data += 2;
    }
    else if (STRNCMP(data, "ex", 2) == 0)
    {
        *length = *length * svg_context->font_size / 2.0, data += 2;
    }
    else if (STRNCMP(data, "%", 1) == 0)
    {
        *length = *length * L / 100., data += 1;
    }

    *data_used = data;

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_to_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length          [?]         
 *  data            [?]         
 *  is_width        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_to_length(float *length, U8 *data, BOOL is_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return svg_to_length_internal(length, data, is_width, &tmp);
}


/*****************************************************************************
 * FUNCTION
 *  svg_attr_get_number_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list            [?]         
 *  list_len        [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
U32 svg_attr_get_number_list(float list[], U32 list_len, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < list_len && *data; i++)
    {
        while (*data)
        {
            if (*data != ' ' && *data != ',' && *data != '\t' && *data != '\n')
            {
                break;
            }
            data++;
        }   /* jump space/comma */
        if (!*data)
        {
            break;
        }

        list[i] = svg_strtod(data, &data);

        while (*data)
        {
            if (*data != ' ')
            {
                break;
            }
            data++;
        }   /* jump space */

        if (*data == '%')
        {
            list[i] /= 100.0;
            data++;
        }   /* support percent % */

        while (*data)
        {
            if (*data == ' ' || *data == ',' || *data != '\t' || *data != '\n')
            {
                break;
            }
            data++;
        }   /* move to space/comma */
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  svg_attr_get_string_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list            [?]         
 *  list_len        [IN]        
 *  data            [?]         
 * RETURNS
 *  
 *****************************************************************************/
U32 svg_attr_get_string_list(U8 *list[], U32 list_len, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < list_len && *data; i++)
    {
        while (*data)
        {
            if (*data != ' ' && *data != ',' && *data != '\t' && *data != '\n')
            {
                break;
            }
            data++;
        }   /* jump space/comma */
        if (!*data)
        {
            break;
        }

        list[i] = data;

        while (*data)
        {
            if (*data == ' ' || *data == ',' || *data != '\t' || *data != '\n')
            {
                break;
            }
            data++;
        }   /* move to space/comma */
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  svg_attr_get_viewbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  view_box            [?]         
 *  attributes          [IN]        
 *  name                [?]         
 *  default_value       [?]         
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_attr_get_viewbox(svg_view_box_t *view_box, U8 **attributes, U8 *name, U8 *default_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data;
    svg_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_attr_get_string(attributes, name, &data, default_value);
    if (data)
    {
        float list[4];
        U32 list_len;

        list_len = svg_attr_get_number_list(list, 4, data);
        if (list_len == 4)
        {
            view_box->x = list[0];
            view_box->y = list[1];
            view_box->width = list[2];
            view_box->height = list[3];
        }
        else
        {
            ret = SVG_FAIL_NUMBER_LIST_NOT_ENOUGH;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_attr_get_clock_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  seconds             [?]         
 *  attributes          [IN]        
 *  name                [?]         
 *  default_value       [?]         
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_attr_get_clock_value(float *seconds, U8 **attributes, U8 *name, U8 *default_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data;
    svg_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_attr_get_string(attributes, name, &data, default_value);

    svg_to_clock_value(seconds, data);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_to_clock_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  seconds     [?]     
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_to_clock_value(float *seconds, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *seconds = 0;
    if (data)
    {
        if ((pos = (U8*) STRCHR(data, ':')) == NULL)    /* Timecount-val */
        {
            *seconds = (float)svg_strtod(data, &data); /* default is seconds */
            if (STRCMP(data, "h") == 0)                 /* hour */
            {
                *seconds *= 60 * 60;
            }
            else if (STRCMP(data, "min") == 0)  /* min */
            {
                *seconds *= 60;
            }
            else if (STRCMP(data, "ms") == 0)   /* ms */
            {
                *seconds /= 1000.0;
            }
        }
        else if ((pos = (U8*) STRCHR(pos + 1, ':')) == NULL)   /* Partial-clock-val */
        {
            *seconds = svg_strtod(data, &data) * 60;        /* Minutes */
            data++;                                         /* drop ':' */
            *seconds += (float)svg_strtod(data, &data);    /* seconds */
        }
        else    /* Full-clock-val */
        {
            *seconds = svg_strtod(data, &data) * 60 * 60;   /* Hours */
            data++;                                         /* drop ':' */
            *seconds += svg_strtod(data, &data) * 60;       /* Minutes */
            data++;                                         /* drop ':' */
            *seconds += svg_strtod(data, &data);            /* seconds */
        }

    }

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_to_xy_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  xy          [?]     
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_to_xy_length(float xy[], U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *tmpstr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_to_length_internal(&xy[0], data, TRUE, &tmpstr);
    svg_to_length(&xy[1], tmpstr, FALSE);

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_sum_segments_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]         
 *  is_width        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
float svg_sum_segments_length(U8 *data, BOOL is_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float total_len = 0;
    float old, l;  /* previous & current value */
    U8 *p;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (p = data, i = 0; *p; i++)
    {
        old = l;
        svg_to_length_internal(&l, p, is_width, &p);
        if (i == 0)
        {
            old = l;
        }

        while (*p && (*p == ';' || *p == ' '))
        {
            p++;    /* jump space || ';' */
        }

        total_len += fabs(l - old);
    }
    return total_len;
}


/*****************************************************************************
 * FUNCTION
 *  svg_count_total_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int svg_count_total_segment(U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p;
    float l;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (p = data, i = 0; *p; i++)
    {
        svg_to_length_internal(&l, p, FALSE, &p);
        while (*p && (*p == ';' || *p == ' '))
        {
            p++;    /* jump space || ';' */
        }
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  svg_fetch_segment_interval_values
 * DESCRIPTION
 *  
 * PARAMETERS
 *  left                    [?]         
 *  right                   [?]         
 *  segment_interval        [IN]        
 *  data                    [?]         
 *  is_width                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_fetch_segment_interval_values(float *left, float *right, int segment_interval, U8 *data, BOOL is_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p;
    int i;
    float old = 0, l = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* seek to current segment */
    for (p = data, i = 0; i <= segment_interval + 1 && *p; i++)
    {
        old = l;
        svg_to_length_internal(&l, p, is_width, &p);
        if (i == 0)
        {
            old = l;
        }

        while (*p && (*p == ';' || *p == ' '))
        {
            p++;    /* jump space || ';' */
        }
    }
    *left = old;
    *right = l;
    if (i > segment_interval + 1)
    {
        return SVG_OK;
    }
    else
    {
        return SVG_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cal_bazier4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [?]         
 *  y       [?]         
 *  p1      [?]         
 *  p2      [?]         
 *  p3      [?]         
 *  p4      [?]         
 *  mu      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void cal_bazier4(float *x, float *y, float p1[2], float p2[2], float p3[2], float p4[2], float mu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float mum1, mum13, mu3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mum1 = 1 - mu;
    mum13 = mum1 * mum1 * mum1;
    mu3 = mu * mu * mu;

    *x = mum13 * p1[0] + 3 * mu * mum1 * mum1 * p2[0] + 3 * mu * mu * mum1 * p3[0] + mu3 * p4[0];
    *y = mum13 * p1[1] + 3 * mu * mum1 * mum1 * p2[1] + 3 * mu * mu * mum1 * p3[1] + mu3 * p4[1];
}


/*****************************************************************************
 * FUNCTION
 *  svg_get_xy_from_keyspline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1          [?]         
 *  y1          [?]         
 *  x2          [?]         
 *  y2          [?]         
 *  segment     [IN]        
 *  data        [?]         
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_get_xy_from_keyspline(float *x1, float *y1, float *x2, float *y2, int segment, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cnt = 0;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i <= segment; i++)
    {
        cnt = 0;
        if (*data)
        {
            *x1 = svg_strtod(data, &data);
            cnt++;
        }
        while (*data == ',' || *data == ' ')
        {
            data++;
        }

        if (*data)
        {
            *y1 = svg_strtod(data, &data);
            cnt++;
        }
        while (*data == ',' || *data == ' ')
        {
            data++;
        }

        if (*data)
        {
            *x2 = svg_strtod(data, &data);
            cnt++;
        }
        while (*data == ',' || *data == ' ')
        {
            data++;
        }

        if (*data)
        {
            *y2 = svg_strtod(data, &data);
            cnt++;
        }

        while (*data == ';' || *data == ',' || *data == ' ')
        {
            data++;
        }
    }
    if (cnt == 4)
    {
        return SVG_OK;
    }
    else
    {
        return SVG_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_interpolation_time_via_keytimes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  t_in_segment        [?]         
 *  current_seg         [?]         
 *  segments            [IN]        
 *  current_time        [IN]        
 *  total_time          [IN]        
 *  keytimes            [?]         
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_interpolation_time_via_keytimes(
            float *t_in_segment,
            int *current_seg,
            int segments,
            float current_time,
            float total_time,
            U8 *keytimes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keytimes)
    {
        int i;
        float low = 0, n = 0;
        float t = current_time / total_time;
        U8 *data = keytimes;

        for (i = 0; i <= segments; i++)
        {
            if (*data)
            {
                n = svg_strtod(data, &data);
            }
            while (*data == ',' || *data == ' ' || *data == ';')
            {
                data++;
            }

            if (n <= t)
            {
                low = n;
                *current_seg = i;
            }
            else
            {
                break;
            }
        }

        if (i > segments)   /* not find the high bound */
        {
            *t_in_segment = 1;
            (*current_seg)--;
        }
        else if (n > low)   /* for safe (divide by zero) */
        {
            *t_in_segment = (t - low) / (n - low);
        }
    }
    else    /* no keytimes */
    {
        float begin_time;

        if (current_time != total_time)
        {
            *current_seg = (int)(current_time * segments / total_time);
            begin_time = total_time * (*current_seg) / segments;

            *t_in_segment = (current_time - begin_time) / (total_time / segments);
        }
        else
        {
            *t_in_segment = 1;
            *current_seg = segments - 1;
        }
    }
    return SVG_OK;
}

// return value is between low ~ high, according the t (0 ~ 1) time value
// the key spline are (0,0) (x1,y1) (x2,y2) (1,1)


/*****************************************************************************
 * FUNCTION
 *  svg_interpolation_value_via_keyspline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  low         [IN]        
 *  high        [IN]        
 *  t           [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
float svg_interpolation_value_via_keyspline(
        float low,
        float high,
        float t,
        float x1,
        float y1,
        float x2,
        float y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float u, l, h;
    float x, y;
    float p0[] = {0, 0};
    float p1[2];
    float p2[2];
    float p3[] = {1, 1};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p1[0] = x1;
    p1[1] = y1;
    p2[0] = x2;
    p2[1] = y2;

    l = 0;
    h = 1;
    u = t;  /* assume u is time , but u is length unit, t is second unit */
    while (1)
    {
        float delta;

        cal_bazier4(&x, &y, p0, p1, p2, p3, u);
        delta = y - t;
        if (-1e-5 <= delta && delta <= 1e-5)    /* assume they are equal */
        {
            break;
        }
        else if (delta < 0)
        {
            l = u;
        }
        else
        {
            h = u;
        }
        u = (l + h) / 2;
    }
    return x * (high - low) + low;
}


/*****************************************************************************
 * FUNCTION
 *  svg_interpolation_values
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret                 [?]         
 *  data                [?]         
 *  is_width            [IN]        
 *  calc_mode           [IN]        
 *  keysplines          [?]         
 *  keytimes            [?]         
 *  current_time        [IN]        
 *  total_time          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_interpolation_values(
            float *ret,
            U8 *data,
            BOOL is_width,
            svg_animate_calc_mode_enum calc_mode,
            U8 *keysplines,
            U8 *keytimes,
            float current_time,
            float total_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret = 0;   /* default value */

    if (calc_mode == SVG_ANIMATE_PACED) /* paced ignore the keytimes and keysplines */
    {
        float total_length;
        float target_length;
        float len;
        float seg_len = 0;
        float left = 0, right;
        U8 *p;
        int i;

        total_length = svg_sum_segments_length(data, is_width);

        target_length = total_length * current_time / total_time;

        /* seek to target length */
        len = 0;
        for (p = data, i = 0; *p; i++)
        {
            left = right;
            svg_to_length_internal(&right, p, is_width, &p);
            if (i == 0)
            {
                left = right;
            }

            while (*p && (*p == ';' || *p == ' '))
            {
                p++;    /* jump space || ';' */
            }

            seg_len = fabs(right - left);
            if (len + seg_len >= target_length || p == NULL)
            {
                break;
            }
            len += seg_len;
        }

        *ret = left + (right - left) * (target_length - len) / seg_len;
    }
    else    /* SVG_ANIMATE_LINEAR || SVG_ANIMATE_DISCRETE || SVG_ANIMATE_SPLINE */
    {
        float left, right;
        int total_seg_interval;
        int current_seg_interval;
        float t_in_segment;    /* time percentage in segment , (0 ~ 1) */

        /* count how many segment */
        total_seg_interval = svg_count_total_segment(data);
        total_seg_interval--;   /* ( 0, 1,2,... seg )  segment interval = total segment -1 */
        if (total_seg_interval <= 0)
        {
            return SVG_FAIL;
        }

        if (calc_mode == SVG_ANIMATE_DISCRETE)
        {
            total_seg_interval++;
        }

        /* find current segment & t_in_segment */
        if (svg_interpolation_time_via_keytimes
            (&t_in_segment, &current_seg_interval, total_seg_interval, current_time, total_time, keytimes) != SVG_OK)
        {
            return SVG_FAIL;
        }

        /* find the segment interval boundary , left and right */
        if (svg_fetch_segment_interval_values(&left, &right, current_seg_interval, data, is_width) != SVG_OK)
        {
            if (calc_mode != SVG_ANIMATE_DISCRETE)
            {
                return SVG_FAIL;
            }
            else
            {
                left = right;
            }
        }

        if (calc_mode == SVG_ANIMATE_LINEAR)
        {
            /* calculate linear between old to l */
            if (current_time == total_time)
            {
                *ret = right;
            }
            else
            {
                *ret = left + (right - left) * t_in_segment;
            }
        }
        else if (calc_mode == SVG_ANIMATE_DISCRETE)
        {
            if (current_time == total_time)
            {
                *ret = right;
            }
            else
            {
                *ret = left;
            }
        }
        else    /* SVG_ANIMATE_SPLINE */
        {
            float x1, y1, x2, y2;

            SVG_ASSERT(keysplines != NULL);
            if (svg_get_xy_from_keyspline(&x1, &y1, &x2, &y2, current_seg_interval, keysplines) == SVG_OK)
            {
                *ret = svg_interpolation_value_via_keyspline(
                        left,
                        right,                      /* low high */
                        current_time / total_time,  /* time */
                        x1,
                        y1,
                        x2,
                        y2);
            }
        }
    }

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_interpolation_from_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret                 [?]         
 *  from                [?]         
 *  to                  [?]         
 *  cnt                 [IN]        
 *  from_str            [?]         
 *  to_str              [?]         
 *  by_str              [?]         
 *  is_width            [?]         
 *  calc_mode           [IN]        
 *  keysplines          [?]         
 *  current_time        [IN]        
 *  total_time          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int svg_interpolation_from_to(
        float ret[],
        float from[],
        float to[],
        int cnt,
        U8 *from_str,
        U8 *to_str,
        U8 *by_str,
        BOOL is_width[],
        svg_animate_calc_mode_enum calc_mode,
        U8 *keysplines,
        float current_time,
        float total_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cnt && from_str && *from_str; i++)
    {
        svg_to_length_internal(&from[i], from_str, is_width[i], &from_str);
    }
    cnt = i;    /* reduce to available items */

    if (to_str)
    {
        for (i = 0; i < cnt && to_str && *to_str; i++)
        {
            svg_to_length_internal(&to[i], to_str, is_width[i], &to_str);
        }
        cnt = i;    /* reduce to available items */
    }
    else
    {
        for (i = 0; i < cnt && by_str && *by_str; i++)
        {
            svg_to_length_internal(&to[i], by_str, is_width[i], &by_str);
            to[i] += from[i];
        }
        cnt = i;    /* reduce to available items */
    }

    switch (calc_mode)
    {
        case SVG_ANIMATE_DISCRETE:
            if (current_time < total_time)
            {
                memcpy(ret, from, sizeof(ret[0]) * cnt);
            }
            else
            {
                memcpy(ret, to, sizeof(ret[0]) * cnt);
            }
            break;
        case SVG_ANIMATE_SPLINE:
            if (keysplines)
            {
                float x1, y1, x2, y2;

                if (svg_get_xy_from_keyspline(&x1, &y1, &x2, &y2, 0, keysplines) == SVG_OK)
                {
                    for (i = 0; i < cnt; i++)
                    {
                        ret[i] = svg_interpolation_value_via_keyspline(
                                    from[i],
                                    to[i],  /* low high */
                                    current_time / total_time,       /* time */
                                    x1,
                                    y1,
                                    x2,
                                    y2);
                    }
                    break;
                }
            }
        default:
        case SVG_ANIMATE_LINEAR:
            for (i = 0; i < cnt; i++)
            {
                ret[i] = (from[i] * (total_time - current_time) + to[i] * current_time) / total_time;
            }
            break;
    }
    return cnt;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */

