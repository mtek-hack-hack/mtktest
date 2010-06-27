/*
 * Copyright (C) Obigo AB, 2002-2005.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */










#ifndef _mms_ui_h
#define _mms_ui_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif

int mmsHandleExtUISignal(MSF_UINT8 module, MSF_UINT16 signal, void *sigData);
void mmsHandleUISStart(void);

void mmsNotifyUISMsgNew(MSF_UINT32 msgId);
void mmsNotifyUISMsgDeleted(MSF_UINT32 msgId);
void mmsNotifyUISMsgChanged(MSF_UINT32 msgId);
void mmsNotifyUISUnreadMsg(MSF_UINT16 nbrOfUnreadMsgs);

#endif 


