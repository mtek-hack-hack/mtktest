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
 *  mmi_ut_db.c
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

#include "mmi_ut_db.h"

/*
 *  Global/Static Definitions
 */
static mmi_ut_test_registry_struct* g_test_registry_array[MMI_UT_REGISTRY_MAX_NUM] = {0};   /* The active internal Test Registry. */
static U16  g_test_registry_curr_num = 0;                      


/*
 * Private function forward declarations
 */
static void mmi_ut_validate_registry(mmi_ut_test_registry_struct *registry_p);


/*
 *  Public Interface functions
 */
/*****************************************************************************
 * FUNCTION
 *  mmi_ut_add_registry
 * DESCRIPTION
 *  Add the registry to mmi_test_registry_array[].
 * PARAMETERS
 *  registry_p      [IN]        An existing mmi_ut_test_registry_struct* instance
 * RETURNS
 *  return  MMI_UT_ERROR_CODE_REGISTRY_OVERFLOW if the existed registrys have got max number,
 *  MMI_UT_ERROR_CODE_SUCCESS otherwise.
 *****************************************************************************/
mmi_ut_error_code_enum mmi_ut_add_registry(mmi_ut_test_registry_struct *registry_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum error = MMI_UT_ERROR_CODE_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(MMI_FALSE == mmi_ut_is_test_running());

    mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);

    if (g_test_registry_curr_num < MMI_UT_REGISTRY_MAX_NUM)
    {
        g_test_registry_array[g_test_registry_curr_num] =  registry_p;
        g_test_registry_curr_num++; 
    }
    else 
    {
        error = MMI_UT_ERROR_CODE_REGISTRY_OVERFLOW;
        mmi_ut_set_error(MMI_UT_ERROR_CODE_REGISTRY_OVERFLOW);
    }
    
    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_cleanup_registry
 * DESCRIPTION
 *  Clear all registered test registry.
 *  This function may be called multiple times without generating an
 *  error condition.  However, this function must not be called during
 *  a test run (checked by assertion).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ut_cleanup_registrys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(MMI_FALSE == mmi_ut_is_test_running());

    mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);

    if (0 != g_test_registry_curr_num)
    {
        memset(g_test_registry_array, 0, g_test_registry_curr_num);
        g_test_registry_curr_num = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_registry_by_name
 * DESCRIPTION
 *  Retrieve a pointer to the registry having the specified name.
 *  Scans the g_test_registry_array[] and returns a pointer to the first
 *  suite located having the specified name.
 * PARAMETERS
 *  str_registry_name      [IN]        The name of the registry to locate.
 * RETURNS
 *  Pointer to the first registry having the specified name, NULL if not found.
 *****************************************************************************/
mmi_ut_test_registry_struct *mmi_ut_get_registry_by_name(const S8 *str_registry_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_test_registry_struct *test_registry_p = NULL;
    S32                          index           = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (index < g_test_registry_curr_num)
    {
        if ((NULL != g_test_registry_array[index]->str_name) 
            && (0 == strcmp(g_test_registry_array[index]->str_name, str_registry_name)))
        {
            test_registry_p = g_test_registry_array[index];
            break;
        }
        index++;
    }
    
    return test_registry_p;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_suite_by_name
 * DESCRIPTION
 *  Retrieve a pointer to the suite having the specified name.
 *  Scans the registry_p and returns a pointer to the first
 *  suite located having the specified name.
 * PARAMETERS
 *  str_suite_name      [IN]        The name of the suite to locate.
 *  registry_p          [IN]        The registry to scan.
 * RETURNS
 *  Pointer to the first suite having the specified name, NULL if not found.
 *****************************************************************************/
mmi_ut_suite_struct *mmi_ut_get_suite_by_name(const S8 *str_suite_name, mmi_ut_test_registry_struct *registry_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_suite_struct *suite_p = NULL;
    S32                  index   = 0;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != registry_p);
    MMI_ASSERT(NULL != str_suite_name);
    
    while (index < registry_p->number_of_suites)
    {
        if ((NULL != registry_p->suite_p[index].str_name) 
            && (0 == strcmp(registry_p->suite_p[index].str_name, str_suite_name)))
        {
            suite_p = &(registry_p->suite_p[index]);
            break;
        }
        index++;
    }

    return suite_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_get_test_by_name
 * DESCRIPTION
 *  Retrieve a pointer to the test case having the specified name.
 *  Scans the suite_p and returns a pointer to the first
 *  test case located having the specified name.
 * PARAMETERS
 *  str_test_name       [IN]        The name of the test case to locate.
 *  suite_p             [IN]        The suite to scan.
 * RETURNS
 *  Pointer to the first test case having the specified name, NULL if not found.
 *****************************************************************************/
mmi_ut_test_struct *mmi_ut_get_test_by_name(const S8 *str_test_name, mmi_ut_suite_struct *suite_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_test_struct *test_p = NULL;
    S32                 index  = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != suite_p);
    MMI_ASSERT(NULL != str_test_name);
    
    while (index < suite_p->number_of_tests)
    {
        if ((NULL != suite_p->test_p[index].str_name) 
           && (0 == strcmp(suite_p->test_p[index].str_name, str_test_name)))
        {
            test_p = &(suite_p->test_p[index]);
            break;
        }
        index++;
    }

    return test_p;
}

/*
 *  Private static function definitions
 */
/*****************************************************************************
 * FUNCTION
 *  mmi_ut_validate_registry
 * DESCRIPTION
 *  Check the test registry's validity.
 * PARAMETERS
 *  registry_p  [IN] the test registry which want to been validated.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_validate_registry(mmi_ut_test_registry_struct *registry_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 registry_ind = 0, suite_ind = 0, test_ind = 0, temp_ind = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != registry_p)
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_NOREGISTRY);
        MMI_ASSERT(NULL != registry_p);
    }

    if (NULL != registry_p->str_name)
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_NO_REGISTRYNAME);
    }
    
    while (registry_ind < g_test_registry_curr_num)
    {
        if ((NULL != g_test_registry_array[registry_ind]->str_name)&&
            (0 == strcmp(registry_p->str_name, 
                         g_test_registry_array[registry_ind]->str_name)))
        {
            mmi_ut_set_error(MMI_UT_ERROR_CODE_DUP_REGISTRY);
        }
        registry_ind++;
    }

    while (suite_ind < registry_p->number_of_suites)
    {
        if (NULL == registry_p->suite_p[suite_ind].str_name)
        {
            mmi_ut_set_error(MMI_UT_ERROR_CODE_NO_SUITENAME);
        }
        else
        {
            temp_ind = suite_ind + 1;
            while (temp_ind < registry_p->number_of_suites)
            {
                if ((NULL != registry_p->suite_p[temp_ind].str_name)&&
                    (0 == strcmp(registry_p->suite_p[suite_ind].str_name, 
                                 registry_p->suite_p[temp_ind].str_name)))
                {
                     mmi_ut_set_error(MMI_UT_ERROR_CODE_DUP_SUITE);
                }
            }
        }

        test_ind = 0;

        while (test_ind < registry_p->suite_p[suite_ind].number_of_tests)
        {
            if (NULL == registry_p->suite_p[suite_ind].test_p[test_ind].str_name)
            {
                mmi_ut_set_error(MMI_UT_ERROR_CODE_NO_TESTNAME);
            }
            else
            {
                temp_ind = test_ind + 1;
                while (temp_ind < registry_p->suite_p[suite_ind].number_of_tests)
                {
                    if ((NULL != registry_p->suite_p[suite_ind].test_p[temp_ind].str_name)&&
                        (0 == strcmp(registry_p->suite_p[suite_ind].test_p[test_ind].str_name, 
                                     registry_p->suite_p[suite_ind].test_p[temp_ind].str_name)))
                    {
                        mmi_ut_set_error(MMI_UT_ERROR_CODE_DUP_TEST);
                    }
                }
            }
            test_ind++;            
        }
        suite_ind++;        
    }    

    return;
}

#endif /* __MMI_TEST_FRAMEWORK__ */

