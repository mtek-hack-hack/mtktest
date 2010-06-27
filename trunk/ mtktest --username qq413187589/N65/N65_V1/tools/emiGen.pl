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
#*   emiGem.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. read a excel file to get appropriate emi setting based on the
#*          part number defined in custom_MemoryDevice.h
#*       2. based on the emi settings, generate custom_EMI.h if not exist
#*       3. based on the emi settings, generate custom_EMI.c if not exist
#*
#* Author:
#* -------
#*   Sherman Wang  (mtk00590)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision:     $
#* $Modtime:     $
#* $Log:     $
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
use Win32::OLE qw(in with);
use Win32::OLE::Const 'Microsoft Excel';
$Win32::OLE::Warn = 3;                                # die on errors...

#****************************************************************************
# Constants
#****************************************************************************
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

my $COLUMN_VENDOR            	= 1;
my $COLUMN_PART_NUMBER        	= 2;

# column index for Sheet 'NOR_RAM_MCP'
my $COLUMN_CS                 	= 3;
my $COLUMN_SIZE               	= 4;
my $COLUMN_PAGE_SIZE          	= 5;
my $COLUMN_SERIES            	= 6;
my $COLUMN_BANK                 = 7;
my $COLUMN_LAST_BANK_F_OR_C   	= 8;
my $COLUMN_LAST_BANK_C_ADDR   	= 9;
my $COLUMN_LAST_BANK_C_DATA   	= 10;
my $COLUMN_LAST_BANK_REGION   	= 11;
my $COLUMN_PBP_Y_OR_N         	= 12;
my $COLUMN_PBP_SIZE             = 13;
my $COLUMN_ASYNC_EMI          	= 14;
my $COLUMN_ASYNC_DRIVING      	= 20;
my $COLUMN_52MHZ_SYNC_EMI       = 25;
my $COLUMN_52MHZ_SYNC_DRIVING   = 28;
my $COLUMN_104MHZ_SYNC_EMI    	= 30;
my $COLUMN_26MHZ_SYNC_EMI	    = 33; # modified for clock switching
my $COLUMN_13MHZ_SYNC_EMI	    = 36; # modified for clock switching
my $COLUMN_104MHZ_SYNC_DRIVING	= 39; # modified for clock switching

# column index for Sheet 'LPSDRAM'
my $COLUMN_DENSITY                  = 3;
my $COLUMN_EMI_DRAM_RERESH_CONTROL  = 4;
my $COLUMN_MI_DRAM_MODE             = 5;
my $COLUMN_EMI_DRAM_EXT_MODE        = 6;
my $COLUMN_EMI_DRAM_CONTROL         = 7;
my $COLUMN_104MHZ_EMI_GENERAL_CONTROL1_VAL = 8; # modified for clock switching
my $COLUMN_104MHZ_EMI_GENERAL_CONTROL2_VAL = 9; # modified for clock switching
my $COLUMN_104MHZ_EMI_GENERAL_CONTROL3_VAL = 10; # modified for clock switching
my $COLUMN_26MHZ_EMI_GENERAL_CONTROL1_VAL  = 11; # modified for clock switching
my $COLUMN_26MHZ_EMI_GENERAL_CONTROL2_VAL  = 12; # modified for clock switching
my $COLUMN_26MHZ_EMI_GENERAL_CONTROL3_VAL  = 13; # modified for clock switching
my $COLUMN_13MHZ_EMI_GENERAL_CONTROL1_VAL  = 14; # modified for clock switching
my $COLUMN_13MHZ_EMI_GENERAL_CONTROL2_VAL  = 15; # modified for clock switching
my $COLUMN_13MHZ_EMI_GENERAL_CONTROL3_VAL  = 16; # modified for clock switching
#my $COLUMN_EMI_GENERAL_CONTROL1_VAL = 8; # modified for clock switching
#my $COLUMN_EMI_GENERAL_CONTROL2_VAL = 9; # modified for clock switching
#my $COLUMN_EMI_GENERAL_CONTROL3_VAL = 10; # modified for clock switching


my $PLATFORM                  = $ARGV[0];
my $MCU_CLOCK                 = $ARGV[1];
my $CUSTOM_MEMORY_DEVICE_HDR  = Win32::GetCwd()."\\".$ARGV[2];
my $MEMORY_DEVICE_LIST_XLS    = Win32::GetCwd()."\\".$ARGV[3];
print "$PLATFORM\n$MCU_CLOCK\n$CUSTOM_MEMORY_DEVICE_HDR\n$MEMORY_DEVICE_LIST_XLS\n" if ($DebugPrint == 1);

# following parameters come from $CUSTOM_MEMORY_DEVICE_HDR
my $MEMORY_DEVICE_TYPE;
my $FLASH_ACCESS_TYPE;
my $RAM_ACCESS_TYPE;
my $LPSDRAM_CHIP_SELECT = 0xFF;
# data structure of $part_number if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
#
# my $part_info =
# {
#    CS       => { "0" => { PART_NUMBER     => $part_number,
#                           EXCEL_ROW       => $excel_row,
#                           VENDOR 	        => $vendor,
my $part_info     	= ();   # has different data structures for different $MEMORY_DEVICE_TYPE
my $is_part_found 	= 1;    #  1: all part numbers are found
                            #  0: 1 part number is not found
                            # -1: 2 parts number are not found
# locations of output EMI settings
my $CUSTOM_EMI_H  = $CUSTOM_MEMORY_DEVICE_HDR;
my $CUSTOM_EMI_C  = $CUSTOM_MEMORY_DEVICE_HDR;
my $FLASH_OPT_H   = $CUSTOM_MEMORY_DEVICE_HDR;
my $SWITCH_CLK_C  = $CUSTOM_MEMORY_DEVICE_HDR;

$CUSTOM_EMI_H     =~ s/\\custom_MemoryDevice\.h$/\\custom_EMI\.h/i;
$CUSTOM_EMI_C     =~ s/\\custom_MemoryDevice\.h$/\\custom_EMI\.c/i;
$FLASH_OPT_H      =~ s/\\custom_MemoryDevice\.h$/\\flash_opt\.h/i;
$SWITCH_CLK_C     =~ s/\\custom_MemoryDevice\.h$/\\custom_switchclock\.c/i;

# check existance of custom_EMI.h and custom_EMI.c
my $is_existed_h            = (-e $CUSTOM_EMI_H)? 1 : 0;
my $is_existed_c            = (-e $CUSTOM_EMI_C)? 1 : 0;
my $is_existed_flash_opt    = (-e $FLASH_OPT_H)?  1 : 0;
my $is_existed_switch_clk_c = (-e $SWITCH_CLK_C)? 1 : 0;

if ( ($is_existed_h == 1) && ($is_existed_c == 1) && ($is_existed_flash_opt == 1) && ($is_existed_switch_clk_c == 1))
{
   print "\n\nALL custom_switchclock\.c, flash_opt\.h, custom_EMI\.h and custom_EMI\.c are existed!!!\n\n\n";
   exit;
}

#****************************************************************************
# parse custom_MemoryDevice.h to extract MEMORY_DEVICE_TYPE & PART_NUMBER
#****************************************************************************
open CUSTOM_MEMORY_DEVICE_HDR, "<$CUSTOM_MEMORY_DEVICE_HDR" or die "cannot open $CUSTOM_MEMORY_DEVICE_HDR\n";

