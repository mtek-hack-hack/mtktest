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
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   resource_custpack_jtbl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements indirect NVRAM jumps table for multi-load.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __L1_STANDALONE__

#include "MMI_features.h"

#include "kal_release.h"
#include "verno.h"
#include "custom_jump_tbl.h"
#include "custom_mmi_default_value.h"
#include "resource_custpack_jtbl.h"
#include "nvram_user_defs.h"
#include "resource_audio.h"
/* __CUSTPACK_MULTIBIN Calvin BEGIN */
#include "CustDataRes.h"        /* 040805 Calvin added */
#include "Kal_release.h"        /* 040805 Calvin added */
// __CUSTPACK_MULTIBIN Calvin END
// __CUSTPACK_MULTIBIN     Johnnie   BEGIN
#include "custom_wap_config.h"
/* __CUSTPACK_MULTIBIN     Johnnie   END */

/* __CUSTPACK_MULTIBIN Cylen BEGIN */
extern const kal_uint8 NVRAM_SETTING_DEFAULT[];
extern const kal_uint8 NVRAM_PHONEBOOK_SOS_DEFAULT[];
extern const kal_uint8 NVRAM_PHONEBOOK_SPEEDDIAL_DEFAULT[];
extern const kal_uint8 NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[];
extern const kal_uint8 NVRAM_EF_MS_SECURITY_DEFAULT[];
extern const kal_uint8 NVRAM_CACHE_BYTE_DEFAULT[];
extern const kal_uint8 NVRAM_CACHE_SHORT_DEFAULT[];
extern const kal_uint8 NVRAM_CACHE_DOUBLE_DEFAULT[];
extern const kal_uint8 NVRAM_EF_ALS_LINE_ID_DEFAULT[];
extern const kal_uint8 NVRAM_EF_MSCAP_DEFAULT[];
extern const kal_uint8 NVRAM_EF_RAC_PREFERENCE_DEFAULT[];

extern const custpack_nvram_header custpack_nvram_ptr;

/* __CUSTPACK_MULTIBIN Cylen END */

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
extern const CUSTPACK_IMAGE_HEADER mtk_image_header;    /* 040805 Calvin added */

/* __CUSTPACK_MULTIBIN Calvin END */

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
extern const CUSTPACK_AUDIO_HEADER mtk_audio_header;    /* 101205 audio resource Calvin added */

/* __CUSTPACK_MULTIBIN Calvin END */

extern const custpack_audio_header custpack_audio;

#ifdef __MTK_TARGET__
#pragma arm section rwdata = "RESOURCE_JUMP_TBL"
#endif 

Type_Preamble_Content CustPackResPreamble = {VERNO_STR,
    (kal_uint32) (RESOURCE_TYPE_CUSTPACK + CURRENT_CUSTPACK_RES_VERSION),
    CONST_RES_CUSTPACK_ADDR,
    CONST_RES_CUSTPACK_TBL_SIZE,
    CONST_RES_CUSTPACK_CONTENT_SIZE,
    (kal_uint32) MAGIC_NUMBER
};

#ifdef __MTK_TARGET__
#pragma arm section rwdata
#endif 

void *custpack2ndJumpTbl[] = 
{
    /* __CUSTPACK_MULTIBIN Calvin BEGIN */
    (void *)&mtk_image_header,      /* CUSTPACK_IMAGE            //040805 Calvin added */
    /* __CUSTPACK_MULTIBIN Calvin END */
    (void *)&custpack_audio,        /* CUSTPACK_AUDIO */
    (void *)&mtk_audio_header,      /* CUSTPACK_AUTOGEN_AUDIO            //101205 resource audio Calvin added */
    (void *)&custpack_nvram_ptr,    /* CUSTPACK_NVRAM */
#ifdef OBIGO_Q03C
    /* __CUSTPACK_MULTIBIN     Johnnie   BEGIN */
    (void *)&custpack_wap_ptr,      /* CUSTPACK_WAP */
    /* __CUSTPACK_MULTIBIN     Johnnie   END */
#endif /* OBIGO_Q03C */ 
    (void *)0                       /* CUSTPACK_VAR */
};

// #endif
#endif /* __L1_STANDALONE__ */ 

