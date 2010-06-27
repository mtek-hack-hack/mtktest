#!/usr/bin/perl

$myname = "createMoDIS";
use createMoDIS;
 
&Usage if ($#ARGV == -1);
$thefile = $ARGV[0];
die "$thefile does NOT exist\n" if (!-e $thefile);
($thefile =~ /make\\(\w+)_(\w+).mak/i) || die "The Makefile format should be make\\custom_proj.mak\n";
$customer = uc($1);
$mode = uc($2);
($customer = "MTK") if ($customer =~ /^MT\d\d\d\d\w?$/i);

$gvfile = "..\\tst\\src\\gvTbl_modis.c";
system("type nul > $gvfile") if (!-e $gvfile);
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

if($thefile =~ /.+_(.+).mak/) {
	$project = $1;
}
$optMake = "..\\build\\${customer}\\log\\infomake.log";
open (FILE_HANDLE, "<$optMake") or die "cannot open ${optMake}\n";
while (<FILE_HANDLE>) {
  chomp;
  s/\s+/ /g;
  s/\s+$//g;
  if (/^(\S+)\s*=\s*(.+)$/) {
    $keyname = uc($1);
    defined($${keyname}) && warn "$1 redefined in $optMake!\n";
    $${keyname} = $2;
  }
}
close FILE_HANDLE;
###############################################################
# Read ini values
###############################################################
$ini_file = "${myname}.ini";
die "$ini_file did NOT exist!\n" if (!-e $ini_file);
open INI_FILE, "<$ini_file" or die "cannot open $ini_file\n";

$currSec = "";
my %currSec;
while (<INI_FILE>) {
  next if ((/^\s*$/) || (/^\s*#/));
  if (/^\s*\[(\S+)\]/) {
    $currSec = uc($1);
  } elsif (/^\s*(\S+)\s*=\s*(.*)\s*$/) {
    die "$_ in $ini_file did NOT belong to any section!\n" if ($currSec eq "");
    $fullKey = "${currSec}_" . lc($1);
    $currSec{$fullKey} = $2;
  } elsif (/^\s*(\S+)\s*\+=\s*(.*)\s*$/) {
    die "$_ in $ini_file did NOT belong to any section!\n" if ($currSec eq "");
    $fullKey = "${currSec}_". lc($1);
    warn "$_ in $ini_file did NOT initial $1 in $currSec section!\n" if (!defined($currSec{$fullKey}));
    $currSec{$fullKey} = $currSec{$fullKey} . " $2";
  }
}
close INI_FILE;

###############################################################
# Read ALIAS settings
###############################################################
open ALIAS_FILE, "<..\\make\\ALIAS.mak" || die "Cannot open ..\\make\\ALIAS.mak:$!";
while (<ALIAS_FILE>) {
#	next if ((/^\s*$/) || (/^\s*#/));
	if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $thefile!\n";
    $${keyname} = uc($2);
  }
}
close ALIAS_FILE;

foreach $module (split('\s+',$COMPLIST)) {
  if (defined $${module}) {
    if (-e "..\\make\\$${module}\\$${module}.def") {
      $compfolder = "..\\make\\$${module}";
      $compdef = "${compfolder}\\$${module}.def";
	  }
	} else {
    $compfolder = "..\\make\\${module}";
    $compdef = "${compfolder}\\${module}.def";
  }
  if ((-d $compfolder) && (-e $compdef)) {
    open F, "<$compdef" or die "cannot open $compdef\n";
    $a = join('',<F>);
    $a =~ s/\n/ /g;
    $a =~ s/\s+/ /g;
    $currSec{'ENABLE_OPTION_comm'} .= " $a";
    close F;
  }
}
###############################################################
# Check inconsistence in ini file (NOT YET FOR ALL)
#    1. DISABLE_XXX and ENABLE_XXX should not have the duplicate settings
#       Else show warning message and disable it
#    2. Priority: FILE > MODULE > GLOBAL
#    3. For JAVA
#         a. DISABLE_LIBS_java: if defining in ini, skip the checking rules in this file
#         b. ENABLE_LIBS_java: if defining in ini, still need to check the rules in this file
###############################################################
foreach $iniKey (sort keys %currSec) {
  if ($iniKey =~ /^([A-Z0-9_]+)_([a-z0-9_.]+)$/) {
    push @${iniKey},split('\s+',$currSec{$iniKey});
    if ($1 eq "GLOBAL_SETTINGS") {
      if ($2 eq "disable_libs") {
        foreach $a (split('\s+',$currSec{$iniKey})) {
          if (defined($WIN32_LIB{$a}) && ($WIN32_LIB{$a} == 1)) {
            warn "Duplicated define $a in enable and disable library!!\n";
            undef $WIN32_LIB{$a};
          }
          $UN_WIN32_LIB{$a} = 1;
        }     	
      } elsif ($2 eq "enable_libs") {
        foreach $a (split('\s+',$currSec{$iniKey})) {
          if (defined($UN_WIN32_LIB{$a}) && ($UN_WIN32_LIB{$a} == 1)) {
            warn "Duplicated define $a in enable and disable library!!\n";
          } else {
            $WIN32_LIB{$a} = 1;
          }
        }     	
      } elsif ($2 eq "enable_trcs") {
      } else {
        warn "Could not parse out $iniKey\n";
      }	
    } else {
      $$1{$2} = $currSec{$iniKey};
      ##print "$1, $2, $iniKey, $currSec{$iniKey}\n";
    }
  } else {
    die "Could not match $iniKey\n";
  }
}

###############################################################
# Keywords in ini
#    1. ENABLE_INC_PATH, DISABLE_INC_PATH, ENABLE_OPTION, DISABLE_OPTION
#	global and module name (all lowercase)
#    2. ENABLE_FILE, DISABLE_FILE
#       module name (all lowercase)
#    3. ENABLE_FILE_OPTION, DISABLE_FILE_OPTION,
#       filename (all lowercase)
#    4. GLOBAL_SETTINGS
#       disable_libs, fs_root, enable_libs
###############################################################
###############################################################
# Check JAVA (ini > Makefile)
###############################################################
if ($CUSTOM_RELEASE eq "TRUE") {
	if(defined $switchable_feature) {
		if ($switchable_feature ne "NONE") {
			$modislibroot = "MoDIS_LIB\\$platform\\$chip_ver\\$project\\$switchable_feature\\".${lc($switchable_feature)};
	  } else {
		  $modislibroot = "MoDIS_LIB\\$platform\\$chip_ver\\$project";
		}
	} else {
    $modislibroot = "MoDIS_LIB\\$platform\\$chip_ver\\$project";
  }
} else {
	$modislibroot = "MoDIS_lib";
}
print "modislibroot=$modislibroot\n";

###############################################################
# To support platform switch
###############################################################
if ($platform eq "MT6223") {
  $switch_platform = "MT6223P";
} elsif ($platform eq "MT6223P") {
  $switch_platform = "MT6223";
} elsif ($platform eq "MT6229") {
  $switch_platform = "MT6230";
} elsif ($platform eq "MT6230") {
  $switch_platform = "MT6229";
} elsif ($platform eq "MT6226D") {
  $switch_platform = "MT6227D";
} elsif ($platform eq "MT6227D") {
  $switch_platform = "MT6226D";
} elsif ($platform eq "MT6226") {
  $switch_platform = "MT6226M";
  $switch_platform2 = "MT6227";
} elsif ($platform eq "MT6226M") {
  $switch_platform = "MT6226";
  $switch_platform2 = "MT6227";
} elsif ($platform eq "MT6227") {
  $switch_platform = "MT6226";
  $switch_platform2 = "MT6226M";
}

if (!-e $modislibroot) {
	$switch_modislibroot = $modislibroot;
	$modislibroot =~ s/$platform/$switch_platform/;
	if (defined ($switch_platform2)) {
		$switch_modislibroot2 = $modislibroot;
		$modislibroot =~ s/$switch_platform/$switch_platform2/;
    (!-e $modislibroot) && die "$switch_modislibroot2 or $switch_modislibroot or $modislibroot does not exit.";
  } else {
  	(!-e $modislibroot) && die "$switch_modislibroot or $modislibroot does not exit.";
  }
}
###############################################################
# End of platform switch support
###############################################################

@liblist = ();

if (($CUSTOM_RELEASE eq "TRUE") && ($mmi_version ne "NEPTUNE_MMI")) {
	push(@liblist, "${modislibroot}\\sw_jpeg_codec\.lib");
}

if (($CUSTOM_RELEASE eq "TRUE") && ($mmi_version eq "NEPTUNE_MMI")) {
  if (($jpg_decode ne "NONE") || ($jpg_encode ne "NONE")) {
    push(@liblist, "${modislibroot}\\sw_jpeg_codec\.lib");
  }
}

if ($ssl_support eq "SSL_CIC_LIB") {
  push(@liblist, "${modislibroot}\\sb51\.lib");
  push(@liblist, "${modislibroot}\\sbpki2\.lib");    
  push(@liblist, "${modislibroot}\\sslplus5\.lib");    
}

  if (($j2me_support eq "IJET") && (($j2me_vm eq "KVM_SOURCE") || ($j2me_vm eq "KVM"))) {
    die "J2ME_SUPPORT=$j2me_support in $thefile is inconsistent with __J2ME__ defined in $COMMON_COMPILE_OPTION\n" if ($common_compile_option =~ /__J2ME__/);
    if ($j2me_vm eq "KVM_SOURCE") {
      $WIN32_LIB{"j2me_11"}=1;
    } else {
      print "USE ${modislibroot}\\j2me_11\.lib\n";
      push(@liblist, "${modislibroot}\\j2me_11\.lib");
    }
  } elsif ($j2me_support eq "JBLENDIA") {
  	die "J2ME_SUPPORT=$j2me_support in $thefile is inconsistent with __J2ME__ defined in $COMMON_COMPILE_OPTION\n" if ($common_compile_option =~ /__J2ME__/);
  	if ($j2me_vm eq "KVM") {
  		if ($j2me_feature_set eq "JTWI") {
  			if ($support_jsr_205 eq "TRUE") {			
          push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC_PIM_WMA20\\ajsc_win32_msvc\.lib");
          push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC_PIM_WMA20\\libmjb2\.lib");
          push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC_PIM_WMA20\\libaicrypto\.lib");
  			} else {
          if ($support_jsr_75_pim eq "TRUE") {
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC_PIM\\ajsc_win32_msvc\.lib");
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC_PIM\\libmjb2\.lib");
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC_PIM\\libaicrypto\.lib");
  				} else {
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC\\ajsc_win32_msvc\.lib");
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC\\libmjb2\.lib");
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDC11_JTWI10_FC\\libaicrypto\.lib");
          }
  			}
  		}
  	} elsif ($j2me_vm eq "HI_VM") {
  		if ($j2me_feature_set eq "JTWI") {
  			if ($support_jsr_205 eq "TRUE") {			
          push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC_PIM_WMA20\\ajsc_win32_msvc\.lib");
          push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC_PIM_WMA20\\libmjb2\.lib");
          push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC_PIM_WMA20\\libaicrypto\.lib");
  			} else {
          if ($support_jsr_75_pim eq "TRUE") {
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC_PIM\\ajsc_win32_msvc\.lib");
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC_PIM\\libmjb2\.lib");
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC_PIM\\libaicrypto\.lib");
  				} else {
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC\\ajsc_win32_msvc\.lib");
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC\\libmjb2\.lib");
            push(@liblist, "..\\j2me\\vm\\jblendia\\lib\\CLDCHI_JTWI10_FC\\libaicrypto\.lib");
          }
  			}
  		}
  	}
  } elsif (($j2me_support eq "IJET") && (($j2me_vm eq "HI_VM_SOURCE") || ($j2me_vm eq "HI_VM"))) {
    die "J2ME_SUPPORT=$j2me_support in $thefile is inconsistent with __J2ME__ defined in $COMMON_COMPILE_OPTION\n" if ($common_compile_option =~ /__J2ME__/);
    $UN_WIN32_LIB{'j2me_hi'}=1;
    if ($j2me_vm eq "HI_VM_SOURCE") {
      $WIN32_LIB{"j2me_hi_i386"}=1;
    } else {
      print "USE ${modislibroot}\\j2me_hi_i386\.lib\n";
      push(@liblist, "${modislibroot}\\j2me_hi_i386\.lib");
    }
  } elsif ($j2me_support ne "MTK_DUMMYVM") {
    print "DISABLE JAVA\n";
    $DISABLE_OPTION{'global'} .= " __J2ME__ ";
    $UN_WIN32_LIB{'jal'}=1;
    $UN_WIN32_LIB{'j2me_11'}=1;
    $UN_WIN32_LIB{'j2me_hi'}=1;
    $UN_WIN32_LIB{'ijet_adp'}=1;
    $DISABLE_FILE{'custom'} .= " j2me_custom_handler.c j2me_custom_lcd.c j2me_custom_mids.c j2me_custom_mids_jtbl.c j2me_custom_resource.c nativeFunctionTable.c ROMjava.c nativesTable.cpp ROMImage.cpp";
  }

if ($CUSTOM_RELEASE eq "TRUE") {
	$WIN32_LIB{"sw_jpeg_codec"}=0;
	$UN_WIN32_LIB{"sw_jpeg_codec"}=1;
} else {
  if ($mmi_version eq "NEPTUNE_MMI") {
    if (($jpg_decode eq "NONE") && ($jpg_encode eq "NONE")) {
      $WIN32_LIB{"sw_jpeg_codec"}=0;
      $UN_WIN32_LIB{"sw_jpeg_codec"}=1;
    }
  }
}

if (($mmi_base eq "") || ($mmi_base eq "PLUTO_MMI")) { $mmidir = "plutommi"; $mmidir2 = "lcmmi"; $mmidir3 = "plutommi";  $mmiprj2 ="lcmmi"; $mmiprj3 ="conn_app"; }
else { $mmidir = "lcmmi"; $mmidir2 = "plutommi"; $mmidir3 = "lcmmi";  $mmiprj2 ="conn_app"; $mmiprj3 ="lcmmi"; }
###############################################################
# read Common Compile option
###############################################################
my $BASE_PATH = "../build/$customer";
die "$BASE_PATH does NOT exist!\nPlease build MAUI target firstly\n" if (!-d $BASE_PATH);
my $COMMON_COMPILE_OPTION="$BASE_PATH/log/info.log";
my $common_compile_option;
my $common_include_path;

if((! -e $COMMON_COMPILE_OPTION)) {
  die "Can't find $COMMON_COMPILE_OPTION \n";
}

  print "Read $COMMON_COMPILE_OPTION...\n";
  open F,"<$COMMON_COMPILE_OPTION";
  my @data = split('\[',join('',<F>));
  foreach my $set (@data) {
    next if($set =~ /^\s*$/);
    if($set =~ /COMMON OPTION \]/) {
      $common_compile_option = substr($set,$+[0]);
    } elsif($set =~ /COMMON INCLUDE PATH \]/) {
      $common_include_path = substr($set,$+[0]);
    } else {
      die "Unknown instruction $set";
    }
  }
  close F;
