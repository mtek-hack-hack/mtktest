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

/*!\file mauidia.c
 * \brief Dialog handling.
 */

/* MSF */
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_def.h"
#include "msf_log.h"
#include "msf_core.h"

/* MMS */
#include "mms_def.h"

/* MEA */
#include "mea_rc.h"
#include "maintsig.h"
#include "mauisig.h"
#include "mauidia.h"
#include "mea_def.h"
#include "mauicmn.h"
#include "macore.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h" // for Assert prototypes
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Defines
 *****************************************************************************/
#define MEA_MAX_DIALOGS     3 /* !< Maximum number of dialogs queued */
#define IS_DIALOG_DISPLAYED (meaDialog.dialogHandle != 0)
/*! The default timeout value for the dialogs in milliseconds.
 */
#define MEA_DIALOG_DEFAULT_TIME_OUT     3000

/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \struct MeaConfirmDialog
 *  Data structure for confirmation dialogs */
typedef struct
{
    MsfWindowHandle dialogHandle;       /* !< The dialog handle */
    /* Action handles */             
    MsfActionHandle cancelActionHandle; /* !< Cancel action handle*/
    MsfActionHandle okActionHandle;     /* !< Ok action handle */
    /* Destination signal */
    MeaStateMachine fsm;                /* !< The response FSM */
    int             signal;             /* !< The response signal */
    unsigned int    id;                 /* !< ID */
}MeaConfirmDialog;

/*! \struct MeaDialog
 *  Data-structures for global dialog data */
typedef struct
{
    MeaStateMachine fsm;            /* !< Callback FSM */
    int             signal;         /* !< Callback signal */
    MsfWindowHandle dialogHandle;   /* !< Dialog handle */
}MeaDialog;

/*! \struct MeaDialogItem
 * Dialog structure, used for queuing dialog  */
typedef struct
{
    MsfStringHandle strHandle;  /* !< The string handle for dynamic strings */
    MeaDialogType   dialogType; /* !< The type of dialog that is displayed */
    MeaStateMachine fsm;        /* !< Callback FSM */
    int             signal;     /* !< Callback signal */    
}MeaDialogItem;

/******************************************************************************
 * Global variables
 *****************************************************************************/

static MeaDialog            meaDialog;
static MeaDialogItem        meaDialogQueue[MEA_MAX_DIALOGS];
static MeaConfirmDialog     meaConfirmDialog;
static MsfWindowHandle      meaPanicDialog;
static MSF_BOOL             terminating;

#ifdef WAP_SUPPORT	// justin
static MsfWindowHandle		meaWindowToShowAfterDialog;
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Prototypes
 *****************************************************************************/

static MSF_BOOL addDialogItem(MeaDialogType dialogType, 
    MsfStringHandle strHandle, MeaStateMachine fsm, int signal);
static MSF_BOOL showDialog(void);

/******************************************************************************
 * Function implementations
 *****************************************************************************/

/*!
 * \brief Add a dialog to the dialog queue.
 *
 * \param dialogType The type of dialog to display.
 * \param textStrId The string ID of the string to display in the dialog.
 * \param fsm       The callback FSM
 * \param signal    The callback signal
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL addDialogItem(MeaDialogType dialogType, 
    MsfStringHandle strHandle, MeaStateMachine fsm, int signal)
{
    int i;
    for(i = 0; i < MEA_MAX_DIALOGS; i++)
    {
        /* Find an empty slot */
        if (0 == meaDialogQueue[i].strHandle)
        {
            meaDialogQueue[i].strHandle  = strHandle;
            meaDialogQueue[i].dialogType = dialogType;
            meaDialogQueue[i].fsm        = fsm;
            meaDialogQueue[i].signal     = signal;
            return TRUE;
        }
    }
    return FALSE;
}

/*! \brief Callback for removing the dialog.
 *	
 */
static void meaDeleteDialogCb(MsfWindowHandle dialogHandle)
{
    (void)meaDeleteDialog(dialogHandle);
}


