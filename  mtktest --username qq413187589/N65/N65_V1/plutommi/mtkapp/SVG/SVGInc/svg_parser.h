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
#ifndef _SVG_PARSER_H
#define _SVG_PARSER_H

typedef svg_enum(*svg_parser_element_func) (svg_element_t **ret_element, U8 **attr);
typedef svg_enum(*svg_parser_data_func) (svg_element_t *element, U8 *data, U32 len);

typedef struct
{
    char *tag;
    svg_parser_element_func parse_element;
    svg_parser_data_func parse_data;
    BOOL need_add_to_render_tree;
} svg_parser_table_t;

extern void svg_parser_container_list_create(void);
extern void svg_parser_container_list_free(void);
extern void svg_parser_container_push(svg_element_t *container);
extern svg_element_t *svg_parser_container_pop(void);
extern svg_element_t *svg_parser_container_top(void);

extern void svg_read_start_element(void *data, const char *el, const char **attr, S32 error);
extern void svg_read_end_element(void *data, const char *el, S32 error);
extern void svg_read_data_element(void *data, const char *el, const char *value, int len, S32 error);

extern svg_vpath_t *svg_parse_path_data(char *path_str);

extern svg_enum svg_parser_element_svg(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_group(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_rect(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_line(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_path(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_animate(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_defs(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_font(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_font_face(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_missing_glyph(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_glyph(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_text(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_text_data(svg_element_t *element, U8 *data, U32 len);
extern svg_enum svg_parser_element_image(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_animate_motion(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_mpath(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_circle(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_polygon(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_hkern(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_ellipse(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_polyline(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_switch(svg_element_t **ret_element, U8 **attr);
extern svg_enum svg_parser_element_use(svg_element_t **ret_element, U8 **attr);

extern void svg_parser_init(void);
extern svg_enum svg_style_parser(svg_style_t **ret_style, U8 **attr);
extern U8 *svg_style_font_weight(U8 *value, U8 *inherit_str);
extern U8 *svg_style_font_weight(U8 *value, U8 *inherit_str);
extern void svg_parser_element_animate_attributes(svg_element_t *e, U8 **attr);
extern svg_enum svg_style_parse_color(U32 *color, U8 *str);
#endif /* _SVG_PARSER_H */ 

