;/*****************************************************************************
;*  Copyright Statement:
;*  --------------------
;*  This software is protected by Copyright and the information contained
;*  herein is confidential. The software may not be copied and the information
;*  contained herein may not be used or disclosed except with the written
;*  permission of MediaTek Inc. (C) 2005
;*
;*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
;*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
;*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
;*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
;*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
;*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
;*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
;*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
;*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
;*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
;*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
;*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
;*
;*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
;*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
;*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
;*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
;*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
;*
;*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
;*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
;*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
;*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
;*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
;*
;*****************************************************************************/
;
;/*****************************************************************************
; *
; * Filename:
; * ---------
; *   regioninit.s
; *
; * Project:
; * --------
; *   Maui_Software
; *
; * Description:
; * ------------
; *   This Module defines the initialization of RW/ZI/RO data for each area..
; *
; * Author:
; * -------
; *   Rex   Luo    (mtk00389)
; *   Anthony Chin (mtk00276)
; *   Shalyn Chua  (mtk00576)
; *
; *============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * $Revision:   1.14  $
; * $Modtime:   Aug 15 2005 11:47:06  $
; * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/init/src/regioninit_ads.s-arc  $
; *
; * Sep 6 2007 mtk01568
; * [MAUI_00541308] [System Service] [MT6238] Check-in MT6238 Compile Option into Maintrunk.
; * 
; *
; * Sep 2 2007 mtk01568
; * [MAUI_00541308] [System Service] [MT6238] Check-in MT6238 Compile Option into Maintrunk.
; * 
; *
; * Sep 2 2007 mtk01568
; * [MAUI_00541308] [System Service] [MT6238] Check-in MT6238 Compile Option into Maintrunk.
; * 
; *
; * Jul 15 2007 mtk01568
; * [MAUI_00416979] [System Service] [6223P] Check-in 6223P compile option into MAUI/07A.
; * 
; *
; * Jul 5 2007 mtk01568
; * [MAUI_00413251] [System Service] [6226D] Check-in 6226D compile option into MAUI/07A/06B.
; * 
; *
; * May 1 2007 MTK01568
; * [MAUI_00384134] [System Service] [6223] Check-in 6223 related files into main trunk.
; * 
; *
; * Apr 9 2007 mtk01077
; * [MAUI_00377311] [INIT] region_init platform condition syntax correction
; * 
; *
; * Mar 29 2007 mtk01077
; * [MAUI_00377311] [INIT] region_init platform condition syntax correction
; * 
; *
; * Mar 25 2007 MTK01568
; * [MAUI_00375788] [System Service] [6227D] Check-in 6227D related files into main trunk.
; * 
; *
; * Mar 23 2007 mtk00576
; * [MAUI_00359377] [System Service][New Feature] Porting MAUI to support MT6223
; * Bug fix, boot-up failure for MT6223.
; *
; * Feb 8 2007 mtk01337
; * [MAUI_00361983] [NOR][FDM]Enhanced Single Bank NOR Flash Support
; * modify SINGLE_BANK_SUPPORT define
; *
; * Feb 6 2007 mtk01337
; * [MAUI_00361983] [NOR][FDM]Enhanced Single Bank NOR Flash Support
; * add initialization code for single bank RAM code
; *
; * Jan 18 2007 mtk00576
; * [MAUI_00359377] [System Service][New Feature] Porting MAUI to support MT6223
; * Porting for MT6223.
; *
; * Dec 4 2006 mtk01077
; * [MAUI_00348452] Custom\System\BB\* auto generator stage 3 phase-in , scatter file
; * 
; *
; * Nov 20 2006 mtk01077
; * [MAUI_00344919] [INIT] speed up ZI procedure in region init
; * 
; *
; * Nov 10 2006 mtk00576
; * [MAUI_00342298] [Bootloader, Init, Custom][Add Feature] MT6225 supports NFB
; * Switch the order of INSTRAM_Multimedia.
; *
; * Oct 5 2006 mtk00702
; * [MAUI_00323865] [system service][AddFeature] add MT6225 support in MAUI
; * add compilation flag
; *
; * Aug 29 2006 mtk01077
; * [MAUI_00325483] [INIT][Custom] Enable MPU on all RO-code and RO-data, Rearrange scattar file layout
; * 
; *
; * Jul 17 2006 mtk00702
; * [MAUI_00211187] [System service][AddFeature] Add compilation flag to support MT6230
; * add compilation flag MT6230
; 
;    Rev 1.14   Aug 15 2005 11:47:48   mtk00576
; Copy and zero-initialize the INTSRAM_MULTIMEDIA region.
; Resolution for 12335: [CUSTOM][Enhancement] Improve performance of multi-media
; 
;    Rev 1.13   Aug 02 2005 11:40:46   mtk00576
; Remove redundant functions.
; Resolution for 12098: [Init, Inc, drv, custom][Add Feature] Porting system to MT6226, MT6227 and MT6229
; 
;    Rev 1.12   Jul 28 2005 17:55:58   mtk00576
; Porting to MT6226, MT6227 and MT6229.
; Resolution for 12098: [Init, Inc, drv, custom][Add Feature] Porting system to MT6226, MT6227 and MT6229
; 
;    Rev 1.11   Jun 13 2005 09:27:22   BM
; add copyright and disclaimer
; 
;    Rev 1.10   May 29 2005 12:43:44   mtk00576
; Porting to MT6228
; Resolution for 11274: [System][Enhancement] Support MT6228
; 
;    Rev 1.9   Feb 01 2005 17:06:58   mtk00702
; 1. move the compile option- _SIMULATION
; 2. replace "MOVE PC, R7" with "BX R7" such that InitRegions can be invoked by C code
; Resolution for 9731: [INIT, SST][AddFeature] Add Chip UID feature
; 
;    Rev 1.8   Nov 08 2004 18:13:24   mtk00702
; disable initialization of ZI region for co-sim
; Resolution for 8658: [INIT, SST, DRV]Use compile option for co-sim load
; 
;    Rev 1.7   Oct 06 2004 10:16:26   mtk00576
; Making MT6217 available.
; Resolution for 8084: [System Service][Enhancement] Porting MAUI to MT6217
; 
;    Rev 1.6   Jun 06 2004 18:29:02   mtk00576
; At MT6219, configure 256KB internal SRAM for Multi-media.
; 
;    Rev 1.5   Apr 30 2004 22:19:38   mtk00576
; Activate internal SRAM in MT6219.
; 
;    Rev 1.4   Nov 20 2003 16:20:22   mtk00576
; Modify InitRegions to meet both MT6218 and MT6218B.
; Resolution for 3225: [Init][Add Feature]Porting to support MT6218B.
; 
;    Rev 1.3   Oct 29 2003 16:12:56   mtk00576
; Porting to MT6218B.
; Resolution for 3225: [Init][Add Feature]Porting to support MT6218B.
; 
;    Rev 1.2   Jun 06 2003 13:20:14   mtk00389
; Modify to split INTSRAM_CODE and INTSRAM_DATA
; Resolution for 93: Integration with MT6218
; 
;    Rev 1.1   Jun 03 2003 10:43:18   mtk00389
; Modify for MT6218, add region init
; Resolution for 93: Integration with MT6218
; 
;    Rev 1.0   Nov 30 2002 19:49:56   admin
; Initial revision.
; *------------------------------------------------------------------------------
; * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *============================================================================
; ****************************************************************************/

