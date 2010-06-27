/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   intrCtrl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the initialization of intrCtrl.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_release.h"
#include "reg_base.h"
#include "intrCtrl.h"


/*******************************************************************************
 * Define global data
 *******************************************************************************/

/* install interrupt handler functions */
#ifdef MT6218

const kal_uint8  irqLine[] = {IRQ0_CODE, IRQ1_CODE, IRQ2_CODE, IRQ3_CODE, IRQ4_CODE, IRQ5_CODE,
                              IRQ6_CODE, IRQ7_CODE, IRQ8_CODE, IRQ9_CODE, IRQA_CODE, IRQB_CODE,
                              IRQC_CODE, IRQD_CODE, IRQE_CODE, IRQF_CODE, IRQ10_CODE,IRQ11_CODE };

#elif defined(MT6218B) || defined(MT6217) /* MT6218 */

#if defined(MT6218B_FN) || defined(MT6217)

const kal_uint8  irqLine[] = {IRQ0_CODE, IRQ1_CODE, IRQ2_CODE, IRQ3_CODE, IRQ4_CODE, IRQ5_CODE,
                              IRQ6_CODE, IRQ7_CODE, IRQ8_CODE, IRQ9_CODE, IRQA_CODE, IRQB_CODE,
                              IRQC_CODE, IRQD_CODE, IRQE_CODE, IRQF_CODE, IRQ10_CODE,IRQ11_CODE, 
                              IRQ12_CODE, IRQ13_CODE, IRQ14_CODE, IRQ15_CODE, IRQ16_CODE,
                              IRQ17_CODE, IRQ18_CODE, IRQ19_CODE, IRQ1A_CODE };

#else   /* MT6218B_FN || MT6217 */

const kal_uint8  irqLine[] = {IRQ0_CODE, IRQ1_CODE, IRQ2_CODE, IRQ3_CODE, IRQ4_CODE, IRQ5_CODE,
                              IRQ6_CODE, IRQ7_CODE, IRQ8_CODE, IRQ9_CODE, IRQA_CODE, IRQB_CODE,
                              IRQC_CODE, IRQD_CODE, IRQE_CODE, IRQF_CODE, IRQ10_CODE,IRQ11_CODE, 
                              IRQ12_CODE,IRQ13_CODE,IRQ14_CODE,IRQ15_CODE,IRQ16_CODE,IRQ17_CODE };

#endif   /* MT6218B_FN || MT6217 */

#elif defined(MT6219) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6225)  || defined(MT6223) || defined(MT6227D) || defined(MT6226D) || defined(MT6223P) /* MT6218 */

const kal_uint8 irqLine[] = { IRQ0_CODE, IRQ1_CODE, IRQ2_CODE, IRQ3_CODE,
                              IRQ4_CODE, IRQ5_CODE, IRQ6_CODE, IRQ7_CODE,
                              IRQ8_CODE, IRQ9_CODE, IRQA_CODE, IRQB_CODE,
                              IRQC_CODE, IRQD_CODE, IRQE_CODE, IRQF_CODE,
                              IRQ10_CODE, IRQ11_CODE, IRQ12_CODE, IRQ13_CODE,
                              IRQ14_CODE, IRQ15_CODE, IRQ16_CODE, IRQ17_CODE,
                              IRQ18_CODE, IRQ19_CODE, IRQ1A_CODE, IRQ1B_CODE,
                              IRQ1C_CODE, IRQ1D_CODE, IRQ1E_CODE, IRQ1F_CODE };

#elif defined(MT6228) || defined(MT6229) || defined(MT6230)  /* MT6218 */

