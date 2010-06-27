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
# *************************************************************************
#
#   		MediaTek Inc GSM/GPRS Wireless Communicatin Project
#					Build/Make Development Tools
#
#			Author			Date			Description
#			Sherman Wang 	2004/04/29		Create version 1.0
#
# *************************************************************************
# COMP.MAK  - Component build script
#
#  DISCUSSION:
#
#     This file is build script for component modules, and contains C source
#  files (.c), and Assembly source files(.s).
#
#  USAGE:
#
#  IMPORTANT NOTES:
#
# *************************************************************************
#
# $Revision:$
# $Modtime:$
# $Log:$
# *************************************************************************
# *************************************************************************
# Project Variables
# *************************************************************************
include make\~compbld.tmp            # Temporary build script created by gsm2.mak
include make\ALIAS.mak

# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .obj .c .s .cpp .arm

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : update_lib


# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))


# *************************************************************************
# Set Shell
# *************************************************************************
#SHELL = $(ComSpec)

# *************************************************************************
# Construct $(COMPONENT) specific varible
# *************************************************************************
TARGLIB       =  $(subst \,/,$(OBJSDIR))/lib/$(COMPONENT).lib
COMPOBJS_DIR  =  $(subst \,/,$(OBJSDIR))/$(COMPONENT)

ifdef $($(COMPONENT))
COMPBUILD_DIR =  $(FIXPATH)\make\$(strip $($(COMPONENT)))\$(COMPONENT)
COMPPARENT_DIR = $(FIXPATH)\make\$(strip $($(COMPONENT)))
else
COMPBUILD_DIR =  $(FIXPATH)\make\$(COMPONENT)
endif

ifdef DUAL_MODE_SUPPORT
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),MASTER)
    ifeq ($(strip $(MASTER)), TRUE)
      COMPBUILD_DIR =  $(FIXPATH)\make\$(COMPONENT)\master
    endif
  endif
  ifeq ($(strip $(DUAL_MODE_SUPPORT)),SLAVE)
    ifeq ($(strip $(SLAVE)), TRUE)
      COMPBUILD_DIR =  $(FIXPATH)\make\$(COMPONENT)\slave
    endif
  endif
endif

# *************************************************************************
# Construct the list of object dependencies
# *************************************************************************
SRC_LIST	=  $(subst .S,.s,$(subst .C,.c,$(shell type $(COMPBUILD_DIR)\$(COMPONENT).lis)))
CPPSRC_LIST	=  $(subst .S,.s,$(subst .CPP,.cpp,$(shell type $(COMPBUILD_DIR)\$(COMPONENT).lis)))
CSRCS       =  $(filter %.c, $(SRC_LIST))
CPPSRCS     =  $(filter %.cpp, $(CPPSRC_LIST))
ASRCS       =  $(filter %.s, $(SRC_LIST))
ARMSRCS     =  $(filter %.arm, $(SRC_LIST))
COBJS       =  $(patsubst %.c,%.obj, $(notdir $(subst \,/,$(CSRCS))))
CPPOBJS     =  $(patsubst %.cpp,%.obj, $(notdir $(subst \,/,$(CPPSRCS))))
AOBJS       =  $(patsubst %.s,%.obj, $(notdir $(subst \,/,$(ASRCS))))
ARMOBJS     =  $(patsubst %.arm,%.obj, $(notdir $(subst \,/,$(ARMSRCS))))

INCDIRS		+= $(shell type $(COMPBUILD_DIR)\$(COMPONENT).inc)

ifdef $($(COMPONENT))
COMP_DEFS	=  $(shell type $(COMPPARENT_DIR)\$(strip $($(COMPONENT))).def)
else
COMP_DEFS	=  $(shell type $(COMPBUILD_DIR)\$(COMPONENT).def)
endif

DEFINES		+= $(COMP_DEFS)
SRCPATH		=  $(shell type $(COMPBUILD_DIR)\$(COMPONENT).pth)
ifneq ($(strip $(FOTA_ENABLE)),NONE)
 	ifeq ($(strip $(COMPONENT)),fota)
		SRCPATH       += custom\system\$(strip $(BOARD_VER)) custom\drv\LCD\$(strip $(LCD_MODULE)) \
		  custom\drv\misc_drv\$(strip $(BOARD_VER)) custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen
	endif
