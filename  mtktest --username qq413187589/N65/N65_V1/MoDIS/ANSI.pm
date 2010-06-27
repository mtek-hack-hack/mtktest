package ANSI;
#
# Copyright (c) 2004 Jean-Louis Morel <jl_morel@bribes.org>
#
# Version 0.07 (02/01/2005)
#
# This program is free software; you can redistribute it and/or modify
# it under the same terms as Perl itself.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See either the
# GNU General Public License or the Artistic License for more details.
#

use 5.006;
use strict;
use warnings;
require Exporter;

our @ISA = qw(Exporter);
our $VERSION = '0.07';
our $DEBUG = 0;
our $CON;

our @EXPORT_OK = ( 'Title', 'Cursor',
);

our @EXPORT = qw(
);

# print overloading

package Win32::Console::ANSI::IO;
use Carp qw/carp croak/;
use Win32::Console;
use Win32API::Registry qw( :HKEY_ :KEY_ );

# module Encode available ?
my $EncodeOk;
BEGIN {eval "use Encode qw/ from_to /"; $EncodeOk = $@ ? 0 : 1;}

# Retrieving the codepages
my ($key, $cpANSI);
Win32API::Registry::RegOpenKeyEx( HKEY_LOCAL_MACHINE,
              'SYSTEM\CurrentControlSet\Control\Nls\CodePage', 0, KEY_READ, $key );
Win32API::Registry::RegQueryValueEx( $key, 'ACP', [], [], $cpANSI, [] );
Win32API::Registry::RegCloseKey( $key );
print STDERR "Unable to read Win codepage\n" if $DEBUG and !$cpANSI;
$cpANSI = 'cp'.($cpANSI ? $cpANSI : 1252);      # Windows codepage
my $OEM = Win32::Console::OutputCP();
my $cpOEM = 'cp'.$OEM;                          # DOS codepage
my $cp = $cpANSI.$cpOEM;
print STDERR "EncodeOk=$EncodeOk cpANSI=$cpANSI cpOEM=$cpOEM\n" if $DEBUG;

my %color = ( 30 => 0,                                               # black foreground
              31 => FOREGROUND_RED,                                  # red foreground
              32 => FOREGROUND_GREEN,                                # green foreground
              33 => FOREGROUND_RED|FOREGROUND_GREEN,                 # yellow foreground
              34 => FOREGROUND_BLUE,                                 # blue foreground
              35 => FOREGROUND_BLUE|FOREGROUND_RED,                  # magenta foreground
              36 => FOREGROUND_BLUE|FOREGROUND_GREEN,                # cyan foreground
              37 => FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE, # white foreground
              40 => 0,                                               # black background
              41 => BACKGROUND_RED,                                  # red background
              42 => BACKGROUND_GREEN,                                # green background
              43 => BACKGROUND_RED|BACKGROUND_GREEN,                 # yellow background
              44 => BACKGROUND_BLUE,                                 # blue background
              45 => BACKGROUND_BLUE|BACKGROUND_RED,                  # magenta background
              46 => BACKGROUND_BLUE|BACKGROUND_GREEN,                # cyan background
              47 => BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE, # white background
            );

sub TIEHANDLE {
  my $self = bless {}, shift;
  $self->{handle} = shift;
  if ($self->{handle} eq 'STDOUT') {
    $self->{'Out'} = new Win32::Console(STD_OUTPUT_HANDLE);
    $self->{'fileno'} = fileno STDOUT;
    $CON = $self->{'Out'};
  }
  else {
    $self->{'Out'} = new Win32::Console(STD_ERROR_HANDLE);
    $self->{'fileno'} = fileno STDERR;
    $CON = $self->{'Out'} unless defined $CON;
  }
  $self->{x} = 0;
  $self->{y} = 0;           # to save cursor position ESC[s
  $self->{foreground} = 7;
  $self->{background} = 0;
  $self->{bold} = 0;
  $self->{underline} = 0;
  $self->{revideo} = 0;
  $self->{concealed} = 0;
  $self->{conv} = 1;        # char conversion by default
  return $self;
}