;**************************************************************
;*     File: regioninit.s                                     *
;*  Purpose: Application Startup Code                         *
;**************************************************************
;
; This file contains the macro and supporting subroutines to
; copy RO code and RW data from ROM to RAM and zero-initialize
; the ZI data areas in RAM.


; All of this should be set as an assembler argument using the -pd option.
; For example to set support for Angel it would be -pd "MT6218 SETL {TRUE}"
; see also make\comp.mak


;  /* Added by Anthony Chin 10/28/2001. */
 CODE32
 
        AREA RegionInit, CODE, READONLY

        EXPORT INT_InitRegions
        EXPORT INT_InitInternalRegions
        EXPORT SYS_InitRegions

; This macro:
; a) copies RO code and/or RW data from ROM at Load$$area$$Base
; to RAM at Image$$area$$Base, of length Image$$area$$Length bytes.
; b) fills with zero the ZI data in RAM at Image$$area$$ZI$$Base, 
; of length Image$$area$$ZI$$Length bytes.
        
        MACRO
        macro_RegionInit $areaname

        LCLS   namecp
        LCLS   copyloadsym
        LCLS   copybasesym
        LCLS   copylensym
        LCLS   zibasesym
        LCLS   zilensym

namecp SETS "$areaname"

copyloadsym SETS  "|Load$$$$":CC:namecp:CC:"$$$$Base|"
copybasesym SETS  "|Image$$$$":CC:namecp:CC:"$$$$Base|"
copylensym  SETS  "|Image$$$$":CC:namecp:CC:"$$$$Length|"
zibasesym   SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Base|"
zilensym    SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Length|"

