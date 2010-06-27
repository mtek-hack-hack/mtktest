
#ifndef CMS_BASEDEF_H
#define CMS_BASEDEF_H

typedef unsigned char			CMS_U8;			/* unsigned 8 bit data  */
typedef unsigned short			CMS_U16;		/* unsigned 16 bit data */
typedef unsigned int			CMS_U32;		/* unsigned 32 bit data */
typedef unsigned long			CMS_U64;		/* unsigned 64 bit data */
typedef signed char				CMS_S8;			/* signed 8 bit data  */
typedef signed short			CMS_S16;		/* signed 16 bit data */
typedef signed int				CMS_S32;		/* signed 32 bit data */
typedef signed long				CMS_S64;		/* signed 64 bit data */


#define CMS_VOID				void

typedef CMS_U8 *			P_CMS_U8;
typedef CMS_U16 *			P_CMS_U16; 
typedef CMS_U32 *			P_CMS_U32;
typedef CMS_U64 *			P_CMS_U64;  
typedef CMS_S8 *			P_CMS_S8;
typedef CMS_S16 *			P_CMS_S16;  
typedef CMS_S32 *			P_CMS_S32; 
typedef CMS_S64 *			P_CMS_S64;
typedef CMS_VOID *			P_CMS_VOID;

typedef	CMS_U8				CMS_BOOL;
typedef char					CMS_CHAR;		/* Li Shouming 2004.8.6*/
typedef CMS_CHAR *			P_CMS_CHAR;/* add by Li Shouming 2004.8.6*/


typedef CMS_U32				u32	;
typedef char				ascii;

#define CMS_YES             (CMS_BOOL)1
#define CMS_NO              (CMS_BOOL)0

#ifndef NULL
#define NULL  (void *)0
#endif

#ifndef FILE_HANDLE
#define FILE_HANDLE int
#endif

#endif  //CMS_BASEDEF_H
