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
# *************************************************************************
# Common macro definitions
# *************************************************************************

# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .ptr .h

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : custom_release sec_policy_sst base hdr_comp src_comp par_src_comp mtk_comp files_list obj_list level_rel sec_policy gen_trace common_2726M26 switch29_30 filter_out done

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
# Build option definitons
include make\option.mak
include make\ALIAS.mak

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
include make\Custom_Release_ext.mak
endif

ifndef EMPTY_RESOURCE

EMPTY_RESOURCE = FALSE
	
MMI_FEATURES_SWITCH = FALSE       # TRUE or FALSE   It's for the internal usage only.
endif

#########################################################
# Replace alias modules.
#########################################################
ifdef CUS_REL_SRC_COMP
CUS_REL_SRC_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_SRC_COMP)), \
  $(if $(findstring $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_SRC_COMP := $(CUS_REL_SRC_COMP_TEMP)

ifdef CUS_REL_PAR_SRC_COMP
CUS_REL_PAR_SRC_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_PAR_SRC_COMP)), \
  $(if $(findstring $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_PAR_SRC_COMP := $(CUS_REL_PAR_SRC_COMP_TEMP)

ifdef CUS_REL_MTK_COMP
CUS_REL_MTK_COMP_TEMP = $(foreach mod,$(call Upper,$(CUS_REL_MTK_COMP)), \
  $(if $(findstring $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
CUS_REL_MTK_COMP := $(CUS_REL_MTK_COMP_TEMP)

ifdef COMPLIST
COMPLIST_TEMP = $(foreach mod,$(call Upper,$(COMPLIST)), \
  $(if $(findstring $($(mod)),TRUE),$($(mod)_CHILD),$(call lc,$(mod))))
endif
COMPLIST := $(COMPLIST_TEMP)

#########################################################
# End of replacing alias modules.
#########################################################

# ensure J2ME_SUPPORT <> MTK_J2ME
ifdef J2ME_SUPPORT
  ifneq ($(strip $(RELEASE_PACKAGE)),REL_CR_OBJ_JAL_SRC_GPRS)
    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
      ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
        $(error to prevent \mcu\j2me being released as source code, J2ME_VM cannot be set to KVM_SOURCE when J2ME_SUPPORT is IJET)
      endif
    endif
    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
      ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
        $(error to prevent \mcu\j2me being released as source code, J2ME_VM cannot be set to HI_VM_SOURCE when J2ME_SUPPORT is IJET)
      endif
    endif
  endif
endif

EN_DEF_FILE = make\$(CUSTOMER)_$(PROJECT)_en.def
DIS_DEF_FILE = make\$(CUSTOMER)_$(PROJECT)_dis.def
INFOMAKELOG  = make\info_custom_release.log
CODE_REMOVAL_DIR_FILE = make\SpecifyRemovalCodeDir.def

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
# Auto Remove Code
$(shell tools\strcmpex.exe abc abc e make\~com_def.tmp $(strip $(COM_DEFS)))

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  $(shell echo _SST_FUNCTION_ENABLE_ >> make\~com_def.tmp)
endif

$(shell if not exist $(strip $(DIS_DEF_FILE)) (perl mtk_tools\Auto_RemovingCode.pl $(CUSTOMER) $(PROJECT) $(CC) $(MTK_SUBSIDIARY)))
$(shell del make\~com_def.tmp)
# end of Auto Remove Code

$(shell if not exist $(strip $(EN_DEF_FILE)) (copy /y nul $(strip $(EN_DEF_FILE)) > nul ))
DIS_DEF_CNT = $(shell dir $(strip $(DIS_DEF_FILE)) /b 2>nul)
ifneq ($(words $(DIS_DEF_CNT)),1)
   $(error $(DIS_DEF_FILE) does NOT exist)
endif
endif
ifdef FOTA_ENABLE
  ifeq ($(strip $(FOTA_ENABLE)),FOTA_FULL)
    COMPLIST 			+= fota
    CUS_REL_SRC_COMP += fota
    CUS_REL_BASE_COMP += fota
  endif
endif

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
   ifeq ($(strip $(J2ME_VM)),KVM)
      COMPLIST :=  	$(subst ijet_adp,,$(COMPLIST))
      CUS_REL_SRC_COMP :=  	$(subst ijet_adp,,$(CUS_REL_SRC_COMP))
      CUS_REL_MTK_COMP :=  	$(subst ijet_adp,,$(CUS_REL_MTK_COMP))
      CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\IJET\j2me_11.lib,,$(CUS_REL_OBJ_LIST))
   endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
   ifeq ($(strip $(J2ME_VM)),HI_VM)
      COMPLIST :=  	$(subst ijet_adp,,$(COMPLIST))
      CUS_REL_SRC_COMP :=  	$(subst ijet_adp,,$(CUS_REL_SRC_COMP))
      CUS_REL_MTK_COMP :=  	$(subst ijet_adp,,$(CUS_REL_MTK_COMP))
      CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\IJET\j2me_hi.lib,,$(CUS_REL_OBJ_LIST))
   endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
   COMPLIST :=  	$(subst jblendia,,$(COMPLIST))
   CUS_REL_SRC_COMP :=  	$(subst jblendia,,$(CUS_REL_SRC_COMP))
   CUS_REL_MTK_COMP :=  	$(subst jblendia,,$(CUS_REL_MTK_COMP))
   CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\JBlendia\lib\ajsc_arm_ads.a,,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\JBlendia\lib\ajsc_custom_arm_ads.a,,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\JBlendia\lib\libmjb2.a,,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\JBlendia\lib\libz.a,,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\jblendia\lib\ajsc_win32_msvc.lib,,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\jblendia\lib\libmjb2.lib,,$(CUS_REL_OBJ_LIST))
   CUS_REL_OBJ_LIST :=  	$(subst j2me\vm\jblendia\lib\zlib_win32_msvc.lib,,$(CUS_REL_OBJ_LIST))
endif
endif

# check comp should not in $(CUS_REL_SRC_COMP) or $(CUS_REL_BASE_COMP)
PMT_INTERNAL_PROJECT =
ifneq ($(findstring $(strip $(call Upper,$(CUSTOMER))),$(PMT_INTERNAL_PROJECT)),)
FORBIDDEN_COMP = dp_engine opengl opengl16 fdm media_sec nvram_sec sst 
else
FORBIDDEN_COMP = dp_engine opengl opengl16 fdm media_sec nvram_sec sst 
endif

COMPLIST_NOT_CREL_COMP = $(foreach comp,$(FORBIDDEN_COMP), $(findstring $(comp),$(CUS_REL_SRC_COMP) $(CUS_REL_BASE_COMP)))
ifneq ($(words $(COMPLIST_NOT_CREL_COMP)),0)
   $(error $(foreach comp,$(COMPLIST_NOT_CREL_COMP),"$(comp)") should NOT in CUS_REL_SRC_COMP $(foreach comp,$(CUS_REL_SRC_COMP),"$(comp)") or CUS_REL_BASE_COMP $(foreach comp,$(CUS_REL_BASE_COMP),"$(comp)"))
endif

# put all CUS_REL_XXX_PAR_SRC_LIST together
ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
   ALL_CUS_REL_PAR_SRC_LIST = $(foreach comp,$(call Upper,$(CUS_REL_PAR_SRC_COMP)),[make\~$(comp).lis]$(CUS_REL_$(comp)_PAR_SRC_LIST))
endif

# check each comp in $(COMPLIST) if it has been put in $(CUS_REL_XXX_COMP)
COMPLIST_NOT_CREL_COMP = $(foreach comp,$(COMPLIST),$(if $(findstring "$(comp)",$(foreach word,$(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP),"$(word)")),,$(comp) ))
ifneq ($(words $(COMPLIST_NOT_CREL_COMP)),0)
   $(error $(foreach comp,$(COMPLIST_NOT_CREL_COMP),"$(comp)") in COMPLIST but NOT in CUS_REL_XXX_COMP)
endif

# check each comp in $(CUS_REL_XXX_COMP) if it has been put in $(COMPLIST)
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
CREL_COMP_NOT_COMPLIST = $(foreach comp,$(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP),$(if $(findstring "$(comp)",$(foreach word,$(COMPLIST),"$(word)")),,$(comp) ))
ifneq ($(words $(CREL_COMP_NOT_COMPLIST)),0)
   # for some custom releases, CUS_REL_XXX_COMP will be greater than COMPLIST
#   ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
#      ifneq ($(strip $(MMI_VERSION)),NEPTUNE_COLOR_MMI)
   	$(error $(foreach comp,$(CREL_COMP_NOT_COMPLIST),"$(comp)") in CUS_REL_XXX_COMP but NOT in COMPLIST)
#      endif
#   endif
endif
endif

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
   ifeq ($(strip $(J2ME_VM)),KVM)
      CUS_REL_BASE_COMP += make\ijet_adp make\j2me_11
      CUS_REL_SRC_COMP +=  	jdummy
   endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
   ifeq ($(strip $(J2ME_VM)),HI_VM)
      CUS_REL_BASE_COMP += make\ijet_adp make\j2me_hi make\j2me_hi_i386
      CUS_REL_SRC_COMP +=  	jdummy
   endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
   CUS_REL_BASE_COMP += make\jblendia
   CUS_REL_SRC_COMP +=  	jdummy
endif
endif

ifdef SSL_SUPPORT
  ifeq ($(strip $(SSL_SUPPORT)),SSL_CIC_LIB)
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\adaptation
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sb51\cntnr\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sb51\cic\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sb51\coding\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sb51\husw\src\huapi\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sb51\statmach\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sslplus5\dtlsapi\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sslplus5\utils\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sslplus5\private_shared\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sslplus5\hshk\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sslplus5\impexp\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sslplus5\rec\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sslplus5\api\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sbpki2\x509\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sbpki2\ber\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sbpki2\tputil\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sbpki2\identity\include
    CUS_REL_BASE_COMP += vendor_sec\security\certicom\v1_official\sbpki2\validate\include
  endif
endif

# *************************************************************************
#  Target Definitions
# *************************************************************************

MMI_PROJ = $(strip $(subst _MMI,,$(MMI_VERSION)))

ifeq ($(strip $(MMI_BASE)),PLUTO_MMI)
	ifeq ($(strip $(MMI_VERSION)),PLUTO_MMI)
   	ifdef EMPTY_RESOURCE
      	ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
				MP_NOT_IN_MTK = TRUE
			else
				MP_NOT_IN_MTK = INTERNAL
			endif
		endif
	endif
endif

ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
	ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
   	ifdef EMPTY_RESOURCE
      	ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
				MP_NOT_IN_MTK = TRUE
			else
				MP_NOT_IN_MTK = INTERNAL
			endif
		endif
	endif
endif

BPLGUINFOCUSTOM = $(shell dir $(strip $(TST_DB))\$(strip $(BPLGUINFOCUSTOMPREFIX))* /b)
# *************************************************************************
# Custom Release
# *************************************************************************
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
custom_release: base hdr_comp src_comp par_src_comp mtk_comp files_list obj_list filter_out done
	@echo vendor_release is done!!!
endif
else
custom_release: sec_policy_sst base hdr_comp src_comp par_src_comp mtk_comp files_list obj_list level_rel sec_policy gen_trace switch29_30 common_2726M26 filter_out done
	@echo custom_release is done!!!
endif

base:
	@if $(words $(strip $(BPLGUINFOCUSTOM))) NEQ 1 @echo More than two $(strip $(BPLGUINFOCUSTOM)). Please check.
	@echo Customer Release $(strip $(PROJECT)) for $(strip $(CUSTOMER)):
	@if not exist "$(RELEASE_DIR)"  \
		md "$(RELEASE_DIR)"

   # -----------------------------
   # generate 3 party release log info
   # -----------------------------
	@if exist "$(RELEASE_DIR)"\*.txt \
		(del "$(RELEASE_DIR)"\*.txt)

ifdef VR_ENGINE
ifeq ($(strip $(VR_ENGINE)),VR_CYBERON)
	echo. > "$(RELEASE_DIR)"\Cyberon-VR.txt
endif
ifeq ($(strip $(VR_ENGINE)),VR_ITRI)
	echo. > "$(RELEASE_DIR)"\ITRI-VR.txt
endif
endif

ifdef J2ME_SUPPORT
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
	echo. > "$(RELEASE_DIR)"\III-J2ME.txt
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
	echo. > "$(RELEASE_DIR)"\APLIX-J2ME.txt
endif
endif

ifdef TELECA_FEATURE
ifeq ($(strip $(TELECA_FEATURE)),WAP)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
ifeq ($(strip $(TELECA_FEATURE)),WAP2)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
ifeq ($(strip $(TELECA_FEATURE)),WAP_MMS)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
ifeq ($(strip $(TELECA_FEATURE)),WAP2_MMS)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
ifeq ($(strip $(TELECA_FEATURE)),WAP2_SEC_MMS)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS.txt
endif
endif

ifneq ($(findstring nucleus,$(strip $(COMPLIST))),)
	echo. > "$(RELEASE_DIR)"\MG-RTOS.txt
endif

ifdef HAND_WRITING
ifeq ($(strip $(HAND_WRITING)),MMI_HANWANG)
	echo. > "$(RELEASE_DIR)"\HW-HW.txt
endif
ifeq ($(strip $(HAND_WRITING)),MMI_PENPOWER)
	echo. > "$(RELEASE_DIR)"\PP-HW.txt
endif
endif

ifdef WMA_DECODE
ifeq ($(strip $(WMA_DECODE)),TRUE)
	echo. > "$(RELEASE_DIR)"\MS-WMA.txt
endif
endif

ifdef INPUT_METHOD
ifeq ($(strip $(INPUT_METHOD)),MMI_T9)
	echo. > "$(RELEASE_DIR)"\T9-IMD.txt
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_ZI)
	echo. > "$(RELEASE_DIR)"\Zi-IMD.txt
endif
ifeq ($(strip $(INPUT_METHOD)),MMI_CSTAR_V2)
	echo. > "$(RELEASE_DIR)"\Cstar-IMD.txt
endif
endif

ifdef DICT_SUPPORT
ifeq ($(strip $(DICT_SUPPORT)),MMI_GV)
	echo. > "$(RELEASE_DIR)"\GV-DICT.txt
endif
ifeq ($(strip $(DICT_SUPPORT)),MMI_MOTECH)
	echo. > "$(RELEASE_DIR)"\MOTECH-DICT.txt
endif
ifeq ($(strip $(DICT_SUPPORT)),MMI_TRILOGY)
	echo. > "$(RELEASE_DIR)"\TRILOGY-DICT.txt
endif
endif

ifdef DRM_SUPPORT
ifeq ($(strip $(DRM_SUPPORT)),BSCI)
	echo. > "$(RELEASE_DIR)"\BS-DRM.txt
endif
endif

ifdef GAME_ENGINE
ifeq ($(strip $(GAME_ENGINE)),GE_BROGENT)
	echo. > "$(RELEASE_DIR)"\Brogent-3DGAME.txt
endif
endif

ifdef AAC_DECODE
ifeq ($(strip $(AAC_DECODE)),TRUE)
	echo. > "$(RELEASE_DIR)"\CT-AAC.txt
endif
endif

ifdef AAC_PLUS_DECODE
ifeq ($(strip $(AAC_PLUS_DECODE)),TRUE)
	echo. > "$(RELEASE_DIR)"\CT-AACPLUS.txt
endif
endif

ifdef AAC_PLUS_PS_DECODE
ifeq ($(strip $(AAC_PLUS_PS_DECODE)),TRUE)
	echo. > "$(RELEASE_DIR)"\CT-AACPLUSV2.txt
endif
endif

ifdef SYNCML_DM_SUPPORT
ifeq ($(strip $(SYNCML_DM_SUPPORT)),TRUE)
	echo. > "$(RELEASE_DIR)"\Bitfone-DM.txt
endif
endif

ifdef WAP_SUPPORT
ifeq ($(strip $(WAP_SUPPORT)),OBIGO_Q05A)
	echo. > "$(RELEASE_DIR)"\Obigo-MMS05A.txt
endif
endif

ifdef JATAAYU_FEATURE
ifneq ($(strip $(JATAAYU_FEATURE)),NONE)
	echo. > "$(RELEASE_DIR)"\Jataayu-MMS.txt
endif
endif

ifdef TTS
ifeq ($(strip $(TTS)),CYBERON_DIC_TTS)
	echo. > "$(RELEASE_DIR)"\Cyberon-TTS.txt
endif
endif

	@if not exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB) \
		md "$(RELEASE_DIR)"\$(CUS_MTK_LIB)

	@if not exist "$(RELEASE_DIR)"\make \
		md "$(RELEASE_DIR)"\make

	@if not exist "$(RELEASE_DIR)"\tools \
		md "$(RELEASE_DIR)"\tools

	@if not exist "$(RELEASE_DIR)"\Fast_DL \
		md "$(RELEASE_DIR)"\Fast_DL

	@if not exist "$(RELEASE_DIR)"\custom\system\$(BOARD_VER) \
		md "$(RELEASE_DIR)"\custom\system\$(BOARD_VER)


   # -----------------------------
   # Duplicate base files
   # -----------------------------
	copy /z $(FIXPATH)\make.bat "$(RELEASE_DIR)"\.
	copy /z $(FIXPATH)\m.bat "$(RELEASE_DIR)"\.
	copy /z $(FIXPATH)\make2.pl "$(RELEASE_DIR)"\.
	copy /z $(FIXPATH)\m_cp2lsf.pl "$(RELEASE_DIR)"\.
