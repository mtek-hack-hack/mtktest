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
 *   custom_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the custom task index and module index configuration
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

#ifndef _CUSTOM_CONFIG_H
#define _CUSTOM_CONFIG_H

#include "kal_non_specific_general_types.h"


/*************************************************************************
* Steps to add component task
*
* DESCRIPTION
*   The file describes steps to add component task.
*
*  1. add component task's index (Please add before system service)
*
*  2. add component task's module id definition (Please add before system service)
*
*  3. add module to task transformation in syscomp_config.c
*
*  4. add and implement component task's create handler
*
* GLOBALS AFFECTED
*
*************************************************************************/

/*************************************************************************
 * [Very Important Message]
 * 1. Component Task Index (Please add before system service)
 * 2. Customers are allowed to create at most 16 tasks as defined in 
 *    config\include\stack_config.h (MAX_CUSTOM_TASKS = 16)
 *************************************************************************/
typedef enum {
   INDX_CUSTOM1 = RPS_CUSTOM_TASKS_BEGIN,
   INDX_CUSTOM2,
   INDX_CUSTCMS,//05.10.18 pan add
   RPS_CUSTOM_TASKS_END
} custom_task_indx_type;

/*************************************************************************
 * [Very Important Message]
 * 1. Component task's module id (Please add before system service)
 * 2. Customers are allowed to create at most 16 task module ID as defined 
 *    in config\include\stack_config.h (MAX_CUSTOM_MODS = 16)
 *************************************************************************/
typedef enum {
   MOD_CUSTOM1 = MOD_CUSTOM_BEGIN,
   MOD_CUSTOM2,
   MOD_CMSMMS,//05.10.18 pan add
   MOD_CMSWAP,
   MOD_CMSMAP,
   MOD_CUSTOM_END
} custom_module_type;

/*************************************************************************
 * Other Declarations
 *************************************************************************/
extern custom_task_indx_type custom_mod_task_g[ MAX_CUSTOM_MODS ];

#endif /* _CUSTOM_CONFIG_H */

