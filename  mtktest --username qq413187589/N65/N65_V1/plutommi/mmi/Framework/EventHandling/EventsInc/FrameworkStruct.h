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
 * FrameworkStruct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is defines prototypes, struct, defined marco for general MMI framework usage.
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

#ifndef _FRAMEWORKSTRUCT_H
#define _FRAMEWORKSTRUCT_H

#include "MMIDataType.h"
#include "QueueGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* maximum history data */
#if defined(JATAAYU_SUPPORT)
    #define MAX_INPUT_BUFFER         1500
#elif defined(__MMI_BROWSER_2__)
    #define MAX_INPUT_BUFFER         1500
#else    
    #define MAX_INPUT_BUFFER         1000
#endif
#define MAX_GUI_BUFFER           128


/* MMI supports dump screen string automatically */
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
  #define __COMBINE_CHAR_IN_DUMP_SCREEN_STRING__
#endif

#define MMI_STR_DUMP_TIMEOUT                    (1500)  /* ms */
#define MMI_SCREEN_NO_STR                       (0)
#define MMI_SCREEN_NORMAL_STR                   (1)
#define MMI_SCREEN_HIGHLIGHT_STR                (2)


#define MMI_SCREEN_HIGHLIGHT_NONE                       (0)
#define MMI_SCREEN_HIGHLIGHT_TEXT_ITEM                  (21)
#define MMI_SCREEN_FOCUSED_ICONTEXT_ITEM                (22)
#define MMI_SCREEN_HIGHLIGHT_ICONTEXT_ITEM              (23)
#define MMI_SCREEN_HIGHLIGHT_ICONTEXT_MARQUEE_SCROLL    (24)
#define MMI_SCREEN_FOCUSED_TWO_LINE_ICONTEXT            (25)
#define MMI_SCREEN_HIGHLIGHT_TWO_LINE_HINTS             (26)
#define MMI_SCREEN_HIGHLIGHT_ICONTEXT_LIST              (27)
#define MMI_SCREEN_HIGHLIGHT_TWOSTATE_ITEM              (28)
#define MMI_SCREEN_HIGHLIGHT_FOR_HOR_SELECT             (29)
#define MMI_SCREEN_HIGHLIGHT_FOR_CAR213_DYNAMIC_LIST    (30)


/* We want combined separated chars to the string */
#define MMI_SCREEN_COMBINED_CHAR_MAX_LENGTH     (100)

/*
 * MMI_SCREEN_STR_MAX_LENGTH should be the same with
 * "data_string" in mmi_eq_str_res_req_struct/mmi_eq_str_req_ind_struct
 */
#define MMI_SCREEN_STR_MAX_LENGTH               (250)



/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* enum type for framework */
typedef enum
{
    MMI_KEY_TONE_ENABLED = 0,
    MMI_KEY_VOL_TONE_DISABLED,
    MMI_KEY_VOL_UP_DOWN_TONE_DISABLED,
    MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED,
    MMI_KEY_TONE_DISABLED,
    MMI_KEY_TONE_INVALID
} mmi_frm_kbd_tone_state_enum;

typedef struct KEYBRD_MESSAGE
{
    LOCAL_PARA_HDR
    S16 nMsgType;
    S16 nKeyCode;
} KEYBRD_MESSAGE;

/* FuncPtr is a pointer to a func returns void */
typedef void (*FuncPtr) (void);
typedef void (*FuncPtrShort) (U16);

/* FuncPtr is a pointer to a func that takes void* has a parameter &  returns void */
typedef void (*PsFuncPtr) (void *);
typedef U8(*PsIntFuncPtr) (void *);

/* JL added for new history callback */
typedef U8(*HistoryDelCBPtr) (void *);
typedef U8(*SubLcdHistoryCBPtr) (void *);
typedef U8(*MainLcdHistoryCBPtr) (void *);

typedef void (*PsFuncPtrU32) (void *, U32);

typedef void (*PsExtFuncPtr) (void *, int); /* add by hjf, to pass the mod_src */
typedef U8(*PsExtIntFuncPtr) (void *, int); /* add by hjf, to pass the mod_src */

typedef void (*PsExtPeerFuncPtr) (void *, int, void *);
typedef U8(*PsExtPeerIntFuncPtr) (void *, int, void *);

