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
#  operator_feature_check.pl
#
# Description: 
# ------------
#  To generate dummy C files and pre-process them to get macro values.
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
use strict;

#******************************************************************************
# Global Data
#******************************************************************************
my $returnErrorCode = 0;        # return error code or not

my $mcuPath = "$ARGV[1]";
my $headerFilename = "$ARGV[2]";
my $operatorHeaderFile = "$ARGV[3]";
my $headerFilepath = "$ARGV[4]";
my $IsResult = "$ARGV[6]";#1: To get finial values. 0: To get original values.

# list the modules which their *.inc will be added into include path
my @includeMod = ();       # include *.inc

# additional path for include files
my @addIncPath = ($headerFilepath);
                  
# additional include files      
my @addIncFiles = ();

# additional lines
my @addLines = ();

# additional features to watch
my @addFeaturesToWatch = ();

# remove temp file or not
my $removeTempFile = 1;

# also process disabled features or not
my $alsoProcessDisabledFeatures = 0;

# compiler
my $compiler = "$ARGV[7]";
my $VIA = "$ARGV[8]";

my $checkMainFilename;
my $logFilename;

my %featureList = ();
my @sortedAllFeatures = ();
my @defFeatures = ();
my @undefFeatures = ();

my $allFeatureCount;
my $defFeatureCount;
my $undefFeatureCount;

#******************************************************************************
# Export Function
#******************************************************************************

#******************************************************************************
# Internal Data
#******************************************************************************
my @fileData = ();
my $logPath = "";
my $prjName = "";

#******************************************************************************
# Program Start
#******************************************************************************

# get project name from input argument
if (scalar(@ARGV) == 0)
{
    die "\nUsage: operator_feature_check.pl <project name> <mcu path>
    <customer header file> <operator header file> <customer header file path>
    <operator path> <1: To get final values 0: To get initial values>
    <compiler path> <compiler via argument>\n";
}
else
{
    $prjName = $ARGV[0];
}

print "\nStart Header File Feature Check...\n";

$logPath = $ARGV[5];

# get all feature list
open(hFile, "<$logPath\\$headerFilename") or die "can't open $logPath\\$headerFilename";
@fileData = <hFile>;
close(hFile);

