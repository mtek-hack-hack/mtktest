Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))
# *************************************************************************
# Java Feature Setting
# *************************************************************************

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)

        COM_DEFS += SUPPORT_CMCC
        COM_DEFS += SUPPORT_HTTP_OVER_WSP
        
        ifdef J2ME_FEATURE_SET
          ifeq ($(strip $(call Upper,$(J2ME_FEATURE_SET))),JTWI)
            COM_DEFS += SUPPORT_WMA
            COM_DEFS += SUPPORT_JSR_120
            COM_DEFS += SUPPORT_MMAPI
            COM_DEFS += SUPPORT_JSR_135
            COM_DEFS += SUPPORT_JSR_75_FILE
        
            ifdef SUPPORT_JSR_75_PIM
              ifeq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM))),TRUE)
                COM_DEFS += SUPPORT_JSR_75_PIM
              endif
            endif
        
            ifdef SUPPORT_JSR_184
              ifeq ($(strip $(call Upper,$(SUPPORT_JSR_184))),TRUE)
                COM_DEFS += SUPPORT_JSR_184_IN_JAVA
                COM_DEFS += J2ME_JSR184_SUPPORT        
                COM_DEFS += SUPPORT_JSR_184
              endif
            endif
        
            ifdef SUPPORT_JSR_205
              ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
                COM_DEFS += SUPPORT_WMA_MMS
                COM_DEFS += SUPPORT_JSR_205
              endif
            endif
            
          endif
        endif
        
        ifdef SUPPORT_INFUSIO
          ifeq ($(strip $(call Upper,$(SUPPORT_INFUSIO))),TRUE)
            COM_DEFS += SUPPORT_INFUSIO
            COM_DEFS += __SUPPORT_INFUSIO__
          endif
        endif
        
        ifdef SUPPORT_SURFKITCHEN
          ifeq ($(strip $(call Upper,$(SUPPORT_SURFKITCHEN))),TRUE)
            COM_DEFS += SUPPORT_SURFKITCHEN
          endif
        endif

    endif
endif

# *************************************************************************
# J2ME OTHER COMPILE OPTION
# *************************************************************************

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        ifeq ($(strip $(J2ME_VM)),KVM)
            COM_DEFS    += __KVM__
        endif
        ifeq ($(strip $(J2ME_VM)),HI_VM)
            COM_DEFS    += __HI_VM__
        endif
        ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
            COM_DEFS    += __KVM__
        endif
        ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
            COM_DEFS    += __HI_VM__
        endif
        ifeq ($(strip $(J2ME_VM)),JAZELLE)
            COM_DEFS    += __JAZELLE__
        endif
    endif
endif

