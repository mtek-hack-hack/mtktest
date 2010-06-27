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

/*! \file maopts.h
 * \brief A library for parsing/encoding command line options.
 */


#ifndef _maopts_H
#define _maopts_H

/*--- Definitions/Declarations ---*/
typedef struct mea_opts_token_s
{
    MSF_BOOL                isOption;       /* Is Option parameter, otherwise option data */
    MSF_UINT32              numberOfChars;  /* String length of token (parsed chars) */
    MSF_UINT32              length;         /* Binary length of token */
    char                    *start;         /* start of token string */
    struct mea_opts_token_s *next;          /* Next token */
} mea_opts_token;

typedef struct mea_opts_list
{
    char                    *line;          /* The command line */
    MSF_UINT32             lineLength ;    /* Line buffer length */
    struct mea_opts_token_s *tokenList;     /* List of tokens */
    MSF_UINT32             maxLength;      /* Maximum command line length */
} mea_opts_list;

/*!
 *	\brief The first function to call when to parse a command line.
 *  \param   line, Command line to parse
 *  \param   modId, Where to allocate memory.
 *  \return  structure with parsed data.
 */
mea_opts_list *mea_opts_get_list(MSF_UINT8 modId, const char *commandLine);

/*!
 *	\brief Free entire args list structure.
 *  \param   list, structure to free.
 *  \param   modId, Where to memory was allocated.
 */
void mea_opts_free_list(MSF_UINT8 modId, mea_opts_list *list);

/*!
 *	\brief Find parameter
 *  \param   option, the string command option (-option).
 *  \return  pointer to param.
 */
mea_opts_token *mea_opts_find_option(const mea_opts_list *p, const char *option);

/*!
 * \brief Get next command argument,
 * This is called after mea_opts_find_cmd to
 * get a pointer to the first command argument, and the the next etc.
 * When the last argument was found this function returns NULL.
 *  \param   p, pointer to token list.
 *  \return  pointer to command argument, returns null if not available.
 */
mea_opts_token *mea_opts_get_next_arg(const mea_opts_token *p);

/*!
 *	\brief Get command argument unsigned number value.
 *  \param   p,  pointer to command argument.
 *  \param   ip, integer to store value into (result).
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_get_uint32(const mea_opts_token *p, MSF_UINT32 *ip);

/*!
 *	\brief Get command argument signed number value.
 *  \param   p, pointer to command argument.
 *  \param   ip, integer to store value into (result).
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_get_int32(const mea_opts_token *p, MSF_INT32 *ip);

/*!
 *	\brief Get command argument string value.
 *  \param   p, pointer to command argument.
 *  \param   modId, Where to allocate memory.
 *  \param   str, string to store value into (result).
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_get_str(MSF_UINT8 modId, const mea_opts_token *p, char **str);

/*!
 *	\brief Get command argument binary value.
 *  \param   p, pointer to command argument.
 *  \param   modId, Where to allocate memory.
 *  \param   dp, pointer to allocated binary data (result).
 *  \param   size,  size of allocated binary data (result).
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_get_data(MSF_UINT8 modId, const mea_opts_token *p, void **dp,
    MSF_UINT32 *size);


/*!
 *	\brief The first function to call when to create a command line.
 *  \param   modId, Where to allocate memory.
 *  \paramm  maxLen, Maximum length of command line string to create.
 *  \return  structure with parsed data.
 */
mea_opts_list *mea_opts_create_list(MSF_UINT8 modId, MSF_UINT32 maxLen);


/*!
 *	\brief Add parameter string.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   option, option name string.
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_option(MSF_UINT8 modId, mea_opts_list *p,
    const char *option);

/*!
 *	\brief Set command argument unsigned number value.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   i, integer to add as argument
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_uint32(MSF_UINT8 modId, mea_opts_list *p, MSF_UINT32 i);


/*!
 *	\brief Add command argument signed number value.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   i, integer to add as argument
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_int32(MSF_UINT8 modId, mea_opts_list *p, 
    MSF_INT32 i);

/*!
 *	\brief Add command argument string value.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   str, integer to get value from.
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_str(MSF_UINT8 modId, mea_opts_list *p, 
    const char *str);

/*!
 *	\brief Add command argument string value.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   dp, pointer to binary data.
 *  \param   size,  size of binary data.
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_data(MSF_UINT8 modId, mea_opts_list *p, void *dp,
    MSF_UINT32 size);

/*!
 *	\brief Get options line string
 *  \param   p,  pointer to command list.
 *  \param   line_len, length of command line.
 *  \return  Command line string.
 */
const char *mea_opts_get_line(const mea_opts_list *p, MSF_UINT32 *line_len);


#endif /* _mea_opts_H */


