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
/*
 * brs_cfg.h
 *
 */
#ifndef _brs_cfg_h
#define _brs_cfg_h

/**************************************************
 * Language support
 **************************************************/

/*
 * XHTML - Always included. XHTML Mobile Profile
 * HTML  - Adds HTML 4.01 (and XHTML 1.0) and iMode
 * WML   - Adds WML 1.3
 *
 * If LOOSE_XHTML is defined, then XHTML is handled as HTML,
 * that is, parsed with best effort.
 *
 * Valid language combinations:
 *
 * |----------------------------|
 * | WML | XHTML | HTML | LOOSE |
 * |----------------------------|
 * |  X  |   X   |  X   |   X   |
 * |-----|-------|--------------|
 * |  X  |   X   |  X   |       |
 * |-----|-------|--------------|
 * |  X  |   X   |      |       |
 * |-----|-------|--------------|
 * |  X  |       |      |       | Includes the XHTML code, but it is inactivated.
 * |-----|-------|--------------|
 * |     |   X   |  X   |   X   |
 * |-----|-------|--------------|
 * |     |   X   |  X   |       |
 * |-----|-------|--------------|
 * |     |   X   |      |       |
 * |----------------------------|
 */
#ifdef WAP2
#define BRS_CONFIG_XHTML
#define BRS_CONFIG_HTML
#endif
#define BRS_CONFIG_WML

#define BRS_CONFIG_LOOSE_XHTML
#define BRS_CONFIG_WBXML
#define BRS_CONFIG_WMLS
#ifdef WAP_SEC_SUPPORT
#define BRS_CONFIG_WMLS_CRYPTO
#endif
#define BRS_CONFIG_PLUGIN

/* If defined, BRS will use unstrict WML validation */
#define BRS_CONFIG_EXTENDED_WML_VALIDATION

/* To use SGML grammar for WML the following flag 
 * should be defined in msf_cfg.h 
 * MSF_CFG_EXTENDED_WML_PARSING */

/**************************************************
 * Browser configuration settings
 **************************************************/

/* Define this flag to force update on stale cache when 
 * browsing forward or back */
/* #define BRS_CFG_NO_STALE_CACHE_ON_GO_FWD_OR_BACK */

/* If the memory usage of BRS exceeds this limit, the fetching
 * of the current page will be aborted but the browser
 * can continue to run. To disable this feature, undefine
 * this constant or define it to be 0. */
 #define BRS_CFG_MEMORY_LIMIT                      0/*120*1024*//*150000*/


/* The WML standard says that the history stack must be cleared
 * when entering a card that has the "newcontext" attribute set,
 * or if a script calls the function Browser.newContext. Also,
 * calling the function BRSif_loadUrl sets the "newcontext" attribute
 * by default.
 * However, frequent emptying of the history stack usually implies
 * that the history becomes very shallow, and limits the usefulness
 * of the BACK and FWD buttons.
 * By default, BRS will let the history remain intact on "newcontext".
 * The following configurations are available:
 *   0: Never clear history on newcontext. (default)
 *   1: Always clear history on newcontext.
 *   2: Never clear history on newcontext, and don't set "newcontext" in BRSif_loadUrl
 *   3: Always clear history on newcontext, but don't set "newcontext" in BRSif_loadUrl
 */
extern unsigned int bra_cfg_brs_clear_history_on_newcontext(void);
#define BRS_CFG_CLEAR_HISTORY_ON_NEWCONTEXT		(bra_cfg_brs_clear_history_on_newcontext())

/* Each request for an image or embedded_object on a HTML page uses up a resource
 * in the form of a pipe, while the retrieval of the image/object is in progress.
 * If too many images or objects are loaded at the same time, this may
 * use up all available pipes (depending on the total number of pipes
 * available). Hence, this constant should be defined to a number
 * somewhat smaller than the total number of pipes in the system,
 * to allow for other uses of the pipes as well. */
#define BRS_CFG_MAX_SIMULTANEOUS_OBJECT_REQUESTS            5


/* Define BRS_CONFIG_DRM to support the OMA Digital Rights Management
 * specification, OMA-Download-DRM-v1_0-20020905-a. Only Forward Lock
 * is handled by BRS.
 */
