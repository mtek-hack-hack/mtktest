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

/*--- Include files ---*/
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */ 
#include "msf_mem.h"    /* MSF: Memory handling */

#include "maopts.h"

static char *skip_white_space(char *str)
{
    if (str == NULL)
    {
        return NULL;
    }
    
    while((*str) != 0 && ((*str) == ' ' || (*str)== '\t'))
    {
        str++;
    }

    return str;
}

/*
 *	Scans through a token:
 *  - Decides if token is option
 *  - Finds token data start
 *  - Finds token data length
 *  \return the end of 
 */
static char *parseToken(MSF_UINT8 modId, char *str, mea_opts_token **res_token)
{
    mea_opts_token  *token = 0;
    MSF_BOOL        isString = FALSE;

    (*res_token) = (mea_opts_token*) MSF_MEM_ALLOC( modId, sizeof(mea_opts_token));

    token = (*res_token);

    if (token == NULL)
    {
        /*
         *	Error; Memory allocation failed.
         */
        return str;
    }

    memset( token, 0, sizeof(mea_opts_token));
    
    if ((*str) == '-')
    {
        token->isOption = TRUE;
        str++;
    }

    if ((*str) == 0)
    {
        MSF_MEM_FREE(modId, token);
        (*res_token) = 0;
        return str;
    }

    if ((*str) == '"')
    {
        isString = TRUE;
        str++;
    }

    token->start = str;

    /*
     *	Scan through token data.
     */
    while ((*str) != 0 &&                                        /* Terminate at end of line */
		( (isString == TRUE && (*str) != '"') ||                 /* Terminate at string end, if string */
          (isString == FALSE && (*str) != ' ' && (*str) != '\t') /* Terminate at white-space, if not string */
          ))
    {
        str++;
    }

    token->length = str-token->start;
    token->next = 0;
    token->numberOfChars = token->length;

    if (isString == TRUE && (*str) == '"')
    {
        str++;
    }
    else if (isString == TRUE)
    {
        MSF_MEM_FREE(modId, token);
        (*res_token) = 0;
        return str;        
    }

    return str;
}

/*
 *	The first function to call when to parse a command line.
 *  \param   line, Command line to parse
 *  \param   modId, Where to allocate memory.
 *  \return  structure with parsed data.
 */
mea_opts_list *mea_opts_get_list(MSF_UINT8 modId, const char *commandLine)
{
    mea_opts_list   *opts = 0;
    char            *str;
    mea_opts_token  *token = 0;
    mea_opts_token  *last_token = 0;
    
    opts = (mea_opts_list*) MSF_MEM_ALLOC( modId, sizeof(mea_opts_list));
    if (opts == NULL)
    {
        return NULL;
    }
    opts->lineLength = strlen(commandLine);
    opts->line = (char*) MSF_MEM_ALLOC( modId, opts->lineLength+1);
    if (opts->line == NULL)
    {
        mea_opts_free_list(modId, opts);
        return NULL;
    }
    memset(opts->line, 0, opts->lineLength+1);
    memcpy(opts->line, commandLine, opts->lineLength+1);
    
    opts->tokenList = 0;
    opts->maxLength = opts->lineLength;

    str = opts->line;
    str = skip_white_space(str);
    
    while (str != 0 && (*str) != 0)
    {
        str = parseToken(modId, str, &token);
        
        if (token == 0 && str != 0)
        {
            /*
             *	Error, the token couldn't be parsed.
             */
            mea_opts_free_list(modId, opts);
            
            return NULL;
        }
        if (last_token == 0)
        {
            opts->tokenList = token;
        }
        else
        {
            last_token->next = token;
        }
        last_token = token;
        str = skip_white_space(str);
    }
    
    return opts;    
}


/*
 *	Free entire token list structure.
 *  \param   list, structure to free.
 *  \param   modId, Where to memory was allocated.
 */
void mea_opts_free_tokens(MSF_UINT8 modId, mea_opts_token *list)
{
    mea_opts_token *next = list;

    while (list != NULL)
    {
        next = list->next;
        MSF_MEM_FREE(modId, list);

        list = next;
    }
}

