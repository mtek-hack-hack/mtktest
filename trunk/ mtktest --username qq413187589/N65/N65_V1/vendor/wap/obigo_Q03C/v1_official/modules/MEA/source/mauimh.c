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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*!\file mauimh.c
 * \brief Functions for implemention the GUI handling for the MH.
 */

/* MSF includes */
#include "msf_wid.h"
#include "msf_def.h"
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_cfg.h"
#ifdef WAP_SUPPORT
#include "msf_mem.h" /* For mamem.h */
#endif
#include "msf_chrs.h"
#include "msf_file.h" /* For MSF_FILE_GETSIZE */

/* MMS Service includes */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#ifdef WAP_SUPPORT
#include "mmsl_if.h"
#include "msig.h"
#include "fldmgr.h"
#include "mms_aApp.h"	/* For USE Number and IsReachMEAMaxNumofMsg */
#include "mutils.h" /* For freeMmsGetHeader */
#include "mcpdu.h"
#include "mlfieldp.h" /* For parseEncodedStringValue */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA includes */
#include "mea_rc.h"
#include "mea_cfg.h" //for MEA_SIG_TEXT_FILE
#include "matypes.h"
#include "maintsig.h"
#include "maconf.h"
#include "mamh.h"
#include "mauicmn.h"
#include "mauimh.h"
#include "maintsig.h"
#include "mamr.h"
#include "mame.h"
#include "macore.h"
#include "mamv.h"
#include "mauisig.h"
#include "mauimenu.h"
#include "macomm.h"
#include "mauidia.h"
#include "madel.h"
#ifdef WAP_SUPPORT
#include "mamem.h" /* For mhReadHeader */
#include "maaddr.h"
#include "maasync.h"
#include "mauimv.h"
#include "mauime.h"
#include "masrh.h" /* For Dial */
#include "mauise.h" /* For meaSmilEditorIsActive */
#include "mautils.h"

/* Widget includes */
#include "widget.h"  /* For isInCall() */
#include "widget_extension.h"  /* For ctk_image_id */
#include "wgui_fixed_menuitems.h"

#ifdef __UNIFIED_MSG_SUPPORT__
#include "wap_um.h"
#include "mamob.h"  /* MEA_SIG_MOB_DEACTIVATE */
#include "mammv.h"  /* MEA_SIG_MMV_NAV_DEACTIVATE */
  #ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mmsadp.h"
extern void wap_send_mmi_mms_start_uc_req(kal_uint8 mode, kal_uint32 msg_id);
  #endif
#endif

#ifdef __MMI_KLG__
#include "wgui_datetime.h"
#include "DateTimeGprot.h"
#endif

#include "app_usedetails.h"
#include "bra_if.h"  /* for BRAif_createUI */
static applib_address_node_struct *getAddressNodeByIndex(applib_address_node_struct *list, MSF_UINT32 index);

extern void widget_send_update_event_to_wap(void);
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
extern void mms_enter_sms_editor_handler(void *p);
extern MSF_BOOL MMS_FILE_OPEN_BLOCK_FLAG;
extern MSF_BOOL smaIsRunning(void);
extern MsfScreenHandle smaGetScreenHandle(void);

MmsMessageFolderInfo *fldrMgrGetMsgInfo(MSF_UINT32 msgId);
void meaFreePropItem(MeaPropItem *prop, MSF_BOOL dynamicOnly);
#endif /*WAP_SUPPORT*/
#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGprot.h"
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
/******************************************************************************
 * Constants
 *****************************************************************************/

/*! Properties for the message folder menu */
#define MENU_PROPERTIES (MSF_WINDOW_PROPERTY_TITLE |\
    MSF_WINDOW_PROPERTY_SCROLLBARVER)

#ifdef WAP_SUPPORT
#ifndef __MMI_MMS_TEMPLATES_NUM__
#define __MMI_MMS_TEMPLATES_NUM__ 10
#endif

#ifdef __MMI_KLG__
#define MEA_MH_MAX_DATE_SIZE               50 /* !< Maximum buffer size for date */
#endif

#define MMS_PARSING_BUFFER_SIZE (10 * 1024)
#define MMS_PARSING_LINK_MAX_NUM    15
#endif /*WAP_SUPPORT*/
/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \struct MeaMhView
 *  Widget handles for the message handler GUI */
typedef struct 
{
    MsfWindowHandle menuHandle; /*!< The menu handle */
}MeaMhView;

#ifdef WAP_SUPPORT
/*! \struct MeaUseNumberListView */
typedef struct 
{
    MsfWindowHandle menuHandle; /*!< The menu handle */
    applib_address_node_struct *list;
}MeaNumberListView;

typedef enum 
{
   MEA_STRING_MSG,
   MEA_STRING_NO_SUBJECT
} MeaStringType;
#endif /* WAP_SUPPORT */
/*! \struct MeaStartupMenu 
 *  The startup menu */
typedef struct 
{
    MsfWindowHandle menuHandle; /*!< The menu handle */
}MeaStartupMenu;

/*! \struct MeaStartupMenuItem
 *  An item for the startup menu */
typedef struct 
{
    MSF_UINT32      strId;  /*!< The string ID */
    const int       menuId; /*!< The unique ID for the menu item */
#ifdef WAP_SUPPORT
    MSF_UINT16      imgId; /*!< The unique ID for the menu icon */
#endif /*WAP_SUPPORT*/
}MeaStartupMenuItem;

/******************************************************************************
 * Static variables
 *****************************************************************************/

/*! Message handler data */
static MeaMhView meaMhView;

/*! The startup menu */
static MeaStartupMenu meaStartupMenu;

#ifdef WAP_SUPPORT
/*! The Use Number menu */
static MeaNumberListView meaNumberListView;
  #if defined(MEA_MERGE_SENT)
static const MSF_UINT16 meaMenuFolderItem[MEA_MH_MENU_COUNT] = 
{
    0,
    MMS_INBOX | MMS_NOTIFY,    
    MMS_OUTBOX | MMS_SENT,
    MMS_DRAFTS,
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    MMS_ARCHIVE,
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/    
    0/*MMS_TEMPLATES*/,
    0};
  #elif defined(MEA_MERGE_OUTBOX)
static const MSF_UINT16 meaMenuFolderItem[MEA_MH_MENU_COUNT] = 
{
    MMS_INBOX | MMS_NOTIFY,
    MMS_OUTBOX | MMS_DRAFTS, 
    0,
    MMS_SENT,
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
    MMS_ARCHIVE,
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/    
    0/*MMS_TEMPLATES*/,
    0};
  #else
static const MSF_UINT16 meaMenuFolderItem[MEA_MH_MENU_COUNT] = 
{
    MMS_INBOX | MMS_NOTIFY,
    0, 
    MMS_DRAFTS,
    MMS_SENT,
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
    MMS_ARCHIVE,
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/    
    0/*MMS_TEMPLATES*/,
    MMS_OUTBOX,
    0};
  #endif /* defined(MEA_MERGE_SENT) */
#ifdef __MMI_MMS_BGSR_SUPPORT__
static mmi_mms_bgsr_msg_info_struct *mea_cur_msg_info;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
static MmsFolderType meaEmptyFolder;
static ctk_image_id imgItemList[__MMI_MMS_TEMPLATES_NUM__]; /* template no. */
static char * strNoSubject = NULL;
#ifdef __MMI_KLG__
static char * strNoNumber = NULL;
#endif /* __MMI_KLG__ */
static char * strDeliveryReport = NULL;
static char * strReadReport = NULL;
static char * strMsg = NULL;
static char * strMsgs = NULL;
static int msgCount;

static int meaMhBufferSize = 0;

static MmsMsgId useNumberMsgId = 0;
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Prototypes
 *****************************************************************************/
#ifdef MMS_SUPPORT
static void navMenuSignalConverter(MeaNavAction actionType);
#endif /*MMS_SUPPORT*/
#ifdef WAP_SUPPORT
static void meaItemListCallback(int index, void *list, kal_uint8 *string, int string_size, ctk_image_id *img);
static void meaHintListCallback(int index, void *list, kal_uint8 *hint, int hint_size);
static void meaCreatePredefinedStrings(MeaStringType strType);
#ifdef MMS_SUPPORT
#ifndef __UNIFIED_MSG_SUPPORT__
static 
#endif
ctk_image_id createImgList(int suffix, MSF_BOOL read, 
    MSF_BOOL forwardLock, MmsPriority prio, MSF_BOOL isJSR);
#endif  /*MMS_SUPPORT*/
  #if (__MMI_MMS_TEMPLATES_NUM__ > 0)
static MSF_BOOL meaMhCreateMsgList(const MmsListOfProperties *list, char **itemList, 
    ctk_image_id * imgList);
  #endif /* __MMI_MMS_TEMPLATES_NUM__ > 0 */
static void handleMhBackAction(ctk_screen_handle scrHandle);
static void handleMhOptionAction(ctk_screen_handle scrHandle);
static void handleStartupAction(ctk_screen_handle scrHandle);
static void handleOkAction(ctk_screen_handle scrHandle);
#else
static void handleBackAction(MsfWindowHandle winHandle);
static void handleStartupAction(MsfWindowHandle winHandle);
static void handleOkAction(MsfWindowHandle winHandle)
#endif /* WAP_SUPPORT */
static MsfStringHandle createString(const char *str);
#ifdef MMS_SUPPORT
static MsfImageHandle createListItemImg(int suffix, MSF_BOOL read, 
    MSF_BOOL forwardLock, MSF_BOOL isJSR);
#endif /*MMS_SUPPORT*/    

/******************************************************************************
 * Function implementation
 *****************************************************************************/
 
/*!
 * \brief Creates a graphical list of messages.
 *
 * \return TRUE if the message handler view is active, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaMhIsActive()
{
    return (0 != meaMhView.menuHandle);
}

/*!
 * \brief Init for internal data-structures for the MH view.
 *
 *****************************************************************************/
void meaMhUiInit()
{
    memset(&meaMhView, 0, sizeof(MeaMhView));
    memset(&meaStartupMenu, 0, sizeof(MeaStartupMenu));
    memset(&meaNumberListView, 0, sizeof(MeaNumberListView));
}

/*!
 * \brief Gets a image according to suffix and read status.
 *
 * \param folder The current folder
 * \param suffix The message type. See MmsFileType.
 * \param read TRUE if the message has been read, otherwise FALSE.
 * \param forwardLock TRUE if the message has a forward lock, otherwise FALSE.
 * \return An image handle.
 *****************************************************************************/
#ifdef MMS_SUPPORT 
static MsfImageHandle createListItemImg(int suffix, MSF_BOOL read, 
    MSF_BOOL forwardLock, MSF_BOOL isJSR)
{
    MsfImageHandle imgHandle;
    imgHandle = MEA_GET_IMG_ID(MEA_IMG_EMPTY);
    /* Messages in the Template folder has its own icon  */
    switch(suffix)
    { 
    case MMS_SUFFIX_MSG:
        if(isJSR)
        {
            imgHandle = MEA_GET_IMG_ID(MEA_IMG_LETTER_JAVA);
        }
        else if (forwardLock)
        {
            imgHandle = (read)?MEA_GET_IMG_ID(MEA_IMG_FORWARD_LOCK_READ):
                MEA_GET_IMG_ID(MEA_IMG_FORWARD_LOCK);
        }
        else
        {
            imgHandle = (read)?MEA_GET_IMG_ID(MEA_IMG_LETTER_READ):
                MEA_GET_IMG_ID(MEA_IMG_LETTER);
        }
        break;
    case MMS_SUFFIX_TEMPLATE:
        imgHandle = MEA_GET_IMG_ID(MEA_IMG_TEMPLATE);
        break;
    case MMS_SUFFIX_SEND_REQ:
        imgHandle = MEA_GET_IMG_ID(MEA_IMG_LETTER_CREATED);
        break;
    case MMS_SUFFIX_NOTIFICATION:
    case MMS_SUFFIX_IMMEDIATE:
        imgHandle = MEA_GET_IMG_ID(MEA_IMG_NOTIF);
        break;
    case MMS_SUFFIX_READREPORT:
        imgHandle = (read)?MEA_GET_IMG_ID(MEA_IMG_RR_READ):
            MEA_GET_IMG_ID(MEA_IMG_RR);
        break;
    case MMS_SUFFIX_DELIVERYREPORT:
        imgHandle = (read)?MEA_GET_IMG_ID(MEA_IMG_DR_READ):
            MEA_GET_IMG_ID(MEA_IMG_DR);
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAUIMH_27D90E6256B9738E7A271F385C9EA2B8, "(%s) (%d) createListItemImg suffix state (%d)\n", __FILE__, 
            __LINE__, suffix));
        break;
    }
    /* Return an empty picture as default */
    return imgHandle;
}
#endif /*MMS_SUPPORT*/
/*!
 * \brief Gets an image corresponding to the priority.
 *
 * \param prio The current priority.
 * \return An image handle.
 *****************************************************************************/
#ifdef MMS_SUPPORT 
static MsfImageHandle createPrioImg(MmsPriority prio)
{
    switch(prio)
    {
    case MMS_PRIORITY_HIGH:
        return MEA_GET_IMG_ID(MEA_IMG_PRIO_HIGH);
    case MMS_PRIORITY_LOW:
        return MEA_GET_IMG_ID(MEA_IMG_PRIO_LOW);
    case MMS_PRIORITY_NORMAL:
    case MMS_PRIORITY_NOT_SET:
    default:
        return MEA_GET_IMG_ID(MEA_IMG_EMPTY);
    }
}
#endif /*MMS_SUPPORT*/
/*!\brief Creates a string handle.
 *
 * \param str The content of the string to create.
 * \return The new string handle
 *****************************************************************************/
static MsfStringHandle createString(const char *str)
{
    if ( (NULL != str) && (0 != strlen(str)))
    {
        return MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, str, MsfUtf8, 
            (int)strlen(str) + 1, 0);
    }
    else
    {
        return MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, (char *)"", MsfUtf8, 1,
            0);
    }
}
 
/*!
 * \brief Creates a graphical list of messages.
 *
 * \param list A linked list of folder items that are to be displayed.
 * \param folder The folder to create the list in.
 * \return TRUE if the menu was successfully created, otherwise FALSE.
 *
 *****************************************************************************/
MSF_BOOL meaMhUpdateList(const MmsListOfProperties *list, MeaFolder folder)
{
#ifdef MMS_SUPPORT
    unsigned int index;
    MsfStringHandle titleStrHandle;
    MsfStringHandle subjectStrHandle;
    MsfStringHandle fromStrHandle;
    MsfImageHandle listItemImg;
    MsfImageHandle prioImgHandle;
    MmsMessageFolderInfo *fInfo;

    /* Check that the handle is valid */
    if (!meaMhIsActive())
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMH_B308D4280296A2DC7B04F7DE3E738342, "(%s) (%d) instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
    /* Remove old elements */
    for(index = (unsigned int)MSF_WIDGET_CHOICE_SIZE(meaMhView.menuHandle); 
        index > list->noOfElements; index--)
    {
        if (0 > MSF_WIDGET_CHOICE_REMOVE_ELEMENT(meaMhView.menuHandle, 
            (int)index - 1))
        {
            return FALSE;
        }
    }
    /* Insert items in the list so that all messages can be displayed */
    for(index = (unsigned)MSF_WIDGET_CHOICE_SIZE(meaMhView.menuHandle); 
        index < list->noOfElements; index++)
    {
        if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMhView.menuHandle, (int)index,
            0, 0, 0, 0, TRUE))
        {
            return FALSE;
        }
    }
    /* Add new elements to the list */
    for (index = 0; (unsigned int)index < list->noOfElements; index++)
    {
        fInfo = &(list->msgPropertyList[index].msgFolderInfo);
        /* Get image dependent on the read status */
        listItemImg = createListItemImg(fInfo->suffix, fInfo->read, fInfo->forwardLock, mmcIsJSRMsg(fInfo->msgId));
        prioImgHandle = createPrioImg(fInfo->priority);

        /* Create subject string */
        subjectStrHandle = createString(fInfo->subject);
        
        /* Create from handle */
        fromStrHandle = createString(fInfo->address);

        /* Add element*/
        if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMhView.menuHandle, (int)index, 
            subjectStrHandle, fromStrHandle, listItemImg, prioImgHandle, FALSE))
        {
            return FALSE;
        }
        /* Release strings */
        if (0 != subjectStrHandle)
        {
            (void)MSF_WIDGET_RELEASE(subjectStrHandle);
        }
        if (0 != fromStrHandle)
        {
            (void)MSF_WIDGET_RELEASE(fromStrHandle);
        }
    }
    /* Convert folder name */
    titleStrHandle = MEA_STR_ID_EMPTY_STRING;
    switch(folder)
    {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__  
    case MEA_FOLDER_ARCHIVE:
        titleStrHandle = MEA_STR_ID_ARCHIVE;
        break;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    case MEA_FOLDER_INBOX:
        titleStrHandle = MEA_STR_ID_INBOX;
        break;
    case MEA_FOLDER_DRAFTS:
        titleStrHandle = MEA_STR_ID_DRAFTS;
        break;
    case MEA_FOLDER_SENT:
        titleStrHandle = MEA_STR_ID_SENT;
        break;
    case MEA_FOLDER_OUTBOX:
        titleStrHandle = MEA_STR_ID_OUTBOX;
        break;
    case MEA_FOLDER_TEMPLATE:
        titleStrHandle = MEA_STR_ID_TEMPLATES;
        break;
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_FOLDER_USER_TEMPLATE:
        titleStrHandle = MEA_STR_ID_USER_TEMPLATES;
        break;
#endif
    case MEA_FOLDER_NONE:
        break;
    case MEA_FOLDER_COUNT:
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MAUIMH_814E7D2D7146313B8F62BF65C361D39D, "(%s) (%d) erroneous folder type\n", __FILE__, __LINE__));
        break;
    }
    (void)MSF_WIDGET_SET_TITLE(meaMhView.menuHandle, 
        MEA_GET_STR_ID(titleStrHandle));
    return TRUE;
#endif
    return FALSE ;
}

#ifndef WAP_SUPPORT
/*!
 * \brief Back action handler for the MH view.
 *
 * \param winHandle The handle of current window.
 *
 *****************************************************************************/
static void handleBackAction(MsfWindowHandle winHandle)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MAUIMH_0AD3B15EC779E745ECC0FFDB075F843A, "(%s) (%d) Back action received 0x%x\n", __FILE__, __LINE__, 
        winHandle));
    if (MEA_STARTUP_MODE_DEFAULT == meaGetStartupMode())
    {
        /* Ask before closing the application */
        (void)meaShowConfirmDialog(MEA_STR_ID_CLOSE_MEA, NULL, MEA_MH_FSM, 
            MEA_SIG_MH_CLOSE_MEA, 0);
    }
    else
    {
        /* Close the MH view */
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_DEACTIVATE);
    }
}

/*!
 * \brief Ok action handler for the MH view.
 *
 * \param winHandle The handle of current window.
 *
 *****************************************************************************/