###############################################################
# Generate each library
###############################################################
my $MAKE_PATH="../make";
my $MCU_ROOT="..\\..\\";
{
  opendir D,"$DEP_PATH";
  print "\n\nGenerate project file ......";

  if ($CUSTOM_RELEASE eq "TRUE") {
    push @skip_set, split('\s+',$CUS_REL_PAR_SRC_COMP);
    push @skip_set, split('\s+',$CUS_REL_MTK_COMP);
    push @skip_set, "oscar";
    foreach $lib (@skip_set) {
      $UN_WIN32_LIB{$lib} = 1;
      if (${lib} eq "drv_sec") {
        if (uc($gemini) eq "TRUE") {
          if ($common_compile_option =~ /__DRV_DUAL_SIM_INVERSE__/) {
            if (-e "${modislibroot}\\DRV_DUAL_SIM_INVERSE_ON\\${lib}\.lib") { push(@liblist, "${modislibroot}\\DRV_DUAL_SIM_INVERSE_ON\\${lib}\.lib"); }
          } else {
            if (-e "${modislibroot}\\DRV_DUAL_SIM_INVERSE_OFF\\${lib}\.lib") { push(@liblist, "${modislibroot}\\DRV_DUAL_SIM_INVERSE_OFF\\${lib}\.lib"); }
          }
        } else {
          if (-e "${modislibroot}\\${lib}\.lib") { push(@liblist, "${modislibroot}\\${lib}\.lib"); }
        }
      } else {
        if (-e "${modislibroot}\\${lib}\.lib") { push(@liblist, "${modislibroot}\\${lib}\.lib"); }
      }
      $WIN32_LIB{$lib} = 0;
    }
  }

  undef %lib_list;
  foreach $dir (split('\s+',$COMPLIST)) {
    next if (defined($UN_WIN32_LIB{lc($dir)}));
    $lib_list{$dir}=1;
  }
  closedir D;

  foreach my $tmp (keys %WIN32_LIB) {   next if ($WIN32_LIB{$tmp} == 0); print "$tmp ";$lib_list{$tmp} = 1;}
  @tmp_lib_list =  keys %lib_list;

if ($CUSTOM_RELEASE ne "TRUE") {
 if ($ENV{"USERDOMAIN"} =~ /MTK/i) {
 	if (($j2me_support eq "IJET") && ($j2me_vm =~ /HI_VM/i)) {
    if ($WIN32_LIB{"j2me_hi_i386"} != 1) {
      push(@tmp_lib_list, "j2me_hi_i386");
    }
    push(@tmp_lib_list, "jdummy");
  } elsif (($j2me_support eq "IJET") && ($j2me_vm =~ /KVM/i)) {
    if ($WIN32_LIB{"j2me_11"} != 1) {
      push(@tmp_lib_list, "j2me_11");
    }
    push(@tmp_lib_list, "jdummy");
  } elsif($j2me_support =~ /JBLENDIA/) {
    push(@tmp_lib_list, "jdummy");
  }
 }
}

  foreach my $lib (sort @tmp_lib_list) {
    my @tmp_set;
    print "$lib";
    (mkdir $lib or die "Can't create directory $lib") if(! -d $lib );

    ########################################################################################################
    ## read filelist
    my $lis_filename = "$MAKE_PATH/$lib/$lib.lis";
    if (defined $${lib}) {
    	if (-e "$MAKE_PATH/$${lib}/$lib/$lib.lis") {
    	  $lis_filename = "$MAKE_PATH/$${lib}/$lib/$lib.lis";
      }
    }
    open F,"<$lis_filename" or die "Can't read $lis_filename";
    my $list = "";
    my %list_hash;
    my @list_set;

    push @list_set,split('\s+',$ENABLE_FILE{'global'}) if(defined($ENABLE_FILE{'global'}));
    push @list_set,split('\s+',$ENABLE_FILE{$lib}) if(defined($ENABLE_FILE{$lib}));
    
    @tmp_set = <F>;
    push @list_set,@tmp_set;
    close F;

    foreach my $file (@list_set) {
      $file =~ s/^\s+//gs;
      $file =~ s/\s+$//gs;
      next if($file !~ /\S+/);
      next if($list_hash{lc($file)});

      if(!is_in_list1($file,$DISABLE_FILE{'global'})
         && !is_in_list1($file,$DISABLE_FILE{$lib})) {
          if ($file =~ /^\./) {
            $list .= $file ."\n"
          } else {
            $list .= $MCU_ROOT . $file ."\n"
          }
          $list_hash{lc($file)} = 1;
      }
    }
    $list = join("\n",sort(split('\s+',$list))) . "\n";

    ########################################################################################################
    # read compile option
    my $def_filename = "$MAKE_PATH/$lib/$lib.def";
    if (defined $${lib}) {
    	if (-e "$MAKE_PATH/$${lib}/$${lib}.def") {
    	  $def_filename = "$MAKE_PATH/$${lib}/$${lib}.def";
      }
    }
    my $compile_option = "";
    open F,"<$def_filename" or die "Can't read $def_filename";
    my @compile_option_set;
    push @compile_option_set,split('\s+',$ENABLE_OPTION{'global'})if(defined($ENABLE_OPTION{'global'}));
    push @compile_option_set,split('\s+',$ENABLE_OPTION{$lib}) if(defined($ENABLE_OPTION{$lib}));
    push @compile_option_set, split('\s+',$common_compile_option);
    @tmp_set = <F>;
    push @compile_option_set,@tmp_set;

    foreach my $option(@compile_option_set) {
      while($option =~ /(\S+)/gs) {
        my $flag = $1;
        if ($flag =~ /^\d+$/) {
          #print "Warning: compile option only define number $flag\n. ignore it";
        next;
      }
      if((!is_in_list1($flag,$DISABLE_OPTION{'global'}) 
         && !is_in_list1($flag,$DISABLE_OPTION{$lib}))
         ||  $ENABLE_OPTION{$lib} =~ /\b$flag\b/
         ||  $ENABLE_OPTION{$lib} =~ /\s?$flag\s?/)  {
          if($flag =~ /^\//) {
            $compile_option .= $flag . "\n";
          } else {
            $compile_option .= "/D \"$flag\"\n";
          }
        }
      }
    }
    close F;

    ########################################################################################################
    # read include path
    my $inc_filename = "$MAKE_PATH/$lib/$lib.inc";
    if (defined $${lib}) {
    	if (-e "$MAKE_PATH/$${lib}/$lib/$lib.inc") {
    	  $inc_filename = "$MAKE_PATH/$${lib}/$lib/$lib.inc";
    	}
    }
    my $include_path = "";
    open F,"<$inc_filename" or die "Can't read $inc_filename";

    my @include_set;

    push @include_set, split('\s+',$ENABLE_INC_PATH{'global'}) if(defined($ENABLE_INC_PATH{'global'}));
    push @include_set, split('\s+',$ENABLE_INC_PATH{$lib}) if(defined($ENABLE_INC_PATH{$lib}));
    push @include_set, split('\s+',$common_include_path);
    @tmp_set = <F>;
    foreach my $path(@tmp_set) {
      $path =~ s/${mmidir2}/${mmidir}/ig;
      push @include_set,$path;
    }
    close F;

    foreach my $option(@include_set) {
      while($option =~ /(\S+)/gs) {
        my $path = $1;

        $path =~ s/\\$//;
        $path =~ s/\/$//;

        # ignore some path
        if(!is_in_list1($path,$DISABLE_INC_PATH{'global'}) && 
           !is_in_list1($path,$DISABLE_INC_PATH{$lib})) {
          # record it!
          if($path =~ /^\./) {
            $include_path .= "/I \"$path\"\n" ;
          } else {
            $include_path .= "/I \"$MCU_ROOT$path\"\n" ;
          }
        }
      }
    }

    ## write .dep file
    createMoDIS::create_lib_project(
      $lib,
      "$lib/$lib.dsp",
      $compile_option,
      $include_path,
      $list,
      \%ENABLE_OPTION
    );
  }
  open (F, ">lib_list") or die "cannot open lib_list\n";
  foreach my $lib (sort keys %lib_list) {
    print F "$lib\n";
  }
  close F;
  
  if ((-d "..\\ps\\mcddll") && (-e "..\\ps\\mcddll\\mcddll.dsp")) {
    $lib = "mcddll";
    my @compile_option_set;
    my $compile_option = "";
    push @compile_option_set,split('\s+',$ENABLE_OPTION{'global'})if(defined($ENABLE_OPTION{'global'}));
    push @compile_option_set,split('\s+',$ENABLE_OPTION{$lib}) if(defined($ENABLE_OPTION{$lib}));
    push @compile_option_set, split('\s+',$common_compile_option);

    foreach my $option(@compile_option_set) {
      while($option =~ /(\S+)/gs) {
        my $flag = $1;
        if ($flag =~ /^\d+$/) {
          #print "Warning: compile option only define number $flag\n. ignore it";
        next;
      }
      if((!is_in_list1($flag,$DISABLE_OPTION{'global'}) 
         && !is_in_list1($flag,$DISABLE_OPTION{$lib}))
         ||  $ENABLE_OPTION{$lib} =~ /\b$flag\b/
         ||  $ENABLE_OPTION{$lib} =~ /\s?$flag\s?/)  {
          if($flag =~ /^\//) {
            $compile_option .= $flag . "\n";
          } else {
            $compile_option .= "/D \"$flag\"\n";
          }
        }
      }
    }

    ########################################################################################################
    # read include path
    my @include_set;
    my $include_path = "";

    push @include_set, split('\s+',$ENABLE_INC_PATH{'global'}) if(defined($ENABLE_INC_PATH{'global'}));
    push @include_set, split('\s+',$ENABLE_INC_PATH{$lib}) if(defined($ENABLE_INC_PATH{$lib}));
    push @include_set, split('\s+',$common_include_path);

    foreach my $option(@include_set) {
      while($option =~ /(\S+)/gs) {
        my $path = $1;

        $path =~ s/\\$//;
        $path =~ s/\/$//;

        # ignore some path
        if(!is_in_list1($path,$DISABLE_INC_PATH{'global'}) && 
           !is_in_list1($path,$DISABLE_INC_PATH{$lib})) {
          # record it!
          if($path =~ /^\./) {
            $include_path .= "/I \"$path\"\n" ;
          } else {
            $include_path .= "/I \"$MCU_ROOT$path\"\n" ;
          }
        }
      }
    }
    open H,">../ps/mcddll/mcddll.ini";
    print H "$compile_option\n$include_path\n";
    close H;

  }
}

