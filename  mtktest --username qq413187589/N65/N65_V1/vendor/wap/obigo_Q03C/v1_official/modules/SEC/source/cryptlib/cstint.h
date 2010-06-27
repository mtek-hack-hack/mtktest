/* cstint.h -- functions are declared here so they will be visible
 * between CST functions without being visible outside the CST. This may
 * have to be split up in the future.
 */

#ifndef _CSTINT_H
#define _CSTINT_H

#include "ut.h"
#include "bsapi.h"
#include "prng.h"

#ifdef __cplusplus
extern "C" {
#endif /* def __cplusplus */

void
sha_compress(u32 *digest, u32 *message);

extern int
_ut_provides_RSA;

extern int
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_sharedparams_vb60_des(prng_inst *prng, ut_mblk *shrdpt,
    bsapi_kparam *param);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_key_vb60_des(prng_inst *prng, ut_mblk *secpt,
    ut_mblk *pubpt, bsapi_kparam *param);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_generate_privatenonce_vb60_des (prng_inst *rand_gen, ut_mblk *pnonce, 
    bsapi_kparam *param);
extern size_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_iv_vb60_des(bsapi_mode *mode, bsapi_kset *keys);
extern bsapi_id 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_start_vb60_des(bsapi_mode *mode, prng_inst *prngpt,
    bsapi_kset *keys);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_append_vb60_des(u8 *data, size_t length, bsapi_id session);
extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_read_vb60_des(bsapi_id session);
extern ut_mblk_list 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_readmost_vb60_des(bsapi_id session);
extern int 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_finish_vb60_des(bsapi_id session, ut_mblk_list *data);
extern sec_off_t 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_sizeof_output_vb60_des(bsapi_id session, sec_off_t input);
extern void 
  CST32EXPORTTYPE CST16EXPORTTYPE
    bsapi_kill_vb60_des(bsapi_id session);
extern const char CST32EXPORTTYPE * CST16EXPORTTYPE
    bsapi_get_name_vb60_des(void);
void CST32EXPORTTYPE CST16EXPORTTYPE
    vb60_des_direct(bsapi_id session, u8 *in, u8 *out, size_t len);
extern const bsapi_alg CST32EXPORTDATA CST16EXPORTDATA bsapi_vb60_des;


/* Function:  <compat_normalise>
 * Syntax:    result = compat_normalise(in);
 * Semantics: Compatibility normalize the NUL-terminated Unicode string
 *   'in'. This may (in fact probably will) produce a string that is
 *   slightly longer than the original. In addition, because
 *   compatibility
 *   decomposition maps multiple distinct characters to the same
 *   sequence
 *   of charaters (e.g. ligatures) and canonical ordering maps different
 *   orderings of accents to the same order, the entropy of the
 *   resulting
 *   string will be slightly lower than the entropy of the original
 *   string.
 * Failure:   
 * Errors:    
 */
extern u16 *compat_normalise(u16 *in);
extern u16 *inner_compat_normalise(u16 *in, size_t len);
 
  




#ifdef __cplusplus
}       /* Balance extern "C" above */
#endif

#endif /* ndef _PRIVCAPI_H  */
