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
#  operator_check.pl
#
# Description: 
# ------------
#  To call operator_feature_check.pl to pre-process operator header files for
#  generating warning messages when customer macros were modified by operator
#  header files.
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
#  2007/04/01   Create.
#
#use strict;
use Fcntl;
use File::Basename;

#Open operator_checklist.txt
open(optr_check,"$ARGV[2]") || die "Cannot open $ARGV[2]. Error:$!";

my $CUSTOMER = $ARGV[0];
my $PROJECT = $ARGV[1];
my $theMF = "make\\$CUSTOMER\_$PROJECT.mak";
my $CC = "$ARGV[3]";
my $VIA = "$ARGV[4]";
my $operator_path = "";
my $DoCheck = 0;
my $flag = 0;
my $operator_macro = "";
my @logname = ();
my @macroname = ();
my $logs = "";
my $macro = "";
my @extlist = qw(.log);
my $base = "";
my $MMI_switch_path = "";

# remove temp file or not
my $removeTempFile = 1;

open (FILE_HANDLE, "<$theMF") or die "Cannot open $theMF\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    my $keyname = lc($1);
    defined($${keyname});
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;

$ARGV[2] =~ /(.+)operator_checklist/;
my $operator_path = $1;

$operator_path =~ /.+\\.+\\(.+?)\\(.+?)\\.+/;
my $operator_name = uc($1);
my $spec_version = $2;

if (-e "$operator_path\\operator_check.log"){
	system("del /F /Q $operator_path\\operator_check.log");
}
sysopen(log_file,"$operator_path\\operator_check.log",O_CREAT|O_RDWR|O_APPEND) || die "Error:$!";
print log_file "[Messages from operator header files]\n";
while(<optr_check>){
	if (index($_,"OPERATOR RELATED FILES")>=0 || index($_,"OPERATOR MACRO")>=0){
		next;
	}
	$_ =~ s/{BOARD_VER}/$board_ver/;
	$DoCheck = $_ =~ /(.+?)[\s]+(.+?)[\s]+(.+)/;
	if ($DoCheck){
			if(index($2,"MMI_features_switch")>=0){
				$MMI_switch_path = "$1\\$2";
			} elsif (index($2,"MMI_features.h")>=0) {
				$MMI_switch_path = "$1\\$2";
				$MMI_switch_path =~ s/.h/_switch.h/;
			}
			my $dummyHeaderFile = splitFilename($3, 0)."_dummy".".h";
			CreateDummyHeaderFile($3, $dummyHeaderFile, $operator_path, $1, $2, 1);
			CreateDummyHeaderFile($3, "original_".$dummyHeaderFile, $operator_path, $1, $2, 0);
			system("perl .\\tools\\operator_feature_check.pl $CUSTOMER . $dummyHeaderFile $3 $1 $operator_path 1 $CC $VIA");
			system("perl .\\tools\\operator_feature_check.pl $CUSTOMER . original_$dummyHeaderFile $3 $1 $operator_path 0 $CC $VIA");
			push @logname, "$operator_path\\".splitFilename($3, 0)."_dummy"."_$CUSTOMER".".log";
			if ($removeTempFile)
			{
    		system("del /F /Q $operator_path\\*_dummy.h");
    	}
	} elsif ($_ =~ /([\w]+?)[\s]?/) {
		$operator_macro = $_;
		chomp($operator_macro);
		push @macroname, $operator_macro;
	}
}
close(optr_check);


#*******************************************************************
# Start to parse the log files.
#*******************************************************************

