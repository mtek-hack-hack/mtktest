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
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   ckScatter.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script embedded checking rules for scatter file and custom memory device
#*       1. Load View      --- NOR Flash
#        2. Execution View --- RAM Device
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
my $CKSCATTER_VERNO     = " V0.04";

#****************************************************************************
# File Names
#****************************************************************************
my $SCATTERFILE      = $ARGV[0];
my $themf            = $ARGV[1];
my $CUSTOM_EMI_H     = $ARGV[2];

#****************************************************************************
# 1 >>>  open and read scatter file, keep the important content in memory
#****************************************************************************
my %Scat_Content;

open (SCAT_HANDLE, "<$SCATTERFILE") or die "cannot open $SCATTERFILE\n";
while (<SCAT_HANDLE>) {
   if (/\(.+\)/) {next;}
   if (/;/) {s/;.*//;}
   if (/{/ or /}/ or /\S+/) { $Scat_Content{$.} = $_; }
}
close (SCAT_HANDLE);
#&dump_scatter_file_structure();

#****************************************************************************
# 2 >>> parse Project Make File
#****************************************************************************
my %MAKEFILE_OPTIONS;
my $keyname;

die "$themf did NOT exist!\n" if (!-e $themf);

open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $MAKEFILE_OPTIONS{$keyname} = uc($2);
  }
}
close (FILE_HANDLE);

#****************************************************************************
# 3 >>> parse key definition in CUSTOM_EMI_H
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
}
close (EMIH_HANDLE);
#&dump_custom_emi_h_values();

#****************************************************************************
# 4 >>> Build the LOAD View List and Execution View List
#****************************************************************************
# use hash in hash structure to store the parseing
my %LoadView;
my %ExecView;

&parse_scatter_file_structure();
#print "=== LOAD VIEW ===\n";
#&dump_load_view();
#print "=== EXEC VIEW ===\n";
#&dump_exec_view();

#****************************************************************************
# 5 >>> determine NOR-FLASH BOOTING based or NAND-FLASH BOOTING based
#****************************************************************************
my $flash_size  = &comp_flash_size();
my $ram_size    = &comp_ram_size();
my $load_length = &comp_load_length();
my $ram_boundary= &comp_ram_boundary();

#print $flash_size, "\n", $ram_size, "\n", $load_length, "\n", $ram_boundary, "\n";

if (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq "TRUE")
{
   print "LOAD VIEW , bypass check on NAND FLASH BOOTING\n";
   printf "EXEC VIEW , EMI 0x%x , SCAT 0x%x\t%s\n", $ram_size , $ram_boundary, ($ram_size >= $ram_boundary) ? "PASS" : "ERROR";
   if ($ram_size > $ram_boundary and ($ram_size - $ram_boundary) >= 1024 * 1024)
   {
      print "Warnning : RAM / Exec View configure waste at least 1MB\n";
   }
}
else
{
   printf "LOAD VIEW , EMI 0x%x , SCAT 0x%x\t%s\n", $flash_size, $load_length, ($flash_size >= $load_length)? "PASS" : "ERROR";
   printf "EXEC VIEW , EMI 0x%x , SCAT 0x%x\t%s\n", $ram_size , $ram_boundary, ($ram_size >= $ram_boundary) ? "PASS" : "ERROR";
   if ($flash_size > $load_length and ($ram_size - $ram_boundary) >= 1024 * 1024)
   {
      print "Warnning : NOR flash / Load View configure waste at least 1MB\n";
   }
   if ($ram_size > $ram_boundary and ($ram_size - $ram_boundary) >= 1024 * 1024)
   {
      print "Warnning : RAM / Exec View configure waste at least 1MB\n";
   }
}

