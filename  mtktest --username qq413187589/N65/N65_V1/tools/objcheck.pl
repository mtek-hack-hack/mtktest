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
#
# Filename: 
# ---------
#  objcheck.pl
#
# Description: 
# ------------
#  this script is used to check run-time values, e.g. 'size of each element of union'.
#
# Auther: 
# -------
#  Shinn Lin
# 
# Note:
# -----
#  Support Status
#  1. union/struct      (o)
#  2. multi-setting     (o)
#
# Log: 
# -----
#  2008/02/22   Create.
#

#BEGIN { push @INC, 'U:\\00MyPerlLib'}  # add additional library path
#package XXX;  
use strict;

#******************************************************************************
# Global Data
#******************************************************************************
my $g_settingFilename = "tools\\objcheck.txt";
my $g_logFile = "objcheck.log";

my $g_prjName = '';
my $g_mcuPath = ".";

# remove temp file or not
my $g_removeTempFile = 1;

# also process disabled features or not
my $g_alsoProcessDisabledFeatures = 1;

my $g_compiler = 'armcc';   # default compiler
my $g_viaOption = '--via';  # default 'via' option

my $checkMainFilename;

my $separation = "***********************************************************************";

my $magicNumber = "26598088";

my $str_objcheck = "objcheck";
my $str_info = "info";
my $str_removeTmpFile = "removeTmpFile";
my $str_alsoProcessDisabledFeatures = "alsoProcessDisabledFeatures";
my $str_filename = "filename";
my $str_path = "path";
my $str_type = "type";
my $str_parsingInc = "parsingInc";
my $str_addModuleInc = "addModuleInc";
my $str_addIncPath = "addIncPath";
my $str_addIncFiles = "addIncFiles";
my $str_addLines = "addLines";
my $str_addPostLines = "addPostLines";
my $str_addFeaturesToWatch = "addFeaturesToWatch";

# tag name and in-tag/end-tag handler
my %xmlTags = ( $str_objcheck           => \&objcheck_tag_hdlr,
                $str_info               => \&info_tag_hdlr, 
                $str_addModuleInc       => \&addModuleInc_tag_hdlr, 
                $str_addIncPath         => \&addIncPath_tag_hdlr,
                $str_addIncFiles        => \&addIncFiles_tag_hdlr, 
                $str_addLines           => \&addLines_tag_hdlr,
                $str_addPostLines       => \&addPostLines_tag_hdlr,
                $str_addFeaturesToWatch => \&addFeaturesToWatch_tag_hdlr);

#******************************************************************************
# Export Function
#******************************************************************************

#******************************************************************************
# Internal Data
#******************************************************************************
my %settingData = ();

#******************************************************************************
# Program Start
#******************************************************************************

# get project name from input argument
if (scalar(@ARGV) == 0)
{
    my @usage = ();
    push @usage, "\nUsage 1: 'objcheck.pl <project name> <compiler> <via option>'\n\n";
    push @usage, "e.g. 'objcheck.pl DRAGONFLY_DEMO armcc --via'\n\n";
    die join('', @usage);
}
else
{
    ($g_prjName, $g_compiler, $g_viaOption) = @ARGV;       
}

print "\n[start objcheck]\n\n";

#&timeCheck();

# get settings from file
&getSettings($g_settingFilename, \%settingData);

#&timeCheck();

exit 0;


