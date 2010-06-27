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
 *	Res_IMPS.c
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *	This file populates resource for IMPS appliction.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_RES_IMPS_C
#define _MMI_RES_IMPS_C
#include "MMI_features.h"

#ifdef __MMI_IMPS__

#include "MMIDataType.h"
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "IMPSResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"


    void PopulateIMPSData (void)
    {
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_MENU, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\SB_IMPS.bmp", "sub menu icon");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_BUSY, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Busy.bmp", "Busy image");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ONLINE, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Online.bmp", "Online image");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_OFFLINE, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Offline.bmp", "Offline image");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_REFRESH, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Refresh.bmp", "Ashamed symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_MESSAGE, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Message.bmp", "Message image");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_BLOCK, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Contact\\\\IM_Block.bmp", "Block image");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ABOUT_DEFAULT, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\About\\\\IM_Default.gif", "default image for About Me screen");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ABOUT_BUSY, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\About\\\\IM_SBusy.bmp", "Busy small icon for About Me screen");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ABOUT_OFFLINE, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\About\\\\IM_SOffline.bmp", "Offline small icon for About Me screen");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ABOUT_ONLINE, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\About\\\\IM_SOnline.bmp", "Online small icon for About Me screen");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ABOUT_REFRESH, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\About\\\\IM_SRefresh.bmp", "Refresh small icon for About Me screen");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_CONT_LIST, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_ContactList.bmp", "Contact list tab image");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_CHAT_ROOM, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_ChatRoom.bmp", "Chat room tab image");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_TALK, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Tab\\\\IM_Talk.bmp", "Single talk tab image");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_CHATROOM_MENU, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\ChatRoom\\\\SB_CHAT.bmp", "Chat room menu icon");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_TALK_MENU, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\ChatRoom\\\\SB_TALK.bmp", "Single talk menu icon");

    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_HAPPY, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Happy.bmp", "Happy symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_SAD, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Sad.bmp", "Sad symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ANGRY, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Angry.bmp", "Angry symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_JEALOUS, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Jealous.bmp", "Jealous symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ASHAMED, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Ashamed.bmp", "Ashamed symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_INVINCIBLE, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Invincible.bmp", "Invincible symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_IN_LOVE, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Inlove.bmp", "In Love symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_SLEEPY, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Sleepy.bmp", "Sleepy symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_BORED, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Bored.bmp", "Bored symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_EXCITED, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Excited.bmp", "Excited symbol");
    ADD_APPLICATION_IMAGE2 ( IMG_ID_IMPS_ANXIOUS, CUST_IMG_PATH"\\\\MainLCD\\\\IMPS\\\\Chat\\\\IM_Anxious.bmp", "Anxious symbol");

    ADD_APPLICATION_STRING2 (STR_ID_IMPS, "Instant Message", "Instant Message String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROGRESSING, "Progressing", "Progressing String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_LOGIN, "Login", "Login String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROF, "Profile", "Profile String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROF_SETTING, "Profile Setting", "Profile Setting String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROF_CONN, "Connection Setting", "Connection Setting Signature String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROF_NAME, "Profile Name", "Profile Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SERVER, "Server", "Server String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_USERNAME, "User Name", "User Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PASSWD, "Password", "Password String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_AUTO_LOGIN, "Auto Login", "Auto Login String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_DATA_ACCT, "Data Account", "Data Account String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CONN_TYPE, "Connection Type", "Connection Type String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_USE_PROXY, "Use Proxy", "Use Proxy String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROXY_SERVER, "Proxy Server", "Proxy Server String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROXY_PORT, "Proxy Port", "Proxy Port String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROXY_USERNAME, "Proxy User Name", "Proxy Port String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROXY_PASSWD, "Proxy Password", "Proxy Port String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_WAP, "WAP", "WAP String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_HTTP, "HTTP", "HTTP String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ABOUT_ME, "About Me", "About Me String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_WATCHER_LIST, "Watcher List", "Watcher List String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_DEL_CONTACT, "Delete Contact", "Delete Contact String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SEND_READ_MSG, "Send/Read Message", "Send/Read Message String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_BLOCK_CONTACT, "Block", "Block String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GRANT_CONTACT, "Grant", "Grant String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ADD_CONTACT, "Add Contact", "Add Contact String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SORT_LIST, "Sort List", "Sort List String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_LOGOUT, "Logout", "Logout String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CHAT_ROOMS, "Chat Rooms", "Chat Rooms String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MANAGE_GROUPS, "Manage Groups", "Manage Groups String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MY_PROFILE, "My Profile", "My Profile String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_STATUS, "Status", "Status String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MOOD, "Mood", "Mood String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MY_PICTURE, "My Picture", "My Picture String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SEL_FILE, "Select File", "Select File String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ONLINE, "Online", "Online String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_OFFLINE, "Offline", "Offline String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_AWAY, "Away", "Away String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_HAPPY, "Happy", "Happy String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SAD, "Sad", "Sad String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ANGRY, "Angry", "Angry String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_JEALOUS, "Jealous", "Jealous String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ASHAMED, "Ashamed", "Ashamed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVINCIBLE, "Invincible", "Invincible String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_IN_LOVE, "In Love", "In Love String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SLEEPY, "Sleepy", "Sleepy String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_BORED, "Bored", "Bored String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_EXCITED, "Excited", "Excited String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ANXIOUS, "Anxious", "Anxious String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SEARCH_CONTACT, "Search Contact", "Search Contact String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SEARCH_RESULT, "Search Result", "Search Result String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PHONE_NO, "Phone Number", "Phone Number String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ALIAS, "Alias", "Alias String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_EMAIL, "Email Address", "Email Address String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_EMPTY_USERNAME, "Empty Username", "Empty Username String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PROF_NO_CONFIG, "Profile Not Configured", "Profile Not Configured String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SEL_FROM_FILE, "Select From File", "Select From File String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SIZE_TOO_LARGE, "Size Too Large", "Size Too Large String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CONT_LIST, "Contact List", "Contact List String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_LOAD_FROM_PHB, "Load From Phonebook", "Load From Phonebook String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SORT_BY_NAME, "By Username", "By Username String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SORT_BY_STATUS, "By Status", "By Status String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SORT_BY_GROUP, "By Group", "By Group String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INSERT_SYMBOL, "Insert Symbol", "Insert Symbol String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVITE, "Invite Friend", "Invite Friend String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SAVE_TEXT, "Save Text", "Save Text String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MYSELF, "Myself", "Myself String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_EMPTY_FILENAME, "Empty Filename", "File Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_DUPLICATE_FILENAME, "Duplicated Filename", "Duplicated Filename String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_FILENAME_TOO_LONG, "Filename Too Long", "Filename Too Long String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_EMPTY_INPUT, "Empty Input", "Empty Input String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_JUMP_TO, "Jump To", "Jump To String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_OPEN_CHAT_ROOM, "Create", "Create String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NAME, "Name", "Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_TOPIC, "Topic", "Topic String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_WELCOME_TEXT, "Welcome", "Welcome String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_DISPLAY_NAME, "Nick Name", "Nick Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_OWNER, "Owner", "Owner String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_JOINED_USER, "Joined User", "Joined User String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_JOIN, "Join", "Join String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_LIST_MEMBER, "List Members", "List Members String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_DISCLOSE_ID, "Disclose User ID", "Disclose User ID String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_HIDE, "Hide", "Hide String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SHOW, "Show", "Show String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GROUP_NOT_EMPTY, "Group Not Empty", "Group Not Empty String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CONTACT_EXIST, "Contact Exists", "Contact Exists String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SELECT_GROUP, "Select Group", "Select Group String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ANONYMOUS, "<Anonymous>", "<Anonymous> String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVITE_NOTE, "Invitation", "Invitation String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MSG_CANNOT_SEND, "<Message sent failed>", "<Message sent failed> String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVITING, "Inviting", "Inviting String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVITE_FAIL, "Failed to invite:", "Failed to invite: String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_JOINED_ROOM, "Joined Chat Room", "Joined Chat Room String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_REFRESH, "Refresh Data", "Refresh Data String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_UNSUPPORT_SERVICE, "Unsupported Service", "Unsupported Service String");

    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_NOT_LOGIN, "Not Yet Login", "Not Yet Login String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ALREADY_LOGIN, "Already Login", "Already Login String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_CONN_FAILED, "Connection Failed", "Connection Failed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_INVALID_PASSWD, "Invalid Password", "Invalid Password String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_INVALID_USERNAME, "Invalid Username", "Invalid Username String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_INVALID_SERVER, "Invalid Server", "Invalid Server String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_CHAT_ROOM_FULL, "Chat Room Full", "Chat Room Full String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ROOM_EXIST, "Chat Room Already Exists", "Chat Room Already Exists String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ROOM_NOT_EXIST, "Chat Room Not Exists", "Chat Room Not Exists String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ROOM_NOT_JOINED, "Chat Room Not Joined", "Chat Room Not Joined String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ABORT_FAIL, "Abort Failed", "Abort Failed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_AUTH_FAIL, "Athorization Failed", "Athorization Failed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_REQUEST_TIMEOUT, "Request Timeout", "Request Timeout String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_MSG_SEND_FAIL, "Message Sent Failed", "Message Sent Failed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_TOO_BROAD_SEARCH_CRITERIA, "Criterion Too Simple", "Criterion Too Simple String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_CONT_FULL, "Contact Full", "Contact Full String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_CONT_LIST_FULL, "Group Full", "Group Full String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_SNAME_IN_USE, "Duplicated Display Name", "Duplicated Display Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ROOM_ALREADY_JOINED, "Already Joined Chat Room", "Already Joined Chat Room String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ROOM_NOT_JOINED, "Chat Room Not Joined", "Chat Room Not Joined String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ROOM_FULL, "Chat Room Full", "Chat Room Full String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_NO_SEATCH_RESULT, "No Search Result", "No Search Result String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_INVALID_PORT, "Invalid Port Number", "Invalid Port Number String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_EMPTY_NAME, "Empty Name", "Empty Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_EMPTY_DISP_NAME, "Empty Nick Name", "Empty Nick Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NEW_ROOM_CREATED, "New Chat Room Opened", "New Chat Room Opened String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_WRITE_MSG, "Write Message", "Write Message String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_NO_SPACE, "No Space", "No Space String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_NO_GROUP, "No Group Created", "No Group Created String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_UNKNOWN_ERROR, "Unknown Error", "Unknown Error String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_INVALID_INPUT, "Invalid Input", "Invalid Input String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_INVALID_REQUEST, "Invalid Request", "Invalid Request String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_SESSION_PROBLEM, "Session Problem", "Session Problem String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_PRESENCE_PROBLEM, "Presence Problem", "Presence Problem String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_SERVER_NOT_SUPPORT, "Server Not Support", "Server Not Support String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_GROUP_PROBLEM, "Server Not Support", "Server Not Support String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_SEND_REQUEST_FAIL, "Request Send Failed", "Request Send Failed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_RECV_RESPONSE_FAIL, "Request Received Failed", "Request Received Failed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_MSG_REJECT_BY_RECIPIENT, "Request Rejected By Receiver", "Request Rejected By Receiver String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_FILE_ACCESS_ERROR, "File Access Error", "File Access Error String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_CONT_NOT_READY, "Contact Data Not Ready", "Contact Data Not Ready String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_NETWORK_BUSY, "Network Busy", "Network Busy String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_VIEW_CONT_DETAIL, "View Contact Detail", "View Contact Detail String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NOT_READY, "Application Not Ready", "Application Not Ready String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVITATION, "Invitation", "Invitation String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SERVER_DISCONNECT, "Server Disconnected", "Server Disconnected String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_LEFT_CHAT_ROOM, "Left Chat Room", "Left Chat Room String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CHANGE_NICK_NAME, "Change Nick Name", "Change Nick Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ADD_DIRECTLY, "Add Directly", "Add Directly String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CHAT_ROOM_NAME, "Room Name", "Room Name String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ROOM_JOIN, "Join Chat Room Name", "Join Chat Room String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVALID_GROUP_NAME, "Invalid Name", "Invalid Name String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CHAT_ROOM_CLOSE, "Chat Room Closed", "Chat Room Closed String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NEW_INVITATION, "New Invitation", "New Invitation String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NEW_INVITE_REMINDER, "Invitation Reminder", "Invitation Reminder String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ROOM_ID, "Room ID", "Room ID String");

    ADD_APPLICATION_STRING2 (STR_ID_IMPS_OPEN, "Open", "Open String"); 
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_RESTRICT, "Restrict", "Restrict String"); 
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_DELETE_MEMBER, "Delete Member", "Delete Member String");   
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ACCESS_TYPE, "Access Type", "Access Type String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ADD_MEMBER, "Add Member", "Add Member String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_LIST_REJECTED, "List Rejected", "List Rejected String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_LIST_JOINED, "List Joined", "List Joined String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SET_MODERATOR, "Set as Moderator", "Set as Moderator String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SET_USER, "Set as User", "Set as User String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ADD_TO_MEM, "Add to Member", "Add to Member String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ADD_TO_REJ, "Add to Rejected", "Add to Rejected String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ADD_FROM_ONLINE, "Add from online", "Add from online String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MEMBER_EXISTS, "Member already exists", "Member already exists String"); 

    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SUBSCRIBE_NOTIFY, "Subscribe Notify", "Subscribe Notify String"); 
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_UNSUBSCRIBE_NOTIFY, "Unsubscribe Notify", "Unsubscribe Notify String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PRESENCE, "Presence", "Presence String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PUBLIC_PROFILE_1, "Basic", "Public profile String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PUBLIC_PROFILE_2, "Additional", "Public profile String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MALE, "Male", "Male String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_FEMALE, "Female", "Female String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_COHABITANT, "Cohabitant", "Cohabitant String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_DIVORCED, "Divorced", "Divorced String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ENGAGED, "Engaged", "Engaged String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MARRIED, "Married", "Married String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SINGLE, "Single", "Single String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_WIDOWED, "Widowed", "Widowed String");    
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_UNSPECIFIED, "Unspecified", "Unspecified String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NO_DISCLOSE, "No Disclose", "No Disclose String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_AGE, "Age", "Age String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_FRIENDLY_NAME, "Friendly Name", "Friendly Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CITY, "City", "City String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_FREE_TEXT, "Free Text", "Free Text String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GENDER, "Gender", "Gender String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INTENTION, "Intention", "Intention String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_HOBBIES, "Hobbies", "Hobbies String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MARITAL_STATUS, "Marital Status", "Marital Status String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_FIRST_NAME, "First Name", "First Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_LAST_NAME, "Last Name", "Last Name String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_USERID, "User ID", "User ID String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MAX_AGE, "Max Age", "Max Age String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_MIN_AGE, "Min Age", "Min Age String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_AUTO_JOINED_USER, "Auto Joined User", "Auto Joined User String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_TEXT_FORMAT, "Text Format", "Text Format String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_SIZE_DEFAULT, "Default", "Default String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_SIZE_TINY, "Tiny", "Tiny String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_SIZE_SMALL, "Small", "Small String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_SIZE_MEDIUM, "Medium", "Medium String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_SIZE_BIG, "Big", "Big String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_SIZE_HUGE, "Huge", "Huge String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_DEFAULT, "Default", "Default String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_BLACK, "Black", "Black String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_GREEN, "Green", "Green String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_SILVER, "Silver", "Silver String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_LIME, "Lime", "Lime String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_GRAY, "Gray", "Gray String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_OLIVE, "Olive", "Olive String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_WHITE, "White", "White String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_YELLOW, "Yellow", "Yellow String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_MAROON, "Maroon", "Maroon String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_NAVY, "Navy", "Navy String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_RED, "Red", "Red String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_BLUE, "Blue", "Blue String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_PURPLE, "Purple", "Purple String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_TEAL, "Teal", "Teal String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_FUCHSIA, "Fuchsia", "Fuchsia String");
    ADD_APPLICATION_STRING2 (STR_IMPS_TEXT_COLOR_AQUA, "Aqua", "Aqua String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_TEXT_BOLD, "Bold", "Bold String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_TEXT_ITALIC, "Italic", "Italic String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_TEXT_UNDERLINE, "Underline", "Underline String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_TEXT_COLOR, "Color", "Color String");    
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_TEXT_SIZE, "Size", "Size String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SEND_FILE, "Send File", "Send File String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SYSTEM_MESSAGE, "System Message", "System Message String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SYSTEM_MESSAGE_HELP, "Press Num n, and then OK", "Press Num n, and then OK String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_VERIFICATION_KEY, "Verification Key", "Verification Key String");

    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_SERVER_OR_NETWORK_ERROR, "Server or Network error", "Server or Network error String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_NO_ENOUGH_SPACE, "Not Enough Space", "Not Enough Space String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_NO_AVAILABLE_VERSION, "Not Available Version", "Not Available Version String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_SYSTEM_MESSAGE_RESPONSE_REQUIRE, "System Message Response Require", "System Message Response Require String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_TOO_MANY_WRONG_SM_RESPONSE, "Too Many Wrong System Message Response", "Too Many Wrong System Message Response String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_UNKNOWN_SYSTEM_MESSAGE_ID, "Unknown System Message ID", "Unknown System Message ID String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_INCORRECT_VERIFICATION_KEY, "Incorrect Verification Key", "Incorrect Verification Key String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_MESSAGE_TOO_LARGE, "Message Too Large", "Message Too Large String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_DATA_NOT_COMPLETE, "Data Not Complete", "Data Not Complete String");

    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ADD_TO_ANOTHER_LIST, "Add You to His(Her) Contact List", "Add You to His(Her) Contact List String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_AUTHORIZATION_CHANGED, "Authorization Changed", "Authorization Changed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_AUTHORIZATION_NEEDED_CONTACTLIST, "Authorization needed contact list", "Authorization needed contact list String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_AUTHORIZATION_NEEDED_DEFAULTLIST, "Authorization needed default list", "Authorization needed default list String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_AUTHORIZATION_NEEDED_USER, "Authoriztion needed user", "Authoriztion needed user String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_BLOCK_LIST_CHANGED, "Block list changed", "Block list changed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_BLOCK_LIST_USAGECHANGE, "Block list usage changed", "Block list usage changed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CONTACT_LIST_CREATED, "Contact list created", "Contact list created String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CONTACT_LIST_CHANGED, "Contact list changed", "Contact list changed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CONTACT_LIST_DELETED, "Contact list deleted", "Contact list deleted String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GRANT_LIST_CHANGED, "Grant list changed", "Grant list changed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GRANT_LIST_USAGECHANGE, "Grant list usage changed", "Grant list usage changed String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GROUP_CREATED, "Chat room created", "Chat room created String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GROUP_DELETED, "Chat room deleted", "Chat room deleted String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GROUP_MEMBERACCESS_UPDATED, "Chat room member access updated", "Chat room member access updated String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GROUP_MEMBER_UPDATED, "Chat room member updated", "Chat room member updated String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GROUP_MEMBERSHIP_GRANTED, "Chat room membership granted", "Chat room membership granted String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GROUP_MEMBERSHIP_REVOKED, "Chat room membership revoked", "Chat room membership revoked String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GROUP_REMOVED, "Chat room removed by server", "Chat room removed by server String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVITATION_ACCEPTED, "Invitation accepted", "Invitation accepted String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVITATION_CANCELLED, "Invitation cancelled", "Invitation cancelled String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVITATION_REJECTED, "Invitation rejected", "Invitation rejected String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ONLINEETEMHANDLING_UPDATED, "Online etem handling updated", "Online etem handling updated String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PUBLIC_PROFILE_UPDATED, "Public profile updated", "Public profile updated String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SESSION_PRIORITY_ADJUSTED, "Session priority adjusted", "Session priority adjusted String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_USER_ID_CHANGED, "User id changed", "User id changed String");

    ADD_APPLICATION_STRING2 (STR_ID_IMPS_RECEIVE_NEW_FILE, "New file received", "New file received String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NEW_PA_AUTH, "New presence authentication", "New presence authentication String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PRESENCE_AUTHENTICATION, "Authentication", "Authentication String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ACCEPT, "Accept", "Accept String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_REJECT, "Reject", "Reject String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_PA_AUTH_NOTE, "Subscribe your presence attribute, Accept?", "Subscribe your presence attribute, Accept? String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NEW_SYSTEM_MESSAGE, "New System Message", "New System Message String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CONTENT_POLICY_EXTRA_COST, "Some extra charge will be added, Continue?", "CONTENT_POLICY_EXTRA_COST String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_CONTENT_POLICY_REJECT, "The content is larger than the limitation", "CONTENT_POLICY_REJECT String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_NEW_FILE_FROM, "New file from:", "New file from String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_PP_NOT_COMPLETE, "Public profile not complete", "Public profile not complete");    
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_TEXT_VERIFICATION, "Edit the verification key", "Edit the verification key String");        
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_URL_VERIFICATION, "Goto the URL for verification", "Goto the URL for verification String");    
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ACCOUNT_INFO, "Your account information", "Your account information");    
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_GOTO, "Goto", "Goto");
    
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_EMPTY_FILE, "Empty File", "Empty File");
        
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_ID_TOO_LONG, "User ID too long", "User ID too long string");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_ERR_PSW_TOO_LONG, "Password too long", "Password ID too long string");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_HTTP_AUTH_USERNAME, "HTTP Auth Username", "HTTP Auth Username string");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_HTTP_AUTH_PASSWD, "HTTP Auth Password", "HTTP Auth Password string");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_EMPTY_FRIENDLY_NAME, "Empty friendly name", "Empty friendly name");
	ADD_APPLICATION_STRING2 (STR_ID_IMPS_INVALID_FRIENDLY_NAME, "Invalid friendly name", "Invalid friendly name");
    
    

