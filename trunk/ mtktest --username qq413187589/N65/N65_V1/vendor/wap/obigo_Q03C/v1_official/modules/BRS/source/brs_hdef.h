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






#ifndef _brs_hdef_h
#define _brs_hdef_h

#ifndef _brs_cfg_h
#include "brs_cfg.h"
#endif

#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif




#define BRS_HTML_LAST_ELEMENT          0x5E


#define BRS_HTML_ELEMENT_A             0x1C
#define BRS_HTML_ELEMENT_ABBR          0x00
#define BRS_HTML_ELEMENT_ACRONYM       0x01
#define BRS_HTML_ELEMENT_ADDRESS       0x02
#define BRS_HTML_ELEMENT_BASE          0x03
#define BRS_HTML_ELEMENT_BLOCKQUOTE    0x04
#define BRS_HTML_ELEMENT_BODY          0x05
#define BRS_HTML_ELEMENT_BR            0x26
#define BRS_HTML_ELEMENT_CAPTION       0x06
#define BRS_HTML_ELEMENT_CITE          0x07
#define BRS_HTML_ELEMENT_CODE          0x08
#define BRS_HTML_ELEMENT_DD            0x09
#define BRS_HTML_ELEMENT_DFN           0x0A
#define BRS_HTML_ELEMENT_DIV           0x0B
#define BRS_HTML_ELEMENT_DL            0x0C
#define BRS_HTML_ELEMENT_DT            0x0D
#define BRS_HTML_ELEMENT_EM            0x29
#define BRS_HTML_ELEMENT_FORM          0x0E
#define BRS_HTML_ELEMENT_H1            0x0F
#define BRS_HTML_ELEMENT_H2            0x10
#define BRS_HTML_ELEMENT_H3            0x11
#define BRS_HTML_ELEMENT_H4            0x12
#define BRS_HTML_ELEMENT_H5            0x13
#define BRS_HTML_ELEMENT_H6            0x14
#define BRS_HTML_ELEMENT_HEAD          0x2C
#define BRS_HTML_ELEMENT_HTML          0x15
#define BRS_HTML_ELEMENT_IMG           0x2E
#define BRS_HTML_ELEMENT_INPUT         0x2F
#define BRS_HTML_ELEMENT_KBD           0x16
#define BRS_HTML_ELEMENT_LABEL         0x17
#define BRS_HTML_ELEMENT_LI            0x18
#define BRS_HTML_ELEMENT_LINK          0x19
#define BRS_HTML_ELEMENT_META          0x30
#define BRS_HTML_ELEMENT_OBJECT        0x49
#define BRS_HTML_ELEMENT_OL            0x3A
#define BRS_HTML_ELEMENT_OPTION        0x35
#define BRS_HTML_ELEMENT_P             0x20
#define BRS_HTML_ELEMENT_PARAM         0x40
#define BRS_HTML_ELEMENT_PRE           0x1B
#define BRS_HTML_ELEMENT_Q             0x41
#define BRS_HTML_ELEMENT_SAMP          0x42
#define BRS_HTML_ELEMENT_SELECT        0x37
#define BRS_HTML_ELEMENT_SPAN          0x43
#define BRS_HTML_ELEMENT_STRONG        0x39
#define BRS_HTML_ELEMENT_TABLE         0x1F
#define BRS_HTML_ELEMENT_TD            0x1D
#define BRS_HTML_ELEMENT_TEXTAREA      0x44
#define BRS_HTML_ELEMENT_TH            0x45
#define BRS_HTML_ELEMENT_TITLE         0x46
#define BRS_HTML_ELEMENT_TR            0x1E
#define BRS_HTML_ELEMENT_UL            0x47
#define BRS_HTML_ELEMENT_VAR           0x48