/*!
 * \brief Deletes the dialog with dialogHandle .
 *
 * \param dialogHandle The handle of the window that is to be deleted.
 * \return TRUE if the window has been deleted, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaDeleteDialog(MsfWindowHandle dialogHandle)
{
    /* Check all the global dialogs */
    if (0 == dialogHandle)
    {
        return TRUE;
    }
    else if (meaConfirmDialog.dialogHandle == dialogHandle)
    {
        /* Confirm dialog */
        (void)MSF_WIDGET_REMOVE(meaGetScreenHandle(), 
            meaConfirmDialog.dialogHandle);
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.dialogHandle);
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.okActionHandle);
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.cancelActionHandle);
        memset(&meaConfirmDialog, 0, sizeof(MeaConfirmDialog));
        return TRUE;
    }
    else if (meaDialog.dialogHandle == dialogHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaDialog.dialogHandle);
        
        /* inform about removal of dialog, if requested */
        if (MEA_NOTUSED_FSM != meaDialog.fsm)
        {
            (void)MEA_SIGNAL_SENDTO(meaDialog.fsm, meaDialog.signal);
        }

        memset(&meaDialog, 0, sizeof(MeaDialog));

        /* Show the next dialog in the list */
        if (!showDialog() && terminating)
        {
            /* Terminate */
#ifdef __UNIFIED_MSG_SUPPORT__
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_ABNORMAL_TERMINATE_APP);
#else
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
#endif
        }
        return TRUE;
    }
    return FALSE;
}

/*! \brief Deletes the panic dialog.
 *
 * \param windowHandle The handle of the 
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaDeletePanicDialog(MsfWindowHandle windowHandle)
{
    if (windowHandle == meaPanicDialog)
    {
        (void)MSF_WIDGET_RELEASE(meaPanicDialog);
        return TRUE;
    }
    return FALSE;
}

/*!
 * \brief Handles deletion of the confirmation dialog.
 *
 * \param windowHandle The handle of the window that generated a notification.
 * \param actionHandle The action handle of the generated action.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaHandleConfirmationDialogSignal(MsfWindowHandle windowHandle, 
    MsfActionHandle actionHandle)
{
    if (meaConfirmDialog.dialogHandle == windowHandle)
    {
        /* Send signal depending on action type */
        if (actionHandle == meaConfirmDialog.okActionHandle)
        {
            (void)MEA_SIGNAL_SENDTO_UU( (MeaStateMachine)meaConfirmDialog.fsm, 
                meaConfirmDialog.signal, MEA_CONFIRM_DIALOG_OK, 
                meaConfirmDialog.id);
        }
        else if (actionHandle == meaConfirmDialog.cancelActionHandle)
        {
            (void)MEA_SIGNAL_SENDTO_UU( (MeaStateMachine)meaConfirmDialog.fsm, 
                meaConfirmDialog.signal, MEA_CONFIRM_DIALOG_CANCEL, 
                meaConfirmDialog.id);
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAUIDIA_68108B0AB2E07EB677F5E16478AD88F2, "(%s) (%d) erroneous signal type!\n", __FILE__, __LINE__));
        }
        /* Delete the dialog */
        (void)meaDeleteDialog(windowHandle);
        return TRUE;
    }
    return FALSE;
}

/*!
 * \brief Initiates the data-structures for the dialog handling.
 *****************************************************************************/
void meaInitDia(void)
{
    /* Create a panic dialog, if anything went totally wrong */
    meaPanicDialog = MSF_WIDGET_DIALOG_CREATE(MSF_MODID_MEA,
        MEA_GET_STR_ID(MEA_STR_ID_PANIC), MsfError, 
        MEA_DIALOG_DEFAULT_TIME_OUT, 0, 0);
    terminating = FALSE;
    memset(&meaConfirmDialog, 0, sizeof(MeaConfirmDialog));
    memset(meaDialogQueue, 0, sizeof(meaDialogQueue));
    memset(&meaDialog, 0, sizeof(MeaDialog));
}

