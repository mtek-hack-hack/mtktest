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

# *************************************************************************
# Include GNU Make Standard Library (GMSL)
# *************************************************************************
-include tools\GMSL\gmsl

# *************************************************************************
# Set defaul value to eliminate "option not define" warning
# *************************************************************************
BM_NEW         =  FALSE
RUN_RESGEN      =  FALSE

# *************************************************************************
# Include temporary build script
# *************************************************************************
# Get $(PROJECT) Definition
-include make\~buildinfo.tmp

# Custom specific build script
-include make\Custom.bld         # Custom release build
ifndef CUSTOM_RELEASE
CUSTOM_RELEASE  =  FALSE         # Default custom release
endif

ifeq ($(strip $(call Upper,$(CUSTOMER))),MTK)

 ifneq ($(strip $(call Upper,$(APLAT))),NONE)
include make\$(strip $(APLAT))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(APLAT))_$(strip $(PROJECT)).mak
 else
include make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
 endif

else
include make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
THE_MF = make\$(strip $(CUSTOMER))_$(strip $(PROJECT)).mak
endif

-include make\USER_SPECIFIC.mak
ifndef DEBUG_MODULES
  DEBUG_MODULES =
endif

ifndef NON_DEBUG_MODULES
  NON_DEBUG_MODULES =
endif

# *************************************************************************
# Environment and Tools
# *************************************************************************
COMPILE_MODE   =  INST16                           # 16bits instruction set

# default is ADS compiler
ifndef COMPILER
   VIA = -via
   COMPILER = ADS
else
   ifeq ($(strip $(COMPILER)),RVCT)
      VIA = --via
   endif
   ifeq ($(strip $(COMPILER)),ADS)
      VIA = -via
   endif
endif

#ifeq ($(strip $(COMPILER)),RVCT)
#  DIR_ARM        =  C:\Progra~1\ARM\RVCT
#  DIR_ARM := $(strip $(DIR_ARM))
#  DIR_TOOL       =  $(DIR_ARM)\Programs\2.1\328\win_32-pentium
#  DIR_ARMLIB     =  $(DIR_ARM)\Data\2.1\328\lib
#  DIR_ARMINC     =  $(DIR_ARM)\Data\2.1\328\include
#endif


ifeq ($(strip $(COMPILER)),RVCT)
  DIR_ARM        =  C:\Progra~1\ARM\RVCT
  DIR_ARM := $(strip $(DIR_ARM))
  DIR_TOOL       =  $(DIR_ARM)\Programs\2.2\349\win_32-pentium
  DIR_ARMLIB     =  $(DIR_ARM)\Data\2.2\349\lib
  DIR_ARMINC     =  $(DIR_ARM)\Data\2.2\349\include
endif


ifeq ($(strip $(COMPILER)),ADS)
  DIR_ARM        =  c:\progra~1\arm\adsv1_2
  DIR_ARM := $(strip $(DIR_ARM))
  DIR_TOOL       =  $(DIR_ARM)\bin
  DIR_ARMLIB     =  $(DIR_ARM)\lib
  DIR_ARMINC     =  $(DIR_ARM)\include
endif

DIR_TOOL := $(strip $(DIR_TOOL))
LINK           =  $(DIR_TOOL)\armlink.exe          # Linker
ASM            =  $(DIR_TOOL)\armasm.exe           # ARM assembler
LIB            =  $(DIR_TOOL)\armar.exe            # Library tool
BIN_CREATE     =  $(DIR_TOOL)\fromelf.exe          # Binary tool

ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     CC          =  $(DIR_TOOL)\armcc.exe --thumb    # Thumb Mode(16bits), use tcc
     CC32        =  $(DIR_TOOL)\armcc.exe --arm      # ARM Mode(32bits), use armcc
  else
     ifeq ($(strip $(COMPILE_MODE)),INST32)
        CC          =  $(DIR_TOOL)\armcc.exe --arm   # ARM Mode(32bits), use armcc
     else
        CC          =  $(DIR_TOOL)\armcc.exe --thumb # Default tcc
        CC32        =  $(DIR_TOOL)\armcc.exe --arm   # ARM Mode(32bits), use armcc
     endif
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     CC          =  $(DIR_TOOL)\tcc.exe              # Thumb Mode(16bits), use tcc
     CC32        =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
     CPPC        =  $(DIR_TOOL)\tcpp.exe              # Thumb Mode(16bits), use tcc
     CPPC32      =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
  else
     ifeq ($(strip $(COMPILE_MODE)),INST32)
        CC          =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
        CPPC        =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
     else
        CC          =  $(DIR_TOOL)\tcc.exe              # Default tcc
        CC32        =  $(DIR_TOOL)\armcc.exe            # ARM Mode(32bits), use armcc
        CPPC        =  $(DIR_TOOL)\tcpp.exe              # Thumb Mode(16bits), use tcc
        CPPC32      =  $(DIR_TOOL)\armcpp.exe            # ARM Mode(32bits), use armcc
     endif
  endif
endif

# *************************************************************************
# Build Options
# *************************************************************************

# -----------------------------
# CODEGEN option
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
   CGENFLAG = -D__RVCT__
endif

ifeq ($(strip $(COMPILER)),ADS)
   CGENFLAG =
endif

# -----------------------------
# Interwork option
# -----------------------------
APCSINT     =
ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     APCSINT  +=  --apcs /inter/adsabi/noswst
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     APCSINT  +=  -apcs /interwork
  endif
endif

# -----------------------------
# C options COPTION16 for thumb mode and COPTION32 for arm mode
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  CPLUSFLAGS = --cpp --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  CFLAGS     = --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  ifeq ($(strip $(PLATFORM)),MT6218B)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6217)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6219)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6226M)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6229)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6230)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6228)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6227)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6227D)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6226)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6226D)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6208)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6205B)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6205C)
     CFLAGS   :=   --cpu ARM7TDMI --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6223)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6223P)
     CFLAGS   :=   --cpu ARM7EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif

  ifeq ($(strip $(PLATFORM)),MT6238)
     CFLAGS   :=   --cpu ARM9EJ-S --littleend -O3 --split_sections -D__RVCT__ --apcs /adsabi
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  CFLAGS     =   -cpu ARM7EJ-S -littleend -O2 -zo -Ono_peephole -fa

  ifeq ($(strip $(PLATFORM)),MT6218B)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6217)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6219)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226M)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6229)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6230)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6228)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6227)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6227D)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6226)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6226D)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6208)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6205B)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6205C)
      CFLAGS     :=   -cpu ARM7TDMI -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif

  ifeq ($(strip $(PLATFORM)),MT6223)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
    
  ifeq ($(strip $(PLATFORM)),MT6223P)
     CFLAGS     :=   -cpu ARM7EJ-S -littleend -O2 -zo -fa
  endif
  
  ifeq ($(strip $(PLATFORM)),MT6238)
     CFLAGS     :=   -cpu ARM9EJ-S -littleend -O2 -zo -fa
  endif
endif

CFLAGS     +=  $(CUSTOM_CFLAGS)

ifeq ($(strip $(COMPILER)),RVCT)
   CPLUSFLAGS +=  $(CUSTOM_CFLAGS)

# move to Comp.mak 
# begin
#   CFLAGS += --bss_threshold=0
#   CPLUSFLAGS += --bss_threshold=0
# end

endif


# -----------------------------
# assembly option AOPTION16 for Thumb mode and AOPTION32 for Arm mode
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  BL_AFLAGS  = -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  AFLAGS     =   -g --littleend --cpu ARM7TDMI --apcs /interwork/adsabi
  ifeq ($(strip $(PLATFORM)),MT6218B)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6219)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6217)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6226M)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6226)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6226D)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6227)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6227D)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
     AFLAGS     :=   -g --littleend --cpu ARM7EJ-S --apcs /interwork/adsabi
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
     AFLAGS     :=   -g --littleend --cpu ARM9EJ-S --apcs /interwork/adsabi
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  BL_AFLAGS  = -g -littleend -cpu ARM7EJ-S
  AFLAGS     =   -g -littleend -cpu ARM7TDMI
  ifeq ($(strip $(PLATFORM)),MT6218B)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6219)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6217)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226M)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6226D)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6227)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6227D)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6225)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
     AFLAGS     :=   -g -littleend -cpu ARM7EJ-S
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
     AFLAGS     :=   -g -littleend -cpu ARM9EJ-S
  endif
endif

ifeq ($(strip $(COMPILE_MODE)),INST16)
   AFLAGS +=  -16
endif

# -----------------------------
# Library option LIBOPT for generating libraries
# -----------------------------
LIBOPT      =  -create

# -----------------------------
# Linker options
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)
  LNKOPT      =  --map --info sizes,totals --symbols --xref --remove --pad 0xFF
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
        LNKOPT      +=  --first LARGEPOOL_FIRST_ZI
    endif
  endif
endif

ifeq ($(strip $(COMPILER)),ADS)
  LNKOPT      =  -map -info sizes,totals -symbols -xref -remove
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
        LNKOPT      +=  -first LARGEPOOL_FIRST_ZI
    endif
  endif
endif

# -----------------------------
# Binary tool options
# -----------------------------
BIN_FORMAT  =  -bin

# -----------------------------
# custom release library path
# -----------------------------
ifdef OPTR_SPEC
  ifeq ($(strip $(OPTR_SPEC)),NONE)
    ifdef SWITCHABLE_FEATURE
      ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
      else
        CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))
      endif      
    else
      CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))
    endif
  else
    ifdef SWITCHABLE_FEATURE
      ifneq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))\$(strip $(SWITCHABLE_FEATURE))\$(strip $($(strip $(SWITCHABLE_FEATURE))))
      else
        CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))
      endif      
    else
      CUS_MTK_LIB = mtk_lib\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\$(strip $(PROJECT))\$(strip $(OPTR_SPEC))
    endif
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6226)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226,6226M,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226,6226M,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6226,6227,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226,6227,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6227)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6227,6226M,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227,6226M,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6227,6226,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227,6226,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6226M)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226M,6226,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226M,6226,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(subst 6226M,6227,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226M,6227,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6229)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6229,6230,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6229,6230,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6230)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6230,6229,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6230,6229,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6226D)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6226D,6227D,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6226D,6227D,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6227D)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6227D,6226D,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6227D,6226D,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6223)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6223,6223P,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6223,6223P,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif
ifeq ($(strip $(PLATFORM)),MT6223P)
  ORIGINAL_CUS_MTK_LIB := $(strip $(CUS_MTK_LIB))
  SWITCHABLE = $(shell dir $(subst 6223P,6223,$(strip $(CUS_MTK_LIB))) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(subst 6223P,6223,$(strip $(CUS_MTK_LIB)))
  endif
  SWITCHABLE = $(shell dir $(strip $(ORIGINAL_CUS_MTK_LIB)) /b 2>nul)
  ifneq ($(words $(strip $(SWITCHABLE))),0)
    CUS_MTK_LIB := $(strip $(ORIGINAL_CUS_MTK_LIB))
  endif
endif

# *************************************************************************
# Common include file and output directory path
# *************************************************************************
ifndef RTOS
   RTOS = NUCLEUS
endif

ifndef RTOS_DEBUG
   RTOS_DEBUG = TRUE
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
COMMINCDIRS    =  nucleus\inc \
                  kal\include kal\common\include \
                  kal\nucleus\include
endif

ifeq ($(strip $(RTOS)),THREADX)
COMMINCDIRS    =  threadx\inc \
                  kal\include kal\common\include \
                  kal\threadx\include
endif

COMMINCDIRS   +=  custom\system\$(strip $(BOARD_VER))

COMMINCDIRS   +=  interface\wap \
                  wapadp\include 



COMMINCDIRS   +=  drm\include

COMMINCDIRS   +=  ps\email\inc \
                  ps\email\pop3\inc \
                  ps\email\smtp\inc \
                  ps\email\imap\inc

COMMINCDIRS   +=  ps\ems\include ps\cc-ss\ss\include
COMMINCDIRS   +=  ps\l4\smu\include ps\l4\rac\include
COMMINCDIRS   +=  ps\mcddll\include ps\rr\asn\include
COMMINCDIRS   +=  ps\interfaces\local_inc
#for GEMINI
COMMINCDIRS   +=  SIM2\ps\l4\smu\include SIM2\ps\cc-ss\ss\include SIM2\ps\l4\rac\include

ifeq ($(strip $(call Upper,$(PROJECT))),UMTS)
  COMMINCDIRS   +=  ps\mcddll\include ps\rr2\asn\include
else
  COMMINCDIRS   +=  ps\mcddll\include ps\rr\asn\include
endif

COMMINCDIRS   += interface\bt
COMMINCDIRS   += ps\dt\include

ifdef GEMINI
  ifeq ($(strip $(GEMINI)),TRUE)
    ifeq ($(strip $(BT_SIM_PROFILE)),TRUE)
      $(error Please turn off BT_SIM_PROFILE when GEMINI = TRUE)
    endif 
  endif
endif

ifdef GEMINI
  ifeq ($(strip $(GEMINI)),TRUE)
    ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
      $(error Please turn off UNIFIED_MESSAGE_SUPPORT when GEMINI = TRUE)
    endif  
  endif
endif

ifdef DUAL_MODE_SUPPORT
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),GEMINI)
    ifndef GEMINI
      $(error Please set GEMINI to be TRUE when DUAL_MODE_SUPPORT is GEMINI)
    endif
    ifdef GEMINI
      ifneq ($(strip $(GEMINI)),TRUE)
        $(error Please set GEMINI to be TRUE when DUAL_MODE_SUPPORT is GEMINI)
      endif
    endif
  endif
endif

ifneq ($(findstring __GEMINI__,$(CUSTOM_OPTION)),)
  ifeq ($(strip $(PLATFORM)),MT6223)
    $(error $(PLATFORM) does not support the dual SIM feature. Please disable GEMINI)
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
    $(error $(PLATFORM) does not support the dual SIM feature. Please disable GEMINI)
  endif
endif