/*
 *	Free entire opts list structure.
 *  \param   list, structure to free.
 *  \param   modId, Where to memory was allocated.
 */
void mea_opts_free_list(MSF_UINT8 modId, mea_opts_list *list)
{
    if (list == NULL)
    {
        return ;
    }

    mea_opts_free_tokens(modId, list->tokenList);
    if (list->line != NULL)
    {
        MSF_MEM_FREE(modId, list->line);
    }

    MSF_MEM_FREE(modId, list);    
    /* Hmm, maybe should dealloc string also!? */
}

/*
 *	Find parameter
 *  \param   command, the sting command (-command).
 *  \return  pointer to param.
 */
mea_opts_token *mea_opts_find_option(const mea_opts_list *p, const char *option)
{
    mea_opts_token *token = NULL;

    if (p == NULL || p->tokenList == NULL || option == NULL)
    {
        return NULL;
    }

    token = p->tokenList;
    while (token != NULL)
    {
        if (token->isOption == TRUE)
        {
            if (token->start != NULL && (strlen(option) == token->length) && 
                strncmp(option, token->start, token->length) == 0)
            {
                return token;
            }

        }
        token = token->next;
    }

    return NULL;    
}

/*
 * Get next command argument, this is called after mea_opts_find_cmd to
 * get a pointer to the first command argument, and the the next etc.
 * When the last argument was found this function returns NULL.
 *  \param   p, pointer to token list.
 *  \return  pointer to command argument, returns null if not available.
 */
mea_opts_token *mea_opts_get_next_arg(const mea_opts_token *p)
{
    if (p == NULL)
    {
        return NULL;    
    }

    return p->next;
}

/*
 *	Get command argument unsigned number value.
 *  \param   p,  pointer to command argument.
 *  \param   ip, integer to store value into (result).
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_get_uint32(const mea_opts_token *p, MSF_UINT32 *ip)
{
    if (p == NULL || p->start == NULL)
    {
        return FALSE;
    }
    
    sscanf(p->start, "%d", ip);
    return TRUE;    
}

/*
 *	Get command argument signed number value.
 *  \param   p, pointer to command argument.
 *  \param   ip, integer to store value into (result).
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_get_int32(const mea_opts_token *p, MSF_INT32 *ip)
{
    MSF_INT32 i = 0;
    MSF_BOOL  res = FALSE;

    if (p == NULL || p->start == NULL)
    {
        return FALSE;
    }

    res = (sscanf(p->start, "%d", &i) == 1);
    (*ip) = i;

    return res;
}

/*
 *	Get command argument string value.
 *  \param   p, pointer to command argument.
 *  \param   modId, Where to allocate memory.
 *  \param   str, string to store value into (result). Caller deallocates.
 *  \return  TRUE if successful.
 */
MSF_BOOL mea_opts_get_str(MSF_UINT8 modId, const mea_opts_token *p, char **str)
{
    if (p == NULL || p->start == NULL)
    {
        return FALSE;
    }

    (*str) = (char*) MSF_MEM_ALLOC(modId, p->length+1);
    if ((*str) == NULL)
    {
        return FALSE;
    }
    memset((void*) (*str), 0, p->length+1);
    memcpy((void*) (*str), p->start, p->length);

    return TRUE;    
}

/*
 *	Helper function.
 */