sub is_in_list1 {
  my $item = shift;
  my $list = shift;

  return 0 if(!defined($list));

  while( $list =~ /(\S+)/g) {
    my $i=$1;
    $i =~ s/\\/\\\\/g;
    return 1 if( $item =~ /^$i\W/is);
    return 1 if( $item =~ /^$i$/is);
    return 1 if( $item =~ /\W$i$/si);
    return 1 if( $item =~ /\W$i\W/si);
  }
  return 0;
}

sub update_simulator_compile_option {
  my $compile_option = "";
  foreach my $lib (keys %SIMULATOR_COMPILE_OPTION_COPY_LIST) {
    if (-e "$lib/$lib.dsp") {
      open F,"<$lib/$lib.dsp";
      if(join("",<F>) =~ /((# ADD CPP.*?\n)+)/s) {
        $compile_option = $1 
      } else {
        print "didn't modify the simulator project compile option\n";
        return ;
      }
      close F;
      last;
    }
  }
  # customize the compile option
  $compile_option .= "# ADD CPP /c\n";

  # modify compile option
  open F,"<MoDIS/MoDIS.dsp";
  my $content = join("",<F>);
  close F;

  {
    my @pos;
    my @len;
    while($content =~ /((# ADD CPP.*?\n)+)/sg) {
      push @pos,$-[1];
      push @len,$+[1]-$-[1];
    }
    while($#pos>=0) {
      my $p;
      my $l;
      $p = pop @pos;
      $l = pop @len;
      substr($content,$p,$l) = $compile_option;
    }
  }
  open F,">MoDIS/MoDIS.dsp";
  print F $content;
  close F;
}
###############################################################
# Generate Main workspace
###############################################################
{
  my @tmp = (sort keys %lib_list);
  ##########################
  # Huyanwei Add BEGIN
  ##########################
  my @temp =();
  foreach my $item(@tmp) { 
	  if ($item =~ /obigo\S*/) {
		  next; }
	  push(@temp,$item);
  }  
  @tmp=();
  @tmp = @temp;
  print "\ntemp = @tmp\n";
  ########################
  # Huyanwei Add  End
  ########################

  push(@tmp, "MODIS_UI") if ((-d "MODIS_UI") && (-e ".\\MODIS_UI\\MODIS_UI.dsp"));
  createMoDIS::create_workspace(
    "MoDIS.dsw",
    \@tmp
  );
  #update_simulator_compile_option;
}

###############################################################
# Check 3rd-party utilities
###############################################################

$hwlib = "..\\vendor\\handwriting\\hanwang\\v1_official\\lib\\hws\.lib";
$hwdemolib = "..\\vendor\\handwriting\\hanwang\\v1_demo\\lib\\hws\.lib";
if ($empty_resource eq "TRUE") {
  ($mmidir = $customer) if (($mmi_version eq "PLUTO_MMI")||($mmi_version eq "NEPTUNE_MMI"));
}
($mmidir = $customer) if (($mmi_version ne "PLUTO_MMI")&&($mmi_version ne "NEPTUNE_MMI")&&($mmi_version ne "NEPTUNE_COLOR_MMI"));

$ziv6lib = "..\\vendor\\InputMethod\\zi\\project\\${mmidir}\\v6_official\\lib\\zi8clib_modis\.lib";
$ziv6ARlib = "..\\vendor\\InputMethod\\zi\\project\\${mmidir}\\v6_official\\lib\\zi8ARShape_modis\.lib";
$ziv7lib = "..\\vendor\\InputMethod\\zi\\project\\${mmidir}\\v7_official\\lib\\zi8clib_modis\.lib";
$ziv7ARlib = "..\\vendor\\InputMethod\\zi\\project\\${mmidir}\\v7_official\\lib\\zishape_modis\.lib";
$t9v7lib = "..\\vendor\\InputMethod\\t9\\project\\${mmidir}\\v7_official\\lib\\T9RelVCChin_modis\.obj";
$t9v6lib = "..\\vendor\\InputMethod\\t9\\project\\${mmidir}\\v6_official\\lib\\T9RelVCChin_modis\.obj";
$penpwrlib = "..\\vendor\\handwriting\\penpower\\v1_official\\lib\\MediaTek_Hwre\.lib";
$pphraselib = "..\\vendor\\handwriting\\penpower\\v1_official\\lib\\MTK_PPhrase_WIN\.lib";
$ppdemolib = "..\\vendor\\handwriting\\penpower\\v1_demo\\lib\\MediaTek_Hwre_demo\.lib";
$cstarlib = "..\\vendor\\InputMethod\\cstar\\v2_official\\lib\\csk2_MoDIS\.lib";
$cstardemolib = "..\\vendor\\InputMethod\\cstar\\v2_demo\\lib\\csk2_MoDIS\.lib";
$decumascrlib = "..\\vendor\\handwriting\\Zi_decuma\\\v1_official\\lib\\scrlib_MODIS\.lib";
$decumadltlib = "..\\vendor\\handwriting\\Zi_decuma\\\v1_official\\lib\\dltlib_MODIS\.lib";

$t9 = 0;
if (($input_method eq "MMI_ZI") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'zi'} == 1))) {
  push(@liblist, $ziv6lib);
  push(@liblist, $ziv6ARlib) if (-e $ziv6ARlib);
  warn "$ziv6lib does NOT exist and INPUT_METHOD == $input_method\n" if (!-e $ziv6lib);
} elsif (($input_method eq "MMI_ZI_V6") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'zi'} == 1))) {
  push(@liblist, $ziv6lib);
  push(@liblist, $ziv6ARlib) if (-e $ziv6ARlib);
  warn "$ziv6lib does NOT exist and INPUT_METHOD == $input_method\n" if (!-e $ziv6lib);
} elsif (($input_method eq "MMI_ZI_V7") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'zi'} == 1))) {
  push(@liblist, $ziv7lib);
  push(@liblist, $ziv7ARlib) if (-e $ziv7ARlib);
  warn "$ziv7lib does NOT exist and INPUT_METHOD == $input_method\n" if (!-e $ziv7lib);
} elsif (($input_method eq "MMI_T9_V7") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'t9'} == 1))) {
  push(@liblist, $t9v7lib); $t9 = 1;
  warn "$t9v7lib does NOT exist and INPUT_METHOD == $input_method\n" if (!-e $t9v7lib);
} elsif (($input_method eq "MMI_T9") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'t9'} == 1))) {
  push(@liblist, $t9v7lib); $t9 = 1;
  warn "$t9v7lib does NOT exist and INPUT_METHOD == $input_method\n" if (!-e $t9v7lib);
} elsif (($input_method eq "MMI_T9_V6") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'t9'} == 1))) {
  push(@liblist, $t9v6lib); $t9 = 1;
  warn "$t9v6lib does NOT exist and INPUT_METHOD == $input_method\n" if (!-e $t9v6lib);
} elsif (($input_method eq "MMI_CSTAR_V2") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'cstar'} == 1))) {
  push(@liblist, $cstarlib);
  warn "$cstarlib does NOT exist and INPUT_METHOD == $input_method\n" if (!-e $cstarlib);
} elsif (($input_method eq "MMI_CSTAR_V2_DEMO") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'cstar'} == 1))) {
  push(@liblist, $cstardemolib);
  warn "$cstardemolib does NOT exist and INPUT_METHOD == $input_method\n" if (!-e $cstardemolib);
}

