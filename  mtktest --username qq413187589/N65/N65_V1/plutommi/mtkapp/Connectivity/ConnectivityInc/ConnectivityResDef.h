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
 * ConnectivityResDef.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for connectivity application resource definations
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CONNECTIVITY_RES_DEF_H__
#define __CONNECTIVITY_RES_DEF_H__

#include "MMI_features.h"

/***************************************************************************** 
* Predefine header checking
*****************************************************************************/
#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 


/***************************************************************************** 
* String Define
*****************************************************************************/

/**
  * USB Device
  **/
enum STR_LIST_EXTDEV_USB
{
    STR_EXTDEV_USB_BEGIN = EXT_DEVICE_BASE + 1,

    STR_USB_CONFIG_TITLE,

    STR_USB_CONFIG_CDCACM_ONLY,
    STR_USB_CONFIG_MS_ONLY, /* For charger/alarm power on */
    STR_USB_CONFIG_MS,
    STR_USB_CONFIG_CDCACM_DATA,
    //STR_USB_CONFIG_CDCACM_DEBUG,

    STR_USB_CONFIG_PICT_BRIGE,
    STR_USB_PICT_BRIGE_CONFIGING,
    
    STR_ID_USB_CONFIG_WEBCAM,
    STR_ID_USB_NOTIFY_WEBCAM_ERROR,
    STR_ID_USB_WEBCAM_STOPPED,
    STR_ID_USB_NOTIFY_WEBCAM_CAM_ERROR,

    STR_USB_CDCACM_SETTING_SCR,
    STR_USB_SHUTDOWN_SCR,
    STR_USB_POWER_ON_PROCESSING,

    STR_ID_USB_MODE_PROGRESS,
    STR_ID_USB_MODE_EXPORTED_WARNING,
    STR_ID_USB_IRCOMM_OCCUPY_CDCACM,
    STR_ID_USB_NO_MS_FOR_PC,
    STR_ID_USB_SYS_NOT_READY,
    STR_ID_USB_UART2_OCCUPIED,
    STR_EXTDEV_USB_LAST
};

/**
  * IrDA Device
  **/
enum STR_LIST_EXTDEV_IRDA
{
    STR_EXTDEV_IRDA_BEGIN = STR_EXTDEV_USB_LAST,

    STR_IRDA_MENU_TITLE,

    /* Priyesh - Memory Card Support */
    STR_IRDA_MENU_ACTIVATION,
    STR_IRDA_MENU_STORAGE,
    STR_IRDA_STORAGE_PHONE,
    STR_IRDA_STORAGE_CARD,
    STR_IRDA_NO_CARD_ERROR,
    STR_IRDA_FILE_RECEIVED,
    /* Priyesh - Memory Card Support */

    STR_IRDA_MENU_OPEN,
    STR_IRDA_MENU_CLOSE,
    STR_IRDA_MENU_PERIOD,
    STR_IRDA_RECV_DISK_FULL,
    STR_IRDA_RECV_ROOT_DIR_FULL,
    STR_IRDA_RECV_FILE_IND,
    STR_IRDA_NOTY_RECV_FILE_BROWSE,
    STR_IRDA_NOTY_RECV_FILE_HED,
    STR_IRDA_NOTY_RECV_FILE_TIL,
    STR_IRDA_DEV_BUSY,
    STR_IRDA_THEME_FILE_RECV,
    STR_ID_DLT_DO_YOU_WANT_TO_ACTIVATE,

    STR_IRDA_SEND,  /* PMT PANKAJ */
    STR_IRDA_WRITE_FILE_FAIL,
    STR_EXTDEV_IRDA_LAST
};

/**
  * Bluetooth Device
  **/
enum STR_LIST_EXTDEV_BT
{
    STR_EXTDEV_BT_BEGIN = STR_EXTDEV_IRDA_LAST,

    /* for Handphone solution only */
    STR_BT_DISCON,
    STR_BT_SWITCH,
    STR_BT_PWRON,
    STR_BT_SHHF,
    STR_BT_SEARCH,
    STR_BT_SEARCH_FOUND,
    STR_BT_SEARCH_RES,
    STR_BT_PAIR,
    STR_BT_PAIRING,
    STR_BT_ENTER_PIN,
    STR_BT_ENLIST_TRDEV_CNF,    /* Enlist confirm string  */
    STR_BT_ENLIST_TRDEV_PROC,   /* Enlist prograssing string  */
    STR_BT_MYDEV,
    STR_BT_MYDEVOPT_CONN,
    STR_BT_MYDEVOPT_REN,
    STR_BT_MYDEVOPT_DEL,
    STR_BT_MYDEVOPT_AUTH,
    STR_BT_MYDEVOPT_SCH,
    STR_BT_MYDEVOPT_SERVLST,
    STR_BT_MYDEVOPT_BROWSE,
    STR_BT_SET,
    STR_BT_SET_VIS,
    STR_BT_SET_VIS_PROC,
    STR_BT_SET_NAME,
    STR_BT_SET_NAME_DONE,
    STR_BT_SET_NAME_DENY,
    STR_BT_SET_AUTH,
    STR_BT_SET_PATH,
    STR_BT_SET_PATH_PHONE,
    STR_BT_SET_PATH_HF,
    STR_BT_AUD_PATH_PHONE,
    STR_BT_AUD_PATH_HF,

    STR_BT_RFC_CON,
    STR_BT_RFC_CONFAIL,
    STR_BT_RFC_DISCON,
    STR_BT_SCO_CON,
    STR_BT_SCO_DISCON,

    STR_BT_HS_CON_AUTH,     /* Ask for user's permission to be connected via audio gateway profile */
    STR_BT_HF_CON_AUTH,     /* Ask for user's permission to be connected via handfree profile */
    STR_BT_DUN_CON_AUTH,    /* Ask for user's permission to be connected via dailup network profile */
    STR_BT_SPP_CON_AUTH,    /* Ask for user's permission to be connected via serial port profile */
    STR_BT_FAX_CON_AUTH,    /* Ask for user's permission to be connected via fax profile */

    STR_BT_PROFCON_HS,  /* Audio Gateway profile connected */
    STR_BT_PROFCON_HF,  /* Handfree profile connected */
    STR_BT_PROFCON_DUN, /* Dailup Netowk profile connected */
    STR_BT_PROFCON_SPP, /* Serial profile connected */
    STR_BT_PROFCON_FAX, /* Fax profile connected  */

