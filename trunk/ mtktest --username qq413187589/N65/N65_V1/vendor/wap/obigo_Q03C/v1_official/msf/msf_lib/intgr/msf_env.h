/*
 * Copyright (C) Obigo AB, 2002-2006.
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
/*
 * msf_env.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 * 
 *
 */

#ifndef _msf_env_h
#define _msf_env_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_int_h
#include "msf_int.h"
#endif

/****************************************
 * Messaging
 ****************************************/

MSF_UINT8
HDIc_signalGetDestination (void* signalData);

MSF_UINT8
HDIc_signalGetSource (void* signalData);


/**********************************************************************
 * Named Pipes
 **********************************************************************/

void
HDIc_pipeNotify (MSF_UINT8 modId, int handle, int eventType);


/**********************************************************************
 * Sockets
 **********************************************************************/

void
HDIc_socketConnectResponse (MSF_UINT8 modId, int socketId, int result);

void
HDIc_socketNotify (MSF_UINT8 modId, int socketId, int eventType);

void
HDIc_socketHostByName (MSF_UINT8 modId, int requestId, int result,
                       unsigned char *addr, int addrLen);

/**********************************************************************
 * File
 **********************************************************************/

void
HDIc_fileNotify (MSF_UINT8 modId, int fileHandle, int eventType);


/**********************************************************************
 * Telephone
 **********************************************************************/

void
HDIc_telMakeCallResponse (MSF_UINT8 modId, MSF_UINT16 telId, int result);

void
HDIc_telSendDtmfResponse (MSF_UINT8 modId, MSF_UINT16 telId, int result);


/**********************************************************************
 * Phonebook
 **********************************************************************/

void
HDIc_pbAddEntryResponse (MSF_UINT8 modId, MSF_UINT16 pbId, int result);


/**********************************************************************
 * Widgets
 **********************************************************************/

void
HDIc_widgetNotify(MSF_UINT8 modId, MSF_UINT32 msfHandle, MsfNotificationType notificationType);

void
HDIc_widgetAction(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 action);

void
HDIc_widgetUserEvent(MSF_UINT8 modId, MSF_UINT32 msfHandle, MsfEvent* msfEvent);

void
HDIc_widgetAccessKey(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 accessKey);

#ifdef MSF_CONFIG_PIM

/**********************************************************************
 * PIM
 **********************************************************************/
void 
HDIc_pimOpenResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 result);

void 
HDIc_pimCloseResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 result);

void 
HDIc_pimAddrLookupResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 numRecordInfos,
                            MsfPimAddrRecordInfo *recordInfos, MSF_UINT16 result);

void 
HDIc_pimAddrLookupNameResponse (MSF_UINT8 modId, MSF_UINT16 requestId, 
                                const char *name, MSF_UINT32 recordId, MSF_UINT16 result);

void 
HDIc_pimAddrGetRecordReponse(MSF_UINT8 modId, MSF_UINT16 requestId, MsfPimField *fields,
                             MSF_UINT16 numFields, MSF_UINT32 recordId, MSF_UINT16 result);

void 
HDIc_pimAddrSetRecordResponse(MSF_UINT8 modId, MSF_UINT16 requestId, 
                              MSF_UINT32 recordId, MSF_UINT16 result);
#endif /*MSF_CONFIG_PIM*/

#endif
