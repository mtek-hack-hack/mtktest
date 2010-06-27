/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2004
 ALL RIGHTS RESERVED

================================================================

工程名称		: WAP2.0 HTTP STACK
 
文件名			: Cms_WHTTPCookie.h

功能描述		: this module provides a simple HTTP Cookie handling mechanism

最近修改时间	: 8/5/2004
 
代码编写人员	: Li Shouming;shoumingl@mobilesoft.com.cn

================================================================*/
#ifndef _CMS_WHTTPCOOKIE_H
#define _CMS_WHTTPCOOKIE_H

#ifdef __cplusplus
extern "C" {
#endif

#define PUBLIC
#define PRIVATE static

/*

  Initiate and Terminate Cookie Handling

In order to start handling cookies, you need to initiate the module. Likewise,
when you are done, you must terminate the module in order to clean up memory
etc. Note that this cookie handler doesn't provide storage room for cookies
- the application MUST do that by registering cookie
callbacks. Initiation does one thing now only:
O
	Let user to determine wether choose cookie service

*/

CMS_BOOL HTCookie_init (CMS_VOID);
CMS_BOOL HTCookie_terminate (CMS_VOID);
/*
  The Cookie Class
The cookie class is used to handle cookies in libwww and to hand them off
to the application. The creation and deletion of cookie object is handled
by this cookie module - the application is handed a cookie and can access
the elements using the following methods:
*/

/* Our cookies */
typedef struct {
    unsigned char *name;
    unsigned char *domain;
    unsigned char *path;
    unsigned char *expiration;
    CMS_BOOL	  *secure;
} HTSETCookie;



CMS_BOOL HTCookie_isSecure (HTSETCookie * me);

/*
  Cookie Handling Mode
The application can decide how cookies are to be handled - should they be
ignored, should the user be asked, etc.
*/
typedef enum _HTCookieMode {
    HT_COOKIE_ACCEPT          = 0x1,  /* Accept cookies */
    HT_COOKIE_SEND            = 0x2,  /* Send cookies when fit */
    HT_COOKIE_SAME_HOST       = 0x4,  /* Don't accept cookies for other hosts */
    HT_COOKIE_SAME_DOMAIN     = 0x8,  /* Don't accept cookies for other domains */
    HT_COOKIE_PROMPT          = 0x10  /* Prompt before accepting cookies */
} HTCookieMode;
CMS_BOOL HTCookie_setCookieMode (HTCookieMode mode);
HTCookieMode HTCookie_getcookieMode (void);
/*
*/
extern void HTTPCookie_Add2File(const unsigned char * strSetcookie);
extern int GetPromptCookie(unsigned char * cookies);
extern void DeleteCookie(void);

#ifdef __cplusplus
};
#endif

#endif