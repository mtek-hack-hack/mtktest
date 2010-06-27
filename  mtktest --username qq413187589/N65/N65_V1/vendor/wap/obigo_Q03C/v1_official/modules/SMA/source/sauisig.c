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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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
 *****************************************************************************/

/*! \file sauisig.c
 *  \brief Signal handler for Widgets.
 */

/* MSF */
#include "msf_int.h"
#include "msf_wid.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_mem.h"
#include "msf_lib.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* SMA */
#include "saintsig.h"
#include "sauisig.h"
#include "sauidia.h"
#include "sma_def.h"
#include "samem.h"
#include "satypes.h"
#include "saui.h"
#include "samain.h"

#include "saslide.h"  /* SMA_SIG_SLIDE_READ_RSP */
#include "saasync.h" /* SMA_ASIO_RESULT_XX */
/******************************************************************************
 * Data-types
 *****************************************************************************/

/*! \struct SmaCallbackSignal
 *  Callback signals for Widget API are saved in the structure */
typedef struct
{
    int                 fsm;    /* !< Callback FSM */
    int                 signal; /* !< Callback signal */
}SmaCallbackSignal;

/*! \struct SmaEventResponse
 *  Callback/signal information for a response call */
typedef struct 
{
    unsigned char type;                 /*!< SMA_WIDGET_NA,
                                             SMA_WIDGET_CALLBACK or 
                                             SMA_WIDGET_SIGNAL */

    /*!\union callback Callback functions */
    union
    {
        SmaActionCallBack   func; /* !< Callback function */
        SmaCallbackSignal   sig;  /* !< Callback signal */
    }callback;
}SmaEventResponse;

/*! \struct SmaEventItem
 *  List item for action and notification handling */
typedef struct
{
    SmaEventType eventType;             /*!< Type of event (action/notif/
                                             user event) */
    /*!\union identifier Identification of the action handle or notif type */
    union 
    {
        MsfNotificationType notifType;      /*!< Type of notification */
        MsfActionHandle     actionHandle;   /*!< Widget action handle */
        MsfEventType        usrEventType;   /*!< User event */
    }identifier;
    SmaEventResponse response;          /*!< Response */
}SmaEventItem;

/*! \struct SmaWidgetItem
 *  List item for window/gadget and action/notification/usr event handling */
typedef struct
{
    MSF_UINT32 handle; /* !< Widget window/gadget handle */
    SmaEventItem eventList[SMA_MAX_ACTIVE_ACTIONS]; /* !< a list of actions or
                                                            notifications or
                                                            user events
                                                            associated with the 
                                                            window */
}SmaWidgetItem;

/******************************************************************************
 * Static data
 *****************************************************************************/

/* Data-structure for signals originating from widget API */
static SmaWidgetItem *widgetList;
static unsigned int  widgetItemCount;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

static SmaWidgetItem *findWidgetByHandle(MSF_UINT32 widgetHandle);
static SmaEventItem *findEventByHandle(MSF_UINT32 widgetHandle,
    SmaEventType eventType, MsfActionHandle actionHandle, 
    MsfNotificationType notifType, MsfEventType usrEvent);
static int routeEvent(const SmaEventResponse *response,
	MSF_UINT32 widgetHandle);
static MSF_BOOL handleDialogNotification(MsfWindowHandle windowHandle);
static MSF_BOOL handleWidgetNotification(MSF_UINT32 widgetHandle, 
                       MsfNotificationType notifType);
static MSF_BOOL handleUsrEvent(MsfWindowHandle handle, MsfEventType usrEvent, 
    MsfEventClass eventClass);
static int findEmptyEventSlot(const SmaEventItem *eventItems);
static void registerEventItem(SmaEventItem *eventItem, 
    SmaActionCallBack callback, int fsm, int signal);
static void addEventToSlot(SmaEventItem *eventItem, SmaEventType eventType,
    MsfActionHandle actionHandle, MsfNotificationType notifType, 
    MsfEventType usrEvent, SmaActionCallBack callback, int fsm,  int signal);
