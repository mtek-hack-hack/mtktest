#!/usr/bin/perl -W
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#
#*****************************************************************************

#use strict;
use Fcntl;

if ($#ARGV != 1) { &Usage; }
#die "Please use 5.8.6 or later Perl interpreter\n" if $] < 5.008005;

#
# NP3R - 0 : (under construction) pre-processing & info gathering from makefile
#
$prefix_path = $ARGV[0];
$themf = $ARGV[1];

die "$themf did NOT exist!\n" if (!-e $themf);
open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $${keyname} = uc($2);
  }
}
close (FILE_HANDLE);

#
# NP3R - 1 : determine if _NAND_FLASH_BOOTING_ defined
#

if (not defined $nand_flash_booting or $nand_flash_booting ne "TRUE")
{
    exit(0);
}

#
# NP3R - 2 : Global Configuration section
#
my $EnfbOutputfile = "THIRD_ROM";
my %EnfbInputFiles = (
"CustENFBImg\0" => "plutommi\\Customer\\CustResource\\CustENFBImgData",
"CustENFBStr\0" => "plutommi\\Customer\\CustResource\\CustENFBStrData",
);
my $EnfbReservedHearderSize = 256;
my $EnfbAlignToSize         =  64;
#
# NP3R - 3 : read the pre-defined 3rd ROM header content
#
my %EnfbInputKeys;  # Key ==> id
my %EnfbInputBegin; # Key ==> begin
my %EnfbInputEnd;   # Key ==> end
my %EnfbBinFiles;   # Key ==> external bin file length
my $buffer;
$EnfbOutputfile = $prefix_path . $EnfbOutputfile;

sysopen( HANDLE, $EnfbOutputfile, O_RDWR ) or die $!;
binmode(HANDLE);
while ( sysread(HANDLE, $buffer, 32) )
{
#   my (@ID, $cid, $begin, $length, @Desc) = unpack "C11CVVC12", $buffer;
   my @buf = unpack "C11CVVC12", $buffer;
   my $cid = $buf[11];
   my $begin = $buf[12];
   my $length = $buf[13];
   my $key = pack "C12", splice(@buf, 14, 12);
   my $idstring = pack "C7", splice(@buf, 0, 7);
   #printf "ID = %x , \t %s \t %x \t %x \n", $cid, $key, $begin, $length;
   if ($cid eq 0xff)
   {
       &AdjustDynamicCodeBeginEnd($begin);
       last;
   }
   if (defined $EnfbInputFiles{$key}) # external binary file ...
   {
       $EnfbInputKeys{$key}  = $cid;
       next;
   }
   if ($length > 0                  ) # dynamic code linked ...
   {
       $EnfbInputKeys{$key}  = $cid;
       $EnfbInputBegin{$key} = $begin;
       $EnfbInputEnd{$key}   = $begin + $length - 1;
   }
   last unless ($idstring eq "ENFB3RD");
}
#
# NP3R - 4 : testing existing of external members in the 3rd rom
#
&ChkAllExternalBehindDynamicCode();
foreach (keys %EnfbInputKeys)
{
    next if not defined $EnfbInputFiles{$_};
    my $f = $EnfbInputFiles{$_};
    if (-e $f)
    {
        $EnfbBinFiles{$_} = (stat $f )[7];
    }
    else
    {
        print "External Binary File $_ ==> $f not found\n";
        delete $EnfbInputKeys{$_};
    }
}
#
# NP3R - 5 : correct 3RD ROM header , synthetize external content to 3RD ROM
#
&SetupExternalBinOffset();
&DumpInternal3rdRomHeader();
my $read_pos = sysseek(HANDLE, 0, 1); # SEEK_CUR 
my @SortedKeyList = sort { $EnfbInputKeys{$a} <=> $EnfbInputKeys{$b} } keys %EnfbInputKeys;
sysseek(HANDLE, 0, 0);

foreach my $h (@SortedKeyList)
{
   $buffer = &Pack_enfb_header( $EnfbInputKeys{$h},
                                $EnfbInputBegin{$h},
                                $EnfbInputEnd{$h},
                                $h);
   syswrite(HANDLE, $buffer, 32);
}
$buffer = &Pack_enfb_header( 0xff, 0, 0, "ENDMARK");
syswrite(HANDLE, $buffer, 32);
   # Zero Padding ---
my $write_pos = sysseek(HANDLE, 0, 1); # SEEK_CUR 
#print "Read position : $read_pos\n";
#print "Write position : $write_pos\n";
if ($read_pos > $write_pos)
{
   $buffer = chr(0) x ($read_pos - $write_pos);
   syswrite(HANDLE, $buffer, $read_pos - $write_pos);
}
   # External Binary Append