    STR_BT_PWRON_CNF,
    STR_BT_CONN_CNF,
    STR_BT_BUSY,
    STR_BT_HW_ERROR,
    STR_BT_PANIC_RECOV,
    STR_BT_DISCOV_PERIOD,
    STR_BT_MYDEV_FULL,

    /* common string id */
    STR_BT_MENU_TITLE,
    STR_BT_LSK_DISC,
    STR_BT_CM_SETPATH,
    STR_BT_CONNECT_LAST_HEADSET, /* Configure Default Headset */
    STR_BT_NO_DEFAULT_HEADSET,

    STR_BT_LSK_CONN,

    STR_BT_POWER,
    STR_BT_SWITCHING,
    STR_BT_SWITCHED_ON,
    STR_BT_SWITCHED_OFF,
    STR_BT_RELEASE_ALL_CONN,
    STR_BT_RELEASE_DEV_CONN,
    STR_BT_RELEASING,
    STR_BT_CON_RELEASED,

    STR_BT_SEARCHING,
    STR_BT_SCH_AUD_DEV,
    STR_BT_SCH_OPP_DEV,
    STR_BT_SCH_ALL_DEV,
    STR_BT_SCH_RESULT,
    STR_BT_INQUIRY_STOP,
    STR_BT_INQUIRY_STOPPING,
    STR_BT_BOND,
    STR_BT_BOND_FAILED,
    STR_BT_SEND,
    STR_BT_BONDING,
    STR_BT_ENTER_PASSCODE,
    STR_BT_PAIR_REQ,
    STR_BT_PAIR_FAILED,
    STR_BT_PAIR_SUCCEED,
    STR_BT_START_PAIRING,
    STR_BT_CONNECT,
    STR_BT_CONNECT_AND_SET_AS_DEFAULT_HF,
    STR_BT_ACCEPT_CONNECT_FROM,
    STR_BT_CONNECTING,
    STR_BT_DISCONNECT,
    STR_BT_DISCONNECTING,
    STR_BT_REFRESH,
    STR_BT_REFRESH_SERVICE_LIST,
    STR_BT_REFRESHING,
    STR_BT_DELETE,
    STR_BT_DELETING,
    STR_BT_DELETED,

    STR_BT_REMOTE_CONTROL,
    STR_BT_REMOTE_CTRL_LAST_DEV,
    STR_BT_REMOTE_CTRL_NO_LAST_DEV_INFO,    
    STR_BT_REMOTE_CTRL_PAIRED_DEV,    
    STR_BT_REMOTE_CTRL_DESKTOP,    
    STR_BT_REMOTE_CTRL_MEDIA_PLAYER,    
    STR_BT_REMOTE_CTRL_PRESENTER,    
    STR_BT_REMOTE_CTRL_KEYBOARD,  
    STR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM,
    STR_BT_UNSUPPORTED_KEY_CMD,
    STR_BT_REMOTE_CTRL_CONN_AUTH,

    STR_BT_MYDEVICE,
    STR_BT_MYDEV_OPT_CONN,
    STR_BT_MYDEV_OPT_DISCONN,
    STR_BT_MYDEV_OPT_CONNECTED_PROF,
    STR_BT_MYDEV_OPT_SET_DEFAULT_HS, /* Configure Default Headset */
    STR_BT_MYDEV_OPT_REN,
    STR_BT_MYDEV_OPT_AUTH,
    STR_BT_MYDEV_OPT_DEL,
    STR_BT_MYDEV_OPT_DEL_ALL,
    STR_BT_MYDEV_OPT_SUP_SER,
    STR_BT_MYDEV_OPT_SCH,

    STR_BT_ACT_DEV,

    STR_BT_DEV_SET,
    STR_BT_DEV_SET_VIS,
    STR_BT_DEV_SET_NAME,
    STR_BT_DEV_SET_AUTH,
    STR_BT_DEV_SET_AUDIO_PATH,
    STR_BT_DEV_SET_AUDIO_PATH_PHONE,
    STR_BT_DEV_SET_AUDIO_PATH_HF,
    STR_BT_DEV_SET_FTP,
    STR_BT_DEV_SET_SIMAP,

    STR_BT_ABOUT,
    STR_BT_BD_NAME,
    STR_BT_SERVICE,
    STR_BT_BD_ADDR,

    STR_BT_CONN_ED,
    STR_BT_DISCON_ED,

    STR_BT_ESTAB,
    STR_BT_RELEASE,

    STR_BT_AUDIO_SCO_CON,
    STR_BT_AUDIO_SCO_DISCON,


    STR_BT_PROF_SPP,
    STR_BT_PROF_LAP,
    STR_BT_PROF_DUN,
    STR_BT_PROF_SYNC,
    STR_BT_PROF_OPP,
    STR_BT_PROF_FTP,
    STR_BT_PROF_FAX,
    STR_BT_PROF_CTP,
    STR_BT_PROF_AUDIO_SOURCE,
    STR_BT_PROF_AUDIO_SINK,
    STR_BT_PROF_AVRCP_T,
    STR_BT_PROF_A2DP,
    STR_BT_PROF_AVRCP,
    STR_BT_PROF_ICP,
    STR_BT_PROF_PAN_PANU,
    STR_BT_PROF_PAN_NAP,
    STR_BT_PROF_PAN_GN,
    STR_BT_PROF_DIRECT_PRINTING,
    STR_BT_PROF_OBEX_IMAGING,
    STR_BT_PROF_OBEX_IMAGING_RESPONDER,
    STR_BT_PROF_HF,
    STR_BT_PROF_HS,
    STR_BT_PROF_BASIC_PRINTING,
    STR_BT_PROF_HID,
    STR_BT_PROF_SAP,
    STR_BT_PROF_PBAP,
    STR_BT_PROF_OBEX_BPPS,
    STR_BT_PROF_UNKNOWN,

    STR_BT_NOT_READY,
    STR_BT_HARDWARE_ERROR,
    STR_BT_DEV_BUSY,
    STR_BT_FAILED,
    STR_BT_NOT_SUPPORT,
    STR_BT_NOT_ALLOW,
    STR_BT_NO_SUPPORTED_PROFILE,
    STR_BT_PWR_ON_CNF,
    STR_BT_DISCONN_ALL_CONN_CNF,
    STR_BT_DISCONN_DEV_CONN_CNF,
    STR_BT_TRY_HFP_FIRST,
    STR_BT_ONE_HEADSET_ALREADY_CONNECTED,
    STR_BT_PAIRED_DEV_FULL,
    STR_BT_PROHIBIT_BY_A2DP,
    STR_BT_PROHIBIT_VIS_BY_A2DP,