ifeq ($(strip $(RTOS)),THREADX)
	copy /z $(FIXPATH)\THREADX*.* "$(RELEASE_DIR)"\.
else
	copy /z $(FIXPATH)\nuc*.* "$(RELEASE_DIR)"\.
endif
	copy /z $(FIXPATH)\make\GSM2.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\Comp.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\Option.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\JAVA_DEF.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\ALIAS.mak "$(RELEASE_DIR)"\make\.

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	copy /z $(FIXPATH)\make\Custom_Release.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\make\USER_SPECIFIC.mak "$(RELEASE_DIR)"\make\.
	copy /z $(FIXPATH)\mtk_tools\traversedir.pl "$(RELEASE_DIR)"\tools\.
	copy /z $(FIXPATH)\mtk_tools\traversedir_modis.pl "$(RELEASE_DIR)"\tools\.
endif

	copy /z $(FIXPATH)\make\$(CUSTOMER)_$(PROJECT).mak "$(RELEASE_DIR)"\make\.

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),KVM)
		perl -e "open F,'+<"$(RELEASE_DIR)"\make\$(CUSTOMER)_$(PROJECT).mak';$$f = join(\"\",<F>);$$f=~s/(J2ME_SUPPORT\s*=\s*)J2ME_LIB/$$1 MTK_DUMMYVM/g;seek(F,0,0);print F $$f;close F;"
		perl -e "open F,'+<"$(RELEASE_DIR)"\make\option.mak';$$f = join(\"\",<F>);$$f=~s/(COM_DEFS\s*\+=\s*__MTK_DUMMY_VM__)/$$1 CLDC11/g;seek(F,0,0);print F $$f;close F;"
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),HI_VM)
		perl -e "open F,'+<"$(RELEASE_DIR)"\make\$(CUSTOMER)_$(PROJECT).mak';$$f = join(\"\",<F>);$$f=~s/(J2ME_JSR184_SUPPORT\s*=\s*)\S+/$$1 NONE/g;$$f=~s/(J2ME_SUPPORT\s*=\s*)J2MEHI_LIB/$$1 MTK_DUMMYVM/g;seek(F,0,0);print F $$f;close F;"
		perl -e "open F,'+<"$(RELEASE_DIR)"\make\option.mak';$$f = join(\"\",<F>);$$f=~s/(COM_DEFS\s*\+=\s*__MTK_DUMMY_VM__)/$$1 CLDCHI/g;seek(F,0,0);print F $$f;close F;"
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
	perl -e "open F,'+<"$(RELEASE_DIR)"\make\$(CUSTOMER)_$(PROJECT).mak';$$f = join(\"\",<F>);$$f=~s/(J2ME_SUPPORT\s*=\s*)JBLENDIA/$$1 MTK_DUMMYVM/g;seek(F,0,0);print F $$f;close F;"
	perl -e "open F,'+<"$(RELEASE_DIR)"\make\option.mak';$$f = join(\"\",<F>);$$f=~s/(COM_DEFS\s*\+=\s*__MTK_DUMMY_VM__)/COMMINCDIRS	\+= j2me\vm\JBlendia\include\ksi\\n$$1/g;seek(F,0,0);print F $$f;close F;"
