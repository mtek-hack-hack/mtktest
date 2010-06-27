#!/usr/local/bin/perl

# 
# Copyright Statement:
# --------------------
# This software is protected by Copyright and the information contained
# herein is confidential. The software may not be copied and the information
# contained herein may not be used or disclosed except with the written
# permission of MediaTek Inc. (C) 2005
# 
# BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
# NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
# SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
# 
# BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
# LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
# 
# THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
# WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
# LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
# RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
# THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
# 

use Net::SMTP;

$ENV{"MoDIS"} = 'AutoPower';
$lsf_dir = "E:\\temp\\mcu";
$allArgv = join(" ", @ARGV);
@orgARGV = @ARGV;
$custom = "MTK";
$ini = "make.ini";
$enINI = 0;
($enINI = 1) if (($ENV{"USERDOMAIN"} =~ /MTK/i) || ($ENV{"USERDOMAIN"} =~ /PMT/i));
@projects = qw(l1s gsm gprs basic umts);
chomp($cwd = `cd`);
$skipIni = 0;
$computerName = $ENV{"COMPUTERNAME"};
$curr_usr = getlogin() or die "can't get your login name\n$!\n";
$ENV{"atMoDIS_LSF_remote"} = "$cwd\\MoDIS";

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /^(c|cu|cus|cust|custo|custom)=(\w+)/i) {
    $custom = $2;
    last;
  } elsif ($ARGV[0] =~ /^(p|pl|pla|plat|platf|platfo|platfor|platform)=(\w+)/i) {
    last;
  } elsif (($ARGV[0] !~ /-(modis|debug|release)/i) && ($ARGV[0] !~ /^-(o|op|opt)=(.*)$/i)) {
    foreach $m (@projects) {
      if ($ARGV[0] =~ /\b$m\b/i) {
        shift(@ARGV);
        $skipIni = 1;
        last;
      }
      if ($ARGV[1] =~ /\b$m\b/i) {
        if ($ARGV[0] !~ /^mt6\d\d\d\w?$/i) {
          $custom = $ARGV[0];
        }
        shift(@ARGV);
        shift(@ARGV);
        $skipIni = 1;
        last;
      }
    }
    if (($skipIni == 0) && ($enINI == 1) && (-e "${cwd}\\$ini")) {
      system("copy /y ${cwd}\\$ini ${lsf_dir}\\$ini > nul");
      open (FILE_HANDLE, "<$ini") or die "cannot open $ini\n";
      while (<FILE_HANDLE>) {
        if (/^(\S+)\s*=\s*(\S+)/) {
          $keyname = $1;
          $${keyname} = $2;
        }
      }
      close FILE_HANDLE;
      print "custom=$custom; plat=$plat; project=$project\n";
    }
  }
  shift(@ARGV);
}
($custom = "MTK") if ($custom =~ /^mt6\d\d\d\w?$/i);
print("in m_cp2lsf.pl\n");

#**********************************************************************************************
# Decide lsf_dir
#**********************************************************************************************
if ($custom eq "MTK") {
   if($project =~ /GSM/i) {
     $verno_file = "Verno.bld";
   } else {
     $verno_file = "Verno_classb.bld";
   }
} else {
     $verno_file = "Verno_$custom.bld";
}

system("md $lsf_dir\\make") unless (-e "$lsf_dir\\make");
system("copy /y $cwd\\make\\$verno_file $lsf_dir\\make\\$verno_file > nul");
open (VERNO_FILE, "<$lsf_dir\\make\\$verno_file") or die "cannot open $lsf_dir\\make\\$verno_file\n";
$backup = $/;
undef $/;
$fcontent = <VERNO_FILE>;
$/ = $backup;

if($fcontent =~ /VERNO\s*=\s*MAUI\.([^\s]+)/i){
    $verno = $1;
    if($verno =~ /^W\d\d\.\d\d$/){ # for MainTrunk -> match Wxx.xx
        $branch = "MAUI"; # MAUI
    }
    if($verno =~ /^(\w+)\.W\d\d\.\d\d.MP/){ # for MP branch -> match 06B.Wxx.xx.MP
        $branch = "${1}MP"; # 06BMP
    }
    if($verno =~ /^(\w+)\.W\d\d\.\d\d$/){ # for ABC branch -> match 06B.Wxx.xx
        $branch = "$1"; # 06B
    }
}
close VERNO_FILE;

$branch = 'mcu' unless ($branch);

if (-e "E:\\temp\\$branch") {
    $lsf_dir = "E:\\temp\\$branch";
} elsif ($branch eq 'MAUI') {
    $lsf_dir = "E:\\temp\\$branch";
    print "md $lsf_dir\n";
    system("md $lsf_dir");
    $is_new_dir = 1;
} elsif ($branch) {
	my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
	$year = sprintf("%02d",($year+1900)%100);
	
	if ($verno =~ /$year\w{1}\.W\d\d\.\d\d/i) { # match Wxx.xx
		$lsf_dir = "E:\\temp\\$branch";
		print "md $lsf_dir\n";
		system("md $lsf_dir");
		$is_new_dir = 1;
	}
}

