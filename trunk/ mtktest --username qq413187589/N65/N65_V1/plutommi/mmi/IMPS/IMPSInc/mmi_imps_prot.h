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
 * mmi_imps_prot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines local contant, structure, enum, and function prototypes forIMPS application.
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
#ifndef _MMI_IMPS_PROT_H
#define _MMI_IMPS_PROT_H
#ifdef __MMI_IMPS__

#include "MMIDataType.h"
#include "mmi2imps_struct.h"
#include "DataAccountGProt.h"
#include "FileMgr.h"
#include "PhoneBookTypes.h"
#include "wap_ps_struct.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* #define IMPS_TEST_CODE */
// #define IMPS_PROF_TEST_CODE

/*****************************************************************************              
* Extern Global Variable                                                                    
**************************************************************************** */

/*****************************************************************************              
* Extern Global Function                                                                    
**************************************************************************** */
/* general */
#define IMPS_MAX_SEQ_NUM   65535        /* maximum sqeunce number of session id */
#define IMPS_MAX_SEARCH_RESULT 30       /* maximum number of search result */
#define IMPS_MSG_TONE   0       /* id of message tone */
#define IMPS_ERR_TONE   1       /* id of error tone */

/* inline editors */
#define IMPS_INLINE_PROF_SETTING 10
#define IMPS_INLINE_PROF_CONN 18
#define IMPS_INLINE_SEARCH_CONT 30
#define IMPS_INLINE_JOIN_ROOM 6
#define IMPS_INLINE_SEARCH_ROOM 12
#define IMPS_INLINE_EDIT_ROOM 12
#define IMPS_INLINE_GROUP_EDIT 12
#define IMPS_INLINE_PRESENCE 10
#define IMPS_INLINE_PUBLIC_PROFILE_1 10
#define IMPS_INLINE_PUBLIC_PROFILE_2 6
#define IMPS_INLINE_ADD_DIRECT 4
#define IMPS_INLINE_ROOM_JOIN_DIRECT 6
#define IMPS_INLINE_TEXT_FORMAT 10

/* profiles */
#define IMPS_PROF_NAME_LEN 17   /* 16 word count + 1 word NULL terminate */
#define IMPS_PROF_COUNT 3       /* number of supported profiles */
#define IMPS_PROF_PORT_LEN 6    /* number of digits for port + NULL terminate */

/* login/logout */
#define IMPS_LOGIN_RAC_READY         0x01       /* GPRS ready to activate */
#define IMPS_LOGIN_PS_READY          0x02       /* IMPS task ready to serve MMI */
#define IMPS_LOGIN_IDLE_REACHED      0x04       /* MMI reaches IDLE screen */
#define IMPS_LOGIN_READY              0x07      /* IMPS application ready to login, the previous two items shall ready together. */
#define IMPS_LOGIN_ALREADY            0x08      /* already login */

/* contact list */
#define IMPS_MAX_NO_GROUP 5
#define IMPS_MAX_NO_CONT   (IMPS_MAX_NO_GROUP*IMPS_MAX_ENTITY_NUMBER + 1)       /* one for contact list */
#define IMPS_CONT_PA_READY 0x01
#define IMPS_CONT_BLOCK     0x02
#define IMPS_CONT_NEW_MSG  0x04

#define IMPS_PA_USER_UNKNOWN 0xFF       /* refreshed state */

#define IMPS_PA_ATTR_VALUE IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_STATUS_MOOD|IMPS_PA_ALIAS|IMPS_PA_STATUS_CONTENT
#define IMPS_PA_ATTR_VALUE_NO_PIC IMPS_PA_ONLINE_STATUS|IMPS_PA_USER_AVAILABILITY|IMPS_PA_STATUS_TEXT|IMPS_PA_STATUS_MOOD|IMPS_PA_ALIAS
#define IMPS_NUM_MOOD 11        /* number of supported mood */
#define IMPS_ADD_CONT_DIRECT    0       /* cause of add contact list -- add direcrtly */
#define IMPS_ADD_CONT_SEARCH    1       /* cause of add contact list -- add from search result */
#define IMPS_STATUS_OPEN 0      /* opened state of property */
#define IMPS_STATUS_HIDE 1      /* hidden state of property */
#define IMPS_BLOCK 0    /* blocked state */
#define IMPS_GRANT 1    /* unblocked state */

/* chat/chat room */
#define IMPS_MAX_NO_ROOM 5      /* chat room shall not exceed the maximum number of tab count */
#define IMPS_MAX_CHAT_INPUT_LEN (FMGR_MAX_PATH_LEN + 1) /* maximum length of input buffer */
#define IMPS_MAX_CHAT_BUFF 600  /* maximum length of display buffer */

#define IMPS_MAX_CHAT_MSG_COUNT 5       /* maximum number of session hold in MMI task */

#define IMPS_ROOM_MEMBER_LEFT    0      /* cause of group changed -- member left */
#define IMPS_ROOM_MEMBER_JOINED  1      /* cause of group changed -- member joined */

#define IMPS_JOIN_FROM_SEARCH 0 /* cause of join -- from search result */
#define IMPS_JOIN_DIRECT        1       /* cause of join -- join directly */
#define IMPS_JOIN_FROM_INVITE  2        /* cause of join -- join from invitation */

/* About Me related */
#define IMPS_ABOUT_PIC_PREFIX L"about." /* file name of picture */
#define IMPS_MAX_PIC_PATH_LEN 60        /* maximum buffer length to store my picture */
#define IMPS_MAX_PIC_SIZE (20*1024)     /* maximum length of my picture */

/* invitation related */
#define IMPS_MAX_INVITATION_NOTE 1024   /* size of invitation note buffer */
#define IMPS_MAX_INVITEE_SESSION 5      /* maximum number of invitation that can be sent at the same time */
#define IMPS_MAX_PEND_INVITATION 5      /* maximum number of pending invitation */

#define IMPS_MAX_PROXY_ID_LEN  (41)   /* length of proxy id */  
#define IMPS_DATA_ACCOUNT_TYPE (DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI)

/* filename for rejected user list */
#define IMPS_REJECTED_USER L"rejected"

#define IMPS_PUBLIC_PROFILE L"pp.dat"
#define IMPS_PA_AUTH L"pa_auth.dat"

#define IMPS_SYS_FILE_DIRECTORY "Z:\\@imps\\"

/* #define IMPS_DEFAULT_FILE_PATH FMGR_DEFAULT_FOLDER_RECEIVED */ /* L"Received\\" */
#define IMPS_PUBLIC_PROFILE_DISP_BUFF 700

#if ((WPS_MAX_AUTH_PASSWORD_LENGTH) > (IMPS_MAX_PASSWORD_LEN))
#define IMPS_MAX_HTTP_AUTH_PASSWORD_LEN IMPS_MAX_PASSWORD_LEN
#else
#define IMPS_MAX_HTTP_AUTH_PASSWORD_LEN WPS_MAX_AUTH_PASSWORD_LENGTH
#endif

#define IMPS_MAX_PROXY_PASSWORD_LEN 31
#define IMPS_MAX_PROXY_USERNAME_LEN 31

/*****************************************************************************
* Typedef 
*****************************************************************************/
/* cause of reading NVRAM */
typedef enum
{
    IMPS_NVRAM_INIT = 0,    /* initialization during power on */
    IMPS_NVRAM_PROF_LIST,   /* retrieving profile list */
    IMPS_NVRAM_PROF_EDIT    /* edit a specific profile */
} mmi_imps_nvram_cause;

/* type of chat room */
typedef enum
{
    IMPS_ROOM_TYPE_SINGLE = 0,      /* single talk */
    IMPS_ROOM_TYPE_GROUP_CREATE,    /* a created group */
    IMPS_ROOM_TYPE_GROUP_JOIN       /* a joined group */
} mmi_imps_room_type_enum;

/* source of search */
typedef enum
{
    IMPS_SEARCH_CONT = IMPS_SEARCH_USER,
    IMPS_SEARCH_ROOM = IMPS_SEARCH_GROUP,
    IMPS_SEARCH_WATCHER
} mmi_imps_search_cause_enum;

/* type of sorting type */
typedef enum
{
    IMPS_SORT_BY_NAME = 0,
    IMPS_SORT_BY_STATUS,
    IMPS_SORT_BY_GROUP
} mmi_imps_sort_type_enum;

/* Indicate current cause for displaying online contact: invite or add member */
typedef enum
{
    IMPS_INVITE_ONLINE = 0,
    IMPS_ADD_MEMBER_ONLINE
} mmi_imps_invite_state_enum;

/* add contact or add member */
typedef enum
{
    IMPS_ADD_CONTACT = 0,
    IMPS_ADD_MEMBER
} mmi_imps_add_type_enum;

/* OTA node symbols */
typedef enum 
{
    MMI_IMPS_NS_OMA_PROXY,       /* L1 node */
    MMI_IMPS_NS_OMA_APP,         /* L1 node */
    MMI_IMPS_NS_OMA_PXAUTHINFO,  /* child node of MMI_IMPS_NS_OMA_PROXY */
    MMI_IMPS_NS_OMA_PORT,        /* child node of MMI_IMPS_NS_OMA_PROXY */
    MMI_IMPS_NS_OMA_APPAUTH,     /* child node of MMI_IMPS_NS_OMA_APP */
    MMI_IMPS_NS_OMA_APPADDR,     /* child node of MMI_IMPS_NS_OMA_APP */
    MMI_IMPS_NS_OMA_TOTAL
} mmi_imps_ns_oma_enum;


