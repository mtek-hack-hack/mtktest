#ifndef	_GIF_CLIB_H_
#define _GIF_CLIB_H_

#include "CmsBrowserPublic.h"
#include "CmsFunc.h"

#define GIFDEBUG	//printf

/* BASIC DATA TYPE DEFINES */


typedef unsigned char GIF_U8; 		/*=== unsigned 8 bit data  ===*/
typedef unsigned short GIF_U16; 	/*=== unsigned 16 bit data ===*/
typedef unsigned int GIF_U32; 		/*=== unsigned 32 bit data ===*/
typedef unsigned long GIF_U64; 		/*=== unsigned 64 bit data ===*/
typedef char GIF_S8; 				/*=== signed 8 bit data  ===*/
typedef short GIF_S16; 				/*=== signed 16 bit data ===*/
typedef int GIF_S32; 				/*=== signed 32 bit data ===*/
typedef long GIF_S64; 				/*=== signed 64 bit data ===*/
typedef void GIF_VOID;				/*=== void ===*/

typedef GIF_U8 * P_GIF_U8;
typedef GIF_U16 * P_GIF_U16; 
typedef GIF_U32 * P_GIF_U32;
typedef GIF_U64 * P_GIF_U64;  
typedef GIF_S8 * P_GIF_S8;
typedef GIF_S16 * P_GIF_S16;  
typedef GIF_S32 * P_GIF_S32; 
typedef GIF_S64 * P_GIF_S64;
typedef GIF_VOID * P_GIF_VOID;

typedef GIF_S32 GIF_BOOL;
typedef FILE* GIF_FILE;


/* define string process functions */
GIF_U32 GIF_strlen (const GIF_S8* str);
GIF_S8 *GIF_strstr (const GIF_S8 *str, const GIF_S8 *find);
GIF_S8 *GIF_strcpy (GIF_S8 *dst,  const GIF_S8 *src);
GIF_S8 *GIF_strncpy (GIF_S8 *dst, const GIF_S8 *src, GIF_U32 num);
GIF_S32 GIF_strcmp (GIF_S8 *str1,  const GIF_S8* str2);
GIF_S32 GIF_strncmp (GIF_S8 *str1,  const GIF_S8 *str2,  GIF_U32 num);
GIF_S32 GIF_strcasecmp (GIF_S8 *str1, GIF_S8 *str2);
GIF_S8 *GIF_strcat (GIF_S8 *str,  const GIF_S8 *append);
GIF_S8 *GIF_strncat (GIF_S8 *str,  const GIF_S8 *append, GIF_U32 num);

/* define memory process functions */
GIF_VOID *GIF_malloc(GIF_S32 line, GIF_U16 size);
GIF_VOID GIF_free(GIF_S32 line, GIF_VOID *ptr);
GIF_VOID GIF_memset(GIF_VOID *ptr, GIF_U8 value, GIF_U32 size);
GIF_VOID GIF_memcpy(GIF_VOID *dptr, GIF_VOID *sptr, GIF_U32 size);
void* GIF_remalloc(GIF_VOID *address, GIF_U16 oldsize, GIF_U16 size );

/* define file process functions */
GIF_FILE GIF_fopen(GIF_S8 *filename, const GIF_S8 *option);
GIF_BOOL GIF_fclose(GIF_FILE fp);
GIF_U32 GIF_fread(GIF_VOID *buf, GIF_U32 size, GIF_U32 times, GIF_FILE fp);
GIF_U32 GIF_fwrite(GIF_VOID *buf, GIF_U32 size, GIF_U32 times, GIF_FILE fp);
GIF_S32 GIF_fseek(GIF_FILE fp, GIF_S64 size, GIF_S32 base);
GIF_S64 GIF_ftell(GIF_FILE fp);


int GIF_drawpoint(GIF_S32 x, GIF_S32 y, GIF_U16 color);
void GIF_refreshwindow(void);
long GIF_getms(void);
void *GIF_settimer(int value, int *id, int taskid);
void GIF_killtimer(void *timer);


int gif_clearmempool();
int gif_setmempool(void *mempool);



#endif /* _GIF_CLIB_H_ */
