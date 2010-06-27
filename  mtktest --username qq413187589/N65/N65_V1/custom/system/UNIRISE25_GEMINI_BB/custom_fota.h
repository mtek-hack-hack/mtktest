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
 *   custom_fota.h
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

#ifndef __CUSTOM_FOTA_H__
#define __CUSTOM_FOTA_H__

/*****************************************
 * Don't modify any code above this line *
 *****************************************/

/*******************************************************************************
   Follow the 5 steps below to configure flash memory for FOTA
   
   Step 1. Modify the sub file name of compressed image file, the file name format
           is [A-Z] and maximum length is 3

   Step 2. Modify the value of FOTA_ORIGINAL_BASE_ADDRESS, which is the MAUI start 
           address of FOTA project, this value need "erase unit aligned" and must be
           greater than firmware udpate engine image size
           
   Step 3. Modify the value of FOTA_SPARE_BASE_ADDRESS, which is spare image pool start
           address
           
   Step 4. Modify the value of FOTA_SPARE_ALLOCATED_SIZE, which is the size of spare image
           pool reserved for downloading compressed image
                          
   Step 5. Fill the flash erase unit information table, each element records the memory 
           space that contains continuous erase uints of equal size. Each element
           in the table is the format as below:
           {S_EU, N_EU}   
               S_EU: the size of erase unit 
               N_EU: the number of sectors
               
           EX1: {0x40000, 128}
           EX2: {0x2000,8},{0x10000,31}
      
        
   Note : Code region and spare image pool region can not share the same bank (partition)
*******************************************************************************/

/***********
 * Step 1. *
 ***********/
#define FMGR_TYPE_FOTA_FULL_EXT_NAME "xxx"   /* [A-Z] Max len: 3 */

/***********
 * Step 2. *
 ***********/
#define FOTA_ORIGINAL_BASE_ADDRESS x

/***********
 * Step 3. *
 ***********/
#define FOTA_SPARE_BASE_ADDRESS x

/***********
 * Step 4. *
 ***********/
#define FOTA_SPARE_ALLOCATED_SIZE x

/***********
 * Step 5. *
 ***********/
#define CUSTOM_FLASH_INFO {x, x}

/*****************************************

 * Don't modify any code below this line *
 *****************************************/
#if defined(__MTK_TARGET__)
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
extern FlashRegionInfo NORRegionInfo[];
#else
extern const FlashRegionInfo NORRegionInfo[];
#endif
#endif

extern kal_int32 FOTA_CustomInitialize(void);

#endif /*__CUSTOM_FOTA_H__*/
