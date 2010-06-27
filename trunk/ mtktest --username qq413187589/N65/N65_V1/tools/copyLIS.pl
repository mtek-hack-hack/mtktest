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
# find out required .(hpp|h|dat|c|hex) for the header sources listed in .lis and in .dep

# show usage
sub usage
{
	print "USAGE: perl copyLIS.pl <filename of .lis> <release dir> <MMI DIR> <MMI_VERSION>\n";
	exit(0);
}

#
# parsing command arguments
#

my $LIS_FILE;
my $REL_DIR;
my $reading;

if (!($ARGV[0] =~ /\.lis$/))
{
   usage();
}

#
# open .lis & .dep
#

$LIS_FILE = $ARGV[0];
$REL_DIR = $ARGV[1];
$MMI_DIR = $ARGV[2];
$MMI_VERSION = $ARGV[3];

if ($ARGV[0] =~ /.+\\(.*)\\(.*)\\(.+).lis/) {
	$path = $1;
	$module = $3;
} else {
	die "Cannot get module name.";
}
#print "path = $path\n";
#print "$module\n";
#print "$REL_DIR\\make\\$path\\$module\n";
$path = lc($path);

if(!-e "$REL_DIR\\make\\$path\\$module"){
	system("md $REL_DIR\\make\\$path\\$module");
}

if ($module =~ /$MMI_DIR/i){
	#print "enter 1\n";
	system("copy /z make\\$path\\$module\\$module.* $REL_DIR\\make\\$path\\$module\\.");
	system("xcopy /e /y make\\$path\\$module\\$MMI_VERSION $REL_DIR\\make\\$path\\$module\\$MMI_VERSION\\*.*");
	if(length($path) > 0){
		print "$path\n";
		system("copy /z make\\$path\\* $REL_DIR\\make\\$path\\.");
	}
} else {
	#print "enter 2\n";
	system("xcopy /e /y make\\$path\\$module $REL_DIR\\make\\$path\\$module\\*.*");
	if(length($path) > 0){
		print "$path\n";
		system("copy /z make\\$path\\* $REL_DIR\\make\\$path\\.");
	}
}