    /* AVRCP command string*/
    STR_BT_AVRCP_CMD_UNIT_COMMAND,
    STR_BT_AVRCP_CMD_SUBUNIT_COMMAND,
    STR_BT_AVRCP_CMD_SELECT,
    STR_BT_AVRCP_CMD_UP,
    STR_BT_AVRCP_CMD_DOWN,
    STR_BT_AVRCP_CMD_LEFT,
    STR_BT_AVRCP_CMD_RIGHT,
    STR_BT_AVRCP_CMD_RIGHT_UP,
    STR_BT_AVRCP_CMD_RIGHT_DOWN,
    STR_BT_AVRCP_CMD_LEFT_UP,
    STR_BT_AVRCP_CMD_LEFT_DOWN,
    STR_BT_AVRCP_CMD_ROOT_MENU,
    STR_BT_AVRCP_CMD_SETUP,
    STR_BT_AVRCP_CMD_CONTENTS,
    STR_BT_AVRCP_CMD_FAVORITE,
    STR_BT_AVRCP_CMD_EXIT,
    STR_BT_AVRCP_CMD_0,
    STR_BT_AVRCP_CMD_1,
    STR_BT_AVRCP_CMD_2,
    STR_BT_AVRCP_CMD_3,
    STR_BT_AVRCP_CMD_4,
    STR_BT_AVRCP_CMD_5,
    STR_BT_AVRCP_CMD_6,
    STR_BT_AVRCP_CMD_7,    
    STR_BT_AVRCP_CMD_8,    
    STR_BT_AVRCP_CMD_9,
    STR_BT_AVRCP_CMD_DOT,
    STR_BT_AVRCP_CMD_ENTER,
    STR_BT_AVRCP_CMD_CLEAR,
    STR_BT_AVRCP_CMD_CHANNEL_UP,
    STR_BT_AVRCP_CMD_CHANNEL_DOWN,
    STR_BT_AVRCP_CMD_PREVIOUS_CHANNEL,
    STR_BT_AVRCP_CMD_SOUND_SELECT,
    STR_BT_AVRCP_CMD_INPUT_SELECT,
    STR_BT_AVRCP_CMD_DISPLAY_INFO,    
    STR_BT_AVRCP_CMD_HELP,
    STR_BT_AVRCP_CMD_PAGE_UP,
    STR_BT_AVRCP_CMD_PAGE_DOWN,
    STR_BT_AVRCP_CMD_POWER,
    STR_BT_AVRCP_CMD_VOLUME_UP,
    STR_BT_AVRCP_CMD_VOLUME_DOWN,
    STR_BT_AVRCP_CMD_MUTE,
    STR_BT_AVRCP_CMD_PLAY,
    STR_BT_AVRCP_CMD_STOP,
    STR_BT_AVRCP_CMD_PAUSE,
    STR_BT_AVRCP_CMD_RECORD,
    STR_BT_AVRCP_CMD_REWIND,
    STR_BT_AVRCP_CMD_FAST_FORWARD,
    STR_BT_AVRCP_CMD_EJECT,
    STR_BT_AVRCP_CMD_FORWARD,
    STR_BT_AVRCP_CMD_BACKWARD,
    STR_BT_AVRCP_CMD_ANGLE,
    STR_BT_AVRCP_CMD_SUBPICTURE,
    STR_BT_AVRCP_CMD_F1,
    STR_BT_AVRCP_CMD_F2,
    STR_BT_AVRCP_CMD_F3,
    STR_BT_AVRCP_CMD_F4,
    STR_BT_AVRCP_CMD_F5,
    /* End of AVRCP command string*/

    STR_BT_SWITCH_SPEECH_PATH,
    STR_BT_WAIT_PAIR_RESULT,
    STR_BT_WAIT_INQUIRY_FINISH,
    STR_BT_DISABLE_VISIBILITY,
    STR_BT_ENABLE_VISIBILITY,    
    STR_BT_OPERATION_NOT_ALLOWED_DIS_HFP_FIRST,
    STR_BT_PROHIBIT_VIS_BY_MAX_ACL,
    STR_BT_SET_NAME_LENGTH_LIMITATION,
    STR_BT_TRUNCATE_NAME_FOR_DIFF_CHAR_SET,
    STR_BT_PROHIBIT_BY_SIMAP,
    STR_BT_ACTIVATING,
    STR_BT_DEACTIVATING,
    STR_BT_CANCELLING,

    STR_BT_BPP_PRINT_BY_BT,
    STR_BT_BPP_BT_PRINTING,
    STR_BT_BPP_AUTHENTICATING,
    STR_BT_BPP_NEGOTIATING,
    STR_BT_BPP_GETTING_CAPABILITY,    
    STR_BT_BPP_PRINT_SETTING,
    STR_BT_BPP_SETTING_PAPER,
    STR_BT_BPP_SETTING_PAPER_A4,
    STR_BT_BPP_SETTING_PAPER_US,
    STR_BT_BPP_SETTING_PAPER_4X6,
    STR_BT_BPP_SETTING_SIDES,    
    STR_BT_BPP_SETTING_SIDES_ONE,
    STR_BT_BPP_SETTING_SIDES_TWO,
    STR_BT_BPP_SETTING_PAGES,
    STR_BT_BPP_SETTING_ORIENTATION,
    STR_BT_BPP_SETTING_ORIENTATION_PORTRAIT,    
    STR_BT_BPP_SETTING_ORIENTATION_LANDSCAP,    
    STR_BT_BPP_SETTING_QUALITY,
    STR_BT_BPP_SETTING_QUALITY_HIGH,    
    STR_BT_BPP_SETTING_QUALITY_NORMAL,
    STR_BT_BPP_SETTING_QUALITY_DRAFT,
    STR_BT_BPP_SETTING_COPIES,
    STR_BT_BPP_SETTING_COPIES_ERROR,
    STR_BT_BPP_SETTING_COPIES_EXCEED,
    STR_BT_BPP_SETTING_COPIES_EXCEED_END,
    STR_BT_BPP_LAYOUT_PREVIEW,
    STR_BT_BPP_PRINT,
    STR_BT_BPP_PRINT_JOB_CREATING,
    STR_BT_BPP_PRINT_DOCUMENT_COMPOSING,
    STR_BT_BPP_PRINTING,
    STR_BT_BPP_BACKGROUND,
    STR_BT_BPP_FOREGROUND,
    STR_BT_BPP_TROUBLE,
    STR_BT_BPP_TROUBLE_NOTICE,
    STR_BT_BPP_TROUBLE_JAM,    
    STR_BT_BPP_TROUBLE_PAUSED,    
    STR_BT_BPP_TROUBLE_DOOR,        
    STR_BT_BPP_TROUBLE_MARKER,            
    STR_BT_BPP_TROUBLE_MEDIA,            
    STR_BT_BPP_POPUP_PRINTER_BUSY,
    STR_BT_BPP_POPUP_AUTH_FAILED,
    STR_BT_BPP_POPUP_CONNECT_FAILED,
    STR_BT_BPP_POPUP_GET_ATTR_FAILED,
    STR_BT_BPP_POPUP_CREATE_JOB_FAILED,
    STR_BT_BPP_POPUP_COMPOSE_FAILED,
    STR_BT_BPP_POPUP_READ_FILE_FAILED,
    STR_BT_BPP_POPUP_BACKGROUND_PRINTING,
    STR_BT_BPP_POPUP_PRINTED,
    STR_BT_BPP_POPUP_CANCELED,
    STR_BT_BPP_POPUP_DISCONNECTED,
    STR_BT_BPP_POPUP_FORMAT_WARNING,
    STR_BT_BPP_CANCEL,    