while (<CUSTOM_MEMORY_DEVICE_HDR>)
{
   # matching the following lines
   # "#define MEMORY_DEVICE_TYPE    NOR_RAM_MCP"
   # "#define FLASH_ACCESS_TYPE     ASYNC_ACCESS"
   # "#define RAM_ACCESS_TYPE    	ASYNC_ACCESS"
   # "#define CS0_PART_NUMBER       RD38F3040L0ZBQ0"

   $MEMORY_DEVICE_TYPE  	        = $1 if (/^#define\s+MEMORY_DEVICE_TYPE\s+(\w+)/);
   $FLASH_ACCESS_TYPE               = $1 if (/^#define\s+FLASH_ACCESS_TYPE\s+(\w+)/);
   $RAM_ACCESS_TYPE                 = $1 if (/^#define\s+RAM_ACCESS_TYPE\s+(\w+)/);
   if (/^#define\s+CS(\d+)_PART_NUMBER\s+(\w+)/)
   {
      if ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
      {
         $LPSDRAM_CHIP_SELECT = $1;
         die "Only CS0 or CS1 is allowed for LPSDRAM!\n" if (($LPSDRAM_CHIP_SELECT != 0) && ($LPSDRAM_CHIP_SELECT != 1));
      }
      $part_info->{CS}->{$1}->{PART_NUMBER}  = $2 ;
      $is_part_found--;
   }

}

close CUSTOM_MEMORY_DEVICE_HDR;

#****************************************************************************
# read a excel file to get emi settings
#****************************************************************************
# get already active Excel application or open new
my $Excel = Win32::OLE->GetActiveObject('Excel.Application')
    || Win32::OLE->new('Excel.Application', 'Quit');

# copy the Excel file to a temp file and open it;
# this will prevent error due to simultaneous Excel access
my $Book    = $Excel->Workbooks->Open($MEMORY_DEVICE_LIST_XLS);

# select worksheet
my $Sheet;

my $eos_flag       = 7; # if this flag counts to '0', it means End Of Sheet


if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
{

    my $row        = 2;          # scan from row 3 when $MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP'
    my $col        = $COLUMN_CS; # scan column 3 for CS (Chip Select)

    my @all_rows   = ();

    $Sheet     = $Book->Worksheets($MEMORY_DEVICE_TYPE);

    # find cell address of the specified part number
    while (defined (my $scan_idx = $Sheet->Cells(++$row, $col)->{'Value'}) || ($eos_flag > 0))
    {
    unless (defined $scan_idx)
       {
          print "[$row][scan_idx]No Value\n" if $DebugPrint == 1;
       $eos_flag --;
       next;
       }

    $eos_flag   = 7;

       # remove leading and tailing spaces
    $scan_idx =~ s/^\s+// if $DebugPrint == 1;
    $scan_idx =~ s/\s+$// if $DebugPrint == 1;

    my $part_no = &xls_cell_value($Sheet, $row, $COLUMN_PART_NUMBER);
       if ($part_no =~ /$part_info->{CS}->{$scan_idx}->{PART_NUMBER}/)
      {
         if (defined($part_info->{CS}->{$scan_idx}->{EXCEL_ROW}))
         {
            die "redefine for the same part number in row $part_info->{CS}->{$scan_idx}->{EXCEL_ROW}!\n";
         }
         else
         {
            $part_info->{CS}->{$scan_idx}->{EXCEL_ROW} = $row;
            push @all_rows, $row;
            print "CS($scan_idx) with part_number($part_info->{CS}->{$scan_idx}->{PART_NUMBER}) found in row $row\n";
            $is_part_found++;
            last if ($is_part_found == 1); # check if all to-be-found parts are found
         }
       }
   } # while (defined (my $scan_idx = $Sheet->Cells(++$row, $col)->{'Value'}) || ($eos_flag > 0))

    # collect information for specified part number from Excel
    #
    # data structure of $part_info if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
    #
    # my $part_info =
    # {
    #    CS       => { "0" => { VENDOR              => $vendor,
    #                           SIZE                => $size,
    #                           PAGE_SIZE           => $page_size,
    #                           SERIES              => $series,
    #                           BANK                => $bank,
    #                           LAST_BANK           => {    F_OR_C      => $f_or_c,
    #                                                       C_ADDR      => $c_addr,
    #                                                       C_DATA      => $c_data,
    #                                                       REGION      => $region, },
    #                           PBP                 => {    Y_OR_N      => $y_or_n,
    #                                                       SIZE        => $size, },
    #                           ASYNC_EMI           => {    "MT6208"    => $setting,
    #                                                       "MT6205B"   => $setting,
    #                                                       "MT6217"    => $setting,
    #                                                       "MT6218B"   => $setting,
    #                                                       "MT6219"    => $setting,
    #                                                       "MT6227"    => $setting,
    #                                                       "MT6226"    => $setting,
    #                                                       "MT6226M"   => $setting,
    #                                                       "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6229"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       ADDRESS     => $address,
    #                                                       DATA        => $data, },
    #                           ASYNC_DRIVING       => {    "MT6208"    => $setting,
    #                                                       "MT6205B"   => $setting,
    #                                                       "MT6217"    => $setting,
    #                                                       "MT6218B"   => $setting,
    #                                                       "MT6219"    => $setting,
    #                                                       "MT6227"    => $setting,
    #                                                       "MT6226"    => $setting,
    #                                                       "MT6226M"   => $setting,
    #                                                       "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting, },
    #                           52MHZ_SYNC_EMI      => {    "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting,
    #                                                       ADDRESS     => $address,
    #                                                       DATA        => $data, },
    #                           52MHZ_SYNC_DRIVING  => {    "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting, },
    #                           104MHZ_SYNC_EMI     => {    "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting,
    #                                                       ADDRESS     => $address,
    #                                                       DATA        => $data, },
    #                           26MHZ_SYNC_EMI      => {    "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting,
    #                                                       ADDRESS     => $address,
    #                                                       DATA        => $data, },
    #                           13MHZ_SYNC_EMI      => {    "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting,
    #                                                       ADDRESS     => $address,
    #                                                       DATA        => $data, },
    #                           104MHZ_SYNC_DRIVING => {    "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting, }, }, },
    #                  "1" => ... },
    # };
    #

    foreach (@all_rows)
    {
        my $cs_value = $Sheet->Cells($_, $COLUMN_CS)->{'Value'};
        die "Row number NOT matched![$_][$part_info->{CS}->{$cs_value}->{EXCEL_ROW}]\n" unless ($part_info->{CS}->{$cs_value}->{EXCEL_ROW});

        $part_info->{CS}->{$cs_value}->{VENDOR}              = $Sheet->Cells($_, $COLUMN_VENDOR)->{'Value'};
        $part_info->{CS}->{$cs_value}->{SIZE}                = $Sheet->Cells($_, $COLUMN_SIZE)->{'Value'};
        $part_info->{CS}->{$cs_value}->{PAGE_SIZE}           = $Sheet->Cells($_, $COLUMN_PAGE_SIZE)->{'Value'};
        $part_info->{CS}->{$cs_value}->{SERIES}              = $Sheet->Cells($_, $COLUMN_SERIES)->{'Value'};
        $part_info->{CS}->{$cs_value}->{BANK}                = $Sheet->Cells($_, $COLUMN_BANK)->{'Value'};
        $part_info->{CS}->{$cs_value}->{LAST_BANK}->{F_OR_C} = $Sheet->Cells($_, $COLUMN_LAST_BANK_F_OR_C)->{'Value'};
        $part_info->{CS}->{$cs_value}->{LAST_BANK}->{C_ADDR} = $Sheet->Cells($_, $COLUMN_LAST_BANK_C_ADDR)->{'Value'};
        $part_info->{CS}->{$cs_value}->{LAST_BANK}->{C_DATA} = $Sheet->Cells($_, $COLUMN_LAST_BANK_C_DATA)->{'Value'};
        $part_info->{CS}->{$cs_value}->{LAST_BANK}->{REGION} = $Sheet->Cells($_, $COLUMN_LAST_BANK_REGION)->{'Value'};
        $part_info->{CS}->{$cs_value}->{PBP}->{Y_OR_N}       = $Sheet->Cells($_, $COLUMN_PBP_Y_OR_N)->{'Value'};
        $part_info->{CS}->{$cs_value}->{PBP}->{SIZE}         = $Sheet->Cells($_, $COLUMN_PBP_SIZE)->{'Value'};

        my $current_row         = $_;

        # collect Asynchrnous EMI Setting (Maximal MPLL)
        my $emi_setting_scan_idx     = $COLUMN_ASYNC_EMI;
        while ((&xls_cell_value($Sheet, 1, $emi_setting_scan_idx) =~ /Asynchrnous\s+EMI/i) &&
               ((my $platforms = &xls_cell_value($Sheet, 2, $emi_setting_scan_idx)) =~ /MT\d+/))
        {
            my $emi_setting     = &xls_cell_value($Sheet, $current_row, $emi_setting_scan_idx);

            while ($platforms =~ /(MT\w+)\W*/)
            {
                $part_info->{CS}->{$cs_value}->{ASYNC_EMI}->{$1}    = $emi_setting;
                $platforms = $';
            }
            $emi_setting_scan_idx++;
        }

        $part_info->{CS}->{$cs_value}->{ASYNC_EMI}->{ADDRESS}    = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx);
        $part_info->{CS}->{$cs_value}->{ASYNC_EMI}->{DATA}     = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx+1);

        # collect Asynchrnous Driving Setting
        my $driving_setting_scan_idx     = $COLUMN_ASYNC_DRIVING;
        while (&xls_cell_value($Sheet, 1, $driving_setting_scan_idx) =~ /Asynchrnous\s+Driving/i)
        {
            my $platforms        = &xls_cell_value($Sheet, 2, $driving_setting_scan_idx);
            my $driving_setting  = &xls_cell_value($Sheet, $current_row, $driving_setting_scan_idx);

            while ($platforms =~ /(MT\w+)\W*/)
        {
            $part_info->{CS}->{$cs_value}->{ASYNC_DRIVING}->{$1}    = $driving_setting;
            $platforms = $';
        }
        $driving_setting_scan_idx++;
    } # foreach (@all_rows)

    # collect 52MHz Synchronous EMI Setting
    my $emi_setting_scan_idx     = $COLUMN_52MHZ_SYNC_EMI;
    while ((&xls_cell_value($Sheet, 1, $emi_setting_scan_idx) =~ /52MHz\s+Synchronous\s+EMI/i) &&
           ((my $platforms = &xls_cell_value($Sheet, 2, $emi_setting_scan_idx)) =~ /MT\d+/))
    {
        my $emi_setting     = &xls_cell_value($Sheet, $current_row, $emi_setting_scan_idx);

        while ($platforms =~ /(MT\w+)\W*/)
        {
            $part_info->{CS}->{$cs_value}->{"52MHZ_SYNC_EMI"}->{$1}    = $emi_setting;
            $platforms = $';
        }
        $emi_setting_scan_idx++;
    }

    $part_info->{CS}->{$cs_value}->{"52MHZ_SYNC_EMI"}->{ADDRESS}    = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx);
    $part_info->{CS}->{$cs_value}->{"52MHZ_SYNC_EMI"}->{DATA}       = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx+1);

    # collect 52MHz Synchronous Driving Setting
    my $driving_setting_scan_idx     = $COLUMN_52MHZ_SYNC_DRIVING;
    while (&xls_cell_value($Sheet, 1, $driving_setting_scan_idx) =~ /52MHz\s+Synchronous\s+Driving/i)
    {
        my $platforms        = &xls_cell_value($Sheet, 2, $driving_setting_scan_idx);
        my $driving_setting  = &xls_cell_value($Sheet, $current_row, $driving_setting_scan_idx);

        while ($platforms =~ /(MT\w+)\W*/)
        {
            $part_info->{CS}->{$cs_value}->{"52MHZ_SYNC_DRIVING"}->{$1}    = $driving_setting;
            $platforms = $';
        }
        $driving_setting_scan_idx++;
    }

    # collect 104MHz Synchronous EMI Setting
    my $emi_setting_scan_idx     = $COLUMN_104MHZ_SYNC_EMI;
    while ((&xls_cell_value($Sheet, 1, $emi_setting_scan_idx) =~ /104MHz\s+Synchronous\s+EMI/i) &&
           ((my $platforms = &xls_cell_value($Sheet, 2, $emi_setting_scan_idx)) =~ /MT\d+/))
    {
        my $emi_setting     = &xls_cell_value($Sheet, $current_row, $emi_setting_scan_idx);

        while ($platforms =~ /(MT\w+)\W*/)
        {
            $part_info->{CS}->{$cs_value}->{"104MHZ_SYNC_EMI"}->{$1}    = $emi_setting;
            $platforms = $';
        }
        $emi_setting_scan_idx++;
    }

    $part_info->{CS}->{$cs_value}->{"104MHZ_SYNC_EMI"}->{ADDRESS}   = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx);
    $part_info->{CS}->{$cs_value}->{"104MHZ_SYNC_EMI"}->{DATA}      = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx+1);

    # collect 26MHz Synchronous EMI Setting
    my $emi_setting_scan_idx     = $COLUMN_26MHZ_SYNC_EMI;
    while ((&xls_cell_value($Sheet, 1, $emi_setting_scan_idx) =~ /26MHz\s+Synchronous\s+EMI/i) &&
           ((my $platforms = &xls_cell_value($Sheet, 2, $emi_setting_scan_idx)) =~ /MT\d+/))
    {
        my $emi_setting     = &xls_cell_value($Sheet, $current_row, $emi_setting_scan_idx);

        while ($platforms =~ /(MT\w+)\W*/)
        {
            $part_info->{CS}->{$cs_value}->{"26MHZ_SYNC_EMI"}->{$1}    = $emi_setting;
            $platforms = $';
        }
        $emi_setting_scan_idx++;
    }

    $part_info->{CS}->{$cs_value}->{"26MHZ_SYNC_EMI"}->{ADDRESS}   = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx);
    $part_info->{CS}->{$cs_value}->{"26MHZ_SYNC_EMI"}->{DATA}      = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx+1);

    # collect 13MHz Synchronous EMI Setting
    my $emi_setting_scan_idx     = $COLUMN_13MHZ_SYNC_EMI;
    while ((&xls_cell_value($Sheet, 1, $emi_setting_scan_idx) =~ /13MHz\s+Synchronous\s+EMI/i) &&
           ((my $platforms = &xls_cell_value($Sheet, 2, $emi_setting_scan_idx)) =~ /MT\d+/))
    {
        my $emi_setting     = &xls_cell_value($Sheet, $current_row, $emi_setting_scan_idx);

        while ($platforms =~ /(MT\w+)\W*/)
        {
            $part_info->{CS}->{$cs_value}->{"13MHZ_SYNC_EMI"}->{$1}    = $emi_setting;
            $platforms = $';
        }
        $emi_setting_scan_idx++;
    }

    $part_info->{CS}->{$cs_value}->{"13MHZ_SYNC_EMI"}->{ADDRESS}   = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx);
    $part_info->{CS}->{$cs_value}->{"13MHZ_SYNC_EMI"}->{DATA}      = &xls_cell_value($Sheet, $_, $emi_setting_scan_idx+1);

    # collect 104MHz Synchronous Driving Setting
    my $driving_setting_scan_idx     = $COLUMN_104MHZ_SYNC_DRIVING;
    while (&xls_cell_value($Sheet, 1, $driving_setting_scan_idx) =~ /104MHz\s+Synchronous\s+Driving/i)
    {
        my $platforms        = &xls_cell_value($Sheet, 2, $driving_setting_scan_idx);
        my $driving_setting  = &xls_cell_value($Sheet, $current_row, $driving_setting_scan_idx);

        while ($platforms =~ /(MT\w+)\W*/)
        {
            $part_info->{CS}->{$cs_value}->{"104MHZ_SYNC_DRIVING"}->{$1}    = $driving_setting;
            $platforms = $';
        }
        $driving_setting_scan_idx++;
    }

    } # foreach (@all_rows)

} # if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
{
    my $row        = 1;                   # scan from row 2 when $MEMORY_DEVICE_TYPE eq 'LPSDRAM'
    my $col        = $COLUMN_PART_NUMBER; # scan column 2 for Part Number

    $Sheet     = $Book->Worksheets($MEMORY_DEVICE_TYPE);

    # find cell address of the specified part number
    while (defined (my $scan_idx = $Sheet->Cells(++$row, $col)->{'Value'}) || ($eos_flag > 0))
    {
        unless (defined $scan_idx)
        {
            print "[$row][scan_idx]No Value\n" if $DebugPrint == 1;
            $eos_flag --;
            next;
        }

        $eos_flag   = 7;

       # remove leading and tailing spaces
        $scan_idx =~ s/^\s+// if $DebugPrint == 1;
        $scan_idx =~ s/\s+$// if $DebugPrint == 1;

        if ($scan_idx =~ /$part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{PART_NUMBER}/) # scan column 2 for Part Number
        {
            if (defined($part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EXCEL_ROW}))
            {
                die "redefine for the same part number in row $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EXCEL_ROW}!\n";
            }
            else
            {
                $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EXCEL_ROW} = $row;
                print "part_number($part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{PART_NUMBER}) found in row $row\n";
                $is_part_found = 1;
                last;
            }
        }
    } # while (defined (my $scan_idx = $Sheet->Cells(++$row, $col)->{'Value'}) || ($eos_flag > 0))

    # collect information for specified part number from Excel
    #
    # data structure of $part_info if ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
    #
    # my $part_info =
    # {
    #    CS       => { "0" => { VENDOR                          => $vendor,
    #                           DENSITY                         => $density,
    #                           EMI_DRAM_RERESH_CONTROL         => $setting,
    #                           EMI_DRAM_MODE                   => $setting,
    #                           EMI_DRAM_EXT_MODE               => $setting,
    #                           EMI_DRAM_CONTROL                => $setting,
    #                           EMI_104MHZ_GENERAL_CONTROL1_VAL => $setting,
    #                           EMI_104MHZ_GENERAL_CONTROL2_VAL => $setting,
    #                           EMI_104MHZ_GENERAL_CONTROL3_VAL => $setting,
    #                           EMI_26MHZ_GENERAL_CONTROL1_VAL  => $setting,
    #                           EMI_26MHZ_GENERAL_CONTROL2_VAL  => $setting,
    #                           EMI_26MHZ_GENERAL_CONTROL3_VAL  => $setting,
    #                           EMI_13MHZ_GENERAL_CONTROL1_VAL  => $setting,
    #                           EMI_13MHZ_GENERAL_CONTROL2_VAL  => $setting,
    #                           EMI_13MHZ_GENERAL_CONTROL3_VAL  => $setting, }, },
    # };
    #

    my $cs_value = $LPSDRAM_CHIP_SELECT;
    $_ = $row;

    $part_info->{CS}->{$cs_value}->{VENDOR}                             = $Sheet->Cells($_, $COLUMN_VENDOR)->{'Value'};
    $part_info->{CS}->{$cs_value}->{DENSITY}                            = $Sheet->Cells($_, $COLUMN_DENSITY)->{'Value'};
    $part_info->{CS}->{$cs_value}->{EMI_DRAM_RERESH_CONTROL}            = $Sheet->Cells($_, $COLUMN_EMI_DRAM_RERESH_CONTROL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{EMI_DRAM_MODE}                      = $Sheet->Cells($_, $COLUMN_MI_DRAM_MODE)->{'Value'};
    $part_info->{CS}->{$cs_value}->{EMI_DRAM_EXT_MODE}                  = $Sheet->Cells($_, $COLUMN_EMI_DRAM_EXT_MODE)->{'Value'};
    $part_info->{CS}->{$cs_value}->{EMI_DRAM_CONTROL}                   = $Sheet->Cells($_, $COLUMN_EMI_DRAM_CONTROL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"104MHZ_EMI_GENERAL_CONTROL1_VAL"}  = $Sheet->Cells($_, $COLUMN_104MHZ_EMI_GENERAL_CONTROL1_VAL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"104MHZ_EMI_GENERAL_CONTROL2_VAL"}  = $Sheet->Cells($_, $COLUMN_104MHZ_EMI_GENERAL_CONTROL2_VAL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"104MHZ_EMI_GENERAL_CONTROL3_VAL"}  = $Sheet->Cells($_, $COLUMN_104MHZ_EMI_GENERAL_CONTROL3_VAL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"26MHZ_EMI_GENERAL_CONTROL1_VAL"}   = $Sheet->Cells($_, $COLUMN_26MHZ_EMI_GENERAL_CONTROL1_VAL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"26MHZ_EMI_GENERAL_CONTROL2_VAL"}   = $Sheet->Cells($_, $COLUMN_26MHZ_EMI_GENERAL_CONTROL2_VAL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"26MHZ_EMI_GENERAL_CONTROL3_VAL"}   = $Sheet->Cells($_, $COLUMN_26MHZ_EMI_GENERAL_CONTROL3_VAL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"13MHZ_EMI_GENERAL_CONTROL1_VAL"}   = $Sheet->Cells($_, $COLUMN_13MHZ_EMI_GENERAL_CONTROL1_VAL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"13MHZ_EMI_GENERAL_CONTROL2_VAL"}   = $Sheet->Cells($_, $COLUMN_13MHZ_EMI_GENERAL_CONTROL2_VAL)->{'Value'};
    $part_info->{CS}->{$cs_value}->{"13MHZ_EMI_GENERAL_CONTROL3_VAL"}   = $Sheet->Cells($_, $COLUMN_13MHZ_EMI_GENERAL_CONTROL3_VAL)->{'Value'};

}# elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
else
{
    undef $MEMORY_DEVICE_TYPE;
}

