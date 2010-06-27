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

#ifndef _CST_PKCS12_H    /* prevent multiple inclusion */
#define _CST_PKCS12_H

#include "ut.h"
#include "prng.h"

#include "pkcs12t.h"    /* for types */
#include "algid.h"    /* for algid_objid */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * IMPORTANT NOTE: Memory allocation and deallocation.
 *
 * This header file uses three types of data structure:
 * - pkcs12_obj object
 * - Intermediate pkcs12_XXX objects
 * - ut_mblks
 *
 * ut_mblks are the basic building blocks. They are considered to
 * represent data that has a relevance outside the PKCS#12 object. When
 * we add a ut_mblk data block to some intermediate object we add a COPY
 * of the data. When we get a ut_mblk from an intermediate object we
 * extract a COPY of the data. Data that is held in a ut_mblk inside an
 * intermediate object can be deleted from that intermediate object with
 * a "delete" function. 
 *
 * All intermediate object types are typedefed as void *s. They are
 * treated differently from the ut_mblk data types. If you add an
 * intermediate object to another intermediate object or to a pkcs12_obj
 * object, you are inserting the actual pointer; you are not making a
 * copy of the object. If you get an intermediate object from some other
 * object, again you get the same pointer that the containing object
 * references. To copy intermediate objects, use the copy() function for
 * that object. You can remove an intermediate object from the object
 * that contains it using the remove() function. This detaches the
 * pointer from inside the containing object. It does NOT delete the
 * intermediate object itself; it still takes up memory which must be
 * disposed of separately.
 *
 * When you destroy a pkcs12_obj object, or any intermediate object, you
 * also destroy all the intermediate objects and ut_mblks within it.
 *
 * The function pkcs12_XXX_copy makes a copy of a pkcs12_XXX
 * intermediate object and all its contents.
 */

/* ALGORITHM IDs */

extern u32 algid_pkcs9[];
extern u32 algid_pkcs12_FriendlyName[];
extern u32 algid_pkcs12_LocalKeyId[];

/* never output directly... */
extern u32 algid_pkcs12version1[];
extern u32 algid_pkcs12bagIds[];

/* SafeBag Ids... */
extern u32 algid_pkcs12_KeyBag[];
extern u32 algid_pkcs12_ShroudedKeyBag[];
extern u32 algid_pkcs12_CertBag[];
extern u32 algid_pkcs12_CrlBag[];
extern u32 algid_pkcs12_SecretBag[];
extern u32 algid_pkcs12_SafeConBag[];

/* Cert Type Ids... */
extern u32 algid_pkcs12_certTypes[];
extern u32 algid_pkcs12_X509Cert[];
extern u32 algid_pkcs12_SDSICert[];

/* CRL Type Ids... */
extern u32 algid_pkcs12_crlTypes[];
extern u32 algid_pkcs12_X509Crl[];


/* Useful Oid to pkcs12_XXX_algid functions */


extern 
algid_objid
pkcs12_PbeAlgId2Oid(pkcs12_PbeAlgId type);

extern
pkcs12_PbeAlgId
pkcs12_Oid2PbeAlgId(algid_objid oid);

extern
algid_objid
pkcs12_SafeConType2Oid(pkcs12_SafeContentsType type);

extern
algid_objid
pkcs12_SafeBagType2Oid(pkcs12_SafeBagType type);

extern
pkcs12_SafeBagType
pkcs12_Oid2SafeBagType(algid_objid oid);

extern
algid_objid
pkcs12_KeyAlgId2Oid(pkcs12_KeyAlgId algid);

extern
pkcs12_KeyAlgId
pkcs12_Oid2KeyAlgId(algid_objid oid);

extern
algid_objid
pkcs12_CertBagType2Oid(pkcs12_CertBagType type);

extern
pkcs12_CertBagType
pkcs12_Oid2CertBagType(algid_objid oid);

extern
algid_objid
pkcs12_AttributeType2Oid(pkcs12_AttributeType type);

extern
pkcs12_AttributeType
pkcs12_Oid2AttributeType(algid_objid oid);



/* Functions on pkcs12_obj */


/*
 * FUNCTIONS ON pkcs12_obj:
 */

/* Allocate memory for a pkcs12_obj. Returns 0 on failure. */

/* Note that this command simply allocates memory for a bare-bones
 * pkcs12_obj. A typical PKCS#12 object, containing a two or three cert
 * cert chain and the corresponding private key, will take up up to 8K
 * of memory and up to 4K when written out to disk (the object is bigger
 * because we maintain unencrypted and encrypted copies of all encrypted
 * data if possible).
 */

pkcs12_obj
pkcs12_obj_new();


/* Deallocate the memory for the object and all its contents. */

void
pkcs12_obj_destroy(pkcs12_obj victim);

/* Clear only the MAC data */

void
pkcs12_obj_clearMacData(pkcs12_obj victim);

/* Make a full copy of the pkcs12_obj -- this probably won't be used
 * very often. Returns 0 on success, -1 on internal failure (failure to
 * allocate memory), -2 in debug mode if passed any null parameters.
 *
 * The copy must be disposed of with pkcs12_obj_destroy(copy).
 */

int
pkcs12_obj_copy(pkcs12_obj  original,
                pkcs12_obj *copy);

/*
 * Writing a PKCS#12 object:
 */

/* Add a SafeContents to a pkcs12_obj.
 *
 * Returns -1 on failure. In debug mode, returns -2 if passed any null
 * parameters.
 *
 * NOTE that this does not insert a copy, but the actual SafeContents
 * object that you've created. pkcs12_obj_destroy will destroy the
 * SafeContents object as well. Use pkcs12_SafeContents_copy() if you
 * will need the given pkcs12_SafeContents after you've destroyed the
 * pkcs12_obj.
 *
 * Also NOTE that the functions do not prevent you inserting a
 * SafeContents even after you've generated the integrity code on the
 * PKCS#12 object. This will naturally invalidate the integrity code.
 * Care must be taken not to call pkcs12_obj_generateMac() until after the
 * last possible call to pkcs12_obj_addSafeContents().
 */

int
pkcs12_obj_addSafeContents(pkcs12_obj          object,
                           pkcs12_SafeContents safeCon);



/* Remove a SafeContents from a pkcs12_obj.
 *
 * This may be useful if you had a pkcs12_obj which contained two
 * different key/cert-chain pairs, in different SafeContents, and wanted
 * to create a pkcs12_obj which only had one of the pairs in it.
 *
 * Note that a SafeContents has no unique identifier, so the only way to
 * find the SafeContents you want to remove is:
 * - get each SafeContents in turn with pkcs12_obj_getSafeContents
 * - check its properties to see if you want to remove it
 * - call pkcs12_obj_removeSafeContents if so.
 *
 * Once a SafeContents has been removed from the object, it must be
 * destroyed independently using pkcs12_SafeContents_destroy().
 *
 * Returns 0 on success, -1 on failure... but shouldn't fail.
 */

