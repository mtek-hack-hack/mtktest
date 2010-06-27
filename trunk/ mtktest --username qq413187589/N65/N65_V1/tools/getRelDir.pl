#!/usr/bin/perl
#Change relative RELEASE_DIR path to absolute RELEASE_DIR path in info_custom_release.log.

system "dir $ARGV[0] |find \"Directory of\" > ~reldir.tmp";
open (FH,"~reldir.tmp");
while(<FH>){
	if (index($_,"Directory") >= 0) {
		$_ =~ /Directory of (.+)/;
		print "RELEASE_DIR = $1\n";
	}
}
close (FH);
system "del ~reldir.tmp";
