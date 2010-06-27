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

#ifndef __SB_ECCOM_H
#define __SB_ECCOM_H

#include "ut.h"

/* SB EC DSA */
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  SB_EC113A01, /* 00 */
  SB_EC131A01, /* 01 */
  SB_EC163A01, /* 02 */
  SB_EC163A02, /* 03 */
  SB_EC239A01, /* 04 */
  SB_EC239A02, /* 05 */
  SB_EC239A03, /* 06 */
  SB_EC131B01, /* 07 */
  SB_EC155B01, /* 08 */ /* decommissioned */
  SB_EC163B01, /* 09 */
  SB_EC163B02, /* 10 */
  SB_EC191B01, /* 11 */
  SB_EC210B01, /* 12 */ /* decommissioned */
  SB_EC239B01, /* 13 */
  SB_EC160P01, /* 14 */
  SB_EC192P01  /* 15 */
} SB_EllipticCurveID;
    
#define SB_EC_LOW SB_EC113A01
#define SB_EC_MEDIUM SB_EC163A02
#define SB_EC_HIGH SB_EC239A03

#define BSAPI_SB_SMALL BSAPI_ANSI
#define BSAPI_SB_FAST BSAPI_FAST

/* point compression flag; defined in a different order than within
 * SecurityBuilder because we want point compression to be ON by
 * default.
 */

typedef enum {
  SB_CFLAG_ON = 0,
  SB_CFLAG_HYBRID,
  SB_CFLAG_OFF
} sb_pcFlag;


typedef struct {
  enum {
    ECFieldID_primeP,
    ECFieldID_characteristicTwo
  } fieldID;
  
  union {
    struct {
      ut_mblk prime;
    } primeP;
    
    struct {
      u16 m;
      
      enum {
        ECBasisType_onb,
        ECBasisType_trinomial,
        ECBasisType_pentanomial
      } basisType;
      
      union {
        struct {
          char pad;
        } onb;

        struct {
          ut_mblk k;
        } trinomial;

        struct {
          ut_mblk k1;
          ut_mblk k2;
          ut_mblk k3;
        } pentanomial;
      } basisData;
    } characteristicTwo;
  } fieldData;

  struct {
    ut_mblk a;
    ut_mblk b;
    ut_mblk seed;
  } curve;

  ut_mblk base; /* Doesn't include point compression flag */

  ut_mblk order;

  ut_mblk cofactor;
} SB_EllipticCurve;

/* Function:    <sb_enum2comm>
 * Summary:     Convert SB_EC_LOW, MEDIUM or HIGH to a set of curve
 *              params.
 * Syntax:      int rval = sb_enum2comm(int cur, ut_mblk **comm);
 * Description: The sb_enum2comm() function reads cur (which has one of
 *              the values SB_EC_LOW, SB_EC_MEDIUM, SB_EC_HIGH) and 
 *              fills in comm with the parameters corresponding to that
 *              curve.
 * Returns:     This function returns 0 on success or -1 on failure
 *              (unable to allocate memory, or illegitimate curve
 *              identifier). In debug mode, returns -2 if passed a null
 *              comm parameter.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_mblk *comm;
 *              sb_enum2comm(SB_EC_MEDIUM, &comm);
 *              ...
 *              ut_dispose_mblk_f(comm);
 *           (/code)
 */
int
sb_enum2comm(int curve, ut_mblk **comm);
  
int
sb_enum2sharedparams(int curve, ut_mblk *param);

/* Convert EC param to SB_EllipticCurveID */
int
sb_sharedparams2enum(void *par);

int
sb_get_sharedparams_strength (void *par);

/* Convert EC param to SB_EllipticCurve */
int
sb_sharedparams2curve(void *par, SB_EllipticCurve *dst);

/* ASN.1 Object Identifiers */

extern u32 oid_ANSI_X9_62[];
extern u32 oid_ANSI_X9_62_FieldType[];
extern u32 oid_ANSI_X9_62_FieldType_Prime[];
extern u32 oid_ANSI_X9_62_FieldType_2m[];
extern u32 oid_ANSI_X9_62_FieldType_2m_Basis[];
extern u32 oid_ANSI_X9_62_FieldType_2m_Basis_ON[];
extern u32 oid_ANSI_X9_62_FieldType_2m_Basis_TP[];
extern u32 oid_ANSI_X9_62_FieldType_2m_Basis_PP[];

#ifdef __cplusplus
}
#endif

#endif /* __SB_ECCOM_H */
