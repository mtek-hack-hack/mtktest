#ifndef __SVG_H__
#define  __SVG_H__

#ifndef __XML_SUPPORT__
#error "You must turn on the XML libaray for support SVG"
#endif 

typedef enum
{
    SVG_FAIL_TIMEOUT = -14,
    SVG_FAIL_STACK_WILL_OVERFLOW = -13,
    SVG_FAIL_PARSER_FORMAT = -12,
    SVG_FAIL_WORK_BUFFER_RESIZE = -11,
    SVG_FAIL_HEX_FORMAT_ERROR = -10,
    SVG_FAIL_NUMBER_LIST_NOT_ENOUGH = -9,
    SVG_FAIL_TRANSFORM_FORMAT_ERROR = -8,
    SVG_FAIL_NO_STYLE = -7,
    SVG_FAIL_ATTR_NOT_FOUND = -6,
    SVG_FAIL_PARSER = -5,
    SVG_FAIL_BUSY = -4,
    SVG_FAIL_NOT_FOUND = -3,
    SVG_FAIL_NO_MEMORY = -2,
    SVG_FAIL = -1,
    SVG_OK = 0,
    SVG_HASH_REPLACE,

    __SVG_DUMMY__   /* this enum should not be used */
} svg_enum;

typedef U32 svg_handle; /* everything is svg_handle */

#define SVG_WORK_BUFFER_SIZE    (256*1024)
extern void svg_init(U32 *buffer, U32 buffer_size);
extern svg_enum svg_new(svg_handle *handle);
extern svg_enum svg_parse_file(svg_handle, U16 *filename);
extern svg_enum svg_draw(svg_handle handle, S32 x1, S32 y1, S32 x2, S32 y2);
extern svg_enum svg_draw_anim(svg_handle handle, S32 x1, S32 y1, S32 x2, S32 y2, void (*callback) (svg_enum result));
extern void svg_stop_draw_anim(void);
extern void svg_viewport_set(float tx, float ty, float scale, float angle);
extern void svg_viewport_reset(void);
extern svg_enum svg_get_dimension(svg_handle handle,S32 *width,S32 *height);
extern svg_enum svg_reset_anim(svg_handle handle, S32 x1, S32 y1, S32 x2, S32 y2, void (*callback) (svg_enum result));
extern svg_enum svg_draw_anim_single_frame(void);
#endif /* __SVG_H__ */ 

