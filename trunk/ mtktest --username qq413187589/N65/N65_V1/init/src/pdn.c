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
 *   pdn.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the power down management
 *
 * Author:
 * -------
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
 * Include files
 *******************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "lpwr.h"

extern void RestoreIRQMask(kal_uint32 irq);
extern kal_uint32 SaveAndSetIRQMask(void);

#ifdef __NEW_DRVPDN_FUNCTION__

LPWR_STRUCT LPWR_DEV[PDN_MAX_DEV];
/*This mapping must be correct*/
const DEVICE_ID_ENUM PDNID_2_DEVI[PDN_MAX_DEV+1] = 
{
   DEV_UART1,
   DEV_UART2,
   DEV_ALTER,
   DEV_GCU,
   DEV_DMA,
   DEV_SIM,
   DEV_ADC,
   DEV_GPT,
   DEV_PWM1,
   DEV_PWM2,
   DEV_USB,
   DEV_UART3,
   DEV_MSDC,
   DEV_NFI,
   DEV_B2SPI,
   DEV_IPP,
   DEV_IMGDMA,
   DEV_GIF,
   DEV_RESZ,
   DEV_IRDA,
   DEV_TRC,
   DEV_PPP,
   DEV_PNG,
   DEV_MSDC2,
   0xff                                   
};                                        
                                          
void DRV_PDN_EN(void *parameter)          
{
   PDN_INPUT *pdn_data = (PDN_INPUT *)parameter;
#if defined(MT6208) || defined(MT6205)
   DRV_Reg(pdn_data->addr) |= pdn_data->code;
#else
   DRV_WriteReg((pdn_data->addr+0x10), pdn_data->code);
#endif
   
}

void DRV_PDN_DIS(void *parameter)
{
   PDN_INPUT *pdn_data = (PDN_INPUT *)parameter;
#if defined(MT6208) || defined(MT6205)
   DRV_Reg(pdn_data->addr) |= pdn_data->code;
#else
   DRV_WriteReg((pdn_data->addr+0x20), pdn_data->code);
#endif
}

void DRVPDN_ini(void)
{
   kal_uint8 index;/*obtain all device handle*/
   for (index =0;index<PDN_MAX_DEV;index++)
   {
      ASSERT(PDNID_2_DEVI[index] != 0xff);
#if defined(MT6208) || defined(MT6205B) || defined(MT6218B) || defined(MT6217)
      if ((index == DRVPDN_CON1_UART1) || (index == DRVPDN_CON1_UART2) )
#else
      if ((index == DRVPDN_CON1_UART1) || (index == DRVPDN_CON1_UART2) || (index == DRVPDN_CON1_UART3))
#endif  /* MT6208, MT6205B, MT6218B, MT6217 */
      {
         lpwr_module_open(&LPWR_DEV[index], PDNID_2_DEVI[index], NULL, NULL);
      }
      else
      {
         lpwr_module_open(&LPWR_DEV[index], PDNID_2_DEVI[index], DRV_PDN_EN, DRV_PDN_DIS);
      }
   }
}
/*************************************************************************
* FUNCTION
*  DRVPDN_Enable
*
* DESCRIPTION
*
* CALLS
*
* PARAMETERS
*  MTK_SLEEP_ENABLE is to enable sleep mode
*  DRV_SLEEPONLY is only to enable drver sleep mode
*
* RETURNS
*
* GLOBALS AFFECTED
*
* HISTORY
*         NAME            DATE                    REMARKS
*        Jessen Hu      04-03-2002      Create initial version 1.0
*        Rex Luo        04-03-2002      Add comements and function description
*
*************************************************************************/
void DRVPDN_Enable(kal_uint32 addr,kal_uint16 code,kal_uint8 pdn_id)
{
   PDN_INPUT pdn_data;
   pdn_data.addr = addr;
   pdn_data.code = code;
   lpwr_main_enable(&LPWR_DEV[pdn_id],&pdn_data);
}