endif
endif

	copy /z $(FIXPATH)\$(VERNOFILE) "$(RELEASE_DIR)"\$(VERNOFILE)
ifdef RELEASE_PACKAGE
	copy /z $(FIXPATH)\make\$(strip $(RELEASE_PACKAGE)).mak "$(RELEASE_DIR)"\make\.
endif

	copy /z $(FIXPATH)\$(SCATTERFILE) "$(RELEASE_DIR)"\$(SCATTERFILE)

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
	@if exist $(FIXPATH)\$(CUSTOMER)_*_$(PROJECT)_*_MTK_only.cmm \
		(copy /z $(FIXPATH)\$(CUSTOMER)_*_$(PROJECT)_*_MTK_only.cmm "$(RELEASE_DIR)"\.) & \
		(perl mtk_tools\RemoveLine.pl "$(RELEASE_DIR)"\$(CUSTOMER)_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_MTK_only.cmm "menu.reprogram gprs") \
	else \
		(if exist $(FIXPATH)\MTK_*_$(PROJECT)_*_MTK_only.cmm \
			(copy /z $(FIXPATH)\MTK_*_$(PROJECT)_*_MTK_only.cmm "$(RELEASE_DIR)"\.) & \
			(perl mtk_tools\RemoveLine.pl "$(RELEASE_DIR)"\MTK_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_MTK_only.cmm "menu.reprogram gprs") \
		)
	@if exist $(FIXPATH)\BasicAnalysis.cmm \
		(copy /z $(FIXPATH)\BasicAnalysis.cmm "$(RELEASE_DIR)"\.)
