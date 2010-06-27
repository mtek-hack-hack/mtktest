#!/usr/bin/perl -w

($#ARGV < 4) && die "Too few ARGUMENTS!\n";
$relDir = $ARGV[0];
$en_file = $ARGV[1];
$dis_file = $ARGV[2];
$if_fil = uc($ARGV[3]);
$log_fil = uc($ARGV[4]);
$dir_file = $ARGV[5];
if (defined($ARGV[6])) {
	$not_remove_MTK_INTERNAL_MMI_FEATURES = 1;
} else {
	$not_remove_MTK_INTERNAL_MMI_FEATURES = 0;
}

(!-d $relDir) && die "Release Directory $relDir does NOT exist\n";
(!-e $en_file) && die "Enable file $en_file does NOT exist\n";
(!-e $dis_file) && die "Disable file $dis_file does NOT exist\n";
($if_fil ne "TRUE") && ($if_fil ne "FALSE") && die "if_fil $if_fil should be TRUE/FALSE\n";
($log_fil ne "TRUE") && ($log_fil ne "FALSE") && die "log_fil $log_fil should be TRUE/FALSE\n";
(!-e $dir_file) && die "Removal Dir file $dir_file does NOT exist\n";
system "del ~removalDir.log";
open(dirH,$dir_file);
while(<dirH>){
	chomp($_);
	if (!(index($_,"#") == 0) && length($_) >= 1){		
		if (index($_,"\\") == 0){
			$_ =~ s/\\//;
		}
		if ($_ =~ /.+(\\)$/) {
			chop($_);
		}	
		$_ = $relDir . "\\" . $_;
		if(!-e $_) {
			system "echo WARNING! $_ doesn't exist. >> ~removalDir.log";
			print "WARNING! $_ doesn't exist.\n";
		}
		push(@removalDir,$_);
	}
}
close(dirH);

#@thedirs = ($relDir);

@allfiles = qw();

foreach $specifyDir (@removalDir) {
	if (-d $specifyDir) {
		if (opendir(SUBDIRS, $specifyDir)) {
    	@childdirs = sort readdir(SUBDIRS);
    	closedir(SUBDIRS);
  	} else {
    	warn "Could not open $specifyDir\n";
    	next;
  	}
  	foreach $f (@childdirs) {
    	next if ($f eq ".");
    	next if ($f eq "..");
    	next if (($f eq "tools") && ($specifyDir eq $relDir));
    	$fname = $specifyDir . "\\". $f;
    	if (-d $fname) {
      	push(@removalDir, $fname);
    	} elsif ($f =~ /\.(c|h|cpp|hpp|s|java|txt)$/i) {
      	next if (lc($f) eq "t9.h");
      	if ($f =~ /txt$/i) {
      		if ($f =~ /^scat/i) {
      			push(@allfiles, $fname);
      		}
      	} else {
      		push(@allfiles, $fname);
      	}
    	}
  	}
	}	elsif (-e $specifyDir) {
		if ($specifyDir =~ /\.(c|h|cpp|hpp|s|java|txt)$/i) {
      	next if (lc($specifyDir) eq "t9.h");
      	if ($specifyDir =~ /txt$/i) {
      		if ($specifyDir =~ /^scat/i) {
      			push(@allfiles, $specifyDir);
      		}
      	} else {
      		push(@allfiles, $specifyDir);
      	}
    } else {
    	warn "$specifyDir is not a code-removal-format(.c,.h,.cpp,.hpp,.s,.java) file.";
    	next;
    }
	}
}

#foreach $tarDir (@thedirs) {
#	print "$tarDir\n";
#  if (opendir(OBJDIRS, $tarDir)) {
#    @syndirs = sort readdir(OBJDIRS);
#    closedir(OBJDIRS);
#  } else {
#    warn "Could not open $tarDir\n";
#    next;
#  }
#  foreach $f (@syndirs) {
#    next if ($f eq ".");
#    next if ($f eq "..");
#    next if (($f eq "tools") && ($tarDir eq $relDir));
#    $fname = $tarDir . "\\". $f;
#    if (-d $fname) {
#      push(@thedirs, $fname);
#    } elsif ($f =~ /\.(c|h|cpp|hpp|s)$/i) {
#      next if (lc($f) eq "t9.h");
#      push(@allfiles, $fname);
#    }
#  }
#}

$tmpFile = "$relDir\\~traverseFile.c";
foreach $f (@allfiles) {
  if ($if_fil eq "TRUE") {
    print("$f\n");
    #print("\tif_fil\n");
    system("perl tools\\if_fil.pl $f $en_file $dis_file $tmpFile");
    system("move /y $tmpFile $f > nul");
  }
  if ($log_fil eq "TRUE") {
    #print("\tlog_fil\n");
    system("perl tools\\log_fil.pl $f > nul");
  }
  $writeFile = 1;
  if (($f =~ /mmi_features.h/i) && ($not_remove_MTK_INTERNAL_MMI_FEATURES =~ /0/)) {
  	open(F, "<$f");
  	open(W, ">.\\~mmi_features.h");
  	while(<F>){
  		if (($_ =~ /ifdef/i) && ($_ =~ /MTK_INTERNAL_MMI_FEATURES/i)) {
  			$writeFile = 0;
  		}
  		if($writeFile == 1) {
  			print W $_;
  		}  		
  	  if (($_ =~ /endif/i) && ($_ =~ /MTK_INTERNAL_MMI_FEATURES/i)) {
  			$writeFile = 1;
  		}
  	}
  	close(W);
  	close(F);
  	system("move /Y .\\~mmi_features.h $f");
  }
}

exit 0;

