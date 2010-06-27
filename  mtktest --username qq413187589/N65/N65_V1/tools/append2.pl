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
#*
#* Filename:
#* ---------
#*   Append.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script can append some information to a file
#*   1. its file name
#*   2. input strings
#*   3. flash configuration information
#*   This script also can query flash configuration stored in FlashConf.c
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Usage
#****************************************************************************
sub Usage {
  print "perl append2.pl -h -d
               <symfile> <flash_cfg_file> <filename> <bin_name> <verno> <MAKEILE>
               <symfile> <flash_cfg_string> <filename> <bin_name> <verno> <MAKEILE>
               <flash_cfg_file>\n";
  exit(1);
}

#****************************************************************************
# parsing command arguments
#****************************************************************************

$DebugPrint = 0;
$rom_info_ver = "MTK_ROMINFO_v04";
(length($rom_info_ver) != 15) && die "ROM_INFO_VER: $rom_info_ver should be 15 bytes!\n";
$file = "";
$bin_name = "";
$symFile = "";
$verno = "";
$FLASH_CFG = "";
$themf = "";
$query_mode = 0;
my $sec_support = 0;
my $needEMIInfo = 0;

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /-h/i) {
    &Usage;
  } elsif ($ARGV[0] =~ /-d/i) {
    $DebugPrint = 1;
  } elsif ($#ARGV == 2) {
    $FLASH_CFG = $ARGV[0];
    (!-e $FLASH_CFG) && die "$FLASH_CFG does NOT EXIST!\n";
    $memory_cfg = $ARGV[1];
    (!-e $memory_cfg) && die "$memory_cfg does NOT EXIST!\n";
    $themf = $ARGV[2];
    (!-e $themf) && die "$themf does NOT EXIST!\n";
    $query_mode = 1;
    last;
  } elsif ($#ARGV == 5) {
    $symFile = $ARGV[0];
    (!-e $symFile) && die "$symFile does NOT EXIST!\n";
    $FLASH_CFG = $ARGV[1];
    $file = $ARGV[2];
    (!-e $file) && die "$file does NOT EXIST!\n";
    $bin_name = $ARGV[3];
    (length($bin_name) > 127) && die "BIN_NAME: $ARGV[3] should NOT exceed 127 bytes!\n";
    $verno = $ARGV[4];
    (length($verno) > 63) && die "VERNO: $ARGV[4] should NOT exceed 63 bytes!\n";
    $themf = $ARGV[5];
    (!-e $themf) && die "$themf does NOT EXIST!\n";
    last;
  } elsif ($#ARGV == 6) {
    $symFile = $ARGV[0];
    (!-e $symFile) && die "$symFile does NOT EXIST!\n";
    $FLASH_CFG = $ARGV[1];
    $file = $ARGV[2];
    (!-e $file) && die "$file does NOT EXIST!\n";
    $bin_name = $ARGV[3];
    (length($bin_name) > 127) && die "BIN_NAME: $ARGV[3] should NOT exceed 127 bytes!\n";
    $verno = $ARGV[4];
    (length($verno) > 63) && die "VERNO: $ARGV[4] should NOT exceed 63 bytes!\n";
    $themf = $ARGV[5];
    (!-e $themf) && die "$themf does NOT EXIST!\n";
    $memory_cfg = $ARGV[6];
    $EMI_INFO = $ARGV[6];
    if ($memory_cfg !~ /\d.+/) {
      (!-e $memory_cfg) && die "$memory_cfg does NOT EXIST!\n";
    }
    last;
  } else {
    &Usage;
  }
  shift(@ARGV);
}

