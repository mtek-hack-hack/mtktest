#ifndef __SVG_INTERNAL_H__
#define  __SVG_INTERNAL_H__

#define SVG_ASSERT(exp)       ASSERT(exp)
#ifndef __PRODUCTION_RELEASE__
#define SVG_DEBUG_ASSERT(exp) ASSERT(exp)
#else 
#define SVG_DEBUG_ASSERT(exp)
#endif 

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "setjmp.h"

#define M_PI 3.14159265358979323846

typedef enum
{
    SVG_ELEMENT_TYPE_SVG,
    SVG_ELEMENT_TYPE_GROUP,
    SVG_ELEMENT_TYPE_DEFS,
    SVG_ELEMENT_TYPE_USE,
    SVG_ELEMENT_TYPE_SYMBOL,
    SVG_ELEMENT_TYPE_PATH,
    SVG_ELEMENT_TYPE_CIRCLE,
    SVG_ELEMENT_TYPE_ELLIPSE,
    SVG_ELEMENT_TYPE_LINE,
    SVG_ELEMENT_TYPE_RECT,
    SVG_ELEMENT_TYPE_TEXT,
    SVG_ELEMENT_TYPE_GRADIENT,
    SVG_ELEMENT_TYPE_GRADIENT_STOP,
    SVG_ELEMENT_TYPE_PATTERN,
    SVG_ELEMENT_TYPE_IMAGE,
    SVG_ELEMENT_TYPE_ANIMATE,
    SVG_ELEMENT_TYPE_ANIMATE_MOTION,
    SVG_ELEMENT_TYPE_FONT,
    SVG_ELEMENT_TYPE_GLYPH,
    SVG_ELEMENT_TYPE_POLYGON,
    SVG_ELEMENT_TYPE_SWITCH,
    SVG_ELEMENT_TYPE_END
} svg_element_type;

typedef enum
{
    SVG_ANIMATE_DISCRETE,
    SVG_ANIMATE_LINEAR,
    SVG_ANIMATE_PACED,
    SVG_ANIMATE_SPLINE
} svg_animate_calc_mode_enum;

typedef enum
{
    SVG_VAR_TYPE_WIDTH,
    SVG_VAR_TYPE_HEIGHT,
    SVG_VAR_TYPE_CLOCK,
    SVG_VAR_TYPE_VIEWBOX,
    SVG_VAR_TYPE_FONT_SIZE,
    SVG_VAR_TYPE_COLOR,
    SVG_VAR_TYPE_XY,
    SVG_VAR_TYPE_TRANSFORM
} svg_variable_flag_enum;

typedef enum
{
    SVG_ANIMATE_MOTION_NONE,
    SVG_ANIMATE_MOTION_PATH,
    SVG_ANIMATE_MOTION_SEGMENT,
    SVG_ANIMATE_MOTION_REF
} svg_animate_motion_type_enum;

typedef enum
{
    SVG_ANIMATE_MOTION_ROTATE_NONE,
    SVG_ANIMATE_MOTION_ROTATE,
    SVG_ANIMATE_MOTION_ROTATE_REVERSE
} svg_animate_motion_rotate_enum;

typedef enum
{
    SVG_TRANSFORM_TYPE_NONE,
    SVG_TRANSFORM_TYPE_TRANSLATE,
    SVG_TRANSFORM_TYPE_SCALE,
    SVG_TRANSFORM_TYPE_ROTATE,
    SVG_TRANSFORM_TYPE_SKEWX,
    SVG_TRANSFORM_TYPE_SKEWY
} svg_transform_type_enum;

#define SVG_TREE_MAX_DEPTH 64

extern jmp_buf svg_jmpbuf;
extern BOOL svg_jmpbuf_is_used;

#define SVG_RAISE(ret_code)   longjmp (svg_jmpbuf, ret_code)
#define SVG_TRY                       \
   {                                  \
      int jmpret;                     \
      SVG_ASSERT(!svg_jmpbuf_is_used);\
      svg_jmpbuf_is_used = TRUE;      \
      jmpret = setjmp (svg_jmpbuf);   \
      if(jmpret == 0 )                \
      {

#define SVG_CATCH_BEGIN \
      }                 \
      else              \
      {                 \
         {

#define SVG_CATCH_END            \
         }                       \
      }                          \
      svg_jmpbuf_is_used = FALSE;\
   }

#define SVG_CATCH(N) if(jumpret == N)

#define SVG_CLIP_TWO_RECT(X1, Y1, X2, Y2,CX1,CY1,CX2,CY2,NULL_ACTION)\
{                                                                    \
   if(X1 > X2) { NULL_ACTION; }                                      \
   else if(Y1 > Y2)  { NULL_ACTION; }                                \
   else if(X2 < CX1) { NULL_ACTION; }                                \
   else if(Y2 < CY1) { NULL_ACTION; }                                \
   else if(X1 > CX2) { NULL_ACTION; }                                \
   else if(Y1 > CY2) { NULL_ACTION; }                                \
   else                                                              \
   {                                                                 \
      if(X1 < CX1) { X1 = CX1; }                                     \
      if(Y1 < CY1) { Y1 = CY1; }                                     \
      if(X2 > CX2) { X2 = CX2; }                                     \
      if(Y2 > CY2) { Y2 = CY2; }                                     \
   }                                                                 \
}

