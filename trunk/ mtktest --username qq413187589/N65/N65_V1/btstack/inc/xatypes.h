#ifndef __XATYPES_H
#define __XATYPES_H
/***************************************************************************
 *
 * File:
 *     $Workfile:xatypes.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision:21$
 *
 * Description:
 *     This file contains declarations for iAnywhere (formerly iAnywhere)
 *     protocol stacks.
 *
 * Created:
 *     November 19, 1996
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

#include "config.h"

/****************************************************************************
 *
 * Base definitions used by the stack and framer
 *
 ****************************************************************************/

#ifndef BOOL_DEFINED
typedef unsigned char BOOL;   /* IGNORESTYLE */
#endif

typedef unsigned int  U32;
typedef unsigned short U16;
typedef unsigned char  U8;

typedef signed int  S32;
typedef signed short S16;
typedef char  S8;

/* Variable sized integers. Used to optimize processor efficiency by
 * using the most efficient data size for counters, arithmatic, etc.
 */
typedef unsigned long  I32;

#if XA_INTEGER_SIZE == 4
typedef unsigned long  I16;
typedef unsigned long  I8;
#elif XA_INTEGER_SIZE == 2
typedef unsigned short I16;
typedef unsigned short I8;
#elif XA_INTEGER_SIZE == 1
typedef unsigned short I16;
typedef unsigned char  I8;
#else
#error No XA_INTEGER_SIZE specified!
#endif

typedef void (*PFV) (void);

/* Boolean Definitions */
#ifndef TRUE
#define TRUE  (1==1)
#endif /* TRUE */

#ifndef FALSE
#define FALSE (0==1)  
#endif /* FALSE */

#endif /* __XATYPES_H */
