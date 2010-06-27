
#define  _MMI_EBOOKDEFS_H
#include "MMI_features.h"

#include "MMIDataType.h"
#include "EbookResDef.h"

typedef enum
{
    EBR_FONT_STYLE_NORMAL = 0,
    EBR_FONT_STYLE_ITALIC,
    EBR_FONT_STYLE_BOLD
} ebr_font_style_enum;

typedef enum
{
    EBR_FONT_SIZE_SMALL = 0,
    EBR_FONT_SIZE_MEDIUM,
    EBR_FONT_SIZE_LARGE
} ebr_font_size_enum;

typedef enum
{
    EBR_SCROLL_BY_LINE = 0,
    EBR_SCROLL_BY_PAGE
} ebr_scroll_type_enum;

typedef enum
{
    EBR_AUTO_SCROLL_SPEED_1 = 0,
    EBR_AUTO_SCROLL_SPEED_2,
    EBR_AUTO_SCROLL_SPEED_3,
    EBR_AUTO_SCROLL_SPEED_4,
    EBR_AUTO_SCROLL_SPEED_5
} ebr_scroll_speed_enum;

typedef enum
{
    EBR_SCROLL_OFF = 0,
    EBR_SCROLL_ON
} ebr_scroll_status_enum;

typedef enum
{
    EBR_FULL_SCREEN_OFF = 0,
    EBR_FULL_SCREEN_ON
} ebr_full_screen_status_enum;

typedef enum
{
    EBOOK_WESTERN_WINDOWS,          /* windows-1252 */
    EBOOK_UCS,
    EBOOK_UTF8,
#ifdef __MMI_CHSET_BIG5__
    EBOOK_BIG5,             /* big5 */
#endif 

#ifdef __MMI_CHSET_GB2312__
    EBOOK_GB2312,   /* gb2312 */
#endif 

#ifdef __MMI_CHSET_TURKISH_ISO__
    EBOOK_TURKISH_ISO,
#endif 

#ifdef __MMI_CHSET_TURKISH_WIN__
    EBOOK_TURKISH_WINDOWS,  /* windows-1254 */
#endif 

#ifdef __MMI_CHSET_BALTIC_ISO__
    EBOOK_BALTIC_ISO,   /* iso-8859-13 */
#endif 

#ifdef __MMI_CHSET_BALTIC_WIN__
    EBOOK_BALTIC_WINDOWS,   /* windows-1257 */
#endif 

#ifdef __MMI_CHSET_CEURO_ISO__
    EBOOK_CENTRAL_EUROPEAN_ISO, /* iso-8859-2 */
#endif 

#ifdef __MMI_CHSET_CEURO_WIN__
    EBOOK_CENTRAL_EUROPEAN_WINDOWS, /* windows-1250 */
#endif 

#ifdef __MMI_CHSET_GREEK_ISO__
    EBOOK_GREEK_ISO,    /* iso-8859-7 */
#endif 

#ifdef __MMI_CHSET_GREEK_WIN__
    EBOOK_GREEK_WINDOWS,    /* windows-1253 */
#endif 

#ifdef __MMI_CHSET_HEBREW_ISO__
    EBOOK_HEBREW_ISO,   /* iso-8859-8-i */
#endif 

#ifdef __MMI_CHSET_HEBREW_WIN__
    EBOOK_HEBREW_WINDOWS,   /* windows-1255 */
#endif 

#ifdef __MMI_CHSET_LATIN_ISO__
    EBOOK_LATIN_ISO,    /* iso-8859-15 */
#endif 

#ifdef __MMI_CHSET_NORDIC_ISO__
    EBOOK_NORDIC_ISO,   /* iso-8859-10 */
#endif 

#ifdef __MMI_CHSET_SEURO_ISO__
    EBOOK_SOURTH_EUROPEAN_ISO,  /* iso-8859-3 */
#endif 

#ifdef __MMI_CHSET_WESTERN_ISO__
    EBOOK_WESTERN_ISO,  /* iso-8859-1 */
#endif 

#ifdef __MMI_CHSET_ARABIC_ISO__
    EBOOK_ARABIC_ISO,   /* iso-8859-6 */
#endif 

#ifdef __MMI_CHSET_ARABIC_WIN__
    EBOOK_ARABIC_WINDOWS,   /* windows-1256 */
#endif 
    
#ifdef __MMI_CHSET_GB18030__
        EBOOK_GB18030,
#endif /* __MMI_CHSET_GB18030__ */ 

    EBOOK_UNSPECIFIED_CHARSET,

    MMI_EBOOK_MAX_CHARSET   /* internal used by e-mail protocol entity */
} ebook_charset_enum;

