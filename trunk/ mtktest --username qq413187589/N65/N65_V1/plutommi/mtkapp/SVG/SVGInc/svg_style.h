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
#ifndef _SVG_STYLE_H
#define _SVG_STYLE_H

#define SVG_STYLE_FLAG_FONT_SIZE       (1<<0)
#define SVG_STYLE_FLAG_TRANSFORM       (1<<1)
#define SVG_STYLE_FLAG_COLOR           (1<<2)
#define SVG_STYLE_FLAG_FILL            (1<<3)
#define SVG_STYLE_FLAG_STROKE_SIZE     (1<<4)
#define SVG_STYLE_FLAG_STROKE_COLOR    (1<<5)
#define SVG_STYLE_FLAG_FONT_FAMILY     (1<<6)
#define SVG_STYLE_FLAG_FILL_RULE_EVENODD  (1<<7)
#define SVG_STYLE_FLAG_LINE_JOIN       (1<<8)
#define SVG_STYLE_FLAG_LINE_CAP        (1<<9)
#define SVG_STYLE_FLAG_LINE_MITER_LIMIT   (1<<10)
#define SVG_STYLE_FLAG_STROKE_DASH     (1<<11)
#define SVG_STYLE_FLAG_FONT_WEIGHT     (1<<12)
#define SVG_STYLE_FLAG_SWITCH_FAIL     (1<<13)
#define SVG_STYLE_FLAG_TEXT_ANCHOR      (1<<14)

typedef enum
{
    SVG_TEXT_ANCHOR_START,
    SVG_TEXT_ANCHOR_MIDDLE,
    SVG_TEXT_ANCHOR_END
} svg_text_anchor_enum;

typedef enum
{
    SVG_STROKE_JOIN_MITER,
    SVG_STROKE_JOIN_ROUND,
    SVG_STROKE_JOIN_BEVEL
} svg_join_enum;

typedef enum
{
    SVG_STROKE_CAP_BUTT,
    SVG_STROKE_CAP_ROUND,
    SVG_STROKE_CAP_SQUARE
} svg_cap_enum;

typedef enum
{
    SVG_COLOR_TYPE_HWRGB,
    SVG_COLOR_TYPE_USING_CURRENT_COLOR,
    SVG_COLOR_TYPE_NONE
} svg_color_type_enum;

typedef struct
{
    float offset;
    U32 n;
    float *list;
} svg_dash_t;

typedef struct
{
    U32 flag;
    U32 color;
    U32 fill_color;
    U32 stroke_color;
    float font_size;
    float transform[6];
    float stroke_size;
    float miter_limit;
    U8 *font_family;
    U8 *font_weight;
    svg_text_anchor_enum text_anchor;
    svg_join_enum join;
    svg_cap_enum cap;
    svg_color_type_enum fill_color_type;
    svg_color_type_enum stroke_color_type;
    svg_dash_t dash;
} svg_style_t;

#endif /* _SVG_STYLE_H */ 

