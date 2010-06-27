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
 * BTMMIFtpScr.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BT_MMI_FTP_SCR_H__
#define __BT_MMI_FTP_SCR_H__

/***************************************************************************** 
* Predefine header checking
*****************************************************************************/
#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 
#ifndef __BT_MMI_FTP_GPROTS_H__
#error "BTMMIFtpGprots.h should be included"
#endif 

#include "xml_def.h"//sergeycao
#include "EventsGprot.h"

/******************************************************************************
    Enum Value
******************************************************************************/

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/* identify the selected object type */
typedef enum
{
    MMI_FTP_OBJ_TYPE_NONE,
    MMI_FTP_OBJ_TYPE_FILE,
    MMI_FTP_OBJ_TYPE_FOLDER
} mmi_ftp_obj_type_enum;

/* identify the access right option */
typedef enum
{
    MMI_FTP_ACCESS_RIGHT_FULLY_CONTROL,
    MMI_FTP_ACCESS_RIGHT_READ_ONLY
} mmi_ftp_access_right_enum;

/* identify the option selection from user */
typedef enum
{
    MMI_FTP_SCR_SELECT_OPT_OPEN_GET,
    MMI_FTP_SCR_SELECT_OPT_REFRESH,
    MMI_FTP_SCR_SELECT_OPT_DETAIL,
    MMI_FTP_SCR_SELECT_OPT_BACK_ROOT,
    MMI_FTP_SCR_SELECT_OPT_DISCONNECT,
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    MMI_FTP_SCR_SELECT_OPT_ADD_TO_LIST,
    MMI_FTP_SCR_SELECT_OPT_SHOW_LIST,
    MMI_FTP_SCR_SELECT_OPT_GET_LIST_FILES,
    MMI_FTP_SCR_SELECT_OPT_GET_ALL_FILES,
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
    MMI_FTP_SCR_SELECT_OPT_END_OF_NUM
} mmi_ftp_scr_select_opt_enum;

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
/* identify the list option selection from user */
typedef enum
{
    MMI_FTP_MULTI_PULL_LIST_OPT_GET,
    MMI_FTP_MULTI_PULL_LIST_OPT_DETAIL,
    MMI_FTP_MULTI_PULL_LIST_OPT_UP,
    MMI_FTP_MULTI_PULL_LIST_OPT_DOWN,
    MMI_FTP_MULTI_PULL_LIST_OPT_DELETE,
    MMI_FTP_MULTI_PULL_LIST_OPT_DEL_ALL,
    MMI_FTP_MULTI_PULL_LIST_OPT_MAX
} mmi_ftp_multi_pull_list_opt_enum;

/* identify the download type */
typedef enum
{
    MMI_FTP_PULL_TYPE_NONE,
    MMI_FTP_PULL_TYPE_SINGLE,
    MMI_FTP_PULL_TYPE_MULTI,
    MMI_FTP_PULL_TYPE_ALL,
    MMI_FTP_PULL_TYPE_MAX
} mmi_ftp_pull_type_enum;
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

/******************************************************************************
    Structure
******************************************************************************/
/* object entity structure is used to temp buffering the object received from FTPS */
typedef struct
{
    U16 name[FTP_MAX_OBJ_NAME_LEN / 2];
    U16 created_date[FTP_MAX_OBJ_CREATED_DATE_LEN / 2];
    U16 size[FTP_MAX_OBJ_SIZE_LEN / 2];
    mmi_ftp_obj_type_enum type;
} mmi_ftp_obj_entity_struct;

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

/******************************************************************************
    MMI FTP SCR CONTEXT
******************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
typedef struct
{
    /* the file indexs in file browser of current path */
    U16 *p_obj_indexs_in_folder;

    /* size of download list */
    U16 list_capability;

    /* count of objs in download list */
    U16 list_obj_cnt;
} mmi_ftpc_download_list;
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
#endif /* __MMI_FTC_SUPPORT__ */ 