print "\nTemp codebase is at $lsf_dir in $computerName\n";

if ($is_new_dir) {
    foreach (split(/[\r\n]+/, `dir $lsf_dir`)) {
  	    if (/([0-9,]+)\s*(bytes free)$/i) {
  	        $free_space = "$1 bytes";
  	    }
    }
    
    if (-e "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini") {
    	my %BM_conf = iniToHash("\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini");
    	$email_list = $BM_conf{'M_CP2LSF'}->{'CREATE_FOLDER_NOTIFY_LIST'} . ",$curr_usr";
    } else {
    	$email_list = $curr_usr;
    }
	
    $smtp = Net::SMTP->new('mtksmtp2.mtk.com.tw');
	$smtp->mail($curr_usr);
	map { $smtp->recipient($_); } split(/,/, $email_list);
	$smtp->data();
	$smtp->datasend("Subject: [Script Notify] $computerName had create a new folder $lsf_dir, and free disk space is $free_space\n");
	$smtp->quit;
}
#**********************************************************************************************
# End of decide lsf_dir
#**********************************************************************************************


#**********************************************************************************************
# Check disk free space
#**********************************************************************************************
if (-e "\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini") {
	my %BM_conf = iniToHash("\\\\mtkrfs01\\Public1\\3rd_party\\Scripts\\BM_conf.ini");
    $email_list = $BM_conf{'M_CP2LSF'}->{'UNDER_THRESHOLD_NOTIFY_LIST'} . ",$curr_usr";
    $threshold  = $BM_conf{'M_CP2LSF'}->{'THRESHOLD'};
} else {
   	$email_list = $curr_usr;
   	$threshold  = 20*1024*1024*1024;
}
$folder_status = `dir E:\\temp`;

foreach (split(/[\r\n]+/, $folder_status)) {
    if (/([0-9,]+)\s*(bytes free)$/i) {
  	    $free_space = $1;
  	    $free_space =~ s/,//gi
  	}
}

if ($free_space < $threshold) {
    $del_folder = '';
    
    # If free space is less than threshold, try to delete 'build' and 'custom_release' folders
    @lsf_temp_dir = <e:\\temp\\*>;
    foreach (@lsf_temp_dir)
    {
        if (-d $_)
	    {
		    if (-d "$_\\build") {
		        system("rd /s /q $_\\build");
		        $del_folder .= "$_\\build\n";
		    }
		    if (-d "$_\\custom_release") {
		        system("rd /s /q $_\\custom_release");
		        $del_folder .= "$_\\custom_release\n";
		    }
	    }
    }
    
    # After delete 'build' and 'custom_release', check free space again
    foreach (split(/[\r\n]+/, `dir E:\\temp`)) {
        if (/([0-9,]+)\s*(bytes free)$/i) {
  	        $latest_free_space = $1;
  	        $latest_free_space =~ s/,//gi
  	    }
    }
	
    $smtp = Net::SMTP->new('mtksmtp2.mtk.com.tw');
	$smtp->mail($curr_usr);
	map { $smtp->recipient($_); } split(/,/, $email_list);
	$smtp->data();
	$smtp->datasend("Subject: [Script Notify] $computerName :: $lsf_dir  free disk space is under threshold.\n");
	$smtp->datasend("The free disk space is $free_space bytes, and below is the folder status.\n\n");
	$smtp->datasend("=========================================================================\n\n");
    $smtp->datasend("$folder_status\n");
    $smtp->datasend("=========================================================================\n\n\n");
    $smtp->datasend("After script try to delete below folders, the latest free disk space is $latest_free_space bytes.\n\n");
    $smtp->datasend("$del_folder\n");
	$smtp->quit;
}
#**********************************************************************************************
# End of Check disk free space
#**********************************************************************************************


system("attrib -a -r  ${lsf_dir}\\*.* /s /d");
print("rd /s /q ${lsf_dir}\\build\n");
system("rd /s /q ${lsf_dir}\\build");

if ($allArgv =~ /new_modis/i) {
  if (-d "${cwd}\\build\\${custom}\\log") {
    print("robocopy ${cwd}\\build\\${custom}\\log ${lsf_dir}\\build\\${custom}\\log /MIR /XF robo*.log /R:10\n");
    system("robocopy ${cwd}\\build\\${custom}\\log ${lsf_dir}\\build\\${custom}\\log /MIR /XF robo*.log /R:10 /A-:RA");
  } else {
  	print("${cwd}\\build\\${custom}\\log does NOT exist!\nPlease run target new firstly until resgen\n");
  	exit 0;
  }
}