/* general info of whole IMPS application */
typedef struct
{
    S32 seq_no;         /* global sequence number for chat and invite session */
    U16 curr_action;    /* message id of currently request sent */
    U8 gen_state;       /* general state of IMPS */
    U8 is_login;                                        /* if it's currently login */
    U8 curr_group;                                      /* current index of group (for background update) */
    U8 curr_tab;                                        /* index of current highlighting tab */
    U8 no_tab;                                          /* total number of tab */
    U8 curr_subs;                                       /* current subscribed contact */
    BOOL auto_update_done;                              /* if update finished */
    BOOL is_reentry;                                    /* re_entry IMPS application when progressing */
    BOOL is_sub_notify;    /* Flag to indicate current state of subscribe notify, True-subscribed, False-unsubscribed */
    BOOL not_agreed_all;   /* not agreed all content type, it means there is a list indicate the accepted content types by server */
    U8 imps_version;       /* Version used through  this session */
    U8 ps_ready_state;     /* state to indicate if the PS is currently ready -- 
                           an auxiliary flag to indicate if the auto-login process can start. */
    imps_not_agreed_services_struct not_agreed_serv;    /* not agreed service by server */
} mmi_imps_general_info_struct;

/* structure of progressing screen */
typedef struct
{
    U8 *strBody1;
    U8 *strBody2;
    FuncPtr lskFuncPtr;
    FuncPtr rskFuncPtr;
    FuncPtr endFuncPtr;
    U16 strCaption;
    U16 imgCaption;
    U16 strLsk;
    U16 imgLsk;
    U16 strRsk;
    U16 imgRsk;
    U16 imgBody;
} mmi_imps_progress_scr_struct;

/* mapping between errro code and string index */
typedef struct
{
    S32 err_cause;
    U16 str_id;
} mmi_imps_err_mapping_struct;

/* profile */
typedef struct
{
    UI_character_type prof_name[IMPS_PROF_NAME_LEN];    /* name of profile */
    U16 proxy_port;                                     /* port number */
    U8 server[IMPS_MAX_SERVER_ADDRESS_LEN];             /* address of server */
    U8 username[IMPS_MAX_USERID_LEN];                     /* user name */
    U8 passwd[IMPS_MAX_PASSWORD_LEN];                   /* password */
    U8 proxy_ip[4];                                     /* address of proxy server */
    U8 proxy_username[IMPS_MAX_PROXY_USERNAME_LEN];               /* username */
    U8 proxy_passwd[IMPS_MAX_PROXY_PASSWORD_LEN];             /* password */
    U8 auth_usrn[IMPS_MAX_NAME_LEN];                    /* http auth username */
    U8 auth_pwd[IMPS_MAX_HTTP_AUTH_PASSWORD_LEN];                 /* http auth password */
    U8 conn_type;                                       /* WAP or HTTP */
    U8 dt_acct;                                         /* data account */
    U8 use_proxy;                                       /* use proxy or not */
    U8 auto_login;                                      /* auto login or not */
} mmi_imps_prof_struct;

/* about me NVRAM structure */
typedef struct
{
    UI_character_type pic_name[(FMGR_MAX_FILE_LEN + 1)];    /* file name of the picture */
    UI_character_type alias[IMPS_MAX_NAME_LEN];             /* alias */
    UI_character_type my_prof[IMPS_MAX_PA_STATUS_TEXT_LEN]; /* text of profile */
    U8 status;                                              /* status of user */
    U8 mood;                                                /* mood of user */
    U8 is_pic;
} mmi_imps_presence_nvram_struct;

/* inline editor structure for when editing about me */
typedef struct
{
    S32 status;                                             /* for inline editor */
    S32 mood;                                               /* for inline editor */
    S32 is_pic;                                             /* for inline editor */
    U8 *status_list[3];                                     /* for inline editor */
    U8 *mood_list[IMPS_NUM_MOOD];                           /* for inline editor */
    U8 *file_sel_list[2];                                   /* for inline editor */
    UI_character_type my_prof[IMPS_MAX_PA_STATUS_TEXT_LEN]; /* profile text buff */
    UI_character_type alias[IMPS_MAX_NAME_LEN];             /* alias */
    UI_character_type my_pic[IMPS_MAX_PIC_PATH_LEN];        /* original picture */
    UI_character_type file_buff[FMGR_MAX_PATH_LEN];         /* path from FMGR */
    UI_character_type pic_name[(FMGR_MAX_FILE_LEN + 1)];    /* new selected picture */
    U8 is_pic_changed;
} mmi_imps_presence_struct;

/* Structure of public profile */
typedef struct
{    
    S32 country_code;                                       /* Country, current not present*/
    S32 gender;                                             /* Gender */ 
    S32 marital_status;                                     /* Marital status */
    UI_character_type   city[IMPS_MAX_CITY_NAME_LEN];       /* City */
    UI_character_type   free_text[IMPS_MAX_FREE_TEXT_LEN];  /* Free text */
    UI_character_type   intention[IMPS_MAX_INTENTION_LEN];  /* Intention */
    UI_character_type   hobbies[IMPS_MAX_HOBBY_LEN];        /* Hobbies */
    UI_character_type   fname[IMPS_MAX_FRIENDLY_NAME_LEN];  /* Friendly name */      
    U8 year_buff[10];       /* year buffer */
    U8 month_buff[6];      /* month buffer */
    U8 day_buff[6];        /* day buffer */
} mmi_imps_public_profile_struct;

/* Structure used when editing public profile info in inline editor screen */
typedef struct
{
    mmi_imps_public_profile_struct public_profile;
    U8* gender_list[4];              /* List of gender for inline select component */
    U8* marital_status_list[8];      /* List of marital status for inline select component */
    /* U8* country_list[STR_ID_IMPS_CC_END - STR_ID_IMPS_CC_BEGIN]; */  /* List of country for inline select component */
} mmi_imps_public_profile_inline_struct;


/* nvram struct */
typedef struct
{
    mmi_imps_presence_nvram_struct about_me;    /* about me */
    mmi_imps_prof_struct prof[IMPS_PROF_COUNT]; /* list of profile */
    U8 act_prof_indx;                           /* index of active profile */
    U8 sort_type;                               /* type of sorting */
} mmi_imps_nvram_struct;

/* Structure used when to store temporary data when editing a Profile. */
typedef struct
{
    S32 conn_type;                                          /* connection type */
    S32 use_proxy;                                          /* user proxy or not */
    S32 auto_login;                                         /* auto-login or not */
    UI_character_type proxy_ip[4][4];                       /* 255.255.255.255 */
    UI_character_type prof_name[IMPS_PROF_NAME_LEN];        /* profile name */
    UI_character_type server[IMPS_MAX_SERVER_ADDRESS_LEN];  /* server address */
    UI_character_type username[IMPS_MAX_USERID_LEN];          /* username */
    UI_character_type passwd[IMPS_MAX_PASSWORD_LEN];        /* password */
    UI_character_type proxy_port[IMPS_PROF_PORT_LEN];       /* proxy port number */
    UI_character_type proxy_username[IMPS_MAX_PROXY_USERNAME_LEN];    /* username of proxy */
    UI_character_type proxy_passwd[IMPS_MAX_PROXY_PASSWORD_LEN];  /* password of proxy */
    UI_character_type auth_usrn[IMPS_MAX_NAME_LEN];         /* http auth username */
    UI_character_type auth_pwd[IMPS_MAX_HTTP_AUTH_PASSWORD_LEN];      /* http auth password */    
    U8 curr_dt_acct;                                        /* index of data account */
} mmi_imps_prof_edit_struct;

/* All misc application when modifying profile settings. */
typedef struct
{
    mmi_imps_prof_edit_struct edit_prof;    /* current editing profile */
    U8 *yes_no_list[2];                     /* Inline selection list for "Yes" and "No" */
    U8 *wap_http_list[2];                   /* Inline selection list for "HTTP" and "WAP" */
    UI_character_type prof_name_list[IMPS_PROF_COUNT][IMPS_PROF_NAME_LEN];      /* List of profile names */
    UI_character_type dt_acct_name[(MAX_DATA_ACCOUNT_NAME_LEN + 1)];    /* Name of current selected data account */
    U8 act_prof_indx;                       /* Index of current active profile */
    U8 hilte_prof;                          /* Index of current highlighted profile */
    U8 setting_type;                        /* Index of current editing setting */
} mmi_imps_prof_misc_struct;

/* structure used to store each OTA profile infomation */
typedef struct
{
    mmi_imps_prof_struct prof_info;      /* ota profile */
    U8  proxy_id[IMPS_MAX_PROXY_ID_LEN]; /* used to build dependence relation between proxy and application */
    U8  is_proxy;                        /* whether use proxy or not */
    U8  is_valid;                        /* whether this profile is valid */
    U8  is_used;                         /* whether this profile is used */
    U8  is_app_addr;                     /* whether exist valid app address */
    U8  is_app_auth;                     /* whether exist valid app authorization information */    
} mmi_imps_ota_prof_struct;

