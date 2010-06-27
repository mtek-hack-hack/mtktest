#!/usr/bin/perl

$myname = "gencodegenbat";
&Usage if ($#ARGV == -1);
$thefile = $ARGV[0];
die "$thefile does NOT exist\n" if (!-e $thefile);
($thefile =~ /make\\(\w+)_(\w+).mak/i) || die "The Makefile format should be make\\custom_proj.mak\n";
$customer = uc($1);
$mode = uc($2);
($customer = "MTK") if ($customer =~ /^MT\d\d\d\d\w?$/i);
###############################################################
# Read from Makefile
###############################################################
open (FILE_HANDLE, "<$thefile") or die "cannot open $thefile\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $thefile!\n";
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;
die "Could not recognive PLATFORM(MT62) = $platform in $thefile!\n" if ($platform !~ /MT62/i);

$optMake = "..\\build\\$customer\\log\\infomake.log";
open (FILE_HANDLE, "<$optMake") or die "cannot open $optMake\n";
while (<FILE_HANDLE>) {
  chomp;
  s/\s+/ /g;
  s/\s+$//;
  s/^\s+//;
  if (/^(\S+)\s*=\s*(.+)$/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $optMake!\n";
    $${keyname} = $2;
  }
}
close FILE_HANDLE;

$is_cl = system("cl > nul 2>&1");
die "Could NOT execute \"cl\"!\nPlease help to add into PATH environment!\n" if ($is_cl != 0);
###############################################################
# Read ini values
###############################################################
push @trc_set, split('\s+',$comp_trace_defs);
push @trc_set, split('\s+',$enable_trcs) if ($enable_trcs !~ /^\s*$/);
#die join(' ', @trc_set), '\n';

die "comm folder does NOT exist!\n" if (!-d "comm");
chdir("comm");

$relDir = "..\\..";
$reltst = "$relDir\\tst";
$dbfolder = "${reltst}\\database_modis";
$pstrace_db = "${dbfolder}\\pstrace_db";

$parsedb = "${reltst}\\database\\msglog_db\\parse_db.c";
$pridb = "${dbfolder}\\msglog_db\\pri.db";
$custparsedb = "${reltst}\\database\\msglog_db\\custom_parse_db.c";
$custpridb = "${dbfolder}\\msglog_db\\custom_pri.db";
$appparsedb = "${reltst}\\database\\msglog_db\\app_parse_db.c";
$apppridb = "${dbfolder}\\msglog_db\\app_pri.db";

$cgen = "$relDir\\tools\\cgen.exe";
die "$cgen does NOT exist!\n" if (!-e $cgen);

if ($mode eq "UMTS") {
  $chk_pstrace_db = "${reltst}\\database_classb_umts\\pstrace_db";
  chdir("$relDir\\uas") if (-d "$relDir\\uas");
  $res = system("uas_generate.bat");
  die "uas_generate.bat failed ==> $res\n" if ($res != 0);
  chdir("..\\MoDIS\\comm");
  system("copy ${reltst}\\database_classb_umts\\uniontag.txt ${reltst}\\database\\uniontag.txt");
} elsif ($mode eq "GPRS") {
  $chk_pstrace_db = "${reltst}\\database_classb\\pstrace_db";
} else {
  $chk_pstrace_db = "${reltst}\\database\\pstrace_db";
}

system("del /Q $pstrace_db") if (-d $pstrace_db);
system("md $dbfolder") if (!-d $dbfolder);
system("md $dbfolder\\gv") if (!-d "$dbfolder\\gv");
system("md $pstrace_db") if (!-d $pstrace_db);
system("md ${dbfolder}\\msglog_db") if (!-d "${dbfolder}\\msglog_db");

if ($custom_release ne "TRUE") {
  print "cl -E \@comm.ini $parsedb > $pridb\n";
  $res = system("cl -E \@comm.ini $parsedb > $pridb");
  die "cl -E \@comm.ini $parsedb > $pridb failed ==> $res\n" if ($res != 0);
  print "cl -E \@comm.ini $custparsedb > $custpridb\n";
  $res = system("cl -E \@comm.ini $custparsedb > $custpridb");
  die "cl -E \@comm.ini $custparsedb > $custpridb failed ==> $res\n" if ($res != 0);
} else {
  print "cl -E \@comm.ini $custparsedb > $custpridb\n";
  $res = system("cl -E \@comm.ini $custparsedb > $custpridb");
  die "cl -E \@comm.ini $custparsedb > $custpridb failed ==> $res\n" if ($res != 0);
  if ($mtk_subsidiary eq "TRUE") {
  	  print "cl -E \@comm.ini $appparsedb > $apppridb\n";
  		$res = system("cl -E \@comm.ini $appparsedb > $apppridb");
  		die "cl -E \@comm.ini $appparsedb > $apppridb failed ==> $res\n" if ($res != 0);
  		
  		$res = system("$cgen -cm $dbfolder\\BPGUInfoCustom_pc_Src $dbfolder\\BPGUInfoCustomApp_pc $custpridb $dbfolder\\enumFileCustomSrc MoDIS $verno");
  		die "$cgen -cm $dbfolder\\BPGUInfoCustom_pc_Src $dbfolder\\BPGUInfoCustomApp_pc $custpridb $dbfolder\\enumFileCustomSrc MoDIS $verno ==> $res\n" if ($res != 0);
  		$res = system("$cgen -ap $dbfolder\\BPGUInfoCustomApp_pc_Src $dbfolder\\BPGUInfoCustom_pc_Src $apppridb $dbfolder\\enumFileCustomAppSrc MoDIS $verno $relDir\\plutommi");
  		die "$cgen -ap $dbfolder\\BPGUInfoCustomApp_pc_Src $dbfolder\\BPGUInfoCustom_pc_Src $apppridb $dbfolder\\enumFileCustomAppSrc MoDIS $verno $relDir\\plutommi ==> $res\n" if ($res != 0);
  } else {
  	$res = system("$cgen -cm $dbfolder\\BPGUInfoCustomApp_pc_Src $dbfolder\\BPGUInfoCustomApp_pc $custpridb $dbfolder\\enumFileCustomAppSrc MoDIS $verno $relDir\\plutommi");
  	die "$cgen -cm $dbfolder\\BPGUInfoCustomApp_pc_Src $dbfolder\\BPGUInfoCustomApp_pc $custpridb $dbfolder\\enumFileCustomAppSrc MoDIS $verno $relDir\\plutommi ==> $res\n" if ($res != 0);
	}
}


foreach $trc (@trc_set) {
  next if (($trc eq "\\") || ($trc eq ""));
  #print "Check \"$trc\"\n";
  #sleep 1;
  next if ($trc !~ /\\(\w+)\.h/);
  next if ($1 =~ /^l1/i);
  next if (!-e "${chk_pstrace_db}\\${1}.ptr");
  print "Processing $trc\n";
  #sleep 1;
  $res = system("cl -E \@comm.ini $relDir\\$trc > $pstrace_db\\${1}.ptr");
  warn "cl -E \@comm.ini $relDir\\$trc > $pstrace_db\\${1}.ptr failed ==> $res\n" if ($res != 0);
}

if ($custom_release ne "TRUE") {
  $pc_cnf = "$reltst\\database\\pc_cnf";
  $res = system("$cgen -c $pridb $pc_cnf $pc_cnf $dbfolder\\tgt_cnf.int $dbfolder\\enumFile MoDIS $verno");
  die "$cgen -c $pridb $pc_cnf $pc_cnf $dbfolder\\tgt_cnf.int $dbfolder\\enumFile MoDIS $verno ==> $res\n" if ($res != 0);
  $res = system("$cgen -ps $pstrace_db\\BPInfo_pc $dbfolder\\tgt_cnf.int  $pstrace_db $pstrace_db\\ps_trace.h");
  die "$cgen -ps $pstrace_db\\BPInfo_pc $dbfolder\\tgt_cnf.int  $pstrace_db $pstrace_db\\ps_trace.h ==> $res\n" if ($res != 0);
  $res = system("$cgen -gv $dbfolder\\BPGInfo_pc $pstrace_db\\BPInfo_pc $dbfolder\\gv\ ${reltst}\\src\\gvTbl_modis.c");
  die "$cgen -gv $dbfolder\\BPGInfo_pc $pstrace_db\\BPInfo_pc $dbfolder\\gv\ ${reltst}\\src\\gvTbl_modis.c ==> $res\n" if ($res != 0);
  system("del $pstrace_db\\BPInfo_pc");
  $res = system("$cgen -un $dbfolder\\BPGUInfo_pc $dbfolder\\BPGInfo_pc ${reltst}\\database\\uniontag.txt");
  die "$cgen -un $dbfolder\\BPGUInfo_pc $dbfolder\\BPGInfo_pc ${reltst}\\database\\uniontag.txt ==> $res\n" if ($res != 0);
  system("del $dbfolder\\BPGInfo_pc");
  #Compile custom_db.c
  print "cl -E \@comm.ini $custparsedb > $custpridb\n";
  $res = system("cl -E \@comm.ini $custparsedb > $custpridb");
  die "cl -E \@comm.ini $custparsedb > $custpridb failed ==> $res\n" if ($res != 0);
  #Compile app_parse_db.c
  print "cl -E \@comm.ini $appparsedb > $apppridb\n";
  $res = system("cl -E \@comm.ini $appparsedb > $apppridb");
  die "cl -E \@comm.ini $appparsedb > $apppridb failed ==> $res\n" if ($res != 0);
  #Merge custom_pri.db
  $res = system("$cgen -cm $dbfolder\\BPGUInfoCustom_pc $dbfolder\\BPGUInfo_pc $custpridb $dbfolder\\enumFileCustom MoDIS $verno");
  die "$cgen -cm $dbfolder\\BPGUInfoCustom_pc $dbfolder\\BPGUInfo_pc $custpridb $dbfolder\\enumFileCustom MoDIS $verno ==> $res\n" if ($res != 0);
  system("del $dbfolder\\BPGUInfo_pc");
  #Merge app_pri.db
  $res = system("$cgen -ap $dbfolder\\BPGUInfoCustomApp_pc $dbfolder\\BPGUInfoCustom_pc $apppridb $dbfolder\\enumFileCustomApp MoDIS $verno $relDir\\plutommi");
  die "$cgen -ap $dbfolder\\BPGUInfoCustomApp_pc $dbfolder\\BPGUInfoCustom_pc $apppridb $dbfolder\\enumFileCustomApp MoDIS $verno $relDir\\plutommi ==> $res\n" if ($res != 0);
  system("del $dbfolder\\BPGUInfoCustom_pc");
  
  #Disable the following steps due to this flow is not used now.
  #$res = system("$cgen -ss ${reltst}\\database\\tempFile  $dbfolder\\BPGUInfo_pc $dbfolder\\BPGUInfo_pc ${reltst}\\database\\Routing.txt ${reltst}\\src\\tst_routing.c");
  #die "$cgen -ss ${reltst}\\database\\tempFile $dbfolder\\BPGUInfo_pc $dbfolder\\BPGUInfo_pc ${reltst}\\database\\Routing.txt ${reltst}\\src\\tst_routing.c ==> $res\n" if ($res != 0);
} else {
  $res = system("$cgen -ps $dbfolder\\BPGUInfoCustomApp_pc_SrcP  $dbfolder\\BPGUInfoCustomApp_pc_Src $pstrace_db $pstrace_db\\ps_trace.h");
  die "$cgen -ps $dbfolder\\BPGUInfoCustomApp_pc_SrcP $dbfolder\\BPGUInfoCustomApp_pc_Src $pstrace_db $pstrace_db\\ps_trace.h ==> $res\n" if ($res != 0);
}

exit 0;
