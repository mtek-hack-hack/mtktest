#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
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
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   emiGem.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script will
#*       1. parse custom_MemoryDevice.h to get memory device type and part number
#*       2. parse custom_EMI.h to retrieve the EMI setting 
#*       3. calc the latency on the specific platform
#*
#* Author:
#* -------
#*   JI Huang      (mtk01077)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
use Win32::OLE qw(in with);


#****************************************************************************
# Constants
#****************************************************************************
my $EMIMCPCHECK_VERNO  = " V1.01";

my $PLATFORM                  = $ARGV[0];
my $MODE                      = $ARGV[1];
my $CUSTOM_MEMORY_DEVICE_HDR  = Win32::GetCwd()."\\".$ARGV[2]."\\"."custom_MemoryDevice.h";
my $CUSTOM_EMI_H              = Win32::GetCwd()."\\".$ARGV[2]."\\"."custom_EMI.h";

#****************************************************************************
# Global Variables
#****************************************************************************
my $MEMORY_DEVICE_TYPE;
my $FLASH_ACCESS_TYPE;
my $RAM_ACCESS_TYPE;
my @EMI_SettingOnCS;


#****************************************************************************
# parse custom_MemoryDevice.h to extract MEMORY_DEVICE_TYPE & PART_NUMBER
#****************************************************************************
open CUSTOM_MEMORY_DEVICE_HDR, "<$CUSTOM_MEMORY_DEVICE_HDR" or die "cannot open $CUSTOM_MEMORY_DEVICE_HDR\n";