const kal_uint8 irqLine[] = { IRQ0_CODE,  IRQ1_CODE,  IRQ2_CODE,  IRQ3_CODE,
                              IRQ4_CODE,  IRQ5_CODE,  IRQ6_CODE,  IRQ7_CODE,
                              IRQ8_CODE,  IRQ9_CODE,  IRQA_CODE,  IRQB_CODE,
                              IRQC_CODE,  IRQD_CODE,  IRQE_CODE,  IRQF_CODE,
                              IRQ10_CODE, IRQ11_CODE, IRQ12_CODE, IRQ13_CODE,
                              IRQ14_CODE, IRQ15_CODE, IRQ16_CODE, IRQ17_CODE,
                              IRQ18_CODE, IRQ19_CODE, IRQ1A_CODE, IRQ1B_CODE,
                              IRQ1C_CODE, IRQ1D_CODE, IRQ1E_CODE, IRQ1F_CODE,
                              IRQ20_CODE, IRQ21_CODE, IRQ22_CODE, IRQ23_CODE,
                              IRQ24_CODE, IRQ25_CODE, IRQ26_CODE, IRQ27_CODE

#if defined(MT6229) || defined(MT6230)
                              , IRQ28_CODE };
#else /* MT6229 || MT6230 */
                            };
#endif   /* MT6229 || MT6230 */
#elif defined(MT6238)	

const kal_uint8 irqLine[] = { 
					IRQ0_CODE,  IRQ1_CODE,  IRQ2_CODE,  IRQ3_CODE,
					IRQ4_CODE,  IRQ5_CODE,  IRQ6_CODE,  IRQ7_CODE,
					IRQ8_CODE,  IRQ9_CODE,  IRQA_CODE,  IRQB_CODE,
					IRQC_CODE,  IRQD_CODE,  IRQE_CODE,  IRQF_CODE,
					IRQ10_CODE, IRQ11_CODE, IRQ12_CODE, IRQ13_CODE,
					IRQ14_CODE, IRQ15_CODE, IRQ16_CODE, IRQ17_CODE,
					IRQ18_CODE, IRQ19_CODE, IRQ1A_CODE, IRQ1B_CODE,
					IRQ1C_CODE, IRQ1D_CODE, IRQ1E_CODE, IRQ1F_CODE,
					IRQ20_CODE, IRQ21_CODE, IRQ22_CODE, IRQ23_CODE,
					IRQ24_CODE, IRQ25_CODE, IRQ26_CODE, IRQ27_CODE, 
					IRQ28_CODE, IRQ29_CODE, IRQ2A_CODE, IRQ2B_CODE,
					IRQ2C_CODE, IRQ2D_CODE, IRQ2E_CODE, IRQ2F_CODE,
					IRQ30_CODE, IRQ31_CODE
					};
                                   
#else /* MT6218 */

const kal_uint8 irqLine[] = { IRQ0_CODE, IRQ1_CODE, IRQ2_CODE, IRQ3_CODE,
                              IRQ4_CODE, IRQ5_CODE, IRQ6_CODE, IRQ7_CODE,
                              IRQ8_CODE, IRQ9_CODE, IRQA_CODE, IRQB_CODE,
                              IRQC_CODE, IRQD_CODE, IRQE_CODE, IRQF_CODE };

#endif   /* MT6218 */

kal_uint8 IRQCode2Line[NUM_IRQ_SOURCES];


/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/

extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);


