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
 * Definitions needed as part of the adaptation for a
 * specific platform.
 *
 */
#ifndef _msf_def_h
#define _msf_def_h

/************************************************************
 * Generic type definitions
 ************************************************************/

typedef signed char     MSF_INT8; 	  /*  INT8    :   8 bit signed integer  */
typedef unsigned char   MSF_UINT8;	  /*  UINT8   :   8 bit unsigned integer  */
typedef signed short    MSF_INT16;	  /*  INT16   :   16 bit signed integer   */
typedef unsigned short  MSF_UINT16; 	/*  UINT16  :   16 bit unsigned integer */
typedef signed long     MSF_INT32;	  /*  INT32   :   32 bit signed integer   */
typedef unsigned long   MSF_UINT32; 	/*  UINT32  :   32 bit unsigned integer */
typedef int             MSF_BOOL;     /*  BOOLEAN :   int */

/* Define this if the platform has support for floating-point numbers. */
#define CFG_MSF_HAS_FLOAT

/* If no real type exists for the host device, define as INT32. */
typedef float           MSF_FLOAT32;  /* FLOAT32 :   32 bit real */


/************************************************************
 * Constants
 ************************************************************/
#ifndef NULL
#define NULL  (void *)0           /*  NULL    :   Null pointer */
#endif

#ifndef TRUE
#define TRUE    1                 /*  TRUE    :   Integer value 1 */
#endif

#ifndef FALSE
#define FALSE   0                 /*  FALSE   :   Integer value 0 */
#endif

#endif