/*#define BRS_CONFIG_DRM*/

/* Define BRS_CFG_OFFLINE_PAGES to enable offline browsing.
 * Undefine to remove the offline browsing code.
 * !! NOTE !! The browser application should have a similar config-flag;
 * make sure that both flags are defined appropriately to
 * acheive the desired configuration.
 */
#define BRS_CFG_OFFLINE_PAGES

/* Default "Accept:" header, sent by browser when retrieving a document. */
extern const char * bra_cfg_default_accept_header(void);
#define BRS_CFG_DEFAULT_ACCEPT_HEADER (bra_cfg_default_accept_header())

/* Default accapt header when loading objects. Registry configuration
   is first used, but if not set this setting will be used instaed     */
#ifdef BRS_CONFIG_DRM
   #define BRS_CFG_DEFAULT_OBJECT_ACCEPT_HEADER  "image/*,audio/*,application/*"
#else
   #define BRS_CFG_DEFAULT_OBJECT_ACCEPT_HEADER  "image/*,audio/*"
#endif

/* Default "Accept-Charset:" header, sent by browser when retrieving a document. */
extern const char * bra_cfg_default_charset_header(void);
#define BRS_CFG_DEFAULT_ACCEPT_CHARSET_HEADER (bra_cfg_default_charset_header())

/* Default "User-Agent:" header, sent by browser when retrieving a document. */
#define BRS_CFG_DEFAULT_USER_AGENT_HEADER "MAUI WAP Browser"

/* Default "Accept-Language:" header, sent by browser when retrieving a document. */
const char* bra_cfg_default_accept_language_header (void);
#define BRS_CFG_DEFAULT_ACCEPT_LANGUAGE_HEADER    (bra_cfg_default_accept_language_header())

/*
 * How to handle redirections:
 *   1      Normal:   always automatic redirection, and POST is changed into GET
 *                      (this is what most browsers do)
 *   2      Cautious: responses with status codes 301 and 307 are always
 *                      shown to the user
 *   3      Special:  for responses with status codes 301, 302, 307:
 *                      if GET, do automatic redirection,
 *                      if POST, ask for user confirmation
 */
extern unsigned int bra_cfg_brs_redirect_handling (void);
#define BRS_CFG_REDIRECT   (bra_cfg_brs_redirect_handling())

/* Each time a request is made for a page/object, a signal is sent from the 
 * BRS, to the STK. The memory used by these signals is allocated using 
 * HDIa_signalAllocMemory(). Thus, if to many simultaneous  requests are made, 
 * the signalling memory can on some platforms become depleted. By configuring 
 * BRS_CFG_MAX_SIMULTANEOUS_REQUESTS to a value => 1, requests will instead be 
 * queued by the BRS, which will lead to less usage of signalling memory. */
/* #define BRS_CFG_MAX_SIMULTANEOUS_REQUESTS         7 */

/*
 * If a BACK or FORWARD navigation requires the re-posting
 * of data, then the user is asked for confirmation if this symbol is defined.
 * Otherwise, an error/warning is generated to the application
 * and an empty page is shown.
 */
/* #define BRS_CFG_CONFIRM_REPOST */

/*
 *	If a http request is aborted due to unspecified error
 *  an error message is displayed instead of error page
 */
/*#define BRS_CFG_HTTP_ERROR_MSG*/

/*
* The integration specifies if a certain image mime type is supported or not. 
*/
extern const char * bra_cfg_supported_image_mime(void);
#define BRS_CFG_SUPPORTED_IMAGE_MIME (bra_cfg_supported_image_mime())

/**************************************************
 * Unspecified items. Enabling these items typically means supporting features not
 * defined in CSS or any of the supported markup languages.
 */

/* Enabling this config makes white-space: nowrap act like a particular type of marquee,
 * which typically scrolls links around inside their box.*/
#undef BRS_CFG_SCROLLING_LINKS
/* Minimum part of the screen that should be available for a scrolling link
 * to be allowed. This should be a value between 0 and 100. */
#define BRS_LE_SCROLLING_LINK_MIN_PART_OF_SCREEN 25

#ifdef BRS_CFG_SCROLLING_LINKS
/* If scrolling links are defined the white-space property is needed to determine which 
 * links should scroll and to render the link marquee.
 */
