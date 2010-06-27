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
 * PhoneBookTypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   phone book application 
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
 *==============================================================================
 *******************************************************************************/
#ifndef _PHONEBOOKTYPES_H
#define _PHONEBOOKTYPES_H

#include "MMIDataType.h"
#include "audioinc.h"
#include "SettingProfile.h"
/* NVRAM_REVISE */
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "custom_equipment.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_Master_ADN.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_UCM__
#include "FileMgr.h"
#endif

/* The enum decide the order of usim phonebook fields */
typedef enum
{
    MMI_PHB_USIM_FIELD_ANRA,
    MMI_PHB_USIM_FIELD_EMAIL,
    MMI_PHB_USIM_FIELD_ANRB,
    MMI_PHB_USIM_FIELD_ANRC,
    MMI_PHB_USIM_FIELD_GROUP,
    MMI_PHB_USIM_FIELD_SNE,
    MMI_PHB_USIM_FIELD_TOTAL
} MMI_PHB_USIM_FIELD_ORDER_ENUM;

#ifdef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
typedef enum
{
    MMI_PHB_MOBILE_NUMBER,
    MMI_PHB_HOME_NUMBER,
    MMI_PHB_OFFICE_NUMBER,
    MMI_PHB_FAX_NUMBER,
    MMI_PHB_MAX_NUMBER_COUNT
} MMI_PHB_NUMBERS;
#endif /* __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__ */ 

/* 
 * Define
 */
#if defined(__MMI_PHB_MAX_NAME_60__)
#define MAX_PS_NAME_LENGTH    62
#else 
#define MAX_PS_NAME_LENGTH    32
#endif 

#define MAX_ENTRIES_IN_LIST      15

#define MAX_PB_SIM_ENTRIES       MAX_PHB_SIM_ENTRY      /* value defined in option.mak */
#define MAX_PB_PHONE_ENTRIES     MAX_PHB_PHONE_ENTRY    /* value defined in option.mak */
#ifdef __MMI_DUAL_SIM_MASTER__
#define MAX_PB_SIM2_ENTRIES	MAX_PHB_SIM_ENTRY
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_MASTER__
#define MAX_PB_ENTRIES		(MAX_PB_SIM_ENTRIES + MAX_PB_PHONE_ENTRIES + MAX_PB_SIM2_ENTRIES)	/*Maximum number of entries in Phonebook*/
#else   /* __MMI_DUAL_SIM_MASTER__ */
#define MAX_PB_ENTRIES           (MAX_PB_SIM_ENTRIES + MAX_PB_PHONE_ENTRIES)    /* Maximum number of entries in Phonebook */
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_VOIP__
#define MAX_PB_FIELDS            (MMI_PHB_FIELD_TOTAL + MMI_PHB_EXTRA_FIELD_TOTAL + 1) /* 1 for VOIP */
#else
#define MAX_PB_FIELDS            (MMI_PHB_FIELD_TOTAL + MMI_PHB_EXTRA_FIELD_TOTAL)
#endif

#if defined(__MMI_INCOMING_CALL_VIDEO__)
#define MAX_PB_VIDEO_TAGS     30        /* Max Video tags allowed */
#define MAX_CALLER_GRP_ITEMS  7
#else /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
#define MAX_CALLER_GRP_ITEMS  6
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
#define MAX_PB_PICTURES_TAGS  30        /* Max Pictures tags allowed */
#define MAX_PB_OWNER_NUMBERS   4

#define MAX_SEARCH_NAME_LENGTH   10

#ifdef __MMI_PHB_USIM_FIELD__
#define MAX_PB_USIM_GROUPS  5
#else
#define MAX_PB_USIM_GROUPS  0
#endif

#define CALLER_GROUPS_RECORD_SIZE   260
#define OPTIONAL_IDS_RECORD_TOTAL 85
#define OPTIONAL_IDS_RECORD_SIZE 510    /* Store 85 entries in one NVRAM record, so total is 85 x 6 (6 bytes each) */
#define OPTIONAL_FIELDS_RECORD_SIZE 229
#define MMI_PHB_VCARD_RECORD_SIZE   338

#define MMI_PHB_INFO_RECORD_SIZE 335

