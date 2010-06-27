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
 * phs_if.h
 *
 * Created by Kent Olsson, Wed July 03 18:23:35 2001.
 *
 * Revision  history:
 *
 *
 */

#ifndef _phs_if_h
#define _phs_if_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif


/**********************************************************************
 * Signals in the PUSH API:
 **********************************************************************/

/* Signals sent to the PHS Module */
#define PHS_SIG_OPEN_PUSH_CONNECTION             ((MSF_MODID_PHS << 8) + 0x01)
#define PHS_SIG_CLOSE_PUSH_CONNECTION            ((MSF_MODID_PHS << 8) + 0x02)

/* Signals sent from the PHS Module */
#define PHS_SIG_CONNECTION_OPENED                ((MSF_MODID_PHS << 8) + 0x03)
#define PHS_SIG_CONNECTION_CLOSED                ((MSF_MODID_PHS << 8) + 0x04)

/**********************************************************************
 * Error Codes:
 **********************************************************************/

#define PHS_ERR_OK                                   0x00
#define PHS_ERR_OK_ALREADY_OPENED_BY_OTHER_MODULE    0x01
#define PHS_ERR_FAILED_HANDLE_ALREADY_EXIST          0x02
#define PHS_ERR_FAILED_TOO_MANY_CONN                 0x03
#define PHS_ERR_FAILED_ALREADY_EXIST_WITH_OTHER_NWA  0x04
#define PHS_ERR_CONN_CLOSED_BY_STK                   0x05

 /**********************************************************************
 * Incoming Signals:
 **********************************************************************/

/* For the signal PSH_SIG_OPEN_PUSH_CONNECTION */
typedef struct {
  MSF_INT16  handle;
  MSF_UINT16 portNumber;
  MSF_INT16  connectionType;
  MSF_INT32  networkAccountId;
} phs_open_push_connection_t;

/* For the signal PSH_SIG_CLOSE_PUSH_CONNECTION */
typedef struct {
  MSF_INT16 handle;
} phs_close_push_connection_t;

/**********************************************************************
 * Outgoing Signals:
 **********************************************************************/

/* For the signal PHS_SIG_CONNECTION_OPENED */
typedef struct {
  MSF_INT16 handle;
  MSF_INT16 errorCode;
} phs_connection_opened_t;

/* For the signal PHS_SIG_CONNECTION_CLOSED */
typedef struct {
  MSF_INT16 handle;
  MSF_INT16 errorCode;
} phs_connection_closed_t;

/*
 * Called by any other module that wants to use the PHS module.
 */
void
PHSif_startInterface (void);


/**********************************************************************
 * Signal-sending API
 * These functions should be used by any other module that wants to
 * send a signal to the PSH module.
 **********************************************************************/

/*
 * Signals sent from client to PHS Module
 */
void
PHSif_openPushConnection (MSF_UINT8 modId, int handle,
                          MSF_UINT16 portNumber, int connectionType,
                          MSF_INT32 networkAccountId);

void
PHSif_closePushConnection (MSF_UINT8 modId, int handle);


/**********************************************************************
 * Conversion routines for all signal owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/

int
phs_cvt_open_push_connection (msf_dcvt_t *obj, phs_open_push_connection_t* p);

int
phs_cvt_close_push_connection (msf_dcvt_t *obj, phs_close_push_connection_t* p);

int
phs_cvt_connection_opened (msf_dcvt_t *obj, phs_connection_opened_t *p);

int
phs_cvt_connection_closed (msf_dcvt_t *obj, phs_connection_closed_t *p);

/*
 * Convert from memory buffer to signal structs.
 */
void*
phs_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);

/*
 * Released a signal structure to a signal.
 */
void
phs_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);

#endif