static void handleOkAction(MsfWindowHandle winHandle)
#else
static void handleOkAction(ctk_screen_handle scrHandle)
#endif /* ~WAP_SUPPORT */
{
    MmsMsgId msgId;
    MmsFileType fileType;
    MeaFolder folder;
    int index;

#ifdef WAP_SUPPORT
    CTK_UNUSED(scrHandle);
    index = HDIa_widgetExtListMenuGetHilighted(meaMhView.menuHandle);
    index = HDIa_widgetExtListMenuGetCount(meaMhView.menuHandle)-index-1;
    if (index >= 0)
#else
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
        MAUIMH_F514184CBC35B21EFF7F83E2EAEA3EE5, "(%s) (%d) Ok action received 0x%x\n", __FILE__, __LINE__, 
        winHandle));
    /* Get the id of the item that is currently selected*/
    if ((index = meaGetSelectedMhItem()) >= 0)
#endif /* WAP_SUPPORT */
    {
        meaSetActiveMm(index);
        msgId     = meaGetActiveMm()->msgId;
        folder    = meaGetCurrentFolder();
        fileType  = (MmsFileType)meaGetActiveMm()->fileType;
        /* Check that the selected msgId is ok */
        if (0 != msgId)
        {
            if (MEA_FOLDER_TEMPLATE == folder)
            {
                /* Create new message from using the template */
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                    fileType, MEA_ME_STARTUP_FROM_TEMPLATE, 
                    msgId);
            }
            else 
            {
#if defined(WAP_SUPPORT) && defined(MMS_SUPPORT)
                if(!isValidMmsMSg(msgId))
                    meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_CORRUPT),MEA_DIALOG_ERROR);
                else
#endif /*WAP_SUPPORT*/
                    /* View message */
                    (void)MEA_SIGNAL_SENDTO_IU(MEA_MV_FSM, MEA_SIG_MV_ACTIVATE, 
                        fileType, msgId);
            }
        }
    }
#ifdef WAP_SUPPORT
    widget_send_update_event_to_wap();
#endif /* WAP_SUPPORT */
}

/*!
 * \brief Creates the GUI for the MH.
 *
 * \param list A list of folder items that are to be displayed.
 * \param folder The folder to create the list in.
 * \return TRUE if the menu was successfully created, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateMhView(const MmsListOfProperties *list, MeaFolder folder)
{
#ifdef WAP_SUPPORT
    ctk_string_id titleId;
	ctk_screen_handle scrid;
	MSF_BOOL ret;
    titleId = MEA_STR_ID_EMPTY_STRING;
    switch(folder)
    {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    case MEA_FOLDER_ARCHIVE:
        titleId = MEA_STR_ID_ARCHIVE;
        break;
#endif  /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/      
    case MEA_FOLDER_INBOX:
        titleId = MEA_STR_ID_INBOX;
        //HDIa_widgetExtClearMMS();
        break;
    case MEA_FOLDER_DRAFTS:
        titleId = MEA_STR_ID_DRAFTS;
        break;
    case MEA_FOLDER_SENT:
        titleId = MEA_STR_ID_SENT;
        break;
    case MEA_FOLDER_OUTBOX:
        titleId = MEA_STR_ID_OUTBOX;
        break;
    case MEA_FOLDER_TEMPLATE:
        titleId = MEA_STR_ID_TEMPLATES;
        break;
    case MEA_FOLDER_NONE:
        break;
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_FOLDER_USER_TEMPLATE:
        titleId = MEA_STR_ID_USER_TEMPLATES;
        break;
#endif
    case MEA_FOLDER_COUNT:
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MAUIMH_814E7D2D7146313B8F62BF65C361D39D, "(%s) (%d) erroneous folder type\n", __FILE__, __LINE__));
        break;
    }
    meaCreatePredefinedStrings(MEA_STRING_NO_SUBJECT);

#ifndef MEA_CFG_USER_TEMPLATE_SUPPORT

  #if (__MMI_MMS_TEMPLATES_NUM__ > 0)
    if (folder == MEA_FOLDER_TEMPLATE)
    {
        int numOfList = list->noOfElements;
        MSF_UINT32 i,j;
        char **strItemList;

        strItemList = MEA_ALLOC(sizeof(char *) * numOfList);
        if (0 != meaMhView.menuHandle)
            return FALSE;

        for(i=0;i<list->noOfElements;i++)
        {
		strItemList[i]=NULL;
        }
        
        /* Add content to the list*/
        if (!meaMhCreateMsgList(list, strItemList, imgItemList))
            return FALSE;

        for(i=0,j=0;i<list->noOfElements;i++)
        {
        	if(strItemList[i])
        		j++;
        }
        meaMhView.menuHandle = HDIa_widgetExtCreateListMenuByValue(MSF_MODID_MEA, 
            titleId, 0, (int)j, 
            (kal_uint8 **)strItemList, imgItemList, (kal_uint8 **)0, KAL_TRUE);
        for(i=0;i<list->noOfElements;i++)
        {
            if (strItemList[i] && (strItemList[i] != strNoSubject)) //template doesn't have report
                MEA_FREE(strItemList[i]);
        }
        MEA_FREE(strItemList);
    }
    else
  #endif /* __MMI_MMS_TEMPLATES_NUM__ > 0 */
  
  #endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/
    {
        msgCount = list->noOfElements;
        meaMhView.menuHandle = HDIa_widgetExtCreateListMenuByCallback(MSF_MODID_MEA, 
            titleId, 0, (int)list->noOfElements, 0, meaItemListCallback, 
            meaHintListCallback, NULL);
    }
    scrid = HDIa_widgetCtkGetScreenHandle(meaMhView.menuHandle);

#ifdef __UNIFIED_MSG_SUPPORT__
    if (meaGetCurrentFolder() == MEA_FOLDER_TEMPLATE 
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        || meaGetCurrentFolder() == MEA_FOLDER_USER_TEMPLATE
#endif
       ) //unified
    {
        ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OPTIONS, 0, NULL, handleMhOptionAction, KAL_TRUE);
    }
    else
    {
        ctk_screen_addLSK_UA(scrid, MEA_STR_ID_LSK_READ, 0, NULL, handleOkAction, KAL_TRUE);
    }
#else
    ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OPTIONS, 0, NULL, handleMhOptionAction, KAL_TRUE);
#endif
    ctk_screen_addRSK_UA(scrid, MEA_STR_ID_BACK, 0, NULL, handleMhBackAction, KAL_TRUE);
    ctk_screen_add_key_UA(scrid, KEY_RIGHT_ARROW, NULL, handleMhOptionAction, KAL_TRUE);
    ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, handleMhBackAction, KAL_TRUE);

	meaAddWidgetList(meaMhView.menuHandle);
    ret = (MSF_BOOL)meaDisplayWindow(meaMhView.menuHandle, meaGetPosLeftTop());

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    if (folder == MEA_FOLDER_TEMPLATE ||
        folder == MEA_FOLDER_USER_TEMPLATE)
#else
    if (folder == MEA_FOLDER_TEMPLATE)
#endif
	{
        HDIa_widgetExtCloseTransitionAnimation();
    }
	return ret;
#else
    MsfActionHandle actionHandle;
    MSF_UINT32 strId;
    /* Check that this view is not already active */
    if (0 != meaMhView.menuHandle)
    {
        return FALSE;
    }
    actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA,
        MEA_GET_STR_ID(MEA_STR_ID_OK), MsfSelect, 0, 
        MSF_ACTION_PROPERTY_ENABLED);
    
    if (0 == (meaMhView.menuHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_MEA, 
        MsfImplicitChoice, NULL, actionHandle, NULL, 
        MSF_CHOICE_ELEMENT_IMAGE_1 | MSF_CHOICE_ELEMENT_IMAGE_2 | 
        MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_STRING_2, 
        MENU_PROPERTIES, 0)))
    {
        return FALSE;
    }
    /*  We couldn't register the action until we had a window handle.
     *  Now we have it so rock'n'roll. 
     */
    if (!meaRegisterAction(meaMhView.menuHandle, actionHandle, 
        handleOkAction, 0, 0))
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return FALSE;
    }
    /* Menu action */
    if (!meaCreateAction(meaMhView.menuHandle, MsfMenu, NULL, MEA_MH_FSM,
        MEA_SIG_MH_NAV_ACTIVATE, MEA_STR_ID_MENU))
    {
        return FALSE;
    }

    /* Back action */
    /* Change the soft button according to the start-up mode */
    strId = MEA_STR_ID_EXIT;
    if (MEA_STARTUP_MODE_MENU == meaGetStartupMode())
    {
        strId = MEA_STR_ID_BACK;
    }
    if (0 == meaCreateAction(meaMhView.menuHandle, MsfBack, 
        handleBackAction, 0, 0, strId))
    {
        return FALSE;
    }
    /* Add content to the list*/
    if (!meaMhUpdateList(list, folder))
    {
        return FALSE;
    }
    
    /* Bind menu to the screen and activate */
    return meaDisplayWindow(meaMhView.menuHandle, meaGetPosLeftTop());
#endif /* WAP_SUPPORT */
}

#ifdef WAP_SUPPORT
/*!
 * \brief update dynamic message list.
 *
 * \param number of message items.
 * \param folder The folder to create the list in.
 *****************************************************************************/
void meaMhUpdateDynamicList(int noOfElements, MeaFolder folder)
{
    ctk_string_id titleId = MEA_STR_ID_EMPTY_STRING;
    ctk_screen_handle scrId = HDIa_widgetCtkGetScreenHandle(meaMhView.menuHandle);
    int highlighted = HDIa_widgetExtListMenuGetHilighted(meaMhView.menuHandle);
    msgCount = noOfElements;
    switch(folder)
    {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__      
    case MEA_FOLDER_ARCHIVE:
        titleId = MEA_STR_ID_ARCHIVE;
        break;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    case MEA_FOLDER_INBOX:
        titleId = MEA_STR_ID_INBOX;
        //HDIa_widgetExtClearMMS();
        break;
    case MEA_FOLDER_DRAFTS:
        titleId = MEA_STR_ID_DRAFTS;
        break;
    case MEA_FOLDER_SENT:
        titleId = MEA_STR_ID_SENT;
        break;
    case MEA_FOLDER_OUTBOX:
        titleId = MEA_STR_ID_OUTBOX;
        break;
    case MEA_FOLDER_TEMPLATE:
        titleId = MEA_STR_ID_TEMPLATES;
        break;
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    case MEA_FOLDER_USER_TEMPLATE:
        titleId = MEA_STR_ID_USER_TEMPLATES;
        break;
#endif
    case MEA_FOLDER_NONE:
        break;
    case MEA_FOLDER_COUNT:
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA,
            MAUIMH_814E7D2D7146313B8F62BF65C361D39D, "(%s) (%d) erroneous folder type\n", __FILE__, __LINE__));
        break;
    }
    //meaCreatePredefinedStrings(MEA_STRING_NO_SUBJECT);

    HDIa_widgetExtUpdateListMenuByCallback(meaMhView.menuHandle, 
        titleId, 0, noOfElements, (kal_uint16)highlighted, meaItemListCallback, 
        meaHintListCallback, NULL);
    if (CTK_SCREEN_STATE_ACTIVE == ctk_screen_get_current_state(scrId))
        ctk_screen_invoke_redraw(scrId);
}
#ifdef __MMS_DUAL_SIM_SUPPORT__
ctk_image_id meaTranslateDualSIIMImgId(ctk_image_id imgId, MSF_UINT32 simId)
{
    switch(imgId)
    {
        case    MEA_IMG_SENT:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_SENT_SIM_1;
            }
            else
            {
                return MEA_IMG_SENT_SIM_2;
            }
            break;
		case    MEA_IMG_OUTBOX:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_OUTBOX_SIM_1;
            }
            else
            {
                return MEA_IMG_OUTBOX_SIM_2;
            }
            break;
        case    MEA_IMG_LETTER_JAVA:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_LETTER_JAVA_SIM_1;
            }
            else
            {
                return MEA_IMG_LETTER_JAVA_SIM_2;
            }
            break;
        case    MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH_SIM_1;
            }
            else
            {
                return MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH_SIM_2;
            }
            break;
        case    MEA_IMG_FORWARD_LOCK_PRIO_HIGH:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_FORWARD_LOCK_PRIO_HIGH_SIM_1;
            }
            else
            {
                return MEA_IMG_FORWARD_LOCK_PRIO_HIGH_SIM_2;
            }
            break;
		case    MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW_SIM_1;
            }
            else
            {
                return MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW_SIM_2;
            }
            break;
        case    MEA_IMG_FORWARD_LOCK_PRIO_LOW:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_FORWARD_LOCK_PRIO_LOW_SIM_1;
            }
            else
            {
                return MEA_IMG_FORWARD_LOCK_PRIO_LOW_SIM_2;
            }
            break;
        case    MEA_IMG_FORWARD_LOCK_READ:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_FORWARD_LOCK_READ_SIM_1;
            }
            else
            {
                return MEA_IMG_FORWARD_LOCK_READ_SIM_2;
            }
            break;
        case    MEA_IMG_FORWARD_LOCK:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_FORWARD_LOCK_SIM_1;
            }
            else
            {
                return MEA_IMG_FORWARD_LOCK_SIM_2;
            }
            break;
        case    MEA_IMG_LETTER_READ_PRIO_HIGH:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_LETTER_READ_PRIO_HIGH_SIM_1;
            }
            else
            {
                return MEA_IMG_LETTER_READ_PRIO_HIGH_SIM_2;
            }
            break;
        case    MEA_IMG_LETTER_PRIO_HIGH:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_LETTER_PRIO_HIGH_SIM_1;
            }
            else
            {
                return MEA_IMG_LETTER_PRIO_HIGH_SIM_2;
            }
            break;
        case    MEA_IMG_LETTER_READ_PRIO_LOW:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_LETTER_READ_PRIO_LOW_SIM_1;
            }
            else
            {
                return MEA_IMG_LETTER_READ_PRIO_LOW_SIM_2;
            }
            break;
        case    MEA_IMG_LETTER_PRIO_LOW:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_LETTER_PRIO_LOW_SIM_1;
            }
            else
            {
                return MEA_IMG_LETTER_PRIO_LOW_SIM_2;
            }
            break;
        case    MEA_IMG_LETTER_READ:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_LETTER_READ_SIM_1;
            }
            else
            {
                return MEA_IMG_LETTER_READ_SIM_2;
            }
            break;
        case    MEA_IMG_LETTER:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_LETTER_SIM_1;
            }
            else
            {
                return MEA_IMG_LETTER_SIM_2;
            }
            break;
        case    MEA_IMG_NOTIF_PRIO_HIGH:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_NOTIF_PRIO_HIGH_SIM_1;
            }
            else
            {
                return MEA_IMG_NOTIF_PRIO_HIGH_SIM_2;
            }
            break;
        case    MEA_IMG_NOTIF_PRIO_LOW:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_NOTIF_PRIO_LOW_SIM_1;
            }
            else
            {
                return MEA_IMG_NOTIF_PRIO_LOW_SIM_2;
            }
            break;
        case    MEA_IMG_NOTIF:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_NOTIF_SIM_1;
            }
            else
            {
                return MEA_IMG_NOTIF_SIM_2;
            }
            break;
        case    MEA_IMG_RR_READ:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_RR_READ_SIM_1;
            }
            else
            {
                return MEA_IMG_RR_READ_SIM_2;
            }
            break;
        case    MEA_IMG_RR:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_RR_SIM_1;
            }
            else
            {
                return MEA_IMG_RR_SIM_2;
            }
            break;
        case    MEA_IMG_DR_READ:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_DR_READ_SIM_1;
            }
            else
            {
                return MEA_IMG_DR_READ_SIM_2;
            }
            break;
        case    MEA_IMG_DR:
            if(simId == MMS_SIM_CARD_MASTER)
            {
                return MEA_IMG_DR_SIM_1;
            }
            else
            {
                return MEA_IMG_DR_SIM_2;
            }
            break;
        default:
            return imgId;
    }
}
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
/*!
 * \brief Call back for creating message list item
 *
 * \param index of the menu item (should convert to the message index)
 * \param not used
 * \param message list string
 * \param string size
 * \param image resource id for message icon
 *****************************************************************************/
