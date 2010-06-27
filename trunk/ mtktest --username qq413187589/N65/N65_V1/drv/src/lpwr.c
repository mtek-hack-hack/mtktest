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
 *    lpwr.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements low power functions
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_comm.h"
#include    "lpwr.h"

#define LPWR_INTERNAL_SRAM

extern LPWR_STRUCT LPWR_DEV[];
kal_uint16 max_lpwr_module;

#ifdef LPWR_INTERNAL_SRAM
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif
LPWR_INFO_STRUCT LPWR_INFO[LPWR_MAX_MODULE_GROUP];
#ifdef LPWR_INTERNAL_SRAM
#pragma arm section rwdata, rodata , zidata
#endif

const LPWR_GROUP_MAP_STRUCT   lpwr_group_mapping[] = {
   /*LPWR_DRV0_MODULE_GROUP*/
   {DEV_UART1,      LPWR_DRV0_MODULE_GROUP},
   {DEV_UART2,      LPWR_DRV0_MODULE_GROUP},
   {DEV_UART3,      LPWR_DRV0_MODULE_GROUP},
   {DEV_LCD,        LPWR_DRV0_MODULE_GROUP},
   {DEV_ALTER,      LPWR_DRV0_MODULE_GROUP},
   {DEV_GCU,        LPWR_DRV0_MODULE_GROUP},
   {DEV_DMA,        LPWR_DRV0_MODULE_GROUP},
   {DEV_SIM,        LPWR_DRV0_MODULE_GROUP},
   {DEV_ADC,        LPWR_DRV0_MODULE_GROUP},
   {DEV_B2SPI,      LPWR_DRV0_MODULE_GROUP},
   /*LPWR_DRV1_MODULE_GROUP*/
   {DEV_GPT,        LPWR_DRV1_MODULE_GROUP},
   {DEV_PWM1,       LPWR_DRV1_MODULE_GROUP},
   {DEV_PWM2,       LPWR_DRV1_MODULE_GROUP},
   {DEV_USB,        LPWR_DRV1_MODULE_GROUP},
   {DEV_MSDC,       LPWR_DRV1_MODULE_GROUP},
   {DEV_NFI,        LPWR_DRV1_MODULE_GROUP},
   {DEV_IRDA,       LPWR_DRV1_MODULE_GROUP},
   {DEV_TRC,        LPWR_DRV1_MODULE_GROUP},
   {DEV_PPP,        LPWR_DRV1_MODULE_GROUP},
   {DEV_MSDC2,        LPWR_DRV1_MODULE_GROUP},
   /*LPWR_MM_MODULE_GROUP*/
   {DEV_IPP,        LPWR_MM_MODULE_GROUP},
   {DEV_IMGDMA,     LPWR_MM_MODULE_GROUP},
   {DEV_GIF,        LPWR_MM_MODULE_GROUP},
   {DEV_PNG,        LPWR_MM_MODULE_GROUP},
   {DEV_RESZ,       LPWR_MM_MODULE_GROUP},
   {0xfe,           0xfe      }     //END
};

LPWR_MODULE_GROUP lpwr_get_group_id(DEVICE_ID_ENUM module_id)
{
   kal_uint32 index;
   for(index = 0;index< max_lpwr_module; index++)
   {
      if (lpwr_group_mapping[index].id == module_id)
         return lpwr_group_mapping[index].group;
   }   
   ASSERT(0);
   return 0;
}

void lpwr_default_callback(void *parameter)
{
   ASSERT(0);
}

void lpwr_mainstruct_init(LPWR_MAIN_STRUCT *main_info)
{
   main_info->module_id = 0xfe;
   main_info->lpwr_main_sm_handle = 0xfe;
   main_info->lpwr_sub_glb_hanlde = 0;
   main_info->lpwr_sub_sleepDisable = 0;
   main_info->pdn_enable_ctrl_callback = lpwr_default_callback;
   main_info->pdn_disable_ctrl_callback = lpwr_default_callback;
}

