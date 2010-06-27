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
; *   bootarm.s
; *
; * Project:
; * --------
; *   Maui_Software
; *
; * Description:
; * ------------
; *   This Module defines the boot sequence of asm level.
; *
; * Author:
; * -------
; *   Rex   Luo  (mtk00389)
; *   Anthony Chin (mtk00276)
; *
; *============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * $Revision:   1.38  $
; * $Modtime:   Aug 15 2005 18:13:06  $
; * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/init/src/bootarm.s-arc  $
; *
; * Mar 6 2008 mtk01568
; * [MAUI_00728818] [System Service] [Gemini] Fix the remap problem.
; * 
; *
; * Sep 26 2007 mtk01747
; * [MAUI_00548762] [Init][Add feature] Add custom_InitDRAM to initialize SDR when using NOR+SDR MCP
; * rearrange custom_InitDRAM
; *
; * Sep 16 2007 mtk01747
; * [MAUI_00548762] [Init][Add feature] Add custom_InitDRAM to initialize SDR when using NOR+SDR MCP
; * Add custom_InitDRAM to initialize SDR when using NOR+SDR MCP
; *
; * Sep 12 2007 mtk01568
; * [MAUI_00541308] [System Service] [MT6238] Check-in MT6238 Compile Option into Maintrunk.
; * 
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
; * Aug 7 2007 mtk01500
; * [MAUI_00530954] [System Service] Check in the feature of HW ID check
; * 
; *
; * Aug 7 2007 mtk01500
; * [MAUI_00530954] [System Service] Check in the feature of HW ID check
; * 
; *
; * Jul 7 2007 mtk01077
; * [MAUI_00413769] [INIT] adjust exception stack pointer to avoid corrupt neighbor global variable
; * 
; *
; * May 10 2007 mtk00702
; * [MAUI_00374374] [MT6223][BT Load]Add Burning test load
; * remove redundant EXTSRAM_BSS_Limit_Ptr
; *
; * Apr 27 2007 mtk01178
; * [MAUI_00387299] [New Chip Support][MT6230] add MT6230 support to bootarm.s
; * Add MT6230 support
; *
; * Apr 17 2007 mtk01077
; * [MAUI_00382952] [SST] Add System Stack , TIMER HISR Guard Pattern and Checking
; * 
; *
; * Feb 12 2007 mtk00702
; * [MAUI_00346291] [init][Enhancement] Check IRQ disable duration
; * add LockIRQ() and refine DisableIRQ()
; *
; * Feb 6 2007 mtk01337
; * [MAUI_00361983] [NOR][FDM]Enhanced Single Bank NOR Flash Support
; * Add remapping definition for single bank support on MT6225.
; *
; * Feb 5 2007 mtk00702
; * [MAUI_00346291] [init][Enhancement] Check IRQ disable duration
; * merge SNORCODE section into INTERNCODE section
; *
; * Jan 29 2007 mtk01337
; * [MAUI_00361983] [NOR][FDM]Enhanced Single Bank NOR Flash Support
; * enhanced single bank NOR flash support phase in
; *
; * Jan 4 2007 mtk01587
; * [MAUI_00355761] [init][AddFeature] Dynamic switch stack
; * Remove the compiler option __SW_JPEG_CODEC_SUPPORT__
; *
; * Jan 2 2007 mtk01587
; * [MAUI_00355761] [init][AddFeature] Dynamic switch stack
; * Add compile option __SW_JPEG_CODEC_SUPPORT__
; *
; * Jan 2 2007 mtk01587
; * [MAUI_00355761] [init][AddFeature] Dynamic switch stack
; * Add INT_SwitchStackAndBranch()
; *
; * Dec 26 2006 mtk01178
; * [MAUI_00342696] [New Feature][FOTA] Add firmware update over the air feature
; * modify bootarm.s to support FOTA
; *
; * Dec 8 2006 mtk00702
; * [MAUI_00339559] [kal][AddFeature] THREADX porting
; * add dummy reference
; *
; * Dec 5 2006 mtk00681
; * [MAUI_00348640] [SST] Remove JTAG control compile option
; * 
; *
; * Nov 27 2006 mtk00702
; * [MAUI_00346291] [init][Enhancement] Check IRQ disable duration
; * rename SaveAndSetIRQMask() and RestoreIRQMask() to DisableIRQ() and RestoreIRQ() respectively.
; *
; * Nov 6 2006 mtk00702
; * [MAUI_00339559] [kal][AddFeature] THREADX porting
; * add INT_GetCurrentSP()
; *
; * Oct 31 2006 mtk00702
; * [MAUI_00339559] [kal][AddFeature] THREADX porting
; * add threadx-related code
; *
; * Oct 24 2006 mtk00576
; * [MAUI_00338241] [Init][Bug Fixed]Enable SW JTAG ealier
; * Calling SST_DTLB_Init().
; *
; * Oct 23 2006 mtk01077
; * [MAUI_00337852] [INIT] independent stack pool for exception handling
; * 
; *
; * Jul 9 2006 mtk01337
; * [MAUI_00208924] [SST][Enhancement] keep the sp used before abnormal reset
; * Save current sp value before INT_System_Reset_Check( )
; 
;    Rev 1.38   Aug 15 2005 18:19:58   mtk00576
; Assign SaveAndSetIRQMask and RestoreIRQMask to internal SRAM.
; Resolution for 12357: [INIT, CUSTOM][Add Feature] System site supports single bank NOR-flash solution
; 
;    Rev 1.37   Jul 28 2005 17:20:14   mtk00576
; Adding custom_setAdvEMI.
; Resolution for 12098: [Init, Inc, drv, custom][Add Feature] Porting system to MT6226, MT6227 and MT6229
; 
;    Rev 1.36   Jun 27 2005 12:23:44   mtk00576
; Disable INT_Swith2BurstMode.
; Resolution for 11695: [Init, Custom, SST][Enhancement] Leaving EMI setting outside of MAUI
; 
;    Rev 1.35   Jun 13 2005 09:27:20   BM
; add copyright and disclaimer
; 
;    Rev 1.34   May 29 2005 12:43:44   mtk00576
; Porting to MT6228
; Resolution for 11274: [System][Enhancement] Support MT6228
; 
;    Rev 1.33   May 06 2005 20:01:12   mtk00681
; Add ROM code initialization
; Resolution for 10959: [ROM][AddFeature] Add ROM code support on main trunk
; 
;    Rev 1.32   Feb 01 2005 17:05:12   mtk00702
; 1. invoke INT_Switch2BurstMode
; 2. add IMG_INFO
; Resolution for 9731: [INIT, SST][AddFeature] Add Chip UID feature
; 
;    Rev 1.31   Nov 08 2004 17:48:16   mtk00576
; Changing FIQ service routine.
; Resolution for 8654: [Init][Enhancement] Correction of FIQ service routine.
; 
;    Rev 1.30   Sep 24 2004 10:50:50   mtk00576
; Rest the SP to system stack rather than IRQ stack.
; Resolution for 7064: [INIT][Bug Fixed] Memory corruption at system stack.
; 
;    Rev 1.29   Aug 08 2004 22:34:08   mtk00576
; Changing stack initialization method.
; Resolution for 7064: [INIT][Bug Fixed] Memory corruption at system stack.
; 
;    Rev 1.28   Apr 27 2004 16:45:24   mtk00576
; Take abnormal reset into consideration.
; 
;    Rev 1.27   Apr 15 2004 18:43:36   mtk00576
; (1) Setting RLT to 2 rather than 7.
; (2) Adding NOP soon after remapping.
; (3) Restart watchdog at the first instruction fetched from address 0x0800____.
; Resolution for 518: Fatal Error on Internal KAL Take Mutex when power on the MS
; Resolution for 552: [PS2][Tester] System error - undefined exception
; Resolution for 956: Fatal Error:Undefined Exception lr=0x250 -?????????
; 
;    Rev 1.26   Dec 29 2003 14:54:10   mtk00702
; Re-write the comment of INT_ExceptionSwitchSP() function definition.
; 
;    Rev 1.25   Dec 12 2003 18:34:38   mtk00576
; Switching SP to system stack while system error.
; Resolution for 3530: [KAL][Enhancement]Avoid damaging stack of offending task.
; 
;    Rev 1.24   Nov 20 2003 17:34:48   mtk00576
; Merging CPU exception to stack fatal error.
; Resolution for 3374: [KAL][Enhancement]Simplify bootarm.s and adding Remapping Scheme
; 
;    Rev 1.23   Nov 19 2003 18:05:16   mtk00576
; Saving ISR return address to global variable processing_irqlr.
; Resolution for 418: Assert fail:0 m12168.c 485
; 
;    Rev 1.22   Oct 29 2003 16:06:32   mtk00576
; Porting to MT6218B.
; Resolution for 3225: [Init][Add Feature]Porting to support MT6218B.
; 
;    Rev 1.21   Oct 03 2003 21:50:18   mtk00576
; Always disable watchdog in saving exception records.
; Resolution for 3056: [Init][Bug Fixed]Flash corrupted when saving fatal errors with watchdog enabled.
; 
;    Rev 1.20   Sep 19 2003 17:28:38   mtk00576
; Masking IRQ via C function call and passing lr for tracing where abnormal reset taken place.
; Resolution for 2925: [Init][Enhance]Enhance portability and saving return addressof abnormal reset.
; 
;    Rev 1.19   Aug 22 2003 19:43:00   mtk00576
; Removing unnecessary or non-timing critical code and data from internal SRAM to fully utilize its usage.
; Resolution for 2606: Fine tuning code and data of system service occupied in internal SRAM.
; 
;    Rev 1.18   Jun 16 2003 09:10:14   mtk00576
; Declare internal stack as array, includeing IRQ, FIQ, Abort, Undefined, System and Timer HISR.
; Resolution for 2012: [Init][Enhance]Declare internal memory stack as array.
; 
;    Rev 1.17   Jun 11 2003 17:06:58   mtk00389
; Reduce IRQ stack (1024->128), System stack (1536->1024), Timer HISR stack (1024->512), and increase FIQ stack (64->128)
; 
;    Rev 1.16   Jun 06 2003 20:20:46   mtk00389
; Modify for to use INTERNSRAM_DATA as system stack
; Resolution for 93: Integration with MT6218
; 
;    Rev 1.15   May 29 2003 09:26:40   mtk00389
; Modify to save prefetch/data abort, undef instr exception after switch to supervisor mode
; Resolution for 230: General exception handling
; 
;    Rev 1.14   May 27 2003 09:02:36   mtk00389
; Move INT_Config() to external memory
; Resolution for 1705: [System][Optimization]Optimize internal RAM usage
; 
;    Rev 1.12   Mar 25 2003 15:42:40   mtk00389
; Expand stack frame up to 60longs for exception record
; Resolution for 1371: Expand saved stack frame up to 60longs for exception record
; 
;    Rev 1.11.2.0   Mar 12 2003 11:01:00   admin
; check in field trial load based on Maui_sw.W03.11
; 
;    Rev 1.11   27 Jan 2003 10:14:30   mtk00389
; Modify to use WDT timeout interval register as abornmal reset check 
; Resolution for 230: General exception handling
; 
;    Rev 1.10   22 Jan 2003 15:12:00   mtk00389
; Fix disabled codes typo
; Resolution for 223: Fix typo
; 
;    Rev 1.9   22 Jan 2003 09:07:34   mtk00389
; Modify exception record format
; Resolution for 230: General exception handling
; 
;    Rev 1.8   14 Jan 2003 16:48:40   mtk00389
; Fix save MCU information before halt
; Resolution for 230: General exception handling
; 
;    Rev 1.7   09 Jan 2003 15:27:18   mtk00389
; Fix save MCU information and stack information if assertion fail or fatal error
; 
;    Rev 1.6   02 Jan 2003 20:47:22   mtk00389
; add handler for abnormal reset case
; 
;    Rev 1.5   31 Dec 2002 16:55:58   mtk00389
; fix INT_Initialize_Check value due to endian order
; 
;    Rev 1.4   19 Dec 2002 16:54:32   mtk00389
; modify exception handler to dump task information
; 
;    Rev 1.3   19 Dec 2002 13:28:20   mtk00389
; Move set cache, preftech register codes from bootarm.s to init.c 
; 
;    Rev 1.2   17 Dec 2002 18:11:36   mtk00389
; add INT_SaveMCUInfo()
; 
;    Rev 1.1   02 Dec 2002 16:45:36   mtk00389
; optimize boot stack size for different modes
; 
;    Rev 1.0   Nov 30 2002 19:49:54   admin
; Initial revision.
; *------------------------------------------------------------------------------
; * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *============================================================================
; ****************************************************************************/
;