static void meaItemListCallback(int index, void *list, kal_uint8 *string, int string_size, ctk_image_id *img)
{
#ifdef MMS_SUPPORT    
#ifdef MMS_FILE_PROTECT_SUPPORT
    MeaMsgInfo *msgList  = meaGetMessageInfo(msgCount - index -1);
    MmsMessageFolderInfo *msgInfo  = fldrMgrGetMsgInfo(msgList->msgId);
    char *subject=NULL;
    char *address=NULL;

    getMmsMsgSubAddr(MSF_MODID_MEA,msgList->msgId, &subject, &address,250);
  #ifdef __MMI_KLG__
    if (meaGetCurrentFolder() == MEA_FOLDER_INBOX || meaGetCurrentFolder() == MEA_FOLDER_OUTBOX)
    {
        char * name = NULL;    
	    /* address */
	    if (address)
	    {    
	        if (MEA_ADDR_TYPE_PLMN == meaGetAddrType(address))
	        {
	            //addr should be validated before, so we are sure that addrType is valid
	            name = meaLookupNameFromPHB(address);
	        }
	        if (name)
	        {
	            widget_utf8_to_ucs2_string(string, string_size, (kal_uint8*)name);
	            MEA_FREE(name);
	        }
	        else
	        {
	            widget_utf8_to_ucs2_string(string, string_size, (kal_uint8*)address);
	        }
	    }
	    else
	    {
	        switch(msgList->fileType)
		    {   
			    //You can make itemList[listIndex] point to delievry report, read report or notifcaiton string.
				case MMS_SUFFIX_DELIVERYREPORT:	
					widget_ucs2_strncpy((kal_uint8*)string, (kal_uint8*)strDeliveryReport, string_size);
					break;
				case MMS_SUFFIX_READREPORT:				
					widget_ucs2_strncpy((kal_uint8*)string, (kal_uint8*)strReadReport, string_size);
					break;
			    case MMS_SUFFIX_NOTIFICATION:  					   			
			    case MMS_SUFFIX_IMMEDIATE:
			    default:	
				    widget_ucs2_strncpy((kal_uint8*)string, (kal_uint8*)strNoNumber, string_size);
				    break;
		    }
	    }
    }
	else
	{
  #endif /* __MMI_KLG__ */
	    /* subject */
	    if ((NULL != subject) && (0 != strlen(subject)) && 
	        !(*subject == 0x20  && *(subject+1) == 0x00)) //interoperability with TCC
	    {
	        char *utf8_str = subject;
            if(*subject == 0x7F && *(subject+1) > 0x7F)  /* Text-string=[Quote] *TEXT End-of-string : remove [Quote] */
            {   
                utf8_str++;
            }
            if (widget_utf8_length((kal_uint8 *)utf8_str) > MAX_SUBMENU_CHARACTERS)
            {
                char *end = msf_cmmn_utf8_str_incr(utf8_str, MAX_SUBMENU_CHARACTERS - 3);
                strcpy(end, "...");
            }
	        widget_utf8_to_ucs2_string(string, string_size, (kal_uint8*)utf8_str);
	    }
	    else
	    {
	        switch(msgList->fileType)
		    {   
			    //You can make itemList[listIndex] point to delievry report, read report or notifcaiton string.
				case MMS_SUFFIX_DELIVERYREPORT:	
					widget_ucs2_strncpy((kal_uint8*)string, (kal_uint8*)strDeliveryReport, string_size);
					break;
				case MMS_SUFFIX_READREPORT:				
					widget_ucs2_strncpy((kal_uint8*)string, (kal_uint8*)strReadReport, string_size);
					break;
			    case MMS_SUFFIX_NOTIFICATION:  					   			
			    case MMS_SUFFIX_IMMEDIATE:
			    default:	
				    widget_ucs2_strncpy((kal_uint8*)string, (kal_uint8*)strNoSubject, string_size);
				    break;
		    }
	    }
  #ifdef __MMI_KLG__
	}
  #endif /* __MMI_KLG__ */
  #if defined(MEA_MERGE_SENT)
    if ( MMS_SUFFIX_SEND_REQ == msgList->fileType)
    {
        *img = (ctk_image_id)((MMS_SENT == fldrGetFolderId(msgList->msgId)) ? MEA_IMG_SENT : MEA_IMG_LETTER_CREATED);
     }
    else
  #elif defined(MEA_MERGE_OUTBOX)
    if ( MMS_SUFFIX_SEND_REQ == msgList->fileType)
    {
        *img = (ctk_image_id)((MMS_DRAFTS == fldrGetFolderId(msgList->msgId)) ? MEA_IMG_LETTER_CREATED : MEA_IMG_OUTBOX);
    }
    else
  #endif /* defined(MEA_MERGE_SENT) */
    *img = createImgList(msgList->fileType, msgInfo->read, msgList->forwardLock, msgInfo->priority, mmcIsJSRMsg(msgInfo->msgId));
#ifdef __MMS_DUAL_SIM_SUPPORT__
    if( msgList->msgId != 0)
    {
        *img = meaTranslateDualSIIMImgId(*img, fldrGetMessageSimId(msgList->msgId));
    }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    if(subject)
	MEA_FREE(subject);
    if(address)
	MEA_FREE(address);
    MEA_FREE(msgList);
#else /* MMS_FILE_PROTECT_SUPPORT */
    MeaMsgInfo *msgList  = meaGetMessageInfo(msgCount - index -1);
    MmsMessageFolderInfo *msgInfo  = fldrMgrGetMsgInfo(msgList->msgId);
    MmsMsgHandle msgHandle=NULL;
    MmsTransactionHandle transaction=NULL;
    MmsGetHeader header;
    MmsResult ret = MMS_RESULT_ERROR;
    MmsNotification notiheader;
    MSF_BOOL freeHeader=FALSE;
    MSF_BOOL freeBuffer=FALSE;
    char *buffer=NULL;
    int  bufSize=0;
    char *subject=NULL;
    MmsHeaderValue headerValue;
    MmsEncodedText enSubject;
    MmsPriority priority = MMS_PRIORITY_NORMAL;

    //fInfo = &((((MmsMessageProperties *)list)-> [listIndex]).msgFolderInfo);
    /* Get image dependent on the read status and priority*/
    /* Open message and then get message header */ 
	enSubject.charset=MMS_UNKNOWN_CHARSET;
	enSubject.text=NULL;

	switch(msgList->fileType)
	{			
		case MMS_SUFFIX_DELIVERYREPORT:				
		case MMS_SUFFIX_READREPORT:
			loadMmsDataToBuffer(MSF_MODID_MEA,msgList->msgId,(MSF_UINT8)msgList->fileType,&buffer,&bufSize);        
			if(!buffer)
				break;					
			freeBuffer=TRUE;	

			if (mmsPduGet( buffer, bufSize, MMS_SUBJECT, &headerValue))
			{
				MSF_UINT32 notUsed = 0;
				int size=0;
				size = (MSF_UINT32)((unsigned char *)buffer - (unsigned char *)headerValue.subject) + 
					bufSize;
				if (parseEncodedStringValue( MSF_MODID_MEA, headerValue.subject, size, &notUsed, 
					&enSubject) != FALSE)
				{
					subject=enSubject.text;
				}	 
			}  
			break;

		case MMS_SUFFIX_SEND_REQ:
		case MMS_SUFFIX_TEMPLATE:
		case MMS_SUFFIX_MSG:
		case MMS_SUFFIX_NOTIFICATION:
		case MMS_SUFFIX_IMMEDIATE:
			memset(&header,0x00,sizeof(MmsGetHeader));
			memset(&notiheader,0x00,sizeof(notiheader));
			MMS_FILE_OPEN_BLOCK_FLAG=TRUE;
			if(MMSlib_messageOpen(MSF_MODID_MEA,msgList->msgId,msgList->fileType, &msgHandle)!=MMS_RESULT_OK)
			{
				MMS_FILE_OPEN_BLOCK_FLAG=FALSE;		
				break;
			}
			else if(MMSlib_transactionOpen(MSF_MODID_MEA,&transaction)!=MMS_RESULT_OK)
			{		
				MMS_FILE_OPEN_BLOCK_FLAG=FALSE;		
				MMSlib_transactionClose(MSF_MODID_MEA,&transaction);
				transaction=NULL;
				break;
			}
			MMS_FILE_OPEN_BLOCK_FLAG=FALSE;	
			if(msgList->fileType == MMS_SUFFIX_NOTIFICATION || msgList->fileType == MMS_SUFFIX_IMMEDIATE)
			{
				if((ret=MMSlib_getNotification(MSF_MODID_MEA, &notiheader, &msgHandle, &transaction))==MMS_RESULT_OK)        			
					freeHeader=TRUE;
			}
			else
			{
				if((ret=MMSlib_getMessageHeader(MSF_MODID_MEA, &header, &msgHandle, &transaction))==MMS_RESULT_OK)        			
					freeHeader=TRUE;
			}
			if(transaction)
			{
				MMSlib_transactionClose(MSF_MODID_MEA,&transaction);
			}
			if(msgHandle)
			{
				MMSlib_messageClose(MSF_MODID_MEA,&msgHandle);
			}				
			msgHandle = NULL;
			transaction = NULL;
			if(freeHeader && header.subject.text)
				subject = header.subject.text;
			if(freeHeader && notiheader.subject.text)
				subject = notiheader.subject.text;
	}
    /* subject */
    if ( (NULL != subject) && (0 != strlen(subject)))
    {    
        //kal_uint8 *ucs2Subject=NULL;
        //int size = (widget_utf8_length((kal_uint8*)subject)+1) * UCS2_ENCODING_LENGTH;
        //ucs2Subject=MEA_ALLOC(size);
        widget_utf8_to_ucs2_string(string,string_size,(kal_uint8*)subject);
        //widget_ucs2_strncpy(string,subject,string_size);
        if(enSubject.text)
        MEA_FREE(enSubject.text);
    }
    else
    {
        switch(msgList->fileType)
		{   //You can make itemList[listIndex] point to delievry report, read report or notifcaiton string.
			case MMS_SUFFIX_NOTIFICATION:  					   			
			case MMS_SUFFIX_IMMEDIATE:
			case MMS_SUFFIX_DELIVERYREPORT:				
			case MMS_SUFFIX_READREPORT:				
			default:	
				widget_ucs2_strncpy((kal_uint8*)string,(kal_uint8*)strNoSubject,string_size);
				break;
		}
    }
    priority = header.priority;
  #if defined(MEA_MERGE_SENT)
    if ( MMS_SUFFIX_SEND_REQ == msgList->fileType)
        *img = (ctk_image_id)((MMS_SENT == fldrGetFolderId(msgList->msgId)) ? MEA_IMG_SENT : MEA_IMG_LETTER_CREATED);
    else
  #elif defined(MEA_MERGE_OUTBOX)
    if ( MMS_SUFFIX_SEND_REQ == msgList->fileType)
        *img = (ctk_image_id)((MMS_DRAFTS == fldrGetFolderId(msgList->msgId)) ? MEA_IMG_LETTER_CREATED : MEA_IMG_OUTBOX);
    else
  #endif /* defined(MEA_MERGE_SENT) */
    *img = createImgList(msgList->fileType, msgInfo->read, msgList->forwardLock, priority, mmcIsJSRMsg(msgInfo->msgId));

	if(freeHeader)
	{	
		if( msgList->fileType == MMS_SUFFIX_NOTIFICATION || msgList->fileType == MMS_SUFFIX_IMMEDIATE)
			freeMmsNotification( MSF_MODID_MEA,&notiheader);
		else
			freeMmsGetHeader(MSF_MODID_MEA,&header);
		}
	if(freeBuffer)
		MEA_FREE(buffer);
	MEA_FREE(msgList);
#endif /* MMS_FILE_PROTECT_SUPPORT */
#endif /* MMS_SUPPORT */
}

/*!
 * \brief Call back for creating message list hint
 *
 * \param index of the menu item (should convert to the message index)
 * \param not used
 * \param message list hint string
 * \param hint string size
 *****************************************************************************/
static void meaHintListCallback(int index, void *arg, kal_uint8 *hint, int hint_size)
{
    MeaMsgInfo *msgList  = meaGetMessageInfo(msgCount - index -1);
    //MmsMessageFolderInfo *msgInfo  = fldrMgrGetMsgInfo(msgList->msgId);
#ifdef MMS_FILE_PROTECT_SUPPORT
    char * name = NULL;    
    char *subject=NULL;
	char *address=NULL;

    if (msgList->fileType != MMS_SUFFIX_SEND_REQ && msgList->fileType != MMS_SUFFIX_TEMPLATE)
        HDIa_widgetExtClearMMS();

  #ifdef __MMI_KLG__
    if (meaGetCurrentFolder() == MEA_FOLDER_INBOX || meaGetCurrentFolder() == MEA_FOLDER_OUTBOX)
    {
	    MmsMsgHandle msgHandle=NULL;
	    MmsTransactionHandle transaction=NULL;
	    MmsGetHeader header;
	    MmsResult ret = MMS_RESULT_ERROR;
	    MmsNotification notiheader;
		MSF_BOOL freeHeader=FALSE;
		MSF_BOOL freeBuffer=FALSE;
	    char *buffer = NULL;
	    int  bufSize = 0;
	    MmsTimeSec date = 0;
	    MmsHeaderValue headerValue;
		MYTIME time;
		MSF_UINT16* dateString;

		switch(msgList->fileType)
		{			
			case MMS_SUFFIX_DELIVERYREPORT:				
			case MMS_SUFFIX_READREPORT:
				loadMmsDataToBuffer(MSF_MODID_MEA, msgList->msgId, (MSF_UINT8)msgList->fileType, &buffer, &bufSize);        
				if (!buffer)
					break;					
				freeBuffer=TRUE;	

				if (mmsPduGet( buffer, bufSize, MMS_DATE, &headerValue))
				{
					date = headerValue.date;
				}  
				break;

			case MMS_SUFFIX_SEND_REQ:
			case MMS_SUFFIX_TEMPLATE:
			case MMS_SUFFIX_MSG:
			case MMS_SUFFIX_NOTIFICATION:
			case MMS_SUFFIX_IMMEDIATE:
				memset(&header, 0x00, sizeof(MmsGetHeader));
				memset(&notiheader, 0x00, sizeof(notiheader));
				MMS_FILE_OPEN_BLOCK_FLAG=TRUE;
				if (MMSlib_messageOpen(MSF_MODID_MEA,msgList->msgId,msgList->fileType, &msgHandle)!=MMS_RESULT_OK)
				{
					MMS_FILE_OPEN_BLOCK_FLAG=FALSE;		
					break;
				}
				else if (MMSlib_transactionOpen(MSF_MODID_MEA,&transaction)!=MMS_RESULT_OK)
				{		
					MMS_FILE_OPEN_BLOCK_FLAG=FALSE;		
					MMSlib_transactionClose(MSF_MODID_MEA,&transaction);
					transaction=NULL;
					break;
				}
				MMS_FILE_OPEN_BLOCK_FLAG=FALSE;	
				if (msgList->fileType == MMS_SUFFIX_NOTIFICATION || msgList->fileType == MMS_SUFFIX_IMMEDIATE)
				{
					//if ((ret=MMSlib_getNotification(MSF_MODID_MEA, &notiheader, &msgHandle, &transaction))==MMS_RESULT_OK)        			
					//	freeHeader=TRUE;
				}
				else
				{
					if ((ret=MMSlib_getMessageHeader(MSF_MODID_MEA, &header, &msgHandle, &transaction))==MMS_RESULT_OK)        			
						freeHeader=TRUE;
				}
				if (transaction)
				{
					MMSlib_transactionClose(MSF_MODID_MEA, &transaction);
				}
				if (msgHandle)
				{
					MMSlib_messageClose(MSF_MODID_MEA, &msgHandle);
				}				
				msgHandle = NULL;
				transaction = NULL;
				if (freeHeader && header.date)
					date = header.date;
				//if (freeHeader && notiheader.date)
				//	date = notiheader.date;
		}
	    /* date string */
	    if (date)
	    {    
            date+=(HDIa_timeGetTimeZone()*60);
			dateString = MEA_ALLOC(MEA_MH_MAX_DATE_SIZE); //Max date size
		    mmi_dt_utc_sec_2_mytime(date, &time, KAL_FALSE);
		    date_string(&time, dateString, DT_IDLE_SCREEN);
	        widget_ucs2_strncpy(hint, (kal_uint8*)dateString, hint_size);
			MEA_FREE(dateString);
	    }
	    else
	    {
	        *hint = 0;
	        *(hint+1) = 0;
	    }

		if (freeHeader)
		{	
			if (msgList->fileType == MMS_SUFFIX_NOTIFICATION || msgList->fileType == MMS_SUFFIX_IMMEDIATE)
				freeMmsNotification( MSF_MODID_MEA,&notiheader);
			else
				freeMmsGetHeader(MSF_MODID_MEA,&header);
		}
		if (freeBuffer)
			MEA_FREE(buffer);
		MEA_FREE(msgList);
        return;
    }
  #endif /* __MMI_KLG__ */
	getMmsMsgSubAddr(MSF_MODID_MEA,msgList->msgId, &subject, &address,250);

    if(address)
    {
        char *displayStr = NULL;
        if (MEA_ADDR_TYPE_PLMN == meaGetAddrType(address))
        {
            //addr should be validated before, so we are sure that addrType is valid
            name = meaLookupNameFromPHB(address);
        }

        displayStr = (name) ? name : address;
        if (widget_utf8_length((kal_uint8 *)displayStr) > MAX_SUBMENU_CHARACTERS)
        {
            char *end = msf_cmmn_utf8_str_incr(displayStr, MAX_SUBMENU_CHARACTERS - 3);
            strcpy(end, "...");
        }
        widget_utf8_to_ucs2_string(hint, hint_size, (kal_uint8*)displayStr);
    }
    else
    {
        *hint = 0;
        *(hint+1) = 0;
    }

	if(subject)
		MEA_FREE(subject);
	if(address)
		MEA_FREE(address);
	if(name)
		MEA_FREE(name);
    MEA_FREE(msgList);
#else
    //MmsMessageFolderInfo *fInfo;
    MmsMsgHandle msgHandle=NULL;
    MmsTransactionHandle transaction=NULL;
    MmsGetHeader header;
    MmsResult ret = MMS_RESULT_ERROR;
    MmsNotification notiheader;
    MSF_BOOL freeHeader=FALSE; //for message
    MSF_BOOL freeBuffer=FALSE; //for report
    char *addr=NULL;
    char *buffer=NULL;
    int  bufSize=0;
    //char *subject=NULL, *address=NULL;
    //MmsHeaderValue headerValue;
    //MmsEncodedText enSubject;
    MmsAddress     fromAddress;
    char * name = NULL;

	fromAddress.address=NULL;
	fromAddress.addrType=MMS_UNSUPPORTED;
	//fromAddress.name.charset=MMS_UNKNOWN_CHARSET;
	fromAddress.name.text=NULL;

	switch(msgList->fileType)
	{			
		case MMS_SUFFIX_DELIVERYREPORT:				
		case MMS_SUFFIX_READREPORT:
			HDIa_widgetExtClearMMS();
			loadMmsDataToBuffer(MSF_MODID_MEA,msgList->msgId,(MSF_UINT8)msgList->fileType,&buffer,&bufSize);        
			if(!buffer)
				break;					
			freeBuffer=TRUE;	
			
			if (parseFromAddress( MSF_MODID_MEA, (unsigned char *)buffer, bufSize, 
				  &fromAddress) != FALSE)
			{	        
				addr=fromAddress.address;
			}
			break;

		case MMS_SUFFIX_SEND_REQ:
		case MMS_SUFFIX_TEMPLATE:
		case MMS_SUFFIX_MSG:			
		case MMS_SUFFIX_NOTIFICATION:					   				
		case MMS_SUFFIX_IMMEDIATE:
			if (msgList->fileType == MMS_SUFFIX_MSG || msgList->fileType == MMS_SUFFIX_NOTIFICATION || 
				msgList->fileType == MMS_SUFFIX_IMMEDIATE)
				HDIa_widgetExtClearMMS();

			memset(&header,0x00,sizeof(MmsGetHeader));
			memset(&notiheader,0x00,sizeof(notiheader));
			MMS_FILE_OPEN_BLOCK_FLAG=TRUE;
			if(MMSlib_messageOpen(MSF_MODID_MEA,msgList->msgId,msgList->fileType, &msgHandle)!=MMS_RESULT_OK)
			{
				MMS_FILE_OPEN_BLOCK_FLAG=FALSE;
				break;
			}
			else if(MMSlib_transactionOpen(MSF_MODID_MEA,&transaction)!=MMS_RESULT_OK)
			{		
				MMS_FILE_OPEN_BLOCK_FLAG=FALSE;
				MMSlib_transactionClose(MSF_MODID_MEA,&transaction);
				break;
			}
			MMS_FILE_OPEN_BLOCK_FLAG=FALSE;
			if(msgList->fileType == MMS_SUFFIX_NOTIFICATION || msgList->fileType == MMS_SUFFIX_IMMEDIATE)
			{
				if((ret=MMSlib_getNotification(MSF_MODID_MEA, &notiheader, &msgHandle, &transaction))==MMS_RESULT_OK)        			
					freeHeader=TRUE;
			}
			else
			{
				if((ret=MMSlib_getMessageHeader(MSF_MODID_MEA, &header, &msgHandle, &transaction))==MMS_RESULT_OK)        			
					freeHeader=TRUE;
			}
			if(transaction)
			{	
				MMSlib_transactionClose(MSF_MODID_MEA,&transaction);
			}
			if(msgHandle)
			{
				MMSlib_messageClose(MSF_MODID_MEA,&msgHandle);
			}
			msgHandle = NULL;
			transaction = NULL;
			/* hint = from */
			if(msgList->fileType != MMS_SUFFIX_SEND_REQ && msgList->fileType!=MMS_SUFFIX_TEMPLATE)
			{
				if(msgList->fileType == MMS_SUFFIX_NOTIFICATION || msgList->fileType == MMS_SUFFIX_IMMEDIATE)
					addr = notiheader.from.address;
				else
					addr = header.from.address;
			}
			else
			{
				if(header.to)
					addr=header.to->current.address;
				else if(header.cc)
					addr=header.cc->current.address;
				else if(header.bcc)
					addr=header.bcc->current.address;
			}
			break;
	}
    /* address */

    if(addr)
    {
        name = meaLookupNameFromPHB(addr);
        if (name)
        {
            widget_utf8_to_ucs2_string(hint, hint_size, (kal_uint8*)name);
            MEA_FREE(name);
        }
        else
        {
            widget_utf8_to_ucs2_string(hint, hint_size, (kal_uint8*)addr);
        }
        if(fromAddress.address)
            MEA_FREE(fromAddress.address);
        if(fromAddress.name.text)
            MEA_FREE(fromAddress.name.text);
    }
    else
    {
        *hint = 0;
        *(hint+1) = 0;
    }
    if(freeHeader)
    {	
        if(msgList->fileType==MMS_SUFFIX_NOTIFICATION || msgList->fileType == MMS_SUFFIX_IMMEDIATE)
            freeMmsNotification( MSF_MODID_MEA,&notiheader);
        else
            freeMmsGetHeader(MSF_MODID_MEA,&header);
    }
    if(freeBuffer)
        MEA_FREE(buffer);
	
    MEA_FREE(msgList);
#endif /* MMS_FILE_PROTECT_SUPPORT */
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
#endif			/*0*/
static void handleMhOptionAction(ctk_screen_handle scrHandle)
{
    //meaSetActiveMm(HDIa_widgetExtListMenuGetHilighted(meaMhView.menuHandle));
    int index =HDIa_widgetExtListMenuGetHilighted(meaMhView.menuHandle);
    index = HDIa_widgetExtListMenuGetCount(meaMhView.menuHandle)-index-1;
    CTK_UNUSED(scrHandle);
    meaSetActiveMm(index);

    if (!meaCreateMhNavMenu(meaGetCurrentFolder(), meaGetActiveMm()->msgId, 
        meaGetActiveMm()->fileType, meaGetActiveMm()->forwardLock
#ifdef __MMI_MMS_BGSR_SUPPORT__
        , NULL
#endif /*__MMI_MMS_BGSR_SUPPORT__*/        
        ))
    {
        meaDeleteMhNavMenu();
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
            MEA_DIALOG_ERROR);
    }
    //MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_ACTIVATE);
    //widget_send_update_event_to_wap();
}