ifneq ($(findstring FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
  ifneq ($(findstring fmt,$(COMPLIST)),)
    $(error Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when fmt module is defined in COMPLIST)
  endif
endif

ifdef LENS_MODULE
  ifneq ($(strip $(LENS_MODULE)),NONE)
  	ifndef AF_SUPPORT
  		$(error Please set AF_SUPPORT = TRUE when LENS_MODULE was defined or set LENS_MODULE = NONE)
  	endif
  	ifeq ($(strip $(AF_SUPPORT)),FALSE)
  		$(error Please set AF_SUPPORT = TRUE when LENS_MODULE was defined or set LENS_MODULE = NONE)
  	endif
    COMMINCDIRS    +=	custom\drv\lens_module\$(strip $(LENS_MODULE))
  endif
endif

ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    COMMINCDIRS    +=	custom\drv\camera\$(strip $(BOARD_VER))
  endif
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
    COMMINCDIRS   += applib\inet\engine\include
    COMMINCDIRS   += applib\inet\app\include
  endif
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\xdm\include
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\voip\include
       COMMINCDIRS  +=	ps\saf\include
  endif
endif

COMMINCDIRS += custom\common\$(strip $(MMI_BASE))


COMMINCDIRS	+= interface\wifi


ifdef UNIFIED_MESSAGE_SUPPORT
   ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
      COMMINCDIRS	+= plutommi\MMI\UnifiedMessage\UnifiedMessageInc
   endif
endif

COMMINCDIRS	  += plutommi\MtkApp\DLAgent\DLAgentInc

ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    COMMINCDIRS    +=	custom\drv\camera\$(strip $(BOARD_VER))
    ifneq ($(strip $(YUV_SENSOR_SUPPORT)),TRUE)
        COMMINCDIRS    +=	custom\drv\image_sensor
#      COMMINCDIRS    +=	custom\drv\image_sensor\$(strip $(CMOS_SENSOR))
    else
         COMMINCDIRS    +=	custom\drv\YUV_sensor
#      COMMINCDIRS    +=	custom\drv\YUV_sensor\$(strip $(CMOS_SENSOR))
    endif
  endif
endif

COMMINCDIRS	  += interface\drv_def

ifdef RTSP_SUPPORT
  ifneq ($(strip $(RTSP_SUPPORT)),FALSE)
       COMMINCDIRS  +=	ps\rtsp\include
  endif
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
   COMMINCDIRS   +=  lcmmi\mmi\Inc
else
   COMMINCDIRS   +=  plutommi\mmi\Inc
   COMMINCDIRS   +=  plutommi\mmi\framework\commonfiles\commoninc
endif


ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi
    COMMINCDIRS  += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\plutommi
  endif
endif

# ifdef SYNCML_DM_SUPPORT
#  ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
#       COMMINCDIRS  +=  dm\task\inc 
#       COMMINCDIRS  +=  dm\wrapper\inc 
#  endif
# endif

ifdef SYNCML_DM_SUPPORT
  ifneq ($(strip $(SYNCML_DM_SUPPORT)),FALSE)
       COMMINCDIRS  +=	vendor\dm\bitfone\adaptation\task\inc
       COMMINCDIRS  +=	vendor\dm\bitfone\adaptation\wrapper\inc
  endif
endif


ifdef FOTA_ENABLE
  ifneq ($(strip $(FOTA_ENABLE)),NONE)
    COMMINCDIRS    +=	custom\drv\misc_drv\$(strip $(BOARD_VER))
    COMMINCDIRS    +=	custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen
  endif
endif

COMMINCDIRS	+= interface\GIS



ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
    COMMINCDIRS    +=  vendor_sec\security\certicom\adaptation
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sb51\cntnr\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sb51\cic\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sb51\coding\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sb51\husw\src\huapi\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sb51\husw\src\huswadap\include 
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sb51\statmach\include

    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sslplus5\dtlsapi\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sslplus5\utils\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sslplus5\private_shared\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sslplus5\hshk\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sslplus5\impexp\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sslplus5\rec\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sslplus5\api\include

    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sbpki2\x509\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sbpki2\ber\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sbpki2\tputil\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sbpki2\identity\include
    COMMINCDIRS    +=  vendor_sec\security\certicom\v1_official\sbpki2\validate\include
  else
    ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
      COMMINCDIRS  +=  vendor_sec\security\certicom\adaptation
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sb51\cntnr\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sb51\cic\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sb51\coding\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sb51\husw\src\huapi\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sb51\husw\src\huswadap\include 
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sb51\statmach\include

      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sslplus5\dtlsapi\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sslplus5\utils\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sslplus5\private_shared\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sslplus5\hshk\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sslplus5\impexp\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sslplus5\rec\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sslplus5\api\include

      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sbpki2\x509\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sbpki2\ber\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sbpki2\tputil\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sbpki2\identity\include
      COMMINCDIRS  +=  vendor_sec\security\certicom\v1_official\sbpki2\validate\include
    endif
  endif
endif

ifdef SSL_SUPPORT
  ifneq ($(strip $(SSL_SUPPORT)), NONE)
    COMMINCDIRS    +=  interface\security
    COMMINCDIRS    +=  applib\misc\include
  endif
endif


COMMINCDIRS	+= ps\interfaces\asn\rr\include 

# -----------------------------
# Custom Options
# -----------------------------
COMMINCDIRS    += $(DIR_ARMINC) $(CUSTOM_COMMINC)

# *************************************************************************
# Component Compile Options
# *************************************************************************
# -----------------------------
# Common Options
# -----------------------------
COM_DEFS    = $(CUSTOM_OPTION)


#**************************************
# Huyanwei Add It For Multi Language
COM_DEFS	+=BIDI_SUPPORT
#**************************************

###########################
###	Huyanwei Add Start 
###########################
LANGUAGEDIR:=
LANGUAGEPREFIX:=LMU
LANGUAGESUFFIX:=

### 项目宏
ifdef NOKE_PROJECT
  ifneq ($(strip $(NOKE_PROJECT)),NONE)
    COM_DEFS    += NOKE_$(NOKE_PROJECT)
    ifdef NOKE_PCB_VERSION
         ifneq ($(strip $(NOKE_PCB_VERSION)),NONE)
		COM_DEFS    += PCB_$(strip $(NOKE_PROJECT))_$(strip $(NOKE_PCB_VERSION))	    
         endif
    endif
  endif
endif

###设置软件的版本发布状态
ifdef NOKE_VER
     ifeq ($(findstring $(strip $(NOKE_VER)),D A B R),)
 	$(error Huyanwei Tell You : Your Var NOKE_VER Define Invalid !!!)
     else
      ifeq ($(strip $(NOKE_VER)),D)
	COM_DEFS  += NOKE_DEBUG
      endif
      ifeq ($(strip $(NOKE_VER)),A)
	COM_DEFS  += NOKE_ALPHA
      endif
      ifeq ($(strip $(NOKE_VER)),B)
	COM_DEFS  += NOKE_BETA
      endif
      ifeq ($(strip $(NOKE_VER)),R)
	COM_DEFS  += NOKE_RELEASE
      endif      
     endif
endif

####语言宏
ifeq ($(findstring EN,$(NOKE_LANGUAGE)),EN)
  COM_DEFS += LANG_EN_SUPPORT
  LANGUAGESUFFIX+=En
  LANGUAGEDIR+=英
endif  
ifeq ($(findstring SM,$(NOKE_LANGUAGE)),SM)
  COM_DEFS += LANG_SM_SUPPORT
  LANGUAGESUFFIX+=Cn
  LANGUAGEDIR+=中
endif  
ifeq ($(findstring AR,$(NOKE_LANGUAGE)),AR)
  COM_DEFS += LANG_AR_SUPPORT
  LANGUAGESUFFIX+=Ar
  LANGUAGEDIR+=阿
endif  
ifeq ($(findstring TU,$(NOKE_LANGUAGE)),TU)
  COM_DEFS += LANG_TU_SUPPORT
  LANGUAGESUFFIX+=Tu
  LANGUAGEDIR+=土
endif
ifeq ($(findstring PE,$(NOKE_LANGUAGE)),PE)
  COM_DEFS += LANG_PE_SUPPORT
  LANGUAGESUFFIX+=Pe
  LANGUAGEDIR+=波
endif
ifeq ($(findstring FR,$(NOKE_LANGUAGE)),FR)
  COM_DEFS += LANG_FR_SUPPORT
  LANGUAGESUFFIX+=Fr
  LANGUAGEDIR+=法
endif
ifeq ($(findstring RU,$(NOKE_LANGUAGE)),RU)
  COM_DEFS += LANG_RU_SUPPORT
  LANGUAGESUFFIX+=Ru
  LANGUAGEDIR+=俄
endif  
ifeq ($(findstring VI,$(NOKE_LANGUAGE)),VI)
  COM_DEFS += LANG_VI_SUPPORT
  LANGUAGESUFFIX+=Vi
  LANGUAGEDIR+=越
endif  
ifeq ($(findstring TH,$(NOKE_LANGUAGE)),TH)
  COM_DEFS += LANG_TH_SUPPORT
  ifdef NOKE_HANDWRITE_THAI
  ifeq ($(strip $(NOKE_HANDWRITE_THAI)),TRUE)
  COM_DEFS += LANG_TH_HANDWRITE_SUPPORT
  endif
  endif
  LANGUAGESUFFIX+=Th
  LANGUAGEDIR+=泰
endif
ifeq ($(findstring IN,$(NOKE_LANGUAGE)),IN)
  COM_DEFS += LANG_IN_SUPPORT
  LANGUAGESUFFIX+=In
  LANGUAGEDIR+=印
endif
ifeq ($(findstring SP,$(NOKE_LANGUAGE)),SP)
  COM_DEFS += LANG_SP_SUPPORT
  LANGUAGESUFFIX+=Sp
  LANGUAGEDIR+=西
endif
ifeq ($(findstring PO,$(NOKE_LANGUAGE)),PO)
  COM_DEFS += LANG_PO_SUPPORT
  LANGUAGESUFFIX+=Po
  LANGUAGEDIR+=葡
endif
ifeq ($(findstring MA,$(NOKE_LANGUAGE)),MA)
  COM_DEFS += LANG_MA_SUPPORT
  LANGUAGESUFFIX+=Ma
  LANGUAGEDIR+=马
endif
ifeq ($(findstring IT,$(NOKE_LANGUAGE)),IT)
  COM_DEFS += LANG_IT_SUPPORT
  LANGUAGESUFFIX+=It
  LANGUAGEDIR+=意
endif
ifeq ($(findstring GE,$(NOKE_LANGUAGE)),GE)
  COM_DEFS += LANG_GE_SUPPORT
  LANGUAGESUFFIX+=Ge
  LANGUAGEDIR+=德
endif
ifeq ($(findstring GR,$(NOKE_LANGUAGE)),GR)
  COM_DEFS += LANG_GR_SUPPORT
  LANGUAGESUFFIX+=Gr
  LANGUAGEDIR+=希
endif

###
# 判断是否是只有英文和泰文
###
ifeq ($(strip $(NOKE_LANGUAGE)),TH_EN)
  COM_DEFS += LANG_EN_TH_ONLY__
endif  
ifeq ($(strip $(NOKE_LANGUAGE)),EN_TH)
  COM_DEFS += LANG_EN_TH_ONLY__
endif 


###
# 判断是否是只有英文和中文
###
ifeq ($(strip $(NOKE_LANGUAGE)),SM_EN)
  COM_DEFS += LANG_EN_SM_ONLY__
  LANGUAGEPREFIX:=LCN
endif  
ifeq ($(strip $(NOKE_LANGUAGE)),EN_SM)
  COM_DEFS += LANG_EN_SM_ONLY__
  LANGUAGEPREFIX:=LCN
endif 

#############################
# 设置LCD 
############################
### LCD 宏

ifdef NOKE_LCD
  ifneq ($(strip $(NOKE_LCD)),NONE)
    COM_DEFS    += LCD_$(NOKE_LCD)
  endif
endif


###设置双摄相头宏
ifdef NOKE_DOUBLE_CAMERA
  ifeq ($(strip $(NOKE_DOUBLE_CAMERA)),TRUE)
    COM_DEFS    += DOUBLE_CAMERA_SUPPORT
  endif
endif


###设置重力传感器宏
ifdef NOKE_G_SENSOR
  ifeq ($(strip $(NOKE_G_SENSOR)),TRUE)
    COM_DEFS    += G_SENSOR_SUPPORT
    COMMINCDIRS    +=	custom\drv\g_sensor
  endif
endif


###设置方向传感器
ifdef NOKE_M_SENSOR
  ifeq ($(strip $(NOKE_M_SENSOR)),TRUE)
    #COM_DEFS    += M_SENSOR_SUPPORT
    COM_DEFS   += __DIRECTION_SENSOR_SUPPORT__
    COMMINCDIRS    +=	custom\drv\motion_sensor
  endif
endif

###设置特效
ifdef NOKE_EFFECT
  ifeq ($(strip $(NOKE_EFFECT)),TRUE)
    COM_DEFS    += EFFECT_SUPPORT
  endif
endif


###设置跑马灯
ifdef NOKE_HORSERACE
  ifeq ($(strip $(NOKE_HORSERACE)),TRUE)
    COM_DEFS    += HORSERACE_SUPPORT
    COMMINCDIRS    +=	custom\drv\horse_race
  endif
endif

###设置ok 键背光灯
ifdef NOKE_KEY_ENTER_BACKLIGHT_SUPPORT
  ifeq ($(strip $(NOKE_KEY_ENTER_BACKLIGHT_SUPPORT)),TRUE)
    COM_DEFS    += KEY_ENTER_BACKLIGHT_SUPPORT
  endif
endif


###设置camera 130W 作弊
ifdef NOKE_CAMERA_130W_CHEAT
  ifeq ($(strip $(NOKE_CAMERA_130W_CHEAT)),TRUE)
    COM_DEFS    += __CAMERA_130W_CHEAT__
  endif
endif


#**********设置摄相头闪光灯
ifdef NOKE_CAMERA_WITH_FLASH
  ifeq ($(strip $(NOKE_CAMERA_WITH_FLASH)),TRUE)
    COM_DEFS    += __MAIN_CAMERA_WITH_FLASH__
  endif
endif

#**********设置手电筒
ifdef NOKE_FLASHLIGHT_SUPPORT
  ifeq ($(strip $(NOKE_FLASHLIGHT_SUPPORT)),TRUE)
    COM_DEFS    += __FLASH_LIGHT_SUPPORT__
  endif
endif

#**********设置验钞灯
ifdef NOKE_COUNTERFEIT_MONEY_LAMP_SUPPORT
   ifeq ($(strip $(NOKE_COUNTERFEIT_MONEY_LAMP_SUPPORT)),TRUE)
      COM_DEFS += __COUNTERFEIT_MONEY_LAMP_SUPPORT__
   endif
endif

###设置音量侧键
ifdef NOKE_SIDE_VOL_KEY
  ifneq ($(strip $(NOKE_SIDE_VOL_KEY)),TRUE)
    COM_DEFS    += __MMI_NO_VOL_KEYS__
    COM_DEFS    += __VOL_WITH_28KEY__#    COM_DEFS    += __VOL_WITH_25KEY__
  endif
endif

###设置电视录制
ifneq ( $(strip $(ANALOG_TV_CHIP)),NONE)
ifdef NOKE_TV_RECORD
  ifeq ($(strip $(NOKE_TV_RECORD)),TRUE)
    COM_DEFS    += TV_RECORD_SUPPORT
  endif
endif
endif


###设置使用泰文中的英文
ifdef NOKE_HANDWRITE_THAI
  ifeq ($(strip $(NOKE_HANDWRITE_THAI)),TRUE)
  	ifdef NOKE_HANDWRITE_THAI_AS_ENGLISH
		 ifeq ($(strip $(NOKE_HANDWRITE_THAI_AS_ENGLISH)),TRUE)
		 	ifeq ($(findstring SM,$(NOKE_LANGUAGE)),)
				  COM_DEFS += LANG_TH_HANDWRITE_AS_ENGLISH_SUPPORT
			endif
		  endif
	endif  
  endif  	
endif  

#if defined(OV9655)
#define __MMI_CAMERA_130M_SENSOR__
#endif

#define __MMI_CAMERA_200M_SENSOR__

ifdef NOKE_CAMERA_TO_XXX_SUPPORT_ 
  ifneq ($(strip $(NOKE_CAMERA_TO_XXX_SUPPORT_)),130M)
    COM_DEFS    += __MMI_CAMERA_130M_SENSOR__
   else
     ifneq ($(strip $(NOKE_CAMERA_TO_XXX_SUPPORT_)),200M)
    COM_DEFS    += __MMI_CAMERA_200M_SENSOR__
   endif
  endif  
endif 

###设置双电池
ifdef NOKE_DOUBLE_BATTERY
	ifeq ($(strip $(NOKE_DOUBLE_BATTERY)),TRUE)
	 COM_DEFS    += DOUBLE_BATTERY_SUPPORT	
	endif
endif

###设置RF PA

ifdef NOKE_RFPA_MODULE
	ifneq ($(strip $(NOKE_RFPA_MODULE)),NONE)
	 COM_DEFS    += $(strip $(NOKE_RFPA_MODULE))
	endif
endif
###




###设置RF PA FREQ

ifdef NOKE_RFPA_FREQ
	ifneq ($(strip $(NOKE_RFPA_FREQ)),NONE)
	NOKE_RFPA_FREQ_TEMP :=$(subst |, ,$(strip $(NOKE_RFPA_FREQ)))
       COM_DEFS += $(foreach RF_MOD,$(NOKE_RFPA_FREQ_TEMP),RF_$(strip $(RF_MOD)))
	endif
endif
###




### 设置GPRS 配置
ifdef NOKE_GPRS_CONFIG
ifeq ($(strip $(NOKE_GPRS_CONFIG)),GPRS_TH)
	COM_DEFS += GPRS_TH_SUPPORT
endif
ifeq ($(strip $(NOKE_GPRS_CONFIG)),GPRS_SM)
	COM_DEFS += GPRS_SM_SUPPORT	
endif
ifeq ($(strip $(NOKE_GPRS_CONFIG)),GPRS_SM_TH)
	COM_DEFS += GPRS_SM_TH_SUPPORT
endif	
ifeq ($(strip $(NOKE_GPRS_CONFIG)),GPRS_DEFAULT)
	COM_DEFS += GPRS_DEFAULT_SUPPORT
endif	
endif	
###

###########################
###	Huyanwei Add End
###########################


ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    COM_DEFS    += $(OPTR_DEFS)
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  COM_DEFS += KAL_ON_NUCLEUS
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
    ifneq ($(strip $(NU_DEBUG)),FALSE)
       COM_DEFS += NU_DEBUG
    else
       COM_DEFS += NU_NO_ERROR_CHECKING
    endif
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
else
  ifeq ($(strip $(NU_DEBUG)),TRUE)
       COM_DEFS += NU_DEBUG
  endif
endif

ifeq ($(strip $(RTOS)),THREADX)
  COM_DEFS += KAL_ON_THREADX
  COM_DEFS += TX_ENABLE_IRQ_NESTING TX_DISABLE_NOTIFY_CALLBACKS \
              TX_DISABLE_PREEMPTION_THRESHOLD TX_DISABLE_STACK_FILLING TX_REACTIVE_INLINE
  ifneq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += TX_DISABLE_ERROR_CHECKING
  endif
endif

COM_DEFS    +=  IDLE_TASK _DEBUG MTK_KAL  __MTK_TARGET__ IDMA_DOWNLOAD

COM_DEFS    +=  SME_NOT_PRESENT SME_READER_NOT_PRESENT STDC_HEADERS TARGET_BUILD

COM_DEFS    += DEBUG_LEVEL=0

COM_DEFS    += __SATC3__

ifeq ($(strip $(COMPILER)),RVCT)
  COM_DEFS += __RVCT__
endif

ifeq ($(strip $(COMPILER)),ADS)
  COM_DEFS += __ADS__
endif

ifdef OPTR_SPEC
    ifeq ($(strip $(OPTR_SPEC)),NONE)
       COM_DEFS += __OPTR_NONE__
    endif
endif

ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
ifdef MMI_FEATURES_SET
    ifeq ($(strip $(MMI_FEATURES_SET)),BASIC)
       COM_DEFS += __MMI_FEATURES_SET_BASIC__
    endif

    ifeq ($(strip $(MMI_FEATURES_SET)),NORMAL)
       COM_DEFS += __MMI_FEATURES_SET_NORMAL__
    endif
endif
endif


ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
   ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
		  COM_DEFS +=  EMPTY_MMI
	 endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
   ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
		  COM_DEFS +=  EMPTY_MMI
	 endif
endif


ifdef DEMO_PROJECT
   ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      COM_DEFS   += DEMO_PROJECT
      COM_DEFS   += MTK_INTERNAL_MMI_FEATURES
      COM_DEFS   += __MTK_INTERNAL__
      
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
         COM_DEFS += WIFI_BLACKLIST 
      endif        
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
           COM_DEFS += WIFI_PORT_TIMER 
      endif          
   endif
endif

ifdef EMPTY_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
    ifdef MMI_FEATURES_SWITCH
      ifeq ($(strip $(MMI_FEATURES_SWITCH)),FALSE)
        COM_DEFS   += USE_COMMON_MMI_FEATURES_SWITCH
      endif
    else
      COM_DEFS   += USE_COMMON_MMI_FEATURES_SWITCH
    endif
  endif
endif

# remove COM_DEFS   += __SIM_PLUS__

# *************************************************************************
# Include Java compile settings.
# *************************************************************************
-include make\JAVA_DEF.mak

# *************************************************************************
# Components
# *************************************************************************
# -----------------------------
# Common Components
# -----------------------------



# *************************************************************************
# Component trace definition header files
# *************************************************************************
# -----------------------------
# Common trace
# -----------------------------

ifdef MMI_VERSION
   ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_conn_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_common_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_inet_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_media_app_trc.h 
      COMP_TRACE_DEFS += plutommi\mmi\inc\mmi_fw_trc.h
   endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
     COMP_TRACE_DEFS += ps\email\inc\email_trace.h
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
     COMP_TRACE_DEFS	+= ps\cmux\include\cmux_trc.h
  endif
endif

ifdef POC_SUPPORT
  ifneq ($(strip $(POC_SUPPORT)),NONE)
     COMP_TRACE_DEFS	+= ps\poc\include\poc_trc.h
  endif
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\sip\include\sip_trc.h
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\voip\include\voip_trc.h
     COMP_TRACE_DEFS	+= ps\saf\include\saf_trc.h
  endif
endif

ifdef DT_SUPPORT
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
  ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
    ifneq ($(strip $(DT_SUPPORT)),FALSE)
       COMP_TRACE_DEFS	+= ps\dt\include\dt_trc.h
    endif
  endif
endif
endif


COMP_TRACE_DEFS	+= l1audio\l1sp_trc.h
COMP_TRACE_DEFS   += dp_engine\dp_engine_trc.h

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\xdm\include\xdm_trc.h
  endif
endif

# Java should not be enabled on the GEMINI branch. 
ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    $(error Java should not be enabled on the GEMINI branch)
  endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
    COMP_TRACE_DEFS	+= j2me\interface\j2me_trace.h
  endif
endif

ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
     COMP_TRACE_DEFS	+= wifi\wndrv\include\os\wndrv_trc.h
     COMP_TRACE_DEFS	+= wifi\dummy_supc\include\supc_trc.h
     COMP_TRACE_DEFS	+= ps\dhcp\include\dhcp_trc.h
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     COMP_TRACE_DEFS	+= ps\iperf\include\iperf_trc.h
  endif
endif

ifdef TFTP_SUPPORT
  ifeq ($(strip $(TFTP_SUPPORT)),TRUE)
     COMP_TRACE_DEFS	+= ps\tftp\include\tftp_trc.h
  endif
endif


ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
	COMP_TRACE_DEFS += btadp\include\bluetooth_trc.h
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
	COMP_TRACE_DEFS += btadp\include\bluetooth_trc.h
endif

ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
   COMP_TRACE_DEFS += btadp\include\bluetooth_trc.h
endif


ifdef JATAAYU_FEATURE
  ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
     COMP_TRACE_DEFS	+= vendor\wap\jataayu4\adaptation\include\wap_trc.h
     COMP_TRACE_DEFS	+= vendor\wap\jataayu4\adaptation\include\wps_trc.h
  endif
endif


ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
   ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
     ifdef $(FLC_VER)
       ifeq ($(strip $(call Upper,$(FLC_VER)),FLC1))
         COMP_TRACE_DEFS   += ps\flow_ctrl\include\flc_trc.h
       else
         COMP_TRACE_DEFS   += ps\flc2\include\flc_trc.h
       endif
     else
       COMP_TRACE_DEFS   += ps\flow_ctrl\include\flc_trc.h
     endif
      COMP_TRACE_DEFS   += ps\ems\include\ems_trc.h
   endif
endif

ifdef RTSP_SUPPORT
  ifneq ($(strip $(RTSP_SUPPORT)),FALSE)
     COMP_TRACE_DEFS	+= ps\rtsp\include\rtsp_trc.h
  endif
endif

ifdef WAP_SUPPORT
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
     COMP_TRACE_DEFS	+= vendor\wap\obigo_q05a\adaptation\integration\include\wap_trc.h
  endif
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
     COMP_TRACE_DEFS	+= vendor\wap\obigo_Q03C\adaptation\integration\include\wap_trc.h          
  endif
endif

ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
     COMP_TRACE_DEFS	+= vendor_sec\security\certicom\adaptation\ssl\sslplus5_trc.h
  else
    ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
       COMP_TRACE_DEFS	+= vendor_sec\security\certicom\adaptation\ssl\sslplus5_trc.h
    endif
  endif
endif

ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
   L1_TMD_FILES   +=    l1\common\l1D_EDGE_trace.tmd
endif    

# ---------------------------------------------------------------
# The followings are global options from $(Customer)_$(Project).bld
# ---------------------------------------------------------------
# Platform Options
COM_DEFS_FOR_MT6208  = MT6208
COM_DEFS_FOR_MT6205  = MT6205 __HW_DIVIDER__
COM_DEFS_FOR_MT6205B = MT6205B __HW_DIVIDER__
COM_DEFS_FOR_FPGA    = FPGA
COM_DEFS_FOR_MT6218  = MT6218  __HW_DIVIDER__
COM_DEFS_FOR_MT6218B = MT6218B __HW_DIVIDER__ MT6218B_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6217  = MT6217 __HW_DIVIDER__ MT6217_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6219  = MT6219 __HW_DIVIDER__ MT6219_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6228  = MT6228 __HW_DIVIDER__ MT6228_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6229  = MT6229 __HW_DIVIDER__ MT6229_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6238  = MT6238 __HW_DIVIDER__ MT6238_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6230  = MT6230 __HW_DIVIDER__ MT6230_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6227  = MT6227 __HW_DIVIDER__ MT6227_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6227D = MT6227D __HW_DIVIDER__ MT6227D_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226  = MT6226 __HW_DIVIDER__ MT6226_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226D = MT6226D __HW_DIVIDER__ MT6226D_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6226M = MT6226M __HW_DIVIDER__ MT6226M_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6225  = MT6225 __HW_DIVIDER__ MT6225_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6223  = MT6223 __HW_DIVIDER__ MT6223_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6223P  = MT6223P __HW_DIVIDER__ MT6223P_$(strip $(CHIP_VER))

COM_DEFS_FOR_PLATFORM =  COM_DEFS_FOR_$(strip $(PLATFORM))
ifdef $(COM_DEFS_FOR_PLATFORM)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(PLATFORM)))
else
   $(error [COM_DEFS_FOR_$(strip $(PLATFORM))] was not defined)
endif

# RF Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_BRIGHT4                  = BRIGHT4_RF BRIGHT4_EVB
COM_DEFS_FOR_EUROPA                   = MT6129C_RF EUROPA_EVB
COM_DEFS_FOR_FOUNTAIN2                = MT6119C_RF FOUNTAIN2_EVB  FOUNTAIN2_RF
COM_DEFS_FOR_MT6129C                  = MT6129C_RF MT6129C_EVB
COM_DEFS_FOR_MT6129D                  = MT6129D_RF MT6129D_EVB
COM_DEFS_FOR_MT6139B                  = MT6139B_RF MT6139B_EVB
COM_DEFS_FOR_MT6139C                  = MT6139C_RF MT6139C_EVB
COM_DEFS_FOR_MT6139E                  = MT6139E_RF MT6139E_EVB
COM_DEFS_FOR_MT6140A                  = MT6140A_RF MT6140A_EVB
COM_DEFS_FOR_MT6140C                  = MT6140C_RF MT6140C_EVB
COM_DEFS_FOR_MT6140D                  = MT6140D_RF MT6140D_EVB
COM_DEFS_FOR_SKY74117                 = SKY74117_RF SKY74117_EVB
COM_DEFS_FOR_SKY74137                 = SKY74137_RF SKY74137_EVB
COM_DEFS_FOR_SKY74045                 = SKY74045_RF SKY74045_EVB
COM_DEFS_FOR_BRIGHT5P                 = BRIGHT5P_RF BRIGHT5P_EVB
COM_DEFS_FOR_AERO2                    = AERO2_RF   AERO2_EVB
COM_DEFS_FOR_SONY_CXA3359             = SONY_CXA3359_RF SONY_CXA3359_EVB
COM_DEFS_FOR_SMARTI3G                 = SMARTI3G_RF SMARTI3G_EVB

# For Customer projects.
COM_DEFS_FOR_MT6140_CUSTOM = MT6140D_RF MT6140_CUSTOM
COM_DEFS_FOR_MT6139_CUSTOM = MT6139E_RF MT6139_CUSTOM
COM_DEFS_FOR_MT6129_CUSTOM = MT6129D_RF MT6129_CUSTOM
COM_DEFS_FOR_SKY74137_CUSTOM = SKY74137_RF SKY74137_CUSTOM

COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(RF_MODULE))
ifdef $(COM_DEFS_FOR_RF_MODULE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(RF_MODULE)))
else
   $(error [COM_DEFS_FOR_$(strip $(RF_MODULE))] was not defined)
endif

ifdef UMTS_RF_MODULE
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE)))
  else
    $(error [COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))] was not defined)
  endif
endif

ifdef 3G_VIDEO_CALL
   ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
      ifneq ($(strip $(UCM_SUPPORT)),TRUE)
        $(error Please turn on UCM_SUPPORT or turn off 3G_VIDEO_CALL )
      endif
   endif
endif

# check AFC_VCXO_TYPE matches RF_MODULE
ifdef AFC_VCXO_TYPE
  ifdef RF_MODULE
    ifneq ($(findstring MT6129D,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6129D series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring MT6129,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6129 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring MT6119,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6119 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring BRIGHT4,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING BRIGHT4 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring MT6140A,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING MT6140A series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring SKY74117,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING SKY74117 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring SKY74045,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING SKY74045 series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring BRIGHT5P,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING  BRIGHT5P series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif
    ifneq ($(findstring FOUNTAIN,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING FOUNTAIN series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif

    ifneq ($(findstring AERO,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING AERO series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif
    ifneq ($(findstring MT6139,$(strip $(RF_MODULE))),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING MT6139 series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif
  endif
endif

# Board Options
ifneq ($(strip $(BOARD_VER)),)
   COM_DEFS    += $(BOARD_VER)
endif

# Board Subversion
ifneq ($(strip $(SUB_BOARD_VER)),)
   COM_DEFS    += $(SUB_BOARD_VER)
endif

# Feature Options
#ifeq ($(strip $(NU_DEBUG)),TRUE)            # Nucleus Plus Debug Support
#   COM_DEFS    += NU_DEBUG
#else
#   COM_DEFS    += NU_NO_ERROR_CHECKING
#endif


# LCD Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_KLMLCM            = PCF8833 COLOR_LCD S6B1713 DUAL_LCD KLMLCM
COM_DEFS_FOR_MTKLCM_COLOR      = S1D15G00 COLOR_LCD MTKLCM_COLOR
COM_DEFS_FOR_NEPTUNE_LCM       = S6B33B1X COLOR_LCD NEPTUNE_LCM STN_MAINLCD
COM_DEFS_FOR_POWERTIP_LCM      = S6B33B1X COLOR_LCD POWERTIP_LCM STN_MAINLCD
COM_DEFS_FOR_SONY_LCM          = SONY_LCM TFT_MAINLCD
COM_DEFS_FOR_TOPPOLY_LCM       = TOPPOLY_LCM TFT_MAINLCD
COM_DEFS_FOR_RENESAS_LCM       = HD66781 COLOR_LCD HD66791 COLOR_SUBLCD DUAL_LCD RENESAS_LCM TFT_MAINLCD
COM_DEFS_FOR_TAURUS_LCM        = S6B33B2A COLOR_LCD S6B0756 DUAL_LCD TAURUS_LCM
COM_DEFS_FOR_PHOENIX29_LCM     = PHOENIX29_LCM TFT_MAINLCD
COM_DEFS_FOR_FIREFLY_LCM       = WSX6396A COLOR_LCD SSD1773 COLOR_SUBLCD DUAL_LCD FIREFLY_LCM TFT_MAINLCD STN_SUBLCD
COM_DEFS_FOR_MTK6225_LCM       = MTK6225_LCM TFT_MAINLCD
COM_DEFS_FOR_TOP_6227_LCM      = TOP_6227_LCM TFT_MAINLCD



COM_DEFS_FOR_LCD_MODULE =  COM_DEFS_FOR_$(strip $(LCD_MODULE))
ifdef $(COM_DEFS_FOR_LCD_MODULE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(LCD_MODULE)))
else
   $(error No COM_DEFS for LCD_MODULE = $(strip $(LCD_MODULE))!)
endif

# BAND_SUPPORT Options
COM_DEFS_FOR_PGSM900   = __PGSM900__
COM_DEFS_FOR_EGSM900   = __EGSM900__
COM_DEFS_FOR_RGSM900   = __RGSM900__
COM_DEFS_FOR_DCS1800   = __DCS1800__
COM_DEFS_FOR_PCS1900   = __PCS1900__
COM_DEFS_FOR_GSM850    = __GSM850__
COM_DEFS_FOR_GSM450    = __GSM450__
COM_DEFS_FOR_DUAL900   = __EGSM900__ __DCS1800__
COM_DEFS_FOR_TRIPLE    = __EGSM900__ __DCS1800__ __PCS1900__
COM_DEFS_FOR_QUAD      = __EGSM900__ __DCS1800__ __PCS1900__  __GSM850__
COM_DEFS_FOR_DUAL850   = __GSM850__ __PCS1900__
COM_DEFS_FOR_TRIPLE850 = __GSM850__ __DCS1800__ __PCS1900__  TRIPLE850

COM_DEFS_FOR_BAND_SUPPORT =  COM_DEFS_FOR_$(strip $(BAND_SUPPORT))
ifdef $(COM_DEFS_FOR_BAND_SUPPORT)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(BAND_SUPPORT)))
else
   COM_DEFS		+= __EGSM900__ __DCS1800__   # the same as DUAL900
endif


# AFC_VCXO_TYPE Options
COM_DEFS_FOR_VCXO   		= AFC_VCXO
COM_DEFS_FOR_VCXO_SC   	= AFC_VCXO AFC_SC
COM_DEFS_FOR_VCXO_TC   	= AFC_VCXO AFC_TC
COM_DEFS_FOR_VCXO_SC_TC = AFC_VCXO AFC_SC AFC_TC

COM_DEFS_FOR_AFC_VCXO_TYPE =  COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE))
ifdef $(COM_DEFS_FOR_AFC_VCXO_TYPE)
   COM_DEFS		+=  $(COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE)))
endif

#
# Check the dependency of each options
#
ifdef WAP_SUPPORT
  ifneq ($(strip $(WAP_SUPPORT)),NONE)
    ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(error Please set TCPIP_SUPPORT or set WAP_SUPPORT as NONE!)
    endif
    ifneq ($(findstring WAP2,$(strip $(TELECA_FEATURE))),)
      ifeq ($(findstring TCP,$(strip $(TCPIP_SUPPORT))),)
        $(error Please turn on TCP in TCPIP_SUPPORT when WAP2 was enabled in TELECA_FEATURE)
      endif
    endif
  endif
endif

ifdef WAP_SUPPORT
  ifeq ($(strip $(WAP_SUPPORT)),NONE)
    ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
       $(error Please set JATAAYU_FEATURE = NONE when WAP_SUPPORT = NONE)
    endif    
    ifneq ($(strip $(TELECA_FEATURE)),NONE)
       $(error Please set TELECA_FEATURE = NONE when WAP_SUPPORT = NONE)
    endif    
  endif
endif

ifdef J2ME_SUPPORT
ifneq ($(strip $(J2ME_SUPPORT)),NONE)
  ifeq ($(strip $(WAP_SUPPORT)),NONE)
    $(error Please set WAP_SUPPORT or turn off J2ME_SUPPORT!)
  endif
  ifneq ($(strip $(MELODY_VER)),DSP_WT_SYN)
    $(error Please set MELODY_VER as DSP_WT_SYN or turn off J2ME_SUPPORT!)
  endif
endif
endif

ifneq ($(strip $(IMPS_SUPPORT)),FALSE)
  ifeq ($(strip $(WAP_SUPPORT)),NONE)
    $(error Please set WAP_SUPPORT or turn off IMPS_SUPPORT!)
  endif
  ifneq ($(strip $(XML_SUPPORT)),TRUE)
    $(error Please turn on XML_SUPPORT or turn off IMPS_SUPPORT!)
  endif
endif

MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6227 MT6227D MT6226 MT6226M MT6226D MT6238
ifneq ($(findstring $(strip $(PLATFORM)),$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
  ifeq ($(strip $(EXT_CAM_MODULE)),NONE)
    ifeq ($(strip $(ISP_SUPPORT)),FALSE)
      ifeq ($(strip $(MJPG_SUPPORT)),TRUE)
        $(error Please set EXT_CAM_MODULE or ISP_SUPPORT then MJPG_SUPPORT could be turned on!)
      endif
    endif
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
    ifeq ($(strip $(WAP_SUPPORT)),NONE)     
      $(error Please set WAP_SUPPORT or turn off DRM_SUPPORT!)
    endif
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
     ifeq ($(findstring FMT_NOT_PRESENT,$(COM_DEFS)),FMT_NOT_PRESENT)
        $(error Please turn off DRM_SUPPORT when FMT_NOT_PRESENT!)     
     endif              
  endif
endif




ifeq ($(strip $(FS_CHECKDRIVE_SUPPORT)),TRUE)
  ifneq ($(strip $(NAND_SUPPORT)),TRUE)
    $(error Please turn on NAND_SUPPORT or turn off FS_CHECKDRIVE_SUPPORT!)
  endif
endif

ifdef  NAND_SUPPORT
ifdef  SYSTEM_DRIVE_ON_NAND
   ifeq ($(strip $(NAND_SUPPORT)),FALSE)
     ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
        $(error Please turn on NAND_SUPPORT or turn off SYSTEM_DRIVE_ON_NAND !)
     endif
   endif
endif
endif

ifdef EMAIL_SUPPORT
ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(error Please set TCPIP_SUPPORT as TCP or UDP_TCP or set EMAIL_SUPPORT as NONE!)
  endif
  ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
    $(error Please set TCPIP_SUPPORT as TCP or UDP_TCP or set EMAIL_SUPPORT as NONE!)
  endif
endif
endif

ifdef POC_SUPPORT
ifneq ($(strip $(POC_SUPPORT)),NONE)
  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      $(error GSM project does not support POC!)
  endif
  ifeq ($(strip $(SIP_SUPPORT)),FALSE)
      $(error Please set POC_SUPPORT as NONE or turn on SIP_SUPPORT!)
  endif
  ifeq ($(strip $(SDP_SUPPORT)),FALSE)
      $(error Please set POC_SUPPORT as NONE or turn on SDP_SUPPORT!)
  endif
  ifeq ($(strip $(XDM_SUPPORT)),FALSE)
      $(error Please set POC_SUPPORT as NONE or turn on XDM_SUPPORT!)
  endif
endif
endif

ifdef VOIP_SUPPORT
ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
  ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
      $(error GSM project does not support VoIP!)
  endif
  ifeq ($(strip $(SIP_SUPPORT)),FALSE)
      $(error Please set VOIP_SUPPORT as FALSE or turn on SIP_SUPPORT!)
  endif
  ifeq ($(strip $(SDP_SUPPORT)),FALSE)
      $(error Please set VOIP_SUPPORT as FALSE or turn on SDP_SUPPORT!)
  endif
endif
endif

ifdef SIP_SUPPORT
ifneq ($(strip $(SIP_SUPPORT)),FALSE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(error Please set TCPIP_SUPPORT or turn off SIP_SUPPORT!)
  endif
endif
endif

ifdef TFTP_SUPPORT
ifneq ($(strip $(TFTP_SUPPORT)),FALSE)
  ifeq ($(strip $(TCPIP_SUPPORT)),NONE)
      $(error Please set TCPIP_SUPPORT or turn off TFTP_SUPPORT!)
  endif
endif
endif

# WIFI_BB_MODULE Options
COM_DEFS_FOR_MT5911       = WIFI_BB_MT5911
COM_DEFS_FOR_NONE         = WIFI_BB_NONE
COM_DEFS_FOR_None         = WIFI_BB_None


COM_DEFS_FOR_WIFI_BB_MODULE =  COM_DEFS_FOR_$(strip $(WIFI_BB_MODULE))
ifdef $(COM_DEFS_FOR_WIFI_BB_MODULE)
   COM_DEFS	+=  $(COM_DEFS_FOR_$(strip $(WIFI_BB_MODULE)))
else
   $(error WIFI_BB_MODULE = $(strip $(WIFI_BB_MODULE)) is not defined!)
endif


# WIFI_RF_MODULE Options
COM_DEFS_FOR_AL2236      = WIFI_RF_AL2236
COM_DEFS_FOR_MAX2827     = WIFI_RF_MAX2827
COM_DEFS_FOR_NONE        = WIFI_RF_NONE
COM_DEFS_FOR_None        = WIFI_RF_None



COM_DEFS_FOR_WIFI_RF_MODULE =  COM_DEFS_FOR_$(strip $(WIFI_RF_MODULE))
ifdef $(COM_DEFS_FOR_WIFI_RF_MODULE)
   COM_DEFS	+=  $(COM_DEFS_FOR_$(strip $(WIFI_RF_MODULE)))
else
   $(error WIFI_RF_MODULE = $(strip $(WIFI_RF_MODULE)) is not defined!)
endif


ifdef STREAM_SUPPORT
  ifneq ($(strip $(STREAM_SUPPORT)),FALSE)
    ifeq ($(strip $(SDP_SUPPORT)),FALSE)
       $(error Please set STREAM_SUPPORT as FALSE or turn on SDP_SUPPORT!)
    endif
    ifeq ($(strip $(RTSP_SUPPORT)),FALSE)
       $(error Please set STREAM_SUPPORT as FALSE or turn on RTSP_SUPPORT!)
    endif
    ifeq ($(strip $(AAC_DECODE)),FALSE)
       $(error Please set STREAM_SUPPORT as FALSE or turn on AAC_DECODE!)
    endif
  endif
endif

# JATAAYU_FEATURE  and  TELECA_FEATURE  must be exclusive.
ifdef JATAAYU_FEATURE
  ifdef TELECA_FEATURE
    ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
      ifneq ($(strip $(TELECA_FEATURE)),NONE)
        $(error Please turn off TELECA_FEATURE when JATAAYU_FEATURE is turned on)
      endif
    endif
  endif
endif

ifdef JATAAYU_FEATURE
  ifeq ($(strip $(JATAAYU_FEATURE)),WAP_SEC_MMS)
    $(error JATAAYU_FEATURE does not support WAP_SEC_MMS yet)
  endif
  ifeq ($(strip $(JATAAYU_FEATURE)),WAP2_SEC_MMS)
    $(error JATAAYU_FEATURE does not support WAP2_SEC_MMS yet)
  endif
endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
    COMPLIST        += 3g324m
    COMP_TRACE_DEFS += 3g324m\appl\inc\vt_trc.h
    CUSTOM_OPTION   += __CC_VIDEO_CALL__  __3G_VIDEO_CALL__
  endif
endif



ifdef FLC_VER
  ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
      ifeq ($(strip $(FLC_VER)), FLC2)
         COMPLIST += flc2
         CUS_REL_MTK_COMP += flc2
         COMP_TRACE_DEFS += ps\flc2\include\flc_trc.h         
         CUSTOM_COMMINC += ps\flc2\include  
         CUSTOM_OPTION += __FLC2__                
      else
         COMPLIST += flow_ctrl
         CUS_REL_MTK_COMP += flow_ctrl
         COMP_TRACE_DEFS += ps\flow_ctrl\include\flc_trc.h         
         CUSTOM_COMMINC += ps\flow_ctrl\include         
      endif
    endif
  endif
endif



ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
    ifndef WAP_SUPPORT
      $(error Please turn on WAP_SUPPORT when SYNCML_DM_SUPPORT is enabled)
    endif
    ifdef WAP_SUPPORT
      ifeq ($(strip $(WAP_SUPPORT)),NONE)
        $(error Please turn on WAP_SUPPORT when SYNCML_DM_SUPPORT is enabled)
      endif
    endif
  endif
endif


ifdef EMPTY_RESOURCE
  ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
    ifdef MMI_FEATURES_SWITCH
      ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
        $(error MMI_FEATURES_SWITCH could not be TRUE when EMPTY_RESOURCE is TRUE)
      endif
    endif
  endif
endif
# Disabled definitions
# COM_DEFS  += MTK_PCM MTK_SLEEP_ENABLE MT6205_SIM GSI_SUPPORT MTK_GSM_ENABLE

# -----------------------------
# Custom Options
# -----------------------------
ifeq ($(call Upper,$(strip $(PROJECT))),UMTS)
   COM_DEFS += __MTK_3G_MRAT_ARCH__
endif

ifeq ($(strip $(PLATFORM)),MT6225)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6223)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(PLATFORM)),MT6223P)
   COM_DEFS    += __REDUCE_TCM_SUPPORT__
endif

ifeq ($(strip $(L1_CATCHER)),TRUE)
   ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS    += L1_CATCHER
   endif
endif

ifeq ($(strip $(MTK_SLEEP_ENABLE)),TRUE)
   COM_DEFS    += MTK_SLEEP_ENABLE
endif

ifeq ($(strip $(MTK_DSP_DEBUG)),TRUE)
   COM_DEFS    += MTK_DSP_DEBUG
endif

ifeq ($(strip $(CSD_SUPPORT)),TRUE)
   COM_DEFS    += CSD_SUPPORT __CSD_NT__ __CSD_T__
   ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += __CSD_FAX__
   endif
endif

ifneq ($(findstring __PS_SERVICE__,$(CUSTOM_OPTION)),)
   COM_DEFS += KAL_ENH_MUTEX
endif

ifneq ($(findstring __CS_SERVICE__,$(CUSTOM_OPTION)),)
  ifeq ($(strip $(CSD_SUPPORT)),TRUE)
     COM_DEFS    += KAL_ENH_MUTEX
  endif
endif

ifdef WBXML_SUPPORT
  ifeq ($(strip $(WBXML_SUPPORT)),TRUE)
    COM_DEFS    += __WBXML_SUPPORT__
  endif
endif
   
ifdef PMIC_PRESENT
	ifeq ($(strip $(PMIC_PRESENT)),TRUE)
   	COM_DEFS    += PMIC_PRESENT
	endif
endif

ifdef PMIC
  ifneq ($(strip $(PMIC)),NONE)
     COM_DEFS    += PMIC_PRESENT
  endif
  ifeq ($(strip $(PLATFORM)),MT6205)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6205 only supports MT6305 PMIC, not support $(strip $(PMIC)))
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6205B)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6205B only supports MT6305 PMIC, not support $(strip $(PMIC)))
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6205C)
    ifneq ($(strip $(PMIC)),MT6305)
      ifneq ($(strip $(PMIC)),NONE)
        $(error MT6205C only supports MT6305 PMIC, not support $(strip $(PMIC)))
      endif
    endif
  endif
endif

ifeq ($(strip $(PMIC)),MT6223PMU)
   COM_DEFS    += MT6223PMU
endif

ifeq ($(strip $(PMIC)),MT6238PMU)
   COM_DEFS    += MT6238PMU
endif

ifeq ($(strip $(PMIC)),MT6305)
     COM_DEFS    += MT6305
endif

ifeq ($(strip $(PMIC)),MT6318)
   COM_DEFS    += MT6318
endif

ifeq ($(strip $(TELECA_FEATURE)),WAP)
   COM_DEFS    += WAP_SUPPORT
else
	ifeq ($(strip $(TELECA_FEATURE)),WAP2)
   	COM_DEFS    += WAP_SUPPORT  WAP2
	else
		ifeq ($(strip $(TELECA_FEATURE)),WAP_MMS)
			COM_DEFS    += WAP_SUPPORT  MMS_SUPPORT
		else
			ifeq ($(strip $(TELECA_FEATURE)),WAP2_MMS)
				COM_DEFS    += WAP_SUPPORT  WAP2 MMS_SUPPORT
			endif

			ifeq ($(strip $(TELECA_FEATURE)),NONE)
				COM_DEFS    += WAP_NOT_PRESENT
			endif
		endif
	endif
endif


ifeq ($(strip $(TELECA_FEATURE)),WAP_SEC)
   COM_DEFS    += WAP_SUPPORT  WAP_SEC_SUPPORT
else
	ifeq ($(strip $(TELECA_FEATURE)),WAP2_SEC)
   	COM_DEFS    += WAP_SUPPORT  WAP2 WAP_SEC_SUPPORT
	else
		ifeq ($(strip $(TELECA_FEATURE)),WAP_SEC_MMS)
			COM_DEFS    += WAP_SUPPORT  MMS_SUPPORT WAP_SEC_SUPPORT
		else
			ifeq ($(strip $(TELECA_FEATURE)),WAP2_SEC_MMS)
				COM_DEFS    += WAP_SUPPORT  WAP2 MMS_SUPPORT WAP_SEC_SUPPORT
			endif
		endif
	endif
endif

#ifneq ($(strip $(TELECA_FEATURE)),NONE)
#   COM_DEFS    += OBIGO_SUPPORT
#endif


ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
######          COMMINCDIRS   +=  vendor\drm\$(strip $(DRM_SUPPORT))\adp\include
    COMP_TRACE_DEFS += drm\include\drm_trace.h
	
    ifeq ($(strip $(DRM_SUPPORT)),BSCI)
      COM_DEFS	  += __DRM_SUPPORT__ __DRM_BSCI__
      COMPLIST	  += bsci drmadp
                  CUS_REL_SRC_COMP += drmadp
                  CUS_REL_BASE_COMP += vendor\drm\$(strip $(DRM_SUPPORT))\inc
                  CUS_REL_MTK_COMP += bsci
                  COMMINCDIRS   +=  vendor\drm\$(strip $(DRM_SUPPORT))\adp\include
    else
      COM_DEFS    += __DRM_SUPPORT__ __DRM_MTK__
      COMPLIST	  += drmadp
                  CUS_REL_SRC_COMP += drmadp
                  COMMINCDIRS   +=  vendor\drm\MTK\adp\include
    endif
    ifdef DRM_VERSION
      ifeq ($(strip $(DRM_VERSION)),NONE)
        $(error Please turn on DRM_VERSION or turn off DRM_SUPPORT)
      endif
      ifeq ($(strip $(DRM_VERSION)),ALL)
        COM_DEFS += __DRM_V01__ __DRM_V02__
      else
        ifeq ($(strip $(DRM_VERSION)),V01)
          COM_DEFS += __DRM_V01__
        endif
        ifeq ($(strip $(DRM_VERSION)),V02)
          COM_DEFS += __DRM_V02__
        endif
      endif
    else
      COM_DEFS += __DRM_V01__	
    endif
  endif
endif

ifdef DRM_SUPPORT
  ifneq ($(strip $(DRM_SUPPORT)),NONE)
    ifneq ($(strip $(TELECA_FEATURE)),NONE)
      ifeq ($(strip $(TELECA_FEATURE)),WAP_SEC)
        COM_DEFS += __DRM_SEC_TELECA__
      else
        ifeq ($(strip $(TELECA_FEATURE)),WAP2_SEC)
          COM_DEFS += __DRM_SEC_TELECA__
        else
          ifeq ($(strip $(TELECA_FEATURE)),WAP_SEC_MMS)
            COM_DEFS += __DRM_SEC_TELECA__
          else
            ifeq ($(strip $(TELECA_FEATURE)),WAP2_SEC_MMS)
              COM_DEFS += __DRM_SEC_TELECA__
            else
              COM_DEFS += __DRM_SEC_MTK__
            endif
          endif
        endif
       endif
    else
       COM_DEFS += __DRM_SEC_MTK__
    endif
  endif
endif



ifeq ($(strip $(FAST_UART)),TRUE)
	COM_DEFS    += __FAST_UART__
endif



# We can define __TWO_KEY_DETECTION_SWITCHABLE__  when __KBD_JOYSTICK_SUPPORT__ is not defined.
ifeq ($(findstring __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
   ifeq ($(findstring __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__TWO_KEY_DETECTION_SWITCHABLE__)
      $(error Please turn off __TWO_KEY_DETECTION_SWITCHABLE__ or turn off __KBD_JOYSTICK_SUPPORT__)
  endif
endif

ifdef NAND_SUPPORT
ifeq ($(strip $(NAND_SUPPORT)),TRUE)
      COM_DEFS    += NAND_SUPPORT
endif
endif

ifdef NAND_SUPPORT
ifdef SYSTEM_DRIVE_ON_NAND
  ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
    SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6217 MT6218B MT6219 MT6227 MT6226 MT6226M MT6225 MT6223 MT6227D MT6226D MT6223P MT6238
    ifeq ($(findstring $(strip $(PLATFORM)),$(SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM)),)
           $(error Chip version $(strip $(PLATFORM)) does not support SYSTEM_DRIVE_ON_NAND.)
    else
      ifeq ($(strip $(NAND_SUPPORT)),TRUE)
          COM_DEFS    += __FS_SYSDRV_ON_NAND__
      endif
    endif
  endif
endif
endif


ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
      $(error The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.)
    endif
    ifeq ($(strip $(PLATFORM)),MT6205)
      $(error The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.)
    endif
    ifeq ($(strip $(PLATFORM)),MT6208)
      $(error The $(strip $(PLATFORM)) chip does not have NAND_SUPPORT feature.)
    endif
  endif
endif


ifdef APP_STORAGE_IN_SYS_DRV
  ifeq ($(strip $(APP_STORAGE_IN_SYS_DRV)),FALSE)
     ifdef TELECA_FEATURE
        ifeq ($(strip $(TELECA_FEATURE)),WAP_MMS)
		     COM_DEFS    += MMS_IN_LARGE_STORAGE
        endif
        ifeq ($(strip $(TELECA_FEATURE)),WAP2_MMS)
           COM_DEFS    += MMS_IN_LARGE_STORAGE
        endif
        ifeq ($(strip $(TELECA_FEATURE)),WAP_SEC_MMS)
           COM_DEFS    += MMS_IN_LARGE_STORAGE
        endif
        ifeq ($(strip $(TELECA_FEATURE)),WAP2_SEC_MMS)
           COM_DEFS    += MMS_IN_LARGE_STORAGE
        endif
     endif
     ifdef JATAAYU_FEATURE
        ifeq ($(strip $(JATAAYU_FEATURE)),WAP_MMS)
		     COM_DEFS    += MMS_IN_LARGE_STORAGE
        endif
        ifeq ($(strip $(JATAAYU_FEATURE)),WAP2_MMS)
           COM_DEFS    += MMS_IN_LARGE_STORAGE
        endif
        ifeq ($(strip $(JATAAYU_FEATURE)),WAP_SEC_MMS)
           COM_DEFS    += MMS_IN_LARGE_STORAGE
        endif
        ifeq ($(strip $(JATAAYU_FEATURE)),WAP2_SEC_MMS)
           COM_DEFS    += MMS_IN_LARGE_STORAGE
        endif
     endif
     ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
       COM_DEFS   += IMPS_IN_LARGE_STORAGE
     endif
  else
      COM_DEFS    += APP_STORAGE_IN_SYS_DRV
  endif
endif

ifeq ($(strip $(SW_CHANGE_BLOCKING)),TRUE)
   COM_DEFS    += SW_CHANGE_BLOCKING
endif

ifdef MELODY_CHIP
  ifneq ($(strip $(MELODY_CHIP)),NONE)
     COM_DEFS	+= $(MELODY_CHIP)
  endif
endif

# hongzhe.liu add start

#ifdef  ANALOG_TV_CHIP
#  ifneq ($(strip $(ANALOG_TV_CHIP)),NONE)
#    COMMINCDIRS    +=	custom\drv\analog_tv\$(strip $(ANALOG_TV_CHIP))
#  endif
#endif

ifeq ($(strip $(ANALOG_TV_CHIP)), TLG1100)
   COM_DEFS += ANALOG_TV_SUPPORT
   COM_DEFS += ANALOG_TV_TLG1100
   COM_DEFS += __MMI_CENTER_KEY_TO_TV_SHORTCUT__
   COM_DEFS += __MMI_ANALOG_TV_FULLSCREEN_SINGNAL_QUALITY_HINT__
   #CUS_REL_SRC_COMP  +=  tlg_tv
   #COM_DEFS += __ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__
   #COM_DEFS += __UNI_MMI_VOL_KEY_TO_CHANNEL__
   #COM_DEFS += __MMI_ANALOG_TV_SHOW_PROMPT__
endif  

#hongzhe.liu add end

ifdef FM_RADIO_CHIP
  ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
     COM_DEFS	+= $(strip $(FM_RADIO_CHIP))
     ifdef FM_RADIO_RECORD
        ifeq ($(strip $(FM_RADIO_RECORD)),TRUE)
               COM_DEFS  += FM_RADIO_RECORD
        endif
     endif
  endif
endif

# keyboard case
ifdef NOKE_KEYBOARD_VERSION
   ifneq ($(strip $(NOKE_KEYBOARD_VERSION)),NONE)
      COM_DEFS  += __KEY_BOARD_$(strip $(NOKE_KEYBOARD_VERSION))__
   endif
endif

ifdef FM_RADIO_WITH_TV_CHIP
  ifeq ($(strip $(FM_RADIO_WITH_TV_CHIP)),TRUE)
    COM_DEFS	+= FM_RADIO_ENABLE
    COM_DEFS	+= FM_RADIO_WITH_TV
  endif
#2009.05.18 added by ghw for add FM_RADIO_RECORD   +

     ifdef FM_RADIO_RECORD
	ifeq ($(strip $(FM_RADIO_RECORD)),TRUE)
	       COM_DEFS  += FM_RADIO_RECORD
  endif
  endif
#2009.05.18 added by ghw for add FM_RADIO_RECORD   +

endif

#2009.04.25 added by hongzhe.liu for rda fm internal and pcb antenna +
ifneq ($(strip $(FM_RADIO_CHIP)),NONE)

    ifeq ($(strip $(FM_RADIO_ANTENNA_POS)),NONE)
        $(error Fm need set antenna position!)
    else
        ifeq ($(strip $(FM_RADIO_ANTENNA_POS)),CHIP)
             COM_DEFS	+= FM_RADIO_INTERNAL_ANTENNA
        else
            ifeq ($(strip $(FM_RADIO_ANTENNA_POS)),PCB)
                 COM_DEFS	+= FM_RADIO_PCB_ANTENNA
            else
                ifeq ($(strip $(FM_RADIO_ANTENNA_POS)),HEADSET)
                     COM_DEFS	+= FM_RADIO_HEADSET_ANTENNA
                else
                     $(error Fm antenna position error!)
                endif
            endif
        endif
    endif

endif
#2009.04.25 added by hongzhe.liu for rda fm internal and pcb antenna -

#2009.04.24 added by hongzhe.liu for dual sim support default  +
ifdef NOKE_DEFAULT_DUAL_SIM_SUPPORT
  ifeq ($(strip $(NOKE_DEFAULT_DUAL_SIM_SUPPORT)),TRUE)
    COM_DEFS	+= __DEFAULT_DUAL_SIM_SUPPORT__
  endif
endif
#2009.04.24 added by hongzhe.liu for dual sim support default  -

#2009.05.12 added by hongzhe.liu for power on off pic and ring +
ifneq ($(strip $(NOKE_POWER_ONOFF_ANIMATION)),NONE)
   COM_DEFS	+= __POWERONOFF_$(strip $(NOKE_POWER_ONOFF_ANIMATION))_ANIM__
endif

ifneq ($(strip $(NOKE_POWER_ONOFF_RING)),NONE)
   COM_DEFS	+= __POWERONOFF_$(strip $(NOKE_POWER_ONOFF_RING))_RING__
endif
# 2009.05.12 added by hongzhe.liu for power on off pic and ring -

# 2009.05.19 added by hongzhe.liu for camera +
ifeq ($(findstring $(strip $(CMOS_SENSOR)),$(CAMERA_SENSOR_SUPPORT_LIST)),)
   $(error Main camera sensor $(strip $(CMOS_SENSOR)) not support in this project.)
endif

ifeq ($(findstring $(strip $(SUB_CMOS_SENSOR)),$(CAMERA_SENSOR_SUPPORT_LIST)),)
   $(error Sub camera sensor $(strip $(SUB_CMOS_SENSOR)) not support in this project.)
endif
# 2009.05.19 added by hongzhe.liu for camera -


ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
      MSDC_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6227D MT6226D MT6223P MT6238 
      ifeq ($(findstring $(strip $(PLATFORM)) ,$(MSDC_SUPPORT_PLATFORM)),)
          $(error Chip version $(strip $(PLATFORM)) not support MSDC SD MMC.)
      else
           COM_DEFS	+= __FS_CARD_SUPPORT__
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_MMC)
           COM_DEFS	+= __MSDC_SD_MMC__
         endif
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MS)
           COM_DEFS	+= __MSDC_MS__
         endif
         ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MSPRO)
           COM_DEFS	+= __MSDC_MSPRO__
         endif
      endif
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  USB_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6228 MT6229 MT6230 MT6227 MT6226 MT6226M MT6225 MT6223 MT6227D MT6226D MT6223P MT6238
  ifeq ($(findstring $(strip $(PLATFORM)),$(USB_SUPPORT_PLATFORM)),)
     $(error Chip version $(strip $(PLATFORM)) not support USB.)
  else
	 ifeq ($(strip $(USB_SUPPORT)),TRUE)
	 	COM_DEFS    += __USB_ENABLE__  __NVRAM_IN_USB_MS__
	   ifeq ($(strip $(BOARD_VER)),MT6228_EVB)
	      COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
	   endif
	   ifeq ($(strip $(BOARD_VER)),MT6229_EVB)
	      COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
	   endif
	   ifeq ($(strip $(BOARD_VER)),MT6229_MGM_EVB)
	      COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
	   endif	   	   	   
	   ifeq ($(strip $(BOARD_VER)),MT6230_EVB)
	      COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
	   endif
    	ifeq ($(strip $(USB_IN_META_SUPPORT)),TRUE)
	      COM_DEFS    += __ENABLE_USB_IN_META__
	   endif
	 else
    	ifeq ($(strip $(USB_IN_META_SUPPORT)),TRUE)
        $(error Please turn on USB_SUPPORT or turn off USB_IN_META_SUPPORT.)
	   endif
	 endif
  endif
endif

ifeq ($(strip $(MELODY_VER)),SW_SYN_8K)
   COM_DEFS	+= $(strip $(WAVETABLE_VER))
endif

ifeq ($(strip $(MELODY_VER)),SW_SYN_16K)
   COM_DEFS	+= $(strip $(WAVETABLE_VER))
endif

ifeq ($(strip $(MELODY_VER)),DSP_WT_SYN)
  DSP_WT_SYN_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
  ifneq ($(findstring $(strip $(PLATFORM)),$(DSP_WT_SYN_NOT_SUPPORT_PLATFORM)),)
     $(error Chip version $(strip $(PLATFORM)) not support MELODY_VER=DSP_WT_SYN.)
  endif
   COM_DEFS	+= $(strip $(WAVETABLE_VER))
endif


ifdef DEDI_AMR_REC
  ifeq ($(strip $(DEDI_AMR_REC)),TRUE)
    COM_DEFS	+= DEDI_AMR_REC
  endif
endif

