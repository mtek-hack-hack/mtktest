/* `bsapi/block.h' $Revision: 1.11 $ $Date: 1999/02/23 18:24:36 $
 */


#ifndef _BLOCK_H /* prevent multiple inclusion */
#define _BLOCK_H

/*loko#include "string.h"  For memcpy() & memset() */

#include "bsapi.h"  /* For BSAPI_ENOMEM, BSAPI_EXTRAC, BSAPI_EPADFA, bsapi_cfb,
    bsapi_mode, bsapi_encrypt, bsapi_decrypt, bsapi_ecb, bsapi_cbc, bsapi_cbc3,
    bsapi_key, bsapi_sched, bsapi_ansi, & bsapi_id */
#include "ut.h"     /* For u8, u32, ut_mblk_list, ut_new_mem(), ut_new_mblk(),
    ut_dispose_mblk(), UT_AABORT, UT_ACONTINUE, ut_log(), & ut_dispose_mem() */
#include "prng.h"   /* For prng_inst */
#include "pad.h"    /* For pad_alg */

#define BLOCKSIZE (8)
#define MINBSZ (1024)

typedef struct block_mach_s *block_mach;

typedef void (*blockfn)(block_mach m, size_t len, u8 *in, u8 *out);
typedef void (*dcfn)(u32 *data, void *ks[]);

#ifdef CST_WITH_BSAFE_BLOCK_CIPHER

#include "bsafecst.h"

typedef struct bsafe_session_info_s {
  B_ALGORITHM_OBJ   *aInfo;
} bsafe_session_info;

void bsafe_corefn(u32 *data, void *ks[]);

#endif /* def CST_USE_ONLY_BSAFE */

struct block_mach_s {
  void * ks[3];
  union {
    u8           d8[BLOCKSIZE];
    u32          d32[BLOCKSIZE / 4];
  }              pending[3];
  u32            iv[3][BLOCKSIZE / 4];
  blockfn        fn;
  dcfn           corefn;
  bsapi_mode_op  op;
  const pad_alg *pad;
  pad_params     ppar;
  unsigned       chain;
  unsigned       fbits;
  size_t         npend;
  ut_mblk_list   buf;
};


void
block3(dcfn core, u32 *data, void *ks[]);

void
block_ecb(block_mach m, size_t len, u8 *in, u8 *out);

void
block_cbc(block_mach m, size_t _len, u8 *in, u8 *out);

void
block_cfb(block_mach m, size_t _len, u8 *in, u8 *out);

void
block_ofb(block_mach m, size_t _len, u8 *in, u8 *out);

int
bsapi_generate_key_block(prng_inst *prng, ut_mblk *secpt, ut_mblk *pubpt,
                             size_t size);

int
bsapi_generate_sharedparams_block(prng_inst *prng, ut_mblk *shrdpt,
                             bsapi_kparam *param);
int 		
bsapi_generate_privatenonce_block (prng_inst *rand_gen, ut_mblk *kpt,
bsapi_kparam *param);

size_t
bsapi_sizeof_iv_block(bsapi_mode *mode, bsapi_kset *keys);

sec_off_t
bsapi_sizeof_output_block(bsapi_id session, sec_off_t input);

int
bsapi_append_block(u8 *data, size_t length, bsapi_id session);

ut_mblk_list
bsapi_read_block(bsapi_id session);

size_t
bsapi_sizeof_readmost_block(size_t input, bsapi_id session);

ut_mblk_list
bsapi_readmost_block(bsapi_id session);

void
bsapi_kill_block(bsapi_id session);

int
bsapi_finish_block(bsapi_id session, ut_mblk_list *data);

void
block_direct(bsapi_id session, u8 *in, u8 *out, size_t len);


#endif   /* ndef _BLOCK_H */