# close the temp Excel file
$Book->Close(1);

die "Incorrect memory device type"  unless $MEMORY_DEVICE_TYPE;
die "part number not supported"     if ($is_part_found <= 0);

#****************************************************************************
# check consistency among PLATFORM, MCU_CLOCK and MemoryDeviceList data
#****************************************************************************
my $fast_mem_prj_type = 0; # 104: MT6228/MT6229 SYNC_ACCESS MCU_104M
                           # 52: MT6228/MT6229 SYNC_ACCESS MCU_52M
                           # 0: other settings

if ( ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && ($RAM_ACCESS_TYPE eq 'SYNC_ACCESS')
  && (($PLATFORM eq 'MT6228') || ($PLATFORM eq 'MT6229') || ($PLATFORM eq 'MT6225') || ($PLATFORM eq 'MT6230') || ($PLATFORM eq 'MT6268T')) )
{
    if ($MCU_CLOCK eq 'MCU_104M')
    {
        die "Device not support 104MHz Burst Access!\n" if ($part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{ADDRESS} eq 'x');
        die "Device not support 104MHz Burst Access!\n" if ($part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{ADDRESS} eq 'x');
        if (($part_info->{CS}->{0}->{SERIES} ne 'INTEL_SIBLEY') && ($part_info->{CS}->{0}->{SERIES} ne 'TOSHIBA_TY'))
        {
            die "Not support 104MHz Burst Access except Intel Sibley and Toshiba TY!\n";
        }
        $fast_mem_prj_type = 104;
    }
    elsif ($MCU_CLOCK eq 'MCU_52M')
    {
        die "Device not support 52MHz Burst Access!\n" if ($part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{ADDRESS} eq 'x');
        die "Device not support 52MHz Burst Access!\n" if ($part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{ADDRESS} eq 'x');
        $fast_mem_prj_type = 52;
    }
}

if ( ($MEMORY_DEVICE_TYPE eq 'LPSDRAM') && ($LPSDRAM_CHIP_SELECT !~ /0xFF/i)
     && (($PLATFORM ne 'MT6228') && ($PLATFORM ne 'MT6229') && ($PLATFORM ne 'MT6230')) )
{
    die "$PLATFORM not support LPSDRAM!\n";
}

#****************************************************************************
# generate custom_switchclock.c
#****************************************************************************
if ($is_existed_switch_clk_c == 0)
{
    open (SWITCH_CLK_C, ">$SWITCH_CLK_C") or die "cannot open $SWITCH_CLK_C\n";

    print SWITCH_CLK_C &switch_clk_c_file_header();
    print SWITCH_CLK_C &before_custom_dynamicclockswitch();

    if ( ($MEMORY_DEVICE_TYPE eq 'LPSDRAM') && ($LPSDRAM_CHIP_SELECT !~ /0xFF/i)
        && (($PLATFORM eq 'MT6228') || ($PLATFORM eq 'MT6229') || ($PLATFORM eq 'MT6230') || ($PLATFORM eq 'MT6225')) )
    {
        print SWITCH_CLK_C &custom_dynamicclockswitch_for_lpsdram_104mhz();

        my $ctrl_val = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL2_VAL"};
        print SWITCH_CLK_C "      *EMI_GENB = $ctrl_val;\n";

        print SWITCH_CLK_C "#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )\n";

        $ctrl_val    = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL3_VAL"};
        print SWITCH_CLK_C "      *EMI_GENC = $ctrl_val;\n";

        print SWITCH_CLK_C "#endif\n";
        print SWITCH_CLK_C "\n      /* turn on clock, set clock driving and delay */\n";

        $ctrl_val    = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL1_VAL"};
        print SWITCH_CLK_C "      *EMI_GENA = $ctrl_val;\n";


        print SWITCH_CLK_C &custom_dynamicclockswitch_for_lpsdram_26mhz();

        $ctrl_val    = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL2_VAL"};
        print SWITCH_CLK_C "      *EMI_GENB = $ctrl_val;\n";

        $ctrl_val    = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL3_VAL"};
        print SWITCH_CLK_C "      *EMI_GENC = $ctrl_val;\n";

        print SWITCH_CLK_C "\n      /* turn on clock, set clock driving and delay */\n";

        $ctrl_val    = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL1_VAL"};
        print SWITCH_CLK_C "      *EMI_GENA = $ctrl_val;\n";

        print SWITCH_CLK_C &custom_dynamicclockswitch_for_lpsdram_13mhz();

        $ctrl_val    = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"13MHZ_EMI_GENERAL_CONTROL2_VAL"};
        print SWITCH_CLK_C "      *EMI_GENB = $ctrl_val;\n";

        print SWITCH_CLK_C "\n      /* turn on clock, set clock driving and delay */\n";

        $ctrl_val    = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"13MHZ_EMI_GENERAL_CONTROL1_VAL"};
        print SWITCH_CLK_C "      *EMI_GENA = $ctrl_val;\n";

        print SWITCH_CLK_C &custom_dynamicclockswitch_for_lpsdram_ending();
    } # if ( ($MEMORY_DEVICE_TYPE eq 'LPSDRAM') && ($LPSDRAM_CHIP_SELECT !~ /0xFF/i)
    elsif ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
           && ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && ($RAM_ACCESS_TYPE eq 'SYNC_ACCESS') )
    {
        if ($part_info->{CS}->{0}->{SERIES} eq 'INTEL_SIBLEY')
        {
            print SWITCH_CLK_C &custom_dynamicclockswitch_for_intel_sibley_104mhz();

            my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

            print SWITCH_CLK_C "\n      /* set EMI B */\n";

            $emi_setting_6229    = $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

            my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
            my @flash_data = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{DATA};

            print SWITCH_CLK_C "\n      /*\n       * Configure flash in burst mode.\n       */\n";

            for (0..$#flash_addr)
            {
                print SWITCH_CLK_C "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
                print SWITCH_CLK_C "      *ptr16 = $flash_data[$_];\n";
            }

            my @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
            my @ram_data   = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{DATA};

            print SWITCH_CLK_C "\n      /*\n       * Configure PSRAM in burst mode.\n       */\n";

            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[0]);\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[1]);\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[2]) = $ram_data[2];\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[3]) = $ram_data[3];\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[4]);\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[5]);\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[6]) = $ram_data[6];\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[7]) = $ram_data[7];\n";

            print SWITCH_CLK_C "\n      /* set EMI A */\n";

            $emi_setting_6229 = $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

            print SWITCH_CLK_C "\n      /* delay for a while */\n      for (delay = 0; delay < 2; delay++) {\n\n         /* NOP */\n      }\n      /* set EMI B */\n";

            $emi_setting_6229 = $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";


            print SWITCH_CLK_C &custom_dynamicclockswitch_for_intel_sibley_26mhz();

            my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

            print SWITCH_CLK_C "\n      /* set EMI B */\n";

            $emi_setting_6229    = $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

            my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{ADDRESS};
            my @flash_data = split /\s/, $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{DATA};

            print SWITCH_CLK_C "\n      /*\n       * Configure flash in burst mode.\n       */\n";

            for (0..$#flash_addr)
            {
                $flash_addr[$_] = '???value_NOT_defined_in_MemoryDeviceList_xls' if ($flash_addr[$_] eq 'x'); # if 'x' is defined in Excel, a compile error occurred
                print SWITCH_CLK_C "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
                print SWITCH_CLK_C "      *ptr16 = $flash_data[$_];\n";
            }

            my @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"26MHZ_SYNC_EMI"}->{ADDRESS};
            my @ram_data   = split /\s/, $part_info->{CS}->{1}->{"26MHZ_SYNC_EMI"}->{DATA};

            print SWITCH_CLK_C "\n      /*\n       * Configure PSRAM in burst mode.\n       */\n";

            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[0]);\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[1]);\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[2]) = $ram_data[2];\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[3]) = $ram_data[3];\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[4]);\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[5]);\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[6]) = $ram_data[6];\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[7]) = $ram_data[7];\n";

            print SWITCH_CLK_C "\n      /* set EMI A */\n";

            $emi_setting_6229 = $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

            print SWITCH_CLK_C "\n      /* delay for a while */\n      for (delay = 0; delay < 2; delay++) {\n\n         /* NOP */\n      }\n      /* set EMI B */\n";

            $emi_setting_6229 = $part_info->{CS}->{1}->{"26MHZ_SYNC_EMI"}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";


            print SWITCH_CLK_C &custom_dynamicclockswitch_for_intel_sibley_13mhz();

            my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

            print SWITCH_CLK_C "\n      /* set EMI B */\n";

            $emi_setting_6229    = $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

            my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{ADDRESS};
            my @flash_data = split /\s/, $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{DATA};

            print SWITCH_CLK_C "\n      /*\n       * Configure flash in burst mode.\n       */\n";

            for (0..$#flash_addr)
            {
                $flash_addr[$_] = '???value_NOT_defined_in_MemoryDeviceList_xls' if ($flash_addr[$_] eq 'x'); # if 'x' is defined in Excel, a compile error occurred
                print SWITCH_CLK_C "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
                print SWITCH_CLK_C "      *ptr16 = $flash_data[$_];\n";
            }

            my @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"13MHZ_SYNC_EMI"}->{ADDRESS};
            my @ram_data   = split /\s/, $part_info->{CS}->{1}->{"13MHZ_SYNC_EMI"}->{DATA};

            print SWITCH_CLK_C "\n      /*\n       * Configure PSRAM in burst mode.\n       */\n";

            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[0]);\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[1]);\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[2]) = $ram_data[2];\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[3]) = $ram_data[3];\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[4]);\n";
            print SWITCH_CLK_C "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[5]);\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[6]) = $ram_data[6];\n";
            print SWITCH_CLK_C "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[7]) = $ram_data[7];\n";

            print SWITCH_CLK_C "\n      /* set EMI A */\n";

            $emi_setting_6229 = $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

            print SWITCH_CLK_C "\n      /* delay for a while */\n      for (delay = 0; delay < 2; delay++) {\n\n         /* NOP */\n      }\n      /* set EMI B */\n";

            $emi_setting_6229 = $part_info->{CS}->{1}->{"13MHZ_SYNC_EMI"}->{MT6229};
            print SWITCH_CLK_C "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";


            print SWITCH_CLK_C &custom_dynamicclockswitch_for_intel_sibley_ending();
        } # if ($part_info->{CS}->{0}->{SERIES} eq 'INTEL_SIBLEY')
        else
        {
            print SWITCH_CLK_C &custom_dynamicclockswitch_for_else();
        }
    } # elsif ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') && ... )
    else
    {
        print SWITCH_CLK_C &custom_dynamicclockswitch_for_else();
    }

    print SWITCH_CLK_C &switch_clk_c_file_ending();

    close SWITCH_CLK_C;

    print "\n$SWITCH_CLK_C is generated\n";
} # if ($is_existed_switch_clk_c == 0)

