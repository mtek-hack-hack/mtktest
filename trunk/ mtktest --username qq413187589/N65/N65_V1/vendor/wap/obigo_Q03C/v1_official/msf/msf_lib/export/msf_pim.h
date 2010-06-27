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
 * msf_pim.h
 *
 * Created by Magnus Eriksson
 *
 * Revision  history:
 *   
 *
 */
#ifndef _msf_pim_h
#define _msf_pim_h

#ifdef MSF_CONFIG_PIM
#ifndef _msf_int_h
#include "msf_int.h"
#endif

/**********************************************************************
 * PIM interface
 **********************************************************************/

/* 
 * Field types 
 */
#define MSF_PIM_ADDR_FIELD_NAME                 HDI_PIM_ADDR_FIELD_NAME
#define MSF_PIM_ADDR_FIELD_SHORT_NAME           HDI_PIM_ADDR_FIELD_SHORT_NAME
#define MSF_PIM_ADDR_FIELD_NICK_NAME            HDI_PIM_ADDR_FIELD_NICK_NAME 
#define MSF_PIM_ADDR_FIELD_JOB_TITLE            HDI_PIM_ADDR_FIELD_JOB_TITLE
#define MSF_PIM_ADDR_FIELD_STREET               HDI_PIM_ADDR_FIELD_STREET
#define MSF_PIM_ADDR_FIELD_CITY                 HDI_PIM_ADDR_FIELD_CITY 
#define MSF_PIM_ADDR_FIELD_ZIP                  HDI_PIM_ADDR_FIELD_ZIP
#define MSF_PIM_ADDR_FIELD_STATE                HDI_PIM_ADDR_FIELD_STATE
#define MSF_PIM_ADDR_FIELD_COUNTRY              HDI_PIM_ADDR_FIELD_COUNTRY
#define MSF_PIM_ADDR_FIELD_POST_CODE            HDI_PIM_ADDR_FIELD_POST_CODE 
#define MSF_PIM_ADDR_FIELD_TEL                  HDI_PIM_ADDR_FIELD_TEL
#define MSF_PIM_ADDR_FIELD_MOBILE               HDI_PIM_ADDR_FIELD_MOBILE
#define MSF_PIM_ADDR_FIELD_TEL_FAX              HDI_PIM_ADDR_FIELD_TEL_FAX
#define MSF_PIM_ADDR_FIELD_EMAIL                HDI_PIM_ADDR_FIELD_EMAIL
#define MSF_PIM_ADDR_FIELD_BIRTHDAY             HDI_PIM_ADDR_FIELD_BIRTHDAY
#define MSF_PIM_ADDR_FIELD_HOMEPAGE             HDI_PIM_ADDR_FIELD_HOMEPAGE
#define MSF_PIM_ADDR_FIELD_GROUP                HDI_PIM_ADDR_FIELD_GROUP
#define MSF_PIM_ADDR_FIELD_CATEGORY             HDI_PIM_ADDR_FIELD_CATEGORY
#define MSF_PIM_ADDR_FIELD_PICTURE              HDI_PIM_ADDR_FIELD_PICTURE
#define MSF_PIM_ADDR_FIELD_SOUND                HDI_PIM_ADDR_FIELD_SOUND
#define MSF_PIM_ADDR_FIELD_VOICE_MAIL_BOX       HDI_PIM_ADDR_FIELD_VOICE_MAIL_BOX 
#define MSF_PIM_ADDR_FIELD_IM                   HDI_PIM_ADDR_FIELD_IM

/*
 *	Location
 */
#define MSF_PIM_WORK                            HDI_PIM_WORK 
#define MSF_PIM_HOME                            HDI_PIM_HOME

/*
 * Pim objects 
 */
#define MSF_PIM_OBJECT_PHONE_BOOK               HDI_PIM_OBJECT_PHONE_BOOK
#define MSF_PIM_OBJECT_CALENDAR                 HDI_PIM_OBJECT_CALENDAR 
#define MSF_PIM_OBJECT_TODO                     HDI_PIM_OBJECT_TODO 
#define MSF_PIM_OBJECT_ALARM                    HDI_PIM_OBJECT_ALARM 

/* 
 * Filters 
 */
#define MSF_PIM_ADDR_FILTER_MOBILE              HDI_PIM_ADDR_FILTER_MOBILE 
#define MSF_PIM_ADDR_FILTER_FAX                 HDI_PIM_ADDR_FILTER_FAX
#define MSF_PIM_ADDR_FILTER_STREET              HDI_PIM_ADDR_FILTER_STREET  
#define MSF_PIM_ADDR_FILTER_EMAIL               HDI_PIM_ADDR_FILTER_EMAIL
#define MSF_PIM_ADDR_FILTER_IM                  HDI_PIM_ADDR_FILTER_IM 
#define MSF_PIM_ADDR_FILTER_PHONE               HDI_PIM_ADDR_FILTER_PHONE
#define MSF_PIM_ADDR_FILTER_TEL                 HDI_PIM_ADDR_FILTER_TEL 
#define MSF_PIM_ADDR_FILETR_GROUP               HDI_PIM_ADDR_FILETR_GROUP 
#define MSF_PIM_ADDR_FILTER_PIC                 HDI_PIM_ADDR_FILTER_PIC
#define MSF_PIM_ADDR_FILTER_SOUND               HDI_PIM_ADDR_FILTER_SOUND
#define MSF_PIM_ADDR_FILTER_URI                 HDI_PIM_ADDR_FILTER_URI
#define MSF_PIM_ADRR_FILTER_ALL                 HDI_PIM_ADRR_FILTER_ALL 
#define MSF_PIM_ADRR_FILTER_NONE                HDI_PIM_ADRR_FILTER_NONE

/*
 * Result types
 */
#define MSF_PIM_OK                              HDI_PIM_OK
#define MSF_PIM_ERROR_NOT_OPEN                  HDI_PIM_ERROR_NOT_OPEN
#define MSF_PIM_ERROR_ADDR_NO_RECORD            HDI_PIM_ERROR_NO_RECORD
#define MSF_PIM_ERROR_ADDR_CANCEL_BY_USER       HDI_PIM_ERROR_CANCEL_BY_USER
#define MSF_PIM_ERROR_UNSPECIFIED               HDI_PIM_ERROR_UNSPECIFIED
#define MSF_PIM_ERROR_INVALID                   HDI_PIM_ERROR_INVALID
#define MSF_PIM_ERROR_ADDR_MEM_FULL             HDI_PIM_ERROR_MEM_FULL
#define MSF_PIM_ERROR_DUPLICATE_RECORD          HDI_PIM_ERROR_DUPLICATE_RECORD

/*
 * Functions
 */
#define MSF_PIM_OPEN                            HDIa_pimOpen
#define MSF_PIM_CLOSE                           HDIa_pimClose
#define MSF_PIM_ADDR_LOOKUP                     HDIa_pimAddrLookup
#define MSF_PIM_ADDR_LOOKUP_NAME                HDIa_pimAddrLookupName
#define MSF_PIM_ADDR_GET_RECORD                 HDIa_pimAddrGetRecord
#define MSF_PIM_ADDR_SET_RECORD                 HDIa_pimAddrSetRecord

#endif /*MSF_CONFIG_PIM*/

#endif