#ifdef IMPS_FOR_OMA_ONLY
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_SUBSCRIBE, "Subscribe", "Subscribe String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_UNSUBSCRIBE, "Unsubscribe", "Subscribe String");
    ADD_APPLICATION_STRING2 (STR_ID_IMPS_BROADCAST, "Broadcast", "Broadcast String");
#endif

    /* Login/Profile Setting */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_MAIN, MAIN_MENU_MESSAGES_MENUID,
    						2,
    						MENU_ID_IMPS_LOGIN,
    						MENU_ID_IMPS_PROF,
    						SHOW, SHORTCUTABLE, DISP_LIST,
    						STR_ID_IMPS, IMG_ID_IMPS_MENU));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_LOGIN, MENU_ID_IMPS_MAIN,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LOGIN, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF, MENU_ID_IMPS_MAIN,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_PROF, 0));
    /* Profile */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF_OPT, 0,
    						2,
    						MENU_ID_IMPS_PROF_ACTIVATE,
    						MENU_ID_IMPS_PROF_EDIT,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF_ACTIVATE, MENU_ID_IMPS_PROF_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_ACTIVATE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF_EDIT, MENU_ID_IMPS_PROF_OPT,
    						2,
    						MENU_ID_IMPS_PROF_SETTING,
    						MENU_ID_IMPS_PROF_CONN,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_EDIT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF_SETTING, MENU_ID_IMPS_PROF_EDIT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_PROF_SETTING, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF_CONN, MENU_ID_IMPS_PROF_EDIT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_PROF_CONN, 0));

    /* Done, Input Method */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF_EDITOR_OPT, 0,
    						2,
    						MENU_ID_IMPS_PROF_EDITOR_OPT_DONE,
    						MENU_ID_IMPS_PROF_EDITOR_OPT_INPUT_METH,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF_EDITOR_OPT_DONE, MENU_ID_IMPS_PROF_EDITOR_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PROF_EDITOR_OPT_INPUT_METH, MENU_ID_IMPS_PROF_EDITOR_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_INPUT_METHOD, 0));

     /* Done, Input Method */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_INPUT_VERIFY_OPT, 0,
    						2,
    						MENU_ID_IMPS_INPUT_VERIFY_OPT_DONE,
    						MENU_ID_IMPS_INPUT_VERIFY_OPT_INPUT_METH,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_INPUT_VERIFY_OPT_DONE, MENU_ID_IMPS_INPUT_VERIFY_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_INPUT_VERIFY_OPT_INPUT_METH, MENU_ID_IMPS_INPUT_VERIFY_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_INPUT_METHOD, 0));

    /* options for contact list */
    /* option for myself */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_MY_OPT, 0,
    						8, 
    						MENU_ID_IMPS_CONT_ABOUT_ME,
    						MENU_ID_IMPS_CONT_WATCHER_LIST,
    						MENU_ID_IMPS_CONT_ADD,
    						MENU_ID_IMPS_CONT_CHAT_ROOMS,
    						MENU_ID_IMPS_CONT_MANAGE_GROUP,
    						MENU_ID_IMPS_CONT_SUBS_UNSUBS_NOTIFY,
    						MENU_ID_IMPS_CONT_SORT,
    						MENU_ID_IMPS_CONT_LOGOUT,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_ABOUT_ME, MENU_ID_IMPS_CONT_MY_OPT,
    						3, 
    						MENU_ID_IMPS_CONT_PRESENCE,
    						MENU_ID_IMPS_CONT_PUBLIC_PROFILE_1,
    						MENU_ID_IMPS_CONT_PUBLIC_PROFILE_2,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ABOUT_ME, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_WATCHER_LIST, MENU_ID_IMPS_CONT_MY_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_WATCHER_LIST, 0));

    	ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_ADD, MENU_ID_IMPS_CONT_MY_OPT,
    						3,
    						MENU_ID_IMPS_CONT_ADD_DIRECT,
    						MENU_ID_IMPS_SEARCH_DIRECT,
    						MENU_ID_IMPS_SEARCH_PHB,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_ID_IMPS_ADD_CONTACT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_CHAT_ROOMS, MENU_ID_IMPS_CONT_MY_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_CHAT_ROOMS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_MANAGE_GROUP, MENU_ID_IMPS_CONT_MY_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_MANAGE_GROUPS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_SUBS_UNSUBS_NOTIFY, MENU_ID_IMPS_CONT_MY_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SUBSCRIBE_NOTIFY, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_SORT, MENU_ID_IMPS_CONT_MY_OPT,
    						3, 
                            MENU_ID_IMPS_SORT_BY_NAME,
                            MENU_ID_IMPS_SORT_BY_STATUS,
                            MENU_ID_IMPS_SORT_BY_GROUP,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SORT_LIST, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_LOGOUT, MENU_ID_IMPS_CONT_MY_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LOGOUT, 0));

    /* option for friends */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_USER_OPT, 0,
