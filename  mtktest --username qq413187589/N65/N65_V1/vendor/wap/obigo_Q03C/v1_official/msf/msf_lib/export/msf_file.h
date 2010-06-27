/*
 * Copyright (C) Obigo AB, 2002-2006.
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
 * msf_file.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 *   021014, IPN: Added MSF_FILE_CLOSE_ALL
 *
 */

#ifndef _msf_file_h
#define _msf_file_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif




/****************************************
 * File
 ****************************************/

#define MSF_FILE_OPEN                 HDIa_fileOpen

#define MSF_FILE_CLOSE                HDIa_fileClose

#define MSF_FILE_WRITE                HDIa_fileWrite

#define MSF_FILE_READ                 HDIa_fileRead

#define MSF_FILE_FLUSH                HDIa_fileFlush

#define MSF_FILE_SEEK                 HDIa_fileSeek

#define MSF_FILE_REMOVE               HDIa_fileRemove

#define MSF_FILE_RENAME               HDIa_fileRename

#define MSF_FILE_MKDIR                HDIa_fileMkDir

#define MSF_FILE_RMDIR                HDIa_fileRmDir

#define MSF_FILE_GETSIZE_DIR          HDIa_fileGetSizeDir

#define MSF_FILE_READ_DIR             HDIa_fileReadDir

#define MSF_FILE_READ_DIR_LONG        HDIa_fileReadDirLong

#ifdef MSF_USE_FILE_READ_DIR_SEQ
#define MSF_FILE_READ_DIR_SEQ         HDIa_fileReadDirSeq

#define MSF_FILE_READ_DIR_SEQ_CLOSE   HDIa_fileReadDirSeqClose
#endif /* MSF_USE_FILE_READ_DIR_SEQ */

#define MSF_FILE_SETSIZE              HDIa_fileSetSize

#define MSF_FILE_GETSIZE              HDIa_fileGetSize

#define MSF_FILE_SELECT               HDIa_fileSelect

#define MSF_FILE_CLOSE_ALL            HDIa_fileCloseAll


#define MSF_FILE_SET_RDONLY    HDI_FILE_SET_RDONLY

#define MSF_FILE_SET_WRONLY    HDI_FILE_SET_WRONLY

#define MSF_FILE_SET_RDWR      HDI_FILE_SET_RDWR     

#define MSF_FILE_SET_APPEND    HDI_FILE_SET_APPEND

#define MSF_FILE_SET_CREATE    HDI_FILE_SET_CREATE

#define MSF_FILE_SET_EXCL      HDI_FILE_SET_EXCL

#define MSF_FILE_SET_BUFFERED  HDI_FILE_SET_BUFFERED


#define MSF_FILE_SEEK_SET    HDI_FILE_SEEK_SET

#define MSF_FILE_SEEK_CUR    HDI_FILE_SEEK_CUR

#define MSF_FILE_SEEK_END    HDI_FILE_SEEK_END


#define MSF_FILE_DIRTYPE     HDI_FILE_DIRTYPE 

#define MSF_FILE_FILETYPE    HDI_FILE_FILETYPE


#define MSF_FILE_EVENT_READ  HDI_FILE_EVENT_READ

#define MSF_FILE_EVENT_WRITE HDI_FILE_EVENT_WRITE


#define MSF_FILE_READ_READY  HDI_FILE_READ_READY

#define MSF_FILE_WRITE_READY HDI_FILE_WRITE_READY


#define MSF_FILE_OK             HDI_FILE_OK

#define MSF_FILE_ERROR_ACCESS   HDI_FILE_ERROR_ACCESS

#define MSF_FILE_ERROR_DELAYED  HDI_FILE_ERROR_DELAYED

#define MSF_FILE_ERROR_PATH     HDI_FILE_ERROR_PATH

#define MSF_FILE_ERROR_INVALID  HDI_FILE_ERROR_INVALID

#define MSF_FILE_ERROR_SIZE     HDI_FILE_ERROR_SIZE

#define MSF_FILE_ERROR_FULL     HDI_FILE_ERROR_FULL

#define MSF_FILE_ERROR_EOF      HDI_FILE_ERROR_EOF

#define MSF_FILE_ERROR_EXIST    HDI_FILE_ERROR_EXIST

#endif