ifdef J2ME_SUPPORT
  ifneq ($(strip $(J2ME_SUPPORT)),NONE)
     COM_DEFS += __J2ME__  
      ifneq ($(findstring __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
           ifneq ($(findstring __THREE_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__THREE_KEY_DETECTION_SWITCHABLE__)                        
                 COM_DEFS +=   __TWO_KEY_DETECTION_SWITCHABLE__
           endif
      endif     
  endif

  ifeq ($(strip $(J2ME_SUPPORT)),IJET)
     ifeq ($(strip $(J2ME_VM)),KVM)
          COM_DEFS    += CLDC11 __IJET_VM__
     endif
  
     ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
        COM_DEFS    += CLDC11 __IJET_VM__
     endif
  
     ifeq ($(strip $(J2ME_VM)),HI_VM)
        COM_DEFS    += CLDCHI __IJET_VM__
     endif
   
     ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
        COM_DEFS    += CLDCHI __IJET_VM__
     endif
  endif
 
  ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
     COM_DEFS    += __JBLENDIA__ AJ_LITTLE_ENDIAN __UCS2_ENCODING APLIX_JAVA AJ_PLATFORM_ARM
  endif

  ifeq ($(strip $(J2ME_SUPPORT)),JBED)
     COM_DEFS    += __JBED__
  endif
  
endif


# *************************************************************************
# J2ME LIBRARY CONFIG
# *************************************************************************
ifdef J2ME_SUPPORT

    ifeq ($(strip $(J2ME_SUPPORT)),IJET)
        ifeq ($(strip $(J2ME_VM)),HI_VM)
            COMPOBJS    += j2me\vm\ijet\j2me_hi.lib
        endif
        
        ifeq ($(strip $(J2ME_VM)),KVM)
            COMPOBJS    += j2me\vm\ijet\j2me_11.lib
        endif
    endif
    
    ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
        ifeq ($(strip $(J2ME_VM)),KVM)
            ifeq ($(strip $(J2ME_FEATURE_SET)),JTWI)
               ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
                   JBLENDIA_LIB = CLDC11_JTWI10_FC_PIM_WMA20
               else
                   ifeq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM))),TRUE)
                       JBLENDIA_LIB = CLDC11_JTWI10_FC_PIM
                   else
                       JBLENDIA_LIB = CLDC11_JTWI10_FC
                   endif
               endif
            endif                        
        endif
    
        ifeq ($(strip $(J2ME_VM)),HI_VM)
            ifeq ($(strip $(J2ME_FEATURE_SET)),JTWI)
                ifeq ($(strip $(call Upper,$(SUPPORT_JSR_205))),TRUE)
                    JBLENDIA_LIB = CLDCHI_JTWI10_FC_PIM_WMA20
                else
                    ifeq ($(strip $(call Upper,$(SUPPORT_JSR_75_PIM))),TRUE)
                        JBLENDIA_LIB = CLDCHI_JTWI10_FC_PIM
                        
                    else
                        JBLENDIA_LIB = CLDCHI_JTWI10_FC    
                    endif
                endif
            endif
        endif                        
    
        COMPOBJS    += j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\ajsc_arm_ads.a \
            j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\libmjb2.a \
            j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.a
            
        CUS_REL_OBJ_LIST += j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\ajsc_arm_ads.a  \
                        j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\libmjb2.a  \
                        j2me\vm\JBlendia\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.a \
                        j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\ajsc_win32_msvc.lib \
                        j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\libmjb2.lib \
                        j2me\vm\jblendia\lib\$(strip $(JBLENDIA_LIB))\libaicrypto.lib
    endif
    
    ifeq ($(strip $(J2ME_SUPPORT)),JBED)
         COMPOBJS += j2me\vm\jbed\lib\libjbedfbcc.lib
         CUS_REL_OBJ_LIST += j2me\vm\jbed\lib\libjbedfbcc.lib
    endif
endif

# *************************************************************************
# J2ME PATH SETTING
# *************************************************************************

ifdef J2ME_SUPPORT
    COMMINCDIRS += j2me\interface
    
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
            CUSTOM_COMMINC    +=    custom\j2me\JBLENDIA\$(strip $(BOARD_VER))
        endif
        
        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
            CUSTOM_COMMINC    +=    custom\j2me\IJET\$(strip $(BOARD_VER))
        endif
    
        ifeq ($(strip $(J2ME_SUPPORT)),JBED)
            CUSTOM_COMMINC    +=    custom\j2me\JBED\$(strip $(BOARD_VER))
        endif
    
        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
            CUSTOM_COMMINC    +=    custom\j2me\DUMMY\_DEFAULT_BB
        endif
    endif
endif

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        COMMINCDIRS += plutommi\mmi\Organizer\OrganizerInc
        COMMINCDIRS += j2me\jal\include

        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
            CUS_REL_BASE_COMP += custom\j2me\IJET\_DEFAULT_BB\builtin_game_generator
            COMMINCDIRS += custom\j2me\IJET\$(strip $(BOARD_VER)) custom\j2me\IJET\_DEFAULT_BB
        endif  

        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
            CUS_REL_BASE_COMP += custom\j2me\JBLENDIA\_DEFAULT_BB\jblend_preinstall
            COMMINCDIRS += custom\j2me\JBLENDIA\$(strip $(BOARD_VER)) custom\j2me\JBLENDIA\_DEFAULT_BB
            COMMINCDIRS += j2me\vm\JBlendia\include\aci j2me\vm\JBlendia\include\ksi
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),JBED)
            COMMINCDIRS += custom\j2me\JBED\$(strip $(BOARD_VER)) custom\j2me\JBED\_DEFAULT_BB
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
            COMMINCDIRS += custom\j2me\DUMMY\_DEFAULT_BB
        endif
    endif
