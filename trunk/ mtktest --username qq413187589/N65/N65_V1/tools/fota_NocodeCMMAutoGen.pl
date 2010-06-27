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
#*****************************************************************************

&Usage if ($#ARGV != 1);

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /^(\w+)\=(\S+)/i) {
    $keyname = $1;
    $$keyname = $2;
  }
  shift(@ARGV);
}

if ($themf =~ /make\\(\w+)_(\w+).mak/i) {
  $customer = uc($1);
  $mode = uc($2);
}

  open (FILE_HANDLE, "<$themf") or die "cannot open $themf\n";
  while (<FILE_HANDLE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = lc($1);
      defined($${keyname}) && warn "$1 redefined in $themf!\n";
      $${keyname} = uc($2);
    }
  }

print &legal_disclaimer();
print &specify_reset_func();
print "\n";
print &setting_EMI_and_watchdog();
print "\n";
print &specify_load_elf;
print "\n";
print &specify_load_path;
print "\n";
print &set_hw_breakpoint_by_def($plat);
print "\n";
print &clean_win_and_endup($plat);
print "\n";

exit 0;

sub specify_reset_func {
  my $for_OTHERS = <<"__FOR_OTHERS";
SYStem.RESet
SYStem.CPU ARM9E
;SYStem.JtagClock 2000000.
SYStem.JtagClock RTCK.
sys.o cflush on
SYStem.Up
setup.IMASKHLL ON
setup.IMASKASM ON
__FOR_OTHERS

  return $for_OTHERS;
}

sub setting_EMI_and_watchdog {
  my $for_TYPE3 = <<"__FOR_TYPE3";

D.S SD:0x80040000 %LE %WORD 2200      ; Disable Watch Dog Timer 
__FOR_TYPE3
;

  if (($platform eq "MT6228") || ($platform eq "MT6229") || ($platform eq "MT6230")) {
  $for_TYPE3 .= <<"__FOR_TYPE3";
D.S SD:0x80010060 %LE %WORD 0x00       ; Start from BootROM
R.S PC 0x00
__FOR_TYPE3
;
  } else {
  $for_TYPE3 .= <<"__FOR_TYPE3";
D.S SD:0x80010040 %LE %WORD 0x00       ; Start from BootROM
R.S PC 0x00
__FOR_TYPE3
;
  }
  return $for_TYPE3;
}

sub specify_load_elf {
  my $elf_name = "${customer}_FOTA_${platform}_${verno}.elf";

  my $for_OTHERS = <<"__FOR_OTHERS";
D.LOAD.ELF .\\BUILD\\${customer}\\${elf_name} /nocode
__FOR_OTHERS

  return $for_OTHERS;
}

sub specify_load_path {
  my $for_OTHERS = <<"__FOR_OTHERS";
; set the path for source level debugging
y.spath .\\fota\\src
y.spath .\\custom\\system\\${board_ver}
y.spath .\\applib\\misc\\src
__FOR_OTHERS

  return $for_OTHERS;
}

sub set_hw_breakpoint_by_def {
  my $for_OTHERS = <<"__FOR_OTHERS";
; setting attribute of breakpoints
Break.Select Program OnChip
Break.Select Hll OnChip
Break.Select Spot OnChip
Break.Select Read OnChip
Break.Select Write OnChip
__FOR_OTHERS

  return $for_OTHERS;
}

sub clean_win_and_endup {
  my $for_TYPE4 = <<"__FOR_TYPE4";
winclear
d.l
enddo
__FOR_TYPE4

  return $for_TYPE4;
}

sub Usage {
  warn " Usage:\n";
  warn "     $0 Makefile\n";
  exit 1;
}

sub legal_disclaimer {
  my $for_OTHERS = <<"__FOR_OTHERS";
; Copyright Statement:
; --------------------
; This software is protected by Copyright and the information contained
; herein is confidential. The software may not be copied and the information
; contained herein may not be used or disclosed except with the written
; permission of MediaTek Inc. (C) 2005
; 
; BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
; THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
; RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
; AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
; EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
; MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
; NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
; SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
; SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
; THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
; NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
; SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
; 
; BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
; LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
; AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
; OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
; MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
; 
; THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
; WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
; LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
; RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
; THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

__FOR_OTHERS

  return $for_OTHERS;
}

