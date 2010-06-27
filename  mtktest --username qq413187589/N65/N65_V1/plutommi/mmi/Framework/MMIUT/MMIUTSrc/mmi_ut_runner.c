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
 *  mmi_ut_runner.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Test run management functions (implementation).
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

#ifdef __MMI_TEST_FRAMEWORK__

#include "mmi_ut_runner.h"

typedef enum {
    MMI_UT_RUN_REGISTRY,
    MMI_UT_RUN_SUITE,
    MMI_UT_RUN_TEST    
}mmi_ut_run_type_enum;

static mmi_ut_run_type_enum g_run_type;                  
static MMI_BOOL g_test_is_running = MMI_FALSE;      /* Flag for whether a test run is in progress */
static MMI_BOOL g_is_async_test = MMI_FALSE;        /* Flag for whether a test run is in asynchronous progress  */

static mmi_ut_test_registry_struct *g_cur_registry_p = NULL; /* Pointer to the registry currently being run. */
static mmi_ut_suite_struct *g_cur_suite_p = NULL;            /* Pointer to the suite currently being run. */
static mmi_ut_test_struct *g_cur_test_p = NULL;              /* Pointer to the test currently being run. */

/* mmi_ut_run_summary_struct to hold results of each test run. */
static mmi_ut_run_summary_struct g_run_summary = {0, 0, 0, 0, 0, 0, 0};

/* Pointer to the function to be called before running a test. */
static mmi_ut_test_start_message_handler g_test_start_message_handler_p = NULL;

/* Pointer to the function to be called after running a test. */
static mmi_ut_test_complete_message_handler g_test_complete_message_handler_p = NULL;

/* Pointer to the function to be called when all tests have been run. */
static mmi_ut_all_tests_complete_message_handler g_all_tests_complete_message_handler_p = NULL;

static mmi_ut_failure_message_handler g_failure_message_handler_p = NULL;

/* Forward declarations of static functions. */
static void mmi_ut_clear_previous_results(mmi_ut_run_summary_struct *run_summary_p);
static void mmi_ut_add_failure(
                mmi_ut_run_summary_struct *run_summary_p,
                unsigned int line_number,
                S8 str_condition[],
                S8 str_file_name[],
                mmi_ut_suite_struct *suite_p,
                mmi_ut_test_struct *test_p);
static void mmi_ut_all_tests_complete(void);
static mmi_ut_error_code_enum mmi_ut_run_single_registry(
                                mmi_ut_test_registry_struct *registry_p,
                                mmi_ut_run_summary_struct *run_summary_p);
static mmi_ut_error_code_enum mmi_ut_pre_run_single_registry(mmi_ut_test_registry_struct *registry_p,
                                                          mmi_ut_run_summary_struct *run_summary_p);
static mmi_ut_error_code_enum mmi_ut_post_run_single_registry(mmi_ut_test_registry_struct *registry_p,
                                                          mmi_ut_run_summary_struct *run_summary_p);
static mmi_ut_error_code_enum mmi_ut_run_single_suite(mmi_ut_suite_struct *suite_p,
                                                      mmi_ut_run_summary_struct *run_summary_p);
static mmi_ut_error_code_enum mmi_ut_pre_run_single_suite(mmi_ut_suite_struct *suite_p,
                                                          mmi_ut_run_summary_struct *run_summary_p);
static mmi_ut_error_code_enum mmi_ut_post_run_single_suite(mmi_ut_suite_struct *suite_p,
                                                          mmi_ut_run_summary_struct *run_summary_p);
static mmi_ut_error_code_enum mmi_ut_run_single_test(mmi_ut_test_struct *test_p, 
                                              mmi_ut_run_summary_struct *run_summary_p);
static mmi_ut_error_code_enum mmi_ut_pre_run_single_test(mmi_ut_test_struct *test_p,
                                                          mmi_ut_run_summary_struct *run_summary_p);
static mmi_ut_error_code_enum mmi_ut_post_run_single_test(mmi_ut_test_struct *test_p,
                                                          mmi_ut_run_summary_struct *run_summary_p,
                                                          MMI_BOOL passed);
static S8* mmi_ut_filter_filename(const S8 *str_file_path);