/*!
 * \brief Gets a image according to suffix and read status.
 *
 * \param folder The current folder
 * \param suffix The message type. See MmsFileType.
 * \param read TRUE if the message has been read, otherwise FALSE.
 * \param forwardLock TRUE if the message has a forward lock, otherwise FALSE.
 * \return An image handle.
 *****************************************************************************/
#ifdef MMS_SUPPORT
#ifndef __UNIFIED_MSG_SUPPORT__
static 
#endif
ctk_image_id createImgList(int suffix, MSF_BOOL read, 
    MSF_BOOL forwardLock, MmsPriority prio, MSF_BOOL isJSR)
{
    switch(suffix)
    {
    case MMS_SUFFIX_MSG:
        if(isJSR)
        {
            return (ctk_image_id)(MEA_IMG_LETTER_JAVA);
        }
        if (forwardLock)
        {
            switch(prio)
            {
                case MMS_PRIORITY_HIGH:
                    return (ctk_image_id)((read)?(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH):(MEA_IMG_FORWARD_LOCK_PRIO_HIGH));
                case MMS_PRIORITY_LOW:
                    return (ctk_image_id)((read)?(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW):(MEA_IMG_FORWARD_LOCK_PRIO_LOW));
                case MMS_PRIORITY_NORMAL:
                case MMS_PRIORITY_NOT_SET:
                default:
                    return (ctk_image_id)((read)?(MEA_IMG_FORWARD_LOCK_READ):(MEA_IMG_FORWARD_LOCK));
            }
        }
        else
        {
            switch(prio)
            {
                case MMS_PRIORITY_HIGH:
                    return (ctk_image_id)((read)?(MEA_IMG_LETTER_READ_PRIO_HIGH):(MEA_IMG_LETTER_PRIO_HIGH));
                case MMS_PRIORITY_LOW:
                    return (ctk_image_id)((read)?(MEA_IMG_LETTER_READ_PRIO_LOW):(MEA_IMG_LETTER_PRIO_LOW));
                case MMS_PRIORITY_NORMAL:
                case MMS_PRIORITY_NOT_SET:
                default:
                    return (ctk_image_id)((read)?(MEA_IMG_LETTER_READ):(MEA_IMG_LETTER));
            }
        }
    /* Messages in the Template folder has its own icon  */
    case MMS_SUFFIX_TEMPLATE:
        return MEA_IMG_TEMPLATE;
    case MMS_SUFFIX_SEND_REQ:
        return MEA_IMG_LETTER_CREATED;
    case MMS_SUFFIX_NOTIFICATION:
    case MMS_SUFFIX_IMMEDIATE:
        switch (prio)
        {
            case MMS_PRIORITY_HIGH:
                return MEA_IMG_NOTIF_PRIO_HIGH;
            case MMS_PRIORITY_LOW:
                return MEA_IMG_NOTIF_PRIO_LOW;
            case MMS_PRIORITY_NORMAL:
            case MMS_PRIORITY_NOT_SET:
            default:
                return MEA_IMG_NOTIF;
		}
    case MMS_SUFFIX_READREPORT:
        return (ctk_image_id)((read)?(MEA_IMG_RR_READ):(MEA_IMG_RR));
    case MMS_SUFFIX_DELIVERYREPORT:
        return (ctk_image_id)((read)?(MEA_IMG_DR_READ):(MEA_IMG_DR));
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAUIMH_27D90E6256B9738E7A271F385C9EA2B8, "(%s) (%d) createListItemImg suffix state (%d)\n", __FILE__, 
            __LINE__, suffix));
        return MEA_IMG_EMPTY;
	}
}
#endif /*MMS_SUPPORT*/
 #if (__MMI_MMS_TEMPLATES_NUM__ > 0)
/*!
 * \brief Creates Templates Message list.
 * \param list A linked list of folder items that are to be displayed.
 * \param folder The folder to create the list in.
 * \return TRUE if the menu was successfully created, otherwise FALSE.
 *
 *****************************************************************************/
static MSF_BOOL meaMhCreateMsgList(const MmsListOfProperties *list, char **itemList, 
    ctk_image_id * imgList)
{
#ifdef MMS_SUPPORT
#ifdef MMS_FILE_PROTECT_SUPPORT
    int index=0;// = list->noOfElements-1;
    MmsMessageFolderInfo *fInfo = NULL;
    char *subject=NULL;
    char *address=NULL;
    char *tmp[__MMI_MMS_TEMPLATES_NUM__];
    int i;

    for (i = 0; i<__MMI_MMS_TEMPLATES_NUM__; i++)
    	tmp[i]=NULL;
    
    for (index=0;index <=(int)list->noOfElements-1; index++)
    {      
        fInfo = &(list->msgPropertyList[index].msgFolderInfo);
        subject=NULL;
        getMmsMsgSubAddr(MSF_MODID_MEA,fInfo->msgId,&subject,&address,250);
        if(address)
            MEA_FREE(address);

        /* Get subject */        
        if ( (NULL != subject) && (0 != strlen(subject)))
        {    
  #ifdef MMS_TMPLATES_MULTIPLE_LANG_SUPPORT
			char *Ptr = NULL;
			unsigned char *mediaPtr = NULL;	
			int mediaSize=0;

			MEA_FREE(subject);		
			Ptr=GetString((MSF_UINT16)(fInfo->msgId+MMS_STR_ID_TEMPLATES_TITLE_01-1));
			if (!Ptr) 
			{
				subject = NULL;
			}
			else
			{
				mediaSize=widget_ucs2_length((kal_uint8*)Ptr)*2;
				MEA_CALLOC(mediaPtr,mediaSize+2);
				memset(mediaPtr,0x00,mediaSize+2);
				memcpy(mediaPtr,Ptr,mediaSize+1);
				mediaSize=widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)mediaPtr);
				MEA_CALLOC(Ptr,mediaSize+1);
				if(Ptr)
					widget_ucs2_to_utf8_string((kal_uint8*)Ptr,mediaSize+1,(kal_uint8*)mediaPtr);
				MEA_FREE(mediaPtr);
				subject=Ptr;
			}
  #endif /* MMS_TMPLATES_MULTIPLE_LANG_SUPPORT */
		    tmp[index]=subject;
        } 
    }
    for (i = __MMI_MMS_TEMPLATES_NUM__ - 1, index = 0; i >= 0; i--)
    {
	    if(tmp[i])
	    {
		    itemList[index]=tmp[i];
		    imgItemList[index] = createImgList(fInfo->suffix, fInfo->read, 
				fInfo->forwardLock, fInfo->priority, mmcIsJSRMsg(fInfo->msgId));
		    index++;
	    }        
    }
    return TRUE;
#else
    unsigned int index,listIndex = list->noOfElements-1;
    MmsMessageFolderInfo *fInfo;
    MmsMsgHandle msgHandle=NULL;
    MmsTransactionHandle transaction=NULL;
    MmsGetHeader header;
    MmsResult ret=MMS_RESULT_ERROR;
    char *addr=NULL;
    char *buffer=NULL;
    int  bufSize=0;
    MSF_BOOL freeHeader=FALSE;
    MSF_BOOL freeBuffer=FALSE;
	char *subject=NULL; //,*address=NULL;
	//MmsHeaderValue headerValue;
    MmsEncodedText enSubject;
    /* Add new elements to the list */
    for (index = 0; (unsigned int)index < list->noOfElements; index++)
    {
		fInfo = &(list->msgPropertyList[index].msgFolderInfo);
		/* Get image dependent on the read status and priority*/
		imgItemList[listIndex] = createImgList(fInfo->suffix, fInfo->read, 
			fInfo->forwardLock, fInfo->priority, mmcIsJSRMsg(fInfo->msgId));
		/* Open message and then get message header */ 
		freeHeader=FALSE;
		freeBuffer=FALSE;
		bufSize=0;
		buffer=NULL;
		subject=NULL;
		addr=NULL;
		enSubject.charset=MMS_UNKNOWN_CHARSET;
		enSubject.text=NULL;
		msgHandle=NULL;
		transaction=NULL;

		memset(&header,0x00,sizeof(MmsGetHeader));
		MMS_FILE_OPEN_BLOCK_FLAG=TRUE;
		if(MMSlib_messageOpen(MSF_MODID_MEA,fInfo->msgId,fInfo->suffix, &msgHandle)!=MMS_RESULT_OK)
		{}
		else if(MMSlib_transactionOpen(MSF_MODID_MEA,&transaction)!=MMS_RESULT_OK)
		{}
		else if((ret=MMSlib_getMessageHeader(MSF_MODID_MEA, &header, &msgHandle, &transaction))==MMS_RESULT_OK)
		{
			freeHeader=TRUE;
		}
		MMS_FILE_OPEN_BLOCK_FLAG=FALSE;	
		if(transaction)
		{
			MMSlib_transactionClose(MSF_MODID_MEA,&transaction);
		}
		if(msgHandle)
		{
			MMSlib_messageClose(MSF_MODID_MEA,&msgHandle);
		}
		msgHandle=NULL;
		transaction=NULL;
		if(freeHeader&&header.subject.text)
			subject=header.subject.text;
		/* subject */
		if ( (NULL != subject) && (0 != strlen(subject)))
		{    
			itemList[listIndex] = MEA_ALLOC(strlen(subject)+1);
			memset(itemList[listIndex],0,strlen(subject)+1);
			strcpy(itemList[listIndex],subject);
			if(enSubject.text)
				MEA_FREE(enSubject.text);
		}
		else
		{
           itemList[listIndex] = 0; //strNoSubject;
		}
        
        listIndex--;
		if(freeHeader)
            freeMmsGetHeader(MSF_MODID_MEA,&header);
        if(freeBuffer)
            MEA_FREE(buffer);
    }
    return TRUE;
  #endif /* MMS_FILE_PROTECT_SUPPORT */
  #endif /* MMS_SUPPORT*/
    return FALSE;
}
 #endif /* __MMI_MMS_TEMPLATES_NUM__ > 0 */

static void handleMhBackAction(ctk_screen_handle scrHandle)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MAUIMH_0AD3B15EC779E745ECC0FFDB075F843A, "(%s) (%d) Back action received 0x%x\n", __FILE__, __LINE__, 
        scrHandle));
    if (MEA_STARTUP_MODE_VIEW == meaGetStartupMode() || MEA_STARTUP_MODE_DOWNLOAD == meaGetStartupMode())
        (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
    else
    (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_DEACTIVATE);
    widget_send_update_event_to_wap();
}

static void useNumberNavMenuHandler(MeaNavAction action)
{
    if (MEA_NAV_ACTION_OK == action)
    {
        MSF_INT32 index = meaGetSelectedChoiceIndex(meaNumberListView.menuHandle);
        applib_address_node_struct *link = NULL;
        
        if (index < 0)
        {
        }
        else
        {
            link = getAddressNodeByIndex(meaNumberListView.list, index);
            if (MEA_MH_NUM_LIST_DIAL == meaGetUseDetailNavMenuItem())
            {
                meaSrhMakeCall(MEA_MH_FSM, MEA_SIG_MH_MAKE_CALL_RSP, link->data2);
                meaDeleteMhNavMenu(); 
                meaDeleteNumberListView();
            }
            else if (MEA_MH_NUM_LIST_SAVE_PHB == meaGetUseDetailNavMenuItem())
            {
                /* Save phonebook */
                int len= (widget_utf8_length((kal_uint8 *)link->data2) + 1) * UCS2_ENCODING_LENGTH;
                char * str = MEA_ALLOC(len);

                if (widget_utf8_length((kal_uint8 *)link->data) > 40)  /* 40: max length of number */
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_NUMBER_TOO_LONG), MsfError, 0);
                    MEA_FREE(str);
                    return;
                }

                widget_utf8_to_ucs2_string((kal_uint8 *)str, len, (kal_uint8 *)link->data2);
                HDIa_widgetExtSavePhoneNumber((kal_uint8*)str);
                MEA_FREE(str);
                meaDeleteMhNavMenu(); 
                meaDeleteNumberListView();
            }
            else if (MEA_MH_NUM_LIST_WRITE_MMS == meaGetUseDetailNavMenuItem())
            {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
                /* A little bit dirty cuz wap_send_mmi_mms_start_uc_req() didn't include this scenario */
                extern void mms_address_insert_hdlr(char *address);
                int len = (widget_utf8_length((kal_uint8 *)link->data) + 1) * UCS2_ENCODING_LENGTH;
                char *str = MEA_ALLOC(len);
                widget_utf8_to_ucs2_string((kal_uint8 *)str, len, (kal_uint8 *)link->data);
                mms_address_insert_hdlr(str);
                MEA_FREE(str);
                HDIa_widgetExtDeleteWidgetScreenIfPresent();
#else

                MeaCtContentInsert *ct;

                if (widget_utf8_length((kal_uint8 *)link->data) > 40)  /* 40: max length of number */
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_INVALID_RECIP_ADDRESS), MsfError, 0);
                    return;
                }

                ct = MEA_ALLOC(sizeof(MeaCtContentInsert));
                memset(ct, 0, sizeof(MeaCtContentInsert));
                MEA_CALLOC(ct->propItem, sizeof(MeaPropItem));
                MEA_CALLOC(ct->propItem->to, sizeof(MeaAddrItem));
                ct->propItem->to->addrType = MEA_ADDR_TYPE_PLMN;
                ct->propItem->to->address = msf_cmmn_strdup(MSF_MODID_MEA, link->data);

                (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);
#endif
                meaDeleteMhNavMenu(); 
                meaDeleteNumberListView();
#ifdef __UNIFIED_MSG_SUPPORT__
                if (meaIsModuleStarted(MSF_MODID_SMA))
                {
                    meaModuleStop(MSF_MODID_SMA, FALSE);
                }
                else
                {
                    (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);  /* Delete menu */
                    (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_DEACTIVATE);  /* Stop MMV */
                    (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);  /* Stop MOB */
                }
#endif
            }
#ifdef __UNIFIED_MSG_SUPPORT__            
            else if (MEA_MH_NUM_LIST_WRITE_SMS == meaGetUseDetailNavMenuItem())
            {
                int len = (widget_utf8_length((kal_uint8 *)link->data) + 1) * UCS2_ENCODING_LENGTH;
                char *str = MEA_ALLOC(len);
                msf_cmmn_strcpy_lc((char *)str, (char *)link->data);
                if (msf_cmmn_utf8_strlen(str) > 20)  /* 20: MAX_DIGITS_SMS */
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_NUMBER_TOO_LONG), MsfError, 0);
                    MEA_FREE(str);
                }
                else
                {
                    widget_execute_MMI_p(mms_enter_sms_editor_handler, str, FALSE);
                    (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
                }
            }
#endif /*__UNIFIED_MSG_SUPPORT__*/
        }
    }
    else if (MEA_NAV_ACTION_BACK == action)
    {
        (void)meaRemoveUseDetailNavMenu();
    }
}

static void handleMhSendAction(MsfWindowHandle winHandle)
{
    MSF_INT32 index = meaGetSelectedChoiceIndex(meaNumberListView.menuHandle);
    applib_address_node_struct *link = NULL;
    
    if (index < 0)
    {
        return;
    }
    
    link = getAddressNodeByIndex(meaNumberListView.list, index);
    if (link->dataType == APPLIB_ADDR_TYPE_PHONENUMBER )
    {
        if ( !isInCall() || ( isInCall() && GetWapCallPresent() ) )
        {
            meaSrhMakeCall(MEA_MH_FSM, MEA_SIG_MH_MAKE_CALL_RSP, link->data2);
            meaDeleteMhNavMenu(); 
            meaDeleteNumberListView();
        }
        else
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_NOT_AVAILABLE), MEA_DIALOG_ERROR);
            return;
        }
    }
    else if (link->dataType == APPLIB_ADDR_TYPE_URL && (!isInCall() || (isInCall() && GetWapCallPresent())))
    {
        char *url = NULL, *tmp = NULL;

        url = msf_cmmn_strdup(MSF_MODID_MEA, link->data);
        tmp = url;
        while ((tmp = strstr(tmp, ":\\\\")) != NULL)
        {
            *(tmp + 1) = '/';
            *(tmp + 2) = '/';
            tmp += 3;
        }
        
        (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
        BRAif_createUI(BRA_UI_GOTO_URL, url);
        MEA_FREE(url);
    }
    else if (link->dataType == APPLIB_ADDR_TYPE_EMAIL)
    {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
        extern void mms_address_insert_hdlr(char *address);
        int len = (widget_utf8_length((kal_uint8 *)link->data) + 1) * UCS2_ENCODING_LENGTH;
        char *str = MEA_ALLOC(len);

        if( link->length > MEA_ME_MAX_EMAIL_ADDRESS_SIZE)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_RECIP_ADDRESS), 
                MEA_DIALOG_ERROR);
            MEA_FREE(str);
            return;
        }

        widget_utf8_to_ucs2_string((kal_uint8 *)str, len, (kal_uint8 *)link->data);
        mms_address_insert_hdlr(str);
        MEA_FREE(str);
#else
        MeaCtContentInsert *ct = NULL;
        
        if( link->length > MEA_ME_MAX_EMAIL_ADDRESS_SIZE)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_RECIP_ADDRESS), 
                MEA_DIALOG_ERROR);
            return;
        }

        ct = MEA_ALLOC(sizeof(MeaCtContentInsert));

        memset(ct, 0, sizeof(MeaCtContentInsert));
        MEA_CALLOC(ct->propItem, sizeof(MeaPropItem));
        MEA_CALLOC(ct->propItem->to, sizeof(MeaAddrItem));
        ct->propItem->to->addrType = MEA_ADDR_TYPE_EMAIL;
        ct->propItem->to->address = msf_cmmn_strdup(MSF_MODID_MEA, link->data);

        (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);