endif
endif

	@if exist $(FIXPATH)\$(CUSTOMER)_*_$(PROJECT)_*_nocode.cmm \
		(copy /z $(FIXPATH)\$(CUSTOMER)_*_$(PROJECT)_*_nocode.cmm "$(RELEASE_DIR)"\.) \
	else \
		(if exist $(FIXPATH)\MTK_*_$(PROJECT)_*_nocode.cmm \
			(copy /z $(FIXPATH)\MTK_*_$(PROJECT)_*_nocode.cmm "$(RELEASE_DIR)"\.) \
		)
ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
		@if exist "$(RELEASE_DIR)"\$(CUSTOMER)_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_nocode.cmm \
			(perl mtk_tools\RemoveLine.pl "$(RELEASE_DIR)"\$(CUSTOMER)_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_nocode.cmm "menu.reprogram gprs") \
		else \
			(if exist "$(RELEASE_DIR)"\MTK_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_nocode.cmm \
				(perl mtk_tools\RemoveLine.pl "$(RELEASE_DIR)"\MTK_$(strip $(SUB_BOARD_VER))_$(PROJECT)_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_nocode.cmm "menu.reprogram gprs") \
			)
endif
	copy /z $(FIXPATH)\Fast_DL\FastDL.elf "$(RELEASE_DIR)"\Fast_DL\.
	copy /z $(FIXPATH)\Fast_DL\FastDL_V1.elf "$(RELEASE_DIR)"\Fast_DL\.
	@if exist $(FIXPATH)\Fast_DL\$(TARGNAME).cmm \
		(copy /z $(FIXPATH)\Fast_DL\$(TARGNAME).cmm "$(RELEASE_DIR)"\Fast_DL\.)

	@if /I "$(PROJECT)" EQU "GSM" \
		(xcopy /y $(FIXPATH)\tst\database\*.txt "$(RELEASE_DIR)"\tst\database\) & \
		(xcopy /y $(FIXPATH)\tst\database\$(BPLGUINFOCUSTOMPREFIX)_* "$(RELEASE_DIR)"\tst\database\)

	@if /I "$(PROJECT)" EQU "GPRS" \
		(xcopy /y $(FIXPATH)\tst\database_classb\$(BPLGUINFOCUSTOMPREFIX)_* "$(RELEASE_DIR)"\tst\database_classb\)

	@if /I "$(PROJECT)" EQU "UMTS" \
		(xcopy /y $(FIXPATH)\tst\database_classb_umts\$(BPLGUINFOCUSTOMPREFIX)_* "$(RELEASE_DIR)"\tst\database_classb_umts\)

   # -----------------------------
   # Duplicate base directories
   # -----------------------------