void lpwr_group_init(LPWR_INFO_STRUCT  *group_info, 
                     LPWR_MODULE_GROUP group_id, 
                     kal_uint8 group_handle)
{
   kal_uint32 index;
   group_info->group_id = group_id;
   group_info->lpwr_group_sm_handle = group_handle;
   group_info->lpwr_main_handle_cnt = 0;
   group_info->lpwr_main_sleepDisable = 0;

   ASSERT( (lpwr_group_mapping[max_lpwr_module-1].id == 0xfe) &&
           (lpwr_group_mapping[max_lpwr_module-1].group == 0xfe)
         );

   for(index=0;index<MAIN_MAX_MODULE;index++)
   {
      lpwr_mainstruct_init(&group_info->main_info[index]);
   }
}

void lpwr_init(void)
{
#ifndef __LOW_COST_PROJECT__
   kal_uint32 index;
   
   max_lpwr_module = sizeof(lpwr_group_mapping)/sizeof(LPWR_GROUP_MAP_STRUCT);
   
   for(index=0;index<LPWR_MAX_MODULE_GROUP;index++)
   {
#ifdef MTK_SLEEP_ENABLE
      lpwr_group_init(&LPWR_INFO[index], index, L1SM_GetHandle() );
#else /*MTK_SLEEP_ENABLE*/
      lpwr_group_init(&LPWR_INFO[index], index, 0 );
#endif   /*MTK_SLEEP_ENABLE*/
   }
#endif   /*__LOW_COST_PROJECT__*/
}

kal_uint8 lpwr_get_handle(kal_uint32 *handle, 
                          kal_uint8 max_handle_number)
{
   //Internal use
   kal_uint32  index;
   kal_uint8   result = 0xfe;
   kal_uint64  temp;

   for(index=0;index<max_handle_number;index++)
   {
      temp = (1<<index);
      if ( ( (*handle) & temp ) == 0 )
      {
         (*handle) |= temp;
         result = index;
         break;
      }
   }
   ASSERT(result != 0xfe);
   return result;
}

kal_uint8 lpwr_get_main_handle(LPWR_STRUCT *lpwr_handle,
                               void (*pdn_enable_ctrl_callback)(void *parameter),
                               void (*pdn_disable_ctrl_callback)(void *parameter) 
                               )
{
   kal_uint32  savedMask;
   kal_uint8   result;
   
#ifdef __LOW_COST_PROJECT__
   ASSERT(0);
#endif   /*__LOW_COST_PROJECT__*/
   
   savedMask = SaveAndSetIRQMask();
   ASSERT(LPWR_INFO[lpwr_handle->group_id].lpwr_main_handle_cnt<MAIN_MAX_MODULE);
   result = LPWR_INFO[lpwr_handle->group_id].lpwr_main_handle_cnt++;
   RestoreIRQMask(savedMask);
   
   LPWR_INFO[lpwr_handle->group_id].main_info[result].module_id = lpwr_handle->module_id;
   LPWR_INFO[lpwr_handle->group_id].main_info[result].lpwr_main_sm_handle = result;
   LPWR_INFO[lpwr_handle->group_id].main_info[result].lpwr_sub_glb_hanlde = 0x0;
   LPWR_INFO[lpwr_handle->group_id].main_info[result].pdn_enable_ctrl_callback = pdn_enable_ctrl_callback;
   LPWR_INFO[lpwr_handle->group_id].main_info[result].pdn_disable_ctrl_callback = pdn_disable_ctrl_callback;
   return result;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

kal_uint8 lpwr_get_sub_handle(LPWR_STRUCT *lpwr_handle)
{
   kal_uint32  savedMask;
   kal_uint8   result;

#ifdef __LOW_COST_PROJECT__
   ASSERT(0);
#endif   /*__LOW_COST_PROJECT__*/
   ASSERT(lpwr_handle->main_handle<MAIN_MAX_MODULE);
   ASSERT(lpwr_handle->group_id < LPWR_MAX_MODULE_GROUP);
   savedMask = SaveAndSetIRQMask();
   result = lpwr_get_handle(&LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].lpwr_sub_glb_hanlde, SUB_MAX_MODULE);
   RestoreIRQMask(savedMask);
   
   return result;
}

void lpwr_free_sub_handle(LPWR_STRUCT *lpwr_handle, kal_uint8 sub_handle)
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();
   LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].lpwr_sub_glb_hanlde &= ~(1<<sub_handle);
   RestoreIRQMask(savedMask);
}