/*************************************************************************
* FUNCTION
*  IRQSel
*
* DESCRIPTION
*  Reserved for system service only!
*  IRQ selection.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQSel(void)
{
#ifdef MT6218

   *IRQ_SEL0 = IRQ0_SEL0 | IRQ1_SEL0 |  IRQ2_SEL0 |  IRQ3_SEL0 | IRQ4_SEL0  | IRQ5_SEL0;
   *IRQ_SEL1 = IRQ6_SEL1 | IRQ7_SEL1 |  IRQ8_SEL1 |  IRQ9_SEL1 | IRQA_SEL1  | IRQB_SEL1;
   *IRQ_SEL2 = IRQC_SEL2 | IRQD_SEL2 |  IRQE_SEL2 |  IRQF_SEL2 | IRQ10_SEL2 | IRQ11_SEL2;
   
#elif defined(MT6218B) || defined(MT6217)

   *IRQ_SEL0 = IRQ0_SEL0  | IRQ1_SEL0  |  IRQ2_SEL0  |  IRQ3_SEL0  | IRQ4_SEL0  | IRQ5_SEL0;
   *IRQ_SEL1 = IRQ6_SEL1  | IRQ7_SEL1  |  IRQ8_SEL1  |  IRQ9_SEL1  | IRQA_SEL1  | IRQB_SEL1;
   *IRQ_SEL2 = IRQC_SEL2  | IRQD_SEL2  |  IRQE_SEL2  |  IRQF_SEL2  | IRQ10_SEL2 | IRQ11_SEL2;
   *IRQ_SEL3 = IRQ12_SEL3 | IRQ13_SEL3 |  IRQ14_SEL3 |  IRQ15_SEL3 | IRQ16_SEL3 | IRQ17_SEL3;

#if defined(MT6218B_FN) || defined(MT6217)
   *IRQ_SEL4 = IRQ18_SEL4 | IRQ19_SEL4 | IRQ1A_SEL4;
#endif   /* MT6218B_FN */

	
#elif defined(MT6219) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6225) || defined(MT6223) || defined(MT6227D) || defined(MT6226D) || defined(MT6223P)

   *IRQ_SEL0 = IRQ0_SEL0  | IRQ1_SEL0  |  IRQ2_SEL0  |  IRQ3_SEL0  | IRQ4_SEL0  | IRQ5_SEL0;
   *IRQ_SEL1 = IRQ6_SEL1  | IRQ7_SEL1  |  IRQ8_SEL1  |  IRQ9_SEL1  | IRQA_SEL1  | IRQB_SEL1;
   *IRQ_SEL2 = IRQC_SEL2  | IRQD_SEL2  |  IRQE_SEL2  |  IRQF_SEL2  | IRQ10_SEL2 | IRQ11_SEL2;
   *IRQ_SEL3 = IRQ12_SEL3 | IRQ13_SEL3 |  IRQ14_SEL3 |  IRQ15_SEL3 | IRQ16_SEL3 | IRQ17_SEL3;
   *IRQ_SEL4 = IRQ18_SEL4 | IRQ19_SEL4 | IRQ1A_SEL4 | IRQ1B_SEL4 | IRQ1C_SEL4 | IRQ1D_SEL4;
   *IRQ_SEL5 = IRQ1E_SEL5 | IRQ1F_SEL5;

#elif ( defined(MT6228)   || defined(MT6229) || defined(MT6230) )

   *IRQ_SEL0 = IRQ0_SEL0  | IRQ1_SEL0  | IRQ2_SEL0  | IRQ3_SEL0  | IRQ4_SEL0;
   *IRQ_SEL1 = IRQ5_SEL1  | IRQ6_SEL1  | IRQ7_SEL1  | IRQ8_SEL1  | IRQ9_SEL1;
   *IRQ_SEL2 = IRQA_SEL2  | IRQB_SEL2  | IRQC_SEL2  | IRQD_SEL2  | IRQE_SEL2;
   *IRQ_SEL3 = IRQF_SEL3  | IRQ10_SEL3 | IRQ11_SEL3 | IRQ12_SEL3 | IRQ13_SEL3;
   *IRQ_SEL4 = IRQ14_SEL4 | IRQ15_SEL4 | IRQ16_SEL4 | IRQ17_SEL4 | IRQ18_SEL4;
   *IRQ_SEL5 = IRQ19_SEL5 | IRQ1A_SEL5 | IRQ1B_SEL5 | IRQ1C_SEL5 | IRQ1D_SEL5;
   *IRQ_SEL6 = IRQ1E_SEL6 | IRQ1F_SEL6 | IRQ20_SEL6 | IRQ21_SEL6 | IRQ22_SEL6;
   *IRQ_SEL7 = IRQ23_SEL7 | IRQ24_SEL7 | IRQ25_SEL7 | IRQ26_SEL7 | IRQ27_SEL7;   
   