#define BRS_HTML_ELEMENT_B             0x24
#define BRS_HTML_ELEMENT_BIG           0x25
#define BRS_HTML_ELEMENT_FIELDSET      0x2A
#define BRS_HTML_ELEMENT_HR            0x4A
#define BRS_HTML_ELEMENT_I             0x2D
#define BRS_HTML_ELEMENT_OPTGROUP      0x34
#define BRS_HTML_ELEMENT_SMALL         0x38
#define BRS_HTML_ELEMENT_STYLE         0x1A


#define BRS_HTML_ELEMENT_BLINK         0x4C
#define BRS_HTML_ELEMENT_CENTER        0x4D
#define BRS_HTML_ELEMENT_DIR           0x4E
#define BRS_HTML_ELEMENT_FONT          0x51
#define BRS_HTML_ELEMENT_MARQUEE       0x4F
#define BRS_HTML_ELEMENT_MENU          0x50
#define BRS_HTML_ELEMENT_PLAINTEXT     0x4B


#define BRS_HTML_ELEMENT_U             0x3D


#define BRS_HTML_ELEMENT_AREA          0x52
#define BRS_HTML_ELEMENT_BDO
#define BRS_HTML_ELEMENT_BUTTON        0x58
#define BRS_HTML_ELEMENT_COL
#define BRS_HTML_ELEMENT_COLGROUP
#define BRS_HTML_ELEMENT_DEL
#define BRS_HTML_ELEMENT_FRAME         0x5A
#define BRS_HTML_ELEMENT_FRAMESET      0x56
#define BRS_HTML_ELEMENT_IFRAME
#define BRS_HTML_ELEMENT_LEGEND        0x5B
#define BRS_HTML_ELEMENT_MAP           0x53
#define BRS_HTML_ELEMENT_NOFRAMES      0x57
#define BRS_HTML_ELEMENT_NOSCRIPT      0x55
#define BRS_HTML_ELEMENT_SCRIPT        0x54
#define BRS_HTML_ELEMENT_SUB
#define BRS_HTML_ELEMENT_SUP
#define BRS_HTML_ELEMENT_TBODY
#define BRS_HTML_ELEMENT_TFOOT
#define BRS_HTML_ELEMENT_THEAD
#define BRS_HTML_ELEMENT_TT            0x5C
#define BRS_HTML_ELEMENT_FORM_END      0x59


#define BRS_HTML_ELEMENT_APPLET
#define BRS_HTML_ELEMENT_BASEFONT      0x5D
#define BRS_HTML_ELEMENT_COMMENT       0x5E
#define BRS_HTML_ELEMENT_ISINDEX
#define BRS_HTML_ELEMENT_S
#define BRS_HTML_ELEMENT_STRIKE


#define BRS_HTML_ELEMENT_ACCESS        0x23
#define BRS_HTML_ELEMENT_ANCHOR        0x22
#define BRS_HTML_ELEMENT_CARD          0x27
#define BRS_HTML_ELEMENT_DO            0x28
#define BRS_HTML_ELEMENT_GO            0x2B
#define BRS_HTML_ELEMENT_NOOP          0x31
#define BRS_HTML_ELEMENT_ONEVENT       0x33
#define BRS_HTML_ELEMENT_POSTFIELD     0x21
#define BRS_HTML_ELEMENT_PREV          0x32
#define BRS_HTML_ELEMENT_REFRESH       0x36
#define BRS_HTML_ELEMENT_SETVAR        0x3E
#define BRS_HTML_ELEMENT_TEMPLATE      0x3B
#define BRS_HTML_ELEMENT_TIMER         0x3C
#define BRS_HTML_ELEMENT_WML           0x3F






#define BRS_HTML_LAST_ATTRIBUTE            0x69


