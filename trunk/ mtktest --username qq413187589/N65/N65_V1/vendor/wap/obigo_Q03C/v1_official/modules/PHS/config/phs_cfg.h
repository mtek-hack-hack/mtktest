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
 * phs_cfg.h
 *
 * Created by Kent Olsson, Thu Sep 11 15:51:11 2002.
 *
 * Revision history:
 *
 */
#ifndef _phs_cfg_h
#define _phs_cfg_h

/* PHS_CONFIG_WAP_PUSH_MESSAGES Requires the UIS module
 * If not supported PHS will ignore the following message types
 * - SIA
 * - SL
 * - SI
 * - CO
 */
#define PHS_CONFIG_WAP_PUSH_MESSAGES  

#define PHS_CONFIG_WSP_PUSH
#ifdef WAP_SEC_SUPPORT
#define PHS_CONFIG_HTTP_PUSH
#endif
#define PHS_CONFIG_MULTIPART

/**************************************************
 * Parser configuration settings
 **************************************************/

#define PHS_CFG_MAX_CONCURRENT_PARSINGS 10

/* The initial buffer size used for the parser. */
#define PHS_PRSR_BUF_SIZE 500

/* The default character set used when parsing a text document
 * with no encoding information. Must be ASCII based.
 * PHS_CFG_DEFAULT_CHARSET can only take the value MSF_CHARSET_UTF_8
 * or MSF_CHARSET_LATIN_1. */
#define PHS_CFG_DEFAULT_CHARSET   MSF_CHARSET_UTF_8

/**************************************************
 * Connections configuration settings
 **************************************************/

/* Max number of open connections per active Object */
#define PHS_CFG_MAX_CONNECTIONS_PER_USER          5

#define PHS_CFG_MAX_CONNECTIONS                   20

#define PHS_CFG_UDP_DEFAULT_PUSH_PORT             2948
#define PHS_CFG_WTLS_DEFAULT_PUSH_PORT            2949
#define PHS_CFG_HTTP_DEFAULT_PUSH_PORT            4035

/**************************************************
 * Other settings
 **************************************************/
/* 
 * PHS_CFG_SIR_LOCKOUT_TIMER is used for handling a lockout timer for SIR. 
 * The lockut timer is used to protect against denial of service 
 * attacks. The timer is turned om when a SIR arrives and can be handled
 * sucessfully. All other SIR that arrives when the timer is set will 
 * be discarded. The timer is turned of and SIR can be handled again
 * after one of the following cases:
 * - When the connection has been established 
 * - If the user answers the dialog followed after an SIR with cancel 
 *   (then the connection will never be established)
 * - If the timer expires.
 *
 * PHS_CFG_SIR_LOCKOUT_TIMER defines how long the 
 * lockout timer should be on. The value should be given
 * in 1/10ths of a second
 *
 * If this behavior is not requried set the value to 0,
 * and no lockout tmer will be used
 */
#define PHS_CFG_SIR_LOCKOUT_TIMER                 100

#endif