int
pkcs12_obj_removeSafeContents(pkcs12_obj          object,
                              pkcs12_SafeContents safeCon);



/* set the MAC params. If the third argument is zero the prng supplied
 * in the fourth argument is used to generate the salt. The salt length
 * if generated internally is given by DEFAULT_SALT_LEN in pbei.h --
 * currently 20 bytes. If iCount is zero it is set equal to 1.
 *
 * Returns 0 on success, -1 on internal failure, -2 in debug mode on
 * null params.
 */

int
pkcs12_obj_setMacParams(pkcs12_obj   object,
                        int          iCount,
                        ut_mblk     *salt,
                        prng_inst   *prng);



/* Generate a MAC integrity check on the pkcs12_obj using the password.
 * This should be the last function called before pkcs12_obj_write().
 * The password MUST be a BMP (Unicode) string. The functions
 * ut_ascii2bmp help with this.
 *
 * A MAC consists of a "keyed hash". The key is generated by hashing the
 * passphrase and some random "salt" a number of times, known as the
 * iteration count. In this implementation the salt is generated
 * internally. The iteration count iCount should be betwen 500 and 1000
 * for security -- but see the next paragraph.
 *
 * Netscape and MSIE will ONLY read in a PKCS#12 file if:
 * - the same password is used to generate both the encryption key and
 *   the MAC key
 * - the MAC iteration count is 1.
 *
 * Returns 0 on success; returns -1 on internal failure; in debug mode,
 * returns -2 if passed null parameters; returns 1 if a MAC has already
 * been generated on the pkcs12_obj; returns 2 if the MAC parameters
 * haven't been set.
 */

int
pkcs12_obj_generateMac(pkcs12_obj       object,
                       pkcs12_MacAlgId  macAlgId,
                       ut_mblk         *passphrase,
                       int              passphraseIsAscii);



/* Get the size of the BER-encoded PKCS#12 object.
 */

sec_off_t
pkcs12_obj_sizeof2ber(pkcs12_obj obj);




/* Write out the data */

u8 *
pkcs12_obj_2ber(pkcs12_obj  obj,
                u8         *dest);




/* Output a PKCS#12 object to a file.
 *
 * This function assumes that all processing has been successfully done
 * up till now, so it doesn't check that there is an integrity check on
 * the data; this means that you can output non-standard PKCS#12 if you
 * call this function without having called pkcs12_obj_generateMac().
 *
 * Returns 0 on failure, -1 on internal error, -2 in debug mode on null
 * parameters.
 */

int
pkcs12_obj_writeToFile(pkcs12_obj  object,
                       FILE       *file);



/* Output a PKCS#12 object to a ut_mblk_list.
 *
 * This function assumes that all processing has been successfully done
 * up till now, so it doesn't check that there is an integrity check on
 * the data; this means that you can output non-standard PKCS#12 if you
 * call this function without having called pkcs12_obj_generateMac().
 *
 * This outputs the data in a ut_mblk_list, terminated with a NULL
 * pointer. The data is all BER-encoded already. If you want to output
 * the data to a file from the list and then dispose of the data, use
 * code like the following:
 *   ut_mblk_list output, tmplist;
 *   FILE *outfile;
 *   ...
 *   pkcs12_obj_writeToMblkList(object, &output);
 *   ...
 *   for (tmplist = output; tmplist; tmplist = tmplist->next);
 *     fwrite(tmplist->block.data, 1, tmplist->block.used, outfile);
 *   ...
 *   ut_dispose_list(output);
 */

int
pkcs12_obj_writeToMblkList(pkcs12_obj     object,
                           ut_mblk_list  *mlist);

/*
 * Reading a PKCS#12 object:
 */

/* Import data from a saved PKCS#12 file into a pkcs12_obj.
 */

/* Find out what type of integrity check was performed on the PKCS#12
 * data. This should be called immediately after we finish reading in
 * the data from the file.
 *
 * Returns PKCS12_INTMODE_UNSUP on error. If it returns
 * PKCS12_INTMODE_PASSWD, check the integrity with pkcs12_obj_verifyMac.
 * If it returns PKCS12_INTMODE_PUBKEY, we currently don't provide
 * routines to handle the integrity checking.
 */

pkcs12_IntMode
pkcs12_obj_getIntMode(pkcs12_obj object);




/* Verify the MAC integrity check on the pkcs12_obj using the password.
 * The password MUST be a BMP (Unicode) string. The functions
 * ut_ascii2bmp help with this.
 *
 * Returns 0 on successful integrity check; -1 on internal error; 1 if
 * the integrity check was failed; -2 in debug mode if it's passed null
 * parameters.
 *
 * Currently the MAC hash algorithm is hardwired as SHA-1. This will be
 * changed in future releases.
 */

int
pkcs12_obj_verifyMac(pkcs12_obj  object,
                     ut_mblk    *password,
                     int         passwordIsAscii);





/* Query a pkcs12_obj about the contents.
 *
 * On success, the function returns 0 and noOfSafeContents is set equal
 * to the number of SafeContents within the PKCS#12 object.
 *
 * On failure, the function returns -1 (which should never happen -- if
 * there's been an error it'll have happened in one of the readFrom
 * functions).
 */

int
pkcs12_obj_getInfo(pkcs12_obj  object,
                   int        *noOfSafeContents);




/* Function:    <pkcs12_obj_getMacInfo>
 * Summary:     Get MAC info from a PKCS#12 object.
 * Syntax:      int rval = pkcs12_obj_getMacInfo(pkcs12_obj  obj, 
 *                s32 *iCount, ut_mblk *salt);
 * Description: The pkcs12_obj_getMacInfo() function gets the iteration
 *              count and salt data from a PKCS#12 object. It allocates
 *              memory at salt.data.
 * Returns:     This function returns 0 on success, -1 on failure.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(salt->data);
 *           (/code)
 */
int
pkcs12_obj_getMacInfo(pkcs12_obj  obj,
                      s32        *iCount,
                      ut_mblk    *salt);




/* Get SafeContents[index] from the pkcs12_obj, where index is between 0
 * and noOfSafeContents. Returns 0 on failure.
 *
 * Note that this returns the pointer to the SafeContents object itself.
 * The object should not be disposed of as pkcs12_obj_destroy will also
 * destroy the pkcs12_SafeContents.
 */

pkcs12_SafeContents
pkcs12_obj_getSafeContentsByIndex(pkcs12_obj object,
                                  int        index);





/* Get an array of pointers to all the SafeContents in the pkcs12_obj.
 * The SafeContentses in the array should not be disposed of
 * individually. The memory for the array of SafeContents pointers is
 * allocated internally and must be deallocated as in the following
 * example:
 *   pkcs12_SafeContents   *safeCons;
 *   ...
 *   pkcs12_obj_getAllSafeContents(object, &noOfSafeCons, &safeCons);
 *   ...
 *   ut_dispose_mem(safeCons);
 *
 * Returns 0 on success, -1 on internal error. If there are no
 * safecontents it returns success but sets *safeCons and noOfSafeCons
 * to 0.
 */

