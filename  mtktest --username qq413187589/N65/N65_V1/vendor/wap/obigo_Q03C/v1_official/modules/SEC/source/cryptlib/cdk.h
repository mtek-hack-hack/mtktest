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

#ifdef CST_NO_RSA

#ifndef _CST_NO_RSA_H
#define _CST_NO_RSA_H

typedef const char *in;
typedef char *out;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32

typedef int (__stdcall *LPFNCDKVERSION)(void);
typedef int (__stdcall *LPFNRSAKEYGEN)(in,in,int,out,out,out,out,out,out,out);
typedef int (__stdcall *LPFNRSAENCRYPT)(in,in,in,out);
typedef int (__stdcall *LPFNRSADECRYPT)(in,in,in,in,in,out);

LPFNCDKVERSION lpfnCDKversion;
LPFNRSAKEYGEN lpfnRSAkeygen;
LPFNRSAENCRYPT lpfnRSAencrypt;
LPFNRSADECRYPT lpfnRSAdecrypt;

#define CDKversion lpfnCDKversion
#define CDK_RSAkeygen lpfnRSAkeygen
#define CDK_RSAencrypt lpfnRSAencrypt
#define CDK_RSAdecrypt lpfnRSAdecrypt

#else /* def/ndef WIN32 */

int CDKversion(void);
int CDK_RSAkeygen(in seed, in e, int size, out n, out d,
    out p, out q, out dmodpredp, out dmodpredq, out qinvmodp);
int CDK_RSAencrypt(in m, in e, in n, out c);
int CDK_RSAdecrypt(in c, in e, in n, in p, in d, out m);

#endif /* def/ndef WIN32 */

#ifdef __cplusplus
}
#endif

#define MinDSinst	3500

#endif  /* ndef _CST_NO_RSA_H */

#endif /* def CST_NO_RSA */