    /* BIP */
    STR_BIP_SETTING,
    STR_BIP_SHARED_FOLDER,
    STR_BIP_CON_AUTH,   

    STR_BIP_RECV_FILE_IND,
    STR_BIP_SERVER_BUSY,

    STR_BIP_NOTY_RECV_FILE_BROWSE,
    STR_BIP_NOTY_RECV_FILE_HED,
    STR_BIP_NOTY_RECV_FILE_TIL,
    STR_BIP_NOTY_RECV_FILE_SINGLE_TIL,

    STR_BIP_IMGLIST_BROWSER,
    STR_BIP_OPTION_GET,
    STR_BIP_OPTION_GET_ALL,
    STR_BIP_OPTION_DETAIL,
    STR_BIP_OPTION_GET_THM,
    STR_BIP_OPTION_REFRESH,
    STR_BIP_OPTION_DISCONNECT,
    STR_BIP_STATUS_CONNECTING,
    STR_BIP_STATUS_DISCONNECTING,
    STR_BIP_STATUS_RECEIVING,
    STR_BIP_STATUS_GETTING_IMGPROP,
    STR_BIP_STATUS_GETTING_IMGTHM,
    STR_BIP_STATUS_SENDING,
    STR_BIP_STATUS_ABORTING,
    STR_BIP_STATUS_GETTING,
    STR_BIP_CON_EXIT,           /* Ask for exit BIP connection ? */
    STR_BIP_NOTY_RECV_IMAGE_BROWSE,
    STR_BIP_DETAIL_ENCODING,
    STR_BIP_DETAIL_PIXEL,
    STR_BIP_DETAIL_SIZE,
    STR_BIP_DETAIL_NAME,
    STR_BIP_EXIT_IMGBROWSER,
    STR_BIP_REFRESH_IMGLIST,

    STR_BIP_CON_DISCONNECTED,  
    STR_BIP_RECV_DISK_FULL,
    STR_BIP_RECV_ROOT_DIR_FULL,
    STR_BIP_OPEN_FILE_FAIL,
    STR_BIP_WRITE_FILE_FAIL,
    STR_BIP_READ_FILE_FAIL,
    STR_BIP_XML_GEN_FAIL,
  
    STR_BIP_DEV_BUSY,
    STR_BIP_NOTSUPPORT_BT_PUSH,

    STR_BIP_CONNECTING_CLIENT,
    STR_BIP_DRM_FORBIDDEN,
    STR_BIP_REQ_TIMEOUT,
    STR_BIP_GET_CUR_IMG,
    STR_BIP_ADDTO_GETLIST,
    STR_BIP_REMOVEFROM_GETLIST,
    
	STR_ID_BT_BIP,
	
    STR_EXTDEV_BT_LAST
};

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/**
  * FTP
  **/
enum STR_LIST_EXTDEV_FTP
{
    STR_EXTDEV_FTP_BEGIN = STR_EXTDEV_BT_LAST,

#ifdef __MMI_FTS_SUPPORT__
    STR_FTP_SETTING,
    STR_FTP_SHARED_FOLDER,
    STR_FTP_ACCESS_RIGHT,
    STR_FTP_OPTION_FULLY_CONTROL,
    STR_FTP_OPTION_READ_ONLY,
    STR_FTP_CON_AUTH,   /* Ask for user's permission to be connected via FTP profile */
    STR_FTP_RECV_FILE_IND,
    STR_FTP_SERVER_BUSY,
    STR_FTP_DISCONN_CLIENT,
    STR_FTP_QUESTION_MARK,
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
    STR_FTP_FILE_BROWSER,
    STR_FTP_OPTION_GET,
    STR_FTP_OPTION_BACK_TO_ROOT_DIR,
    STR_FTP_CON_EXIT,           /* Ask for exit FTP connection ? */
    STR_FTP_NOTY_RECV_FILE_BROWSE,
    STR_FTP_NOTY_RECV_FILE_TIL,
    STR_FTP_NOTY_RECV_FILE_TIL_SINGLE,
    STR_FTP_DETAIL_DATE,
    STR_FTP_DETAIL_SIZE,
    STR_FTP_NOTY_SHOW_PARTIAL_CONTENT_ONLY,
    STR_FTP_OPTION_ADD_TO_LIST,
    STR_FTP_OPTION_SHOW_LIST,
    STR_FTP_OPTION_GET_LIST,
    STR_FTP_OPTION_GET_ALL,
    STR_FTP_DOWNLOAD_LIST,
    STR_FTP_LIST_OPTION_UP,
    STR_FTP_LIST_OPTION_DOWN,
    STR_FTP_LIST_ARRIVE_MAX,
    STR_FTP_LIST_IS_EMPTY,
    STR_FTP_LIST_FIRST_FILE,
    STR_FTP_LIST_LAST_FILE,
    STR_FTP_LIST_FILE_DEL_CONFIRM,
    STR_FTP_LIST_ALL_FILE_DEL_CONFIRM,
    STR_FTP_NO_FILE_CURR_FOLDER,
    STR_FTP_GET_ALL_CONFIRM_HEAD,
    STR_FTP_GET_ALL_CONFIRM_TAIL,
    STR_FTP_NO_FILE_IN_LIST,
    STR_FTP_CLEAR_LIST,
    STR_FTP_FILE,
    STR_FTP_FILE_ALREADY_IN_LIST,
    STR_FTP_FILE1,
    STR_FTP_FILE_UNFINISHED,
    STR_FTP_FILE_PREFIX,
    STR_FTP_FILE_1ST,
    STR_FTP_FILE_2ND,
    STR_FTP_FILE_3RD,
    STR_FTP_FILE_TH,
    STR_FTPC_NOTIFY_BROWSE_FILES_FAILED,
    STR_FTPC_NOTIFY_GOEP_STATUS_BUSY,
    STR_FTPC_NOTIFY_WORK_FOLDER_NO_EXIST,
    STR_FTP_DEV_BUSY,
#endif /* __MMI_FTC_SUPPORT__ */ 
    /* General */
    STR_FTP_CON_DISCONNECTED,   /* FTP profile disconnected */
    STR_FTP_RECV_DISK_FULL,
    STR_FTP_WRITE_FILE_FAIL,

  
  
