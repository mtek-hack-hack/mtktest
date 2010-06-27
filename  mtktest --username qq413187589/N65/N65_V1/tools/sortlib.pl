#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2007
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
#
# Filename: 
# ---------
#  sortLib.pl
#
# Description: 
# ------------
#  To sort libraries in ~libs.tmp file before linking(armlink.exe).
#
# Auther: 
# -------
#  Frank Wu
# 
# Note:
# -----
#  none.
#
# Log: 
# -----
#  2007/04/25   Create.
#
# Usage:
# -----
# sortib.pl make\~libs.tmp $(strip $(COMPOBJS))
open(lib,"$ARGV[0]") || die "Cannot open $ARGV[0]: $!";
open(sortlib,">make\\~sortedLibs.tmp") || die "Cannot open make\\~sortedLibs.tmp: $!";
my $i = 0;
my $j = 0;
my %path = "";
my @file = "";
my @specialFile = "";
while(<lib>){
	if($i > 0){
		if($_ =~ /(.+)\\(.+lib)[\s]/){
			if(index($_, $ARGV[1]) >= 0){
				$specialFile[$i] = $_;
			} else {
				$path{$2} = $1; 
				$file[$i] = $2;
			}
		} else {
			$specialFile[$i] = $_;
		}
	} else {
		print sortlib $_;
	}
	$i++;
}
close(lib);

my @sortedLibs = sort @file;
foreach $item(@sortedLibs){
	if(length($specialFile[$j]) > 0){
		chomp($specialFile[$j]);
		print sortlib "$specialFile[$j]\n";
	} 
	if(length($item) > 0){
		print sortlib "$path{$item}\\$item\n";
	}
	$j++;
}
while($j <= $#specialFile){
	if(length($specialFile[$j]) > 0){
		chomp($specialFile[$j]);
		print sortlib "$specialFile[$j]\n";
	}
	$j++;
}
close(sortlib);

#To confirm ~libs.tmp and ~sortedLibs.tmp have the same line numbers.
open(lib,"$ARGV[0]") || die "Cannot open $ARGV[0]: $!";
my $originalLine = 0;
while(<lib>){
	$originalLine++;
}
close(lib);

open(sortlib,"make\\~sortedLibs.tmp") || die "Cannot open make\\~sortedLibs.tmp: $!";
my $sortedLine = 0;
while(<sortlib>){
	$sortedLine++;
}
close(sortlib);

if($originalLine!=$sortedLine){
	print "The library may be lost after sorting libraries. Please compare $ARGV[0] and make\\~sortedLibs.tmp.";
	exit(1);
}
