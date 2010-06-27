#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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

if ($#ARGV != 3) { &Usage; }

$file = $ARGV[0];
$verno_file = $ARGV[1];
$scatter_file = $ARGV[2];
$themf = $ARGV[3];

die "$themf did NOT exist!\n" if (!-e $themf);
open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $${keyname} = uc($2);
  }
}

if ($platform =~ /MT6228/i) {
  $rom_info_ver = "MTK_BLOADER_INFO_v02\0\0\0\0";
} elsif ($platform =~ /MT62(29|30)/i) {
  $rom_info_ver = "MTK_BLOADER_INFO_v03\0\0\0\0";
} elsif ($platform =~ /MT6225/i) {
  $rom_info_ver = "MTK_BLOADER_INFO_v02\0\0\0\0";
} else {
  die "Do not support rom_info_ver for PLATFORM=${platform}\n";
}
$emi_file = "custom\\system\\${board_ver}\\custom_emi.h";

(!-e "${file}") && die "${file} does NOT exist!\n";
(!-e "${verno_file}") && die "${verno_file} does NOT exist!\n";
(!-e "${scatter_file}") && die "${scatter_file} does NOT exist!\n";
(!-e "${emi_file}") && die "${emi_file} does NOT exist!\n";

open (VERNO, "<${verno_file}") or die "cannot open ${verno_file}\n";
while (<VERNO>) {
  next if (/^\s*\/\//);
  if (/const\s+\S+\s+CHECKSUM_SEED\s+=\s+0x([0-9A-Fa-f]+)/) {
    (defined($checksum_seed)) && warn "checksum_seed redefined!";
    $checksum_seed = hex $1;
  } elsif (/const\s+\S+\s+BootLDVerno\[\d+\]\s+=\s+"(\S+)"/) {
    (defined($verno_str)) && warn "verno_str redefined!";
    $verno_str = $1;
  }
}
close VERNO;
(!defined($checksum_seed)) && die "checksum_seed does NOT exist!";
(!defined($verno_str)) && die "verno_str does NOT exist!";

open (SCATTER, "<${scatter_file}") or die "cannot open ${scatter_file}\n";
while (<SCATTER>) {
  next if (/^;/);
  if (/READ_ONLY\s+0x([0-9A-Fa-f]+)/) {
    $start_addr = hex $1;
    last;
  }
}
close SCATTER;
(!defined($start_addr)) && die "Start address does NOT exist!";

open (EMI, "<${emi_file}") or die "cannot open ${emi_file}\n";
while (<EMI>) {
  next if ($_ !~ /^#define\s+EMI_/);
  if (/^#define\s+EMI_DRAM_RERESH_CONTROL\s+0x([0-9A-Fa-f]+)/) {
    (defined($emi_dram_refresh_ctrl)) && warn "emi_dram_refresh_ctrl redefined!";
    $emi_dram_refresh_ctrl = hex $1;
  } elsif (/^#define\s+EMI_DRAM_EXT_MODE\s+0x([0-9A-Fa-f]+)/) {
    (defined($emi_dram_ext_mode)) && warn "emi_dram_ext_mode redefined!";
    $emi_dram_ext_mode = hex $1;
  } elsif (/^#define\s+EMI_DRAM_CONTROL\s+0x([0-9A-Fa-f]+)/) {
    (defined($emi_dram_ctrl)) && warn "emi_dram_ctrl redefined!";
    $emi_dram_ctrl = hex $1;
  } elsif (/^#define\s+EMI_DRAM_MODE\s+0x([0-9A-Fa-f]+)/) {
    (defined($emi_dram_mode)) && warn "emi_dram_mode redefined!";
    $emi_dram_mode = hex $1;
  } elsif (/^#define\s+EMI_GENERAL_CONTROL1_VAL\s+0x([0-9A-Fa-f]+)/) {
    (defined($emi_gen_ctrl1)) && warn "emi_gen_ctrl1 redefined!";
    $emi_gen_ctrl1 = hex $1;
  } elsif (/^#define\s+EMI_GENERAL_CONTROL2_VAL\s+0x([0-9A-Fa-f]+)/) {
    (defined($emi_gen_ctrl2)) && warn "emi_gen_ctrl2 redefined!";
    $emi_gen_ctrl2 = hex $1;
  } elsif (/^#define\s+EMI_GENERAL_CONTROL3_VAL\s+0x([0-9A-Fa-f]+)/) {
    (defined($emi_gen_ctrl3)) && warn "emi_gen_ctrl3 redefined!";
    $emi_gen_ctrl3 = hex $1;
  }
}
close EMI;
(!defined($emi_dram_refresh_ctrl)) && die "EMI_DRAM_RERESH_CONTROL does NOT exist!";
(!defined($emi_dram_ctrl)) && die "EMI_DRAM_CONTROL does NOT exist!";
(!defined($emi_dram_ext_mode)) && die "EMI_DRAM_EXT_MODE does NOT exist!";
(!defined($emi_dram_mode)) && die "EMI_DRAM_MODE does NOT exist!";
(!defined($emi_gen_ctrl1)) && die "EMI_GENERAL_CONTROL1_VAL does NOT exist!";
(!defined($emi_gen_ctrl2)) && die "EMI_GENERAL_CONTROL2_VAL does NOT exist!";
(!defined($emi_gen_ctrl3)) && ($rom_info_ver =~ /v03/i) && die "EMI_GENERAL_CONTROL3_VAL does NOT exist!";

#****************************************************************************
# append information to the file
#****************************************************************************
$totalLen = 0;

open (FILE, ">>$file") or die "cannot open $file\n";
binmode(FILE);

print FILE $rom_info_ver;
$totalLen += length $rom_info_ver;

$binfilename = $file;
$binfilename =~ s/.*\\//g;
if (length ($binfilename) <= 64) {
  $binfilename .= "\0" x (64 - length ($binfilename));
} else {
  ##die "Length of \"$binfilename\" is more than 64!!!";
  $binfilename =~ s/^(.{64}).*$/$1/;
  warn "$binfilename\n";
}
$totalLen += length $binfilename;

print FILE $binfilename;
print FILE $verno_str;
print FILE pack("V1", $checksum_seed); #little endian
print FILE pack("V1", $start_addr);
print FILE pack("V1", $emi_gen_ctrl1);
print FILE pack("V1", $emi_gen_ctrl2);
($rom_info_ver =~ /v03/i) && print FILE pack("V1", $emi_gen_ctrl3);
print FILE pack("V1", $emi_dram_mode);
print FILE pack("V1", $emi_dram_ext_mode);
print FILE pack("V1", $emi_dram_ctrl);
print FILE pack("V1", $emi_dram_refresh_ctrl);
print FILE "MTK_BIN\0";
$totalLen += 44;
($rom_info_ver =~ /v03/i) && ($totalLen += 4);
print FILE pack("V1", $totalLen);
close FILE;
exit 0;

sub Usage {
  print "perl bl_append.pl <filename> <verno file> <scatter file> <BOARD_VER>\n";
  exit 1;
}
