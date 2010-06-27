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
 * nvram_user_defs.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for customers to config/customize their parameters to NVRAM Layer and
 *   Driver Layer.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef NVRAM_USER_DEFS_H
#define NVRAM_USER_DEFS_H

#ifndef __MAUI_BASIC__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "nvram_common_defs.h"

#define NVRAM_LID_CUST_BEGIN  NVRAM_EF_LAST_LID_COMMAPP

    typedef enum
    {
        NVRAM_EF_CACHE_BYTE_LID = NVRAM_LID_CUST_BEGIN,
        NVRAM_EF_CACHE_SHORT_LID,
        NVRAM_EF_CACHE_DOUBLE_LID,

        /* Don't remove this line: insert LID definition above */

        NVRAM_EF_LAST_LID_CUST
    } nvram_lid_cust_enum;

 /************************************
 * Custom data item Define Start
 ************************************/

/* MMI cache size is defined in custom_mmi_default_value.h */


#ifdef __MMI_FM_RADIO__
/*
 * FM Radio settings
 */
#define NVRAM_EF_FM_RADIO_CHANNEL   9 /* Better less than 30 channels, or it may exceed the maximum NVRAM record size */
#define NVRAM_EF_FM_RADIO_TOTAL     1
#define NVRAM_EF_FM_RADIO_SIZE      (NVRAM_EF_FM_RADIO_CHANNEL * 44) /* Same as "sizeof(mmi_fmrdo_channel_list_struct) */
#endif /* __MMI_FM_RADIO__ */ 


    /* Don't remove this line: insert size and total definition above */


    /* 
     * Max folders to clean by reset to factory default
     * If this value is chanaged, MUST remake nvram custom 
     */
#define NVRAM_MAX_CLEAN_FOLDERS 5
    extern const custpack_nvram_header custpack_nvram_ptr;

/* DO NOT MOVE OR REMOVE THIS HEADER */
#ifndef __OPTR_NONE__
#include "op_nvram_user_defs.h"
#endif

#ifdef __cplusplus
}
#endif
 
#endif /* __MAUI_BASIC__ */ 
#endif /* NVRAM_USER_DEFS_H */ 

