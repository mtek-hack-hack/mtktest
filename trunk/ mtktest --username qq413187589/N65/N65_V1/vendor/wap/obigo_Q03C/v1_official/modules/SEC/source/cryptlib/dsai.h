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

#ifndef _DSA_H
#define _DSA_H

#include "mpm.h"
#include "utmpm.h"
#include "ut.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Return Values */

#define DSA_GOOD 0	/* Function worked OK, and fucntioned */
#define DSA_FAIL -1	/* Function failed to function ( out of mem etc ) */
#define DSA_BAD 1	/* Function didn`t work, but functioned normally */
#define DSA_FLOP 2	/* Function failed to complete, funny parameters */

/*  * Component : err_dsa
 * Purpose : Error handling within the DSA module.
 */

#define DSA_EBASE  (0x0d000000)  /* Module Code */

#define DSA_EPARAM (DSA_EBASE + 0x00100) /* FAIL/ABORT Bad Function parameters */
#define DSA_ENTRNL (DSA_EBASE + 0x00200) /* FAIL/IGNORE Internal function failure */
#define DSA_EUNEXP (DSA_EBASE + 0x00300) /* INPUT/PRINT Wrong Type */
#define DSA_ENFBIT (DSA_EBASE + 0x00400) /* INPUT/PRINT Bitstring with nonfull last byte */
#define DSA_EXTRAD (DSA_EBASE + 0x00500) /* INPUT/PRINT Unexpected trailing data in key */
#define DSA_EMPMF  (DSA_EBASE + 0x00600) /* MPM failed */
#define DSA_ENOMEM (DSA_EBASE + 0x00700) /* out of memory */
#define DSA_EBSAFE  (DSA_EBASE + 0x00800) /* BSafe error */

/* Module Error ID */

extern void *dsa_errid;

/*  * Function:  <dsa_init>
 * Syntax: success = dsa_init();
 * Semantics: Submits rsa error block. Returns 0 on sucessful setup.
 */
extern int dsa_init(void);

/*  * Operation <dsa_shutdown>
 * Syntax: dsa_shutdown(cancel);
 * Semantics: If cancel is TRUE then we cancel then we remove the
 *	dsa error block from erc.
 */
extern void dsa_shutdown(int cancel);


/*  * Component: shrdpub
 * Purpose: Storage, creation and deallocation of DSA shrdpub parameters.
 */

typedef struct dsa_shrdpub_st {
	mpm_arc	p;		/* Larger Modulus */
	mpm_arc	q;		/* Smaller Modulus */
	mpm_arc	g;		/* in GF(p) and Order(g) = q */
} *dsa_shrdpub_t;
#define DSA_NULL_SHARED ((dsa_shrdpub_t)NULL)

/*  * Function:  <dsa_kill_shrdpub>
 * Syntax: dsa_kill_shrdpub(shrdpub);
 * Semantics: This Deallocates all the memory occupied by the
 *		DSA shrdpub given to it.
 * Failure: If passed a valid Community it cannot fail.
 */
extern void dsa_kill_shrdpub(dsa_shrdpub_t);

/*  * Function: <dsa_make_shrdpub>
 * Syntax: shrdpub = dsa_make_shrdpub(p_length,q_length);
 * Semantics: Creates a new set of parameters for a new DSA shrdpub,
 *              with the specified key lengths. You should deallocate
 *		the memory when you're finished.
 * Failure: Returns DSA_NULL_SHARED if there is a memory problem or
 *		part of MPM fails.
 */
extern dsa_shrdpub_t dsa_make_shrdpub(u32 p_length, u32 q_length);


/*  * Component: user
 * Purpose: Storage, creation and deallocation of DSA shrdpub parameters.
 */

typedef struct dsa_user_st {
	mpm_arc	x;
	mpm_arc	y;
} *dsa_user_t;
#define DSA_NULL_USER ((dsa_user_t)NULL)

/*  * Function:  <dsa_kill_user>
 * Syntax: dsa_kill_user(user);
 * Semantics: This deallocates all the memory below the DSA user
 *		paramater structure.
 * Failure: If passed valid shrdpub should not fail.
 */
extern void dsa_kill_user(dsa_user_t);

/*  * Function: <dsa_make_user>
 * Syntax: user = dsa_make_user(shrdpub,secret_key_file_fp);
 * Semantics: This creates user parameters for a new user within
 *		the specified shrdpub shrdpub. The parameters
 *		are chosen so to avoid collision with other users
 *		who have their parameters footprinted in the given
 *		file. ( see fprnt.h ) The database can be created
 *		with createdb.
 * Failure: Will return DSA_NULL_USER if there was a problem with
 *		memory or MPM.
 */
