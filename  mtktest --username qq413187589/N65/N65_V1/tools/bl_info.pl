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

my $lisfile="make\\bootloader\\bootloader.lis";
my $pthfile="make\\bootloader\\bootloader.pth";

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /^board_ver=(\w+)/i) {
    $board_ver = $1;
  } else {
    &Usage;
  }
  shift(@ARGV);
}

(!defined($board_ver) || ($board_ver eq "") || (!-d ".\\custom\\system\\${board_ver}")) && &Usage;

open (file,"+<$lisfile") || die "cannot open $lisfile\n";   
truncate file, 0;

my $reading = "";

# System
my $thatdir = "bootloader\\src";
opendir THATDIR, $thatdir;
@allfiles = grep -T, map "$thatdir/$_", readdir THATDIR;
closedir THATDIR;

foreach $elem (@allfiles) {
	$elem =~ s/\//\\/g;
	if ($elem =~ m/[a-zA-Z0-9_\.\\\/]*\.[csCS]$/) {	
     $reading .= "$elem\n";
   }
}

$reading .= "custom\\system\\${board_ver}\\custom_emi.c\n";

seek(file, 0, 0);
print file $reading;
close file;
     
open (file,"+<$pthfile") || die "cannot open $pthfile\n";   
truncate file, 0;
$reading = "custom\\system\\$board_ver\nbootloader\\src\n";
seek(file, 0, 0);
print file $reading;
close file;

exit 0;

sub Usage {
  warn " Usage:\n";
  warn "     $0 board_ver=MT6226_EVB\n";
  exit 1;
}
