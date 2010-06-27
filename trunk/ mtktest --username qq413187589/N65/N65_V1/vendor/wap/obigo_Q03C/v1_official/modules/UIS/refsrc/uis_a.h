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
 * uis_a.h
 *
 * Created by Klas Hermodsson, Thu May 22 15:47:35 2003.
 *
 * Revision  history:
 * 2003-09-22 (MADE) Removed UISa_newMessage (int msgType)
 *                   Removed UISa_noPendingMessages (int msgType)
 *                   Added UISa_notifyUnreadMsgCount (int msgType, unsigned nbrOfUnreadMsgs);
 * 
 *
 */

#ifndef _uis_a_h
#define _uis_a_h

#include "uis_cfg.h"



/* ref src adapter function */
/* May be called at any time and several times with the same value.
 * nbrOfUnreadMsgs may be 0 which means there are no unread messages.
 */
void
UISa_notifyUnreadMsgCount (int msgType, unsigned nbrOfUnreadMsgs);




#endif


