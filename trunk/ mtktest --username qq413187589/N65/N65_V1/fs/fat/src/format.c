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
 *   format.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file provides format function. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* RTFiles formatting. */

#include <stdlib.h>
#include <string.h>

#include "kal_release.h"
#include <rtfiles.h>
#include "fs_kal.h"
#include "app_buff_alloc.h"


#define SECTOR_SIZE 512


extern int compUAstring(const char * FileName, const char* str, int len);


/*-----------------------------------*/
int RTFAPI RTFFormat(const WCHAR * DeviceName, 
                     UINT MinSectorsPerCluster,
                     RTFFormatCallback Progress, 
                     DWORD Flags)
{
   RTFBootRecord * BR = NULL; 
   RTFPartitionInfo Par;
   RTFFileInfo FI;
   RTFHANDLE Drive;
   int Result   = RTF_NO_ERROR;
   int FATType  = RTF_ERROR_RESERVED;
   int TryCount = 1;
   BYTE *ScratchSector = NULL;
   DWORD SystemSectors, RootDirSectors, FATSectors, Written;

   Drive = RTFOpen(DeviceName, RTF_READ_WRITE); // this ensures exclusive access
   if (Drive < RTF_NO_ERROR)
      return Drive;

   ScratchSector = (BYTE*) get_ctrl_buffer(SECTOR_SIZE); // alloc template sector space
   BR            = (RTFBootRecord*) ScratchSector;

   Result = RTFGetFileInfo(Drive, &FI); // make sure it's a drive name
   if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

   // Shalyn Chua (mtk00576)
   // if ((strlen(FI.FullName) != 6) || (memcmp(FI.FullName, "\\\\.\\", 4) != 0))
   if ((kal_dchar_strlen(FI.FullName) != 12) || !(compUAstring(FI.FullName, "\\\\.\\", 4)))
   {
       Result = RTF_PARAM_ERROR;
       goto ExitWithErrorCode;
   }

   Result = RTFGetPartitionInfo(DeviceName, &Par);
   if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

   if (Flags & RTF_FMT_FORCE_LOW_LEVEL)
   {
Retry:
      if (TryCount >= 2) goto ExitWithErrorCode;

      TryCount++;

      /* Remove the restriction on ScanDevices, Karen Hsu, 2004/03/10, MOD START */
      if ((Flags & RTF_FMT_NO_LOW_LEVEL) == 0)
      //if ((Par.PhysicalDiskIndex == -1) && ((Flags & RTF_FMT_NO_LOW_LEVEL) == 0))
      /* Remove the restriction on ScanDevices, Karen Hsu, 2004/03/10, MOD END */
      {
         Result = RTFRawLowLevelFormat(Par.DeviceListIndex, DeviceName, Progress, Flags);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
      }

      Result = RTFGetPartitionInfo(DeviceName, &Par); // formating might have changed it
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
   }

   if (Par.Partition.Sectors == 0) goto Retry;

//ReadBootSector:
   if (Flags & RTF_FMT_NO_LOW_LEVEL)
   {
      Result = RTFRead(Drive, (void*)BR, SECTOR_SIZE, NULL);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

      if (BR->BP.SectorsOnDisk != 0)
         BR->BP.TotalSectors = BR->BP.SectorsOnDisk;

      if (BR->Signature != 0xAA55 ||
          BR->BP.TotalSectors > Par.Partition.Sectors ||
          BR->BP.BytesPerSector != SECTOR_SIZE ||
          BR->BP.SectorsPerCluster == 0 ||
          BR->BP.ReservedSectors == 0 ||
          BR->BP.NumberOfFATs == 0)
      {
         Result = RTFSeek(Drive, 0, RTF_FILE_BEGIN);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

         goto NewBootSecotrs;
      }

      FATSectors     = (BR->BP.SectorsPerFAT) ? BR->BP.SectorsPerFAT : BR->BP.E._32.SectorsPerFAT;
      RootDirSectors = (BR->BP.DirEntries * 32 + (BR->BP.BytesPerSector - 1)) / BR->BP.BytesPerSector;

      Written        = BR->BP.TotalSectors
                     - BR->BP.ReservedSectors
                     - BR->BP.NumberOfFATs * FATSectors
                     - RootDirSectors;
      Written = Written / BR->BP.SectorsPerCluster;

      Result = MTCheckMSCard(Drive, BR);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

      if (Written <= 0xFF4L)
         FATType = 12;
      else if (Written <= 0xFFF4l)
         FATType = 16;
      else if (Written <= 0xFFFFFF4l)
         FATType = 32;
      else
         goto NewBootSecotrs;
      Written = 0;

      if (FATType == 32)
      {
         RootDirSectors = BR->BP.SectorsPerCluster;

         if (BR->BP.E._32.RootDirCluster != 2)
         {
            BR->BP.E._32.RootDirCluster = 2;
            Result = RTFSeek(Drive, 0, RTF_FILE_BEGIN);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

            Result = RTFWrite(Drive, (void*)BR, SECTOR_SIZE, NULL);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

            Result = RTFSeek(Drive, BR->BP.E._32.BackupBootSector * SECTOR_SIZE, RTF_FILE_BEGIN);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

            Result = RTFWrite(Drive, (void*)BR, SECTOR_SIZE, NULL);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
         }
      }

      SystemSectors  = BR->BP.ReservedSectors
                     + BR->BP.NumberOfFATs * FATSectors
                     + RootDirSectors;

      goto ZeroFATRegion;
   }

NewBootSecotrs:
   Result = RTFCreateBootSector(ScratchSector, &Par.Partition, Par.MediaDescriptor, MinSectorsPerCluster, Flags);
   if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
   FATType = Result;

#if 0
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
       // end of modified

   if (FATType == 32)
      RootDirSectors = BR->BP.SectorsPerCluster;
   else
      RootDirSectors = BR->BP.DirEntries / 16;

   FATSectors     = (FATType != 32) ? BR->BP.SectorsPerFAT : BR->BP.E._32.SectorsPerFAT;

   SystemSectors  = BR->BP.ReservedSectors
                  + BR->BP.NumberOfFATs * FATSectors
                  + RootDirSectors;

   if (Progress) Progress((char *)DeviceName, RTF_FMT_PGS_HIGH_FMT, SystemSectors, Written = 0);

   // write boot sector to the disk
   Result = RTFWrite(Drive, (void*)BR, SECTOR_SIZE, NULL);
   if (Result < RTF_NO_ERROR) goto Retry;

   // if this is FAT-32, write backup boot sector
   if (FATType == 32)
   {
      Result = RTFSeek(Drive, BR->BP.E._32.BackupBootSector * SECTOR_SIZE, RTF_FILE_BEGIN);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

      Result = RTFWrite(Drive, (void*)BR, SECTOR_SIZE, NULL);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
   }

   // save data we need further down

ZeroFATRegion:
   {
      UINT FatCount = BR->BP.NumberOfFATs;
      BYTE MediaDescriptor = BR->BP.MediaDescriptor;
      RTFSector StartOfFAT = BR->BP.ReservedSectors;
      RTFSector InfoSector = BR->BP.E._32.FSInfoSector;
      DWORD i, j;

      // clear info sector, all FATs, and the root directory
      memset(ScratchSector, 0, SECTOR_SIZE);

      if ((FATType == 32) && (InfoSector > 0) && (InfoSector < StartOfFAT))
      {
         Result = RTFSeek(Drive, InfoSector * SECTOR_SIZE, RTF_FILE_BEGIN);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

         Result = RTFWrite(Drive, ScratchSector, SECTOR_SIZE, NULL);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
      }

      // do the FATs
      Result = RTFSeek(Drive, StartOfFAT * SECTOR_SIZE, RTF_FILE_BEGIN);
      if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

      Written = StartOfFAT;
      if (Progress) Progress((char *)DeviceName, RTF_FMT_PGS_HIGH_FMT, SystemSectors, Written);

      for (j=0; j<FatCount; j++)
      {
         switch (FATType)
         {
            case 32:
               {
                  DWORD * FPtr = (void*) ScratchSector;
                  FPtr[2] = 0x0FFFFFFF; // this is for the root dir
                  FPtr[1] = 0x0FFFFFFF;
               }
            case 16:
               {
                  WORD * FPtr = (void*) ScratchSector;
                  FPtr[1] = 0xFFFF;
               }
            case 12:
               ScratchSector[2] = 0xFF;
               ScratchSector[1] = 0xFF;
               ScratchSector[0] = MediaDescriptor;
         }
         for (i=0; i<FATSectors; i++)
         {
            Result = RTFWrite(Drive, ScratchSector, SECTOR_SIZE, NULL);
            if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;

            if (i == 0) memset(ScratchSector, 0, 3*4);
         }
         if (Progress) Progress((char *)DeviceName, RTF_FMT_PGS_HIGH_FMT, SystemSectors, Written += FATSectors);
      }

      // and the root directory

      for (i=0; i<RootDirSectors; i++)
      {
         Result = RTFWrite(Drive, ScratchSector, SECTOR_SIZE, NULL);
         if (Result < RTF_NO_ERROR) goto ExitWithErrorCode;
      }
   }

   if (Progress) Progress((char *)DeviceName, RTF_FMT_PGS_HIGH_FMT, SystemSectors, SystemSectors);

//DiscardDataRegion:
   // to help flash disks to perform well, we will delete all data sectors
   // devices which do not support this will ignore this
   #ifdef ERASE_DATA_SECTOR  // kumar remove it
   {
      DWORD AbsOff, ToDo, Done, Increment;
      
      AbsOff = Par.PartitionSector + Par.Partition.RelativeSector;
      ToDo   = Par.Partition.Sectors;
      Increment = ToDo / 50;

      if (RTFRawDiscardSectors(Par.DeviceListIndex, AbsOff + SystemSectors, 1) >= RTF_NO_ERROR)
      {
         if (Progress) Progress((char *)DeviceName, RTF_FMT_PGS_CLEAR_MEDIUM, Par.Partition.Sectors, 0);

         if (FATType == 32)
         {
            RTFRawDiscardSectors(Par.DeviceListIndex, AbsOff + 2, 6-2);  // 2 3 4 5
            RTFRawDiscardSectors(Par.DeviceListIndex, AbsOff + 7, 32-7); // 7-31
         }
         if (Progress) Progress((char *)DeviceName, RTF_FMT_PGS_CLEAR_MEDIUM, Par.Partition.Sectors, SystemSectors);

         ToDo -= SystemSectors;
         Done = SystemSectors;

         while (ToDo > 0)
         {
            DWORD n = (ToDo > Increment) ? Increment : ToDo;
            RTFRawDiscardSectors(Par.DeviceListIndex, AbsOff + Done, n);
            ToDo -= n;
            Done += n;
            if (Progress) Progress((char *)DeviceName, RTF_FMT_PGS_CLEAR_MEDIUM, Par.Partition.Sectors, Done);
         }
      }
   }
   #endif // ERASE_DATA_SECTOR
   
   if (ScratchSector != NULL) free_ctrl_buffer(ScratchSector);
   RTFClose(Drive);
   return FATType;

ExitWithErrorCode:
   if (ScratchSector != NULL) free_ctrl_buffer(ScratchSector);
   RTFClose(Drive);
   return Result;
}