/*!
 * \brief Creates and displays a global dialog. If textStr is NULL textStrId is
 *        used instead. 
 *
 * \param strHandle The text that is presented.
 * \param dialogType The type of dialog that is presented, see #MeaDialogType.
 * \return TRUE if the dialog was created, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowDialog(MsfStringHandle strHandle, MeaDialogType dialogType)
{
    return meaShowDialogWithCallback(strHandle, dialogType, MEA_NOTUSED_FSM,
        0);
}

/*!
 * \brief Creates and displays a global dialog. 
 *
 * \param strHandle The text that is presented
 * \param dialogType The type of dialog that is presented, see #MeaDialogType.
 * \param fsm The fsm to call when dialog is closed.
 * \param signal The signal to send to the fsm when the dialog is closed.
 * \return TRUE if the dialog was created, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowDialogWithCallback(MsfStringHandle strHandle, 
    MeaDialogType dialogType, MeaStateMachine fsm, int signal)
{
#ifdef WAP_SUPPORT
	if (fsm == MEA_NOTUSED_FSM && signal==0)
	{
		MsfDialogType msfDialogType = MsfWarning;
		switch (dialogType)
		{
		case(MEA_DIALOG_ALERT):
			msfDialogType = MsfAlert;
			break;
		case(MEA_DIALOG_WARNING):
			msfDialogType = MsfWarning;
			break;
		case(MEA_DIALOG_INFO):
			msfDialogType = MsfInfo;
			break;
		case(MEA_DIALOG_ERROR):
			msfDialogType = MsfError;
			break;
		case(MEA_DIALOG_CONFIRMATION):
			msfDialogType = MsfConfirmation;
			break;
		case(MEA_DIALOG_PROMPT):
			msfDialogType = MsfPrompt;
			break;
		case(MEA_DIALOG_PROMPT_EMPTY):
			msfDialogType = (MsfDialogType)MsfPromptEmpty;
			break;
		case(MEA_DIALOG_PROMPT_DONE):
			msfDialogType = (MsfDialogType)MsfPromptSaveDone;
			break;
		}

		if(HDIa_widgetExtIsWaitingMessageNotificationInIdleScreen() == FALSE)
		{
			HDIa_widgetExtForcePopup(strHandle, msfDialogType, 0);
		}
	        return TRUE;
	}
#endif /* WAP_SUPPORT */
    if (!MSF_WIDGET_HAS_FOCUS(meaGetScreenHandle()))
    {
        /* Do not display the dialog if the screen is not visible */ 
        if (meaCheckWindowFocus())
        {
            /* Do not display the dialog if the module has screen is not 
               visible */
            return TRUE;
        }
        /* However, set the screen in focus if there are no windows 
           so that dialogs can be displayed even though no windows
           are present */
    }
    if (!addDialogItem(dialogType, strHandle, fsm, signal))
    {
        return FALSE;
    }
    /* Check if a dialog is currently displayed */
    if (!IS_DIALOG_DISPLAYED)
    {
        /* Show next dialog in the queue */
        return showDialog();
    }
    return TRUE;
}

