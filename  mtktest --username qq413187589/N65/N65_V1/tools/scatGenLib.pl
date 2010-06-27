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
#*   scatGenLib.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script designed as module to be include by top level perl script
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
#****************************************************************************/
use strict;

my  $feature_query_function_ptr;
my  $norflash_info_href;
1;

#****************************************************************************
# MAIN INTERFACE
# input: 
#          arg1 : a function pointer to query feature 
#          arg2 : base band chip
#          arg3 : a hash reference to query flash geometry
#          arg4 : ram size
#****************************************************************************
sub scatGen_main
{
    my ($func, $bb, $flash_href, $rs) = @_;
    $feature_query_function_ptr = $func;
    $norflash_info_href         = $flash_href;

    my $nfb      = &$func('nand_flash_booting');
    my $multibin = &$func('multiple_binary_files');
    my $security = &$func('secure_support');
    my $fota     = &$func('fota_enable');
    my $usbdl    = &$func('usb_download');

    # Layout configuration
    &config_setup($bb);
    my $flash_size   = $flash_href->{'AVAILABLE_SIZE'};

    # SW Feature dispatch decision tree
    my $output_result;

    if    ($nfb eq 'TRUE')
    {
        # NAND FLASH BOOTING (Phase 1)
        if (defined $usbdl and $usbdl ne 'NONE')
        {
           print "Feature Combination : NFB + USBDL\n";
           return undef; # And output error 
        }

        if (defined $fota and $fota ne 'NONE')
        {
           print "Feature Combination : NFB + FOTA\n";
           return undef; # And output error 
        }

        # NAND FLASH BOOTING (Phase 2)
        $output_result .= &layout1($bb, undef, $rs);
    }
    else
    {
        # NOR TRADITIONAL BOOTING (Phase 1)
        if (defined $usbdl and $usbdl ne 'NONE')
        {
            $output_result .= &layout4($bb);
        }

        if (defined $fota and $fota ne 'NONE')
        {
           print "Feature Combination : FOTA\n";
           return undef; # And output error 
        }

        # NOR TRADITIONAL BOOTING (Phase 2)
        if ($multibin eq 'TRUE')
        {
            $output_result .= &layout2($bb, $flash_size, $rs);
        }
        elsif ($security eq 'TRUE')
        {
            $output_result .=  &layout3($bb, $flash_size, $rs);
        }
        else
        {
            $output_result .=  &layout0($bb, $flash_size, $rs);
        }
    }

    # Finally , return output
    return $output_result;
}

sub scatGen_verno
{
    return "v0.96";
    # v0.96 by Claudia, support NORMAL/SECURE/NONE USB_DOWNLOAD option
    # v0.95 by Claudia, force med_main.obj to be the first in LARGEPOOL execution region on MT6227D/MT6226D
    # v0.94 by Claudia, DYNAMIC_CODE add RESAMPLE/REVERB on MT6223/MT6227/MT6227D/MT6226/MT6226M/MT6226D
    # v0.93 by JI, code location bug fix when ESBNOR + DCM_SUPPORT + MT6227 series
    # v0.92 by JI, Scatter address calc correct on multi-bin , secure layout
    # v0.91 by JI, new library sss.lib
    # v0.90 by JI, MT6223 ESBNOR move l1dsm.obj from External to Internal
    # v0.89 by JI, NFB Secondary DSP TX RX address calc bug-fix
    # v0.88 by JI, Scatter adjustable with NOR Flash Block Size.
    #              And USB_DOWNLOAD feature supported
    # v0.87 by JI, NFB Primary add BLINUSED execution region
    # v0.84 by JI, NFB Primary ROM add MiscUtils.obj for C++ const data init
    # v0.83 by JI, NFB Primary RAM length limit calc correction
    # v0.82 by JI, SINGLE_BANK_CODE revise and doc organize on all platform
    # v0.81 by JI, SINGLE_BANK_CODE revise on MT6223/23P platform
    # -------------- 07B active branch 
}

#****************************************************************************
# subroutine:  USBDOWNLOAD Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout4
{
    my ($bb) = @_;
    # --- --- --- 
    # Support Check
    my %BBtbl_USBDL_Capability =
       (        
                'MT6225'  => 1,
                'MT6226'  => 1,
                'MT6226M' => 1,
                'MT6227'  => 1,
                'MT6227D' => 1,
                'MT6226D' => 1,
       );
    die "unsupported $bb " if not exists $BBtbl_USBDL_Capability{$bb}; 

    my $blbase = sprintf("0x%08x", &config_query_flash_base_address);
    my $blksz  = &config_query_flash_block_sz(0x0);
    $blksz     = (32 * 1024) if ($blksz < 32 * 1024);
    my $blsize = sprintf("0x%x", $blksz);

    # --- --- --- 
    my $layout_default = <<"__LAYOUT";
BOOTLOADER $blbase $blsize
{
}

__LAYOUT
    return $layout_default;

}

#****************************************************************************
# subroutine:  SECURE Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout3
{
    my ($bb, $fs, $rs) = @_;
    # --- --- --- 
    # address setting
    my $fbase    = sprintf("0x%08x", &lv_rom_fbase($bb));
    $fs = &ROMlength_calc($bb, $fs);
    my $flength  = sprintf("0x%08x", $fs - &config_query_rom_offset());

    my $query_address        ;
    my $last_block_size      ;
    # --- --- --- 
    # custom parameter address setup
    $query_address           = $fs - 1;
    $last_block_size         = &config_query_flash_block_sz($query_address);
    $query_address           = $fs - $last_block_size;
    my $flash_custpara_addr  = sprintf("0x%08x", &config_query_flash_base_address($bb) + $query_address);

    # --- --- --- 
    # tool config address setup
    $query_address           --;
    $last_block_size         = &config_query_flash_block_sz($query_address);
    $query_address           = $query_address - $last_block_size + 1;
    my $flash_toolcfg_addr   = sprintf("0x%08x", &config_query_flash_base_address($bb) + $query_address);

    # --- --- --- 
    # Secure RO   address setup
    $query_address           --;
    $last_block_size         = &config_query_flash_block_sz($query_address);
    $query_address           = $query_address - $last_block_size + 1;
    my $flash_secure_ro_addr = sprintf("0x%08x", &config_query_flash_base_address($bb) + $query_address);

    # --- --- --- 
    # execution view reterieving
    my $ev_rom_secure        = &layout3_rom_ev($bb, &lv_rom_fbase($bb), $rs);
    my $ev_hidden_secure_mac = &layout3_secure_mac_ev();
    my $ev_hidden_secure_ro  = &layout3_secure_ro_ev($flash_secure_ro_addr);
    my $ev_hidden_toolcfg    = &layout3_toolcfg_ev($flash_toolcfg_addr);
    my $ev_hidden_custpara   = &layout3_custpara_ev($flash_custpara_addr);
    chomp $ev_rom_secure;
    chomp $ev_hidden_secure_mac;
    chomp $ev_hidden_secure_ro;
    chomp $ev_hidden_toolcfg;
    chomp $ev_hidden_custpara;
    # --- --- --- 
    my $layout_mbin = <<"__LAYOUT";
ROM $fbase $flength
{
$ev_rom_secure
}

;=========================================================================
; This load region must be behind all the protected load region
;=========================================================================
; 1. DO NOT modify load region naming and pragma naming!
;=========================================================================

__HIDDEN_SECURE_MAC +0x0
{
$ev_hidden_secure_mac
}

;=========================================================================
; The following load regions must be the end of all the load regions
;=========================================================================
; 1. Only address is configurable.
; 2. Region address must be fixed address.
; 3. Using flash-sector-aligned address in region address for higher security.
; 4. DO NOT modify load region order, load region naming and pragma naming!
;=========================================================================

__HIDDEN_SECURE_RO $flash_secure_ro_addr
{
$ev_hidden_secure_ro
}

__HIDDEN_FLASHTOOL_CFG $flash_toolcfg_addr
{
$ev_hidden_toolcfg
}

__HIDDEN_CUST_PARA $flash_custpara_addr
{
$ev_hidden_custpara
}

__LAYOUT
    return $layout_mbin;
}

#****************************************************************************
# subroutine:  MULTIBIN Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout2
{
    my ($bb, $fs, $rs) = @_;
    my $fbase   = sprintf("0x%08x", &lv_rom_fbase($bb));
    $fs = &ROMlength_calc($bb, $fs);
    my $flength = sprintf("0x%08x", $fs - &config_query_rom_offset() );
    my $jbase   = sprintf("0x%08x", &config_query_flash_base_address($bb) + $fs - 0x200);
    my $ev_rom_default  = &layout0_rom_ev($bb, $fbase, $rs);
    my $ev_lang_pack    = &layout2_lang_ev();
    my $ev_custpack_rom = &layout2_cust_ev();
    my $ev_jump_table   = &layout2_jump_ev();
    # --- --- --- 
    chomp $ev_rom_default;
    chomp $ev_lang_pack;
    chomp $ev_custpack_rom;
    chomp $ev_jump_table;
    # --- --- --- 
    my $layout_mbin = <<"__LAYOUT";
ROM $fbase $flength
{
$ev_rom_default
}

LANG_PACK_ROM +0x00
{
$ev_lang_pack
}

CUSTPACK_ROM +0x00
{
$ev_custpack_rom
}

JUMP_TABLE $jbase 0x200
{
$ev_jump_table
}
__LAYOUT
    return $layout_mbin;
}

#****************************************************************************
# subroutine:  NFB Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout1
{
    my ($bb, $fs, $rs) = @_;
    die "<<Warnning>> RAM size $rs < 32 MB, please check MemoryDevice setting"
        if $rs < (32 * 1024 * 1024);
    # --- --- --- 
    my $seperate_primary_and_secondary;
    my $seperate_secondary_rom_and_ram;
    if ($rs == 32 * 1024 * 1024 )
    {
        $seperate_primary_and_secondary = 0x0800000;
        $seperate_secondary_rom_and_ram = 0x1800000;
    }
    elsif ($rs == 64 * 1024 * 1024 )
    {
        #--- Note XXX ---------------------
        # MT621X , MT622X LCD DMA cannot access memory cross 32 MB boundary
        #----------------------------------
        $seperate_primary_and_secondary = 0x0C00000;
        $seperate_secondary_rom_and_ram = 0x2000000;
    }
    # --- --- --- 
    die "RAM partition layout not defined for RAM density $rs" unless defined $seperate_secondary_rom_and_ram;
    # --- --- --- 
    my $ev_primary   = &layout1_primaryrom_ev($bb, $seperate_primary_and_secondary);
    my $ev_secondary = &layout1_secondaryrom_ev($bb,
                                                $rs,
                                                $seperate_primary_and_secondary,
                                                $seperate_secondary_rom_and_ram);
    my $ev_third     = &layout1_thirdrom_ev($bb, $rs);
    my $sep_string   = sprintf("0x%08x", $seperate_primary_and_secondary);
    # --- --- --- 
    chomp $ev_primary;
    chomp $ev_secondary;
    chomp $ev_third;
    # --- --- --- 
    my $layout_nfb = <<"__LAYOUT";
ROM 0x00 0x800000
{
$ev_primary
}

SECONDARY_ROM $sep_string 0x1400000
{
$ev_secondary
}

THIRD_ROM +0x0
{
$ev_third
}
__LAYOUT
    return $layout_nfb;
}

#****************************************************************************
# subroutine:  Default Layout <Class>
# return:      the body strings
#****************************************************************************
sub layout0
{
    my ($bb, $fs, $rs) = @_;
    my $fbase   = sprintf("0x%08x", &lv_rom_fbase($bb));
    $fs = &ROMlength_calc($bb, $fs);
    my $flength = sprintf("0x%08x", $fs - &config_query_rom_offset() );
    my $ev_rom_default = &layout0_rom_ev($bb, $fbase, $rs);
    # --- --- --- 
    chomp $ev_rom_default;
    # --- --- --- 
    my $layout_default = <<"__LAYOUT";
ROM $fbase $flength
{
$ev_rom_default
}
__LAYOUT
    return $layout_default;
}