;/*************************************************************************/
;/*                                                                       */
;/*            Copyright (c) 1994 -2000 Accelerated Technology, Inc.      */
;/*                                                                       */
;/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
;/* subject matter of this material.  All manufacturing, reproduction,    */
;/* use, and sales rights pertaining to this subject matter are governed  */
;/* by the license agreement.  The recipient of this software implicitly  */
;/* accepts the terms of the license.                                     */
;/*                                                                       */
;/*************************************************************************/
;
;/*************************************************************************/
;/*                                                                       */
;/* FILE NAME                                            VERSION          */
;/*                                                                       */
;/*      bootarm.s                                   ARM 6/7/9 1.11.19    */
;/*                                                                       */
;/* COMPONENT                                                             */
;/*                                                                       */
;/*      IN - Initialization                                              */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This file contains the target processor dependent initialization */
;/*      routines and data.                                               */
;/*                                                                       */
;/*                                                                       */
;/* DATA STRUCTURES                                                       */
;/*                                                                       */
;/*      INT_Vectors                         Interrupt vector table       */
;/*                                                                       */
;/* FUNCTIONS                                                             */
;/*                                                                       */
;/*      INT_Initialize                      Target initialization        */
;/*      INT_Vectors_Loaded                  Returns a NU_TRUE if all the */
;/*                                            default vectors are loaded */
;/*      INT_Setup_Vector                    Sets up an actual vector     */
;/*                                                                       */
;/*                                                                       */
;/*************************************************************************/


