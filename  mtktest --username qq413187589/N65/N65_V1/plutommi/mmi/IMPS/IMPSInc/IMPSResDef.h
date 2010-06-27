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
 * mmi_imps_enum.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines enum value for global resources used in IMPS application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_IMPS_ENUM_H
#define _MMI_IMPS_ENUM_H
#ifdef __MMI_IMPS__

/***************************************************************************** 
* Define
*****************************************************************************/
// #define IMPS_FOR_OMA_ONLY
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    IMG_ID_IMPS_MENU = (IMPS_BASE + 1),
    IMG_ID_IMPS_ONLINE,
    IMG_ID_IMPS_BUSY,
    IMG_ID_IMPS_OFFLINE,
    IMG_ID_IMPS_REFRESH,
    IMG_ID_IMPS_MESSAGE,
    IMG_ID_IMPS_BLOCK,
    IMG_ID_IMPS_ABOUT_DEFAULT,
    IMG_ID_IMPS_ABOUT_ONLINE,
    IMG_ID_IMPS_ABOUT_BUSY,
    IMG_ID_IMPS_ABOUT_OFFLINE,
    IMG_ID_IMPS_ABOUT_REFRESH,
    IMG_ID_IMPS_CONT_LIST,
    IMG_ID_IMPS_CHAT_ROOM,
    IMG_ID_IMPS_TALK,
    IMG_ID_IMPS_CHATROOM_MENU,
    IMG_ID_IMPS_TALK_MENU,
    IMG_ID_IMPS_HAPPY,      /* do not change the order */
    IMG_ID_IMPS_SAD,        /* do not change the order */
    IMG_ID_IMPS_ANGRY,      /* do not change the order */
    IMG_ID_IMPS_JEALOUS,    /* do not change the order */
    IMG_ID_IMPS_ASHAMED,    /* do not change the order */
    IMG_ID_IMPS_INVINCIBLE, /* do not change the order */
    IMG_ID_IMPS_IN_LOVE,    /* do not change the order */
    IMG_ID_IMPS_SLEEPY,     /* do not change the order */
    IMG_ID_IMPS_BORED,      /* do not change the order */
    IMG_ID_IMPS_EXCITED,    /* do not change the order */
    IMG_ID_IMPS_ANXIOUS     /* do not change the order */
} imps_img_id_enum;

