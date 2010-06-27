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
 *   custom_fota.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the FOTA (Firmware Over the Air) related setting.
 *
 * Author:
 * -------
 *   Yoda Chen (mtk01178)     system auto generator V0.30
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

/*******************************************
*   Customization Part      
********************************************/
#ifdef __MTK_TARGET__

#include "custom_MemoryDevice.h"
#include "flash_opt.h"
#include "kal_release.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "fota.h"
#include "custom_fota.h"

#ifdef __FOTA_ENABLE__

#ifdef _LOW_COST_SINGLE_BANK_FLASH_
FlashRegionInfo NORRegionInfo[] =
#else /* _LOW_COST_SINGLE_BANK_FLASH_ */
const FlashRegionInfo NORRegionInfo[] =
#endif
{
   CUSTOM_FLASH_INFO,
   EndRegionInfo /* Don't modify this line */
};

/* ---------------------------------------------------------------------------------
DESCRIPTION
   FOTA Customization Initialization API
	FOTA_Initialize() will call this function, this is for customization.
	User can register their own customized authentication or 
	decryption function in this function
PARAMETER
	NULL
RETURN
	0: means pass initialization step (ERROR_FOTA_SUCCESS)
	< 0: means fail
	   ERROR_FOTA_CUSTOMIZATION: customization error
--------------------------------------------------------------------------------- */
kal_int32 FOTA_CustomInitialize(void)
{
   kal_uint32 AddrLowBound=0, AddrUpperBound  = 0;
   kal_uint32 region = 0, StartBlkIndex = 0;

   FOTAData.SpareBaseAddr = FOTAData.FlashBaseAddr + FOTA_SPARE_BASE_ADDRESS;
   FOTAData.OriginalBaseAddr = FOTAData.FlashBaseAddr + FOTA_ORIGINAL_BASE_ADDRESS;
   FOTAData.TotalFOTALength = FOTA_SPARE_ALLOCATED_SIZE;
   FOTAData.NORRegionInfo = (FlashRegionInfo *)NORRegionInfo;
   FOTAData.SpareCurrAddr = FOTAData.SpareBaseAddr;
   FOTAData.NextBlockAddr = FOTAData.SpareBaseAddr;
   
   /*calculate the start block index*/
   AddrUpperBound = NORRegionInfo[0].RegionBlocks * NORRegionInfo[0].BlockSize;
   
   do{
      if (AddrUpperBound >= FOTA_SPARE_BASE_ADDRESS)
         break;
      else
      {
         StartBlkIndex += NORRegionInfo[region].RegionBlocks;
         region++;
         AddrLowBound = AddrUpperBound;
         AddrUpperBound = NORRegionInfo[region].RegionBlocks * NORRegionInfo[region].BlockSize;
      }
   }while(NORRegionInfo[region].RegionBlocks != 0);

   if(NORRegionInfo[region].RegionBlocks == 0 || (FOTA_SPARE_BASE_ADDRESS - AddrLowBound)%NORRegionInfo[region].BlockSize !=0)
   {
      return ERROR_FOTA_CUSTOMIZATION;
   }
   FOTAData.SpareStartBlkIndex = StartBlkIndex + (FOTA_SPARE_BASE_ADDRESS - AddrLowBound)/NORRegionInfo[region].BlockSize;

   /*register private authentication function or encryption function */
   FOTA_Reg_Auth((CALLBACK_Auth_FUNC)NULL);
   FOTA_Reg_Decrypt((CALLBACK_Decrypt_FUNC)NULL);
   
   return 0;
   
}
#endif /*__FOTA_ENABLE__*/
#endif
