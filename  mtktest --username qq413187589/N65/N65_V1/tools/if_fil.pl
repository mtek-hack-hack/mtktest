#!/usr/bin/perl
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
#!/usr/bin/perl
# filter out the lines having no define options


#
# parsing command arguments
#
my $line_no;
$debug_print = 0; # 1 for debug; 0 for non-debug

if (!($ARGV[0] =~ /\.(h|c|hpp|cpp|s|java)$/i))
{
   &usage;
}
if (!(($ARGV[1] =~ /info\.log$/i) || ($ARGV[1] =~ /\.def$/i)) || !($ARGV[2] =~ /\.def$/i))
{
   &usage;
}
if (!($ARGV[3] =~ /\.(h|c|hpp|cpp|s|java)$/i))
{
   &usage;
}

#
#get %opt_list
#
$ENOPT_FILE = $ARGV[1];
open ENOPT_FILE, "<$ENOPT_FILE" or die "cannot open $ENOPT_FILE\n";

$is_option_area = -1;   # -1: not in a option area
                        #  1: in a option area
$log_turnon     = "[ COMMON OPTION ]";
$log_turnoff    = "[ COMMON INCLUDE PATH ]";
$opt_no = 0;
while (<ENOPT_FILE>)
{
    $read_line = $_;

    if ((index($read_line, $log_turnon) >=0) && ($is_option_area == -1))
    {
        $is_option_area = 1;
    }
    elsif ((index($read_line, $log_turnoff) >=0) && ($is_option_area == 1))
    {
        $is_option_area = -1;
    }
    else
    {
        if ($is_option_area == 1)
        {
            $read_line =~ s/\s*(\w+)\s*(\n)+/$1/;
            $opt_list{$read_line} = 1;
            $opt_no ++;
        }
    }
}
close ENOPT_FILE;
#print $opt_no;
#exit(0);

$DISOPT_FILE = $ARGV[2];
open DISOPT_FILE, "<$DISOPT_FILE" or die "cannot open $DISOPT_FILE\n";
while (<DISOPT_FILE>)
{
    s/\s*(\w+)\s*(\n)+/$1/;
    $opt_list{$_} = 0;
}
close DISOPT_FILE;

while ( ($key, $value) = each %opt_list)
{
   #print "$key => $value\n";
}

#
# open source file & result file
#
$SRC_FILE = $ARGV[0];
$is_exist = 0;
$is_exist = 1 if -e $SRC_FILE;
if ($is_exist == 1)
{
    open SRC_FILE, "<$SRC_FILE" or die "cannot open $SRC_FILE\n";
}
else
{
    print "$SRC_FILE is not existed!!!\n";
    exit(0);
}

$RSLT_FILE = $ARGV[3];
open RSLT_FILE, ">$RSLT_FILE" or die "cannot open $RSLT_FILE\n";

