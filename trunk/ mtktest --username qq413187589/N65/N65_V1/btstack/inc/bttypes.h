#ifndef __BTTYPES_H
#define __BTTYPES_H

/****************************************************************************
 *
 * File:
 *     $Workfile:bttypes.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision:46$
 *
 * Description:
 *     General types, defines, and prototypes for Blue SDK components.
 *
 * Copyright 1999-2005 Extended Systems, Inc.
 * Portions copyright 2005 iAnywhere Solutions, Inc.
 * All rights reserved. All unpublished rights reserved.
 *
 * Unpublished Confidential Information of iAnywhere Solutions, Inc.  
 * Do Not Disclose.
 *
 * No part of this work may be used or reproduced in any form or by any 
 * means, or stored in a database or retrieval system, without prior written 
 * permission of iAnywhere Solutions, Inc.
 * 
 * Use of this work is governed by a license granted by iAnywhere Solutions,
 * Inc.  This work contains confidential and proprietary information of
 * iAnywhere Solutions, Inc. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/

#include "xatypes.h"
#include "btconfig.h"
#include "xastatus.h"
#include "utils.h"
#include "eventmgr.h"


/*---------------------------------------------------------------------------
 * Global Types layer
 *
 *     General types and conversion functions used by all components of
 *     the stack and applications are defined here.
 */


/****************************************************************************
 *
 * Constants
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * BDADDR_NTOA_SIZE constant
 *
 *     Defines the minimum size for the string when using the bdaddr_ntoa
 *     function.
 */
#define BDADDR_NTOA_SIZE        18


/****************************************************************************
 *
 * Types
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * BtStatus type
 *
 *     This type is returned from most stack APIs to indicate the success
 *     or failure of the operation. In many cases, BT_STATUS_PENDING
 *     is returned, meaning that a future callback will indicate the
 *     result of the operation.
 */
typedef XaStatus BtStatus;

#define BT_STATUS_SUCCESS           XA_STATUS_SUCCESS
#define BT_STATUS_FAILED            XA_STATUS_FAILED
#define BT_STATUS_PENDING           XA_STATUS_PENDING
#define BT_STATUS_BUSY              XA_STATUS_BUSY
#define BT_STATUS_NO_RESOURCES      XA_STATUS_NO_RESOURCES
#define BT_STATUS_NOT_FOUND         XA_STATUS_NOT_FOUND
#define BT_STATUS_DEVICE_NOT_FOUND  XA_STATUS_DEVICE_NOT_FOUND
#define BT_STATUS_CONNECTION_FAILED XA_STATUS_CONNECTION_FAILED
#define BT_STATUS_TIMEOUT           XA_STATUS_TIMEOUT
#define BT_STATUS_NO_CONNECTION     XA_STATUS_NO_CONNECTION
#define BT_STATUS_INVALID_PARM      XA_STATUS_INVALID_PARM
#define BT_STATUS_IN_PROGRESS       XA_STATUS_IN_PROGRESS
#define BT_STATUS_RESTRICTED        XA_STATUS_RESTRICTED
#define BT_STATUS_INVALID_TYPE      XA_STATUS_INVALID_TYPE
#define BT_STATUS_HCI_INIT_ERR      XA_STATUS_HCI_INIT_ERR
#define BT_STATUS_NOT_SUPPORTED     XA_STATUS_NOT_SUPPORTED
#define BT_STATUS_IN_USE            XA_STATUS_IN_USE
#define BT_STATUS_SDP_CONT_STATE    XA_STATUS_CONTINUE
#define BT_STATUS_CANCELLED         XA_STATUS_CANCELLED
#define BT_STATUS_NOSERVICES    XA_STATUS_NOSERVICES
#define BT_STATUS_SCO_REJECT    MTK_STATUS_SCO_REJECT
#define BT_STATUS_CHIP_REASON    MTK_STATUS_CHIP_REASON

/* End of BtStatus */

/*---------------------------------------------------------------------------
 * BtPacketFlags type
 *
 *     This type is used by L2CAP and protocols that use directly L2CAP
 *     to manage the status of a particular BtPacket.
 */
typedef U8 BtPacketFlags;

#define BTP_FLAG_NONE       0x00  /* No current flags */
#define BTP_FLAG_INUSE      0x01  /* Used only by packet owner */
#define BTP_FLAG_LSYSTEM    0x02  /* Used only by L2CAP */
#define BTP_FLAG_TAIL       0x04  /* Used only by L2CAP Applications */
#define BTP_FLAG_RDEV       0x08  /* Used only by L2CAP */
#define BTP_FLAG_FCS        0x10  /* FCS field is valid, set only by L2CAP */
#define BTP_FLAG_HIGH_PRIPORTY       0x20
#define BTP_FLAG_LOW_PRIPORTY       0x40