/* structure used to store all info of OTA */
typedef struct
{
    mmi_imps_ota_prof_struct *info[IMPS_PROF_COUNT * 2];                  /* ota profile */
    
    /* list profiles name when all profiles configured for user to select which one to replace */
    UI_character_type prof_name[IMPS_PROF_COUNT][IMPS_PROF_NAME_LEN]; 
    /* profile index to record app information because one app may include mulitple proxy */
    MMI_BOOL app_prof_index[IMPS_PROF_COUNT * 2]; 
    MMI_BOOL is_curr_store; /* whether current profile can be store*/
	U8 is_act;              /* whether have activated profile */
    U8 total;               /* total number of ota profiles this time */
    U8 curr_index;          /* current handling ota profile index */
    U8 install_no;          /* number of installed profiles */
    U8 skip_no;             /* number of skipped profiles */
    U8 invalid_no;          /* number of invalide profiles */
    U8 hilite_prof;         /* index of highlighting profile */
    U16 config_id;          /* id of configure application */
    S32 hConfig;            /* handler of ota */    
} mmi_imps_ota_info_struct;

/* common and basic element of a contact */
typedef struct
{
    UI_character_type sname[IMPS_MAX_NAME_LEN]; /* screen name, display name or nick name */
    U8 id[IMPS_MAX_ID_LEN];
} mmi_imps_entity_struct;


/* search criteria structure for inline editor screen */
typedef struct
{
    /* chat room part */
    UI_character_type room_id[IMPS_MAX_ID_LEN];
    UI_character_type room_name[IMPS_MAX_NAME_LEN];
    UI_character_type room_topic[IMPS_MAX_NAME_LEN];
    UI_character_type room_joined_user[IMPS_MAX_ID_LEN];
    UI_character_type room_owner[IMPS_MAX_ID_LEN];
    UI_character_type room_autojoin_user[IMPS_MAX_ID_LEN];    
} mmi_imps_search_room_struct;


/* search criteria structure for inline editor screen */
typedef struct
{
    /* user part */
    S32  gender;                /* Gender */
    S32  user_onlinestatus;     /*User online status */
    S32  marital_status;        /* Marital status */    
    UI_character_type   user_alias[IMPS_MAX_NAME_LEN];                     /* User alias */
    UI_character_type   user_emailaddr[IMPS_MAX_USER_EMAIL_ADDRESS_LEN];   /* User email address */
    UI_character_type   user_firstname[IMPS_MAX_SEARCH_KEYWORD_LEN];                 /* User first name */
    UI_character_type   user_id[IMPS_MAX_ID_LEN];                          /* User ID */
    UI_character_type   user_lastname[IMPS_MAX_SEARCH_KEYWORD_LEN];                  /* User last name */
    UI_character_type   user_mobile_number[IMPS_MAX_USER_MOBILE_PHONE_LEN];/* User mobile number */
    UI_character_type   user_max_age[3];                                /* Maximum of user's age. [v13] */
    UI_character_type   user_min_age[3];                                /* Minimum of user's age */
    UI_character_type   fname[IMPS_MAX_SEARCH_KEYWORD_LEN];           /* Friendly name */
    UI_character_type   city[IMPS_MAX_SEARCH_KEYWORD_LEN];                /* City */
    /* UI_character_type   free_text[IMPS_MAX_FREE_TEXT_LEN]; */           /* Free text */    
    UI_character_type   intention[IMPS_MAX_SEARCH_KEYWORD_LEN];           /* Intention */
    UI_character_type   hobbies[IMPS_MAX_SEARCH_KEYWORD_LEN];                 /* Hobbies */
    U8* marital_status_list[8];      /* List of marital status for inline select component */    
    U8* status_list[3];                                     /* for inline editor */
    U8* gender_list[4];              /* List of gender for inline select component */
} mmi_imps_search_cont_struct;


/* data strucure of a contact */
typedef struct
{
    UI_character_type nick_name[IMPS_MAX_NAME_LEN]; /* nikc name */
    UI_character_type alias[IMPS_MAX_NAME_LEN];     /* alias */
    UI_character_type prof_text[IMPS_MAX_PA_STATUS_TEXT_LEN];   /* text profile */
    U8 id[IMPS_MAX_ID_LEN];                         /* id */
    U8 group_id[IMPS_MAX_ID_LEN];                   /* group id the contact belongs to */
    U8 availability;                                /* availability */
    U8 mood;                                        /* mood */
    U8 comm_state;                                  /* common state */
} mmi_imps_cont_struct;

/* general information of all contacts */
typedef struct
{
    mmi_imps_cont_struct cont_list[IMPS_MAX_NO_CONT];   /* array of contacts */
    mmi_imps_sort_type_enum sort_type;                  /* current sorting criteria of contact list */
    U8 curr_cont;                                       /* index of current highlighted contact */
    U8 no_cont;                                         /* number of contact */
    U8 clear_gui_buff;                                  /* flag to indicate if the GUI buffer of contact list screen shall be cleared or not */
    U8 add_type;                                        /* auxiliary flag to indicate the method of adding a contact */
} mmi_imps_cont_info_struct;

/* structure of inline editor screen */
typedef struct
{
    S32 open_status;                                    /* open online stauts or not */
    S32 open_text;                                      /* open status text or not */
    S32 open_mood;                                      /* open mood or not */
    S32 open_pic;                                       /* open picture or not */
    S32 do_not_notify;                                  /* indicate whether the user 
                                                           added to this contact list 
                                                           should be notified of such event */
    U8 *open_hide_list[2];                              /* inline selectoin items for open/hide */
    U8 *yes_no_list[2];                                 /* Inline selection list for "Yes" and "No" */
    UI_character_type group_name[IMPS_MAX_NAME_LEN];    /* input buffer of group name */
} mmi_imps_group_inline_struct;

/* structure of a group */
typedef struct
{
    S32 no_users;                                       /* number of users in the group */
    UI_character_type group_name[IMPS_MAX_NAME_LEN];    /* group name */
    U8 group_id[IMPS_MAX_ID_LEN];                       /* group id */
    U8 open_status;                                     /* opened/hidden state of online status */
    U8 open_text;                                       /* opened/hidden state of text */
    U8 open_mood;                                       /* opened/hidden state of mood */
    U8 open_pic;                                        /* opened/hidden state of status content */
    U8 do_not_notify;                                   /* subscribe notify or not */
    U8 is_sync;                                         /* if data is sync with server or not */
} mmi_imps_group_struct;

/* overall information of groups */
typedef struct
{
    mmi_imps_group_inline_struct *inline_edit_group;        /* inline editor structure */
    mmi_imps_group_struct group_list[IMPS_MAX_NO_GROUP];    /* list of groups */
    U8 no_group;                                            /* number of groups */
    U8 curr_item;                                           /* current selected item */
    U8 is_created;      /*
                         * auxiliary variable to indicate 
                         * the group is editing or creating 
                         * when in inline editor screen 
                         */
} mmi_imps_group_info_struct;

/*
 * Structure for a chat session. When the user sends a message to remote contacts, 
 * we have to hold the previous sent message before the response comes back. 
 * If the message is failed to send, we will display a error indication for the user 
 * with the exact message he just tpyed. Success or not, after responses back, 
 * the session will be destroyed. 
 */
typedef struct
{
    S32 session_id;                                         /* session ID */
    UI_character_type input_buff[IMPS_MAX_CHAT_INPUT_LEN];  /* input buffer for the message */
    U8 room_id[IMPS_MAX_ID_LEN];                            /* id of the room */
} mmi_imps_chat_session_struct;

/* structure to store chatting information */
typedef struct
{
    mmi_imps_chat_session_struct chat_session[IMPS_MAX_CHAT_MSG_COUNT];
    UI_character_type input_buff[IMPS_MAX_CHAT_INPUT_LEN];  /* buffer of current input message */        
    U8 sel_style;  /* current selected text style */
    U8 sel_size;   /* current selected text size */
    U8 sel_color;  /* current selected text color */  
    U8 curr_room;   /* current seleting highlighting chat room room */
    U8 sel_sym;     /* current selected symbol */
} mmi_imps_chat_info_struct;

/* structure for a chat room */
typedef struct
{
    UI_character_type chat_buff[IMPS_MAX_CHAT_BUFF + 1];    /* buffer of chat history */
    UI_character_type room_name[IMPS_MAX_NAME_LEN];         /* name of the chat room */
    UI_character_type room_topic[IMPS_MAX_NAME_LEN];        /* topic of the chat room */
    UI_character_type welcome[IMPS_MAX_NOTE_LEN];           /* welcome text of the chat room */
    UI_character_type sname[IMPS_MAX_NAME_LEN];             /* screen name of the user in the chat room */
    U8 room_id[IMPS_MAX_ID_LEN];                            /* id of the chat room */
    mmi_imps_room_type_enum type;                           /* type of chat room (single talk or chat) */
    U8 access_type;                                         /* access type of the chat room */
    U8 is_used;                                             /* is chat room in used */
    U8 tab_index;                                           /* tab index that the chat room belongs to */
    BOOL clear_gui_buff;                                    /* if clear GUI buffer is needed */
    BOOL unread_msg;                                        /* if there is any unread message for in the chat room */
    BOOL edit_mode;                                         /* it's in EDIT mode or not */
    U8 pri_level;                                           /* privilege level of the user */
    U8 subs_notify;                                          /* subscribe notify or not */
} mmi_imps_room_struct;

/* structure of inline editor screen when join/create a chat room */
typedef struct
{
    S32 access_type;                                /* access type of the chat room */
    S32 subscribe_notify;                           /* subscribe notify or not */
    UI_character_type room_name[IMPS_MAX_NAME_LEN]; /* name of chat room */
    UI_character_type topic[IMPS_MAX_NAME_LEN];     /* topic of chat room */
    UI_character_type welcome[IMPS_MAX_NOTE_LEN];   /* welcome text of chat room */
    UI_character_type sname[IMPS_MAX_NAME_LEN];     /* user's screen name in the chat room */
    UI_character_type room_id[IMPS_MAX_ID_LEN];     /* id of the chat room */
    U8 *open_restrict_list[2];                      /* list of inline selection for access type (open or restrict) */
    U8 *yes_no_list[2];                             /* Inline selection list for "Yes" and "No" */
} mmi_imps_room_inline_struct;

