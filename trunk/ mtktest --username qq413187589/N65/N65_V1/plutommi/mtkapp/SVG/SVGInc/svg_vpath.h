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
#ifndef _SVG_VPATH_H
#define _SVG_VPATH_H

typedef struct
{
    svg_pos_t *path;
    float path_length; /* only used for animate path */
    U16 len;
    U16 max_len;
    U16 segments;
    S16 open_index;     /* point to the open curve point */

} svg_vpath_t;

enum
{
    SVG_PATH_MOVE_TO,
    SVG_PATH_LINE_TO
};

//#define VPATH_IS_MOVETO(POS,LEN,N)            ((N+1==LEN)?FALSE:(POS[N].x == POS[N+1].x && POS[N].y == POS[N+1].y))
//#define VPATH_IS_LINETO(POS,LEN,N)            ((N+1==LEN)?TRUE :(POS[N].x != POS[N+1].x  || POS[N].y != POS[N+1].y))
#define VPATH_IS_MOVETO(POS,LEN,N)     (  (N>0&&POS[N-1].x==POS[N].x&& POS[N-1].y==POS[N].y) \
                              ||(N<LEN-1&&POS[N+1].x==POS[N].x&& POS[N+1].y==POS[N].y))
#define VPATH_IS_LINETO(POS,LEN,N)     (!VPATH_IS_MOVETO(POS,LEN,N))

extern svg_vpath_t *svg_vpath_new(U32 max_items);
extern void svg_vpath_free(svg_vpath_t *vpath);
extern svg_enum svg_vpath_enlarge(svg_vpath_t *vpath);
extern svg_vpath_t *svg_vpath_dup(svg_vpath_t *src);
extern svg_enum svg_vpath_append(svg_vpath_t *vpath, U8 cmd, float x, float y);
extern svg_enum svg_vpath_move_to(svg_vpath_t *vpath, float x, float y);
extern svg_enum svg_vpath_line_to(svg_vpath_t *vpath, float x, float y);
extern svg_enum svg_vpath_close(svg_vpath_t *vpath);
extern svg_enum svg_vpath_transform(svg_vpath_t *vpath, float transform[6]);
extern svg_enum svg_vpath_curve_to(
                    svg_vpath_t *vpath,
                    float x0,
                    float y0,
                    float x1,
                    float y1,
                    float x2,
                    float y2);
extern void svg_vpath_arc_to(
                svg_vpath_t *vpath,
                float rx,
                float ry,
                float x_axis_rotation,
                int large_arc_flag,
                int sweep_flag,
                float x,
                float y);
extern svg_enum svg_vpath_update_length(svg_vpath_t *vpath);

extern svg_enum svg_vpath_interpolation(
                    svg_animate_motion_type_enum type,
                    float xy[2],
                    float *rotate,
                    svg_vpath_t *vpath,
                    svg_animate_calc_mode_enum calc_mode,
                    U8 *keysplines,
                    U8 *keytimes,
                    float current_time,
                    float total_time);
extern svg_vpath_t *svg_vpath_to_dash(svg_vpath_t *vpath, svg_dash_t *dash);
extern svg_vpath_t *svg_vpath_to_close_vpath(svg_vpath_t *src);

#endif /* _SVG_VPATH_H */ 

