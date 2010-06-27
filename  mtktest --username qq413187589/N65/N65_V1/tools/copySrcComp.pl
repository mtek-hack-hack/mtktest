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
# find out required .(hpp|h|dat|c|hex) for the header sources listed in .lis and in .dep

# show usage
sub usage
{
	print "USAGE: perl copySrcComp.pl <filename of .lis> <path of .dep> <tmp file path> <release dir>\n";
	exit(0);
}

#
# parsing command arguments
#

my $arg_idx=0;
my $LIS_FILE;
my $DEP_FILE;
my $reading;

if (!($ARGV[0] =~ /\.lis$/))
{
   usage();
}

#
# open .lis & .dep
#

$LIS_FILE = $ARGV[0];
open LIS_FILE,"$LIS_FILE" or die "cannot open $LIS_FILE\n";

if ($ARGV[0] =~ /.+\\(.+).lis/) {
	$DEP_FILE = "$ARGV[1]\\".$1.".dep";
	$module = $1;
} else {
	die "Cannot get module name.";
}
print "$DEP_FILE\n";
print "$module\n";

open DEP_FILE,"$DEP_FILE" or die "cannot open $DEP_FILE\n";

#print "$LIS_FILE and $DEP_FILE are OPENED\n";

#
#
#

@reading    = <LIS_FILE>;
$obj_count  = 0;
$obj_list   = '';
foreach (@reading)
{
   if (s/\S+\\(\w+)\.cp?p?\s*$/\L$1.obj/i) # extract '*.c'
   {
      $obj_list .= " $_";
#      print "$_\n";
      $obj_count++;
   }
}
close LIS_FILE;
#print "$obj_count .obj will be checked for the dependency\n";
#print $obj_list;

@reading = <DEP_FILE>;
$dep_count = 0;
$hdr_count = 0;
$needed_obj = 0;
foreach (@reading)
{
   if (/\.obj/)
   {
      $reading = $_;

      s/(\w+\.obj).+\n/\L$1/;                # extract '*.obj' from .dep
      if (index($obj_list, $_) > -1)         # if the '.obj' is needed in .lis
      {
         $needed_obj = 1;

#         print "\n\n$dep_count\t";
         while ($reading =~ /\b\S+\.(hpp|h|dat|c|hex)/)      # find out next .(hpp|h|dat|c|hex) in this line
         {
            $hdr_name = "\L$&";
            $reading = ($`).($');
            if ( !($hdr_name =~ /c:/) )      # exclude the c:\progra~1\...\xxx.(hpp|h|dat|c|hex)
            {
               if ( !($req_hdr{$hdr_name}) ) # find out non-duplicated .(hpp|h|dat|c|hex)
               {
                  $req_hdr{$hdr_name} = 1;
                  $hdr_count ++;
#                  print "[$hdr_name]\t";
               }
               else
               {
                  $req_hdr{$hdr_name} ++;    # count duplication times of .(hpp|h|dat|c|hex), just for our info.
               }
            }
         }
         $dep_count++;
      }
      else
      {
         $needed_obj = 0;
      }
   }
   elsif (/\.(hpp|h|dat|c|hex)/ && $needed_obj == 1)
   {
      $reading = $_;

      while ($reading =~ /\b\S+\.(hpp|h|dat|c|hex)/)         # find out next .(hpp|h|dat|c|hex) in this line
      {
         $hdr_name = "\L$&";
         $reading = ($`).($');
         if ( !($hdr_name =~ /c:/) )      # exclude the c:\progra~1\...\xxx.(hpp|h|dat|c|hex)
         {
            if ( !($req_hdr{$hdr_name}) ) # find out non-duplicated .(hpp|h|dat|c|hex)
            {
               $req_hdr{$hdr_name} = 1;
               $hdr_count ++;
#               print "[$hdr_name]\t";
            }
            else
            {
               $req_hdr{$hdr_name} ++;    # count duplication times of .(hpp|h|dat|c|hex), just for our info.
            }
         }
      }
   }
}
close DEP_FILE;

print "\n\n$hdr_count .(hpp|h|dat|c|hex) will be copied: \n";
$output = "~"."$module"."rh.tmp";
print "out = $output\n";

open(W,">$ARGV[2]\\$output");
while ( ($key, $value) = each %req_hdr)
{
   print W "$key\n";

   # Copy header files at the same time.
   print "Copying file $key\n";
   $targetfile = "$ARGV[3]"."\\$key";
   
   if (!-e $targetfile) {
      system("md $targetfile");
      system("rd $targetfile");
      system("copy /y $key $targetfile");
   }
}
close(W);

# dump header file list to make\~srccomprh.tmp
system("type make\\$output >> make\\~srccomprh.tmp");

system("echo $DEP_FILE $module >> make\\module.tmp");
