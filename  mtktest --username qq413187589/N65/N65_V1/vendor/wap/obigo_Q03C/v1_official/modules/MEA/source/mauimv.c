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

/*!\file mauimv.c
 * \brief The graphical user interface for the message property viewer.
 */

/* MSF */
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_cfg.h"
#include "msf_def.h"
#include "msf_lib.h"
#ifdef WAP_SUPPORT
#include "msf_core.h" //for startupMode
#include "msf_cmmn.h"
#include "widget_extension.h"
#endif

/* MMS */
#include "mms_def.h"
#ifdef WAP_SUPPORT
#include "mms_cfg.h"
#include "mms_if.h"
#include "mmsl_if.h" //for MMSlib_getMessageFullPath
#include "msig.h"    //for fldmgr.h
#include "fldmgr.h"  //for fldrGetFileSuffix
#endif
/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA*/
#include "mea_cfg.h"
#include "mea_def.h"
#include "mea_rc.h"
#include "matypes.h"
#include "maintsig.h"
#include "mamr.h"
#include "mamv.h"
#include "mauimv.h"
#include "mamem.h"
#include "mauicmn.h"
#include "mamh.h"
#include "mauisig.h"
#include "mauimenu.h"
#include "madel.h"
#include "maaddr.h"
#include "mauidia.h"

#ifdef WAP_SUPPORT
#include "mauimh.h"
#include "macore.h" /* startupMode */
#include "wgui_datetime.h"

#include "DateTimeType.h"
#include "app_datetime.h"
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Constants
 *****************************************************************************/

/* From field position and size */
#define MEA_MV_FROM_WIDTH               MEA_GADGET_DEF_WIDTH
#define MEA_MV_FROM_HEIGHT              54

/* TO field position and size */
#define MEA_MV_TO_WIDTH                 MEA_GADGET_DEF_WIDTH
#define MEA_MV_TO_HEIGHT                54

/* CC field position and size */
#define MEA_MV_CC_WIDTH                 MEA_GADGET_DEF_WIDTH
#define MEA_MV_CC_HEIGHT                54

/* Subject position and size */
#define MEA_MV_SUBJECT_WIDTH            MEA_GADGET_DEF_WIDTH
#define MEA_MV_SUBJECT_HEIGHT           54

/* Date position and size */
#define MEA_MV_DATE_HEIGHT              54
#define MEA_MV_DATE_WIDTH               MEA_GADGET_DEF_WIDTH

/* Status position and size */
#define MEA_MV_STATUS_WIDTH             MEA_GADGET_DEF_WIDTH
#define MEA_MV_STATUS_HEIGHT            54

#ifdef WAP_SUPPORT
#define MEA_MAX_DATE_SIZE               50 /* !< Maximum buffer size for date                                                 conversion */
#endif

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*!\struct MeaMvPropView
 *  \brief Message property viewer widget handles 
 */
typedef struct
{
    MsfWindowHandle formHandle;         /*!< The handle of the form */
#ifndef WAP_SUPPORT
    MsfGadgetHandle fromHandle;         /*!< The "From" gadget handle */
    MsfGadgetHandle fromTitleHandle;    /*!< The "From" gadget handle */
    MsfGadgetHandle toHandle;           /*!< The "To" gadget handle */
    MsfGadgetHandle toTitleHandle;      /*!< The "To" gadget handle */
    MsfGadgetHandle ccHandle;           /*!< The "Cc" gadget handle */
    MsfGadgetHandle ccTitleHandle;      /*!< The "Cc" gadget handle */
    MsfGadgetHandle subjectHandle;      /*!< The "Subject" gadget handle */
    MsfGadgetHandle subjectTitleHandle; /*!< The "Subject" gadget handle */
#endif /* ~WAP_SUPPORT */
}MeaMvPropView;

/*! \struct MeaMvRrDrView
 *  \brief Handles for read/delivery reports */
