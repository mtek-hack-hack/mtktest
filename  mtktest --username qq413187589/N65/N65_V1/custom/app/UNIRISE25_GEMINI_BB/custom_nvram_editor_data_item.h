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
 * custom_nvram_editor_data_item.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for customers to config/customize their parameters to NVRAM Layer and
 *    Driver Layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CUSTOM_NVRAM_EDTIOR_DATA_ITEM_H
#define CUSTOM_NVRAM_EDTIOR_DATA_ITEM_H

#ifndef __MAUI_BASIC__
/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef GEN_FOR_PC
#include "nvram_user_defs.h"
#endif 
#include "common_nvram_editor_data_item.h"
/***************************************************************************** 
* Define
*****************************************************************************/
/* for MS_SECURITY */
#define NVRAM_EDITOR_NUM_OF_BYTE_KEY   8
#define NVRAM_EDITOR_NUM_OF_BYTE_NP    3
#define NVRAM_EDITOR_NUM_NP            3
#define NVRAM_EDITOR_NUM_OF_BYTE_NSP   5
#define NVRAM_EDITOR_NUM_NSP           3
#define NVRAM_EDITOR_NUM_GID           20
#define NVRAM_EDITOR_NUM_OF_BYTE_IMSI  9
#define NVRAM_EDITOR_NUM_PIN1          8
#define NVRAM_EDITOR_NUM_OF_BYTE_ICCID	10

/* Version numbers of data items */
#define NVRAM_EF_CACHE_BYTE_LID_VERNO        "010"
#define NVRAM_EF_CACHE_SHORT_LID_VERNO       "010"
#define NVRAM_EF_CACHE_DOUBLE_LID_VERNO         "010"
#define NVRAM_EF_MS_SECURITY_LID_VERNO       "001"
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    kal_uint8 reg_ps_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
    kal_uint8 security_indication;
    kal_uint8 auto_lock_item;
    kal_uint8 np_code[NVRAM_EDITOR_NUM_OF_BYTE_NP *NVRAM_EDITOR_NUM_NP];
    kal_uint8 np_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
    kal_uint8 nsp_code[NVRAM_EDITOR_NUM_OF_BYTE_NSP *NVRAM_EDITOR_NUM_NSP];
    kal_uint8 nsp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
    kal_uint8 np_of_sp[NVRAM_EDITOR_NUM_OF_BYTE_NP];
    kal_uint8 np_of_cp[NVRAM_EDITOR_NUM_OF_BYTE_NP];
    kal_uint8 gid1[NVRAM_EDITOR_NUM_GID];
    kal_uint8 gid2[NVRAM_EDITOR_NUM_GID];
    kal_uint8 sp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
    kal_uint8 cp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
    kal_uint8 imsi_code[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
    kal_uint8 imsi_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
    kal_uint8 phone_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
    kal_uint8 last_imsi[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
    kal_uint8 pin1[NVRAM_EDITOR_NUM_PIN1];
    kal_uint8 pin1_valid;
    kal_uint8 phone_lock_verified;   
    kal_uint8                iccid[NVRAM_EDITOR_NUM_OF_BYTE_ICCID];
} smu_security_info_struct;

#ifdef GEN_FOR_PC
typedef struct
{
    kal_uint8 CacheByte[NVRAM_CACHE_SIZE];
} nvram_cache_byte_struct;

typedef struct
{
    kal_uint16 CacheShort[NVRAM_CACHE_SIZE / 2];
} nvram_cache_short_struct;

typedef struct
{
    kal_uint64 Cachedouble[NVRAM_CACHE_SIZE / 8];
} nvram_cache_double_struct;

/***************************************************************************** 
* META Description
*****************************************************************************/

BEGIN_NVRAM_DATA
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_CACHE_BYTE_LID
  ***
  ***  Module:
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
    LID_BIT VER_LID(NVRAM_EF_CACHE_BYTE_LID)
     nvram_cache_byte_struct *NVRAM_CACHE_TOTAL
     {
         CacheByte:"One-byte parameter setting";
         CacheByte[14]
         {
           default_lang:8 "Default Language"
             {
             };
         };

         CacheByte[24]
         {
           time_zone:8 "Time Zone (Current City)"
             {
             };
         };

         CacheByte[25]
         {
           date_format:8 "Time Format"
             {
             };
         };

         CacheByte[26]
         {
           date_format:8 "Date Format"
             {
             };
         };
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_CACHE_SHORT_LID
  ***
  ***  Module:
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
LID_BIT VER_LID(NVRAM_EF_CACHE_SHORT_LID)
     nvram_cache_short_struct *NVRAM_CACHE_TOTAL
     {
         CacheShort:"Two-byte parameter setting";
         CacheShort[13]
         {
           Wallpaper:16 "Wallpaper"
             {
             };
         };
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_CACHE_DOUBLE_LID
  ***
  ***  Module:
  ***
  ***  Description:
  ***
  ***  Maintainer:
  ***
  ***********************************************************************/
LID_BIT VER_LID(NVRAM_EF_CACHE_DOUBLE_LID)
     nvram_cache_double_struct *NVRAM_CACHE_TOTAL
     {
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_MS_SECURITY_LID)
     smu_security_info_struct *NVRAM_EF_MS_SECURITY_TOTAL
     {
         reg_ps_key:"Registeration personalization key"
         {
         };

       security_indication:"Security indication"
         {
           pl:1 "Phone lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           nl:1 "Network lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           nsbl:1 "Network subset lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           spl:1 "Service provide lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           cl:1 "Corporate lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           il:1 "IMSI lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           al:1 "Auto lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           res:1 "Reserved"
             {
                 /*
                  * 0x0: "Not Supported";
                  * 0x1: "Supported";
                  */
             };

         };

       auto_lock_item:"Auto lock item"
         {
           nl:1 "Network lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           nsbl:1 "Network subset lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           spl:1 "Service provide lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           cl:1 "Corporate lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           il:1 "IMSI lock"
             {
               0x0:"Not Supported";
               0x1:"Supported";
             };

           res:3 "Reserved"
             {
                 /*
                  * 0x0: "Not Supported";
                  * 0x1: "Supported";
                  */
             };

         };

       np_code:"Network personalization code"
         {
         };
       np_key:"Network personalization key"
         {
         };
       nsp_code:"Network subset personalization code"
         {
         };
       nsp_key:"Network subset personalization key"
         {
         };
       np_of_sp:"NP of SP"
         {
         };
       np_of_cp:"NP of CP"
         {
         };
       gid1:"EF_GID 1"
         {
         };
       gid2:"EF_GID 2"
         {
         };
       sp_key:"Service provide personalization key"
         {
         };
       cp_key:"Corporate personalization key"
         {
         };
       imsi_code:"IMSI personalization code"
         {
         };
       imsi_key:"IMSI personalization key"
         {
         };
       phone_key:"Phone key"
         {
         };
       last_imsi:"Last IMSI code"
         {
         };

       pin1:"Last IMSI code"
         {
         };
       pin1_valid:"Last IMSI code"
         {
         };
       phone_lock_verified:"Phone Lock verified"
         {
         };
     };


END_NVRAM_DATA
#endif /* GEN_FOR_PC */

/* DO NOT MOVE OR REMOVE THIS HEADER */
#ifndef __OPTR_NONE__
#include "op_custom_nvram_editor_data_item.h"
#endif

#endif /* __MAUI_BASIC__ */ 
#endif /* CUSTOM_NVRAM_EDTIOR_DATA_ITEM_H */ 

