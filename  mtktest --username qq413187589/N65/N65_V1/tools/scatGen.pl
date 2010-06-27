#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2007
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
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   scatGen.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script aim to generate scatter file base on Makefile and custom_EMI.h
#*       1. generate scatter file if not exists
#*       2. if MULTIPLE_BINARY_FILES , generate custom_jump_tbl.c if not exists
#*       3. if MULTIPLE_BINARY_FILES , generate custom_jump_tbl.h if not exists
#*
#* Author:
#* -------
#*   JI Huang  (mtk01077)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
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

#****************************************************************************
# Constants
#****************************************************************************

#****************************************************************************
# File Names
#****************************************************************************
my $SCATTERFILE      = $ARGV[0];
my $themf            = $ARGV[1];
my $CUSTOM_EMI_H     = $ARGV[2];

#****************************************************************************
# 1 >>> main judges : scatter file exists or not
#****************************************************************************
if (-e $SCATTERFILE)
{
    print "$SCATTERFILE already exists\n";
    exit 0;
}

#****************************************************************************
# 2 >>> parse Project Make File
#****************************************************************************
my %MAKEFILE_OPTIONS;
my $keyname;

die "$themf did NOT exist!\n" if (!-e $themf);

if ($themf =~ /make\\(\w+)_(\w+).mak/i) {
  $MAKEFILE_OPTIONS{'MODE'} = uc($2);
}

open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $MAKEFILE_OPTIONS{$keyname} = uc($2);
  }
  elsif (/^CUSTOM_OPTION\s*\+=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $MAKEFILE_OPTIONS{$keyname} = 'TRUE';
  }
}
close (FILE_HANDLE);

#****************************************************************************
# 3 >>> parse key definition in CUSTOM_EMI_H
#       also, block information gathered
#****************************************************************************
my %EMI_H_Value;