#define INVALID_NUMBER        1000000000
#define ALPHA_LIST_LENGTH         26
#define MAX_PB_RING_TONES         60
#if !defined(HARDWARE_LED_NOT_SUPPORT)
#define MAX_PB_ALERT_TYPES         5
#else 
#define MAX_PB_ALERT_TYPES         4
#endif 
#define MAX_PB_LED_PATTERNS           6
#define  PHB_NOTIFY_TIMEOUT         UI_POPUP_NOTIFYDURATION_TIME

/* For FDl & BDL */
#define MAX_SIM_ENTRIES       20
#define MAX_NAME_LEN_FSB_LIST MAX_PB_NAME_LENGTH
#define MAX_NUMBER_LEN_FSB_LIST  MAX_PB_NUMBER_LENGTH

#define MAX_SIM_SOS_ENTRIES          5
#define MAX_NVRAM_SOS_ENTRIES     5
#define NVRAM_SOS_RECORD_SIZE    86

/* For File System and File Manager */
#define MMI_PHB_MAX_PATH_LENGTH        64*ENCODING_LENGTH       /* Not max length support by file manager, use carefully */
#define MMI_PHB_DRV                       MMI_PUBLIC_DRV
#define MMI_PHB_IMAGE_FOLDER           FMGR_DEFAULT_FOLDER_PHBIMAGES
#define MMI_PHB_VIDEO_DATA_FILE        FMGR_DEFAULT_FILE_PHBVIDEO

/* For field filter */
#define  MMI_PHB_ENTRY_FIELD_NAME      0x01
#define  MMI_PHB_ENTRY_FIELD_NUMBER    0x02 /* use MMI_PHB_ENTRY_FIELD_ALL_NUMBER for 4 type numbers */
#define  MMI_PHB_ENTRY_FIELD_HOME      0x04
#define  MMI_PHB_ENTRY_FIELD_OFFICE    0x08
#define  MMI_PHB_ENTRY_FIELD_FAX       0x10

#define MMI_PHB_ENTRY_FIELD_ALL_NUMBER 0x1E 

#define  MMI_PHB_ENTRY_FIELD_EMAIL     0x20     /* for nvram and USIM */
#define  MMI_PHB_ENTRY_FIELD_COMPANY   0x40

#define  MMI_PHB_ENTRY_FIELD_ANRA      0x04     /* for USIM, same as home number */
#define  MMI_PHB_ENTRY_FIELD_ANRB      0x08     /* for USIM, same as office number */
#define  MMI_PHB_ENTRY_FIELD_ANRC      0x10     /* for USIM, same as fax */
#ifndef __MMI_DUAL_SIM_MASTER__
#if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
#if defined(__MMI_PHB_USIM_FIELD__)
#define MAX_LOOKUP_TABLE_COUNT (3*MAX_PB_SIM_ENTRIES+MAX_PB_PHONE_ENTRIES+1)
#else 
#define MAX_LOOKUP_TABLE_COUNT (MAX_PB_SIM_ENTRIES+MAX_PB_PHONE_ENTRIES+1)
#endif 
#else /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
#if defined(__MMI_PHB_USIM_FIELD__)
#define MAX_LOOKUP_TABLE_COUNT (3*MAX_PB_SIM_ENTRIES+4*MAX_PB_PHONE_ENTRIES+1)
#else 
#define MAX_LOOKUP_TABLE_COUNT (MAX_PB_SIM_ENTRIES+4*MAX_PB_PHONE_ENTRIES+1)
#endif 
#endif /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
#else /* __MMI_DUAL_SIM_MASTER__ */
#if defined(__MMI_PHB_NO_OPTIONAL_FIELD__)
#if defined(__MMI_PHB_USIM_FIELD__)
#define MAX_LOOKUP_TABLE_COUNT (3*MAX_PB_SIM_ENTRIES+MAX_PB_PHONE_ENTRIES+1+MAX_PB_SIM2_ENTRIES)
#else 
#define MAX_LOOKUP_TABLE_COUNT (MAX_PB_SIM_ENTRIES+MAX_PB_PHONE_ENTRIES+1+MAX_PB_SIM2_ENTRIES)
#endif 
#else /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
#if defined(__MMI_PHB_USIM_FIELD__)
#define MAX_LOOKUP_TABLE_COUNT (3*MAX_PB_SIM_ENTRIES+4*MAX_PB_PHONE_ENTRIES+1+MAX_PB_SIM2_ENTRIES)
#else 
#define MAX_LOOKUP_TABLE_COUNT (MAX_PB_SIM_ENTRIES+4*MAX_PB_PHONE_ENTRIES+1+MAX_PB_SIM2_ENTRIES)
#endif 
#endif /* defined(__MMI_PHB_NO_OPTIONAL_FIELD__) */ 
#endif /* __MMI_DUAL_SIM_MASTER__ */

