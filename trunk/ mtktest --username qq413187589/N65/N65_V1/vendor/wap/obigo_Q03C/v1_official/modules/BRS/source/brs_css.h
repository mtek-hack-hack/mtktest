/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */








#ifndef _brs_css_h
#define _brs_css_h








#define BRS_CSS_PROP_BACKGROUND                       1
#define BRS_CSS_PROP_BACKGROUND_ATTACHMENT            2
#define BRS_CSS_PROP_BACKGROUND_COLOR                 3
#define BRS_CSS_PROP_BACKGROUND_IMAGE                 4
#define BRS_CSS_PROP_BACKGROUND_POSITION              5
#define BRS_CSS_PROP_BACKGROUND_REPEAT                6
#define BRS_CSS_PROP_BORDER                           7
#define BRS_CSS_PROP_BORDER_BOTTOM                    8
#define BRS_CSS_PROP_BORDER_BOTTOM_COLOR              9
#define BRS_CSS_PROP_BORDER_BOTTOM_STYLE              10
#define BRS_CSS_PROP_BORDER_BOTTOM_WIDTH              11
#define BRS_CSS_PROP_BORDER_COLLAPSE                  12
#define BRS_CSS_PROP_BORDER_COLOR                     13
#define BRS_CSS_PROP_BORDER_LEFT                      14
#define BRS_CSS_PROP_BORDER_LEFT_COLOR                15
#define BRS_CSS_PROP_BORDER_LEFT_STYLE                16
#define BRS_CSS_PROP_BORDER_LEFT_WIDTH                17
#define BRS_CSS_PROP_BORDER_RIGHT                     18
#define BRS_CSS_PROP_BORDER_RIGHT_COLOR               19
#define BRS_CSS_PROP_BORDER_RIGHT_STYLE               20
#define BRS_CSS_PROP_BORDER_RIGHT_WIDTH               21
#define BRS_CSS_PROP_BORDER_SPACING                   22
#define BRS_CSS_PROP_BORDER_STYLE                     23
#define BRS_CSS_PROP_BORDER_TOP                       24
#define BRS_CSS_PROP_BORDER_TOP_COLOR                 25
#define BRS_CSS_PROP_BORDER_TOP_STYLE                 26
#define BRS_CSS_PROP_BORDER_TOP_WIDTH                 27
#define BRS_CSS_PROP_BORDER_WIDTH                     28
#define BRS_CSS_PROP_CAPTION_SIDE                     29
#define BRS_CSS_PROP_CLEAR                            30
#define BRS_CSS_PROP_COLOR                            31
#define BRS_CSS_PROP_DISPLAY                          32
#define BRS_CSS_PROP_EMPTY_CELLS                      33
#define BRS_CSS_PROP_FLOAT                            34
#define BRS_CSS_PROP_FONT                             35
#define BRS_CSS_PROP_FONT_FAMILY                      36
#define BRS_CSS_PROP_FONT_SIZE                        37
#define BRS_CSS_PROP_FONT_STYLE                       38
#define BRS_CSS_PROP_FONT_VARIANT                     39
#define BRS_CSS_PROP_FONT_WEIGHT                      40
#define BRS_CSS_PROP_HEIGHT                           41
#define BRS_CSS_PROP_LINE_HEIGHT                      42
#define BRS_CSS_PROP_LIST_STYLE                       43
#define BRS_CSS_PROP_LIST_STYLE_IMAGE                 44
#define BRS_CSS_PROP_LIST_STYLE_POSITION              45
#define BRS_CSS_PROP_LIST_STYLE_TYPE                  46
#define BRS_CSS_PROP_MARGIN                           47
#define BRS_CSS_PROP_MARGIN_BOTTOM                    48
#define BRS_CSS_PROP_MARGIN_LEFT                      49
#define BRS_CSS_PROP_MARGIN_RIGHT                     50
#define BRS_CSS_PROP_MARGIN_TOP                       51
#define BRS_CSS_PROP_MAX_WIDTH                        52
#define BRS_CSS_PROP_PADDING                          53
#define BRS_CSS_PROP_PADDING_BOTTOM                   54
#define BRS_CSS_PROP_PADDING_LEFT                     55
#define BRS_CSS_PROP_PADDING_RIGHT                    56
#define BRS_CSS_PROP_PADDING_TOP                      57
#define BRS_CSS_PROP_TABLE_LAYOUT                     58
#define BRS_CSS_PROP_TEXT_ALIGN                       59
#define BRS_CSS_PROP_TEXT_DECORATION                  60
#define BRS_CSS_PROP_TEXT_INDENT                      61
#define BRS_CSS_PROP_TEXT_TRANSFORM                   62
#define BRS_CSS_PROP_VERTICAL_ALIGN                   63
#define BRS_CSS_PROP_VISIBILITY                       64
#define BRS_CSS_PROP_WHITE_SPACE                      65
#define BRS_CSS_PROP_WIDTH                            66
#define BRS_CSS_PROP__WAP_ACCESSKEY                   67
#define BRS_CSS_PROP__WAP_INPUT_FORMAT                68
#define BRS_CSS_PROP__WAP_INPUT_REQUIRED              69
#define BRS_CSS_PROP__WAP_MARQUEE_DIR                 70
#define BRS_CSS_PROP__WAP_MARQUEE_LOOP                71
#define BRS_CSS_PROP__WAP_MARQUEE_SPEED               72
#define BRS_CSS_PROP__WAP_MARQUEE_STYLE               73
#define BRS_CSS_PROP___PCS_INPUT_MODE                 74


