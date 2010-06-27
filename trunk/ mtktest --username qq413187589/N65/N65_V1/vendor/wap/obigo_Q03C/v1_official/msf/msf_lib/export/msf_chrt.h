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
 * msf_chrt.h
 *
 * Created by Anders Edenbrandt, Fri Mar 23 15:10:13 2001.
 *
 *
 * Character type classification with fast lookup functions,
 * similar to ANSI-C ctype.h.
 *
 *
 * Revision history:
 *   011001  NKE  Added isxmlwhitespace and changed to unsigned.
 *   011123  NKE  Added formfeed to ct_iswhitespace
 *
 *
 */
#ifndef _msf_chrt_h
#define _msf_chrt_h

#include "msf_def.h"

extern unsigned const short int msf_chrtype[256];

#define _UC    0x1u            /* Lower case: a-z */
#define _LC    0x2u            /* Upper case: A-Z */
#define _D     0x4u            /* Digit: 0-9 */
#define _X     0x8u            /* Hex digit: a-f, A-F */
#define _M     0x10u           /* Mark: -_.!~*'() */
#define _SRES  0x20u           /* Sometimes reserved: :@&=+$, */
#define _ARES  0x40u           /* Always reserved: ;/? */
#define _DL    0x80u           /* Delimiters: <>#%" */
#define _UW    0x100u          /* Unwise: {}|\^[]` */
#define _WS    0x200u          /* Whitespace: HT, VT, CR, LF, SP, FF */
#define _SP    0x400u          /* Space: ' ' */
#define _B     0x800u          /* Blank: SP TAB */
#define _C     0x1000u         /* Ctlr character: 0x0-0x1f, 0xff */
#define _T     0x2000u         /* Tspecials: ()<>@,;:\"/[]?={}SPHT */
#define _ESC   0x4000u         /* Escape character: % */
#define _XWS   0x8000u         /* XML whitespace character: HT, CR, LF, SP */

#define ct_isascii(c)         ((unsigned char)(c) < 0x80)
#define ct_isalpha(c)         (msf_chrtype[(unsigned char)(c)] & (_UC | _LC))
#define ct_isalphanum(c)      (msf_chrtype[(unsigned char)(c)] & (_UC | _LC | _D))
#define ct_islower(c)         (msf_chrtype[(unsigned char)(c)] & _LC)
#define ct_isupper(c)         (msf_chrtype[(unsigned char)(c)] & _UC)
#define ct_isdigit(c)         (msf_chrtype[(unsigned char)(c)] & _D)
#define ct_ishex(c)           (msf_chrtype[(unsigned char)(c)] & (_D | _X))
#define ct_ishexletter(c)     (msf_chrtype[(unsigned char)(c)] & _X)
#define ct_isblank(c)         (msf_chrtype[(unsigned char)(c)] & (_B))
#define ct_iswhitespace(c)    (msf_chrtype[(unsigned char)(c)] & _WS)
#define ct_isxmlwhitespace(c) (msf_chrtype[(unsigned char)(c)] & _XWS)
#define ct_isctrl(c)          (msf_chrtype[(unsigned char)(c)] & _C)

#define ct_isescape(c)        (msf_chrtype[(unsigned char)(c)] & _ESC)
#define ct_isreserved(c)      (msf_chrtype[(unsigned char)(c)] & (_SRES | _ARES))
#define ct_isexcluded(c)      (msf_chrtype[(unsigned char)(c)] & (_C | _SP | _DL))
#define ct_isdelimiter(c)     (msf_chrtype[(unsigned char)(c)] & _DL)
#define ct_isunwise(c)        (msf_chrtype[(unsigned char)(c)] & _UW)
#define ct_istspecial(c)      (msf_chrtype[(unsigned char)(c)] & _T)
#define ct_isspecial(c)       (msf_chrtype[(unsigned char)(c)] & (_C | _SP | _SRES | _ARES | _UW | _DL))
#define ct_ispchar(c)         (msf_chrtype[(unsigned char)(c)] & (_UC | _LC | _D | _M | _SRES))
#ifdef MTK_TMP_PATCH /* TR17965 */
#define ct_isuric(c)          (msf_chrtype[(unsigned char)(c)] & (_SRES | _ARES | _UC | _LC | _D | _M | _UW))
#else
#define ct_isuric(c)          (msf_chrtype[(unsigned char)(c)] & (_SRES | _ARES | _UC | _LC | _D | _M))
#endif

#endif

