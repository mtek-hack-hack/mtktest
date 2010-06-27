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
#include "svg_style.h"
#include "svg_transform.h"

#define _RGB_(R,G,B)    ((R<<16)|(G<<8)|B)
typedef int (*compare_func) (const void *, const void *);


/*****************************************************************************
 * FUNCTION
 *  svg_style_parse_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color       [?]     
 *  str         [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_style_parse_color(U32 *color, U8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 r, g, b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    r = g = b = 0;

    if (str == NULL || *str == '\0')
    {
        return SVG_FAIL_NO_STYLE;
    }

    if (str[0] == '#')
    {
        int i;
        U32 val = 0;

        for (i = 1; str[i]; i++)
        {
            int hexval;

            if (str[i] >= '0' && str[i] <= '9')
            {
                hexval = str[i] - '0';
            }
            else if (str[i] >= 'A' && str[i] <= 'F')
            {
                hexval = str[i] - 'A' + 10;
            }
            else if (str[i] >= 'a' && str[i] <= 'f')
            {
                hexval = str[i] - 'a' + 10;
            }
            else
            {
                break;
            }
            val = (val << 4) + hexval;
        }
        if (i == 4)     // #rgb
        {
            val = ((val & 0xf00) << 8) | ((val & 0x0f0) << 4) | (val & 0x00f);
            val |= val << 4;
        }
        r = (val >> 16) & 0xff;
        g = (val >> 8) & 0xff;
        b = (val) & 0xff;
    }
    else if (strstr((char*)str, "rgb(") != NULL)
    {
        U32 item_len;
        float items[3];

        while (*str && *str != '(') /* find the '(' */
        {
            str++;
        }
        str++;

        item_len = svg_attr_get_number_list(items, 3, str);
        if (item_len != 3)
        {
            return SVG_FAIL_NO_STYLE;
        }

        if (strstr((char*)str, "%") != 0)
        {
            r = ((U32) (255 * items[0]));
            g = ((U32) (255 * items[1]));
            b = ((U32) (255 * items[2]));
            if (r > 255)
            {
                r = 255;
            }
            if (g > 255)
            {
                g = 255;
            }
            if (b > 255)
            {
                b = 255;
            }
        }
        else
        {
            r = ((U32) items[0]);
            g = ((U32) items[1]);
            b = ((U32) items[2]);
            if (r > 255)
            {
                r = 255;
            }
            if (g > 255)
            {
                g = 255;
            }
            if (b > 255)
            {
                b = 255;
            }
        }
    }
    else
    {
        typedef struct
        {
            const char *name;
            U32 value;
        } color_table_struct;

        const static color_table_struct color_list[] = 
        {
            {"aliceblue", _RGB_(240, 248, 255)},
            {"antiquewhite", _RGB_(250, 235, 215)},
            {"aqua", _RGB_(0, 255, 255)},
            {"aquamarine", _RGB_(127, 255, 212)},
            {"azure", _RGB_(240, 255, 255)},
            {"beige", _RGB_(245, 245, 220)},
            {"bisque", _RGB_(255, 228, 196)},
            {"black", _RGB_(0, 0, 0)},
            {"blanchedalmond", _RGB_(255, 235, 205)},
            {"blue", _RGB_(0, 0, 255)},
            {"blueviolet", _RGB_(138, 43, 226)},
            {"brown", _RGB_(165, 42, 42)},
            {"burlywood", _RGB_(222, 184, 135)},
            {"cadetblue", _RGB_(95, 158, 160)},
            {"chartreuse", _RGB_(127, 255, 0)},
            {"chocolate", _RGB_(210, 105, 30)},
            {"coral", _RGB_(255, 127, 80)},
            {"cornflowerblue", _RGB_(100, 149, 237)},
            {"cornsilk", _RGB_(255, 248, 220)},
            {"crimson", _RGB_(220, 20, 60)},
            {"cyan", _RGB_(0, 255, 255)},
            {"darkblue", _RGB_(0, 0, 139)},
            {"darkcyan", _RGB_(0, 139, 139)},
            {"darkgoldenrod", _RGB_(184, 132, 11)},
            {"darkgray", _RGB_(169, 169, 169)},
            {"darkgreen", _RGB_(0, 100, 0)},
            {"darkgrey", _RGB_(169, 169, 169)},
            {"darkkhaki", _RGB_(189, 183, 107)},
            {"darkmagenta", _RGB_(139, 0, 139)},
            {"darkolivegreen", _RGB_(85, 107, 47)},
            {"darkorange", _RGB_(255, 140, 0)},
            {"darkorchid", _RGB_(153, 50, 204)},
            {"darkred", _RGB_(139, 0, 0)},
            {"darksalmon", _RGB_(233, 150, 122)},
            {"darkseagreen", _RGB_(143, 188, 143)},
            {"darkslateblue", _RGB_(72, 61, 139)},
            {"darkslategray", _RGB_(47, 79, 79)},
            {"darkslategrey", _RGB_(47, 79, 79)},
            {"darkturquoise", _RGB_(0, 206, 209)},
            {"darkviolet", _RGB_(148, 0, 211)},
            {"deeppink", _RGB_(255, 20, 147)},
            {"deepskyblue", _RGB_(0, 191, 255)},
            {"dimgray", _RGB_(105, 105, 105)},
            {"dimgrey", _RGB_(105, 105, 105)},
            {"dodgerblue", _RGB_(30, 144, 255)},
            {"firebrick", _RGB_(178, 34, 34)},
            {"floralwhite", _RGB_(255, 255, 240)},
            {"forestgreen", _RGB_(34, 139, 34)},
            {"fuchsia", _RGB_(255, 0, 255)},
            {"gainsboro", _RGB_(220, 220, 220)},
            {"ghostwhite", _RGB_(248, 248, 255)},
            {"gold", _RGB_(255, 215, 0)},
            {"goldenrod", _RGB_(218, 165, 32)},
            {"gray", _RGB_(128, 128, 128)},
            {"green", _RGB_(0, 128, 0)},
            {"greenyellow", _RGB_(173, 255, 47)},
            {"grey", _RGB_(128, 128, 128)},
            {"honeydew", _RGB_(240, 255, 240)},
            {"hotpink", _RGB_(255, 105, 180)},
            {"indianred", _RGB_(205, 92, 92)},
            {"indigo", _RGB_(75, 0, 130)},
            {"ivory", _RGB_(255, 255, 240)},
            {"khaki", _RGB_(240, 230, 140)},
            {"lavender", _RGB_(230, 230, 250)},
            {"lavenderblush", _RGB_(255, 240, 245)},
            {"lawngreen", _RGB_(124, 252, 0)},
            {"lemonchiffon", _RGB_(255, 250, 205)},
            {"lightblue", _RGB_(173, 216, 230)},
            {"lightcoral", _RGB_(240, 128, 128)},
            {"lightcyan", _RGB_(224, 255, 255)},
            {"lightgoldenrodyellow", _RGB_(250, 250, 210)},
            {"lightgray", _RGB_(211, 211, 211)},
            {"lightgreen", _RGB_(144, 238, 144)},
            {"lightgrey", _RGB_(211, 211, 211)},
            {"lightpink", _RGB_(255, 182, 193)},
            {"lightsalmon", _RGB_(255, 160, 122)},
            {"lightseagreen", _RGB_(32, 178, 170)},
            {"lightskyblue", _RGB_(135, 206, 250)},
            {"lightslategray", _RGB_(119, 136, 153)},
            {"lightslategrey", _RGB_(119, 136, 153)},
            {"lightsteelblue", _RGB_(176, 196, 222)},
            {"lightyellow", _RGB_(255, 255, 224)},
            {"lime", _RGB_(0, 255, 0)},
            {"limegreen", _RGB_(50, 205, 50)},
            {"linen", _RGB_(250, 240, 230)},
            {"magenta", _RGB_(255, 0, 255)},
            {"maroon", _RGB_(128, 0, 0)},
            {"mediumaquamarine", _RGB_(102, 205, 170)},
            {"mediumblue", _RGB_(0, 0, 205)},
            {"mediumorchid", _RGB_(186, 85, 211)},
            {"mediumpurple", _RGB_(147, 112, 219)},
            {"mediumseagreen", _RGB_(60, 179, 113)},
            {"mediumslateblue", _RGB_(123, 104, 238)},
            {"mediumspringgreen", _RGB_(0, 250, 154)},
            {"mediumturquoise", _RGB_(72, 209, 204)},
            {"mediumvioletred", _RGB_(199, 21, 133)},
            {"midnightblue", _RGB_(25, 25, 112)},
            {"mintcream", _RGB_(245, 255, 250)},
            {"mistyrose", _RGB_(255, 228, 225)},
            {"moccasin", _RGB_(255, 228, 181)},
            {"navajowhite", _RGB_(255, 222, 173)},
            {"navy", _RGB_(0, 0, 128)},
            {"oldlace", _RGB_(253, 245, 230)},
            {"olive", _RGB_(128, 128, 0)},
            {"olivedrab", _RGB_(107, 142, 35)},
            {"orange", _RGB_(255, 165, 0)},
            {"orangered", _RGB_(255, 69, 0)},
            {"orchid", _RGB_(218, 112, 214)},
            {"palegoldenrod", _RGB_(238, 232, 170)},
            {"palegreen", _RGB_(152, 251, 152)},
            {"paleturquoise", _RGB_(175, 238, 238)},
            {"palevioletred", _RGB_(219, 112, 147)},
            {"papayawhip", _RGB_(255, 239, 213)},
            {"peachpuff", _RGB_(255, 218, 185)},
            {"peru", _RGB_(205, 133, 63)},
            {"pink", _RGB_(255, 192, 203)},
            {"plum", _RGB_(221, 160, 203)},
            {"powderblue", _RGB_(176, 224, 230)},
            {"purple", _RGB_(128, 0, 128)},
            {"red", _RGB_(255, 0, 0)},
            {"rosybrown", _RGB_(188, 143, 143)},
            {"royalblue", _RGB_(65, 105, 225)},
            {"saddlebrown", _RGB_(139, 69, 19)},
            {"salmon", _RGB_(250, 128, 114)},
            {"sandybrown", _RGB_(244, 164, 96)},
            {"seagreen", _RGB_(46, 139, 87)},
            {"seashell", _RGB_(255, 245, 238)},
            {"sienna", _RGB_(160, 82, 45)},
            {"silver", _RGB_(192, 192, 192)},
            {"skyblue", _RGB_(135, 206, 235)},
            {"slateblue", _RGB_(106, 90, 205)},
            {"slategray", _RGB_(119, 128, 144)},
            {"slategrey", _RGB_(119, 128, 144)},
            {"snow", _RGB_(255, 255, 250)},
            {"springgreen", _RGB_(0, 255, 127)},
            {"steelblue", _RGB_(70, 130, 180)},
            {"tan", _RGB_(210, 180, 140)},
            {"teal", _RGB_(0, 128, 128)},
            {"thistle", _RGB_(216, 191, 216)},
            {"tomato", _RGB_(255, 99, 71)},
            {"turquoise", _RGB_(64, 224, 208)},
            {"violet", _RGB_(238, 130, 238)},
            {"wheat", _RGB_(245, 222, 179)},
            {"white", _RGB_(255, 255, 255)},
            {"whitesmoke", _RGB_(245, 245, 245)},
            {"yellow", _RGB_(255, 255, 0)},
            {"yellowgreen", _RGB_(154, 205, 50)}
        };

        {
            int i;

            for (i = 0; i < sizeof(color_list) / sizeof(color_list[0]); i++)
            {
                if (STRCMP(color_list[i].name, str) == 0)
                {
                    break;
                }
            }
            if (i >= sizeof(color_list) / sizeof(color_list[0]))
            {
                return SVG_FAIL_NO_STYLE;
            }

            r = (color_list[i].value >> 16) & 0xff;
            g = (color_list[i].value >> 8) & 0xff;
            b = (color_list[i].value) & 0xff;
        }

    }
    *color = (U32) gdi_act_color_from_rgb(255, r, g, b);

    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_style_parser_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  style       [?]     
 *  flag        [?]     
 *  tag         [?]     
 *  value       [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_style_parser_internal(svg_style_t *style, U32 *flag, U8 *tag, U8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret = SVG_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (tag && *tag == ' ')
    {
        tag++;  /* skip space from head */
    }
    while (value && *value == ' ')
    {
        value++;    /* skip space from head */
    }

    if (tag == NULL || value == NULL)
    {
        return SVG_FAIL;
    }

    if (STRCMP(tag, "color") == 0)
    {
        *flag = SVG_STYLE_FLAG_COLOR;
        ret = svg_style_parse_color(&style->color, value);
    }
    else if (STRCMP(tag, "transform") == 0)
    {
        *flag = SVG_STYLE_FLAG_TRANSFORM;
        ret = svg_style_parse_transform(style, value);
    }
    else if (STRCMP(tag, "font-size") == 0)
    {
        *flag = SVG_STYLE_FLAG_FONT_SIZE;
        ret = svg_to_length(&style->font_size, value, FALSE);
    }
    else if (STRCMP(tag, "fill") == 0)
    {
        *flag = SVG_STYLE_FLAG_FILL;
        if (STRCMP(value, "currentColor") == 0)
        {
            style->fill_color = 0;
            style->fill_color_type = SVG_COLOR_TYPE_USING_CURRENT_COLOR;
        }
        else if (STRCMP(value, "none") == 0)
        {
            style->fill_color_type = SVG_COLOR_TYPE_NONE;
        }
        else
        {
            ret = svg_style_parse_color(&style->fill_color, value);
            style->fill_color_type = SVG_COLOR_TYPE_HWRGB;
        }
    }
    else if (STRCMP(tag, "stroke") == 0)
    {
        *flag = SVG_STYLE_FLAG_STROKE_COLOR;

        if (style->stroke_size == 0)
        {
            style->stroke_size = 1;
        }
        if (STRCMP(value, "currentColor") == 0)
        {
            style->stroke_color = 0;
            style->stroke_color_type = SVG_COLOR_TYPE_USING_CURRENT_COLOR;
        }
        else if (STRCMP(value, "none") == 0)
        {
            style->stroke_color_type = SVG_COLOR_TYPE_NONE;
        }
        else
        {
            ret = svg_style_parse_color(&style->stroke_color, value);
            style->stroke_color_type = SVG_COLOR_TYPE_HWRGB;
        }
    }
    else if (STRCMP(tag, "stroke-width") == 0)
    {
        *flag = SVG_STYLE_FLAG_STROKE_SIZE;
        ret = svg_to_length(&style->stroke_size, value, FALSE);
    }
    else if (STRCMP(tag, "font-family") == 0)
    {
        *flag = SVG_STYLE_FLAG_FONT_FAMILY;
        style->font_family = value;

        if (svg_hash_find(svg_context->font_family, value, &style->font_family) == NULL)
        {
            ret = SVG_FAIL;
        }
    }
    else if (STRCMP(tag, "font-weight") == 0)
    {
        *flag = SVG_STYLE_FLAG_FONT_WEIGHT;
        style->font_weight = svg_const_pool(value);
    }
    else if (STRCMP(tag, "text-anchor") == 0)
    {
        *flag = SVG_STYLE_FLAG_TEXT_ANCHOR;
        if(STRCMP(value, "middle")==0)
            style->text_anchor= SVG_TEXT_ANCHOR_MIDDLE;
        else if(STRCMP(value, "end")==0)
            style->text_anchor= SVG_TEXT_ANCHOR_END;
        else
            style->text_anchor= SVG_TEXT_ANCHOR_START;
    }

    else if (STRCMP(tag, "fill-rule") == 0 && STRCMP(value, "evenodd") == 0)
    {
        *flag = SVG_STYLE_FLAG_FILL_RULE_EVENODD;
    }
    else if (STRCMP(tag, "stroke-linejoin") == 0)
    {
        *flag = SVG_STYLE_FLAG_LINE_JOIN;
        if (STRCMP(value, "round") == 0)
        {
            style->join = SVG_STROKE_JOIN_ROUND;
        }
        else if (STRCMP(value, "bevel") == 0)
        {
            style->join = SVG_STROKE_JOIN_BEVEL;
        }
        else
        {
            style->join = SVG_STROKE_JOIN_MITER;
        }
    }
    else if (STRCMP(tag, "stroke-linecap") == 0)
    {
        *flag = SVG_STYLE_FLAG_LINE_CAP;
        if (STRCMP(value, "round") == 0)
        {
            style->cap = SVG_STROKE_CAP_ROUND;
        }
        else if (STRCMP(value, "square") == 0)
        {
            style->cap = SVG_STROKE_CAP_SQUARE;
        }
        else
        {
            style->cap = SVG_STROKE_CAP_BUTT;
        }
    }
    else if (STRCMP(tag, "stroke-miterlimit") == 0)
    {
        *flag = SVG_STYLE_FLAG_LINE_MITER_LIMIT;
        style->miter_limit = svg_strtod(value, NULL);
    }
    else if (STRCMP(tag, "stroke-dashoffset") == 0)
    {
        style->dash.offset = svg_strtod(value, NULL);
    }
    else if (STRCMP(tag, "stroke-dasharray") == 0)
    {
        int j, len;
        U8 *data;
        float *dash_array;

        /* count the dash array length */
        data = value;
        len = 1;
        for (; *data; data++)
            if (*data == ',')
            {
                len++;
            }

        if (len > 1)
        {
            /* malloc dash array space */
            dash_array = svg_mem_malloc(sizeof(float) * len);
            /* parse dash array */
            data = value;
            for (j = 0; j < len; j++)
            {
                dash_array[j] = svg_strtod(data, &data);
                while (*data == ',' || *data == ' ')
                {
                    data++;
                }
            }

            /* put into const pool */
            style->dash.list = (float*)svg_const_pool_raw((U8*) dash_array, sizeof(float) * len);
            style->dash.n = len;

            /* free dash array space */
            svg_mem_free(dash_array);
            *flag = SVG_STYLE_FLAG_STROKE_DASH;
        }
    }
    else if (STRCMP(tag, "requiredExtensions") == 0)    /* currently, we don't support any extensions */
    {
        *flag = SVG_STYLE_FLAG_SWITCH_FAIL;
    }
    else if (STRCMP(tag, "requiredFeatures") == 0)  /* currently, we don't support any feature */
    {
        *flag = SVG_STYLE_FLAG_SWITCH_FAIL;
    }
    else if (STRCMP(tag, "requiredFormats") == 0)   /* currently, we don't support any format */
    {
        *flag = SVG_STYLE_FLAG_SWITCH_FAIL;
    }
    else if (STRCMP(tag, "requiredFonts") == 0) /* currently, we don't support any font */
    {
        *flag = SVG_STYLE_FLAG_SWITCH_FAIL;
    }
    else if (STRCMP(tag, "systemLanguage") == 0)    /* currently, we don't support any language */
    {
        *flag = SVG_STYLE_FLAG_SWITCH_FAIL;
    }
    else
    {
        ret = SVG_FAIL;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  svg_style_parser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_style       [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_style_parser(svg_style_t **ret_style, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    svg_style_t style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_style = NULL;
    memset(&style, 0, sizeof(style));

    for (i = 0; attr[i]; i += 2)
    {
        svg_enum ret = SVG_FAIL_NO_STYLE;
        U32 flag = 0;
        U8 *tag = attr[i];

        if (STRCMP(tag, "style") == 0)
        {
            U8 *style_list = attr[i + 1];
            U8 *pos, *pos1;

            while ((pos = (U8*) STRCHR(style_list, ':')) != NULL)
            {
                pos1 = (U8*) STRCHR(pos + 1, ';');
                *pos = '\0';
                if (pos1)
                {
                    *pos1 = '\0';
                }

                if (svg_style_parser_internal(&style, &flag, style_list, pos + 1) == SVG_OK)
                {
                    ret = SVG_OK;
                    style.flag |= flag;
                }

                if (pos1)
                {
                    style_list = pos1 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            ret = svg_style_parser_internal(&style, &flag, attr[i], attr[i + 1]);
            if (ret == SVG_OK)
            {
                style.flag |= flag;
            }
        }
    }

    if (style.flag)
    {
        U32 tmp;

        svg_hash_add_raw(svg_context->styles, (U8*) & style, sizeof(style), NULL, (U8 **) ret_style, &tmp);
        return SVG_OK;
    }
    else
    {
        return SVG_FAIL_NO_STYLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_style_font_weight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value           [?]     
 *  inherit_str     [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 *svg_style_font_weight(U8 *value, U8 *inherit_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 inherit_value = atoi((char*)inherit_str);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (STRCMP(value, "bold") == 0)
    {
        return svg_const_pool((U8*) "700");
    }

    if (STRCMP(value, "border") == 0)
    {
        return svg_const_pool((U8*) "900");
    }

    if (STRCMP(value, "lighter") == 0)
    {
        char buf[32];

        inherit_value -= 100;
        if (inherit_value < 100)
        {
            inherit_value = 100;
        }

        sprintf((char*)buf, "%d", inherit_value);
        return svg_const_pool((U8*) buf);
    }

    return svg_const_pool((U8*) "400"); /* default value */
}

#endif /* __MMI_SVG__ */ /* __SVG__ */