#endif
        meaDeleteMhNavMenu(); 
        meaDeleteNumberListView();
#ifdef __UNIFIED_MSG_SUPPORT__
        if (meaIsModuleStarted(MSF_MODID_SMA))
        {
            meaModuleStop(MSF_MODID_SMA, FALSE);
        }
        else
        {
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);  /* Delete menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_DEACTIVATE);  /* Stop MMV */
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);  /* Stop MOB */
        }
#endif
    }
}

void meaMhWriteMessageByMail(const char *mail)
{
    MeaCtContentInsert *ct;// = MEA_ALLOC(sizeof(MeaCtContentInsert));

    if( msf_cmmn_utf8_strlen(mail) > MEA_ME_MAX_EMAIL_ADDRESS_SIZE)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_RECIP_ADDRESS), 
            MEA_DIALOG_ERROR);
        return;
    }
    ct = MEA_ALLOC(sizeof(MeaCtContentInsert));
    memset(ct, 0, sizeof(MeaCtContentInsert));
    MEA_CALLOC(ct->propItem, sizeof(MeaPropItem));
    MEA_CALLOC(ct->propItem->to, sizeof(MeaAddrItem));
    ct->propItem->to->addrType = MEA_ADDR_TYPE_EMAIL;
    ct->propItem->to->address = msf_cmmn_strdup(MSF_MODID_MEA, mail);

    (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);
}

MSF_BOOL meaMhCreateUseNumberNavMenu(void)
{
    if (!meaCreateUseDetailNavMenu(meaGetEmptyStringHandle(), useNumberNavMenuHandler))
    {
        return FALSE;
    }
    else if (!meaAddUseDetailNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_WRITE_MMS), 
        MEA_MH_NUM_LIST_WRITE_MMS))
    {
        return FALSE;
    }
#ifdef __UNIFIED_MSG_SUPPORT__                
    else if (!meaAddUseDetailNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_WRITE_SMS),
        MEA_MH_NUM_LIST_WRITE_SMS))
    {
        return FALSE;
    }
#endif /*__UNIFIED_MSG_SUPPORT__*/

    if (!isInCall() || (isInCall() && GetWapCallPresent()))
    {
        if (!meaAddUseDetailNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DIAL), 
        MEA_MH_NUM_LIST_DIAL))
        {
            return FALSE;
        }
    }
    
    if (!meaAddUseDetailNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SAVE_TO_PHONE_BOOK), 
        MEA_MH_NUM_LIST_SAVE_PHB))
    {
        return FALSE;
    }
    else if (!meaShowUseDetailNavMenu())
    {
        return FALSE;
    }
    return TRUE;
}

void meaDeleteNumberListView(void)
{
    meaRemoveUseDetailNavMenu();
    (void)meaDeleteWindow(meaNumberListView.menuHandle);
    applib_free_address_list(&meaNumberListView.list, meaFree);
    memset(&meaNumberListView, 0, sizeof(MeaMhView));
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    if (smaIsRunning())
    {
        /* Back to last SMA screen */
        (void)MSF_WIDGET_SET_IN_FOCUS(smaGetScreenHandle(), TRUE);
    }
#elif defined(MEA_CFG_USER_TEMPLATE_SUPPORT)
    if (smaIsRunning())
    {
        /* Back to last SMA screen */
        (void)MSF_WIDGET_SET_IN_FOCUS(smaGetScreenHandle(), TRUE);
    }
#endif
}

static void handleNumberListBackAction(MsfWindowHandle winHandle)
{
    meaDeleteNumberListView();
}

static applib_address_node_struct *getAddressNodeByIndex(applib_address_node_struct *list, MSF_UINT32 index)
{
    MSF_UINT32 i;

    applib_address_node_struct *ptr = list;
    for (i = 0; i < index && ptr != NULL; i++, ptr = ptr->next);
    return ptr;
}

static void useEmailNavMenuHandler(MeaNavAction action)
{
    if (MEA_NAV_ACTION_OK == action)
    {
        MSF_INT32 index = meaGetSelectedChoiceIndex(meaNumberListView.menuHandle);
        applib_address_node_struct *link = NULL;
        
        if (index < 0)
        {
        }
        else
        {
            link = getAddressNodeByIndex(meaNumberListView.list, index);
            if (MEA_MH_USE_EMAIL_WRITE_MMS == meaGetUseDetailNavMenuItem())
            {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
                /* A little bit dirty cuz wap_send_mmi_mms_start_uc_req() didn't include this scenario */
                extern void mms_address_insert_hdlr(char *address);
                int len = (widget_utf8_length((kal_uint8 *)link->data) + 1) * UCS2_ENCODING_LENGTH;
                char *str = MEA_ALLOC(len);
                widget_utf8_to_ucs2_string((kal_uint8 *)str, len, (kal_uint8 *)link->data);
                mms_address_insert_hdlr(str);
                MEA_FREE(str);
                HDIa_widgetExtDeleteWidgetScreenIfPresent();
#else

                MeaCtContentInsert *ct = MEA_ALLOC(sizeof(MeaCtContentInsert));
                
                if( link->length > MEA_ME_MAX_EMAIL_ADDRESS_SIZE)
                {
                    (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_RECIP_ADDRESS), 
                        MEA_DIALOG_ERROR);
                    return;
                }
                
                memset(ct, 0, sizeof(MeaCtContentInsert));
                MEA_CALLOC(ct->propItem, sizeof(MeaPropItem));
                MEA_CALLOC(ct->propItem->to, sizeof(MeaAddrItem));
                ct->propItem->to->addrType = MEA_ADDR_TYPE_EMAIL;
                ct->propItem->to->address = msf_cmmn_strdup(MSF_MODID_MEA, link->data);

                (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, MEA_ME_STARTUP_NEW_SMIL, ct);
#endif
    			meaDeleteMhNavMenu(); 
                meaDeleteNumberListView();
#ifdef __UNIFIED_MSG_SUPPORT__
                if (meaIsModuleStarted(MSF_MODID_SMA))
                {
                    meaModuleStop(MSF_MODID_SMA, FALSE);
                }
                else
                {
                    (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);  /* Delete menu */
                    (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_DEACTIVATE);  /* Stop MMV */
                    (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);  /* Stop MOB */
                }
#endif
            }
            else if (MEA_MH_USE_EMAIL_SAVE_PHB== meaGetUseDetailNavMenuItem())  /* Save to phonebook */
            {
                int len = (widget_utf8_length((kal_uint8 *)link->data) + 1) * UCS2_ENCODING_LENGTH;
                char *str = MEA_ALLOC(len);

                if (widget_utf8_length((kal_uint8 *)link->data) > MEA_ME_MAX_EMAIL_ADDRESS_SIZE)  /* 60: max length of email */
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_NUMBER_TOO_LONG), MsfError, 0);
                    MEA_FREE(str);
                    return;
                }

                widget_utf8_to_ucs2_string((kal_uint8 *)str, len, (kal_uint8 *)link->data);
                HDIa_widgetExtSaveEmail((kal_uint8*)str);
                MEA_FREE(str);
                meaDeleteMhNavMenu(); 
                meaDeleteNumberListView();
            }
        }
    }
    else if (MEA_NAV_ACTION_BACK == action)
    {
        meaRemoveUseDetailNavMenu();
    }
}

static void useUrlNavMenuHandler(MeaNavAction action)
{
    if (MEA_NAV_ACTION_OK == action)
    {
        MSF_INT32 index = meaGetSelectedChoiceIndex(meaNumberListView.menuHandle);
        applib_address_node_struct *link = NULL;
        
        if (index < 0)
        {
        }
        else
        {
            char *url = NULL, *tmp = NULL;
            
            link = getAddressNodeByIndex(meaNumberListView.list, index);
            url = msf_cmmn_strdup(MSF_MODID_MEA, link->data);
            tmp = url;
            while ((tmp = strstr(tmp, ":\\\\")) != NULL)
            {
                *(tmp + 1) = '/';
                *(tmp + 2) = '/';
                tmp += 3;
            }
            
            if (MEA_MH_USE_URL_BROWSE == meaGetUseDetailNavMenuItem())
            {
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
                BRAif_createUI(BRA_UI_GOTO_URL, url);
            }
            else if (MEA_MH_USE_URL_ADD_BOOKMARK == meaGetUseDetailNavMenuItem())
            {
                BRAif_createUI (BRA_UI_ADD_BOOKMARK, url);
            }
            MEA_FREE(url);
        }
    }
    else if (MEA_NAV_ACTION_BACK == action)
    {
        meaRemoveUseDetailNavMenu();
    }
}

MSF_BOOL meaMhCreateUseEmailNavMenu(void)
{
    if (!meaCreateUseDetailNavMenu(meaGetEmptyStringHandle(), useEmailNavMenuHandler))
    {
        return FALSE;
    }
    else if (!meaAddUseDetailNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_WRITE_MESSAGE), MEA_MH_USE_EMAIL_WRITE_MMS))
    {
        return FALSE;
    }
    else if (!meaAddUseDetailNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SAVE_TO_PHONE_BOOK), MEA_MH_USE_EMAIL_SAVE_PHB))
    {
        return FALSE;
    }
    else if (!meaShowUseDetailNavMenu())
    {
        return FALSE;
    }
    return TRUE;
}

MSF_BOOL meaMhCreateUseUrlNavMenu(void)
{
    if (!meaCreateUseDetailNavMenu(meaGetEmptyStringHandle(), useUrlNavMenuHandler))
    {
        return FALSE;
    }

    if (!isInCall() || (isInCall() && GetWapCallPresent()))
    {
        if (!meaAddUseDetailNavMenuItem(MEA_GET_STR_ID(BRA_STR_ID_GOTO), MEA_MH_USE_URL_BROWSE))
        {
            return FALSE;
        }
    }
    
    if (!meaAddUseDetailNavMenuItem(MEA_GET_STR_ID(BRA_STR_ID_ADD_BOOKMARK), MEA_MH_USE_URL_ADD_BOOKMARK))
    {
        return FALSE;
    }
    else if (!meaShowUseDetailNavMenu())
    {
        return FALSE;
    }
    return TRUE;
}

void meaMhCreateUseDetailNavMenu(void)
{
    MSF_INT32 index = meaGetSelectedChoiceIndex(meaNumberListView.menuHandle);
    applib_address_node_struct *link = NULL;

    if (index < 0)
    {
        return;
    }

    link = getAddressNodeByIndex(meaNumberListView.list, index);
    switch (link->dataType)
    {
    case APPLIB_ADDR_TYPE_EMAIL:
        if (meaMhCreateUseEmailNavMenu() != TRUE)
        {
            meaRemoveUseDetailNavMenu();
        }
        break;
    case APPLIB_ADDR_TYPE_URL:
        if (meaMhCreateUseUrlNavMenu() != TRUE)
        {
            meaRemoveUseDetailNavMenu();
        }
        break;
    case APPLIB_ADDR_TYPE_PHONENUMBER:
        if (meaMhCreateUseNumberNavMenu() != TRUE)
        {
            meaRemoveUseDetailNavMenu();
        }
        break;
    default:
        ASSERT(0);
    }
}

static kal_bool meaMhCheckStopFunc(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 no)
{
    if (addr)
    {
        meaMhBufferSize += sizeof(applib_address_node_struct);
    }
    if (addr->data)
    {
        meaMhBufferSize += strlen(addr->data);
    }
    if (addr->data2)
    {
        meaMhBufferSize += strlen(addr->data2);
    }
    
    if (meaMhBufferSize > MMS_PARSING_BUFFER_SIZE)
    {
        return KAL_TRUE;
    }
    
    return KAL_FALSE;
}

applib_address_node_struct *meaMhCreateDetailListFromHeader(MmsMsgId msgId)
{
    MmsFileType msgType = fldrGetFileSuffix(msgId);
    applib_address_node_struct *list = NULL;
    applib_address_node_struct *tmpList = NULL;

    if (msgType == MMS_SUFFIX_NOTIFICATION || msgType == MMS_SUFFIX_IMMEDIATE || msgType == MMS_SUFFIX_TEMPLATE ||
        msgType == MMS_SUFFIX_SEND_REQ || msgType == MMS_SUFFIX_MSG)
    {
        MmsMsgHandle mHandle;
        MmsTransactionHandle tHandle;
        MmsGetHeader header;
        MmsNotification nHeader;
        MmsAddressList *addrList;

        if (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, &tHandle))
        {
             return NULL;
        }   
        else if (MMS_RESULT_OK != MMSlib_messageOpen(MSF_MODID_MEA, msgId, msgType, &mHandle))
        {
            MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
            MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
            return NULL;
        }	

        switch (msgType)
        {
        case MMS_SUFFIX_NOTIFICATION:  /* From and Subject fields */
        case MMS_SUFFIX_IMMEDIATE:
            if (MMS_RESULT_OK != MMSlib_getNotification(MSF_MODID_MEA, &nHeader, &mHandle, &tHandle))
            {
                break;
            }

            if (nHeader.from.address != NULL)  /* From */
            {
                tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER,
                                                             (applib_mem_alloc_fn)meaAlloc, 
                                                             meaFree, 
                                                             nHeader.from.address, 
                                                             strlen(nHeader.from.address));
    
                list = applib_concatenate_address_list(list, tmpList);
            }

            if (nHeader.subject.text != NULL)  /* Subject */
            {
                tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_URL | 
                                                             APPLIB_ADDR_TYPE_EMAIL | 
                                                             APPLIB_ADDR_TYPE_PHONENUMBER,
                                                             (applib_mem_alloc_fn)meaAlloc, 
                                                             meaFree, 
                                                             nHeader.subject.text, 
                                                             strlen(nHeader.subject.text));
    
                list = applib_concatenate_address_list(list, tmpList);
            }
            freeMmsNotification(MSF_MODID_MEA, &nHeader);
            break;
            
        case MMS_SUFFIX_TEMPLATE:
        case MMS_SUFFIX_SEND_REQ:
        case MMS_SUFFIX_MSG:
            if (MMS_RESULT_OK != MMSlib_getMessageHeader(MSF_MODID_MEA, &header, &mHandle, &tHandle))
            {
                break;
            }   
            
            if (header.from.address != NULL)  /* From */
            {
                tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER,
                                                             (applib_mem_alloc_fn)meaAlloc, 
                                                             meaFree, 
                                                             header.from.address, 
                                                             strlen(header.from.address));
    
                list = applib_concatenate_address_list(list, tmpList);
            }

            if ((addrList = header.to) != NULL)  /* To */
            {
                while(addrList)
                {
                    tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER,
                                                                 (applib_mem_alloc_fn)meaAlloc, 
                                                                 meaFree, 
                                                                 addrList->current.address, 
                                                                 strlen(addrList->current.address));
                    
                    list = applib_concatenate_address_list(list, tmpList);
                    addrList=addrList->next;
                }
            }

            if ((addrList = header.cc) != NULL)  /* CC */
            {
                while(addrList)
                {
                    tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER,
                                                                 (applib_mem_alloc_fn)meaAlloc, 
                                                                 meaFree, 
                                                                 addrList->current.address, 
                                                                 strlen(addrList->current.address));
                    
                    list = applib_concatenate_address_list(list, tmpList);
                    addrList=addrList->next;
                }
            }

            if ((addrList = header.bcc) != NULL)  /* BCC */
            {
                while(addrList)
                {
                    tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER,
                                                                 (applib_mem_alloc_fn)meaAlloc, 
                                                                 meaFree, 
                                                                 addrList->current.address, 
                                                                 strlen(addrList->current.address));
                    
                    list = applib_concatenate_address_list(list, tmpList);
                    addrList=addrList->next;
                }
            }

            if (header.subject.text != NULL)  /* Subject */
            {
                tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_URL | 
                                                             APPLIB_ADDR_TYPE_EMAIL | 
                                                             APPLIB_ADDR_TYPE_PHONENUMBER,
                                                             (applib_mem_alloc_fn)meaAlloc, 
                                                             meaFree, 
                                                             header.subject.text, 
                                                             strlen(header.subject.text));
    
                list = applib_concatenate_address_list(list, tmpList);
            }

            freeMmsGetHeader(MSF_MODID_MEA, &header);
            break;
        }
        MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
        MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
    }
    else if (msgType == MMS_SUFFIX_READREPORT || msgType == MMS_SUFFIX_DELIVERYREPORT)  /* to and from(only rr) fields */
    {
        char *buffer = NULL;
        int size = 0;
        MmsAddress from; 
        MmsAddressList *address = NULL;

        loadMmsDataToBuffer(MSF_MODID_MEA, msgId, (MSF_UINT8)msgType, &buffer, &size);        
        if (buffer != NULL)
        {
            if ((parseFromAddress( MSF_MODID_MEA, (unsigned char *)buffer, size, &from) != FALSE) && 
                (from.address != NULL))
            {
                tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER,
                                                             (applib_mem_alloc_fn)meaAlloc, 
                                                             meaFree, 
                                                             from.address, 
                                                             strlen(from.address));
    
                list = applib_concatenate_address_list(list, tmpList);
            }
            
            MEA_FREE(from.address);
            MEA_FREE(from.name.text);
            
            if ((address = parseAddress(MSF_MODID_MEA, MMS_TO, (unsigned char*)buffer, size)) != NULL)
            {
                MmsAddressList *ptr = address;
                while(ptr)
                {
                    if(ptr->current.address)
                    {
                        tmpList = applib_get_address_list_from_text(APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER,
                                                                     (applib_mem_alloc_fn)meaAlloc, 
                                                                     meaFree, 
                                                                     ptr->current.address, 
                                                                     strlen(ptr->current.address));
                        
                        list = applib_concatenate_address_list(list, tmpList);
                    }
                    ptr = ptr->next;
                }
                freeMmsAddressList(MSF_MODID_MEA, address);
            }
            MEA_FREE(buffer);
        }
    }

    return list;
}

