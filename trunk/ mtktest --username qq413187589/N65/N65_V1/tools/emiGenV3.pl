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
#*       1. parse custom_MemoryDevice.h to get memory device type and part number
#*       2. read a excel file to get appropriate emi setting based on the part number
#*       3. based on the emi settings, generate custom_switchclock.c if not exist
#*       4. based on the emi settings, generate flash_opt.h if not exist
#*       5. based on the emi settings, generate custom_EMI.c if not exist
#*       6. based on the emi settings, generate custom_EMI.h if not exist
#*
#* Author:
#* -------
#*   JI Huang      (mtk01077)
#*   Sherman Wang  (mtk00590)
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
use Win32::OLE qw(in with);
use Win32::OLE::Const 'Microsoft Excel';
$Win32::OLE::Warn = 3;                                # die on errors...

#****************************************************************************
# Constants
#****************************************************************************
my $EMIGEN_VERNO  = " V3.06";
                    # V3.06 , by JI at 2007/08/02 , revise page buffer size/iteration for single-bank feature
                    # V3.05 , by JI at 2007/07/20 , support new device type NOR_LPSDRAM_MCP
                    # V3.04 , by JI at 2007/07/15 , support new chip MT6223P
                    # V3.03 , by JI at 2007/07/15 , output single / mutli bank NOR Flash information 
                    # V3.02 , by JI at 2007/04/22 , custom_EMI.h stop when TOTAL_BLOCK > 127
                    # V3.01 , by JI at 2007/04/19 , custom_switchclock.c revise for MT6227D, MT6223 
                    # V3.00 , by JI at 2007/04/12 , MT6227D, MT6223 supported since 07A
                    #
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

my $COLUMN_VENDOR               = 1;
my $COLUMN_PART_NUMBER          = 2;

# column index for Sheet 'NOR_RAM_MCP'
my $COLUMN_ADMUX                = 3;
my $COLUMN_CS                   = 4;
my $COLUMN_SIZE                 = 5;
my $COLUMN_PAGE_SIZE            = 6;
my $COLUMN_SERIES               = 7;
my $COLUMN_BANK                 = 8;
my $COLUMN_LAST_BANK_F_OR_C     = 9;
my $COLUMN_LAST_BANK_C_ADDR     = 10;
my $COLUMN_LAST_BANK_C_DATA     = 11;
my $COLUMN_LAST_BANK_REGION     = 12;
my $COLUMN_PBP_Y_OR_N           = 13;
my $COLUMN_PBP_SIZE             = 14;
my $COLUMN_ASYNC_EMI            = 15;
my $COLUMN_ASYNC_DRIVING        = 22;
my $COLUMN_52MHZ_SYNC_EMI       = 29;
my $COLUMN_52MHZ_SYNC_DRIVING   = 33;
my $COLUMN_104MHZ_SYNC_EMI      = 38;
my $COLUMN_26MHZ_SYNC_EMI       = 41; # modified for clock switching
my $COLUMN_13MHZ_SYNC_EMI       = 44; # modified for clock switching
my $COLUMN_104MHZ_SYNC_DRIVING  = 48; # modified for clock switching

# column index for Sheet 'LPSDRAM'
my $COLUMN_DENSITY                         = 3;
my $COLUMN_EMI_DRAM_RERESH_CONTROL         = 4;
my $COLUMN_MI_DRAM_MODE                    = 5;
my $COLUMN_EMI_DRAM_EXT_MODE               = 6;
my $COLUMN_EMI_DRAM_CONTROL                = 7;
my $COLUMN_104MHZ_EMI_GENERAL_CONTROL1_VAL = 8; # modified for clock switching
my $COLUMN_104MHZ_EMI_GENERAL_CONTROL2_VAL = 9; # modified for clock switching
my $COLUMN_104MHZ_EMI_GENERAL_CONTROL3_VAL = 10; # modified for clock switching
my $COLUMN_26MHZ_EMI_GENERAL_CONTROL1_VAL  = 11; # modified for clock switching
my $COLUMN_26MHZ_EMI_GENERAL_CONTROL2_VAL  = 12; # modified for clock switching
my $COLUMN_26MHZ_EMI_GENERAL_CONTROL3_VAL  = 13; # modified for clock switching
my $COLUMN_13MHZ_EMI_GENERAL_CONTROL1_VAL  = 14; # modified for clock switching
my $COLUMN_13MHZ_EMI_GENERAL_CONTROL2_VAL  = 15; # modified for clock switching
my $COLUMN_13MHZ_EMI_GENERAL_CONTROL3_VAL  = 16; # modified for clock switching


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
#                           VENDOR          => $vendor,
my $part_info     = ();   # has different data structures for different $MEMORY_DEVICE_TYPE
my $is_part_found = 1;    #  1: all part numbers are found
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
   # "#define RAM_ACCESS_TYPE       ASYNC_ACCESS"
   # "#define CS0_PART_NUMBER       RD38F3040L0ZBQ0"

   $MEMORY_DEVICE_TYPE              = $1 if (/^#define\s+MEMORY_DEVICE_TYPE\s+(\w+)/);
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
    &DeviceListParser_NOR_RAM_MCP();
} # if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
{
    &DeviceListParser_LPSDRAM();
}# elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
elsif ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP')
{
    &DeviceListParser_NOR_LPSDRAM_MCP();
}# elsif ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP')
else
{
    undef $MEMORY_DEVICE_TYPE;
}

# close the temp Excel file
$Book->Close(1);

die "Incorrect memory device type"  unless $MEMORY_DEVICE_TYPE;
die "part number not supported"     if ($is_part_found <= 0);

#****************************************************************************
# PLATFORM EMI support matrix
#****************************************************************************
my %BBtbl_SYNC_ACCESS = 
    (       
        'MT6228'  => 1,
        'MT6229'  => 1,
        'MT6230'  => 1,
        'MT6268T' => 1,
    );
my %BBtbl_LPSDRAM = 
    (       
        'MT6225'  => 1,
        'MT6228'  => 1,
        'MT6229'  => 1,
        'MT6230'  => 1,
    );
#****************************************************************************
# check consistency among PLATFORM, MCU_CLOCK and MemoryDeviceList data
#****************************************************************************
my $fast_mem_prj_type = 0; # 104: MT6228/MT6229 SYNC_ACCESS MCU_104M
                           # 52: MT6228/MT6229 SYNC_ACCESS MCU_52M
                           # 0: other settings

if ( $MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP'
  && ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && ($RAM_ACCESS_TYPE eq 'SYNC_ACCESS')
  && $BBtbl_SYNC_ACCESS{$PLATFORM} )
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

if ( $MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP'
  && ($FLASH_ACCESS_TYPE ne 'SYNC_ACCESS') )
{
    die "Device NOR_LPSDRAM_MCP is recommend to set FLASH_ACCESS_TYPE = SYNC_ACCESS!\n";
}

if ( $MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP'
  && ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') 
  && $BBtbl_SYNC_ACCESS{$PLATFORM} )
{
    if ($MCU_CLOCK eq 'MCU_104M')
    {
        die "Device not support 104MHz Burst Access!\n" if ($part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{ADDRESS} eq 'x');
        if (($part_info->{CS}->{0}->{SERIES} ne 'INTEL_SIBLEY') && ($part_info->{CS}->{0}->{SERIES} ne 'TOSHIBA_TY'))
        {
            die "Not support 104MHz Burst Access except Intel Sibley and Toshiba TY!\n";
        }
        $fast_mem_prj_type = 104;
    }
    elsif ($MCU_CLOCK eq 'MCU_52M')
    {
        die "Device not support 52MHz Burst Access!\n" if ($part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{ADDRESS} eq 'x');
        $fast_mem_prj_type = 52;
    }
}

if ( ($MEMORY_DEVICE_TYPE eq 'LPSDRAM') && ($LPSDRAM_CHIP_SELECT !~ /0xFF/i)
     && not exists $BBtbl_LPSDRAM{$PLATFORM} )
{
    die "$PLATFORM not support LPSDRAM!\n";
}

if ( ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP') && not exists $BBtbl_LPSDRAM{$PLATFORM} )
{
    die "$PLATFORM not support NOR_LPSDRAM_MCP!\n";
}

#****************************************************************************
# generate custom_switchclock.c
#****************************************************************************
if ($is_existed_switch_clk_c == 0)
{
    open (SWITCH_CLK_C, ">$SWITCH_CLK_C") or die "cannot open $SWITCH_CLK_C\n";

    print SWITCH_CLK_C &copyright_file_header();
    print SWITCH_CLK_C &description_file_header(               "custom_switchclock.c",
          "This file implements clock switching function of Dynamic Clock Management",
                                                  "EMI auto generator". $EMIGEN_VERNO);
    print SWITCH_CLK_C &custom_switchclock_file_body();
    close SWITCH_CLK_C or die "fail to generate $SWITCH_CLK_C\n$!\n";

    print "\n$SWITCH_CLK_C is generated\n";
} # if ($is_existed_switch_clk_c == 0)

#****************************************************************************
# generate inc\flash_opt.h
#****************************************************************************
if ($is_existed_flash_opt == 0)
{
    open (FLASH_OPT_H, ">$FLASH_OPT_H") or die "cannot open $FLASH_OPT_H\n";

    print FLASH_OPT_H &copyright_file_header();
    print FLASH_OPT_H &description_file_header(        "flash_opt.h",
                                         "NOR flash related options",
                                 "EMI auto generator". $EMIGEN_VERNO);
    print FLASH_OPT_H &flash_opt_h_file_body();
    close FLASH_OPT_H or die "fail to generate $FLASH_OPT_H\n$!\n";

    print "\n$FLASH_OPT_H is generated\n";
}

#****************************************************************************
# generate custom_EMI.c
#****************************************************************************
if ($is_existed_c == 0)
{
    open (CUSTOM_EMI_C, ">$CUSTOM_EMI_C") or die "cannot open $CUSTOM_EMI_C\n";

    print CUSTOM_EMI_C &copyright_file_header();
    print CUSTOM_EMI_C &description_file_header(                      "custom_EMI.c",
          "This Module defines the EMI (external memory interface) related setting.",
                                                 "EMI auto generator". $EMIGEN_VERNO);
    print CUSTOM_EMI_C &custom_EMI_c_file_body();
    close CUSTOM_EMI_C or die "fail to generate $CUSTOM_EMI_C\n$!\n";

    print "\n$CUSTOM_EMI_C is generated\n";
} # if ($is_existed_c == 0)

#****************************************************************************
# generate custom_EMI.h
#****************************************************************************
if ($is_existed_h == 0)
{
    open (CUSTOM_EMI_H, ">$CUSTOM_EMI_H") or die "cannot open $CUSTOM_EMI_H\n";

    print CUSTOM_EMI_H &copyright_file_header();
    print CUSTOM_EMI_H &description_file_header(                      "custom_EMI.h",
          "This Module defines the EMI (external memory interface) related setting.",
                                                 "EMI auto generator". $EMIGEN_VERNO);
    print CUSTOM_EMI_H &custom_EMI_h_file_body();
    close CUSTOM_EMI_H or die "fail to generate $CUSTOM_EMI_H\n$!\n";

    print "\n$CUSTOM_EMI_H is generated\n";
}

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
# subroutine:  custom_setadvemi_for_ram_async_access
# return:      template of "FUNCTION custom_setAdvEMI()" for
#              RAM_ACCESS_TYPE==ASYNC_ACCESS
#****************************************************************************
sub custom_setadvemi_for_ram_async_access
{
    my @addr = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{ADDRESS};
    my @data = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{DATA};
    my $sub_content;

    for (0..$#addr)
    {
        my $idx = $_ + 1;
        $sub_content .=  "      *(volatile kal_uint16 *)(RAMBaseAddr+(kal_uint32)(DEV_CONFIG_RAM_PMODE_ADDR_$idx)) = DEV_CONFIG_RAM_PMODE_DATA_$idx;\n";
    }

    ###
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on RAM (SRAM / PSRAM / Cellular RAM) */
   {
      kal_uint32 RAMBaseAddr;
      kal_uint32 delayRAM;

      RAMBaseAddr = (INT_RetrieveFlashBaseAddr() ^ 0x08000000);

$sub_content

      for (delayRAM = 0; delayRAM < 200; delayRAM++);

      *(EMI_CONB) = EMI_RAM_PAGE_MODE;

      for (delayRAM = 0; delayRAM < 200; delayRAM++);

      status |= 8;
   }

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_flash_async_access
# return:      template of "FUNCTION custom_setAdvEMI()" for
#              FLASH_ACCESS_TYPE==ASYNC_ACCESS
#****************************************************************************
sub custom_setadvemi_for_flash_async_access
{
    my @addr = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{ADDRESS};
    my @data = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{DATA};
    my $sub_content;

    for (0..$#addr)
    {
        my $idx    = $_ + 1;
        $sub_content .=  "      *(volatile kal_uint16 *)(NORBaseAddr+(kal_uint32)(DEV_CONFIG_FLASH_PMODE_ADDR_$idx)) = DEV_CONFIG_FLASH_PMODE_DATA_$idx;\n";
    }

    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on NOR-flash */
   {
      kal_uint32 NORBaseAddr;
      kal_uint32 delayNOR;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();

$sub_content

      for (delayNOR = 0; delayNOR < 200; delayNOR++);

      *(EMI_CONA) = EMI_FLASH_PAGE_MODE;

      for (delayNOR = 0; delayNOR < 200; delayNOR++);

      status |= 4;
   }

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_2829_sync_access
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part 1
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access
{
    my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{ADDRESS};
    my @flash_data = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{DATA};
    my @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{ADDRESS};
    my @ram_data   = split /\s/, $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{DATA};
    my $sub_content1;
    my $sub_content2;
    ###

    for (0..$#flash_addr)
    {
        my $idx = $_ + 1;
        $sub_content1 .=  "      *(volatile kal_uint16 *)(NORBaseAddr+(kal_uint32)(DEV_CONFIG_FLASH_BMODE_ADDR_$idx)) = DEV_CONFIG_FLASH_BMODE_DATA_$idx;\n";
    }

    for (0..$#ram_addr)
    {
        my $idx = $_ + 1;
        $sub_content2 .=  "      *(volatile kal_uint16 *)(RAMBaseAddr+(kal_uint32)(DEV_CONFIG_RAM_BMODE_ADDR_$idx)) = DEV_CONFIG_RAM_BMODE_DATA_$idx;\n";
    }

    ###
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on NOR-flash */
   {
      kal_uint32 NORBaseAddr, RAMBaseAddr;
      kal_uint32 delay;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();
      RAMBaseAddr = NORBaseAddr ^ 0x08000000;

$sub_content1
      for (delay = 0; delay < 200; delay++);

$sub_content2
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
# subroutine:  custom_setadvemi_for_2829_sync_access_104_sibley_nor_lpsdram_part
# return:      template of "FUNCTION custom_setAdvEMI()" for 28/29 SYNC_ACCESS
#              part for 104MHz INTEL SIBLEY
#****************************************************************************
sub custom_setadvemi_for_2829_sync_access_104_sibley_nor_lpsdram_part
{
    my $template = <<"__TEMPLATE";
   /* Turn on advanced mode on NOR-flash */
   {
      kal_uint32 NORBaseAddr;
      kal_uint32 delay;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();

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

      for (delay = 0; delay < 0xff; delay++);

      status |= 0x10;
   }
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  custom_setadvemi_for_flash_async_access
# return:      template of "FUNCTION custom_setAdvEMI()" for
#              FLASH_ACCESS_TYPE==ASYNC_ACCESS
#****************************************************************************
sub custom_setadvemi_for_last_bank_is_c
{
    my @c_addr = split /\s/, $part_info->{CS}->{0}->{LAST_BANK}->{C_ADDR};
    my @c_data = split /\s/, $part_info->{CS}->{0}->{LAST_BANK}->{C_DATA};
    my $sub_content_block;

    for (0..$#c_addr)
    {
        my $idx = $_ + 1;
        $sub_content_block .=  "      *(volatile kal_uint16 *)(NORBaseAddr+(kal_uint32)(DEV_CONFIG_BANK_ADDR_$idx)) = DEV_CONFIG_BANK_DATA_$idx;\n";
    }

    my $template = <<"__TEMPLATE";
   /* Partition Configuration */
   {
      kal_uint32 NORBaseAddr;
      kal_uint32 delay;

      NORBaseAddr = INT_RetrieveFlashBaseAddr();
$sub_content_block
      for (delay = 0; delay < 200; delay++);

      status = 1;
   }

__TEMPLATE
    return $template;
}


#****************************************************************************
# subroutine:  region_info
# return:      template of part "configure flash memory for FAT"
#****************************************************************************
sub region_info
{
    my @regions = @_;
    my $region_info_lines;
    
    for (0..$#regions)
    {
        if ($regions[$_] =~ /\{(0x\w+),\s*(\d+)\}/) # match {0x20000, 7}
        {
            $region_info_lines .=  "   $regions[$_]\n";
        }
    }
    chomp $region_info_lines;

    ###
    my $template = <<"__TEMPLATE";
#if defined(_LOW_COST_SINGLE_BANK_FLASH_) || defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define FLASH_REGIONINFO_VAR_MODIFIER  static
#else /* _LOW_COST_SINGLE_BANK_FLASH_ || __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#define FLASH_REGIONINFO_VAR_MODIFIER  static const
#endif /* _LOW_COST_SINGLE_BANK_FLASH_ || __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo RegionInfo[] =
{
$region_info_lines
   EndRegionInfo /* Don't modify this line */
};

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  additional_information
# return:      template of part "additional information"
#****************************************************************************
sub additional_information
{
    my $content;
    if ($part_info->{CS}->{0}->{LAST_BANK}->{F_OR_C} =~ /C/i)
    {
        my @c_addr = split /\s/, $part_info->{CS}->{0}->{LAST_BANK}->{C_ADDR};
        my @c_data = split /\s/, $part_info->{CS}->{0}->{LAST_BANK}->{C_DATA};

        for (0..$#c_addr)
        {
            my $idx = $_ + 1;
            $content .=  "#define DEV_CONFIG_BANK_ADDR_$idx        $c_addr[$_]\n";
            $content .=  "#define DEV_CONFIG_BANK_DATA_$idx        $c_data[$_]\n";
        }
    }
    ###
    if ($fast_mem_prj_type == 104)
    {
        my @addr = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            $content .=  "#define DEV_CONFIG_FLASH_BMODE_ADDR_$idx        $addr[$_]\n";
            $content .=  "#define DEV_CONFIG_FLASH_BMODE_DATA_$idx        $data[$_]\n";
        }

        my @addr = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            $content .=  "#define DEV_CONFIG_RAM_BMODE_ADDR_$idx        $addr[$_]\n";
            $content .=  "#define DEV_CONFIG_RAM_BMODE_DATA_$idx        $data[$_]\n";
        }

        my $emi_setting = $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{MT6229};
        $content .=  "#define EMI_FLASH_BURST_MODE        $emi_setting\n" if defined $emi_setting;

        $emi_setting = $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{MT6229};
        $content .=  "#define EMI_RAM_BURST_MODE        $emi_setting\n" if defined $emi_setting;

        # use #if ... #elif for 6228,6225/6229,6230 6268T differentiation
        $content .=  "#if defined(MT6228)\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_DRIVING"}->{MT6228};
        if ($driving_setting[0] ne 'x')
        {
            $content .=  "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
#           die "no 2nd driving setting for CS=0, 104Mhz, MT6228" if (!defined $driving_setting[1]); MT6228 need only 1st and 3rd driving settings
#           $content .=  "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 104Mhz, MT6228" if (!defined $driving_setting[1]);
            $content .=  "#define EMI_DRV2_BURST_MODE        $driving_setting[1]\n";
        }
        $content .=  "#elif defined(MT6225)\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_DRIVING"}->{MT6225};
        if ($driving_setting[0] ne 'x')
        {
            $content .=  "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
#           die "no 2nd driving setting for CS=0, 104Mhz, MT6228" if (!defined $driving_setting[1]); MT6228 need only 1st and 3rd driving settings
#           $content .=  "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 104Mhz, MT6225" if (!defined $driving_setting[1]);
            $content .=  "#define EMI_DRV2_BURST_MODE        $driving_setting[1]\n";
        }
        $content .=  "#elif ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_DRIVING"}->{MT6229};
        if ($driving_setting[0] ne 'x')
        {
            $content .=  "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
            die "no 2nd driving setting for CS=0, 104Mhz, MT6229, MT6230, MT6268T" if (!defined $driving_setting[1]);
            $content .=  "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 104Mhz, MT6229, MT6230, MT6268T" if (!defined $driving_setting[2]);
            $content .=  "#define EMI_DRV2_BURST_MODE        $driving_setting[2]\n";
        }
        $content .=  "#endif\n";

    } # if ($fast_mem_prj_type == 104)
    elsif ($fast_mem_prj_type == 52)
    {
        my @addr = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            $content .=  "#define DEV_CONFIG_FLASH_BMODE_ADDR_$idx        $addr[$_]\n";
            $content .=  "#define DEV_CONFIG_FLASH_BMODE_DATA_$idx        $data[$_]\n";
        }

        my @addr = split /\s/, $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{ADDRESS};
        my @data = split /\s/, $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{DATA};

        for (0..$#addr)
        {
            my $idx = $_ + 1;
            $content .=  "#define DEV_CONFIG_RAM_BMODE_ADDR_$idx        $addr[$_]\n";
            $content .=  "#define DEV_CONFIG_RAM_BMODE_DATA_$idx        $data[$_]\n";
        }

        my $emi_setting = $part_info->{CS}->{0}->{"52MHZ_SYNC_EMI"}->{MT6229};
        $content .=  "#define EMI_FLASH_BURST_MODE        $emi_setting\n" if defined $emi_setting;

        $emi_setting = $part_info->{CS}->{1}->{"52MHZ_SYNC_EMI"}->{MT6229};
        $content .=  "#define EMI_RAM_BURST_MODE        $emi_setting\n" if defined $emi_setting;

        # use #if ... #elif for 6228,6225/6229,6230, 6268T differentiation
        $content .=  "#if defined(MT6228)\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_DRIVING"}->{MT6228};
        if ($driving_setting[0] ne 'x')
        {
            $content .=  "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
#           die "no 2nd driving setting for CS=0, 52Mhz, MT6228" if (!defined $driving_setting[1]);
#                                                    MT6228 need only 1st and 3rd driving settings
#           $content .=  "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 52Mhz, MT6228" if (!defined $driving_setting[1]);
            $content .=  "#define EMI_DRV2_BURST_MODE        $driving_setting[1]\n";
        }
        $content .=  "#elif defined(MT6225)\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_DRIVING"}->{MT6225};
        if ($driving_setting[0] ne 'x')
        {
            $content .=  "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
#           die "no 2nd driving setting for CS=0, 52Mhz, MT6225" if (!defined $driving_setting[1]);
#                                                    MT6225 need only 1st and 3rd driving settings
#           $content .=  "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 52Mhz, MT6225" if (!defined $driving_setting[1]);
            $content .=  "#define EMI_DRV2_BURST_MODE        $driving_setting[1]\n";
        }
        $content .=  "#elif ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )\n";
        my @driving_setting = split /\s/, $part_info->{CS}->{0}->{"52MHZ_SYNC_DRIVING"}->{MT6229};
        if ($driving_setting[0] ne 'x')
        {
            $content .=  "#define EMI_DRV0_BURST_MODE        $driving_setting[0]\n";
            die "no 2nd driving setting for CS=0, 52Mhz, MT6229, MT6230, MT6268T" if (!defined $driving_setting[1]);
            $content .=  "#define EMI_DRV1_BURST_MODE        $driving_setting[1]\n";
            die "no 3rd driving setting for CS=0, 52Mhz, MT6229, MT6230, MT6268T" if (!defined $driving_setting[2]);
            $content .=  "#define EMI_DRV2_BURST_MODE        $driving_setting[2]\n";
        }
        # XXX Here comes MT6223 and MT6227D 
        $content .=  "#endif\n";

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
            $content .=  "#define DEV_CONFIG_FLASH_PMODE_ADDR_$idx        $addr[$_]\n";
            $content .=  "#define DEV_CONFIG_FLASH_PMODE_DATA_$idx        $data[$_]\n";
        }

        $content .=  "#if ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6217};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        $content .=  "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

        $content .=  "#elif ( defined(MT6226) || defined(MT6227) || defined(MT6226M) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6227};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        $content .=  "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

        $content .=  "#elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        $content .=  "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

        $content .=  "#elif ( defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6223};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        $content .=  "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

        $content .=  "#else /* defined(MT6205B) */\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6205B};
        my $emi_setting     = $emi_settings[0] if defined $emi_settings[0]; # get 1st item
        $content .=  "#define EMI_FLASH_PAGE_MODE        $emi_setting\n";

        $content .=  "#endif\n";

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
            $content .=  "#define DEV_CONFIG_RAM_PMODE_ADDR_$idx        $addr[$_]\n";
            $content .=  "#define DEV_CONFIG_RAM_PMODE_DATA_$idx        $data[$_]\n";
        }

        $content .=  "#if ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6217};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        $content .=  "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        $content .=  "#elif ( defined(MT6226) || defined(MT6227) || defined(MT6226M) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6227};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        $content .=  "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        $content .=  "#elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6229};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        $content .=  "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        $content .=  "#elif ( defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) )\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6223};
        my $emi_setting     = $emi_settings[1] if defined $emi_settings[1]; # get 2nd item
        $content .=  "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        $content .=  "#else\n";
        my @emi_settings     = split /\s/, $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6205B};
        my $emi_setting     = $emi_settings[0] if defined $emi_settings[0]; # get 1st item
        $content .=  "#define EMI_RAM_PAGE_MODE        $emi_setting\n";

        $content .=  "#endif\n";

    } # if ( ($RAM_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )

    return $content;
}

#****************************************************************************
# subroutine:  emi_setting_on_chip_select
# return:      EMI setting section
#****************************************************************************
sub emi_setting_on_chip_select
{
    my $setting_func = sub { 
       my ($platform) = @_;
       my $content;
       for (0..3)
       {
           my $emi_setting_value = '0';
           if (exists $part_info->{CS}->{$_}->{ASYNC_EMI}->{$platform})
           {
               $emi_setting_value = $part_info->{CS}->{$_}->{ASYNC_EMI}->{$platform};
               $emi_setting_value =~ s/(0x\w+)\W.*/$1/;
           }
           $content .=  (($_<=2) ? "   $emi_setting_value,\n" : "   $emi_setting_value\n");
       }
       return $content;
    };
    ###

    my $emi_setting_6205b = &$setting_func('MT6205B');
    my $emi_setting_6217  = &$setting_func('MT6217' );
    my $emi_setting_6227  = &$setting_func('MT6227' );
    my $emi_setting_6229  = &$setting_func('MT6229' );
    my $emi_setting_6223  = &$setting_func('MT6223' );

    chomp $emi_setting_6205b;
    chomp $emi_setting_6217 ;
    chomp $emi_setting_6227 ;
    chomp $emi_setting_6229 ;
    chomp $emi_setting_6223 ;
    ###
    my $template = <<"__TEMPLATE";
#if ( defined(MT6205B) || defined(MT6208) )

const kal_uint16   EMI_SettingOnCS[4] =
{
$emi_setting_6205b
};

#elif ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )

const kal_uint32   EMI_SettingOnCS[4] =
{
$emi_setting_6217
};

#elif ( defined(MT6227) || defined(MT6226) || defined(MT6226M) )

const kal_uint32   EMI_SettingOnCS[4] =
{
$emi_setting_6227
};

#elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )

const kal_uint32   EMI_SettingOnCS[4] =
{
$emi_setting_6229
};

#elif ( defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) )

const kal_uint32   EMI_SettingOnCS[4] =
{
$emi_setting_6223
};

#endif

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  driving_and_cache_prefetch_setting
# return:      driving and cache section
#****************************************************************************
sub driving_and_cache_prefetch_setting
{
    my $driving_setting_6205b = $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6205B};
    my $driving_setting_6217  = $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6217};
    my $driving_setting_6227  = $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6227};
    my $driving_setting_6223  = $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6223};

    ###
    my @driving_list_6228 = split /\s/, $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6228};
    my @driving_list_6225 = split /\s/, $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6225};
    my @driving_list_6229 = split /\s/, $part_info->{CS}->{0}->{ASYNC_DRIVING}->{MT6229};

    my $driving_func = sub { 
       my @input = @_;
       my $content;
       for (0..$#input)
       {
          $content .=  "#define EMI_GENERAL_CONTROL_$_        $input[$_]\n";
       }
       return $content;
    };

    my $driving_setting_6228 = &$driving_func(@driving_list_6228);
    my $driving_setting_6225 = &$driving_func(@driving_list_6225);
    my $driving_setting_6229 = &$driving_func(@driving_list_6229);

    chomp $driving_setting_6228;
    chomp $driving_setting_6225;
    chomp $driving_setting_6229;

    ###

    my $default_value  = 0x03030103;
    if ($part_info->{CS}->{0}->{PAGE_SIZE} == 16)
    {
        $default_value = $default_value | 0x4;
    }
    elsif ($part_info->{CS}->{1}->{PAGE_SIZE} == 16)
    {
        $default_value = $default_value | 0x40000;
    }
    my $cache_prefetch = sprintf("0x%08X", $default_value);

    ###
    
    my $template = <<"__TEMPLATE";
#if ( defined(MT6205B) || defined(MT6208) )
#define EMI_GENERAL_CONTROL          $driving_setting_6205b

#elif defined(MT6228)
$driving_setting_6228

#elif defined(MT6225)
$driving_setting_6225

#elif ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
$driving_setting_6229

#elif ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )
#define EMI_GENERAL_CONTROL          $driving_setting_6217
#define EMI_CACHE_PREFETCH           $cache_prefetch

#elif ( defined(MT6223)  || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) )
#define EMI_GENERAL_CONTROL          $driving_setting_6223
#define EMI_CACHE_PREFETCH           $cache_prefetch

#else /* defined(MT6227) || defined(MT6226) || defined(MT6226M) */
#define EMI_GENERAL_CONTROL          $driving_setting_6227
#define EMI_CACHE_PREFETCH           $cache_prefetch

#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  mcp_admux
# return:      template of part "RAM size in Bytes"
#****************************************************************************
sub mcp_admux
{
    my $template = <<"__TEMPLATE";
/*
 ****************************************************************************
 Specify if ADMUX device is applied
 If it is supported, define ADMUX_MCP
 ****************************************************************************
*/
#define ADMUX_MCP
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  emi_csconfiguration
# return:      template of part EMI_CSConfiguration
#****************************************************************************
sub emi_csconfiguration
{
    my $content;
    for (0..3)
    {
        if (!defined $part_info->{CS}->{$_}->{SERIES})
        {
            $content .=  (($_==3) ? "   UNUSED\n" : "   UNUSED,\n");
        }
        elsif ($part_info->{CS}->{$_}->{SERIES} ne '*')
        {
            $content .=  "   NOR_FLASH,\n";
        }
        elsif ($part_info->{CS}->{$_}->{SERIES} eq '*')
        {
            $content .=  "   RAM,\n";
        }
    }
    ###
    my $template = <<"__TEMPLATE";
const ExtMemoryType_T   EMI_CSConfiguration[4] =
{
$content
};

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  DeviceListParser_NOR_RAM_MCP
# return:      None
#****************************************************************************
sub DeviceListParser_NOR_RAM_MCP
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
    #                                                       "MT6229"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6223"    => $setting,
    #                                                       "MT6223P"   => $setting,
    #                                                       "MT6227D"   => $setting,
    #                                                       "MT6226D"   => $setting,
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
    #                                                       "MT6229"    => $setting,
    #                                                       "MT6223"    => $setting,
    #                                                       "MT6223P"   => $setting,
    #                                                       "MT6227D"   => $setting,
    #                                                       "MT6226D"   => $setting, },
    #                           52MHZ_SYNC_EMI      => {    "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting,
    #                                                       "MT6223"    => $setting,
    #                                                       "MT6223P"   => $setting,
    #                                                       "MT6227D"   => $setting,
    #                                                       "MT6226D"   => $setting,
    #                                                       ADDRESS     => $address,
    #                                                       DATA        => $data, },
    #                           52MHZ_SYNC_DRIVING  => {    "MT6228"    => $setting,
    #                                                       "MT6225"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting,
    #                                                       "MT6223"    => $setting,
    #                                                       "MT6223P"   => $setting,
    #                                                       "MT6227D"   => $setting,
    #                                                       "MT6226D"   => $setting, },
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
    #                                                       "MT6223"    => $setting,
    #                                                       "MT6223P"   => $setting,
    #                                                       "MT6227D"   => $setting,
    #                                                       "MT6226D"   => $setting,
    #                                                       ADDRESS     => $address,
    #                                                       DATA        => $data, },
    #                           104MHZ_SYNC_DRIVING => {    "MT6225"    => $setting,
    #                                                       "MT6228"    => $setting,
    #                                                       "MT6230"    => $setting,
    #                                                       "MT6268T"   => $setting,
    #                                                       "MT6229"    => $setting, },
    #                         },
    #                  "1" => {...},
    #                },
    # };
    #

    foreach (@all_rows)
    {
        my $cs_value = $Sheet->Cells($_, $COLUMN_CS)->{'Value'};
        die "Row number NOT matched![$_][$part_info->{CS}->{$cs_value}->{EXCEL_ROW}]\n" unless ($part_info->{CS}->{$cs_value}->{EXCEL_ROW});

        $part_info->{CS}->{$cs_value}->{VENDOR}              = $Sheet->Cells($_, $COLUMN_VENDOR)->{'Value'};
        $part_info->{CS}->{$cs_value}->{ADMUX}               = $Sheet->Cells($_, $COLUMN_ADMUX)->{'Value'};
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
}

#****************************************************************************
# subroutine:  DeviceListParser_LPSDRAM
# return:      None
#****************************************************************************
sub DeviceListParser_LPSDRAM
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
    #                           EMI_13MHZ_GENERAL_CONTROL3_VAL  => $setting, },
    #                },
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
}

#****************************************************************************
# subroutine:  DeviceListParser_NOR_LPSDRAM_MCP
# return:      None
#****************************************************************************
sub DeviceListParser_NOR_LPSDRAM_MCP
{
    my $NOR_CHIP_SELECT;

    $MEMORY_DEVICE_TYPE = 'NOR_LPSDRAM_MCP';

    $MEMORY_DEVICE_TYPE = 'NOR_RAM_MCP';
    &DeviceListParser_NOR_RAM_MCP();

    # search NOR Chip Select and search LPSDRAM Chip Select
    undef $LPSDRAM_CHIP_SELECT;
    for my $scan_idx (0..3)
    {
       if (defined $part_info->{CS}->{$scan_idx}->{EXCEL_ROW} and not defined $NOR_CHIP_SELECT)
       {
          $NOR_CHIP_SELECT = $scan_idx;
       }
       elsif (not defined $LPSDRAM_CHIP_SELECT and not defined $part_info->{CS}->{$scan_idx}->{EXCEL_ROW})
       {
          $LPSDRAM_CHIP_SELECT = $scan_idx;
       }
    }
    die "NOR_LPSDRAM_MCP cannot find NOR flash part no in NOR_RAM_MCP sheet" unless defined $NOR_CHIP_SELECT;
    die "cannot locate LPSRAM chip select" unless defined $LPSDRAM_CHIP_SELECT;

    # Make the device part no. search available on LPSDRAM sheet
    $eos_flag           = 7;
    $MEMORY_DEVICE_TYPE = 'LPSDRAM';
    &DeviceListParser_LPSDRAM();

    # Restore the device type setting
    $MEMORY_DEVICE_TYPE = 'NOR_LPSDRAM_MCP';
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body specific for INTELSIBLEY
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_INTELSIBLEY
{
    my $C104M_Setting;
        my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
        $C104M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        $C104M_Setting .=  "\n      /* set EMI B */\n";

        $emi_setting_6229    = $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6229};
        $C104M_Setting .=  "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

        my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
        my @flash_data = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{DATA};

        $C104M_Setting .=  "\n      /*\n       * Configure flash in burst mode.\n       */\n";

        for (0..$#flash_addr)
        {
            $C104M_Setting .=  "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
            $C104M_Setting .=  "      *ptr16 = $flash_data[$_];\n";
        }

        my @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
        my @ram_data   = split /\s/, $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{DATA};

        $C104M_Setting .=  "\n      /*\n       * Configure PSRAM in burst mode.\n       */\n";

        $C104M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[0]);\n";
        $C104M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[1]);\n";
        $C104M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[2]) = $ram_data[2];\n";
        $C104M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[3]) = $ram_data[3];\n";
        $C104M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[4]);\n";
        $C104M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[5]);\n";
        $C104M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[6]) = $ram_data[6];\n";
        $C104M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[7]) = $ram_data[7];\n";

        $C104M_Setting .=  "\n      /* set EMI A */\n";

        $emi_setting_6229 = $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{MT6229};
        $C104M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        $C104M_Setting .=  "\n      /* delay for a while */\n      for (delay = 0; delay < 2; delay++) {\n\n         /* NOP */\n      }\n      /* set EMI B */\n";

        $emi_setting_6229 = $part_info->{CS}->{1}->{"104MHZ_SYNC_EMI"}->{MT6229};
        $C104M_Setting .=  "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

    ###
    my $C26M_Setting;

        my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
        $C26M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        $C26M_Setting .=  "\n      /* set EMI B */\n";

        $emi_setting_6229    = $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6229};
        $C26M_Setting .=  "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

        my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{ADDRESS};
        my @flash_data = split /\s/, $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{DATA};

        $C26M_Setting .=  "\n      /*\n       * Configure flash in burst mode.\n       */\n";

        for (0..$#flash_addr)
        {
            $flash_addr[$_] = '/*FIXME*/value_NOT_defined_in_MemoryDeviceList_xls' if ($flash_addr[$_] eq 'x'); # if 'x' is defined in Excel, a compile error occurred
            $C26M_Setting .=  "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
            $C26M_Setting .=  "      *ptr16 = $flash_data[$_];\n";
        }

        my @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"26MHZ_SYNC_EMI"}->{ADDRESS};
        my @ram_data   = split /\s/, $part_info->{CS}->{1}->{"26MHZ_SYNC_EMI"}->{DATA};

        $C26M_Setting .=  "\n      /*\n       * Configure PSRAM in burst mode.\n       */\n";

        $C26M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[0]);\n";
        $C26M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[1]);\n";
        $C26M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[2]) = $ram_data[2];\n";
        $C26M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[3]) = $ram_data[3];\n";
        $C26M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[4]);\n";
        $C26M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[5]);\n";
        $C26M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[6]) = $ram_data[6];\n";
        $C26M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[7]) = $ram_data[7];\n";

        $C26M_Setting .=  "\n      /* set EMI A */\n";

        $emi_setting_6229 = $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{MT6229};
        $C26M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        $C26M_Setting .=  "\n      /* delay for a while */\n      for (delay = 0; delay < 2; delay++) {\n\n         /* NOP */\n      }\n      /* set EMI B */\n";

        $emi_setting_6229 = $part_info->{CS}->{1}->{"26MHZ_SYNC_EMI"}->{MT6229};
        $C26M_Setting .=  "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

    ###
    my $C13M_Setting;

        my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
        $C13M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        $C13M_Setting .=  "\n      /* set EMI B */\n";

        $emi_setting_6229    = $part_info->{CS}->{1}->{ASYNC_EMI}->{MT6229};
        $C13M_Setting .=  "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

        my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{ADDRESS};
        my @flash_data = split /\s/, $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{DATA};

        $C13M_Setting .=  "\n      /*\n       * Configure flash in burst mode.\n       */\n";

        for (0..$#flash_addr)
        {
            $flash_addr[$_] = '/*FIXME*/value_NOT_defined_in_MemoryDeviceList_xls' if ($flash_addr[$_] eq 'x'); # if 'x' is defined in Excel, a compile error occurred
            $C13M_Setting .=  "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
            $C13M_Setting .=  "      *ptr16 = $flash_data[$_];\n";
        }

        my @ram_addr   = split /\s/, $part_info->{CS}->{1}->{"13MHZ_SYNC_EMI"}->{ADDRESS};
        my @ram_data   = split /\s/, $part_info->{CS}->{1}->{"13MHZ_SYNC_EMI"}->{DATA};

        $C13M_Setting .=  "\n      /*\n       * Configure PSRAM in burst mode.\n       */\n";

        $C13M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[0]);\n";
        $C13M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[1]);\n";
        $C13M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[2]) = $ram_data[2];\n";
        $C13M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[3]) = $ram_data[3];\n";
        $C13M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[4]);\n";
        $C13M_Setting .=  "      data = *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[5]);\n";
        $C13M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[6]) = $ram_data[6];\n";
        $C13M_Setting .=  "      *(volatile unsigned short *)(RAM_BASE_ADDR | 0x04000000 | $ram_addr[7]) = $ram_data[7];\n";

        $C13M_Setting .=  "\n      /* set EMI A */\n";

        $emi_setting_6229 = $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{MT6229};
        $C13M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        $C13M_Setting .=  "\n      /* delay for a while */\n      for (delay = 0; delay < 2; delay++) {\n\n         /* NOP */\n      }\n      /* set EMI B */\n";

        $emi_setting_6229 = $part_info->{CS}->{1}->{"13MHZ_SYNC_EMI"}->{MT6229};
        $C13M_Setting .=  "      *(volatile kal_uint32 *)0x80010008 = $emi_setting_6229;\n";

