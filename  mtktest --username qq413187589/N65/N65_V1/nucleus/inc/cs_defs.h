/*************************************************************************/
/*                                                                       */
/*        Copyright (c) 1993-2001 Accelerated Technology, Inc.           */
/*                                                                       */
/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
/* subject matter of this material.  All manufacturing, reproduction,    */
/* use, and sales rights pertaining to this subject matter are governed  */
/* by the license agreement.  The recipient of this software implicitly  */
/* accepts the terms of the license.                                     */
/*                                                                       */
/*************************************************************************/

/*************************************************************************/
/*                                                                       */
/* FILE NAME                                            VERSION          */
/*                                                                       */
/*      cs_defs.h                                       PLUS  1.13       */
/*                                                                       */
/* COMPONENT                                                             */
/*                                                                       */
/*      CS -    Common Services                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This file contains data structure definitions used in the common */
/*      service linked list routines.                                    */
/*                                                                       */
/* AUTHOR                                                                */
/*                                                                       */
/*      Accelerated Technology, Inc.                                     */
/*                                                                       */
/* DATA STRUCTURES                                                       */
/*                                                                       */
/*      CS_NODE                             Link node structure          */
/*                                                                       */
/* FUNCTIONS                                                             */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* DEPENDENCIES                                                          */
/*                                                                       */
/*      nucleus.h                           Nucleus PLUS constants       */
/*                                                                       */
/* HISTORY                                                               */
/*                                                                       */
/*         DATE                    REMARKS                               */
/*                                                                       */
/*      03-01-1993      Created initial version 1.0                      */
/*      04-19-1993      Verified version 1.0                             */
/*      06-01-1993      Added padding conditional into                   */
/*                      CS_NODE structure, making                        */
/*                      version 1.0a                                     */
/*      06-01-1993      Verified version 1.0a                            */
/*      03-01-1994      Moved include files outside of                   */
/*                      the file #ifndef to allow the                    */
/*                      use of actual data structures,                   */
/*                      resulting in version 1.1                         */
/*                                                                       */
/*      03-18-1994      Verified version 1.1                             */
/*      04-17-1996      updated to version 1.2                           */
/*      03-24-1998      Released version 1.3.                            */
/*                                                                       */
/*************************************************************************/

#include        "nucleus.h"                 /* Include Nucleus constants */


/* Check to see if the file has been included already.  */
#ifndef CS_DEFS
#define CS_DEFS


/* Define a common node data structure that can be included inside of
   other system data structures.  */

typedef struct  CS_NODE_STRUCT
{
    struct CS_NODE_STRUCT  *cs_previous;
    struct CS_NODE_STRUCT  *cs_next;
    DATA_ELEMENT            cs_priority;

#if     PAD_1
    DATA_ELEMENT            cs_padding[PAD_1];
#endif

}  CS_NODE;

#endif


