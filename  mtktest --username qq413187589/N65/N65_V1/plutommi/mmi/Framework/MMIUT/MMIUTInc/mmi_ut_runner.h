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
 *  mmi_ut_runner.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Test run management functions (user interface).
 *  The TestRuner module implements functions supporting the running
 *  of tests elements (suites and tests).  This includes functions for
 *  running suites and tests, retrieving the number of tests/suites run,
 *  and managing callbacks during the run process.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_UT_RUNNER_H
#define MMI_UT_RUNNER_H

#ifdef __MMI_TEST_FRAMEWORK__

#include "mmi_ut_internal.h"



    /*  mmi_ut_failure_record_struct type definition. */
    /*  Data type for holding check failure information. */

    typedef struct
    {       
        mmi_ut_test_struct  *test_p;                     /* Test containing failure.                   */
        mmi_ut_suite_struct *suite_p;                   /* Suite containing test having failure.      */
        U32 line_number;                                /* Line number of failure.                    */
        S8  str_file_name[MMI_UT_FILE_NAME_LENGTH + 1]; /* Name of file where failure occurred.       */
        S8  str_condition[MMI_UT_CONDITION_LENGTH + 1]; /* Test condition which failed.               */
    } mmi_ut_failure_record_struct;

    /*  mmi_ut_run_summary_struct type definition. */
    /*  Data type for holding statistics and check failures for a test run. */
    typedef struct
    {
        U32 suites_run;        /* Number of suites completed during run.            */
        U32 suites_failed;     /* Number of suites for which initialization failed. */
        U32 tests_run;         /* Number of tests completed during run.             */
        U32 tests_failed;      /* Number of tests containing failed assertions.     */
        U32 checks;            /* Number of assertions tested during run.           */
        U32 checks_failed;     /* Number of failed assertions.                      */
        U32 failure_records;   /* Number of failure records generated.              */
    } mmi_ut_run_summary_struct;

    /* Type Definitions for Message Handlers. */
    /* Message handler called at the start of a test.
     * The parameters are the test and suite being run.
     * The test run is considered in progress when the
     * message handler is called.  Neither test_p nor
     * suite_p may be null.
     */
    typedef void (*mmi_ut_test_start_message_handler) (const mmi_ut_test_struct *test_p,
                                                       const mmi_ut_suite_struct *suite_p);
    /*
     * Message handler called at the completion of a test.
     * The parameters are the test and suite being run, plus
     * a pointer to the first failure record applicable to
     * this test.  If the test did not have any assertion
     * failures, pFailure will be NULL.
     * The test run is considered in progress when the
     * message handler is called.
     */
    typedef void (*mmi_ut_test_complete_message_handler) (const mmi_ut_test_struct *test_p,
                                                          const mmi_ut_suite_struct *suite_p,
                                                          MMI_BOOL passed);
    /*
     * Message handler called at the completion of a test run.
     * The parameter is a pointer to the linked list holding
     * the failure records for the test run.
     * The test run is considered completed when the
     * message handler is called.
     */
    typedef void (*mmi_ut_all_tests_complete_message_handler) (void);


    /*
     * Message handler called at occurs a failure.
     */
    typedef void (*mmi_ut_failure_message_handler)(mmi_ut_failure_record_struct  *failure_record_p);

    
    /* Get/Set functions for Message Handlers. */
    extern void mmi_ut_set_test_start_handler(mmi_ut_test_start_message_handler test_start_message_p);
    extern void mmi_ut_set_test_complete_handler(mmi_ut_test_complete_message_handler test_complete_message_p);
    extern void mmi_ut_set_all_test_complete_handler(
                    mmi_ut_all_tests_complete_message_handler all_tests_complete_message_p);
    extern void mmi_ut_set_failure_message_handler(mmi_ut_failure_message_handler failure_message_handler_p);
    
    extern mmi_ut_test_start_message_handler mmi_ut_get_test_start_handler(void);
    extern mmi_ut_test_complete_message_handler mmi_ut_get_test_complete_handler(void);
    extern mmi_ut_all_tests_complete_message_handler mmi_ut_get_all_test_complete_handler(void);
  
    /* Functions for running registered tests and suites. */
    extern mmi_ut_error_code_enum mmi_ut_run_registry(mmi_ut_test_registry_struct *registry_p);
    extern mmi_ut_error_code_enum mmi_ut_run_suite(mmi_ut_test_registry_struct *registry_p,
                                                   mmi_ut_suite_struct *suite_p);
    extern mmi_ut_error_code_enum mmi_ut_run_test(mmi_ut_test_registry_struct *registry_p,
                                                  mmi_ut_suite_struct *suite_p,
                                                  mmi_ut_test_struct *test_p);

    /* Functions for getting information about the previous test run. */
    extern unsigned int mmi_ut_get_number_of_suites_run(void);
    extern unsigned int mmi_ut_get_number_of_suites_failed(void);
    extern unsigned int mmi_ut_get_number_of_tests_run(void);
    extern unsigned int mmi_ut_get_number_of_tests_failed(void);
    extern unsigned int mmi_ut_get_number_of_asserts(void);
    extern unsigned int mmi_ut_get_number_of_successes(void);
    extern unsigned int mmi_ut_get_number_of_failures(void);
    extern unsigned int mmi_ut_get_number_of_failure_records(void);
    extern mmi_ut_run_summary_struct *mmi_ut_get_run_summary(void);

    /* Functions for internal & testing use. */
    extern mmi_ut_suite_struct *mmi_ut_get_current_suite(void);
    extern mmi_ut_test_struct *mmi_ut_get_current_test(void);
    extern MMI_BOOL mmi_ut_is_test_running(void);
    
#endif /* __MMI_TEST_FRAMEWORK__ */

#endif /* MMI_UT_RUNNER_H */ 