    STR_OBEX_INPUT_AUTHPWD,

    STR_EXTDEV_FTP_LAST
};

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

#ifdef __MMI_OPP_SUPPORT__

/**
  * OPP
  **/
enum STR_LIST_EXTDEV_OPP
{
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
    STR_EXTDEV_OPP_BEGIN = STR_EXTDEV_FTP_LAST,
#else 
    STR_EXTDEV_OPP_BEGIN = STR_EXTDEV_BT_LAST,
#endif 

    STR_OPP_NO_CARD_ERROR,
    STR_OPP_FILE_RECEIVED,

    STR_OPP_RECV_DISK_FULL,
    STR_OPP_RECV_ROOT_DIR_FULL,
    STR_OPP_WRITE_FILE_FAIL,
    STR_OPP_RECV_FILE_IND,
    STR_OPP_NOTY_RECV_FILE_BROWSE,
    STR_OPP_NOTY_RECV_FILE_HED,
    STR_OPP_NOTY_RECV_FILE_TIL,
    STR_OPP_NOTY_RECV_ACCEPT,
    STR_OPP_DEV_BUSY,
    STR_OPP_SEND,
    STR_OPP_CON_DISCONNECTED,
    STR_OPP_UNKNOWN_FILE_TYPE,
    STR_OPP_NOTY_RECV_FOLDER,
    STR_OPP_RECV_FILE_FOLDER,
    STR_OPP_NOTY_RECV_MULTI_FILE_TIL,
    STR_OPP_NOTY_CON_BUSY,
    STR_OPP_NOTY_DISCONNECTING,
    STR_EXTDEV_OPP_LAST
};

#endif /* __MMI_OPP_SUPPORT__ */ 

#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OPP_SUPPORT__
/* under construction !*/
#else
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/* under construction !*/
#else 
/* under construction !*/
#endif 
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__))) */
/***************************************************************************** 
* Image Define
*****************************************************************************/
/**
  * USB Device
  **/
enum IMG_LIST_EXTDEV_USB
{
    IMG_EXTDEV_USB_BEGIN = EXT_DEVICE_BASE + 1,

    IMG_USB_POWER_ON,
    IMG_SUB_USB_POWER_ON,
    IMG_USB_CHGR_CMPLT,
    IMG_USB_SUB_CHGR_CMPLT,

    IMG_ID_USB_MODE_PROGRESS,

    IMG_ID_WEBCAM_BG,
    IMG_ID_WEBCAM_PAUSE_JPEG_0,
    IMG_ID_WEBCAM_PAUSE_JPEG_1,
    IMG_ID_WEBCAM_PAUSE_JPEG_2,
    IMG_ID_WEBCAM_PAUSE_JPEG_3,
    IMG_ID_WEBCAM_SUB_BG,

    IMG_ID_USB_CHARGING,

    IMG_EXTDEV_USB_LAST
};

/**
  * IrDA Device
  **/
enum IMG_LIST_EXTDEV_IRDA
{
    IMG_EXTDEV_IRDA_BEGIN = IMG_EXTDEV_USB_LAST,

    IMG_IRDA_MENU_TITLE,

    /* Priyesh - Memory Card Support */
    IMG_IRDA_MENU_ACTIVATION,
    IMG_IRDA_MENU_STORAGE,
    IMG_IRDA_STORAGE_PHONE,
    IMG_IRDA_STORAGE_CARD,
    /* Priyesh - Memory Card Support */

    IMG_IRDA_MENU_OPEN,
    IMG_IRDA_MENU_CLOSE,
    IMG_IRDA_MENU_PERIOD,

    IMG_EXTDEV_IRDA_LAST
};

/**
  * Bluetooth Device
  **/

enum IMG_LIST_EXTDEV_BT
{
    IMG_EXTDEV_BT_BEGIN = IMG_EXTDEV_IRDA_LAST,

    /* for Handphone solution only */
    IMG_BT_DISCON,
    IMG_GLOBAL_DISC,
    IMG_BT_SWITCH,
    IMG_BT_SHHF,
    IMG_BT_SET_PATH,
    IMG_BT_SET_PATH_PHONE,
    IMG_BT_SET_PATH_HF,

    /* common image id */
    IMG_BT_MENU_TITLE,
    IMG_BT_SCH_TITLE,

    IMG_BT_POWER,
    IMG_BT_SCH_AUD_DEV,
    IMG_BT_REMOTE_CONTROL,
    IMG_BT_MYDEV,
    IMG_BT_ACT_DEV,
    IMG_BT_SET,
    IMG_BT_SET_VIS,
    IMG_BT_SET_NAME,
    IMG_BT_SET_AUTH,
    IMG_BT_SET_AUDIO_PATH,
    IMG_BT_SET_AUDIO_PATH_PHONE,
    IMG_BT_SET_AUDIO_PATH_HF,
    IMG_BT_SET_FTS,
    IMG_BT_SET_SIMAP,    
    IMG_BT_ABOUT,

    IMG_BT_DEV_MOB,
    IMG_BT_DEV_LAP,
    IMG_BT_DEV_EAR,
    IMG_BT_DEV_PRT,
    IMG_BT_DEV_OTHER,
    IMG_BT_CM_SETPATH,
	/* Configure Default Headset */
    IMG_BT_CONNECT_LAST_HEADSET,


