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
 *  MMSViewerMem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Viewer MEM Requirement 
 *
 *
 * Author: Sukrit K Mehra (PMT0050)
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMSVIEWERMEM_H__
#define __MMSVIEWERMEM_H__
#ifdef __MMI_MMS_2__

#include "custom_wap_config.h"

/* USE DETAILS */
#define MMI_MV_MAX_USE_DETAILS (60)
#define MMI_MV_MAX_USE_DETAILS_PER_SLIDE (15)
#define MMI_MV_MAX_URL_LEN    (512)
/* sizeof(applib_address_node_struct) +MMI_MV_MAX_URL_LEN */
#define MMI_MV_USE_DETAIL_STRUCT_SIZE (24+MMI_MV_MAX_URL_LEN)

/* ADDRESSES */
#define MMI_MV_MAX_ADDRESS_LEN (312) /* MMI_UC_MAX_ADDR_LEN */
/* sizeof(applib_address_node_struct) + MMI_MV_MAX_ADDRESS_LEN */
#define MMI_MV_ADDRESS_STRUCT_SIZE (24+MMI_MV_MAX_ADDRESS_LEN)
#define MMI_MV_MAX_MMS_ADDRESSES (WAP_CUSTOM_CFG_MAX_MMS_ADDRESS)

/* OBJECTS */
#define MMI_MV_MAX_OBJECTS_PER_SLIDE (3)
#define MMI_MV_MAX_SLIDES (WAP_CUSTOM_CFG_MAX_MMS_SLIDES)
#define MMI_MV_MAX_OBJECTS (MMI_MV_MAX_OBJECTS_PER_SLIDE * MMI_MV_MAX_SLIDES)
#define MMI_MV_MAX_FILE_PATH_LEN (260 * 2)
#define MMI_MV_MAX_FILE_NAME_LEN (100 * 2)


/*  + sizeof(mmi_mv_attachment_info_struct) 
    + sizeof(wgui_mv_object_struct) 
    + sizeof(wgui_mv_slide_struct) 
    + MMI_MV_MAX_FILE_PATH_LEN 
    + MMI_MV_MAX_FILE_NAME_LEN */
#define MMI_MV_MMS_OBJECT_STRUCT_SIZE (200 + MMI_MV_MAX_FILE_PATH_LEN + MMI_MV_MAX_FILE_NAME_LEN )

/* TEXT */
/* Temp UTF-8 Buffer's Size */
#define MMI_MV_MAX_UTF8_TXT_SLIDE_LEN (20480)
/* UCS2 Buffer's Size (made from UTF-8 buffer) */
#define MMI_MV_TXT_BUF_UCS2_SIZE (MMI_MV_MAX_UTF8_TXT_SLIDE_LEN * 2)
/* Buffer supplied to multiline inputbox */
#define MMI_MV_TXT_INPUTBOX_BUFFER_SIZE (5120) /* CAT630_MAIN_TXT_BUFFER_SIZE => 512*5 *ENCODING_LENGTH */

/* USE DETAIL MEMORY REQUIREMENT */
#define MMI_MV_USE_DETAIL_MEM_SIZE (MMI_MV_USE_DETAIL_STRUCT_SIZE * MMI_MV_MAX_USE_DETAILS)
/* ADDRESSES MEMORY REQUIREMENT */
#define MMI_MV_ADDRESSES_MEM_SIZE (MMI_MV_ADDRESS_STRUCT_SIZE * MMI_MV_MAX_MMS_ADDRESSES)
/* OBJECTS MEMORY REQUIREMENT */
#define MMI_MV_OBJECT_MEM_SIZE (MMI_MV_MMS_OBJECT_STRUCT_SIZE * MMI_MV_MAX_OBJECTS )
/* TEXT MEMORY REQUIREMENT */
#define MMI_MV_TEXT_MEM_SIZE (MMI_MV_MAX_UTF8_TXT_SLIDE_LEN +  MMI_MV_TXT_BUF_UCS2_SIZE + MMI_MV_TXT_INPUTBOX_BUFFER_SIZE)

#define MMI_MV_CONTEXT_MEM_SIZE ((MMI_MV_USE_DETAIL_MEM_SIZE) + \
                                (MMI_MV_ADDRESSES_MEM_SIZE) +   \
                                (MMI_MV_OBJECT_MEM_SIZE) +      \
                                (5 * 1024))

#define MMI_MV_ASM_MEM_POOL_SIZE ( MMI_MV_TEXT_MEM_SIZE + MMI_MV_CONTEXT_MEM_SIZE )

#endif /* __MMI_MMS_2__ */
#endif /* __MMSVIEWERMEM_H__ */ 