void meaMhTruncAddressList(applib_address_node_struct *srcList)
{
    applib_address_node_struct *p = srcList;
    applib_address_node_struct *q = p;
    int i = 0;

    while (i <= MMS_PARSING_LINK_MAX_NUM && p != NULL)
    {
        q = p;
        p = p->next;
        i++;
    }

    if (i > MMS_PARSING_LINK_MAX_NUM && p != NULL)
    {
        q->next = NULL;
        applib_free_address_list(&p, meaFree);
    }

    return;
}
applib_address_node_struct *meaMhCreateDetailListFromBody(MmsMsgId msgId, SlsUnrefItemList *unrefItems)
{
    int fh = 0;
    char *path;
    MmsFileType msgType = fldrGetFileSuffix(msgId);
    MmsGetHeader header;
    MmsMsgHandle mHandle;
    MmsTransactionHandle tHandle;
    applib_address_node_struct *list = NULL;
    applib_address_node_struct *tmpList = NULL;
    SlsUnrefItemList * unrefObj = unrefItems;

    if ( msgType != MMS_SUFFIX_TEMPLATE && msgType != MMS_SUFFIX_SEND_REQ && msgType != MMS_SUFFIX_MSG)
    {
        return NULL;
    }

    if (MMS_RESULT_OK != MMSlib_transactionOpen(MSF_MODID_MEA, &tHandle))
    {
         return NULL;
    }   
    else if (MMS_RESULT_OK != MMSlib_messageOpen(MSF_MODID_MEA, msgId, msgType, &mHandle))
    {
        MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
        return NULL;
    }	
    else if (MMS_RESULT_OK != MMSlib_getMessageHeader(MSF_MODID_MEA, &header, &mHandle, &tHandle))
    {
        return NULL;
    }   

    /* Get MMS file path */
    path = MMSlib_getMessageFullPath(MSF_MODID_MEA, msgId, msgType);
    fh = MSF_FILE_OPEN(MSF_MODID_MEA, path, HDI_FILE_SET_RDONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0);
    MEA_FREE(path);
    if (fh >= 0)
    {
        MmsBodyInfoList *body = &header.bodyInfoList;
        char *buffer = NULL;
        MSF_UINT32 size = 0;
        meaMhBufferSize = 0;
        
        while (body)
        {
            unrefObj = unrefItems;            
            while (unrefObj != NULL && unrefObj->offset != body->startPos)
            {
                unrefObj = unrefObj->next;
            }
            if (unrefObj == NULL && body->contentType != NULL && body->contentType->knownValue == MMS_TYPE_TEXT_PLAIN && body->size > 0)
            {
                size = (body->size > MEA_CFG_INSERT_TEXT_MAX_SIZE) ? MEA_CFG_INSERT_TEXT_MAX_SIZE : body->size;
                if ((buffer = (char *)MEA_ALLOC(size + 1)) != NULL)
                {
                    memset(buffer, 0x00, size + 1);
                    if (body->startPos != (MSF_UINT32)HDIa_fileSeek(fh, body->startPos, HDI_FILE_SEEK_SET))
                    {
                        break;
                    }
                    else if (size != (MSF_UINT32)HDIa_fileRead(fh, buffer, size))
                    {
                        break;
                    }
                    else
                    {
                        kal_bool stopped = KAL_FALSE;

                        if((size > MEA_UTF16_BOM_LEN) &&
                            ((memcmp(buffer, MEA_UTF16_BOM_BIG, MEA_UTF16_BOM_LEN) == 0) ||
                            (memcmp(buffer, MEA_UTF16_BOM_LITTELE, MEA_UTF16_BOM_LEN) == 0)))
                        {
                            if (!meaConvertToUTF8(MSF_CHARSET_UTF_16, &size, (unsigned char **)&buffer))
                            {
                                break;
                            }
                        }

                        tmpList = applib_get_address_list_from_text_ext(
                                       APPLIB_ADDR_TYPE_URL | APPLIB_ADDR_TYPE_EMAIL | APPLIB_ADDR_TYPE_PHONENUMBER, 
                                       (applib_mem_alloc_fn)meaAlloc, 
                                       meaFree,
                                       meaMhCheckStopFunc,
                                       APPLIB_INPUT_DATA_TYPE_UTF8,
                                       buffer, 
                                       strlen(buffer),
                                       &stopped);

                        list = applib_concatenate_address_list(list, tmpList);
                        applib_remove_duplicate_address(&list, meaFree);    
                        meaMhTruncAddressList(list);
                    }
                    MEA_FREE(buffer);
                }
            }
            body = body->next;
        }
    }
    MSF_FILE_CLOSE(fh);
    freeMmsGetHeader(MSF_MODID_MEA, &header);
    MMSlib_transactionClose(MSF_MODID_MEA, &tHandle);
    MMSlib_messageClose(MSF_MODID_MEA, &mHandle);
    return list;
}

void meaSetUseNumberMsgID(MmsMsgId msgId)
{
    useNumberMsgId = msgId;
    return;
}

MmsMsgId meaGetUseNumberMsgID(void)
{
    return useNumberMsgId;
}

MSF_BOOL meaCreateDetailListView(MmsMsgId msgId, SlsUnrefItemList *unrefItems)
{
    MmsFileType msgType = fldrGetFileSuffix(msgId);
    applib_address_node_struct *list = NULL, *tmplist = NULL;
    MsfActionHandle actionHandle;
    MsfStringHandle strHandle;
    int i;
    
    list = meaMhCreateDetailListFromHeader(msgId);
    if (msgType == MMS_SUFFIX_TEMPLATE || msgType == MMS_SUFFIX_MSG || msgType == MMS_SUFFIX_SEND_REQ)
    {
        tmplist = meaMhCreateDetailListFromBody(msgId, unrefItems);
        list = applib_concatenate_address_list(list, tmplist);
    }

    applib_remove_duplicate_address(&list, meaFree);    
    if (list == NULL)
    {
        meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
        return TRUE;
    }

    /* Check that this view is not already active */
    if (0 != meaNumberListView.menuHandle)
    {
        applib_free_address_list(&list, meaFree);
        return FALSE;
    }
    else if (0 == (actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_OPTIONS), 
        MsfSelect, 0, MSF_ACTION_PROPERTY_ENABLED)))
    {
        applib_free_address_list(&list, meaFree);
        return FALSE;
    }
    else if (0 == (meaNumberListView.menuHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_MEA, 
        MsfImplicitChoice, NULL, actionHandle, NULL, 
        MSF_CHOICE_ELEMENT_IMAGE_1 | MSF_CHOICE_ELEMENT_IMAGE_2 | 
        MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_STRING_2, 
        MENU_PROPERTIES, 0)))
    {
        applib_free_address_list(&list, meaFree);
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return FALSE;
    }
    else if (!meaRegisterAction(meaNumberListView.menuHandle, actionHandle, NULL, MEA_MH_FSM, MEA_SIG_MH_NUMBER_OPTION))  /*  LSK: Option */
    {
        applib_free_address_list(&list, meaFree);
        (void)MSF_WIDGET_RELEASE(actionHandle);
        meaDeleteNumberListView();
        return FALSE;
    }
    else if (0 == meaCreateAction(meaNumberListView.menuHandle, MsfBack, handleNumberListBackAction, 
        MEA_NOTUSED_FSM, 0, MEA_STR_ID_BACK))  /*  RSK: Back */
    {
        applib_free_address_list(&list, meaFree);
        meaDeleteNumberListView();  /* actionHandle'd be released in it */
        return FALSE;
    }
    else if (meaRegisterUserEvent(meaNumberListView.menuHandle, MsfKey_Yes, handleMhSendAction, (MeaStateMachine)0, 0) < 0)  /* Send key */
    {
        applib_free_address_list(&list, meaFree);
        meaDeleteNumberListView();
        return FALSE;
    }
    else
    {
        tmplist = list;
		i = 0;
        while (tmplist != NULL && i < MAX_FIXED_ICONTEXT_MENU_ITEMS) /* Max item number*/
        {
            /* Add content to the list*/
/*            if (tmplist->dataType == APPLIB_ADDR_TYPE_PHONENUMBER)
            {
                strHandle = createString(tmplist->data2);
            }
            else
            {*/
                strHandle = createString(tmplist->data);
//            }
            
    		if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaNumberListView.menuHandle, i++, strHandle, 0, 0, 0, TRUE))
            {
                applib_free_address_list(&list, meaFree);
                meaDeleteNumberListView();
                (void)MSF_WIDGET_RELEASE(strHandle);
                return FALSE;
            }
            tmplist = tmplist->next;
            (void)MSF_WIDGET_RELEASE(strHandle);
        }

        meaNumberListView.list = list;
        meaSetTitle(meaNumberListView.menuHandle, MEA_GET_STR_ID(MEA_STR_ID_USE_DETAILS), 0);
        return meaDisplayWindow(meaNumberListView.menuHandle, meaGetPosLeftTop());
    }
}

static void handleStartupBackAction(ctk_screen_handle id)
{
    CTK_UNUSED(id);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
        MAUIMH_C67F304346753CD139BC955A73F979B5, "(%s) (%d) Back action received\n", __FILE__, __LINE__));
    /* The MEA_TERMINATE call cannot be used directly 
       because then memory will not be de-allocated */
    (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
    widget_send_update_event_to_wap();
}

/*!
 * \brief Create MMS Main Menu hint list.
 * \param The hint list
 *****************************************************************************/
static void meaCreateHintList(char **hintList)
{
	int i;
    if ( HDIa_fileCheckDirExist(MMS_FOLDER))
	{
		MmsFolderType emptyFolder = MMS_NO_FOLDER;
		for (i=0;i<MEA_MH_MENU_COUNT;i++)
		{
			if (meaMenuFolderItem[i]>0)
			{
				MSF_UINT16 nMsgs, nUnreadMsgs; //, nNotifs;
				fldrMgrGetNumberOfMessages((MSF_UINT16)meaMenuFolderItem[i],&nMsgs,&nUnreadMsgs);
				if (nMsgs == 0)
					emptyFolder = (MmsFolderType)(emptyFolder | meaMenuFolderItem[i]);
				if (nMsgs < 2)
                {
                    hintList[i] = MEA_ALLOC(strlen("xxx ")+strlen(strMsg)+1);
					sprintf(hintList[i], "%u %s", nMsgs, strMsg);
                }
				else
                {            
                    hintList[i] = MEA_ALLOC(strlen("xxx ")+strlen(strMsgs)+1);
					sprintf(hintList[i], "%u %s", nMsgs, strMsgs);
                }
			}
			else
			{
				hintList[i] = NULL;
			}
		}
		meaEmptyFolder = emptyFolder;
	}
	else
	{
		for (i=0;i<MEA_MH_MENU_COUNT;i++)
		{
			if (meaMenuFolderItem[i]>0)
			{
				hintList[i] = MEA_ALLOC(strlen("0 ")+strlen(strMsg)+1);
				sprintf(hintList[i], "0 %s", strMsg);
			}
			else
			{
				hintList[i] = NULL;
			}
		}
		meaEmptyFolder = MMS_ALL_FOLDERS; //all folders are empty
	}
}

/*!
 * \brief Update MMS Main Menu hint list.
 *****************************************************************************/
void updateHintList(void)
{
	int i;
	MmsFolderType emptyFolder = MMS_NO_FOLDER;
	char* updatedHint = NULL;
	MSF_UINT16 totalNoOfMsg = 0;  
	int len = 0;
	for (i=0;i<MEA_MH_MENU_COUNT;i++)
	{
		if (meaMenuFolderItem[i]>0)
		{
			MSF_UINT16 nMsgs, nUnreadMsgs; //, nNotifs;
			fldrMgrGetNumberOfMessages((MSF_UINT16)meaMenuFolderItem[i],&nMsgs,&nUnreadMsgs);

			if (nMsgs == 0)
				emptyFolder = (MmsFolderType)(emptyFolder | meaMenuFolderItem[i]);

			if (nMsgs < 2)
            {         
                len = strlen("xxx ")+strlen(strMsg)+1;
                updatedHint = MEA_ALLOC(len);
       			memset(updatedHint, 0, len);
				_snprintf(updatedHint, len, "%u %s", nMsgs, strMsg);
            }
			else
            {         
                len = strlen("xxx ")+strlen(strMsgs)+1;
                updatedHint = MEA_ALLOC(len);
       			memset(updatedHint, 0, len);
				_snprintf(updatedHint, len, "%u %s", nMsgs, strMsgs);
            }
			//updatedHint[len-1] = '\0';
			HDIa_widgetExtListMenuUpdateHint(meaStartupMenu.menuHandle, 
				(kal_uint8 *)updatedHint , i, KAL_TRUE);
			totalNoOfMsg = (MSF_UINT16)(nMsgs + totalNoOfMsg);
		}
	}
	MEA_FREE(updatedHint);
	meaEmptyFolder = emptyFolder;
}

/*!
 * \brief Free hint list
 *****************************************************************************/
static void freeHintList(char **hintList)
{
	int i;
	for (i=0;i<MEA_MH_MENU_COUNT;i++)
		MEA_FREE(hintList[i]);
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
#endif 
/*!
 * \brief Frees a #MeaMhMessage structure completely
 *
 * \param msg The #MeaMhMessage structure to dispose of
 *****************************************************************************/
#if  0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/
#endif /* WAP_SUPPORT */

/*!
 * \brief Gets the index of the MH menu item that is currently selected.
 *
 * \return The index of the selected menu item, or -1 if no item is selected.
 *
 *****************************************************************************/
int meaGetSelectedMhItem(void)
{
    if (0 == meaMhView.menuHandle)
        return -1;
    return meaGetSelectedChoiceIndex(meaMhView.menuHandle);
}

/*!
 * \brief Deletes the MH view.
 *
 * \return TRUE if the operation was successful, otherwise FALSE.
 *
 *****************************************************************************/
void meaDeleteMhView()
{
    (void)meaDeleteWindow(meaMhView.menuHandle);
    /* Delete obsolete data */
    memset(&meaMhView, 0, sizeof(MeaMhView));
}

/*!
 *  \brief Creates the context sensitive menu for the message handler.
 *
 *  \param folder The folder that i currently active.
 *  \param activeMsgId Message ID of the active message
 *  \param msgType The type of the active message. See #MmsFileType.
 *  \param forwardLock TRUE if the current message has a forward lock, 
 *                     otherwise FALSE.
 *  \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
#ifdef MMS_SUPPORT 
static int createMenuItems(MeaFolder folder, MmsMsgId activeMsgId, 
    MmsFileType msgType, MSF_BOOL forwardLock, MSF_BOOL isJSR
#ifdef __MMI_MMS_BGSR_SUPPORT__
    , mmi_mms_bgsr_msg_info_struct * msg_info
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
    )
{
#ifndef __UNIFIED_MSG_SUPPORT__
    int index = 0;
#endif /*__UNIFIED_MSG_SUPPORT__*/
    char *subject = NULL, *address = NULL;
    MeaAddrType addrType = MEA_ADDR_TYPE_NONE;

    getMmsMsgSubAddr(MSF_MODID_MEA, meaGetActiveMm()->msgId, &subject, &address, 250);
    addrType = meaGetAddrType(address);

#ifndef __UNIFIED_MSG_SUPPORT__
    index =HDIa_widgetExtListMenuGetHilighted(meaMhView.menuHandle);
    index = HDIa_widgetExtListMenuGetCount(meaMhView.menuHandle)-index-1;
    meaSetActiveMm(index);

  #if defined(MEA_MERGE_SENT)
    if (folder==MEA_FOLDER_OUTBOX)
        folder = ((MMS_SENT == fldrGetFolderId(activeMsgId)) ? MEA_FOLDER_SENT : MEA_FOLDER_OUTBOX);
  #elif defined(MEA_MERGE_OUTBOX)
    if (folder==MEA_FOLDER_OUTBOX)
        folder = ((MMS_DRAFTS == fldrGetFolderId(activeMsgId)) ? MEA_FOLDER_DRAFTS : MEA_FOLDER_OUTBOX);
  #endif /* defined(MEA_MERGE_SENT) */
#endif /*__UNIFIED_MSG_SUPPORT__*/

#ifdef __UNIFIED_MSG_SUPPORT__
    if ( (0 < activeMsgId) && (msgType != MMS_SUFFIX_NOTIFICATION) )
#else
    if ((0 < activeMsgId) && (msgType != MMS_SUFFIX_NOTIFICATION) && (msgType != MMS_SUFFIX_IMMEDIATE))
#endif  /*__UNIFIED_MSG_SUPPORT__*/
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        if(folder != MEA_FOLDER_OUTBOX)
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
	        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_VIEW), MEA_MH_VIEW_MM))
	        {
	            ASSERT(0);
	        }
    }

    /* Download */
    if ((0 < activeMsgId) && ((msgType == MMS_SUFFIX_NOTIFICATION) || (msgType == MMS_SUFFIX_IMMEDIATE))
        && (!isJSR))
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        if(msg_info != NULL)
        {
            if(msg_info->status != MMI_MMS_BGSR_STATUS_DOWNLOADING)
            {
		        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DOWNLOAD), MEA_MH_DOWNLOAD))
		        {
		            ASSERT(0);
		        }
			}
#ifndef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
            if( msg_info->status == MMI_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD ||
                 msg_info->status == MMI_MMS_BGSR_STATUS_DOWNLOADING)
            {
                if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_CANCEL), MEA_MH_CANCEL_DOWNLOAD))
                {
		            ASSERT(0);
                }
            }
#endif /*__MMI_MMS_BGSR_CANCEL_PROHIBIT__*/
        }
        else
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
        {
            if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DOWNLOAD), MEA_MH_DOWNLOAD))
            {
	            ASSERT(0);
            }
        }
    }

    /* Use template */
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    if ((activeMsgId > 0) && ((MEA_FOLDER_TEMPLATE == folder) || (MEA_FOLDER_USER_TEMPLATE == folder)))
#else
    if ((activeMsgId > 0) && (MEA_FOLDER_TEMPLATE == folder))
#endif
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_NEW_MSG_FROM_TEMPL), MEA_MH_USING_TEMPLATE))
        {
            ASSERT(0);
        }
    }

    /* Send */
    if ((0 != activeMsgId) && (msgType == MMS_SUFFIX_SEND_REQ) && 
        (MEA_FOLDER_TEMPLATE != folder) && (MEA_FOLDER_SENT != folder)
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    && (MEA_FOLDER_ARCHIVE != folder)
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
    && (MEA_FOLDER_USER_TEMPLATE != folder)
#endif
    )
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__    
        if(msg_info != NULL)
        {
            if(msg_info->status != MMI_MMS_BGSR_STATUS_SENDING)
            {
                if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SEND), MEA_MH_SEND))
                {
		           ASSERT(0);
                }
            }
            if( msg_info->status == MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND ||
                 msg_info->status == MMI_MMS_BGSR_STATUS_SENDING)
            {
                if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_CANCEL), MEA_MH_CANCEL_SEND))
                {
		           ASSERT(0);
                }
            }
        }
        else
#endif /*__MMI_MMS_BGSR_SUPPORT__*/            
        {
            if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SEND), MEA_MH_SEND))
            {
	           ASSERT(0);
            }
       }
    }

#ifndef __UNIFIED_MESSAGE_MMS_REPLY_BY_SMS_FIRST__
    /* Reply */
    if ((0 < activeMsgId) && (msgType == MMS_SUFFIX_MSG) && (!isJSR) && (addrType != MEA_ADDR_TYPE_NONE))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REPLY), MEA_MH_REPLY))
        {
            ASSERT(0);
        }
    }
#endif

    /* Reply by SMS */
    if ((0 < activeMsgId) && (msgType == MMS_SUFFIX_MSG) && (!isJSR) && (addrType == MEA_ADDR_TYPE_PLMN))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REPLY_SMS), MEA_MH_REPLY_SMS))
        {
            ASSERT(0);
        }
    }

#ifdef __UNIFIED_MESSAGE_MMS_REPLY_BY_SMS_FIRST__
    /* Reply */
    if ((0 < activeMsgId) && (msgType == MMS_SUFFIX_MSG) && (!isJSR) && (addrType != MEA_ADDR_TYPE_NONE))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REPLY), MEA_MH_REPLY))
        {
            ASSERT(0);
        }
    }
