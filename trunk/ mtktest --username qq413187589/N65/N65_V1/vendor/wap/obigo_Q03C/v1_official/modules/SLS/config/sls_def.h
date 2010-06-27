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
/*! \file sls_def.h
 * \brief  Definitions for SLS
 */

/*--- Include files ---*/

/*--- Definitions/Declarations ---*/

#ifndef _SLS_DEF_H
#define _SLS_DEF_H

#define SLS_HASH_MARK       '#'
/*--- Types ---*/

/* ! \struct SlsCharsetItem
 * \brief Structure used for conversion between MMS and MSF charset 
 * definitions.
 *
 */
typedef struct
{
    const MSF_UINT32 mmsCharset;    /*!< The MMS charset definition */
    const MSF_UINT32 msfCharset;    /*!< The MSF charset definition */
}SlsCharsetItem;

/*--- Constants ---*/

/*! Object types for the SLS
 *
 */
typedef enum
{
    SLS_OBJECT_TYPE_NONE,       /*!< No object  */
    SLS_OBJECT_TYPE_TEXT,       /*!< Text object  */
    SLS_OBJECT_TYPE_IMAGE,      /*!< Image object */
    SLS_OBJECT_TYPE_AUDIO,      /*!< Audio object */
    SLS_OBJECT_TYPE_VIDEO,      /*!< Video object */
	SLS_OBJECT_TYPE_ATTACMENT,  /*!< Attacment object */
	SLS_OBJECT_TYPE_DRM         /*!< Used for DRM content */      
}SlsMediaObjectType;

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/

/*--- Prototypes ---*/
/**************************************************************************/


#endif /* _SLS_DEF_H */


