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
#*   sysGen1.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script embedded several .c .h source code templates and will 
#*       1. generate custom_util.c if not exists
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
my $SYSGEN2_VERNO     = " v0.05";
                       #  v0.05 , get_ROM_Length algorithm revise
                       #  v0.04 , apply formal dependency check since W07.36
                       #  v0.03 , force update custom_scatstruct.c since W07.20
                       #  v0.02 , two new functions for cache.c

#****************************************************************************
# File Names
#****************************************************************************
my $CUSTOM_SCATSTRUCT_C   = $ARGV[0] . '\\' . "custom_scatstruct.c";
my $SCATTERFILE           = $ARGV[1];

#****************************************************************************
# 1 >>>  Parse Scatter File
#****************************************************************************
my %Scat_Content;
# use hash in hash structure to store the parseing
my %LoadView;
my %ExecView;

open (SCAT_HANDLE, "<$SCATTERFILE") or die "cannot open $SCATTERFILE\n";
while (<SCAT_HANDLE>) {
   if (/\(.+\)/) {next;}
   if (/;/) {s/;.*//;}
   if (/{/ or /}/ or /\S+/) { $Scat_Content{$.} = $_; }
}
close (SCAT_HANDLE);

&parse_scatter_file_structure;
# DebugPrint
# &dump_exec_view;

#****************************************************************************
# 2 >>>  Generate custom_scatstruct.c
#****************************************************************************
&dependency_check($CUSTOM_SCATSTRUCT_C, "tools/sysGen2.pl", $SCATTERFILE);

if (-e $CUSTOM_SCATSTRUCT_C)
{
    print "$CUSTOM_SCATSTRUCT_C already exists\n";
}
else
{
    open (CUSTOM_SCATSTRUCT_C, ">$CUSTOM_SCATSTRUCT_C") or die "cannot open $CUSTOM_SCATSTRUCT_C\n";

    print CUSTOM_SCATSTRUCT_C &copyright_file_header();
    print CUSTOM_SCATSTRUCT_C &description_file_header(    "custom_scatstruct.c",
                          "This file provides the scatter file dependent APIs",
                                 "system auto generator". $SYSGEN2_VERNO);
    print CUSTOM_SCATSTRUCT_C &custom_scatstruct_c_file_body();
    close CUSTOM_SCATSTRUCT_C or die "fail to generate $CUSTOM_SCATSTRUCT_C";

    print "$CUSTOM_SCATSTRUCT_C is generated\n";
}

exit;

#****************************************************************************
# subroutine:  dependency check
# return:      None
#****************************************************************************
sub dependency_check
{
    my ($target, @depends) = (@_);
    
    return unless (-e $target);

    my @stat_target = stat $target;

    foreach my $dep (@depends)
    {
        next unless (-e $dep);
        my @stat_dep = stat $dep;

        next if ($stat_dep[9] < $stat_target[9]);

        ## Now check if the $target file check-in or auto-gen
        open SRC_FILE_R , "<$target" or die "cannot open $target\n";
        my $saved_sep = $/;
        undef $/;
        my $reading = <SRC_FILE_R>; 
        close SRC_FILE_R;
        $/ = $saved_sep;

        if ($reading !~ /\[MAUI_\d{8}\]/)
        {
            print "$target is older than $dep, force delete and update\n";
            unlink $target;
        }

        ## return in either way
        return;
    }
}
#****************************************************************************
# subroutine:  get_regions_reside_EXTSRAM
#****************************************************************************
sub get_regions_reside_EXTSRAM
{
    my @regions = (sort { $ExecView{$a}->{'seq'} <=> $ExecView{$b}->{'seq'} } keys %ExecView);
    my $EXTSRAM_Addr;

    for (my $i=0; $i <= $#regions; $i++)
    {
        if ($ExecView{$regions[$i]}->{'begin'} =~ /\+/ )
        {
            $ExecView{$regions[$i]}->{'addr'}  = $ExecView{$regions[$i-1]}->{'addr'} + 1;
        }
        else
        {
            $ExecView{$regions[$i]}->{'addr'}  = hex($ExecView{$regions[$i]}->{'begin'});
        }

        next if defined $EXTSRAM_Addr;

        if ($regions[$i] =~ /EXTSRAM/)
        {
            $EXTSRAM_Addr = $ExecView{$regions[$i]}->{'addr'};
        }
    }

    @regions = grep { ($ExecView{$_}->{'addr'} & 0xF8000000) == ($EXTSRAM_Addr & 0xF8000000) } keys %ExecView;
    return @regions;
}

#****************************************************************************
# subroutine:  get_regions_reside_ROM
#****************************************************************************
sub get_regions_reside_ROM
{
    my @regions = (sort { $ExecView{$a}->{'seq'} <=> $ExecView{$b}->{'seq'} } keys %ExecView);
    my $NORFlash_Addr;

    for (my $i=0; $i <= $#regions; $i++)
    {
        if ($ExecView{$regions[$i]}->{'begin'} =~ /\+/ )
        {
            $ExecView{$regions[$i]}->{'addr'}  = $ExecView{$regions[$i-1]}->{'addr'} + 1;
        }
        else
        {
            $ExecView{$regions[$i]}->{'addr'}  = hex($ExecView{$regions[$i]}->{'begin'});
        }

        next if defined $NORFlash_Addr;

        if ($regions[$i] =~ /ROM/)
        {
            $NORFlash_Addr = $ExecView{$regions[$i]}->{'addr'};
        }
    }

    @regions = grep { ($ExecView{$_}->{'addr'} & 0xF8000000) == ($NORFlash_Addr & 0xF8000000) } keys %ExecView;
    return @regions;
}

#****************************************************************************
# subroutine:  func_get_Max_AvailableRAMSegment
#****************************************************************************
sub func_get_Max_AvailableRAMSegment
{
    my (@regions) = @_;

    ###
    my @FixAddrRegions;
    my @LastRegions;

    for (my $i=1; $i <= $#regions; $i++)
    {
        next if ($ExecView{$regions[$i]}->{'begin'} =~ /\+/ );

        next if ($regions[$i-1] =~ /ROM/ or $regions[$i-1] =~ /DUMMY_END/);

        push @FixAddrRegions ,$regions[$i];
        push @LastRegions    ,$regions[$i-1];

        # DebugPrint
        #print $regions2[$i], " Inserted \n";
    }

    ###
    my $regions_define;
    map { $regions_define .= "extern kal_uint32 Image\$\$$_\$\$Base;\n" } @FixAddrRegions;
    $regions_define .= "\n";
    map { $regions_define .= "extern kal_uint32 Image\$\$$_\$\$ZI\$\$Limit;\n" } @LastRegions;

    ###
    my $segments_compare;
    for (my $num=0; $num <= $#FixAddrRegions; )
    {
        my $name1 = $FixAddrRegions[$num];
        my $name2 = $LastRegions[$num];

        $num++; # show number count from 1 instead of Zero

        my $sub_block = <<"__SUBBLOCK";
    /* Round $num */
    ThisRegionBegin = (kal_uint32)&Image\$\$$name1\$\$Base;
    LastRegionEnd   = (kal_uint32)&Image\$\$$name2\$\$ZI\$\$Limit;
    LastRegionEnd   = (LastRegionEnd + 16) & 0xFFFFFFF0;
    if ((ThisRegionBegin - LastRegionEnd) > MaxLength)
    {
       MaxBeginAddr = LastRegionEnd;
       MaxLength    = ThisRegionBegin - LastRegionEnd;
    }

__SUBBLOCK
        $segments_compare .= $sub_block;
    }

    return ($regions_define, $segments_compare);
}

#****************************************************************************
# subroutine:  func_get_ROM_Length
#****************************************************************************
sub func_get_ROM_Length
{
    my ($aref, $seq_begin, $seq_end) = @_;

    my @regions = grep {$ExecView{$_}->{'seq'} > $seq_begin and $ExecView{$_}->{'seq'} < $seq_end} @$aref;

    #map {print $_, "\t", $ExecView{$_}->{'begin'}, "\n";} @regions;

    my $definitions;
    map { $definitions .= "extern kal_uint32 Image\$\$$_\$\$Length;\n" } @regions;

    #
    my $funcbodies;
    my $baseaddr;
    my $thisregionaddr;
    map { 
            #print $_ , "\t" , $ExecView{$_}->{'begin'};
            #print      "\t" , $ExecView{$_}->{'attr'} if defined $ExecView{$_}->{'attr'};
            #print "\n";

            $thisregionaddr = $ExecView{$_}->{'begin'};

            if ($thisregionaddr =~ /^\+/)
            {
                $funcbodies  .= "    ROMLength += (kal_uint32)&Image\$\$$_\$\$Length;\n";
            }
            elsif (not defined $baseaddr)
            {
                $baseaddr = $thisregionaddr unless defined $baseaddr;
                $funcbodies  .= "    ROMLength += (kal_uint32)&Image\$\$$_\$\$Length;\n";
            }
            else
            {
                $funcbodies  .= "    ROMLength = $thisregionaddr - $baseaddr; /* $_ define fixed address */ \n";
            }

        } @regions;
    return ($definitions, $funcbodies);
}

#****************************************************************************
# subroutine:  custom_scatstruct_c_file_body
#****************************************************************************
sub custom_scatstruct_c_file_body
{
    my @regions1  = sort { $ExecView{$a}->{'addr'} <=> $ExecView{$b}->{'addr'} } &get_regions_reside_EXTSRAM();
    ###
    # discard overlay address
    my @regions2;
    for (my $i=1; $i <= $#regions1; $i++)
    {
        if ($ExecView{$regions1[$i-1]}->{'addr'} != $ExecView{$regions1[$i]}->{'addr'})
        {
           push @regions2, $regions1[$i-1];
           push @regions2, $regions1[$i] if ($i == $#regions1);
        }
    }
    ###
    # dump sorted View
    # DebugPrint
    # print "\n";
    # map {print $_, "\t", $ExecView{$_}->{'begin'}, "\n";} @regions2;

    my ($regions_define, $segments_compare) = &func_get_Max_AvailableRAMSegment(@regions2);
    
    chomp $regions_define;
    chomp $segments_compare;

    ###
    #

    my @loads    = sort { $LoadView{$a}->{'seq'} <=> $LoadView{$b}->{'seq'} } keys %LoadView;
    @loads       = grep { /ROM/; } @loads;
    my @regions3 = grep { /ROM/; } &get_regions_reside_ROM();
    @regions3    = sort { $ExecView{$a}->{'seq'} <=> $ExecView{$b}->{'seq'} } @regions3;

    #map {print $_, "\t", $ExecView{$_}->{'begin'}, "\n";} @regions3;

    my $def_1st;
    my $body_1st;
    my $def_2nd;
    my $body_2nd;

    if ($#loads == 0)
    {
            ($def_1st, $body_1st) = &func_get_ROM_Length(\@regions3,
                                                         $LoadView{ $loads[0] }->{'seq'},
                                                         65536);
    }
    elsif ($#loads == 1)
    {
            ($def_1st, $body_1st) = &func_get_ROM_Length(\@regions3,
                                                         $LoadView{ $loads[0] }->{'seq'},
                                                         $LoadView{ $loads[1] }->{'seq'}  );
            ($def_2nd, $body_2nd) = &func_get_ROM_Length(\@regions3,
                                                         $LoadView{ $loads[1] }->{'seq'},
                                                         65536);
    }
    else
    {
            ($def_1st, $body_1st) = &func_get_ROM_Length(\@regions3,
                                                         $LoadView{ $loads[0] }->{'seq'},
                                                         $LoadView{ $loads[1] }->{'seq'}  );
            ($def_2nd, $body_2nd) = &func_get_ROM_Length(\@regions3,
                                                         $LoadView{ $loads[1] }->{'seq'},
                                                         $LoadView{ $loads[2] }->{'seq'}  );
    }

    ###
    my $template = <<"__TEMPLATE";

#include "kal_release.h"

#ifdef __MTK_TARGET__

$regions_define
$def_1st
$def_2nd

/*************************************************************************
* FUNCTION
*  custom_get_MaxAvailableMemorySegment
*
* DESCRIPTION
*  Retrieve the pointer (16 Bytes aligned) and the length that unUsed memory segments
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

void custom_get_MaxAvailableMemorySegment(kal_uint32 **Return_begin_addr, kal_uint32 *Return_segment_size)
{
    kal_uint32  MaxLength;
    kal_uint32  MaxBeginAddr;
    kal_uint32  LastRegionEnd;
    kal_uint32  ThisRegionBegin;

    MaxLength = 0;

$segments_compare
    
    /* Now we get the maximum segments */
    *Return_begin_addr   = (kal_uint32 *)MaxBeginAddr;
    *Return_segment_size = MaxLength;
}

/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_Length
*
* DESCRIPTION
*  Retrieve the actual length of 1st ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_Length(void)
{
    kal_uint32 ROMLength = 0;

$body_1st
    return ROMLength; 
}

/*************************************************************************
* FUNCTION
*  custom_get_2nd_ROM_Length
*
* DESCRIPTION
*  Retrieve the actual length of 2nd ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_2nd_ROM_Length(void)
{
    kal_uint32 ROMLength = 0;

$body_2nd
    return ROMLength; 
}
#endif /* __MTK_TARGET__ */
__TEMPLATE
    return $template;
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
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author) = @_;
    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *   $author
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$
 * \$Modtime\$
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

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