extern dsa_user_t dsa_make_user(dsa_shrdpub_t,FILE *);

/*  * Component: pnonce
 * Purpose: Contains the random number used in signing, and its inverse
 * and exponentiation.
 */

typedef struct dsa_pnonce_st {
        mpm_arc k;
        mpm_arc r;
        mpm_arc k_inv;
} *dsa_pnonce_t;

#define DSA_NULL_KSTRUCT ((dsa_pnonce_t)NULL)

/*  * Function:  <dsa_kill_pnonce>
 * Syntax: dsa_kill_pnonce(pnonce);
 * Semantics: This deallocates all the memory below the DSA pnonce
 *              paramter structure.
 * Failure: If passed valid pnonce should not fail.
 */
extern void dsa_kill_pnonce(dsa_pnonce_t);

/*  * Function: <dsa_generate_privatenonce>
 * Syntax: pnonce = dsa_generate_privatenonce(shrdpub,old_kay_file_fp,prng);
 * Semantics: This creates a triplet containing a pnonce, its inverse
 *              and exponentiate in specified shrdpub shrdpub. The
 *              parameters are chosen so as to avoid collision with
 *              other triplets who have their pnonce footprinted in the
 *              given file. ( see fprnt.h ) The database can be created
 *              with createdb.
 * Failure: Will return DSA_NULL_STRUCT if there was a problem with
 *              memory or MPM.
 */
extern dsa_pnonce_t dsa_generate_privatenonce(dsa_shrdpub_t, FILE *, prng_inst *);

/*  * Component: sign
 * Purpose: Signing of hashed messages.
 */

typedef struct dsa_sig_st {
	mpm_arc	r;
	mpm_arc	s;
} *dsa_sig_t;

#define DSA_NULL_SIG ((dsa_sig_t)NULL)

/*  * Function:  <dsa_kill_sig>
 * Syntax: dsa_kill_sig(sig);
 * Semantics: Deallocates space used by signature.
 * Failure: Cannot fail if passed vaild args.
 */
extern void dsa_kill_sig(dsa_sig_t);

/*  * Function: <dsa_sign>
 * Syntax: sig = dsa_sign(shrdpub,key,hash,sig_key_file_fp,pnonce);
 * Semantics: Simply provides DSA signature of a hash, by given
 *	key within a given shrdpub. To prevent the same signature
 *	being used twice a FILE * to a footprint file must be passed.
 *	The database can be created with createdb ( see fprnt.h ).
 * Failure: In the event of a problem this will return DSA_NULL_SIG.
 *	Probably due to lack of memory, or mpm failure.
 */
extern dsa_sig_t
dsa_sign
(dsa_shrdpub_t, mpm_arc, mpm_arc, FILE *, dsa_pnonce_t, prng_inst *);

/*  * Component: validate
 * Purpose: Validation of hashes message.
 */

/*  * Function: <dsa_validate_sig>
 * Syntax:	result = dsa_validate_sig(shrdpub,sig,hash,key)
 * Semanitcs: Validates if signature of the given hash comes from
 *	given pub_key, within shrdpub. Returns
 *		DSA_GOOD        Validated OK.
 *		DSA_BAD         Did not validate.
 *		DSA_FAIL        Failure of memory etc...
 *		DSA_FLOP	Unable to validate, signature not within
 *					user and shrdpub.
 */
extern int
dsa_validate_sig
(dsa_shrdpub_t,dsa_sig_t,mpm_arc,mpm_arc );

/* Component: ber_dsa
 * Purpose: To provide BER of ASN1 forms for the structures within dsa.
 */

/* Function: <dsa_sizeof_shrdpub2berparameter>
 * Syntax: size = dsa_sizeof_shrdpub2berparameter(shrdpub);
 * Semantics: Returns the number of octets occupied by the DSA
 *	shrdpub parameters under an ASN1 encoding in a bit
 *	string of p,q,g as integers.
 * Failure: Inherits failures from mpm_sizeof_arc2berinteger(),
 *	asn1_sizeof_type2bertag(), & asn1_sizeof_size2berlen(); none of
 *	these are flagged.
 * Errors: UT_ERR_A1ASZ (DSA_ERR_PARAM,UT_ERR_A1ATP)
 * Note: This incorporates the parameters in a bit string.
 *	An octet string might be more apropriate ?
 */
extern sec_off_t
dsa_sizeof_shrdpub2berparameter(dsa_shrdpub_t);

