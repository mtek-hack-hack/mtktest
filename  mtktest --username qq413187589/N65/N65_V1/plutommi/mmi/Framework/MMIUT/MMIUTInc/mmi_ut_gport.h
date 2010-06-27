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
*  mmi_ut_gport.h
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
#ifndef MMI_UT_GPORT_H
#define MMI_UT_GPORT_H

#ifdef __MMI_TEST_FRAMEWORK__

/*****************************************************************************
 *
 *  MMI_UT Organization
 *  
 *****************************************************************************/

/*                        +-----------+
 *                        | Registry  |
 *                        +-----------+      
 *                              |
 *                +-------------+-------------+
 *                |                           |
 *                v                           v 
 *            +-------+                   +-------+
 *            | Suite |      .......      | Suite | 
 *            +-------+                   +-------+         
 *                |                           |
 *       +--------+--------+         +--------+--------+
 *       |        |        |         |        |        |
 *       v        v        v         v        v        v
 *   +------+          +------+  +------+          +------+ 
 *   | Test |  ......  | Test |  | Test |  ......  | Test | 
 *   +------+          +------+  +------+          +------+ 
 *
 */ 

/*  Type definition for Initialization/Cleaup/TestFunction */
typedef MMI_BOOL (*mmi_ut_pre_func) (void);         /* Signature for a pre-function. */
typedef MMI_BOOL (*mmi_ut_post_func) (void);        /* Signature for a post-function. */
typedef void     (*mmi_ut_test_func) (void);        /* Signature for a testing function in a test case. */
typedef MMI_BOOL (*mmi_ut_parse_command_func)(S8*); /* Signature for a command parsing function in the test registry. */

/* mmi_ut test case data type. */
typedef struct
{
    S8               *str_name;         /* Test name. */        
    mmi_ut_test_func test_func_p;       /* Pointer to the test function. */
    mmi_ut_pre_func  pre_func_p;        /* Pointer to the pre-function.  */
    mmi_ut_post_func post_func_p;       /* Pointer to the post-function. */
} mmi_ut_test_struct;

/* mmi_ut suite data type. */
typedef struct
{        
    S8                  *str_name;         /* Suite name. */
    mmi_ut_test_struct  *test_p;           /* Pointer to the 1st test in the suite. */
    U32                  number_of_tests;  /* Number of tests in the suite. */
    mmi_ut_pre_func      pre_func_p;       /* Pointer to the pre-function.  */
    mmi_ut_post_func     post_func_p;      /* Pointer to the post-function. */    
} mmi_ut_suite_struct;

/* mmi_ut test registry data type. */
typedef struct
{
    S8                       *str_name;            /* Registry name. */
    mmi_ut_suite_struct      *suite_p;             /* Pointer to the 1st suite in the test registry. */
    U32                       number_of_suites;    /* Number of suites in the test registry. */
    mmi_ut_parse_command_func parse_command_func_p;/* Pointer to the command parsing function. */
    mmi_ut_pre_func           pre_func_p;          /* Pointer to the pre-function.  */
    mmi_ut_post_func          post_func_p;         /* Pointer to the post-function. */
} mmi_ut_test_registry_struct;

