#ifndef _CMS_CSS_H_
#define _CMS_CSS_H_


/* 定义四个方向的CSS属性值：top_width, top_color, top_style....*/
#define CMS_CSS_TOP		0
#define	CMS_CSS_RIGHT	1
#define CMS_CSS_BOTTOM	2
#define CMS_CSS_LEFT	3


typedef unsigned int colour;
//typedef unsigned char FontType_t;
#ifndef FontType_t
#define FontType_t unsigned char
#endif
// Modified by TIPrj[2005/6/29]


//font-family
typedef enum {
	
	CSS_FONT_FAMILY_INHERIT = 0,

	CSS_FONT_FAMILY_CURSIVE,
	CSS_FONT_FAMILY_FANTASY,
	CSS_FONT_FAMILY_MONOSPACE,
	CSS_FONT_FAMILY_SERIF,
	CSS_FONT_FAMILY_SANS_SERIF,
	CSS_FONT_FAMILY_SONG_TI
	//add more if needed

} CSS_FONT_FAMILY;

//font-style
typedef enum {
	
	CSS_FONT_STYLE_INHERIT = 0,

	CSS_FONT_STYLE_NORMAL,
	CSS_FONT_STYLE_ITALIC,
	CSS_FONT_STYLE_OBLIQUE	

} CSS_FONT_STYLE;

//font-variant
typedef enum {
	
	CSS_FONT_VARIANT_INHERIT = 0,
	CSS_FONT_VARIANT_NORMAL,
	CSS_FONT_VARIANT_SMALL_CAPS
		
} CSS_FONT_VARIANT;

//font-weight
typedef enum {

	CSS_FONT_WEIGHT_INHERIT = 0,

	CSS_FONT_WEIGHT_NORMAL,
	CSS_FONT_WEIGHT_BOLD,
	CSS_FONT_WEIGHT_BOLDER,
	CSS_FONT_WEIGHT_LIGHTER,
	CSS_FONT_WEIGHT_100,
	CSS_FONT_WEIGHT_200,
	CSS_FONT_WEIGHT_300,
	CSS_FONT_WEIGHT_400,
	CSS_FONT_WEIGHT_500,
	CSS_FONT_WEIGHT_600,
	CSS_FONT_WEIGHT_700,
	CSS_FONT_WEIGHT_800,
	CSS_FONT_WEIGHT_900

} CSS_FONT_WEIGHT;


//text-align:
typedef enum {

	CSS_TEXT_ALIGH_INHERIT = 0,

	CSS_TEXT_ALIGH_LEFT,
	CSS_TEXT_ALIGH_RIGHT,
	CSS_TEXT_ALIGH_CENTER,
	CSS_TEXT_ALIGH_JUSTIFY

}	CSS_TEXT_ALIGH;

//text-decoration:
typedef enum {
	CSS_TEXT_DECORATION_INHERIT = 0,
	
	CSS_TEXT_DECORATION_NONE,
	CSS_TEXT_DECORATION_UNDERLINE,
	CSS_TEXT_DECORATION_OVERLINE,
	CSS_TEXT_DECORATION_LINE_THROUGH,
	CSS_TEXT_DECORATION_BLINK

}	CSS_TEXT_DECORATION;

//text-spacing:
typedef enum{
	CSS_TEXT_SPACE_TYPE_INHERIT = 0,

	CSS_TEXT_SPACE_TYPE_NORMAL,
	CSS_TEXT_SPACE_TYPE_LENGTH

}	CSS_TEXT_SPACE_TYPE;



//text-transform:

typedef enum {

	CSS_TEXT_TRANSFORM_INHERIT = 0,

	CSS_TEXT_TRANSFORM_CAPITALIZE,
	CSS_TEXT_TRANSFORM_UPPERCASE,
	CSS_TEXT_TRANSFORM_LOWERCASE,
	CSS_TEXT_TRANSFORM_NONE

}	CSS_TEXT_TRANSFORM;

//white-space:

typedef enum {
	CSS_WHITE_SPACE_INHERIT = 0,

	CSS_WHITE_SPACE_NORMAL,
	CSS_WHITE_SPACE_PRE,
	CSS_WHITE_SPACE_NOWRAP,
	CSS_WHITE_SPACE_PRE_WRAP,
	CSS_WHITE_SPACE_PRE_LINE

}	CSS_WHITE_SPACE;

//border-style:

typedef enum {
	CSS_BORDER_STYLE_NONE = 0,

	CSS_BORDER_STYLE_HIDDEN,
	CSS_BORDER_STYLE_DOTTED,
	CSS_BORDER_STYLE_DASHED,
	CSS_BORDER_STYLE_SOLID,
	CSS_BORDER_STYLE_DOUBLE,
	CSS_BORDER_STYLE_GROOVE,
	CSS_BORDER_STYLE_RIDGE,
	CSS_BORDER_STYLE_INSET,
	CSS_BORDER_STYLE_OUTSET
	
}	CSS_BORDER_STYLE;

typedef enum{
		line_none = 0,

		line_hidden,
		line_dotted,
		line_dashed,
		line_solid,
		line_double,
		line_groove,
		line_ridge,
		line_inset,
		line_outset
} LineType_t;

void* CMS_BR_CSS_LIST_INIT(void);
int CMS_BR_CSS_LIST_DESTROY(void* csslist);
int CMS_BR_CSS_PARSER(char * buffer, void* csslist);
void* CMS_BR_CSS_SEARCH(void* csslist, void *element, void* p_style);
void* CMS_BR_CSS_INLINE_PARSER(char* pbuf_inline, void* style, void* csslist);
int CSS_BR_FREE_STYLE(void * css_style);
void CMS_BR_CSS_TRAVEL_STYLE(void* css_style);

colour GetCssFontColor(void);
CSS_FONT_FAMILY GetCssFontFaminly(void);
CSS_FONT_STYLE GetCssFontStyle(void);
CSS_FONT_VARIANT GetCssFontVariant(void);
CSS_FONT_WEIGHT GetCssFontWeight(void);
unsigned int GetCssFontSize(void);

unsigned int GetCssWidth(void);
unsigned int GetCssHeight(void);

FontType_t GetCssFontType(void);

unsigned int GetCssTextIndent(void);
CSS_TEXT_ALIGH GetCssTextAlign(void);
CSS_TEXT_DECORATION GetCssTextDecoration(void);
unsigned int GetCssLetterSpace(void);
unsigned int GetCssWordSpace(void);
CSS_TEXT_TRANSFORM GetCssTextTransform(void);
CSS_WHITE_SPACE GetCssWhiteSpace(void);

colour GetCssBorderColor(int i);
CSS_BORDER_STYLE GetCssBorderStyle(int i);
unsigned int GetCssBorderWidth(int i);
unsigned int GetCssMargin(int i);
unsigned int GetCssPadding(int i);

unsigned int GetCssBackgroundColor(void);
colour CSS_PARSER_COLOR(const char *colorstr);

/* for table */
unsigned int GetTableCssBgColor(void* style);
unsigned int GetTableCssColor(void* style);


#endif