#include "svg.h"
#include "svg_smalloc.h"
#include "svg_hash.h"
#include "svg_attribute.h"
#include "svg_style.h"
#include "svg_util.h"

typedef struct
{
    float x;
    float y;
} svg_pos_t;

typedef struct
{
    float width;
    float height;
    float x;
    float y;
    svg_view_box_t view_box;
} svg_element_group_t;

typedef struct
{
    float width;
    float height;
    float x;
    float y;
    float rx;
    float ry;
} svg_element_rect_t;

typedef struct
{
    float x1, y1, x2, y2;
} svg_element_line_t;

typedef struct
{
    float cx, cy, r;
} svg_element_circle_t;

typedef struct
{
    float cx, cy, rx, ry;
} svg_element_ellipse_t;

typedef struct
{
    float x, y, width, height;
    U8 *src;
    U32 src_len;
    U8 src_type;
    BOOL is_from_file;
} svg_element_image_t;

typedef struct
{
    void *vpath;
} svg_element_path_t;

typedef struct
{
    U8 *attribute_name;
    U8 *from;
    U8 *to;
    U8 *begin;
    U8 *end;
    U8 *by;
    U8 *values;
    U8 *path_data;
    U8 *keysplines;
    U8 *keytimes;
    float dur;             /* unit: seconds */
    float repeat_count;    /* 0 : means repeat forever */
    svg_animate_calc_mode_enum calc_mode;
    BOOL is_additive_sum;
    BOOL is_accumulate;
    BOOL is_freeze;
    void *variable_address;
    svg_variable_flag_enum variable_flag;
    void *object;           /* animate object */

    svg_animate_motion_type_enum motion_path_type;
    void *motion_path;  /* for animateMtion used */
    svg_animate_motion_rotate_enum motion_rotate;

    svg_transform_type_enum tramsform_type;

} svg_element_animate_t;

typedef struct
{
    float units_per_em;
    float ascent;
    float descent;
    float horiz_origin_x;
    float horiz_origin_y;
    float horiz_adv_x;

    float vert_origin_x;
    float vert_origin_y;
    float vert_adv_y;
    U8 *font_family;
    void *miss_glyph;
    svg_hash_t *glyph_name_hash;    /* key "glyph_name" value "glyph object" */
    svg_hash_t *glyph_hash;         /* key "unicode" value "glyph object" */
    svg_hash_t *hkern_hash;         /* key "Unicode1Unicode2" value "k" */
} svg_element_font_t;

typedef struct
{
    U8 *name;
    U8 *ucs2;
    U8 *path_data;
    float horiz_origin_x;
    float horiz_origin_y;
    float horiz_adv_x;

    float vert_origin_x;
    float vert_origin_y;
    float vert_adv_y;
} svg_element_glyph_t;

typedef struct
{
    float x;
    float y;
    U8 *data;
    U32 data_len;
} svg_element_text_t;

typedef struct
{
    void *vpath;
} svg_element_polygon_t;

typedef struct
{
    BOOL can_be_execute;
} svg_element_switch_t;

typedef struct
{
    U8 *ref;
    float x;
    float y;
} svg_element_use_t;

typedef union
{
    svg_element_group_t group;
    svg_element_rect_t rect;
    svg_element_line_t line;
    svg_element_path_t path;
    svg_element_animate_t animate;
    svg_element_font_t font;
    svg_element_glyph_t glyph;
    svg_element_text_t text;
    svg_element_image_t image;
    svg_element_circle_t circle;
    svg_element_polygon_t polygon;
    svg_element_ellipse_t ellipse;
    svg_element_switch_t sw;
    svg_element_use_t use;
} svg_element_internal_t;

typedef struct svg_element_t
{
    struct svg_element_t *child;
    struct svg_element_t *sib;

    U8 *id;
    svg_element_type type;
    svg_style_t *style;
    float animate_transform[6];    /* for animateMotion used */
    U32 animate_transform_serial;

    svg_element_internal_t X;
} svg_element_t;

typedef struct
{
    S32 output_x1, output_y1, output_x2, output_y2, output_width, output_height;
    svg_style_t style;
    float predefine_transform[6];
    float viewport_x, viewport_y, viewport_scale, viewport_rotate;

    U16 current_path[512];
    U32 current_serial;
    U32 current_tick;
    float current_time;
    U32    virtual_time;    /* show each frame will increment 0.5 seconds */
    float max_end_time;    /* <0 means loop forever */
    float dpi_x, dpi_y;
    float font_size;
    float units_per_em;
    float width;
    float height;
    float x;
    float y;

    svg_element_t *root;
    svg_hash_t *elements;
    svg_hash_t *styles;
    svg_hash_t *font_family;
    void (*render_callback) (svg_enum result);

    /* only be render temp variables */
    U32 render_color;
    int render_bounds[4];

} svg_t;

extern svg_t *svg_context;  /* current svg */

extern svg_enum svg_check_stack_overflow(void);
#endif /* __SVG_INTERNAL_H__ */ 

