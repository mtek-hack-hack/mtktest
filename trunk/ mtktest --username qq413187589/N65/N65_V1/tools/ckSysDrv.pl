#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   ckSysDrv.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script parse prepocessed fs_quota.c and nvram_user_config.c to
#*       1. check if system drive space is enough
#*       2. display current flash usage
#*
#* Author:
#* -------
#*   Sherman Wang  (mtk00590)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision:  $
#* $Modtime: $
#* $Log: $
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use Getopt::Std;
use POSIX;

#****************************************************************************
# Constants
#****************************************************************************
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

#****************************************************************************
# Usage
#****************************************************************************
sub usage
{
	print "perl ckSysDrv.pl <Preprocessed fs_quota.c> <Preprocessed nvram_user_config.c>\n";
	exit(0);
}

#****************************************************************************
# parsing command arguments
#****************************************************************************
my %option = ();
if (!getopts('hdc:',\%option) or $option{'h'})
{
	&usage;
	exit(0);
}
$DebugPrint = 1 if $option{'d'};

my $FLASH_CFG  = $ARGV[0];
my $FS_STAT    = $ARGV[1];
my $NVRAM_FILE = $ARGV[2];
my $NVRAM_STAT = $ARGV[3];
my $CUSTOM_EMI = $ARGV[4];
my $SNOR_ERASE_QUEUE_SIZE = 0;

#****************************************************************************************
# Get SNOR_ERASE_QUEUE_SIZE value from custom_emi.h when enhanced single bank is enabled.
#****************************************************************************************
if(defined $ARGV[4]){
	open(EMI_FILE,"<$CUSTOM_EMI") or die "Cannot open $CUSTOM_EMI:$!\n";
	while(<EMI_FILE>){
		if($_ =~ /SNOR_ERASE_QUEUE_SIZE\s+(.+)/i){
			$SNOR_ERASE_QUEUE_SIZE = $1;
		}
	}
}

#****************************************************************************
# Parse preprocessed custom_MemoryDevice.h and custom_EMI.h
#****************************************************************************
open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";

my $backup= $/;
undef $/;

my $reading 	   = <FLASH_CFG>;
my $max_blk_size  = 0;     # in Byte
my $regions;
my $allocated_fat_space;   # in Byte
my $partition_sectors;     # in Byte

# macth  FlashRegionInfo RegionInfo[] =
#        {
#           {0x20000, 16},
#           EndRegionInfo
#        };
if ( $reading =~ /\s+FlashRegionInfo\s+RegionInfo\s*\[\s*\]\s*=\s*\{([\w\W]+EndRegionInfo)\s*\}\s*;/ )
{
   $regions = $1;
}
else
{
   die "RegionInfo is NOT found!";
}

# match {0x20000, 16},
while ($regions =~ /\{\s*(0x[\dA-Fa-f]+)\s*,\s*\d+\s*\}\s*,/)
{
   $regions =$';
   $max_blk_size = hex($1) if ($max_blk_size < hex($1));
}

# macth   int allocated_fat_space =  0x00200000 ;
if ( $reading =~ /int\s+allocated_fat_space\s*=\s*(0x[\dA-Fa-f]+)\s*;/)
{
   $allocated_fat_space = hex($1);
}
else
{
   die "ALLOCATED_FAT_SPACE is NOT found!";
}

# macth   int partition_sectors =  0 ;
if ( $reading =~ /int\s+partition_sectors\s*=\s*(\d+)\s*;/)
{
   $partition_sectors = $1 * 512;
}
else
{
   die "PARTITION_SECTORS is NOT found!";
}

close FLASH_CFG;

my $drive_overhead   = 1.5*$max_blk_size + 8*1024;
if(defined $ARGV[4]){
	$drive_overhead   = $SNOR_ERASE_QUEUE_SIZE*$max_blk_size + 8*1024;
}
my $free_space       = $allocated_fat_space - $partition_sectors - $drive_overhead - 8*1024; # in Byte
my $cluster_size     = -1; # in Byte
if ($free_space < 1024*1024)
{
   $cluster_size = 512;
}
elsif ($free_space < 4096*1024)
{
   $cluster_size = 1024;
}
elsif ($free_space < 8192*1024)
{
   $cluster_size = 2048;
}
elsif ($free_space < 16384*1024)
{
   $cluster_size = 4096;
}