/*****************************************************************************
 * FUNCTION
 *  mmi_ut_assert_implementation
 * DESCRIPTION
 *  Assertion implementation function.
 *  All mmi_ut assertions reduce to a call to this function.
 *  It should only be called during an active test run (checked
 *  by assertion).  This means that mmi_ut assertions should only
 *  be used in registered test functions during a test run.
 * PARAMETERS
 *  value               [IN]        Value of the assertion (MMI_TRUE or MMI_FALSE).
 *  line                [IN]        Line number of failed test statement.
 *  str_condition       [IN]        String containing logical test that failed.
 *  str_file            [IN]        Source file where test statement failed.
 *  str_function        [IN]        Function where test statement failed.
 *  fatal               [IN]        MMI_TRUE to abort test (via longjmp()), MMI_FALSE to continue test.
 * RETURNS
 *  return the input value.
 *****************************************************************************/
MMI_BOOL mmi_ut_check_implementation(
            MMI_BOOL value,
            U32 line,
            S8 str_condition[],
            S8 str_file[],
            S8 str_function[],
            MMI_BOOL fatal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* not used in current implementation - stop compiler warning */
    MMI_UT_UNREFERENCED_PARAMETER(str_function);
    MMI_UT_UNREFERENCED_PARAMETER(fatal);

    /* these should always be non-NULL (i.e. a test run is in progress) */
    MMI_ASSERT(NULL != g_cur_suite_p);
    MMI_ASSERT(NULL != g_cur_test_p);

    g_run_summary.checks++;
    if (MMI_FALSE == value)
    {
        ++g_run_summary.checks_failed;
        mmi_ut_add_failure(&g_run_summary, line, str_condition, str_file, g_cur_suite_p, g_cur_test_p);
    }

    return value;
}


/*
 * Get/Set functions for Message Handlers.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_set_test_start_handler
 * DESCRIPTION
 *  Set the message handler to call before each test is run
 * PARAMETERS
 *  test_start_handler_p        [IN]     the message handler to call before each test is run   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ut_set_test_start_handler(mmi_ut_test_start_message_handler test_start_handler_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_test_start_message_handler_p = test_start_handler_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_set_test_complete_handler
 * DESCRIPTION
 *  Set the message handler to call after each test is run.
 * PARAMETERS
 *  test_complete_handler_p     [IN]    the message handler to call after each test is run.    
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ut_set_test_complete_handler(mmi_ut_test_complete_message_handler test_complete_handler_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_test_complete_message_handler_p = test_complete_handler_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_set_all_test_complete_handler
 * DESCRIPTION
 *  Set the message handler to call after all tests have been run.
 * PARAMETERS
 *  all_tests_complete_handler_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ut_set_all_test_complete_handler(mmi_ut_all_tests_complete_message_handler all_tests_complete_handler_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_all_tests_complete_message_handler_p = all_tests_complete_handler_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_set_failure_message_handler
 * DESCRIPTION
 *  Set the message handler to call after occurs a failure.
 * PARAMETERS
 *  failure_message_handler_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ut_set_failure_message_handler(mmi_ut_failure_message_handler failure_message_handler_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_failure_message_handler_p = failure_message_handler_p;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_test_start_handler
 * DESCRIPTION
 *  Retrieve the message handler called before each test is run.
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the message handler which called at the start of a test.
 *****************************************************************************/
mmi_ut_test_start_message_handler mmi_ut_get_test_start_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_test_start_message_handler_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_test_complete_handler
 * DESCRIPTION
 *  Retrieve the message handler called after each test is run.
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the message handler which called at the completion of a test.
 *****************************************************************************/
mmi_ut_test_complete_message_handler mmi_ut_get_test_complete_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_test_complete_message_handler_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_all_test_complete_handler
 * DESCRIPTION
 *  Retrieve the message handler called after all tests are run.
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the message handler called after all tests are run.
 *****************************************************************************/
mmi_ut_all_tests_complete_message_handler mmi_ut_get_all_test_complete_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_all_tests_complete_message_handler_p;
}

/*
 * Functions to get the Run statistics for the Test Run.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_number_of_suites_run
 * DESCRIPTION
 *  Retrieve the number of suites completed during the previous run.
 *  The count is reset each time the client initiates a run.
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the number of suites completed during the previous run.
 *****************************************************************************/
U32 mmi_ut_get_number_of_suites_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_run_summary.suites_run;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_number_of_suites_failed
 * DESCRIPTION
 *  Retrieve the number of suites which failed to initialize
 *  during the previous run.
 *  The count is reset each time the client initiates a run.
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the number of suites which failed to initialize
 *  during the previous run.
 *****************************************************************************/