typedef struct
{
    MsfWindowHandle formHandle;         /*!< The form handle */

    MsfGadgetHandle fromHandle;         /*!< The from gadget handle */
    MsfGadgetHandle fromTitleHandle;    /*!< The from gadget handle */
    MsfGadgetHandle subjectHandle;      /*!< The subject gadget handle */
    MsfGadgetHandle subjectTitleHandle; /*!< The subject gadget handle */
    MsfGadgetHandle statusHandle;       /*!< The status gadget handle */
    MsfGadgetHandle statusTitleHandle;  /*!< The status gadget handle */
    MsfGadgetHandle dateHandle;         /*!< The date gadget handle */
    MsfGadgetHandle dateTitleHandle;    /*!< The date gadget handle */
}MeaMvRrDrView;

#ifdef __MMI_MMS_BGSR_SUPPORT__
typedef struct
{
    MsfWindowHandle formHandle;     /*!< The form handle */

    MsfGadgetHandle status;         /*!< The status gadget handle */
    MsfGadgetHandle ntt;            /*!< The ntt gadget handle */
    MsfGadgetHandle quota;          /*!< The quota gadget handle */
}MeaMvStatusView;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

/******************************************************************************
 * Static Data-structures
 *****************************************************************************/

/* Window sizes and placement */

#ifndef WAP_SUPPORT
/* Gadget sizes*/
static const MsfSize     meaMvToSize        = {MEA_MV_TO_HEIGHT, 
                                               MEA_MV_TO_WIDTH};
static const MsfSize     meaMvCcSize        = {MEA_MV_CC_HEIGHT, 
                                               MEA_MV_CC_WIDTH};
static const MsfSize     meaMvSubjectSize   = {MEA_MV_SUBJECT_HEIGHT, 
                                               MEA_MV_SUBJECT_WIDTH};
static const MsfSize     meaMvFromSize      = {MEA_MV_FROM_HEIGHT, 
                                               MEA_MV_FROM_WIDTH};
static const MsfSize     meaMvStatusSize    = {MEA_MV_STATUS_HEIGHT, 
                                               MEA_MV_STATUS_WIDTH};
static const MsfSize     meaMvDateSize      = {MEA_MV_DATE_HEIGHT, 
                                               MEA_MV_DATE_WIDTH};
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Data-structures for the user interface
 *****************************************************************************/

static MeaMvPropView    meaMvPropView;
static MeaMvRrDrView    meaMvRrDrView;
#ifdef __MMI_MMS_BGSR_SUPPORT__
static MeaMvStatusView  meaMvStatusView;
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

/******************************************************************************
 * Prototypes
 *****************************************************************************/
extern char *meaCreateMsgPropText(MmsMsgId msgId);
#ifdef WAP_SUPPORT
static void meaMvPropViewGoBack(ctk_screen_handle scrid);
static void meaMvPropViewGoNext(ctk_screen_handle scrid);
static void meaMvPropViewOnlyGoBack(ctk_screen_handle scrid);
#ifdef __MMI_MMS_BGSR_SUPPORT__
static void meaMvStatusViewGoBack(ctk_screen_handle scrid);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#ifdef __UNIFIED_MSG_SUPPORT__
static void handleMvPropOptionAction(ctk_screen_handle scrHandle);
#endif
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
/******************************************************************************
 * Function implementation
 *****************************************************************************/