#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  startCheck
# DESCRIPTION
#  start obj check
# PARAMETERS
#  
# RETURNS
#  none
#******************************************************************************
sub startCheck()
{
    my $settingData_href;

    ($settingData_href) = @_;
    
    my $targetFilepath = ${$settingData_href}{$str_path};
    my $targetFilename = ${$settingData_href}{$str_filename};
    my $parsingInc = ${$settingData_href}{$str_parsingInc};
    my $type = ${$settingData_href}{$str_type};
    my @fileData = ();
    my $logFilename;

    # list the modules which their *.inc will be added into include path
    my $includeMod = ${$settingData_href}{$str_addModuleInc};    # include *.inc
        
    # additional path for include files
    my $addIncPath = ${$settingData_href}{$str_addIncPath};
    unshift @{${$settingData_href}{$str_addIncPath}}, $targetFilepath;
                      
    # additional include files      
    my $addIncFiles = ${$settingData_href}{$str_addIncFiles};       #("mmi_features.h");
    
    # additional lines
    my $addLines = ${$settingData_href}{$str_addLines};
       
    # additional features to watch
    my $addFeaturesToWatch = ${$settingData_href}{$str_addFeaturesToWatch};
    
    my %featureList = ();
    my @unionInOrder = ();
    my @sortedAllFeatures = ();
    my @defFeatures = ();
    my @undefFeatures = ();
    my $allFeatureCount;
    my $defFeatureCount;
    my $undefFeatureCount;
    
    $checkMainFilename = "~".splitFilename($targetFilename, 0)."_check";
    my $checkTmpMainFilename = "$checkMainFilename"."_tmp";      
    my $checkFile = "$g_mcuPath\\$targetFilepath\\$targetFilename";

    # get all feature list
    if (!(-e $checkFile))
    {
        print "[objcheck.pl][Warning] $checkFile not exist!\n";
        return;
    }
    
    open(hFile, "<$checkFile") or die "can't open $checkFile";
    @fileData = <hFile>;
    close(hFile);

    print "--> get checking data from $targetFilename...\n";

    if ($type eq 'macro')       
    {
        # get macros
        getMacro(\@fileData, \%featureList);
        foreach my $feature (keys(%featureList))
        {
            push @{${$settingData_href}{$str_addPostLines}}, "#ifndef $feature\n#define $feature 0\n#endif\n";
        }
        push @sortedAllFeatures, sort(keys(%featureList));        
    }
    else
    {
        # get union from target file
        my @targetUnionInOrder = ();
        getUnion(\@fileData, \@targetUnionInOrder) if ($parsingInc == 0);
               
        # gen pre-processed tmp file   
        genCheckDotC($type, "$checkTmpMainFilename.c", $targetFilename, \@sortedAllFeatures, $settingData_href);
        processCheckDotC($checkTmpMainFilename, "-E", $settingData_href, $g_removeTempFile);
        $checkFile = "$g_mcuPath\\$checkTmpMainFilename.obj";         
        open(hFile, "<$checkFile") or die "can't open $checkFile";
        @fileData = <hFile>;
        close(hFile);      

        # get union from pre-processed file (means it really exists)
        my %unionTmp = ();
        getUnion(\@fileData, \@unionInOrder, \%unionTmp);
        
        if ($parsingInc == 0)
        {
            foreach my $targetUnion (@targetUnionInOrder)
            {
                # if targetUnion really exists
                push @sortedAllFeatures, $targetUnion if (defined ${unionTmp}{$targetUnion});
            }
        }
        else
        {
            push @sortedAllFeatures, @unionInOrder if (scalar(@unionInOrder));
        }
    }    
       
    # add additional features to watch
    push @sortedAllFeatures, @{$addFeaturesToWatch} if (defined $addFeaturesToWatch);
    
    $allFeatureCount = @sortedAllFeatures;
       
    # generate XXX_check.c
    print "--> generate checking file...\n";
    genCheckDotC($type, "$checkMainFilename.c", $targetFilename, \@sortedAllFeatures, $settingData_href);
    
    # validate features
    print "--> checking...\n";
    my $compileOption = "-c";
    $compileOption = "-E" if ($type eq 'macro');
    processCheckDotC($checkMainFilename, $compileOption, $settingData_href, $g_removeTempFile);
    
    # check def/undef features in pre-processed file
    #print "--> check def/undef features in pre-processed file...\n";
    checkFeatures($type, "$checkMainFilename.obj", \%featureList, \@sortedAllFeatures, \@defFeatures, \@undefFeatures);
    $defFeatureCount = @defFeatures;
    $undefFeatureCount = @undefFeatures;
    
    if ($g_removeTempFile)
    {
        system("del $checkMainFilename.c") if (-e "$checkMainFilename.c");
        system("del $checkMainFilename.obj") if (-e "$checkMainFilename.obj");
        system("del $checkTmpMainFilename.c") if (-e "$checkTmpMainFilename.c");
        system("del $checkTmpMainFilename.obj") if (-e "$checkTmpMainFilename.obj");        
    }    
    
    # output results
    #$logFilename = splitFilename($targetFilename, 0).".log";
    $logFilename = "build\\$g_prjName\\log\\$g_logFile";
    genLog($type, $logFilename, $targetFilename, \@defFeatures, \%featureList,
            \@undefFeatures, \@sortedAllFeatures);
    
    # verify result
    if ($allFeatureCount != ($defFeatureCount+$undefFeatureCount))
    {
        print "[Error] all feature count($allFeatureCount) != defined count($defFeatureCount) + undef count($undefFeatureCount)\n";
        return 1;
    }
    else
    {
        print "\n[Done] [$targetFilename] defined count = $defFeatureCount\n\n";
        return 0;
    }
}

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
    my $type;
    my $filename;
    my $targetFilename;
    my @fileData;
    my $pUserData;  # reference to data array
    my $settingData_href;
    
    ($type, $filename, $targetFilename, $pUserData, $settingData_href) = @_;
        
    open(hFile, ">$filename") or die "can't open $filename";
       
    foreach my $line (@{${$settingData_href}{$str_addLines}})
    {
        print hFile "$line\n";
    }
       
    # write header part
    
    foreach my $inc (@{${$settingData_href}{$str_addIncFiles}})
    {
        print hFile "#include \"$inc\"\n";
    }
    
    print hFile "#include \"$targetFilename\"\n\n";
    
    foreach my $data (@{${$settingData_href}{$str_addPostLines}})
    {
        print hFile $data;
    }
    
    # write start tag    
    print hFile "\nvoid * feature_check[] = {\n"; 
    
    if ($type eq 'macro')
    {
        foreach my $data (@$pUserData)
        {
            print hFile "(void *)$data,\n";
        }
        
        # write end tag
        print hFile "(void *)\"END FEATURE LIST\"};\n";
    }
    else
    {
        print hFile "(void *)0x$magicNumber,\n";
        
        foreach my $data (@$pUserData)
        {
            print hFile "(void *)($data),\n";
        }
        
        # write end tag
        print hFile "(void *)0x$magicNumber};\n";
    }
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
    my $mainFilename;
    my $compileOptions;
    my $settingData_href;
    my $removeTmpFile;
    
    ($mainFilename, $compileOptions, $settingData_href, $removeTmpFile) = @_;
    
    my $includeMod = ${$settingData_href}{$str_addModuleInc};    # include *.inc       
    my $addIncPath = ${$settingData_href}{$str_addIncPath};
    
    my $infoFilename = "$g_mcuPath\\build\\$g_prjName\\log\\info.log";
    my $batFilename = "~makeCheck.bat";
    my $defTmpFilename = "$mainFilename.def";
    my $incTmpFilename = "$mainFilename.inc";
    my @fileData;
    my $inSection = 0;
    my $incPaths = "";
     
    my $count = 0;    
    my $commonOptions = "";
            
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
                #print "$1\n";
                $commonOptions = "$commonOptions\n-D$1";
            }
            elsif ($inSection == 2)
            {
                my $inc = "$1";
                
                if ($inc !~ /:/)
                {
                    $inc = "$g_mcuPath\\$inc";
                }
                #print "$inc\n";
                $incPaths = "$incPaths\n-I$inc";
            }
        }
        else            
        {
            $inSection = 0;
        }
    }
    
    # read inc from *.inc
    foreach my $myMod (@{$includeMod})
    {
        my @incFiles = ();
        if (&getFileList("$g_mcuPath\\make\\$myMod\\*.inc /s", \@incFiles) > 0)
        {
            foreach my $incFilename (@incFiles)
            {
                open(hFile, "<$incFilename") or die "can't open $incFilename";
                @fileData = <hFile>;
                close(hFile);
                
                foreach my $line (@fileData)
                {
                    if ($line =~ /(^[^\s]+)([\s]*$)/)
                    {
                        $incPaths = "$incPaths\n-I$g_mcuPath\\$1";
                    }
                }
            }            
        }
    }
    
    # additional inc path
    foreach my $inc (@{$addIncPath})
    {
        $incPaths = "$incPaths\n-I$g_mcuPath\\$inc";
    }     
    
    # read macro from *.def
    foreach my $myMod (@{$includeMod})
    {
        my @defFiles = ();
        if (&getFileList("$g_mcuPath\\make\\$myMod\\*.def /s", \@defFiles) > 0)
        {
            foreach my $defFilename (@defFiles)
            {
                open(hFile, "<$defFilename") or die "can't open $defFilename";
                @fileData = <hFile>;
                close(hFile);
                
                foreach my $line (@fileData)
                {
                    if ($line =~ /(^[^\s]+)([\s]*$)/)
                    {
                        $commonOptions = "$commonOptions\n-D$1";
                    }
                }
            }            
        }
    }
  
    #print "$commonOptions\n";
    open(hFile, ">$defTmpFilename") or die "can't open $defTmpFilename";
    print hFile "$commonOptions\n";
    close(hFile);
    
    #print "$incPaths\n";
    open(hFile, ">$incTmpFilename") or die "can't open $incTmpFilename";
    print hFile "$incPaths\n";
    close(hFile);    
    
    open(hFile, ">$batFilename") or die "can't open $batFilename\n";
    print hFile "\@echo off\n";
    print hFile "$g_compiler $mainFilename.c -o $mainFilename.obj $compileOptions $g_viaOption $defTmpFilename $g_viaOption $incTmpFilename\n";    
    print hFile "\@echo on\n";
    close(hFile);   
   
    #&timeCheck();
    system("$batFilename");    
    #&timeCheck();

    # remove empty lines for -E
    if ($compileOptions =~ /-e([\s]+|$)/i)
    {
        open(hFile, "<$mainFilename.obj") or die "can't open $mainFilename.obj\n";
        my $tmp = join('',<hFile>);
        close(hFile);
        $tmp =~ s/\n([\s]+)\n/\n\n/g;    # reduce multi-CR/LF
        open(hFile, ">$mainFilename.obj") or die "can't open $mainFilename.obj for write\n";
        print hFile $tmp;
        close(hFile);
    }
        
    if ($removeTmpFile)
    {
        system("del $batFilename");        
        system("del $defTmpFilename");
        system("del $incTmpFilename");
    }    
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
    my $type;               # 'obj' or 'macro'
    my $filename;           # preprocessed object filename
    my $pFeatureList;       # reference to hash of feature list
    my $pSortedAllFeatures; # reference to array of sorted all features
    my $pDefFeatures;       # reference to array of defined features
    my $pUndefFeatures;     # reference to array of undefined features

    my @fileData;
    my $isFeature = 0;
    my $featureIndex;
    my $defFeature;
    
    ($type, $filename, $pFeatureList, $pSortedAllFeatures, 
        $pDefFeatures, $pUndefFeatures) = @_;  
       
    if ($type eq 'macro')
    {       
        open(hFile, "<$filename") or die "can't open $filename";
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
                        
                        push @$pUndefFeatures, $2;
                       
                        # remove it from feature list
                        delete $$pFeatureList{$2};
                        
                        #print "[U] $2\n";                      
                    }
                    else
                    {
                        # process defined symbols
                        
                        push @$pDefFeatures, $defFeature;
                        
                        # update value of feature list
                        $$pFeatureList{$defFeature} = $2;
                        
                        #print "[D] $defFeature = $2\n";       
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
                
                #print "[$featureIndex] $$pSortedAllFeatures[$featureIndex] $line\n";
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
    else    # 'obj'
    {
        open(hFile, "<$filename") or die "can't open $filename";
        binmode(hFile);
        my $binData;
        my $status = '';
        while (read(hFile, $binData, 4))
        {
            if ($status eq 'start')
            {
                my $value = ascii2dec_le($binData);
                if ($value == hex($magicNumber))
                {
                    #print "END\n";
                    last;
                }
                
                $defFeature = $$pSortedAllFeatures[$featureIndex];
                $featureIndex++;
                
                push @$pDefFeatures, $defFeature;
                # update value of feature list
                $$pFeatureList{$defFeature} = $value;
                #print "$defFeature = $value\n";
            }
    
            # begin of array
            if (ascii2dec_le($binData) == hex($magicNumber))
            {
                $status = 'start';
                $featureIndex = 0;
                #print "Start\n";
            }
        }
        close(hFile);
    }

}