typedef U8* (*HistoryGetData) (U8*);    /* Get GUI-buffer/input-buffer to history */
typedef S32 (*HistoryGetSize) (void);   /* Get input buffer size */
typedef void *(*MemAlloc) (U32);
typedef void (*MemFree) (void *);


typedef U8(*PsKeyProcessCBPtr) (KEYBRD_MESSAGE *);

/* event information stuct */
typedef struct _eventInfo
{
    U16 eventID;    /* for timer & hardware events      */
    FuncPtr entryFuncPtr;
} eventInfo;

/* Async PRT event information struct */
typedef struct _PseventInfo
{
    U16 eventID;    /* for timer & hardware events      */
    PsFuncPtr entryFuncPtr;
} PseventInfo;

typedef struct _PIntseventInfo
{
    U16 eventID;    /* for timer & hardware events      */
    PsIntFuncPtr entryIntFuncPtr;
    PsIntFuncPtr postIntFuncPtr;
} PsInteventInfo;

/* history information stuct */
typedef struct _history
{
    U16 scrnID;
    FuncPtr entryFuncPtr;
    U8 inputBuffer[MAX_INPUT_BUFFER];   /* running text data                   */
    U8 guiBuffer[MAX_GUI_BUFFER];       /* this includes hilite item, input mode & etc.. */
} history;

/* history information stuct */
typedef struct _historyNode
{
    U16 scrnID;
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    U16 isSmallScreen;
#endif 
    FuncPtr entryFuncPtr;
    U8 *inputBuffer;    /* running text data                   */
    U8 *guiBuffer;      /* this includes hilite item, input mode & etc.. */
    
    MemAlloc mallcFuncPtr;	/* keep the memory allocated function */
    MemFree  mfreeFuncPtr;	/* keep the memory freed function */
} historyNode;

/* history information stuct */
typedef struct _historyCallback
{
    U16 scrnID;
    HistoryDelCBPtr historydelCBPtr;
} historyCallback;

/* hilite information stuct   */
typedef struct _hiliteInfo
{
    FuncPtrShort hintFuncPtr;
    FuncPtr entryFuncPtr;
} hiliteInfo;

typedef struct _SubLCDhistoryNode
{
    U16 scrnID;
    FuncPtr entryFuncPtr;
} SubLCDHistoryNode;

typedef struct
{
    U16 scrnID;
    FuncPtr entryFuncPtr;
    U8 guiBuffer[MAX_GUI_BUFFER];   /* this includes hilite item, input mode & etc.. */
} SubLCDHistoryNodeEx;

typedef struct
{
    FuncPtr entryFuncPtr;
    U16 scrnID;
    U16 guiLen;
    U8 *guiBuffer;  /* this includes hilite item, input mode & etc.. */
} SubLCDHistoryInternalNode;

/* MMI supports dump screen string automatically */
typedef struct
{
    MMI_BOOL    is_enable;
    MMI_BOOL    allow_dump_screen_str;
    MMI_BOOL    allow_dump_dm_screen;
    U16         hightlight_type;
    U16         backup_hightlight_type;
    S16         y;
    S16         backup_y;
    S16         combined_chars_x;
    S16         combined_chars_y;
#ifdef __COMBINE_CHAR_IN_DUMP_SCREEN_STRING__
    S8          combined_chars[MMI_SCREEN_COMBINED_CHAR_MAX_LENGTH];
#endif
    /* the backup string size should be the same with mmi_eq_str_res_req_struct*/
    S8          backup_string[MMI_SCREEN_STR_MAX_LENGTH];
}DumpScreenStr;

/* mmi framework contact struct */
typedef struct
{
    mmi_frm_kbd_tone_state_enum key_tone_state; /* state of keypad tone */
    PsKeyProcessCBPtr kbd_pre_func;             /* function to be executed before general keypad handler */
    PsKeyProcessCBPtr kbd_post_func;            /* function to be executed after general keypad handler */
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    DumpScreenStr                   dump_screen_info;
#endif
    U16 key_tone_id;
    U8 key_tone_duration;
} mmi_frm_context_struct;


typedef struct  
{
    U16 screen_id;
    FuncPtr tab_entry_func;
    U8*  tab_icon;
    U8*  tab_string;
}mmi_frm_tab_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern mmi_frm_context_struct g_mmi_frm_cntx;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/


#endif /* _FRAMEWORKSTRUCT_H */ 