#****************************************************************************
# generate inc\flash_opt.h
#****************************************************************************
if ($is_existed_flash_opt == 0)
{
    open (FLASH_OPT_H, ">$FLASH_OPT_H") or die "cannot open $FLASH_OPT_H\n";
    print FLASH_OPT_H &flash_opt_header();

    if ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') )
    {
        if ($part_info->{CS}->{0}->{PBP}->{Y_OR_N} =~ /Y/i)
        {
            print FLASH_OPT_H "#define __PAGE_BUFFER_PROGRAM__\n" ;
        }

        if ($part_info->{CS}->{0}->{SERIES} =~ /(\w*)/i)
        {
            my $nor_flash_type = "NOR_FLASH_TYPE_" . $1;
            print FLASH_OPT_H "#define $nor_flash_type\n" ;
        }
    }

    print FLASH_OPT_H &flash_opt_ending();

    close FLASH_OPT_H;

    print "\n$FLASH_OPT_H is generated\n";
}

#****************************************************************************
# generate custom_EMI.c
#****************************************************************************
if ($is_existed_c == 0)
{
    open (CUSTOM_EMI_C, ">$CUSTOM_EMI_C") or die "cannot open $CUSTOM_EMI_C\n";

    print CUSTOM_EMI_C &c_file_header();
    print CUSTOM_EMI_C &before_custom_setemi();


    if ( ($MEMORY_DEVICE_TYPE eq 'LPSDRAM') && ($LPSDRAM_CHIP_SELECT !~ /0xFF/i)
        && (($PLATFORM eq 'MT6228') || ($PLATFORM eq 'MT6229') || ($PLATFORM eq 'MT6230') || ($PLATFORM eq 'MT6225')) )
    {
        print CUSTOM_EMI_C &custom_setemi_for_lpsdram();
    }


    if ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') )
    {
        print CUSTOM_EMI_C &custom_setemi_for_nor_ram_mcp();
    }


    print CUSTOM_EMI_C &before_custom_setadvemi();


    if ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') )
    {
        if ($part_info->{CS}->{0}->{LAST_BANK}->{F_OR_C} =~ /C/i)
        {
            print CUSTOM_EMI_C &custom_setadvemi_for_last_bank_is_c_part1();

            my @c_addr = split /\s/, $part_info->{CS}->{0}->{LAST_BANK}->{C_ADDR};
            my @c_data = split /\s/, $part_info->{CS}->{0}->{LAST_BANK}->{C_DATA};

            for (0..$#c_addr)
            {
                my $idx = $_ + 1;
                print CUSTOM_EMI_C "      *(volatile kal_uint16 *)(NORBaseAddr+(kal_uint32)(DEV_CONFIG_BANK_ADDR_$idx)) = DEV_CONFIG_BANK_DATA_$idx;\n";
            }

            print CUSTOM_EMI_C &custom_setadvemi_for_last_bank_is_c_part2();
        }

        if ( ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && ($RAM_ACCESS_TYPE eq 'SYNC_ACCESS')
        && (($PLATFORM eq 'MT6228') || ($PLATFORM eq 'MT6229') || ($PLATFORM eq 'MT6225') || ($PLATFORM eq 'MT6230') || ($PLATFORM eq 'MT6268T')) )
        {
            my @flash_addr;
            my @flash_data;
            my @ram_addr;
            my @ram_data;

            if ($fast_mem_prj_type == 104) # $MCU_CLOCK eq 'MCU_104M'
            {
                @flash_addr = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
                @flash_data = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{DATA};
                @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
                @ram_data   = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{DATA};

                if ($part_info->{CS}->{0}->{SERIES} eq 'INTEL_SIBLEY')
                {
                    print CUSTOM_EMI_C &custom_setadvemi_for_2829_sync_access_104_sibley_part();
                }
                elsif ($part_info->{CS}->{0}->{SERIES} eq 'TOSHIBA_TY')
                {
                   print CUSTOM_EMI_C &custom_setadvemi_for_2829_sync_access_104_ty_part();
                }
            }
            elsif ($fast_mem_prj_type == 52) # $MCU_CLOCK eq 'MCU_52M'
            {
                @flash_addr = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{ADDRESS};
                @flash_data = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{DATA};
                @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{ADDRESS};
                @ram_data   = split /\s/, $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{DATA};

                print CUSTOM_EMI_C &custom_setadvemi_for_2829_sync_access_part1();

                for (0..$#flash_addr)
                {
                    my $idx = $_ + 1;
                    print CUSTOM_EMI_C "      *(volatile kal_uint16 *)(NORBaseAddr+(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_$idx)) = DEV_CONFIG_FLASH_BMODE_DATA_$idx;\n";
                }

                print CUSTOM_EMI_C &custom_setadvemi_for_2829_sync_access_part2();

                for (0..$#ram_addr)
                {
                    my $idx = $_ + 1;
                    print CUSTOM_EMI_C "      *(volatile kal_uint16 *)(RAMBaseAddr+(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_$idx)) = DEV_CONFIG_RAM_BMODE_DATA_$idx;\n";
                }

                print CUSTOM_EMI_C &custom_setadvemi_for_2829_sync_access_part3();
            } # elsif ($fast_mem_prj_type == 52) # $MCU_CLOCK eq 'MCU_52M'
        } # if ( ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && ($RAM_ACCESS_TYPE eq 'SYNC_ACCESS') ...

        my $addr = lc($part_info->{CS}->{0}->{ASYNC_EMI}->{ADDRESS});
        $addr =~ s/\s//g;
        if ( ($FLASH_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )
        {
            print CUSTOM_EMI_C &custom_setadvemi_for_flash_async_access_part1();

            my @addr = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{ADDRESS};
            my @data = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{DATA};

            for (0..$#addr)
            {
                my $idx = $_ + 1;
                print CUSTOM_EMI_C "      *(volatile kal_uint16 *)(NORBaseAddr+(kal_uint32)(DEV_CONFIG_FLASH_PMODE_ADDR_$idx)) = DEV_CONFIG_FLASH_PMODE_DATA_$idx;\n";
            }

            print CUSTOM_EMI_C &custom_setadvemi_for_flash_async_access_part2();
        }

        $addr = lc($part_info->{CS}->{1}->{ASYNC_EMI}->{ADDRESS});
        $addr =~ s/\s//g;
        if ( ($RAM_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )
        {
            print CUSTOM_EMI_C &custom_setadvemi_for_ram_async_access_part1();

            my @addr = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{ADDRESS};
            my @data = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{DATA};

            for (0..$#addr)
            {
                my $idx = $_ + 1;
                print CUSTOM_EMI_C "      *(volatile kal_uint16 *)(RAMBaseAddr+(kal_uint32)(DEV_CONFIG_RAM_PMODE_ADDR_$idx)) = DEV_CONFIG_RAM_PMODE_DATA_$idx;\n";
            }

            print CUSTOM_EMI_C &custom_setadvemi_for_ram_async_access_part2();
        }
    } # if ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') )

    print CUSTOM_EMI_C &c_file_ending();

    close CUSTOM_EMI_C;

    print "\n$CUSTOM_EMI_C is generated\n";
} # if ($is_existed_c == 0)

#****************************************************************************
# generate custom_EMI.h
#****************************************************************************
exit if ($is_existed_h == 1);

open (CUSTOM_EMI_H, ">$CUSTOM_EMI_H") or die "cannot open $CUSTOM_EMI_H\n";

print CUSTOM_EMI_H &header_file_header();

if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
{
    print CUSTOM_EMI_H &emi_csconfiguration();
    for (0..3)
    {
        if (!defined $part_info->{CS}->{$_}->{SERIES})
        {
            print CUSTOM_EMI_H (($_==2) ? "   UNUSED,\n" : "   UNUSED\n");
        }
        elsif ($part_info->{CS}->{$_}->{SERIES} ne '*')
        {
            print CUSTOM_EMI_H "   NOR_FLASH,\n";
        }
        elsif ($part_info->{CS}->{$_}->{SERIES} eq '*')
        {
            print CUSTOM_EMI_H "   RAM,\n";
        }
    }


    print CUSTOM_EMI_H &ram_size_in_bytes();
    my $size = $part_info->{CS}->{1}->{SIZE};
    print CUSTOM_EMI_H "const kal_uint32  EMI_EXTSRAM_SIZE = (($size)<<20)>> 3;\n";


    print CUSTOM_EMI_H &driving_and_cache_prefetch_setting_6205b_6208();
    my $driving_setting_6205b = $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6205B};
    print CUSTOM_EMI_H "#define EMI_GENERAL_CONTROL        $driving_setting_6205b\n";


    print CUSTOM_EMI_H &driving_and_cache_prefetch_setting_6228();
    my @driving_setting_6228 = split /\s/, $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6228};
    for(0..$#driving_setting_6228)
    {
       print CUSTOM_EMI_H "#define EMI_GENERAL_CONTROL_$_        $driving_setting_6228[$_]\n";
    }

    print CUSTOM_EMI_H &driving_and_cache_prefetch_setting_6229();
    my @driving_setting_6229 = split /\s/, $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6229};
    for(0..$#driving_setting_6229)
    {
       print CUSTOM_EMI_H "#define EMI_GENERAL_CONTROL_$_        $driving_setting_6229[$_]\n";
    }


    print CUSTOM_EMI_H &driving_and_cache_prefetch_setting_6218b_6217_6219();
    my $driving_setting_6217 = $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6217};
    print CUSTOM_EMI_H "#define EMI_GENERAL_CONTROL        $driving_setting_6217\n";
    my $default_value = 0x03030103;
    if ($part_info->{CS}->{0}->{PAGE_SIZE} == 16)
    {
        $default_value = $default_value | 0x4;
    }
    elsif ($part_info->{CS}->{1}->{PAGE_SIZE} == 16)
    {
        $default_value = $default_value | 0x40000;
    }
    printf CUSTOM_EMI_H "#define EMI_CACHE_PREFETCH        0x%08X\n", $default_value;


    print CUSTOM_EMI_H &driving_and_cache_prefetch_setting_else();
    my $driving_setting_6227 = $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6227};
    print CUSTOM_EMI_H "#define EMI_GENERAL_CONTROL        $driving_setting_6227\n";
    printf CUSTOM_EMI_H "#define EMI_CACHE_PREFETCH        0x%08X\n", $default_value;


    print CUSTOM_EMI_H &emi_setting_6205b_6208();
    for (0..3)
    {
        my $emi_setting_6205b = '0';
        if (exists $part_info->{CS}->{$_}->{ASYNC_EMI}->{MT6205B})
        {
            $emi_setting_6205b = $part_info->{CS}->{$_}->{ASYNC_EMI}->{MT6205B};
        }
        print CUSTOM_EMI_H (($_<=2) ? "   $emi_setting_6205b,\n" : "   $emi_setting_6205b\n");
    }


    print CUSTOM_EMI_H &emi_setting_6218b_6217_6219();
    for (0..3)
    {
        my $emi_setting_6217 = '0';
        if (exists $part_info->{CS}->{$_}->{ASYNC_EMI}->{MT6217})
        {
            $emi_setting_6217 = $part_info->{CS}->{$_}->{ASYNC_EMI}->{MT6217};
            $emi_setting_6217 =~ s/(0x\w+)\W.*/$1/;
        }
        print CUSTOM_EMI_H (($_<=2) ? "   $emi_setting_6217,\n" : "   $emi_setting_6217\n");
    }


    print CUSTOM_EMI_H &emi_setting_6227_6226_6226m();
    for (0..3)
    {
        my $emi_setting_6227 = '0';
        if (exists $part_info->{CS}->{$_}->{ASYNC_EMI}->{MT6227})
        {
            $emi_setting_6227 = $part_info->{CS}->{$_}->{ASYNC_EMI}->{MT6227};
            $emi_setting_6227 =~ s/(0x\w+)\W.*/$1/;
        }
        print CUSTOM_EMI_H (($_<=2) ? "   $emi_setting_6227,\n" : "   $emi_setting_6227\n");
    }


    print CUSTOM_EMI_H &emi_setting_6228_6229();
    for (0..3)
    {
        my $emi_setting_6229 = '0';
        if (exists $part_info->{CS}->{$_}->{ASYNC_EMI}->{MT6229})
        {
            $emi_setting_6229 = $part_info->{CS}->{$_}->{ASYNC_EMI}->{MT6229};
            $emi_setting_6229 =~ s/(0x\w+)\W.*/$1/;
        }
        print CUSTOM_EMI_H (($_<=2) ? "   $emi_setting_6229,\n" : "   $emi_setting_6229\n");
    }


    print CUSTOM_EMI_H &additional_information();
    if ($part_info->{CS}->{0}->{LAST_BANK}->{F_OR_C} =~ /C/i)
    {
        my @c_addr = split /\s/, $part_info->{CS}->{0}->{LAST_BANK}->{C_ADDR};
        my @c_data = split /\s/, $part_info->{CS}->{0}->{LAST_BANK}->{C_DATA};

        for (0..$#c_addr)
        {
            my $idx = $_ + 1;
            print CUSTOM_EMI_H "#define DEV_CONFIG_BANK_ADDR_$idx        $c_addr[$_]\n";
            print CUSTOM_EMI_H "#define DEV_CONFIG_BANK_DATA_$idx        $c_data[$_]\n";
        }
    }

    if ($fast_mem_prj_type == 104)
    {
        my @addr = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            print CUSTOM_EMI_H "#define DEV_CONFIG_FLASH_BMODE_ADDR_$idx        $addr[$_]\n";
            print CUSTOM_EMI_H "#define DEV_CONFIG_FLASH_BMODE_DATA_$idx        $data[$_]\n";
        }

        my @addr = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            print CUSTOM_EMI_H "#define DEV_CONFIG_RAM_BMODE_ADDR_$idx        $addr[$_]\n";
            print CUSTOM_EMI_H "#define DEV_CONFIG_RAM_BMODE_DATA_$idx        $data[$_]\n";
        }

        my $emi_setting = $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{MT6229};
        print CUSTOM_EMI_H "#define EMI_FLASH_BURST_MODE        $emi_setting\n";
        $emi_setting = $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{MT6229};
        print CUSTOM_EMI_H "#define EMI_RAM_BURST_MODE        $emi_setting\n";

        # use #if ... #elif for 6228,6225/6229,6230 6268T differentiation
        print CUSTOM_EMI_H "#if ( defined(MT6228) || defined(MT6225) )\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_DRIVING"}->{MT6228};
        if ($driving_setting[0] ne 'x')
        {
            print CUSTOM_EMI_H "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
#           die "no 2nd driving setting for CS=0, 104Mhz, MT6228" if (!defined $driving_setting[1]); MT6228 need only 1st and 3rd driving settings
#           print CUSTOM_EMI_H "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 104Mhz, MT6228" if (!defined $driving_setting[1]);
            print CUSTOM_EMI_H "#define EMI_DRV2_BURST_MODE        $driving_setting[1]\n";
        }
        print CUSTOM_EMI_H "#elif ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_DRIVING"}->{MT6229};
        if ($driving_setting[0] ne 'x')
        {
            print CUSTOM_EMI_H "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
            die "no 2nd driving setting for CS=0, 104Mhz, MT6229, MT6230, MT6268T" if (!defined $driving_setting[1]);
            print CUSTOM_EMI_H "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 104Mhz, MT6229, MT6230, MT6268T" if (!defined $driving_setting[2]);
            print CUSTOM_EMI_H "#define EMI_DRV2_BURST_MODE        $driving_setting[2]\n";
        }
        print CUSTOM_EMI_H "#endif\n";

    } # if ($fast_mem_prj_type == 104)
    elsif ($fast_mem_prj_type == 52)
    {
        my @addr = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            print CUSTOM_EMI_H "#define DEV_CONFIG_FLASH_BMODE_ADDR_$idx        $addr[$_]\n";
            print CUSTOM_EMI_H "#define DEV_CONFIG_FLASH_BMODE_DATA_$idx        $data[$_]\n";
        }

        my @addr = split /\s/, $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            print CUSTOM_EMI_H "#define DEV_CONFIG_RAM_BMODE_ADDR_$idx        $addr[$_]\n";
            print CUSTOM_EMI_H "#define DEV_CONFIG_RAM_BMODE_DATA_$idx        $data[$_]\n";
        }

        my $emi_setting = $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{MT6229};
        print CUSTOM_EMI_H "#define EMI_FLASH_BURST_MODE        $emi_setting\n";
        $emi_setting = $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{MT6229};
        print CUSTOM_EMI_H "#define EMI_RAM_BURST_MODE        $emi_setting\n";

        # use #if ... #elif for 6228,6225/6229,6230, 6268T differentiation
        print CUSTOM_EMI_H "#if ( defined(MT6228) || defined(MT6225) )\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_DRIVING"}->{MT6228};
        if ($driving_setting[0] ne 'x')
        {
            print CUSTOM_EMI_H "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
#           die "no 2nd driving setting for CS=0, 52Mhz, MT6228" if (!defined $driving_setting[1]); MT6228 need only 1st and 3rd driving settings
#           print CUSTOM_EMI_H "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 52Mhz, MT6228" if (!defined $driving_setting[1]);
            print CUSTOM_EMI_H "#define EMI_DRV2_BURST_MODE        $driving_setting[1]\n";
        }
        print CUSTOM_EMI_H "#elif ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_DRIVING"}->{MT6229};
        if ($driving_setting[0] ne 'x')
        {
            print CUSTOM_EMI_H "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
            die "no 2nd driving setting for CS=0, 52Mhz, MT6229, MT6230, MT6268T" if (!defined $driving_setting[1]);
            print CUSTOM_EMI_H "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 52Mhz, MT6229, MT6230, MT6268T" if (!defined $driving_setting[2]);
            print CUSTOM_EMI_H "#define EMI_DRV2_BURST_MODE        $driving_setting[2]\n";
        }
        print CUSTOM_EMI_H "#endif\n";

    } # if ($fast_mem_prj_type == 52)

    my $addr = lc($part_info->{CS}->{0}->{ASYNC_EMI}->{ADDRESS});
    $addr =~ s/\s//g;
    if ( ($FLASH_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )
    {
        my @addr = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            print CUSTOM_EMI_H "#define DEV_CONFIG_FLASH_PMODE_ADDR_$idx        $addr[$_]\n";
            print CUSTOM_EMI_H "#define DEV_CONFIG_FLASH_PMODE_DATA_$idx        $data[$_]\n";
        }

        print CUSTOM_EMI_H "#if ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6217};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        print CUSTOM_EMI_H "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

        print CUSTOM_EMI_H "#elif ( defined(MT6226) || defined(MT6227) || defined(MT6226M) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6227};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        print CUSTOM_EMI_H "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

      print CUSTOM_EMI_H "#elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        print CUSTOM_EMI_H "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

        print CUSTOM_EMI_H "#else\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6205B};
        my $emi_setting     = $emi_settings[0] if defined $emi_settings[0]; # get 1st item
        print CUSTOM_EMI_H "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

        print CUSTOM_EMI_H "#endif\n";

    } # if ( ($FLASH_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )

    $addr = lc($part_info->{CS}->{1}->{ASYNC_EMI}->{ADDRESS});
    $addr =~ s/\s//g;
    if ( ($RAM_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )
    {
        my @addr = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            print CUSTOM_EMI_H "#define DEV_CONFIG_RAM_PMODE_ADDR_$idx        $addr[$_]\n";
            print CUSTOM_EMI_H "#define DEV_CONFIG_RAM_PMODE_DATA_$idx        $data[$_]\n";
        }

        print CUSTOM_EMI_H "#if ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6217};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        print CUSTOM_EMI_H "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        print CUSTOM_EMI_H "#elif ( defined(MT6226) || defined(MT6227) || defined(MT6226M) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6227};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        print CUSTOM_EMI_H "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        print CUSTOM_EMI_H "#elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6229};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        print CUSTOM_EMI_H "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        print CUSTOM_EMI_H "#else\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6205B};
        my $emi_setting     = $emi_settings[0] if defined $emi_settings[0]; # get 1st item
        print CUSTOM_EMI_H "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        print CUSTOM_EMI_H "#endif\n";

    } # if ( ($RAM_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )


    print CUSTOM_EMI_H &fat_information();
    my $size                = $part_info->{CS}->{0}->{SIZE};
    my @regions             = split /\n/, $part_info->{CS}->{0}->{LAST_BANK}->{REGION};
    my $sum_of_regions      = 0;
    my $blocks_of_regions   = 0;
    for (0..$#regions)
    {
        if ($regions[$_] =~ /\{(0x\w+),\s*(\d+)\}/) # match {0x20000, 7}
        {
            $blocks_of_regions += $2;
            $sum_of_regions += hex($1) * $2;
        }
    }
    printf CUSTOM_EMI_H "#define FLASH_BASE_ADDRESS    0x%08X\n", (($size/8*1024*1024) - $sum_of_regions);

    print CUSTOM_EMI_H &fat_information_step2();
    printf CUSTOM_EMI_H "#define ALLOCATED_FAT_SPACE   0x%08X\n", $sum_of_regions;

    print CUSTOM_EMI_H &fat_information_low_cost_single_bank_flash();
    for (0..$#regions)
    {
        if ($regions[$_] =~ /\{(0x\w+),\s*(\d+)\}/) # match {0x20000, 7}
        {
            print CUSTOM_EMI_H "   $regions[$_]\n";
        }
    }
    print CUSTOM_EMI_H &fat_information_low_cost_single_bank_flash_else();
    for (0..$#regions)
    {
        if ($regions[$_] =~ /\{(0x\w+),\s*(\d+)\}/) # match {0x20000, 7}
        {
            print CUSTOM_EMI_H "   $regions[$_]\n";
        }
    }

    print CUSTOM_EMI_H &fat_information_step4();
    print CUSTOM_EMI_H "#define TOTAL_BLOCKS          $blocks_of_regions\n";

    print CUSTOM_EMI_H &page_buffer_size_for_page_buffer_program();
    my $pbp_size = ($part_info->{CS}->{0}->{PBP}->{Y_OR_N} =~ /Y/i) ? $part_info->{CS}->{0}->{PBP}->{SIZE} : 0;
    print CUSTOM_EMI_H "kal_uint32 PAGE_BUFFER_SIZE = $pbp_size;\n";

} # if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
{
    print CUSTOM_EMI_H "#define DRAM_CS                     $LPSDRAM_CHIP_SELECT\n";

    print CUSTOM_EMI_H "/* Density of LPSDRAM,in terms of Mbits */\n";
    my $density = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{DENSITY};
    print CUSTOM_EMI_H "#define DRAM_SIZE                   $density\n";

    print CUSTOM_EMI_H "/* EMI_CONL value */\n";
    my $ref_con = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EMI_DRAM_RERESH_CONTROL};
    print CUSTOM_EMI_H "#define EMI_DRAM_RERESH_CONTROL     $ref_con\n";

    print CUSTOM_EMI_H "/* EMI_CONI value */\n";
    my $dram_mode = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EMI_DRAM_MODE};
    print CUSTOM_EMI_H "#define EMI_DRAM_MODE               $dram_mode\n";

    print CUSTOM_EMI_H "/* EMI_CONI value */\n";
    my $dram_ext_mode = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EMI_DRAM_EXT_MODE};
    print CUSTOM_EMI_H "#define EMI_DRAM_EXT_MODE           $dram_ext_mode\n";

    print CUSTOM_EMI_H "/* EMI_CONK value */\n";
    my $dram_ctrl = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EMI_DRAM_CONTROL};
    print CUSTOM_EMI_H "#define EMI_DRAM_CONTROL            $dram_ctrl\n";

    print CUSTOM_EMI_H "/* EMI_GENA value */\n";
    my $gen_ctrla = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL1_VAL"};
    print CUSTOM_EMI_H "#define EMI_GENERAL_CONTROL1_VAL    $gen_ctrla\n";

    print CUSTOM_EMI_H "/* EMI_GENB value */\n";
    my $gen_ctrlb = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL2_VAL"};
    print CUSTOM_EMI_H "#define EMI_GENERAL_CONTROL2_VAL    $gen_ctrlb\n";

    if (($PLATFORM eq 'MT6229') || ($PLATFORM eq 'MT6230'))
    {
        print CUSTOM_EMI_H "/* EMI_GENC value */\n";
        my $gen_ctrlc = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL3_VAL"};
        print CUSTOM_EMI_H "#define EMI_GENERAL_CONTROL3_VAL    $gen_ctrlc\n";
    }

    print CUSTOM_EMI_H "const kal_uint32  EMI_EXTSRAM_SIZE = (DRAM_SIZE<<20) >> 3;\n";

} # elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
else
{
    # Incorrect memory device type or part number not supported!
    ;
}

