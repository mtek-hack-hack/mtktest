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
 * EmsMiscell.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
 /**************************************************************

   FILENAME : EmsMiscell.c

   PURPOSE     : Dislay all EMS objects(Manufacture picture, 
               User defined picture, Predefined animation, Usedefiend animation,
               Manufacturer melodies, Usedefined melodies, Predefined sound.)

   REMARKS     : nil

   AUTHOR      : Hiran, Magesh k

   DATE     : 

**************************************************************/
#include "MMI_include.h"
#ifdef __MOD_SMSAL__

/*  */

/* ... Add More MMI header */
#include "CommonScreens.h"

/* ...Add MSG header */
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
/*  */
#include "ProfileGprots.h"
/*  */
#include "ems.h"
#include "Gui_ems.h"
#include "wgui_ems.h"
#include "GSM7BitDefaultAlphabet.h"
/*  */
#include "SettingProfile.h"
#include "DownloadDefs.h"
#include "DownloadProtos.h"
/*  */
/*  */
#if (defined(__MMI_FILE_MANAGER__))
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 
#ifdef __MMI_IMELODY_SUPPORT__
#include "resource_audio.h"
extern audio_resource_struct *resource_ems_imelodys;
#endif /* __MMI_IMELODY_SUPPORT__ */ 

#include "nvram_user_defs.h"

#include "SMSApi.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif /* __USB_IN_NORMAL_MODE__ */

#if defined(__MMI_MESSAGES_EMS__)
/*  */
#ifndef NVRAM_EMS_MY_PICTURE_NAME_RECORD_SIZE
#define NVRAM_EMS_MY_PICTURE_NAME_RECORD_SIZE   140
#endif 

#ifndef NVRAM_EMS_MY_ANIMATION_NAME_RECORD_SIZE
#define NVRAM_EMS_MY_ANIMATION_NAME_RECORD_SIZE 140
#endif 

#if defined(__MMI_IMELODY_SUPPORT__)
#ifndef NVRAM_EMS_MY_MELODY_NAME_RECORD_SIZE
#define NVRAM_EMS_MY_MELODY_NAME_RECORD_SIZE 140
#endif 
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 

#define   MESSAGES_ONE_SEC_TIME_OUT     1000

#define   MAX_EMS_OBJECT_LIST_DISPLAY     15
#define   MAX_EMS_PREDEFINED_ANIMATION    15
#define   MAX_EMS_PREDEFINED_SOUND     10
#ifdef __EMS_REL5__
#define   MAX_CURR_EMS_OBJECT_DATA_BUFF            1588+12
#define   MAX_EMS_OBJECT_INSERT_SIZE            1588
#else /* __EMS_REL5__ */ 
#define   MAX_CURR_EMS_OBJECT_DATA_BUFF            128+12
#define   MAX_EMS_OBJECT_INSERT_SIZE               128
#endif /* __EMS_REL5__ */ 

#if defined (__MMI_FILE_MANAGER__)
#define   MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN         FMGR_MAX_INPUT_FILE_LEN
#define   MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH   FMGR_MAX_PATH_LEN
#define   MAX_EMS_DOWNLOAD_OBJECT_NAME_EXTN_LEN FMGR_MAX_EXT_LEN
#define  MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN       FMGR_MAX_PATH_LEN+FMGR_MAX_FILE_LEN
#else /* defined (__MMI_FILE_MANAGER__) */
#define MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN        13
#define MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH	30	
#define MAX_EMS_DOWNLOAD_OBJECT_NAME_EXTN_LEN	5	
#define MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN		MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH + MAX_EMS_DOWNLOAD_OBJECT_NAME_EXTN_LEN	
#endif /* defined (__MMI_FILE_MANAGER__) */


/*  */
#define STR_EMS_PICTURE_OBJECT_FILE_NAME_EXTN_ID   ".ems"
#define STR_EMS_ANIMATION_OBJECT_FILE_NAME_EXTN_ID ".anm"
#define STR_EMS_IMELODY_OBJECT_FILE_NAME_EXTN_ID   ".imy"
#if (defined(__MMI_FILE_MANAGER__))
#define STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID       FMGR_DEFAULT_FOLDER_IMAGES       /* "USER\\image\\ems\\" */
#define STR_EMS_IMELODY_OBJECT_FILE_NAME_INIT_PATH_ID          FMGR_DEFAULT_FOLDER_AUDIO        /* "USER\\sound\\ems\\" */
#else /* (defined(__MMI_FILE_MANAGER__)) */ 
#define MAX_EMS_STR_FOLDER_LEN 30
#define STR_EMS_USER_FOLDER_ID "c:\\USER\\"
#define STR_EMS_IMAGE_FOLDER_ID "image\\"
#define STR_EMS_IMELODY_FOLDER_ID "sound\\"
#define STR_EMS_FOLDER_ID "ems\\"
#define STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID       "c:\\USER\\image\\ems\\" /* SYNC with above define values ! */
#define STR_EMS_IMELODY_OBJECT_FILE_NAME_INIT_PATH_ID          "c:\\USER\\sound\\ems\\" /* SYNC with above define values ! */
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 
/* MTK Joy added for file names, 1128 */
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_0   "ems0"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_1   "ems1"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_2   "ems2"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_3   "ems3"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_4   "ems4"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_5   "ems5"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_6   "ems6"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_7   "ems7"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_8   "ems8"
#define STR_EMS_MANUFACTURER_PIC_OBJECT_FILE_NAME_9   "ems9"
/* MTK end */

extern void (*EMS_inputbox_input_callback) (void);
#endif /* defined(__MMI_MESSAGES_EMS__) */ 
#if defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
#ifndef MAX_EMS_OBJECT_INSERT_SIZE
#ifdef __EMS_REL5__
#define   MAX_EMS_OBJECT_INSERT_SIZE               1588
#else 
#define   MAX_EMS_OBJECT_INSERT_SIZE               128
#endif 
#endif /* MAX_EMS_OBJECT_INSERT_SIZE */ 
#ifndef MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN
#define  MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN          260+41       /* FMGR_MAX_PATH_LEN+FMGR_MAX_FILE_LEN */
#endif 
PsFuncPtr emscallback;
static S8 *file_path;
#endif /* defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__) */ 
/*  */
#if defined(__MMI_MESSAGES_EMS__)
U16 PredefinedAnimationStrIDs[] =   /* Predefined Animations */
{
    STR_PREDEFINED_ANIMATION_0,
    STR_PREDEFINED_ANIMATION_1,
    STR_PREDEFINED_ANIMATION_2,
    STR_PREDEFINED_ANIMATION_3,
    STR_PREDEFINED_ANIMATION_4,
    STR_PREDEFINED_ANIMATION_5,
    STR_PREDEFINED_ANIMATION_6,
    STR_PREDEFINED_ANIMATION_7,
    STR_PREDEFINED_ANIMATION_8,
    STR_PREDEFINED_ANIMATION_9,
    STR_PREDEFINED_ANIMATION_10,
    STR_PREDEFINED_ANIMATION_11,
    STR_PREDEFINED_ANIMATION_12,
    STR_PREDEFINED_ANIMATION_13,
    STR_PREDEFINED_ANIMATION_14
};
const U16 PredefinedSoundStrIDs[] = /* Predefined Sounds */
{
    STR_PREDEFINED_SOUND_0,
    STR_PREDEFINED_SOUND_1,
    STR_PREDEFINED_SOUND_2,
    STR_PREDEFINED_SOUND_3,
    STR_PREDEFINED_SOUND_4,
    STR_PREDEFINED_SOUND_5,
    STR_PREDEFINED_SOUND_6,
    STR_PREDEFINED_SOUND_7,
    STR_PREDEFINED_SOUND_8,
    STR_PREDEFINED_SOUND_9
};
U16 ManufacturerPictureStrIDs[] =   /* ManufacturerPicture Str IDs */
{
    STR_MANUFACTURER_PICTURE_0,
    STR_MANUFACTURER_PICTURE_1,
    STR_MANUFACTURER_PICTURE_2,
    STR_MANUFACTURER_PICTURE_3,
    STR_MANUFACTURER_PICTURE_4,
    STR_MANUFACTURER_PICTURE_5,
    STR_MANUFACTURER_PICTURE_6,
    STR_MANUFACTURER_PICTURE_7,
    STR_MANUFACTURER_PICTURE_8,
    STR_MANUFACTURER_PICTURE_9
};
const U16 ManufacturerMelodiesStrIDs[] =    /* Manufacturer Melodies Str IDs */
{
    STR_MANUFACTURER_MELODIES_0,
    STR_MANUFACTURER_MELODIES_1,
    STR_MANUFACTURER_MELODIES_2,
    STR_MANUFACTURER_MELODIES_3,
    STR_MANUFACTURER_MELODIES_4,
    STR_MANUFACTURER_MELODIES_5,
    STR_MANUFACTURER_MELODIES_6,
    STR_MANUFACTURER_MELODIES_7,
    STR_MANUFACTURER_MELODIES_8,
    STR_MANUFACTURER_MELODIES_9
};

static U16 preDefinedObjectIds[MAX_EMS_OBJECT_LIST_DISPLAY] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
static U8 *userDefinedObjectDataPtrs[MAX_EMS_OBJECT_LIST_DISPLAY];
static U8 userDefinedObjectDataBuff[MAX_CURR_EMS_OBJECT_DATA_BUFF] = {0, 0};
static S32 userDefinedObjectDataSize = 0;
static S32 currObjectListHiliteIndex = 0;
static U8 currMaxEmsObjectList = 0;
static U8 currMaxEmsPictureObjects = 0;
static U8 userEmsObjectNameInput[(MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + 1) * ENCODING_LENGTH] = {0, 0};

static U8 *emsObjectNameWhenPreview = NULL;
static EMS_OBJECT_DISPLAY_STATE currEmsObjectDisplayListState;
static U8 emsFmtTextStyleStates[4] = {0, 0, 0, 0};
static U8 IsAllowed = FALSE;
static S32 listOfIsAllowedData[MAX_EMS_OBJECT_LIST_DISPLAY];

/*  */
static EMSObject *previewObjectListPtr = NULL;
static S32 nObjectLists = 0;
static S32 currObjectIndex = 0;

extern UI_EMS_input_box MMI_EMS_inputbox;
extern EMSTextFormat wgui_EMS_text_format;

/* MTK end */
#if (defined(__MMI_FILE_MANAGER__))
void mmi_ems_fm_send_by_ems(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType);
void mmi_ems_add_object_from_fm(void);
void mmi_ems_preview_object_from_fm(PU16 filePath, S32 is_short);
EMSTATUS mmi_ems_fm_open_file(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType);
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 
#if defined(__MMI_IMELODY_SUPPORT__)
extern U32 GetEmsMelodyLength(S32 index);
extern PU8 GetEmsMelodyData(S32 index);

extern void custom_get_fixed_ems_imelody_range(U8 *min_id, U8 *max_id);
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
extern U32 GetEmsPictureLength(S32 index);
extern PU8 GetEmsPictureData(S32 index);
extern void handle_category28_input(void);
extern void T9SynT9WithInputBox(void);
#endif /* defined(__MMI_MESSAGES_EMS__) */ 
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
extern U8 DeInitMessagesEMSBuffer(msg_ems_data_struct *pE);

