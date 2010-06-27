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
&Usage if ($#ARGV == -1);
if ($ARGV[0] eq "-rm") {
  $cphdr = 0;
} elsif ($ARGV[0] eq "-cp") {
  $cphdr = 1;
} else {
  Usage();
}

@mapDirs = (
 [ qw(MinGW_Slim tools\MinGW) ],
 [ qw(msys_Slim\1.0 tools\MSYS) ],
);

@mapFiles = (
 [ qw(Scripts\clean_obj.pl tools clean_obj.pl) ],
 [ qw(MinGW\bin\mingw32-make.exe tools make.exe) ],
 [ qw(7-Zip_Slim\7za.exe lcmmi\Customer\ResGenerator 7za.exe) ],
 [ qw(7-Zip_Slim\7za.exe plutommi\Customer\ResGenerator 7za.exe) ],
 [ qw(7-Zip_Slim\convert.exe lcmmi\Customer\ResGenerator convert.exe) ],
 [ qw(7-Zip_Slim\convert.exe plutommi\Customer\ResGenerator convert.exe) ],
);

@srcs = qw(
\\\\szfs3\\MAUI_load\\3rd_party
\\\\mbjfs01\\public\\WCPRD\\SW_Releases\\3rd_party
\\\\mtisfs02\\Public\\SW_Releases\\3rd_party
\\\\glbfs14\\WCP\\sw_releases\\3rd_party
\\\\mediatek.inc\\Taiwan\\WCP\\Public\\Public\\3rd_party
\\\\mtkrfs01\\Public1\\3rd_party
);

$src = "";
foreach $d (@srcs) {
  next if (!-d $d);
  $src = $d;
  last;
}

die "Could NOT find thiry parties source\n" if (($cphdr==1) && ($src eq ""));

for $i (0 .. $#mapDirs) {
  if ($cphdr==1) {
    print("Copy folder ${src}\\$mapDirs[$i][0] to $mapDirs[$i][1]\n");
    system("mkdir $mapDirs[$i][1]") if (!-d $mapDirs[$i][1]);
    system("xcopy /Y /Q /S ${src}\\$mapDirs[$i][0] $mapDirs[$i][1]");
  } elsif (-d $mapDirs[$i][1]) { 
    print("Remove directory: $mapDirs[$i][1]\n");
    system("rd /s /q $mapDirs[$i][1]");
  }
}

for $i (0 .. $#mapFiles) {
  if ($cphdr==1) {
    if (-d $mapFiles[$i][1]) {
      print("Copy file ${src}\\$mapFiles[$i][0] to $mapFiles[$i][1]\\$mapFiles[$i][2]\n");
      system("copy /Y ${src}\\$mapFiles[$i][0] $mapFiles[$i][1]\\$mapFiles[$i][2] > nul 2>&1");
    }
  } elsif (-e "$mapFiles[$i][1]\\$mapFiles[$i][2]") {
    print("Remove file: $mapFiles[$i][1]\\$mapFiles[$i][2]\n");
    system("del /f /q $mapFiles[$i][1]\\$mapFiles[$i][2]");
  }
}

exit 0;

sub Usage {
  print <<"__EOFUSAGE";
Usage: $0 [-rm | -cp]
       -rm       Remove third parties files
       -cp       Copy third parties files
__EOFUSAGE
  exit 1;
}