if (($hand_writing eq "MMI_HANWANG") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'hanwang'} == 1))) { 
  push(@liblist, $hwlib);
  warn "$hwlib does NOT exist and HAND_WRITING == $hand_writing\n" if (!-e $hwlib);
} elsif (($hand_writing eq "MMI_HANWANG_DEMO") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'hanwang'} == 1))) {
  push(@liblist, $hwdemolib);
  warn "$hwdemolib does NOT exist! HAND_WRITING==MMI_HANWANG_DEMO && TOUCH_PANEL==$touch_panel_support)\n" if (!-e $hwdemolib);
} elsif (($hand_writing eq "MMI_PENPOWER") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'penpower'} == 1))) {
  push(@liblist, $penpwrlib);
  warn "$penpwrlib does NOT exist!(HAND_WRITING == $hand_writing)\n" if (!-e $penpwrlib);
  push(@liblist, $pphraselib);
  warn "$pphraselib does NOT exist!(HAND_WRITING == $hand_writing)\n" if (!-e $pphraselib);
} elsif (($hand_writing eq "MMI_PENPOWER_DEMO") && ($touch_panel_support ne "NONE") && (($CUSTOM_RELEASE eq "TRUE") || ($lib_list{'penpower'} == 1))) {
  push(@liblist, $ppdemolib);
  warn "$ppdemolib does NOT exist! HAND_WRITING==MMI_PENPOWER_DEMO && TOUCH_PANEL == $touch_panel_support)\n" if (!-e $ppdemolib);
} elsif (($hand_writing eq "MMI_DECUMA") && (($touch_panel_support ne "NONE") || ($lib_list{'decuma'} == 1))) {
  push(@liblist, $decumascrlib);
  warn "$decumascrlib does NOT exist! HAND_WRITING==MMI_DECUMA && TOUCH_PANEL==$touch_panel_support)\n" if (!-e $decumascrlib);
  push(@liblist, $decumadltlib);
  warn "$decumadltlib does NOT exist! HAND_WRITING==MMI_DECUMA && TOUCH_PANEL==$touch_panel_support)\n" if (!-e $decumadltlib);
}