static MSF_BOOL handleWidgetAction(MsfWindowHandle windowHandle,
    MsfActionHandle actionHandle);
/******************************************************************************
 * Function implementation
 *****************************************************************************/


 /*!\brief Find a widget in widget list by its handle
 *
 * \param widgetHandle The widget handle of interest
 * \return Pointer to window list item or NULL if not found
 *****************************************************************************/
static SmaWidgetItem *findWidgetByHandle(MSF_UINT32 widgetHandle)
{
    unsigned int i;

    for (i = 0; i < widgetItemCount; i++)
    {
        if (widgetHandle == widgetList[i].handle)
        {
            return &widgetList[i];
        }
    }
    return NULL;
}

 /*!\brief Find an event that matches the specified widget handle and
           action handle or notification type
 * \param widgetHandle The widget handle of interest (window/gadget)
 * \param eventType    The type of event (action, notif, or user event)
 * \param actionHandle The action handle of interest (only for actions)
 * \param notifType    The notification type of interest (only for notifs)
 * \param usrEvent     The user event type of interest (only for usr events)
 * \return Pointer to the event or NULL if not found
 *****************************************************************************/
static SmaEventItem *findEventByHandle(MSF_UINT32 widgetHandle,
    SmaEventType eventType, MsfActionHandle actionHandle, 
    MsfNotificationType notifType, MsfEventType usrEvent)
{
    unsigned int i;
    SmaWidgetItem *widgetItem = findWidgetByHandle(widgetHandle);
    SmaEventItem *eventItem;

    if (NULL == widgetItem)
    {
        return NULL;
    }

    for (i = 0; i < SMA_MAX_ACTIVE_ACTIONS; i++)
    {
        eventItem = &(widgetItem->eventList[i]);
        if (eventType == eventItem->eventType &&
            ((eventType == SMA_ACTION_EVENT && 
            actionHandle == eventItem->identifier.actionHandle) ||
            (eventType == SMA_NOTIFICATION_EVENT &&
            notifType == eventItem->identifier.notifType) ||
            (eventType == SMA_USR_EVENT &&
            usrEvent == eventItem->identifier.usrEventType)))
        {
            return eventItem;
        }
    }
    return NULL;
}

/*!\brief Route event through signal or callback
 *
 * \param response The information about the signal or callback
 * \param windowHandle The widget handle that was affected by the event
 * \return TRUE if the event was handled, otherwise FALSE.
 *****************************************************************************/
static int routeEvent(const SmaEventResponse *response,
    MSF_UINT32 widgetHandle)
{
    /* Signal or function call ?? */
    if (SMA_WIDGET_CALLBACK == response->type)
    {
        /* Call callback function */
        response->callback.func(widgetHandle);
        return TRUE;
    }
    else if (SMA_WIDGET_SIGNAL == response->type)
    {
        /* Send signal */
        (void)SMA_SIGNAL_SENDTO_U(
            (SmaStateMachine)response->callback.sig.fsm, 
            response->callback.sig.signal, widgetHandle);
        return TRUE;
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUISIG_A361CA62F58D81BF06DBDF0428ECB689, "(%s) (%d) unhandled event\n", __FILE__, 
            __LINE__));
    }
    return FALSE;
}

