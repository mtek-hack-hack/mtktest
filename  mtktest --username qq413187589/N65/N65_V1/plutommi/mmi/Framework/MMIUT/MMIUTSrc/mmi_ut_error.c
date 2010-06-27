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
*  mmi_ut_error.c
*
* Project:
* -------- 
*  MAUI
*
* Description:
* ------------
*  Error handling functions (implementation).
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
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifdef __MMI_TEST_FRAMEWORK__

#include "mmi_ut_error.h"

/*
 * Global/Static Definitions
 */
/** Local variable holding the current error code. */
static mmi_ut_error_code_enum error_number_g = MMI_UT_ERROR_CODE_SUCCESS;

/** Local variable holding the current error action code. */
static mmi_ut_error_action_enum error_action_g = MMI_UT_ERROR_ACTION_IGNORE;

/* Private function forward declarations */
static void print_error_desc(mmi_ut_error_code_enum error);


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_set_error
 * DESCRIPTION
 *  Set the error code.
 *  This function is used internally by mmi_ut implementation functions
 *  when an error condition occurs within the framework.  It should
 *  not generally be called by user code.  NOTE that if the current
 *  error action is MMI_UT_ERROR_ACTION_ABORT, then calling this function will
 *  result in MMI_ASSERT(0) being called for the current application.
 * PARAMETERS
 *  error       [IN]        mmi_ut_error_code_enum indicating the current error condition.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ut_set_error(mmi_ut_error_code_enum error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != MMI_UT_ERROR_CODE_SUCCESS)
    {        
        print_error_desc(error);
        if (error_action_g == MMI_UT_ERROR_ACTION_ABORT)
        {
            MMI_ASSERT(0);            
        }        
    }

    error_number_g = error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_error
 * DESCRIPTION
 *  Get the error code.
 *  mmi_ut implementation functions set the error code to indicate the
 *  status of the most recent operation.  In general, the mmi_ut functions
 *  will clear the code to MMI_UT_ERROR_CODE_SUCCESS, then reset it to a specific error
 *  code if an exception condition is encountered.  Some functions
 *  return the code, others leave it to the user to inspect if desired.
 * PARAMETERS
 *  void
 * RETURNS
 *  The current error condition code.
 *****************************************************************************/
mmi_ut_error_code_enum mmi_ut_get_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return error_number_g;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_error_msg
 * DESCRIPTION
 *  Print the message corresponding to the error code.
 *  mmi_ut implementation functions set the error code to indicate the
 *  of the most recent operation.  In general, the mmi_ut functions will
 *  clear the code to MMI_UT_ERROR_CODE_SUCCESS, then reset it to a specific error
 *  code if an exception condition is encountered.  This function allows
 *  the user to retrieve a descriptive error message corresponding to the
 *  error code set by the last operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  return A message corresponding to the current error condition.
 *****************************************************************************/
void mmi_ut_get_error_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    print_error_desc(error_number_g);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_set_error_action
 * DESCRIPTION
 *  Set the action to take when an error condition occurs.
 *  This function should be used to specify the action to take
 *  when an error condition is encountered.  The default action is
 *  MMI_UT_ERROR_ACTION_IGNORE, which results in errors being ignored and test runs
 *  being continued (if possible).  A value of MMI_UT_ERROR_ACTION_FAIL causes test
 *  runs to stop as soon as an error condition occurs.
 * PARAMETERS
 *  action      [IN]        mmi_ut_error_action_enum indicating the new error action.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ut_set_error_action(mmi_ut_error_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_action_g = action;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_error_action
 * DESCRIPTION
 *  Get the current error action code.
 * PARAMETERS
 *  void
 * RETURNS
 *  return The current error action code.
 *****************************************************************************/
mmi_ut_error_action_enum mmi_ut_get_error_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return error_action_g;
}

/*
 * Private static function definitions
 */


