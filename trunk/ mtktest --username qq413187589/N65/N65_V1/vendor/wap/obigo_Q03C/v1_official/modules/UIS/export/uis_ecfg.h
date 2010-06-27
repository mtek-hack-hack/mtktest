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
 * uis_ecfg.h 
 *
 * It is allowed for an integrator to make changes in this file.
 *
 * Created by Klas Hermodsson, Thu Nov 20 11:00 2003.
 *
 * Revision  history:
 *
 * 2004-01-16 (KOGR): CR 13932: entry for UIS_MSG_KEY_STORAGE added in
 *                      UIS_USER_TITLE_PROPERTY_ARRAY
 * 2004-02-19 (KOGR): CR 13636: entry for UIS_MSG_KEY_NBR_OF_MESSAGES_WAITING
 *                      added in UIS_USER_TITLE_PROPERTY_ARRAY
 * 2004-02-19 (KOGR): CR 13934/13626: entry for UIS_MSG_KEY_MSG_STATUS
 *                      added in UIS_USER_TITLE_PROPERTY_ARRAY
 */

#ifndef _uis_ecfg_h
#define _uis_ecfg_h

#ifndef _uis_if_h
  #include "uis_if.h"
#endif


/******************************************************************************************
 *  The number of user message types.
 *
 *  This MUST be set to the number of user message types listed in this file.
 *
 */
#define UIS_NBR_OF_USER_MSG_TYPES           0

/*
 *  The definition of the user message types
 *
 *  The user defined message types MUST have values based on UIS_NBR_OF_SYSTEM_MSG_TYPES!
 *  This ensures that an update of the system message types do not interfere with the 
 *  user message types. All code handling these message types MUST use these 
 *  defines to reference the message type values.
 *  
 *  For each user message type, add a define.
 *
 *  The message types MUST be numbered in sequence with no gaps in between!
 *  That means if there are a total of 10 user message types, they must be numbered 
 *  from UIS_NBR_OF_SYSTEM_MSG_TYPES + 0 to UIS_NBR_OF_SYSTEM_MSG_TYPES + 9!
 *
 *  Example of two user message type definitions:
 *  #define UIS_MSG_TYPE_USER_1                  UIS_NBR_OF_SYSTEM_MSG_TYPES + 0
 *  #define UIS_MSG_TYPE_USER_2                  UIS_NBR_OF_SYSTEM_MSG_TYPES + 1
 */

/* place user message type definitions here */

/******************************************************************************************
 *  The number of user message property keys.
 *
 *  This MUST be set to the number of user message property keys listed in this file.
 *
 */
#define UIS_NBR_OF_USER_KEYS                0

/*
 *  The definition of the user message property keys
 *
 *  The user defined keys MUST have values based on UIS_NBR_OF_SYSTEM_KEYS!
 *  This ensures that an update of the system keys do not interfere with the user keys.
 *  All code handling these user properties MUST use these defines to reference
 *  the message property key values.
 *  
 *  For each user message property, add a define.
 *
 *  The keys MUST be numbered in sequence with no gaps in between!
 *  That means if there are a total of 10 user message property keys, 
 *  they must be numbered from UIS_NBR_OF_SYSTEM_KEYS + 0 to UIS_NBR_OF_SYSTEM_KEYS + 9!
 *
 *  Example of two user message property key definitions:
 *  #define UIS_MSG_USER_KEY_1                  UIS_NBR_OF_SYSTEM_KEYS + 0
 *  #define UIS_MSG_USER_KEY_2                  UIS_NBR_OF_SYSTEM_KEYS + 1
 */

/* place user message property key definitions here */
 
/******************************************************************************************
 *  The title property array.
 *
 *  For a description see UIS_TITLE_PROPERTY_ARRAY in uis_if.h
 *
 *  NOTE that the size of this array MUST be UIS_NBR_OF_KEYS. Which means that
 *  in addition to the system keys there must also be one entry for each defined 
 *  user message property key.
 */
#ifdef WAP_SUPPORT

#define UIS_USER_TITLE_PROPERTY_ARRAY { \
  /*folder {TRUE, 0}, \*/ {FALSE, 0}, \
                        {FALSE, 0}, \
  /* subject \*/        {TRUE, 10}, \
  /* from \*/           {TRUE, 0}, \
  /* timestamp \*/      {TRUE, 0}, \
  /* read \*/           {TRUE, 0}, \
                        {FALSE, 0}, \
                        {FALSE, 0}, \
                       {FALSE, 0}, \
                       {FALSE, 0}, \
  /*expire {FLASE, 0}, \*/ {TRUE, 0}, \
                       {FALSE, 0}, \
                       {FALSE, 0}, \
  /*url {TRUE, 0}, \*/ {TRUE, 0}, \
                       {FALSE, 0}, \
                        {FALSE, 0}, \
                       {FALSE, 0}, \
  /*{TRUE, 0}, \*/     {FALSE, 0}, \
       }
#else
      
#define UIS_USER_TITLE_PROPERTY_ARRAY { \
                        {TRUE, 0}, \
                        {TRUE, 0}, \
                        {TRUE, 0}, \
                        {TRUE, 0}, \
                        {TRUE, 0}, \
                        {TRUE, 0}, \
                        {TRUE, 0}, \
                        {TRUE, 0}, \
                        {TRUE, 0}, \
                       {FALSE, 0}, \
                       {FALSE, 0}, \
                       {FALSE, 0}, \
                       {FALSE, 0}, \
                        {TRUE, 0}, \
                       {FALSE, 0}, \
                       {FALSE, 0}, \
                       {FALSE, 0}, \
                       {TRUE, 0}, \
/* add one entry below for each user message property key defined in this file */ \
        }
#endif 

#endif