if (($allArgv =~ /new_modis/i) || ($allArgv =~ /-modis/i)) {
  print("robocopy $cwd $lsf_dir /MIR /XD ${cwd}\\build /XF robo*.log TStoCF.log /LOG:TStoCF.log /R:10\n");
  system("robocopy $cwd $lsf_dir /MIR /XD ${cwd}\\build /XF robo*.log TStoCF.log /LOG:TStoCF.log /R:10 /A-:RA");
  system("xcopy $cwd\\TStoCF.log $lsf_dir /Y /Q > nul");
} else {
  print("robocopy $cwd $lsf_dir /MIR /XD ${cwd}\\build ${cwd}\\MoDIS\\ /XF robo*.log TStoCF.log /LOG:TStoCF.log /R:10\n");
  system("robocopy $cwd $lsf_dir /MIR /XD ${cwd}\\build ${cwd}\\MoDIS\\ /XF robo*.log TStoCF.log /LOG:TStoCF.log /R:10 /A-:RA");
  system("xcopy $cwd\\TStoCF.log $lsf_dir /Y /Q > nul");
}

chdir("e:");
chdir($lsf_dir);
system("set > lsf_env.log");
system("attrib +r ${lsf_dir}\\MoDIS\\MoDIS.ncb") if ((-d $lsf_dir) && (-e "${lsf_dir}\\MoDIS\\MoDIS.ncb"));
print("perl ${lsf_dir}\\make2.pl -lsf @orgARGV\n");
system("perl ${lsf_dir}\\make2.pl -lsf @orgARGV");
print("perl ${lsf_dir}\\mtk_tools\\clean_obj.pl\n") if (-f "${lsf_dir}\\mtk_tools\\clean_obj.pl");
system("perl ${lsf_dir}\\mtk_tools\\clean_obj.pl") if (-f "${lsf_dir}\\mtk_tools\\clean_obj.pl");
print("perl ${lsf_dir}\\tools\\clean_obj.pl\n") if (-f "${lsf_dir}\\tools\\clean_obj.pl");
system("perl ${lsf_dir}\\tools\\clean_obj.pl") if (-f "${lsf_dir}\\tools\\clean_obj.pl");
print "\nrobocopy $lsf_dir $cwd /E /XF robo*.log /XD ${lsf_dir}\\build ${lsf_dir}\\MoDIS /LOG:robo2.log /R:10 at ", &CurrTimeStr;
system("robocopy $lsf_dir $cwd /E /XF robo*.log /XD ${lsf_dir}\\build ${lsf_dir}\\MoDIS /LOG:robo2.log /R:10");
system("xcopy ${lsf_dir}\\robo2.log $cwd /Y /Q > nul");


if ($allArgv !~ /new_modis/i) {
  print "\nrobocopy ${lsf_dir}\\build\\$custom ${cwd}\\build\\$custom /MIR /XF robo*.log /LOG:robo3.log /R:10 at ", &CurrTimeStr;
  system("robocopy ${lsf_dir}\\build\\$custom ${cwd}\\build\\$custom /MIR /XF robo*.log /LOG:robo3.log /R:10");
  system("xcopy ${lsf_dir}\\robo3.log $cwd /Y /Q > nul");
}

if (($allArgv =~ /new_modis/i) || ($allArgv =~ /-modis/i)) {
	print "\nrobocopy ${lsf_dir}\\MoDIS ${cwd}\\MoDIS /MIR /XF robo*.log /LOG:robo4.log /R:10 at ", &CurrTimeStr;
  system("robocopy ${lsf_dir}\\MoDIS ${cwd}\\MoDIS /MIR /XF robo*.log /LOG:robo4.log /R:10");
  system("xcopy ${lsf_dir}\\robo4.log $cwd /Y /Q > nul");
  system("attrib +r ${cwd}\\MoDIS\\MoDIS.ncb") if ((-d $cwd) && (-e "${cwd}\\MoDIS\\MoDIS.ncb"));
}

print "\nrd /s /q ${lsf_dir}\\build\\\n";
system("rd /s /q ${lsf_dir}\\build\\");

print "\nTemp codebase is at $lsf_dir in $computerName. Perl version is $]\n";
print "\nm_cp2lsf.pl end at ", &CurrTimeStr, "\n";

exit 0;

sub CurrTimeStr {
  my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
  return (sprintf "%4.4d/%2.2d/%2.2d %2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min);
}

#usage:
#      my %hash=iniToHash('/tmp/myini.ini');
#      print $hash{'TITLE'}->{'Name'},"\n";
#
sub iniToHash{
    open(MYINI, $_[0]);
    my %hash;
    my $hashref;
    
    while(<MYINI>)
    {
        next if ((/^\s*$/) || (/^\s*#/));
        if (/^\s*\[(.+)\]/)
        {
            $hashref = $hash{$1} ||= {};
        }
        elsif (/^\s*(\S+)\s*=\s*(.+)\s*$/)
        {
            $hashref->{$1} = $2;
        }
        elsif (/^\s*(\S+)\s*\+=\s*(.+)\s*$/)
        {
        	$hashref->{$1} = $hashref->{$1} . " $2";
        }
    }
    
    close MYINI;
    return %hash;
}