#****************************************************************************
# subroutine:  comp_flash_size
# return:      EMI value
#****************************************************************************
sub comp_flash_size
{
   if (exists $MAKEFILE_OPTIONS{'system_drive_on_nand'} and $MAKEFILE_OPTIONS{'system_drive_on_nand'} eq 'TRUE')
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
# subroutine:  comp_load_length
# return:      LoadView
#****************************************************************************
sub comp_load_length
{
   my @region_list = sort { $LoadView{$a}->{'seq'} <=> $LoadView{$b}->{'seq'} } keys %LoadView;
   return hex($LoadView{ $region_list[0] } -> {'length'});
}

#****************************************************************************
# subroutine:  comp_ram_boundary
# return:      LoadView
#****************************************************************************
sub comp_ram_boundary
{
   my $addr;
   if    (exists $ExecView{'DUMMY_END'})
   {
      $addr = $ExecView{'DUMMY_END'} -> {'begin'};
      $addr = hex($addr);
      if ($addr & 0x08000000)
      {
         $addr = $addr & (~0x08000000);
      }
   }
   elsif (exists $ExecView{'EXTSRAM'} and exists $ExecView{'EXTSRAM'}->{'length'})
   {
      $addr = $ExecView{'EXTSRAM'}->{'length'};
      $addr = hex($addr);
   }
   elsif (exists $ExecView{'EXTSRAM_DSP_TX'})
   {
      $addr = $ExecView{'EXTSRAM_DSP_TX'} -> {'begin'};
      $addr = hex($addr);
      if ($addr & 0x08000000)
      {
         $addr = $addr & (~0x08000000);
      }
   }
   else
   {
      die "Unknown Scatter File Structure";
   }
   return $addr;
}

#****************************************************************************
# subroutine:  dump_exec_view
# return:      all %LoadView ; key = RegionName , value = hash ref , begin , attr , length
#****************************************************************************
sub dump_exec_view
{
   foreach my $region_name (sort { $ExecView{$a}->{'seq'} <=> $ExecView{$b}->{'seq'} } keys %ExecView)
   {
      print $region_name, "\t", $ExecView{$region_name}->{'begin'}, "\n";
   }
}

#****************************************************************************
# subroutine:  dump_load_view
# return:      all %LoadView ; key = RegionName , value = hash ref , begin , attr , length
#****************************************************************************
sub dump_load_view
{
   foreach my $region_name (sort { $LoadView{$a}->{'seq'} <=> $LoadView{$b}->{'seq'} } keys %LoadView)
   {
      print $region_name, "\t", $LoadView{$region_name}->{'begin'}, "\n";
   }
}

#****************************************************************************
# subroutine:  parse_region_string
# input:       reference to %LoadView or %ExecView ; Region Name start address string
# return:      %LoadView ; key = RegionName , value = hash ref , begin , attr , length
#****************************************************************************
my $sequence = 0;
sub parse_region_string
{
   my ($hash_ref, $string) = @_;
   my %tmp;

   if    ($string =~ m/(\S+)\s+(\S+)\s+OVERLAY\s+(\S+)/)
   {
      #print 'PATTERN1', "\t", $1, "\t", $2, "\t", 'OVERLAY', "\t", $3 , "\n";
      $tmp{'seq'}     = ++$sequence;
      $tmp{'attr'}    = "OVERLAY";
      $tmp{'begin'}   = $2;
      $tmp{'length'}  = $3;
      $hash_ref->{$1} = \%tmp;
   }
   elsif ($string =~ m/(\S+)\s+(\S+)\s+FIXED\s+(\S+)/)
   {
      #print 'PATTERN1', "\t", $1, "\t", $2, "\t", 'FIXED', "\t", $3, "\n";
      $tmp{'seq'}     = ++$sequence;
      $tmp{'attr'}    = "FIXED";
      $tmp{'begin'}   = $2;
      $tmp{'length'}  = $3;
      $hash_ref->{$1} = \%tmp;
   }
   elsif ($string =~ m/(\S+)\s+(\S+)\s+(\S+)/)
   {
      #print 'PATTERN3', "\t", $1, "\t", $2, "\t", $3, "\n";
      $tmp{'seq'}     = ++$sequence;
      $tmp{'begin'}   = $2;
      $tmp{'length'}  = $3;
      $hash_ref->{$1} = \%tmp;
   }
   elsif ($string =~ m/(\S+)\s+(\S+)/)
   {
      #print 'PATTERN4', "\t", $1, "\t", $2, "\n";
      $tmp{'seq'}     = ++$sequence;
      $tmp{'begin'}   = $2;
      $hash_ref->{$1} = \%tmp;
   }
   else
   {
      warn "UNKNOWN PATTERN : $string";
   }
}

#****************************************************************************
# subroutine:  parse_scatter_file_structure
# return:      %LoadView , %ExecView
#****************************************************************************
sub parse_scatter_file_structure
{
   my $last_line_no;
   my $text_line;
   my $view=0;  #counter , 1 = load view , 2 = exec view
   foreach my $file_line_no (sort {$a <=> $b} keys %Scat_Content)
   {
      $text_line = $Scat_Content{$file_line_no};
      if    ($text_line =~ m/{/)
      {
         die "un recognize view at $file_line_no" if ($view > 1);
         $view++;
         die "no region name detected before $file_line_no" if (not defined $last_line_no);
         &parse_region_string( ($view == 1) ? \%LoadView : \%ExecView , $Scat_Content{$last_line_no} );
      }
      elsif ($text_line =~ m/}/)
      { 
         $view--;
         die "un recognize view at $file_line_no" if ($view < 0);
      }
      $last_line_no = $file_line_no;
   }
}

#****************************************************************************
# subroutine:  dump_scatter_file_structure
# return:      none
#****************************************************************************
sub dump_scatter_file_structure
{
   foreach my $file_line_no (sort {$a <=> $b} keys %Scat_Content)
   {
      print $file_line_no, "\t", $Scat_Content{$file_line_no};
   }
}

#****************************************************************************
# subroutine:  dump_custom_emi_h_values
# return:      none
#****************************************************************************
sub dump_custom_emi_h_values
{
   foreach my $key (sort keys %EMI_H_Value)
   {
      print $key, "\t", $EMI_H_Value{$key} , "\n";
   }
}
