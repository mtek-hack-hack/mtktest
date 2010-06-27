/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   fsal.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   File System Abstraction Layer, with buffered read/write.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/**
 * \file fsal.h
 * \author Murphy Chen
 * \version $Revision:   1.26  $
 * \date $Modtime:   May 16 2005 23:18:18  $
 *
 * FSAL stands for File System Abstraction Layer.
 * This layer provides the following functionalities:
 * - Isolate the underlying file systems.
 * - Provide buffered read/write operations.
 * - Provide bits/bytes accessing functions.
 */

#ifndef __FSAL_BUFFER_H__
#define __FSAL_BUFFER_H__


#ifndef FSAL_STANDALONE
   /// For target and MoDIS
   #define FSAL_VERBOSE 0
   #include "kal_release.h"
   #include "fat_fs.h"
   #include "med_status.h"
   /// access MOD_MED module ID for kal_prompt_trace
   #include "stack_config.h"
   /// for kal_prompt_trace
   #include "kal_trace.h"
   #define FSAL_PLATFORM_KAL 1
   #define FSAL_PLATFORM_WIN32 0
   #define FSAL_PLATFORM_MEMORY 0
#else
   /// For Win32 standalone application, unit test and PC Simulator
   #include <stdio.h>
   #include <assert.h>
   #include <string.h>
   #ifndef ASSERT
      #define ASSERT(x) assert(x)
   #endif
   #define FSAL_VERBOSE 0
   #define kal_mem_cpy(a,b,c) memcpy(a,b,c)
   #include "kal_non_specific_general_types.h"
   #define MED_STAT_FSAL_START 0
   #define FSAL_PLATFORM_KAL 0
   #define FSAL_PLATFORM_WIN32 1
   #define FSAL_PLATFORM_MEMORY 0
#endif

typedef enum {
   FSAL_OK = MED_STAT_FSAL_START,
   FSAL_OPEN_ERROR,
   FSAL_READ_ERROR,
   FSAL_WRITE_ERROR,
   FSAL_SEEK_ERROR,
   FSAL_CLOSE_ERROR,
   FSAL_INVALID_ARGUMENT,
   /// The field of the structure is invalid. Possibly caused by memory corruption.
   FSAL_MEMORY_CORRUPTION,
   FSAL_FATAL_ERROR,
   FSAL_DEVICE_BUSY,
   FSAL_READ_OVER_EOF,
   FSAL_SEEK_OVER_EOF
} FSAL_Status;



typedef enum {
   /// Open for reading.
   FSAL_READ = 0,
   /// Open for reading and writing.
   /// The file is created if it is not existed, otherwise it is truncated.
   FSAL_WRITE,
   /// Open for reading and appending.
   /// The file is created if it is not existed.
   FSAL_APPEND,
   /// Open a ROM file for reading.
   /// FSAL_Direct_SetRamFileSize shall be called before calling FSAL_Open.
   FSAL_ROMFILE,
   ///
   FSAL_READ_SHARED,
   FSAL_NONBLOCKING = 0x80
} FSAL_FileMode;

/**
 * The memory space of the FSAL structure is prepared by the caller.
 * Accesses to each file requires a separate instance of each FSAL structure.
 * The content of the structuer will be initialized via the FSAL_Open
 * function call.
 * And the pointer to the structure need to be passed as the first argument
 * to each FSAL function invocations.
 */
typedef struct {
   /* file system abstration layer*/
#if FSAL_PLATFORM_KAL
   FS_HANDLE hFile;
   /// error code from file system
   kal_int32 iFSErrorCode;
#elif FSAL_PLATFORM_MEMORY
   kal_uint32 uMaxRamFileSize;
#elif FSAL_PLATFORM_WIN32
   FILE *hFile;
#endif
   /// For ROM file. Point to the start memory address of the file.
   kal_uint8 *pbFile;
   kal_uint32 uRamFileSize;
   kal_uint32 uRamFileOffset;
   kal_uint32 uFileSize;
   kal_uint32 uFileOffset;
   kal_bool bBuffering;
   kal_uint8 *pbBuf;
   kal_uint32 uBufSize;
   kal_uint32 uCachedBlock;
   kal_bool bDirty; /* whether the cache has been written to */
   kal_uint32 uLastReadCount;
   kal_uint32 uDRMpermission;
} STFSAL;

/* ------ Private Macros ------ */

#define FSAL_CHECK_ARG(exp) \
   if (!(exp)) \
      return FSAL_INVALID_ARGUMENT

#define FSAL_ASSERT(exp) \
   if (!(exp)) \
      return FSAL_FATAL_ERROR

#define FSAL_ASSERT_NO_RET_VAL(exp) \
   if (!(exp)) \
      return

/* ------ public functions ------ */