sub _PrintString {
  my ($self, $s) = @_;
  while ($s ne '') {
    my ($x, $y, $n);
    if ( $s =~ s/([^\e]*)?\e([\[(])([0-9\;\=]*)([a-zA-Z@])(.*)/$5/s ) {
      $self->{Out}->Write((_conv($self, $1)));
      if ( $2 eq '[' ) {
        if ($4 eq 'm') {                        # ESC[#;#;....;#m Set display attributes
          my @attributs = split /\;/, $3;
          push @attributs, 0 unless @attributs;   # ESC[m == ESC[;m ==...==ESC[0m
          my $attribut;
          foreach my $attr (@attributs) {
            if ( $attr ) {
              if ( $attr == 1 ) {
                $self->{bold} = 1;
              }
              elsif ( $attr == 21 ) {
                $self->{bold} = 0;
              }
              elsif ( $attr == 4 ) {
                $self->{underline} = 1;
              }
              elsif ( $attr == 24 ) {
                $self->{underline} = 0;
              }
              elsif ( $attr == 7 ) {
                $self->{revideo} = 1;
              }
              elsif ( $attr == 27 ) {
                $self->{revideo} = 0;
              }
              elsif ( $attr == 8 ) {
                $self->{concealed} = 1;
              }
              elsif ( $attr == 28 ) {
                $self->{concealed} = 0;
              }
              elsif ( $attr>=30 and $attr<=37 ) {
                $self->{foreground} = $attr-30;
              }
              elsif ( $attr>=40 and $attr<=47 ) {
                $self->{background} = $attr-40;
              }
            }
            else {                                # ESC[0m reset
              $self->{foreground} = 7;
              $self->{background} = 0;
              $self->{bold} = 0;
              $self->{underline} = 0;
              $self->{revideo} = 0;
              $self->{concealed} = 0;
            }
          }
          if ($self->{revideo}) {
            $attribut = $color{40+$self->{foreground}}|$color{30+$self->{background}};
          }
          else {
            $attribut = $color{30+$self->{foreground}}|$color{40+$self->{background}};
          }
          $attribut |= FOREGROUND_INTENSITY if $self->{bold};
          $attribut |= BACKGROUND_INTENSITY if $self->{underline};
          $self->{Out}->Attr($attribut);
        }
        elsif ($4 eq 'J') {
          if (!$3) {                            # ESC[0J from cursor to end of display
            my @info = $self->{Out}->Info();
            $self->{Out}->FillChar(' ', ($info[1]-$info[3]-1)*$info[0]+$info[0]-$info[2]-1,$info[2], $info[3]);
          }
          elsif ($3==1) {                       # ESC[1J erase from start to cursor.
            my @info = $self->{Out}->Info();
            $self->{Out}->FillChar(' ', $info[3]*$info[0]+$info[2]+1, 0, 0);
          }
          elsif ($3 == 2) {                     # ESC[2J Clear screen and home cursor
            $self->{Out}->Cls();
            $self->{Out}->Cursor(0, 0);
          }
          else {
            print STDERR "\e$2$3$4" if $DEBUG;     # if ESC-code not implemented
          }
        }
        elsif ($4 eq 'K') {
          my @info = $self->{Out}->Info();
          if (!$3) {                            # ESC[0K Clear to end of line
            $self->{Out}->FillChar(' ', $info[7]-$info[2]+1, $info[2], $info[3]);
          }
          elsif ($3==1) {                       # ESC[1K Clear from start of line to cursor
            $self->{Out}->FillChar(' ', $info[2]+1, 0, $info[3]);
          }
          elsif ($3==2) {                       # ESC[2K Clear whole line.
            $self->{Out}->FillChar(' ', $info[0], 0, $info[3]);
          }
        }
        elsif ($4 eq 'L') {                     # ESC[#L Insert # blank lines.
          $n = $3 eq ''? 1 : $3;  # ESC[L == ESC[1L
          my @info = $self->{Out}->Info();
          $self->{Out}->Scroll(0, $info[3], $info[0]-1, $info[1]-1,
                               0, $info[3]+$n,
                               unpack("c"," "), $self->{Out}->Attr(),
                               0, 0, 10000, 10000);
          $self->{Out}->Cursor($info[2], $info[3]);
        }
        elsif ($4 eq 'M') {                     # ESC[#M Delete # line.
          $n = $3 eq ''? 1 : $3;  # ESC[M == ESC[1M
          my @info = $self->{Out}->Info();
          $self->{Out}->Scroll(0, $info[3]+$n, $info[0]-1, $info[1]-1,
                               0, $info[3],
                               unpack("c"," "), $self->{Out}->Attr(),
                               0, 0, 10000, 10000);
          $self->{Out}->Cursor($info[2], $info[3]);
        }
        elsif ($4 eq 'P') {                     # ESC[#P Delete # characters.
          $n = $3 eq ''? 1 : $3;  # ESC[P == ESC[1P
          my @info = $self->{Out}->Info();
          $n = $info[0]-$info[2] if $info[2]+$n > $info[0]-1;
          $self->{Out}->Scroll($info[2]+$n, $info[3] , $info[0]-1, $info[3],
                               $info[2], $info[3],
                               unpack("c"," "), $self->{Out}->Attr(),
                               0, 0, 10000, 10000);
          $self->{Out}->FillChar(' ', $n, $info[0]-$n, $info[3]);
        }
        elsif ($4 eq '@') {                     # ESC[#@ Insert # blank Characters
          my $s = ' 'x $3;
          my @info = $self->{Out}->Info();
          $s .= $self->{Out}->ReadChar ($info[7]-$info[2]+1, $info[2], $info[3]);
          $s = substr $s, 0, -$3;
          $self->{Out}->Write($s);
          $self->{Out}->Cursor($info[2], $info[3]);
        }
        elsif ($4 eq 'A') {                     # ESC[#A Moves cursor up # lines
          ($x, $y) = $self->{Out}->Cursor();
          $n = $3 eq ''? 1 : $3;  # ESC[A == ESC[1A
          $self->{Out}->Cursor($x, $y-$n);
        }
        elsif ($4 eq 'B') {                     # ESC[#B Moves cursor down # lines
          ($x, $y) = $self->{Out}->Cursor();
          $n = $3 eq ''? 1 : $3;  # ESC[B == ESC[1B
          $self->{Out}->Cursor($x, $y+$n);
        }
        elsif ($4 eq 'C') {                     # ESC[#C Moves cursor forward # spaces
          ($x, $y) = $self->{Out}->Cursor();
          $n = $3 eq ''? 1 : $3;  # ESC[C == ESC[1C
          $self->{Out}->Cursor($x+$n, $y);
        }
        elsif ($4 eq 'D') {                     # ESC[#D Moves cursor back # spaces
          ($x, $y) = $self->{Out}->Cursor();
          $n = $3 eq ''? 1 : $3;  # ESC[D == ESC[1D
          $self->{Out}->Cursor($x-$n, $y);
        }
        elsif ($4 eq 'E') {                     # ESC[#E Moves cursor down # lines, column 1.
          ($x, $y) = $self->{Out}->Cursor();
          $n = $3 eq ''? 1 : $3;  # ESC[E == ESC[1E
          $self->{Out}->Cursor(0, $y+$n);
        }
        elsif ($4 eq 'F') {                     # ESC[#F Moves cursor up # lines, column 1.
          ($x, $y) = $self->{Out}->Cursor();
          $n = $3 eq ''? 1 : $3;  # ESC[F == ESC[1F
          $self->{Out}->Cursor(0, $y-$n);
        }
        elsif ($4 eq 'G') {                     # ESC[#G Moves cursor column # in current row.
          ($x, $y) = $self->{Out}->Cursor();
          $n = $3 eq ''? 1 : $3;  # ESC[G == ESC[1G
          $self->{Out}->Cursor($n-1, $y);
        }
        elsif ($4 eq 'H' or $4 eq 'f') {        # ESC[#;#H or ESC[#;#f Moves cursor to line #, column #
          ($y, $x) = split /\;/, $3;
          $x = 1 unless $x;    # ESC[;5H == ESC[1;5H ...etc
          $y = 1 unless $y;
          $self->{Out}->Cursor($x-1, $y-1);  # origin (0,0) in DOS console
        }
        elsif ($4 eq 's') {                      # ESC[s Saves cursor position for recall later
          ($x, $y) = $self->{Out}->Cursor();
          $self->{x} = $x;
          $self->{y} = $y;
        }
        elsif ($4 eq 'u') {                      # ESC[u Return to saved cursor position
          $self->{Out}->Cursor($self->{x}, $self->{y});
        }
        else {
          print STDERR "\e$2$3$4 not implemented\n" if $DEBUG;  # ESC-code not implemented
        }
      }
      else {
        if ($4 eq 'U') {                         # ESC(U no mapping
          $self->{conv} = 0;
        }
        elsif ($4 eq 'K') {                      # ESC(K mapping if it exist
          $self->{Out}->OutputCP($OEM);      # restore original codepage
          $self->{conv} = 1;
        }
        elsif ($4 eq 'X') {                      # ESC(#X codepage **EXPERIMENTAL**
          $self->{conv} = 0;
          $self->{Out}->OutputCP($3);
        }
        else {
          print STDERR "\e$2$3$4 not implemented\n" if $DEBUG;  # ESC-code not implemented
        }
      }
      # _PrintString($self, $5);
    }
    else {
      $self->{Out}->Write(_conv($self, $s));
      $s='';
    }
  }
}

sub _conv {                     # conversions
  my $self = shift;
  my $s = shift;
  if ( $self->{concealed} ) {
    $s =~ s/\S/ /g;
  }
  elsif ( $self->{conv} ) {
    if ($EncodeOk) {
      from_to($s, $cpANSI, $cpOEM);
    }
    elsif ($cp eq 'cp1252cp850') {      # WinLatin1 --> DOSLatin1
      $s =~ tr{€‚ƒ„…†‡ˆ‰Š‹Ž‘’“”•–—˜™š›žŸ ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ}
              {???Ÿ??????????????????????????ÿ­½œÏ¾Ýõù¸¦®ªð©îøñýüïæôú÷û§¯¬«ó¨·µ¶ÇŽ’€ÔÒÓÞÖ×ØÑ¥ãàâå™žëéêšíèá… ƒÆ„†‘‡Š‚ˆ‰¡Œ‹Ð¤•¢“ä”ö›—£–ìç˜}
    }
    elsif ($cp eq 'cp1252cp437') {      # WinLatin1 --> DOSLatinUS
      $s =~ tr{€‚ƒ„…†‡ˆ‰Š‹Ž‘’“”•–—˜™š›žŸ ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ}
              {??????????????????????????????ÿ­›œ?????¦®ª???øñý??æ?ú??§¯¬«?¨????Ž’€????????¥????™?????š??á… ƒ?„†‘‡Š‚ˆ‰¡Œ‹?¤•¢“?”ö?—£–??˜}
    }
    elsif ($cp eq 'cp1250cp852') {      # WinLatin2 --> DOSLatin2
      $s =~ tr{€‚ƒ„…†‡ˆ‰Š‹Ž‘’“”•–—˜™š›žŸ ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ}
              {??????????æ?›¦??????????ç?œ§«ÿóôÏ¤?õù?¸®ªð?½ø?òˆï???÷¥­¯•ñ–¾èµ¶ÆŽ‘€¬¨Ó·Ö×ÒÑãÕàâŠ™žüÞéëšíÝáê ƒÇ„’†‡Ÿ‚©‰Ø¡ŒÔÐäå¢“‹”öý…£ûìîú}
    }
    elsif ($cp eq 'cp1251cp855') {      # WinCyrillic --> DOSCyrillic
      $s =~ tr{€‚ƒ„…†‡ˆ‰Š‹Ž‘’“”•–—˜™š›žŸ ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ}
              {ƒ?‚??????‘?—•›€??????????–”šÿ™˜Ï??ý…?‡®?ð???‹Š????„ï†¯Ž‰ˆŒ¡£ì­§©êô¸¾ÇÑÓÕ×Ýâäæè«¶¥üöúŸòîøà ¢ë¬¦¨éó·½ÆÐÒÔÖØáãåçªµ¤ûõùžñí÷œÞ}
    }
  }
return $s;
}

sub PRINT {
  my $self = shift;
  my $s;
  {
    local $SIG{__WARN__} = sub {
      warnings::warnif('uninitialized', "Use of uninitialized value in print")};
    $s = join defined $,?$,:'', @_;
  }
  $self->_PrintString($s);
}

sub PRINTF {
  my $self = shift;
  my $format = shift;
  my $s;
  {
    local $SIG{__WARN__} = sub {
      warnings::warnif('uninitialized', "Use of uninitialized value in printf")};
    $s = sprintf $format, @_;
  }
  $self->_PrintString($s);
}

sub CLOSE {
  my $self = shift;
  if ($self->{handle} eq 'STDOUT') {
    undef *STDOUT;
  }
  else {
    undef *STDERR;
  }
}

sub OPEN {
  my $self = shift;
  unless (@_) {
    warnings::warnif('uninitialized', "Use of uninitialized value in open");
    return 1;
  }
  my $n = shift;
  my $r;
  if ($self->{handle} eq 'STDOUT') {
    undef *STDOUT;
    eval{$r = open STDOUT, $n, @_;};
    if ($@) {
      $@ =~ s/ at .*$//;
      chomp $@;
      warnings::warnif('all', $@);
    }
  }
  else {
    undef *STDERR;
    eval{$r = open STDERR, $n, @_;};
    if ($@) {
      $@ =~ s/ at .*$//;
      chomp $@;
      warnings::warnif('all', $@);
    }
  }
  return $r;
}

sub FILENO {
  my $self = shift;
  return $self->{'fileno'};
}

1;

# end print overloading

## Win32::Console::ANSI Module Interface

package Win32::Console::ANSI;

# Create tied filehandles for print overloading.

if (-t STDOUT) {
  tie *STDOUT, 'Win32::Console::ANSI::IO', 'STDOUT';
}
if (-t STDERR) {
  tie *STDERR, 'Win32::Console::ANSI::IO', 'STDERR';
}

# Auxiliary functions

sub Title {
  my $t = shift;
  my $r = Win32::Console::Title();
  Win32::Console::Title($t) if defined $t;
  return $r;
}

sub Cursor {
  return unless defined $CON;
  my ($oldx, $oldy) = $CON->Cursor();
  $CON->Cursor($_[0]-1, $_[1]-1) if 1 < @_;  # origin (0,0) in DOS console
  return ($oldx+1, $oldy+1);
}

1;
__END__

# POD documentation

=head1 NAME

Win32::Console::ANSI - Perl extension to emulate ANSI console on Win32 system.

=head1 SYNOPSIS

  use Win32::Console::ANSI;

  print "\e[1;34mThis text is bold blue.\e[0m\n";
  print "This text is normal.\n";
  print "\e[33;45;1mBold yellow on magenta.\e[0m\n";
  print "This text is normal.\n";

With the Term::ANSIColor module one increases the readability:

  use Win32::Console::ANSI;
  use Term::ANSIColor;

  print color 'bold blue';
  print "This text is bold blue.\n";
  print color 'reset';
  print "This text is normal.\n";
  print colored ("Bold yellow on magenta.\n", 'bold yellow on_magenta');
  print "This text is normal.\n";

And even more with Term::ANSIScreen:

  use Win32::Console::ANSI;
  use Term::ANSIScreen qw/:color :cursor :screen/;

  locate 1, 1; print "@ This is (1,1)", savepos;
  print locate(24,60), "@ This is (24,60)"; loadpos;
  print down(2), clline, "@ This is (3,16)\n";
  setscroll 1, 20;
  color 'black on white'; clline;
  print "This line is black on white.\n";
  print color 'reset'; print "This text is normal.\n";
  print colored ("This text is bold blue.\n", 'bold blue');
  print "This text is normal.\n";
  print colored ['bold blue'], "This text is bold blue.\n";
  print "This text is normal.\n";

=head1 DESCRIPTION

Windows NT/2000/XP does not support ANSI escape sequences in Win32 Console
applications. This module emulates an ANSI console for the script which
uses it.

Caution: this module is still in beta stage; don't use it in a production
script.

=head2 Escape sequences for Cursor Movement

=over

=item * \e[#A

CUU: CUrsor Up: Moves the cursor up by the specified number of lines without
changing columns. If the cursor is already on the top line, this sequence
is ignored. \e[A is equivalent to \e[1A.

=item * \e[#B

CUD: CUrsor Down: Moves the cursor down by the specified number of lines
without changing columns. If the cursor is already on the bottom line,
this sequence is ignored. \e[B is equivalent to \e[1B.

=item * \e[#C

CUF: CUrsor Forward: Moves the cursor forward by the specified number of
columns without changing lines. If the cursor is already in the
rightmost column, this sequence is ignored. \e[C is equivalent to \e[1C.

=item * \e[#D

CUB: CUrsor Backward: Moves the cursor back by the specified number of
columns without changing lines. If the cursor is already in the leftmost
column, this sequence is ignored. \e[D is equivalent to \e[1D.

=item * \e[#E

CNL: Cursor Next Line: Moves the cursor down the indicated # of rows, to
column 1. \e[E is equivalent to \e[1E.

=item * \e[#F

CPL: Cursor Preceding Line: Moves the cursor up the indicated # of rows,
to column 1. \e[F is equivalent to \e[1F.

=item * \e[#G

CHA: Cursor Horizontal Absolute: Moves the cursor to indicated column in
current row. \e[G is equivalent to \e[1G.

=item * \e[#;#H

CUP: CUrsor Position: Moves the cursor to the specified position. The first #
specifies the line number, the second # specifies the column.
If you do not specify a position, the cursor moves to the
home position: the upper-left corner of the screen (line 1, column 1).

=item * \e[#;#f

HVP: Horizontal and Vertical Position.
Works the same way as the preceding escape sequence.

=item * \e[s

SCP: Save Cursor Position: Saves the current cursor position. You can move
the cursor to the saved cursor position by using the Restore Cursor
Position sequence.

=item * \e[u

RCP: Restore Cursor Position: Returns the cursor to the position stored
by the Save Cursor Position sequence.

=back

=head2 Escape sequences for Display Edition

=over

=item * \e[#J

ED: Erase Display:

=over

=item * \e[0J

Clears the screen from cursor to end of display. The cursor position is unchanged.

=item * \e[1J

Clears the screen from start to cursor. The cursor position is unchanged.

=item * \e[2J

Clears the screen and moves the cursor to the home position (line 1, column 1).

=back

\e[J is equivalent to \e[0J. (Some terminal/emulators respond to \e[J as if
it were \e[2J. Here, the default is 0; it's the norm)

=item * \e[#K

EL: Erase Line:

=over

=item * \e[0K

Clears all characters from the cursor position to the end of the line
(including the character at the cursor position).
The cursor position is unchanged.

=item * \e[1K

Clears all characters from start of line to the cursor position.
(including the character at the cursor position).
The cursor position is unchanged.

=item * \e[2K

Clears all characters of the whole line.
The cursor position is unchanged.

=back

\e[K is equivalent to \e[0K.

=item * \e[#L

IL: Insert Lines: The cursor line and all lines below it move down # lines,
leaving blank space. The cursor position is unchanged. The bottommost #
lines are lost. \e[L is equivalent to \e[1L.

=item * \e[#M

DL: Delete Line: The block of # lines at and below the cursor are  deleted;
all  lines below  them  move up # lines to fill in the gap, leaving # blank
lines at the bottom of the screen.  The cursor position is unchanged.
\e[M is equivalent to \e[1M.

=item * \e#\@

ICH: Insert CHaracter: The cursor character and all characters to the right
of it move right # columns, leaving behind blank space.
The cursor position is unchanged. The rightmost # characters on the line are lost.

=item * \e[#P

DCH: Delete CHaracter: The block of # characters at and to the right of the
cursor are deleted; all characters to the right of it move left # columns,
leaving behind blank space. The cursor position is unchanged.
\e[P is equivalent to \e[1P.

=back

=head2 Escape sequences for Set Graphics Rendition

=over

=item * \e[#;...;#m

SGM: Set Graphics Mode: Calls the graphics functions specified by the
following values. These specified functions remain active until the next
occurrence of this escape sequence. Graphics mode changes the colors and
attributes of text (such as bold and underline) displayed on the
screen.

=over

=item * Text attributes

       0    All attributes off
       1    Bold on
       4    Underscore on
       7    Reverse video on
       8    Concealed on

       21   Bold off
       24   Underscore off
       27   Reverse video off
       28   Concealed off

=item * Foreground colors

       30    Black
       31    Red
       32    Green
       33    Yellow
       34    Blue
       35    Magenta
       36    Cyan
       37    White

=item * Background colors

       40    Black
       41    Red
       42    Green
       43    Yellow
       44    Blue
       45    Magenta
       46    Cyan
       47    White

=back

\e[m is equivalent to \e0m.

=back

=head2 Escape sequences for Select Character Set

=over

=item * \e(U

Select null mapping - straight to character from the codepage of the console.

=item * \e(K

Select Windows to DOS mapping, if the corresponding map exist; no effect
otherwise. This is the default mapping (if the map exist, of course). It's
useful because one types the script with a Windows-based editor (using a
Windows codepage) and the script prints its messages on the console using
another codepage: without translation, the characters with a code greatest
than 127 are different and the printed messages may be not readable.

The conversion is done by the module Encode if it is installed (it's a
standard module with Perl5.8). Otherwise, the conversion is limited to the
following couples:

    WinLatin1 (cp1252)  to DOSLatin1  (cp850)
    WinLatin1 (cp1252)  to DOSLatinUS (cp437)
    WinLatin2 (cp1250)  to DOSLatin2  (cp852)
    WinCyrillic(cp1251) to DOSCyrillic (cp855)

=item * \e(#X

This escape sequence is I<not> standard! It's an experimental one, just for
fun :-)

If (I<and only if>) the console uses an Unicode police, it is possible to
change its codepage with this escape sequence. No effect with an ordinary
"Raster Font". (For Windows NT/2000/XP the currently available Unicode
console font is the Lucida Console TrueType font.)
# is the number of the codepage needed, 855 for cp855 for instance.

=back

=head1 AUXILIARY FUNCTIONS

Because the module exports no symbols into the callers namespace, it's 
necessary to import the names of the functions before using them.

=over

=item * $old_title = Title( [$new_title] );

Gets and sets the title bar of the current console window. With no argument
the title is not modified.

  use Win32::Console::ANSI qw/ Title /;
  for (reverse 0..5) {
    Title "Count down ... $_";
    sleep 1;
  }

=item * ($old_x, $old_y) = Cursor( [$new_x, $new_y] );

Gets and sets the cursor position (the upper-left corner of the screen is
at (1, 1)). With no arguments the cursor position is not modified. If one
of the two coordinates $new_x or $new_y is 0, the the corresponding
coordinate doesn't change.

  use Win32::Console::ANSI qw/ Cursor /;
  ($x, $y) = Cursor();     # reads cursor position
  Cursor(5, 8);            # puts the cursor at column 5, line 8
  Cursor(5, 0);            # puts the cursor at column 5, line doesn't change
  Cursor(0, 8);            # puts the cursor at line 8, column doesn't change
  Cursor(0, 0);            # the cursor doesn't change a position (useless!)
  ($x, $y) = Cursor(5, 8); # reads cursor position AND puts cursor at (5, 8)

=back

=head1 LIMITATIONS

=over

=item *

Due to DOS-console limitations, the blink mode (text attributes 5 and 25) is
not implemented.

=item *

Because with this module C<STDERR> and C<STDOUT> are tied filehandles it's
not possible to duplicate them as usual:

  open(OUTCOPY, ">&STDOUT");  # the tie is broken

If you print in C<OUTCOPY> the conversion is lost.

As a consequence this module is incompatible with the 
L<IPC::Open2|IPC::Open2> and L<IPC::Open3|IPC::Open3> modules.

=item *

It has been reported that this module is not thread-safe. There is a
problem with the method C<join>: C<STDOUT> is sometimes mysteriously closed.
It's an odd bug in the C<Win32::Console> module.

=back

=head1 SEE ALSO

L<Win32::Console>, L<Term::ANSIColor>, L<Term::ANSIScreen>.

=head1 AUTHOR

J-L Morel E<lt>jl_morel@bribes.orgE<gt>

Home page: http://www.bribes.org/perl/wANSIConsole.html

=head1 CREDITS

Render unto Cæsar the things which are Cæsar's...

This module use the module Win32::Console. Thanks to Aldo Calpini.

The method used to overload the print function is due to Matt Sergeant
(see his module Win32::ASP).

=head1 COPYRIGHT

Copyright (c) 2003-2005 J-L Morel. All rights reserved.

This program is free software; you can redistribute it and/or modify it under
the same terms as Perl itself.

=cut