    IMG_BPP_LAYOUT_L_S1_C1,
    IMG_BPP_LAYOUT_L_S1_C2,
    IMG_BPP_LAYOUT_L_S1_C4,
    IMG_BPP_LAYOUT_L_S2_C1,
    IMG_BPP_LAYOUT_L_S2_C2,
    IMG_BPP_LAYOUT_L_S2_C4,
    IMG_BPP_LAYOUT_P_S1_C1,
    IMG_BPP_LAYOUT_P_S1_C2,
    IMG_BPP_LAYOUT_P_S1_C4,
    IMG_BPP_LAYOUT_P_S2_C1,
    IMG_BPP_LAYOUT_P_S2_C2,
    IMG_BPP_LAYOUT_P_S2_C4,
    IMG_BPP_DEFAULT_LOGO,

    IMG_BIP_DEFAULT_THM,


    HID_IMG_BG,
    DESKTOP_IMG_01_DISALBE,
    DESKTOP_IMG_01_OFF,
    DESKTOP_IMG_01_ON,
    DESKTOP_IMG_01_DOWN,
    DESKTOP_IMG_02_DISALBE,
    DESKTOP_IMG_02_OFF,
    DESKTOP_IMG_02_ON,
    DESKTOP_IMG_02_DOWN,
    DESKTOP_IMG_03_DISALBE,
    DESKTOP_IMG_03_OFF,
    DESKTOP_IMG_03_ON,
    DESKTOP_IMG_03_DOWN,
    DESKTOP_IMG_04_DISALBE,
    DESKTOP_IMG_04_OFF,
    DESKTOP_IMG_04_ON,
    DESKTOP_IMG_04_DOWN,
    DESKTOP_IMG_05_DISALBE,
    DESKTOP_IMG_05_OFF,
    DESKTOP_IMG_05_ON,
    DESKTOP_IMG_05_DOWN,
    DESKTOP_IMG_06_DISALBE,
    DESKTOP_IMG_06_OFF,
    DESKTOP_IMG_06_ON,
    DESKTOP_IMG_06_DOWN,
    DESKTOP_IMG_07_DISALBE,
    DESKTOP_IMG_07_OFF,
    DESKTOP_IMG_07_ON,
    DESKTOP_IMG_07_DOWN,
    DESKTOP_IMG_08_DISALBE,
    DESKTOP_IMG_08_OFF,
    DESKTOP_IMG_08_ON,
    DESKTOP_IMG_08_DOWN,
    DESKTOP_IMG_09_DISALBE,
    DESKTOP_IMG_09_OFF,
    DESKTOP_IMG_09_ON,
    DESKTOP_IMG_09_DOWN,
    DESKTOP_IMG_10_DISALBE,
    DESKTOP_IMG_10_OFF,
    DESKTOP_IMG_10_ON,
    DESKTOP_IMG_10_DOWN,
    DESKTOP_IMG_11_DISALBE,
    DESKTOP_IMG_11_OFF,
    DESKTOP_IMG_11_ON,
    DESKTOP_IMG_11_DOWN,
    DESKTOP_IMG_12_DISALBE,
    DESKTOP_IMG_12_OFF,
    DESKTOP_IMG_12_ON,
    DESKTOP_IMG_12_DOWN,
    
    MOUSE_IMG_UP_DISALBE,
    MOUSE_IMG_UP_OFF,
    MOUSE_IMG_UP_ON,
    MOUSE_IMG_UP_DOWN,
    MOUSE_IMG_DOWN_DISALBE,
    MOUSE_IMG_DOWN_OFF,
    MOUSE_IMG_DOWN_ON,
    MOUSE_IMG_DOWN_DOWN,
    MOUSE_IMG_LEFT_DISALBE,
    MOUSE_IMG_LEFT_OFF,
    MOUSE_IMG_LEFT_ON,
    MOUSE_IMG_LEFT_DOWN,
    MOUSE_IMG_RIGHT_DISALBE,
    MOUSE_IMG_RIGHT_OFF,
    MOUSE_IMG_RIGHT_ON,
    MOUSE_IMG_RIGHT_DOWN,
    MOUSE_IMG_COMMON,
    
    MEDIA_PLAYER_IMG_01_DISALBE,
    MEDIA_PLAYER_IMG_01_OFF, 
    MEDIA_PLAYER_IMG_01_ON, 
    MEDIA_PLAYER_IMG_01_DOWN, 
    MEDIA_PLAYER_IMG_02_DISALBE,
    MEDIA_PLAYER_IMG_02_OFF,
    MEDIA_PLAYER_IMG_02_ON, 
    MEDIA_PLAYER_IMG_02_DOWN, 
    MEDIA_PLAYER_IMG_03_DISALBE,
    MEDIA_PLAYER_IMG_03_OFF, 
    MEDIA_PLAYER_IMG_03_ON,
    MEDIA_PLAYER_IMG_03_DOWN, 
    MEDIA_PLAYER_IMG_04_DISALBE,
    MEDIA_PLAYER_IMG_04_OFF,
    MEDIA_PLAYER_IMG_04_ON, 
    MEDIA_PLAYER_IMG_04_DOWN, 
    MEDIA_PLAYER_IMG_05_DISALBE,
    MEDIA_PLAYER_IMG_05_OFF, 
    MEDIA_PLAYER_IMG_05_ON, 
    MEDIA_PLAYER_IMG_05_DOWN, 
    MEDIA_PLAYER_IMG_06_DISALBE,
    MEDIA_PLAYER_IMG_06_OFF, 
    MEDIA_PLAYER_IMG_06_ON, 
    MEDIA_PLAYER_IMG_06_DOWN, 
    MEDIA_PLAYER_IMG_07_DISALBE,
    MEDIA_PLAYER_IMG_07_OFF, 
    MEDIA_PLAYER_IMG_07_ON, 
    MEDIA_PLAYER_IMG_07_DOWN, 
    MEDIA_PLAYER_IMG_08_DISALBE,
    MEDIA_PLAYER_IMG_08_OFF, 
    MEDIA_PLAYER_IMG_08_ON, 
    MEDIA_PLAYER_IMG_08_DOWN, 
    MEDIA_PLAYER_IMG_09_DISALBE,
    MEDIA_PLAYER_IMG_09_OFF, 
    MEDIA_PLAYER_IMG_09_ON, 
    MEDIA_PLAYER_IMG_09_DOWN, 
    MEDIA_PLAYER_IMG_10_DISALBE,
    MEDIA_PLAYER_IMG_10_OFF, 
    MEDIA_PLAYER_IMG_10_ON, 
    MEDIA_PLAYER_IMG_10_DOWN, 
    MEDIA_PLAYER_IMG_11_DISALBE,
    MEDIA_PLAYER_IMG_11_OFF, 
    MEDIA_PLAYER_IMG_11_ON, 
    MEDIA_PLAYER_IMG_11_DOWN, 
    MEDIA_PLAYER_IMG_12_DISALBE,
    MEDIA_PLAYER_IMG_12_OFF,
    MEDIA_PLAYER_IMG_12_ON, 
    MEDIA_PLAYER_IMG_12_DOWN, 
    
