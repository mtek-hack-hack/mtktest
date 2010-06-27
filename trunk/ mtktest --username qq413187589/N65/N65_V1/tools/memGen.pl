#!/usr/bin/perl
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   memGem.pl
#*
#*    Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. read MEMORY CHIP TYPE from .mak
#*       2. according memory chip type generate custom_MemoryDevice.h
#*
#* Author:
#* -------
#*   Hongzhe.Liu (NOKE)
#*
#*=============================================================



#****************************************************************************
# subroutine:  custom_MemoryDevice_h_BodyGen
# return:     file body 
# input:       $memory type:     memory_device_type
# input:       $memory id:  memory_device_id
#****************************************************************************
sub custom_MemoryDevice_h_BodyGen
{

    ###########

    my ($memroy_device_type, $memory_device_id) = @_;

    ###########
    my $template = <<"__TEMPLATE";
    
#ifndef __CUSTOM_MEMORYDEVICE__
#define __CUSTOM_MEMORYDEVICE__


/*
 ****************************************************************************
 Step 1: Specify memory device type and its complete part number
         Possible memory device type: NOR_RAM_MCP, LPSDRAM
 ****************************************************************************
*/

#define MEMORY_DEVICE_TYPE    $memroy_device_type
#define CS0_PART_NUMBER         $memory_device_id
#define CS1_PART_NUMBER         $memory_device_id


/*
 ****************************************************************************
 Step 2: Specify access type for NOR_RAM_MCP; for LPSDRAM, just assign
         UNDEF_ACCESS to both items (NOR_ACCESS_TYPE and RAM_ACCESS_TYPE)
         Possible access types: ASYNC_ACCESS,
                                SYNC_ACCESS,
                                UNDEF_ACCESS
 ****************************************************************************
*/
#define FLASH_ACCESS_TYPE     ASYNC_ACCESS
#define RAM_ACCESS_TYPE       ASYNC_ACCESS


/*
 ****************************************************************************
 Step 3: Define the first partition size on NOR-flash FAT; if no additional
         partition on NOR-flash disk, it should be 0.

         It is special for NOR-flash disk which has two partitions, the
         first leading is user drive, visible on USB disk, the second may be
         system drive, and invisible from USB disk.

         [VERY IMPORTANT NOTICE]
         =======================
         Please assign the exact value in terms of sectors (one srctor equal
         to 512Bytes).
         MUST NOT assign as
         (TOTAL_FAT_SIZE - SIZE_OF_SYSTEM_DRIVE), because system will keep
         some spaces for disk management.



 ****************************************************************************
*/
#define PARTITION_SECTORS  768


/*
 ****************************************************************************
 Step 4: Define the first partition size on NAND-flash FAT; if no additional
         partition on NAND-flash disk, it should be 0.

         It is special for NAND-flash disk which has two partitions, the
         first leading is user drive, visible on USB disk, the second may be
         system drive or user drive.


         [VERY IMPORTANT NOTICE]
         =======================
         Please assign the exact value in terms of sectors (one srctor equal
         to 512Bytes).
         MUST NOT assign as
         (TOTAL_FAT_SIZE - SIZE_OF_SYSTEM_DRIVE), because system will keep
         some spaces for disk management.

 ****************************************************************************
*/
#if ( defined(__FS_SYSDRV_ON_NAND__) || defined( _NAND_FLASH_BOOTING_) )
#define PARTITION_SIZE         (180000)
#else
#define PARTITION_SIZE         (0)
#endif


/*
 ****************************************************************************
 Step 5: This is an optional step sepcial for NFB (NAND-flash Booting)
         system only.

         Users are responsible to specify the partition on NAND-flash,
         Step a. Start address of FAT on NAND-flash (FLASH_BASE_ADDRESS),
         Step b. Total FAT size on NAND-flash disk (ALLOCATED_FAT_SPACE)

         For example, on 128MB NAND-flash, code segment occupies 32MB, the
         balanced 96MB is reserved for NAND-flash disk, then

         FLASH_BASE_ADDRESS  = 0x02000000
         ALLOCATED_FAT_SPACE = 0x06000000

         [VERY IMPORTANT NOTICE]
         =======================
         The spare area is excluding from the FAT SPACE!!!

 ****************************************************************************
*/
#ifdef _NAND_FLASH_BOOTING_

#define FLASH_BASE_ADDRESS 0x02000000		// 32MB
#define ALLOCATED_FAT_SPACE 0x06000000		// 96MB

#endif /* _NAND_FLASH_BOOTING_ */


/*
 ****************************************************************************
 Step 6: MTK NOR FDM is upgraded to 5.0 from 2006/Q3 to support large NOR-flash
         disk (multi-bank), for example, disk space larger than 64blocks.
         
         The major differnces of NOR FDM 5.0 and NOR FDM 4.0 as below:
         1. RAM consumption
            To manage 32MB INTEL M18 NOR-flash disk, FDM 5.0 consumes 1KB,
            but FDM 4.0 takes 32KB.
         2. Addressable block numbers
            The addressable space of NOR FDM 5.0 is 65K-1 blocks, but NOR FDM 4.0
            is limited at 128-1 blocks.
         3. Idle reclaim and manual reclaim are implemented on NOR FDM 5.0.

         To enable NOR FDM 5.0 on NOR-flash disk, please enable the following 
         definition and customize custom_nor_large_disk.c; the option is swithable 
         at customer site without deliver new library.
         
         [REMIND]
         ========
         To manage small disk space, like smaller than 64 blocks, FDM 4.0 is
         recommended.

 ****************************************************************************
*/
//#define __NOR_FDM5__

#endif /* __CUSTOM_MEMORYDEVICE__ */


__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

__TEMPLATE

   return $template;
}