#ifdef __MMI_MMS_BGSR_SUPPORT__
/*!
 * \brief Creates the GUI for the message status dialog.
 *
 * \param propItem The current message properties.
 * \param 
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateMvStatusView(U32 str_id, U8 ntt, U8 quota)
{
    ctk_screen_handle	scrid;
    ctk_string_id       titleid;
    kal_uint8 			*text, *str;
    int                 text_size;

    if (0 != meaMvStatusView.formHandle)
    {
        return FALSE;
    }
    memset(&meaMvStatusView, 0, sizeof(MeaMvPropView));

    text_size = 300;
    text = MEA_ALLOC(text_size);
    str = MEA_ALLOC(3);
    widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*) "");
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_STATUS);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)" ");
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, str_id);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");



    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_NEXT_TRANS_TIME);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)": ");
    sprintf((S8 *)str,"%d", ntt);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)" ");
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_MINS);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_REMAIN_QUOTA);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)": ");
    sprintf((S8 *)str,"%d", quota);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)str);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

	/* Create widow */
    titleid = MEA_STR_ID_SHOW_STATUS;
    meaMvStatusView.formHandle = HDIa_widgetExtCreateTextViewSeparator(MSF_MODID_MEA, text, titleid , 0); 
	MEA_FREE(text);
    MEA_FREE(str);
	meaAddWidgetList(meaMvStatusView.formHandle);

	/* Set Key */
	scrid = HDIa_widgetCtkGetScreenHandle(meaMvStatusView.formHandle);

    ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, meaMvStatusViewGoBack, KAL_TRUE);
    ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, meaMvStatusViewGoBack, KAL_TRUE);

    return meaDisplayWindow(meaMvStatusView.formHandle, meaGetPosLeftTop());

}
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
/*!
 * \brief Creates the GUI for the message property dialog.
 *
 * \param propItem The current message properties.
 * \param 
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateMvPropView(MmsMsgId msgId, MSF_BOOL appActivated)
{
    ctk_screen_handle	scrid;
    ctk_string_id       titleid;
    kal_uint8 			*text;

    if (0 != meaMvPropView.formHandle)
    {
        return FALSE;
    }
    memset(&meaMvPropView, 0, sizeof(MeaMvPropView));

    text = (kal_uint8 *)meaCreateMsgPropText(msgId);	

	/* Create widow */
    titleid = (appActivated == TRUE) ? MEA_STR_ID_VIEW_TITLE : MEA_STR_ID_PROPERTIES;
    meaMvPropView.formHandle = HDIa_widgetExtCreateTextViewSeparator(MSF_MODID_MEA, text, titleid , 0); 
	MEA_FREE(text);
	meaAddWidgetList(meaMvPropView.formHandle);

	/* Set Key */
	scrid = HDIa_widgetCtkGetScreenHandle(meaMvPropView.formHandle);
    if (appActivated == TRUE)
    {
        ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, meaMvPropViewGoBack, KAL_TRUE);
        ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, meaMvPropViewGoBack, KAL_TRUE);
        ctk_screen_addLSK_UA(scrid, SMA_STR_ID_MENU_PLAY, IMG_GLOBAL_OK, NULL, meaMvPropViewGoNext, KAL_TRUE);
        //ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, meaMvPropViewGoNext, KAL_TRUE);
    }
    else
    {
#if defined(__UNIFIED_MSG_SUPPORT__) && !defined(__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__)  /* For delete option */
        if (mmcIsJSRMsg(msgId))
        {
            ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OPTIONS, IMG_GLOBAL_OK, NULL, handleMvPropOptionAction, KAL_TRUE);
        }
#endif
        ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, meaMvPropViewOnlyGoBack, KAL_TRUE);
        ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, meaMvPropViewOnlyGoBack, KAL_TRUE);
    }
    return meaDisplayWindow(meaMvPropView.formHandle, meaGetPosLeftTop());
}