#ifdef IMPS_FOR_OMA_ONLY
    						12, 
#else
                            10,
#endif
    						MENU_ID_IMPS_CONT_SEND_MSG,
    						MENU_ID_IMPS_CONT_ABOUT_FRIEND,
    						MENU_ID_IMPS_CONT_DEL,
    						MENU_ID_IMPS_CONT_BLOCK_GRANT,
    						MENU_ID_IMPS_CONT_ADD,
    						MENU_ID_IMPS_CONT_CHAT_ROOMS,
    						MENU_ID_IMPS_CONT_MANAGE_GROUP,
    						MENU_ID_IMPS_CONT_SUBS_UNSUBS_NOTIFY,
    						MENU_ID_IMPS_CONT_SORT,
#ifdef IMPS_FOR_OMA_ONLY
    						MENU_ID_IMPS_CONT_SUBSCRIBE,
    						MENU_ID_IMPS_CONT_UNSUBSCRIBE,
#endif
    						MENU_ID_IMPS_CONT_LOGOUT,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_SEND_MSG, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SEND_READ_MSG, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_ABOUT_FRIEND, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_VIEW_CONT_DETAIL, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_DEL, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_DEL_CONTACT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_BLOCK_GRANT, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_BLOCK_CONTACT, 0));

    	ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_ADD, MENU_ID_IMPS_CONT_USER_OPT,
    						3,
    						MENU_ID_IMPS_CONT_ADD_DIRECT,
    						MENU_ID_IMPS_SEARCH_DIRECT,
    						MENU_ID_IMPS_SEARCH_PHB,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_ID_IMPS_ADD_CONTACT, 0));

    	ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_ADD_DIRECT, MENU_ID_IMPS_CONT_USER_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ADD_DIRECTLY, 0));

    	ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_SEARCH_DIRECT, MENU_ID_IMPS_CONT_ADD,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_SEARCH, 0));      

    	ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_SEARCH_PHB, MENU_ID_IMPS_CONT_ADD,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LOAD_FROM_PHB, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_CHAT_ROOMS, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_CHAT_ROOMS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_MANAGE_GROUP, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_MANAGE_GROUPS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_SUBS_UNSUBS_NOTIFY, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SUBSCRIBE_NOTIFY, 0));    

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_SORT, MENU_ID_IMPS_CONT_USER_OPT,
    						3, 
    						MENU_ID_IMPS_SORT_BY_NAME,
    						MENU_ID_IMPS_SORT_BY_STATUS,
    						MENU_ID_IMPS_SORT_BY_GROUP,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SORT_LIST, 0));