endif

CINCDIRS 	=  $(foreach inc, $(subst \,/,$(INCDIRS)),-I$(inc))
CDEFS 		=  $(foreach def, $(DEFINES),-D$(def))

# if LCMMI is applied
ifeq ($(MMIDIR),lcmmi)
   INCDIRS  :=  $(subst PLUTOMMI,lcmmi,$(call Upper,$(INCDIRS)))
#   $(warning Include paths of $(COMPONENT) are $(INCDIRS))
endif

ifndef RVCT_MULTI_FILE
   RVCT_MULTI_FILE = NONE
endif

# *************************************************************************
# Set View Path
# *************************************************************************
vpath
vpath %.s   $(subst \,/,$(SRCPATH))
vpath %.arm   $(subst \,/,$(SRCPATH))
vpath %.c   $(subst \,/,$(SRCPATH))
vpath %.cpp   $(subst \,/,$(SRCPATH))
vpath %.h   $(subst \,/,$(INCDIRS))
vpath %.dat $(subst \,/,$(INCDIRS))
vpath %.obj $(COMPOBJS_DIR)

# XXX!!! To use predefine for assembler is a little difficult and
# usually can be replaced with C sources.
ifneq ($(COMPONENT),ijet_adp)
ADEFS       = $(foreach def, $(COMP_DEFS),-pd "$(def) SETL {TRUE}")
else
ADEFS       = 
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6205B)
 	ifeq ($(COMPONENT),init)
		ADEFS       += -pd "MT6205B SETL {TRUE}"
	endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6218)
 	ifeq ($(COMPONENT),init)
		ADEFS       += -pd "MT6218 SETL {TRUE}"
	endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6218B)
 	ifeq ($(COMPONENT),init)
		ADEFS       += -pd "MT6218B SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
	endif
 	ifeq ($(COMPONENT),custom)
		CFLAGS += -DREMAPPING
	endif
endif


ifeq ($(call Upper,$(strip $(PLATFORM))),MT6217)
 	ifeq ($(COMPONENT),init)
		ADEFS       += -pd "MT6217 SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
	endif
 	ifeq ($(COMPONENT),custom)
		CFLAGS += -DREMAPPING
	endif
endif