; The following symbols are generated by the linker.  They are imported 
; WEAKly because they may not all have defined values. Those which are
; undefined will take the value zero.

        IMPORT $copyloadsym, WEAK
        IMPORT $copybasesym, WEAK
        IMPORT $copylensym, WEAK
        IMPORT $zibasesym, WEAK
        IMPORT $zilensym, WEAK
        
        IF :DEF: _SIMULATION

                                        ; For co-sim load,
                                        ; memory is initialized by hardware...   

        ELSE  ; _SIMULATION 

        LDR     r0, =$copyloadsym       ; load address of region
        LDR     r1, =$copybasesym       ; execution address of region
        MOV     r2, r1                  ; copy execution address into r2
        LDR     r4, =$copylensym
        ADD     r2, r2, r4              ; add region length to execution address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of execution region
        BL      copy

        LDR     r2, =$zilensym          ; get length of ZI region
        LDR     r0, =$zibasesym         ; load base address of ZI region
        MOV     r1, r0                  ; copy base address of ZI region into r1
        ADD     r1, r1, r2              ; add region length to base address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of ZI region
        BL      zi_init_32

        ENDIF ; _SIMULATION 

        MEND
        
; This macro:
; a) fills with zero the ZI data in RAM at Image$$area$$ZI$$Base, 
; of length Image$$area$$ZI$$Length bytes.

        MACRO
        macro_ZeroInit $areaname
        
        LCLS   namecp
        LCLS   copyloadsym
        LCLS   copybasesym
        LCLS   copylensym
        LCLS   zibasesym
        LCLS   zilensym

namecp SETS "$areaname"

copyloadsym SETS  "|Load$$$$":CC:namecp:CC:"$$$$Base|"
copybasesym SETS  "|Image$$$$":CC:namecp:CC:"$$$$Base|"
copylensym  SETS  "|Image$$$$":CC:namecp:CC:"$$$$Length|"
zibasesym   SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Base|"
zilensym    SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Length|"

; The following symbols are generated by the linker.  They are imported 
; WEAKly because they may not all have defined values. Those which are
; undefined will take the value zero.

        IMPORT $copyloadsym, WEAK
        IMPORT $copybasesym, WEAK
        IMPORT $copylensym, WEAK
        IMPORT $zibasesym, WEAK
        IMPORT $zilensym, WEAK        
        
        LDR     r2, =$zilensym          ; get length of ZI region
        LDR     r0, =$zibasesym         ; load base address of ZI region
        MOV     r1, r0                  ; copy base address of ZI region into r1
        ADD     r1, r1, r2              ; add region length to base address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of ZI region
        BL      zi_init_32

        MEND

; This macro:
; a) copies RO code and/or RW data from ROM at Load$$area$$Base
; to RAM at Image$$area$$Base, of length Image$$area$$Length bytes.

        MACRO
        macro_CopyRW $areaname
        
        LCLS   namecp
        LCLS   copyloadsym
        LCLS   copybasesym
        LCLS   copylensym
        LCLS   zibasesym
        LCLS   zilensym

namecp SETS "$areaname"

copyloadsym SETS  "|Load$$$$":CC:namecp:CC:"$$$$Base|"
copybasesym SETS  "|Image$$$$":CC:namecp:CC:"$$$$Base|"
copylensym  SETS  "|Image$$$$":CC:namecp:CC:"$$$$Length|"
zibasesym   SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Base|"
zilensym    SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Length|"

; The following symbols are generated by the linker.  They are imported 
; WEAKly because they may not all have defined values. Those which are
; undefined will take the value zero.

        IMPORT $copyloadsym, WEAK
        IMPORT $copybasesym, WEAK
        IMPORT $copylensym, WEAK
        IMPORT $zibasesym, WEAK
        IMPORT $zilensym, WEAK

        LDR     r0, =$copyloadsym       ; load address of region
        LDR     r1, =$copybasesym       ; execution address of region
        MOV     r2, r1                  ; copy execution address into r2
        LDR     r4, =$copylensym
        ADD     r2, r2, r4              ; add region length to execution address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of execution region
        BL      copy

        MEND         
                
;
; INT_InitRegions is called from boot.s to initialize the specified execution regions.
; NoteXXX: The register r12 will be used in the bootarm.s. We should be careful not to
;          overwrite r12.
; 
INT_InitInternalRegions
   MOV   r7,lr
   
   IF :DEF:_NAND_FLASH_BOOTING_


   macro_RegionInit INTSRAM_CODE
   macro_RegionInit INTSRAM_DATA


   ELSE ; _NAND_FLASH_BOOTING_  


   IF :DEF: MT6205B :LOR: :DEF: MT6223 :LOR: :DEF: MT6223P
      macro_RegionInit INTSRAM
   ELSE
      macro_RegionInit INTSRAM_CODE
      macro_RegionInit INTSRAM_DATA
   ENDIF

   IF :DEF:MT6219 :LOR: :DEF:MT6226 :LOR: :DEF:MT6227 :LOR: :DEF:MT6228 :LOR: :DEF:MT6229 :LOR: :DEF:MT6226M :LOR: :DEF:MT6230 :LOR: :DEF:MT6225 :LOR: :DEF:MT6227D :LOR: :DEF:MT6226D :LOR: :DEF:MT6238
   macro_RegionInit INTSRAM_MULTIMEDIA
   ENDIF


   ENDIF; _NAND_FLASH_BOOTING_  
   
   BX    r7                                 ; Return to caller

