#!/usr/bin/perl
use Net::SMTP;
	
#********************************************************************
# Global Vars for mail notification
#********************************************************************
my $Sender = uc(getlogin());;
my $ToList = "MBJ06037".","."MBJ06026";
my $CcList = "";
my $smtp_server = "mtksmtp2.mtk.com.tw"; #172.21.100.20(192.168.160.24)
my $ts_name = $ENV{"COMPUTERNAME"};
my $user_domain = $ENV{"USERDOMAIN"};


print "*******************************************\n";
print " Start checking MTK build environment......\n";
print "*******************************************\n";
#********************************************************************
# checking OS version
#********************************************************************
if($ENV{OS} eq "Windows_NT")
{
	print "OS is Windows 2000 or XP. => [OK]\n";
}
else
{
	if ($user_domain =~ /MBJ/i)
	{
		my $subject = "[$ts_name: Compile Enviroment error]";
		my $content = "Your OS should be Windows2000 or above!\n";
		&SendEmailNotify($ToList, $CcList, $subject, $content);
	}
	print "Your OS should be Windows2000 or above!\n";
	exit(1);
}

#********************************************************************
# checking ARM installation path
#********************************************************************
&USAGE() if ($#ARGV != 0);
my $optiondir = "$ARGV[0]\\option.mak";
open(OPTION,"<$optiondir");
if($ENV{ARMHOME} =~ /program\sFiles/i)
{
	$ENV{ARMHOME} =~ s/m\sFiles/~1/i;	
}

while(<OPTION>)
{
	chomp;
	if(/DIR_ARM(\s*)=(\s*)(.*?ADSV1_2)+?/i)
	{
		my $arm_path = $3;
		if(lc($ENV{ARMHOME}) eq lc($arm_path))
		{
			print "ARM installation path is correct. => [OK]\n";
			last;
		}
		else
		{
			if ($user_domain =~ /MBJ/i)
			{
				my $subject = "[$ts_name: Compile Enviroment error]";
				my $content = "ARM installation path is inconsistent with the path defined in makefile[option.mak].\n" . 
								"Current ARM installation path: $ENV{ARMHOME}.\n" . 
								"In \"$optiondir\", ARM path is: $arm_path.\n" . 
								"\nThe different path will cause a compiling error!\n" . 
								"You should make them consistent\n";
				&SendEmailNotify($ToList, $CcList, $subject, $content);
			} 
			print "ARM installation path is inconsistent with the path defined in makefile[option.mak].\n";
			print "Current ARM installation path: $ENV{ARMHOME}.\n";
			print "In \"$optiondir\", ARM path is: $arm_path.\n";
			print "\nThe different path will cause a compiling error!\n";
			print "You should make them consistent\n";
			exit(1);
		}
	}
}
close(OPTION);

#********************************************************************
# checking ARM compiler version & build number
#********************************************************************
my $arm_compiler = 0;
foreach (split(/[\r\n]+/, `armcc -h 2>&1`))
{
	chomp;
	if(/\bADS1.2/i)
	{
		print "ARM version is correct. => [OK]\n";
		if(/\bBuild(\s)*(\d+)/)
		{
			if($2 >= 848)
			{
				print "The build number of ARM is correct. => [OK]\n";
				$arm_compiler = 1;
				last;
			}
			else
			{
				if ($user_domain =~ /MBJ/i)
				{
					my $subject = "[$ts_name: Compile Enviroment error]";
					my $content = "The build number of ARM should be at least 848!\n";
					&SendEmailNotify($ToList, $CcList, $subject, $content);
				}
				print "The build number of ARM should be at least 848!\n";
				exit(1);
			}
		}		
	}
	elsif(/\bRVCT/i)
	{
		print "ARM version is correct. => [OK]\n";
		print "The build number of ARM is correct. => [OK]\n";
		$arm_compiler = 1;
		last;
	}
	else
	{
		next;
	}
}

if($arm_compiler == 0)
{
	if ($user_domain =~ /MBJ/i)
	{
		my $subject = "[$ts_name: Compile Enviroment error]";
		my $content = "ARM should be ARM1.2 [Build 848](above) or RVCT!\n";
		&SendEmailNotify($ToList, $CcList, $subject, $content);
	} 
	print "ARM should be ARM1.2 [Build 848](above) or RVCT!\n";
	exit(1);
}

#********************************************************************
# checking ARM license
#********************************************************************
if ($ENV{"USERDOMAIN"} =~ /MBJ/i)
{
	my $arm_license = 0;
	my $arm_var_name = "ARMLMD_LICENSE_FILE";
	my @env_key = keys(%ENV);

	my $count = 0;
	foreach $_(@env_key)
	{
		if($_ =~ /$arm_var_name/i)
		{
			my @arm_var_value = split(";",$ENV{$_});
			for (my $i = 0; $i < @arm_var_value; $i++)
			{
				if ($ts_name =~ /^BJSTS\d\d$/i)
				{
					if (($arm_var_value[$i] =~ /^\s*C:\\Program Files\\ARM\\ADSv1_2\\licenses\\license\.dat$/i) ||
						($arm_var_value[$i] =~ /^\s*C:\\Progra~1\\ARM\\ADSv1_2\\licenses\\license\.dat$/i))
					{
						for (my $j = $i + 1; $j < @arm_var_value; $j++)
						{
							if ($arm_var_value[$j] =~ /^\s*8224\@bjslic01$/i)
							{
								print "ARM license setting is correct. => [OK]\n";
								$arm_license = 1;
								last;
							}
						}
					}
					if ($arm_license == 1)
					{
						last;
					}
					
				}
				else
				{
					if ($arm_var_value[$i] =~ /^\s*8224\@bjslic01$/i)
					{
						print "ARM license setting is correct. => [OK]\n";
						$arm_license = 1;
						last;
					}
				}
			}
	
			if ($arm_license == 0)
			{
				my $subject = "[$ts_name: Compile Enviroment error]";
				my $content = "Please checking your ARM license setting!\n";
				&SendEmailNotify($ToList, $CcList, $subject, $content);
				print "Please checking your ARM license setting!\n";
				exit(1);
			}
			else
			{
				last;
			}
	  	}
	  
		$count++;
		if($count == ($#env_key+1))
		{
			my $subject = "[$ts_name: Compile Enviroment error]";
			my $content = "Please checking your ARM license setting!\n";
			&SendEmailNotify($ToList, $CcList, $subject, $content);
			print "Please checking your ARM license setting!\n";
			exit(1);
		}
	}
}
#********************************************************************
# checking Active perl version
#********************************************************************
if($] >= 5.008006)
{
	print "Perl version is $] or above. => [OK]\n";
}
else
{
	if ($user_domain =~ /MBJ/i)
		{
		my $subject = "[$ts_name: Compile Enviroment error]";
		my $content = "Perl version is too low.\n";
		&SendEmailNotify($ToList, $CcList, $subject, $content);
	} 
	print "Perl version is too low.\n";
	exit(1);
}

#********************************************************************
# checking shell(modification)
#********************************************************************
my @path = split(";",$ENV{"PATH"});

foreach my $path (@path)
{
	if(-d $path)
	{
		$path = "\"$path\""; 
		open(TEMPHANDLE,"<dir /B $path |");
		while(<TEMPHANDLE>)
		{
			chomp;			
			if($_ =~ /^sh\.exe\b/i)
			{
			    if ($user_domain =~ /MBJ/i)
                {
                    my $subject = "[$ts_name: Compile Enviroment error]";
	                my $content = "sh.exe founded in: $path\nplease remove it\n";
	                &SendEmailNotify($ToList, $CcList, $subject, $content);
	            } 
				print "sh.exe founded in: $path\nplease remove it\n";
				exit(1);
			}
		}
		close(TEMPHANDLE);
	}
}
print "Shell is cmd.exe. => [OK]\n";

#********************************************************************
# checking Excel version
#********************************************************************
use Win32::OLE;
my $excel = Win32::OLE->new('excel.Application');
if($excel->version >= 9)
{
	print "Excel version is 2000 or above. => [OK]\n";
}
else
{
	if ($user_domain =~ /MBJ/i)
	{
		my $subject = "[$ts_name: Compile Enviroment error]";
		my $content = "Your Excel should be 2000+!\n";
		&SendEmailNotify($ToList, $CcList, $subject, $content);
	}
	print "Your Excel should be 2000+!\n";
	exit(1);
}

print "*******************************************\n";
print "      MTK build environment is ready!\n";
print "*******************************************\n";

sub SendEmailNotify
{
	my ($to_list, $cc_list, $mail_subject, $mail_content) = @_;
	my $msg = <<__EOFNOTIFY
To: $to_list
Cc: $cc_list
Subject: $mail_subject
From: $Sender

Dear All,

$mail_content

Best Regards,

__EOFNOTIFY
;
    my $smtp = Net::SMTP->new($smtp_server);
	$smtp->mail($Sender);
	map { $smtp->to($_); } split(/,/, $to_list);
	map { $smtp->cc($_); } split(/,/, $cc_list);
	$smtp->data($msg);
	$smtp->quit;
}


sub USAGE
{
  print <<"__EOFUSAGE";

USAGE: chk_env Option_MF_Path
__EOFUSAGE
  exit 1;
}