/*!
 * \brief Displays a dialog that requires End User actions to disappear.
 *
 * \param textStrId The text to be displayed or 0 if the str param is used 
 *                  instead.
 * \param str The text string to displayed if textStrId is 0
 * \param fsm The FSM to respond the result to.
 * \param signal The response signal.
 * \param id A optional id that is sent back in the response as u_param2.
 * \return  TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowConfirmDialog(MSF_UINT32 textStrId, const char *str, 
    MeaStateMachine fsm, int signal, unsigned int id)
{
    MsfStringHandle strHandle;
    if (0 != meaConfirmDialog.dialogHandle)
    {
#ifdef WAP_SUPPORT
        meaDeleteDialog(meaConfirmDialog.dialogHandle);
#else
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIDIA_B308D4280296A2DC7B04F7DE3E738342, "(%s) (%d) instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
#endif /* WAP_SUPPORT */
    }
    meaConfirmDialog.fsm    = fsm;
    meaConfirmDialog.signal = signal;
    meaConfirmDialog.id     = id;

    /* Create string handle */
    /*lint -e{539} */
   if (0 == textStrId)
   {
       if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, str, 
           MsfUtf8, (int)strlen(str) + 1, 0)))
       {
           return FALSE;
       }
   }
   else
   {
       strHandle = MEA_GET_STR_ID(textStrId);
   }

    /* Create dialog */
    if (0 == (meaConfirmDialog.dialogHandle = MSF_WIDGET_DIALOG_CREATE(
        MSF_MODID_MEA, strHandle, MsfConfirmation, 0, 
        MSF_WINDOW_PROPERTY_NOTIFY, 0)))
    {
        if (0 == textStrId)
        {
            (void)MSF_WIDGET_RELEASE(strHandle);
        }
        return FALSE;
    }
    if (0 == textStrId)
    {
        (void)MSF_WIDGET_RELEASE(strHandle);
    }
    /* Create actions */
#ifdef WAP_SUPPORT	
    if (textStrId==MEA_STR_ID_NEW_MMS_MSG
#ifdef __MMS_DUAL_SIM_SUPPORT__
        || textStrId == WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_1 || textStrId == WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_2
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
        )
        meaConfirmDialog.okActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, 
            MEA_GET_STR_ID(MEA_STR_ID_LSK_READ), MsfOk, 0, MSF_ACTION_PROPERTY_ENABLED);
    else
        meaConfirmDialog.okActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, 
            MEA_GET_STR_ID(MEA_STR_ID_LSK_YES), MsfOk, 0, MSF_ACTION_PROPERTY_ENABLED);
#else
    meaConfirmDialog.okActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, 
        MEA_GET_STR_ID(MEA_STR_ID_OK), MsfOk, 0, MSF_ACTION_PROPERTY_ENABLED);
#endif /* WAP_SUPPORT */
    if (0 > MSF_WIDGET_ADD_ACTION(meaConfirmDialog.dialogHandle, 
        meaConfirmDialog.okActionHandle))
    {
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.dialogHandle);
        memset(&meaConfirmDialog, 0 , sizeof(MeaConfirmDialog));
        return FALSE;
    }
#ifdef WAP_SUPPORT	
    if (textStrId==MEA_STR_ID_NEW_MMS_MSG
#ifdef __MMS_DUAL_SIM_SUPPORT__
        || textStrId == WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_1 || textStrId == WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_2
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
        )
        meaConfirmDialog.cancelActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, 
            MEA_GET_STR_ID(MEA_STR_ID_BACK), MsfCancel, 0, MSF_ACTION_PROPERTY_ENABLED);
    else
        meaConfirmDialog.cancelActionHandle = MSF_WIDGET_ACTION_CREATE(
            MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_RSK_NO), MsfCancel, 0, 
            MSF_ACTION_PROPERTY_ENABLED);
#else
    meaConfirmDialog.cancelActionHandle = MSF_WIDGET_ACTION_CREATE(
        MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_CANCEL), MsfCancel, 0, 
        MSF_ACTION_PROPERTY_ENABLED);
#endif /* WAP_SUPPORT */
    if (0 > MSF_WIDGET_ADD_ACTION(meaConfirmDialog.dialogHandle, 
        meaConfirmDialog.cancelActionHandle))
    {
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.dialogHandle);
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.okActionHandle);
        memset(&meaConfirmDialog, 0 , sizeof(MeaConfirmDialog));
        return FALSE;
    }
    /* Display the dialog */
    if (0 <= MSF_WIDGET_SCREEN_ADD_WINDOW(meaGetScreenHandle(), 
        meaConfirmDialog.dialogHandle, meaGetPosLeftTop(), 
        meaGetScreenHandle(), 0))
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(meaGetScreenHandle(), TRUE);
        (void)MSF_WIDGET_SET_IN_FOCUS(meaConfirmDialog.dialogHandle, TRUE);
    }
    else
    {
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.dialogHandle);
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.okActionHandle);
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.cancelActionHandle);
        memset(&meaConfirmDialog, 0 , sizeof(MeaConfirmDialog));
        return FALSE;
    }
    return TRUE;
}