/* inline editor structure of joining a chat room */
typedef struct
{
    S32 disclose_id;                            /* disclose use's id or not */
    S32 subscribe_notify;                       /* subscribe notify or not */
    U8 *yes_no_list[2];                         /* list of inline selection for Yes and No */
    UI_character_type room_id[IMPS_MAX_ID_LEN]; /* id of chat room to join */
    UI_character_type sname[IMPS_MAX_NAME_LEN]; /* screen name of the user in the chat room */
} mmi_imps_join_inline_struct;

/* inline editor structure of setting text format */
typedef struct
{
    S32 text_style_bold;        /* bold text or not */
    S32 text_style_italics;     /* italics text or not */    
    S32 text_style_underline;   /* underline text or not */    
    S32 text_size;       /* current selected text size */
    S32 text_color;      /* current selected text color */ 
    U8 *yes_no_list[2];  /* list of inline selection for Yes and No */
    U8 *size_list[IMPS_FONT_SIZE_MAX_NUM];      /* list of inline selection for Text size */
    U8 *color_list[IMPS_FONT_COLOR_MAX_NUM];    /* list of inline selection for Text color */
} mmi_imps_text_format_inline_struct;

/* overall information of chat rooms */
typedef struct
{
    mmi_imps_room_struct room_list[IMPS_MAX_NO_ROOM];   /* list of chat rooms */
    mmi_imps_room_inline_struct *inline_open_room;      /* inline editor for creating a chat room */
    mmi_imps_join_inline_struct *inline_join;           /* inline editor for joining a chat room */
    mmi_imps_text_format_inline_struct *inline_text_format;  /* inline editor for text format */
    imps_entity_list_struct *member;                     /* member of the chat room */
    imps_entity_list_struct *joined_user;                /* joined user of the chat room */    
    imps_entity_list_struct *rejected_user;              /* rejected user of the chat room */
    U8 no_rooms;                                         /* number of chat rooms */
    U8 curr_item;                                        /* current selected item in room list */
    U8 curr_sel_user;                                    /* Index of current selected user */    
    U8 join_cause;                                       /* cause of join */
    U8 invite_or_add;                                    /* current action for listing current online contact */
} mmi_imps_room_info_struct;

/* invite session */
typedef struct
{
    S32 session_id;                 /* session id */
    U8 cont_id[IMPS_MAX_ID_LEN];    /* contact id to invite */
    U8 room_id[IMPS_MAX_ID_LEN];    /* chat room to invite */
} mmi_imps_invite_session_struct;

/* structure of pending invitation */
typedef struct
{
    mmi_imps_invite_ind_struct *node;   /* local parameter of invite indication */
    MYTIME time_stamp;                  /* time when invite indication comes */
} mmi_imps_invite_list_struct;

/* overall information of invitation */
typedef struct
{
    S8 *invite_note;                        /* buffer for invitation string */
    mmi_imps_invite_list_struct invite_pending_list[IMPS_MAX_PEND_INVITATION];  /* pending invitation list to process */
    mmi_imps_invite_session_struct invite_session[IMPS_MAX_INVITEE_SESSION];    /* list of invite session that sends out */
    U8 invite_cand_list[IMPS_MAX_NO_CONT];  /* temporary list of contact that can be invite */
    U8 invite_count;                        /* number of invitation that sends out currently */
    U8 curr_sel_cont;                       /* index of current selected contact to invite */
    U8 curr_pend_invite;                    /* index of current pending invitation to process */
    U8 reminder_flag;                       /* shall remind user in IDLE screen or not */
} mmi_imps_invite_info_struct;

/* structure to store result of search */
typedef struct
{
    mmi_imps_entity_struct entity[IMPS_MAX_SEARCH_RESULT];  /* entity list of search result */
    mmi_imps_search_cause_enum search_cause;                /* cause of search */
    U8 count;                                               /* number of items in search result */
    U8 curr_item;                                           /* index of current selected item in search result screen */
} mmi_imps_search_result_struct;

/* data structure used in View Friend's Detail screen */
typedef struct
{
    U8 id[IMPS_MAX_ID_LEN];                                 /* id of the friend */
    U16 *profile_text;                                    /* pointer of profile text: profile text = profile text + public profile */
    UI_character_type file_name[IMPS_MAX_FILE_NAME_LEN];    /* image file name */
} mmi_imps_about_friend_struct;

/* data structure used in processing system message */
typedef struct
{
    imps_system_message_option_struct	option[IMPS_MAX_SM_OPTION_NUM];
    UI_character_type sm_path[IMPS_MAX_FILE_PATH_LEN];    /* system message file path */
    UI_character_type verification_key[IMPS_MAX_URL_LEN/2]; /* verification key */
    UI_character_type verification[IMPS_MAX_URL_LEN]; /* verification */
    U8 curr_sm_id[IMPS_MAX_SM_ID_LEN];                    /* current system message id */
    U8 curr_index;          /* current processing index */
    U8 total;               /* total */
    U8 sel_option;          /* user selected option */
    U8 option_count;        /* option count */
    U8 verification_type;   /* verification type */
    BOOL need_rsp;          /* need response or not */
    BOOL is_give_up;        /* give up or not */
    S8  *buff;              /* buffer for system message information */
} mmi_imps_system_message_struct;

/* data structure used in processing presence authentication indication */
typedef struct
{
    imps_entity_struct auth_user;         /* current processing user */
    U32 attr_list;                        /* attribute list */
    U8 curr_index;                        /* current user index */
    U8 total;                             /* total user count */
} mmi_imps_presence_auth_struct;

typedef struct
{
    UI_character_type username[IMPS_MAX_NAME_LEN];
    UI_character_type password[IMPS_MAX_HTTP_AUTH_PASSWORD_LEN];    
    U8 channel_id;
    U8 request_id;    
} mmi_imps_http_auth_struct;

typedef struct
{
    mmi_imps_general_info_struct gen_info;  /* general information of IMPS application */

    mmi_imps_prof_struct act_prof;  /* current active profile */

    mmi_imps_prof_misc_struct *prof_misc;   /* misc data for editing profile */

    mmi_imps_ota_info_struct *ota_prof;

    mmi_imps_cont_info_struct cont_info;    /* contact list informaion */

    mmi_imps_search_room_struct *search_room;    /* search criteria */

    mmi_imps_search_cont_struct *search_cont;    /* search criteria */    

    mmi_imps_search_result_struct search_result;    /* result of searching */

    mmi_imps_presence_struct *about_info;   /* inline buffer for editing presence info */

    mmi_imps_public_profile_inline_struct *pp_info;  /* inline buffer for editing public profile */

    mmi_imps_chat_info_struct chat_info;    /* chatting related information */

    mmi_imps_room_info_struct room_info;    /* chat room information */

    mmi_imps_invite_info_struct invite_info;    /* invitation related information */

    mmi_imps_group_info_struct group_info;  /* group releated information */

    mmi_imps_about_friend_struct friend_info;   /* information of a friend when view his detail */

    mmi_imps_progress_scr_struct progress_info; /* general progressing screen */

    mmi_imps_system_message_struct *system_message;  /* system message info */

    mmi_imps_presence_auth_struct *pa_auth;     /* presence authentication */

    mmi_imps_http_auth_struct *http_auth;

    UI_character_type path_buff[(FMGR_MAX_PATH_LEN + 1)];   /* common buffer to store file path */

    UI_character_type file_buff[FMGR_MAX_FILE_LEN]; /* common buffer to store file name */

    void *history_buffer;

    U8 add_cause;   /* add contact or member when reuse inline screen */
} mmi_imps_context_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern mmi_imps_context_struct *imps_p;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#define UI_IMPS_PROT
/* init function */
extern void mmi_imps_init_chat_hilite_hdlr(void);
extern void mmi_imps_init_common_hilite_hdlr(void);
extern void mmi_imps_init_contact_hilite_hdlr(void);
extern void mmi_imps_init_pa_hilite_hdlr(void);
extern void mmi_imps_init_prof_hilite_hdlr(void);

extern void mmi_imps_init_ps_pa_hdlr(void);
extern void mmi_imps_init_ps_gen_hdlr(void);

extern void mmi_imps_reset_cntx(void);
extern void mmi_imps_init_mood_icon_list(void);
extern void mmi_imps_init_invite_icon_list(void);

/* main menu */
extern void mmi_imps_pre_entry_main(void);
extern void mmi_imps_entry_main(void);
extern void mmi_imps_pre_entry_cont(void);
extern void mmi_imps_entry_cont(void);

/* common function */
#define COMM_UI_PROT
extern void mmi_imps_display_progressing(void);
extern void mmi_imps_entry_abort(void);
extern void mmi_imps_pre_entry_progressing(
                U16 strCaption,
                U16 imgCaption,
                U16 strLsk,
                U16 imgLsk,
                U16 strRsk,
                U16 imgRsk,
                U8 *strBody1,
                U8 *strBody2,
                U16 imgBody,
                FuncPtr lskFuncPtr,
                FuncPtr rskFuncPtr,
                FuncPtr endFuncPtr);
