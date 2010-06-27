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
#*       2. generate custom_util.h if not exists
#*       3. generate custom_sap.h if not exists
#*       4. generate custom1_create.c if not exists
#*       5. generate custom_config.h if not exists
#*       6. generate custom_config.c if not exists
#*       7. generate fs_config.c if not exists
#*       8. generate custom_jump_tbl.h if not exists
#*       9. generate custom_jump_tbl.c if not exists
#*      10. generate custom_fota.h if not exists
#*      11. generate custom_fota.c if not exists
#*      12. generate custom_nor_large_disk.c if not exists
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
my $SYSGEN_VERNO     = " V0.30";
                       # v0.30 , 2008/04/03 , Enlarge system memory pool for GEMINI
                       # v0.27 , 2008/03/27 , GLOBAL_MEM_SIZE 290K -> 320K on GPRS Generic globalmem_gprs for GEMINI projects
                       # v0.24 , 2007/10/05 , fs_config.c revise for Dual MSDC setting
                       # v0.22 , 2007/08/20 , fs_config.c revise for MT6223P platform setting
                       # v0.21 , 2007/08/20 , custom_config.c system RAM default value alignment on GSM projects
                       # v0.20 , 2007/08/10 , custom_config.c system RAM and MMI stack adjustment if OBIGO_Q05A
                       # v0.19 , 2007/05/14 , custom_config.c control buffer slots adjustment
                       # v0.18 , 2007/05/14 , custom_config.c fs_config.c resource enlarge for DM , DRMT tasks
                       # v0.17 , 2007/04/23 , dependency_check enable
                       # v0.16 , 2007/04/23 , custom_config.c OBIGO_Q05A compile option 
                       # v0.15 , 2007/04/17 , GLOBAL_DEBUG_MEM_SIZE 150K -> 160K on globalmem_gsm
                       # v0.14 , 2007/03/12 , custom_config.c new function custom_config_task_stack_location()
                       # v0.13 , 2007/02/26 , fs_config.c revise for MSDC device configure update
                       # v0.12 , 2007/01/21 , make event schedule pool size customizable
                       # v0.11 , 2007/01/02 , custom_nor_large_disk.c template imported
                       #                    , add error checking on file close
                       # v0.10 ,            , minor revise on custom_fota.h template
                       # v0.09 , 2006/12/25 , fs_config.c support SIM_PLUS, custom_fota.c custom_fota.h template
                       # v0.08 , 2006/12/18 , new mechanism for custom task present on usb / factory boot mode

#****************************************************************************
# File Names
#****************************************************************************
my $CUSTOM_UTIL_C    = $ARGV[0] . '\\' . "custom_util.c";
my $CUSTOM_UTIL_H    = $ARGV[0] . '\\' . "custom_util.h";
my $CUSTOM_SAP_H     = $ARGV[0] . '\\' . "custom_sap.h";
my $CUSTOM1_CREATE_C = $ARGV[0] . '\\' . "custom1_create.c";
my $CUSTOM_CONFIG_H  = $ARGV[0] . '\\' . "custom_config.h";
my $CUSTOM_CONFIG_C  = $ARGV[0] . '\\' . "custom_config.c";
my $FS_CONFIG_C      = $ARGV[0] . '\\' . "fs_config.c";
my $CUSTOM_JUMPTBL_H = $ARGV[0] . '\\' . "custom_jump_tbl.h";
my $CUSTOM_JUMPTBL_C = $ARGV[0] . '\\' . "custom_jump_tbl.c";
my $CUSTOM_FOTA_H    = $ARGV[0] . '\\' . "custom_fota.h";
my $CUSTOM_FOTA_C    = $ARGV[0] . '\\' . "custom_fota.c";
my $CUSTOM_NORFDM5_C = $ARGV[0] . '\\' . "custom_nor_large_disk.c";

#****************************************************************************
# Script filename
#****************************************************************************
my $sysgen_pl        = $0;

#****************************************************************************
# Project Make File
#****************************************************************************
my %MAKEFILE_OPTIONS;
my $keyname;

my $themf = $ARGV[1];
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
# 1 >>>  Generate custom_util.c
#****************************************************************************
&dependency_check($CUSTOM_UTIL_C, $sysgen_pl);