/* Birthday Field */
#define MMI_PHB_BDAY_MIN_YEAR_INT   1900        /* Min Year */
#define MMI_PHB_BDAY_MAX_YEAR_INT   2030        /* Max Year */
#define MMI_PHB_BDAY_YEAR_STR L"0000"   /* Empty Birthday */
#define MMI_PHB_BDAY_MON_STR  L"00"
#define MMI_PHB_BDAY_DAY_STR  L"00"

/* 
 * Extern Global Function
 */
extern void playRequestedTone(ALL_TONE_ENUM);

/* 
 * Typedef 
 */
typedef enum
{
    MMI_PHB_LIST_FOR_NONE,
    MMI_PHB_LIST_FOR_PHB,
    MMI_PHB_LIST_FOR_FRM,
    MMI_PHB_LIST_FOR_SMS,
    MMI_PHB_LIST_FOR_SMS_SEARCH_NAME,
    MMI_PHB_LIST_FOR_CHAT,
    MMI_PHB_LIST_FOR_CHAT_NO_CHECK,
    MMI_PHB_LIST_FOR_SETTINGS,
    MMI_PHB_LIST_FOR_SPEED_DIAL,
    MMI_PHB_LIST_FOR_CM,
    MMI_PHB_LIST_FOR_MMS_ALL,           /* MMS */
    MMI_PHB_LIST_FOR_VIEW_MEMBER_LIST,  /* Caller Group Member List */
    MMI_PHB_LIST_FOR_ADD_MEMBER_LIST,   /* Caller Group Member List */
    MMI_PHB_LIST_FOR_SAVE_FROM_FILE_MGR,
    MMI_PHB_LIST_FOR_DELETE_ONE_BY_ONE,
    MMI_PHB_LIST_FOR_EMAIL_APP,
    MMI_PHB_LIST_FOR_VR,
    MMI_PHB_LIST_FOR_GET_ADDRESS_FROM_GROUP,
    MMI_PHB_LIST_FOR_ALL_SHARED,
    MMI_PHB_LIST_FOR_OTHER_APP
} MMI_PHB_LIST_VIEW;

typedef enum
{
    MMI_PHB_IMAGE_NO_SELECT,    /* No picture, use default. */
    MMI_PHB_IMAGE_FOR_ENTRY,    /* picture for phonebook entry.. */
    MMI_PHB_IMAGE_SELECT_PATH,  /* picture from select path for phb entry. */
    MMI_PHB_IMAGE_CALLER_GROUP,  /* picture for caller group. */
    MMI_PHB_SWFLASH_SELECT_PATH,
    MMI_PHB_AVATAR_SELECT_PATH,
    MMI_PHB_IMAGE_LOCATION_ENUM_TOTAL
} mmi_phb_image_location_enum;

typedef enum
{
    MMI_PHB_RECV_RES_IMAGE,
    MMI_PHB_RECV_RES_AUDIO,
    MMI_PHB_RECV_RES_VIDEO,
    MMI_PHB_RECV_RES_AVATAR_IMAGE,
    MMI_PHB_RECV_RES_AVATAR_VIDEO,
    MMI_PHB_RECV_RES_SWFLASH
} mmi_phb_receive_resource_enum;

#if defined(__MMI_PHB_MULTI_OPERATION__)
typedef enum
{
    MMI_PHB_MULTI_DELETE,
    MMI_PHB_MULTI_COPY
} mmi_phb_multi_operation_enum;
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */

#if defined(__MMI_UCM__)
typedef enum
{
    MMI_PHB_VOICE_CALL_TYPE = 0x01,
    MMI_PHB_DATA_CALL_TYPE  = 0x02,
    MMI_PHB_FAX_CALL_TYPE   = 0x04,
    MMI_PHB_VOIP_CALL_TYPE  = 0x08,
    MMI_PHB_VIDEO_CALL_TYPE = 0x10,
    MMI_PHB_CALL_TYPE_ENUM_END
} mmi_phb_call_type_enum;

typedef struct
{
    U16 new_image_id;
    U16 image_type;
    S8 image_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];
    MMI_BOOL is_video_sound;
}mmi_phb_caller_image_info_struct;