U32 mmi_ut_get_number_of_suites_failed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_run_summary.suites_failed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_number_of_tests_run
 * DESCRIPTION
 *  Retrieve the number of tests completed during the previous run.
 *  The count is reset each time the client initiates a run.
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the number of tests completed during the previous run.
 *****************************************************************************/
U32 mmi_ut_get_number_of_tests_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_run_summary.tests_run;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_number_of_tests_failed
 * DESCRIPTION
 *  Retrieve the number of tests which contained failed
 *  assertions during the previous run.
 *  The count is reset each time the client initiates a run.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the number of tests which contained failed
 *  assertions during the previous run.
 *****************************************************************************/
U32 mmi_ut_get_number_of_tests_failed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_run_summary.tests_failed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_number_of_asserts
 * DESCRIPTION
 *  Retrieve the number of assertions processed during the last run.
 *  The count is reset each time the client initiates a run.
 * PARAMETERS
 *  void
 * RETURNS
 *  the number of assertions processed during the last run.
 *****************************************************************************/
U32 mmi_ut_get_number_of_checks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_run_summary.checks;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_number_of_successes
 * DESCRIPTION
 *  Retrieve the number of successful assertions during the last run.
 *  The count is reset each time the client initiates a run.
 * PARAMETERS
 *  void
 * RETURNS
 *  the number of successful assertions during the last run.
 *****************************************************************************/
U32 mmi_ut_get_number_of_successes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_run_summary.checks - g_run_summary.checks_failed);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_number_of_failures
 * DESCRIPTION
 *  Retrieve the number of failed assertions during the last run.
 *  The count is reset each time the client initiates a run.
 * PARAMETERS
 *  void
 * RETURNS
 *  the number of failed assertions during the last run.
 *****************************************************************************/
U32 mmi_ut_get_number_of_failures(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_run_summary.checks_failed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_number_of_failure_records
 * DESCRIPTION
 *  Retrieve the number failure records created during
 *  the previous run.  Note that this may be more than the
 *  number of failed assertions, since failure records may also
 *  be created for failed suite initialization and cleanup.
 *  The count is reset each time the client initiates a run.
 * PARAMETERS
 *  void
 * RETURNS
 *  the number failure records created during the previous run. 
 *****************************************************************************/
U32 mmi_ut_get_number_of_failure_records(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_run_summary.failure_records;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_run_summary
 * DESCRIPTION
 *  Retrieve the entire run summary for the last test run.
 *  Note that the pFailure pointer in the run summary is
 *  invalidated when the client initiates a run using
 * PARAMETERS
 *  void
 * RETURNS
 *  the entire run summary for the last test run.
 *****************************************************************************/
mmi_ut_run_summary_struct *mmi_ut_get_run_summary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_run_summary;
}

/*
 * Functions for running suites and tests.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_run_registry
 * DESCRIPTION
 *  Run all tests in all suites registered in the test registry.
 *  The suites are run in the order registered in the test registry.
 *  For each registered suite, any initialization function is first
 *  called, the suite is run using mmi_ut_run_single_suite(), and finally
 *  any  suite cleanup function is called.  If an error condition
 *  (other than MMI_UT_ERROR_CODE_NOREGISTRY) occurs during the run, the action
 *  depends on the current error action (see mmi_ut_set_error_action()).
 * PARAMETERS
 *  void
 * RETURNS
 *  return A mmi_ut_error_code_enum indicating the first error condition
 *  encountered while running the tests.
 *****************************************************************************/
mmi_ut_error_code_enum mmi_ut_run_registry(mmi_ut_test_registry_struct *registry_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);
    if (NULL == registry_p)
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_NOREGISTRY);
    }
    else
    {
        /* test run is starting - set flag */
        g_test_is_running = MMI_TRUE;

        g_run_type = MMI_UT_RUN_REGISTRY;

        /* Clear results from the previous run */
        mmi_ut_clear_previous_results(&g_run_summary);       
        
        mmi_ut_run_single_registry(registry_p, &g_run_summary);
    }

    return mmi_ut_get_error();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_run_suite
 * DESCRIPTION
 *  Run all tests in a specified suite.
 *  The suite need not be registered in the test registry to be run.
 *  Any initialization function for the suite is first called,
 *  then the suite is run using mmi_ut_run_single_suite(), and any
 *  suite cleanup function is called.  Note that the
 *  run statistics (counts of tests, successes, failures)
 *  are initialized each time this function is called.
 *  If an error condition occurs during the run, the action
 *  depends on the current error action (see mmi_ut_set_error_action()).
 * PARAMETERS
 *  suite_p     [IN]        The suite containing the test (non-NULL)
 * RETURNS
 *  return A mmi_ut_error_code_enum indicating the first error condition
 *  encountered while running the suite.  mmi_ut_run_suite()
 *  sets and returns MMI_UT_ERROR_CODE_NOSUITE if suite_p is NULL.  Other
 *  error codes can be set during suite initialization or
 *  cleanup or during test runs.
 *****************************************************************************/
