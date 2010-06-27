#!/usr/local/bin/perl
#$file = $ARGV[0];
#$FIXPATH = $ARGV[1];
#$RELEASE_DIR = $ARGV[2];
$OUTPUT = $ARGV[0];
print "$OUTPUT\n";
shift(@ARGV);

$ITEM = $ARGV[0];
print "$ITEM\n";
shift(@ARGV);

@INPUT = @ARGV;
print "@INPUT\n";

@new_output = sort @INPUT;
print "@new_output\n";

if(-e $OUTPUT) {
	open(W,">>$OUTPUT") or die "Cannot open $OUTPUT";
} else {
	open(W,">$OUTPUT") or die "Cannot open $OUTPUT";
}

print W "$ITEM = ";
foreach (@new_output) {
  print W "$_ ";
}
print W "\n";
close(W);