static void meaMvPropViewGoBack(ctk_screen_handle scrid)
{
    CTK_UNUSED(scrid);
    //meaDeleteMvPropView();
    (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
    widget_send_update_event_to_wap();
    return;
}
 
static void meaMvPropViewGoNext(ctk_screen_handle scrid)
{
    CTK_UNUSED(scrid);
    (void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_PROP_OK);
    widget_send_update_event_to_wap();
    return;
}

MSF_BOOL meaNoPropView(void)
{
	return (meaMvPropView.formHandle == 0);
}


static void meaMvDrViewOk(ctk_screen_handle scrid)
{
	CTK_UNUSED(scrid);
	if (hasMvInstance())
	{
		(void)MEA_SIGNAL_SENDTO(MEA_MV_FSM, MEA_SIG_MV_DEACTIVATE);
		widget_send_update_event_to_wap();
	}
	else
	{
		meaDeleteMvRrDrView();
		if (MEA_STARTUP_MODE_VIEW == meaGetStartupMode() || MEA_STARTUP_MODE_DOWNLOAD == meaGetStartupMode())
			(void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
	}
}
#ifdef __MMI_MMS_BGSR_SUPPORT__
static void meaMvStatusViewGoBack(ctk_screen_handle scrid)
{
	CTK_UNUSED(scrid);
	meaDeleteMvStatusView();
}
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

static void meaMvPropViewOnlyGoBack(ctk_screen_handle scrid)
{
	CTK_UNUSED(scrid);
	meaDeleteMvPropView();
}


#ifdef __UNIFIED_MSG_SUPPORT__
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
static int createMenuItems(MeaFolder folder, MmsMsgId activeMsgId, 
    MmsFileType msgType, MSF_BOOL forwardLock, MSF_BOOL isJSR)
{
    /* Download */
    if ((0 < activeMsgId) && ((msgType == MMS_SUFFIX_NOTIFICATION) || (msgType == MMS_SUFFIX_IMMEDIATE))
        && (!isJSR))
    {
        if (!meaAddPropNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DOWNLOAD), MEA_MV_DOWNLOAD))//MEA_SIG_MV_ACTIVATE
            return FALSE;	
    }

    /* Delete only if a message is selected */
    if ((0 < activeMsgId) && (MEA_FOLDER_TEMPLATE != folder))
    {
        if (!meaAddPropNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE), MEA_MV_PROP_DELETE))
        {
            return FALSE;
        }

        if (!meaAddPropNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE_ALL), MEA_MV_PROP_DELETE_ALL))
        {
            return FALSE;
        }
    }
    /* MOVE TO ARCHIVE */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if(( folder == MMS_SENT || folder == MMS_INBOX ) && msgType == MMS_SUFFIX_MSG)
    {
        if (!meaAddPropNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_MOVE_TO_ARCHIVE), MEA_MV_PROP_MOVE_TO_ARCHIVE))
        {
            return FALSE;
        }
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    /* Use Details */
    if ((0 < activeMsgId) && (MEA_FOLDER_TEMPLATE != folder) && (!isJSR))
    {
        if (!meaAddPropNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_USE_DETAILS), MEA_MV_PROP_USE_DETAILS))
        {
            return FALSE;
        }
    }
    
    return TRUE;
}

/*!
 * \brief Signal converter for the navigation menu.
 *
 * \param actionType The type of action. See #MeaNavAction
 *****************************************************************************/
static void navMenuSignalConverter(MeaNavAction actionType)
{
    if (actionType == MEA_NAV_ACTION_OK)
    {
        switch(meaGetPropNavMenuItem())            
        {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MEA_MV_PROP_MOVE_TO_ARCHIVE:
            /* move to archive */
            if (0 != meaGetActiveMm()->msgId)
            {
                (void)meaShowConfirmDialog(MEA_STR_ID_MOVE_TO_ARCHIVE_QUERY, NULL, 
                    MEA_MH_FSM, MEA_SIG_MH_MOVE_TO_ARCHIVE, meaGetActiveMm()->msgId);
            }
            break;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        case MEA_MV_DOWNLOAD:
            if (0 != meaGetActiveMm()->msgId)
            {
                (void)MEA_SIGNAL_SENDTO_IU(MEA_MV_FSM, MEA_SIG_MV_ACTIVATE, 
                    meaGetActiveMm()->fileType, (unsigned long)meaGetActiveMm()->msgId); 
            }
            break;
        case MEA_MV_PROP_DELETE:
            /* Delete active message */
            if (0 != meaGetActiveMm()->msgId)
            {
                (void)meaShowConfirmDialog(MEA_STR_ID_DELETE_MSG_QUEST, NULL, 
                    MEA_MH_FSM, MEA_SIG_MH_DELETE_MSG, meaGetActiveMm()->msgId);
            }
            break;
        case MEA_MV_PROP_DELETE_ALL:
            /* Delete all messages and disable the navigation view */
            if (0 != meaGetActiveMm()->msgId)
            {
                meaDeleteAllMsg(meaGetCurrentFolder());
            }
            break;
        case MEA_MV_PROP_USE_DETAILS:
            /* Start the SLS module, continue when the SLS is started */
            meaModuleStart(MSF_MODID_SLS, TRUE, MEA_MH_FSM, MEA_SIG_MH_SLS_RSP);        
            break;
        }
    }

    if (actionType == MEA_NAV_ACTION_BACK)
    {
        meaRemovePropNavMenu();
    }
}