#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author) = @_;
    my @stat_ar = stat $MEMORY_DEVICE_LIST_XLS;
    my ($day, $month, $year) = (localtime($stat_ar[9]))[3,4,5]; $month++; $year+=1900;
    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   Noke all project
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *   $author
 *
 *
  ****************************************************************************/

__TEMPLATE

   return $template;
}


my $MEMORY_DEVICE_HDR  = Win32::GetCwd()."\\".$ARGV[0];
my $MEMORY_DEVICE_TYPE  = $ARGV[1];
my $MEMORY_DEVICE_ID  = $ARGV[2];

my $CUSTOM_EMI_H  = $MEMORY_DEVICE_HDR;
my $CUSTOM_EMI_C  = $MEMORY_DEVICE_HDR;
my $FLASH_OPT_H   = $MEMORY_DEVICE_HDR;
my $SWITCH_CLK_C  = $MEMORY_DEVICE_HDR;

$CUSTOM_EMI_H     =~ s/\\custom_MemoryDevice\.h$/\\custom_EMI\.h/i;
$CUSTOM_EMI_C     =~ s/\\custom_MemoryDevice\.h$/\\custom_EMI\.c/i;
$FLASH_OPT_H      =~ s/\\custom_MemoryDevice\.h$/\\flash_opt\.h/i;
$SWITCH_CLK_C     =~ s/\\custom_MemoryDevice\.h$/\\custom_switchclock\.c/i;


############################################################
#
#
#  del old file
#
print "[Hongzhe.Liu] .... delete $MEMORY_DEVICE_HDR ...\n";
system "del $MEMORY_DEVICE_HDR";
print "[Hongzhe.Liu] .... delete $CUSTOM_EMI_H ...\n";
system "del $CUSTOM_EMI_H";
print "[Hongzhe.Liu] .... delete $CUSTOM_EMI_C ...\n";
system "del $CUSTOM_EMI_C";
print "[Hongzhe.Liu] .... delete $FLASH_OPT_H ...\n";
system "del $FLASH_OPT_H";
print "[Hongzhe.Liu] .... delete $SWITCH_CLK_C ...\n";
system "del $SWITCH_CLK_C";

############################################################
#
#
#   gen new file
#
print "[Hongzhe.Liu] .... Generate $MEMORY_DEVICE_HDR ...\n";
open (MEMORY_DEVICE_HDR, ">$MEMORY_DEVICE_HDR") or die "cannot open $MEMORY_DEVICE_HDR\n";
print MEMORY_DEVICE_HDR &copyright_file_header();
print MEMORY_DEVICE_HDR &description_file_header(
							"custom_MemoryDevice.h",
							"This Module defines the memory device information.",
							"Hongzhe.liu (NOKE,  by memGen.pl) ");
print MEMORY_DEVICE_HDR &custom_MemoryDevice_h_BodyGen($MEMORY_DEVICE_TYPE, $MEMORY_DEVICE_ID);
close MEMORY_DEVICE_HDR or die "fail to generate MEMORY_DEVICE_HDR\n$!\n";
print "[Hongzhe.Liu] .... $MEMORY_DEVICE_HDR is generated\n";

