#define BRS_CFG_CSS_SPECIAL_STYLE_SHEET_WHITESPACE_PROP   "}\n"
#else
#define BRS_CFG_CSS_SPECIAL_STYLE_SHEET_WHITESPACE_PROP   "   white-space: normal;}\n"
#endif

/* All cookies will be deleted after the last instance of BRS 
 * is deleted. */
#define BRS_CFG_CLEAR_COOKIES

/* This controls whether the CSS property -pcs-input-mode is supported.*/
#undef BRS_CFG_LE_PCS_INPUT_MODE

/* If this is enabled controls such as text-inputs or selectgroups are never rendered
 * as larger than screen. This typically means controls need to be able to scroll their
 * contents, but does not suggest that controls cannot be rendered partly on screen.
 */
#undef BRS_CFG_LE_LIMIT_CONTROLS_TO_SCREEN_SIZE

/* If this is enabled images are rescaled to fit the screen size. This may lead to very
 * poor image quality, which is especially devastating for images that are used to convey
 * textual messages.
 */
#undef BRS_CFG_LE_LIMIT_OBJECTS_TO_SCREEN_WIDTH


/**************************************************
 * Style Sheets
 **************************************************/

/* Default style sheet */
extern const char * bra_cfg_brs_default_css(void);
#define BRS_CFG_CSS_DEFAULT_STYLE_SHEET (bra_cfg_brs_default_css())


/* The narrow rendering feature can be turned on to make the layout engine perform a best
 * effort attempt at reducing width for content that is wider than the screen in an 
 * effort to avoid horizontal scrollbars. The rules for how this attempt should be made 
 * follows below.
 */
#define BRS_CFG_CSS_SPECIAL_STYLE_SHEET \
  "* {height: auto;\n" \
  "   width: auto;\n" \
  "   padding-left: 0px;\n" \
  "   padding-right: 0px;\n" \
  "   margin-left: 0px;\n" \
  "   margin-right: 0px;\n" \
  "   float: none;\n" \
  BRS_CFG_CSS_SPECIAL_STYLE_SHEET_WHITESPACE_PROP \
  "li {list-style-position: inside}\n" \
  "table,tbody,thead,tfoot,tr,td,th,col,colgroup {display: block}\n" \
  "* {max-width: 100% }\n"

  
/* If defined, BRS will allow style information
 * in WML documents, as well as in HTML documents. */
#define BRS_CFG_ALLOW_CSS_IN_WML

/* Default message to display if <script> element found in HTML content */
#define BRS_CFG_DEFAULT_SCRIPT_WARNING_MSG "Script element skipped in content."


/* 
 * Maximum size of html/wml page including css header.  
 * If the define is 0 all pages regardless of size will be loaded.
 */
#define BRS_CFG_MAX_PAGE_SIZE            0

/* 
 * Maximum size of html/wml page including css/images/sounds/.. 
 * If the define is 0 all content regardless of size will be loaded.
 */
#define BRS_CFG_MAX_TOTAL_SIZE           0

/* Define this flag to extend the character format matching from ascii to a large 
 * (but not complete) set of the Unicode character space.
 */
#undef BRS_CFG_EXTENDED_FORMAT_CHECK


/**************************************************
 * Parser configuration settings
 **************************************************/

#define BRS_CFG_MAX_CONCURRENT_PARSINGS 10

/* The initial buffer size used for the parser. */
#define BRS_PRSR_BUF_SIZE 1400	/* 500 */

/* The default character set used when parsing a text document
 * with no encoding information. Must be ASCII based. */
#define BRS_CFG_DEFAULT_CHARSET   MSF_CHARSET_UTF_8


/**************************************************
 * WMLScript
 **************************************************/

#define BRS_CFG_WMLS_HAS_FLOAT


/**************************************************
 * Layout engine configuration settings
 **************************************************/

/* 
 * An alt or standby text is always shown before loading. If this flag is
 * set, the alt text remains on the display until the MsfNotifyResourceLoaded
 * signal is received from the adaptation. If not set, then the alt text
 * text is removed as soon as the loading starts. Instead the corresponding
 * gadget is displayed to make it possible to show loading progress.
 *
 * If set, do not send MsfNotifyResourceLoaded until the image decoding
 * is finished. This way the alt text remains until the image is ready
 * to be displayed.
 */
