/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


/*****************************************************************************
 *
 * Filename:
 * ---------
 * tst_ext.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains data structures for both L1 and PS traces
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef TST_EXT_H
#define TST_EXT_H


#include "fat_fs.h"


#define TST_COMMIT_BATCH 10
// (1<<24) is 16M, don't define it less than 1M (1<<20)
#define TST_MAX_LOG_SIZE_FOR_SINGLE_FILE (1<<24)
#define TST_FSWRITE_BUFFER_SIZE (1<<14)
//TST_L1_BUFFER_SIZE_FOR_WRITE_FILE must be smaller than TST_FSWRITE_BUFFER_SIZE
#define TST_L1_BUFFER_SIZE_FOR_WRITE_FILE (1<<13)

typedef struct 
{
  kal_bool   bWriteToFile;
  kal_bool   bWriteToFileOnly;
  kal_bool   bHeadOfOnePacket;
  kal_bool   bAssertForFull;

#if defined(__TST_WRITE_TO_FILE_ALSO__) || defined(__TST_WRITE_TO_FILE_ONLY__)
  kal_char   cDriveLetter;
  WCHAR      strAssertFolderName[64];
//  kal_uint16 nLogSN;
//  kal_uint16 nFileSN;
  kal_uint32 nDiskFreeSpace;
  kal_uint32 nFileFreeSpace;
  FS_HANDLE  fHandle;
  kal_uint32 nOmitPacketCount;
  kal_uint32 nBufferPtr;
  kal_uint32 nCommitCountDown;
  kal_uint8  buffer[TST_FSWRITE_BUFFER_SIZE];
#endif  
#if defined(__TST_WRITE_TO_FILE_ONLY__)
  kal_uint32 nL1BufferWritePtr;
  kal_uint32 nL1BufferVancancy;  
  kal_uint8  L1Buffer[TST_L1_BUFFER_SIZE_FOR_WRITE_FILE];
#endif
}
tst_dump_info_struct;

extern tst_dump_info_struct tst_dump_info;


#endif
