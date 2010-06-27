#!/usr/bin/perl -w

($#ARGV < 4) && die "Too few ARGUMENTS!\n";
$relDir = $ARGV[0];
$en_file = $ARGV[1];
$dis_file = $ARGV[2];
$if_fil = uc($ARGV[3]);
$log_fil = uc($ARGV[4]);

(!-d $relDir) && die "Release Directory $relDir does NOT exist\n";
(!-e $en_file) && die "Enable file $en_file does NOT exist\n";
(!-e $dis_file) && die "Disable file $dis_file does NOT exist\n";
($if_fil ne "TRUE") && ($if_fil ne "FALSE") && die "if_fil $if_fil should be TRUE/FALSE\n";
($log_fil ne "TRUE") && ($log_fil ne "FALSE") && die "log_fil $log_fil should be TRUE/FALSE\n";
@thedirs = ($relDir);

@allfiles = qw();
foreach $tarDir (@thedirs) {
  if (opendir(OBJDIRS, $tarDir)) {
    @syndirs = sort readdir(OBJDIRS);
    closedir(OBJDIRS);
  } else {
    warn "Could not open $tarDir\n";
    next;
  }
  foreach $f (@syndirs) {
    next if ($f eq ".");
    next if ($f eq "..");
    next if (($f eq "tools") && ($tarDir eq $relDir));
    $fname = $tarDir . "\\". $f;
    if (-d $fname) {
      push(@thedirs, $fname);
    } elsif ($f =~ /\.(c|h|cpp|hpp|s)$/i) {
      next if (lc($f) eq "t9.h");
      push(@allfiles, $fname);
    }
  }
}

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
}

exit 0;