#define BRS_HTML_ATTRIBUTE_ABBR            0x00
#define BRS_HTML_ATTRIBUTE_ACCESSKEY       0x01
#define BRS_HTML_ATTRIBUTE_ACTION          0x02
#define BRS_HTML_ATTRIBUTE_ALIGN           0x03 
#define BRS_HTML_ATTRIBUTE_ALT             0x04
#define BRS_HTML_ATTRIBUTE_ARCHIVE         0x05
#define BRS_HTML_ATTRIBUTE_AXIS            0x06
#define BRS_HTML_ATTRIBUTE_CHARSET         0x07
#define BRS_HTML_ATTRIBUTE_CHECKED         0x08
#define BRS_HTML_ATTRIBUTE_CLASS           0x09
#define BRS_HTML_ATTRIBUTE_CLASSID         0x0A
#define BRS_HTML_ATTRIBUTE_CODEBASE        0x0B
#define BRS_HTML_ATTRIBUTE_CODETYPE        0x0C
#define BRS_HTML_ATTRIBUTE_COLS            0x0D
#define BRS_HTML_ATTRIBUTE_COLSPAN         0x0E
#define BRS_HTML_ATTRIBUTE_CONTENT         0x0F
#define BRS_HTML_ATTRIBUTE_DATA            0x10
#define BRS_HTML_ATTRIBUTE_DECLARE         0x11
#define BRS_HTML_ATTRIBUTE_ENCTYPE         0x12
#define BRS_HTML_ATTRIBUTE_FOR             0x13
#define BRS_HTML_ATTRIBUTE_HEADERS         0x14
#define BRS_HTML_ATTRIBUTE_HEIGHT          0x15
#define BRS_HTML_ATTRIBUTE_HREF            0x16
#define BRS_HTML_ATTRIBUTE_HREFLANG        0x17
#define BRS_HTML_ATTRIBUTE_HTTP_EQUIV      0x18
#define BRS_HTML_ATTRIBUTE_ID              0x19
#define BRS_HTML_ATTRIBUTE_LONGDESC        0x1A
#define BRS_HTML_ATTRIBUTE_MAXLENGTH       0x1B
#define BRS_HTML_ATTRIBUTE_MEDIA           0x1C
#define BRS_HTML_ATTRIBUTE_METHOD          0x1D
#define BRS_HTML_ATTRIBUTE_MULTIPLE        0x1E
#define BRS_HTML_ATTRIBUTE_NAME            0x1F 
#define BRS_HTML_ATTRIBUTE_PROFILE         0x20
#define BRS_HTML_ATTRIBUTE_REL             0x21
#define BRS_HTML_ATTRIBUTE_REV             0x22
#define BRS_HTML_ATTRIBUTE_ROWS            0x23
#define BRS_HTML_ATTRIBUTE_ROWSPAN         0x24
#define BRS_HTML_ATTRIBUTE_SCHEME          0x25
#define BRS_HTML_ATTRIBUTE_SCOPE           0x26
#define BRS_HTML_ATTRIBUTE_SELECTED        0x27
#define BRS_HTML_ATTRIBUTE_SIZE            0x28 
#define BRS_HTML_ATTRIBUTE_SRC             0x29
#define BRS_HTML_ATTRIBUTE_STANDBY         0x2A
#define BRS_HTML_ATTRIBUTE_SUMMARY         0x2B
#define BRS_HTML_ATTRIBUTE_TABINDEX        0x2C
#define BRS_HTML_ATTRIBUTE_TITLE           0x2D
#define BRS_HTML_ATTRIBUTE_TYPE            0x2E 
#define BRS_HTML_ATTRIBUTE_VALIGN          0x2F
#define BRS_HTML_ATTRIBUTE_VALUE           0x30
#define BRS_HTML_ATTRIBUTE_VALUETYPE       0x31
#define BRS_HTML_ATTRIBUTE_VERSION         0x32
#define BRS_HTML_ATTRIBUTE_WIDTH           0x33
#define BRS_HTML_ATTRIBUTE_DISABLED        0x63





#define BRS_HTML_ATTRIBUTE_STYLE           0x36 