/*!\brief Signal handler for Widget actions.
 *
 * \param windowHandle The window that generated an action.
 * \param actionHandle The handle of the action that was generated.
 * \return TRUE if the action was handled, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL handleWidgetAction(MsfWindowHandle windowHandle,
    MsfActionHandle actionHandle)
{
    SmaEventItem *eventItem;

    eventItem = findEventByHandle(windowHandle, SMA_ACTION_EVENT, actionHandle,
        (MsfNotificationType)0, (MsfEventType)0);

    if (NULL != eventItem)
    {
        return routeEvent(&eventItem->response, windowHandle);        
    }
    return FALSE;    
}

/*!\brief Signal handler for widget notifications.
 *
 * \param widgetHandle The widget that generated a notification.
 * \param notifType The type of notification that was generated.
 * \return TRUE if the notification was handled, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL handleWidgetNotification(MSF_UINT32 widgetHandle, 
    MsfNotificationType notifType)
{
    SmaEventItem *eventItem;

    if (NULL != (eventItem = findEventByHandle(widgetHandle,
        SMA_NOTIFICATION_EVENT, 0, notifType, (MsfEventType)0)))
    {
        return routeEvent(&eventItem->response, widgetHandle);        
    }
    return FALSE;    
}

/*!\brief Signal handler for widget user events.
 *
 * \param widgetHandle The widget that generated a user event.
 * \param usrEvent The type of user event that was generated.
 * \param eventClass The even class, see #MsfEventClass.
 * \return TRUE if the user event was handled, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL handleUsrEvent(MsfWindowHandle handle, MsfEventType usrEvent, 
    MsfEventClass eventClass)
{
    SmaEventItem *eventItem;

    if ((eventClass == MsfPress) && (NULL != (eventItem = 
        findEventByHandle(handle, SMA_USR_EVENT, 0, (MsfNotificationType)0, 
		usrEvent))))
    {
        return routeEvent(&eventItem->response, handle);
    }
    return FALSE;
}

/*!\brief Initiates data structes for the MH GUI.
 *
 *****************************************************************************/

void smaInitWidgetSignalHandler(void)
{
    /* Allocate signal handling buffer */
    widgetItemCount = SMA_MAX_ACTIVE_WIN;
    widgetList = SMA_ALLOC(widgetItemCount*sizeof(SmaWidgetItem));
    /* Set all data to zero */
    memset(widgetList, 0, sizeof(SmaWidgetItem)*widgetItemCount);
}

/*!\brief Initiates data structes for the MH GUI.
 *
 *****************************************************************************/

void smaTerminateWidgetSignalHandler(void)
{
    /* Allocate signal handling buffer */
    SMA_FREE(widgetList);
    widgetList = NULL;
    widgetItemCount = 0;
}


/*!\brief Delete a window and its actions.
 *
 * \param winHandle The handle of the window (with attached actions) to delete.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaDeleteWindow(MsfWindowHandle winHandle)
{
    unsigned int i;
    unsigned int j;

    if (0 == winHandle)
    {
        return TRUE;
    }
    for (i = 0; i < widgetItemCount; i++)
    {
        if (winHandle == widgetList[i].handle)
        {
            /* Delete window */
            (void)MSF_WIDGET_REMOVE(smaGetScreenHandle(), 
                widgetList[i].handle);
            (void)MSF_WIDGET_RELEASE(widgetList[i].handle);
            /* Delete all actions */
            for (j = 0; j < SMA_MAX_ACTIVE_ACTIONS; j++)
            {
                if (SMA_ACTION_EVENT == widgetList[i].eventList[j].eventType &&
                    0 != widgetList[i].eventList[j].identifier.actionHandle)
                {
                    (void)MSF_WIDGET_RELEASE(
                        widgetList[i].eventList[j].identifier.actionHandle);
                }
            }
            /* Delete obsolete data*/
            memset(&widgetList[i], 0, sizeof(SmaWidgetItem));
            return TRUE;
        }
    }
    return FALSE;
}

/*!\brief Deletes a specific action.
 *
 * \param actionHandle The action to delete.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaDeleteAction(MsfActionHandle actionHandle)
{
    unsigned int i, j;
    for (i = 0; i < widgetItemCount; i++)
    {
        if (0 != widgetList[i].handle)
        {
            for (j = 0; j < SMA_MAX_ACTIVE_ACTIONS; j++)
            {
                if (SMA_ACTION_EVENT == widgetList[i].eventList[j].eventType &&
                    actionHandle == 
                    widgetList[i].eventList[j].identifier.actionHandle)
                {
                    (void)MSF_WIDGET_RELEASE(
                        widgetList[i].eventList[j].identifier.actionHandle);
                    /* Delete obsolete data */
                    memset(&widgetList[i].eventList[j], 0, 
                        sizeof(SmaEventItem));
                    return TRUE;
                }

            }
        }
    }
    return FALSE;
}