#define BRS_CFG_LE_SHOW_ALT_TEXT_DURING_LOADING


/* If defined the render do not start until all images stored in cache
   has been fetched or the the time interval between the fetching is larger
   then BRS_LE_IMAGE_TIMER_INTERVAL */
#undef BRS_LE_WAIT_FOR_CACHED_IMAGES_BEFORE_RENDER

#ifdef BRS_LE_WAIT_FOR_CACHED_IMAGES_BEFORE_RENDER
#define  BRS_LE_IMAGE_TIMER_INTERVAL 5
#endif
/**************************************************
 * Various device capability configuration items
 *   -- Please note that some default CSS values are configured in the default style
 *      sheet BRS_CFG_CSS_DEFAULT_STYLE_SHEET. The values which are configured there
 *      overrides the below, in case of conflict.
 */

/* Enables pen navigation */
#define BRS_CFG_LE_SUPPORT_PEN_NAVIGATION
/* Enables vertical scroll and navigating using key up/down */
#define BRS_CFG_LE_SUPPORT_KEY_NAVIGATION
#ifdef BRS_CFG_LE_SUPPORT_KEY_NAVIGATION
/* Enables 4-way navigation */
#define BRS_CFG_LE_SUPPORT_KEY_NAVIGATION_4WKEY
#ifdef BRS_CFG_LE_SUPPORT_KEY_NAVIGATION_4WKEY
/* Determines the area where an element is considered focusable by
 * vertical or horizontal key navigation. The nbr defined is how much
 * larger the vertical key navigation area gets. 
 */
#define BRS_CFG_LE_RATIO_HORIZ_VERT 5
/* Enables subscription to one or several of the keys up, down, left
 * and right. 
 */
#undef BRS_CFG_LE_SUPPORT_KEY_SUBSCRIPTION
#endif
#endif

/* Automatically activate textinput gadgets when they are focused */
#undef BRS_CFG_LE_ACTIVATE_TEXTINPUT_ON_FOCUS
/* Activate textinput gadget when it is focused and one of key_0 to key_9 is pressed */
#undef BRS_CFG_LE_ACTIVATE_TEXTINPUT_ON_BUTTON_EVENT
/* Automatically move the focus from a gadget when ok is pressed */
#undef BRS_CFG_LE_MOVE_GADGET_FOCUS_ON_OK

/* Accesskey recommended rendering differ in WML and HTML. The below controls whether
 * the accesskey shall be drawn in content for both languages, for WML or never.
 * If neither BRS_CFG_LE_DRAW_ACCESSKEY nor BRS_CFG_LE_DRAW_ACCESSKEY_WML are defined,
 * accesskeys never generate a box and are not drawn but are still active.
 */
#undef BRS_CFG_LE_DRAW_ACCESSKEY	/* Due to Widget limitation */
#ifndef BRS_CFG_LE_DRAW_ACCESSKEY
#undef BRS_CFG_LE_DRAW_ACCESSKEY_WML	/* Due to Widget limitation */
#endif

/* Sets the LE to wrap around the screen. That is, to go to the bottom
 * of the page when pressing the scroll up key when page is at the top
 * and vice versa. */
#define BRS_CFG_LE_CONTENT_WRAPAROUND

/* When doing pen/scrollbar driven scrolling the scrolling is based on the change
 * to the control.*/

/* For scrolling with key navigation.*/
#define BRS_CFG_LE_SCROLL_PIXELSVERTICAL    21	/* Modify to scroll screen as long as larger than small font size */
#define BRS_CFG_LE_SCROLL_PIXELSHORIZONTAL  50	

/* When using four way navigation, the below configuration is used to decide whether
 * an element is focusable, in case it is at the edge of the screen. The value is
 * the number of pixels its upper content edge must be inside the screen.
 */
#define BRS_CFG_LE_PIXELS_EDGE_VERTICAL_FOCUSABLE BRS_CFG_LE_SCROLL_PIXELSVERTICAL
/* Changed from BRS_CFG_LE_SCROLL_PIXELSHORIZONTAL to 21 for MAUI_00367853 */
#define BRS_CFG_LE_PIXELS_EDGE_HORIZONTAL_FOCUSABLE 21 /* BRS_CFG_LE_SCROLL_PIXELSHORIZONTAL */