endif

# *************************************************************************
# J2ME COMPLIST AND CUS_REL CONFIG
# *************************************************************************

ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
        COMPLIST    += jal
        CUS_REL_SRC_COMP += jal
        
        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
            ifeq ($(strip $(J2ME_VM)),HI_VM_SOURCE)
                COMPLIST    += j2me_hi
                CUS_REL_SRC_COMP += j2me_hi
            endif
            ifeq ($(strip $(J2ME_VM)),KVM_SOURCE)
                COMPLIST    += j2me_11
                CUS_REL_SRC_COMP += j2me_11
            endif

            ifeq ($(strip $(J2ME_VM)),KVM)
                CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_11.lib
            endif
        
            ifeq ($(strip $(J2ME_VM)),HI_VM)
                CUS_REL_OBJ_LIST  +=   j2me\vm\IJET\j2me_hi.lib
            endif
        endif
    
    
        ifeq ($(strip $(J2ME_SUPPORT)),IJET)
            COMPLIST    += ijet_adp
            CUS_REL_SRC_COMP += ijet_adp
        endif

        ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
            COMPLIST    += jblendia
            CUS_REL_SRC_COMP    += jblendia
        endif
        
        ifeq ($(strip $(J2ME_SUPPORT)),JBED)
            COMPLIST += jbed
            CUS_REL_SRC_COMP += jbed
        endif    
        
        ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
            COMPLIST    += jdummy
            CUS_REL_SRC_COMP += jdummy
        endif
        
    endif 
endif

# *************************************************************************
# J2ME Dependency rules
# *************************************************************************
ifdef J2ME_SUPPORT
  ifeq ($(strip $(J2ME_SUPPORT)),IJET)
    J2ME_VM_SUPPORT_ITEM = KVM KVM_SOURCE HI_VM HI_VM_SOURCE 
    ifeq ($(findstring $(strip $(J2ME_VM)) ,$(J2ME_VM_SUPPORT_ITEM)),)
      $(error J2ME_VM does not support $(J2ME_VM) when J2ME_SUPPORT = IJET)
    endif
  endif
  ifeq ($(strip $(J2ME_SUPPORT)),JBLENDIA)
    J2ME_VM_SUPPORT_ITEM = KVM HI_VM 
    ifeq ($(findstring $(strip $(J2ME_VM)) ,$(J2ME_VM_SUPPORT_ITEM)),)
      $(error J2ME_VM does not support $(J2ME_VM) when J2ME_SUPPORT = JBLENDIA)
    endif
    ifneq ($(strip $(J2ME_FEATURE_SET)),JTWI)
      $(error J2ME_FEATURE_SET only supports JTWI when J2ME_SUPPORT = JBLENDIA)
    endif
  endif
  ifeq ($(strip $(J2ME_SUPPORT)),JBED)
    J2ME_VM_SUPPORT_ITEM = KVM  
    ifeq ($(findstring $(strip $(J2ME_VM)) ,$(J2ME_VM_SUPPORT_ITEM)),)
      $(error J2ME_VM does not support $(J2ME_VM) when J2ME_SUPPORT = JBED)
    endif
  endif
endif

ifdef SUPPORT_JSR_184
  ifeq ($(strip $(call Upper,$(SUPPORT_JSR_184))),TRUE)
    ifneq ($(J2ME_SUPPORT),IJET)
      $(error J2ME_SUPPORT must be IJET when SUPPORT_JSR_184 is TRUE)
    endif
    ifneq ($(J2ME_FEATURE_SET),JTWI)
      $(error J2ME_FEATURE_SET must be JTWI when SUPPORT_JSR_184 is TRUE)
    endif
    ifneq ($(M3D_MMI_SUPPORT),TRUE)
      $(error M3D_MMI_SUPPORT must be TRUE when SUPPORT_JSR_184 is TRUE)
    endif
  endif
endif