my $cur_pos;
#$cur_pos = sysseek(HANDLE, 0, 2); # SEEK_END
#print "Current position : $cur_pos\n";
foreach my $h (@SortedKeyList)
{
    next if not defined $EnfbBinFiles{$h};
    # Padding To
    $cur_pos = sysseek(HANDLE, 0, 2); # SEEK_END
    if ($EnfbInputBegin{$h} > $cur_pos)
    {
       $buffer = chr(0) x ($EnfbInputBegin{$h} - $cur_pos);
       syswrite(HANDLE, $buffer, ($EnfbInputBegin{$h} - $cur_pos));
    }
    # Append To
    sysopen(EXTBIN, $EnfbInputFiles{$h} , O_RDONLY) or die $!;
    binmode(EXTBIN);
    my $read_len = sysread(EXTBIN, $buffer, 8192);
    while ($read_len)
    {
       syswrite(HANDLE, $buffer, $read_len);
       $read_len = sysread(EXTBIN, $buffer, 8192);
    }
    close(EXTBIN);
}
$cur_pos = sysseek(HANDLE, 0, 2); # SEEK_END
print "Tail position : $cur_pos\n";

close (HANDLE);
exit(0);
#
# NP3R ------ End of MAIN BODY ----------- 
#

sub Align
{
   my ($size, $orig) = @_;

   return $size * (int($orig/$size) + 1);
}

sub Pack_enfb_header
{
   my ($cid, $begin, $end, $description ) = @_;
   my $ID = "ENFB3RDROM!";
   my @ID = unpack "C*", $ID;
   my $buf;
   my @Desc  = unpack "C*", $description;

   $buf = pack "C11CVVC12", @ID, $cid, $begin, $end, @Desc ;
   return $buf;
}

#
# NP3R ------ Shift the being & end ------
#
sub AdjustDynamicCodeBeginEnd
{
    my ($base)  = @_;
    foreach my $k (keys %EnfbInputKeys)
    {
        next unless defined $EnfbInputBegin{$k};
        $EnfbInputBegin{$k} -= $base;
        $EnfbInputEnd{$k}   -= $base;
    }
}

#
# NP3R ------ Debug use ------
#
sub DumpInternal3rdRomHeader
{
    foreach my $k (sort { $EnfbInputKeys{$a} <=> $EnfbInputKeys{$b} } keys %EnfbInputKeys)
    {
        if (defined $EnfbBinFiles{$k})  # external binary files
        {
           print $k, "\t", $EnfbInputKeys{$k}, "\t", $EnfbInputBegin{$k}, "\t", $EnfbInputEnd{$k}, "\t";
           print "External BIN files\t size : ", $EnfbBinFiles{$k} , "\n";
        }
        else   # linked dynamic code on NAND flash
        {
           print $k, "\t", $EnfbInputKeys{$k}, "\t", $EnfbInputBegin{$k}, "\t", $EnfbInputEnd{$k}, "\n";
        }
    }
}

#
# NP3R ------ check if external bin cid larger than internal code cid ------
#
sub ChkAllExternalBehindDynamicCode
{
    my @codelist = keys %EnfbInputEnd;
    #print "CODE LIST at Chk: $#codelist \n";
    #map { print "CODE: ", $_, "\n"; } @codelist;
    return if ($#codelist == -1);
    my @SortedKeyList = sort { $EnfbInputKeys{$a} <=> $EnfbInputKeys{$b} } keys %EnfbInputKeys;
    my @SortedCodeList = sort { $EnfbInputKeys{$a} <=> $EnfbInputKeys{$b} } @codelist;
    my $lastidx = $#codelist;
    die "External BIN cid must behind code cid" 
    unless ($SortedCodeList[$lastidx] eq $SortedKeyList[$lastidx]);
}

#
# NP3R ------ check if external bin cid larger than internal code cid ------
#
sub SetupExternalBinOffset
{
    my @codelist = keys %EnfbInputEnd;
    #print "CODE LIST at Setup: $#codelist \n";
    #map { print "CODE: ", $_, "\n"; } @codelist;
    my $ExtBinBegin;
    if ($#codelist == -1)
    {
       $ExtBinBegin = $EnfbReservedHearderSize;
    }
    elsif ($#codelist == 0)
    {
       $ExtBinBegin = &Align( $EnfbAlignToSize, $EnfbInputEnd{ $codelist[-1] } );
    }
    else
    {
       my @SortedCodeList = sort { $EnfbInputKeys{$a} <=> $EnfbInputKeys{$b} } @codelist;
       #print "The Last one : ", $SortedCodeList[-1], "\n";
       $ExtBinBegin = &Align( $EnfbAlignToSize, $EnfbInputEnd{ $SortedCodeList[-1] } );
    }
    # okay , external bin setup begin and offset
    foreach my $ebin ( sort { $EnfbInputKeys{$a} <=> $EnfbInputKeys{$b} } keys %EnfbBinFiles)
    {
       $EnfbInputBegin{$ebin} = $ExtBinBegin;
       $EnfbInputEnd{$ebin}   = $ExtBinBegin + $EnfbBinFiles{$ebin} - 1;
       $ExtBinBegin  = &Align( $EnfbAlignToSize, $ExtBinBegin + $EnfbBinFiles{$ebin} );
    }
}

sub Usage {
   print "perl nfbpack3rdrom.pl <binary path> <Project MakeFile>\n";
}

