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
 *    bmt_create.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements bmt task create function
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_comm.h"
#include    "syscomp_config.h" 

/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool    bmt_create(comptask_handler_struct **handle);

extern void bmt_task_main(task_entry_struct *task_entry_ptr);
extern void RTC_start_cali(void);
static kal_bool   bmt_task_init(task_indx_type task_indx);
static kal_bool   bmt_task_reset(task_indx_type task_indx);
static kal_bool   bmt_task_end(task_indx_type task_indx);

/*************************************************************************
* FUNCTION                                                            
*	bmt_create
*
* DESCRIPTION                                                           
*	This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
bmt_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct bmt_handler_info = 
	{
		bmt_task_main,			/* task entry function */
		bmt_task_init,			/* task initialization function */
		NULL,		/* task configuration function */
		bmt_task_reset,		/* task reset handler */
		bmt_task_end			/* task termination handler */
	};

	*handle = (comptask_handler_struct *)&bmt_handler_info;
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	bmt_task_init
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
bmt_task_init(task_indx_type task_indx)
{
	/* Do task's initialization here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
   RTC_start_cali();
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	bmt_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
bmt_task_reset(task_indx_type task_indx)
{
	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	bmt_task_end
*
* DESCRIPTION
*	This function implements xyz's termination handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
bmt_task_end(task_indx_type task_indx)
{
	/* Do task's termination here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_end() will do. */
	return KAL_TRUE;
}