/*! \brief Display the panic dialog.
 *
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowPanicDialog(void)
{
    if (0 != meaPanicDialog)
    {
        return meaDisplayWindow(meaPanicDialog, meaGetPosLeftTop());
    }
    return FALSE;      
}

/*!
 * \brief De-allocates resources allocated for the dialog handling.
 *****************************************************************************/
void meaTerminateDia(void)
{
    /* Delete panic dialog */
    if (0 != meaPanicDialog)
    {
       (void)MSF_WIDGET_RELEASE(meaPanicDialog);
        meaPanicDialog = 0;
    }
    terminating = FALSE;
    memset(meaDialogQueue, 0, sizeof(meaDialogQueue));
    (void)meaDeleteDialog(meaDialog.dialogHandle);
    (void)meaDeleteDialog(meaConfirmDialog.dialogHandle);
}

#ifdef WAP_SUPPORT // justin
/* \brief set meaWindowToShowAfterDialog MsfWindowHand.*/
void meaShowWindowAfterDialog(MsfWindowHandle windowHandle)
{
	WAP_DBG_ASSERT(meaWindowToShowAfterDialog == 0);
	meaWindowToShowAfterDialog = windowHandle;
}

/* \brief show confirmation dialog with status icons for new MMS confirmation in idle. */
MSF_BOOL meaShowConfirmDialogWithStatusIcons(MSF_UINT32 textStrId, const char *str, 
    MeaStateMachine fsm, int signal, unsigned int id)
{
	MSF_BOOL res = meaShowConfirmDialog(textStrId, str, fsm, signal, id);
	if (res)
	{
		int old_properties = 
			HDIa_widgetWindowGetProperties(meaConfirmDialog.dialogHandle);
		MSF_WIDGET_WINDOW_SET_PROPERTIES(meaConfirmDialog.dialogHandle, 
			old_properties | MSF_WINDOW_PROPERTY_EXT_STATUS_ICON);
        HDIa_widgetExtDialogDisableTone(meaConfirmDialog.dialogHandle);
	}
	return res;
}

