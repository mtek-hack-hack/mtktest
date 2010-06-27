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
#ifndef _SVG_ATTRIBUTE_H
#define _SVG_ATTRIBUTE_H

typedef enum
{
    SVG_UNIT_CM,
    SVG_UNIT_EM,
    SVG_UNIT_EX,
    SVG_UNIT_IN,
    SVG_UNIT_MM,
    SVG_UNIT_PC,
    SVG_UNIT_PCT,
    SVG_UNIT_PT,
    SVG_UNIT_PX
} svg_unit_enum;

typedef struct svg_view_box
{
    float x, y, width, height;
} svg_view_box_t;

extern svg_enum svg_to_length_internal(float *length, U8 *data, BOOL is_width, U8 **data_used);
extern svg_enum svg_attr_get_string(U8 **attributes, U8 *name, U8 **value, U8 *default_value);
extern svg_enum svg_attr_get_length(float *length, U8 **attributes, U8 *name, U8 *default_value, BOOL is_width);
extern svg_enum svg_attr_get_viewbox(svg_view_box_t *view_box, U8 **attributes, U8 *name, U8 *default_value);
extern U32 svg_attr_get_number_list(float list[], U32 list_len, U8 *data);
extern U32 svg_attr_get_string_list(U8 *list[], U32 list_len, U8 *data);
extern svg_enum svg_attr_get_clock_value(float *seconds, U8 **attributes, U8 *name, U8 *default_value);
extern svg_enum svg_interpolation_values(
                    float *ret,
                    U8 *data,
                    BOOL is_width,
                    svg_animate_calc_mode_enum calc_mode,
                    U8 *keysplines,
                    U8 *keytimes,
                    float current_time,
                    float total_time);
extern int svg_interpolation_from_to(
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
            float total_time);
extern float svg_interpolation_value_via_keyspline(
                float low,
                float high,
                float t,
                float x1,
                float y1,
                float x2,
                float y2);
extern svg_enum svg_get_xy_from_keyspline(float *x1, float *y1, float *x2, float *y2, int segment, U8 *data);

extern svg_enum svg_to_length(float *length, U8 *data, BOOL is_width);
extern svg_enum svg_to_clock_value(float *seconds, U8 *data);
extern svg_enum svg_to_xy_length(float xy[], U8 *data);
#endif /* _SVG_ATTRIBUTE_H */ 

