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

open(F,">$FIXPATH\\make\\~base.tmp") or die "Cannot open $FIXPATH\\make\\~base.tmp";
print F @Files;
close(F);

print "perl tools\\lnitem.pl $FIXPATH\\make\\~base.tmp";
system("perl tools\\lnitem.pl $FIXPATH\\make\\~base.tmp");

open(F,"<$FIXPATH\\make\\~base.tmp") or die "Cannot open $file: $!";
while(<F>) {
	if (-e $_) {
		print "xcopy /e /y $FIXPATH\\$_ $RELEASE_DIR\\$_\\*.*\n";
		system("xcopy /e /y $FIXPATH\\$_ $RELEASE_DIR\\$_\\*.*");
	} else {
		chop($_);
		print "xcopy /e /y $FIXPATH\\$_ $RELEASE_DIR\\$_\\*.*\n";
		system("xcopy /e /y $FIXPATH\\$_ $RELEASE_DIR\\$_\\*.*");
	}
}
close(F);