typedef enum
{
    SCR_ID_IMPS_START = (IMPS_BASE + 1),
    SCR_ID_IMPS_MAIN,
    SCR_ID_IMPS_PROGRESS,
    SCR_ID_IMPS_CONT,
    SCR_ID_IMPS_PROF,
    SCR_ID_IMPS_PROF_OPT,
    SCR_ID_IMPS_PROF_EDIT,
    SCR_ID_IMPS_PROF_SETTING,
    SCR_ID_IMPS_COMM_FULL_EDIT_OPT,
    SCR_ID_IMPS_CONT_OPT,
    SCR_ID_IMPS_CONT_SEARCH,
    SCR_ID_IMPS_CONT_SEARCH_INLINE,
    SCR_ID_IMPS_ABOUT_ME,
    SCR_ID_IMPS_PRESENCE_INLINE,
    SCR_ID_IMPS_PRESENCE_SEL_FILE,
    SCR_ID_IMPS_PRESENCE_VIEW_PIC,
    SCR_ID_IMPS_PUBLIC_PROFILE_INLINE,
    SCR_ID_IMPS_SORT,
    SCR_ID_IMPS_CHAT,
    SCR_ID_IMPS_CHAT_OPT,
    SCR_ID_IMPS_INSERT_SYMBOL,
    SCR_ID_IMPS_CHAT_MEMBER,
    SCR_ID_IMPS_CHAT_MEMBER_OPT,
    SCR_ID_IMPS_CHAT_ADD_MEMBER,
    SCR_ID_IMPS_ADD_MEMBER_DIRECT,
    SCR_ID_IMPS_ADD_MEMBER_FROM_ONLINE,
    SCR_ID_IMPS_CHAT_REJECTED,
    SCR_ID_IMPS_CHAT_JOINED,
    SCR_ID_IMPS_CHAT_JOINED_OPT,
    SCR_ID_IMPS_CHAT_FILENAME,
    SCR_ID_IMPS_CHAT_SAVE_OPT,
    SCR_ID_IMPS_ADD_CONT,
    SCR_ID_IMPS_ADD_CONT_DIRECT,
    SCR_ID_IMPS_ADD_CONT_INPUT_NAME,
    SCR_ID_IMPS_ADD_CONT_INPUT_NAME_OPT,
    SCR_ID_IMPS_SEARCH_OPT,
    SCR_ID_IMPS_SEARCH_RESULT,
    SCR_ID_IMPS_WATCHER_LIST,
    SCR_ID_IMPS_GROUP,
    SCR_ID_IMPS_GROUP_OPT,
    SCR_ID_IMPS_GROUP_EDIT,
    SCR_ID_IMPS_CHAT_ROOM,
    SCR_ID_IMPS_CHAT_ROOM_OPT,
    SCR_ID_IMPS_CHAT_ROOM_OPEN,
    SCR_ID_IMPS_ROOM_JOIN_DIRECT,
    SCR_ID_IMPS_CHAT_ROOM_SEARCH,
    SCR_ID_IMPS_CHAT_ROOM_JOIN,
    SCR_ID_IMPS_LIST_GROUP_MEMBER,
    SCR_ID_IMPS_SELECT_GROUP,
    SCR_ID_IMPS_INVITE,
    SCR_ID_IMPS_INVITE_NOTE,
    SCR_ID_IMPS_CHAT_NOTE_OPT,
    SCR_ID_IMPS_ABOUT_FRIEND,
    SCR_ID_IMPS_ABOUT_FRIEND_OPT,
    SCR_ID_IMPS_INVITATION_IND,
    SCR_ID_IMPS_GROUP_BROADCAST,
    SCR_ID_IMPS_CHAT_TEXT_FORMAT,
    SCR_ID_IMPS_SYSTEM_MESSAGE,
    SCR_ID_IMPS_SYSTEM_MESSAGE_OPTION,
    SCR_ID_IMPS_VERIFICATION_KEY,
    SCR_ID_IMPS_PRESENCE_AUTHENTICATION,
    SCR_ID_IMPS_HTTP_AUTH,
    SCR_ID_IMPS_OTA_SETTING,
    SCR_ID_IMPS_OTA_PROF_LIST,
    SCR_ID_IMPS_INPUT_VERIFY_OPT,
    SCR_ID_IMPS_END
} imps_src_id_enum;

