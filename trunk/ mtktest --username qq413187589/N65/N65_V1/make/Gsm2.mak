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
# *************************************************************************
# GSM2.MAK  - GSM phase 2 master project build script
#
#  DISCUSSION:
#     CUSTOMER = MTK, PLUTO ...
#     PROJECT = L1S, GSM, GPRS
#
#  USAGE:
#     tools\make.exe -f[make file] [build_flag] <CUSTOMER> <PROJECT> <ACTION>
#
#     Example:
#     tools\make.exe -fmake\gsm2.mak -r -R CUSTOMER=mtk PROJECT=gprs new
#
#  IMPORTANT NOTES:
#
# *************************************************************************

# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .ptr .h

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : new cleanall emigen cmmgen asngen nvram_auto_gen codegen ptrgen asnregen update cleanlog cleanbin genverno gencustominfo gencustomlists cksysdrv resgen scan remake libs code_generate cleancodegen cleanmod done gen_bl_verno startbuildlibs bootloader fota gen_infolog mmi_feature_check operator_check mcp_check ckmake mmi_obj_check

# *************************************************************************
# MediaTek is the default CUSTOMER.
# *************************************************************************

# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# -----------------------------
#  Include scripts
# -----------------------------
include make\option.mak            # Build option definitons


# ------------------------
# Huyanwei Add It For Collecting Something
# -----------------------
EMPTY:=
SPACE:=$(EMPTY) $(EMPTY)
TIMESTRING =$(strip $(subst :, ,$(subst /, ,$(strip $(BUILD_DATE_TIME)))))
COLLECTDIR=$(word 1,$(TIMESTRING))年$(word 2,$(TIMESTRING))月$(word 3,$(TIMESTRING))日$(word 4,$(TIMESTRING))时$(word 5,$(TIMESTRING))分$(subst $(SPACE),,$(strip $(LANGUAGEDIR)))
TARGETRARFILE=$(strip .\"$(strip $(LANGUAGEPREFIX))$(strip $(NOKE_PROJECT)).$(strip $(NOKE_PCB_VERSION)).$(strip $(NOKE_CUSTOMER)).$(strip $(NOKE_FLASHTYPE)).$(strip $(CMOS_SENSOR)).$(strip $(SUB_CMOS_SENSOR)).$(strip $(NOKE_LCD)).TV.FM.D$(strip $(subst 20,,$(strip $(word 1,$(TIMESTRING)))))$(strip $(word 2,$(TIMESTRING)))$(strip $(word 3,$(TIMESTRING))).$(subst $(SPACE),,$(strip $(LANGUAGEDIR))).$(strip $(NOKE_POWER_ONOFF_ANIMATION)).KEY$(strip $(NOKE_KEYBOARD_VERSION)).[JAVA]NO.[TP]NO.T.rar")
SOFTWARE_INFO=$(strip $(NOKE_PROJECT))_[BB]$(strip $(PLATFORM))_[PCB]$(strip $(NOKE_PCB_VERSION))_[RFPA:$(strip $(NOKE_RFPA_FREQ))]$(strip $(NOKE_RFPA_MODULE))_[Mem]$(strip $(NOKE_FLASHTYPE))_[LCD]$(strip $(NOKE_LCD))_[MainCam]$(strip $(CMOS_SENSOR))_[SubCam]$(strip $(SUB_CMOS_SENSOR))_[BT]$(strip $(NOKE_BLUETOOTH_CHIP))_[TV]$(strip $(ANALOG_TV_CHIP))_[FM]$(strip $(FM_RADIO_CHIP))_[ANI]$(strip $(NOKE_POWER_ONOFF_ANIMATION))_[KEY]$(strip $(NOKE_KEYBOARD_VERSION))_[JAVA]NO_[TP]NO


ifeq ($(strip $(ANALOG_TV_CHIP)),NONE)
TARGETRARFILE:=$(strip $(subst TV.,,$(TARGETRARFILE)))
endif
ifeq ($(strip $(FM_RADIO_CHIP)),NONE)
    ifneq ($(strip $(FM_RADIO_WITH_TV_CHIP)),TRUE)
	TARGETRARFILE:=$(strip $(subst FM.,,$(TARGETRARFILE)))
    endif
endif
ifneq ($(strip $(J2ME_SUPPORT)),NONE)
	TARGETRARFILE:=$(strip $(subst [JAVA]NO,[JAVA]YES,$(TARGETRARFILE)))
	SOFTWARE_INFO:=$(strip $(subst [JAVA]NO,[JAVA]YES,$(SOFTWARE_INFO)))
endif
ifneq ($(strip $(TOUCH_PANEL_SUPPORT)),NONE)
	TARGETRARFILE:=$(strip $(subst [TP]NO,[TP]YES,$(TARGETRARFILE)))
	SOFTWARE_INFO:=$(strip $(subst [TP]NO,[TP]YES,$(SOFTWARE_INFO)))
endif
ifneq ($(strip $(NOKE_VER)),NONE)
## Option.mak protect var valid......
TARGETRARFILE:=$(strip $(subst .T.,.$(strip $(NOKE_VER)).,$(TARGETRARFILE)))
endif

# ------------------------
# Huyanwei Add End
# -----------------------


NEED_TRANS_CLASSB = FALSE
ifeq ($(call Upper,$(strip $(PROJECT))),L1S)
	ifeq ($(strip $(L1_GPRS)),TRUE)
      NEED_TRANS_CLASSB = TRUE
	endif
else
	ifeq ($(call Upper,$(strip $(PROJECT))),GPRS)
      NEED_TRANS_CLASSB = TRUE
	endif
#	ifeq ($(call Upper,$(strip $(PROJECT))),UMTS)
#      NEED_TRANS_CLASSB = TRUE
#	endif
endif

NEED_TRANS_UMTS = FALSE
ifeq ($(call Upper,$(strip $(PROJECT))),UMTS)
   NEED_TRANS_UMTS = TRUE
endif
	
-include make\~cleanmod.tmp      # Define clean modules
ifndef DO_CLEAN_MODULE
   # Default clean all
	DO_CLEAN_MODULE   =  FALSE
	CLEAN_MODS        =
else

	ifneq ($(findstring =L1=,$(foreach mod,$(call Upper,$(CLEAN_MODS)),=$(mod)=)),)
		NEED_CLEAN_CGENLST	=  TRUE
	else
		NEED_CLEAN_CGENLST	=  FALSE
	endif

   # Do component module name parsing according to different project combination
   # For example, in classb solution, l1 -> l1_classb instead l1,
   # but l1_classb should be accepted, too.

	ifeq ($(NEED_TRANS_CLASSB),TRUE)
		CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb))
		CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb))
		CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb))
		CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
		CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
		CLEAN_MODS := $(foreach comp,$(CLEAN_MODS),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
	endif

#$(warning CLEAN_MODS = $(CLEAN_MODS))
endif


-include make\~updatemod.tmp     # Define update modules
ifndef DO_UPDATE_MODULE
   # Default update all
	DO_UPDATE_MODULE  =  FALSE
	UPDATE_MODS       =
	RUN_RESGEN			=  TRUE
else

	RUN_RESGEN			=  FALSE

	ifneq ($(findstring =MMIRESOURCE=,$(foreach mod,$(call Upper,$(UPDATE_MODS)),=$(mod)=)),)
		RUN_RESGEN			=  TRUE
	endif

endif

# reset RUN_RESGEN if $(PROJECT) == BASIC || L1S
ifeq ($(strip $(call Upper,$(PROJECT))),BASIC)
	RUN_RESGEN			=  FALSE
endif

ifeq ($(strip $(call Upper,$(PROJECT))),L1S)
	RUN_RESGEN			=  FALSE
endif

ifneq ($(findstring MODEM,$(CUSTOMER)),)
	RUN_RESGEN			=  FALSE
endif

ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	RUN_RESGEN			=  FALSE
endif

#$(warning RUN_RESGEN: $(RUN_RESGEN))

-include make\~remakemod.tmp     # Define remake modules
ifndef DO_REMAKE_MODULE
   # Default remake all
	DO_REMAKE_MODULE  =  FALSE
	REMAKE_MODS       =
endif

-include make\Custom.bld         # Custom release build
ifndef CUSTOM_RELEASE
   # Default custom release
	CUSTOM_RELEASE  =  FALSE
endif

CODE_GEN_SRCS =

ifndef EXT_CAM_MODULE
	EXT_CAM_MODULE = NONE
endif

ifndef CMOS_SENSOR
	CMOS_SENSOR = NONE
endif

ifdef COMPILER
   ifeq ($(strip $(COMPILER)),RVCT)
      VIA = --via
   endif
   ifeq ($(strip $(COMPILER)),ADS)
      VIA = -via
   endif
endif

# default is ADS compiler
ifndef COMPILER
   COMPILER = ADS
   VIA = -via
endif

####################################################################
# Add alias module capability
####################################################################
include make\ALIAS.mak

ifdef COMPLIST
COMPLIST_TEMP = $(foreach mod,$(call Upper,$(COMPLIST)), \
  $(if $(findstring $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
COMPLIST := $(COMPLIST_TEMP)

ifdef UPDATE_MODS
UPDATE_MODS_TEMP = $(foreach mod,$(call Upper,$(UPDATE_MODS)), \
  $(if $(findstring $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
UPDATE_MODS := $(UPDATE_MODS_TEMP)

#ifdef REMAKE_MODS
#REMAKE_MODS_TEMP = $(foreach mod,$(call Upper,$(REMAKE_MODS)), \
#  $(if $(findstring $($(mod)),TRUE),$(subst $(mod),$($(mod)_CHILD),$(call Upper,$(REMAKE_MODS))),$(mod)))
#endif
#REMAKE_MODS := $(REMAKE_MODS_TEMP)

ifdef REMAKE_MODS
REMAKE_MODS_TEMP = $(foreach mod,$(call Upper,$(REMAKE_MODS)), \
  $(if $(findstring $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
REMAKE_MODS := $(REMAKE_MODS_TEMP)
####################################################################
# End of alias build settings.
####################################################################

ifndef MTK_SUBSIDIARY
  MTK_SUBSIDIARY = FALSE
endif

ifndef SYSGEN_ENABLE
  SYSGEN_ENABLE = FALSE
endif

# *************************************************************************
# Build path, directories
# *************************************************************************
# Do not support new mmi feature file architecture
OPTR_WARNING_DEF = $(strip $(FIXPATH))\operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi\operator_checklist.txt
PURE_VERNO = $(subst .,_, $(subst $(call Upper,$(strip $(CUSTOMER))).,, $(subst MAUI_SW.,, $(subst MAUI_SW.CLASSB.,, $(call Upper,$(VERNO))))))
FOTA_PURE_VERNO = $(subst .,_, $(subst $(call Upper,$(strip $(CUSTOMER))).,, $(subst MAUI.,, $(subst MAUI_SW.,, $(subst MAUI_SW.CLASSB.,, $(call Upper,$(VERNO)))))))
NEWTARGNAME    =  $(strip $(TARGNAME)).$(strip $(PURE_VERNO))
BPLGUINFOCUSTOMSRCP = BPLGUInfoCustomAppSrcP_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_$(strip $(PURE_VERNO))
MMI_FEATURES_FILE = $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features.h
MMI_FEATURES_SWITCH_FILE = $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
   BPLGUINFOCUSTOM = $(shell dir $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMPREFIX))* /b)
else
   BPLGUINFOCUSTOM = $(BPLGUINFOCUSTOMPREFIX)_$(strip $(PURE_VERNO))
endif

PLATFORM_LIB   =

COM_SCANDEFS   = $(foreach def, $(COM_DEFS),-define $(def))

COM_SCANDEFS_NEW  = $(foreach def, $(COM_DEFS),-D$(def))

# .log
LOGDIR         =  $(strip $(TARGDIR))

# version no dir
VERNODIR       =  $(strip $(FIXPATH))\verno

# summary log
LOG            =  $(strip $(LOGDIR))\$(strip $(PLATFORM)).log

# Component's log file
COMPLOGDIR     =  $(strip $(TARGDIR))\log
INFOLOG        =  $(strip $(COMPLOGDIR))\info.log
INFOMAKELOG        =  $(strip $(COMPLOGDIR))\infomake.log
CODE_GEN_LOG   =  $(strip $(COMPLOGDIR))\codegen.log

# L1 database
L1_DB_COMM     =  $(strip $(FIXPATH))\l1\common

# Cgen
CGEN           =  $(strip $(FIXPATH))\tools\Cgen.exe

# Catbin
CATBIN         =  $(strip $(FIXPATH))\tools\catbin.exe

ifeq ($(CUSTOM_RELEASE),FALSE)
	TMD_FILES         = $(L1_TMD_FILES)
	TST_GEN_DEP_SRCS  = $(strip $(TSTDIR))\database\msglog_db\parse_db.c
	TST_GEN_DEP_OUTS  = $(strip $(TST_DB))\msglog_db\pri.db
	PTR_GEN_OUTS  		= $(patsubst %.h,%.ptr, $(notdir $(subst \,/,$(COMP_TRACE_DEFS))))
	TST_GEN_DEP_STP3_SRCS  	= $(strip $(TST_DB))\msglog_db\BInfo
	TST_GEN_DEP_STP3_OUTS  	= $(strip $(TST_DB))\pstrace_db\BPInfo

else
	TMD_FILES         		=
	TST_GEN_DEP_SRCS  		= $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c
	TST_GEN_DEP_OUTS  		= $(strip $(TST_DB))\BPLGUInfoCustomAppSrc
	COMP_TRACE_DEFS			= $(EXISTED_CUS_REL_TRACE_DEFS)
	COMP_TRACE_DEFS			+= $(NEW_CUS_REL_TRACE_DEFS)
	PTR_GEN_OUTS  				= $(patsubst %.h,%.ptr, $(notdir $(subst \,/,$(COMP_TRACE_DEFS))))
	TST_GEN_DEP_STP3_SRCS  	= $(strip $(TST_DB))\BPLGUInfoCustomAppSrc  $(PTR_GEN_OUTS)
	TST_GEN_DEP_STP3_OUTS  	= $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP))

endif

# Concat module's local preprocessor definition
COMPDEFS          = __NULL_DEF__
COMPDEFS += $(foreach COMP,$(COMPLIST),$(shell type make\$(COMP)\$(COMP).def))
#$(warning [$(COMPDEFS)])

# -----------------------------
# Macros definition
# -----------------------------
PURELNKOPT     = $(strip $(LNKOPT))

ifeq ($(strip $(COMPILER)),RVCT)
  LNKOPT       += --largeregions --scatter $(SCATTERFILE) --output $(strip $(TARGDIR))\$(TARGNAME).elf \
						--symdefs $(strip $(TARGDIR))\$(TARGNAME).sym \
						--list $(strip $(TARGDIR))\$(TARGNAME).lis \
						--libpath $(DIR_ARMLIB)

ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
  LNKOPT       += --keep g_secinfo_tail \
						--keep g_SEC_RO \
						--keep g_FlashToolCfg \
						--keep g_SecureMAC_Size \
						--keep g_SecureMAC
endif

ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
  LNKOPT       += --keep g_CustParaCfg \
                  --keep g_CustParaCfg_Tail
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
  LNKOPT       += --keep g_enfb_3rdrom_header
endif

endif

ifeq ($(strip $(COMPILER)),ADS)
  LNKOPT       += -scatter $(SCATTERFILE) -output $(strip $(TARGDIR))\$(TARGNAME).elf \
						-symdefs $(strip $(TARGDIR))\$(TARGNAME).sym \
						-list $(strip $(TARGDIR))\$(TARGNAME).lis \
						-libpath $(DIR_ARMLIB)

ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
  LNKOPT       += -keep g_secinfo_tail \
						-keep g_SEC_RO \
						-keep g_FlashToolCfg \
						-keep g_SecureMAC_Size \
						-keep g_SecureMAC
endif

ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
  LNKOPT       += -keep g_CustParaCfg \
                  -keep g_CustParaCfg_Tail
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
  LNKOPT       += -keep g_enfb_3rdrom_header
endif

endif


# *************************************************************************
#  Target Definitions
# *************************************************************************

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)

  ifneq ($(findstring init,$(COMPLIST)),)
		INITLIB        =  $(strip $(COMPLIBDIR))\init.lib
  else
		INITLIB        =  $(CUS_MTK_LIB)\init.lib
  endif

ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)

  ifneq ($(findstring init_ma,$(COMPLIST)),)
		INITLIB        =  $(strip $(COMPLIBDIR))\init_ma.lib
  else
		INITLIB        =  $(CUS_MTK_LIB)\init_ma.lib
  endif

endif

  MTK_LIBS       =  $(foreach COMP,$(CUS_REL_HDR_COMP),$(CUS_MTK_LIB)\$(COMP).lib)
  
  ifdef GEMINI
    ifeq ($(strip $(GEMINI)),TRUE)
      CUS_REL_MTK_COMP := $(subst drv_sec,,$(CUS_REL_MTK_COMP))
      ifneq ($(findstring __DRV_DUAL_SIM_INVERSE__,$(CUSTOM_OPTION)),)
        MTK_LIBS += $(CUS_MTK_LIB)\DRV_DUAL_SIM_INVERSE_ON\drv_sec.lib
      else
        MTK_LIBS += $(CUS_MTK_LIB)\DRV_DUAL_SIM_INVERSE_OFF\drv_sec.lib
      endif
    endif
  endif
  
	MTK_LIBS       += $(foreach COMP,$(CUS_REL_MTK_COMP),$(CUS_MTK_LIB)\$(COMP).lib)
else

  ifneq ($(findstring init,$(COMPLIST)),)
	  INITLIB        =  $(strip $(COMPLIBDIR))\init.lib
  endif
  ifneq ($(findstring init_ma,$(COMPLIST)),)
	  INITLIB        =  $(strip $(COMPLIBDIR))\init_ma.lib
  endif
	MTK_LIBS       =

endif



ifeq ($(call Upper,$(PROJECT)),L1S)
	ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	CODEGEN_RESULT = $(strip $(TST_DB))\l1validation_db\BPLVInfo
	endif
else

	ifeq ($(strip $(SPLIT_SYSTEM)),TRUE)
		CODEGEN_RESULT = $(strip $(TST_DB))\BPLGUSplitInfo
	else

		ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
			CODEGEN_RESULT = $(strip $(TST_GEN_DEP_STP3_OUTS))		# used to control which steps will be available in custom release
		else
			CODEGEN_RESULT = $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM))
		endif
	endif
endif


ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
   ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
      NEED_RM_TSTDB = TRUE
   endif
else
	NEED_RM_TSTDB = FALSE
endif


L1TRACE_DB_DIR  =  $(strip $(TST_DB))\l1trace_db
L1VAL_DB_DIR    =  $(strip $(TST_DB))\l1validation_db
PSTRACE_DB_DIR  =  $(strip $(TST_DB))\pstrace_db
GV_DB_DIR       =  $(strip $(TST_DB))\gv

TMD_GEN_C_H_FILES = $(foreach tmd_file,$(TMD_FILES), $(basename $(tmd_file)).c $(strip $(TSTDIR))\include\$(notdir $(basename $(tmd_file)).h))

GV_FILES			 = $(shell dir $(strip $(TST_DB))\gv\*.gv /s/b)
#$(error [$(GV_FILES)])

ifeq ($(call Upper,$(PROJECT)),L1S)
	L1V_FILES	 = $(shell dir $(strip $(TST_DB))\l1validation_db\*.l1v /s/b)
#$(error [$(L1V_FILES)])
endif


ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
   ifeq ($(findstring verno,$(UPDATE_MODS)),)
      UPDATE_MODS := $(UPDATE_MODS) verno
   endif
   COMPLIBLIST = $(foreach comp,$(UPDATE_MODS),$(comp).lib)
else
	ifeq ($(strip $(DO_REMAKE_MODULE)),TRUE)
           ifeq ($(findstring verno,$(REMAKE_MODS)),)
              REMAKE_MODS := $(REMAKE_MODS) verno
           endif
   	COMPLIBLIST = $(foreach comp,$(REMAKE_MODS),$(comp).lib)
	else
		COMPLIBLIST = $(call sort,$(foreach comp,$(COMPLIST),$(comp).lib))
	endif
endif

# either drmadp.lib or custom.lib will run custominfo.pl
# but some project may not have to compile drmadp.lib, so put drmadp.lib first
ifneq ($(findstring drmadp.lib,$(COMPLIBLIST)),)
	CUSTOM_EXIST   =  TRUE
else
	CUSTOM_EXIST   =  FALSE
endif

ifneq ($(findstring custom.lib,$(COMPLIBLIST)),)
	CUSTOM_EXIST   =  TRUE
else
	CUSTOM_EXIST   =  FALSE
endif

# Do component module name parsing according to different project combination
# For example, in classb solution, l1 -> l1_classb instead l1,
# but l1_classb should be accepted, too.
ifeq ($(NEED_TRANS_CLASSB),TRUE)
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1.lib,$(comp)),$(comp),l1_classb.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr.lib,$(comp)),$(comp),rr_classb.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm.lib,$(comp)),$(comp),mm_classb.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l4.lib,$(comp)),$(comp),l4_classb.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out peer.lib,$(comp)),$(comp),peer_classb.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out interface.lib,$(comp)),$(comp),interface_classb.lib))
endif
ifeq ($(NEED_TRANS_UMTS),TRUE)
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1.lib,$(comp)),$(comp),l1_classb_umts.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr.lib,$(comp)),$(comp),rr_classb_umts.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm.lib,$(comp)),$(comp),mm_classb_umts.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l1_classb.lib,$(comp)),$(comp),l1_classb_umts.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out rr_classb.lib,$(comp)),$(comp),rr_classb_umts.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out mm_classb.lib,$(comp)),$(comp),mm_classb_umts.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out l4.lib,$(comp)),$(comp),l4_classb.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out peer.lib,$(comp)),$(comp),peer_classb.lib))
	COMPLIBLIST := $(foreach comp,$(COMPLIBLIST),$(if $(filter-out interface.lib,$(comp)),$(comp),interface_classb.lib))