/*!
 * \brief Creates a navigation menu for the DR/RR property window.
 *
 * \param folder The folder that i currently active.
 * \param activeMsgId Message ID of the active message
 * \param msgType The type of the active message. See #MmsFileType.
 * \param forwardLock TRUE if the current message has forward lock, otherwise
 *                    FALSE.
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateMvPropNavMenu(MeaFolder folder, MmsMsgId activeMsgId, MmsFileType msgType, MSF_BOOL forwardLock)
{
    extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);

    /* Create navigation menu */
    if (!meaCreatePropNavMenu(0, navMenuSignalConverter))
    {
        meaRemovePropNavMenu();
        return FALSE;
    }
    else if (!createMenuItems(folder, activeMsgId, msgType, forwardLock, mmcIsJSRMsg(activeMsgId)))
    {
        meaRemovePropNavMenu();
        return FALSE;
    }
    else if (!meaShowPropNavMenu())
    {
        meaRemovePropNavMenu();
        return FALSE;
    }
    return TRUE;
}

static void handleMvPropOptionAction(ctk_screen_handle scrHandle)
{
    CTK_UNUSED(scrHandle);

    if (!meaCreateMvPropNavMenu(meaGetCurrentFolder(), meaGetActiveMm()->msgId, 
        meaGetActiveMm()->fileType, meaGetActiveMm()->forwardLock))
    {
        meaRemovePropNavMenu();
    }
}

/*!
 * \brief Creates the GUI for the notification property dialog.  Show in App (LSK Option, RSK Back)
 *
 * \param 
 * \return void
 *****************************************************************************/
void meaCreateMvNotifPropView(MmsMsgId msgId)
{
    ctk_screen_handle	scrid;
    kal_uint8 			*text;
    extern char *meaCreateNotifPropText(MmsMsgId msgId);

    if (0 != meaMvPropView.formHandle)
    {
        return;
    }
    memset(&meaMvPropView, 0, sizeof(MeaMvPropView));
	
    /* Create widow */
    text = (kal_uint8 *)meaCreateNotifPropText(msgId);
    meaMvPropView.formHandle = HDIa_widgetExtCreateTextViewSeparator(MSF_MODID_MEA, text, MEA_STR_ID_PROPERTIES, 0); 
    MEA_FREE(text);
    meaAddWidgetList(meaMvPropView.formHandle);
    
    /* Set Key */
    scrid = HDIa_widgetCtkGetScreenHandle(meaMvPropView.formHandle);
    ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, meaMvPropViewOnlyGoBack, KAL_TRUE);
    ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, meaMvPropViewOnlyGoBack, KAL_TRUE);
    ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OPTIONS, IMG_GLOBAL_OK, NULL, handleMvPropOptionAction, KAL_TRUE);
	
    meaDisplayWindow(meaMvPropView.formHandle, meaGetPosLeftTop());
    return;
}
#endif /* __UNIFIED_MSG_SUPPORT__ */
#endif /* WAP_SUPPORT */

/*! \brief Set the message properties view.
 *
 * \param propItem The current message properties.
 *****************************************************************************/