mmi_ut_error_code_enum mmi_ut_run_suite(mmi_ut_test_registry_struct *registry_p, 
                                        mmi_ut_suite_struct *suite_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ut_set_error(result = MMI_UT_ERROR_CODE_SUCCESS);

    if (NULL == registry_p)
    {
        mmi_ut_set_error(result = MMI_UT_ERROR_CODE_NOREGISTRY);
        return result;
    }
    if (NULL == suite_p)
    {
        mmi_ut_set_error(result = MMI_UT_ERROR_CODE_NOSUITE);
        return result;
    }
    else
    {
        /* test run is starting - set flag */
        g_test_is_running = MMI_TRUE;

        /* Clear results from the previous run */
        mmi_ut_clear_previous_results(&g_run_summary);

        g_run_type = MMI_UT_RUN_SUITE;

        g_cur_registry_p = registry_p;

        if ((result = mmi_ut_pre_run_single_registry(g_cur_registry_p, &g_run_summary)) != MMI_UT_ERROR_CODE_SUCCESS)
        {
            return result;
        }
        
        result = mmi_ut_run_single_suite(suite_p, &g_run_summary);

        if (!g_is_async_test)
        {
            mmi_ut_post_run_single_registry(g_cur_registry_p, &g_run_summary);
        }       
    }

    return result;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_ut_run_test
 * DESCRIPTION
 *  Run a specific test in a specified suite.
 *  The suite need not be registered in the test registry to be run,
 *  although the test must be registered in the specified suite.
 *  Any initialization function for the suite is first
 *  called, then the test is run using mmi_ut_run_single_suite(), and
 *  any suite cleanup function is called.  Note that the
 *  run statistics (counts of tests, successes, failures)
 *  are initialized each time this function is called.
 * PARAMETERS
 *  suite_p     [IN]        The suite containing the test (non-NULL)
 *  test_p      [IN]        The test to run (non-NULL)
 * RETURNS
 *  return A mmi_ut_error_code_enum indicating the first error condition
 *  encountered while running the suite.  mmi_ut_run_test()
 *  sets and returns MMI_UT_ERROR_CODE_NOSUITE if suite_p is NULL,
 *  MMI_UT_ERROR_CODE_NOTEST if test_p is NULL, and MMI_UT_ERROR_CODE_TEST_NOT_IN_SUITE
 *  if test_p is not registered in suite_p.  Other
 *  error codes can be set during suite initialization or
 *  cleanup or during the test run.
 *****************************************************************************/
mmi_ut_error_code_enum mmi_ut_run_test(mmi_ut_test_registry_struct *registry_p,
                                       mmi_ut_suite_struct *suite_p, 
                                       mmi_ut_test_struct *test_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);
    if (NULL == registry_p)
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_NOREGISTRY);
    }
    if (NULL == suite_p)
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_NOSUITE);
    }
    else if (NULL == test_p)
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_NOTEST);
    }
    else if ((NULL == test_p->str_name) || (NULL == mmi_ut_get_test_by_name(test_p->str_name, suite_p)))
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_TEST_NOT_IN_SUITE);
    }
    else
    {
        /* test run is starting - set flag */
        g_test_is_running = MMI_TRUE;

        /* Clear results from the previous run */
        mmi_ut_clear_previous_results(&g_run_summary);

        g_run_type = MMI_UT_RUN_TEST;

        g_cur_registry_p = registry_p;
        g_cur_suite_p    = suite_p;

        if (mmi_ut_pre_run_single_registry(g_cur_registry_p, &g_run_summary) != MMI_UT_ERROR_CODE_SUCCESS)
        {
            return mmi_ut_get_error();
        }

        if (mmi_ut_pre_run_single_suite(g_cur_suite_p, &g_run_summary) != MMI_UT_ERROR_CODE_SUCCESS)
        {
            return mmi_ut_get_error();
        }

        mmi_ut_run_single_test(test_p, &g_run_summary);

        if (!g_is_async_test)
        {
            mmi_ut_post_run_single_suite(g_cur_suite_p, &g_run_summary);

            mmi_ut_post_run_single_registry(g_cur_registry_p, &g_run_summary);
        }
        
    }

    return mmi_ut_get_error();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_all_tests_complete
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_ut_all_tests_complete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* test run is complete - clear flag */
    g_test_is_running = MMI_FALSE;

    if (NULL != g_all_tests_complete_message_handler_p)
    {
        (*g_all_tests_complete_message_handler_p) ();
    }

    g_cur_registry_p = NULL;
    g_cur_suite_p    = NULL;
    g_cur_test_p     = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_current_suite
 * DESCRIPTION
 *  Retrieve a pointer to the currently-running suite (NULL if none).
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to the currently-running suite
 *****************************************************************************/