/*!
 * \brief Displays a dialog that requires End User actions to disappear.
 *
 * \param textStrId The text to be displayed or 0 if the str param is used 
 *                  instead.
 * \param str The text string to displayed if textStrId is 0
 * \param fsm The FSM to respond the result to.
 * \param signal The response signal.
 * \param id A optional id that is sent back in the response as u_param2.
 * \return  TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaShowDialogWithConfirm(MsfDialogType dlgType, MSF_UINT32 lskStrId, MSF_UINT32 rskStrId, 
    MSF_UINT32 textStrId, MeaStateMachine fsm, int signal, unsigned int id)
{
    if (0 != meaConfirmDialog.dialogHandle)
    {
        meaDeleteDialog(meaConfirmDialog.dialogHandle);
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAUIDIA_B308D4280296A2DC7B04F7DE3E738342, "(%s) (%d) instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
    meaConfirmDialog.fsm    = fsm;
    meaConfirmDialog.signal = signal;
    meaConfirmDialog.id     = id;

    /* Create string handle */
   if (0 == textStrId)
   {
       return FALSE;
   }

    /* Create dialog */
    if (0 == (meaConfirmDialog.dialogHandle = MSF_WIDGET_DIALOG_CREATE(MSF_MODID_MEA, MEA_GET_STR_ID(textStrId), dlgType, 0, MSF_WINDOW_PROPERTY_NOTIFY, 0)))
    {
        return FALSE;
    }

    /* Create LSK action */
    if(0 == lskStrId)
    {
        meaConfirmDialog.okActionHandle = 0;
    }
    else
    {
        meaConfirmDialog.okActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, MEA_GET_STR_ID(lskStrId), MsfOk, 0, MSF_ACTION_PROPERTY_ENABLED);
    }
    
    if (meaConfirmDialog.okActionHandle > 0 && 0 > MSF_WIDGET_ADD_ACTION(meaConfirmDialog.dialogHandle, meaConfirmDialog.okActionHandle))
    {
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.dialogHandle);
        memset(&meaConfirmDialog, 0 , sizeof(MeaConfirmDialog));
        return FALSE;
    }
    
    /* Create RSK action */
    if(0 == rskStrId)
    {
        meaConfirmDialog.cancelActionHandle = 0;
    }
    else
    {
        meaConfirmDialog.cancelActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, MEA_GET_STR_ID(rskStrId), MsfCancel, 0, MSF_ACTION_PROPERTY_ENABLED);
    }
    
    if (meaConfirmDialog.cancelActionHandle> 0 && 0 > MSF_WIDGET_ADD_ACTION(meaConfirmDialog.dialogHandle, meaConfirmDialog.cancelActionHandle))
    {
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.dialogHandle);
        if(meaConfirmDialog.okActionHandle != 0)
        {
            (void)MSF_WIDGET_RELEASE(meaConfirmDialog.okActionHandle);
        }
        memset(&meaConfirmDialog, 0 , sizeof(MeaConfirmDialog));
        return FALSE;
    }
    
    /* Display the dialog */
    if (0 <= MSF_WIDGET_SCREEN_ADD_WINDOW(meaGetScreenHandle(), meaConfirmDialog.dialogHandle, meaGetPosLeftTop(), meaGetScreenHandle(), 0))
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(meaGetScreenHandle(), TRUE);
        (void)MSF_WIDGET_SET_IN_FOCUS(meaConfirmDialog.dialogHandle, TRUE);
    }
    else
    {
        (void)MSF_WIDGET_RELEASE(meaConfirmDialog.dialogHandle);
        if(meaConfirmDialog.okActionHandle != 0)
        {
            (void)MSF_WIDGET_RELEASE(meaConfirmDialog.okActionHandle);
        }

        if(meaConfirmDialog.cancelActionHandle != 0)
        {
            (void)MSF_WIDGET_RELEASE(meaConfirmDialog.cancelActionHandle);
        }
        
        memset(&meaConfirmDialog, 0 , sizeof(MeaConfirmDialog));
        return FALSE;
    }
    return TRUE;
}