foreach $logs (@logname){
	open(read_log,"$logs") || die "Cannot open $longs. Error:$!";	
	$base = basename($logs, @extlist);
	$base =~ s/_dummy_$CUSTOMER/.h/;
	while(<read_log>){
		$line = $_;
		chomp($line);
		$line =~ /([\w]+)\'s/;
		my $macro = $1;
		my $originalValue = getValue($macro, $base, 0);
		my $resultValue = getValue($macro, $base, 1);
		
		if ($originalValue eq ""){
			$originalValue = "Undefined or NULL";
		} elsif ($resultValue eq "") {
			$resultValue = "Undefined or NULL";
		}
		
		#To get __ON__, __OFF__ and __DEFAULT__ definitions from MMI_features_switch.h
		if ($base eq "operator_mmi.h") {
			open(mmi_switch,"$MMI_switch_path") || die "Cannot open $MMI_switch_path. Error:$!\n";
			while(<mmi_switch>){
				$_ =~ /^([\s]*)(#define[\s]+)([\w_]+)([\s]*)(.+)/;
				if($3 eq "__ON__"){
					if (index("\($originalValue\)",$5)>=0){
						$originalValue = "__ON__";
					} elsif (index("\($resultValue\)",$5)>=0) {
						$resultValue = "__ON__";
					}
				} elsif ($3 eq "__OFF__") {
					if (index("\($originalValue\)",$5)>=0){
						$originalValue = "__OFF__";
					} elsif (index("\($resultValue\)",$5)>=0) {
						$resultValue = "__OFF__";
					}
				} elsif ($3 eq "__DEFAULT__") {
					if (index("\($originalValue\)",$5)>=0){
						$originalValue = "__DEFAULT__";
					} elsif (index("\($resultValue\)",$5)>=0) {
						$resultValue = "__DEFAULT__";
					}
				} elsif ($3 eq "__AUTO__") {
					if (index("\($originalValue\)",$5)>=0){
						$originalValue = "__AUTO__";
					} elsif (index("\($resultValue\)",$5)>=0) {
						$resultValue = "__AUTO__";
					}
				}
			}
			close(mmi_switch);
		}

		print log_file ($line," from \"",$originalValue,"\" to \"",$resultValue,"\" according to"," $operator_name"," Specification Version ","$spec_version"," by File"," \"$base\"",".\n");
	}
	close(read_log);
}
print log_file "\n";
close(log_file);
#*******************************************************************
#To merge makefile warning messages from make\~warning.tmp
#*******************************************************************
if(-e "make\\\~warning.tmp"){
	system("echo [Messages from operator.mak]>>$operator_path\\operator_check.log");
	system("type make\\\~warning.tmp >>$operator_path\\operator_check.log");
}

print "\nPlease check the Operator Log: $operator_path\\operator_check.log\n";

if ($removeTempFile)
{
    system("del /F /Q $operator_path\\*_dummy_$CUSTOMER.log");
    system("del /F /Q .\\*_OriginalValue.log");
    system("del /F /Q .\\*_ResultValue.log");
}

#*******************************************************************
sub splitFilename()
{
    my $filename;
    my $refSubFilename = "";
    my $mainFilename = "";
    
    ($filename, $refSubFilename) = @_;
    
    if ($filename =~ /([^\s]*)(\.)([^\.]*$)/)
    {
        $mainFilename = "$1";
        if ($refSubFilename != 0)
        {
            $$refSubFilename = "$3";
        }
    }
    return $mainFilename;
}

sub CreateDummyHeaderFile()
{
	my $operatorHeaderFile;
	my $outputFile = "";
	my $operatorPath = "";
	my $filePath = "";
	my $customerHeaderFile = "";
	my $IfCreateOpMacro;
	
	($operatorHeaderFile, $outputFile, $operatorPath, $filePath, $customerHeaderFile, $IfCreateOpMacro) = @_;
	
	open(readfile,"$operatorPath\\$operatorHeaderFile") || die "Cannot open $operatorPath\\$operatorHeaderFile. Error:$!";
	if (-e "$operatorPath\\$outputFile"){
		system("del $operatorPath\\$outputFile");
	}
	sysopen(writefile,"$operatorPath\\$outputFile",O_CREAT|O_RDWR|O_APPEND) || die "Error:$!";

	if ($IfCreateOpMacro){
		print writefile "#include \"$customerHeaderFile\"";
	  print writefile "\n";	
		while(<readfile>){
			print writefile $_;
		}
		close(writefile);
		close(readfile);
	} else {
		open(readCustH,"$filePath\\$customerHeaderFile") || die "Cannot open $filePath\\$customerHeaderFile. Error:$!";
		$customerHeaderFile =~ /(.+?)[\.h]/;
		my $dummyCustomerHeaderFile = $1."_dummy.h";

		open(writeCustDummyH,">$operatorPath\\$dummyCustomerHeaderFile") || die "Error:$!";
		while(<readCustH>){
			if(index($_,"$operatorHeaderFile")>=0){
				print writeCustDummyH "";
			} else {
				print writeCustDummyH $_;
			}
		}
		close(writeCustDummyH);
		close(readCustH);
		
		print writefile "#include \"$dummyCustomerHeaderFile\"";
	  print writefile "\n";	
	  
		while(<readfile>){
			if ($_ =~ /^([\s]*)(#define[\s]+)([\w_]+)([\s]*)/){
				print writefile "//{",$3,"}","\n";
			}
		}
		close(writefile);
		close(readfile);
	}	
}

sub getValue() {
	my $macroN = "";
	my $OpHeadF = "";
	my $IfReuslt = "";
	my $result = "";
	($macroN, $OpHeadF, $IfResult) = @_;
	$OpHeadF =~ /(.+)\./;
	$OpHeadBase = $1;

	if ($IfResult){
		open(FH, "$OpHeadBase\_ResultValue.log") || die "Error:$!";
		while(<FH>){
			if (index($_, $macroN)==0){
				$_ =~ /.+=[\s](.+)/;
				$result = $1;
			}
		}
		close(FH);
	} else {
		open(FH, "$OpHeadBase\_OriginalValue.log") || die "Error:$!";
		while(<FH>){
			if (index($_, $macroN)==0){
				$_ =~ /.+=[\s](.+)/;
				$result = $1;
			}		
		}
		close(FH);
	}
	return $result;	
}