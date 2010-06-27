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
 * PhoneBookSearch.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sorting, search, quick search function in Phonebook application
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
#include "MMI_include.h"
#ifndef _PHONEBOOKSEARCH_C
#define _PHONEBOOKSEARCH_C


#if defined(__MMI_T9__)
#include "T9api.h"
#include "T9Main.h"
#endif /* defined(__MMI_T9__) */ 

#if defined(__MMI_ZI__)
#include "Zi8api.h"

#ifndef ZI8_GETMODE_BOPOMOFO_NAME
#define ZI8_GETMODE_BOPOMOFO_NAME ZI8_GETMODE_BOPOMOFO
#endif 

#ifndef ZI8_GETMODE_PINYIN_NAME
#define ZI8_GETMODE_PINYIN_NAME ZI8_GETMODE_PINYIN
#endif 

#endif /* defined(__MMI_ZI__) */ 

#if defined(__MMI_CSTAR__)
#include "CStarHMI.h"
#endif

#if defined(__MMI_ITAP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_ITAP__) */ 

#include "ProtocolEvents.h"
#include "wgui_status_icons.h"
#include "PhonebookDef.h"
#include "PhoneBookTypes.h"
#include "PhonebookProt.h"
#include "PhonebookGprot.h"
#include "mainmenudef.h"
#include "CommonScreens.h"

#if defined(__MMI_PHB_EMAIL_SORT__)
#include "Nvram_user_defs.h"    /* For email sorting. Need Accessing NVRAM data */
#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
#include "mdi_datatype.h"
#include "mdi_audio.h"
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

#include "SimDetectionGprot.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_PHB_QUICK_SEARCH__)
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_Master_ADN.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_CC.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

/*
 * Typedef
 */
typedef void (*phb_comp_func) (U16 first, U16 second, U8 *same_count, S32 *distance);

/*
 * Define
 */
#define MMI_PHB_COMPARE_LENGTH 10       /* Compare 10 characters */
#define MMI_PHB_CONVERT_BUFF_ZI 32      /* ZI convert function need 32 bytes for buffer. */
#define MMI_PHB_QUICK_SEARCH_INPUT_LENGTH 6

#define MMI_PHB_SORT_LENGTH 10  /* Compare 10 characters */
#define MAX_PHB_NUMBER_COMP   20        /* Compare 20 entries for number filed */

#define BYTE_SIZE                      8        /* for g_phb_qsearch_bitmask */
#define BYTE_SIZE_SHIFT_ARITHMETIC     3
#if defined(__MMI_PHB_BOOT_UP_RECURSIVE_SORTING__)
// the max times value is used to set the max sorting times to start timer, you can adjust it to further improve the performance
#define MMI_PHB_NAME_SORT_MAX_TIMES 100 /* use for name sort when booting up, when sort times is 10, then envoke timer */
#endif /* defined(__MMI_PHB_BOOT_UP_RECURSIVE_SORTING__) */


/*
 * Local Variable
 */
#if defined(__MMI_PHB_QUICK_SEARCH__)
static U16 g_phb_qsearch_cache[MAX_PB_ENTRIES];

/* static U8    g_phb_qsearch[MAX_PB_ENTRIES]; */
static U8 g_phb_qsearch_bitmask[(MAX_PB_ENTRIES + 7) / 8];
static U8 g_phb_qsearch_input[(MMI_PHB_QUICK_SEARCH_INPUT_LENGTH + 1) * ENCODING_LENGTH];
static U8 g_phb_qsearch_is_cache = 0;   /* Check if cache already build */
/* for generic quick search -> SMS or MMS */
static U16 g_phb_generic_qsearch_cache[MAX_PB_ENTRIES];
static U8 g_phb_generic_qsearch_bitmask[(MAX_PB_ENTRIES + 7) / 8];
static U8 g_phb_generic_qsearch_input[(MMI_PHB_QUICK_SEARCH_INPUT_LENGTH + 1) * ENCODING_LENGTH];
static U8 g_phb_generic_qsearch_is_cache = 0;   /* Check if cache already build */
static U8 g_phb_quick_search_enter;
#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */ 

#if defined(__MMI_PHB_PINYIN_SORT__)
static U8 g_phb_name_pinyin_index[MAX_PB_ENTRIES][(MMI_PHB_SORT_LENGTH + 1) * ENCODING_LENGTH];
#endif 

static U8 g_phb_compare_length = 0xff;  /* number compare length */

#if defined(__MMI_PHB_BOOT_UP_RECURSIVE_SORTING__)
/* use for name sort */
static U16 g_phb_sort_left_stack[MAX_PB_ENTRIES / 2 + 1];
static U16 g_phb_sort_right_stack[MAX_PB_ENTRIES / 2 + 1];
// left and right stack are used to save the left and right element to quick sort
// you could modify the stack size to eliminate the usage of memory
static S32 g_phb_sort_index = 0;
// g_phb_sort_index means the num placed in stack
static phb_comp_func g_phb_name_sort_comp_func = NULL;
// name sort compare function, because the starttimer function cannot pass into argument, so I need this function pointer to save it
#endif /* defined(__MMI_PHB_BOOT_UP_RECURSIVE_SORTING__) */


/*
 * Global Variable
 */
extern U8 phb_list_view_type;
extern MMI_PHB_LIST_VIEW phbListView;
extern S8 pbName[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];

extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
extern U16 g_phb_name_index[];
extern U16 PhoneBookEntryCount;

#ifdef __MMI_PHB_USIM_FIELD__
extern MMI_PHB_NUMBER_BCD_STRUCT phb_anr[MAX_PB_SIM_ENTRIES][3];
#ifdef __MMI_PHB_EMAIL_SORT__
extern MMI_PHB_EMAIL_STRUCT phb_email[MAX_PB_SIM_ENTRIES];
#endif 
#endif /* __MMI_PHB_USIM_FIELD__ */

extern U8 MMI_current_input_mode;

extern MMI_PHB_LOOKUP_NODE_STRUCT LookUpTable[];

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
extern U8 g_phb_is_speaking_name;
#endif 

#if defined(__MMI_T9__)
#if defined(__MMI_T9_V7__)
extern T9CCAWFieldInfo FieldInfo;
#else 
extern T9FieldInfo FieldInfo;
#endif 
#endif /* defined(__MMI_T9__) */ 

#if defined(__MMI_ITAP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_ITAP__) */ 

extern PHB_OPTIONAL_FIELDS_STRUCT PhoneBookOptionalFields;
extern S8 pbEmailAddress[];

/*
 * Local Function
 */
static void mmi_phb_sort_name_fast_quicksort(U16 left, U16 right, phb_comp_func compare);
static void mmi_phb_sort_name_quicksort(U16 left, U16 right, phb_comp_func compare);
static void mmi_phb_sort_name_insertionsort(U16 low, U16 high, phb_comp_func compare);
static void mmi_phb_sort_name_swap(U16 a, U16 b);

/*
 * Global Function
 */

#define MMI_PHB_SEARCH_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_search_init
 * DESCRIPTION
 *  Initial function for phonebook search and sort.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_search_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MITEM101_PBOOK_SEARCH_ENTRY, mmi_phb_highlight_search_name);
    SetHiliteHandler(MITEM1010_SEARCH, mmi_phb_highlight_search_name_option_search);
    SetHiliteHandler(MITEM1011_INPUT_MEHTHOD, mmi_phb_highlight_search_name_option_input_method);

#if defined(__MMI_PHB_QUICK_SEARCH__)
    SetHiliteHandler(MENU_ID_PHB_QUICK_SEARCH, mmi_phb_highlight_quick_search_list);

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    SetHiliteHandler(MENU_ID_PHB_QUICK_SEARCH_INPUT_METHOD, mmi_phb_highlight_quick_search_input_method);
    SetHiliteHandler(MENU_ID_PHB_QUICK_SEARCH_OP_OPTION, mmi_phb_highlight_quick_search_op_option);
    SetHiliteHandler(MENU_ID_PHB_GENERIC_QUICK_SEARCH_INPUT_METHOD, mmi_phb_generic_highlight_quick_search_input_method);
    SetHiliteHandler(MENU_ID_PHB_GENERIC_QUICK_SEARCH_DONE, mmi_phb_generic_highlight_quick_search_done);
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */ 

}