#	for /d %%i in ($(strip $(CUS_REL_BASE_COMP))) do \
#		xcopy /e /y  $(FIXPATH)\%%i "$(RELEASE_DIR)"\%%i\*.*
	@perl tools\copyDirs.pl $(FIXPATH) "$(RELEASE_DIR)" $(strip $(CUS_REL_BASE_COMP))

   # -----------------------------
   # copy \$(strip $(MMIDIR))\Customer\CustResource\$(strip $(CUSTOMER))_MMI\*.* @if /I "$(NEED_COPY_MMIFEATURE)" EQU "TRUE"
   # -----------------------------
# copy \$(strip $(MMIDIR))\Customer\CustResource\$(strip $(CUSTOMER))_MMI\mmi_featureXXX.h & CustMiscDataXXX.c @if /I "$(NEED_COPY_MMIFEATURE)" EQU "TRUE"
# copy \$(strip $(MMIDIR))\Customer\CustResource\$(strip $(CUSTOMER))_MMI\*.* @if /I "$(NEED_COPY_MMIFEATURE)" EQU "TRUE"

ifneq (,$(findstring $(strip $(PLATFORM)), $(strip $(NAND_FLASH_BOOTING_SUPPORT_PLATFORM))))
ifeq ($(strip $(NAND_FLASH_BOOTING)),TRUE)
ifeq ($(call Upper ,$(strip $(LEVEL))),VENDOR)
	@if exist $(strip $(FLASHFILE)) \
		(if not exist "$(RELEASE_DIR)"\custom\system\$(strip $(BOARD_VER))	(md "$(RELEASE_DIR)"\custom\system\$(strip $(BOARD_VER)))) & \
		(copy /z $(strip $(FLASHFILE)) "$(RELEASE_DIR)"\$(strip $(FIXPATH))\custom\system\$(strip $(BOARD_VER)))
	@if exist $(strip $(TARGDIR))\$(strip $(CUSTOMER))_BOOTLOADER_*.bin \
		(if not exist "$(RELEASE_DIR)"\$(strip $(TARGDIR))	(md "$(RELEASE_DIR)"\$(strip $(TARGDIR)))) & \
		(copy /z $(strip $(TARGDIR))\$(strip $(CUSTOMER))_BOOTLOADER_*.bin "$(RELEASE_DIR)"\$(strip $(TARGDIR)))
	@if exist bootloader\src\verno_bootloader.bld \
		(if not exist "$(RELEASE_DIR)"\bootloader\src	(md "$(RELEASE_DIR)"\bootloader\src)) & \
		(copy /z bootloader\src\verno_bootloader.bld "$(RELEASE_DIR)"\bootloader\src)
endif
endif
endif


hdr_comp:

   # -----------------------------
   # Duplicate release header file components
   # -----------------------------
ifneq ($(strip $(CUS_REL_HDR_COMP)),)
	@echo Duplicate release header file components ...
	for /d %%i in ($(strip $(CUS_REL_HDR_COMP))) do \
		(@echo header file component: %%i) & \
		(for /f "skip=2" %%j in ('find /I ".h" $(strip $(FIXPATH))\make\%%i\%%i.lis') do \
			(@echo copying file %%j) & \
			(if not exist "$(RELEASE_DIR)"\%%j \
				(md "$(RELEASE_DIR)"\%%j) & \
				(rd "$(RELEASE_DIR)"\%%j) & \
				(copy /y $(FIXPATH)\%%j "$(RELEASE_DIR)"\%%j) \
			) \
		) & \
		(copy /z $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib)
endif

src_comp:

   # -----------------------------
   # Duplicate release source components
   # -----------------------------
