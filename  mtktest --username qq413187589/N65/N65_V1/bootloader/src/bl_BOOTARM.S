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
; *   bl_bootarm.s
; *
; * Project:
; * --------
; *   Bootloader
; *
; * Description:
; * ------------
; *   This Module defines the boot sequence of asm level.
; *
; * Author:
; * -------
; *   Shalyn Chua (mtk00576)
; *
; *============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * $Revision$
; * $Modtime$
; * $Log$
; *
; * Aug 7 2007 mtk01500
; * [MAUI_00530954] [System Service] Check in the feature of HW ID check
; * 
; *------------------------------------------------------------------------------
; * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *============================================================================
; ****************************************************************************/
;
                
Mode_USR       EQU      &10
Mode_FIQ       EQU      &11
Mode_IRQ       EQU      &12
Mode_SVC       EQU      &13
Mode_ABT       EQU      &17
Mode_UNDEF     EQU      &1B
Mode_SYS       EQU      &1F    

SUP_MODE       EQU      &13                 ; Supervisor Mode (SVC)
LOCKOUT        EQU      &C0                 ; Interrupt lockout value
LOCK_MSK       EQU      &C0                 ; Interrupt lockout mask value
MODE_MASK      EQU      &1F                 ; Processor Mode Mask
I_Bit          EQU      &80
F_Bit          EQU      &40
I_BIT          EQU      &80                 ; Interrupt bit of CPSR and SPSR
F_BIT          EQU      &40                 ; Interrupt bit of CPSR and SPSR
INT_BIT			EQU		&C0					  ; Interrupt bits

SPV_STACK_SIZE EQU      4096

   IF  (:LNOT: :DEF: __CHIP_VERSION_CHECK__)
      GBLL         __CHIP_VERSION_CHECK__
__CHIP_VERSION_CHECK__   SETL    {FALSE}
   ENDIF

      AREA |STACK_POOL_INTSRAM|, DATA, READWRITE, ALIGN=3
  
SPV_Stack_Pool
   SPACE    SPV_STACK_SIZE


      AREA |C$$code|, CODE, READONLY
      
;        .TEXT
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    ENTRY    
    B     ResetHandler
    
Undefined_Handler
    B   Undefined_Handler
    
SWIHandler
    B   SWIHandler

Prefetch_Handler    
    B   Prefetch_Handler

Abort_Handler    
    B   Abort_Handler
    
Reserved_vector
    B   Reserved_vector

IrqHandler    
    B   IrqHandler

FiqHandler    
    B   FiqHandler
    
   EXPORT   JumpCmd
      
   IMPORT   C_Main
   IMPORT   INTConfig

   IF __CHIP_VERSION_CHECK__
   IMPORT   INT_Version_Check
   ENDIF

   IMPORT   InitRegions   
            
BOOT_Stack_End
   DCD   SPV_Stack_Pool+SPV_STACK_SIZE-4 
 
   
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

ResetHandler
  
   ; Initialize stack pointer for Supervisor Mode Stack
   LDR   a1, BOOT_Stack_End
   MOV   sp, a1
          
   IF __CHIP_VERSION_CHECK__
   LDR     a4,=INT_Version_Check
   MOV    lr, pc
   BX      a4
   ENDIF

   BL    INTConfig
   BL    InitRegions       
      
   BL    C_Main 
   
End_BootLoader
   B     End_BootLoader


;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

JumpCmd
   BX      r0
      
   END