ifeq ($(call Upper,$(strip $(PLATFORM))),MT6219)
 	ifeq ($(COMPONENT),init)
		ADEFS       += -pd "MT6219 SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
	endif
 	ifeq ($(COMPONENT),custom)
		CFLAGS += -DREMAPPING
	endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6238)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6238 SETL {TRUE}" 
      ADEFS       += -pd "ARM9_MMU SETL {TRUE}" 
      ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
         ADEFS       += -pd "_NAND_FLASH_BOOTING_ SETL {TRUE}"
      endif
      ifdef FOTA_ENABLE
      ifneq ($(strip $(FOTA_ENABLE)),NONE)
      ifneq ($(strip $(FOTA_ENABLE)),)
         ADEFS       += -pd "REMAPPING SETL {TRUE}" -pd "__FOTA_ENABLE__ SETL {TRUE}"  
         CFLAGS += -DREMAPPING
      endif
      endif
      endif
   endif
   ifeq ($(COMPONENT),fota)
      ADEFS       += -pd "MT6238 SETL {TRUE}"
   endif
   ifeq ($(COMPONENT),custom)
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
        ifneq ($(strip $(FOTA_ENABLE)),)
           CFLAGS += -DREMAPPING
        endif
        endif
      endif
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6225)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6225 SETL {TRUE}"
      ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
         ADEFS       += -pd "__ROMSA_SUPPORT__ SETL {TRUE}"
      endif
      ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
         ADEFS       += -pd "_NAND_FLASH_BOOTING_ SETL {TRUE}"
      endif      
      ifdef FOTA_ENABLE
      ifneq ($(strip $(FOTA_ENABLE)),NONE)
      ifneq ($(strip $(FOTA_ENABLE)),)
         ADEFS       += -pd "REMAPPING SETL {TRUE}" -pd "__FOTA_ENABLE__ SETL {TRUE}"  
         CFLAGS += -DREMAPPING
      endif
      endif
      endif
      ifeq ($(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT),TRUE)
         ADEFS       += -pd "REMAPPING SETL {TRUE}"  
      endif
   endif
   ifeq ($(COMPONENT),fota)
      ADEFS       += -pd "MT6225 SETL {TRUE}"
   endif
   ifeq ($(COMPONENT),custom)
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
        ifneq ($(strip $(FOTA_ENABLE)),)
           CFLAGS += -DREMAPPING
        endif
        endif
      endif
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6223 SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
      ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
         ADEFS       += -pd "__ROMSA_SUPPORT__ SETL {TRUE}"
      endif
      ifdef FOTA_ENABLE
      ifneq ($(strip $(FOTA_ENABLE)),NONE)
      ifneq ($(strip $(FOTA_ENABLE)),)
         ADEFS       += -pd "REMAPPING SETL {TRUE}" -pd "__FOTA_ENABLE__ SETL {TRUE}"  
         CFLAGS += -DREMAPPING
      endif
      endif
      endif
   endif
   ifeq ($(COMPONENT),fota)
      ADEFS       += -pd "MT6223 SETL {TRUE}"
   endif
   ifeq ($(COMPONENT),custom)
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
        ifneq ($(strip $(FOTA_ENABLE)),)
           CFLAGS += -DREMAPPING
        endif
        endif
      endif
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223P)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6223P SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
      ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
         ADEFS       += -pd "__ROMSA_SUPPORT__ SETL {TRUE}"
      endif
      ifdef FOTA_ENABLE
      ifneq ($(strip $(FOTA_ENABLE)),NONE)
      ifneq ($(strip $(FOTA_ENABLE)),)
         ADEFS       += -pd "REMAPPING SETL {TRUE}" -pd "__FOTA_ENABLE__ SETL {TRUE}"  
         CFLAGS += -DREMAPPING
      endif
      endif
      endif
   endif
   ifeq ($(COMPONENT),fota)
      ADEFS       += -pd "MT6223P SETL {TRUE}"
   endif
   ifeq ($(COMPONENT),custom)
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
        ifneq ($(strip $(FOTA_ENABLE)),)
           CFLAGS += -DREMAPPING
        endif
        endif
      endif
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226M)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6226M SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
      ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
         ADEFS       += -pd "__ROMSA_SUPPORT__ SETL {TRUE}"
      endif
   endif
   ifeq ($(COMPONENT),custom)
      CFLAGS += -DREMAPPING
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6229)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6229 SETL {TRUE}" 
      ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
         ADEFS       += -pd "_NAND_FLASH_BOOTING_ SETL {TRUE}"
      endif
      ifdef FOTA_ENABLE
      ifneq ($(strip $(FOTA_ENABLE)),NONE)
      ifneq ($(strip $(FOTA_ENABLE)),)
         ADEFS       += -pd "REMAPPING SETL {TRUE}" -pd "__FOTA_ENABLE__ SETL {TRUE}"  
         CFLAGS += -DREMAPPING
      endif
      endif
      endif
   endif
   ifeq ($(COMPONENT),fota)
      ADEFS       += -pd "MT6229 SETL {TRUE}"
   endif
   ifeq ($(COMPONENT),custom)
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
        ifneq ($(strip $(FOTA_ENABLE)),)
           CFLAGS += -DREMAPPING
        endif
        endif
      endif
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6229)
   ifeq ($(COMPONENT),init_ma)
      ADEFS       += -pd "MT6229 SETL {TRUE}" 
      ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
         ADEFS       += -pd "_NAND_FLASH_BOOTING_ SETL {TRUE}"
      endif
      ifdef FOTA_ENABLE
      ifneq ($(strip $(FOTA_ENABLE)),NONE)
      ifneq ($(strip $(FOTA_ENABLE)),)
         ADEFS       += -pd "REMAPPING SETL {TRUE}" -pd "__FOTA_ENABLE__ SETL {TRUE}"  
         CFLAGS += -DREMAPPING
      endif
      endif
      endif
   endif
   ifeq ($(COMPONENT),fota)
      ADEFS       += -pd "MT6229 SETL {TRUE}"
   endif
   ifeq ($(COMPONENT),custom)
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
        ifneq ($(strip $(FOTA_ENABLE)),)
           CFLAGS += -DREMAPPING
        endif
        endif
      endif
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6230)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6230 SETL {TRUE}" 
      ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
         ADEFS       += -pd "_NAND_FLASH_BOOTING_ SETL {TRUE}"
      endif
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6228)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6228 SETL {TRUE}" 
      ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
         ADEFS       += -pd "_NAND_FLASH_BOOTING_ SETL {TRUE}"
      endif
      ifdef FOTA_ENABLE
      ifneq ($(strip $(FOTA_ENABLE)),NONE)
      ifneq ($(strip $(FOTA_ENABLE)),)
         ADEFS       += -pd "REMAPPING SETL {TRUE}" -pd "__FOTA_ENABLE__ SETL {TRUE}"  
         CFLAGS += -DREMAPPING
      endif
      endif
      endif
   endif
   ifeq ($(COMPONENT),fota)
      ADEFS       += -pd "MT6228 SETL {TRUE}"
   endif
   ifeq ($(COMPONENT),custom)
      ifdef FOTA_ENABLE
        ifneq ($(strip $(FOTA_ENABLE)),NONE)
        ifneq ($(strip $(FOTA_ENABLE)),)
           CFLAGS += -DREMAPPING
        endif
        endif
      endif
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6227)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6227 SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
      ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
         ADEFS       += -pd "__ROMSA_SUPPORT__ SETL {TRUE}"
      endif
   endif
   ifeq ($(COMPONENT),custom)
      CFLAGS += -DREMAPPING
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6227D)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6227D SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
      ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
         ADEFS       += -pd "__ROMSA_SUPPORT__ SETL {TRUE}"
      endif
   endif
   ifeq ($(COMPONENT),custom)
      CFLAGS += -DREMAPPING
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6226 SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
      ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
         ADEFS       += -pd "__ROMSA_SUPPORT__ SETL {TRUE}"
      endif
   endif
   ifeq ($(COMPONENT),custom)
      CFLAGS += -DREMAPPING
   endif