#******************************************************************************
# FUNCTION
#  getSettings
# DESCRIPTION
#  get settings from file
# PARAMETERS
#  $filename        [IN] - setting file pathname
#  $targetHash_ref  [IN] - reference to target hash
# RETURNS
#  none
#******************************************************************************
sub getSettings()
{
    my $filename;
    my $settingData_href;

    ($filename, $settingData_href) = @_;
    
    my @fileData;
    #my %settingData = ();    
        
    open(hFile, "<$filename") or die "can't open $filename\n";
    @fileData = <hFile>;
    close(hFile);
    
    # parse setting file
    parseXmlLineData(\@fileData, \%xmlTags, $settingData_href);
}


sub objcheck_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;
    
    #print "tag hdlr [0]\n";
    
    &startCheck($para_href);
    %{$para_href} = ();     # reset setting data
}


sub info_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;
    
    #print "tag hdlr [1]\n";
    
    while (my ($attr, $value) = each(%{$$taginfo_aref[0]}))
    {
        #print "    attr [$attr] = $value\n";
        ${$para_href}{$str_filename}    = $value if ($attr eq $str_filename);
        ${$para_href}{$str_path}        = $value if ($attr eq $str_path);
        ${$para_href}{$str_parsingInc}  = $value if ($attr eq $str_parsingInc);
        ${$para_href}{$str_type}        = $value if ($attr eq $str_type);
        
        $g_removeTempFile = $value if ($attr eq $str_removeTmpFile);
        $g_alsoProcessDisabledFeatures = $value if ($attr eq $str_alsoProcessDisabledFeatures);
    }
}

