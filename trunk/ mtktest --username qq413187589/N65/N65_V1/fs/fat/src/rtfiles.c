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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   rtfiles.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains core functions of file system.
 *
 * Author:
 * -------
 *
 *
 *============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include "kal_release.h"
#include "rtfiles.h"
#include "fs_kal.h"
#include "rtfex.h"
#include "fs_type.h"
#include "app_buff_alloc.h"
//#include "text_encoding.h" /* Add for SFN display issue, Karen Hsu, 2004/06/02, ADD */
extern kal_uint16 UCS2_TO_WCHAR(kal_uint16 src_char); /* Add for SFN display issue, Karen Hsu, 2004/10/08, ADD */

#ifdef _MSC_VER
   #define INTERN _fastcall
#elif defined __BORLANDC__
   #define INTERN __fastcall
#else
   #define INTERN
#endif

#define DIR_COMPACT_SUPPORT   // comment out if you do not need this
#define CHECK_DISK_SUPPORT    // comment out if you do not need this

#define RTF_DELETED           ((char) -27) // first char in file name of deleted file
#define RTF_LONGNAME_ATTR     (RTF_ATTR_READ_ONLY | RTF_ATTR_HIDDEN | RTF_ATTR_SYSTEM | RTF_ATTR_VOLUME)

#define RTFATUnknown  0
#define RTFAT12      12
#define RTFAT16      16
#define RTFAT32      32

#define RTF_CHAIN_END_MARK    0x0FFFFFFFL

#define BITS                  (8*sizeof(int))          // default # of bits in integer
#define FMAX                  (1 << (BITS/2))          // max number of file handles
#define UMAX                  ((1 << (BITS/2-1)) - 1)  // max Unique value for file handles

// partition type flags
#define RTF_PARTITION_FIRST_PRIMARY  0x00000001
#define RTF_PARTITION_EXTENDED       0x00000002
#define RTF_PARTITION_OTHER_PRIMARY  0x00000004
#define RTF_PARTITION_ALL            0x00000007 // all of the above

// flags specifying how buffers are loaded and errors should be handled
#define NO_RAISE     0x00000001
#define NO_CRITICAL  0x00000002
#define NO_LOAD      0x00000004
#define ALT_BUFFER   0x00000008

typedef struct DiskCheckData {
   DWORD                  Flags;
   RTFDrive             * Drive;
   BYTE                 * S;
   BYTE                 * ClusterMap;
   RTFCheckDiskCallback   ErrorHandler;
   RTFDOSDirEntry         D;
   char                   Path[RTF_MAX_PATH];
} DiskCheckData;

const WCHAR dchar_dot[]={0x2e, 0}; /* . */
const WCHAR dchar_dot_dot[]={0x2e, 0x2e, 0}; /* .. */
const WCHAR dchar_start_dot_star[]={0x2a, 0x2e, 0x2a, 0}; /* *.* */

// theses chars may appear on disk. Note that "." is not in ShortNameChars, but " " is
static const char ShortNameChars[] = " $%'-_@~`!(){}^#&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

static RTFDrive * DefaultDrive = NULL;
RTFMutex * RTFLock = NULL;

/* MTK Enhancement, Karen Hsu, ADD START */
/***********************************************************************/

#if (defined __FS_SYSDRV_ON_NAND__) && !(defined _NAND_FLASH_BOOTING_)
        /* Treat __FS_SYSDRV_ON_NAND__ equal _NAND_FLASH_BOOTING_ */
#define _NAND_FLASH_BOOTING_
#endif

//---------------------- MT Global Data --------------------------
static BYTE DrvMappingFlag = 0; //not mapping
int DrvMappingOld = 67; //default is C
int DrvMappingNew = 90; //default is Z
int SysLockFAT = 0; /* For USB mode to lock FS, Karen Hsu, 2004/10/19, ADD */
int CardBusyCheck = 0;

int SysBlockFAT = 1; //don't use compile option for easy customization

RTFMutex *MTFMLock = NULL;

RTFMutex *MTXLock = NULL;

#ifdef __FS_MOVE_SUPPORT__
   RTFMutex *MTMoveLock = NULL;
#endif

RTFMutex *MTXdelLock = NULL;

#ifdef __FS_SORT_SUPPORT__
   RTFMutex *MTSortLock = NULL;
#endif

static kal_bool  NorPartition = KAL_FALSE;
static kal_bool  NandPartition = KAL_FALSE;

#ifdef __FS_TRACE_SUPPORT__
   RTFMutex             *MTTraceLock = NULL;
   DWORD                g_TraceFlag = 0;
   static char          TraceStrBuf[MAX_TRACE_STR_LEN];
   char                 TraceTmpBuf[MT_TRACE_TMP_LEN];
   extern kal_bool      gFS_TraceTask[][2];
#endif

#ifdef __FS_QM_SUPPORT__
   WCHAR NvramName[6];
#endif

kal_bool COPYRIGHT_USB_ON = KAL_FALSE; //speedup, don't wrap with compile option flag
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* For Virtual File Feature */
const static WCHAR dchar_HexDigits[]= /* 0123456789ABCDEF */
   {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46};

const static WCHAR dchar_virtual_filename_prefix[]= /* \\.\FMapF\ */
   {0x5C, 0x5C, 0x2E, 0x5C, 0x46, 0x4D, 0x61, 0x70, 0x46, 0x5C, 0x0};

#ifdef __FS_SHADOW_NAND_32M__
   #define NUM_OF_FAT_CLUSTER_NAND 65536    //worst case needs 256KB
#elif defined __FS_SHADOW_NAND_64M__
   #define NUM_OF_FAT_CLUSTER_NAND 131072   //worst case needs 512KB
#elif defined __FS_SHADOW_NAND_128M__
   #define NUM_OF_FAT_CLUSTER_NAND 131072   //worst case needs 512KB
#elif defined __FS_SHADOW_NAND_256M__
   #define NUM_OF_FAT_CLUSTER_NAND 262144   //worst case needs 1MB
#elif defined __FS_SHADOW_NAND_512M__
   #define NUM_OF_FAT_CLUSTER_NAND 262144   //worst case needs 1MB
#elif defined __FS_SHADOW_NAND_1G__
   #define NUM_OF_FAT_CLUSTER_NAND 524288   //worst case needs 2MB
#endif

#ifdef __FS_SHADOW_CARD_32M__
   #define NUM_OF_FAT_CLUSTER_CARD 65536    //worst case needs 256KB
#elif defined __FS_SHADOW_CARD_64M__
   #define NUM_OF_FAT_CLUSTER_CARD 131072   //worst case needs 512KB
#elif defined __FS_SHADOW_CARD_128M__
   #define NUM_OF_FAT_CLUSTER_CARD 131072   //worst case needs 512KB
#elif defined __FS_SHADOW_CARD_256M__
   #define NUM_OF_FAT_CLUSTER_CARD 262144   //worst case needs 1MB
#elif defined __FS_SHADOW_CARD_512M__
   #define NUM_OF_FAT_CLUSTER_CARD 262144   //worst case needs 1MB
#elif defined __FS_SHADOW_CARD_1G__
   #define NUM_OF_FAT_CLUSTER_CARD 524288   //worst case needs 2MB
#endif

#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
#pragma arm section zidata = "SHADOW_FAT"

#ifdef __FS_SHADOW_NAND__
#ifndef NUM_OF_FAT_CLUSTER_NAND
#error "Size of NAND, __FS_SHADOW_NAND_xxx__, is not defined!"
#endif
   UINT Shadow_FAT_Array_NAND[NUM_OF_FAT_CLUSTER_NAND];
#endif

#ifdef __FS_SHADOW_CARD__
#ifndef NUM_OF_FAT_CLUSTER_CARD
#error "Size of CARD, __FS_SHADOW_CARD_xxx__, is not defined!"
#endif
   UINT Shadow_FAT_Array_CARD[NUM_OF_FAT_CLUSTER_CARD];
#endif

#pragma arm section zidata
#endif

#ifdef __FS_CARD_SUPPORT__
   #ifndef _NAND_FLASH_BOOTING_
      #define __FS_EMERGENT_NOR_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NOR_Buffer;
      BYTE g_Emergent_NOR_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
   #ifdef NAND_SUPPORT
      #define __FS_EMERGENT_NAND_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NAND_Buffer;
      BYTE g_Emergent_NAND_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
      /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
      #define __FS_EMERGENT_CARD_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_Card_Buffer;
      BYTE g_Emergent_Card_BufferData[RTF_MIN_BUFFER_SIZE];
      /* PATCH , WCP_SW, 2006/08/03, ADD END */
#else
   #if (defined NAND_SUPPORT) && !(defined _NAND_FLASH_BOOTING_)
      #define __FS_EMERGENT_NOR_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NOR_Buffer;
      BYTE g_Emergent_NOR_BufferData[RTF_MIN_BUFFER_SIZE];
      #define __FS_EMERGENT_NAND_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NAND_Buffer;
      BYTE g_Emergent_NAND_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
#endif

/* Sub Mark = Sub Watermark, store on FAT32 InfoSector.
 * Design to get faster respone in Free Cluster Search wrost case, especially on Large Disk
 */
#define SUBMARK_ID_SHIFT   (16)
#define SUBMARK_MASKOUT    (0xFFFF0000)
#define SUBMARK_MASK       (0x0000FFFF)
#define SUBMARK_LASTNUM    (119)

/* Directory Associated Cache Value, store run-time cache
 * Design to get faster respone for browsing application, especially on Large Directory case
 */
typedef struct MTDirAssociatedCache {
   RTFDrive * Drive;
   RTFCluster Cluster;
   UINT       Value;
} DirAssocatedCacheStruct;

#define DIRCACHE_NUM       (8)
#define DIRCACHE_MASK      (0x00000007)

#ifndef _LOW_COST_SINGLE_BANK_FLASH_
DirAssocatedCacheStruct    g_DirCacheArray[DIRCACHE_NUM];
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */

//---------------------- MT Global Static Func --------------------------

#ifdef __FS_QM_SUPPORT__
   static void  GetQuotaEntry(int * Index, RTFile * f);
   static int   QMPermitAllocate(UINT DriveFree, int Index, UINT NeedCluster);
#endif

#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
static void InitShadowFAT(RTFDrive *Drive);
static void FlushShadowFAT(void);
#endif

static void INTERN SetupFMapF_FileHandle(RTFile *f);
static int INTERN MTChkMapedFH(RTFHANDLE File);
static RTFCluster INTERN FATSearchZeroInBuffer(RTFDrive *Drive, RTFCluster Cluster);
static void INTERN FATHoistSubMark(RTFDrive *Drive, RTFCluster Begin, RTFCluster End);
static void INTERN FATLowerSubMark(RTFDrive *Drive, RTFCluster Begin, RTFCluster End);
static void INTERN FATInitInfoSectorSubMark(RTFDrive *Drive);
static RTFCluster INTERN FATHintSearchBySubMark(RTFDrive * Drive, RTFCluster Cluster, int MarkFlag);

//---------------------- MT Global Extern Func --------------------------
#ifdef __FS_TRACE_SUPPORT__
   #include <stdio.h>
   extern void tst_sys_trace(kal_uint8 *);
#endif
extern kal_bool INT_QueryExceptionStatus(void);
extern int FS_GetDevStatus(UINT QueryTarget, UINT QueryType);

/***********************************************************************/
/* MTK Enhancement, Karen Hsu, ADD END */

static RTFCriticalErrorHandler CriticalError = RTFDefaultCriticalErrorHandler;
static UINT       Unique = 0;

//static fs_block_type_enum fs_block_type = FS_BLOCK_ENUM; /* Fix multi-access bug, Karen Hsu, 2004/07/08, REM */
static int        TLSBlockIndex = -1;

extern void WDT_Restart2(void); /* Add for avoiding compile warning, Karen Hsu, 2004/01/14 */

BYTE          RTFAPI _rtfLock(BYTE * Lock); // Temp = *Lock;  *Lock = 1; return Temp;
static void   INTERN LockDevice   (RTFDevice * Dev, UINT Flags);
static void   INTERN DiscardOtherBuffer(RTFBuffer * B);
static void * INTERN SearchBuffer (RTFDevice * Dev, RTFSector Sector);
static void * INTERN GetBuffer    (RTFDevice * Dev, RTFSector Sector, UINT Flags);
static void   INTERN ScanDevices(void);
static void   INTERN UnmountDevice(RTFDevice * Dev, int CloseFiles);
static char   INTERN ScanPartitionTable(char volatile DriveLetter, RTFDevice * Dev, int PartitionKind);
static int    INTERN GenerateShortName(const char * LongName, char * ShortName);
static void   INTERN IncShortName(char * ShortName);

#define RTFRoundUp(N, Multiple)  (((N)+(Multiple)-1) & ~((Multiple)-1))
#define RTFRoundDown(N, Multiple) ((N) & ~((Multiple)-1))

#define CLUSTER_TO_SECTOR(Drive, Cluster)     ((Drive)->FirstDataSector + (((Cluster)-2L) << (Drive)->SPerCShift))
#define CLUSTER_TO_SECTOR_DIR(Drive, Cluster) (((Cluster) == RTF_ROOT_DIR) ? (Drive)->FirstDirSector : CLUSTER_TO_SECTOR(Drive, Cluster))
#define CLUSTER_TO_SECTOR_OFS(Drive, Cluster, Ofs)     ((Drive)->FirstDataSector + (((Cluster)-2L) << (Drive)->SPerCShift) + ((Ofs) >> (Drive)->Dev->DevData.SectorShift))
#define CLUSTER_TO_SECTOR_DIR_OFS(Drive, Cluster, Ofs) ((((Cluster) == RTF_ROOT_DIR) ? (Drive)->FirstDirSector : CLUSTER_TO_SECTOR(Drive, Cluster)) + ((Ofs) >> (Drive)->Dev->DevData.SectorShift))
#define SECTOR_OFS(Drive, Ofs)                ((Ofs) & ((Drive)->Dev->DevData.SectorSize-1))
#define SAME_DIR_ENTRY(D1, D2)                (((D1).Cluster == (D2).Cluster) && ((D1).Index == (D2).Index))
#define DIRS_PER_SECTOR(Drive)                (Drive->Dev->DevData.SectorSize/sizeof(RTFDOSDirEntry))

// Buffer flags
#define B_VALID   0x01   // buffer has valid data
#define B_DIRTY   0x02   // buffer has valid data and must be written to disk
#define B_INUSE   0x04   // buffer is being accessed by RTFiles
#define B_BUSY    0x08   // buffer is being accessed by a device driver
#define B_SINGLE  0x10   // single buffer for emergent use only /* Guarantee fixed disk access, Karen Hsu, 2005/05/19 */

/*----------------------------------*/
static int INTERN PowerTwo(unsigned int i)
{
   if (i == 0)
      return 0; // it's a power of two, put we need > 0
   while (i != 0)
   {
      if ((i & 1) && (i != 1))
         return 0;
      i >>= 1;
   }
   return 1;
}

/*-----------------------------------*/
static void INTERN ToHexString(char * Name, DWORD TimeStamp)
// write 8 hex digits, no zero termination
{
   UINT i;
   char HexDigits[] = "0123456789ABCDEF";

   for (i=0; i<8; i++)
   {
      Name[7-i] = HexDigits[TimeStamp & 0xF];
      TimeStamp >>= 4;
   }
}

/*-----------------------------------*/
static int INTERN IsValidShortNameChar(char c)
// ".", "\\", and ":" is invalid
{
   if ( strchr(ShortNameChars, c) )
      return 1;
   else
      return 0;
}

/*-----------------------------------*/
/* Check the validity of filename with ascii code only */
int RTFAPI IsValidLongNameChar(WCHAR c)
//static int INTERN IsValidLongNameChar(WCHAR c)
// "\\" and ":" is invalid
{
   char LongNameChars[]  = ".+,;=[]";

   if ( c<0x80 )
      return ( strchr(ShortNameChars, (char)c) || strchr(LongNameChars, (char)c) );

   return 1;
}

/*-----------------------------------*/
/* check only the last filename component */
static void INTERN CheckValidFileName2(const WCHAR * FileName, kal_bool bCheckLeading)
{
   const WCHAR *p = kal_wstrrchr(FileName, 0x005c);

   if (p == NULL)
      p = FileName;
   else
      p++;

   if (bCheckLeading && ((*p == 0x2E) || (*p == 0x20)))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
      XRAISE(RTF_INVALID_FILENAME);
   }

   for ( ;*p != 0x0; p++)
   {  if (!IsValidLongNameChar(*p) || *p == 0xFFFF /* UCS2 convert failure mark, WCP_SW, 2005/11/17*/)
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
         XRAISE(RTF_INVALID_FILENAME);
      }
   }

   /* Fix Dot-end issue, Karen Hsu, 2004/04/29, ADD START */
   p--;
   if (*p == 0x2E)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
      XRAISE(RTF_INVALID_FILENAME);
   }
   /* Fix Dot-end issue, Karen Hsu, 2004/04/29, ADD END */
}

static void INTERN CheckValidFileName(const WCHAR * FileName)
{
   CheckValidFileName2(FileName, KAL_TRUE);
}

/*-----------------------------------*/
/* COMPare Unicode and Ascii STRING */
int compUAstring(const char * FileName, const char* str, int len)
{
   int i;

   for (i=0; i<len; i++)
   {
      if (!compASCII(FileName, i, str[i]))
         return 0;
   }
   return 1;
}

/*-----------------------------------*/
WCHAR UnicodetoNative(WCHAR unicode)
{
        if ( unicode<0x80 )
           return unicode;
        else
/* Support SFN in active encoding, Karen Hsu, 2004/05/28, MOD START */
   {
      WCHAR encode;
      encode = UCS2_TO_WCHAR(unicode);
      ASSERT(encode != 0x0000);
      return encode;
   }
/* Support SFN in active encoding, Karen Hsu, 2004/05/28, MOD END */
}

/*-----------------------------------*/
WCHAR NativetoUnicode(WCHAR native)
{
   return native;
}

/*-----------------------------------*/
static char INTERN _rtftoupper(signed char c)
{
   if ( (c >= 'a') && (c <= 'z') )
      return c - ('a' - 'A');
   return c;
}

/*-----------------------------------*/
WCHAR RTFAPI wchartoupper(WCHAR c)
{
   // check if ascii code
   if ( (c>=0x61) && (c<=0x7a) )
      return c - (0x61 - 0x41);
   return c;
}

/*-----------------------------------*/
static RTFErrorAction INTERN HandleCriticalError(RTFDevice * Dev, int ErrorCode);
static int INTERN GetDiskGeometry(RTFDevice * Dev, RTFPartitionRecord * DiskGeometry, BYTE * MediaDescriptor);

/*-----------------------------------*/
static void INTERN CheckMedia(RTFDevice * Dev)
{
   if ((Dev->DevData.MediaRemovedReported == 0) ||
       (Dev->DevData.MediaPresent == 0))
   {
      Dev->DevData.MediaRemovedReported = 1;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR");
         else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND");
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_MEDIA_CHANGED, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_MEDIA_CHANGED);
   }
}

/*-----------------------------------*/
static int INTERN MountDevice(RTFDevice * Dev, DWORD Flags)
{
   int volatile Result;
   int Status;
   RTFSYSFreeMutex((RTFMutex *)RTFLock);
   XTRY
      case XCODE:
         Dev->DevData.MediaRemovedReported = 1;
         CheckMedia(Dev);
         Dev->DevData.ErrorCondition = RTF_NO_ERROR;
         Dev->DevData.MediaDescriptor = 0;
         memset((void *)&Dev->DevData.Geometry, 0, sizeof(Dev->DevData.Geometry));
         Dev->DevData.MountState = Initialized;

         Result = Dev->Driver->MountDevice(Dev->DriverData, Dev->DeviceNumber, Dev->DeviceType, Dev->DeviceFlags);
         if (Result < RTF_NO_ERROR)
         {
            Dev->DevData.ErrorCondition = Result;
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR");
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND");
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card");
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(Result);
         }
         Dev->DevData.ErrorCondition = RTF_NO_ERROR;

         if (Result > RTF_MIN_BUFFER_SIZE)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR");
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND");
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card");
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_SECTOR_SIZE, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_SECTOR_SIZE);
         }
         if (!PowerTwo(Result))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR");
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND");
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card");
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_SECTOR_SIZE, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_SECTOR_SIZE);
         }

         Dev->DevData.SectorSize = Result;
         Dev->DevData.SectorShift = 0;
         while ((1 << Dev->DevData.SectorShift) < Dev->DevData.SectorSize)
            Dev->DevData.SectorShift++;

         break;
      default:
         if (Flags & NO_RAISE)
         {
            Result = XVALUE;
            XHANDLED;
         }
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   if (Result >= RTF_NO_ERROR)
   {
      /* Modify for write protect issue, Karen Hsu, 2004/04/07, MOD START */
      if((Status = GetDiskGeometry(Dev, &Dev->DevData.Geometry, &Dev->DevData.MediaDescriptor)) == RTF_WRITE_PROTECTION)
         Dev->DeviceFlags |= MT_DEVICE_WRITE_PROTECT;
      else
         Dev->DeviceFlags &= ~MT_DEVICE_WRITE_PROTECT;
      //GetDiskGeometry(Dev, &Dev->DevData.Geometry, &Dev->DevData.MediaDescriptor);
      /* Modify for write protect issue, Karen Hsu, 2004/04/07, MOD END */

      Dev->DevData.MountState = Mounted;
   }
   /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD START */
   else
   {
      if((Status = GetDiskGeometry(Dev, &Dev->DevData.Geometry, &Dev->DevData.MediaDescriptor)) != 0)
      {
         if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            NorPartition = KAL_TRUE;
         else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            NandPartition = KAL_TRUE;
      }
   }

   if (Status == MT_MSDC_NOT_PRESENT)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "Dev:Card");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Status, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      Dev->DevData.MountState = NotMounted;
      Result = Status;
   }
   /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD END */
   return Result;
}

/*-----------------------------------*/
static int INTERN ShutDown(RTFDevice * Dev)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         Result = Dev->Driver->ShutDown(Dev->DriverData);
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN ReadSectors(RTFDevice * Dev, void * Data, RTFSector Sector, UINT Sectors, DWORD Flags)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.ErrorCondition < RTF_NO_ERROR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Dev->DevData.ErrorCondition, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(Dev->DevData.ErrorCondition);
         }
         if (Dev->DevData.MountState < Mounted)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_READY, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_DRIVE_NOT_READY);
         }
         Result = Dev->Driver->ReadSectors(Dev->DriverData, Sector, Sectors, Data);
         if (Result < RTF_NO_ERROR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(Result);
         }
         break;
      default:
         if (((Flags & NO_CRITICAL) == 0) &&
             (HandleCriticalError(Dev, XVALUE) == RTFRetry))
         {
            XHANDLED;
            XREEXECUTE;
         }
         if (Flags & NO_RAISE)
         {
            Result = XVALUE;
            Dev->DevData.ErrorCondition = RTF_NO_ERROR;
            XHANDLED;
         }
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN WriteSectors(RTFDevice * Dev, void * Data, RTFSector Sector, UINT Sectors, DWORD Flags, BYTE recoverable_flag)
{
   int volatile Result;
   int fs_block_type = FS_BLOCK_ENUM; /* Fix multi-access bug, Karen Hsu, 2004/07/08, ADD */

   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.ErrorCondition < RTF_NO_ERROR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Dev->DevData.ErrorCondition, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(Dev->DevData.ErrorCondition);
         }
         if (Dev->DevData.MountState < Mounted)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_READY, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_DRIVE_NOT_READY);
         }

#ifdef _LOW_COST_SINGLE_BANK_FLASH_
         if (!SysBlockFAT)
            fs_block_type = FS_NON_BLOCK_ENUM;
#else
         fs_block_type = (int)RTFSYSGetTLS(TLSBlockIndex); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD*/
#endif
         if (recoverable_flag == RTF_RECOVERABLE_WRITE)          // if (fs_block_type == FS_BLOCK_PROTECTION_ENUM)
         {
            if (Dev->Driver->RecoverableWriteSectors)
               Result = Dev->Driver->RecoverableWriteSectors(Dev->DriverData, Sector, Sectors, Data);
            else
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
                  else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_NO_PROTECTIONMODE, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(MT_NO_PROTECTIONMODE);
            }
         }
         else if (fs_block_type == FS_NON_BLOCK_ENUM)
         {
            if (Dev->Driver->NonBlockWriteSectors)
               Result = Dev->Driver->NonBlockWriteSectors(Dev->DriverData, Sector, Sectors, Data);
            else
            {
               /* if not support nonblock mode, use block mode,  2005/02/16 */
               Result = Dev->Driver->WriteSectors(Dev->DriverData, Sector, Sectors, Data);
            }
         }
         else
         {
            Result = Dev->Driver->WriteSectors(Dev->DriverData, Sector, Sectors, Data);
         }
         /* Add for NAND flash bad block issue, Karen Hsu, 2004/02/20, ADD START */
         if(Result == RTF_BAD_SECTOR)
         {
            UINT drvIdx;

#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_BAD_SECTOR, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            for (drvIdx = MT_BASE_DRIVE_INDEX; drvIdx < FS_MAX_DRIVES; drvIdx++)
            {
               if(gFS_Data.DriveTable[drvIdx].Dev != NULL)
               {
                  if(gFS_Data.DriveTable[drvIdx].Dev == Dev)
                  {
                     DWORD fatStart, dataStart;
                     fatStart = gFS_Data.DriveTable[drvIdx].FirstFATSector;
                     dataStart = gFS_Data.DriveTable[drvIdx].FirstDataSector;
                     if(Sector >= fatStart && Sector < dataStart)
                     {
#ifdef __FS_TRACE_SUPPORT__
                        if(g_TraceFlag & MT_TRACE_ERROR)
                        {
                           if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                              kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
                           else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                              kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
                           else
                              kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
                           memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                           MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_SYSTEM_CRASH, NULL, (BYTE *)TraceTmpBuf);
                        }
#endif
                        XRAISE(MT_SYSTEM_CRASH);
                     }
                  }
               }
               else break;
            }
         }
        /* Add for NAND flash bad block issue, Karen Hsu, 2004/02/20, ADD END */
         if (Result < RTF_NO_ERROR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d, Sectors: %d", Sector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d, Sectors: %d", Sector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d, Sectors: %d", Sector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
            if(SysBlockFAT == 0)
            {
               DiscardAllBuffers(Dev);
            }
#endif
            XRAISE(Result);
         }
         break;
      default:
         if (((Flags & NO_CRITICAL) == 0) &&
             (HandleCriticalError(Dev, XVALUE) == RTFRetry))
         {
            XHANDLED;
            XREEXECUTE;
         }
         if (Flags & NO_RAISE)
         {
            Result = XVALUE;
            Dev->DevData.ErrorCondition = RTF_NO_ERROR;
            XHANDLED;
         }
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN MediaChanged(RTFDevice * Dev)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.MountState < Initialized)
            Result = RTF_DRIVE_NOT_READY;
         else
            Result = Dev->Driver->MediaChanged(Dev->DriverData);
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN DiscardSectors(RTFDevice * Dev, RTFSector Sector, RTFSector Sectors)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.MountState < Initialized)
            Result = RTF_DRIVE_NOT_READY;
         else
            if (Dev->Driver->DiscardSectors)
               Result = Dev->Driver->DiscardSectors(Dev->DriverData, Sector, Sectors);
            else
               Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN GetDiskGeometry(RTFDevice * Dev, RTFPartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.MountState < Initialized)
            Result = RTF_DRIVE_NOT_READY;
         else
            if (Dev->Driver->GetDiskGeometry)
               Result = Dev->Driver->GetDiskGeometry(Dev->DriverData, DiskGeometry, MediaDescriptor);
            else
               Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN LowLevelFormat(RTFDevice * Dev, const char * DeviceName, RTFFormatCallback Progress, DWORD Flags)
// assume NO_RAISE NO_CRITICAL
{
   int volatile Result;
   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         /* Add for MSDC, Karen Hsu, 2004/02/11, ADD START */
         if (!Dev->Driver->LowLevelFormat)
         {
            Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
            break;
         }
         /* Add for MSDC, Karen Hsu, 2004/02/11, ADD END */
         if (Dev->DevData.MountState < Initialized)
            Result = RTF_DRIVE_NOT_READY;
         else
            if (Dev->Driver->LowLevelFormat)
               Result = Dev->Driver->LowLevelFormat(Dev->DriverData, DeviceName, Progress, Flags);
            else
               Result = RTF_UNSUPPORTED_DRIVER_FUNCTION;
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

/*-----------------------------------*/
static int INTERN CheckSerialNumber(RTFDrive * Drive, int ErrorCode)
// must not raise any exceptions
{
   RTFBootRecord * BR;
   int volatile Result;

   // lock file system as we now need a buffer
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
   XTRY
      case XCODE:
         // clear any media changed errors
         MediaChanged(Drive->Dev);

         // if the current temp buffer is the boot sector, then we can't do our thing
         if (Drive->Dev->DevData.B &&
             (Drive->Dev->DevData.B->Sector == Drive->FirstSector))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, ErrorCode, NULL, NULL);
#endif
            XRAISE(ErrorCode);
         }

         BR = GetBuffer(Drive->Dev, Drive->FirstSector, NO_LOAD | ALT_BUFFER); // not! filled
         ReadSectors(Drive->Dev, (void*)BR, Drive->FirstSector, 1, NO_CRITICAL);
         if (((Drive->FATType == RTFAT32) ? BR->BP.E._32.BPB.SerialNumber : BR->BP.E._16.BPB.SerialNumber) != Drive->SerialNumber)
            Result = RTF_WRONG_MEDIA;
         else
            Result = RTF_NO_ERROR;
         break;
      default:
         Result = XVALUE;
         XHANDLED;
         break;
      case XFINALLY:
         // manually discard the buffer
         if (Drive->Dev->DevData.AltBuffer)
         {
            DiscardOtherBuffer(Drive->Dev->DevData.AltBuffer);
            Drive->Dev->DevData.AltBuffer = NULL;
         }
         RTFSYSFreeMutex(RTFLock);
         break;
   XENDX
   return Result;
}

/*-----------------------------------*/
static RTFErrorAction INTERN HandleCriticalError(RTFDevice * Dev, int ErrorCode)
// device is locked, but RTFiles is not locked when called
{
   #define LostMedia(Code) ((Code == RTF_MEDIA_CHANGED) || (Code == RTF_WRONG_MEDIA) || (Code == RTF_DRIVE_NOT_FOUND) || (Code == RTF_DRIVE_NOT_READY))
   RTFDrive * Drive = (Dev->DevData.FirstDrive && (Dev->DevData.FirstDrive->MountState >= HasFileSystem)) ? Dev->DevData.FirstDrive : NULL;

   if (LostMedia(ErrorCode) && Drive)
   {
      ErrorCode = CheckSerialNumber(Drive, ErrorCode);
      if (ErrorCode == RTF_NO_ERROR)
         return RTFRetry;
   }

   while (1)
   {
      RTFErrorAction Result = CriticalError(Drive ? (MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable)) : Dev->DevData.FriendlyName[5], Drive ? Drive->SerialNumber : 0, ErrorCode);

      switch (Result)
      {
         case RTFFail:
            if (LostMedia(ErrorCode))
               Dev->DevData.ErrorCondition = ErrorCode; // this will unmount the device and discard all buffers
            return RTFFail;
         case RTFRetry:
            if (LostMedia(ErrorCode) && Drive)
            {
               ErrorCode = CheckSerialNumber(Drive, ErrorCode);
               if (ErrorCode == RTF_NO_ERROR)
                  return RTFRetry;
               else
                  break; // keep on looping
            }
            else
               return RTFRetry;
         default:
            RTFSYSErrorExit("Invalid return value from critical error handler", 1);
      }
   }
}

/*-----------------------------------*/
#ifdef __FS_DEBUG__
static RTFBufferStatistic BufferStat = { 0 };
#endif

static RTFBuffer * FirstBuffer = NULL;

/*-----------------------------------*/
static void INTERN UpFront(RTFBuffer * B)
{
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      return;
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

   if (B != FirstBuffer)
   {
      // unlink it
      B->Prev->Next = B->Next;
      B->Next->Prev = B->Prev;

      // link into front
      B->Next = FirstBuffer;
      B->Prev = FirstBuffer->Prev;

      B->Next->Prev = B;
      B->Prev->Next = B;

      FirstBuffer = B;
   }
}

/*-----------------------------------*/
static void INTERN ToTail(RTFBuffer * B)
{
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      return;
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

   if (B == FirstBuffer)
      FirstBuffer = FirstBuffer->Next;
   else
   {
      // unlink it
      B->Prev->Next = B->Next;
      B->Next->Prev = B->Prev;

      B->Next = FirstBuffer;
      B->Prev = FirstBuffer->Prev;

      B->Next->Prev = B;
      B->Prev->Next = B;
   }
}

/*-----------------------------------*/
static void INTERN FreeBuffer(RTFDevice * Dev)
// this is called only by UnlockDevice and GetBuffer
{
   if (Dev->DevData.B)
   {
      Dev->DevData.B->Flags &= ~B_INUSE;
      Dev->DevData.B = NULL;
   }
}

/*-----------------------------------*/
static void INTERN DiscardOtherBuffer(RTFBuffer * B)
{
#ifdef __FS_DEBUG__
   if (B->Flags & B_DIRTY)
      BufferStat.DirtyBuffers--;
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      B->Flags = B_SINGLE;
   else
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */
   B->Flags = 0;
   B->recoverable_flag = RTF_NORMAL_WRITE;
   ToTail(B);
}

/*-----------------------------------*/
static void INTERN DiscardBuffer(RTFDevice * Dev)
// this frees a buffer
{
#ifdef DEBUG
   if (Dev->DevData.B == NULL)
      RTFSYSErrorExit("Can't discard non-current buffer", 1);
#endif
   DiscardOtherBuffer(Dev->DevData.B);
   Dev->DevData.B = NULL;
}

/*-----------------------------------*/
static void INTERN AllocBuffers(void)
{
   RTFBuffer * B;
   UINT i;

   if (FirstBuffer)
      return;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   g_Emergent_NOR_Buffer.Flags |= B_SINGLE;
   g_Emergent_NOR_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_NOR_Buffer.Data = g_Emergent_NOR_BufferData;
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   g_Emergent_NAND_Buffer.Flags |= B_SINGLE;
   g_Emergent_NAND_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_NAND_Buffer.Data = g_Emergent_NAND_BufferData;
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__  /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   g_Emergent_Card_Buffer.Flags |= B_SINGLE;
   g_Emergent_Card_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_Card_Buffer.Data = g_Emergent_Card_BufferData;
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

   //if (gFS_Data.Version != RTFILE_VER)
      //RTFSYSErrorExit("gFS_Data version mismatch", 1);

#ifdef __FS_DEBUG__
   BufferStat.TotalBuffers = FS_MAX_BUFFERS;
#endif

   if ((RTF_MIN_BUFFER_SIZE > RTF_MAX_BUFFER_SIZE) ||
       !PowerTwo(RTF_MIN_BUFFER_SIZE))
      RTFSYSErrorExit("Invalid RTF_BUFFER_SIZE", 1);

   if (FS_MAX_FILES > FMAX)
      RTFSYSErrorExit("Too many file handles", 1);

   if (((DWORD) gFS_Data.BufferTable) % 4)
      RTFSYSErrorExit("Cache buffer not properly aligned", 1);

   for (i=0; i<FS_MAX_BUFFERS; i++)
   {
      B = gFS_Data.BufferTable + i;
      B->Num = i;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      B->Data = gFS_Data.BufferData + (i*RTF_MIN_BUFFER_SIZE);
      B->Next = B + 1;
      B->Prev = B - 1;
   }

   FirstBuffer = gFS_Data.BufferTable;

   FirstBuffer->Prev = FirstBuffer + FS_MAX_BUFFERS - 1;
   FirstBuffer->Prev->Next = FirstBuffer;
}

#ifdef __FS_DEBUG__

/*-----------------------------------*/
void RTFAPI RTFBufferInfo(RTFBufferStatistic * BufferInfo)
{
   RTFBuffer * B;

#ifdef DEBUG
   UINT Test = 0;
#endif

   if (FirstBuffer == 0)
      AllocBuffers();

   *BufferInfo = BufferStat;

   BufferInfo->CacheHits = BufferInfo->PhysicalBufferReads ? 100 * (BufferInfo->CachedBufferReads) / (BufferInfo->PhysicalBufferReads + BufferInfo->CachedBufferReads) : 0;

   BufferInfo->ValidBuffers = 0;

   B = FirstBuffer;
   do
   {
      if (B->Flags & B_VALID)
         BufferInfo->ValidBuffers++;
#ifdef DEBUG
      if (B->Flags & B_DIRTY)
         Test++;
#endif
      B = B->Next;
   } while (B != FirstBuffer);
#ifdef DEBUG
   if (Test != BufferStat.DirtyBuffers)
      RTFSYSErrorExit("DirtyBuffers incorrect", 0);
#endif
}

#endif

/*-----------------------------------*/
static void INTERN ReadBuffer(RTFBuffer * B)
{
   int fs_block_type = FS_BLOCK_ENUM; /* Fix multi-access bug, Karen Hsu, 2004/07/08, ADD */

   XTRY
      case XCODE:
         B->Flags |= B_BUSY;
         ReadSectors(B->Dev, B->Data, B->Sector, 1, 0);

         // set the recoverable_flag according to the TLS setting
         fs_block_type = (int)RTFSYSGetTLS(TLSBlockIndex);
         if (fs_block_type == FS_BLOCK_PROTECTION_ENUM)
           B->recoverable_flag = RTF_RECOVERABLE_WRITE;
         else
           B->recoverable_flag = RTF_NORMAL_WRITE;

#ifdef __FS_DEBUG__
         BufferStat.PhysicalBufferReads++;
#endif
         B->Flags |= B_VALID;
         break;
      default:
         ToTail(B);
         B->Flags &= ~B_INUSE;
         break;
      case XFINALLY:
         B->Flags &= ~B_BUSY;
         break;
   XENDX
}

/*-----------------------------------*/
static void INTERN WriteBuffer(RTFBuffer * B)
{
#ifdef DEBUG
   if (B->Flags != (B_INUSE | B_VALID | B_DIRTY))
      RTFSYSErrorExit("Attempt to write none inuse/valid/dirty buffer", 0);
#endif
   XTRY
      case XCODE:
         B->Flags |= B_BUSY;

         // recoverable_flag indicates if it has to use recoverablewritesector or not
         if (B->recoverable_flag == RTF_RECOVERABLE_WRITE)
           WriteSectors(B->Dev, B->Data, B->Sector, 1, 0, RTF_RECOVERABLE_WRITE);
         else
           WriteSectors(B->Dev, B->Data, B->Sector, 1, 0, RTF_NORMAL_WRITE);
          // clear the recoverable_flag
         B->recoverable_flag = RTF_NORMAL_WRITE;

         B->Flags &= ~B_DIRTY;
#ifdef __FS_DEBUG__
         BufferStat.PhysicalBufferWrites++;
         BufferStat.AsynchBufferFlushs += (B->FirstDirtyTime != B->Dev->DevData.AccessCount);
         BufferStat.DirtyBuffers--;
#endif
         // check if this is a FAT sector and we have to
         // take care of other FATs
         // We will ignore any errors here, but we do want
         // critical errors.

         {
            int i, FATs;

            if ((B->FATSectorInfo) && ((B->Dev->DeviceFlags & RTF_DEVICE_SINGLE_FAT) == 0))
               FATs = B->FATSectorInfo->FATCount;
            else
               FATs = 1;

            if (FATs > 1)
            {
               B->Flags = B_VALID | B_INUSE | B_BUSY;
               for (i=1; i<FATs; i++)
               {
                  WriteSectors(B->Dev, B->Data, B->Sector + i * B->FATSectorInfo->SectorsPerFAT, 1, NO_RAISE, RTF_NORMAL_WRITE);
#ifdef __FS_DEBUG__
                  BufferStat.PhysicalBufferWrites++;
                  BufferStat.AsynchBufferFlushs += B->FirstDirtyTime != B->Dev->DevData.AccessCount;
#endif
               }
               B->Flags = B_VALID | B_INUSE;
            }
         }
         break;
      default: // only the first FAT can raise exceptions
         B->Flags &= ~B_INUSE;
         break;
      case XFINALLY:
         B->Flags &= ~B_BUSY;
         break;
   XENDX
}

/*-----------------------------------*/
static void * INTERN SearchBuffer(RTFDevice * Dev, RTFSector Sector)
{
   RTFBuffer * B;    // selected buffer

   #ifdef DEBUG
   if (!RTFSYSOwnMutex(RTFLock))
      RTFSYSErrorExit("Attempt access buffers without locking", 1);
   #endif

   if (Dev->DevData.B && (Dev->DevData.B->Sector == Sector))
      return Dev->DevData.B->Data;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   B = &g_Emergent_NOR_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   B = &g_Emergent_NAND_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   B = &g_Emergent_Card_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

   // search forward for the sector in question

   B = FirstBuffer;
   do
   {
      if (B->Flags & B_VALID)
      {
         if ((B->Sector == Sector) && (B->Dev == Dev))
         {
            #ifdef DEBUG
            if (B->Flags & (B_INUSE | B_BUSY))  // double allocation
               RTFSYSErrorExit("Buffer allocated twice", 0);
            #endif
            UpFront(B);
            B->Flags |= B_INUSE;
            FreeBuffer(Dev);
            Dev->DevData.B = B;
            return B->Data;
         }
      }
      else
         return NULL;
      B = B->Next;
   } while (B != FirstBuffer);
   return NULL;
}

/*-----------------------------------*/
static void * INTERN GetBuffer(RTFDevice * Dev, RTFSector Sector, UINT Flags)
{
   RTFBuffer * B;    // selected buffer

   #ifdef DEBUG
   if (!RTFSYSOwnMutex(RTFLock))
      RTFSYSErrorExit("Attempt access buffers without locking", 1);
   if (Dev->DevData.AltBuffer)
      RTFSYSErrorExit("AltBuffer not freed", 1);
   #endif

   if ((Flags & ALT_BUFFER) == 0)
   {
      if (Dev->DevData.B)
      {
         if (Dev->DevData.B->Sector == Sector)
            return Dev->DevData.B->Data;
         else
            FreeBuffer(Dev);
      }
   }
   // search forward for the sector in question or an invalid (free) buffer

   B = FirstBuffer;
   do
   {
      if (B->Flags != 0)
      {
         if ((B->Sector == Sector) && (B->Dev == Dev))
         {
            #ifdef DEBUG
            if (B->Flags & (B_INUSE | B_BUSY))  // double allocation
               RTFSYSErrorExit("Buffer allocated twice", 0);
            if ((B->Flags & B_VALID) == 0)
               RTFSYSErrorExit("allocating invalid buffer", 0);
            #endif
#ifdef __FS_DEBUG__
            BufferStat.CachedBufferReads++;
#endif
            B->Flags |= B_INUSE;
            goto SaveAndExit;
         }
      }
      else // not allocated buffers follow the first unallocated buffer
      {
         #ifdef DEBUG
         {
            RTFBuffer * B1 = B;
            do
            {
               if (B1->Flags != 0)
                  RTFSYSErrorExit("Buffer with flags after last valid buffer", 0);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif
         goto ReadAndExit;
      }
      B = B->Next;
   } while (B != FirstBuffer);

#ifdef __FS_DEBUG__
   BufferStat.BuffersDiscarded++; // we have to discard one
#endif
   // now search backwards (oldest first) for a buffer to discard:
   // for any buffer on the same device
   // or for a clean buffer

   B = FirstBuffer->Prev;
   do
   {
      if (((B->Flags & B_INUSE) == 0) &&                     // it's not in use and
          ((B->Dev == Dev) ||                                //  it's on this device or
           ((B->Flags & B_DIRTY) == 0)))                     //  it's not dirty
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            RTFSYSErrorExit("can't discard a busy buffer", 0);
         #endif
         if (B->Flags & B_DIRTY)
         {
            #ifdef DEBUG
            if (B->Dev != Dev)
               RTFSYSErrorExit("can'd discard foreighn dirty buffer", 0);
            #endif
            B->Flags        |= B_INUSE;
            WriteBuffer(B);
         }
         goto ReadAndExit;
      }
      B = B->Prev;
   } while (B != FirstBuffer->Prev);

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
   {
      B = &g_Emergent_NOR_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
   {
      B = &g_Emergent_NAND_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   if(Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
   {
      B = &g_Emergent_Card_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & MT_TRACE_ERROR)
   {
      if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
         kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d", Sector);
      else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
         kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d", Sector);
      else
         kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d", Sector);
      memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
      MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_OUT_OF_BUFFERS, NULL, (BYTE *)TraceTmpBuf);
   }
#endif
   XRAISE(RTF_OUT_OF_BUFFERS);

ReadAndExit:
   B->Dev           = Dev;
   B->Sector        = Sector;
   B->FATSectorInfo = NULL;
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
   {
      B->Flags = (B_SINGLE | B_INUSE);
   }
   else
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */
   B->Flags         = B_INUSE;
   B->recoverable_flag = RTF_NORMAL_WRITE;

   if (Flags & NO_LOAD)
      B->Flags |= B_VALID;
   else
      ReadBuffer(B);

SaveAndExit:
   UpFront(B);
   if (Flags & ALT_BUFFER)
      Dev->DevData.AltBuffer = B;
   else
      Dev->DevData.B = B;
   return B->Data;
}

/*-----------------------------------*/
#ifdef __FS_DEBUG__
static void INTERN FlushOldest(RTFDevice * Dev)
{
   // search backwards (oldest first) for a buffer to commit

   RTFBuffer * B = FirstBuffer->Prev;

   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            RTFSYSErrorExit("flushing a busy buffer", 0);
         #endif
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         return;
      }
      B = B->Prev;
   } while (B != FirstBuffer->Prev);

   #ifdef DEBUG
   // Some debugging. This is actually not a fatal error.
   // The file system can keep on going if no buffer to commit is found.
   // The only danger now is a critical error on an other device, which
   // could throw an out-of-buffer exception
   RTFSYSErrorExit("no oldest buffer to commit found", 0);
   #endif
}
#endif

/*-----------------------------------*/
static void INTERN SetDirty(RTFDevice * Dev)
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       RTFSYSErrorExit("no buffer to set dirty", 0);
   if ((B->Flags & B_INUSE) == 0)
       RTFSYSErrorExit("set non inuse buffer dirty", 0);
   if ((B->Flags & B_VALID) == 0)
       RTFSYSErrorExit("set invalid buffer dirty", 0);
   #endif
   if (B->Flags & B_DIRTY)
#ifdef __FS_DEBUG__
      BufferStat.CachedBufferWrites += (B->LastDirtyTime != B->Dev->DevData.AccessCount);
#else
   ;
#endif
   else
   {
      B->Flags |= B_DIRTY;
#ifdef __FS_DEBUG__
      if (++BufferStat.DirtyBuffers > BufferStat.MaxDirtyBuffers)
         BufferStat.MaxDirtyBuffers = BufferStat.DirtyBuffers;
#endif
      B->FirstDirtyTime = B->Dev->DevData.AccessCount;
   }
   B->LastDirtyTime = B->Dev->DevData.AccessCount;

   // prevent from human errors
   B->recoverable_flag = RTF_NORMAL_WRITE;

#ifdef __FS_DEBUG__
   if (BufferStat.DirtyBuffers > (FS_MAX_BUFFERS-2))
      FlushOldest(Dev);
#endif

#ifdef _LOW_COST_SINGLE_BANK_FLASH_
   if (SysBlockFAT == 0)
   {
      WriteBuffer(B);
   }
#else
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      WriteBuffer(B);
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */
#endif

}

/*-----------------------------------*/
static void INTERN SetRecoverableFlag(RTFDevice * Dev, BYTE block_type)
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       RTFSYSErrorExit("no buffer to set recoverable flag", 0);
   #endif

   if (block_type == FS_BLOCK_PROTECTION_ENUM)
      B->recoverable_flag = RTF_RECOVERABLE_WRITE;
   else
      B->recoverable_flag = RTF_NORMAL_WRITE;
}

/*-----------------------------------*/
void RTFAPI CommitBuffer(RTFDevice * Dev)
// write a buffer if it is dirty
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       RTFSYSErrorExit("no buffer to commit", 0);
   if ((B->Flags & B_INUSE) == 0)
       RTFSYSErrorExit("committing non inuse buffer", 0);
   if ((B->Flags & B_VALID) == 0)
       RTFSYSErrorExit("committing invalid buffer", 0);
   #endif
   if (B->Flags & B_DIRTY)
      WriteBuffer(B);
}

/*-----------------------------------*/
void RTFAPI DiscardAllBuffers(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_VALID) == 0)
      {
         #ifdef DEBUG
         {
            RTFBuffer * B1 = B;
            do
            {
               if (B1->Flags != 0)
                  RTFSYSErrorExit("Buffer with flags after last valid buffer", 0);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif
         return;
      }
      else
         if (B->Dev == Dev)
         {
            if (Dev->DevData.B == B)
               DiscardBuffer(Dev);
            else
               DiscardOtherBuffer(B);
            goto Again;
         }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*-----------------------------------*/
static void INTERN DiscardBuffersRange(RTFDevice * Dev, RTFSector Sector, RTFSector Count, int Commit)
{
   RTFBuffer * B;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
//don't put these two cases behind
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   B = &g_Emergent_NOR_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   B = &g_Emergent_NAND_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_Card_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   B = &g_Emergent_Card_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_VALID) == 0)
      {
         #ifdef DEBUG
         {
            RTFBuffer * B1 = B;
            do
            {
               if (B1->Flags != 0)
                  RTFSYSErrorExit("Buffer with flags after last valid buffer", 0);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif
         return;
      }
      else
         if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
         {
            if ((B->Flags & B_DIRTY) && Commit)
            {
               #ifdef DEBUG
               if (B->Flags & B_BUSY)
                  RTFSYSErrorExit("flushing a busy buffer", 0);
               #endif
               if (B->Flags & B_INUSE)
                  WriteBuffer(B);
               else
               {
                  B->Flags |= B_INUSE;
                  WriteBuffer(B);
                  B->Flags &= ~B_INUSE;
               }
            }
            if (Dev->DevData.B == B)
               DiscardBuffer(Dev);
            else
               DiscardOtherBuffer(B);
            goto Again;
         }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*-----------------------------------*/
void RTFAPI FlushAllBuffers(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            RTFSYSErrorExit("flushing a busy buffer", 0);
         #endif
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         goto Again;
      }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*-----------------------------------*/
static void INTERN FlushFAT(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_DIRTY) && B->FATSectorInfo && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            RTFSYSErrorExit("flushing busy buffer", 0);
         if (B->FATSectorInfo->Dev != Dev)
            RTFSYSErrorExit("incorrect device for FAT sector", 0);
         #endif
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         goto Again;
      }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*-----------------------------------*/
void RTFAPI FlushAllBuffersInGeometryOrder(RTFDevice * Dev)
{
   RTFBuffer * B;
   RTFBuffer * W;

Again:
   B = FirstBuffer;
   W = NULL;
   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            RTFSYSErrorExit("flushing a busy buffer", 0);
         #endif
         if (W == NULL || W->Sector > B->Sector)
         {
            W = B;
         }
      }
      B = B->Next;
   } while (B != FirstBuffer);

   if (W != NULL)
   {
      if (W->Flags & B_INUSE)
      {
         WriteBuffer(W);
      }
      else
      {
         W->Flags |= B_INUSE;
         WriteBuffer(W);
         W->Flags &= ~B_INUSE;
      }
      goto Again;
   }
}

/*-----------------------------------*/
static int INTERN FindDevice(RTFDevice * * D, int DeviceIndex, MountStates State)
{
   RTFDevice * Dev;
   int i;

   if (RTFLock == NULL)
      RTFInit();

   for (i=0; i<=DeviceIndex; i++)
      if (gFS_DeviceList[i].DeviceType == 0)
         return RTF_DRIVE_NOT_FOUND;

   *D = Dev = gFS_DeviceList + DeviceIndex;

   LockDevice(Dev, 0);
   if (Dev->DevData.MountState < State)
   {
      i = MountDevice(Dev, NO_RAISE | NO_CRITICAL);
      if ((i < RTF_NO_ERROR) || (Dev->DevData.MountState < State))
      {
         UnlockDevice(Dev);
         return (i < RTF_NO_ERROR) ? i : RTF_INVALID_FILE_SYSTEM;
      }
      else
         return i;
   }
   else
      return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFRawLowLevelFormat(int DeviceIndex, const WCHAR * DeviceName, RTFFormatCallback Progress, DWORD Flags)
{
   RTFDevice * Dev = NULL; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int Result = FindDevice(&Dev, DeviceIndex, Initialized);

   if (Result >= RTF_NO_ERROR)
   {
      Result = LowLevelFormat(Dev, (char *)DeviceName, Progress, Flags);
      UnlockDevice(Dev);
   }
   return Result;
}

#ifdef DEBUG
/*-----------------------------------*/
static void INTERN EntryExitCheck(RTFDevice * Dev, _XData * XD)
{
   int i;

   if (FirstBuffer == NULL) // buffers not initialized yet
      return;
   if ((XD == NULL) || (XD->Next == NULL)) // are we leaving the the file system?
   {
      RTFBuffer * B;

      if (Dev->DevData.B)
         RTFSYSErrorExit("Internal: Temp buffer not free", 1);

      // check that the buffer chain is not corrupted

      B = FirstBuffer;
      for (i=0; i<FS_MAX_BUFFERS-1; i++)
         B = B->Next;
      if (B == FirstBuffer)
         RTFSYSErrorExit("Internal: Buffer chain corrupted 1", 1);
      B = B->Next;
      if (B != FirstBuffer)
         RTFSYSErrorExit("Internal: Buffer chain corrupted 2", 1);

      // now check backward links
      B = FirstBuffer->Prev;
      for (i=0; i<FS_MAX_BUFFERS-1; i++)
         B = B->Prev;
      if (B == FirstBuffer->Prev)
         RTFSYSErrorExit("Internal: Buffer chain corrupted 3", 1);
      B = B->Prev;
      if (B != FirstBuffer->Prev)
         RTFSYSErrorExit("Internal: Buffer chain corrupted 4", 1);

      // check that not buffers of this drive are in use or busy
      B = gFS_Data.BufferTable;
      for (i=0; i<FS_MAX_BUFFERS; i++)
      {
         if ((B->Dev == Dev) && (B->Flags & (B_INUSE | B_BUSY)))
            RTFSYSErrorExit("Internal: Buffer in use", 1);
         B++;
      }

      // check that RTFiles and the drive are locked
      if (!RTFSYSOwnMutex(RTFLock) || !RTFSYSOwnMutex(Dev->DevData.Lock))
         RTFSYSErrorExit("Internal: Dev not locked", 1);

   }
   else  // we are not leaving, so make sure the next exception handler is in scope
      if ((void*) XD <= (void*) &XD)
          RTFSYSErrorExit("Internal: XEND not called", 1);
}

/*-----------------------------------*/
static void INTERN CheckReleased(_XData * XD)
{
   RTFDevice * Dev;

   if ((XD == NULL) || (XD->Next == NULL)) // are we leaving the file system?
   {
      for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         if (RTFSYSOwnMutex(Dev->DevData.Lock))
            RTFSYSErrorExit("Internal: Dev mutex locked", 1);
      if (RTFSYSOwnMutex(RTFLock))
         RTFSYSErrorExit("Internal: RTFiles mutex locked", 1);
   }
}
#endif

/*-----------------------------------*/
static RTFMutex * INTERN FindDeviceLock(RTFDevice * Dev, RTFDriver * Driver, const char * Name)
{
   for (; Dev >= gFS_DeviceList; Dev--)
      if (Dev->Driver == Driver)
         return Dev->DevData.Lock;
   return RTFSYSAllocMutex(Name);
}

/*-----------------------------------*/
static void INTERN InitDevices(void)
{
   RTFDevice * Dev;

   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      //if ((Dev->Driver->Version < 200) || (Dev->Driver->Version > RTFILE_VER))
         //RTFSYSErrorExit("Dev driver version mismatch", 1);
      if (Dev->DeviceType == RTF_DEVICE_FLOPPY)
         Dev->DeviceFlags |= RTF_DEVICE_REMOVABLE;

      Dev->DevData.MediaPresent = (Dev->DeviceFlags & RTF_DEVICE_NO_MEDIA) == 0;
      Dev->DevData.MediaRemovedReported = 1;
      Dev->DevData.PhysicalDiskIndex = -1;

      strcpy(Dev->DevData.FriendlyName, "Disk X");
      Dev->DevData.FriendlyName[5] = (Dev - gFS_DeviceList) + '0';
      if (Dev->DevData.Lock == NULL)
      {
         if (Dev->DeviceFlags & RTF_DEVICE_NEW_LOCK)
            Dev->DevData.Lock = RTFSYSAllocMutex(Dev->DevData.FriendlyName);
         else
            Dev->DevData.Lock = FindDeviceLock(Dev-1, Dev->Driver, Dev->DevData.FriendlyName);
      }
   }
}

/*-----------------------------------*/
void RTFAPI RTFInit(void)
{
//   ASSERT((FS_MAX_DRIVES >= 1) && (FS_MAX_DRIVES <= 5));
   ASSERT(FS_MAX_DRIVES >= 1);
   ASSERT(FS_MAX_BUFFERS >= 1);
   ASSERT(FS_MAX_FILES >= 3);
   ASSERT(FS_MAX_THREAD >= 2);

   RTFLock = RTFSYSAllocMutex("RTFiles");
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   if(TLSBlockIndex == -1)
      TLSBlockIndex = RTFSYSAllocTLS();

   AllocBuffers();
   InitDevices();
   ScanDevices();
   RTFSYSFreeMutex(RTFLock);
   RTFSYSFreeMutex(RTFLock);
}

/*-----------------------------------*/
static void INTERN LockDevice(RTFDevice * Dev, UINT Flags)
{
#ifdef DEBUG
   if (Dev == NULL)
       RTFSYSErrorExit("can't lock null device", 1);
   CheckReleased(XHANDLER);
#endif

/* Add for USB mode, Karen Hsu, 2004/10/19, ADD START */
   if(INT_QueryExceptionStatus() == KAL_FALSE) //allow to write exception record
      ASSERT(SysLockFAT == 0);
/* Add for USB mode, Karen Hsu, 2004/10/19, ADD END */


   if (CardBusyCheck && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) && !(Flags & FS_NOBUSY_CHECK_MODE))
   {
      int Result = FS_GetDevStatus(FS_DEVICE_TYPE_CARD, FS_FEATURE_STATE_ENUM);
      if (Result == MT_DEVICE_BUSY)
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
               kal_sprintf(TraceTmpBuf, "Dev:NOR");
            else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
               kal_sprintf(TraceTmpBuf, "Dev:NAND");
            else
               kal_sprintf(TraceTmpBuf, "Dev:Card");
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(Result);
      }
   }

   RTFSYSLockMutex(Dev->DevData.Lock, RTF_INFINITE);
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
   Dev->DevData.AccessCount++;
#ifdef DEBUG
   EntryExitCheck(Dev, XHANDLER);
#endif
}

/*-----------------------------------*/
static void INTERN NonBlockLockDevice(RTFDevice * Dev, UINT Flags)
{
   int status;

   if (CardBusyCheck && (Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) && !(Flags & FS_NOBUSY_CHECK_MODE))
   {
      int Result = FS_GetDevStatus(FS_DEVICE_TYPE_CARD, FS_FEATURE_STATE_ENUM);
      if (Result == MT_DEVICE_BUSY)
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
               kal_sprintf(TraceTmpBuf, "Dev:NOR");
            else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
               kal_sprintf(TraceTmpBuf, "Dev:NAND");
            else
               kal_sprintf(TraceTmpBuf, "Dev:Card");
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(Result);
      }
   }

   status = RTFSYSLockMutex(Dev->DevData.Lock, RTF_NO_WAIT);
   if(status != RTF_NO_ERROR)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR");
         else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND");
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, status, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(status);
   }
   status = RTFSYSLockMutex(RTFLock, RTF_NO_WAIT);
   if(status != RTF_NO_ERROR)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR");
         else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND");
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, status, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      RTFSYSFreeMutex(Dev->DevData.Lock); /* Fix always occupy device lock bug, Karen Hsu, 2005/01/30, ADD */
      XRAISE(status);
   }
   Dev->DevData.AccessCount++;
}
/*-----------------------------------*/
void RTFAPI UnlockDevice(RTFDevice * Dev)
{
   if (Dev->DevData.B)
      FreeBuffer(Dev);
   if (Dev->DevData.ErrorCondition < RTF_NO_ERROR)
      UnmountDevice(Dev, 1);

#ifdef DEBUG
   EntryExitCheck(Dev, XHANDLER);
#endif
   RTFSYSFreeMutex(RTFLock);
   RTFSYSFreeMutex(Dev->DevData.Lock);
#ifdef DEBUG
   CheckReleased(XHANDLER);
#endif
}

/*-----------------------------------*/
static RTFile * INTERN ReserveFTSlot(void)
// not protected by any mutex!
{
   int i;
   RTFile * f = gFS_Data.FileTable;

   if (RTFLock == NULL)
      RTFInit();

   for (i=0; i<FS_MAX_FILES; i++, f++)
      if (_rtfLock(&f->Lock) == 0)
         return f;
#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & MT_TRACE_ERROR)
      MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_TOO_MANY_FILES, NULL, NULL);
#endif
//   EXT_ASSERT(0, FS_MAX_FILES, 0, 0); /* Add for fatal resource exception, Karen Hsu, 2004/08/31 */
//   XRAISE(RTF_TOO_MANY_FILES);
   RTFSYSErrorExit("RTF_TOO_MANY_FILES", RTF_TOO_MANY_FILES);
   return NULL;
}

/*-----------------------------------*/
void RTFAPI FreeFTSlot(RTFile * f)
{
   memset(f, 0, sizeof(RTFile));
}

/*-----------------------------------*/
RTFHANDLE RTFAPI MakeNewFileHandle(RTFile * f)
{
   Unique = (Unique + 1) & UMAX;
   if (Unique == 0)
      Unique++;
   f->Unique = Unique;
   /* Add for hot plug I/O, Karen Hsu, 2004/02/04, ADD START */
   f->Valid = MT_ENUM_FH_VALID;
   /* Add for hot plug I/O, Karen Hsu, 2004/02/04, ADD END */
   f->Task = kal_get_current_thread_ID(); /* ADD for garbage collection, Karen Hsu, 2004/04/16 */
   return (RTFHANDLE) ((f->Unique << (4*sizeof(int))) | (f - gFS_Data.FileTable));
}

/*-----------------------------------*/
RTFile * RTFAPI ParseFileHandle(RTFHANDLE File)
{
   UINT U = File >> (4*sizeof(int));
   UINT i = File & ((1 << (4*sizeof(int))) - 1);
   RTFile * f;
   RTFDevice * Dev;

   if (i >= FS_MAX_FILES)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }
   f = gFS_Data.FileTable + i;
   if (f->Lock == 0)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }
   if (f->Unique != U)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }
   Dev = f->Dev;
   if (Dev == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
   /* blocking is possible during LockDevice */
   LockDevice(Dev, f->Flags);

   // we have to wait at the lock. If someone closed the file
   // in the mean time, bail out
   if ((f->Lock == 0) || (f->Unique != U) || (Dev != f->Dev))
   {
      UnlockDevice(Dev);
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }

   /* Add for usb normal mode access, , 2005/12/01, ADD START */
   /* align and simplify USB & Removable file handle processing, 2006/10/20, MOD START */
   if (f->Valid == MT_ENUM_FH_EXPORTED)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_DEVICE_EXPORTED_ERROR, f, (BYTE *)TraceTmpBuf);
      }
#endif
      FreeFTSlot(f);
      UnlockDevice(Dev);
      XRAISE(MT_DEVICE_EXPORTED_ERROR);
   }
   /* align and simplify USB & Removable file handle processing, 2006/10/20, MOD END */
   /* Add for usb normal mode access, , 2005/12/01, ADD END */

   /* Add for hot plug in/out issue, Karen Hsu, 2004/02/11, ADD START */
   /* align and simplify USB & Removable file handle processing, 2006/10/20, MOD START */
   if(f->Valid == MT_ENUM_FH_MEDIACHANGED)
   {
      FreeFTSlot(f);
      UnlockDevice(Dev);
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_MEDIA_CHANGED, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_MEDIA_CHANGED);
   }
   /* align and simplify USB & Removable file handle processing, 2006/10/20, MOD END */
   /* Add for hot plug in/out issue, Karen Hsu, 2004/02/11, ADD END */
   return f;
}

/*-----------------------------------*/
/* Note that this routine is only called by RTFRead and RTFWrite.
    That is, when a file is opened in non-blocking mode, only read/write
    will be affected. Other APIs, like RTFSeek, RTFTruncate, etc., will still be blocking.
*/
static RTFile * INTERN ParseFileHandle_NB(RTFHANDLE File)
{
   UINT U = File >> (4*sizeof(int));
   UINT i = File & ((1 << (4*sizeof(int))) - 1);
   RTFile * f;
   RTFDevice * Dev;

   if (i >= FS_MAX_FILES)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, NULL, (BYTE *)TraceTmpBuf);
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }
   f = gFS_Data.FileTable + i;
   if (f->Lock == 0)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }
   if (f->Unique != U)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }
   Dev = f->Dev;
   if (Dev == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }
   if(f->Flags & FS_NONBLOCK_MODE)
      NonBlockLockDevice(Dev, f->Flags);
   else
      LockDevice(Dev, f->Flags);

   // we have to wait at the lock. If someone closed the file
   // in the mean time, bail out
   if ((f->Lock == 0) || (f->Unique != U) || (Dev != f->Dev))
   {
      UnlockDevice(Dev);
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, NULL);
      }
#endif
      XRAISE(RTF_INVALID_FILE_HANDLE);
   }

   /* Add for usb normal mode access, , 2005/12/01, ADD START */
   /* align and simplify USB & Removable file handle processing, 2006/10/20, MOD START */
   if (f->Valid == MT_ENUM_FH_EXPORTED)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_DEVICE_EXPORTED_ERROR, f, (BYTE *)TraceTmpBuf);
      }
#endif
      FreeFTSlot(f);
      UnlockDevice(Dev);
      XRAISE(MT_DEVICE_EXPORTED_ERROR);
   }
   /* align and simplify USB & Removable file handle processing, 2006/10/20, MOD END */
   /* Add for usb normal mode access, , 2005/12/01, ADD END */
   return f;
}

/*-----------------------------------*/
// Count the number of file handle by Device
// note that f->Valid don't care
static int INTERN FileCount(RTFDevice * Dev)
{
   UINT Count = 0;
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)
      if (f->Drive && (f->Dev == Dev))
         Count++;
   return Count;
}

/*-----------------------------------*/
// Count the number of file handle by Drive
// note it was usd by RTFClose() for Volumn file thus f->Valid do care
static int INTERN FileCountDrive(RTFDrive * Drive)
{
   UINT Count = 0;
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)
   {  
      if (f->Drive == Drive && f->Valid == MT_ENUM_FH_VALID )
      {
         Count++;
      }
   }
   return Count;
}

/*-----------------------------------*/
void RTFAPI CheckSharing(RTFile * File)
//static void INTERN CheckSharing(RTFile * File)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   // check if the same data file is open and either file has write access
   // without sharing
   for (i=0; i<FS_MAX_FILES; i++, f++)
      if ((f != File) &&
          (f->Dev == File->Dev) &&
          ((f->Flags & File->Flags & RTF_READ_ONLY) == 0) &&   // not both read only AND
          ((f->Flags & File->Flags & RTF_OPEN_SHARED) == 0) && // not both opend shared AND
          ((((f->Drive == File->Drive) && /* Fix mis-check on two partition, Karen Hsu, 2005/04/15 */
             (SAME_DIR_ENTRY(f->DirEntry.ShortPos,
              File->DirEntry.ShortPos))) ||         // both are the same file OR
           ((f->SpecialKind == PhysicalDisk) ||                // one of them is a device file OR
            (File->SpecialKind == PhysicalDisk)) ||
           ((f->Drive == File->Drive) &&                       // one volume and both go to the same drive
            ((f->SpecialKind == Volume) ||
             (File->SpecialKind == Volume))))))
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, File, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(RTF_ACCESS_DENIED);
      }
}

/*-----------------------------------*/
void RTFAPI CheckNotOpen2(RTFile * File, RTFile * File2)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)
      if ((f != File) && (f != File2) &&
          (f->Drive == File->Drive) &&
          (f->SpecialKind == File->SpecialKind) &&
          SAME_DIR_ENTRY(f->DirEntry.ShortPos, File->DirEntry.ShortPos))
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, File, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(RTF_ACCESS_DENIED);
      }
}

void RTFAPI CheckNotOpen(RTFile * File)
{
   CheckNotOpen2(File, NULL);
}

/*-----------------------------------*/
static RTFDrive * INTERN AllocateDrive(char DriveLetter, RTFDevice * Dev)
// reserves a drive and links it into the drive list of a device
// no device access
{
   RTFDrive * Drive;

   if ((DriveLetter < 'C') && (Dev->DeviceType == RTF_DEVICE_FDISK))
      DriveLetter = 'C';

   while (1)
   {
      if ((DriveLetter - MT_BASE_DRIVE_LETTER) >= FS_MAX_DRIVES)
         return NULL;
      Drive = gFS_Data.DriveTable + DriveLetter - MT_BASE_DRIVE_LETTER;
      if (Drive->Dev == Dev)
         break;
      if (Drive->Dev == NULL)
      {
         Drive->Dev = Dev;
         Drive->NextDrive = Dev->DevData.FirstDrive;
         Dev->DevData.FirstDrive = Drive;
         break;
      }
      DriveLetter++;
   }
   Drive->MountState = NotMounted;
   return Drive;
}

/*-----------------------------------*/
static char INTERN InitLogicalDrive(char DriveLetter,
                                    RTFDevice * Dev,
                                    RTFPartitionRecord * Geometry,
                                    RTFSector PartitionSector)
// sets up a drive with informationm from a partition entry
// no device access, but the caller must have read a partition
// table or guess at the format of a floppy
{
   RTFDrive * Drive;

   Drive = AllocateDrive(DriveLetter, Dev);
   if (Drive == NULL) // can't mount, too many drives
      return DriveLetter;

   Drive->MountState = Mounted;
   Drive->Geometry = *Geometry;
   Drive->FirstSector = PartitionSector + Geometry->RelativeSector;
   return MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable) + 1; // return next drive letter
}

/*-----------------------------------*/
static char INTERN ReserveLogicalDrive(char DriveLetter, RTFDevice * Dev)
// this is called for removable devices at startup
// it does not access the device and creates exactly one
// logical drive
{
   RTFDrive * Drive = AllocateDrive(DriveLetter, Dev);

   if (Drive == NULL)        // can't mount, too many drives
      return DriveLetter;
   else
      return MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable) + 1; // return next drive letter
}

/*-----------------------------------*/
static void INTERN MountPartitions(RTFDevice * Dev)
// mount all partitions
{
   switch (Dev->DeviceType)
   {
      case RTF_DEVICE_FDISK:
         ScanPartitionTable('C', Dev, RTF_PARTITION_ALL);
         break;
      case RTF_DEVICE_FLOPPY:
         Dev->DevData.Geometry.OSType = 1;
         InitLogicalDrive(MT_BASE_DRIVE_LETTER + (Dev->DevData.FirstDrive - gFS_Data.DriveTable), Dev, &Dev->DevData.Geometry, 0);
         break;
      #ifdef DEBUG
      default:
         RTFSYSErrorExit("Invalid device type in device list", 1);
      #endif
   }
}

/*-----------------------------------*/
void RTFAPI MakePseudoRootDirEntry(RTFDrive * Drive, RTFDirEntry * DirEntry)
{
   RTFCluster DirCluster = (Drive->FATType == RTFAT32) ? Drive->FirstDirSector : RTF_ROOT_DIR;

   memset(DirEntry, 0, sizeof(*DirEntry));
   DirEntry->Dir.FileName[0] = '\\';
   memset((char *)DirEntry->Dir.FileName+1, ' ', 7+3);
   DirEntry->Dir.Attributes = RTF_ATTR_DIR;
   SET_FIRST_FILE_CLUSTER(DirEntry->Dir, DirCluster);
}

/*-----------------------------------*/
void RTFAPI MountLogicalDrive(RTFDrive * Drive, MountStates State)
// prepares drive or device for a file open operation
// all required mounting is done, if required
// devices are identified by State == Initialized
{
   WCHAR driver_X[]={0x58, 0x3a, 0x5c, 0};  /*X:\\*/

   if (Drive->Dev == NULL)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_FOUND, NULL, NULL);
#endif
      XRAISE(RTF_DRIVE_NOT_FOUND);
   }

   XTRY
      case XCODE:
         if (Drive->Dev->DevData.MountState < Mounted)
         {
            /* Modify for hot plug in/out issue, Karen Hsu, 2004/02/11, MOD START */
            int Result;
            //Karen ADD START
            if((Drive->Dev->DevData.MountState == NotMounted) &&
               (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
            {
               Drive->MountState = NotMounted;
            }
            //Karen ADD END
            Result = MountDevice(Drive->Dev, 0);
            //int Result = MountDevice(Drive->Dev, 0);
            /* Modify for hot plug in/out issue, Karen Hsu, 2004/02/11, MOD END */
            if (Drive->Dev->DevData.MountState < Mounted)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR");
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND");
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card");
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(Result);
            }
         }

         // don't get here if the device is not mounted

         if (Drive->MountState < Mounted)
         {
            MountPartitions(Drive->Dev);
            if (Drive->MountState < Mounted)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR");
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND");
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card");
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_FOUND, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_DRIVE_NOT_FOUND);
            }
         }

         {
            RTFBootRecord * BR = GetBuffer(Drive->Dev, Drive->FirstSector, 0);
            RTFSector RootDirSectors, DataSectors;

            Drive->MountState = Accessible;

            if ((BR->Signature != 0xAA55) ||
               ((Drive->Dev->DeviceFlags & MT_DEVICE_CHECK_PART) && 
               (BR->NearJump[0] != 0xE9) && (BR->NearJump[0] != 0xEB)))
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR, Signature: 0x%x, NearJump: 0x%x", BR->Signature, BR->NearJump[0]);
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND, Signature: 0x%x, NearJump: 0x%x", BR->Signature, BR->NearJump[0]);
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card, Signature: 0x%x, NearJump: 0x%x", BR->Signature, BR->NearJump[0]);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            if (BR->BP.BytesPerSector != Drive->Dev->DevData.SectorSize)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR, BR Size: %d", BR->BP.BytesPerSector);
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND, BR Size: %d", BR->BP.BytesPerSector);
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card, BR Size: %d", BR->BP.BytesPerSector);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_SECTOR_SIZE, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_SECTOR_SIZE);
            }

            if (PowerTwo(BR->BP.SectorsPerCluster))
               Drive->SectorsPerCluster = BR->BP.SectorsPerCluster;
            else
               if ((BR->BP.SectorsPerCluster & 0x80) &&
                   ((BR->BP.SectorsPerCluster & 0x7F) >= 8) &&
                   ((BR->BP.SectorsPerCluster & 0x7F) <= 15))
                  Drive->SectorsPerCluster = 1 << (BR->BP.SectorsPerCluster & 0x7F);
               else
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                  {
                     if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                        kal_sprintf(TraceTmpBuf, "Dev:NOR, SPC Size: %d", BR->BP.SectorsPerCluster);
                     else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                        kal_sprintf(TraceTmpBuf, "Dev:NAND, SPC Size: %d", BR->BP.SectorsPerCluster);
                     else
                        kal_sprintf(TraceTmpBuf, "Dev:Card, SPC Size: %d", BR->BP.SectorsPerCluster);
                     memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
                  }
#endif
                  XRAISE(RTF_INVALID_FILE_SYSTEM);
               }

            Drive->ClusterShift = 1;
            while ((1l << Drive->ClusterShift) < (1l * Drive->Dev->DevData.SectorSize * Drive->SectorsPerCluster))
               Drive->ClusterShift++;

            Drive->SPerCShift = 0;
            while ((1 << Drive->SPerCShift) < Drive->SectorsPerCluster)
               Drive->SPerCShift++;

            if (BR->BP.SectorsOnDisk != 0)
               BR->BP.TotalSectors = BR->BP.SectorsOnDisk;

            Drive->FirstFATSector = Drive->FirstSector + BR->BP.ReservedSectors;
            Drive->FATCount = BR->BP.NumberOfFATs;
            RootDirSectors = (BR->BP.DirEntries * 32 + (BR->BP.BytesPerSector - 1)) / BR->BP.BytesPerSector;
            DataSectors = BR->BP.TotalSectors
                        - BR->BP.ReservedSectors
                        - (Drive->FATCount * (BR->BP.SectorsPerFAT ? BR->BP.SectorsPerFAT : BR->BP.E._32.SectorsPerFAT))
                        - RootDirSectors;

            Drive->Clusters = DataSectors >> Drive->SPerCShift;

            if (Drive->Clusters <= 0xFF4L)
               Drive->FATType = RTFAT12;
            else if (Drive->Clusters <= 0xFFF4l)
               Drive->FATType = RTFAT16;
            else if (Drive->Clusters <= 0xFFFFFF4l)
               Drive->FATType = RTFAT32;
            else
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR, Clusters: %d", Drive->Clusters);
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND, Clusters: %d", Drive->Clusters);
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card, Clusters: %d", Drive->Clusters);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            Drive->Clusters += 2;  // make that logical clusters

            if (Drive->FATType == RTFAT32)
            {
               if (BR->BP.E._32.Version != 0)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                  {
                     if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                        kal_sprintf(TraceTmpBuf, "Dev:NOR, Version: %d", BR->BP.E._32.Version);
                     else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                        kal_sprintf(TraceTmpBuf, "Dev:NAND, Version: %d", BR->BP.E._32.Version);
                     else
                        kal_sprintf(TraceTmpBuf, "Dev:Card, Version: %d", BR->BP.E._32.Version);
                     memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
                  }
#endif
                  XRAISE(RTF_INVALID_FILE_SYSTEM);
               }
               Drive->SectorsPerFAT = BR->BP.E._32.SectorsPerFAT;
               Drive->FirstDataSector = Drive->FirstFATSector + Drive->FATCount * Drive->SectorsPerFAT;
               Drive->FirstDirSector = BR->BP.E._32.RootDirCluster; // not a sector
               Drive->RootDirEntries = 0;
               Drive->SerialNumber = BR->BP.E._32.BPB.SerialNumber;
               Drive->InfoSector = (BR->BP.E._32.FSInfoSector != 0xFFFF) ? (Drive->FirstSector + BR->BP.E._32.FSInfoSector) : 0;
               // if FAT mirroring is disabled, pretend we only have one FAT
               if (BR->BP.E._32.Flags & 0x80)
               {
                  Drive->FATCount = 1;
                  Drive->FirstFATSector = Drive->FirstSector
                                        + BR->BP.ReservedSectors
                                        + (BR->BP.E._32.Flags & 0x0F)
                                          * BR->BP.E._32.SectorsPerFAT;
               }
            }
            else
            {
               Drive->SectorsPerFAT = BR->BP.SectorsPerFAT;
               Drive->FirstDirSector = Drive->FirstFATSector + Drive->FATCount * Drive->SectorsPerFAT;
               Drive->FirstDataSector = Drive->FirstDirSector + RootDirSectors;
               Drive->RootDirEntries = BR->BP.DirEntries;
               Drive->SerialNumber = BR->BP.E._16.BPB.SerialNumber;
               Drive->InfoSector = 0;
            }
            Drive->ClusterSize = 1l << Drive->ClusterShift;

            kal_dchar_strcpy(Drive->CurrDir, (char *)driver_X);
            Drive->CurrDir[0] = MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable);
            MakePseudoRootDirEntry(Drive, &Drive->CurrDirEntry);

            // do some plausibility checks

            if (BR->BP.ReservedSectors == 0)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR, RSectors: %d", BR->BP.ReservedSectors);
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND, RSectors: %d", BR->BP.ReservedSectors);
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card, RSectors: %d", BR->BP.ReservedSectors);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            if ((Drive->FATCount < 1) || (Drive->FATCount > 2))
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR, FATCount: %d", Drive->FATCount);
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND, FATCount: %d", Drive->FATCount);
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card, FATCount: %d", Drive->FATCount);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            if (Drive->SectorsPerFAT == 0)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR");
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND");
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card");
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }

            if (Drive->SectorsPerCluster == 0)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR");
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND");
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card");
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_SYSTEM);
            }
         /* Check Sectors Range of Drive-onto-Device , WCP_SW , 2005/09/13, ADD START */
            /* Check If Logical Sectors Larger than Physical Sectors
             * -----------------------------------------------------
             *  This modification is a trade-off solution come from a special case.
             *  Which a cluster-overflow-formatted card will stop response once
             *  out-of-valid sector written.
             *  On spec, card must response error when try to write wrong sector.
             *  Another approach on driver is to check range every sector write.
             *  But it degrad the performance.
             *  Yet another proposal is reject mount for this case.
             *  But Windows can mount this card and make user confused.
             *  So the trade-off solution is try to limit drive cluster value at initialize.
             * */
            while ( (Drive->FirstDataSector + (Drive->Clusters - 2) * Drive->SectorsPerCluster)
                 /* Max Logical Sector */ > (Drive->Dev->DevData.Geometry.Sectors) /* Max Physical Sector */ )
            {
               Drive->Clusters--;
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR --- sector overflow");
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND --- sector overflow");
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card --- sector overflow");
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               if (Drive->Dev->DevData.Geometry.Sectors == 0)
               {
                  Drive->Dev->DevData.MountState = NotMounted;
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                  {
                     if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                        kal_sprintf(TraceTmpBuf, "Dev:NOR");
                     else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                        kal_sprintf(TraceTmpBuf, "Dev:NAND");
                     else
                        kal_sprintf(TraceTmpBuf, "Dev:Card");
                     memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_MEDIA_CHANGED, NULL, (BYTE *)TraceTmpBuf);
                  }
#endif
                  XRAISE(RTF_MEDIA_CHANGED);
               }
               if (((Drive->Clusters - 2) * Drive->SectorsPerCluster) <= Drive->FirstDataSector)
               {
                  break;
               }
            }
         /* Check Sectors Range of Drive-onto-Device , WCP_SW , 2005/09/13, ADD END */

         }

         Drive->MountState = HasFileSystem;
         /* Construct free cluster count for system drive right away, Karen Hsu, 2005/01/06, ADD START */
         if((kal_query_systemInit() == KAL_FALSE) &&
            (Drive->Dev->DeviceNumber == gFS_DeviceNumOfSYSDRV))
         {
            Drive->FreeClusterCount = 0;
            Drive->ClusterWatermark = RTF_INVALID_CLUSTER;
            BatchCountFreeClusters(Drive);
         }
         else
         {
            Drive->FreeClusterCount = RTF_INVALID_CLUSTER;
            Drive->ClusterWatermark = 2;
         }
         /* Construct free cluster count for system drive right away, Karen Hsu, 2005/01/06, ADD END */

#if 0 /* Fix FAT32 display wrong free size, Karen Hsu, 2005/06/06, REM */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


            /* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD START */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
         if ( stack_query_boot_mode() != USBMS_BOOT )
         {   
            InitShadowFAT( Drive );
         }
#endif
            /* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD END */
         break;
      default:
         if (((State <= Initialized) && (Drive->Dev->DevData.MountState >= State)) || (Drive->MountState >= State))
            XHANDLED;
         break;
      case XFINALLY:
         break;
   XENDX
}

/*-----------------------------------*/
static void INTERN UnmountDevice(RTFDevice * Dev, int CloseFiles)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;
   RTFDrive * D = Dev->DevData.FirstDrive;

   if (CloseFiles)
      for (i=0; i<FS_MAX_FILES; i++, f++)
         if (f->Dev == Dev)
            FreeFTSlot(f);

   while (D)
   {
      D->MountState = NotMounted;
      D = D->NextDrive;
   }
   DiscardAllBuffers(Dev);
   Dev->DevData.MountState = NotMounted;
}

/*-----------------------------------*/
static char INTERN ScanPartitionTable(char volatile DriveLetter,
                                      RTFDevice * Dev,
                                      int PartitionKind)
// raises no exceptions
{
   DWORD ExOffset = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int i;
   int ExPartition = -1;   // see if we have an extended partition
   int PrimPartitions = 0; // count primary partitions
   int DriveOffset = 0;
   RTFMasterBootRecord * MBR;

   MBR = GetBuffer(Dev, 0, 0);

   Dev->DevData.MountState = Accessible;

   if (MBR->Signature != 0xAA55)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR, Signature: 0x%x", MBR->Signature);
         else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND, Signature: 0x%x", MBR->Signature);
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card, Signature: 0x%x", MBR->Signature);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_CORRUPTED_PARTITION_TABLE, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_CORRUPTED_PARTITION_TABLE);
   }

   Dev->DevData.MountState = HasFileSystem;

   // process primary partions first
   for (i=0; i<4; i++)
   {
      switch (MBR->PTable[i].OSType)
      {
         // primary partions with FAT12/FA16
         case 0x01:
         case 0x04: // max 32MB, 1024 cylinder
         case 0x06: // max  2GB, 1024 cylinder
         case 0x0B: // FAT-32 CHS
         case 0x0C: // FAT-32 LBA
         case 0x0E: // max 2GB, more than 1024 cylinder
               PrimPartitions++;

               if ((PrimPartitions == 1) && (PartitionKind & RTF_PARTITION_FIRST_PRIMARY) &&
                  (Dev->DeviceFlags & MT_DEVICE_CHECK_PART) && (MBR->PTable[i].BootIndicator != 0x80))
               {
                  Dev->DevData.MountState = Accessible;
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                  {
                     if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                        kal_sprintf(TraceTmpBuf, "Dev:NOR, BootIndicator: 0x%x", MBR->PTable[i].BootIndicator);
                     else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                        kal_sprintf(TraceTmpBuf, "Dev:NAND, BootIndicator: 0x%x", MBR->PTable[i].BootIndicator);
                     else
                        kal_sprintf(TraceTmpBuf, "Dev:Card, BootIndicator: 0x%x", MBR->PTable[i].BootIndicator);
                     memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_CORRUPTED_PARTITION_TABLE, NULL, (BYTE *)TraceTmpBuf);
                  }
#endif
                  XRAISE(RTF_CORRUPTED_PARTITION_TABLE);
               }
               
               if (((PrimPartitions == 1) && (PartitionKind & RTF_PARTITION_FIRST_PRIMARY)) ||
                   ((PrimPartitions > 1) && (PartitionKind & RTF_PARTITION_OTHER_PRIMARY)))
                  DriveLetter = InitLogicalDrive(DriveLetter,
                                              Dev,
                                              MBR->PTable + i,
                                              0);
            break;
         case 0x05: // extended DOS partition max 2GB, max 1024 cylinder
         case 0x0F: // ditto, more than 1024 cylinder
            ExOffset = MBR->PTable[i].RelativeSector;
            ExPartition = i;
         default:   // ignore anything else
            break;
      }
   }

   if (PartitionKind & RTF_PARTITION_EXTENDED)
   {
      // Process extended partions.
      // Note that we support only one extended partition on a drive,
      // but this partition can contain any number of logical drives
      while (ExPartition != -1)
      {
         ExPartition = -1;

         MBR = GetBuffer(Dev, ExOffset + DriveOffset, 0);

         if (MBR->Signature != 0xAA55)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Signature: 0x%x", MBR->Signature);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Signature: 0x%x", MBR->Signature);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Signature: 0x%x", MBR->Signature);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_CORRUPTED_PARTITION_TABLE, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_CORRUPTED_PARTITION_TABLE);
         }

         for (i=0; i<4; i++)
         {
            switch (MBR->PTable[i].OSType)
            {
               // primary partions with FAT12/FAT16
               case 0x01:
               case 0x04: // max 32MB, 1024 cylinder
               case 0x06: // max 2GB, 1024 cylinder
               case 0x0B: // FAT-32 CHS
               case 0x0C: // FAT-32 LBA
               case 0x0E: // max 2GB, more than 1024 cylinder
                  DriveLetter = InitLogicalDrive(DriveLetter,
                                                 Dev,
                                                 MBR->PTable + i,
                                                 ExOffset + DriveOffset);
                  break;
               case 0x05: // extended DOS partition max 2GB, max 1024 cylinder
               case 0x0F: // ditto, more than 1024 cylinder
                  if (MBR->PTable[i].RelativeSector <= DriveOffset)
                  {
#ifdef __FS_TRACE_SUPPORT__
                     if(g_TraceFlag & MT_TRACE_ERROR)
                     {
                        if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                           kal_sprintf(TraceTmpBuf, "Dev:NOR, RelativeSector: %d", MBR->PTable[i].RelativeSector);
                        else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                           kal_sprintf(TraceTmpBuf, "Dev:NAND, RelativeSector: %d", MBR->PTable[i].RelativeSector);
                        else
                           kal_sprintf(TraceTmpBuf, "Dev:Card, RelativeSector: %d", MBR->PTable[i].RelativeSector);
                        memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                        MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_CORRUPTED_PARTITION_TABLE, NULL, (BYTE *)TraceTmpBuf);
                     }
#endif
                     XRAISE(RTF_CORRUPTED_PARTITION_TABLE);
                  }
                  DriveOffset = MBR->PTable[i].RelativeSector;
                  ExPartition = i;
               default:   // ignore anything else
                  break;
            }
         }
      }
   }
   return DriveLetter;
}

/*-----------------------------------*/
static char INTERN LockedScanPartitionTable(char volatile DriveLetter,
                                            RTFDevice * Dev,
                                            int PartitionKind)
{
   XTRY // just to keep CheckReleased happy
      case XCODE:
         XTRY
            case XCODE:
               LockDevice(Dev, 0);
               DriveLetter = ScanPartitionTable(DriveLetter, Dev, PartitionKind);
               break;
            default:
               XHANDLED;
               break;
            case XFINALLY:
               UnlockDevice(Dev);
               break;
         XENDX
         break;
      default:
         break;
      case XFINALLY:
         break;
   XENDX
   return DriveLetter;
}

/*-----------------------------------*/
static void INTERN ScanDevices(void)
{
   RTFDevice * Dev;
   char DriveLetter = MT_BASE_DRIVE_LETTER;
   int DiskIndex = 0;
   /* Dynamic assign device number, Karen Hsu, 2005/06/08, MOD START */
   int i = 1;

   // distribute disk indexes
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      Dev->DeviceNumber = i;
      i++;
      if (Dev->DeviceType == RTF_DEVICE_FDISK)
         Dev->DevData.PhysicalDiskIndex = DiskIndex++;
      else
         Dev->DevData.PhysicalDiskIndex = -1;
   }
   /* Dynamic assign device number, Karen Hsu, 2005/06/08, MOD END */

   // mount devices if they are not removeable
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if ((Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0)
         MountDevice(Dev, NO_RAISE);

   // mount first primary partitions
   // ignore RTF_MOUNT_CONTIGUOUS devices
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
   {
      if (Dev->DeviceFlags & RTF_DEVICE_MOUNT_CONTIGUOUS)
         continue;
      if (Dev->DeviceType == RTF_DEVICE_FLOPPY)
      {
         DriveLetter = ReserveLogicalDrive(DriveLetter, Dev);
      }
      else
      {
         if (Dev->DevData.MountState >= Mounted)
            DriveLetter = LockedScanPartitionTable(DriveLetter, Dev, RTF_PARTITION_FIRST_PRIMARY);
         /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD START */
         else if((Dev->DeviceFlags & RTF_DEVICE_REMOVABLE) == 0)
         {
            UINT idx;
            for(idx = MT_BASE_DRIVE_INDEX; idx < FS_MAX_DRIVES; idx++)
               if(gFS_Data.DriveTable[idx].Dev == NULL)
                  break;
            AllocateDrive(MT_BASE_DRIVE_LETTER + idx, Dev);
         }
         /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD END */
      }
   }

   // mount extended partitions
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if (((Dev->DeviceFlags & (RTF_DEVICE_REMOVABLE | RTF_DEVICE_MOUNT_CONTIGUOUS)) == 0) &&
          (Dev->DevData.MountState >= Mounted))
      {
         DriveLetter = LockedScanPartitionTable(DriveLetter, Dev, RTF_PARTITION_EXTENDED);
      }

   // mount other primary partitions
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if (((Dev->DeviceFlags & (RTF_DEVICE_REMOVABLE | RTF_DEVICE_MOUNT_CONTIGUOUS)) == 0) &&
          (Dev->DevData.MountState >= Mounted))
      {
         DriveLetter = LockedScanPartitionTable(DriveLetter, Dev, RTF_PARTITION_OTHER_PRIMARY);
      }
      /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD START */
      else if((Dev->DeviceType & RTF_DEVICE_REMOVABLE) == 0)
      {
         if(((Dev->DeviceFlags & MT_DEVICE_NOR_FLASH) && NorPartition) ||
            ((Dev->DeviceFlags & MT_DEVICE_NAND_FLASH) && NandPartition))
         {
            UINT idx;
            for(idx = MT_BASE_DRIVE_INDEX; idx < FS_MAX_DRIVES; idx++)
               if(gFS_Data.DriveTable[idx].Dev == NULL)
                  break;
            AllocateDrive(MT_BASE_DRIVE_LETTER + idx, Dev);
         }
      }
      /* Reserve drive name for mount error device, Karen Hsu, 2004/03/04, ADD END */


   // mount RTF_MOUNT_CONTIGUOUS devices
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if (((Dev->DeviceFlags & (RTF_DEVICE_REMOVABLE | RTF_DEVICE_MOUNT_CONTIGUOUS)) == RTF_DEVICE_MOUNT_CONTIGUOUS) &&
          (Dev->DevData.MountState >= Mounted))
      {
         DriveLetter = LockedScanPartitionTable(DriveLetter, Dev, RTF_PARTITION_ALL);
      }

   // reserve a drive letters for removable hard disks
   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if ((Dev->DeviceType == RTF_DEVICE_FDISK) &&
          ((Dev->DeviceFlags & (RTF_DEVICE_MOUNT_CONTIGUOUS | RTF_DEVICE_REMOVABLE)) == RTF_DEVICE_REMOVABLE))
      {
         DriveLetter = ReserveLogicalDrive(DriveLetter, Dev);
      }
}

/*-----------------------------------*/
static RTFDrive * INTERN LocateDrive(int DriveIndex, MountStates State)
{
   RTFDrive * Drive;

   /* Add for fix drive name, Karen Hsu, 2004/02/17, ADD START */
   if(DrvMappingFlag && ( DriveIndex == DrvMappingNew - MT_BASE_DRIVE_LETTER))
      DriveIndex = DrvMappingOld - MT_BASE_DRIVE_LETTER;
   /* Add for fix drive name, Karen Hsu, 2004/02/17, ADD END */

   if ((DriveIndex < 0) || (DriveIndex >= FS_MAX_DRIVES))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "Drive: %c", DriveIndex);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_FOUND, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_DRIVE_NOT_FOUND);
   }

   Drive = gFS_Data.DriveTable + DriveIndex;

   if (Drive->Dev == NULL)
   {
      // some other thread might be initialising, so wait for it
      RTFSYSLockMutex(RTFLock, RTF_INFINITE);
      RTFSYSFreeMutex(RTFLock);
      if (Drive->Dev == NULL)
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_FOUND, NULL, NULL);
#endif
         XRAISE(RTF_DRIVE_NOT_FOUND);
      }
   }

   LockDevice(Drive->Dev, 0);

   if (stack_query_boot_mode() == NORMAL_BOOT)
   {
      /* Add for usb normal mode access, , 2005/12/01, ADD START */
      if ((Drive->Dev->DeviceFlags & MT_DEVICE_EXPORTING) == MT_DEVICE_EXPORTING)
      {
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
               kal_sprintf(TraceTmpBuf, "Dev:NOR");
            else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
               kal_sprintf(TraceTmpBuf, "Dev:NAND");
            else
               kal_sprintf(TraceTmpBuf, "Dev:Card");
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_DEVICE_EXPORTED_ERROR, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(MT_DEVICE_EXPORTED_ERROR);
      }
      /* Add for usb normal mode access, , 2005/12/01, ADD END */

      /* Add for hot plug in/out issue, Karen Hsu, 2004/02/23, ADD START */
      if((Drive->Dev->DevData.MountState == NotMounted) &&
         (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE))
      {
         DiscardAllBuffers(Drive->Dev);
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);

#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
               kal_sprintf(TraceTmpBuf, "Dev:NOR");
            else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
               kal_sprintf(TraceTmpBuf, "Dev:NAND");
            else
               kal_sprintf(TraceTmpBuf, "Dev:Card");
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_MEDIA_CHANGED, NULL, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(RTF_MEDIA_CHANGED);
      }
      /* Add for hot plug in/out issue, Karen Hsu, 2004/02/23, ADD END */
   }/* boot_mode() == NORMAL_BOOT */

   /* Remove to use our mechanism instead, Karen Hsu, 2004/03/03, REM START */
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   /* Remove to use our mechanism instead, Karen Hsu, 2004/03/03, REM END */

   if (Drive->MountState < State)
   XTRY
      case XCODE:
         MountLogicalDrive(Drive, State);
         break;
      default:
         UnlockDevice(Drive->Dev);
         break;
      case XFINALLY:
         break;
   XENDX
   return Drive;
}

/*-----------------------------------*/
static RTFDrive * INTERN FindDefaultDrive(void)
{
   RTFDrive * volatile Result = NULL;

   XTRY
      case XCODE:
         Result = LocateDrive(MT_BASE_DRIVE_INDEX, HasFileSystem);
         break;
      default:
         XHANDLED;
         break;
      case XFINALLY:
         break;
   XENDX
   if (Result == NULL)
      return LocateDrive(0, HasFileSystem);
   else
      return Result;
}

/*-----------------------------------*/
void RTFAPI FreeFTSlotAndDevice(RTFile * f)
{
   if (f)
   {
      RTFDevice * Dev = f->Dev;
      FreeFTSlot(f);
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
      if (Dev)
         UnlockDevice(Dev);
   }
}

/*-----------------------------------*/
RTFile * RTFAPI ParseFileName1(const char * FileName, RTFHANDLE File)
// FileName: [D:][\][Path\]FileName[.Ext]
//           \\.\FMapF\[HexStrings]
//           \\.\PHYSICALDRIVEx
//           \\.\D:
{
   int UL;
   RTFile * f;

   if (File)
   {
      f = ParseFileHandle(File);
   }
   else
   {
      f = ReserveFTSlot();
   }

   while (compASCII(FileName, 0, ' '))
      FileName += 2;

   UL = kal_dchar_strlen(FileName);

   XTRY
      case XCODE:

         // check for special file names
         if ((UL == 12) && compUAstring(FileName, "\\\\.\\", 4) && compASCII(FileName, 5, ':'))
         {
            // \\.\X:
            // for floppies, we only need Initialized
            // for partitions, we need Accessible
            memcpy((void*) f->FullName, (void*) FileName, UL);
            f->Drive = LocateDrive(_rtftoupper(toASCII(FileName, 4)) - MT_BASE_DRIVE_LETTER, Initialized);
            setASCII(f->FullName, 4,  MT_BASE_DRIVE_LETTER + gFS_Data.DriveTable - f->Drive);
            f->Dev = f->Drive->Dev;
            if (f->Dev->DeviceType == RTF_DEVICE_FDISK) // we want a drive file
            {
               if (f->Drive->MountState < Accessible)
                  MountLogicalDrive(f->Drive, Accessible);
               f->SpecialKind = Volume;
            }
            else
               f->SpecialKind = PhysicalDisk;
         }
         else if ((UL == 36) && (compUAstring(FileName, "\\\\.\\PHYSICALDRIVE", 17)))
         {
            // it's a physical disk
            RTFDevice * Dev;
            // some other thread might be initialising, so wait for it
            RTFSYSLockMutex(RTFLock, RTF_INFINITE);
            RTFSYSFreeMutex(RTFLock);
            memcpy((void*) f->FullName, (void*) FileName, UL);
            for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
               if ((toASCII(f->FullName, 17) - '0') == Dev->DevData.PhysicalDiskIndex)
               {
                  f->Dev = Dev;
                  break;
               }
            if (f->Dev == NULL)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_FOUND, NULL, NULL);
#endif
               XRAISE(RTF_DRIVE_NOT_FOUND);
            }
            LockDevice(f->Dev, f->Flags);
            if (f->Dev->DevData.MountState < Initialized)
               MountDevice(f->Dev, Initialized);
            f->SpecialKind = PhysicalDisk;
         }
/* FileMapFile parse file name, MTK_WCP_SW , 2005/08/21, MODIFY START */
         else if ((UL >= 90) && (compUAstring(FileName, "\\\\.\\FMapF\\", 10)))
         {
            /* it's probably a virtual file */
            f->SpecialKind = FileMapFile;
            memcpy((void*) f->FullName, (void*) FileName, UL);
            SetupFMapF_FileHandle(f);
         }
/* FileMapFile parse file name, MTK_WCP_SW , 2005/08/21, MODIFY END */
         else
         {
            /* Add error checking, Karen Hsu, 2004/10/08, ADD START */
            if(UL == 0)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, NULL, NULL);
#endif
               XRAISE(RTF_PARAM_ERROR);
            }
            /* Add error checking, Karen Hsu, 2004/10/08, ADD END */
            // see if the dir name contains a drive letter
            if ((UL < 2) || !compASCII(FileName, 1, ':'))
               if (DefaultDrive == NULL)
                  f->Drive = DefaultDrive = FindDefaultDrive();
               else
                  f->Drive = LocateDrive(DefaultDrive - gFS_Data.DriveTable, HasFileSystem);
            else
               f->Drive = LocateDrive(_rtftoupper(toASCII(FileName, 0)) - MT_BASE_DRIVE_LETTER, HasFileSystem);
            f->Dev = f->Drive->Dev;
            f->SpecialKind = NormalFile;
         }
         break;
      default:
         if (f->Dev) UnlockDevice(f->Dev);
         FreeFTSlot(f);
         break;
      case XFINALLY:
         break;
   XENDX
   return f;
}

/*-----------------------------------*/
kal_bool gMT_Sanity = KAL_FALSE;

RTFCluster RTFAPI GetClusterValue(RTFDrive * Drive, RTFCluster Cluster)
{
   RTFCluster Result = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */

   if (((Cluster != 1) || (gMT_Sanity != KAL_TRUE)) && 
      ((Cluster < 2l) || (Cluster >= Drive->Clusters)))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR, Cluster: %d", Cluster);
         else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND, Cluster: %d", Cluster);
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card, Cluster: %d", Cluster);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FAT_ALLOC_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_FAT_ALLOC_ERROR);
   }

/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD START */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
   if (stack_query_boot_mode() != USBMS_BOOT)
   {  
      UINT *ShadowFATptr=NULL;

#ifdef __FS_SHADOW_NAND__
      if (Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
      {  
         ShadowFATptr = Shadow_FAT_Array_NAND;
      }
#endif
#ifdef __FS_SHADOW_CARD__
      if (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
      {  
         ShadowFATptr = Shadow_FAT_Array_CARD;
      }
#endif
      if( ShadowFATptr )
      {
         if (Drive->FATType == RTFAT16)
         {
            Result = ShadowFATptr[Cluster/2];
            if (Cluster & 0x01)
               Result >>= 16;
            else
               Result &= 0x0000FFFF;

            if (Result >= 0xFFF7)
               Result |= 0x0FFF0000;
         
         else
            Result = ShadowFATptr[Cluster];
      goto GetClusterValueContinue;
      }
   }
#endif

/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD END */

   switch (Drive->FATType)
   {
      case RTFAT12:
      {
         DWORD Pos;
         UINT  B1, B2;
         BYTE  * FATPtr;

         Pos    = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
         FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift), 0);
         B1     = FATPtr[Pos & (Drive->Dev->DevData.SectorSize-1)];

         Pos++;
         FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift), 0);
         B2     = FATPtr[Pos & (Drive->Dev->DevData.SectorSize-1)];

         Result = (Cluster & 1) ? ((B2 << 4) | (B1 >> 4)) : (((B2 & 0x0F) << 8) | B1);
         if (Result >= 0xFF7)
            Result |= 0x0FFFF000;
         break;
      }
      case RTFAT16:
      {
         WORD * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-1)), 0);
         Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 1)-1)];
         if (Result >= 0xFFF7)
            Result |= 0x0FFF0000;
         break;
      }
      case RTFAT32:
      {
         DWORD * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-2)), 0);
         Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 2)-1)] & 0x0FFFFFFF;
         break;
      }
#ifdef DEBUG
      default:
         RTFSYSErrorExit("Invalid file system ID in GetClusterValue", 1);
#endif
         EXT_ASSERT(0, (UINT)Drive, Drive->FATType, 0);
   }

/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD START */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
GetClusterValueContinue:
#endif
/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD END */

   if ((Result != 0) &&
       (Result < 0x0FFFFFF7) &&
       (gMT_Sanity != KAL_TRUE) &&
       ((Result < 2) || (Result >= Drive->Clusters)))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR, ClusterValue: %d", Result);
         else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND, ClusterValue: %d", Result);
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card, ClusterValue: %d", Result);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FAT_ALLOC_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_FAT_ALLOC_ERROR);
   }
   return Result;
}

/*-----------------------------------*/
void RTFAPI SetClusterValue(RTFDrive * Drive, RTFCluster Cluster, RTFCluster Value)
{
   RTFSector S1=0;
   RTFSector S2=0;

   if (((Cluster != 1) || (gMT_Sanity != KAL_TRUE)) &&
      ((Cluster < 2l) || (Cluster >= Drive->Clusters)))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR, Cluster: %d", Cluster);
         else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND, Cluster: %d", Cluster);
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card, Cluster: %d", Cluster);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FAT_ALLOC_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_FAT_ALLOC_ERROR);
   }
#ifdef DEBUG
   if ((Value != 0) &&
       (Value < 0x0FFFFFF7) &&
       ((Cluster != 1) || (gMT_Sanity != KAL_TRUE)) &&
       ((Value < 2) || (Value >= Drive->Clusters)))
      RTFSYSErrorExit("Invalid value in SetClusterValue", 1);
   if (Cluster == Value)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR, Cluster: %d", Cluster);
         else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND, Cluster: %d", Cluster);
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card, Cluster: %d", Cluster);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FAT_ALLOC_ERROR, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_FAT_ALLOC_ERROR);
   }
#endif

/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD START */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
   if (stack_query_boot_mode() != USBMS_BOOT)
   {  
      UINT *ShadowFATptr=NULL;

#ifdef __FS_SHADOW_NAND__
      if (Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
      {  
         ShadowFATptr = Shadow_FAT_Array_NAND;
      }
#endif
#ifdef __FS_SHADOW_CARD__
      if (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
      {  
         ShadowFATptr = Shadow_FAT_Array_CARD;
      }
#endif
      if (ShadowFATptr)
      {
         if (Drive->FATType == RTFAT16)
         {
            if (Cluster & 0x01)
                ShadowFATptr[Cluster/2] = (Value << 16) + (ShadowFATptr[Cluster/2] & 0x0000FFFF);
            else
                ShadowFATptr[Cluster/2] = (Value + (ShadowFATptr[Cluster/2] & 0xFFFF0000));
         }
         else
            ShadowFATptr[Cluster] = Value;
         return;
      }
   }
#endif
/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD END */

   switch (Drive->FATType)
   {
      case RTFAT12:
      {
         DWORD Pos, O;
         UINT  B1, B2;
         BYTE  * FATPtr;

         Pos    = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
         S1     = Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift);
         FATPtr = GetBuffer(Drive->Dev, S1, 0);
         O      = Pos & (Drive->Dev->DevData.SectorSize-1);

         if (Cluster & 1)  // odd cluster numbers start in the middle
         {
            B1 = FATPtr[O];
            B1 = (B1 & 0x0F) | (Value << 4);
         }
         else
            B1 = Value;
         FATPtr[O] = B1;

         Pos++;
         S2     = Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift);
         if (S1 != S2)
         {
            SetDirty(Drive->Dev);
            Drive->Dev->DevData.B->FATSectorInfo = Drive;
            FATPtr = GetBuffer(Drive->Dev, S2, 0);
         }
         O      = Pos & (Drive->Dev->DevData.SectorSize-1);

         if (Cluster & 1)  // odd cluster numbers start in the middle
            B2 = Value >> 4;
         else
         {
            B2 = FATPtr[O];
            B2 = (B2 & 0xF0) | ((Value >> 8) & 0x0F);
         }
         FATPtr[O] = B2;
         break;
      }
      case RTFAT16:
      {
         WORD * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-1)), 0);
         FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 1)-1)] = Value;
         break;
      }
      case RTFAT32:
      {
         DWORD * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-2)), 0);
         FATPtr += (Cluster & ((Drive->Dev->DevData.SectorSize >> 2)-1));
         *FATPtr = (*FATPtr & 0xF0000000) | Value;
         break;
      }
#ifdef DEBUG
      default:
         RTFSYSErrorExit("Invalid file system ID in SetClusterValue", 1);
#endif
         EXT_ASSERT(0, (UINT)Drive, Drive->FATType, 0);
   }
   SetDirty(Drive->Dev);
   Drive->Dev->DevData.B->FATSectorInfo = Drive;

   if ((Drive->FATType == RTFAT12) && (S1 != S2))
   {
      CommitBuffer(Drive->Dev);
      GetBuffer(Drive->Dev, S1, 0);
      CommitBuffer(Drive->Dev);
   }

   if ((Cluster != 1) && ((Value == 0) || (Value == RTF_BAD_CLUSTER)))
      DiscardSectors(Drive->Dev, CLUSTER_TO_SECTOR(Drive, Cluster), Drive->SectorsPerCluster);
}

/*-----------------------------------*/
static RTFCluster INTERN FATClusterChainLength(RTFDrive * Drive, RTFCluster Cluster, RTFCluster * LastCluster)
// follows the chain until the last cluster is found
// return number of clusters in chain
// *LastCluster has the last cluster of the chain
{
   RTFCluster NextCluster;
   RTFCluster i = 0;

   while (1)
   {
      i++;
      NextCluster = GetClusterValue(Drive, Cluster);
      if (NextCluster >= RTF_CLUSTER_CHAIN_END)
      {
         if (LastCluster)
            *LastCluster = Cluster;
         return i;
      }
      Cluster = NextCluster;
   }
}

/*-----------------------------------*/
int RTFAPI UpdateClusterWatermark(RTFDrive * Drive, RTFCluster Watermark, int DeltaFreeClusters)
//static int INTERN UpdateClusterWatermark(RTFDrive * Drive, RTFCluster Watermark, int DeltaFreeClusters)
// returns 1 if flushing is required
{
#ifdef DEBUG
   if (Watermark < 2)
       RTFSYSErrorExit("invalid watermark in UpdateClusterWatermark", 1);
#endif
   if (Watermark != RTF_INVALID_CLUSTER)
      Drive->ClusterWatermark = (Watermark < Drive->Clusters) ? Watermark : 2;
   if (Drive->FreeClusterCount != RTF_INVALID_CLUSTER)
      Drive->FreeClusterCount += DeltaFreeClusters;
   if (Drive->InfoSector)
   {
      RTFFAT32InfoSector * IS;
      IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      if ((IS->NextFreeCluster != Drive->ClusterWatermark) || (IS->FreeClusterCount != Drive->FreeClusterCount))
      {
         IS->Signature1 = 0x41615252L;
         IS->Signature2 = 0x61417272L;
         IS->Signature  = 0xAA550000L;
         IS->NextFreeCluster = Drive->ClusterWatermark;
         IS->FreeClusterCount = Drive->FreeClusterCount;
         SetDirty(Drive->Dev);
         return 1;
      }
   }
   return 0;
}

/*-----------------------------------*/
#define FAT_DELETE_MAX_CLUSTERS 64

RTFCluster RTFAPI FATDelete(RTFDrive * Drive, RTFCluster Cluster, RTFile * f)
//static RTFCluster INTERN FATDelete(RTFDrive * Drive, RTFCluster Cluster)
// delete a complete cluster chain starting at Cluster
{
   RTFCluster NextCluster;
   RTFCluster ChainEnd = Cluster, ChainStart = Cluster;
   RTFCluster Clusters = 0;

   while (Cluster < RTF_CLUSTER_CHAIN_END)
   {
      NextCluster = GetClusterValue(Drive, Cluster);
      SetClusterValue(Drive, Cluster, 0);
      Clusters++;

      // to avoid occupying the lock for a long period
      if ((Clusters % FAT_DELETE_MAX_CLUSTERS) == 0)
      {
         UnlockDevice(Drive->Dev);
         LockDevice(Drive->Dev, 0);
      }

      /* Get Segment Range */
      ChainStart = (Cluster < ChainStart) ? Cluster : ChainStart;
      ChainEnd   = (Cluster > ChainEnd  ) ? Cluster : ChainEnd  ;
      Cluster = NextCluster;
   }

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif
   UpdateClusterWatermark(Drive, ChainStart, Clusters);

/* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD START */
   FATLowerSubMark(Drive, ChainStart, ChainEnd);
/* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD END */

   /* Add for quota management, Karen Hsu, 2004/08/10, ADD START */
#ifdef __FS_QM_SUPPORT__
   if(f && (f->Drive->QuotaMgt))
   {
      int quota_idx = -1;

#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "After Delete: %d, Free: %d,", Clusters, f->Drive->FreeClusterCount);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_OK, f, (BYTE *)TraceTmpBuf);
      }
#endif

      if(f->FullName[6] == '@')
      {
         GetQuotaEntry(&quota_idx, f);
         if(quota_idx >= 0)
         {
            if(gFS_IntQuotaSet[quota_idx].Qnow >= Clusters)
            {
               gFS_IntQuotaSet[quota_idx].Qnow -= Clusters;

               #ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                  {
                     kal_sprintf(TraceTmpBuf, "Idx: %d, Now: %d", quota_idx, gFS_IntQuotaSet[quota_idx].Qnow);
                     memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                     MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_OK, f, (BYTE *)TraceTmpBuf);
                  }
               #endif
            }
            else
               gFS_IntQuotaSet[quota_idx].Qnow = 0;
         }
      }
   }
#endif
   /* Add for quota management, Karen Hsu, 2004/08/10, ADD END */
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif
   return Clusters;
}

/*-----------------------------------*/
static RTFCluster INTERN FATZeros(RTFDrive * Drive, RTFCluster Cluster, RTFCluster MaxClusters)
// determine the number of free consecutive clusters starting at Cluster
{
   RTFCluster i;

   for (i=0; i<MaxClusters; i++)
   {
      if (Cluster == Drive->Clusters)
         return i;
      if (GetClusterValue(Drive, Cluster) != 0)
         return i;
      Cluster++;
   }
   return MaxClusters;
}

/*-----------------------------------*/
static void INTERN FATMarkSegment(RTFDrive * Drive, RTFCluster Cluster, RTFCluster Clusters)
// chain up a contiguous cluster chain
{
   RTFCluster i;

   for (i=Cluster; i<(Cluster+Clusters-1); i++)
      SetClusterValue(Drive, i, i+1);

   SetClusterValue(Drive, Cluster+Clusters-1, RTF_CHAIN_END_MARK);

   if ((Cluster == Drive->ClusterWatermark) && ((Cluster+Clusters) < Drive->Clusters))
      UpdateClusterWatermark(Drive, Cluster+Clusters, -Clusters);
   else
      UpdateClusterWatermark(Drive, RTF_INVALID_CLUSTER, -Clusters);

/* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD START */
   FATHoistSubMark(Drive, Cluster, Cluster+Clusters);
/* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD END */
}

/*-----------------------------------*/
static RTFCluster INTERN AllocateFATSegment(RTFDrive * Drive, RTFCluster * Cluster, RTFCluster MaxClusters, RTFile * f)
//static RTFCluster INTERN AllocateFATSegment(RTFDrive * Drive, RTFCluster * Cluster, RTFCluster MaxClusters)
// Allocate a segment anywhere, start searching at Cluster (if valid), with maximum (less is allowed)
// Return number of clusters allocated
{
   /* Fix C1406: When disk is full, RTFGetDiskInfoEx will let watermark becomes
      RTF_INVALID_CLUSTER. This will cause FATZeros raise RTF_FAT_ALLOC_ERROR
      exception, Karen Hsu, 2004/04/27, MOD START */
   RTFCluster SegmentLength = 0, C;
   //RTFCluster SegmentLength, C;
   /* Fix C1406, Karen Hsu, 2004/04/27, MOD END */
   int Try = 0;
#ifdef __FS_QM_SUPPORT__
   int quota_idx = -1; /* Add for quota management, Karen Hsu, 2004/08/10, ADD */
#endif


   C = *Cluster;

   if ((C < 2) || (C >= Drive->Clusters))
      C = Drive->ClusterWatermark;

   /* Fix C1406, Karen Hsu, 2004/04/27, ADD START */
   if(C == RTF_INVALID_CLUSTER)
   {
      C = 2;
      Try = 1;
   }
   /* Fix C1406, Karen Hsu, 2004/04/27, ADD END */
   /* Speedup bootup time with full disk, Karen Hsu, 2005/05/18, ADD START */
   else if(Drive->FreeClusterCount == 0)
   {
      *Cluster = 0;
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR");
         else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND");
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card");
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DISK_FULL, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_DISK_FULL);
   }
   /* Speedup bootup time with full disk, Karen Hsu, 2005/05/18, ADD END */

   while (1)
   {
      SegmentLength = FATZeros(Drive, C, MaxClusters);
      if (SegmentLength > 0)
      {
         /* Add for quota management, Karen Hsu, 2004/08/10, ADD START */
#ifdef __FS_QM_SUPPORT__
         if(f->Drive->QuotaMgt)
         {
            char * fName;
            fName = &f->FullName[6];

            #ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Before Allocate: %d, Free: %d", SegmentLength, f->Drive->FreeClusterCount);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_OK, f, (BYTE *)TraceTmpBuf);
               }
            #endif

            if(*fName == '@')
            {
               GetQuotaEntry(&quota_idx, f);
               if(quota_idx >= 0)
               {
                  if(QMPermitAllocate(f->Drive->FreeClusterCount, quota_idx, SegmentLength) != RTF_NO_ERROR)
                  {
                     *Cluster = 0;
#ifdef __FS_TRACE_SUPPORT__
                        if(g_TraceFlag & MT_TRACE_ERROR)
                        {
                           kal_sprintf(TraceTmpBuf, "Idx: %d", quota_idx);
                           memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                           MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_ERR, f, (BYTE *)TraceTmpBuf);
                        }
#endif
                     XRAISE(MT_APP_QUOTA_FULL);
                  }
               }
            }
            else if(WFNamesMatch(fName, (char *)NvramName) == 0)
            {
               if(QMPermitAllocate(f->Drive->FreeClusterCount, -1, SegmentLength) != RTF_NO_ERROR)
               {
                  *Cluster = 0;
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                  {
                     kal_sprintf(TraceTmpBuf, "None NVRAM Access!");
                     memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                     MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_ERR, f, (BYTE *)TraceTmpBuf);
                  }
#endif
                     XRAISE(MT_APP_QUOTA_FULL);
               }
            }
         }
#endif
         /* Add for quota management, Karen Hsu, 2004/08/10, ADD END */
         FATMarkSegment(Drive, C, SegmentLength);
         *Cluster = C;

#ifdef __FS_QM_SUPPORT__
         if(quota_idx >= 0)
         {
            gFS_IntQuotaSet[quota_idx].Qnow += SegmentLength; /* Add for quota management, Karen Hsu, 2004/08/10, ADD */

            #ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Idx: %d, Now: %d", quota_idx, gFS_IntQuotaSet[quota_idx].Qnow);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_OK, f, (BYTE *)TraceTmpBuf);
               }
            #endif
         }
#endif
         return SegmentLength;
      }
      else
      {
         C++;
         /* Improve Response Time, MTK_WCP_SW , 2006/02/22, ADD START */
         C = FATSearchZeroInBuffer(Drive, C);
         /* Improve Response Time, MTK_WCP_SW , 2006/02/22, ADD END   */
         /* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD START */
         if ((C & SUBMARK_MASK) == 0x0)
         {
            C = FATHintSearchBySubMark(Drive, C, Try);
         }
         /* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD END   */
         if (C >= Drive->Clusters)
         {
            if (Try == 0)
            {
               C = 2;
               Try = 1;
            }
            else
            /* Fix C2418: Keep using same FH, will write to watermark cluster, Karen Hsu, 2004/06/02, MOD START */
            {
               *Cluster = 0;
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NOR");
                  else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                     kal_sprintf(TraceTmpBuf, "Dev:NAND");
                  else
                     kal_sprintf(TraceTmpBuf, "Dev:Card");
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DISK_FULL, NULL, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_DISK_FULL);
            }
            /* Fix C2418: Keep using same FH, will write to watermark cluster, Karen Hsu, 2004/06/02, MOD END */
         }
      } /* END if (SegmentLength) */
   } /* END while (1) */
}

/*-----------------------------------*/
void RTFAPI InitFilePointer(RTFile * f)
// set file pointer and cluster/sector/offset to 0
// to move back, you must call InitFilePointer first
// note that cluster 0 indicates unallocated space (except for the root)
{
   f->FilePointer = 0;
   f->Offset = 0;
   f->LastCluster = 0;
   f->Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
}

/*-----------------------------------*/
static void INTERN MoveFilePointer(RTFile * f, UINT Offset)
// move the file pointer and cluster/offset forward
// to move back, you must call InitFilePointer first
// this function cannot move the file pointer beyond the allocated file
// size
{
   DWORD Ofs = f->Offset + Offset;

   if ((f->FilePointer+Offset) < f->FilePointer)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "FilePointer: %d, Offset: %d", f->FilePointer, Offset);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_TOO_LARGE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_FILE_TOO_LARGE);
   }

   f->FilePointer += Offset;

   // root dir is a special case
   if (f->Cluster == RTF_ROOT_DIR)
   {
      f->Offset = Ofs;
      return;
   }

   while (Ofs >= f->Drive->ClusterSize)
   {
      Ofs -= f->Drive->ClusterSize;
      if ((f->Cluster == 0) || (f->Cluster >= RTF_CLUSTER_CHAIN_END))
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "Cluster: %d", f->Cluster);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FAT_ALLOC_ERROR, f, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(RTF_FAT_ALLOC_ERROR);  // Attempt to move beyond last cluster
      }
      f->LastCluster = f->Cluster;
      f->Cluster = GetClusterValue(f->Drive, f->LastCluster);
   }
   if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
      f->Cluster = 0;
   f->Offset = Ofs;
}

/*-----------------------------------*/
static UINT INTERN MoveFilePointerSegment(RTFile * f, UINT Offset)
// move the sector aligned file pointer and cluster/offset forward within
// one segment of contiguous clusters.
// return value is length of segment in bytes.
// the file pointer is advanced by the same value.
// this function can move less bytes then requested
{
   DWORD Ofs = f->Offset + Offset;

   if ((f->FilePointer+Offset) < f->FilePointer)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         kal_sprintf(TraceTmpBuf, "FilePointer: %d, Offset: %d", f->FilePointer, Offset);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_TOO_LARGE, f, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_FILE_TOO_LARGE);
   }

   // root dir is a special case
   if (f->Cluster == RTF_ROOT_DIR)
   {
      f->FilePointer += Offset;
      f->Offset = 0;
      return Offset;
   }

   while (Ofs >= f->Drive->ClusterSize)
   {
      Ofs -= f->Drive->ClusterSize;
      f->LastCluster = f->Cluster;
      f->Cluster = GetClusterValue(f->Drive, f->LastCluster);
      if (f->Cluster != (f->LastCluster+1))
      {
         Offset -= Ofs;
         Ofs = 0;
      }
   }
   if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
      f->Cluster = 0;
   f->FilePointer += Offset;
   f->Offset = Ofs;
   return Offset;
}

/*-----------------------------------*/
DirEntry RTFAPI EntryType(const RTFDOSDirEntry * D)
{
   if (D->FileName[0] == '\0')
      return NeverUsed;
   if (D->FileName[0] == RTF_DELETED)
      return Available;
   if (D->Attributes == RTF_LONGNAME_ATTR)
      return Lfn;
   return InUse;
}

/*-----------------------------------*/
RTFDOSDirEntry * RTFAPI GetDir(RTFDrive * Drive, const RTFDirLocation * Pos)
{
   RTFSector Sector = CLUSTER_TO_SECTOR_DIR(Drive, Pos->Cluster) + (Pos->Index / DIRS_PER_SECTOR(Drive));

   return (RTFDOSDirEntry *) GetBuffer(Drive->Dev, Sector, 0) + (Pos->Index % DIRS_PER_SECTOR(Drive));
}

/*-----------------------------------*/
static RTFDOSDirEntry * INTERN StartDirSearch(RTFDrive * Drive, RTFCluster Cluster, UINT Index, RTFDirLocation * DSR)
{
   if ((Cluster != RTF_ROOT_DIR) && ((Cluster < 2L) || (Cluster >= Drive->Clusters)))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         if(Drive->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NOR, Cluster: %d, Index: %d", Cluster, Index);
         else if(Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
            kal_sprintf(TraceTmpBuf, "Dev:NAND, Cluster: %d, Index: %d", Cluster, Index);
         else
            kal_sprintf(TraceTmpBuf, "Dev:Card, Cluster: %d, Index: %d", Cluster, Index);
         memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_BAD_DIR_ENTRY, NULL, (BYTE *)TraceTmpBuf);
      }
#endif
      XRAISE(RTF_BAD_DIR_ENTRY);
   }

   DSR->Cluster = Cluster;
   DSR->Index   = Index;

   return GetDir(Drive, DSR);
}

/*-----------------------------------*/
static int INTERN IncDir(RTFDrive * Drive, RTFDirLocation * DSR)
{
   DSR->Index++;

   if (DSR->Cluster == RTF_ROOT_DIR)
   {
      if (DSR->Index >= Drive->RootDirEntries)
         return 0;
   }
   else
   {
      if (DSR->Index >= (Drive->ClusterSize/sizeof(RTFDOSDirEntry)))
      {
         RTFCluster NextCluster = GetClusterValue(Drive, DSR->Cluster);
         DSR->Index = 0;
         if (NextCluster >= RTF_CLUSTER_CHAIN_END)
            return 0;
         DSR->Cluster = NextCluster;
      }
   }
   return 1;
}

/*-----------------------------------*/
RTFDOSDirEntry * RTFAPI NextDir(RTFDrive * Drive, RTFDirLocation * DSR)
{
   if (IncDir(Drive, DSR))
      return GetDir(Drive, DSR);
   else
      return NULL;
}

/*-----------------------------------*/
int RTFAPI MakeShortFileName(const RTFDOSDirEntry * FileInfo, char * FileName, UINT MaxLength)
// translate short file name to unicode
// input is OEM/Native
// output is Unicode
{
   const __packed char * LastName; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   const __packed char * LastExt; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int i, N, E;

   LastExt = FileInfo->Extension + 2;
   for (i=0; i<3; i++)
      if (LastExt[0] == ' ')
         LastExt--;
   if (LastExt == (const char*)((unsigned)FileInfo->Extension-1))
      LastExt = NULL;

   LastName = FileInfo->FileName + 7;
   for (i=0; i<8; i++)
      if (LastName[0] == ' ')
         LastName--;
   if (LastName == (const char*)((unsigned)FileInfo->FileName-1))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
      return RTF_INVALID_FILENAME;
   }

   N = LastName - FileInfo->FileName + 1;
   E = LastExt ? (LastExt - FileInfo->Extension + 1) : 0;

   if (FileInfo->Attributes & RTF_ATTR_VOLUME)
   {
      if ((N+E+1) > MaxLength)
         return RTF_STRING_BUFFER_TOO_SMALL;
      memcpy(FileName,(char*) FileInfo->FileName, N);
   }
   else
   {
      if ((N+E+1+(E != 0)) > MaxLength)
         return RTF_STRING_BUFFER_TOO_SMALL;
      memcpy(FileName,(char*) FileInfo->FileName, N);
      if (E)
      {
         FileName[N] = '.';
         N++;
      }
   }
   memcpy(FileName+N,(char*) FileInfo->Extension, E);

   FileName[N+E] = '\0';

   return RTF_NO_ERROR;
}

/*-----------------------------------*/
BYTE RTFAPI ShortNameCheckSum(const BYTE * Name)
{
   int i;
   BYTE Sum = 0;
   for (i=0; i<11; i++)
      Sum = ((Sum & 1) ? 0x80 : 0) + (Sum >> 1) + Name[i];
   return Sum;
}

/*-----------------------------------*/
/* copy long file name from LFN entry, and translate to short file name format */
static void INTERN CopyLFN_toShort(char * Name, const LFNDirEntry * LD)
{
   UINT i, index=0;
   WCHAR wide_c;
   WORD U;

   for (i=0; i<13; i++)
   {
      if(i < 5)
      {
         U = LD->Name1[i];
      }
      else if(i < 11)
      {
         U = LD->Name2[i-5];
      }
      else
      {
         U = LD->Name3[i-11];
      }

      if ((U == 0) || (U == 0xFFFF))
         break; // end of string
      wide_c = UnicodetoNative((WCHAR)U);
      wide_c = ( wide_c>=0x61 && wide_c<=0x7a) ? wide_c-(0x61-0x41) : wide_c;
      if ( wide_c&0xff00 )
      {
         Name[index++] = (char)(wide_c>>8);   /* Fix NULL string in multi-language, Karen Hsu, 2005/03/14, MOD */
         Name[index++] = (char)(wide_c&0xff); /* Fix NULL string in multi-language, Karen Hsu, 2005/03/14, MOD */
      }
      else
         Name[index++] = (char)wide_c;
   }

   Name[index] = 0;
}

/*-----------------------------------*/
/* copy long file name from LFN entry, remain the Unicode format */
void RTFAPI CopyLFN(char * Name, const LFNDirEntry * LD)
{
   UINT i, index=0;
   WORD U;

   for (i=0; i<13; i++)
   {
      if(i < 5)
      {
         U = LD->Name1[i];
      }
      else if(i < 11)
      {
         U = LD->Name2[i-5];
      }
      else
      {
         U = LD->Name3[i-11];
      }

      if ((U == 0) || (U == 0xFFFF))
      {
         Name[index++] = 0;
         Name[index] = 0;
         break; // end of string
      }
      Name[index++] = U&0xff;
      Name[index++] = U>>8;
   }
}

/*-----------------------------------*/
/*In terms of WCHAR */
int RTFAPI LFNCharCount(const LFNDirEntry * LD)
{
   int i;

   for (i=0; i<13; i++)
   {
      if(i < 5)
      {
         if((UINT)(LD->Name1[i]) == 0)
            return i;
      }
      else if(i < 11)
      {
         if((UINT)(LD->Name2[i-5]) == 0)
            return i;
      }
      else
      {
         if((UINT)(LD->Name3[i-11]) == 0)
            return i;
      }
   }
   return 13;
}


/*-----------------------------------*/
static int INTERN FNamesMatch(const char * N1, const char * N2)
// match file name components (i.e. up to '\' or end-of-string
// compare two short file name (native/ASCII)
{
   char c1 = 0, c2, c0;

   do {
      c0 = c1;
      c1 = _rtftoupper(*N1++);
      if (c1 == '\\') c1 = '\0';
      c2 = _rtftoupper(*N2++);
      if (c2 == '\\') c2 = '\0';
   } while ((c1 || (c0 & 0x80)) && (c1 == c2)); // for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...

   return c1 == c2;
}

/*-----------------------------------*/
int RTFAPI WFNamesMatch(const char * N1, const char * N2)
// match file name components in unicode, i.e. up to '\' or end-of-string
// operation on wide character string.
{
   WCHAR c1, c2;

   do {
      c1 = isASCII(N1,0) ? (WCHAR)_rtftoupper(N1[0]) : *(WCHAR *)N1;
      N1+=2;
      if (c1 == 0x5c) c1 = 0;
      c2 = isASCII(N2,0) ? (WCHAR)_rtftoupper(N2[0]) : *(WCHAR *)N2;
      N2+=2;
      if (c2 == 0x5c) c2 = 0;
   } while (c1 && (c1 == c2));

   return c1 == c2;
}

/*-----------------------------------*/
// for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...
int MTNativeFileNameLen(char *filename)
{
   int len=0;
   
   while(1)
   {
      if (filename[len] & 0x80)
      {
         len += 2;
      }
      else if (filename[len] == 0)
      {
         break;
      }
      else
      {
         len++;
      }
   }
   
   return len;
}
/*-----------------------------------*/
/* Note that FileName is expected to be a unicode stream */
int RTFAPI SearchFile(RTFile * f, UINT Flags, const char * FileName, RTFDirLocation * DSR_Hint)
// if path not found -> exception
// if file not found, returns 0, else 1
// if 0, the file's parent is opened
// update DirPos, DirEntry, and FullName in f->
// [X:][\][Path\][Path\]file (Unicode format)
{
   RTFDirLocation DSR;
   const RTFDOSDirEntry * D;
   const char * pN = FileName;
   char * pF = f->FullName;
   BYTE CheckSum = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int LFNIndex;
   /* Optimize algo, Karen Hsu, 2004/04/28, ADD START */
   kal_bool SkipMatchSFN;
   char pTemp[12], pTemp2[12];
   /* Optimize algo, Karen Hsu, 2004/04/28, ADD END */

   if ( (pN[0]||pN[1]) && compASCII(pN, 1, ':'))
      pN += 4;

   kal_dchar_strcpy(pF, f->Drive->CurrDir);

   if (compASCII(pN, 0, '\\'))
   {
      MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
      pN += 2;
      pF+=6;
      pF[0] = '\0';
      pF[1] = '\0';
   }
   else // it's a relative path
   {
      f->DirEntry = f->Drive->CurrDirEntry;
      pF += kal_dchar_strlen(pF);
   }

NextDir:

   // done, file found
   if (pN == NULL)
   {
      if (DSR_Hint)
      {
        DSR_Hint->Cluster= DSR.Cluster;
        DSR_Hint->Index  = DSR.Index;
      }
      
      return 1;
   }
   // skip any ".", and multiple "\"
   while ( WFNamesMatch((char *)pN, (char *)dchar_dot) || compASCII(pN, 0, '\\') )// || compASCII(pN, 0, ' '))
      pN += 2;

   // found
   if ( compASCII(pN, 0, '\0') )
      return 1;

   if ( !compASCII(pF, -1, '\\'))
   {
      setASCII(pF, 0, '\\');
      pF += 2;
   }

   // if there is only one component left, and we are searching the parent,
   // return 0 (not found, but parent found)
   // if ((Flags & SEARCH_PARENT) && (strchr(pN, '\\') == NULL))
   if ((Flags & SEARCH_PARENT) && (kal_dchar_strchr(pN, 0x5c) == NULL))
      goto Return0;

   if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, f, (BYTE *)FileName);
#endif
      XRAISE(RTF_PATH_NOT_FOUND);
   }

   // search
   f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
   if (DSR_Hint && DSR_Hint->Cluster)
   {
      const char *ppN = pN;

      while ((pN = kal_dchar_strchr(pN, '\\')) != 0)
      {
         // skip any " ", ".", and multiple "\"
         while ( WFNamesMatch((char *)pN, (char *)dchar_dot) || compASCII(pN, 0, '\\')) // || compASCII(pN, 0, ' ') )
            pN += 2;

         ppN = pN;
      }

      pN = ppN;
      D = StartDirSearch(f->Drive, DSR_Hint->Cluster, DSR_Hint->Index, &DSR);
   }
   else
      D = StartDirSearch(f->Drive, f->DirEntry.DirCluster, 0, &DSR);

   setASCII(pF, 0, '\0');

   SkipMatchSFN = KAL_FALSE;

   // pN[] Generate ShortFileName formats into pTemp[] (Native encoding) and pTemp2[] (Leave it as-is)
   // pTemp[] and pTemp2[] will be compared to the ShortFileName entry found from DIR search loop.
   // If the LFN => SFN convertion lossy, set SkipMatchSFN = KAL_TRUE
   {
      int idx = 0;
      int idx1 = 0, idx2 = 0;
      
      while(idx < 12)
      {
         pTemp[idx] = 0x20;
         pTemp2[idx]= 0x20;
         idx++;
      }
      if ( kal_dchar_strcmp(pN, (char *)dchar_dot_dot) == 0 )
      {
         //strcpy(pTemp, "..         ");
         pTemp[0] = 0x2e;
         pTemp[1] = 0x2e;
         pTemp[11] = 0x0;
         pTemp2[0] = 0x0;
         goto StartRetrieveDIREntry;
      }
      else if ( kal_dchar_strcmp(pN, (char *)dchar_dot) == 0 )
      {
         //strcpy(pTemp, ".          ");
         pTemp[0] = 0x2e;
         pTemp[11] = 0x0;
         pTemp2[0] = 0x0;
         goto StartRetrieveDIREntry;
      }

      //Formal short name algo (Special characters , convert and compare , eg.  1+1 )
      if (GenerateShortName(pN, pTemp) != 0)
      {  // lossy flag detected, raise SkipMatchSFN , But need validate in next bracket 
         // Don't clear pTemp[0] because SkipMatchSFN might revert in next bracket for non-ascii
         SkipMatchSFN = KAL_TRUE;
      }

      //Direct short name algo (API pass previous taken short name, bypass encoding and go through , eq. XYZ~1.TXT )
      {
         idx      = 0; // re-use idx as non-ascii flag
         LFNIndex = 0; // re-use LFNIndex as last dot position
         idx1     = 0; // position to pN[]     (input)
         idx2     = 0; // position to pTemp2[] (output)
         while((idx2 < 11) && ((*(pN + idx1) != NULL) || (*(pN + idx1 + 1) != NULL)))
         {
            if((*(pN + idx1) == 0x5C) && (*(pN + idx1 + 1) == 0x0)) // ascii : back slash
               break;
            if((*(pN + idx1) == 0x2E) && (*(pN + idx1 + 1) == 0x0)) // ascii : dot 
            {
               while(idx2 < 8)
               {
                  pTemp2[idx2] = 0x20;
                  idx2++;
               }
               if (LFNIndex != 0) // dot hit again , 
               {
                  // don't need to compare SFN , pTemp2[0] = 0x0;
                  LFNIndex += idx2;
                  break;
            }
               else               // dot hit once , LFNIndex must be 8 to pass criteria
               {
                  LFNIndex = idx2;
               }
            }
            // for non-ascii characters . Note an example Thai encoding : 0xA8 0x00 0xA8 0x00 ...
            else if( (pN[idx1] & 0x80) || (pN[idx1 + 1] != 0x0))
            {
               idx ++; // raise flag ! non-ascii character detected !
               pTemp2[idx2] = *(pN + idx1);
               pTemp2[idx2 + 1] = *(pN + idx1 + 1);
               idx2 += 2;
            }
            else // others , must be ascii 
            {
               pTemp2[idx2] = *(pN + idx1);
               idx2++;
            }
            idx1+=2;
         }
         // check if pN[] (1) multi-dot  (2) dot at wrong position (3) name length > 8 without any dot detected
         if ( (LFNIndex > 8) || (LFNIndex == 0 && idx2 > 8) )
         {
            // Don't need to compare pTemp2[] string
            pTemp2[0] = 0x0;
         }
         // check if pN[] contain non-ascii characters ?
         else if ( idx != 0 )
         {
            /* Check if pN[] dchar string ended */
            if (  ((*(pN + idx1) == NULL) && (*(pN + idx1 + 1) == NULL))
               || ((*(pN + idx1) == 0x5C) && (*(pN + idx1 + 1) == NULL))
               )
            {
               // invert SkipMatchSFN to compare pTemp2[] string with SFN
               SkipMatchSFN = KAL_FALSE;
               /* 0xE5 special char will be treated as deleted */
               if (pTemp2[0] == 0xE5)
                  pTemp2[0] = 0x05;
            }
            else
            {
               // Don't need to compare pTemp2[] string
               pTemp2[0] = 0x0;
            }
         }
         else
         {
            // it's enough to just compare pTemp[] string with SFN , skip pTemp2[] string
            pTemp2[0] = 0x0;
         }
      }
      pTemp[11]  = 0x00;
      pTemp2[11] = 0x00;
   }


StartRetrieveDIREntry:
   LFNIndex = -1;
   while (D != NULL)
   {
      int Kind = EntryType(D);

      if (Kind == NeverUsed)
         break;  // file not found
      else if (Kind == Lfn)
      {
         const LFNDirEntry * LD = (void*) D;
         if (LD->Ord & 0x40) // it's the start of an LFN
         {
            // see if it fits
            char * Limit;
            LFNIndex = LD->Ord & 0x3F;
            CheckSum = LD->CheckSum;
            f->DirEntry.LongPos = DSR;
            Limit = pF + (LFNIndex-1)*13*2 + 2*LFNCharCount(LD);
            if (Limit > (f->FullName+RTF_MAX_PATH-1) )
               LFNIndex = -1;
            else
            {
               Limit[0] = '\0';  // terminate the long name
               Limit[1] = '\0';
            }
         }
         if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
            LFNIndex = -1;
         else
            CopyLFN(pF + --LFNIndex * 26, LD);
      }
      else if ((Kind == InUse) &&
               (((D->Attributes & ~RTF_ATTR_ARCHIVE) == RTF_ATTR_VOLUME) ==
                ((Flags & SEARCH_LABEL) == SEARCH_LABEL)))
      {
         // check against LFN first
         int Match = (LFNIndex == 0) && (CheckSum == ShortNameCheckSum((const BYTE*) D->FileName));
         int length;

         if (!Match) // the LFN doees not belong to this file
            LFNIndex = -1;
         else
         {
            Match =  WFNamesMatch(pF, pN);
            //Match = (Match==1) ? 1: -1; /* Remove to fix cannot search via unicode short name, Karen Hsu, 2004/03/30 */
         }

         if ( !Match )
         {
            if(SkipMatchSFN) goto SearchContinue;  /* Optimize algo, Karen Hsu, 2004/04/28, ADD */

            /* Copy Short FileName into pF string */
            memcpy(pF, (const char *)D->FileName, 8);
            memcpy(pF + 8, (const char *)D->Extension, 3);
            pF[11]='\0';

            Match = FNamesMatch(pF, pTemp);

            if(!Match)
               Match = FNamesMatch(pF, pTemp2);

            if ( Match )
            {
               if ( kal_dchar_strchr(pN, 0x5c) )
                  length = kal_dchar_strlen(pN) - kal_dchar_strlen(kal_dchar_strchr(pN, 0x5c));
               else
                  length = kal_dchar_strlen(pN);

               kal_dchar_strncpy(pF, pN, length);
            }
         }

         if ( Match==1 )
         {
            if (WFNamesMatch((char *)pN, (char *)dchar_dot_dot) && compASCII(pN, 1, '.') && (FIRST_FILE_CLUSTER(*D) == 0))  // ".." to root?
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
            else
            {
               f->DirEntry.Dir = *D;
               f->DirEntry.ShortPos = DSR;
               if (LFNIndex != 0)
                  f->DirEntry.LongPos.Cluster = 0;
            }

            if (compASCII(pN, 0, '.') && compASCII(pN, 1, '.'))
            {
               setASCII(pF, -1, '\0');
               pF = kal_dchar_strrchr(f->FullName, '\\');
               if (pF == NULL)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, f, (BYTE *)FileName);
#endif
                  XRAISE(RTF_PATH_NOT_FOUND);
               }
               if ((pF - 3*2) < f->FullName)
                  pF += 2;
               setASCII(pF, 0, '\0');
            }
            else
               pF += kal_dchar_strlen(pF);

            pN = kal_dchar_strchr(pN, '\\');
            
            goto NextDir;
         }
      }
SearchContinue: /* Optimize algo, Karen Hsu, 2004/04/28, ADD */
      if (Kind != Lfn)
         LFNIndex = -1;
      D = NextDir(f->Drive, &DSR);
   }

   // deal with pathname end with backslash
   {
      char *pE = kal_dchar_strchr(pN, 0x5C);
      if (pE != NULL)
      {
         if ( (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) && compASCII(pE, 1, 0x0) )
         {
            if ((pF + kal_dchar_strlen(pN)) >= (f->FullName + RTF_MAX_PATH - 1))
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_PATH_OVER_LEN_ERROR, f, (BYTE *)FileName);
#endif
               XRAISE(MT_PATH_OVER_LEN_ERROR);
            }
            kal_dchar_strcpy(pF, pN);
            // remove tail backslash in dest path string
            *(pF + (int) ((int)pE - (int)pN) ) = 0x0;
            return 0;
         }
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, f, (BYTE *)FileName);
#endif
         XRAISE(RTF_PATH_NOT_FOUND);
      }
   }

Return0:

   // path is found, but not the file
   // complete full path name
   if ((pF + kal_dchar_strlen(pN)) >= (f->FullName + RTF_MAX_PATH - 1))
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_PATH_OVER_LEN_ERROR, f, (BYTE *)FileName);
#endif
      /* XRAISE(RTF_INVALID_FILENAME); --- align to (-49) FS_PATH_OVER_LEN_ERROR */
      XRAISE(MT_PATH_OVER_LEN_ERROR);
   }

   kal_dchar_strcpy(pF, pN);

   return 0;
}

/*-----------------------------------*/
void RTFAPI UpdateDirEntry(RTFile * f)
// copy the short dir entry to the buffer cache, commit if required
{
   RTFDOSDirEntry * D;

   if (f->DirEntry.DirCluster == 0) // it's the root
      return;

   D = GetDir(f->Drive, &f->DirEntry.ShortPos);
   if (memcmp((void*)D,(void*) &f->DirEntry.Dir, sizeof(f->DirEntry.Dir)) != 0)
   {
      UINT i;
      RTFile * f1 = gFS_Data.FileTable;

      *D = f->DirEntry.Dir;

      // directories on disk do not have a filesize
      if (D->Attributes & RTF_ATTR_DIR)
         D->FileSize = 0;

      SetDirty(f->Dev);
      if (f->Flags & RTF_COMMITTED)
         CommitBuffer(f->Dev);

      // search for shared files and update their dir entry too
      for (i=0; i<FS_MAX_FILES; i++, f1++)
      {
         if ((f1 != f) && (f1->Dev == f->Dev) && (f1->Drive == f->Drive) && SAME_DIR_ENTRY(f1->DirEntry.ShortPos, f->DirEntry.ShortPos))
         {
            // check the file pointer & file size
            if (f1->Task != f->Task)
            {
               ASSERT(f->DirEntry.Dir.FileSize >= f1->FilePointer);
            }
            // force update the f->cluster value in the boundary case ; See Also MoveFilePointerSegment
            if (f1->Cluster == 0 && f1->LastCluster != 0)
            {
               f1->Cluster = GetClusterValue(f1->Drive, f1->LastCluster);
               if (f1->Cluster >= RTF_CLUSTER_CHAIN_END)
                  f1->Cluster = 0;
            }
            // update the f->Cluster value when first cluster value updated ; WCP_SW 2007/10/08
            else if (f1->Cluster == 0 &&
                     FIRST_FILE_CLUSTER(f1->DirEntry.Dir) == 0 &&
                     FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0
                    )
            {
               f1->Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
            }
            // update the directory entry then
            f1->DirEntry.Dir = f->DirEntry.Dir;
         }
      }

      /* Associate Cache Value Expiration */
#ifndef _LOW_COST_SINGLE_BANK_FLASH_
      MTExpireDirCacheValue(f->Drive, f->DirEntry.DirCluster);
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */
   }
}

/*-----------------------------------*/
static void INTERN CommitDirEntry(RTFile * f)
// commit the short dir entry
{
   RTFSector Sector;

   if (f->DirEntry.DirCluster == 0) // it's the root
      return;

   Sector = CLUSTER_TO_SECTOR_DIR(f->Drive, f->DirEntry.DirCluster);

   if (SearchBuffer(f->Dev, Sector + (f->DirEntry.ShortPos.Index / DIRS_PER_SECTOR(f->Drive))))
      CommitBuffer(f->Dev);
}

/*-----------------------------------*/
static char INTERN GenerateShortChar_ASCII(char c)
{
   c = _rtftoupper(c);
   return IsValidShortNameChar(c) ? c : '_';
}

/*-----------------------------------*/
static int INTERN GenerateShortName(const char * LongName, char * ShortName)
// input is Unicode
// output is combination of ASCII and native code
// ShortName is in DirEntry format
// Validity of ASCII code must be checked, any invalid short file name is coded as '_'
// LossyFlag is used to tracking the necessity to associate an LFN entry 
{
   const char * pN = LongName;
   char       * pF = ShortName;
   int          LossyFlag = 0;
   WCHAR        wide_c;
   char         c;
   const char * pSearch;

   memset(pF, ' ', 8+3);

   // locate the last dot before NULL or backslash 
   for (pSearch  = pN; (pSearch[0]||pSearch[1]) && !(compASCII(pSearch, 0, '\\')) ; pSearch+=2);
   for (pSearch -=  2; (pSearch > pN)           && !(compASCII(pSearch, 0, '.' )) ; pSearch-=2);

   // set pSearch to NULL if dot-begin or dot-not-found
   if (pSearch == pN) { pSearch = NULL; }

   // major file name partion
   while ( (pN[0]||pN[1]) && !(compASCII(pN,0,'\\')) && ((pF-ShortName) < 8) )
   {
      if ( compASCII(pN,0,'.') )
      {
         // break if last dot hit
         // otherwise , set LossyFlag and continue
         if (pN == pSearch)
         {
            break;
         }
         else
         {
            LossyFlag++;
            pN+=2;
            continue;
         }
      }
      if ( isASCII(pN, 0) )
      {
         if ( !(compASCII(pN,0,' ')) )
         {
            c = GenerateShortChar_ASCII(pN[0]);
            LossyFlag += (c == '_') && ( !(compASCII(pN,0,'_')) );
            *pF++ = c;
         }
         else
         {
            LossyFlag++;
         }
      }
      else
      {
         LossyFlag++;

         if ( (pF-ShortName)>=7 )
            break;

         wide_c = UnicodetoNative( *(pN) | (*(pN+1)<<8));
         *pF++ = wide_c>>8;
         *pF++ = wide_c&0xff;
      }
      pN+=2;
   }

   LossyFlag += (pN[0]||pN[1]) && !(compASCII(pN,0,'.') || (compASCII(pN,0,'\\')));

   pN = pSearch; // position to last dot
   pF = ShortName+8;
   if (pN)
   // extension file name partion
   {
      pN+=2;
      while ( (pN[0]||pN[1]) && !(compASCII(pN,0,'\\')) && ((pF-ShortName) < 11) )
      {
         if ( isASCII(pN, 0) )
         {
            if ( !compASCII(pN,0,' ') )
            {
               c = GenerateShortChar_ASCII(pN[0]);
               LossyFlag += (c == '_') && ( !(compASCII(pN,0,'_')) );
               *pF++ = c;
            }
            else
            {
               LossyFlag++;
            }
         }
         else
         {
            LossyFlag++;

            if ( (pF-ShortName)>=10 ) break;

            wide_c = UnicodetoNative(*(pN) | (*(pN+1)<<8));
            *pF++ = wide_c>>8;
            *pF++ = wide_c&0xff;
         }
         pN+=2;
      }

      LossyFlag += (pN[0]||pN[1]) && !(compASCII(pN,0,'\\'));
   }

   // Convert 0xE5 special char (deleted mark) to 0x05
   if (ShortName[0] == 0xE5) ShortName[0] = 0x05;

   // Exit Point
   if (LossyFlag)               return LossyFlag;
   else                         return 0;
}

/*-----------------------------------*/
static void INTERN IncShortName(char * ShortName)
// ShortName is in DirEntry format
// append telda (~) + number
{
   char * p = NULL;
   int    i, j;
   /* Last Revision @ 2008/01/18 */

   // locate last character of major partion
   j = 7;
   while ( ShortName[j]==' ' )
   {
      j--;
   }
   i = j;
   // locate telda(~) position
   while ( j >= 0 )
   {
     if (ShortName[j] == '~')
     {
        p = ShortName + j;
        break;
     }
     j--;
   }
   // telda(~) not found , create one
   if (p == NULL)
   {
      if ( i<6 )
      {
         ShortName[++i] = '~';
         ShortName[++i] = '1';
      }
      else if ((ShortName[5]&0x80 ) && (ShortName[7] == 0x20))
      /* Example: 0xA0 0xA0 0xA0 0xA0 0xA0 ~ 1 0xA0 */
      {
         ShortName[5] = '~';
         ShortName[6] = '1';
      }
      else
      {
         ShortName[6] = '~';
         ShortName[7] = '1';
      }
   }
   // telda(~) found , increment the numeric tail
   else
   {
      // rewind p to tail character of major filename partion
      for ( p=ShortName+i; p>=ShortName; p-- )
      {
         switch (p[0])
         {
            case '~':
               // position at j
               if ( j>2 && p[-2]>0x80 )
               // replace 2 character , copy digits and put space in tail
               {
                  p[-2]='~';
                  p[-1]='1';
                  for ( ; j < 7 ; j++, p++) 
                  {
                     p[0] = p[1];
                  }
                  p[0] = ' ';
               }
               else
               {
               p[0] = '1';
               if (p > ShortName)
                  p[-1] = '~';
               }
               return;
            case '9':
               // digit must carry in and continue to previous digit
               if ( p[1] == ' ' && p<ShortName+7 )
               // there's space in tail, set it to zero and return
               {
                  p[1] = '0';
                  p[0]='0';
                  return;
               }
               // set zero, back one digit
               p[0] = '0';
               break;
            default:
               // others, increament and exit
               if ((p[0] >= '0') && (p[0] < '9'))
                  p[0]++;
               else
                  p[0] = '0';
               return;
         }
      } // for (p=ShortName+i ... ShortName)
   } // if ( ShortName contain telda(~) )
}

/*-----------------------------------*/
static void INTERN CreateNewDirEntry(RTFile * f)
// this function assumes that the long name is available
// a short name is created
// FAT is not committed
// DIR is not committed
// slack dir space is committed
// long name is commited
{
   const char * Name = kal_dchar_strrchr(f->FullName, 0x005c);
   RTFDOSDirEntry * D;
   RTFDirLocation DSR;
   char ShortName[14];
   char ShortName1[26]={0};
   int NeedDirEntries, FreeDirEntries;
   int LossyFlag, i;
   int SpeedupTry_Flag = 0; /* Speed up matching SFN, Karen Hsu, 2005/06/06 */

   /* Associate Cache Value Expiration */
#ifndef _LOW_COST_SINGLE_BANK_FLASH_
   MTExpireDirCacheValue(f->Drive, f->DirEntry.DirCluster);
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */

   if ( Name==0 )
      Name = f->FullName;
   else
      Name += 2;

   if (kal_dchar_strlen(Name) > 510)
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_PATH_OVER_LEN_ERROR, NULL, (BYTE *)Name);
#endif
      XRAISE(MT_PATH_OVER_LEN_ERROR);
   }

   LossyFlag = (GenerateShortName(Name, (char *)f->DirEntry.Dir.FileName) != 0); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   if (LossyFlag)
   {
   /* 0xFFFF is convert fail mark and don't make it as short name character , 2007/12/19 , ADD */
      char *ptr;
      ptr = (char*)f->DirEntry.Dir.FileName;
      for (i=0 ; i<10 ; i++)
      {
         if ( i == 7 /* End of major name component */ ) continue;
         if ( ptr[i] == 0xFF && ptr[i+1] == 0xFF )
         {
            ptr[i] = '#';
            ptr[i+1] = '_';
         }
      }
   /* 0xFFFF is convert fail mark and don't make it as short name character , 2007/12/19 , ADD */
   }

   memset(ShortName, 0, sizeof(ShortName));
   MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);
   for (i=0; i<26; i+=2)
      ShortName1[i] = ShortName[i>>1];
   i = kal_dchar_strcmp(Name, ShortName1);
   // clean file name case indication flags
   f->DirEntry.Dir.NTReserved &= ~(MT_ENUM_LOWERCASE_MARK | MT_ENUM_EXT_LOWERCASE_MARK);
   // short file name case indication
   if (!LossyFlag && (kal_dchar_strlen(Name) < 26))
   {
      int flag_dot = 0, uflag = 0, lflag = 0, j;
      WCHAR *pName = (WCHAR *)Name;
      BYTE NTReserved = f->DirEntry.Dir.NTReserved;
      
      for(j = 0; j < 13; j++)
      {
         if (pName[j] == 0)
         {
            break;
         }
         
         if (pName[j] == dchar_dot[0])
         {
            flag_dot = 1;
            uflag = lflag = 0;
         }
         else if ((pName[j] >= 0x61) && (pName[j] <= 0x7A)) // a-z
         {
            lflag = 1;
            if (flag_dot)
            {
              NTReserved |= MT_ENUM_EXT_LOWERCASE_MARK;
            }
            else
            {
              NTReserved |= MT_ENUM_LOWERCASE_MARK;
            }
         }
         else if ((pName[j] >= 0x41) && (pName[j] <= 0x5A)) // A-Z
         {
            uflag = 1;
         }
         if (uflag && lflag)
         {
            break;
         }
      }
      
      if (!uflag || !lflag)
      {
         f->DirEntry.Dir.NTReserved = NTReserved;
         i = 0;
      }
   }
   if ( LossyFlag || (i != 0) )
      NeedDirEntries = 1 + (kal_dchar_strlen(Name)-2) / 26 + 1;       // need long name
   else
      NeedDirEntries = 1;

#ifdef DEBUG
   if (f->DirEntry.DirCluster == 0)
      RTFSYSErrorExit("CreateNewDirEntry requires dir to be searched", 1);
#endif

   FreeDirEntries =
   f->DirEntry.ShortPos.Cluster = 0;

Retry:
   if (LossyFlag)
   {
      IncShortName((char *)f->DirEntry.Dir.FileName); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
      MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);
   }
SpeedupTry1: /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD */
   LossyFlag = 1;
   D = StartDirSearch(f->Drive, f->DirEntry.DirCluster, 0, &DSR);
SpeedupTry2: /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD */
   while (1)
   {
      int Kind = EntryType(D);

      // accumulate free slots as long as we need them
      if ((f->DirEntry.ShortPos.Cluster == 0) && ((Kind == Available) || (Kind == NeverUsed)))
      {
         FreeDirEntries++;
         if (FreeDirEntries == NeedDirEntries)
         {
            f->DirEntry.ShortPos = DSR;
            if (NeedDirEntries == 1)
               break; // found, no need to check short name clashes
         }
         if (FreeDirEntries == 1)
            f->DirEntry.LongPos = DSR;
      }
      else
         FreeDirEntries = 0;

      if (f->DirEntry.ShortPos.Cluster && (Kind == NeverUsed))
      {
         if (SpeedupTry_Flag)
         {
            SpeedupTry_Flag = 0;
            goto SpeedupTry1;
         }
         else
         {
            break; // done
         }
      }

      // check generated short name clashes
      if (NeedDirEntries > 1)
      {
         // check short name against short name
         if (Kind == InUse)
         {
            char Temp[14];
            memset(Temp, 0, sizeof(Temp));
            MakeShortFileName(D, Temp, 13);
            /* Fix 0x5C always match in multi-language, Karen Hsu, 2005/03/14, ADD START */
            //if (FNamesMatch(ShortName, Temp))
            {
               int i=0;
               char c1 = 0, c2, c0;
               do
               {
                  c0 = c1;
                  c1 = _rtftoupper(ShortName[i]);
                  c2 = _rtftoupper(Temp[i]);
                  i++;
               } while ((c1 || c0) && (c1 == c2)); // for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...

               if (c1 == c2)
               {
                  /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD START */
                  if (LossyFlag)
                  {
                     IncShortName((char *)f->DirEntry.Dir.FileName);
                     MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);
                     D = NextDir(f->Drive, &DSR);
                     if (D == NULL)
                     {
                        goto SpeedupTry3;
                     }
                     if (EntryType(D) == Lfn)
                     {
                        D = NextDir(f->Drive, &DSR);
                        if (D == NULL)
                        {
                           goto SpeedupTry3;
                        }
                     }
                     SpeedupTry_Flag = 1;
                     goto SpeedupTry2; //compare next directly
                  }
                  /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD END */
                  goto Retry;
            }
               /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD START */
/*
               else if (SpeedupTry_Flag) //compare with previous
               {
                  SpeedupTry_Flag = 0;
                  goto SpeedupTry1;
               }
*/
               /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD END */
            }
            /* Fix 0x5C always match in multi-language, Karen Hsu, 2005/03/14, ADD END */
         }
         else if ((Kind == Lfn) && (D->FileName[0] == 0x41)) // Check LD->Ord to check short name against long name
         {
            char Temp[28];
            const LFNDirEntry * LD = (void*) D;
            memset(Temp, 0, sizeof(Temp)); // zero terminate Temp
            CopyLFN_toShort(Temp, LD);
            /* Fix 0x5C always match in multi-language, Karen Hsu, 2005/03/14, ADD START */
            //if (FNamesMatch(ShortName, Temp))
            {
               int i=0;
               char c1 = 0, c2, c0;
               do
               {
                  c0 = c1;
                  c1 = _rtftoupper(ShortName[i]);
                  c2 = _rtftoupper(Temp[i]);
                  i++;
               } while ((c1 || c0) && (c1 == c2)); // for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...

               if (c1 == c2)
                     goto Retry;
            }
            /* Fix 0x5C always match in multi-language, Karen Hsu, 2005/03/14, ADD END */
         }
      }
      D = NextDir(f->Drive, &DSR);
SpeedupTry3: /* Speed up matching SFN, Karen Hsu, 2005/06/06, ADD */
      if (D == NULL) // try to extend directory, if required
      {
         RTFCluster NextCluster;
         RTFSector Sector;
         UINT i;

         if (f->DirEntry.ShortPos.Cluster)
            break; // same as NeverUsed, done

         if (DSR.Cluster == RTF_ROOT_DIR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ROOT_DIR_FULL, f, NULL);
#endif
            XRAISE(RTF_ROOT_DIR_FULL);
         }

         NextCluster = DSR.Cluster + 1;
         AllocateFATSegment(f->Drive, &NextCluster, 1, f);
         SetClusterValue(f->Drive, DSR.Cluster, NextCluster);

         // clear new directory cluster
         Sector = CLUSTER_TO_SECTOR(f->Drive, NextCluster);
         for (i=0; i<f->Drive->SectorsPerCluster; i++)
         {
            void * DTemp = GetBuffer(f->Dev, Sector + i, NO_LOAD);
            memset(DTemp, 0, f->Dev->DevData.SectorSize);
            SetDirty(f->Dev);
            if (i > 0)
            {
               CommitBuffer(f->Dev);
               DiscardBuffer(f->Dev);
            }
         }
         D = StartDirSearch(f->Drive, NextCluster, 0, &DSR);
      }
   }

   // write the short dir entry
   D = GetDir(f->Drive, &f->DirEntry.ShortPos);
   *D = f->DirEntry.Dir;
   SetDirty(f->Dev);

   // write the long file name dir entry
   if (NeedDirEntries > 1)
   {
      BYTE CheckSum        = ShortNameCheckSum((const BYTE*) f->DirEntry.Dir.FileName);
      int LFNIndex         = NeedDirEntries - 1;
      RTFSector SDirSector = f->Dev->DevData.B->Sector;
      LFNDirEntry * LD     = (LFNDirEntry *) StartDirSearch(f->Drive, f->DirEntry.LongPos.Cluster, f->DirEntry.LongPos.Index, &DSR);
      RTFSector LDirSector = f->Dev->DevData.B->Sector;

      while (1)
      {
         UINT i;
         const char * N = Name + (LFNIndex - 1) * 13 * 2;

         memset((void*)LD, 0xFF, sizeof(*LD));
         LD->Ord          = LFNIndex | ((LFNIndex == (NeedDirEntries-1)) ? 0x40 : 0);
         LD->Attributes   = RTF_LONGNAME_ATTR;
         LD->Type         = 0;
         LD->CheckSum     = CheckSum;
         LD->FirstCluster = 0;

         for (i=0; i<13; i++)
         {
            if(i < 5)
            {
               LD->Name1[i] = *(WORD *)N;
            }
            else if(i < 11)
            {
               LD->Name2[i-5] = *(WORD *)N;
            }
            else
            {
               LD->Name3[i-11] = *(WORD *)N;
            }

            if ( *(WORD *)N==0 )
               break;
            N+=2;
         }
         SetDirty(f->Dev);
         if (--LFNIndex == 0)
            break;
         LD = (LFNDirEntry *) NextDir(f->Drive, &DSR);
      }
      // must commit long file name?
      // we assume that a long file name will never span more than two sectors
      if ((SDirSector != LDirSector) && SearchBuffer(f->Dev, LDirSector))
         CommitBuffer(f->Dev);
   }
   else
      f->DirEntry.LongPos.Cluster = 0;
   f->DirEntry.DirCluster = f->DirEntry.ShortPos.Cluster; /* Fix new entry cross cluster cannot be committed, Karen Hsu, 2004/04/16, ADD */
}


/*-----------------------------------*/
static RTFDOSDirEntry * INTERN DelLongDirEntry(RTFDrive * Drive, RTFDirLocation * LongPos, const RTFDirLocation * Pos)
{
   RTFDOSDirEntry * D = GetDir(Drive, LongPos);

   while (!SAME_DIR_ENTRY(*LongPos, *Pos))
   {
      D->FileName[0] = RTF_DELETED;
      SetDirty(Drive->Dev);
      D = NextDir(Drive, LongPos);
   }
   LongPos->Cluster = 0;
   return D;
}

/*-----------------------------------*/
void RTFAPI DelDirEntry(RTFDrive * Drive, RTFDirLocation * LongPos, const RTFDirLocation * Pos)
//static void INTERN DelDirEntry(RTFDrive * Drive, RTFDirLocation * LongPos, const RTFDirLocation * Pos)
{
   RTFDOSDirEntry * D;

   if (LongPos->Cluster)
      D = DelLongDirEntry(Drive, LongPos, Pos);
   else
      D = GetDir(Drive, Pos);
   D->FileName[0] = RTF_DELETED;
   SetDirty(Drive->Dev);
}

/*-----------------------------------*/
void RTFAPI DeleteDirEntry(RTFile * f)
{
   DelDirEntry(f->Drive, &f->DirEntry.LongPos, &f->DirEntry.ShortPos);
   /* Associate Cache Value Expiration */
#ifndef _LOW_COST_SINGLE_BANK_FLASH_
   MTExpireDirCacheValue(f->Drive, f->DirEntry.DirCluster);
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */
   if (f->Flags & RTF_COMMITTED)
      CommitBuffer(f->Dev);
}

/*-----------------------------------*/
int RTFAPI RTFCreateDir(const WCHAR * DirName)
{
   RTFile * volatile f = NULL;
   RTFDOSDirEntry * D;
   RTFSector Sector;
   RTFCluster ParentDirFirstCluster;
   UINT i;

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);

         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD END */

         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (SearchFile(f, SEARCH_FILES, (char *)DirName, NULL))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_EXISTS, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_FILE_EXISTS);
         }

         CheckValidFileName((WCHAR *)f->FullName);

         ParentDirFirstCluster = f->DirEntry.DirCluster;

         memset((void*)&f->DirEntry.Dir, 0, sizeof(f->DirEntry.Dir));
         f->DirEntry.Dir.Attributes = RTF_ATTR_DIR;
         RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
         f->DirEntry.Dir.CreateDateTime = f->DirEntry.Dir.DateTime;

         /* Fix root dir full but disk free space shrink, Karen Hsu, 2005/06/21, MOD START */
         if (f->Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
         {
            f->Drive->FreeClusterCount = 0;
            f->Drive->ClusterWatermark = RTF_INVALID_CLUSTER;

            BatchCountFreeClusters(f->Drive);
         }
         if (f->Drive->FreeClusterCount < 1)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DISK_FULL, f, NULL);
#endif
            XRAISE(RTF_DISK_FULL);
         }
         CreateNewDirEntry(f);
         /* Dir clusters may be not enough, and needed to be extended: avoid generating a bad directory entry */
         if (f->Drive->FreeClusterCount < 1)
         {
            DeleteDirEntry(f);
            CommitBuffer(f->Dev);
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DISK_FULL, f, NULL);
#endif
            XRAISE(RTF_DISK_FULL);
         }
         // allocate a cluster
         AllocateFATSegment(f->Drive, &f->Cluster, 1, f);
         SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->Cluster);
         UpdateDirEntry(f);
         //CreateNewDirEntry(f);
         /* Fix root dir full but disk free space shrink, Karen Hsu, 2005/06/21, MOD END */

         // clear sectors after the first sector
         Sector = CLUSTER_TO_SECTOR(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir));
         for (i=1; i<f->Drive->SectorsPerCluster; i++)
         {
            D = GetBuffer(f->Dev, Sector + i, NO_LOAD);
            memset((void*)D, 0, f->Dev->DevData.SectorSize);
            SetDirty(f->Dev);
            CommitBuffer(f->Dev);
            DiscardBuffer(f->Dev);
         }

         // write the first sector of the directory and leave the buffer in the cache
         D = GetBuffer(f->Dev, Sector, NO_LOAD);
         memset((void*)D, 0, f->Dev->DevData.SectorSize);
         D[0] = f->DirEntry.Dir;
         memset((char*)D->FileName, ' ', 8+3);
         D->FileName[0] = '.';
         D[1] = D[0];
         D[1].FileName[1] = '.';
         if (((f->Drive->FATType == 32) && (ParentDirFirstCluster == f->Drive->FirstDirSector)) ||
             (f->DirEntry.DirCluster == RTF_ROOT_DIR))
            SET_FIRST_FILE_CLUSTER(D[1], 0); // back link to root are zero
         else
            SET_FIRST_FILE_CLUSTER(D[1], ParentDirFirstCluster);
         SetDirty(f->Dev);
         if ((FileCount(f->Dev) <= 1) || ((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0))
            FlushAllBuffers(f->Dev);
         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSetVolumeLabel(const WCHAR * DriveName, const WCHAR * Label)
{
   RTFile * volatile f = NULL;
   RTFDOSDirEntry * D;
   RTFDirLocation DSR;
   BYTE CheckSum = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   int LFNIndex = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */

   XTRY
      case XCODE:

         f = ParseFileName((char *)DriveName);
         if (f->Drive == NULL)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)DriveName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }
         if (f->Drive->MountState < HasFileSystem)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, f, (BYTE *)DriveName);
#endif
            XRAISE(RTF_INVALID_FILE_SYSTEM);
         }

         if (Label)
            CheckValidFileName(Label);

         // search and delete any old label
         MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
         f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         D = StartDirSearch(f->Drive, f->DirEntry.DirCluster, 0, &DSR);
         while (D != NULL)
         {
            int Kind = EntryType(D);
            if (Kind == NeverUsed)
               break;
            else if (Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;
                  f->DirEntry.LongPos = DSR;
               }
               if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
                  LFNIndex = -1;
               else
                  LFNIndex--;
            }
            else if ((Kind == InUse) && ((D->Attributes & ~RTF_ATTR_ARCHIVE) == RTF_ATTR_VOLUME))
            {
               if ((LFNIndex != 0) || (CheckSum != ShortNameCheckSum((BYTE*) D->FileName)))
                  LFNIndex = -1;

               f->DirEntry.Dir = *D;
               f->DirEntry.ShortPos = DSR;
               if (LFNIndex != 0)
                  f->DirEntry.LongPos.Cluster = 0;
               break;
            }
            if (Kind != Lfn)
               LFNIndex = -1;
            D = NextDir(f->Drive, &DSR);
         }

         // get rid of it
         if (f->DirEntry.ShortPos.Cluster)
            DeleteDirEntry(f);

         // install new one
         if (Label)
         {
            setASCII(f->FullName, 0, 'X');
            setASCII(f->FullName, 1, ':');
            setASCII(f->FullName, 2, '\\');
            kal_dchar_strcat(f->FullName, (char *)Label);
            f->FullName[0] = MT_BASE_DRIVE_LETTER + f->Drive - gFS_Data.DriveTable;

            memset((void*)&f->DirEntry.Dir, 0, sizeof(f->DirEntry.Dir));
            f->DirEntry.Dir.Attributes = RTF_ATTR_VOLUME;
            RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
            f->DirEntry.Dir.CreateDateTime = f->DirEntry.Dir.DateTime;
            CreateNewDirEntry(f);
         }

         // update boot record
         {
            RTFBootRecord * BR = GetBuffer(f->Dev, f->Drive->FirstSector, 0);
            RTFExtendedBIOSParameter * EBPB = (f->Drive->FATType == 32) ? &BR->BP.E._32.BPB : &BR->BP.E._16.BPB;
            memcpy((char*)EBPB->Label, Label ? (char*)f->DirEntry.Dir.FileName : "NO NAME    ", 11);
            SetDirty(f->Dev);
         }

         if ((FileCount(f->Dev) <= 1) || ((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0))
            FlushAllBuffers(f->Dev);

         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
RTFHANDLE RTFAPI RTFReopen(const WCHAR * FileName, DWORD Flags, RTFHANDLE File)
{
   RTFHANDLE volatile handle;
   int volatile result;

   result = RTFSoftClose(File);

   if (result < RTF_NO_ERROR)
   {
      UINT i = File & ((1 << (4*sizeof(int))) - 1);
      RTFile * f;

      if (i >= FS_MAX_FILES)
         return RTF_INVALID_FILE_HANDLE;
      f = gFS_Data.FileTable + i;

      FreeFTSlotAndDevice(f);
      return result;
   }

   handle = RTFOpenFile(FileName, Flags, File, 0);

   return handle;
}

/*-----------------------------------*/
RTFHANDLE RTFAPI RTFOpen(const WCHAR * FileName, DWORD Flags)
{
   return RTFOpenFile(FileName, Flags, NULL, NULL);
}

RTFHANDLE RTFAPI RTFOpenHint(const WCHAR * FileName, DWORD Flags, RTFDirLocation * DSR_Hint)
{
   int volatile Result;

   Result = RTFOpenFile(FileName, Flags, NULL, DSR_Hint);

   if (Result == RTF_FILE_NOT_FOUND) /* if not found, try again w/o hint */
   {
      DSR_Hint->Cluster = 0;
      DSR_Hint->Index   = 0;
      Result = RTFOpenFile(FileName, Flags, NULL, NULL);
   }

   return Result;
}

/*-----------------------------------*/
RTFHANDLE RTFAPI RTFOpenFile(const WCHAR * FileName, DWORD Flags, RTFHANDLE File, RTFDirLocation * DSR_Hint)
{
   int volatile Result;
   RTFile * volatile f = NULL;

   if (Flags & RTF_OPEN_DIR)
      Flags &= ~RTF_OPEN_NO_DIR;

   XTRY
      case XCODE:
         // check for invalid flag combinations
         if (Flags & RTF_CREATE_ALWAYS)
         {
            if (Flags & (RTF_READ_ONLY | RTF_ATTR_READ_ONLY))
               /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, NULL, (BYTE *)FileName);
#endif
               XRAISE(MT_READ_ONLY_ERROR);
               //XRAISE(RTF_PARAM_ERROR);
            }
               /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */
            if (Flags & (RTF_ATTR_DIR | RTF_ATTR_VOLUME))
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, NULL, (BYTE *)FileName);
#endif
               XRAISE(RTF_PARAM_ERROR);
            }
         }

         if ((Flags & FS_PROTECTION_MODE) && (Flags & FS_NONBLOCK_MODE))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ATTR_CONFLICT, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_ATTR_CONFLICT); // Can't specify FS_PROTECTION_MODE and FS_NONBLOCK_MODE
         }

         if (Flags & RTF_COMMITTED)
            Flags &= ~RTF_LAZY_DATA;

         if (Flags & RTF_LAZY_DATA)
            Flags |= RTF_CACHE_DATA;

         if (File)
           f = ParseFileName1((char *)FileName, File);
         else
           f = ParseFileName((char *)FileName);

/* FileMapFile open, MTK_WCP_SW , 2005/08/21, ADD START */
         if (f->SpecialKind == FileMapFile)
         {  
            /* Flags has inherited from LargeFile already 
             * ==> Change to force OR RTF_OPEN_SHARED flag, 2006/08/07, MOD
             */
            if ( (Flags & (RTF_READ_ONLY) ) != (RTF_READ_ONLY) )
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, f, NULL);
#endif
               XRAISE(RTF_ACCESS_DENIED);
            }
            f->Flags = Flags | RTF_OPEN_SHARED; /* 2006/08/07 ADD */
         }
         else
         {  
            f->Flags = Flags;
         }
/* FileMapFile open, MTK_WCP_SW , 2005/08/21, ADD END */

         if (f->SpecialKind != NormalFile)
         {
            /* check special kind file handle concurrency , 2006/10/21, ADD START */
            MTCheckSharingWithSpecialKindFh(f);
            /* check special kind file handle concurrency , 2006/10/21, ADD END   */
            Result = MakeNewFileHandle(f);
            break;
         }

         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if ((Flags & RTF_CREATE_ALWAYS) || ((Flags & RTF_READ_ONLY) == 0))
         {
            if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)FileName);
#endif
               XRAISE(RTF_WRITE_PROTECTION);
            }
         }
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD END */

         if (SearchFile(f, SEARCH_FILES, (char *)FileName, DSR_Hint)) // it does exist
         {
            CheckSharing(f);
            if (Flags & RTF_CREATE_ALWAYS)
            {
               // delete it
               if (f->DirEntry.Dir.Attributes & (RTF_ATTR_READ_ONLY | RTF_ATTR_DIR | RTF_ATTR_VOLUME))
                  /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, NULL, (BYTE *)FileName);
#endif
                  XRAISE(MT_READ_ONLY_ERROR);
                  //XRAISE(RTF_ACCESS_DENIED);
               }
                  /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

               if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0)
               {
                  //quota
                  FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), f);
                  //FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir));
                  if (Flags & RTF_COMMITTED)
                     FlushFAT(f->Dev);
                  SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, 0);
               }
               f->DirEntry.Dir.Attributes = Flags & RTF_ATTR_ANY;
               if (f->DirEntry.Dir.FileSize != 0)
               {
                  RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
                  f->DirEntry.Dir.FileSize = 0;
               }
               UpdateDirEntry(f);
            }
            else // open an existing file
            {
               if ((f->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY) && ((Flags & RTF_READ_ONLY) == 0))
                  /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, NULL, (BYTE *)FileName);
#endif
                  XRAISE(MT_READ_ONLY_ERROR);
                  //XRAISE(RTF_ACCESS_DENIED);
               }
                  /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

               if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) && ((Flags & RTF_OPEN_NO_DIR) || ((Flags & RTF_READ_ONLY) == 0)))
                  /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, NULL, (BYTE *)FileName);
#endif
                  XRAISE(MT_READ_ONLY_ERROR);
                  //XRAISE(RTF_ACCESS_DENIED);
               }
                  /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

               InitFilePointer(f);

               if (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
               {
                  if (f->Cluster == RTF_ROOT_DIR)
                     f->DirEntry.Dir.FileSize = f->Drive->RootDirEntries * sizeof(RTFDOSDirEntry);
                  else
                     f->DirEntry.Dir.FileSize = FATClusterChainLength(f->Drive, f->Cluster, NULL) << f->Drive->ClusterShift;
               }
            }
         }
         else // it does not exist
         {
            if (Flags & (RTF_CREATE_ALWAYS | RTF_CREATE))
            {
               /* Fix write protect issue, Karen Hsu, 2004/09/14, ADD START */
               if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)FileName);
#endif
                  XRAISE(RTF_WRITE_PROTECTION);
               }
               /* Fix write protect issue, Karen Hsu, 2004/09/14, ADD END */

               if (Flags & RTF_READ_ONLY)
                  /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, NULL, (BYTE *)FileName);
#endif
                  XRAISE(MT_READ_ONLY_ERROR);
                  //XRAISE(RTF_ACCESS_DENIED);
               }
                  /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

               /* check special kind file handle concurrency , 2006/10/21, ADD START */
               MTCheckSharingWithSpecialKindFh(f);
               /* check special kind file handle concurrency , 2006/10/21, ADD END   */

               CheckValidFileName((WCHAR *)f->FullName);
               memset((void*)&f->DirEntry.Dir, 0, sizeof(f->DirEntry.Dir));
               f->DirEntry.Dir.Attributes = Flags & RTF_ATTR_ANY;
               RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
               f->DirEntry.Dir.CreateDateTime = f->DirEntry.Dir.DateTime;
               CreateNewDirEntry(f);
               if (Flags & RTF_COMMITTED)
               {
                  CommitDirEntry(f);
                  FlushFAT(f->Dev);
               }
            }
            else
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_NOT_FOUND, NULL, (BYTE *)FileName);
#endif
               XRAISE(RTF_FILE_NOT_FOUND);
            }
         }
         InitFilePointer(f);

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f)
         {
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
         }
         break;
   XEND_API
   return Result;
}

/*-----------------------------------*/
/* FIXME: This Function doesn't referenced by any public API */
int RTFAPI RTFMakeTempFileName(const WCHAR * DirName, WCHAR * FileName, UINT MaxLength)
{
   RTFile * volatile f = NULL;
   RTFDirLocation DSR;
   RTFDOSDirEntry * D;
   char ShortName[13];
   DWORD TimeStamp;
   WCHAR tempFileName[]={0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x2e,0x54,0x4d,0x50,0x00};

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);
         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_PATH_NOT_FOUND);
         }

         if (!SearchFile(f, SEARCH_FILES, (char *)DirName, NULL)) // it does exist
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_PATH_NOT_FOUND);
         }

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_PATH_NOT_FOUND);
         }

         // create a unique name
         GenerateShortName((char *)tempFileName, (char *)f->DirEntry.Dir.FileName); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
         RTFSYSGetDateTime((void*) &TimeStamp);
Retry:
         ToHexString((char *)f->DirEntry.Dir.FileName, TimeStamp); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
         MakeShortFileName(&f->DirEntry.Dir, ShortName, 13);

         D = StartDirSearch(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), 0, &DSR);
         while (D != NULL)
         {
            int Kind = EntryType(D);
            if (Kind == InUse)
            {
               char Temp[14];
               MakeShortFileName(D, Temp, 13);
               if (FNamesMatch(ShortName, Temp))
               {
                  TimeStamp++;
                  goto Retry;
               }
            }
            else if ((Kind == Lfn) && (D->FileName[0] == 0x41)) // Check LD->Ord to check short name against long name
            {
               char Temp[26];
               const LFNDirEntry * LD = (void*) D;
               memset(Temp, 0, sizeof(Temp)); // zero terminate Temp
               CopyLFN_toShort(Temp, LD);
               if (FNamesMatch(ShortName, Temp))
               {
                  TimeStamp++;
                  goto Retry;
               }
            }
            else if (Kind == NeverUsed)
               break;
            D = NextDir(f->Drive, &DSR);
         }

         // when we are here, the name is unique
         if ( (f->FullName[kal_dchar_strlen(f->FullName)-2] != 0x5c) )
            setASCII(f->FullName, kal_dchar_strlen(f->FullName)>>1, '\\');
         kal_dchar_strcat(f->FullName, ShortName);

         if (MaxLength <= kal_dchar_strlen(f->FullName))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_STRING_BUFFER_TOO_SMALL, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }

         kal_dchar_strcpy((char *)FileName, f->FullName);

         f->DirEntry.DirCluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         memset((void*)&f->DirEntry.Dir, 0, sizeof(f->DirEntry.Dir));
         RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
         f->DirEntry.Dir.CreateDateTime = f->DirEntry.Dir.DateTime;
         CreateNewDirEntry(f);

         if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
            FlushAllBuffers(f->Dev);

         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFDelete(const WCHAR * FileName)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD END */

         f->Flags = RTF_READ_WRITE;

         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (!SearchFile(f, SEARCH_FILES, (char *)FileName, NULL))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_NOT_FOUND, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_FILE_NOT_FOUND);
         }

         CheckNotOpen(f);

         if (f->DirEntry.Dir.Attributes & (RTF_ATTR_READ_ONLY | RTF_ATTR_DIR | RTF_ATTR_VOLUME))
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, NULL, (BYTE *)FileName);
#endif
            XRAISE(MT_READ_ONLY_ERROR);
            //XRAISE(RTF_ACCESS_DENIED);
         }
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

         DeleteDirEntry(f);

         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0)
         //quota
         {
            FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), f);
            //FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir));
         }

         if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
            FlushAllBuffers(f->Dev);

         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
static int INTERN PathContains(RTFDrive * Drive, RTFCluster StartCluster, const RTFCluster Cluster)
{
   RTFDirLocation DSR;
   const RTFDOSDirEntry * D;

   while (1)
   {
      if (StartCluster == Cluster)
         return 1; // clash
      D = StartDirSearch(Drive, StartCluster, 1, &DSR); // second entry should be ".."
      if ((EntryType(D) == InUse) && (memcmp((char*)D->FileName, ".. ", 3) == 0))
      {
         StartCluster = FIRST_FILE_CLUSTER(*D);
         if (StartCluster == 0)
            return 0;  // back to root
      }
      else
         return 0; // we are in the root
   }
}

/*-----------------------------------*/
static int INTERN MTCheckPathOpen(RTFile * File)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   for (i=0; i<FS_MAX_FILES; i++, f++)
      if ((f != File) &&
          (f->Drive == File->Drive) &&
          PathContains(f->Drive, f->DirEntry.DirCluster, FIRST_FILE_CLUSTER(File->DirEntry.Dir)))
         return 1;
      
   return 0;
}

/*-----------------------------------*/
int RTFAPI RTFRename(const WCHAR * FileName, const WCHAR * NewName)
{
   RTFile * volatile f1 = NULL;
   RTFile * volatile f2 = NULL;
   int volatile rename_state = 0; /* Fix disk full will make both two files gone, Karen Hsu, 2004/10/27, ADD */

   XTRY
      case XCODE:
         f1 = ParseFileName((char *)FileName);
         UnlockDevice(f1->Dev);

         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if(f1->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD END */

         if (f1->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         f2 = ParseFileName((char *)NewName);

         if (f2->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)NewName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (f1->Drive != f2->Drive)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "Drive1 ptr: 0x%x, Drive2 ptr: 0x%x", (DWORD)f1->Drive, (DWORD)f2->Drive);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }

         if (!SearchFile(f1, SEARCH_FILES, (char *)FileName, NULL))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_NOT_FOUND, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_FILE_NOT_FOUND);
         }

         if (SearchFile(f2, SEARCH_FILES, (char *)NewName, NULL) != 0)
         {
            CheckValidFileName((WCHAR*)f2->FullName); /* Fix ended with dot, Karen Hsu, 2004/05/26, ADD*/
            if (SAME_DIR_ENTRY(f1->DirEntry.ShortPos, f2->DirEntry.ShortPos))
            /* For capital sensitive, Karen Hsu, 2004/07/07, MOD START */
            {
               if(kal_dchar_strcmp((char*)FileName, (char*)NewName) != 0)
               {
                  WCHAR *pFullName;
                  const WCHAR *pNewName;

                  // locate pFullName at <tail - 1>
                  for (pFullName = (WCHAR*)f2->FullName;
                       *pFullName != 0x0000;
                       pFullName++
                      );
                  pFullName--;

                  // locate pNewName at <tail - 1>
                  for (pNewName = NewName;
                       *pNewName != 0x0000;
                       pNewName++
                      );
                  pNewName--;

                  // shift if pNewName contain backslash tail
                  if (*pNewName == 0x005C)
                  {
                     pNewName--;
                  }

                  // copy pNewName to pFullName in reverse order
                  for ( ;
                        (*pFullName != 0x005C) && (*pNewName != 0x005C);
                        pFullName-- , pNewName--
                      )
                  {
                     *pFullName = *pNewName;
                  }

                  // Make sure Name Segment length equalience to NewName
                  if (*pFullName != *pNewName)
                  {
                  // fall through and do nothing
                  }
                  else
                  {
                  CheckNotOpen2(f1, f2);
                  goto RenameContinue;
               }
               }
               break; // do nothing
            }
            /* For capital sensitive, Karen Hsu, 2004/07/07, MOD END */
            else
               /* Avoid to confuse user, Karen Hsu, 2004/04/22, MOD START */
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_EXISTS, NULL, (BYTE *)NewName);
#endif
               XRAISE(RTF_FILE_EXISTS);
               //XRAISE(RTF_ACCESS_DENIED);
            }
               /* Avoid to confuse user, Karen Hsu, 2004/04/22, MOD END */
       }
       else
       {
          // do not use the field NTReserved of the parent folder
          f2->DirEntry.Dir.NTReserved = 0;
       }
         CheckValidFileName((WCHAR*)f2->FullName);

         CheckNotOpen(f1);

         if ((f1->DirEntry.Dir.Attributes & RTF_ATTR_DIR) &&
              // do not rename a directory if there is a child file/directory opened
             (MTCheckPathOpen(f1) ||
              // do not move the a component of the current directory
             PathContains(f1->Drive, FIRST_FILE_CLUSTER(f1->Drive->CurrDirEntry.Dir), FIRST_FILE_CLUSTER(f1->DirEntry.Dir)) ||
              // do not move f1 to it's own child
              PathContains(f1->Drive, f2->DirEntry.DirCluster, FIRST_FILE_CLUSTER(f1->DirEntry.Dir))))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)NewName);
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }

RenameContinue:
         // do it
         DeleteDirEntry(f1);
         rename_state = 1;  /* Fix disk full will make both two files gone, Karen Hsu, 2004/10/27, ADD */
         CreateNewDirEntry(f2);
         rename_state = 2;  /* Fix disk full will make both two files gone, Karen Hsu, 2004/10/27, ADD */

         // copy directory information except name/ext over
         // reserve NTReserved for file name case indicator
         memcpy((char*)f2->DirEntry.Dir.FileName + 8 + 3 + 2,
                (char*)f1->DirEntry.Dir.FileName + 8 + 3 + 2,
                        sizeof(f2->DirEntry.Dir) - 8 - 3 - 2);
         f2->DirEntry.Dir.Attributes = f1->DirEntry.Dir.Attributes;

         // commit
         {
            RTFDOSDirEntry * D = GetDir(f2->Drive, &f2->DirEntry.ShortPos);
            *D = f2->DirEntry.Dir;
            SetDirty(f2->Dev);
         }

         // if we moved a dir, then we must adjust the .. entry
         if (f2->DirEntry.Dir.Attributes & RTF_ATTR_DIR)
         {
            RTFDOSDirEntry * D = GetBuffer(f2->Dev, CLUSTER_TO_SECTOR(f2->Drive, FIRST_FILE_CLUSTER(f2->DirEntry.Dir)), 0);
            RTFCluster NewParentCluster = f2->DirEntry.DirCluster;

            if ((NewParentCluster == RTF_ROOT_DIR) ||
                ((f2->Drive->FATType == RTFAT32) &&
                 (NewParentCluster == f2->Drive->FirstDirSector)))
            {
               NewParentCluster = 0;
            }

            if (FIRST_FILE_CLUSTER(D[1]) != NewParentCluster)
            {
               SET_FIRST_FILE_CLUSTER(D[1], NewParentCluster);
               SetDirty(f2->Dev);
            }
         }

         if (((f2->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f2->Dev) <= 2))
            FlushAllBuffers(f2->Dev);
         break;
      default:
         break;
      case XFINALLY:
         if (f1)
         {
            /* Fix disk full will make both two files gone, Karen Hsu, 2004/10/27, ADD START */
            if(rename_state == 1)
            {
               CreateNewDirEntry(f1);
               if (((f1->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f1->Dev) <= 2))
                  FlushAllBuffers(f1->Dev);
            }
            /* Fix disk full will make both two files gone, Karen Hsu, 2004/10/27, ADD END */
            FreeFTSlot(f1); // device is unlocked already, see above
         }
         if (f2) FreeFTSlotAndDevice(f2);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetAttributes(const WCHAR * FileName)
{
   int volatile Result;
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         CheckValidFileName2(FileName, KAL_FALSE);
         f = ParseFileName((char *)FileName);

         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (SearchFile(f, SEARCH_FILES, (char *)FileName, NULL))
            Result = f->DirEntry.Dir.Attributes;
         else
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_NOT_FOUND, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_FILE_NOT_FOUND);
         }

         break;

      default:
         break;

      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFSetAttributes(const WCHAR * FileName, BYTE Attributes)
{
   RTFile * volatile f = NULL;

   Attributes &= RTF_ATTR_ANY;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);

         /* Fix write protect issue, Karen Hsu, 2004/09/15, ADD START */
         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/09/15, ADD END */

         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (!SearchFile(f, SEARCH_FILES, (char *)FileName, NULL))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_NOT_FOUND, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_FILE_NOT_FOUND);
         }

         if (f->DirEntry.Dir.Attributes != Attributes)
         {
            // if it's a root dir, just return now
            if (f->DirEntry.DirCluster == 0)    // it's a root dir
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)FileName);
#endif
               XRAISE(RTF_ACCESS_DENIED);
            }

            // volume labels are not allowed
            // dir is not allowed
            if ((f->DirEntry.Dir.Attributes ^ Attributes) & (RTF_ATTR_DIR | RTF_ATTR_VOLUME))
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)FileName);
#endif
               XRAISE(RTF_ACCESS_DENIED);
            }

            f->DirEntry.Dir.Attributes = Attributes;

            f->Flags |= RTF_COMMITTED;

            UpdateDirEntry(f);

            if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
               FlushAllBuffers(f->Dev);

         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFExpandName(WCHAR * FileName, UINT MaxLength)
{
   RTFile * volatile f = NULL;
   const char * pN = (char *)FileName;
   const char * pN2;
   char * pF;
   int l;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);
         pF = f->FullName;

         if ( compASCII(pN, 1, ':') )
            pN += 4;

         kal_dchar_strcpy(pF, f->Drive->CurrDir);

         // if the next char is a "\", we have an abs path
         if ( compASCII(pN, 0, '\\'))
         {
            pN+=2;
            pF+=6;
            setASCII(pF,0,'\0');
         }
         else // it's a relative path
            pF+=kal_dchar_strlen(pF);

         while (pN)
         {
            // skip any "." and multiple "\"
            while ( (WFNamesMatch(pN, (char *)dchar_dot)) || (compASCII(pN,0,'\\')) )
               pN+=2;

            if ( compASCII(pN,0,0) ) //found
               break;

            if ( !compASCII(pF,-1,'\\') )
            {
               setASCII(pF,0,'\\');
               pF++;
            }

            pN2 = kal_dchar_strchr(pN, '\\');
            if ( WFNamesMatch(pN, (char *)dchar_dot_dot))
            {
               setASCII(pF,-1,'\0');
               pF = kal_dchar_strrchr(f->FullName, '\\');
               if (pF == NULL)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)FileName);
#endif
                  XRAISE(RTF_PATH_NOT_FOUND);
               }
               if ((pF-6) < f->FullName)
                  pF+=2;
               setASCII(pF,0,'\0');
            }
            else
            {
               if (pN2)
                  l = pN2 - pN;
               else
                  l = kal_dchar_strlen(pN);
               memcpy((void*)pF, (void*)pN, l);
               pF += l;
            }
            pN = pN2;
         }

         if (kal_dchar_strlen(f->FullName) < MaxLength)
            kal_dchar_strcpy((char *)FileName, f->FullName);
         else
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_STRING_BUFFER_TOO_SMALL, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }
         break;

      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFClose(RTFHANDLE File)
{
   return RTFCloseFile(File, RTFFREESLOT);
}

/*-----------------------------------*/
int RTFAPI RTFCloseFile(RTFHANDLE File, BYTE freeSlot)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         if (FileCount(f->Dev) <= 1)
            FlushAllBuffers(f->Dev);    // always flush all when last file is closed
         else
            if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) &&
                ((f->Flags & RTF_READ_ONLY) == 0))
            {
               if (f->Flags & RTF_LAZY_DATA)
                  FlushAllBuffers(f->Dev);
               else
               {
                  CommitDirEntry(f);
                  FlushFAT(f->Dev);
                  if (SearchBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset)))
                  {
                     CommitBuffer(f->Dev);
                     if ((f->Flags & RTF_CACHE_DATA) == 0)
                        DiscardBuffer(f->Dev);
                  }
               }
            }

         // recoverable support
         if ((f->Flags & FS_PROTECTION_MODE) && f->Dev->Driver->ResumeSectorStates)
         {
            int result = f->Dev->Driver->ResumeSectorStates(f->Dev->DriverData);

            if (result < RTF_NO_ERROR)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, result, f, NULL);
#endif
               XRAISE(result);
            }
         }

         // if this is the last device or drive file with write access
         // unmount the device or drive
         if ((f->Flags & RTF_READ_ONLY) == 0)
            switch (f->SpecialKind)
            {
               case Volume:
                  if (FileCountDrive(f->Drive) <= 1)
                     f->Drive->MountState = NotMounted;
                  break;
               case PhysicalDisk:
                  if (FileCount(f->Dev) <= 1)
                     UnmountDevice(f->Dev, 0);
                  break;
            }
         break;
      default:
         break;
      case XFINALLY:
         if (f)
         {
            if (freeSlot)
               FreeFTSlotAndDevice(f);
            else
            {
               if (f->Dev)
                  UnlockDevice(f->Dev);
            }
         }
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetFileSize(RTFHANDLE File, DWORD * Size)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         switch (f->SpecialKind)
         {
            case NormalFile:
               *Size = f->DirEntry.Dir.FileSize;
               break;
/* FileMapFile GetFileSize, MTK_WCP_SW , 2005/08/21, MODIFY START */
            case FileMapFile:
               *Size = f->DirEntry.Dir.FileSize - f->DirEntry.ShortPos.Index; /* BIAS */
               break;
/* FileMapFile GetFileSize, MTK_WCP_SW , 2005/08/21, MODIFY END */
            case Volume:
               *Size = f->Drive->Geometry.Sectors << f->Dev->DevData.SectorShift;
               break;
            case PhysicalDisk:
               *Size = f->Dev->DevData.Geometry.Sectors << f->Dev->DevData.SectorShift;
               break;
            default:
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, NULL);
#endif
               XRAISE(RTF_INVALID_FILE_HANDLE);
               break;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSetFileTime(RTFHANDLE File, const RTFDOSDateTime * Time)
{
   RTFile * volatile f = NULL;
   RTFDOSDirEntry * D;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, f, NULL);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }

         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, f, NULL);
#endif
            XRAISE(RTF_PARAM_ERROR);
         }
         f->DirEntry.Dir.DateTime = *Time;
         D = GetDir(f->Drive, &f->DirEntry.ShortPos);
         *D = f->DirEntry.Dir;
         SetDirty(f->Dev);
         if (f->Flags & RTF_COMMITTED)
            CommitBuffer(f->Dev);
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSetFileCreatedTime(RTFHANDLE File, const RTFDOSDateTime * Time)
{
   RTFile * volatile f = NULL;
   RTFDOSDirEntry * D;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, f, NULL);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }

         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, f, NULL);
#endif
            XRAISE(RTF_PARAM_ERROR);
         }
         f->DirEntry.Dir.CreateDateTime = *Time;
         D = GetDir(f->Drive, &f->DirEntry.ShortPos);
         *D = f->DirEntry.Dir;
         SetDirty(f->Dev);
         if (f->Flags & RTF_COMMITTED)
            CommitBuffer(f->Dev);
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
 
int RTFAPI MTCheckMSCard(RTFHANDLE File, RTFBootRecord *BR)
{
   RTFile * volatile f = NULL;
   int Mega, i;
   int volatile bCorrect = 0, Result = RTF_NO_ERROR;

   XTRY
      case XCODE:
         f = ParseFileHandle_NB(File);
         if ((f->Dev->DeviceFlags & MT_DEVICE_MEMORY_STICK) == MT_DEVICE_MEMORY_STICK)
         {
            Mega = BR->BP.TotalSectors / 2048;
            if (Mega > 64)
            {
               i = 16; // 128M
            }
            else if (Mega > 32)
            {
               i = 8;   // 64M
            }
            else if (Mega > 16)
            {
               i = 4;   // 32M
            }
            else if (Mega > 8)
            {
               i = 4;   // 16M
            }
            else   // 8M & 4M
            {
               i = 2;
            }

            if (BR->BP.NumberOfHeads != i)
            {
               BR->BP.NumberOfHeads = (WORD)(i & 0xFFFF);
               if(i<= 4)
                  BR->BP.TotalSectors = 0;
               bCorrect = 1;
            }
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);

         if (bCorrect)
         {
            Result = RTFSeek(File, 0, RTF_FILE_BEGIN);
            if (Result >= RTF_NO_ERROR)
            {
               kal_mem_set( (void *)BR->BP.E._16.BPB.Label, 0, 11);
               Result = RTFWrite(File, (void*)BR, sizeof(RTFBootRecord), NULL);
            }
         }
         break;
   XEND_API
   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFGetFileInfo(RTFHANDLE File, RTFFileInfo * FileInfo)
{
   RTFile * volatile f = NULL;
   RTFCluster Cluster, LastCluster;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         FileInfo->FilePos = f->FilePointer;
         FileInfo->FullName = f->FullName;
         FileInfo->ClusterChains = 0;
         FileInfo->VolumeSerialNumber = f->Drive ? f->Drive->SerialNumber : 0;

         switch (f->SpecialKind)
         {
            case PhysicalDisk:
               FileInfo->VolumeSerialNumber = 0;
               FileInfo->DirEntry = NULL;
               FileInfo->AllocatedSize = f->Dev->DevData.Geometry.Sectors << f->Dev->DevData.SectorShift;
               break;
            case Volume:
               FileInfo->VolumeSerialNumber = f->Drive->SerialNumber;
               FileInfo->DirEntry = NULL;
               FileInfo->AllocatedSize = f->Drive->Geometry.Sectors << f->Dev->DevData.SectorShift;
               break;
            case NormalFile:
               FileInfo->VolumeSerialNumber = f->Drive->SerialNumber;
               FileInfo->DirEntry = &f->DirEntry.Dir;
               Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
               if (Cluster == RTF_ROOT_DIR) // special cluster for root dir
                  FileInfo->AllocatedSize = f->DirEntry.Dir.FileSize;
               else
               {
                  FileInfo->AllocatedSize = 0;
                  LastCluster = 0;
                  while ((Cluster != 0) && (Cluster < RTF_CLUSTER_CHAIN_END))
                  {
                     FileInfo->AllocatedSize += f->Drive->ClusterSize;
                     if (Cluster != (LastCluster+1))
                        FileInfo->ClusterChains++;
                     LastCluster = Cluster;
                     Cluster = GetClusterValue(f->Drive, LastCluster);
                  }
               }
/* FileMapFile Get file info, MTK_WCP_SW , 2005/08/21, MODIFY START */
               break;
            case FileMapFile:
               /* Reset FilePointer as 0 */
               FileInfo->FilePos -= f->DirEntry.ShortPos.Index; /* BIAS */
/* FileMapFile Get file info, MTK_WCP_SW , 2005/08/21, MODIFY END */
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFMakeFileName(const RTFDOSDirEntry * FileInfo, WCHAR * FileName)
{
   return MakeShortFileName(FileInfo, (char *)FileName, 13);
}

/*-----------------------------------*/
int RTFAPI RTFRead(RTFHANDLE File, void * DataPtr, UINT Length, UINT * Read)
{
   register RTFile * f;
   RTFile * volatile f1 = NULL; // just for cleanup
   UINT l1, l2, l3;
   DWORD volatile InitialFilePointer;
   int volatile Result = RTF_NO_ERROR;
   UINT DummyRead;

   if (Read == NULL)
      Read = &DummyRead;
   *Read = 0;

   XTRY
      case XCODE:
         f1 = f = ParseFileHandle_NB(File);
         InitialFilePointer = f->FilePointer;

         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD START */
         if(f->Valid == MT_ENUM_FH_ABORTED)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_ABORTED_ERROR, f, NULL);
#endif
            XRAISE(MT_ABORTED_ERROR);
         }
         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD END */

         if ((f->SpecialKind == NormalFile) && (f->FilePointer > f->DirEntry.Dir.FileSize))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "FilePointer: %d, Size: %d", f->FilePointer, f->DirEntry.Dir.FileSize);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILE_POS);
         }

         if ((f->FilePointer + Length) < f->FilePointer)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "FilePointer: %d, Length: %d", f->FilePointer, Length);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_TOO_LARGE, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_FILE_TOO_LARGE);
         }

         if(f->Flags & FS_NONBLOCK_MODE)
            RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_NON_BLOCK_ENUM);

         if (f->SpecialKind == Volume || f->SpecialKind == PhysicalDisk )
         {
            RTFSector C = Length >> f->Dev->DevData.SectorShift;
            RTFSector S = ((f->SpecialKind == Volume) ? f->Drive->FirstSector : 0)
                        + (f->FilePointer >> f->Dev->DevData.SectorShift);

            if ((Length & (f->Dev->DevData.SectorSize-1)) != 0)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Length: %d", Length);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, f, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_PARAM_ERROR);
            }

            DiscardBuffersRange(f->Dev, S, C, 1);
            ReadSectors(f->Dev, DataPtr, S, C, 0);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedReads += C;
#endif

            f->FilePointer += Length;
            *Read          += Length;
            break;
         }
/* FileMapFile read, MTK_WCP_SW , 2005/08/21, MODIFY START */
         else if(f->SpecialKind == FileMapFile)
         {  
            Result = MTChkMapedFH( f->DirEntry.LongPos.Index ); /* LINK */
            if( Result != RTF_NO_ERROR )
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "FilePointer: %d, Link: %d", f->FilePointer, f->DirEntry.LongPos.Index);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_VF_MAP_ERROR, f, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(MT_VF_MAP_ERROR);
            }
         }
/* FileMapFile read, MTK_WCP_SW , 2005/08/21, MODIFY END */

         Length = min(Length, f->DirEntry.Dir.FileSize - f->FilePointer);

         // make 3 partitions:
         // 1. bytes up to next sector boundary
         // 2. complete sectors
         // 3. to end of area
         // if start and end of area are within the same sector,
         // l3 is used.

         if ((f->FilePointer >> f->Dev->DevData.SectorShift) == ((f->FilePointer+Length) >> f->Dev->DevData.SectorShift))
         {
            l1 = 0;
            l2 = 0;
            l3 = Length;
         }
         else
         {
            l3 = (f->FilePointer+Length) - RTFRoundDown((f->FilePointer+Length), f->Dev->DevData.SectorSize);
            l1 = RTFRoundUp(f->FilePointer, f->Dev->DevData.SectorSize) - f->FilePointer;
            l2 = Length - l1 - l3;
         }

         if (l1 > 0)
         {
            BYTE * Data = GetBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset), 0);

            memcpy(DataPtr, Data + SECTOR_OFS(f->Drive, f->Offset), l1);

            // this could be a file with read/write access
            // thus we must always check if we leave a dirty buffer behind
            if ((f->Flags & RTF_LAZY_DATA) == 0)
               CommitBuffer(f->Dev);
            if ((f->Flags & RTF_CACHE_DATA) == 0)
               DiscardBuffer(f->Dev);

            *Read           += l1;
            DataPtr = (BYTE*) DataPtr + l1;
            MoveFilePointer(f, l1);
         }
         while (l2 > 0)
         {
            UINT       n;      // bytes in this segment
            RTFSector  C;      // number of sectors in segment;
            RTFSector  S;      // sector to start writing at

            S = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
            n = MoveFilePointerSegment(f, l2);
            C = n >> f->Dev->DevData.SectorShift;

            // can read C sectors starting at S, but have to check
            // for any data in buffers

            DiscardBuffersRange(f->Dev, S, C, 1);  // discard with commit
            ReadSectors(f->Dev, DataPtr, S, C, 0);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedReads += C;
#endif
            *Read           += n;
            DataPtr = (BYTE*)DataPtr + n;
            l2 -= n;
         }
         if (l3 > 0)
         {
            BYTE * Data = GetBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset), 0);
            memcpy(DataPtr, Data + SECTOR_OFS(f->Drive, f->Offset), l3);
            MoveFilePointer(f, l3);
            *Read += l3;
         }
         break;
      default:
         Result = XVALUE;
         if ((Result != RTF_FILE_TOO_LARGE) &&
             f1 && ((InitialFilePointer + *Read) != f1->FilePointer)
             || Result == MT_FLASH_ERASE_BUSY)
         XTRY
            case XCODE:
               InitFilePointer(f1);
               MoveFilePointer(f1, InitialFilePointer + *Read);
               break;
            default:
               if (Result == RTF_NO_ERROR)
                   Result = XVALUE;
               XHANDLED;
               break;
            case XFINALLY:
               break;
         XENDX
         break;
      case XFINALLY:
#ifdef DEBUG
         if (f1 && ((InitialFilePointer + *Read) != f1->FilePointer))
             RTFSYSErrorExit("RTFRead: file pointer incorrect\n", 1);
#endif
         // reset to block mode
         if(f1) /* Fix f1 is null case, Karen Hsu, 2004/03/01 */
         {
            if(f1->Flags & FS_NONBLOCK_MODE)
               RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_BLOCK_ENUM);
            UnlockDevice(f1->Dev);
         }
         break;
   XEND_API
   return Result;
}

/*-----------------------------------*/
void RTFAPI ExtendFile(RTFile * f, DWORD Bytes)
// extend at most by Bytes bytes, but possibly less
// the extend is one segment
{
   RTFCluster NeedClusters = ((Bytes - 1) >> (f->Drive->ClusterShift)) + 1;

#ifdef DEBUG
   if (f->Cluster != 0)
       RTFSYSErrorExit("ExtendFile: f->Cluster not 0\n", 1);
#endif

   f->Cluster = f->LastCluster+1; // will be fixed by AllocateFATSegment if invalid
   AllocateFATSegment(f->Drive, &f->Cluster, NeedClusters, f);
   if (f->LastCluster)
   {
      SetClusterValue(f->Drive, f->LastCluster, f->Cluster); // connect the two chains
   }
   else
   {
      SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->Cluster);   // this is the first chain
      UpdateDirEntry(f);
   }
}

/*-----------------------------------*/
int RTFAPI RTFWrite(RTFHANDLE File, void * DataPtr, UINT Length, UINT * Written)
{
   register RTFile * f;
   RTFile * volatile f1 = NULL;
   UINT l1, l2, l3;
   DWORD volatile InitialFilePointer;
   int volatile Result = RTF_NO_ERROR;
   UINT DummyWritten;
   int fs_block_type = FS_BLOCK_ENUM; /* Fix multi-access bug, Karen Hsu, 2004/07/08, ADD */

   if (Written == NULL)
      Written = &DummyWritten;
  *Written = 0;

   XTRY
      case XCODE:
         f1 = f = ParseFileHandle_NB(File);

         InitialFilePointer = f->FilePointer;

         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD START */
         if(f->Valid == MT_ENUM_FH_ABORTED)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_ABORTED_ERROR, f, NULL);
#endif
            XRAISE(MT_ABORTED_ERROR);
         }
         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD END */

         if (f->Flags & RTF_READ_ONLY)
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, f, NULL);
#endif
            XRAISE(MT_READ_ONLY_ERROR);
            //XRAISE(RTF_ACCESS_DENIED);
         }
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

         if ((f->SpecialKind == NormalFile) && (f->FilePointer > f->DirEntry.Dir.FileSize))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "FilePointer: %d, Size: %d", f->FilePointer, f->DirEntry.Dir.FileSize);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILE_POS);
         }

         if ((f->FilePointer + Length) < f->FilePointer)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "FilePointer: %d, Length: %d", f->FilePointer, Length);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_TOO_LARGE, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_FILE_TOO_LARGE);
         }

         if(f->Flags & FS_NONBLOCK_MODE)
            RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_NON_BLOCK_ENUM);
         else if (f->Flags & FS_PROTECTION_MODE)
            RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_BLOCK_PROTECTION_ENUM);

         if (f->SpecialKind != NormalFile)
         {
            RTFSector C = Length >> f->Dev->DevData.SectorShift;
            RTFSector S = ((f->SpecialKind == Volume) ? f->Drive->FirstSector : 0)
                        + (f->FilePointer >> f->Dev->DevData.SectorShift);
            if ((Length & (f->Dev->DevData.SectorSize-1)) != 0)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "SpecialKind: %d", f->SpecialKind);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, f, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_PARAM_ERROR);
            }

            DiscardBuffersRange(f->Dev, S, C, 0);   // discard without commit
            WriteSectors(f->Dev, DataPtr, S, C, 0, RTF_NORMAL_WRITE);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedWrites += C;
#endif
            f->FilePointer += Length;
            *Written       += Length;
            break;
         }

         // make 3 partitions:
         // 1. bytes up to next sector boundary
         // 2. complete sectors
         // 3. to end of area
         // if start and end of area are within the same sector,
         // l3 is used.

         if ((f->Cluster == RTF_ROOT_DIR) && ((f->FilePointer + Length) > f->DirEntry.Dir.FileSize))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ROOT_DIR_FULL, f, NULL);
#endif
            XRAISE(RTF_ROOT_DIR_FULL);
         }

         if ((f->FilePointer >> f->Dev->DevData.SectorShift) == ((f->FilePointer+Length) >> f->Dev->DevData.SectorShift))
         {
            l1 = 0;
            l2 = 0;
            l3 = Length;
         }
         else
         {
            l3 = (f->FilePointer+Length) - RTFRoundDown((f->FilePointer+Length), f->Dev->DevData.SectorSize);
            l1 = RTFRoundUp(f->FilePointer, f->Dev->DevData.SectorSize) - f->FilePointer;
            l2 = Length - l1 - l3;
         }

            fs_block_type = (int)RTFSYSGetTLS(TLSBlockIndex); /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD*/

         if (l1 > 0)
         {
            BYTE * Data = GetBuffer(f->Dev, CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset), 0);

            memcpy(Data + SECTOR_OFS(f->Drive, f->Offset), DataPtr, l1);

            SetDirty(f->Dev);
            SetRecoverableFlag(f->Dev, fs_block_type);

            if ((f->Flags & RTF_LAZY_DATA) == 0)
               CommitBuffer(f->Dev);
            if ((f->Flags & RTF_CACHE_DATA) == 0)
               DiscardBuffer(f->Dev);

            *Written        += l1;
            DataPtr = (BYTE*) DataPtr + l1;
            MoveFilePointer(f, l1);
         }
         while (l2 > 0)
         {
            UINT       n;      // number of bytes in segment
            RTFSector  S;      // sector to start writing at
            RTFSector  C;      // number of sectors in segment;

            if (f->Cluster == 0) // end of file, allocate more
               ExtendFile(f, l2+l3);

            S = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
            n = MoveFilePointerSegment(f, l2);
            C = n >> f->Dev->DevData.SectorShift;

            // can write C sectors starting at S, but have to check
            // for any data in buffers

            DiscardBuffersRange(f->Dev, S, C, 0);   // discard without commit

            /* l2 writes will not involve cache */
            if (fs_block_type == FS_BLOCK_PROTECTION_ENUM)
               WriteSectors(f->Dev, DataPtr, S, C, 0, RTF_RECOVERABLE_WRITE);
            else
               WriteSectors(f->Dev, DataPtr, S, C, 0, RTF_NORMAL_WRITE);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedWrites += C;
#endif
            *Written        += n;
            DataPtr = (BYTE*) DataPtr + n;
            l2 -= n;
         }
         if (l3 > 0)
         {
            RTFSector S;
            UINT Offset = SECTOR_OFS(f->Drive, f->Offset);
            UINT NeedOldSector = (f->DirEntry.Dir.FileSize > f->FilePointer) || Offset;
            BYTE * Data;

            if (f->Cluster == 0)
               ExtendFile(f, l3);

            S = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
            MoveFilePointer(f, l3);

            Data = GetBuffer(f->Dev, S, NeedOldSector ? 0 : NO_LOAD);
            memcpy(Data + Offset, DataPtr, l3);
            SetDirty(f->Dev);
            SetRecoverableFlag(f->Dev, fs_block_type);

            *Written += l3;

            if (f->Flags & RTF_COMMITTED)
               CommitBuffer(f->Dev);
         }
         break;
      default:
         Result = XVALUE;
         if ((Result != RTF_FILE_TOO_LARGE) &&
             f1 && ((InitialFilePointer + *Written) != f1->FilePointer)
             || Result == MT_FLASH_ERASE_BUSY)
         XTRY
            case XCODE:
               InitFilePointer(f1);
               MoveFilePointer(f1, InitialFilePointer + *Written);
               break;
            default:
               XHANDLED;   // ignore further exceptions
               break;
            case XFINALLY:
               break;
         XENDX
         break;
      case XFINALLY:
         if (f1)
         {
            #ifdef DEBUG
            if (((InitialFilePointer + *Written) != f1->FilePointer))
                RTFSYSErrorExit("RTFWrite: file pointer incorrect\n", 1);
            #endif
            if (((f1->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)) // do not update dirs
            {
               if (f1->FilePointer > f1->DirEntry.Dir.FileSize)
                  f1->DirEntry.Dir.FileSize = f1->FilePointer;
               f1->DirEntry.Dir.Attributes |= RTF_ATTR_ARCHIVE;
            }
            XTRY
               case XCODE:
                  RTFSYSGetDateTime(&f1->DirEntry.Dir.DateTime);
                  UpdateDirEntry(f1);
                  if (f1->Flags & RTF_COMMITTED)
                     FlushFAT(f1->Dev);
                  break;
               default:
                  if (Result == RTF_NO_ERROR)
                      Result = XVALUE;
                  XHANDLED;
                  break;
               case XFINALLY:
                  // reset to block mode
                  /* Fix protection mode didn't reset to block mode, Karen Hsu, 2004/01/27, MOD START */
                  if((f1->Flags & FS_NONBLOCK_MODE) || (f1->Flags & FS_PROTECTION_MODE))
                  //if(f1->Flags & FS_NONBLOCK_MODE)
                  /* Fix protection mode didn't reset to block mode, Karen Hsu, 2004/01/27, MOD END */
                     RTFSYSSetTLS(TLSBlockIndex,(_XData*)FS_BLOCK_ENUM);
                  break;
            XENDX
            UnlockDevice(f1->Dev);
         }
         break;
   XEND_API
   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFCommit(RTFHANDLE File)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         /* Speed Up Commit Algo, MTK_WCP_SW , 2006/05/17, MOD START */
         // FlushAllBuffers(f->Dev);
         FlushAllBuffersInGeometryOrder(f->Dev);
         /* Speed Up Commit Algo, MTK_WCP_SW , 2006/05/17, MOD END   */
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFTruncate(RTFHANDLE File)
{
   RTFile * volatile f = NULL;
   RTFCluster StartCluster;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "SpecialKind: %d", f->SpecialKind);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_PARAM_ERROR);
         }

         if (f->Flags & RTF_READ_ONLY)
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, f, NULL);
#endif
            XRAISE(MT_READ_ONLY_ERROR);
            //XRAISE(RTF_ACCESS_DENIED);
         }
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */


         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == RTF_ROOT_DIR) // can't truncate a root dir
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, f, NULL);
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) && (f->FilePointer == 0))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, f, NULL);
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }

         if (f->FilePointer > f->DirEntry.Dir.FileSize)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "FilePointer: %d, Size: %d", f->FilePointer, f->DirEntry.Dir.FileSize);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILE_POS);
         }

         f->DirEntry.Dir.FileSize = f->FilePointer;
         UpdateDirEntry(f);

         // if the file pointer is on a cluster boundary, delete its cluster
         // and all following clusters
         // else delete only following clusters

         if (f->Offset == 0)                  // file pointer is on a cluster boundary
            StartCluster = f->Cluster;
         else
            StartCluster = GetClusterValue(f->Drive, f->Cluster);
         if (StartCluster != 0)
         //quota
         {
            FATDelete(f->Drive, StartCluster, f);
            //FATDelete(f->Drive, StartCluster);
         }

         if (f->DirEntry.Dir.FileSize == 0) // no cluster chain at all (Dirs will never haev this value)
         {
            SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, 0);
            UpdateDirEntry(f);
            f->Cluster = 0;
         }
         else
            // terminate the now open cluster chain
            if (StartCluster == f->Cluster)
            {
               f->Cluster = 0;
               #ifdef DEBUG
               if ((f->LastCluster < 2) || (f->LastCluster > f->Drive->Clusters))
                  RTFSYSErrorExit("Invalid LastCluster in RTFTruncate", 1);
               #endif
               SetClusterValue(f->Drive, f->LastCluster, RTF_CHAIN_END_MARK);
               f->Cluster = 0;
            }
            else
               SetClusterValue(f->Drive, f->Cluster, RTF_CHAIN_END_MARK); // no following clusters

         if (f->Flags & RTF_COMMITTED)
            FlushFAT(f->Dev);
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
//long RTFAPI RTFSeek(RTFHANDLE File, long Offset, int Whence)
int RTFAPI RTFSeek(RTFHANDLE File, int Offset, int Whence)
{
   RTFile * volatile f = NULL;
   DWORD StartPos = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
   DWORD volatile NewPos;
   RTFSector Sector;

   XTRY
      case XCODE:
         f = ParseFileHandle(File);

         if ((f->SpecialKind == NormalFile) && (f->FilePointer > f->DirEntry.Dir.FileSize))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "FilePointer: %d, Size: %d", f->FilePointer, f->DirEntry.Dir.FileSize);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILE_POS);
         }

         switch (Whence)
         {
            case RTF_FILE_BEGIN:
/* FileMapFile seek, MTK_WCP_SW , 2005/08/21, MODIFY START */
               if (f->SpecialKind == FileMapFile)
               {  
                  StartPos = f->DirEntry.ShortPos.Index; /* BIAS */
               }
               else
               {  
                  StartPos = 0;
               }
/* FileMapFile seek, MTK_WCP_SW , 2005/08/21, MODIFY END */
               break;
            case RTF_FILE_CURRENT:
               StartPos = f->FilePointer;
               break;
            case RTF_FILE_END:
               StartPos = f->DirEntry.Dir.FileSize;
               break;
            default:
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Whence: %d", Whence);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, f, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_PARAM_ERROR);
         }

         NewPos = StartPos + Offset;

         if ((Offset < 0) && (NewPos > StartPos))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "Offset: %d, NewPos: %d, StartPos: %d", Offset, NewPos, StartPos);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILE_POS);
         }
         if ((Offset > 0) && (NewPos < StartPos))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "Offset: %d, NewPos: %d, StartPos: %d", Offset, NewPos, StartPos);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILE_POS);
         }

         if (f->SpecialKind == Volume  || f->SpecialKind == PhysicalDisk)
         {
            if ((NewPos & (f->Dev->DevData.SectorSize-1)) != 0)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "Offset: %d, NewPos: %d, StartPos: %d", Offset, NewPos, StartPos);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_POS);
            }
            f->FilePointer = NewPos;
            break;
         }
/* FileMapFile seek, MTK_WCP_SW , 2005/08/21, MODIFY START */
         else if(f->SpecialKind == FileMapFile)
         {  
            if( RTF_NO_ERROR != MTChkMapedFH( f->DirEntry.LongPos.Index ) ) /* LINK */
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "FilePointer: %d, Link: %d", f->FilePointer, f->DirEntry.LongPos.Index);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_VF_MAP_ERROR, f, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(MT_VF_MAP_ERROR);
            }
         }
/* FileMapFile seek, MTK_WCP_SW , 2005/08/21, MODIFY END */

         if (NewPos > f->DirEntry.Dir.FileSize)
         {
            if (f->Flags & RTF_READ_ONLY)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "NewPos: %d, FileSize: %d", NewPos, f->DirEntry.Dir.FileSize);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_POS);
            }
            if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == RTF_ROOT_DIR)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
               {
                  kal_sprintf(TraceTmpBuf, "NewPos: %d, FileSize: %d", NewPos, f->DirEntry.Dir.FileSize);
                  memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
               }
#endif
               XRAISE(RTF_INVALID_FILE_POS);
            }
         }

         Sector = CLUSTER_TO_SECTOR_OFS(f->Drive, f->Cluster, f->Offset);

         if (NewPos < f->FilePointer)
         {
            if ((f->FilePointer - NewPos) > f->Offset) // we need to go back at least one cluster
            {
               /* Speedup seek, Karen Hsu, 2004/05/14, ADD START */
               if(f->HintNum && (f->Seek_Hint[0].Index <= NewPos))
               {
                  int i;
                  DWORD Ofs;
                  for(i = f->HintNum - 1; i >= 0; i--)
                  {
                     if(f->Seek_Hint[i].Index <= NewPos)
                        break;
                  }
                  f->FilePointer = NewPos;
                  f->Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
                  if (f->Cluster == RTF_ROOT_DIR)
                  {
                     f->LastCluster = 0;
                     f->FilePointer = NewPos;
                     f->Offset = NewPos;
                     goto SeekContinue;
                  }
                  Ofs = NewPos - f->Seek_Hint[i].Index;
                  f->Cluster = f->Seek_Hint[i].Cluster;
                  while (Ofs >= f->Drive->ClusterSize)
                  {
                     Ofs -= f->Drive->ClusterSize;
                     if ((f->Cluster < 2L) || (f->Cluster >= RTF_CLUSTER_CHAIN_END))
                     {
#ifdef __FS_TRACE_SUPPORT__
                        if(g_TraceFlag & MT_TRACE_ERROR)
                        {
                           kal_sprintf(TraceTmpBuf, "Cluster: %d", f->Cluster);
                           memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                           MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FAT_ALLOC_ERROR, f, (BYTE *)TraceTmpBuf);
                        }
#endif
                        XRAISE(RTF_FAT_ALLOC_ERROR);
                     }
                     f->LastCluster = f->Cluster;
                     f->Cluster = GetClusterValue(f->Drive, f->LastCluster);
                  }
                  if (f->Cluster >= RTF_CLUSTER_CHAIN_END)
                     f->Cluster = 0;
                  f->Offset = Ofs;
                  goto SeekContinue;
               }
               /* Speedup seek, Karen Hsu, 2004/05/14, ADD END */
               InitFilePointer(f);
               MoveFilePointer(f, NewPos);
            }
            else
            {
               f->Offset -= f->FilePointer - NewPos;
               f->FilePointer -= f->FilePointer - NewPos;
            }
         }
         else if (NewPos > f->FilePointer)
         {
            /* Speedup seek, Karen Hsu, 2004/05/14, MOD START */
            DWORD NextClusterBoundary;
            //DWORD NextClusterBoundary = RTFRoundUp(f->FilePointer, f->Drive->ClusterSize);
            /* Speedup seek, Karen Hsu, 2004/05/14, MOD END */
            DWORD l;

            /* Speedup seek, Karen Hsu, 2004/05/14, ADD START */
            if(f->HintNum)
            {
               if((f->FilePointer < f->Seek_Hint[f->HintNum-1].Index) &&
               (f->Seek_Hint[0].Index <= NewPos))
               {
                  int i;
                  for(i = f->HintNum - 1; i >= 0; i--)
                  {
                     if(f->Seek_Hint[i].Index <= NewPos)
                     {
                        f->FilePointer = f->Seek_Hint[i].Index;
                        f->Offset = 0;
                        f->Cluster = f->Seek_Hint[i].Cluster;
                        break;
                     }
                  }
               }
            }
            NextClusterBoundary = RTFRoundUp(f->FilePointer, f->Drive->ClusterSize);
            /* Speedup seek, Karen Hsu, 2004/05/14, ADD END */

            // move to the next cluster boundary
            if (NextClusterBoundary > NewPos)
               NextClusterBoundary = NewPos;

            l = NextClusterBoundary - f->FilePointer;
            if (l > 0)
               MoveFilePointer(f, l);

            l = NewPos - f->FilePointer;
            while (l > 0)
            {
               if (f->Cluster == 0)
                  ExtendFile(f, l);
               MoveFilePointerSegment(f, l);
               l = NewPos - f->FilePointer;
            }
            if (NewPos > f->DirEntry.Dir.FileSize)
            {
               f->DirEntry.Dir.FileSize = NewPos;
               UpdateDirEntry(f);
               if (f->Flags & RTF_COMMITTED)
                  FlushFAT(f->Dev);
            }
         }
SeekContinue: /* Speedup seek, Karen Hsu, 2004/05/14 */
         if ((Sector != CLUSTER_TO_SECTOR_OFS(f->Drive, f->Cluster, f->Offset)) &&
             ((f->Flags & RTF_LAZY_DATA) == 0) &&
             SearchBuffer(f->Dev, Sector))
         {
            CommitBuffer(f->Dev);
            if ((f->Flags & RTF_CACHE_DATA) == 0)
               DiscardBuffer(f->Dev);
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API

/* FileMapFile seek, MTK_WCP_SW , 2005/08/21, ADD START */
   if (f->SpecialKind == FileMapFile)
   {  
      NewPos -= f->DirEntry.ShortPos.Index; /* BIAS */
   }
/* FileMapFile seek, MTK_WCP_SW , 2005/08/21, ADD END */

   if ((int) NewPos >= 0)
      return (int) NewPos;
   else
      return RTF_LONG_FILE_POS;
}

/*-----------------------------------*/
int RTFAPI RTFExtend(RTFHANDLE File, DWORD Length)
{
   RTFile * volatile f = NULL;
   UINT        Try = 0;
   RTFCluster  CurrClusters,
               NewClusters,
               //ClusterStart,
               ChainTo,
               SegmentLength,
               C,
               MaxSegment;
   DWORD       TotalBytes;
#ifdef __FS_QM_SUPPORT__
   int quota_idx = -1; /* Add for quota management, Karen Hsu, 2004/08/10, ADD */
#endif

   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         if ((f->SpecialKind != NormalFile) ||
             (f->Flags & RTF_READ_ONLY) ||
             (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == RTF_ROOT_DIR))
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, f, NULL);
#endif
            XRAISE(MT_READ_ONLY_ERROR);
            //XRAISE(RTF_ACCESS_DENIED);
         }
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */

         if (f->FilePointer > f->DirEntry.Dir.FileSize)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "FilePointer: %d, Size: %d", f->FilePointer, f->DirEntry.Dir.FileSize);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_POS, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILE_POS);
         }

         TotalBytes = f->FilePointer + Length;
         if (TotalBytes < f->FilePointer)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "TotalBytes: %d, FilePointer: %d", TotalBytes, f->FilePointer);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_FILE_TOO_LARGE, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_FILE_TOO_LARGE);
         }

         /* Speed Up Extend Algo, MTK_WCP_SW , 2006/05/17, MOD START */
         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == 0) // zero file size
         {
            ChainTo = f->Drive->ClusterWatermark;
            CurrClusters = 0;
            C = ChainTo;
         }
         else if (f->Cluster == 0) // file pointer *just* on the boundy, cluster not allocated yet
         {
            EXT_ASSERT(f->Offset == 0, (UINT)(f->FilePointer),
                                       (UINT)(f->LastCluster),
                                       (UINT)(FIRST_FILE_CLUSTER(f->DirEntry.Dir)));
            ChainTo = f->LastCluster;
            TotalBytes = Length;
            CurrClusters = 0;
            C = f->Drive->ClusterWatermark;
         }
         else // file pointer correctly set, calculate partial offset
         {
            TotalBytes = f->Offset + Length;
            CurrClusters = FATClusterChainLength(f->Drive, f->Cluster, &ChainTo);
            C = ChainTo;
         }
         /* Speed Up Extend Algo, MTK_WCP_SW , 2006/05/17, MOD END   */

         if (TotalBytes > 0)
            NewClusters = ((TotalBytes-1) >> f->Drive->ClusterShift) + 1;
         else
            NewClusters = 0;

         if (NewClusters > CurrClusters)
            NewClusters -= CurrClusters;
         else
            break; // nothing to do

         MaxSegment = 0;

         while (1)
         {
            SegmentLength = FATZeros(f->Drive, C, NewClusters);
            if (SegmentLength >= NewClusters)
            {
               /* Add for quota management, Karen Hsu, 2004/08/10, ADD START */
#ifdef __FS_QM_SUPPORT__
               if(f->Drive->QuotaMgt)
               {
                  char * fName;

                  fName = &f->FullName[6];

                  #ifdef __FS_TRACE_SUPPORT__
                     if(g_TraceFlag & MT_TRACE_ERROR)
                     {
                        kal_sprintf(TraceTmpBuf, "Before Allocate: %d, Free: %d", NewClusters, f->Drive->FreeClusterCount);
                        memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                        MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_OK, f, (BYTE *)TraceTmpBuf);
                     }
                  #endif

                  if(*fName == '@')
                  {
                     GetQuotaEntry(&quota_idx, f);
                     if(quota_idx >= 0)
                     {
                        if(QMPermitAllocate(f->Drive->FreeClusterCount, quota_idx, NewClusters) != RTF_NO_ERROR)
                        {
#ifdef __FS_TRACE_SUPPORT__
                              if(g_TraceFlag & MT_TRACE_ERROR)
                              {
                                 kal_sprintf(TraceTmpBuf, "Idx: %d", quota_idx);
                                 memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                                 MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_ERR, f, (BYTE *)TraceTmpBuf);
                              }
#endif
                           XRAISE(MT_APP_QUOTA_FULL);
                        }
                     }
                  }
                  else if(WFNamesMatch(fName, (char *)NvramName) == 0)
                  {

                     if(QMPermitAllocate(f->Drive->FreeClusterCount, -1, NewClusters) != RTF_NO_ERROR)
                     {
#ifdef __FS_TRACE_SUPPORT__
                        if(g_TraceFlag & MT_TRACE_ERROR)
                        {
                           kal_sprintf(TraceTmpBuf, "None NVRAM Access!");
                           memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                           MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_ERR, f, (BYTE *)TraceTmpBuf);
                        }
#endif
                           XRAISE(MT_APP_QUOTA_FULL);
                     }
                  }
               }
#endif
               /* Add for quota management, Karen Hsu, 2004/08/10, ADD END */
               FATMarkSegment(f->Drive, C, NewClusters);

#ifdef __FS_QM_SUPPORT__
               if(quota_idx >= 0)
               {
                  gFS_IntQuotaSet[quota_idx].Qnow += NewClusters; /* Add for quota management, Karen Hsu, 2004/08/10, ADD */

                  #ifdef __FS_TRACE_SUPPORT__
                     if(g_TraceFlag & MT_TRACE_ERROR)
                     {
                        kal_sprintf(TraceTmpBuf, "Idx: %d, Now: %d", quota_idx, gFS_IntQuotaSet[quota_idx].Qnow);
                        memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
                        MTTraceFS((UINT)kal_get_current_thread_ID(), 1 , __LINE__, MT_TRACE_QM_OK, f, (BYTE *)TraceTmpBuf);
                     }
                  #endif
               }
#endif

               if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == 0)
               {
                  SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, C);
                  UpdateDirEntry(f);
               }
               else
                  SetClusterValue(f->Drive, ChainTo, C);
               break;
            }
            else /* if (SegmentLength >= NewClusters) */
            {
               C += SegmentLength + 1;
               if (SegmentLength > MaxSegment)
                  MaxSegment = SegmentLength;
               /* Improve Response Time, MTK_WCP_SW , 2006/02/22, ADD START */
               C = FATSearchZeroInBuffer(f->Drive, C);
               /* Improve Response Time, MTK_WCP_SW , 2006/02/22, ADD END   */
               /* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD START */
               if ((C & SUBMARK_MASK) == 0x0)
               {
                  C = FATHintSearchBySubMark(f->Drive, C, (Try == 1 && NewClusters == 1));
               }
               /* Multiple Sub Cluster Watermark, MTK_WCP_SW , 2006/02/24, ADD END   */
               if (C >= f->Drive->Clusters)
               {
                  if ((Try == 0) && (ChainTo > 2))
                  {
                     C = 2;
                     Try = 1;
                  }
                  else
                  {
                     /* Distinguish Disk Full or Disk Fragment, MTK_WCP_SW , 2006/05/17, ADD START */
                     if (MaxSegment > 0)
                     {
#ifdef __FS_TRACE_SUPPORT__
                        if(g_TraceFlag & MT_TRACE_ERROR)
                           MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_DISK_FRAGMENT, f, NULL);
#endif
                        XRAISE(MT_DISK_FRAGMENT);
                     }
                     /* Distinguish Disk Full or Disk Fragment, MTK_WCP_SW , 2006/05/17, ADD END   */
#ifdef __FS_TRACE_SUPPORT__
                     if(g_TraceFlag & MT_TRACE_ERROR)
                        MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DISK_FULL, f, NULL);
#endif
                     XRAISE(RTF_DISK_FULL);
                  }
               }
            } /* END else (SegmentLength >= NewClusters) */
         }

         if (f->Cluster == 0)
         {
            DWORD Pos = f->FilePointer;
            InitFilePointer(f);
            MoveFilePointer(f, Pos);
         }

         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
/*Extending character string (short file name) to wdie character string */
void RTFAPI FileNameExtendToWCHAR(char *filename)
{
        // for Thai encoding issues: 0xA8 0x00 0xA8 0x00 ...
   int len=MTNativeFileNameLen(filename);
   int i=0, j=len;

   while ( filename[i] )
   {
      if ( filename[i] < 0x80 )
      {
         filename[j+2] = '\0';
         filename[j+1] = '\0';
         while ( j>i+1 )
         {
            filename[j] = filename[j-1];
            j--;
         }
         filename[i+1] = 0;
         len++;
         j=len;
      }
      i += 2;
   }
   filename[i+1]=0;
   /* Fix 0xE5 special char will be treated as deleted, Karen Hsu, 2005/07/04, ADD START */
   if (filename[0] == 0x05 && filename[1] != 0x00)
      filename[0] = 0xE5;
   /* Fix 0xE5 special char will be treated as deleted, Karen Hsu, 2005/07/04, ADD END */
}

/*-----------------------------------*/
/*Both of the arguments are in type of WCHAR * */
int RTFAPI FileNamesMatch(const WCHAR * p, const WCHAR * n)
{
   const WCHAR * LastWild = NULL;
   const WCHAR * LastWildN = NULL;

   while (1)
   {
      while ( p[0] && n[0] )
      {
         WCHAR P = wchartoupper(p[0]);
         WCHAR N = wchartoupper(n[0]);

         if (P == 0x2a)
         {
            LastWild = p;
            if (wchartoupper(p[1]) == N)
            {
               LastWildN = n;
               p++;
               P = wchartoupper(p[0]);
            }
         }
         if ((P == N) || (P == 0x3F))
            p++, n++;
         else if (P == 0x2A)
            n++;
         else
            break;
      }
      if ( (n[0]==0) && (p[0]==0 || (p[0]==0x2a && p[1]==0)) )
         return 1;
      if (LastWild && LastWildN && LastWildN[1])
      {
         p = LastWild;
         n = ++LastWildN;
      }
      else
         return 0;
   }
}

/*-----------------------------------*/
int  RTFAPI RTFFindClose(RTFHANDLE Handle)
{
   return RTFClose(Handle);
}

/*-------------------------------------------------------*/
/* Please note that MaxLength is counted in bytes, *not* characters.
    It is the caller's responsibility to pass a proper buffer, "FileName".
    If it is not large enough to hold the whole long file name,
    the short file name will be returned.
*/
int RTFAPI RTFFindNextEx(RTFHANDLE Handle, RTFDOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength)
{
   BYTE CheckSum = 0;
   int LFNIndex = -1;
   RTFile * volatile f = NULL;
   const char * NamePattern;
   RTFDirLocation * Pos;
   BYTE * A;
   BYTE NTReserved = 0;

   XTRY
      case XCODE:
         f = ParseFileHandle(Handle);

         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD START */
         if(f->Valid == MT_ENUM_FH_ABORTED)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_ABORTED_ERROR, f, NULL);
#endif
            XRAISE(MT_ABORTED_ERROR);
         }
         /* Add to abort in the middle of action, Karen Hsu, 2004/05/03, ADD END */

         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "SpecialKind: %d", f->SpecialKind);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILE_HANDLE);
         }

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_HANDLE, f, NULL);
#endif
            XRAISE(RTF_INVALID_FILE_HANDLE);
         }

         NamePattern = kal_dchar_strrchr(f->FullName, '\\')+2;
         A           = (void*) &f->LastCluster;
         Pos         = (void*) &f->Cluster;

         if ((A[0] == 0xFF) && (A[1] == 0xFF))
         {
/*#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_NO_MORE_FILES, NULL, NULL);
#endif*/
            XRAISE(RTF_NO_MORE_FILES);
         }

         if ( kal_dchar_strcmp(NamePattern, (char *)dchar_start_dot_star) == 0 )
            NamePattern += 4;

         while (1)
         {
            int Kind;
            const RTFDOSDirEntry * D = NextDir(f->Drive, Pos);

            if (D == NULL)
            {
/*#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_NO_MORE_FILES, NULL, NULL);
#endif*/
               XRAISE(RTF_NO_MORE_FILES);
            }

            Kind = EntryType(D);

            if (Kind == NeverUsed)
            {
/*#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_NO_MORE_FILES, NULL, NULL);
#endif*/
               XRAISE(RTF_NO_MORE_FILES);
            }
            else if (Kind == Lfn)
            {
               const LFNDirEntry * LD = (void*) D;

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
#endif

               if (LD->Ord & 0x40) // it's the start of an LFN
               {
                  // see if it fits
                  char * Limit;
                  LFNIndex = LD->Ord & 0x3F;
                  CheckSum = LD->CheckSum;

                  /* characters stored in the LFN entry are in 2-byte unicode*/
                  Limit = ( (char *)FileName) + ((LFNIndex-1)*13*2 + 2*LFNCharCount(LD) );
                  if (Limit > ( ((char *)FileName) + MaxLength - 1)) /* not able to hold */
                      LFNIndex = -1;
                  else
                  {
                     Limit[0] = '\0';
                     Limit[1] = '\0';
                  }
               }
               if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
                  LFNIndex = -1;
               else
                  CopyLFN((char *)FileName + --LFNIndex * 26, LD);
            }
            else if ((Kind == InUse) && ((D->Attributes & A[1]) == A[0]))
            {
               if (FileInfo != NULL)
                  *FileInfo = *D;

               /* Add LFN/SFN info for upper layer, Karen Hsu, 2004/4/28, MOD START */
               if (FileInfo != NULL)
                  FileInfo->NTReserved = MT_ENUM_FIND_NONE;

               // check against LFN first
               if ((LFNIndex == 0) && (CheckSum== ShortNameCheckSum((BYTE*) D->FileName)) && FileNamesMatch((WCHAR *)NamePattern, FileName))
               {
                  if (FileInfo != NULL)
                     FileInfo->NTReserved = MT_ENUM_FIND_LFN;

#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
#endif
                  break;
               }

               // try short name
               if ((MakeShortFileName(D, (char *)FileName, MaxLength) == RTF_NO_ERROR) )
               {
                  FileNameExtendToWCHAR((char *)FileName);
                  if ( FileNamesMatch((WCHAR *)NamePattern, FileName) )
                  {
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                     /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, Karen Hsu, ADD START */
                     if (FileInfo != NULL && FileInfo->FileName[0] == 0x05)
                        FileInfo->FileName[0] = 0xE5;
                     /* Fix 0xE5 special char will be treated as deleted, 2005/07/04, Karen, Hsu, ADD END */
                     if (FileInfo != NULL)
                        FileInfo->NTReserved = MT_ENUM_FIND_SFN;
                     NTReserved = D->NTReserved;
                     break;
                  }
               /* Add LFN/SFN info for upper layer, Karen Hsu, 2004/4/28, MOD END */
               }
            }
            if (Kind != Lfn)
               LFNIndex = -1;
         }
         MTCheckFileNameCase(FileName, MaxLength, NTReserved);
         break;
      default:
         break;
      case XFINALLY:
         if (f) UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
RTFHANDLE RTFAPI RTFFindFirstEx(const WCHAR * NamePattern, BYTE Attr, BYTE AttrMask, RTFDOSDirEntry * FileInfo, WCHAR * FileName, UINT MaxLength)
// the files must have at least all Attr1 attributes
// the files may not have any of Attr2
{
   int volatile Result;
   RTFile * volatile f = NULL;
   RTFDirLocation * Pos;
   BYTE * volatile A;

   XTRY
      case XCODE:
         f = ParseFileName((char *)NamePattern);
         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "SpecialKind: %d", f->SpecialKind);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         f->Flags = RTF_OPEN_DIR | RTF_READ_ONLY | RTF_CACHE_DATA;

         if (SearchFile(f, SEARCH_PARENT, (char *)NamePattern, NULL))  // it's a directory or file
         {
            if (f->DirEntry.DirCluster == 0) // there is no up level, it's the root
            {
               MakePseudoRootDirEntry(f->Drive, &f->DirEntry);
               if (FileInfo)
                  *FileInfo = f->DirEntry.Dir;
               setASCII(FileName, 0, '\\');
               setASCII(FileName, 1, 0);
               AttrMask = Attr = 0xFF; // special value for RTFFindNextEx
            }
            else
               SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->DirEntry.DirCluster);
         }
         // else we found the parent

         InitFilePointer(f);

         A    = (void*) &f->LastCluster;
         Pos  = (void*) &f->Cluster;
         Pos->Index--;
         A[0] = Attr;
         A[1] = AttrMask | Attr;

         Result = MakeNewFileHandle(f);

         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f != NULL)
         {
            if (Result < RTF_NO_ERROR)
               FreeFTSlotAndDevice(f);
            else
               UnlockDevice(f->Dev);
         }
         break;
   XEND_API

   if ((Result >= RTF_NO_ERROR) && (A[0] != 0xFF)  && (A[1] != 0xFF))
   {
      int R = RTFFindNextEx(Result, FileInfo, FileName, MaxLength);

      if (R == RTF_NO_ERROR)
         return Result;
      else
      {
         RTFFindClose(Result);
         return R;
      }
   }
   else
      return Result;
}

/*-----------------------------------*/
RTFHANDLE RTFAPI RTFFindFirst(const WCHAR * NamePattern, BYTE Attr1, BYTE Attr2, RTFDOSDirEntry * FileInfo, WCHAR * FileName)
// match ((A & Attr1) == Attr1) && ((A & Attr2) == 0)
{
   WCHAR Dummy[13];
   return RTFFindFirstEx(NamePattern, Attr1 & ~Attr2, Attr1 | Attr2, FileInfo, FileName ? FileName : Dummy, 13);
}

/*-----------------------------------*/
int RTFAPI RTFFindNext(RTFHANDLE Handle, RTFDOSDirEntry * FileInfo, WCHAR * FileName)
{
   WCHAR Dummy[13];
   return RTFFindNextEx(Handle, FileInfo, FileName ? FileName : Dummy, 13);
}

/*-----------------------------------*/
int RTFAPI RTFGetDiskInfoEx(const WCHAR * FileName, RTFDiskInfo * DiskInfo, int Flags)
{
   RTFile * volatile f = NULL;
   int volatile _Flags;
   RTFDrive * Drive;

   if (FileName == NULL)
      FileName = 0;

   _Flags = Flags & (RTF_DI_BASIC_INFO | RTF_DI_FREE_SPACE | RTF_DI_FAT_STATISTICS);

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);
         Drive = f->Drive;
         if (Drive == NULL)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (Drive->MountState < HasFileSystem)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)FileName);
#endif
            XRAISE(RTF_INVALID_FILE_SYSTEM);
         }

         memset(DiskInfo, 0, sizeof(RTFDiskInfo));

         /* Add for memory card write protection, Karen Hsu, 2004/04/14, MOD START */
         if(Drive->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
            DiskInfo->WriteProtect = 1;
         /* Add for memory card write protection, Karen Hsu, 2004/04/14, MOD END */

         if (_Flags & RTF_DI_BASIC_INFO)
         {
            DiskInfo->Label[0] = '\0';
            DiskInfo->DriveLetter = MT_BASE_DRIVE_LETTER + (Drive - gFS_Data.DriveTable);
            DiskInfo->Reserved[0] = '\0';
            DiskInfo->FirstPhysicalSector = Drive->FirstSector;
            DiskInfo->SerialNumber = Drive->SerialNumber;
            DiskInfo->FATType = Drive->FATType;
            DiskInfo->FATCount = Drive->FATCount;
            DiskInfo->MaxDirEntries = Drive->RootDirEntries;
            DiskInfo->BytesPerSector = Drive->Dev->DevData.SectorSize;
            DiskInfo->SectorsPerCluster = Drive->SectorsPerCluster;
            DiskInfo->TotalClusters = Drive->Clusters - 2;
         }

         if (_Flags & RTF_DI_FREE_SPACE)
         {
            if (Drive->FreeClusterCount == RTF_INVALID_CLUSTER)
            /* Adopt BatchCountFreeClusters for faster boot up on large size disk, WCP_SW , 2006/02/08, MOD START */
            {
               // _Flags |= RTF_DI_FAT_STATISTICS;
               BatchCountFreeClusters(Drive);
               DiskInfo->FreeClusters = Drive->FreeClusterCount;
            }
            /* Adopt BatchCountFreeClusters for faster boot up on large size disk, WCP_SW , 2006/02/08, MOD END */
            else
               DiskInfo->FreeClusters = Drive->FreeClusterCount;
           
            /* 2 member filled for usage convenience, WCP_SW , 2006/08/24, ADD START */
            DiskInfo->BytesPerSector = Drive->Dev->DevData.SectorSize;
            DiskInfo->SectorsPerCluster = Drive->SectorsPerCluster;
            /* 2 member filled for usage convenience, WCP_SW , 2006/08/24, ADD END */
         }

         if (_Flags & RTF_DI_FAT_STATISTICS)
         {
            RTFCluster i, Cluster, LastCluster, FreeCount;

            Drive->FreeClusterCount = FreeCount = 0;
            Drive->ClusterWatermark = LastCluster = RTF_INVALID_CLUSTER;

            for (i=2; i<Drive->Clusters; i++)
            {
               Cluster = GetClusterValue(Drive, i);
               if (Cluster == 0)
               {
                  Drive->FreeClusterCount++;
                  FreeCount++;
                  if (Drive->ClusterWatermark == RTF_INVALID_CLUSTER)
                     Drive->ClusterWatermark = i;
               }
               else if (Cluster == RTF_BAD_CLUSTER)
                  DiskInfo->BadClusters++;
               else if (Cluster >= RTF_CLUSTER_CHAIN_END)
                  DiskInfo->Files++;

               if ((Cluster != RTF_BAD_CLUSTER) &&
                    (Cluster > 0) &&
                    (LastCluster != i))
                  DiskInfo->FileChains++;

               if ((LastCluster == 0) && (Cluster != 0))
               {
                  if (FreeCount > DiskInfo->LargestFreeChain)
                     DiskInfo->LargestFreeChain = FreeCount;
                  DiskInfo->FreeChains++;
                  FreeCount = 0;
               }
               LastCluster = Cluster;
            }
            if (LastCluster == 0)
            {
               if (FreeCount > DiskInfo->LargestFreeChain)
                  DiskInfo->LargestFreeChain = FreeCount;
               DiskInfo->FreeChains++;
            }
            if (UpdateClusterWatermark(Drive, Drive->ClusterWatermark, 0) &&
                ((FileCount(Drive->Dev) == 0) || ((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0)))
               FlushAllBuffers(Drive->Dev);
            DiskInfo->FreeClusters = Drive->FreeClusterCount;
         }
         break;

      default:
         break;

      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
   XEND_API

   // get the volume label

   if (_Flags & RTF_DI_BASIC_INFO)
   {
      RTFHANDLE h;
      WCHAR Label[]={0x58,0x3a,0x5c,0x2a,0};
      RTFDOSDirEntry D;
      Label[0] = (WCHAR)DiskInfo->DriveLetter;
      h = RTFFindFirstEx(Label, RTF_ATTR_VOLUME, RTF_ATTR_DIR | RTF_ATTR_VOLUME, &D, (WCHAR *)DiskInfo->Label, sizeof(DiskInfo->Label));
      if (h >= RTF_NO_ERROR)
         RTFClose(h);
      else
         DiskInfo->Label[0] = '\0';
   }

   return _Flags;
}

/*-----------------------------------*/
int RTFAPI RTFGetDiskInfo(const WCHAR * FileName, RTFDiskInfo * DiskInfo)
{
   int Result = RTFGetDiskInfoEx(FileName, DiskInfo, RTF_DI_BASIC_INFO | RTF_DI_FREE_SPACE | RTF_DI_FAT_STATISTICS);
   return Result < RTF_NO_ERROR ? Result : RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetPartitionInfo(const WCHAR * DriveName, RTFPartitionInfo * PartitionInfo)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         memset(PartitionInfo, 0, sizeof(*PartitionInfo));
         f = ParseFileName((char *)DriveName);
         if (f->SpecialKind == PhysicalDisk)
            PartitionInfo->Partition = f->Dev->DevData.Geometry;
         else
            PartitionInfo->Partition = f->Drive->Geometry;
         PartitionInfo->MediaDescriptor   = f->Dev->DevData.MediaDescriptor;
         PartitionInfo->BytesPerSector    = f->Dev->DevData.SectorSize;
         PartitionInfo->PhysicalDiskIndex = f->Dev->DevData.PhysicalDiskIndex;
         PartitionInfo->DeviceListIndex   = f->Dev - gFS_DeviceList;
         if (f->Dev->DevData.MountState < Mounted)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_READY, NULL, (BYTE *)DriveName);
#endif
            XRAISE(RTF_DRIVE_NOT_READY);
         }
         if (PartitionInfo->Partition.Sectors == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_UNSUPPORTED_DRIVER_FUNCTION, NULL, (BYTE *)DriveName);
#endif
            XRAISE(RTF_UNSUPPORTED_DRIVER_FUNCTION);
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFGetCurrentDir(WCHAR * DirName, UINT MaxLength)
{
   RTFDrive * volatile Drive = NULL;

   if (RTFLock == NULL)
      RTFInit();

   XTRY
      case XCODE:
         if (DefaultDrive == NULL)
            DefaultDrive = FindDefaultDrive();
         else
            LockDevice(DefaultDrive->Dev, 0);

         Drive = DefaultDrive;

         if ((kal_dchar_strlen(Drive->CurrDir) + 2) > MaxLength)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_STRING_BUFFER_TOO_SMALL, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }

         kal_dchar_strcpy((char *)DirName, Drive->CurrDir);
         break;

      default:
         break;

      case XFINALLY:
         if (Drive) UnlockDevice(Drive->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFSetCurrentDir(const WCHAR * DirName)
{
   RTFile * volatile f = NULL;

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);
         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if ((SearchFile(f, SEARCH_FILES, (char *)DirName, NULL)) && (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR))
         {
            DefaultDrive = f->Drive;
            kal_dchar_strcpy(f->Drive->CurrDir, f->FullName);
            f->Drive->CurrDirEntry = f->DirEntry;
         }
         else
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_PATH_NOT_FOUND);
         }
         break;

      default:
         break;

      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFRemoveDir(const WCHAR * DirName)
{
   RTFile * volatile f = NULL;
   RTFDOSDirEntry * D;
   RTFDirLocation DSR;

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);

         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD START */
         if(f->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_WRITE_PROTECTION, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_WRITE_PROTECTION);
         }
         /* Fix write protect issue, Karen Hsu, 2004/04/07, ADD END */

         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (SearchFile(f, SEARCH_FILES, (char *)DirName, NULL) == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_PATH_NOT_FOUND);
         }

         CheckNotOpen(f);

         if ((f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) == 0)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_PATH_NOT_FOUND);
         }

         if (f->DirEntry.Dir.Attributes & RTF_ATTR_READ_ONLY)
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD START */
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, MT_READ_ONLY_ERROR, NULL, (BYTE *)DirName);
#endif
            XRAISE(MT_READ_ONLY_ERROR);
            //XRAISE(RTF_ACCESS_DENIED);
         }
            /* Change error message for FMT, Karen Hsu, 2004/04/20, MOD END */


         // do not remove the current directory
         if (SAME_DIR_ENTRY(f->DirEntry.ShortPos, f->Drive->CurrDirEntry.ShortPos))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }

         // do not remove the root
         if (kal_dchar_strlen(f->FullName) == 6)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }

         // check that the directory is empty
         // skip the first two . and .. entries
         D = StartDirSearch(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), 2, &DSR);

         while (D)
         {
            int Kind = EntryType(D);

            if (Kind == InUse)
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)DirName);
#endif
               XRAISE(RTF_ACCESS_DENIED);
            }
            else if (Kind == NeverUsed)
               break;
            D = NextDir(f->Drive, &DSR);
         }

         DeleteDirEntry(f);

         if (FIRST_FILE_CLUSTER(f->DirEntry.Dir) != 0)
         //quota
         {
            FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), f);
            //FATDelete(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir));
         }

         if (((f->Dev->DeviceFlags & RTF_DEVICE_LAZY_WRITE) == 0) || (FileCount(f->Dev) <= 1))
            FlushAllBuffers(f->Dev);

         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFCloseAll(void)
{
   int i;
   int R, Result = RTF_NO_ERROR;
   int Count = 0;
   RTFile * f;

   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
      if ((f->Lock != 0) && (f->Dev != NULL))
      {
         Count++;
         R = RTFClose((f->Unique << (4*sizeof(int))) | i);
         if (R < RTF_NO_ERROR)
            Result = R;
      }
   if (Result == RTF_NO_ERROR)
      return Count;
   else
      return Result;
}

/*------------------------------------------*/
/* Unlock all devices bruteforcily for exception cases */
int RTFAPI RTFUnlockAll(void)
{
   int i;
   int Count = 0;
   RTFile * f;

   for (i=0, f = gFS_Data.FileTable; i<FS_MAX_FILES; i++, f++)
      if ((f->Lock != 0) && (f->Dev != NULL))
      {
         Count++;
         UnlockDevice(f->Dev);
      }

   return Count;
}

/*-----------------------------------*/
int RTFAPI RTFCommitAll(const WCHAR * DriveName)
{
   RTFile * volatile f = NULL;
   RTFDevice * volatile Dev = NULL;

   XTRY
      case XCODE:
         if (DriveName != NULL)
         {
            f = ParseFileName((char *)DriveName);
            FlushAllBuffers(f->Dev);
         }
         else
         {
            RTFDevice * D;
            for (D = gFS_DeviceList; D->DeviceType; D++)
               if (D->DevData.MountState >= Mounted)
               {
                  LockDevice(D, 0); Dev = D;
                  FlushAllBuffers(D);
                  UnlockDevice(D); Dev = NULL;
               }
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f)   FreeFTSlotAndDevice(f);
         if (Dev) UnlockDevice(Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
int RTFAPI RTFResetDisk(const WCHAR * DriveName)
{
   RTFile * volatile f = NULL; /* Remove RVCT warning, Karen Hsu, 2004/11/02, ADD */

   if (RTFLock == NULL)
   {
      RTFInit();
      return RTF_NO_ERROR;
   }

   if (DriveName != NULL) // do just one physical drive
   XTRY
      //RTFile * volatile f = NULL; /* Remove RVCT warning, Karen Hsu, 2004/11/02, REM */
      case XCODE:
         f = ParseFileName((char *)DriveName);
         if (FileCount(f->Dev) > 1)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               kal_sprintf(TraceTmpBuf, "FileCount: %d", FileCount(f->Dev));
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, f, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }
         else
            UnmountDevice(f->Dev, 0);
         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   else // reset all devices
   XTRY
      RTFDevice * Dev;
      RTFDrive  * Drive;
      case XCODE:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
            if (Dev->DevData.MountState >= Mounted)
            {
               if (FileCount(Dev) > 0)
               {
#ifdef __FS_TRACE_SUPPORT__
                  if(g_TraceFlag & MT_TRACE_ERROR)
                     MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)DriveName);
#endif
                  XRAISE(RTF_ACCESS_DENIED);
               }
               else
                  UnmountDevice(Dev, 0);
            }
         // destroy the device -> drive and drive -> device information
         for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
            Dev->DevData.FirstDrive = NULL;
         for (Drive = gFS_Data.DriveTable; Drive < (gFS_Data.DriveTable + FS_MAX_DRIVES); Drive++)
         {
            Drive->Dev = NULL;
            Drive->NextDrive = NULL;
         }
         ScanDevices(); // this will not throw exceptions
         break;
      default:
         break;
      case XFINALLY:
         RTFSYSFreeMutex(RTFLock);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
void RTFAPI RTFShutDown(void)
{
   RTFDevice * Dev;

   if (RTFLock == NULL)
      return;

   /* if shutdown is called from exception writing, we should not flush cache or incur wirtes to flash */
   if (INT_QueryExceptionStatus() == KAL_FALSE)
   {
      RTFCloseAll();
   }

   RTFSYSLockMutex(RTFLock, RTF_INFINITE);
   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      if (Dev->DevData.MountState >= Mounted)
         UnmountDevice(Dev, 1);

   Dev--;

   for (; Dev >= gFS_DeviceList; Dev--)
      ShutDown(Dev);

   RTFSYSFreeMutex(RTFLock);
   RTFSYSFreeMutex(RTFLock);
}

/*-----------------------------------*/
RTFErrorAction RTFAPI RTFDefaultCriticalErrorHandler(WCHAR Drive, DWORD SerialNumber, int ErrorCode)
{
   return RTFFail;
}

#ifdef DIR_COMPACT_SUPPORT
/*-----------------------------------*/
static int INTERN CompactDir(RTFDrive * Drive, RTFCluster Cluster, DWORD Flags)
{
   RTFDirLocation DSR_I;
   RTFDOSDirEntry * D = StartDirSearch(Drive, Cluster, 0, &DSR_I);
   RTFDirLocation DSR_O = DSR_I;
   int i=0, o=0;
   int More = 1;
   RTFCluster LastCluster = 0;

   // copy used entries
   while (D)
   {
      int Kind = EntryType(D);

      if (Kind == NeverUsed)
         break;

      i++;
      if (Kind != Available)
      {
         o++;
         if (!SAME_DIR_ENTRY(DSR_I, DSR_O))
         {
            if ((Flags & RTF_CMPCT_READ_ONLY) == 0)
            {
               RTFDOSDirEntry Temp = *D;
               D = GetDir(Drive, &DSR_O);
               *D = Temp;
               SetDirty(Drive->Dev);
            }
         }
         if ((Kind == InUse) &&
             (D->Attributes & RTF_ATTR_DIR) &&
             (Flags & RTF_CMPCT_RECURSIVE) &&
             (memcmp((char*)D->FileName, ".  ", 3) != 0) &&
             (memcmp((char*)D->FileName, ".. ", 3) != 0))
         {
            i += CompactDir(Drive, FIRST_FILE_CLUSTER(*D), Flags);
         }
         LastCluster = DSR_O.Cluster;
         More = IncDir(Drive, &DSR_O);
      }
      D = NextDir(Drive, &DSR_I);
   }

   if (More)
   {
      // zero out slack
      D = GetDir(Drive, &DSR_O);
      while (D)
      {
         if (LastCluster && (DSR_O.Cluster != LastCluster))
         {
            if ((Flags & RTF_CMPCT_READ_ONLY) == 0)
            {
               SetClusterValue(Drive, LastCluster, RTF_CHAIN_END_MARK);
               //quota
               i += DIRS_PER_SECTOR(Drive) * Drive->SectorsPerCluster * FATDelete(Drive, DSR_O.Cluster, NULL);
               //i += DIRS_PER_SECTOR(Drive) * Drive->SectorsPerCluster * FATDelete(Drive, DSR_O.Cluster, NULL);
            }
            else
            {
               RTFCluster LastCluster;
               i += DIRS_PER_SECTOR(Drive) * Drive->SectorsPerCluster * FATClusterChainLength(Drive, DSR_O.Cluster, &LastCluster);
            }
            break;
         }
         if (D->FileName[0])
         {
            i++;
            if ((Flags & RTF_CMPCT_READ_ONLY) == 0)
            {
               memset((void*)D, 0, sizeof(*D));
               SetDirty(Drive->Dev);
            }
         }
         LastCluster = DSR_O.Cluster;
         D = NextDir(Drive, &DSR_O);
      }
   }
   return i-o;
}

/*-----------------------------------*/
int RTFAPI RTFCompactDir(const WCHAR * DirName, DWORD Flags)
{
   RTFile * volatile f = NULL;
   int volatile Result = 0;

   XTRY
      case XCODE:
         f = ParseFileName((char *)DirName);
         if (f->SpecialKind != NormalFile)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (((Flags & RTF_CMPCT_READ_ONLY) == 0) && (FileCountDrive(f->Drive) > 1))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }

         if ((SearchFile(f, SEARCH_FILES, (char *)DirName, NULL)) && (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR))
            Result = CompactDir(f->Drive, FIRST_FILE_CLUSTER(f->DirEntry.Dir), Flags);
         else
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)DirName);
#endif
            XRAISE(RTF_PATH_NOT_FOUND);
         }

         FlushAllBuffers(f->Dev);

         // the current dir's dir entry may have moved, find it again using an abs path
         if (((Flags & RTF_CMPCT_READ_ONLY) == 0) && (Result > 0))
         {
            if ((SearchFile(f, SEARCH_FILES, f->Drive->CurrDir, NULL)) && (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR))
               f->Drive->CurrDirEntry = f->DirEntry;
            else
            {
#ifdef __FS_TRACE_SUPPORT__
               if(g_TraceFlag & MT_TRACE_ERROR)
                  MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PATH_NOT_FOUND, NULL, (BYTE *)DirName);
#endif
               XRAISE(RTF_PATH_NOT_FOUND);
            }
         }

         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API
   return Result;
}

#endif // DIR_COMPACT_SUPPORT

#ifdef CHECK_DISK_SUPPORT

/*-----------------------------------*/
int RTFAPI RTFCheckDiskBufferSize(const WCHAR * DriveName)
// The buffer will hold a DiskCheckData structure followed by
// a sector buffer followed by
// a cluster bit map.
{
   RTFDiskInfo DI;
   int Result;

   if (DriveName == NULL)
      DriveName = 0;

   Result = RTFGetDiskInfoEx(DriveName, &DI, RTF_DI_BASIC_INFO);

   if (Result < RTF_NO_ERROR)
      return Result;

   return sizeof(DiskCheckData) + DI.BytesPerSector + (DI.TotalClusters+3) / 8 + 1;
}

/*-----------------------------------*/
static DWORD RTFAPI DummyChkDskHandler(DWORD Flags)
{
   return Flags;
}

static DWORD RTFAPI MTKChkDskHandler(DWORD Flags,
                                              const char * Path,
                                              const RTFDOSDirEntry * FileInfo,
                                              DWORD N1,
                                              DWORD N2)
{
   if (Flags & RTF_CHK_INVALID_CLUSTER)
     return RTF_CHK_INVALID_CLUSTER_DELETE;

   if (Flags & RTF_CHK_INVALID_DIR)
     return RTF_CHK_INVALID_DIR_DELETE;

   if (Flags & RTF_CHK_CROSSLINK)
     return RTF_CHK_CROSSLINK_DELETE;

   if (Flags & RTF_CHK_FILESIZE_SMALL)
     return RTF_CHK_FILESIZE_SMALL_DELETE;

   if (Flags & RTF_CHK_FILESIZE_LARGE)
     return RTF_CHK_FILESIZE_LARGE_DELETE;

   if (Flags & RTF_CHK_LONG_FILENAME)
     return RTF_CHK_LONG_FILENAME_DELETE;

   if (Flags & RTF_CHK_LOST_CLUSTER)
     return RTF_CHK_LOST_CLUSTER_FREE;

   return Flags;
}

/*-----------------------------------*/
static DWORD RTFAPI CallChkDskCallback(DiskCheckData * DCD,
                                       DWORD Mask,
                                       const char * Path,
                                       const RTFDOSDirEntry * FileInfo,
                                       DWORD N1,
                                       DWORD N2)
{
#ifdef __PRODUCTION_RELEASE__
   /* kick watchdog timer */
   WDT_Restart2();
#endif

   if (DCD->Flags & Mask)
   {
      DWORD Result;

      RTFSYSFreeMutex(RTFLock);
      Result = DCD->ErrorHandler(DCD->Flags & Mask, Path, FileInfo, N1, N2);
      RTFSYSLockMutex(RTFLock, RTF_INFINITE);
      return Result;
   }
   else
      return 0;
}

/*-----------------------------------*/
static void INTERN CheckFATMismatch(DiskCheckData * DCD)
{
   RTFSector i, FCount, S1, S2, SCount;

   if (DCD->Drive->FATCount == 1)
      return;

   for (SCount=0; SCount < DCD->Drive->SectorsPerFAT; SCount += FS_MAX_BUFFERS)
   {
      // preread primary FAT
      for (i=0; i<FS_MAX_BUFFERS; i++)
      {
         S1 = SCount + i;
         if (S1 >= DCD->Drive->SectorsPerFAT)
            break;
         GetBuffer(DCD->Drive->Dev, DCD->Drive->FirstFATSector + S1, 0);
      }

      // read fat copies and compare
      for (FCount=1; FCount < DCD->Drive->FATCount; FCount++)
         for (i=0; i<FS_MAX_BUFFERS; i++)
         {
            BYTE * FATPtr;

            S1 = SCount + i;
            if (S1 >= DCD->Drive->SectorsPerFAT)
               break;
            S2 = S1 + FCount*DCD->Drive->SectorsPerFAT;
            FATPtr = GetBuffer(DCD->Drive->Dev, DCD->Drive->FirstFATSector + S1, 0);
            ReadSectors(DCD->Drive->Dev, DCD->S, DCD->Drive->FirstFATSector + S2, 1, 0);
#ifdef __FS_DEBUG__
            BufferStat.UnbufferedReads++;
#endif
            if (memcmp(FATPtr, DCD->S, DCD->Drive->Dev->DevData.SectorSize) != 0)
               switch (CallChkDskCallback(DCD, RTF_CHK_FAT_MISMATCH_MASK, DCD->Path, NULL, DCD->Drive->FirstFATSector + S1, DCD->Drive->FirstFATSector + S2))
               {
                  case RTF_CHK_FAT_MISMATCH_1:     // use FAT 1
                     memcpy(DCD->S, FATPtr, DCD->Drive->Dev->DevData.SectorSize);
                     WriteSectors(DCD->Drive->Dev, DCD->S, DCD->Drive->FirstFATSector + S2, 1, 0, RTF_NORMAL_WRITE);
                     break;
                  case RTF_CHK_FAT_MISMATCH_2:     // use FAT 2
                     memcpy(FATPtr, DCD->S, DCD->Drive->Dev->DevData.SectorSize);
                     SetDirty(DCD->Drive->Dev);
                     break;
               }
         }
   }
}

/*-----------------------------------*/
static void INTERN ClearClusterMapChain(BYTE * ClusterMap, RTFDrive * Drive, RTFCluster Cluster, RTFCluster Count)
{
   while (Count--)
   {
      CLEAR_CLUSTER_BIT(ClusterMap, Cluster);
      Cluster = GetClusterValue(Drive, Cluster);
   }
}

/*-----------------------------------*/
RTFCluster RTFAPI SafeGetClusterValue(RTFDrive * Drive, RTFCluster Cluster)
//static RTFCluster INTERN SafeGetClusterValue(RTFDrive * Drive, RTFCluster Cluster)
// get a cluster value, but do not throw any exceptions
{
   RTFCluster volatile Result;

   XTRY
      case XCODE:
         Result = GetClusterValue(Drive, Cluster);
         break;
      default:
         XHANDLED;
         Result = 0;
         break;
      case XFINALLY:
         break;
   XENDX
   return Result;
}

/*----------- Check short filename -------------*/
int RTFAPI FileNameInvalid(const char * Name)
//static int INTERN FileNameInvalid(const char * Name)
{
   int i;

   if ((BYTE)(Name[0]) < (BYTE)' ')
      return 1;

   for (i=0; i<11; )
   {
      if (Name[i] & 0x80) /* native code ... skip to next character */
      {
         i += 2;
      }
      else
      {
         if (!IsValidShortNameChar(Name[i]) || (Name[i] == '.'))
           return 1;
         i++;
      }
   }
   return 0;
}

/*-----------------------------------*/
static int INTERN AttrInvalid(BYTE A, int IsInRoot)
{
   if (A & 0xC0) // 0x80 and 0x40 are undefined
      return 1;

   // volume labels outside the root are always invalid
   if (A & RTF_ATTR_VOLUME){
      if (!IsInRoot)
         return 1;
      else
         // if there is a volume label, it must have no other attrs set
         if (A & ~(RTF_ATTR_VOLUME | RTF_ATTR_ARCHIVE))
            return 1;
   }
   return 0;
}

/*-----------------------------------*/
static void INTERN LFNError(DiskCheckData * DCD, RTFDirLocation * LongPos, const RTFDirLocation * Pos)
// remove all dir entry between LongPos and (excluding) Pos
{
   switch (CallChkDskCallback(DCD, RTF_CHK_LONG_FILENAME_MASK, DCD->Path, NULL, 0, 0))
   {
     case RTF_CHK_LONG_FILENAME_REMOVE:
         DelLongDirEntry(DCD->Drive, LongPos, Pos);
         break;
     case RTF_CHK_LONG_FILENAME_DELETE:
         DelDirEntry(DCD->Drive, LongPos, Pos);
         break;
   }
   LongPos->Cluster = 0;
}

/*-----------------------------------*/
static int INTERN CheckDir(DiskCheckData * DCD, RTFDirLocation * LongPos, const RTFDirLocation * Pos, int Level)
// check DCD->D
// check a single directory entry
// level is 0 is for the root pseudo dir entry
{
   RTFCluster Parent, C;
   RTFCluster FATClusters = 0;

   // don't check "." and ".." entries
   if ((Pos->Index < 2) && ((memcmp((char*)DCD->D.FileName, ".          ", 8+3) == 0) ||
                            (memcmp((char*)DCD->D.FileName, "..         ", 8+3) == 0)))
      return RTF_NO_ERROR;

   // check non FAT dependent stuff in the dir entry
   C = FIRST_FILE_CLUSTER(DCD->D);
   if ((DCD->Flags & RTF_CHK_INVALID_DIR_MASK) && (Level > 0) &&
       (FileNameInvalid((char *)DCD->D.FileName)           ||       // valid file names chars /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
        AttrInvalid(DCD->D.Attributes, Level == 1) ||       // valid attribute
        (C == 1L) || (C >= DCD->Drive->Clusters)   ||       // valid start cluster
        ((DCD->D.Attributes & RTF_ATTR_DIR) && (C == 0L)))) // dirs must have a FAT chain
      switch (CallChkDskCallback(DCD, RTF_CHK_INVALID_DIR_MASK, DCD->Path, &DCD->D, 0, 0))
      {
         case RTF_CHK_INVALID_DIR_DELETE:
            DelDirEntry(DCD->Drive, LongPos, Pos);
            return RTF_NO_ERROR; // mo more checks on this entry
      }

   // go through the file's cluster chain
   // check for invalid FAT entries
   // check for crosslinks
   // markup cluster map
   // do not check fat12/16 root directories
   // but do take all files which have a cluster chain
   // this code does not physically free any space in the FAT
   // it merely leaves lost clusters behind
   // use the lost cluster check to recover this space
   Parent = RTF_INVALID_CLUSTER;
   C = FIRST_FILE_CLUSTER(DCD->D);
   if ((C != RTF_ROOT_DIR) && (C != 0))
      do {
#ifdef __PRODUCTION_RELEASE__
         /* kick watchdog timer */
         WDT_Restart2();
#endif
         if ((C < 2L) || (C >= DCD->Drive->Clusters))
            switch (CallChkDskCallback(DCD, RTF_CHK_INVALID_CLUSTER_MASK, DCD->Path, &DCD->D, (Parent == RTF_INVALID_CLUSTER) ? 0 : Parent, 0))
            {
               case RTF_CHK_INVALID_CLUSTER_TRUNC:
                  if (Parent != RTF_INVALID_CLUSTER)
                     SetClusterValue(DCD->Drive, Parent, C = RTF_CLUSTER_CHAIN_END);
                  else
                  // fall thru
               case RTF_CHK_INVALID_CLUSTER_DELETE:
                  {
                     DelDirEntry(DCD->Drive, LongPos, Pos);
                     return RTF_NO_ERROR; // no further checks on deleted files
                  }
            }

         if ((C < 2L) || (C >= DCD->Drive->Clusters))
            break; // can't do cross link check on invalid cluster

         if (CLUSTER_BIT(DCD->ClusterMap, C))
            switch (CallChkDskCallback(DCD, RTF_CHK_CROSSLINK_MASK, DCD->Path, &DCD->D, C, 0))
            {
               case RTF_CHK_CROSSLINK_TRUNC:
                  if (Parent != RTF_INVALID_CLUSTER)
                     SetClusterValue(DCD->Drive, Parent, C = RTF_CHAIN_END_MARK);
                  else
                  // fall thru
               case RTF_CHK_CROSSLINK_DELETE:
                  {
                     ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), FATClusters);
                     DelDirEntry(DCD->Drive, LongPos, Pos);
                     //quota
                     FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), NULL); /* Clear the chain */
                     //FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D)); /* Clear the chain */

                     return RTF_CHECKDISK_RETRY;
                  }
            }
         else
            SET_CLUSTER_BIT(DCD->ClusterMap, C);

         if ((C < 2L) || (C >= DCD->Drive->Clusters))
            break; // can't walk invalid cluster chain

         Parent = C;
         FATClusters++;
         C = SafeGetClusterValue(DCD->Drive, Parent);

      } while (C < RTF_CLUSTER_CHAIN_END);

   // check file sizes
   if ((DCD->D.Attributes & RTF_ATTR_DIR) == 0) // dirs do not have valid filesize
   {
      RTFCluster DirClusters = (DCD->D.FileSize > 0) ? ((DCD->D.FileSize-1) / DCD->Drive->ClusterSize) + 1 : 0;

#ifdef __PRODUCTION_RELEASE__
      /* kick watchdog timer */
      WDT_Restart2();
#endif
      if (FATClusters > DirClusters)
         switch (CallChkDskCallback(DCD, RTF_CHK_FILESIZE_SMALL_MASK, DCD->Path, &DCD->D, DCD->D.FileSize, FATClusters * DCD->Drive->ClusterSize))
         {
            case RTF_CHK_FILESIZE_SMALL_TRUNC:
               // too many FAT clusters
               // free superflous clusters
               // first, find beginning of to-free chain
               if (DirClusters > 0)
               {
                  RTFCluster i, Next;
                  C = FIRST_FILE_CLUSTER(DCD->D);
                  for (i=0; i < DirClusters-1; i++)
                     C = GetClusterValue(DCD->Drive, C);
                  Next = GetClusterValue(DCD->Drive, C);
                  SetClusterValue(DCD->Drive, C, RTF_CHAIN_END_MARK);
                  ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, Next, FATClusters - DirClusters);
               }
               else
               // fall through
            case RTF_CHK_FILESIZE_SMALL_DELETE:
               {
                  DelDirEntry(DCD->Drive, LongPos, Pos);
                  ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), FATClusters);
                  //quota
                  FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), NULL); /* Clear the chain */
                  //FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D)); /* Clear the chain */
                  return RTF_NO_ERROR;  // no further checks on deleted files
                }
         }
      else if (FATClusters < DirClusters)
         switch (CallChkDskCallback(DCD, RTF_CHK_FILESIZE_LARGE_MASK, DCD->Path, &DCD->D, DCD->D.FileSize, FATClusters * DCD->Drive->ClusterSize))
         {
            case RTF_CHK_FILESIZE_LARGE_TRUNC:
               // filesize in dir entry too large, truncate
               {
                  RTFDOSDirEntry * D = GetDir(DCD->Drive, Pos);
                  D->FileSize = FATClusters * DCD->Drive->ClusterSize;
                  SetDirty(DCD->Drive->Dev);
               }
               break;
            case RTF_CHK_FILESIZE_LARGE_DELETE:
               {
                  DelDirEntry(DCD->Drive, LongPos, Pos);
                  ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), FATClusters);
                  //quota
                  FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), NULL); /* Clear the chain */
                  //FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D)); /* Clear the chain */
                  /* if another file cross-links to the chain will have invalid clusters */
                  return RTF_NO_ERROR;
               }
         }
   }
   else // this is a directory, process its content
   {
      RTFDirLocation DSR;
      RTFDirLocation LDSR;
      RTFDOSDirEntry * D;
      char * pF = DCD->Path + kal_dchar_strlen(DCD->Path);
      BYTE CheckSum = 0; /* Remove RVCT warning, Karen Hsu, 2004/11/02, MOD */
      int LFNIndex;

      if (!compASCII(pF, -1, '\\') )
         setASCII(pF, 0, '\\');
      pF += 2;
      setASCII(pF, 0, '\0');

      /* Do not allow folder too deep, avoid stack overful, 2005/12/12, ADD START*/
      if (Level > MT_CHECKDISK_MAX_DEPTH)
      {
         DelDirEntry(DCD->Drive, LongPos, Pos);
         ClearClusterMapChain(DCD->ClusterMap, DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), FATClusters);
         FATDelete(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), NULL); /* Clear the chain */
         return RTF_NO_ERROR;
      }
      /* Do not allow folder too deep, avoid stack overful, 2005/12/12, ADD END*/

      CallChkDskCallback(DCD, RTF_CHK_VERBOSE, DCD->Path, NULL, 0, 0);

      D = StartDirSearch(DCD->Drive, FIRST_FILE_CLUSTER(DCD->D), 0, &DSR);
      LFNIndex = -1;
      LDSR.Cluster = 0;
      while (D != NULL)
      {
         int Kind = EntryType(D);

#ifdef __PRODUCTION_RELEASE__
         /* kick watchdog timer */
         WDT_Restart2();
#endif
         if (Kind == Lfn)
         {
            const LFNDirEntry * LD = (void*) D;
            if (LD->Ord & 0x40) // it's the start of an LFN
            {
               // see if it fits
               char * Limit;
               char * L;
               if (LDSR.Cluster)
                  LFNError(DCD, &LDSR, &DSR);
               LFNIndex = LD->Ord & 0x3F;
               CheckSum = LD->CheckSum;
               LDSR = DSR;
               Limit = pF + (LFNIndex-1)*13*2 + 2*LFNCharCount(LD);
               L = (char *)min(Limit, (DCD->Path+RTF_MAX_PATH-1));
               memset(pF, '?', L - pF);
               L[0] ='\0';
               L[1] ='\0';
               if (L < Limit)
                  LFNIndex = -1;
            }
            if ((LD->CheckSum != CheckSum) || (LFNIndex != (LD->Ord & 0x3F)))
               LFNIndex = -1;
            else
               CopyLFN(pF + --LFNIndex * 26, LD);
         }
         else if (LDSR.Cluster && (LFNIndex == -1))
         {
            LFNError(DCD, &LDSR, &DSR);
         }

         Kind = EntryType(D); /* reget entry type because the entry may be deleted */

         if (Kind == InUse)
         {
            if (LFNIndex != -1)
            {
               if ((LFNIndex != 0) ||
                   (CheckSum != ShortNameCheckSum((const BYTE*) D->FileName)))
               {
                  LFNError(DCD, &LDSR, &DSR);
                  LFNIndex = -1;
               }
            }

            if (LFNIndex == 0)
            {
               const WCHAR *p = (WCHAR *)pF;
               while (p[0])
                  if (!IsValidLongNameChar(*p++))
                  {
                     LFNError(DCD, &LDSR, &DSR);
                     LFNIndex = -1;
                     break;
                  }
            }

            DCD->D = *D;
            if (LFNIndex == -1)
            {
               if (MakeShortFileName(D, pF, DCD->Path + RTF_MAX_PATH - pF) != RTF_NO_ERROR)
                  switch (CallChkDskCallback(DCD, RTF_CHK_INVALID_DIR_MASK, DCD->Path, &DCD->D, 0, 0))
                  {
                     case RTF_CHK_INVALID_DIR_DELETE:
                        DelDirEntry(DCD->Drive, &LDSR, &DSR);
                        goto SkipDir;
                  }
            }

            if (CheckDir(DCD, &LDSR, &DSR, Level+1) == RTF_CHECKDISK_RETRY)
               return RTF_CHECKDISK_RETRY;
SkipDir:
            pF[0] = '\0';
            LFNIndex = -1;
            LDSR.Cluster = 0;
         }
         D = NextDir(DCD->Drive, &DSR);
      }
   }

   return RTF_NO_ERROR;
}

/*-----------------------------------*/
static void INTERN CheckLostClusters(DiskCheckData * DCD)
{
   RTFCluster i, C, Free;
   UINT State = 1;

   // mark up all free and bad clusters
   // count free clusters
   Free = 0;
   for (i=2; i < DCD->Drive->Clusters; i++)
   {
      if (!CLUSTER_BIT(DCD->ClusterMap, i))
         switch (SafeGetClusterValue(DCD->Drive, i))
         {
            case 0:
               Free++;
               // fall through
            case RTF_BAD_CLUSTER:
               SET_CLUSTER_BIT(DCD->ClusterMap, i);
               break;
         }
   }

   DCD->Drive->FreeClusterCount = Free;
   UpdateClusterWatermark(DCD->Drive, DCD->Drive->ClusterWatermark, 0);

   SET_CLUSTER_BIT(DCD->ClusterMap, DCD->Drive->Clusters); // one more to close the last chain

   // look for unmarked areas
   C = 0;
   for (i=2; i <= DCD->Drive->Clusters ; i++)
   {
      if (State != CLUSTER_BIT(DCD->ClusterMap, i))
      {
         if (State == 0) // end of a lost chain
         {
            switch (CallChkDskCallback(DCD, RTF_CHK_LOST_CLUSTER_MASK, DCD->Path, NULL, i-C, C))
            {
               case RTF_CHK_LOST_CLUSTER_FREE:
               {
                  RTFCluster j;
                  for (j=0; j < C; j++)
                     SetClusterValue(DCD->Drive, j+i-C, 0);
                  UpdateClusterWatermark(DCD->Drive, i, C);
               }
               break;
            }
         }
         State = !State;
         C = 0;
      }
      C++;
   }
}

/*-----------------------------------*/
int RTFAPI RTFCheckDisk(const WCHAR * DriveName,
                        void * Buffer,
                        UINT BufferSize,
                        RTFCheckDiskCallback ErrorHandler,
                        DWORD Flags)
{
   RTFile * volatile f = NULL;
   DiskCheckData * DCD;
   int result = RTF_NO_ERROR;

   if (DriveName == NULL)
      DriveName = 0;

   if (ErrorHandler == NULL)
      ErrorHandler = (RTFCheckDiskCallback) DummyChkDskHandler;

   if ((Buffer == NULL) || (BufferSize < RTFCheckDiskBufferSize(DriveName)))
      return MT_FAIL_GET_MEM;

   DCD = Buffer;
   DCD->Flags = Flags;
   DCD->S = (void*) (DCD+1);
   DCD->ErrorHandler = ErrorHandler;

   XTRY
      case XCODE:
         f = ParseFileName((char *)DriveName);
         if ((f->Drive == NULL) || (f->SpecialKind == PhysicalDisk))
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)DriveName);
#endif
            XRAISE(RTF_INVALID_FILENAME);
         }
         f->Flags = RTF_READ_WRITE;
         f->SpecialKind = Volume;
         CheckSharing(f);

         if (f->Drive->MountState < HasFileSystem)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILE_SYSTEM, NULL, (BYTE *)DriveName);
#endif
            XRAISE(RTF_INVALID_FILE_SYSTEM);
         }

         DCD->Drive = f->Drive;
         DCD->ClusterMap = (void*) (DCD->S + DCD->Drive->Dev->DevData.SectorSize);

         if (Flags & RTF_CHK_FAT_MISMATCH_MASK)
         {
            setASCII(DCD->Path, 0, '\\');
            setASCII(DCD->Path, 1, '\\');
            setASCII(DCD->Path, 2, '.');
            setASCII(DCD->Path, 3, '\\');
            setASCII(DCD->Path, 4, 'X');
            setASCII(DCD->Path, 5, ':');
            setASCII(DCD->Path, 6, '\0');
            DCD->Path[8] = MT_BASE_DRIVE_LETTER + (f->Drive - gFS_Data.DriveTable);
            CallChkDskCallback(DCD, RTF_CHK_VERBOSE, "checking FAT...", NULL, 0, 0);
            CheckFATMismatch(DCD);
         }

         if (Flags & (RTF_CHK_FILESIZE_SMALL_MASK | RTF_CHK_FILESIZE_LARGE_MASK | RTF_CHK_INVALID_DIR_MASK | RTF_CHK_LOST_CLUSTER_MASK | RTF_CHK_CROSSLINK_MASK))
         {
            RTFDirEntry Root;

            MakePseudoRootDirEntry(DCD->Drive, &Root);
            DCD->D = Root.Dir;

            DCD->Path[0] = MT_BASE_DRIVE_LETTER + (f->Drive - gFS_Data.DriveTable);
            DCD->Path[1] = 0;
            DCD->Path[2] = ':';
            DCD->Path[3] = 0;
            DCD->Path[4] = '\0';
            DCD->Path[5] = 0;

            memset(DCD->ClusterMap, 0, DCD->Drive->Clusters / 8 + 1);

            if (CheckDir(DCD, &Root.LongPos, &Root.ShortPos, 0) == RTF_CHECKDISK_RETRY)
            {
               result = RTF_CHECKDISK_RETRY;
               goto RTFCheckDisk_done;
            }

            if (Flags & RTF_CHK_LOST_CLUSTER_MASK)
            {
               CallChkDskCallback(DCD, RTF_CHK_VERBOSE, "searching lost clusters...", NULL, 0, 0);
               CheckLostClusters(DCD);
            }
         }

RTFCheckDisk_done:
        FlushAllBuffers(DCD->Drive->Dev);

      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
   XEND_API
   return result;
}

/*-----------------------------------*/
static const char CHKDSKDRV[] =  "Z\0:\0\\\0\\\0\0\0"; /* Z:\\ */
static const char CHKDSKFILE[] = "Z\0:\0\\\0\\\0m\0t\0k\0f\0l\0g\0\0\0"; /*Z:\\mtkflg */
#define CHKDSKATTR (RTF_ATTR_HIDDEN|RTF_ATTR_SYSTEM|RTF_CREATE_ALWAYS)
#define CHKFLAGNOTFOUND 0
#define CHKFLAGEXIST 1

/*-----------------------------------*/
static int RTFRecoverFlashDisk()
{
   int checkbytes = RTFCheckDiskBufferSize((const WCHAR*) CHKDSKDRV);
   char* checkbuffer;
   int result;

#ifdef _NAND_FLASH_BOOTING_
   checkbuffer = (char*)gFS_SanityCheckBuffer;
   ASSERT(checkbytes <= FS_MAX_CHECK_BUFFER);
#else
   checkbuffer = (char*)get_ctrl_buffer(checkbytes);
#endif

   do {
       result = RTFCheckDisk((const WCHAR*) CHKDSKDRV, (void *)checkbuffer, checkbytes, MTKChkDskHandler, \
                                RTF_CHK_INVALID_DIR     | \
                                RTF_CHK_INVALID_CLUSTER | \
                                RTF_CHK_CROSSLINK       | \
                                RTF_CHK_FILESIZE_SMALL  | \
                                RTF_CHK_FILESIZE_LARGE  | \
                                RTF_CHK_LONG_FILENAME   | \
                                RTF_CHK_LOST_CLUSTER      \
                      );

       if (result != RTF_CHECKDISK_RETRY) break;
    } while (1);

#ifndef _NAND_FLASH_BOOTING_
    if (checkbuffer) free_ctrl_buffer(checkbuffer);
#endif
    return result;
}

/*-----------------------------------*/
int RTFAPI RTFCheckDiskFlag(void)
//static int RTFCheckDiskFlag(void)
{
   RTFile * volatile f = NULL;
   int volatile retval =  CHKFLAGNOTFOUND;

   XTRY
      case XCODE:
         f = ParseFileName(CHKDSKFILE);
         f->Flags = CHKDSKATTR;

         if (SearchFile(f, SEARCH_FILES, CHKDSKFILE, NULL))
         {
            retval = CHKFLAGEXIST;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f) FreeFTSlotAndDevice(f);
         break;
   XEND_API

   return retval;
}
/*-----------------------------------*/
int RTFAPI RTFCheckBootUpFlag(void)
{
   int volatile retval =  CHKFLAGNOTFOUND;
   RTFDrive * Drive;
   RTFCluster cvalue;

   XTRY
      case XCODE:        
         Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);                   
         if (Drive->MountState < HasFileSystem)
         {
            break;
         }

         gMT_Sanity = KAL_TRUE;
         cvalue = GetClusterValue(Drive, 1);
         gMT_Sanity = KAL_FALSE;
         switch(Drive->FATType)
         {
            case RTFAT12:
               if (cvalue & 0x800)
               {
                  retval = CHKFLAGEXIST;
               }
               break;
            case RTFAT16:
               if (cvalue & 0x8000)
               {
                  retval = CHKFLAGEXIST;
               }
               break;
            case RTFAT32:
               if (cvalue & 0x08000000)
               {
                  retval = CHKFLAGEXIST;
               }
            default:
               break;
         }
         break;
      default:
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);   
         break;
   XEND_API

   return retval;
}

/*-----------------------------------*/
int RTFAPI RTFSetBootUpFlag(kal_bool bSet)
{
   int Result = RTF_NO_ERROR;
   RTFDrive * Drive;
   RTFCluster ovalue;

   XTRY
      case XCODE:        
         Drive = &gFS_Data.DriveTable[(BYTE)DrvMappingOld - MT_BASE_DRIVE_LETTER];
         SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);                   
         if (Drive->MountState < HasFileSystem)
         {
            break;
         }
   
         gMT_Sanity = KAL_TRUE;
         FlushAllBuffers(Drive->Dev); // to avoid FAT or file content error
         ovalue = GetClusterValue(Drive, 1);
         if (bSet == KAL_TRUE)
         {
            switch(Drive->FATType)
            {
               case RTFAT12:   ovalue  |=      0x800; break;
               case RTFAT16:   ovalue  |=     0x8000; break;
               case RTFAT32:   ovalue  |= 0x08000000; break;
               default:                               break;
            }
         }
         else
         {
            switch(Drive->FATType)
            {
               case RTFAT12:   ovalue  &=     ~0x800; break;
               case RTFAT16:   ovalue  &=    ~0x8000; break;
               case RTFAT32:   ovalue  &=~0x08000000; break;
               default:                               break;
            }
         }
         
         SetClusterValue(Drive, 1, ovalue);
         gMT_Sanity = KAL_FALSE;
         FlushAllBuffers(Drive->Dev);
         break;
      default:
         break;
      case XFINALLY:
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);   
         break;
   XEND_API

   return Result;
}

/*-----------------------------------*/
int RTFAPI RTFSetDiskFlag(void)
{
   RTFHANDLE File;

   RTFSetBootUpFlag(KAL_TRUE);

   File = RTFOpen((const WCHAR*) CHKDSKFILE, CHKDSKATTR);
   return RTFClose(File);
}

/*-----------------------------------*/
int RTFAPI RTFSanityCheck(void)
{
   int result;

   result = RTFCheckDiskFlag();
   if (result == CHKFLAGNOTFOUND)
   {
      result = RTFCheckBootUpFlag();
   }

   if (result == CHKFLAGEXIST)
   {
     gMT_Sanity = KAL_TRUE;
     result = RTFRecoverFlashDisk();
     gMT_Sanity = KAL_FALSE;
     if (result != RTF_NO_ERROR)
        return result;
   }
   else
   {
      result = RTFSetBootUpFlag(KAL_TRUE);
   }

#ifdef __PRODUCTION_RELEASE__
   /* kick watchdog timer */
   WDT_Restart2();
#endif

   return result;
}

/*-----------------------------------*/
int RTFAPI RTFClearDiskFlag(void)
{
   int Result = RTF_NO_ERROR;

   if (RTFCheckBootUpFlag() == CHKFLAGEXIST)
   {
      Result = RTFSetBootUpFlag(KAL_FALSE);
   }
   if (RTFCheckDiskFlag() == CHKFLAGEXIST)
   {
      //return RTFDelete((const WCHAR*) CHKDSKFILE);
      Result = RTFDelete((const WCHAR*) CHKDSKFILE);

/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD START */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
      FlushShadowFAT();
#endif
/* Add for SHADOW FAT, Karen Hsu, 2005/05/11, ADD END */
   }
   return Result;
}

#endif // CHECK_DISK_SUPPORT

/* MTK Internal Enhancement, Karen Hsu, ADD START */
/*************************************************/

/* Promise task only takes one lock */
int RTFAPI SafeLock(DWORD Lock, RTFDevice * Dev, DWORD Timeout)
{
   int Result = RTF_NO_ERROR;

   if(kal_query_systemInit() == KAL_TRUE) //for sanity check
      return Result;

   if(Lock & MT_LOCK_DEV)
   {
      if((Dev) && (Dev->DeviceType & (RTF_DEVICE_FDISK | RTF_DEVICE_REMOVABLE)))
      {
         Result = RTFSYSLockMutex(Dev->DevData.Lock, Timeout);
         if(Result < RTF_NO_ERROR)
            return Result;
         while(Dev->DevData.Lock->rtf_lock_count > 1)
            RTFSYSFreeMutex(Dev->DevData.Lock);
      }
   }

   if(Lock & MT_LOCK_RTF)
   {
      if (RTFLock == NULL)
         RTFInit();

      Result = RTFSYSLockMutex(RTFLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(RTFLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(RTFLock);
   }

   if(Lock & MT_LOCK_FMT)
   {
      Result = RTFSYSLockMutex(MTFMLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTFMLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTFMLock);
   }

   if(Lock & MT_LOCK_EXT)
   {
      Result = RTFSYSLockMutex(MTXLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTXLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTXLock);
   }

#ifdef __FS_MOVE_SUPPORT__
   if(Lock & MT_LOCK_MOVE)
   {
      Result = RTFSYSLockMutex(MTMoveLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTMoveLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTMoveLock);
   }
#endif

   if(Lock & MT_LOCK_XDEL)
   {
      Result = RTFSYSLockMutex(MTXdelLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTXdelLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTXdelLock);
   }

#ifdef __FS_SORT_SUPPORT__
   if(Lock & MT_LOCK_SORT)
   {
      Result = RTFSYSLockMutex(MTSortLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTSortLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTSortLock);
   }
#endif

#ifdef __FS_TRACE_SUPPORT__
   if(Lock & MT_LOCK_TRACE)
   {
      Result = RTFSYSLockMutex(MTTraceLock, Timeout);
      if(Result < RTF_NO_ERROR)
         return Result;
      while(MTTraceLock->rtf_lock_count > 1)
         RTFSYSFreeMutex(MTTraceLock);
   }
#endif

   return Result;
}

/* Promise task exits without holding lock */
int RTFAPI SafeUnlock(DWORD Lock)
{
   int Result = RTF_NO_ERROR;
   RTFDevice * Dev;

   if(kal_query_systemInit() == KAL_TRUE) //for sanity check
      return Result;

   if((Lock & MT_LOCK_RTF) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(RTFLock) == KAL_TRUE)
         RTFSYSFreeMutex(RTFLock);
   }

   if((Lock & MT_LOCK_DEV) || (Lock & MT_LOCK_ALL))
   {
      for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
      {
         while(RTFSYSOwnMutex(Dev->DevData.Lock) == KAL_TRUE)
         {
            if (Dev->DevData.B)
               FreeBuffer(Dev);
            RTFSYSFreeMutex(Dev->DevData.Lock);
         }
      }
   }

   if((Lock & MT_LOCK_FMT) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTFMLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTFMLock);
   }

   if((Lock & MT_LOCK_EXT) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTXLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTXLock);
   }

#ifdef __FS_MOVE_SUPPORT__
   if((Lock & MT_LOCK_MOVE) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTMoveLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTMoveLock);
   }
#endif

   if((Lock & MT_LOCK_XDEL) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTXdelLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTXdelLock);
   }

#ifdef __FS_SORT_SUPPORT__
   if((Lock & MT_LOCK_SORT) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTSortLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTSortLock);
   }
#endif

#ifdef __FS_TRACE_SUPPORT__
   if((Lock & MT_LOCK_TRACE) || (Lock & MT_LOCK_ALL))
   {
      while(RTFSYSOwnMutex(MTTraceLock) == KAL_TRUE)
         RTFSYSFreeMutex(MTTraceLock);
   }
#endif

   return Result;
}

/*************************************************/
/* MTK Internal Enhancement, Karen Hsu, ADD END */

/* MTK External Enhancement, Karen Hsu, ADD START */
/*************************************************/
/*------------------------------------------------------------------ */
static const int DriveMapTBL[] = 
{                       /* Pub 1, Pub 2, Sys 1, Sys 2 */
   /* NOR:NAND = 1:0 */      0x0,   0x0,  0x43,  0x0,   /* 0 0 C 0 */
   /* NOR:NAND = 2:0 */     0x43,   0x0,  0x44,  0x0,   /* C 0 D 0 */
   /* NOR:NAND = 0:1 */      0x0,   0x0,  0x43,  0x0,   /* 0 0 C 0 */
   /* NOR:NAND = 1:1 */     0x44,   0x0,  0x43,  0x0,   /* D 0 C 0 */
   /* NOR:NAND = 2:1 */     0x43,  0x44,  0x45,  0x0,   /* C D E 0 */
   /* NOR:NAND = 0:2 */     0x43,   0x0,  0x44,  0x0,   /* C 0 D 0 */
   /* NOR:NAND = 1:2 */     0x44,   0x0,  0x43, 0x45,   /* D 0 C E */
   /* NOR:NAND = 2:2 */     0x43,  0x44,  0x45, 0x46    /* C D E F */
};

int RTFAPI MTGetDrive(DWORD Type, DWORD Serial, DWORD AltMask)
{
   UINT Count = 0;
   UINT NORCount = 0, NANDCount = 0, ExtCount = 0, CardCount = 0, SPlusCount = 0;
   int  Result = 0, TBLidx = -1;

#define DEVTYPE_ALL_FLAGS (MT_DRIVE_I_SYSTEM | MT_DRIVE_V_NORMAL | MT_DRIVE_V_REMOVABLE | MT_DRIVE_V_EXTERNAL | MT_DRIVE_V_SIMPLUS)
   /* MTGetDrive - 1 Check parameter */
   if(((Type & DEVTYPE_ALL_FLAGS) == 0) ||
      ((Type & ~DEVTYPE_ALL_FLAGS) != 0) ||
      ((Type & (MT_DRIVE_I_SYSTEM | MT_DRIVE_V_NORMAL)) && (Serial > 2)) ||
      ((Type == MT_DRIVE_V_REMOVABLE) && (Serial > 2)) ||
      ( Serial < 1) ||
      ((AltMask != MT_NO_ALT_DRIVE) && (AltMask & MT_NO_ALT_DRIVE)) ||
      ((AltMask != MT_ONLY_ALT_SERIAL) && (AltMask & MT_ONLY_ALT_SERIAL)) ||
       (AltMask & MT_DRIVE_V_EXTERNAL) )
   {
      return RTF_PARAM_ERROR;
   }
#undef DEVTYPE_ALL_FLAGS

   /* MTGetDrive - 2 Count Drive in each type */
   SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);

   for(Count = MT_BASE_DRIVE_INDEX; Count < FS_MAX_DRIVES; Count++)
   {
      if(gFS_Data.DriveTable[Count].Dev != NULL)
      {
         if(gFS_Data.DriveTable[Count].Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
         {
            NORCount++;
            ASSERT(NORCount < 3);
         }
         else if(gFS_Data.DriveTable[Count].Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
         {
            NANDCount++;
            ASSERT(NANDCount < 3);
         }
         else if((gFS_Data.DriveTable[Count].Dev->DeviceFlags & (RTF_DEVICE_REMOVABLE | MT_DEVICE_EXTERNAL | MT_DEVICE_SIMPLUS)) == RTF_DEVICE_REMOVABLE)
         {
            CardCount++;
            ASSERT(CardCount < 3);
         }
         else if(gFS_Data.DriveTable[Count].Dev->DeviceFlags & MT_DEVICE_SIMPLUS)
         {
            SPlusCount++;
            ASSERT(SPlusCount < 5);
         }
         else if(gFS_Data.DriveTable[Count].Dev->DeviceFlags & MT_DEVICE_EXTERNAL)
         {
            ExtCount++;
         }
      }
      else
         break;
   }

   Count = NORCount + NANDCount;
   ASSERT((Count > 0) && (Count < 5));

#ifndef _NAND_FLASH_BOOTING_
   ASSERT(NORCount > 0);
#endif

#ifdef __FS_SHADOW_NAND__
   ASSERT(NANDCount < 2);
#endif

#ifdef __FS_SHADOW_CARD__
   ASSERT(CardCount < 2);
#endif

   /* Calculate TBLidx BASE */
   TBLidx = (NORCount + NANDCount * 3 - 1) * 4;
   /* 1 0 => 0; 0 1 => 2; 0 2 => 5 */

   /* Match type first */
   switch (Type)
   {
      case MT_DRIVE_I_SYSTEM: /* Match system drive */
         if(DriveMapTBL[TBLidx + 2 + Serial - 1] != 0x0)
         {
            Result = DriveMapTBL[TBLidx + 2 + Serial - 1];
            goto getReturn;
         }
         break;
      case MT_DRIVE_V_NORMAL: /* Match normal drive */
         if(DriveMapTBL[TBLidx + 0 + Serial - 1] != 0x0)
         {
            Result = DriveMapTBL[TBLidx + 0 + Serial - 1];
            goto getReturn;
         }
         break;
      case MT_DRIVE_V_REMOVABLE: /* Match removable drive */
         if(Serial <= CardCount)
         {
            Result = MT_BASE_DRIVE_LETTER + Count + Serial - 1;
            goto getReturn;
         }
         break;
      case MT_DRIVE_V_SIMPLUS: /* Match SIMPLUS drive ; No alternative match */
         if(Serial <= SPlusCount)
         {
            Result = MT_BASE_DRIVE_LETTER + Count + CardCount + Serial - 1;
         }
         else
         {
            Result = RTF_DRIVE_NOT_FOUND;
         }
         goto getReturn;
      case MT_DRIVE_V_EXTERNAL: /* Match external drive ; No alternative match */
         if(Serial <= ExtCount)
         {
            Result = MT_BASE_DRIVE_LETTER + Count + CardCount + SPlusCount + Serial - 1;
         }
         else
         {
            Result = RTF_DRIVE_NOT_FOUND;
         }
         goto getReturn;
      default:
         Result = RTF_PARAM_ERROR;
         goto getReturn;
   }//end of switch

   if(AltMask & MT_NO_ALT_DRIVE)
   {
      Result = RTF_DRIVE_NOT_FOUND;
      goto getReturn;
   }

   /* Match serial then */
   if(AltMask & MT_ONLY_ALT_SERIAL)
   {
      switch (Type)
      {
         case MT_DRIVE_I_SYSTEM: /* Match system drive */
            if((Serial == 2) && (DriveMapTBL[TBLidx + 2] != 0x0))
            {
               Result = DriveMapTBL[TBLidx + 2];
               goto getReturn;
            }
            else if ((Serial == 1) && (DriveMapTBL[TBLidx + 3] != 0x0))
            {
               Result = DriveMapTBL[TBLidx + 3];
               goto getReturn;
            }
            break;
         case MT_DRIVE_V_NORMAL: /* Match normal drive */
            if((Serial == 1) && (DriveMapTBL[TBLidx + 1] != 0x0))
            {
               Result = DriveMapTBL[TBLidx + 1];
               goto getReturn;
            }
            else if((Serial == 2) && (DriveMapTBL[TBLidx + 0] != 0x0))
            {
               Result = DriveMapTBL[TBLidx + 0];
               goto getReturn;
            }
            break;
         case MT_DRIVE_V_REMOVABLE: /* Match removable drive */
            if (CardCount > 0)
            {
               Result = MT_BASE_DRIVE_LETTER + Count + CardCount - 1;
               goto getReturn;
            }
            break;
         default:
            Result = RTF_PARAM_ERROR;
            goto getReturn;
      }//end of switch
   }

   /* Match other alter last */
   if((DriveMapTBL[TBLidx + 1]) && (AltMask & MT_DRIVE_V_NORMAL))
   {
      Result = DriveMapTBL[TBLidx + 1];
   }
   else if((DriveMapTBL[TBLidx + 0]) && (AltMask & MT_DRIVE_V_NORMAL))
   {
      Result = DriveMapTBL[TBLidx + 0];
   }
   else if((CardCount > 0) && (AltMask & MT_DRIVE_V_REMOVABLE))
   {
      Result = MT_BASE_DRIVE_LETTER + Count + CardCount - 1;
   }
   else if((DriveMapTBL[TBLidx + 3]) && (AltMask & MT_DRIVE_I_SYSTEM))
   {
      Result = DriveMapTBL[TBLidx + 3];
   }
   else if((DriveMapTBL[TBLidx + 2]) && (AltMask & MT_DRIVE_I_SYSTEM))
   {
      Result = DriveMapTBL[TBLidx + 2];
   }

getReturn:
   SafeUnlock(MT_LOCK_RTF);

   if(Result)
      return Result;

#ifdef __FS_TRACE_SUPPORT__
   if(g_TraceFlag & MT_TRACE_ERROR)
      MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_DRIVE_NOT_FOUND, NULL, NULL);
#endif
   return RTF_DRIVE_NOT_FOUND;
}

/*------------------------------------------------------------------ */
int RTFAPI MTMappingDrive(DWORD UpperOldDrv, DWORD UpperNewDrv)
{
   if(RTFLock == NULL)
      return RTF_DRIVE_NOT_READY;

   if((UpperOldDrv < 67) || (UpperOldDrv > (FS_MAX_DRIVES + MT_BASE_DRIVE_LETTER - 1)) ||
      (UpperNewDrv < (FS_MAX_DRIVES + MT_BASE_DRIVE_LETTER)) || (UpperNewDrv > 90) || (UpperNewDrv == 88))
      return RTF_PARAM_ERROR;

   SafeLock(MT_LOCK_RTF, NULL, RTF_INFINITE);
   DrvMappingFlag = 1;
   DrvMappingOld = UpperOldDrv;
   DrvMappingNew = UpperNewDrv;
   SafeUnlock(MT_LOCK_RTF);
   return RTF_NO_ERROR;
}

/*------------------------------------------------------------------ */
#ifdef __FS_TRACE_SUPPORT__

void RTFAPI MTSetTrace(DWORD Flag, DWORD Timeout)
{
   BYTE i;
   int Result;

   if(RTFLock == NULL)
      RTFInit();

   if(MTTraceLock == NULL)
      MTTraceLock = RTFSYSAllocMutex("MTTraceLock");

   Result = SafeLock(MT_LOCK_TRACE, NULL, Timeout);
   if(Result < RTF_NO_ERROR)
      return;

   if(Flag & MT_TRACE_DISABLE)
   {
      g_TraceFlag = 0;
      for(i = 0; i < FS_MAX_THREAD; i++)
      {
         gFS_TraceTask[i][0] = KAL_FALSE;
         if(Timeout == RTF_INFINITE)
            gFS_TraceTask[i][1] = KAL_TRUE;
         else
            gFS_TraceTask[i][1] = KAL_FALSE;
      }
      return;
   }
   else if(Flag & MT_TRACE_ALL_TASK)
   {
      for(i = 0; i < FS_MAX_THREAD; i++)
      {
         gFS_TraceTask[i][0] = KAL_TRUE;
         if(Timeout == RTF_INFINITE)
            gFS_TraceTask[i][1] = KAL_TRUE;
         else
            gFS_TraceTask[i][1] = KAL_FALSE;
      }
   }
   else
   {
      for(i = 0; i < FS_MAX_THREAD; i++)
         if(kal_get_current_thread_ID() == gFS_TaskList[i])
         {
            gFS_TraceTask[i][0] = KAL_TRUE;
            if(Timeout == RTF_INFINITE)
               gFS_TraceTask[i][1] = KAL_TRUE;
            else
               gFS_TraceTask[i][1] = KAL_FALSE;
            break;
         }
   }
   g_TraceFlag = Flag;

   SafeUnlock(MT_LOCK_TRACE);
}

#endif

/*------------------------------------------------------------------ */
#ifdef __FS_TRACE_SUPPORT__

void RTFAPI MTTraceFS(DWORD TaskId, DWORD FileCode, DWORD Line, int Code,
                      RTFile * f, BYTE * TraceStr)
{
   DWORD i = 0, j = 0, k = 0;
   int AppendLen, Result;
   kal_bool SendAgain = KAL_TRUE;

   if((kal_query_systemInit() == KAL_TRUE) || (TaskId == NULL))
      return;

   if(MTTraceLock == NULL)
      MTTraceLock = RTFSYSAllocMutex("MTTraceLock");

   for(k = 0; k < FS_MAX_THREAD; k++)
      if(TaskId == (DWORD)gFS_TaskList[k])
      {
         if(gFS_TraceTask[k][0] == KAL_FALSE)
         {
               return;
         }
         else
         {
            if(gFS_TraceTask[k][1] == KAL_TRUE)
               SafeLock(MT_LOCK_TRACE, NULL, RTF_INFINITE);
            else
            {
               Result = SafeLock(MT_LOCK_TRACE, NULL, RTF_NO_WAIT);
               if(Result < RTF_NO_ERROR)
               {
                  return;
               }
            }
         }
         break;
      }

   memset(TraceStrBuf, 0, MAX_TRACE_STR_LEN);
   if(Code >= RTF_NO_ERROR)
      kal_sprintf(TraceStrBuf, "[FS: API]Task(0x%x) ", TaskId);
   else if(FileCode == 1)
      kal_sprintf(TraceStrBuf, "[FS: ERR]%d#%d@fs> Task(0x%x) ", Code, Line, TaskId);
   else if(FileCode == 2)
      kal_sprintf(TraceStrBuf, "[FS: ERR]%d#%d@Efs1> Task(0x%x) ", Code, Line, TaskId);
   else if(FileCode == 3)
      kal_sprintf(TraceStrBuf, "[FS: ERR]%d#%d@Efs2> Task(0x%x) ", Code, Line, TaskId);
   else
      kal_sprintf(TraceStrBuf, "[FS: ERR]%d#%d@unknown> Task(0x%x) ", Code, Line, TaskId);

   k = strlen((char *)TraceStrBuf);
   if(TraceStr != NULL)
   {
      AppendLen = MAX_TRACE_STR_LEN - k;
      if (AppendLen)
      {
         for(j = 0; j < MT_TRACE_TMP_LEN; j++)
         {
            if(TraceStr[j] != NULL)
            {
               TraceStrBuf[k] = TraceStr[j];
               k++;
               i++;
            }
            else if(TraceStr[j+1] == NULL)
               break;
            if(i == AppendLen)
               break;
         }
      }
   }

   if(f != NULL)
   {
      memset(TraceTmpBuf, 0, MT_TRACE_TMP_LEN);
      if(f->Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
      {
         kal_sprintf((char *)TraceTmpBuf, " (Access NOR: ");
      }
      else if(f->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
      {
         kal_sprintf((char *)TraceTmpBuf, " (Access NAND: ");
      }
      else if(f->Dev->DeviceFlags & MT_DEVICE_EXTERNAL)
      {
         kal_sprintf((char *)TraceTmpBuf, " (Access EXT: ");
      }
      else
      {
         kal_sprintf((char *)TraceTmpBuf, " (Access Card: ");
      }
      i = strlen((char *)TraceTmpBuf);
      kal_mem_cpy((void *)(TraceTmpBuf + i), (void *)(f->DirEntry.Dir.FileName), 11);
      i = strlen((char *)TraceTmpBuf);
      kal_sprintf(TraceTmpBuf + i, ")");
      
      i = 0;
      AppendLen = MAX_TRACE_STR_LEN - strlen((char *)TraceStrBuf);
      if (AppendLen)
      {
         while(TraceTmpBuf[i])
         {
            if(i == AppendLen)
               break;
            TraceStrBuf[k] = TraceTmpBuf[i];
            k++;
            i++;
         }
      }
   }
   TraceStrBuf[strlen((char *)TraceStrBuf)] = 0x00;

   tst_sys_trace((kal_uint8 *)TraceStrBuf);

   switch(Code)
   {
      case RTF_ACCESS_DENIED:
      case RTF_TOO_MANY_FILES:
      case RTF_ERROR_RESERVED:
         j = 0;
         for (i=0, f = gFS_Data.FileTable; i < FS_MAX_FILES; i++, f++)
         {
            if((i % 3) == 0)
            {
               j++;
               if(i > 0)
               {
                  tst_sys_trace((kal_uint8 *)TraceStrBuf);
                  SendAgain = KAL_FALSE;
               }
               memset(TraceStrBuf, 0, strlen((char *)TraceStrBuf));
               kal_sprintf(TraceStrBuf, "[FS: File Table %d]", j);
            }
            kal_sprintf(TraceStrBuf, "%sTask(0x%x)%s?", TraceStrBuf, (int) f->Task,
                        f->DirEntry.Dir.FileName);
            SendAgain = KAL_TRUE;
         }
         if(SendAgain == KAL_TRUE)
            tst_sys_trace((kal_uint8 *)TraceStrBuf);
         break;
      default:
         break;
   }
   SafeUnlock(MT_LOCK_TRACE);
}

#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

/* Get the specific quota entry from gFS_ExtQuotaSet */
static void GetQuotaEntry(int * Index, RTFile * f)
{
   int i, j, k;

   ASSERT(f != NULL);

   for(i = FS_MAX_QSET - 1 ; i >= 0 ; i--)
   {
      for(j = 0; j < RTF_MAX_PATH; j++)
      {
         if((j & 0x01) && (f->FullName[j] != 0x00)) break;
         else k = j / 2;

         if(gFS_ExtQuotaSet[i].Path[k] == 0x00) //match
         {
            if(gFS_ExtQuotaSet[i].Path[k+1] == 0x00)
            {
               *Index = i;
               return;
            }
         }

         if(f->FullName[j] == 0x00)
         {
            if(f->FullName[j+1] == 0x00)
            {
               if(gFS_ExtQuotaSet[i].Path[k+1] == 0x5C) //match
               {
                  *Index = i;
                  return;
               }
               break;
            }
         }
         else
         {
            if(gFS_ExtQuotaSet[i].Path[k] != 0x00)
            {
               if(k || j)
               {
                  if(gFS_ExtQuotaSet[i].Path[k] != f->FullName[j])
                     break;
               }
               else if(gFS_ExtQuotaSet[i].Path[k] == (BYTE)DrvMappingNew)
               {
                  if((BYTE)DrvMappingOld != f->FullName[j])
                     break;
               }
            }
         }
      }
   }
   *Index = -1; //nothing match
}

#endif

/* ------------------------------------------------------------------------------- */
#ifdef __FS_QM_SUPPORT__

static int QMPermitAllocate(UINT DriveFree, int Index, UINT NeedCluster)
{
   int i, RFS_for_Other = 0, FreeSpace1, FreeSpace2, FreeSpace;

   if(Index < 0) //Count all RFS
   {
      for(i = FS_MAX_QSET - 1 ; i >= 0 ; i--)
      {
         if(gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Qnow)
            RFS_for_Other += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Qnow);
      }
      FreeSpace = (DriveFree > RFS_for_Other) ? (DriveFree - RFS_for_Other) : 0;
      goto QMPermitAllocateReturn;
   }

   if(gFS_IntQuotaSet[Index].Qmax)
   {
      if((gFS_IntQuotaSet[Index].Qnow + NeedCluster) > gFS_IntQuotaSet[Index].Qmax)
         return MT_APP_QUOTA_FULL;
   }

   for(i = FS_MAX_QSET - 1 ; i >= 0 ; i--)
   {
      if(i != Index)
      {
         if(gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Qnow)
            RFS_for_Other += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Qnow);
      }
   }

   FreeSpace1 = (DriveFree > RFS_for_Other) ? (DriveFree - RFS_for_Other) : 0;
   if(gFS_IntQuotaSet[Index].Qmax)
   {
      FreeSpace2 = gFS_IntQuotaSet[Index].Qmax - gFS_IntQuotaSet[Index].Qnow;
      FreeSpace = (FreeSpace1 > FreeSpace2) ? FreeSpace2: FreeSpace1; //min
   }
   else //FS_QMAX_NO_LIMIT
      FreeSpace = FreeSpace1;

QMPermitAllocateReturn:
   if(NeedCluster <= FreeSpace)
      return RTF_NO_ERROR;

   return MT_APP_QUOTA_FULL;
}

#endif

/* ------------------------------------------------------------------------------- */
UINT RTFAPI GetFirstSector(WCHAR * FileName, void * SectorContent, UINT *Sector1, UINT *Sector2)
{
   int volatile Result = RTF_NO_ERROR;
   RTFile * volatile f;
   UINT Cluster, NextCluster;

   XTRY
      case XCODE:
         f = ParseFileName((char *)FileName);

#ifndef __P_PROPRIETARY_COPYRIGHT__
         if (f->SpecialKind != NormalFile)
         {
            XRAISE(RTF_INVALID_FILENAME);
         }

         if (!SearchFile(f, SEARCH_FILES, (char *)FileName, NULL))
            XRAISE(RTF_PATH_NOT_FOUND);
#else
/* under construction !*/
#endif

         Cluster = FIRST_FILE_CLUSTER(f->DirEntry.Dir);

         if ((Cluster < 2) || (Cluster == RTF_ROOT_DIR))
            XRAISE(RTF_BAD_DIR_ENTRY); //maybe empty file or root file

         *Sector1 = CLUSTER_TO_SECTOR(f->Drive, Cluster);
         ReadSectors(f->Dev, SectorContent, *Sector1, 1, 0);
         NextCluster = GetClusterValue(f->Drive, Cluster);
         if (NextCluster < RTF_CLUSTER_CHAIN_END)
            *Sector2 = CLUSTER_TO_SECTOR(f->Drive, NextCluster);
         else
            *Sector2 = 0xFFFFFFFF;
         break;
      default:
         Result = XVALUE;
         break;
      case XFINALLY:
         if (f)
            FreeFTSlot(f);
#ifndef __P_PROPRIETARY_COPYRIGHT__  //speedup
         SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
#endif
         break;
   XEND_API
   return Result;
}

/* ------------------------------------------------------------------------------- */
int SetCopyrightEntry(RTFDirLocation *lFS_CopyrightLongPos, RTFDirLocation *lFS_CopyrightShortPos,
                       RTFDOSDirEntry *lFS_CopyrightDir)
{
#ifdef __P_PROPRIETARY_COPYRIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   return RTF_NO_ERROR;
}

/* ------------------------------------------------------------------------------- */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))
/* InitShadowFAT will copy FAT in the memory
 * XXX: Potential Limit -- Only One and Last Drive will be mapped if multiple Partitions on 1 device
 */
static void InitShadowFAT(RTFDrive *Drive)
{
      if (Drive->Dev->DeviceType != RTF_DEVICE_FDISK)
         return;

#ifdef __FS_SHADOW_NAND__
      if (Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
      {
         ReadSectors(Drive->Dev, Shadow_FAT_Array_NAND, Drive->FirstFATSector, Drive->SectorsPerFAT, NO_RAISE);
      }
#endif

#ifdef __FS_SHADOW_CARD__
      if (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
      {
         ReadSectors(Drive->Dev, Shadow_FAT_Array_CARD, Drive->FirstFATSector, Drive->SectorsPerFAT, NO_RAISE);
      }
#endif
}

#endif

/* ------------------------------------------------------------------------------- */
#if (defined(__FS_SHADOW_NAND__) || defined(__FS_SHADOW_CARD__))

static void FlushShadowFAT(void)
{
   if ((kal_query_systemInit() == KAL_FALSE) && (stack_query_boot_mode() != USBMS_BOOT))
   {
      int i;
      RTFDrive * Drive;
      for (i = 0; i < FS_MAX_DRIVES; i++)
      {
         Drive = &gFS_Data.DriveTable[i];

         if (Drive->Dev->DeviceType != RTF_DEVICE_FDISK)
            break;

#ifdef __FS_SHADOW_NAND__
         if (Drive->Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
         {
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
            WriteSectors(Drive->Dev, Shadow_FAT_Array_NAND, Drive->FirstFATSector, Drive->SectorsPerFAT, NO_RAISE, RTF_NORMAL_WRITE);
            SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
            continue;
         }
#endif

#ifdef __FS_SHADOW_CARD__
         if (Drive->Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
         {
            SafeLock(MT_LOCK_RTF | MT_LOCK_DEV, Drive->Dev, RTF_INFINITE);
            WriteSectors(Drive->Dev, Shadow_FAT_Array_CARD, Drive->FirstFATSector, Drive->SectorsPerFAT, NO_RAISE, RTF_NORMAL_WRITE);
            SafeUnlock(MT_LOCK_RTF | MT_LOCK_DEV);
            continue;
         }
#endif
         continue;
      }
   }
}

#endif

/* ------------------------------------------------------------------------------- */
/* For Virtual File Feature */

static void INTERN ToWsHexString(WCHAR * Name, DWORD TimeStamp)
// write 8 hex digits, no zero termination
{
   UINT i;

   for (i=0; i<8; i++)
   {
      Name[7-i] = dchar_HexDigits[TimeStamp & 0xF];
      TimeStamp >>= 4;
   }
}
static int INTERN RestoreWsHexString(WCHAR * Name, DWORD *value) // inverse of ToWsHexString()
{
   UINT v,i;
   WCHAR *p;

   for (i=0, v=0; i<8; i++)
   {
      p = kal_wstrchr( dchar_HexDigits, (int) Name[i] );
      if( p == NULL )
      {
         return KAL_FALSE;
      }
      v += (UINT)(p - dchar_HexDigits);
      if( i<7 ) // not last run
      {
         v <<= 4;
      }
   }
   *value = v;
   return KAL_TRUE;
}

int MTGenVirtualFileName(RTFHANDLE File, WCHAR * VFileNameBuf, UINT BufLength, UINT VFBeginOffset, UINT VFValidLength)
{
   RTFile * volatile f = NULL;
   WCHAR *VFNptr;
   UINT FillStrLength, CheckSum;
   XTRY
      case XCODE:
         f = ParseFileHandle(File);
         /* GenVirtual - 1 : check valid input (type, access, region)*/
         if ((f->SpecialKind != NormalFile) ||
             (FIRST_FILE_CLUSTER(f->DirEntry.Dir) == RTF_ROOT_DIR) ||
             (f->DirEntry.Dir.Attributes & RTF_ATTR_DIR) ||
             (f->DirEntry.Dir.FileSize <= VFBeginOffset) ||
             (f->DirEntry.Dir.FileSize <  VFBeginOffset+VFValidLength) )
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_PARAM_ERROR, f, NULL);
#endif
            XRAISE(RTF_PARAM_ERROR);
         }

         if ( (f->Flags & (RTF_READ_ONLY | RTF_OPEN_SHARED) ) != (RTF_READ_ONLY | RTF_OPEN_SHARED) )
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, f, NULL);
#endif
            XRAISE(RTF_ACCESS_DENIED);
         }


         /* GenVirtual - 2 : Generate FileName and Write Back The Buffer */
         FillStrLength = kal_wstrlen( dchar_virtual_filename_prefix );
         if( BufLength < FillStrLength * sizeof(WCHAR) + ( 9 * sizeof(WCHAR) ) * 4 ) /* 92 */
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
               MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_STRING_BUFFER_TOO_SMALL, f, NULL);
#endif
            XRAISE(RTF_STRING_BUFFER_TOO_SMALL);
         }
        
         VFNptr = kal_wstrncpy( VFileNameBuf, dchar_virtual_filename_prefix, FillStrLength );
         /* FillStrLength = kal_wstrlen( VFileNameBuf ); */
         BufLength -= FillStrLength;
         VFNptr += FillStrLength;

         #define VIRTUAL_NAME_BUF_PROCESS_NEXT  VFNptr[8] = 0x5c; VFNptr += 9; BufLength -= 9* sizeof(WCHAR)
         ToWsHexString( VFNptr, (DWORD) File);
         VIRTUAL_NAME_BUF_PROCESS_NEXT;

         CheckSum = FIRST_FILE_CLUSTER(f->DirEntry.Dir);
         ToWsHexString( VFNptr, (DWORD) CheckSum);
         VIRTUAL_NAME_BUF_PROCESS_NEXT;

         ToWsHexString( VFNptr, (DWORD) VFBeginOffset);
         VIRTUAL_NAME_BUF_PROCESS_NEXT;

         ToWsHexString( VFNptr, (DWORD) VFValidLength);
         VIRTUAL_NAME_BUF_PROCESS_NEXT;

         VFNptr --; VFNptr[0] = 0x0;
         ASSERT( ((int) BufLength) >= 0 ); // if fail, it's logical error inside, not caller's fault 

      default:
         break;
      case XFINALLY:
         if (f != NULL)
            UnlockDevice(f->Dev);
         break;
   XEND_API
   return RTF_NO_ERROR;
}

static void INTERN SetupFMapF_FileHandle(RTFile *f)
{
   RTFHANDLE  Identity;
   RTFile *LargeFileTable;
   WCHAR *name_ptr;

   /* SetupFMapF 1 --- Get LargeFileTable and make sure it does exist */
   name_ptr =  (WCHAR*) f->FullName;
   name_ptr += kal_wstrlen( dchar_virtual_filename_prefix );
   if( RestoreWsHexString( name_ptr, (DWORD*) &Identity ) != KAL_TRUE )
   {
      goto INVALID_FILENAME_EXIT;
   }
   LargeFileTable = ParseFileHandle( Identity ); /* Lock Device Here */
   f->DirEntry.LongPos.Index = (UINT) Identity;
   // borrow the DirEntry.LongPos.Index as LargeFile RTFile Pointer

   f->Dev = LargeFileTable->Dev;
   f->Drive = LargeFileTable->Drive;

   /* SetupFMapF 2 --- Reterieve Other Parameters,  CheckSum match*/
   name_ptr += 9;
   if( RestoreWsHexString( name_ptr, (DWORD*) &Identity ) != KAL_TRUE
    || FIRST_FILE_CLUSTER(LargeFileTable->DirEntry.Dir) != Identity )
   {  
      goto INVALID_FILENAME_EXIT;
   }
   f->DirEntry.Dir.Attributes = LargeFileTable->DirEntry.Dir.Attributes;
   SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, Identity); // setup for InitFilePointer(),

   /* get the Begin Pos */
   name_ptr += 9;
   if( RestoreWsHexString( name_ptr, (DWORD*) &Identity ) != KAL_TRUE )
   { 
      goto INVALID_FILENAME_EXIT;
   }
   f->DirEntry.ShortPos.Index = Identity;
   // borrow the DirEntry.ShortPos.Index as Begin Position

   /* Setup the FIRST_FILE_CLUSTER and Length */
   name_ptr += 9;
   if( RestoreWsHexString( name_ptr, (DWORD*) &Identity ) != KAL_TRUE
    || (name_ptr[8]!=0x0 && name_ptr[8]!=0x2e) /* Allow dot tail for user append extension name*/ )
   {
      goto INVALID_FILENAME_EXIT;
   }

   /* Last, We copy the Parent FileName as Long as Possible For Debug */
   name_ptr = (WCHAR*) f->FullName + kal_wstrlen( (WCHAR*)f->FullName );
   kal_wstrncpy( name_ptr, (WCHAR*)LargeFileTable->FullName, RTF_MAX_PATH/sizeof(WCHAR) - kal_wstrlen( (WCHAR*) f->FullName) - 1 ); 

   /* SetupFMapF 3 --- Fill File Table members , Search my first cluster first */
   InitFilePointer( f );
   MoveFilePointer( f, f->DirEntry.ShortPos.Index );

   /* Now we have reach the VF Begin */
   f->DirEntry.ShortPos.Index = f->Offset; /* This member is brrowed as the Bias offset */
   SET_FIRST_FILE_CLUSTER(f->DirEntry.Dir, f->Cluster); /* This is the first cluster of VF */
   f->FilePointer = f->Offset; /* Reset FilePointer */
   f->DirEntry.Dir.FileSize = f->Offset + Identity; /* Setup the FileSize (biased) */
   f->LastCluster = 0;

   return;
INVALID_FILENAME_EXIT:
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
         MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_INVALID_FILENAME, NULL, (BYTE *)name_ptr);
#endif
      XRAISE(RTF_INVALID_FILENAME);
}

static int MTChkMapedFH(RTFHANDLE File)
{  UINT U = File >> (4*sizeof(int));
   UINT i = File & ((1 << (4*sizeof(int))) - 1);
   RTFile * maped_ft;

   if (i >= FS_MAX_FILES)
   {
      return (MT_VF_MAP_ERROR);
   }
   maped_ft = gFS_Data.FileTable + i;
   if (maped_ft->Lock == 0 || maped_ft->Unique != U || maped_ft->Dev == NULL)
   {
      return (MT_VF_MAP_ERROR);
   }
   return RTF_NO_ERROR;
}

void RTFAPI AdjustBuffer(void)
{
   RTFBuffer * B;

   FlushAllBuffers(gFS_Data.DriveTable[0].Dev);
   DiscardAllBuffers(gFS_Data.DriveTable[0].Dev);

   B = FirstBuffer->Next;
   do
   {
      B->Flags |= B_INUSE;
      B->Dev = 0x0;
      B = B->Next;
   }while (B != FirstBuffer);

   FirstBuffer->Next = FirstBuffer;
}

int RTFAPI BatchCountFreeClusters(RTFDrive * Drive)
{
   RTFCluster FreeCount, CurrCluster;
   RTFCluster Watermark=RTF_INVALID_CLUSTER;
   DWORD      CurrSector;
   RTFCluster BaseCluster, TillCluster, CurrClusterValue;
   BYTE*      DicatedBuffer2K;
   volatile int i, factor;

   if (Drive->FATType == 12 || INT_QueryExceptionStatus() == KAL_TRUE)
   {
      /* BatchCountFreeClusters - 1 , FAT12 only 12 Sectors maximum, fallback to non-batch way */
SequentialWay:
      for (FreeCount=0, CurrCluster = 2; CurrCluster < Drive->Clusters; CurrCluster++)
      {
         CurrClusterValue = GetClusterValue(Drive, CurrCluster);

         if (CurrClusterValue == 0)
         {
            FreeCount++;
            if (Watermark == RTF_INVALID_CLUSTER)
            {
               Watermark = CurrCluster;
            }
         } /* if (CurrClusterValue == 0) */
      }
      goto BatchExit;
   }
      /* BatchCountFreeClusters - 2 , Deal Buffer allocation */
   DicatedBuffer2K = (BYTE *)get_ctrl_buffer(Drive->Dev->DevData.SectorSize * 4 /* 2048 */);
   if (DicatedBuffer2K == NULL)
      goto SequentialWay;

   /* FirstFATSector ... > FirstFATSector + SectorsPerFAT */
   factor = Drive->Dev->DevData.SectorSize * 8 / Drive->FATType;
   for (FreeCount=0, CurrCluster=2, CurrSector=0; CurrSector < Drive->SectorsPerFAT; )
   {
      int result;
      /* BatchCountFreeClusters - 3 , Get 2K Page align and fill buffer */
      i = 4 - (CurrSector + Drive->FirstFATSector) % 4;
         /* reuse variable int i */
      result = ReadSectors(Drive->Dev, DicatedBuffer2K, Drive->FirstFATSector + CurrSector, i, NO_RAISE);
      if (result < RTF_NO_ERROR)
      {
         free_ctrl_buffer(DicatedBuffer2K);
#ifdef __FS_TRACE_SUPPORT__
         if (g_TraceFlag & MT_TRACE_ERROR);
         /* Note this XRAISE here aim for propagate error only and doesn't need to dump trace */
#endif
         XRAISE(result);
      }

      /* BatchCountFreeClusters - 4 , MARK Begin and End Cluster Number */
      BaseCluster = CurrSector * factor;
      CurrSector += i;
      TillCluster = CurrSector * factor;
      TillCluster = (TillCluster > Drive->Clusters) ? Drive->Clusters : TillCluster;

      /* BatchCountFreeClusters - 5 , Traverse The Buffer */
      for (; CurrCluster < TillCluster; CurrCluster++)
      {
         if (Drive->FATType == 16)
         {
            WORD * FATPtr = (WORD *) DicatedBuffer2K;
            CurrClusterValue = FATPtr[CurrCluster - BaseCluster];
         }
         else if (Drive->FATType == 32)
         {
            DWORD * FATPtr = (DWORD *) DicatedBuffer2K;
            CurrClusterValue = FATPtr[CurrCluster - BaseCluster];
         }
         else
         {
#ifdef DEBUG
            RTFSYSErrorExit("Invalid file system ID in BatchCountFreeClusters", 1);
#endif
            EXT_ASSERT(0, (UINT)Drive, Drive->FATType, 0);
            break;
         }

         if (CurrClusterValue == 0)
         {
            FreeCount++;
            if (Watermark == RTF_INVALID_CLUSTER)
            {
               Watermark = CurrCluster;
            }
         } /* if (CurrClusterValue == 0) */
      }
   } /* For Sector 0 ... SectorsPerFAT */

      /* BatchCountFreeClusters - 6 , Deal Buffer Release */
   free_ctrl_buffer(DicatedBuffer2K);

BatchExit:
   Drive->FreeClusterCount = FreeCount;
   Drive->ClusterWatermark = Watermark;
   FATInitInfoSectorSubMark(Drive);
   return RTF_NO_ERROR;
}

static RTFCluster INTERN FATSearchZeroInBuffer(RTFDrive *Drive, RTFCluster Cluster)
{
   RTFCluster NextZero;
   RTFCluster Result;

   switch (Drive->FATType)
   {
      case RTFAT12:
      {
         DWORD Pos;
         UINT  B1, B2;
         BYTE  * FATPtr;

         Pos      = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
         NextZero = (((Pos >> Drive->Dev->DevData.SectorShift) + 1) << Drive->Dev->DevData.SectorShift) * 2 / 3;

         FATPtr   = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Pos >> Drive->Dev->DevData.SectorShift), 0);

         /* Verify Case for 512B sector size : Cluster = 340, 341, 342, 682, 683, 1023, 1024 */
         while(Cluster < NextZero)
         {
            Pos   = Cluster + Cluster / 2;     // 0 1 3 4 6 7 9 10 12 13
            B1    = FATPtr[    Pos & (Drive->Dev->DevData.SectorSize-1)];
            B2    = FATPtr[(++Pos) & (Drive->Dev->DevData.SectorSize-1)];
            Result = (Cluster & 1) ? ((B2 << 4) | (B1 >> 4)) : (((B2 & 0x0F) << 8) | B1);
            if (Result == 0)
            {
               break; /* while (Cluster < NextZero) */
            }
            Cluster++;
         }
         
         return Cluster;
      }
      case RTFAT16:
      {
         WORD * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-1)), 0);

         NextZero = ((Cluster >> (Drive->Dev->DevData.SectorShift-1)) + 1) << (Drive->Dev->DevData.SectorShift-1);

         while(Cluster < NextZero)
         {
            Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 1)-1)];
            if (Result == 0)
            {
               break; /* while (Cluster < NextZero) */
            }
            Cluster++;
         }

         return Cluster;
      }
      case RTFAT32:
      {
         DWORD * FATPtr = GetBuffer(Drive->Dev, Drive->FirstFATSector + (Cluster >> (Drive->Dev->DevData.SectorShift-2)), 0);

         NextZero = ((Cluster >> (Drive->Dev->DevData.SectorShift-2)) + 1) << (Drive->Dev->DevData.SectorShift-2);

         while(Cluster < NextZero)
         {
            Result = FATPtr[Cluster & ((Drive->Dev->DevData.SectorSize >> 2)-1)] & 0x0FFFFFFF;
            if (Result == 0)
            {
               break; /* while (Cluster < NextZero) */
            }
            Cluster++;
         }

         return Cluster;
      }
#ifdef DEBUG
      default:
         RTFSYSErrorExit("Invalid file system ID in GetClusterValue", 1);
#endif
         EXT_ASSERT(0, (UINT)Drive, Drive->FATType, 0);
   }
   return Cluster;
}

static void INTERN FATHoistSubMark(RTFDrive *Drive, RTFCluster Begin, RTFCluster End)
{
   if (Drive->InfoSector)
   {
      RTFFAT32InfoSector * IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      RTFCluster         * Map= (RTFCluster *) IS->Reserved;
      int                  Idx= Begin >> SUBMARK_ID_SHIFT;
      int                  IdxEnd = End >> SUBMARK_ID_SHIFT;

      /* Hoist - 0 : Input range : Begin (include) ~ End (NOT included) , contingous chain */
      IdxEnd = (IdxEnd > SUBMARK_LASTNUM) ? SUBMARK_LASTNUM : IdxEnd;
      Idx    = (Idx    > SUBMARK_LASTNUM) ? SUBMARK_LASTNUM : Idx;

      /* Hoist - 1 : There are 4 cases here
       *    1-A : Begin ~ End , at different segment => set first segment as full mark and
       *                                                check subwatermark of last segment
       *    1-B : Begin ~ End , at the same segment => set subwatermark as End Cluster
       *    1-C : !Begin ~ End, at the same segment => Do-nothing & return
       *    1-D : !Begin ~ End, at different segment => check subwatermark of last segment
       */
      if (Map[Idx] == Begin)
      {
         if (Idx != IdxEnd)
         {
            Map[Idx] = RTF_INVALID_CLUSTER;
            if (Map[IdxEnd] < End) Map[IdxEnd] = End;
         }
         else
            Map[Idx] = End;
      }
      else
      {
         if (Idx == IdxEnd)
            return;
         else if (Map[IdxEnd] < End)
            Map[IdxEnd] = End;
      }
      /* Hoist - 2 : Set full from (last - 1) segment to (first + 1) segment one by one */
      for (IdxEnd--;IdxEnd > Idx;IdxEnd--)
      {
         Map[IdxEnd] = RTF_INVALID_CLUSTER;
      }

      SetDirty(Drive->Dev);
   }
}

static void INTERN FATLowerSubMark(RTFDrive *Drive, RTFCluster Begin, RTFCluster End)
{
   if (Drive->InfoSector)
   {
      RTFFAT32InfoSector * IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      RTFCluster         * Map= (RTFCluster *) IS->Reserved;
      int                  Idx= Begin >> SUBMARK_ID_SHIFT;
      int                  IdxEnd = End >> SUBMARK_ID_SHIFT;

      /* Lower - 0 : Input range : Begin (include) ~ End (included) ; but may not contingus chain */
      IdxEnd = (IdxEnd > SUBMARK_LASTNUM) ? SUBMARK_LASTNUM : IdxEnd;
      Idx    = (Idx    > SUBMARK_LASTNUM) ? SUBMARK_LASTNUM : Idx;

      /* Lower - 1 : Review lowest segment , see if lower watermark required */
      if (Map[Idx] > Begin)
      {
         Map[Idx] = Begin;
      }
      /* Lower - 2 : Review (lowest + 1) ~ (highest) segment , reset watermark as init value */
      for (Idx++;Idx <= IdxEnd;Idx++)
      {
         Map[Idx] = (Idx << SUBMARK_ID_SHIFT) & SUBMARK_MASKOUT;
      }

      SetDirty(Drive->Dev);
   }
}

static void INTERN FATInitInfoSectorSubMark(RTFDrive *Drive)
{
   if (Drive->InfoSector && ((Drive->Dev->DeviceFlags & MT_DEVICE_WRITE_PROTECT) == 0))
   {
      RTFFAT32InfoSector * IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      RTFCluster         * Map= (RTFCluster *) IS->Reserved;
      int                  Idx= 0;
      int                  IdxEnd = Drive->Clusters >> SUBMARK_ID_SHIFT;

      for (; Idx <= SUBMARK_LASTNUM; Idx++)
      {
         if (Idx > IdxEnd)
         {  /* Fill remain submarks as 0x0 in Map */
            Map[Idx] = 0x0;
         }
         else if ((Drive->ClusterWatermark >> SUBMARK_ID_SHIFT) > Idx)
         {  /* Set known full segments submarks as 0xFFFFFFFF in Map */
            Map[Idx] = RTF_INVALID_CLUSTER;
         }
         else if ((Drive->ClusterWatermark >> SUBMARK_ID_SHIFT) == Idx)
         {  /* Set the one segments submarks as ClusterWatermark in Map */
            Map[Idx] = Drive->ClusterWatermark;
         }
         else
         {  /* Set the segments after ClusterWatermark submarks as Init Value in Map */
            Map[Idx] = (Idx << SUBMARK_ID_SHIFT) & SUBMARK_MASKOUT;
         }
      }
      SetDirty(Drive->Dev);
      /* Note: If Disk Full, ClusterWatermark = 0xFFFFFFFF,
       *       and all valid submark will be set to 0xFFFFFFFF, too.
       */
   }
}

static RTFCluster INTERN FATHintSearchBySubMark(RTFDrive * Drive, RTFCluster Cluster, int MarkFlag)
{
   if (Drive->InfoSector)
   {
      RTFFAT32InfoSector * IS = GetBuffer(Drive->Dev, Drive->InfoSector, 0);
      RTFCluster         * Map= (RTFCluster *) IS->Reserved;
      int                  Idx= Cluster >> SUBMARK_ID_SHIFT;

      if (Idx > SUBMARK_LASTNUM)
      {
         /* Oops, out of range */
         return Cluster;
      }

      if (MarkFlag)
      {
         /* True means the previous segment already full, set Full mark */
         ASSERT(Idx > 0);
         Map[Idx - 1] = RTF_INVALID_CLUSTER;
         SetDirty(Drive->Dev);
      }
      
      /* Hint Search loop */
      for (;Idx <= SUBMARK_LASTNUM; Idx++)
      {
         if (Map[Idx] == RTF_INVALID_CLUSTER)
         {  /* This Range alreay occupied */
            Cluster += (1 << SUBMARK_ID_SHIFT);
            continue;
         }
         if ((Map[Idx] >> SUBMARK_ID_SHIFT) == Idx)
         {  /* This watermark is trustable */
            return Map[Idx];
         }
         /* No more hint? back */
         break;
      }
   }
   return Cluster;
}

void * RTFAPI MTProxyGetBuffer (RTFDevice * Dev, RTFSector Sector)
{
   return GetBuffer(Dev, Sector, 0);
}

void RTFAPI MTExpireDirCacheValue(RTFDrive * Drive, RTFCluster DirCluster)
{
#ifndef _LOW_COST_SINGLE_BANK_FLASH_
   int hash;

   hash = DirCluster & DIRCACHE_MASK;
   if (g_DirCacheArray[hash].Drive == Drive && g_DirCacheArray[hash].Cluster == DirCluster)
   {
      g_DirCacheArray[hash].Drive = NULL;
   }
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */
}

void RTFAPI MTSetDirCacheValue(RTFDrive * Drive, RTFCluster DirCluster, UINT NewValue)
{
#ifndef _LOW_COST_SINGLE_BANK_FLASH_
   int hash;

   hash = DirCluster & DIRCACHE_MASK;
   g_DirCacheArray[hash].Drive   = Drive;
   g_DirCacheArray[hash].Cluster = DirCluster;
   g_DirCacheArray[hash].Value   = NewValue;
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */
}

void RTFAPI MTGetDirCacheValue(RTFDrive * Drive, RTFCluster DirCluster, UINT *CurrValue)
{
#ifndef _LOW_COST_SINGLE_BANK_FLASH_
   int hash;

   hash = DirCluster & DIRCACHE_MASK;
   if (g_DirCacheArray[hash].Drive == Drive && g_DirCacheArray[hash].Cluster == DirCluster)
   {
      *CurrValue = g_DirCacheArray[hash].Value;
   }
   else
   {
#ifdef __FS_TRACE_SUPPORT__
      if(g_TraceFlag & MT_TRACE_ERROR)
      {
         MTTraceFS((UINT)kal_get_task_self_id(), 2, __LINE__, MT_DIRCACHE_EXPIRED, NULL, NULL);
      }
#endif
      XRAISE(MT_DIRCACHE_EXPIRED);
   }
#else
   // always return Cache expired when disabled on _LOW_COST_SINGLE_BANK_FLASH_ !!   
   XRAISE(MT_DIRCACHE_EXPIRED);
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */
}

static int INTERN CopySectors(RTFDevice * Dev, RTFSector FromSector, RTFSector ToSector, UINT Sectors, DWORD Flags)
{
   int volatile Result;

   RTFSYSFreeMutex(RTFLock);
   XTRY
      case XCODE:
         CheckMedia(Dev);
         if (Dev->DevData.ErrorCondition < RTF_NO_ERROR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_task_self_id(), 1, __LINE__, Dev->DevData.ErrorCondition, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(Dev->DevData.ErrorCondition);
         }
         if (Dev->DevData.MountState < Mounted)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_task_self_id(), 1, __LINE__, RTF_DRIVE_NOT_READY, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(RTF_DRIVE_NOT_READY);
         }

         Result = Dev->Driver->CopySectors(Dev->DriverData, FromSector, ToSector, Sectors);
         /* Error Handling */
         if (Result < RTF_NO_ERROR)
         {
#ifdef __FS_TRACE_SUPPORT__
            if(g_TraceFlag & MT_TRACE_ERROR)
            {
               if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NOR, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               else if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
                  kal_sprintf(TraceTmpBuf, "Dev:NAND, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               else
                  kal_sprintf(TraceTmpBuf, "Dev:Card, Sector: %d => %d, Sectors: %d", FromSector, ToSector, Sectors);
               memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
               MTTraceFS((DWORD)kal_get_task_self_id(), 1, __LINE__, Result, NULL, (BYTE *)TraceTmpBuf);
            }
#endif
            XRAISE(Result);
         }
         break;
      default:
         if (((Flags & NO_CRITICAL) == 0) &&
             (HandleCriticalError(Dev, XVALUE) == RTFRetry))
         {
            XHANDLED;
            XREEXECUTE;
         }
         if (Flags & NO_RAISE)
         {
            Result = XVALUE;
            Dev->DevData.ErrorCondition = RTF_NO_ERROR;
            XHANDLED;
         }
         break;
      case XFINALLY:
         RTFSYSLockMutex(RTFLock, RTF_INFINITE);
         break;
   XEND
   return Result;
}

int MTCopyFileByClusterChain(RTFHANDLE FileDst, RTFCluster *ClustersArray, UINT ClusterNum)
{
   RTFile * volatile f = NULL;
   int written=0;
   UINT l;

   XTRY
      case XCODE:
         f = ParseFileHandle(FileDst);
         l = ClusterNum << (f->Drive->ClusterShift);
         while (l > 0)
         {
            UINT       n;      // number of bytes in segment
            RTFSector  S;      // sector to start writing at
            RTFSector  C;      // number of sectors in segment;
            RTFSector  R;      // sector to start copy from

            if (f->Cluster == 0) // end of file, allocate more
               ExtendFile(f, l);

            S = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, f->Cluster, f->Offset);
            R = CLUSTER_TO_SECTOR_DIR_OFS(f->Drive, ClustersArray[written], 0);
            n = MoveFilePointerSegment(f, l);
            C = n >> f->Dev->DevData.SectorShift;

            // can write C sectors starting at S, but have to check
            // for any data in buffers

            DiscardBuffersRange(f->Dev, S, C, 0);   // discard without commit

            // issue Drive operation
            CopySectors(f->Dev, R, S, C, 0);

            // update iteration value
            written += n >> (f->Drive->ClusterShift);
            l -= n;
         }
         break;
      default:
         break;
      case XFINALLY:
         if (f != NULL)
         {
         if (f->FilePointer > f->DirEntry.Dir.FileSize)
         {
            f->DirEntry.Dir.FileSize = f->FilePointer;
         }
         RTFSYSGetDateTime(&f->DirEntry.Dir.DateTime);
         UpdateDirEntry(f);
         if (f->Flags & RTF_COMMITTED) FlushFAT(f->Dev);
            UnlockDevice(f->Dev);
         }
         break;
   XEND_API
   return written;
}

/**************************************************
 *  discard sector piece by piece
 **************************************************/
int RTFAPI CleanUpDataSectors(RTFDrive * Drive, RTFCluster *Start, int MaxClusters)
{
   RTFCluster MaxCN = *Start + MaxClusters;
   
   XTRY
      case XCODE:
         for (; *Start < MaxCN ; (*Start)++)
         {
            if (GetClusterValue(Drive, (*Start)) == 0)
            {
               DiscardSectors(Drive->Dev, CLUSTER_TO_SECTOR(Drive, (*Start)), Drive->SectorsPerCluster);
            }
         }
         break;
      default:
         break;
      case XFINALLY:
         break;
   XEND_API
   return RTF_NO_ERROR;
}

/*-----------------------------------*/
/* See also : CheckSharing() */
void RTFAPI MTCheckSharingWithSpecialKindFh(RTFile * File)
{
   UINT i;
   RTFile * f = gFS_Data.FileTable;

   // check if the special kind file is open and the access scope overlap without sharing
   for (i=0; i<FS_MAX_FILES; i++, f++)
   {
      if ((f != File) &&
          (f->Dev == File->Dev) &&
          (f->Valid == MT_ENUM_FH_VALID) &&
          ((f->Flags & File->Flags & RTF_READ_ONLY) == 0) &&   // not both read only AND
          ((f->Flags & File->Flags & RTF_OPEN_SHARED) == 0) && // not both opend shared AND
          (((f->SpecialKind == PhysicalDisk) ||                // one of them is a device file OR
            (File->SpecialKind == PhysicalDisk)) ||
           ((f->Drive == File->Drive) &&                       // one volume and both go to the same drive
            ((f->SpecialKind == Volume) || (File->SpecialKind == Volume)))))
      {
#ifdef __FS_TRACE_SUPPORT__
         if(g_TraceFlag & MT_TRACE_ERROR)
         {
            kal_sprintf(TraceTmpBuf, "%dth FH", i+1);
            memset(TraceTmpBuf+strlen((char *)TraceTmpBuf)+1, 0, 2);
            MTTraceFS((DWORD)kal_get_current_thread_ID(), 1, __LINE__, RTF_ACCESS_DENIED, File, (BYTE *)TraceTmpBuf);
         }
#endif
         XRAISE(RTF_ACCESS_DENIED);
      }
   }
}

/*-----------------------------------*/
void RTFAPI MTToLowerString(WCHAR *FileName, UINT MaxLength)
{
   UINT i;
   
   for(i = 0 ; i < (MaxLength/2 - 1); i++)
   {
      if(FileName[i] == 0)
         break;
      if((FileName[i] >= 0x41) && (FileName[i] <= 0x5A))
      {
         FileName[i] = FileName[i] + (0x61 - 0x41);
      }
   }
}

/*-----------------------------------*/
void RTFAPI MTCheckFileNameCase(WCHAR *FileName, UINT MaxLength, BYTE NTReserved)
{
   UINT i;
   
   MaxLength /= 2;
   // check primary file name
   for(i = 0 ; i < (MaxLength - 1); i++)
   {
      if((FileName[i] == 0) || (FileName[i] == dchar_dot[0]))
         break;
   }
   if (NTReserved & MT_ENUM_LOWERCASE_MARK)
   {
      MTToLowerString(FileName, (i + 1) * 2);
   }
   
   // check extension file name
   if (( i < (MaxLength - 1)) && (FileName[i] == dchar_dot[0]))
   {
      if (NTReserved & MT_ENUM_EXT_LOWERCASE_MARK)
      {
         MTToLowerString(FileName + i + 1, (MaxLength - i - 1) * 2);
      }
   }
}
/* ------------------------------------------------------------------------------- */

WCHAR * RTFAPI TruncateWideWhiteSpacesAndPeriods(const WCHAR *pSrcBuf)
{
   int i, j;
   WCHAR *pBuf = (WCHAR *)pSrcBuf;
   
   if (pBuf)
   {
      // remove leading white spaces
      while((pBuf[0] != 0) && (pBuf[0] == 0x0020))
      {
         pBuf++;
      }      
      // remove trailing whtie spaces and periods
      for (i=0 , j=-1; pBuf[i] != 0x0; i++)
      {
         if (pBuf[i] == 0x005C /* backslash */) j=i;
      }
      if (pBuf[j + 1] == 0x002E)
      {
         // skip truncate period if  \\. \\.. 
         j = 0;
      }

      if ((i && (pBuf[i - 1] == 0x0020 /* space */ ))
        ||(j && (pBuf[i - 1] == 0x002E /* period */)))
      {
         i--;
         while(((i >= 0) && (pBuf[i] == 0x0020 /* space */))
             ||( j       && (pBuf[i] == 0x002E /* period */)))
         {
            i--;
         }
         pBuf[i + 1] = 0;
      }
   }
   
   return pBuf;
}
/* ------------------------------------------------------------------------------- */
/* MTK External Enhancement, Karen Hsu, ADD END */