void lpwr_main_disable(LPWR_STRUCT *lpwr_handle, 
                       void        *parameter)
{
   kal_uint32 savedMask;
   
   ASSERT(lpwr_handle->main_handle<MAIN_MAX_MODULE);
   ASSERT(lpwr_handle->group_id < LPWR_MAX_MODULE_GROUP);

   savedMask = SaveAndSetIRQMask();
   if (LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].pdn_disable_ctrl_callback != NULL)
      LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].pdn_disable_ctrl_callback(parameter);
      
#ifdef MTK_SLEEP_ENABLE
   if (LPWR_INFO[lpwr_handle->group_id].lpwr_main_sleepDisable == 0)
      L1SM_SleepDisable(LPWR_INFO[lpwr_handle->group_id].lpwr_group_sm_handle);
#endif   /*MTK_SLEEP_ENABLE*/
   
   LPWR_INFO[lpwr_handle->group_id].lpwr_main_sleepDisable |= (1 << lpwr_handle->main_handle);
   RestoreIRQMask(savedMask);
}

void lpwr_main_enable(LPWR_STRUCT *lpwr_handle, 
                      void        *parameter)
{
   kal_uint32 savedMask;
   ASSERT(lpwr_handle->main_handle<MAIN_MAX_MODULE);
   ASSERT(lpwr_handle->group_id < LPWR_MAX_MODULE_GROUP);
   savedMask = SaveAndSetIRQMask();

   if (LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].pdn_enable_ctrl_callback != NULL)
      LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].pdn_enable_ctrl_callback(parameter);

   LPWR_INFO[lpwr_handle->group_id].lpwr_main_sleepDisable &= ~(1 << lpwr_handle->main_handle);

#ifdef MTK_SLEEP_ENABLE
   if (LPWR_INFO[lpwr_handle->group_id].lpwr_main_sleepDisable == 0)
      L1SM_SleepEnable(LPWR_INFO[lpwr_handle->group_id].lpwr_group_sm_handle);
#endif   /*MTK_SLEEP_ENABLE*/

   RestoreIRQMask(savedMask);
}

void lpwr_sub_disable(LPWR_STRUCT   *lpwr_handle, 
                      kal_uint8     sub_handle, 
                      void          (*pdn_disable_ctrl_callback)(void *parameter),
                      void          *parameter)
{
   kal_uint32 savedMask;
   ASSERT(sub_handle<SUB_MAX_MODULE);
   ASSERT(lpwr_handle->main_handle<MAIN_MAX_MODULE);
   ASSERT(lpwr_handle->group_id < LPWR_MAX_MODULE_GROUP);
   savedMask = SaveAndSetIRQMask();
   
   if (pdn_disable_ctrl_callback != NULL)
      pdn_disable_ctrl_callback(parameter);

   if (LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].lpwr_sub_sleepDisable == 0)
   {
      lpwr_main_disable(lpwr_handle,parameter);
   }
   
   LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].lpwr_sub_sleepDisable |= (1 << sub_handle);
   RestoreIRQMask(savedMask);
}

void lpwr_sub_enable(LPWR_STRUCT *lpwr_handle, 
                     kal_uint8   sub_handle,
                     void        (*pdn_enable_ctrl_callback)(void *parameter),
                     void        *parameter)
{
   kal_uint32 savedMask;
   ASSERT(sub_handle<SUB_MAX_MODULE);
   ASSERT(lpwr_handle->main_handle<MAIN_MAX_MODULE);
   ASSERT(lpwr_handle->group_id < LPWR_MAX_MODULE_GROUP);
   savedMask = SaveAndSetIRQMask();
   
   if (pdn_enable_ctrl_callback != NULL)
      pdn_enable_ctrl_callback(parameter);
      
   LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].lpwr_sub_sleepDisable &= ~(1 << sub_handle);
   if (LPWR_INFO[lpwr_handle->group_id].main_info[lpwr_handle->main_handle].lpwr_sub_sleepDisable == 0)
   {
      lpwr_main_enable(lpwr_handle,parameter);
   }
   RestoreIRQMask(savedMask);
}

