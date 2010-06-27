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
*  mmi_ut_error.h
*
* Project:
* -------- 
*  MAUI
*
* Description:
* ------------
*  Error handling functions (user interface).
*
* Author:
* -------
*  Kun Liu (mbj06075)
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * 
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef MMI_UT_ERROR_H
#define MMI_UT_ERROR_H

#ifdef __MMI_TEST_FRAMEWORK__

#include "mmi_ut_internal.h"


/*****************************************************************************
*  mmi_ut error action codes.
* These are used to set the action desired when an error
* condition is detected in the mmi_ut framework.
*****************************************************************************/
typedef enum 
{
    MMI_UT_ERROR_ACTION_IGNORE,    /* Runs should be continued when an error condition occurs (if possible). */
    MMI_UT_ERROR_ACTION_FAIL,      /* Runs should be stopped when an error condition occurs. */
    MMI_UT_ERROR_ACTION_ABORT      /* The application should exit() when an error conditions occurs. */
} mmi_ut_error_action_enum;

/* Error handling & reporting functions. */

extern mmi_ut_error_code_enum mmi_ut_get_error(void);
extern void mmi_ut_print_error_msg(void);
extern void mmi_ut_set_error_action(mmi_ut_error_action_enum action);
extern mmi_ut_error_action_enum mmi_ut_get_error_action(void);

/* Internal function - users should not generally call this function */
void mmi_ut_set_error(mmi_ut_error_code_enum error);

#endif /* __MMI_TEST_FRAMEWORK__ */

#endif /* MMI_UT_ERROR_H */ 

