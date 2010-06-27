/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSCfg.h"

    $Revision:

    $vision:       1.00

    $Date:         05/16/2003

    $Author:       Shawn

	$Declare: 
	This document contains information proprietary to MobileSoft  
 Technology (Nanjing),  Corp.    Transmittal, receipt, or possession 
 of this document does not express, license, or imply any rights to 
 use, sell, design, or manufacture from this information. No reproduction, 
 publication, or disclosure of this information, in whole or in part, 
 shall be made without prior written authorization from an officer of 
 MobileSoft Technology (NanJing), Corp.

Abstract:

Modified By:

Environment: 

Revision History:

=====================================================================*/
#ifndef	_MMS_CLIB_H_
#define _MMS_CLIB_H_

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<math.h>
#include	"cms_sysfun.h"
#include    "Cms_MMSGlobal.h"
//zhangyanjun 0629
#ifndef CMS_MMS_FILE
#define CMS_MMS_FILE int 
#endif

/* define string process functions */
CMS_MMS_U32 MMS_strlen (const CMS_MMS_S8* str);
CMS_MMS_S8 *MMS_strstr (const CMS_MMS_S8 *str, const CMS_MMS_S8 *find);
CMS_MMS_S8 *MMS_strcpy (CMS_MMS_S8 *dst,  const CMS_MMS_S8 *src);
CMS_MMS_S8 *MMS_strncpy (CMS_MMS_S8 *dst, const CMS_MMS_S8 *src, CMS_MMS_U32 num);
CMS_MMS_S32 MMS_strcmp (CMS_MMS_S8 *str1,  const CMS_MMS_S8* str2);
//CMS_MMS_S8 *MMS_strncmp (CMS_MMS_S8 *str1,  const CMS_MMS_S8 *str2,  CMS_MMS_U32 num);
CMS_MMS_S32 MMS_strcasecmp (CMS_MMS_S8 *str1, CMS_MMS_S8 *str2);
CMS_MMS_S8 *MMS_strcat (CMS_MMS_S8 *str,  const CMS_MMS_S8 *append);
CMS_MMS_S8 *MMS_strncat (CMS_MMS_S8 *str,  const CMS_MMS_S8 *append, CMS_MMS_U32 num);
CMS_MMS_S32 MMS_strncmp (CMS_MMS_S8 *str1,  const CMS_MMS_S8 *str2,  CMS_MMS_U32 num);

/* define memory process functions */
CMS_MMS_VOID MMS_memset(CMS_MMS_VOID *ptr, CMS_MMS_U8 value, CMS_MMS_U32 size);
CMS_MMS_VOID MMS_memcpy(CMS_MMS_VOID *dptr, CMS_MMS_VOID *sptr, CMS_MMS_U32 size);
CMS_MMS_VOID *MMS_realloc(CMS_MMS_VOID *ptr,CMS_MMS_U32 orignsize,CMS_MMS_U32 totalsize);

/* define file process functions */
//int         init_mms_mem_file_info(void);
//void	    destroy_mms_mem_file_info(void);
CMS_MMS_FILE cms_fopen(CMS_MMS_S8 *filename, const CMS_MMS_S8 *option);
CMS_MMS_BOOL cms_fclose(CMS_MMS_FILE fp);
CMS_MMS_U32 cms_fread(CMS_MMS_VOID *buf, CMS_MMS_U32 size, CMS_MMS_U32 times, CMS_MMS_FILE fp);
CMS_MMS_U32 cms_fwrite(CMS_MMS_VOID *buf, CMS_MMS_U32 size, CMS_MMS_U32 times, CMS_MMS_FILE fp);
CMS_MMS_S32 MMS_fgetc(CMS_MMS_FILE fp);
CMS_MMS_S32 MMS_fputc(CMS_MMS_S32 value, CMS_MMS_FILE fp);
CMS_MMS_S32 cms_fseek(CMS_MMS_FILE fp, CMS_MMS_S64 size, CMS_MMS_S32 base);
CMS_MMS_S64 cms_ftell(CMS_MMS_FILE fp);
CMS_MMS_S32 MMS_fflush(CMS_MMS_FILE fd);

/* define other ansi c functions */
CMS_MMS_S8 *MMS_itoa (CMS_MMS_U32 value,  CMS_MMS_S8 *buf, CMS_MMS_U32 radix);
CMS_MMS_BOOL MMS_rand(CMS_MMS_U64 *pvalue);

//void	char2utf8(char *strin, char *strout, int length);
//void	utf82char(CMS_MMS_S8 *strin, CMS_MMS_S8 *strout, CMS_MMS_S32 length);


#endif /* _MMS_CLIB_H_ */