{
#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Globals
#****************************************************************************
    my %BBtbl_Default_ROM_address =
       (        'MT6205B' => 0,
                'MT6208'  => 0,
                'MT6217'  => 0x08000000,
                'MT6218B' => 0x08000000,
                'MT6219'  => 0x08000000,
                'MT6223'  => 0x08000000,
                'MT6223P' => 0x08000000,
                'MT6225'  => 0,
                'MT6226'  => 0x08000000,
                'MT6226M' => 0x08000000,
                'MT6227'  => 0x08000000,
                'MT6227D' => 0x08000000,
                'MT6226D' => 0x08000000,
                'MT6228'  => 0,
                'MT6229'  => 0,
                'MT6230'  => 0,
       );
    my %BBtbl_MPU_Capability =
       (        
                'MT6225'  => 1,
                'MT6228'  => 1,
                'MT6229'  => 1,
                'MT6230'  => 1,
       );
    my $config_cs_swap = 0;
    my $config_rom_offset = 0;

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query Flash Block Size
# input:       Flash Offset Address
# Output:      Flash block size
#****************************************************************************
sub config_query_flash_block_sz
{
    my ($offset) = @_;
    my $flash_size   = $norflash_info_href->{'AVAILABLE_SIZE'};

    die "Query Block Size at $offset larger than available size\n" if ($offset > $flash_size);

    my $href   = $norflash_info_href->{'BLOCKS_TABLE'};
    die "Block Size Information Unavailable, Please check EMI DataBase and custom_EMI.h\n" unless defined $href;

    my @offset = sort {$b <=> $a} keys %$href;

    foreach my $i (@offset)
    {
        return $href->{$i} if ($offset >= $i);
    }
    die "Unreachable!";
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Setup
# input:       BB chip
# Output:      NOR Flash / External RAM Chip Select swap determine
#              ROM begin address offset determine
#****************************************************************************
sub config_setup
{
    my ($bb) = @_;

    my $esb    = &$feature_query_function_ptr('enhanced_single_bank_nor_flash_support');
    my $fota   = &$feature_query_function_ptr('fota_enable');
    my $usbdl  = &$feature_query_function_ptr('usb_download');

    # determine $config_cs_swap
    if (defined $BBtbl_MPU_Capability{$bb})
    {
        if (defined $esb and $esb eq 'TRUE')
        {
            $config_cs_swap = 1;  
        }
        if (defined $usbdl and $usbdl ne 'NONE')
        {
            $config_cs_swap = 1;  
        }
        if (defined $fota and $fota ne 'NONE')
        {
            $config_cs_swap = 1;  
        }
    }
    # determine $config_rom_offset
    if (defined $usbdl and $usbdl ne 'NONE')
    {
       # NOTE : at least 32KB
       $config_rom_offset = (&config_query_flash_block_sz(0x0) > 32 * 1024)
                          ? &config_query_flash_block_sz(0x0)
                          : 32 * 1024
                          ;
    }
    if (defined $fota and $fota ne 'NONE')
    {
       # NOTE : at least 64KB
       my $tmp = $config_rom_offset;
       $config_rom_offset = (&config_query_flash_block_sz($tmp) > 64 * 1024)
                          ? &config_query_flash_block_sz($tmp)
                          : 64 * 1024
                          ;
       $config_rom_offset += $tmp;
    }
}

#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: Flash Base
# input:       BB chip
# Output:      Configure Flash Base Address
#****************************************************************************
sub config_query_flash_base_address
{
   my ($bb) = @_;

   die "unsupported $bb " if not exists $BBtbl_Default_ROM_address{$bb}; 

   my $addr = $BBtbl_Default_ROM_address{$bb};
   return $addr if ($config_cs_swap == 0);

   # Do chip select swap
   if ($bb eq 'MT6205B')
   {
       return $addr ^ 0x10000000;
   }
   else
   {
       return $addr ^ 0x08000000;
   }
}
#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: ROM BEGIN OFFSET
# input:       None
# Output:      Begin offset
#****************************************************************************
sub config_query_rom_offset
{
   return $config_rom_offset;
}
#****************************************************************************
# subroutine:  SCHEME Configure Routines :: Query :: External SRAM Base
# input:       BB chip
# Output:      Configured External SRAM Base Address
#****************************************************************************
sub config_query_extsram_base_address
{
   my ($bb) = @_;

   die "unsupported $bb " if not exists $BBtbl_Default_ROM_address{$bb}; 

   my $addr = $BBtbl_Default_ROM_address{$bb};
   return $addr if ($config_cs_swap == 1);

   # Do chip select swap
   if ($bb eq 'MT6205B')
   {
       return $addr ^ 0x10000000;
   }
   else
   {
       return $addr ^ 0x08000000;
   }
}
}
#****************************************************************************
# subroutine:  Default Layout :: Load View :: ROM base address
# input:       BB chip
#****************************************************************************
sub lv_rom_fbase
{
    my ($bb) = @_;
    return &config_query_flash_base_address($bb) + &config_query_rom_offset();
}

#****************************************************************************
# subroutine:  Default Layout :: Exec View :: EXTSRAM base address
# input:       BB chip
#****************************************************************************
sub ev_extsram_base
{
    my ($bb) = @_;
    return &config_query_extsram_base_address($bb);
}

#****************************************************************************
# subroutine:  SECURE Layout :: ROM :: Exec View
# input:       BB chip, flash base address[value], ram size [value]
#****************************************************************************
sub layout3_rom_ev
{
    my ($bb, $fbAddr, $ram_size_value) = @_;
    my %BBtbl =
       (
             'MT6223'  => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_2($bb, $ram_size_value) .
                                &INTSRAM_type2($bb);  },
             'MT6223P' => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_2($bb, $ram_size_value) .
                                &INTSRAM_type2($bb);  },
             'MT6225'  => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_1($bb, $ram_size_value) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb); },
             'MT6226'  => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_1($bb, $ram_size_value) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb); },
             'MT6226M' => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_1($bb, $ram_size_value) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb); },
             'MT6227'  => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_1($bb, $ram_size_value) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb); },
             'MT6227D' => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_1($bb, $ram_size_value) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb); },
             'MT6226D' => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_1($bb, $ram_size_value) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb); },
             'MT6229'  => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_2($bb, $ram_size_value) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb); },
             'MT6230'  => sub { &ROM_type_3($fbAddr) .
                                &EXTSRAM_type_2($bb, $ram_size_value) .
                                &INTSRAM_type1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &INTSRAM_MED_EV($bb); },
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "$bb Secure Layout not supported Yet" if not exists $BBtbl{$bb}; 
    my $func = $BBtbl{$bb};
    return &$func;
}

