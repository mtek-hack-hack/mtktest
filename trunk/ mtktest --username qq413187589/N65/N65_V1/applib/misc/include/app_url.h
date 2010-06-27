/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * app_url.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains prototype for URI parsing utilities.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _APP_URL_H
#define _APP_URL_H


/*
 * The different parts of a URL, used to index into the arrays
 * in the msf_url_t type.
 */
#define APPLIB_URL_SCHEME_PART             0
#define APPLIB_URL_AUTHORITY_PART          1
#define APPLIB_URL_PATH_PART               2
#define APPLIB_URL_QUERY_PART              3
#define APPLIB_URL_FRAGMENT_PART           4
#define APPLIB_URL_USERINFO_PART           5
#define APPLIB_URL_HOST_PART               6
#define APPLIB_URL_PORT_PART               7

#define APPLIB_URL_NUM_PARTS               8

#define APPLIB_URL_ERR_INVALID_PARAM	-1
#define APPLIB_URL_ERR_INVALID_SCHEME	-2
#define APPLIB_URL_ERR_INVALID_HOST		-3
#define APPLIB_URL_ERR_INVALID_PORT		-4


/**********************************************************************
 * Type definitions
 **********************************************************************/

/* The scheme type */
typedef enum {
	applib_scheme_empty = 0x00,
	applib_scheme_http = 0x01,
	applib_scheme_https = 0x02,
	applib_scheme_file = 0x04,
	applib_scheme_wtai = 0x08,
	applib_scheme_rtsp = 0x10,
	applib_scheme_unknown = 0xff
} url_scheme_type_enum;


/* The URL type */
typedef struct {
    url_scheme_type_enum  scheme_type;
    const char *          parts[APPLIB_URL_NUM_PARTS];
    int                   len[APPLIB_URL_NUM_PARTS];
} applib_url_struct;


typedef struct 
{
	const char *leading_string;
	int scheme_type;
} applib_scheme_struct;

#define APPLIB_NBR_OF_SUPPORTED_SCHEMES 5

#define APPLIB_URL_SUPPORTED_SCHEMES { \
    { "http",   applib_scheme_http }, \
    { "https",  applib_scheme_https }, \
    { "file",   applib_scheme_file }, \
    { "wtai",   applib_scheme_wtai }, \
    { "rtsp",   applib_scheme_rtsp } }
  

extern int applib_url_check_scheme(applib_url_struct *p);

extern int applib_url_check_host(applib_url_struct *p);

extern int applib_url_check_port(applib_url_struct *p);

extern int applib_parse_url(const char *url, applib_url_struct *p);

extern int applib_url_is_valid(const char *url);

extern int applib_url_is_valid_ext(const char *url, unsigned short schemes);

#endif /* _APP_URL_H */