MSF_BOOL meaSetMvProperties(const MeaPropItem *propItem)
{
#ifdef WAP_SUPPORT
	return TRUE;
#else
    char *str;
    if ((NULL != propItem) && (0 != meaMvPropView.formHandle))
    {
        str = meaAddrItemToStr(propItem->to);
        if (!meaSetStringGadgetValue(meaMvPropView.fromHandle, 0, str))
        {
            MEA_FREE(str);
            return FALSE;
        }
        MEA_FREE(str);
        str = meaAddrItemToStr(propItem->cc);
        if (!meaSetStringGadgetValue(meaMvPropView.ccHandle, 0, str))
        {
            MEA_FREE(str);
            return FALSE;
        }
        MEA_FREE(str);
        if (!meaSetStringGadgetValue(meaMvPropView.subjectHandle, 
            0, propItem->subject))
        {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
#endif /* WAP_SUPPORT */
}


/*!
 * \brief Initiates the data-structures for the message viewer.
 *****************************************************************************/
void meaMvUiInit(void)
{
    /* Init widget data-structures */
    memset(&meaMvPropView, 0, sizeof(MeaMvPropView));
    memset(&meaMvRrDrView, 0, sizeof(MeaMvRrDrView));
#ifdef __MMI_MMS_BGSR_SUPPORT__
    memset(&meaMvStatusView, 0, sizeof(MeaMvStatusView));
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
}
#ifdef __MMI_MMS_BGSR_SUPPORT__
/*!
 * \brief Deletes the property view.
 *
 *****************************************************************************/
void meaDeleteMvStatusView(void)
{
    /* Delete form and actions */
    (void)meaDeleteWindow(meaMvStatusView.formHandle);
#ifndef WAP_SUPPORT
    /* Delete gadgets */
    if (0 != meaMvStatusView.status)
    {
        (void)MSF_WIDGET_RELEASE(meaMvStatusView.status);
    }
    if (0 != meaMvStatusView.ntt)
    {
        (void)MSF_WIDGET_RELEASE(meaMvStatusView.ntt);
    }
    if (0 != meaMvStatusView.quota)
    {
        (void)MSF_WIDGET_RELEASE(meaMvStatusView.quota);
    }
#endif /* WAP_SUPPORT */
    /* Delete obsolete handles */
    memset(&meaMvStatusView, 0, sizeof(MeaMvStatusView));
}
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

/*!
 * \brief Deletes the property view.
 *
 *****************************************************************************/
void meaDeleteMvPropView(void)
{
    /* Delete form and actions */
    (void)meaDeleteWindow(meaMvPropView.formHandle);
#ifndef WAP_SUPPORT
    /* Delete gadgets */
    if (0 != meaMvPropView.fromHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvPropView.fromHandle);
    }
    if (0 != meaMvPropView.toHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvPropView.toHandle);
    }
    if (0 != meaMvPropView.ccHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvPropView.ccHandle);
    }
    if (0 != meaMvPropView.subjectHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvPropView.subjectHandle);
    }
    if (0 != meaMvPropView.fromTitleHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvPropView.fromTitleHandle);
    }  
    if (0 != meaMvPropView.toTitleHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvPropView.toTitleHandle);
    }
    if (0 != meaMvPropView.ccTitleHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvPropView.ccTitleHandle);
    }
    if (0 != meaMvPropView.subjectTitleHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvPropView.subjectTitleHandle);
    }
#endif /* WAP_SUPPORT */
    /* Delete obsolete handles */
    memset(&meaMvPropView, 0, sizeof(MeaMvPropView));
}