# when free space >= 16MB, no need to determine system drive free space;
# $cluster_size will be set as -1

print "$allocated_fat_space $partition_sectors $max_blk_size $cluster_size\n" if ($DebugPrint == 1);
#****************************************************************************
# Parse ~fs_quota_usage.log to determine folder size
#****************************************************************************
# my $folder =
# {
#    FOLDER    => $folder_name,
#    COUNT   	=> $count,
#    UNIT      => $unit_byte,
#    SIZE      => $size_in_byte
# }
my @folder_size = ();

open (FS_STAT, "<$FS_STAT") or die "cannot open $FS_STAT\n";
$/ = $backup;

while (<FS_STAT>)
{
   # match {Z:\@USER\, 0, 83968,  0xf1f2f3f4 ,  0x1 },
   if (/\{\s*(Z.+\\)\s*,[^,]+,\s*(\d+)\s*,[^,]+,\s*(0x[\dA-Fa-f]+)\s*\}\s*,/i)
   {
      my %this_folder      = ();
      $this_folder{FOLDER} = $1;
      $this_folder{COUNT}  = $2;
      $this_folder{UNIT}   = $3;
      $this_folder{SIZE}   = ($this_folder{UNIT} eq '0x1') ? ($this_folder{COUNT}) : ($this_folder{COUNT} * $cluster_size * 1024);

      push @folder_size, \%this_folder;

   }
}

close FS_STAT;

foreach my $folder (@folder_size)
{
   printf ("%-20s %10s\n", $folder->{FOLDER}, $folder->{SIZE}) if ($DebugPrint == 1);
}

#****************************************************************************
# Parse preprocessed nvram_xxx.c
#****************************************************************************
# my $app =
# {
#    APPLICATION  => $app_name,
#    UNIT_SIZE    => $unit_size,
#    RECORD_NUM   => $number,
#    SIZE         => $size_in_byte
# }
my @app_rev_size = ();

open (NVRAM_FILE, "<$NVRAM_FILE") or die "cannot open $NVRAM_FILE\n";

undef $/;
my $reading 	= <NVRAM_FILE>;

close NVRAM_FILE;

# macth const ltable_entry_struct logical_data_item_table_cust[NVRAM_EF_LAST_LID_CUST- NVRAM_EF_LAST_LID_VENDOR ] =
if ( $reading =~ /\n\s*ltable_entry_struct\s+logical_data_item_table_\w*\s*\[.*\]\s*=/ )
{
   $reading =$';
}
else
{
   die "ltable_entry_struct logical_data_item_table_xxx is NOT found!";
}