#
# record lines in multi-line comments in %in_mline_cmt_list
# !!!nested comments are not applicable
#
# %in_mline_cmt_list is used to record the line which is in a multi-line comment
# $key : line number in a multi-line comment
# $value 0: the beginning line of the multi-line comment
#        1: the line between the beginning and the end lines of the multi-line comment
#        2: the end line of the multi-line comment
#        3: the end line of one multi-line comment & the beginning line of another multi-line comment
$is_in_mline_cmt = 0;
$line_no = 1;
#print "scanning comment\n";
while (<SRC_FILE>)
{
    my $line = $_;
    my $cmt_ptn;

    if ($is_in_mline_cmt == 1)
    {
        if ($line =~ /\*\//)
        {
            $in_mline_cmt_list{$line_no} = 2;
            $is_in_mline_cmt = 0;
            $line =~ s{.*?\*/}{};
        }
        else
        {
            $in_mline_cmt_list{$line_no} = 1;
        }
#       print $in_mline_cmt_list{$line_no};
    }
    else
    {
#        print "-";
    }

    while ( $line =~ /\/\/|\/\*/ )
    {
        $cmt_ptn = $&;

        if ( $line =~ /\".*?(\/\/|\/\*).*?\"/ )
        {
            last;
        }
#        print "$line \t $cmt_ptn \n";

        if ($cmt_ptn =~ /\/\//)
        {
            $line =~ s{//.*}{\n};
        }
        elsif ($cmt_ptn =~ /\/\*/)
        {
            $line =~ /\/\*/;
            if ($' =~ /\*\//)
            {
                $line =~ s{/\*.*?\*/}{};
            }
            else
            {
                $in_mline_cmt_list{$line_no} = ( exists $in_mline_cmt_list{$line_no} )? 3 : 0;
                $is_in_mline_cmt = 1;
#                print $in_mline_cmt_list{$line_no};
                last;
            }
        }
    }
    $line_no ++;
#    print "$line_no \n";
} # foreach (<SRC_FILE>) of record lines in multi-line comments in %in_mline_cmt_list
seek(SRC_FILE, 0, 0);


#print "start parsing...\n";
#
# parsing directives: #if, #ifdef, #ifndef, #endif, #else, #elif
#
$line_no = 1;
while (<SRC_FILE>)
{
    $read_line = $_;

    print "$line_no\t" if ($debug_print == 1);
    if (((/^\s*\#if/) || (/^\s*\/\*.*\*\/\s*\#if/)) && !($in_mline_cmt_list{$line_no} > 0))
    {
        print RSLT_FILE $read_line;
        # remove the comment in expression first
        $uncommented_line = &rm_cmt($read_line);
        while ($uncommented_line eq 'A non-ended multiple-line comment!!!')
        {
            chomp($read_line);
            print "$uncommented_line\n" if ($debug_print == 1);
            $extra_line       = <SRC_FILE>;
            $line_no ++;
            print "$line_no\t" if ($debug_print == 1);
            print RSLT_FILE $extra_line;
            $read_line       .= $extra_line;
            $uncommented_line = &rm_cmt($read_line);
        }
        &do_ifxxx($uncommented_line);
    }
    elsif (((/^\s*\#endif/) || (/^\s*\/\*.*\*\/\s*\#endif/)) && !($in_mline_cmt_list{$line_no} > 0))
    {
        print RSLT_FILE $read_line;
        &do_endif;
    }
    elsif (((/^\s*\#else/) || (/^\s*\/\*.*\*\/\s*\#else/)) && !($in_mline_cmt_list{$line_no} > 0))
    {
        print RSLT_FILE $read_line;
        &do_else;
    }
    elsif (((/^\s*\#elif/) || (/^\s*\/\*.*\*\/\s*\#elif/)) && !($in_mline_cmt_list{$line_no} > 0))
    {
        print RSLT_FILE $read_line;
        # remove the comment in expression first
        $uncommented_line = &rm_cmt($read_line);
        while ($uncommented_line eq 'A non-ended multiple-line comment!!!')
        {
            chomp($read_line);
            print "$uncommented_line\n" if ($debug_print == 1);
            $extra_line       = <SRC_FILE>;
            $line_no ++;
            print "$line_no\t" if ($debug_print == 1);
            print RSLT_FILE $extra_line;
            $read_line       .= $extra_line;
            $uncommented_line = &rm_cmt($read_line);
        }
        &do_elif($uncommented_line);
    }
    else
    {
        if (@if_stack != ())
        {
            my $need_prn;
            my $need_removal = 0;

            for ($i=$#if_stack; $i>=0; $i--)
            {
                $if_truth_value_list = $if_stack[$i];
                $if_truth_value_list =~ m/(\w)\s*$/;
                $need_prn = $1;
                print "<$need_prn>" if ($debug_print == 1);
                if ($need_prn =~ /0/)
                {
                    $need_removal = 1;
                    last;
                }
            }
            print "\n" if ($debug_print == 1);

            ($need_removal == 1) ?
                print RSLT_FILE "/* under construction !*/\n" :
                print RSLT_FILE $read_line;
        }
        else
        {
            print RSLT_FILE $read_line;
            print "1\n" if ($debug_print == 1);
        }
    }
    $line_no ++;
} # foreach (<SRC_FILE>) of parsing directives: #if, #ifdef, #ifndef, #endif, #else, #elif

close SRC_FILE;

# show usage
sub usage
{
	print "USAGE: perl if_fil.pl <source file> <enabled define options> <disabled define options> <destination file>\n";
	exit(0);
}

# remove comment in line
sub rm_cmt
{
    my $line;
    my $cmt_ptn;

    $_ = $_[0];
    while (/\/\/|\/\*/)
    {
        $line = $_;
        $cmt_ptn = $&;
        if ($cmt_ptn =~ /\/\//)
        {
            $line =~ s{//.*\n}{\n};
        }
        elsif ($cmt_ptn =~ /\/\*/)
        { # nested comments are not applicable!!!
            if ($line =~ /\*\//)
            {
                $line =~ s{/\*.*?\*/}{};
            }
            else
            {
                return "A non-ended multiple-line comment!!!";
            }
        }
        $_ = $line;
    }
    $_;
}

# determine the truth value of a conditional expression
sub truth_exp
{
    my $line;
    my $opt;
    my $opt_value;
    my $exp_rslt;
    my $undetermin_cnt = 0;

    $_ = $_[0];
    s/defined//g;
    while (/\w\w+/)
    {
        $line = $_;
        $opt = $&;
        if ( exists $opt_list{$opt})
        {
            $opt_value = $opt_list{$opt};
            $line =~ s/$opt/$opt_value/;
        }
        else
        {
            $undetermin_cnt ++;
            $line =~ s/$opt/_/;
            #print "[$line]";
        }
        $_ = $line;
    }

    #print "[$undetermin_cnt]";
    $line = $_;
    if ($undetermin_cnt == 0)
    {
        $exp_rslt = `perl -e "print ($line)"`;
    }
    else # if ($undetermin_cnt > 0)
    {
        my $pre_exp_rslt = -1;
        foreach (0..2**$undetermin_cnt-1)
        {
            #print "\n$_ = ";
            my $i = $_;
            my $ln = $line;
            foreach (1..$undetermin_cnt)
            {
                my $mod = $i % 2;
                $ln  =~ s/_/$mod/;
                $i -= $mod;
                $i /= 2;
            }

            $exp_rslt = `perl -e "print ($ln)"`;
            #print "[$exp_rslt]";
            if ($pre_exp_rslt == -1)
            {
                $pre_exp_rslt = $exp_rslt;
            }
            else
            {
                if ($pre_exp_rslt != $exp_rslt)
                {
                    $exp_rslt = "";
                    last;
                }
            }
        } # foreach (0..2**$undetermin_cnt-1)
    }
    if ($exp_rslt =~ /1/)
    {
        # print "$line ==> $exp_rslt";
        return "1 ";
    }
    elsif ($exp_rslt =~ /0/)
    {
        # print "$line ==> $exp_rslt";
        return "0 ";
    }
    else
    {
        return "_ ";
    }
}

# do for #ifndef, #ifdef, #if
sub do_ifxxx
{
    my $truth_value;

    # determine current expression truth value
    $_ = $_[0];
    if ( (s/^\s*\#ifndef\s+(.+)\n$/$1/) || (s/^\s*\/\*.*\*\/\s*\#ifndef\s+(.+)\n$/$1/))
    {
        s/\s+/ /g;
        s/\s+$//;
        $opt = $_;
        if ( exists $opt_list{$opt} )
        {
            if ($opt_list{$opt} == 0) # is in the $dis_opt_list
            {
                $truth_value = "1 ";
            }
            elsif ($opt_list{$opt} == 1) # is in the $en_opt_list
            {
                $truth_value = "0 ";
            }
        }
        else # $opt is in neither $en_opt_list nor $dis_opt_list
        {
            $truth_value = "_ ";
        }
        print "#ifndef $opt  ==>  $truth_value\n" if ($debug_print == 1);
    }
    elsif ( (s/^\s*\#ifdef\s+(.+)\n$/$1/) || (s/^\s*\/\*.*\*\/\s*\#ifdef\s+(.+)\n$/$1/))
    {
        s/\s+/ /g;
        s/\s+$//;
        $opt = $_;
        if ( exists $opt_list{$opt} )
        {
            if ($opt_list{$opt} == 0) # is in the $dis_opt_list
            {
                $truth_value = "0 ";
            }
            elsif ($opt_list{$opt} == 1) # is in the $en_opt_list
            {
                $truth_value = "1 ";
            }
        }
        else # $opt is in neither $en_opt_list nor $dis_opt_list
        {
            $truth_value = "_ ";
        }
        print "#ifdef $opt  ==>  $truth_value\n" if ($debug_print == 1);
    }
    elsif ( (s/^\s*\#if\s+(.+)\n$/$1/) || (s/^\s*\/\*.*\*\/\s*\#if\s+(.+)\n$/$1/))
    {
        $truth_value = &truth_exp($_);
        print "#if $_  ==>  $truth_value\n" if ($debug_print == 1);
    }

    # push an entry into @if_stack
    push @if_stack, $truth_value;
}

# do for #endif
sub do_endif
{
    pop @if_stack;
    print "#endif\n" if ($debug_print == 1);
}

# do for #else
sub do_else
{
    $if_stack[-1] .= ($if_stack[-1] =~ /1/) ? "0 " : "1 ";

    # Just fur debug
    $_ = $if_stack[-1];
    m/(\d)\s*$/;
    print "#else  ==>  $1\n" if ($debug_print == 1);
}

# do for #elif
sub do_elif
{
    my $truth_value;

    $_ = $_[0];
    s/^\s*\#elif\s+(.+)\n$/$1/;
    $truth_value = &truth_exp($_);
    $if_stack[-1] .= $truth_value;
    print "#elif $if_stack[-1]\n" if ($debug_print == 1);
}