/*!
* \brief Creates the GUI for read or delivery reports.
*
* \param titleStrId The form title.
* \param from The from address.
* \param subject The subject.
* \param statusStrId The status of the message.
* \param date The date of the message
* \return TRUE if successful, otherwise FALSE.
*****************************************************************************/
MSF_BOOL meaCreateMvRrDrView(MSF_UINT32 titleStrId, const char *from, const char *subject,
                             MSF_UINT32 statusStrId, MmsTimeSec rDate)
{
    ctk_screen_handle	scrid;
    kal_uint8 			*text;
    int					text_size;
    MYTIME time;
    MSF_UINT16* dateOrTimeString;
    MeaAddrType addrType;
    char *name = NULL;

    if (0 != meaMvRrDrView.formHandle)
    {
        /* Delete the GUI so that all resources are de-allocated */
        meaDeleteMvRrDrView();    
    }
    memset(&meaMvRrDrView, 0, sizeof(meaMvRrDrView));
	
    /* Prepare text */
    text_size = 150; /* The default size. widget_ucs2str_append_* will realloc the buffer on necessary */
    text = MEA_ALLOC(text_size);
    widget_utf8_to_ucs2_string(text, text_size, (kal_uint8*) "");

    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, (MSF_UINT16)titleStrId);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\n\n");

	/* To */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_TO);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");

    if (MEA_ADDR_TYPE_PLMN == (addrType = meaGetAddrType(from)))
    {
        name = meaLookupNameFromPHB((char *)from);
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)name);
    }    
    else
    {
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)from);
    }
    
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    /* Subject */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_SUBJECT);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)":\n");
    if (subject)
    {
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)subject);
    }
    else
    {
        text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_NO_SUBJECT);
    }
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    /* Date */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_DATE);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\n");
    dateOrTimeString = MEA_ALLOC(MEA_MAX_DATE_SIZE);
    rDate += (HDIa_timeGetTimeZone() * 60);
    mmi_dt_utc_sec_2_mytime((kal_int32)rDate, &time, KAL_TRUE);
    date_string(&time, dateOrTimeString, DT_IDLE_SCREEN);
    text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, (kal_uint8 *)dateOrTimeString);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\n");
    time_string(&time, dateOrTimeString, DT_IDLE_SCREEN);
    text = widget_ucs2str_append_ucs2(MSF_MODID_MEA, text, &text_size, (kal_uint8 *)dateOrTimeString);
    MEA_FREE(dateOrTimeString);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\x1B\n");

    /* Status */
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, MEA_STR_ID_STATUS);
    text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &text_size, (kal_uint8*)"\n");
    text = widget_ucs2str_append_id(MSF_MODID_MEA, text, &text_size, (MSF_UINT16)statusStrId);

    /* Create widow */
    meaMvRrDrView.formHandle = HDIa_widgetExtCreateTextViewSeparator(MSF_MODID_MEA, text, 
    									(MSF_UINT16)titleStrId, 0); 

    MEA_FREE(text);
    meaAddWidgetList(meaMvRrDrView.formHandle);

    /* Set Key */
    scrid = HDIa_widgetCtkGetScreenHandle(meaMvRrDrView.formHandle);

#ifdef __UNIFIED_MSG_SUPPORT__
    ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, meaMvDrViewOk, KAL_TRUE);
    ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, meaMvDrViewOk, KAL_TRUE);
    ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OPTIONS, IMG_GLOBAL_OK, NULL, handleMvPropOptionAction, KAL_TRUE);
#else
    ctk_screen_addLSK_UA(scrid, STR_GLOBAL_OK, IMG_GLOBAL_OK, NULL, meaMvDrViewOk, KAL_TRUE);
    //ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, meaMvPropViewOnlyGoBack, KAL_TRUE);
#endif

    return meaDisplayWindow(meaMvRrDrView.formHandle, meaGetPosLeftTop());
}

/*!
 * \brief Deletes the read/delivery report view.
 *
 *****************************************************************************/
void meaDeleteMvRrDrView()
{
    /* Delete form and actions */
    (void)meaDeleteWindow(meaMvRrDrView.formHandle);
    /* Delete gadgets */
    if (0 != meaMvRrDrView.fromHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvRrDrView.fromHandle);
    }
    if (0 != meaMvRrDrView.dateHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvRrDrView.dateHandle);
    }
    if (0 != meaMvRrDrView.subjectHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvRrDrView.subjectHandle);
    }
    if (0 != meaMvRrDrView.statusHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvRrDrView.statusHandle);
    }
    if (0 != meaMvRrDrView.fromTitleHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvRrDrView.fromTitleHandle);
    }
    if (0 != meaMvRrDrView.dateTitleHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvRrDrView.dateTitleHandle);
    }
    if (0 != meaMvRrDrView.subjectTitleHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvRrDrView.subjectTitleHandle);
    }
    if (0 != meaMvRrDrView.statusTitleHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMvRrDrView.statusTitleHandle);
    }
    /* Delete obsolete handles */
    memset(&meaMvRrDrView, 0, sizeof(MeaMvRrDrView));
}