//////////////////////////////////////////////////////////////////////
// Routines for manipulating local buffers for EMS Edit and View
//////////////////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  ErrorHandlingWhileInsertingObject
 * DESCRIPTION
 *  Handle error case when insert object
 * PARAMETERS
 *  emsObjectStatus     [IN]        Insert status
 * RETURNS
 *  void
 *****************************************************************************/
void ErrorHandlingWhileInsertingObject(EMSTATUS emsObjectStatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hander error case, if could not insert objects. */
    switch (emsObjectStatus)
    {
        case EMS_OK:
            break;
        case EMS_NO_MEMORY:
            DisplayPopup(
                (PU8) GetString(STR_EMS_OBJECT_NUM_EXCEED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
        case EMS_NO_SPACE:
            DisplayPopup(
                (PU8) GetString(STR_NO_SPACE_TO_INSERT_OBJECT),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
        case EMS_INVALID_OBJECT:
    #if (defined(__MMI_FILE_MANAGER__))
            DisplayPopup(
                (PU8) GetString(STR_FMGR_INVALID_FORMAT),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            DisplayPopup(
                (PU8) GetString(STR_SMS_DOES_NOT_SUPPORT),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            break;
        case EMS_EMS_DATA_EXCEEDED:
    #if (defined(__MMI_FILE_MANAGER__))
            DisplayPopup(
                (PU8) GetString(FMGR_FS_FILE_TOO_LARGE_TEXT),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            break;
        case EMS_NULL_POINTER:
            DisplayPopup(
                (PU8) GetString(STR_READ_SMS_DATA_FAILED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
        case EMS_NO_ALIGNMENT_FMT:
            DisplayPopup(
                (PU8) GetString(STR_SMS_OBJECT_EXISTENCE_ERROR),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
        default /* EMS_UNSPECIFIED_ERROR */ :
            DisplayPopup(
                (PU8) GetString(STR_SMS_DOES_NOT_SUPPORT),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
    }
}

#if defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_vobject_send_by_ems_callback
 * DESCRIPTION
 *  Call back vobject send by ems function
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  flag        [IN]        Send result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_vobject_send_by_ems_callback(void *dummy, module_type mod, U16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (flag)
    {
        case MMI_FRM_SMS_OK:
            DisplayPopup(
                (PU8) GetString(STR_SMS_SEND_SUCCESS),
                IMG_SEND_SUCCESS_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
            mmi_frm_sms_delete_screen_history();
            break;
        case MMI_FRM_SMS_RETURN:
        case MMI_FRM_SMS_END:
        case MMI_FRM_SMS_END_FROM_SENDING:
            /* do not keep vcard and vcalendar content when sending fail */
            ReleaseEMSEditBuffer();
            break;
        case MMI_FRM_SMS_DATAEXCEED:
    #if (defined(__MMI_FILE_MANAGER__))
            DisplayPopup(
                (PU8) GetString(FMGR_FS_FILE_TOO_LARGE_TEXT),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            DisplayPopup(
                (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_frm_sms_delete_screen_history();
            break;
        case MMI_FRM_SMS_NOTREADY:
            DisplayPopup(
                (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                IMG_SEND_FAIL_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
        case MMI_FRM_SMS_ABORT:
            /* do not keep vcard and vcalendar content when sending aborts */
            ReleaseEMSEditBuffer();
            DisplayPopup(
                (PU8) GetString(STR_ABORT_SENDING_SMS),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
            mmi_frm_sms_delete_screen_history();
            break;
        default:
            /* do not keep vcard and vcalendar content when sending fail */
            ReleaseEMSEditBuffer();
            DisplayPopup(
                (PU8) GetString(STR_SMS_SEND_FAILED),
                IMG_SEND_FAIL_PIC_MSG,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            mmi_frm_sms_delete_screen_history();
            break;
    }
    if (file_path != NULL)
    {
        OslMfree(file_path);
        file_path = NULL;
    }
    if (emscallback)
    {
        emscallback(&flag);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_vobject_send_by_ems
 * DESCRIPTION
 *  Send vobject by ems
 * PARAMETERS
 *  scrport         [IN]        Source port
 *  dstport         [IN]        Destination port
 *  filepath        [IN]        Filepath
 *  callback        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_vobject_send_by_ems(U16 scrport, U16 dstport, S8 *filepath, PsFuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = TRUE;
    mmi_frm_sms_send_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

    emscallback = callback;
    sendData->sendrequire |= MMI_FRM_SMS_PORT;
    sendData->srcport = scrport;
    sendData->desport = dstport;
    sendData->dcs = SMSAL_8BIT_DCS;
    if (IsMessagesReEntering())
    {
        result = FALSE;
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        if (emscallback != NULL)
        {
            emscallback((PU16) & result);
        }
        OslMfree(sendData);
        return;
    }
    if ((mmi_ucs2strlen(filepath) == 0) || (mmi_ucs2strlen(filepath) > MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN))
    {
        result = FALSE;
        DisplayPopup(
            (PU8) GetString(STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        if (emscallback != NULL)
        {
            emscallback((PU16) & result);
        }
        OslMfree(sendData);
        return;
    }
    if (file_path != NULL)
    {
        OslMfree(file_path);
        file_path = NULL;
    }
    file_path = OslMalloc((mmi_ucs2strlen(filepath) + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy(file_path, filepath);
    sendData->filename = file_path;
#ifdef __MMI_DUAL_SIM_MASTER__
	sendData->sendrequire |= MMI_FRM_SMS_DISP_SIM_OPT;
#endif
    mmi_frm_sms_send_sms(mmi_ems_vobject_send_by_ems_callback, MOD_MMI, sendData);
    OslMfree(sendData);
}

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
#endif /* 0 */ 
#endif /* defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__) */ 

#if defined(__MMI_MESSAGES_EMS__)
/**************************************************************
            text format
**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  GetFmtTextSize
 * DESCRIPTION
 *  Get text format size
 * PARAMETERS
 *  void
 * RETURNS
 *  size
 *****************************************************************************/
U8 GetFmtTextSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (EMS_inputbox_get_text_size())
    {
        case EMS_FONTSIZE_SMALL:
            return (U8) 0;
        case EMS_FONTSIZE_NORMAL:
            return (U8) 1;
        case EMS_FONTSIZE_LARGE:
            return (U8) 2;
    }
    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetFmtTextSize
 * DESCRIPTION
 *  Set text format size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetFmtTextSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetHighlightedItem())
    {
        case 0:
            EMS_inputbox_set_text_size(EMS_FONTSIZE_SMALL);
            break;
        case 1:
            EMS_inputbox_set_text_size(EMS_FONTSIZE_NORMAL);
            break;
        case 2:
            EMS_inputbox_set_text_size(EMS_FONTSIZE_LARGE);
            break;
    }
    GoBackToHistory(SCR_ID_MSG_WRITE);
}


/*****************************************************************************
 * FUNCTION
 *  SetFmtTextStyle
 * DESCRIPTION
 *  Set text format style
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetFmtTextStyle(void)
{
#ifndef __MMI_TEXT_FORMAT_WITHOUT_BOLD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMS_inputbox_set_text_style(
        emsFmtTextStyleStates[0],
        emsFmtTextStyleStates[1],
        emsFmtTextStyleStates[2],
        emsFmtTextStyleStates[3]);
#else /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 
    EMS_inputbox_set_text_style(
        emsFmtTextStyleStates[3],
        emsFmtTextStyleStates[0],
        emsFmtTextStyleStates[1],
        emsFmtTextStyleStates[2]);
#endif /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 
    GoBackToHistory(SCR_ID_MSG_WRITE);
}


/*****************************************************************************
 * FUNCTION
 *  GetFmtTextAlignment
 * DESCRIPTION
 *  Get text format alignment
 * PARAMETERS
 *  void
 * RETURNS
 *  alignment
 *****************************************************************************/
U8 GetFmtTextAlignment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (EMS_inputbox_get_text_alignment())
    {
        case EMS_ALIGN_LANG_DEP:
            return (U8) 0;
        case EMS_ALIGN_LEFT:
            return (U8) 1;
        case EMS_ALIGN_CENTER:
            return (U8) 2;
        case EMS_ALIGN_RIGHT:
            return (U8) 3;
    }
    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetFmtTextAlignment
 * DESCRIPTION
 *  Set text format alignment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetFmtTextAlignment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetHighlightedItem())
    {
        case 0:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_LANG_DEP);
            break;
        case 1:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_LEFT);
            break;
        case 2:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_CENTER);
            break;
        case 3:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_RIGHT);
            break;
        default:
            emsObjectStatus = EMS_inputbox_set_text_alignment(EMS_ALIGN_LANG_DEP);
            break;
    }
    GoBackToHistory(SCR_ID_MSG_WRITE);
    ErrorHandlingWhileInsertingObject(emsObjectStatus); /* check whetehr it is inserted or not. */
}


/*****************************************************************************
 * FUNCTION
 *  SetFmtTextNewParagraph
 * DESCRIPTION
 *  Set text format new paragraph
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetFmtTextNewParagraph(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetHighlightedItem())
    {
        case 0:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_LANG_DEP);
            break;
        case 1:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_LEFT);
            break;
        case 2:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_CENTER);
            break;
        case 3:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_RIGHT);
            break;
        default:
            emsObjectStatus = EMS_inputbox_create_new_paragraph(EMS_ALIGN_LANG_DEP);
            break;
    }

    GoBackToHistory(SCR_ID_MSG_WRITE);
    ErrorHandlingWhileInsertingObject(emsObjectStatus); /* check whetehr it is inserted or not. */
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrFmtTextSizeMenu
 * DESCRIPTION
 *  Entry text format size screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrFmtTextSizeMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 nNumofItem = 0;
    U16 nStrItemListIDs[MAX_SUB_MENUS] = {0, 0, 0};
    U8 *guiBuffer = NULL;
    U8 *nStrItemList[MAX_SUB_MENUS] = {NULL, NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_TEXT_FORMAT_SIZE, mmi_msg_exit_generic, EntryScrFmtTextSizeMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEXT_FORMAT_SIZE);
    if (guiBuffer == NULL)
    {
        currObjectListHiliteIndex = GetFmtTextSize();
    }
    SetParentHandler(MENU_EMS_TEXT_SIZE_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MENU_EMS_TEXT_SIZE_ID);
    GetSequenceStringIds(MENU_EMS_TEXT_SIZE_ID, nStrItemListIDs);
    for (index = 0; index < nNumofItem; index++)
    {
        nStrItemList[index] = (PU8) GetString((U16) nStrItemListIDs[index]);
    }
    SetMessagesCurrScrnID(SCR_ID_MSG_TEXT_FORMAT_SIZE);
    ShowCategory109Screen(
        STR_EMS_TEXT_SIZE_ID,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        NULL,
        currObjectListHiliteIndex,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrFmtTextStyleMenu
 * DESCRIPTION
 *  Entry text format style screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrFmtTextStyleMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 nNumofItem = 0;
    U16 nStrItemListIDs[MAX_SUB_MENUS] = {0, 0, 0};
    U8 *guiBuffer = NULL;
    U8 *nStrItemList[MAX_SUB_MENUS] = {NULL, NULL, NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_TEXT_FORMAT_STYLE, mmi_msg_exit_generic, EntryScrFmtTextStyleMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEXT_FORMAT_STYLE);
    if (guiBuffer == NULL)
    {
        currObjectListHiliteIndex = 0;
    #ifndef __MMI_TEXT_FORMAT_WITHOUT_BOLD__
        EMS_inputbox_get_text_style(
            &emsFmtTextStyleStates[0],
            &emsFmtTextStyleStates[1],
            &emsFmtTextStyleStates[2],
            &emsFmtTextStyleStates[3]);
    #else /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 
        EMS_inputbox_get_text_style(
            &emsFmtTextStyleStates[3],
            &emsFmtTextStyleStates[0],
            &emsFmtTextStyleStates[1],
            &emsFmtTextStyleStates[2]);
    #endif /* __MMI_TEXT_FORMAT_WITHOUT_BOLD__ */ 
    }
    SetParentHandler(MENU_EMS_TEXT_STYLE_ID);
    nNumofItem = GetNumOfChild(MENU_EMS_TEXT_STYLE_ID);
    GetSequenceStringIds(MENU_EMS_TEXT_STYLE_ID, nStrItemListIDs);
    for (index = 0; index < nNumofItem; index++)
    {
        nStrItemList[index] = (PU8) GetString((U16) nStrItemListIDs[index]);
    }
    SetCheckboxToggleRightSoftkeyFunctions(SetFmtTextStyle, GoBackHistory);
    SetMessagesCurrScrnID(SCR_ID_MSG_TEXT_FORMAT_STYLE);
    ShowCategory140Screen(
        STR_EMS_TEXT_STYLE_ID,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        nNumofItem,
        nStrItemList,
        emsFmtTextStyleStates,
        currObjectListHiliteIndex,
        guiBuffer);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrFmtAlignmentMenu
 * DESCRIPTION
 *  Entry text format alignment screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrFmtAlignmentMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 nNumofItem = 0;
    U16 nStrItemListIDs[MAX_SUB_MENUS] = {0, 0, 0};
    U8 *guiBuffer = NULL;
    U8 *nStrItemList[MAX_SUB_MENUS] = {NULL, NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_TEXT_FORMAT_ALIGNMENT, mmi_msg_exit_generic, EntryScrFmtAlignmentMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEXT_FORMAT_ALIGNMENT);
    if (guiBuffer == NULL)
    {
        currObjectListHiliteIndex = GetFmtTextAlignment();
    }
    SetParentHandler(MENU_EMS_ALIGNMENT_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MENU_EMS_ALIGNMENT_ID);
    GetSequenceStringIds(MENU_EMS_ALIGNMENT_ID, nStrItemListIDs);
    for (index = 0; index < nNumofItem; index++)
    {
        nStrItemList[index] = (PU8) GetString((U16) nStrItemListIDs[index]);
    }
    SetMessagesCurrScrnID(SCR_ID_MSG_TEXT_FORMAT_ALIGNMENT);
    ShowCategory109Screen(
        STR_EMS_ALIGNMENT_ID,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        NULL,
        currObjectListHiliteIndex,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrFmtNewParagraphMenu
 * DESCRIPTION
 *  Entry text format new paragraph screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrFmtNewParagraphMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 nNumofItem = 0;
    U16 nStrItemListIDs[MAX_SUB_MENUS] = {0, 0, 0};
    U8 *guiBuffer = NULL;
    U8 *nStrItemList[MAX_SUB_MENUS] = {NULL, NULL, NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_TEXT_FORMAT_NEW_PARA, mmi_msg_exit_generic, EntryScrFmtNewParagraphMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEXT_FORMAT_NEW_PARA);
    if (guiBuffer == NULL)
    {
        currObjectListHiliteIndex = GetFmtTextAlignment();
    }
    SetParentHandler(MENU_EMS_NEW_PARAGRAPH_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MENU_EMS_NEW_PARAGRAPH_ID);
    GetSequenceStringIds(MENU_EMS_NEW_PARAGRAPH_ID, nStrItemListIDs);
    for (index = 0; index < nNumofItem; index++)
    {
        nStrItemList[index] = (PU8) GetString((U16) nStrItemListIDs[index]);
    }
    SetMessagesCurrScrnID(SCR_ID_MSG_TEXT_FORMAT_NEW_PARA);
    ShowCategory109Screen(
        STR_EMS_NEW_PARAGRAPH_ID,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        NULL,
        currObjectListHiliteIndex,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrEmsFormatTextMenu
 * DESCRIPTION
 *  Entry text format screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrEmsFormatTextMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems = 0;
    PU8 guiBuffer = NULL;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_TEXT_FORMAT, mmi_msg_exit_generic, EntryScrEmsFormatTextMenu, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_TEXT_FORMAT);
    SetParentHandler(MENU_EMS_FORMATING_TEXT_ID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    numItems = GetNumOfChild(MENU_EMS_FORMATING_TEXT_ID);
    GetSequenceStringIds(MENU_EMS_FORMATING_TEXT_ID, nStrItemList);
    SetMessagesCurrScrnID(SCR_ID_MSG_TEXT_FORMAT);
    ShowCategory52Screen(
        STR_EMS_FORMATING_TEXT_ID,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsFormattingTextHandler
 * DESCRIPTION
 *  Highlight text format handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsFormattingTextHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryScrEmsFormatTextMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScrEmsFormatTextMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* /////////////////////////////////////////////////////////////////////////////////// */


/*****************************************************************************
 * FUNCTION
 *  InitUserDefinedObjectDataPtrs
 * DESCRIPTION
 *  Init user defined object data pointers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitUserDefinedObjectDataPtrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_EMS_OBJECT_LIST_DISPLAY; index++)
    {
        userDefinedObjectDataPtrs[index] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MemsetUserDefinedObjectDataBuff
 * DESCRIPTION
 *  Reset user defined object data buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MemsetUserDefinedObjectDataBuff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&userDefinedObjectDataBuff, 0, MAX_CURR_EMS_OBJECT_DATA_BUFF);
}


/*****************************************************************************
 * FUNCTION
 *  FreeUserEmsObjectNameInputBuff
 * DESCRIPTION
 *  Reset user defined object name input buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FreeUserEmsObjectNameInputBuff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&userEmsObjectNameInput, 0, (MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN * ENCODING_LENGTH) + ENCODING_LENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  MessagesGetString
 * DESCRIPTION
 *  Get string in UCS2 format
 * PARAMETERS
 *  pathStr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static S8 *MessagesGetString(S8 *pathStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 emsObjectFileNameStaticBuf[(MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + 1) * ENCODING_LENGTH] = {0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(emsObjectFileNameStaticBuf, 0, (MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2(emsObjectFileNameStaticBuf, pathStr);
    return emsObjectFileNameStaticBuf;
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectDataSize
 * DESCRIPTION
 *  Get object data size
 * PARAMETERS
 *  void
 * RETURNS
 *  object data size
 *****************************************************************************/
S32 GetEmsObjectDataSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IsAllowed = FALSE;
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_PICTURE_STATE:
            return EMS_check_predefined_picture_data_size(userDefinedObjectDataBuff, &IsAllowed);
        case EMS_OBJECT_MY_PICTURE_STATE:
            return EMS_check_userdefined_picture_size(userDefinedObjectDataBuff, &IsAllowed);
        case EMS_OBJECT_MY_ANIMATION_STATE:
            return EMS_check_userdefined_animation_size(userDefinedObjectDataBuff, &IsAllowed);
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            return EMS_check_predefined_melody_data_size(userDefinedObjectDataBuff, &IsAllowed);
        case EMS_OBJECT_MY_MELODY_STATE:
        case EMS_OBJECT_MY_MELODY_DOWNLOAD_APP_STATE:
            return EMS_check_userdefined_melody_size(userDefinedObjectDataBuff, &IsAllowed);
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_MY_PICTURE_A_ANIMATION_DOWNLOAD_APP_STATE:
            if (currObjectListHiliteIndex < currMaxEmsPictureObjects)
            {
                return EMS_check_userdefined_picture_size(userDefinedObjectDataBuff, &IsAllowed);
            }
            else
            {
                return EMS_check_userdefined_animation_size(userDefinedObjectDataBuff, &IsAllowed);
            }
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ErrorHandlingWhileSavingObject
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  emsObjectStatus     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ErrorHandlingWhileSavingObject(EMSTATUS emsObjectStatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (emsObjectStatus)
    {
        case EMS_OK:
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_SAVED),
                IMG_GLOBAL_ACTIVATED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) SAVE_TONE);
            break;
        case EMS_ALREADY_INITIALIZED:
    #if (defined(__MMI_FILE_MANAGER__))
            DisplayPopup(
                (PU8) GetString(FMGR_FS_FILE_EXISTS_TEXT),
                IMG_GLOBAL_ERROR,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            DisplayPopup(
                (PU8) GetString(STR_EMS_OBJECT_DUPLICATED_NAME_INPUT_AGAIN),
                IMG_GLOBAL_ERROR,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            break;
        case EMS_NO_SPACE:
    #if (defined(__MMI_FILE_MANAGER__))
            DisplayPopup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_ERROR,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            DisplayPopup(
                (PU8) GetString(STR_EMS_OBJECT_STAORAGE_FULL),
                IMG_GLOBAL_ERROR,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            break;
        case EMS_INVALID_FILE_NAME:
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(FS_INVALID_FILENAME)),
                IMG_GLOBAL_ERROR,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
            
        case EMS_EMPTY_FILE_NAME:
            DisplayPopup(
                (PU8) GetString(STR_EMS_EMPTY_FILENAME),
                IMG_GLOBAL_ERROR,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break; 
            
        default /* EMS_UNSPECIFIED_ERROR */ :
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_UNFINISHED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_skip_space
 * DESCRIPTION
 *  skip space in a string
 * PARAMETERS
 *  line        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
PS8 mmi_msg_skip_space(S8 *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ptr;
    S32 i = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = line;

    len = (mmi_ucs2strlen(line)) << 1;

    while (ptr[i] == ' ' && ptr[i + 1] == 0)
    {
        ptr += 2;
        if (i >= len)
        {
            break;
        }
    }
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  WriteDownloadObjectDataIntoFileSystem
 * DESCRIPTION
 *  Write object data into file system
 * PARAMETERS
 *  void
 * RETURNS
 *  write result
 *****************************************************************************/
EMSTATUS WriteDownloadObjectDataIntoFileSystem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 wByte = 0;
    S32 gWriteResult = 0;
    FS_HANDLE emsObjectFilePtr = 0;
    S8 emsObjectFileNameBuf[(MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN + 1) * ENCODING_LENGTH] = {0, 0};
    S8 *temptr = NULL;
#if (defined(__MMI_FILE_MANAGER__))
    U16 driveName;
    S8 temp[4];
    UI_character_type dir_ems_root[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_fmgr_is_filename_valid((S8*)userEmsObjectNameInput) == FALSE)
	{
		return EMS_INVALID_FILE_NAME;
	}
    driveName = MMI_PUBLIC_DRV;
    sprintf(temp, "%c:\\", (S8) driveName);
    mmi_asc_to_ucs2((S8*) dir_ems_root, temp);
#endif /* (defined(__MMI_FILE_MANAGER__)) */
    temptr = mmi_msg_skip_space((PS8)userEmsObjectNameInput);
    if (mmi_ucs2strlen(temptr) == 0)
    {
        return EMS_EMPTY_FILE_NAME;
    }
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_MY_PICTURE_STATE:   /* All Download Objects Only... */
    #if (defined(__MMI_FILE_MANAGER__))
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cpy(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID));
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) temptr);
            mmi_ucs2cat(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_PICTURE_OBJECT_FILE_NAME_EXTN_ID));
            break;
        case EMS_OBJECT_MY_ANIMATION_STATE:
    #if (defined(__MMI_FILE_MANAGER__))
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cpy(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID));
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) temptr);
            mmi_ucs2cat(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_ANIMATION_OBJECT_FILE_NAME_EXTN_ID));
            break;
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MY_MELODY_STATE:
    #if (defined(__MMI_FILE_MANAGER__))
            mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cpy(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_IMELODY_OBJECT_FILE_NAME_INIT_PATH_ID));
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) temptr);
            mmi_ucs2cat(
                (S8*) emsObjectFileNameBuf,
                (S8*) MessagesGetString((S8*) STR_EMS_IMELODY_OBJECT_FILE_NAME_EXTN_ID));
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    }
    /* duplicated filename */
    emsObjectFilePtr = FS_Open((U16*)emsObjectFileNameBuf, FS_READ_ONLY);
    if (emsObjectFilePtr > 0)
    {
        FS_Close(emsObjectFilePtr);
        return EMS_ALREADY_INITIALIZED;
    }
    emsObjectFilePtr = FS_Open((U16*)emsObjectFileNameBuf, FS_READ_WRITE|FS_CREATE_ALWAYS);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[EmsMiscell.c] fopen result = %d -------*", emsObjectFilePtr);
    if (emsObjectFilePtr > 0)
    {
        gWriteResult = FS_Write(emsObjectFilePtr, (void*)userDefinedObjectDataBuff, userDefinedObjectDataSize, &wByte);
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[EmsMiscell.c] fwrite result = %d -------*", gWriteResult);
        /* if(userDefinedObjectDataSize==wByte) success ele failure; */
        FS_Close(emsObjectFilePtr);
        if (gWriteResult < 0)
        {
            FS_Delete((U16*)emsObjectFileNameBuf);
            return EMS_NO_SPACE;
        }
        else
        {
            return EMS_OK;
        }
    }

    if (emsObjectFilePtr == FS_INVALID_FILENAME)
    {
        return EMS_INVALID_FILE_NAME;
    }
    else
    {
        return EMS_UNSPECIFIED_ERROR;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  ReadDownloadObjectDataFromFileSystem
 * DESCRIPTION
 *  Read object data from file system
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  read result
 *****************************************************************************/
U8 ReadDownloadObjectDataFromFileSystem(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_PICTURE_STATE:
        {
            U8 *imagedata;
            U16 imageindex = IMG_EMS01_PIC + (U16) index;
            U16 imagedatasize;

            MemsetUserDefinedObjectDataBuff();
            imagedata = (U8*) GetImage(imageindex);
            imagedatasize = 9 + (*(imagedata + 7)) | (*(imagedata + 8)) << 8;
            memcpy(userDefinedObjectDataBuff, imagedata, imagedatasize);
            emsObjectNameWhenPreview = (U8*) GetString(ManufacturerPictureStrIDs[index]);
            return TRUE;
        }
    #ifdef __MMI_IMELODY_SUPPORT__
        case EMS_OBJECT_MELODY_STATE:
        {
            U8 userDefinedObjectDataBuffTemp[MAX_CURR_EMS_OBJECT_DATA_BUFF];

            MemsetUserDefinedObjectDataBuff();
            memcpy(userDefinedObjectDataBuff, resource_ems_imelodys[index].data, resource_ems_imelodys[index].len);
            userDefinedObjectDataSize = resource_ems_imelodys[index].len;
            EMS_predefined_melody_attach_header(
                userDefinedObjectDataBuff,
                userDefinedObjectDataBuffTemp,
                &userDefinedObjectDataSize);
            memcpy(userDefinedObjectDataBuff, userDefinedObjectDataBuffTemp, userDefinedObjectDataSize);
            return TRUE;
        }
    #endif /* __MMI_IMELODY_SUPPORT__ */ 
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrEmsObjectDisplayListState
 * DESCRIPTION
 *  Set object state
 * PARAMETERS
 *  userDefinedObjectDataType       [IN]        Object data type
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrEmsObjectDisplayListState(U8 userDefinedObjectDataType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (userDefinedObjectDataType)
    {
        case EMS_USERDEFINED_PICTURE:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_PICTURE_STATE;
            break;
        case EMS_USERDEFINED_ANIMATION:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_ANIMATION_STATE;
            break;
            /* MTK Joy added for customization, 1014 */
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_USERDEFINED_MELODY:
            currEmsObjectDisplayListState = EMS_OBJECT_MY_MELODY_STATE;
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            /* MTK end */
    }
}


/*****************************************************************************
 * FUNCTION
 *  CallBackLoadUserDefinedObjectDataBuffPtr
 * DESCRIPTION
 *  Call back to get user defined object data
 * PARAMETERS
 *  index       [IN]        Object index
 * RETURNS
 *  data buffer pointer
 *****************************************************************************/
U8 *CallBackLoadUserDefinedObjectDataBuffPtr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadDownloadObjectDataFromFileSystem(index))
    {
        userDefinedObjectDataSize = GetEmsObjectDataSize();
    #if !defined UI_SMALL_IMAGE_SELECTOR_SCREEN
        if (!whether_no_small_screen())
        {
            ChangeTitleString(emsObjectNameWhenPreview);
            draw_title();
        }
    #endif /* !defined UI_SMALL_IMAGE_SELECTOR_SCREEN */ 
        return userDefinedObjectDataBuff;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectDataInsertStatus
 * DESCRIPTION
 *  Get object insert status
 * PARAMETERS
 *  index       [IN]        Object index
 * RETURNS
 *  insert status
 *****************************************************************************/
U16 GetEmsObjectDataInsertStatus(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadDownloadObjectDataFromFileSystem(index))
    {
        userDefinedObjectDataSize = GetEmsObjectDataSize();
        listOfIsAllowedData[index] = IsAllowed;
    }
    else
    {
        IsAllowed = 0;
        listOfIsAllowedData[index] = IsAllowed;
    }
    if (IsAllowed)
    {
        return EMS_CAN_INSERT_OBJECT_ID;
    }
    else
    {
        return EMS_CANNOT_INSERT_OBJECT_ID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectDataSizeHint
 * DESCRIPTION
 *  Get object data size hint
 * PARAMETERS
 *  index       [IN]        Object index
 * RETURNS
 *  hint data pointer
 *****************************************************************************/
U8 *GetEmsObjectDataSizeHint(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsAllowed)
    {
        U8 emsObjectDataSizeHintBuff[10] = { '\0', '\0' };
        memset(hintData[index], 0, MAX_SUB_MENU_HINT_SIZE);
        mmi_asc_to_ucs2((S8*) hintData[index], (S8*) emsObjectDataSizeHintBuff);
        return hintData[index];
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectDisplayListDetails
 * DESCRIPTION
 *  Get object display list
 * PARAMETERS
 *  lskStrID            [IN/OUT]        LSK string ID
 *  strItemListPtr      [IN/OUT]        String list pointer
 *  imgItemListPtr      [IN/OUT]        Image list pointer
 *  popUpList           [IN/OUT]        Popup list pointer
 * RETURNS
 *  void
 *****************************************************************************/
void GetEmsObjectDisplayListDetails(U16 *lskStrID, U8 **strItemListPtr, U16 *imgItemListPtr, U8 **popUpList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

#if defined(__MMI_IMELODY_SUPPORT__)
    U8 minid = 0;
    U8 maxid = 0;
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*-------[EmsMiscell.c] GetEmsObjectListDetails -------*\n");
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_PICTURE_STATE:
            currMaxEmsObjectList = EmsPictureNum();
            *lskStrID = STR_GLOBAL_VIEW;
            for (index = 0; index < currMaxEmsObjectList; index++)
            {
                strItemListPtr[index] = (PU8) GetString((U16) ManufacturerPictureStrIDs[index]);
                imgItemListPtr[index] = GetEmsObjectDataInsertStatus(index);
                popUpList[index] = GetEmsObjectDataSizeHint(index);
            }
            break;
        case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
            currMaxEmsObjectList = MAX_EMS_PREDEFINED_ANIMATION;
            *lskStrID = STR_GLOBAL_VIEW;
            for (index = 0; index < currMaxEmsObjectList; index++)
            {
                strItemListPtr[index] = (PU8) GetString((U16) PredefinedAnimationStrIDs[index]);
                imgItemListPtr[index] = EMS_CAN_INSERT_OBJECT_ID;
                popUpList[index] = NULL;
            }
            break;
        #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            EnableDisableAudioPlayback();
            custom_get_fixed_ems_imelody_range(&minid, &maxid);
            currMaxEmsObjectList = (maxid - minid + 1);
            *lskStrID = STR_GLOBAL_OK;
            for (index = 0; index < currMaxEmsObjectList; index++)
            {
                strItemListPtr[index] = (PU8) GetString((U16) ManufacturerMelodiesStrIDs[index]);
                imgItemListPtr[index] = GetEmsObjectDataInsertStatus(index);
                popUpList[index] = GetEmsObjectDataSizeHint(index);
            }
            break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
            EnableDisableAudioPlayback();
            currMaxEmsObjectList = MAX_EMS_PREDEFINED_SOUND;
            *lskStrID = STR_GLOBAL_OK;
            for (index = 0; index < currMaxEmsObjectList; index++)
            {
                strItemListPtr[index] = (PU8) GetString((U16) PredefinedSoundStrIDs[index]);
                imgItemListPtr[index] = EMS_CAN_INSERT_OBJECT_ID;
                popUpList[index] = NULL;
            }
            break;
        default:
            currMaxEmsObjectList = 0;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryEMSObjectList
 * DESCRIPTION
 *  Entry object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategoryEMSScreen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_symbols,
                MMI_ID_TYPE *symbols,
                MMI_ID_TYPE *descriptions,
                S32 highlighted_item,
                U8 *history_buffer);
extern U16 EMS_predefined_images[];
extern U16 EMS_predefined_animations[];
static void RegisterLskAndRightArrowHandler(void);
static void RegisterEndKeyForPreviewEmsObjectScrnHandler(void);
static U16 GetLskStringID(void);
static U16 GetLskImageID(void);

void EntryEMSObjectList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lskStrID = 0;
    U8 *guiBuffer = NULL;
    U8 *strItemList[MAX_EMS_OBJECT_LIST_DISPLAY
                    /* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
                    + MAXIMUM_DOWNLOAD_AUDIO + MAXIMUM_COMPOSED_RINGTONE
#endif 
                    /* MTK end */
        ];
    U16 imgItemList[MAX_EMS_OBJECT_LIST_DISPLAY
                    /* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
                    + MAXIMUM_DOWNLOAD_AUDIO + MAXIMUM_COMPOSED_RINGTONE
#endif 
                    /* MTK end */
        ];
    U8 *popUpList[MAX_EMS_OBJECT_LIST_DISPLAY
                  /* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
                  + MAXIMUM_DOWNLOAD_AUDIO + MAXIMUM_COMPOSED_RINGTONE
#endif 
                  /* MTK end */
        ];

#if (defined(__MMI_FILE_MANAGER__))
    U16 driveName;
    S8 temp[4];
    UI_character_type dir_ems_root[4];
    S8 emsObjectFileNameBuf[(MAX_EMS_DOWNLOAD_OBJECT_FILE_LEN + 1) * ENCODING_LENGTH] = {0, 0};
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    driveName = MMI_PUBLIC_DRV;
    sprintf(temp, "%c:\\", (S8) driveName);
    mmi_asc_to_ucs2((S8*) dir_ems_root, temp);

    mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 

    switch (currEmsObjectDisplayListState)
    {
    #if (defined(__MMI_FILE_MANAGER__))
        case EMS_OBJECT_MY_PICTURE_STATE:
            /* [Bear] 2004/6/23 - begin */
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_EMS);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
            mmi_fmgr_select_path_and_enter(
                APP_MESSAGES,
                FMGR_SELECT_FILE,
                filter,
                (PS8) emsObjectFileNameBuf,
                (PsExtFuncPtr) mmi_ems_preview_object_from_fm);
            /* [Bear] 2004/6/23 - end */
            break;
        case EMS_OBJECT_MY_ANIMATION_STATE:
            /* [Bear] 2004/6/23 - begin */
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_ANM);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
            mmi_fmgr_select_path_and_enter(
                APP_MESSAGES,
                FMGR_SELECT_FILE,
                filter,
                (PS8) emsObjectFileNameBuf,
                (PsExtFuncPtr) mmi_ems_preview_object_from_fm);
            /* [Bear] 2004/6/23 - end */
            break;
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MY_MELODY_STATE:
            /* [Bear] 2004/6/23 - begin */
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_IMY);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

            mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);
            mmi_fmgr_select_path_and_enter(
                APP_MESSAGES,
                FMGR_SELECT_FILE,
                filter,
                (PS8) emsObjectFileNameBuf,
                (PsExtFuncPtr) mmi_ems_preview_object_from_fm);
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    #else /* (defined(__MMI_FILE_MANAGER__)) */ 
        case EMS_OBJECT_MY_PICTURE_STATE:
        case EMS_OBJECT_MY_ANIMATION_STATE:
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MY_MELODY_STATE:
    #endif 
    #endif /* (defined(__MMI_FILE_MANAGER__)) */ 
        case EMS_OBJECT_PICTURE_STATE:
        case EMS_OBJECT_MELODY_STATE:
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
    #if !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__)
        case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
    #endif 

            GetEmsObjectDisplayListDetails(&lskStrID, strItemList, imgItemList, popUpList);
            if (currMaxEmsObjectList > 0)
            {
            #ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
            #if !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__)
                if (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE ||
                    currEmsObjectDisplayListState == EMS_OBJECT_PREDEFINED_ANIMATION_STATE)
            #else /* !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__) */ 
                if (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE)
            #endif /* !defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_240X320__) */ 
                {
                    enable_resized_small_screen();  /* small screen is only applicable to picture and animation */
                }
                else
                {
                    disable_resized_small_screen(); /* small screen is not applicable to sound and melody */
                }
                if (whether_no_small_screen())
                {
                    EntryNewScreen(SCR_ID_MSG_EMS_PREVIEW_OBJECT, mmi_msg_exit_generic, EntryEMSObjectList, NULL);
                    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_EMS_PREVIEW_OBJECT);
                    RegisterCategory144ObjectLoader(CallBackLoadUserDefinedObjectDataBuffPtr);
                    SetMessagesCurrScrnID(SCR_ID_MSG_EMS_PREVIEW_OBJECT);
                    ShowImageSelectorScreen(
                        GetString(STR_GLOBAL_SELECT),
                        IMG_SMS_ENTRY_SCRN_CAPTION,
                        GetLskStringID(),
                        GetLskImageID(),
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        currEmsObjectDisplayListState,
                        currMaxEmsObjectList,
                        NULL,
                        preDefinedObjectIds,
                        userDefinedObjectDataPtrs,
                        (PS32) & currObjectListHiliteIndex,
                        guiBuffer);
                    RegisterLskAndRightArrowHandler();
                    RegisterEndKeyForPreviewEmsObjectScrnHandler();
                    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                }
                else
                {
                    restore_small_screen();
            #endif /* UI_SMALL_IMAGE_SELECTOR_SCREEN */ 
                    EntryNewScreen(SCR_ID_MSG_EMS_OBJECT_LIST, ExitEMSObjectList, EntryEMSObjectList, NULL);
                    RegisterHighlightHandler(GetEmsObjectHiliteIndex);
                    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_EMS_OBJECT_LIST);
                    if (guiBuffer != NULL)
                    {
                        change_list_menu_category_history(
                            guiBuffer,
                            currObjectListHiliteIndex,
                            currMaxEmsObjectList,
                            0);
                    }
                    else
                    {
                        currObjectListHiliteIndex = 0;
                    }
                    SetMessagesCurrScrnID(SCR_ID_MSG_EMS_OBJECT_LIST);
                    ShowCategory53Screen(
                        STR_EMS_OBJECT_LIST,
                        IMG_SMS_ENTRY_SCRN_CAPTION,
                        lskStrID,
                        IMG_GLOBAL_OK,
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        currMaxEmsObjectList,
                        (U8 **) strItemList,
                        imgItemList,
                        (U8 **) popUpList,
                        0,
                        currObjectListHiliteIndex,
                        guiBuffer);
                    SetLeftSoftkeyFunction(EntryScrPreviewEmsObject, KEY_EVENT_UP);
                    SetKeyHandler(EntryScrPreviewEmsObject, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                #ifdef UI_SMALL_IMAGE_SELECTOR_SCREEN
                }
                #endif 
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_EMPTY),
                    IMG_GLOBAL_EMPTY,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) EMPTY_LIST_TONE);
            }
            break;
        #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)        /* 041205 Calvin modified */
        case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
        {
            MMI_ID_TYPE *imglist = (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE) ?
                EMS_predefined_images : EMS_predefined_animations;
            MMI_ID_TYPE *strlist = (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE) ?
                ManufacturerPictureStrIDs : PredefinedAnimationStrIDs;
            S32 objectcount = (currEmsObjectDisplayListState == EMS_OBJECT_PICTURE_STATE) ?
                EmsPictureNum() : MAX_EMS_PREDEFINED_ANIMATION;
            EntryNewScreen(SCR_ID_MSG_EMS_OBJECT_LIST, mmi_msg_exit_generic, EntryEMSObjectList, NULL);
            guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_EMS_OBJECT_LIST);
            if (guiBuffer == NULL)
            {
                currObjectListHiliteIndex = 0;
            }
            SetMessagesCurrScrnID(SCR_ID_MSG_EMS_OBJECT_LIST);
            RegisterHighlightHandler(GetEmsObjectHiliteIndex);
            ShowCategoryEMSScreen(
                STR_EMS_OBJECT_LIST,
                IMG_SMS_ENTRY_SCRN_CAPTION,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                objectcount,
                imglist,
                strlist,
                currObjectListHiliteIndex,
                guiBuffer);
            SetLeftSoftkeyFunction(PreviewEmsObjectIsDone, KEY_EVENT_UP);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        }
            break;
        #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitEMSObjectList
 * DESCRIPTION
 *  Exit object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEMSObjectList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* history currHistory; */
    currObjectListHiliteIndex = GetHighlightedItem();
    StopEmsObjectIMelodyAndSoundIfAny();
    /* currHistory.scrnID = SCR_ID_MSG_EMS_OBJECT_LIST; */
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_EMS_OBJECT_LIST;
    //currHistory.entryFuncPtr = EntryEMSObjectList;
    //memset (currHistory.inputBuffer, 0, ENCODING_LENGTH);
    //GetCategoryHistory (currHistory.guiBuffer);
    //AddHistory (currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  RegisterLskAndRightArrowHandler
 * DESCRIPTION
 *  Register LSK handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void RegisterLskAndRightArrowHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(PreviewEmsObjectIsDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  RegisterEndKeyForPreviewEmsObjectScrnHandler
 * DESCRIPTION
 *  Register End key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void RegisterEndKeyForPreviewEmsObjectScrnHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  GetLskStringID
 * DESCRIPTION
 *  Get LSK string
 * PARAMETERS
 *  void
 * RETURNS
 *  LSK string
 *****************************************************************************/
static U16 GetLskStringID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return STR_GLOBAL_OK;
}


/*****************************************************************************
 * FUNCTION
 *  GetLskImageID
 * DESCRIPTION
 *  Get LSK image
 * PARAMETERS
 *  void
 * RETURNS
 *  LSK image
 *****************************************************************************/
static U16 GetLskImageID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IMG_GLOBAL_OK;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrPreviewEmsObject
 * DESCRIPTION
 *  Entry preview object screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrPreviewEmsObject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 objectType = 0;
    U8 *guiBuffer = NULL;
    U8 isPictureOrAnimation = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_PICTURE_STATE:
            objectType = EMS_PREDEFINED_PICTURE;
            isPictureOrAnimation = TRUE;
            break;
        case EMS_OBJECT_MY_PICTURE_STATE:
            objectType = EMS_USERDEFINED_PICTURE;
            isPictureOrAnimation = TRUE;
            break;
        case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
            objectType = EMS_PREDEFINED_ANIMATION;
            isPictureOrAnimation = TRUE;
            break;
        case EMS_OBJECT_MY_ANIMATION_STATE:
            objectType = EMS_USERDEFINED_ANIMATION;
            isPictureOrAnimation = TRUE;
            break;
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            objectType = EMS_PREDEFINED_MELODY | CATEGORY144_DISABLE_PREVIEW;
            isPictureOrAnimation = FALSE;
            break;
        case EMS_OBJECT_MY_MELODY_STATE:
            objectType = EMS_USERDEFINED_MELODY | CATEGORY144_DISABLE_PREVIEW;
            isPictureOrAnimation = FALSE;
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
            objectType = EMS_PREDEFINED_SOUND | CATEGORY144_DISABLE_PREVIEW;
            isPictureOrAnimation = FALSE;
            break;
    }
    if (isPictureOrAnimation == TRUE)
    {
        EntryNewScreen(SCR_ID_MSG_EMS_PREVIEW_OBJECT, mmi_msg_exit_generic, EntryScrPreviewEmsObject, NULL);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_EMS_PREVIEW_OBJECT);
        if (currEmsObjectDisplayListState == EMS_OBJECT_PREDEFINED_ANIMATION_STATE)
        {
            emsObjectNameWhenPreview = (U8*) GetString(PredefinedAnimationStrIDs[currObjectListHiliteIndex]);
            RegisterHighlightHandler(ChangeEmsObjectTitleWithIndex);
        }
        else
        {
            RegisterCategory144ObjectLoader(CallBackLoadUserDefinedObjectDataBuffPtr);
        }
        SetMessagesCurrScrnID(SCR_ID_MSG_EMS_PREVIEW_OBJECT);
        ShowCategory144Screen(
            emsObjectNameWhenPreview,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            GetLskStringID(),
            GetLskImageID(),
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            objectType,
            currMaxEmsObjectList,
            NULL,
            preDefinedObjectIds,
            FALSE,
            userDefinedObjectDataPtrs,
            (PS32) & currObjectListHiliteIndex,
            guiBuffer);
        RegisterLskAndRightArrowHandler();
        RegisterEndKeyForPreviewEmsObjectScrnHandler();
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        ExitCategoryFunction();
        RegisterCategory144ObjectLoader(CallBackLoadUserDefinedObjectDataBuffPtr);
        ShowCategory144Screen(
            (PU8) GetString(STR_PREVIEW_EMS_OBJECT),
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            objectType,
            currMaxEmsObjectList,
            NULL,
            preDefinedObjectIds,
            FALSE,
            userDefinedObjectDataPtrs,
            (PS32) & currObjectListHiliteIndex,
            guiBuffer);
        PreviewEmsObjectIsDone();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ChangeEmsObjectTitleWithIndex
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  index       [IN]        Object index
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeEmsObjectTitleWithIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    emsObjectNameWhenPreview = (U8*) GetString(PredefinedAnimationStrIDs[index]);
    ChangeTitleString(emsObjectNameWhenPreview);
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  GetEmsObjectHiliteIndex
 * DESCRIPTION
 *  Get object highlight index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void GetEmsObjectHiliteIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currObjectListHiliteIndex = index;
    switch (currEmsObjectDisplayListState)
    {
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
            EMSObjectStopPlayBack();
            if (ReadDownloadObjectDataFromFileSystem(index))
            {
                StartTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID, MESSAGES_ONE_SEC_TIME_OUT, PlayEmsManufacturerIMelody);
            }
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
            StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
            EMSObjectStopPlayBack();
            StartTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID, MESSAGES_ONE_SEC_TIME_OUT, PlayEmsManufacturerSound);
            break;
    }
}

/* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  PlayEmsManufacturerIMelody
 * DESCRIPTION
 *  Play manufacturer melody
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PlayEmsManufacturerIMelody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
    EMSObjectStopPlayBack();

    if (!IsSilentModeActivated())
#ifdef __MMI_SILENT_MEETING_PROFILE__
        if (!IsMeetingModeActivated())
#endif 
            EMSObjectPlayback(EMS_PREDEFINED_MELODY, userDefinedObjectDataBuff, -1);
}
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  PlayEmsManufacturerSound
 * DESCRIPTION
 *  Play manufacturer sound
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PlayEmsManufacturerSound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
    EMSObjectStopPlayBack();

    if (!IsSilentModeActivated())
#ifdef __MMI_SILENT_MEETING_PROFILE__
        if (!IsMeetingModeActivated())
#endif 
            EMSObjectPlayback(EMS_PREDEFINED_SOUND, NULL, currObjectListHiliteIndex);
}


/*****************************************************************************
 * FUNCTION
 *  StopEmsObjectIMelodyAndSoundIfAny
 * DESCRIPTION
 *  Stop melody/sound
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopEmsObjectIMelodyAndSoundIfAny(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currEmsObjectDisplayListState)
    {
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MELODY_STATE:
            StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
            EMSObjectStopPlayBack();
            break;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        case EMS_OBJECT_PREDEFINED_SOUND_STATE:
            StopTimer(MESSAGES_EMS_OBJECT_PLAY_TIMER_ID);
            EMSObjectStopPlayBack();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PreviewEmsObjectIsDone
 * DESCRIPTION
 *  After preview, add object to message body
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreviewEmsObjectIsDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((currEmsObjectDisplayListState != EMS_OBJECT_PREDEFINED_ANIMATION_STATE) &&
        (currEmsObjectDisplayListState != EMS_OBJECT_PREDEFINED_SOUND_STATE) &&
        (!listOfIsAllowedData[currObjectListHiliteIndex]))
    {
        DisplayPopup(
            (PU8) GetString(STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    else
    {
        switch (currEmsObjectDisplayListState)
        {
            case EMS_OBJECT_PICTURE_STATE:
                emsObjectStatus = EMS_inputbox_insert_predefined_picture(currObjectListHiliteIndex);
                break;
            case EMS_OBJECT_MY_PICTURE_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_picture(userDefinedObjectDataBuff);
                break;
            case EMS_OBJECT_PREDEFINED_ANIMATION_STATE:
                emsObjectStatus = EMS_inputbox_insert_predefined_animation(currObjectListHiliteIndex);
                break;
            case EMS_OBJECT_MY_ANIMATION_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_animation(userDefinedObjectDataBuff);
                break;
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MELODY_STATE:
                emsObjectStatus = EMS_inputbox_insert_predefined_melody(currObjectListHiliteIndex);
                break;
            case EMS_OBJECT_MY_MELODY_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_melody(userDefinedObjectDataBuff);
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            case EMS_OBJECT_PREDEFINED_SOUND_STATE:
                emsObjectStatus = EMS_inputbox_insert_predefined_sound(currObjectListHiliteIndex);
                break;
            default:
                emsObjectStatus = EMS_inputbox_insert_predefined_picture(currObjectListHiliteIndex);
                break;
        }

        GoBackToHistory(SCR_ID_MSG_WRITE);
        ErrorHandlingWhileInsertingObject(emsObjectStatus); /* check whetehr it is inserted or not. */
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrInsertObjectMenu
 * DESCRIPTION
 *  Entry insert object screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrInsertObjectMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems = 0;
    PU8 guiBuffer = NULL;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_EMS_INSERT_OBJECT, mmi_msg_exit_generic, EntryScrInsertObjectMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_EMS_INSERT_OBJECT);
    SetParentHandler(EMS_ED_OPT_INS_OBJ);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    numItems = GetNumOfChild(EMS_ED_OPT_INS_OBJ);
    GetSequenceStringIds(EMS_ED_OPT_INS_OBJ, nStrItemList);
    SetMessagesCurrScrnID(SCR_ID_MSG_EMS_INSERT_OBJECT);
    ShowCategory52Screen(
        STR_OPT_INS_OBJECT_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEditOptionInsertObject
 * DESCRIPTION
 *  Highlight insert object handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEditOptionInsertObject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryScrInsertObjectMenu, KEY_EVENT_UP);
    SetKeyHandler(EntryScrInsertObjectMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightInsObjPicture
 * DESCRIPTION
 *  Highlight insert picture handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInsObjPicture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryEMSObjectList, KEY_EVENT_UP);
    SetKeyHandler(EntryEMSObjectList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    currEmsObjectDisplayListState = EMS_OBJECT_PICTURE_STATE;
    currObjectListHiliteIndex = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightInsObjMyPicture
 * DESCRIPTION
 *  Highlight insert my picture handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInsObjMyPicture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryEMSObjectList, KEY_EVENT_UP);
    SetKeyHandler(EntryEMSObjectList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    currEmsObjectDisplayListState = EMS_OBJECT_MY_PICTURE_STATE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightInsObjPredefinedAnimation
 * DESCRIPTION
 *  Highlight insert predefined animation handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInsObjPredefinedAnimation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryEMSObjectList, KEY_EVENT_UP);
    SetKeyHandler(EntryEMSObjectList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    currEmsObjectDisplayListState = EMS_OBJECT_PREDEFINED_ANIMATION_STATE;
    currMaxEmsObjectList = MAX_EMS_PREDEFINED_ANIMATION;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightInsObjMyAnimation
 * DESCRIPTION
 *  Highlight insert my animation handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInsObjMyAnimation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryEMSObjectList, KEY_EVENT_UP);
    SetKeyHandler(EntryEMSObjectList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    currEmsObjectDisplayListState = EMS_OBJECT_MY_ANIMATION_STATE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightInsObjMelody
 * DESCRIPTION
 *  Highlight insert melody handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK Joy added for customization, 1014 */
#if defined(__MMI_IMELODY_SUPPORT__)
void HighlightInsObjMelody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryEMSObjectList, KEY_EVENT_UP);
    SetKeyHandler(EntryEMSObjectList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    currEmsObjectDisplayListState = EMS_OBJECT_MELODY_STATE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightInsObjMyMelody
 * DESCRIPTION
 *  Highlight insert my melody handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInsObjMyMelody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryEMSObjectList, KEY_EVENT_UP);
    SetKeyHandler(EntryEMSObjectList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    currEmsObjectDisplayListState = EMS_OBJECT_MY_MELODY_STATE;
}
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
/* MTK end */


/*****************************************************************************
 * FUNCTION
 *  HighlightInsObjPredefinedSound
 * DESCRIPTION
 *  Highlight insert predefined sound handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInsObjPredefinedSound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(EntryEMSObjectList, KEY_EVENT_UP);
    SetKeyHandler(EntryEMSObjectList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    currEmsObjectDisplayListState = EMS_OBJECT_PREDEFINED_SOUND_STATE;
}

#if (defined(__MMI_FILE_MANAGER__))


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_add_object_from_fm
 * DESCRIPTION
 *  Add object from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_add_object_from_fm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    userDefinedObjectDataSize = GetEmsObjectDataSize();
    if (IsAllowed == TRUE)
    {
        switch (currEmsObjectDisplayListState)
        {
            case EMS_OBJECT_MY_PICTURE_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_picture(userDefinedObjectDataBuff);
                break;
            case EMS_OBJECT_MY_ANIMATION_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_animation(userDefinedObjectDataBuff);
                break;
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MY_MELODY_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_melody(userDefinedObjectDataBuff);
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            default:
                emsObjectStatus = EMS_inputbox_insert_userdefined_picture(userDefinedObjectDataBuff);
                break;
        }
        GoBackToHistory(SCR_ID_MSG_WRITE);
        ErrorHandlingWhileInsertingObject(emsObjectStatus);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_go_back_from_preview_object
 * DESCRIPTION
 *  clear screen for file manager preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_go_back_from_preview_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_MSG_EMS_INSERT_OBJECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_entry_preview_object_from_fm
 * DESCRIPTION
 *  Entry preview object screen from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_entry_preview_object_from_fm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 objectType = 0;
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_EMS_PREVIEW_OBJECT, mmi_msg_exit_generic, mmi_ems_entry_preview_object_from_fm, NULL);
    switch (currEmsObjectDisplayListState)
    {
        case EMS_OBJECT_MY_PICTURE_STATE:
            objectType = EMS_USERDEFINED_PICTURE;
            break;
        case EMS_OBJECT_MY_ANIMATION_STATE:
            objectType = EMS_USERDEFINED_ANIMATION;
            break;
    #if defined(__MMI_IMELODY_SUPPORT__)
        case EMS_OBJECT_MY_MELODY_STATE:
            objectType = EMS_USERDEFINED_MELODY;
    #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            break;
    }
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_EMS_PREVIEW_OBJECT);
    SetMessagesCurrScrnID(SCR_ID_MSG_EMS_PREVIEW_OBJECT);

    emsObjectNameWhenPreview = (U8*) GetString(STR_PREVIEW_EMS_OBJECT);
    currObjectListHiliteIndex = 0;
    userDefinedObjectDataPtrs[0] = userDefinedObjectDataBuff;
    EnableDisableAudioPlayback();
    ShowCategory144Screen(
        emsObjectNameWhenPreview,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        objectType,
        1,
        NULL,
        preDefinedObjectIds,
        FALSE,
        userDefinedObjectDataPtrs,
        (PS32) & currObjectListHiliteIndex,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_ems_add_object_from_fm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ems_go_back_from_preview_object, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_preview_object_from_fm
 * DESCRIPTION
 *  Preview object from file manager
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_preview_object_from_fm(PU16 filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath == NULL)
    {
        GoBackToHistory(SCR_ID_MSG_EMS_INSERT_OBJECT);
        return;
    }
    emsObjectStatus = mmi_ems_fm_open_file((S8*) filePath, currEmsObjectDisplayListState);
    if (emsObjectStatus != EMS_OK)
    {
        ErrorHandlingWhileInsertingObject(emsObjectStatus);
        DeleteUptoScrID(SCR_ID_MSG_EMS_INSERT_OBJECT);
        return;
    }
    else
    {
        mmi_ems_entry_preview_object_from_fm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_fm_open_file
 * DESCRIPTION
 *  Open file
 * PARAMETERS
 *  emsObjectFileNameBuf        [IN]        File name
 *  emsObjectType               [IN]        Object type
 * RETURNS
 *  TRUE: open success, FALSE: open fail
 *****************************************************************************/
EMSTATUS mmi_ems_fm_open_file(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 errorCode = 0;
    FS_HANDLE emsObjectFilePtr = 0;
    U32 read_size = 0;
    U32 file_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MemsetUserDefinedObjectDataBuff();
    emsObjectFilePtr = FS_Open((U16*)emsObjectFileNameBuf, FS_READ_ONLY);
    if (emsObjectFilePtr > 0)
    {
        FS_GetFileSize(emsObjectFilePtr, &file_size);
        userDefinedObjectDataSize = file_size;
        switch (emsObjectType)
        {
        #if defined(__MMI_IMELODY_SUPPORT__)    /* Pending work here ...abt hint for over sized.. */
            case EMS_OBJECT_MY_MELODY_STATE:
                if (userDefinedObjectDataSize > MAX_EMS_OBJECT_INSERT_SIZE /* 128 bytes */ )
                {
                    FS_Close(emsObjectFilePtr);
                    return EMS_EMS_DATA_EXCEEDED;
                }
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
            default:
                if (userDefinedObjectDataSize > MAX_CURR_EMS_OBJECT_DATA_BUFF /* bytes */ )
                {
                    FS_Close(emsObjectFilePtr);
                    return EMS_EMS_DATA_EXCEEDED;
                }
        }
        errorCode = FS_Read( emsObjectFilePtr, userDefinedObjectDataBuff, userDefinedObjectDataSize, &read_size);
        FS_Close(emsObjectFilePtr);
        if (errorCode < 0)
        {
            return EMS_UNSPECIFIED_ERROR;
        }
        switch (emsObjectType)
        {
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MY_MELODY_STATE:
            {
                U8 userDefinedObjectDataBuffTemp[MAX_CURR_EMS_OBJECT_DATA_BUFF];

                EMS_userdefined_melody_attach_header(
                    userDefinedObjectDataBuff,
                    userDefinedObjectDataBuffTemp,
                    &userDefinedObjectDataSize);
                memcpy(userDefinedObjectDataBuff, userDefinedObjectDataBuffTemp, userDefinedObjectDataSize);
            }
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        }
        return EMS_OK;
    }
    return EMS_UNSPECIFIED_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_fm_send_by_ems
 * DESCRIPTION
 *  Send by EMS from file manager
 * PARAMETERS
 *  emsObjectFileNameBuf        [IN]        File name
 *  emsObjectType               [IN]        Object type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ems_fm_send_by_ems(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS emsObjectStatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currEmsObjectDisplayListState = emsObjectType;
    g_msg_cntx.number_from_phb = 0;

    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    emsObjectStatus = mmi_ems_fm_open_file(emsObjectFileNameBuf, emsObjectType);
    if (emsObjectStatus != EMS_OK)
    {
        ErrorHandlingWhileInsertingObject(emsObjectStatus);
        return;
    }
    GetEmsObjectDataSize();
    if (!IsAllowed)
    {
        DisplayPopup(
            (PU8) GetString(STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    else
    {
        EMSTATUS emsObjectStatus = EMS_UNSPECIFIED_ERROR;

    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
    #endif 
        GetEMSDataForEdit(0, 1);    /* Force init */
        g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;
        mmi_msg_entry_write_msg();
        switch (emsObjectType)
        {
            case EMS_OBJECT_MY_PICTURE_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_picture(userDefinedObjectDataBuff);
                break;
            case EMS_OBJECT_MY_ANIMATION_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_animation(userDefinedObjectDataBuff);
                break;
        #if defined(__MMI_IMELODY_SUPPORT__)
            case EMS_OBJECT_MY_MELODY_STATE:
                emsObjectStatus = EMS_inputbox_insert_userdefined_melody(userDefinedObjectDataBuff);
                break;
        #endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
        }
        handle_category28_input();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
    #endif 
    #ifdef __MMI_T9__
        switch (MMI_current_input_type & INPUT_TYPE_MASK)
        {
            case INPUT_TYPE_TR_BOPOMO:
            case INPUT_TYPE_SM_PINYIN:
            case INPUT_TYPE_TR_STROKE:
            case INPUT_TYPE_SM_STROKE:
            case INPUT_TYPE_SMART_UPPERCASE_ABC:
            case INPUT_TYPE_SMART_LOWERCASE_ABC:
            case INPUT_TYPE_TR_MULTITAP_BOPOMO:
            case INPUT_TYPE_SM_MULTITAP_PINYIN:
                /* PMT dara added for t9 thai */
        #if defined(__MMI_T9_THAI__)
            case INPUT_TYPE_SMART_THAI:
        #endif 

                /* PMT NO_AR_SL_DU START 20050909 */
        #if defined(__MMI_T9_ARABIC__)
            case INPUT_TYPE_SMART_ARABIC:
        #endif 
                /* PMT VIKAS GUPTA START 20051129 */
        #if defined(__MMI_T9_HINDI__)
            case INPUT_TYPE_SMART_HINDI:
        #endif 
                //PMT VIKAS GUPTA END 20051129
                //PMT NO_AR_SL_DU END 20050909
                //MTK Terry for Spanish French German Italian
        #if defined(__MMI_T9_SPANISH__)
            case INPUT_TYPE_SMART_UPPERCASE_SPANISH:
            case INPUT_TYPE_SMART_LOWERCASE_SPANISH:
        #endif /* defined(__MMI_T9_SPANISH__) */ 
                /* PMT VIKASG START 20050729 */
        #if defined(__MMI_T9_DANISH__)  /* Vikas */
            case INPUT_TYPE_SMART_UPPERCASE_DANISH:
            case INPUT_TYPE_SMART_LOWERCASE_DANISH:
        #endif /* defined(__MMI_T9_DANISH__) */ 
                //PMT VIKASG END 20050729
                //PMT CZ_PO_TU START 20050812   
        #if defined(__MMI_T9_POLISH__)  /* Vikas */
            case INPUT_TYPE_SMART_UPPERCASE_POLISH:
            case INPUT_TYPE_SMART_LOWERCASE_POLISH:
        #endif /* defined(__MMI_T9_POLISH__) */ 
                /* PMT CZ_PO_TU END 20050812 */
        #if defined(__MMI_T9_FRENCH__)
            case INPUT_TYPE_SMART_UPPERCASE_FRENCH:
            case INPUT_TYPE_SMART_LOWERCASE_FRENCH:
        #endif /* defined(__MMI_T9_FRENCH__) */ 
        #if defined(__MMI_T9_GERMAN__)
            case INPUT_TYPE_SMART_UPPERCASE_GERMAN:
            case INPUT_TYPE_SMART_LOWERCASE_GERMAN:
        #endif /* defined(__MMI_T9_GERMAN__) */ 
        #if defined(__MMI_T9_ITALIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_ITALIAN:
            case INPUT_TYPE_SMART_LOWERCASE_ITALIAN:
        #endif /* defined(__MMI_T9_ITALIAN__) */ 

                /* PMT BHASKAR START 20052907 */

        #if defined(__MMI_T9_VIETNAMESE__)
            case INPUT_TYPE_SMART_UPPERCASE_VIETNAMESE:
            case INPUT_TYPE_SMART_LOWERCASE_VIETNAMESE:
        #endif /* defined(__MMI_T9_VIETNAMESE__) */ 

                /* PMT BHASKAR END 20052907 */

                /* PMT Gurdev Start 20050729 */
        #if defined(__MMI_T9_INDONESIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_INDONESIAN:
            case INPUT_TYPE_SMART_LOWERCASE_INDONESIAN:
        #endif /* defined(__MMI_T9_INDONESIAN__) */ 
                //PMT Gurdev End 20050729
                //PMT CZ_PO_TU START 20050812   
        #if defined(__MMI_T9_CZECH__)
            case INPUT_TYPE_SMART_UPPERCASE_CZECH:
            case INPUT_TYPE_SMART_LOWERCASE_CZECH:
        #endif /* defined(__MMI_T9_CZECH__) */ 
                //PMT CZ_PO_TU END 20050812     
                //PMT CZ_PO_TU START 20050812    
        #if defined(__MMI_T9_TURKISH__)
            case INPUT_TYPE_SMART_UPPERCASE_TURKISH:
            case INPUT_TYPE_SMART_LOWERCASE_TURKISH:
        #endif /* defined(__MMI_T9_TURKISH__) */ 
                /* PMT CZ_PO_TU END 20050812 */

                /* START PMT VANDANA 20051506 */
        #if defined(__MMI_T9_RUSSIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_RUSSIAN:
            case INPUT_TYPE_SMART_LOWERCASE_RUSSIAN:
        #endif /* defined(__MMI_T9_RUSSIAN__) */ 
                //END PMT
                //MTK end

                /* PMT BULGARIAN START 20051201 */
        #if defined(__MMI_T9_BULGARIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_BULGARIAN:
            case INPUT_TYPE_SMART_LOWERCASE_BULGARIAN:
        #endif /* defined(__MMI_T9_BULGARIAN__) */ 
                //PMT BULGARIAN END 20051201
                //PMT SHARIQ START 20050729
        #if defined(__MMI_T9_PORTUGUESE__)
            case INPUT_TYPE_SMART_UPPERCASE_PORTUGUESE:
            case INPUT_TYPE_SMART_LOWERCASE_PORTUGUESE:
        #endif /* defined(__MMI_T9_PORTUGUESE__) */ 
                /* PMT SHARIQ END 20050729 */

                /* PMT START HU_FI 20050825 */
        #if defined(__MMI_T9_FINNISH__)
            case INPUT_TYPE_SMART_UPPERCASE_FINNISH:
            case INPUT_TYPE_SMART_LOWERCASE_FINNISH:
        #endif /* defined(__MMI_T9_FINNISH__) */ 
        #if defined(__MMI_T9_HUNGARIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_HUNGARIAN:
            case INPUT_TYPE_SMART_LOWERCASE_HUNGARIAN:
        #endif /* defined(__MMI_T9_HUNGARIAN__) */ 
                //PMT END HU_FI 20050825
                //PMT NO_AR_SL_DU START 20050909
                //Norwegian start
        #if defined(__MMI_T9_NORWEGIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_NORWEGIAN:
            case INPUT_TYPE_SMART_LOWERCASE_NORWEGIAN:
        #endif /* defined(__MMI_T9_NORWEGIAN__) */ 
                //Norwegian end
                //START DUTCH_T9 20051021
        #if defined(__MMI_T9_DUTCH__)
            case INPUT_TYPE_SMART_UPPERCASE_DUTCH:
            case INPUT_TYPE_SMART_LOWERCASE_DUTCH:
        #endif /* defined(__MMI_T9_DUTCH__) */ 
                //END DUTCH_T9 20051021
                //PMT NO_AR_SL_DU END 20050909
                //PMT LANGUAGE START 20051221
        #if defined(__MMI_T9_SLOVENIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_SLOVENIAN:
            case INPUT_TYPE_SMART_LOWERCASE_SLOVENIAN:
        #endif /* defined(__MMI_T9_SLOVENIAN__) */ 
        #if defined(__MMI_T9_SWEDISH__)
            case INPUT_TYPE_SMART_UPPERCASE_SWEDISH:
            case INPUT_TYPE_SMART_LOWERCASE_SWEDISH:
        #endif /* defined(__MMI_T9_SWEDISH__) */ 
                /* PMT SLO_SWE END 20051213 */
        #if defined(__MMI_T9_GREEK__)
            case INPUT_TYPE_SMART_UPPERCASE_GREEK:
            case INPUT_TYPE_SMART_LOWERCASE_GREEK:
        #endif /* defined(__MMI_T9_GREEK__) */ 
        #if defined(__MMI_T9_HEBREW__)
            case INPUT_TYPE_SMART_HEBREW:

        #endif /* defined(__MMI_T9_HEBREW__) */ 
                //PMT LANGUAGE END 20051221
                //PMT START LANGUAGE 20060104
        #if defined(__MMI_T9_CROATIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_CROATIAN:
            case INPUT_TYPE_SMART_LOWERCASE_CROATIAN:
        #endif /* defined(__MMI_T9_CROATIAN__) */ 
        #if defined(__MMI_T9_MALAY__)
            case INPUT_TYPE_SMART_UPPERCASE_MALAY:
            case INPUT_TYPE_SMART_LOWERCASE_MALAY:
        #endif /* defined(__MMI_T9_MALAY__) */ 
        #if defined(__MMI_T9_SLOVAK__)
            case INPUT_TYPE_SMART_UPPERCASE_SLOVAK:
            case INPUT_TYPE_SMART_LOWERCASE_SLOVAK:
        #endif /* defined(__MMI_T9_SLOVAK__) */ 
        #if defined(__MMI_T9_ROMANIAN__)
            case INPUT_TYPE_SMART_UPPERCASE_ROMANIAN:
            case INPUT_TYPE_SMART_LOWERCASE_ROMANIAN:
        #endif /* defined(__MMI_T9_ROMANIAN__) */ 
                /* PMT END LANGUAGE 20060104 */
                T9SynT9WithInputBox();
                break;
        }
    #endif /* __MMI_T9__ */ 
        dm_redraw_category_screen();
        ErrorHandlingWhileInsertingObject(emsObjectStatus); /* check whetehr it is inserted or not. */
    }
}

/* MTk end */
#endif /* (defined(__MMI_FILE_MANAGER__)) */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScrSaveObjectList
 * DESCRIPTION
 *  Entry save object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSaveObjectList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    EMSData *pEms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SAVE_OBJECT_LIST);
    if (guiBuffer == NULL)
    {
        currObjectIndex = 0;
    }
    CreateCategory143ObjectList(GetEMSDataForView(&pEms, 0), &previewObjectListPtr);
    if (previewObjectListPtr != NULL)
    {
        EntryNewScreen(SCR_ID_MSG_SAVE_OBJECT_LIST, ExitScrSaveObjectList, NULL, NULL);
        EnableDisableAudioPlayback();
        ShowCategory143Screen(
            STR_EMS_OBJECT_LIST,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            previewObjectListPtr,
            &nObjectLists,
            &currObjectIndex,
            guiBuffer);

        SetLeftSoftkeyFunction(PreEntryScrSaveObjectName, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(PreEntryScrSaveObjectName, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrSaveObjectList
 * DESCRIPTION
 *  Exit save object list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrSaveObjectList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeCategory143ObjectList(&previewObjectListPtr);
    currHistory.scrnID = SCR_ID_MSG_SAVE_OBJECT_LIST;
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_SAVE_OBJECT_LIST;
    currHistory.entryFuncPtr = EntryScrSaveObjectList;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & ucs2InputBuffer);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  PreEntryScrSaveObjectName
 * DESCRIPTION
 *  Before entry save object name, get object type and size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryScrSaveObjectName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FreeUserEmsObjectNameInputBuff();
    MemsetUserDefinedObjectDataBuff();
    SetCurrEmsObjectDisplayListState(GetCategory143DataType());
    userDefinedObjectDataSize = GetCategory143DataSize();
#if defined(__MMI_IMELODY_SUPPORT__)
    if (currEmsObjectDisplayListState == EMS_OBJECT_MY_MELODY_STATE)
    {
        U8 userDefinedObjectDataBuffTemp[MAX_CURR_EMS_OBJECT_DATA_BUFF];

        GetCategory143Data(userDefinedObjectDataBuffTemp);
        EMS_userdefined_melody_detach_header(
            userDefinedObjectDataBuffTemp,
            userDefinedObjectDataBuff,
            &userDefinedObjectDataSize);
    }
    else
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
    {
        GetCategory143Data(userDefinedObjectDataBuff);
    }
    EntryScrSaveObjectName();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrSaveObjectName
 * DESCRIPTION
 *  Entry save object name screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSaveObjectName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SAVE_OBJECT_NAME, mmi_msg_exit_generic, EntryScrSaveObjectName, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SAVE_OBJECT_NAME);
    /* SetMessagesScrnIdToDelHistoryNodes (SCR_ID_MSG_SAVE_OBJECT_NAME); */
    ShowCategory5Screen(
        STR_EMS_OBJECT_NAME,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (PU8) userEmsObjectNameInput,
        MAX_EMS_DOWNLOAD_OBJECT_NAME_LEN,
        guiBuffer);
    SetLeftSoftkeyFunction(EntryEmsSaveObjectOption, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmsSaveObjectOption
 * DESCRIPTION
 *  Entry save object option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmsSaveObjectOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems = 0;
    U8 *guiBuffer = NULL;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_SAVE_OBJECT_OPTION, mmi_msg_exit_generic, EntryEmsSaveObjectOption, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_SAVE_OBJECT_OPTION);
    SetParentHandler(SMS_INBOX_OPT_SAVE_OBJECT_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    numItems = GetNumOfChild(SMS_INBOX_OPT_SAVE_OBJECT_OPTION);
    GetSequenceStringIds(SMS_INBOX_OPT_SAVE_OBJECT_OPTION, nStrItemList);
    SetMessagesCurrScrnID(SCR_ID_MSG_SAVE_OBJECT_OPTION);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  SaveEmsObjectNameAndDownLoadEmsObject
 * DESCRIPTION
 *  Save object name and data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveEmsObjectNameAndDownLoadEmsObject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS saveResult;
    S32 create_directory_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_directory_result = mmi_ems_create_ems_folder();

    /* Create folder success */
    if (create_directory_result == FS_FILE_EXISTS || create_directory_result == FS_NO_ERROR)
    {

        saveResult = WriteDownloadObjectDataIntoFileSystem();
        ErrorHandlingWhileSavingObject(saveResult);
        if (saveResult != EMS_ALREADY_INITIALIZED &&
            saveResult != EMS_INVALID_FILE_NAME && saveResult != EMS_EMPTY_FILE_NAME)
        {
            DeleteUptoScrID(SCR_ID_MSG_SAVE_OBJECT_LIST);
            FreeUserEmsObjectNameInputBuff();
        }
        else
        {
            DeleteUptoScrID(SCR_ID_MSG_SAVE_OBJECT_NAME);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(create_directory_result)),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteUptoScrID(SCR_ID_MSG_SAVE_OBJECT_NAME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmsSaveObjectDone
 * DESCRIPTION
 *  Highlight save object done handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmsSaveObjectDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_SMS_COMMON_NOIMAGE);
    SetLeftSoftkeyFunction(SaveEmsObjectNameAndDownLoadEmsObject, KEY_EVENT_UP);
    SetKeyHandler(SaveEmsObjectNameAndDownLoadEmsObject, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ems_create_ems_folder
 * DESCRIPTION
 *  Create EMS object folder in boot up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_ems_create_ems_folder(void)
{
#if (defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 emsObjectFileNameBuf[(MAX_EMS_DOWNLOAD_OBJECT_NAME_INIT_PATH + 1) * ENCODING_LENGTH] = {0, 0};
    U16 driveName;
    S8 temp[4];
    S32 result = FS_NO_ERROR;
    UI_character_type dir_ems_root[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    driveName = MMI_PUBLIC_DRV;
    sprintf(temp, "%c:\\", (S8) driveName);
    mmi_asc_to_ucs2((S8*) dir_ems_root, temp);

    memset(emsObjectFileNameBuf, 0, ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
    mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
    FS_CreateDir((U16*)emsObjectFileNameBuf);

    memset(emsObjectFileNameBuf, 0, ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) emsObjectFileNameBuf, (S8*) dir_ems_root);
    mmi_ucs2cat((S8*) emsObjectFileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);
    result = FS_CreateDir((U16*)emsObjectFileNameBuf);
#else /* (defined(__MMI_FILE_MANAGER__)) */ 

    U8 *file_name = OslMalloc((MAX_EMS_STR_FOLDER_LEN + 1) * ENCODING_LENGTH);
    S32 result = 0;
    FS_HANDLE fh = 0;
    
#if (0)
/* under construction !*/
/* under construction !*/
#endif /* #if(0) */

    memset(file_name, 0, (MAX_EMS_STR_FOLDER_LEN + 1) * ENCODING_LENGTH);

    fh = FS_Open((U16*)MessagesGetString((S8*) STR_EMS_PIC_A_ANIM_OBJECT_FILE_NAME_INIT_PATH_ID), 
    		 FS_OPEN_DIR|FS_READ_ONLY);
    
    if (fh < 0)
    {
        mmi_ucs2cpy((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_USER_FOLDER_ID));
        FS_CreateDir((U16*)file_name); /* the api does not support recursive creation */
        mmi_ucs2cat((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_IMAGE_FOLDER_ID));
        FS_CreateDir((U16*)file_name);
        mmi_ucs2cat((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_FOLDER_ID));
        FS_CreateDir((U16*)file_name);        
    }
    else
    {
        FS_Close(fh);
    }

    memset(file_name, 0, (MAX_EMS_STR_FOLDER_LEN + 1) * ENCODING_LENGTH);

    fh = FS_Open((U16*)MessagesGetString((S8*) STR_EMS_IMELODY_OBJECT_FILE_NAME_INIT_PATH_ID), 
    		 FS_OPEN_DIR|FS_READ_ONLY);
    
    if (fh < 0)
    {
        mmi_ucs2cpy((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_USER_FOLDER_ID));
        FS_CreateDir((U16*)file_name); /* the api does not support recursive creation */
        mmi_ucs2cat((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_IMELODY_FOLDER_ID));
        FS_CreateDir((U16*)file_name);
        mmi_ucs2cat((S8*)file_name, (S8*)MessagesGetString((S8*)STR_EMS_FOLDER_ID));
        FS_CreateDir((U16*)file_name);        
    }
    else
    {
        FS_Close(fh);
    }

    OslMfree(file_name);

#endif /* (defined(__MMI_FILE_MANAGER__)) */ 

    return result;
}

#endif /* defined(__MMI_MESSAGES_EMS__) */ 

#endif /* __MOD_SMSAL__ */ 