endif

#$(warning COMPLIBLIST = $(COMPLIBLIST))

ifneq ($(strip $(call Upper,$(REMAKE_MODS))),BOOTLOADER)
ifneq ($(strip $(call Upper,$(REMAKE_MODS))),FOTA)
   CHK_COMPLIST = $(foreach comp,$(COMPLIBLIST),$(if $(findstring "$(comp)",$(foreach word,$(COMPLIST),"$(word).lib")),,$(comp) ))
   ifneq ($(words $(CHK_COMPLIST)),0)
      ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
         $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in CUS_REL_SRC_COMP or NOT in CUS_REL_PAR_SRC_COMP)
      else
         $(error $(foreach comp,$(CHK_COMPLIST),"$(comp)") NOT in COMPLIST)
      endif
   endif
endif
endif

ifeq ($(strip $(DO_UPDATE_MODULE)),TRUE)
   COMPSCANLIST = $(UPDATE_MODS)
else
	COMPSCANLIST = $(COMPLIST)
endif

ifdef COMPLIST
COM_DEF_PATH = $(foreach mod,$(COMPLIST), \
    $(if $($(mod)),$(FIXPATH)\make\$($(mod))\$($(mod)).def,$(FIXPATH)\make\$(mod)\$(mod).def))
endif

# Do component module name parsing according to different project combination
# For example, in classb solution, l1 -> l1_classb instead l1,
# but l1_classb should be accepted, too.
ifeq ($(NEED_TRANS_CLASSB),TRUE)
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
endif
#$(warning COMPSCANLIST = $(COMPSCANLIST))
ifeq ($(NEED_TRANS_UMTS),TRUE)
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1,$(comp)),$(comp),$(comp)_classb_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr,$(comp)),$(comp),$(comp)_classb_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm,$(comp)),$(comp),$(comp)_classb_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l1_classb,$(comp)),$(comp),$(comp)_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out rr_classb,$(comp)),$(comp),$(comp)_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out mm_classb,$(comp)),$(comp),$(comp)_umts))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out l4,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out peer,$(comp)),$(comp),$(comp)_classb))
	COMPSCANLIST := $(foreach comp,$(COMPSCANLIST),$(if $(filter-out interface,$(comp)),$(comp),$(comp)_classb))
endif

COMP_DEP_LIST = $(foreach comp,$(COMPSCANLIST),$(comp).dep)

# copy mmi_features_switch.h & CustMiscData.c will be used when CUSTOM_RELEASE == FALSE
# 1. MMI_VERSION != (PLUTO_MMI | NEPTUNE_MMI) ............................. MP is in our site     => CUSTOMER_MMI
# 2. MMI_VERSION == (PLUTO_MMI | NEPTUNE_MMI) & EMPTY_RESOURCE == TRUE .... MP is NOT in our site => CUSTOMER_MMI
# 3. MMI_VERSION == (PLUTO_MMI | NEPTUNE_MMI) & EMPTY_RESOURCE == FALSE ... MTK internal          => PLUTO_MMI or NEPTUNE_MMI
# copy mmi_features_switch.h & CustMiscData.c will be used when CUSTOM_RELEASE == TRUE
# 4. MMI_VERSION != (PLUTO_MMI | NEPTUNE_MMI) ............................. MP is in our site     => CUSTOMER_MMI
# 5. MMI_VERSION == (PLUTO_MMI | NEPTUNE_MMI) & EMPTY_RESOURCE == TRUE .... MP is NOT in our site => PLUTO_MMI or NEPTUNE_MMI
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
   NEED_COPY_MMIFEATURE = CUSTOMER_MMI

   ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
		NEED_COPY_MMIFEATURE = PLUTO_MMI

      ifdef EMPTY_RESOURCE
	      ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
				NEED_COPY_MMIFEATURE = CUSTOMER_MMI
		   endif
		endif
	else
		ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
			NEED_COPY_MMIFEATURE = NEPTUNE_MMI

         ifdef EMPTY_RESOURCE
	         ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
				   NEED_COPY_MMIFEATURE = CUSTOMER_MMI
		      endif
		   endif
		endif
	endif
else
   NEED_COPY_MMIFEATURE = CUSTOMER_MMI

   ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
		NEED_COPY_MMIFEATURE = PLUTO_MMI
	endif

	ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
		NEED_COPY_MMIFEATURE = NEPTUNE_MMI
	endif

endif

ifeq ($(call Upper,$(PROJECT)),BASIC)
	NEED_COPY_MMIFEATURE = NONE
endif

ifeq ($(call Upper,$(PROJECT)),L1S)
	NEED_COPY_MMIFEATURE = NONE
endif

# *************************************************************************
# Search Paths
# *************************************************************************
vpath
vpath %.h   $(subst \,/,$(dir $(COMP_TRACE_DEFS)))
vpath %.ptr $(subst \,/,$(strip $(TST_DB))\pstrace_db)
vpath %.dep $(subst \,/,$(strip $(RULESDIR)))
vpath %.lib $(strip $(OBJSDIR))\lib

vpath %.bin $(strip $(TARGDIR))

# *************************************************************************
#  Implicit Rules and Compiler Options
# *************************************************************************
BIN_FILE       =  $(strip $(NEWTARGNAME)).bin
IMG_FILE       =  $(strip $(TARGNAME)).elf
CODE_GEN_LST	=  $(strip $(TST_DB))\codegen.lis
ROM_IMG_FILE   =  rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
# *************************************************************************
#  Settings for BOOTLOADER
# *************************************************************************
BTLDVERNODIR   =  $(strip $(FIXPATH))\BootLoader\src
BTLD_PREFIX    =  $(strip $(CUSTOMER))_BOOTLOADER_$(strip $(BTLD_VERNO))_$(strip $(PLATFORM))_$(strip $(PURE_VERNO))
BTLD_BIN_FILE  =  $(strip $(BTLD_PREFIX)).bin
BTLD_SCATTERFILE	=	.\bootloader\src\scatter\scatBL_$(strip $(PLATFORM)).txt
BTLDLNKOPT     = $(strip $(LNKOPT)) -scatter $(BTLD_SCATTERFILE) \
                  -output $(strip $(TARGDIR))\$(BTLD_PREFIX).elf \
                  -symdefs $(strip $(TARGDIR))\$(BTLD_PREFIX).sym \
                  -list $(strip $(TARGDIR))\$(BTLD_PREFIX).lis \
                  -libpath $(DIR_ARMLIB)
-include $(BTLDVERNODIR)\verno_bootloader.bld
# *************************************************************************
#  Settings for FOTA
# *************************************************************************
# FOTA bin file name (cannot contain MAUI in FOTA bin file name)
FOTA_PREFIX    =  $(strip $(CUSTOMER))_FOTA_$(strip $(PLATFORM))_$(strip $(FOTA_PURE_VERNO))
FOTA_BIN_FILE  =  $(strip $(FOTA_PREFIX)).bin
CUSTOM_FOTA_H = $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))\custom_fota.h
FOTA_SCATTERFILE	=	.\fota\src\scatter\scatFOTA.txt
FOTALNKOPT     = $(strip $(LNKOPT)) -scatter $(FOTA_SCATTERFILE) \
                  -output $(strip $(TARGDIR))\$(FOTA_PREFIX).elf \
                  -symdefs $(strip $(TARGDIR))\$(FOTA_PREFIX).sym \
                  -list $(strip $(TARGDIR))\$(FOTA_PREFIX).lis \
                  -libpath $(DIR_ARMLIB)
# *************************************************************************
# New Build
# *************************************************************************
ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
new : cleanall cleanlog cleanbin resgen remake
else
  ifneq (,$(findstring $(strip $(PLATFORM)), $(strip $(NAND_FLASH_BOOTING_SUPPORT_PLATFORM))))
    ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
      ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
new : cleanall cmmgen mmi_feature_check asngen umts_gen codegen asnregen operator_check_lite $(BTLD_BIN_FILE) update
      else
new : cleanall cmmgen mmi_feature_check asngen codegen asnregen operator_check_lite $(BTLD_BIN_FILE) update  
      endif
    else
      ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
new : cleanall cmmgen mmi_feature_check asngen umts_gen codegen asnregen operator_check_lite update
      else
new : cleanall cmmgen mmi_feature_check asngen codegen asnregen operator_check_lite update
      endif
    endif
  else
    ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
new : cleanall cmmgen mmi_feature_check asngen umts_gen codegen asnregen operator_check_lite update
    else
new : cleanall cmmgen mmi_feature_check asngen codegen asnregen operator_check_lite update
    endif
  endif
endif