/*************************************************************************
* FUNCTION
*  DRVPDN_Disable
*
* DESCRIPTION
*
* CALLS
*
* PARAMETERS
*  MTK_SLEEP_ENABLE is to enable sleep mode
*  DRV_SLEEPONLY is only to enable drver sleep mode
*
* RETURNS
*
* GLOBALS AFFECTED
*
* HISTORY
*         NAME            DATE                    REMARKS
*        Jessen Hu      04-03-2002      Create initial version 1.0
*        Rex Luo        04-03-2002      Add comements and function description
*
*************************************************************************/
void DRVPDN_Disable(kal_uint32 addr,kal_uint16 code,kal_uint8 pdn_id)
{
   PDN_INPUT pdn_data;
   pdn_data.addr = addr;
   pdn_data.code = code;
   lpwr_main_disable(&LPWR_DEV[pdn_id],&pdn_data);
}

#else /*!__NEW_DRVPDN_FUNCTION__*/

#ifdef MTK_SLEEP_ENABLE
kal_uint8 PDNhandle[PDN_MAX_DEV];
#endif   /*MTK_SLEEP_ENABLE*/

void DRVPDN_ini(void)
{
#ifdef MTK_SLEEP_ENABLE
   kal_uint8 index;/*obtain all device handle*/
   //ASSERT(PDN_MAX_DEV <= 12);
   for (index =0;index<PDN_MAX_DEV;index++)
   {
      PDNhandle[index] = L1SM_GetHandle();
   }
#endif /*MTK_SLEEP_ENABLE*/
}
/*************************************************************************
* FUNCTION
*  PDN_iniEnable
*
* DESCRIPTION
*
* CALLS
*
* PARAMETERS
*  MTK_SLEEP_ENABLE is to enable sleep mode
*  DRV_SLEEPONLY is only to enable drver sleep mode
*
* RETURNS
*
* GLOBALS AFFECTED
*
* HISTORY
*         NAME            DATE                    REMARKS
*        Jessen Hu      04-03-2002      Create initial version 1.0
*        Rex Luo        04-03-2002      Add comements and function description
*
*************************************************************************/
void DRVPDN_Enable(kal_uint32 addr,kal_uint16 code,kal_uint8 handle)
{
#if defined(MT6205) || defined(MT6208)

   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();

   if ((code == DRVPDN_CON1_UART1) ||
       (code == DRVPDN_CON1_UART2)
       )
   {
      ;
   }
   else
      DRV_Reg(addr) |= code;

   #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepEnable(PDNhandle[handle]);
   #endif /*MTK_SLEEP_ENABLE*/

   RestoreIRQMask(savedMask);

#else   /* MT6205 || MT6208 */

#if defined(MT6208) || defined(MT6205B) || defined(MT6218B) || defined(MT6217)
   if ((code == DRVPDN_CON1_UART1) || (code == DRVPDN_CON1_UART2))
#else   /* MT6208, MT6205B, MT6218B, MT6217 */
   if ((code == DRVPDN_CON1_UART1) || (code == DRVPDN_CON1_UART2) || (code == DRVPDN_CON1_UART3))
#endif  /* MT6208, MT6205B, MT6218B, MT6217 */
   {
      ;
   }
   else
      DRV_Reg(addr+0x10) = code;

   #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepEnable(PDNhandle[handle]);
   #endif /*MTK_SLEEP_ENABLE*/
#endif   /*MT6205B,MT6218*/
}

/*************************************************************************
* FUNCTION
*  PDN_iniEnable
*
* DESCRIPTION
*
* CALLS
*
* PARAMETERS
*  MTK_SLEEP_ENABLE is to enable sleep mode
*  DRV_SLEEPONLY is only to enable drver sleep mode
*
* RETURNS
*
* GLOBALS AFFECTED
*
* HISTORY
*         NAME            DATE                    REMARKS
*        Jessen Hu      04-03-2002      Create initial version 1.0
*        Rex Luo        04-03-2002      Add comements and function description
*
*************************************************************************/
void DRVPDN_Disable(kal_uint32 addr,kal_uint16 code,kal_uint8 handle)
{
#if ( (defined(MT6205)) || (defined(MT6208)) )
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   DRV_Reg(addr) &= (~code);

   #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepDisable(PDNhandle[handle]);
   #endif /*MTK_SLEEP_ENABLE*/
   RestoreIRQMask(savedMask);

#else

   DRV_Reg(addr+0x20) = code;

   #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepDisable(PDNhandle[handle]);
   #endif /*MTK_SLEEP_ENABLE*/
   
#endif   /*MT6205B,MT6218*/
}

#endif   /*__NEW_DRVPDN_FUNCTION__*/