#if defined(MT6229) || defined(MT6230)
   *IRQ_SEL8 = IRQ28_SEL8;
#endif   
#elif defined(MT6238)

   *IRQ_SEL0 = IRQ0_SEL0  | IRQ1_SEL0  | IRQ2_SEL0  | IRQ3_SEL0  | IRQ4_SEL0;
   *IRQ_SEL1 = IRQ5_SEL1  | IRQ6_SEL1  | IRQ7_SEL1  | IRQ8_SEL1  | IRQ9_SEL1;
   *IRQ_SEL2 = IRQA_SEL2  | IRQB_SEL2  | IRQC_SEL2  | IRQD_SEL2  | IRQE_SEL2;
   *IRQ_SEL3 = IRQF_SEL3  | IRQ10_SEL3 | IRQ11_SEL3 | IRQ12_SEL3 | IRQ13_SEL3;
   *IRQ_SEL4 = IRQ14_SEL4 | IRQ15_SEL4 | IRQ16_SEL4 | IRQ17_SEL4 | IRQ18_SEL4;
   *IRQ_SEL5 = IRQ19_SEL5 | IRQ1A_SEL5 | IRQ1B_SEL5 | IRQ1C_SEL5 | IRQ1D_SEL5;
   *IRQ_SEL6 = IRQ1E_SEL6 | IRQ1F_SEL6 | IRQ20_SEL6 | IRQ21_SEL6 | IRQ22_SEL6;
   *IRQ_SEL7 = IRQ23_SEL7 | IRQ24_SEL7 | IRQ25_SEL7 | IRQ26_SEL7 | IRQ27_SEL7;   
   *IRQ_SEL8 = IRQ28_SEL8 | IRQ29_SEL8 | IRQ2A_SEL8 | IRQ2B_SEL8 | IRQ2C_SEL8;   
   *IRQ_SEL9 = IRQ2D_SEL9 | IRQ2E_SEL9 | IRQ2F_SEL9 | IRQ30_SEL9 | IRQ31_SEL9;   

#else /* re-routing */
   
   *IRQ_SEL0 = IRQ0_SEL0 | IRQ1_SEL0 |  IRQ2_SEL0 |  IRQ3_SEL0;
   *IRQ_SEL1 = IRQ4_SEL1 | IRQ5_SEL1 |  IRQ6_SEL1 |  IRQ7_SEL1;
   *IRQ_SEL2 = IRQ8_SEL2 | IRQ9_SEL2 |  IRQA_SEL2 |  IRQB_SEL2;
   *IRQ_SEL3 = IRQC_SEL3 | IRQD_SEL3 |  IRQE_SEL3 |  IRQF_SEL3;

#endif   
}

/*************************************************************************
* FUNCTION
*  FIQSel
*
* DESCRIPTION
*  Reserved for system service only!
*  Selection of FIQ.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQSel(void)
{
   *FIQ_SEL = FIQ_CODE;
}

/*************************************************************************
* FUNCTION
*  IRQDirectMaskAll
*
* DESCRIPTION
*  Mask all of the interrupts with direct indexing.
*
* IMPORTANT NOTICE
*  Reserved for system service only!
*  used while system error
*  such as fatal error, assertion failure and CPU triggered excetpion.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQDirectMaskAll(void)
{
   kal_uint32 savedmask;

   /* Lockout all interrupts */
   savedmask = LockIRQ();

#if defined(MT6205) || defined(MT6205B) || defined(MT6208)

   *IRQ_MASK = 0xffff;

#elif defined(MT6228)   /* MT6205 || MT6205B || MT6208 */

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0xff;

#elif defined(MT6229) || defined(MT6230)    /* MT6205 || MT6205B || MT6208 */

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0x1ff;

#elif defined(MT6238)    /* MT6205 || MT6205B || MT6208 */

   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKH = 0x3ffff;

#else  /* MT6205 || MT6205B || MT6208 */

   *IRQ_MASK = 0xffffffff;
   
#endif   /* MT6205 || MT6205B || MT6208 */

   RestoreIRQ(savedmask);
}