typedef struct
{
    U16 video_id;
    U16 video_record_index;
    U16 image_id;
    U16 record_index;
    U8 call_type;
}mmi_phb_caller_image_input_struct;
#endif /* defined(__MMI_UCM__) */

typedef struct
{
    U8 name[(MAX_PB_NAME_LENGTH + 1) *ENCODING_LENGTH];
    U8 number[(MAX_PB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];
    U8 name_dcs;
    U8 alertType;       /* MMI_ALERT_TYPE */
    U16 pictureId;
    U16 ringtoneId;
    U16 backlightId;
    U16 record_index;   /* For Query Image Path */
    U16 videoId;
    U16 video_record_index;
    U8 dialInList;
} PHB_CM_INTERFACE;


#ifdef __VOIP__
typedef struct
{
    U8 name[(MAX_PB_NAME_LENGTH + 1) *ENCODING_LENGTH];
    U8 uri[(VOIP_URI_LEN) *ENCODING_LENGTH];
    U8 name_dcs;
    U8 alertType;       /* MMI_ALERT_TYPE */
    U16 pictureId;
    U16 ringtoneId;
    U16 backlightId;
    U16 record_index;   /* For Query Image Path */
    U16 videoId;
    U16 video_record_index;
    U8 dialInList;
} PHB_VOIP_INTERFACE;
#endif /* __VOIP__ */


/* Optional field in a phonebook entry */
typedef struct
{
    U8 homeNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U8 companyName[(MAX_PB_COMPANY_LENGTH + 1) *ENCODING_LENGTH];
    U8 emailAddress[MAX_PB_EMAIL_LENGTH + 1];
    U8 officeNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U8 faxNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];
} PHB_OPTIONAL_FIELDS_STRUCT;

typedef struct
{
    U8 name_length; /* Name Length */
    U8 name_dcs;    /* Name Data Coding Scheme */
    U8 name[(MAX_PB_NAME_LENGTH + 1) *ENCODING_LENGTH];
} MMI_PHB_NAME_STRUCT;

typedef struct
{
    U8 type;    /* 129-default, 145-international */
    U8 length;
    U8 number[(MAX_PB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];        /* 1 for + Sign and 1 for Null Termination. */
} MMI_PHB_NUMBER_STRUCT;

typedef struct
{
    U8 storage; /* 0-none, 1-SIM, 2-ME */
    U8 type;
    U16 index;
    U16 record_index;
    MMI_PHB_NUMBER_STRUCT tel;
    MMI_PHB_NAME_STRUCT alpha_id;
} MMI_PHB_ENTRY_STRUCT;

/* Use BCD format to store number to save memory. */
typedef struct
{
    U8 type;                                    /* 129-default; 145-international, begin with '+' */
    U8 length;
    U8 number[(MAX_PB_NUMBER_LENGTH + 1) / 2];  /* half space to store BCD format. */
} MMI_PHB_NUMBER_BCD_STRUCT;

/* Use array index to decide storage and record_index. */
typedef struct
{
    //U8         storage;
    //U8         type;
    //U16                index;
    //U16                record_index;
    MMI_PHB_NUMBER_BCD_STRUCT tel;
    MMI_PHB_NAME_STRUCT alpha_id;
    U8 field;   /* Indicate if an entry has the field */
    U8 dummy;   /* Make sure each phb structure is two-bytes aligned. */
} MMI_PHB_ENTRY_BCD_STRUCT;

/* Owner number associate with Line ID */
typedef struct
{
    U8 name[(MAX_PB_NAME_LENGTH + 1) *ENCODING_LENGTH];
    U8 number[(MAX_PB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];
} MMI_OWNER_NUMBER_STRUCT;

typedef struct
{
    U16 store_index;    /* Store Index of Phonebook, Begin from 0 */
    U32 number;
} MMI_PHB_LOOKUP_NODE_STRUCT;

typedef struct
{
    U8 type;    /* 129-default, 145-international */
    U8 length;
    U8 number[(MAX_PB_NUMBER_LENGTH + 1 + 1) *ENCODING_LENGTH];
} MMI_SOS_NUMBER_STRUCT;

typedef struct
{
    S8 name[(MAX_PB_NAME_LENGTH + 1) *ENCODING_LENGTH];
    S8 number[MAX_PB_NUMBER_LENGTH + 1 + 1];    /* 1 for + Sign and 1 for Null Termination. */
    S8 homeNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];
    S8 companyName[(MAX_PB_COMPANY_LENGTH + 1) *ENCODING_LENGTH];
    S8 emailAddress[MAX_PB_EMAIL_LENGTH + 1];
    S8 officeNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];
    S8 faxNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];
    U16 pictureTagID;
    U16 ringToneID;
} MMI_PHB_VCARD_STRUCT;