# *************************************************************************
#  Update Build
# *************************************************************************
#update : cleanlog cleanbin mcddll_update codegen resgen cksysdrv remake
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(CUSTOM)),MONZA29)
update : cleanlog codegen remake
  else
   ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
update : cleanlog cleanbin umts_gen mcddll_update codegen cksysdrv resgen remake
   else
update : cleanlog cleanbin mcddll_update codegen cksysdrv resgen remake
   endif
  endif
else
  ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
update : cleanlog cleanbin umts_gen mcddll_update codegen resgen cksysdrv remake
  else
update : cleanlog cleanbin mcddll_update codegen resgen cksysdrv remake
  endif
endif


# *************************************************************************
#  Remake Build
# *************************************************************************
ifeq ($(strip $(call Upper,$(REMAKE_MODS))),BOOTLOADER)
remake : $(BTLD_BIN_FILE) done
else
ifeq ($(strip $(call Upper,$(REMAKE_MODS))),FOTA)
remake : $(FOTA_BIN_FILE) done
else
ifdef FOTA_ENABLE
ifneq ($(strip $(FOTA_ENABLE)),NONE)
remake : mcp_check cleanlog cleanbin genverno libs $(BIN_FILE) $(FOTA_BIN_FILE) done
else
remake : mcp_check cleanlog cleanbin genverno libs $(BIN_FILE) done
endif
else
remake : mcp_check cleanlog cleanbin genverno libs $(BIN_FILE) done
endif
endif
endif

# *************************************************************************
#  Tools code preprocess and generation
# *************************************************************************
ifeq  ($(strip $(call Upper,$(PROJECT))),UMTS)
code_generate: cleancodegen asngen umts_gen codegen asnregen mcddll_update done
else
code_generate: cleancodegen asngen codegen asnregen mcddll_update done
endif

# ---------------------------------------
# 3G Codegen Gen Files: ASN and DBME
# ---------------------------------------
umts_gen:
	(cd uas) &  \
	(uas_generate.bat) &  \
	(cd ..) &  \

# ---------------------------------------
# MCDDLL update
# ---------------------------------------
mcddll_update: codegen
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifneq ($(call Upper,$(strip $(PROJECT))),L1S)
ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
	(cd ps) &  \
	(cd mcddll) &  \
    (perl updatemcddll_msvc.pl $(call Upper,$(strip $(PROJECT)))) &  \
    (cd ..) &  \
    (cd ..) &  \
	(copy /y ps\mcddll\mcddll.dll $(strip $(TST_DB))\mcddll.dll > nul)
endif
endif
endif
# -----------------------------
# Asn Gen Files
# -----------------------------
asngen:
   # XXX!!!. Temporary solution for customer engagement
	@if /I $(CUSTOMER) EQU PLUTO   \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(copy /z init\src\Pluto_idma.c init\src\idma.c) & \
			(copy /z init\include\Pluto_idma_out.h init\include\idma_out.h) & \
			(copy /z init\src\Pluto_bootarm.s init\src\bootarm.s) & \
			(copy /z init\src\Pluto_init.c init\src\init.c) \
		)

	-@if /I $(PROJECT) NEQ L1S   \
		(@if /I $(PROJECT) NEQ BASIC   \
			(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
				(@if /I $(MCD_SUPPORT) EQU TRUE   \
					(md ps\gen) & \
					(@echo Generate ASN Gen Files 1st Phase ...) & \
					(cd ps\tools) & \
					(perl ./mcdparser.pl mcd.ini --only=$(PROJECT) --define="$(CUSTOM_OPTION)") & \
					(cd ..\..) \
				else \
					(@echo Generate ASN Gen Files ...) & \
					(cd ps) & \
					(generate.bat) & \
					(@echo Generate ASN Gen Files Done ...) \
				) \
			) \
		)


asnregen:
	-@if /I $(PROJECT) NEQ L1S   \
		(@if /I $(PROJECT) NEQ BASIC   \
			(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
				(@if /I $(MCD_SUPPORT) EQU TRUE   \
					(@echo Generate ASN Gen Files 2nd Phase ...) & \
					(cd ps\tools) & \
					(perl ./mcdparser.pl mcd.ini  --only=$(PROJECT) --only=for_catcher --define="$(CUSTOM_OPTION)") & \
					(cd ..\..) \
				) \
			) \
		)


codegen : gencustominfo operator_check gencustomlists nvram_auto_gen $(CODEGEN_RESULT)
	-@if exist $(strip $(INFOMAKELOG)) \
		echo COMP_TRACE_DEFS = $(call sort, $(foreach def,$(COMP_TRACE_DEFS),$(def))) >> $(INFOMAKELOG)

# -----------------------------
# Step 1: Preprocess
# -----------------------------
$(TST_GEN_DEP_OUTS) : $(TST_GEN_DEP_SRCS)
	@echo Check Directories ...
	-@if not exist $(strip $(TST_DB)) \
		md $(TST_DB)

	-@if not exist $(strip $(TST_DB))\msglog_db \
		md $(strip $(TST_DB))\msglog_db

	-@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(@if not exist $(strip $(L1TRACE_DB_DIR)) \
				(md $(strip $(L1TRACE_DB_DIR))) \
			) & \
			(@if not exist $(strip $(L1VAL_DB_DIR)) \
				(md $(strip $(L1VAL_DB_DIR))) \
			) \
		)

	-@if not exist $(strip $(PSTRACE_DB_DIR)) \
		md $(strip $(PSTRACE_DB_DIR))

	-@if not exist $(strip $(GV_DB_DIR)) \
		md $(strip $(GV_DB_DIR))

	@echo Preprocessing C source code ...

	@tools\strcmpex.exe def def e make\~inc_def.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~inc_def.tmp

	@perl tools\echoLongString2.pl make\~inc_def.tmp -D $(COM_DEF_PATH)

#	@for /d %%i in ($(COM_DEF_PATH)) do \
#		(for /F %%j in (%%i) do \
#			(echo -D%%j >> make\~inc_def.tmp) \
#		) & \
#		(echo %%i > nul)

	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~inc.tmp >> make\~inc_def.tmp


	@if /I $(CUSTOM_RELEASE) EQU FALSE \
		@echo Compile parse_db.c ... & \
		($(CC) -E -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\pri.db $(strip $(TSTDIR))\database\msglog_db\parse_db.c 2>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		(@echo $(strip $(TST_DB))\msglog_db\pri.db > $(CODE_GEN_LST)) & \
		(@echo Compiling parse_db.c was done.) \
	else \
	  (if /I $(PROJECT) NEQ BASIC \
		($(CC) -E -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c 2>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		(if /I $(MTK_SUBSIDIARY) EQU TRUE \
		($(CC) -E -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TSTDIR))\database\msglog_db\app_parse_db.c 2>>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1)) & \
		(if $(words $(strip $(BPLGUINFOCUSTOM))) NEQ 1 ((@echo More than two $(strip $(BPLGUINFOCUSTOM)). Please check.) & \
		 (exit 644))) \
	  )
	@if /I $(CUSTOM_RELEASE) EQU TRUE \
		(if /I $(PROJECT) NEQ BASIC \
		(if /I $(MTK_SUBSIDIARY) EQU TRUE \
		($(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustomSrc $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) 2>>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		($(CGEN) -ap $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\BPLGUInfoCustomSrc $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) 2>>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1) & \
		(del /q $(strip $(TST_DB))\BPLGUInfoCustomSrc) & \
		(del /q $(strip $(TST_DB))\enumFileCustomSrc) \
		else \
		($(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustomAppSrc $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) 2>>$(CODE_GEN_LOG)) & \
		(if ERRORLEVEL 1 exit 1)) & \
		(@echo $(strip $(TST_DB))\BPLGUInfoCustomAppSrc > $(CODE_GEN_LST)) \
	  )

#	based on .h generate .ptr
.h.ptr:
	@echo Preprocessing PS trace definition ... $<
	@if /I $(PROJECT) NEQ BASIC \
			(copy $(subst /,\,$<) ~$(basename $(notdir $(subst \,/,$<))).c >nul) & \
			($(CC) -E -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -o $(strip $(TST_DB))\pstrace_db\$(basename $(notdir $(subst \,/,$<))).ptr ~$(basename $(notdir $(subst \,/,$<))).c 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\pstrace_db\$(basename $(notdir $(subst \,/,$<))).ptr >> $(CODE_GEN_LST)) & \
			(del ~$(basename $(notdir $(subst \,/,$<))).c)

# -----------------------------
# B ==> Base information
# P ==> Protocol trace information
# L ==> Layer 1 trace information
# G ==> Global variable information
# V ==> Layer 1 validation information
# U ==> GSM/GPRS Union Information
# -----------------------------

# -----------------------------
# Step 2: Generate Base Information
# -----------------------------
$(strip $(TST_DB))\msglog_db\BInfo :  $(TST_GEN_DEP_OUTS) $(PTR_GEN_OUTS) $(strip $(TSTDIR))\database\Tgt_Cnf
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate Base Information ...) & \
			($(CGEN) -c $(strip $(TST_DB))\msglog_db\pri.db $(strip $(TSTDIR))\database\Tgt_Cnf $(strip $(TSTDIR))\database\Pc_Cnf $(strip $(TST_DB))\msglog_db\BInfo $(strip $(TST_DB))\enumFile $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\msglog_db\BInfo >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TST_DB))\enumFile >> $(CODE_GEN_LST)) \
		)

# -----------------------------
# Step 3: Protocol trace information
# -----------------------------
#$(strip $(TST_DB))\pstrace_db\BPInfo : $(strip $(TST_DB))\msglog_db\BInfo
$(strip $(TST_GEN_DEP_STP3_OUTS)) : $(strip $(TST_GEN_DEP_STP3_SRCS))
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate PS Trace Information ...) & \
			($(CGEN) -ps $(strip $(TST_DB))\pstrace_db\BPInfo $(strip $(TST_DB))\msglog_db\BInfo $(strip $(TST_DB))\pstrace_db $(strip $(TST_DB))\pstrace_db\ps_trace.h 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\pstrace_db\BPInfo >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TST_DB))\msglog_db\BInfo >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TST_DB))\pstrace_db\ps_trace.h >> $(CODE_GEN_LST)) & \
			(del /q $(strip $(TST_DB))\msglog_db\BInfo > nul) \
		else \
			(echo Generate PS Trace Information ...) & \
			($(CGEN) -ps $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP)) $(strip $(TST_DB))\BPLGUInfoCustomAppSrc $(strip $(TST_DB))\pstrace_db $(strip $(TST_DB))\pstrace_db\ps_trace.h 2>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP)) >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TST_DB))\pstrace_db\ps_trace.h >> $(CODE_GEN_LST)) & \
			(del /q $(strip $(TST_DB))\BPLGUInfoCustomAppSrc > nul) \
		)

# -----------------------------
# Step 4: Layer 1 trace information
# -----------------------------
$(strip $(TST_DB))\l1trace_db\BPLInfo : $(strip $(TST_DB))\pstrace_db\BPInfo $(TMD_FILES)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate L1 Trace Information ...) & \
			($(CGEN) -L1 $(strip $(TST_DB))\l1trace_db\BPLInfo $(strip $(TST_DB))\pstrace_db\BPInfo L1_CATCHER $(strip $(TSTDIR))\src\TrcMod.c $(strip $(TSTDIR))\include\TrcMod.h $(TMD_FILES) 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\l1trace_db\BPLInfo >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TSTDIR))\src\TrcMod.c >> $(CODE_GEN_LST)) & \
			(echo $(strip $(TSTDIR))\include\TrcMod.h >> $(CODE_GEN_LST)) \
		)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(for /d %%i in ($(TMD_GEN_C_H_FILES)) do \
			   (echo %%i >> $(CODE_GEN_LST)) \
			) & \
			(del /q $(strip $(TST_DB))\pstrace_db\BPInfo > nul) \
		) 

# -----------------------------
# Step 5: Result temporary - Global variable information
# -----------------------------
$(strip $(TST_DB))\BPLGInfo : $(strip $(TST_DB))\l1trace_db\BPLInfo $(GV_FILES)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate Global variable Information ...) & \
			($(CGEN) -gv $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\l1trace_db\BPLInfo $(strip $(TST_DB))\gv\ $(strip $(TSTDIR))\src\gvTbl.c 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\BPLGInfo >> $(CODE_GEN_LST)) & \
			(del /q $(strip $(TST_DB))\l1trace_db\BPLInfo > nul) \
		)

# -----------------------------
# Step 6:  Result - Layer 1 validation information (L1S)
# -----------------------------
$(strip $(TST_DB))\l1validation_db\BPLVInfo :  $(strip $(TST_DB))\BPLGInfo $(L1V_FILES)
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate L1 Validation Information ...) & \
			($(CGEN) -L1V $(strip $(TST_DB))\l1validation_db\BPLVInfo $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\l1validation_db\ 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\l1validation_db\BPLVInfo >> $(CODE_GEN_LST)) & \
			(del /q $(strip $(TST_DB))\BPLGInfo > nul) \
		)

# -----------------------------
# Step 7: Result - Union Information (GSM/GPRS)
#------------------------------
$(strip $(TST_DB))\BPLGUInfo :  $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\uniontag.txt
	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Generate Union Information ...) & \
			($(CGEN) -un $(strip $(TST_DB))\BPLGUInfo $(strip $(TST_DB))\BPLGInfo $(strip $(TST_DB))\uniontag.txt 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(echo $(strip $(TST_DB))\BPLGUInfo >> $(CODE_GEN_LST)) & \
			(del /q $(strip $(TST_DB))\BPLGInfo > nul) \
		)

# ------------------------------------------
# Step 8: Result - Merge customization code
# ------------------------------------------
$(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) :  $(strip $(TST_DB))\BPLGUInfo
	@tools\strcmpex.exe def def e make\~inc_def.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~inc_def.tmp

	@perl tools\echoLongString2.pl make\~inc_def.tmp -D $(COM_DEF_PATH)
#	@for /d %%i in ($(COM_DEF_PATH)) do \
#		(for /F %%j in (%%i) do \
#			(echo -D%%j >> make\~inc_def.tmp) \
#		) & \
#		(echo %%i > nul)

	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@type make\~inc.tmp >> make\~inc_def.tmp

	@if /I $(PROJECT) NEQ BASIC \
		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
			(echo Merge customization code ...) & \
			($(CC) -E -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TSTDIR))\database\msglog_db\custom_parse_db.c 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(@echo Compile app_parse_db.c) & \
			($(CC) -E -DGEN_FOR_CPARSER -DGEN_FOR_PC $(VIA) make\~inc_def.tmp -USTDC_HEADERS -o $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TSTDIR))\database\msglog_db\app_parse_db.c 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(@echo Compiling app_parse_db.c was done.) & \
			($(CGEN) -cm $(strip $(TST_DB))\BPLGUInfoCustom $(strip $(TST_DB))\BPLGUInfo $(strip $(TST_DB))\msglog_db\custom_pri.db $(strip $(TST_DB))\enumFileCustom $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			($(CGEN) -ap $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\BPLGUInfoCustom $(strip $(TST_DB))\msglog_db\app_pri.db $(strip $(TST_DB))\enumFileCustomApp $(strip $(PLATFORM))_$(strip $(CHIP_VER)) $(strip $(VERNO)) $(FIXPATH)\plutommi 2>>$(CODE_GEN_LOG)) & \
			(if ERRORLEVEL 1 exit 1) & \
			(del /q $(strip $(TST_DB))\BPLGUInfo > nul) & \
			(del /q $(strip $(TST_DB))\BPLGUInfoCustom > nul) \
		)