extern void mmi_imps_entry_progressing(void);
extern void mmi_imps_entry_confirm(U16 msg, FuncPtr lskFuncPtr, FuncPtr rskFuncPtr);
extern void mmi_imps_entry_comm_full_edit_opt(void);
extern void mmi_imps_hilite_comm_input_meth(void);

#define LOGIN_OUT_PROT
extern void mmi_imps_hilite_login(void);
extern void mmi_imps_login_progress(void);
extern void mmi_imps_auto_login(void);
extern void mmi_imps_entry_auto_login(void);
extern void mmi_imps_entry_auto_login_confirm(void);
extern void mmi_imps_auto_login_yes(void);
extern void mmi_imps_entry_login(void);
extern void mmi_imps_login_abort(void);
extern void mmi_imps_login_abort_finish(void);
extern void mmi_imps_re_entry_app(void);
extern void mmi_imps_hilite_logout(void);
extern void mmi_imps_entry_logout(void);
extern void mmi_imps_logout_complete(void);

#define PROF_IMPS_PROT
extern void mmi_imps_pre_entry_prof(void);
extern void mmi_imps_hilite_prof(void);
extern void mmi_imps_prof_read_nvram(mmi_imps_nvram_cause type);
extern void mmi_imps_entry_prof(void);
extern void mmi_imps_prof_save(void);
extern void mmi_imps_prof_save_no(void);
extern void mmi_imps_prof_save_yes(void);
extern U8 mmi_imps_prof_del_callback(void *param);
extern void mmi_imps_prof_free_mem_n_back(void);
extern void mmi_imps_prof_free_mem(void);
extern void mmi_imps_hilite_prof_list(S32 index);
extern void mmi_imps_entry_prof_opt(void);
extern void mmi_imps_entry_prof_activate(void);
extern void mmi_imps_hilite_prof_setting(void);
extern void mmi_imps_hilite_prof_conn(void);
extern void mmi_imps_pre_entry_prof_setting(void);
extern void mmi_imps_pre_entry_prof_conn(void);
extern void mmi_imps_pre_entry_prof_edit(void);
extern void mmi_imps_dt_acct_callback(void);
extern void mmi_imps_entry_prof_edit(void);
extern void mmi_imps_entry_prof_setting(void);
extern void mmi_imps_exit_prof_setting(void);
extern void mmi_imps_prof_setting_fill_inline_struct(void);
extern void mmi_imps_entry_prof_conn(void);
extern void mmi_imps_exit_prof_conn(void);
extern void mmi_imps_prof_conn_fill_inline_struct(void);
extern void mmi_imps_hilite_prof_full_edit(void);
extern void mmi_imps_prof_ip_addr_callback(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);
extern void mmi_imps_hilite_prof_activate(void);
extern void mmi_imps_hilite_prof_edit(void);
extern void mmi_imps_hilite_prof_done(void);
extern void mmi_imps_prof_list_data_acct(void);
extern void mmi_imps_email_custom_function(void);

#define CONT_PROT
extern void mmi_imps_entry_cont_opt(void);
extern void mmi_imps_hilite_contact(S32 index);
extern void mmi_imps_cont_redraw_list(void);
extern void mmi_imps_cont_update_when_msg_come(imps_entity_struct *entity);
extern void mmi_imps_cont_reset_msg_icon(void);

#define DEL_CONT_PROT
extern void mmi_imps_hilite_del_cont(void);
extern void mmi_imps_entry_del_cont_confirm(void);
extern void mmi_imps_del_cont(void);
extern void mmi_imps_del_cont_finished(S32 result);

#define ABOUT_PROT
extern void mmi_imps_hilite_about_me(void);
extern void mmi_imps_entry_about_me(void);
extern void mmi_imps_presence_fill_inline_struct(void);
extern void mmi_imps_public_profile_1_fill_inline_struct(void);
extern void mmi_imps_hilite_presence_inline_sel(S32 index);
extern void mmi_imps_entry_presence_sel_file(void);
extern void mmi_imps_hilite_presence_pic_sel(void);
extern void mmi_imps_hilite_presence_pic_view(void);
extern void mmi_imps_hilite_presence_pic_del(void);
extern void mmi_imps_entry_presence_pic_sel(void);
extern void mmi_imps_entry_presence_pic_view(void);
extern void mmi_imps_entry_presence_pic_del(void);
extern void mmi_imps_entry_presence_pic_del_yes(void);
extern void mmi_imps_presence_sel_pic_callback(void *filePath, S32 is_short);
extern void mmi_imps_presence_save_pic_callback(void *info);
extern void mmi_imps_presence_save(void);
extern void mmi_imps_presence_save_yes(void);
extern void mmi_imps_presence_save_no(void);
extern void mmi_imps_public_profile_save(void);
extern void mmi_imps_public_profile_save_yes(void);
extern void mmi_imps_public_profile_save_no(void);
extern void mmi_imps_presence_write_to_nvram(void);
extern void mmi_imps_presence_save_done(S32 result);
extern U8 mmi_imps_presence_del_callback(void *param);
extern void mmi_imps_free_presence_buff(void);
extern void mmi_imps_presence_free_mem_and_back(void);
extern void mmi_imps_public_profile_write_to_file(void);
extern void mmi_imps_public_profile_save_done(S32 result);
extern U8 mmi_imps_public_profile_del_callback(void *param);
extern void mmi_imps_free_public_profile_buff(void);
extern void mmi_imps_public_profile_free_mem_and_back(void);
extern void mmi_imps_hilite_presence(void);
extern void mmi_imps_hilite_public_profile_1(void);
extern void mmi_imps_pre_entry_presence(void);
extern void mmi_imps_entry_presence(void);
extern void mmi_imps_exit_presence(void);
extern void mmi_imps_pre_entry_public_profile_1(void);
extern void mmi_imps_entry_public_profile_1(void);
extern void mmi_imps_exit_public_profile_1(void);
extern void mmi_imps_exit_public_profile_2(void);
extern void mmi_imps_exit_inline_editor(U16 scrnID, FuncPtr entryFuncPtr);

extern void mmi_imps_public_profile_2_fill_inline_struct(void);
extern void mmi_imps_hilite_public_profile_2(void);
extern void mmi_imps_pre_entry_public_profile_2(void);
extern void mmi_imps_entry_public_profile_2(void);


#define ABOUT_FRIEND_PROT
extern void mmi_imps_hilite_about_friend(void);
extern void mmi_imps_pre_entry_about_friend(void);
extern void mmi_imps_entry_about_friend(void);
extern U8 mmi_imps_about_friend_del_callback(void *param);
extern void mmi_imps_entry_about_friend_opt(void);
extern void mmi_imps_hilite_about_friend_edit(void);
extern void mmi_imps_hilite_about_friend_refresh(void);
extern void mmi_imps_pre_entry_about_friend_edit(void);
extern void mmi_imps_about_friend_edit_done(void);
extern void mmi_imps_about_friend_edit_finish(S32 result);
extern void mmi_imps_about_friend_refersh(void);
extern void mmi_imps_about_friend_abort(void);
extern void mmi_imps_about_friend_refresh_finish(void);

#define ADD_CONT_PROT
extern void mmi_imps_hilite_add_cont(void);
extern void mmi_imps_entry_add_cont(void);
extern void mmi_imps_hilite_add_direct(void);
extern void mmi_imps_pre_entry_add_direct(void);
extern void mmi_imps_entry_add_direct(void);
extern void mmi_imps_exit_add_direct(void);
extern void mmi_imps_add_direct_save(void);
extern void mmi_imps_add_direct_save_yes(void);
extern void mmi_imps_add_direct_fill_inline_struct(void);
extern void mmi_imps_hilite_direct_search(void);
extern void mmi_imps_pre_entry_cont_search(void);
extern void mmi_imps_entry_cont_search(void);


extern void mmi_imps_exit_cont_search(void);
extern void mmi_imps_free_search_mem(void);
extern void mmi_imps_search_free_mem_n_back(void);
extern U8 mmi_imps_search_scr_del_callback(void *param);
extern void mmi_imps_search_fill_inline_struct(void);
extern void mmi_imps_entryt_search_opt(void);
extern void mmi_imps_hilite_search_done(void);
extern void mmi_imps_hilite_search_quit(void);
extern void mmi_imps_search_start(void);
extern void mmi_imps_search_quit(void);
extern void mmi_imps_search_abort(void);
extern void mmi_imps_abort_search_finish(void);
extern void mmi_imps_hilite_search_from_phb(void);
extern void mmi_imps_entry_search_from_phb(void);
extern void mmi_imps_search_phb_callback(MMI_PHB_VCARD_STRUCT *entity);
extern void mmi_imps_entry_search_result(void);
extern void mmi_imps_hilite_search_result(S32 index);
extern void mmi_imps_pre_entry_sel_group(void);
extern void mmi_imps_entry_sel_group(void);
extern void mmi_imps_hilite_sel_group(S32 index);
extern void mmi_imps_pre_entry_input_name(void);
extern void mmi_imps_entry_cont_input_name(void);
extern void mmi_imps_entry_add_cont_input_name_opt(void);
extern void mmi_imps_hilite_input_name_opt_done(void);
extern void mmi_imps_add_cont_done(void);
extern void mmi_imps_add_cont_finished(S32 result);

#define SUBS_NOTIFY_PROT
extern void mmi_imps_hilite_subs_unsubs_notify(void);
extern void mmi_imps_subs_unsubs_notify(void);
extern void mmi_imps_subs_notify_finished(U8 result);
extern void mmi_imps_unsubs_notify_finished(U8 result);