typedef struct
{
    U16 bYear;
    U8 bMonth;
    U8 bDay;
} MMI_PHB_BDAY_STRUCT;

//huzhuhua 080722 begin
#ifdef __PHONEBOOK_OUTPUT_INPUT__
typedef struct
{
	S8 Day[3 * ENCODING_LENGTH];
	S8 Mon[3 * ENCODING_LENGTH];
	S8 Year[6 * ENCODING_LENGTH];
} MMI_PHB_BDAY_STR_STRUCT;
#endif
//end

typedef struct
{
    U8 title[(MAX_PB_TITLE_LENGTH + 1) *ENCODING_LENGTH];
    U8 url[MAX_PB_URL_LENGTH + 1];
    U8 address[(MAX_PB_ADDRESS_LENGTH + 1) *ENCODING_LENGTH];
    U8 note[(MAX_PB_NOTE_LENGTH + 1) *ENCODING_LENGTH];
} PHB_INFO_FIELDS_STRUCT;

typedef struct
{
    U8 email_length;
    U8 email_address[MAX_PB_EMAIL_LENGTH + 1];
} MMI_PHB_EMAIL_STRUCT;

typedef enum
{
    MMI_PHB_BCD = 0x01,
    MMI_PHB_ASCII = 0x00,
    MMI_PHB_UCS2 = 0x08
#if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
        ,
    MMI_PHB_UCS2_81 = 0x09,
    MMI_PHB_UCS2_82 = 0x10
#endif /* defined(__PHB_0x81_SUPPORT__) */ 
} MMI_PHB_CHARSET_ENUM;

typedef enum
{
    MMI_STORAGE_NONE,
    MMI_SIM,
    MMI_NVRAM,
#ifdef __MMI_DUAL_SIM_MASTER__
    MMI_SIM2,
#endif /* __MMI_DUAL_SIM_MASTER__ */
    MMI_STORAGE_BOTH
} MMI_PHB_STORAGE_LOCATION;

typedef enum
{
    MMI_CSMCC_DEFAULT_ADDR_TYPE = 129,
    MMI_CSMCC_INTERNATIONAL_ADDR = 145
} MMI_CSMCC_ADDR_TYPE;

typedef enum
{
    MMI_PHB_NONE,
    MMI_PHB_ECC,
    MMI_PHB_FDN,
    MMI_PHB_BDN,
    MMI_PHB_MSISDN,
    MMI_PHB_SDN,
    MMI_PHB_PHONEBOOK,
    MMI_PHB_GAS,
    MMI_PHB_GRP,
    MMI_PHB_ANR,
    MMI_PHB_SNE,
    MMI_PHB_FROM_OTHER_APP
} MMI_PHB_TYPE;

typedef enum
{
    MMI_PHB_NO_CAUSE,
    MMI_PHB_CAUSE_STORAGE_FULL,
    MMI_PHB_CAUSE_CAPACITY_EXCEEDED
} MMI_PHB_CAUSE_ENUM;

typedef enum
{
    MMI_PHB_UPDATE,
    MMI_PHB_DELETE,
    MMI_PHB_DELETE_ALL,
    MMI_WRITE_LND,
    MMI_WRITE_LNM,
    MMI_WRITE_LNR,
    MMI_DELETE_LND,
    MMI_DELETE_LNM,
    MMI_DELETE_LNR
} MMI_PHB_UPDATE_ENUM; /* For AT */


typedef enum
{
    MMI_PHB_VCARD_READ,
    MMI_PHB_VCARD_ADD,
    MMI_PHB_VCARD_UPDATE,
    MMI_PHB_VCARD_DELETE
} mmi_phb_sync_vcard_enum; /* For SyncML */