int
pkcs12_obj_getAllSafeContents(pkcs12_obj            object,
                              int                  *noOfSafeCons,
                              pkcs12_SafeContents **safeCons);



/* Get all the SafeBags with the same Local Key ID attribute value.
 * The Local Key ID is stored in id.data and has length id.used. It is
 * an unstructured byte string and can be any length.
 *
 * This function will return the SafeBags which can be retrieved from
 * decrypted SafeContents. It should only be called after all
 * SafeContents in the pkcs12_obj have been decrypted.
 *
 * On success, the function returns 0; noOfSafeBags contains the number
 * of SafeBags with that Local Key ID which were found; and safeBags
 * contains an array of SafeBags, each of which can then be queried to
 * find out which contains the private key and which the cert. The
 * pkcs12_SafeBags in the array are pointers to the pkcs12_SafeBags
 * within the pkcs12_obj. They will be freed when the pkcs12_object is
 * destroyed and should not be destroyed individually. The memory for
 * the array of SafeBag pointers is allocated internally and must be
 * deallocated as in the following example:
 *   pkcs12_SafeBags   *safeBags;
 *   ...
 *   pkcs12_obj_getSafeBagsByKeyId(object, &id, &noOfSafeBags, &safeBags);
 *   ...
 *   ut_dispose_mem(safeBags);
 *
 * If id = 0, the function returns an array of all the SafeBags that
 * have NO associated LocalKeyId. This array may or may not be any use.
 *
 * Returns 0 on success, -1 on internal failure (failure to allocate
 * memory). If it can't find any SafeBags with the given LocalKeyID
 * attribute value it returns 0 but noOfSafeBags = 0.
 *
 * The control flow envisaged is:
 * - import pkcs12_object
 * - decrypt all encrypted SafeContents
 * - for each SafeBag in each SafeContents:
 *   - if it has a local key ID which hasn't been found already, use
 *     pkcs12_obj_getSafeBagsByKeyId to make a collection of all
 *     SafeBags with the same KeyId.
 *   - add this to an associative array of (keyId, safeBags[]).
 * This will reassemble the contents of the pkcs12_objs as a set of
 * SafeBags which are associated by ID instead of by encryption method.
 */

/* this function should be called as if it was declared thus:
  int
  pkcs12_obj_getSafeBagsByKeyId(pkcs12_obj       object,
                                ut_mblk         *id,
                                int             *noOfSafeBags,
                                pkcs12_SafeBag **safeBags);
 *  ... while in fact it's a macro wrapper to
 *  pkcs12_obj_getSafeBagsByAttrValue(), as follows:
 */

#define pkcs12_obj_getSafeBagsByKeyId(object,id,noOfSafeBags,safeBags) \
    pkcs12_obj_getSafeBagsByAttrValue(object, PKCS12_ATTRTYPE_KEYID, \
                                     (void *)id, noOfSafeBags, safeBags);

int
pkcs12_obj_getSafeBagsByAttrValue(pkcs12_obj            object,
                                  pkcs12_AttributeType  type,
                                  void                 *id,
                                  int                  *noOfSafeBags,
                                  pkcs12_SafeBag      **safeBags);




/* pkcs12_obj_readFromFile: reads in a PKCS12 object from a file. The
 * FILE * passed in is returned pointing to the byte after the final
 * byte in the object.
 *
 * returns 0 on success, -1 on failure.
 */

int
pkcs12_obj_readFromFile(pkcs12_obj  obj,
                        FILE       *file);




/* pkcs12_obj_readberobj: reads in a PKCS12 object and returns a pointer to
 * the byte after the last byte read, or 0 on failure. On successful
 * completion *finished is set = 1, otherwise it is 0.
 *
 * obj has already been created with pkcs12_obj_new.
 */
extern
u8 *
pkcs12_obj_readberobj(pkcs12_obj    obj,
                      u8           *src,
                      size_t        srclen,
                      int          *finished);





/* If we're sure we have enough data, convert it to a pkcs12_obj and
 * parse all the internals as well.
 */

u8 *
pkcs12_obj_fullber2obj(pkcs12_obj obj, u8 *src);





/*
 * FUNCTIONS ON pkcs12_SafeContents
 */

/* a pkcs12_SafeContents is a sequence of SafeBags. The SafeContents
 * level is the level at which encryption is usually applied in PKCS#12;
 * in other words, rather than storing your PKCS#8 encrypted private key
 * in a SafeBag, you put your plaintext private key in a SafeBag, put
 * the SafeBag in a SafeContents, and encrypt the SafeContents.
 */


/* Allocate memory for a pkcs12_SafeContents. Returns 0 on failure.
 *
 * The created SafeContents will have pkcs12_SafeContentsType =
 * PKCS12_SAFECON_DATA; in other words, it is created as plaintext data.
 */

extern
pkcs12_SafeContents
pkcs12_SafeContents_new();

/* Deallocate the memory for the object and all its contents. */

extern
void
pkcs12_SafeContents_destroy(pkcs12_SafeContents victim);

/* Make a full copy of the pkcs12_SafeContents.
 *
 * Returns 0 on success, -1 on internal failure (failure to allocate memory), 
 * -2 in debug mode if passed any null parameters.
 */

extern
int
pkcs12_SafeContents_copy(pkcs12_SafeContents  original,
                         pkcs12_SafeContents *copy);



/*
 * Writing a pkcs12_SafeContents
 */

/* Add a SafeBag to a SafeContents.
 *
 * Returns -1 on internal failure, 0 on success, 1 if the SafeContents
 * is not of type PKCS12_SAFECON_DATA. In other words, you can't add a
 * SafeBag to a SafeContents that's already encrypted.
 *
 * NOTE that this does not insert a copy, but the actual SafeContents
 * object that you've created. pkcs12_obj_destroy will destroy the
 * SafeContents object as well. Use pkcs12_SafeContents_copy() if you
 * will need the given pkcs12_SafeContents after you've destroyed the
 * pkcs12_obj.
 *
 * For this reason, we don't supply a method to access the SafeBag
 * within the SafeContents. You can simply keep track of the SafeBag
 * itself.
 */

extern
int
pkcs12_SafeContents_addSafeBag(pkcs12_SafeContents safeCon,
                               pkcs12_SafeBag      safeBag);

/* Pkcs12_SafeContents_setEncryptionParams: Sets the encryption
 * parameters.
 * 
 * If the third argument is zero the prng supplied in the fourth
 * argument is used to generate the salt. The salt length if generated
 * internally is given by DEFAULT_SALT_LEN in pbei.h -- currently 20
 * bytes. If iCount is zero it is set equal to 1.
 * 
 * Returns 0 on success, -1 on internal failure, -2 in debug mode on
 * null params. 
 */
 
