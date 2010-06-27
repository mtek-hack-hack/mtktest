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
 *  ResMemMgrGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Exported APIs for Resource Memroy Manager
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _RES_MEM_MGR_GPROT_H_
#define _RES_MEM_MGR_GPROT_H_

/***************************************************************************** 
* Include
*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
/*----------------------------------------------------------------*
  Image resource                                                 
 *----------------------------------------------------------------*/
#define MMI_FRM_RESMEM_SCATTER_MAX_NUMBER   128

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/*----------------------------------------------------------------*
  Image resource                                                 
 *----------------------------------------------------------------*/
/* strucutre to receieve information passing from resource-generated table */
typedef struct
{
    U16 id;
    U32 offset;
    U32 size;
} mmi_frm_resmem_res_info_struct;

typedef enum
{
    MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND = 0x00000001,
    MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST = 0x00000002,

    MMI_FRM_RESMEM_TYPE_EOE
} mmi_frm_resmem_enum;

/*----------------------------------------------------------------*
  String resource
 *----------------------------------------------------------------*/

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/

/*****************************************************************************              
* Extern Global Function                                                                    
*****************************************************************************/
/*----------------------------------------------------------------*
  Image resource                                                 
 *----------------------------------------------------------------*/
extern void mmi_frm_resmem_init(void);
extern U8 *mmi_frm_resmem_if_ramed(U16 id);
extern U8 *mmi_frm_resmem_load_single_image(U16 id, U32 offset, U32 size);
extern U8 *mmi_frm_resmem_load_multi_image(U16 id, const mmi_frm_resmem_res_info_struct *info_array, U32 res_cnt);
extern void mmi_frm_resmem_reset(U32 flag);
extern void mmi_frm_resmem_reg_retain(U16 id);
extern void mmi_frm_resmem_dereg_retain(U16 id);

/*----------------------------------------------------------------*
  String resource
 *----------------------------------------------------------------*/
extern void mmi_frm_resmem_load_str_suite(U8 **ptr_ary, U32 *offset_ary, U32 *size_ary, U32 ary_count);
#endif /* _RES_MEM_MGR_GPROT_H_ */ 

