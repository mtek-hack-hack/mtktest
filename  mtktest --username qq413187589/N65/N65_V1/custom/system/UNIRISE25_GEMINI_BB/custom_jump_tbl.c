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
 *   custom_jump_tbl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   source file for indirect jump table for multiple binary load
 *
 * Author:
 * -------
 *   system auto generator V0.30
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

#if ( (defined(__MTK_TARGET__) || defined (MTK_KAL_MNT) || defined(KAL_ON_OSCAR) ) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) ) 

#include "custom_jump_tbl.h"
#include "verno.h"

/* __CUSTPACK_MULTIBIN */

const Type_Preamble_Content  system_jump_table[8] = { 
   /* Language Pack */
   { VERNO_STR,
     (kal_uint32)(RESOURCE_TYPE_LANG_PACK + CURRENT_LANG_PACK_RES_VERSION), 
     CONST_RES_LANG_PACK_ADDR,
     CONST_RES_LANG_PACK_TBL_SIZE,
     CONST_RES_LANG_PACK_CONTENT_SIZE, 
     (kal_uint32)MAGIC_NUMBER
   },
   /*__CUSTPACK_MULTIBIN__ */
   { VERNO_STR,
     (kal_uint32)(RESOURCE_TYPE_CUSTPACK+CURRENT_CUSTPACK_RES_VERSION),
     CONST_RES_CUSTPACK_ADDR,
     CONST_RES_CUSTPACK_TBL_SIZE,
     CONST_RES_CUSTPACK_CONTENT_SIZE,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   { VERNO_STR,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   }
}; 

#endif
