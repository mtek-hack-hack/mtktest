/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: filefunc.h

    $Revision:

    $vision:       1.00

    $Date:         04/17/2003

    $Author:       longqiangl

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


#ifndef _FILE_FUNC__H_
#define _FILE_FUNC__H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _CMS_FILE_SYSTEM_SUPPORTED
	typedef FILE*	FILE_HANDLE;
#else
	#ifndef FILE_HANDLE
		#define FILE_HANDLE int
	#endif
#endif


	
#define CMS_SEEK_SET        0               /* seek to an absolute position */
#define CMS_SEEK_CUR        1               /* seek relative to current position */
#define CMS_SEEK_END        2               /* seek relative to end of file */


FILE_HANDLE mmsf_Open(char *fname,const char *mode);
int			mmsf_Read(char *buf,int size,int count,FILE_HANDLE fd);
int			mmsf_Fflush(FILE_HANDLE fd);
int			mmsf_Write(char *buf,int size,int count,FILE_HANDLE fd);
int			mmsf_Getc(FILE_HANDLE fd);
int			mmsf_Putc(int c, FILE_HANDLE fd);
void		mmsf_Close(FILE_HANDLE fd);
int			mmsf_Seek(FILE_HANDLE fd,int offset,int origin);
int	        mmsf_Remove(char *fname);
int         mmsf_RemoveByHandle(FILE_HANDLE fd);
int         mmsf_Tell(FILE_HANDLE fd);
int			mmsf_Rename(char *old_fname,char *new_fname);
int         mmsf_GetFileData(char *filename,char **data,int *len);
int         mmsf_SetFileData(char *filename,char *data,int len);
int			cmsf_SetFileData(char *filename,char *data,int len);
int         mmsf_GetConstFileData(char *filename,char **data,int *len);
int         mmsf_FileDuplicate(char *src_fname,char *des_fname);
int         mmsf_SetFilepBuf(char *fname,int size);   //2003.9.2
int         mmsf_ifFileExited(char *fname);
int         mmsf_MediaFileRefPlus1(char *fname);
int         mmsf_MediaFileRefSubstract1(char *fname);
int         mmsf_GetMediaFileRefNum(char *fname);
int         mmsf_Feof(FILE_HANDLE fd);
int         init_mms_mem_file_info(void);
void	    destroy_mms_mem_file_info(void);
char* mmf_getFileBufPtr( FILE_HANDLE fd );
char *mmf_getFileBufPtrByName(char *fname, int *length);

int mmsf_GetFileInfo( char			*name,		/* file name	*/
					 unsigned char **buf,		/* (out)buf		*/
					 int			*buf_len);	/* (out)buf len	*/

int	mmf_CreateFile(char			*fname,	/* 文件名称		*/
				   unsigned char *buf,	/* 已知的内存块	*/
				   int			 size	/* 内存的大小	*/
				   );
int	mmf_DestroyFile(char *fname);
int mmf_Write(char *buf,int size,int count,FILE_HANDLE fd);

int			mmf_CreateFile(char			*fname,	/* 文件名称		*/
						   unsigned char *buf,	/* 已知的内存块	*/
						   int			 size	/* 内存的大小	*/
						   );
int	mmf_DestroyFile(char *fname);


char* mmf_getFileBufPtr(FILE_HANDLE fd);

#endif  /*	_FILE_FUNC__H_	*/