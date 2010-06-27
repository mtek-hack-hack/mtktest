/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: WAP STACK Ver 1.20
 
 File Name   : Cms_WAPOctStr.h

 Description : To Implement Browser application

 Last Modify : 06/22/2002
 
 Written By  : Mobilesoft Technology

******************************************************************************/

#ifndef _CMS_WAPOCTSTR_H
#define _CMS_WAPOCTSTR_H

/***********************************************************/

#include "stdio.h"
//#include "Cms_WAPTypes.h"
//#ifndef CHARSET//zhangyanjun 0628用来防止下面的类型重复定义
//typedef unsigned char			CMS_U8;			/* unsigned 8 bit data  */
//typedef unsigned short			CMS_U16;			/* unsigned 16 bit data */
//typedef unsigned int			CMS_U32;			/* unsigned 32 bit data */
//typedef unsigned long			CMS_U64;			/* unsigned 64 bit data */
//typedef signed char				CMS_S8;			/* signed 8 bit data  */
//typedef signed short			CMS_S16;			/* signed 16 bit data */
//typedef signed int				CMS_S32;			/* signed 32 bit data */
//typedef signed long				CMS_S64;			/* signed 64 bit data */
//#if 0	/* declaring a void parameter list with a typedef is nonstandard. */
//typedef void					CMS_VOID;			/*void*/
//#else
//#define CMS_VOID				void
//#endif
//
//typedef CMS_U8 *			P_CMS_U8;
//typedef CMS_U16 *			P_CMS_U16; 
//typedef CMS_U32 *			P_CMS_U32;
//typedef CMS_U64 *			P_CMS_U64;  
//typedef CMS_S8 *			P_CMS_S8;
//typedef CMS_S16 *			P_CMS_S16;  
//typedef CMS_S32 *			P_CMS_S32; 
//typedef CMS_S64 *			P_CMS_S64;
//typedef CMS_VOID *			P_CMS_VOID;
//
//typedef	CMS_U8				CMS_BOOL;			/*--Shawn 2003-01-02*/
//
//#ifndef NULL
//#define NULL 0
//#endif
//#endif
#include "cms_basedef.h"
/**********************************************************/

struct _Octstr 
{
	P_CMS_U8 data;
	CMS_S64 len;
	CMS_S64 size;
};

typedef struct _Octstr Octstr;

/*===============================================*/

/* Reserve space for at least 'size' octets */
//static CMS_VOID octstr_grow(Octstr *ostr, CMS_S64 size) ;


/*
 * Create an empty octet string. Return pointer to the new object.
 */
Octstr *octstr_create_empty(CMS_VOID);


/*
 * Create an octet string from a NUL-terminated C string. Return pointer to
 * the new object.
 */
Octstr *octstr_create(P_CMS_U8 cstr);

/*
 * Create an octet string from arbitrary binary data. The length of the
 * data is given, so it can contain NUL characters.
 */
Octstr *octstr_create_from_data(P_CMS_VOID data, CMS_S64 len);

Octstr *OTA_octstr_create_from_data(P_CMS_VOID data, CMS_S64 len);


/*
 * Destroy an octet string, freeing all memory it uses. A NULL argument
 * is ignored.
 */
CMS_VOID octstr_destroy(Octstr *ostr);


/*
 * Return the length of (number of octets in) an object string.
 */
long octstr_len(Octstr *ostr);


/*
 * Create a new octet string by copying part of an existing one. Return 
 * pointer to the new object. If `from' is after end of `ostr', an empty
 * octet string is created. If `from+len' is after the end of `ostr', 
 * `len' is reduced appropriately.
 */
Octstr *octstr_copy(Octstr *ostr, CMS_S64 from, CMS_S64 len);


/*
 * as copy but duplicates entirely
 */
Octstr *octstr_duplicate(Octstr *ostr);


/*
 * Return value of octet at a given position in an octet string. The returned
 * value has a range of 0..255 for valid positions, and -1 if `pos' is
 * after the end of the octet string.
 */
CMS_U8 octstr_get_char(Octstr *ostr, CMS_S64 pos);


/*
 * Replace a single, existing character in an octet string. Operation cannot
 * fail: if pos is not inside the string, the operation will silently be
 * ignored.
 */
CMS_VOID octstr_set_char(Octstr *ostr, CMS_S64 pos, CMS_U8 ch);



/*
 * Return pointer to contents of octet string as a NUL-terminated C string.
 * This is guaranteed to have a NUL character at the end, but it is not
 * guaranteed (how could it?) to not contain NUL characters elsewhere.
 * The pointer points directly into the internal buffer of the octet
 * string, and must not be modified, and must not be used after any
 * octstr_* function that modifies the octet string is called after this
 * one. It is meant for printing debug messages easily.
 *
 * If the octet string is empty, an empty C string is returned, not NULL.
 */
P_CMS_U8 octstr_get_cstr(Octstr *ostr);


/*
 * Insert characters from C array into an octet string. `pos' 
 * gives the position in `ostr' where `data' should be inserted. `len'
 * gives the number of characters in `data'.
 * If the given `pos' is greater than the length of the input octet string,
 * it is set to that length, resulting in an append.
 */
int octstr_insert_data(Octstr *ostr, CMS_S64 pos, P_CMS_U8 data, CMS_U32 len);


/*
 * Append characters from C array at the tail of an octet string.
 */
CMS_VOID octstr_append_data(Octstr *ostr, P_CMS_U8 data, CMS_U32 len);


/*
 * Append a normal C string at the tail of an octet string.
 */
CMS_VOID octstr_append_cstr(Octstr *ostr, P_CMS_U8 cstr);


/*
 * Append a single character at the tail of an octet string.
 */
CMS_VOID octstr_append_char(Octstr *ostr, CMS_U32 ch);


/*
 * Delete part of an octet string.
 */
CMS_VOID octstr_delete(Octstr *ostr1, CMS_S64 pos, CMS_S64 len);


CMS_VOID octstr_insert(Octstr *ostr1, Octstr *ostr2, CMS_S64  pos);

#endif