ifdef VR_ENGINE
  ifneq ($(strip $(VR_ENGINE)),NONE)
    COM_DEFS	+= $(VR_ENGINE)
  endif

  ifeq ($(strip $(VR_ENGINE)),VR_CYBERON)
     COMPOBJS    += l1audio\obj\BSR_Shell.lib
     CUS_REL_OBJ_LIST += l1audio\obj\BSR_Shell.lib
     COM_DEFS	+= VR_ENABLE
  endif


  ifeq ($(strip $(VR_ENGINE)),VRSI_CYBERON)
       COM_DEFS += VRSI_ENABLE
       ifeq ($(strip $(VRSI_LANGUAGE)),CYBERON_CNBI)
            COMPOBJS    += l1audio\obj\BSR_SI_Shell_CNBI.lib
            CUS_REL_OBJ_LIST += l1audio\obj\BSR_SI_Shell_CNBI.lib
            COM_DEFS += CYBERON_CNBI
      else
            COMPOBJS    += l1audio\obj\BSR_SI_Shell_TWBI.lib
            CUS_REL_OBJ_LIST    += l1audio\obj\BSR_SI_Shell_TWBI.lib
            COM_DEFS += CYBERON_TWBI
      endif
  endif
endif

ifdef FM_RADIO_CHIP
  ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
    COM_DEFS	+= $(FM_RADIO_CHIP)
    COM_DEFS	+= FM_RADIO_ENABLE
  endif
endif

ifdef PROJECT
  ifdef TCPIP_SUPPORT
    ifeq ($(call Upper,$(strip $(PROJECT))),UMTS)
       ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
             COM_DEFS   += __TCPIP__
       else
             COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),TCP)
             COM_DEFS   += TCP_SUPPORT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
             COM_DEFS   += UDP_SUPPORT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
             COM_DEFS   += UDP_SUPPORT TCP_SUPPORT
       endif
    endif
    ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
       ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
             COM_DEFS   += __TCPIP__
       else
             COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),TCP)
             COM_DEFS   += TCP_SUPPORT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
             COM_DEFS   += UDP_SUPPORT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
             COM_DEFS   += UDP_SUPPORT TCP_SUPPORT
       endif
    endif
    ifeq ($(strip $(PROJECT)),GSM)
       ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
             COM_DEFS   += __TCPIP__
       else
             COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT PPP_NOT_PRESENT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),TCP)
             COM_DEFS   += TCP_SUPPORT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
             COM_DEFS   += UDP_SUPPORT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
             COM_DEFS   += UDP_SUPPORT TCP_SUPPORT
       endif
    endif
    ifeq ($(strip $(PROJECT)),gsm)
       ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
             COM_DEFS   += __TCPIP__
       else
             COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT PPP_NOT_PRESENT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),TCP)
             COM_DEFS   += TCP_SUPPORT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),UDP)
             COM_DEFS   += UDP_SUPPORT
       endif
       ifeq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
             COM_DEFS   += UDP_SUPPORT TCP_SUPPORT
       endif
    endif
  endif
else
  $(error PROJECT is not defined!)
endif

ifdef FS_SORT_SUPPORT
  ifeq ($(strip $(FS_SORT_SUPPORT)),TRUE)
     COM_DEFS   += __FS_SORT_SUPPORT__
  endif
endif

ifdef FS_MOVE_SUPPORT
  ifeq ($(strip $(FS_MOVE_SUPPORT)),TRUE)
     COM_DEFS   += __FS_MOVE_SUPPORT__
  endif
endif

ifdef FS_CHECKDRIVE_SUPPORT
  ifeq ($(strip $(FS_CHECKDRIVE_SUPPORT)),TRUE)
     COM_DEFS   += __FS_CHECKDRIVE_SUPPORT__
  else
    ifeq ($(strip $(NAND_SUPPORT)), TRUE)
       $(warning WARNING recommend set FS_CHECKDRIVE_SUPPORT=TRUE when NAND_SUPPORT=TRUE)
    else
      ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)), NONE)
         $(warning WARNING recommend set FS_CHECKDRIVE_SUPPORT=TRUE when MSDC_CARD_SUPPORT_TYPE!=NONE)
      endif
    endif
  endif
endif

ifdef FS_QM_SUPPORT
  ifeq ($(strip $(FS_QM_SUPPORT)),TRUE)
     COM_DEFS   += __FS_QM_SUPPORT__
  endif
endif

ifdef FS_TRACE_SUPPORT
  ifdef TST_SUPPORT
    ifdef PRODUCTION_RELEASE
      ifeq ($(strip $(FS_TRACE_SUPPORT)),TRUE)
        ifeq ($(strip $(TST_SUPPORT)),TRUE)
          ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
             COM_DEFS   += __FS_TRACE_SUPPORT__
	  else
            $(error FS_TRACE_SUPPORT is TRUE, PRODUCTION_RELEASE sould not be TRUE!)
          endif
	else
          $(error FS_TRACE_SUPPORT is TRUE, TST_SUPPORT sould not be FALSE!)
        endif
      endif
    endif
  endif
endif

ifdef AMRWB_DECODE
  ifeq ($(strip $(AMRWB_DECODE)),TRUE)
      AMRWB_DECODE_NOT_SUPPORT_PLATFORM = MT6205B MT6218 MT6208 MT6218B MT6217 MT6223 MT6223P
      ifneq ($(findstring $(strip $(PLATFORM)),$(AMRWB_DECODE_NOT_SUPPORT_PLATFORM)),)
          $(error Platform $(strip $(PLATFORM)) not support AMRWB_DECODE!)
      endif
      COM_DEFS   += AMRWB_DECODE
  endif
endif

ifdef AMRWB_ENCODE
  ifeq ($(strip $(AMRWB_ENCODE)),TRUE)
      AMRWB_ENCODE_NOT_SUPPORT_PLATFORM = MT6205B MT6218 MT6208 MT6218B MT6217 MT6223 MT6223P
      ifneq ($(findstring $(strip $(PLATFORM)),$(AMRWB_ENCODE_NOT_SUPPORT_PLATFORM)),)
          $(error Platform $(strip $(PLATFORM)) not support AMRWB_ENCODE!)
      endif
      COM_DEFS   += AMRWB_ENCODE
  endif
endif

ifdef EES_ENABLE
  ifeq ($(strip $(EES_ENABLE)),TRUE)
     ifeq ($(strip $(PLATFORM)),MT6205B)
          $(error Platform $(strip $(PLATFORM)) not support EES_ENABLE!)
     endif
     COM_DEFS    += EES_ENABLE
  endif
endif

ifdef AEC_ENABLE
  ifeq ($(strip $(AEC_ENABLE)),TRUE)
     ifeq ($(strip $(PLATFORM)),MT6205B)
          $(error Platform $(strip $(PLATFORM)) not support AEC_ENABLE!)
     endif
     COM_DEFS    += AEC_ENABLE
  endif
endif

ifdef EMAIL_SUPPORT
  ifneq ($(strip $(EMAIL_SUPPORT)),NONE)
     COM_DEFS    += __EMAIL__  __EMAIL_AUTO_CHECK__ __POP3_LEAVE_COPY_ON_SERVER__
     COM_DEFS    += __EMAIL_DOWNLOAD_OPTION__  EMAIL_BCC  __EMAIL_USE_ASM_ADM__

     ifeq ($(strip $(EMAIL_SUPPORT)),SMTP_POP3)
        COM_DEFS    += __NO_IMAP__
     endif
  endif
endif



#BT_A2DP_PROFILE was not supported on MT6205/6217/6218/6219/6223 platforms
ifdef BT_A2DP_PROFILE
  ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
      BT_A2DP_PROFILE_NOT_SUPPORT_PLATFORM = MT6205 MT6217 MT6218 MT6219 MT6223 MT6223P
      ifneq ($(findstring $(strip $(PLATFORM)),$(BT_A2DP_PROFILE_NOT_SUPPORT_PLATFORM)),)
          $(error Platform $(strip $(PLATFORM)) does not support BT_A2DP_PROFILE!)
      endif
  endif
endif

#BT_AVRCP_PROFILE was not supported on MT6205/6217/6218/6219/6223 platforms
ifdef BT_AVRCP_PROFILE
  ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
      BT_AVRCP_PROFILE_NOT_SUPPORT_PLATFORM = MT6205 MT6217 MT6218 MT6219 MT6223 MT6223P 
      ifneq ($(findstring $(strip $(PLATFORM)),$(BT_AVRCP_PROFILE_NOT_SUPPORT_PLATFORM)),)
          $(error Platform $(strip $(PLATFORM)) does not support BT_AVRCP_PROFILE!)
      endif
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
          COM_DEFS    +=  __BT_SUPPORT__
    ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(error Please turn on DMA_UART_VIRTUAL_FIFO or turn off BLUETOOTH_SUPPORT!)
    endif
    ifneq ($(strip $(XML_SUPPORT)),TRUE)
      $(error Please turn on XML_SUPPORT or turn off BLUETOOTH_SUPPORT!)
    endif
    ifdef CMUX_SUPPORT
      ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
        $(error Please turn off CMUX_SUPPORT or turn off BLUETOOTH_SUPPORT!)
      endif
    endif
    ifneq ($(strip $(UART3_SUPPORT)),TRUE)
       $(error Please turn on UART3_SUPPORT or set BLUETOOTH_SUPPORT as NONE!)
    endif

    ifdef BT_CONNECT_TO_UART2
      ifeq ($(strip $(BT_CONNECT_TO_UART2)),TRUE)        # BT module is connected to UART2
        COM_DEFS += __BT_USE_UART2__ __ONLY_ONE_UART__
      endif
    endif

    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
          COM_DEFS    +=  __BTMTK__ __BTMODULE_RFMD3500__
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
          COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6601__
    endif    
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
       COM_DEFS    +=  __BTMTK__ __BTMODULE_MT6611__
    endif

#hongzhe.liu add for rda5868 begin
    ifeq ($(strip $(NOKE_BLUETOOTH_CHIP)),RDA5868)
       COM_DEFS    +=  __BT_RDA5868__
    endif
#hongzhe.liu add for rda5868 end
    
          ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
               COM_DEFS    +=  __BT_HFG_PROFILE__
               ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK)
                 COM_DEFS    +=  __HF_V15__
               endif
               ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
                 COM_DEFS    +=  __HF_V15__
               endif
               ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
                 COM_DEFS    +=  __HF_V15__
               endif
          endif
          ifeq ($(strip $(BT_AUDIO_VIA_SCO)),TRUE)
            BT_AUDIO_VIA_SCO_SUPPORT_PLATFORM = MT6225 MT6228 MT6229 MT6230 MT6235 MT6238 MT6268
            ifeq ($(findstring $(strip $(PLATFORM)),$(BT_AUDIO_VIA_SCO_SUPPORT_PLATFORM)),)
              $(error Chip version $(strip $(PLATFORM)) does not support BT_AUDIO_VIA_SCO)
            endif
          
            COM_DEFS    +=  __BT_AUDIO_VIA_SCO__
            COM_DEFS    +=  __BT_INBAND_RING__
          endif
          ifeq ($(strip $(BT_FM_RADIO_VIA_SCO)),TRUE)
              ifdef FM_RADIO_CHIP
                  ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
                      COM_DEFS    +=  __BT_FM_VIA_SCO__
                  endif
              endif
          endif
          ifeq ($(strip $(BT_FTS_PROFILE)),TRUE)
                    COM_DEFS    +=  __BT_FTS_PROFILE__
          endif
          ifeq ($(strip $(BT_FTC_PROFILE)),TRUE)
                    ifneq ($(strip $(XML_SUPPORT)),TRUE)
                       $(error Please turn on XML_SUPPORT or turn off BT_FTC_PROFILE!)
                    endif
                    COM_DEFS    +=  __BT_FTC_PROFILE__
          endif
          ifeq ($(strip $(BT_OPP_PROFILE)),TRUE)
                    COM_DEFS    +=  __BT_OPP_PROFILE__
          endif
          ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
                    COM_DEFS    +=  __BT_DUN_PROFILE__
          endif
          
          ifeq ($(findstring $(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601 BTMTK_MT6611),)
            ifneq ($(strip $(BT_SPP_SERVER)),NONE)
              $(error If BLUETOOTH_SUPPORT is not BTMTK_MTxxxx, set BT_SPP_SERVER is NONE)
            endif
          
            ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
              $(error If not BLUETOOTH_SUPPORT is not BTMTK_MTxxxx, set BT_SPP_CLIENT is NONE)
            endif
          endif
          
          ifneq ($(findstring $(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601 BTMTK_MT6611),)
            ifeq ($(strip $(BT_SPP_SERVER)),NONE)
              ifeq ($(strip $(BT_SPP_CLIENT)),NONE)
                ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
                  $(error If BLUETOOTH_SUPPORT is BTMTK_MTxxxx, BT_SPP_PROFILE should be FALSE when BT_SPP_SERVER and BT_SPP_CLIENT are both NONE)
                endif
              endif
            endif
          
            ifneq ($(strip $(BT_SPP_SERVER)),NONE)
              ifeq ($(strip $(BT_SPP_PROFILE)),FALSE)
                $(error When BLUETOOTH_SUPPORT is BTMTK_MTxxxx, BT_SPP_PROFILE should be TRUE if BT_SPP_SERVER or BT_SPP_CLIENT is not NONE)
              endif
            endif
          
            ifneq ($(strip $(BT_SPP_CLIENT)),NONE)
              ifeq ($(strip $(BT_SPP_PROFILE)),FALSE)
                $(error When BLUETOOTH_SUPPORT is BTMTK_MTxxxx, BT_SPP_PROFILE should be TRUE if BT_SPP_SERVER or BT_SPP_CLIENT is not NONE)
              endif
            endif
          endif
          
          
          ifneq ($(findstring $(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601 BTMTK_MT6611),)
            ifeq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_NO_SCO)
              COM_DEFS    +=  __BT_SPP_SRV_NO_SCO__
            endif
          
            ifeq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_WITH_SCO)
              COM_DEFS    +=  __BT_SPP_SRV_WITH_SCO__
            endif
          
            ifeq ($(strip $(BT_SPP_CLIENT)),BT_SPP_CLI_NO_SCO)
              COM_DEFS    +=  __BT_SPP_CLI_NO_SCO__
            endif
          
            ifeq ($(strip $(BT_SPP_CLIENT)),BT_SPP_CLI_WITH_SCO)
              COM_DEFS    +=  __BT_SPP_CLI_WITH_SCO__
            endif
          endif

          
          ifeq ($(strip $(BT_SPP_PROFILE)),TRUE)
                    COM_DEFS    +=  __BT_SPP_PROFILE__
          endif
          ifeq ($(strip $(BT_A2DP_PROFILE)),TRUE)
                    COM_DEFS    +=  __BT_A2DP_PROFILE__ __BT_A2DP_SUPPORT__
          endif
          ifeq ($(strip $(BT_AVRCP_PROFILE)),TRUE)
                COM_DEFS    +=  __BT_AVRCP_PROFILE__
          endif
          ifeq ($(strip $(BT_SIM_PROFILE)),TRUE)
                COM_DEFS    +=  __BT_SIM_PROFILE__
          endif
          ifeq ($(strip $(BT_HIDD_PROFILE)),TRUE)
                COM_DEFS    +=  __BT_HIDD_PROFILE__
          endif
          ifeq ($(strip $(BT_BPP_PROFILE)),TRUE)
             ifneq ($(strip $(XML_SUPPORT)),TRUE)
                $(error Please turn on XML_SUPPORT or turn off BT_BPP_PROFILE!)
             endif
             COM_DEFS    +=  __BT_BPP_PROFILE__
          endif
          ifeq ($(strip $(BT_BIP_PROFILE)),TRUE)
             COM_DEFS    +=  __BT_BIP_PROFILE__
          endif
  endif
endif

#ifdef BLUETOOTH_SUPPORT
#ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
#   ifdef MCU_DCM
#   ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
#      COM_DEFS += __BT_USE_UART2__
#   endif 
#   endif 
#endif 
#endif

ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(error Please set BT_SPP_PROFILE to TRUE when BT_HFG_PROFILE is TRUE)
  endif
  ifneq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_NO_SCO)
    $(error Please set BT_SPP_SERVER to BT_SPP_SRV_NO_SCO when BT_HFG_PROFILE is TRUE)
  endif  
endif

ifeq ($(strip $(BT_DUN_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(error Please set BT_SPP_PROFILE to TRUE when BT_DUN_PROFILE is TRUE)
  endif
  ifneq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_NO_SCO)
    $(error Please set BT_SPP_SERVER to BT_SPP_SRV_NO_SCO when BT_DUN_PROFILE is TRUE)
  endif  
endif

ifeq ($(strip $(BT_FAX_PROFILE)),TRUE)
  ifneq ($(strip $(BT_SPP_PROFILE)),TRUE)
    $(error Please set BT_SPP_PROFILE to TRUE when BT_FAX_PROFILE is TRUE)
  endif
  ifneq ($(strip $(BT_SPP_SERVER)),BT_SPP_SRV_NO_SCO)
    $(error Please set BT_SPP_SERVER to BT_SPP_SRV_NO_SCO when BT_FAX_PROFILE is TRUE)
  endif  
endif

ifneq ($(strip $(JPG_DECODE)),NONE)
   COM_DEFS    += JPG_DECODE
endif

# only MT6238 supports PNG_HW
ifdef PNG_DECODE
  ifneq ($(strip $(PLATFORM)),MT6238)
     ifeq ($(strip $(PNG_DECODE)),PNG_HW)
       $(error $(PLATFORM) does not support PNG_HW)
     endif
  endif
endif

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
  ifeq ($(strip $(PLATFORM)),MT6228)
     ifeq ($(strip $(PNG_DECODE)),PNG_HW)
       $(error MT6228 PNG_DECODE does not support PNG_HW)
     endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
     ifeq ($(strip $(PNG_DECODE)),PNG_HW)
       $(error MT6229 PNG_DECODE does not support PNG_HW)
     endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
     ifeq ($(strip $(PNG_DECODE)),PNG_HW)
       $(error MT6230 PNG_DECODE does not support PNG_HW)
     endif
  endif

  ifeq ($(strip $(PLATFORM)),MT6225)
     ifeq ($(strip $(JPG_DECODE)),JPG_HW)
       $(error MT6225 JPG_DECODE does not support JPG_HW)
     endif
     ifeq ($(strip $(JPG_ENCODE)),JPG_HW)
       $(error MT6225 JPG_ENCODE does not support JPG_HW)
     endif
     ifeq ($(strip $(PNG_DECODE)),PNG_HW)
       $(error MT6225 PNG_DECODE does not support PNG_HW)
     endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6223)
     ifeq ($(strip $(JPG_DECODE)),JPG_HW)
       $(error MT6223 JPG_DECODE does not support JPG_HW)
     endif
     ifeq ($(strip $(JPG_ENCODE)),JPG_HW)
       $(error MT6223 JPG_ENCODE does not support JPG_HW)
     endif
     ifeq ($(strip $(PNG_DECODE)),PNG_HW)
       $(error MT6223 PNG_DECODE does not support PNG_HW)
     endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6223P)
     ifeq ($(strip $(JPG_DECODE)),JPG_HW)
       $(error MT6223P JPG_DECODE does not support JPG_HW)
     endif
     ifeq ($(strip $(JPG_ENCODE)),JPG_HW)
       $(error MT6223P JPG_ENCODE does not support JPG_HW)
     endif
     ifeq ($(strip $(PNG_DECODE)),PNG_HW)
       $(error MT6223P PNG_DECODE does not support PNG_HW)
     endif
  endif
endif


ifdef GIF_DECODE
  ifeq ($(strip $(GIF_DECODE)),TRUE)
       COM_DEFS    += GIF_DECODE
  endif
ifdef PLATFORM
  ifeq ($(strip $(GIF_DECODE)),TRUE)
         ifeq ($(strip $(PLATFORM)),MT6219)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V1
         endif
         ifeq ($(strip $(PLATFORM)),MT6226)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V1
         endif
         ifeq ($(strip $(PLATFORM)),MT6226M)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V1
         endif
         ifeq ($(strip $(PLATFORM)),MT6226D)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V1
         endif
         ifeq ($(strip $(PLATFORM)),MT6223)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V1
         endif
         ifeq ($(strip $(PLATFORM)),MT6223P)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V1
         endif
         ifeq ($(strip $(PLATFORM)),MT6227)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V1
         endif
         ifeq ($(strip $(PLATFORM)),MT6227D)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V1
         endif
         ifeq ($(strip $(PLATFORM)),MT6228)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V2
         endif
         ifeq ($(strip $(PLATFORM)),MT6229)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V2
         endif
         ifeq ($(strip $(PLATFORM)),MT6238)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V2
         endif
         ifeq ($(strip $(PLATFORM)),MT6230)
            COM_DEFS    +=   USE_HW_GIF_DECODER_V2
         endif
  endif
endif
endif

COMPLIST    += sw_png_codec
CUS_REL_SRC_COMP  += sw_png_codec

ifdef PNG_DECODE
  ifneq ($(strip $(PNG_DECODE)),NONE)
    PNG_HW_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238
    ifeq ($(strip $(PNG_DECODE)),PNG_HW)
       ifeq ($(findstring $(strip $(PLATFORM)),$(PNG_HW_DECODE_SUPPORT_PLATFORM)),)
           $(error Chip version $(strip $(PLATFORM)) not support PNG_DECODE.)
       else
          COM_DEFS    += USE_HW_PNG_DECODER_V1
       endif
    else
       ifeq ($(strip $(PNG_DECODE)),PNG_SW)
          COM_DEFS    += USE_SW_PNG_DECODER
       endif
    endif
  endif
endif


# sw_jpeg_code only release OBJ!! 
##  CUS_REL_BASE_COMP   +=  image_codec\sw_jpeg_codec 
##  CUS_REL_BASE_COMP   +=  image_codec\common 

ifeq ($(strip $(JPG_DECODE)),JPG_SW)
  COMPLIST    += sw_jpeg_codec
  CUS_REL_MTK_COMP  += sw_jpeg_codec
  COM_DEFS    += __SW_JPEG_CODEC_SUPPORT__
  COMMINCDIRS   +=  image_codec\sw_jpeg_codec\include
else
  ifeq ($(strip $(JPG_ENCODE)),JPG_SW)
    COMPLIST    += sw_jpeg_codec
    CUS_REL_MTK_COMP  += sw_jpeg_codec
    COM_DEFS    += __SW_JPEG_CODEC_SUPPORT__
    COMMINCDIRS   +=  image_codec\sw_jpeg_codec\include
  endif
endif


ifeq ($(strip $(DAF_DECODE)),TRUE)
   DAF_DECODE_SUPPORT_PLATFORM = MT6217 MT6218B MT6219 MT6226M MT6228 MT6229 MT6230 MT6226 MT6227 MT6225 MT6223 MT6227D MT6226D MT6223P MT6238
   ifeq ($(findstring $(strip $(PLATFORM)),$(DAF_DECODE_SUPPORT_PLATFORM)),)
      $(error Chip version $(strip $(PLATFORM)) not support DAF_DECODE.)
   endif
   COM_DEFS    += DAF_DECODE
endif

ifdef MUSICAM_DECODE
  MUSICAM_DECODE_NOT_SUPPORT_PLATFORM = MT6217 MT6219 MT6223 MT6223P
  ifeq ($(strip $(MUSICAM_DECODE)),TRUE)
    ifneq ($(findstring $(strip $(PLATFORM)),$(MUSICAM_DECODE_NOT_SUPPORT_PLATFORM)),)
      $(error Chip version $(PLATFORM) not support MUSICAM_DECODE_NOT_SUPPORT_PLATFORM.)
    endif
    ifeq ($(strip $(PLATFORM)),MT6227)
      ifeq ($(strip $(CHIP_VER)),S00)
        $(error Chip version $(PLATFORM) $(CHIP_VER) not support MUSICAM_DECODE_NOT_SUPPORT_PLATFORM.)
      endif
    endif
    ifeq ($(strip $(PLATFORM)),MT6228)
      ifeq ($(strip $(CHIP_VER)),S00)
        $(error Chip version $(PLATFORM) $(CHIP_VER) not support MUSICAM_DECODE_NOT_SUPPORT_PLATFORM.)
      endif
    endif
    ifeq ($(strip $(PLATFORM)),MT6228)
      ifeq ($(strip $(CHIP_VER)),S01)
        $(error Chip version $(PLATFORM) $(CHIP_VER) not support MUSICAM_DECODE_NOT_SUPPORT_PLATFORM.)
      endif
    endif
    ifeq ($(strip $(PLATFORM)),MT6229)
      ifeq ($(strip $(CHIP_VER)),S00)
        $(error Chip version $(PLATFORM) $(CHIP_VER) not support MUSICAM_DECODE_NOT_SUPPORT_PLATFORM.)
      endif
    endif
    ifneq ($(strip $(DAF_DECODE)),TRUE)
      $(error Please turn on DAF_DECODE or turn off MUSICAM_DECODE.)
    endif
    COM_DEFS    += MUSICAM_DECODE    
  endif
endif

ifneq ($(strip $(JPG_ENCODE)),NONE)
   COM_DEFS    += JPG_ENCODE
endif

ifdef MP4_CODEC
  ifeq ($(strip $(MP4_CODEC)),TRUE)
   COM_DEFS    += MP4_CODEC
  endif
endif

ifeq ($(strip $(AAC_DECODE)),TRUE)
   AAC_DECODE_SUPPORT_PLATFORM = MT6219 MT6226M MT6228 MT6229 MT6230 MT6226 MT6227 MT6225 MT6223 MT6227D MT6226D MT6223P MT6238
   ifeq ($(findstring $(strip $(PLATFORM)),$(AAC_DECODE_SUPPORT_PLATFORM)),)
      $(error Chip version $(strip $(PLATFORM)) not support AAC_DECODE.)
   endif
   COM_DEFS    += AAC_DECODE
endif

ifeq ($(strip $(ISP_SUPPORT)),TRUE)
   COM_DEFS    += ISP_SUPPORT
endif


### Huyanwei Add It For Camera macro Defined Start
    COM_DEFS    += OV7660=10 OV7670=11 OV7680=12
    COM_DEFS    += MC501CC=21 MC501CB=22
    COM_DEFS    += GC0306=31 GC0307=32 GC0316=33 
    COM_DEFS    += BF3403=41 BF3503=42 BF3603=43