typedef enum
{
    MMI_PHB_SYNC_SUCCESS,
    MMI_PHB_SYNC_ERROR,
    MMI_PHB_SYNC_NOT_READY,
    MMI_PHB_SYNC_OPEN_FILE_ERROR,
    MMI_PHB_SYNC_NOT_SUPPORT,
    MMI_PHB_SYNC_NOT_FOUND,
    MMI_PHB_SYNC_STORAGE_FULL,
    MMI_PHB_SYNC_OUT_OF_INDEX
} mmi_phb_sync_error_enum; /* For SyncML */


typedef enum
{
    MMI_PHB_OTHERS_SUCCESS,
    MMI_PHB_OTHERS_ERROR,
    MMI_PHB_OTHERS_ENUM_TOTAL
} mmi_phb_add_from_others_error_enum; /* For OtherApp */


typedef enum
{
    MMI_PHB_ENTER_NONE,
    MMI_PHB_ENTER_FROM_IDLE_SCREEN,
    MMI_PHB_ENTER_FROM_CALL_LOG,
    MMI_PHB_ENTER_FROM_CALL_MGNT,
    MMI_PHB_ENTER_FROM_SMS,
#if defined (__MMI_VOIP__)
    MMI_PHB_ENTER_FROM_VOIP,
#endif
    MMI_PHB_ENTER_FROM_JAVA,
    MMI_PHB_ENTER_FROM_SYNCML,
    MMI_PHB_ENTER_FROM_WAP,
    MMI_PHB_ENTER_FROM_OTHERS
} MMI_PHB_ENTER_LOCATION_ENUM;


typedef enum
{
    MMI_PHB_QUICK_SEARCH_MAIN,
    MMI_PHB_QUICK_SEARCH_GENERIC,
    MMI_PHB_QUICK_SEARCH_ENUM_TOTAL
} MMI_PHB_QUICK_SEARCH_ENUM;

/* See if the phonebook list screen data need reload. */
typedef enum
{
    MMI_PHB_ENTRY_NO_CHANGE,
    MMI_PHB_ENTRY_REFRESH,
    MMI_PHB_ENTRY_QSEARCH
} MMI_PHB_ENTRY_UPDATE_ENUM;

typedef enum
{
    MMI_PHB_SORT_STORAGE,
    MMI_PHB_SORT_ENCODING,
    MMI_PHB_SORT_PINYIN
} MMI_PHB_SORT_METHOD_ENUM;

typedef enum
{
    MMI_PHB_OP_NONE,
    MMI_PHB_OP_ADD,
    MMI_PHB_OP_EDIT
} MMI_PHB_OP_ENUM;



/* __MMI_PHB_USIM_FIELD__ */
typedef enum
{
    MMI_PHB_USIM_NOT_READY,
    MMI_PHB_USIM_READY_PHASE1,
    MMI_PHB_USIM_READY_ANR,
    MMI_PHB_USIM_READY_EMAIL,
    MMI_PHB_USIM_READY_GAS,
    MMI_PHB_USIM_READY_GRP,
    MMI_PHB_USIM_READY_SNE,
    MMI_PHB_USIM_READY
} MMI_PHB_USIM_READY_STAGE_ENUM;

typedef enum
{
    MMI_PHB_USIM_ANR_FULL = 8,
    MMI_PHB_USIM_EMAIL_FULL,
    MMI_PHB_USIM_SNE_FULL
} MMI_PHB_USIM_WRITE_ERROR_ENUM;


typedef enum
{
    MMI_PHB_VCARD_VERSION_21,
    MMI_PHB_VCARD_VERSION_30
} MMI_PHB_VCARD_VERSION_ENUM;


/* 
 * Define for Messages
 */
