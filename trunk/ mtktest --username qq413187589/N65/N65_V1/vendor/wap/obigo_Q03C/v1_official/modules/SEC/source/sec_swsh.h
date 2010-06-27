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







#ifndef _sec_swsh_h
#define _sec_swsh_h

#ifndef _sec_sw_h
#include "sec_sw.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif

struct SessionInfo {
  MSF_UINT8 sessionOptions;
  unsigned char sessionId[SESSION_ID_LEN]; 
  MSF_UINT8 sessionIdLen;
  MSF_UINT8 cipherSuite[2];
  MSF_UINT8 compressionAlg;
  unsigned char privateKeyId[PRIVATE_KEY_ID_LEN];
  MSF_UINT32 creationTime;
};
 
struct SessionRecord {
  struct SessionInfo info;
  unsigned char masterSecret[TLS_MASTER_SECRET_LEN];
  MSF_UINT8 isActive;
  MSF_UINT8 slotInUse;
} ;

struct PeerRecord {
  int connectionType;
  unsigned char address[ADDRESS_LEN];
  int addrlen;
  MSF_UINT16 portnum;
  int masterSecretId;
  MSF_UINT8 slotInUse;
} ;


void SWWIM_retrieveMasterSecret(int masterSecretId, unsigned char *masterSecret, int masterSecretLen, int *res);
void SWWIM_storeMasterSecret(unsigned char *masterSecret, int masterSecretLen, int *masterSecretId, int *res);

void SWWIM_clearSessionInfoRecord(struct SessionInfo *info);
void SWWIM_clearSessionRecord(struct SessionRecord *rec);
void SWWIM_clearPeerRecord(struct PeerRecord *rec);
void SWWIM_clearSessionInfo(int index);
void SWWIM_clearPeerInfo(int index);

void SWWIM_sessionInit (void);
void SWWIM_sessionClose (void);


#endif 