/* End of BtPacketFlags */


/****************************************************************************
 *
 * Data Structures
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * BtPacket structure
 *
 *     Represents a packet of data. These packets may be used by applications
 *     to provide data to the stack. Certain stack events may also provide
 *     data to the application enclosed in a BtPacket structure.
 */
typedef struct _BtPacket
{
    ListEntry    node;    /* Used internally by the stack. */

    U8          *data;    /* Points to a buffer of user data.  */
    U16          dataLen; /* Indicates the length of "data" in bytes. */

    U8           flags;   /* Must be initialized to BTP_FLAG_NONE by
                           * applications running on top of L2CAP. Other
                           * higher layer protocols must never modify this
                           * value.
                           */
    U8          priority_type;
    /* Group: The following fields are for internal use only by the stack. */
    void        *ulpContext;
    U8          *tail;
    U16          tailLen;

#if XA_STATISTICS == XA_ENABLED
    U32          rfc_timer;
    U32          hci_timer;
    U32          l2cap_timer;
#endif /* XA_STATISTICS == XA_ENABLED */

    U16          llpContext;
    U16          remoteCid;

#if L2CAP_FLOW_CONTROL == XA_ENABLED
    U8           segStart;
    U8           segNum;
    U8           fcs[2];
#endif /* L2CAP_FLOW_CONTROL == XA_ENABLED */

    U8           hciPackets;
    U8           headerLen;
    U8           header[BT_PACKET_HEADER_LEN];
} BtPacket;


/* Indicates size of BD_ADDR array */
#define BD_ADDR_SIZE    6

/*---------------------------------------------------------------------------
 * BD_ADDR structure
 *
 *     Represents a 48-bit Bluetooth device address.
 */
typedef struct _BD_ADDR {
    U8    addr[BD_ADDR_SIZE];
} BD_ADDR;


/* Internal ROM constant defined in btrom.c to represent an invalid address */
extern const BD_ADDR INVALID_BDADDR;


/****************************************************************************
 *
 * Function Reference
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * bdaddr_aton()
 *
 *     Converts an ASCII-formatted Bluetooth device address into a BD_ADDR
 *     structure.
 *
 * Parameters:
 *     addr - Address in the format "xx:xx:xx:xx:xx", where x is a
 *         hexadecimal digit. The most significant byte appears first.
 *
 * Returns:
 *     BD_ADDR - A structure that contains the binary version of the
 *         address.
 */
BD_ADDR  bdaddr_aton(const char *addr);


/*---------------------------------------------------------------------------
 * bdaddr_ntoa()
 *
 *     Converts a BD_ADDR structure into an ASCII-formatted device address.
 *
 * Parameters:
 *     addr - Binary device address to convert.
 *
 *     addrString - Destination string space for formatted device address.
 *         The string must contain at least BDADDR_NTOA_SIZE bytes of space.
 *
 * Returns:
 *     char * - A copy of the pointer passed in as "addrString".
 */
char    *bdaddr_ntoa(const BD_ADDR *addr, char *addrString);


/*---------------------------------------------------------------------------
 * AreBdAddrsEqual()
 *
 *     Compares two Bluetooth device addresses for equality.
 *
 * Parameters:
 *     addrA - First address to compare.
 *
 *     addrB - Second address to compare.
 *
 * Returns:
 *     TRUE when the addresses are the same, FALSE when they are different
 */
BOOL    AreBdAddrsEqual(const BD_ADDR *addrA, const BD_ADDR *addrB);
#define AreBdAddrsEqual(_ADDRA, _ADDRB)   OS_MemCmp((_ADDRA)->addr, 6, (_ADDRB)->addr, 6)


/*---------------------------------------------------------------------------
 * IsValidBdAddr()
 *
 *     Determines whether a BD_ADDR contains a valid Bluetooth device
 *     address.
 *
 * Parameters:
 *     addr - Address to examine.
 *
 * Returns:
 *     TRUE when the address is valid, FALSE if it is invalid.
 */
BOOL    IsValidBdAddr(const BD_ADDR *Addr);
#define IsValidBdAddr(_BDA) (OS_MemCmp((_BDA)->addr, 6, INVALID_BDADDR.addr, 6) == FALSE)

#endif /* __BTTYPES_H */