void lpwr_module_open(LPWR_STRUCT      *lpwr_handle, 
                      DEVICE_ID_ENUM   module_id,
                      void (*pdn_enable_ctrl_callback)(void *parameter),
                      void (*pdn_disable_ctrl_callback)(void *parameter)
                      )
{
   lpwr_handle->module_id = module_id;
   lpwr_handle->group_id = lpwr_get_group_id(module_id);
   lpwr_handle->main_handle = 
            lpwr_get_main_handle(lpwr_handle, 
                                 pdn_enable_ctrl_callback, 
                                 pdn_disable_ctrl_callback);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef LPWR_INTERNAL_SRAM
#pragma arm section code = "INTERNCODE"
#endif
void lpwr_main_fast_disable(LPWR_STRUCT *lpwr_handle)
{
#ifdef MTK_SLEEP_ENABLE
   if (LPWR_INFO[lpwr_handle->group_id].lpwr_main_sleepDisable == 0)
      L1SM_UnIRQSleepDisable(LPWR_INFO[lpwr_handle->group_id].lpwr_group_sm_handle);
#endif   /*MTK_SLEEP_ENABLE*/
   
   LPWR_INFO[lpwr_handle->group_id].lpwr_main_sleepDisable |= (1 << lpwr_handle->main_handle);
}

void lpwr_main_fast_enable(LPWR_STRUCT *lpwr_handle)
{
   LPWR_INFO[lpwr_handle->group_id].lpwr_main_sleepDisable &= ~(1 << lpwr_handle->main_handle);

#ifdef MTK_SLEEP_ENABLE
   if (LPWR_INFO[lpwr_handle->group_id].lpwr_main_sleepDisable == 0)
      L1SM_UnIRQSleepEnable(LPWR_INFO[lpwr_handle->group_id].lpwr_group_sm_handle);
#endif   /*MTK_SLEEP_ENABLE*/

}
#ifdef LPWR_INTERNAL_SRAM
#pragma arm section code
#endif


#ifdef __NEW_DRVPDN_FUNCTION__
   #ifdef LPWR_INTERNAL_SRAM
   #pragma arm section code = "INTERNCODE"
   #endif
void DRVPDN_Disable2(kal_uint32 addr,kal_uint16 code,kal_uint8 pdn_id)
{
   #if defined(MT6208) || defined(MT6205)
   DRV_Reg(addr) |= code;
   #else
   DRV_WriteReg((addr+0x20), code);
   #endif
   lpwr_main_fast_disable(&LPWR_DEV[pdn_id]);
}

void DRVPDN_Enable2(kal_uint32 addr,kal_uint16 code,kal_uint8 pdn_id)
{
   #if defined(MT6208) || defined(MT6205)
   DRV_Reg(addr) |= code;
   #else
   DRV_WriteReg((addr+0x10), code);
   #endif
   lpwr_main_fast_enable(&LPWR_DEV[pdn_id]);
}
   #ifdef LPWR_INTERNAL_SRAM
   #pragma arm section code
   #endif
#endif

#if !defined(__NEW_DRVPDN_FUNCTION__)

#ifdef MTK_SLEEP_ENABLE
extern kal_uint8 PDNhandle[];
#endif   /*MTK_SLEEP_ENABLE*/

/* No Low Power management*/
void DRVPDN_Disable2(kal_uint32 addr,kal_uint16 code,kal_uint8 handle)
{
#if defined(MT6205) || defined(MT6208)

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

#else   /* MT6205 || MT6208 */

#if defined(MT6219) || defined(MT6227) || defined(MT6226) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6226M) || defined(MT6225)
   if ((code == DRVPDN_CON1_UART1) || (code == DRVPDN_CON1_UART2) || (code == DRVPDN_CON1_UART3))
#else   /* MT6219 || MT6228 || NT6229 */
   if ((code == DRVPDN_CON1_UART1) || (code == DRVPDN_CON1_UART2))
#endif  /* MT6219 || MT6228 || MT6229 */
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

void DRVPDN_Enable2(kal_uint32 addr,kal_uint16 code,kal_uint8 handle)
{
#if ( (defined(MT6205)) || (defined(MT6208)) )
   DRV_Reg(addr) &= (~code);

   #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepDisable(PDNhandle[handle]);
   #endif /*MTK_SLEEP_ENABLE*/

#else

   DRV_Reg(addr+0x20) = code;

   #ifdef MTK_SLEEP_ENABLE
      L1SM_SleepDisable(PDNhandle[handle]);
   #endif /*MTK_SLEEP_ENABLE*/
   
#endif   /*MT6205B,MT6218*/
}
#endif /* __NEW_DRVPDN_FUNCTION__ */