endif

ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226D)
   ifeq ($(COMPONENT),init)
      ADEFS       += -pd "MT6226D SETL {TRUE}" -pd "REMAPPING SETL {TRUE}"
      ifeq ($(strip $(MCUROM_SUPPORT)),TRUE)
         ADEFS       += -pd "__ROMSA_SUPPORT__ SETL {TRUE}"
      endif
   endif
   ifeq ($(COMPONENT),custom)
      CFLAGS += -DREMAPPING
   endif
endif

ifeq ($(DEBUG_SAVE_CUR_THREAD),TRUE)
	ADEFS       +=  -pd "__DEBUG_SAVE_CUR_THREAD__ SETL {TRUE}"
endif

ifeq ($(SWDBG_SUPPORT),TRUE)
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6228)
      ifeq ($(COMPONENT),init)
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}"
      endif     	
      ifeq ($(findstring nucleus,$(COMPONENT)),nucleus) 
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}"
      endif     	      
   endif	
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6229)
      ifeq ($(COMPONENT),init)
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}" 
      endif
      ifeq ($(COMPONENT),init_ma)
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}" 
      endif     	
      ifeq ($(findstring nucleus,$(COMPONENT)),nucleus) 
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}"
      endif
      ifeq ($(findstring nucleus_ma,$(COMPONENT)),nucleus_ma) 
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}"
      endif     	      
   endif	      
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6238)
      ifeq ($(COMPONENT),init)
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}" 
      endif     	
      ifeq ($(findstring nucleus,$(COMPONENT)),nucleus) 
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}"
      endif     	      
   endif	   
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6230)
      ifeq ($(COMPONENT),init)
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}"
      endif     	
      ifeq ($(findstring nucleus,$(COMPONENT)),nucleus) 
         ADEFS       +=  -pd "__SWDBG_SUPPORT__ SETL {TRUE}"
      endif     	      
   endif	      