sub addModuleInc_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [2]\n";
    push @{${$para_href}{$str_addModuleInc}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(' ',@{${$para_href}{$str_addModuleInc}})."\n";
}

sub addIncPath_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [3]\n";
    push @{${$para_href}{$str_addIncPath}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(' ',@{${$para_href}{$str_addIncPath}})."\n";
}

sub addIncFiles_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [4]\n";
    push @{${$para_href}{$str_addIncFiles}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(', ',@{${$para_href}{$str_addIncFiles}})."\n";
}

sub addLines_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [5]\n";
    push @{${$para_href}{$str_addLines}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(' ',@{${$para_href}{$str_addLines}})."\n";
}

sub addPostLines_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    push @{${$para_href}{$str_addPostLines}}, trim($_) foreach (@{$$taginfo_aref[1]});    
}

sub addFeaturesToWatch_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [6]\n";
    push @{${$para_href}{$str_addFeaturesToWatch}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(' ',@{${$para_href}{$str_addFeaturesToWatch}})."\n";
}


#******************************************************************************
# FUNCTION
#  getUnion
# DESCRIPTION
#  get union from file
# PARAMETERS
#  
# RETURNS
#  none
#******************************************************************************
sub getUnion()
{
    my $srcDataRef;
    my $dataARef;
    my $dataHRef;
    
    ($srcDataRef, $dataARef, $dataHRef) = @_;
         
    # remove comments
    my $tmpStr = join('', @{$srcDataRef});
    $tmpStr =~ s/(\/\*.*?\*\/)//gs; # remove all C comments
    $tmpStr =~ s/(\/\/.*)//g;       # remove all C++ comments                 
                                                   
    # find union
    while ($tmpStr =~ /[\s]+typedef[\s]+(union|struct)[\s]*\{([^\{\}]+?)\}[\s]*([\*]*)[\s]*([\w]+)[\s]*\;/sg)
    {
        #my $typedef = $1;
        my $type = $1;
        my $data = $2;      
        my $ptrStr = $3;
        my $unionName = $4;
        my $str = "";
       
        #print "====>>> [$unionName][$typedef] [$type] [$ptrStr]\n";
        $str = "sizeof($unionName)";
        push @{$dataARef}, $str if (defined $dataARef);
        ${$dataHRef}{$str} = "" if (defined $dataHRef);
                
        my @dataArray = ();
        @dataArray = split(';', $data);
        foreach my $line (@dataArray)
        {
            # [^:] => exclude bit-field
            if (($line =~ /[^:]+[\s]+[\*]*([\w]+)[\s]*$/) ||
                ($line =~ /[^:]+[\s]+[\*]*([\w]+)[\s]*\[[^\]]+\][\s]*$/))
            
            {
                if ($type eq 'union' || $type eq 'struct')
                {
                    $str = "sizeof(($ptrStr($unionName *)0)->$1)";
                    push @{$dataARef}, $str if (defined $dataARef);
                    ${$dataHRef}{$str} = "" if (defined $dataHRef);
                }
            }
        }
    }
}



