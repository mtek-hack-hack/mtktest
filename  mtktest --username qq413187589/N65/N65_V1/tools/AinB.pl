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
#*   lnitem.pl
#*
#* Project:
#* --------
#*   Maui_Software
#*
#* Description:
#* ------------
#*   This script will list all lines in A file which also appear in B file
#*
#* Author:
#* -------
#*   Sherman Wang  (mtk00590)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision:   1.1  $
#* $Modtime:   Jun 20 2005 18:37:52  $
#* $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/tools/AinB.pl-arc  $
 #
 #   Rev 1.1   Jun 20 2005 18:39:24   BM
 #Karlos:
 #add copyright and disclaimer
 #
 #   Rev 1.0   Sep 12 2004 17:01:10   BM
 #Initial revision.
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
my $DebugPrint    = 0; # 1 for debug; 0 for non-debug

#****************************************************************************
# show usage
#****************************************************************************
sub usage
{
	print "USAGE: perl AinB.pl <filename of A> <filename of B>\n";
	exit(0);
}

#
# open a file & b file
#

my $A_FLIE = $ARGV[0];
open A_FLIE,"<$A_FLIE" or usage();
my $B_FLIE = $ARGV[1];
open B_FLIE,"<$B_FLIE" or usage();

#print "$A_FLIE and $B_FLIE are OPENED\n";

#
# read b file & add a leading & tailing space for easy comparason
#
my $backup= $/;
undef $/;
my $reading = <B_FLIE>;
$reading =~ s/\s+/ /g;
$reading = ' ' . $reading . ' ';
$/ = $backup;
close B_FLIE;
#print "$reading\n";

#
# read a file & match each line in A file to B file
#

my %non_duplicated = ();
$reading =~ s/\\/-/g; # because ($reading =~ / $line /i) doesn't work if $line contain '\'

while (<A_FLIE>)
{
   my $line = $_;
   $line =~ s/^\s+//;
   $line =~ s/\s+$//;

#   print "[$line]\n";

   $line =~ s/\\/-/g; # because ($reading =~ / $line /i) doesn't work if $line contain '\'
   if ($reading =~ / $line /i)
   {
      my $lower_line = $_;
      $lower_line =~ tr/A-Z/a-z/;

      unless ( exists($non_duplicated{$lower_line}) )
      {
         print "$_";
         $non_duplicated{$lower_line} = 1;
      }
   }
}
close A_FLIE;