/* The default width of a scrollbar in pixels. */
#define BRS_CFG_LE_SCROLLBAR_WIDTH MSF_CFG_SCROLLBAR_WIDTH

/* Enable this define to have string type font-families matched to the fonts of the 
 * device using HDIa_widgetFontGetFamily (eg "Times new roman"). If it is disabled only 
 * the generic font family values are forwarded to the integration.
 */
#undef BRS_CFG_LE_SUPPORT_STRING_FONT_FAMILY

/* If BRS_CFG_LE_CSS_INHERIT_BACKGROUND_COLOR is set background color values
 * are inherited, rather than defaulting to transparent.
 * If the host device is capable of using transparent colors this setting
 * should be undefined.*/
#define BRS_CFG_LE_CSS_INHERIT_BACKGROUND_COLOR

/* The pixel per centimeter configuration is used to convert length values using
 * measurements mm, inches, picas and points to pixels.*/
#define BRS_CFG_LE_CSS_PIXELS_PER_CENTIMETER 33


/**************************************************
 * CSS and look-and-feel configuration
 *  -- Please note that many of the below are expected to require configuration.
 *     The most probable configs are collected at the start of the below list.
 */

/* Configures the padding of the outermost block, making the content being
 * rendered some distance into the page.
 * The same configuration is used for cards.*/
#define BRS_CFG_LE_CSS_BODY_PADDING_PIXELS 8

/* The below constant should be configured large enough to fit the marker
 * images used for list items. That is, a list item marker will end up in
 * the margin of its parent list if it can fit, otherwise it will be inlined.
 */
#define BRS_CFG_LE_CSS_LIST_BLOCK_LEFT_MARGIN_PX 20

/* Font sizes in pixels. Those are recommended to scale by a factor of 1.2. 
 * Depending on the number of supported sizes, some values may be set at the same
 * number. For instance, a device supporting two font sizes may choose to set every
 * value up to medium to the smallest font size, and everything from large and
 * upwards to the higher value.*/
#define BRS_CFG_LE_CSS_XX_SMALL_FONT_SIZE_PX  10
#define BRS_CFG_LE_CSS_X_SMALL_FONT_SIZE_PX   12
#define BRS_CFG_LE_CSS_SMALL_FONT_SIZE_PX     14
#define BRS_CFG_LE_CSS_MEDIUM_FONT_SIZE_PX    17
#define BRS_CFG_LE_CSS_LARGE_FONT_SIZE_PX     21
#define BRS_CFG_LE_CSS_X_LARGE_FONT_SIZE_PX   25
#define BRS_CFG_LE_CSS_XX_LARGE_FONT_SIZE_PX  30

/* Default block top and bottom margin. This is defined as 1.33 em in the sample
 * style sheet in CSS2.*/
#define BRS_CFG_LE_CSS_BLOCK_TOP_BOTTOM_MARGIN_PX (int)(BRS_CFG_LE_CSS_MEDIUM_FONT_SIZE_PX * 1)

/* The heading elements are defaulted with the following default CSS info:
 *  H1 { font-size: xx-large; font-weight: bold} 
 *  H2 { font-size: x-large; font-weight: bold } 
 *  H3 { font-size: large; font-weight: bold } 
 *  H4 { font-size: large ; font-style: italic ; font-weight: bold} 
 *  H5 { font-size: medium; font-weight: bold} 
 *  H6 { font-size: medium; font-style: italic ; font-weight: bold} 
 * To override the above use the default style sheet.
 * In addition, margins of headings are based on the H1 margin defined below. 
 * For instance, the top and bottom margins for H2 are 1.33 times as large as the 
 * H1 margin, and the H3 top bottom margins are 1,5 times as long as the H1 top 
 * and bottom margins.*/
#define BRS_CFG_LE_CSS_H1_MARGIN_TOP_BOTTOM_PX 10

/* The minimum table row height. This is used in WML when all cells of a row
 * has no height themselves. WML expects table rows to take up space even when
 * no data is entered into the cell. This config item relates to the TOG test
 * wml/struct/text/tr/1.*/