    PRESENTER_IMG_01_DISALBE,            
    PRESENTER_IMG_01_OFF,               
    PRESENTER_IMG_01_ON,                    
    PRESENTER_IMG_01_DOWN,                     
    PRESENTER_IMG_02_DISALBE,                    
    PRESENTER_IMG_02_OFF,                  
    PRESENTER_IMG_02_ON,                     
    PRESENTER_IMG_02_DOWN,                     
    PRESENTER_IMG_03_DISALBE,                    
    PRESENTER_IMG_03_OFF,                    
    PRESENTER_IMG_03_ON,                      
    PRESENTER_IMG_03_DOWN,                    
    PRESENTER_IMG_04_DISALBE,                     
    PRESENTER_IMG_04_OFF,                    
    PRESENTER_IMG_04_ON,                     
    PRESENTER_IMG_04_DOWN,                      
    PRESENTER_IMG_05_DISALBE,                     
    PRESENTER_IMG_05_OFF,                    
    PRESENTER_IMG_05_ON,                    
    PRESENTER_IMG_05_DOWN,                    
    PRESENTER_IMG_06_DISALBE,                     
    PRESENTER_IMG_06_OFF,                    
    PRESENTER_IMG_06_ON,                      
    PRESENTER_IMG_06_DOWN,                     
    PRESENTER_IMG_07_DISALBE,                     
    PRESENTER_IMG_07_OFF,                   
    PRESENTER_IMG_07_ON,                      
    PRESENTER_IMG_07_DOWN,                     
    PRESENTER_IMG_08_DISALBE,                   
    PRESENTER_IMG_08_OFF,                     
    PRESENTER_IMG_08_ON,                      
    PRESENTER_IMG_08_DOWN,                      
    PRESENTER_IMG_09_DISALBE,                     
    PRESENTER_IMG_09_OFF,                  
    PRESENTER_IMG_09_ON,                      
    PRESENTER_IMG_09_DOWN,                      
    PRESENTER_IMG_10_DISALBE,                     
    PRESENTER_IMG_10_OFF,                     
    PRESENTER_IMG_10_ON,                   
    PRESENTER_IMG_10_DOWN,                      
    PRESENTER_IMG_11_DISALBE,                   
    PRESENTER_IMG_11_OFF,                   
    PRESENTER_IMG_11_ON,                      
    PRESENTER_IMG_11_DOWN,                     
    PRESENTER_IMG_12_DISALBE,                     
    PRESENTER_IMG_12_OFF,                    
    PRESENTER_IMG_12_ON,                    
    PRESENTER_IMG_12_DOWN,                    
                                                           
    PRESENTER_MOUSE_IMG_UP_DISALBE,                      
    PRESENTER_MOUSE_IMG_UP_OFF,                     
    PRESENTER_MOUSE_IMG_UP_ON,                
    PRESENTER_MOUSE_IMG_UP_DOWN,                    
    PRESENTER_MOUSE_IMG_DOWN_DISALBE,                      
    PRESENTER_MOUSE_IMG_DOWN_OFF,                   
    PRESENTER_MOUSE_IMG_DOWN_ON,                   
    PRESENTER_MOUSE_IMG_DOWN_DOWN,                     
    PRESENTER_MOUSE_IMG_LEFT_DISALBE,                      
    PRESENTER_MOUSE_IMG_LEFT_OFF,                     
    PRESENTER_MOUSE_IMG_LEFT_ON,                     
    PRESENTER_MOUSE_IMG_LEFT_DOWN,                     
    PRESENTER_MOUSE_IMG_RIGHT_DISALBE,                     
    PRESENTER_MOUSE_IMG_RIGHT_OFF,                     
    PRESENTER_MOUSE_IMG_RIGHT_ON,                    
    PRESENTER_MOUSE_IMG_RIGHT_DOWN,                    
    HID_IMG_TOTAL,
    

    IMG_EXTDEV_BT_LAST
};

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)

/**
  * Bluetooth FTP Device
  **/
enum IMG_LIST_EXTDEV_FTP
{
    IMG_EXTDEV_FTP_BEGIN = IMG_EXTDEV_BT_LAST,

    IMG_FTP_SETTING_TITLE,
    IMG_FTP_SHARED_FOLDER,
    IMG_FTP_ACCESS_RIGHT,
    IMG_FTP_FILE_BROWSER,
    IMG_EXTDEV_FTP_LAST
};

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

#ifdef __MMI_OPP_SUPPORT__

/**
  * Bluetooth OPP Device
  **/
enum IMG_LIST_EXTDEV_OPP
{
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
    IMG_EXTDEV_OPP_BEGIN = IMG_EXTDEV_FTP_LAST,
#else 
    IMG_EXTDEV_OPP_BEGIN = IMG_EXTDEV_BT_LAST,
#endif 
    IMG_OPP_MENU_TITLE,
    IMG_OPP_MY_DEVICE,
    IMG_OPP_SEARCH_DEVICE,

    IMG_EXTDEV_OPP_LAST
};

#endif /* __MMI_OPP_SUPPORT__ */ 

#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OPP_SUPPORT__
/* under construction !*/
#else
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/* under construction !*/
#else 
/* under construction !*/
#endif 
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))*/
/***************************************************************************** 
* Screen Define
****************************************************************************/
/**
  * USB Device
  **/
enum SCR_EXTDEVICE_LIST
{
    SCR_EXTDEV_USB_BEGIN = EXT_DEVICE_BASE + 1,

    SCR_DEV_USBDETECT,
    SCR_USB_POWER_ON,
    SCR_USB_CHGR_CMPLT,
    SCR_USB_POWER_ON_DONE,
    SCR_ID_USB_WEBCAM,

    SCR_ID_USB_PROGRESS,

    SCR_EXTDEV_USB_LAST
};

/**
  * IrDA Device
  **/
enum SCR_EXTDEVICE_IRDA_LIST
{
    SCR_EXTDEV_IRDA_BEGIN = SCR_EXTDEV_USB_LAST,