#if ($query_mode == 0) {
  open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
  while (<FILE_HANDLE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = lc($1);
      defined($${keyname}) && warn "$1 redefined in $themf!\n";
      $${keyname} = uc($2);
    }
  }

  if ($secure_support eq "TRUE") {
    $sec_support = 1;
    ($secure_version !~ /\d{1,4}/) && die "SECURE_VERSION: $secure_version should be a integer no longer than 4 digits!\n";
    ($secure_jtag_enable !~ /(TRUE|FALSE)/) && die "SECURE_JTAG_ENABLE: $secure_jtag_enable should be TRUE or FALSE!\n";
    $secure_jtag_enable = ($secure_jtag_enable =~ /TRUE/)? 1 : 0;
    (length($secure_custom_name) > 31) && die "SECURE_CUSTOM_NAME: $secure_custom_name should NOT exceed 31 bytes!\n";
  }
    
  if (($nand_flash_booting eq "TRUE") && (($platform eq "MT6225") || ($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6230"))) {
  	$needEMIInfo = 1;
  } else {
  	$needEMIInfo = 0;
  }
#}
#****************************************************************************
# parsing flash configuration from a file or a string
#****************************************************************************
my $full_hex_str = '';
my $full_emi_str = '';

if ($FLASH_CFG =~ /\.h/i) {
  # parsing flash configuration from custom_EMI.h or custom_MemoryDevice.h (NAND_FLASG_BOOTING)
  open (FLASH_CFG, "<$FLASH_CFG") or die "cannot open $FLASH_CFG\n";

  $backup = $/; undef $/;
  $reading = <FLASH_CFG>;
  $/ = $backup;
  $cfg_type = 0; # 1 for Chicago type ... multiple configurations
                 # 0 for Beetle type .... single configuration

  if ($reading =~ /\*\s*Define\s+FLASH_SET_NUMBER\s+\d+\s+--- BEGIN -{5,}\s+\*\s*Define\s+FLASH_BASE_ADDRESS\s+/gs) {
    $cfg_type = 1;
  } elsif ($reading =~ /#\s*define\s+FLASH_BASE_ADDRESS\s+0x/gs) {
    $cfg_type = 0;
  } else {
    close FLASH_CFG;
    die "$FLASH_CFG: WRONG format\n";;
  }

  seek(FLASH_CFG,0,0);

  if ($cfg_type == 1) {
    {} while (($line = <FLASH_CFG>) !~ /\*\s*Define\s+FLASH_SET_NUMBER\s+(\d+)\s+/);
    $cfg_number = $1;
    ($cfg_number > 6) && close(FLASH_CFG) && die "$FLASH_CFG: FLASH_SET_NUMBER should NOT exceed 6.\n";
    foreach my $idx (0..$cfg_number-1) {
      {} while (($line = <FLASH_CFG>) !~ /\*\s*Define\s+FLASH_BASE_ADDRESS\s+(0x[0-9A-Fa-f]+)/);
      $addr = hex $1;
      $len = hex $1 if (($line = <FLASH_CFG>) =~ /\*\s*Define\s+ALLOCATED_FAT_SPACE\s+(0x[0-9A-Fa-f]+)/);
      $id1 = hex $1 if (($line = <FLASH_CFG>) =~ /\*\s*Define\s+FLASH_ID_ENTRY_1\s+(0x[0-9A-Fa-f]+)/);
      $id2 = hex $1 if (($line = <FLASH_CFG>) =~ /\*\s*Define\s+FLASH_ID_ENTRY_2\s+(0x[0-9A-Fa-f]+)/);
      $id3 = hex $1 if (($line = <FLASH_CFG>) =~ /\*\s*Define\s+FLASH_ID_ENTRY_3\s+(0x[0-9A-Fa-f]+)/);
      $id4 = hex $1 if (($line = <FLASH_CFG>) =~ /\*\s*Define\s+FLASH_ID_ENTRY_4\s+(0x[0-9A-Fa-f]+)/);

	if (($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "FALSE")) {
		$addr = 0x0;
		$len = 0x0;
	}
	
      if ($idx == 0) {
        $hex_str = sprintf("%02X%04X%04X%04X%04X%08X%08X", $cfg_number, $id1, $id2, $id3, $id4, $addr, $len);
        $full_hex_str .= $hex_str;
      } else {
        $hex_str = sprintf("%04X%04X%04X%04X%08X%08X", $id1, $id2, $id3, $id4, $addr, $len);
        $full_hex_str .= $hex_str;
      }

      print "[Flash Cfg $idx] $hex_str\n" if $DebugPrint == 1;
    }
    
  #Check if MEMORY_DEVICE_TYPE is NOR_LPSDRAM_MCP.
  if (($needEMIInfo == 0) && (($platform eq "MT6225") || ($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6230"))) {
  	if ($FLASH_CFG =~ /custom_EMI\.h/i) {
    	open (memory_cfg, "<$memory_cfg") or die "cannot open $memory_cfg:$!\n";
    	{} while (($line = <memory_cfg>) !~ /\s*Define\s+MEMORY_DEVICE_TYPE\s+(.+)\s+/i);
    	$MEMORY_DEVICE_TYPE = $1;
    	print "MEMORY_DEVICE_TYPE=$MEMORY_DEVICE_TYPE\n" if $DebugPrint == 1;
    	close(memory_cfg);
    	if($MEMORY_DEVICE_TYPE eq "NOR_LPSDRAM_MCP") {
    		$needEMIInfo = 1;
    	}
  	} elsif ($FLASH_CFG =~ /custom_MemoryDevice\.h/i) {
  		#When FLASH_CFG is custom_MemoryDevice.h, that means NFB is true and EMI_Info is needed.
  		$needEMIInfo = 1;
  	}
	}
  ######################################
  #Get register values from custom_MEI.h
  ######################################
  if (($needEMIInfo == 1) && ($FLASH_CFG =~ /custom_EMI\.h/i)) {
  	seek(FLASH_CFG,0,0);
		{} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_DRAM_RERESH_CONTROL\s+(0x[0-9A-Fa-f]+)/);
#   $EMI_DRAM_RERESH_CONTROL = hex $1;
		$EMI_DRAM_RERESH_CONTROL = substr($1,2);
		$full_emi_str .= $EMI_DRAM_RERESH_CONTROL;
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_DRAM_MODE\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_MODE = hex $1;
    $EMI_DRAM_MODE = substr($1,2);
    $full_emi_str .= $EMI_DRAM_MODE;
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_DRAM_EXT_MODE\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_EXT_MODE = hex $1;
    $EMI_DRAM_EXT_MODE = substr($1,2);
    $full_emi_str .= $EMI_DRAM_EXT_MODE;
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_DRAM_CONTROL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_CONTROL = hex $1;
    $EMI_DRAM_CONTROL = substr($1,2);
    $full_emi_str .= $EMI_DRAM_CONTROL;  
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL1_VAL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_GENERAL_CONTROL1_VAL = hex $1;
    $EMI_GENERAL_CONTROL1_VAL = substr($1,2);
    $full_emi_str .= $EMI_GENERAL_CONTROL1_VAL;
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL2_VAL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_GENERAL_CONTROL2_VAL = hex $1;
    $EMI_GENERAL_CONTROL2_VAL = substr($1,2);
    $full_emi_str .= $EMI_GENERAL_CONTROL2_VAL;
    if (($platform eq "MT6229") || ($platform eq "MT6230")) {
    	{} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL3_VAL\s+(0x[0-9A-Fa-f]+)/);
#    	$EMI_GENERAL_CONTROL3_VAL = hex $1;
    	$EMI_GENERAL_CONTROL3_VAL = substr($1,2);
    	$full_emi_str .= $EMI_GENERAL_CONTROL3_VAL;
  	}
      print "EMI_DRAM_RERESH_CONTROL=$EMI_DRAM_RERESH_CONTROL\n" if $DebugPrint == 1;
      print "EMI_DRAM_MODE=$EMI_DRAM_MODE\n" if $DebugPrint == 1;
      print "EMI_DRAM_EXT_MODE=$EMI_DRAM_EXT_MODE\n" if $DebugPrint == 1;
      print "EMI_DRAM_CONTROL=$EMI_DRAM_CONTROL\n" if $DebugPrint == 1;
      print "EMI_GENERAL_CONTROL1_VAL=$EMI_GENERAL_CONTROL1_VAL\n" if $DebugPrint == 1;
      print "EMI_GENERAL_CONTROL2_VAL=$EMI_GENERAL_CONTROL2_VAL\n" if $DebugPrint == 1;
      print "EMI_GENERAL_CONTROL3_VAL=$EMI_GENERAL_CONTROL3_VAL\n" if $DebugPrint == 1;
  } elsif (($needEMIInfo == 1) && ($FLASH_CFG =~ /custom_MemoryDevice\.h/i)) {
  	open (memory_cfg, "<$memory_cfg") or die "cannot open $memory_cfg\n";
		{} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_DRAM_RERESH_CONTROL\s+(0x[0-9A-Fa-f]+)/);
#		$EMI_DRAM_RERESH_CONTROL = hex $1;
		$EMI_DRAM_RERESH_CONTROL = substr($1,2);
		$full_emi_str .= $EMI_DRAM_RERESH_CONTROL;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_DRAM_MODE\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_MODE = hex $1;
    $EMI_DRAM_MODE = substr($1,2);
    $full_emi_str .= $EMI_DRAM_MODE;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_DRAM_EXT_MODE\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_EXT_MODE = hex $1;
    $EMI_DRAM_EXT_MODE = substr($1,2);
    $full_emi_str .= $EMI_DRAM_EXT_MODE;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_DRAM_CONTROL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_CONTROL = hex $1;
    $EMI_DRAM_CONTROL = substr($1,2);
    $full_emi_str .= $EMI_DRAM_CONTROL; 
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL1_VAL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_GENERAL_CONTROL1_VAL = hex $1;
    $EMI_GENERAL_CONTROL1_VAL = substr($1,2);
    $full_emi_str .= $EMI_GENERAL_CONTROL1_VAL;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL2_VAL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_GENERAL_CONTROL2_VAL = hex $1;
    $EMI_GENERAL_CONTROL2_VAL = substr($1,2);
    $full_emi_str .= $EMI_GENERAL_CONTROL2_VAL;
    if (($platform eq "MT6229") || ($platform eq "MT6230")) {
    	{} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL3_VAL\s+(0x[0-9A-Fa-f]+)/);
#    	$EMI_GENERAL_CONTROL3_VAL = hex $1;
    	$EMI_GENERAL_CONTROL3_VAL = substr($1,2);
    	$full_emi_str .= $EMI_GENERAL_CONTROL3_VAL;
    }
    close(memory_cfg);
    print "EMI_DRAM_RERESH_CONTROL=$EMI_DRAM_RERESH_CONTROL\n" if $DebugPrint == 1;
    print "EMI_DRAM_MODE=$EMI_DRAM_MODE\n" if $DebugPrint == 1;
    print "EMI_DRAM_EXT_MODE=$EMI_DRAM_EXT_MODE\n" if $DebugPrint == 1;
    print "EMI_DRAM_CONTROL=$EMI_DRAM_CONTROL\n" if $DebugPrint == 1;
    print "EMI_GENERAL_CONTROL1_VAL=$EMI_GENERAL_CONTROL1_VAL\n" if $DebugPrint == 1;
    print "EMI_GENERAL_CONTROL2_VAL=$EMI_GENERAL_CONTROL2_VAL\n" if $DebugPrint == 1;
    print "EMI_GENERAL_CONTROL3_VAL=$EMI_GENERAL_CONTROL3_VAL\n" if $DebugPrint == 1;
  }
    
  } else {
  	#custom_MemoryDevice.h (NAND_FLASG_BOOTING)
    $cfg_number = 1;
    
		if (($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "FALSE"))  {
			$addr = 0x0;
			$len = 0x0;
    } else {
			{} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+FLASH_BASE_ADDRESS\s+(0x[0-9A-Fa-f]+)/);
			$addr  = hex $1;
			{} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+ALLOCATED_FAT_SPACE\s+(0x[0-9A-Fa-f]+)/);
			$len  = hex $1;
    }
    
    $hex_str = sprintf("%02X%04X%04X%04X%04X%08X%08X", $cfg_number, 0, 0, 0, 0, $addr, $len);
    $full_hex_str .= $hex_str;

    print "[Flash Cfg 0] $hex_str\n" if $DebugPrint == 1;
  }

  #Check if MEMORY_DEVICE_TYPE is NOR_LPSDRAM_MCP.
  if (($needEMIInfo == 0) && (($platform eq "MT6225") || ($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6230"))) {
  	if ($FLASH_CFG =~ /custom_EMI\.h/i) {
    	open (memory_cfg, "<$memory_cfg") or die "cannot open $memory_cfg:$!\n";
    	{} while (($line = <memory_cfg>) !~ /\s*Define\s+MEMORY_DEVICE_TYPE\s+(.+)\s+/i);
    	$MEMORY_DEVICE_TYPE = $1;
    	print "MEMORY_DEVICE_TYPE=$MEMORY_DEVICE_TYPE\n" if $DebugPrint == 1;
    	close(memory_cfg);
    	if($MEMORY_DEVICE_TYPE eq "NOR_LPSDRAM_MCP") {
    		$needEMIInfo = 1;
    	}
  	} elsif ($FLASH_CFG =~ /custom_MemoryDevice\.h/i) {
  		#When FLASH_CFG is custom_MemoryDevice.h, that means NFB is true and EMI_Info is needed.
  		$needEMIInfo = 1;
  	}
	}
  ######################################
  #Get register values from custom_MEI.h
  ######################################
  if (($needEMIInfo == 1) && ($FLASH_CFG =~ /custom_EMI\.h/i)) {
  	seek(FLASH_CFG,0,0);
		{} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_DRAM_RERESH_CONTROL\s+(0x[0-9A-Fa-f]+)/);
#   $EMI_DRAM_RERESH_CONTROL = hex $1;
		$EMI_DRAM_RERESH_CONTROL = substr($1,2);
		$full_emi_str .= $EMI_DRAM_RERESH_CONTROL;
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_DRAM_MODE\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_MODE = hex $1;
    $EMI_DRAM_MODE = substr($1,2);
    $full_emi_str .= $EMI_DRAM_MODE;
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_DRAM_EXT_MODE\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_EXT_MODE = hex $1;
		$EMI_DRAM_EXT_MODE = substr($1,2);
    $full_emi_str .= $EMI_DRAM_EXT_MODE;
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_DRAM_CONTROL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_CONTROL = hex $1;
    $EMI_DRAM_CONTROL = substr($1,2);
    $full_emi_str .= $EMI_DRAM_CONTROL; 
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL1_VAL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_GENERAL_CONTROL1_VAL = hex $1;
    $EMI_GENERAL_CONTROL1_VAL = substr($1,2);
    $full_emi_str .= $EMI_GENERAL_CONTROL1_VAL;
    {} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL2_VAL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_GENERAL_CONTROL2_VAL = hex $1;
    $EMI_GENERAL_CONTROL2_VAL = substr($1,2);
    $full_emi_str .= $EMI_GENERAL_CONTROL2_VAL;
    if (($platform eq "MT6229") || ($platform eq "MT6230")) {
    	{} while (($line = <FLASH_CFG>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL3_VAL\s+(0x[0-9A-Fa-f]+)/);
#    	$EMI_GENERAL_CONTROL3_VAL = hex $1;
    	$EMI_GENERAL_CONTROL3_VAL = substr($1,2);
    	$full_emi_str .= $EMI_GENERAL_CONTROL3_VAL;
  	}
      print "EMI_DRAM_RERESH_CONTROL=$EMI_DRAM_RERESH_CONTROL\n" if $DebugPrint == 1;
      print "EMI_DRAM_MODE=$EMI_DRAM_MODE\n" if $DebugPrint == 1;
      print "EMI_DRAM_EXT_MODE=$EMI_DRAM_EXT_MODE\n" if $DebugPrint == 1;
      print "EMI_DRAM_CONTROL=$EMI_DRAM_CONTROL\n" if $DebugPrint == 1;
      print "EMI_GENERAL_CONTROL1_VAL=$EMI_GENERAL_CONTROL1_VAL\n" if $DebugPrint == 1;
      print "EMI_GENERAL_CONTROL2_VAL=$EMI_GENERAL_CONTROL2_VAL\n" if $DebugPrint == 1;
      print "EMI_GENERAL_CONTROL3_VAL=$EMI_GENERAL_CONTROL3_VAL\n" if $DebugPrint == 1;
  } elsif (($needEMIInfo == 1) && ($FLASH_CFG =~ /custom_MemoryDevice\.h/i)) {
  	open (memory_cfg, "<$memory_cfg") or die "cannot open $memory_cfg:$!\n";
		{} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_DRAM_RERESH_CONTROL\s+(0x[0-9A-Fa-f]+)/);
#		$EMI_DRAM_RERESH_CONTROL = hex $1;
		$EMI_DRAM_RERESH_CONTROL = substr($1,2);
		$full_emi_str .= $EMI_DRAM_RERESH_CONTROL;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_DRAM_MODE\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_MODE = hex $1;
    $EMI_DRAM_MODE = substr($1,2);
    $full_emi_str .= $EMI_DRAM_MODE;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_DRAM_EXT_MODE\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_EXT_MODE = hex $1;
    $EMI_DRAM_EXT_MODE = substr($1,2);
    $full_emi_str .= $EMI_DRAM_EXT_MODE;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_DRAM_CONTROL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_DRAM_CONTROL = hex $1;
    $EMI_DRAM_CONTROL = substr($1,2);
    $full_emi_str .= $EMI_DRAM_CONTROL;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL1_VAL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_GENERAL_CONTROL1_VAL = hex $1;
    $EMI_GENERAL_CONTROL1_VAL = substr($1,2);
    $full_emi_str .= $EMI_GENERAL_CONTROL1_VAL;
    {} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL2_VAL\s+(0x[0-9A-Fa-f]+)/);
#    $EMI_GENERAL_CONTROL2_VAL = hex $1;
    $EMI_GENERAL_CONTROL2_VAL = substr($1,2);
    $full_emi_str .= $EMI_GENERAL_CONTROL2_VAL;
    if (($platform eq "MT6229") || ($platform eq "MT6230")) {
    	{} while (($line = <memory_cfg>) !~ /^\s*#\s*define\s+EMI_GENERAL_CONTROL3_VAL\s+(0x[0-9A-Fa-f]+)/);
#    	$EMI_GENERAL_CONTROL3_VAL = hex $1;
    	$EMI_GENERAL_CONTROL3_VAL = substr($1,2);
    	$full_emi_str .= $EMI_GENERAL_CONTROL3_VAL;
    }
    close(memory_cfg);
    print "EMI_DRAM_RERESH_CONTROL=$EMI_DRAM_RERESH_CONTROL\n" if $DebugPrint == 1;
    print "EMI_DRAM_MODE=$EMI_DRAM_MODE\n" if $DebugPrint == 1;
    print "EMI_DRAM_EXT_MODE=$EMI_DRAM_EXT_MODE\n" if $DebugPrint == 1;
    print "EMI_DRAM_CONTROL=$EMI_DRAM_CONTROL\n" if $DebugPrint == 1;
    print "EMI_GENERAL_CONTROL1_VAL=$EMI_GENERAL_CONTROL1_VAL\n" if $DebugPrint == 1;
    print "EMI_GENERAL_CONTROL2_VAL=$EMI_GENERAL_CONTROL2_VAL\n" if $DebugPrint == 1;
    print "EMI_GENERAL_CONTROL3_VAL=$EMI_GENERAL_CONTROL3_VAL\n" if $DebugPrint == 1;
  }
    
  close FLASH_CFG;
} else {
  # parsing flash configuration from a string
  $full_hex_str = $FLASH_CFG;
  $full_emi_str = $EMI_INFO;
  if ((length($full_emi_str) == 0) && (($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6225") || ($platform eq "MT6230"))) {
  	die "Cannot get EMI_INFO.";
  }
  print "full_hex_str=$full_hex_str\n" if $DebugPrint == 1;

  print "[Flash Cfg 0] $FLASH_CFG\n" if $DebugPrint == 1;
}

$flash_len = length($full_hex_str);
if (($flash_len == 2) || ((($flash_len-34)%32) !=0) ||
    ($flash_len > 34+5*32)) {
  die "The length of $full_hex_str ($flash_len) should be 34+32n. (5>=n>=0)\n";
}
$flash_device_count = hex(substr($full_hex_str, 0, 2));
if ((($flash_len-2)/32) != $flash_device_count) {
  die "($flash_len-2)/32 should be $flash_device_count\n";
}

#****************************************************************************
# in query, output @cfg_list with hex string
#****************************************************************************
if ($query_mode == 1) {
  print "FLASH_CFG = $full_hex_str\n";
  print "EMI_INFO = $full_emi_str\n";
  exit(0);
}

(open(LOGF, "<$symFile")) || die "$symFile can NOT been opened\n";

$addr1 =  0;
$addr_secinfo =  0;
$matchChk = 0;
$initAddr = 0;
while(<LOGF>) {
  if (/^0x(\S+)\s+\S+\s+IMG_INFO$/) {
    $addr1 = hex($1) % 0x08000000 - $initAddr;
    $matchChk += 1;
  }
  elsif (/^0x(\S+)\s+\S+\s+g_CustParaCfg$/) {
    $addr_CustParaCfg = hex($1);
    $_ = <LOGF>;
    if (/^0x(\S+)\s+\S+\s+\S+/) {
      $addr2 = hex($1);
    }
    $len_CustParaCfg = $addr2 - $addr_CustParaCfg;
  }
  elsif (/^0x(\S+)\s+\S+\s+g_secinfo$/) {
    $addr_secinfo = hex($1) % 0x08000000;
    $matchChk += 2;
  }
  elsif (/^0x(\S+)\s+\S+\s+INT_Vectors$/) {
    $initAddr = hex($1) % 0x08000000;
  }  
  elsif (/^0x(\S+)\s+\S+\s+EMI_INFO$/) {
    $addr_emi_info = hex($1) % 0x08000000 - $initAddr;
    $matchChk += 3;
  }
  #last if ($matchChk == 3);
}
close(LOGF);
(($matchChk == 0) && ($sec_support == 1)) && die "Could not find IMG_INFO and g_secinfo in $symFile\n";
(($matchChk == 0) && ($sec_support == 0)) && die "Could not find IMG_INFO in $symFile\n";
(($matchChk == 1) && ($sec_support == 1)) && die "Could not find g_secinfo in $symFile\n";
($matchChk == 2) && die "Could not find IMG_INFO in $symFile\n";
(($matchChk == 3) && ($sec_support == 0)) && die "Could not find IMG_INFO in $symFile\n";
(($matchChk == 3) && ($sec_support == 1)) && die "Could not find IMG_INFO and g_secinfo in $symFile\n";
(($matchChk == 4) && ($sec_support == 1)) && die "Could not find g_secinfo in $symFile\n";
#****************************************************************************
# set ROMINFO version
#****************************************************************************
if ((($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "FALSE")) || ($fota_enable eq "FOTA_FULL"))
{
	$rom_info_ver = "MTK_ROMINFO_v05";
}

#****************************************************************************
# append information to the file
#****************************************************************************
open (FILE, "+<$file") or die "cannot open $file\n";
binmode(FILE);
seek(FILE, $addr1, 0);
if (($sec_support == 1) || ($cust_para_support eq "TRUE")) {
  seek(FILE, 16, 1);
} else {
  print FILE "$rom_info_ver\0";
}
print FILE "$bin_name";
print FILE "\0" x (128 -length($bin_name));
print FILE "$verno";
print FILE "\0" x (64 -length($verno));
if ($FLASH_CFG =~ /custom_MemoryDevice\.h/i) {
  print FILE pack("H4", "ffff");
} else {
  print FILE pack("H4", "0000");
}
$flash_len = length($full_hex_str);
print FILE pack("v1", $flash_device_count);
for ($i=0; $i<$flash_device_count; $i++) {
  $menuID = hex(substr($full_hex_str, 2+32*$i, 4));
  $devID = hex(substr($full_hex_str, 6+32*$i, 4));
  $extID1 = hex(substr($full_hex_str, 10+32*$i, 4));
  $extID2 = hex(substr($full_hex_str, 14+32*$i, 4));
  $fatAddr = hex(substr($full_hex_str, 18+32*$i, 8));
  $fatLen = hex(substr($full_hex_str, 26+32*$i, 8));
  print FILE pack("v1", $menuID);
  print FILE pack("v1", $devID);
  print FILE pack("v1", $extID1);
  print FILE pack("v1", $extID2);
  print FILE pack("V1", $fatAddr);
  print FILE pack("V1", $fatLen);
}

if ($cust_para_support eq "TRUE") {
  seek(FILE, 12+(6-$flash_device_count)*16, 1);
  print FILE pack("V1", $addr_CustParaCfg);
  print FILE pack("V1", $len_CustParaCfg);
}

if ($sec_support == 1) {
  seek(FILE, $addr_secinfo+20, 0);
  print FILE pack("V1", $secure_jtag_enable);
  print FILE "$secure_custom_name";
  print FILE "\0" x (32 -length($secure_custom_name));
  seek(FILE, $addr_secinfo+60, 0);
  print FILE pack("V1", $secure_version);

  # find address of g_secinfo_tail
  my $addr_secinfo_tail;
  seek(FILE, $addr_secinfo+80, 0);
  die "cannot read $file\n" unless (my $chnum = (read FILE, $addr_secinfo_tail, 4));
  $addr_secinfo_tail = unpack ("V1",$addr_secinfo_tail) % 0x08000000;

  seek(FILE, $addr_secinfo_tail+20, 0);
  print FILE pack("V1", $secure_jtag_enable);
  print FILE "$secure_custom_name";
  print FILE "\0" x (32 -length($secure_custom_name));
  seek(FILE, $addr_secinfo_tail+60, 0);
  print FILE pack("V1", $secure_version);
}

if ($rom_info_ver eq "MTK_ROMINFO_v05") {
  $cust_para_addr = hex(0);
  $cust_para_len = hex(0);
  $bit_ctrl = hex(0);

  if (($system_drive_on_nand eq "TRUE") && ($nand_flash_booting eq "FALSE")) {
  	$bit_ctrl = $bit_ctrl | 0x00000002;
  }
  elsif ($fota_enable eq "FOTA_FULL") {
  	$bit_ctrl = $bit_ctrl | 0x00000004;
  }

   seek(FILE, $addr1+320, 0);
   print FILE pack("V1", $cust_para_addr);
    
   seek(FILE, $addr1+324, 0);
   print FILE pack("V1", $cust_para_len);

   seek(FILE, $addr1+328, 0);
   print FILE pack("V1", $bit_ctrl);
}

#seek(FILE, 0, 2);
#print FILE "MTK_BIN\0";
#print FILE pack("H8", "00000000");
#****************************************************************************
# append EMI_Info information to the file
#****************************************************************************
if (($needEMIInfo == 1) && (($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6225") || ($platform eq "MT6230"))) {
	seek(FILE, $addr_emi_info, 0);
	print FILE "MTK_EMI_INFO";
	print FILE "\0" x (16 -length(MTK_EMI_INFO));
	print seek(FILE,4,1);
	print FILE pack("V1",hex "0x".substr($full_emi_str,0,8));
	print FILE pack("V1",hex "0x".substr($full_emi_str,8,8));
	print FILE pack("V1",hex "0x".substr($full_emi_str,16,8));
	print FILE pack("V1",hex "0x".substr($full_emi_str,24,8));
	print FILE pack("V1",hex "0x".substr($full_emi_str,32,8));
	print FILE pack("V1",hex "0x".substr($full_emi_str,40,8));
	if (($platform eq "MT6229") || ($platform eq "MT6230")) {
		print FILE pack("V1",hex "0x".substr($full_emi_str,48,8));
	}
}


close FILE;
exit 0;