/*************************************************************************
* FUNCTION
*  SYS_ClearInt
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear IRQ with plain format interrupt status
*  It is trapped while Interrupt is disabled!
*
* PARAMETERS
*  Plain format interrupt status
*
* RETURNS
*
*************************************************************************/
void SYS_ClearInt(kal_uint8 code)
{
#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))

   if (code <= 31)
      *IRQ_EOIL = (1 << code);
   else
      *IRQ_EOIH = (1 << (code - 32));
      
#else         

   *IRQ_EOI = (1 << code);
   
#endif 
}

/*************************************************************************
* FUNCTION
*  SYS_ClearInt2
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear IRQ with binary coded interrupt status
*  It is trapped while Interrupt is disabled!
*
* PARAMETERS
*  Binary coded interrupt status
*
* RETURNS
*
*************************************************************************/
void SYS_ClearInt2(kal_uint8 irq_idx)
{
   *IRQ_EOI2 = irq_idx;
}

/*************************************************************************
* FUNCTION
*  IRQClearAllInt
*
* DESCRIPTION
*  Clear all of the interrupts with direct indexing.
*
* IMPORTANT NOTICE
*  Reserved for system service only!
*  This is special API for system service only; used on system 
*  initialization stage!
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQClearAllInt(void)
{
#if defined(MT6205) || defined(MT6205B) || defined(MT6208)

   *IRQ_EOI = 0xffff;

#elif defined(MT6228)   /* MT6205 || MT6205B || MT6208 */

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIH = 0xff;

#elif defined(MT6229) || defined(MT6230)    /* MT6205 || MT6205B || MT6208 */

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIH = 0x1ff;

#elif defined(MT6238)    /* MT6205 || MT6205B || MT6208 */

   *IRQ_EOIL = 0xffffffff;
   *IRQ_EOIH = 0x3fff;

#else  /* MT6205 || MT6205B || MT6208 */

   *IRQ_EOI = 0xffffffff;
   
#endif   /* MT6205 || MT6205B || MT6208 */
}

/*************************************************************************
* FUNCTION
*  FIQMask
*
* DESCRIPTION
*  Reserved for system service only!
*  Mask FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQMask(void)
{
   *FIQ_CON |= 0x0001; /* different method from masking FIQ!! */
}

/*************************************************************************
* FUNCTION
*  FIQUnmask
*
* DESCRIPTION
*  Reserved for system service only!
*  Unmask FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQUnmask(void)
{
   *FIQ_CON &= 0xFFFE; /* different method from unmasking FIQ!! */
}

/*************************************************************************
* FUNCTION
*  FIQClearInt
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQClearInt(void)
{
   *FIQ_EOI = 0x0001;
}

/*************************************************************************
* FUNCTION
*  IRQClearInt
*
* DESCRIPTION
*  Clear IRQ with plain format interrupt status
*
* PARAMETERS
*  Plain format interrupt status
*
* RETURNS
*
*************************************************************************/
void IRQClearInt(kal_uint8 code)
{
   kal_uint8 line;
   kal_uint32 savedmask;
   
   line = IRQCode2Line[code];

   /* Lockout all interrupts */
   savedmask = LockIRQ();   

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))

   if (line <= 31)
      *IRQ_EOIL = (1 << line);
   else
      *IRQ_EOIH = (1 << (line - 32));
      
#else

   *IRQ_EOI = (1 << line);

#endif 

   RestoreIRQ(savedmask);
}