static unsigned char mea_opts_get_hex(char c)
{
    if (c >= '0' && c <= '9')
    {
        return (unsigned char) (c - '0');
    }
    if (c >= 'a' && c <= 'f')
    {
        return (unsigned char) (c - 'a'+ 10);
    }
    if (c >= 'A' && c <= 'F')
    {
        return (unsigned char) (c - 'A' + 10);
    }
    return 0;
}
/*
 *	Get command argument binary value.
 *  \param   p, pointer to command argument.
 *  \param   modId, Where to allocate memory.
 *  \param   dp, pointer to allocated binary data (result).
 *  \param   size,  size of allocated binary data (result).
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_get_data(MSF_UINT8 modId, const mea_opts_token *p, void **dp,
    MSF_UINT32 *size)
{
    unsigned char *data = 0;
    char *str = 0;
    MSF_UINT32 i;


    if (dp == NULL || p == NULL)
    {
        return FALSE;
    }
    (*dp) = NULL;
    (*size) = 0;
    
    data = (unsigned char*) MSF_MEM_ALLOC(modId, p->length/2);
    if (data == NULL)
    {
        return FALSE;
    }

    str = p->start;

    for(i=0; i<(p->length/2); i++)
    {
        data[i] = (unsigned char) ((mea_opts_get_hex(str[0]) << 4) + mea_opts_get_hex(str[1]));
        str += 2;
        (*size)++;
    }

    (*dp) = data;

    return TRUE;    
}


/*
 *	The first function to call when to create a command line.
 *  \param   modId, Where to allocate memory.
 *  \paramm  maxLen, Maximum length of command line string to create.
 *  \return  structure with parsed data.
 */
mea_opts_list *mea_opts_create_list(MSF_UINT8 modId, MSF_UINT32 maxLen)
{
    mea_opts_list *list = NULL;
    
    list = (mea_opts_list*) MSF_MEM_ALLOC(modId, sizeof(mea_opts_list));
    memset(list, 0, sizeof(mea_opts_list));
    if (list == NULL)
    {
        return NULL;
    }

    list->line = (char*) MSF_MEM_ALLOC(modId, maxLen);
    if (list->line == NULL)
    {
        MSF_MEM_FREE(modId, list);

        return NULL;
    }
    memset(list->line, 0, maxLen);

    list->lineLength = 0;
    list->maxLength = maxLen;
    list->tokenList = NULL;
    
    return list;
}

/*
 *	Add token last in list.
 */
mea_opts_token *mea_opts_add_token(MSF_UINT8 modId, mea_opts_list *p)
{
    mea_opts_token *token = NULL;
    mea_opts_token *prev = NULL;
    
    if (p == NULL)
    {
        return NULL;
    }

    token = (mea_opts_token*) MSF_MEM_ALLOC(modId, sizeof(mea_opts_token));

    if (token == NULL)
    {
        /*
         *	Out of memory error.
         */
        return FALSE;
    }

    memset( token, 0, sizeof(mea_opts_token));

    token->isOption = FALSE;
    token->length = 0;
    token->next = 0;
    token->numberOfChars = 0;
    token->start = 0;

    if (p->tokenList == NULL)
    {
        p->tokenList = token;
    }
    else
    {
        prev = p->tokenList;
        while(prev->next != NULL)
        {
            prev = prev->next;
        }

        prev->next = token;

        *(p->line+p->lineLength) = ' ';
        p->lineLength++;
    }
    
    return token;
}