#define PHB_NAME_STRUCT                      l4_name_struct
#define PHB_NUMBER_STRUCT                    l4c_number_struct
#define PHB_ENTRY_STRUCT                     l4c_phb_entry_struct
#define PHB_RESULT_STRUCT                    l4c_result_struct
#define MSG_PHB_GET_ENTRY_BY_NAME_REQ_STRUCT    mmi_phb_get_entry_by_name_req_struct
#define MSG_PHB_GET_ENTRY_BY_NAME_RSP_STRUCT    mmi_phb_get_entry_by_name_rsp_struct
#define MSG_PHB_GET_ENTRY_BY_INDEX_REQ_STRUCT      mmi_phb_get_entry_by_index_req_struct
#define MSG_PHB_GET_ENTRY_BY_INDEX_RSP_STRUCT      mmi_phb_get_entry_by_index_rsp_struct
#define MSG_PHB_SET_ENRTY_REQ_STRUCT            mmi_phb_set_entry_req_struct
#define MSG_PHB_SET_ENRTY_RSP_STRUCT            mmi_phb_set_entry_rsp_struct
#define MSG_PHB_DELETE_ENTRY_REQ_STRUCT            mmi_phb_del_entry_req_struct
#define MSG_PHB_DELETE_ENTRY_RSP_STRUCT            mmi_phb_del_entry_rsp_struct
#define MSG_PHB_GET_PREFERRED_STORAGE_RSP_STRUCT   mmi_phb_get_preferred_storage_rsp_struct
#define MSG_PHB_SET_PREFERRED_STORAGE_REQ_STRUCT   mmi_phb_set_preferred_storage_req_struct
#define MSG_PHB_SET_PREFERRED_STORAGE_RSP_STRUCT   mmi_phb_set_preferred_storage_rsp_struct
#define  MSG_PHB_GET_ALPHA_LIST_REQ_STRUCT         mmi_phb_get_alpha_list_req_struct
#define MSG_PHB_GET_ALPHA_LIST_RSP_STRUCT       mmi_phb_get_alpha_list_rsp_struct
#define  MSG_PHB_STARTUP_FINISH_IND_STRUCT         mmi_phb_startup_finish_ind_struct
#define  MSG_PHB_STARTUP_READ_IND_STRUCT     mmi_phb_startup_read_ind_struct
#define MSG_PHB_STARTUP_READ_NEXT_REQ_STRUCT mmi_phb_startup_read_next_req_struct
#define  MSG_PHB_UPDATE_IND_STRUCT              mmi_phb_update_ind_struct

#define MSG_PHB_STARTUP_FINISH_PHASE1_IND_STRUCT         mmi_phb_startup_phase1_ind_struct
#define MSG_PHB_STARTUP_READ_NEXT_USIM_FIELD_REQ_STRUCT mmi_phb_startup_read_next_usim_field_req_struct
#define MSG_PHB_STARTUP_READ_ANR_IND_STRUCT mmi_phb_startup_read_anr_ind_struct
#define MSG_PHB_STARTUP_READ_EMAIL_IND_STRUCT mmi_phb_startup_read_email_ind_struct
#define MSG_PHB_STARTUP_READ_GAS_IND_STRUCT mmi_phb_startup_read_gas_ind_struct
#define MSG_PHB_STARTUP_READ_GRP_IND_STRUCT mmi_phb_startup_read_grp_ind_struct
#define MSG_PHB_READ_EMAIL_REQ_STRUCT     mmi_phb_read_email_req_struct
#define MSG_PHB_READ_EMAIL_RSP_STRUCT     mmi_phb_read_email_rsp_struct
#define MSG_PHB_SET_EMAIL_REQ_STRUCT      mmi_phb_set_email_req_struct
#define MSG_PHB_SET_EMAIL_RSP_STRUCT      mmi_phb_set_email_rsp_struct
#define MSG_PHB_SET_USIM_ENRTY_REQ_STRUCT          mmi_phb_write_usim_req_struct
#define MSG_PHB_SET_USIM_ENRTY_RSP_STRUCT          mmi_phb_write_usim_rsp_struct
#define MSG_PHB_SET_GRP_REQ_STRUCT        mmi_phb_set_grp_req_struct
#define MSG_PHB_SET_GRP_RSP_STRUCT        mmi_phb_set_grp_rsp_struct

#if defined(MMS_SUPPORT)
#define MSG_PHB_MEA_ADDR_INPUT_STRUCT  mea_addr_input_struct    /* For MMS */
#endif 