/* Function: <dsa_shrdpub2berparameter>
 * Syntax: dsa_shrdpub2berparameter(shrdpub,destination);
 * Semantics: Writes shrdpub parameters as detailed above.
 *	Returns a pointer to the octet after the last one written.
 *	or NULL in the case of error. ( Some data may already have
 *	been written in this case ).
 * Failure: Inheretes errors from <mpm_arc2berinteger>.
 * Errors: UT_ERR_A1ASZ (DA_ERR_PARAM,UT_ERR_A1ATP)
 */
u8 *dsa_shrdpub2berparameter(dsa_shrdpub_t,u8 *);

/* Function <dsa_berparameter2shrdpub>
 * Syntax: dsa_berparameter2shrdpub(source,&shrdpub);
 * Semantics: Reads ASN encoding of shrdpub begining at
 *	source and places it in shrdpub. Returns pointer
 *	to octet after the last one read.
 * Failure: Returns NULL on failure. Failures are all PRINT/IGNORE
 *	except for parameter failures.
 * Errors: DSA_ERR_PARAM,DSA_ERR_UNEXP,DSA_ERR_XTRAD,DSA_ERR_NFBIT
 */
u8 *dsa_berparameter2shrdpub(u8 *,dsa_shrdpub_t *);

/* Function: <dsa_sizeof_user2berparameter>
 * Syntax: size = dsa_sizeof_user2berparameter(user);
 * Semantics: Returns the number of octets occupied by the DSA
 *	new user parameters under an ASN1 encoding in a bit
 *	string of x,y as integers. Note the inclusion of secret key.
 * Failure: Inherits failures from mpm_sizeof_arc2berinteger(),
 *	asn1_sizeof_type2bertag(), & asn1_sizeof_size2berlen(); none of
 *	these are flagged.
 * Errors: UT_ERR_A1ASZ (DSA_ERR_PARAM,UT_ERR_A1ATP)
 * Note: This incorporates the parameters in a bit string.
 *	An octet string might be more apropriate ?
 */
sec_off_t dsa_sizeof_user2berparameter(dsa_user_t);

/*  * Function: <dsa_user2berparameter>
 * Syntax: dsa_user2berparameter(user,destination);
 * Semantics: Writes users secret and public key as detailed above.
 *	Returns a pointer to the octet after the last one written.
 *	or NULL in the case of error. ( Some data may already have
 *	been written in this case ).
 * Failure: Inheretes errors from <mpm_arc2berinteger>.
 * Errors: UT_ERR_A1ASZ (DA_ERR_PARAM,UT_ERR_A1ATP)
 */
u8 *dsa_user2berparameter(dsa_user_t,u8 *);

/*  * Function <dsa_berparameter2user>
 * Syntax: dsa_berparameter2user(source,&user);
 * Semantics: Reads ASN encoding of user parameters begining at
 *	source and places it in user. Returns pointer
 *	to octet after the last one read.
 * Failure: Returns NULL on failure. Failures are all PRINT/IGNORE
 *	except for parameter failures.
 * Errors: DSA_ERR_PARAM,DSA_ERR_UNEXP,DSA_ERR_XTRAD,DSA_ERR_NFBIT
 */
u8 *dsa_berparameter2user(u8 *,dsa_user_t *);

/*  * Function: <dsa_sizeof_key2berkey>
 * Syntax: size = dsa_sizeof_key2berkey(key);
 * Semantics: Returns the number of octets occupied by the DSA
 *	key encoded as an integer. This should be suitable for
 *	the public key section of a certificate.
 * Failure: Inherits failures from mpm_sizeof_arc2berinteger(),
 *	asn1_sizeof_type2bertag(), & asn1_sizeof_size2berlen(); none of
 *	these are flagged.
 * Errors: UT_ERR_A1ASZ (DSA_ERR_PARAM,UT_ERR_A1ATP)
 * Note: This incorporates the parameters in a bit string.
 */
size_t dsa_sizeof_key2berkey(mpm_arc);

/*  * Function: <dsa_key2berkey>
 * Syntax: dsa_key2berkey(key,destination);
 * Semantics: Writes public or private key as detailed above.
 *	Returns a pointer to the octet after the last one written.
 *	or NULL in the case of error. ( Some data may already have
 *	been written in this case ).
 * Failure: Inheretes errors from <mpm_arc2berinteger>.
 * Errors: UT_ERR_A1ASZ (DA_ERR_PARAM,UT_ERR_A1ATP)
 */
u8 *dsa_key2berkey(mpm_arc ,u8 *);