/*****************************************************************************
*  mmi_ut error codes.
* If codes are added or removed, be sure to make a change to the
* error messages in mmi_ut_error.c/error_get_error_desc().
*****************************************************************************/
typedef enum 
{
    /* basic errors */
    MMI_UT_ERROR_CODE_SUCCESS,  /* No error condition. */
    MMI_UT_ERROR_CODE_NOMEMORY, /* Memory allocation failed. */

    /* Failure Record Errors */
    MMI_UT_ERROR_FAILURE_REC_OVERFLOW, /* The number of failure record has got max. */
   
    /* Test Registry Level Errors */   
    MMI_UT_ERROR_CODE_REGISTRY_OVERFLOW,         /* The number of registry has got maximum. */
    MMI_UT_ERROR_CODE_NO_REGISTRYNAME,           /* Registry name cannot be NULL. */
    MMI_UT_ERROR_CODE_DUP_REGISTRY,              /* Registry having name already registered. */
    MMI_UT_ERROR_CODE_NOREGISTRY,                /* Test registry does not exist. */
    MMI_UT_ERROR_CODE_REGISTRY_PRE_FUNC_FAILED,  /* Registry pre-function failed. */   
    MMI_UT_ERROR_CODE_REGISTRY_POST_FUNC_FAILED, /* Registry post-function failed. */  

    /* Test Suite Level Errors */
    MMI_UT_ERROR_CODE_NOSUITE,                /* NULL suite not allowed. */
    MMI_UT_ERROR_CODE_NO_SUITENAME,           /* Suite name cannot be NULL. */
    MMI_UT_ERROR_CODE_SUITE_PRE_FUNC_FAILED,  /* Suite pre-function failed. */   
    MMI_UT_ERROR_CODE_SUITE_POST_FUNC_FAILED, /* Suite post-function failed. */           
    MMI_UT_ERROR_CODE_DUP_SUITE,              /* Suite having name already registered. */
    MMI_UT_ERROR_CODE_SUITE_OVERFLOW,         /* The number of suites has alreay surpassed the maximum which can be displayed.*/

    /* Test Case Level Errors */
    MMI_UT_ERROR_CODE_NOTEST,                /* NULL test not allowed. */
    MMI_UT_ERROR_CODE_NO_TESTNAME,           /* Test name cannot be NULL. */
    MMI_UT_ERROR_CODE_TEST_PRE_FUNC_FAILED,  /* Test pre-function failed. */   
    MMI_UT_ERROR_CODE_TEST_POST_FUNC_FAILED, /* Test post-function failed. */                
    MMI_UT_ERROR_CODE_DUP_TEST,              /* Test having this name already in suite. */
    MMI_UT_ERROR_CODE_TEST_OVERFLOW,         /* The number of tests has alreay surpassed the maximum which can be displayed.*/
    MMI_UT_ERROR_CODE_TEST_NOT_IN_SUITE,     /* Test not registered in specified suite. */

    MMI_UT_ERROR_CODE_UNDEFINED              /*Undefined Error*/  
} mmi_ut_error_code_enum;

/* Shortcut macro for initialize an array of test case */
#define MMI_UT_CREATE_TEST_ARRAY_START(test_array)            const static mmi_ut_test_struct test_array[] = {
#define MMI_UT_ADD_TEST(name, test_func, pre_func, post_func)             {name, test_func, pre_func, post_func}
#define MMI_UT_ADD_TEST_WITH_DEFAULT_NAME(test_func, pre_func, post_func) {#test_func, test_func, pre_func, post_func}
#define MMI_UT_CREATE_TEST_ARRAY_END                           }; 

/* Shortcut macro for initialize an array of test suite */
#define MMI_UT_CREATE_SUITE_ARRAY_START(suite_array)           const static mmi_ut_suite_struct suite_array[] = {
#define MMI_UT_ADD_SUITE(name, test_arry, pre_func, post_func)             {name, test_arry, sizeof(test_arry)/sizeof(mmi_ut_test_struct), pre_func, post_func}
#define MMI_UT_ADD_SUITE_WITH_DEFAULT_NAME(test_arry, pre_func, post_func) {#test_arry, test_arry, sizeof(test_arry)/sizeof(mmi_ut_test_struct), pre_func, post_func}
#define MMI_UT_CREATE_SUITE_ARRAY_END                          };

/* Shortcut macro for initialize a test registry*/
#define LENGH(array) sizeof(array)/sizeof(array[0])
#define MMI_UT_CEARTE_REGISTRY(registry, name, suite_array, pars_func, pre_func, post_func) const static mmi_ut_test_registry_struct  registry = {name, suite_array, LENGH(suite_array), pars_func, pre_func, post_func}
                      

/* Public interface functions */
extern mmi_ut_error_code_enum mmi_ut_add_registry(mmi_ut_test_registry_struct *registry_p);
extern void mmi_ut_cleanup_registrys(void); 

/* Shortcut macro for check*/
#define MMI_UT_CHECK(value) \
   mmi_ut_check_implementation((value), __LINE__, #value, __FILE__, "", MMI_FALSE)

/* check implementation function. */
extern MMI_BOOL mmi_ut_check_implementation(
                                    MMI_BOOL value,
                                    U32 line,
                                    S8 str_condition[],
                                    S8 str_file[],
                                    S8 str_function[],
                                    MMI_BOOL fatal);

/* Public interface functions */
extern void mmi_ut_async_test_start(void);
extern void mmi_ut_async_test_end(void);

extern void mmi_ut_ui_entry_main_screen(void);

extern mmi_ut_error_code_enum mmi_ut_ui_run_all_tests(void);
extern mmi_ut_error_code_enum mmi_ut_ui_run_suite(mmi_ut_suite_struct *suite_p);
extern mmi_ut_error_code_enum mmi_ut_ui_run_test(mmi_ut_suite_struct *suite_p, mmi_ut_test_struct *test_p);

#endif /* __MMI_TEST_FRAMEWORK__ */

#endif /* MMI_UT_GPORT_H */ 