# Disable Step 9 due to this flow is not used now.
# ------------------------------------------
# Step 9: Result - Split system checking and code gen (Split system)
# ------------------------------------------
#$(strip $(TST_DB))\BPLGUSplitInfo :  $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TSTDIR))\database\Routing.txt $(strip $(TST_DB))\BPGUInfo_pc
#	@if /I $(PROJECT) NEQ BASIC \
#		(@if /I $(CUSTOM_RELEASE) EQU FALSE   \
#			(echo Generate Split System Information ...) & \
#			($(CGEN) -ss $(strip $(TST_DB))\BPLGUSplitInfo $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOM)) $(strip $(TST_DB))\BPGUInfo_pc $(strip $(TSTDIR))\database\Routing.txt $(strip $(TSTDIR))\src\tst_routing.c 2>>$(CODE_GEN_LOG)) & \
#			(if ERRORLEVEL 1 exit 1) & \
#			(echo $(strip $(TST_DB))\BPLGUSplitInfo >> $(CODE_GEN_LST)) \
#		)


# *************************************************************************
# nvram_auto_gen
# *************************************************************************
nvram_auto_gen : 
#nvram_auto_gen : gencustominfo
	@tools\strcmpex.exe TRUE TRUE e make\~cus_opt.tmp $(foreach def,$(COM_DEFS),-D \"$(def)\")
	@tools\strcmpex.exe TRUE TRUE e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),$(inc))

ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
	@if exist $(MMIDIR)\customer \
		((echo CUSTOM_FOLDER = $(foreach def,$(BOARD_VER),$(def))> tools\NVRAMStatistic\include\custom_option.txt) & \
		(echo MMI_FOLDER = $(foreach def,$(MMI_BASE),$(def))>> tools\NVRAMStatistic\include\custom_option.txt) & \
		(echo CUSTOM_OPTION = $(foreach def,$(BOARD_VER) $(PLATFORM) $(LCD_MODULE) $(EXT_CAM_MODULE) $(CMOS_SENSOR),-D "$(def)") \>> tools\NVRAMStatistic\include\custom_option.txt) & \
		(type make\~cus_opt.tmp >> tools\NVRAMStatistic\include\custom_option.txt))

	@if exist $(MMIDIR)\customer \
		(@perl -e "open F,'<make\~inc.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > tools\NVRAMStatistic\include\custom_include.txt)

   #Output NVRAM info
	@if exist tools\NVRAMStatistic\include \
		(tools\NVRAMStatistic\NVRAMAutogen.bat $(strip $(CUSTOMER)))
endif

	@if exist $(strip $(TST_DB))\BPLGUInfoCustomAppSrc (del /q $(strip $(TST_DB))\BPLGUInfoCustomAppSrc)



# *************************************************************************
# Clean Generated Code Sources
# *************************************************************************
cleancodegen:
   # $(CODE_GEN_LST) should be copied to another place then delete
	-@if exist $(CODE_GEN_LST)						         \
		(copy $(CODE_GEN_LST) make\~codegenlis.tmp) &   \
		(@for /f %%i in ($(CODE_GEN_LST)) do 	         \
			(@if exist %%i	(del %%i))                                    \
		)

# *************************************************************************
#  Executable Targets
# *************************************************************************
$(BIN_FILE):
	@echo Linking $(strip $(NEWTARGNAME)) ...
	@perl tools\time.pl -n
	@echo $(LNKOPT) $(INITLIB)(bootarm.obj) > make\~libs.tmp
	@for /d %%i in ($(COMPLIST)) do \
		@if /I "%%i" NEQ "rompatch" \
		(echo $(COMPLIBDIR)\%%i.lib >> make\~libs.tmp)

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if /I "$(strip $(MAUI_IN_ROM))" EQU "TRUE" \
		echo $(CUS_MTK_LIB)\rompatch.lib(*) >> make\~libs.tmp
else
	@if /I "$(strip $(MAUI_IN_ROM))" EQU "TRUE" \
		echo $(COMPLIBDIR)\rompatch.lib(*) >> make\~libs.tmp
endif

ifneq ($(strip $(MTK_LIBS)),)
	@tools\strcmpex.exe abc abc e make\~libs_2.tmp $(MTK_LIBS)
	@perl tools\lnitem.pl make\~libs_2.tmp
	@type make\~libs_2.tmp >> make\~libs.tmp
	@del make\~libs_2.tmp
endif

ifneq ($(strip $(COMPOBJS)),)	
	@echo $(COMPOBJS)>> make\~libs.tmp
endif

	@if /I "$(strip $(MAUI_IN_ROM))" EQU "TRUE" \
		(echo $(ROM_IMG_FILE) >> make\~libs.tmp)

	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if /I %OS% EQU WINDOWS_NT \
		($(LINK) $(VIA) make\~sortedLibs.tmp > $(LOG) 2>&1) \
	else \
		($(LINK) $(VIA) make\~sortedLibs.tmp > $(LOG) )

   # -----------------------------
   # The size of the binary image depends on the available memory on the target
   # platform.
   # -----------------------------
	@echo Creating binary file $(BIN_FILE)
	$(BIN_CREATE) $(strip $(TARGDIR))\$(IMG_FILE) $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BIN_FILE)
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)		
ifneq ($(findstring JRD,$(call Upper,$(strip $(CUSTOMER)))),)
	$(BIN_CREATE) $(strip $(TARGDIR))\$(IMG_FILE) -m32 -output $(strip $(TARGDIR))\$(patsubst %.bin,%.m32,$(strip $(BIN_FILE)))
endif
endif
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(@if /I "$(strip $(UID_SUPPORT))" EQU "TRUE"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)\ROM) & \
		(@if /I "$(strip $(NAND_FLASH_BOOTING))" NEQ "TRUE" \
		  (@echo Combine resource images with original ROM) & \
		  ($(CATBIN) -p $(strip $(TARGDIR))\$(BIN_FILE) -s $(SCATTERFILE) -o $(strip $(TARGDIR))\$(strip $(BIN_FILE))\JTAG_$(BIN_FILE)) \
		) & \
		(@if exist $(strip $(FLASHFILE)) \
			   (perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FLASHFILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM $(call Upper,$(strip $(BIN_FILE))) $(VERNO) $(strip $(THE_MF)) $(MEMORY_CFG)) \
			else \
			   (perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(FLASH_CFG) $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM $(call Upper,$(strip $(BIN_FILE))) $(VERNO) $(strip $(THE_MF)) $(EMI_INFO)) \
		)

	@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
	   (@if /I "$(strip $(UID_SUPPORT))" EQU "TRUE"  .\tools\update_img.exe -sym $(strip $(TARGDIR))\$(TARGNAME).sym -path $(strip $(TARGDIR))\$(BIN_FILE)) & \
		(@if exist $(strip $(FLASHFILE)) \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(strip $(FLASHFILE)) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(BIN_FILE))) $(VERNO) $(strip $(THE_MF)) $(MEMORY_CFG)) \
			else \
			(perl .\tools\append2.pl $(strip $(TARGDIR))\$(TARGNAME).sym $(FLASH_CFG) $(strip $(TARGDIR))\$(BIN_FILE) $(call Upper,$(strip $(BIN_FILE))) $(VERNO) $(strip $(THE_MF)) $(EMI_INFO)) \
		)

	@if exist .\tools\NFBPack3rdROM.pl \
	(if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		(perl .\tools\NFBPack3rdROM.pl $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ $(strip $(THE_MF)) \
		) \
	else \
		(perl .\tools\NFBPack3rdROM.pl $(strip $(TARGDIR))\ $(strip $(THE_MF))))

ifdef FOTA_ENABLE
ifneq ($(strip $(FOTA_ENABLE)),NONE)
	@if exist tools\fota_ext_name.pl \
	   (perl tools\fota_ext_name.pl $(CUSTOM_FOTA_H) > make\~fota_ext.tmp)

	@for /f %%i in (make\~fota_ext.tmp) do \
	(@if not exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
	  (if exist tools\fota.exe \
            tools\fota.exe -ch $(strip $(TARGDIR))\$(strip $(BIN_FILE)) %%i))
endif
endif

   # -----------------------------
   # Nothting related binary directly
   # -----------------------------
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\__* (del /q $(strip $(TARGDIR))\$(strip $(BIN_FILE))\__*)
	@if exist $(strip $(TARGDIR))\__* (del /q $(strip $(TARGDIR))\__*)
	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM  \
		((@copy /y $(SCATTERFILE) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul) & \
		 (if exist $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) \
			(@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE)) del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE))) & \
			(copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul)) \
		) \
	else \
		(copy /y $(SCATTERFILE) $(strip $(TARGDIR)) > nul)

	@if exist $(strip $(MMI_FEATURES_FILE)) (copy /y $(strip $(MMI_FEATURES_FILE)) $(strip $(TARGDIR)) > nul)
	@if exist $(strip $(MMI_FEATURES_SWITCH_FILE)) (copy /y $(strip $(MMI_FEATURES_SWITCH_FILE)) $(strip $(TARGDIR)) > nul)
	@if exist $(strip $(THE_MF)) (copy /y $(strip $(THE_MF)) $(strip $(TARGDIR)) > nul)
	
# *************************************************************************
#  FOTA Targets
# *************************************************************************
fota: $(FOTA_BIN_FILE) done

del_fota:
ifneq ($(strip $(FOTA_ENABLE)),NONE)
	@-if not exist $(TARGDIR) (md $(TARGDIR))            	\
	else                                                 	\
		(@if exist $(strip $(TARGDIR))\$(FOTA_BIN_FILE) (del $(strip $(TARGDIR))\$(FOTA_BIN_FILE))) &  	\
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).elf (del $(strip $(TARGDIR))\$(FOTA_PREFIX).elf)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).lis (del $(strip $(TARGDIR))\$(FOTA_PREFIX).lis)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).sym (del $(strip $(TARGDIR))\$(FOTA_PREFIX).sym)) & \
		(@if exist $(strip $(TARGDIR))\$(FOTA_PREFIX).htm (del $(strip $(TARGDIR))\$(FOTA_PREFIX).htm)) & \
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))
endif

$(FOTA_BIN_FILE): del_fota
ifneq ($(strip $(FOTA_ENABLE)),NONE)

	-@if not exist $(COMPLOGDIR)	(md $(COMPLOGDIR))         \
	else (@if exist $(strip $(COMPLOGDIR))\fota.log (del /q $(strip $(COMPLOGDIR))\fota.log))

	-@if not exist $(PROJDIR)	(md $(PROJDIR))
	-@if not exist $(OBJSDIR)	(md $(OBJSDIR))

	@echo Generate FOTA CMM file ...
	@perl .\tools\fota_NocodeCMMAutoGen.pl themf=$(strip $(THE_MF)) verno=$(strip $(FOTA_PURE_VERNO)) \
	   > FOTA_$(strip $(CUSTOMER))_$(strip $(PLATFORM))_nocode.cmm

	-@if not exist $(strip $(OBJSDIR))\fota	(md $(strip $(OBJSDIR))\fota) \
	else	(@if exist $(strip $(OBJSDIR))\fota\*.obj (del $(strip $(OBJSDIR))\fota\*.obj))

	-@if not exist $(strip $(COMPLIBDIR))	(md $(COMPLIBDIR)) \
	else	(@if exist $(strip $(COMPLIBDIR))\fota.lib (del $(strip $(COMPLIBDIR))\fota.lib))

	-@if not exist $(RULESDIR) (md $(RULESDIR))	\
	else	(@if exist $(strip $(RULESDIR))\fota.dep (del $(strip $(RULESDIR))\fota.dep))

	@tools\make.exe -fmake\gsm2.mak -r -R CUSTOMER=$(strip $(CUSTOMER)) PROJECT=$(strip $(PROJECT)) fota.lib

	@echo Linking $(strip $(FOTA_PREFIX)) ...
	@perl tools\time.pl -n
	@echo $(FOTALNKOPT) > make\~libs.tmp
	@echo $(strip $(COMPLIBDIR))\fota.lib(*) >> make\~libs.tmp
	
	@echo $(LINK) $(VIA) make\~libs.tmp

	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if /I %OS% EQU WINDOWS_NT \
		($(LINK) $(VIA) make\~sortedLibs.tmp > $(LOG) 2>&1) \
	else \
		($(LINK) $(VIA) make\~sortedLibs.tmp > $(LOG) )

	@echo Creating binary file $(FOTA_BIN_FILE)
	@echo $(BIN_CREATE) $(strip $(TARGDIR))\$(FOTA_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(FOTA_BIN_FILE)
	$(BIN_CREATE) $(strip $(TARGDIR))\$(FOTA_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(FOTA_BIN_FILE)

endif

# *************************************************************************
#  BOOTLOADER Targets
# *************************************************************************
bootloader: $(BTLD_BIN_FILE) done

$(BTLD_BIN_FILE): gen_bl_verno
ifneq (,$(findstring $(strip $(PLATFORM)), $(strip $(NAND_FLASH_BOOTING_SUPPORT_PLATFORM))))
ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
	@-if not exist $(TARGDIR) (md $(TARGDIR))            	\
	else                                                 	\
		(@if exist $(strip $(TARGDIR))\$(BTLD_BIN_FILE) (del $(strip $(TARGDIR))\$(BTLD_BIN_FILE))) &  	\
		(@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).elf (del $(strip $(TARGDIR))\$(BTLD_PREFIX).elf)) & \
		(@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).lis (del $(strip $(TARGDIR))\$(BTLD_PREFIX).lis)) & \
		(@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).sym (del $(strip $(TARGDIR))\$(BTLD_PREFIX).sym)) & \
		(@if exist $(strip $(TARGDIR))\$(BTLD_PREFIX).htm (del $(strip $(TARGDIR))\$(BTLD_PREFIX).htm)) & \
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))

	-@if not exist $(COMPLOGDIR)	(md $(COMPLOGDIR))         \
	else (@if exist $(strip $(COMPLOGDIR))\bootloader.log (del /q $(strip $(COMPLOGDIR))\bootloader.log))

	-@if not exist $(PROJDIR)	(md $(PROJDIR))
	-@if not exist $(OBJSDIR)	(md $(OBJSDIR))

	-@if not exist $(strip $(OBJSDIR))\bootloader	(md $(strip $(OBJSDIR))\bootloader) \
	else	(@if exist $(strip $(OBJSDIR))\bootloader\*.obj (del $(strip $(OBJSDIR))\bootloader\*.obj))

	-@if not exist $(strip $(COMPLIBDIR))	(md $(COMPLIBDIR)) \
	else	(@if exist $(strip $(COMPLIBDIR))\bootloader.lib (del $(strip $(COMPLIBDIR))\bootloader.lib))

	-@if not exist $(RULESDIR) (md $(RULESDIR))	\
	else	(@if exist $(strip $(RULESDIR))\bootloader.dep (del $(strip $(RULESDIR))\bootloader.dep))

	@tools\make.exe -fmake\gsm2.mak -r -R CUSTOMER=$(strip $(CUSTOMER)) PROJECT=$(strip $(PROJECT)) bootloader.lib

	@echo Linking $(strip $(BTLD_PREFIX)) ...
	@perl tools\time.pl -n
	@echo $(BTLDLNKOPT) > make\~libs.tmp
	@echo $(strip $(COMPLIBDIR))\bootloader.lib(*) >> make\~libs.tmp

	@perl .\tools\sortLib.pl make\~libs.tmp $(strip $(COMPOBJS))
	@if /I %OS% EQU WINDOWS_NT \
		($(LINK) $(VIA) make\~sortedLibs.tmp > $(LOG) 2>&1) \
	else \
		($(LINK) $(VIA) make\~sortedLibs.tmp > $(LOG) )

	@echo Creating binary file $(BTLD_BIN_FILE)
	$(BIN_CREATE) $(strip $(TARGDIR))\$(BTLD_PREFIX).elf $(BIN_FORMAT) -output $(strip $(TARGDIR))\$(BTLD_BIN_FILE)

	@perl .\tools\bl_append.pl $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(BTLDVERNODIR))\bl_verno.c $(strip $(BTLD_SCATTERFILE)) $(strip $(THE_MF))

	@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM \
	  (if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE)) \
	     del $(strip $(TARGDIR))\$(strip $(BIN_FILE))\$(strip $(BTLD_BIN_FILE))) & \
	  copy /Y $(strip $(TARGDIR))\$(strip $(BTLD_BIN_FILE)) $(strip $(TARGDIR))\$(strip $(BIN_FILE)) > nul