ifneq ($(strip $(CUS_REL_SRC_COMP)),)
	@echo Duplicate release source components ...
	tools\strcmpex.exe trcdef trcdef e make\~trcdef.tmp $(foreach file,$(COMP_TRACE_DEFS),$(file))
	@echo. > make\~srccomprh.tmp

   # copy all files listed in .lis
	(for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
		(for /f %%j in (%%i) do \
			(@echo copying file %%j) & \
			(if not exist "$(RELEASE_DIR)"\%%j \
				(md "$(RELEASE_DIR)"\%%j) & \
				(rd "$(RELEASE_DIR)"\%%j) & \
				(copy /y $(FIXPATH)\%%j "$(RELEASE_DIR)"\%%j) \
			) \
		) \
		)

   # use .lis and .dep to find out the required header files then copy them
#	(for /d %%i in ($(strip $(CUS_REL_SRC_COMP))) do \
#		(perl tools\req_hdr.pl $(FIXPATH)\make\%%i\%%i.lis $(RULESDIR)\%%i.dep > make\~%%irh.tmp) & \
#		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
#		(for /f %%k in (make\~%%irh.tmp) do \
#			(@echo copying file %%k) & \
#			(if not exist "$(RELEASE_DIR)"\%%k \
#				(md "$(RELEASE_DIR)"\%%k) & \
#				(rd "$(RELEASE_DIR)"\%%k) & \
#				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
#			) \
#		) \
#	) & \
#	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)

	(for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
		(perl tools\copySrcComp.pl %%i $(RULESDIR) make "$(RELEASE_DIR)") & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp))


ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),KVM)
	(for /d %%i in (ijet_adp) do \
		(perl tools\req_hdr.pl $(FIXPATH)\make\%%i\%%i.lis $(RULESDIR)\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
	(for /d %%i in (j2me_11) do \
		(perl tools\req_hdr.pl $(FIXPATH)\make\%%i\%%i.lis $(FIXPATH)\make\%%i\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),HI_VM)
	(for /d %%i in (ijet_adp) do \
		(perl tools\req_hdr.pl $(FIXPATH)\make\%%i\%%i.lis $(RULESDIR)\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
	(for /d %%i in (j2me_hi) do \
		(perl tools\req_hdr.pl $(FIXPATH)\make\%%i\%%i.lis $(FIXPATH)\make\%%i\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
  endif	
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
	(for /d %%i in (jblendia) do \
		(perl tools\req_hdr.pl $(FIXPATH)\make\%%i\%%i.lis $(FIXPATH)\make\%%i\%%i.dep > make\~%%irh.tmp) & \
		(type make\~%%irh.tmp >> make\~srccomprh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		) \
	) & \
	(perl tools\AinB.pl make\~srccomprh.tmp make\~trcdef.tmp > make\~existtrc.tmp)
endif
endif

   # copy .lis, .def, .pth, .inc
#	for /d %%i in ($(strip $(CUS_REL_SRC_COMP))) do \
#		(if /I "%%i" EQU "$(strip $(MMIDIR))" \
#			(if not exist "$(RELEASE_DIR)"\make\%%i \
#				(md "$(RELEASE_DIR)"\make\%%i) \
#			) & \
#			(copy /z $(FIXPATH)\make\%%i\%%i.* "$(RELEASE_DIR)"\make\%%i\.) & \
#			(xcopy /e /y $(FIXPATH)\make\%%i\$(MMI_VERSION) "$(RELEASE_DIR)"\make\%%i\$(strip $(MMI_VERSION))\*.*) \
#		else \
#			(xcopy /e /y $(FIXPATH)\make\%%i "$(RELEASE_DIR)"\make\%%i\*.*) \
#		)

   # copy .lis, .def, .pth, .inc
	for /d %%i in ($(strip $(SRC_LIS_FILE))) do \
		(perl tools\copyLIS.pl %%i "$(RELEASE_DIR)" $(MMIDIR) $(MMI_VERSION) \
		)

endif

par_src_comp:

   # -----------------------------
   # Duplicate partial release source components
   # -----------------------------
	tools\strcmpex.exe crpsrcl crpsrcl e make\~crpsrcl.tmp $(ALL_CUS_REL_PAR_SRC_LIST)
ifneq ($(strip $(CUS_REL_PAR_SRC_COMP)),)
	(@echo Duplicate release partial source components ...) & \
	(perl tools\lst2file.pl make\~crpsrcl.tmp)

   # copy all files listed in .lis

	for /d %%i in ($(strip $(CUS_REL_PAR_SRC_COMP))) do \
		(@echo partial source component: %%i) & \
		(perl tools\lnitem.pl make\~%%i.lis) & \
		(for /f %%j in ($(FIXPATH)\make\~%%i.lis) do \
			(@echo copying file %%j) & \
			(if not exist "$(RELEASE_DIR)"\%%j \
				(md "$(RELEASE_DIR)"\%%j) & \
				(rd "$(RELEASE_DIR)"\%%j) & \
				(copy /y $(FIXPATH)\%%j "$(RELEASE_DIR)"\%%j) \
			) \
		)

   # use .lis and .dep to find out the required header files then copy them
	for /d %%i in ($(strip $(CUS_REL_PAR_SRC_COMP))) do \
		(perl tools\req_hdr.pl $(FIXPATH)\make\~%%i.lis $(RULESDIR)\%%i.dep > make\~%%irh.tmp) & \
		(for /f %%k in (make\~%%irh.tmp) do \
			(@echo copying file %%k) & \
			(if not exist "$(RELEASE_DIR)"\%%k \
				(md "$(RELEASE_DIR)"\%%k) & \
				(rd "$(RELEASE_DIR)"\%%k) & \
				(copy /y $(FIXPATH)\%%k "$(RELEASE_DIR)"\%%k) \
			) \
		)

   # copy .lis, .def, .pth, .inc, .$(CUS_MTK_LIB)\*.lib
	for /d %%i in ($(strip $(CUS_REL_PAR_SRC_COMP))) do \
		(if /I "%%i" EQU "$(strip $(MMIDIR))" \
			(if not exist "$(RELEASE_DIR)"\make\%%i \
				(md "$(RELEASE_DIR)"\make\%%i) \
			) & \
			(copy /z $(FIXPATH)\make\%%i\%%i.* "$(RELEASE_DIR)"\make\%%i\.) & \
			(copy /z make\~%%i.lis "$(RELEASE_DIR)"\make\%%i\%%i.lis) & \
			(xcopy /e /y $(FIXPATH)\make\%%i\$(MMI_VERSION) "$(RELEASE_DIR)"\make\%%i\$(strip $(MMI_VERSION))\*.*) & \
			(copy /z make\~%%i.lis "$(RELEASE_DIR)"\make\%%i\$(strip $(MMI_VERSION))\%%i.lis) \
		else \
			(xcopy /e /y $(FIXPATH)\make\%%i "$(RELEASE_DIR)"\make\%%i\*.*) & \
			(copy /z make\~%%i.lis "$(RELEASE_DIR)"\make\%%i\%%i.lis) \
		) & \
		(copy /z $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib)
endif

mtk_comp:

   # -----------------------------
   # Duplicate MTK library only
   # -----------------------------
ifneq ($(strip $(CUS_REL_MTK_COMP)),)
	for /d %%i in ($(strip $(CUS_REL_MTK_COMP))) do \
		(copy /z $(COMPLIBDIR)\%%i.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\%%i.lib)

ifeq ($(call Upper,$(strip $(GEMINI))),TRUE)
ifneq ($(findstring __DRV_DUAL_SIM_INVERSE__,$(CUSTOM_OPTION)),)
	if exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\drv_sec.lib \
		(if not exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\DRV_DUAL_SIM_INVERSE_ON \
			(md "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\DRV_DUAL_SIM_INVERSE_ON) & \
		(move /Y "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\drv_sec.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\DRV_DUAL_SIM_INVERSE_ON\drv_sec.lib))
else
	if exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\drv_sec.lib \
		(if not exist "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\DRV_DUAL_SIM_INVERSE_OFF \
			(md "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\DRV_DUAL_SIM_INVERSE_OFF) & \
		(move /Y "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\drv_sec.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\DRV_DUAL_SIM_INVERSE_OFF\drv_sec.lib))
endif
endif
#ifneq ($(call Upper ,$(strip $(LEVEL))),VENDOR)
#	for /d %%i in ($(strip $(MTK_LIS_FILE))) do \
#		(perl tools\copyLIS.pl %%i "$(RELEASE_DIR)" $(MMIDIR) $(MMI_VERSION) \
#		)
#
#endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	copy /z $(CUS_MTK_LIB)\*.lib "$(RELEASE_DIR)"\$(CUS_MTK_LIB)\.
endif

files_list:

   # -----------------------------
   # Duplicate custom dedicate files
   # -----------------------------
   # because the length of $(CUS_REL_FILES_LIST) may exceeds the DOS command limit,
   # use strcmpex.exe & lnitem.pl to dump $(CUS_REL_FILES_LIST)

	tools\strcmpex.exe crfl crfl e make\~crfl.tmp $(foreach file,$(CUS_REL_FILES_LIST),$(file))
	if exist $(FIXPATH)\make\~crfl.tmp \
		(perl tools\lnitem.pl make\~crfl.tmp) & \
		(for /f %%i in (make\~crfl.tmp) do \
			(@echo copying file %%i) & \
			(if not exist "$(RELEASE_DIR)"\%%i \
				(md "$(RELEASE_DIR)"\%%i) & \
				(rd "$(RELEASE_DIR)"\%%i) & \
				(copy /y $(FIXPATH)\%%i "$(RELEASE_DIR)"\%%i) \
			) \
		)


obj_list:

   # -----------------------------
   # Duplicate custom dedicate obj
   # -----------------------------
	perl tools\copyFiles.pl $(FIXPATH) "$(RELEASE_DIR)" $(strip $(CUS_REL_OBJ_LIST))
	

filter_out:
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
	if not exist $(strip $(EN_DEF_FILE)) (copy /y nul $(strip $(EN_DEF_FILE)) > nul )
	if not exist $(strip $(DIS_DEF_FILE)) (copy /y nul $(strip $(DIS_DEF_FILE)) > nul )	
	if not exist $(strip $(CODE_REMOVAL_DIR_FILE)) (copy /y nul $(strip $(CODE_REMOVAL_DIR_FILE)) > nul )
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) $(CODE_REMOVAL_DIR_FILE) TRUE
else
	echo .> ~customRemovalDir.tmp
  ifneq ($(call Upper,$(strip $(RELEASE_PACKAGE))),REL_CR_OBJ_JAL_SRC_GPRS)
		perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp
  else
		perl mtk_tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp TRUE
  endif
	del ~customRemovalDir.tmp
endif
else
ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
	perl tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) $(CODE_REMOVAL_DIR_FILE) TRUE
else
	echo .> ~customRemovalDir.tmp
  ifneq ($(call Upper,$(strip $(RELEASE_PACKAGE))),REL_CR_OBJ_JAL_SRC_GPRS)
		perl tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp
  else
		perl tools\traverseDir.pl "$(RELEASE_DIR)" $(EN_DEF_FILE) $(DIS_DEF_FILE) $(CUS_REL_OPTION_FILTER) $(CUS_REL_HISTORY_FILTER) ~customRemovalDir.tmp TRUE
  endif
	del ~customRemovalDir.tmp
endif
endif

done:

   # -----------------------------
   # Generate custom.bld for use in custom release
   # -----------------------------
	@echo CUSTOM_RELEASE = TRUE > "$(RELEASE_DIR)"\make\Custom.bld
	@echo LEVEL = $(call Upper,$(LEVEL)) >> "$(RELEASE_DIR)"\make\Custom.bld
	perl .\tools\append2.pl $(strip $(FLASHFILE)) $(strip $(MEMORY_CFG)) $(strip $(THE_MF))>> "$(RELEASE_DIR)"\make\Custom.bld


	@echo COMP_TRACE_DEFS = $(call sort, $(foreach def,$(COMP_TRACE_DEFS),$(def))) > $(INFOMAKELOG)
	@echo COMPLIST = $(call sort, $(foreach def,$(COMPLIST),$(def))) >> $(INFOMAKELOG)
	@echo COMPOBJS = $(call sort, $(foreach def,$(COMPOBJS),$(def))) >> $(INFOMAKELOG)
#	@echo CUS_REL_BASE_COMP = $(call sort, $(foreach def,$(CUS_REL_BASE_COMP),$(def))) >> $(INFOMAKELOG)
	@perl tools\echoLongString.pl $(INFOMAKELOG) CUS_REL_BASE_COMP $(CUS_REL_BASE_COMP)
	@echo CUS_REL_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_SRC_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_PAR_SRC_COMP = $(call sort, $(foreach def,$(CUS_REL_PAR_SRC_COMP),$(def))) >> $(INFOMAKELOG)
ifneq ($(words $(CUS_REL_PAR_SRC_COMP)),0)
	@tools\strcmpex.exe def def e make\~remove.tmp ALL_CUS_REL_PAR_SRC_COMP = $(foreach comp,$(call Upper,$(CUS_REL_PAR_SRC_COMP)),$(CUS_REL_$(comp)_PAR_SRC_LIST))
	@type make\~remove.tmp >> $(INFOMAKELOG)
endif
	@if exist make\~remove.tmp (del make\~remove.tmp)
	@echo CUS_REL_MTK_COMP = $(call sort, $(foreach def,$(CUS_REL_MTK_COMP),$(def))) >> $(INFOMAKELOG)
	@echo CUS_REL_OBJ_LIST = $(call sort, $(foreach def,$(CUS_REL_OBJ_LIST),$(def))) >> $(INFOMAKELOG)
	@echo LEVEL = $(strip $(LEVEL)) >> $(INFOMAKELOG)
	@echo VERNO = $(strip $(VERNO)) >> $(INFOMAKELOG)
	@echo CUS_REL_OPTION_FILTER = $(strip $(CUS_REL_OPTION_FILTER)) >> $(INFOMAKELOG)
	@echo CUS_REL_HISTORY_FILTER = $(strip $(CUS_REL_HISTORY_FILTER)) >> $(INFOMAKELOG)
	@echo EN_DEF_FILE = $(strip $(EN_DEF_FILE)) >> $(INFOMAKELOG)
	@echo DIS_DEF_FILE = $(strip $(DIS_DEF_FILE)) >> $(INFOMAKELOG)
#	@echo RELEASE_DIR = $(strip "$(RELEASE_DIR)") >> $(INFOMAKELOG)
	@perl tools\getRelDir.pl $(strip "$(RELEASE_DIR)") >> $(INFOMAKELOG)
	@echo CUS_MTK_LIB = $(strip $(CUS_MTK_LIB)) >> $(INFOMAKELOG)
ifeq ($(strip $(DUMMYVM)),TRUE)
	@echo DUMMYVM = $(strip $(DUMMYVM)) >> $(INFOMAKELOG)
endif
	@echo CUSTOM_RELEASE = $(strip $(CUSTOM_RELEASE)) >> $(INFOMAKELOG)
	@echo MTK_SUBSIDIARY = $(strip $(MTK_SUBSIDIARY)) >> $(INFOMAKELOG)
   # -----------------------------
   # Clean third party files
   # -----------------------------
	@if exist "$(RELEASE_DIR)"\tools\make.exe (del "$(RELEASE_DIR)"\tools\make.exe)
	@if exist "$(RELEASE_DIR)"\lcmmi\Customer\ResGenerator\7za.exe \
		(del "$(RELEASE_DIR)"\lcmmi\Customer\ResGenerator\7za.exe)
	@if exist "$(RELEASE_DIR)"\plutommi\Customer\ResGenerator\7za.exe \
		(del "$(RELEASE_DIR)"\plutommi\Customer\ResGenerator\7za.exe)
	@if exist "$(RELEASE_DIR)"\lcmmi\Customer\ResGenerator\convert.exe \
		(del "$(RELEASE_DIR)"\lcmmi\Customer\ResGenerator\convert.exe)
	@if exist "$(RELEASE_DIR)"\plutommi\Customer\ResGenerator\convert.exe \
		(del "$(RELEASE_DIR)"\plutommi\Customer\ResGenerator\convert.exe)
	@if exist "$(RELEASE_DIR)"\tools\MSYS (rd /s /q "$(RELEASE_DIR)"\tools\MSYS)
	@if exist "$(RELEASE_DIR)"\tools\MinGW (rd /s /q "$(RELEASE_DIR)"\tools\MinGW)

ifeq ($(strip $(DUMMYVM)),TRUE)
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),KVM)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h)
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),IJET)
  ifeq ($(strip $(J2ME_VM)),HI_VM)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp)
		@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h)
  endif
endif
ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\nativeFunctionTable.c)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMjava.c)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\NativesTable.cpp)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMImage.cpp)
	@if exist $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h (type nul > $(strip "$(RELEASE_DIR)")\custom\j2me\$(strip $(BOARD_VER))\ROMStructs.h)
endif
endif

   # -----------------------------
   # Clean temporary files in make directory
   # -----------------------------
	@echo Cleaning make\~*.tmp files ...
	@if exist make\~*.tmp \
		(del make\~*.tmp)
	@echo Cleaning make\~*.lis files ...
	@if exist make\~*.lis \
		(del make\~*.lis)
	@echo Done.

   