### Huyanwei Add It For Camera macro Defined End


ifdef CMOS_SENSOR
  ifneq ($(strip $(CMOS_SENSOR)),NONE)
    #COM_DEFS    += $(strip $(CMOS_SENSOR))
    COM_DEFS    += MAIN_CAMERA=$(strip $(CMOS_SENSOR))
  endif
endif

# Huyanwei Add Start
ifdef SUB_CMOS_SENSOR
  ifneq ($(strip $(SUB_CMOS_SENSOR)),NONE)
    #COM_DEFS    += $(strip $(SUB_CMOS_SENSOR))
    COM_DEFS    += SUB_CAMERA=$(strip $(SUB_CMOS_SENSOR))
  endif
endif
#Huyanwei Add End

ifdef SENSOR_ROTATE
  ifneq ($(strip $(SENSOR_ROTATE)),NONE)
          COM_DEFS    += $(strip $(SENSOR_ROTATE))
  endif
endif

ifdef SENSOR_LOCATION
  ifneq ($(strip $(SENSOR_LOCATION)),NONE)
          COM_DEFS    += $(strip $(SENSOR_LOCATION))
  endif
endif

ifdef MOTION_SENSOR_SUPPORT
  ifneq ($(strip $(MOTION_SENSOR_SUPPORT)),NONE)
    COM_DEFS    += $(strip $(MOTION_SENSOR_SUPPORT))
    COM_DEFS    += MOTION_SENSOR_SUPPORT
    COMMINCDIRS += custom\drv\motion_sensor\$(strip $(MOTION_SENSOR_SUPPORT))
  endif
endif

ifdef AUDIO_EQ_ENABLE
  ifeq ($(strip $(AUDIO_EQ_ENABLE)),TRUE)
    COM_DEFS += AUDIO_EQ_ENABLE
    COM_DEFS += AUDIO_EQUALIZER_ENABLE
  endif
endif

ifdef AUDIO_COMPENSATION_ENABLE
  AUDIO_EQ_ENABLE_AUDIO_COMPENSATION_ENABLE_EXCLUSIVE_PLATFORM = MT6219 MT6223 MT6225 MT6226 MT6226D MT6226M MT6227D MT6227
  ifeq ($(strip $(AUDIO_COMPENSATION_ENABLE)),TRUE)
    COM_DEFS += AUDIO_COMPENSATION_ENABLE
    
    ifeq ($(strip $(AUDIO_EQ_ENABLE)),TRUE)
      ifneq ($(findstring $(strip $(PLATFORM)),$(AUDIO_EQ_ENABLE_AUDIO_COMPENSATION_ENABLE_EXCLUSIVE_PLATFORM)),)
        $(error AUDIO_EQ_ENABLE and AUDIO_COMPENSATION_ENABLE must be exclusive in $(PLATFORM)!)
      endif
    endif
  else
    ifneq ($(findstring $(strip $(PLATFORM)),MT6228 MT6229 MT6235 MT6238),)
      $(error AUDIO_COMPENSATION_ENABLE must turn on in $(PLATFORM)!)
    endif
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
          COM_DEFS     += __CMUX_SUPPORT__
  endif
endif

ifdef DIGIT_TONE_SUPPORT
  ifeq ($(strip $(DIGIT_TONE_SUPPORT)),TRUE)
        COM_DEFS    +=  DIGIT_TONE_SUPPORT
  endif
endif

ifdef TTS
  ifneq ($(strip $(TTS)),NONE)
        COM_DEFS    +=  $(strip $(TTS))
  endif
  
  ifeq ($(strip $(TTS)),CYBERON_DIC_TTS)
     COMPOBJS    += l1audio\obj\TDic_Shell.lib
     CUS_REL_OBJ_LIST += l1audio\obj\TDic_Shell.lib
     COM_DEFS	+= __GENERAL_TTS__
  endif  
endif

ifdef CUST_KEYPAD_TONE_SUPPORT
  ifeq ($(strip $(CUST_KEYPAD_TONE_SUPPORT)),TRUE)
        COM_DEFS    +=  CUST_KEYPAD_TONE_SUPPORT
  endif
endif


ifdef EXT_CAM_MODULE
 ifneq ($(strip $(EXT_CAM_MODULE)),NONE)
    ifeq ($(strip $(PLATFORM)),MT6205B)
         $(error Platform mt6205b not support EXT_CAM_MODULE!)
    endif
    COM_DEFS    += CAMERA_MODULE $(strip $(EXT_CAM_MODULE))
    ifeq ($(strip $(EXT_CAM_MODULE)),VC0558)
       COM_DEFS    += CAMERA_MODULE_WITH_LCD
    endif

    ifeq ($(strip $(EXT_CAM_MODULE)),AIT700)
       COM_DEFS    += CAMERA_MODULE_WITH_LCD
    endif

    ifeq ($(strip $(EXT_CAM_MODULE)),AIT800)
       COM_DEFS    += CAMERA_MODULE_WITH_LCD
    endif
 endif
endif

ifdef CAMERA_MODULE_WITH_LCD
  ifeq ($(strip $(CAMERA_MODULE_WITH_LCD)),TRUE)
     COM_DEFS    += CAMERA_MODULE_WITH_LCD
  endif
endif

HORIZONTAL_CAMERA_SUPPORT_SIZE = 176X220 240X320
ifdef HORIZONTAL_CAMERA
  ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
    ifeq ($(findstring $(call Upper,$(strip $(MAIN_LCD_SIZE))),$(HORIZONTAL_CAMERA_SUPPORT_SIZE)),)
       $(error $(MAIN_LCD_SIZE) does not support HORIZONTAL_CAMERA. Please disable HORIZONTAL_CAMERA)
    else
      COM_DEFS    += HORIZONTAL_CAMERA
    endif
  endif
endif

MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM = MT6217 MT6218B MT6225 MT6223 MT6223P MT6238
ifneq ($(findstring $(strip $(PLATFORM)),$(MJPG_SUPPORT_EXT_CAM_MODULE_DEP_PLATFORM)),)
ifdef MJPG_SUPPORT
   ifeq ($(strip $(MJPG_SUPPORT)),TRUE)
     COM_DEFS    += MJPG_SUPPORT
   endif
endif
endif



ifdef MED_PROFILE
     COM_DEFS    += $(strip $(MED_PROFILE))
endif


ifdef XML_SUPPORT
  ifeq ($(strip $(XML_SUPPORT)),TRUE)
     COM_DEFS   += __XML_SUPPORT__
  endif
endif

ifdef AMR_LINK_SUPPORT
  ifeq ($(strip $(AMR_LINK_SUPPORT)),TRUE)
     COM_DEFS   += __AMR_SUPPORT__
  endif
endif

ifdef IMPS_SUPPORT
  ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
     COM_DEFS    += __IMPS__
  endif
endif

ifdef TOUCH_PANEL_SUPPORT
  ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
    ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
      $(error TOUCH_PANEL does not support NEPTUNE_MMI)
    endif
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),MT6301)
     COM_DEFS    += TOUCH_PANEL_SUPPORT
  endif
  ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),MT6301B)
     COM_DEFS    += TOUCH_PANEL_SUPPORT
     COM_DEFS    += TOUCH_PANEL_PRESSURE
  endif
endif


ifdef TOUCH_PANEL_SUPPORT
   ifeq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)  
          $(error Please turn on TOUCH_PANEL_SUPPORT or turn off TOUCH_PANEL_SHORTCUT_SUPPORT )
      endif
   else 
      ifeq ($(strip $(TOUCH_PANEL_SHORTCUT_SUPPORT)),TRUE)
         COM_DEFS    += TOUCH_PANEL_SHORTCUT_SUPPORT
      endif
   endif     
endif

ifdef TOUCH_PAD_SUPPORT
   ifeq ($(strip $(TOUCH_PAD_SUPPORT)),TRUE)
       COM_DEFS  += TOUCH_PAD_SUPPORT
   endif
endif

ifndef GPRS_MAX_PDP_SUPPORT
     GPRS_MAX_PDP_SUPPORT = 2
endif

ifdef GPRS_MAX_PDP_SUPPORT
     COM_DEFS    += GPRS_MAX_PDP_SUPPORT=$(strip $(GPRS_MAX_PDP_SUPPORT))
endif

ifdef UART3_SUPPORT
  ifeq ($(strip $(UART3_SUPPORT)),TRUE)
    UART3_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
    ifneq ($(findstring $(strip $(PLATFORM)),$(UART3_NOT_SUPPORT_PLATFORM)),)
       $(error Chip version $(strip $(PLATFORM)) not support UART3_SUPPORT.)
    endif
    COM_DEFS    +=	__UART3_SUPPORT__
    UART_PORT_FREE_COUNT = 1
  else
    UART_PORT_FREE_COUNT = 0
  endif
else
    UART_PORT_FREE_COUNT = 0
endif

ifdef BLUETOOTH_SUPPORT
  ifeq ($(strip $(BLUETOOTH_SUPPORT)), NONE)
    ifdef TOUCH_PAD_SUPPORT
      ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
        UART_PORT_USED_COUNT = 1
      else
        UART_PORT_USED_COUNT = 0
      endif
    else
      UART_PORT_USED_COUNT = 0
    endif
  else
    ifdef TOUCH_PAD_SUPPORT
      ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
        UART_PORT_USED_COUNT = 2
      else
        UART_PORT_USED_COUNT = 1
      endif
    else
      UART_PORT_USED_COUNT = 1
    endif
  endif
else
  ifdef TOUCH_PAD_SUPPORT
    ifeq ($(strip $(TOUCH_PAD_SUPPORT)), TRUE)
      UART_PORT_USED_COUNT = 1
    else
      UART_PORT_USED_COUNT = 0
    endif
  else
    UART_PORT_USED_COUNT = 0
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),1)
   ifeq ($(strip $(UART_PORT_USED_COUNT)),2)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),0)
  ifneq ($(strip $(UART_PORT_USED_COUNT)),0)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif



ifdef DMA_UART_VIRTUAL_FIFO
  ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
    VFIFO_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
    ifneq ($(findstring $(strip $(PLATFORM)),$(VFIFO_NOT_SUPPORT_PLATFORM)),)
       $(error Chip version $(strip $(PLATFORM)) not support DMA_UART_VIRTUAL_FIFO.)
    endif
     COM_DEFS    +=	__DMA_UART_VIRTUAL_FIFO__
  endif
endif

ifdef POC_SUPPORT
  ifneq ($(strip $(POC_SUPPORT)),NONE)
     COM_DEFS    += __POC__  __POC_NON_RLS__
  endif
endif

ifdef SIP_SUPPORT
  ifneq ($(strip $(SIP_SUPPORT)),FALSE)
     COM_DEFS    +=  __SIP__
  endif
endif

ifdef SDP_SUPPORT
  ifneq ($(strip $(SDP_SUPPORT)),FALSE)
     COM_DEFS    +=  __SDP__
     COMP_TRACE_DEFS	  += ps\sdp\include\sdp_trc.h
  endif
endif

ifdef WIFI_SUPPORT
  ifeq ($(strip $(WIFI_SUPPORT)),WIFI_LIB)
#     COMPOBJS         += wifi\sslplus.lib
#     CUS_REL_OBJ_LIST += wifi\sslplus.lib
#     COMPOBJS         += wifi\sb.lib
#     CUS_REL_OBJ_LIST += wifi\sb.lib
  endif
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
     COM_DEFS    +=  __WIFI_SUPPORT__
     COM_DEFS    +=  __WIFI_CHIP_VERIFY__
  endif
endif

ifdef IPERF_SUPPORT
  ifneq ($(strip $(IPERF_SUPPORT)),NONE)
     ifneq ($(strip $(TCPIP_SUPPORT)),UDP_TCP)
        $(error Please set TCPIP_SUPPORT as UDP_TCP or set IPERF_SUPPORT as NONE!)
     endif
  endif

  ifeq ($(strip $(IPERF_SUPPORT)),QUAD)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
     COM_DEFS    += __IPERF3__
     COM_DEFS    += __IPERF4__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),TRIPLE)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
     COM_DEFS    += __IPERF3__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),DUAL)
     COM_DEFS    += __IPERF__
     COM_DEFS    += __IPERF2__
  endif
  ifeq ($(strip $(IPERF_SUPPORT)),SINGLE)
     COM_DEFS    += __IPERF__
  endif
endif

ifdef VOIP_SUPPORT
  ifneq ($(strip $(VOIP_SUPPORT)),FALSE)
     COM_DEFS    += __VOIP__  __SAF__
  endif
endif

ifdef TFTP_SUPPORT
  ifeq ($(strip $(TFTP_SUPPORT)),TRUE)
     COM_DEFS    += __TFTP__
  endif
endif

ifndef PHB_SIM_ENTRY
     PHB_SIM_ENTRY = 250
endif

ifdef PHB_SIM_ENTRY
     COM_DEFS    += MAX_PHB_SIM_ENTRY=$(strip $(PHB_SIM_ENTRY))
endif

ifndef PHB_PHONE_ENTRY
     PHB_PHONE_ENTRY = 200
endif

ifdef PHB_PHONE_ENTRY
     COM_DEFS    += MAX_PHB_PHONE_ENTRY=$(strip $(PHB_PHONE_ENTRY))
endif

ifndef PHB_LN_ENTRY
     PHB_LN_ENTRY = 20
endif

ifdef PHB_LN_ENTRY
     COM_DEFS    += MAX_PHB_LN_ENTRY=$(strip $(PHB_LN_ENTRY))
endif

ifndef PHONE_TYPE
  PHONE_TYPE = BAR
endif

ifdef PHONE_TYPE
     COM_DEFS    += __PHONE_$(strip $(PHONE_TYPE))__
     ifeq ($(strip $(PHONE_TYPE)),CLAMSHELL)
        COM_DEFS  +=  CLAM_SUPPORT
     endif
endif

ifdef SUBLCD_DEDICATED_KEYS_SUPPORT
  ifeq ($(strip $(SUBLCD_DEDICATED_KEYS_SUPPORT)),TRUE)
    ifeq ($(strip $(PHONE_TYPE)),CLAMSHELL)
        COM_DEFS    +=  __SUBLCD_DEDICATED_KEYS_SUPPORT__
    else
        $(error SUBLCD_DEDICATED_KEYS_SUPPORT only support in clam shell, please turn off SUBLCD_DEDICATED_KEYS_SUPPORT)
    endif
  endif
endif



ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
    IRDA_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B
    ifneq ($(findstring $(strip $(PLATFORM)),$(IRDA_NOT_SUPPORT_PLATFORM)),)
       $(error Chip version $(strip $(PLATFORM)) not support IRDA_SUPPORT.)
    endif
   ifeq ($(strip $(PLATFORM)),MT6228)
      COM_DEFS    += __IRDA_SUPPORT__ __IRDA_MIR_SUPPORT__ __IRDA_FIR_SUPPORT__
   else
      ifeq ($(strip $(PLATFORM)),MT6229)
          COM_DEFS    += __IRDA_SUPPORT__ __IRDA_MIR_SUPPORT__ __IRDA_FIR_SUPPORT__
      else
        ifeq ($(strip $(PLATFORM)),MT6230)
          COM_DEFS    += __IRDA_SUPPORT__ __IRDA_MIR_SUPPORT__ __IRDA_FIR_SUPPORT__
        else
          ifeq ($(strip $(PLATFORM)),MT6238)
            COM_DEFS    += __IRDA_SUPPORT__ __IRDA_MIR_SUPPORT__ __IRDA_FIR_SUPPORT__
          else
            COM_DEFS    += __IRDA_SUPPORT__
          endif
        endif
      endif
   endif
endif

ifdef NAND_FLASH_BOOTING
  ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
    NAND_FLASH_BOOTING_SUPPORT_PLATFORM = MT6228 MT6229 MT6225 MT6230 MT6238
    ifeq ($(findstring $(strip $(PLATFORM)),$(NAND_FLASH_BOOTING_SUPPORT_PLATFORM)),)
      $(error Chip version $(strip $(PLATFORM)) not support NAND_FLASH_BOOTING.)
    endif
    ifdef NAND_SUPPORT
      ifeq ($(strip $(NAND_SUPPORT)),FALSE)
       $(error Please turn off NAND_FLASH_BOOTING or turn on NAND_SUPPORT!)
      endif
    endif
    COM_DEFS    += _NAND_FLASH_BOOTING_
  endif
    CUS_REL_BASE_COMP += bootloader make\bootloader
endif

ifdef FOTA_ENABLE
   ifneq ($(strip $(FOTA_ENABLE)),NONE)
      ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
         $(error Please turn off SECURE_SUPPORT when FOTA_ENABLE is turned on.)
      endif
   endif
   ifneq ($(strip $(FOTA_ENABLE)),NONE)
      COM_DEFS += __$(strip $(FOTA_ENABLE))__ __FOTA_ENABLE__
   endif
endif

ifdef SINGLE_BANK_NOR_FLASH_SUPPORT
   ifeq ($(strip $(SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
     ifdef EMS_SUPPORT
       ifneq ($(strip $(EMS_SUPPORT)),EMS_NONE)
         $(error EMS_SUPPORT should be set to EMS_NONE when SINGLE_BANK_NOR_FLASH_SUPPORT is TRUE)
       endif
     endif
     ifdef FS_SORT_SUPPORT
       ifneq ($(strip $(FS_SORT_SUPPORT)),FALSE)
         $(error FS_SORT_SUPPORT should be set to FALSE when SINGLE_BANK_NOR_FLASH_SUPPORT is TRUE)
       endif
     endif
     ifdef FS_MOVE_SUPPORT
       ifneq ($(strip $(FS_MOVE_SUPPORT)),FALSE)
         $(error FS_MOVE_SUPPORT should be set to FALSE when SINGLE_BANK_NOR_FLASH_SUPPORT is TRUE)
       endif
     endif
     ifdef MMI_VERSION
       ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
         $(error Cannot set MMI_VERSION to PLUTO_MMI when SINGLE_BANK_NOR_FLASH_SUPPORT is TRUE)
       endif
     endif
     COM_DEFS += _LOW_COST_SINGLE_BANK_FLASH_
   endif
endif

ifdef ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT
  ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
    ifeq ($(strip $(SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
    	$(error ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT and SINGLE_BANK_NOR_FLASH_SUPPORT must exclusive )
    else
      COM_DEFS += __SINGLE_BANK_NOR_FLASH_SUPPORT__
    endif
  endif
endif

ifdef SWDBG_SUPPORT
   ifeq ($(strip $(SWDBG_SUPPORT)),TRUE)
      SWDBG_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6223 MT6223P MT6238
      ifeq ($(findstring $(strip $(PLATFORM)),$(SWDBG_SUPPORT_PLATFORM)),)
          $(error Chip version $(strip $(PLATFORM)) not support SWDBG_SUPPORT.)
      endif
      ifeq ($(strip $(NAND_SUPPORT)),TRUE)
        $(error NAND_SUPPORT and SWDBG_SUPPORT must be exclusive!)
      endif
      ifneq ($(strip $(WIFI_SUPPORT)),NONE)
        $(error WIFI_SUPPORT and SWDBG_SUPPORT must be exclusive!)
      endif
      COM_DEFS    += __SWDBG_SUPPORT__
   endif
endif

ifdef UID_SUPPORT
   ifeq ($(strip $(UID_SUPPORT)),TRUE)
      UID_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6227 MT6226 MT6226M MT6225 MT6223 MT6227D MT6226D MT6223P MT6238
      ifeq ($(findstring $(strip $(PLATFORM)),$(UID_SUPPORT_PLATFORM)),)
          $(error Chip version $(strip $(PLATFORM)) not support UID_SUPPORT.)
      endif
      COM_DEFS    += UID_SUPPORT
   endif
else
UID_SUPPORT = FALSE
endif

ifdef WMA_DECODE
  ifeq ($(strip $(WMA_DECODE)),TRUE)
      WMA_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238
      ifeq ($(findstring $(strip $(PLATFORM)),$(WMA_DECODE_SUPPORT_PLATFORM)),)
          $(error Chip version $(strip $(PLATFORM)) not support WMA_DECODE.)
      endif
      COM_DEFS    += WMA_DECODE
  endif
endif

ifdef LOW_COST_SUPPORT
    ifeq ($(strip $(LOW_COST_SUPPORT)),TRUE)
      COM_DEFS    +=  LOW_COST_SUPPORT
    endif
endif

ifdef AAC_PLUS_DECODE
   ifeq ($(strip $(AAC_PLUS_DECODE)),TRUE)
      AAC_PLUS_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6223 MT6227D MT6226D MT6223P MT6238
      ifeq ($(findstring $(strip $(PLATFORM)),$(AAC_PLUS_DECODE_SUPPORT_PLATFORM)),)
         $(error Chip version $(strip $(PLATFORM)) not support AAC_PLUS_DECODE.)
      endif
      COM_DEFS    +=  AAC_PLUS_DECODE
   endif
endif


ifdef AAC_PLUS_PS_DECODE
   ifeq ($(strip $(AAC_PLUS_PS_DECODE)),TRUE)
      AAC_PLUS_PS_DECODE_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6226 MT6227 MT6226M MT6225 MT6223 MT6227D MT6226D MT6223P MT6238
      ifeq ($(findstring $(strip $(PLATFORM)),$(AAC_PLUS_PS_DECODE_SUPPORT_PLATFORM)),)
         $(error Chip version $(strip $(PLATFORM)) does not support AAC_PLUS_PS_DECODE.)
      endif
      ifeq ($(strip $(AAC_PLUS_DECODE)),FALSE)
         $(error Please turn on AAC_PLUS_DECODE or turn off AAC_PLUS_PS_DECODE.)
      endif
      COM_DEFS    +=  AAC_PLUS_PS_DECODE
   endif
endif



ifdef EMS_SUPPORT
    ifeq ($(strip $(EMS_SUPPORT)),EMS_50)
      COM_DEFS    +=  __EMS_REL5__
    endif
    ifeq ($(strip $(EMS_SUPPORT)),EMS_40)
       # do nothing
    endif
    ifeq ($(strip $(EMS_SUPPORT)),EMS_NONE)
      COM_DEFS    +=  __SLIM_EMS__
    endif
endif

ifdef EDGE_SUPPORT
   ifeq ($(strip $(EDGE_SUPPORT)),TRUE)
      EDGE_SUPPORT_PLATFORM = MT6229 MT6230 MT6238 MT6268 MT6516
      ifeq ($(findstring $(strip $(PLATFORM)),$(EDGE_SUPPORT_PLATFORM)),)
         $(error Chip version $(strip $(PLATFORM)) does not support EGPRS.)
      endif

      COM_DEFS    += __EGPRS_MODE__
      ifeq ($(strip $(L1_EPSK_TX)),TRUE)
        COM_DEFS    +=  __EPSK_TX__
      endif
   endif
endif

ifdef XDM_SUPPORT
ifneq ($(strip $(XDM_SUPPORT)),FALSE)
  # XDM_SUPPORT should be based on TELECA_FEATURE (WAP2 and SEC)
  ifdef TELECA_FEATURE
    ifneq ($(strip $(TELECA_FEATURE)),NONE)
       ifneq ($(strip $(TELECA_FEATURE)),WAP2_SEC)
          ifneq ($(strip $(TELECA_FEATURE)),WAP2_SEC_MMS)
             $(error Please turn XDM_SUPPORT as FALSE or turn TELECA_FEATURE to WAP2_SEC or WAP2_SEC_MMS!)
          endif
       endif
    else
      ifdef JATAAYU_FEATURE
         ifneq  ($(strip $(JATAAYU_FEATURE)),NONE)
	    ifneq ($(findstring WAP2,$(strip $(JATAAYU_FEATURE))),WAP2)
               $(error Please turn XDM_SUPPORT as FALSE or turn JATAAYU_FEATURE to WAP2_XXX)
            endif
         else
            $(error Please turn XDM_SUPPORT as FALSE or turn JATAAYU_FEATURE to WAP2_XXX or turn TELECA_FEATURE to WAP2_SEC or WAP2_SEC_MMS!)
         endif
      endif
    endif
  else
    ifdef JATAAYU_FEATURE
       ifneq  ($(strip $(JATAAYU_FEATURE)),NONE)
	  ifneq ($(findstring WAP2,$(strip $(JATAAYU_FEATURE))),WAP2)
             $(error Please turn XDM_SUPPORT as FALSE or turn JATAAYU_FEATURE to WAP2_XXX)
	  endif
       else
          $(error Please turn XDM_SUPPORT as FALSE or turn JATAAYU_FEATURE to WAP2_XXX)
       endif
    else
      $(error Please turn XDM_SUPPORT as FALSE or turn JATAAYU_FEATURE to WAP2_XXX or turn TELECA_FEATURE to WAP2_SEC or WAP2_SEC_MMS!)
    endif
  endif
  # XDM_SUPPORT should be based on XML_SUPPORT
  ifdef XML_SUPPORT
  ifeq ($(strip $(XML_SUPPORT)),FALSE)
      $(error Please turn XDM_SUPPORT as FALSE or turn on XML_SUPPORT!)
  endif
  endif
endif
endif

ifdef POC_SUPPORT
  ifneq ($(strip $(POC_SUPPORT)),NONE)
    ifeq ($(strip $(SIP_SUPPORT)),FALSE)
       $(error Please set POC_SUPPORT as NONE or turn on SIP_SUPPORT!)
    endif
    ifeq ($(strip $(XDM_SUPPORT)),FALSE)
       $(error Please set POC_SUPPORT as NONE or turn on XDM_SUPPORT!)
    endif
  endif
endif

ifdef R99_SUPPORT
  R99_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B MT6219
  ifeq ($(strip $(R99_SUPPORT)),TRUE)
    ifeq ($(findstring $(strip $(PLATFORM)),$(R99_NOT_SUPPORT_PLATFORM)),)
      COM_DEFS    +=   __R99__
      CUSTOM_OPTION    += __R99__
    else
       $(error Chip version $(strip $(PLATFORM)) not support R99_SUPPORT.)
    endif
  endif
endif


ifdef CHE_SUPPORT
  ifeq ($(strip $(PLATFORM)),MT6228)
    ifeq ($(strip $(CHE_SUPPORT)),TRUE)
       COM_DEFS    +=  __HW_CHE__
    endif
  endif
endif

ifdef TV_OUT_SUPPORT
  ifeq ($(strip $(HORIZONTAL_CAMERA)),TRUE)
    ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
      ifeq ($(strip $(LCM_ROTATE_SUPPORT)),FALSE)
          $(error Please set LCM_ROTATE_SUPPORT as TRUE or turn off  HORIZONTAL_CAMERA or TV_OUT_SUPPORT !)
      endif
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6229)
    ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
       COM_DEFS    +=  TV_OUT_SUPPORT
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6238)
    ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
       COM_DEFS    +=  TV_OUT_SUPPORT
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6230)
    ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
       COM_DEFS    +=  TV_OUT_SUPPORT
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6228)
    ifeq ($(strip $(TV_OUT_SUPPORT)),TRUE)
       COM_DEFS    +=  TV_OUT_SUPPORT
    endif
  endif
endif

ifndef MAIN_LCD_SIZE
   MAIN_LCD_SIZE = 0X0
endif

ifdef MAIN_LCD_SIZE
   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),120X160)
      # spacial case for MTKLCM_COLOR in MT6208 EVB
      MAIN_LCD_SIZE := 128X160
   endif

   ifeq ($(call Upper,$(strip $(MAIN_LCD_SIZE))),128X128)
     ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
       $(error MAIN_LCD_SIZE 128X128 does not support TOUCH_PANEL)
     endif
   endif
   COM_DEFS    += __MMI_MAINLCD_$(call Upper,$(strip $(MAIN_LCD_SIZE)))__
