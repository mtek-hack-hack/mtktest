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
/*
 * uis_a.c
 *
 * Created by Klas Hermodsson, Thu May 22 15:50 2003.
 *
 * Revision  history:
 * 2003-09-22 (MADE) Removed UISa_newMessage (int msgType)
 *                   Removed UISa_noPendingMessages (int msgType)
 *                   Added UISa_notifyUnreadMsgCount (int msgType, unsigned nbrOfUnreadMsgs);
 * 
 *
 */

#include "uis_a.h"

#include "msf_log.h"


/* ref src adapter function */
/* May be called at any time and several times with the same value.
 * nbrOfUnreadMsgs may be 0 which means there are no unread messages.
 */
void
UISa_notifyUnreadMsgCount (int msgType, unsigned nbrOfUnreadMsgs)
{
  MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_UIS,  
    UIS_A_95208430155E809622227D5427A3155B, "UIS: msgType %i, nbrOfUnreadMsgs %u [UISa_notifyUnreadMsgCount]\n", 
    msgType, nbrOfUnreadMsgs));
}