print CUSTOM_EMI_H &header_file_ending();

close CUSTOM_EMI_H;

print "\n$CUSTOM_EMI_H is generated\n";

#****************************************************************************
# subroutine:  xls_cell_value
# return:      Excel cell value no matter it's in merge area or not
# input:       $Sheet:  Specified Excel Sheet
# input:       $row:    Specified row number
# input:       $col:    Specified column number
#****************************************************************************
sub xls_cell_value
{
    my ($Sheet, $row, $col) = @_;

    if ($Sheet->Cells($row, $col)->{'MergeCells'})
    {
        my $ma = $Sheet->Cells($row, $col)->{'MergeArea'};
        return ($ma->Cells(1, 1)->{'Value'});
    }
    else
    {
        return ($Sheet->Cells($row, $col)->{'Value'})
    }
}


#****************************************************************************
#
# following subroutines generate the templates of
# 1. custom_switchclock.c
# 2. flash_opt.h
# 3. custom_EMI.c
# 4. custom_EMI.h
#
#****************************************************************************
#****************************************************************************
# subroutine:  switch_clk_c_file_ending
# return:      custom_switchclock.c file ending
#****************************************************************************
sub switch_clk_c_file_ending
{
    my $template = <<"__TEMPLATE";
}

#pragma arm section code