#define BRS_CSS_NO_PROPERTIES                         74




#define BRS_CSS_VALUE_ALTERNATE                       1
#define BRS_CSS_VALUE_AQUA                            2
#define BRS_CSS_VALUE_AUTO                            3
#define BRS_CSS_VALUE_BASELINE                        4
#define BRS_CSS_VALUE_BLACK                           5
#define BRS_CSS_VALUE_BLINK                           6
#define BRS_CSS_VALUE_BLOCK                           7
#define BRS_CSS_VALUE_BLUE                            8
#define BRS_CSS_VALUE_BOLD                            9
#define BRS_CSS_VALUE_BOLDER                          10
#define BRS_CSS_VALUE_BOTH                            11
#define BRS_CSS_VALUE_BOTTOM                          12
#define BRS_CSS_VALUE_CAPITALIZE                      13
#define BRS_CSS_VALUE_CAPTION                         14
#define BRS_CSS_VALUE_CENTER                          15
#define BRS_CSS_VALUE_CIRCLE                          16
#define BRS_CSS_VALUE_COLLAPSE                        17
#define BRS_CSS_VALUE_CURSIVE                         18
#define BRS_CSS_VALUE_DASHED                          19
#define BRS_CSS_VALUE_DECIMAL                         20
#define BRS_CSS_VALUE_DISC                            21
#define BRS_CSS_VALUE_DOTTED                          22
#define BRS_CSS_VALUE_DOUBLE                          23
#define BRS_CSS_VALUE_FALSE                           24
#define BRS_CSS_VALUE_FANTASY                         25
#define BRS_CSS_VALUE_FAST                            26
#define BRS_CSS_VALUE_FIXED                           27
#define BRS_CSS_VALUE_FUCHSIA                         28
#define BRS_CSS_VALUE_GRAY                            29
#define BRS_CSS_VALUE_GREEN                           30
#define BRS_CSS_VALUE_GROOVE                          31
#define BRS_CSS_VALUE_HIDDEN                          32
#define BRS_CSS_VALUE_HIDE                            33
#define BRS_CSS_VALUE_ICON                            34
#define BRS_CSS_VALUE_INFINITE                        35
#define BRS_CSS_VALUE_INHERIT                         36
#define BRS_CSS_VALUE_INLINE                          37
#define BRS_CSS_VALUE_INSET                           38
#define BRS_CSS_VALUE_INSIDE                          39
#define BRS_CSS_VALUE_ITALIC                          40
#define BRS_CSS_VALUE_JUSTIFY                         41
#define BRS_CSS_VALUE_LARGE                           42
#define BRS_CSS_VALUE_LARGER                          43
#define BRS_CSS_VALUE_LEFT                            44
#define BRS_CSS_VALUE_LIGHTER                         45
#define BRS_CSS_VALUE_LIME                            46
#define BRS_CSS_VALUE_LIST_ITEM                       47
#define BRS_CSS_VALUE_LOWERCASE                       48
#define BRS_CSS_VALUE_LOWER_ALPHA                     49
#define BRS_CSS_VALUE_LOWER_ROMAN                     50
#define BRS_CSS_VALUE_LTR                             51
#define BRS_CSS_VALUE_MAROON                          52
#define BRS_CSS_VALUE_MEDIUM                          53
#define BRS_CSS_VALUE_MENU                            54
#define BRS_CSS_VALUE_MESSAGE_BOX                     55
#define BRS_CSS_VALUE_MIDDLE                          56
#define BRS_CSS_VALUE_MONOSPACE                       57
#define BRS_CSS_VALUE_NAVY                            58
#define BRS_CSS_VALUE_NONE                            59
#define BRS_CSS_VALUE_NORMAL                          60
#define BRS_CSS_VALUE_NOWRAP                          61
#define BRS_CSS_VALUE_NO_REPEAT                       62
#define BRS_CSS_VALUE_OBLIQUE                         63
#define BRS_CSS_VALUE_OLIVE                           64
#define BRS_CSS_VALUE_OUTSET                          65
#define BRS_CSS_VALUE_OUTSIDE                         66
#define BRS_CSS_VALUE_PRE                             67
#define BRS_CSS_VALUE_PURPLE                          68
#define BRS_CSS_VALUE_RED                             69
#define BRS_CSS_VALUE_REPEAT                          70
#define BRS_CSS_VALUE_REPEAT_X                        71
#define BRS_CSS_VALUE_REPEAT_Y                        72
#define BRS_CSS_VALUE_RIDGE                           73
#define BRS_CSS_VALUE_RIGHT                           74
#define BRS_CSS_VALUE_RTL                             75
#define BRS_CSS_VALUE_SANS_SERIF                      76
#define BRS_CSS_VALUE_SCROLL                          77
#define BRS_CSS_VALUE_SEPARATE                        78
#define BRS_CSS_VALUE_SERIF                           79
#define BRS_CSS_VALUE_SHOW                            80
#define BRS_CSS_VALUE_SILVER                          81
#define BRS_CSS_VALUE_SLIDE                           82
#define BRS_CSS_VALUE_SLOW                            83
#define BRS_CSS_VALUE_SMALL                           84
#define BRS_CSS_VALUE_SMALLER                         85
#define BRS_CSS_VALUE_SMALL_CAPS                      86
#define BRS_CSS_VALUE_SMALL_CAPTION                   87
#define BRS_CSS_VALUE_SOLID                           88
#define BRS_CSS_VALUE_SQUARE                          89
#define BRS_CSS_VALUE_STATUS_BAR                      90
#define BRS_CSS_VALUE_SUB                             91
#define BRS_CSS_VALUE_SUPER                           92
#define BRS_CSS_VALUE_TEAL                            93
#define BRS_CSS_VALUE_THICK                           94
#define BRS_CSS_VALUE_THIN                            95
#define BRS_CSS_VALUE_TOP                             96
#define BRS_CSS_VALUE_TRANSPARENT                     97
#define BRS_CSS_VALUE_TRUE                            98
#define BRS_CSS_VALUE_UNDERLINE                       99
#define BRS_CSS_VALUE_UPPERCASE                       100
#define BRS_CSS_VALUE_UPPER_ALPHA                     101
#define BRS_CSS_VALUE_UPPER_ROMAN                     102
#define BRS_CSS_VALUE_VISIBLE                         103
#define BRS_CSS_VALUE_WHITE                           104
#define BRS_CSS_VALUE_XX_LARGE                        105
#define BRS_CSS_VALUE_XX_SMALL                        106
#define BRS_CSS_VALUE_X_LARGE                         107
#define BRS_CSS_VALUE_X_SMALL                         108
#define BRS_CSS_VALUE_YELLOW                          109
#define BRS_CSS_VALUE__OBIGO_INSIDE_SCROLL            110
#define BRS_CSS_VALUE__WAP_MARQUEE                    115
#define BRS_CSS_VALUE__HTML_MIDDLE                    116