mmi_ut_suite_struct *mmi_ut_get_current_suite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_cur_suite_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_current_test
 * DESCRIPTION
 *  Retrieve a pointer to the currently-running test (NULL if none).
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer to the currently-running test. 
 *****************************************************************************/
mmi_ut_test_struct *mmi_ut_get_current_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_cur_test_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_is_test_running
 * DESCRIPTION
 *  Returns MMI_TRUE if a test run is in progress,
 *  MMI_TRUE otherwise.
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns MMI_TRUE if a test run is in progress,
 *  MMI_TRUE otherwise.
 *****************************************************************************/
MMI_BOOL mmi_ut_is_test_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_test_is_running;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_add_failure
 * DESCRIPTION
 *  Record a failed test.
 *  This function is called whenever a test fails to record the
 *  details of the failure.  This includes user assertion failures
 *  and system errors such as failure to initialize a suite.
 * PARAMETERS
 *  run_summary_p       [IN]        Pointer to mmi_ut_run_summary_struct keeping track of failure records
 *                                  (ignored if NULL).
 *  line_number         [IN]        Line number of the failure, if applicable.
 *  str_condition       [IN]        Description of failure condition
 *  str_file_name       [IN]        Name of file, if applicable
 *  suite_p             [IN]        The suite being run at time of failure
 *  test_p              [IN]        The test being run at time of failure
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_add_failure(
        mmi_ut_run_summary_struct *run_summary_p,
        U32 line_number,
        S8 str_condition[],
        S8 str_file_path[],
        mmi_ut_suite_struct *suite_p,
        mmi_ut_test_struct *test_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* str_file_name = NULL;
    mmi_ut_failure_record_struct  failure_record;   
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != run_summary_p)
    {
        run_summary_p->failure_records++;
    }

    if (NULL != str_file_path)
    {
        str_file_name = mmi_ut_filter_filename(str_file_path);
    }

    failure_record.line_number = line_number;
    strncpy(failure_record.str_condition, str_condition, MMI_UT_CONDITION_LENGTH);
    strncpy(failure_record.str_file_name, str_file_name, MMI_UT_FILE_NAME_LENGTH);
    failure_record.suite_p = suite_p;
    failure_record.test_p  = test_p;
    
    (*g_failure_message_handler_p)(&failure_record);
    
}