endif
endif

# *************************************************************************
# Generate Bootloader VersionNo
# *************************************************************************
gen_bl_verno:
	@echo Generate BOOTLOADER CMM file ...
	@perl .\tools\bl_NocodeCMMAutoGen.pl plat=$(strip $(PLATFORM)) board_ver=$(strip $(BOARD_VER)) \
	   custom=$(strip $(CUSTOMER)) blver=$(strip $(BTLD_VERNO)) verno=$(strip $(PURE_VERNO)) \
	   > BOOTLOADER_$(strip $(CUSTOMER))_$(strip $(PLATFORM))_nocode.cmm

	@echo Generate BOOTLOADER version number ...
	@if not exist $(strip $(BTLDVERNODIR)) exit 0

	@if exist $(strip $(BTLDVERNODIR))\bl_verno.c (del $(strip $(BTLDVERNODIR))\bl_verno.c)

	@echo #include "kal_release.h" > $(strip $(BTLDVERNODIR))\bl_verno.c
	@echo const kal_uint32 CHECKSUM_SEED = $(strip $(BTLD_CHECKSUM_SEED)); >> $(strip $(BTLDVERNODIR))\bl_verno.c
	@echo const kal_int8 BootLDVerno[5] = "$(strip $(BTLD_VERNO))"; >> $(strip $(BTLDVERNODIR))\bl_verno.c

	@echo Generate BOOTLOADER .lis and .pth file ...
	@perl .\tools\bl_info.pl board_ver=$(strip $(BOARD_VER))

# *************************************************************************
# Generate VersionNo
# *************************************************************************
genverno:
	@echo Generate version number ... >> $(LOG)

	@if not exist $(VERNODIR) \
		md $(VERNODIR)

	@if exist $(strip $(VERNODIR))\verno.c (del $(strip $(VERNODIR))\verno.c)

	@echo #include "kal_release.h" > $(strip $(VERNODIR))\verno.c
	@echo kal_char* release_verno(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char verno_str[] = "$(strip $(VERNO))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return verno_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_hw_ver(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char hw_ver_str[] = "$(strip $(HW_VER))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return hw_ver_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* build_date_time(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_date_time_str[] = "$(strip $(BUILD_DATE_TIME))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_date_time_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_build(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_str[] = "$(strip $(BUILD))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* release_branch(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char build_branch_str[] = "$(strip $(BRANCH))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return build_branch_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo kal_char* software_summary(void) >> $(strip $(VERNODIR))\verno.c
	@echo { >> $(strip $(VERNODIR))\verno.c
	@echo    static kal_char software_comment_str[] = "$(strip $(SOFTWARE_INFO))"; >> $(strip $(VERNODIR))\verno.c
	@echo    return software_comment_str; >> $(strip $(VERNODIR))\verno.c
	@echo } >> $(strip $(VERNODIR))\verno.c

	@echo #define VERNO_STR "$(strip $(VERNO))" > $(strip $(VERNODIR))\verno.h

# *************************************************************************
# Generate Custom Information
# *************************************************************************
gencustominfo:

# For RF_MODULE = MT6129D
ifdef DRV_CUSTOM_TOOL_SUPPORT
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
ifeq ($(findstring MT6129D,$(strip $(RF_MODULE))),MT6129D)
	@if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
	(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_MT6129D.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_MT6129D.dws) \
	else \
	($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen.dws) \
	)
endif
endif
endif

# For RF_MODULE = MT6139E
ifdef DRV_CUSTOM_TOOL_SUPPORT
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
ifeq ($(findstring MT6139E,$(strip $(RF_MODULE))),MT6139E)
	@if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
	(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_MT6139E.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_MT6139E.dws) \
	else \
	($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen.dws) \
	)
endif
endif
endif

# For RF_MODULE != MT6129D or != MT6139E
ifdef DRV_CUSTOM_TOOL_SUPPORT
ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
ifeq ($(findstring MT6129D,$(strip $(RF_MODULE))),)
ifeq ($(findstring MT6139E,$(strip $(RF_MODULE))),)
	@if /I "$(strip  $(DRV_CUSTOM_TOOL_SUPPORT))" EQU "TRUE" \
		(if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
		(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen.dws) \
		) \
		)
endif
endif
endif
endif

	@if /I "$(strip  $(DRV_CUSTOM_TOOL_SUPPORT))" EQU "TRUE" \
	(if /I "$(strip $(BOARD_VER))" EQU "SUPERMAN29_DEMO_BB" \
		(if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
		(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_$(strip $(SUB_BOARD_VER)).dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen_$(strip $(SUB_BOARD_VER)).dws) \
		) \
		) \
	)

   # For rotated keypad on Tianyu28_demo landscape MMI
	@if /I "$(strip  $(DRV_CUSTOM_TOOL_SUPPORT))" EQU "TRUE" \
	(if /I "$(strip $(BOARD_VER))" EQU "TIANYU28_DEMO_BB" \
	(if /I "$(strip $(MAIN_LCD_SIZE))" EQU "320X240" \
		(if exist $(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe \
		(if exist $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen1.dws \
		   ($(FIXPATH)\custom\drv\Drv_Tool\DrvGen.exe $(FIXPATH)\custom\drv\misc_drv\$(strip $(BOARD_VER))\codegen\codegen1.dws) \
		) \
		) \
	) \
	)
ifneq ($(call Upper,$(strip $(PROJECT))),BASIC)
ifneq ($(strip $(call Upper,$(LEVEL))),LEVEL2_OBJ)
	@if exist $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\LcdResource\MainLcd$(strip $(MAIN_LCD_SIZE))\*.* $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_VERSION))\*.* > nul)
endif
endif
   # copy only for Neptune_Color
	@if /I "$(strip $(CUSTOMER))" EQU "NEPTUNE_COLOR" \
		(if exist $(FIXPATH)\plutommi\customer\CustResource\NEPTUNE_COLOR_MMI\Themecomponents.h \
		   (copy /y $(FIXPATH)\plutommi\Customer\CustResource\NEPTUNE_COLOR_MMI\Themecomponents.h $(FIXPATH)\plutommi\Customer\CustResource\PLUTO_MMI\Themecomponents.h > nul) \
		)


	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "CUSTOMER_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h > nul) \
		)


	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "PLUTO_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_features_switchPLUTO.h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\MMI_features_switchPLUTO.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		) 


	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "NEPTUNE_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\MMI_features_switchNEPTUNE.h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\MMI_features_switchNEPTUNE.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\MMI_features_switch$(strip $(CUSTOMER)).h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h) \
		)


       # Because MMIDIR\mmi\inc\mmi_features.h includes switch file,
       # but EMPTY_MMI , L1S , BASIC will not copy switch file
       # So copy an empty MMI_features_switchEMPTY.h to MMIDIR\mmi\inc for new mmi feature files architecture

ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h \
		(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h)
endif

ifeq ($(call Upper,$(PROJECT)),L1S)
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h \
		(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h)
endif

ifeq ($(call Upper,$(PROJECT)),BASIC)
	if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h \
		(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\EMPTY_MMI\MMI_features_switchEMPTY.h $(FIXPATH)\$(MMIDIR)\MMI\Inc\MMI_features_switch.h)
endif

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "CUSTOMER_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustMiscData$(strip $(MMI_BASE_PRJ)).c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustMiscData$(strip $(MMI_BASE_PRJ)).c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\CustMiscData$(strip $(CUSTOMER)).c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\CustMiscData$(strip $(CUSTOMER)).c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "PLUTO_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustMiscDataPLUTO.c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustMiscDataPLUTO.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "NEPTUNE_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\CustMiscDataNEPTUNE.c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\CustMiscDataNEPTUNE.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\CustMiscData.c) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "CUSTOMER_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustResDef$(strip $(MMI_BASE_PRJ)).h \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(MMI_BASE))\CustResDef$(strip $(MMI_BASE_PRJ)).h $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\CustResDef$(strip $(CUSTOMER)).h \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\CustResDef$(strip $(CUSTOMER)).h $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "PLUTO_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustResDefPLUTO.h \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\CustResDefPLUTO.h $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h) \
		)

	@if /I "$(NEED_COPY_MMIFEATURE)" EQU "NEPTUNE_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\CustResDefNEPTUNE.h \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\CustResDefNEPTUNE.h $(FIXPATH)\$(MMIDIR)\Customer\CustomerInc\CustResDef.h) \
		)

   # clean font related files in $(FIXPATH)\$(MMIDIR)\Customer\CustResource
ifneq ($(call Upper,$(PROJECT)),BASIC)
ifneq ($(call Upper,$(PROJECT)),L1S)
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c \
		(del $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c)

	@if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_*.h \
		(if exist $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_MMIProp.h \
			(copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_MMIProp.h $(FIXPATH)\make) \
		) & \
		(del $(FIXPATH)\$(MMIDIR)\Customer\CustResource\L_*.h) & \
		(if exist $(FIXPATH)\make\L_MMIProp.h \
			(copy /y $(FIXPATH)\make\L_MMIProp.h $(FIXPATH)\$(MMIDIR)\Customer\CustResource) & \
			(del $(FIXPATH)\make\L_MMIProp.h) \
		)
endif
endif
endif

	@if $(call Upper,$(PROJECT)) NEQ BASIC ( \
	if exist $(strip $(FONTRES_PATH_MTK))\FontRes.c \
		   (copy /y $(strip $(FONTRES_PATH_MTK))\FontRes.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c > nul) \
		   )

	@if $(call Upper,$(PROJECT)) NEQ BASIC ( \
	if exist $(strip $(FONTRES_PATH_CUST))\FontRes.c \
		   (copy /y $(strip $(FONTRES_PATH_CUST))\FontRes.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\FontRes.c > nul) \
		   )

	@if /I "$(MMI_BASE)" EQU "PLUTO_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\PLUTO_MMI\ref_list.txt \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\PLUTO_MMI\ref_list.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\ref_list.txt \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\ref_list.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt) \
		)

	@if /I "$(MMI_BASE)" EQU "NEPTUNE_MMI" \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\NEPTUNE_MMI\ref_list.txt \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\NEPTUNE_MMI\ref_list.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt) \
		) & \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\ref_list.txt \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\ref_list.txt $(FIXPATH)\$(MMIDIR)\Customer\CustResource\ref_list.txt) \
		)

gencustomlists: gencustominfo
   # If module "custom" is released to customer with .lib only, don't run custominfo.pl
	@if /I "$(CUSTOM_EXIST)" EQU "TRUE" \
		(@echo Generate customization information ... >> $(LOG)) & \
		(@if /I $(PROJECT) NEQ BASIC \
			(@if /I $(PROJECT) NEQ L1S \
			   (@if /I $(CUSTOM_RELEASE) EQU FALSE (perl tools\gencust.pl $(strip $(THE_MF)))) \
			) \
		) & \
		(perl tools\custominfo.pl $(strip $(THE_MF)) $(strip $(THE_OP_CUSTOM_LIS)) $(strip $(OPTR_PATH)))

	@if /I "$(strip $(MAUI_IN_ROM))" EQU "TRUE" \
		(@if exist make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER))\rompatch.* \
			(xcopy /Y make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER)) make\rompatch > nul 2>&1) \
		else \
			(echo Directory make\rompatch\$(strip $(PLATFORM))\$(strip $(CHIP_VER)) Does NOT exist.) \
		)

# *************************************************************************
# Check MMI Feature Files
# *************************************************************************
mmi_feature_check: gencustominfo gen_infolog
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) MMI_features.h MMI_features_switch.h plutommi\mmi\inc)
endif
else
ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) MMI_features.h MMI_features_switch.h lcmmi\mmi\inc)
endif
endif
endif

# *************************************************************************
# Check MMI Obj Values
# *************************************************************************
mmi_obj_check: sysgen mmi_feature_check
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
	@if exist tools\objcheck.pl \
		(perl tools\objcheck.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)))
endif
endif
endif

# *************************************************************************
# Check operator setting Files
# *************************************************************************
operator_check_lite: gencustominfo gen_infolog
ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
	@if exist tools\operator_check.pl \
	   (perl tools\operator_check.pl $(strip $(CUSTOMER)) $(strip $(call Upper,$(PROJECT))) $(strip $(OPTR_WARNING_DEF)) $(firstword $(strip $(CC))) $(strip $(VIA)))
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) operator_mmi.h operator_mmi.h $(strip $(FIXPATH))\operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi)
  endif
endif

# *************************************************************************
# Check operator setting Files (An independent target)
# *************************************************************************
operator_check: gencustominfo gen_infolog
ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
	@if exist tools\operator_check.pl \
	   (perl tools\operator_check.pl $(strip $(CUSTOMER)) $(strip $(call Upper,$(PROJECT))) $(strip $(OPTR_WARNING_DEF)) $(firstword $(strip $(CC))) $(strip $(VIA)))
	@if exist tools\mmi_feature_check.pl \
	   (perl tools\mmi_feature_check.pl $(strip $(CUSTOMER)) $(firstword $(strip $(CC))) $(strip $(VIA)) operator_mmi.h operator_mmi.h $(strip $(FIXPATH))\operator\$(strip $(word 1,$(subst _, ,$(OPTR_SPEC))))\$(strip $(word 2,$(subst _, ,$(OPTR_SPEC))))\plutommi)
  endif
endif

# *************************************************************************
# Check if system drive space is enough or not
# *************************************************************************
cksysdrv:
   # If building for basic, l1s, don't run cksysdrv.pl
   # If module "custom" is released to customer with .lib only, don't run cksysdrv.pl
   # If NAND_FLASH_BOOTING is TRUE, don't run cksysdrv.pl
   # If __FS_QM_SUPPORT__ is off, don't run cksysdrv.pl
   # If FEATURE_OVERLOAD is TRUE, don't run cksysdrv.pl