#endif  /* DCM_ENABLE */

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_else
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              for non-LPSDRAM and non Burst Mode NOR_RAM_MCP
#****************************************************************************
sub custom_dynamicclockswitch_for_else
{
    my $template = <<"__TEMPLATE";

   register kal_uint32 delay;

   if (clock == MCU_104MHZ) {

      /* restore EMI A */
      *(volatile kal_uint32 *)EMI_CONA = saved_emi_a;

      /* restore EMI B */
      *(volatile kal_uint32 *)EMI_CONB = saved_emi_b;

      /* switch clock to 104MHz */
      *MCUCLK_CON = 0x0703;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

      return 0;
   } else if (clock == MCU_52MHZ) {
      /* restore EMI A */
      *(volatile kal_uint32 *)EMI_CONA = saved_emi_a;

      /* restore EMI B */
      *(volatile kal_uint32 *)EMI_CONB = saved_emi_b;

      /* switch clock to 52MHz */
      *MCUCLK_CON = 0x0303;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

      return 0;
   } else if (clock == MCU_26MHZ) {
      /* save EMI A */
      saved_emi_a = *EMI_CONA;

      /* save EMI B */
      saved_emi_b = *EMI_CONB;

      /* switch clock to 26MHz */
      *MCUCLK_CON = 0x0101;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

      /* set EMI A */
      *EMI_CONA = 0x4102;

      /* set EMI B */
      *EMI_CONB = 0x4102;

      return 0;
   } else if (clock == MCU_13MHZ) {

      /* save EMI A */
      saved_emi_a = *EMI_CONA;

      /* save EMI B */
      saved_emi_b = *EMI_CONB;

      /* switch clock to 13MHz */
      *MCUCLK_CON = 0x0000;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

      /* set EMI A */
      *EMI_CONA = 0x4102;

      /* set EMI B */
      *EMI_CONB = 0x4102;

      return 0;
   } else {

      /* unsupported MCU clock */

      return -1;
   }

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_intel_sibley_ending
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              ending section for INTEL_SIBLEY
#****************************************************************************
sub custom_dynamicclockswitch_for_intel_sibley_ending
{
    my $template = <<"__TEMPLATE";


      /* switch clock to 13MHz */
      *MCUCLK_CON = 0x0000;

      /* delay for a while */
      for (delay = 0; delay < 2; delay++) {

         /* NOP */
      }

      return 0;
   }
#endif  /* !MT6229 && !MT6268T && !MT6230 */

   /* unsupported MCU clock */
   return -1;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_intel_sibley_13mhz
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              section clock == MCU_13MHZ for INTEL_SIBLEY
#****************************************************************************
sub custom_dynamicclockswitch_for_intel_sibley_13mhz
{
    my $template = <<"__TEMPLATE";


      /* switch clock to 26MHz */
      *MCUCLK_CON = 0x0101;

      /* delay for a while */
      for (delay = 0; delay < 2; delay++) {

         /* NOP */
      }

      return 0;
   }
#endif  /* MT6229 , MT6268T, MT6230 */

#if ( !defined(MT6229) && !defined(MT6268T) && !defined(MT6230))
   if (clock == MCU_13MHZ)
   {
      /* set EMI A */
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_intel_sibley_26mhz
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              section clock == MCU_26MHZ for INTEL_SIBLEY
#****************************************************************************
sub custom_dynamicclockswitch_for_intel_sibley_26mhz
{
    my $template = <<"__TEMPLATE";

      return 0;
   }
#endif /* MT6228 || MT6225 || MT6229 || MT6230 || MT6268T */

#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
   if (clock == MCU_26MHZ)
   {
      /* set EMI A */
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_intel_sibley_104mhz
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              section clock == MCU_104MHZ for INTEL_SIBLEY
#****************************************************************************
sub custom_dynamicclockswitch_for_intel_sibley_104mhz
{
    my $template = <<"__TEMPLATE";

   kal_uint32 data, delay;
   volatile kal_uint16 *ptr16;


#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )
   if (clock == MCU_104MHZ)
   {
      /* switch clock to 104MHz */
      *MCUCLK_CON = 0x0703;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {

          /* NOP */
      }

      /* set EMI A */
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_lpsdram_ending
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              ending section for LPSDRAM
#****************************************************************************
sub custom_dynamicclockswitch_for_lpsdram_ending
{
    my $template = <<"__TEMPLATE";

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* exist self-refresh mode */
      *EMI_CONJ &= ~(0x00000100);

      /* wait until the status is changed */
      while (*EMI_CONJ & 0x01000000)
      {
         /* NOP */
      }

      /* enable auto refresh */
      *EMI_CONL = *EMI_CONL | 0x80000000;

      return 0;
   }
#endif  /* !MT6229 && !MT6230 && !MT6268T */

   /* unsupported MCU clock */
   return -1;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_lpsdram_13mhz
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              section clock == MCU_13MHZ for LPSDRAM
#****************************************************************************
sub custom_dynamicclockswitch_for_lpsdram_13mhz
{
    my $template = <<"__TEMPLATE";

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* exist self-refresh mode */
      *EMI_CONJ &= ~(0x00000100);

      /* wait until the status is changed */
      while (*EMI_CONJ & 0x01000000)
      {
         /* NOP */
      }

      /* enable auto refresh */
      *EMI_CONL = *EMI_CONL | 0x80000000;

      return 0;
   }
#endif  /* MT6229 , MT6230, MT6268T */

#if ( !defined(MT6229) && !defined(MT6230) && !defined(MT6268T) )
   if (clock == MCU_13MHZ)
   {
      /* enter self-refresh mode */
      *EMI_CONJ |= 0x00000100;

      /* wait until the status is changed */
      while (!(*EMI_CONJ & 0x01000000))
      {
         /* NOP */
      }

      /* switch clock to 13MHz */
      *MCUCLK_CON = 0x0000;

      /* delay for 8 cycles */
      for (delay = 0; delay < 8; delay++) {

         /* NOP */
      }

      /* specify EMI setting */

      /* set driving */
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_lpsdram_26mhz
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              section clock == MCU_26MHZ for LPSDRAM
#****************************************************************************
sub custom_dynamicclockswitch_for_lpsdram_26mhz
{
    my $template = <<"__TEMPLATE";

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* auto refresh */
      *EMI_CONJ = 0x02;

      /* exist self-refresh mode */
      *EMI_CONJ &= ~(0x00000100);

      /* wait until the status is changed */
      while (*EMI_CONJ & 0x01000000)
      {
         /* NOP */
      }

      /* enable auto refresh */
      *EMI_CONL = *EMI_CONL | 0x80000000;

      return 0;
   }
#endif  /* MT6228 || MT6225 || MT6229 || MT6230 || MT6268T */

#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
   if (clock == MCU_26MHZ)
   {
      /* enter self-refresh mode */
      *EMI_CONJ |= 0x00000100;

      /* wait until the status is changed */
      while (!(*EMI_CONJ & 0x01000000))
      {
         /* NOP */
      }

      /* switch clock to 26MHz */
      *MCUCLK_CON = 0x0101;

      /* delay for 8 cycles */
      for (delay = 0; delay < 8; delay++) {

         /* NOP */
      }

      /* specify EMI setting */

      /* set driving */
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_dynamicclockswitch_for_lpsdram_104mhz
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#              section clock == MCU_104MHZ for LPSDRAM
#****************************************************************************
sub custom_dynamicclockswitch_for_lpsdram_104mhz
{
    my $template = <<"__TEMPLATE";

   register kal_uint32 delay;


#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )
   if (clock == MCU_104MHZ)
   {
      /* enter self-refresh mode */
      *EMI_CONJ |= 0x00000100;

      /* wait until the status is changed */
      while (!(*EMI_CONJ & 0x01000000))
      {
         /* NOP */
      }

      /* switch clock to 104MHz */
      *MCUCLK_CON = 0x0703;

      /* delay for 8 cycles */
      for (delay = 0; delay < 8; delay++) {

         /* NOP */
      }

      /* specify EMI setting */

      /* set driving */
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  before_custom_dynamicclockswitch
# return:      template before the part "FUNCTION custom_DynamicClockSwitch()"
#****************************************************************************
sub before_custom_dynamicclockswitch
{
    my $template = <<"__TEMPLATE";
#include <kal_release.h>
#include <reg_base.h>
#include <init.h>

#ifdef REMAPPING
#define FLASH_BASE_ADDR 0x08000000
#define RAM_BASE_ADDR 0x00
#else
#define FLASH_BASE_ADDR 0x00
#define RAM_BASE_ADDR 0x08000000
#endif

#ifdef DCM_ENABLE

#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
static kal_uint32 saved_emi_a, saved_emi_b;
#pragma arm section rwdata , rodata , zidata

#pragma arm section code = "INTERNCODE"

/*************************************************************************
* FUNCTION
*  custom_DynamicClockSwitch
*
* DESCRIPTION
*  This function dedicates to switch the system clock and adjust the EMI
*  according to the working system clock.
*
* PARAMETERS
*  clock    -    clock to switch
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
int custom_DynamicClockSwitch(mcu_clock_enum clock)
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  switch_clk_c_file_header
# return:      custom_switchclock.c file header
#****************************************************************************
sub switch_clk_c_file_header
{
    my $template = &header_file_header();

    $template =~ s/custom_emi\.h/custom_switchclock\.c/g; # replace file name
    $template =~ s/^(\s*\*\s*) This Module defines.+\n/$1 This file implements clock switching function of DCM\.\n/; # replace file Description
    $template =~ s/^(\s*\*\s*) Shalyn Chua/$1 mtk00702/; # remove #ifndef __CUSTOM_EMI__
    $template =~ s/#ifndef __CUSTOM_EMI__//g; # remove #ifndef __CUSTOM_EMI__
    $template =~ s/#define __CUSTOM_EMI__//g; # remove #define __CUSTOM_EMI__

    return $template;
}

#****************************************************************************
# subroutine:  flash_opt_header
# return:      flash opt header
#****************************************************************************
sub flash_opt_header
{
    my $template = &header_file_header();

    $template =~ s/custom_emi\.h/flash_opt\.h/g; # replace file name
    $template =~ s/EMI \(external memory interface\) related setting/NOR flash related options/g; # replace file description
    $template =~ s/#ifndef __CUSTOM_EMI__//g; # remove #ifndef __CUSTOM_EMI__
    $template =~ s/#define __CUSTOM_EMI__//g; # remove #define __CUSTOM_EMI__

    return $template;
}



#****************************************************************************
# subroutine:  flash_opt_ending
# return:      flash opt ending
#****************************************************************************
sub flash_opt_ending
{
    my $template = <<"__TEMPLATE";

#ifdef NOR_FLASH_TYPE_INTEL_SERIES
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_INTEL
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_RENESAS_SERIES
#define __RENESAS_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_RENESAS
#define __RENESAS_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_INTEL_SIBLEY
#define __INTEL_SERIES_NOR__
#define __INTEL_SIBLEY__
#endif

#ifdef NOR_FLASH_TYPE_RAM_DISK
#define __RAMDISK__
#endif

#ifdef NOR_FLASH_TYPE_SST
#define __AMD_SERIES_NOR__
#define __SST_NOR__
#endif

#ifdef NOR_FLASH_TYPE_ST_AMD_LIKE
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_ST_INTEL_LIKE
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_AMD_SERIES
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_PL_J
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_PL_N
#define __AMD_SERIES_NOR__
#define __SPANSION_PL_N__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_WS_N
#define __AMD_SERIES_NOR__
#define __SPANSION_WS_N__
#define __SPANSION_PL_N__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_GL_A
#define __AMD_SERIES_NOR__
#define __SPANSION_GL_A__
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA_TV
#define __AMD_SERIES_NOR__
#define __TOSHIBA_TV__
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA_TY
#define __AMD_SERIES_NOR__
#define __TOSHIBA_TY__
#endif

#ifdef NOR_FLASH_TYPE_SILICON7
#define __RENESAS_SERIES_NOR__
#endif

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  c_file_ending
# return:      file ending
#****************************************************************************
sub c_file_ending
{
    my $template = <<"__TEMPLATE";

    return status;
}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_get_EXTSRAM_size()
*
* DESCRIPTION
*  Return predefined external SRAM size.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
custom_get_EXTSRAM_size(kal_uint32 *size)
{
   *size = (kal_uint32)EMI_EXTSRAM_SIZE;
}


/*************************************************************************
* FUNCTION
*  Initialize_FDD_tables
*
* DESCRIPTION
*  Initialize important information for NOR-flash disk
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifndef __NOR_FDM5__
void Initialize_FDD_tables(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )

   /* Initialize MTD data table */
   mtdflash.Signature = ~((kal_uint32)RegionInfo);

#ifdef __MTK_TARGET__
   mtdflash.BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + FLASH_BASE_ADDRESS);
#endif

   mtdflash.RegionInfo = (FlashRegionInfo *)RegionInfo;

   /* Initialize FDD data table */
   FlashDriveData.MTDDriver = &NORFlashMtd;
   FlashDriveData.MTDData = &mtdflash;
   FlashDriveData.AvailSectorsInBlock = AVAILSECTORS;
   FlashDriveData.ValidSectorsInBlock = VALIDSECTORS;
   FlashDriveData.SectorMap = (BYTE*)SectorMap;
   FlashDriveData.PartitionSectors = PARTITION_SECTORS;
   FlashDriveData.Buffer = FDMBuffer;

#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
}
#endif /*__NOR_FDM5__*/


void nor_sweep_device(void)
{
#ifdef __NOR_FDM5__
   kal_set_eg_events(nor_egid, NOR_DMAN_EVENT, KAL_OR);
#endif
   return;
}

void nor_manual_reclaim(void)
{
#ifdef __NOR_FDM5__
   kal_set_eg_events(nor_egid, NOR_BRECL_EVENT, KAL_OR);
#endif
   return;
}
#endif /*__FUE__*/

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_ram_async_access_part2
# return:      template of "FUNCTION custom_setAdvEMI()" for
#              RAM_ACCESS_TYPE==ASYNC_ACCESS
#              part 2
#****************************************************************************
sub custom_setadvemi_for_ram_async_access_part2
{
    my $template = <<"__TEMPLATE";

      for (delayRAM = 0; delayRAM < 200; delayRAM++);

      *(EMI_CONB) = EMI_RAM_PAGE_MODE;

      for (delayRAM = 0; delayRAM < 200; delayRAM++);

      status |= 8;
   }

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_ram_async_access_part1
# return:      template of "FUNCTION custom_setAdvEMI()" for
#              RAM_ACCESS_TYPE==ASYNC_ACCESS
#              part 1
#****************************************************************************
sub custom_setadvemi_for_ram_async_access_part1
{
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on RAM (SRAM / PSRAM / Cellular RAM) */
   {
      kal_uint32 RAMBaseAddr;
      kal_uint32 delayRAM;

      RAMBaseAddr = (INT_RetrieveFlashBaseAddr() ^ 0x08000000);

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_flash_async_access_part2
# return:      template of "FUNCTION custom_setAdvEMI()" for
#              FLASH_ACCESS_TYPE==ASYNC_ACCESS
#              part 2
#****************************************************************************
sub custom_setadvemi_for_flash_async_access_part2
{
    my $template = <<"__TEMPLATE";

      for (delayNOR = 0; delayNOR < 200; delayNOR++);

      *(EMI_CONA) = EMI_FLASH_PAGE_MODE;

      for (delayNOR = 0; delayNOR < 200; delayNOR++);

      status |= 4;
   }


__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_flash_async_access_part1
# return:      template of "FUNCTION custom_setAdvEMI()" for
#              FLASH_ACCESS_TYPE==ASYNC_ACCESS
#              part 1
#****************************************************************************
sub custom_setadvemi_for_flash_async_access_part1
{
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on NOR-flash */
   {
      kal_uint32 NORBaseAddr;
      kal_uint32 delayNOR;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access_part3
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part 3
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_part3
{
    my $template = <<"__TEMPLATE";

      for (delay = 0; delay < 200; delay++);

      *EMI_GENA = EMI_DRV0_BURST_MODE;
      *EMI_GENB = EMI_DRV1_BURST_MODE;
#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
      *EMI_GENC = EMI_DRV2_BURST_MODE;
#endif


      for (delay = 0; delay < 200; delay++);

      *(EMI_CONA) = EMI_FLASH_BURST_MODE;
      *(EMI_CONB) = EMI_RAM_BURST_MODE;

      for (delay = 0; delay < 200; delay++);

      status |= 2;
   }


__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access_part2
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part 2
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_part2
{
    my $template = <<"__TEMPLATE";

      for (delay = 0; delay < 200; delay++);

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access_part1
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part 1
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_part1
{
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on NOR-flash */
   {
      kal_uint32 NORBaseAddr, RAMBaseAddr;
      kal_uint32 delay;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();
      RAMBaseAddr = NORBaseAddr ^ 0x08000000;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access_104_ty_part
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part for 104MHz TOSHIBA TYAX
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_104_ty_part
{
    my $template = <<"__TEMPLATE";
   /* Turn on 104Mhz synchronous mode on NOR-flash and PSRAM */
   {
      kal_uint32 NORBaseAddr, RAMBaseAddr;
      kal_uint32 delay;
      kal_uint16 data;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();
      RAMBaseAddr = NORBaseAddr ^ 0x08000000;

      *EMI_GENB = EMI_DRV0_BURST_MODE;
#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
      *EMI_GENC = EMI_DRV1_BURST_MODE;
#endif
      *EMI_GENA = EMI_DRV2_BURST_MODE;

      /* Configure NOR-flash to synchronous access */
      for (delay = 0; delay < 0xff; delay++);

      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_1)) = DEV_CONFIG_FLASH_BMODE_DATA_1;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_2)) = DEV_CONFIG_FLASH_BMODE_DATA_2;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_3)) = DEV_CONFIG_FLASH_BMODE_DATA_3;

      for (delay = 0; delay < 0xff; delay++);

      *(EMI_CONA) = EMI_FLASH_BURST_MODE;

      /* Configure PSRAM to synchronous access */
      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_1));

      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_2)) = data;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_3)) = data;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_4)) = data;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_5)) = data;

      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_6));

      for (delay = 0; delay < 0xff; delay++);

      *(EMI_CONB) = EMI_RAM_BURST_MODE;

      for (delay = 0; delay < 0xff; delay++);

      status |= 0x10;
   }
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access_104_sibley_part
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part for 104MHz INTEL SIBLEY
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_104_sibley_part
{
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on NOR-flash */
   {
      kal_uint32 NORBaseAddr, RAMBaseAddr;
      kal_uint32 delay;
      kal_uint16 data;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();
      RAMBaseAddr = NORBaseAddr ^ 0x08000000;

      *EMI_GENB = EMI_DRV0_BURST_MODE;
#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
      *EMI_GENC = EMI_DRV1_BURST_MODE;
#endif
      *EMI_GENA = EMI_DRV2_BURST_MODE;

      /* Configure NOR-flash to synchronous access */
      for (delay = 0; delay < 0xff; delay++);

      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_1)) = DEV_CONFIG_FLASH_BMODE_DATA_1;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_2)) = DEV_CONFIG_FLASH_BMODE_DATA_2;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_3)) = DEV_CONFIG_FLASH_BMODE_DATA_3;
      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_4)) = DEV_CONFIG_FLASH_BMODE_DATA_4;

      for (delay = 0; delay < 0xff; delay++);

      *(volatile kal_uint16 *)(NORBaseAddr|(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_5)) = DEV_CONFIG_FLASH_BMODE_DATA_5;

      *(EMI_CONA) = EMI_FLASH_BURST_MODE;

      /* Configure PSRAM to synchronous access */
      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_1));
      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_2));

      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_3)) = DEV_CONFIG_RAM_BMODE_DATA_3;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_4)) = DEV_CONFIG_RAM_BMODE_DATA_4;

      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_5));
      data = *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_6));

      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_7)) = DEV_CONFIG_RAM_BMODE_DATA_7;
      *(volatile kal_uint16 *)(RAMBaseAddr|(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_8)) = DEV_CONFIG_RAM_BMODE_DATA_8;

      for (delay = 0; delay < 0xff; delay++);

      *(EMI_CONB) = EMI_RAM_BURST_MODE;

      status |= 0x10;
   }
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_last_bank_is_c_part2
# return:      template of "FUNCTION custom_setAdvEMI()"
#              for CS0's Lask Bank, C/F==C part 2
#****************************************************************************
sub custom_setadvemi_for_last_bank_is_c_part2
{
    my $template = <<"__TEMPLATE";

      for (delay = 0; delay < 200; delay++);

      status = 1;
   }