extern
int
pkcs12_SafeContents_setEncryptionParams(pkcs12_SafeContents   sCon,
                                        pkcs12_PbeAlgId       pbeAlgId,
                                        int                   iCount,
                                        ut_mblk              *salt,
                                        prng_inst            *prng);


/* Encrypt a SafeContents.
 *
 * Returns -1 on internal error, 0 on success, -2 in debug mode on null
 * parameters, 1 if the SafeContents is already encrypted. Once this
 * function is called no more pkcs12_SafeBags may be added to the
 * SafeContents.
 *
 * The password MUST be a BMP (Unicode) string. The functions
 * ut_ascii2bmp help with this.
 *
 * The encrypted key is generated by hashing the passphrase and some
 * random "salt" a number of times, known as the iteration count. In
 * this implementation the salt is generated internally. The iteration
 * count iCount should be betwen 500 and 1000 for security.
 *
 * Netscape and MSIE will ONLY read in a PKCS#12 file if:
 * - the same password is used to generate both the encryption key and
 *   the MAC key
 * - the MAC iteration count is 1.
 */

extern
int
pkcs12_SafeContents_encrypt(pkcs12_SafeContents safeCon,
                            ut_mblk            *passphrase,
                            int                 passphraseIsAscii);



/* Remove a SafeBag from a pkcs12_SafeContents.
 *
 * Useful for generating a pkcs12_obj which is almost, but not quite,
 * the same as another one.
 *
 * Once a SafeBag has been removed from the object, it must be
 * destroyed independently using pkcs12_SafeBag_destroy().
 *
 * Returns 0 on success, -1 on failure... but shouldn't fail.
 */

extern
int
pkcs12_SafeContents_removeSafeBag(pkcs12_SafeContents safeCon,
                                  pkcs12_SafeBag      safeBag);



/*
 * Reading a pkcs12_SafeContents
 */


/* Pkcs12_SafeContents_ber2obj -- reads in a BER-encoded
 * SafeContents and does an amount of processing on it. Returns a
 * pointer to the byte after
 */

extern
u8 *
pkcs12_SafeContents_ber2obj(pkcs12_SafeContents  sCon,
                            u8                   *src);



/* Once you've got a given SafeContents from an imported object with
 * pkcs12_obj_getSafeContents(), the following functions interrogate it.
 */

/* get the type of data in a PKCS12_SafeContents.
 *
 * If the type is NOT PKCS12_SAFECON_DATA you will not be able to
 * extract any SafeBags from the SafeContents until it's decrypted.
 *
 * If the type is PKCS12_SAFECON_ENCR, it can be decrypted using
 * pkcs12_SafeContents_Decrypt. This changes the data type to
 * PKCS12_SAFECON_DATA.
 *
 * Otherwise, PKCS12_SAFECON_ENVL cannot currently be handled, and
 * PKCS12_SAFECON_UNSUP denotes some kind of error.
 */

extern
pkcs12_SafeContentsType
pkcs12_SafeContents_getType (pkcs12_SafeContents safeCon);


/* decrypt it if it was of type PKCS12_SAFECON_ENCR. The passphrase must
 * be a BMP (Unicode) string. The function ut_ascii2bmp will help with
 * this.
 *
 * returns 0 on success, -1 on internal error, 1 on incorrect ASN.1
 * parsing.
 */

extern 
int
pkcs12_SafeContents_decrypt (pkcs12_SafeContents  safeCon,
                             ut_mblk             *passphrase,
                             int                  passphraseIsAscii);


/* Get the parameters used to encrypt a pkcs12_SafeContents. This
 * function must be called AFTER pkcs12_SafeContents_decrypt.
 *
 * Allocates memory at aid.
 * 
 * Returns 0 on success, -1 on internal error, -2 in debug mode on
 * null parameters.
 */
int
pkcs12_SafeContents_getPbeInfo (pkcs12_SafeContents  safeCon,
                                algid_algid         *aid);


/* Query a pkcs12_SafeContents about the contents.
 *
 * On success, the function returns 0 and noOfSafeBags is set equal
 * to the number of SafeBags within the PKCS#12 SafeContentsect.
 *
 * On failure, the function returns -1 (which should never happen -- if
 * there's been an error it'll have happened in one of the readFrom
 * functions).
 */

extern
int
pkcs12_SafeContents_getInfo(pkcs12_SafeContents  safeCon,
                            int                 *noOfSafeBags);


/* Get SafeBags[index] from the pkcs12_SafeContents, where index is between 0
 * and noOfSafeBags. Returns 0 on failure.
 *
 * Note that this returns the pointer to the SafeBag object itself. The
 * object should not be disposed of as pkcs12_SafeContents_destroy will
 * also destroy the pkcs12_SafeBag.
 */
extern
pkcs12_SafeBag
pkcs12_SafeContents_getSafeBagByIndex(pkcs12_SafeContents safeCon,
                                      int                 index);


/* Get an array of pointers to all the SafeBags in a SafeContents. The
 * SafeBags in the array should not be disposed of individually. The
 * memory for the array of SafeBag pointers is allocated internally and
 * must be deallocated as in the following example:
 *   pkcs12_SafeContents   *safeCons;
 *   ...
 *   pkcs12_obj_getAllSafeContents(object, &noOfSafeCons, &safeCons);
 *   ...
 *   ut_dispose_mem(safeCons);
 *  
 * Returns 0 on success, -1 on internal error. If there are no
 * safecontents it returns success but sets *safeCons and noOfSafeCons
 * to 0.
 */

extern
int
pkcs12_SafeContents_getAllSafeBags(pkcs12_SafeContents   safeCon,
                                   int                  *noOfSafeBags,
                                   pkcs12_SafeBag      **safeBags);
 


/* Get all the SafeBags with the same Local Key ID attribute value in a
 * given SafeContents. The Local Key ID is stored in id.data and has
 * length id.used. It is an unstructured byte string and can be any
 * length.
 *
 * This function can only be called on an unencrypted SafeContents.
 *
 * On success, the function returns 0; noOfSafeBags contains the number
 * of SafeBags with that Local Key ID which were found; and safeBags
 * contains an array of SafeBags, each of which can then be queried
 * using existing functions.
 *
 * The memory for the array of SafeBag pointers is allocated internally
 * and must be deallocated as in the following example:
 *   pkcs12_SafeBags   *safeBags;
 *   ...
 *   pkcs12_SafeContents_getSafeBagsByKeyId(object, &id, 
 *     &noOfSafeBags, &safeBags);
 *   ...
 *   ut_dispose_mem(safeBags);
 *  
 * If id = 0, the function returns an array of all the SafeBags that
 * have NO associated LocalKeyId. This array may or may not be any use.
 *
 * Returns 0 on success, -1 on internal failure (failure to allocate
 * memory). If it can't find any SafeBags with the given LocalKeyID
 * attribute value it returns 0 but noOfSafeBags = 0.
 *
 * This function may not be much use, but it's used by
 * pkcs12_obj_getSafeBagsByKeyId, so we may as well publish it.
 */

