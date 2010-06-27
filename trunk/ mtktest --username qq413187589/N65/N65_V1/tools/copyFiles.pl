#!/usr/local/bin/perl
#$file = $ARGV[0];
#$FIXPATH = $ARGV[1];
#$RELEASE_DIR = $ARGV[2];
$FIXPATH = $ARGV[0];
print "$FIXPATH\n";

$RELEASE_DIR = $ARGV[1];
print "$RELEASE_DIR\n";
shift(@ARGV);
shift(@ARGV);
@Files="@ARGV";

open(F,">$FIXPATH\\make\\~copy.tmp") or die "Cannot open $FIXPATH\\make\\~copy.tmp";
print F @Files;
close(F);

print "perl tools\\lnitem.pl $FIXPATH\\make\\~copy.tmp";
system("perl tools\\lnitem.pl $FIXPATH\\make\\~copy.tmp");

open(F,"<$FIXPATH\\make\\~copy.tmp") or die "Cannot open $file: $!";
while(<F>) {
	chomp($_);
	if (-e $_) {
		if(!-e "$RELEASE_DIR\\$_") {
			system("md $RELEASE_DIR\\$_");
			system("rd $RELEASE_DIR\\$_");
		}
		print "copy /y $FIXPATH\\$_ $RELEASE_DIR\\$_\n";
		system("copy /y $FIXPATH\\$_ $RELEASE_DIR\\$_");
	} else {
		chop($_);
		if(!-e "$RELEASE_DIR\\$_") {
			system("md $RELEASE_DIR\\$_");
			system("rd $RELEASE_DIR\\$_");
		}
		print "copy /y $FIXPATH\\$_ $RELEASE_DIR\\$_\n";
		system("copy /y $FIXPATH\\$_ $RELEASE_DIR\\$_");
	}
}
close(F);
