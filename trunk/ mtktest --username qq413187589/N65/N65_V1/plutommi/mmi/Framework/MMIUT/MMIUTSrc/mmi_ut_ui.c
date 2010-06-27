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
 *  mmi_ut_ui.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  User Interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __MMI_TEST_FRAMEWORK__

#include "GlobalDefs.h"
#include "GlobalConstants.h"
#include "HistoryGprot.h"
#include "DebugInitDef.h"
#include "gui_data_types.h"
#include "CustMenuRes.h"

#include "mmi_ut_ui.h"

typedef enum
{
    MMI_UT_UI_START,
    MMI_UT_UI_RUNNING,
    MMI_UT_UI_END
} mmi_ut_ui_state_enum;


#define MMI_UT_UI_SUMMARY_ITEMS_NUM       12
#define MMI_UT_UI_SUMMARY_ITEM_STR_LEN    16
#define MMI_UT_UI_ELLIPSIS_STR_LEN        3   

extern const U16 gIndexIconsImageList[];

static mmi_ut_ui_state_enum g_run_state = MMI_UT_UI_START;    

static S32 g_suites_list_highlighted_item = 0;
static S32 g_tests_list_highlighted_item = 0;

/* Pointer to the currently running registry. */
static mmi_ut_test_registry_struct *g_running_registry_p = NULL;

/* Pointer to the currently running suite. */
static mmi_ut_suite_struct *g_running_suite_p = NULL;

/* Forward declaration of module functions */
static mmi_ut_error_code_enum mmi_ut_ui_initialize(void);

static void mmi_ut_ui_test_start_message_handler(const mmi_ut_test_struct *test_p, const mmi_ut_suite_struct *suite_p);
static void mmi_ut_ui_test_complete_message_handler(
                const mmi_ut_test_struct *test_p,
                const mmi_ut_suite_struct *suite_p,
                MMI_BOOL passed);
static void mmi_ut_ui_all_tests_complete_message_handler(void);
static void mmi_ut_ui_failure_message_handler(mmi_ut_failure_record_struct  *failure_record_p);