endif

ifeq ($(UID_SUPPORT),TRUE)
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226D)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif   
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6227)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6227D)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif	
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6228)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif	
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6229)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif	
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6238)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif	
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6230)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif	
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226M)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif	
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6225)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif	
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif
   ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223P)
         ADEFS       +=  -pd "UID_SUPPORT SETL {TRUE}"
   endif
endif

ifeq ($(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT),TRUE)
   ifeq ($(COMPONENT),init)
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6205B)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226D)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6226M)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6227)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6227D)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6229)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6230)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif             
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6225)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
      ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223P)
            ADEFS       +=  -pd "SINGLE_BANK_SUPPORT SETL {TRUE}"
      endif
   endif
endif

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
  ifeq ($(strip $(COMPONENT)),init)
		ADEFS       += -pd "DCM_ENABLE SETL {TRUE}"
  endif
  ifeq ($(strip $(COMPONENT)),init_ma)
		ADEFS       += -pd "DCM_ENABLE SETL {TRUE}"
  endif
endif

ifeq ($(PRODUCTION_RELEASE),TRUE)
	ADEFS       +=  -pd "__PRODUCTION_RELEASE__ SETL {TRUE}"
endif

ifeq ($(strip $(L1_GPRS)),TRUE)
  ifeq ($(strip $(L1_WCDMA)),TRUE)
    ifeq ($(strip $(L1_3GSOLUTION)),MA_L1)
       ifeq ($(findstring nucleus_ctrl_code,$(COMPONENT)),nucleus_ctrl_code) 
          ADEFS       += -pd "__MA_L1__ SETL {TRUE}"
       endif
       ifeq ($(findstring nucleus_ctrl_code_ma,$(COMPONENT)),nucleus_ctrl_code_ma) 
          ADEFS       += -pd "__MA_L1__ SETL {TRUE}"
       endif
    endif
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
	ADEFS       +=  -pd "KAL_ON_NUCLEUS SETL {TRUE}"
endif

ifeq ($(strip $(RTOS)),THREADX)
	ADEFS       +=  -pd "KAL_ON_THREADX SETL {TRUE}"
endif


ifeq ($(strip $(JPG_DECODE)),JPG_SW)
   ADEFS       +=  -pd "__SW_JPEG_CODEC_SUPPORT__ SETL {TRUE}"
else
  ifeq ($(strip $(JPG_ENCODE)),JPG_SW)
     ADEFS       +=  -pd "__SW_JPEG_CODEC_SUPPORT__ SETL {TRUE}"
   endif
endif


##ifeq ($(strip $(COMPONENT)),sst)
##	CFLAGS  := $(subst -g, ,$(CFLAGS))
##endif

ifeq ($(strip $(COMPONENT)),sbpki2)
	CFLAGS  := $(subst -g, ,$(CFLAGS))
endif

ifeq ($(strip $(COMPONENT)),sb51)
	CFLAGS  := $(subst -g, ,$(CFLAGS))
endif

ifeq ($(strip $(COMPONENT)),sslplus5)
	CFLAGS  := $(subst -g, ,$(CFLAGS))
endif

ifeq ($(strip $(COMPONENT)),j2me_11)
	CFLAGS  := $(subst -g, ,$(CFLAGS))
endif

ifeq ($(strip $(COMPONENT)),j2me_hi)
	CFLAGS  := $(subst -g, ,$(CFLAGS))
endif



# if any component needs to interwork with other ARM mode components, it should
# add "APCS_INTWORK" into its .def
ifneq ($(findstring -DAPCS_INTWORK,$(CDEFS)),)
	CINTWORK    =  $(APCSINT)
	AINTWORK    =  $(APCSINT)
else
	CINTWORK    =
	AINTWORK    =
