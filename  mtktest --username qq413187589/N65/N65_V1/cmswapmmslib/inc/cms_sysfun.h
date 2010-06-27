/********************************************************************
  Copyright (c) 2001-2002 MobileSoft Corporation All Rights Reserved.
	Environment:		Windows 2000 
	Created:			13:10:2003   9:46
	Filename: 			cms_sysfun.h
	Author:				teng yong
	E_Mail:				yongt@moiblesoft.com.cn	
	    	
	Abstract:			常用系统函数;
	Modify records: 
	Who           When	  Where       For What      Status
	滕永	2003-10-13 NanJing     Create       Finished 
*********************************************************************/
#ifndef SYSFUN_H_
#define SYSFUN_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cms_RedirectFunc.h" // redirect function for TI Modified by TIPrj[2005/7/1]
#include "cms_TimerTrigger.h" //  Modified by TIPrj[2005/7/19]

#if defined( _MSC_VER ) && !defined( __CC_ARM ) && !defined( __ARM_CC )
#pragma warning ( disable: 4018 )	/* warning C4018: '<' : signed/unsigned mismatch */
#endif

/*************************************************************************
	 宏定义
 ************************************************************************/
/* win32 平台宏定义 */	
#define CMS_RGB(r,g,b)   ((unsigned long)(((unsigned char)(r)| \
						 ((unsigned short)((unsigned char)(g))<<8))|\
						 (((unsigned long)(unsigned char)(b))<<16)))

#define CMS_NRGB(color)  ((unsigned long)(((unsigned char)(255 - (char)(color&0x000000FF))| \
						 ((unsigned short)((unsigned char)(255 - (char)((color&0x0000FF00)>>8)))<<8))|\
						 (((unsigned long)(unsigned char)(255 - (char)((color&0x00FF0000)>>16)))<<16)))

#define ISWHITESPACE(c) (c==' ' || c=='\t' || c=='\r' || c=='\n' || c=='\f') 
#define STRCMP(a,R,b) (cms_strcmp(a, b) R 0)

#define INVALID_FILE_HANDLE		0
//#define HEAP_MEMORY_TYPE		/* 采用heap的方式分配内存 */

/*************************************************************************
	 类型定义
 ************************************************************************/
//typedef unsigned char FontType_t;
#ifndef FontType_t
#define FontType_t unsigned char
#endif
// Modified by TIPrj[2005/6/29]

//zhangyanjun 0628
#ifndef CMS_MMS_FILE
#define CMS_MMS_FILE int 
#endif
//typedef int CMS_MMS_FILE;
//zhangyanjun 0628
#ifndef FILE_HANDLE
#define FILE_HANDLE int
#endif
//typedef int FILE_HANDLE;