#define BRS_HTML_ATTRIBUTE_ISMAP           0x5E
#define BRS_HTML_ATTRIBUTE_USEMAP          0x5F
#define BRS_HTML_ATTRIBUTE_SHAPE           0x60
#define BRS_HTML_ATTRIBUTE_COORDS          0x61
#define BRS_HTML_ATTRIBUTE_NOHREF          0x62
#define BRS_HTML_ATTRIBUTE_CELLPADDING     0x64
#define BRS_HTML_ATTRIBUTE_CELLSPACING     0x65
#define BRS_HTML_ATTRIBUTE_BACKGROUND      0x66
#define BRS_HTML_ATTRIBUTE_BORDER          0x67
#define BRS_HTML_ATTRIBUTE_NOWRAP          0x68
#define BRS_HTML_ATTRIBUTE_FACE            0x69


#define BRS_HTML_ATTRIBUTE_UTN             0x4E
#define BRS_HTML_ATTRIBUTE_CTI             0x4F
#define BRS_HTML_ATTRIBUTE_TELBOOK         0x50
#define BRS_HTML_ATTRIBUTE_EMAIL           0x51
#define BRS_HTML_ATTRIBUTE_KANA            0x52
#define BRS_HTML_ATTRIBUTE_IJAM            0x53
#define BRS_HTML_ATTRIBUTE_ISTYLE          0x54
#define BRS_HTML_ATTRIBUTE_DIRECTION       0x55
#define BRS_HTML_ATTRIBUTE_LOOP            0x56
#define BRS_HTML_ATTRIBUTE_BEHAVIOR        0x57
#define BRS_HTML_ATTRIBUTE_CLEAR           0x58
#define BRS_HTML_ATTRIBUTE_START           0x59
#define BRS_HTML_ATTRIBUTE_BGCOLOR         0x5A
#define BRS_HTML_ATTRIBUTE_TEXT            0x5B
#define BRS_HTML_ATTRIBUTE_LINK            0x5C
#define BRS_HTML_ATTRIBUTE_COLOR           0x5D


#define BRS_HTML_ATTRIBUTE_ACCEPT_CHARSET  0x37
#define BRS_HTML_ATTRIBUTE_CACHE_CONTROL   0x38
#define BRS_HTML_ATTRIBUTE_COLUMNS         0x39
#define BRS_HTML_ATTRIBUTE_DOMAIN          0x3A
#define BRS_HTML_ATTRIBUTE_EMPTYOK         0x3B
#define BRS_HTML_ATTRIBUTE_FORMAT          0x3C
#define BRS_HTML_ATTRIBUTE_FORUA           0x3D
#define BRS_HTML_ATTRIBUTE_HSPACE          0x3E
#define BRS_HTML_ATTRIBUTE_INAME           0x3F
#define BRS_HTML_ATTRIBUTE_IVALUE          0x40
#define BRS_HTML_ATTRIBUTE_LABEL           0x41
#define BRS_HTML_ATTRIBUTE_LOCALSRC        0x42
#define BRS_HTML_ATTRIBUTE_MODE            0x43
#define BRS_HTML_ATTRIBUTE_NEWCONTEXT      0x44
#define BRS_HTML_ATTRIBUTE_ONENTERBACKWARD 0x45
#define BRS_HTML_ATTRIBUTE_ONENTERFORWARD  0x46
#define BRS_HTML_ATTRIBUTE_ONPICK          0x47
#define BRS_HTML_ATTRIBUTE_ONTIMER         0x48
#define BRS_HTML_ATTRIBUTE_OPTIONAL        0x49
#define BRS_HTML_ATTRIBUTE_ORDERED         0x4A
#define BRS_HTML_ATTRIBUTE_PATH            0x4B
#define BRS_HTML_ATTRIBUTE_SENDREFERER     0x4C
#define BRS_HTML_ATTRIBUTE_VSPACE          0x4D









#define BRS_HTML_ATTRVAL_LEFT          0x0000
#define BRS_HTML_ATTRVAL_RIGHT         0x0001


#define BRS_HTML_ATTRVAL_CENTER        0x0100