$miniblglib = "..\\vendor\\game_engine\\brogent\\engine_v1\\pc\\mini_bgl\.lib";
$bgt_ggr2_opt_lib = "..\\vendor\\game_engine\\brogent\\game\\GoGoRobot2\\GAME_LIB\\pc\\bgt_ggr2_optimize\.lib";
$bgt_hb2_util_lib = "..\\vendor\\game_engine\\brogent\\game\\HeatBreaker2\\GAME_LIB\\pc\\bgt_hb2_utils\.lib";
if ($common_compile_option =~ /GE_BROGENT/) {
  push(@liblist, $miniblglib, $bgt_ggr2_opt_lib, $bgt_hb2_util_lib);
  warn "$miniblglib, $bgt_ggr2_opt_lib, $bgt_hb2_util_lib does NOT exist!\n" if ((!-e $miniblglib) || (!-e $bgt_ggr2_opt_lib) || (!-e $bgt_hb2_util_lib));
}

# 3D game engine
#$gameenginelib = "..\\vendor\\game_engine\\intergrafx\\engine_v1\\pc\\${main_lcd_size}\\game_engine\.lib";
$ignitem3glib = "..\\vendor\\game_engine\\intergrafx\\engine_v1\\pc\\${main_lcd_size}\\ignitem3g\.lib";
$ignitemathlib = "..\\vendor\\game_engine\\intergrafx\\engine_v1\\pc\\${main_lcd_size}\\ignitemath\.lib";
$libpnglib = "..\\vendor\\game_engine\\intergrafx\\engine_v1\\pc\\${main_lcd_size}\\libpng\.lib";

