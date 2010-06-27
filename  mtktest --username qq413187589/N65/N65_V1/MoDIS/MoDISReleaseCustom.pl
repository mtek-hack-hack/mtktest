#!/usr/bin/perl
use ANSI;
use createMoDIS;
$|=1;
$ENV{PERLIO}="crlf";

$relMode = "Debug";
while ($#ARGV != -1) {
  if (lc($ARGV[0]) eq "-release") {
    $relMode = "Release";
  } elsif (lc($ARGV[0]) eq "-debug") {
    $relMode = "Debug";
  }
  shift(@ARGV);
}

if((!-d "MoDIS")||(!-d "MoDIS\\${relMode}")||(!-e "MoDIS\\${relMode}\\MoDIS.exe")) {
  warn "MoDIS\\${relMode}\\MoDIS.exe does NOT exist\nWe do NOT recommend you to use this utility\n";
  sleep 10;
}
###############################################################
# global variable
###############################################################
my @libs;
my %selected_libs;
my %default_libs;
###############################################################
# default libs
###############################################################
$default_libs{'MoDIS'} = 1;
###############################################################
# search the all library
###############################################################

opendir D,"." or die "Can't opendir this directory\n";
my @dirs = sort readdir(D);
closedir D;

foreach my $i (@dirs) {
	next if($i eq '.');
	next if($i eq '..');
	next if(exists $default_libs{$i});
	next if((!-d $i)||(!-d "${i}\\${relMode}")||(!-e "${i}\\${relMode}\\${i}.lib"));
	push @libs,$i;
}

###############################################################
# User choose the libs
###############################################################
while(1)
{
	print "Select the librarys\n";
	for(my $i=0;$i<=$#libs;$i++)
	{
		my $lib = $libs[$i];
		print "\n" if (($i %4) == 0);
		print "\e[1;33m" if($selected_libs{$lib});
		printf "[%2d] %-14s",$i+1,$lib;
		print "\e[0m";
	}
	print "\e[1;31m";
	print "\n\n[GO] Start to slim modis		[L] Load the last setting";
	print "\nChoose the library which you need to debug :";
	print "\e[0m";
	my $item = <>;
	$item =~ s/^\s+//gs;
	$item =~ s/\s+$//gs;
	$item = lc($item);
	last if($item eq 'go');
	if($item eq 'l')
	{
		open F,"<_MoDISReleaseCustom.ini" or die "Can't open _MoDISReleaseCustom.ini";
		my @tmp = <F>;
		close F;
		undef %selected_libs;
		foreach my $t (@tmp)
		{
			$t =~ s/\s+$//gs;
			$selected_libs{$t} = 1;
		}
	}

	if(0< $item  && $item <= $#libs+1)
	{
		if(exists $selected_libs{$libs[$item-1]})
		{
			delete $selected_libs{$libs[$item-1]};
		}
		else
		{
			$selected_libs{$libs[$item-1]}=1;
		}
	}
}

###############################################################
# Save the choose to _MoDISReleaseCustom.ini
###############################################################
open F,">_MoDISReleaseCustom.ini" or die "Can't open _MoDISReleaseCustom.ini";
syswrite F,join("\n",sort (keys %selected_libs));
close F;

###############################################################
# Generate Main workspace
###############################################################
{
	my %WIN32_COMPILE_OPTION;
	my $list;
	for(my $i=0;$i<=$#libs;$i++)
	{
		my $lib = $libs[$i];
		if(!exists $selected_libs{$lib})
		{
			if (-e "${lib}\\${relMode}\\${lib}.lib") {
				$list .= "../$lib/${relMode}/$lib.lib\n";
			} else {
				warn "${lib}\\${relMode}\\${lib}.lib does NOT exist\n";
			}
		}
	}
	## create MoDIS1.dep file
	createMoDIS::update_lib_project(
			"MoDIS/MoDIS.DSP",
			"MoDIS/MoDIS_Custom.dsp",
			$list);

	my @tmp = (sort keys %selected_libs);
	createMoDIS::create_workspace(
		"MoDIS_Custom.dsw",
		\@tmp
	);
}