# match { NVRAM_EF_CUSTPACK_VERNO_LID, 34 , 1 , NVRAM_EF_ZERO_DEFAULT, (kal_uint8)(  0x2  |  0x1  ), 0x01 , NVRAM_DRV_FDM, "CP00", "000"  , "Cust Pack Bin Ver\0", NVRAM_AVERAGE_LID, (kal_uint8) ~0 }
#while ($reading =~ /\{\s*(NVRAM_EF_[\w\d]+_LID)\s*,\s*([^,]+),\s*([^,]+),[^\}]+\}\s*/)
while ($reading =~ /\{\s*(NVRAM_[\w\d]+)\s*,\s*([^,]+),\s*([^,]+),\s*[^,]+,\s*[^,]+,\s*[^,]+,\s*[^,]+,\s*[^,]+,\s*([^,]+),[^\}]+\}\s*/)
{
   $reading =$';

   my %this_app            = ();
   $this_app{APPLICATION}  = $1;
   $this_app{UNIT_SIZE}    = $2;
   $this_app{RECORD_NUM}   = $3;
   $this_app{APP_NAME}     = $4;
   next unless ($this_app{APP_NAME} =~ /\"/);

   $this_app{UNIT_SIZE}    =~ s/\s//g;
   $this_app{RECORD_NUM}   =~ s/\s//g;
   $this_app{APP_NAME}     =~ s/^\"(.+)\\0\"$/$1/;

   my $exp1_rslt           = `perl -e "print ($this_app{UNIT_SIZE})" 2>&1`;
   my $exp2_rslt           = `perl -e "print int($this_app{RECORD_NUM})" 2>&1`;
   $exp1_rslt              =~ s/\s//g;
   $exp2_rslt              =~ s/\s//g;
   if (($exp1_rslt =~ /^\d+\.?\d*$/) && ($exp2_rslt =~ /^\d+\.?\d*$/)) # if it can't be calculated by perl
   {
      $this_app{SIZE}      = $exp1_rslt * $exp2_rslt;
   }
   else
   {
#      print "$this_app{UNIT_SIZE} \t $this_app{RECORD_NUM}\n" if ($DebugPrint == 1);
      $this_app{SIZE}      = "unknown";
   }

   push @app_rev_size, \%this_app;
}

foreach my $app (@app_rev_size)
{
   printf ("%-40s %10s %-25s\n", $app->{APPLICATION}, $app->{SIZE}, $app->{APP_NAME}) if ($DebugPrint == 1);
}

# Parse ~nvram_lid_size.log to determine LID size
open (NVRAM_STAT, "<$NVRAM_STAT") or die "cannot open $NVRAM_STAT\n";

my %app_size = ();
$/ = $backup;

while (<NVRAM_STAT>)
{
   if (/(\d+)\s*(\d+)\s*(\w.+\w)/)
   {
      if (defined $app_size{$3})
      {
         die "$3 has different sizes $app_size{$3} vs. $2!" unless ($app_size{$3} == $2);
      }
      else
      {
         $app_size{$3} = $2;
#         print "$app_size{$3} $3\n";
      }
   }
}

close NVRAM_STAT;

while ( (my $key, my $value) = each %app_size)
{
#   print "$key $value\n" if ($DebugPrint == 1);
}

foreach my $app (@app_rev_size)
{
   if ($app->{SIZE} ne 'unknown')
   {
      warn "$app->{APPLICATION} has different sizes $app->{SIZE} vs. $app_size{$app->{APP_NAME}}!" unless ($app->{SIZE} == $app_size{$app->{APP_NAME}});
   }
   else
   {
      $app->{SIZE} = $app_size{$app->{APP_NAME}};
   }
   printf ("%-40s %10s %-25s\n", $app->{APPLICATION}, $app->{SIZE}, $app->{APP_NAME}) if ($DebugPrint == 1);
}

#****************************************************************************
# Determine FAT overhead
#****************************************************************************
# Example:
#Z:\@WAP\
#Z:\@DRM\
#Z:\NVRAM\NVD_DATA\NVRAM_EF_PHB_LID
#                 \NVRAM_EF_SMS_LID
# dir entry of level-1 = 3 (@WAP, @DRM, NVRAM)
# dir entry of level-2 = 1 + 2 (NVD_DATA, ".", "..")
# dir entry of level-3 = 2 + 2 (NVRAM_EF_PHB_LID, NVRAM_EF_SMS_LID, ".", "..")

my $fat_overhead_cluster;
if ($cluster_size > 0)
{
   # level-1 directory entries + level-2 directory entries + level-3 directory entries
   $fat_overhead_cluster = ceil(($#folder_size+1)*32 / $cluster_size) +
                           ceil((2+1)*32 / $cluster_size) +
                           ceil((2+$#app_rev_size)*32 / $cluster_size);
}

#****************************************************************************
# Print out the result
#****************************************************************************
#1.
#  die "Free space is greater than 16MB!";

print ("                                               Byte Cluster\n");
print ("===========================================================\n");

print "$partition_sectors $max_blk_size $cluster_size\n" if ($DebugPrint == 1);

printf ("Allocated FAT Space %31s \n", $allocated_fat_space);
printf ("Partition Sectors   %31s \n", $partition_sectors);
printf ("Drive Overhead %36s\n", $drive_overhead);
print  ("===========================================================\n");

my $free_space_cluster     = ceil($free_space/$cluster_size); # ceil of floor ???
my $app_rev_total          = 0;
my $app_rev_total_cluster  = 0;
my $folder_total           = 0;
my $folder_total_cluster   = 0;

if ($cluster_size > 0)
{
   printf ("Free Space for Folders and Applications %11s %7s\n\n", $free_space, $free_space_cluster);
   print  ("-----------------------------------------------------------\n");
   printf ("Cluster Size %38s       1\n", $cluster_size);
   print  ("-----------------------------------------------------------\n");
   printf ("FAT Overhead %38s %7s\n", $fat_overhead_cluster*$cluster_size, $fat_overhead_cluster);
   print  ("-----------------------------------------------------------\n");
   foreach my $app (@app_rev_size)
   {
      if ($app->{SIZE} ne "unknown")
      {
         printf ("%-40s %10s %7s\n", $app->{APPLICATION}, $app->{SIZE}, ceil($app->{SIZE}/$cluster_size));
         $app_rev_total          += $app->{SIZE};
         $app_rev_total_cluster  += ceil($app->{SIZE}/$cluster_size);
      }
      else
      {
         printf ("%-40s %10s %7s\n", $app->{APPLICATION}, $app->{SIZE}, $app->{SIZE});
      }
   }
   printf ("\nTOTAL %45s %7s\n", $app_rev_total, $app_rev_total_cluster);
   print  ("-----------------------------------------------------------\n");
   foreach my $folder (@folder_size)
   {
      if ($folder->{SIZE} ne "unknown")
      {
         printf ("%-40s %10s %7s\n", $folder->{FOLDER}, $folder->{SIZE}, ceil($folder->{SIZE}/$cluster_size));
         $folder_total           += $folder->{SIZE};
         $folder_total_cluster   += ceil($folder->{SIZE}/$cluster_size);
      }
      else
      {
         printf ("%-40s %10s %7s\n", $folder->{FOLDER}, $folder->{SIZE}, $folder->{SIZE});
      }
   }
   printf ("\nTOTAL %45s %7s\n", $folder_total, $folder_total_cluster);

   print  ("===========================================================\n");

   my $folder_and_app_clusters   = $fat_overhead_cluster + $app_rev_total_cluster + $folder_total_cluster;
   my $diff                      = $free_space_cluster - $folder_and_app_clusters;
   if ( $diff >= 0 )
   {
      print "\n\nFree Space $free_space_cluster clusters are enough for Folders and Applications $folder_and_app_clusters clusters.\n";
      print "$diff clusters are left.\n";
   }
   else
   {
      print "\n\nFree Space $free_space_cluster clusters are NOT enough for Folders and Applications $folder_and_app_clusters clusters.\n";
      printf ("Shortage is %d clusters.\n", $diff*(-1));
      die "Free clusters are NOT enough. Check ckSysDrv.log for detail!\n";
   }
}
else
{
   printf ("Free Space for Folders and Applications %11s\n\n", $free_space);
   print  ("-----------------------------------------------------------\n");
   print  ("Cluster Size  No need to be determined if Free space >= 16MB\n");
   print  ("-----------------------------------------------------------\n");
   print  ("FAT Overhead  No need to be determined if Free space >= 16MB\n");
   print  ("-----------------------------------------------------------\n");
   foreach my $app (@app_rev_size)
   {
      printf ("%-40s %10s\n", $app->{APPLICATION}, $app->{SIZE});
      $app_rev_total          += $app->{SIZE} if ($app->{SIZE} ne "unknown");
   }
   printf ("\nTOTAL %45s\n", $app_rev_total);
   print  ("-----------------------------------------------------------\n");
   foreach my $folder (@folder_size)
   {
      printf ("%-40s %10s\n", $folder->{FOLDER}, $folder->{SIZE});
      $folder_total           += $folder->{SIZE} if ($folder->{SIZE} ne "unknown");
   }
   printf ("\nTOTAL %45s\n", $folder_total);

   print  ("===========================================================\n");
   print "\n\nFree space >= 16MB are enough for Folders and Applications.\n";

}