#ifdef IMPS_FOR_OMA_ONLY
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_SUBSCRIBE, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SUBSCRIBE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_UNSUBSCRIBE, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_UNSUBSCRIBE, 0));

#endif

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_LOGOUT, MENU_ID_IMPS_CONT_USER_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LOGOUT, 0));

    /* options for name input screen when adding new contact */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_ADD_NAME_OPT, 0,
    						2,
    						MENU_ID_IMPS_CONT_ADD_NAME_OPT_DONE,
    						MENU_ID_IMPS_CONT_ADD_NAME_OPT_INPUT_METH,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    	ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_ADD_NAME_OPT_DONE, MENU_ID_IMPS_CONT_ADD_NAME_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_DONE, 0));

    	ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_ADD_NAME_OPT_INPUT_METH, MENU_ID_IMPS_CONT_ADD_NAME_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_INPUT_METHOD, 0));

    /* option for chat rooms */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_CHAT_OPT, 0,
    						0,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    /* About me */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_PRESENCE, MENU_ID_IMPS_CONT_ABOUT_ME,
    						0,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_ID_IMPS_PRESENCE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_PUBLIC_PROFILE_1, MENU_ID_IMPS_CONT_ABOUT_ME,
    						0,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_ID_IMPS_PUBLIC_PROFILE_1, 0)); 

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CONT_PUBLIC_PROFILE_2, MENU_ID_IMPS_CONT_ABOUT_ME,
    						0,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_ID_IMPS_PUBLIC_PROFILE_2, 0));     


    /* about me option */
    	ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PRESENCE_FILE_OPT, 0,
    						3,
    						MENU_ID_IMPS_PRESENCE_FILE_OPT_SEL,
    						MENU_ID_IMPS_PRESENCE_FILE_OPT_VIEW,
    						MENU_ID_IMPS_PRESENCE_FILE_OPT_DEL,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_ID_IMPS_SEL_FILE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PRESENCE_FILE_OPT_VIEW, MENU_ID_IMPS_PRESENCE_FILE_OPT,
    						0,  // No child
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_VIEW, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PRESENCE_FILE_OPT_SEL, MENU_ID_IMPS_PRESENCE_FILE_OPT,
    						0,  // No child
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SEL_FILE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_PRESENCE_FILE_OPT_DEL, MENU_ID_IMPS_PRESENCE_FILE_OPT,
    						0,  // No child
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_DELETE, 0));

    /* search contact */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_SEARCH_OPT, 0,
    						2,
    						MENU_ID_IMPS_SEARCH_OPT_SEARCH,
    						MENU_ID_IMPS_SEARCH_OPT_QUIT,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_SEARCH_OPT_SEARCH, MENU_ID_IMPS_SEARCH_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_SEARCH, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_SEARCH_OPT_QUIT, MENU_ID_IMPS_SEARCH_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_QUIT, 0));

    /* sort */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_SORT_BY_NAME, MENU_ID_IMPS_CONT_SORT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SORT_BY_NAME, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_SORT_BY_STATUS, MENU_ID_IMPS_CONT_SORT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SORT_BY_STATUS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_SORT_BY_GROUP, MENU_ID_IMPS_CONT_SORT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SORT_BY_GROUP, 0));

    /* options of chatting for ordinary user*/
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT, 0,
    						6, 
    						MENU_ID_IMPS_CHAT_OPT_WRITE,
    						MENU_ID_IMPS_CHAT_OPT_SEND_FILE,
    						MENU_ID_IMPS_CHAT_OPT_INVITE,
    						MENU_ID_IMPS_CHAT_LIST_JOINED,
    						MENU_ID_IMPS_CHAT_OPT_SAVE_TEXT,
    						MENU_ID_IMPS_CHAT_OPT_CLOSE,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_WRITE, MENU_ID_IMPS_CHAT_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_WRITE_MSG, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SEND_FILE, MENU_ID_IMPS_CHAT_OPT,
    						0, 						
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SEND_FILE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_INVITE, MENU_ID_IMPS_CHAT_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_INVITE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_LIST_MEMBER, MENU_ID_IMPS_CHAT_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LIST_MEMBER, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SAVE_TEXT, MENU_ID_IMPS_CHAT_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SAVE_TEXT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_CLOSE, MENU_ID_IMPS_CHAT_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_CLOSE, 0));	

    /* options of chatting for administrator and moderator */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT1, 0,
    						9, 
    						MENU_ID_IMPS_CHAT_OPT_WRITE,
    						MENU_ID_IMPS_CHAT_OPT_SEND_FILE,
    						MENU_ID_IMPS_CHAT_OPT_INVITE,
    						MENU_ID_IMPS_CHAT_ADD_MEMBER,
    						MENU_ID_IMPS_CHAT_OPT_LIST_MEMBER,
    						MENU_ID_IMPS_CHAT_LIST_REJECTED,
    						MENU_ID_IMPS_CHAT_LIST_JOINED,
    						MENU_ID_IMPS_CHAT_OPT_SAVE_TEXT,
    						MENU_ID_IMPS_CHAT_OPT_CLOSE,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_WRITE, MENU_ID_IMPS_CHAT_OPT1,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_WRITE_MSG, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SEND_FILE, MENU_ID_IMPS_CHAT_OPT1,
    						0, 						
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SEND_FILE, 0));    

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_INVITE, MENU_ID_IMPS_CHAT_OPT1,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_INVITE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_ADD_MEMBER, MENU_ID_IMPS_CHAT_OPT1,
    						2, 
    						MENU_ID_IMPS_CHAT_ADD_MEMBER_DIRECTLY,
    						MENU_ID_IMPS_CHAT_ADD_MEMBER_FROM_ONLINE,							
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ADD_MEMBER, 0));    

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_LIST_MEMBER, MENU_ID_IMPS_CHAT_OPT1,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LIST_MEMBER, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_LIST_REJECTED, MENU_ID_IMPS_CHAT_OPT1,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LIST_REJECTED, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_LIST_JOINED, MENU_ID_IMPS_CHAT_OPT1,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LIST_JOINED, 0));    

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SAVE_TEXT, MENU_ID_IMPS_CHAT_OPT1,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SAVE_TEXT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_CLOSE, MENU_ID_IMPS_CHAT_OPT1,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_CLOSE, 0));	

    /* options of chatting for single room */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT2, 0,
    						4, 
    						MENU_ID_IMPS_CHAT_OPT_WRITE,
    						MENU_ID_IMPS_CHAT_OPT_SEND_FILE,
    						MENU_ID_IMPS_CHAT_OPT_SAVE_TEXT,
    						MENU_ID_IMPS_CHAT_OPT_CLOSE,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_WRITE, MENU_ID_IMPS_CHAT_OPT2,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_WRITE_MSG, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SEND_FILE, MENU_ID_IMPS_CHAT_OPT2,
    						0, 						
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SEND_FILE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SAVE_TEXT, MENU_ID_IMPS_CHAT_OPT2,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SAVE_TEXT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_CLOSE, MENU_ID_IMPS_CHAT_OPT2,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_CLOSE, 0));	    

    /* options of add member */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_ADD_MEMBER_DIRECTLY, MENU_ID_IMPS_CHAT_ADD_MEMBER,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ADD_DIRECTLY, 0));  

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_ADD_MEMBER_FROM_ONLINE, MENU_ID_IMPS_CHAT_ADD_MEMBER,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ADD_FROM_ONLINE, 0)); 

    /* options of list member */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT, 0,
    						2,
    						MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT_DEL,
    						MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT_SET_MOD_USER,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT_DEL, MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_DELETE_MEMBER, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT_SET_MOD_USER, MENU_ID_IMPS_CHAT_LIST_MEMBER_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SET_MODERATOR, 0));

    /* options of joined user */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_LIST_JOINED_OPT, 0,
    						2,
    						MENU_ID_IMPS_CHAT_LIST_JOINED_OPT_ADD_MEM,
    						MENU_ID_IMPS_CHAT_LIST_JOINED_OPT_ADD_REJ,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_LIST_JOINED_OPT_ADD_MEM, MENU_ID_IMPS_CHAT_LIST_JOINED_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ADD_TO_MEM, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_LIST_JOINED_OPT_ADD_REJ, MENU_ID_IMPS_CHAT_LIST_JOINED_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ADD_TO_REJ, 0));

    /* options of popup input editor */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_INPUT_OPT, 0,
    						5, 
    					    MENU_ID_IMPS_CHAT_OPT_SEND,
    						MENU_ID_IMPS_CHAT_OPT_INSERT_SYMBOL,
    						MENU_ID_IMPS_CHAT_OPT_TEXT_FORMAT,
    						MENU_ID_IMPS_CHAT_OPT_SEND_FILE,
    						MENU_ID_IMPS_CHAT_OPT_INPUT_METH,	
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SEND, MENU_ID_IMPS_CHAT_INPUT_OPT,
    						0, 
    					   SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_SEND, 0));	


    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_INSERT_SYMBOL, MENU_ID_IMPS_CHAT_INPUT_OPT,
    						0, 
    					   SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_INSERT_SYMBOL, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_TEXT_FORMAT, MENU_ID_IMPS_CHAT_INPUT_OPT,
    						0, 						
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_TEXT_FORMAT, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SEND_FILE, MENU_ID_IMPS_CHAT_INPUT_OPT,
    						0, 						
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_SEND_FILE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_INPUT_METH, MENU_ID_IMPS_CHAT_INPUT_OPT,
    						0, 
    					   SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_INPUT_METHOD, 0));	


    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SEND_OPT, 0,
    						3, 
    						MENU_ID_IMPS_CHAT_OPT_SEND_DONE,
    						MENU_ID_IMPS_CHAT_OPT_INSERT_SYMBOL,
    						MENU_ID_IMPS_CHAT_OPT_SEND_INPUT_METH,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SEND_DONE, MENU_ID_IMPS_CHAT_OPT_SEND_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_DONE, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_INSERT_SYMBOL, MENU_ID_IMPS_CHAT_OPT_SEND_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_INSERT_SYMBOL, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_OPT_SEND_INPUT_METH, MENU_ID_IMPS_CHAT_OPT_SEND_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_INPUT_METHOD, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_SAVE_OPT, 0,
    						2, 
    						MENU_ID_IMPS_CHAT_SAVE_OPT_DONE,
    						MENU_ID_IMPS_CHAT_SAVE_OPT_INPUT_METH,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_SAVE_OPT_DONE, MENU_ID_IMPS_CHAT_SAVE_OPT,
    						0,
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_CHAT_SAVE_OPT_INPUT_METH, MENU_ID_IMPS_CHAT_SAVE_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_INPUT_METHOD, 0));

    /* options for chat room */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT, 0,
    						5, 
    						MENU_ID_IMPS_ROOM_OPT_JUMP_TO,
    						MENU_ID_IMPS_ROOM_OPT_CREATE,
    						MENU_ID_IMPS_ROOM_OPT_JOIN,
    						MENU_ID_IMPS_ROOM_OPT_SEARCH,
    						MENU_ID_IMPS_ROOM_OPT_CLOSE,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT_JUMP_TO, MENU_ID_IMPS_ROOM_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_JUMP_TO, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT_CREATE, MENU_ID_IMPS_ROOM_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_OPEN_CHAT_ROOM, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT_JOIN, MENU_ID_IMPS_ROOM_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ROOM_JOIN, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT_SEARCH, MENU_ID_IMPS_ROOM_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_SEARCH, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT_CLOSE, MENU_ID_IMPS_ROOM_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_CLOSE, 0));	

    /* empty chat room options */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT2, 0,
    						3, 
    						MENU_ID_IMPS_ROOM_OPT_CREATE,
    						MENU_ID_IMPS_ROOM_OPT_JOIN,
    						MENU_ID_IMPS_ROOM_OPT_SEARCH,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT_CREATE, MENU_ID_IMPS_ROOM_OPT2,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_OPEN_CHAT_ROOM, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT_SEARCH, MENU_ID_IMPS_ROOM_OPT2,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_SEARCH, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_OPT_JOIN, MENU_ID_IMPS_ROOM_OPT2,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_ROOM_JOIN, 0));	

      /* invivation note option */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_INVITE_OPT, 0,
                                    2,
                                    MENU_ID_IMPS_ROOM_INVITE_OPT_DONE,
                                    MENU_ID_IMPS_ROOM_INVITE_OPT_INPUT_METH,                        
                                    SHOW, NONMOVEABLE, DISP_LIST,
                                    STR_GLOBAL_OPTIONS, 0));
      
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_INVITE_OPT_DONE, MENU_ID_IMPS_ROOM_INVITE_OPT,
                                    0,
                                    SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                                    STR_GLOBAL_DONE, 0));

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ROOM_INVITE_OPT_INPUT_METH, MENU_ID_IMPS_ROOM_INVITE_OPT,
                                    0,
                                    SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
                                    STR_GLOBAL_INPUT_METHOD, 0));

    /* group options */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_GROUP_OPT, 0,
