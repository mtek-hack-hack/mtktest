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
 *	visualhisr.c
 *
 * Project:
 * --------
 *		MT6218B and MT6219 later chips
 *
 * Description:
 * ------------
 *   This file is intends for multimedia HISR management.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_comm.h"

#if ( (defined(MULTIMEDIA_INIT_MT6217_SERIES)) || (defined(MULTIMEDIA_INIT_MT6219_SERIES))  )
//#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )
/*(MT6217)||(MT6218B)||(MT6219)||(MT6226)||(MT6227)||(MT6226M)||(MT6228)||(MT6229)*/
#include "visualhisr.h"

#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
/* under construction !*/
#endif

kal_hisrid visual_hisr;
kal_uint32 visual_hisr_status;

void VISUAL_ERROR_HISR(void);
VISUAL_HISR_STRUCT VISUAL_HISR_TABLE[MAX_VISUAL_DEVICE];
VISUAL_HISR_ID    VISUAL_CURRENT_HISR;

VISUAL_HISR_DBG_STRUCT	VISUAL_HISR_DBG_INFO_DATA;

void visual_hisr_dbg_trace(VISUAL_HISR_ID index, kal_uint32 time)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();

    VISUAL_HISR_DBG_INFO_DATA.dbg_data[VISUAL_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_VISUAL_HISR_DBG_INFO_SIZE - 1)].tag = index;
    VISUAL_HISR_DBG_INFO_DATA.dbg_data[VISUAL_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_VISUAL_HISR_DBG_INFO_SIZE - 1)].time = time;
    VISUAL_HISR_DBG_INFO_DATA.dbg_data_idx++;

    RestoreIRQMask(savedMask);
}

void VISUAL_ERROR_HISR(void)
{
   ASSERT(0);
}

void VISUAL_Register_HISR(kal_uint8 visula_hisr_id, VOID_FUNCTION hisr_func)
{
   VISUAL_HISR_TABLE[visula_hisr_id].hisr_func = hisr_func;
}

void VISUAL_HISR(void)
{
   kal_uint16 index;
   kal_uint32 savedMask;
#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
#endif
   
   if (visual_hisr_status != 0)
   {
      for(index = 0;index<MAX_VISUAL_DEVICE;index++)
      {
         if (visual_hisr_status & (1 << index))
         {
            savedMask = SaveAndSetIRQMask();
#if defined(_MAUI_SOFTWARE_LA_)
/* under construction !*/
/* under construction !*/
#endif
            VISUAL_CURRENT_HISR = index;
#if ( (defined(MULTIMEDIA_INIT_MT6217_SERIES)) || (defined(MULTIMEDIA_INIT_MT6219_SERIES))  )
            visual_hisr_dbg_trace(index, drv_get_current_time());
#else
            #error "Compile option error!!"
#endif	/*(MULTIMEDIA_INIT_MT6217_SERIES, MULTIMEDIA_INIT_MT6219_SERIES)*/
            ASSERT(VISUAL_HISR_TABLE[index].hisr_count!=0);
            VISUAL_HISR_TABLE[index].hisr_count--;
            if (VISUAL_HISR_TABLE[index].hisr_count == 0)
               visual_hisr_status &= ~((1 << index));
            RestoreIRQMask(savedMask);
            VISUAL_HISR_TABLE[index].hisr_func();
            VISUAL_CURRENT_HISR = VISUAL_UNKNOWN_HISR_ID;
         }
      }
   }
}

void visual_hisr_init(void)
{
   kal_uint32 index;
   for(index=0;index<MAX_VISUAL_DEVICE;index++)
   {
      VISUAL_HISR_TABLE[index].hisr_func = VISUAL_ERROR_HISR;
      VISUAL_HISR_TABLE[index].hisr_count = 0;
   }
   
   if (visual_hisr == NULL)
      visual_hisr = kal_create_hisr("VISUHISR",1,1024,VISUAL_HISR,NULL);
}

#endif /*MULTIMEDIA_INIT_MT6217_SERIES, MULTIMEDIA_INIT_MT6219_SERIES*/

