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
#!/usr/bin/perl
# filter out the lines having RCS Log

# Log Area Turn on Criteria:
# 1. match $log_turnon in one line and match "^ \*-{75}" in the next line, log area begin from the next line
$log_turnon     = " \* Below this line, this part is controlled by PVCS VM\. DO NOT MODIFY!!";
# 2. match " * $Revision: ... $", " * $Modtime: ... $" or " * $Log: ... $", log area begin from this line

# Log Area Turn on Criteria:
# 1. match $log_turnoff and log area is before this line
$log_turnoff    = " \* Upper this line, this part is controlled by PVCS VM\. DO NOT MODIFY!!";
# 2. match "^ \*-{75}" and $log_turnon is not in previous line
# 3. match "^ \*{15}\*+\/" and $log_turnon is not in previous line

$author_turnon  = " \* Author:";

#
# parsing command arguments
#

my $line_no;
$debug_print = 0; # 1 for debug; 0 for non-debug

if (!($ARGV[0] =~ /\.(h|c|hpp|cpp)$/i))
{
	if  (!(index(lc($ARGV[0]),"scat") > 0 && index(lc($ARGV[0]),"txt") > 0)) {
  	&usage;
  }
}

#
# open source file & result file
#
$SRC_FILE = $ARGV[0];
$is_exist = 0;
$is_exist = 1 if -e $SRC_FILE;
if ($is_exist == 1)
{
    open SRC_FILE_R , "<$SRC_FILE" or die "cannot open $SRC_FILE\n";
}
else
{
    exit(0);
}

#
# search the RCS $Log & remove them
#
$is_log_area = -1;      # -1: not in a log area
                        #  0: possibly the beginning of the area
                        #  1: in a log area

$is_author_area = -1;   # -1: not in a author area
                        #  0: possibly the beginning of the area
                        #  1: in a author area
$line_no = 1;

undef $/;
my $reading = <SRC_FILE_R>;

close SRC_FILE_R;
system "del $SRC_FILE" if ($reading !~ /\[MAUI_\d{8}\]/);

# show usage
sub usage
{
	print "USAGE: perl emidel.pl <source file>\n";
	exit(0);
}
