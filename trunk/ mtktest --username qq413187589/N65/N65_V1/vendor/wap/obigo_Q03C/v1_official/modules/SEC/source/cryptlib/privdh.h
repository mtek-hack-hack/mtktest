/* 
 * privdh.h
 * Summary: Internal Diffie-Hellman functions
 *
 * Author: William Whyte
 *
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 */

#ifndef _PRIVDH_H
#define _PRIVDH_H

#include "cstopt.h"    /* for WITH_dh */

#ifdef WITH_dh_dh

#include "ut.h"
#include "prng.h"
#include "mpm.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Get the amount of memory that a BER-encoded set of Diffie-Hellman
 * removed!
 */ 

extern size_t 
CST32EXPORTTYPE CST16EXPORTTYPE
dh_sizeof_parameters2berstring_pkcs3(mpm_arc, mpm_arc, u32);

/* Convert a set of Diffie-Hellman parameters to a BER-encoded string
 * removed!
 * removed!
 */

extern u8 
CST32EXPORTTYPE * CST16EXPORTTYPE
dh_parameters2berstring_pkcs3(mpm_arc, mpm_arc, u32, u8 *);

/* Convert a BER-encoded set of Diffie-Hellman parameters to a
 * removed!
 * removed!
 */

extern u8 
CST32EXPORTTYPE * CST16EXPORTTYPE
dh_berstring2parameters_pkcs3(u8 *, mpm_arc *, mpm_arc *, u32 *);

/* Get the amount of memory that a BER-encoded Diffie-Hellman key
 * removed!
 */

extern size_t 
CST32EXPORTTYPE CST16EXPORTTYPE
dh_sizeof_key2berstring_pkcs3(mpm_arc);

/* Convert a Diffie-Hellman key (public, private or shared; it doesn't
 * removed!
 * removed!
 */

extern u8 
CST32EXPORTTYPE * CST16EXPORTTYPE
dh_key2berstring_pkcs3(mpm_arc, u8 *);

/* Convert a BER-encoded string to a Diffie-Hellman key. Returns a pointer
 * removed!
 */

extern u8 
CST32EXPORTTYPE * CST16EXPORTTYPE
dh_berstring2key_pkcs3(u8 *, mpm_arc *);



/* Function:    <dh_sizeof_parameters2berstring_x942>
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 */
size_t 
CST32EXPORTTYPE CST16EXPORTTYPE
dh_sizeof_parameters2berstring_x942(mpm_arc p, mpm_arc q, mpm_arc g,
    mpm_arc j);

/* Function:    <dh_parameters2berstring_x942>
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 */
u8 * 
CST32EXPORTTYPE CST16EXPORTTYPE
dh_parameters2berstring_x942(mpm_arc p, mpm_arc q, mpm_arc g, mpm_arc j,
    u8 *dest);

/* Function:    <dh_berstring2parameters_x942>
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 */
u8 *
CST32EXPORTTYPE CST16EXPORTTYPE
dh_berstring2parameters_x942(u8 *src, mpm_arc *p, mpm_arc *q, mpm_arc *g,
  mpm_arc *j);


/*
 * removed!
 */

/* Merge priv and params together into dest. The memory at dest is
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 */

extern int
dh_merge_priv_and_params(ut_mblk *priv, ut_mblk *params, ut_mblk *dest);



/* Extract from src into priv and params. Both priv and params are 
 * removed!
 * removed!
 *
 * removed!
 */

extern int
dh_separate_priv_and_params(ut_mblk *src, ut_mblk *priv, ut_mblk *params);



#ifdef __cplusplus
}
#endif 


#endif  /* def WITH_dh_dh  */

#endif  /* ndef _PRIVDH_H */