#define SYSTEM_MESSAGE
extern void mmi_imps_entry_system_message(void);
extern void mmi_imps_give_up_sm_confirm(void);
extern void mmi_imps_system_message_option(void);
extern void mmi_imps_hilite_system_message_option(S32 index);
extern void mmi_imps_check_system_message(void);
extern void mmi_imps_view_next_system_message(void);
extern void mmi_imps_del_system_message_scr(void);
extern void mmi_imps_give_up_system_message(void);
extern void mmi_imps_free_system_message(void);
extern void mmi_imps_system_message_yes(void);
extern void mmi_imps_input_verification_done(void);
extern void mmi_imps_system_message_string(S8* buff);
extern void mmi_imps_system_message_res_cnf(void);
extern void mmi_imps_entry_verification_key(void);

#define PRESENCE_AUTH
extern void mmi_imps_entry_presence_authentication(void);
extern void mmi_imps_pa_auth_string(S8 *buff);
extern void mmi_imps_entry_pa_auth_accept(void);
extern void mmi_imps_entry_pa_auth_reject(void);
extern void mmi_imps_check_pa_auth(void);

#define HTTP_AUTH
extern void mmi_imps_create_attributelist_finished(U8 result);
extern void mmi_imps_entry_http_auth(void);
extern void mmi_imps_http_auth_confirm_hdlr(void);
extern void mmi_imps_http_auth_no_hdlr(void);
extern void mmi_imps_http_auth_yes_hdlr(void);
extern void mmi_imps_http_auth_confirm_hdlr(void);
extern void mmi_imps_free_http_auth_buffer(void);

#define SORT_PROT
extern void mmi_imps_hilite_sort(void);
extern void mmi_imps_entry_sort(void);
extern void mmi_imps_hilite_sort_by_name(void);
extern void mmi_imps_entry_sort_by_name(void);
extern void mmi_imps_hilite_sort_by_status(void);
extern void mmi_imps_entry_sort_by_status(void);
extern void mmi_imps_hilite_sort_by_group(void);
extern void mmi_imps_entry_sort_by_group(void);
extern void mmi_imps_sort_list(void);
extern void mmi_imps_sort_by_name(void);
extern void mmi_imps_sort_by_group(void);
extern void mmi_imps_sort_by_status(void);

#define WATCH_LIST_PROT
extern void mmi_imps_hilite_get_watch_list(void);
extern void mmi_imps_get_watch_list(void);
extern void mmi_imps_get_watch_list_abort(void);
extern void mmi_imps_get_watch_list_abort_finish(void);
extern void mmi_imps_entry_watch_list(void);
extern S32 mmi_imps_pre_entry_watch_list(S16 *file_name);
extern void mmi_imps_hilite_watch_list(S32 index);

#define CHAT_PROT
extern void mmi_imps_hilite_cont_send_msg(void);
extern void mmi_imps_pre_entry_chat(void);
extern void mmi_imps_chat_show_input_screen(void);
extern void mmi_imps_chat_hide_input_screen(BOOL redraw);
extern void mmi_imps_chat_register_key_hdlr(void);
extern void mmi_imps_entry_chat(void);
extern void mmi_imps_exit_chat(void);
extern void mmi_imps_entry_chat_opt(void);
extern void mmi_imps_hilite_chat_send(void);
extern void mmi_imps_hilite_chat_write(void);
extern void mmi_imps_entry_chat_write(void);
extern void mmi_imps_entry_chat_send_opt(void);
extern void mmi_imps_hilite_chat_insert_symbol(void);
extern void mmi_imps_entry_chat_insert_symbol(void);
extern void mmi_imps_hilite_symbol(S32 index);
extern void mmi_imps_hilite_chat_invite(void);
extern void mmi_imps_pre_entry_chat_invite(void);
extern void mmi_imps_entry_chat_invite(void);
extern void mmi_imps_hilite_chat_save(void);
extern void mmi_imps_hilite_chat_text_format(void);
extern void mmi_imps_pre_entry_chat_text_format(void);
extern void mmi_imps_entry_chat_text_format(void);
extern void mmi_imps_eixt_chat_text_format(void);
extern void mmi_imps_chat_text_format_fill_inline_struct(void);
extern void mmi_imps_chat_text_format_done(void);
extern void mmi_imps_text_format_free_mem(void);
extern U8 mmi_imps_text_format_scr_del_callback(void *param);
extern void mmi_imps_hilite_chat_send_file(void);
extern void mmi_imps_entry_chat_send_file(void);
extern void mmi_imps_chat_sel_file_callback(void *filePath, S32 is_short);
extern void mmi_imps_send_file_confirm_yes(void);
extern void mmi_imps_send_file_confirm_no(void);

/* added by keneng start */
extern void mmi_imps_pre_entry_chat_member(void);
extern U8 mmi_imps_member_scr_del_callback(void *param);
extern S32 mmi_imps_get_member_from_file(S16 *filename, U8 count, U8 pri_level);
extern void mmi_imps_get_member_done(S32 result);
extern void mmi_imps_get_group_member_abort(void);
extern void mmi_imps_hilite_chat_add_member(void);
extern void mmi_imps_entry_chat_add_member(void);
extern void mmi_imps_hilite_chat_list_rejected(void);
extern void mmi_imps_entry_chat_list_rejected(void);
extern U8 mmi_imps_rejected_scr_del_callback(void *param);
extern void mmi_imps_free_list_rejected_buff(void);
extern void mmi_imps_chat_pre_del_rejected(void);
extern void mmi_imps_hilite_chat_list_joined(void);
extern void mmi_imps_pre_entry_chat_list_joined(void);
extern void mmi_imps_entry_chat_list_joined(void);
extern U8 mmi_imps_joined_scr_del_callback(void *param);
extern void mmi_imps_free_list_joined_buff(void);
extern void mmi_imps_get_joined_user_abort(void);
extern void mmi_imps_get_joined_user_abort_finish(void);
extern S32 mmi_imps_get_joined_from_file(S16 *filename, U8 count);
extern void mmi_imps_hilite_list_joined_item(S32 index);
extern void mmi_imps_hilite_list_member_item(S32 index);
extern void mmi_imps_hilite_list_rejected_item(S32 index);
extern void mmi_imps_hilite_chat_add_directly(void);
extern void mmi_imps_pre_entry_chat_add_direct(void);
extern void mmi_imps_hilite_chat_add_from_online(void);
extern void mmi_imps_pre_entry_chat_add_from_online(void);
extern void mmi_imps_add_member_from_online(void);
extern void mmi_imps_entry_chat_list_member_opt(void);
extern void mmi_imps_hilite_chat_del_member(void);
extern void mmi_imps_entry_del_member_confirm(void);
extern void mmi_imps_del_member(void);
extern void mmi_imps_del_member_done(S32 result);
extern void mmi_imps_hilite_chat_set_mod_user(void);
extern void mmi_imps_chat_set_mod_user(void);
extern void mmi_imps_chat_set_mod_user_done(S32 result);
extern void mmi_imps_chat_del_rejected(void);
extern void mmi_imps_entry_chat_list_joined_opt(void);
extern void mmi_imps_hilite_chat_add_to_mem(void);
extern void mmi_imps_entry_add_to_mem_confirm(void);
extern void mmi_imps_chat_add_to_mem(void);
extern void mmi_imps_add_member_done(S32 result);
extern void mmi_imps_hilite_chat_add_to_rejected(void);
extern void mmi_imps_entry_add_to_rejected_confirm(void);
extern void mmi_imps_chat_add_to_rejected(void);
extern void mmi_imps_add_reject_user_done(S32 result);
extern void mmi_imps_delete_reject_user_done(S32 result);
extern void mmi_imps_chat_add_reject_user(void);
extern void mmi_imps_abort_get_joined_finish(void);
/* added by keneng end */
extern void mmi_imps_hilite_chat_member(void);
extern void mmi_imps_entry_chat_member(void);
extern void mmi_imps_entry_chat_save(void);
extern void mmi_imps_chat_save_select_path_done(void *path, int is_short);
extern void mmi_imps_entry_chat_save_filename(void);
extern void mmi_imps_entry_chat_save_opt(void);
extern void mmi_imps_hilite_chat_save_opt_done(void);
extern void mmi_imps_chat_save_done(void);
extern void mmi_imps_hilite_chat_close(void);
extern void mmi_imps_entry_chat_close(void);
extern void mmi_imps_chat_close(void);
extern void mmi_imps_close_chat_room_done(S32 result);
extern void mmi_imps_hilite_chat_send_done(void);
extern void mmi_imps_chat_send_done(void);
extern void mmi_imps_chat_input_opt(void);
extern void mmi_imps_chat_send_key_hdlr(void);
extern void mmi_imps_chat_disp_input_msg(void);
extern void mmi_imps_chat_recv_msg(mmi_imps_newmessage_ind_struct *ind, U8 room_id);
extern void mmi_imps_chat_save_file_callback(void *info);
extern void mmi_imps_chat_disp_user_change_msg(S32 room_id, imps_entity_struct *joined_user, S32 type);
extern void mmi_imps_chat_display_send_failed(U8 room_id, U16 *msg);
extern void mmi_imps_chat_flush_msg(U16 *data, S32 room_id);
extern S32 mmi_imps_chat_insert_session(void);
extern void mmi_imps_sym_sel_done(void);
extern void mmi_imps_entry_dl_large_file(void);