#define BRS_CFG_LE_WML_MIN_ROW_HEIGHT_PX 7
/* The minimum table column width. This is used when the WML restriction to create
 * unexisting table cells makes a full row have no real content and thus no intrinsic
 * width.
 */
#define BRS_CFG_LE_WML_MIN_EMPTY_COLUMN_WIDTH_PX 20

/* Default WML table border width. If 0, no default borders are used.*/
#define BRS_CFG_LE_DEFAULT_WML_BORDER_WIDTH BRS_CFG_LE_CSS_BORDER_THIN_PIXELS

/*
 * The below items are assumed to be of less importance to configure.
 */

/* If a border-style but no width has been set in the document, this width
 * will be used*/
#define BRS_CFG_LE_CSS_BORDER_THIN_PIXELS   1
#define BRS_CFG_LE_CSS_BORDER_MEDIUM_PIXELS 2
#define BRS_CFG_LE_CSS_BORDER_THICK_PIXELS  3
#define BRS_CFG_LE_CSS_DEFAULT_BORDER_WIDTH BRS_CFG_LE_CSS_BORDER_THIN_PIXELS

/* Substitute tab char (0x09) in strings inside pre elements. */
#define BRS_CFG_LE_TAB_VALUE_IN_PRE "   "

/* The height in pixels of a horizontal ruler.*/
#define BRS_CFG_LE_DEFAULT_HR_HEIGHT 2

/* The padding of a cell that does not have a specified padding, in pixels.*/
#define BRS_CFG_LE_DEFAULT_CELL_PADDING_PX 1

/* The background color used on the elements if none is otherwise set.*/
#define BRS_CFG_LE_DEFAULT_BACKGROUND             0x00ffffff

/* The foreground color used on the body/card element if none is otherwise set.*/
#define BRS_CFG_LE_DEFAULT_FOREGROUND             0x00000000

/* The background color used on the control elements if none is otherwise set.*/
#define BRS_CFG_LE_DEFAULT_CONTROL_BACKGROUND     0x00ffffff

/* The foreground color used on the control elements if none is otherwise set.*/
#define BRS_CFG_LE_DEFAULT_CONTROL_FOREGROUND     0x00000000


/* The default font.*/
/* Family should hold one of the MSF values corresponding to a generic font family.*/
#define BRS_CFG_LE_DEFAULT_FONT_FAMILY  MsfGenericFontSerif 
#define BRS_CFG_LE_DEFAULT_FONT_STYLE   BRS_CSS_VALUE_NORMAL
#define BRS_CFG_LE_DEFAULT_FONT_SIZE    BRS_CFG_LE_CSS_MEDIUM_FONT_SIZE_PX
/* 400 equals normal, eg non-bold.*/
#define BRS_CFG_LE_DEFAULT_FONT_WEIGHT  400

/* The default button colour */
#define BRS_CFG_LE_DEFAULT_BTN_COLOUR             0x00aaaaaa

/* Default fieldset border colour*/
#define BRS_CFG_LE_DEFAULT_FIELDSET_COLOUR        0x00000000

/* Default fieldset border width in pixels*/
#define BRS_CFG_LE_DEFAULT_FIELDSET_BORDER_WIDTH 1

/* Default fieldset border style, as CSS keyword*/
#define BRS_CFG_LE_DEFAULT_FIELDSET_STYLE BRS_CSS_VALUE_DOTTED

/* Default fieldset padding in pixels*/
#define BRS_CFG_LE_DEFAULT_FIELDSET_PADDING 1

/* Default object and image sizes. Used while loading or failed loading if the sizes
 * are not given by the document or css. */
#define BRS_CFG_LE_DEFAULT_OBJECT_WIDTH  20
#define BRS_CFG_LE_DEFAULT_OBJECT_HEIGHT 20

/**
 * Defines the default padding width for HTML lists, in px units
 */
#define BRS_CFG_LE_DEFAULT_LIST_PADDING           20 

#ifdef MTK_TMP_PATCH /* CR28889 */
/* Extra space between two adjacent lines */
#define BRS_CFG_LE_EXTRA_SPACE_BETWEEN_LINES    1
#endif

#endif