/*************************************************************************
* FUNCTION
*  IRQMask
*
* DESCRIPTION
*  Mask certain interrupt source.
*
* PARAMETERS
*  Interrupt source to be masked, it is indexed via IRQCode2Line.
*
* RETURNS
*
*************************************************************************/
void IRQMask(kal_uint8 code)
{
   kal_uint8 line;
   kal_uint32 savedMask;

   line = IRQCode2Line[code];

   /*
    * [Important]
    * IRQ mask will be valid around 2T ~ 3T after register is written. 
    * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
    * advanced; otherwise, IRQ may be triggered unexpectedly.
    */
   savedMask = LockIRQ();
   
#if ( defined(MT6205) || defined(MT6208) || defined(FPGA) )

   *IRQ_MASK |= (1 << line);   
   
#elif ( defined(MT6228)   || defined(MT6229) || defined(MT6230) || defined(MT6238))

   if (line <= 31)
      *IRQ_MASK_SETL = (1 << line);
   else
      *IRQ_MASK_SETH = (1 << (line - 32));
   
#else   /* defined(MT6205) || defined(MT6208) || defined(FPGA) */

   *IRQ_MASK_SET = (1 << line);
   
#endif   /* defined(MT6205) || defined(MT6208) || defined(FPGA) */

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQMaskAll
*
* DESCRIPTION
*  Mask all of the interrupts
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQMaskAll(void)
{
   kal_uint8 idx;

   for (idx=0;idx<NUM_IRQ_SOURCES;idx++) 
      IRQMask(idx);
}

/*************************************************************************
* FUNCTION
*  IRQUnmask
*
* DESCRIPTION
*  Unmask certain interrupt source.
*
* PARAMETERS
*  Interrupt source to be unmasked, it is indexed via IRQCode2Line.
*
* RETURNS
*
*************************************************************************/
void IRQUnmask(kal_uint8 code)
{
   kal_uint8 line;
   kal_uint32 savedMask;

   line = IRQCode2Line[code];
   
   savedMask = LockIRQ();
   
#if ( defined(MT6205) || defined(MT6208) || defined(FPGA) )

   *IRQ_MASK &= (~(1 << line));

#elif ( defined(MT6228)	|| defined(MT6229) || defined(MT6230) || defined(MT6238))

   if (line <= 31)
      *IRQ_MASK_CLRL = (1 << line);
   else
      *IRQ_MASK_CLRH = (1 << (line - 32));
	
#else   /* defined(MT6205) || defined(MT6208) || defined(FPGA) */

      *IRQ_MASK_CLR = (1 << line);
	
#endif   /* defined(MT6205) || defined(MT6208) || defined(FPGA) */

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  CTIRQ1_2_MaskAll
*
* DESCRIPTION
*  Mask all of the interrupts except CTIRQ1 and CTIRQ2.

* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  CTIRQ1_2_MaskAll().
*
* PARAMETERS
*
* RETURNS
*  Current interrupt mask value.
*
*************************************************************************/
void CTIRQ1_2_MaskAll(IRQ_MASK_VALUE_T *val)
{
     kal_uint32 savedMask;

   if (val == NULL)
      ASSERT(0);
      
   savedMask = LockIRQ();
      
#ifdef MT6205B

   val->irq_maskl = (kal_uint32)*IRQ_MASK;
   val->irq_maskh = 0;
   *IRQ_MASK = 0xfffc;

#elif defined(MT6219)   /* MT6205B */

   /* 
    * NoteXXX: We change the priority of CAMERA, CTIRQ1, and CTIRQ2 on MT6219.
    */

   val->irq_maskl = *IRQ_MASK;
   val->irq_maskh = 0;
   *IRQ_MASK = 0xffffffff;
   *IRQ_MASK &= ~(1 << IRQCode2Line[IRQ_CTIRQ1_CODE]);
   *IRQ_MASK &= ~(1 << IRQCode2Line[IRQ_CTIRQ2_CODE]);
   *IRQ_MASK &= ~(1 << IRQCode2Line[IRQ_CAMERA_CODE]);

#elif defined(MT6228)   /* MT6205B */

   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKL &= ~(1 << IRQCode2Line[IRQ_CTIRQ1_CODE]);
   *IRQ_MASKL &= ~(1 << IRQCode2Line[IRQ_CTIRQ2_CODE]);
   *IRQ_MASKH = 0xff;      

#elif defined(MT6229) || defined(MT6230)   /* MT6205B */

   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKL &= ~(1 << IRQCode2Line[IRQ_CTIRQ1_CODE]);
   *IRQ_MASKL &= ~(1 << IRQCode2Line[IRQ_CTIRQ2_CODE]);
   *IRQ_MASKH = 0x1ff;      

#elif defined(MT6238)   /* MT6205B */

   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = 0xffffffff;
   *IRQ_MASKL &= ~(1 << IRQCode2Line[IRQ_CTIRQ1_CODE]);
   *IRQ_MASKL &= ~(1 << IRQCode2Line[IRQ_CTIRQ2_CODE]);
   *IRQ_MASKH = 0x3ffff;      

#else /* MT6205B */

   val->irq_maskl = *IRQ_MASK;
   val->irq_maskh = 0;
   *IRQ_MASK = 0xffffffff;
   *IRQ_MASK &= ~(1 << IRQCode2Line[IRQ_CTIRQ1_CODE]);
   *IRQ_MASK &= ~(1 << IRQCode2Line[IRQ_CTIRQ2_CODE]);
   
#endif   /* MT6205B */

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  CTIRQ1_2_Restore
*
* DESCRIPTION
*  Restore interrupt mask saved by CTIRQ1_2_MaskAll().

* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  CTIRQ1_2_MaskAll().
*
* PARAMETERS
*  Interrupt mask to be restored
*
* RETURNS
*
*************************************************************************/
void CTIRQ1_2_Restore(IRQ_MASK_VALUE_T *val)
{
   kal_uint32 savedMask;

   savedMask = LockIRQ();
      
#ifdef MT6205B

   *IRQ_MASK = (kal_uint16)val->irq_maskl;
   
#elif ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))

   *IRQ_MASKH = val->irq_maskh;
   *IRQ_MASKL = val->irq_maskl;
      
#else

   *IRQ_MASK = val->irq_maskl;
   
#endif

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQSensitivity
*
* DESCRIPTION
*  Setting sensitivity of IRQ
*
* PARAMETERS
*  code: IRQ number to be set
*  edge: either edge active low or level active low
*
* RETURNS
*
*************************************************************************/
void IRQSensitivity(kal_uint8 code, kal_bool edge)
{
   kal_uint8 line;

   line = IRQCode2Line[code];

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))

   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line <= 31)
         *IRQ_SENSL &= (~(1 << line));
      else
         *IRQ_SENSH &= (~(1 << (line - 32)));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line <= 31)
         *IRQ_SENSL |= (1 << line);
      else
         *IRQ_SENSH |= (1 << (line - 32));
   }
         