open (EMIH_HANDLE, "<$CUSTOM_EMI_H") or die "cannot open $CUSTOM_EMI_H\n";
while (<EMIH_HANDLE>) {
   if    (/^#define DRAM_SIZE\s+(\S+)/)
   {
      $EMI_H_Value{'DRAM_SIZE'} = $1;
   }
   elsif (/^const kal_uint32  EMI_EXTSRAM_SIZE = \((\S+)<<20\)\s*>>\s*3;/)
   {
      $EMI_H_Value{'EXTSRAM_SIZE'} = $1;
   }
   elsif (/^#define FLASH_BASE_ADDRESS\s+(\S+)/)
   {
      $EMI_H_Value{'FLASH_BASE_ADDRESS'} = $1;
   }
   elsif (/^#define ALLOCATED_FAT_SPACE\s+(\S+)/)
   {
      $EMI_H_Value{'ALLOCATED_FAT_SPACE'} = $1;
   }
   elsif (/^FLASH_REGIONINFO_VAR_MODIFIER FlashBlockTBL\s+\S+/)
   {
      $EMI_H_Value{'BlockTBLFlag'} ++;
      $EMI_H_Value{'BlockTBL'} = ();
   }
   elsif (defined $EMI_H_Value{'BlockTBLFlag'})
   {
      $EMI_H_Value{'BlockTBLTxt'} .= $_;
      # debug purpose
      # print $_;
      if (/\{\s*(\S+)\s*,\s*(\S+)\s*\}/)
      {
         my $offset = hex($1);
         my $blksz  = hex($2);
         $EMI_H_Value{'BlockTBL'}->{$offset} = $blksz;
         # debug purpose
         # print $offset, "\n";
      }
      delete $EMI_H_Value{'BlockTBLFlag'} if (/^\s+EndBlockInfo\s+/);
   }
   elsif (/^\/\/ PROJECT_EXPECTED_CODESIZE\s+(\w+)/)
   {
      $EMI_H_Value{'PROJECT_EXPECTED_CODESIZE'} = $1;
   }
}
close (EMIH_HANDLE);

#****************************************************************************
# 4 >>> Board parameters gathering
#****************************************************************************
my %BOARD_PARAMETERS;
&gather_board_parameters(\%BOARD_PARAMETERS);

#****************************************************************************
# 5 >>> Flash information gathering
#       Dump Block Table 
#****************************************************************************
my %NORFLASH_INFO;
# debug purpose
#if (defined $EMI_H_Value{'BlockTBL'})
if (0)
{
    my $href   = $EMI_H_Value{'BlockTBL'};
    my @offset = sort {$a <=> $b} keys %$href;

    print "Block Table Retrieved\n----------\n";
    foreach my $i (@offset)
    {
       printf "0x%X => 0x%X \n", $i , $EMI_H_Value{'BlockTBL'}->{$i};
    }
}

$NORFLASH_INFO{'AVAILABLE_SIZE'} = $BOARD_PARAMETERS{'FLASH'};
if (defined $EMI_H_Value{'BlockTBL'})
{
    $NORFLASH_INFO{'BLOCKS_TABLE'}   = $EMI_H_Value{'BlockTBL'};
}

#****************************************************************************
# 5 >>> Generate Scatter File
#****************************************************************************
require "tools/scatGenLib.pl";
my $scat_content = &scatGen_main(sub { my ($key) = @_;
                                        if (exists $MAKEFILE_OPTIONS{$key})
                                        {   return $MAKEFILE_OPTIONS{$key};
                                        }
                                        else
                                        {   return undef;
                                        }
                                     },
                                 $BOARD_PARAMETERS{'BB'},
                                 \%NORFLASH_INFO,
                                 $BOARD_PARAMETERS{'EXTSRAM'}
                                );

die "Please create $SCATTERFILE manually\n" unless defined $scat_content;

open (SCATTER_TXT, ">$SCATTERFILE") or die "cannot open $SCATTERFILE\n";

print SCATTER_TXT &copyright_file_header();
print SCATTER_TXT &description_file_header( $SCATTERFILE,
                         "system auto generator ". &scatGen_verno(),
                         &dump_board_parameters());
print SCATTER_TXT $scat_content;
close SCATTER_TXT;

print "$SCATTERFILE is generated\n";

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit;

#****************************************************************************
# subroutine:  gather the required information for board
# return:      void (add key / value in input hash)
#****************************************************************************
sub gather_board_parameters
{
    my ($hash_ref) = @_;

    # <1> get platform
    $hash_ref->{'FLASH'}   = &comp_flash_size();
    $hash_ref->{'EXTSRAM'} = &comp_ram_size();
    $hash_ref->{'BB'}      = $MAKEFILE_OPTIONS{'platform'};

    # <2> gather sw features
    $hash_ref->{'SWCFG'}   = "";

    if (exists $MAKEFILE_OPTIONS{'nand_flash_booting'}
           and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq "TRUE")
    {
        $hash_ref->{'NFB'} = 1;
        $hash_ref->{'SWCFG'} .= "NFB ";
    }
    if (exists $MAKEFILE_OPTIONS{'fota_enable'}
           and $MAKEFILE_OPTIONS{'fota_enable'} ne 'NONE')
    {
        $hash_ref->{'SWCFG'} .= "FOTA ";
    }
    if (exists $MAKEFILE_OPTIONS{'usb_download'}
           and $MAKEFILE_OPTIONS{'usb_download'} ne 'NONE')
    {
        $hash_ref->{'SWCFG'} .= "USBDOWNLOAD ";
    }
    if (exists $MAKEFILE_OPTIONS{'multiple_binary_files'}
           and $MAKEFILE_OPTIONS{'multiple_binary_files'} eq 'TRUE')
    {
        $hash_ref->{'SWCFG'} .= "MULTIBIN ";
    }
    if (exists $MAKEFILE_OPTIONS{'secure_support'}
           and $MAKEFILE_OPTIONS{'secure_support'} eq 'TRUE')
    {
        $hash_ref->{'SWCFG'} .= "SECURE ";
    }
    if (exists $MAKEFILE_OPTIONS{'enhanced_single_bank_nor_flash_support'}
           and $MAKEFILE_OPTIONS{'enhanced_single_bank_nor_flash_support'} eq 'TRUE')
    {
        $hash_ref->{'SWCFG'} .= "ESBNOR ";
    }
}

#****************************************************************************
# subroutine:  dump the board parameters
# return:      the summary string 
#****************************************************************************
sub dump_board_parameters
{
    my ($bb, $loadsize, $ramsize) = ($BOARD_PARAMETERS{'BB'},
                                     $BOARD_PARAMETERS{'FLASH'} / (1024 * 1024),
                                     $BOARD_PARAMETERS{'EXTSRAM'} / (1024 * 1024)
                                    );
    $loadsize = $loadsize . "MB";
    $ramsize  = $ramsize . "MB";
    my $sw_features = $BOARD_PARAMETERS{'SWCFG'};

    my $template1 = <<"__TEMPLATE";
;--------------------
; SCHEME   : external $loadsize flash memory and $ramsize SRAM
; PLATFORM : $bb
; FEATURES : $sw_features
;--------------------
__TEMPLATE

    my $template2 = <<"__TEMPLATE";
;--------------------
; SCHEME   : external NAND flash and $ramsize LPSDRAM
; PLATFORM : $bb
; FEATURES : $sw_features
;--------------------
__TEMPLATE

   if (exists $BOARD_PARAMETERS{'NFB'}) { return $template2; }
   else                                 { return $template1; }
}

#****************************************************************************
# subroutine:  comp_flash_size
# return:      EMI value
#****************************************************************************
sub comp_flash_size
{
   if (exists $EMI_H_Value{'PROJECT_EXPECTED_CODESIZE'})
   {
       return hex($EMI_H_Value{'PROJECT_EXPECTED_CODESIZE'});
   }
   elsif (exists $MAKEFILE_OPTIONS{'system_drive_on_nand'} and $MAKEFILE_OPTIONS{'system_drive_on_nand'} eq 'TRUE')
   {
      my $total_flash_size;
      $total_flash_size = hex($EMI_H_Value{'ALLOCATED_FAT_SPACE'});
      $total_flash_size += hex($EMI_H_Value{'FLASH_BASE_ADDRESS'});
      return $total_flash_size;
   }
   return hex($EMI_H_Value{'FLASH_BASE_ADDRESS'});
}

#****************************************************************************
# subroutine:  comp_ram_size
# return:      EMI value
#****************************************************************************
sub comp_ram_size
{
   if ($EMI_H_Value{'EXTSRAM_SIZE'} eq 'DRAM_SIZE')
   {
      return $EMI_H_Value{'DRAM_SIZE'} * 1024 * 1024 / 8;
   }
   $EMI_H_Value{'EXTSRAM_SIZE'} =~ s/\(//;
   $EMI_H_Value{'EXTSRAM_SIZE'} =~ s/\)//;

   return $EMI_H_Value{'EXTSRAM_SIZE'} * 1024 * 1024 / 8;
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
    my ($filename, $author, $board_description) = @_;
    my ($day, $month, $year) = (localtime)[3,4,5]; $month++; $year+=1900;
    $filename =~ s/.*\\//;
    my $template = <<"__TEMPLATE";
;/*****************************************************************************
; *
; * Filename:
; * ---------
; *   $filename
; *
; * Project:
; * --------
; *   Maui_Software
; *
; * Description:
; * ------------
; *   defines the memory map for the validation board
; *
; * Author:
; * -------
; *   $author
; *
; * Auto Generated Date:
; * -------
; *   $year/$month/$day
; *
; * Revision History:
; * -------
; * \$Log: $filename $author \$
; * 
; ****************************************************************************/
;
$board_description
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
;/*****************************************************************************
;*  Copyright Statement:
;*  --------------------
;*  This software is protected by Copyright and the information contained
;*  herein is confidential. The software may not be copied and the information
;*  contained herein may not be used or disclosed except with the written
;*  permission of MediaTek Inc. (C) 2007
;*
;*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
;*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
;*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
;*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
;*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
;*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
;*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
;*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
;*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
;*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
;*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
;*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
;*
;*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
;*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
;*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
;*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
;*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
;*
;*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
;*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
;*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
;*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
;*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
;*
;*****************************************************************************/
;
__TEMPLATE

   return $template;
}

