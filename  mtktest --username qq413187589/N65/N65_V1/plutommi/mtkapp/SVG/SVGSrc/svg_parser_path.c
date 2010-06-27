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
typedef struct
{
    svg_vpath_t *vpath;
    float cpx, cpy;    /* current point */
    float rpx, rpy;    /* reflection point (for 's' and 't' commands) */
    char cmd;           /* current command (lowercase) */
    int param;          /* parameter number */
    BOOL rel;           /* true if relative coords */
    float params[7];   /* parameters that have been parsed */
} svg_path_cntx_t;


/*****************************************************************************
 * FUNCTION
 *  svg_parse_path_prepare_xy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx             [?]         
 *  n_params        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void svg_parse_path_prepare_xy(svg_path_cntx_t *ctx, int n_params)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctx->rel)
    {
        for (i = ctx->param; i < n_params; i++)
        {
            if (i > 2)
            {
                ctx->params[i] = ctx->params[i - 2];
            }
            else if (i == 1)
            {
                ctx->params[i] = ctx->cpy;
            }
            else if (i == 0)
            {
                ctx->params[i] = ctx->cpx;
            }
        }
    }
    else
    {
        for (i = ctx->param; i < n_params; i++)
        {
            ctx->params[i] = 0.0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _svg_parse_path_do_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx         [?]         
 *  final       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void _svg_parse_path_do_cmd(svg_path_cntx_t *ctx, BOOL final)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float x1, y1, x2, y2, x3, y3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ctx->cmd)
    {
        case 'm':
            if (ctx->param == 2 || final)
            {
                svg_parse_path_prepare_xy(ctx, 2);
                svg_vpath_move_to(ctx->vpath, ctx->params[0], ctx->params[1]);
                ctx->cpx = ctx->rpx = ctx->params[0];
                ctx->cpy = ctx->rpy = ctx->params[1];
                ctx->param = 0;
            }
            break;
        case 'l':
            if (ctx->param == 2 || final)
            {
                svg_parse_path_prepare_xy(ctx, 2);
                svg_vpath_line_to(ctx->vpath, ctx->params[0], ctx->params[1]);
                ctx->cpx = ctx->rpx = ctx->params[0];
                ctx->cpy = ctx->rpy = ctx->params[1];
                ctx->param = 0;
            }
            break;
        case 'c':
            if (ctx->param == 6 || final)
            {
                svg_parse_path_prepare_xy(ctx, 6);
                x1 = ctx->params[0];
                y1 = ctx->params[1];
                x2 = ctx->params[2];
                y2 = ctx->params[3];
                x3 = ctx->params[4];
                y3 = ctx->params[5];
                svg_vpath_curve_to(ctx->vpath, x1, y1, x2, y2, x3, y3);
                ctx->rpx = x2;
                ctx->rpy = y2;
                ctx->cpx = x3;
                ctx->cpy = y3;
                ctx->param = 0;
            }
            break;
        case 's':   /* smooth curveto */
            if (ctx->param == 4 || final)
            {
                svg_parse_path_prepare_xy(ctx, 4);
                x1 = 2 * ctx->cpx - ctx->rpx;
                y1 = 2 * ctx->cpy - ctx->rpy;
                x2 = ctx->params[0];
                y2 = ctx->params[1];
                x3 = ctx->params[2];
                y3 = ctx->params[3];
                svg_vpath_curve_to(ctx->vpath, x1, y1, x2, y2, x3, y3);
                ctx->rpx = x2;
                ctx->rpy = y2;
                ctx->cpx = x3;
                ctx->cpy = y3;
                ctx->param = 0;
            }
            break;
        case 'h':
            if (ctx->param == 1)
            {
                svg_vpath_line_to(ctx->vpath, ctx->params[0], ctx->cpy);
                ctx->cpx = ctx->rpx = ctx->params[0];
                ctx->param = 0;
            }
            break;
        case 'v':
            if (ctx->param == 1)
            {
                svg_vpath_line_to(ctx->vpath, ctx->cpx, ctx->params[0]);
                ctx->cpy = ctx->rpy = ctx->params[0];
                ctx->param = 0;
            }
            break;
        case 'q':
            if (ctx->param == 4 || final)
            {
                svg_parse_path_prepare_xy(ctx, 4);

                x1 = (ctx->cpx + 2 * ctx->params[0]) * (1.0 / 3.0);
                y1 = (ctx->cpy + 2 * ctx->params[1]) * (1.0 / 3.0);
                x3 = ctx->params[2];
                y3 = ctx->params[3];
                x2 = (x3 + 2 * ctx->params[0]) * (1.0 / 3.0);
                y2 = (y3 + 2 * ctx->params[1]) * (1.0 / 3.0);
                svg_vpath_curve_to(ctx->vpath, x1, y1, x2, y2, x3, y3);
                ctx->rpx = ctx->params[0];
                ctx->rpy = ctx->params[1];
                ctx->cpx = x3;
                ctx->cpy = y3;
                ctx->param = 0;
            }
            break;
        case 't':
            if (ctx->param == 2 || final)
            {
                float xc, yc;

                xc = 2 * ctx->cpx - ctx->rpx;
                yc = 2 * ctx->cpy - ctx->rpy;

                x1 = (ctx->cpx + 2 * xc) * (1.0 / 3.0);
                y1 = (ctx->cpy + 2 * yc) * (1.0 / 3.0);
                x3 = ctx->params[0];
                y3 = ctx->params[1];
                x2 = (x3 + 2 * xc) * (1.0 / 3.0);
                y2 = (y3 + 2 * yc) * (1.0 / 3.0);

                svg_vpath_curve_to(ctx->vpath, x1, y1, x2, y2, x3, y3);
                ctx->rpx = xc;
                ctx->rpy = yc;
                ctx->cpx = x3;
                ctx->cpy = y3;
                ctx->param = 0;
            }
            else if (final)
            {
                if (ctx->param > 2)
                {
                    svg_parse_path_prepare_xy(ctx, 4);

                    x1 = (ctx->cpx + 2 * ctx->params[0]) * (1.0 / 3.0);
                    y1 = (ctx->cpy + 2 * ctx->params[1]) * (1.0 / 3.0);
                    x3 = ctx->params[2];
                    y3 = ctx->params[3];
                    x2 = (x3 + 2 * ctx->params[0]) * (1.0 / 3.0);
                    y2 = (y3 + 2 * ctx->params[1]) * (1.0 / 3.0);

                    svg_vpath_curve_to(ctx->vpath, x1, y1, x2, y2, x3, y3);
                    ctx->rpx = ctx->params[0];
                    ctx->rpy = ctx->params[1];
                    ctx->cpx = x3;
                    ctx->cpy = y3;
                }
                else
                {
                    svg_parse_path_prepare_xy(ctx, 2);

                    svg_vpath_line_to(ctx->vpath, ctx->params[0], ctx->params[1]);
                    ctx->cpx = ctx->rpx = ctx->params[0];
                    ctx->cpy = ctx->rpy = ctx->params[1];
                }
                ctx->param = 0;
            }
            break;
        case 'a':
            if (ctx->param == 7 || final)
            {
                svg_vpath_arc_to(
                    ctx->vpath,
                    ctx->params[0],
                    ctx->params[1],
                    ctx->params[2],
                    (int)ctx->params[3],
                    (int)ctx->params[4],
                    ctx->params[5],
                    ctx->params[6]);
                ctx->cpx = ctx->params[5];
                ctx->cpy = ctx->params[6];
                ctx->param = 0;
            }
            break;
        default:
            ctx->param = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _svg_parse_path_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ctx         [?]     
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void _svg_parse_path_data(svg_path_cntx_t *ctx, char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    float val = 0;
    char c = 0;
    BOOL in_num = FALSE;
    BOOL in_frac = FALSE;
    BOOL in_exp = FALSE;
    BOOL exp_wait_sign = FALSE;
    int sign = 0;
    int exp = 0;
    int exp_sign = 0;
    float frac = 0.0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    in_num = FALSE;
    for (i = 0;; i++)
    {
        c = data[i];
        if (c >= '0' && c <= '9')
        {
            /* digit */
            if (in_num)
            {
                if (in_exp)
                {
                    exp = (exp * 10) + c - '0';
                    exp_wait_sign = FALSE;
                }
                else if (in_frac)
                {
                    val += (frac *= 0.1) * (c - '0');
                }
                else
                {
                    val = (val * 10) + c - '0';
                }
            }
            else
            {
                in_num = TRUE;
                in_frac = FALSE;
                in_exp = FALSE;
                exp = 0;
                exp_sign = 1;
                exp_wait_sign = FALSE;
                val = c - '0';
                sign = 1;
            }
        }
        else if (c == '.')
        {
            if (!in_num)
            {
                in_num = TRUE;
                val = 0;
            }
            in_frac = TRUE;
            frac = 1;
        }
        else if ((c == 'E' || c == 'e') && in_num)
        {
            in_exp = TRUE;
            exp_wait_sign = TRUE;
            exp = 0;
            exp_sign = 1;
        }
        else if ((c == '+' || c == '-') && in_exp)
        {
            exp_sign = c == '+' ? 1 : -1;
        }
        else if (in_num)
        {
            val *= sign * pow(10, exp_sign * exp);
            if (ctx->rel)
            {
                switch (ctx->cmd)
                {
                    case 'l':
                    case 'm':
                    case 'c':
                    case 's':
                    case 'q':
                    case 't':
                        /* rule: even-numbered params are x-relative, odd-numbered are y-relative */
                        if ((ctx->param & 1) == 0)
                        {
                            val += ctx->cpx;
                        }
                        else if ((ctx->param & 1) == 1)
                        {
                            val += ctx->cpy;
                        }
                        break;
                    case 'a':
                        /* rule: sixth and seventh are x and y, rest are not relative */
                        if (ctx->param == 5)
                        {
                            val += ctx->cpx;
                        }
                        else if (ctx->param == 6)
                        {
                            val += ctx->cpy;
                        }
                        break;
                    case 'h':
                        /* rule: x-relative */
                        val += ctx->cpx;
                        break;
                    case 'v':
                        /* rule: y-relative */
                        val += ctx->cpy;
                        break;
                }
            }
            ctx->params[ctx->param++] = val;
            _svg_parse_path_do_cmd(ctx, FALSE);
            in_num = FALSE;
        }

        if (c == '\0')
        {
            break;
        }
        else if ((c == '+' || c == '-') && !exp_wait_sign)
        {
            sign = c == '+' ? 1 : -1;;
            val = 0;
            in_num = TRUE;
            in_frac = FALSE;
            in_exp = FALSE;
            exp = 0;
            exp_sign = 1;
            exp_wait_sign = FALSE;
        }
        else if (c == 'z' || c == 'Z')
        {
            if (ctx->param)
            {
                _svg_parse_path_do_cmd(ctx, TRUE);
            }
            svg_vpath_close(ctx->vpath);

            ctx->cpx = ctx->rpx = ctx->vpath->path[ctx->vpath->len - 1].x;
            ctx->cpy = ctx->rpy = ctx->vpath->path[ctx->vpath->len - 1].y;
        }
        else if (c >= 'A' && c <= 'Z' && c != 'E')
        {
            if (ctx->param)
            {
                _svg_parse_path_do_cmd(ctx, TRUE);
            }
            ctx->cmd = c + 'a' - 'A';
            ctx->rel = FALSE;
        }
        else if (c >= 'a' && c <= 'z' && c != 'e')
        {
            if (ctx->param)
            {
                _svg_parse_path_do_cmd(ctx, TRUE);
            }
            ctx->cmd = c;
            ctx->rel = TRUE;
        }
        /* else c _should_ be whitespace or , */
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_parse_path_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path_str        [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_vpath_t *svg_parse_path_data(char *path_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_path_cntx_t ctx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctx.vpath = svg_vpath_new(5);
    ctx.cpx = 0.0;
    ctx.cpy = 0.0;
    ctx.cmd = 0;
    ctx.param = 0;

    _svg_parse_path_data(&ctx, path_str);

    if (ctx.param)
    {
        _svg_parse_path_do_cmd(&ctx, TRUE);
    }

    return ctx.vpath;
}


/*****************************************************************************
 * FUNCTION
 *  svg_parser_element_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret_element     [IN]        
 *  attr            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_parser_element_path(svg_element_t **ret_element, U8 **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = svg_element_create(ret_element, SVG_ELEMENT_TYPE_PATH);
    if (ret == SVG_OK)
    {
        svg_element_t *e = *ret_element;
        U8 *data;

        ret = svg_attr_get_string(attr, (U8*) "d", &data, (U8*) "");
        if (ret != SVG_OK)
        {
            svg_mem_free(e);
            return ret;
        }

        e->X.path.vpath = (void*)svg_parse_path_data((char*)data);

    }
    return ret;
}

#endif /* __MMI_SVG__ */ /* __SVG__ */