/*
 *  Local function for result set initialization/cleanup.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_clear_previous_results
 * DESCRIPTION
 *  Initialize the run summary information in the
 *  specified structure.  Resets the run counts to zero.
 *  Calling this function multiple times, while inefficient,
 *  will not cause an error condition.
 * PARAMETERS
 *  run_summary_p       [IN]        Mmi_ut_run_summary_struct to initialize (non-NULL).
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_clear_previous_results(mmi_ut_run_summary_struct *run_summary_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != run_summary_p);
    
    run_summary_p->suites_run = 0;
    run_summary_p->suites_failed = 0;
    run_summary_p->tests_run = 0;
    run_summary_p->tests_failed = 0;
    run_summary_p->checks = 0;
    run_summary_p->checks_failed = 0;
    run_summary_p->failure_records = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_run_single_registry
 * DESCRIPTION
 *  Run all tests in a specified registry.
 *  Internal function to run all tests in a registry. 
 *  If the mmi_ut system is in an error condition after running
 *  a test, no additional tests are run.
 * PARAMETERS
 *  suite_p             [IN]        The registry containing the test.
 *  run_summary_p       [IN]        The mmi_ut_run_summary_struct to receive the results (non-NULL).
 * RETURNS
 *  return A mmi_ut_error_code_enum indicating the status of the run 
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_run_single_registry(
                                mmi_ut_test_registry_struct *registry_p,
                                mmi_ut_run_summary_struct *run_summary_p)
                                
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ut_suite_struct *suite_p = NULL;
    static U32 count; 
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != run_summary_p);

    if (NULL != registry_p)
    {
        g_cur_registry_p =  registry_p;
        count = 0;

        if (mmi_ut_pre_run_single_registry(registry_p, run_summary_p) != MMI_UT_ERROR_CODE_SUCCESS)
        {
            return mmi_ut_get_error();
        }

        suite_p = registry_p->suite_p;        
    }
    else
    {
        suite_p = g_cur_suite_p;
            
        mmi_ut_run_single_suite(NULL, run_summary_p);

        if (g_is_async_test)
        {
            return mmi_ut_get_error();            
        }        

        suite_p++;
        count++;       
        
    }

    while ((count < registry_p->number_of_suites) &&
            ((MMI_UT_ERROR_CODE_SUCCESS == mmi_ut_get_error()) || (mmi_ut_get_error_action() == MMI_UT_ERROR_ACTION_IGNORE)))
    {
            
        mmi_ut_run_single_suite(suite_p, run_summary_p);        

        if (g_is_async_test)
        {
            return mmi_ut_get_error();            
        }
            
        suite_p++;
        count++; 
    }

    mmi_ut_post_run_single_registry(registry_p, run_summary_p);         

    return mmi_ut_get_error();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_pre_run_single_registry(mmi_ut_test_registry_struct *registry_p,
                                                          mmi_ut_run_summary_struct *run_summary_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum result = MMI_UT_ERROR_CODE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL != registry_p->pre_func_p)&& (MMI_TRUE != registry_p->pre_func_p()))
    {
        mmi_ut_add_failure(
            run_summary_p,
            0,
            "Registry pre-function failed - Registry Skipped",
            "mmi_ut syetem",
            NULL,
            NULL);
        
        mmi_ut_set_error(result = MMI_UT_ERROR_CODE_REGISTRY_PRE_FUNC_FAILED);

        g_test_is_running = MMI_FALSE;

        if (NULL != g_all_tests_complete_message_handler_p)
        {
            (*g_all_tests_complete_message_handler_p) ();
        }        
    }    

    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_post_run_single_registry(mmi_ut_test_registry_struct *registry_p,
                                                          mmi_ut_run_summary_struct *run_summary_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum result = MMI_UT_ERROR_CODE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL != registry_p->post_func_p)&& !(registry_p->post_func_p()))
    {
        mmi_ut_add_failure(run_summary_p,
                           0, 
                           "registry post-function failed.", 
                           "mmi_ut syetem", 
                           NULL, NULL
                           );
        mmi_ut_set_error(result = MMI_UT_ERROR_CODE_REGISTRY_POST_FUNC_FAILED);            
    }

    mmi_ut_all_tests_complete();

    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_run_single_suite
 * DESCRIPTION
 *  Run all tests in a specified suite.
 *  Internal function to run all tests in a suite.  The suite
 *  need not be registered in the test registry to be run.
 *  If the mmi_ut system is in an error condition after running
 *  a test, no additional tests are run.
 * PARAMETERS
 *  suite_p             [IN]        The suite containing the test (non-NULL).
 *  run_summary_p       [IN]        The mmi_ut_run_summary_struct to receive the results (non-NULL).
 * RETURNS
 *  return A mmi_ut_error_code_enum indicating the status of the run 
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_run_single_suite(
                                mmi_ut_suite_struct *suite_p,
                                mmi_ut_run_summary_struct *run_summary_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_test_struct *test_p = NULL;
    static U32 count;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != run_summary_p);

    if (NULL != suite_p)
    {
        g_cur_test_p  = NULL;
        g_cur_suite_p = suite_p;
        count         = 0;

        mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);
   
        if (mmi_ut_pre_run_single_suite(suite_p, run_summary_p) != MMI_UT_ERROR_CODE_SUCCESS)
        {        
            return mmi_ut_get_error();
        }

        test_p = suite_p->test_p;           
    }
    else
    {
        test_p = g_cur_test_p;

        mmi_ut_run_single_test(NULL, run_summary_p);
        if (g_is_async_test)
        {
            return mmi_ut_get_error();
        }
        
        count++;         
        test_p++;
        
    }

    while ((count < suite_p->number_of_tests) &&
           ((MMI_UT_ERROR_CODE_SUCCESS == mmi_ut_get_error()) || 
           (mmi_ut_get_error_action() == MMI_UT_ERROR_ACTION_IGNORE)))
    {
        mmi_ut_run_single_test(test_p, run_summary_p);
        if (g_is_async_test)
        {
            return mmi_ut_get_error();
        }
        
        count++;         
        test_p++;
    } 
    
    run_summary_p->suites_run++;
  
    mmi_ut_post_run_single_suite(suite_p, run_summary_p);    
        
    return mmi_ut_get_error();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_pre_run_single_suite(mmi_ut_suite_struct *suite_p,
                                                          mmi_ut_run_summary_struct *run_summary_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum result = MMI_UT_ERROR_CODE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL != suite_p->pre_func_p) && (MMI_TRUE != (*suite_p->pre_func_p) ()))
    {
        run_summary_p->suites_failed++;
        mmi_ut_add_failure(
            run_summary_p,
            0,
            "Suite pre-function failed - Suite Skipped",
            "mmi_ut syetem",
            suite_p,
            NULL);
        mmi_ut_set_error(result = MMI_UT_ERROR_CODE_SUITE_PRE_FUNC_FAILED);

        g_cur_suite_p = NULL;
    }

    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_post_run_single_suite(mmi_ut_suite_struct *suite_p,
                                                          mmi_ut_run_summary_struct *run_summary_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum result = MMI_UT_ERROR_CODE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL != suite_p->post_func_p) && (MMI_TRUE != (*suite_p->post_func_p) ()))
    {
        run_summary_p->suites_failed++;
        mmi_ut_add_failure(run_summary_p, 0, "Suite pre-function post-function failed.", "mmi_ut system", suite_p, g_cur_test_p);
        mmi_ut_set_error(MMI_UT_ERROR_CODE_SUITE_POST_FUNC_FAILED);
        result = (MMI_UT_ERROR_CODE_SUCCESS == result) ? MMI_UT_ERROR_CODE_SUITE_POST_FUNC_FAILED : result;
    }   

    g_cur_suite_p = NULL;
    
    return result;    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ut_run_single_suite
 * DESCRIPTION
 *  Run a specific test.
 *  Internal function to run a test case.  This includes
 *  calling any handler to be run before executing the test,
 *  running the test's function (if any), and calling any
 *  handler to be run after executing a test.
 * PARAMETERS
 *  test_p              [IN]        The test to be run (non-NULL).
 *  run_summary_p       [IN]        The mmi_ut_run_summary_struct to receive the results (non-NULL).
 * RETURNS
 *  return A mmi_ut_error_code_enum indicating the status of the run
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_run_single_test(mmi_ut_test_struct *test_p, mmi_ut_run_summary_struct *run_summary_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 start_failures;
    MMI_BOOL   passed = MMI_TRUE; 

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != g_cur_suite_p);    
    MMI_ASSERT(NULL != run_summary_p);

    if (NULL != test_p)
    {

        start_failures = run_summary_p->checks_failed;

        mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);
        g_cur_test_p = test_p;
    

        if  (mmi_ut_pre_run_single_test(test_p, run_summary_p) != MMI_UT_ERROR_CODE_SUCCESS)
        {        
            return mmi_ut_get_error();        
        }
    
        if (NULL != test_p->test_func_p)
        {
            (*test_p->test_func_p) ();
        }

        if (g_is_async_test)
        {
            return mmi_ut_get_error();
        }
    }    

    run_summary_p->tests_run++;

    /* if additional assertions have failed... */
    if (run_summary_p->checks_failed > start_failures)
    {
        run_summary_p->tests_failed++;
        passed = MMI_FALSE;
    }

    mmi_ut_post_run_single_test(test_p, run_summary_p, passed);    

    return mmi_ut_get_error();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_pre_run_single_test(mmi_ut_test_struct *test_p,
                                                          mmi_ut_run_summary_struct *run_summary_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum result = MMI_UT_ERROR_CODE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_test_start_message_handler_p)
    {
        (*g_test_start_message_handler_p) (g_cur_test_p, g_cur_suite_p);
    }

    
    if ((NULL != test_p->pre_func_p) && (MMI_TRUE != (*test_p->pre_func_p) ()))
    {       
        mmi_ut_add_failure(
            &g_run_summary,
            0,
            "test pre-function failed - Test Skipped",
            "mmi_ut syetem",
            g_cur_suite_p,
            test_p);
        mmi_ut_set_error(result = MMI_UT_ERROR_CODE_TEST_PRE_FUNC_FAILED);

        if (NULL != g_test_complete_message_handler_p)
        {
            (*g_test_complete_message_handler_p) (g_cur_test_p, g_cur_suite_p, MMI_FALSE);
        }
        g_cur_test_p = NULL;
    }   

    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_post_run_single_test(mmi_ut_test_struct *test_p,
                                                          mmi_ut_run_summary_struct *run_summary_p,
                                                          MMI_BOOL passed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum result = MMI_UT_ERROR_CODE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL != test_p->post_func_p) && (MMI_TRUE != (*test_p->post_func_p) ()))
    {        
        mmi_ut_add_failure(&g_run_summary, 0, "test post-function failed.", "mmi_ut syetem", g_cur_suite_p, test_p);
        mmi_ut_set_error(MMI_UT_ERROR_CODE_TEST_POST_FUNC_FAILED);
        result = (MMI_UT_ERROR_CODE_SUCCESS == result) ? MMI_UT_ERROR_CODE_TEST_POST_FUNC_FAILED : result;
    }

    if (NULL != g_test_complete_message_handler_p)
    {
        (*g_test_complete_message_handler_p) (g_cur_test_p, g_cur_suite_p, passed);
    }

    g_cur_test_p = NULL;    

    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_filter_filename
 * DESCRIPTION
 *  Get the file's name from the file's full path.
 * PARAMETERS
 *  str_file_path       [IN]    the file's full path.    
 * RETURNS
 *  the pointer to the the file's name
 *****************************************************************************/