#else
   
   if (edge != KAL_FALSE) 
   {   /* it is an edge sensitive interrupt */
      *IRQ_SENS &= (~(1 << line));
   } 
   else 
   {   /* level sensitive interrupt */
      *IRQ_SENS |= (1 << line);
   }
   
#endif 
}

/*************************************************************************
* FUNCTION
*  FIQSensitivity
*
* DESCRIPTION
*  Setting sensitivity of FIQ
*
* PARAMETERS
*  Either edge active low or level active low
*
* RETURNS
*
*************************************************************************/
void FIQSensitivity(kal_bool edge)
{
   /* it is an edge sensitive interrupt */
   if (edge != KAL_FALSE)
      *FIQ_CON &= 0xFFFD;
      
   /* level sensitive interrupt */
   else
      *FIQ_CON |= 0x0002;
}

/*************************************************************************
* FUNCTION
*  initINTR
*
* DESCRIPTION
*  Interrupt initialization
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void initINTR(void)
{
   kal_uint8 idx;

   /* determine the mapping between interrupt code and line */
   for (idx=0;idx<NUM_IRQ_SOURCES;idx++) 
      IRQCode2Line[irqLine[idx]] = idx;

   /* mask all interrupt events */
   IRQDirectMaskAll();

   /* clear all pending interrupts */
   IRQClearAllInt();

   /* assign IRQ Selection Registers */
   IRQSel();
}


