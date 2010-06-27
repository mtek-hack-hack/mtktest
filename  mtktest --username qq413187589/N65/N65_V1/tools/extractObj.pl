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
$custom = "Dragonfly_Demo";
$proj = "gprs"; # gprs or gsm
@objs = ();#qw(custom_wap_cust_pack.obj nvram_cust_pack.obj);
$outputdir = "C:\\CustPack\\BIN";
$dboutputdir = "C:\\CustPack";
$extractObjExe = "ExtractObj.exe";

$ini_file = "ExtractObj.ini";
if (!-e $ini_file) {
  die "$ini_file OR tools\\$ini_file did NOT exist!\n" if (!-e "tools\\$ini_file");
  $ini_file = "tools\\$ini_file";
}

open INI_FILE, "<$ini_file" or die "cannot open $ini_file\n";

while (<INI_FILE>) {
  if (/^\s*CUSTOM\s*=\s*\"(\S+)\"\s/) {
    $custom = $1;
  } elsif (/^\s*PROJECT\s*=\s*\"(\S+)\"\s/) {
    $proj = $1;
  } elsif (/^\s*OBJ\d+\s*=\s*\"(\S+)\"\s/) {
    push(@objs, $1);
  } elsif (/^\s*OUTPUTDIR\s*=\s*\"(\S+)\"\s/) {
    $dboutputdir = $1;
  }
}
close INI_FILE;

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /-h/) {
    Usage();
  } elsif ($ARGV[0] =~ /^custom=(\w+)/) {
    $custom = $1;
  } elsif ($ARGV[0] =~ /(gprs|gsm|umts)/i) {
    $proj = $ARGV[0];
  } elsif ($ARGV[0] =~ /^objs=(\S+)/) {
    @objs = split(',', $1);
  } else {
    Usage();
  }
  shift(@ARGV);
}

$fromelf = "fromelf";
$builddir = "build\\${custom}\\${proj}";

$makefolder = "make";
if (!-d $makefolder) {
  die "$makefolder OR ..\\$makefolder did NOT exist!\n" if (!-d "..\\$makefolder");
  $makefolder = "..\\$makefolder";
}
$custombld = "${makefolder}\\custom.bld";
die "$custombld did NOT exist!\n" if (!-e $custombld);
open (FILE_HANDLE, "<$custombld") or die "cannot open $custombld\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $custombld!\n";
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;

if ($custom_release eq "TRUE") {
  $dbfileprefix = "BPLGUInfoCustomSrcP_MT62";
} else {
  $dbfileprefix = "BPLGUInfoCustom_MT62";
}

system("rd /s /q $outputdir") if (-d $outputdir);
system("rd /s /q $dboutputdir") if (-d $dboutputdir);
system("md $dboutputdir") if (!-d $dboutputdir);
system("md $outputdir") if (!-d $outputdir);
if (!-d $builddir) {
  die "$builddir OR ..\\$builddir did NOT exist!\n" if (!-d "..\\$builddir");
  $builddir = "..\\$builddir";
}

$not_found_flag = 0;
foreach $chkobj (@objs) {
  if (!-e $chkobj) { $not_found_flag = 1; last; }
  else { $found{$chkobj} = $chkobj; }
}

if ($not_found_flag == 0) { goto DEAL_OBJ; }

if (opendir(OBJDIRS, $builddir)) {
  @syndirs = sort readdir(OBJDIRS);
  closedir(OBJDIRS);
  shift(@syndirs); shift(@syndirs); ## . and ..
} else {
  die "Could not open $builddir";
}

CHIP_DIR: foreach $tarDir (@syndirs) {
  next if ($tarDir !~ m/o$/);
  $tarDir = "$builddir\\$tarDir";
  if (opendir(OBJDIRS, $tarDir)) {
    @moduledirs = sort readdir(OBJDIRS);
    closedir(OBJDIRS);
    shift(@moduledirs); shift(@moduledirs); ## . and ..
  } else {
    warn "Could not open $tarDir\n";
    next;
  }

  foreach $chkobj (@objs) { undef($found{$chkobj}); }

  CHIP_OBJ:  foreach $m (@moduledirs) {
    next if ($m eq "lib");
    $tarDir2 = "$tarDir\\$m";
    if (opendir(OBJDIRS, $tarDir2)) {
      @objfiles = sort readdir(OBJDIRS);
      closedir(OBJDIRS);
      shift(@objfiles); shift(@objfiles); ## . and ..
    } else {
      warn "Could not open $tarDir2\n";
      next;
    }
    foreach $objfile (@objfiles) {
      foreach $chkobj (@objs) {
        next if (defined($found{$chkobj}));
        next if ($objfile ne $chkobj);
        $found{$chkobj} = "$tarDir2\\$chkobj";
      }
    }
    foreach $chkobj (@objs) { next CHIP_OBJ if (!defined($found{$chkobj}));}
    print "Found all obj files @ $tarDir\n";
    last CHIP_DIR;
  }
}

DEAL_OBJ:
$allObjs = "";
foreach $chkobj (@objs) { 
  $chktxt = $found{$chkobj};
  $allObjs .= " $chktxt";
  $chktxt =~ s/\.obj/\.txt/;
  system("del /f /q $chktxt") if (-e $chktxt);
  print("$fromelf -text -v -s $found{$chkobj} > $chktxt\n");
  system("$fromelf -text -v -s $found{$chkobj} > $chktxt");
}

if (!-e $extractObjExe) {
  die "$extractObjExe OR tools\\$extractObjExe did NOT exist!\n" if (!-e "tools\\$extractObjExe");
  $extractObjExe = "tools\\$extractObjExe";
}
print("$extractObjExe $outputdir $allObjs\n");
system("$extractObjExe $outputdir $allObjs");

if ($proj =~ /gprs/i) {
  $dbfolder = "tst\\database_classb";
} elsif ($proj =~ /umts/i) {
  $dbfolder = "tst\\database_classb_umts";
} elsif ($proj =~ /gsm/i) {
  $dbfolder = "tst\\database";
}

if (!-d $dbfolder) {
  die "$dbfolder OR ..\\$dbfolder did NOT exist!\n" if (!-d "..\\$dbfolder");
  $dbfolder = "..\\$dbfolder";
}
print("$extractObjExe $outputdir $allObjs\n");
if (opendir(OBJDIRS, $dbfolder)) {
  @dbfiles= sort readdir(OBJDIRS);
  closedir(OBJDIRS);
  shift(@dbfiles); shift(@dbfiles); ## . and ..
} else {
  die "Could not open $dbfolder\n";
}
foreach $dbfile (@dbfiles) { 
  next if ($dbfile !~ /$dbfileprefix/);
  system("copy /Y ${dbfolder}\\$dbfile ${dboutputdir}\\$dbfile");
}

exit 0;

sub Usage {
  print <<"__EOFUSAGE";
Usage: $0 [-h | custom=\$custom | (gprs|gsm) | [objs=a.obj,b.obj]]
        -h       Help.
__EOFUSAGE
  exit 0;
}