endif

ifndef SUB_LCD_SIZE
    SUB_LCD_SIZE = NONE
endif

ifdef SUB_LCD_SIZE
    COM_DEFS += __MMI_SUBLCD_$(call Upper,$(strip $(SUB_LCD_SIZE)))__
endif

ifeq ($(strip $(MMI_MAIN_LCD_DEFAULT_FORMAT)),16)
    COM_DEFS    +=  MMI_MAIN_LCD_DEFAULT_FORMAT=16
endif
ifeq ($(strip $(MMI_MAIN_LCD_DEFAULT_FORMAT)),24)
    COM_DEFS    +=  MMI_MAIN_LCD_DEFAULT_FORMAT=24
endif
ifeq ($(strip $(MMI_MAIN_LCD_DEFAULT_FORMAT)),32)
    COM_DEFS    +=  MMI_MAIN_LCD_DEFAULT_FORMAT=32
endif
ifeq ($(strip $(MMI_SUB_LCD_DEFAULT_FORMAT)),16)
    COM_DEFS    +=  MMI_SUB_LCD_DEFAULT_FORMAT=16
endif
ifeq ($(strip $(MMI_SUB_LCD_DEFAULT_FORMAT)),24)
    COM_DEFS    +=  MMI_SUB_LCD_DEFAULT_FORMAT=24
endif
ifeq ($(strip $(MMI_SUB_LCD_DEFAULT_FORMAT)),32)
    COM_DEFS    +=  MMI_SUB_LCD_DEFAULT_FORMAT=32
endif


ifdef BACKGROUND_SOUND
	ifeq ($(strip $(BACKGROUND_SOUND)),TRUE)
		COM_DEFS	+= BGSND_ENABLE
	endif
endif

ifdef WEBCAM_SUPPORT
	ifeq ($(strip $(WEBCAM_SUPPORT)),TRUE)
      WEBCAM_SUPPORT_NOT_SUPPORT_PLATFORM = MT6205B MT6217 MT6218B
      ifneq ($(findstring $(strip $(PLATFORM)),$(WEBCAM_SUPPORT_NOT_SUPPORT_PLATFORM)),)
         $(error Chip version $(strip $(PLATFORM)) not support WEBCAM_SUPPORT.)
      else
		COM_DEFS	+= WEBCAM_SUPPORT
	endif
endif
endif

# AUDIO_POST_PROCESS for 6228/6229/6230/6238 only
AUDIO_POST_PROCESS_SUPPORT_PLATFORM = MT6228 MT6229 MT6230 MT6238
ifdef AUDIO_POST_PROCESS
        ifneq ($(strip $(AUDIO_POST_PROCESS)),NONE)
           ifeq ($(findstring $(strip $(PLATFORM)),$(AUDIO_POST_PROCESS_SUPPORT_PLATFORM)),)
              $(error Chip version $(strip $(PLATFORM)) not support AUDIO_POST_PROCESS.)
           endif
        endif

	ifeq ($(strip $(AUDIO_POST_PROCESS)),ALL_EFFECT)
		COM_DEFS	+= AUD_REVERB
		COM_DEFS	+= AUD_TIME_STRETCH
	else
		ifeq ($(strip $(AUDIO_POST_PROCESS)),REVERB_ONLY)
			COM_DEFS	+= AUD_REVERB
		else
			ifeq ($(strip $(AUDIO_POST_PROCESS)),TIME_STRETCH_ONLY)
				COM_DEFS	+= AUD_TIME_STRETCH
			endif
		endif
	endif
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COM_DEFS    +=  __DT_SUPPORT__
  endif
endif

ifeq ($(strip $(AU_DECODE)),TRUE)
   AU_DECODE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(findstring $(strip $(PLATFORM)),$(AU_DECODE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(error Chip version $(strip $(PLATFORM)) not support AU_DECODE.)
   endif
      COM_DEFS    += AU_DECODE
endif


ifeq ($(strip $(AIFF_DECODE)),TRUE)
   AIFF_DECODE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208 
   ifeq ($(findstring $(strip $(PLATFORM)),$(AIFF_DECODE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(error Chip version $(strip $(PLATFORM)) not support AIFF_DECODE.)
   endif
   COM_DEFS    += AIFF_DECODE
endif

ifeq ($(strip $(JTONE_SUPPORT)),TRUE)
   JTONE_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6218 MT6218B MT6208
   ifeq ($(findstring $(strip $(PLATFORM)),$(JTONE_NOT_SUPPORT_PLATFORM)),$(strip $(PLATFORM)))
      $(error Chip version $(strip $(PLATFORM)) not support JTONE_SUPPORT.)
   endif
   COM_DEFS    += JTONE_SUPPORT
endif



ifdef AF_SUPPORT
  ifneq ($(strip $(AF_SUPPORT)),FALSE)
    ifndef LENS_MODULE
  		$(error Please set LENS_MODULE when AF_SUPPORT = TRUE or turn off AF_SUPPORT.)
  	endif
  	ifeq ($(strip $(LENS_MODULE)),NONE)
  		$(error Please set LENS_MODULE when AF_SUPPORT = TRUE or turn off AF_SUPPORT.)
  	endif
     COM_DEFS    +=  AF_SUPPORT
  endif
endif


ifdef CTM_SUPPORT
  ifneq ($(strip $(CTM_SUPPORT)),FALSE)
     COM_DEFS    +=  __CTM_SUPPORT__
  endif
endif

ifdef XDM_SUPPORT
  ifeq ($(strip $(XDM_SUPPORT)),TRUE)
     COM_DEFS    += __XDM__
  endif
endif

#
#ifdef BT_HFG_PROFILE
#  ifeq ($(strip $(BT_HFG_PROFILE)),TRUE)
#    COM_DEFS    +=  __BT_HFG_PROFILE__
#  else
#    COM_DEFS    += EXCLUDE_HFG_MODULE
#  endif
#endif
#

# JSR184
ifndef J2ME_JSR184_SUPPORT
   J2ME_JSR184_SUPPORT = NONE
endif

ifdef J2ME_JSR184_SUPPORT
  ifneq ($(strip $(J2ME_JSR184_SUPPORT)),NONE)
    ifeq ($(strip $(OPENGL)),NONE)
      $(error Please set OPENGL or turn off J2ME_JSR184_SUPPORT!)
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
        $(error When J2ME_SUPPORT=JBLENDIA, please turn off J2ME_JSR184_SUPPORT!)
    endif
    # We can turn on J2ME_JSR184_SUPPORT  when J2MEHI_LIB is defined in J2ME_SUPPORT.
    ifeq ($(findstring J2MEHI,$(J2ME_SUPPORT)),)
      $(error Please change J2ME_JSR184_SUPPORT to NONE  or set J2MEHI_LIB in  J2ME_SUPPORT )
    else
      COM_DEFS += SUPPORT_JSR_184
    endif
    ifdef OPENGL
      ifneq ($(strip $(OPENGL)),NONE)
        COM_DEFS += M3D_SUPPORT
      endif
    endif
  endif
endif


ifndef M3D_MMI_SUPPORT
   M3D_MMI_SUPPORT = FALSE
endif

ifdef M3D_MMI_SUPPORT
  ifneq ($(strip $(M3D_MMI_SUPPORT)),FALSE)
    ifeq ($(strip $(OPENGL)),NONE)
       $(error Please set OPENGL or turn off M3D_MMI_SUPPORT!)
    else
       # We can turn on M3D_MMI_SUPPORT  when J2MEHI_LIB is defined in J2ME_SUPPORT.
       ifeq ($(strip $(J2ME_JSR184_SUPPORT)),NONE)
          COM_DEFS += M3D_MMI_SUPPORT M3D_SUPPORT
       else
          COM_DEFS += M3D_MMI_SUPPORT
       endif
    endif
  endif
endif





ifdef LCM_ROTATE_SUPPORT
  ifeq ($(strip $(LCM_ROTATE_SUPPORT)),TRUE)
      COM_DEFS += LCM_ROTATE_SUPPORT
  endif
endif

ifdef EXIF_SUPPORT
  ifeq ($(strip $(EXIF_SUPPORT)),TRUE)
  	ifdef YUV_SENSOR_SUPPORT
  		ifeq ($(strip $(YUV_SENSOR_SUPPORT)),TRUE)
  			$(error YUV_SENSOR_SUPPORT cannot be TRUE when EXIF_SUPPORT = TRUE)
  		endif
  	endif	
      COM_DEFS += EXIF_SUPPORT
  endif
endif

ifdef SVG_SUPPORT
  ifeq ($(strip $(SVG_SUPPORT)),TRUE)
      COM_DEFS += SVG_SUPPORT
  endif
endif

#ifdef USB_IN_NORMAL_MODE_SUPPORT
#  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
#	COM_DEFS += __USB_IN_NORMAL_MODE__
#	ifeq ($(strip $(BOARD_VER)),DRAGONFLY_BB)
#	   COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
#        endif
#	ifeq ($(strip $(BOARD_VER)),SAPPHIRE28_BB)
#	   COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
#        endif
#  endif
#endif

ifdef USB_IN_NORMAL_MODE_SUPPORT
  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
	COM_DEFS += __USB_IN_NORMAL_MODE__
	COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
  endif
endif


ifneq ($(strip $(PLATFORM)),MT6205B)
   ifneq ($(strip $(PLATFORM)),MT6208)
     ifneq ($(strip $(PLATFORM)),MT6218B)
       ifneq ($(strip $(PLATFORM)),MT6217)
         COM_DEFS +=  __USIM_DRV__
       endif
     endif
   endif
endif

ifdef OTG_SUPPORT
ifdef USB_IN_NORMAL_MODE_SUPPORT
   ifneq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
      ifeq ($(strip $(OTG_SUPPORT)),TRUE)
         $(error Please turn off OTG_SUPPORT or turn on USB_IN_NORMAL_MODE_SUPPORT.)
      endif
   else
      ifeq ($(strip $(OTG_SUPPORT)),TRUE)
         ifeq ($(findstring __USB_MULTI_CHARGE_CURRENT__,$(strip $(CUSTOM_OPTION))),)
            $(error Please turn off OTG_SUPPORT or define __USB_MULTI_CHARGE_CURRENT__ option.)
         else
            COM_DEFS	+= __OTG_ENABLE__
         endif
      endif
   endif
endif
endif

ifdef OTG_DETECT_ID_PIN_WITH_EINT
  ifeq ($(strip $(OTG_DETECT_ID_PIN_WITH_EINT)),TRUE)
	COM_DEFS += __OTG_DETECT_IDPIN_WITH_EINT__
  endif
endif



ifdef OPENGL
  ifneq ($(strip $(OPENGL)),NONE)
     COM_DEFS +=  __OPENGL_SUPPORT__
     COMPLIST         += opengl opengl16
     CUS_REL_MTK_COMP    += opengl opengl16
  endif
  ifeq ($(strip $(OPENGL)),COMMON_LITE)
     COM_DEFS +=  __COMMON_LITE__
     COMPOBJS    += dp_engine\opengl\swrast\affine_span_sfo.obj
     COMPOBJS    += dp_engine\opengl\swrast\fast_persp_span_sfo.obj
     COMPOBJS    += dp_engine\opengl\swrast\s_span_arm_sfo_flat.obj
     COMPOBJS    += dp_engine\opengl\swrast\s_span_arm_sfo_smooth.obj
     CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\affine_span_sfo.obj
     CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\fast_persp_span_sfo.obj
     CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\s_span_arm_sfo_flat.obj
     CUS_REL_OBJ_LIST    += dp_engine\opengl\swrast\s_span_arm_sfo_smooth.obj
  endif
endif

ifneq ($(findstring __DISABLE_SMS_CONTROLLED_BY_SIM__,$(strip $(CUSTOM_OPTION))),)
  ifeq ($(findstring __SAT__,$(strip $(CUSTOM_OPTION))),)
    $(error Please define __SAT__ or don't define __DISABLE_SMS_CONTROLLED_BY_SIM__)
  endif
endif

ifdef USB_MULTI_CHARGE_CURRENT_SUPPORT
  ifeq ($(strip $(USB_MULTI_CHARGE_CURRENT_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(error Please turn on USB_SUPPORT or turn off USB_MULTI_CHARGE_CURRENT_SUPPORT )
     else
        COM_DEFS +=  __USB_MULTI_CHARGE_CURRENT__
     endif
  endif
endif

ifdef RC5_SUPPORT
  ifeq ($(strip $(RC5_SUPPORT)),TRUE)
    ifeq ($(findstring SEC,$(strip $(TELECA_FEATURE))),SEC)
      COM_DEFS    += RC5_SUPPORT
    endif
  endif
endif


ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
     ifeq ($(strip $(OPENGL)),NONE)
        $(error Please turn on OPENGL or turn off GAME_ENGINE )
     else
        COM_DEFS +=  $(strip $(GAME_ENGINE))
     endif
  endif
endif

ifdef YUV_SENSOR_SUPPORT
  ifneq ($(strip $(YUV_SENSOR_SUPPORT)),FALSE)
     ifeq ($(strip $(ISP_SUPPORT)),FALSE)
        $(error Please turn on ISP_SUPPORT or turn off YUV_SENSOR_SUPPORT )
     else
        COM_DEFS += YUV_SENSOR_SUPPORT
     endif
  endif
endif

ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6225)
    ifdef ISP_SUPPORT
      ifneq ($(strip $(ISP_SUPPORT)),FALSE)
        ifdef YUV_SENSOR_SUPPORT
          ifeq ($(strip $(YUV_SENSOR_SUPPORT)),FALSE)
            $(error Please turn on YUV_SENSOR_SUPPORT when PLATFORM = MT6225 and ISP_SUPPORT is turned on.)
          endif
        endif
      endif
    endif
  endif
endif

ifdef EXT_DAC_SUPPORT
  ifeq ($(strip $(EXT_DAC_SUPPORT)),TRUE)
     COM_DEFS    +=  EXT_DAC_SUPPORT
  endif
endif

ifdef UNIFIED_MESSAGE_SUPPORT
   ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
      ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
        $(error $(MMI_VERSION) doesn't support UNIFIED_MESSAGE )
      endif
   endif
endif

ifdef UNIFIED_MESSAGE_SUPPORT
  ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),TRUE)
     ifneq ($(strip $(TELECA_FEATURE)),NONE)
        ifeq ($(findstring WAP,$(strip $(TELECA_FEATURE))),)
           $(error Please turn on WAP in TELECA_FEATURE or turn off UNIFIED_MESSAGE_SUPPORT )
        else
           ifeq ($(findstring MMS,$(strip $(TELECA_FEATURE))),)
              $(error Please turn on MMS in TELECA_FEATURE or turn off UNIFIED_MESSAGE_SUPPORT )
           else
              ifeq ($(strip $(PROJECT)),GSM)
                 $(error GSM project doesn't support UNIFIED_MESSAGE_SUPPORT)
              else
                 COM_DEFS    +=  __UNIFIED_MSG_SUPPORT__
              endif
           endif
        endif
     else
        ifeq ($(findstring WAP,$(strip $(JATAAYU_FEATURE))),)
           $(error Please turn on WAP in JATAAYU_FEATURE or turn off UNIFIED_MESSAGE_SUPPORT )
        else
           ifeq ($(findstring MMS,$(strip $(JATAAYU_FEATURE))),)
              $(error Please turn on MMS in JATAAYU_FEATURE or turn off UNIFIED_MESSAGE_SUPPORT )
           else
              ifeq ($(strip $(PROJECT)),GSM)
                 $(error GSM project doesn't support UNIFIED_MESSAGE_SUPPORT)
              else
                 COM_DEFS    +=  __UNIFIED_MSG_SUPPORT__
              endif
           endif
        endif
     endif
  endif
endif


ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
     COM_DEFS    +=  __CUST_NEW__
  endif
endif


#ifdef WAP_SUPPORT
#ifdef TELECA_FEATURE
#  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
#     ifeq ($(strip $(TELECA_FEATURE)),NONE)
#           $(error Please turn on TELECA_FEATURE or turn off OBIGO_Q03C in WAP_SUPPORT )
#     endif
#     ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
#           $(error Please turn off JATAAYU_FEATURE or turn off OBIGO_Q03C in WAP_SUPPORT )
#     endif
#  endif
#  ifeq ($(strip $(WAP_SUPPORT)),JATAAYU4)
#     ifneq ($(strip $(TELECA_FEATURE)),NONE)
#           $(error Please turn off TELECA_FEATURE or turn off JATAAYU4 in WAP_SUPPORT )
#     endif
#     ifeq ($(strip $(JATAAYU_FEATURE)),NONE)
#           $(error Please turn on JATAAYU_FEATURE or turn off JATAAYU4 in WAP_SUPPORT )
#     endif
#  endif
#  ifeq ($(strip $(WAP_SUPPORT)),NONE)
#     ifneq ($(strip $(TELECA_FEATURE)),NONE)
#           $(error Please turn off TELECA_FEATURE or turn on WAP_SUPPORT )
#     endif
#     ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
#           $(error Please turn off JATAAYU_FEATURE or turn on WAP_SUPPORT )
#     endif
#  endif
#endif
#endif


#ifdef WAP_SUPPORT
#  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
#    COM_DEFS    +=  __Q03C__
#    ifeq ($(findstring WAP,$(TELECA_FEATURE)),WAP)
#      COM_DEFS    +=  OBIGO_WAP
#    endif
#    ifeq ($(findstring MMS,$(TELECA_FEATURE)),MMS)
#      COM_DEFS    +=  OBIGO_MMS
#    endif
#  else
#    ifeq ($(strip $(WAP_SUPPORT)),JATAAYU4)
#      COM_DEFS    +=  __JATAAYU4__
#    ifeq ($(findstring WAP,&(JATAAYU_FEATURE)),WAP)
#        COM_DEFS    +=  JATAAYU_WAP
#      endif
#     ifeq ($(findstring MMS,$(JATAAYU_FEATURE)),MMS)
#        COM_DEFS    +=  JATAAYU_MMS
#      endif
#    endif
#  endif
#endif


ifdef WAP_SUPPORT
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
    COM_DEFS    +=   OBIGO_Q03C
    ifeq ($(findstring WAP,$(TELECA_FEATURE)),WAP)
      COM_DEFS    +=  OBIGO_WAP
    endif
    ifeq ($(findstring MMS,$(TELECA_FEATURE)),MMS)
      COM_DEFS    +=  OBIGO_MMS
    endif  
  endif
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
    COM_DEFS    +=  OBIGO_Q05A
    ifeq ($(findstring WAP,$(TELECA_FEATURE)),WAP)
      COM_DEFS    +=  OBIGO_WAP
    endif
    ifeq ($(findstring MMS,$(TELECA_FEATURE)),MMS)
      COM_DEFS    +=  OBIGO_MMS
    endif    
  endif
  ifeq ($(strip $(WAP_SUPPORT)),JATAAYU4)
    COM_DEFS    +=  __JATAAYU4__
    ifeq ($(findstring WAP,&(JATAAYU_FEATURE)),WAP)
        COM_DEFS    +=  JATAAYU_WAP
    endif
    ifeq ($(findstring MMS,$(JATAAYU_FEATURE)),MMS)
        COM_DEFS    +=  JATAAYU_MMS
    endif
  endif  
endif


ifdef JATAAYU_FEATURE
  ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
     COM_DEFS    +=    JATAAYU_SUPPORT
     ifeq ($(strip $(JATAAYU_FEATURE)),WAP)
          COM_DEFS    +=  WAP_SUPPORT
     endif
     ifeq ($(strip $(JATAAYU_FEATURE)),WAP2)
          COM_DEFS    +=  WAP_SUPPORT  WAP2
     endif
     ifeq ($(strip $(JATAAYU_FEATURE)),WAP_MMS)
          COM_DEFS    +=  WAP_SUPPORT MMS_SUPPORT
     endif
     ifeq ($(strip $(JATAAYU_FEATURE)),WAP2_MMS)
          COM_DEFS    +=  WAP_SUPPORT WAP2 MMS_SUPPORT
     endif
     ifeq ($(strip $(JATAAYU_FEATURE)),WAP_SEC)
          COM_DEFS    +=  WAP_SUPPORT WAP_SEC_SUPPORT
     endif
     ifeq ($(strip $(JATAAYU_FEATURE)),WAP2_SEC)
          COM_DEFS    +=  WAP_SUPPORT WAP2 WAP_SEC_SUPPORT
     endif
     ifeq ($(strip $(JATAAYU_FEATURE)),WAP_SEC_MMS)
          COM_DEFS    +=  WAP_SUPPORT MMS_SUPPORT WAP_SEC_SUPPORT
     endif
     ifeq ($(strip $(JATAAYU_FEATURE)),WAP2_SEC_MMS)
          COM_DEFS    +=  WAP_SUPPORT WAP2 MMS_SUPPORT WAP_SEC_SUPPORT
     endif
  endif
endif

#
#ifeq ($(strip $(TELECA_FEATURE)),NONE)
#	COM_DEFS    += WAP_NOT_PRESENT
#	ifeq ($(strip $(JATAAYU_FEATURE)),NONE)
#     	COM_DEFS    += WPS_NOT_PRESENT
#	endif
#endif
#

ifeq ($(strip $(TELECA_FEATURE)),NONE)
   COM_DEFS    += WAP_NOT_PRESENT
   ifeq ($(strip $(JATAAYU_FEATURE)),NONE)
      COM_DEFS    += WPS_NOT_PRESENT
   endif
else
   ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
      COM_DEFS    += WAP_NOT_PRESENT
   endif
endif


ifdef DSPIRDBG
   ifeq ($(strip $(DSPIRDBG)),TRUE)
      COM_DEFS    += __DSPIRDBG__
   endif
endif

ifndef ISP_SUPPORT
   COM_DEFS    += MED_C_NOT_PRESENT
endif

ifdef ISP_SUPPORT
   ifeq ($(strip $(ISP_SUPPORT)),FALSE)
      COM_DEFS    += MED_C_NOT_PRESENT
   endif
endif

ifdef PROJECT
   ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
      ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
         COM_DEFS    += __MANUAL_MODE_NW_SEL__  __NORMAL_NW_SEARCH__
      endif
   endif
endif

ifdef CUST_PARA_SUPPORT
   ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
      COM_DEFS += __CUST_PARA_SUPPORT__
   endif
endif

ifdef DISPLAY_TYPE
    COM_DEFS    += __MMI_DISPLAY_TYPE_$(call Upper,$(strip $(DISPLAY_TYPE)))__
endif

ifdef OTP_SUPPORT
   ifeq ($(strip $(OTP_SUPPORT)),TRUE)
      COM_DEFS    += __SECURITY_OTP__
   endif
endif

#6226C (S02), 6229E4, and 6225 and newer chip related project only.
SECURE_SUPPORT_NOT_SUPPORT_PLATFORM = MT6205B MT6208 MT6217 MT6218B MT6219 MT6226 MT6226M MT6227 MT6228 MT6229 MT6238
SECURE_SUPPORT_NOT_SUPPORT_PARTIAL_PLATFORM = MT6226 MT6226M MT6227 MT6229 MT6238
SECURE_SUPPORT_NOT_SUPPORT_CHIPVER = S00 S01
# For 6226, 6226M, 6227, 6229: only 6226C (S02), 6226M (S02), 6227 (S02), 6229E4 (S02) and later chip version support SECURE PLATFORM

SECURE_SUPPORT_NOT_SUPPORT_NFB_PLATFORM = MT6226 MT6229 MT6225 MT6223 MT6227 MT6230 MT6226M MT6223P MT6238
SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM = MT6226 MT6229 MT6227 MT6226M MT6238
SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER = S00 S01 S02
# For 6229 (S00, S01, S02), 6226 (S00, S01, S02), 6227 (S00, S01, S02), 6226M (S00, S01, S02): do not support SECURE PLATFORM when NFB is on

ifdef SECURE_SUPPORT
  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    # Platforms which do not support secure platform
    ifneq ($(findstring $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_PLATFORM)),)
       ifneq ($(findstring $(strip $(PLATFORM)), $(SECURE_SUPPORT_NOT_SUPPORT_PARTIAL_PLATFORM)),)
                # Platforms which do not support secure platform
                ifneq ($(findstring $(strip $(CHIP_VER)), $(SECURE_SUPPORT_NOT_SUPPORT_CHIPVER)),)
                  $(error $(strip $(PLATFORM)) $(strip $(CHIP_VER)) not support SECURE_SUPPORT.)
                # Platforms which partially support secure platform (new chip version)
                else
                  ifneq ($(findstring $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM)),)
                     ifneq ($(findstring $(strip $(CHIP_VER)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER)),)
                                ifeq ($(strip $(NAND_FLASH_BOOTING)),FALSE)
                                   COM_DEFS    += __MTK_SECURE_PLATFORM__
                                else
                                   $(error $(strip $(PLATFORM)) $(strip $(CHIP_VER)) does not support SECURE_SUPPORT when NAND_FLASH_BOOTING is TRUE.)
                                endif
                      # new chip version of partial NFB support platform
                      else
                               COM_DEFS    += __MTK_SECURE_PLATFORM__
                      endif
                   endif
                 endif
        # Platforms which do not support secure platform
        else
               $(error $(strip $(PLATFORM)) not support SECURE_SUPPORT.)
        endif
    # Platforms which support secure platform
    else
             ifneq ($(findstring $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PLATFORM)),)
                ifneq ($(findstring $(strip $(PLATFORM)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_PARTIAL_PLATFORM)),)
                  ifneq ($(findstring $(strip $(CHIP_VER)),$(SECURE_SUPPORT_NOT_SUPPORT_NFB_CHIPVER)),)
                         ifeq ($(strip $(NAND_FLASH_BOOTING)),FALSE)
                             COM_DEFS    += __MTK_SECURE_PLATFORM__
                         else
                             $(error $(strip $(PLATFORM)) $(strip $(CHIP_VER)) not support SECURE_SUPPORT when NAND_FLASH_BOOTING = TRUE.)
                         endif
                  endif
                #  NFB support platform
                else
                  ifeq ($(strip $(NAND_FLASH_BOOTING)),FALSE)
                        COM_DEFS    += __MTK_SECURE_PLATFORM__
                  else
                       $(error $(strip $(PLATFORM)) not support SECURE_SUPPORT when NAND_FLASH_BOOTING = TRUE.)
                 endif
                endif
              # other support platforms
              else
                COM_DEFS    += __MTK_SECURE_PLATFORM__
              endif
    endif
  endif
endif

ifdef SECURE_RO_ENABLE
   ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      ifeq ($(strip $(SECURE_SUPPORT)),FALSE)
         $(error Please turn on SECURE_SUPPORT or tunr off  SECURE_RO_ENABLE.)
      else
         COM_DEFS    += __SECURE_RO_ENABLE__
      endif
   endif
endif

ifdef DOWNLOADABLE_THEME
   ifeq ($(strip $(DOWNLOADABLE_THEME)),TRUE)
      ifdef XML_SUPPORT
        ifneq ($(strip $(XML_SUPPORT)),TRUE)
           $(error Please turn on XML_SUPPORT or tunr off  DOWNLOADABLE_THEME.)
        endif
      endif
      ifeq ($(strip $(WAP_SUPPORT)),NONE)
         $(error Please turn on WAP_SUPPORT or tunr off  DOWNLOADABLE_THEME.)
      endif
      COM_DEFS    += __DOWNLOADABLE_THEME__
   endif
endif

ifndef DLT_ALWAYS_LOAD_BUFFER_SIZE
   DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
endif

ifdef DLT_ALWAYS_LOAD_BUFFER_SIZE
   COM_DEFS    += __DLT_ALWAYS_LOAD_BUFFER_SIZE__=$(strip $(DLT_ALWAYS_LOAD_BUFFER_SIZE))
endif

ifndef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
   DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
endif

ifdef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
   COM_DEFS    += __DLT_LOAD_ON_DEMAND_BUFFER_SIZE__=$(strip $(DLT_LOAD_ON_DEMAND_BUFFER_SIZE))
endif

TEARING_REDUCTION_FB_PLATFORM = MT6227 MT6227D MT6226 MT6226M MT6226D
ifneq ($(findstring $(strip $(PLATFORM)),$(TEARING_REDUCTION_FB_PLATFORM)),)
   ifeq ($(strip $(MAIN_LCD_SIZE)),240X320)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
   ifeq ($(strip $(MAIN_LCD_SIZE)),320X240)
      COM_DEFS  +=  __TEARING_REDUCTION_FB_IN_INTSRAM__
   endif
endif

ifdef FOTA_ENABLE
   ifneq ($(strip $(FOTA_ENABLE)),NONE)
      COM_DEFS += __$(strip $(FOTA_ENABLE))__ __FOTA_ENABLE__
   endif
endif

ifdef STREAM_SUPPORT
  ifeq ($(strip $(STREAM_SUPPORT)),TRUE)
     COM_DEFS    += STREAM_SUPPORT
  endif
endif

ifdef PGDL_SUPPORT
  ifeq ($(strip $(PGDL_SUPPORT)),TRUE)
     COM_DEFS    += PGDL_SUPPORT
  endif
endif

ifndef VIRTUAL_PORTS_NUM
     VIRTUAL_PORTS_NUM = 5
endif

ifdef VIRTUAL_PORTS_NUM
     COM_DEFS    += VIRTUAL_PORTS_NUM=$(strip $(VIRTUAL_PORTS_NUM))
endif

ifdef SYNCML_DM_SUPPORT
  ifeq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
    COM_DEFS    += SYNCML_DM_SUPPORT
    COMPLIST    += dm
    #### CUS_REL_SRC_COMP    += dm
    COMPLIST    += dmsdk
    #### CUS_REL_SRC_COMP    += dmsdk    
  endif
endif

ifeq ($(strip $(SPATIAL_DITHERING)),TRUE)
     COM_DEFS += __SPATIAL_DITHERING__
endif

ifeq ($(strip $(PICTBRIDGE_SUPPORT)),TRUE)
     ifeq ($(strip $(USB_SUPPORT)),FALSE)
        $(error Please turn on USB_SUPPORT or turn off PICTBRIDGE_SUPPORT )
     else
        COM_DEFS +=  PICTBRIDGE_SUPPORT
     endif
endif

ifdef UNIFIED_MESSAGE_SUPPORT
   ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
      ifeq ($(strip $(UNIFIED_MESSAGE_SIMBOX_SUPPORT)),TRUE)   
         $(error Please turn on UNIFIED_MESSAGE_SUPPORT or turn off UNIFIED_MESSAGE_SIMBOX_SUPPORT )
      endif   
   else
      ifeq ($(strip $(UNIFIED_MESSAGE_SIMBOX_SUPPORT)),TRUE)
         COM_DEFS	+= __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
      endif
   endif
endif

ifdef TDMB_SUPPORT
  ifneq ($(strip $(TDMB_SUPPORT)),NONE)
    COMPLIST += cyberlink
    COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibDemuxInterface.a
    COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibDLSParser.a
	COMPOBJS += vendor\tdmb\cyberlink\lib\arm\LibPADParser.a
    CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibDemuxInterface.a
    CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibDLSParser.a
	CUS_REL_OBJ_LIST += vendor\tdmb\cyberlink\lib\arm\LibPADParser.a	
    CUS_REL_BASE_COMP += vendor\tdmb\cyberlink
  endif
  ifeq ($(strip $(TDMB_SUPPORT)),TELECHIP_TDMB)
      COM_DEFS    += TELECHIP_TDMB
  endif
endif

ifdef ISO_PRIORITY_MODE_SUPPORT
   ifeq ($(strip $(ISO_PRIORITY_MODE_SUPPORT)),TRUE)      
      COM_DEFS    += ISO_PRIORITY_SUPPORT 
   endif       
endif 

ifneq ($(strip $(BOARD_VER)),Y200_DEMO_BB)
  COM_DEFS    += __IP_NUMBER__
endif

ifdef KEYPAD_TYPE
   ifeq ($(strip $(KEYPAD_TYPE)),NORMAL_KEYPAD)      
      COM_DEFS    += NORMAL_KEYPAD 
   endif       
   ifeq ($(strip $(KEYPAD_TYPE)),REDUCED_KEYPAD)      
      COM_DEFS    += REDUCED_KEYPAD 
   endif          
endif 

ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    ifeq ($(strip $(APP_STORAGE_IN_SYS_DRV)),TRUE) 
  		$(error Please switch APP_STORAGE_IN_SYS_DRV to FALSE when NAND_SUPPORT is TRUE)
  	endif
  endif
endif

ifdef FLASHLIGHT_TYPE
  ifneq ($(strip $(FLASHLIGHT_TYPE)),NONE)
    ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_ONOFF_SUPPORT)      
       COM_DEFS    += LED_ONOFF_SUPPORT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),LED_FLASHLIGHT_SUPPORT)      
       COM_DEFS    += LED_FLASHLIGHT_SUPPORT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT)      
       COM_DEFS    += XENON_FLASHLIGHT 
    endif          
    ifeq ($(strip $(FLASHLIGHT_TYPE)),XENON_FLASHLIGHT_ANTI_RED_EYE)      
       COM_DEFS    += XENON_FLASHLIGHT_ANTI_RED_EYE 
    endif            
  endif
endif


#ifdef LANGLN_ENGINE
#   ifeq ($(strip $(LANGLN_ENGINE)),LANGLN_DIGIDEA)   
#      COM_DEFS    += LANGLN_DIGIDEA         
#   endif
#endif

ifdef UCM_SUPPORT
  ifeq ($(strip $(UCM_SUPPORT)),TRUE)
    ifeq ($(strip $(VOIP_SUPPORT)),TRUE)
      $(error Please either turn off VOIP_SUPPORT or turn off UCM_SUPPORT)
    else
      COM_DEFS    += __UCM_SUPPORT__
    endif
  endif
endif

ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6238)
      COM_DEFS    += __ARM9_MMU__
  endif
endif

ifdef GIS_SUPPORT
  ifneq ($(strip $(GIS_SUPPORT)),NONE)
    COMPLIST    += gis
    COM_DEFS    += GIS_SUPPORT
    ifeq ($(strip $(GIS_SUPPORT)),SUNAVI)
       COM_DEFS    += GIS_SUNAVI
    endif
    
    ifeq ($(strip $(GIS_SUPPORT)),MAPBAR)
       COM_DEFS    += GIS_MAPBAR
    endif    
  endif
endif


ifdef LANGLN_ENGINE
  ifneq ($(strip $(LANGLN_ENGINE)),NONE)
    COM_DEFS += $(LANGLN_ENGINE)
    COM_DEFS += LANGLN_ENABLE
    COMPLIST += langln
    CUS_REL_SRC_COMP += langln
    
    ifeq ($(strip $(LANGLN_ENGINE)),LANGLN_DIGIDEA)
      COMPOBJS            += vendor\langlearn\digidea\engine_01\dzdarm.a
      CUS_REL_OBJ_LIST    += vendor\langlearn\digidea\engine_01\dzdarm.a
      CUS_REL_OBJ_LIST    += vendor\langlearn\digidea\engine_01\dzdpc.lib
      COMMINCDIRS         += vendor\langlearn\digidea\adaptation\inc
      CUSTOM_COMMINC      += vendor\langlearn\digidea\adaptation\inc
    endif
  endif
endif


ifdef WIFI_SUPPORT
  ifneq ($(strip $(WIFI_SUPPORT)),NONE)
    ifndef SSL_SUPPORT
     $(error Please define SSL_SUPPORT!)
    endif
    ifeq ($(strip $(SSL_SUPPORT)),NONE)
       $(error Please set WIFI_SUPPORT as NONE or turn on SSL_SUPPORT!)
    endif
  endif
endif  

ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),MTK_SSL_CIC)
     COMPLIST        += sb51 sbpki2 sslplus5 sslplus5adp 
  endif   