/* this function should be called as if it was declared thus:
  extern
  int
  pkcs12_SafeContents_getSafeBagsByKeyId(pkcs12_SafeContents   safeCon,
                                         ut_mblk              *id,
                                         int                  *noOfSafeBags,
                                         pkcs12_SafeBag      **safeBags);
 *  ... while in fact it's a macro wrapper to
 *  pkcs12_SafeContents_getSafeBagsByAttrValue(), as follows:
 */

#define \
    pkcs12_SafeContents_getSafeBagsByKeyId(object,id,noOfSafeBags,safeBags) \
    pkcs12_SafeContents_getSafeBagsByAttrValue(object, PKCS12_ATTRTYPE_KEYID, \
                                     (void *)id, noOfSafeBags, safeBags)

extern
int
pkcs12_SafeContents_getSafeBagsByAttrValue(pkcs12_SafeContents   safeCon,
                                           pkcs12_AttributeType  type,
                                           ut_mblk              *id,
                                           int                  *noOfSafeBags,
                                           pkcs12_SafeBag      **safeBags);


/*
 * FUNCTIONS ON pkcs12_SafeBag
 */

/* a pkcs12_SafeBag is a wrapper for your key, your encrypted key, your
 * certificate, a further SafeContents, or any additional identity
 * information you want to store. 
 * 
 * Each bag contents has an associated set of zero or more optional attributes.
 *
 * One of these attributes is the "friendly name". This is a BMP (Unicode) 
 * string which describes the contents of the SafeBag. Netscape REQUIRES that 
 * certs in a SafeBag have an associated friendly name, or it cannot import 
 * them.
 *
 * Another attribute is the "local key ID". This is simply an octet
 * string. However, the same octet string can be associated with both a
 * given key and a given certificate so you can link one with the other.
 */


/* Allocate memory for a pkcs12_SafeBag. Returns 0 on failure.
 * 
 * The SafeBag is created with bagType PKCS12_SAFEBAG_NONE.
 */

extern
pkcs12_SafeBag
pkcs12_SafeBag_new();

/* Deallocate the memory for the object and all its contents. */

extern
void
pkcs12_SafeBag_destroy(pkcs12_SafeBag victim);

/* Make a full copy of the pkcs12_SafeBag.
 *
 * Returns 0 on success, -1 on internal failure (failure to allocate memory), 
 * -2 in debug mode if passed any null parameters.
 */

extern
int
pkcs12_SafeBag_copy(pkcs12_SafeBag  original,
                    pkcs12_SafeBag *copy);



/*
 * Writing a pkcs12_SafeBag:
 */

/* Add a SafeBagContents and set the bagType appropriately.
 *
 * Returns 0 on success; -1 on internal failure; 1 if the bag already
 * has contents.
 *
 * NOTE that this does not insert a copy, but the actual SafeBagContents
 * object that you've created. See above for what this means.
 */

extern
int
pkcs12_SafeBag_insertContents(pkcs12_SafeBag         safeBag,
                              pkcs12_SafeBagContents contents,
                              pkcs12_SafeBagType     type);


/* Get a handle to a SafeBagContents from a pkcs12_SafeBag.
 *
 * Returns 0 on success, -1 on failure... but shouldn't fail.
 */

extern
pkcs12_SafeBagContents
pkcs12_SafeBag_getContents(pkcs12_SafeBag safeBag);





/* Remove a SafeBagContents from a pkcs12_SafeBag.
 *
 * Provided for completeness more than anything. The remove functions
 * for specific Bag-types are more likely to be useful.
 *
 * Once a SafeBagContents has been removed from the object, it must be
 * destroyed independently using pkcs12_SafeBag_destroy().
 *
 * Returns 0 on success, -1 on failure... but shouldn't fail.
 */

extern
pkcs12_SafeBagContents
pkcs12_SafeBag_removeContents(pkcs12_SafeBag safeBag);



/* Set attributes. Currently the only attributes that can be set are the
 * ones defined in the enum pkcs12_SafeBag_AttributeType.
 *
 * type is the type; data is a ut_mblk containing the data. Note that
 * because the data is in the ut_mblk, it is COPIED in (ut_mblks are
 * considered basic data types) rather than the address of the ut_mblk
 * being taken. THINK ABOUT THIS.
 *
 * The function returns 0 on success, -1 on an internal error, and 1 if
 * the SafeBag already has an attribute of the given type.
 */

extern
int
pkcs12_SafeBag_setAttribute(pkcs12_SafeBag        safeBag,
                            pkcs12_AttributeType  type,
                            ut_mblk              *data);


/*
 * Reading a pkcs12_SafeBag:
 */

/* Get the SafeBagType. Returns PKCS12_BAGTYPE_UNSUP on error. 
 */

extern
pkcs12_SafeBagType
pkcs12_SafeBag_getType(pkcs12_SafeBag safeBag);

/* Get description of attributes.
 *
 * On success, the function returns 0; noOfAttrs is set to the number of
 * attributes; and attrTypes contains an array of attribute types
 * which give the type of each attribute in turn. The memory allocated
 * at attrTypes must be explicitly deallocated as in the following
 * example:
 *   pkcs12_AttributeType *attrTypes;
 *   ...
 *   pkcs12_SafeBag_getAttrInfo(safeBag, &noOfAttrs, &attrTypes);
 *   ...
 *   ut_dispose_mem(attrTypes);
 *
 * On failure, returns -1 for internal error, 1 if there was a parsing
 * problem. In debug mode, returns -2 if passed null parameters.
 */

extern
int
pkcs12_SafeBag_getAttrInfo(pkcs12_SafeBag         safeBag,
                           int                   *noOfAttrs,
                           pkcs12_AttributeType **attrTypes);


/* Get all attributes.
 *
 * On success, the function returns 0; noOfAttrs is set to the number of
 * attributes; and attrTypes contains an array of attribute types
 * which give the type of each attribute in turn. The memory allocated
 * must be explicitly deallocated as in the following example:
 *   pkcs12_AttributeType *attrTypes;
 *   ut_mblk             **blkArray;
 *   ...
 *   pkcs12_SafeBag_getAttrInfo(safeBag, &noOfAttrs, &attrTypes,
 *     &blkArray);
 *   ...
 *   ut_dispose_mem(attrTypes)
 *   while (noOfAttrs) 
 *     ut_dispose_mblk_f(blkArray[--noOfAttrs]);
 *   ut_dispose_meme(blkArray);
 *
 * On failure, returns -1 for internal error, 1 if there was a parsing
 * problem. In debug mode, returns -2 if passed null parameters.
 */
 