# 3D game: petfish
$petfishobj = "..\\vendor\\game_engine\\intergrafx\\game\\petfish\\${main_lcd_size}\\modis\\fish\.obj";
$petfishmenuobj = "..\\vendor\\game_engine\\intergrafx\\game\\petfish\\${main_lcd_size}\\modis\\fishmenu\.obj";
$petfishgamemainobj = "..\\vendor\\game_engine\\intergrafx\\game\\petfish\\${main_lcd_size}\\modis\\gamemain\.obj";
$petfishdemoobj = "..\\vendor\\game_engine\\intergrafx\\game\\petfish\\${main_lcd_size}\\modis\\ig_demogame\.obj";
$petfishlogoobj = "..\\vendor\\game_engine\\intergrafx\\game\\petfish\\${main_lcd_size}\\modis\\logo\.obj";
$petfishutilityobj = "..\\vendor\\game_engine\\intergrafx\\game\\petfish\\${main_lcd_size}\\modis\\utility\.obj";

# 3D game: rollingball
$rollingballobj = "..\\vendor\\game_engine\\intergrafx\\game\\rollingball\\${main_lcd_size}\\modis\\ig_rollingball_${main_lcd_size}\.obj";
$rollingballinputobj = "..\\vendor\\game_engine\\intergrafx\\game\\rollingball\\${main_lcd_size}\\modis\\ig_rotation_${main_lcd_size}_input\.obj";
$rollingballmainobj = "..\\vendor\\game_engine\\intergrafx\\game\\rollingball\\${main_lcd_size}\\modis\\ig_rotation_main_${main_lcd_size}\.obj";
$rollingballtitleobj = "..\\vendor\\game_engine\\intergrafx\\game\\rollingball\\${main_lcd_size}\\modis\\ig_rotation_title_${main_lcd_size}\.obj";

