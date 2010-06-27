#!/usr/local/bin/perl

# 
# Copyright Statement:
# --------------------
# This software is protected by Copyright and the information contained
# herein is confidential. The software may not be copied and the information
# contained herein may not be used or disclosed except with the written
# permission of MediaTek Inc. (C) 2005
# 
# BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
# NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
# SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
# 
# BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
# LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
# 
# THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
# WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
# LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
# RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
# THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
# 

(!-d "make")&&(die "Folder \"make\" does NOT exist!\nPlease help to check.\n");

use Win32::OLE qw(in);

if ((-e "mtk_tools\\Perl") && ($] >= 5.008006)){
  use lib "mtk_tools\\Perl";
  use Win32::Process;
  use Win32;
  use File::Basename;
  Parse::CSV->import() if (eval "require Parse::CSV");
  MIME::Lite->import() if (eval "require MIME::Lite");
}

$myCmd = "make"; #$0
$plat = "";
$custom = "MTK";
@arguments = ();
$project = "";
$action = "";
$m_in_lsf = 0;
@mOpts = ();
$fullOpts = "";
$level = "";
$relDir = "";
$MoDISLogDir = "_BUILD_LOG"; #for MoDIS
$modisDir = "";
$MoDIS_poweron_result = 0;
$ini = "make.ini";
$enINI = 0;
($enINI = 1) if (($ENV{"USERDOMAIN"} =~ /MTK/i) || ($ENV{"USERDOMAIN"} =~ /PMT/i) || ($ENV{"USERDOMAIN"} =~ /MBJ/i));
($#ARGV < 0) && &Usage;
(($#ARGV < 1) && ($enINI == 0)) && &Usage;
      
$newMoDIS = 0;
$atMoDIS = 0;
$dummyvm = 0;
@levels = qw(level2_src level2_obj level1 vendor);
@actions = qw(new update remake clean resgen codegen emiclean emigen sysgen ckscatter mmi_feature_check mmi_obj_check operator_check viewlog c,r c,u ckcr);
unshift(@actions, "bootloader") if ((-d "bootloader") && (-d "bootloader\\src"));
unshift(@actions, "fota") if ((-d "fota") && (-d "fota\\src"));
@projects = qw(l1s gsm gprs basic umts);
@orgARGV = @ARGV;
$ENV{"NUMBER_OF_PROCESSORS"} = 1;

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /^(p|pl|pla|plat|platf|platfo|platfor|platform)=(\w+)/i) {
    $plat = $2;
  } elsif ($ARGV[0] =~ /^(c|cu|cus|cust|custo|custom)=(\w+)/i) {
    $custom = $2;
  } elsif ($ARGV[0] =~ /-modis/i) {
    $newMoDIS = 1;
  } elsif ($ARGV[0] =~ /-atmodis/i) {
    $atMoDIS = 1;
  } elsif ($ARGV[0] =~ /-dummyvm/i) {
    $dummyvm = 1;
  } elsif ($ARGV[0] =~ /-release/i) {
    $modisDir = "Release";
  } elsif ($ARGV[0] =~ /-debug/i) {
    $modisDir = "Debug";
  } elsif ($ARGV[0] =~ /-h/i) {
    &Usage;
  } elsif ($ARGV[0] =~ /^-(o|op|opt)=(.*)$/i) {
    $fullOpts = "CMD_ARGU=$2";
    @mOpts = split(",", $2);
  } elsif ($ARGV[0] =~ /-lsf/i) {
    $m_in_lsf = 1;
  } else {
    foreach $m (@projects) {
      if (lc($ARGV[0]) eq $m) {
        $project = $m;
        shift(@ARGV);
        last;
      } elsif (lc($ARGV[1]) eq $m) {
        $project = $m;
        if ($ARGV[0] =~ /^mt6\d\d\d\w?$/i) {
          $plat = $ARGV[0];
        } else {
          $custom = $ARGV[0];
        }
        shift(@ARGV);
        shift(@ARGV);
        last;
      }
    }
    if (($project eq "") && ($enINI == 1) && (-e $ini)) {
      open (FILE_HANDLE, "<$ini") or die "cannot open $ini\n";
      while (<FILE_HANDLE>) {
        if (/^(\S+)\s*=\s*(\S+)/) {
          $keyname = $1;
          $${keyname} = $2;
        }
      }
      close FILE_HANDLE;
      print "custom=$custom; plat=$plat; project=$project\n";
    }
    ($project eq "") && (die "Unrecognized \"$ARGV[0]\" or \"$ARGV[1]\"\nLack off one of (@projects)\nOr try $myCmd -h\n");
    if ($#ARGV != -1) {
      if ($ARGV[0] =~ /^[ucrUCR]$/) {
        ($action = "clean") if ($ARGV[0] =~ /^[cC]$/);
        ($action = "update") if ($ARGV[0] =~ /^[uU]$/);
        ($action = "remake") if ($ARGV[0] =~ /^[rR]$/);
        shift(@ARGV);
        @arguments = @ARGV;
        @ARGV = ();
        last;
      } else {
	unshift(@actions, "bm_new", "check", "notify", "cq_notify", "err_out", "db_notify", "db_modis_notify", "bm_remake", "bm_update", "patch", "ckmake")
          if (($ENV{"USERDOMAIN"} =~ /MTK/i) || ($ENV{"USERDOMAIN"} =~ /PMT/i) || ($ENV{"USERDOMAIN"} =~ /MBJ/i));
	if (-d "MoDIS") {
	  unshift(@actions, "new_modis") if ((-e "MoDIS\\createMoDIS.pl") || (-e "MoDIS\\MoDIS.dsw"));
	  unshift(@actions, "gen_modis") if (-e "MoDIS\\createMoDIS.pl");
	  unshift(@actions, "codegen_modis") if (-e "MoDIS\\modisCodegen.pl");
	  unshift(@actions, "remake_modis", "clean_modis") if (-e "MoDIS\\MoDIS.dsw");
	  unshift(@actions, "at_modis");
        }
	unshift(@actions, "cmmgen", "rel") if (($ENV{"USERDOMAIN"} =~ /MTK/i) || ($ENV{"USERDOMAIN"} =~ /PMT/i) || ($ENV{"USERDOMAIN"} =~ /MBJ/i));
        foreach $act (@actions) {
          if (lc($ARGV[0]) eq $act) {
            $action = $act;
            if (($act eq "bm_update") || ($act eq "bm_remake")) {
              ($action = "update") if ($act eq "bm_update");
              ($action = "remake") if ($act eq "bm_remake");
              ($fullOpts eq "") ? ($fullOpts = "CMD_ARGU=-k") : ($fullOpts .= ",-k");
              push(@mOpts, "-k");
	    }
            shift(@ARGV);
            @arguments = @ARGV;
            @ARGV = ();
            last;
          }
        }
      }
    }
    ($action eq "") && (die "Unrecognized \"$ARGV[0]\"\nLack off one of (@actions)\nOr try $myCmd -h\n");
    ($#ARGV != -1) && (die "Unrecognized \"@ARGV\"\nPlease check again or try $myCmd -h\n");
    if ($action eq "rel") {
      $relDir = $arguments[0];
      shift(@arguments);
      ($#arguments == -1) && die "Lack off release level(@levels).\nOr try $myCmd -h\n";
      foreach $arg (@levels) {
        if (lc($arguments[0]) eq $arg) {
          $level = $arg;
          shift(@arguments);
          last;
        }
      }
      ($level eq "") && die "Lack off release level(@levels).\nOr try $myCmd -h\n";
      ($#arguments != -1) && (warn "Unrecognized \"@arguments\"\n");
    }
    last;
  }
  shift(@ARGV);
}

if ($ENV{"OS"} eq "Windows_NT") {
  $delCmd = "del /Q";
  $dirDelim = "\\";
  $makeFolder = "make\\";
  $toolsFolder = "tools\\";
  $MTKtoolsFolder = "mtk_tools\\";
  $makeCmd = "tools\\make.exe";
} else {
  $delCmd = "rm";
  $dirDelim = "/";
  $makeFolder = "make/";
  $toolsFolder = "tools/";
  $MTKtoolsFolder = "mtk_tools/";
  $makeCmd = "tools/make";
}

die "$toolsFolder folder does NOT exist!\n" if (!-d $toolsFolder);

if (!-e $makeCmd) 
{
	warn "$makeCmd does NOT exist!\n";

	if ($ENV{"USERDOMAIN"} =~ /MTK|PMT|MBJ/i)
	{
		if (-e "tools\\thirdParties.pl")
		{
			print("perl tools\\thirdParties.pl -cp \n");
			system("perl tools\\thirdParties.pl -cp");
		}
		else
		{
			warn "tools\\thirdParties.pl does NOT exist!\n";	
			exit 1;
		}
	}
	else
	{
		exit 1;
	}
}

if (($action eq "update") || ($action eq "remake") || ($action eq "new") || ($action eq "bm_new") ||
    ($action eq "c,r") || ($action eq "c,u")) {
  if ($ENV{"NUMBER_OF_PROCESSORS"} > 1) {
    if ($fullOpts eq "") {
      $fullOpts = "CMD_ARGU=-j$ENV{\"NUMBER_OF_PROCESSORS\"}";
    } else {
      $fullOpts .= ",-j$ENV{\"NUMBER_OF_PROCESSORS\"}";
    }
  }
}

if ($fullOpts ne "") {
  $fullOpts =~ s/"/\\"/g;
  $fullOpts = "\"$fullOpts\"";
  $fullOpts =~ s/,/ /g;
  $makeCmd .= " " . join(" ", @mOpts) . " $fullOpts ";
}

$msdev = 'msdev';
$cl = 'cl';
$is_msdev = 0;
$is_cl = 0;
$VSCommonDir = "C:\\Program Files\\Microsoft Visual Studio\\Common";
$MSDevDir = "C:\\Program Files\\Microsoft Visual Studio\\Common\\MSDev98";
$MSVCDir = "C:\\Program Files\\Microsoft Visual Studio\\VC98";
$VcOsDir = "WIN95";
if (($newMoDIS == 1) || ($atMoDIS == 1) || ($action =~ /MoDIS/i)) {
  if ((-d $VSCommonDir) && (-d $MSDevDir) && (-d $MSVCDir)) {
    if ($ENV{"OS"} eq "Windows_NT") {
      $VcOsDir = "WINNT";
      $ENV{"PATH"} = "${MSDevDir}\\BIN;${MSVCDir}\\BIN;${VSCommonDir}\\TOOLS\\${VcOsDir};${VSCommonDir}\\TOOLS;" . $ENV{"PATH"};
    } else {
      $ENV{"PATH"} = "${MSDevDir}\\BIN;${MSVCDir}\\BIN;${VSCommonDir}\\TOOLS\\${VcOsDir};${VSCommonDir}\\TOOLS;" .$ENV{"windir"}. "\\SYSTEM;" . $ENV{"PATH"};
    }
    $ENV{"INCLUDE"} = "${MSVCDir}\\ATL\\INCLUDE;${MSVCDir}\\INCLUDE;${MSVCDir}\\MFC\\INCLUDE;". $ENV{"INCLUDE"};
    $ENV{"LIB"} = "${MSVCDir}\\LIB;${MSVCDir}\\MFC\\LIB;". $ENV{"LIB"};
  } else {
    print "$VSCommonDir does NOT exist!\n" if (!-d $VSCommonDir);
    print "$MSDevDir does NOT exist!\n" if (!-d $MSDevDir);
    print "$MSVCDir does NOT exist!\n" if (!-d $MSVCDir);
  }
  $is_msdev = system("$msdev /? > nul 2>&1");
  $is_cl = system("$cl > nul 2>&1");
}

if ($m_in_lsf == 1) {
  die "NOT IN LSF SERVER!\n" if ($ENV{"LS_ADMINNAME"} eq "");
  $computerName = $ENV{"COMPUTERNAME"};
  system("echo set LAST_SUBMITTED_CF=$computerName > LAST_S_C.bat");
  $ENV{"TMP"} = "e:\\temp";
  $ENV{"TEMP"} = "e:\\temp";
  system("mkdir e:\\temp  > nul 2>&1") if (!-d "e:\\temp");
}

if ($plat ne "") {
  $plat =~ y/a-z/A-Z/;
  $theMF = "${makeFolder}${plat}_${project}.mak";
  $enFile = "${makeFolder}${plat}_${project}_en.def";
  $disFile = "${makeFolder}${plat}_${project}_dis.def";
  if ($project =~ /GPRS/i) {
    $theVerno = "${makeFolder}verno_classb.bld";
  } elsif ($project =~ /UMTS/i) {
    $theVerno = "${makeFolder}verno_classb_umts.bld";
  } else {
    $theVerno = "${makeFolder}verno.bld";
  }
} else {
  $custom =~ y/a-z/A-Z/;
  $plat = "NONE";
  $theMF = "${makeFolder}${custom}_${project}.mak";
  $enFile = "${makeFolder}${custom}_${project}_en.def";
  $disFile = "${makeFolder}${custom}_${project}_dis.def";
  $theVerno = "${makeFolder}Verno_${custom}.bld";
  if (($custom eq "MTK") || ($custom =~ /\bMT62\d\d\w?\b/i)) {
    if ($custom =~ /\bMT62\d\d\w?\b/i) {
      $plat= $custom;
      $custom = "MTK";      
    }
    if ($project =~ /GPRS/i) {
      $theVerno = "${makeFolder}verno_classb.bld";
    } elsif ($project =~ /UMTS/i) {
      $theVerno = "${makeFolder}verno_classb_umts.bld";
    } else {
      $theVerno = "${makeFolder}verno.bld";
    }
  }
}
(!-e $theMF) && (die "$theMF does NOT exist!\nPlease help to check.\n");
(!-e $theVerno) && (die "$theVerno does NOT exist!\nPlease help to check.\n");
$myMF = "gsm2.mak";

open (FILE_HANDLE, "<$theMF") or die "cannot open $theMF\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    #defined($${keyname}) && warn "$1 redefined in $thefile!\n";
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;
if ($modisDir eq "") {
  if ((($mmi_version eq "PLUTO_MMI") || ($mmi_version eq "NEPTUNE_MMI")) && ($empty_resource eq "FALSE")) {
    $modisDir = "Debug";
  } else {
    $modisDir = "Release";
  }
}

if (($m_in_lsf == 0) && ($action =~ /new/i) && ($ENV{"SESSIONNAME"} ne "") &&
    ($ENV{"LSF_BINDIR"} ne "") && ($project !~ /BASIC/i) && ($project !~ /L1S/i)) {

  chomp($cwd = `cd`);
  if (($cwd =~ /^[a-df-z]/i) && ($ENV{COMPUTERNAME} !~ /mtkcf/i)) {

    print "Before submitting into CF machines, pre-check the Makefile and cmmgen\n";  
    $ENV{"ACTION"} = "cmmgen";
    system("$delCmd ${makeFolder}~*.tmp *.d > nul 2>&1");
    system("echo CUSTOMER=$custom > ${makeFolder}~buildinfo.tmp");
    system("echo PROJECT=$project >> ${makeFolder}~buildinfo.tmp");
    system("echo APLAT=$plat >> ${makeFolder}~buildinfo.tmp");
    $timeStr = &CurrTimeStr;
    system("echo BUILD_DATE_TIME=$timeStr >> ${makeFolder}~buildinfo.tmp");
    $preTestResult = system("${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project cmmgen");
    (&writeINI && exit 1) if ($preTestResult != 0);
    print "Pass pre-check for Makefile and cmmgen\n";  

    $env_last_S_CF = "";
    $lastSC = "LAST_S_C.bat";
    if ((-e $lastSC) && (open(LOGF, "${lastSC}"))) {
      while (<LOGF>) {
        if (/set LAST_SUBMITTED_CF=(\S+)/) {
          $env_last_S_CF = $1;
          last;
        }
      }
      close(LOGF);
    }
    $ENV{"NUMBER_OF_PROCESSORS"} = 1;
    if ($env_last_S_CF eq "") {
      system("bsub -I perl m_cp2lsf.pl @orgARGV");
    } else {
      system("bsub -I -m \"${env_last_S_CF}+2 mtkcf+1\" perl m_cp2lsf.pl @orgARGV");
    }
    &writeINI;
    exit 0;
  }
}

if ($#arguments != -1) {
  if (($action eq "clean") || ($action eq "remake") || ($action eq "update") ||
      ($action eq "c,r") || ($action eq "c,u") || ($action eq "remake_modis") ||
      ($action eq "clean_modis")) {
    $chk_wrong = 0;
    foreach $argu (@arguments) {
      next if ((lc($argu) eq "modis_ui") && (($action eq "remake_modis") || ($action eq "clean_modis")));
#      (!-d "${makeFolder}$argu") && (!-d "${makeFolder}${argu}_classb") && ($chk_wrong = 1) && print "Wrong module name ==> $argu\n";
    }
    ($chk_wrong == 1) && die "Please check and retry again\n";
  }
}

if ($action eq "c,r") {
  @theAct = qw(clean remake);
} elsif ($action eq "c,u") {
  @theAct = qw(clean update);
} else {
  @theAct = ($action);
}

foreach $action (@theAct) {
  $ENV{"ACTION"} = $action;
  system("$delCmd ${makeFolder}~*.tmp *.d > nul 2>&1");
  system("echo CUSTOMER=$custom > ${makeFolder}~buildinfo.tmp");
  system("echo PROJECT=$project >> ${makeFolder}~buildinfo.tmp");
  system("echo APLAT=$plat >> ${makeFolder}~buildinfo.tmp");
  $timeStr = &CurrTimeStr;
  system("echo BUILD_DATE_TIME=$timeStr >> ${makeFolder}~buildinfo.tmp");
  system("echo ACTION=$action#Huyanwei Add It  >> ${makeFolder}~buildinfo.tmp");
  
  if ($action eq "clean") {
    if ($#arguments != -1) {
      system("echo DO_CLEAN_MODULE=TRUE > ${makeFolder}~cleanmod.tmp");
      system("echo CLEAN_MODS=@arguments >> ${makeFolder}~cleanmod.tmp");
      system("${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project cleanmod");
    } else {
      system("echo DO_CLEAN_MODULE=FALSE > ${makeFolder}~cleanmod.tmp");
      system("${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project cleanall");
    }
  } elsif (($action eq "remake") && ($#arguments != -1)) {
    system("echo DO_REMAKE_MODULE=TRUE > ${makeFolder}~remakemod.tmp");
    system("echo REMAKE_MODS=@arguments >> ${makeFolder}~remakemod.tmp");
  } elsif (($action eq "update") && ($#arguments != -1)) {
    system("echo DO_UPDATE_MODULE=TRUE > ${makeFolder}~updatemod.tmp");
    system("echo UPDATE_MODS=@arguments >> ${makeFolder}~updatemod.tmp");
  } elsif ($action eq "codegen") {
    system("${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project code_generate");
  } elsif ($action eq "check") {
    system("perl ${toolsFolder}parse_comp_err.pl $custom");
  } elsif ($action eq "notify") {
    system("perl ${MTKtoolsFolder}notify_err.pl $custom $project bm_notify");
  } elsif ($action eq "cq_notify") {
    system("perl ${MTKtoolsFolder}notify_err.pl $custom $project cq_notify");  
  } elsif ($action eq "err_out") {
    system("perl ${MTKtoolsFolder}notify_err.pl $custom $project err_out");
  } elsif ($action eq "db_notify") {
    system("perl ${MTKtoolsFolder}notify_err.pl $custom $project db_notify");
  } elsif ($action eq "db_modis_notify") {
    system("perl ${MTKtoolsFolder}notify_err.pl $custom $project db_modis_notify");
  } elsif ($action eq "patch") {
    system("perl ${MTKtoolsFolder}patch_file.pl $custom $project @arguments");
  } elsif ($action =~ /_modis$/) {
    &chdirMoDIS;
    &genMoDIS if (($action eq "new_modis") || ($action eq "gen_modis"));
    &codegenMoDIS if (($action eq "new_modis") || ($action eq "codegen_modis"));
    &cleanMoDIS if (($action eq "new_modis") || ($action eq "clean_modis"));
    &remakeMoDIS if (($action eq "new_modis") || ($action eq "remake_modis"));
    &MoDIS_auto_power_on_test if ($action eq "new_modis");
    &at_MoDIS if ($action eq "at_modis");
    &chdirToMcu;
    $mcddllpath = "ps\\mcddll";
    if ((-d $mcddllpath) && (-e "${mcddllpath}\\mcddll.dsw")) {
      if ($action eq "new_modis") {
      	chdir($mcddllpath);
      	system("$msdev mcddll.dsw /MAKE \"mcddll - Win32 $modisDir\" /rebuild > nul 2>&1");
     	chdir("..\\..");
        if (-e "${mcddllpath}\\mcddll.dll") {
          system("copy /y ${mcddllpath}\\mcddll.dll tst\\database_modis\\mcddll.dll > nul");
        }
      } elsif ($action eq "remake_modis") {
      	chdir($mcddllpath);
      	system("$msdev mcddll.dsw /MAKE \"mcddll - Win32 $modisDir\" > nul 2>&1");
      	chdir("..\\..");
        if (-e "${mcddllpath}\\mcddll.dll") {
          system("copy /y ${mcddllpath}\\mcddll.dll tst\\database_modis\\mcddll.dll > nul");
        }
      }
    }
  } elsif ($action eq "viewlog") {
    $logDir = ".\\build\\${custom}\\log";
    die "$logDir does NOT exist\n" if (!-d $logDir);
    if ($#arguments != -1) {
      foreach $argu (@arguments) {
        if (-e "${logDir}\\${argu}.log") {
          system("start ${logDir}\\${argu}.log");
        } elsif (-e "${logDir}\\${argu}_classb.log") {
          system("start ${logDir}\\${argu}_classb.log");
        } else {
           warn "${logDir}\\${argu}.log does NOT exist\n";
        }
      }
    } else {
      while ($argu = <$logDir\\*.log>) {
        system("start ${argu}") if (-e "${argu}");
      }
    }
  } elsif ($action eq "rel") {
    #(!-e $disFile) && (die "$disFile does NOT exist!\nPlease help to check.\n");
    if (!-e $enFile) {
      warn "$enFile does NOT exist!\nCreate an EMPTY $enFile\n";
      sleep 2;
      system "copy /y nul $enFile > nul";
    }
    system("echo LEVEL=$level >> ${makeFolder}~buildinfo.tmp");
    system("echo DUMMYVM=TRUE >> ${makeFolder}~buildinfo.tmp") if ($dummyvm == 1);
    system("$makeCmd -f${makeFolder}custom_release.mak -r -R CUSTOMER=$custom PROJECT=$project RELEASE_DIR=$relDir LEVEL=$level");
    &writeINI;
    exit 0;
  } elsif (($action ne "new") && ($action ne "bm_new")) {
    system("echo #Huyanwei ${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project $action >> ${makeFolder}~buildinfo.tmp");
    system("${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project $action");
    next;
  }
  
  if (($action eq "remake") || ($action eq "update") ||
      ($action eq "new")|| ($action eq "bm_new")) {
    if ($action eq "bm_new") {
      system("echo BM_NEW=TRUE >> ${makeFolder}~buildinfo.tmp");
      $result = system("${makeCmd} -f${makeFolder}${myMF} -k -r -R CUSTOMER=$custom PROJECT=$project new");
    } else {
      system("echo #Huyanwei ${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project $action >> ${makeFolder}~buildinfo.tmp");
      $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project $action");
    }

    &writeINI;
    if ((($newMoDIS == 1) || ($atMoDIS == 1)) && (($result == 0) && (-d "MoDIS"))) {
      &chdirMoDIS;
      &genMoDIS;
      &codegenMoDIS;
      &cleanMoDIS;
      &remakeMoDIS;
      &MoDIS_auto_power_on_test;
      if ($atMoDIS == 1) {
      	&at_MoDIS;
      }
      &chdirToMcu;
    }
    exit 0;
  }
}

&writeINI;
exit 0;

sub genMoDIS {
  &chdirToMcu;	
  system("${makeCmd} -f${makeFolder}${myMF} -r -R CUSTOMER=$custom PROJECT=$project cleanlog");
  &chdirMoDIS;
  if (!-e "createMoDIS.pl") {
    warn "Skip genMoDIS due to script createMoDIS.pl does NOT exist!\n";
    return;
  }
  print("perl createMoDIS.pl ..\\$theMF\n") if (-e "createMoDIS.pl");
  system("perl createMoDIS.pl ..\\$theMF") if (-e "createMoDIS.pl");
}

sub codegenMoDIS {
  if (!-e "modisCodegen.pl") {
    warn "Skip codegenMoDIS due to script modisCodegen.pl does NOT exist!\n";
    return;
  }
  die "Could not run \"cl.exe\". Please check your PATH!\n" if ($is_cl != 0);
  mkdir($MoDISLogDir) if (!-d $MoDISLogDir);
  print("perl modisCodegen.pl ..\\$theMF > ${MoDISLogDir}\\codegen.log\n") if (-e "modisCodegen.pl");
  system("perl modisCodegen.pl ..\\$theMF > ${MoDISLogDir}\\codegen.log") if (-e "modisCodegen.pl");
}

sub cleanMoDIS {
  die "Could not run \"msdev.exe\". Please check your PATH!\n" if ($is_msdev != 0);
  if ($#arguments != -1) {
    foreach $argu (@arguments) {
      if (($project =~ /(GPRS|UMTS)/i) && ((lc($argu) eq "l1") || (lc($argu) eq "rr") || (lc($argu) eq "mm")
         || (lc($argu) eq "l4") || (lc($argu) eq "peer") || (lc($argu) eq "interface"))) {
        $argu .= "_classb";
      }
      if (((!-e "${argu}\\${argu}.ini") && (lc($argu) ne "modis_ui")) || (!-e "${argu}\\${argu}.dsp")) {
        warn "SKIP $argu since ${argu}\\${argu}.ini or ${argu}\\${argu}.dsp does NOT exist\n";
        next;
      }
      print("$msdev MoDIS.dsw /MAKE \"$argu - Win32 $modisDir\" /clean\n");
      system("$msdev MoDIS.dsw /MAKE \"$argu - Win32 $modisDir\" /clean");
    }
  } else {
    print("$msdev MoDIS.dsw /MAKE \"MoDIS - Win32 $modisDir\" /clean\n");
    system("$msdev MoDIS.dsw /MAKE \"MoDIS - Win32 $modisDir\" /clean");
  }
}

sub remakeMoDIS {
  mkdir($MoDISLogDir) if (!-d $MoDISLogDir);
  die "Could not run \"msdev.exe\". Please check your PATH!\n" if ($is_msdev != 0);

  if ($#arguments != -1) {
    foreach $argu (@arguments) {
      if (($project =~ /(GPRS|UMTS)/i) && ((lc($argu) eq "l1") || (lc($argu) eq "rr") || (lc($argu) eq "mm")
         || (lc($argu) eq "l4") || (lc($argu) eq "peer") || (lc($argu) eq "interface"))) {
        $argu .= "_classb";
      }
      if (((!-e "${argu}\\${argu}.ini") && (lc($argu) ne "modis_ui")) || (!-e "${argu}\\${argu}.dsp")) {
        warn "SKIP $argu since ${argu}\\${argu}.ini or ${argu}\\${argu}.dsp does NOT exist\n";
        next;
      }
      system("perl ../tools/time.pl");
      print("$msdev MoDIS.dsw /MAKE \"$argu - Win32 $modisDir\" /OUT ${MoDISLogDir}\\${argu}.log\n");
      $result = system("$msdev MoDIS.dsw /MAKE \"$argu - Win32 $modisDir\" /OUT ${MoDISLogDir}\\${argu}.log");
      if ($result == 0) {
        print("      ==> [P]\n");
      } else {
        print("      ==> [F]\n");
      }
    }
  } else {
    print("\nBuilding MoDIS ...\n");
    if ((-e "lib_list") && (open(LOGF, "<lib_list"))) {
      while ($f = <LOGF>) {
        chomp($f);
        next if (!-e "${f}\\${f}.ini");
        next if (!-e "${f}\\${f}.dsp");
        system("perl ../tools/time.pl");
        print("$msdev MoDIS.dsw /MAKE \"$f - Win32 $modisDir\" /OUT ${MoDISLogDir}\\${f}.log\n");
        $result = system("$msdev MoDIS.dsw /MAKE \"$f - Win32 $modisDir\" /OUT ${MoDISLogDir}\\${f}.log");
        if ($result == 0) {
          print("      ==> [P]\n");
        } else {
          print("      ==> [F]\n");
        }
      }
      close(LOGF);
    }
  }
  system("perl ../tools/time.pl");
  print("$msdev MoDIS.dsw /MAKE \"MoDIS - Win32 $modisDir\" /OUT ${MoDISLogDir}\\MoDIS.log\n");
  system("$msdev MoDIS.dsw /MAKE \"MoDIS - Win32 $modisDir\" /OUT ${MoDISLogDir}\\MoDIS.log");
  if (-e "MoDIS\\${modisDir}\\MoDIS.exe") {
    print("      ==> [P]\n");
  } else {
    print("      ==> [F]\n");
  }
}

sub MoDIS_auto_power_on_test{
  # MoDIS auto power on test
  #$ENV{"MoDIS"} = 'AutoPower';
  
  chomp(my $cwd = `cd`);
  my $is_in_lsf = ($ENV{"atMoDIS_LSF_remote"})?1:0;
  
  if ((-e "MoDIS\\${modisDir}\\MoDIS.exe") && ($ENV{"MoDIS"} eq 'AutoPower')) {
  	$MoDIS_poweron_result = 0;
  	$WIN32FS = "$cwd\\WIN32FS";
    
    # Backup/Recover WIN32FS
    if (-e "${WIN32FS}_BAK") {
      # Recover file system
      print ("\nrobocopy ${WIN32FS}_BAK $WIN32FS /MIR /R:3 /W:3 /LOG:robo_win32fs.log");
      system("robocopy ${WIN32FS}_BAK $WIN32FS /MIR /R:3 /W:3 /LOG:robo_win32fs.log");
    } else {
      # Backup file system
      print ("\nrobocopy $WIN32FS ${WIN32FS}_BAK /MIR /LOG:robo_win32fs.log");
      system("robocopy $WIN32FS ${WIN32FS}_BAK /MIR /LOG:robo_win32fs.log");
    }
    
    if (-e "_BUILD_LOG\\_PowerOn.log") {
  	  unlink("_BUILD_LOG\\_PowerOn.log");
    }
  	
    print "\n";
    system("perl ../tools/time.pl");
    print("MoDIS Auto PowerOn Test\n");
    chdir("MoDIS\\$modisDir");
    chomp($cwd = `cd`);
    if ($is_in_lsf) {
      system("call start MoDIS.exe");
    } else {
      Win32::Process::Create(  $MoDIS_Process,
                               "$cwd\\MoDIS.exe",
                               "MoDIS.exe",
                               0,
                               CREATE_NEW_CONSOLE,
                               $cwd) || assert(Win32::FormatMessage( Win32::GetLastError() ));
    }
    chdir("..\\..\\");

    sleep 60;
   	
    if (-e "_BUILD_LOG\\_PowerOn.log") {
      open MoDIS_AutoPower, "<_BUILD_LOG\\_PowerOn.log" or assert("\ncannot open mcu\\MoDIS\\_BUILD_LOG\\_PowerOn.log\n\n");
      $backup = $/;
      undef $/;
      $MoDIS_AutoPower_Result = <MoDIS_AutoPower>;
      $/ = $backup;
      close MoDIS_AutoPower;
			
      if ($MoDIS_AutoPower_Result =~ /(Auto Power ON Success)/i) {
        $MoDIS_poweron_result = 1;
        print("      ==> [P]\n\n");
      }
    }
		
    unless ($MoDIS_poweron_result) {
      if ($is_in_lsf) {
        # MoDIS auto poweron fail, kill its process
        $objWMI = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2');
        $colProcesses = $objWMI->InstancesOf('Win32_Process');
        foreach my $objProcess (in $colProcesses) {
            if ($objProcess->Name =~ /^(modis.exe)$/i) {
                $objName = $objProcess->Name;
                $objPID = $objProcess->ProcessID;
                $objWMIProcess = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2:Win32_Process.Handle=\'' . $objPID . '\'');
                if ($intRC = $objWMIProcess->Terminate()) {
                    print "Could not kill process \"$objName\" (PID=$objPID). Error code: " . $intRC, "\n";
                }
            }
        }
      } else {
      	$MoDIS_Process->Kill(STILL_ACTIVE);
      }
      print("      ==> [F]\n\n");
    }
  
  }
  # end of MoDIS auto power on test
}

sub at_MoDIS {
  
  unless ((-e "..\\mtk_tools\\Perl") && ($] >= 5.008006)){
  	assert("Perl package doesn't exist or Perl version is less then 5.008006. Your Perl version is $]\n");
  }
  
  # cwd = mcu\MoDIS
  chomp(my $cwd = `cd`);
  
  # Parsing the network path name
  if ($ENV{"atMoDIS_LSF_remote"}) {
  	$full_path = $ENV{"atMoDIS_LSF_remote"};
  } else {
    $device_name = substr($cwd, 0, 2);
    $path_name = substr($cwd, 2);
    @net_use_result = `net use $device_name 2>&1`;
    ($full_path) = ($net_use_result[1] =~ /\s+(\\\\.*)\s*$/);
    $full_path = ($full_path)?($full_path.$path_name):$cwd;
  }

  my $curr_usr       = lc(getlogin()) or assert("can't get your login name\n$!\n");
  my $computerName   = $ENV{"COMPUTERNAME"};
  my $notify_list    = "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini";
  my $NetSim         = "$cwd\\NetSim\\NetSim.exe";
  my $Catcher        = "$cwd\\Catcher\\Catcher.exe";
  my $MoDIS          = "$cwd\\MoDIS\\${modisDir}\\MoDIS.exe";
  my $MSC_log        = "$cwd\\Catcher\\report.csv";
  my $MSC_workspace  = "$cwd\\MSC_TestCase\\${custom}_${project}.msc";
  my $MoDIS_database = "$cwd\\..\\tst\\database_modis\\BPGUInfoCustomApp_pc";
  my $MoDIS_iniFILE  = "$cwd\\MoDIS\\${modisDir}\\MoDIS.ini";
  my $catcher_source = '';
  my $fail_case_pl   = "$cwd\\atMoDIS_add_fail_case.pl";
  my $fail_case_tcl  = "$cwd\\atMoDIS_add_fail_case.tcl";
  my $reset_MoDIS    = "$cwd\\atMoDIS_reset_MoDIS.pl";
  my $email_notify   = "$cwd\\atMoDIS_email_notify.pl";
  my $Catcher_init   = "$cwd\\Catcher\\Catcher_init.tcl";
  my $CustMenuTree   = "$cwd\\..\\plutommi\\Customer\\CustResource\\CustMenuTree_Out.c";
  
  $temp_cwd = $cwd;
  $MSC_workspace_full_path = $MSC_workspace;
  $temp_cwd =~ s/\\/\\\\/gi;
  $MSC_workspace_full_path =~ s/$temp_cwd/$full_path/i;
  
  #*----------------------------------------------------------------------------*
  #* Get Catcher source path                                                    *
  #*----------------------------------------------------------------------------*
  unless (-e $Catcher) {
    @catcher_srcs = qw(
      \\\\Mtkrd5fs1\\Public\\Public\\MTK_tool_release\\Catcher_Development
      \\\\glbfs14\\WCP\\MBJ\\tool_release\\Catcher
      \\\\glbfs14\\WCP\\MSZ\\tool_release\\Catcher
      \\\\glbfs14\\WCP\\PMT\\tool_release\\Catcher
    );

    foreach (@catcher_srcs) {
      next if (!-d $_);
      $catcher_source = $_;
      last;
    }

    assert("Could NOT find Catcher source\n") if ($catcher_source eq '');
  }
  #*----------------------------------------------------------------------------*
  #* End of Get Catcher source path                                             *
  #*----------------------------------------------------------------------------*

  assert("$NetSim not exist !!\n")         unless (-e $NetSim);
  assert("$MoDIS not exist !!\n")          unless (-e $MoDIS);
  assert("$MSC_workspace not exist !!\n")  unless (-e $MSC_workspace);
  assert("$MoDIS_database not exist !!\n") unless (-e $MoDIS_database);
  assert("$MoDIS_iniFILE not exist !!\n")  unless (-e $MoDIS_iniFILE);
  assert("$fail_case_pl not exist !!\n")   unless (-e $fail_case_pl);
  assert("$fail_case_tcl not exist !!\n")  unless (-e $fail_case_tcl);
  assert("$reset_MoDIS not exist !!\n")    unless (-e $reset_MoDIS);
  assert("$email_notify not exist !!\n")   unless (-e $email_notify);
  assert("$CustMenuTree not exist !!\n")   unless (-e $CustMenuTree);
  
  
  # Before MoDIS auto test, be sure MoDIS auto power on is success
  my $is_in_lsf = ($ENV{"atMoDIS_LSF_remote"})?1:0;
  if ((!$MoDIS_poweron_result) && (-e $MoDIS)) {
    $ENV{"MoDIS"} = 'AutoPower';
    &MoDIS_auto_power_on_test;
    $ENV{"MoDIS"} = 'Null';
  }
  

  # Start MoDIS auto test procedure
  if ($MoDIS_poweron_result) {
    #*----------------------------------------------------------------------------*
    #* Getting latest Catcher, if Catcher not exist
    #*----------------------------------------------------------------------------*
    unless (-e $Catcher) {
      my $catcher_ver = 0, $catcher_source_path = '';
      if (opendir(CATCHER_SOURCE, $catcher_source)) {
        foreach (sort readdir(CATCHER_SOURCE)) {
          if (/^\[(\d+)\.(\d+)\.(\d+)\]Catcher$/i) { # match [X.X.XX]Catcher
            # compare catcher version, to get the latest one
            if (("$1$2$3") > $catcher_ver) {
              $catcher_ver = "$1$2$3";
              $catcher_source_path = "$catcher_source\\$_"; # <= the latest catcher source path
            }
          }
        }
        closedir(CATCHER_SOURCE);
      } else {
        assert("Could not open $catcher_source !!\n");
      }
        
      # Mirror catcher source to local
      if (-e $catcher_source_path) {
        print ("\nGetting Catcher form ...\n$catcher_source_path");
        system("call robocopy $catcher_source_path " . dirname($Catcher) . " /MIR /LOG:robo_catcher.log");
        
        # add fail case handling content
        print ("\ncall perl $fail_case_pl $Catcher_init\n");
        system("call perl $fail_case_pl $Catcher_init");
      } else {
        assert("Unknow path : $catcher_source_path\n");
      }
    }
    #*----------------------------------------------------------------------------*
    #* End of Getting latest Catcher, if Catcher not exist
    #*----------------------------------------------------------------------------*


    #*----------------------------------------------------------------------------*
    #* Replace MoDIS.ini to support auto power on
    #*----------------------------------------------------------------------------*
    my $ini_flag   = 0;
    my $ini_output = '';
    open FILE, "<$MoDIS_iniFILE" or assert("\ncannot open $MoDIS_iniFILE\n\n");
    while (<FILE>)
    {
      $ini_flag  = 1 if (/^\s*\[AutoTest\]\s*/i);
      if ($ini_flag && /^\s*MoDIS\s*=\s*(\w+)\s*/i) # match MoDIS = XXXX
      {
        $ini_output .= "MoDIS = Reboot\n";
      }
      else
      {
        $ini_output .= $_;
      }
    }
    close FILE;
    
    if (!$ini_flag)
    {
    	$ini_output .= "[AutoTest]\nMoDIS = Reboot\n\n";
    }
    
    open OUTPUT_FILE, ">$MoDIS_iniFILE";
    print OUTPUT_FILE $ini_output;
    close OUTPUT_FILE;
    #*----------------------------------------------------------------------------*
    #* End of Replace MoDIS.ini to support auto power on
    #*----------------------------------------------------------------------------*
    
    print "\n";
    system("perl ../tools/time.pl");
    print("MoDIS Auto Test\n");
      
    if ($is_in_lsf) {
      # Start MoDIS
      chdir(dirname($MoDIS));
      system("start $MoDIS");
      
      # Start Catcher
      chdir(dirname($Catcher));
      system("start $Catcher \"$MoDIS_database\"");
      
      sleep 20;
      
      # Start NetSim
      chdir(dirname($NetSim));
      system("start $NetSim \"$MSC_workspace\" Modis \"" . dirname($MSC_workspace) . "\" $CustMenuTree");
      
      chdir($cwd);
    } else {
      # Start MoDIS
      Win32::Process::Create(  $MoDIS_Process,
                               $MoDIS,
                               "MoDIS.exe",
                               0,
                               CREATE_NEW_CONSOLE,
                               dirname($MoDIS)) || assert(Win32::FormatMessage( Win32::GetLastError() ));
                           
      # Start Catcher
      Win32::Process::Create(  $Catcher_Process,
                               $Catcher,
                               "Catcher.exe \"$MoDIS_database\"",
                               0,
                               CREATE_NEW_CONSOLE,
                               dirname($Catcher)) || assert(Win32::FormatMessage( Win32::GetLastError() ));
  
      # wait for MoDIS initial
      sleep 20;
  
      # Start NetSim
      Win32::Process::Create(  $NetSim_Process,
                               $NetSim,
                               "NetSim.exe \"$MSC_workspace\" Modis \"" . dirname($MSC_workspace) . "\" $CustMenuTree",
                               0,
                               CREATE_NEW_CONSOLE,
                               dirname($NetSim)) || assert(Win32::FormatMessage( Win32::GetLastError() ));
    }
  
    # Waiting for test case finish
    sleep 60;
    while(!(rename($MSC_log, "${MSC_log}.tmp"))) {
      sleep 30;
    }
    rename("${MSC_log}.tmp", $MSC_log);
    
    
    #/*************************************************************************
	# Parsing MSC report
	#*************************************************************************/
    # To transform every row into one line
    my $temp_csv = '';
    open CSV_FILE, "<$MSC_log" or assert("\ncannot open $MSC_log\n\n");
    while (<CSV_FILE>) {
  	  $line = $_;
  	  unless ($line =~ /\"\s$/i) {
  	    $line =~ s/\s$//i;
  	    chomp($line);
  	    $line .= '<br>';
  	  }
  	  $temp_csv .= $line;
    }
    close CSV_FILE;

    open TEMP_CSV, ">MSC_report.csv" or assert("\ncannot open MSC_report.csv\n\n");
    print TEMP_CSV $temp_csv;
    close TEMP_CSV;
    
    # Parse CSV file
    my $parser = Parse::CSV->new(
      file     => 'MSC_report.csv',
      csv_attr => {
        sep_char   => ',',
        quote_char => '"',
      },
    );
  
    my $is_fail = 0;
    my $html_output = '';
    while ( my $value = $parser->fetch ) {
      # @$value[0]: MSC
      # @$value[1]: PASS
      # @$value[2]: FAIL
      # @$value[3]: REASON
      unless(@$value[1]) {
      	$is_fail = 1;
      }
      if ((@$value[0] eq 'Total') && (@$value[3]) eq '') {
      	$is_fail = 0 if (@$value[2] == 0);
      }
      
      # Generating HTML format output
      @$value[0] = (@$value[0])?@$value[0]:'&nbsp;';
      @$value[1] = (@$value[1])?@$value[1]:'&nbsp;';
      @$value[2] = (@$value[2])?@$value[2]:'&nbsp;';
      @$value[3] = (@$value[3])?@$value[3]:'&nbsp;';
      $html_output .= "<TR><td class=my_td align=left>@$value[0]</td><td class=my_td width=80 align=center>@$value[1]</td><td class=my_td width=80 align=center>@$value[2]</td><td class=my_td width=100>@$value[3]</td></TR>\n";
    }
    
    undef $parser;
    unlink('MSC_report.csv');
    #/*************************************************************************
	# End of Parsing MSC report
	#*************************************************************************/


    #/*************************************************************************
	# Send MSC report
	#*************************************************************************/
    if (-e $notify_list) {
    	my %BM_conf = iniToHash($notify_list);
    	$email_list = $BM_conf{'atMoDIS'}->{'EMAIL_NOTIFY_LIST'} . ",$curr_usr";
    } else {
    	$email_list = $curr_usr;
    }
    
    MIME::Lite->send('smtp', 'mtksmtp2.mtk.com.tw', Timeout=>60);
    $msg = MIME::Lite->new(
      From     => $curr_usr,
      To       => $email_list,
      subject  => "[Script Notify][$custom] MoDIS auto test result - ".((($is_fail) || ($html_output eq ''))?'FAIL':'PASS'),
      Type     => 'multipart/related',
      Datestamp=> 0
    );
    $msg->attach(Type => 'text/html',
      Data => qq{
<FONT face=Verdana size=2>
<B>PROJECT:</B> $custom<br>
<B>MODEM:</B> $project<br>
<B>EXECUTION MACHINE:</B> $computerName<br>
<B>EXECUTION PATH:</B> $cwd<br>
<B>CODEBASE:</B> $full_path<br>
<B>MSC PATH:</B> $MSC_workspace_full_path<br>
</FONT>
<br>
<br>
        <style>
          .my_td
          {
            border: 1px solid #ddd;
            vertical-align: middle;
            font-family: Verdana;
            font-size: 12px;
          }
        </style>
        <table style="border: 1px solid #ddd;">
          $html_output
        </table>
      }
    );
    $msg->send();
    
    print ((($is_fail) || ($html_output eq ''))?"      ==> [F]\n\n":"      ==> [P]\n\n");
	#/*************************************************************************
	# End of Send MSC report
	#*************************************************************************/
	
	
	#/*************************************************************************
	# Terminate processes
	#*************************************************************************/
	unless (($is_fail) || ($html_output eq '') || $is_in_lsf) {
      $MoDIS_Process->Kill(STILL_ACTIVE);
      $Catcher_Process->Kill(STILL_ACTIVE);
      $NetSim_Process->Kill(STILL_ACTIVE);
	}
    
    if ($is_in_lsf) {
      $objWMI = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2');
      $colProcesses = $objWMI->InstancesOf('Win32_Process');
      foreach my $objProcess (in $colProcesses) {
          if ($objProcess->Name =~ /^(modis.exe|catcher.exe|netsim.exe)$/i) {
            $objName = $objProcess->Name;
            $objPID = $objProcess->ProcessID;
            $objWMIProcess = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2:Win32_Process.Handle=\'' . $objPID . '\'');
            if ($intRC = $objWMIProcess->Terminate()) {
                print "Could not kill process \"$objName\" (PID=$objPID). Error code: " . $intRC, "\n";
            }
        }
      }
    }
    
    # Backup/Recover WIN32FS
    if (-e "${WIN32FS}_BAK") {
      # Recover file system
      print ("\nrobocopy ${WIN32FS}_BAK $WIN32FS /MIR /R:3 /W:3 /LOG:robo_win32fs.log");
      system("robocopy ${WIN32FS}_BAK $WIN32FS /MIR /R:3 /W:3 /LOG:robo_win32fs.log");
    }
    #/*************************************************************************
	# End of Terminate processes
	#*************************************************************************/
	
	
  } else {
    print "\nMoDIS auto power on fail, stop MoDIS auto test procedure !!\n\n";
    exit;
  }
}

sub assert {
    if ($ENV{"atMoDIS_LSF_remote"})
    {
        $objWMI = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2');
        $colProcesses = $objWMI->InstancesOf('Win32_Process');
        foreach my $objProcess (in $colProcesses) {
            if ($objProcess->Name =~ /^(modis.exe|catcher.exe|netsim.exe)$/i) {
                $objName = $objProcess->Name;
                $objPID = $objProcess->ProcessID;
                $objWMIProcess = Win32::OLE->GetObject('winmgmts:\\\\.\\root\\cimv2:Win32_Process.Handle=\'' . $objPID . '\'');
                if ($intRC = $objWMIProcess->Terminate()) {
                    print "Could not kill process \"$objName\" (PID=$objPID). Error code: " . $intRC, "\n";
                }
            }
        }
    }
    
    # Backup/Recover WIN32FS
    if (-e "${WIN32FS}_BAK") {
      # Recover file system
      print ("\nrobocopy ${WIN32FS}_BAK $WIN32FS /MIR /R:3 /W:3 /LOG:robo_win32fs.log");
      system("robocopy ${WIN32FS}_BAK $WIN32FS /MIR /R:3 /W:3 /LOG:robo_win32fs.log");
    }
    
    print $_[0];
    exit;
}

#usage:
#      my %hash=iniToHash('/tmp/myini.ini');
#      print $hash{'TITLE'}->{'Name'},"\n";
#
sub iniToHash{
    open(MYINI, $_[0]);
    my %hash;
    my $hashref;
    
    while(<MYINI>)
    {
        next if ((/^\s*$/) || (/^\s*#/));
        if (/^\s*\[(.+)\]/)
        {
            $hashref = $hash{$1} ||= {};
        }
        elsif (/^\s*(\S+)\s*=\s*(.+)\s*$/)
        {
            $hashref->{$1} = $2;
        }
        elsif (/^\s*(\S+)\s*\+=\s*(.+)\s*$/)
        {
        	$hashref->{$1} = $hashref->{$1} . " $2";
        }
    }
    
    close MYINI;
    return %hash;
}

sub chdirMoDIS {
  die "MoDIS directory does NOT exist!\n" if (!-d "MoDIS");
  chdir("MoDIS");
  print("\nChange Working Directory to MoDIS\n");
}

sub chdirToMcu {
  chdir("..");
}


sub CurrTimeStr {
  my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
  return (sprintf "%4.4d/%2.2d/%2.2d %2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min);
}

sub Usage {

  warn << "__END_OF_USAGE";

Usage:
  make ["customer"|"mt62xx"] "project" "action" ["modules"]

Description:
  customer   = mtk             (Default customer)
             = firefly17_demo  (FIREFLY17_DEMO project)
             = [mt6217|mt6219|mt6226|mt6227|mt6228|mt6229] (EVB only)
             = ...

  project    = l1s             (Layer 1 stand-alone)
             = gsm             (GSM only)
             = gprs            (GPRS only)
             = umts            (GPRS+UMTS)
             = basic           (Basic Framework)

  action     = new             (codegen, resgen, clean, update) (default)
             = update or u     (scan, compile, link)
             = remake or r     (compile, link)
             = clean or c      (clean)
             = resgen          (resgen)
             = c,u             (clean then update)
             = c,r             (clean then remake)
             = codegen         (codegen)
             = viewlog         (open edit to view build log)
             = emigen          (emigen)
             = emiclean        (emiclean)

  module(s)  = modules' name   (kal, l1, ...)
   => OPTIONAL when action is one of (clean c remake r update u c,r c,u)

Example:
  make gsm new                         (MT6205B EVB new)
  make gprs codegen                    (MT6218B EVB codegen)
  make mt6219 gprs update              (MT6219 EVB update)
  make firefly17_demo gprs new
  make milan_demo gprs c,u init custom
  make mt6219 gprs r init custom drv
__END_OF_USAGE

  exit 1;
}

sub writeINI {
  @iniFields = qw(plat custom project);
 
  if ($plat eq "NONE") {$plat = ""; }
  if ($enINI == 1) {
    open (FILE_HANDLE, ">$ini") or die "cannot open $ini\n";
    foreach $m (@iniFields) {
      $value = $${m};
      print FILE_HANDLE "$m = $value\n";
    }
    close FILE_HANDLE;
  }
}