/*!\brief Deletes requests for notifications for a specific widget
 *
 * \param widgetHandle   The widget for which notifications should no longer
                         be captured
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaDeleteNotification(MSF_UINT32 widgetHandle)
{
    SmaWidgetItem *widget;
    int i;
    MSF_BOOL hasOther;

    widget = findWidgetByHandle(widgetHandle);

    if (NULL == widget)
    {
        return FALSE;
    }

    /* clean all notification instances for this widget */
    hasOther = FALSE;
    for (i = 0; i < SMA_MAX_ACTIVE_ACTIONS; i++)
    {
        if (SMA_NOTIFICATION_EVENT == widget->eventList[i].eventType)
        {
            memset(&widget->eventList[i], 0, sizeof(SmaEventItem));
        }
        else if (SMA_NO_EVENT != widget->eventList[i].eventType)
        {
            hasOther = TRUE;
        }
    }

    /* if there were only notification instances, clean the widget itself */
    if (!hasOther)
    {
        widget->handle = 0;
    }
    return TRUE;
}

/*!\brief Deletes requests for a registered user event
 *
 * \param winHandle The window for which the event should be removed
 * \param eventType The kind of event type to register, see #MsfEventType.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaDeleteUserEvent(MsfWindowHandle winHandle, MsfEventType eventType)
{
    SmaEventItem *event;
    
    event = findEventByHandle(winHandle, SMA_USR_EVENT, 0, 
		(MsfNotificationType)0,  eventType);
      
    if (NULL == event)
    {
        return FALSE;
    }

    (void)MSF_WIDGET_HANDLE_MSF_EVT(winHandle, eventType, 0, 1); 
    memset(event, 0, sizeof(SmaEventItem));
    return TRUE;
}


/*!\brief Finds a empty slot for inserting a new event.
 *
 * \param eventItems A pointer to a list (SMA_MAX_ACTIVE_ACTIONS items) of
 *                    actions.
 * \return The index of the empty slot or -1 if no slot could be found.
 *****************************************************************************/
static int findEmptyEventSlot(const SmaEventItem *eventItems)
{
    int i;
    for(i = 0; i < SMA_MAX_ACTIVE_ACTIONS; i++)
        if (SMA_NO_EVENT == eventItems[i].eventType)
            return i;
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
            SAUISIG_68CF1525AB4D73E087DB0E54323F5DC6, "findEmptyEventSlot - no empty slots"));
    return -1;
}

/*!
 * \brief Registers an event into the widget event handler
 *
 * \param eventItem A pointer to a valid smaEventItem structure.
 * \param callback  A callback function that is called when an event is 
 *                  generated or NULL if no callback is used.
 * \param fsm       The fsm to send a signal. The fsm is only valid if callback
 *                  is NULL.
 * \param signal    The signal to send. The signal is only valid if callback is
 *                  NULL.
 *****************************************************************************/
static void registerEventItem(SmaEventItem *eventItem, 
    SmaActionCallBack callback, int fsm, int signal)
{
    /* Check if callback should be used */
    if (NULL != callback)
    {
        /* Register callback func */
        eventItem->response.callback.func = callback;
        eventItem->response.type         = SMA_WIDGET_CALLBACK;
    }
    else
    {
        /* Register callback signal */
        eventItem->response.callback.sig.fsm    = fsm;
        eventItem->response.callback.sig.signal = signal;
        eventItem->response.type                = SMA_WIDGET_SIGNAL;
    }
}

