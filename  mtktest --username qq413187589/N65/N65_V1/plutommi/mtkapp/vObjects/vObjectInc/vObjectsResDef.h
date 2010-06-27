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
 * vObjectsResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is to define the resource id for vObjects
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VOBJECTSRESDEF_H
#define _MMI_VOBJECTSRESDEF_H

#include "MMIDataType.h"
/* if some header should be include before this one */
/* 
 * Define
 */

/* 
 * Typedef 
 */
typedef enum
{
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    MENU_ID_VOBJECT_SMS,
#endif 
#if defined(__MMI_IRDA_SUPPORT__)
    MENU_ID_VOBJECT_IRDA,
#endif 
#if defined(__MMI_FILE_MANAGER__)
    MENU_ID_VOBJECT_FILE,
#endif 
    MENU_ID_VOBJECT_TOTAL
} vobj_option_menu_id_enum;

typedef enum
{
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    MENU_ID_VOBJ_SMS,
#endif 
#if defined(__MMI_MMS__)
    MENU_ID_VOBJ_MMS,
#endif 
#if defined(EMAIL_APP_SUPPORT)
    MENU_ID_VOBJ_EMAIL,
#endif 
#if defined(__MMI_IRDA_SUPPORT__)
    MENU_ID_VOBJ_IRDA,
#endif 
#if defined(__MMI_FILE_MANAGER__)
    MENU_ID_VOBJ_FMGR,
#endif 
#ifdef __MMI_OPP_SUPPORT__
    MENU_ID_VOBJ_BT,
#endif 
    MENU_ID_VOBJ_TOTAL
} vobj_opt_enum;

typedef enum
{
    SCR_ID_VOBJ_RECV_OBJECT = VOBJECT_BASE + 1,
    SCR_ID_VOBJ_REVC_OBJECT_ABORT,
    SCR_ID_VOBJ_IRDA_FORWARD_PROCESSING
} vobj_scr_id_enum;

typedef enum
{
    STR_ID_VOBJ_RECV_VCARD = VOBJECT_BASE + 1,
    STR_ID_VOBJ_RECV_VCLNDR,
#ifdef __MMI_VBOOKMARK__
    STR_ID_VOBJ_RECV_VBKM,
#endif
    STR_ID_VOBJ_CANCEL_QUERY,
    STR_ID_VOBJ_FORWARD_TO_SMS,
    STR_ID_VOBJ_FORWARD_TO_MMS,
    STR_ID_VOBJ_FORWARD_TO_IRDA,
    STR_ID_VOBJ_FORWARD_TO_EMAIL,
    STR_ID_VOBJ_FORWARD_TO_FILE_MGR,
    STR_ID_VOBJ_FORWARD_TO_BT,
    STR_ID_VOBJ_FILENAME,
    STR_ID_VOBJ_INPUT_METHOD,
    STR_ID_VOBJ_EMPTY_FILENAME,
    STR_ID_VOBJ_DUPLICATE_FILENAME,
    STR_ID_VOBJ_INVALID_FILENAME,
    STR_ID_VOBJ_FILE_PATH_TOO_LONG,
    STR_ID_VOBJ_FORMAT_NOT_SUPPORT,
    STR_ID_VOBJ_FUNC_NOT_SUPPORTED,
    STR_ID_VOBJ_UNFINISHED,
    STR_ID_VCARD_SAVE_TO_SIM,
    STR_ID_VCARD_SAVE_TO_PHONE
} vobj_str_id_enum;

typedef enum
{
    SCR_ID_VCARD_FORWARD_OPTION = VCARD_BASE + 1,
    SCR_ID_VCARD_RECV_VIEW_DETAIL,
    SCR_ID_VCARD_ENTER_FILENAME,
    SCR_ID_VCARD_ENTER_FILENAME_OPT,
    SCR_ID_VCARD_RECV_OPT
} vcard_scr_id_enum;

typedef enum
{
    STR_ID_VCARD_NAME_EMPTY = VCARD_BASE + 1
} vcard_str_id_enum;

typedef enum
{
    SCR_ID_VCLNDR_FORWARD = VCALENDAR_BASE + 1,
    SCR_ID_VCLNDR_FILENAME,
    SCR_ID_VCLNDR_FILENAME_OPT,
    SCR_ID_VCLNDR_RECV_OPT
} vclndr_scr_id_enum;

typedef enum
{
    STR_ID_VCLNDR_FORWARD = VCALENDAR_BASE + 1,
    STR_ID_VCLNDR_SAVE_TO_TDL,
    STR_ID_VCLNDR_TASK_FULL
} vclndr_str_id_enum;

typedef enum
{
    VCLNDR_RECV_TDL,
#if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)
    VCLNDR_RECV_FILE,
#endif 
    VCLNDR_OPT_TOTAL
} vclndr_recv_opt_enum;

#ifdef __MMI_VBOOKMARK__
typedef enum
{
    SCR_ID_VBKM_RECEIVE_OPTION = VBOOKMARK_BASE + 1
} vbkm_scr_id_enum;

typedef enum
{
    STR_ID_VBKM_VIEW = VBOOKMARK_BASE + 1,
#if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)
	STR_ID_VBKM_SAVE_TO_FMGR,
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__) */
	STR_ID_VBKM_SAVE_TO_BOOKMARK
} vbkm_str_id_enum;
#endif

#endif /* _MMI_VOBJECTSRESDEF_H */