/**
 * Open the file.
 *
 * @param pstFSAL pointer to FSAL structure prepared by caller.
 * FSAL will initialize the structure.
 * @param szFile pointer to a string contained the file name when opened in FSAL_READ,
 * FSAL_WRITE, or FSAL_APPEND mode; pointer to the start memory address of the file
 * when opened in FSAL_ROMFILE mode.
 * @param eMode file operation mode.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Open(STFSAL *pstFSAL, void *szFile, FSAL_FileMode eMode);

/**
 * Open the file which has been opened via file I/O API with its file handle.
 * Please do not call FSAL_Close for this handle.
 *
 * @param pstFSAL pointer to FSAL structure prepared by caller.
 * FSAL will initialize the structure.
 * @param pFileHandle file handle of the underlying file I/O API.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Open_WithHandle(STFSAL *pstFSAL, void *pFileHandle);

/**
 * Open an existing file. When using this interface, you need to consider
 * about the issues of multiple access to the same file.
 * Please do not call FSAL_Close for this handle.
 *
 * @param pstFSAL pointer to FSAL structure prepared by caller.
 * FSAL will initialize the structure.
 * @param pstFSAL_Existing pointer to an existing FSAL structure,
 * FSAL will access file opened via the file handle in that structure.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Open_Attach(STFSAL *pstFSAL, STFSAL *pstFSAL_Existing);

/**
 * Client prepares its own buffer and call this function
 * to set buffer for FSAL cache.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param uBufferSize size of the buffer in unit of byte.
 * @param pbBuf memory location of the buffer
 *
 * @return None.
 */
void FSAL_SetBuffer(STFSAL *pstFSAL, kal_uint32 uBufferSize, kal_uint8 *pbBuf);

/**
 * Flush FSAL cache and close the file.
 *
 * @param pstFSAL pointer to FSAL structure.
 *
 * @return None.
 */
FSAL_Status FSAL_Close(STFSAL *pstFSAL);

/* ------ buffering functions (fsal_buffer.c) ------ */

/**
 * Read data from the file.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param pbBuf memory location of the data.
 * @param uSize number of bytes to read. uSize must be larger than 0.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Read(STFSAL *pstFSAL, kal_uint8* pbBuf, kal_uint32 uSize);

/**
 * Write data to the file.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param pbBuf memory location of the data.
 * @param uSize number of bytes to write. uSize must be larger than 0.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Write(STFSAL *pstFSAL, kal_uint8 *pbBuf, kal_uint32 uSize);

/**
 * Change file offset.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param uOffset offsets in unit of bytes.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Seek(STFSAL *pstFSAL, kal_uint32 uOffset);

/**
 * Flush FSAL cache to the underlying file system.
 *
 * @param pstFSAL pointer to FSAL structure.
 *
 * @return None.
 */
FSAL_Status FSAL_CacheFlush(STFSAL *pstFSAL);

/**
 * Get the current file position.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param puPosition memory location for retrieving the file position.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_GetCurPos(STFSAL *pstFSAL, kal_uint32 *puPosition);

/**
 * Get the file size.
 * The current file position remains the same after invocation.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param puFileSize memory location for retrieving the file size.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_GetFileSize(STFSAL *pstFSAL, kal_uint32 *puFileSize);



/* ------ bits/bytes read access functions (fsal_read.c) ------ */

/**
 * Read n bytes.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param pbData memory location for storing the result bytes
 * @param uLen number of bytes to read
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Read_Bytes(STFSAL *pstFSAL, kal_uint8 *pbData, kal_uint32 uLen);

/**
 * Read n bits.
 * When calling this function for the first time, *puBitCnt must be 0.
 * *puBitCnt will be updated after each invocation.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param puBitCnt memory location for storing the bit offset.
 * @param pbValue memory location for storing the result bits.
 * @param uBitLen number of bits to read (1~8).
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Read_Bits(STFSAL *pstFSAL, kal_uint32 *puBitCnt, kal_uint8 *pbValue, kal_uint32 uBitLen);

/**
 * Read 4 bytes representing an unsigned integer.
 * The content stored on the file is assumed to be big-endian.
 * This function will handle the endian-conversion issue.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param puValue memory location for storing the result unsigned integer
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Read_UINT(STFSAL *pstFSAL, kal_uint32 *puValue);

/**
 * Read 3 bytes representing an unsigned integer.
 * The content stored on the file is assumed to be big-endian.
 * This function will handle the endian-conversion issue.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param puValue memory location for storing the result unsigned integer
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Read_UINT24(STFSAL *pstFSAL, kal_uint32 *puValue);

/**
 * Read 2 bytes representing an unsigned integer.
 * The content stored on the file is assumed to be big-endian.
 * This function will handle the endian-conversion issue.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param pwValue memory location for storing the result unsigned integer
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Read_UINT16(STFSAL *pstFSAL, kal_uint16 *pwValue);

/**
 * Skip n bytes.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param uLen number of bytes to skip
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Skip_Bytes(STFSAL *pstFSAL, kal_uint32 uLen);

/**
 * Get next n bytes. The file offset does not change after invocation.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param pbValue memory location for storing the result bytes
 * @param uLen number of bytes to peek
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Peek_Bytes(STFSAL *pstFSAL, kal_uint8 *pbValue, kal_uint32 uLen);

/**
 * Get next unsinged integer. The file offset does not change after invocation.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param puValue memory location for storing the result unsigned integer
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Peek_UINT(STFSAL *pstFSAL, kal_uint32 *puValue);


/* ------ bits/bytes write access functions (fsal_write.c) ------ */