#define INVITE_PROT
extern void mmi_imps_hilite_invite_item(S32 index);
extern void mmi_imps_entry_invite_note(void);
extern void mmi_imps_entry_invite_note_opt(void);
extern void mmi_imps_hilite_invite_note_opt_done(void);
extern void mmi_imps_invite_done(void);
extern S32 mmi_imps_invite_insert_session(void);
extern void mmi_imps_invite_disp_msg(void);
extern void mmi_imps_invite_disp_failed_msg(void);
extern void mmi_imps_invite_start(S32 state, S32 id);
extern void mmi_imps_invite_finish(BOOL accept, S32 session_id, imps_entity_struct *sender, U16 *response_note);
extern void mmi_imps_check_pending_invite(void);
extern void mmi_imps_entry_invite_ind(void);
extern void mmi_imps_ps_invite_reject(void);
extern U8 mmi_imps_invite_ind_scr_del_callback(void *param);
extern void mmi_imps_invite_ind_free_mem(void);
extern void mmi_imps_invite_ind_free_n_back(void);
extern void mmi_imps_invite_ind_release_node(void);
extern void mmi_imps_invite_ind_gen_note(void);
extern void mmi_imps_invite_accept(void);
extern void mmi_imps_entry_invite_reminder(void);
extern void mmi_imps_entry_invite_key_lokced(U16 lsk_img_id, U16 lsk_str_id, U16 rsk_img_id, U16 rsk_str_id);
extern void mmi_imps_free_invite_list(void);

#define GROUP_PROT
extern void mmi_imps_hilite_manage_group(void);
extern void mmi_imps_entry_group(void);
extern void mmi_imps_hilite_group(S32 index);
extern void mmi_imps_entry_group_opt(void);
extern void mmi_imps_entry_group_edit(void);
extern void mmi_imps_exit_group_edit(void);
extern U8 mmi_imps_group_scr_del_callback(void *param);
extern void mmi_imps_group_free_mem_n_back(void);
extern void mmi_imps_group_free_mem(void);
extern void mmi_imps_group_fill_inline_struct(void);
extern void mmi_imps_group_save(void);
extern void mmi_imps_group_save_yes(void);
extern void mmi_imps_group_edit_done(S32 result);
extern void mmi_imps_hilite_group_create(void);
extern void mmi_imps_hilite_group_edit(void);
extern void mmi_imps_pre_entry_group_create(void);
extern void mmi_imps_pre_entry_group_edit(void);
extern void mmi_imps_hilite_group_del(void);
extern void mmi_imps_entry_group_del(void);
extern void mmi_imps_group_del_yes(void);
extern void mmi_imps_group_del_done(S32 result);
extern void mmi_imps_hilite_group_list_member(void);
extern void mmi_imps_pre_entry_group_list_member(void);
extern void mmi_imps_entry_group_list_member(void);

#define BLOCK_PROT
extern void mmi_imps_hilite_block_grant(void);
extern void mmi_imps_entry_block_grant(void);
extern void mmi_imps_block_grant_done(S32 result);

#define ROOM_PROT
extern void mmi_imps_room_reset_cntx(mmi_imps_room_struct *room);
extern void mmi_imps_room_close_finished(mmi_imps_room_struct *room);
extern void mmi_imps_new_room_string(S8 *chat_buff, S8 *room);
extern void mmi_imps_hilite_chat_room(void);
extern void mmi_imps_entry_room(void);
extern void mmi_imps_hilite_room(S32 index);
extern void mmi_imps_entry_room_opt(void);
extern void mmi_imps_hilite_room_open(void);
extern void mmi_imps_pre_entry_room_open(void);
extern void mmi_imps_entry_room_open(void);
extern void mmi_imps_exit_room_open(void);
extern U8 mmi_imps_room_scr_del_callback(void *param);
extern void mmi_imps_free_room_mem(void);
extern void mmi_imps_room_create_fill_inline_struct(void);
extern void mmi_imps_room_create_done(void);
extern void mmi_imps_room_create_yes(void);
extern void mmi_imps_room_create_finish(S32 result);
extern void mmi_imps_hilite_room_search(void);
extern void mmi_imps_room_pre_entry_search(void);
extern void mmi_imps_entry_room_search(void);
extern void mmi_imps_exit_room_search(void);
extern void mmi_imps_room_search_fill_inline_struct(void);
extern void mmi_imps_entryt_room_search_opt(void);
extern void mmi_imps_hilite_room_search_done(void);
extern void mmi_imps_hilite_room_search_quit(void);
extern void mmi_imps_room_search_quit(void);
extern void mmi_imps_room_search_start(void);
extern void mmi_imps_hilite_room_close(void);
extern void mmi_imps_entry_room_close(void);
extern void mmi_imps_room_close(void);
extern void mmi_imps_hilite_room_jump_to(void);
extern void mmi_imps_hilite_room_join(void);
extern void mmi_imps_pre_entry_room_direct_join(void);
extern void mmi_imps_entry_room_direct_join(void);
extern void mmi_imps_eixt_room_direct_join(void);
extern void mmi_imps_room_join_fill_inline_struct(void);
extern void mmi_imps_room_direct_join_confirm(void);
extern void mmi_imps_room_direct_join_yes(void);
extern void mmi_imps_room_jump_to(void);
extern void mmi_imps_pre_entry_join(void);
extern void mmi_imps_entry_join(void);
extern void mmi_imps_exit_join(void);
extern void mmi_imps_join_fill_inline_struct(void);
extern void mmi_imps_join_free_mem_n_back(void);
extern U8 mmi_imps_join_scr_del_callback(void *param);
extern void mmi_imps_join_free_mem(void);
extern void mmi_imps_join_room(void);
extern void mmi_imps_join_room_yes(void);
extern void mmi_imps_join_room_finished(void *msg);

#define PS_IMPS_PROT
extern void mmi_imps_init_ps_before_idle(void);
extern void mmi_imps_ps_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void mmi_imps_ps_login_req(void);
extern void mmi_imps_ps_login_rsp(void *msg);
extern void mmi_imps_ps_logout_req(void);
extern void mmi_imps_ps_logout_rsp(void *msg);
extern void mmi_imps_ps_abort_login_req(void);
extern void mmi_imps_ps_abort_login_rsp(void *msg);
extern void mmi_imps_ps_get_contact_list_req(void);
extern void mmi_imps_ps_get_contact_list_rsp(void *msg);
extern void mmi_imps_ps_view_contact_list_req(U8 index);
extern void mmi_imps_ps_view_contact_list_rsp(void *msg);
extern void mmi_imps_ps_search_req(U8 type);
extern void mmi_imps_ps_search_rsp(void *msg);
extern void mmi_imps_ps_abort_search_req(void);
extern void mmi_imps_ps_abort_search_rsp(void *msg);
extern void mmi_imps_ps_edit_contact_list_req(void);
extern void mmi_imps_ps_edit_contact_list_rsp(void *msg);
extern void mmi_imps_ps_add_contact_list_req(void);
extern void mmi_imps_ps_add_contact_list_rsp(void *msg);
extern void mmi_imps_ps_del_contact_list_req(void);
extern void mmi_imps_ps_del_contact_list_rsp(void *msg);
extern void mmi_imps_ps_del_cont_req(void);
extern void mmi_imps_ps_del_cont_rsp(void *msg);
extern void mmi_imps_add_cont_req(U8 *group_id, U8 *cont_id, S8 *nick_name);
extern void mmi_imps_add_cont_rsp(void *msg);
extern void mmi_imps_edit_cont_req(U8 *group_id, U8 *cont_id, S8 *nick_name);
extern void mmi_imps_edit_cont_rsp(void *msg);
extern void mmi_imps_sync_cont_list(void);
extern void mmi_imps_ps_get_pa_req(void *data);
extern void mmi_imps_ps_get_pa_rsp(void *msg);
extern void mmi_imps_ps_get_about_me_pa_req(void);
extern void mmi_imps_ps_get_single_pa_req(U8 *id);
extern void mmi_imps_ps_get_single_pa_rsp(void *msg);
extern void mmi_imps_abort_get_pa_req(void);
extern void mmi_imps_abort_get_pa_rsp(void *msg);
extern void mmi_imps_ps_pa_notify_ind(void *msg);
extern void mmi_imps_ps_update_pa_req(void);
extern void mmi_imps_ps_update_pa_rsp(void *msg);
extern void mmi_imps_ps_block_entity_req(U8 type);
extern void mmi_imps_ps_block_entity_rsp(void *msg);
extern void mmi_imps_ps_get_block_list_req(void);
extern void mmi_imps_ps_get_block_list_rsp(void *msg);
extern void mmi_imps_ps_newmsg_ind(void *msg);
extern void mmi_imps_ps_get_watch_list_req(void);
extern void mmi_imps_ps_get_watch_list_rsp(void *msg);
extern void mmi_imps_ps_abort_get_watch_list_req(void);
extern void mmi_imps_ps_abort_get_watch_list_rsp(void *msg);
extern void mmi_imps_ps_create_group_req(void);
extern void mmi_imps_ps_create_group_rsp(void *msg);
extern void mmi_imps_ps_join_group_req(S8 *id);
extern void mmi_imps_ps_join_group_rsp(void *msg);
extern void mmi_imps_ps_del_group_req(U8 *room_id);
extern void mmi_imps_ps_del_group_rsp(void *msg);
extern void mmi_imps_ps_leave_group_req(U8 *room_id);
extern void mmi_imps_ps_leave_group_rsp(void *msg);
extern void mmi_imps_ps_leave_group_ind(void *msg);
extern void mmi_imps_ps_group_change_ind(void *ind);
extern void mmi_imps_ps_ready_ind(void *msg);
extern void mmi_imps_ps_invite_req(S32 id);
extern void mmi_imps_ps_invite_rsp(void *msg);
extern void mmi_imps_ps_invite_reply_req(BOOL accept);
extern void mmi_imps_ps_invite_response_ind(void *msg);
extern void mmi_imps_ps_invite_ind(void *msg);
extern void mmi_imps_ps_invite_reply_rsp(void *msg);
extern void mmi_imps_ps_reject_invite_reply_rsp(void *msg);
extern void mmi_imps_ps_invite_res(void);
extern void mmi_imps_ps_send_msg_req(S32 msg_id, S16 *msg, U8 *recv_id, U8 recv_type, S8 *screen_name, BOOL is_text_plain);
extern void mmi_imps_ps_send_msg_rsp(void *msg);
extern void mmi_imps_ps_server_disconn_ind(void *msg);