/*!\brief Creates a new action, binds the action to a window and register the
 *        action in the signal dispatcher for widget actions.
 *
 * \param winHandle The window to bind the action to.
 * \param action    The action to bind.
 * \param callback  A callback function that is called when an action is 
 *                  generated or NULL if no callback is used.
 * \param fsm       The fsm to send a signal. The fsm is only valid if callback
 *                  is NULL.
 * \param signal    The signal to send. The signal is only valid if callback is 
 *                  NULL.
 * \param strId     The label for the action.
 * \return          The new action handle or 0 if something went wrong.
 *****************************************************************************/
MsfActionHandle smaCreateAction(MsfWindowHandle winHandle, 
    MsfActionType action, SmaActionCallBack callback, int fsm, int signal, 
    MSF_UINT32 strId)
{
    MsfActionHandle actionHandle;
    actionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA,
        SMA_GET_STR_ID(strId), action, 0, MSF_ACTION_PROPERTY_ENABLED);
    if (0 == actionHandle)
    {
        return 0;
    }
    if (0 > MSF_WIDGET_ADD_ACTION(winHandle, actionHandle))
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return 0;
    }
    if (smaRegisterAction(winHandle, actionHandle, callback, fsm, signal))
    {
        return actionHandle;
    }
    else
    {
        (void)MSF_WIDGET_RELEASE(actionHandle);
        return 0;
    }
}

/*!\brief Registers an event into the widget signal dispatcher.
 *
 * \param eventItem The event item to store in
 * \param eventType Type of event to dispatch (notification or action)
 * \param actionHandle A handle to the action to register. (0 for notifs)
 * \param notifType The notification type to register (0 for actions)
 * \param callback  A callback function that is called when an event is 
 *                  generated or NULL if no callback is used.
 * \param fsm The fsm to send a signal. 
 * \param signal The signal to send. 
 * \return TRUE if successful, otherwise FALSE..
 *****************************************************************************/
static void addEventToSlot(SmaEventItem *eventItem, SmaEventType eventType,
    MsfActionHandle actionHandle, MsfNotificationType notifType, 
    MsfEventType usrEvent, SmaActionCallBack callback, int fsm,  int signal)
{
    eventItem->eventType = eventType;
    
    switch (eventType)
    {
    case SMA_ACTION_EVENT:
        eventItem->identifier.actionHandle = actionHandle;
        break;
    case SMA_NOTIFICATION_EVENT:
        eventItem->identifier.notifType = notifType;
        break;
    case SMA_USR_EVENT:
        eventItem->identifier.usrEventType = usrEvent;
        break;
	case SMA_NO_EVENT:
	/* lint -fallthrough */
	default:
		break;
    }

    registerEventItem(eventItem, callback, fsm, signal);
}


/*!\brief Registers an event into the widget signal dispatcher.
 *
 * \param widgetHandle The widget to bind the event to.
 * \param eventType Type of event to dispatch (notification or action)
 * \param actionHandle A handle to the action to register. (only for actions)
 * \param notifType The notification type to register (only for notifs)
 * \param usrEvent The user event to register (only for usr events)
 * \param callback A callback function that is called when an event is 
 *                 generated or NULL if no callback is used.
 * \param fsm The fsm to send a signal. 
 * \param signal The signal to send. 
 * \return TRUE if successful, otherwise FALSE..
 *****************************************************************************/
