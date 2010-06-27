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

/*******************************************************************************
 * Filename:
 * ---------
 *	drv_hisr.c
 *
 * Project:
 * --------
 *		ALL
 *
 * Description:
 * ------------
 *   This file is intends for driver HISR management.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_hisr.h"

#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
/* under construction !*/
#endif

kal_hisrid drv_hisr;
kal_uint64 drv_hisr_status;

void DRV_ERROR_HISR(void);
DRV_HISR_STRUCT DRV_HISR_TABLE[MAX_DRV_HISR_DEVICE];
DRV_HISR_ID     DRV_CURRENT_HISR;

DRV_HISR_DBG_STRUCT	DRV_HISR_DBG_INFO_DATA;

void drv_hisr_dbg_trace(DRV_HISR_ID index, kal_uint32 time)
{
#if !defined(__LOW_COST_PROJECT__) && defined(__PS_SERVICE__)
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();

    DRV_HISR_DBG_INFO_DATA.dbg_data[DRV_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_HISR_DBG_INFO_SIZE - 1)].tag = index;
    DRV_HISR_DBG_INFO_DATA.dbg_data[DRV_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_HISR_DBG_INFO_SIZE - 1)].time = time;
    DRV_HISR_DBG_INFO_DATA.dbg_data_idx++;

    RestoreIRQMask(savedMask);
#endif   /*__LOW_COST_PROJECT__*/
}

void DRV_ERROR_HISR(void)
{
   ASSERT(0);
}

void DRV_Register_HISR(kal_uint8 hisr_id, VOID_FUNCTION hisr_func)
{
   DRV_HISR_TABLE[hisr_id].hisr_func = hisr_func;
}

void DRV_HISR(void)
{
   kal_uint16 index;
   kal_uint32 savedMask;
#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
#endif

   if (drv_hisr_status != 0)
   {
      for(index = 0;index<MAX_DRV_HISR_DEVICE;index++)
      {
         if (drv_hisr_status & (1 << index))
         {
            savedMask = SaveAndSetIRQMask();
#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
/* under construction !*/
#endif
            DRV_CURRENT_HISR = index;
#if ( defined(MT6218B) || defined(MT6205B) )
				drv_hisr_dbg_trace(index, 0xffff);
#else	/*! (MT6218B, MT6205B)*/
            drv_hisr_dbg_trace(index, drv_get_current_time());
#endif	/*(MT6218B, MT6205B)*/
            ASSERT(DRV_HISR_TABLE[index].hisr_count!=0);
            DRV_HISR_TABLE[index].hisr_count--;
            if (DRV_HISR_TABLE[index].hisr_count == 0)
               drv_hisr_status &= ~((1 << index));
            RestoreIRQMask(savedMask);
            DRV_HISR_TABLE[index].hisr_func();
            DRV_CURRENT_HISR = DRV_UNKNOWN_HISR_ID;
         }
      }
   }
}

void drv_hisr_init(void)
{
   kal_uint32 index;
   ASSERT(MAX_DRV_HISR_DEVICE <= 32);
   for(index=0;index<MAX_DRV_HISR_DEVICE;index++)
   {
      DRV_HISR_TABLE[index].hisr_func = DRV_ERROR_HISR;
      DRV_HISR_TABLE[index].hisr_count = 0;
   }
   
   if (drv_hisr == NULL)
      drv_hisr = kal_create_hisr("DRVHISR",1,1024,DRV_HISR,NULL);
}
