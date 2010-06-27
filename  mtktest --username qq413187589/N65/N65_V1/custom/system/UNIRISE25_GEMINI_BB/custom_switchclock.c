/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_switchclock.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements clock switching function of Dynamic Clock Management
 *
 * Author:
 * -------
 *   EMI auto generator V4.17
 *
 *   Memory Device database last modified on 2009/11/16
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include <kal_release.h>
#include <reg_base.h>
#include <init.h>

#ifdef REMAPPING
#define FLASH_BASE_ADDR 0x08000000
#define RAM_BASE_ADDR 0x00
#else
#define FLASH_BASE_ADDR 0x00
#define RAM_BASE_ADDR 0x08000000
#endif

#ifdef DCM_ENABLE

#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
static kal_uint32 saved_emi_a, saved_emi_b;
#pragma arm section rwdata , rodata , zidata

#pragma arm section code = "INTERNCODE"

/*************************************************************************
* FUNCTION
*  custom_DynamicClockSwitch
*
* DESCRIPTION
*  This function dedicates to switch the system clock and adjust the EMI
*  according to the working system clock.
*
* PARAMETERS
*  clock    -    clock to switch
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
int custom_DynamicClockSwitch(mcu_clock_enum clock)
{

   register kal_uint32 delay;

   if (clock == MCU_104MHZ) {

      /* restore EMI A */
      *(volatile kal_uint32 *)EMI_CONA = saved_emi_a;

      /* restore EMI B */
      *(volatile kal_uint32 *)EMI_CONB = saved_emi_b;

      /* switch clock to 104MHz */
      *MCUCLK_CON = 0x0703;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

      return 0;

   } else if (clock == MCU_52MHZ) {

      /* restore EMI A */
      *(volatile kal_uint32 *)EMI_CONA = saved_emi_a;

      /* restore EMI B */
      *(volatile kal_uint32 *)EMI_CONB = saved_emi_b;

      /* switch clock to 52MHz */
      *MCUCLK_CON = 0x0303;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

      return 0;

   } else if (clock == MCU_26MHZ) {

      /* save EMI A */
      saved_emi_a = *EMI_CONA;

      /* save EMI B */
      saved_emi_b = *EMI_CONB;

      /* switch clock to 26MHz */
      *MCUCLK_CON = 0x0101;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

#if defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) || defined(MT6217) || defined(MT6218B) || defined(MT6219) || defined(MT6226) || defined(MT6226M) || defined(MT6227)
      /* set EMI A */
      *EMI_CONA = 0x44004405;
      /* set EMI B */
      *EMI_CONB = 0x44004405;
#else /* MT6223 || MT6223P || MT6227D || MT6226D || MT6217 || MT6218B || MT6219 || MT6226 || MT6226M || MT6227 */
      /* set EMI A */
      *EMI_CONA = 0x20404405;
      /* set EMI B */
      *EMI_CONB = 0x20404405;    
#endif /* MT6223 || MT6223P || MT6227D || MT6226D || MT6217 || MT6218B || MT6219 || MT6226 || MT6226M || MT6227 */

      return 0;

   } else if (clock == MCU_13MHZ) {

      /* save EMI A */
      saved_emi_a = *EMI_CONA;

      /* save EMI B */
      saved_emi_b = *EMI_CONB;

      /* switch clock to 13MHz */
      *MCUCLK_CON = 0x0000;

      /* delay for a while */
      for (delay = 0; delay < 8; delay++) {
          /* NOP */
      }

#if defined(MT6223) || defined(MT6223P) || defined(MT6227D) || defined(MT6226D) || defined(MT6217) || defined(MT6218B) || defined(MT6219) || defined(MT6226) || defined(MT6226M) || defined(MT6227)
      /* set EMI A */
      *EMI_CONA = 0x44004203;
      /* set EMI B */
      *EMI_CONB = 0x44004203;      
#else /* MT6223 || MT6223P || MT6227D || MT6226D || MT6217 || MT6218B || MT6219 || MT6226 || MT6226M || MT6227 */
      /* set EMI A */
      *EMI_CONA = 0x20404203;
      /* set EMI B */
      *EMI_CONB = 0x20404203;   
#endif /* MT6223 || MT6223P || MT6227D || MT6226D || MT6217 || MT6218B || MT6219 || MT6226 || MT6226M || MT6227 */

      return 0;

   } else {

      /* unsupported MCU clock */

      return -1;
   }

 
}

#pragma arm section code

#endif  /* DCM_ENABLE */