#endif

    /* Reply all - should only be visible when several recipients exists */
    /* CR to be written */
    if ((0 < activeMsgId) && (msgType == MMS_SUFFIX_MSG) && (!isJSR) && (addrType != MEA_ADDR_TYPE_NONE))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REPLY_TO_ALL), MEA_MH_REPLY_ALL))
        {
            ASSERT(0);
        }
    }

    /* Forward */
    if ((0 < activeMsgId) && (msgType == MMS_SUFFIX_MSG || MEA_FOLDER_SENT == folder) && 
        (!forwardLock) && (!isJSR)
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    || ((MEA_FOLDER_ARCHIVE == folder) && (msgType != MMS_SUFFIX_DELIVERYREPORT) && 
        (msgType != MMS_SUFFIX_NOTIFICATION) && (!forwardLock) && (!isJSR) && (0 < activeMsgId))
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    )
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_FORWARD), MEA_MH_FORWARD))
        {
            ASSERT(0);
        }
    }
    
    /* Edit message */
#ifdef __UNIFIED_MSG_SUPPORT__
    if ((0 != activeMsgId) && (MEA_FOLDER_TEMPLATE != folder) && 
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        (MEA_FOLDER_USER_TEMPLATE != folder) &&
    #endif
        (msgType == MMS_SUFFIX_SEND_REQ || msgType == MMS_SUFFIX_MSG) && (!isJSR))
#else
    if ((0 != activeMsgId) && 
        (msgType == MMS_SUFFIX_SEND_REQ) && 
        (MEA_FOLDER_OUTBOX != folder) &&
    #ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        (MEA_FOLDER_USER_TEMPLATE != folder) &&
    #endif
        (!isJSR))
#endif
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        if(folder != MEA_FOLDER_OUTBOX)
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
	        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT), MEA_MH_EDIT_MM))
	        {
	            ASSERT(0);
	        }
    }

    /* Delete only if a message is selected */
    if ((0 < activeMsgId) && (MEA_FOLDER_TEMPLATE != folder))
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__    
        if(msg_info != NULL)
        {
            if(msg_info->status != MMI_MMS_BGSR_STATUS_SENDING &&
                msg_info->status != MMI_MMS_BGSR_STATUS_DOWNLOADING)
            {
                if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE), MEA_MH_DELETE_MM))
                {
		            ASSERT(0);
                }

                if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE_ALL), MEA_MH_DELETE_MM_ALL))
                {
		            ASSERT(0);
                }
            }
        }
        else
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
        {
	        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE), MEA_MH_DELETE_MM))
	        {
	            ASSERT(0);
	        }

	        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE_ALL), MEA_MH_DELETE_MM_ALL))
	        {
	            ASSERT(0);
            }
        }
    }
        /* MOVE TO ARCHIVE */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if(( folder == MMS_SENT || folder == MMS_INBOX ) && msgType == MMS_SUFFIX_MSG)  //travis
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_MOVE_TO_ARCHIVE), MEA_MH_MOVE_TO_ARCHIVE))
        {
            ASSERT(0);
        }
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

#ifdef __MMI_MMS_BGSR_SUPPORT__
    if( folder == MEA_FOLDER_OUTBOX || folder == MEA_FOLDER_INBOX)
    {    
        if(msg_info != NULL)
        {
            if(msg_info->status == MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND ||
               msg_info->status == MMI_MMS_BGSR_STATUS_SEND_FAIL||
               msg_info->status == MMI_MMS_BGSR_STATUS_DEFERRED_FOR_SEND)
            {
                if(folder == MEA_FOLDER_OUTBOX)
                {
                    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_MOVE_TO_DRAFT), MEA_MH_MOVE_TO_DRAFT))
                    {
                        ASSERT(0);
                    }
                }
            }
            if(msgType != MMS_SUFFIX_MSG)
            {
                if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SHOW_STATUS), MEA_MH_SHOW_STATUS))
                {
                    ASSERT(0);
                }
            }
        }
    }
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        /* Save as Template
            Not available in Default template and user template folder.
            Not available for Notification.*/
    if ((folder != MEA_FOLDER_TEMPLATE) && 
        (folder != MEA_FOLDER_USER_TEMPLATE) &&
        (!meaGetActiveMm()->forwardLock) &&
        !isJSR &&
        (meaGetActiveMm()->fileType != MMS_SUFFIX_NOTIFICATION) &&
        (meaGetActiveMm()->fileType != MMS_SUFFIX_READREPORT) &&
        (meaGetActiveMm()->fileType != MMS_SUFFIX_DELIVERYREPORT) &&
        (meaGetActiveMm()->fileType != MMS_SUFFIX_IMMEDIATE))
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SAVE_AS_TEMPLATE), 
            MEA_MH_SAVE_AS_TEMPLATE))
	 {
	     return FALSE;
	 }
    }
#endif

    /* Properties */
    if ((meaGetActiveMm()->fileType == MMS_SUFFIX_TEMPLATE) || meaGetActiveMm()->fileType == MMS_SUFFIX_SEND_REQ || 
        meaGetActiveMm()->fileType == MMS_SUFFIX_MSG
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        || folder == MEA_FOLDER_USER_TEMPLATE
#endif
        )
    {
	    if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PROPERTIES), MEA_MH_PROPERTIES))
	    {
            ASSERT(0);
	    }
    }

    /* Use Details */
    if ((0 < activeMsgId) && (MEA_FOLDER_TEMPLATE != folder) &&
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        (MEA_FOLDER_USER_TEMPLATE != folder) &&
#endif
        (!isJSR))
    {
#ifdef __MMI_MMS_BGSR_SUPPORT__
        if( folder != MEA_FOLDER_OUTBOX && (msgType != MMS_SUFFIX_NOTIFICATION) )
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
	        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_USE_DETAILS), MEA_MH_USE_NUMBER))
	        {
	            ASSERT(0);
	        }
    }
    
    MEA_FREE(subject);
    MEA_FREE(address);
    return TRUE;
}
#endif /*MMS_SUPPORT */
/*!
 * \brief Creates a navigation menu for the MH window.
 *
 * \param folder The folder that i currently active.
 * \param activeMsgId Message ID of the active message
 * \param msgType The type of the active message. See #MmsFileType.
 * \param forwardLock TRUE if the current message has forward lock, otherwise
 *                    FALSE.
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateMhNavMenu(MeaFolder folder, MmsMsgId activeMsgId, MmsFileType msgType, MSF_BOOL forwardLock
#ifdef __MMI_MMS_BGSR_SUPPORT__
                            , mmi_mms_bgsr_msg_info_struct *msg_info
#endif 
                            )
{
#ifdef __MMI_MMS_BGSR_SUPPORT__
    mea_cur_msg_info = msg_info;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#ifdef MMS_SUPPORT
    /* Create navigation menu */
    if (!meaCreateNavMenu(0, navMenuSignalConverter))
    {
        meaShowNavMenu();
        HDIa_widgetExtPaintDirectly();
        return TRUE;
/*        meaRemoveNavMenu();
        return FALSE;*/
    }else if (!createMenuItems(folder, activeMsgId, msgType, forwardLock, mmcIsJSRMsg(activeMsgId)
#ifdef __MMI_MMS_BGSR_SUPPORT__
    , msg_info
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
    ))
    {
        meaRemoveNavMenu();
        return FALSE;
    }else if (!meaShowNavMenu())
    {
        meaRemoveNavMenu();
        return FALSE;
    }
    HDIa_widgetExtPaintDirectly();
    return TRUE;
#endif /*MMS_SUPPORT*/
    return FALSE;
}

/*!
 * \brief Deletes the navigation menu for the MH window.
 *
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
void meaDeleteMhNavMenu()
{
    meaRemoveNavMenu();
}

/*!
 *  \brief Handles ok action for the startup menu.
 *  \param winHandle Current window handle
 *****************************************************************************/

#ifdef WAP_SUPPORT
static void handleStartupAction(ctk_screen_handle scrHandle)
#else
static void handleStartupAction(MsfWindowHandle winHandle)
#endif /* WAP_SUPPORT */
{
#ifndef WAP_SUPPORT
    int i;
    MeaStartupMenuItem menuItems[] = MEA_STARTUP_MENU_ITEMS;

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MAUIMH_F514184CBC35B21EFF7F83E2EAEA3EE5, "(%s) (%d) Ok action received 0x%x\n", __FILE__, __LINE__, winHandle));
    /* Find the menu item */
    if (-1 == (i = meaGetSelectedChoiceIndex(meaStartupMenu.menuHandle)))
    {
        return;
    }
    switch(menuItems[i].menuId)
#else
    switch (HDIa_widgetExtListMenuGetHilighted(meaStartupMenu.menuHandle))
#endif /* ~WAP_SUPPORT */
    {
    case MEA_MH_NEW_SMIL:
        meaSetStartupFsm(MEA_ME_FSM);
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                MEA_ME_STARTUP_NEW_SMIL, 0);
        break;

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__          
    case MEA_MH_ARCHIVE:
#ifdef WAP_SUPPORT
        if (MMS_ARCHIVE & meaEmptyFolder)
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
            return;
        }
#endif /* WAP_SUPPORT */
        meaSetStartupFsm(MEA_MH_FSM);
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
                MEA_FOLDER_ARCHIVE);
        break;               
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

    case MEA_MH_INBOX:
#ifdef WAP_SUPPORT
        if (MMS_INBOX & meaEmptyFolder)
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
            return;
        }
#endif /* WAP_SUPPORT */
        meaSetStartupFsm(MEA_MH_FSM);
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
                MEA_FOLDER_INBOX);
        break;               
#ifndef MEA_MERGE_OUTBOX
    case MEA_MH_DRAFTS:
#ifdef WAP_SUPPORT
        if (MMS_DRAFTS & meaEmptyFolder)
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
            return;
        }
#endif /* WAP_SUPPORT */
        meaSetStartupFsm(MEA_MH_FSM);
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
                MEA_FOLDER_DRAFTS);
        break;
#endif /* MEA_MERGE_OUTBOX */
#ifndef MEA_MERGE_SENT
    case MEA_MH_SENT:
#ifdef WAP_SUPPORT
        if (MMS_SENT & meaEmptyFolder)
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
            return;
        }
#endif /* WAP_SUPPORT */
        meaSetStartupFsm(MEA_MH_FSM);
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
            MEA_FOLDER_SENT);
        break;
#endif /* MEA_MERGE_SENT */
    case MEA_MH_OUTBOX:
#ifdef WAP_SUPPORT
  #if defined(MEA_MERGE_SENT)
        if ( (MMS_OUTBOX | MMS_SENT) & meaEmptyFolder)  
  #elif defined(MEA_MERGE_OUTBOX)
        if ( (MMS_OUTBOX | MMS_DRAFTS) & meaEmptyFolder)  
  #else
        if (MMS_OUTBOX & meaEmptyFolder)
  #endif /* defined(MEA_MERGE_SENT) */
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
            return;
        }
#endif /* WAP_SUPPORT */
        meaSetStartupFsm(MEA_MH_FSM);
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
            MEA_FOLDER_OUTBOX);
        break;
    case MEA_MH_TEMPLATE:
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        meaCreateTemplatesFolderListView();
#else

#ifdef WAP_SUPPORT
        if (MMS_TEMPLATES & meaEmptyFolder)
        {
            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
            return;
        }
        HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
#endif /* WAP_SUPPORT */
        meaSetStartupFsm(MEA_MH_FSM);
        (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, 
            MEA_FOLDER_TEMPLATE);

#endif /* MEA_CFG_USER_TEMPLATE_SUPPORT*/
        break;
    case MEA_MH_SETTINGS:
        meaSetStartupFsm(MEA_CONFIG_FSM);
        (void)MEA_SIGNAL_SENDTO(MEA_CONFIG_FSM, MEA_SIG_CONF_ACTIVATE);
        break;
    case MEA_MH_BACK:
        /* Terminate through a signal to prevent memory leak */
        (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMH_AEB787B703258596C1C4CC204322365E, "(%s) (%d) startupMenuSignalConverter invalid entry\n", 
            __FILE__, __LINE__));
        break;
    }
#ifdef WAP_SUPPORT
    widget_send_update_event_to_wap();
#endif /* WAP_SUPPORT */
}

static void meaCreatePredefinedStrings(MeaStringType strType)
{
	char * str = NULL;
	int size;
	switch (strType)
	{
		case MEA_STRING_MSG:
			str = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_MSG);
			size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8 *)str)+1;
			strMsg = MEA_ALLOC(size);
			widget_ucs2_to_utf8_string((kal_uint8*)strMsg, size, (kal_uint8 *)str);
			str = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_MSGS);
			size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8 *)str)+1;
			strMsgs = MEA_ALLOC(size);
			widget_ucs2_to_utf8_string((kal_uint8*)strMsgs, size, (kal_uint8 *)str);
			break;
		case MEA_STRING_NO_SUBJECT:
			/*
			str = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_NO_SUBJECT);
			   size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8 *)str)+1;
			strNoSubject = MEA_ALLOC(size);
			widget_ucs2_to_utf8_string((kal_uint8*)strNoSubject, size, (kal_uint8 *)str);
			*/
			strNoSubject = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_NO_SUBJECT);
#ifdef __MMI_KLG__
			strNoNumber = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_NO_NUMBER);
#endif /* __MMI_KLG__ */
			strDeliveryReport= (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_DELIV_REPORT);
			strReadReport = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_READ_REPORT);
			break;
		default:
			break;
	}
}

/*!
 * \brief Creates a startup menu for the MEA.
 *
 * \return TRUE if the menu was created successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateMhStartupMenu()
{
#ifdef WAP_SUPPORT
	int i;
	MeaStartupMenuItem items[] = MEA_STARTUP_MENU_ITEMS;
	ctk_string_id strItemList[MEA_MH_MENU_COUNT];
	ctk_image_id imgItemList[MEA_MH_MENU_COUNT];
	char *hintList[MEA_MH_MENU_COUNT];
	ctk_screen_handle scrid;
	meaCreatePredefinedStrings(MEA_STRING_MSG);

	if (0 != meaStartupMenu.menuHandle)
	{
		MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
		MAUIMH_F802AB5385A0F5C26826D1DAC0047423, "(%s) (%d) The startup menu instance is busy\n", __FILE__, 
		__LINE__));
		return FALSE;
	}	
	for (i = 0; items[i].menuId != -1; i++)
	{
		strItemList[i] = (MSF_UINT16)items[i].strId;
		imgItemList[i] = items[i].imgId;
	}
	meaCreateHintList(hintList);
	meaStartupMenu.menuHandle = HDIa_widgetExtCreateListMenu(MSF_MODID_MEA, MEA_STR_ID_MMS, 0, MEA_MH_MENU_COUNT, 
		strItemList, imgItemList, (kal_uint8 **) hintList, KAL_TRUE);
	freeHintList(hintList);
	scrid = HDIa_widgetCtkGetScreenHandle(meaStartupMenu.menuHandle);
	ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OK, 0, NULL, handleStartupAction, KAL_TRUE);
	ctk_screen_addRSK_UA(scrid, MEA_STR_ID_BACK, 0, NULL, handleStartupBackAction, KAL_TRUE);
	ctk_screen_add_key_UA(scrid, KEY_RIGHT_ARROW, NULL, handleStartupAction, KAL_TRUE);
	ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, handleStartupBackAction, KAL_TRUE);
	return meaDisplayWindow(meaStartupMenu.menuHandle, meaGetPosLeftTop());
#else
    int i;
    MsfActionHandle actionHandle;    
    MeaStartupMenuItem items[] = MEA_STARTUP_MENU_ITEMS;
    
    if (0 != meaStartupMenu.menuHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIMH_F802AB5385A0F5C26826D1DAC0047423, "(%s) (%d) The startup menu instance is busy\n", __FILE__, 
            __LINE__));
        return FALSE;
    }

    /*  Create the menu */

    /*  Create a dummy action for the select event. According to the manual
     *  MSF_WIDGET_MENU_APP_CREATE should have an implicit action in the call.
     */
    actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA,
        MEA_GET_STR_ID(MEA_STR_ID_SELECT), MsfSelect, 0, 
        MSF_ACTION_PROPERTY_ENABLED);
    if (0 == (meaStartupMenu.menuHandle = MSF_WIDGET_MENU_APP_CREATE(
        MSF_MODID_MEA, actionHandle, NULL, MSF_CHOICE_ELEMENT_STRING_1, 0, 
        0)))
    {
        return FALSE;
    }
    /* Create and bind actions */
    /*  We couldn't register the action until we had a window handle.
    *  Now we have it so rock'n'roll. 
    */
    if (!meaRegisterAction(meaStartupMenu.menuHandle, actionHandle, 
        handleStartupAction, 0, 0))
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return FALSE;
    }
    if (!meaCreateAction(meaStartupMenu.menuHandle, MsfBack, handleStartupBack, 
        0, 0, MEA_STR_ID_EXIT))
    {
        return FALSE;
    }
    /* Add items */
    for (i = 0; items[i].menuId != -1; i++)
    {
        if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaStartupMenu.menuHandle, i, 
            MEA_GET_STR_ID(items[i].strId), 0, 0, 0, TRUE))
        {
            return FALSE;
        }
    }
    /* Set the menu title */
    (void)meaSetTitle(meaStartupMenu.menuHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_MESSENGER_APP), 
        MSF_WINDOW_PROPERTY_SINGLEACTION);
    /* Display the window */
    return meaDisplayWindow(meaStartupMenu.menuHandle, meaGetPosLeftTop());
#endif /* WAP_SUPPORT */
}

/*!
 * \brief Remove the start-up menu for the MEA.
 *
 *****************************************************************************/
void meaDeleteMhStartupMenu(void)
{
    (void)meaDeleteWindow(meaStartupMenu.menuHandle);
#ifdef WAP_SUPPORT
    MEA_FREE(strMsg);
    strMsg = NULL;
    MEA_FREE(strMsgs);
    strMsgs = NULL;
#endif /* WAP_SUPPORT */
}

/*!
 * \brief Signal handler for the MH menu.
 * \param actionType The chosen action. See #MeaNavAction.
 *****************************************************************************/
#ifdef MMS_SUPPORT
static void navMenuSignalConverter(MeaNavAction actionType)
{
    if (actionType == MEA_NAV_ACTION_OK)
    {
        /* Set the active message id just in case */
#ifdef MMS_FILE_PROTECT_SUPPORT
		switch(meaGetNavMenuItem())
		{
			case MEA_MH_VIEW_MM:
            case MEA_MH_DOWNLOAD:
			case MEA_MH_EDIT_MM:
			case MEA_MH_FORWARD:
			case MEA_MH_REPLY:
            case MEA_MH_REPLY_SMS:
			case MEA_MH_REPLY_ALL:	
			case MEA_MH_USE_NUMBER:
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case MEA_MH_MOVE_TO_ARCHIVE:
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
            case MEA_MH_SAVE_AS_TEMPLATE:
#endif
			case MEA_MH_PROPERTIES:	
#ifdef __MMI_MMS_BGSR_SUPPORT__         
            case MEA_MH_CANCEL_SEND:
            case MEA_MH_CANCEL_DOWNLOAD:
            case MEA_MH_MOVE_TO_DRAFT:
            case MEA_MH_SHOW_STATUS:
#endif /*__MMI_MMS_BGSR_SUPPORT__*/     
                if(!meaSmilEditorIsActive())
                {
                #ifdef MMS_SUPPORT
                    if (!isValidMmsMSg((unsigned long)meaGetActiveMm()->msgId))
                    {
                        if (meaGetActiveMm()->fileType == MMS_SUFFIX_TEMPLATE)
                        {
                            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_TEMPLATE_CORRUPT),MEA_DIALOG_ERROR);
                        }
                        else
                        {
                            meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_CORRUPT),MEA_DIALOG_ERROR);
                        }
                        return;
                    }
                #endif
                }
        }