endif

# Compiler settings for specific components
#the following will be removed after *.def are updated
CMPLR       = $(CC)
ifeq ($(COMPONENT),kal)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(COMPONENT),kal_ma)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(COMPONENT),l1audio32)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(COMPONENT),fota)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(COMPONENT),l1audio)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(COMPONENT),dp_engine)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime -Ono_autoinline
endif
ifeq ($(COMPONENT),opengl)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime 
endif
ifeq ($(COMPONENT),opengl16)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime 
endif
ifeq ($(COMPONENT),rompatch)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime
endif
ifeq ($(COMPONENT),bootloader)
   CMPLR       := $(CC)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif
ifeq ($(COMPONENT),gdi_arm)
   CMPLR       := $(CC32)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   CFLAGS      += -Otime
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6228)
   ifeq ($(COMPONENT),sw_png_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6229)
   ifeq ($(COMPONENT),sw_png_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6238)
   ifeq ($(COMPONENT),sw_png_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6230)
   ifeq ($(COMPONENT),sw_png_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6225)
   ifeq ($(COMPONENT),sw_png_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6225)
   ifeq ($(COMPONENT),sw_jpeg_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223)
   ifeq ($(COMPONENT),sw_png_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223)
   ifeq ($(COMPONENT),sw_jpeg_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223P)
   ifeq ($(COMPONENT),sw_png_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif
ifeq ($(call Upper,$(strip $(PLATFORM))),MT6223P)
   ifeq ($(COMPONENT),sw_jpeg_codec)
      CMPLR       := $(CC32)
      CINTWORK    =  $(APCSINT)
      AINTWORK    =  $(APCSINT)
      CFLAGS      += -Otime
   endif   
endif

ifeq ($(strip $(COMPILER)),RVCT)
   CFLAGS += --bss_threshold=0
   CPLUSFLAGS += --bss_threshold=0
endif

ifeq ($(strip $(COMPILER)),ADS)
   CPP_CMPLR = $(CPPC)
   CPLUSFLAGS = $(CFLAGS)
   MD = -MD
else
   CPP_CMPLR = $(CMPLR)
   MD = --md
endif   

# *************************************************************************
# Library Targets
# *************************************************************************
update_lib: $(TARGLIB)

ifeq ($(strip $(RVCT_MULTI_FILE)),NONE)

$(TARGLIB) : $(COBJS) $(CPPOBJS) $(AOBJS) $(ARMOBJS)

   # If library for customer release exists.
   # Copy and update it or create a new one
	@if exist $(FIXPATH)\$(CUS_MTK_LIB)\$(COMPONENT).lib 										\
		(copy /z $(FIXPATH)\$(CUS_MTK_LIB)\$(COMPONENT).lib $(subst /,\,$(TARGLIB))) & \
		($(LIB) -r $(TARGLIB) $(COMPOBJS_DIR)/*.obj) 									\
	else 																								\
		($(LIB) -create $(TARGLIB) $(COMPOBJS_DIR)/*.obj)

	@echo $(TARGLIB) is updated

	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT).dep if exist $(RULESDIR)\$(COMPONENT)_dep\*.det type $(RULESDIR)\$(COMPONENT)_dep\*.det >> $(RULESDIR)\$(COMPONENT).dep
	@if not $(ACTION)==remake if not exist $(RULESDIR)\$(COMPONENT).dep if exist $(RULESDIR)\$(COMPONENT)_dep\*.det  type $(RULESDIR)\$(COMPONENT)_dep\*.det > $(RULESDIR)\$(COMPONENT).dep
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT)_dep\*.det del /f /q $(RULESDIR)\$(COMPONENT)_dep\*.det
	@if exist $(RULESDIR)\$(COMPONENT)_dep rd /s /q $(RULESDIR)\$(COMPONENT)_dep
ifeq ($(findstring j2me,$(COMPONENT)),j2me)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT).dep copy /y $(RULESDIR)\$(COMPONENT).dep make\$(COMPONENT)
endif
ifeq ($(COMPONENT),jblendia)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT).dep copy /y $(RULESDIR)\$(COMPONENT).dep make\$(COMPONENT)
endif
ifeq ($(COMPONENT),ijet_adp)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT).dep copy /y $(RULESDIR)\$(COMPONENT).dep make\$(COMPONENT)
endif

endif


ifeq ($(strip $(RVCT_MULTI_FILE)),MULTI_FILE)
ifeq ($(strip $(COMPILER)),RVCT)

$(TARGLIB):
	@echo Compiling $< ...
	@tools\strcmpex.exe $(ACTION) remake e $(*F).via  $(CINTWORK) -c $(CFLAGS) $(CDEFS) $(CINCDIRS) --multifile  -o $(COMPOBJS_DIR)/$(COMPONENT).obj $(CPPSRCS) $(CSRCS) $<
	@tools\strcmpex.exe $(ACTION) remake n $(*F).via  $(CINTWORK) -c $(CFLAGS) $(CDEFS) $(CINCDIRS) --multifile -o $(COMPOBJS_DIR)/$(COMPONENT).obj $(CPPSRCS) $(CSRCS) $<
	@if exist $(*F).via tools\warp.exe $(*F).via
	@if exist $(*F).via $(CMPLR) -via $(*F).via

	@if exist $(FIXPATH)\$(CUS_MTK_LIB)\$(COMPONENT).lib 										\
		(copy /z $(FIXPATH)\$(CUS_MTK_LIB)\$(COMPONENT).lib $(subst /,\,$(TARGLIB))) & \
		($(LIB) -r $(TARGLIB) $(COMPOBJS_DIR)/*.obj) 									\
	else 																								\
		($(LIB) -create $(TARGLIB) $(COMPOBJS_DIR)/*.obj)

	@echo $(TARGLIB) is updated
	
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT).dep if exist $(RULESDIR)\$(COMPONENT)_dep\*.det type $(RULESDIR)\$(COMPONENT)_dep\*.det >> $(RULESDIR)\$(COMPONENT).dep
	@if not $(ACTION)==remake if not exist $(RULESDIR)\$(COMPONENT).dep if exist $(RULESDIR)\$(COMPONENT)_dep\*.det type $(RULESDIR)\$(COMPONENT)_dep\*.det > $(RULESDIR)\$(COMPONENT).dep
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT)_dep\*.det del /f /q $(RULESDIR)\$(COMPONENT)_dep\*.det
	@if exist $(RULESDIR)\$(COMPONENT)_dep rd /s /q $(RULESDIR)\$(COMPONENT)_dep
ifeq ($(findstring j2me,$(COMPONENT)),j2me)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT).dep copy /y $(RULESDIR)\$(COMPONENT).dep make\$(COMPONENT)
endif
ifeq ($(COMPONENT),jblendia)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT).dep copy /y $(RULESDIR)\$(COMPONENT).dep make\$(COMPONENT)
endif
ifeq ($(COMPONENT),ijet_adp)
	@if not $(ACTION)==remake if exist $(RULESDIR)\$(COMPONENT).dep copy /y $(RULESDIR)\$(COMPONENT).dep make\$(COMPONENT)
endif

endif
endif

# *************************************************************************
# Include dependencies for this component (updated by ScanDeps)
# *************************************************************************
-include $(RULESDIR)\$(COMPONENT).dep

# *************************************************************************
# Component Targets
# *************************************************************************
# -----------------------------
# C Objects
# -----------------------------
.c.obj:
	@echo Compiling $< ...
	@tools\strcmpex.exe $(ACTION) remake e $(*F).via  $(CINTWORK) -c $(CFLAGS) $(CDEFS) $(CINCDIRS) -o $(COMPOBJS_DIR)/$@ $<
	@tools\strcmpex.exe $(ACTION) remake n $(*F).via  $(CINTWORK) -c $(CFLAGS) $(CDEFS) $(CINCDIRS) $(MD) -o $(COMPOBJS_DIR)/$@ $<
	@if exist $(*F).via tools\warp.exe $(*F).via
	@if exist $(*F).via $(CMPLR) $(VIA) $(*F).via
	@if not $(ACTION)==remake if exist $(FIXPATH)\$(*F).d perl .\tools\pack_dep.pl $(FIXPATH)\$(*F).d > $(RULESDIR)\$(COMPONENT)_dep\$(*F).det
	@if not $(ACTION)==remake if exist $(FIXPATH)\$(*F).d del /f /q $(FIXPATH)\$(*F).d > nul
	@if exist $(*F).via del /f /q $(*F).via

%.obj : %.cpp
	@echo Compiling $< ...
	@tools\strcmpex.exe $(ACTION) remake e $(*F).via  $(CINTWORK) -c $(CPLUSFLAGS) $(CDEFS) $(CINCDIRS) -o $(COMPOBJS_DIR)/$@ $<
	@tools\strcmpex.exe $(ACTION) remake n $(*F).via  $(CINTWORK) -c $(CPLUSFLAGS) $(CDEFS) $(CINCDIRS) $(MD) -o $(COMPOBJS_DIR)/$@ $<
	@if exist $(*F).via tools\warp.exe $(*F).via
	@if exist $(*F).via $(CPP_CMPLR) $(VIA) $(*F).via
	@if not $(ACTION)==remake if exist $(FIXPATH)\$(*F).d perl .\tools\pack_dep.pl $(FIXPATH)\$(*F).d > $(RULESDIR)\$(COMPONENT)_dep\$(*F).det
	@if not $(ACTION)==remake if exist $(FIXPATH)\$(*F).d del /f /q $(FIXPATH)\$(*F).d > nul
	@if exist $(*F).via del /f /q $(*F).via

# -----------------------------
# Assembly Objects
# -----------------------------
Interpreter_armJIT.obj: Interpreter_armJIT.s
	@echo Compiling $< ..
ifeq ($(strip $(PLATFORM)),MT6238)
	$(ASM) $(APCSINT) -g -littleend -cpu ARM9EJ-S -32 $< -o $(COMPOBJS_DIR)/$@
else
	$(ASM) $(APCSINT) -g -littleend -cpu ARM7EJ-S -32 $< -o $(COMPOBJS_DIR)/$@
endif

Interpreter_thumbJIT.obj: Interpreter_thumbJIT.s
	@echo Compiling $< ..
ifeq ($(strip $(PLATFORM)),MT6238)
	$(ASM) $(APCSINT) -g -littleend -cpu ARM9EJ-S -32 $< -o $(COMPOBJS_DIR)/$@
else
	$(ASM) $(APCSINT) -g -littleend -cpu ARM7EJ-S -32 $< -o $(COMPOBJS_DIR)/$@
endif

divider.obj: divider.s
	@echo Compiling $< ..
ifeq ($(strip $(PLATFORM)),MT6238)
	$(ASM) $(APCSINT) -g -littleend -cpu ARM9EJ-S -32 $< -o $(COMPOBJS_DIR)/$@
else
  ifeq ($(strip $(PLATFORM)),MT6205B)
		$(ASM) $(APCSINT) -g -littleend -cpu ARM7TDMI -32 $< -o $(COMPOBJS_DIR)/$@
  else
    ifeq ($(strip $(PLATFORM)),MT6205C)
			$(ASM) $(APCSINT) -g -littleend -cpu ARM7TDMI -32 $< -o $(COMPOBJS_DIR)/$@
    else
			$(ASM) $(APCSINT) -g -littleend -cpu ARM7EJ-S -32 $< -o $(COMPOBJS_DIR)/$@
    endif
  endif
endif


.s.obj:
	@echo Compiling $< ..
	@$(ASM) $(AINTWORK) $(AFLAGS) $(ADEFS) $< -o $(COMPOBJS_DIR)/$@
	
%.obj : %.arm
	@echo Compiling $< ..
	@echo $(ASM) $(AINTWORK) $(AFLAGS) $(ADEFS) 
	@$(ASM) $(AINTWORK) $(AFLAGS) $(ADEFS) $< -o $(COMPOBJS_DIR)/$@
	