/*
 *	Add parameter string.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   param, parameter name string.
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_option(MSF_UINT8 modId, mea_opts_list *p, 
    const char *option)
{
    char            *strp = 0;
    mea_opts_token  *token = 0;
    
    if (p == NULL || (p->lineLength + strlen(option)+2) > p->maxLength)
    {
        return FALSE;        
    }
    
    token = mea_opts_add_token(modId, p);
    if (token == NULL)
    {
        return FALSE;
    }
    
    strp = p->line+p->lineLength;
    
    (*strp) = '-';
    strp++;
    token->start = strp;
    
    memcpy(token->start, option, strlen(option));
    strp += strlen(option);
    
    token->length = strp-token->start;
    token->numberOfChars = token->length;
    token->isOption = TRUE;
    
    (*strp) = 0;
    
    p->lineLength = strp-p->line;
    
    return TRUE;
}

/*
 *	Set command argument unsigned number value.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   i, integer to add as argument
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_uint32(MSF_UINT8 modId, mea_opts_list *p, MSF_UINT32 i)
{
    char            *strp = 0;
    mea_opts_token  *token = 0;
    
    if (p == NULL || (p->lineLength + 7+3) > p->maxLength)
    {
        return FALSE;        
    }
    
    token = mea_opts_add_token(modId, p);
    if (token == NULL)
    {
        return FALSE;
    }
    
    strp = p->line+p->lineLength;
    
    token->start = strp;
    
    sprintf(strp, "%lu", i);
    
    strp += strlen(strp);
    
    token->length = strp-token->start;
    token->numberOfChars = token->length;
    
    (*strp) = 0;
    
    p->lineLength = strp-p->line;
    
    return TRUE;
}


/*
 *	Add command argument signed number value.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   i, integer to add as argument
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_int32(MSF_UINT8 modId, mea_opts_list *p, MSF_INT32 i)
{
    char            *strp = 0;
    mea_opts_token  *token = 0;
    
    if (p == NULL || (p->lineLength + 7+3) > p->maxLength)
    {
        return FALSE;        
    }
    
    token = mea_opts_add_token(modId, p);
    if (token == NULL)
    {
        return FALSE;
    }
    
    
    strp = p->line+p->lineLength;
    (*strp) = '"';
    strp++;
    
    token->start = strp;

    sprintf(strp, "%lu", i);
    
    strp += strlen(strp);
        
    token->length = strp-token->start;
    token->numberOfChars = token->length;
        

    (*strp) = '"';
    strp++;
    (*strp) = 0;
    
    p->lineLength = strp-p->line;
    
    return TRUE;
}

/*
 *	Add command argument string value.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   str, integer to get value from.
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_str(MSF_UINT8 modId, mea_opts_list *p, const char *str)
{
    char            *strp = 0;
    mea_opts_token  *token = 0;
    
    if (p == NULL || (p->lineLength + strlen(str)+3) > p->maxLength)
    {
        return FALSE;        
    }
    
    token = mea_opts_add_token(modId, p);
    if (token == NULL)
    {
        return FALSE;
    }
    
    strp = p->line+p->lineLength;
    
    (*strp) = '"';
    strp++;
    token->start = strp;
    
    memcpy(token->start, str, strlen(str));
    strp += strlen(str);

    token->length = strp-token->start;
    token->numberOfChars = token->length;
    
    (*strp) = '"';
    strp++;

    (*strp) = 0;
    
    p->lineLength = strp-p->line;
    
    return TRUE;
}

/*
 *	Add command argument string value.
 *  \param   modId, Where to allocate memory.
 *  \param   p,  pointer to command list.
 *  \param   dp, pointer to binary data.
 *  \param   size,  size of binary data.
 *  \return  True if successful.
 */
MSF_BOOL mea_opts_add_data(MSF_UINT8 modId, mea_opts_list *p, void *dp, MSF_UINT32 size)
{
    char            *data = (char*) dp;
    char            *str = 0;
    const char      val[17] = "0123456789ABCDEF";
    MSF_UINT32      i;
    mea_opts_token  *token = 0;

    if (p == NULL || (p->lineLength + size*2+1) > p->maxLength)
    {
        return FALSE;        
    }

    token = mea_opts_add_token(modId, p);
    if (token == NULL)
    {
        return FALSE;
    }

    str = p->line+p->lineLength;

    token->start = str;

    for(i=0; i<size; i++)
    {
        (*str) = val[(data[i]>>4)&15];
        str++;
        (*str) = val[data[i]&15];
        str++;
    }
    (*str) = 0;

    token->length = token->start-str;
    token->numberOfChars = token->length;

    p->lineLength = str-p->line;
    
    return TRUE;
}

/*
 *	Get command line string
 *  \param   p,  pointer to command list.
 *  \param   line_len, length of command line.
 *  \return  Command line string.
 */
const char *mea_opts_get_line(const mea_opts_list *p, MSF_UINT32 *line_len)
{
    if (p == NULL)
    {
        (*line_len) = 0;
        return NULL;
    }

    (*line_len) = p->lineLength;
    
    return p->line;
}


