/* sb_ecdh.h   $Date: 1999/08/11 11:16:02 $ $Author: nosullivan $
 * 
 *
 * Summary: BSAPI API to Certicom Security Builder ECC: ECDH.
 */

#ifndef __SB_ECDH_H
#define __SB_ECDH_H

#include "sbeccom.h"

/* SB EC DH */
#ifdef __cplusplus
extern "C" {
#endif

extern int CST32EXPORTTYPE CST16EXPORTTYPE
sb_ecdh_generate_key
(prng_inst *prng, ut_mblk *pript, ut_mblk *pubpt, bsapi_kparam *param);

extern int CST32EXPORTTYPE CST16EXPORTTYPE
sb_ecdh_derive_shared
(bsapi_kparam *params, ut_mblk *pubpt, ut_mblk *pript, ut_mblk *shrpt);

extern int CST32EXPORTTYPE CST16EXPORTTYPE
sb_ecdh_generate_sharedparams
(prng_inst *prng, ut_mblk *shrdpt, bsapi_kparam *param);

extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_sb_ecdh;

#ifdef __cplusplus
}
#endif

#endif /* __SB_ECDH_H */
