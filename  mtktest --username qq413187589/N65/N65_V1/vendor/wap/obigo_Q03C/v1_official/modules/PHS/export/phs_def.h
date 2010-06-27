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
 * phs_hdef.h
 *
 * Created by Kent Olsson, Sun Oct 27 14:23:35 2001.
 *
 * Revision history:
 *
 */

#ifndef _brs_hdef_h
#define _brs_hdef_h

#include "msf_cmmn.h"
/***********************************************
 *               SI Documents                  *
 ***********************************************/

/*****************  ELEMENTS  *****************/

#define PHS_ELEMENT_SI                   5
#define PHS_ELEMENT_INDICATION           6
#define PHS_ELEMENT_INFO                 7
#define PHS_ELEMENT_ITEM                 8


/****************  ATTRIBUTES  ****************/

#define PHS_ATTRIBUTE_ACTION             0
#define PHS_ATTRIBUTE_CREATED            1
#define PHS_ATTRIBUTE_HREF               2
#define PHS_ATTRIBUTE_SI_EXPIRES         3
#define PHS_ATTRIBUTE_SI_ID              4
#define PHS_ATTRIBUTE_CLASS              5


/*************  ATTRIBUTE VALUES  *************/

/* ENUM_A */
#define PHS_ATTRVAL_SIGNAL_NONE          0x0A00
#define PHS_ATTRVAL_SIGNAL_LOW           0x0A01
#define PHS_ATTRVAL_SIGNAL_MEDIUM        0x0A02
#define PHS_ATTRVAL_SIGNAL_HIGH          0x0A03
#define PHS_ATTRVAL_SIGNAL_DELETE        0x0A04


/**********************************************/

extern const msf_strtable_info_t phs_SI_Elements;

extern const msf_strtable_info_t phs_SI_Attributes;

extern const msf_strtable_info_t phs_SI_Attrvals;


extern const unsigned char phs_SI_Element_table[];

extern const MSF_UINT16    phs_SI_AttributeTypes[];


#define PHS_SI_TRANSFORM_SIZE 19

extern const MSF_UINT8           phs_SI_AttrTransform[];

extern const msf_strtable_info_t phs_SI_AttrStart;





/***********************************************
 *               SL Documents                  *
 ***********************************************/

/*****************  ELEMENTS  *****************/

#define PHS_ELEMENT_SL                   5


/****************  ATTRIBUTES  ****************/

/* The same as for SI is used */
/* 
#define PHS_ATTRIBUTE_ACTION             0
#define PHS_ATTRIBUTE_HREF               2
*/

/*************  ATTRIBUTE VALUES  *************/

/* ENUM_A */
#define PHS_ATTRVAL_EXECUTE_LOW          0x0A00
#define PHS_ATTRVAL_EXECUTE_HIGH         0x0A01
#define PHS_ATTRVAL_CACHE                0x0A02


/**********************************************/

extern const msf_strtable_info_t phs_SL_Elements;

extern const msf_strtable_info_t phs_SL_Attributes;

extern const msf_strtable_info_t phs_SL_Attrvals;


extern const unsigned char phs_SL_Element_table[];

extern const MSF_UINT16        phs_SL_AttributeTypes[];


#define PHS_SL_TRANSFORM_SIZE 13

extern const MSF_UINT8           phs_SL_AttrTransform[];

extern const msf_strtable_info_t phs_SL_AttrStart;





/***********************************************
 *               CO Documents                  *
 ***********************************************/

/*****************  ELEMENTS  *****************/

#define PHS_ELEMENT_CO                   5
#define PHS_ELEMENT_INVALIDATE_OBJECT    6
#define PHS_ELEMENT_INVALIDATE_SERVICE   7


/****************  ATTRIBUTES  ****************/

#define PHS_ATTRIBUTE_URI                0


/*************  ATTRIBUTE VALUES  *************/


/**********************************************/

extern const msf_strtable_info_t phs_CO_Elements;

extern const msf_strtable_info_t phs_CO_Attributes;


extern const unsigned char phs_CO_Element_table[];

extern const MSF_UINT16        phs_CO_AttributeTypes[];


#define PHS_CO_TRANSFORM_SIZE 10

extern const MSF_UINT8           phs_CO_AttrTransform[];

extern const msf_strtable_info_t phs_CO_AttrStart;





/***********************************************
 *       COMMON FOR ALL PUSH DOCUMENTS         *
 ***********************************************/

extern const msf_strtable_info_t phs_AttrValue;

#endif