#****************************************************************************
# subroutine:  NFB Layout :: PRIMARY ROM :: Exec View
# input:       BB chip, flash size[value], ram size [value]
#****************************************************************************
sub layout1_primaryrom_ev
{
    my ($bb, $ram_size_value) = @_;
    my %BBtbl =
       (
             'MT6225'  => sub { &ROM_type_1($bb) .
                                &INTSRAM_DCM_EV($bb).
                                &EXTSRAM_type_3($bb, 0x400000, $ram_size_value - 0x400000) .
                                &INTSRAM_type1($bb).
                                &INTSRAM_BLINUSED_EV($bb);},
             'MT6228'  => sub { &ROM_type_1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &EXTSRAM_type_3($bb, 0x400000, $ram_size_value - 0x400000) .
                                &INTSRAM_type1($bb).
                                &INTSRAM_BLINUSED_EV($bb);},
             'MT6229'  => sub { &ROM_type_1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &EXTSRAM_type_3($bb, 0x400000, $ram_size_value - 0x400000) .
                                &INTSRAM_type1($bb).
                                &INTSRAM_BLINUSED_EV($bb);},
             'MT6230'  => sub { &ROM_type_1($bb) .
                                &INTSRAM_DCM_EV($bb) .
                                &EXTSRAM_type_3($bb, 0x400000, $ram_size_value - 0x400000) .
                                &INTSRAM_type1($bb).
                                &INTSRAM_BLINUSED_EV($bb);}, 
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "$bb NFB Layout not supported Yet" if not exists $BBtbl{$bb}; 
    die "RAM size $ram_size_value < 8 MB" if $ram_size_value < (8 * 1024 * 1024);
    my $func = $BBtbl{$bb};
    return &$func;
}

#****************************************************************************
# subroutine:  NFB Layout :: SECONDARY ROM :: Exec View
# input:       BB chip, flash size[value], ram size [value]
#****************************************************************************
sub layout1_secondaryrom_ev
{
    my ($bb, $ram_size_value, $secondary_rompool, $secondary_rampool) = @_;
    
    my %BBtbl =
       (
             'MT6225'  => sub { &ROM_type_2($secondary_rompool) .
                                &EXTSRAM_type_4($bb, $secondary_rampool, $ram_size_value) .
                                &INTSRAM_MED_EV($bb, 1) ;},
             'MT6228'  => sub { &ROM_type_2($secondary_rompool) .
                                &EXTSRAM_type_4($bb, $secondary_rampool, $ram_size_value) .
                                &INTSRAM_MED_EV($bb, 1) ;},
             'MT6229'  => sub { &ROM_type_2($secondary_rompool) .
                                &EXTSRAM_type_5($bb, $secondary_rampool, $ram_size_value) .
                                &INTSRAM_MED_EV($bb, 1) ;},
             'MT6230'  => sub { &ROM_type_2($secondary_rompool) .
                                &EXTSRAM_type_5($bb, $secondary_rampool, $ram_size_value) .
                                &INTSRAM_MED_EV($bb, 1) ;},
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "NFB Layout not supported on $bb platform" if not exists $BBtbl{$bb}; 
    my $func = $BBtbl{$bb};
    return &$func;
}

#****************************************************************************
# subroutine:  NFB Layout :: THIRD ROM :: Exec View
# input:       BB chip, flash size[value], ram size [value]
#****************************************************************************
sub layout1_thirdrom_ev
{
    my ($bb, $ram_size_value) = @_;
    my $invalidaddr = sprintf("0x%08x", $ram_size_value + 0x04);
    my $template    = <<"__TEMPLATE";
    THIRD_ROM $invalidaddr
    {
         * (NFB3RDROM_HEADER_HINT)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View Lists
# input:       BB chip, begin address [string], ram size [value]
#****************************************************************************
sub layout0_rom_ev
{
    my ($bb, $bAdr, $rSZ) = @_;
    my %BBtbl =
       (
       'MT6205B' => sub { &ROM_type_0($bAdr). &EXTSRAM_type_0($bb, $rSZ). &INTSRAM_type0($bb);},
       'MT6217'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb);},
       'MT6218B' => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb);},
       'MT6219'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_MED_EV($bb);},
       'MT6223'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_2($bb, $rSZ). &INTSRAM_type2($bb);},
       'MT6223P' => sub { &ROM_type_0($bAdr). &EXTSRAM_type_2($bb, $rSZ). &INTSRAM_type2($bb);},
       'MT6225'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       'MT6226'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       'MT6226M' => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       'MT6227'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       'MT6227D' => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       'MT6226D' => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       'MT6228'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_1($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       'MT6229'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_2($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       'MT6230'  => sub { &ROM_type_0($bAdr). &EXTSRAM_type_2($bb, $rSZ). &INTSRAM_type1($bb). &INTSRAM_DCM_EV($bb). &INTSRAM_MED_EV($bb);},
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "$bb Default Layout not supported Yet" if not exists $BBtbl{$bb}; 
    my $func = $BBtbl{$bb};
    return &$func;
}

#****************************************************************************
# subroutine:  SECURE Layout :: SECURE MAC :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_secure_mac_ev
{
   my $template = <<"__TEMPLATE";
    __HIDDEN_SECURE_MAC +0x0
    {
         *.obj (SECURE_MAC_SIZE)
    }
    __HIDDEN_SECURE_MAC_CONTENT +0x0
    {
         *.obj (SECURE_MAC_CONTENT)
    }
__TEMPLATE
   return $template;
}

#****************************************************************************
# subroutine:  SECURE Layout :: SECURE RO :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_secure_ro_ev
{
    my ($addr) = @_;
    return &format_execution_view( "SECURE_RO", $addr, undef, ["*.obj (SECURE_RO)"] );
}

#****************************************************************************
# subroutine:  SECURE Layout :: FLASHTOOL CFG:: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_toolcfg_ev
{
    my ($addr) = @_;
    return &format_execution_view( "__HIDDEN_FLASHTOOL_CFG", $addr, undef, ["*.obj (FLASHTOOL_CFG)"] );
}

#****************************************************************************
# subroutine:  SECURE Layout :: CUST PARA:: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout3_custpara_ev
{
    my ($addr) = @_;
    my $template = &format_execution_view( "CUST_PARA", $addr, undef, ["*.obj (CUST_PARA)"] );
    $template .= &format_execution_view( "__HIDDEN_CUST_PARA_TAIL", "+0x0", undef, ["*.obj (CUST_PARA_TAIL)"] );
    return $template;
}

#****************************************************************************
# subroutine:  MultiBIN Layout :: LANG PACK ROM :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout2_lang_ev
{
    my $template = <<"__TEMPLATE";
    LANG_PACK_ROM +0x00
    {
         resource_lang_pack_jtbl.obj (RESOURCE_JUMP_TBL, +First)
         resource_lang_pack_jtbl.obj (+RW)
         CustStrRes.obj (+RW)
         CustStrMap.obj (+RW)
         FontRes.obj (+RW)
         IMERes.obj (+RW)
         CustMenuRes.obj (+RW)
    }
    LANG_PACK_ROM_CONTENT +0x00
    {
         CustStrRes.obj (+RO)
         CustStrMap.obj (+RO)
         FontRes.obj (+RO)
         IMERes.obj (+RO)
         CustMenuRes.obj (+RO)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  MultiBIN Layout :: CUST PACK ROM :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout2_cust_ev
{
    my $template = <<"__TEMPLATE";
    CUSTPACK_ROM +0x00
    {
         resource_custpack_jtbl.obj (RESOURCE_JUMP_TBL, +First)           
         resource_custpack_jtbl.obj (+RW)
         nvram_cust_pack.obj (+RW)        
    }
    CUSTPACK_ROM_CONTENT +0x00
    {
         nvram_cust_pack.obj (+RO)      
         CustImgResExt.obj (+RO)
         CustAdoResExt.obj (+RO)
         custpack_audio.obj (+RO)
         custom_wap_cust_pack.obj (+RO)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  MultiBIN Layout :: JUMP TABL ROM :: Exec View
# input:       BB chip, begin address [string], ram size [value] "None"
#****************************************************************************
sub layout2_jump_ev
{
    return &format_execution_view( "JUMP_TABLE", "+0x00", undef, ["custom_jump_tbl.obj (+RO, +RW, +ZI)"] );
}

#****************************************************************************
# subroutine:  Execution View Generator
# input:       Region name [string], Begin [string], Length [string], Content [Array Reference]
# output:      execution view body string
#****************************************************************************
sub format_execution_view
{
    my ($name, $begin, $length, $ar) = @_;
    my $formated_string = ' ' x 4 . $name . " $begin $length\n";
    $formated_string .= ' ' x 4 . "{\n";
    foreach (@$ar)
    {
           if (/\A;/) {$formated_string .= $_ . "\n";}
           else       {$formated_string .= ' ' x 9 . $_ . "\n";}
    }
    $formated_string .= ' ' x 4 . "}\n";
    return $formated_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: ROM Type 0
# input:       Begin [string]
#****************************************************************************
sub ROM_type_0
{
    my ($begin_string) = @_;

    my $rom_temp = <<"__TEMPLATE";
         bootarm.obj (C\$\$code,+First)
         *.obj (LEADING_PART,+First)
         *l1_classb.lib (+RO-CODE)
         *l4_classb.lib (+RO-CODE)
         *l4misc.lib (+RO-CODE)
         *email.lib (+RO-CODE)
         *lcmmi.lib (+RO-CODE)
         *mmi_framework.lib (+RO-CODE)
         *mmi_app.lib (+RO-CODE)
         *conn_app.lib (+RO-CODE)
         *media_app.lib (+RO-CODE)
         *inet_app.lib (+RO-CODE)

         cpp_initialise.o(+RO)
         cpp_finalise.o(+RO)
         * (C\$\$pi_ctorvec)
         * (C\$\$pi_dtorvec)
         * (C\$\$ddtorvec)
__TEMPLATE

    my $ThirdParty_temp = <<"__TEMPLATE";
; WAP family
         *wapadp.lib (+RO-CODE)
         *wap.lib (+RO-CODE)
         *wae.lib (+RO-CODE)
         *jataayu.lib (+RO-CODE)
         *jataayuapp.lib (+RO-CODE)
         *wapapp.lib (+RO-CODE)
         *obigo05aadp.lib (+RO-CODE)
         *obigo05alib.lib (+RO-CODE)
; J2ME family
         *j2me_11.lib (+RO-CODE)
         *j2me_hi.lib (+RO-CODE)
         *jal.lib (+RO-CODE)
         *ijet_adp.lib (+RO-CODE)
         *jblendia.lib (+RO-CODE)
         j2me_custom_*.obj (+RO-CODE)
__TEMPLATE

    my @mtklibs = split("\n", $rom_temp);
    map { s/^\s+//; } @mtklibs;

    my @thirdpartylibs = split("\n", $ThirdParty_temp);
    map { s/^\s+//; } @thirdpartylibs;

    my $ev_string;
    $ev_string  = &format_execution_view( "ROM", $begin_string, sprintf("0x%08x", 0x400000), \@mtklibs);
    $ev_string .= &format_execution_view( "ROM2", "+0x0", sprintf("0x%08x", 0x400000), \@thirdpartylibs );
    $ev_string .= &format_execution_view( "ROM3", "+0x0", sprintf("0x%08x", 0x400000), [".ANY (+RO-CODE)"] );
    $ev_string .= &format_execution_view( "ROM4", "+0x0", sprintf("0x%08x", 0x400000), [".ANY (+RO-CODE)"] );
    $ev_string .= &format_execution_view( "ROM5", "+0x0", undef, [".ANY (+RO-DATA)"] );
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: PRIMARY ROM :: Exec View :: ROM Type 1
# input:       Begin [string]
#****************************************************************************
sub ROM_type_1
{
    my ($bb) = @_;
    my $template_A = << "__RTOSLIBS_A";
         *nucleus.lib                  (+RO)
         *nucleus_int.lib              (+RO)
         *nucleus_debug.lib            (+RO)
         *threadx.lib                  (+RO)
         *threadx_ctrl_data.lib        (+RO)
         *threadx_debug.lib            (+RO)
__RTOSLIBS_A
    # --- --- --- 
    my $template_B = << "__RTOSLIBS_B";
         *nucleus.lib                  (+RO)
         *nucleus_int.lib              (+RO)
         *nucleus_debug.lib            (+RO)
         *nucleus_ctrl_code.lib        (+RO)
         *threadx.lib                  (+RO)
         *threadx_ctrl_data.lib        (+RO)
         *threadx_debug.lib            (+RO)
__RTOSLIBS_B
    # --- --- --- 
    my %BBtbl =
       (        'MT6225'  => $template_B,
                'MT6228'  => $template_A,
                'MT6229'  => $template_A,
                'MT6230'  => $template_A,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    my $rtos_libs = $BBtbl{$bb};
    chomp $rtos_libs;
    my $rom_temp = <<"__TEMPLATE";
    ROM 0x00 FIXED 0x3E8000
    {
         bootarm.obj                   (C\$\$code,+First)
         *.obj                         (LEADING_PART,+First)
         *.l                           (+RO)

         *adaptation.lib               (+RO)
         *bmt.lib                      (+RO)
         *config.lib                   (+RO)
         *drv.lib                      (+RO)
         *fdm.lib                      (+RO)
         *init.lib                     (+RO)
         *kal.lib                      (+RO)
         *l1_classb.lib                (+RO)
         *stacklib.lib                 (+RO)
         *sst.lib                      (+RO)
         *sss.lib                      (+RO)
         *tst.lib                      (+RO)
$rtos_libs

; C++ related input sections
         cpp_initialise.o              (+RO)
         cpp_finalise.o                (+RO)
         *                             (C\$\$pi_ctorvec)
         *                             (C\$\$pi_dtorvec)
         *                             (C\$\$ddtorvec)
         *                             (C\$\$ctor)
         *                             (C\$\$dtor)

; libs must be in primary ROM
         *mmi_framework.lib            (+RO)
         *sw_png_codec.lib             (+RO)
         *media.lib                    (+RO)
         *media_sec.lib                (+RO)
         *fs.lib                       (+RO)
         *verno.lib                    (+RO)
         *j2me_hi.lib                  (+RO)

; libs to balance primary & secondary ROM
         *dsp_ram.lib                  (+RO)
         *rr_classb.lib                (+RO)
         *mm_classb.lib                (+RO)
         *llc.lib                      (+RO)
         *cc.lib                       (+RO)
         *usb.lib                      (+RO)
         *nvram.lib                    (+RO)
         *nvram_sec.lib                (+RO)

; specific objects in custom.lib
; directory mcu\\custom\\system
         custom_emi.obj                (+RO)
         custom_config.obj             (+RO)
         custom_switchclock.obj        (+RO)
         custom_scatstruct.obj         (+RO)
; directory mcu\\custom\\drv\\common
         gpio_setting.obj              (+RO)
; directory mcu\\custom\\drv\\misc_drv
         adc_channel.obj               (+RO)
         alerter_tone.obj              (+RO)
         alerterdrv.obj                (+RO)
         auxmain.obj                   (+RO)
         chr_parameter.obj             (+RO)
         custom_drv_init.obj           (+RO)
         custom_equipment.obj          (+RO)
         custom_hw_default.obj         (+RO)
         eint_def.obj                  (+RO)
         exif_custom.obj               (+RO)
         gpio_drv.obj                  (+RO)
         irda_custom.obj               (+RO)
         kbdmain_joystick.obj          (+RO)
         keypad_def.obj                (+RO)
         msdc_custom.obj               (+RO)
         pmic_custom.obj               (+RO)
         pwmdrv.obj                    (+RO)
         touch_panel_custom.obj        (+RO)
         touch_panel_spi.obj           (+RO)
         touchpad.obj                  (+RO)
         touchpad_keydef.obj           (+RO)
         tv_custom.obj                 (+RO)
         uart_def.obj                  (+RO)
         uem_gpio.obj                  (+RO)
         usb_custom.obj                (+RO)
         usb_host_ms_custom.obj        (+RO)
; directory mcu\\custom\\drv\\misc_drv\\BB_folder\\codegen
         adc_var.obj                   (+RO)
         eint_var.obj                  (+RO)
         gpio_var.obj                  (+RO)
         uem_drv.obj                   (+RO)
; directory mcu\\custom\\drv\\LCD
         lcd.obj                       (+RO)

; specific objects in mmiresource.lib
         custNFBProgressImg.obj        (+RO)
         gui_wrapper.obj               (+RO)

; specific objects in media_app.lib
         mdi_tv.obj                    (+RO)

; specific objects in bcsi.lib ; C++ const data init
         MiscUtils.obj                 (+RO)
    }
__TEMPLATE

    return $rom_temp;
}

#****************************************************************************
# subroutine:  NFB Layout :: PRIMARY ROM :: Exec View :: ROM Type 2
# input:       Begin [value]
#****************************************************************************
sub ROM_type_2
{
    my ($ev_baseaddr_value) = @_;
    my $ev_string;
    my $ev_baseaddr = sprintf("0x%08x", $ev_baseaddr_value);
    $ev_string  = &format_execution_view( "SECONDARY_ROM",
                                          $ev_baseaddr,
                                          "0x400000",
                                          [".ANY (+RO-CODE)"]
                                        );
    $ev_string .= &format_execution_view( "ROM2", "+0x0", "0x400000", [".ANY (+RO-CODE)"]);
    $ev_string .= &format_execution_view( "ROM3", "+0x0", "0x400000", [".ANY (+RO-DATA)"]);
    $ev_string .= &format_execution_view( "ROM4", "+0x0", "0x400000", [".ANY (+RO-DATA)"]);
    $ev_string .= &format_execution_view( "ROM5", "+0x0", "0x400000", [".ANY (+RO-DATA)"]);
    $ev_string .= &format_execution_view( "ROM6", "+0x0", "0x400000", [".ANY (+RO-DATA)"]);
    return $ev_string;
}

#****************************************************************************
# subroutine:  Secure Layout :: ROM :: Exec View :: ROM Type 3
# input:       Flash Begin [value] , Secure INFO Offset [value]
#****************************************************************************
sub ROM_type_3
{
    my ($baseaddr_value)     = @_;
    my $secinfo_offset_value = 4 * 1024;

    my $rom_temp = <<"__TEMPLATE";
         *.obj (LEADING_PART,+First)
         *l1_classb.lib (+RO-CODE)
         *l4_classb.lib (+RO-CODE)
         *l4misc.lib (+RO-CODE)
         *email.lib (+RO-CODE)
         *lcmmi.lib (+RO-CODE)
         *mmi_framework.lib (+RO-CODE)
         *mmi_app.lib (+RO-CODE)
         *conn_app.lib (+RO-CODE)
         *media_app.lib (+RO-CODE)
         *inet_app.lib (+RO-CODE)

         cpp_initialise.o(+RO)
         cpp_finalise.o(+RO)
         * (C\$\$pi_ctorvec)
         * (C\$\$pi_dtorvec)
         * (C\$\$ddtorvec)
__TEMPLATE

    my $ThirdParty_temp = <<"__TEMPLATE";
; WAP family
         *wapadp.lib (+RO-CODE)
         *wap.lib (+RO-CODE)
         *wae.lib (+RO-CODE)
         *jataayu.lib (+RO-CODE)
         *jataayuapp.lib (+RO-CODE)
         *wapapp.lib (+RO-CODE)
         *obigo05aadp.lib (+RO-CODE)
         *obigo05alib.lib (+RO-CODE)
; J2ME family
         *j2me_11.lib (+RO-CODE)
         *j2me_hi.lib (+RO-CODE)
         *jal.lib (+RO-CODE)
         *ijet_adp.lib (+RO-CODE)
         *jblendia.lib (+RO-CODE)
         j2me_custom_*.obj (+RO-CODE)
__TEMPLATE

    my @mtklibs = split("\n", $rom_temp);
    map { s/^\s+//; } @mtklibs;

    my @thirdpartylibs = split("\n", $ThirdParty_temp);
    map { s/^\s+//; } @thirdpartylibs;

    # --- --- --- 
    my $ev_string;
    my $ev_baseaddr    = sprintf("0x%08x", $baseaddr_value);
    my $ev_secinfoAddr = sprintf("0x%08x", $baseaddr_value + $secinfo_offset_value);
    $ev_string  = &format_execution_view( "ROM",
                                          $ev_baseaddr,
                                          "0x800",
                                          ["bootarm.obj (C\$\$code,+First)"]);
    $ev_string .= &format_execution_view( "ROM0",
                                          $ev_secinfoAddr,
                                          "FIXED ;4KB",
                                          ["*.obj (SECINFO)"]);
    $ev_string .= &format_execution_view( "ROM1",
                                          "+0x0",
                                          sprintf("0x%08x", 0x400000),
                                          \@mtklibs);
    $ev_string .= &format_execution_view( "ROM2",
                                          "+0x0",
                                          sprintf("0x%08x", 0x400000),
                                          \@thirdpartylibs);
    $ev_string .= &format_execution_view( "ROM3",
                                          "+0x0",
                                          sprintf("0x%08x", 0x400000),
                                          [".ANY (+RO-CODE)"]);
    $ev_string .= &format_execution_view( "ROM4",
                                          "+0x0",
                                          sprintf("0x%08x", 0x400000),
                                          [".ANY (+RO-CODE)"]);
    $ev_string .= &format_execution_view( "ROM5",
                                          "+0x0",
                                          undef,
                                          [".ANY (+RO-DATA)"]);
    $ev_string .= &format_execution_view( "ROM_TAIL",
                                          "+0x0",
                                          undef,
                                          ["*.obj (SECINFO_TAIL)"]);
    return $ev_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM Type 0
# input:       BB , RAM size [value]
# remark:      SINGLE_BANK_CODE, EXTSRAM
#****************************************************************************
sub EXTSRAM_type_0
{
    my ($bb, $ram_size) = @_;
    my $ev_string;
    my $ev_baseaddr = sprintf("0x%08x", &ev_extsram_base($bb));

    $ev_string  = &SINGLE_BANK_CODE($bb, "SINGLE_BANK_CODE", $ev_baseaddr);
    if (defined $ev_string)
    {
        $ev_baseaddr = sprintf("0x%08x", &ev_extsram_base($bb) + 0x2000);
    }
    $ev_string  .= &format_execution_view( "EXTSRAM", $ev_baseaddr, undef, ["* (+RW, +ZI)"]);
    $ev_string  .= &format_execution_view( "DUMMY_END",
                                           sprintf("0x%08x", &ev_extsram_base($bb) + $ram_size),
                                           "0x04",
                                           ["bootarm.obj (DUMMY_POOL)"]
                                         );
    return $ev_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM Type 1
# input:       BB , RAM size [value]
# remark:      include SINGLE_BANK_CODE, LARGEPOOL , EXTSRAM , APP Features , DUMMY END
#****************************************************************************
sub EXTSRAM_type_1
{
    my ($bb, $ram_size) = @_;
    my $ev_string;
    my $extsram_base_value = &ev_extsram_base($bb);
    my $ev_baseaddr = sprintf("0x%08x", ($extsram_base_value == 0x0) ? 0x140 : $extsram_base_value);

    $ev_string  = &SINGLE_BANK_CODE($bb, "SINGLE_BANK_CODE", $ev_baseaddr);
    if (defined $ev_string)
    {
       $ev_baseaddr = sprintf("0x%08x", 0x2000);
    }

    $ev_string .= &LARGEPOOL($bb, "EXTSRAM_LARGEPOOL_NORMAL", $ev_baseaddr);
    $ev_string .= &app_feature_jblend();
    $ev_string .= &format_execution_view( "EXTSRAM", "+0x00", undef, ["* (+RW, +ZI)"]);
    $ev_string .= &app_feature_opengl( $extsram_base_value + $ram_size );
    $ev_string .= &format_execution_view( "DUMMY_END",
                                          sprintf("0x%08x", &ev_extsram_base($bb) + $ram_size),
                                          "0x04",
                                          ["bootarm.obj (DUMMY_POOL)"]
                                        );
    return $ev_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM Type 2
# input:       BB , RAM size [value]
# remark:      include SINGLE_BANK_CODE, LARGEPOOL , EXTSRAM , APP Features , DSP TX, DSP RX
#****************************************************************************
sub EXTSRAM_type_2
{
    my ($bb, $ram_size) = @_;
    my $ev_string;
    my $extsram_base_value = &ev_extsram_base($bb);
    my $ev_baseaddr = sprintf("0x%08x", ($extsram_base_value == 0x0) ? 0x140 : $extsram_base_value);

    $ev_string  = &SINGLE_BANK_CODE($bb, "SINGLE_BANK_CODE", $ev_baseaddr);
    if (defined $ev_string)
    {
       $ev_baseaddr = sprintf("0x%08x", 0x2000);
    }

    $ev_string .= &LARGEPOOL($bb, "EXTSRAM_LARGEPOOL_NORMAL", $ev_baseaddr);
    $ev_string .= &app_feature_jblend();
    $ev_string .= &format_execution_view( "EXTSRAM", "+0x00", undef, ["* (+RW, +ZI)"]);

    my $mode = &$feature_query_function_ptr('MODE');
    my $region_size = &DSPTXRX_query_length($bb, $mode);

    $ev_string .= &app_feature_opengl( $extsram_base_value + $ram_size - $region_size * 2);
    $ev_string .= &DSPTXRX( "EXTSRAM", $extsram_base_value, $ram_size, $region_size );
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: PRIMARY ROM :: Exec View :: EXTSRAM Type 3
# input:       RAM base, RAM size [value]
# remark:      PRIMARY_EXTSRAM with FIXED
#****************************************************************************
sub EXTSRAM_type_3
{
    my ($bb, $ram_base_value, $ram_size_value) = @_;
    my $ev_string;
    my $ev_baseaddr = sprintf("0x%08x", $ram_base_value);
    my $ev_size     = sprintf("0x%08x", $ram_size_value);
    my $template_A = << "__RTOSLIBS_A";
         *nucleus.lib                  (+RW)
         *nucleus_int.lib              (+RW)
         *nucleus_debug.lib            (+RW)
         *threadx.lib                  (+RW)
         *threadx_debug.lib            (+RW)
__RTOSLIBS_A
    # --- --- --- 
    my $template_B = << "__RTOSLIBS_B";
         *nucleus.lib                  (+RW)
         *nucleus_int.lib              (+RW)
         *nucleus_debug.lib            (+RW)
         *nucleus_ctrl_code.lib        (+RW)
         *nucleus_critical_data.lib    (+RW)
         *threadx.lib                  (+RW)
         *threadx_debug.lib            (+RW)
__RTOSLIBS_B
    # --- --- --- 
    my %BBtbl =
       (        'MT6225'  => $template_B,
                'MT6228'  => $template_A,
                'MT6229'  => $template_A,
                'MT6230'  => $template_A,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    my $rtos_libs = $BBtbl{$bb};
    chomp $rtos_libs;
    my $ev_temp     = <<"__TEMPLATE";
         *.l                           (+RW)

         *adaptation.lib               (+RW)
         *bmt.lib                      (+RW)
         *config.lib                   (+RW)
         *drv.lib                      (+RW)
         *fdm.lib                      (+RW)
         *init.lib                     (+RW)
         *kal.lib                      (+RW)
         *l1_classb.lib                (+RW)
         *stacklib.lib                 (+RW)
         *sst.lib                      (+RW)
         *sss.lib                      (+RW)
         *tst.lib                      (+RW)
$rtos_libs

; libs must be in primary ROM
         *mmi_framework.lib            (+RW)
         *sw_png_codec.lib             (+RW)
         *media.lib                    (+RW)
         *media_sec.lib                (+RW)
         *fs.lib                       (+RW)
         *verno.lib                    (+RW)
         *j2me_hi.lib                  (+RW)

; libs to balance primary & secondary ROM
         *dsp_ram.lib                  (+RW)
         *rr_classb.lib                (+RW)
         *mm_classb.lib                (+RW)
         *llc.lib                      (+RW)
         *cc.lib                       (+RW)
         *usb.lib                      (+RW)
         *nvram.lib                    (+RW)
         *nvram_sec.lib                (+RW)

; specific objects in custom.lib
; directory mcu\\custom\\system
         custom_emi.obj                (+RW)
         custom_config.obj             (+RW)
         custom_switchclock.obj        (+RW)
         custom_scatstruct.obj         (+RW)
; directory mcu\\custom\\drv\\common
         gpio_setting.obj              (+RW)
; directory mcu\\custom\\drv\\misc_drv
         adc_channel.obj               (+RW)
         alerter_tone.obj              (+RW)
         alerterdrv.obj                (+RW)
         auxmain.obj                   (+RW)
         chr_parameter.obj             (+RW)
         custom_drv_init.obj           (+RW)
         custom_equipment.obj          (+RW)
         custom_hw_default.obj         (+RW)
         eint_def.obj                  (+RW)
         exif_custom.obj               (+RW)
         gpio_drv.obj                  (+RW)
         irda_custom.obj               (+RW)
         kbdmain_joystick.obj          (+RW)
         keypad_def.obj                (+RW)
         msdc_custom.obj               (+RW)
         pmic_custom.obj               (+RW)
         pwmdrv.obj                    (+RW)
         touch_panel_custom.obj        (+RW)
         touch_panel_spi.obj           (+RW)
         touchpad.obj                  (+RW)
         touchpad_keydef.obj           (+RW)
         tv_custom.obj                 (+RW)
         uart_def.obj                  (+RW)
         uem_gpio.obj                  (+RW)
         usb_custom.obj                (+RW)
         usb_host_ms_custom.obj        (+RW)
; directory mcu\\custom\\drv\\misc_drv\\BB_folder\\codegen
         adc_var.obj                   (+RW)
         eint_var.obj                  (+RW)
         gpio_var.obj                  (+RW)
         uem_drv.obj                   (+RW)
; directory mcu\\custom\\drv\\LCD
         lcd.obj                       (+RW)

; specific objects in mmiresource.lib
         custNFBProgressImg.obj        (+RW)
         gui_wrapper.obj               (+RW)

; specific objects in media_app.lib
         mdi_tv.obj                    (+RW)

; ZI chunk
         *                             (+ZI)
__TEMPLATE
    # --- --- --- 
    my @objects = split("\n", $ev_temp);
    map { s/^\s+//; } @objects;
    # --- --- --- 
    return &format_execution_view( "PRIMARY_EXTSRAM", $ev_baseaddr . " FIXED", $ev_size, \@objects);
}
#****************************************************************************
# subroutine:  NFB Layout :: SECONDARY ROM :: Exec View :: EXTSRAM Type 4
# input:       BB, Begin Addr [value], RAM size [value]
# remark:      include SECONDARY_LARGEPOOL , SECONDARY_EXTSRAM , APP Features , DUMMY END
#****************************************************************************
sub EXTSRAM_type_4
{
    my ($bb, $base_addr, $ram_size) = @_;
    my $ev_string;
    $ev_string  = &LARGEPOOL_NFB($bb, "SECONDARY_EXTSRAM_LARGEPOOL_NORMAL", sprintf("0x%08x", $base_addr));
    $ev_string .= &app_feature_jblend();
    $ev_string .= &format_execution_view( "SECONDARY_EXTSRAM",
                                          "+0x00",
                                          undef,
                                          ["*            (+RW)",
                                           "*media.lib   (+ZI)",
                                           "*custom.lib  (+ZI)",
                                          ]
                                        );
    $ev_string .= &app_feature_opengl( $ram_size );
    $ev_string .= &format_execution_view( "DUMMY_END",
                                          sprintf("0x%08x", $ram_size),
                                          "0x04",
                                          ["bootarm.obj (DUMMY_POOL)"]
                                        );
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: SECONDARY ROM :: Exec View :: EXTSRAM Type 5
# input:       BB , Begin Addr [value], RAM size [value]
# remark:      include SECONDARY_LARGEPOOL , SECONDARY_EXTSRAM , APP Features , DSP TX, DSP RX
#****************************************************************************
sub EXTSRAM_type_5
{
    my ($bb, $base_addr, $ram_size) = @_;
    my $ev_string;
    $ev_string  = &LARGEPOOL_NFB($bb, "SECONDARY_EXTSRAM_LARGEPOOL_NORMAL", sprintf("0x%08x", $base_addr));
    $ev_string .= &app_feature_jblend();
    $ev_string .= &format_execution_view( "SECONDARY_EXTSRAM",
                                          "+0x00",
                                          undef,
                                          ["*            (+RW)",
                                           "*media.lib   (+ZI)",
                                           "*custom.lib  (+ZI)",
                                          ]
                                        );

    my $mode = &$feature_query_function_ptr('MODE');
    my $region_size = &DSPTXRX_query_length($bb, $mode);

    $ev_string .= &app_feature_opengl( $ram_size - $region_size * 2 );
    $ev_string .= &DSPTXRX( "SECONDARY_EXTSRAM", 0x0, $ram_size , $region_size );
    return $ev_string;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM Type 6
# input:       BB , RAM size [value]
# remark:      include SINGLE_BANK_CODE, LARGEPOOL , EXTSRAM , APP Features , CODE_CACHE_DCM , DUMMY END
#****************************************************************************
sub EXTSRAM_type_6
{
    my ($bb, $ram_size) = @_;
    my $ev_string;
    my $extsram_base_value = &ev_extsram_base($bb);
    my $ev_baseaddr = sprintf("0x%08x", ($extsram_base_value == 0x0) ? 0x140 : $extsram_base_value);

    $ev_string  = &SINGLE_BANK_CODE($bb, "SINGLE_BANK_CODE", $ev_baseaddr);
    if (defined $ev_string)
    {
       $ev_baseaddr = sprintf("0x%08x", 0x2000);
    }

    $ev_string .= &LARGEPOOL($bb, "EXTSRAM_LARGEPOOL_NORMAL", $ev_baseaddr);
    $ev_string .= &app_feature_jblend();
    $ev_string .= &format_execution_view( "EXTSRAM", "+0x00", undef, ["* (+RW, +ZI)"]);
    $ev_string .= &app_feature_opengl( $extsram_base_value + $ram_size - 32 * 1024);
    $ev_string .= &EXTSRAM_DCM_EV( $bb, $extsram_base_value + $ram_size - 32 * 1024);
    $ev_string .= &format_execution_view( "DUMMY_END",
                                          sprintf("0x%08x", &ev_extsram_base($bb) + $ram_size),
                                          "0x04",
                                          ["bootarm.obj (DUMMY_POOL)"]
                                        );
    return $ev_string;
}

#****************************************************************************
# subroutine:  NFB Layout :: ROM :: Exec View :: EXTSRAM :: LARGEPOOL
# input:       BB , LargePool Base Address [string]
#****************************************************************************
sub LARGEPOOL_NFB
{
    my ($bb, $ev_regionname, $ev_baseaddr) = @_;
    my $largepool_tempB = <<"__LARGEPOOLTEMPLATE";
    $ev_regionname $ev_baseaddr
    {
; For MT6228, MT6229 projects, app-based ASM always at first due to Java FBBR
         app_mem.obj (LARGEPOOL_FIRST_ZI)
         ScrMemMgr.obj (LARGEPOOL_ZI)
         j2me_custom_resource.obj (LARGEPOOL_ZI)
         med_main.obj (LARGEPOOL_ZI)
         ResMemMgr.obj (LARGEPOOL_ZI)
    }
__LARGEPOOLTEMPLATE
    my %BBtbl =
       (        
                'MT6225'  => $largepool_tempB,
                'MT6228'  => $largepool_tempB,
                'MT6229'  => $largepool_tempB,
                'MT6230'  => $largepool_tempB,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: SINGLE_BANK_CODE
# input:       BB , SINGLE_BANK_CODE Base Address [string]
#****************************************************************************
sub SINGLE_BANK_CODE
{
    my ($bb, $ev_regionname, $ev_baseaddr) = @_;
    my $sbcode_tempA = <<"__SBNORFLASHTEMPLATE";
    $ev_regionname $ev_baseaddr
    {
;for single bank support , certain following code need to be called by sleep manager
         bootarm.obj (SNORCODE,+First)
         Drvflash.obj (SNORCODE,SNORCONST)
         nor_test.obj(SNORCODE)
         flash_mtd.obj (SNORCODE)
         flash_mtd.intel.obj (SNORCODE)
         flash_mtd.amd.obj (SNORCODE)
         m11301.obj (SNORCODE)
    }
__SBNORFLASHTEMPLATE
    my $sbcode_tempB = <<"__SBNORFLASHTEMPLATE";
    $ev_regionname $ev_baseaddr
    {
;for single bank support , certain following code need to be called by sleep manager
         Drvflash.obj (SNORCODE)
         nor_test.obj (SNORCODE)
         flash_mtd.intel.obj (SNORCODE)
         flash_mtd.amd.obj (SNORCODE)
         m11301.obj (SNORCODE)
         kal_nucleus_initialize.obj(SNORCODE)
         kal_threadx_initialize.obj(SNORCODE)
         ex_item.obj (SNORCODE)
    }
__SBNORFLASHTEMPLATE
    my $sbcode_tempC = <<"__SBNORFLASHTEMPLATE";
    $ev_regionname $ev_baseaddr
    {
;for single bank support , certain following code need to be called by sleep manager
         bootarm.obj (SNORCODE,+First)
         Drvflash.obj (SNORCODE,SNORCONST)
         nor_test.obj(SNORCODE)
         flash_mtd.obj (SNORCODE)
         flash_mtd.intel.obj (SNORCODE)
         flash_mtd.amd.obj (SNORCODE)
         m11301.obj (SNORCODE)
         init.obj (SNORCODE)
         uread4.o (+RO)
         uwrite4.o (+RO)
    }
__SBNORFLASHTEMPLATE
    # --- --- --- 
    # SINGLE_BANK_CODE execution view is optional 
    my $esb = &$feature_query_function_ptr('enhanced_single_bank_nor_flash_support');
    return undef unless(defined $esb);
    return undef unless($esb eq 'TRUE');
    # --- --- --- 
    my %BBtbl =
       (        'MT6225'  => $sbcode_tempA,
                'MT6226'  => $sbcode_tempA,
                'MT6226M' => $sbcode_tempA,
                'MT6227'  => $sbcode_tempA,
                'MT6227D' => $sbcode_tempA,
                'MT6226D' => $sbcode_tempA,
                'MT6223'  => $sbcode_tempC,
                'MT6223P' => $sbcode_tempC,
                'MT6229'  => $sbcode_tempA,
                'MT6230'  => $sbcode_tempA,
                'MT6205B' => $sbcode_tempB,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    # +First but not present will make basic and l1s load build failure
    my $mode = &$feature_query_function_ptr('MODE');
    if (defined $mode)
    {
        if ($mode eq "BASIC" or $mode eq "L1S")
        {
           $BBtbl{$bb} =~ s/,\+First\)/\)/g;
        }
    }
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: LARGEPOOL
# input:       BB , LargePool Base Address [string]
#****************************************************************************
sub LARGEPOOL
{
    my ($bb, $ev_regionname, $ev_baseaddr) = @_;
    my $largepool_tempA = <<"__LARGEPOOLTEMPLATE";
    $ev_regionname $ev_baseaddr
    {
; For MT6219, MT6227, MT6226 projects, med_main.obj must be the first for tearing issue
         med_main.obj (LARGEPOOL_ZI,+First)
         ScrMemMgr.obj (LARGEPOOL_ZI)
         app_mem.obj (LARGEPOOL_FIRST_ZI)
         j2me_custom_resource.obj (LARGEPOOL_ZI)
    }
__LARGEPOOLTEMPLATE
    my $largepool_tempB = <<"__LARGEPOOLTEMPLATE";
    $ev_regionname $ev_baseaddr
    {
; For MT6228, MT6229 projects, app-based ASM always at first due to Java FBBR
         app_mem.obj (LARGEPOOL_FIRST_ZI)
         ScrMemMgr.obj (LARGEPOOL_ZI)
         j2me_custom_resource.obj (LARGEPOOL_ZI)
         med_main.obj (LARGEPOOL_ZI)
    }
__LARGEPOOLTEMPLATE
    my $largepool_tempC = <<"__LARGEPOOLTEMPLATE";
    $ev_regionname $ev_baseaddr
    {
         app_mem.obj (LARGEPOOL_FIRST_ZI)
         ScrMemMgr.obj (LARGEPOOL_ZI)
         j2me_custom_resource.obj (LARGEPOOL_ZI)
         med_main.obj (LARGEPOOL_ZI)
    }
__LARGEPOOLTEMPLATE
    my %BBtbl =
       (        'MT6217'  => $largepool_tempC,
                'MT6218B' => $largepool_tempC,
                'MT6219'  => $largepool_tempA,
                'MT6223'  => $largepool_tempC,
                'MT6223P' => $largepool_tempC,
                'MT6225'  => $largepool_tempB,
                'MT6226'  => $largepool_tempA,
                'MT6226M' => $largepool_tempA,
                'MT6227'  => $largepool_tempA,
                'MT6227D' => $largepool_tempA,
                'MT6226D' => $largepool_tempA,
                'MT6228'  => $largepool_tempB,
                'MT6229'  => $largepool_tempB,
                'MT6230'  => $largepool_tempB,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    # +First but not present will make basic and l1s load build failure
    my $mode = &$feature_query_function_ptr('MODE');
    if (defined $mode)
    {
        if ($mode eq "BASIC" or $mode eq "L1S")
        {
           $BBtbl{$bb} =~ s/,\+First\)/\)/g;
        }
    }
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: jblend
# input:       None
#****************************************************************************
sub app_feature_jblend
{
    my $j2me_support = &$feature_query_function_ptr('j2me_support');
    if (defined $j2me_support and $j2me_support eq "JBLENDIA")
    {
        return &format_execution_view( "jblend_ram", "+0x0", undef, ["*jblend_*.o (+RW, +ZI)"]);
    }
    return '';
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: CODE_PATCH_CODE
# input:       RamAddress
# output:      Begin RamAddress - 4KB , Length 4KB
#****************************************************************************
sub app_feature_opengl
{
    my ($baseaddr) = @_;
    my $j2me_support = &$feature_query_function_ptr('opengl');
    my $begin = sprintf("0x%08x", $baseaddr - 4 * 1024);
    if (defined $j2me_support and $j2me_support ne "NONE")
    {
        return &format_execution_view( "CODE_PATCH_CODE", $begin, "0x1000 ; 4KB", ["* (CODE_PATCH_REGION)"]);
    }
    return '';
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: DSP
# input:       ram start address <value> , ram size <value>
#****************************************************************************
sub DSPTXRX
{
    my ($prefix_name, $baseaddr, $ram_size, $region_size) = @_;
    my $tx_addr = sprintf("0x%08x", $baseaddr + $ram_size - $region_size * 2);
    my $rx_addr = sprintf("0x%08x", $baseaddr + $ram_size - $region_size * 1);
    my $ev_len  = sprintf("0x%x", $region_size);
    my $ev_dsp  = <<"__DSPTEMPLATE";
; DSP execution regions cannot be OVERLAY; its size should be specified as 2^N, larger than 4KB, and should align with its start address
    ${prefix_name}_DSP_TX $tx_addr $ev_len
    {
         dps_misc.obj (EXTRAM_TXDATA)
         rr_create.obj (EXTRAM_TXDATA)
         rlc_main.obj (EXTRAM_TXDATA)
         mpal_main.obj (EXTRAM_TXDATA)
         v110.obj (EXTRAM_TXDATA)
         m12161.obj (EXTRAM_TXDATA)
         m12150.obj (EXTRAM_TXDATA)
         dps_rlc_func.obj (EXTRAM_TXDATA)
         csd_ra.obj (EXTRAM_TXDATA)
    }
    ${prefix_name}_DSP_RX $rx_addr $ev_len
    {
         m11006.obj (EXTRAM_RXDATA)
         v110.obj (EXTRAM_RXDATA)
         m12161.obj (EXTRAM_RXDATA)
         irdbg_drv.obj (EXTRAM_RXDATA)
    }
__DSPTEMPLATE
    return $ev_dsp;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type 2
# input:       BB
# remark:      INTSRAM only
#****************************************************************************
sub INTSRAM_type2
{
    my ($bb) = @_;
    my $system_related_code_and_common_C_libs = <<"__6223";
; system-realted CODE ... for MT6223
         isrentry.obj (INTERNCODE)
         bootarm.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE,INTERNCONST)
         custom_emi.obj (INTERNCODE)
         custom_switchclock.obj (INTERNCODE)
         idle_task.obj (INTERNCODE)
         data_buff_pool.obj (INTERNCODE)
         ctrl_buff_pool.obj (INTERNCODE)
         stack_buff_pool.obj (INTERNCODE)
         stack_ltlcom.obj (INTERNCODE)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
         lcd_dll.obj (INTERNCODE)
         event_shed.obj (INTERNCODE)
         stack_timer.obj (INTERNCODE)
         tct.obj (+RO)
         tcc.obj (INTERNCODE)
         csc.obj (INTERNCODE)
         tmt.obj (+RO)
         tms.obj (+RO)
         smc.obj (+RO)
         evc.obj (+RO)
         pmc.obj (+RO)
         quc.obj (+RO)
; common C library ... for MT6223
         memset.o (+RO)
         rt_memclr.o (+RO)
         callvia.o (+RO)
         _sprintf.o (+RO)
         rt_memcpy.o (+RO)
         lludiv10.o (+RO)
         rt_udiv.o (+RO)
__6223

    my $system_related_RW = <<"__6223";
; system-realted RW/ZI ... for MT6223
         bootarm.obj (STACK_POOL_INTSRAM)
         custom_switchclock.obj (INTERNCONST, INTERNRW, INTERNZI)
         idle_task.obj (INTERNCONST, INTERNRW, INTERNZI)
         isrentry.obj (INTERNCONST, INTERNRW, INTERNZI)
         stack_init.obj (INTERNCONST, INTERNRW, INTERNZI)
         ctrl_buff_pool.obj (INTERNCONST, INTERNRW, INTERNZI)
         stack_ltlcom.obj (INTERNCONST, INTERNRW, INTERNZI)
         tct.obj (+RW, +ZI)
         tcd.obj (INTERNCONST, INTERNRW, INTERNZI)
         tmd.obj (+RW, +ZI)
         evd.obj (+RW, +ZI)
         pmd.obj (+RW, +ZI)
         qud.obj (+RW, +ZI)
         smd.obj (+RW, +ZI)
__6223

    my $misc_code = <<"__6223";
; misc CODE ... for MT6223
         m12100.obj (INTERNCODE)
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m11303.obj (INTERNCODE)
         gpt.obj (INTERNCODE)
         lpwr.obj (INTERNCODE)
         ;wav.obj (INTERNCODE)
         ;wav_codec.obj (INTERNCODE)
         gdi_image_alpha_bmp.obj (INTERNCODE)
         *l1dsm.obj (SNORCODE)
__6223
    $misc_code .= " " x 9 . "lsd.obj (INTERNCODE)" . "\n" if $bb eq 'MT6223P';

    chomp($system_related_code_and_common_C_libs);
    chomp($misc_code);
    chomp($system_related_RW);

    my $intsram_6223 = <<"__6223";
    INTSRAM 0x40000000 0x0000A000
    {
$system_related_code_and_common_C_libs 
$misc_code
$system_related_RW 
; misc RW/ZI
         ;tst*.obj (INTERNCONST, INTERNRW, INTERNZI)
         ;m12100.obj (INTERNCONST, INTERNRW, INTERNZI)
         ;m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         ;m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
    }
    DYNAMIC_CODE3 0x40008D80 OVERLAY 0x1280
    {
         * (CTM_DYNAMIC_CODE, CTM_DYNAMIC_ZI)
    }
    DYNAMIC_CODE5 0x40008D80 OVERLAY 0x1280
    {
         * (SBC_DYNAMIC_CODE, SBC_DYNAMIC_ZI)
    }
    DYNAMIC_CODE7 0x40008D80 OVERLAY 0x1280
    {
         * (REVERB_DYNAMIC_CODE, REVERB_DYNAMIC_ZI)
    }
    DYNAMIC_CODE8 0x40008D80 OVERLAY 0x1280
    {
         * (RESAMPLE_DYNAMIC_CODE, RESAMPLE_DYNAMIC_ZI)
    }

__6223

    return $intsram_6223;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type 0
# input:       BB
# remark:      INTSRAM only
#****************************************************************************
sub INTSRAM_type0
{
    my ($bb) = @_;
    my $intsram_6205 = <<"__6205";
    INTSRAM 0x40000000 0x00008000
    {
; system-realted CODE/RW/ZI , STANDARD set
         bootarm.obj (STACK_POOL_INTSRAM, INTERNCODE)
         custom_emi.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE,INTERNCONST)
         isrentry.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         stack_init.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tcc.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         csc.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tcd.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tct.obj (+RO, +RW, +ZI)
; misc CODE/RW/ZI
         divider.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         midisyn.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_image_alpha_bmp.obj (INTERNCODE)
         gdi.obj (INTERNZI)  
    }
__6205
    my $intsram_6205_enhanced_snor = <<"__6205";
    INTSRAM 0x40000000 0x00008000
    {
; system-realted CODE/RW/ZI , SINGLE-BANK set
         bootarm.obj (STACK_POOL_INTSRAM, INTERNCODE, SNORCODE)
         custom_emi.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE,INTERNCONST)
         isrentry.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         init.obj (SNORCODE)
         stack_init.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tcc.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         csc.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tcd.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tct.obj (+RO, +RW, +ZI)
; misc CODE/RW/ZI
         divider.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         midisyn.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi.obj (INTERNZI)  
; common C library
         uread4.o (+RO)
         uwrite4.o (+RO)
         callvia.o (+RO)
; Enhanced Single Bank Support
         Drvflash.obj (INTERNCODE, SNORCONST)
         flash_mtd.obj (SNORCODE, SNORRW, SNORZI)
         flash_mtd.intel.obj (INTERNCODE)
         flash_mtd.amd.obj (INTERNCODE)
         *l1dsm.obj (SNORCODE)
    }
__6205
    my $intsram_6205_lowcost_snor = <<"__6205";
    INTSRAM 0x40000000 0x00008000
    {
; system-realted CODE/RW/ZI , SINGLE-BANK set
         bootarm.obj (STACK_POOL_INTSRAM, INTERNCODE, SNORCODE)
         custom_emi.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE, INTERNCONST)
         isrentry.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         init.obj (SNORCODE)
         stack_init.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tcc.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         csc.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tcd.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         tct.obj (+RO, +RW, +ZI)
; misc CODE/RW/ZI
         divider.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         midisyn.obj (INTERNCODE, INTERNCONST, INTERNRW, INTERNZI)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi.obj (INTERNZI)
; common C library
         uread4.o (+RO)
         uwrite4.o (+RO)
         callvia.o (+RO)
; Low-Cost Single Bank Support
         Drvflash.obj (SNORCODE)
         nor_test.obj(SNORCODE)
         flash_mtd.obj (SNORCODE)
         flash_mtd.intel.obj (SNORCODE)
         flash_mtd.amd.obj (SNORCODE)
         *l1dsm.obj (SNORCODE)
    }
__6205
    my $option_esb = &$feature_query_function_ptr('enhanced_single_bank_nor_flash_support');
    my $option_lsb = &$feature_query_function_ptr('single_bank_nor_flash_support');
    # The 2 option are exclusive 

    if (defined $option_esb and $option_esb eq 'TRUE')
    {
       return $intsram_6205_enhanced_snor;
    }
    elsif (defined $option_lsb and $option_lsb eq 'TRUE')
    {
       return $intsram_6205_lowcost_snor;
    }
    else
    {
       return $intsram_6205;
    }
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type 1
# input:       BB
# remark:      INTSRAM_CODE INTSRAM_DATA
#****************************************************************************
sub INTSRAM_type1
{
    my ($bb) = @_;
    my $comm_intsram_code  = &INTSRAM_CODE_OBJ_system($bb);
    my $comm_intsram_data  = &INTSRAM_DATA_OBJ_system($bb);
    my $other_intsram_code = &INTSRAM_CODE_OBJ_others($bb);
    my $other_intsram_data = &INTSRAM_DATA_OBJ_others($bb);
    # --- --- --- 
    chomp $comm_intsram_code;
    chomp $comm_intsram_data;
    chomp $other_intsram_code;
    chomp $other_intsram_data;
    # --- --- --- 
    my $template_6219 = <<"__TEMPLATE_6219";
    INTSRAM_CODE 0x40000000 0x00014000
    {
$comm_intsram_code
$other_intsram_code
    }
    INTSRAM_DATA 0x40014000 0x0000c000
    {
$comm_intsram_data
$other_intsram_data
    }   
__TEMPLATE_6219
    # --- --- --- 
    my $template_6217 = <<"__TEMPLATE_6217";
    INTSRAM_CODE 0x40000000 0x00014000
    {
$comm_intsram_code
$other_intsram_code
    }
    INTSRAM_DATA 0x40014000 0x0000c000
    {
$comm_intsram_data
$other_intsram_data
    }   
__TEMPLATE_6217
    # --- --- --- 
    my $template_6225 = <<"__TEMPLATE_6225";
    INTSRAM_CODE 0xA0000000 0x7600
    {
$comm_intsram_code
$other_intsram_code
    }
    INTSRAM_DATA 0xA0007600 0x5A00
    {
$comm_intsram_data
$other_intsram_data
    }   
__TEMPLATE_6225
    # --- --- --- 
    my $template_6227 = <<"__TEMPLATE_6227";
    INTSRAM_CODE 0x40000380 0x0000FD00
    {
$comm_intsram_code
$other_intsram_code
    }
    INTSRAM_DATA 0x40010080 0x00008780
    {
$comm_intsram_data
$other_intsram_data
    }
__TEMPLATE_6227
    # --- --- --- 
    my $template_6227D = <<"__TEMPLATE_6227D";
    INTSRAM_CODE 0x40000000 0x0000FC00
    {
$comm_intsram_code
$other_intsram_code
    }
    INTSRAM_DATA 0x4000FC00 0x00008C00
    {
$comm_intsram_data
$other_intsram_data
    }
__TEMPLATE_6227D
    # --- --- --- 
    my $template_6228 = <<"__TEMPLATE_6228";
    INTSRAM_CODE 0xA0000000 0x00010400
    {
$comm_intsram_code
$other_intsram_code
    }
    INTSRAM_DATA 0xA0010400 0x00008400
    {
$comm_intsram_data
$other_intsram_data
    }
__TEMPLATE_6228
    # --- --- --- 
    my %BBtbl =
       (        'MT6217'  => $template_6217,
                'MT6218B' => $template_6217,
                'MT6219'  => $template_6219,
                'MT6225'  => $template_6225,
                'MT6226'  => $template_6227,
                'MT6226M' => $template_6227,
                'MT6227'  => $template_6227,
                'MT6227D' => $template_6227D,
                'MT6226D' => $template_6227D,
                'MT6228'  => $template_6228,
                'MT6229'  => $template_6228,
                'MT6230'  => $template_6228,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    die "NOT defined $bb " if not defined $BBtbl{$bb};
    return $BBtbl{$bb};
}


#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: system
# input:       BB
# remark:      But regard it 
#****************************************************************************
sub INTSRAM_CODE_OBJ_system
{
    my ($bb) = @_;
    my $template_sys = << "__TEMPLATE";
; system-realted CODE , STANDARD set
         bootarm.obj (INTERNCODE)
         init.obj (SNORCODE)
         custom_emi.obj (INTERNCODE)
         isrentry.obj (INTERNCODE)
         data_buff_pool.obj (INTERNCODE)
         ctrl_buff_pool.obj (INTERNCODE)
         stack_buff_pool.obj (INTERNCODE)
         stack_ltlcom.obj (INTERNCODE)
         stack_timer.obj (INTERNCODE)
         lcd_dll.obj (INTERNCODE)
         event_shed.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE, INTERNCONST)
__TEMPLATE
    my $template_small_sys = << "__TEMPLATE";
; system-realted CODE , SMALL set
         bootarm.obj (INTERNCODE)
         init.obj (SNORCODE)
         custom_emi.obj (INTERNCODE)
         isrentry.obj (INTERNCODE)
         data_buff_pool.obj (INTERNCODE)
         ctrl_buff_pool.obj (INTERNCODE)
         stack_buff_pool.obj (INTERNCODE)
         stack_ltlcom.obj (INTERNCODE)
         stack_timer.obj (INTERNCODE)
         SST_intrCtrl.obj (INTERNCODE, INTERNCONST)
__TEMPLATE
    # --- --- --- 
    my $template_lib = << "__TEMPLATE";
; common used C library
         memset.o (+RO)
         rt_memclr.o (+RO)
         callvia.o (+RO)
         _sprintf.o (+RO)
         rt_memcpy.o (+RO)
         lludiv10.o (+RO)
         rt_udiv.o (+RO)
         uread4.o (+RO)
         uwrite4.o (+RO)
__TEMPLATE
    # --- --- --- 
    my $template_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , STANDARD set
         tct.obj (+RO)
         tcc.obj (INTERNCODE)
         csc.obj (INTERNCODE)
         tmt.obj (+RO)
         tms.obj (+RO)
         smc.obj (+RO)
         evc.obj (+RO)
         pmc.obj (+RO)
         quc.obj (+RO)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_small_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , SMALL set
         tct.obj (+RO)
         tcc.obj (INTERNCODE)
         csc.obj (INTERNCODE)
         tmt.obj (+RO)
         smc.obj (INTERNCODE)
         evc.obj (INTERNCODE)
         pmc.obj (INTERNCODE)
         quc.obj (INTERNCODE)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_nfb_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , NFB set
         *nucleus_ctrl_code.lib (+RO)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_nfb_small_nucleus = << "__TEMPLATE";
; Nucleus-related CODE , NFB set (Small Configure)
         *nucleus_ctrl_code.lib (INTERNCODE)
         kal_nucleus_buff_mgr.obj (INTERNCODE)
         kal_nucleus_evshed_buff_mgr.obj (INTERNCODE)
         kal_nucleus_itc.obj (INTERNCODE)
         kal_nucleus_timer.obj (INTERNCODE)
__TEMPLATE
    # --- --- --- 
    my $template_threadx = << "__TEMPLATE";
; THREADX-related CODE , STANDARD set
         tx_thread_interrupt_disable.obj (+RO)
         tx_thread_interrupt_restore.obj (+RO)
         tx_thread_context_save.obj (+RO)
         tx_thread_context_restore.obj (+RO)
         tx_thread_irq_nesting_start.obj (+RO)
         tx_thread_irq_nesting_end.obj (+RO)
         tx_thread_system_return.obj (+RO)
         tx_thread_schedule.obj (+RO)
         tx_thread_resume.obj (+RO)
         tx_thread_system_resume.obj (+RO)
         tx_timer_interrupt.obj (+RO)
         tx_timer_thread_entry.obj (+RO)
         tx_block_allocate.obj (+RO)
         tx_block_release.obj (+RO)
         tx_event_flags_get.obj (+RO)
         tx_event_flags_set.obj (+RO)
         tx_mutex_get.obj (+RO)
         tx_mutex_put.obj (+RO)
         kal_threadx_tasks.obj (INTERNCODE)
         kal_threadx_buff_mgr.obj (INTERNCODE)
         kal_threadx_itc.obj (INTERNCODE)
         kal_threadx_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_small_threadx = << "__TEMPLATE";
; THREADX-related CODE , SMALL set
         ; UNDER CONSTRUCTION
         tx_thread_interrupt_disable.obj (+RO)
         tx_thread_interrupt_restore.obj (+RO)
         tx_thread_context_save.obj (+RO)
         tx_thread_context_restore.obj (+RO)
         tx_thread_irq_nesting_start.obj (+RO)
         tx_thread_irq_nesting_end.obj (+RO)
         tx_thread_system_return.obj (+RO)
         tx_thread_schedule.obj (+RO)
         tx_thread_resume.obj (+RO)
         tx_thread_system_resume.obj (+RO)
         tx_timer_interrupt.obj (+RO)
         tx_timer_thread_entry.obj (+RO)
         tx_block_allocate.obj (+RO)
         tx_block_release.obj (+RO)
         tx_event_flags_get.obj (+RO)
         tx_event_flags_set.obj (+RO)
         tx_mutex_get.obj (+RO)
         tx_mutex_put.obj (+RO)
         kal_threadx_tasks.obj (INTERNCODE)
         kal_threadx_buff_mgr.obj (INTERNCODE)
         kal_threadx_itc.obj (INTERNCODE)
         kal_threadx_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_nfb_threadx = << "__TEMPLATE";
; THREADX-related CODE , NFB set
         *threadx_ctrl_code.lib (+RO)
         kal_threadx_tasks.obj (INTERNCODE)
         kal_threadx_buff_mgr.obj (INTERNCODE)
         kal_threadx_itc.obj (INTERNCODE)
         kal_threadx_timer.obj (INTERNCODE)
__TEMPLATE
    my $template_nfb_small_threadx = << "__TEMPLATE";
; THREADX-related CODE , NFB set (Small Configure)
         *threadx_ctrl_code.lib (INTERNCODE)
         kal_threadx_tasks.obj (INTERNCODE)
         kal_threadx_buff_mgr.obj (INTERNCODE)
         kal_threadx_itc.obj (INTERNCODE)
         kal_threadx_timer.obj (INTERNCODE)
__TEMPLATE
    # --- --- --- 
    my $template;
    my $nfb      = &$feature_query_function_ptr('nand_flash_booting');
    # --- --- --- 
    my %BBtbl_dcm = # Place the MCU list with DCM facility
       (        'MT6225'  => 1, # must  if  synchronous access memory device or DRAM
                'MT6228'  => 1, # must  if  synchronous access memory device or DRAM
                'MT6229'  => 1, # must  if  synchronous access memory device or DRAM
                'MT6230'  => 1, # must  if  synchronous access memory device or DRAM
                'MT6227D' => 1, # must  if  synchronous access memory device
                'MT6226D' => 1, # must  if  synchronous access memory device
                'MT6223'  => 1, # must  if  synchronous access memory device
                'MT6223P' => 1, # must  if  synchronous access memory device
                'MT6227'  => 1, # must  if ESBNOR
                'MT6226'  => 1, # must  if ESBNOR
                'MT6226M' => 1, # must  if ESBNOR
       );
    if (defined $BBtbl_dcm{$bb} and $BBtbl_dcm{$bb})
    {    $template .= " " x 9 . "custom_switchclock.obj (INTERNCODE)" . "\n";
         $template .= " " x 9 . "idle_task.obj (INTERNCODE)" . "\n";
    }
    # --- --- --- 
    my %BBtbl_cache = # Place the MCU list with cache facility
       (        'MT6225'  => 1,
                'MT6228'  => 1,
                'MT6229'  => 1,
                'MT6230'  => 1,
       );
    if (defined $BBtbl_cache{$bb} and $BBtbl_cache{$bb})
    {    $template .= " " x 9 . "cache.obj (INTERNCODE)" . "\n";
    }
    # --- --- --- 
    my %BBtbl_cfg = # Place the MCU list for small configure
       (        'MT6225'  => 1,
       );      
    if (defined $BBtbl_cfg{$bb} and $BBtbl_cfg{$bb})
    {
       if (defined $nfb and $nfb eq 'TRUE')
       {
           $template = $template_small_sys . $template .
                       $template_nfb_small_nucleus . $template_nfb_small_threadx;
       }
       else
       {
           $template = $template_small_sys . $template .
                       $template_small_nucleus . $template_small_threadx . $template_lib;
       }
    }
    else # small configure ?
    {
       if (defined $nfb and $nfb eq 'TRUE')
       {
           $template = $template_sys . $template .
                       $template_nfb_nucleus . $template_nfb_threadx;
       }
       else
       {
           $template = $template_sys . $template .
                       $template_nucleus . $template_threadx . $template_lib;
       }
    }
    # --- --- --- 
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: system
# input:       BB
# remark:      But regard it 
#****************************************************************************
sub INTSRAM_DATA_OBJ_system
{
    my ($bb) = @_;
    my $template_sys = << "__TEMPLATE";
; system-realted data
         bootarm.obj (STACK_POOL_INTSRAM)
         isrentry.obj (INTERNCONST, INTERNRW, INTERNZI)
         stack_init.obj (INTERNCONST, INTERNRW, INTERNZI)
         ctrl_buff_pool.obj (INTERNCONST, INTERNRW, INTERNZI)
         stack_ltlcom.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    # --- --- --- 
    my $template_nucleus = << "__TEMPLATE";
; Nucleus-related data ; Standard set
         tst*.obj (INTERNCONST, INTERNRW, INTERNZI)
         tct.obj (+RW, +ZI)
         tcd.obj (INTERNCONST, INTERNRW, INTERNZI)
         tmd.obj (+RW, +ZI)
         evd.obj (+RW, +ZI)
         pmd.obj (+RW, +ZI)
         qud.obj (+RW, +ZI)
         smd.obj (+RW, +ZI)
__TEMPLATE
    # --- --- --- 
    my $template_threadx = << "__TEMPLATE";
; THREADX-related data ; Standard set
         tx_thread_initialize.obj (+RW, +ZI)
         tx_timer_initialize.obj (+RW, +ZI)
__TEMPLATE
    # --- --- --- 
    my $template_nucleus_nfb = << "__TEMPLATE";
; Nucleus-related data ; Standard set on NFB
         *nucleus_critical_data.lib (+RW, +ZI)
         *nucleus_ctrl_code.lib (+RW, +ZI)
__TEMPLATE
    # --- --- --- 
    my $template_threadx_nfb = << "__TEMPLATE";
; THREADX-related data ; Standard set on NFB
         *threadx_ctrl_data.lib (+RW, +ZI)
__TEMPLATE
    # --- --- --- 
    my $template_nucleus_nfb_small = << "__TEMPLATE";
; Nucleus-related data ; Small set on NFB
         *nucleus_critical_data.lib (INTERNCONST, INTERNRW, INTERNZI)
         *nucleus_ctrl_code.lib (INTERNDATA)
__TEMPLATE
    # --- --- --- 
    my $template_threadx_nfb_small = << "__TEMPLATE";
; THREADX-related data ; Small set on NFB (same with Standard)
         *threadx_ctrl_data.lib (+RW, +ZI)
__TEMPLATE
    # --- --- --- 
    my $nfb      = &$feature_query_function_ptr('nand_flash_booting');
    my %BBtbl_dcm = # Place the MCU list with DCM facility
       (        'MT6225'  => 1, # must  if  synchronous access memory device or DRAM
                'MT6228'  => 1, # must  if  synchronous access memory device or DRAM
                'MT6229'  => 1, # must  if  synchronous access memory device or DRAM
                'MT6230'  => 1, # must  if  synchronous access memory device or DRAM
                'MT6227D' => 1, # must  if  synchronous access memory device
                'MT6226D' => 1, # must  if  synchronous access memory device
                'MT6223'  => 1, # must  if  synchronous access memory device
                'MT6223P' => 1, # must  if  synchronous access memory device
                'MT6227'  => 1, # must  if ESBNOR
                'MT6226'  => 1, # must  if ESBNOR
                'MT6226M' => 1, # must  if ESBNOR
       );
    if (defined $BBtbl_dcm{$bb} and $BBtbl_dcm{$bb})
    {    $template_sys .= " " x 9 . "custom_switchclock.obj (INTERNCONST, INTERNRW, INTERNZI)" . "\n";
         $template_sys .= " " x 9 . "idle_task.obj (INTERNCONST, INTERNRW, INTERNZI)" . "\n";
    }
    # --- --- --- 
    my $template;
    my %BBtbl_cfg = # Place the MCU list for small configure
       (        'MT6225'  => 1,
       );      
    if (defined $BBtbl_cfg{$bb} and $BBtbl_cfg{$bb})
    {
       if (defined $nfb and $nfb eq 'TRUE')
       {
           $template = $template_sys . $template_nucleus_nfb_small . $template_threadx_nfb_small;
       }
       else
       {
           $template = $template_sys . $template_nucleus . $template_threadx;
       }
    }
    else # small configure ?
    {
       if (defined $nfb and $nfb eq 'TRUE')
       {
           $template = $template_sys . $template_nucleus_nfb . $template_threadx_nfb;
       }
       else
       {
           $template = $template_sys . $template_nucleus . $template_threadx;
       }
    }
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others
{
    my ($bb) = @_;
    my %BBtbl =
       (        'MT6217'  => &INTSRAM_CODE_OBJ_others_6217(),
                'MT6218B' => &INTSRAM_CODE_OBJ_others_6218(),
                'MT6219'  => &INTSRAM_CODE_OBJ_others_6219(),
                'MT6225'  => &INTSRAM_CODE_OBJ_others_6225(),
                'MT6226'  => &INTSRAM_CODE_OBJ_others_6227(),
                'MT6226M' => &INTSRAM_CODE_OBJ_others_6227(),
                'MT6227'  => &INTSRAM_CODE_OBJ_others_6227(),
                'MT6227D' => &INTSRAM_CODE_OBJ_others_6227D(),
                'MT6226D' => &INTSRAM_CODE_OBJ_others_6227D(),
                'MT6228'  => &INTSRAM_CODE_OBJ_others_6228(),
                'MT6229'  => &INTSRAM_CODE_OBJ_others_6228(),
                'MT6230'  => &INTSRAM_CODE_OBJ_others_6228(),
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    die "NOT defined $bb " if not defined $BBtbl{$bb};
    # --- --- --- 
    my %BBtbl_cfg = # Place the MCU list for small configure
       (        'MT6225'  => 1,
       );      
    my $template = $BBtbl{$bb};
    my $nfb      = &$feature_query_function_ptr('nand_flash_booting');
    
    if (defined $nfb and $nfb eq 'TRUE')
    {
        if (defined $BBtbl_cfg{$bb} and $BBtbl_cfg{$bb})
        {
            $template =~ s/cam_module\.obj/;cam_module\.obj/;
        }
    }
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6217
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6217
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6217
         mpal_gprs_common_func.obj (INTERNCODE)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCODE)
         m11194.obj (INTERNCODE)
         m11191.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE)
         l1d_internal_data.obj (INTERNCODE)
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12168.obj (INTERNCODE)
         m12180.obj (INTERNCODE)                  
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)         
         m12194.obj (INTERNCODE)                  
         midisyn.obj (INTERNCODE)
         cam_module.obj (INTERNCODE)
         wav.obj (INTERNCODE)
         wav_codec.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_gif.obj (INTERNCODE)
         gdi_bytestream.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         gdi_image_alpha_bmp.obj (INTERNCODE)
         cor_h.obj (INTERNCODE)
         convolve.obj (INTERNCODE)
         calc_cor.obj (INTERNCODE)
         pitch_fr.obj (INTERNCODE)
         syn_filt.obj (INTERNCODE)
         c2_9pf.obj (INTERNCODE)
         pred_lt.obj (INTERNCODE)
         q_plsf.obj (INTERNCODE)
         residu.obj (INTERNCODE)
         lpc.obj (INTERNCODE)
         pre_proc.obj (INTERNCODE)
         oper_32b.obj (INTERNCODE)
         qua_gain.obj (INTERNCODE)
         copy.obj (INTERNCODE)
         az_lsp.obj (INTERNCODE)
         weight_a.obj (INTERNCODE)
         pitch_ol.obj (INTERNCODE)
         calc_en.obj (INTERNCODE)
         spstproc.obj (INTERNCODE)
         lsp_az.obj (INTERNCODE)
         cl_ltp.obj (INTERNCODE)
         bytecodesasm.obj (INTERNCODE)
         j2me_custom_lcd.obj (INTERNCODE)
         execute.obj (INTERNCODE)
         native.obj (INTERNCODE)
         file62.o (INTERNCODE)
         file12.o (INTERNCODE)
         file71.o (INTERNCODE)
         aes_engine.obj (INTERNCODE)
         gpt.obj(INTERNCODE)
         lpwr.obj(INTERNCODE)
__TEMPLATE
    return $template;
}
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6218
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6218
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6218
         mpal_gprs_common_func.obj (INTERNCODE)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCODE)
         m11194.obj (INTERNCODE)
         m11191.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE)
         l1d_internal_data.obj (INTERNCODE)
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12168.obj (INTERNCODE)
         m12180.obj (INTERNCODE)                  
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)         
         m12194.obj (INTERNCODE)                  
         midisyn.obj (INTERNCODE)
         cam_module.obj (INTERNCODE)
         wav.obj (INTERNCODE)
         wav_codec.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_gif.obj (INTERNCODE)
         gdi_bytestream.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         gdi_image_alpha_bmp.obj (INTERNCODE)
         cor_h.obj (INTERNCODE)
         convolve.obj (INTERNCODE)
         calc_cor.obj (INTERNCODE)
         pitch_fr.obj (INTERNCODE)
         syn_filt.obj (INTERNCODE)
         c2_9pf.obj (INTERNCODE)
         pred_lt.obj (INTERNCODE)
         q_plsf.obj (INTERNCODE)
         residu.obj (INTERNCODE)
         lpc.obj (INTERNCODE)
         pre_proc.obj (INTERNCODE)
         oper_32b.obj (INTERNCODE)
         qua_gain.obj (INTERNCODE)
         copy.obj (INTERNCODE)
         az_lsp.obj (INTERNCODE)
         weight_a.obj (INTERNCODE)
         pitch_ol.obj (INTERNCODE)
         calc_en.obj (INTERNCODE)
         spstproc.obj (INTERNCODE)
         lsp_az.obj (INTERNCODE)
         cl_ltp.obj (INTERNCODE)
         bytecodesasm.obj (INTERNCODE)
         j2me_custom_lcd.obj(INTERNCODE)
         execute.obj (INTERNCODE)
         native.obj (INTERNCODE)
         file62.o (INTERNCODE)
         file12.o (INTERNCODE)
         file71.o (INTERNCODE)
         gpt.obj(INTERNCODE)
         lpwr.obj(INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6219
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6219
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6219
         mpal_gprs_common_func.obj (INTERNCODE)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCODE)
         m11194.obj (INTERNCODE)
         m11191.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE)
         l1d_internal_data.obj (INTERNCODE)
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12168.obj (INTERNCODE)
         m12180.obj (INTERNCODE)
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)
         m12194.obj (INTERNCODE)
         midisyn.obj (INTERNCODE)
         cam_module.obj (INTERNCODE)
         wav.obj (INTERNCODE)
         wav_codec.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_gif.obj (INTERNCODE)
         gdi_bytestream.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         gdi_image_alpha_bmp.obj (INTERNCODE)
         cor_h.obj (INTERNCODE)
         convolve.obj (INTERNCODE)
         calc_cor.obj (INTERNCODE)
         pitch_fr.obj (INTERNCODE)
         syn_filt.obj (INTERNCODE)
         c2_9pf.obj (INTERNCODE)
         pred_lt.obj (INTERNCODE)
         q_plsf.obj (INTERNCODE)
         residu.obj (INTERNCODE)
         lpc.obj (INTERNCODE)
         pre_proc.obj (INTERNCODE)
         oper_32b.obj (INTERNCODE)
         qua_gain.obj (INTERNCODE)
         copy.obj (INTERNCODE)
         az_lsp.obj (INTERNCODE)
         weight_a.obj (INTERNCODE)
         pitch_ol.obj (INTERNCODE)
         calc_en.obj (INTERNCODE)
         spstproc.obj (INTERNCODE)
         lsp_az.obj (INTERNCODE)
         cl_ltp.obj (INTERNCODE)
         bytecodesasm.obj (INTERNCODE)
         j2me_custom_lcd.obj (INTERNCODE)
         execute.obj (INTERNCODE)
         native.obj (INTERNCODE)
         file62.o (INTERNCODE)
         file12.o (INTERNCODE)
         file71.o (INTERNCODE)
         img_resizer.obj(INTERNCODE)
         pngrutil.obj(INTERNCODE)
         app_zlib.obj(INTERNCODE)
         crc32.obj(INTERNCODE)
         aes_engine.obj(INTERNCODE)
         gpt.obj(INTERNCODE)
         lpwr.obj(INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6225
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6225
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6225
         mpal_gprs_common_func.obj (INTERNCODE)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         cam_module.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_gif.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         gpt.obj (INTERNCODE)
         *l1dsm.obj (SNORCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6227
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6227
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6227
         mpal_gprs_common_func.obj (INTERNCODE)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCODE)
         m11194.obj (INTERNCODE)
         m11191.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE)
         l1d_internal_data.obj (INTERNCODE)
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12168.obj (INTERNCODE)
         m12180.obj (INTERNCODE)                  
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)         
         m12194.obj (INTERNCODE)                  
         cam_module.obj (INTERNCODE)
         wav.obj (INTERNCODE)
         wav_codec.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_gif.obj (INTERNCODE)
         gdi_bytestream.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         gdi_image_alpha_bmp.obj (INTERNCODE)
         bytecodesasm.obj (INTERNCODE)
         j2me_custom_lcd.obj(INTERNCODE)
         execute.obj (INTERNCODE)
         native.obj (INTERNCODE)
         *rompatch.lib (INTERNCODE)
         file62.o (INTERNCODE)
         file12.o (INTERNCODE)
         file71.o (INTERNCODE) 
         *bchs.lib (BCHS_INTERNCODE)
         *bchsadp.lib (BCHS_INTERNCODE)
         aes_engine.obj (INTERNCODE)
         *l1dsm.obj (SNORCODE)
         gpt.obj (INTERNCODE)
         lpwr.obj (INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6227D
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6227D
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6227D
         mpal_gprs_common_func.obj (INTERNCODE)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCODE)
         m11194.obj (INTERNCODE)
         m11191.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE)
         l1d_internal_data.obj (INTERNCODE)
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12168.obj (INTERNCODE)
         m12180.obj (INTERNCODE)                  
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)         
         m12194.obj (INTERNCODE)                  
         cam_module.obj (INTERNCODE)
         wav.obj (INTERNCODE)
         wav_codec.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_gif.obj (INTERNCODE)
         gdi_bytestream.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         gdi_image_alpha_bmp.obj (INTERNCODE)
         bytecodesasm.obj (INTERNCODE)
         j2me_custom_lcd.obj(INTERNCODE)
         execute.obj (INTERNCODE)
         native.obj (INTERNCODE)
         file62.o (INTERNCODE)
         file12.o (INTERNCODE)
         file71.o (INTERNCODE) 
         *bchs.lib (BCHS_INTERNCODE)
         *bchsadp.lib (BCHS_INTERNCODE)
         aes_engine.obj (INTERNCODE)
         *l1dsm.obj (SNORCODE)
         gpt.obj (INTERNCODE)
         lpwr.obj (INTERNCODE)
         adcmeasure.obj (INTERNCODE)
         b2spi.obj (INTERNCODE)
         pmic6318.obj (INTERNCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM CODE content :: others :: 6228
# input:       BB
#****************************************************************************
sub INTSRAM_CODE_OBJ_others_6228
{
    my $template = << "__TEMPLATE";
; INTSRAM_CODE_OBJ_others_6228
         mpal_gprs_common_func.obj (INTERNCODE)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCODE)
         m11194.obj (INTERNCODE)
         m11191.obj (INTERNCODE)
         l1d_data.obj (INTERNCODE)
         l1d_internal_data.obj (INTERNCODE)
         m12100.obj (INTERNCODE)         
         m12110.obj (INTERNCODE)
         m12120.obj (INTERNCODE)
         m12160.obj (INTERNCODE)
         m12167.obj (INTERNCODE)
         m12170.obj (INTERNCODE)
         m12168.obj (INTERNCODE)
         m12180.obj (INTERNCODE)
         m11303.obj (INTERNCODE)
         m11305.obj (INTERNCODE)
         m12194.obj (INTERNCODE)
         cam_module.obj (INTERNCODE)
         divider.obj (INTERNCODE)
         L1Trc.obj (INTERNCODE)
         uart.obj (INTERNCODE)
         gdi_image_gif.obj (INTERNCODE)
         gdi_bytestream.obj (INTERNCODE)
         gdi_image_direct_gif.obj (INTERNCODE)
         gdi_mutex.obj (INTERNCODE)
         file62.o (INTERNCODE)
         file12.o (INTERNCODE)
         file71.o (INTERNCODE)
         jvm_runtime.obj (INTERNCODE)
         *l1dsm.obj (SNORCODE)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others
{
    my ($bb) = @_;
    my %BBtbl =
       (        'MT6217'  => &INTSRAM_DATA_OBJ_others_6217(),
                'MT6218B' => &INTSRAM_DATA_OBJ_others_6218(),
                'MT6219'  => &INTSRAM_DATA_OBJ_others_6219(),
                'MT6225'  => &INTSRAM_DATA_OBJ_others_6225(),
                'MT6226'  => &INTSRAM_DATA_OBJ_others_6227(),
                'MT6226M' => &INTSRAM_DATA_OBJ_others_6227(),
                'MT6227'  => &INTSRAM_DATA_OBJ_others_6227(),
                'MT6227D' => &INTSRAM_DATA_OBJ_others_6227D(),
                'MT6226D' => &INTSRAM_DATA_OBJ_others_6227D(),
                'MT6228'  => &INTSRAM_DATA_OBJ_others_6228(),
                'MT6229'  => &INTSRAM_DATA_OBJ_others_6228(),
                'MT6230'  => &INTSRAM_DATA_OBJ_others_6228(),
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    die "NOT defined $bb " if not defined $BBtbl{$bb};
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6217
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6217
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6217
         mpal_gprs_common_func.obj (INTERNCONST, INTERNRW, INTERNZI)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11194.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11191.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)         
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         midisyn.obj (INTERNCONST, INTERNRW, INTERNZI)
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image_gif.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_bytestream.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)
         wav.obj (INTERNCONST, INTERNRW, INTERNZI)
         wav_codec.obj (INTERNCONST, INTERNRW, INTERNZI)
         cod_amr.obj (INTERNCONST, INTERNRW, INTERNZI)
         pred_lt.obj (INTERNCONST, INTERNRW, INTERNZI)
         syn_filt.obj (INTERNCONST, INTERNRW, INTERNZI)
         q_plsf.obj (INTERNCONST, INTERNRW, INTERNZI)
         lpc.obj (INTERNCONST, INTERNRW, INTERNZI)
         pre_proc.obj (INTERNCONST, INTERNRW, INTERNZI)
         spstproc.obj (INTERNCONST, INTERNRW, INTERNZI)
         interpret.obj(INTERNZI)
         file71.o(INTERNCONST, INTERNRW, INTERNZI)
         gpt.obj (INTERNCONST, INTERNRW, INTERNZI)
         lpwr.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6218
# input:       BB
# Remark:      simd.obj is specific for MT6218B only
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6218
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6218
         mpal_gprs_common_func.obj (INTERNCONST, INTERNRW, INTERNZI)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11194.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11191.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)         
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         midisyn.obj (INTERNCONST, INTERNRW, INTERNZI)
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image_gif.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_bytestream.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)
         wav.obj (INTERNCONST, INTERNRW, INTERNZI)
         wav_codec.obj (INTERNCONST, INTERNRW, INTERNZI)
         cod_amr.obj (INTERNCONST, INTERNRW, INTERNZI)
         pred_lt.obj (INTERNCONST, INTERNRW, INTERNZI)
         syn_filt.obj (INTERNCONST, INTERNRW, INTERNZI)
         q_plsf.obj (INTERNCONST, INTERNRW, INTERNZI)
         lpc.obj (INTERNCONST, INTERNRW, INTERNZI)
         pre_proc.obj (INTERNCONST, INTERNRW, INTERNZI)
         spstproc.obj (INTERNCONST, INTERNRW, INTERNZI)
         simd.obj(INTERNRW, INTERNZI)
         interpret.obj (INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)
         gpt.obj (INTERNCONST, INTERNRW, INTERNZI)
         lpwr.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6219
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6219
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6219
         mpal_gprs_common_func.obj (INTERNCONST, INTERNRW, INTERNZI)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11194.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11191.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)
         midisyn.obj (INTERNCONST, INTERNRW, INTERNZI)
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_bytestream.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)
         wav.obj (INTERNCONST, INTERNRW, INTERNZI)
         wav_codec.obj (INTERNCONST, INTERNRW, INTERNZI)
         cod_amr.obj (INTERNCONST, INTERNRW, INTERNZI)
         pred_lt.obj (INTERNCONST, INTERNRW, INTERNZI)
         syn_filt.obj (INTERNCONST, INTERNRW, INTERNZI)
         q_plsf.obj (INTERNCONST, INTERNRW, INTERNZI)
         lpc.obj (INTERNCONST, INTERNRW, INTERNZI)
         pre_proc.obj (INTERNCONST, INTERNRW, INTERNZI)
         spstproc.obj (INTERNCONST, INTERNRW, INTERNZI)
         interpret.obj (INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)
         gpt.obj (INTERNCONST, INTERNRW, INTERNZI)
         lpwr.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6225
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6225
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6225
         mpal_gprs_common_func.obj (INTERNCONST, INTERNRW, INTERNZI)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)
         interpret.obj (INTERNZI)
         sw_jpeg_decoder.obj (INTERNRW1, INTERNZI1)
         jpeg_encoder.obj (+RW, +ZI)
         med_main.obj (INTERNRW2, INTERNZI2)
__TEMPLATE
    return $template;
}
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6227
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6227
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6227
         mpal_gprs_common_func.obj (INTERNCONST, INTERNRW, INTERNZI)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11194.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11191.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_bytestream.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)
         wav.obj (INTERNCONST, INTERNRW, INTERNZI)
         wav_codec.obj (INTERNCONST, INTERNRW, INTERNZI)
         interpret.obj (INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)
         *bchs.lib (BCHS_INTERNZI)
         *bchsadp.lib (BCHS_INTERNZI)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6227D
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6227D
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6227D
         mpal_gprs_common_func.obj (INTERNCONST, INTERNRW, INTERNZI)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11194.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11191.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_bytestream.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)
         wav.obj (INTERNCONST, INTERNRW, INTERNZI)
         wav_codec.obj (INTERNCONST, INTERNRW, INTERNZI)
         interpret.obj (INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)
         *bchs.lib (BCHS_INTERNZI)
         *bchsadp.lib (BCHS_INTERNZI)
         pmic6318.obj (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DATA content :: others :: 6228
# input:       BB
#****************************************************************************
sub INTSRAM_DATA_OBJ_others_6228
{
    my $template = << "__TEMPLATE";
; INTSRAM_DATA_OBJ_others_6228
         mpal_gprs_common_func.obj (INTERNCONST, INTERNRW, INTERNZI)
         mpal_gprs_dl_msg_hdlr.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11194.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11191.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         l1d_internal_data.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12100.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12110.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12120.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12160.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12167.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12170.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12168.obj (INTERNCONST, INTERNRW, INTERNZI)
         m12180.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         m11303.obj (INTERNCONST, INTERNRW, INTERNZI)
         m11305.obj (INTERNCONST, INTERNRW, INTERNZI)         
         m12194.obj (INTERNCONST, INTERNRW, INTERNZI)                  
         L1Trc.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_image.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi_bytestream.obj (INTERNCONST, INTERNRW, INTERNZI)
         gdi.obj (INTERNZI)         
         interpret.obj (INTERNZI)
         file71.o (INTERNCONST, INTERNRW, INTERNZI)
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM MED content
# input:       BB  ,  OVERLAY indication
#****************************************************************************
sub INTSRAM_MED_EV
{
    my ($bb, $overlay) = @_;
    $overlay = "OVERLAY" if defined $overlay;
    my $med_template_A = << "__MULTIMEDIA_A";
    INTSRAM_MULTIMEDIA 0x40020000 0x00060000
    {
         med_main.obj (INTERNRW1, INTERNZI1) 
         gdi_layer.obj (INTERNRW1, INTERNZI1) 
         gdi_image_gif.obj (INTERNZI)
    }
__MULTIMEDIA_A
    # --- --- --- 
    my $med_template_B = << "__MULTIMEDIA_B";
    INTSRAM_MULTIMEDIA 0x4001D800 0x00029800
    {
         med_main.obj (INTERNRW1, INTERNZI1)
         isp_comm.obj (INTERNRW1, INTERNZI1)
    }
__MULTIMEDIA_B
    # --- --- --- 
    my $med_template_C = << "__MULTIMEDIA_C";
    INTSRAM_MULTIMEDIA 0x40000000 $overlay 0x00020000
    {
         ae.obj (INTERNRW1, INTERNZI1) 
         isp_comm.obj (INTERNRW1, INTERNZI1) 
         med_main.obj (INTERNRW1, INTERNZI1) 
    }
__MULTIMEDIA_C
    # --- --- --- 
    my $med_template_D = << "__MULTIMEDIA_D";
    INTSRAM_MULTIMEDIA 0x40000000 $overlay 0xC000
    {
         med_main.obj (INTERNRW1, INTERNZI1)
         isp_comm.obj (INTERNRW1, INTERNZI1)
    }
__MULTIMEDIA_D
    # --- --- --- 
    my %BBtbl =
       (        'MT6219'  => $med_template_A,
                'MT6225'  => $med_template_D,
                'MT6226'  => $med_template_B,
                'MT6226M' => $med_template_B,
                'MT6227'  => $med_template_B,
                'MT6227D' => $med_template_B,
                'MT6226D' => $med_template_B,
                'MT6228'  => $med_template_C,
                'MT6229'  => $med_template_C,
                'MT6230'  => $med_template_C,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# subroutine:  NFB Layout :: ROM :: Exec View :: INTSRAM type :: SYS-RAM BOOTLOADER USED INDICATION
# input:       BB
#****************************************************************************
sub INTSRAM_BLINUSED_EV
{
    my ($bb) = @_;
    # --- --- --- 
    my $med_template_C = << "__BLINUSED_C";
    INTSRAM_BLINUSED 0x40000000 OVERLAY 0x00020000
    {
    ; Execution Region Reserved for Bootloader
    }
__BLINUSED_C
    # --- --- --- 
    my $med_template_D = << "__BLINUSED_D";
    INTSRAM_BLINUSED 0x40000000 OVERLAY 0xC000
    {
    ; Execution Region Reserved for Bootloader
    }
__BLINUSED_D
    # --- --- --- 
    my %BBtbl =
       (
                'MT6225'  => $med_template_D,
                'MT6228'  => $med_template_C,
                'MT6229'  => $med_template_C,
                'MT6230'  => $med_template_C,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    return $BBtbl{$bb};
}

#****************************************************************************
# Global Table  ,  DCM id table
#****************************************************************************
    my %DCMidtbl =
       (       'DYNAMIC_CODE1' => 'AMR515',
               'DYNAMIC_CODE2' => 'G3D',
               'DYNAMIC_CODE3' => 'CTM',
               'DYNAMIC_CODE4' => 'G729',
               'DYNAMIC_CODE5' => 'SBC',
               'DYNAMIC_CODE6' => 'BCODE',
               'DYNAMIC_CODE7' => 'REVERB',
               'DYNAMIC_CODE8' => 'RESAMPLE',
       );
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: INTSRAM type :: INTSRAM DCM content
# input:       BB
#****************************************************************************
sub INTSRAM_DCM_EV
{
    my ($bb) = @_;
    my %DCMcfg_A =
       (       'DYNAMIC_CODE1' => [ 0x40018800, 0x5000 ],
               'DYNAMIC_CODE2' => [ 0x40018800, 0x5000 ],
               'DYNAMIC_CODE3' => [ 0x40018800, 0x5000 ],
               'DYNAMIC_CODE4' => [ 0x40018800, 0x5000 ],
               'DYNAMIC_CODE5' => [ 0x40018800, 0x5000 ],
               'DYNAMIC_CODE6' => [ 0x40018800, 0x5000 ],
               'DYNAMIC_CODE7' => [ 0x40018800, 0x5000 ],
               'DYNAMIC_CODE8' => [ 0x40018800, 0x5000 ],
       );
    my %DCMcfg_B =
       (       'DYNAMIC_CODE1' => [ 0xA001B000, 0x5000 ],
               'DYNAMIC_CODE2' => [ 0xA0018800, 0x2800 ],
               'DYNAMIC_CODE3' => [ 0xA001B000, 0x5000 ],
               'DYNAMIC_CODE4' => [ 0xA001B000, 0x5000 ],
               'DYNAMIC_CODE5' => [ 0xA001B000, 0x5000 ],
       );
    my %DCMcfg_C =
       (       'DYNAMIC_CODE1' => [ 0xA000D000, 0x5000 ],
               'DYNAMIC_CODE2' => [ 0xA000D000, 0x5000 ],
               'DYNAMIC_CODE3' => [ 0xA000D000, 0x5000 ],
               'DYNAMIC_CODE4' => [ 0xA000D000, 0x5000 ],
               'DYNAMIC_CODE5' => [ 0xA000D000, 0x5000 ],
       );
    # --- --- --- 
    my %BBtbl =
       (        'MT6225'  => \%DCMcfg_C,
                'MT6226'  => \%DCMcfg_A,
                'MT6226M' => \%DCMcfg_A,
                'MT6227'  => \%DCMcfg_A,
                'MT6227D' => \%DCMcfg_A,
                'MT6226D' => \%DCMcfg_A,
                'MT6228'  => \%DCMcfg_B,
                'MT6229'  => \%DCMcfg_B,
                'MT6230'  => \%DCMcfg_B,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    my $href = $BBtbl{$bb};
    my @list = sort { $href->{$a}->[0] <=> $href->{$b}->[0] or $a cmp $b } keys %$href;
       #map {print $_, "\n";} @list;
    my $result;
    foreach my $region (@list)
    {
        my $section =        $DCMidtbl{$region} . "_DYNAMIC_CODE";
        $section   .= ", " . $DCMidtbl{$region} . "_DYNAMIC_ZI";

        $result .= &format_execution_view( $region, 
                                           sprintf("0x%08x", $href->{$region}->[0]),
                                           sprintf("OVERLAY 0x%04x", $href->{$region}->[1]),
                                           ["* ($section)"]
                                         );
    }
    return $result;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM type 6 :: EXTSRAM DCM content
# input:       BB , begin address
#****************************************************************************
sub EXTSRAM_DCM_EV
{
    my ($bb, $addr) = @_;
    my %DCMcfg_C =
       (       'DYNAMIC_CODE1' => [ $addr + 0x2800 , 0x5000 ],
               'DYNAMIC_CODE2' => [ $addr          , 0x2800 ],
               'DYNAMIC_CODE3' => [ $addr + 0x2800 , 0x5000 ],
               'DYNAMIC_CODE4' => [ $addr + 0x2800 , 0x5000 ],
               'DYNAMIC_CODE5' => [ $addr + 0x2800 , 0x5000 ],
               'DYNAMIC_CODE7' => [ $addr + 0x2800 , 0x5000 ],
               'DYNAMIC_CODE8' => [ $addr + 0x2800 , 0x5000 ],
       );
    # --- --- --- 
    my %BBtbl =
       (        'MT6225'  => \%DCMcfg_C,
       );
       #map {print $_, "\n";} keys %BBtbl;
    die "unsupported $bb " if not exists $BBtbl{$bb}; 
    # --- --- --- 
    my $href = $BBtbl{$bb};
    my @list = sort { $href->{$a}->[0] <=> $href->{$b}->[0] or $a cmp $b } keys %$href;
       #map {print $_, "\n";} @list;
    my $result;
    foreach my $region (@list)
    {
        my $section =        $DCMidtbl{$region} . "_DYNAMIC_CODE";
        $section   .= ", " . $DCMidtbl{$region} . "_DYNAMIC_ZI";

        $result .= &format_execution_view( $region, 
                                           sprintf("0x%08x", $href->{$region}->[0]),
                                           sprintf("OVERLAY 0x%04x", $href->{$region}->[1]),
                                           ["* ($section)"]
                                         );
    }
    return $result;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: DSP TX RX :: Size Of TX RX query
# input:       BB , Mode (BASIC, L1S, GSM, GPRS, UMTS)
#****************************************************************************
sub DSPTXRX_query_length
{
    my ($bb, $mode) = @_;

    # --- --- --- 
    my %BBtbl_gprs =
       (        'MT6229'  => 0x20000,
                'MT6230'  => 0x20000,
                'MT6223'  => 0x02000,
                'MT6223P' => 0x02000,
       );
       #map {print $_, "\n";} keys %BBtbl;
    my %BBtbl_gsm =
       (        'MT6229'  => 0x20000,
                'MT6230'  => 0x20000,
                'MT6223'  => 0x01000,
                'MT6223P' => 0x01000,
       );
       #map {print $_, "\n";} keys %BBtbl;
    # --- --- --- 
    if ($mode eq 'GPRS')
    {
       die "unsupported $bb " if not exists $BBtbl_gprs{$bb}; 
       return $BBtbl_gprs{$bb};
    }
    elsif ($mode eq 'GSM')
    {
       die "unsupported $bb " if not exists $BBtbl_gsm{$bb}; 
       return $BBtbl_gsm{$bb};
    }

    #   die "unsupported $bb " if not exists $BBtbl_gsm{$bb}; 
    #   print "MODE : $mode\n";
       return 0x20000;
}

#****************************************************************************
# subroutine:  Default Layout :: ROM :: limit ROM size for cache channel
# return:      the ROM limit length
#****************************************************************************
sub ROMlength_calc
{
    my ($bb, $fs) = @_;

    # --- --- --- 
    my %BBtbl =
       (        'MT6229'  => 0x400000 * 6,
                'MT6230'  => 0x400000 * 6,
                'MT6228'  => 0x400000 * 6,
       );
    # --- --- --- 
    if (exists $BBtbl{$bb} and $fs > $BBtbl{$bb})
    {
       return $BBtbl{$bb};
    }
    return $fs;
}