/*****************************************************************************
 * FUNCTION
 *  print_error_desc
 * DESCRIPTION
 *  Internal function to look up the error message for a specified
 *  error code.  An empty string is returned if error is not a member
 *  of mmi_ut_error_code_enum.
 * PARAMETERS
 *  error       [IN]        mmi_ut_error_code_enum to look up.
 * RETURNS
 *  return Pointer to a string containing the error message.
 *****************************************************************************/
static void print_error_desc(mmi_ut_error_code_enum error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(error)
    {
        /* basic errors */       
        case MMI_UT_ERROR_CODE_NOMEMORY: /* Memory allocation failed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_NOMEMORY);
            break;

        /* Failure Record Errors */
          case MMI_UT_ERROR_FAILURE_REC_OVERFLOW: /* The number of failure record has got max. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_FAILURE_REC_OVERFLOW);
            break;

        /* Test Registry Level Errors */   
        case MMI_UT_ERROR_CODE_REGISTRY_OVERFLOW: /* The number of registry has got max. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_REGISTRY_OVERFLOW);
            break;

        case MMI_UT_ERROR_CODE_NO_REGISTRYNAME: /* Registry name cannot be NULL. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_NO_REGISTRYNAME);
            break;
            
        case MMI_UT_ERROR_CODE_DUP_REGISTRY: /* Registry having name already registered. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_DUP_REGISTRY);
            break;
            
        case MMI_UT_ERROR_CODE_NOREGISTRY: /* Test registry does not exist. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_NOREGISTRY);
            break;

        case MMI_UT_ERROR_CODE_REGISTRY_PRE_FUNC_FAILED:  /* Registry pre-function failed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_REGISTRY_PRE_FUNC_FAILED);
            break;
            
        case MMI_UT_ERROR_CODE_REGISTRY_POST_FUNC_FAILED: /* Registry post-function failed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_REGISTRY_POST_FUNC_FAILED);
            break;

        /* Test Suite Level Errors */
        case MMI_UT_ERROR_CODE_NOSUITE: /* NULL suite not allowed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_NOSUITE);
            break;

        case MMI_UT_ERROR_CODE_NO_SUITENAME: /* Test name cannot be NULL. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_NO_SUITENAME);
            break;

        case MMI_UT_ERROR_CODE_SUITE_PRE_FUNC_FAILED: /* Suite pre-function failed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_SUITE_PRE_FUNC_FAILED);
            break;
        
        case MMI_UT_ERROR_CODE_SUITE_POST_FUNC_FAILED: /* Suite post-function failed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_SUITE_POST_FUNC_FAILED);
            break;

        case MMI_UT_ERROR_CODE_DUP_SUITE: /* Suite having name already registered. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_DUP_SUITE);
            break;

        case MMI_UT_ERROR_CODE_SUITE_OVERFLOW:/* The number of suites has alreay surpassed the maximum which can be displayed.*/
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_SUITE_OVERFLOW);
            break;

        /* Test Case Level Errors */
        case MMI_UT_ERROR_CODE_NOTEST: /* NULL test not allowed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_NOTEST);
            break;

        case MMI_UT_ERROR_CODE_NO_TESTNAME: /* Test name cannot be NULL. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_NO_TESTNAME);
            break;
        
        case MMI_UT_ERROR_CODE_TEST_PRE_FUNC_FAILED: /* Test pre-function failed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_TEST_PRE_FUNC_FAILED);
            break;
        
        case MMI_UT_ERROR_CODE_TEST_POST_FUNC_FAILED: /* Test post-function failed. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_TEST_POST_FUNC_FAILED);
            break;
        
        case MMI_UT_ERROR_CODE_DUP_TEST: /* Test having this name already in suite. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_DUP_TEST);
            break;

        case MMI_UT_ERROR_CODE_TEST_OVERFLOW: /* The number of test has alreay surpassed the maximum which can be displayed.*/
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_TEST_OVERFLOW);
            break;

        case  MMI_UT_ERROR_CODE_TEST_NOT_IN_SUITE: /* Test not registered in specified suite. */
            MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_ERROR_CODE_TEST_NOT_IN_SUITE);

        default:
            break;        
    }
    
}

#endif /* __MMI_TEST_FRAMEWORK__ */

