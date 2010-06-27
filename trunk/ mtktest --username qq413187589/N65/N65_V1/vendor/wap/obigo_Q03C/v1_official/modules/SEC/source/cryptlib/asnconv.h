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

#ifndef _ASNCONV_H
#define _ASNCONV_H

#ifdef __cplusplus
extern "C" {
#endif

#define ut_sizeof_size2berlen(a) asn1_sizeof_size2berlen((a))
#define ut_size2berlen(a,b) asn1_size2berlen((a),(b))
#define ut_size2paddedberlen(a,b,c) asn1_size2paddedberlen((a),(b),(c))
#define ut_berlen2size(a,b) asn1_berlen2size((a),(b))
#define ut_sizeof_mblk2beroctetstring(a) asn1_sizeof_mblk2beroctetstring((a))
#define ut_mblk2beroctetstring(a,b) asn1_mblk2beroctetstring((a),(b))
#define ut_beroctetstring2mblk(a,b) asn1_beroctetstring2mblk((a),(b))
#define ut_cmp_beroctetstring(a,b) asn1_cmp_beroctetstring((a),(b))
#define ut_sizeof_s322berinteger(a) asn1_sizeof_s322berinteger((a))
#define ut_s322berinteger(a,b) asn1_s322berinteger((a),(b))
#define ut_berinteger2s32(a,b) asn1_berinteger2s32((a),(b))
#define ut_sizeof_mblk2berbit string(a) asn1_sizeof_mblk2berbit string((a))
#define ut_mblk2berbit string(a,b) asn1_mblk2berbit string((a),(b))
#define ut_berbit string2mblk(a,b) asn1_berbit string2mblk((a),(b))

#ifdef __cplusplus
}
#endif

#endif /* ndef _ASNCONV_H */
