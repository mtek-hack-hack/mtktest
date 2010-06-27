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

/*******************************************************************************
 * Filename:
 * ---------
 * HistoryGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for history functions Prototypes.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
#ifndef _PIXCOM_HISTORYGPROT_H
#define _PIXCOM_HISTORYGPROT_H

#include "FrameworkStruct.h"
#include "gui_tab_bars.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* Definition for delete callback handler */
#define MMI_HIST_EXIT_SCREEN_TYPE       (1)
#define MMI_HIST_DELETE_SCREEN_TYPE     (0)

#define MMI_HIST_STOP_DELETING          (1)
#define MMI_HIST_ALLOW_DELETING         (0)

#define MMI_HIST_TOP_SCREEN		GetCurrScrnId()

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void InitHistory(MainLcdHistoryCBPtr main_root_ptr, SubLcdHistoryCBPtr sub_root_ptr);
extern void HistoryDump(void);
extern pBOOL HistoryReplace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func);

#ifdef OSL_MEMORY_DUMP
extern void AddHistoryReferenceMemoryRecord(history *addHistory, char *fileName, int lineNumber);

#define AddHistory(addHistory) AddHistoryReferenceMemoryRecord(&(addHistory), __FILE__, __LINE__)
#else /* OSL_MEMORY_DUMP */ 
extern void AddHistoryReference(history *addHistory);

#define AddHistory(addHistory) AddHistoryReference(&(addHistory))

extern void InsertHistoryBeforeThisScrnReference(U16 scrnId, history *addHistory);

#define InsertHistoryBeforeThisScrn(scrnId, addHistory) InsertHistoryBeforeThisScrnReference(scrnId, &(addHistory))
#endif /* OSL_MEMORY_DUMP */ 

extern MMI_BOOL InsertHistoryAfterThisScrnReference(U16 scrnId, history *addHistory);


extern U8 GetHistory(U16 scrnID, history *ptrHistory);
extern U8 GetHistoryPointer(U16 scrnID, historyNode **ptrHistory);

/* please change to use GetHistoryPointer, rather than GetHistoryScrID */
extern U8 GetHistoryScrID(U16 scrnID, historyNode **ptrHistory);
extern pBOOL CheckIsBackHistory(void);
extern void GoBackHistory(void);
extern U8 GoBackToHistory(U16 scrnid);
extern void GoBacknHistory(U16 nHistory);
extern S16 GetScreenCountInHistory(void);
extern U8 *GetCurrGuiBuffer(U16 scrnid);                /* get current screen history */
extern U8 *GetCurrInputBuffer(U16 scrnid);
extern void DeleteNHistory(U16 DeleteCount);
extern void ExecutecurrHisIndEntryFunc(void);
extern U8 GoBeyondMarkerScr(U16 scrnid);
extern U8 DeleteScreens(U16 start_scrnid, U16 end_scrnid);

extern U32 DeleteHistory(U16 startScrId, U8 bIncStart, U16 count, U16 endScrId, U8 bIncEnd);

extern U8 DeleteBeyondScrTillScr(U16 beyondScrnid, U16 tillScrnid);
extern U16 DeleteBetweenScreen(U16 StartScrId, U16 EndScrId);
extern U8 DeleteUptoScrID(U16 scrnid);
extern U16 DeleteScreenFromToNnodes(U16 ScrId, U16 num_nodes);
extern U8 DeleteFromScrUptoScr(U16 start_scrnid, U16 upto_scrnid);
extern U8 DeleteNScrId(U16 scrnid);
extern U16 DeleteScreenIfPresent(U16 ScrId);
extern pBOOL IsScreenPresent(U16 scrnId);
extern pBOOL IsMainLCDHistoryBack(void);
extern U8 IsCurrMarkerScreen(U16 scrnid);
extern void DinitHistory(void);
extern void DisplayIdleScreen(void);
extern U8 ExecuteRootMainHistoryScreen(void *funcPtr);  /* execute main lcd history callback function and root history function */
extern U8 GetNHistory(U16 scrnID, history *ptrHistory);

extern void AddNHistory_ext(history *addHistory, U16 size);

#define AddNHistory(addHistory,size)   AddNHistory_ext(&(addHistory),size)

extern MMI_BOOL AddHistoryEx(
                    U16 scrnID,                             /* the screen id */
                    FuncPtr entryFuncPtr,                   /* the screen¡¦s entry function */
                    HistoryGetData getGuiFuncPtr,           /* the function to get GUI data */
                    HistoryGetSize getInputBufSizeFuncPtr,  /* the function to get input buffer size */
                    HistoryGetData getInputBufFuncPtr,      /* the function to get input buffer */
                    MemAlloc mallocFuncPtr,                 /* the function to allocate memory */
                    MemFree mfreeFuncPtr);                  /* the function to free memory */

extern void mmi_set_orderly_exit_screen(void);

extern U8 *GetCurrNInputBuffer(U16 scrnid, U16 *size);
extern pBOOL GetPreviousScrnIdOf(U16 scrnId, U16 *previousScrnId);
extern pBOOL GetNextScrnIdOf(U16 scrnId, U16 *nextScrnId);
extern U16 GetCurrScrnId(void);

extern U8 SetDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);
extern U8 ClearDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);

extern MMI_BOOL redraw_in_small_screen_proceduer(void);
extern void set_small_screen(void); /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */
extern void reset_small_screen(void);
extern void force_no_small_screen(void);
extern void restore_small_screen(void);
extern S32 is_redrawing_old_screens(void);

/* 
 * enable_resized_small_screen(), disable_resized_small_screen(), and whether_no_small_screen()
 * There is no relation with small screen process in history.
 * It's only used for tha WGUI and application and decide to 
 * show the small screen or the normal screen.
 */
extern void enable_resized_small_screen(void);
extern void disable_resized_small_screen(void);
extern S32 whether_no_small_screen(void);
extern U8 *GetCurrGuiBuffer_Ex(U16 scrnid);

extern MMI_BOOL mmi_frm_general_tab_entry(U16 screen_id, FuncPtr entry_func_ptr, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count);
extern void mmi_frm_general_tab_exit(void);
extern U8 mmi_frm_general_tab_delete_hdlr(void* p);
extern MMI_BOOL mmi_frm_add_tab_history(U16 screen_id , history *tab_page_history);
extern MMI_BOOL mmi_frm_add_tab_n_history(U16 screen_id , history *tab_page_history, U16 size);
extern S32 mmi_frm_set_cur_sel_page (U8 index);
extern U8 *mmi_frm_get_cur_tab_gui_buffer(U16 screen_id);
extern U8 *mmi_frm_get_cur_tab_input_buffer(U16 screen_id);
extern U8 *mmi_frm_get_cur_tab_n_input_buffer(U16 screen_id, U16 *size); 
extern void mmi_frm_general_tab_l_arrow_key_hdlr(void);
extern void mmi_frm_general_tab_r_arrow_key_hdlr(void);
extern MMI_BOOL mmi_frm_get_tab_bar_items(tab_bar_item_type *tab_bar_items_p, S8 *tabs_p);
#endif /* _PIXCOM_HISTORYGPROT_H */ 

