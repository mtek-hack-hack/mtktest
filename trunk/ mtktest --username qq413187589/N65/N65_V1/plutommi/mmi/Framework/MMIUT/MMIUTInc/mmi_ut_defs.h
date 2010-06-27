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
*  mmi_ut_defs.h
*
* Project:
* -------- 
*  MAUI
*
* Description:
* ------------
*  
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
#ifndef MMI_UT_DEFS_H
#define MMI_UT_DEFS_H

#ifdef __MMI_TEST_FRAMEWORK__

enum STR_MMI_UT_LIST
{
    STR_MMI_UT_UI_TITLE = RESOURCE_BASE_MMI_UT + 1,
    STR_MMI_UT_DEFAULT_TEST_NAME,      /* Test No.%d */ 
    STR_MMI_UT_SUITES_TOTAL,           /* Suites Total */    
    STR_MMI_UT_SUITES_RAN,             /* Suites Ran */    
    STR_MMI_UT_SUITES_PASSED,          /* Suites Passed */
    STR_MMI_UT_SUITES_FAILED,          /* Suites Failed */ 
    STR_MMI_UT_TEST_TOTAL,             /* Tests Total */
    STR_MMI_UT_TEST_RAN,               /* Tests Ran */
    STR_MMI_UT_TESTS_PASSED,           /* Tests Passed */ 
    STR_MMI_UT_TESTS_FAILED,           /* Tests Failed */   
    STR_MMI_UT_CHECKS_TOTAL,           /* Checks Total */    
    STR_MMI_UT_CHECKS_RAN,             /* Checks Ran */
    STR_MMI_UT_CHECKS_PASSED,          /* Checks Passed */ 
    STR_MMI_UT_CHECKS_FAILED,          /* Checks Failed */
    STR_MMI_UT_RUN_ALL_TESTS,          /* Run all tests */
    STR_MMI_UT_NA,                     /* n/a */
    STR_MMI_UT_ELLIPSIS                /* ... */ 
};

enum SCR_MMI_UT_LIST
{
    SCR_MMI_UT_UI_SUITES_LIST_ID = RESOURCE_BASE_MMI_UT + 1,
    SCR_MMI_UT_UI_TESTS_LIST_ID,
    SCR_MMI_UT_UI_RESULT_ID
};

#endif /* __MMI_TEST_FRAMEWORK__ */

#endif /* MMI_UT_DEFS_H */ 