/*  * Function <dsa_berkey2key>
 * Syntax: dsa_berkey2key(source,&key);
 * Semantics: Reads ASN encoding of public or private key begining at
 *	source and places it in y. Returns pointer
 *	to octet after the last one read.
 * Failure: Returns NULL on failure. Failures are all PRINT/IGNORE
 *	except for parameter failures.
 * Errors: DSA_ERR_PARAM,DSA_ERR_UNEXP,DSA_ERR_XTRAD,DSA_ERR_NFBIT
 */
u8 *dsa_berkey2key(u8 *,mpm_arc *);

/*  * Function: <dsa_sizeof_sig2beroctetstring>
 * Syntax: size = dsa_sizeof_sig2beroctetstring(sig);
 * Semantics: Returns the number of octets occupied by the DSA
 *	signature under an ASN1 encoding in a octet
 *	string of r,s as integers. This should be suitable for
 *	using as a signature in a certificate.
 * Failure: Inherits failures from mpm_sizeof_arc2berinteger(),
 *	asn1_sizeof_type2bertag(), & asn1_sizeof_size2berlen(); none of
 *	these are flagged.
 * Errors: UT_ERR_A1ASZ (DSA_ERR_PARAM,UT_ERR_A1ATP)
 * Note: This incorporates the parameters in a octetstring.
 */
sec_off_t dsa_sizeof_sig2beroctetstring(dsa_sig_t );

/*  * Function: <dsa_sig2beroctetstring>
 * Syntax: dsa_sig2beroctetstring(sig,destination);
 * Semantics: Writes signature as detailed above.
 *	Returns a pointer to the octet after the last one written.
 *	or NULL in the case of error. ( Some data may already have
 *	been written in this case ).
 * Failure: Inheretes errors from <mpm_arc2berinteger>.
 * Errors: UT_ERR_A1ASZ (DA_ERR_PARAM,UT_ERR_A1ATP)
 */
u8 *dsa_sig2beroctetstring(dsa_sig_t ,u8 *);

/*  * Function <dsa_beroctetstring2sig>
 * Syntax: dsa_beroctetstring2sig(source,&sig);
 * Semantics: Reads ASN encoding of signature begining at
 *	source and places it in sig. Returns pointer
 *	to octet after the last one read.
 * Failure: Returns NULL on failure. Failures are all PRINT/IGNORE
 *	except for parameter failures.
 * Errors: DSA_ERR_PARAM,DSA_ERR_UNEXP,DSA_ERR_XTRAD
 */
u8 *dsa_beroctetstring2sig(u8 *,dsa_sig_t *);

/*  * Function: <dsa_sizeof_pnonce2berparameter>
 * Syntax: size = dsa_sizeof_pnonce2berparameter(pnonce);
 * Semantics: Returns the number of octets occupied by the DSA
 *	pnonce parameters under an ASN1 encoding in a bit
 *	string of k, r, k_inv as integers.
 * Failure: Inherits failures from mpm_sizeof_arc2berinteger(),
 *	asn1_sizeof_type2bertag(), & asn1_sizeof_size2berlen(); none of
 *	these are flagged.
 * Errors: UT_ERR_A1ASZ (DSA_ERR_PARAM,UT_ERR_A1ATP)
 * Note: This incorporates the parameters in a bit string.
 *	An octet string might be more apropriate ?
 */
sec_off_t dsa_sizeof_pnonce2berparameter(dsa_pnonce_t);

/*  * Function: <dsa_pnonce2berparameter>
 * Syntax: dsa_pnonce2berparameter(pnonce,destination);
 * Semantics: Writes pnonce parameters as detailed above.
 *	Returns a pointer to the octet after the last one written.
 *	or NULL in the case of error. ( Some data may already have
 *	been written in this case ).
 * Failure: Inherits errors from <mpm_arc2berinteger>.
 * Errors: UT_ERR_A1ASZ (DA_ERR_PARAM,UT_ERR_A1ATP)
 */
u8 *dsa_pnonce2berparameter(dsa_pnonce_t,u8 *);

/*  * Function <dsa_berparameter2pnonce>
 * Syntax: dsa_berparameter2pnonce(source,&pnonce);
 * Semantics: Reads ASN encoding of pnonce begining at
 *	source and places it in pnonce. Returns pointer
 *	to octet after the last one read.
 * Failure: Returns NULL on failure. Failures are all PRINT/IGNORE
 *	except for parameter failures.
 * Errors: DSA_ERR_PARAM,DSA_ERR_UNEXP,DSA_ERR_XTRAD,DSA_ERR_NFBIT
 */
u8 *dsa_berparameter2pnonce(u8 *,dsa_pnonce_t *);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* Not _DSA_H */