static S8* mmi_ut_filter_filename(const S8 *str_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *str_file_name;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( NULL == (str_file_name = strrchr(str_file_path, '\\')))
    {
       if (NULL == (str_file_name = strrchr(str_file_path, '/')))
       {            
            return (S8*)str_file_path;
       }
    }
        
    return (++str_file_name);   
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ut_async_test_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_async_test = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ut_async_test_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    module_type src_mod_id;
    sap_type    sap_id = INVALID_SAP;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_mod_id = stack_get_active_module_id();
    ilm_ptr = allocate_ilm(src_mod_id);
   
    switch(src_mod_id)
    {
        case MOD_MMI:
            sap_id = MMI_MMI_SAP;
            break;

        case MOD_WAP:
            sap_id = WAP_MMI_SAP;
            break;

        case MOD_J2ME:
            sap_id = J2ME_MMI_SAP;
            break;

        case MOD_EMAIL:
            sap_id = EMAIL_MMI_SAP;
            break;
        
        case MOD_IMPS:
            sap_id = IMPS_MMI_SAP;
            break;
         
        case MOD_POC:   
            sap_id = POC_MMI_SAP;
            break;
            
        case MOD_VOIP:
            sap_id = VOIP_MMI_SAP;
            break;
            
        case MOD_WNDRV:
            sap_id = WNDRV_MMI_SAP;
            break;

        case MOD_SUPC:
            sap_id = SUPC_MMI_SAP;
            break;
            
#ifdef __IPERF__
        case MOD_IPERF:
            sap_id = IPERF_MMI_SAP;
            break;
#endif /* __IPERF__ */            

        case MOD_BCHS:
            sap_id = BCHS_MMI_SAP;
            break;

        case MOD_DRMT:
            sap_id = DRMT_MMI_SAP;
            break;

        default:
             break;
    }

    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = sap_id;
    ilm_ptr->msg_id = MSG_ID_MMI_UT_ASYNC_TEST_END;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ut_async_test_end_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_async_test = MMI_FALSE;

    //mmi_ut_run_single_test(NULL, &g_run_summary);

    switch(g_run_type)
    {
        case MMI_UT_RUN_REGISTRY:        
            mmi_ut_run_single_registry(NULL, &g_run_summary);            
            break;
            
        case MMI_UT_RUN_SUITE:
            mmi_ut_run_single_suite(NULL, &g_run_summary);
            if (!g_is_async_test)
            {
                mmi_ut_post_run_single_registry(g_cur_registry_p, &g_run_summary);
            } 
            break;
            
        case MMI_UT_RUN_TEST:            
            mmi_ut_post_run_single_suite(g_cur_suite_p, &g_run_summary);
            mmi_ut_post_run_single_registry(g_cur_registry_p, &g_run_summary);             
            break;

        default:            
            MMI_ASSERT(0);
    }

    return;
    
}


#endif /* __MMI_TEST_FRAMEWORK__ */ 