while (<CUSTOM_MEMORY_DEVICE_HDR>)
{
   # matching the following lines
   # "#define MEMORY_DEVICE_TYPE    NOR_RAM_MCP"
   # "#define FLASH_ACCESS_TYPE     ASYNC_ACCESS"
   # "#define RAM_ACCESS_TYPE       ASYNC_ACCESS"
   # "#define CS0_PART_NUMBER       RD38F3040L0ZBQ0"

   $MEMORY_DEVICE_TYPE              = $1 if (/^#define\s+MEMORY_DEVICE_TYPE\s+(\w+)/);
   $FLASH_ACCESS_TYPE               = $1 if (/^#define\s+FLASH_ACCESS_TYPE\s+(\w+)/);
   $RAM_ACCESS_TYPE                 = $1 if (/^#define\s+RAM_ACCESS_TYPE\s+(\w+)/);
}

close CUSTOM_MEMORY_DEVICE_HDR;

#****************************************************************************
# parse custom_EMI.h to extract EMI setting
#****************************************************************************
open CUSTOM_EMI_H, "<$CUSTOM_EMI_H" or die "cannot open $CUSTOM_EMI_H\n";

my $search_step=0;

while (<CUSTOM_EMI_H>)
{
   #/*
   # ****************************************************************************
   # Specify the related EMI Setting
   # ****************************************************************************
   #*/
   ##if ( defined(MT6205B) || defined(MT6208) )
   #
   #const kal_uint16   EMI_SettingOnCS[4] =
   #{
   #   0x4102,
   #   0x4102,
   #   0,
   #   0
   #};
   #
   ##elif ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )
   #
   #const kal_uint32   EMI_SettingOnCS[4] =
   #{
   #   0x44894324,
   #   0x448a4324,
   #   0,
   #   0
   #};
   if ($search_step==0)
   {
      $search_step++ if (m/Specify the related EMI Setting/);
      next;
   }
   elsif ($search_step==1)
   {
      if ((m/^#if/ or m/^#elif/) and (m/$PLATFORM/))
      {
         $search_step++;
      }
      elsif (m/^#endif/)
      {
         die "platform not found";
      }
   }
   elsif ($search_step==2)
   {
      if (m/EMI_SettingOnCS\[4\]/)
      {   
         $search_step++
      }
      elsif (m/^#if/ or m/^#elif/ or m/^#endif/)
      {
         die "EMI_SettingOnCS[4] not found";
      }
      next;
   }
   elsif ($search_step==3)
   {
      if (m/(0x[0-9A-Fa-f]{8}),/ or m/(0x[0-9A-Fa-f]{4}),/)
      {
         push @EMI_SettingOnCS, hex($1);
      }
      elsif (m/^#if/ or m/^#elif/ or m/^#endif/)
      {
         $search_step++;
      }
      next;
   }
   #/*
   # ****************************************************************************
   # Specify additional information
   # ****************************************************************************
   #*/
   ##define DEV_CONFIG_RAM_PMODE_ADDR_1        0x020001e0
   ##define DEV_CONFIG_RAM_PMODE_DATA_1        0x01
   ##if ( defined(MT6218B) || defined(MT6217) || defined(MT6219) )
   ##define EMI_RAM_PAGE_MODE        
   ##elif ( defined(MT6226) || defined(MT6227) || defined(MT6226M) )
   ##define EMI_RAM_PAGE_MODE        0x44Ca4305
   ##elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) )
   ##define EMI_RAM_PAGE_MODE        
   ##elif ( defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) )
   ##define EMI_RAM_PAGE_MODE        0x44Ca4305
   ##else
   ##define EMI_RAM_PAGE_MODE        0x4102
   ##endif
   #
   elsif ($search_step==4)
   {
      $search_step++ if (m/define/ and m/DEV_CONFIG_RAM_PMODE_DATA/);
      next;
   }
   elsif ($search_step==5)
   {
      if ((m/^#if/ or m/^#elif/) and (m/$PLATFORM/))
      {
         $search_step++;
      }
      elsif (m/^#endif/)
      {
         $search_step--;
         # die "NOT FOUND";
      }
   }
   elsif ($search_step==6)
   {
      if (/EMI_RAM_PAGE_MODE\s+(0x[0-9A-Fa-f]{8})/)
      {
         $EMI_SettingOnCS[1] = hex($1);
         $search_step++;
      }
   }
   else
   {
      last;
   }
}

close CUSTOM_EMI_H;

#****************************************************************************
# Control flow
#****************************************************************************
foreach my $e (@EMI_SettingOnCS)
{
   printf "0x%x\n",  $e;
   print "PAGE MODE\n" if (&EMI_is_pagemode($e));
   print "BURST MODE\n" if (&EMI_is_burstmode($e));
   print "16 bit\n" if (&EMI_is_16bit($e));
   print "RLT: ", &EMI_val_RLT($e) ,"\n";
   print "PRLT: ", &EMI_val_PRLT($e) ,"\n";
}
print "-" x 20 ,"\n";

if ($PLATFORM eq "MT6223" || $PLATFORM eq "MT6223P")
{
   if ($RAM_ACCESS_TYPE eq "SYNC_ACCESS" || $FLASH_ACCESS_TYPE eq "SYNC_ACCESS")
   {
      print "MT6223 MCP check : SYNC_ACCESS type bypass\n";
   }
   elsif ($RAM_ACCESS_TYPE eq "ASYNC_ACCESS" && $FLASH_ACCESS_TYPE eq "ASYNC_ACCESS")
   {
      if ($MODE eq "GSM")
      {
         print "MT6223 MCP check : GSM Project bypass\n";
      }
      elsif ($MODE eq "GPRS")
      {
         my $latency;
         foreach my $s (@EMI_SettingOnCS)
         {
            if (&EMI_val_PRLT($s) == 0)
            {
               $latency = (&EMI_val_RLT($s) + 1) * 8;
            }
            elsif (&EMI_is_16bit($s))
            {
               $latency = (&EMI_val_RLT($s) + 1 ) + ((&EMI_val_PRLT($s) + 1) * 7);
            }
            else
            {
               $latency = ((&EMI_val_RLT($s) + 1 ) * 2) + ((&EMI_val_PRLT($s) + 1) * 6);
            }
            die "MT6223 MCP check : Cannot support such low speed MCP!!!\n" if ($latency > 28);
         }
         print "MT6223 MCP check : GPRS project criteria pass\n";
      }
   }
   else
   {
      die "MT6223 MCP check : illegal memory access type!\n";
   }
}
else
{
      print "Platform " . $PLATFORM . " bypass\n";
}

exit 0;

#****************************************************************************
# Sub routines
#****************************************************************************
sub EMI_is_pagemode
{
   my ($setting) = @_;
   return 1 if ($setting & 0x00010000);
   return 0;
}

sub EMI_is_burstmode
{
   my ($setting) = @_;
   return 1 if ($setting & 0x00020000);
   return 0;
}

sub EMI_is_16bit
{
   my ($setting) = @_;
   return 1 if ($setting & 0x00000020);
   return 0;
}

sub EMI_val_RLT
{
   my ($setting) = @_;
   return ($setting & 0x0000001f);
}

sub EMI_val_PRLT
{
   my ($setting) = @_;
   return (($setting & 0x001c0000) >> 18);
}