#****************************************************************************
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
$C104M_Setting

      return 0;
   }
#endif /* MT6228 || MT6225 || MT6229 || MT6230 || MT6268T */

#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
   if (clock == MCU_26MHZ)
   {
      /* set EMI A */
$C26M_Setting

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
$C13M_Setting

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
# subroutine:  generate custom_DynamicClockSwitch() function body specific for LPSDRAM
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_LPSDRAM
{
    my $ctrl_val;
    ###
    my $C104_Driving;
        $ctrl_val      = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL2_VAL"};
        $C104_Driving .=  "      *EMI_GENB = $ctrl_val;\n";
    
        $C104_Driving .=  "#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )\n";
    
        $ctrl_val      = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL3_VAL"};
        $C104_Driving .=  "      *EMI_GENC = $ctrl_val;\n";
    
        $C104_Driving .=  "#endif\n";
        $C104_Driving .=  "\n      /* turn on clock, set clock driving and delay */\n";
    
        $ctrl_val      = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL1_VAL"};
        $C104_Driving .=  "      *EMI_GENA = $ctrl_val;\n";
    ###
    my $C26_Driving;
        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL2_VAL"};
        $C26_Driving .=  "      *EMI_GENB = $ctrl_val;\n";

        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL3_VAL"};
        $C26_Driving .=  "      *EMI_GENC = $ctrl_val;\n";

        $C26_Driving .=  "\n      /* turn on clock, set clock driving and delay */\n";

        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL1_VAL"};
        $C26_Driving .=  "      *EMI_GENA = $ctrl_val;\n";

    ###
    my $C13_Driving;
        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"13MHZ_EMI_GENERAL_CONTROL2_VAL"};
        $C13_Driving .=  "      *EMI_GENB = $ctrl_val;\n";

        $C13_Driving .=  "\n      /* turn on clock, set clock driving and delay */\n";

        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"13MHZ_EMI_GENERAL_CONTROL1_VAL"};
        $C13_Driving .=  "      *EMI_GENA = $ctrl_val;\n";
    ###
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
$C104_Driving

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
$C26_Driving

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
$C13_Driving

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
# subroutine:  generate custom_DynamicClockSwitch() function body specific for INTELSIBLEY
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_NORLPSDRAM
{
    my $ctrl_val;
    ###
    my $C104_Driving;
        $ctrl_val      = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL2_VAL"};
        $C104_Driving .=  "      *EMI_GENB = $ctrl_val;\n";
    
        $C104_Driving .=  "#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )\n";
    
        $ctrl_val      = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL3_VAL"};
        $C104_Driving .=  "      *EMI_GENC = $ctrl_val;\n";
    
        $C104_Driving .=  "#endif\n";
        $C104_Driving .=  "\n      /* turn on clock, set clock driving and delay */\n";
    
        $ctrl_val      = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL1_VAL"};
        $C104_Driving .=  "      *EMI_GENA = $ctrl_val;\n";
    ###
    my $C26_Driving;
        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL2_VAL"};
        $C26_Driving .=  "      *EMI_GENB = $ctrl_val;\n";

        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL3_VAL"};
        $C26_Driving .=  "      *EMI_GENC = $ctrl_val;\n";

        $C26_Driving .=  "\n      /* turn on clock, set clock driving and delay */\n";

        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"26MHZ_EMI_GENERAL_CONTROL1_VAL"};
        $C26_Driving .=  "      *EMI_GENA = $ctrl_val;\n";

    ###
    my $C13_Driving;
        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"13MHZ_EMI_GENERAL_CONTROL2_VAL"};
        $C13_Driving .=  "      *EMI_GENB = $ctrl_val;\n";

        $C13_Driving .=  "\n      /* turn on clock, set clock driving and delay */\n";

        $ctrl_val     = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"13MHZ_EMI_GENERAL_CONTROL1_VAL"};
        $C13_Driving .=  "      *EMI_GENA = $ctrl_val;\n";
    ###
    my $C104M_Setting;
        my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
        $C104M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{ADDRESS};
        my @flash_data = split /\s/, $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{DATA};

        $C104M_Setting .=  "\n      /*\n       * Configure flash in burst mode.\n       */\n";

        for (0..$#flash_addr)
        {
            $C104M_Setting .=  "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
            $C104M_Setting .=  "      *ptr16 = $flash_data[$_];\n";
        }

        $C104M_Setting .=  "\n      /* set EMI A */\n";

        $emi_setting_6229 = $part_info->{CS}->{0}->{"104MHZ_SYNC_EMI"}->{MT6229};
        $C104M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

    ###
    my $C26M_Setting;

        my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
        $C26M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{ADDRESS};
        my @flash_data = split /\s/, $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{DATA};

        $C26M_Setting .=  "\n      /*\n       * Configure flash in burst mode.\n       */\n";

        for (0..$#flash_addr)
        {
            $flash_addr[$_] = '/*FIXME*/value_NOT_defined_in_MemoryDeviceList_xls' if ($flash_addr[$_] eq 'x'); # if 'x' is defined in Excel, a compile error occurred
            $C26M_Setting .=  "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
            $C26M_Setting .=  "      *ptr16 = $flash_data[$_];\n";
        }

        $C26M_Setting .=  "\n      /* set EMI A */\n";

        $emi_setting_6229 = $part_info->{CS}->{0}->{"26MHZ_SYNC_EMI"}->{MT6229};
        $C26M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

    ###
    my $C13M_Setting;

        my $emi_setting_6229 = $part_info->{CS}->{0}->{ASYNC_EMI}->{MT6229};
        $C13M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

        my @flash_addr = split /\s/, $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{ADDRESS};
        my @flash_data = split /\s/, $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{DATA};

        $C13M_Setting .=  "\n      /*\n       * Configure flash in burst mode.\n       */\n";

        for (0..$#flash_addr)
        {
            $flash_addr[$_] = '/*FIXME*/value_NOT_defined_in_MemoryDeviceList_xls' if ($flash_addr[$_] eq 'x'); # if 'x' is defined in Excel, a compile error occurred
            $C13M_Setting .=  "      ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | 0x04000000 | $flash_addr[$_]);\n";
            $C13M_Setting .=  "      *ptr16 = $flash_data[$_];\n";
        }

        $C13M_Setting .=  "\n      /* set EMI A */\n";

        $emi_setting_6229 = $part_info->{CS}->{0}->{"13MHZ_SYNC_EMI"}->{MT6229};
        $C13M_Setting .=  "      *(volatile kal_uint32 *)0x80010000 = $emi_setting_6229;\n";

    ###
    my $template = <<"__TEMPLATE";

   register kal_uint32 delay;
   volatile kal_uint16 *ptr16;


#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )
   if (clock == MCU_104MHZ)
   {
      /*------ MCU Clock --------*/
      /* switch clock to 104MHz */
      *MCUCLK_CON = 0x0703;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {

          /* NOP */
      }

      /*------ NOR Flash --------*/
      /* set EMI A */
$C104M_Setting

      /*------ DRAM -------------*/
      /* enter self-refresh mode */
      *EMI_CONJ |= 0x00000100;

      /* wait until the status is changed */
      while (!(*EMI_CONJ & 0x01000000))
      {
         /* NOP */
      }

      /* specify EMI setting */

      /* set Mobile RAM register*/
      *(volatile kal_uint32 *)0x80010050 = 0x60007EFD;

      /* set driving */
$C104_Driving

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

      /* delay for a while */
      for (delay = 0; delay < 2; delay++) {

         /* NOP */
      }

      return 0;
   }
#endif  /* MT6228 || MT6225 || MT6229 || MT6230 || MT6268T */

#if ( defined(MT6229) || defined(MT6230) || defined(MT6268T) )
   if (clock == MCU_26MHZ)
   {
      /*------ NOR Flash --------*/
      /* set EMI A */
$C26M_Setting

      /*------ DRAM -------------*/
      /* enter self-refresh mode */
      *EMI_CONJ |= 0x00000100;

      /* wait until the status is changed */
      while (!(*EMI_CONJ & 0x01000000))
      {
         /* NOP */
      }

      /* specify EMI setting */

      /* set Mobile RAM register*/
      *(volatile kal_uint32 *)0x80010050 = 0x480020C0;

      /* set driving */
$C26_Driving

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

      /*------ MCU Clock --------*/
      /* switch clock to 26MHz */
      *MCUCLK_CON = 0x0101;

      /* delay for a while */
      for (delay = 0; delay < 4; delay++) {

         /* NOP */
      }

      return 0;
   }
#endif  /* MT6229 , MT6230, MT6268T */

#if ( !defined(MT6229) && !defined(MT6230) && !defined(MT6268T) )
   if (clock == MCU_13MHZ)
   {
      /*------ NOR Flash --------*/
      /* set EMI A */
$C13M_Setting

      /*------ DRAM -------------*/
      /* enter self-refresh mode */
      *EMI_CONJ |= 0x00000100;

      /* wait until the status is changed */
      while (!(*EMI_CONJ & 0x01000000))
      {
         /* NOP */
      }

      /* specify EMI setting */

      /* set driving */
$C13_Driving

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

      /*------ MCU Clock --------*/
      /* switch clock to 13MHz */
      *MCUCLK_CON = 0x0000;

      /* delay for a while */
      for (delay = 0; delay < 2; delay++) {

         /* NOP */
      }

      return 0;
   }
#endif  /* !MT6229 && !MT6230 && !MT6268T */

   /* unsupported MCU clock */
   return -1;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_dynamicclockswitch_default
# return:      template for "FUNCTION custom_DynamicClockSwitch()"
#              for non-LPSDRAM and non Burst Mode NOR_RAM_MCP
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch_default
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

#if defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D)
#else /* MT6223 || MT6223P || MT6227D || defined(MT6226D) */
      /* set EMI A */
      *EMI_CONA = 0x4102;

      /* set EMI B */
      *EMI_CONB = 0x4102;
#endif /* MT6223 || MT6223P || MT6227D || defined(MT6226D) */

      return 0;
   } else {

      /* unsupported MCU clock */

      return -1;
   }

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  generate custom_DynamicClockSwitch() function body
# return:      the body strings
#****************************************************************************
sub FuncBody_custom_dynamicclockswitch
{
    if ( ($MEMORY_DEVICE_TYPE eq 'LPSDRAM') && ($LPSDRAM_CHIP_SELECT !~ /0xFF/i)
        && $BBtbl_LPSDRAM{$PLATFORM} )
    {
        return &FuncBody_custom_dynamicclockswitch_LPSDRAM();
    } # if ( ($MEMORY_DEVICE_TYPE eq 'LPSDRAM') && ($LPSDRAM_CHIP_SELECT !~ /0xFF/i)
    elsif ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
           && ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && ($RAM_ACCESS_TYPE eq 'SYNC_ACCESS') )
    {
        if ($part_info->{CS}->{0}->{SERIES} eq 'INTEL_SIBLEY')
        {
            return &FuncBody_custom_dynamicclockswitch_INTELSIBLEY();
        } # if ($part_info->{CS}->{0}->{SERIES} eq 'INTEL_SIBLEY')
        else
        {
            return &FuncBody_custom_dynamicclockswitch_default();
        }
    } # elsif ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') && ... )
    elsif (  ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP')
          && ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') )
    {
        return &FuncBody_custom_dynamicclockswitch_NORLPSDRAM();
    } # elsif ( $MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP' ) && ...
    else
    {
        return &FuncBody_custom_dynamicclockswitch_default();
    }
}

#****************************************************************************
# subroutine:  generate custom_switchclock.c content body
# return:      the body strings
#****************************************************************************
sub custom_switchclock_file_body
{
    my $custom_DynamicClockSwitch = &FuncBody_custom_dynamicclockswitch();
    ###
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
$custom_DynamicClockSwitch 
}

#pragma arm section code

#endif  /* DCM_ENABLE */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  flash_opt_h_file_body
# return:      flash opt header file 
#****************************************************************************
sub flash_opt_h_file_body
{
    my $current_nor_opt;
    if (  ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
       || ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP') )
    {
        if ($part_info->{CS}->{0}->{PBP}->{Y_OR_N} =~ /Y/i)
        {
            $current_nor_opt .= <<"__TEMPLATE__";
#define __PAGE_BUFFER_PROGRAM__
/* NOTE:
  BUFFER_PROGRAM_ITERATION_LENGTH specifies the maximum interrupt 
  disabled period while buffer program operation is applied
 */
__TEMPLATE__
    
            my $pbp_size      = $part_info->{CS}->{0}->{PBP}->{SIZE};

            my $template1     = <<"__TEMPLATE__";
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define BUFFER_PROGRAM_ITERATION_LENGTH  (8)
#else  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#define BUFFER_PROGRAM_ITERATION_LENGTH  ($pbp_size)
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
__TEMPLATE__

            my $template2     = <<"__TEMPLATE__";
#define BUFFER_PROGRAM_ITERATION_LENGTH  ($pbp_size)
__TEMPLATE__

            if ($pbp_size > 8)
            {   
               $current_nor_opt .= $template1;
            }
            else
            {   
               $current_nor_opt .= $template2;
            }
        }

        if ($part_info->{CS}->{0}->{SERIES} =~ /(\w*)/i)
        {
            $current_nor_opt .= "#define NOR_FLASH_TYPE_" . $1 . "\n";
        }

        if ($part_info->{CS}->{0}->{BANK} =~ /M/i)
        {
            $current_nor_opt .= "#define __MULTI_BANK_NOR_DEVICE__\n";
        }
        elsif ($part_info->{CS}->{0}->{BANK} =~ /S/i)
        {
            $current_nor_opt .= "#define __SINGLE_BANK_NOR_DEVICE__\n";
        }

        chomp $current_nor_opt if defined $current_nor_opt;
    }

    ###
    my $template = <<"__TEMPLATE";
$current_nor_opt

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

#ifdef NOR_FLASH_TYPE_SPANSION_GL_N
#define __AMD_SERIES_NOR__
#define __SPANSION_GL_N__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_NS_N
#define __AMD_SERIES_NOR__
#define __SPANSION_NS_N__
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
# subroutine:  FuncBody_Common_initialize_DRAM
# return:      template of "FUNCTION custom_setEMI()" for LPSDRAM
#****************************************************************************
sub FuncBody_Common_initialize_DRAM
{
    my $template = <<"__TEMPLATE";
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
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_setEMI_for_lpsdram
# return:      template of "FUNCTION custom_setEMI()" for LPSDRAM
#****************************************************************************
sub FuncBody_custom_setEMI_for_lpsdram
{
    my $initialize_dram = &FuncBody_Common_initialize_DRAM();
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

$initialize_dram
      return 1;
   }

   return -1;

__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_initDRAM_for_nor_lpsdram_mcp
# return:      template of "FUNCTION custom_setEMI()" for LPSDRAM
#****************************************************************************
sub FuncBody_custom_initDRAM_for_nor_lpsdram_mcp
{
    my $initialize_dram = &FuncBody_Common_initialize_DRAM();
    my $template = <<"__TEMPLATE";
   kal_uint32   DRAM_Enable = DRAM_CS;
   kal_uint32   delay;

   if ( (DRAM_Enable != 0xFF) && (DRAM_Enable == 1) )
   {
$initialize_dram
      return 1;
   }
__TEMPLATE

  return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_setEMI_for_nor_ram_mcp
# return:      template of "FUNCTION custom_setEMI()" for NOR_RAM_MCP
#****************************************************************************
sub FuncBody_custom_setEMI_for_nor_ram_mcp
{
    my $template = <<"__TEMPLATE";
#if (defined(MT6225) || defined(MT6227D) || defined(MT6226D) || defined(MT6223) || defined(MT6223P)) && !defined(ADMUX_MCP)
   *(volatile kal_uint32 *)(0x80010078) = 0;
#endif

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
# subroutine:  FuncBody_custom_setAdvEMI_for_nor_ram_mcp
# return:      template of "FUNCTION custom_setEMI()" for NOR_RAM_MCP
#****************************************************************************
sub FuncBody_custom_setAdvEMI_for_nor_ram_mcp
{
    my $template;

    if ($part_info->{CS}->{0}->{LAST_BANK}->{F_OR_C} =~ /C/i)
    {
        my $template .= &custom_setadvemi_for_last_bank_is_c();
    }

    if ( ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && ($RAM_ACCESS_TYPE eq 'SYNC_ACCESS')
    && $BBtbl_SYNC_ACCESS{$PLATFORM} )
    {
        if ($fast_mem_prj_type == 104) # $MCU_CLOCK eq 'MCU_104M'
        {
            if ($part_info->{CS}->{0}->{SERIES} eq 'INTEL_SIBLEY')
            {
                $template .=  &custom_setadvemi_for_2829_sync_access_104_sibley_part();
            }
            elsif ($part_info->{CS}->{0}->{SERIES} eq 'TOSHIBA_TY')
            {
                $template .=  &custom_setadvemi_for_2829_sync_access_104_ty_part();
            }
        }
        elsif ($fast_mem_prj_type == 52) # $MCU_CLOCK eq 'MCU_52M'
        {
            $template .=  &custom_setadvemi_for_2829_sync_access();

        } # elsif ($fast_mem_prj_type == 52) # $MCU_CLOCK eq 'MCU_52M'
    } # if ( ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && ($RAM_ACCESS_TYPE eq 'SYNC_ACCESS') ...

    my $addr = lc($part_info->{CS}->{0}->{ASYNC_EMI}->{ADDRESS});
    $addr =~ s/\s//g;
    if ( ($FLASH_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )
    {
        $template .=  &custom_setadvemi_for_flash_async_access();
    }

    $addr = lc($part_info->{CS}->{1}->{ASYNC_EMI}->{ADDRESS});
    $addr =~ s/\s//g;
    if ( ($RAM_ACCESS_TYPE eq 'ASYNC_ACCESS') && ( $addr ne 'x') )
    {
        $template .=  &custom_setadvemi_for_ram_async_access();
    }
    return $template;
}

#****************************************************************************
# subroutine:  FuncBody_custom_setAdvEMI_for_nor_lpsdram_mcp
# return:      template of "FUNCTION custom_setEMI()" for NOR_LPSDRAM_MCP
#****************************************************************************
sub FuncBody_custom_setAdvEMI_for_nor_lpsdram_mcp
{
    my $template;
    my $apology = "/* Not Supported by emiGen Yet ! */\n";

    if ( ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') && $BBtbl_SYNC_ACCESS{$PLATFORM} )
    {
        if ($fast_mem_prj_type == 104) # $MCU_CLOCK eq 'MCU_104M'
        {
            if ($part_info->{CS}->{0}->{SERIES} eq 'INTEL_SIBLEY')
            {
                $template .=  &custom_setadvemi_for_2829_sync_access_104_sibley_nor_lpsdram_part();
            }
            elsif ($part_info->{CS}->{0}->{SERIES} eq 'TOSHIBA_TY')
            {
                $template .= $apology;
            }
        }
        elsif ($fast_mem_prj_type == 52) # $MCU_CLOCK eq 'MCU_52M'
        {
            $template .= $apology;

        } # elsif ($fast_mem_prj_type == 52) # $MCU_CLOCK eq 'MCU_52M'
    } # if ( ($FLASH_ACCESS_TYPE eq 'SYNC_ACCESS') ...
    else
    {
        $template .= $apology;
    }

    return $template;
}

#****************************************************************************
# subroutine:  custom_EMI_c_file_body
# return:      flash opt ending
#****************************************************************************
sub custom_EMI_c_file_body
{
    my $custom_setEMI;

    if ( ($MEMORY_DEVICE_TYPE eq 'LPSDRAM') && ($LPSDRAM_CHIP_SELECT !~ /0xFF/i)
        && $BBtbl_LPSDRAM{$PLATFORM} )
    {
        $custom_setEMI = &FuncBody_custom_setEMI_for_lpsdram();
    }
    elsif ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') )
    {
        $custom_setEMI = &FuncBody_custom_setEMI_for_nor_ram_mcp();
    }
    elsif ( ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP') )
    {
        # equalience to NOR RAM MCP 
        $custom_setEMI = &FuncBody_custom_setEMI_for_nor_ram_mcp();
    }

    ###
    my $custom_setAdvEMI;

    if ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') )
    {
        $custom_setAdvEMI = &FuncBody_custom_setAdvEMI_for_nor_ram_mcp();
    } # if ( ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP') )
    elsif ( ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP') )
    {
        $custom_setAdvEMI = &FuncBody_custom_setAdvEMI_for_nor_lpsdram_mcp();
    } #elsif (($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP') )

    ###
    my $custom_initDRAM;

    if ( ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP') )
    {
        $custom_initDRAM = &FuncBody_custom_initDRAM_for_nor_lpsdram_mcp();
    } # if ( ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP') )

    ###
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
  /* __FUE__ compile option is used for FOTA build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   */

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
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NULL,
#else
   NOR_NonBlockWriteSectors,
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
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

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
//static kal_uint32 EraseQueue[TOTAL_BLOCKS];
static NOR_EraseInfo EraseBlockQueue[SNOR_ERASE_QUEUE_SIZE];
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

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
$custom_setEMI
}

/*************************************************************************
* FUNCTION
*  custom_InitDRAM()
*
* DESCRIPTION
*   This routine aims to set EMI and initialize LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_InitDRAM(void)
{
$custom_initDRAM
   return -1;
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
$custom_setAdvEMI
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
*  custom_ifLPSDRAM()
*
* DESCRIPTION
*  Query if the memory device is LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: The memory device is LPSDRAM
*  KAL_FALSE: The memory device is not LPSDRAM
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
custom_ifLPSDRAM(void)
{
#if defined(DRAM_CS) && defined(DRAM_SIZE)
   return KAL_TRUE;
#else
   return KAL_FALSE;
#endif      
}

/*************************************************************************
* FUNCTION
*  custom_get_NORFLASH_ROMSpace()
*
* DESCRIPTION
*  Query the of space configured for NORFLASH ROM
*
* PARAMETERS
*
* RETURNS
*  BASE ADDRESS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32
custom_get_NORFLASH_ROMSpace(void)
{
#if   defined(_NAND_FLASH_BOOTING_)
   return 0;
#elif defined(__FS_SYSDRV_ON_NAND__)
   return FLASH_BASE_ADDRESS + ALLOCATED_FAT_SPACE;
#else
   return FLASH_BASE_ADDRESS;
#endif
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
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
extern kal_uint32 NOR_Flash_Base_Address;
#if defined(MT6205B)
extern NOR_AddrLookup addr_lookup_tbl[][];
#endif
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#ifndef __NOR_FDM5__
void Initialize_FDD_tables(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )

   /* Initialize MTD data table */
   mtdflash.Signature = ~((kal_uint32)RegionInfo);

#ifdef __MTK_TARGET__
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_Flash_Base_Address =INT_RetrieveFlashBaseAddr();
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   mtdflash.BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + FLASH_BASE_ADDRESS);
#endif /* __MTK_TARGET__ */

   mtdflash.RegionInfo = (FlashRegionInfo *)RegionInfo;
#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
   mtdflash.BankInfo = (FlashBankInfo*)BankInfo;
#endif

   /* Initialize FDD data table */
   FlashDriveData.MTDDriver = &NORFlashMtd;
   FlashDriveData.MTDData = &mtdflash;
   FlashDriveData.AvailSectorsInBlock = AVAILSECTORS;
   FlashDriveData.ValidSectorsInBlock = VALIDSECTORS;
   FlashDriveData.SectorMap = (BYTE*)SectorMap;
   FlashDriveData.PartitionSectors = PARTITION_SECTORS;
   FlashDriveData.Buffer = FDMBuffer;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   FlashDriveData.queueSize = SNOR_ERASE_QUEUE_SIZE;
   FlashDriveData.EraseQueue = EraseBlockQueue;
   /* align page buffer size for iteration */
   #if defined(__PAGE_BUFFER_PROGRAM__)
   PAGE_BUFFER_SIZE = BUFFER_PROGRAM_ITERATION_LENGTH;
   #endif /* __PAGE_BUFFER_PROGRAM__ */
   /* initialize address look up table */
   #if defined(MT6205B)
   memset(addr_lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);
   #else /* MT6205B */
   memset(mtdflash.lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);
   #endif /* MT6205B */
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

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
# subroutine:  HeaderBody_for_nor_ram_mcp
# return:      content for custom_EMI.h 
#****************************************************************************
sub HeaderBody_for_nor_ram_mcp
{
    my $ram_size            = $part_info->{CS}->{1}->{SIZE};
    my $flash_size          = $part_info->{CS}->{0}->{SIZE};
    my @regions             = split /\n/, $part_info->{CS}->{0}->{LAST_BANK}->{REGION};
    my $sum_of_regions      = 0;
    my $blocks_of_regions   = 0;
    my $pbp_size            = ($part_info->{CS}->{0}->{PBP}->{Y_OR_N} =~ /Y/i)
                            ?  $part_info->{CS}->{0}->{PBP}->{SIZE} 
                            : 0;
    for (0..$#regions)
    {
        if ($regions[$_] =~ /\{(0x\w+),\s*(\d+)\}/) # match {0x20000, 7}
        {
            $blocks_of_regions += $2;
            $sum_of_regions += hex($1) * $2;
        }
    }
    die "TOTAL_BLOCKS > 127 , recommend enable FDM5.0 feature!\n" if ($blocks_of_regions > 127);
    my $base_addr_string    = sprintf("0x%08X", (($flash_size/8*1024*1024) - $sum_of_regions));
    my $fat_space_string    = sprintf("0x%08X",                              $sum_of_regions );

    ###
    my $sub_content_block1 = &emi_csconfiguration();
    my $sub_content_block2 = &driving_and_cache_prefetch_setting();
    my $sub_content_block3 = &emi_setting_on_chip_select();
    my $sub_content_block4 = &additional_information();
    my $sub_content_block5 = &region_info(@regions);

    ###
    my $optional_block_admux;
    if ($part_info->{CS}->{0}->{ADMUX} ne 'NO' or $part_info->{CS}->{1}->{ADMUX} ne 'NO')
    {
       $optional_block_admux = &mcp_admux();
    }

    ###
    my $template = <<"__TEMPLATE";
#include "flash_opt.h"

/*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/
$sub_content_block1
/*
 ****************************************************************************
 Specify RAM size in Bytes
 ****************************************************************************
*/
const kal_uint32  EMI_EXTSRAM_SIZE = (($ram_size)<<20)>> 3;
$optional_block_admux
/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/
$sub_content_block2
/*
 ****************************************************************************
 Specify the related EMI Setting
 ****************************************************************************
*/
$sub_content_block3
/*
 ****************************************************************************
 Specify additional information
 ****************************************************************************
*/
$sub_content_block4
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
#define FLASH_BASE_ADDRESS    $base_addr_string

/*******************************************************************************
   Step 2. Modify the value of ALLOCATED_FAT_SPACE, which is the total flash
           space allocated for FAT
 *******************************************************************************/
#define ALLOCATED_FAT_SPACE   $fat_space_string

/*******************************************************************************
   Step 3. Fill the flash region information table, a region is the memory space
           that contains continuous sectors of equal size. Each region element
           in the table is the format as below:
           {S_sector, N_sector},
               S_sector: the size of sector in the region
               N_sector: the number of sectors in the region
 *******************************************************************************/
$sub_content_block5

/*******************************************************************************
   Step 4. Modify the value of TOTAL_BLOCKS, which is the sum of the number of
           sectors in all regions.
           Note : The Maximum value of TOTAL_BLOCKS is (127).
 *******************************************************************************/
#define TOTAL_BLOCKS          $blocks_of_regions

/*******************************************************************************
   Step 5. Modify the value of page buffer size in WORD for page buffer program
 *******************************************************************************/
kal_uint32 PAGE_BUFFER_SIZE = $pbp_size;

/*******************************************************************************
   !CAUTION! !!Only for Enhanced Single Bank NOR Flash support!!
   Step 6. Modify the size of block erase queue, which is the number of reserved 
           blocks. It is recommended to be 10~20% of TOTAL_BLOCK value.
           If this value is less than 2, the FDM would use 1.5 internally.
 *******************************************************************************/
#define SNOR_ERASE_QUEUE_SIZE    5

/*******************************************************************************
   Step 7. This is for the Enhanced Signle Bank Support, when this feature is
           turned on and still use multi-bank device, this table should be filled
           with correct value.
 
           This Table define the flash bank information which starts from 
           FLASH_BASE_ADDRESS, please fill the flash bank information table, every
           entry defines the memory space that contains continuous banks of equal size.
           Each entry element in the table is the format as below:
           {S_Bank, N_Bank},
               S_Bank: the size of bank in the entry
               N_Bank: the number of banks in the entry
 *******************************************************************************/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)
FLASH_REGIONINFO_VAR_MODIFIER FlashBankInfo BankInfo[] =
{
   {x , x},
   EndBankInfo /* Don't modify this line */
};
#endif 


__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  HeaderBody_for_lpsdram
# return:      content for custom_EMI.h 
#****************************************************************************
sub HeaderBody_for_lpsdram
{
    my $density = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{DENSITY};
    my $ref_con = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EMI_DRAM_RERESH_CONTROL};
    my $dram_mode = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EMI_DRAM_MODE};
    my $dram_ext_mode = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EMI_DRAM_EXT_MODE};
    my $dram_ctrl = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{EMI_DRAM_CONTROL};
    my $gen_ctrla = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL1_VAL"};
    my $gen_ctrlb = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL2_VAL"};
    my $gen_ctrlc = $part_info->{CS}->{$LPSDRAM_CHIP_SELECT}->{"104MHZ_EMI_GENERAL_CONTROL3_VAL"};

    ###
    my $sub_content_block1;
    if (($PLATFORM eq 'MT6229') || ($PLATFORM eq 'MT6230'))
    {
       $sub_content_block1 = <<"__TEMPLATE";
/* EMI_GENC value */
#define EMI_GENERAL_CONTROL3_VAL    $gen_ctrlc
__TEMPLATE
       chomp $sub_content_block1;
    }

    ###
    my $template = <<"__TEMPLATE";
#define DRAM_CS                     $LPSDRAM_CHIP_SELECT
/* Density of LPSDRAM,in terms of Mbits */
#define DRAM_SIZE                   $density
/* EMI_CONL value */
#define EMI_DRAM_RERESH_CONTROL     $ref_con
/* EMI_CONI value */
#define EMI_DRAM_MODE               $dram_mode
/* EMI_CONI value */
#define EMI_DRAM_EXT_MODE           $dram_ext_mode
/* EMI_CONK value */
#define EMI_DRAM_CONTROL            $dram_ctrl
/* EMI_GENA value */
#define EMI_GENERAL_CONTROL1_VAL    $gen_ctrla
/* EMI_GENB value */
#define EMI_GENERAL_CONTROL2_VAL    $gen_ctrlb
$sub_content_block1
const kal_uint32  EMI_EXTSRAM_SIZE = (DRAM_SIZE<<20) >> 3;
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  HeaderBody_for_nor_lpsdram_mcp
# return:      content for custom_EMI.h 
#****************************************************************************
sub HeaderBody_for_nor_lpsdram_mcp
{
    my $flash_size          = $part_info->{CS}->{0}->{SIZE};
    my @regions             = split /\n/, $part_info->{CS}->{0}->{LAST_BANK}->{REGION};
    my $sum_of_regions      = 0;
    my $blocks_of_regions   = 0;
    my $pbp_size            = ($part_info->{CS}->{0}->{PBP}->{Y_OR_N} =~ /Y/i)
                            ?  $part_info->{CS}->{0}->{PBP}->{SIZE} 
                            : 0;
    for (0..$#regions)
    {
        if ($regions[$_] =~ /\{(0x\w+),\s*(\d+)\}/) # match {0x20000, 7}
        {
            $blocks_of_regions += $2;
            $sum_of_regions += hex($1) * $2;
        }
    }
    die "TOTAL_BLOCKS > 127 , recommend enable FDM5.0 feature!\n" if ($blocks_of_regions > 127);
    my $base_addr_string    = sprintf("0x%08X", (($flash_size/8*1024*1024) - $sum_of_regions));
    my $fat_space_string    = sprintf("0x%08X",                              $sum_of_regions );

    ###
    my $sub_content_block1 = &emi_csconfiguration();
    my $sub_content_block2 = &driving_and_cache_prefetch_setting();
    my $sub_content_block3 = &emi_setting_on_chip_select();
    my $sub_content_block4 = &additional_information();
    my $sub_content_block5 = &region_info(@regions);
    my $sub_content_block6 = &HeaderBody_for_lpsdram();

    ###
    my $template = <<"__TEMPLATE";
#include "flash_opt.h"

/*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/
$sub_content_block1
/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/
$sub_content_block2
/*
 ****************************************************************************
 Specify the related EMI Setting
 ****************************************************************************
*/
$sub_content_block3
/*
 ****************************************************************************
 Specify additional information
 ****************************************************************************
*/
$sub_content_block4
/*
 ****************************************************************************
 Specify RAM information
 ****************************************************************************
*/
$sub_content_block6
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
#define FLASH_BASE_ADDRESS    $base_addr_string

/*******************************************************************************
   Step 2. Modify the value of ALLOCATED_FAT_SPACE, which is the total flash
           space allocated for FAT
 *******************************************************************************/
#define ALLOCATED_FAT_SPACE   $fat_space_string

/*******************************************************************************
   Step 3. Fill the flash region information table, a region is the memory space
           that contains continuous sectors of equal size. Each region element
           in the table is the format as below:
           {S_sector, N_sector},
               S_sector: the size of sector in the region
               N_sector: the number of sectors in the region
 *******************************************************************************/
$sub_content_block5

/*******************************************************************************
   Step 4. Modify the value of TOTAL_BLOCKS, which is the sum of the number of
           sectors in all regions.
           Note : The Maximum value of TOTAL_BLOCKS is (127).
 *******************************************************************************/
#define TOTAL_BLOCKS          $blocks_of_regions

/*******************************************************************************
   Step 5. Modify the value of page buffer size in WORD for page buffer program
 *******************************************************************************/
kal_uint32 PAGE_BUFFER_SIZE = $pbp_size;

/*******************************************************************************
   !CAUTION! !!Only for Enhanced Single Bank NOR Flash support!!
   Step 6. Modify the size of block erase queue, which is the number of reserved 
           blocks. It is recommended to be 10~20% of TOTAL_BLOCK value.
           If this value is less than 2, the FDM would use 1.5 internally.
 *******************************************************************************/
#define SNOR_ERASE_QUEUE_SIZE    5

/*******************************************************************************
   Step 7. This is for the Enhanced Signle Bank Support, when this feature is
           turned on and still use multi-bank device, this table should be filled
           with correct value.
 
           This Table define the flash bank information which starts from 
           FLASH_BASE_ADDRESS, please fill the flash bank information table, every
           entry defines the memory space that contains continuous banks of equal size.
           Each entry element in the table is the format as below:
           {S_Bank, N_Bank},
               S_Bank: the size of bank in the entry
               N_Bank: the number of banks in the entry
 *******************************************************************************/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined( __MULTI_BANK_NOR_DEVICE__)
FLASH_REGIONINFO_VAR_MODIFIER FlashBankInfo BankInfo[] =
{
   {x , x},
   EndBankInfo /* Don't modify this line */
};
#endif 


__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  custom_EMI_h_file_body
# return:      flash opt ending
#****************************************************************************
sub custom_EMI_h_file_body
{
    my $HeaderBody;

    if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
    {
        $HeaderBody = &HeaderBody_for_nor_ram_mcp();
    } # if ($MEMORY_DEVICE_TYPE eq 'NOR_RAM_MCP')
    elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
    {
        $HeaderBody = &HeaderBody_for_lpsdram();
    } # elsif ($MEMORY_DEVICE_TYPE eq 'LPSDRAM')
    elsif ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM_MCP')
    {
        $HeaderBody = &HeaderBody_for_nor_lpsdram_mcp();
    } # elsif ($MEMORY_DEVICE_TYPE eq 'NOR_LPSDRAM')
    else
    {
        # Incorrect memory device type or part number not supported!
        ;
    }
    ###
    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__
$HeaderBody
#endif /* __CUSTOM_EMI__ */

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
 *   Memory Device database last modified on $year/$month/$day
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