ifneq ($(strip $(call Upper,$(PROJECT))),L1S)
ifneq ($(strip $(call Upper,$(PROJECT))),BASIC)
ifeq ($(strip $(CUSTOM_EXIST)),TRUE)
ifneq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
ifeq ($(findstring __FS_QM_SUPPORT__,$(COM_DEFS)),__FS_QM_SUPPORT__)
ifneq ($(strip $(FEATURE_OVERLOAD)),TRUE)

	@echo checking system drive space ...
	@tools\strcmpex.exe def def e make\~customIncDef.tmp $(foreach def,$(COM_DEFS),-D$(def))
	@echo -D__NULL_DEF__ >> make\~customIncDef.tmp
	@tools\strcmpex.exe inc inc e make\~customInc.tmp $(foreach inc,$(COMMINCDIRS),-I$(inc))
	@echo. > ~nvram_tmp.c
	@if exist nvram\src\nvram_data_items.c \
		(@type make\~customInc.tmp >> make\~nvramIncDef.tmp) & \
		(for /F %%i in (make\nvram\nvram.def) do \
			(echo -D%%i >> make\~nvramIncDef.tmp) \
		) & \
		(for /F %%i in (make\nvram\nvram.inc) do \
			(echo -I%%i >> make\~nvramIncDef.tmp) \
		) & \
		($(CC) $(VIA) make\~nvramIncDef.tmp -E nvram\src\nvram_data_items.c >> ~nvram_tmp.c)



	@if exist custom\common\$(strip $(MMI_BASE))\nvram_common_config.c \
		(@if exist custom\app\$(strip $(BOARD_VER))\nvram_user_config.c \
			(@if exist custom\common\fs_quota.c \
				(@type make\~customInc.tmp >> make\~customIncDef.tmp) & \
				(for /F %%i in (make\custom\custom.def) do \
					(echo -D%%i >> make\~customIncDef.tmp) \
				) & \
				(for /F %%i in (make\custom\custom.inc) do \
					(echo -I%%i >> make\~customIncDef.tmp) \
				) & \
				($(CC) $(VIA) make\~customIncDef.tmp -E custom\common\fs_quota.c > ~fs_quota_tmp.c) & \
				($(CC) $(VIA) make\~customIncDef.tmp -E custom\app\$(strip $(BOARD_VER))\nvram_user_config.c >> ~nvram_tmp.c) & \
				($(CC) $(VIA) make\~customIncDef.tmp -E custom\common\$(strip $(MMI_BASE))\nvram_common_config.c >> ~nvram_tmp.c) & \
				(@echo #include "custom_MemoryDevice.h" > make\~flash_cfg.c) & \
				(@echo #include "custom_EMI.h" >> make\~flash_cfg.c) & \
				(@echo int allocated_fat_space = ALLOCATED_FAT_SPACE; >> make\~flash_cfg.c) & \
				(@echo int partition_sectors = PARTITION_SECTORS; >> make\~flash_cfg.c) & \
				($(CC) $(VIA) make\~customIncDef.tmp -E make\~flash_cfg.c > ~flash_cfg_tmp.c) \
			) \
		)
ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
	perl tools\ckSysDrv.pl ~flash_cfg_tmp.c ~fs_quota_usage.log ~nvram_tmp.c ~nvram_lid_size.log $(CUSTOM_EMI_H)> $(strip $(COMPLOGDIR))\ckSysDrv.log
	@if ERRORLEVEL 1 exit 1
endif
ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),FALSE)
	perl tools\ckSysDrv.pl ~flash_cfg_tmp.c ~fs_quota_usage.log ~nvram_tmp.c ~nvram_lid_size.log > $(strip $(COMPLOGDIR))\ckSysDrv.log
	@if ERRORLEVEL 1 exit 1
endif
 
endif
endif
endif
endif
endif
endif

# *************************************************************************
# Clean 3 emi setting related files
# *************************************************************************
emiclean:
	@echo Clean EMI settings
	-@if exist $(strip $(FLASH_OPTIONS_HDR)) (del $(strip $(FLASH_OPTIONS_HDR)))
	-@if exist $(strip $(CUSTOM_EMI_H)) (del $(strip $(CUSTOM_EMI_H)))
	-@if exist $(strip $(CUSTOM_EMI_C)) (del $(strip $(CUSTOM_EMI_C)))
	-@if exist $(strip $(SWITCH_CLK_C)) (del $(strip $(SWITCH_CLK_C)))

# *************************************************************************
# check scatter file and memory device consistency
# *************************************************************************
ckscatter: $(strip $(CUSTOM_EMI_H)) $(SCATTERFILE)
	@if exist $(FIXPATH)\tools\ckScatter.pl \
		   (perl $(FIXPATH)\tools\ckScatter.pl $(SCATTERFILE) $(strip $(THE_MF)) $(strip $(CUSTOM_EMI_H)))
	
# *************************************************************************
# Generate emi settings based on configurations in custom_MemoryDevice.h
# *************************************************************************
$(strip $(FLASH_OPTIONS_HDR)): $(strip $(MEMORY_DEVICE_HDR)) $(strip $(MEMORY_DEVICE_LST)) $(strip $(EMI_GENERATOR))
$(strip $(CUSTOM_EMI_H)): $(strip $(MEMORY_DEVICE_HDR)) $(strip $(MEMORY_DEVICE_LST)) $(strip $(EMI_GENERATOR))
$(strip $(CUSTOM_EMI_C)): $(strip $(MEMORY_DEVICE_HDR)) $(strip $(MEMORY_DEVICE_LST)) $(strip $(EMI_GENERATOR))
$(strip $(SWITCH_CLK_C)): $(strip $(MEMORY_DEVICE_HDR)) $(strip $(MEMORY_DEVICE_LST)) $(strip $(EMI_GENERATOR))
	@echo Clean EMI settings
	-@if exist $(strip $(FLASH_OPTIONS_HDR)) (perl tools\emidel.pl $(strip $(FLASH_OPTIONS_HDR)))
	-@if exist $(strip $(CUSTOM_EMI_H)) (perl tools\emidel.pl $(strip $(CUSTOM_EMI_H)))
	-@if exist $(strip $(CUSTOM_EMI_C)) (perl tools\emidel.pl $(strip $(CUSTOM_EMI_C)))
	-@if exist $(strip $(SWITCH_CLK_C)) (perl tools\emidel.pl $(strip $(SWITCH_CLK_C)))

#emigen: $(strip $(FLASH_OPTIONS_HDR)) $(strip $(CUSTOM_EMI_H)) $(strip $(CUSTOM_EMI_C)) $(strip $(SWITCH_CLK_C))
emigen:
#*************************************************************************
# 2009.07.23 added by hongzhe.liu for custom_MemoryDevice.h generate automation
	@echo [Hongzhe.Liu] .... Generate custom_MemoryDevice.h
	@if exist $(strip $(MEMORY_DEVICE_HDR_GENERATOR)) \
		(perl $(strip $(MEMORY_DEVICE_HDR_GENERATOR)) $(strip $(MEMORY_DEVICE_HDR))  $(strip $(MEMORY_DEVICE_TYPE))  $(strip $(MEMORY_DEVICE_ID)))
#*************************************************************************

	@echo Generate EMI settings
	@if exist $(strip $(EMI_GENERATOR)) \
		(perl $(strip $(EMI_GENERATOR)) $(strip $(PLATFORM)) $(strip $(MCU_CLOCK)) $(strip $(MEMORY_DEVICE_HDR)) $(strip $(MEMORY_DEVICE_LST))) 2>&1

mcp_check:
ifneq ($(call Upper,$(strip $(LEVEL))),VENDOR)
	@if not exist $(COMPLOGDIR)	(md $(COMPLOGDIR))
	@echo perl .\tools\emiMCPcheck.pl $(strip $(PLATFORM)) $(call Upper,$(strip $(PROJECT))) $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER))
	@echo $(strip $(COMPLOGDIR))\mcp_check.log
	@perl .\tools\emiMCPcheck.pl $(call Upper,$(strip $(PLATFORM))) $(call Upper,$(strip $(PROJECT))) $(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER)) > $(strip $(COMPLOGDIR))\mcp_check.log
endif
	
# *************************************************************************
# Generate custom\system\BB\* base on makefile and EMI.h
# *************************************************************************
sysgen: emigen mcp_check
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@if exist $(strip $(SCATTERFILE)) (perl tools\emidel.pl $(strip $(SCATTERFILE)))
	@if exist $(FIXPATH)\tools\scatGen.pl \
			(perl $(FIXPATH)\tools\scatGen.pl $(SCATTERFILE) $(strip $(THE_MF)) $(strip $(CUSTOM_EMI_H)))
else
  ifeq ($(strip $(SYSGEN_ENABLE)),TRUE)
		@if exist $(strip $(SCATTERFILE)) (perl tools\emidel.pl $(strip $(SCATTERFILE)))
		@if exist $(FIXPATH)\tools\scatGen.pl \
			(perl $(FIXPATH)\tools\scatGen.pl $(SCATTERFILE) $(strip $(THE_MF)) $(strip $(CUSTOM_EMI_H)))
  endif
endif
	@if exist $(FIXPATH)\tools\sysGen1.pl \
		(perl $(FIXPATH)\tools\sysGen1.pl $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(strip $(THE_MF)))
	@if exist $(FIXPATH)\tools\sysGen2.pl \
		(perl $(FIXPATH)\tools\sysGen2.pl $(FIXPATH)\custom\system\$(strip $(BOARD_VER)) $(SCATTERFILE))

# *************************************************************************
# Generate cmm files for different SUB_BOARD_VER
# *************************************************************************
ifeq ($(call Upper,$(strip $(LEVEL))),VENDOR)
cmmgen:
else
cmmgen: sysgen
endif
ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
	@echo Generate cmm files
	@if exist mtk_tools\NocodeCMMAutoGen.pl  \
		((perl mtk_tools\NocodeCMMAutoGen.pl $(strip $(THE_MF)) $(strip $(FLASH_OPTIONS_HDR)) $(FIXPATH)\$(strip $(TARGNAME))_nocode.cmm) & \
		 (perl mtk_tools\NocodeCMMAutoGen.pl -ps1 $(strip $(THE_MF)) $(strip $(FLASH_OPTIONS_HDR)) $(FIXPATH)\$(strip $(TARGNAME))_MTK_only.cmm))
	@if exist mtk_tools\FastDLCMMAutoGen.pl  \
		(perl mtk_tools\FastDLCMMAutoGen.pl $(strip $(THE_MF)) $(strip $(FLASH_OPTIONS_HDR)) $(FIXPATH)\Fast_DL\$(strip $(TARGNAME)).cmm)
endif

# *************************************************************************
# Library Targets
# *************************************************************************
libs: cleanlib startbuildlibs $(COMPLIBLIST)

startbuildlibs:
	@echo Start to build $(COMPLIBLIST)

cleanlib:
   # can be moved to cleanlog
	-@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (del $(strip $(TARGDIR))\$(strip $(NEWTARGNAME)).bin)
	-@if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).elf)
	-@if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).lis)
	-@if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).sym)
	-@if exist $(strip $(TARGDIR))\$(TARGNAME).htm (del $(strip $(TARGDIR))\$(strip $(TARGNAME)).htm)

	@echo Clean $(COMPLIBLIST) under $(strip $(COMPLIBDIR))
	-@for /d %%i in ($(COMPLIBLIST)) do \
		(@if exist $(strip $(COMPLIBDIR))\%%i (del $(strip $(COMPLIBDIR))\%%i))

%.lib:
	@echo Beginning $* component build process... >> $(LOG)
	@perl tools\time.pl
	@echo Building $*
	@echo                     LOG: $(strip $(COMPLOGDIR))\$*.log

	@if not exist $(strip $(OBJSDIR))\$* (md $(strip $(OBJSDIR))\$*)
	@if $(ACTION)==new if exist $(strip $(RULESDIR))\$*.dep del /q /f $(strip $(RULESDIR))\$*.dep
	@if $(ACTION)==bm_new if exist $(strip $(RULESDIR))\$*.dep del /q /f $(strip $(RULESDIR))\$*.dep
	@if not $(ACTION)==remake if not exist $(strip $(RULESDIR))\$*_dep md $(strip $(RULESDIR))\$*_dep
	@if $(ACTION)==new if exist $(strip $(RULESDIR))\$*_dep\*.det del /f /q $(strip $(RULESDIR))\$*_dep\*.det
	@if $(ACTION)==bm_new if exist $(strip $(RULESDIR))\$*_dep\*.det del /f /q $(strip $(RULESDIR))\$*_dep\*.det
	@if exist *.via del /f /q *.via
	@if exist *.d del /f /q *.d

   # -----------------------------
   # Write the required script variables to the config file
   # and invoke the component build script.
   # -----------------------------
	@echo FIXPATH 	= $(strip $(FIXPATH))>  make\~compbld.tmp
	@echo OBJSDIR  = $(strip $(OBJSDIR))>> make\~compbld.tmp
	@echo RULESDIR	= $(strip $(RULESDIR))>> make\~compbld.tmp
	@echo TARGDIR 	= $(strip $(TARGDIR))>> make\~compbld.tmp
	@echo PROJDIR 	= $(strip $(PROJDIR))>> make\~compbld.tmp
	@echo PLATFORM = $(strip $(call Upper,$(PLATFORM)))>> make\~compbld.tmp
	@echo BOARD_VER = $(strip $(call Upper,$(BOARD_VER)))>> make\~compbld.tmp
	@echo CHIP_VER = $(strip $(call Upper,$(CHIP_VER)))>> make\~compbld.tmp
	@echo MCU_DCM = $(strip $(call Upper,$(MCU_DCM)))>> make\~compbld.tmp
	@echo DEBUG_SAVE_CUR_THREAD	= $(strip $(DEBUG_SAVE_CUR_THREAD))>> make\~compbld.tmp
	@echo PRODUCTION_RELEASE   	= $(strip $(PRODUCTION_RELEASE))>> make\~compbld.tmp
	@echo APCSINT 	= $(strip $(APCSINT))>> make\~compbld.tmp
	@echo LIB     	= $(strip $(LIB))>> make\~compbld.tmp
	@echo CC	    	= $(strip $(CC))>> make\~compbld.tmp
	@echo CC32	 	= $(strip $(CC32))>> make\~compbld.tmp
	@echo CPPC	    	= $(strip $(CPPC))>> make\~compbld.tmp
	@echo CPPC32	 	= $(strip $(CPPC32))>> make\~compbld.tmp
	@echo CFLAGS 	= $(strip $(CFLAGS))>> make\~compbld.tmp
	@echo CPLUSFLAGS = $(strip $(CPLUSFLAGS))>> make\~compbld.tmp
	@echo VIA = $(strip $(VIA))>> make\~compbld.tmp
	@echo SWDBG_SUPPORT = $(strip $(SWDBG_SUPPORT))>> make\~compbld.tmp
	@echo UID_SUPPORT    = $(strip $(UID_SUPPORT))>> make\~compbld.tmp
	@echo RTOS    = $(strip $(RTOS))>> make\~compbld.tmp
	@echo CUS_MTK_LIB    = $(strip $(CUS_MTK_LIB))>> make\~compbld.tmp
	@echo FOTA_ENABLE    = $(strip $(FOTA_ENABLE))>> make\~compbld.tmp
	@echo LCD_MODULE    = $(strip $(LCD_MODULE))>> make\~compbld.tmp
	@echo JPG_DECODE = $(strip $(JPG_DECODE))>> make\~compbld.tmp
	@echo JPG_ENCODE = $(strip $(JPG_ENCODE))>> make\~compbld.tmp
	-@if /I \"$(strip $(DEBUG_MODULES))\" NEQ \"\" \
		(@for %%i in ($(DEBUG_MODULES)) do \
			(@if "%%i"=="$*" \
				((echo CFLAGS 	= $(strip $(CFLAGS)) -g -gtp>> make\~compbld.tmp) & \
				(echo CPLUSFLAGS = $(strip $(CPLUSFLAGS)) -g -gtp>> make\~compbld.tmp)) \
			else	\
				(@if /I "%%i" EQU "ALL" \
					((echo CFLAGS 	= $(strip $(CFLAGS)) -g -gtp>> make\~compbld.tmp) & \
					(echo CPLUSFLAGS = $(strip $(CPLUSFLAGS)) -g -gtp>> make\~compbld.tmp)))))

	-@if /I \"$(strip $(NON_DEBUG_MODULES))\" NEQ \"\" \
		(@for %%i in ($(NON_DEBUG_MODULES)) do \
			(@if "%%i"=="$*" \
				((echo CFLAGS 	= $(subst -g,,$(subst -gtp,,$(strip $(CFLAGS)))) >> make\~compbld.tmp) & \
				(echo CPLUSFLAGS = $(subst -g,,$(subst -gtp,,$(strip $(CPLUSFLAGS)))) >> make\~compbld.tmp)) \
			else	\
				(@if /I "%%i" EQU "ALL" \
					((echo CFLAGS 	= $(subst -g,,$(subst -gtp,,$(strip $(CFLAGS)))) >> make\~compbld.tmp) & \
					(echo CPLUSFLAGS = $(subst -g,,$(subst -gtp,,$(strip $(CPLUSFLAGS)))) >> make\~compbld.tmp)))))