#endif /* WAP_SUPPORT */
/*!
 * \brief Creates and displays a dialog.
 * 
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL showDialog()
{
    int i;
    MsfDialogType msfDialogType;
    
    if (0 != meaDialog.dialogHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIDIA_5AA3B4FB841AC6A9C5FC4188FD141007, "(%s) (%d) instance busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
    if (0 == meaDialogQueue[0].strHandle)
    {
#ifdef WAP_SUPPORT	// justin
		if (meaWindowToShowAfterDialog != 0)
		{
			meaDisplayWindow(meaWindowToShowAfterDialog, meaGetPosLeftTop());
			meaWindowToShowAfterDialog = 0;
		}
#endif /* WAP_SUPPORT */
        return FALSE;
    }
    msfDialogType = MsfWarning;
    switch (meaDialogQueue[0].dialogType)
    {
    case(MEA_DIALOG_ALERT):
        msfDialogType = MsfAlert;
        break;
    case(MEA_DIALOG_WARNING):
        msfDialogType = MsfWarning;
        break;
    case(MEA_DIALOG_INFO):
        msfDialogType = MsfInfo;
        break;
    case(MEA_DIALOG_ERROR):
        msfDialogType = MsfError;
        break;
#ifdef WAP_SUPPORT
    case(MEA_DIALOG_CONFIRMATION):
        msfDialogType = MsfConfirmation;
        break;
    case(MEA_DIALOG_PROMPT):
        msfDialogType = MsfPrompt;
        break;
    case(MEA_DIALOG_PROMPT_EMPTY):
        msfDialogType = (MsfDialogType)MsfPromptEmpty;
        break;
    case(MEA_DIALOG_PROMPT_DONE):
        msfDialogType = (MsfDialogType)MsfPromptSaveDone;
        break;
#endif /* WAP_SUPPORT */
    }
    
    /* Create dialog */
    meaDialog.dialogHandle = MSF_WIDGET_DIALOG_CREATE(MSF_MODID_MEA, 
        meaDialogQueue[0].strHandle, msfDialogType, 
        MEA_DIALOG_DEFAULT_TIME_OUT, MSF_WINDOW_PROPERTY_NOTIFY, 0);
    if (0 == meaDialog.dialogHandle)
    {
        return FALSE;
    }

    /* copy callback info for this dialog */
    meaDialog.fsm = meaDialogQueue[0].fsm;
    meaDialog.signal = meaDialogQueue[0].signal;

    /* Display the dialog */
    if (0 <= MSF_WIDGET_SCREEN_ADD_WINDOW(meaGetScreenHandle(), 
        meaDialog.dialogHandle, meaGetPosLeftTop(), meaGetScreenHandle(), 0))
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(meaGetScreenHandle(), TRUE);
        (void)MSF_WIDGET_SET_IN_FOCUS(meaDialog.dialogHandle, TRUE);
        (void)meaRegisterNotification(meaDialog.dialogHandle,
            MsfNotifyLostFocus, meaDeleteDialogCb, 0, 0);
    }
    else
    {
        (void)MSF_WIDGET_RELEASE(meaDialog.dialogHandle);
        meaDialog.dialogHandle = 0;
        return FALSE;
    }
    /* Remove the item from the queue */
    for(i = 0; i < MEA_MAX_DIALOGS - 1; i++)
    {
        memcpy(&meaDialogQueue[i], &meaDialogQueue[i + 1], 
            sizeof(MeaDialogItem));
    }

    /* Set last item to zero */
    meaDialogQueue[MEA_MAX_DIALOGS - 1].dialogType = (MeaDialogType)0;
    meaDialogQueue[MEA_MAX_DIALOGS - 1].strHandle  = 0;
    return TRUE;
}

/*! \brief Returns the number of dialogs queued, visible dialogs also counted
 *
 * \return The number of dialogs 
 *****************************************************************************/
unsigned int meaGetDialogCount(void)
{
    unsigned int count = 0;
    unsigned int i;
    for (i = 0; i < MEA_MAX_DIALOGS; i++)
    {
        if (0 != meaDialogQueue[i].strHandle)
        {
            ++count;
        }
    }
#ifndef WAP_SUPPORT
    if (0 != meaDialog.dialogHandle)
    {
        ++count;
    }
#endif /* ~WAP_SUPPORT */
    return count;
}

/*! \brief Waits for the current dialog to close down, and then try to 
 *         terminate
 * 
 * \return TRUE if there are dialogs to display, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCheckDialogs(void)
{
    terminating = TRUE;
    return (meaGetDialogCount() > 0);
}

/*!
 * \brief Displays an error dialog from a string.
 *
 * \param str The string to show in the dialog.
 * \return TRUE on success, else FALSE.
 *****************************************************************************/
MSF_BOOL showErrorDlg(const char *str)
{
    MsfStringHandle strHandle;

    if (NULL == str)
    {
        return FALSE;
    }
    if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
        str, MsfUtf8, (int)strlen(str) + 1, 0)))
    {
        return FALSE;
    }
    (void)meaShowDialog(strHandle, MEA_DIALOG_ERROR);
    (void)MSF_WIDGET_RELEASE(strHandle);
    return TRUE;
}