typedef enum
{
    STR_ID_IMPS = (IMPS_BASE + 1),
    STR_ID_IMPS_PROGRESSING,
    STR_ID_IMPS_LOGIN,
    STR_ID_IMPS_PROF,
    STR_ID_IMPS_PROF_SETTING,
    STR_ID_IMPS_PROF_CONN,
    STR_ID_IMPS_PROF_NAME,
    STR_ID_IMPS_SERVER,
    STR_ID_IMPS_USERNAME,
    STR_ID_IMPS_PASSWD,
    STR_ID_IMPS_AUTO_LOGIN,    
    STR_ID_IMPS_DATA_ACCT,
    STR_ID_IMPS_CONN_TYPE,
    STR_ID_IMPS_USE_PROXY,
    STR_ID_IMPS_PROXY_SERVER,
    STR_ID_IMPS_PROXY_PORT,
    STR_ID_IMPS_PROXY_USERNAME,
    STR_ID_IMPS_PROXY_PASSWD,
    STR_ID_IMPS_HTTP_AUTH_USERNAME,
    STR_ID_IMPS_HTTP_AUTH_PASSWD,    
    STR_ID_IMPS_WAP,
    STR_ID_IMPS_HTTP,
    STR_ID_IMPS_CONT_LIST,
    STR_ID_IMPS_ABOUT_ME,
    STR_ID_IMPS_WATCHER_LIST,
    STR_ID_IMPS_SEND_READ_MSG,
    STR_ID_IMPS_DEL_CONTACT,
    STR_ID_IMPS_BLOCK_CONTACT,
    STR_ID_IMPS_GRANT_CONTACT,
    STR_ID_IMPS_ADD_CONTACT,
    STR_ID_IMPS_SORT_LIST,
    STR_ID_IMPS_LOGOUT,
    STR_ID_IMPS_CHAT_ROOMS,
    STR_ID_IMPS_MANAGE_GROUPS,
    STR_ID_IMPS_MY_PROFILE,
    STR_ID_IMPS_STATUS,
    STR_ID_IMPS_MOOD,
    STR_ID_IMPS_MY_PICTURE,
    STR_ID_IMPS_SEL_FILE,
    STR_ID_IMPS_SEL_FROM_FILE,
    STR_ID_IMPS_ONLINE,
    STR_ID_IMPS_AWAY,
    STR_ID_IMPS_OFFLINE,
    STR_ID_IMPS_HAPPY,
    STR_ID_IMPS_SAD,
    STR_ID_IMPS_ANGRY,
    STR_ID_IMPS_JEALOUS,
    STR_ID_IMPS_ASHAMED,
    STR_ID_IMPS_INVINCIBLE,
    STR_ID_IMPS_IN_LOVE,
    STR_ID_IMPS_SLEEPY,
    STR_ID_IMPS_BORED,
    STR_ID_IMPS_EXCITED,
    STR_ID_IMPS_ANXIOUS,
    STR_ID_IMPS_LOAD_FROM_PHB,
    STR_ID_IMPS_SEARCH_CONTACT,
    STR_ID_IMPS_SEARCH_RESULT,
    STR_ID_IMPS_PHONE_NO,
    STR_ID_IMPS_ALIAS,
    STR_ID_IMPS_EMAIL,
    STR_ID_IMPS_EMPTY_USERNAME,    
    STR_ID_IMPS_PROF_NO_CONFIG,
    STR_ID_IMPS_SIZE_TOO_LARGE,
    STR_ID_IMPS_SORT_BY_NAME,
    STR_ID_IMPS_SORT_BY_STATUS,
    STR_ID_IMPS_SORT_BY_GROUP,    
    STR_ID_IMPS_INSERT_SYMBOL,
    STR_ID_IMPS_INVITE,
    STR_ID_IMPS_SAVE_TEXT,
    STR_ID_IMPS_MYSELF,
    STR_ID_IMPS_EMPTY_FILENAME,
    STR_ID_IMPS_DUPLICATE_FILENAME,
    STR_ID_IMPS_FILENAME_TOO_LONG,
    STR_ID_IMPS_EMPTY_INPUT,
    STR_ID_IMPS_JUMP_TO,
    STR_ID_IMPS_OPEN_CHAT_ROOM,
    STR_ID_IMPS_NAME,
    STR_ID_IMPS_TOPIC,
    STR_ID_IMPS_WELCOME_TEXT,
    STR_ID_IMPS_DISPLAY_NAME,
    STR_ID_IMPS_OWNER,
    STR_ID_IMPS_JOINED_USER,
    STR_ID_IMPS_JOIN,
    STR_ID_IMPS_LIST_MEMBER,
    STR_ID_IMPS_OPEN,
    STR_ID_IMPS_RESTRICT,
    STR_ID_IMPS_DELETE_MEMBER,
    STR_ID_IMPS_ACCESS_TYPE,
    STR_ID_IMPS_ADD_MEMBER,
    STR_ID_IMPS_LIST_REJECTED,
    STR_ID_IMPS_LIST_JOINED,
    STR_ID_IMPS_SET_MODERATOR,
    STR_ID_IMPS_SET_USER,
    STR_ID_IMPS_ADD_TO_MEM,
    STR_ID_IMPS_ADD_TO_REJ,
    STR_ID_IMPS_ADD_FROM_ONLINE,
    STR_ID_IMPS_MEMBER_EXISTS,
    STR_ID_IMPS_BROADCAST,
    STR_ID_IMPS_DISCLOSE_ID,
    STR_ID_IMPS_HIDE,
    STR_ID_IMPS_SHOW,
    STR_ID_IMPS_LIST_FULL,
    STR_ID_IMPS_GROUP_NOT_EMPTY,
    STR_ID_IMPS_CONTACT_EXIST,
    STR_ID_IMPS_SELECT_GROUP,
    STR_ID_IMPS_ANONYMOUS,
    STR_ID_IMPS_INVITE_NOTE,
    STR_ID_IMPS_MSG_CANNOT_SEND,    /* shall be removed */
    STR_ID_IMPS_INVITING,
    STR_ID_IMPS_INVITE_FAIL,
    STR_ID_IMPS_JOINED_ROOM,
    STR_ID_IMPS_REFRESH,
    STR_ID_IMPS_ERR_UNSUPPORT_SERVICE,
    STR_ID_IMPS_ERR_NOT_LOGIN,
    STR_ID_IMPS_ERR_ALREADY_LOGIN,
    STR_ID_IMPS_ERR_NETWORK_BUSY,
    STR_ID_IMPS_ERR_CONN_FAILED,
    STR_ID_IMPS_ERR_INVALID_PASSWD,
    STR_ID_IMPS_ERR_INVALID_USERNAME,
    STR_ID_IMPS_ERR_INVALID_SERVER,
    STR_ID_IMPS_ERR_ROOM_EXIST,
    STR_ID_IMPS_ERR_ROOM_NOT_EXIST,
    STR_ID_IMPS_ERR_CHAT_ROOM_FULL,
    STR_ID_IMPS_ERR_ABORT_FAIL,
    STR_ID_IMPS_ERR_AUTH_FAIL,
    STR_ID_IMPS_ERR_REQUEST_TIMEOUT,
    STR_ID_IMPS_ERR_MSG_SEND_FAIL,
    STR_ID_IMPS_ERR_CONT_FULL,
    STR_ID_IMPS_ERR_CONT_LIST_FULL,
    STR_ID_IMPS_ERR_SNAME_IN_USE,
    STR_ID_IMPS_ERR_ROOM_ALREADY_JOINED,
    STR_ID_IMPS_ERR_ROOM_NOT_JOINED,
    STR_ID_IMPS_ERR_ROOM_FULL,
    STR_ID_IMPS_ERR_NO_SEATCH_RESULT,
    STR_ID_IMPS_ERR_INVALID_PORT,
    STR_ID_IMPS_ERR_EMPTY_NAME,
    STR_ID_IMPS_ERR_EMPTY_DISP_NAME,
    STR_ID_IMPS_NEW_ROOM_CREATED,
    STR_ID_IMPS_WRITE_MSG,
    STR_ID_IMPS_ERR_NO_SPACE,
    STR_ID_IMPS_ERR_NO_GROUP,
    STR_ID_IMPS_ERR_UNKNOWN_ERROR,
    STR_ID_IMPS_ERR_INVALID_INPUT,
    STR_ID_IMPS_ERR_INVALID_REQUEST,
    STR_ID_IMPS_ERR_SERVER_NOT_SUPPORT,
    STR_ID_IMPS_ERR_SESSION_PROBLEM,
    STR_ID_IMPS_ERR_PRESENCE_PROBLEM,
    STR_ID_IMPS_ERR_GROUP_PROBLEM,
    STR_ID_IMPS_ERR_SEND_REQUEST_FAIL,
    STR_ID_IMPS_ERR_RECV_RESPONSE_FAIL,
    STR_ID_IMPS_ERR_TOO_BROAD_SEARCH_CRITERIA,
    STR_ID_IMPS_ERR_MSG_REJECT_BY_RECIPIENT,
    STR_ID_IMPS_ERR_FILE_ACCESS_ERROR,
    STR_ID_IMPS_ERR_CONT_NOT_READY,
    STR_ID_IMPS_ERR_CONT_NOT_ALL_SYNC,
    
    STR_ID_IMPS_ERR_SERVER_OR_NETWORK_ERROR,
    STR_ID_IMPS_ERR_NO_ENOUGH_SPACE,
    STR_ID_IMPS_ERR_NO_AVAILABLE_VERSION,
    STR_ID_IMPS_ERR_SYSTEM_MESSAGE_RESPONSE_REQUIRE,
    STR_ID_IMPS_ERR_TOO_MANY_WRONG_SM_RESPONSE,
    STR_ID_IMPS_ERR_UNKNOWN_SYSTEM_MESSAGE_ID,
    STR_ID_IMPS_ERR_INCORRECT_VERIFICATION_KEY,
    STR_ID_IMPS_ERR_MESSAGE_TOO_LARGE,
    STR_ID_IMPS_ERR_DATA_NOT_COMPLETE,
    
    STR_ID_IMPS_ERR_ID_TOO_LONG,
    STR_ID_IMPS_ERR_PSW_TOO_LONG,
    STR_ID_IMPS_EMPTY_FRIENDLY_NAME,
	STR_ID_IMPS_INVALID_FRIENDLY_NAME,
    
    STR_ID_IMPS_VIEW_CONT_DETAIL,
    STR_ID_IMPS_NOT_READY,
    STR_ID_IMPS_INVITATION,
    STR_ID_IMPS_SERVER_DISCONNECT,
    STR_ID_IMPS_LEFT_CHAT_ROOM,
    STR_ID_IMPS_CHANGE_NICK_NAME,
    STR_ID_IMPS_SUBSCRIBE,
    STR_ID_IMPS_UNSUBSCRIBE,
    STR_ID_IMPS_ADD_DIRECTLY,
    STR_ID_IMPS_CHAT_ROOM_NAME,
    STR_ID_IMPS_ROOM_JOIN,
    STR_ID_IMPS_INVALID_GROUP_NAME,
    STR_ID_IMPS_CHAT_ROOM_CLOSE,
    STR_ID_IMPS_NEW_INVITATION,
    STR_ID_IMPS_NEW_INVITE_REMINDER,
    STR_ID_IMPS_ROOM_ID,
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* Maritail status */
    STR_ID_IMPS_NO_DISCLOSE,       /* do not change the order */
    STR_ID_IMPS_COHABITANT,   /* do not change the order */
    STR_ID_IMPS_DIVORCED,     /* do not change the order */
    STR_ID_IMPS_ENGAGED,      /* do not change the order */
    STR_ID_IMPS_MARRIED,      /* do not change the order */
    STR_ID_IMPS_SINGLE,       /* do not change the order */
    STR_ID_IMPS_WIDOWED,      /* do not change the order */
    STR_ID_IMPS_UNSPECIFIED,  /* do not change the order */
    STR_ID_IMPS_SUBSCRIBE_NOTIFY,     /* subscribe notify */
    STR_ID_IMPS_UNSUBSCRIBE_NOTIFY,    /* unsubscribe notify */
    STR_ID_IMPS_PRESENCE,
    STR_ID_IMPS_PUBLIC_PROFILE_1,
    STR_ID_IMPS_PUBLIC_PROFILE_2,
    STR_ID_IMPS_MALE,
    STR_ID_IMPS_FEMALE,
    STR_ID_IMPS_AGE,
    STR_ID_IMPS_FRIENDLY_NAME,
    STR_ID_IMPS_CITY,
    STR_ID_IMPS_FREE_TEXT,
    STR_ID_IMPS_GENDER,
    STR_ID_IMPS_INTENTION,
    STR_ID_IMPS_HOBBIES,
    STR_ID_IMPS_MARITAL_STATUS,
    STR_ID_IMPS_FIRST_NAME,
    STR_ID_IMPS_LAST_NAME,
    STR_ID_IMPS_USERID,
    STR_ID_IMPS_MAX_AGE,
    STR_ID_IMPS_MIN_AGE,
    STR_ID_IMPS_AUTO_JOINED_USER,
    STR_ID_IMPS_TEXT_FORMAT,
    STR_IMPS_TEXT_SIZE_DEFAULT,  /* do not change the order */
    STR_IMPS_TEXT_SIZE_TINY,     /* do not change the order */
    STR_IMPS_TEXT_SIZE_SMALL,    /* do not change the order */
    STR_IMPS_TEXT_SIZE_MEDIUM,   /* do not change the order */
    STR_IMPS_TEXT_SIZE_BIG,      /* do not change the order */
    STR_IMPS_TEXT_SIZE_HUGE,     /* do not change the order */
    STR_IMPS_TEXT_COLOR_DEFAULT, /* do not change the order */
    STR_IMPS_TEXT_COLOR_BLACK,   /* do not change the order */
    STR_IMPS_TEXT_COLOR_GREEN,   /* do not change the order */
    STR_IMPS_TEXT_COLOR_SILVER,  /* do not change the order */
    STR_IMPS_TEXT_COLOR_LIME,    /* do not change the order */
    STR_IMPS_TEXT_COLOR_GRAY,    /* do not change the order */
    STR_IMPS_TEXT_COLOR_OLIVE,   /* do not change the order */
    STR_IMPS_TEXT_COLOR_WHITE,   /* do not change the order */
    STR_IMPS_TEXT_COLOR_YELLOW,  /* do not change the order */
    STR_IMPS_TEXT_COLOR_MAROON,  /* do not change the order */
    STR_IMPS_TEXT_COLOR_NAVY,    /* do not change the order */
    STR_IMPS_TEXT_COLOR_RED,     /* do not change the order */
    STR_IMPS_TEXT_COLOR_BLUE,    /* do not change the order */
    STR_IMPS_TEXT_COLOR_PURPLE,  /* do not change the order */
    STR_IMPS_TEXT_COLOR_TEAL,    /* do not change the order */
    STR_IMPS_TEXT_COLOR_FUCHSIA, /* do not change the order */
    STR_IMPS_TEXT_COLOR_AQUA,     /* do not change the order */
    STR_ID_IMPS_TEXT_BOLD,
    STR_ID_IMPS_TEXT_ITALIC,
    STR_ID_IMPS_TEXT_UNDERLINE,
    STR_ID_IMPS_TEXT_COLOR,
    STR_ID_IMPS_TEXT_SIZE,
    STR_ID_IMPS_SEND_FILE,
    STR_ID_IMPS_SYSTEM_MESSAGE,
    STR_ID_IMPS_SYSTEM_MESSAGE_HELP,
    STR_ID_IMPS_VERIFICATION_KEY,
    STR_ID_IMPS_ADD_TO_ANOTHER_LIST,
    STR_ID_IMPS_AUTHORIZATION_CHANGED,
    STR_ID_IMPS_AUTHORIZATION_NEEDED_CONTACTLIST,
    STR_ID_IMPS_AUTHORIZATION_NEEDED_DEFAULTLIST,
    STR_ID_IMPS_AUTHORIZATION_NEEDED_USER,
    STR_ID_IMPS_BLOCK_LIST_CHANGED,
    STR_ID_IMPS_BLOCK_LIST_USAGECHANGE,
    STR_ID_IMPS_CONTACT_LIST_CREATED,
    STR_ID_IMPS_CONTACT_LIST_CHANGED,
    STR_ID_IMPS_CONTACT_LIST_DELETED,
    STR_ID_IMPS_GRANT_LIST_CHANGED,
    STR_ID_IMPS_GRANT_LIST_USAGECHANGE,
    STR_ID_IMPS_GROUP_CREATED,
    STR_ID_IMPS_GROUP_DELETED,
    STR_ID_IMPS_GROUP_MEMBERACCESS_UPDATED,
    STR_ID_IMPS_GROUP_MEMBER_UPDATED,
    STR_ID_IMPS_GROUP_MEMBERSHIP_GRANTED,
    STR_ID_IMPS_GROUP_MEMBERSHIP_REVOKED,
    STR_ID_IMPS_GROUP_REMOVED,
    STR_ID_IMPS_INVITATION_ACCEPTED,
    STR_ID_IMPS_INVITATION_CANCELLED,
    STR_ID_IMPS_INVITATION_REJECTED,
    STR_ID_IMPS_ONLINEETEMHANDLING_UPDATED,
    STR_ID_IMPS_PUBLIC_PROFILE_UPDATED,
    STR_ID_IMPS_SESSION_PRIORITY_ADJUSTED,
    STR_ID_IMPS_USER_ID_CHANGED,
    STR_ID_IMPS_RECEIVE_NEW_FILE,
    STR_ID_IMPS_NEW_PA_AUTH,
    STR_ID_IMPS_PRESENCE_AUTHENTICATION,
    STR_ID_IMPS_ACCEPT,
    STR_ID_IMPS_REJECT,
    STR_ID_IMPS_PA_AUTH_NOTE,
    STR_ID_IMPS_NEW_SYSTEM_MESSAGE,
    STR_ID_IMPS_CONTENT_POLICY_EXTRA_COST,
    STR_ID_IMPS_CONTENT_POLICY_REJECT,
    STR_ID_IMPS_NEW_FILE_FROM,
    STR_ID_IMPS_ERR_PP_NOT_COMPLETE,
    STR_ID_IMPS_TEXT_VERIFICATION,
    STR_ID_IMPS_URL_VERIFICATION,
    STR_ID_IMPS_ACCOUNT_INFO,
    STR_ID_IMPS_GOTO,
    STR_ID_IMPS_EMPTY_FILE
} imps_str_id_enum;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#endif /* __MMI_IMPS__ */ /* #ifdef __MMI_IMPS__ */
#endif /* _MMI_IMPS_ENUM_H */ 