extern
int
pkcs12_SafeBag_getAttrs(pkcs12_SafeBag         safeBag,
                        int                   *noOfAttrs,
                        pkcs12_AttributeType **attrTypes,
                        ut_mblk             ***attrData);


/* Get an attribute of a specific type.
 *
 * On success, returns 0 and attribute contains a copy of the attribute
 * data. This data must be explicitly deallocated as in the following
 * example:
 *   ut_mblk    attribute; 
 *   ...
 *   pkcs12_SafeBag_getAttrByType(safeBag, PKCS12_ATTRTYPE_FNAME, &attribute);
 *   ...
 *   ut_dispose_mblk (&attribute);
 *
 * On failure, returns -1 for internal error, 1 if there was a parsing
 * problem, 2 if it could not find an attribute of the given type.
 */

extern
int
pkcs12_SafeBag_getAttrByType(pkcs12_SafeBag        safeBag,
                             pkcs12_AttributeType  attrType,
                             ut_mblk              *attribute);

/* To be added: getAttrOids, getAttrByOid, getAttrByIndex. */




/*
 * FUNCTIONS ON pkcs12_KeyBag
 */

/* pkcs12_KeyBag pkcs12_KeyBag_new(): initializes a pkcs12_KeyBag object.
 * returns 0 on failure.
 */

extern
pkcs12_KeyBag
pkcs12_KeyBag_new();


/* disposes of a pkcs12_KeyBag */

extern
void
pkcs12_KeyBag_destroy(pkcs12_KeyBag victim);


/* Make a full copy of the pkcs12_KeyBag.
 *
 * Returns 0 on success, -1 on internal failure (failure to allocate memory), 
 * -2 in debug mode if passed any null parameters.
 */

extern
int
pkcs12_KeyBag_copy(pkcs12_KeyBag  original,
                   pkcs12_KeyBag *copy);



/*
 * Writing a pkcs12_KeyBag:
 */

/* Currently, keys are added to KeyBags in the format that bsapi uses.
 * Internally they are converted into PKCS#8 format. When they are
 * extracted, they are extracted in bsapi format. Future development
 * will include functions to add and extract PKCS#8 formatted keys.
 */

/* add a key to a KeyBag. This creates a copy of the data passed in. 
 *
 * Returns 0 on success; 1 if it doesn't recognise the pkcs12_KeyAlgId
 * passed in; 2 if the KeyBag specified already contains a key; -1 if
 * there has been an internal error (failure to allocate memory); -2
 * in debug mode if it's passed a null keyBag or key.
 *
 * The params field contains any shared parameters (eg the DSA "shrdpub"
 * parameters. It may never be necessary to use it. Most private key formats, 
 * and all the ones in the current CST, include the shared parameters within
 * the private key ut_mblk.
 */

extern
int
pkcs12_KeyBag_addKeyData(pkcs12_KeyBag    keyBag,
                         ut_mblk         *key,
                         ut_mblk         *params, 
                         pkcs12_KeyAlgId  algid);


/* Delete a key from a pkcs12_KeyBag and dispose of any associated
 * memory.
 *
 * Provided for completeness more than anything, though if you have a
 * template for producing pkcs12_objs it might be handy to repeatedly
 * remove keys and cert chains and replace them with others, writing out
 * in between times.
 *
 * This behaves differently from the previous pkcs12_XXX_remove
 * functions. A KeyBag can only contain one key, so there is no need to
 * specify which key. 
 *
 * Returns 0 on success, -1 on failure, 1 if the keyBag didn't contain
 * a key in the first place.
 */

extern
int
pkcs12_KeyBag_deleteKey(pkcs12_KeyBag keyBag);


/*
 * Reading a pkcs12_KeyBag:
 */

/* Retrieve a key from a KeyBag. On success, key.data will be newly allocated
 * and params.data may or may not be allocated; it will be 0 if it was not
 * allocated. algid will give the algorithm of the key.
 *
 * Returns 0 on success; 1 on failure (couldn't find key, or the
 * object was incorrectly ASN.1 encoded); -1 on internal error (couldn't
 * allocate memory); -2 in debug mode if passed a null keyBag, key * or
 * algid *.
 *
 * If we don't recognise the key alg id, we still return 0 for success
 * and put the key data, minus the BIT STRING header, in key.data;
 * however, algid is set to PKCS12_ALGID_UNSUP.
 */

extern
int
pkcs12_KeyBag_getKeyData(pkcs12_KeyBag     keyBag,
                         ut_mblk          *key,
                         ut_mblk          *params, 
                         pkcs12_KeyAlgId  *algid,
                         algid_objid      *oid);

/* Get the alg id for a stored key in a keyBag.
 *
 * Returns 0 on success; 1 if it couldn't parse the ASN.1; -2 in DEBUG
 * mode if passed a null keyBag or keyAlgId *. If it successfully parsed
 * the ASN.1 but couldn't recognise the key data it returns 0 and sets
 * algid = PKCS12_KEYALGID_UNSUP.
 */

extern
int
pkcs12_KeyBag_getKeyAlgId(pkcs12_KeyBag keyBag,
                          pkcs12_KeyAlgId *algid);




/*
 * FUNCTIONS ON pkcs12_ShroudedKeyBag:
 */

/* pkcs12_ShroudedKeyBag pkcs12_ShroudedKeyBag_new(): initializes a
 * pkcs12_ShroudedKeyBag object.
 * returns 0 on failure.
 */
extern
pkcs12_ShroudedKeyBag
pkcs12_ShroudedKeyBag_new();

/* disposes of a pkcs12_ShroudedKeyBag */
extern
void
pkcs12_ShroudedKeyBag_destroy(pkcs12_ShroudedKeyBag victim);


/* Make a full copy of the pkcs12_KeyBag.
 *
 * Returns 0 on success, -1 on internal failure (failure to allocate memory), 
 * -2 in debug mode if passed any null parameters.
 */

extern
int
pkcs12_ShroudedKeyBag_copy(pkcs12_ShroudedKeyBag  original,
                           pkcs12_ShroudedKeyBag *copy);


/* 
 * Writing a ShroudedKeyBag...
 */

/* Add a (non-encrypted) key to a ShroudedKeyBag. This creates a copy of
 * the data passed in.
 *
 * Returns 0 on success; 1 if it doesn't recognise the pkcs12_KeyAlgId
 * passed in; 2 if the ShroudedKeyBag specified already contains a key; -1 if
 * there has been an internal error (failure to allocate memory); -2
 * in debug mode if it's passed a null keyBag or key.
 *
 * The params field contains any shared parameters (eg the DSA "shrdpub"
 * parameters". It may never be necessary to use it. Most private key formats, 
 * and all the ones in the current CST, include the shared parameters within
 * the private key ut_mblk.
 */