#ifndef TI //  Modified by TIPrj[2005/6/29]
#if defined( __cplusplus  ) && __cplusplus
extern "C"{
#endif
#endif 

void cms_heap_clean( void );

void *  cms_heap_alloc_raw( size_t sz );
void	cms_heap_free_raw( void* pv , size_t sz );
/* 与 realloc 不同的是在cms_heap_realloc_raw失败时, pv将不会被释放.*/
void *  cms_heap_realloc_raw( void* pv , size_t szold , size_t sznew ); 

void * cms_get_heap_handle( void );
void * cms_heap_alloc( size_t sz );
void   cms_heap_free ( void* pv  );
void * cms_heap_realloc( void* pv , size_t sznew );
size_t cms_heap_memsize( void* pv );

void * cms_heap_alloc_dbg( size_t sz , const char* file , int line );
void * cms_heap_realloc_dbg( void* pv , size_t sznew , const char* file , int line );


/************************************************************************
内存操作; 
************************************************************************/


#ifdef WIN32
	//测内存开关, WIN32默认打开
	#define  _D_TEST_MEMORY
	
	#ifdef _D_TEST_MEMORY

		#include "memory_test.h"
		#undef cms_malloc
		#undef cms_free
		#define cms_malloc	my_malloc
		#define cms_free(x) my_free(x)
		#define cms_bogusfree(x) my_bogusfree(x);

	#else
	
		void *cms_malloc(unsigned int size);
		void cms_free(void *pObject);	
		#define cms_bogusfree

	#endif

#else	
	
//测内存开关, 平台默认关闭
#ifndef CMS_RELEASE	
//#	define  _D_TEST_MEMORY	
#endif

#if	defined (_D_TEST_MEMORY)

		#include "memory_test.h"
		#undef cms_malloc

		#define cms_malloc	my_malloc
		#define cms_free(x) my_free(x)
		#define cms_bogusfree(x) my_bogusfree(x);

#else
		
#	if	defined( _MEMTRACE )

		void *cms_malloc_d(unsigned int size,char* filename,int line);
		void cms_free_d(void *pObject,char* filename,int line);
		#define cms_malloc(x)	cms_malloc_d(x,__FILE__,__LINE__)
		#define cms_free(x)		cms_free_d(x,__FILE__,__LINE__)
		#define cms_bogusfree

#	else
		void *cms_malloc(unsigned int size);
		void cms_free(void *pObject);
		#define cms_bogusfree
#	endif 
	
#endif



#endif

void *cms_memset(void *pObject,int value, unsigned int count);
void *cms_memcpy(void *pTarget, const void *pSource, unsigned int count);
void *cms_memmove(void *pTarget, const void *pSource, unsigned int count);		/* 增加 cms_memmove , liangl. */
void *cms_realloc(void *ptr,unsigned int orignsize,unsigned int totalsize);
//增加 cms_memcpy
int cms_memcmp( const void * lhs , const void* rhs , size_t len );
void *cms_realloc_mtk(void *ptr,unsigned int newsize);//20050912 cocoma xu add
/************************************************************************
	 字符串操作
************************************************************************/
#define cms_sprintf		sprintf
char *cms_strcpy( char *pTarget, const char *pSource );
char *cms_strncpy( char* lhs , const char* rhs , size_t sz );
unsigned int cms_strlen(const char *str);
char *cms_strstr( const char *p_string, const char *p_charset );
char *cms_strcat (char *dest, const char *src );
int  cms_strcmp(const char *pTarget,const char *pSource);
int  cms_strncmp(const char *pTarget,const char *pSource,int len);
int  cms_filelength(unsigned char *file_name);
char *cms_strchr(const char *p_string,char ch);
char *cms_strrchr(const char *p_string,char ch);
int  cms_atoi(const char * str);
char *cms_strncat( char* dst , const char* src , size_t sz );

char *cms_strUpcase(char* str);
int  cms_strUpcmp( const char* str1, const char* Upstrcase );
char *cms_strUpstr( const char* str1, const char* Upstrcase );
unsigned char *cms_memchar(unsigned char *str,unsigned char charTemp,int len);
int cms_stricmp(const char * str , const char * str2 );
int cms_strnicmp(const char * str , const char * str2 , size_t sz );
char*cms_stristr(const char * lstr,const char * rstr);
char*cms_strirstr( const char * lstr , const char * rstr );
unsigned char* cms_membytebyte(const unsigned char *strSur,
						  const unsigned char *strDst,
						  int			 lenstrSur,
						  int			 lenstrDst);
/************************************************************************
	unicode转化
*************************************************************************/
void Cms_FreeUTF16str(unsigned char* utf16str);
int Cms_Uni8_strlen(unsigned char * string);

//增加了 cms_strchr cms_strrchr cms_strncmp,由于不清楚系统是不是支持strchr,strrchr,strncmp，所以这三个函数全部重新写

/*************************************************************************
	 文件操作
 ************************************************************************/
CMS_MMS_FILE cms_fopen(char *filename, const char *option);
int cms_fclose(CMS_MMS_FILE fp);
unsigned int cms_fread(void *buf, unsigned int size, unsigned int times, CMS_MMS_FILE fp);
unsigned int cms_fwrite(void *buf, unsigned int size, unsigned int times, CMS_MMS_FILE fp);
int cms_fgetc(CMS_MMS_FILE fp);
int cms_fputc(int value, CMS_MMS_FILE fp);
int cms_fseek(CMS_MMS_FILE fp, long size, int base);
long cms_ftell(CMS_MMS_FILE fp);
int cms_fflush(CMS_MMS_FILE fd);


/************************************************************************/
/* 内在测试函数                                                         */
/************************************************************************/
void reset_memory_count( void );
void plus_memory_count( void );
void minus_meory_count( void );
void print_memory_count( void );


/*************************************************************************
	 平台特有函数
 ************************************************************************/
void mms_watchdog(void);
#define cms_watchdog mms_watchdog

/************************************************************************/
/* 下列内存是为了增加内在的使用效率而增加的								*/
/************************************************************************/
#define Array_36_b	36
extern unsigned char Array_36[Array_36_b];
#define Array_72_b	72
extern unsigned char Array_72[Array_72_b];
#define Array_128_b	128
extern unsigned char Array_128[Array_128_b];

#ifdef _D_DF
#define PS_MEM_MAX_SIZE	550*1024	/* 2m*/
#else
#define PS_MEM_MAX_SIZE	800*1024	/* 800K */
#endif

#ifndef TI //  Modified by TIPrj[2005/6/29]
#if defined( __cplusplus  ) && __cplusplus
}
#endif
#endif

#endif