print "get feature list from $headerFilename...\n";
foreach my $line (@fileData)
{
    my $feature = "";
    
    # also process marked "//" features or not
    if ($alsoProcessDisabledFeatures)
    {
        if ($line =~ /^([\s]*([\/]{2,})?[\s]*)(#define[\s]+)([\w_]+)([\s]*)/)
        {
            $feature = $4;
        }
    }
    else
    {
        if ($line =~ /^([\s]*)(#define[\s]+)([\w_]+)([\s]*)/)
        {
            $feature = $3;
        } elsif ($line =~ /^([\s]*([\/]{2,})[\s]*)\{(.+)\}/) {
        		$feature = $3;
        }
    }
    
    # ignore empty one
    if ($feature ne "")
    {
            $featureList{$feature} = "";
    }
} 

@sortedAllFeatures = sort(keys(%featureList));

# add additional features to watch
push @sortedAllFeatures, @addFeaturesToWatch;

$allFeatureCount = @sortedAllFeatures;

$checkMainFilename = "~".splitFilename($headerFilename, 0)."_check";

# generate XXX_check.c
print "generate feature check file...\n";
genCheckDotC("$checkMainFilename.c", $headerFilename, \@sortedAllFeatures);

# validate features
print "validate features...\n";
processCheckDotC("-E");

# check def/undef features in pre-processed file
print "check def/undef features in pre-processed file...\n";
checkFeatures("$checkMainFilename.obj", \%featureList, \@sortedAllFeatures, \@defFeatures, \@undefFeatures);
$defFeatureCount = @defFeatures;
$undefFeatureCount = @undefFeatures;

if ($removeTempFile)
{
    system("del /F /Q $checkMainFilename.c");
    system("del /F /Q $checkMainFilename.obj");
}
$logFilename = "$logPath\\".splitFilename($headerFilename, 0)."_$prjName.log";

checkConfig("$logPath\\$operatorHeaderFile", \%featureList, $logFilename);

if ($returnErrorCode)
{
    exit 1;
}
exit 0;

#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  genCheckDotC
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub genCheckDotC()
{
    my $filename;
    my $headerFilename;
    my @fileData;
    my $pUserData;  # reference to data array
    
    ($filename, $headerFilename, $pUserData) = @_;
        
    open(hFile, ">$filename") or die "can't open $filename";
       
    foreach my $line (@addLines)
    {
        print hFile $line;
    }
       
    # write header part
    
    foreach my $inc (@addIncFiles)
    {
        print hFile "#include \"$inc\"\n";
    }
    
    print hFile "#include \"$headerFilename\"\n\n";
    
    # write start tag    
    print hFile "static void * feature_check[] = {\n"; 
    
    foreach my $data (@$pUserData)
    {
        print hFile "(void *)$data,\n";
    }
    
    # write end tag
    print hFile "(void *)\"END FEATURE LIST\"};\n";
    
    close(hFile);
}


#******************************************************************************
# FUNCTION
#  processCheckDotC
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub processCheckDotC()
{
    my $infoFilename = "$mcuPath\\build\\$prjName\\log\\info.log";
    my $defTmpFilename = "$checkMainFilename.def";
    my $incTmpFilename = "$checkMainFilename.inc";
    my $compileOptions;
    my @fileData;
    my $inSection = 0;
    my $incPaths = "";
    my $commonOptions = "";
    
    my $incFilename;    
    my $count = 0;
    
    ($compileOptions) = @_;
           
    # read inc from *.inc
    foreach my $mod (@includeMod)
    {
        $incFilename = "$mcuPath\\make\\$mod\\$mod.inc";
        open(hFile, "<$incFilename") or die "can't open $incFilename";
        @fileData = <hFile>;
        close(hFile);
        
        foreach my $line (@fileData)
        {
            if ($line =~ /(^[^\s]*)([\s]*$)/)
            {
                $incPaths = "$incPaths\n-I$mcuPath\\$1";
            }
        }
    }
    
    foreach my $inc (@addIncPath)
    {
        $incPaths = "$incPaths\n-I$mcuPath\\$inc";
    }
            
    # read common options and common include path from info.log     
    open(hFile, "<$infoFilename") or die "can't open $infoFilename";
    @fileData = <hFile>;
    close(hFile);
    
    foreach my $line (@fileData)
    {
        if ($line =~ /\[ COMMON OPTION \]/)
        {
            $inSection = 1;
            next;
        }
        elsif ($line =~ /\[ COMMON INCLUDE PATH \]/)
        {
            $inSection = 2;
            next;
        }
    
        if ($line =~ /(^[^\[][^\s]*)/)
        {           
            if ($inSection == 1)
            {
                $commonOptions = "$commonOptions\n-D$1";
            }
            elsif ($inSection == 2)
            {
                my $inc = "$1";
                
                if ($inc !~ /:/)
                {
                    $inc = "$mcuPath\\$inc";
                }
                $incPaths = "$incPaths\n-I$inc";
            }
        }
        else            
        {
            $inSection = 0;
        }
    }
    open(hFile, ">$defTmpFilename") or die "can't open $defTmpFilename";
    print hFile "$commonOptions\n";
    close(hFile);
    
    open(hFile, ">$incTmpFilename") or die "can't open $incTmpFilename";
    print hFile "$incPaths\n";
    close(hFile);    
    
    open(hFile, ">makeCheck.bat") or die "makeCheck.bat";
    print hFile "\@echo off\n";
    print hFile "$compiler $checkMainFilename.c -o $checkMainFilename.obj $compileOptions $VIA $defTmpFilename $VIA $incTmpFilename\n";    
    print hFile "\@echo on\n";
    close(hFile);
    system("makeCheck.bat");
    if ($removeTempFile)
    {
        system("del /F /Q makeCheck.bat");        
        system("del /F /Q $defTmpFilename");
        system("del /F /Q $incTmpFilename");
    }
    
    # post-process *.obj
    open(hFile, "<$checkMainFilename.obj") or die "can't open $checkMainFilename.obj\n";
    @fileData = <hFile>;
    close(hFile);
    
    # remove multi-CR/LF
    my $tmpStr = join('',@fileData);
    $tmpStr =~ s/\n([\s]+)\n/\n\n/g;
    open(hFile, ">$checkMainFilename.obj") or die "can't open $checkMainFilename.obj\n";
    print hFile $tmpStr;
    close(hFile);
}


#******************************************************************************
# FUNCTION
#  checkConfig
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub checkConfig()
{
    my $switchFilePathname;
    my $featureHash_ref;
    my %featureHash_temp = ();
    my $logname = "";    
    my @fileData;
    my %cfgHash = ();
    my @cfgList = ();
    
    ($switchFilePathname, $featureHash_ref, $logname) = @_;
    open(hFile, "<$switchFilePathname") or die "can't open $switchFilePathname. $!\n";
    @fileData = <hFile>;
    close(hFile);
    
    open(hFile, ">$logname") or die "can't open $logname:$!\n";
    $switchFilePathname =~ /.+\\(.+)\./;
    my $headerfile = $1;
    if ($IsResult){
    	open(writeRsultValue,">$1_ResultValue.log") or die "Error: $!\n";
    } else {
    	open(writeOriginalValue,">$1_OriginalValue.log") or die "Error: $!\n";
    }
    # generate cfgHash from featureHash
    while (my ($feature, $value) = each (%{$featureHash_ref}))
    {
        $feature =~ s/(^[_]*)|([_]*$)//g;
        	
        $value =~ s/[\s]*//g;             # remove empty
        $value =~ s/(^[\(]*)|([\)]*$)//g; # remove head '(' and tail ')' 
        if ($IsResult){
    			print writeRsultValue "$feature = $value\n";
    		} else {
    			print writeOriginalValue "$feature = $value\n";
    		}
        $featureHash_temp{$feature} = "$value";

        $cfgHash{$feature} = $value;

    }
    foreach my $feature (%featureHash_temp){
    	if ($feature =~ /OP_WARNING_(.+)/){
    			if (index($featureHash_temp{$feature},"OPERATOR_CHECK_MESSAGE_ON")>=0){
    				print hFile "$1's value was modified\n";
    			}
    	}
    }

    close(hFile);
}


#******************************************************************************
# FUNCTION
#  checkFeatures
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub checkFeatures()
{
    my $filename;           # preprocessed object filename
    my $pFeatureList;       # reference to hash of feature list,
                            # after this call, only contains defined features
    my $pSortedAllFeatures; # reference to array of sorted all features
    my $pDefFeatures;       # reference to array of defined features
    my $pUndefFeatures;     # reference to array of undefined features

    my @fileData;
    my $isFeature = 0;
    my $featureIndex;
    my $defFeature;
    
    ($filename, $pFeatureList, $pSortedAllFeatures, 
        $pDefFeatures, $pUndefFeatures) = @_;
    
    open(hFile, "<$filename") or die "Cannot open $filename. Error:$!\n";
    @fileData = <hFile>;
    close(hFile);
    
    foreach my $line (@fileData)
    {
        if ($isFeature)
        {
            if ($line =~ /(^\(void \*\)[\s]*)([^,]*)([\s]*,$)/)
            {
                $defFeature = $$pSortedAllFeatures[$featureIndex];
                
                if ($2 eq $defFeature)
                {
                    # undefined symbols ("_XXX_" shows) 
                    # When the symbol was not defined, the obj will show the symbol name directly.
                    # If the symbol name was shown, we know the symbol was not defined.
                    # If the symbol was defined, the evaluated value will be shown.
                    push @$pUndefFeatures, $2;
                   
                    # remove it from feature list
                    delete $$pFeatureList{$2};                    
                }
                else
                {
                    # process defined symbols
                    
                    push @$pDefFeatures, $defFeature;
                    
                    # update value of feature list
                    $$pFeatureList{$defFeature} = $2;      
                }         
            }
            # end of feature list
            elsif ($line =~ /"END FEATURE LIST"}/)
            {
                $isFeature = 0;
            }            
            elsif ($line !~ /^[\s]*$/)
            {
                print "[Not Processed] \"$line\"\n";
            }
            $featureIndex++;
        }

        # check if begining of feature list
        if ($line =~ /feature_check\[\]/)
        {
            $isFeature = 1;
            $featureIndex = 0;
        }
    }
}


#******************************************************************************
# FUNCTION
#  splitFilename
# DESCRIPTION
#  xxx
# PARAMETERS
#  $filename [IN] - filename
#  $refSubFilename [OUT] - reference to sub filename, may be NULL
# RETURNS
#  main filename
#******************************************************************************
sub splitFilename()
{
    my $filename;
    my $refSubFilename = "";
    my $mainFilename = "";
    
    ($filename, $refSubFilename) = @_;
    
    if ($filename =~ /([^\s]*)(\.)([^\.]*$)/)
    {
        #print "$filename [$1][$3]\n";
        $mainFilename = "$1";
        if ($refSubFilename != 0)
        {
            $$refSubFilename = "$3";
        }
    }
    return $mainFilename;
}