#define MMI_PHB_SORT
#if defined(__MMI_PHB_BOOT_UP_RECURSIVE_SORTING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_build_name_index_with_timer
 * DESCRIPTION
 *  phb sorting with timer when boot up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_build_name_index_with_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_PINYIN_SORT__)
    if (g_phb_cntx.sort_type == MMI_PHB_SORT_PINYIN)
    {
        g_phb_name_sort_comp_func = mmi_phb_sort_compare_name_index_by_pinyin_cache;
        mmi_phb_sort_name_init_quicksort_with_timer();
    }
    else
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 
    {
        g_phb_name_sort_comp_func = mmi_phb_sort_compare_name_index_by_encoding;
        mmi_phb_sort_name_init_quicksort_with_timer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_name_init_quicksort_with_timer
 * DESCRIPTION
 *  phb sorting with timer when boot up for the first time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_name_init_quicksort_with_timer(void)
{
    g_phb_sort_index = 0;
    g_phb_sort_left_stack[g_phb_sort_index] = 0;
    g_phb_sort_right_stack[g_phb_sort_index] = (U16) (PhoneBookEntryCount - 1);
    StartTimer(PHB_NAME_SORT_TIMER, 100, mmi_phb_sort_name_quicksort_with_timer);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_name_quicksort_with_timer
 * DESCRIPTION
 *  phb sorting with timer when boot up after the first time sorting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_name_quicksort_with_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 distance;
    U8 same_count;
    U16 left, right, pivot, new_pivot, i;
    U8 phb_sort_times = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_phb_name_sort_comp_func != NULL);
    
    while (g_phb_sort_index >= 0 && phb_sort_times <= MMI_PHB_NAME_SORT_MAX_TIMES)
    {
        /* pop */
        left = g_phb_sort_left_stack[g_phb_sort_index];
        right = g_phb_sort_right_stack[g_phb_sort_index];
        --g_phb_sort_index;
        
        if (right <= left)
        {
            continue;
        }

        pivot = (left + right) / 2;

        mmi_phb_sort_name_swap(pivot, right);

        new_pivot = left;
        for (i = left; i < right; ++i)
        {
            (*g_phb_name_sort_comp_func) (g_phb_name_index[i], g_phb_name_index[right], &same_count, &distance);
            if (distance < 0)
            {
                mmi_phb_sort_name_swap(new_pivot, i);
                ++new_pivot;
            }
        }
        mmi_phb_sort_name_swap(new_pivot, right);

        /* push */
        ++g_phb_sort_index;
        MMI_ASSERT(g_phb_sort_index < (MAX_PB_ENTRIES / 2 + 1));
        g_phb_sort_left_stack[g_phb_sort_index] = left;
        g_phb_sort_right_stack[g_phb_sort_index] = ((new_pivot <= 1) ? 0 : (new_pivot - 1));  //avoid over flow

        /* push */
        ++g_phb_sort_index;
        MMI_ASSERT(g_phb_sort_index < (MAX_PB_ENTRIES / 2 + 1));
        g_phb_sort_left_stack[g_phb_sort_index] = new_pivot + 1;
        g_phb_sort_right_stack[g_phb_sort_index] = right;
        
        phb_sort_times ++;
    }
    if (g_phb_sort_index >= 0)
    {
        StopTimer(PHB_NAME_SORT_TIMER);
        StartTimer(PHB_NAME_SORT_TIMER, 250, mmi_phb_sort_name_quicksort_with_timer);        
    // start timer to let other ap has the chance to excuete his job, avoid MMI hang
    // but it will let the phb ready time interval longer than the original design
    // you can fine tune the timer interval and the max_sort times value
    }
    else
    {
        g_phb_name_sort_comp_func = NULL;
        mmi_phb_ind_startup_finish_after_name_sort();
        // after sort, go back to execute the job in statup_finish in the original design
    }
}   /* end of phb_quicksort */
#endif /* defined(__MMI_PHB_BOOT_UP_RECURSIVE_SORTING__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_build_name_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_build_name_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhoneBookEntryCount > 1)
    {
    #if defined(__MMI_PHB_PINYIN_SORT__)
        if (g_phb_cntx.sort_type == MMI_PHB_SORT_PINYIN)
        {
            mmi_phb_sort_name_fast_quicksort(
                0,
                (U16) (PhoneBookEntryCount - 1),
                mmi_phb_sort_compare_name_index_by_pinyin_cache);
        }
        else
    #endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 
            mmi_phb_sort_name_fast_quicksort(
                0,
                (U16) (PhoneBookEntryCount - 1),
                mmi_phb_sort_compare_name_index_by_encoding);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_insert_name_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  store_index     [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_phb_sort_insert_name_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhoneBookEntryCount == 0)
    {
        g_phb_name_index[PhoneBookEntryCount] = store_index;
        PhoneBookEntryCount++;
        return 0;
    }
    else
    {
        pos = mmi_phb_sort_insert_name_index_find_pos(0, (PhoneBookEntryCount - 1), store_index);

        for (i = PhoneBookEntryCount; i > pos; i--)
        {
            g_phb_name_index[i] = g_phb_name_index[i - 1];
        }
        g_phb_name_index[pos] = store_index;
        PhoneBookEntryCount++;

        return pos;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_insert_name_index_find_pos
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  low             [IN]            
 *  high            [IN]            
 *  store_index     [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_phb_sort_insert_name_index_find_pos(S32 low, S32 high, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mid = 0;
    S16 flag = 0;
    U8 same_count;
    S32 distance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (low <= high)
    {
        mid = (low + high) / 2;

    #if defined(__MMI_PHB_PINYIN_SORT__)
        if (g_phb_cntx.sort_type == MMI_PHB_SORT_PINYIN)
        {
            mmi_phb_sort_compare_name_index_by_pinyin(store_index, g_phb_name_index[mid], &same_count, &distance);
        }
        else
    #endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 
            mmi_phb_sort_compare_name_index_by_encoding(store_index, g_phb_name_index[mid], &same_count, &distance);

        if (distance > 0)
        {
            low = mid + 1;
            flag = -1;
        }
        else    /* Either > 0 or < 0, not possible ==0 */
        {
            high = mid - 1;
            flag = 1;
        }
    }

    if (flag == -1)
    {
        return (U16) (mid + 1);
    }
    else
    {
        return (U16) mid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_compare_name_index
 * DESCRIPTION
 *  Compare two phonebook by name string. If name is empty use number instead.
 * PARAMETERS
 *  first           [IN]            Store_index of first compare element
 *  second          [IN]            Store_index of second compare element
 *  string1         [IN]            First name string
 *  string2         [IN]            Second name string
 *  same_count      [IN/OUT]        Same count of two element
 *  distance        [IN/OUT]        Difference of two element
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_compare_name_index(U16 first, U16 second, S8 *string1, S8 *string2, U8 *same_count, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 number1[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    S8 number2[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use number to sort if name empty */
    if (string1[0] == 0 && string1[1] == 0)
    {
        mmi_phb_convert_get_ucs2_number(number1, first);
        string1 = (S8*) number1;
    }

    /* Use number to sort if name empty */
    if (string2[0] == 0 && string2[1] == 0)
    {
        mmi_phb_convert_get_ucs2_number(number2, second);
        string2 = (S8*) number2;
    }

    /* Compare two strings */
    mmi_phb_compare_ucs2_strings(string1, string2, same_count, distance);

    /* sort according storage location, let entry in NVRAM put before in SIM. (store_index can decide store location) */
    if (*distance == 0)
    {
        if (first < second)
        {
            *distance = -1;
        }
        else if (first > second)
        {
            *distance = 1;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_compare_name_index_by_encoding
 * DESCRIPTION
 *  Compare two phonebook entry element by encoding.
 * PARAMETERS
 *  first           [IN]            Store_index of first compare element
 *  second          [IN]            Store_index of second compare element
 *  same_count      [IN/OUT]        Same count of two element
 *  distance        [IN/OUT]        Difference of two element
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_compare_name_index_by_encoding(U16 first, U16 second, U8 *same_count, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *string1, *string2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string1 = (S8*) PhoneBook[first].alpha_id.name;
    string2 = (S8*) PhoneBook[second].alpha_id.name;

    mmi_phb_sort_compare_name_index(first, second, string1, string2, same_count, distance);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_compare_name_index_by_pinyin_cache
 * DESCRIPTION
 *  Compare two phonebook entry element by pinyin by using prior convert result.
 * PARAMETERS
 *  first           [IN]            Store_index of first compare element
 *  second          [IN]            Store_index of second compare element
 *  same_count      [IN/OUT]        Same count of two element
 *  distance        [IN/OUT]        Difference of two element
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_PHB_PINYIN_SORT__)
void mmi_phb_sort_compare_name_index_by_pinyin_cache(U16 first, U16 second, U8 *same_count, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *string1, *string2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhoneBook[first].alpha_id.name_dcs == MMI_PHB_ASCII)
    {
        string1 = (S8*) PhoneBook[first].alpha_id.name;
    }
    else
    {
        string1 = (S8*) g_phb_name_pinyin_index[first];
    }

    if (PhoneBook[second].alpha_id.name_dcs == MMI_PHB_ASCII)
    {
        string2 = (S8*) PhoneBook[second].alpha_id.name;
    }
    else
    {
        string2 = (S8*) g_phb_name_pinyin_index[second];
    }

    mmi_phb_sort_compare_name_index(first, second, string1, string2, same_count, distance);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_compare_name_index_by_pinyin
 * DESCRIPTION
 *  Compare two phonebook entry element by pinyin.
 * PARAMETERS
 *  first           [IN]            Store_index of first compare element
 *  second          [IN]            Store_index of second compare element
 *  same_count      [IN/OUT]        Same count of two element
 *  distance        [IN/OUT]        Difference of two element
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_compare_name_index_by_pinyin(U16 first, U16 second, U8 *same_count, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *string1, *string2;

    S8 buffer1[(MMI_PHB_SORT_LENGTH + 1) * ENCODING_LENGTH];
    S8 buffer2[(MMI_PHB_SORT_LENGTH + 1) * ENCODING_LENGTH];

    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhoneBook[first].alpha_id.name_dcs == MMI_PHB_ASCII)
    {
        string1 = (S8*) PhoneBook[first].alpha_id.name;
    }
    else
    {
        count = mmi_phb_util_convert_to_pinyin(
                    PhoneBook[first].alpha_id.name,
                    (U8*) buffer1,
                    (MMI_PHB_SORT_LENGTH * ENCODING_LENGTH));
        buffer1[count++] = 0x00;
        buffer1[count] = 0x00;
        string1 = (S8*) buffer1;
    }

    if (PhoneBook[second].alpha_id.name_dcs == MMI_PHB_ASCII)
    {
        string2 = (S8*) PhoneBook[second].alpha_id.name;
    }
    else
    {
        count = mmi_phb_util_convert_to_pinyin(
                    PhoneBook[second].alpha_id.name,
                    (U8*) buffer2,
                    (MMI_PHB_SORT_LENGTH * ENCODING_LENGTH));
        buffer2[count++] = 0x00;
        buffer2[count] = 0x00;
        string2 = (S8*) buffer2;
    }

    mmi_phb_sort_compare_name_index(first, second, string1, string2, same_count, distance);
}
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_name_fast_quicksort
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  left        [IN]            
 *  right       [IN]            
 *  compare     [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_sort_name_fast_quicksort(U16 left, U16 right, phb_comp_func compare)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_sort_name_quicksort(left, right, compare);
    mmi_phb_sort_name_insertionsort(left, right, compare);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_name_quicksort
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  left        [IN]            
 *  right       [IN]            
 *  compare     [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_sort_name_quicksort(U16 left, U16 right, phb_comp_func compare)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 const Min = 4;  /* Lower bound to sort */
    U16 i;
    U16 j;
    U16 pivot;

    S32 distance;
    U8 same_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(compare != NULL);

    if ((right - left) > Min)
    {
        i = (right + left) / 2;

        /* left > mid */
        (*compare) (g_phb_name_index[left], g_phb_name_index[i], &same_count, &distance);
        if (distance > 0)
        {
            mmi_phb_sort_name_swap(left, i);
        }

        /* left > right */
        (*compare) (g_phb_name_index[left], g_phb_name_index[right], &same_count, &distance);
        if (distance > 0)
        {
            mmi_phb_sort_name_swap(left, right);
        }

        /* mid > right */
        (*compare) (g_phb_name_index[i], g_phb_name_index[right], &same_count, &distance);
        if (distance > 0)
        {
            mmi_phb_sort_name_swap(i, right);
        }

        j = right - 1;
        mmi_phb_sort_name_swap(i, j);

        i = left;

        pivot = g_phb_name_index[j];    /* kal_mem_cpy(&v, (void const*)&a[j], sizeof(pindex_struct)); */

        for (;;)
        {
            do  /* ++i < pivot */
            {
                (*compare) (g_phb_name_index[++i], pivot, &same_count, &distance);
            }
            while (distance < 0);

            do  /* --j > pivot */
            {
                (*compare) (g_phb_name_index[--j], pivot, &same_count, &distance);
            }
            while (distance > 0);

            if (j < i)
            {
                break;
            }

            mmi_phb_sort_name_swap(i, j);
        }

        mmi_phb_sort_name_swap(i, (U16) (right - 1));
        mmi_phb_sort_name_quicksort(left, j, compare);
        mmi_phb_sort_name_quicksort((U16) (i + 1), right, compare);
    }
}   /* end of phb_quicksort */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_name_insertionsort
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  low         [IN]            
 *  high        [IN]            
 *  compare     [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_sort_name_insertionsort(U16 low, U16 high, phb_comp_func compare)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 j;
    U16 pivot;

    S32 distance;
    U8 same_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(compare != NULL);

    for (i = low + 1; i <= high; ++i)
    {
        pivot = g_phb_name_index[i];

        j = i;
        while (j > low)
        {
            (*compare) (g_phb_name_index[j - 1], pivot, &same_count, &distance);
            if (distance <= 0)
            {
                break;
            }

            g_phb_name_index[j] = g_phb_name_index[j - 1];

            j--;
        }

        g_phb_name_index[j] = pivot;
    }
}   /* end of phb_insertion_sort */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_name_swap
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  a       [IN/OUT]        First variable, used as returns
 *  b       [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_sort_name_swap(U16 a, U16 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp = g_phb_name_index[a];
    g_phb_name_index[a] = g_phb_name_index[b];
    g_phb_name_index[b] = tmp;
}

#define MMI_PHB_SEARCH_NAME


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_search_name
 * DESCRIPTION
 *  Highlight handler for "Search Entry" in PHB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_search_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_search_name.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_phb_search_name_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_phb_search_name_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    phbListView = MMI_PHB_LIST_FOR_PHB;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_search_name_option_search
 * DESCRIPTION
 *  Highlight handler for "Search" in Search Option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_search_name_option_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_highlight_search_name_option_search.>\n",
                         __FILE__, __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_search_name, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_search_name, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_search_name_option_input_method
 * DESCRIPTION
 *  Highlight handler for "Input Method" in Search Option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_search_name_option_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB,
                         "File: [%s]  Line: [%d] <<mmi_phb_highlight_search_name_option_input_method.>\n", __FILE__,
                         __LINE__);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetInputMethodAndDoneCaptionIcon(IMG_SCR_PBOOK_CAPTION);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_search_name_pre_entry
 * DESCRIPTION
 *  Calls mmi_phb_entry_search_name() after few checks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_search_name_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_search_name_pre_entry.>\n", __FILE__,
                         __LINE__);

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
    else
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif/* __MMI_DUAL_SIM_MASTER__ */
    {
        memset(pbName, 0, ENCODING_LENGTH);
        if (PhoneBookEntryCount)
        {
            mmi_phb_entry_search_name();
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
                IMG_GLOBAL_EMPTY,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                EMPTY_LIST_TONE);
        }
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_search_name
 * DESCRIPTION
 *  Gets name input from user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_search_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_search_name.>\n", __FILE__,
                         __LINE__);

    EntryNewScreen(SCR_SEARCH_NAME_ENTRY, mmi_phb_exit_search_name, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_SEARCH_NAME_ENTRY);

    if (guiBuffer != NULL)
    {
        state = get_multiline_inputbox_category_history_state(SCR_SEARCH_NAME_ENTRY, guiBuffer);
        if (state != -1)
        {
            phbListView = (U8) state;
        }
    }
#if defined UI_SMALL_CATEGORY_EDITOR
    enable_resized_small_screen();
#endif 
    ShowCategory5Screen_ext(
        STR_SCR_SEARCH_NAME_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (INPUT_TYPE_ALPHANUMERIC_UPPERCASE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER),
        (PU8) pbName,
        MAX_SEARCH_NAME_LENGTH + 1,
        guiBuffer,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(mmi_phb_entry_search_name_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_search_name, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_search_name
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_search_name()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_search_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S8 state = (S8) phbListView;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.start_scr_id == 0)   /* start from Shortcut */
    {
        g_phb_cntx.start_scr_id = GetCurrScrnId();
    }
    g_phb_cntx.end_scr_id = SCR_SEARCH_NAME_ENTRY;

    h.scrnID = SCR_SEARCH_NAME_ENTRY;
    h.entryFuncPtr = mmi_phb_entry_search_name;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) pbName);
    GetCategoryHistory(h.guiBuffer);
    set_multiline_inputbox_category_history_state(SCR_SEARCH_NAME_ENTRY, h.guiBuffer, state);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_search_name_option
 * DESCRIPTION
 *  Draws the Search Options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_search_name_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[2];
    U16 nNumofItem;
    S8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_search_name_option.>\n", __FILE__,
                         __LINE__);

    EntryNewScreen(SCR_SEARCH_OPTIONS, mmi_phb_exit_search_name_option, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_SEARCH_OPTIONS);

    if (guiBuffer != NULL)
    {
        state = get_list_menu_category_history_state(SCR_PBOOK_LIST, guiBuffer);
        if (state != -1)
        {
            phbListView = (U8) state;   /* Restore State in history. */
        }
    }

    nNumofItem = GetNumOfChild(MITEM101_SEARCH_OPTIONS);
    GetSequenceStringIds(MITEM101_SEARCH_OPTIONS, nStrItemList);
    SetParentHandler(MITEM101_SEARCH_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    RegisterInputMethodScreenCloseFunction(mmi_phb_go_back_2_history);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_search_name_option
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_search_name_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_search_name_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    S8 state = (S8) phbListView;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_SEARCH_OPTIONS;

    h.scrnID = SCR_SEARCH_OPTIONS;
    h.entryFuncPtr = mmi_phb_entry_search_name_option;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    set_list_menu_category_history_state(SCR_PBOOK_LIST, h.guiBuffer, state);   /* Keep State in history. */
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_search_name
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_search_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.highlight_entry = mmi_phb_search_name_find_closet();

    if (phbListView == MMI_PHB_LIST_FOR_PHB)
    {
        mmi_phb_list_pre_entry();   /* Dynamic List */
    }
    else if ((phbListView == MMI_PHB_LIST_FOR_SMS) || (phbListView == MMI_PHB_LIST_FOR_SMS_SEARCH_NAME))
    {
        mmi_phb_list_pre_entry_second_level();
    }

    DeleteNScrId(SCR_SEARCH_NAME_ENTRY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_search_name_find_closet
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_phb_search_name_find_closet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) pbName) == 0)
    {
        return 0;
    }

    result_index = mmi_phb_search_name_binary_search(0, (PhoneBookEntryCount - 1), (S8*) pbName);

    /* Check boundary */
    if (result_index >= PhoneBookEntryCount)
    {
        result_index = PhoneBookEntryCount - 1;
    }

    return result_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_search_name_binary_search
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  low             [IN]            
 *  high            [IN]            
 *  ucs2_name       [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
U16 mmi_phb_search_name_binary_search(S32 low, S32 high, S8 *ucs2_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mid = 0;
    S16 flag = 0;
    U8 same_count;
    S32 distance;
    U16 index;
    S8 *string;
    S8 number[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

#if defined(__MMI_PHB_PINYIN_SORT__)
    S8 buffer1[(MMI_PHB_SORT_LENGTH + 1) * ENCODING_LENGTH];
    S8 buffer2[(MMI_PHB_SORT_LENGTH + 1) * ENCODING_LENGTH];
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetUCS2Flag(ucs2_name))
    {
        count = mmi_phb_util_convert_to_pinyin((U8*) ucs2_name, (U8*) buffer1, (MMI_PHB_SORT_LENGTH * ENCODING_LENGTH));
        buffer1[count++] = 0x00;
        buffer1[count] = 0x00;
        ucs2_name = (S8*) buffer1;
    }
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 

    /*
     * Use binary search to find nearest name.
     */
    while (low <= high)
    {
        mid = (low + high) / 2;

        /*
         * Prepare entry data to compare
         */
        index = g_phb_name_index[mid];

    #if defined(__MMI_PHB_PINYIN_SORT__)
        if (PhoneBook[index].alpha_id.name_dcs == MMI_PHB_ASCII)
        {
            string = (S8*) PhoneBook[index].alpha_id.name;
        }
        else
        {
            count = mmi_phb_util_convert_to_pinyin(
                        PhoneBook[index].alpha_id.name,
                        (U8*) buffer2,
                        (MMI_PHB_SORT_LENGTH * ENCODING_LENGTH));
            buffer2[count++] = 0x00;
            buffer2[count] = 0x00;
            string = (S8*) buffer2;
        }
    #else /* defined(__MMI_PHB_PINYIN_SORT__) */ 
        string = (S8*) PhoneBook[index].alpha_id.name;
    #endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 

        /*
         * Use number to compare if name is empty
         */
        if (mmi_ucs2strlen(string) == 0)
        {
            mmi_phb_convert_get_ucs2_number(number, index);
            string = (S8*) number;
        }

        /*
         * Compare search pattern with entry
         */
        mmi_phb_compare_ucs2_strings(ucs2_name, string, &same_count, &distance);

        if (distance > 0)
        {
            low = mid + 1;
            flag = -1;
        }
        /*
         * Distance == 0 or < 0 here
         * If there are duplicate entry, this will help to move up until first entry.
         */
        else
        {
            high = mid - 1;
            flag = 1;
        }
    }

    if (flag == -1)
    {
        return (U16) (mid + 1);
    }
    else
    {
        return (U16) mid;
    }
}


#define MMI_PHB_QUICKSEARCH
#if defined(__MMI_PHB_QUICK_SEARCH__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_quick_search_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_quick_search_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_phb_quick_search_list_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_quick_search_list_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_PHB_QUICK_SEARCH__)*/


#if defined(__MMI_PHB_QUICK_SEARCH__)
#if defined(__MMI_T9__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__))
#if defined(__MMI_T9_V7__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_to_spelling
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  input_string        [?]             
 *  output_string       [?]             
 *  out_len             [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
BOOL mmi_phb_quick_search_convert_to_spelling(U8 *input_string, U8 *output_string, U8 *out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 out = 0;
    U8 i = 0;
    T9STATUS t9ReturnCodes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Should already switch to the proper input language in "mmi_phb_quick_search_convert_cache()". */

    if (input_string[0] != 0 || input_string[1] != 0)
    {
        if (MMI_current_input_mode == INPUT_MODE_MMI_SM_STROKE || MMI_current_input_mode == INPUT_MODE_MMI_TR_STROKE)
        {
            t9ReturnCodes = T9CCGetCharStrokes(&FieldInfo.CCFieldInfo, (U16*) input_string, 0);
        }
        else
        {
            t9ReturnCodes = T9CCGetCharSpell(&FieldInfo.CCFieldInfo, (U16*) input_string, 0);
        }

        if (t9ReturnCodes == 0)
        {
            switch (MMI_current_input_mode)
            {
                case INPUT_MODE_MMI_MULTITAP_BPMF:
                    while ((FieldInfo.CCFieldInfo.pbSpellBuf[i] != 0x00) && (i <= 7))
                    {
                        *((U16*) (output_string + out)) = BPMFInternalToUnicode(FieldInfo.CCFieldInfo.pbSpellBuf[i]);
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                case INPUT_MODE_MMI_MULTITAP_PINYIN:
                    while ((FieldInfo.CCFieldInfo.pbSpellBuf[i] != 0x00) && (i <= 7))
                    {
                        output_string[out] = FieldInfo.CCFieldInfo.pbSpellBuf[i];
                        output_string[out + 1] = 0;
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                case INPUT_MODE_MMI_SM_STROKE:
                case INPUT_MODE_MMI_TR_STROKE:
                    while ((FieldInfo.CCFieldInfo.pbKeyBuf[i] != 0x00) &&
                           (i < FieldInfo.CCFieldInfo.nKeyBufLen) && (i <= 7))
                    {
                        *((U16*) (output_string + out)) = StrokeInternalToUnicode(FieldInfo.CCFieldInfo.pbKeyBuf[i]);
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                default:
                    break;
            }

            *out_len = i;
            return TRUE;
        }

        /* Input String Does not Converted. */
        memcpy(output_string, input_string, 2);
        *out_len = 1;
        return TRUE;
    }

    *out_len = 0;
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_cache
 * DESCRIPTION
 *  This function convert first character of name field into cache.
 * PARAMETERS
 *  index       [IN]        Phonebook entry index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_convert_cache(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS t9ReturnCodes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* move change language function out from loop to speed up */

    if (MMI_current_input_mode == INPUT_MODE_MMI_SM_STROKE || MMI_current_input_mode == INPUT_MODE_MMI_TR_STROKE)
    {
        t9ReturnCodes = T9CCGetCharStrokes(&FieldInfo.CCFieldInfo, (U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name, 0);
    }
    else
    {
        t9ReturnCodes = T9CCGetCharSpell(&FieldInfo.CCFieldInfo, (U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name, 0);
    }

    if (t9ReturnCodes == 0)
    {
        switch (MMI_current_input_mode)
        {
            case INPUT_MODE_MMI_MULTITAP_BPMF:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = BPMFInternalToUnicode(FieldInfo.CCFieldInfo.pbSpellBuf[0]);
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = BPMFInternalToUnicode(FieldInfo.CCFieldInfo.pbSpellBuf[0]);
                }
                else
                {
                    ASSERT(0);
                }
                break;

            case INPUT_MODE_MMI_MULTITAP_PINYIN:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = FieldInfo.CCFieldInfo.pbSpellBuf[0];
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = FieldInfo.CCFieldInfo.pbSpellBuf[0];
                }
                else
                {
                    ASSERT(0);
                }
                break;

            case INPUT_MODE_MMI_SM_STROKE:
            case INPUT_MODE_MMI_TR_STROKE:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = StrokeInternalToUnicode(FieldInfo.CCFieldInfo.pbKeyBuf[0]);
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = StrokeInternalToUnicode(FieldInfo.CCFieldInfo.pbKeyBuf[0]);
                }
                else
                {
                    ASSERT(0);
                }
                break;

            default:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = *((U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name);
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = *((U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name);
                }
                else
                {
                    ASSERT(0);
                }
                break;
        }
    }
    else
    {
    	if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
    	{
            g_phb_qsearch_cache[index] = *((U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name);
        }
        else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
        {
            g_phb_generic_qsearch_cache[index] = *((U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name);
        }
        else
        {
            ASSERT(0);
        }
    }
}
#else /* defined(__MMI_T9_V7__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_to_spelling
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  input_string        [?]             
 *  output_string       [?]             
 *  out_len             [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
BOOL mmi_phb_quick_search_convert_to_spelling(U8 *input_string, U8 *output_string, U8 *out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 out = 0;
    U8 i = 0;
    T9Event t9EventInput;
    T9STATUS t9ReturnCodes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Should already switch to the proper input language in "mmi_phb_quick_search_convert_cache()". */

    if (input_string[0] != 0 || input_string[1] != 0)
    {
        if (MMI_current_input_mode == INPUT_MODE_MMI_SM_STROKE || MMI_current_input_mode == INPUT_MODE_MMI_TR_STROKE)
        {
            t9EventInput.mType = T9EVTSTROKES;
        }
        else
        {
            t9EventInput.mType = T9EVTSPELLING;
        }
        t9EventInput.data.sLDBData.psBuf = (U16*) input_string;
        t9EventInput.data.sLDBData.mCtrlID = 0;

        t9ReturnCodes = T9HandleEvent(&FieldInfo, &t9EventInput);

        if (t9ReturnCodes == 0)
        {
            switch (MMI_current_input_mode)
            {
                case INPUT_MODE_MMI_MULTITAP_BPMF:
                    while ((FieldInfo.uLangData.pAuxChinese->pbSpellBuf[i] != 0x00) && (i <= 7))
                    {
                        *((U16*) (output_string + out)) = BPMFInternalToUnicode(FieldInfo.uLangData.pAuxChinese->pbSpellBuf[i]);
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                case INPUT_MODE_MMI_MULTITAP_PINYIN:
                    while ((FieldInfo.uLangData.pAuxChinese->pbSpellBuf[i] != 0x00) && (i <= 7))
                    {
                        output_string[out] = FieldInfo.uLangData.pAuxChinese->pbSpellBuf[i];
                        output_string[out + 1] = 0;
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                case INPUT_MODE_MMI_SM_STROKE:
                case INPUT_MODE_MMI_TR_STROKE:
                    while ((FieldInfo.uLangData.pAuxChinese->pbKeyBuf[i] != 0x00) &&
                           (i < FieldInfo.uLangData.pAuxChinese->nKeyBufLen) && (i <= 7))
                    {
                        *((U16*) (output_string + out)) = StrokeInternalToUnicode(FieldInfo.uLangData.pAuxChinese->pbKeyBuf[i]);
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                default:
                    break;
            }

            *out_len = i;
            return TRUE;
        }

        /* Input String Does not Converted. */
        memcpy(output_string, input_string, 2);
        *out_len = 1;
        return TRUE;
    }

    *out_len = 0;
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_cache
 * DESCRIPTION
 *  This function convert first character of name field into cache.
 * PARAMETERS
 *  index       [IN]        Phonebook entry index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_convert_cache(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9Event t9EventInput;
    T9STATUS t9ReturnCodes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* move change language function out from loop to speed up */

    if (MMI_current_input_mode == INPUT_MODE_MMI_SM_STROKE || MMI_current_input_mode == INPUT_MODE_MMI_TR_STROKE)
    {
        t9EventInput.mType = T9EVTSTROKES;
    }
    else
    {
        t9EventInput.mType = T9EVTSPELLING;
    }
    t9EventInput.data.sLDBData.psBuf = (U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name;
    t9EventInput.data.sLDBData.mCtrlID = 0;

    t9ReturnCodes = T9HandleEvent(&FieldInfo, &t9EventInput);

    if (t9ReturnCodes == 0)
    {
        switch (MMI_current_input_mode)
        {
            case INPUT_MODE_MMI_MULTITAP_BPMF:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = BPMFInternalToUnicode(FieldInfo.uLangData.pAuxChinese->pbSpellBuf[0]);
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = BPMFInternalToUnicode(FieldInfo.uLangData.pAuxChinese->pbSpellBuf[0]);
                }
                else
                {
                    ASSERT(0);
                }
                break;

            case INPUT_MODE_MMI_MULTITAP_PINYIN:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = FieldInfo.uLangData.pAuxChinese->pbSpellBuf[0];
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = FieldInfo.uLangData.pAuxChinese->pbSpellBuf[0];
                }
                else
                {
                    ASSERT(0);
                }
                break;

            case INPUT_MODE_MMI_SM_STROKE:
            case INPUT_MODE_MMI_TR_STROKE:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = StrokeInternalToUnicode(FieldInfo.uLangData.pAuxChinese->pbKeyBuf[0]);
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = StrokeInternalToUnicode(FieldInfo.uLangData.pAuxChinese->pbKeyBuf[0]);
                }
                else
                {
                    ASSERT(0);
                }
                break;

            default:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = *((U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name);
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = *((U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name);
                }
                else
                {
                    ASSERT(0);
                }
                break;
        }
    }
    else
    {
        if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
        {
            g_phb_qsearch_cache[index] = *((U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name);
        }
        else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
        {
            g_phb_generic_qsearch_cache[index] = *((U16*) PhoneBook[g_phb_name_index[index]].alpha_id.name);
        }
        else
        {
            ASSERT(0);
        }
    }
}
#endif /* defined(__MMI_T9_V7__) */ 
#elif defined(__MMI_ZI__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_to_spelling
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  input_string        [?]             
 *  output_string       [?]             
 *  out_len             [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
BOOL mmi_phb_quick_search_convert_to_spelling(U8 *input_string, U8 *output_string, U8 *out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 out = 0;
    U8 i = 0;
    U16 code;
    U16 mode;
    U16 pCharInfoBuffer[MMI_PHB_CONVERT_BUFF_ZI];
    U16 CharInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change convert mode according to input method. */
    switch (MMI_current_input_mode)
    {
        case INPUT_MODE_MMI_MULTITAP_BPMF:
            /* mode = ZI8_GETMODE_BOPOMOFO; */
            mode = ZI8_GETMODE_BOPOMOFO_NAME;
            break;

        case INPUT_MODE_MMI_MULTITAP_PINYIN:
            /* mode = ZI8_GETMODE_PINYIN; */
            mode = ZI8_GETMODE_PINYIN_NAME;
            break;

        case INPUT_MODE_MMI_SM_STROKE:
        case INPUT_MODE_MMI_TR_STROKE:
            mode = ZI8_GETMODE_STROKES;
            break;

        default:
            return FALSE;
            break;
    }

    if (input_string[0] != 0 || input_string[1] != 0)
    {
        memcpy(&code, input_string, 2);

        if ((code >= 0x4e00) && (code <= 0x9fa5) &&
            Zi8GetCharInfo(code, (U16*) pCharInfoBuffer, MMI_PHB_CONVERT_BUFF_ZI, mode))
        {
            switch (MMI_current_input_mode)
            {
                case INPUT_MODE_MMI_MULTITAP_BPMF:
                    /* Do not convert tone */
                    while ((pCharInfoBuffer[i] != 0x0000) &&
                           ((pCharInfoBuffer[i] < ZI8_CODE_TONES_1) || (pCharInfoBuffer[i] > ZI8_CODE_TONES_5)))
                    {
                        CharInfo = pCharInfoBuffer[i] - ZI8_BASE_BPMF + 0x3105;
                        memcpy(output_string + out, &CharInfo, 2);
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                case INPUT_MODE_MMI_MULTITAP_PINYIN:
                    /* Do not convert tone */
                    while ((pCharInfoBuffer[i] != 0x0000) &&
                           ((pCharInfoBuffer[i] < ZI8_CODE_TONES_1) || (pCharInfoBuffer[i] > ZI8_CODE_TONES_5)))
                    {
                        CharInfo = pCharInfoBuffer[i] - ZI8_BASE_PINYIN + 0x0061;
                        memcpy(output_string + out, &CharInfo, 2);
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                case INPUT_MODE_MMI_SM_STROKE:
                case INPUT_MODE_MMI_TR_STROKE:
                    while ((pCharInfoBuffer[i] != 0x0000) && (i <= 7))
                    {
                        memcpy(output_string + out, &pCharInfoBuffer[i], 2);
                        out = out + 2;
                        i = i + 1;
                    }
                    break;

                default:
                    break;
            }

            *out_len = i;
            return TRUE;

        }

        memcpy(output_string, input_string, 2);
        *out_len = 1;
        return TRUE;
    }

    *out_len = 0;
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_cache
 * DESCRIPTION
 *  This function convert first character of name field into cache.
 * PARAMETERS
 *  index       [IN]        Phonebook entry index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_convert_cache(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 code;
    U16 mode;
    U16 pCharInfoBuffer[MMI_PHB_CONVERT_BUFF_ZI];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&code, PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);

    /* Change to proper input method. */
    switch (MMI_current_input_mode)
    {
        case INPUT_MODE_MMI_MULTITAP_BPMF:
            mode = ZI8_GETMODE_BOPOMOFO;
            break;

        case INPUT_MODE_MMI_MULTITAP_PINYIN:
            mode = ZI8_GETMODE_PINYIN;
            break;

        case INPUT_MODE_MMI_SM_STROKE:
        case INPUT_MODE_MMI_TR_STROKE:
            mode = ZI8_GETMODE_STROKES;
            break;

        default:
            if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
            {
                memcpy(&g_phb_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
            }
            else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
            {
                memcpy(&g_phb_generic_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
            }
            else
            {
                ASSERT(0);
            }
            return;
    }

    /* Begin to convert and store the result according to the input method. */
    if ((code >= 0x4e00) && (code <= 0x9fa5) &&
        Zi8GetCharInfo(code, (U16*) pCharInfoBuffer, MMI_PHB_CONVERT_BUFF_ZI, mode))
    {
        switch (MMI_current_input_mode)
        {
            case INPUT_MODE_MMI_MULTITAP_BPMF:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = pCharInfoBuffer[0] - ZI8_BASE_BPMF + 0x3105;
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = pCharInfoBuffer[0] - ZI8_BASE_BPMF + 0x3105;
                }
                else
                {
                    ASSERT(0);
                }
                break;

            case INPUT_MODE_MMI_MULTITAP_PINYIN:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = pCharInfoBuffer[0] - ZI8_BASE_PINYIN + 0x0061;
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = pCharInfoBuffer[0] - ZI8_BASE_PINYIN + 0x0061;
                }
                else
                {
                    ASSERT(0);
                }                
                break;

            case INPUT_MODE_MMI_SM_STROKE:
            case INPUT_MODE_MMI_TR_STROKE:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = pCharInfoBuffer[0];
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = pCharInfoBuffer[0];
                }
                else
                {
                    ASSERT(0);
                }                
                break;

            default:
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    memcpy(&g_phb_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    memcpy(&g_phb_generic_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
                }
                else
                {
                    ASSERT(0);
                }               
                break;
        }
    }
    else
    {
        if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
        {
            memcpy(&g_phb_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
        }
        else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
        {
            memcpy(&g_phb_generic_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
        }
        else
        {
            ASSERT(0);
        }       
    }
}

#elif defined(__MMI_CSTAR__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_to_spelling
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  input_string        [?]             
 *  output_string       [?]             
 *  out_len             [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
BOOL mmi_phb_quick_search_convert_to_spelling(U8* input_string, U8* output_string, U8* out_len) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    U16 code;
    U16 mode;
    U16 buf[MMI_PHB_CONVERT_BUFF_ZI];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode = MMI_current_input_mode;
    switch (mode)
    {	
        case INPUT_MODE_MMI_MULTITAP_BPMF:
        case INPUT_MODE_MMI_MULTITAP_PINYIN:
        case INPUT_MODE_MMI_SM_STROKE:
        case INPUT_MODE_MMI_TR_STROKE:				        		
            break;

        default:
            *out_len = 0;
            return FALSE;
    }

    if ((input_string[0] == 0) && (input_string[1] == 0))
    {
        *out_len = 0;
        return FALSE;
    }

    memcpy(&code, input_string, 2);
    count = CstarQueryCharInfo(code, buf, MMI_PHB_CONVERT_BUFF_ZI, mode);
    if (count == 0)
    {
        memcpy(output_string, input_string, 2);
        *out_len = 1;
        return TRUE;
    }

    if (count > 7)
        count = 7;
    memcpy(output_string, buf, sizeof(U16) * count);
    *out_len = (U8)count;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_cache
 * DESCRIPTION
 *  This function convert first character of name field into cache.
 * PARAMETERS
 *  index       [IN]        Phonebook entry index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_convert_cache(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    U16 code;
    U16 mode;
    U16 buf[MMI_PHB_CONVERT_BUFF_ZI];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode = MMI_current_input_mode;
	switch (mode)
    {   
        case INPUT_MODE_MMI_MULTITAP_BPMF:
        case INPUT_MODE_MMI_MULTITAP_PINYIN:
        case INPUT_MODE_MMI_SM_STROKE:
        case INPUT_MODE_MMI_TR_STROKE:                              
            break;

        default:
            if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
            {
                memcpy(&g_phb_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
            }
            else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
            {
                memcpy(&g_phb_generic_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
            }
            else
            {
                ASSERT(0);
            }
            return;
    }

    memcpy(&code, PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
    count = CstarQueryCharInfo(code, buf, MMI_PHB_CONVERT_BUFF_ZI, mode);
    if (count == 0)
    {
        if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
        {
            memcpy(&g_phb_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
        }
        else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
        {
            memcpy(&g_phb_generic_qsearch_cache[index], PhoneBook[g_phb_name_index[index]].alpha_id.name, 2);
        }
        else
        {
            ASSERT(0);
        }
        return;
    }

    if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
    {
        g_phb_qsearch_cache[index] = buf[0];
    }
    else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
    {
        g_phb_generic_qsearch_cache[index] = buf[0];    
    }
    else
    {
        ASSERT(0);
    }
}


#elif defined(__MMI_ITAP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* No default input method library */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_to_spelling
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  input_string        [?]             
 *  output_string       [?]             
 *  out_len             [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
BOOL mmi_phb_quick_search_convert_to_spelling(U8 *input_string, U8 *output_string, U8 *out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(output_string, input_string, 2);
    *out_len = 1;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_convert_cache
 * DESCRIPTION
 *  This function convert first character of name field into cache.
 * PARAMETERS
 *  index       [IN]        Phonebook entry index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_convert_cache(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
    {
        g_phb_qsearch_cache[index] = (U16) PhoneBook[g_phb_name_index[index]].alpha_id.name[0];
    }
    else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
    {
        g_phb_generic_qsearch_cache[index] = (U16) PhoneBook[g_phb_name_index[index]].alpha_id.name[0];
    }
    else
    {
        ASSERT(0);
    }
}

#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_make_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_make_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U16 pre_store_index;
    U16 store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_T9__)
    /* Switch to the proper input language, only for T9 */
    switch (MMI_current_input_mode)
    {
    #if defined(__MMI_T9_TR_CHINESE__)
        case INPUT_MODE_MMI_MULTITAP_BPMF:
            T9ChangeLanguageToTRChineseBoPoMo();
            break;
        case INPUT_MODE_MMI_TR_STROKE:
            T9ChangeLanguageToTRChineseStroke();
            break;
    #endif /* defined(__MMI_T9_TR_CHINESE__) */ 
    #if defined(__MMI_T9_SM_CHINESE__)
        case INPUT_MODE_MMI_MULTITAP_PINYIN:
            T9ChangeLanguageToSMChinesePinYin();
            break;
        case INPUT_MODE_MMI_SM_STROKE:
            T9ChangeLanguageToSMChineseStroke();
            break;
    #endif /* defined(__MMI_T9_SM_CHINESE__) */ 

        default:
            break;
    }
#endif /* defined(__MMI_T9__) */ 

    /* Begin to convert first character of name field to associated input method string. */
    for (index = 0; index < PhoneBookEntryCount; index++)
    {
        store_index = g_phb_name_index[index];

        if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name) > 0)
        {
            /* The Entry Name is an UCS2 string */
            if (PhoneBook[store_index].alpha_id.name_dcs == PHB_UCS2)
            {
                if (index != 0)
                {
                    pre_store_index = g_phb_name_index[index - 1];

                    /* If character is the same, do not convert again. */
                    if ((PhoneBook[pre_store_index].alpha_id.name[0] == PhoneBook[store_index].alpha_id.name[0]) &&
                        (PhoneBook[pre_store_index].alpha_id.name[1] == PhoneBook[store_index].alpha_id.name[1]))
                    {
                        if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                        {
                            g_phb_qsearch_cache[index] = g_phb_qsearch_cache[index - 1];
                        }
                        else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                        {
                            g_phb_generic_qsearch_cache[index] = g_phb_generic_qsearch_cache[index - 1];
                        }
                        else
                        {
                            ASSERT(0);
                        }
                        continue;
                    }
                }

                mmi_phb_quick_search_convert_cache(index);
            }
            else
                /* This is an ASCII string */
            {
                if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
                {
                    g_phb_qsearch_cache[index] = (U16) PhoneBook[store_index].alpha_id.name[0];
                }
                else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
                {
                    g_phb_generic_qsearch_cache[index] = (U16) PhoneBook[store_index].alpha_id.name[0];
                }
                else
                {
                    ASSERT(0);
                }
            }
        }
        /* The name field is Empty */
        else
        {
            if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
            {
                g_phb_qsearch_cache[index] = 0x0000;
            }
            else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
            {
                g_phb_generic_qsearch_cache[index] = 0x0000;
            }
            else
            {
                ASSERT(0);
            }
        }
    }

    if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
    {
        g_phb_qsearch_is_cache = 1; /* Convert cache done */
    }
    else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
    {
        g_phb_generic_qsearch_is_cache = 1; /* Convert cache done */
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_find_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyword     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_phb_quick_search_find_entry(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key_length;
    U8 flag;
    U16 i;
    U16 code1, code2;
    U16 result_count;

    U8 same_count;
    U8 convert_result;
    S32 distance;
    S8 *string1, *string2 = NULL;
    S8 convert_string[22 * ENCODING_LENGTH];    /* 7*3 + 1 => (char1 + char2 + char3 + Null Terminator) */
    U8 char1[7 * ENCODING_LENGTH];              /* Cache 1st character convert result */
    U8 char2[7 * ENCODING_LENGTH];              /* Cache 2nd character convert result */
    U8 char3[7 * ENCODING_LENGTH];              /* Cache 3rd character convert result */
    U8 len1, len2, len3;
    U16 store_index;
    U8 prev_ucs2 = 0;                           /* Is previous record ucs2 encoding */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if cache already build up before using */
    if ((g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN && !g_phb_qsearch_is_cache) || 
        (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC && !g_phb_generic_qsearch_is_cache))
    {
        StopTimer(PHB_QUICK_SEARCH_TIMER);
        mmi_phb_quick_search_make_cache();
    }

    /* Count the input string length to decide behavior */
    key_length = (U8) mmi_ucs2strlen((S8*) keyword);
    result_count = 0;

    /* For each entry, check if it is in the quick search sub-list */
    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        flag = FALSE;
        store_index = g_phb_name_index[i];
        /*
         * search length == 1, compare whole list with first character only.
         */
        if (key_length == 1)
        {
            if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
            {
                code1 = (U16) g_phb_qsearch_cache[i];
            }
            else //if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
            {
                code1 = (U16) g_phb_generic_qsearch_cache[i];
            }
            memcpy(&code2, keyword, 2);

            if (mmi_phb_compare_chars(code1, code2) == 0)
            {
                flag = TRUE;
            }
        }
        /*
         * search length > 1, compare subset list with maximum search character.
         */
        else if (key_length > 1)
        {
            if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
            {
                code1 = (U16) g_phb_qsearch_cache[i];
            }
            else //if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
            {
                code1 = (U16) g_phb_generic_qsearch_cache[i];
            }
            memcpy(&code2, keyword, 2);

            /* Compare character in cache first. If match, compare the rest part. */
            if (mmi_phb_compare_chars(code1, code2) == 0)
            {
                flag = FALSE;

                if (PhoneBook[store_index].alpha_id.name_dcs == MMI_PHB_UCS2)
                {
                    /* Use previous record convert result as cache */
                    if (i != 0)
                    {
                        string2 = (S8*) PhoneBook[g_phb_name_index[i - 1]].alpha_id.name;
                    }

                    /* Current record */
                    string1 = (S8*) PhoneBook[store_index].alpha_id.name;

                    /*
                     *  Convert 1st character
                     */
                    if ((i != 0) && (string2[0] == string1[0]) && (string2[1] == string1[1]) && prev_ucs2)
                    {
                        convert_result = 10;    /* Use 10 to represent that first character is the same as previous one */
                    }
                    else
                    {
                        U16 code;

                        memcpy(&code, &PhoneBook[store_index].alpha_id.name[0], 2);
                        if ((code >= 0x4e00) && (code <= 0x9fa5))
                        {
                            convert_result = mmi_phb_quick_search_convert_to_spelling(
                                                &PhoneBook[store_index].alpha_id.name[0],
                                                char1,
                                                &len1);
                        }
                        else
                        {
                            convert_result = FALSE;
                        }
                    }

                    if (convert_result)
                    {
                        memset(convert_string, 0, 22 * ENCODING_LENGTH);        /* Clear String in advance, to make sure there will be terminator */

                        len1 = (len1 > 7) ? 7 : len1;
                        memcpy(convert_string, char1, (len1 * ENCODING_LENGTH));

                        /*
                         *  Convert 2nd Character
                         */
                        if (len1 < key_length)
                        {
                            if ((convert_result == 10) && (string2[2] == string1[2]) && (string2[3] == string1[3]) &&
                                prev_ucs2)
                            {
                                convert_result = 20;    /* Use 20 to represent that second character is the same as previous one */
                            }
                            else
                            {
                                convert_result = mmi_phb_quick_search_convert_to_spelling(
                                                    &PhoneBook[store_index].alpha_id.name[2],
                                                    char2,
                                                    &len2);
                            }

                            if (convert_result)
                            {
                                len2 = (len2 > 7) ? 7 : len2;
                                memcpy((convert_string + len1 * ENCODING_LENGTH), char2, (len2 * ENCODING_LENGTH));

                                /*
                                 *  Convert 3rd Character
                                 */
                                if ((len1 + len2) < key_length)
                                {
                                    if ((convert_result == 20) && (string2[4] == string1[4]) &&
                                        (string2[5] == string1[5]) && prev_ucs2)
                                    {
                                        convert_result = 30;    /* Use 30 to represent that third character is the same as previous one */
                                    }
                                    else
                                    {
                                        convert_result = mmi_phb_quick_search_convert_to_spelling(
                                                            &PhoneBook[store_index].alpha_id. name[4],
                                                            char3,
                                                            &len3);
                                    }

                                    if (convert_result)
                                    {
                                        len3 = (len3 > 7) ? 7 : len3;
                                        memcpy(
                                            (convert_string + (len1 + len2) * ENCODING_LENGTH),
                                            char3,
                                            (len3 * ENCODING_LENGTH));
                                    }
                                    else
                                    {
                                        memcpy(
                                            (convert_string + len1 * ENCODING_LENGTH),
                                            &PhoneBook[store_index].alpha_id.name[4],
                                            2);
                                    }
                                }
                            }
                            else
                            {
                                memcpy(
                                    (convert_string + len1 * ENCODING_LENGTH),
                                    &PhoneBook[store_index].alpha_id.name[2],
                                    2);
                            }
                        }

                        /* Chinese convert successfully, use convert result to compare */
                        string1 = convert_string;
                        prev_ucs2 = 1;
                    }
                    else    /* Not Chinese */
                    {
                        string1 = (S8*) PhoneBook[store_index].alpha_id.name;
                        prev_ucs2 = 0;
                    }
                }
                else    /* ASCII */
                {
                    string1 = (S8*) PhoneBook[store_index].alpha_id.name;
                    prev_ucs2 = 0;
                }

                mmi_phb_compare_ucs2_strings((S8*) string1, (S8*) keyword, &same_count, &distance);

                if (same_count == key_length)
                {
                    flag = TRUE;
                }
            }
        }
        /*
         *search length == 0, display whole list.
         */
        else
        {
            flag = TRUE;
        }

        /* Add to list if entry is a subset of a quick search result */
        if (flag)
        {
            /* g_phb_qsearch[i] = 1; */
            if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
            {
                g_phb_qsearch_bitmask[i >> BYTE_SIZE_SHIFT_ARITHMETIC] |= 1 << (i % BYTE_SIZE);
                result_count++;
            }
            else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
            {
                g_phb_generic_qsearch_bitmask[i >> BYTE_SIZE_SHIFT_ARITHMETIC] |= 1 << (i % BYTE_SIZE);
                if (PhoneBook[store_index].field & phb_list_view_type)
                {
                    g_phb_cntx.list_filter[result_count] = store_index;
                    result_count++;
                }
            }
            else
            {
                ASSERT(0);
            }
        }
        else
        {
            /* g_phb_qsearch[i] = 0; */
            if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
            {
                g_phb_qsearch_bitmask[i >> BYTE_SIZE_SHIFT_ARITHMETIC] &= (kal_uint8) (~(1 << (i % BYTE_SIZE)));
            }
            else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
            {
                g_phb_generic_qsearch_bitmask[i >> BYTE_SIZE_SHIFT_ARITHMETIC] &= (kal_uint8) (~(1 << (i % BYTE_SIZE)));
            }
            else
            {
                ASSERT(0);
            }
        }
    }

    if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_MAIN)
    {
        if (result_count == 0)  /* Clear send key when no entry found */
        {
            ClearKeyHandler(KEY_SEND, KEY_EVENT_UP);
        #if defined(__MMI_INTELLIGENT_CALL_ALERT__)
            StopTimer(PHB_LIST_SPEAK_NAME_TIMER);
            if (g_phb_is_speaking_name)
            {
                mdi_audio_stop_string();
            }
        #endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 
        }
        else
        {
	#ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_PFAL_CC_HandleSendKeys(mmi_phb_list_pre_choose_number,KEY_EVENT_UP);
	#else	/* __MMI_DUAL_SIM_MASTER__ */
            SetKeyHandler(mmi_phb_list_pre_choose_number, KEY_SEND, KEY_EVENT_UP);
	#endif	/* __MMI_DUAL_SIM_MASTER__ */     
        }
    }
    else if (g_phb_quick_search_enter == MMI_PHB_QUICK_SEARCH_GENERIC)
    {
        if (result_count == 0)  /* Clear send key when no entry found */
        {
            ClearKeyHandler(KEY_SEND, KEY_EVENT_UP);
        }
    }
    else
    {
        ASSERT(0);
    }

    return result_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_get_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_get_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        /* if(g_phb_qsearch[i] == 1) */
        if (g_phb_qsearch_bitmask[i >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (i % BYTE_SIZE)))
        {
            if (count == nIndex)
            {
                break;
            }
            count++;
        }
    }

    g_phb_cntx.active_index = i;

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    StopTimer(PHB_LIST_SPEAK_NAME_TIMER);
    if (g_phb_is_speaking_name)
    {
        mdi_audio_stop_string();
    }

    if (g_phb_cntx.speak_name)
    {
        StartTimer(PHB_LIST_SPEAK_NAME_TIMER, UI_POPUP_NOTIFYDURATION_TIME, mmi_phb_list_speak_name);
    }
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_list_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
    else
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif/* __MMI_DUAL_SIM_MASTER__ */
    {
        if (PhoneBookEntryCount)
        {
            g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_MAIN;
            mmi_phb_entry_quick_search_list();
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NO_ENTRIES_MESSAGE),
                IMG_GLOBAL_EMPTY,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                EMPTY_LIST_TONE);
        }
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_quick_search_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_quick_search_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 entryCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_PHB_QUICK_SEARCH_LIST,
        mmi_phb_exit_quick_search_list,
        mmi_phb_quick_search_list_pre_entry,
        MMI_FULL_SCREEN);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_QUICK_SEARCH_LIST);
    RegisterHighlightHandler(mmi_phb_quick_search_get_index);

    RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry);

    /* First Time enter or any entry has been modified.. */
    if ((guiBuffer == NULL) || (g_phb_cntx.refresh_list == MMI_PHB_ENTRY_REFRESH))
    {
        g_phb_cntx.highlight_entry = 0;
        memset(g_phb_qsearch_input, 0, ENCODING_LENGTH);
        // memset(g_phb_qsearch,1,MAX_PB_ENTRIES);  /*All records are in the subset at the beginning*/
        memset(g_phb_qsearch_bitmask, 0xff, (MAX_PB_ENTRIES + 7) / 8);

        entryCount = PhoneBookEntryCount;
        guiBuffer = NULL;
        g_phb_cntx.refresh_list = MMI_PHB_ENTRY_QSEARCH;    /* '2' is used only for this screen. */
    }
    else
    {
        entryCount = (U16) mmi_phb_quick_search_find_entry(g_phb_qsearch_input);
    }

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    set_force_icon_on_highlight_only_in_menuitem();
#endif 
    ShowCategory200Screen(
        STR_SCR_PBOOK_VIEW_CAPTION,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        entryCount,
        mmi_phb_quick_search_list_get_item,
        mmi_phb_quick_search_list_get_hint,
        g_phb_cntx.highlight_entry,
        IMG_ID_PHB_QUICK_SEARCH_FIND,
        (U8*) g_phb_qsearch_input,
        MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
        guiBuffer);

    SetCategory200RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    SetCategory200LeftSoftkeyFunction(mmi_phb_entry_quick_search_option, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_phb_entry_quick_search_option, KEY_EVENT_UP);
#else /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
    SetCategory200LeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
 
    if (entryCount > 0)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        MTPNP_PFAL_CC_HandleSendKeys(mmi_phb_list_pre_choose_number,KEY_EVENT_UP);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(mmi_phb_list_pre_choose_number, KEY_SEND, KEY_EVENT_UP);
    #endif /* __MMI_DUAL_SIM_MASTER__ */ 
    }
    //MTK Elvis 20040517--it is incorrect to regist RSK here
    //SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

    /* Make cache according to the current input method, after input method initialized in ShowCategoryScreen. */
    if (guiBuffer == NULL)
    {
        g_phb_qsearch_is_cache = 0;
        mmi_phb_quick_search_make_cache();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_quick_search_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_quick_search_list(void)
{
#if defined(__MMI_PHB_RSK_QUICK_SEARCH__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.ToNameScrFromIdleApp)
    {
        g_phb_cntx.start_scr_id = SCR_ID_PHB_QUICK_SEARCH_LIST;
    }
    g_phb_cntx.end_scr_id = SCR_ID_PHB_QUICK_SEARCH_LIST;

    g_idle_context.ToNameScrFromIdleApp = 0;
    g_idle_context.RskPressedFromIdleApp = 0;

    StopTimer(KEYPAD_LOCK_TIMER);
#endif /* defined(__MMI_PHB_RSK_QUICK_SEARCH__) */ 

#ifdef __MMI_PHB_QUICK_SEARCH__
    g_phb_cntx.end_scr_id = SCR_ID_PHB_QUICK_SEARCH_LIST;
#endif /* __MMI_PHB_QUICK_SEARCH__ */

#if defined(__MMI_VRSD_DIAL__)
    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);
#endif 

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    StopTimer(PHB_LIST_SPEAK_NAME_TIMER);
    if (g_phb_is_speaking_name)
    {
        mdi_audio_stop_string();
    }
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_phb_quick_search_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, count, store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        /* if(g_phb_qsearch[i] == 1) */
        if (g_phb_qsearch_bitmask[i >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (i % BYTE_SIZE)))
        {
            if (count == item_index)
            {
                break;
            }
            count++;
        }
    }

    store_index = g_phb_name_index[i];
    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name))
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) PhoneBook[store_index].alpha_id.name);
    }
    else
    {
        mmi_phb_convert_get_ucs2_number((S8*) str_buff, store_index);
    }

#ifdef	__MMI_DUAL_SIM_MASTER__
    if(store_index >= (MAX_PB_PHONE_ENTRIES + MAX_PB_SIM_ENTRIES))
    {
        *img_buff_p = get_image(IMG_ID_CARD2_PHB_STORAGE_SIM);
    }
    else if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_ID_CARD1_PHB_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (store_index >= MAX_PB_PHONE_ENTRIES)    /* In SIM */
    {
        *img_buff_p = get_image(IMG_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_phb_quick_search_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, count, store_index;
    S8 temp_number[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    for (i = 0; i < PhoneBookEntryCount; i++)
    {
        /* if(g_phb_qsearch[i] == 1) */
        if (g_phb_qsearch_bitmask[i >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (i % BYTE_SIZE)))
        {
            if (count == item_index)
            {
                break;
            }
            count++;
        }
    }

    store_index = g_phb_name_index[i];
    mmi_phb_convert_get_ucs2_number((S8*) temp_number, store_index);

    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name) && mmi_ucs2strlen((S8*) temp_number))
    {
        mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_number);
    }
    else
    {
        return 0;
    }

    return 1;   /* One hint data only, can be more hints. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_change_input_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_change_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // memset(g_phb_qsearch,1,MAX_PB_ENTRIES);  /*All records are in the subset at the beginning*/
    if (GetActiveScreenId() == SCR_ID_PHB_QUICK_SEARCH_LIST)
    {
        memset(g_phb_qsearch_bitmask, 0xff, (MAX_PB_ENTRIES + 7) / 8);
        g_phb_qsearch_is_cache = 0;

        /*
         * Make cache according to the current input method.
         * Start a timer to avoid convert cache each time when user change input method quickly.
         */
        StopTimer(PHB_QUICK_SEARCH_TIMER);
        StartTimer(PHB_QUICK_SEARCH_TIMER, 500, mmi_phb_quick_search_make_cache);
    }
    else if (GetActiveScreenId() == SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST)	
    {
        memset(g_phb_generic_qsearch_bitmask, 0xff, (MAX_PB_ENTRIES + 7) / 8);
        g_phb_generic_qsearch_is_cache = 0;

        /*
         * Make cache according to the current input method.
         * Start a timer to avoid convert cache each time when user change input method quickly.
         */
        StopTimer(PHB_QUICK_SEARCH_TIMER);
        StartTimer(PHB_QUICK_SEARCH_TIMER, 500, mmi_phb_quick_search_make_cache);
    }    
}

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
extern void EntryQuickSearchInputMethodScreen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_quick_search_go_back_editor
 * DESCRIPTION
 *  Go back screen after change input method.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_quick_search_go_back_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_PHB_QUICK_SEARCH_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_quick_search_input_method
 * DESCRIPTION
 *  Highlight function to enter change input method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_quick_search_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryQuickSearchInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryQuickSearchInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    RegisterInputMethodScreenCloseFunction(mmi_phb_quick_search_go_back_editor);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_highlight_quick_search_op_option
 * DESCRIPTION
 *  Highlight function to enter entry option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_highlight_quick_search_op_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_op_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_op_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_quick_search_option
 * DESCRIPTION
 *  Entry function of phonebook quick search option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_quick_search_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];   /* Need Expand when has more options. */
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_PHB_QUICK_SEARCH_OPTION,
        mmi_phb_exit_quick_search_option,
        mmi_phb_entry_quick_search_option,
        NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_QUICK_SEARCH_OPTION);
    nNumofItem = GetNumOfChild(MENU_ID_PHB_QUICK_SEARCH_OPTION);
    GetSequenceStringIds(MENU_ID_PHB_QUICK_SEARCH_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_QUICK_SEARCH_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_quick_search_option
 * DESCRIPTION
 *  Exit function of phonebook quick search option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_exit_quick_search_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_QUICK_SEARCH_OPTION;
}
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 
#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */


#define MMI_PHB_UTIL_SEARCH
/*---------------------------------------------------- General Compare String Functions -------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_char_towupper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wChar       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_phb_char_towupper(U16 wChar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((wChar >= 0x61&& wChar <= 0x7A) || (wChar >= 0xe0 && wChar <= 0xf6) || (wChar >= 0xf8 && wChar <= 0xfe) ||
        (wChar >= 0x0430 && wChar <= 0x044f) || (wChar >= 0x03B1 && wChar <= 0x03C1) || (wChar >= 0x03C3 && wChar <= 0x03CA))
    {
        return (wChar - 0x20);
    }
    else if (wChar == 0x0103 || wChar == 0x01A1 || wChar == 0x01B0 || wChar == 0x0188 || wChar == 0x018C || wChar == 0x0192 ||
                wChar == 0x01AC || wChar == 0x01B9 || wChar == 0x01F3)
    {
        return (wChar - 1);
    }
    else if (wChar >= 0x0450 && wChar <= 0x045f)
    {
        return (wChar - 0x50);
    }
    else if (wChar == 0x0491)
    {
        return 0x0490;
    }
    else if (wChar >= 0x0100 && wChar <= 0x0137 || wChar >= 0x0182 && wChar <= 0x0185 ||
                wChar >= 0x0198 && wChar <= 0x01A5 || wChar >= 0x01DE && wChar <= 0x01EF ||
                wChar >= 0x01F8 && wChar <= 0x01FF || wChar >= 0x0222 && wChar <= 0x0233)
    {
        if ((wChar & 1) == 1) /* odd is small case */
            return wChar - 1;
        else
            return wChar;
    }
    else if (wChar >= 0x0139 && wChar <= 0x0148 || wChar >= 0x014A && wChar <=0x0177 || wChar >= 0x0179 && wChar <=0x017E ||
                wChar >= 0x01B3 && wChar <= 0x01B6 || wChar >= 0x02CD && wChar <= 0x01DC)
    {
        if ((wChar & 1) == 0) /* even is small case */
            return wChar - 1;
        else
            return wChar;
    }
    else
    {
        return wChar;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_compare_chars
 * PARAMETERS
 *  char1       [IN]        
 *  char2       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_phb_compare_chars(U16 char1, U16 char2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 char1_upper = mmi_phb_char_towupper(char1);
    U16 char2_upper = mmi_phb_char_towupper(char2);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* try UCS2 matching */
    if (char1 == char2 || char1_upper == char2_upper)
    {
        return 0;
    }

    /* if not, try ASCII case-insensitive matching */
    else if ((char1 < 0x007E) && (char2 < 0x007E))
    {
        if ((char1 <= 0x007a) && (char1 >= 0x0061))
        {
            char1 -= 0x20;
        }
        if ((char2 <= 0x007a) && (char2 >= 0x0061))
        {
            char2 -= 0x20;
        }

        return char1 - char2;
    }

    /* no match */
    return char1 - char2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_compare_ucs2_strings
 * PARAMETERS
 *  string1         [?]     
 *  string2         [?]     
 *  same_count      [?]     
 *  distance        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_compare_ucs2_strings(S8 *string1, S8 *string2, U8 *same_count, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 len1, len2;
    U8 max_len, min_len;
    U8 i;
    U16 code1, code2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *same_count = 0;
    *distance = 0;

    len1 = (U8) mmi_ucs2strlen(string1);
    len2 = (U8) mmi_ucs2strlen(string2);

    if (len1 > len2)
    {
        max_len = len1;
        min_len = len2;
    }
    else
    {
        max_len = len2;
        min_len = len1;
    }

    for (i = 0; i < max_len && i < MAX_PB_EMAIL_LENGTH; i++)    /* Use Max Phonebook Strlen as upper bound */
        /* for (i = 0; i < max_len; i++) */
    {
        /* If all characters are identical from 0 to min_len. */
        if (i >= min_len)
        {
            /* First is greater than second */
            if (len1 > len2)
            {
                *distance = (U16) string1[i * ENCODING_LENGTH];
            }
            /* First and second is congruence */
            else if (len1 == len2)
            {
                *distance = 0;
            }
            /* len1 < len2: First is less than second */
            else
            {
                *distance = -(U16) string2[i * ENCODING_LENGTH];
            }

            //if (min_len == 0)
            //     *distance = - *distance;

            break;
        }

        /* First, compare from 0 to min_len */
        else
        {
            memcpy(&code1, (string1 + i * ENCODING_LENGTH), 2);
            memcpy(&code2, (string2 + i * ENCODING_LENGTH), 2);

            if ((*distance = mmi_phb_compare_chars(code1, code2)) == 0)
            {
                *same_count = *same_count + 1;
            }
            /* First and second is not equal, return distance */
            else
            {
                break;
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_compare_ascii_strings
 * PARAMETERS
 *  string1         [?]     > string2 ; <0 if sting1 < string2
 *  string2         [?]     
 *  same_count      [?]     
 *  distance        [?]     
 *****************************************************************************/
void mmi_phb_compare_ascii_strings(S8 *string1, S8 *string2, U16 *same_count, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len1, len2;
    U16 max_len, min_len;
    U16 i;
    U16 code1, code2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *same_count = 0;
    *distance = 0;

    len1 = strlen(string1);
    len2 = strlen(string2);

    if (len1 > len2)
    {
        max_len = len1;
        min_len = len2;
    }
    else
    {
        max_len = len2;
        min_len = len1;
    }

    for (i = 0; i < max_len; i++)
    {
        if (i >= min_len)   /* If all characters are identical from 0 to min_len. */
        {
            if (len1 > len2)    /* First is greater than second */
            {
                *distance = (U16) string1[i];
            }
            else if (len1 == len2)  /* First and second is congruence */
            {
                *distance = 0;
            }
            else    /* len1 < len2: First is less than second */
            {
                *distance = -(U16) string2[i];
            }

            if (min_len == 0)
            {
                *distance = -*distance;
            }
            break;
        }
        else    /* First, compare from 0 to min_len */
        {
            code1 = (U16) string1[i];
            code2 = (U16) string2[i];

            if ((*distance = mmi_phb_compare_chars(code1, code2)) == 0)
            {
                *same_count = *same_count + 1;
            }
            else    /* First and second is not equal, return distance */
            {
                break;
            }
        }
    }
}

#if defined(__MMI_PHB_PINYIN_SORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_make_pinyin_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_util_make_pinyin_cache(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((PhoneBook[store_index].alpha_id.name_length != 0) &&
        (PhoneBook[store_index].alpha_id.name_dcs != MMI_PHB_ASCII))
    {
        count = mmi_phb_util_convert_to_pinyin(
                    PhoneBook[store_index].alpha_id.name,
                    &g_phb_name_pinyin_index[store_index][0],
                    MMI_PHB_SORT_LENGTH * ENCODING_LENGTH);
        g_phb_name_pinyin_index[store_index][count++] = 0x00;
        g_phb_name_pinyin_index[store_index][count++] = 0x00;
    }
    else
    {
        memset(&g_phb_name_pinyin_index[store_index][0], 0, 2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_get_pinyin_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  pinyin_ptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_util_get_pinyin_cache(U16 store_index, U8 **pinyin_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pinyin_ptr = &g_phb_name_pinyin_index[store_index][0];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_convert_to_pinyin
 * DESCRIPTION
 *  This function convert the input string into Chinese Pinyin string according to the library
 *  Between each pinyin string result, it will append the original encoding to seperate two
 *  Chinese pinyin result.
 * PARAMETERS
 *  inputString         [?]         The input string buffer in ucs2 format.
 *  outputString        [?]         The output string buffer, it will be ucs2 format
 *  out_length          [IN]        The output string buffer size, in bytes.
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_T9__)
#if defined(__MMI_T9_V7__)
U16 mmi_phb_util_convert_to_pinyin(U8 *inputString, U8 *outputString, U16 out_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9STATUS t9ReturnCodes;
    U8 i, out = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    T9ChangeLanguageToSMChinesePinYin();

    while (!((*inputString == 0) && (*(inputString + 1) == 0)) && ((out + 1) < out_length))
    {
        t9ReturnCodes = T9CCGetCharSpell(&FieldInfo.CCFieldInfo, (U16*) inputString, 0);

        if (t9ReturnCodes == 0) /* (code >= 0x4e00) && (code <= 0x9fa5) */
        {
            i = 0;
            while ((FieldInfo.CCFieldInfo.pbSpellBuf[i] != 0x00) && ((out + 1) < out_length))
            {
                outputString[out++] = FieldInfo.CCFieldInfo.pbSpellBuf[i++];
                outputString[out++] = 0x00;
            }
        }

        /* Add character encoding beetween pinyin strings */
        if ((out + 1) < out_length)
        {
            outputString[out++] = inputString[0];
            outputString[out++] = inputString[1];
        }

        inputString += 2;
    }

    return out;
}
#else /* defined(__MMI_T9_V7__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_convert_to_pinyin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputString         [?]         
 *  outputString        [?]         
 *  out_length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_phb_util_convert_to_pinyin(U8 *inputString, U8 *outputString, U16 out_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    T9Event t9EventInput;
    T9STATUS t9ReturnCodes;
    U8 i, out = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    T9ChangeLanguageToSMChinesePinYin();

    while (!((*inputString == 0) && (*(inputString + 1) == 0)) && ((out + 1) < out_length))
    {
        t9EventInput.mType = T9EVTSPELLING;
        t9EventInput.data.sLDBData.psBuf = (U16*) inputString;
        t9EventInput.data.sLDBData.mCtrlID = 0;
        t9ReturnCodes = T9HandleEvent(&FieldInfo, &t9EventInput);

        if (t9ReturnCodes == 0) /* (code >= 0x4e00) && (code <= 0x9fa5) */
        {
            i = 0;
            while ((FieldInfo.uLangData.pAuxChinese->pbSpellBuf[i] != 0x00) && ((out + 1) < out_length))
            {
                outputString[out++] = FieldInfo.uLangData.pAuxChinese->pbSpellBuf[i++];
                outputString[out++] = 0x00;
            }
        }

        /* Add character encoding beetween pinyin strings */
        if ((out + 1) < out_length)
        {
            outputString[out++] = inputString[0];
            outputString[out++] = inputString[1];
        }

        inputString += 2;
    }

    return out;
}
#endif /* defined(__MMI_T9_V7__) */ 
#elif defined(__MMI_ZI__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_convert_to_pinyin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputString         [?]         
 *  outputString        [?]         
 *  out_length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_phb_util_convert_to_pinyin(U8 *inputString, U8 *outputString, U16 out_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, out = 0;
    U16 code;
    U16 pCharInfoBuffer[MMI_PHB_CONVERT_BUFF_ZI];
    U16 PinYin_Base = ZI8_BASE_PINYIN - 0x0061;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*inputString == 0) && (*(inputString + 1) == 0)) && ((out + 1) < out_length))
    {
        memcpy(&code, inputString, 2);

        if ((code >= 0x4e00) && (code <= 0x9fa5) &&
            Zi8GetCharInfo(code, (U16*) pCharInfoBuffer, MMI_PHB_CONVERT_BUFF_ZI, ZI8_GETMODE_PINYIN))
        {
            i = 0;
            while ((pCharInfoBuffer[i] != 0x0000) && (out < out_length) && ((pCharInfoBuffer[i] < ZI8_CODE_TONES_1) || (pCharInfoBuffer[i] > ZI8_CODE_TONES_5)))    /* No tone needed */
            {
                outputString[out++] = (U8) (pCharInfoBuffer[i++] - PinYin_Base);
                outputString[out++] = 0x00;
            }
        }

        /* Add character encoding beetween pinyin strings */
        if ((out + 1) < out_length)
        {
            outputString[out++] = inputString[0];
            outputString[out++] = inputString[1];
        }

        inputString += 2;
    }

    return out;
}

#elif defined (__MMI_CSTAR__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_convert_to_pinyin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputString         [?]         
 *  outputString        [?]         
 *  out_length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_phb_util_convert_to_pinyin(U8* inputString, U8* outputString, U16 out_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, out = 0;
    U16 code;
    U16 buf[MMI_PHB_CONVERT_BUFF_ZI];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ( !((inputString[0] == 0) && (inputString[1] == 0)) && (out + 1 < out_length) )
    {
        memcpy(&code, inputString, 2);

        if (CstarQueryCharInfo(code, buf, MMI_PHB_CONVERT_BUFF_ZI, INPUT_MODE_MMI_MULTITAP_PINYIN) > 0)
        {
            i = 0;
            while ((buf[i] != 0) && (out < out_length))
            {
                outputString[out++] = (U8)(buf[i++]);
                outputString[out++] = 0x00; 
            }
        }

        if (out + 1 < out_length)
        {
            outputString[out++] = inputString[0];
            outputString[out++] = inputString[1];
        }
            
        inputString += 2;
    }

    return out;
}

#elif defined(__MMI_ITAP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_convert_to_pinyin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inputString         [?]         
 *  outputString        [?]         
 *  out_length          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_phb_util_convert_to_pinyin(U8 *inputString, U8 *outputString, U16 out_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((S8*) outputString, (S8*) inputString, out_length);
    return out_length;
}
#endif 
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 

#define MMI_PHB_LOOKUP_TABLE


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_lookup_table_sort
 * DESCRIPTION
 *  Sorts the look-up table
 *  
 *  This is a fast Quick-Sort as suggested by
 *  Pluto. It will perform insertion sort for
 *  array chunks of size less than 4 and quick
 *  sort for size greater than 4.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_lookup_table_sort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.lookup_table_count)
    {
        /* Set to zero beore sorting, check if this flag larger than phonebook entries to see if finish sorting. */
        g_phb_cntx.populate_count = 0;

        /* Begin to sort. */
        mmi_phb_lookup_table_quicksort(0, (U16) (g_phb_cntx.lookup_table_count - 1));
        mmi_phb_lookup_table_insertionsort(0, (U16) (g_phb_cntx.lookup_table_count - 1));

        /* After sorting, set it to total phonebook entries. */
        g_phb_cntx.populate_count = 0xffff;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_lookup_table_quicksort
 * DESCRIPTION
 *  Sorts the lookup table using quick sort algorithm
 * PARAMETERS
 *  l       [IN]        
 *  r       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_lookup_table_quicksort(U16 l, U16 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U32 pivot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((r - l) > 4)
    {
        i = (r + l) / 2;
        if (LookUpTable[l].number > LookUpTable[i].number)
        {
            mmi_phb_lookup_table_swap_node(l, i);
        }
        if (LookUpTable[l].number > LookUpTable[r].number)
        {
            mmi_phb_lookup_table_swap_node(l, r);
        }
        if (LookUpTable[i].number > LookUpTable[r].number)
        {
            mmi_phb_lookup_table_swap_node(i, r);
        }

        j = r - 1;
        mmi_phb_lookup_table_swap_node(i, j);
        i = l;
        pivot = LookUpTable[j].number;

        for (;;)
        {
            do
            {
            } while (LookUpTable[++i].number < pivot);
            do
            {
            } while (LookUpTable[--j].number > pivot);

            if (j < i)
            {
                break;
            }

            mmi_phb_lookup_table_swap_node(i, j);
        }

        mmi_phb_lookup_table_swap_node(i, (U16) (r - 1));
        mmi_phb_lookup_table_quicksort(l, j);
        mmi_phb_lookup_table_quicksort((U16) (i + 1), r);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_lookup_table_insertionsort
 * DESCRIPTION
 *  Sorts the lookup table using insertion sort algorithm
 * PARAMETERS
 *  lo      [IN]        
 *  hi      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_lookup_table_insertionsort(U16 lo, U16 hi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    MMI_PHB_LOOKUP_NODE_STRUCT elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = lo + 1; i <= hi; ++i)
    {
        memcpy(&elem, &LookUpTable[i], sizeof(MMI_PHB_LOOKUP_NODE_STRUCT));

        j = i;
        while (j > lo)
        {
            if (LookUpTable[j - 1].number <= elem.number)
            {
                break;
            }
            memcpy(&LookUpTable[j], &LookUpTable[j - 1], sizeof(MMI_PHB_LOOKUP_NODE_STRUCT));
            j--;
        }
        memcpy(&LookUpTable[j], &elem, sizeof(MMI_PHB_LOOKUP_NODE_STRUCT));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_lookup_table_swap_node
 * DESCRIPTION
 *  Swaps the look-up table nodes
 * PARAMETERS
 *  i       [IN]        
 *  j       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_lookup_table_swap_node(U16 i, U16 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOOKUP_NODE_STRUCT temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&temp, &LookUpTable[i], sizeof(MMI_PHB_LOOKUP_NODE_STRUCT));
    memcpy(&LookUpTable[i], &LookUpTable[j], sizeof(MMI_PHB_LOOKUP_NODE_STRUCT));
    memcpy(&LookUpTable[j], &temp, sizeof(MMI_PHB_LOOKUP_NODE_STRUCT));
}

/* Advance Search Phone Numbe. For Mobile Field Only!!! */
#if defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_has_extension
 * DESCRIPTION
 *  Find out if a phone number has extension field.
 * PARAMETERS
 *  number      [?]     
 * RETURNS
 *  The position of the first extension character.
 *  Ex. *31#+81234567890p123 => 16
 *****************************************************************************/
U16 mmi_phb_number_has_extension(S8 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp;
    U16 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Ignore *31# and #31# */
    while (((number[0] == '*') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')) ||
           ((number[0] == '#') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')))
    {
        number += 4;
        pos += 4;
    }

    /* Ignore '+' */
    if (number[0] == '+')
    {
        number++;
        pos++;
    }

    /* Find position of first extension character */
    temp = strcspn((PS8) number, "+pw*#");
    if (temp)
    {
        number = number + temp;
        pos = pos + temp;
    }

    /* Check if extension character exists. */
    if (number[0] == '+' || number[0] == 'p' || number[0] == 'w' || number[0] == '*' || number[0] == '#')
    {
        return pos;
    }
    else
    {
        return 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_compare_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number1     [?]     
 *  number2     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_number_compare_extension(S8 *number1, S8 *number2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Ignore *31# and #31# when compare. */
    while (((number1[0] == '*') && (number1[1] == '3') && (number1[2] == '1') && (number1[3] == '#')) ||
           ((number1[0] == '#') && (number1[1] == '3') && (number1[2] == '1') && (number1[3] == '#')))
    {
        number1 += 4;
    }

    while (((number2[0] == '*') && (number2[1] == '3') && (number2[2] == '1') && (number2[3] == '#')) ||
           ((number2[0] == '#') && (number2[1] == '3') && (number2[2] == '1') && (number2[3] == '#')))
    {
        number2 += 4;
    }

    /* Ignore '+' when compare. */
    if (number1[0] == '+')
    {
        number1++;
    }
    if (number2[0] == '+')
    {
        number2++;
    }

    /* Only Compare Extension part. */
    temp = strcspn((PS8) number1, "+pw*#");
    if (temp)
    {
        number1 = number1 + temp;
    }

    temp = strcspn((PS8) number2, "+pw*#");
    if (temp)
    {
        number2 = number2 + temp;
    }

    /* Compare if the number is full match. */
    if (!strcmp((PS8) number1, (PS8) number2))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_compare_before_extension
 * DESCRIPTION
 *  Compare number before extension part
 *  If two numbers are less than 9 digts, do not need to
 *  do extra handling
 * PARAMETERS
 *  number1     [?]     
 *  number2     [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_number_compare_before_extension(S8 *number1, S8 *number2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 len1, len2;
    U16 ext_pos1, ext_pos2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Ignore *31# and #31# */
    while (((number2[0] == '*') && (number2[1] == '3') && (number2[2] == '1') && (number2[3] == '#')) ||
            ((number2[0] == '#') && (number2[1] == '3') && (number2[2] == '1') && (number2[3] == '#')) )
    {
        number2 += 4;
    }

    /* compare length shorter than 9
      if(g_phb_compare_length <= 9)
       return TRUE;
      although already compared when enter this function, still need to confirm the number type
      and need to do more comparation */
    ext_pos1 = mmi_phb_number_has_extension(number1);
    ext_pos2 = mmi_phb_number_has_extension(number2);

    if ((ext_pos1 == 0 && ext_pos2 != 0 && (number2[ext_pos2] == '#' || number2[ext_pos2] == '*'))
        || (ext_pos2 == 0 && ext_pos1 != 0 && (number2[ext_pos1] == '#' || number2[ext_pos1] == '*')))
    {   /* only one with extension '#' or '*'. Not match! */
        return FALSE;
    }
    len1 = (ext_pos1 == 0) ? strlen(number1) : ext_pos1;
    len2 = (ext_pos2 == 0) ? strlen(number2) : ext_pos2;

    if ((len1 < g_phb_compare_length) || (len2 < g_phb_compare_length))
    {
        U16 num_len1 = (number1[0] == '+') ? (len1 - 1) : len1;
        U16 num_len2 = (number2[0] == '+') ? (len2 - 1) : len2;

        if (num_len1 != num_len2)
        {
            return FALSE;
        }
        else    /* the same length except "+" sign */
        {
            for (i = 1; i <= len1 && i <= len2; i++)
            {
                if (number1[len1 - i] != number2[len2 - i])
                {
                    return FALSE;
                }
            }
        }

        return TRUE;
    }

    /* (len1 >= g_phb_compare_length) && (len2 >= g_phb_compare_length) */
    for (i = 1; i <= g_phb_compare_length; i++)
    {
        if (number1[len1 - i] != number2[len2 - i])
        {
            return FALSE;
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_check_full_match_with_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lookup_index        [IN]        
 *  number_in           [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_number_check_full_match_with_extension(U16 lookup_index, S8 *number_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number_buff[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U16 store_index = LookUpTable[lookup_index].store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if mobile field is match */
    if (((PhoneBook[store_index].tel.type & 0x90) == 0x90) && (PhoneBook[store_index].tel.type != 0xFF))
    {
        number_buff[0] = '+';
        mmi_phb_convert_to_digit((U8*) (number_buff + 1), PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    }
    else
    {
        mmi_phb_convert_to_digit(number_buff, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    }

    if (!mmi_phb_number_has_extension((S8*) number_buff) &&
        mmi_phb_number_compare_before_extension(number_in, (S8*) number_buff))
    {
        return TRUE;
    }

#ifdef __MMI_PHB_USIM_FIELD__
    /* Check number in the anr field */
    if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        if (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_ANRA)
        {
            if (((phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].type & 0x90) == 0x90) && (phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].type != 0xFF))
            {
                number_buff[0] = '+';
                mmi_phb_convert_to_digit(
                    (U8*) (number_buff + 1),
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }
            else
            {
                mmi_phb_convert_to_digit(
                    (U8*) number_buff,
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }

            if (!mmi_phb_number_has_extension((S8*) number_buff) &&
                mmi_phb_number_compare_before_extension(number_in, (S8*) number_buff))
            {
                return TRUE;
            }
        }
        if (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_ANRB)
        {
            if (((phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].type & 0x90) == 0x90) && (phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].type != 0xFF))
            {
                number_buff[0] = '+';
                mmi_phb_convert_to_digit(
                    (U8*) (number_buff + 1),
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }
            else
            {
                mmi_phb_convert_to_digit(
                    (U8*) number_buff,
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }

            if (!mmi_phb_number_has_extension((S8*) number_buff) &&
                mmi_phb_number_compare_before_extension(number_in, (S8*) number_buff))
            {
                return TRUE;
            }
        }
        if (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_ANRC)
        {
            if (((phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].type & 0x90) == 0x90) && (phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].type != 0xFF))
            {
                number_buff[0] = '+';
                mmi_phb_convert_to_digit(
                    (U8*) (number_buff + 1),
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }
            else
            {
                mmi_phb_convert_to_digit(
                    (U8*) number_buff,
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }

            if (!mmi_phb_number_has_extension((S8*) number_buff) &&
                mmi_phb_number_compare_before_extension(number_in, (S8*) number_buff))
            {
                return TRUE;
            }
        }
    }
#endif /* __MMI_PHB_USIM_FIELD__ */ 

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    /* Check number in the optional field */
    if ((store_index < MAX_PB_PHONE_ENTRIES) &&
        ((PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_HOME) ||
         (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_OFFICE) ||
         (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_FAX)))
    {
        S16 pError;

        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);

        if (PhoneBook[store_index].field | MMI_PHB_ENTRY_FIELD_HOME)
        {
            if (!mmi_phb_number_has_extension((S8*) PhoneBookOptionalFields.homeNumber) &&
                mmi_phb_number_compare_before_extension(number_in, (S8*) PhoneBookOptionalFields.homeNumber))
            {
                g_phb_cntx.searched_number_type = MMI_PHB_ENTRY_FIELD_HOME;
                return TRUE;
            }
        }
        if (PhoneBook[store_index].field | MMI_PHB_ENTRY_FIELD_OFFICE)
        {
            if (!mmi_phb_number_has_extension((S8*) PhoneBookOptionalFields.officeNumber) &&
                mmi_phb_number_compare_before_extension(number_in, (S8*) PhoneBookOptionalFields.officeNumber))
            {
                g_phb_cntx.searched_number_type = MMI_PHB_ENTRY_FIELD_OFFICE;
                return TRUE;
            }
        }
        if (PhoneBook[store_index].field | MMI_PHB_ENTRY_FIELD_FAX)
        {
            if (!mmi_phb_number_has_extension((S8*) PhoneBookOptionalFields.faxNumber) &&
                mmi_phb_number_compare_before_extension(number_in, (S8*) PhoneBookOptionalFields.faxNumber))
            {
                g_phb_cntx.searched_number_type = MMI_PHB_ENTRY_FIELD_FAX;
                return TRUE;
            }
        }
    }
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_find_first_without_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mid             [IN]        
 *  number          [IN]        
 *  number_in       [?]         
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_phb_number_find_first_without_extension(S16 mid, U32 number, S8 *number_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, new_mid, min_index;
    S16 counter = 0;
    U16 j;
    BOOL is_match = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_mid = mid;
    min_index = MAX_PB_ENTRIES;

    /* Compare number before mid */
    i = mid;
    while ((i >= 0) && (LookUpTable[i].number == number))
    {
        if (mmi_phb_number_check_full_match_with_extension(i, number_in))
        {
            for (j = 0; j < PhoneBookEntryCount; j++)
                if (g_phb_name_index[j] == LookUpTable[i].store_index)
                {
                    is_match = TRUE;
                    break;
                }

            if (j < min_index)
            {
                min_index = j;
                new_mid = i;
            }
        }
        i--;
        counter++;

        if (counter >= MAX_PHB_NUMBER_COMP)
        {
            break;
        }
    }

    /* Compare number after mid */
    i = mid + 1;
    while ((i < g_phb_cntx.lookup_table_count) && (LookUpTable[i].number == number))
    {
        if (mmi_phb_number_check_full_match_with_extension(i, number_in))
        {
            for (j = 0; j < PhoneBookEntryCount; j++)
                if (g_phb_name_index[j] == LookUpTable[i].store_index)
                {
                    is_match = TRUE;
                    break;
                }

            if (j < min_index)
            {
                min_index = j;
                new_mid = i;
            }
        }
        i++;
        counter++;
        if (counter >= MAX_PHB_NUMBER_COMP)
        {
            break;
        }
    }

    if (is_match)
    {
        return new_mid; /* Always return, even only number with extension exists. */
    }
    else
    {
        return -1;
    }
    /*
     * if(counter <= 1)  //Only one entry match.
     * return new_mid;
     * else if(min_index < MAX_PB_ENTRIES)
     * return new_mid;
     * else
     * return -1;
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_check_full_match_without_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lookup_index        [IN]        
 *  number_list         [?]         
 *  number_in           [?]         
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_phb_number_check_full_match_without_extension(U16 lookup_index, S8 *number_list, S8 *number_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = LookUpTable[lookup_index].store_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if mobile field is match */
    if (((PhoneBook[store_index].tel.type & 0x90) == 0x90) && (PhoneBook[store_index].tel.type != 0xFF))
    {
        number_list[0] = '+';
        mmi_phb_convert_to_digit((U8*) (number_list + 1), PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    }
    else
    {
        mmi_phb_convert_to_digit((U8*) number_list, PhoneBook[store_index].tel.number, MAX_PB_NUMBER_LENGTH + 1);
    }

    if (mmi_phb_number_compare_before_extension(number_in, (S8*) number_list) &&
        mmi_phb_number_compare_extension(number_in, (S8*) number_list))
    {
        return TRUE;
    }

#ifdef __MMI_PHB_USIM_FIELD__
    /* Check number in the anr field */
    if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        if (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_ANRA)
        {
            if (((phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].type & 0x90) == 0x90) && (phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].type != 0xFF))
            {
                number_list[0] = '+';
                mmi_phb_convert_to_digit(
                    (U8*) (number_list + 1),
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }
            else
            {
                mmi_phb_convert_to_digit(
                    (U8*) number_list,
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][0].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }

            if (mmi_phb_number_compare_before_extension(number_in, (S8*) number_list) &&
                mmi_phb_number_compare_extension(number_in, (S8*) number_list))
            {
                return TRUE;
            }
        }
        if (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_ANRB)
        {
            if (((phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].type & 0x90) == 0x90) && (phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].type != 0xFF))
            {
                number_list[0] = '+';
                mmi_phb_convert_to_digit(
                    (U8*) (number_list + 1),
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }
            else
            {
                mmi_phb_convert_to_digit(
                    (U8*) number_list,
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][1].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }

            if (mmi_phb_number_compare_before_extension(number_in, (S8*) number_list) &&
                mmi_phb_number_compare_extension(number_in, (S8*) number_list))
            {
                return TRUE;
            }
        }
        if (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_ANRC)
        {
            if (((phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].type & 0x90) == 0x90) && (phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].type != 0xFF))
            {
                number_list[0] = '+';
                mmi_phb_convert_to_digit(
                    (U8*) (number_list + 1),
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }
            else
            {
                mmi_phb_convert_to_digit(
                    (U8*) number_list,
                    phb_anr[store_index - MAX_PB_PHONE_ENTRIES][2].number,
                    MAX_PB_NUMBER_LENGTH + 1);
            }

            if (mmi_phb_number_compare_before_extension(number_in, (S8*) number_list) &&
                mmi_phb_number_compare_extension(number_in, (S8*) number_list))
            {
                return TRUE;
            }
        }
    }
#endif /* __MMI_PHB_USIM_FIELD__ */ 

#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
    /* Check number in the optional field */
    if ((store_index < MAX_PB_PHONE_ENTRIES) &&
        ((PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_HOME) ||
         (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_OFFICE) ||
         (PhoneBook[store_index].field & MMI_PHB_ENTRY_FIELD_FAX)))
    {
        S16 pError;

        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);

        if (PhoneBook[store_index].field | MMI_PHB_ENTRY_FIELD_HOME)
        {
            if (mmi_phb_number_compare_before_extension(number_in, (S8*) PhoneBookOptionalFields.homeNumber) &&
                mmi_phb_number_compare_extension(number_in, (S8*) PhoneBookOptionalFields.homeNumber))
            {
                g_phb_cntx.searched_number_type = MMI_PHB_ENTRY_FIELD_HOME;
                return TRUE;
            }
        }
        if (PhoneBook[store_index].field | MMI_PHB_ENTRY_FIELD_OFFICE)
        {
            if (mmi_phb_number_compare_before_extension(number_in, (S8*) PhoneBookOptionalFields.officeNumber) &&
                mmi_phb_number_compare_extension(number_in, (S8*) PhoneBookOptionalFields.officeNumber))
            {
                g_phb_cntx.searched_number_type = MMI_PHB_ENTRY_FIELD_OFFICE;
                return TRUE;
            }
        }
        if (PhoneBook[store_index].field | MMI_PHB_ENTRY_FIELD_FAX)
        {
            if (mmi_phb_number_compare_before_extension(number_in, (S8*) PhoneBookOptionalFields.faxNumber) &&
                mmi_phb_number_compare_extension(number_in, (S8*) PhoneBookOptionalFields.faxNumber))
            {
                g_phb_cntx.searched_number_type = MMI_PHB_ENTRY_FIELD_FAX;
                return TRUE;
            }
        }
    }
#endif /* !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_find_first_with_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mid             [IN]        
 *  number          [IN]        
 *  number_in       [?]         
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_phb_number_find_first_with_extension(S16 mid, U32 number, S8 *number_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, new_mid, min_index, counter;
    U8 number_list[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_mid = mid;
    min_index = MAX_PB_ENTRIES;
    counter = 0;

    /* Compare number before mid */
    i = mid;
    while ((i >= 0) && (LookUpTable[i].number == number))
    {
        if (mmi_phb_number_check_full_match_without_extension(i, (S8*) number_list, number_in))
        {
            for (j = 0; j < PhoneBookEntryCount; j++)
                if (g_phb_name_index[j] == LookUpTable[i].store_index)
                {
                    break;
                }

            if (j < min_index)
            {
                min_index = j;
                new_mid = i;
            }
        }
        i--;
        counter++;
        if (counter >= MAX_PHB_NUMBER_COMP)
        {
            break;
        }
    }

    /* Compare number after mid */
    i = mid + 1;
    while ((i < g_phb_cntx.lookup_table_count) && (LookUpTable[i].number == number))
    {
        if (mmi_phb_number_check_full_match_without_extension(i, (S8*) number_list, number_in))
        {
            for (j = 0; j < PhoneBookEntryCount; j++)
                if (g_phb_name_index[j] == LookUpTable[i].store_index)
                {
                    break;
                }

            if (j < min_index)
            {
                min_index = j;
                new_mid = i;
            }
        }
        i++;
        counter++;
        if (counter >= MAX_PHB_NUMBER_COMP)
        {
            break;
        }
    }

    if (min_index == MAX_PB_ENTRIES)
    {
        U16 ext1 = 0;

        mmi_phb_convert_to_digit(
            number_list,
            PhoneBook[LookUpTable[new_mid].store_index].tel.number,
            MAX_PB_NUMBER_LENGTH + 1);

        if ((counter <= 1) && !mmi_phb_number_has_extension((S8*) number_list) &&
            ((ext1 = mmi_phb_number_has_extension(number_in)) > 0) &&
            (number_in[ext1] != '#') && (number_in[ext1] != '*'))
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return new_mid;
    }
}
#endif /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_lookup_table_search
 * DESCRIPTION
 *  Search for the number in the lookup table
 *  and returns the index of the matched entry.
 *  
 *  Its a non-recursive binary search
 * PARAMETERS
 *  number              [IN]        
 *  low                 [IN]        
 *  high                [IN]        
 *  number_ASCII        [IN]         
 *  storage             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_lookup_table_search(U32 number, S16 low, S16 high, S8 *number_ASCII, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 mid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (number == LookUpTable[mid].number)
        {
            /*
             * Advanced Compare - Compare number longer than 9 digit,
             * with extension, find out the prior one if numbers are the same, and etc.
             */
        #if defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__)
            if (!mmi_phb_number_has_extension(number_ASCII))
            {
                mid = mmi_phb_number_find_first_without_extension(mid, number, number_ASCII);
            }
            else
            {
                mid = mmi_phb_number_find_first_with_extension(mid, number, number_ASCII);
            }

            if (mid < 0)
            {
                return 0xffff;  /* an invalid number */
            }
            else
        #endif /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */ 
            {
                if (storage == MMI_STORAGE_BOTH || 
                    (storage == MMI_SIM && LookUpTable[mid].store_index >= MAX_PB_PHONE_ENTRIES) || 
                    (storage == MMI_NVRAM && LookUpTable[mid].store_index < MAX_PB_PHONE_ENTRIES))
                {
                    return LookUpTable[mid].store_index;    /* return storage location in array, begin from 0 */
                }
                mid++;
                while ((mid < (g_phb_cntx.lookup_table_count - 1)) && number == LookUpTable[mid].number)
                {
                    if (storage == MMI_STORAGE_BOTH || 
                        (storage == MMI_SIM && LookUpTable[mid].store_index >= MAX_PB_PHONE_ENTRIES) || 
                        (storage == MMI_NVRAM && LookUpTable[mid].store_index < MAX_PB_PHONE_ENTRIES))
                    {
                        return LookUpTable[mid].store_index;    /* return storage location in array, begin from 0 */
                    }
                    mid++;
                }
            }
        }
        else if (number < LookUpTable[mid].number)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0xffff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_read_compare_length
 * DESCRIPTION
 *  Read the compare length from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_util_read_compare_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U8 comp_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Already read value */
    if (g_phb_compare_length != 0xff)
    {
        return;
    }

    ReadRecord(NVRAM_EF_PHB_COMPARE_DIGIT_LID, 1, (void*)&comp_len, 1, &pError);

    if (comp_len < 6)
    {
        g_phb_compare_length = 6;
    }
    else if (comp_len > 20)
    {
        g_phb_compare_length = 20;
    }

    else
    {
        g_phb_compare_length = comp_len;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_convert_number_to_int
 * DESCRIPTION
 *  Converts the last n characters of a phone number to digits
 * PARAMETERS
 *  ascii_number        [IN]        Input ascii number
 * RETURNS
 *  interger of input number
 *****************************************************************************/
U32 mmi_phb_util_convert_number_to_int(U8 *ascii_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_len;
    U16 ext_len;
    U16 buff_len = MAX_PB_NUMBER_LENGTH + 1;
    U8 *number;
    U8 temp_number[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U8 compare_length = 9;  /* Maximum convert number length is 9 digits. (4 bytes integer) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("---[PhonebookSearch.c] mmi_phb_util_convert_number_to_int() => number: [%s] \n", ascii_number);

    if (ascii_number != NULL)
    {
        strncpy((S8*) temp_number, (S8*) ascii_number, buff_len);
        memset((temp_number + buff_len), 0x00, 1);  /* Makre sure there will be terminator */
    }
    else
    {
        return INVALID_NUMBER;
    }

    number = (U8*) temp_number;

    /* Ignore  *31# and #31# case */
    while (((number[0] == '*') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')) ||
           ((number[0] == '#') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')))
    {
        number += 4;
    }

    /* Skip the first plus sign */
    if (number[0] == '+')
    {
        number++;
    }

    /* number empty */
    if (number[0] == '\0')
    {
        return INVALID_NUMBER;
    }

    /* Find the position of extension number and remove that part */
    ext_len = strcspn((PS8) number, "+pw*#");
    if (!ext_len)
    {
        return INVALID_NUMBER;
    }
    else
    {
        MMI_ASSERT(ext_len <= buff_len);

        number[ext_len] = '\0';

        /* Read compare length from NVRAM */
        mmi_phb_util_read_compare_length();

        num_len = strlen((PS8) number);

        /* May compare less number than 9 digits */
        if (g_phb_compare_length < 9)
        {
            compare_length = g_phb_compare_length;
        }

        /* Convert at most 9 digits integer */
        if (num_len > compare_length)
        {
            number += num_len - compare_length;
        }

        /* return a 32 bits integer by atol() */
        return atol((PS8) number);
    }
}

/*-----------------------------------------------END  General Compare String Functions -------------------------------------------------*/


#define MMI_PHB_SEARCH_EMAIL
#if defined(__MMI_PHB_EMAIL_SORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_email_insert_index
 * DESCRIPTION
 *  This function inserts email to mapping table by its index.
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_email_insert_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos;
    U16 i;
    S16 pError;

#ifdef __MMI_PHB_USIM_FIELD__
    U16 g_phb_email_index[MAX_PB_ENTRIES];
#else 
    U16 g_phb_email_index[MAX_PB_PHONE_ENTRIES];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_FIELD__
    ReadRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_ENTRIES * sizeof(U16), &pError);

    if (PhoneBookEntryCount == 1)
    {
        g_phb_email_index[(PhoneBookEntryCount - 1)] = store_index;
    }
    else
    {
        pos = mmi_phb_sort_email_find_insert_pos(0, (PhoneBookEntryCount - 2), store_index, g_phb_email_index);

        for (i = (PhoneBookEntryCount - 1); i > pos; i--)
        {
            g_phb_email_index[i] = g_phb_email_index[i - 1];
        }
        g_phb_email_index[pos] = store_index;

    }

    WriteRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_ENTRIES * sizeof(U16), &pError);
#else /* __MMI_PHB_USIM_FIELD__ */ 
    ReadRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_PHONE_ENTRIES * sizeof(U16), &pError);

    if (g_phb_cntx.phone_used == 1)
    {
        g_phb_email_index[(g_phb_cntx.phone_used - 1)] = store_index;
    }
    else
    {
        pos = mmi_phb_sort_email_find_insert_pos(0, (g_phb_cntx.phone_used - 2), store_index, g_phb_email_index);

        for (i = (g_phb_cntx.phone_used - 1); i > pos; i--)
        {
            g_phb_email_index[i] = g_phb_email_index[i - 1];
        }
        g_phb_email_index[pos] = store_index;

    }

    WriteRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_PHONE_ENTRIES * sizeof(U16), &pError);
#endif /* __MMI_PHB_USIM_FIELD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_email_find_insert_pos
 * DESCRIPTION
 *  This function find the insert position for a new adding email.
 * PARAMETERS
 *  low                 [IN]        
 *  high                [IN]        
 *  store_index         [IN]        
 *  mapping_table       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_sort_email_find_insert_pos(S32 low, S32 high, U16 store_index, U16 *mapping_table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mid;
    S16 flag;
    U8 same_count;
    S32 distance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (low <= high)
    {
        mid = (low + high) / 2;

        mmi_phb_sort_email_compare_by_encoding(store_index, mapping_table[mid], &same_count, &distance);

        if (distance > 0)
        {
            low = mid + 1;
            flag = -1;
        }
        else    /* Either > 0 or < 0, not possible ==0 */
        {
            high = mid - 1;
            flag = 1;
        }
    }

    if (flag == -1)
    {
        return (U16) (mid + 1);
    }
    else
    {
        return (U16) mid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_email_compare_by_encoding
 * DESCRIPTION
 *  This function compare email precedence by encoding.
 *  If no email presents, use name instead.
 * PARAMETERS
 *  first           [IN]        
 *  second          [IN]        
 *  same_count      [?]         
 *  distance        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_email_compare_by_encoding(U16 first, U16 second, U8 *same_count, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *string1, *string2;
    S8 email1[(MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH];
    S8 email2[(MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH];
    S16 pError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Prepare data for compare string 1
     */
    if (PhoneBook[first].field & MMI_PHB_ENTRY_FIELD_EMAIL)
    {
    #ifdef __MMI_PHB_USIM_FIELD__
        if (first >= MAX_PB_PHONE_ENTRIES)
        {
            mmi_asc_to_ucs2((S8*) pbEmailAddress, (S8*) phb_email[first - MAX_PB_PHONE_ENTRIES].email_address);
        }
        else
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
        {
            ReadRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (first + 1),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);
            mmi_asc_to_ucs2(email1, (S8*) PhoneBookOptionalFields.emailAddress);
        }
        string1 = email1;
    }
    else
    {
        string1 = (S8*) PhoneBook[first].alpha_id.name;
    }

    /*
     * Prepare data for compare string 2
     */
    if (PhoneBook[second].field & MMI_PHB_ENTRY_FIELD_EMAIL)
    {
    #ifdef __MMI_PHB_USIM_FIELD__
        if (second >= MAX_PB_PHONE_ENTRIES)
        {
            mmi_asc_to_ucs2((S8*) pbEmailAddress, (S8*) phb_email[second - MAX_PB_PHONE_ENTRIES].email_address);
        }
        else
    #endif /* __MMI_PHB_USIM_FIELD__ */ 
        {
            ReadRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (second + 1),
                (void*)&PhoneBookOptionalFields,
                OPTIONAL_FIELDS_RECORD_SIZE,
                &pError);
            mmi_asc_to_ucs2(email2, (S8*) PhoneBookOptionalFields.emailAddress);
        }
        string2 = email2;
    }
    else
    {
        string2 = (S8*) PhoneBook[second].alpha_id.name;
    }

    /*
     * compare strings
     */
    mmi_phb_compare_ucs2_strings(string1, string2, same_count, distance);

    /*
     * If two strings are the same, put smaller store index in front.
     */
    if (*distance == 0)
    {
        if (first < second)
        {
            *distance = -1;
        }
        else if (first > second)
        {
            *distance = 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_email_delete_index
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_email_delete_index(U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos, i;
    S16 pError;

#ifdef __MMI_PHB_USIM_FIELD__
    U16 g_phb_email_index[MAX_PB_ENTRIES];
#else 
    U16 g_phb_email_index[MAX_PB_PHONE_ENTRIES];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_FIELD__
    ReadRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_ENTRIES * sizeof(U16), &pError);
    for (pos = 0; pos < (PhoneBookEntryCount + 1); pos++)
        if (g_phb_email_index[pos] == store_index)
        {
            break;
        }
    for (i = pos; i < (PhoneBookEntryCount + 1); i++)
    {
        g_phb_email_index[i] = g_phb_email_index[i + 1];
    }
    WriteRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_ENTRIES * sizeof(U16), &pError);
#else /* __MMI_PHB_USIM_FIELD__ */ 
    ReadRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_PHONE_ENTRIES * sizeof(U16), &pError);
    for (pos = 0; pos < (g_phb_cntx.phone_used + 1); pos++)
        if (g_phb_email_index[pos] == store_index)
        {
            break;
        }
    for (i = pos; i < (g_phb_cntx.phone_used + 1); i++)
    {
        g_phb_email_index[i] = g_phb_email_index[i + 1];
    }
    WriteRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_PHONE_ENTRIES * sizeof(U16), &pError);
#endif /* __MMI_PHB_USIM_FIELD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_email_delete_all_index
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sort_email_delete_all_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;

#ifdef __MMI_PHB_USIM_FIELD__
    U16 g_phb_email_index[MAX_PB_ENTRIES];
#else 
    U16 g_phb_email_index[MAX_PB_PHONE_ENTRIES];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_FIELD__
    memset(g_phb_email_index, 0xff, MAX_PB_ENTRIES * sizeof(U16));
    WriteRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_ENTRIES * sizeof(U16), &pError);
#else /* __MMI_PHB_USIM_FIELD__ */ 
    memset(g_phb_email_index, 0xff, MAX_PB_PHONE_ENTRIES * sizeof(U16));
    WriteRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_PHONE_ENTRIES * sizeof(U16), &pError);
#endif /* __MMI_PHB_USIM_FIELD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_search_email_binary_search
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  low                 [IN]        
 *  high                [IN]        
 *  ucs2_pattern        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_search_email_binary_search(S32 low, S32 high, S8 *ucs2_pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 g_phb_email_index[MAX_PB_PHONE_ENTRIES];
    S32 mid;
    S16 flag;
    U8 same_count;
    S32 distance;
    U16 index;
    S8 *string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get email mapping table from NVRAM */
    ReadRecord(NVRAM_EF_PHB_EMAIL_SORT_LID, 1, (void*)g_phb_email_index, MAX_PB_PHONE_ENTRIES * sizeof(U16), &pError);

    /* Use binary search to find nearest name. */
    while (low <= high)
    {
        mid = (low + high) / 2;

        index = g_phb_email_index[mid];

        /* Use email to compare pattern, if email empty, use name instead */
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (index + 1),
            (void*)&PhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
        if (PhoneBookOptionalFields.emailAddress[0] != 0x00)
        {
            mmi_asc_to_ucs2(pbEmailAddress, (PS8) PhoneBookOptionalFields.emailAddress);
            string = (S8*) pbEmailAddress;
        }
        else
        {
            string = (S8*) PhoneBook[index].alpha_id.name;
        }

        mmi_phb_compare_ucs2_strings(ucs2_pattern, string, &same_count, &distance);

        if (distance > 0)
        {
            low = mid + 1;
            flag = -1;
        }
        /*
         * Distance == 0 or < 0 here
         * If there are duplicate entry, this will help to move up until first entry.
         */
        else
        {
            high = mid - 1;
            flag = 1;
        }
    }

    if (flag == -1)
    {
        return (U16) (mid + 1);
    }
    else
    {
        return (U16) mid;
    }
}

#endif /* defined(__MMI_PHB_EMAIL_SORT__) */ 

/*
 * the following code is for quick search from mms entry phonebook
 */
#if defined(__MMI_PHB_QUICK_SEARCH__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_filter_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL mmi_phb_generic_quick_search_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S32 i = -1;
    S32 inner_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    while (i < item_index)
    {
        store_index = g_phb_name_index[inner_index];
		
        if (g_phb_generic_qsearch_bitmask[inner_index >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (inner_index % BYTE_SIZE)))
        {
            if (PhoneBook[store_index].field & phb_list_view_type)
            {
                i++;  
            }
        }		
        inner_index++;
    }

    if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name))
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) PhoneBook[store_index].alpha_id.name);
    }
    else
    {
        mmi_phb_convert_get_ucs2_number((S8*) str_buff, store_index);
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if(store_index >= (MAX_PB_PHONE_ENTRIES+MAX_PB_SIM_ENTRIES))
    {
        *img_buff_p = get_image(IMG_ID_CARD2_PHB_STORAGE_SIM);
    }
    else if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_ID_CARD1_PHB_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (store_index >= MAX_PB_PHONE_ENTRIES)
    {
        *img_buff_p = get_image(IMG_STORAGE_SIM);
    }
    else
    {
        *img_buff_p = get_image(IMG_STORAGE_HANDSET);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_filter_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_phb_generic_quick_search_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0;
    S8 temp_number[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
    S32 i = -1;
    S32 inner_index = 0;
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
    PHB_OPTIONAL_FIELDS_STRUCT tempPhoneBookOptionalFields;
    S8 temp_email[(MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH];
    S16 pError;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < item_index)
    {
        store_index = g_phb_name_index[inner_index];
		
        if (g_phb_generic_qsearch_bitmask[inner_index >> BYTE_SIZE_SHIFT_ARITHMETIC] & (1 << (inner_index % BYTE_SIZE)))
        {
            if (PhoneBook[store_index].field & phb_list_view_type)
            {
                i++;  
            }
        }		
        inner_index++;
    }

    if (phb_list_view_type & MMI_PHB_ENTRY_FIELD_ALL_NUMBER)
    {
        mmi_phb_convert_get_ucs2_number((S8*) temp_number, store_index);

        if (mmi_ucs2strlen((S8*) PhoneBook[store_index].alpha_id.name) && mmi_ucs2strlen((S8*) temp_number))
        {	
            mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_number);
        }
        else
        {
            return 0;
        }
    }
#if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__) || defined(__MMI_PHB_USIM_FIELD__)
    else if (phb_list_view_type & MMI_PHB_ENTRY_FIELD_EMAIL)
    {
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_LID,
            (U16) (store_index + 1),
            (void*)&tempPhoneBookOptionalFields,
            OPTIONAL_FIELDS_RECORD_SIZE,
            &pError);
        mmi_asc_to_ucs2(temp_email, (PS8) tempPhoneBookOptionalFields.emailAddress);
        if (mmi_ucs2strlen((S8*) temp_email))
        {	
            mmi_ucs2cpy((S8*) hint_array[0], (S8*) temp_email);
        }
        else
        {
            return 0;
        }
    }
#endif
    else
    {
        return 0;
    }

    return 1;   /* One hint data only, can be more hints. */
}


#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_quick_search_go_back_editor
 * DESCRIPTION
 *  Go back screen after change input method.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_generic_quick_search_go_back_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_PBOOK_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_highlight_quick_search_input_method
 * DESCRIPTION
 *  Highlight function to enter change input method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_generic_highlight_quick_search_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryQuickSearchInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryQuickSearchInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    RegisterInputMethodScreenCloseFunction(mmi_phb_generic_quick_search_go_back_editor);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_highlight_quick_search_op_option
 * DESCRIPTION
 *  Highlight function to enter entry option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_generic_highlight_quick_search_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phb_entry_choose_number, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_entry_choose_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_entry_quick_search_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_generic_entry_quick_search_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PHB_GENERIC_QUICK_SEARCH_OPTIONS, NULL, mmi_phb_generic_entry_quick_search_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_GENERIC_QUICK_SEARCH_OPTIONS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MENU_ID_PHB_GENERIC_QUICK_SEARCH_OPTION);
    GetSequenceStringIds(MENU_ID_PHB_GENERIC_QUICK_SEARCH_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_PHB_GENERIC_QUICK_SEARCH_OPTION);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_generic_exit_quick_search_option
 * DESCRIPTION
 *  Exit function of phonebook quick search option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_generic_exit_quick_search_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phb_cntx.end_scr_id = SCR_ID_PHB_GENERIC_QUICK_SEARCH_OPTIONS;
}
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_generic_quick_search_list
 * DESCRIPTION
 *  This function provide call back function before enter phonebook list
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_generic_quick_search_list(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 GQSEntryCount = 0;
    U16 entryCount;
    U16 store_index;
    U8 *guiBuffer;
    //MMI_BOOL alpha_index = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "File: [%s]  Line: [%d] <<mmi_phb_entry_generic_quick_search_list.>\n", __FILE__,
                         __LINE__);

#ifdef __SYNCML_SUPPORT__
    if (mmi_syncml_is_phb_sync_now())
    {
        mmi_phb_entry_not_ready(STR_ID_SYNC_PLEASE_WAIT);
    }
    else
#endif /* __SYNCML_SUPPORT__ */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (MTPNP_PFAL_Phb_IsReady() == MTPNP_TRUE)
#else/* __MMI_DUAL_SIM_MASTER__ */
    if (g_phb_cntx.phb_ready && !g_phb_cntx.processing)
#endif/* __MMI_DUAL_SIM_MASTER__ */
    {
        /* Allocate buffer for phonebook memeber list filter */
        mmi_phb_list_allocate_filter();

        /* Build list according to filter */
        PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "[Mude Lin]mmi_phb_entry_generic_quick_search_list[] PhoneBookEntryCount = %d\n", PhoneBookEntryCount);		
        for (i = 0; i < PhoneBookEntryCount; i++)
        {
            store_index = g_phb_name_index[i];
            PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "[Mude Lin]mmi_phb_entry_generic_quick_search_list[] field = %d, phb_list_view_type = %d\n", PhoneBook[store_index].field, phb_list_view_type);		
            if (PhoneBook[store_index].field & phb_list_view_type)
            {
                g_phb_cntx.list_filter[GQSEntryCount] = store_index;
                GQSEntryCount++;
            }
        }
        PRINT_INFORMATION_2(MMI_TRACE_G4_PHB, "[Mude Lin]mmi_phb_entry_generic_quick_search_list[] GQSEntryCount = %d\n", GQSEntryCount);
        if (GQSEntryCount)
        {
            g_phb_cntx.highlight_entry = 0;
            phbListView = MMI_PHB_LIST_FOR_OTHER_APP;
            g_phb_quick_search_enter = MMI_PHB_QUICK_SEARCH_GENERIC;

            EntryNewScreen(SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST, NULL, mmi_phb_entry_generic_quick_search_list, MMI_FULL_SCREEN);
            guiBuffer = GetCurrGuiBuffer(SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST);
    
            if (g_phb_cntx.new_highlight_entry < 0xffff)
            {
                change_list_menu_category_history(guiBuffer, g_phb_cntx.new_highlight_entry, GQSEntryCount, 0);
                g_phb_cntx.new_highlight_entry = 0xffff;
            }

           RegisterHighlightHandler(mmi_phb_get_index_by_store_location_second);
           RegisterCat200SearchFunction(mmi_phb_quick_search_find_entry);

            /* First Time enter or any entry has been modified.. */
            if ((guiBuffer == NULL) || (g_phb_cntx.refresh_list == MMI_PHB_ENTRY_REFRESH))
            {
                g_phb_cntx.highlight_entry = 0;
                memset(g_phb_generic_qsearch_input, 0, ENCODING_LENGTH);
                memset(g_phb_generic_qsearch_bitmask, 0xff, (MAX_PB_ENTRIES + 7) / 8);

                entryCount = GQSEntryCount;
                guiBuffer = NULL;
                g_phb_cntx.refresh_list = MMI_PHB_ENTRY_QSEARCH;    /* '2' is used only for this screen. */
            }
            else
            {
                entryCount = (U16) mmi_phb_quick_search_find_entry(g_phb_generic_qsearch_input);
            }
            
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    set_force_icon_on_highlight_only_in_menuitem();
#endif

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)         
            ShowCategory200Screen(
                STR_SCR_PBOOK_VIEW_CAPTION,
                IMG_SCR_PBOOK_CAPTION,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                entryCount,
                mmi_phb_generic_quick_search_list_get_item,
                mmi_phb_generic_quick_search_list_get_hint,
                g_phb_cntx.highlight_entry,
                IMG_ID_PHB_QUICK_SEARCH_FIND,
                (U8*) g_phb_generic_qsearch_input,
                MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
                guiBuffer);
            SetCategory200LeftSoftkeyFunction(mmi_phb_generic_entry_quick_search_option, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(mmi_phb_generic_entry_quick_search_option, KEY_EVENT_UP);
#else /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */                    
            ShowCategory200Screen(
                STR_SCR_PBOOK_VIEW_CAPTION,
                IMG_SCR_PBOOK_CAPTION,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                entryCount,
                mmi_phb_generic_quick_search_list_get_item,
                mmi_phb_generic_quick_search_list_get_hint,
                g_phb_cntx.highlight_entry,
                IMG_ID_PHB_QUICK_SEARCH_FIND,
                (U8*) g_phb_generic_qsearch_input,
                MMI_PHB_QUICK_SEARCH_INPUT_LENGTH,
                guiBuffer);
            SetCategory200LeftSoftkeyFunction(mmi_phb_entry_choose_number, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(mmi_phb_entry_choose_number, KEY_EVENT_UP);
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */ 

            SetCategory200RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//          SetKeyHandler(mmi_phb_entry_choose_number, KEY_SEND, KEY_EVENT_DOWN);
            if (guiBuffer == NULL)
            {
                g_phb_generic_qsearch_is_cache = 0;
                mmi_phb_quick_search_make_cache();
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_PHB_NO_ENTRY_TO_SELECT),
                IMG_GLOBAL_EMPTY,
                TRUE,
                PHB_NOTIFY_TIMEOUT,
                EMPTY_LIST_TONE);
            mmi_phb_list_free_filter();
        }
    }
    else
    {
        mmi_phb_entry_not_ready(STR_PROCESSING_PHONEBOOK);
    }
}

#endif

#endif /* _PHONEBOOKSEARCH_C */ 