#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
typedef struct
{
#ifdef __MMI_FTC_SUPPORT__
    U16 sel_obj_id;
    U16 sel_opt_id;
    mmi_ftp_obj_entity_struct obj_entity;

    /* Store END key handler void(*)(void) */
    FuncPtr keydown_fp;
    FuncPtr keyup_fp;

    /* MMI_TRUE: endkey is pressed */
    U8        is_endkey_pressed;

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    /* object id in download list */
    U16 sel_list_obj_id;

    /* option id in list option */
    U16 sel_list_opt_id;

    /* download list structure */
    mmi_ftpc_download_list download_list;

    /* count of objs have received */
    U16 received_obj_cnt;

    /* current file id in parsed-fodler-content file, only used in pull-all, for find the file name */
    U16 curent_file_id;

    /* pull type: single, multi, all */
    U8 pull_type;

    /* file total len type: multi, all */
    U8 multi_total_len_type;
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
#endif /* __MMI_FTC_SUPPORT__ */ 
#ifdef __MMI_FTS_SUPPORT__
    U16 access_right_id;
#endif 
} mmi_ftp_scr_cntx_struct;
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

/******************************************************************************
    MMI FTP SCR EXTERNAL VARIABLE
******************************************************************************/
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
extern mmi_ftp_scr_cntx_struct *g_mmi_bt_ftp_scr_cntx_p;
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

/******************************************************************************
    MMI FTP SCR CONTEXT
******************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__

#define MMI_BT_FTPC_MULPULL_LIST_INIT       100
#define MMI_BT_FTPC_MULPULL_LIST_INC         50
#define MMI_BT_FTPC_MULPULL_LIST_MAX        (2000/2)    /* restirct by ctrl buffer */

#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
#endif /* __MMI_FTC_SUPPORT__ */ 

/******************************************************************************
    MMI FTP SCR FUNCTIONS
******************************************************************************/
#ifdef __MMI_FTS_SUPPORT__
void mmi_bt_ftps_menu_hdlr_init(void);
void mmi_bt_ftps_setting_highlight_hdlr(void);
void mmi_bt_ftps_entry_ftp_setting(void);
void mmi_bt_ftps_shared_folder_hint(U16 index);
void mmi_bt_ftps_shared_folder_highlight_hdlr(void);
void mmi_bt_ftps_entry_shared_folder_menu(void);
void mmi_bt_ftps_fmgr_select_path_done(void *path, int is_short);
void mmi_bt_ftps_access_right_hint(U16 index);
void mmi_bt_ftps_access_right_highlight_hdlr(void);
void mmi_bt_ftps_accessright_highlight_hdlr(S32 index);
void mmi_bt_ftps_entry_access_right_menu(void);
#if 0
/* under construction !*/
#endif
void mmi_bt_ftps_entry_recv_confirm_scr(void);
void mmi_bt_ftps_notify_disconnected(void);
void mmi_bt_ftps_popup(U32 flag);
void mmi_bt_ftps_reset_clear_scrs(void);
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
void mmi_bt_ftpc_entry_connect_scr(void);
void mmi_bt_ftpc_entry_canceling(void);
void mmi_bt_ftpc_mmi_bt_ftpc_delscrifpresent(void);
void mmi_bt_ftpc_goback2history(void);
void mmi_bt_ftpc_clear_abort_scr(void);
void mmi_bt_ftpc_parse_folder_fail(void);
void mmi_bt_ftpc_entry_aborting(void);
void mmi_bt_ftpc_entry_back_to_parent_folder(void);
void mmi_bt_ftpc_notify_recv_err(mmi_ftpc_notify_enum cause);
void mmi_bt_ftpc_disconnect_clear_scrs(void);
void mmi_bt_ftpc_entry_file_browser(void);
void mmi_bt_ftpc_browser_history_replace(void);
void mmi_bt_ftpc_obj_receive_ind(void);
void mmi_bt_ftpc_reset_clear_scrs(void);
void mmi_bt_ftpc_AddHistory(U16 scr_id);
void mmi_bt_ftpc_entry_disconnecting(void);

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
void mmi_bt_ftpc_get_next_file(void);
void mmi_bt_ftpc_reset_pull_variable(void);
extern U8 mmi_bt_ftpc_is_first_file(void);
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 
#endif /* __MMI_FTC_SUPPORT__ */ 

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
void mmi_bt_ftp_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

#endif /* __BT_MMI_FTP_SCR_H__ */ 