sub getMacro()
{
    my $srcDataRef;
    my $dataHRef;
    
    ($srcDataRef, $dataHRef) = @_;
    
    foreach my $line (@{$srcDataRef})
    {
        my $feature = "";
        
        # also process marked "//" features or not
        if ($g_alsoProcessDisabledFeatures)
        {
            if ($line =~ /^([\s]*([\/]{2,})?[\s]*)(#define[\s]+)([\w_]+)([\s]+)([\w\(\)]+)/)
            {
                $feature = $4;
            }
        }
        else
        {
            if ($line =~ /^([\s]*)(#define[\s]+)([\w_]+)([\s]+)([\w\(\)]+)/)
            {
                $feature = $3;
            }
        }   
        
        if ($feature ne "")
        {
            ${$dataHRef}{$feature} = "";
        }
    }         
}


#******************************************************************************
# FUNCTION
#  parseXmlLineData
# DESCRIPTION
#  parse XML data lines (usage ref. ffcheck_any.pl)
# PARAMETERS
#  $lineData_aref - ref. to array of line data
#  $interestXmlTags_aref - ref. to hash of interested xml tags
#  $taginfo_href - reference to tag info hash  {tag => [0] {attr => value}}
#                                                   [1] [] data lines
# RETURNS
#  none
#******************************************************************************
sub parseXmlLineData()
{
    my $lineData_aref;          # ref. to xml line data
    my $xmlTags_href;           # ref. to interested xml tags
    my $para_href;              # ref. to user parameter
          
    ($lineData_aref, $xmlTags_href, $para_href) = @_;
   
    my $inXmlTag = 0;
    my $currTag = "";  
    my @tagStack = ();
    my %taginfo;                # parsed tag info
                                # {tag => [0] {attr => value}}
                                #         [1] [] data lines
   
    foreach my $line (@$lineData_aref)
    {       
        %taginfo = ();
        if (($line =~ /(^[ \t]*\#)|(^[\s]*$)/) && ($inXmlTag == 0))
        {
            # ignore comments or empty line, except in Xml tag processing
        }
        elsif ($line =~ /(<)([^>]+)(>)/)
        {
            my $tagData = $2;
            my $newTag;
    
            ($inXmlTag, $newTag) = processTagInt($tagData, \%taginfo);
            #print "ret val = $inXmlTag new[$newTag] curr[$currTag]\n";
            #print "${$xmlTags_href}{$newTag}\n" if (exists ${$xmlTags_href}{$newTag});
            
            if ($inXmlTag == 0)
            {
                if (exists ${$xmlTags_href}{$newTag})
                {
                    # if tag found and hdlr exists, execute the hdlr after whole tag processed
                    ${$xmlTags_href}{$newTag}($taginfo{$newTag}, $para_href) if (${$xmlTags_href}{$newTag} != 0);
                }
                
                pop @tagStack if ($newTag eq $currTag);
            }            
            # update tag for in-tag process
            elsif ($newTag ne $currTag)     # && ($inXmlTag == 1)
            {
                push @tagStack, $currTag if ($currTag ne "");
                $currTag = $newTag;
            }
        }
        elsif ($line =~ /([^\n]+)(\n$)/)
        {
            if ($inXmlTag == 1)
            {
                $line =~ s/(^\s*)|(\s*$)//g;
                push @{$taginfo{$currTag}[1]}, $line if ($line ne "");

                if (exists ${$xmlTags_href}{$currTag})
                {
                    # if tag found and hdlr exists, execute the hdlr after whole tag processed
                    ${$xmlTags_href}{$currTag}($taginfo{$currTag}, $para_href);
                }
            }
        }
    }    
}


#******************************************************************************
# FUNCTION
#  processTag
# DESCRIPTION
#  process tag 
# PARAMETERS
#  para 1 - tag to process
#  para 2 - reference to attribute hash  {tag => {attr => value}}
# RETURNS
#  success (tag name) or not ("")
#******************************************************************************
sub processTagInt()
{
    my $tagToProcess;       # tag to process
    my $result_href;        # reference to result hash
           
    ($tagToProcess, $result_href) = @_;

    my $tagName = "";
    my $inTag = 0;
    
    $tagToProcess =~ s/(^[\s]*)|([\s]*$)//g;
    if ($tagToProcess =~ /^([\w_]+)$/i)
    {
        # start of tag
        $tagName = $1;
        $inTag = 1;
    }
    elsif ($tagToProcess =~ /^\/[ \t]*([\w_]+)$/i)
    {
        # end of tag
        $tagName = $1;
    }
    elsif ($tagToProcess =~ /(^[\w_]+)[ \t]+(([\w_]+[ \t]*=[ \t]*([\"\'])[^\4]+\4[ \t]*)+)(\/?$)/i)
    {
        #print "$tagToProcess\n";
        my @attrAll = split(' ',$2);
        $tagName = $1;
        
        # if tag ends with '/'
        $inTag = 1 if ($5 ne '/');
        
        # parse each attr
        foreach my $attr (@attrAll)
        {
            #print "[$attr]\n";
            if ($attr =~ /([\w_]+)[ \t]*=[ \t]*([\"\'])([^\2]+)\2/i)
            {
                ${$result_href}{$tagName}[0]{$1} = $3;
                #print "[$tagName] [$1] [$3]\n"; 
            }
        }
    }
    else
    {
        #print "[$tagToProcess] not processed\n";
    }

    return ($inTag, $tagName);
}


sub trim()
{
    $_ =~ s/(^\s*)|(\s*$)//g;
    return $_;
}


sub ascii2dec_le()
{
    my $input;
    
    ($input) = @_;
    
    my $output = ord(substr($input, 3, 1))*256*256*256+
                 ord(substr($input, 2, 1))*256*256+
                 ord(substr($input, 1, 1))*256+
                 ord(substr($input, 0, 1));
    #print "$input = $output";
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


#******************************************************************************
# FUNCTION
#  getFileList
# DESCRIPTION
#  get file/path list for given search string
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub getFileList()
{
    my $dirStr;
    my $fileList_ref;
    
    ($dirStr, $fileList_ref) = @_;
    
    my @fileData = ();

    # get file list
    my $tmpFilename = "~tmpFile.lst";
    
    system("dir ".$dirStr." > $tmpFilename");
    open(hFile, "<$tmpFilename") or die "[ERROR] can't open $tmpFilename\n";
    @fileData = <hFile>;
    close(hFile);
    system("del $tmpFilename");

    my $currDir = "";
    foreach my $line (@fileData)
    {
        if ($line =~ /^[\s]*Directory of[\s]+([^\n]+)/i)
        {
            $currDir = $1;
            #print "[dir] $currDir\n";
        }
        elsif ($line =~ /[\s]+File\(s\)[\s]+/)
        {
            $currDir = "";
        }
        elsif ($currDir ne "")
        {
            # [time] [size] [filename]  <= dir result
            if ($line =~ /\d\d:\d\d[\s]+([\d,]+)[\s]+([^\n]+)/)
            {
                my $size = $1;
                my $name = $2;
                #print "[size] $size\t[name] $name\n";
                push @{$fileList_ref}, "$currDir\\$name";
            }
        }
    }
    return scalar(@{$fileList_ref});
}


#******************************************************************************
# FUNCTION
#  genLog
# DESCRIPTION
#  xxx
# PARAMETERS
#  $filename [IN] - log file pathname
# RETURNS
#  none
#******************************************************************************
my $logCount = 0;
sub genLog()
{
    my $type;
    my $logFilePathname;
    my $logTitle;
    my $defFeatures_aref;
    my $featureData_href;
    my $undefFeatures_aref;
    my $sortedAllFeatures_aref;
    
    ($type, $logFilePathname, $logTitle, $defFeatures_aref, $featureData_href,
        $undefFeatures_aref, $sortedAllFeatures_aref) = @_;
    
    my $col1LenMax;
    my $col2LenMax;
    my $allFeatureCount;
    my $defFeatureCount;
    my $undefFeatureCount;    
    
    if ($logCount == 0)
    {
        # create file
        open(hLogFile, ">$logFilePathname") or die "can't open $logFilePathname";
    }
    else
    {
        # append file
        open(hLogFile, ">>$logFilePathname") or die "can't open $logFilePathname";
    }    
    $logCount++;
    
    $allFeatureCount = @$sortedAllFeatures_aref;
    $defFeatureCount = @$defFeatures_aref;
    $undefFeatureCount = @$undefFeatures_aref;    
    
    # title
    print hLogFile "\n$separation\n $logTitle\n$separation\n";    
    
    $col1LenMax = 0;
    $col2LenMax = 0;
    foreach my $feature (@$sortedAllFeatures_aref)
    {
        # get max. len of feature name
        $col1LenMax = length($feature) if (length($feature)>$col1LenMax);
        
        # get max. len of feature value
        $col2LenMax = length(${$featureData_href}{$feature}) if (length(${$featureData_href}{$feature})>$col2LenMax);
    }      
    
    # result: Defined Features
    print hLogFile "\n$separation\n[Defined Values ($defFeatureCount/$allFeatureCount)]\n$separation\n\n";
    if ($type eq 'macro')
    {
        foreach my $feature (@$defFeatures_aref)
        {
            print hLogFile sprintf("[D] %-*s%s\n", $col1LenMax+8, 
                                $feature, ${$featureData_href}{$feature});
        }
    }
    else
    {
        foreach my $feature (@$defFeatures_aref)
        {
            print hLogFile sprintf("[D] %-*s%*s\n", $col1LenMax+8, 
                                $feature, $col2LenMax+2, ${$featureData_href}{$feature});
        }
    }
    print hLogFile "\n\n";
        
    close(hLogFile);    
    print "--> log generated to $logFilePathname\n";
}


#******************************************************************************
# FUNCTION
#  timeCheck
# DESCRIPTION
#  print current time (in sec.) and time-difference to previous check if exists
# PARAMETERS
#  none
# RETURNS
#  current time and time difference if exists (both in sec.)
#******************************************************************************
my @timePrev = ();
sub timeCheck()
{
    my @timeCurr = localtime(time);
    print "[Time: ".&timeInSec(\@timeCurr)." sec.";
    if (@timePrev > 0) # previous-time exists
    {
        print "(Diff = ".&timeDiffInSec(\@timeCurr, \@timePrev).")";
    }
    print "]\n";
    @timePrev = @timeCurr;    
}


#******************************************************************************
# FUNCTION
#  timeDiffInSec
# DESCRIPTION
#  get time difference in sec.
# PARAMETERS
#  para 1 - reference to time1 in localtime array format
#  para 2 - reference to time2 in localtime array format
# RETURNS
#  time difference in sec.
#******************************************************************************
sub timeDiffInSec()
{
    my $time1;
    my $time2;
    my $timeDiff;
    
    ($time1, $time2) = @_;
    
    $timeDiff = timeInSec($time1) - timeInSec($time2);
    if ($timeDiff < 0)
    {
        return (-$timeDiff);
    }
    return $timeDiff;
}


#******************************************************************************
# FUNCTION
#  timeInSec
# DESCRIPTION
#  time in sec.
# PARAMETERS
#  para - time in localtime array format
# RETURNS
#  time in sec.
#******************************************************************************
sub timeInSec()
{
    my @daysInMon = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
    my $sec = $_[0][0];
    my $min = $_[0][1];
    my $hour = $_[0][2];
    my $day = $_[0][3];
    my $mon = $_[0][4]+1;
    my $year = $_[0][5];
    my $timeInSec;    
    
    if (isLeapYear($year+1900))
    {
        $daysInMon[1] = 29;
        $timeInSec = (((($year*366+$mon*$daysInMon[$mon-1]+$day)*24 + $hour)*60 + $min)*60 + $sec);
    }
    else
    {
        $timeInSec = (((($year*365+$mon*$daysInMon[$mon-1]+$day)*24 + $hour)*60 + $min)*60 + $sec);
    }
    return $timeInSec;
}


#******************************************************************************
# FUNCTION
#  isLeapYear
# DESCRIPTION
#  is input year leap-year
# PARAMETERS
#  year
# RETURNS
#  leap-year or not
#******************************************************************************
sub isLeapYear()
{
    my $year = $_[0];
    
    if (($year%4 == 0) && ($year%100 != 0))
    {
        return 1;
    }
    return 0;
}