if ($common_compile_option =~ /GE_INTERGRAFX/) {
  push(@liblist, $ignitem3glib, $ignitemathlib, $libpnglib);
  warn "$ignitem3glib, $ignitemathlib, $libpnglib does NOT exist!\n" if ((!-e $ignitem3glib) || (!-e $ignitemathlib) || (!-e $libpnglib));

  push(@liblist, $petfishobj, $petfishmenuobj, $petfishgamemainobj, $petfishdemoobj, $petfishlogoobj, $petfishutilityobj);
  warn "$petfishobj, $petfishmenuobj, $petfishgamemainobj, $petfishdemoobj, $petfishlogoobj, $petfishutilityobj does NOT exist!\n" if ((!-e $petfishobj) || (!-e $petfishmenuobj) || (!-e $petfishgamemainobj) || (!-e $petfishdemoobj) || (!-e $petfishlogoobj) || (!-e $petfishutilityobj));

  push(@liblist, $rollingballobj, $rollingballinputobj, $rollingballmainobj, $rollingballtitleobj);
  warn "$rollingballobj, $rollingballinputobj, $rollingballmainobj, $rollingballtitleobj does NOT exist!\n" if ((!-e $rollingballobj) || (!-e $rollingballinputobj) || (!-e $rollingballmainobj) || (!-e $rollingballtitleobj));

}