MSF_BOOL smaRegisterEvent(MSF_UINT32 widgetHandle, SmaEventType eventType,
    MsfActionHandle actionHandle, MsfNotificationType notifType,
    MsfEventType usrEvent, SmaActionCallBack callback, int fsm,
    int signal)
{
    SmaWidgetItem *list;
    unsigned int i;
    int sIndex;

    /* only add supported events */
    if ((eventType != SMA_ACTION_EVENT) && 
        (eventType != SMA_NOTIFICATION_EVENT) &&
        (eventType != SMA_USR_EVENT))
    {
        return FALSE;
    }

    /* Check if the widget is registered */
    for (i = 0; i < widgetItemCount; i++)
    {
        if (widgetHandle == widgetList[i].handle)
        {
#ifdef WAP_SUPPORT
            if (findEventByHandle(widgetHandle, eventType, (MsfActionHandle) 0, 
                notifType, (MsfEventType)usrEvent))
            {
                return TRUE;
            }
#endif /* WAP_SUPPORT */
            sIndex = findEmptyEventSlot(widgetList[i].eventList);
            if (sIndex >= 0)
            {
                addEventToSlot(&widgetList[i].eventList[sIndex],
                    eventType, actionHandle, notifType, usrEvent,
                    callback, fsm, signal);
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    /* The window needs to be registered */
    for (i = 0; i < widgetItemCount; i++)
    {
        /* Check if the slot is empty */
        if (0 == widgetList[i].handle)
        {
            widgetList[i].handle = widgetHandle;
            sIndex = findEmptyEventSlot(widgetList[i].eventList);
            if (sIndex >= 0)
            {
                addEventToSlot(&widgetList[i].eventList[sIndex],
                    eventType, actionHandle, notifType, usrEvent,
                    callback, fsm, signal);
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    /* If there is no empty slot get a larger buffer */
    list = SMA_ALLOC((widgetItemCount+1)*sizeof(SmaWidgetItem));
    memset(list, 0, (widgetItemCount+1)*sizeof(SmaWidgetItem));
    /* copy old window and action handles*/
    memcpy(list, widgetList, widgetItemCount*sizeof(SmaWidgetItem));
    SMA_FREE(widgetList);
    widgetList = list;
    ++widgetItemCount;
    /* register the new action */
    widgetList[i].handle = widgetHandle;
    addEventToSlot(&widgetList[i].eventList[0],
        eventType, actionHandle, notifType, usrEvent,
        callback, fsm, signal);  
    return TRUE;
}

/*!\brief Registers an action into the widget signal dispatcher.
 *
 * \param winHandle The window to bind the action to.
 * \param actionHandle A handle to the action to register.
 * \param callback A callback function that is called when an action is 
 *                 generated or NULL if no callback is used.
 * \param fsm The fsm to send a signal. 
 * \param signal The signal to send. 
 * \return TRUE if successful, otherwise FALSE..
 *****************************************************************************/
MSF_BOOL smaRegisterAction(MsfWindowHandle winHandle, 
    MsfActionHandle actionHandle,
    SmaActionCallBack callback, int fsm,  int signal)
{
    return smaRegisterEvent(winHandle, SMA_ACTION_EVENT, actionHandle, 
		(MsfNotificationType)0, (MsfEventType)0, callback, fsm, signal);
}

/*!\brief Registers a notification into the widget signal dispatcher.
 *
 * \param winHandle The window to bind the notification to.
 * \param notifType The kind of notification to register. 
 * \param callback A callback function that is called when the notif is 
 *                 generated or NULL if no callback is used.
 * \param fsm The fsm to send a signal. 
 * \param signal The signal to send. 
 * \return TRUE if successful, otherwise FALSE..
 *****************************************************************************/
MSF_BOOL smaRegisterNotification(MsfWindowHandle winHandle, 
    MsfNotificationType notifType, SmaActionCallBack callback, int fsm, 
    int signal)
{
    return smaRegisterEvent(winHandle, SMA_NOTIFICATION_EVENT, 0, notifType, 
		(MsfEventType)0, callback, fsm, signal);
}

/*!\brief Registers a User Event into the widget signal dispatcher.
 *
 * \param winHandle The window to bind the user event to.
 * \param eventType The kind of event type to register, see #MsfEventType.
 * \param callback A callback function that is called when the event is 
 *                 generated or NULL if no callback is used.
 * \param fsm The fsm to send a signal. 
 * \param signal The signal to send. 
 * \return TRUE if successful, otherwise FALSE..
 *****************************************************************************/
MSF_BOOL smaRegisterUserEvent(MsfWindowHandle winHandle, 
    MsfEventType eventType, SmaActionCallBack callback, int fsm, int signal)
{
    if (MSF_WIDGET_HANDLE_MSF_EVT(winHandle, eventType, 1, 0) < 0)
    {
        return FALSE;
    }
    if (!smaRegisterEvent(winHandle, SMA_USR_EVENT, 0, (MsfNotificationType)0,
		eventType, callback, fsm, signal))
    {
        (void)MSF_WIDGET_HANDLE_MSF_EVT(winHandle, eventType, 0, 1);
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief The signal dispatcher for Widgets.
 *
 * When a new external signal is received it needs to be converted into a 
 * internal signal. This function converts an external signal to a internal
 * one.
 *
 * \param signal The type of external signal that was received.
 * \param p A pointer to the data attached to the signal, this is dependent on
 *          the signal.
 *****************************************************************************/
void smaWidgetSignalHandler(MSF_UINT16 signal, void *p)
{
    msf_widget_action_t *was;
    msf_widget_notify_t *wns;
    msf_widget_userevt_t *ues;
    switch(signal)
    {
    case MSF_SIG_WIDGET_ACTION:
        was = (msf_widget_action_t*) p;
               
        /* Convert the external action signal into a internal */
        if (handleWidgetAction(was->handle, was->action))
        {
            break;
        }
        if (smaHandleConfirmationDialogSignal(was->handle, was->action))
        {
            break;
        }
        (void)widgetActionHandler(was->action, was->handle, getPlayerInfo());
        
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
            SAUISIG_663BAC903F9888948AE16F888EEA6ABA, "smaWidgetSignalHandler() - signal not handled\n"));
        break;
    case MSF_SIG_WIDGET_NOTIFY:
        wns = (msf_widget_notify_t*)p;
        /* First check if any handlers have been registered for this 
           window/notification type combo */
        if (handleWidgetNotification(wns->handle, wns->notificationType))
        {
            break;
        }
        if (wns->notificationType == MsfNotifyLostFocus)
        {
            /* Check if a global dialog has been disabled */
            if (handleDialogNotification(wns->handle))
            {
                break;
            }
        }
        else if (wns->notificationType == MsfNotifyResourceLoaded)
        {
            (void)SMA_SIGNAL_SENDTO_IUU( SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, 0L, SMA_ASIO_RESULT_OK, 0);
        }
        else if (wns->notificationType == MsfNotifyResourceFailed || 
            (MsfNotificationTypeExt)wns->notificationType >= MsfNotifyFailedResolution)
        {
            SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
        }
        break;
        
    case MSF_SIG_WIDGET_USEREVT:
        ues = (msf_widget_userevt_t *)p;
        if (!handleUsrEvent(ues->handle, ues->event.eventType, 
            ues->event.eventClass))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
                SAUISIG_6EDBCD59B1AB329CBEA39448A7664E01, "(%s) (%d) Unhandled widget user event signal!\n", __FILE__, 
                __LINE__));
        }
        break;
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
            SAUISIG_E7C861E8FF00C307DA35A2B865AB4129, "smaWidgetSignalHandler() Unhandled signal from MSF Widget\n"));
        break;
    }
}

/*!
 * \brief Handles dialog events.
 *
 * \param windowHandle A handle to the dialog to delete.
 * \return TRUE if a dialog was deleted, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL handleDialogNotification(MsfWindowHandle windowHandle)
{
    /* Panic dialog */
    if (smaDeletePanicDialog(windowHandle))
    {
        /* If the panic dialog is closed, shut down the application */
        EXIT_SMIL_PLAYER(SMA_RESULT_OK);
        return TRUE;
    }
    /* Global dialog handling */
    else if(smaDeleteDialog(windowHandle))
    {
        return TRUE;
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
            SAUISIG_7C948064F4118EB89141D0C3C3566915, "(%s) (%d) unhandled dialog notification\n", __FILE__, __LINE__));
    }
    return FALSE;
}