    SCR_DEV_IRDA_SETTING,

    /* Priyesh - Memory Card Support */
    SCR_DEV_IRDA_ACTIVATION,
    SCR_DEV_IRDA_STORAGE,
    /* Priyesh - Memory Card Support */

    SCR_DEV_IRDA_NOTY_FILE_RECV,
    SCR_DEV_IRDA_SEND,  /* PMT PANKAJ */
    SCR_DEV_IRDA_NOTY_THM_FILE_RECV,
    SCR_EXTDEV_IRDA_LAST
};

/**
  * Bluetooth Device
  **/

enum SCR_EXTDEVICE_BT_LIST
{
    SCR_EXTDEV_BT_BEGIN = SCR_EXTDEV_IRDA_LAST,

    /* common screen id */
    SCR_BT_MAIN,
	SCR_BT_POWER_ON_CNF,
    SCR_BT_RELEASE_DEV_CONN_CNF,
    SCR_BT_RELEASE_ALL_CONN_CNF,    
    SCR_BT_POWER_PRO,
    SCR_BT_REL_ALL_CONN_PRO,
    SCR_BT_REL_DEV_CONN_PRO,

    SCR_BT_SCH_PRO,
    SCR_BT_SCH_RES,
    SCR_BT_SCH_CANCEL_PRO,
    SCR_BT_BOND,
    SCR_BT_REFREAH_PROFILE,
    SCR_BT_PIN_INPUT,
    SCR_BT_PAIR_PRO,
    SCR_BT_CONNECT_CNF,
    SCR_BT_CONNECTING,
    SCR_BT_CONNECT_AUTHORIZE,
    SCR_BT_CONNECT_ACCEPT_CNF,

    SCR_BT_REMOTE_CONTROL,
    SCR_BT_REMOTE_CONTROL_DEV_SELECT,
    SCR_BT_REMOTE_CONTROL_DESKTOP,    
    SCR_BT_REMOTE_CONTROL_MEDIA_PLAYER,    
    SCR_BT_REMOTE_CONTROL_PRESENTER,    
    SCR_BT_REMOTE_CONTROL_KEYBOARD,    
    SCR_BT_REMOTE_CONTROL_DISCONNECT_CONFIRM,
    SCR_BT_REMOTE_CONTROL_POWER_ON_CONFIRM,
    SCR_BT_REMOTE_CONTROL_CONN_REQ,
    
    SCR_BT_MYDEV,
    SCR_BT_MYDEV_OPT,
    SCR_BT_MYDEV_PROF_CHO,
    SCR_BT_MYDEV_CON,
    SCR_BT_MYDEV_CONNECTED_PROF,
    SCR_BT_MYDEV_DISCON,
    SCR_BT_MYDEV_REN,
    SCR_BT_MYDEV_REN_OPT,
    SCR_BT_MYDEV_AUTH,
    SCR_BT_MYDEV_DEL,
    SCR_BT_MYDEV_DEL_ALL,
    SCR_BT_MYDEV_SUP_PROFILE,
    SCR_BT_MYDEV_SCH,

    SCR_BT_ACT_DEV,
    SCR_BT_DISC_PROC,

    SCR_BT_SET,
    SCR_BT_SET_NAME,
    SCR_BT_SET_NAME_OPT,
    SCR_BT_SET_VIS,
    SCR_BT_SET_AUTH,
    SCR_BT_SET_AUDIO_PATH,
    SCR_BT_SET_FTP,
    SCR_BT_SET_SIMAP,
    SCR_BT_ABOUT,
    SCR_BT_MY_SPECIFIC_DEV,
    SCR_BT_MY_SPECIFIC_DEV_DUMMY,

    SCR_BT_SWITCH_SPEECH_PATH,
    /* Configure Default Headset */
    SCR_BT_CONNECT_LAST_HEADSET,
	SCR_BT_NOT_ALLOWED,
	SCR_BT_NOT_PROHIBIT_BY_SIMAP,


    SCR_OPP_NOTY_FILE_RECV,
    SCR_OPP_NOTY_RECV_ACCEPT,
    SCR_OPP_SENDING,
    SCR_OPP_ABORTING,
    SCR_OPP_DISCONNECTING,

    SCR_FTP_SETTING,
    SCR_FTP_ACCESS_RIGHT_OPTION,
    SCR_FTP_SELECT_SHARED_FOLDER,
    SCR_FTP_NOTY_CONN_REQ,
    SCR_FTP_FILE_BROWSER,
    SCR_FTP_FOLDER_OPTION,
    SCR_FTP_FILE_OPTION,
    SCR_FTP_NOTY_FILE_RECV,
    SCR_FTP_RECEIVING,
    SCR_FTP_DISCONNECTING,
    SCR_FTP_ABORTING,
    SCR_FTP_DETAIL_INFO,
    SCR_FTP_DOWNLOAD_LIST,
    SCR_FTP_LIST_OPTION,
    SCR_FTP_CONNECTING,
    SCR_FTP_OPENING_FOLDER,    
    SCR_FTP_CONNECT_CANCELING,
    SCR_ID_BT_AVCRP_CT_MAIN,
    SCR_BPP_DUMMY,
    SCR_BPP_CONNECTING,
    SCR_BPP_AUTHENTICATING,
    SCR_BPP_GETTING,
    SCR_BPP_PRINT_SETTING,
    SCR_BPP_LAYOUT_PREVIEW,    
    SCR_BPP_CREATING,    
    SCR_BPP_COMPOSING,    
    SCR_BPP_PRINTING,    
    SCR_BPP_TROUBLE,    
    SCR_BPP_DISCONNECTING,    
    SCR_OBEX_INPUT_AUTHPWD,

    SCR_BIP_SETTING,
    SCR_BIP_SENDING,
    SCR_BIP_CONNECTING,
    SCR_BIP_ABORTING,
    SCR_BIP_RECEIVING,
    SCR_BIP_DISCONNECTING,
    SCR_BIP_IMGLIST_BROWSER,
    SCR_BIP_IMG_DETAIL,
    SCR_BIP_IMGLIST_OPTION,
    SCR_BIP_GETTING_IMGPROP,
    SCR_BIP_NOTY_CONN_REQ,
    SCR_BIP_NOTY_FILE_RECV,

    SCR_EXTDEV_BT_LAST
};


#if (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (defined(__MMI_OP01_MENU_9MATRIX__) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__))) */


#endif /* __CONNECTIVITY_RES_DEF_H__ */