#define BRS_HTML_ATTRVAL_BASELINE      0x0200





#define BRS_HTML_ATTRVAL_FALSE         0x0A00
#define BRS_HTML_ATTRVAL_TRUE          0x0A01


#define BRS_HTML_ATTRVAL_GET           0x0B00
#define BRS_HTML_ATTRVAL_POST          0x0B01


#define BRS_HTML_ATTRVAL_TOP           0x0D00
#define BRS_HTML_ATTRVAL_MIDDLE        0x0D01
#define BRS_HTML_ATTRVAL_BOTTOM        0x0D02




#define BRS_HTML_ATTRVAL_ROW           0x0E00
#define BRS_HTML_ATTRVAL_COL           0x0E01


#define BRS_HTML_ATTRVAL_TEXT          0x0F00
#define BRS_HTML_ATTRVAL_PASSWORD      0x0F01
#define BRS_HTML_ATTRVAL_CHECKBOX      0x0F02
#define BRS_HTML_ATTRVAL_RADIO         0x0F03
#define BRS_HTML_ATTRVAL_RESET         0x0F04
#define BRS_HTML_ATTRVAL_HIDDEN        0x0F05
#define BRS_HTML_ATTRVAL_SUBMIT        0x0F06
#define BRS_HTML_ATTRVAL_IMAGE         0x0F07
#define BRS_HTML_ATTRVAL_FILE          0x0F08
#define BRS_HTML_ATTRVAL_BUTTON        0x0F09


#define BRS_HTML_ATTRVAL_DATA          0x1000
#define BRS_HTML_ATTRVAL_REF           0x1001
#define BRS_HTML_ATTRVAL_OBJECT        0x1002




#define BRS_HTML_ATTRVAL_MULTIPLE      0x1100





#define BRS_HTML_ATTRVAL_CIRCLE        0x0100


#define BRS_HTML_ATTRVAL_RECT          0x1201
#define BRS_HTML_ATTRVAL_POLY          0x1200



#define BRS_HTML_ATTRVAL_DISC          0x1300
#define BRS_HTML_ATTRVAL_SQUARE        0x1301









#define BRS_HTML_ATTRVAL_SCROLL        0x1400
#define BRS_HTML_ATTRVAL_SLIDE         0x1401
#define BRS_HTML_ATTRVAL_ALTERNATE     0x1402


#define BRS_HTML_ATTRVAL_ALL           0x1500




#define BRS_HTML_ATTRVAL_ARABIC        0x1600
#define BRS_HTML_ATTRVAL_LOWER_ALPHA   0x1601
#define BRS_HTML_ATTRVAL_UPPER_ALPHA   0x1602
#define BRS_HTML_ATTRVAL_LOWER_ROMAN   0x1603
#define BRS_HTML_ATTRVAL_UPPER_ROMAN   0x1604





#define BRS_HTML_ATTRVAL_WRAP          0x3E00
#define BRS_HTML_ATTRVAL_NOWRAP        0x3E01


#define BRS_HTML_ATTRVAL_NO_CACHE      0x3F00





extern const msf_strtable_info_t brs_html_Elements;

extern const msf_strtable_info_t brs_html_Attributes;

extern const msf_strtable_info_t brs_html_Attrvals;

extern const msf_strtable_info_t brs_html_Entities;

extern const unsigned char brs_html_Element_table[];
extern const unsigned char brs_html_Element_htmltable[];

extern const MSF_UINT16 brs_html_AttributeTypes[];
extern const MSF_UINT16 brs_wml_AttributeTypes[];




#if defined BRS_CONFIG_WML && defined BRS_CONFIG_WBXML

extern const MSF_UINT8           brs_wml_AttrTransform[];
extern const msf_strtable_info_t brs_wml_AttrStart;
extern const msf_strtable_info_t brs_wml_AttrValue;

#define WML_TRANSFORM_SIZE 101

#endif

#endif