INT_InitRegions

   MOV   r7,lr
   
   IF :DEF:_NAND_FLASH_BOOTING_

   macro_RegionInit PRIMARY_EXTSRAM
   macro_ZeroInit   SECONDARY_EXTSRAM
   macro_ZeroInit   SECONDARY_EXTSRAM_LARGEPOOL_NORMAL
   
   IF :DEF: MT6229 :LOR: :DEF: MT6230
      macro_ZeroInit SECONDARY_EXTSRAM_DSP_TX
      macro_ZeroInit SECONDARY_EXTSRAM_DSP_RX
   ENDIF

   ELSE ; _NAND_FLASH_BOOTING_  

   IF :DEF:MT6238
      macro_RegionInit PAGE_TABLE
      macro_RegionInit CACHED_EXTSRAM
   ENDIF
   macro_RegionInit EXTSRAM

   IF :DEF:SINGLE_BANK_SUPPORT
      macro_RegionInit SINGLE_BANK_CODE
   ENDIF

   IF :DEF:MT6205B
   
   ELSE
      macro_ZeroInit EXTSRAM_LARGEPOOL_NORMAL
   ENDIF

   macro_RegionInit CODE_PATCH_CODE

   IF :DEF:MT6229 :LOR: :DEF:MT6230  :LOR: :DEF:MT6223 :LOR: :DEF: MT6223P :LOR: :DEF:MT6238
      macro_RegionInit EXTSRAM_DSP_TX
      macro_RegionInit EXTSRAM_DSP_RX
   ENDIF

   ENDIF ; _NAND_FLASH_BOOTING_

   BX    r7                                 ; Return to caller


SYS_InitRegions

   MOV   r7,lr

   ; /* save working regsters since this function may be called by a C-code caller */
   STMDB sp!, {r0-r4}

   IF :DEF:_NAND_FLASH_BOOTING_

   macro_CopyRW SECONDARY_EXTSRAM
   macro_RegionInit INTSRAM_MULTIMEDIA

   macro_RegionInit CODE_PATCH_CODE

   IF :DEF:MT6229 :LOR: :DEF:MT6230
      macro_CopyRW SECONDARY_EXTSRAM_DSP_TX
      macro_CopyRW SECONDARY_EXTSRAM_DSP_RX
   ENDIF 
      
   ENDIF ; _NAND_FLASH_BOOTING_

   LDMIA sp!, {r0-r4}

   BX    r7                                 ; Return to caller


; --- copy and zi_init subroutines

; copy is a subroutine which copies a region, from an address given by 
; r0 to an address given by r1. The address of the word beyond the end
; of this region is held in r2. r3 is used to hold the word being copied. 
copy
        CMP     r1, r2                 ; loop whilst r1 < r2
        LDRLO   r3, [r0], #4
        STRLO   r3, [r1], #4
        BLO     copy
        MOV     pc, lr                 ; return from subroutine copy

; zi_init is a subroutine which zero-initialises a region,
; starting at the address in r0. The address of the word
; beyond the end of this region is held in r1.
zi_init
        MOV     r2, #0
        CMP     r0, r1                 ; loop whilst r0 < r1
        STRLO   r2, [r0], #4
        BLO     zi_init 
        MOV     pc, lr                 ; return from subroutine zi_init

; zi_init_32 is a subroutine which zero-initialises a region,
; starting at the address in r0. The length is held in r2.
; the address of the 4-byte beyound the end of this region is 
; held in r1. set 32 bytes zero per loop.
zi_init_32
        STMDB   sp!, {r8-r10}          ; save extra working register
        MOV     r3, #0
        MOV     r8, #0
        MOV     r9, #0
        MOV     r10, #0
        SUBS    r2, r2, #0x20          ; loop while r2 > 32

zi_init_32_loop
        STMCSIA r0!, {r3,r8-r10}
        STMCSIA r0!, {r3,r8-r10}
        SUBCSS  r2, r2, #0x20          ; loop while r2 > 32
        BCS     zi_init_32_loop
        LDMIA   sp!, {r8-r10}          ; restore extra working register
        B       zi_init
        MOV     pc, lr                 ; return from subroutine zi_init
        END