#ifdef IMPS_FOR_OMA_ONLY
    						5, 
#else
                     4,
#endif
    						MENU_ID_IMPS_GROUP_OPT_CREATE,
    						MENU_ID_IMPS_GROUP_OPT_LIST_MEMBER,
    						MENU_ID_IMPS_GROUP_OPT_EDIT,
    						MENU_ID_IMPS_GROUP_OPT_DELETE,
#ifdef IMPS_FOR_OMA_ONLY							
    						MENU_ID_IMPS_GROUP_OPT_BROADCAST,
#endif
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_GROUP_OPT_CREATE, MENU_ID_IMPS_GROUP_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_ADD, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_GROUP_OPT_LIST_MEMBER, MENU_ID_IMPS_GROUP_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_LIST_MEMBER, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_GROUP_OPT_EDIT, MENU_ID_IMPS_GROUP_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_EDIT, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_GROUP_OPT_DELETE, MENU_ID_IMPS_GROUP_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_GLOBAL_DELETE, 0));	

#ifdef IMPS_FOR_OMA_ONLY
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_GROUP_OPT_BROADCAST, MENU_ID_IMPS_GROUP_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_BROADCAST, 0));	
#endif

    /* options for about friend */
    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ABOUT_FRIEND_OPT, 0,
    						2, 
    						MENU_ID_IMPS_ABOUT_FRIEND_EDIT,
    						MENU_ID_IMPS_ABOUT_FRIEND_REFRESH,
    						SHOW, NONMOVEABLE, DISP_LIST,
    						STR_GLOBAL_OPTIONS, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ABOUT_FRIEND_EDIT, MENU_ID_IMPS_ABOUT_FRIEND_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_CHANGE_NICK_NAME, 0));	

    ADD_APPLICATION_MENUITEM ((MENU_ID_IMPS_ABOUT_FRIEND_REFRESH, MENU_ID_IMPS_ABOUT_FRIEND_OPT,
    						0, 
    						SHOW, MOVEABLEWITHINPARENT, DISP_LIST,
    						STR_ID_IMPS_REFRESH, 0));	
    }
#endif
#endif  //#ifndef _MMI_RES_EMAIL_C
#endif  //#ifndef _MMI_RES_IMPS_C