endif


ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
     COMPOBJS         += vendor_sec\security\certicom\v1_official\sslplus5.lib
     CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sslplus5.lib
     COMPOBJS         += vendor_sec\security\certicom\v1_official\sb51.lib
     CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sb51.lib
     COMPOBJS         += vendor_sec\security\certicom\v1_official\sbpki2.lib
     CUS_REL_OBJ_LIST += vendor_sec\security\certicom\v1_official\sbpki2.lib
     COMPLIST         += sslplus5adp
     CUS_REL_SRC_COMP += sslplus5adp
  endif
endif


ifeq ($(strip $(PLATFORM)),MT6223)
    COM_DEFS += __HO_IMPROVE__
endif

ifdef WIFI_SUPPORT
   ifneq ($(strip $(WIFI_SUPPORT)),NONE)
      COM_DEFS += __WIFI_CHIP_DYM_POWERON__
   endif
endif

ifdef CHIP_VERSION_CHECK
   ifeq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
      COM_DEFS += __CHIP_VERSION_CHECK__
   endif
else
   $(error The feature CHIP_VERSION_CHECK should be defined as TRUE or FALSE)
endif

ifdef PURE_AUDIO_SUPPORT
   ifeq ($(strip $(PURE_AUDIO_SUPPORT)),TRUE)
      COM_DEFS    += PURE_AUDIO_SUPPORT
   endif
endif

ifdef BACKGROUND_SMS_SUPPORT
  ifeq ($(strip $(BACKGROUND_SMS_SUPPORT)),TRUE)
    COM_DEFS    +=  __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
  endif
endif 

ifneq ($(strip $(call Upper,$(PROJECT))),UMTS)
   COM_DEFS    +=  RATCM_NOT_PRESENT  RATDM_NOT_PRESENT 
endif


ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
   COM_DEFS    +=  __GSM_RAT__ 
endif

ifdef GPS_SUPPORT
  ifneq ($(strip $(GPS_SUPPORT)),NONE)
    COM_DEFS    += GPS_SUPPORT
    COMPLIST    += gps 
    CUS_REL_SRC_COMP  += gps
    CUS_REL_BASE_COMP += gps

    ifeq ($(strip $(GPS_SUPPORT)),MT3318)
       COM_DEFS    += GPS_MT3318
    endif
  endif
endif

ifdef AUDIO_3D_SURROUND
  ifneq ($(strip $(AUDIO_3D_SURROUND)),NONE)
    ifeq ($(strip $(AUDIO_3D_SURROUND)),MODE_LSPK)
      COM_DEFS += AUD_3D_SURROUND_LSPK
    endif
    ifeq ($(strip $(AUDIO_3D_SURROUND)),MODE_EARP)
      COM_DEFS += AUD_3D_SURROUND_EARP
    endif
    ifeq ($(strip $(AUDIO_3D_SURROUND)),MODE_BOTH)
      COM_DEFS += AUD_3D_SURROUND_LSPK AUD_3D_SURROUND_EARP
    endif
  endif
endif

#ifdef WBXML_SUPPORT
#  ifeq ($(strip $(WBXML_SUPPORT)),TRUE)
#	  ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
#      COM_DEFS    += WBXML_SUPPORT
#      COMPLIST    += wbxmlp
#      CUS_REL_SRC_COMP    += wbxmlp
#	  endif
#	  ifeq ($(strip $(call Upper,$(PROJECT))),UMTS)
#      COM_DEFS    += WBXML_SUPPORT
#      COMPLIST    += wbxmlp
#      CUS_REL_SRC_COMP    += wbxmlp
#	  endif  
#  endif
#endif

# end of COM_DEFS

# EMI latency setting, MPLLDISABLED, MPLLXHALF, MPLLX1, MPLLX2, MPLLX3, MPLLX4
MPLL_SETTING_FOR_MT6205_EXT_13M_MCU_13M   = MPLLDISABLED
MPLL_SETTING_FOR_MT6205B_EXT_13M_MCU_13M  = MPLLDISABLED
MPLL_SETTING_FOR_MT6205B_EXT_26M_MCU_13M  = MPLLXHALF
MPLL_SETTING_FOR_MT6205B_EXT_26M_MCU_26M  = MPLLDISABLED
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_13M   = MPLLX1
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_26M   = MPLLX2
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_39M   = MPLLX3
MPLL_SETTING_FOR_MT6208_EXT_13M_MCU_52M   = MPLLX4
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_13M   = MPLLX1
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_26M   = MPLLX2
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_39M   = MPLLX3
MPLL_SETTING_FOR_MT6218_EXT_13M_MCU_52M   = MPLLX4
MPLL_SETTING_FOR_MT6218_EXT_26M_MCU_26M   = MPLLX1
MPLL_SETTING_FOR_MT6218_EXT_26M_MCU_52M   = MPLLX2
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6218B_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6218B_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6218B_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6219_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6219_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6219_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6217_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6217_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6217_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6228_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6228_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6229_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6229_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6238_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_104M  = MPLLX4
MPLL_SETTING_FOR_MT6238_EXT_26M_MCU_208M  = MPLLX4

MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6230_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6230_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226M_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226M_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226M_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6226D_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6226D_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6226D_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6227_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6227_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6227_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6227D_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6227D_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6227D_EXT_26M_MCU_52M  = MPLLX2

MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6225_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6225_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6223_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6223_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_13M  = MPLLX1
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_26M  = MPLLX2
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_39M  = MPLLX3
MPLL_SETTING_FOR_MT6223P_EXT_13M_MCU_52M  = MPLLX4
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_26M  = MPLLX1
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_52M  = MPLLX2
MPLL_SETTING_FOR_MT6223P_EXT_26M_MCU_104M  = MPLLX4

MPLL_SETTING_FOR =  MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK))
ifdef $(MPLL_SETTING_FOR)
   MPLL_SETTING      =  $(MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK)))
#   $(error [$(MPLL_SETTING)])
else
   $(error MCU Clock and External Clock setting cannot be supported.)
endif


COM_DEFS    += $(MCU_CLOCK) $(EXT_CLOCK) $(MPLL_SETTING)

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
   COM_DEFS    += DCM_ENABLE
endif

ifdef SF_MP4_SUPPORT
  ifeq ($(strip $(SF_MP4_SUPPORT)),TRUE)
  	COMPLIST += sfmp4
  	CUS_REL_SRC_COMP += sfmp4
  	CUSTOM_COMMINC  +=	plutommi\mtkapp\sfmp4\include
	COM_DEFS    += __SF_MP4_SUPPORT__
    ifeq ($(strip $(MAIN_LCD_SIZE)),176x220)
        COMPOBJS += plutommi\mtkapp\sfmp4\lib\libsfcodec_QCIF.lib
	COMPOBJS += plutommi\mtkapp\sfmp4\lib\sfapi_mtk_QCIF.lib
	CUS_REL_OBJ_LIST    += plutommi\mtkapp\sfmp4\lib\libsfcodec_QCIF.lib
	CUS_REL_OBJ_LIST    += plutommi\mtkapp\sfmp4\lib\sfapi_mtk_QCIF.lib
    else
        COMPOBJS += plutommi\mtkapp\sfmp4\lib\libsfcodec_QVGA.lib
	COMPOBJS += plutommi\mtkapp\sfmp4\lib\sfapi_mtk_QVGA.lib
	CUS_REL_OBJ_LIST    += plutommi\mtkapp\sfmp4\lib\libsfcodec_QVGA.lib
	CUS_REL_OBJ_LIST    += plutommi\mtkapp\sfmp4\lib\sfapi_mtk_QVGA.lib	
    endif
  endif
endif  	

############################################
ifeq ($(strip $(SDEC_SUPPORT)),TRUE)
COMPLIST += sfapi
COMPOBJS += plutommi\mmi\sfapi\lib\sfapi_mtk_any.lib
COMPOBJS += plutommi\mmi\sfapi\lib\libsfcodec.lib
CUSTOM_OPTION += __SF_MP4_SUPPORT__
endif


############ Huyanwei Modify It For Thai##############
ifdef HAND_WRITING
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
      ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
        $(error For customer project, please set HAND_WRITING = MMI_HANWANG_DEMO, not set HAND_WRITING = MMI_HANWANG)
      endif
      ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
        $(error For customer project, please set HAND_WRITING = MMI_PENPOWER_DEMO, not set HAND_WRITING = MMI_PENPOWER)
      endif
    endif
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
    COM_DEFS    += __MMI_HANWANG__
    COMPLIST    += hanwang
    CUS_REL_SRC_COMP += hanwang
    COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\hw.a
    ifdef NOKE_HANDWRITE_THAI
       ifeq ($(strip $(NOKE_HANDWRITE_THAI)),TRUE)
       COMPOBJS    += vendor\handwriting\hanwang\v1_official\lib\thaihw.a    
       CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\thaihw.a    
       endif
    endif    
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hw.dll
    CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_official\lib\hws.lib
    CUSTOM_COMMINC  +=	vendor\handwriting\hanwang\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG_DEMO)
	COM_DEFS    += __MMI_HANWANG__
	COMPLIST    += hanwang
	CUS_REL_SRC_COMP += hanwang
	COMPOBJS    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
	CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.a
	CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.lib
	CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hw.dll
	CUS_REL_OBJ_LIST    += vendor\handwriting\hanwang\v1_demo\lib\hws.lib
	CUSTOM_COMMINC  +=	vendor\handwriting\hanwang\v1_demo\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
    COM_DEFS    += __MMI_PENPOWER__
    COMPLIST    += penpower
    CUS_REL_SRC_COMP += penpower
    COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\Thumb_MediaTek_HWRE.a
    COMPOBJS    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhase_thumb.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\Thumb_MediaTek_HWRE.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhase_thumb.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MediaTek_HWRE.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\penpower\v1_official\lib\MTK_PPhrase_WIN.lib
    CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_official\inc\hw_data_big5gb2312_vc6.h
    CUSTOM_COMMINC  +=	vendor\handwriting\penpower\v1_official\inc
  endif
  ifeq ($(strip $(HAND_WRITING)),MMI_DECUMA)
    COM_DEFS    += __MMI_DECUMA__
    COMPLIST    += decuma
    CUS_REL_SRC_COMP += decuma
    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib.a
    COMPOBJS    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib.a
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\scrlib_MODIS.lib
    CUS_REL_OBJ_LIST    += vendor\handwriting\Zi_decuma\v1_official\lib\dltlib_MODIS.lib
    CUSTOM_COMMINC  +=	vendor\handwriting\Zi_decuma\v1_official\inc
  endif
  ifdef TOUCH_PANEL_SUPPORT
    ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
      ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER_DEMO)
        COM_DEFS    += __MMI_PENPOWER__
        COMPLIST         += penpower
        CUS_REL_SRC_COMP += penpower
        COMPOBJS    += vendor\handwriting\penpower\v1_demo\lib\Thumb_MediaTek_HWRE_demo.a
        CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\Thumb_MediaTek_HWRE_demo.a
        CUS_REL_OBJ_LIST  +=   vendor\handwriting\penpower\v1_demo\lib\MediaTek_Hwre_demo.lib
        CUS_REL_FILES_LIST  += vendor\handwriting\penpower\v1_demo\inc\hw_data_big5gb2312_vc6.h
        COMMINCDIRS  +=	vendor\handwriting\penpower\v1_demo\inc
      endif
    endif
  endif
endif

ifndef MCUROM_SUPPORT
  MCUROM_SUPPORT = FALSE
endif


ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
ifeq ($(strip $(PLATFORM)),MT6226)
   ifeq ($(strip $(CHIP_VER)),S02)
      $(error platfrom $(strip $(PLATFORM))Chip version $(strip $(CHIP_VER)) not support MCUROM_SUPPORT.)
   endif

   MAUI_IN_ROM       = TRUE
   COMPLIST         += rompatch romsa
   CUS_REL_MTK_COMP += rompatch romsa
   CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
   CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
   COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
   COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
else
   ifeq ($(strip $(PLATFORM)),MT6227)
      MAUI_IN_ROM       = TRUE
      COMPLIST         += rompatch romsa
      CUS_REL_MTK_COMP += rompatch romsa
      CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
      CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
      COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
      COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
   else
      ifeq ($(strip $(PLATFORM)),MT6227D)
         MAUI_IN_ROM       = TRUE
         COMPLIST         += rompatch romsa
         CUS_REL_MTK_COMP += rompatch romsa
         CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
         CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
         COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
         COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
      else
         ifeq ($(strip $(PLATFORM)),MT6226M)
            MAUI_IN_ROM       = TRUE
            COMPLIST         += rompatch romsa
            CUS_REL_MTK_COMP += rompatch romsa
            CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
            CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
            COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
            COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
         else
            ifeq ($(strip $(PLATFORM)),MT6226D)
               MAUI_IN_ROM       = TRUE
               COMPLIST         += rompatch romsa
               CUS_REL_MTK_COMP += rompatch romsa
               CUS_REL_OBJ_LIST += rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
               CUS_REL_BASE_COMP += romsa\include ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include
               COM_DEFS         += __ROMSA_SUPPORT__ __ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER))__
               COMMINCDIRS      += ROM\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\include romsa\include
            else
               $(error Chip version $(strip $(PLATFORM)) not support MCUROM_SUPPORT.)
            endif
         endif
      endif
   endif
endif
else
   MAUI_IN_ROM       = FALSE
endif
endif

ifdef FM_RADIO_CHIP
  ifneq ($(strip $(FM_RADIO_CHIP)),NONE)
     COMPLIST         += fm_drv
     CUS_REL_PAR_SRC_COMP += fm_drv
     CUS_REL_FM_DRV_PAR_SRC_LIST = fm_drv\MT6189A1_drv.c \
                                  fm_drv\$(strip $(FM_RADIO_CHIP))_drv.c
  endif
endif

ifdef XDM_SUPPORT
  ifneq ($(strip $(XDM_SUPPORT)),FALSE)
    COMPLIST         += xdm
    # MMI package
    CUS_REL_MTK_COMP += xdm

    # Protocol package
    # CUS_REL_SRC_COMP += xdm
  endif
endif

ifdef J2ME_JSR184_SUPPORT
   ifneq ($(strip $(J2ME_JSR184_SUPPORT)),NONE)
      COMPLIST    += m3d m3g
      CUS_REL_MTK_COMP += m3d m3g
   endif
endif

ifdef M3D_MMI_SUPPORT
ifneq ($(strip $(M3D_MMI_SUPPORT)),FALSE)
   ifeq ($(strip $(J2ME_JSR184_SUPPORT)),NONE)
      COMPLIST    += m3d
      CUS_REL_MTK_COMP += m3d
   endif
endif
endif