static S32 mmi_ut_ui_get_hint_func(S32 item_index, UI_string_type *hint_array);
static pBOOL mmi_ut_ui_get_item_handle(S32 item_index, UI_string_type str_buff, U8 **img_buff_p, U8 str_img_mask);
static void mmi_ut_ui_suites_list_highlight_hdlr(S32 index);
static void mmi_ut_ui_suites_left_soft_key_hdlr(void);
static void mmi_ut_ui_tests_list_highlight_hdlr(S32 index);
static void mmi_ut_ui_tests_left_soft_key_hdlr(void);
static void mmi_ut_ui_entry_tests_list_screen(void);
static void mmi_ut_ui_entry_summary_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_entry_main_screen
 * DESCRIPTION
 *  The entry function of mmi_ut main screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ut_ui_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *gui_buffer;
    S32 suite_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != g_running_registry_p);
    EntryNewScreen(SCR_MMI_UT_UI_SUITES_LIST_ID, NULL, mmi_ut_ui_entry_main_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_MMI_UT_UI_SUITES_LIST_ID);

    RegisterHighlightHandler(mmi_ut_ui_suites_list_highlight_hdlr);

    if (g_running_registry_p->number_of_suites <  MMI_UT_UI_LIST_MAXIMUM)
    {
        suite_num = g_running_registry_p->number_of_suites + 1; 
    }
    else
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_SUITE_OVERFLOW);
        suite_num = MMI_UT_UI_LIST_MAXIMUM;
    }
    

    ShowCategory184Screen(
        STR_MMI_UT_UI_TITLE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        suite_num,
        mmi_ut_ui_get_item_handle,
        mmi_ut_ui_get_hint_func,
        0,
        gui_buffer);
  
    SetLeftSoftkeyFunction(mmi_ut_ui_suites_left_soft_key_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_get_item_handle
 * DESCRIPTION
 *  Callback function for get the list of items.
 * PARAMETERS
 *  item_index          [IN]    Item index      
 *  str_buff            [IN]    String buffer    
 *  img_buff_p          [IN]    Image buffer     
 *  str_img_mask        [IN]    String image mask
 * RETURNS
 *  Always returns MMI_TURE
 *****************************************************************************/
static pBOOL mmi_ut_ui_get_item_handle(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == 0)
    {
        mmi_ucs2cpy((S8 *)str_buff, GetString(STR_MMI_UT_RUN_ALL_TESTS));
    }
    else
    {
        if ((MAX_SUB_MENU_SIZE - ENCODING_LENGTH) < mmi_ucs2strlen((S8 *)g_running_registry_p->suite_p[item_index].str_name)*ENCODING_LENGTH)
        {
            mmi_ucs2ncpy((S8 *)str_buff, (S8 *)g_running_registry_p->suite_p[item_index].str_name, 
                MAX_SUB_MENU_SIZE - ENCODING_LENGTH - MMI_UT_UI_ELLIPSIS_STR_LEN*ENCODING_LENGTH);
            mmi_ucs2cat((S8 *)str_buff, GetString(STR_MMI_UT_ELLIPSIS));
        }
        else
        {
            mmi_ucs2cpy((S8 *)str_buff, (S8 *)g_running_registry_p->suite_p[item_index].str_name);
        }    
    }

    /* show order icon */
    *img_buff_p = (U8 *)GetImage(gIndexIconsImageList[item_index]);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_get_hint_func
 * DESCRIPTION
 *  Callback function for get the hint item.
 * PARAMETERS
 *  item_index      [IN]  the hint item index      
 *  hint_array      [IN]  the hint item buffer       
 * RETURNS
 *  Always return 1.
 *****************************************************************************/
static S32 mmi_ut_ui_get_hint_func(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == 0)
    {
        kal_wsprintf(hint_array[0], "%d Cases", g_running_suite_p->number_of_tests);
    }
    else
    {        
        kal_wsprintf(hint_array[0], "%d Cases", g_running_registry_p->suite_p[item_index-1].number_of_tests);
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_suites_list_highlight_hdlr
 * DESCRIPTION
 *  The handler of the suites list highlight .
 * PARAMETERS
 *  index       [IN]   the index of the suite list.      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_suites_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_suites_list_highlighted_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_tests_list_highlight_hdlr
 * DESCRIPTION
 *  The handler of the tests list highlight .
 * PARAMETERS
 *  index       [IN]  the index of rthe test list.      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_tests_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_tests_list_highlighted_item = index;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_suites_left_soft_key_hdlr
 * DESCRIPTION
 *  The left soft key handler of the suites list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_suites_left_soft_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == g_suites_list_highlighted_item)
    {
        mmi_ut_ui_run_all_tests();
    }
    else
    {
        mmi_ut_ui_entry_tests_list_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_tests_left_soft_key_hdlr
 * DESCRIPTION
 *  The left soft key handler of the tests list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_tests_left_soft_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == g_tests_list_highlighted_item)
    {
        mmi_ut_ui_run_suite(&g_running_registry_p->suite_p[g_suites_list_highlighted_item - 1]);
    }
    else
    {        
        mmi_ut_ui_run_test(&g_running_registry_p->suite_p[g_suites_list_highlighted_item - 1],
                           &g_running_registry_p->suite_p[g_suites_list_highlighted_item - 1].test_p[g_tests_list_highlighted_item - 1]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_entry_tests_list_screen
 * DESCRIPTION
 *  The entry function of the tests list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_entry_tests_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 item_num, i;
    U16 *list_of_test_items_p[MMI_UT_UI_LIST_MAXIMUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_of_test_items_p[0] = (U16*)GetString(STR_MMI_UT_RUN_ALL_TESTS);

    if (g_running_registry_p->suite_p[g_suites_list_highlighted_item - 1].number_of_tests < MMI_UT_UI_LIST_MAXIMUM)
    {
        item_num = g_running_registry_p->suite_p[g_suites_list_highlighted_item - 1].number_of_tests + 1;
    }
    else
    {
        mmi_ut_set_error(MMI_UT_ERROR_CODE_TEST_OVERFLOW);
        item_num = MMI_UT_UI_LIST_MAXIMUM;
    }
    
    for (i = 1; i < item_num; i++)
    {
        list_of_test_items_p[i] = (U16*)g_running_registry_p->suite_p[g_suites_list_highlighted_item - 1].test_p[i].str_name;        
    }

    EntryNewScreen(SCR_MMI_UT_UI_TESTS_LIST_ID, NULL, mmi_ut_ui_entry_tests_list_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MMI_UT_UI_TESTS_LIST_ID);

    RegisterHighlightHandler(mmi_ut_ui_tests_list_highlight_hdlr);

    ShowCategory84Screen(
        STR_MMI_UT_UI_TITLE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_num,
        (U8 **) list_of_test_items_p,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_ut_ui_tests_left_soft_key_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_entry_summary_screen
 * DESCRIPTION
 *  the entry function of the summary screen. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_entry_summary_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_run_summary_struct *run_summary_p = mmi_ut_get_run_summary();
    U16 *list_of_summary_items1[MMI_UT_UI_SUMMARY_ITEMS_NUM];
    U16  list_of_summary_items2[MMI_UT_UI_SUMMARY_ITEMS_NUM][MMI_UT_UI_SUMMARY_ITEM_STR_LEN];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_of_summary_items1[0]  = (U16 *)GetString(STR_MMI_UT_SUITES_TOTAL);  /*Suites Total*/    
    list_of_summary_items1[1]  = (U16 *)GetString(STR_MMI_UT_SUITES_RAN);    /*Suites Ran*/    
    list_of_summary_items1[2]  = (U16 *)GetString(STR_MMI_UT_SUITES_PASSED); /*Suites Passed*/
    list_of_summary_items1[3]  = (U16 *)GetString(STR_MMI_UT_SUITES_FAILED); /*Suites Failed*/ 
    list_of_summary_items1[4]  = (U16 *)GetString(STR_MMI_UT_TEST_TOTAL);    /*Tests Total*/
    list_of_summary_items1[5]  = (U16 *)GetString(STR_MMI_UT_TEST_RAN);      /*Tests Ran*/
    list_of_summary_items1[6]  = (U16 *)GetString(STR_MMI_UT_TESTS_PASSED);  /*Tests Passed*/ 
    list_of_summary_items1[7]  = (U16 *)GetString(STR_MMI_UT_TESTS_FAILED);  /*Tests Failed*/   
    list_of_summary_items1[8]  = (U16 *)GetString(STR_MMI_UT_CHECKS_TOTAL);  /*Checks Total*/    
    list_of_summary_items1[9]  = (U16 *)GetString(STR_MMI_UT_CHECKS_RAN);    /*Checks Ran*/
    list_of_summary_items1[10] = (U16 *)GetString(STR_MMI_UT_CHECKS_PASSED); /*Checks Passed*/ 
    list_of_summary_items1[11] = (U16 *)GetString(STR_MMI_UT_CHECKS_FAILED); /*Checks Failed*/
        
    kal_wsprintf(list_of_summary_items2[0], "%d", g_running_registry_p->number_of_suites);
    kal_wsprintf(list_of_summary_items2[1], "%d", run_summary_p->suites_run);
    kal_wsprintf(list_of_summary_items2[2], "n/a");
    kal_wsprintf(list_of_summary_items2[3], "%d", run_summary_p->suites_failed);
    kal_wsprintf(list_of_summary_items2[4], "%d", g_running_suite_p->number_of_tests);
    kal_wsprintf(list_of_summary_items2[5], "%d", run_summary_p->tests_run);
    kal_wsprintf(list_of_summary_items2[6], "%d", run_summary_p->tests_run - run_summary_p->tests_failed);
    kal_wsprintf(list_of_summary_items2[7], "%d", run_summary_p->tests_failed);
    kal_wsprintf(list_of_summary_items2[8], "%d", run_summary_p->checks);
    kal_wsprintf(list_of_summary_items2[9], "%d", run_summary_p->checks);
    kal_wsprintf(list_of_summary_items2[10], "%d", run_summary_p->checks - run_summary_p->checks_failed);
    kal_wsprintf(list_of_summary_items2[11], "%d", run_summary_p->checks_failed);


    EntryNewScreen(SCR_MMI_UT_UI_RESULT_ID, NULL, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_MMI_UT_UI_RESULT_ID);

    ShowCategory153Screen(
        STR_MMI_UT_UI_TITLE,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_UT_UI_SUMMARY_ITEMS_NUM,
        (U8 **)list_of_summary_items1,
        (U8 **)list_of_summary_items2,
        0,
        guiBuffer);    

    /* go back to game menu */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_run_all_tests
 * DESCRIPTION
 *  Run all registered mmi_ut tests.
 *  The default mmi_ut_ui_run_mode_enum is used unless it has been
 *  previously changed using mmi_ut_ui_set_mode().  The mmi_ut test
 *  registry must have been initialized before calling this function.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ut_error_code_enum indicating the framework error condition, including
 *  MMI_UT_ERROR_CODE_NOREGISTRY - Registry has not been initialized.
 *****************************************************************************/
mmi_ut_error_code_enum mmi_ut_ui_run_all_tests(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_running_suite_p)
    {        
        error = MMI_UT_ERROR_CODE_NOREGISTRY;
        mmi_ut_set_error(error);
    }
    else if (MMI_UT_ERROR_CODE_SUCCESS == (error = mmi_ut_ui_initialize()))
    {        
        g_running_suite_p = NULL;
        g_run_state = MMI_UT_UI_RUNNING;

        error = mmi_ut_run_registry(g_running_registry_p);
    }

    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_mmi_ut_ui_run_suite
 * DESCRIPTION
 *  Run all tests for a specific suite.
 *  If suite_p is NULL, the function returns without taking any
 *  action. The default mmi_ut_ui_run_mode_enum is used unless it has
 *  been changed using mmi_ut_ui_set_mode().
 * PARAMETERS
 *  suite_p     [IN]        The mmi_ut_suite to run.
 * RETURNS
 *  A mmi_ut_error_code_enum indicating the framework error condition, including
 *  MMI_UT_ERROR_CODE_NOSUITE - suite_p was NULL.
 *****************************************************************************/
mmi_ut_error_code_enum mmi_ut_ui_run_suite(mmi_ut_suite_struct *suite_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);
    
    if (NULL == suite_p)
    {
        error = MMI_UT_ERROR_CODE_NOSUITE;
        mmi_ut_set_error(error);
    }
    else if (MMI_UT_ERROR_CODE_SUCCESS == (error = mmi_ut_ui_initialize()))
    {
        g_running_suite_p = NULL;
        error =  mmi_ut_run_suite(g_running_registry_p, suite_p);
    }
    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_run_test
 * DESCRIPTION
 *  Run a single test in a specific suite.
 *  If suite_p or test_p is NULL, the function returns without
 *  taking any action.  The default mmi_ut_ui_run_mode_enum is used unless
 *  it has been changed using mmi_ut_ui_set_mode.
 * PARAMETERS
 *  suite_p     [IN]        The mmi_ut_suite holding the mmi_ut_test to run.
 *  test_p      [IN]        The mmi_ut_test to run.
 * RETURNS
 *  A mmi_ut_error_code_enum indicating the framework error condition, including
 *  MMI_UT_ERROR_CODE_NOSUITE - suite_p was NULL.
 *  MMI_UT_ERROR_CODE_NOTEST  - test_p was NULL.
 *****************************************************************************/
mmi_ut_error_code_enum mmi_ut_ui_run_test(mmi_ut_suite_struct *suite_p, mmi_ut_test_struct *test_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_error_code_enum error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);
    
    if (NULL == suite_p)
    {
        error = MMI_UT_ERROR_CODE_NOSUITE;
        mmi_ut_set_error(error);
    }
    else if (NULL == test_p)
    {
        error = MMI_UT_ERROR_CODE_NOTEST;
        mmi_ut_set_error(error);
    }
    else if (MMI_UT_ERROR_CODE_SUCCESS == (error = mmi_ut_ui_initialize()))
    {
        g_running_suite_p = NULL;
        return mmi_ut_run_test(g_running_registry_p, suite_p, test_p);
    }

    return error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_initialize
 * DESCRIPTION
 *  Perform inialization actions.
 *  This includes setting output to unbuffered, printing a
 *  welcome message, and setting the test run handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  An error code indicating the framework error condition.
 *****************************************************************************/
static mmi_ut_error_code_enum mmi_ut_ui_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ut_set_error(MMI_UT_ERROR_CODE_SUCCESS);
    MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_INITIALIZE);;
    
    mmi_ut_set_test_start_handler(mmi_ut_ui_test_start_message_handler);
    mmi_ut_set_test_complete_handler(mmi_ut_ui_test_complete_message_handler);
    mmi_ut_set_all_test_complete_handler(mmi_ut_ui_all_tests_complete_message_handler);
    mmi_ut_set_failure_message_handler(mmi_ut_ui_failure_message_handler);
   
    return mmi_ut_get_error();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_test_start_message_handler
 * DESCRIPTION
 *  Handler function called at start of each test.
 * PARAMETERS
 *  test_p      [IN]        The test being run.
 *  suite_p     [IN]        The suite containing the test.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_test_start_message_handler(const mmi_ut_test_struct *test_p, const mmi_ut_suite_struct *suite_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_suite_name[MMI_UT_SUITE_NAME_LENGTH + 1] = {0};
    S8 str_test_name[MMI_UT_TEST_NAME_LENGTH   + 1] = {0}; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != suite_p);
    MMI_ASSERT(NULL != test_p);

    if (NULL != suite_p->str_name)
    {
        mmi_ucs2_n_to_asc(str_suite_name, suite_p->str_name, MMI_UT_SUITE_NAME_LENGTH);
    }
    if (NULL != test_p->str_name)
    {
        mmi_ucs2_n_to_asc(str_test_name, test_p->str_name, MMI_UT_SUITE_NAME_LENGTH);
    }

    if ((NULL == g_running_suite_p) || (g_running_suite_p != suite_p))
    {
        Trace2(MMI_UT_TRACE_GROUP, "[MMI_UT]Suite: %s", str_suite_name);
        Trace2(MMI_UT_TRACE_GROUP, "[MMI_UT]Test: %s", str_test_name);
        g_running_suite_p = (mmi_ut_suite_struct *)suite_p;
    }
    else
    {
        Trace2(MMI_UT_TRACE_GROUP, "[MMI_UT]Test: %s", str_test_name);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_test_complete_message_handler
 * DESCRIPTION
 *  Handler function called at completion of each test.
 * PARAMETERS
 *  test_p              [IN]        The test being run.
 *  suite_p             [IN]        The suite containing the test.
 *  passed              [IN]        the test passed or not.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_test_complete_message_handler(
                const mmi_ut_test_struct *test_p,
                const mmi_ut_suite_struct *suite_p,
                MMI_BOOL passed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_suite_name[MMI_UT_SUITE_NAME_LENGTH + 1] = {0};
    S8 str_test_name[MMI_UT_TEST_NAME_LENGTH   + 1] = {0}; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != suite_p);
    MMI_ASSERT(NULL != test_p);

    if (NULL != suite_p->str_name)
    {
        mmi_ucs2_n_to_asc(str_suite_name, suite_p->str_name, MMI_UT_SUITE_NAME_LENGTH);
    }

    if (NULL != test_p->str_name)
    {
        mmi_ucs2_n_to_asc(str_test_name, test_p->str_name, MMI_UT_SUITE_NAME_LENGTH);
    }

    if (passed)
    {
       
        MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_PASSED);
        
    }
    else
    {
        Trace2(MMI_UT_TRACE_GROUP, "[MMI_UT]Suite %s, Test %s had failures:",
                                   str_test_name, str_test_name);
                
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_all_tests_complete_message_handler
 * DESCRIPTION
 *  Handler function called at completion of all tests in a suite.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_all_tests_complete_message_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ut_run_summary_struct *run_summary_p = mmi_ut_get_run_summary();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != run_summary_p);
    MMI_ASSERT(NULL != g_running_suite_p);

    MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_RUN_SUMMARY);
    MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_SUITES_SUMMARY,
        g_running_registry_p->number_of_suites, run_summary_p->suites_run, run_summary_p->suites_failed);
    MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_CASES_SUMMARY,
        g_running_suite_p->number_of_tests,
        run_summary_p->tests_run,
        run_summary_p->tests_run - run_summary_p->tests_failed, 
        run_summary_p->tests_failed);
    MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_CHECKS_SUMMARY,
        run_summary_p->checks,
        run_summary_p->checks,
        run_summary_p->checks - run_summary_p->checks_failed, run_summary_p->checks_failed);

    mmi_ut_ui_entry_summary_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ut_ui_all_tests_complete_message_handler
 * DESCRIPTION
 *  Handler function called at occurs a failure.
 * PARAMETERS
 *  failure_record_p       [IN]        Pointer to the test failure record.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ut_ui_failure_message_handler(mmi_ut_failure_record_struct  *failure_record_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_suite_name[MMI_UT_SUITE_NAME_LENGTH + 1] = {0};
    S8 str_test_name[MMI_UT_TEST_NAME_LENGTH   + 1] = {0}; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_UT_TRACE_GROUP, MMI_UT_TRC_FAILED);

    if (NULL != failure_record_p->suite_p->str_name)
    {
        mmi_ucs2_n_to_asc(str_suite_name, failure_record_p->suite_p->str_name, MMI_UT_SUITE_NAME_LENGTH);
    }

    if (NULL != failure_record_p->test_p->str_name)
    {
        mmi_ucs2_n_to_asc(str_test_name, failure_record_p->test_p->str_name, MMI_UT_SUITE_NAME_LENGTH);
    }

    Trace2(MMI_UT_TRACE_GROUP, "[MMI_UT] Suite %s, Test %s had failures:", str_suite_name, str_test_name);
        
    Trace2(MMI_UT_TRACE_GROUP, "[MMI_UT] File: %s", 
        (NULL != failure_record_p->str_file_name) ? failure_record_p->str_file_name : "");
    Trace2(MMI_UT_TRACE_GROUP, "[MMI_UT] Line: %d", failure_record_p->line_number);
    Trace2(MMI_UT_TRACE_GROUP, "[MMI_UT] Condition: %s", 
         (NULL != failure_record_p->str_condition) ? failure_record_p->str_condition : "");
  
}

#endif /* __MMI_TEST_FRAMEWORK__ */