;/* Define constants used in low-level initialization.  */
;
;
LOCKOUT                 EQU      &C0         ; Interrupt lockout value
LOCK_MSK                EQU      &C0         ; Interrupt lockout mask value
MODE_MASK               EQU      &1F         ; Processor Mode Mask
SUP_MODE                EQU      &13         ; Supervisor Mode (SVC)
                                            
IRQ_MODE                EQU      &12         ; Interrupt Mode (IRQ)
FIQ_MODE                EQU      &11         ; Fast Interrupt Mode (FIQ)
ABORT_MODE              EQU      &17         ; Abort Mode (Abort)
UND_MODE                EQU      &1b         ; Undefine Mode (Undefine)
SYS_MODE                EQU      &1f         ; System Mode (SYS)
                                            
TIMER_PRIORITY          EQU      2           ; Timer HISR priority (values from
                                            
I_BIT                   EQU      &80         ; Interrupt bit of CPSR and SPSR
F_BIT                   EQU      &40         ; Interrupt bit of CPSR and SPSR
INT_BIT                 EQU      &C0         ; Interrupt bits
T_BIT                   EQU      &20         ; Thumb mode control bit

UNDEF_EXCEPTION_TYPE    EQU      1           ; Undefine instruction exception type
SWI_EXCEPTION_TYPE      EQU      2           ; SWI exception type
PREFETCH_EXCEPTION_TYPE EQU      3           ; Preftech abort exception type
DATA_EXCEPTION_TYPE     EQU      4           ; Data abort exception type

BOOTROM_FLASH_REMAP     EQU      &02
FLASH_SRAM_REMAP        EQU      &03

IRQ_STACK_SIZE          EQU      128
FIQ_STACK_SIZE          EQU      128
OTHER_STACK_SIZE        EQU      128
EX_STACK_SIZE           EQU      2048
SYS_STACK_SIZE          EQU      2048
TIMER_SIZE              EQU      512

ABNORMAL_POOL_SIZE      EQU      16

; If assembled with TASM the variable {CONFIG} will be set to 16
; If assembled with ARMASM the variable {CONFIG} will be set to 32
; Set the variable THUMB to TRUE or false depending on whether the
; file is being assembled with TASM or ARMASM.

        GBLL    THUMB
        GBLL    ARM
    [ {CONFIG} = 16
THUMB   SETL    {TRUE}
ARM     SETL    {FALSE}

; If assembling with TASM go into 32 bit mode as the Armulator will
; start up the program in ARM state.

        CODE32
    |
THUMB   SETL    {FALSE}
ARM     SETL    {TRUE}
    ]


   IF  (:LNOT: :DEF: REMAPPING)
      GBLL         REMAPPING
REMAPPING   SETL    {FALSE}
   ENDIF

   IF  (:LNOT: :DEF: KAL_ON_NUCLEUS)
      GBLL         KAL_ON_NUCLEUS
KAL_ON_NUCLEUS   SETL    {FALSE}
   ENDIF

   IF  (:LNOT: :DEF: KAL_ON_THREADX)
      GBLL         KAL_ON_THREADX
KAL_ON_THREADX   SETL    {FALSE}
   ENDIF
   
   IF  (:LNOT: :DEF: DCM_ENABLE)
      GBLL         DCM_ENABLE
DCM_ENABLE   SETL    {FALSE}
	ENDIF

   IF  (:LNOT: :DEF: __CHIP_VERSION_CHECK__)
      GBLL         __CHIP_VERSION_CHECK__
__CHIP_VERSION_CHECK__   SETL    {FALSE}
   ENDIF


   AREA |C$$data|, DATA, READWRITE
   
   EXPORT  INT_Loaded_Flag
INT_Loaded_Flag
   DCD      &00000000
   
   EXPORT   INT_Exception_Type
INT_Exception_Type
   DCD      &00000000

;/* Define the global system stack variable.  This is setup by the
;   initialization routine.  */
;

   AREA |STACK_POOL_EXTSRAM|, DATA, READWRITE, ALIGN=3

ABT_Stack_Pool
   SPACE    OTHER_STACK_SIZE

UND_Stack_Pool
   SPACE    OTHER_STACK_SIZE

EX_Stack_Pool
   SPACE    EX_STACK_SIZE

   AREA |STACK_POOL_INTSRAM|, DATA, READWRITE, ALIGN=3
  
IRQ_Stack_Pool
   SPACE    IRQ_STACK_SIZE

FIQ_Stack_Pool
   SPACE    FIQ_STACK_SIZE

   EXPORT   SYS_Stack_Pool
SYS_Stack_Pool
   DCB      "STACKEND"
   SPACE    SYS_STACK_SIZE-8

TMD_Stack_Pool
   DCB      "STACKEND"
   SPACE    TIMER_SIZE-8
      
Abnormal_info_Pool
   SPACE    ABNORMAL_POOL_SIZE

   AREA |DUMMY_POOL|, DATA, READWRITE
DUMMY_END
   DCD      0x454E4400
   
;/* for single bank support */

   IF  (:LNOT: :DEF: SINGLE_BANK_SUPPORT)
      GBLL         SINGLE_BANK_SUPPORT
SINGLE_BANK_SUPPORT   SETL    {FALSE}
   ENDIF

   AREA |C$$code|, CODE, READONLY
|x$codeseg|

;
;
;/* Define the global data structures that need to be initialized by this
;   routine.  These structures are used to define the system timer management
;   HISR.  */
;
;

   IF KAL_ON_NUCLEUS

;extern VOID     *TMD_HISR_Stack_Ptr;
;extern UNSIGNED  TMD_HISR_Stack_Size;
;extern INT       TMD_HISR_Priority;
;extern VOID   *TCD_System_Stack;
;extern VOID   *TCD_Current_Thread;
;extern VOID   INC_Initialize(VOID *first_available_memory);
;extern VOID   TCT_Interrupt_Context_Save(VOID);
;extern VOID   TCT_Interrupt_Context_Restore(VOID);

   IMPORT  TMD_HISR_Stack_Ptr
   IMPORT  TMD_HISR_Stack_Size
   IMPORT  TMD_HISR_Priority
   IMPORT   TCD_System_Stack
   IMPORT   TCT_System_Limit
   IMPORT   TCT_Interrupt_Context_Save
   IMPORT   TCT_Interrupt_Context_Restore
   IMPORT   INC_Initialize   

   ELSE

   IMPORT   _tx_thread_system_stack_ptr
   IMPORT   _tx_thread_context_save
   IMPORT   _tx_thread_irq_nesting_start
   IMPORT   _tx_thread_irq_nesting_end
   IMPORT   _tx_thread_context_restore
   IMPORT   _tx_initialize_kernel_enter

   ENDIF

   IMPORT   INT_SystemReset_Check 
   IMPORT   INT_Config
   IMPORT   INT_InitRegions
   IMPORT   INT_InitInternalRegions
   IMPORT   custom_setAdvEMI
   IMPORT   CacheInit
   IMPORT   isrC_Main
   IMPORT   isrCTIRQ1
   IMPORT   INT_FIQ_Lisr
   IMPORT   processing_irqlr
   IMPORT   processing_fiqlr
   IMPORT   stack_system_error
   IMPORT   INT_Exception_SP
   IMPORT   rand_num_seed

   IF :DEF: _NOR_LPSDRAM_MCP_
   IMPORT   custom_InitDRAM
   ENDIF
   
   IF :DEF: MT6238
   IMPORT   custom_InitDRAM
   ENDIF

   IF DCM_ENABLE
   IMPORT  DCM_Recovery
   ENDIF

   IF __CHIP_VERSION_CHECK__
   IMPORT   INT_Version_Check
   ENDIF

   IMPORT   SST_DTLB_Init

   IF :DEF:__ROMSA_SUPPORT__  
   IMPORT InitRegions2   
   IMPORT ROMSA_Init      
   ENDIF                        

   EXPORT  DisableIRQ
   EXPORT  ReEnableIRQ
   EXPORT  LockIRQ
   EXPORT  RestoreIRQ
   EXPORT  INT_ExceptionSwitchSP
   EXPORT  INT_ExceptionResetSystemSP
   EXPORT  INT_GetCurrentSP

   IF KAL_ON_THREADX
   EXPORT __tx_irq_processing_return
   ENDIF
     
;
;/* Define the ARM60 interrupt vector table, INT_Vectors.  This table is
;   assumed to be loaded or copied to address 0.  If coexistence with a
;   target-resident-monitor program is required, it is important to only
;   copy the IRQ and possibly the FIQ interrupt vectors in this table into
;   the actual table.  The idea is to not mess with the monitor's vectors.  */
;VOID    *INT_Vectors[NU_MAX_VECTORS];
;


   EXPORT  INT_Vectors
INT_Vectors
   IF REMAPPING
      B     INT_Initialize
   ELSE
      LDR   pc,INT_Table
   ENDIF
   LDR   pc,(INT_Table + 4)
   LDR   pc,(INT_Table + 8)
   LDR   pc,(INT_Table + 12)
   LDR   pc,(INT_Table + 16)
   LDR   pc,(INT_Table + 20)
   LDR   pc,(INT_Table + 24)
   LDR   pc,(INT_Table + 28)


   EXPORT   INT_Table
INT_Table

INT_Initialize_Addr  DCD   INT_Initialize
Undef_Instr_Addr     DCD   Undef_Instr_ISR
SWI_Addr             DCD   SWI_ISR
Prefetch_Abort_Addr  DCD   Prefetch_Abort_ISR
Data_Abort_Addr      DCD   Data_Abort_ISR
Undefined_Addr       DCD   0              ; NO LONGER USED
IRQ_Handler_Addr     DCD   INT_IRQ_Parse
FIQ_Handler_Addr     DCD   INT_FIQ_Parse

INT_Table_END

   IF :LNOT::DEF:_NAND_FLASH_BOOTING_
  
ROM_Base_Ptr
   IMPORT  |Image$$ROM$$Base|
   DCD     |Image$$ROM$$Base|
   
   IF SINGLE_BANK_SUPPORT
EXTSRAM_Base_Ptr
   IMPORT  |Image$$SINGLE_BANK_CODE$$Base|
   DCD     |Image$$SINGLE_BANK_CODE$$Base|
   ELSE
EXTSRAM_Base_Ptr
   IMPORT  |Image$$EXTSRAM$$Base|
   DCD     |Image$$EXTSRAM$$Base|
   ENDIF

INT_Table_END_PTR
   DCD     INT_Table_END

   ENDIF   

Loaded_Flag
   DCD     INT_Loaded_Flag
;

   IF KAL_ON_NUCLEUS
HISR_Stack_Ptr
   DCD     TMD_HISR_Stack_Ptr
;
HISR_Stack_Size
   DCD     TMD_HISR_Stack_Size
;
HISR_Priority
   DCD     TMD_HISR_Priority
;
System_Stack
   DCD     TCD_System_Stack
;
System_Limit
   DCD     TCT_System_Limit
;
   ELSE

System_Stack
   DCD     _tx_thread_system_stack_ptr
;
   ENDIF

BOOT_IRQ_Stack_End 
   DCD     IRQ_Stack_Pool+IRQ_STACK_SIZE-4
;
BOOT_FIQ_Stack_End 
   DCD     FIQ_Stack_Pool+FIQ_STACK_SIZE-4
;
BOOT_ABT_Stack_End 
   DCD     ABT_Stack_Pool+OTHER_STACK_SIZE-4
;
BOOT_UND_Stack_End 
   DCD     UND_Stack_Pool+OTHER_STACK_SIZE-4
;
   EXPORT   BOOT_SYS_Stack_End
BOOT_SYS_Stack_End 
   DCD     SYS_Stack_Pool+SYS_STACK_SIZE-4
;
BOOT_SYS_Stack
   DCD     SYS_Stack_Pool
;
BOOT_EX_Stack_End 
   DCD     EX_Stack_Pool+EX_STACK_SIZE-16
;

   IF KAL_ON_NUCLEUS
BOOT_TMD_Stack
   DCD     TMD_Stack_Pool
;
BOOT_Timer_HISR_Stack_Size
   DCD     TIMER_SIZE
;
   ENDIF

Exception_SP_PTR
   DCD     INT_Exception_SP
   IF :DEF: MT6238
        IMPORT cp15_enable_itcm
        IMPORT cp15_enable_dtcm
        IMPORT ||Image$$INTSRAM_CODE$$Base||
        IMPORT ||Image$$INTSRAM_DATA$$Base||
   ENDIF



   IF :DEF: MT6238
;
WATCHDOG_RESTART_REG    
   DCD     0x80030008
;
WATCHDOG_RESTART_VALUE  
   DCD     0x1971
;
EMI_BASE_REG       
   DCD     0x81000000
;
EMI_26MHZ_SETTING
   DCD     0x93040110
;
   ELSE
;
WATCHDOG_RESTART_REG    
   DCD     0x80040008
;
WATCHDOG_RESTART_VALUE  
   DCD     0x1971
;
EMI_BASE_REG       
   DCD     0x80010000
;
EMI_26MHZ_SETTING
   DCD     0x44004202
;
   ENDIF
   IF  REMAPPING
MTK_INITIALIZE_PTR
   DCD     MTK_Initialize
   ENDIF
;
RAND_NUM_SEED_PTR
   DCD     rand_num_seed

;
ABN_RST_PTR
   DCD     Abnormal_info_Pool
   DCD     DUMMY_END    ; dummy reference to ensure DUMMY_END won't be optimized

;
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*                                                                       */
;/*      INT_Initialize                                                   */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This function sets up the global system stack variable and       */
;/*      transfers control to the target independent initialization       */
;/*      function INC_Initialize.  Responsibilities of this function      */
;/*      include the following:                                           */
;/*                                                                       */
;/*             - Setup necessary processor/system control registers      */
;/*             - Initialize the vector table                             */
;/*             - Setup the system stack pointers                         */
;/*             - Setup the timer interrupt                               */
;/*             - Calculate the timer HISR stack and priority             */
;/*             - Calculate the first available memory address            */
;/*             - Transfer control to INC_Initialize to initialize all of */
;/*               the system components.                                  */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/*      INC_Initialize                      Common initialization        */
;/*                                                                       */
;/* INPUTS                                                                */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/*                                                                       */
;/*************************************************************************/
;VOID    INT_Initialize(void)
;{

   ENTRY

   EXPORT  INT_Initialize
INT_Initialize
;   /* Insure that the processor is in supervisor mode.  */
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#SUP_MODE                    ; Set the supervisor mode bits
   ORR   a1,a1,#LOCKOUT                     ; Insure IRQ/FIQ interrupts are
                                            ; locked out
   MSR   CPSR_cxsf,a1                       ; Setup the new CPSR
     
   IF   REMAPPING

   IF  (:LNOT: :DEF: __FOTA_ENABLE__)   

   LDR   a4,EMI_BASE_REG                    
   IF :DEF: MT6229 :LOR: :DEF: MT6228 :LOR: :DEF: MT6225 :LOR: :DEF: MT6230 :LOR: :DEF: MT6238
   IF :DEF: MT6238
   LDR   a1,[a4,#0x70]                      
   ELSE
   LDR   a1,[a4,#0x60]                      ; Skip if it is an abnormal reset
   ENDIF
   ELSE
   LDR   a1,[a4,#0x40]
   ENDIF
   AND   a1,a1,#0x03                        ; under remapped configuration
   MOV   a2,#FLASH_SRAM_REMAP
   CMP   a1,a2
   BEQ   MTK_LoadPC
   
   LDR   a1,EMI_26MHZ_SETTING               ; Setting EMI for 13MHz MCU clock
   STR   a1,[a4]                            ; C2WS=1, C2RS=1, WST=2, RLT=2
   STR   a1,[a4,#0x08]                      ; 16 bits device
       
   MOV   a2,#BOOTROM_FLASH_REMAP            ; Restore remapping on \CS0 and \CS1
   
   IF :DEF: MT6229 :LOR: :DEF: MT6228 :LOR: :DEF: MT6225 :LOR: :DEF: MT6230 :LOR: :DEF: MT6238
   
   IF :DEF: MT6238
   LDR   a1,[a4,#0x70]                      
   BIC   a1, a1, #3
   ORR   a2, a2, a1
   STRH  a2,[a4,#0x70]
   ELSE
   STRH  a2,[a4,#0x60]
   ENDIF
   
   ELSE
   STRH  a2,[a4,#0x40]        
   ENDIF

   ENDIF                                    ;___FOTA_ENABLE
                                            
   IF  (:LNOT: :DEF: __FOTA_ENABLE__)
   MOV   a1,#0x00                           ; Copy Exception Vector table to RAM 
   LDR   a2,ROM_Base_Ptr                    ; before remapping
   LDR   a3,EXTSRAM_Base_Ptr
   ORR   a3,a2,a3
Copy_INT_Entry
   CMP   a2,a3  
   LDRLO a4,[a1], #4
   STRLO a4,[a2], #4
   BLO   Copy_INT_Entry
   
   LDR   a4,EMI_BASE_REG                    ; Remapping on \CS0 and \CS1
   MOV   a2,#FLASH_SRAM_REMAP   
   
   IF :DEF: MT6229 :LOR: :DEF: MT6228 :LOR: :DEF: MT6225 :LOR: :DEF: MT6230 :LOR: :DEF: MT6238
   
   IF :DEF: MT6238
   LDR   a1,[a4,#0x70]                      ; SHK: MT6238's remap locates at EMI+0x70.
   BIC   a1, a1, #3
   ORR   a2, a2, a1
   STRH  a2,[a4,#0x70]
   ELSE
   STRH  a2,[a4,#0x60]
   ENDIF
   ELSE
   STRH  a2,[a4,#0x40]
   ENDIF
   NOP
   NOP
   NOP
   NOP
   NOP
   NOP
   ELSE      
   MOV   a1,#0x00                           ; Copy Exception Vector table to RAM 
   LDR   a2,ROM_Base_Ptr                    ; before remapping
   LDR   a3,INT_Table_END_PTR
   ORR   a3,a2,a3
Copy_INT_Entry
   CMP   a2,a3  
   LDRLO a4,[a2], #4
   STRLO a4,[a1], #4
   BLO   Copy_INT_Entry
   ENDIF

MTK_LoadPC   
   LDR   pc,MTK_INITIALIZE_PTR   
   
MTK_Initialize   
   ENDIF

   LDR   a1,WATCHDOG_RESTART_REG            ; Restart watchdog
   LDR   a2,WATCHDOG_RESTART_VALUE
   STR   a2,[a1]
      
;   /* keep lr and sp for abnormal case */
   LDR   a1,ABN_RST_PTR
   STR   lr,[a1]                            ; Where abnormal reset from?
   STR   sp,[a1, #0x4]

   IF :DEF: MT6238
      LDR r0, =||Image$$INTSRAM_CODE$$Base||
      BL cp15_enable_itcm

      LDR r0, =||Image$$INTSRAM_DATA$$Base||      
      BL cp15_enable_dtcm
   ENDIF

   LDR   a1,BOOT_SYS_Stack_End
   MOV   sp,a1                              ; Setup initial stack pointer

   IF __CHIP_VERSION_CHECK__
   LDR     a4,=INT_Version_Check
   MOV    lr, pc
   BX      a4
   ENDIF

;  /* Check if abnormal reset */   
   LDR   a1,ABN_RST_PTR
   BL    INT_SystemReset_Check   
   
   BL    SST_DTLB_Init
   
;  /* BL to INT_Config() to configure EMI wait state after system stack is set up */   

   IF :DEF: MT6238
   BL INT_InitInternalRegions      
   BL INT_Config   
;  /*
;   * NoteXXX: Store the return value of INT_Config (i.e.,random number seed) 
;   *          in r12 temporarily. Thus in the following program r12 should be
;   *          used before we store r12 back to rand_num_seed.
;   */
   MOV  r12,a1
   ELSE
   BL INT_Config   
;  /*
;   * NoteXXX: Store the return value of INT_Config (i.e.,random number seed) 
;   *          in r12 temporarily. Thus in the following program r12 should be
;   *          used before we store r12 back to rand_num_seed.
;   */
   MOV  r12,a1
   IF :DEF: _NOR_LPSDRAM_MCP_
;  /* BL to custom_InitDRAM() to configure DRAM and EMI*/
   BL    custom_InitDRAM
   ENDIF
   BL INT_InitInternalRegions         
   ENDIF

;  /* BL to custom_InitDRAM() to configure DRAM and EMI*/
   IF :DEF: MT6238
   BL    custom_InitDRAM
   ENDIF
   

;  /* Initialize regions */
   BL    INT_InitRegions                    ; in regioninit.s
   
   IF :DEF:__ROMSA_SUPPORT__                ; ROMSA
   BL    InitRegions2                       ; ROMSA
   BL    ROMSA_Init                         ; ROMSA
   ENDIF                                    ; ROMSA
   
;  /* after INT_InitRegions, we can store the random number seed to rand_num_seed */
   LDR   a2,RAND_NUM_SEED_PTR
   STR   r12,[a2]

   BL    custom_setAdvEMI
   
   BL    CacheInit
   
   MOV   a1,#1                              ; All vectors are assumed loaded   
   LDR   a2, Loaded_Flag
   STR   a1,[a2,#0]                         ; Initialize loaded flag

   IF KAL_ON_NUCLEUS

   LDR   a1,BOOT_SYS_Stack            
   LDR   a4,System_Limit                    ; Setup initial stack limit
   STR   a1,[a4, #0]                        ; Save stack limit   

   ENDIF

   LDR   a4, System_Stack
   STR   sp,[a4, #0]                        ; Save stack pointer
   
   LDR   a3,BOOT_IRQ_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#IRQ_MODE                    ; Set the IRQ mode bits
   MSR   CPSR_cxsf,a1                       ; Move to IRQ mode
   MOV   sp,a3                              ; Setup IRQ stack pointer

   LDR   a3,BOOT_FIQ_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#FIQ_MODE                    ; Set the FIQ mode bits
   MSR   CPSR_cxsf,a1                       ; Move to the FIQ mode
   MOV   sp,a3                              ; Setup FIQ stack pointer

   LDR   a3,BOOT_ABT_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#ABORT_MODE                  ; Set the Abort mode bits
   MSR   CPSR_cxsf,a1                       ; Move to the Abort mode
   MOV   sp,a3                              ; Setup Abort stack pointer
   
   LDR   a3,BOOT_UND_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#UND_MODE                    ; Set the Undefine mode bits
   MSR   CPSR_cxsf,a1                       ; Move to the Undefine mode
   MOV   sp,a3                              ; Setup Undefine stack pointer

   LDR   a3,BOOT_SYS_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#SYS_MODE                    ; Set the Undefine mode bits
   MSR   CPSR_cxsf,a1                       ; Move to the Undefine mode
   MOV   sp,a3                              ; Setup Undefine stack pointer

   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear mode bits
   ORR   a1,a1,#SUP_MODE                    ; Set the supervisor mode bits
   MSR   CPSR_cxsf,a1                       ; All interrupt stacks are setup,

   IF KAL_ON_NUCLEUS

   LDR   a4,HISR_Stack_Ptr
   LDR   a3,BOOT_TMD_Stack
   STR   a3,[a4, #0]                        ; Setup timer HISR stack pointer
   
   LDR   a2,BOOT_Timer_HISR_Stack_Size
   LDR   a4,HISR_Stack_Size
   STR   a2,[a4, #0]                        ; Setup timer HISR stack size
   MOV   a2,#TIMER_PRIORITY                 ; Pickup timer HISR priority (0-2)
   LDR   a4,HISR_Priority
   STR   a2,[a4, #0]                        ; Setup timer HISR priority

   ENDIF
   
   MOV   a1, #0

   IF KAL_ON_NUCLEUS

   [ THUMB
   LDR   a4,=INC_Initialize                 ; to high-level initialization
   BX    a4
   |
   B     INC_Initialize                     ; to high-level initialization
   ]

   ELSE

   [ THUMB
   LDR   a4,=_tx_initialize_kernel_enter    ; to high-level initialization
   BX    a4
   |
   B     _tx_initialize_kernel_enter        ; to high-level initialization
   ]

   ENDIF
;}

;
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*                                                                       */
;/*      INT_Setup_Vector                                                 */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This function sets up the specified vector with the new vector   */
;/*      value.  The previous vector value is returned to the caller.     */
;/*                                                                       */
;/*                                                                       */
;/* CALLED BY                                                             */
;/*                                                                       */
;/*      Application                                                      */
;/*      TCC_Register_LISR                   Register LISR for vector     */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/* INPUTS                                                                */
;/*                                                                       */
;/*      vector                              Vector number to setup       */
;/*      new                                 Pointer to new assembly      */
;/*                                            language ISR               */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*                                                                       */
;/*      old vector contents                                              */
;/*                                                                       */
;/*************************************************************************/
;VOID  *INT_Setup_Vector(INT vector, VOID *new)
;{
   EXPORT  INT_Setup_Vector
INT_Setup_Vector
;
;VOID    *old_vector;                        /* Old interrupt vector      */
;VOID   **vector_table;                      /* Pointer to vector table   */
;
;    /* Calculate the starting address of the actual vector table.  */
;    vector_table =  (VOID **) 0;
;
;    /* Pickup the old interrupt vector.  */
;    old_vector =  vector_table[vector];
;
;    /* Setup the new interrupt vector.  */
;    vector_table[vector] =  new;
;
;    /* Return the old interrupt vector.  */
;    return(old_vector);
;

     ADR    a3,INT_Table                    ; Get the address of our table
     LDR    a4,[a3,a1,LSL #2]               ; Make sure we are pointing to
                                            ; the right vector
     STR    a2,[a3,a1,LSL #2]               ; Store the new isr
     MOV    a1,a4                           ; Setup return parameter
     [ THUMB
     BX     lr                              ; Return to caller
     |
     MOV    pc,lr                           ; Return to caller
     ]
;}

;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*                                                                       */
;/*      INT_Vectors_Loaded                                               */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This function returns the flag that indicates whether or not     */
;/*      all the default vectors have been loaded.  If it is false,       */
;/*      each LISR register also loads the ISR shell into the actual      */
;/*      vector table.                                                    */
;/*                                                                       */
;/* CALLED BY                                                             */
;/*                                                                       */
;/*      TCC_Register_LISR                   Register LISR for vector     */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/* INPUTS                                                                */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/*************************************************************************/
;INT    INT_Vectors_Loaded(void)
;{
   EXPORT  INT_Vectors_Loaded
INT_Vectors_Loaded
;
;    /* Just return the loaded vectors flag.  */
;    return(INT_Loaded_Flag);
;
   LDR    a1, Loaded_Flag
   LDR    a1,[a1,#0]                        ; Load current value

   [ THUMB
   BX     lr                                ; Return to caller
   |
   MOV    pc,lr                             ; Return to caller
   ]
;}

;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*                                                                       */
;/*      INT_Retrieve_Shell                                               */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This function retrieves the pointer to the shell interrupt       */
;/*      service routine.  The shell interrupt service routine calls      */
;/*      the LISR dispatch routine.                                       */
;/*                                                                       */
;/* CALLED BY                                                             */
;/*                                                                       */
;/*      TCC_Register_LISR                   Register LISR for vector     */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/* INPUTS                                                                */
;/*                                                                       */
;/*      vector                              Vector number to setup       */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*                                                                       */
;/*      shell pointer                                                    */
;/*                                                                       */
;/*************************************************************************/
;VOID  *INT_Retrieve_Shell(INT vector)
;{
   EXPORT  INT_Retrieve_Shell
INT_Retrieve_Shell
;
;    /* Return the LISR Shell interrupt routine.  */
;    return(INT_Vectors[vector]);
;
    ADR    a2,INT_Table                     ; Get address of our table
    LDR    a1,[a2,a1,LSL #2]                ; Make sure we have correct isr

    [ THUMB
    BX     lr                               ; Return to caller
    |
    MOV    pc,lr                            ; Return to caller
    ]
;}

;/* single bank support */
   IF :LNOT:SINGLE_BANK_SUPPORT

FIQ_RETURN_PTR
   DCD     processing_fiqlr

INT_FIQ_Parse

    IF KAL_ON_NUCLEUS

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #F_BIT
    LDMIA   sp!, {a2}
    SUBNES  PC,lr,#4

    STMDB   sp!,{a1-a4}                     ; Save a1-a4 on temporary FIQ stack
    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)
    
    LDR     a1, FIQ_RETURN_PTR
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.    

    BL      TCT_Interrupt_Context_Save      ; Call context save routine
    BL      INT_FIQ_Lisr
    B       TCT_Interrupt_Context_Restore

    ELSE

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #F_BIT
    LDMIA   sp!, {a2}
    SUBNES  PC,lr,#4

    STMDB   sp!,{a1,a4}                     ; Save a1 and a4 on temporary FIQ stack

    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)
    LDR     a1, FIQ_RETURN_PTR
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.    

    LDMIA   sp!,{a1,a4}                     ; Restore a1 and a4

    BL      INT_FIQ_Lisr

int_fiq_busy_loop

    B       int_fiq_busy_loop

    ENDIF


Default_ISR
   SUBS     pc,lr,#4

;  
;/*************************************************************************/
;/* The following section contains the remaining interrupt handlers.      */
;/* Place you Interrupt Service routine at the appropriate label.         */
;/* For IRQ, you can use Nucleus PLUS call to NU_Register_LISR            */
;/* setup up an interrupt service routine.                                */
;/*************************************************************************/
SYSTEM_FATAL_ERROR
   DCD     stack_system_error

Undef_Instr_ISR
   MOV      a1,#UNDEF_EXCEPTION_TYPE        ; Set type UND_ISR   (1)
   MOV      a2,lr
   B        saveException

SWI_ISR
   MOV      a1,#SWI_EXCEPTION_TYPE          ; Set type SWI_ISR   (2)
   MOV      a2,lr
   B        saveException

Prefetch_Abort_ISR
   MOV      a1,#PREFETCH_EXCEPTION_TYPE     ; Set type ABORT_ISR (3)
   MOV      a2,lr
   B        saveException

Data_Abort_ISR
   MOV      a1,#DATA_EXCEPTION_TYPE         ; Set type DATA_ABORT (4)
   MOV      a2,lr
   
saveException  
   MRS     a3,CPSR                          ; Pickup current CPSR
   BIC     a3,a3,#MODE_MASK                 ; Clear the mode bits
   ORR     a3,a3,#SUP_MODE                  ; Prepare to switch to supervisor mode (SVC)
   MSR     CPSR_cxsf,a3                     ; Switch to supervisor mode (SVC)
   
   LDR     a4, SYSTEM_FATAL_ERROR
   BX      a4

   ENDIF ;/* single bank support */

;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      INT_ExceptionSwitchSP                                            */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Saving current stack pointer (SP) at the entry of system error,  */
;/*      including fatal error, assert and CPU exception                  */
;/*      (INT_Exception_SP); and switch SP to exception used stack.       */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      None                                                             */
;/*************************************************************************/
; VOID INT_ExceptionSwitchSP(VOID)
; {
INT_ExceptionSwitchSP

   LDR   r10, Exception_SP_PTR
   STR   SP, [r10]
   LDR   r10, BOOT_EX_Stack_End
   MOV   SP, r10                            ; Setup initial stack pointer
   [ THUMB
   BX    lr                                 ; Return to caller
   |
   MOV   pc,lr                              ; Return to caller
   ]
;}   

;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      INT_ExceptionResetSystemSP                                       */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      To reserve complete EX use stack for TST dump mechanism during   */
;/*      system error, EX use stack has to be reset before trapping to    */
;/*      tst_system_assertion_handler().                                  */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      None                                                             */
;/*************************************************************************/
; VOID INT_ExceptionResetSystemSP( VOID)
; {
INT_ExceptionResetSystemSP
   
   LDR   r10, BOOT_EX_Stack_End
   MOV   SP, r10                            ; Setup initial exception stack pointer   
   
   [ THUMB
   BX    lr                                 ; Return to caller
   |
   MOV   pc,lr                              ; Return to caller
   ]
;}   

;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      INT_GetCurrentSP                                                 */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Get the value of the current sp register.                        */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      current sp                                                       */
;/*************************************************************************/
; int INT_GetCurrentSP(VOID)
; {
INT_GetCurrentSP
   
   MOV   r0, sp                             ; get the current stack pointer

   [ THUMB
   BX    lr                                 ; Return to caller
   |
   MOV   pc,lr                              ; Return to caller
   ]
;}

;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      INT_SwitchStackAndBranch                                         */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Switch current stack pointer to new_stack and then run           */
;/*      func(argv).                                                      */
;/*                                                                       */
;/* CALLED BY                                                             */
;/*      INT_SwitchStackToRun                                             */
;/*                                                                       */
;/* CALLS                                                                 */
;/*      None                                                             */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      new_stack      the new stack pointer which want to switch to     */
;/*      func           the pointer of function which want to run         */
;/*      argc           the number of arguments of func                   */
;/*      argv           the list of arguments                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      The reture value of func                                         */
;/*************************************************************************/
; kal_uint32 INT_SwitchStackAndBranch(kal_uint32 new_stack, kal_func_ptr func, kal_uint32 argc, va_list argv)
; {
INT_SwitchStackAndBranch
   EXPORT   INT_SwitchStackAndBranch
   
   STMDB    SP!, {R4-R7, LR}

   MOV      R7, SP                          ; Backup original SP in R7
   LDR      R6, [R3]                        ; Load the poitner of argv
   MOV      R5, R0                          ; Backup new SP in R5
   SUBS     R2, R2, #4                      ; Check if need to copy stack?
   BLS      skip_copy_stack

   ADD      R6, R6, #16
   SUB      R5, R0, R2, LSL #2              ; Reserve new stack to store arg4~n

copy_stack
   LDRHI    R4, [R6], #4                    ; Copy arg4~n from argv to new stack
   STRHI    R4, [R5], #4
   CMP      R0, R5
   BHI      copy_stack

   SUB      R5, R0, R2, LSL #2              ; Change new stack pointer

skip_copy_stack
   MOV      R6, R1                          ; Backup function pointer
   LDR      R4, [R3]                        ; Backup the pointer of argv;

   LDR      R0, [R4]                        ; Setup arguments of procedure call
   LDR      R1, [R4, #4]
   LDR      R2, [R4, #8]
   LDR      R3, [R4, #12]

   MOV      SP, R5                          ; Switch to new stack
   ADR      lr, func_return
   BX       R6                              ; Procedure call
func_return
   MOV      SP, R7                          ; Switch back to old stack

   LDMIA    SP!, {R4-R7, PC}
;}

   IF SINGLE_BANK_SUPPORT
   CODE32
   AREA |SNORCODE|, CODE, READONLY

   IMPORT Flash_ReturnReady

FIQ_RETURN_PTR
   DCD     processing_fiqlr

INT_FIQ_Parse

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #F_BIT
    LDMIA   sp!, {a2}
    SUBNES  PC,lr,#4

    STMDB   sp!,{a1-a4}                     ; Save a1-a4 on temporary FIQ stack
    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)
    
    LDR     a1, FIQ_RETURN_PTR
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.

   IF SINGLE_BANK_SUPPORT
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               ; make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             ; r12 is for veneer use
   ENDIF

    BL      TCT_Interrupt_Context_Save      ; Call context save routine
    BL      INT_FIQ_Lisr
    B       TCT_Interrupt_Context_Restore


SYSTEM_FATAL_ERROR
   DCD     stack_system_error

Default_ISR
   SUBS     pc,lr,#4

;  
;/*************************************************************************/
;/* The following section contains the remaining interrupt handlers.      */
;/* Place you Interrupt Service routine at the appropriate label.         */
;/* For IRQ, you can use Nucleus PLUS call to NU_Register_LISR            */
;/* setup up an interrupt service routine.                                */
;/*************************************************************************/

Undef_Instr_ISR
   MOV      a1,#UNDEF_EXCEPTION_TYPE        ; Set type UND_ISR   (1)
   MOV      a2,lr
   B        saveException

SWI_ISR
   MOV      a1,#SWI_EXCEPTION_TYPE          ; Set type SWI_ISR   (2)
   MOV      a2,lr
   B        saveException

Prefetch_Abort_ISR
   MOV      a1,#PREFETCH_EXCEPTION_TYPE     ; Set type ABORT_ISR (3)
   MOV      a2,lr
   B        saveException

Data_Abort_ISR
   MOV      a1,#DATA_EXCEPTION_TYPE         ; Set type DATA_ABORT (4)
   MOV      a2,lr
   
saveException  
   MRS     a3,CPSR                          ; Pickup current CPSR
   BIC     a3,a3,#MODE_MASK                 ; Clear the mode bits
   ORR     a3,a3,#SUP_MODE                  ; Prepare to switch to supervisor mode (SVC)
   MSR     CPSR_cxsf,a3                     ; Switch to supervisor mode (SVC)
   
   IF SINGLE_BANK_SUPPORT
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               ; make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             ; r12 is for veneer use
   ENDIF

   LDR     a4, SYSTEM_FATAL_ERROR
   BX      a4

   ENDIF ;/* single bank support */

   CODE32
   AREA |INTERNCODE|, CODE, READONLY

;
;}
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*                                                                       */
;/*      INT_IRQ_Parse                                                    */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This routine is the board-specific section for                   */
;/*      interrupt handling                                               */
;/*                                                                       */
;/*************************************************************************/
INT_IRQ_Parse

    IF KAL_ON_NUCLEUS

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #I_BIT
    LDMIA   sp!, {a2}
    SUBNES  pc,lr,#4

    STMDB   sp!,{a1-a4}                     ; Save a1-a4 on temporary IRQ stack
    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)

    LDR     a1,=processing_irqlr
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.

  IF DCM_ENABLE
    STMDB   sp!,{a1-a4}
    STMDB   sp!,{r12}
    STMDB   sp!,{r14}
    BL   DCM_Recovery 
    LDMIA   sp!,{r14}
    LDMIA   sp!,{r12}
    LDMIA   sp!,{a1-a4}  
  ENDIF

   IF SINGLE_BANK_SUPPORT
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               ; make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             ; r12 is for veneer use
   ENDIF

    BL      TCT_Interrupt_Context_Save      ; Call context save routine
    BL      isrC_Main
    B       TCT_Interrupt_Context_Restore

    ELSE

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #I_BIT
    LDMIA   sp!, {a2}
    SUBNES  pc,lr,#4

    STMDB   sp!,{a1,a4}                     ; Save a1 and a4 on temporary IRQ stack

    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)
    LDR     a1,=processing_irqlr
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.

    LDMIA   sp!,{a1,a4}                     ; Restore a1 and a4

  IF DCM_ENABLE
    STMDB   sp!,{a1-a4}
    STMDB   sp!,{r12}
    STMDB   sp!,{r14}
    BL   DCM_Recovery 
    LDMIA   sp!,{r14}
    LDMIA   sp!,{r12}
    LDMIA   sp!,{a1-a4}  
  ENDIF

    B       _tx_thread_context_save
__tx_irq_processing_return
    BL      _tx_thread_irq_nesting_start
    BL      isrC_Main
    BL      _tx_thread_irq_nesting_end
    B       _tx_thread_context_restore
 
    ENDIF


;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      DisableIRQ                                                       */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Set I-bit and return the original values.                        */
;/*      NoteXXX: for system internal use only                            */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      original values of I-bit and F-bit                               */
;/*************************************************************************/
; INT DisableIRQ(VOID)
; {
DisableIRQ
   STMDB    SP!,{R1}
   MRS      R0,CPSR
   MOV      R1,R0

   ORR      R0,R0,#I_BIT   
   MSR      CPSR_c, R0
   MOV      R0,R1
   LDMIA    SP!,{R1}
   [ THUMB
    BX      lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
   ]
;}


;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      ReEnableIRQ                                                      */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Enable IRQ by clearing I bit.                                    */
;/*      NoteXXX: for system internal use only                            */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      None                                                             */
;/*************************************************************************/
; VOID ReEnableIRQ( VOID)
; {
ReEnableIRQ
   STMDB    SP!, {R0}
   MRS      R0, CPSR
   BIC      R0, R0, #I_BIT
   MSR      CPSR_c, R0
   LDMIA    SP!, {R0}
   [ THUMB
    BX      lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
   ]
;}


;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      LockIRQ                                                          */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Set I-bit, F-bit and return their original values.               */
;/*      NoteXXX: for system internal use only                            */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      original values of I-bit and F-bit                               */
;/*************************************************************************/
; INT LockIRQ(VOID)
; {
LockIRQ
   STMDB    SP!,{R1}
   MRS      R0,CPSR
   MOV      R1,R0

   ORR      R0,R0,#INT_BIT   
   MSR      CPSR_c, R0
   MOV      R0,R1
   LDMIA    SP!,{R1}
   [ THUMB
    BX      lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
   ]
;}


;
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      RestoreIRQ                                                       */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Restore I-bit and F-bit setting                                  */
;/*      NoteXXX: for system internal use only                            */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      None                                                             */
;/*************************************************************************/
; VOID RestoreIRQ(INT)
; {
RestoreIRQ
   STMDB    SP!,{R1,R2}
   MRS      R1,CPSR
   AND      R2,R0,#INT_BIT
   BIC      R1,R1,#INT_BIT
   ORR      R0,R1,R2
   MSR      CPSR_c,R0
   LDMIA    SP!,{R1,R2}
    [ THUMB
   BX       lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
    ]
;}


; /* CC: add for debugging */
get_ibit
   EXPORT get_ibit
   MRS      R0,CPSR
   [ THUMB
    BX      lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
   ]
;}

   END