//huzhuhua 080722 begin
#ifdef __PHONEBOOK_OUTPUT_INPUT__
typedef struct
{
    S8 Name[(MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH];
    S8 Number[(MAX_PB_NUMBER_LENGTH+1+1)*ENCODING_LENGTH];
 #if !defined(__MMI_PHB_NO_OPTIONAL_FIELD__)   
    PHB_OPTIONAL_FIELDS_STRUCT num_filed;
 #endif   
    kal_uint16 pictureTagID;
    kal_uint16 ringToneID;
    kal_uint8 callerGroupID;
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    S32 videoID;
#endif
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    MMI_PHB_BDAY_STR_STRUCT  birth;
#endif    
} PHB_OUTPUT_INPUT_STRUCT;
#endif
//end

/* Global context */
typedef struct
{
    /* Global variables - Keep phonebook state flag. */
    BOOL phb_ready;
    BOOL processing;
    BOOL copy_all;
    BOOL nvram_data_init;
    U8 refresh_list;
    U16 start_scr_id;
    U16 end_scr_id;
    U8 sim_name_len;
    U8 fdn_name_len;
    U8 bdn_name_len;
    U8 owner_name_len;
    U16 sim_total;
    U16 sim_used;
    U16 phone_total;
    U16 phone_used;
    U16 populate_count; /* physical index for populating option field. 0xffff if sort complete */
    U16 lookup_table_count;

    /* Pointer to global array */
    void *optional_ids;
    void *caller_group;
    U16 *list_filter;

    /* Index for list screen. */
    U16 active_index;
    U16 active_index_second;
    U16 active_index_third;

    /* for JSR PIM */
    U16 java_store_index;

    /* for other APP */
    U16 store_index;

    /* for sim refresh */
    U16 current_op;

    /* Global variables - passing parameter between functions. */
    U8 *number_to_dial[5];
    U16 highlight_entry;
    U16 new_highlight_entry;
    U8 selected_storage;
    U8 image_location;
    S32 selected_pic_index;
    S32 selected_ring_index;
    S32 selected_grp_index;
    S32 selected_pattern_index;
    S32 selected_alert_index;
    S32 selected_pic_in_view;
    U8 dial_from_list;
    U8 searched_number_type;    /* for mmi_phb_call_get_data_for_call_mgnt */
    U8 sort_type;

#ifdef __MMI_PHB_USIM_FIELD__
    BOOL is_usim;
    U8 usim_ready_stage;
    void *usim_group;
    U8 group_name_len;
    U8 group_type[MAX_PB_SIM_ENTRIES];

    U16 gas_total;
    U16 anra_total;
    U16 anra_used;
    U16 anrb_total;
    U16 anrb_used;
    U16 anrc_total;
    U16 anrc_used;
    U16 sne_total;
    U16 sne_used;
    U16 sne_name_len;
    U16 email_total;
    U16 email_used;
    U16 email_length;
    U16 usim_field_read_count;
    U8 support_field[MMI_PHB_USIM_FIELD_TOTAL];
#endif /* __MMI_PHB_USIM_FIELD__ */ 

    /* Inline Selection List */
    U16 ring_tone_list[MAX_PB_RING_TONES];
    U16 image_id_list[MAX_PB_PICTURES_TAGS];
    U8 *image_name_list[MAX_PB_PICTURES_TAGS];
    U8 *ring_tone_name_list[MAX_PB_RING_TONES];
    U8 *alert_name_list[MAX_PB_ALERT_TYPES + 1];
    U8 *led_name_list[MAX_PB_LED_PATTERNS + 1];
#if defined(__MMI_INCOMING_CALL_VIDEO__)
    S32 selected_video_index;
    U16 video_id_list[MAX_PB_VIDEO_TAGS];
    U16 selected_video_id;
    U8 *video_name_list[MAX_PB_VIDEO_TAGS];
    U8 total_video_id;
    U8 init_video;
    U8 video_location;
    U8 video_audio;
#endif /* defined(__MMI_INCOMING_CALL_VIDEO__) */ 
    U16 recv_res_id;    /* receive resource and associate to phb entry */
    U8 recv_res_from;   /* receive resource and associate to phb entry */
    U8 set_done_flag;
    U8 total_ring_tone;
    U8 total_image_id;
    U8 speak_name;

    /* System setting */
    U8 prefer_storage;
    U8 view_field[MAX_PB_VIEW_FIELDS];
    U8 name_list_filter;
#if defined(__MMI_VCARD__) && defined(__MMI_VCARD_V30__)
    U8 vcard_version;
#endif /* defined(__MMI_VCARD__) && defined(__MMI_VCARD_V30__) */
#if defined(__MMI_DUAL_SIM_MASTER__)
    BOOL startup_before_sort;
#endif
} mmi_phb_context_struct;

extern mmi_phb_context_struct g_phb_cntx;

#if (MAX_PB_ENTRIES >= 1000)
extern U16 g_phb_list_filter[MAX_PB_ENTRIES];
#endif /* MAX_PB_ENTRIES >= 1000 */
#endif /* _PHONEBOOKTYPES_H */ 