$swflash_lib = "..\\vendor\\swflash\\${sw_flash}\\v1_official\\VIS20_WIN32_MTK\.lib";
$swflash_dl_lib = "..\\vendor\\swflash\\${sw_flash}\\v1_official\\zdd2_1_lib\.lib";
if ((($sw_flash ne "") || ($sw_flash ne "NONE")) && ($lib_list{'swflash'} == 1)) {
  push(@liblist, $swflash_lib, $swflash_dl_lib);
  warn "$swflash_lib does NOT exist!\n" if (!-e $swflash_lib);
}

@cl_tdmb_libs = (
  "..\\vendor\\tdmb\\cyberlink\\lib\\pc\\LibCodecInterface.lib",
  "..\\vendor\\tdmb\\cyberlink\\lib\\pc\\LibDemuxInterface.lib",
  "..\\vendor\\tdmb\\cyberlink\\lib\\pc\\DLS_Parser.lib",
  "..\\vendor\\tdmb\\cyberlink\\lib\\pc\\PAD_Parser.lib",
  "..\\vendor\\tdmb\\cyberlink\\lib\\pc\\SDL.lib");
if(defined($tdmb_support) && ($tdmb_support ne "NONE")) {
  push(@liblist, @cl_tdmb_libs);
  foreach my $lib (@cl_tdmb_libs) {
    warn "$lib does NOT exist!\n" if (!-e $lib);
  }
}

# Language Learning feature
$langln_lib = "..\\vendor\\langlearn\\digidea\\engine_01\\dzdpc\.lib";
if ((($langln_engine ne "") || ($langln_engine ne "NONE")) && ($lib_list{'langln'} == 1)) {
  push(@liblist, $langln_lib);
  warn "$langln_lib does NOT exist!\n" if (!-e $langln_lib);
}

$pc_sim_dsp = 'MoDIS\\MoDIS.dsp';

open (FILE, "+<$pc_sim_dsp") or die "cannot open $pc_sim_dsp\n";
$fcontent = join("",<FILE>);
close FILE;

$fcontent =~ s/# Begin Group "libs".*?# End Group//gs;

my $t = "# Begin Group \"libs\"\n# PROP Default_Filter \"\"\n";
foreach my $line (@liblist) {
  $t .= "# Begin Source File\n";
  $t .= "SOURCE=..\\$line\n";
  $t .= "# End Source File\n";
}

$t .= "# End Group\n";
$fcontent =~ s/# End Target/$t# End Target/;
$fcontent =~ s/${mmiprj2}\/${mmiprj2}.ini/${mmiprj3}\/${mmiprj3}.ini/ig;


open (FILE, ">$pc_sim_dsp") or die "cannot open $pc_sim_dsp\n";
print FILE $fcontent;
close FILE;

print "Finish createMoDIS\n";

sub Usage {
  warn << "__USAGE";
Usage:
     ${myname}.pl  MAKEFILE
__USAGE

  exit 1;
}

###############################################################
# Copy NFB files
###############################################################
if ($nand_flash_booting eq "TRUE") {
	die "..\\$mmidir\\Customer\\CustResource\\CustENFBImgData does not exist.\n" if (!-e "..\\$mmidir\\Customer\\CustResource\\CustENFBImgData");
	die "..\\$mmidir\\Customer\\CustResource\\CustENFBStrData does not exist.\n" if (!-e "..\\$mmidir\\Customer\\CustResource\\CustENFBStrData");
	system("copy /y ..\\$mmidir\\Customer\\CustResource\\CustENFBImgData MoDIS\\CustENFBImgData");
	system("copy /y ..\\$mmidir\\Customer\\CustResource\\CustENFBStrData MoDIS\\CustENFBStrData");
}