/**
 * Write n bytes.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param pbData memory location of the bytes
 * @param uLen number of bytes to write
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Write_Bytes(STFSAL *pstFSAL, kal_uint8 *pbData, kal_uint32 uLen);

/**
 * Write 4 bytes representing an unsigned integer.
 * The value written to the file will be stored as big-endian.
 * This function will handle the endian-conversion issue.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param uValue The value to be written to the file.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Write_UINT(STFSAL *pstFSAL, kal_uint32 uValue);

/**
 * Write 2 bytes representing an unsigned integer.
 * The value written to the file will be stored as big-endian.
 * This function will handle the endian-conversion issue.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param wValue The value to be written to the file.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Write_UINT16(STFSAL* pstFSAL, kal_uint16 wValue);

/**
 * Write 1 byte representing an unsigned character.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param bValue The value to be written to the file.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Write_UINT8(STFSAL* pstFSAL, kal_uint8 bValue);

/**
 * Write 4 bytes representing an unsigned integer at a given file offset.
 * File position remains the same after the invocation.
 * The value written to the file will be stored as big-endian.
 * This function will handle the endian-conversion issue.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param uValue The value to be written to the file.
 * @param uOffset The file offset to write to.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Write_UINT_AT(STFSAL* pstFSAL, kal_uint32 uValue, kal_uint32 uOffset);

/* ------ direct access functions (bypass buffering mechanism) ------ */

/**
 * Open the file. (Internal Use by FSAL Only)
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param szFile pointer to a string contained the file name.
 * @param eMode file operation mode.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Direct_Open(STFSAL *pstFSAL, void *szFile, FSAL_FileMode eMode);

/**
 * Close the file. (Internal Use by FSAL Only)
 *
 * @param pstFSAL pointer to FSAL structure.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Direct_Close(STFSAL *pstFSAL);

/**
 * Read data from the file directly.
 *
 * Use with caution. Becuase the file offset will be out-of-sync
 * between FSAL and underlying file system.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param pbBuf memory location of the data.
 * @param uSize number of bytes to read. uSize must be larger than 0.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Direct_Read(STFSAL *pstFSAL, kal_uint8* pbBuf, kal_uint32 uSize);

/**
 * Write data to the file directly.
 *
 * Use with caution. Becuase the file offset will be out-of-sync
 * between FSAL and underlying file system.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param pbBuf memory location of the data.
 * @param uSize number of bytes to write. uSize must be larger than 0.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Direct_Write(STFSAL *pstFSAL, kal_uint8* pbBuf, kal_uint32 uSize);

/**
 * Change file offset of the underlying file system directly.
 *
 * Use with caution. Becuase the file offset will be out-of-sync
 * between FSAL and underlying file system.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param uOffset offsets in unit of bytes.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Direct_Seek(STFSAL *pstFSAL, kal_uint32 uOffset);

/**
 * Get the current file position of the underlying file system directly.
 *
 * Use with caution. Becuase the file offset may be out-of-sync
 * between FSAL and underlying file system.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param puPosition memory location for retrieving the file position.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Direct_GetCurPos(STFSAL *pstFSAL, kal_uint32* puPosition);

/**
 * Get the file size of the underlying file system directly.
 * The current file position remains the same after invocation.
 *
 * Use with caution. Becuase the file size may be out-of-sync
 * between FSAL and underlying file system.
 *
 * @param pstFSAL pointer to FSAL structure.
 * @param puFileSize memory location for retrieving the file size.
 *
 * @return If the function succeeds, the return value is FSAL_OK.
 * Otherwise, an error code is returned.
 */
FSAL_Status FSAL_Direct_GetFileSize(STFSAL *pstFSAL, kal_uint32 *puFileSize);

/**
 * When using ram file, this funtion shall be called before calling FSAL_Open.
 */
void FSAL_Direct_SetRamFileSize(STFSAL *pstFSAL, kal_uint32 uSize);

/**
 * When writing to ram file, if after a write operation, the file offset exceeds
 * the specified ram file size, an assertion will be issued in order to detect
 * memory corruption.
 */
void FSAL_Direct_SetMaxRamFileSize(STFSAL *pstFSAL, kal_uint32 uSize);

/**
 * Get the last file system error.
 */
int FSAL_GetLastError(STFSAL *pstFSAL);

/**
 * If the pstFSAL is a handle of ram file, return KAL_TRUE; otherwise return KAL_FALSE.
 */
kal_bool FSAL_IsRamFile(STFSAL *pstFSAL);

/**
 * If the pstFSAL is a handle of ram file, return pointer to the memory block; otherwise return NULL.
 */
kal_uint8* FSAL_GetRamFilePointer(STFSAL *pstFSAL);

/**
 * Get the data count (in bytes) read in the previous read operation.
 * Generally, call this function if the return value of the previous read operation if FSAL_READ_OVER_EOF.
 */
int FSAL_GetLastReadCount(STFSAL *pstFSAL);

#endif