__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_last_bank_is_c_part1
# return:      template of "FUNCTION custom_setAdvEMI()"
#              for CS0's Lask Bank, C/F==C part 1
#****************************************************************************
sub custom_setadvemi_for_last_bank_is_c_part1
{
    my $template = <<"__TEMPLATE";
   /* Partition Configuration */
   {
      kal_uint32 NORBaseAddr;
      kal_uint32 delay;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  before_custom_setadvemi
# return:      template before the part "FUNCTION custom_setAdvEMI()"
#****************************************************************************
sub before_custom_setadvemi
{
    my $template = <<"__TEMPLATE";
}

#ifndef __FUE__

#ifdef __MTK_TARGET__
#pragma arm section code = "INTERNCODE"
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  custom_setAdvEMI()
*
* DESCRIPTION
*   This routine aims to set additional EMI
*   This is special for device which needs to set device configuration
*   register to turn-on special mode.
*
* PARAMETERS
*
* RETURNS
*  1:
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_setAdvEMI(void)
{
   kal_int8    status = 0;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setemi_for_nor_ram_mcp
# return:      template of "FUNCTION custom_setEMI()" for NOR_RAM_MCP
#****************************************************************************
sub custom_setemi_for_nor_ram_mcp
{
    my $template = <<"__TEMPLATE";
   if ( EMI_CSConfiguration[0] != UNUSED )
         *(EMI_CONA) = EMI_SettingOnCS[0];

   if ( EMI_CSConfiguration[1] != UNUSED )
         *(EMI_CONB) = EMI_SettingOnCS[1];

   if ( EMI_CSConfiguration[2] != UNUSED )
         *(EMI_CONC) = EMI_SettingOnCS[2];

   if ( EMI_CSConfiguration[3] != UNUSED )
         *(EMI_COND) = EMI_SettingOnCS[3];

   /* Setting EMI general control register and cache/prefetch size if necessary */
#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )

   *EMI_GENA = EMI_GENERAL_CONTROL_0;
   *EMI_GENB = EMI_GENERAL_CONTROL_1;

#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
   *EMI_GENC = EMI_GENERAL_CONTROL_2;
#endif /* MT6229, MT6230, MT6268T */

#elif ( defined(MT6205B) || defined(MT6208) )

   *EMI_GEN = EMI_GENERAL_CONTROL;

#else

   *EMI_GEN = EMI_GENERAL_CONTROL;
   *PREFETCH_CON = EMI_CACHE_PREFETCH;

#endif

   return 0;
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setemi_for_lpsdram
# return:      template of "FUNCTION custom_setEMI()" for LPSDRAM
#****************************************************************************
sub custom_setemi_for_lpsdram
{
    my $template = <<"__TEMPLATE";
   kal_uint32   DRAM_Enable = DRAM_CS;
   kal_uint32   delay;

   if ( (DRAM_Enable != 0xFF) && (DRAM_Enable < 4) )
   {
      /* remapping if DRAM at CS1 */
      if ( DRAM_Enable == 1 )
         *EMI_REMAP = 3;
      else
         *EMI_REMAP = 2;

      /* Setting driving */
      *EMI_GENB = EMI_GENERAL_CONTROL2_VAL;

#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
      *EMI_GENC = EMI_GENERAL_CONTROL3_VAL;
#endif

      /* Turn on clock and driving tuning */
      *EMI_GENA = EMI_GENERAL_CONTROL1_VAL;

      for (delay = 0; delay < 200; delay++) ;

      /* Turn-on SDRAM */
      *EMI_CONK = EMI_DRAM_CONTROL;
      *EMI_CONL = EMI_DRAM_RERESH_CONTROL;

      /*  Ping-pong operation, SDRAM enable, CAS = 2T, Burst Read/Single Write ; \CS1, 8words burst length, sequential burs, */
      if ( DRAM_SIZE == 64 )
        *EMI_CONI = EMI_DRAM_MODE | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 128 )
        *EMI_CONI = EMI_DRAM_MODE | (1 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 256 )
         *EMI_CONI = EMI_DRAM_MODE | (2 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 512 )
         *EMI_CONI = EMI_DRAM_MODE | (3 << 20) | (DRAM_CS << 16);

      for (delay = 0; delay < 200; delay++);

      /* Precharge all */
      *EMI_CONJ = 0x01;

      for (delay = 0; delay < 200; delay++);

      /* Ping-pong operation, SDRAM enable, CAS = 2T, Burst Read/Single Write ; \CS1, 8words burst length, sequential burs, */
      if ( DRAM_SIZE == 64 )
        *EMI_CONI = EMI_DRAM_EXT_MODE | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 128 )
         *EMI_CONI = EMI_DRAM_EXT_MODE | (1 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 256 )
         *EMI_CONI = EMI_DRAM_EXT_MODE | (2 << 20) | (DRAM_CS << 16);
      else if (DRAM_SIZE == 512)
         *EMI_CONI = EMI_DRAM_EXT_MODE | (3 << 20) | (DRAM_CS << 16);

      /* Set mode register */
      *EMI_CONJ = 0x04;

      for (delay = 0; delay < 200; delay++);

       /* Ping-pong operation, SDRAM enable, CAS = 2T, Burst Read/Single Write; \CS1, 8words burst length, sequential burs, */
      if ( DRAM_SIZE == 64 )
        *EMI_CONI = EMI_DRAM_MODE | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 128 )
         *EMI_CONI = EMI_DRAM_MODE | (1 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 256 )
         *EMI_CONI = EMI_DRAM_MODE | (2 << 20) | (DRAM_CS << 16);
      else if ( DRAM_SIZE == 512 )
         *EMI_CONI = EMI_DRAM_MODE | (3 << 20) | (DRAM_CS << 16);

      /* Set mode register */
      *EMI_CONJ = 0x04;

      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 8 times auto-refresh command */
      *EMI_CONJ = 0x02;
      for (delay = 0; delay < 200; delay++);

      /* 104MHz */
      *EMI_CONL = EMI_DRAM_RERESH_CONTROL | 0x80000000;

      for (delay = 0; delay < 200; delay++);

      return 1;
   }

   return -1;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  before_custom_setemi
# return:      template before the part "FUNCTION custom_setEMI()"
#****************************************************************************
sub before_custom_setemi
{
    my $template = <<"__TEMPLATE";
#define FLASHCONF_C

#ifndef FLASH_DISKDRV_DEBUG
#include "kal_release.h"
#else
#include <stdlib.h>
#endif

#include "flash_opt.h"
#include "reg_base.h"
#include "MemoryDevice_TypeDef.h"
#include "custom_MemoryDevice.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "NAND_FDM.h"
#include "custom_emi.h"

/*
 ****************************************************************************
 Essential Declarations for NOR-Flash Disk
 ****************************************************************************
*/
#ifndef __FUE__
#if ( defined(__FS_SYSDRV_ON_NAND__) || defined( _NAND_FLASH_BOOTING_) )

/* System Drive on NAND-flash */
const kal_uint32 NFB_BASE_ADDRESS = FLASH_BASE_ADDRESS;
const kal_uint32 NFB_ALLOCATED_FAT_SPACE = ALLOCATED_FAT_SPACE;

#else/* __FS_SYSDRV_ON_NAND__ || _NAND_FLASH_BOOTING_ */

#ifndef __NOR_FDM5__

/* System Drive on NOR-flash */

#ifndef __INTEL_SIBLEY__

/* Each FAT sector is 512bytes (0x200) */
#define TOTAL_SECTORS   (ALLOCATED_FAT_SPACE/0x200)

kal_uint8 FDMBuffer[512];

FS_Driver NORFlashDriver =
{
   NOR_MountDevice,
   NOR_ShutDown,
   NOR_ReadSectors,
   NOR_WriteSectors,
   NOR_MediaChanged,
   NULL,
   NOR_GetDiskGeometry,
   NOR_LowLevelFormat,
   NOR_NonBlockWriteSectors,
   NOR_RecoverableWriteSectors,
   NOR_ResumeSectorStates,
   NULL, /*high level format*/
   NULL, /*flush data*/
   NULL  /*message ack*/
#ifdef __SECURITY_OTP__
   ,
   NULL, /*copy sector*/
   OTPAccess,
   OTPQueryLength
#endif
};

#else

/* Each FAT sector is 1024bytes (0x200) */
#define TOTAL_SECTORS   (ALLOCATED_FAT_SPACE/0x400)

kal_uint8 FDMBuffer[1024];

FS_Driver NORFlashDriver =
{
   SIB_MountDevice,
   NOR_ShutDown,
   SIB_ReadSectors,
   SIB_WriteSectors,
   NOR_MediaChanged,
   NULL,
   SIB_GetDiskGeometry,
   SIB_LowLevelFormat,
   SIB_NonBlockWriteSectors,
   SIB_RecoverableWriteSectors,
   SIB_ResumeSectorStates,
   NULL, /*high level format*/
   NULL, /*flush data*/
   NULL  /*message ack*/
#ifdef __SECURITY_OTP__
   ,
   NULL, /*copy sector*/
   OTPAccess,
   OTPQueryLength
#endif
};

#endif /* __INTEL_SIBLEY__ */

static WORD AVAILSECTORS[TOTAL_BLOCKS];
static WORD VALIDSECTORS[TOTAL_BLOCKS];
static BYTE SectorMap[TOTAL_SECTORS];
NOR_FLASH_DRV_Data  FlashDriveData;

extern NOR_MTD_Driver NORFlashMtd;

#ifdef __MTK_TARGET__

static NOR_Flash_MTD_Data mtdflash;
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

#else

static NOR_Flash_MTD_Data mtdflash =
{
   MakeMtdFlashData((BYTE *)FLASH_BASE_ADDRESS, RegionInfo)
};

#endif /* __MTK_TARGET__ */

#endif /*__NOR_FDM5__*/
#endif /* __FS_SYSDRV_ON_NAND__ || _NAND_FLASH_BOOTING_ */

#ifdef PARTITION_SIZE

 #if (PARTITION_SIZE > 0 && PARTITION_SIZE < NAND_MINIMUM_PARTITION_SIZE)
  #error " PARTITION_SIZE MUST be larger than NAND_MINIMUM_PARTITION_SIZE !!"
 #endif

 #if (defined(_NAND_FLASH_BOOTING_))
  #if ( (PARTITION_SIZE << 9) > ALLOCATED_FAT_SPACE)
   #error " PARTITION_SIZE MUST be less than ALLOCATED_FAT_SPACE !!"
  #endif
 #endif /* _NAND_FLASH_BOOTING_ */

#endif /* PARTITION_SIZE */

kal_uint32 custom_part_secs = PARTITION_SIZE;
NAND_FLASH_DRV_DATA  NANDFlashDriveData;
#endif /*__FUE__*/


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_setEMI(void)
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  c_file_header
# return:      c file header
#****************************************************************************
sub c_file_header
{
    my $template = &header_file_header();

    $template =~ s/custom_emi\.h/custom_emi\.c/g; # replace file name
    $template =~ s/#ifndef __CUSTOM_EMI__//g; # remove #ifndef __CUSTOM_EMI__
    $template =~ s/#define __CUSTOM_EMI__//g; # remove #define __CUSTOM_EMI__

    return $template;
}

#****************************************************************************
# subroutine:  header_file_ending
# return:      header file ending
#****************************************************************************
sub header_file_ending
{
    my $template = <<"__TEMPLATE";


#endif /* __CUSTOM_EMI__ */

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  page_buffer_size_for_page_buffer_program
# return:      template of part "configure flash memory for FAT",
#              step "page buffer size in WORD for page buffer program"
#****************************************************************************
sub page_buffer_size_for_page_buffer_program
{
    my $template = <<"__TEMPLATE";

/*******************************************************************************
   Step 5. Modify the value of page buffer size in WORD for page buffer program
 *******************************************************************************/
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  fat_information_step4
# return:      template of part "configure flash memory for FAT" step 4.
#****************************************************************************
sub fat_information_step4
{
    my $template = <<"__TEMPLATE";
   EndRegionInfo /* Don't modify this line */
};
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ */

/*******************************************************************************
   Step 4. Modify the value of TOTAL_BLOCKS, which is the sum of the number of
           sectors in all regions.
           Note : The Maximum value of TOTAL_BLOCKS is (127).
 *******************************************************************************/
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  fat_information_low_cost_single_bank_flash_else
# return:      template of part "configure flash memory for FAT"
#              section _LOW_COST_SINGLE_BANK_FLASH_ Else
#****************************************************************************
sub fat_information_low_cost_single_bank_flash_else
{
    my $template = <<"__TEMPLATE";
   EndRegionInfo /* Don't modify this line */
};
#else /* _LOW_COST_SINGLE_BANK_FLASH_ */
static const FlashRegionInfo RegionInfo[] =
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  fat_information_low_cost_single_bank_flash
# return:      template of part "configure flash memory for FAT",
#              section _LOW_COST_SINGLE_BANK_FLASH_
#****************************************************************************
sub fat_information_low_cost_single_bank_flash
{
    my $template = <<"__TEMPLATE";

/*******************************************************************************
   Step 3. Fill the flash region information table, a region is the memory space
           that contains continuous sectors of equal size. Each region element
           in the table is the format as below:
           {S_sector, N_sector},
               S_sector: the size of sector in the region
               N_sector: the number of sectors in the region
 *******************************************************************************/
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
static FlashRegionInfo RegionInfo[] =
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  fat_information_step2
# return:      template of part "configure flash memory for FAT" step2
#****************************************************************************
sub fat_information_step2
{
    my $template = <<"__TEMPLATE";

/*******************************************************************************
   Step 2. Modify the value of ALLOCATED_FAT_SPACE, which is the total flash
           space allocated for FAT
 *******************************************************************************/
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  fat_information
# return:      template of part "configure flash memory for FAT"
#****************************************************************************
sub fat_information
{
    my $template = <<"__TEMPLATE";

/*
 *******************************************************************************
   Follow the steps below to configure flash memory for FAT

   Note : All sectors allocated for FAT MUST be continuous sectors.

 *******************************************************************************
*/

/*******************************************************************************
   Step 1. Modify the value of FLASH_BASE_ADDRESS, which is the starting address
           of the flash memory allocated for FAT
 *******************************************************************************/
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  additional_information
# return:      template of part "additional information"
#****************************************************************************
sub additional_information
{
    my $template = <<"__TEMPLATE";
};

#endif


/*
 ****************************************************************************
 Specify additional information
 ****************************************************************************
*/
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  emi_setting_6228_6229
# return:      template of part "EMI Setting" section MT6228, MT6229, MT6225, MT6268T, MT6230
#****************************************************************************
sub emi_setting_6228_6229
{
    my $template = <<"__TEMPLATE";
};

#elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )

const kal_uint32   EMI_SettingOnCS[4] =
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  emi_setting_6227_6226_6226m
# return:      template of part "EMI Setting" section MT6227, MT6226, MT6226M
#****************************************************************************
sub emi_setting_6227_6226_6226m
{
    my $template = <<"__TEMPLATE";
};

#elif ( defined(MT6227) || defined(MT6226) || defined(MT6226M) )

const kal_uint32   EMI_SettingOnCS[4] =
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  emi_setting_6218b_6217_6219
# return:      template of part "EMI Setting" section MT6218B, MT6217, MT6219
#****************************************************************************
sub emi_setting_6218b_6217_6219
{
    my $template = <<"__TEMPLATE";
};

#elif ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )

const kal_uint32   EMI_SettingOnCS[4] =
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  emi_setting_6205b_6208
# return:      template of part "EMI Setting" section MT6205B, MT6208
#****************************************************************************
sub emi_setting_6205b_6208
{
    my $template = <<"__TEMPLATE";

#endif


/*
 ****************************************************************************
 Specify the related EMI Setting
 ****************************************************************************
*/
#if ( defined(MT6205B) || defined(MT6208) )

const kal_uint16   EMI_SettingOnCS[4] =
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  driving_and_cache_prefetch_setting_else
# return:      template of part "driving and cache/prefetch setting",
#              section else
#****************************************************************************
sub driving_and_cache_prefetch_setting_else
{
    my $template = <<"__TEMPLATE";

#else
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  driving_and_cache_prefetch_setting_6218b_6217_6219
# return:      template of part "driving and cache/prefetch setting",
#              section MT6218B, MT6217, MT6219
#****************************************************************************
sub driving_and_cache_prefetch_setting_6218b_6217_6219
{
    my $template = <<"__TEMPLATE";

#elif ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  driving_and_cache_prefetch_setting_6229
# return:      template of part "driving and cache/prefetch setting",
#              section MT6229, MT6268T
#****************************************************************************
sub driving_and_cache_prefetch_setting_6229
{
    my $template = <<"__TEMPLATE";

#elif ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  driving_and_cache_prefetch_setting_6228
# return:      template of part "driving and cache/prefetch setting",
#              section MT6228, MT6225
#****************************************************************************
sub driving_and_cache_prefetch_setting_6228
{
    my $template = <<"__TEMPLATE";

#elif ( defined(MT6228) || defined(MT6225) )
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  driving_and_cache_prefetch_setting_6205b_6208
# return:      template of part "driving and cache/prefetch setting",
#              section MT6205B, MT6208
#****************************************************************************
sub driving_and_cache_prefetch_setting_6205b_6208
{
    my $template = <<"__TEMPLATE";

/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/
#if ( defined(MT6205B) || defined(MT6208) )
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  ram_size_in_bytes
# return:      template of part "RAM size in Bytes"
#****************************************************************************
sub ram_size_in_bytes
{
    my $template = <<"__TEMPLATE";
};


/*
 ****************************************************************************
 Specify RAM size in Bytes
 ****************************************************************************
*/
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  emi_csconfiguration
# return:      template of part EMI_CSConfiguration
#****************************************************************************
sub emi_csconfiguration
{
    my $template = <<"__TEMPLATE";
/*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/
const ExtMemoryType_T   EMI_CSConfiguration[4] =
{
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  header_file_header
# return:      header file header
#****************************************************************************
sub header_file_header
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_emi.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the EMI (external memory interface) related setting.
 *
 * Author:
 * -------
 *   Shalyn Chua
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

#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__


__TEMPLATE

  return $template;
}