ifdef DICT_SUPPORT
  ifeq ($(strip $(DICT_SUPPORT)),MMI_GV)
    COM_DEFS    += __MMI_DICT_GV__
    COMPLIST    += dict
    COMPOBJS  	+= vendor\dict\gv\v01_demo\gvlib_targer_rom.lib
    CUS_REL_OBJ_LIST   	+= vendor\dict\gv\v01_demo\gvlib_targer_rom.lib
  endif
  ifeq ($(strip $(DICT_SUPPORT)),MMI_MOTECH)
    COM_DEFS    += __MMI_DICT_MOTECH__
    COMPLIST    += dict
    COMPOBJS  	+= vendor\dict\motech\v01_demo\tccDict.a
    CUS_REL_OBJ_LIST   	+= vendor\dict\motech\v01_demo\tccDict.a
  endif
  ifeq ($(strip $(DICT_SUPPORT)),MMI_TRILOGY)
    COM_DEFS    += __MMI_DICT_TRILOGY__
    COMPLIST    += dict
    COMPOBJS  	+= vendor\dict\trilogy\v01_demo\Dict_core.obj
    COMPOBJS  	+= vendor\dict\trilogy\v01_demo\bg5_uni.obj
    CUS_REL_OBJ_LIST   	+= vendor\dict\trilogy\v01_demo\Dict_core.obj
    CUS_REL_OBJ_LIST   	+= vendor\dict\trilogy\v01_demo\bg5_uni.obj
  endif
endif

ifdef BLUETOOTH_SUPPORT
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
    ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
      $(error Please turn off MERCURY_SLAVE_BT_SUPPORT when BLUETOOTH_SUPPORT is turned off)
    endif
  endif
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
	  COMPLIST          += btadp btprofiles btstack
  endif
  ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
    COMPLIST          += btadp btprofiles btstack
  endif   
endif

ifdef MERCURY_SLAVE_BT_SUPPORT
  ifeq ($(strip $(MERCURY_SLAVE_BT_SUPPORT)),TRUE)
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),NONE)
      $(error Please turn off MERCURY_SLAVE_BT_SUPPORT or turn on BLUETOOTH_SUPPORT!)
    endif
  endif
endif

#ifdef SW_FLASH
#  ifneq ($(strip $(SW_FLASH)),NONE)
#    COMPOBJS            += vendor\swflash\$(strip $(SW_FLASH))\v1_official\mtk_ADS1.2_Cim2Lib.a
#    CUS_REL_OBJ_LIST   	+= vendor\swflash\$(strip $(SW_FLASH))\v1_official\mtk_ADS1.2_Cim2Lib.a
#    CUS_REL_OBJ_LIST   	+= vendor\swflash\$(strip $(SW_FLASH))\v1_official\mtk_WIN32_Cim2Lib.lib
#    COMMINCDIRS         += vendor\swflash\$(strip $(SW_FLASH))\adaptation\inc
#    COM_DEFS         += SWFLASH_$(strip $(SW_FLASH))
#    COMPLIST         += swflash
#  endif
#endif

ifdef SW_FLASH
  ifeq ($(strip $(SW_FLASH)),NEOMTEL)    
    COMPOBJS          += vendor\swflash\$(strip $(SW_FLASH))\v1_official\VIS20_ARM12_IRAM_12K_MTK.a
    COMPOBJS            += vendor\swflash\$(strip $(SW_FLASH))\v1_official\zddlib_mtk-ADS.a
    CUS_REL_OBJ_LIST   	+= vendor\swflash\$(strip $(SW_FLASH))\v1_official\VIS20_ARM12_MTK.a
    CUS_REL_OBJ_LIST   	+= vendor\swflash\$(strip $(SW_FLASH))\v1_official\VIS20_WIN32_MTK.lib
    CUS_REL_OBJ_LIST   	+= vendor\swflash\$(strip $(SW_FLASH))\v1_official\zddlib_mtk-ADS.a
    CUS_REL_OBJ_LIST   	+= vendor\swflash\$(strip $(SW_FLASH))\v1_official\zdd2_1_lib.lib
    COMMINCDIRS         += vendor\swflash\$(strip $(SW_FLASH))\adaptation\inc
    COM_DEFS         += SWFLASH_$(strip $(SW_FLASH))
    COMPLIST         += swflash
  endif
endif



COMPLIST    += che image_codec
CUS_REL_MTK_COMP  += che image_codec


ifeq ($(strip $(PLATFORM)),MT6223P)
   COMPLIST       +=  drv_sec
endif


# end of COMPLIST


ifndef MMI_BASE
	MMI_BASE = PLUTO_MMI
	MMIDIR   = plutommi
else
	ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
		MMIDIR         =  lcmmi
	else
		MMIDIR         =  plutommi
	endif
endif

MMI_BASE_PRJ = $(strip $(subst _MMI,,$(MMI_BASE)))

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)

INPUT_METHOD_BASE = $(strip $(MMIDIR))
ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
  ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
endif

ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
  ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  ifneq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
    INPUT_METHOD_BASE := $(strip $(call Upper,$(CUSTOMER)))
  endif
  endif
endif

ifdef FONT_RESOURCE
  ifeq ($(strip $(FONT_RESOURCE)),OFFICIAL)
    ifneq ($(strip $(MMIDIR)),lcmmi)
      CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    else
      CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc
      FONTRES_PATH_CUST = vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))\content\src
      FONTRES_PATH_MTK = vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\src
    endif
    CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(INPUT_METHOD_BASE))

    ifneq ($(strip $(INPUT_METHOD_BASE)),$(strip $(MMI_BASE_PRJ)))
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\MTK\official\project\$(strip $(MMIDIR))\content\inc
      endif
      CUS_REL_BASE_COMP += vendor\font\MTK\official\project\$(strip $(MMIDIR))
    endif

    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc \
        vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))\content\inc
      endif
      CUS_REL_BASE_COMP += vendor\font\Arphic\official\project\$(strip $(INPUT_METHOD_BASE)) vendor\font\Dynacom\official\project\$(strip $(INPUT_METHOD_BASE))
    endif
  endif
endif

ifdef FONT_RESOURCE
  ifeq ($(strip $(FONT_RESOURCE)),DEMO)
    ifneq ($(strip $(MMIDIR)),lcmmi)
      CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_CUST = vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      FONTRES_PATH_MTK = vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\src\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
    else
      CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc
      CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc
      CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc
      FONTRES_PATH_CUST = vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))\content\src
      FONTRES_PATH_MTK = vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\src
    endif    
    
    CUS_REL_BASE_COMP += vendor\font\MTK\demo\project\$(strip $(INPUT_METHOD_BASE))

    ifneq ($(strip $(INPUT_METHOD_BASE)),$(strip $(MMI_BASE_PRJ)))
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\MTK\demo\project\$(strip $(MMIDIR))\content\inc
        CUSTOM_COMMINC += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))\content\inc
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))\content\inc
      endif
      CUS_REL_BASE_COMP += vendor\font\MTK\demo\project\$(strip $(MMIDIR))
      CUS_REL_BASE_COMP += vendor\font\Dynacom\demo\project\$(strip $(MMIDIR))
      CUS_REL_BASE_COMP += vendor\font\Arphic\demo\project\$(strip $(MMIDIR))
    endif

    ifeq ($(strip $(EMPTY_RESOURCE)),FALSE)
      ifneq ($(strip $(MMIDIR)),lcmmi)
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE))) \
        vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc\MainLcd$(call Upper,$(strip $(MAIN_LCD_SIZE)))
      else
        CUSTOM_COMMINC += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc \
        vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))\content\inc
      endif
      CUS_REL_BASE_COMP += vendor\font\Arphic\demo\project\$(strip $(INPUT_METHOD_BASE)) vendor\font\Dynacom\demo\project\$(strip $(INPUT_METHOD_BASE))
    endif
  endif
endif

endif
endif

ifdef INPUT_METHOD
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V6)
    CUSTOM_COMMINC  +=	vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\inc
    COMPOBJS  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
    CUS_INPUTMETHOD_BASE = vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
    CUSTOM_COMMINC  +=	vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\inc
    COMPOBJS  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\zi8clib.a
    CUS_INPUTMETHOD_BASE 	= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v6_official
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
    CUSTOM_COMMINC  +=	vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
    COMPOBJS  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\zi8clib.a
    CUS_INPUTMETHOD_BASE 	= vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE))\v7_official
  endif

# CSTAR Official version
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_official
    COMPLIST    += cstar
    COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\csk2.a
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif

# CSTAR Demo version
  ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2_DEMO)
    CUS_INPUTMETHOD_BASE = vendor\inputmethod\CStar\v2_demo
    COMPLIST    += cstar
    COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\csk2.a
    COM_DEFS    += __MMI_CSTAR__
    COM_DEFS    += __MMI_CSTAR_V2__
    CUSTOM_COMMINC += $(strip $(CUS_INPUTMETHOD_BASE))\inc
    CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    CUS_REL_SRC_COMP += cstar
  endif

  ifneq ($(findstring MMI_ZI,$(INPUT_METHOD)),)
    COM_DEFS    += __MMI_ZI__
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_ZI_V7)
      COM_DEFS    += __MMI_ZI_V7__
    endif
    COMPLIST    += zi
    CUS_REL_$(strip $(RELEASE_$(strip $(INPUT_METHOD))))_COMP += zi
    ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
    CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a /b 2>nul)
    else
    CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a /b 2>nul)
    endif
    ifeq ($(words $(strip $(CUS_ZI))),1)
      ifeq ($(strip $(INPUT_METHOD)),MMI_ZI_V7)
      COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
      CUS_REL_OBJ_LIST  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\ziShape.a
      else
      COMPOBJS  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a
      CUS_REL_OBJ_LIST  	+= $(strip $(CUS_INPUTMETHOD_BASE))\lib\zi8ARShape.a
    endif
  endif
  endif
  ifneq ($(findstring MMI_T9,$(INPUT_METHOD)),)
    COM_DEFS    += __MMI_T9__
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9_V7)
       ifeq ($(strip $(MMIDIR)),plutommi)
          COM_DEFS    += __MMI_T9_V7__
       endif
    endif
    ifeq ($(strip $(call Upper,$(INPUT_METHOD))),MMI_T9)
       ifeq ($(strip $(MMIDIR)),plutommi)
          COM_DEFS    += __MMI_T9_V7__
       endif
    endif
    COMPLIST    += t9
    CUS_REL_$(strip $(RELEASE_$(strip $(INPUT_METHOD))))_COMP += t9
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9)
    CUSTOM_COMMINC  +=	vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
    COMPOBJS  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V7)
    CUSTOM_COMMINC  +=	vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\inc
    COMPOBJS  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
    CUS_REL_OBJ_LIST  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official\lib\t9relChinese.o
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v7_official
  endif
  ifeq ($(strip $(INPUT_METHOD)),MMI_T9_V6)
    CUSTOM_COMMINC  +=	vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v6_official\inc
    COMPOBJS  	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\t9relChinese.o
    CUS_REL_OBJ_LIST 	+= vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v6_official\lib\t9relChinese.o
    CUS_INPUTMETHOD_BASE   = vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE))\v6_official
  endif
  CUS_REL_BASE_COMP   += $(strip $(CUS_INPUTMETHOD_BASE))
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifneq ($(strip $(INPUT_METHOD)),NONE)
      CUS_ZI = $(shell dir $(strip $(CUS_INPUTMETHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_ZI))),2)
        $(error $(strip $(CUS_INPUTMETHOD_BASE)) does NOT exist!)
      endif
    endif
  endif

  ifneq ($(strip $(CUS_INPUTMETHOD_BASE)),plutommi)
    ifneq ($(strip $(CUS_INPUTMETHOD_BASE)),lcmmi)
      CUS_T9 = $(shell dir vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_T9))),0)
        CUS_REL_BASE_COMP   += vendor\InputMethod\T9\project\$(strip $(INPUT_METHOD_BASE)) make\t9 vendor\InputMethod\T9\adaptation
      endif
      CUS_ZI = $(shell dir vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE)) /b 2>nul)
      ifneq ($(words $(strip $(CUS_ZI))),0)
        CUS_REL_BASE_COMP   += vendor\InputMethod\ZI\project\$(strip $(INPUT_METHOD_BASE)) make\zi vendor\InputMethod\ZI\adaptation
      endif
    endif
  endif

endif

ifdef GAME_ENGINE
  ifneq ($(strip $(GAME_ENGINE)),NONE)
    COMPLIST    += game_engine
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
    COMPOBJS  	+= vendor\game_engine\brogent\engine_v1\arm\mini_bgl.lib \
    		vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\arm\bgt_ggr2_optimize.lib \
    		vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\arm\bgt_hb2_utils.lib
    CUS_REL_OBJ_LIST  	+= vendor\game_engine\brogent\engine_v1\arm\mini_bgl.lib \
    		vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\arm\bgt_ggr2_optimize.lib \
    		vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\arm\bgt_hb2_utils.lib \
    		vendor\game_engine\brogent\engine_v1\pc\mini_bgl.lib \
    		vendor\game_engine\brogent\game\GoGoRobot2\GAME_LIB\pc\bgt_ggr2_optimize.lib \
    		vendor\game_engine\brogent\game\HeatBreaker2\GAME_LIB\pc\bgt_hb2_utils.lib
  endif
  ifeq ($(strip $(GAME_ENGINE)),GE_INTERGRAFX)
    #COMPOBJS  	+= vendor\game_engine\brogent\engine_v1\arm\ur_engine.lib
  endif
endif

ifdef JATAAYU_FEATURE
   ifeq ($(findstring WAP,$(JATAAYU_FEATURE)),WAP) # if $(JATAAYU_FEATURE) is *WAP*
       COMPLIST    += jataayu jataayuapp jdd
   endif
endif

ifdef BARCODE_DECODER
  ifneq ($(strip $(BARCODE_DECODER)),NONE)
    COMPOBJS += vendor\barcode\$(strip $(BARCODE_DECODER))\lib\DecodeLib.lib
    CUS_REL_OBJ_LIST += vendor\barcode\$(strip $(BARCODE_DECODER))\lib\DecodeLib.lib
    COMMINCDIRS += vendor\barcode\$(strip $(BARCODE_DECODER))\inc
    COM_DEFS += BARCODE_DECODER_$(strip $(BARCODE_DECODER))
    COM_DEFS += BARCODE_SUPPORT
  endif
endif


ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
      CUS_REL_BASE_COMP += custom\drv\Drv_Tool
  endif
endif


ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
    COMPLIST         +=  media_rtp applib_inet
endif
endif

ifdef WAP_SUPPORT
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q03C)
    COMPLIST    += obigo03capp obigo03cadp obigo03clib
  endif
  ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
    COMPLIST    += obigo05aadp obigo05alib wapapp
  endif
endif

ifdef SYNCML_SUPPORT
	ifneq ($(strip $(SYNCML_SUPPORT)),FALSE)
  	ifeq ($(strip $(WAP_SUPPORT)),NONE)
    	$(error Please set WAP_SUPPORT or turn off SYNCML_SUPPORT!)
  	endif  
	endif
  ifeq ($(strip $(SYNCML_SUPPORT)),TRUE)
    COM_DEFS    += __SYNCML_SUPPORT__
    COMPLIST    += syncml
  endif
endif

ifdef UNIFIED_MESSAGE_SUPPORT
ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
   ifneq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
      ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
         COMMINCDIRS	+= plutommi\MMI\UnifiedComposer\UnifiedComposerInc
      endif
   endif
endif
endif



ifdef UNIFIED_MESSAGE_SUPPORT
ifdef UNIFIED_MESSAGE_ADVANCE_FEATURE
  ifeq ($(strip $(UNIFIED_MESSAGE_SUPPORT)),FALSE)
     ifneq ($(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE)),NONE)
           $(error Please turn UNIFIED_MESSAGE_ADVANCE_FEATURE to NONE or turn on UNIFIED_MESSAGE_SUPPORT )
     endif
  else
     ifneq ($(findstring COMPOSER,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
         COM_DEFS    +=  __UNIFIED_COMPOSER_SUPPORT__
     endif
     ifneq ($(findstring LISTOPTION,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
         COM_DEFS    +=  __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
     endif
     ifneq ($(findstring ARCHIVE,$(strip $(UNIFIED_MESSAGE_ADVANCE_FEATURE))),)
         COM_DEFS    +=  __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
     endif
  endif
endif
endif


ifdef RTSP_SUPPORT
  ifeq ($(strip $(RTSP_SUPPORT)),TRUE)
    COMPLIST	+= rtsp
    COM_DEFS    += __RTSP__
  endif
endif


ifdef SYNC_LCM_SUPPORT
  ifeq ($(strip $(SYNC_LCM_SUPPORT)),SYNC_LCM_SW_SUPPORT)
     COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_SW_SUPPORT__
  endif
  ifeq ($(strip $(SYNC_LCM_SUPPORT)),SYNC_LCM_HW_SUPPORT)
     COM_DEFS    += __SYNC_LCM_SUPPORT__ __SYNC_LCM_HW_SUPPORT__
  endif
endif





ifeq ($(strip $(call Upper,$(PLATFORM))),MT6225)
   ifeq ($(strip $(call Upper,$(CHIP_VER))),S00)
      COM_DEFS    +=  MT6225_DMA_EMI_ISSUE
   endif
endif

ifdef VDOEDT_SUPPORT
  VDOEDT_SUPPORT_NOT_SUPPORT_FLATFORM = MT6205B MT6208 MT6217 MT6218B MT6219 MT6226 MT6227 MT6227D MT6226D
  ifeq ($(strip $(VDOEDT_SUPPORT)),TRUE)
    ifneq ($(strip $(MP4_CODEC)),TRUE)
      $(error Please turn on MP4_CODEC or turn off VDOEDT_SUPPORT.)
    endif
    ifneq ($(findstring $(strip $(PLATFORM)),$(VDOEDT_SUPPORT_NOT_SUPPORT_FLATFORM)),)
      $(error Chip version $(strip $(PLATFORM)) does not support VDOEDT_SUPPORT.)
    endif
  endif
  ifeq ($(strip $(VDOEDT_SUPPORT)),TRUE)
     COM_DEFS    += VDOEDT_SUPPORT
     COM_DEFS    += __VIDEO_EDITOR__
  endif
endif



#####
# COMMON SECTION used by gsm2.mak and custom_release.mak
#####
ifneq ($(findstring =$(call Upper,$(strip $(CUSTOMER)))=,=MTK=MTK_RF=PLUTO=),)
	VERNOFILE		=  make\Verno.bld

	ifdef FOTA_ENABLE
	   ifneq ($(strip $(FOTA_ENABLE)),NONE)
		SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_FOTA.txt
	   else
	       SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM)).txt
	   endif
	else
		SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM)).txt
	endif

	ifneq ($(strip $(FOTA_ENABLE)),NONE)
		SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_FOTA.txt
	endif
	ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
		SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_L1S.txt
	endif
	ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
		SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(PLATFORM))_BASIC.txt
	endif
	ifeq ($(strip $(call Upper,$(PROJECT))),GPRS)
		VERNOFILE		:=  make\Verno_ClassB.bld
	endif
	ifeq ($(strip $(call Upper,$(PROJECT))),UMTS)
		VERNOFILE		:=  make\Verno_ClassB_UMTS.bld
	endif
else
   VERNOFILE		=  make\Verno_$(CUSTOMER).bld

	ifdef FOTA_ENABLE
	   ifneq ($(strip $(FOTA_ENABLE)),NONE)
		SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_FOTA.txt
	   else
	       SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER)).txt
	   endif
	else
		SCATTERFILE		=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER)).txt
	endif

	ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
		SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_L1S.txt
	endif
	ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
		SCATTERFILE		:=	custom\system\$(strip $(BOARD_VER))\scat$(strip $(CUSTOMER))_BASIC.txt
	endif
endif

include $(strip $(VERNOFILE))
#BRANCH   +=   $(call Upper,$(strip $(CUSTOMER)))

# *************************************************************************
# Build path, directories
# *************************************************************************
FIXPATH        =  .
TARGNAME       =  $(CUSTOMER)_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
PLATLIBROOT    =  $(strip $(FIXPATH))\lib\$(strip $(PLATFORM))
TSTDIR         =  $(strip $(FIXPATH))\tst
TST_DB         =  $(strip $(TSTDIR))\database
ifeq ($(call Upper,$(PROJECT)),GPRS)
	TST_DB         :=  $(strip $(TSTDIR))\database_classb
endif
ifeq ($(call Upper,$(PROJECT)),UMTS)
	TST_DB         :=  $(strip $(TSTDIR))\database_classb_umts
endif
BUILDDIR       =  $(strip $(FIXPATH))\build
TARGDIR        =  $(strip $(BUILDDIR))\$(CUSTOMER)
PROJDIR        =  $(strip $(TARGDIR))\$(PROJECT)
BPLGUINFOCUSTOMPREFIX = BPLGUInfoCustomApp_$(strip $(PLATFORM))_$(strip $(CHIP_VER))

OBJSDIR        =  $(strip $(PROJDIR))\$(strip $(PLATFORM))o
RULESDIR       =  $(strip $(PROJDIR))\$(strip $(PLATFORM))r
COMPLIBDIR     =  $(strip $(OBJSDIR))\lib

# Move to project makefile
# Settings for operator
#ifdef MMI_BASE
#  ifeq ($(strip $(MMI_BASE)),PLUTO_MMI)
#    ifneq ($(strip $(OPTR_SPEC)),NONE)
#      OPTR_PATH = operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi
#      -include $(OPTR_PATH)\operator.mak
#    endif
#  endif
#endif

#  Settings for emigen
FLASH_OPTIONS_HDR = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\flash_opt.h
CUSTOM_EMI_H      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI.h
CUSTOM_EMI_C      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_EMI.c
SWITCH_CLK_C      = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_switchclock.c
MEMORY_DEVICE_HDR = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_MemoryDevice.h
MEMORY_DEVICE_LST = $(strip $(FIXPATH))\tools\MemoryDeviceList\MemoryDeviceList_Since07AW0736.xls
EMI_GENERATOR     = $(strip $(FIXPATH))\tools\emiGenV4.pl


#hongzhe.liu add for custom_MemoryDevice.h auto generation
MEMORY_DEVICE_HDR_GENERATOR = $(strip $(FIXPATH))\tools\memGen.pl
MEMORY_DEVICE_TYPE = $(strip $(NOKE_MEMORY_DEVICE_TYPE))
MEMORY_DEVICE_ID = $(strip $(NOKE_FLASHTYPE))



FLASHFILE = $(strip $(CUSTOM_EMI_H))
MEMORY_CFG = $(strip $(MEMORY_DEVICE_HDR))

ifdef NAND_FLASH_BOOTING
  ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
    ifneq (,$(findstring $(strip $(PLATFORM)), $(strip $(NAND_FLASH_BOOTING_SUPPORT_PLATFORM))))
	   FLASHFILE := $(strip $(MEMORY_DEVICE_HDR))
	   MEMORY_CFG := $(strip $(CUSTOM_EMI_H))
    endif
  endif
endif

ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
  ifeq ($(strip $(MMIDIR)),plutommi)
    CUS_REL_MTK_COMP := $(subst vendorapp,,$(COMPLIST))
    CUS_REL_MTK_COMP := $(subst verno,,$(CUS_REL_MTK_COMP))
    CUS_REL_MTK_COMP := $(subst init,,$(CUS_REL_MTK_COMP))
    CUS_REL_SRC_COMP := vendorapp verno
    CUS_REL_PAR_SRC_COMP := init
    CUS_REL_INIT_PAR_SRC_LIST = init\src\init.c
    CUS_REL_FILES_LIST := 
    CUS_REL_HDR_COMP :=
    CUS_REL_BASE_COMP := tools plutommi\VendorApp
    ifdef MTK_SUBSIDIARY
      ifneq ($(strip $(MTK_SUBSIDIARY)),FALSE)
        ifdef J2ME_SUPPORT
          ifneq ($(strip $(J2ME_SUPPORT)),NONE)
            CUS_REL_BASE_COMP += j2me custom\j2me      
          endif
        endif
      else
        CUS_REL_BASE_COMP += j2me custom\j2me 
      endif
    else
      CUS_REL_BASE_COMP += j2me custom\j2me
    endif
    ifneq ($(strip $(CUS_INPUTMETHOD_BASE)),)
      CUS_REL_BASE_COMP += $(strip $(CUS_INPUTMETHOD_BASE))\lib
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
      CUS_REL_FILES_LIST := plutommi\Customer\CustResource\CustENFBImgData
      CUS_REL_FILES_LIST += plutommi\Customer\CustResource\CustENFBStrData
    endif
  endif
endif

# COMPLIST(during CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
   COMPLIST =     $(strip $(CUS_REL_SRC_COMP))
   COMPLIST +=    $(strip $(CUS_REL_PAR_SRC_COMP))

   ifeq ($(strip $(call Upper,$(PROJECT))),GSM)
	ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
   	COMPLIST :=  	$(subst plutommi,,$(COMPLIST))
		COMPLIST :=  	$(subst mmiresource,,$(COMPLIST))
		COMPLIST :=  	$(subst lc ,lcmmiresource ,$(COMPLIST))
		COMPLIST :=  	$(subst mtkapp,,$(COMPLIST))
		COMPLIST :=  	$(subst lc ,lcmtkapp ,$(COMPLIST))
	else
	ifeq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
   	COMPLIST :=  	$(subst plutommi,,$(COMPLIST))
		COMPLIST :=  	$(subst mmiresource,,$(COMPLIST))
		COMPLIST :=  	$(subst lc ,lcmmiresource ,$(COMPLIST))
		COMPLIST :=  	$(subst mtkapp,,$(COMPLIST))
		COMPLIST :=  	$(subst lc ,lcmtkapp ,$(COMPLIST))
	else
   	COMPLIST :=  	$(subst lcmmi,,$(COMPLIST))
		COMPLIST :=  	$(subst lcmmiresource,,$(COMPLIST))
		COMPLIST :=  	$(subst lcmtkapp,,$(COMPLIST))
	endif
	endif
   endif
endif

ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
ifdef OPTR_SPEC
ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
ifneq ($(strip $(OPTR_SPEC)),NONE)
CUS_REL_BASE_COMP += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC)))\$(word 2,$(subst _, ,$(OPTR_SPEC))))\$(strip $(MMIDIR))
CUS_REL_BASE_COMP += operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\common\$(strip $(MMIDIR))
THE_OP_CUSTOM_LIS = $(OPTR_PATH)\op_custom.lis
endif
else
CUS_REL_BASE_COMP += operator
THE_OP_CUSTOM_LIS = $(OPTR_PATH)\op_custom.lis
endif
endif
endif

ifeq ($(strip $(MTK_NO_LSK)),TRUE)
COM_DEFS += NO_LSK
endif