extern
int
pkcs12_ShroudedKeyBag_addKey(pkcs12_ShroudedKeyBag  keyBag,
                             ut_mblk               *key,
                             ut_mblk               *params, 
                             pkcs12_KeyAlgId        algid);

/* Add a PKCS#8-encrypted key to a ShroudedKeyBag. This creates a copy of
 * the data passed in.
 *
 * Returns 0 on success; 2 if the ShroudedKeyBag specified already
 * contains a key; -1 if there has been an internal error (failure to
 * allocate memory); -2 in debug mode if it's passed a null keyBag or
 * key.
 * 
 * Note that the PKCS#8-encrypted key already includes the key algorithm
 * identifier, so there's no need for it to be included as a parameter.
 */
extern
int
pkcs12_ShroudedKeyBag_addPkcs8ShroudedKey(pkcs12_ShroudedKeyBag  keyBag,
                                          ut_mblk               *key);


/* Delete a key from a pkcs12_KeyBag and dispose of any associated
 * memory.
 *
 * Provided for completeness more than anything, though if you have a
 * template for producing pkcs12_objs it might be handy to repeatedly
 * remove keys and cert chains and replace them with others, writing out
 * in between times.
 *
 * This behaves differently from the previous pkcs12_XXX_remove
 * functions. A KeyBag can only contain one key, so there is no need to
 * specify which key. 
 *
 * Returns 0 on success, -1 on failure, 1 if the keyBag didn't contain
 * a key in the first place.
 */

extern
int
pkcs12_ShroudedKeyBag_deleteKey(pkcs12_ShroudedKeyBag keyBag);


/* encrypt a ShroudedKeyBag.
 * fails if already encrypted, or if no key present, or if it doesn't
 * recognise the algid of the key.
 * 
 * If pbeAlgId and iCount are both 0, we use the parameters that already
 * exist inside the ShroudedKeyBag.
 */
extern
int
pkcs12_ShroudedKeyBag_encrypt_ascii(pkcs12_ShroudedKeyBag  keyBag,
                                    ut_mblk               *passphrase,
                                    pkcs12_PbeAlgId        pbeAlgId,
                                    int                    iCount);

extern
int
pkcs12_ShroudedKeyBag_encrypt_unicode(pkcs12_ShroudedKeyBag  keyBag,
                                      ut_mblk               *passphrase,
                                      pkcs12_PbeAlgId        pbeAlgId,
                                      int                    iCount);

#ifndef _UNICODE
#define pkcs12_ShroudedKeyBag_encrypt(kb,pp,id,c) \
        pkcs12_ShroudedKeyBag_encrypt_ascii(kb,pp,id,c)
#else
#define pkcs12_ShroudedKeyBag_encrypt(kb,pp,id,c) \
        pkcs12_ShroudedKeyBag_encrypt_unicode(kb,pp,id,c)
#endif



/*
 * Reading from a ShroudedKeyBag...
 */

/* Decrypt the KeyBag. Must be done before you can do anything else. */

extern
int
pkcs12_ShroudedKeyBag_decrypt(pkcs12_ShroudedKeyBag  keyBag,
                              ut_mblk               *passphrase,
                              int                    passphraseIsAscii);


/* Get PBE Info from a pkcs12_ShroudedKeyBag. Must be called after
 * pkcs12_ShroudedKeyBag_decrypt().
 *
 * Allocates memory at aid.
 */

int
pkcs12_ShroudedKeyBag_getPbeInfo(pkcs12_ShroudedKeyBag  keyBag,
                                 algid_algid           *aid);


/* Retrieve a key from a pkcs12_ShroudedKeyBag. On success, key.data
 * will be newly allocated and params.data may or may not be allocated;
 * it will be 0 if it was not allocated. algid will give the algorithm
 * of the key.
 *
 * Returns 0 on success; 1 on failure (couldn't find key, or the
 * object was incorrectly ASN.1 encoded); -1 on internal error (couldn't
 * allocate memory); -2 in debug mode if passed a null keyBag, key * or
 * algid *.
 *
 * If we don't recognise the key alg id, we still return 0 for success
 * and put the key data, minus the BIT STRING header, in key.data;
 * however, algid is set to PKCS12_ALGID_UNSUP.
 */

extern
int
pkcs12_ShroudedKeyBag_getKeyData(pkcs12_ShroudedKeyBag  keyBag,
                             ut_mblk               *key,
                             ut_mblk               *params, 
                             pkcs12_KeyAlgId       *algid,
                             algid_objid           *oid);


/* Retrieve the shrouded key data from a pkcs12_ShroudedKeyBag. On
 * success, key.data will be newly allocated. The key data must be
 * passed on to some other PKCS#8 data handler to be decrypted.
 *
 * Returns 0 on success; 1 on failure (couldn't find key, or the
 * object was incorrectly ASN.1 encoded); -1 on internal error (couldn't
 * allocate memory); -2 in debug mode if passed a null keyBag, key * or
 * algid *.
 */

extern
int
pkcs12_ShroudedKeyBag_getShroudedKey(pkcs12_ShroudedKeyBag  keyBag,
                             ut_mblk               *key);

/* Remove the shrouded key data from a pkcs12_ShroudedKeyBag. 
 *
 * Returns 0 on success; 1 on failure (couldn't find key, or the
 * object was incorrectly ASN.1 encoded); -1 on internal error (couldn't
 * allocate memory); -2 in debug mode if passed a null keyBag, key * or
 * algid *.
 */


int
pkcs12_ShroudedKeyBag_removeShroudedKey(pkcs12_ShroudedKeyBag  keyBag,
                                     ut_mblk               *key);


/* Get the alg id for a stored key in a keyBag.
 *
 * Returns 0 on success; 1 if it couldn't parse the ASN.1; -2 in DEBUG
 * mode if passed a null keyBag or keyAlgId *. If it successfully parsed
 * the ASN.1 but couldn't recognise the key data it returns 0 and sets
 * algid = PKCS12_KEYALGID_UNSUP.
 */

extern
int
pkcs12_ShroudedKeyBag_getKeyAlgId(pkcs12_ShroudedKeyBag  keyBag,
                                  pkcs12_KeyAlgId       *algid);




/*
 * FUNCTIONS ON pkcs12_CertBag:
 */

/* pkcs12_CertBag pkcs12_CertBag(): initializes a
 * pkcs12_CertBag object.
 * returns 0 on failure.
 */
extern
pkcs12_CertBag
pkcs12_CertBag_new();

/* disposes of a pkcs12_CertBag */
extern
void
pkcs12_CertBag_destroy(pkcs12_CertBag victim);


/* Make a full copy of the pkcs12_CertBag.
 *
 * Returns 0 on success, -1 on internal failure (failure to allocate memory), 
 * -2 in debug mode if passed any null parameters.
 */

extern
int
pkcs12_CertBag_copy(pkcs12_CertBag  original,
                    pkcs12_CertBag *copy);


/* 
 * Writing a CertBag...
 */