#define BRS_CSS_VALUE_TYPE_KEYWORD                    1
#define BRS_CSS_VALUE_TYPE_NUMBER                     2
#define BRS_CSS_VALUE_TYPE_PERCENTAGE                 3
#define BRS_CSS_VALUE_TYPE_EMS                        4
#define BRS_CSS_VALUE_TYPE_EXS                        5
#define BRS_CSS_VALUE_TYPE_LENGTH_PX                  6
#define BRS_CSS_VALUE_TYPE_LENGTH_CM                  7
#define BRS_CSS_VALUE_TYPE_LENGTH_MM                  8
#define BRS_CSS_VALUE_TYPE_LENGTH_IN                  9
#define BRS_CSS_VALUE_TYPE_LENGTH_PT                  10
#define BRS_CSS_VALUE_TYPE_LENGTH_PC                  11
#define BRS_CSS_VALUE_TYPE_ANGLE_DEG                  12
#define BRS_CSS_VALUE_TYPE_ANGLE_RAD                  13
#define BRS_CSS_VALUE_TYPE_ANGLE_GRAD                 14
#define BRS_CSS_VALUE_TYPE_TIME_MS                    15
#define BRS_CSS_VALUE_TYPE_TIME_S                     16
#define BRS_CSS_VALUE_TYPE_FREQ_HZ                    17
#define BRS_CSS_VALUE_TYPE_FREQ_KHZ                   18
#define BRS_CSS_VALUE_TYPE_RGB                        19
#define BRS_CSS_VALUE_TYPE_STRING                     20
#define BRS_CSS_VALUE_TYPE_URI                        21
#define BRS_CSS_VALUE_TYPE_IDENTIFIER                 22
#define BRS_CSS_VALUE_TYPE_DEFAULT                    23





#define BRS_CSS_FLAG_LINK                             0x01
#define BRS_CSS_FLAG_VISITED                          0x02
#define BRS_CSS_FLAG_ACTIVE                           0x04
#define BRS_CSS_FLAG_FOCUS                            0x08
#define BRS_CSS_FLAG_HOVER                            0x10
#define BRS_CSS_FLAG_MARQUEE                          0x20





typedef struct {
  int         type;     
  union {
    long int                           i;
    float                              f;
    char                              *s;
    struct { unsigned char r, g, b; }  c;  
  } _u;
} brs_css_value_t;

typedef struct {
  int             num_values;
  brs_css_value_t value[1];           
} brs_css_value_array_t;

typedef struct {
  int                    property;    
  int                    flags;       
  brs_css_value_array_t *values;
} brs_css_property_t;

typedef struct {
  int                element_id;
  int                parent_id;

  int                num_properties;
  brs_css_property_t property[1]; 
} brs_css_style_info_t;

#endif