#	@if /I "$*" EQU "obigo05alib" \
#	  (echo CFLAGS = $(subst -g,-g -gtp,$(strip $(CFLAGS))) >> make\~compbld.tmp & \
#	   echo CPLUSFLAGS = $(subst -g,-g -gtp,$(strip $(CPLUSFLAGS))) >> make\~compbld.tmp)
	@echo ASM	  	= $(strip $(ASM))>> make\~compbld.tmp
	-@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS))>> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
	else \
		(echo AFLAGS	= $(strip $(AFLAGS))>> make\~compbld.tmp)
	
	@for /F "tokens=3" %%i in ($(strip $(FIXPATH))\custom\system\$(strip $(call Upper,$(BOARD_VER)))\custom_MemoryDevice.h) do \
	((@if /I "%%i" EQU "NOR_LPSDRAM_MCP"   \
		(@if /I "$*" EQU "BOOTLOADER" \
		((echo AFLAGS	= $(strip $(BL_AFLAGS)) -pd "_NOR_LPSDRAM_MCP_ SETL {TRUE}">> make\~compbld.tmp) & \
		(echo ACTION	= UPDATE>> make\~compbld.tmp)) \
		else \
		(echo AFLAGS	= $(strip $(AFLAGS)) -pd "_NOR_LPSDRAM_MCP_ SETL {TRUE}">> make\~compbld.tmp))))
	
	@echo SWDBG_SUPPORT = $(strip $(SWDBG_SUPPORT))>> make\~compbld.tmp
	@echo MCUROM_SUPPORT = $(strip $(MCUROM_SUPPORT))>> make\~compbld.tmp
	@echo NAND_FLASH_BOOTING = $(strip $(NAND_FLASH_BOOTING))>> make\~compbld.tmp
	@echo NOR_FLASH_BOOTING = $(strip $(NOR_FLASH_BOOTING))>> make\~compbld.tmp
	@echo SECURE_SUPPORT = $(strip $(SECURE_SUPPORT))>> make\~compbld.tmp
	@echo ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT = $(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT))>> make\~compbld.tmp
	@echo L1_WCDMA = $(strip $(L1_WCDMA))>> make\~compbld.tmp
	@echo L1_3GSOLUTION = $(strip $(L1_3GSOLUTION))>> make\~compbld.tmp		
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  INCDIRS  = $(strip $(COMMINCDIRS))
	@type make\~compbld_2.tmp >> make\~compbld.tmp
	@del  make\~compbld_2.tmp
	@tools\strcmpex.exe abc abc e make\~compbld_2.tmp  DEFINES  = $(strip $(COM_DEFS))
	@type make\~compbld_2.tmp >> make\~compbld.tmp
	@del  make\~compbld_2.tmp
	@echo MMIDIR   = $(strip $(MMIDIR))>> make\~compbld.tmp
	@if not %0$(COMPILER)==%0 echo COMPILER = $(COMPILER)>> make\~compbld.tmp
	@if not %0$(RVCT_MULTI_FILE)==%0 echo RVCT_MULTI_FILE = $(RVCT_MULTI_FILE)>> make\~compbld.tmp
	@if exist $(FIXPATH)\make\$*\master echo MASTER = TRUE>> make\~compbld.tmp
	@if exist $(FIXPATH)\make\$*\master echo MASTER = TRUE
	@if exist $(FIXPATH)\make\$*\slave echo SLAVE = TRUE>> make\~compbld.tmp
	@if exist $(FIXPATH)\make\$*\slave echo SLAVE = TRUE
ifdef DUAL_MODE_SUPPORT
	@echo DUAL_MODE_SUPPORT = $(strip $(DUAL_MODE_SUPPORT))>> make\~compbld.tmp
endif
	@echo #Huyanwei BM_NEW=$(BM_NEW) >> make\~compbld.tmp
	@echo #Huyanwei tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* -out $(strip $(COMPLOGDIR))\$*.log >> make\~compbld.tmp	

#@echo tools\make.exe -fmake\comp.mak -r -R COMPONENT=$* ... $(strip $(COMPLOGDIR))\$*.log
	@if /I %OS% EQU WINDOWS_NT \
		(if /I $(BM_NEW) EQU TRUE \
			(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* > $(strip $(COMPLOGDIR))\$*.log 2>&1 ) \
		else \
			(tools\make.exe -fmake\comp.mak -r -R $(strip $(CMD_ARGU)) COMPONENT=$* > $(strip $(COMPLOGDIR))\$*.log 2>&1) \
		) \
	else \
		(if /I $(BM_NEW) EQU TRUE \
			(tools\make.exe -fmake\comp.mak -k -r -R $(strip $(CMD_ARGU)) COMPONENT=$* > $(strip $(COMPLOGDIR))\$*.log) \
		else \
			(tools\make.exe -fmake\comp.mak -r -R $(strip $(CMD_ARGU)) COMPONENT=$* > $(strip $(COMPLOGDIR))\$*.log) \
		)
	@type $(strip $(COMPLOGDIR))\$*.log >> $(LOG)
	@perl .\tools\chk_lib_err_warn.pl $(strip $(COMPLOGDIR))\$*.log

# *************************************************************************
# Scan Target For Scanning Header Dependencies
# *************************************************************************
scan: cleandep $(COMP_DEP_LIST)
	@echo Scanning Header Dependencies finished.

cleandep:
	@echo clean *.dep
	-@for /d %%i in ($(COMPSCANLIST)) do \
		(@if exist $(strip $(RULESDIR))\%%i.dep (del $(strip $(RULESDIR))\%%i.dep))


%.dep:
	echo scan $* dependency. >> $(LOG)

	@echo $(foreach inc,$(COMMINCDIRS),-I$(inc))> make\~scanopt.tmp
	-@if exist $(strip $(FIXPATH))\make\$*\$*.inc \
		(for /f %%i in ($(strip $(FIXPATH))\make\$*\$*.inc) do \
			(echo -I%%i>>make\~scanopt.tmp) \
		)

	@echo $(foreach def,$(COM_SCANDEFS_NEW),$(def))>> make\~scanopt.tmp
	-@if exist $(strip $(FIXPATH))\make\$*\$*.def \
		(for /f %%i in ($(strip $(FIXPATH))\make\$*\$*.def) do \
			(echo -D%%i >>make\~scanopt.tmp) \
		)

	@for /f "skip=2" %%i in ('find /I ".c" $(strip $(FIXPATH))\make\$*\$*.lis') do \
		($(CC) $(VIA) make\~scanopt.tmp -M -W %%i >> $(strip $(FIXPATH))\make\~$*_dep.tmp 2>>$(LOG)) & \
		(if ERRORLEVEL 1 \
		   (@echo scanning dependency error: $(LOG)) & \
		   (exit 1) \
		)

	@perl .\tools\pack_dep.pl $(strip $(FIXPATH))\make\~$*_dep.tmp > $(strip $(RULESDIR))\$*.dep

	@echo $(strip $(RULESDIR))\$@

# *************************************************************************
# Standard "cleanall" Target
# *************************************************************************
cleanall:
   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(CUSTOMER)
   #     +-$(PROJECT)
   #        +-$(PLATFORM)r    - Dependency directory
   #        +-$(PLATFORM)o    - Object directory
   #           +-$(COMPLIST)  - Component object directory
   #           +-lib          - Component libraries directory
   # -----------------------------
	@echo Cleaning directories under $(strip $(PROJDIR)) ...
	@if not exist $(BUILDDIR)  \
		md $(BUILDDIR)

	@-if not exist $(TARGDIR)                             \
		(md $(TARGDIR))                                   	\
	else                                                 	\
		(@if /I %OS% EQU Windows_NT                      	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin \
				(del /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) & 	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin \
			   (rd /S /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) 	\
		else                                              	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin \
				(del $(strip $(TARGDIR))\$(NEWTARGNAME).bin))) &  	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).elf \
			(del $(strip $(TARGDIR))\$(TARGNAME).elf)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).lis \
			(del $(strip $(TARGDIR))\$(TARGNAME).lis)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).sym \
			(del $(strip $(TARGDIR))\$(TARGNAME).sym)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).htm \
			(del $(strip $(TARGDIR))\$(TARGNAME).htm)) &      	\
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log))

	-@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))         \
	else                          \
		(@if exist $(strip $(COMPLOGDIR))\*.log (del /q $(strip $(COMPLOGDIR))\*.log))

   # -----------------------------
   # Remove TST database files
   # -----------------------------
	-@if /I $(NEED_RM_TSTDB) EQU TRUE						\
		(@if exist $(strip $(TST_DB))\msglog_db\pri.db (del $(strip $(TST_DB))\msglog_db\pri.db)) &   	\
		(@if exist $(strip $(TST_DB))\pstrace_db\*.ptr (del $(strip $(TST_DB))\pstrace_db\*.ptr)) &   	\
		(@if exist $(strip $(TST_DB))\msglog_db\BInfo (del $(strip $(TST_DB))\msglog_db\BInfo)) &   	\
		(@if exist $(strip $(TST_DB))\pstrace_db\BPInfo (del $(strip $(TST_DB))\pstrace_db\BPInfo)) &   	\
		(@if exist $(strip $(TST_DB))\l1trace_db\BPLInfo (del $(strip $(TST_DB))\l1trace_db\BPLInfo)) &	\
		(@if exist $(strip $(TST_DB))\BPLVInfo (del $(strip $(TST_DB))\BPLVInfo)) &   				\
		(@if exist $(strip $(TST_DB))\pstrace_db\ps_trace.h (del $(strip $(TST_DB))\pstrace_db\ps_trace.h))

	-@if exist $(CODE_GEN_LST)						         \
		(copy $(CODE_GEN_LST) make\~codegenlis.tmp) &   \
		(@for /f %%i in ($(CODE_GEN_LST)) do 	         \
			(@if exist %%i (del %%i))                                    \
		) &							 	         \
		(@if exist $(CODE_GEN_LST) (del $(CODE_GEN_LST)))

	@if not exist $(PROJDIR)   \
		(md $(PROJDIR))


	-@if not exist $(RULESDIR)  									\
		(md $(RULESDIR))												\
	else																	\
		(@echo Cleaning directories under $(RULESDIR)) &	\
		(@if exist $(strip $(RULESDIR))\*.dep (del $(strip $(RULESDIR))\*.dep))


	@if not exist $(OBJSDIR)   \
		(md $(OBJSDIR))

   # -----------------------------
   # Check component directories
   # -----------------------------
	-@for /d %%i in ($(COMPLIST)) do 			\
		(@if not exist $(strip $(OBJSDIR))\%%i	\
			(md $(strip $(OBJSDIR))\%%i)			\
		else												\
			(@echo Cleaning object files under %%i) & \
			(@if exist $(strip $(OBJSDIR))\%%i\*.obj (del $(strip $(OBJSDIR))\%%i\*.obj)))


	-@if not exist $(strip $(COMPLIBDIR))	\
		(md $(COMPLIBDIR)) 						\
	else												\
		(@echo Cleaning lib files under $(COMPLIBDIR)) & \
		(@if exist $(strip $(COMPLIBDIR))\*.lib (del $(strip $(COMPLIBDIR))\*.lib))

cleanbin:
	@if exist $(INFOLOG) \
		(@if exist ps\mcddll (copy /y $(INFOLOG) ps\mcddll > nul))

	-@if exist $(strip $(TARGDIR))\$(strip $(BIN_FILE))\ROM          \
		(rd /s /q $(strip $(TARGDIR))\$(BIN_FILE))


