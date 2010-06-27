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
 *  AppMemMgrGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI UI related functions for App-based ASM
 *
 *  (Other API are declared in app_mem.h)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _APP_MEM_MGR_GPROT_H_
#define _APP_MEM_MGR_GPROT_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef _MMI_DATA_TYPE_H
#error "Please include MMIDataType.h"
#endif 

#include "kal_non_specific_general_types.h"
#include "app_mem.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Max number of applications shown in the "Stop Application" screen */
#define MMI_FRM_APPMEM_MAX_APP_PROMPTED     (10)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/*****************************************************************************              
 * Extern Global Variable                                                                    
 *****************************************************************************/

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/
extern void mmi_frm_appmem_init(void);

extern void mmi_frm_appmem_prompt_to_release_mem(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
                U32 required_size,
                void (*success_callback)(void));

extern void mmi_frm_appmem_prompt_to_release_full_pool(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
                void (*success_callback)(void));

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/

#ifdef APPLIB_MEM_UNIT_TEST
extern void mmi_frm_appmem_unit_test_setup_environment(MMI_BOOL stress_test);

extern void mmi_frm_appmem_unit_test_prepare_to_enter_test1(void (*run_callback)(void), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test2(void (*run_callback)(void), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test3(void (*run_callback)(void), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test4(void (*run_callback)(void), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test5(void (*run_callback)(void), MMI_BOOL clear_all);
#endif /* APPLIB_MEM_UNIT_TEST */

#endif /* _APP_MEM_MGR_GPROT_H_ */ 