/* A CertBag contains a single X.509 or SDSI certificate. For now, we
 * only support X.509 certs.
 */


/* Add a copy of the given data to the given CertBag. Note: a COPY, not
 * the original.
 *
 * Returns 0 on success, -1 on failure, 1 if the CertBag already has a
 * cert in it.
 */

extern
int
pkcs12_CertBag_addData(pkcs12_CertBag         certBag,
                       ut_mblk               *certData,
                       pkcs12_CertBagType     type);


/* Delete the certificate from a pkcs12_CertBag and dispose of any
 * associated memory.
 *
 * Returns 0 on success, -1 on failure, 1 if it couldn't find any
 * cert in the CertBag.
 */

extern
int
pkcs12_CertBag_deleteCert(pkcs12_CertBag  certBag);



/* 
 * Reading from a CertBag...
 */


/* Get a copy of the certificate. 
 *
 * The memory at cert.data must be deallocated.
 *
 * Returns 0 on success, -1 on failure (couldn't allocate memory). If
 * there are no certs in the certbag returns 0 but cert.data is 0 too.
 */

extern
int
pkcs12_CertBag_getCert(pkcs12_CertBag   certBag,
                       ut_mblk         *cert);


/* Reading in from file... */

/* pkcs12_berpkcs12obj2obj: read in a BER-encoded PKCS#12 object.
 *
 * Reads len bytes of data from src and puts them into the pkcs12_obj
 * object. Returns a pointer to the byte after the last byte read.
 *
 * If there's an internal failure, returns 0.
 *
 * If it reaches the end of the data, finished is set to 1. Otherwise,
 * finished is set to 0.
 */

u8 *
pkcs12_berpkcs12obj2obj(u8 *src,
                        size_t len,
                        pkcs12_obj object,
                        int *finished);


/* pkcs12_berpkcs12SafeContents2SafeContents: read in a BER-encoded
 * PKCS#12 SafeContents.
 *
 * Reads len bytes of data from src and puts them into the
 * pkcs12_SafeContents indicated. Returns a pointer to the byte after
 * the last byte read.
 *
 * If there's an internal failure, returns 0.
 *
 * If it reaches the end of the data, finished is set to 1. Otherwise,
 * finished is set to 0.
 */

u8 *
pkcs12_berpkcs12SafeContents2SafeContents(u8 *src,
                                          size_t len,
                                          pkcs12_SafeContents safeCon,
                                          int *finished);


/* pkcs12_berpkcs12SafeBag2SafeBag: read in a BER-encoded PKCS#12
 * SafeBag.
 *
 * Reads len bytes of data from src and puts them into the
 * pkcs12_SafeBag indicated. Returns a pointer to the byte after the
 * last byte read.
 *
 * If there's an internal failure, returns 0.
 *
 * If it reaches the end of the data, finished is set to 1. Otherwise,
 * finished is set to 0.
 */

u8 *
pkcs12_berpkcs12SafeBag2SafeBag(u8 *src,
                                size_t len,
                                pkcs12_SafeBag safeBag,
                                int *finished);


/* pkcs12_berpkcs12SafeBagContents2SafeBagContents: read in a
 * BER-encoded PKCS#12 SafeBagContents.
 *
 * Reads len bytes of data from src and puts them into the
 * pkcs12_SafeBagContents indicated. Returns a pointer to the byte after
 * the last byte read.
 *
 * If there's an internal failure, returns 0.
 *
 * If it reaches the end of the data, finished is set to 1. Otherwise,
 * finished is set to 0.
 */

u8 *
pkcs12_berpkcs12SafeBagContents2SafeBagContents(u8 *src,
                                             size_t len,
                                             pkcs12_SafeBagContents safeBagCon,
                                             int *finished);


/* pkcs12_berpkcs12KeyBag2KeyBag: read in a BER-encoded PKCS#12 KeyBag.
 *
 * Reads len bytes of data from src and puts them into the pkcs12_KeyBag
 * indicated. Returns a pointer to the byte after the last byte read.
 *
 * If there's an internal failure, returns 0.
 *
 * If it reaches the end of the data, finished is set to 1. Otherwise,
 * finished is set to 0.
 */

u8 *
pkcs12_berpkcs12KeyBag2KeyBag(u8 *src,
                              size_t len,
                              pkcs12_KeyBag keyBag,
                              int *finished);


/* pkcs12_berpkcs12ShroudedKeyBag2ShroudedKeyBag: read in a BER-encoded
 * PKCS#12 ShroudedKeyBag.
 *
 * Reads len bytes of data from src and puts them into the
 * pkcs12_ShroudedKeyBag indicated. Returns a pointer to the byte after
 * the last byte read.
 *
 * If there's an internal failure, returns 0.
 *
 * If it reaches the end of the data, finished is set to 1. Otherwise,
 * finished is set to 0.
 */

u8 *
pkcs12_berpkcs12ShroudedKeyBag2ShroudedKeyBag(u8 *src,
                        size_t len,
                        pkcs12_ShroudedKeyBag shKeybag,
                        int *finished);


/* pkcs12_berpkcs12CertBag2CertBag: read in a BER-encoded PKCS#12 CertBag.
 *
 * Reads len bytes of data from src and puts them into the
 * pkcs12_CertBag indicated. Returns a pointer to the byte after the
 * last byte read.
 *
 * If there's an internal failure, returns 0.
 *
 * If it reaches the end of the data, finished is set to 1. Otherwise,
 * finished is set to 0.
 */

u8 *
pkcs12_berpkcs12CertBag2CertBag(u8 *src,
                                size_t len,
                                pkcs12_CertBag certBag,
                                int *finished);




extern
size_t 
pkcs12_ShroudedKeyBag_sizeof2ber(pkcs12_ShroudedKeyBag  kBag);

extern
u8 *
pkcs12_ShroudedKeyBag_2ber(pkcs12_ShroudedKeyBag   kBag,
                           u8                     *dest);

extern
u8 *
pkcs12_ShroudedKeyBag_ber2obj(pkcs12_ShroudedKeyBag  kBag,
                              u8                    *src);




extern
size_t 
pkcs12_KeyBag_sizeof2ber(pkcs12_KeyBag  kBag);

extern
u8 *
pkcs12_KeyBag_2ber(pkcs12_KeyBag   kBag,
                   u8             *dest);

extern
u8 *
pkcs12_KeyBag_ber2obj(pkcs12_KeyBag  kBag,
                      u8            *src);



extern
size_t 
pkcs12_CertBag_sizeof2ber(pkcs12_CertBag  cBag);

extern
u8 *
pkcs12_CertBag_2ber(pkcs12_CertBag   cBag,
                    u8              *dest);

extern
u8 *
pkcs12_CertBag_ber2obj(pkcs12_CertBag  cBag,
                       u8             *src);

#ifdef __cplusplus
}
#endif

#endif /* ndef _CST_PKCS12_H */