# *************************************************************************
# Standard "cleanlog" Target
# *************************************************************************
cleanlog:
	@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))

	@echo Start logging > $(LOG)

	@tools\strcmpex.exe def def e make\~def.tmp $(foreach def,$(COM_DEFS),$(def))
	@perl tools\lnitem.pl make\~def.tmp

	@if exist make\~inc.tmp \
		(del /f /q make\~inc.tmp)

	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),$(inc))
	@perl tools\lnitem.pl make\~inc.tmp

	@if exist $(COMPLOGDIR)                    	\
		(@echo [ COMMON OPTION ]> $(INFOLOG)) & \
		(type make\~def.tmp >> $(INFOLOG))

	@if exist $(COMPLOGDIR) \
		(@echo [ COMMON INCLUDE PATH ] >> $(INFOLOG)) & \
		(type make\~inc.tmp >> $(INFOLOG))

	@tools\strcmpex.exe def def e $(INFOMAKELOG) COM_DEFS = $(call sort, $(foreach def,$(COM_DEFS),$(def)))
	@tools\strcmpex.exe def def e make\~remove.tmp COMMINCDIRS = $(call sort, $(foreach inc,$(COMMINCDIRS),$(inc)))
	@type make\~remove.tmp >> $(INFOMAKELOG)
	@echo COMP_TRACE_DEFS = $(call sort, $(foreach def,$(COMP_TRACE_DEFS),$(def))) >> $(INFOMAKELOG)
	@echo COMPLIST = $(call sort, $(foreach def,$(COMPLIST),$(def))) >> $(INFOMAKELOG)
	@echo COMPOBJS = $(call sort, $(foreach def,$(COMPOBJS),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_BASE_COMP = $(call sort, $(foreach def,$(CUS_REL_BASE_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_PAR_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_PAR_SRC_COMP),$(def))) >> $(INFOMAKELOG)
ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
	@tools\strcmpex.exe def def e make\~remove.tmp ALL_CUS_REL_PAR_SRC_COMP = $(foreach comp,$(call Upper,$(CUS_REL_PAR_SRC_COMP)),$(CUS_REL_$(comp)_PAR_SRC_LIST))
	@type make\~remove.tmp >> $(INFOMAKELOG)
endif
	@del make\~remove.tmp
	@echo CUS_REL_MTK_COMP = $(call sort, $(foreach def,$(CUS_REL_MTK_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_OBJ_LIST = $(call sort, $(foreach def,$(CUS_REL_OBJ_LIST),$(def))) >> $(INFOMAKELOG)
	@echo LEVEL = $(strip $(LEVEL)) >> $(INFOMAKELOG)
	@echo CUSTOM_RELEASE = $(strip $(CUSTOM_RELEASE)) >> $(INFOMAKELOG)
	@echo VERNO = $(strip $(VERNO)) >> $(INFOMAKELOG)
	@echo MTK_SUBSIDIARY = $(strip $(MTK_SUBSIDIARY)) >> $(INFOMAKELOG)

# *************************************************************************
# Standard "cleanmod" Target
# *************************************************************************
cleanmod:
   # -----------------------------
   # Check build root, target, and project directories
   #
   # build ->
   #  +-$(CUSTOMER)
   #     +-$(PROJECT)
   #        +-$(PLATFORM)r    - Dependency directory
   #        +-$(PLATFORM)o    - Object directory
   #           +-$(COMPLIST)  - Component object directory
   #           +-lib          - Component libraries directory
   # -----------------------------
	@echo Cleaning directories under $(strip $(PROJDIR)) ...
	@if not exist $(BUILDDIR)  \
		md $(BUILDDIR)

	@-if not exist $(TARGDIR)                             \
		(md $(TARGDIR))                                   	\
	else                                                 	\
		(@if /I %OS% EQU Windows_NT                      	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (del /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) & 	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (rd /S /Q $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) 	\
		else                                              	\
			(@if exist $(strip $(TARGDIR))\$(NEWTARGNAME).bin (del $(strip $(TARGDIR))\$(NEWTARGNAME).bin)) &  	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).elf (del $(strip $(TARGDIR))\$(TARGNAME).elf)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).lis (del $(strip $(TARGDIR))\$(TARGNAME).lis)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).sym (del $(strip $(TARGDIR))\$(TARGNAME).sym)) &      	\
		(@if exist $(strip $(TARGDIR))\$(TARGNAME).htm (del $(strip $(TARGDIR))\$(TARGNAME).htm)) &      	\
		(@if exist $(strip $(TARGDIR))\*.log (del /q $(strip $(TARGDIR))\*.log)))

	-@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))         \
	else                          \
		(for /d %%i in ($(CLEAN_MODS)) do \
			(@if exist $(strip $(COMPLOGDIR))\%%i.log (del /q $(strip $(COMPLOGDIR))\%%i.log)) \
		)

	@if not exist $(PROJDIR)   \
		(md $(PROJDIR))

	@if not exist $(OBJSDIR)   \
		(md $(OBJSDIR))

   # -----------------------------
   # Check component directories
   # -----------------------------
	-@for /d %%i in ($(CLEAN_MODS)) do 			\
		(@if not exist $(strip $(OBJSDIR))\%%i	\
			(md $(strip $(OBJSDIR))\%%i)			\
		else												\
			(@echo Cleaning object files under %%i) & \
			(@if exist $(strip $(OBJSDIR))\%%i\*.obj (del $(strip $(OBJSDIR))\%%i\*.obj)))


	-@if not exist $(strip $(COMPLIBDIR))	\
		(md $(COMPLIBDIR)) 						\
	else												\
		(@echo Cleaning library files $(CLEAN_MODS) under $(COMPLIBDIR)) & \
		(for /d %%i in ($(CLEAN_MODS)) do \
			(@if exist $(strip $(COMPLIBDIR))\%%i.lib (del /q $(strip $(COMPLIBDIR))\%%i.lib)) \
		) & \
		(@echo Cleaning code gen files) & \
		(if /I $(NEED_CLEAN_CGENLST) EQU TRUE \
			(@if exist $(CODE_GEN_LST)						         \
				(copy $(CODE_GEN_LST) make\~codegenlis.tmp) &   \
				(@for /f %%j in ($(CODE_GEN_LST)) do 	         \
					(@if exist %%j (del %%j))                                    \
				) &							 	         \
				(@if exist $(CODE_GEN_LST) (del $(CODE_GEN_LST))) \
			) \
		)

##############################################################
# Resource generate
##############################################################
resgen:
ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
	@if exist $(MMIDIR)\VendorApp\DevResource\ResGenerator.bat \
		($(MMIDIR)\VendorApp\DevResource\ResGenerator.bat -t)
else
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(echo CUSTOM_OPTION = $(foreach def,$(BOARD_VER) $(PLATFORM) $(LCD_MODULE) $(EXT_CAM_MODULE) $(CMOS_SENSOR),-D "$(def)") \> $(MMIDIR)\customer\resGenerator\custom_option.txt) \
		)

	@tools\strcmpex.exe TRUE TRUE e make\~cus_opt.tmp $(foreach def,$(COM_DEFS),-D \"$(def)\")
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(type make\~cus_opt.tmp >> $(MMIDIR)\customer\resGenerator\custom_option.txt) \
		)

	@tools\strcmpex.exe TRUE TRUE e make\~tgt_opt.tmp $(foreach def,$(COM_DEFS) $(LCD_MODULE),/D \"$(def)\")
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(@del $(MMIDIR)\mmi\TargetOption.txt) & \
			(copy /Y make\~tgt_opt.tmp $(MMIDIR)\MMI\TargetOption.txt) \
		)

	@tools\strcmpex.exe TRUE TRUE e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),$(inc))
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(type make\~inc.tmp > $(MMIDIR)\customer\resGenerator\custom_include.tmp) \
		)




ifeq ($(strip $(NEED_COPY_MMIFEATURE)),CUSTOMER_MMI)
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > $(MMIDIR)\customer\resGenerator\custom_include.txt) & \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/\/I \"..\\..\\$$1\"\n/gs;print \"$$i\";" > $(MMIDIR)\MMI\GlobalTargetPathDef) & \
			(@if exist $(MMIDIR)\customer\replace_project_name.pl \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\remakeResource.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\UpdateSkin.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\UpdateSkin.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\ResGenerator.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\remakeResource.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\UpdateSkin.bat YYY $(patsubst %_MMI,%,$(CUSTOMER)) $(MMIDIR)\customer\UpdateSkin.bat) \
			) \
		) 
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(@if exist $(MMIDIR)\customer\replace_project_name.pl \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat SSS $(patsubst %_MMI,%,$(OPTR_SPEC)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat MMM $(patsubst %_MMI,%,$(MAIN_LCD_SIZE)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat PPP $(patsubst %_MMI,%,$(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat SSS $(patsubst %_MMI,%,$(OPTR_SPEC)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat MMM $(patsubst %_MMI,%,$(MAIN_LCD_SIZE)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat PPP $(patsubst %_MMI,%,$(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat SSS $(patsubst %_MMI,%,$(OPTR_SPEC)) $(MMIDIR)\customer\remakeResource.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat MMM $(patsubst %_MMI,%,$(MAIN_LCD_SIZE)) $(MMIDIR)\customer\remakeResource.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat PPP $(patsubst %_MMI,%,$(OPTR_PATH)) $(MMIDIR)\customer\remakeResource.bat) \
			) & \
			(@del $(MMIDIR)\customer\resGenerator\custom_include.tmp) & \
			($(MMIDIR)\customer\ResGenerator_HW.bat $(MMI_VERSION) $(CUSTOMER)) \
		)
else
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/-I \"..\\..\\..\\$$1\"/gs;print \"CUSTOM_INC = $$i\";" > $(MMIDIR)\customer\resGenerator\custom_include.txt) & \
			(@perl -e "open F,'<$(MMIDIR)\customer\resGenerator\custom_include.tmp';my $$i=join('',<F>);close F;$$i =~s/\s+/ /gs;$$i =~ s/(\S+)/\/I \"..\\..\\$$1\"\n/gs;print \"$$i\";" > $(MMIDIR)\MMI\GlobalTargetPathDef) & \
			(@if exist $(MMIDIR)\customer\replace_project_name.pl \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\remakeResource.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\UpdateSkin.tmp XXX $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\UpdateSkin.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\ResGenerator.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\remakeResource.bat) & \
					(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\UpdateSkin.bat YYY $(patsubst %_MMI,%,$(MMI_VERSION)) $(MMIDIR)\customer\UpdateSkin.bat) \
			) \
		) 
	@if exist $(MMIDIR)\customer \
		(@if /I $(RUN_RESGEN) EQU TRUE \
			(@if exist $(MMIDIR)\customer\replace_project_name.pl \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat SSS $(patsubst %_MMI,%,$(OPTR_SPEC)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat MMM $(patsubst %_MMI,%,$(MAIN_LCD_SIZE)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator_HW.bat PPP $(patsubst %_MMI,%,$(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator_HW.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat SSS $(patsubst %_MMI,%,$(OPTR_SPEC)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat MMM $(patsubst %_MMI,%,$(MAIN_LCD_SIZE)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\ResGenerator.bat PPP $(patsubst %_MMI,%,$(OPTR_PATH)) $(MMIDIR)\customer\ResGenerator.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat SSS $(patsubst %_MMI,%,$(OPTR_SPEC)) $(MMIDIR)\customer\remakeResource.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat MMM $(patsubst %_MMI,%,$(MAIN_LCD_SIZE)) $(MMIDIR)\customer\remakeResource.bat) & \
				(@perl $(MMIDIR)\customer\replace_project_name.pl $(MMIDIR)\customer\remakeResource.bat PPP $(patsubst %_MMI,%,$(OPTR_PATH)) $(MMIDIR)\customer\remakeResource.bat) \
			) & \
			(@del $(MMIDIR)\customer\resGenerator\custom_include.tmp) & \
			($(MMIDIR)\customer\ResGenerator_HW.bat $(MMI_VERSION) $(CUSTOMER)) \
		)
endif
   # copy only for Neptune162
	if /I "$(strip $(CUSTOMER))" EQU "NEPTUNE162" \
		(if exist $(FIXPATH)\$(MMIDIR)\customer\CustResource\$(strip $(CUSTOMER))_MMI\resource_shortcuts.c \
		   (copy /y $(FIXPATH)\$(MMIDIR)\Customer\CustResource\$(strip $(CUSTOMER))_MMI\resource_shortcuts.c $(FIXPATH)\$(MMIDIR)\Customer\CustResource\resource_shortcuts.c) \
		)

	@if exist $(MMIDIR)\customer\resGenerator\custom_option.txt \
		(@if exist $(MMIDIR)\VendorApp\resGenerator \
			(copy /z $(MMIDIR)\customer\resGenerator\custom_option.txt $(MMIDIR)\VendorApp\resGenerator\custom_option.txt) & \
			(copy /z $(MMIDIR)\customer\resGenerator\custom_include.txt $(MMIDIR)\VendorApp\resGenerator\custom_include.txt) \
		)

endif
##############################################################
gen_infolog:
	@if not exist $(COMPLOGDIR)	\
		(md $(COMPLOGDIR))

	@tools\strcmpex.exe def def e make\~def.tmp $(foreach def,$(COM_DEFS),$(def))
	@perl tools\lnitem.pl make\~def.tmp

	@if exist make\~inc.tmp \
		(del /f /q make\~inc.tmp)

	@tools\strcmpex.exe inc inc e make\~inc.tmp $(foreach inc,$(COMMINCDIRS),$(inc))
	@perl tools\lnitem.pl make\~inc.tmp

	@if exist $(COMPLOGDIR)                    	\
		(@echo [ COMMON OPTION ]> $(INFOLOG)) & \
		(type make\~def.tmp >> $(INFOLOG))

	@if exist $(COMPLOGDIR) \
		(@echo [ COMMON INCLUDE PATH ] >> $(INFOLOG)) & \
		(type make\~inc.tmp >> $(INFOLOG))

##############################################################

done:
#--------------------------------
# Huyanwei Collect Bin File And tar 
#--------------------------------
#ifeq ($(call Upper,$(strip $(ACTION))),NEW)
#	@if not exist $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\
#			(@mkdir $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul)
#	@copy /Y $(FIXPATH)\tools\ReleaseNote.txt $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt >nul
#	@echo "软件编译时间  : $(strip $(BUILD_DATE_TIME))" >> $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt
#	@if exist $(strip $(TARGDIR))\scatUNIRISE25_GEMINI.txt\
#			(@copy /Y 	$(strip $(TARGDIR))\scatUNIRISE25_GEMINI.txt $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul)
#	@if exist $(strip $(TARGDIR))\$(BIN_FILE)\
#			(@copy /Y 	$(strip $(TARGDIR))\$(BIN_FILE) $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul	)
#	@if exist $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP))\
#			(@copy /Y 	$(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP)) $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul	)
#	@if exist $(strip $(NOKE_RARPATH))\winrar.exe\
#			(@cd $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul && @$(strip $(NOKE_RARPATH))\winrar.exe a -r -pNoke -m5 -c- -zNote.txt -xNote.txt -k $(TARGETRARFILE)  .\* && cd ..\.. >nul )	
#endif
ifeq ($(call Upper,$(strip $(ACTION))),NEW)
	@if not exist $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\
			(@mkdir $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul)
	@copy /Y $(FIXPATH)\publish\ReleaseNote.txt $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt >nul			
	@echo "$(strip $(SOFTWARE_INFO))" >> $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt
	@echo ============================================= >> $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt	
	@echo                 软件编译时间   >> $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt
	@echo ============================================= >> $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt
	@echo $(strip $(BUILD_DATE_TIME)) >> $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt
	@echo ============================================= >> $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt	
	@if exist $(FIXPATH)\publish\$(strip $(NOKE_PROJECT)).doc\
			(@copy /Y 	$(FIXPATH)\publish\$(strip $(NOKE_PROJECT)).doc  $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul)
	@if exist $(strip $(SCATTERFILE))\
			(@copy /Y 	$(strip $(SCATTERFILE)) $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul)
	@if exist $(strip $(TARGDIR))\$(BIN_FILE)\
			(@copy /Y 	$(strip $(TARGDIR))\$(BIN_FILE) $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul	)
	@if exist $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP))\
			(@copy /Y 	$(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMSRCP)) $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul	)
	@if exist $(strip $(NOKE_RARPATH))\winrar.exe\
			(@cd $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))" >nul && @$(strip $(NOKE_RARPATH))\winrar.exe a -r -pNoke -m5 -c- -zNote.txt -xNote.txt -k $(TARGETRARFILE)  .\* && cd ..\.. >nul )	
	@if exist $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt\
			(@del $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\Note.txt >nul )				
	@if exist $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\$(strip $(NOKE_PROJECT)).doc \
			(@del $(strip $(TARGDIR))\"$(strip $(COLLECTDIR))"\$(strip $(NOKE_PROJECT)).doc >nul )
endif

# -----------------------------
# Clean temporary files in make directory
# -----------------------------
	@echo Cleaning make\~*.tmp files ...
	@if exist make\~*.tmp \
		del make\~*.tmp
	@echo Done.
	@perl tools\time.pl -n

ckmake:
	@echo makefile check is done