extern void mmi_imps_ps_get_group_member_req(void);
extern void mmi_imps_ps_get_group_member_rsp(void *msg);
extern void mmi_imps_ps_abort_get_group_member_req(void);
extern void mmi_imps_ps_abort_get_group_member_rsp(void *msg);
extern void mmi_imps_ps_add_group_member_req(void *user_list);
extern void mmi_imps_ps_add_group_member_rsp(void *msg);
extern void mmi_imps_ps_remove_group_member_req(void);
extern void mmi_imps_ps_remove_group_member_rsp(void *msg);
extern void mmi_imps_ps_get_joined_user_req(void);
extern void mmi_imps_ps_abort_get_joined_user_req(void);
extern void mmi_imps_ps_abort_get_joined_user_rsp(void *msg);
extern void mmi_imps_ps_get_joined_user_rsp(void *msg);
extern void mmi_imps_ps_member_access_req(void);
extern void mmi_imps_ps_member_access_rsp(void *msg);
extern void mmi_imps_ps_reject_group_user_req(BOOL is_add, void *user_list);
extern void mmi_imps_ps_add_reject_group_user_rsp(void *msg);
extern void mmi_imps_ps_delete_reject_group_user_rsp(void *msg);

extern void mmi_imps_ps_subs_notify_req(void);
extern void mmi_imps_ps_unsubs_notify_req(void);
extern void mmi_imps_ps_subs_notify_rsp(void *msg);
extern void mmi_imps_ps_unsubs_notify_rsp(void *msg);
extern void mmi_imps_ps_notify_request_ind(void *msg);
extern void mmi_imps_ps_update_pp_req(void);
extern void mmi_imps_ps_update_pp_rsp(void *msg);
extern void mmi_imps_ps_get_pp_req(void);
extern void mmi_imps_ps_get_pp_rsp(void *msg);
extern void mmi_imps_ps_system_message_ind(void *msg);
extern void mmi_imps_ps_system_message_user_req(void);
extern void mmi_imps_ps_system_message_user_rsp(void *msg);
extern void mmi_imps_ps_dl_large_file_req(void);
extern void mmi_imps_ps_dl_large_file_rsp(void *msg);
extern void mmi_imps_ps_get_about_me_pp_req(void);
extern void mmi_imps_ps_get_about_me_pp_rsp(void *msg);

extern void mmi_imps_ps_pa_auth_ind(void *msg);
extern void mmi_imps_presence_auth_user_req(BOOL is_accept);
extern void mmi_imps_ps_create_attributelist_req(void *id_list, U32 attr_list);
extern void mmi_imps_ps_create_attributelist_rsp(void *msg);
extern void mmi_imps_ps_http_auth_ind(void *Msg);
extern void mmi_imps_ps_send_http_auth_res(void);

#define TAB_PROT
extern void mmi_imps_tab_init(void);
extern void mmi_imps_tab_del(U8 tab_index, U8 hilite);
extern void mmi_imps_tab_prev(void);
extern void mmi_imps_tab_next(void);
extern void mmi_imps_tab_jump(int index);
extern void mmi_imps_tab_redraw(U16 scr_id);
extern void mmi_imps_tab_update_event(mmi_imps_room_struct *room, imps_entity_struct *entity);

#define UTIL_IMPS_PROT
extern void mmi_imps_util_init_list(void);
extern U16 mmi_imps_util_get_err_str(S32 err);
extern void mmi_imps_util_get_work_path(S8 *dest);
extern void mmi_imps_util_get_img_path(S8 *dest);
extern BOOL mmi_imps_util_is_imps_scr(U16 curr_scr);
extern BOOL mmi_imps_util_is_in_imps(void);
extern void mmi_imps_util_del_up_to_screen(U16 scr_id);
extern void mmi_imps_util_go_back_2_hist(void);
extern void mmi_imps_util_del_scr_after_progress(U16 result_scr);
extern void mmi_imps_util_free_buff_when_logout(void);
extern S32 mmi_imps_util_get_seq_no(void);
extern void mmi_imps_util_read_nvram(void *buff);
extern void mmi_imps_util_write_nvram(void *buff);
extern S32 mmi_imps_util_get_file_size(S8 *filePathPtr, S32 *fileSizePtr);
extern BOOL mmi_imps_util_check_file_exist(S8 *filePathName);
extern void mmi_imps_util_update_cont(void);
extern S32 mmi_imps_util_write_cont(void);
extern S32 mmi_imps_util_read_cont(void);
extern S32 mmi_imps_util_write_group(void);
extern S32 mmi_imps_util_read_group(void);
extern void mmi_imps_util_reset_cont_list(void);
extern void mmi_imps_util_reset_presence(void *prof_buff);
extern BOOL mmi_imps_util_is_cont_exist(S8 *id);
extern BOOL mmi_imps_util_is_id_same(S8 *src, S8 *dest);
extern BOOL mmi_imps_util_is_room_joined(S8 *id);
extern S32 mmi_imps_util_get_empty_room_slot(void);
extern S8 *mmi_imps_get_mine_type(S8 *file_ext);
extern void mmi_imps_util_append_dot(S8 *source);
extern void mmi_imps_util_copy_with_dot(S8 *source, S8 *dest, S32 max_len);
extern void mmi_imps_util_ansi_2_ucs2_menu(S8 *source, S8 *dest, S32 max_len);
extern void mmi_imps_util_generate_name_hint(S8 *source, S32 hint_id, S32 max_len);
extern BOOL mmi_imps_util_is_group_name_valid(S8 *name);
extern BOOL mmi_imps_util_is_username_valid(S8 *name);
extern void mmi_imps_util_append_wv(S8 *dest, S32 max_len);
extern S8 mmi_imps_util_strnicmp(S8 *src, S8 *dest, S32 maxlen);
extern S8 mmi_imps_util_stricmp(S8 *src, S8 *dest);
extern void mmi_imps_util_blink_tab(void);
extern mmi_imps_cont_struct *mmi_imps_util_search_cont(S8 *id);
extern void mmi_imps_util_update_status_icon(void);
extern void mmi_imps_util_update_login_icon(void);
extern void mmi_imps_util_disp_err_popup(U16 str_id);
extern void mmi_imps_util_disp_empty_popup(void);
extern U8 mmi_imps_util_is_on_idle(void);
extern void mmi_imps_util_disp_popup_done(void);
extern void mmi_imps_util_disp_warning_popup(U16 str_id);
extern void mmi_imps_util_play_tone(U8 tone_type);
extern S32 mmi_imps_util_find_room(S8 *room_id);
extern S32 mmi_imps_util_find_cont(S8 *cont_id);
extern void mmi_imps_util_file_path(S8 *ucs2_folder, S8 *prefix, U8 id);
extern S32 mmi_imps_util_get_entity_from_file(imps_entity_list_struct *databuff, S8 *filepath);
extern void mmi_imps_util_fs_error_handle(S32 result);
extern void mmi_imps_util_get_filename_from_fileindex(U32 fileindex, U16 filetype, S8* filename);
extern void mmi_imps_util_startup_wap_browser_req(U8 type, void *URL);
extern BOOL mmi_imps_util_is_fwd_lock_content(S8 *filePath);
extern BOOL mmi_imps_util_is_sep_delivery_content(S8* filePath);

extern void mmi_imps_ps_subs_pa_req(void *id_list);
extern void mmi_imps_ps_subs_pa_rsp(void *msg);
extern void mmi_imps_subscribe_pa_finished(S32 result);

void mmi_imps_check_not_agreed_service(void);

#ifdef IMPS_FOR_OMA_ONLY
extern void mmi_imps_hilite_subscribe(void);
extern void mmi_imps_hilite_unsubscribe(void);
extern void mmi_imps_entry_subscribe(void);
extern void mmi_imps_entry_unsubscribe(void);
extern void mmi_imps_ps_unsubs_pa_req(S8 *id);
extern void mmi_imps_hilite_group_broadcast(void);
extern void mmi_imps_entry_group_broadcast(void);
extern void mmi_imps_group_broadcast_done(void);
extern void mmi_imps_group_broadcast_finished(void);
extern void mmi_imps_ps_broadcast_msg_rsp(void *msg);
extern void mmi_imps_ps_broadcast_msg_req(S32 group_index, S8 *msg);
extern void mmi_imps_ps_subs_group_pa_req(U8 *id);
#endif /* IMPS_FOR_OMA_ONLY */ 

#ifdef __MMI_IMPS_OTA__
extern void mmi_imps_handle_ota(U16 config_id, S32 hConfig);
extern void mmi_imps_ota_init(U16 config_id, S32 hConfig);
#endif

#endif /* __MMI_IMPS__ */
#endif /* _MMI_IMPS_PROT_H */ 