#endif /* MMS_FILE_PROTECT_SUPPORT */ 
        switch(meaGetNavMenuItem())
        {
#ifdef __MMI_MMS_BGSR_SUPPORT__ 
            case MEA_MH_CANCEL_DOWNLOAD:
            {
                if (0 != meaGetActiveMm()->msgId)
                {
                        /* Delete message */
                    (void)meaShowConfirmDialog(MEA_STR_ID_CANCEL, NULL, MEA_MH_FSM, MEA_SIG_MH_BGSR_CANCEL_DOWNLOAD, meaGetActiveMm()->msgId);
                }
                break;
            }
            case MEA_MH_CANCEL_SEND:
            {
                if (0 != meaGetActiveMm()->msgId)
                {
                        /* Delete message */
                    (void)meaShowConfirmDialog(MEA_STR_ID_CANCEL, NULL, MEA_MH_FSM, MEA_SIG_MH_BGSR_CANCEL_SEND, meaGetActiveMm()->msgId);
                }
                break;
            }
            case MEA_MH_MOVE_TO_DRAFT:
            {
                if (0 != meaGetActiveMm()->msgId)
                {
                        /* Delete message */
                    (void)meaShowConfirmDialog(MEA_STR_ID_MOVE_TO_DRAFT, NULL, MEA_MH_FSM, MEA_SIG_MH_BGSR_MOVE_TO_DRAFT, meaGetActiveMm()->msgId);
                }
                break;
            }
            case MEA_MH_SHOW_STATUS:
                if (0 != meaGetActiveMm()->msgId)
                {
                    U32 str_id;
                    switch(mea_cur_msg_info->status)
                    {
                        case    MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND:
                        case    MMI_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD:
                            str_id = MEA_STR_ID_WAITING;
                            break;
                        case    MMI_MMS_BGSR_STATUS_SENDING:
                            str_id = MEA_STR_ID_SENDING_MSG;
                            break;
                        case    MMI_MMS_BGSR_STATUS_SEND_FAIL:
                            str_id = MEA_STR_ID_FAILED_TO_SEND;
                            break;
                        case    MMI_MMS_BGSR_STATUS_DOWNLOAD_FAIL:
                            str_id = MEA_STR_ID_DOWNLOAD_FAILED;
                            break;
                        case    MMI_MMS_BGSR_STATUS_DEFERRED_FOR_SEND:
                        case    MMI_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD:
                            str_id = MEA_STR_ID_DEFERRED;
                            break;
                        case    MMI_MMS_BGSR_STATUS_DOWNLOADING:                        
                            str_id = MEA_STR_ID_DOWNLOADING_MM;
                            break;
                        default:
                            ASSERT(0);
                    }
    	            (void)MEA_SIGNAL_SENDTO_IUU(MEA_MV_FSM, MEA_SIG_MV_STATUS_VIEW, str_id, mea_cur_msg_info->ntt, mea_cur_msg_info->quota);
                }
                break;
            
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
        
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
        case MEA_MH_MOVE_TO_ARCHIVE:
        {
            if (0 != meaGetActiveMm()->msgId)
            {
                    /* Delete message */
                (void)meaShowConfirmDialog(MEA_STR_ID_MOVE_TO_ARCHIVE_QUERY, NULL, MEA_MH_FSM, MEA_SIG_MH_MOVE_TO_ARCHIVE, meaGetActiveMm()->msgId);                }
            }
            break;
#endif     /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/        
        case MEA_MH_VIEW_MM:
#ifdef __UNIFIED_MSG_SUPPORT__
            if (meaGetActiveMm()->fileType == MMS_SUFFIX_IMMEDIATE || 
                meaGetActiveMm()->fileType == MMS_SUFFIX_NOTIFICATION)
            {
                (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_NOTIF, meaGetActiveMm()->msgId);
            }
            else
#endif
            {
                (void)MEA_SIGNAL_SENDTO_IU(MEA_MV_FSM, MEA_SIG_MV_ACTIVATE, 
                    meaGetActiveMm()->fileType, (unsigned long)meaGetActiveMm()->msgId); 
            }
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
            break;                

        case MEA_MH_DOWNLOAD:
            (void)MEA_SIGNAL_SENDTO_IU(MEA_MV_FSM, MEA_SIG_MV_ACTIVATE, 
                meaGetActiveMm()->fileType, 
                (unsigned long)meaGetActiveMm()->msgId); 
            break;                

        case MEA_MH_EDIT_MM:
            if(meaGetActiveMm()->forwardLock)
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD_LOCK), MsfError, 0);
            }
            else if(fldrGetMsgSize(meaGetActiveMm()->msgId) > (MEA_CFG_MESSAGE_SIZE_MAXIMUM + 1024)) /* 1KB margin */
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), MsfError, 0);
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                    meaGetActiveMm()->fileType, MEA_ME_STARTUP_EDIT, 
                    (unsigned int)meaGetActiveMm()->msgId);
#ifndef __UNIFIED_COMPOSER_SUPPORT__
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
#endif
            }
            break;

        case MEA_MH_REPLY:
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            wap_send_mmi_mms_start_uc_req(MMA_MODE_REPLY, (unsigned long)meaGetActiveMm()->msgId);
#else
            (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                meaGetActiveMm()->fileType, MEA_ME_STARTUP_REPLY, 
                (unsigned long)meaGetActiveMm()->msgId);
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
#endif            
            break;

        case MEA_MH_REPLY_SMS:
        {
            char *subject = NULL, *address = NULL;
            getMmsMsgSubAddr(MSF_MODID_WIDGET, (unsigned long)meaGetActiveMm()->msgId, &subject, &address, 250);
            if (msf_cmmn_utf8_strlen(address) > 20)  /* 20: MAX_DIGITS_SMS */
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_NUMBER_TOO_LONG), MsfError, 0);
                MSF_MEM_FREE(MSF_MODID_WIDGET, subject);
                MSF_MEM_FREE(MSF_MODID_WIDGET, address);
                break;
            }
            MSF_MEM_FREE(MSF_MODID_WIDGET, subject);
            widget_execute_MMI_p(mms_enter_sms_editor_handler, (void *)address, FALSE);
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
            break;
        }
        
        case MEA_MH_REPLY_ALL:
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            wap_send_mmi_mms_start_uc_req(MMA_MODE_REPLY_ALL, (unsigned long)meaGetActiveMm()->msgId);
#else
            (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                meaGetActiveMm()->fileType, MEA_ME_STARTUP_REPLY_ALL, 
                (unsigned long)meaGetActiveMm()->msgId);
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
#endif            
            break;
            
        case MEA_MH_FORWARD:
            if(fldrGetMsgSize(meaGetActiveMm()->msgId) > (MEA_CFG_MESSAGE_SIZE_MAXIMUM + 1024)) /* 1KB margin */
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_FORWARD), MsfError, 0);
                break;
            }
            else if (!meaGetActiveMm()->forwardLock)
            {
#ifdef __MMS_FORWARD_WITH_EDIT__            
                (void)meaShowConfirmDialog(MEA_STR_ID_FORWARD_WITH_EDIT_CONTENT, NULL, MEA_MH_FSM, MEA_SIG_MH_FORWARD_WITH_EDIT, meaGetActiveMm()->msgId);
#else /*__MMS_FORWARD_WITH_EDIT__*/               
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                    meaGetActiveMm()->fileType, MEA_ME_STARTUP_FORWARD, 
                    (unsigned long)meaGetActiveMm()->msgId);
#ifndef __UNIFIED_COMPOSER_SUPPORT__
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
#endif
#endif /*__MMS_FORWARD_WITH_EDIT__*/
            }
            break;
            
        case MEA_MH_NEW_SMIL:
            (void)MEA_SIGNAL_SENDTO_U(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                MEA_ME_STARTUP_NEW_SMIL);
            break;
        case MEA_MH_DELETE_MM:
            /* Delete the message and disable the navigation view */
            {
                if (0 != meaGetActiveMm()->msgId)
                {
                    /* Delete message */
#ifdef __MMI_MMS_BGSR_SUPPORT__             
                    (void)meaShowConfirmDialog(MEA_STR_ID_DELETE_MSG_QUEST, NULL, 
                        MEA_MH_FSM, MEA_SIG_MH_BGSR_DELETE_MSG, meaGetActiveMm()->msgId);
#else /*__MMI_MMS_BGSR_SUPPORT__*/
                    (void)meaShowConfirmDialog(MEA_STR_ID_DELETE_MSG_QUEST, NULL, 
                        MEA_MH_FSM, MEA_SIG_MH_DELETE_MSG, meaGetActiveMm()->msgId);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
                }
            }
            break;
        case MEA_MH_DELETE_MM_ALL:
            /* Delete all messages and disable the navigation view */
            if (0 != meaGetActiveMm()->msgId)
                /* Ask for deleting all messages */
                meaDeleteAllMsg(meaGetCurrentFolder());
            break;
        case MEA_MH_PROPERTIES:
            if (0 != meaGetActiveMm()->msgId)
            {
	            (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_PROP_VIEW, meaGetActiveMm()->msgId); 
            }
            break;
        case MEA_MH_USE_NUMBER:
            /* Start the SLS module, continue when the SLS is started */
            meaModuleStart(MSF_MODID_SLS, TRUE, MEA_MH_FSM, MEA_SIG_MH_SLS_RSP);        
/*            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);*/
		    break;
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        case MEA_MH_SAVE_AS_TEMPLATE:
            if(fldrGetMsgSize(meaGetActiveMm()->msgId) > MEA_CFG_MESSAGE_SIZE_MAXIMUM)
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_SAVE_AS_TEMPLATE), MsfError, 0);
                break;
            }
            else if (!meaGetActiveMm()->forwardLock)
            {
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                    meaGetActiveMm()->fileType, MEA_ME_STARTUP_SAVE_AS_TEMPLATE, 
                    (unsigned long)meaGetActiveMm()->msgId);
#ifndef __UNIFIED_COMPOSER_SUPPORT__
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
#endif
            }
            break;
#endif

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__              
        case MEA_MH_ARCHIVE:
            (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SET_FOLDER, 
                MEA_FOLDER_ARCHIVE);
            break;                          
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        case MEA_MH_INBOX:
            (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SET_FOLDER, 
                MEA_FOLDER_INBOX);
            break;               
#ifndef MEA_MERGE_OUTBOX
        case MEA_MH_DRAFTS:
            (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SET_FOLDER, 
                MEA_FOLDER_DRAFTS);
            break;
#endif /* MEA_MERGE_OUTBOX */
#ifndef MEA_MERGE_SENT
        case MEA_MH_SENT:
            (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SET_FOLDER, 
                MEA_FOLDER_SENT);
            break;
#endif /* ~MEA_MERGE_SENT */
        case MEA_MH_OUTBOX:
            (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SET_FOLDER, 
                MEA_FOLDER_OUTBOX);
            break;
        case MEA_MH_TEMPLATE:
            (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SET_FOLDER, 
                MEA_FOLDER_TEMPLATE);
            break;
        case(MEA_MH_SETTINGS):
            (void)MEA_SIGNAL_SENDTO(MEA_CONFIG_FSM, MEA_SIG_CONF_ACTIVATE);
            break;
        case MEA_MH_UPDATE:
            (void)MEA_SIGNAL_SENDTO_I(MEA_MH_FSM, MEA_SIG_MH_UPDATE_FOLDER, 
                MEA_FOLDER_NONE);
            break;
        case MEA_MH_SEND:
#ifndef __MMI_MMS_BGSR_SUPPORT__
   			meaSaveOnSendSet(FALSE);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
            if (0 != meaGetActiveMm()->msgId)
            {
                (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SEND_MSG_MR_START, meaGetActiveMm()->msgId);
            }
            break;
        case MEA_MH_USING_TEMPLATE:
            /* Create a new message using the current template */
            if (0 != meaGetActiveMm()->msgId)
            {
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE,
                    meaGetActiveMm()->fileType, MEA_ME_STARTUP_FROM_TEMPLATE, 
                    meaGetActiveMm()->msgId);
            }
            /* Bring down the navigation menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
            break;
        case MEA_MH_BACK:
            if (MEA_STARTUP_MODE_MENU == meaGetStartupMode())   
            {
                /* Delete navigation dialog and terminate the application */
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_DEACTIVATE);
            }
            else
            {
                /* Delete the navigation dialog */
                (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
                /* Check if the application should terminate */
                (void)meaShowConfirmDialog(MEA_STR_ID_CLOSE_MEA, NULL, 
                    MEA_MH_FSM, MEA_SIG_MH_CLOSE_MEA, 0);
            }
            break;
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAUIMH_B9C8920EFDDAB1A33561F501CC6A67DB, "(%s) (%d) invalid menu entry\n", __FILE__, 
                __LINE__));
        }
    }
    if (actionType == MEA_NAV_ACTION_BACK)
    {
        /* Delete navigation dialog */
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);
    }
}

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT

#define MEA_FOLDER_LIST_DEFAULT_TEMP 1
#define MEA_FOLDER_LIST_USER_DEF_TEMP 0
#define MEA_FOLDER_LIST_COUNT   2

typedef struct 
{
    MsfWindowHandle menuHandle; /*!< The menu handle */
}MeaTemplatesFolderListView;

static MeaTemplatesFolderListView meaTemplatesFolderListView;
static void handleTempatesFolderListOkAction(ctk_screen_handle winHandle);
static void handleTempatesFolderListBackAction(ctk_screen_handle winHandle);

MSF_BOOL meaCreateTemplatesFolderListView(void)
{
    MSF_BOOL ret;
    MSF_UINT16 nMsgs, nUnreadMsgs;
    ctk_screen_handle scrid;
    ctk_string_id strItemList[MEA_FOLDER_LIST_COUNT] = {MEA_STR_ID_USER_TEMPLATES, MEA_STR_ID_DEFAULT_TEMPLATES};
    ctk_image_id imgItemList[MEA_FOLDER_LIST_COUNT] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2,};
    char *hintList[MEA_FOLDER_LIST_COUNT];

    /* Get User Defined Templates numbers*/
    meaCreatePredefinedStrings(MEA_STRING_MSG);
	fldrMgrGetNumberOfMessages((MSF_UINT16)MMS_USRDEF_TEMPLATES, &nMsgs, &nUnreadMsgs);
    
    if (nMsgs < 2)
    {
        hintList[MEA_FOLDER_LIST_USER_DEF_TEMP] = MEA_ALLOC(strlen("xxx ")+strlen(strMsg)+1);
		sprintf(hintList[MEA_FOLDER_LIST_USER_DEF_TEMP], "%u %s", nMsgs, strMsg);
    }
	else
    {            
        hintList[MEA_FOLDER_LIST_USER_DEF_TEMP] = MEA_ALLOC(strlen("xxx ")+strlen(strMsgs)+1);
		sprintf(hintList[MEA_FOLDER_LIST_USER_DEF_TEMP], "%u %s", nMsgs, strMsgs);
    }

    hintList[MEA_FOLDER_LIST_DEFAULT_TEMP] = NULL;

    /* Create Menu*/
    meaTemplatesFolderListView.menuHandle = HDIa_widgetExtCreateListMenu(MSF_MODID_MEA,
        MEA_STR_ID_TEMPLATES_FOLDER_LIST, 0, MEA_FOLDER_LIST_COUNT, strItemList, imgItemList, 
        (kal_uint8 **)hintList, KAL_TRUE);

    scrid = HDIa_widgetCtkGetScreenHandle(meaTemplatesFolderListView.menuHandle);
    
    ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OK, 0, NULL, handleTempatesFolderListOkAction, KAL_TRUE);
    ctk_screen_addRSK_UA(scrid, MEA_STR_ID_BACK, 0, NULL, handleTempatesFolderListBackAction, KAL_TRUE);
    ctk_screen_add_key_UA(scrid, KEY_RIGHT_ARROW, NULL, handleTempatesFolderListOkAction, KAL_TRUE);
    ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, handleTempatesFolderListBackAction, KAL_TRUE);

    meaAddWidgetList(meaTemplatesFolderListView.menuHandle);
    ret = (MSF_BOOL)meaDisplayWindow(meaTemplatesFolderListView.menuHandle, meaGetPosLeftTop());

    MEA_FREE(hintList[MEA_FOLDER_LIST_USER_DEF_TEMP]);

    return ret;
}

void meaDeleteTemplatesFolderListView(void)
{
    (void)meaDeleteWindow(meaTemplatesFolderListView.menuHandle);
    memset(&meaTemplatesFolderListView, 0, sizeof(meaTemplatesFolderListView));
}

static void handleTempatesFolderListOkAction(ctk_screen_handle winHandle)
{
    int index;
    MSF_UINT16 templates = 0, dummy = 0;
    
    index = HDIa_widgetExtListMenuGetHilighted(meaTemplatesFolderListView.menuHandle);

    switch(index)
    {
    case MEA_FOLDER_LIST_USER_DEF_TEMP:
        {
            fldrMgrGetNumberOfMessages(MMS_USRDEF_TEMPLATES, &templates, &dummy);
            if(templates > 0)
            {
                HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
                (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, MEA_FOLDER_USER_TEMPLATE);
                widget_send_update_event_to_wap();
            }
            else
            {
                HDIa_widgetExtForcePopup(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), 
                    MsfPromptEmpty, 2000);
            }
        }
        break;
    case MEA_FOLDER_LIST_DEFAULT_TEMP:
        {
            /*fldrMgrGetNumberOfMessages(MMS_TEMPLATES, &templates, &dummy);
            if(templates > 0)
            {
                HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
                (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, MEA_FOLDER_TEMPLATE);
                widget_send_update_event_to_wap();
            }
            else
            {
                meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_EMPTY), MEA_DIALOG_PROMPT_EMPTY);
            }*/
            HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
            (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_ACTIVATE, MEA_FOLDER_TEMPLATE);
            widget_send_update_event_to_wap();
        }
        break;
    default:
        return;
    }
    //meaDeleteTemplatesFolderListView();
}

static void handleTempatesFolderListBackAction(ctk_screen_handle winHandle)
{
    meaDeleteTemplatesFolderListView();
}

void updateTemplatesFolderListHint(void)
{
    MSF_UINT16 nMsgs, nUnreadMsgs;
	char* updatedHint = NULL;
	
    if (meaTemplatesFolderListView.menuHandle == 0)
    {
        return;
    }

    /* Get number*/
    fldrMgrGetNumberOfMessages((MSF_UINT16)MMS_USRDEF_TEMPLATES,&nMsgs,&nUnreadMsgs);

    if (nMsgs < 2)
    {
        updatedHint = MEA_ALLOC(strlen("xxx ")+strlen(strMsg)+1);
		sprintf(updatedHint, "%u %s", nMsgs, strMsg);
    }
	else
    {            
        updatedHint = MEA_ALLOC(strlen("xxx ")+strlen(strMsgs)+1);
		sprintf(updatedHint, "%u %s", nMsgs, strMsgs);
    }

    HDIa_widgetExtListMenuUpdateHint(meaTemplatesFolderListView.menuHandle, 
				(kal_uint8 *)updatedHint , MEA_FOLDER_LIST_USER_DEF_TEMP, KAL_TRUE);

    MEA_FREE(updatedHint);
}

#endif

#endif /*MMS_SUPPORT*/