if (-e $CUSTOM_UTIL_C)
{
    print "$CUSTOM_UTIL_C already exists\n";
}
else
{
    open (CUSTOM_UTIL_C, ">$CUSTOM_UTIL_C") or die "cannot open $CUSTOM_UTIL_C\n";

    print CUSTOM_UTIL_C &copyright_file_header();
    print CUSTOM_UTIL_C &description_file_header(       "custom_util.c",
                          "This file provides the custom utililty APIs",
                                 "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_UTIL_C &custom_util_c_file_body();
    close CUSTOM_UTIL_C or die "fail to generate $CUSTOM_UTIL_C";

    print "$CUSTOM_UTIL_C is generated\n";
}

#****************************************************************************
# 2 >>>  Generate custom_util.h
#****************************************************************************
&dependency_check($CUSTOM_UTIL_H, $sysgen_pl);

if (-e $CUSTOM_UTIL_H)
{
    print "$CUSTOM_UTIL_H already exists\n";
}
else
{
    open (CUSTOM_UTIL_H, ">$CUSTOM_UTIL_H") or die "cannot open $CUSTOM_UTIL_H\n";

    print CUSTOM_UTIL_H &copyright_file_header();
    print CUSTOM_UTIL_H &description_file_header(       "custom_util.h",
                  "This file provides the custom utililty declarations",
                                 "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_UTIL_H &custom_util_h_file_body();
    close CUSTOM_UTIL_H or die "fail to generate $CUSTOM_UTIL_H";

    print "$CUSTOM_UTIL_H is generated\n";
}

#****************************************************************************
# 3 >>>  Generate custom_sap.h
#****************************************************************************
&dependency_check($CUSTOM_SAP_H, $sysgen_pl);

if (-e $CUSTOM_SAP_H)
{
    print "$CUSTOM_SAP_H already exists\n";
}
else
{
    open (CUSTOM_SAP_H, ">$CUSTOM_SAP_H") or die "cannot open $CUSTOM_SAP_H\n";

    print CUSTOM_SAP_H &copyright_file_header();
    print CUSTOM_SAP_H &description_file_header(         "custom_sap.h",
                       "This file provide for customization message id",
                                 "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_SAP_H &custom_sap_h_file_body();
    close CUSTOM_SAP_H or die "fail to generate $CUSTOM_SAP_H";

    print "$CUSTOM_SAP_H is generated\n";
}

#****************************************************************************
# 4 >>>  Generate custom1_create.c
#****************************************************************************
&dependency_check($CUSTOM1_CREATE_C, $sysgen_pl);

if (-e $CUSTOM1_CREATE_C)
{
    print "$CUSTOM1_CREATE_C already exists\n";
}
else
{
    open (CUSTOM1_CREATE_C, ">$CUSTOM1_CREATE_C") or die "cannot open $CUSTOM1_CREATE_C\n";

    print CUSTOM1_CREATE_C &copyright_file_header();
    print CUSTOM1_CREATE_C &description_file_header( "custom1_create.c",
          "This file implements custom1 component task create function",
                                 "system auto generator". $SYSGEN_VERNO);
    print CUSTOM1_CREATE_C &custom1_create_c_file_body();
    close CUSTOM1_CREATE_C or die "fail to generate $CUSTOM1_CREATE_C";

    print "$CUSTOM1_CREATE_C is generated\n";
}

#****************************************************************************
# 5 >>>  Generate custom_config.h
#****************************************************************************
&dependency_check($CUSTOM_CONFIG_H, $sysgen_pl, $themf);

if (-e $CUSTOM_CONFIG_H)
{
    print "$CUSTOM_CONFIG_H already exists\n";
}
else
{
    open (CUSTOM_CONFIG_H, ">$CUSTOM_CONFIG_H") or die "cannot open $CUSTOM_CONFIG_H\n";

    print CUSTOM_CONFIG_H &copyright_file_header();
    print CUSTOM_CONFIG_H &description_file_header( "custom_config.h",
          "This file provides the custom task index and module index configuration",
                                 "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_CONFIG_H &custom_config_h_file_body();
    close CUSTOM_CONFIG_H or die "fail to generate $CUSTOM_CONFIG_H";

    print "$CUSTOM_CONFIG_H is generated\n";
}

#****************************************************************************
# 6 >>>  Generate custom_config.c
#****************************************************************************
&dependency_check($CUSTOM_CONFIG_C, $sysgen_pl, $themf);

if (-e $CUSTOM_CONFIG_C)
{
    print "$CUSTOM_CONFIG_C already exists\n";
}
else
{
    open (CUSTOM_CONFIG_C, ">$CUSTOM_CONFIG_C") or die "cannot open $CUSTOM_CONFIG_C\n";

    print CUSTOM_CONFIG_C &copyright_file_header();
    print CUSTOM_CONFIG_C &description_file_header(   "custom_config.c",
              "This file contain definition of custom component module".
                                "configuration variables, and routines",
                                 "system auto generator". $SYSGEN_VERNO);
    # template generator here, 
    # See Also  dispatch_globalmem_and_ctrlbuffpool();  for algorithm
    #
    print CUSTOM_CONFIG_C &custom_config_c_file_body();
    close CUSTOM_CONFIG_C or die "fail to generate $CUSTOM_CONFIG_C";

    print "$CUSTOM_CONFIG_C is generated\n";
}

#****************************************************************************
# 7 >>>  Generate fs_config.c
#****************************************************************************
&dependency_check($FS_CONFIG_C, $sysgen_pl, $themf);

if (-e $FS_CONFIG_C)
{
    print "$FS_CONFIG_C already exists\n";
}
else
{
    open (FS_CONFIG_C, ">$FS_CONFIG_C") or die "cannot open $FS_CONFIG_C\n";

    print FS_CONFIG_C &copyright_file_header();
    print FS_CONFIG_C &description_file_header(           "fs_config.c",
                "This file defines all resource setting in file system",
                                 "system auto generator". $SYSGEN_VERNO);
    # template generator here, 
    # See Also  dispatch_drivenum(), dispatch_buffnum(),
    #           dispatch_fhnum(), dispatch_threadnum()   for algorithms
    #
    print FS_CONFIG_C &fs_config_c_file_body();
    close FS_CONFIG_C or die "fail to generate $FS_CONFIG_C";

    print "$FS_CONFIG_C is generated\n";
}

#****************************************************************************
# 8 >>>  Generate custom_jump_tbl.h
#****************************************************************************
&dependency_check($CUSTOM_JUMPTBL_H, $sysgen_pl);

if (-e $CUSTOM_JUMPTBL_H)
{
    print "$CUSTOM_JUMPTBL_H already exists\n";
}
else
{
    open (CUSTOM_JUMPTBL_H, ">$CUSTOM_JUMPTBL_H") or die "cannot open $CUSTOM_JUMPTBL_H\n";

    print CUSTOM_JUMPTBL_H &copyright_file_header();
    print CUSTOM_JUMPTBL_H &description_file_header( "custom_jump_tbl.h",
          "header file for indirect jump table for multiple binary load",
                                 "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_JUMPTBL_H &custom_jump_tbl_h_file_body();
    close CUSTOM_JUMPTBL_H or die "fail to generate $CUSTOM_JUMPTBL_H";

    print "$CUSTOM_JUMPTBL_H is generated\n";
}

#****************************************************************************
# 9 >>>  Generate custom_jump_tbl.c
#****************************************************************************
&dependency_check($CUSTOM_JUMPTBL_C, $sysgen_pl);

if (-e $CUSTOM_JUMPTBL_C)
{
    print "$CUSTOM_JUMPTBL_C already exists\n";
}
else
{
    open (CUSTOM_JUMPTBL_C, ">$CUSTOM_JUMPTBL_C") or die "cannot open $CUSTOM_JUMPTBL_C\n";

    print CUSTOM_JUMPTBL_C &copyright_file_header();
    print CUSTOM_JUMPTBL_C &description_file_header(   "custom_jump_tbl.c",
            "source file for indirect jump table for multiple binary load",
                                 "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_JUMPTBL_C &custom_jump_tbl_c_file_body();
    close CUSTOM_JUMPTBL_C or die "fail to generate $CUSTOM_JUMPTBL_C";

    print "$CUSTOM_JUMPTBL_C is generated\n";
}

#****************************************************************************
#10 >>>  Generate custom_fota.h
#****************************************************************************
&dependency_check($CUSTOM_FOTA_H, $sysgen_pl);

if (-e $CUSTOM_FOTA_H)
{
    print "$CUSTOM_FOTA_H already exists\n";
}
else
{
    open (CUSTOM_FOTA_H, ">$CUSTOM_FOTA_H") or die "cannot open $CUSTOM_FOTA_H\n";

    print CUSTOM_FOTA_H &copyright_file_header();
    print CUSTOM_FOTA_H &description_file_header(                 "custom_fota.h",
          "This Module defines the FOTA (Firmware Over the Air) related setting.",
             "Yoda Chen (mtk01178)     " . "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_FOTA_H &custom_fota_h_file_body();
    close CUSTOM_FOTA_H or die "fail to generate $CUSTOM_FOTA_H";

    print "$CUSTOM_FOTA_H is generated\n";
}

#****************************************************************************
#11 >>>  Generate custom_fota.c
#****************************************************************************
&dependency_check($CUSTOM_FOTA_C, $sysgen_pl);

if (-e $CUSTOM_FOTA_C)
{
    print "$CUSTOM_FOTA_C already exists\n";
}
else
{
    open (CUSTOM_FOTA_C, ">$CUSTOM_FOTA_C") or die "cannot open $CUSTOM_FOTA_C\n";

    print CUSTOM_FOTA_C &copyright_file_header();
    print CUSTOM_FOTA_C &description_file_header(                 "custom_fota.c",
          "This Module defines the FOTA (Firmware Over the Air) related setting.",
             "Yoda Chen (mtk01178)     " . "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_FOTA_C &custom_fota_c_file_body();
    close CUSTOM_FOTA_C or die "fail to generate $CUSTOM_FOTA_C";

    print "$CUSTOM_FOTA_C is generated\n";
}

#****************************************************************************
#12 >>>  Generate custom_nor_large_disk.c
#****************************************************************************
&dependency_check($CUSTOM_NORFDM5_C, $sysgen_pl);

if (-e $CUSTOM_NORFDM5_C)
{
    print "$CUSTOM_NORFDM5_C already exists\n";
}
else
{
    open (CUSTOM_NORFDM5_C, ">$CUSTOM_NORFDM5_C") or die "cannot open $CUSTOM_NORFDM5_C\n";

    print CUSTOM_NORFDM5_C &copyright_file_header();
    print CUSTOM_NORFDM5_C &description_file_header(      "custom_nor_large_disk.c",
	  "defines prototypes and data structure which will be used in NOR FDM 5.0",
              "Yoda Chen (mtk01178)     " . "system auto generator". $SYSGEN_VERNO);
    print CUSTOM_NORFDM5_C &custom_nor_large_disk_c_file_body();
    close CUSTOM_NORFDM5_C or die "fail to generate $CUSTOM_NORFDM5_C";

    print "$CUSTOM_NORFDM5_C is generated\n";
}

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
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
# subroutine:  determine the amount for file system configure in fs_config.c
# return:      the value for recommend drive number <NOTE!!!: scalar context>
#****************************************************************************
sub dispatch_drivenum
{
    my $value = 4; #  4 = 1(*SYS*) + 1 (NOR) +  1 (NAND) + 1 (CARD)
    # check (NOR) not present
    if (exists $MAKEFILE_OPTIONS{'nand_flash_booting'} and $MAKEFILE_OPTIONS{'nand_flash_booting'} eq 'TRUE')
    {  $value -= 1;
    }
    elsif (exists $MAKEFILE_OPTIONS{'system_drive_on_nand'} and $MAKEFILE_OPTIONS{'system_drive_on_nand'} eq 'TRUE')
    {  $value -= 1;
    }
    # check (NAND) not present
    unless (exists $MAKEFILE_OPTIONS{'nand_support'} and $MAKEFILE_OPTIONS{'nand_support'} eq 'TRUE')
    {  $value -= 1;
    }
    #check (CARD) not present
    unless (exists $MAKEFILE_OPTIONS{'msdc_card_support_type'} and $MAKEFILE_OPTIONS{'msdc_card_support_type'} ne 'NONE')
    {  $value -= 1;
    }
    #finial
    return $value;
}

#****************************************************************************
# subroutine:  determine the amount for file system configure in fs_config.c
# return:      the value for recommend buffer number <NOTE!!!: scalar context>
#****************************************************************************
sub dispatch_buffnum
{
    if    (exists $MAKEFILE_OPTIONS{'l1_gprs'} and $MAKEFILE_OPTIONS{'l1_gprs'} eq 'TRUE')
    # GPRS  capability
    {   return 16;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'FALSE')
    # GSM   capability  ; default
    {   return  8;
    }
    else
    # GSM   capability  + Low cost (single bank no matter)
    {   return  4;
    }
    die "search buffer number fail";
}

#****************************************************************************
# subroutine:  determine the amount for file system configure in fs_config.c
# return:      the value for recommend file handle number <NOTE!!!: scalar context>
#****************************************************************************
sub dispatch_fhnum
{
    if    (exists $MAKEFILE_OPTIONS{'l1_gprs'} and $MAKEFILE_OPTIONS{'l1_gprs'} eq 'TRUE')
    # GPRS  capability
    {   return 24;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'FALSE')
    # GSM   capability  ; default
    {   return 16;
    }
    elsif (exists $MAKEFILE_OPTIONS{'single_bank_nor_flash_support'} and
                  $MAKEFILE_OPTIONS{'single_bank_nor_flash_support'} eq 'FALSE')
    # GSM   capability  ; low cost
    {   return  8;
    }
    elsif (exists $MAKEFILE_OPTIONS{'single_bank_nor_flash_support'} and
                  $MAKEFILE_OPTIONS{'single_bank_nor_flash_support'} eq 'TRUE')
    # GSM   capability  ; low cost + single bank
    {   return  4;
    }
    die "search file handle number fail";
}

#****************************************************************************
# subroutine:  determine the amount for file system configure in fs_config.c
# return:      the value for recommend max thread number <NOTE!!!: scalar context>
#****************************************************************************
sub dispatch_threadnum
{
    if    (exists $MAKEFILE_OPTIONS{'l1_egprs'} and $MAKEFILE_OPTIONS{'l1_egprs'} eq 'TRUE')
    # EDGE  capability
    {   return 26;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_gprs'} and $MAKEFILE_OPTIONS{'l1_gprs'} eq 'TRUE')
    # GPRS  capability
    {   return 22;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'FALSE')
    # GSM   capability  ; default
    {   return 14;
    }
    else
    # GSM   capability  ; low cost (single bank no matter)
    {   return  7;
    }
    die "search file handle number fail";
}

#****************************************************************************
# subroutine:  determine the template of global sys memory and
#              global debug memory for custom_config.c
# return:      the partial body strings in <NOTE!!!: list context>
#****************************************************************************
sub dispatch_globalmem_and_ctrlbuffpool
{
    my $gm_str_ref;
    my $cb_str_ref;
    if    (exists $MAKEFILE_OPTIONS{'l1_wcdma'} and $MAKEFILE_OPTIONS{'l1_wcdma'} eq 'TRUE')
    # WCDMA capability
    {   $gm_str_ref = &globalmem_wcdma;
        $cb_str_ref = &ctrlbuffpool_as_default;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_egprs'} and $MAKEFILE_OPTIONS{'l1_egprs'} eq 'TRUE')
    # EDGE  capability
    {   $gm_str_ref = &globalmem_edge;
        $cb_str_ref = &ctrlbuffpool_as_default;
        $cb_str_ref.= &ctrlbuffpool_adjust_on_edge_class;
    }
    elsif (exists $MAKEFILE_OPTIONS{'l1_gprs'} and $MAKEFILE_OPTIONS{'l1_gprs'} eq 'TRUE')
    # GPRS  capability
    {   $gm_str_ref = &globalmem_gprs;
        $cb_str_ref = &ctrlbuffpool_as_default;
        $cb_str_ref.= &ctrlbuffpool_adjust_on_gprs_class;
    }
    elsif (exists $MAKEFILE_OPTIONS{'low_cost_support'} and $MAKEFILE_OPTIONS{'low_cost_support'} eq 'FALSE')
    # GSM   capability  ; default
    {   $gm_str_ref = &globalmem_gsm;
        $cb_str_ref = &ctrlbuffpool_as_default;
    }
    elsif (exists $MAKEFILE_OPTIONS{'single_bank_nor_flash_support'} and
                  $MAKEFILE_OPTIONS{'single_bank_nor_flash_support'} eq 'FALSE')
    # GSM   capability  ; low cost
    {   $gm_str_ref = &globalmem_gsm_lowcost;
        $cb_str_ref = &ctrlbuffpool_gsm_lowcost;
    }
    elsif (exists $MAKEFILE_OPTIONS{'single_bank_nor_flash_support'} and
                  $MAKEFILE_OPTIONS{'single_bank_nor_flash_support'} eq 'TRUE')
    # GSM   capability  ; low cost + single bank
    {   $gm_str_ref = &globalmem_gsm_lowcost_singlebank;
        $cb_str_ref = &ctrlbuffpool_gsm_lowcost_singlebank;
    }
    else  
    # Un supported state
    {       die "global memory and ctrl buff pool template search fail";
    }
    return ($gm_str_ref, $cb_str_ref);
}

#****************************************************************************
# subroutine:  generate global memory definiation for WCDMA type
# return:      the body strings
# EXAMPLE PROJECT : MONZA29E2_EVB
#****************************************************************************
sub globalmem_wcdma
{
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : WCDMA Generic */
#if defined(__WCDMA_RAT__)

    #if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
       #define GLOBAL_MEM_SIZE          (8000*1024) 
       #define GLOBAL_DEBUG_MEM_SIZE    (6000*1024)
    #else /* MTK_KAL_MNT || KAL_ON_OSCAR */
       #define GLOBAL_MEM_SIZE          (5700*1024) 
       #define GLOBAL_DEBUG_MEM_SIZE    (2000*1024)
    #endif

#else  /* __WCDMA_RAT__ */

    #if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
       #define GLOBAL_MEM_SIZE          ( 290*1024)
       #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024)
    #else /* MTK_KAL_MNT || KAL_ON_OSCAR */
       #define GLOBAL_MEM_SIZE          ( 290*1024)
       #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024)
    #endif

#endif /* __WCDMA_RAT__ */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for EDGE type
# return:      the body strings
# EXAMPLE PROJECT : SUPERMAN29_BB
#****************************************************************************
sub globalmem_edge
{
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : EDGE Generic */
#if defined(__EGPRS_MODE__) && ( defined(__VOIP__) || defined(__WIFI_SUPPORT__) ) && defined(OBIGO_Q05A)

    #if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__)
          #define GLOBAL_MEM_SIZE          ( 470*1024)
          #define GLOBAL_DEBUG_MEM_SIZE    ( 320*1024)
       #else
          #define GLOBAL_MEM_SIZE          ( 450*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 300*1024)
       #endif
    #else /* MTK_KAL_MNT || KAL_ON_OSCAR */
       #if defined(__GEMINI__)
          #define GLOBAL_MEM_SIZE          ( 470*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 148*1024)
       #else
          #define GLOBAL_MEM_SIZE          ( 450*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 128*1024)
       #endif
    #endif

#elif defined(__EGPRS_MODE__) && ( defined(__VOIP__) || defined(__WIFI_SUPPORT__) )

    #if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__)
          #define GLOBAL_MEM_SIZE          ( 440*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 320*1024)
       #else
          #define GLOBAL_MEM_SIZE          ( 420*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 300*1024)
       #endif
    #else /* MTK_KAL_MNT || KAL_ON_OSCAR */
       #if defined(__GEMINI__)
          #define GLOBAL_MEM_SIZE          ( 440*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 148*1024)
       #else
          #define GLOBAL_MEM_SIZE          ( 420*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 128*1024)
       #endif
    #endif

#elif defined(OBIGO_Q05A)

    #if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__)
          #define GLOBAL_MEM_SIZE          ( 410*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
       #else
          #define GLOBAL_MEM_SIZE          ( 390*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024)
       #endif
    #else /* MTK_KAL_MNT || KAL_ON_OSCAR */
       #if defined(__GEMINI__)
          #define GLOBAL_MEM_SIZE          ( 380*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 130*1024)
       #else
          #define GLOBAL_MEM_SIZE          ( 360*1024) 
          #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024)
       #endif
    #endif

#else  /* __EGPRS_MODE__ && ( __VOIP__ || __WIFI_SUPPORT__ ) && OBIGO_Q05A */

    #if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
       #if defined(__GEMINI__)
          #define GLOBAL_MEM_SIZE          ( 380*1024)
          #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
       #else
          #define GLOBAL_MEM_SIZE          ( 360*1024)
          #define GLOBAL_DEBUG_MEM_SIZE    ( 100*1024)
       #endif
    #else /* MTK_KAL_MNT || KAL_ON_OSCAR */
       #if defined(__GEMINI__)
          #define GLOBAL_MEM_SIZE          ( 350*1024)
          #define GLOBAL_DEBUG_MEM_SIZE    ( 130*1024)
       #else
          #define GLOBAL_MEM_SIZE          ( 330*1024)
          #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024)
       #endif
    #endif

#endif /* __EGPRS_MODE__ && ( __VOIP__ || __WIFI_SUPPORT__ ) && OBIGO_Q05A */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for GPRS type
# return:      the body strings
# EXAMPLE PROJECT : SAPPHIRE28_BB
#****************************************************************************
sub globalmem_gprs
{
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : GPRS Generic */
#if (defined(__WIFI_SUPPORT__) || defined(__VOIP__)) && defined(OBIGO_Q05A)

    #if defined(__GEMINI__)
        #define GLOBAL_MEM_SIZE         ( 390*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   ( 130*1024)
    #else
        #define GLOBAL_MEM_SIZE         ( 370*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   ( 110*1024)
    #endif

#elif defined(__WIFI_SUPPORT__) || defined(__VOIP__)

    #if defined(__GEMINI__)
        #define GLOBAL_MEM_SIZE         ( 360*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   ( 130*1024)
    #else
        #define GLOBAL_MEM_SIZE         ( 340*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   ( 110*1024)
    #endif

#elif defined(OBIGO_Q05A) || defined(__GEMINI__)

    #if defined(__GEMINI__)
        #define GLOBAL_MEM_SIZE         ( 340*1024)
	#if 0
	/* Huyanwei Modify It */
        #define GLOBAL_DEBUG_MEM_SIZE   ( 120*1024)
	#else
        #define GLOBAL_DEBUG_MEM_SIZE   ( 100*1024)
	#endif
    #else
        #define GLOBAL_MEM_SIZE         ( 320*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   ( 100*1024)
    #endif

#else /* (__WIFI_SUPPORT__ || __VOIP__) && OBIGO_Q05A */

    #if defined(__GEMINI__)
        #define GLOBAL_MEM_SIZE         ( 310*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   ( 120*1024)
    #else
        #define GLOBAL_MEM_SIZE         ( 290*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   ( 100*1024)
    #endif

#endif /* (__WIFI_SUPPORT__ || __VOIP__) && OBIGO_Q05A */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for GSM type
# return:      the body strings
# EXAMPLE PROJECT : MT6205_CEVB
#****************************************************************************
sub globalmem_gsm
{
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : GSM Generic */
#if defined(__GEMINI__)
        #define GLOBAL_MEM_SIZE         ( 180*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   (  70*1024)
#else
        #define GLOBAL_MEM_SIZE         ( 160*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   (  50*1024)
#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for GSM + LOW COST type
# return:      the body strings
# EXAMPLE PROJECT : NEPTUNE_BB
#****************************************************************************
sub globalmem_gsm_lowcost
{
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : GSM + LOW COST */
#if defined(__GEMINI__)
        #define GLOBAL_MEM_SIZE         ( 155*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   (  60*1024)
#else
        #define GLOBAL_MEM_SIZE         ( 135*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   (  40*1024)
#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate global memory definiation for GSM + LOW COST + SINGLE BANK type
# return:      the body strings
# EXAMPLE PROJECT : NEPTUNE162_BB
#****************************************************************************
sub globalmem_gsm_lowcost_singlebank
{
    my $template = <<"__TEMPLATE";
/* SysGen Template Type : GSM + LOW COST + SINGLE BANK */
#if defined(__GEMINI__)
        #define GLOBAL_MEM_SIZE         ( 130*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   (  60*1024)
#else
        #define GLOBAL_MEM_SIZE         ( 110*1024)
        #define GLOBAL_DEBUG_MEM_SIZE   (  40*1024)
#endif
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , type : adjust on gprs class
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_adjust_on_edge_class
{
    my $template = <<"__TEMPLATE";
   /* EDGE class : ctrl buffer slots adjustment */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , type : adjust on gprs class
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_adjust_on_gprs_class
{
    my $template = <<"__TEMPLATE";
   /* GPRS class : ctrl buffer slots adjustment */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , type : as default
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_as_default
{
    my $template = <<"__TEMPLATE";
   /* These constants defined in adaptation\\include\\ctrl_buff_pool.h */
   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE08;
   ctrl_buff_pool_info_g[0].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE08;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE16;
   ctrl_buff_pool_info_g[1].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE16;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[2].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE32;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[3].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE64;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[4].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE128;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[5].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE256;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[6].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE512;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[7].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE1024;

   ctrl_buff_pool_info_g[8].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[8].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE2048;

   ctrl_buff_pool_info_g[9].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[9].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE4096;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[10].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE8192;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[11].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE16384;

   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[12].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE32768;

   ctrl_buff_pool_info_g[13].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[13].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE65536;

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , Type : GSM + LOWCOST
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_gsm_lowcost
{
    my $template = <<"__TEMPLATE";
   /* sysGen Template : GSM + LOWCOST */
   /* These constants defined in adaptation\\include\\ctrl_buff_pool.h */
   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE08;
   ctrl_buff_pool_info_g[0].no_of_buff  = 50;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE16;
   ctrl_buff_pool_info_g[1].no_of_buff  = 50;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[2].no_of_buff  = 50;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[3].no_of_buff  = 30;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[4].no_of_buff  = 40;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[5].no_of_buff  = 30;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[6].no_of_buff  = 18+2;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[7].no_of_buff  = 11-2;

   ctrl_buff_pool_info_g[8].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[8].no_of_buff  = 5;

   ctrl_buff_pool_info_g[9].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[9].no_of_buff  = 0;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[10].no_of_buff = 0;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[11].no_of_buff = 0;

   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[12].no_of_buff = 0;

   ctrl_buff_pool_info_g[13].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[13].no_of_buff = 0;

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate control buffer setting , Type : GSM + LOWCOST + SINGLEBANK
# return:      the body strings
#****************************************************************************
sub ctrlbuffpool_gsm_lowcost_singlebank
{
    my $template = <<"__TEMPLATE";
   /* sysGen Template : GSM + LOWCOST + SINGLEBANK */
   /* These constants defined in adaptation\\include\\ctrl_buff_pool.h */
   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE08;
   ctrl_buff_pool_info_g[0].no_of_buff  = 50;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE16;
   ctrl_buff_pool_info_g[1].no_of_buff  = 50;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[2].no_of_buff  = 50;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[3].no_of_buff  = 30;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[4].no_of_buff  = 40;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[5].no_of_buff  = 30;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[6].no_of_buff  = 18;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[7].no_of_buff  = 8;

   ctrl_buff_pool_info_g[8].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[8].no_of_buff  = 4;

   ctrl_buff_pool_info_g[9].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[9].no_of_buff  = 0;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[10].no_of_buff = 0;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[11].no_of_buff = 0;

   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[12].no_of_buff = 0;

   ctrl_buff_pool_info_g[13].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[13].no_of_buff = 0;

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate custom_util.c content body
# return:      the body strings
#****************************************************************************
sub custom_util_c_file_body
{
    my $template = <<"__TEMPLATE";
/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "kal_release.h"

/*************************************************************************
 * Function Declaration
 *************************************************************************/
#ifdef DRV_DEBUG
extern void dbg_print(char *fmt,...);
#endif /* DRV_DEBUG */

/*************************************************************************
* FUNCTION
*  custom_print
*
* DESCRIPTION
*       This function implements output display through uart port for custom
*       debugging without MTK tool utility.
*
*       Notice:
*       The routine is possibly to hit race condition because of reentrant caller.
*
* PARAMETERS
*       string  -       output string
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
custom_print(kal_char* string)
{
#ifdef DRV_DEBUG
        dbg_print("\%s\\r\\n", string);
#elif defined(__TST_MODULE__) && defined(__CUSTOM_RELEASE__)
        //kal_print(string);
        kal_prompt_trace(MOD_MMI,"\%s",string);
#endif /* DVR_DEBUG */
}

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate custom_util.h content body
# return:      the body strings
#****************************************************************************
sub custom_util_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef _CUSTOM_UTIL_H
#define _CUSTOM_UTIL_H

/*************************************************************************
 * Function Declaration
 *************************************************************************/
extern void custom_print(kal_char* string);

#endif /* _CUSTOM_UTIL_H */

__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate custom_sap.h content body
# return:      the body strings
#****************************************************************************
sub custom_sap_h_file_body
{
    my $template = <<"__TEMPLATE";
/* Add customization message id here */
MSG_ID_CUSTOM1_CUSTOM2  =  CUSTOM_MSG_CODE_BEGIN,
MSG_ID_CUSTOM2_CUSTOM1,
#ifdef CMS_NEW_APP
MSG_ID_CMS_MMS_STARTUP,
MSG_ID_CMS_WAP_STARTUP,
MSG_ID_CMS_MAP_STARTUP,
MSG_ID_CMS_MMS_SHUTDOWN,
MSG_ID_CMS_WAP_SHUTDOWN,
MSG_ID_CMS_MAP_SHUTDOWN,
MSG_ID_CMS_MAP_TEST,
MSG_ID_CMS_WAP_PARSER,
MSG_ID_CMS_WAP_LAYOUT,
MSG_ID_CMS_WAP_DRAW,
MSG_ID_CMS_WAP_PAGEUP,
MSG_ID_CMS_WAP_PAGEDOWN,
MSG_ID_CMS_WAP_NEWINPUTURL,
MSG_ID_CMS_WAP_EDITBOX,
MSG_ID_CMS_WAP_MAILADDRESS,
MSG_ID_CMS_WAP_CALLREQUEST,
MSG_ID_CMS_WAP_STOREPHONENUM,
MSG_ID_CMS_WAP_NEXTLINKFOCUS,
MSG_ID_CMS_WAP_LASTLINKFOCUS,
MSG_ID_CMS_WAP_RIGHTLINKFOCUS,
MSG_ID_CMS_WAP_LEFTLINKFOCUS,
MSG_ID_CMS_WAP_SOCCLOSESUCCESS,
MSG_ID_CMS_WAP_SOCCLOSEFAIL,
MSG_ID_CMS_WAP_UPPAGE,
MSG_ID_CMS_WAP_DOWNPAGE,
MSG_ID_CMS_WAP_TOUCHPENDOWN,
MSG_ID_CMS_WAP_TOUCHPENUP,
MSG_ID_CMS_WAP_DEVDEACTIVEATE,
MSG_ID_CMS_WAP_PAGEREFRESH,
MSG_ID_CMS_MMS_NOTIFICATION_ARRIVE,
MSG_ID_CMS_MMS_RECV_SUCCESS,
MSG_ID_CMS_MMS_SEND_SUCCESS,
MSG_ID_CMS_MMS_RECV_FAILED,
MSG_ID_CMS_MMS_SEND_FAILED_UNKNOWN,
MSG_ID_CMS_MMS_SEND_MESSAGE,
MSG_ID_CMS_MMS_RECEIVE_MESSAGE,
MSG_ID_CMS_MMS_CONNECT_FAILED,
MSG_ID_CMS_MMS_PLAY_MESSAGE,
MSG_ID_QQ_1,
MSG_ID_QQ_2,
MSG_ID_QQ_3,
MSG_ID_QQ_4,
MSG_ID_QQ_5,
MSG_ID_QQ_6,
#endif
#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
MSG_ID_GSENSOR_OFF,
MSG_ID_GSENSOR_ON,
MSG_ID_GSENSOR_WORK,
MSG_ID_GSENSOR_UP,
MSG_ID_GSENSOR_DOWN,
MSG_ID_GSENSOR_LEFT,
MSG_ID_GSENSOR_RIGHT,
MSG_ID_GSENSOR_FRONT,
MSG_ID_GSENSOR_BACK,
#endif
#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It 
MSG_ID_HORSERACE_OFF,
MSG_ID_HORSERACE_ON,
MSG_ID_HORSERACE_WORK,
#endif

#if defined(DOUBLE_BATTERY_SUPPORT)
//Huyanwei Add It 
MSG_ID_BATTERYII_PLUG_IN,
MSG_ID_BATTERYII_PLUG_OUT,
#endif

/* 2009.05.04 added by hongzhe.liu for m-sensor +  */
 #if defined(__DIRECTION_SENSOR_SUPPORT__)
MSG_ID_MSENSOR_DIRECTION_0,
MSG_ID_MSENSOR_DIRECTION_90,
MSG_ID_MSENSOR_DIRECTION_180,
MSG_ID_MSENSOR_DIRECTION_270,
#endif
/* 2009.05.04 added by hongzhe.liu for m-sensor -  */


__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  generate custom1_create.c content body
# return:      the body strings
#****************************************************************************
sub custom1_create_c_file_body
{
    my $template = <<"__TEMPLATE";
/*************************************************************************
* Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "stack_types.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "custom_util.h"
#include "stack_init.h"
#include "stack_ltlcom.h"


/*************************************************************************
* Function declaration
 *************************************************************************/
static void custom1_main(task_entry_struct * task_entry_ptr);
static void custom2_main(task_entry_struct * task_entry_ptr);

/*************************************************************************
* FUNCTION
*  custom1_create
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if (defined(G_SENSOR_SUPPORT) )
//Huyanwei Add It 
void SendMessagesOneToMMI(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
  	send_ilm = allocate_ilm(MOD_CUSTOM1);
	if( send_ilm == NULL)
	{
		times ++ ;
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\\r\\nOne To MMI :%d\\r\\n",times);
#endif		
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_CUSTOM1;
   send_ilm->dest_mod_id = MOD_MMI ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}

void SendMessagesOneToOne(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
  	send_ilm = allocate_ilm(MOD_CUSTOM1);
	if( send_ilm == NULL)
	{
		times ++ ;
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\\r\\nOne To One:%d\\r\\n",times);
#endif		
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_CUSTOM1;
   send_ilm->dest_mod_id = MOD_CUSTOM1 ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}

void SendMessagesMMIToOne(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
   	send_ilm = allocate_ilm(MOD_MMI);
	if( send_ilm == NULL)
	{
		times ++ ;
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\\r\\nMMI To One:%d\\r\\n",times);
#endif		
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_MMI;
   send_ilm->dest_mod_id = MOD_CUSTOM1 ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}
#endif

#if (defined(HORSERACE_SUPPORT) )
void SendMessagesTwoToMMI(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
	send_ilm = allocate_ilm(MOD_CUSTOM2);
	if( send_ilm == NULL)
	{
		times ++ ;
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_CUSTOM2;
   send_ilm->dest_mod_id = MOD_MMI ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}

void SendMessagesTwoToTwo(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
	send_ilm = allocate_ilm(MOD_CUSTOM2);
	if( send_ilm == NULL)
	{
		times ++ ;
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_CUSTOM2;
   send_ilm->dest_mod_id = MOD_CUSTOM2 ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}

void SendMessagesMMIToTwo(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
	   send_ilm = allocate_ilm(MOD_MMI);
	if( send_ilm == NULL)
	{
		times ++ ;
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_MMI;
   send_ilm->dest_mod_id = MOD_CUSTOM2 ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}
#endif



kal_bool
custom1_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct custom1_handler_info =
   {
      custom1_main,  /* task entry function */
      NULL,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&custom1_handler_info;
   return KAL_TRUE;
}

extern int GSensorInitedFlag ;
extern int GetDirection(void);
extern int SleepAtIdleScreen(void);
extern void SetGSensorSleepMode(unsigned char  Mode) ;


static void
custom1_main(task_entry_struct * task_entry_ptr)
{
    int direction = 0 ;
    ilm_struct current_ilm; 
    kal_uint32 my_index;
	
    static int FlagWork = 0;	

    //kal_get_my_task_index(&my_index);
	
    while ( 1 ) 
    { 
	     direction = 0 ;
	     receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm); 
	     //stack_set_active_module_id(my_index, current_ilm.dest_mod_id);	 
#if (defined(G_SENSOR_SUPPORT) ) 	     
#ifndef WIN32	 
	     switch (current_ilm.msg_id)
	     {
	     	      case MSG_ID_GSENSOR_ON:
				 if( FlagWork == 0)
				{
					FlagWork = 1 ;
					SetGSensorSleepMode(FlagWork);
				  	if (  GSensorInitedFlag == 1  )
					{
						SendMessagesOneToOne(MSG_ID_GSENSOR_WORK);
		     	      		}		  		
				}
			  	break;
	             case MSG_ID_GSENSOR_WORK:				
				if( FlagWork == 1 )
				{
					if (  GSensorInitedFlag == 1  )
					{
					   	direction= GetDirection();				
						if( direction == 1)
						{
							SendMessagesOneToMMI(MSG_ID_GSENSOR_RIGHT);	
						}
						else if ( direction == 2)
						{
							SendMessagesOneToMMI(MSG_ID_GSENSOR_LEFT);					
						}
					}		

					if( SleepAtIdleScreen() != 1)
					{
						SendMessagesOneToOne(MSG_ID_GSENSOR_WORK);
					}
				}
				break;
			case MSG_ID_GSENSOR_OFF:
				 {
				 	FlagWork = 0 ;	
				 	SetGSensorSleepMode(FlagWork);
				}			
				break;
			default:
		       	  break;
	      }
#endif		 
#endif		 
    		free_ilm(&current_ilm); 
		kal_sleep_task(15);
    }		
}


/*************************************************************************
* FUNCTION
*  custom2_create
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
custom2_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct custom2_handler_info =
   {
      custom2_main,  /* task entry function */
      NULL,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&custom2_handler_info;
   return KAL_TRUE;
}


extern void HorseRaceThreadTask(void);
extern int  HorseRaceThreadTaskFlag(void);
extern int HorseRaceInitedFlag  ;

static void
custom2_main(task_entry_struct * task_entry_ptr)
{

	int flag = 0 ;
	ilm_struct current_ilm;
	kal_uint32 my_index;
	static int FlagWork = 0;

	//kal_get_my_task_index(&my_index);
   
	while ( 1 ) 
	{
	 
		receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
		//stack_set_active_module_id(my_index, current_ilm.dest_mod_id);	 

#if (defined(HORSERACE_SUPPORT) )		   
#ifndef WIN32
		switch (current_ilm.msg_id)
		{
			case MSG_ID_HORSERACE_ON:
				if( FlagWork == 0)
				{
					if (  HorseRaceInitedFlag == 1  )
					{
						FlagWork = 1 ;		
						SendMessagesTwoToTwo(MSG_ID_HORSERACE_WORK);						
					}
				}
				break;
			case MSG_ID_HORSERACE_WORK:				
				if(FlagWork == 1)
				{
					if (  HorseRaceInitedFlag == 1  )
					{ 
						flag = HorseRaceThreadTaskFlag() ;
						if( flag == 1 )
						{
							HorseRaceThreadTask();
						}
					}
					SendMessagesTwoToTwo(MSG_ID_HORSERACE_WORK);
				}
				break;
			case MSG_ID_HORSERACE_OFF:
				{
					FlagWork = 0 ;				 
				 	//Make Sure Power Off State
					if (  HorseRaceInitedFlag == 1  )
					{ 
						HorseRaceThreadTask();
					}
				}
				break;
			default:
				break;
		}	  
#endif		
#endif		
		free_ilm(&current_ilm); 	
		kal_sleep_task(800);
	}      
}

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_config.h content body
# return:      the body strings
#****************************************************************************
sub custom_config_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef _CUSTOM_CONFIG_H
#define _CUSTOM_CONFIG_H

#include "kal_non_specific_general_types.h"


/*************************************************************************
* Steps to add component task
*
* DESCRIPTION
*   The file describes steps to add component task.
*
*  1. add component task's index (Please add before system service)
*
*  2. add component task's module id definition (Please add before system service)
*
*  3. add module to task transformation in syscomp_config.c
*
*  4. add and implement component task's create handler
*
* GLOBALS AFFECTED
*
*************************************************************************/

/*************************************************************************
 * [Very Important Message]
 * 1. Component Task Index (Please add before system service)
 * 2. Customers are allowed to create at most 16 tasks as defined in 
 *    config\\include\\stack_config.h (MAX_CUSTOM_TASKS = 16)
 *************************************************************************/
typedef enum {
   INDX_CUSTOM1 = RPS_CUSTOM_TASKS_BEGIN,
   INDX_CUSTOM2,
   INDX_CUSTCMS,//05.10.18 pan add
   RPS_CUSTOM_TASKS_END
} custom_task_indx_type;

/*************************************************************************
 * [Very Important Message]
 * 1. Component task's module id (Please add before system service)
 * 2. Customers are allowed to create at most 16 task module ID as defined 
 *    in config\\include\\stack_config.h (MAX_CUSTOM_MODS = 16)
 *************************************************************************/
typedef enum {
   MOD_CUSTOM1 = MOD_CUSTOM_BEGIN,
   MOD_CUSTOM2,
   MOD_CMSMMS,//05.10.18 pan add
   MOD_CMSWAP,
   MOD_CMSMAP,
   MOD_CUSTOM_END
} custom_module_type;

/*************************************************************************
 * Other Declarations
 *************************************************************************/
extern custom_task_indx_type custom_mod_task_g[ MAX_CUSTOM_MODS ];

#endif /* _CUSTOM_CONFIG_H */

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_config.c content body
# return:      the body strings
#****************************************************************************
sub custom_config_c_file_body
{
    my ($global_mem_config_string, $ctrl_buff_pool_config_string) = &dispatch_globalmem_and_ctrlbuffpool;
    my $template = <<"__TEMPLATE";
/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "task_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "custom_MemoryDevice.h"
#include "system_inc.h"    /* include system_inc.h after including above header files */


#if defined(G_SENSOR_SUPPORT)
#define CUSTOM1_EXIST
#endif

#if defined(HORSERACE_SUPPORT)
#define CUSTOM2_EXIST
#endif

#ifdef CMS_NEW_APP
	#define CUSTCMS_EXIST
#endif

/*************************************************************************
 * External function declaration
 *************************************************************************/
extern kal_bool custom1_create(comptask_handler_struct **handle);
extern kal_bool custom2_create(comptask_handler_struct **handle);
//Jo++ 05-05-16	added //05.10.18 pan add for wap&mms
extern kal_bool customCMS_create(comptask_handler_struct **handle);
//Jo--

/*************************************************************************
* Global
*  custom_mod_task_g
*
* DESCRIPTION
*   module to task index mapping.
*   for example:
*      INDX_CUSTOM1 -> MOD_CUSTOM1
*   means module MOD_CUSTOM1 belongs to INDX_CUSTOM1 task
*
*   Please arrange the mapping according to custom_config.h custom_module_type
*   sequence.
*
* GLOBALS AFFECTED
*
*************************************************************************/
custom_task_indx_type custom_mod_task_g[ MAX_CUSTOM_MODS ] =
{
   INDX_CUSTOM1,        /* MOD_CUSTOM1 */
   INDX_CUSTOM2,        /* MOD_CUSTOM2 */
   //Jo++	05-05-16 added for MOD_MMS...//05.10.18 pan add for wap&mms
   INDX_CUSTCMS,		 /* MOD_CMSMMS	*/
   INDX_CUSTCMS,		 /* MOD_CMSWAP	*/
   INDX_CUSTCMS,		/* 	MOD_CMSMAP	*/
   //Jo--
  INDX_NIL             /* Please end with INDX_NIL element */
};

/*************************************************************************
* Global
*  custom_comp_config_tbl
*
* DESCRIPTION
*   The array contains system component tasks' configuration information
*
* GLOBALS AFFECTED
*
*************************************************************************/
const comptask_info_struct custom_comp_config_tbl[ MAX_CUSTOM_TASKS ] =
{
   /* INDX_CUSTOM1 */
   {"CUST1", "CUST1 Q", 210, 1024, 30, 100, 
#ifdef CUSTOM1_EXIST
   custom1_create, KAL_FALSE
#else   
   NULL, KAL_FALSE
#endif
   },

   /* INDX_CUSTOM2 */
   {"CUST2", "CUST2 Q", 211, 1024, 30, 100, 
#ifdef CUSTOM2_EXIST
   custom2_create, KAL_FALSE
#else
   NULL, KAL_FALSE
#endif
   },
   //Jo++ 05-05-16	added the Index_CustCMS//05.10.18 pan add for wap&mms
   /* INDX_CUSTCMS */
   {"CUSTCMS", "CUSTCMS Q", 212, 1024, 30, 100, 
#ifdef CUSTCMS_EXIST	//Jo++ 需事先定义
   customCMS_create, KAL_FALSE},
#else
   NULL, KAL_FALSE},
#endif
	//Jo--
};

/*************************************************************************
* FUNCTION
*  custom_configmem()
*
* DESCRIPTION
*   This routine configure 
*        
*   a. system total memory usage 
*      Task's stack, external queue, control buffer entries etc.
*      Any one who attempts to create new task or enlarge control
*      buffer size should fine tune the value!
*
*   b. system total debug memory usage 
*      Valid for DEBUG_KAL + DEBUG_[some items, ITC, BUF etc] 
*
* PARAMETERS
*        system_mem_sz       -        system all memory usage
*        debug_mem_sz        -        system all debug memory usage
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

$global_mem_config_string

static kal_uint32 System_Mem_Pool[GLOBAL_MEM_SIZE/sizeof(kal_uint32)];

#if defined(DEBUG_KAL)
static kal_uint32 Debug_Mem_Pool[GLOBAL_DEBUG_MEM_SIZE/sizeof(kal_uint32)];
#endif /* DEBUG_KAL */

void
custom_configmem(kal_uint32 *system_mem_sz, kal_uint32** system_mem_addr, 
                 kal_uint32 *debug_mem_sz,  kal_uint32** debug_mem_addr)
{
   *system_mem_sz   = GLOBAL_MEM_SIZE;
   *system_mem_addr = System_Mem_Pool;
   
#if defined(DEBUG_KAL)   
   *debug_mem_addr  = Debug_Mem_Pool;
   *debug_mem_sz    = GLOBAL_DEBUG_MEM_SIZE;
#else
   *debug_mem_addr  = (kal_uint32 *)0;
   *debug_mem_sz    = 0;
#endif
}


/*************************************************************************
* FUNCTION
*  custom_config_ctrl_buff_info()
*
* DESCRIPTION
*   This routine configure control buffer pool information (run time 
*   memory allocation usage)
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
custom_config_ctrl_buff_info(void)
{
$ctrl_buff_pool_config_string        
} 

/*************************************************************************
* FUNCTION
*  custom_config_task_stack_size
*
* DESCRIPTION
*  This function dedicates to specify one task's stack size.
*  Note: Each task's stack size is originally defined in the task 
*        configuration table (in sys_comp_config_tbl[]). When allocating 
*        stack for each task, system will invoke this function. If the 
*        return value is zero, system will use the original stack-size
*        setting for the task. Otherwise, system will use the return value 
*        as the task's stack size IF AND ONLY IF the return value is larger 
*        than the original settting.
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  Task's stack size (in bytes). Zero value implies that system uses
*  the original setting to allocate stack for the task.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_task_stack_size(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return a non-zero value for the task you are interesting.
    * For example,
    *    case INDX_MMI:
    *       // configure MMI's stack size as 8KB
    *       return 8096;
    */

#if defined(OBIGO_Q05A)
   case INDX_MMI:
   // en-large the MMI stack size to 26KB
      return (26 * 1024);
#endif /* OBIGO_Q05A */

   default:
      return 0;
   }

   return 0;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_extq_size
*
* DESCRIPTION
*  This function dedicates to specify one task's external queue size.
*  Note: Each task's external queue size is originally defined in the task 
*        configuration table (in sys_comp_config_tbl[]). When allocating 
*        queue for each task, system will invoke this function. If the 
*        return value is zero, system will use the original queue-size 
*        setting for the task. Otherwise, system will use the return value 
*        as the task's external queue size IF AND ONLY IF the return value 
*        is larger than the original settting.
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  Task's external queue size (number of entries). Zero value implies that
*  system uses the original setting to allocate queue for the task.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_task_extq_size(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return a non-zero value for the task you are interesting.
    * For example,
    *    case INDX_MMI:
    *       // configure MMI's external queue size as 40
    *       return 30;
    */

   default:
      return 0;
   }

   return 0;
}

/*************************************************************************
* FUNCTION
*  custom_config_evshed_pool_size
*
* DESCRIPTION
*  This function dedicates to specify larger pool size on event scheduler.
*
* PARAMETERS
*  void   -   
*
* RETURNS
*  evshed pool size (number of entries). Smaller value than default 
*  implies that system uses the original setting to allocate pool for event.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_evshed_pool_size(void)
{
#ifdef __SIP__
   return 160;
#else
   return 0;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_config_task_under_usb_boot
*
* DESCRIPTION
*  This function dedicates custom tasks present or not under usb boot mode
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  KAL_TRUE  : present on usb boot mode
*  KAL_FALSE : otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_config_task_under_usb_boot(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return true value for the custom task you are interesting.
    * For example,
    *    case INDX_CUSTOM1:
    *       return KAL_TRUE;
    */

   default:
      return KAL_FALSE;
   }

   return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_under_factory_boot
*
* DESCRIPTION
*  This function dedicates custom tasks present or not under factory boot mode
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  KAL_TRUE  : present on factory boot mode
*  KAL_FALSE : otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_config_task_under_factory_boot(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return true value for the custom task you are interesting.
    * For example,
    *    case INDX_CUSTOM1:
    *       return KAL_TRUE;
    */

   default:
      return KAL_FALSE;
   }

   return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_stack_location
*
* DESCRIPTION
*  This function will re-configure task stack location (INTSRAM/EXTSRAM)
*  Original configuration in config.lib will be overwritten.
*  XXX PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  task_info_g
*
*************************************************************************/
void custom_config_task_stack_location(void)
{
#ifdef __SYS_INTERN_RAM__
   /* DCM_ENABLE feature ON/OFF
    * IDLE task have to put in internal SRAM when DCM_ENABLE ON
    */
   #if defined(DCM_ENABLE)
      task_info_g[ INDX_IDLE ].task_internal_ram_stack = KAL_TRUE;
   #endif /* DCM_ENABLE */
#endif /* __SYS_INTERN_RAM__ */
   return;
}

/*************************************************************************
* FUNCTION
*  custom_get_task_module()
*
* DESCRIPTION
*  This routine returns the number of customer tasks and modules.
*
* PARAMETERS
*  Pointer of 8-bits unsigned integer used to return the value.
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void 
custom_get_task_module(kal_uint8 *custom_task, kal_uint8 *custom_module)
{
   *custom_task = RPS_CUSTOM_TASKS_END - RPS_CUSTOM_TASKS_BEGIN;
   *custom_module = MOD_CUSTOM_END - MOD_CUSTOM_BEGIN;
}

/*************************************************************************
* FUNCTION
*  remap_mod_task_g
*
* DESCRIPTION
*  This function will remap module to new task at initialization stage.
*  Original configuration in config.lib will be overwritten.
*  XXX PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  mod_task_g
*
*************************************************************************/
void remap_mod_task_g(void)
{
#if defined(JATAAYU_SUPPORT) || defined(OBIGO_Q05A)
   mod_task_g[MOD_WAP] = INDX_MMI;
#endif
   return;
}

/*************************************************************************
* FUNCTION
*  customization_check
*
* DESCRIPTION
*  Checking system customization, including number of tasks, modules,
*  message ID and SAP.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
customization_check(void)
{
   /* Check if customer tasks exceeding limitation */
   if ( (RPS_CUSTOM_TASKS_END - RPS_CUSTOM_TASKS_BEGIN) > MAX_CUSTOM_TASKS )
      kal_fatal_error_handler((kal_char*)"Customer creates too many tasks",
                              KAL_ERROR_CUSTOMER_TASK_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(RPS_CUSTOM_TASKS_BEGIN-RPS_CUSTOM_TASKS_END)
                             );
                             
   /* Check if customer module ID exceeding limitation */
   if ( (MOD_CUSTOM_END - MOD_CUSTOM_BEGIN) > MAX_CUSTOM_TASKS )
      kal_fatal_error_handler((kal_char*)"Customer defines too many module IDs",
                              KAL_ERROR_CUSTOMER_MOD_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(MOD_CUSTOM_END - MOD_CUSTOM_BEGIN)
                             );
                             
   /* Check if customer message ID exceeding limitation */
   if ( (MSG_ID_END - CUSTOM_MSG_CODE_BEGIN) > MAX_CUSTOM_MESSAGE_ID )
      kal_fatal_error_handler((kal_char*)"Customer define too many message IDs",
                              KAL_ERROR_CUSTOMER_MEESAGE_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(MSG_ID_END - CUSTOM_MSG_CODE_BEGIN)
                             );
                          
   /* Check if customer tasks exceeding limitation */
   if ( (LAST_SAP_CODE - CUSTOM_SAP_BEGIN - 1) > MAX_CUSTOM_SAP_ID )
      kal_fatal_error_handler((kal_char*)"Customer defines too many SAPs",
                              KAL_ERROR_CUSTOMER_SAP_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(LAST_SAP_CODE - CUSTOM_SAP_BEGIN - 1)
                             );
}

/*************************************************************************
* FUNCTION
*  custom_config_mod_task_g()
*
* DESCRIPTION
*   This routine process custom module to global module to task mapping 
*   relation. XXX. PLEASE DON'T EDIT THE FUNCTION.
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
custom_config_mod_task_g(void)
{
   kal_uint32 i;

   for (i = 0; i < MAX_CUSTOM_MODS; i++) {
      if ((task_indx_type)custom_mod_task_g[i] == INDX_NIL)
         break;

      mod_task_g[i + MOD_CUSTOM_BEGIN] = (task_indx_type)custom_mod_task_g[i];
   }
}

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate fs_config.c content body
# return:      the body strings
#****************************************************************************
sub fs_config_c_file_body
{
    my $drive_num     = &dispatch_drivenum();
    my $buffer_num    = &dispatch_buffnum();
    my $fh_num        = &dispatch_fhnum();
    my $maxthread_num = &dispatch_threadnum();
    my $template = <<"__TEMPLATE";
#ifndef _KAL_RELEASE_H
#include "kal_release.h"
#endif

#ifndef _FS_RELEASE_H
#include "fat_fs.h"
#endif

   /* IMPORT DEVICE DRIVER and DRIVER DATA */
#include "drvflash.h"
extern NOR_FLASH_DRV_Data  FlashDriveData;
extern FS_Driver NORFlashDriver;

#ifdef NAND_SUPPORT
#include "NAND_FDM.h"
extern NAND_FLASH_DRV_DATA  NANDFlashDriveData;
extern FS_Driver NANDFlashDriver;
#endif

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
#include "msdc_def.h"
extern FS_Driver FS_MsDrv;
extern FS_Driver FS_SdDrv;
extern FS_Driver FS_MspDrvAll;
extern FS_Driver FS_SdDrv2;
#endif

#ifdef __OTG_ENABLE__
#include "usb_host_ms_adap.h"
extern kal_uint8 USBHost_Media_Handle[];
extern FS_Driver FS_OTGDrv;
#endif

   /* EXTRA DRIVE/FILEHANDLE NUM Declaration */
#ifdef __OTG_ENABLE__

#ifdef __SIM_PLUS__
#define EXTRA_DRIVE_NUM (4 + 1)
#else
#define EXTRA_DRIVE_NUM (4)
#endif

#else /* __OTG_ENABLE__ */

#ifdef __SIM_PLUS__
#define EXTRA_DRIVE_NUM (1)
#else
#define EXTRA_DRIVE_NUM (0)
#endif

#endif /* __OTG_ENABLE__ */

#ifdef __J2ME__
#include "j2me_custom.h"
#if (defined(J2ME_JSR_75_FILE_HANDLER_RESERVE_COUNT))
#define EXTRA_FH_NUM    (J2ME_JSR_75_FILE_HANDLER_RESERVE_COUNT)
#else
#define EXTRA_FH_NUM	(0)
#endif
#else /* __J2ME__ */
#define EXTRA_FH_NUM	(0)
#endif /* __J2ME__ */

/************************ User Configuration ************************/
/* The nubmer of drive in file system: EXTERNAL_DRIVE_NUM + X; 1 <= X <= 5 */ 
//Each one of the defined device (NOR, NAND, Card, External) should has at least one drive.
//If partition is applied on the device, one more drive should be allocated.
//EXTERNAL_DRIVE_NUM: number of drive for USB OTG External, don't remove
const UINT FS_MAX_DRIVES = EXTRA_DRIVE_NUM + $drive_num;

/* The number of buffer in file system:  X >= 1 */
const UINT FS_MAX_BUFFERS = $buffer_num;

/* The number of file handle in file system: EXTRA_FH_NUM + X;
 * EXTRA_FH_NUM: number of file handle for downloadable application, don't remove
 * X >=  4 #if GSM
 * X >= 16 #if GPRS
 * Recommend Value For General Case: 24  # modify this value to best fit your case
 *
 *      24 =  9 (foreground app.) + 12 (basic background app. worst case) + 3 (optional)
 * 
 * Table of Background File Handle Usage by optional application/feature
 * { 4,  BlueTooth FTP + OPP profile },
 * { 1,  IRDA Support                },
 * { 1,  DT Support (Phone Suite)    },
 * { 2,  IMPS                        },
 * { 1,  EMail                       },
 * { 1,  POC                         },
 * { 1,  SIP                         },
 */
const UINT FS_MAX_FILES = EXTRA_FH_NUM + $fh_num;

/* The number of tasks that will use file system: X >=  5 #if GSM
 *                                                X >= 10 #if GPRS
 * Default Value: 22 (GPRS), 26 (EDGE)
 * Common {NVRAM, MMI, MED, FMT, WAP, WPS, L4, L1AUDIO}
 * Discount 1 per feature OFF to optimize
 * {BLUETOOTH, DT, EMAIL, GDC, GDD, IMPS, JAVA, POC, SIP, XDM}
 * {VOIP, DHCP, TFTP, SAF, SUPC, RTSP, DM, DRMT}
 */
const UINT FS_MAX_THREAD = $maxthread_num;

/* The max number of continuous cluster for copy iteration
 *
 * Default value: 128 , 32 (MT6223P)
 */
#if defined(MT6223P)
const UINT FS_MAX_COPY_CLUSTER =  32;
#else /* MT6223P */
const UINT FS_MAX_COPY_CLUSTER = 128;
#endif /* MT6223P */

#if (defined __FS_SYSDRV_ON_NAND__) && !(defined _NAND_FLASH_BOOTING_)
        /* Treat __FS_SYSDRV_ON_NAND__ equal _NAND_FLASH_BOOTING_ */
#define _NAND_FLASH_BOOTING_
#endif

#ifdef _NAND_FLASH_BOOTING_
/* The size of sanity check buffer in byte */
/* It's for system drive on NAND flash booting type project */
/* If the size is not big enough, it will assert when booting up */
const UINT FS_MAX_CHECK_BUFFER = 5*1024;
#else
const UINT FS_MAX_CHECK_BUFFER = 4;
#endif

/* Device List Configuration */
FS_Device gFS_DeviceList[] = {
#ifndef _NAND_FLASH_BOOTING_
	{FS_DEVICE_FDISK, 0, FS_DEVICE_NOR_FLASH, &NORFlashDriver, (void *)&FlashDriveData, NULL},
#endif

#ifdef NAND_SUPPORT
	{FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&NANDFlashDriveData, NULL},
#endif

#ifdef __MSDC_MS__
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_MsDrv, (void *)&gMSDC_Handle, NULL},
#elif (defined __MSDC_SD_MMC__)
	#if defined(__SIM_PLUS__)
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[SD_EXT], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_SIMPLUS  , &FS_SdDrv, (void *)&MSDC_Blk[SD_SIM], NULL},
        #elif defined(__MSDC2_SD_MMC__)
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv , (void *)&MSDC_Blk[0], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv2, (void *)&MSDC_Blk[1], NULL},
	#else
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[0], NULL},	
	#endif		
#elif (defined __MSDC_MSPRO__)
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_CHECK_PART
                           | FS_DEVICE_MEMORY_STICK, &FS_MspDrvAll, (void *)&gMSDC_Handle, NULL},
#endif 
#ifdef __OTG_ENABLE__
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[0], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[1], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[2], NULL},
	{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[3], NULL},
#endif
   { 0, 0, 0, 0, 0, 0 }    // end of list marker
};

/************* Do not modify anything behind this line *************/
FS_Drive          gFS_DriveTable[FS_MAX_DRIVES];
FS_File           gFS_FileTable[FS_MAX_FILES];
FS_Buffer         gFS_BufferTable[FS_MAX_BUFFERS];
BYTE              gFS_BufferData[FS_MAX_BUFFERS * FS_BUFFER_SIZE];
kal_taskid        gFS_TaskList[FS_MAX_THREAD];
FS_ExceptionData* gFS_TaskData[FS_MAX_THREAD][MAX_TLS_INDEX];

#ifdef __FS_TRACE_SUPPORT__
kal_bool          gFS_TraceTask[FS_MAX_THREAD][FS_TRACE_INDEX] = {KAL_FALSE, KAL_FALSE};
#endif

BYTE              gFS_SanityCheckBuffer[FS_MAX_CHECK_BUFFER];
const int         gFS_DeviceNumOfSYSDRV = 1;

FS_Tables gFS_Data  = 
{ 
   gFS_DriveTable,
   gFS_FileTable,
   gFS_BufferTable,
   gFS_BufferData 
};

__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_jump_tbl.h content body
# return:      the body strings
#****************************************************************************
sub custom_jump_tbl_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef _CUSTOM_JUMP_TBL_H_
#define _CUSTOM_JUMP_TBL_H_

#if ( (defined(__MTK_TARGET__) || defined (MTK_KAL_MNT) || defined(KAL_ON_OSCAR) ) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) ) 

#include "kal_release.h"
#include "resource_verno.h"

extern const Type_Preamble_Content system_jump_table[];

//__CUSTPACK_MULTIBIN
typedef enum 
{
   JUMP_TABLE_ENTRY_START, 
   
   JUMP_TABLE_ENTRY_LANG_PACK = JUMP_TABLE_ENTRY_START, 
   JUMP_TABLE_ENTRY_CUSTPACK,
   JUMP_TABLE_ENTRY_AUTOGEN_AUDIO,
   JUMP_TABLE_ENTRY_END = JUMP_TABLE_ENTRY_CUSTPACK

} JUMP_TABLE_ENTRY_ENUM;


#define JUMP_TABLE_ENTRY_END              JUMP_TABLE_ENTRY_CUSTPACK


/* Macros for addressing each resource */
#define GET_Res_Addr(R, X)                (((kal_uint32 *) (system_jump_table[R].StartAddress)) + X)
#define GET_Res_ProjectID(X)              (system_jump_table[X].ProjectID)
#define GET_Res_Magic(X)                  (system_jump_table[X].Magic)


#if defined(MULTIPLE_BINARY_FILES) && defined(__MTK_TARGET__)


extern Type_Preamble_Content AudioResPreamble;
extern void* audio2ndJumpTbl[];

extern Type_Preamble_Content AutogenAudioResPreamble;
extern void* autogenaudio2ndJumpTbl[];

extern Type_Preamble_Content ImageResPreamble;
extern void* image2ndJumpTbl[];

#ifdef __J2ME__
extern Type_Preamble_Content J2MEResPreamble;
extern void* J2ME2ndJumpTbl[];
#endif /*__J2ME__*/

#define CONST_RES_IMAGE_ADDR              ((kal_uint32 *)&ImageResPreamble)
#define CONST_RES_IMAGE_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_IMAGE_CONTENT_SIZE      ((kal_uint32)0)
#define CONST_RES_AUDIO_ADDR              ((kal_uint32 *)&AudioResPreamble)
#define CONST_RES_AUDIO_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_AUDIO_CONTENT_SIZE      ((kal_uint32)0)

#define CONST_RES_AUTOGEN_AUDIO_ADDR              ((kal_uint32 *)&AutogenAudioResPreamble)
#define CONST_RES_AUTOGEN_AUDIO_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_AUTOGEN_AUDIO_CONTENT_SIZE      ((kal_uint32)0)

#ifdef __J2ME__
#define CONST_RES_J2ME_ADDR               ((kal_uint32 *)&J2MEResPreamble)
#define CONST_RES_J2ME_TBL_SIZE           ((kal_uint32)0)
#define CONST_RES_J2ME_CONTENT_SIZE       ((kal_uint32)0)
#endif /*__J2ME__*/  


/* Macros below specific for multiple binary files or multiple load segments only */
/* Collection of Lang Pack */
extern kal_uint32  Load\$\$LANG_PACK_ROM\$\$Base;
extern kal_uint32  Image\$\$LANG_PACK_ROM\$\$Length;
extern kal_uint32  Image\$\$LANG_PACK_ROM_CONTENT\$\$Length;

//__CUSTPACK_MULTIBIN__
extern kal_uint32  Load\$\$CUSTPACK_ROM\$\$Base;
extern kal_uint32  Image\$\$CUSTPACK_ROM\$\$Length;
extern kal_uint32  Image\$\$CUSTPACK_ROM_CONTENT\$\$Length;


/* macro of resource address and size for const arrary initialization */
#define GET_ResLangPack_Addr(X)           GET_Res_Addr(JUMP_TABLE_ENTRY_LANG_PACK, X)
#define CONST_RES_LANG_PACK_ADDR          (&Load\$\$LANG_PACK_ROM\$\$Base)
#define CONST_RES_LANG_PACK_TBL_SIZE      ((kal_uint32)&Image\$\$LANG_PACK_ROM\$\$Length)
#define CONST_RES_LANG_PACK_CONTENT_SIZE  ((kal_uint32)&Image\$\$LANG_PACK_ROM_CONTENT\$\$Length)


//__CUSTPACK_MULTIBIN__
#define GET_ResCUSTPACK_Addr(X)           GET_Res_Addr(JUMP_TABLE_ENTRY_CUSTPACK, X)
#define CONST_RES_CUSTPACK_ADDR           (&Load\$\$CUSTPACK_ROM\$\$Base)
#define CONST_RES_CUSTPACK_TBL_SIZE       ((kal_uint32)&Image\$\$CUSTPACK_ROM\$\$Length)
#define CONST_RES_CUSTPACK_CONTENT_SIZE   ((kal_uint32)&Image\$\$CUSTPACK_ROM_CONTENT\$\$Length)



#else /* MULTIPLE_BINARY_FILES && __MTK_TARGET__ */

extern Type_Preamble_Content AudioResPreamble;
extern void* audio2ndJumpTbl[];
extern Type_Preamble_Content AutogenAudioResPreamble;
extern void* autogenaudio2ndJumpTbl[];
extern Type_Preamble_Content ImageResPreamble;
extern void* image2ndJumpTbl[];
extern Type_Preamble_Content LangPackResPreamble ;
extern void* langpack2ndJumpTbl[];

#ifdef __J2ME__
extern Type_Preamble_Content J2MEResPreamble;
extern void* J2ME2ndJumpTbl[];
#endif /*__J2ME__*/

extern Type_Preamble_Content CustPackResPreamble ;
extern void* custpack2ndJumpTbl[];


#define CONST_RES_IMAGE_ADDR                   ((kal_uint32 *)&ImageResPreamble)
#define CONST_RES_IMAGE_TBL_SIZE               ((kal_uint32)0)
#define CONST_RES_IMAGE_CONTENT_SIZE           ((kal_uint32)0)
#define CONST_RES_AUDIO_ADDR                   ((kal_uint32 *)&AudioResPreamble)
#define CONST_RES_AUDIO_TBL_SIZE               ((kal_uint32)0)
#define CONST_RES_AUDIO_CONTENT_SIZE           ((kal_uint32)0)
#define CONST_RES_AUTOGEN_AUDIO_ADDR           ((kal_uint32 *)&AutogenAudioResPreamble)
#define CONST_RES_AUTOGEN_AUDIO_TBL_SIZE       ((kal_uint32)0)
#define CONST_RES_AUTOGEN_AUDIO_CONTENT_SIZE   ((kal_uint32)0)
#define CONST_RES_LANG_PACK_ADDR               ((kal_uint32 *)&LangPackResPreamble)
#define CONST_RES_LANG_PACK_TBL_SIZE           ((kal_uint32)0)
#define CONST_RES_LANG_PACK_CONTENT_SIZE       ((kal_uint32)0)
#define CONST_RES_CUSTPACK_ADDR                ((kal_uint32 *)&CustPackResPreamble)
#define CONST_RES_CUSTPACK_TBL_SIZE            ((kal_uint32)0)
#define CONST_RES_CUSTPACK_CONTENT_SIZE        ((kal_uint32)0)

#ifdef __J2ME__
#define CONST_RES_J2ME_ADDR                    ((kal_uint32 *)&J2MEResPreamble)
#define CONST_RES_J2ME_TBL_SIZE                ((kal_uint32)0)
#define CONST_RES_J2ME_CONTENT_SIZE            ((kal_uint32)0)
#endif /*__J2ME__*/


#define GET_ResImage_Addr(X)                   ((kal_uint32 *)&image2ndJumpTbl)
#define GET_ResAudio_Addr(X)                   ((kal_uint32 *)&audio2ndJumpTbl)
#define GET_ResAutogenAudio_Addr(X)            ((kal_uint32 *)&autogenaudio2ndJumpTbl)
#define GET_ResFont_Addr(X)                    ((kal_uint32 *)&font2ndJumpTbl)
#define GET_ResStr_Addr(X)                     ((kal_uint32 *)&str2ndJumpTbl)
#define GET_ResIME_Addr(X)                     ((kal_uint32 *)&IME2ndJumpTbl)
#define GET_ResLangPack_Addr(X)                ((kal_uint32 *)&langpack2ndJumpTbl)
#define GET_ResCUSTPACK_Addr(X)                ((kal_uint32 *)&custpack2ndJumpTbl)

#ifdef __J2ME__
#define GET_ResJ2ME_Addr(X)                    ((kal_uint32 *)&J2ME2ndJumpTbl)
#endif /*__J2ME__*/


#endif /* MULTIPLE_BINARY_FILES && __MTK_TARGET__ */

#endif /* (__MTK_TARGET__ || MTK_KAL_MNT || KAL_ON_OSCAR) && (!__MAUI_BASIC__) && (!__L1_STANDALONE__) */

#endif /* _CUSTOM_JUMP_TBL_H_ */
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_jump_tbl.c content body
# return:      the body strings
#****************************************************************************
sub custom_jump_tbl_c_file_body
{
    my $template = <<"__TEMPLATE";
#if ( (defined(__MTK_TARGET__) || defined (MTK_KAL_MNT) || defined(KAL_ON_OSCAR) ) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) ) 

#include "custom_jump_tbl.h"
#include "verno.h"

/* __CUSTPACK_MULTIBIN */

const Type_Preamble_Content  system_jump_table[8] = { 
   /* Language Pack */
   { VERNO_STR,
     (kal_uint32)(RESOURCE_TYPE_LANG_PACK + CURRENT_LANG_PACK_RES_VERSION), 
     CONST_RES_LANG_PACK_ADDR,
     CONST_RES_LANG_PACK_TBL_SIZE,
     CONST_RES_LANG_PACK_CONTENT_SIZE, 
     (kal_uint32)MAGIC_NUMBER
   },
   /*__CUSTPACK_MULTIBIN__ */
   { VERNO_STR,
     (kal_uint32)(RESOURCE_TYPE_CUSTPACK+CURRENT_CUSTPACK_RES_VERSION),
     CONST_RES_CUSTPACK_ADDR,
     CONST_RES_CUSTPACK_TBL_SIZE,
     CONST_RES_CUSTPACK_CONTENT_SIZE,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   }
}; 

#endif
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_fota.h content body
# return:      the body strings
#****************************************************************************
sub custom_fota_h_file_body
{
    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_FOTA_H__
#define __CUSTOM_FOTA_H__

/*****************************************
 * Don't modify any code above this line *
 *****************************************/

/*******************************************************************************
   Follow the 5 steps below to configure flash memory for FOTA
   
   Step 1. Modify the sub file name of compressed image file, the file name format
           is [A-Z] and maximum length is 3

   Step 2. Modify the value of FOTA_ORIGINAL_BASE_ADDRESS, which is the MAUI start 
           address of FOTA project, this value need "erase unit aligned" and must be
           greater than firmware udpate engine image size
           
   Step 3. Modify the value of FOTA_SPARE_BASE_ADDRESS, which is spare image pool start
           address
           
   Step 4. Modify the value of FOTA_SPARE_ALLOCATED_SIZE, which is the size of spare image
           pool reserved for downloading compressed image
                          
   Step 5. Fill the flash erase unit information table, each element records the memory 
           space that contains continuous erase uints of equal size. Each element
           in the table is the format as below:
           {S_EU, N_EU}   
               S_EU: the size of erase unit 
               N_EU: the number of sectors
               
           EX1: {0x40000, 128}
           EX2: {0x2000,8},{0x10000,31}
      
        
   Note : Code region and spare image pool region can not share the same bank (partition)
*******************************************************************************/

/***********
 * Step 1. *
 ***********/
#define FMGR_TYPE_FOTA_FULL_EXT_NAME "xxx"   /* [A-Z] Max len: 3 */

/***********
 * Step 2. *
 ***********/
#define FOTA_ORIGINAL_BASE_ADDRESS x

/***********
 * Step 3. *
 ***********/
#define FOTA_SPARE_BASE_ADDRESS x

/***********
 * Step 4. *
 ***********/
#define FOTA_SPARE_ALLOCATED_SIZE x

/***********
 * Step 5. *
 ***********/
#define CUSTOM_FLASH_INFO {x, x}

/*****************************************

 * Don't modify any code below this line *
 *****************************************/
#if defined(__MTK_TARGET__)
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
extern FlashRegionInfo NORRegionInfo[];
#else
extern const FlashRegionInfo NORRegionInfo[];
#endif
#endif

extern kal_int32 FOTA_CustomInitialize(void);

#endif /*__CUSTOM_FOTA_H__*/
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_fota.h content body
# return:      the body strings
#****************************************************************************
sub custom_fota_c_file_body
{
    my $template = <<"__TEMPLATE";
/*******************************************
*   Customization Part      
********************************************/
#ifdef __MTK_TARGET__

#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "kal_release.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "fota.h"
#include "custom_fota.h"

#ifdef __FOTA_ENABLE__

#ifdef _LOW_COST_SINGLE_BANK_FLASH_
FlashRegionInfo NORRegionInfo[] =
#else /* _LOW_COST_SINGLE_BANK_FLASH_ */
const FlashRegionInfo NORRegionInfo[] =
#endif
{
   CUSTOM_FLASH_INFO,
   EndRegionInfo /* Don't modify this line */
};

/* ---------------------------------------------------------------------------------
DESCRIPTION
   FOTA Customization Initialization API
	FOTA_Initialize() will call this function, this is for customization.
	User can register their own customized authentication or 
	decryption function in this function
PARAMETER
	NULL
RETURN
	0: means pass initialization step (ERROR_FOTA_SUCCESS)
	< 0: means fail
	   ERROR_FOTA_CUSTOMIZATION: customization error
--------------------------------------------------------------------------------- */
kal_int32 FOTA_CustomInitialize(void)
{
   kal_uint32 AddrLowBound=0, AddrUpperBound  = 0;
   kal_uint32 region = 0, StartBlkIndex = 0;

   FOTAData.SpareBaseAddr = FOTAData.FlashBaseAddr + FOTA_SPARE_BASE_ADDRESS;
   FOTAData.OriginalBaseAddr = FOTAData.FlashBaseAddr + FOTA_ORIGINAL_BASE_ADDRESS;
   FOTAData.TotalFOTALength = FOTA_SPARE_ALLOCATED_SIZE;
   FOTAData.NORRegionInfo = (FlashRegionInfo *)NORRegionInfo;
   FOTAData.SpareCurrAddr = FOTAData.SpareBaseAddr;
   FOTAData.NextBlockAddr = FOTAData.SpareBaseAddr;
   
   /*calculate the start block index*/
   AddrUpperBound = NORRegionInfo[0].RegionBlocks * NORRegionInfo[0].BlockSize;
   
   do{
      if (AddrUpperBound >= FOTA_SPARE_BASE_ADDRESS)
         break;
      else
      {
         StartBlkIndex += NORRegionInfo[region].RegionBlocks;
         region++;
         AddrLowBound = AddrUpperBound;
         AddrUpperBound = NORRegionInfo[region].RegionBlocks * NORRegionInfo[region].BlockSize;
      }
   }while(NORRegionInfo[region].RegionBlocks != 0);

   if(NORRegionInfo[region].RegionBlocks == 0 || (FOTA_SPARE_BASE_ADDRESS - AddrLowBound)\%NORRegionInfo[region].BlockSize !=0)
   {
      return ERROR_FOTA_CUSTOMIZATION;
   }
   FOTAData.SpareStartBlkIndex = StartBlkIndex + (FOTA_SPARE_BASE_ADDRESS - AddrLowBound)/NORRegionInfo[region].BlockSize;

   /*register private authentication function or encryption function */
   FOTA_Reg_Auth((CALLBACK_Auth_FUNC)NULL);
   FOTA_Reg_Decrypt((CALLBACK_Decrypt_FUNC)NULL);
   
   return 0;
   
}
#endif /*__FOTA_ENABLE__*/
#endif
__TEMPLATE

   return $template;
}

#****************************************************************************
# subroutine:  generate custom_nor_large_disk.c content body
# return:      the body strings
#****************************************************************************
sub custom_nor_large_disk_c_file_body
{
    my $template = <<"__TEMPLATE";
#include "custom_MemoryDevice.h"
#include "kal_release.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "flash_opt.h"

#ifdef __NOR_FDM5__

#define STORAGE_NO_PARTITION 0xFFFFFFFF

/*****************************************
 * Don't modify any code above this line *
 *****************************************/

/*******************************************************************************
   Follow the 6 steps below to configure flash memory for FAT
   
   Step 1. Modify the value of FLASH_BASE_ADDRESS, which is the starting address
           of the flash memory allocated for FAT

   Step 2. Modify the value of ALLOCATED_FAT_SPACE, which is the total flash
           space allocated for FAT
           
   Step 3. Modify the value of Block size 
           
   Step 4. Fill the flash bank (partition) information table,
           flash device features flexible, multi-bank read-while-program and 
           read-while-erase capability, enabling background programming or erasing in 
           one bank simultaneously with code execution or data reads in another bank.
           Each element in the table is the format as below:
           {bank size, bank number},   
                          
   Step 5. Modify the value of LSMT, you can see MemoryDevice_FlashDisk_FAQ for 
           detail information
      
   Step 6: Define the toal sectors (512bytes) of system drive
           the remainder is the size of public drive
           If there is no partiton (just one drive, system drive)
           set this value to STORAGE_NO_PARTITION (0xFFFFFFFF) 
 
           
   Note : Code region and FAT region can not share the same bank (partition)
*******************************************************************************/



/***********
 * Step 1. *
 ***********/
#define FLASH_BASE_ADDRESS x

/***********
 * Step 2. *
 ***********/
#define ALLOCATED_FAT_SPACE x

/***********
 * Step 3. *
 ***********/
#define NOR_BLOCK_SIZE x

/***********
 * Step 4. *
 ***********/
static NORBankInfo BankInfo[] =
{
   {x,x},
   EndBankInfo /* Don't modify this line */
};

/***********
 * Step 5. *
 ***********/
#define NOR_TOTAL_LSMT x

/***********
 * Step 6. *
 ***********/
#define NOR_SYSDRV_SECTORS x


/*****************************************
 * Don't modify any code below this line *
 *****************************************/

#define NOR_TOTAL_BLOCKS (ALLOCATED_FAT_SPACE/NOR_BLOCK_SIZE)
#define NOR_TOTAL_TABLE_BLOCKS 32
NOR_FTL_DATA  FlashDriveData;
static NORLayoutInfo LayoutInfo;

#ifndef __INTEL_SIBLEY__

#define NOR_PAGE_SIZE 512

FS_Driver NORFlashDriver = {
   nNOR_MountDevice,
   nShutDown,
   nNOR_ReadSectors,
   nNOR_WriteSectors,
   NOR_MediaChanged,
   nNOR_DiscardSectors,
   nGetDiskGeometry,
   nNOR_LowLevelFormat,
   nNOR_NonBlockWriteSectors,
   nNOR_RecoverableWriteSectors,
   nNOR_ResumeSectorStates,
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

#define NOR_PAGE_SIZE 1024

FS_Driver NORFlashDriver = {
   nSIB_MountDevice,
   nShutDown,
   nSIB_ReadSectors,
   nSIB_WriteSectors,
   NOR_MediaChanged,
   nSIB_DiscardSectors,
   nGetDiskGeometry,
   nSIB_LowLevelFormat,
   nSIB_NonBlockWriteSectors,
   nSIB_RecoverableWriteSectors,
   nSIB_ResumeSectorStates,
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
#endif /*__INTEL_SIBLEY__*/


static kal_uint16  NOR_LBM[NOR_TOTAL_BLOCKS];
static LSMGEntry   NOR_LSMG[NOR_TOTAL_LSMT]; // need to check in the program
static kal_uint16  NOR_AvailInBlk[NOR_TOTAL_BLOCKS];
static kal_uint16  NOR_InvaildInBlk[NOR_TOTAL_BLOCKS];
static kal_uint32  NOR_InvalidEntryInTblBlk[NOR_TOTAL_TABLE_BLOCKS];
static kal_uint8 FDMBuffer[NOR_PAGE_SIZE];
static kal_uint8 CopyBuffer[NOR_PAGE_SIZE];
static NOR_MTD_DATA mtdflash;
kal_eventgrpid  nor_egid = NULL;

extern NOR_MTD_Driver NORFlashMtd;
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);



void Initialize_FDD_tables(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )
   	/* Initialize MTD data table */
   mtdflash.Signature = ~((kal_uint32)&LayoutInfo);

#ifdef __MTK_TARGET__
   mtdflash.BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + FLASH_BASE_ADDRESS);
#endif
   LayoutInfo.BankInfo = BankInfo;
   LayoutInfo.TotalBlks = NOR_TOTAL_BLOCKS;
   LayoutInfo.BlkSize = NOR_BLOCK_SIZE;
   LayoutInfo.PageSize = NOR_PAGE_SIZE;
   LayoutInfo.TotalLSMT= NOR_TOTAL_LSMT;
   mtdflash.LayoutInfo = (NORLayoutInfo *)&LayoutInfo;

   /* Initialize FDD data table */
   FlashDriveData.MTDDriver = &NORFlashMtd;
   FlashDriveData.MTDData = &mtdflash;
   FlashDriveData.LBM = NOR_LBM;
   FlashDriveData.LSMG = NOR_LSMG;
   FlashDriveData.AvailInBlk = NOR_AvailInBlk;
   FlashDriveData.InvalidInBlk = NOR_InvaildInBlk;
   FlashDriveData.InvalidEntryInTblBlk = NOR_InvalidEntryInTblBlk;
   FlashDriveData.SecondPartitionSectors = NOR_SYSDRV_SECTORS;
   FlashDriveData.SetTblBlks = NOR_TOTAL_TABLE_BLOCKS;
   FlashDriveData.Buffer = FDMBuffer;
   FlashDriveData.CopyBuffer = CopyBuffer;
#ifndef __INTEL_SIBLEY__
   FlashDriveData.ReclaimBlock = nNOR_ReclaimBlock;
#else
   FlashDriveData.ReclaimBlock = nSIB_ReclaimBlock;
#endif /* __INTEL_SIBLEY__ */
#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
}

#endif /*__NOR_FDM5__*/
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
