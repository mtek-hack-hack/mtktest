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
#******************************************************************************
# Subroutine: Usage
#******************************************************************************
sub usage {
  print "perl custominfo.pl <Makefile> <op_custom_lis_file> <OPTR_PATH>\n";
  exit 1;
}

#******************************************************************************
# Variables Declaration
#******************************************************************************
# Custom information build script files
system("mkdir make\\custom") if (!-d "make\\custom");
my $lisfile="make\\custom\\custom.lis";
my $pthfile="make\\custom\\custom.pth";
my $incfile="make\\custom\\custom.inc";
my $deffile="make\\custom\\custom.def";

#******************************************************************************
# Check input arguments
#******************************************************************************
&Usage if ($#ARGV == -1);
$thefile = $ARGV[0];
$op_custom_lis_file = $ARGV[1] if (defined($ARGV[1]));
$optr_path = $ARGV[2] if (defined($ARGV[2]));

die "$thefile does NOT exist\n" if (!-e $thefile);
if ($thefile =~ /make\\(\w+)_(\w+).mak/i) {
  $custom = uc($1);
  $project = lc($2);
}

($custom eq "") && &Usage;
($project eq "") && &Usage;
$base_dir = ".";
#
# Get PLATFORM, BOARD_VER, NOR_FLASH_TYPE, and SUB_BOARD_VER from MAKEFILE.
#
open (FILE_HANDLE, "<$thefile") or die "cannot open $thefile\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $thefile!\n";
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;

if (defined($ARGV[2])) {
	open (FILE_HANDLE, "<$optr_path\\operator_check.log") or die "cannot open $optr_path\\operator_check.log\n";
	while (<FILE_HANDLE>) {
  	if (/^(set)\s*(\S+)\s*=\s*(\S+)/i) {
    	$keyname = lc($2);
    	defined($${keyname}) && warn "$2 redefined in $optr_path\\operator_check.log!\n";
    	$${keyname} = uc($3);
  	}
	}
close FILE_HANDLE;
}
#******************************************************************************
# Process lis file
#******************************************************************************
my $reading = "";
my $allpth = "";
my $allinc = "";

# System, Common, L1 RF, Drv, BOARD_VER, App, PS
@thatdirs = ("system\\$board_ver", "common", "l1_rf\\$rf_module", "ul1_rf\\$umts_rf_module",
     "drv\\LCD\\$lcd_module", "drv\\misc_drv\\$board_ver",
     "app\\$board_ver", "ps\\$board_ver");

if ($drv_custom_tool_support eq "TRUE") {   push(@thatdirs, "drv\\misc_drv\\$board_ver\\codegen", "drv\\common_drv"); }

($mmi_base = "PLUTO_MMI") if (!defined $mmi_base);
# Common\xx_MMI
if ($project ne "basic") {
  push(@thatdirs, "common\\$mmi_base");
}

# Audio, META, input method
if ($project ne "basic") {
  push(@thatdirs, "audio\\$board_ver");
  push(@thatdirs, "meta\\$board_ver");
}

# EXT_CAM_MOD
if (($project ne "basic") && ($project ne "l1s") && defined($ext_cam_module)) {
  if ($ext_cam_module ne "NONE") {
    push(@thatdirs, "drv\\cam_module\\$board_ver");
    push(@thatdirs, "drv\\cam_module\\$ext_cam_module");
  }
}

# AnalogTV , hongzhe.liu add
if (($project ne "basic") && ($project ne "l1s") && defined($analog_tv_chip)) {
  if ($analog_tv_chip ne "NONE") {
    push(@thatdirs, "drv\\analog_tv\\$analog_tv_chip");
  }
}

#Bluetooth chip , hongzhe.liu add
if (($project ne "basic") && ($project ne "l1s") && defined($noke_bluetooth_chip)) {
  if ($noke_bluetooth_chip ne "MT6601") {
    push(@thatdirs, "drv\\bt_$noke_bluetooth_chip");
  }
}

#Gsensor, hongzhe.liu add
if (($project ne "basic") && ($project ne "l1s") && defined($noke_g_sensor)) {
  if ($noke_g_sensor ne "FALSE") {
    push(@thatdirs, "drv\\g_sensor");
  }
}

#motion sensor, hongzhe.liu add
if (($project ne "basic") && ($project ne "l1s") && defined($noke_m_sensor)) {
  if ($noke_m_sensor ne "FALSE") {
    push(@thatdirs, "drv\\motion_sensor");
  }
}

if (($project ne "basic") && ($project ne "l1s") && defined($noke_horserace)) {
  if ($noke_horserace ne "FALSE") {
    push(@thatdirs, "drv\\horse_race");
  }
}

#hongzhe.liu add end

# CMOS_SENSOR
if (($project ne "basic") && ($project ne "l1s") && defined($cmos_sensor)) {
  if ($cmos_sensor ne "NONE") {
    push(@thatdirs, "drv\\camera\\$board_ver");
    if (($yuv_sensor_support eq "TRUE") && ($isp_support eq "TRUE")) {
    push(@thatdirs, "drv\\yuv_sensor");  
#    push(@thatdirs, "drv\\yuv_sensor\\$cmos_sensor");      
    } else {
      push(@thatdirs, "drv\\image_sensor");
#      push(@thatdirs, "drv\\image_sensor\\$cmos_sensor");
    }
  }
}

# LENS_MODULE
if (($project ne "basic") && ($project ne "l1s") && defined($lens_module)) {
  if ($lens_module ne "NONE") {
    die "LENS_MODUEL=$lens_module but CMOS_SENSOR=NONE\n" if ($cmos_sensor eq "NONE");
    push(@thatdirs, "drv\\lens_module\\$lens_module");
  }
}

# MOTION_SENSOR_SUPPORT
if (($project ne "basic") && ($project ne "l1s") && defined($motion_sensor_support)) {
  if ($motion_sensor_support ne "NONE") {
    push(@thatdirs, "drv\\motion_sensor\\$motion_sensor_support");
  }
}

# WIFI_SUPPORT
if (($project ne "basic") && ($project ne "l1s") && defined($wifi_support)) {
  if ($wifi_support ne "NONE") {
    push(@thatdirs, "drv\\wifi\\$board_ver");
  }
}

# J2ME
if (($project ne "basic") && ($project ne "l1s") && defined($j2me_support)) {
  if ($j2me_support ne "NONE") {
    if ($j2me_support eq "JBLENDIA") {
      push(@thatdirs, "j2me\\JBLENDIA");
    } elsif ($j2me_support eq "JBED") {
    	push(@thatdirs, "j2me\\JBED");
    } else {
      push(@thatdirs, "j2me\\IJET");
    }
  }
}


# BLUETOOTH_SUPPORT
if (($project ne "basic") && ($project ne "l1s") && defined($bluetooth_support)) {
  if ($bluetooth_support ne "NONE") {
    push(@thatdirs, "drv\\bluetooth\\$board_ver");
  }
}

if(defined($optr_spec) && ($optr_spec ne "NONE"))
{
  # GET operator resource files and store them in hash
  our %op_file = ();
  Replace_operator_resource();
}

foreach $t (@thatdirs) {
  $thatdir = "custom\\$t";
  $allpath .= "$thatdir\n";

  if (($t ne "j2me\\IJET")&&($t ne "j2me\\JBLENDIA")&&($t ne "j2me\\JBED")) {
    opendir THATDIR, $thatdir;
    @tmpFiles = readdir THATDIR;
    closedir THATDIR;
    @allfiles = ();
    foreach $f (@tmpFiles) {
      next if (($f eq ".") || ($f eq "..") || (-d "$thatdir\\$f"));
      push(@allfiles, "$thatdir/$f");
    }
  } else { 
    @allfiles = ();
    $defaultBB =  "$thatdir\\_DEFAULT_BB";
    $boardBB = "${thatdir}\\${board_ver}";

   if ($j2me_support eq "JBLENDIA") {
    
    $gameGenDir = "$defaultBB\\jblend_preinstall";
    $gameExe = "DirRomizer.exe";
    $gamePapay = "PapayaPik.exe";
    $gameConfig = "PapayaPik.cfg";
    $gameGenFile = "${gameGenDir}\\$gameExe";
    if ((-d $defaultBB) && (-d $gameGenDir) && (-e $gameGenFile)) {
      chdir($gameGenDir);
      $gamecfg = "..\\..\\$board_ver\\$gameConfig";
      $gamecfgdir = "..\\..\\$board_ver";
      if (!-e $gamecfg) {
      	system("md $gamecfgdir") if (!-e $gamecfgdir);
        system("copy /y $gameConfig $gamecfg > nul");
        open (GAME_CFG_H, ">>$gamecfg") or die "cannot open $gamecfg\n";
        $jarcnt = 1;
        if (((-d "..\\..\\$board_ver") && (<..\\..\\$board_ver\\*\\*.jar>)) ||
            (!((($mmi_version eq "PLUTO_MMI")||($mmi_version eq "NEPTUNE_MMI")||($mmi_version eq "NEPTUNE_COLOR_MMI")) &&
             ($empty_resource eq "FALSE")))) {
          while ($jarname = <../../${board_ver}/*.jar>) {
            $jadname = $jarname;
            $jadname =~ s/\.jar/\.jad/;
            ($jadname = "") if (!-e $jadname);
            print GAME_CFG_H "MIDletSuite-$jarcnt: $jadname , $jarname\n";
            $jarcnt++;
          }
        } else {
          while ($jarname = <../*.jar>) {
            $jadname = $jarname;
            $jadname =~ s/\.jar/\.jad/;
            ($jadname = "") if (!-e $jadname);
            print GAME_CFG_H "MIDletSuite-$jarcnt: $jadname , $jarname\n";
            $jarcnt++;
          }
        }
        close GAME_CFG_H;
      }
      system("del /f /q .\\rom\\*");
      print("$gamePapay -config $gamecfg\n");
      system("$gamePapay -config $gamecfg");
      print("$gameExe rom\n");
      system("$gameExe rom > nul");
      system("move /Y kjava_sys_data_content.c ..\\..\\$board_ver > nul");
      system("move /Y kjava_sys_data_content.h ..\\..\\$board_ver > nul");
      # back to mcu folder
      chdir("..\\..\\..\\..\\..");
    }
   } else {   
    $gameGenDir = "$defaultBB\\builtin_game_generator";
    $gameExe = "DefaultGameGen.exe";
    $gameGenFile = "${gameGenDir}\\$gameExe";
    if ((-d $defaultBB) && (-d $gameGenDir) && (-e $gameGenFile)) {
      chdir($gameGenDir);
      if (((-d "..\\..\\$board_ver") && ((<..\\..\\$board_ver\\*.jar>) || (<..\\..\\$board_ver\\*.jad>))) ||
          (!((($mmi_version eq "PLUTO_MMI")||($mmi_version eq "NEPTUNE_MMI")||($mmi_version eq "NEPTUNE_COLOR_MMI")) &&
           ($empty_resource eq "FALSE")))) {
         if ((-d "..\\..\\$board_ver") && ((-e "..\\..\\$board_ver\\_main.ks") && (-e "..\\..\\$board_ver\\_policy.txt") && (-e "..\\..\\$board_ver\\_tck.ks") )) {
           print("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\$board_ver -output ..\\..\\$board_ver -create -logpath ..\\..\\$board_ver\n");
           system("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\$board_ver -output ..\\..\\$board_ver -create -logpath ..\\..\\$board_ver");
           if (-d "..\\..\\${board_ver}\\eureka") {
             print("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\$board_ver\\eureka -output ..\\..\\$board_ver\\eureka -create -gametype eureka -logpath ..\\..\\$board_ver\n");
             system("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\$board_ver\\eureka -output ..\\..\\$board_ver\\eureka -create -gametype eureka -logpath ..\\..\\$board_ver");
             system("del /f /q ..\\..\\$board_ver\\eureka_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\eureka_custom_mids.c");
             system("copy ..\\..\\$board_ver\\eureka\\j2me_custom_mids.c ..\\..\\$board_ver\\eureka_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\eureka\\j2me_custom_mids.c > nul");
           }
           if (-d "..\\..\\${board_ver}\\musicwav") {
             print("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\$board_ver\\musicwav -output ..\\..\\$board_ver\\musicwav -create -gametype musicwav -logpath ..\\..\\$board_ver\n");
             system("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\$board_ver\\musicwav -output ..\\..\\$board_ver\\musicwav -create -gametype musicwav -logpath ..\\..\\$board_ver");
             system("del /f /q ..\\..\\$board_ver\\musicwav_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\musicwav_custom_mids.c");
             system("copy ..\\..\\$board_ver\\musicwav\\j2me_custom_mids.c ..\\..\\$board_ver\\musicwav_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\musicwav\\j2me_custom_mids.c > nul");
           }
           if (-d "..\\..\\${board_ver}\\surfkitchen") {
             print("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\$board_ver\\surfkitchen -output ..\\..\\$board_ver\\surfkitchen -create -gametype surfkitchen -logpath ..\\..\\$board_ver\n");
             system("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\$board_ver\\surfkitchen -output ..\\..\\$board_ver\\surfkitchen -create -gametype surfkitchen -logpath ..\\..\\$board_ver");
             system("del /f /q ..\\..\\$board_ver\\surfkitchen_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\surfkitchen_custom_mids.c");
             system("copy ..\\..\\$board_ver\\surfkitchen\\j2me_custom_mids.c ..\\..\\$board_ver\\surfkitchen_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\surfkitchen\\j2me_custom_mids.c > nul");
           }
         } else {
           print("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\..\\$board_ver -output ..\\..\\$board_ver -create -logpath ..\\..\\$board_ver\n");
           system("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\..\\$board_ver -output ..\\..\\$board_ver -create -logpath ..\\..\\$board_ver");
           if (-d "..\\..\\${board_ver}\\eureka") {
             print("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\..\\$board_ver\\eureka -output ..\\..\\$board_ver\\eureka -create -gametype eureka -logpath ..\\..\\$board_ver\n");
             system("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\..\\$board_ver\\eureka -output ..\\..\\$board_ver\\eureka -create -gametype eureka -logpath ..\\..\\$board_ver");
             system("del /f /q ..\\..\\$board_ver\\eureka_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\eureka_custom_mids.c");
             system("copy ..\\..\\$board_ver\\eureka\\j2me_custom_mids.c ..\\..\\$board_ver\\eureka_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\eureka\\j2me_custom_mids.c > nul");
           }
           if (-d "..\\..\\${board_ver}\\musicwav") {
             print("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\..\\$board_ver\\musicwav -output ..\\..\\$board_ver\\musicwav -create -gametype musicwav -logpath ..\\..\\$board_ver\n");
             system("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\..\\$board_ver\\musicwav -output ..\\..\\$board_ver\\musicwav -create -gametype musicwav -logpath ..\\..\\$board_ver");
             system("del /f /q ..\\..\\$board_ver\\musicwav_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\musicwav_custom_mids.c");
             system("copy ..\\..\\$board_ver\\musicwav\\j2me_custom_mids.c ..\\..\\$board_ver\\musicwav_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\musicwav\\j2me_custom_mids.c > nul");
           }
           if (-d "..\\..\\${board_ver}\\surfkitchen") {
             print("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\..\\$board_ver\\surfkitchen -output ..\\..\\$board_ver\\musicwav -create -gametype surfkitchen -logpath ..\\..\\$board_ver\n");
             system("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\..\\$board_ver\\surfkitchen -output ..\\..\\$board_ver\\musicwav -create -gametype surfkitchen -logpath ..\\..\\$board_ver");
             system("del /f /q ..\\..\\$board_ver\\surfkitchen_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\surfkitchen_custom_mids.c");
             system("copy ..\\..\\$board_ver\\surfkitchen\\j2me_custom_mids.c ..\\..\\$board_ver\\surfkitchen_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\surfkitchen\\j2me_custom_mids.c > nul");
           }
         }
      } else {
         if ((-d "..\\..\\$board_ver") && ((-e "..\\..\\$board_ver\\_main.ks") && (-e "..\\..\\$board_ver\\_policy.txt") && (-e "..\\..\\$board_ver\\_tck.ks") )) {
           print("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet .. -output ..\\..\\$board_ver -create -logpath ..\n");
           system("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet .. -output ..\\..\\$board_ver -create -logpath ..");
           if (-d "..\\..\\${board_ver}\\eureka") {
             print("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\${board_ver}\\eureka -output ..\\..\\${board_ver}\\eureka -create -gametype eureka -logpath ..\n");
             system("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\${board_ver}\\eureka -output ..\\..\\${board_ver}\\eureka -create -gametype eureka -logpath ..");
             system("del /f /q ..\\..\\$board_ver\\eureka_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\eureka_custom_mids.c");
             system("copy ..\\..\\$board_ver\\eureka\\j2me_custom_mids.c ..\\..\\$board_ver\\eureka_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\eureka\\j2me_custom_mids.c > nul");
           }
           if (-d "..\\..\\${board_ver}\\musicwav") {
             print("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\${board_ver}\\musicwav -output ..\\..\\${board_ver}\\musicwav -create -gametype musicwav -logpath ..\n");
             system("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\${board_ver}\\musicwav -output ..\\..\\${board_ver}\\musicwav -create -gametype musicwav -logpath ..");
             system("del /f /q ..\\..\\$board_ver\\musicwav_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\musicwav_custom_mids.c");
             system("copy ..\\..\\$board_ver\\musicwav\\j2me_custom_mids.c ..\\..\\$board_ver\\musicwav_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\musicwav\\j2me_custom_mids.c > nul");
           }
           if (-d "..\\..\\${board_ver}\\surfkitchen") {
             print("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\${board_ver}\\surfkitchen -output ..\\..\\${board_ver}\\surfkitchen -create -gametype surfkitchen -logpath ..\n");
             system("$gameExe -setpath .\\setting -inputSystem ..\\..\\$board_ver -inputMidlet ..\\..\\${board_ver}\\surfkitchen -output ..\\..\\${board_ver}\\surfkitchen -create -gametype surfkitchen -logpath ..");
             system("del /f /q ..\\..\\$board_ver\\surfkitchen_custom_mids.c > nul") if (-e "..\\..\\$board_ver\\surfkitchen_custom_mids.c");
             system("copy ..\\..\\$board_ver\\surfkitchen\\j2me_custom_mids.c ..\\..\\$board_ver\\surfkitchen_custom_mids.c > nul");
             system("del /f /q ..\\..\\$board_ver\\surfkitchen\\j2me_custom_mids.c > nul");
           }
         } else {
           print("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet .. -output .. -create -logpath ..\n");
           system("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet .. -output .. -create -logpath ..");
           if (-d "..\\eureka") {
             print("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\eureka -output ..\\eureka -create -gametype eureka -logpath ..\n");
             system("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\eureka -output ..\\eureka -create -gametype eureka -logpath ..");
           }
           if (-d "..\\musicwav") {
             print("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\musicwav -output ..\\musicwav -create -gametype musicwav -logpath ..\n");
             system("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\musicwav -output ..\\musicwav -create -gametype musicwav -logpath ..");
           }
           if (-d "..\\surfkitchen") {
             print("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\surfkitchen -output ..\\surfkitchen -create -gametype surfkitchen -logpath ..\n");
             system("$gameExe -setpath .\\setting -inputSystem .. -inputMidlet ..\\surfkitchen -output ..\\surfkitchen -create -gametype surfkitchen -logpath ..");
           }
         }
      }
      # back to mcu folder
      chdir("..\\..\\..\\..\\..");
    } else {
      print("Skip to generate JAVA game due to no $gameGenFile\n");
    }
   }

    if (-d $boardBB) {
      opendir THATDIR, $boardBB;
      @tmpFiles = readdir THATDIR;
      closedir THATDIR;
      @j2meBBfiles = ();
      foreach $f (@tmpFiles) {
        next if (($f eq ".") || ($f eq "..") || (-d "$boardBB\\$f"));
        next if (($j2me_support eq "JBLENDIA") && ($f =~ /(ROMImage.cpp|nativesTable.cpp|ROMjava.c|nativeFunctionTable.c)/i));
        next if (($j2me_support eq "JBED") && ($f =~ /(ROMImage.cpp|nativesTable.cpp|ROMjava.c|nativeFunctionTable.c)/i));
        next if (($j2me_support eq "MTK_DUMMYVM") && ($f =~ /(ROMImage.cpp|nativesTable.cpp|ROMjava.c|nativeFunctionTable.c)/i));
        push(@j2meBBfiles, "$boardBB/$f");
      }
      foreach $f (@j2meBBfiles) {
        $f =~ /\/([^\/]+)$/;
        push(@delfiles, $1);
      }
      @allfiles = @j2meBBfiles;
    } else {
      print("$boardBB does NOT exist!\n");
    }

    if (-d $defaultBB) {
      opendir THATDIR, $defaultBB;
      @tmpFiles = readdir THATDIR;
      closedir THATDIR;
      @j2medeffiles = ();
      foreach $f (@tmpFiles) {
        next if (($f eq ".") || ($f eq "..") || (-d "$defaultBB\\$f") || ($f =~ /(.jar$|.jad$|LOG.txt|Setting_format_error.txt)/i) );
        next if (($j2me_support eq "JBLENDIA") && ($f =~ /(ROMImage.cpp|nativesTable.cpp|ROMjava.c|nativeFunctionTable.c)/i));
				next if (($j2me_support eq "JBED") && ($f =~ /(ROMImage.cpp|nativesTable.cpp|ROMjava.c|nativeFunctionTable.c)/i));
				next if (($j2me_support eq "MTK_DUMMYVM") && ($f =~ /(ROMImage.cpp|nativesTable.cpp|ROMjava.c|nativeFunctionTable.c)/i));
        push(@j2medeffiles, "$defaultBB/$f");
      }
      $mapfile = "$defaultBB\\DEFAULT_TABLE";
      if (-e $mapfile) {
        open (FILE_HANDLE, "<$mapfile") or die "cannot open $mapfile\n";
        while (<FILE_HANDLE>) {
          next if ((/^#/) || (/^\s*$/));
          if (/^J2ME_SUPPORT=(\S+)\s+(.+)$/) {
            $j2meSet = $1;
            $filelist = $2;
            @j2meSets = split(',', $j2meSet);
            $match = 0;
            foreach $b (@j2meSets) {
              next if ($j2me_support ne uc($b));
              $match = 1;
              last;
            }
            next if ($match == 1);
            @files = split(' ', $filelist);
            foreach $f (@files) { push(@delfiles, $f); }
          }
        }
        close FILE_HANDLE;
	}
	
        foreach $elem (@j2medeffiles) {
          next if ($elem =~ /DEFAULT_TABLE$/);
          next if ($elem =~ /MAPPING_TABLE$/);
          $match = 0;
          foreach $delF (@delfiles) {
            next if ($elem !~ /$delF/i);
            $match = 1;
            last;
          }
          next if ($match == 1);
          push(@allfiles, $elem);
        }
        
    } else {
      print("$defaultBB does NOT exist!\n");
    }
  }

  foreach $elem (@allfiles) {
    $elem =~ s/\//\\/g;
    $elem =~ s/[a-zA-Z0-9_\.\\\/]*\.[bB]+[aA]+[kK]+$//g;

    if(defined($optr_spec) && ($optr_spec ne "NONE"))
    {
        # Check if there is any operator resource file to be replaced
        $elem_tmp = $elem;
        my @elem_tmp = split /\\/, $elem_tmp;
        my $elem_tmp_filename = $elem_tmp[-1];
    
        foreach $tmp (keys %op_file)
        {
               $zz = $tmp;
               chomp($zz);
    
    	    # Remove "op_" in the filename
               $zz =~ s/^op_//;
               
    	    if ((exists $op_file{$tmp}) && ($elem_tmp_filename eq $zz)) 
    	    {
    		$elem = $op_file{$tmp};
    	    }
        }
    }
    $reading .= "$elem\n";
  }
}

open (file,">$lisfile") || die "cannot open $lisfile\n";
print file $reading;
close file;

#******************************************************************************
# Process pth file
#******************************************************************************
open (file,">$pthfile") || die "cannot open $pthfile\n";
if($j2me_support eq "JBLENDIA") {
	$allpath =~ s/custom\\j2me\\JBLENDIA/custom\\j2me\\JBLENDIA\\$board_ver\ncustom\\j2me\\JBLENDIA\\_DEFAULT_BB/;
} elsif($j2me_support eq "JBED") {
	$allpath =~ s/custom\\j2me\\JBED/custom\\j2me\\JBED\\$board_ver\ncustom\\j2me\\JBED\\_DEFAULT_BB/;
} else {
	$allpath =~ s/custom\\j2me\\IJET/custom\\j2me\\IJET\\$board_ver\ncustom\\j2me\\IJET\\_DEFAULT_BB/;
}
print file $allpath;
close file;

#******************************************************************************
# Process inc file
#******************************************************************************
$allinc = $allpath;
if ($project ne "basic") {  $allinc .= "l1audio\n"; }
$allinc .= "verno\n";
$allinc .= "drv\\include\n";
$allinc .= "usb\\include\n";


# WIFI_SUPPORT
if (($project ne "basic") && ($project ne "l1s") && defined($wifi_support)) {
  if (uc($wifi) ne "NONE") {
    $allinc .= "drv\\wifi\\${board_ver}\n";
    $allinc .= "wifi\\wndrv\\include\\hal\n";
    $allinc .= "wifi\\wndrv\\include\\hal\\mt5911\n";
    $allinc .= "wifi\\wndrv\\include\\mgmt\n";    
    $allinc .= "wifi\\wndrv\\include\\os\n";    
    $allinc .= "wifi\\wndrv\\include\n";        
  }
}

# MMI
if (($mmi_version eq "NEPTUNE_MMI") || ($mmi_version eq "NEPTUNE_COLOR_MMI")) {
  $mmidir = "lcmmi";
} else {
  $mmidir = "plutommi";
}

$allinc .= "${mmidir}\\MMI\\PROFILES\\ProfilesInc\n";
$allinc .= "${mmidir}\\MMI\\Inc\n";
$allinc .= "${mmidir}\\MMI\\GUI\\GUI_INC\n";
$allinc .= "${mmidir}\\MMI\\IdleScreen\\IdleScreenInc\n";
$allinc .= "${mmidir}\\MMI\\Framework\\History\\HistoryInc\n";
$allinc .= "${mmidir}\\MMI\\Framework\\MemManager\\MemManagerInc\n";
$allinc .= "${mmidir}\\MMI\\Framework\\EventHandling\\EventsInc\n";
$allinc .= "${mmidir}\\MMI\\Framework\\OSL\\OSLInc\n";
$allinc .= "${mmidir}\\MMI\\Framework\\Tasks\\TasksInc\n";
$allinc .= "${mmidir}\\MMI\\DateTime\\DateTimeInc\n";
$allinc .= "${mmidir}\\MMI\\MiscFramework\\MiscFrameworkInc\n";
$allinc .= "${mmidir}\\MTKApp\\MTKAppInc\n";
$allinc .= "${mmidir}\\MTKApp\\MDI\\MDIInc\n";
$allinc .= "${mmidir}\\MtkApp\\EngineerMode\\EngineerModeInc\n";
$allinc .= "${mmidir}\\MMI\\Setting\\SettingInc\n";
$allinc .= "${mmidir}\\MMI\\Organizer\\OrganizerInc\n";
$allinc .= "${mmidir}\\MMI\\Inc\\ImgID\n";
$allinc .= "${mmidir}\\MMI\\Inc\\MenuID\n";
$allinc .= "${mmidir}\\MMI\\Inc\\StringID\n";
if ($project ne "basic") { $allinc .= "${mmidir}\\MMI\\Audio\\AudioInc\n"; }

# J2ME
if (defined $j2me_support) {
  $allinc .= "j2me\\vm\\IJET\\adaptation\\include\n";
  $allinc .= "j2me\\jal\\include\n";
}

# Bluetooth
if (defined $bluetooth_support) {
  $allinc .= "bluetooth\\inc\\sys\n";
  $allinc .= "bluetooth\\inc\n";
}

open (file,">$incfile") || die "cannot open $incfile\n";
print file $allinc;
close file;

#******************************************************************************
# Process def file
#******************************************************************************
$reading = "__UCS2_ENCODING \nMMI_ON_HARDWARE_P\n";
$reading .= "APCS_INTWORK\nUSE_JAM=0\n";
$reading .= "COMPILER_SUPPORTS_LONG=1\n";
$reading .= "MT5911\n";
$reading .= "DBG=0\n";
$reading .= "BUILD_AP=0\n";
$reading .= "BUILD_CCX=0\n";
$reading .= "BUILD_WMM=0\n";
$reading .= "BUILD_11A=0\n";
$reading .= "BUILD_11G=1\n";
$reading .= "BUILD_11H=0\n";
$reading .= "BUILD_11D=0\n";
$reading .= "BUILD_SW_ENCRYPT=0\n";

open (file,">$deffile") || die "cannot open $deffile\n";
print file $reading;
close file;

#******************************************************************************
# Process MMI file
#******************************************************************************
if (defined $mmi_version) {
  if (($mmi_version eq "NEPTUNE_MMI") || ($mmi_version eq "NEPTUNE_COLOR_MMI")) {
    system("copy make\\lcmmi\\LC_MMI\\*.* make\\lcmmi\\*.*");
  }
}

##### VIP!! MT6218B and MT6219 use RGB565 decoder!!
##### VIP!! MT6205B uses RGB3553 decoder!!
##### 6205B 8 bits  => RGB 3553
##### 6205B 16 bits  => RGB 565
##### 6205C, 6218B, 6219 => RGB 565

if ($platform eq "MT6205B") {
  if ($lcd_module eq "KM122_LCM") {
    system("copy ${mmidir}\\Customer\\Images\\decoder\\RGB565\\*.* ${mmidir}\\Customer\\Images");
  } else {
    system("copy ${mmidir}\\Customer\\Images\\decoder\\RGB3553\\*.* ${mmidir}\\Customer\\Images");
  }
} elsif ((($lcd_module eq "MTKLCM_COLOR") || ($lcd_module eq "INFOLCM") || ($lcd_module eq "POWERTIP_LCM")) && (($platform eq "MT6208") || ($platform eq "MT6205") || ($platform eq "MT6218") )) {
  system("copy ${mmidir}\\Customer\\Images\\decoder\\RGB3553\\*.* ${mmidir}\\Customer\\Images");
} else {
  system("copy ${mmidir}\\Customer\\Images\\decoder\\RGB565\\*.* ${mmidir}\\Customer\\Images");
}

#******************************************************************************
# Process WAP file
#******************************************************************************
if (($custom eq "DARTS6227")) {
  system("copy make\\wae\\NO_SEC\\*.* make\\wae\\*.*");
  system("copy make\\wap\\NO_SEC\\*.* make\\wap\\*.*");
  system("copy make\\wapadp\\NO_SEC\\*.* make\\wapadp\\*.*");
}

#******************************************************************************
# Process make files of ZI and T9
#******************************************************************************
if (defined $mmi_version) {
  system("copy make\\t9\\${mmidir}\\*.* make\\t9\\*.*");
  system("copy make\\zi\\${mmidir}\\*.* make\\zi\\*.*");
}

#******************************************************************************
# Process DRM vendor information
#******************************************************************************
($drm_support = "NONE") if (!defined $drm_support);
if (($drm_support ne "NONE") && (!defined($custom_release) || ($custom_release eq "FALSE"))){

	system("mkdir make\\drmadp") if (!-d "make\\drmadp");
	my $drm_lis="make\\drmadp\\drmadp.lis";
	my $drm_pth="make\\drmadp\\drmadp.pth";
	my $drm_inc="make\\drmadp\\drmadp.inc";
	my $drm_def="make\\drmadp\\drmadp.def";

	if (($drm_support eq "MTK") || ($drm_support eq "ALL"))
	{
		@drmdirs =  ("vendor\\drm\\MTK\\adp\\src");    
	}
	elsif ($drm_support eq "BSCI")
	{
		@drmdirs =  ("vendor\\drm\\$drm_support\\adp\\src", "vendor\\drm\\$drm_support\\adp\\oai\\\src");    
	}
	else
	{
		@drmdirs =  ("");    
	}

	
	
    $reading = "";
    #drm.lis
	  foreach $t (@drmdirs) {

	    $all_drm_pth .= "$t\n";
	    
		opendir THATDIR, $t;
		@tmpFiles = readdir THATDIR;
		closedir THATDIR;
		@allfiles = ();
		foreach $f (@tmpFiles) {
			next if (($f eq ".") || ($f eq "..") || (-d "$t\\$f"));
				push(@allfiles, "$t/$f");
		}
		
	    foreach $elem (@allfiles) {
	        $elem =~ s/\//\\/g;
	        $elem =~ s/[a-zA-Z0-9_\.\\\/]*\.[bB]+[aA]+[kK]+$//g;
	        $reading .= "$elem\n";
	    }
	}
    open (file,">$drm_lis") || die "cannot open $drm_lis\n";
    print file $reading;
    close file;

    #drm.pth
    open (file,">$drm_pth") || die "cannot open $drm_pth\n";
    print file $all_drm_pth;
    close file;

    #drm.inc
    system("del /f /q $drm_inc");
    system("copy /y make\\drm\\drm.inc $drm_inc");

    if (($drm_support eq "MTK") || ($drm_support eq "ALL"))
    {    
      $all_drm_inc .= "vendor\\drm\\MTK\\adp\\include\n";
    }
    elsif ($drm_support eq "BSCI")
    {
	    $all_drm_inc .= "vendor\\drm\\$drm_support\\adp\\oai\\include\n";    
    	$all_drm_inc .= "vendor\\drm\\$drm_support\\src\\drmagent-v2\\inc\n";    
    	$all_drm_inc .= "vendor\\drm\\$drm_support\\src\\drmagent-v2\\src\n";    
    }
    
    open (file,">>$drm_inc") || die "cannot open $drm_inc\n";
    print file $all_drm_inc;
    close file;

    #drm.def
    $all_drm_def = "";
    open (file,">>$drm_def") || die "cannot open $drm_def\n";
    print file $all_drm_def;
    close file;

}


exit(0);

##########################################
# replace file path for operator resource
##########################################
sub Replace_operator_resource
{
  	die "$op_custom_lis_file does not exist\n" if (! -e $op_custom_lis_file);
  	print "Read $op_custom_lis_file...\n";
  	
  	open (F,"<$op_custom_lis_file") || die "cannot open $op_custom_lis_file\n";

  	$hit_flag = 0;
  	
  	# Get the resource file list for the operator spec
  	while (<F>)
  	{
  		next if(/^\s*$/);

  		$hit_flag = 0 if(/\[\w*\]/);
  		
  		if(/$optr_spec/i)
  		{
  			$hit_flag = 1;
  			next;
  		}

  		if ($hit_flag == 1)
  		{
			# Need to add operator path to custom.pth and custom.inc
			$optr_path_hit = 1;
			
  			my $fullname = $_;
  			# Get file name
  			my @file = split /\\/;
  			my $file = $file[-1];

  			$op_file{$file} = $fullname;
  		}
  	}

  	close F;
  	
  	if  ($optr_path_hit == 1)
  	{
  		$allpath .= "$optr_path\n";
  	}
}
