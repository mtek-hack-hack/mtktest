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

#ifndef _ASN1_H /* Prevent multiple inclusion */
#define _ASN1_H

/** Includes **/

/*Removed by ANAO 29/3-2001 #include "stdlib.h"*/     /* For size_t */

/*Removed by JAK 28/2-2001	#include "sys/types.h"*/
/*loko#include "string.h"*/
#include "ut.h"         /* For u32, ut_mblk, u8, & utb */
#include "asnconv.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** Errors **/

#define ASN1_EBASE (0x01000000) /* Module code */

#define ASN1_ENOMEM (ASN1_EBASE + 0x40000) /* Unable to allocate %d bytes" */
#define ASN1_ECERTF (ASN1_EBASE + 0x40100) /* Unable to allocate certificate */
#define ASN1_ECOPYF (ASN1_EBASE + 0x40200) /* Unable to copy %s */
#define ASN1_ESETFL (ASN1_EBASE + 0x40300) /* Unable to set %s */
#define ASN1_EA1ERR (ASN1_EBASE + 0x40400) /* ASN.1 error:     %s */
#define ASN1_EKGENF (ASN1_EBASE + 0x40600) /* Unable to generate keys */
#define ASN1_EHASHF (ASN1_EBASE + 0x40700) /* Unable to hash certificate */
#define ASN1_ESIGNF (ASN1_EBASE + 0x40800) /* Unable to sign certificate */
#define ASN1_EVRFYF (ASN1_EBASE + 0x40900) /* Unable to verify certificate */
#define ASN1_EOPENF (ASN1_EBASE + 0x40a00) /* Unable to open file %s */
#define ASN1_EREADF (ASN1_EBASE + 0x40b00) /* Unable to read file %s */
#define ASN1_EWRITE (ASN1_EBASE + 0x40c00) /* Unable to write file %s */
#define ASN1_EPARAM (ASN1_EBASE + 0x40d00) /* FAIL/ABORT Bad parameters */
#define ASN1_EBADOB (ASN1_EBASE + 0x40e00) /* Unrecognized object */
#define ASN1_EBADEX (ASN1_EBASE + 0x40f00) /* Bad extension */
#define ASN1_EUNEXT (ASN1_EBASE + 0x41000) /* Unknown extension */
#define ASN1_ETIME  (ASN1_EBASE + 0x41100) /* Trouble with time conversions */

/* Type:        <asn1_asn1type>
 * Summary:     ASN.1 types supported in CST
 */
typedef u32 asn1_asn1type;

#define ASN1_UNIV (0L)
#define ASN1_APPL (0x40000000L)
#define ASN1_CONT (0x80000000L)
#define ASN1_PRIV (0xc0000000L)
#define ASN1_CONS (0x20000000L)
  
#define asn_tval(x) ((x) & 0x1fffffffL)
#define asn_class(x) ((x) & ASN1_PRIV)

#define asn_is_univ(x) (!asn_class(x))
#define asn_is_appl(x) (asn_class(x) == ASN1_APPL)
#define asn_is_cont(x) (asn_class(x) == ASN1_CONT)
#define asn_is_priv(x) (asn_class(x) == ASN1_PRIV)
#define asn_is_cons(x) ((x) & ASN1_CONS)
#define asn_is_prim(x) (!asn_is_cons(x))

#define asn_univ(x) ((x) & ~ASN1_PRIV)
#define asn_appl(x) (((x) & ~ASN1_PRIV) | ASN1_APPL)
#define asn_cont(x) (((x) & ~ASN1_PRIV) | ASN1_CONT)
#define asn_priv(x) ((x) | ASN1_PRIV)
#define asn_cons(x) ((x) | ASN1_CONS)
#define asn_prim(x) ((x) & ~ASN1_CONS)

/* The universal types */

#define ASN1_UNKNOWN        (0x0UL)  /* suitable return value for failure */
#define ASN1_BOOL           (0x1UL)  /* boolean type. Use 0xff for true */
#define ASN1_INTEGER        (0x2UL)  /* Integer - an s32, an mpm_arc, .. */
#define ASN1_BITSTRING      (0x3UL)  /* Bit string - usually ut_mblk */
#define ASN1_OCTETSTRING    (0x4UL)  /* Octet string - usually ut_mblk */
#define ASN1_NULL           (0x5UL)  /* A null (usually means no parameters) */
#define ASN1_OBJECTID       (0x6UL)  /* An object ID, complicated */
#define ASN1_OBJECTDESC     (0x7UL)  /* An object descriptor, rare */
#define ASN1_EXTERNAL       (0x8UL)  /* The external type, rare */  
#define ASN1_REAL           (0x9UL)  /* The real type. Complicated encoding! */
#define ASN1_ENUMERATED    (0x0aUL)  /* The enumerated type */
#define ASN1_UTF8STRING    (0x0cUL)  /* UTF-8 string */
#define ASN1_SEQUENCE_PR   (0x10UL)  /* Sequence */
#define ASN1_SET_PR        (0x11UL)  /* Set */
#define ASN1_NUMERIC       (0x12UL)  /* As the name implies, a numeric string */
#define ASN1_PRINTSTRING   (0x13UL)  /* A printable string, often mblk */
#define ASN1_T61STRING     (0x14UL)  /* teletext string */
#define ASN1_VIDEOTEX      (0x15UL)  /* The videotex string type */
#define ASN1_IA5           (0x16UL)  /* used for dns/url/email strings */
#define ASN1_TIME          (0x17UL)  /* UTC time */
#define ASN1_GENERALTIME   (0x18UL)  /* Basically, TIME + century */
#define ASN1_GRAPHIC       (0x19UL)  /* a generalized graphical string */
#define ASN1_VISIBLE       (0x1aUL)  /* implied by the name */
#define ASN1_GENERALSTRING (0x1bUL)  /* A generalized string type */
#define ASN1_UNISTR        (0x1cUL)  /* Universal (4-byte) characters */
#define ASN1_BMPSTRING     (0x1eUL)  /* BMP (2-byte), unicode */

#define ASN1_BAD_TAG      (~0L)      /* indicates failed decode */
#define ASN1_VALID (0x2fff8bffL)     /* fortunately < 32 universal types */
  
#define ASN1_SEQUENCE (asn_cons(ASN1_SEQUENCE_PR)) /* always cons */
#define ASN1_SET (asn_cons(ASN1_SET_PR))           /* always cons */
  
#define asn_cmp_univ(x,y) (asn_is_univ(x) && asn_tval(x) == asn_tval(y))


/* Function:    <asn1_sizeof_type>
 * Summary:     Gets the size of an entire DER-encoded type.
 * Syntax:      off_t rval = asn1_sizeof_type(off_t len, asn1_asn1type t);
 * Description: The asn1_sizeof_type() function returns the number of octets 
 *              of memory necessary to store len octets of data as the ASN.1
 *              type atype.
 * Memory:      This function allocates no memory.
 * Notes:       This function was a macro in CST v7.2 and earlier.
 */
extern sec_off_t
asn1_sizeof_type(sec_off_t l, asn1_asn1type t);


/* Function:    <asn1_sizeof_sizetype2bertaglen>
 * Summary:     Gets the size of the DER-encoded tag and length for an
 *              ASN.1 object.
 * Syntax:      off_t rval = asn1_sizeof_sizetype2bertaglen(off_t len,
 *                asn1_asn1type type);
 * Description: The asn1_sizeof_sizetype2bertaglen() function returns the 
 *              number of octets of memory needed to store the BER encoding
 *              of the header data type and len. It inherits errors from 
 *              asn1_sizeof_type2bertag() and asn1_sizeof_size2berlen().              
 * Memory:      This function allocates no memory.
 * Notes:       Usually, you can call asn1_sizeof_type() instead.
 */
#define asn1_sizeof_sizetype2bertaglen(l, t) \
  (asn1_sizeof_size2berlen(l) + asn1_sizeof_type2bertag(t))

/* Function:    <asn1_sizetype2bertaglen>
 * Summary:     DER-encodes an ASN.1 type and length and writes to a buffer.
 * Syntax:      result = asn1_sizetype2bertaglen(off_t len, 
 *                asn1_asn1type atype, u8 *dest);
 * Description: The asn1_sizetype2bertaglen() function DER-encodes the
 *              ASN.1 type header information in atype and len and writes
 *              them to dest. At least asn1_sizeof_sizetype2bertaglen() (and
 *              usually asn1_sizeof_type()) octets must have been allocated
 *              at dest.
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              only by null parameters in debug mode).
 * Notes:       This function is actually a macro.
 */
#define asn1_sizetype2bertaglen(l, t, d) \
  (asn1_size2berlen(l,asn1_type2bertag(t,d)))

/* Function:    <asn1_bertaglen2typesize>
 * Summary:     Reads a DER-encoded length and tag from a buffer.
 * Syntax:      u8 *asn1_bertaglen2typesize(u8 *src, asn1_asn1type *atype,
 *                off_t *len);
 * Description: The asn1_bertaglen2typesize() function reads BER-encoded
 *              ASN.1 type header information from src and stores the
 *              type in atype and the length in len.
 *
 *              If the data being read is indefinite-length encoded, len
 *              will be -1.
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if the data
 *              at src cannot be interpreted as BER-encoded header data,
 *              or (in debug mode) if src or len is NULL.
 * Memory:      This function allocates no memory.
 * Notes:       This function is actually a macro.
 */
#define asn1_bertaglen2typesize(s, t, l) \
  (asn1_berlen2size(asn1_bertag2type((s),(t)), (l)))


/* Function:    <asn1_bertaglentype2size>
 * Summary:     Reads a DER-encoded length from a buffer and checks the tag.
 * Syntax:      u8 *asn1_bertaglentype2size(u8 *src, asn1_asn1type atype,
 *                off_t *len);
 * Description: The asn1_bertaglentype2size() function reads BER-encoded
 *              ASN.1 type header information from src. If the tag is of
 *              ASN.1 type atype, it reads the length into len by calling
 *              asn1_berlen2size().
 *
 *              If the data being read is indefinite-length encoded, len
 *              will be -1.
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if the data
 *              at src cannot be interpreted as BER-encoded header data,
 *              if the tag on the data is not of type atype, or (in debug 
 *              mode) if src or len is NULL.
 * Memory:      This function allocates no memory.
 */
extern u8 *
asn1_bertaglentype2size(u8 *src, asn1_asn1type atype, sec_off_t *len);


/* Function:    <asn1_stream_bertaglentype2size>
 * Summary:     Reads a DER-encoded length from a stream and checks the tag.
 * Syntax:      int rval = asn1_stream_bertaglentype2size (int
 *                (*stre)(void *), void *par, asn1_asn1type atype, off_t *len);
 * Description: The asn1_stream_bertaglen2typesize() function reads 
 *              BER-encoded ASN.1 type header information from stre().
 *              If the tag is of ASN.1 type atype, it reads the length
 *              into len (by calling asn1_berlen2size()).
 *
 *              If the data being read is indefinite-length encoded, len
 *              will be -1.
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Returns:     This function returns 0 on success or -1 on failure
 *              (stre couldn't read from params, tag didn't correspond
 *              to an ASN.1 tag or len wasn't an ASN.1 encoded length).
 * Memory:      This function allocates no memory.
 */
extern int
asn1_stream_bertaglentype2size (int (*stre)(void *), void *par, 
    asn1_asn1type atype, sec_off_t *len);


/* Function:    <asn1_stream_bertaglen2typesize>
 * Summary:     Reads a DER-encoded length and tag from a stream.
 * Syntax:      int rval = asn1_stream_bertaglen2typesize (int
 *                (*stre)(void *), void *par, asn1_asn1type *atype, off_t *len);
 * Description: The asn1_stream_bertaglen2typesize() function reads 
 *              BER-encoded ASN.1 type header information from stre().
 *              If the tag is of ASN.1 type atype, it reads the length
 *              into len by calling asn1_berlen2size().
 *
 *              If the data being read is indefinite-length encoded, len
 *              will be -1.
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Returns:     This function returns 0 on success or -1 on failure
 *              (stre couldn't read from params, tag didn't correspond
 *              to atype or len wasn't an ASN.1 encoded length).
 * Memory:      This function allocates no memory.
 */
extern int
asn1_stream_bertaglen2typesize (int (*stre)(void *), void *par, 
    asn1_asn1type *atype, sec_off_t *len);


/* Function:    <asn1_sizeof_type2bertag>
 * Summary:     Gets the size of a DER-encoded ASN.1 type tag.
 * Syntax:      off_t rval = asn1_sizeof_type2bertag(asn1_asn1type atype);
 * Description: The asn1_sizeof_type2bertag() function returns the number of
 *              octets of memory necessary to store the DER-encoded type tag
 *              for the indicated atype, or 0 if atype is an unrecognized
 *              type.
 * Memory:      This function allocates no memory.
 */
extern sec_off_t 
CST32EXPORTTYPE CST16EXPORTTYPE
asn1_sizeof_type2bertag(asn1_asn1type type);

/* Function:    <asn1_type2bertag>
 * Summary:     Writes a DER-encoded ASN.1 type tag to a buffer.
 * Syntax:      u8 * rval = asn1_type2bertag(asn1_asn1type atype, u8 *dest);
 * Description: The asn1_type2bertag() function DER-encodes the indicated atype
 *              and writes the result to dest. At least 
 *              asn1_sizeof_type2bertag() octets of memory must have been
 *              allocated at dest.
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              by null parameters in debug mode, or unrecognized atype).
 * Memory:      This function allocates no memory.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_type2bertag(asn1_asn1type type, u8 *dest);

/* Function:    <asn1_bertag2type>
 * Summary:     Reads a DER-encoded ASN.1 type tag from a buffer.
 * Syntax:      u8 * rval = asn1_bertag2type(u8 *src, asn1_asn1type *atype);
 * Description: The asn1_berenum2enum() function reads a DER-encoded ASN.1
 *              type tag from src and writes the value to atype.
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if src could
 *              not be parsed.  No attempt is made to find the end of an
 *              unrecognized tag.
 * Memory:      This function allocates no memory.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_bertag2type(u8 *src, asn1_asn1type *type);

/* Function:    <asn1_qbertag2type>
 * Summary:     Reads a DER-encoded ASN.1 type tag from a buffer, without
 *              calling ut_logX() on failure.
 * Syntax:      u8 * rval = asn1_qbertag2type(u8 *src, asn1_asn1type *type);
 * Description: The asn1_qbertag2type() function is exactly the same as
 *              asn1_bertag2type(), except that it doesn't call ut__log() if
 *              it encounters an error.
 * Memory:      This function allocates no memory.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_qbertag2type(u8 *src, asn1_asn1type *type);

/* Function:    <asn1_stream_bertag2type>
 * Summary:     Reads a DER-encoded tag from a stream.
 * Syntax:      asn1_asn1type rval = asn1_stream_bertag2type(int
 *                (*stre)(void *), void *param); 
 * Description: The asn1_stream_bertag2type() function reads an ASN.1
 *              tag from stre and returns it in rval. If the data being
 *              read by stre does not start with a valid BER tag, the
 *              function returns ASN1_UNKNOWN.
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Memory:      This function allocates no memory.
 * Example:     The following code gives an example of the use of this
 *              function.
 *           (code)
 *              int streamfunc(void *fp)
 *              {
 *                u8 tmp;
 *                if(!(fread(&tmp, sizeof (u8), 1, (FILE *)fp)))
 *                  return -1;
 *                return (int) tmp;
 *              }
 *              ...
 *              FILE *fp = fopen ("asn1.dat", "wb");
 *              asn1_asn1type atype =
 *                asn1_stream_bertag2type(streamfunc, (void *)fp);
 *              if (atype == UT_UNKNOWN) {
 *                // handle error
 *              }
 *           (/code)
 */
extern asn1_asn1type
asn1_stream_bertag2type(int (*stre)(void *), void *param);

/* Function:    <asn1_sizeof_size2berlen>
 * Summary:     Gets the length of the DER-encoded length of an ASN.1 object.
 * Syntax:      off_t rval = asn1_sizeof_size2berlen(off_t size);
 * Description: The asn1_sizeof_size2berlen() function returns the number of
 *              octets of memory necessary to store size as a DER length
 *              header tag.
 *
 *              The function aborts if an attempt is made to encode a size 
 *              larger than 0xffffffff.
 * Memory:      This function allocates no memory.
 */
extern sec_off_t 
CST32EXPORTTYPE CST16EXPORTTYPE
asn1_sizeof_size2berlen(sec_off_t size);


/* Function:    <asn1_size2berlen>
 * Summary:     Writes the DER-encoded length of an ASN.1 object to a buffer.
 * Syntax:      u8 * rval = asn1_size2berlen(off_t size, u8 *dest);
 * Description: The asn1_size2berlen() function DER-encodes the indicated size
 *              as a length header tag and writes the result to dest. At least 
 *              asn1_sizeof_size2berlen() octets of memory must have been
 *              allocated at dest.
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              by null parameters in debug mode). It aborts if an attempt is 
 *              made to encode a size larger than 0xffffffffff.
 * Memory:      This function allocates no memory.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_size2berlen(sec_off_t size, u8 *dest);


/* Function:    <asn1_size2paddedberlen>
 * Summary:     Writes the DER-encoded length of an ASN.1 object using a
 *              given number of octets.
 * Syntax:      u8 * rval = asn1_size2paddedberlen(off_t size, u8 *dest,
 *                off_t noctets);
 * Description: The asn1_size2paddedberlen() function BER-encodes the 
 *              indicated size and writes the result to dest. The encoded 
 *              size is exactly noctets in length; it is padded if necessary 
 *              in accordance with the BER.
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              by null parameters in debug mode). It aborts in debug mode
 *              if an attempt is made to encode a size larger than that 
 *              permitted by noctets or if noctets is too large.
 * Memory:      This function allocates no memory.
 */
u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_size2paddedberlen(sec_off_t size, u8 *dest, sec_off_t noctets);

/* Function:    <asn1_berlen2size>
 * Summary:     Reads a BER-encoded length from a buffer.
 * Syntax:      u8 * rval = asn1_berlen2size(u8 *src, off_t *len);
 * Description: The asn1_berlen2size() function reads a BER-encoded
 *              length from a src and stores the result in len. This
 *              will be the length of the data octets, starting after
 *              the last byte of the length octets.
 *
 *              If the data being read is indefinite-length encoded, len
 *              will be -1.
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if the data
 *              at src cannot be interpreted as a DER-encoded length tag, 
 *              or (in debug mode) if src or len is NULL.
 * Memory:      This function allocates no memory.
 * Notes:       This function is actually a macro.
 */
#define asn1_berlen2size(s, l) \
  ((*s == 0x80)?(*l = -1,s+1):    asn1_innerberlen2size(s, l))

/* Function:    <asn1_stream_berlen2size>
 * Summary:     Reads the DER-encoded length of an object from a stream.
 * Syntax:      off_t rval = asn1_stream_berlen2size(int (*stre)(void *),
 *                void *para); 
 * Description: The asn1_stream_bertag2type() function reads a BER-encoded 
 *              length from stre and returns it in rval. The function stre
 *              is a streamer function that takes a single parameter,
 *              param. It reads from the location specified in param and
 *              returns a single byte as an int. If the data being read by 
 *              stre does not start with a valid BER-encoded length, 
 *              asn1_stream_berlen2size() returns 0 (this can also
 *              indicate a correctly encoded zero-length data field). If
 *              the data is indefinite-length encoded, the function
 *              returns -1.
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Memory:      This function allocates no memory.
 */
extern sec_off_t 
asn1_stream_berlen2size(int (*stre)(void *), void *para);

/* Function:    <asn1_sizeof_mblk2beroctetstring>
 * Summary:     Gets the length of a ut_mblk, DER-encoded as an OCTET STRING.
 * Syntax:      off_t rval = asn1_sizeof_mblk2beroctetstring(ut_mblk mem);
 * Description: The asn1_sizeof_mblk2beroctetstring() function returns the 
 *              number of octets of memory needed to store mem.used octets of
 *              data as a DER-encoded ASN.1 OCTET STRING type.
 *
 *              It aborts in debug mode if the ut_mblk is suspicious-looking 
 *              (no data, 0 size or mem.used larger than mem.size).
 * Memory:      This function allocates no memory.
 */
extern sec_off_t 
CST32EXPORTTYPE CST16EXPORTTYPE
asn1_sizeof_mblk2beroctetstring(ut_mblk mem);


/* Function:    <asn1_mblk2beroctetstring>
 * Summary:     DER-encodes the data field of a ut_mblk as an OCTET STRING.
 * Syntax:      u8 * rval = asn1_mblk2beroctetstring(ut_mblk mem, u8 *dest);
 * Description: The asn1_mblk2beroctetstring() function DER-encodes mem.data
 *              as an ASN.1 OCTET STRING type of length mem.used and writes 
 *              the result to dest. At least asn1_sizeof_mblk2beroctetstring()
 *              octets of memory must have been allocated at dest.              
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              by suspicious-looking parameters in debug mode: no data,
 *              0 size, or mem.used larger than mem.size).
 * Memory:      This function allocates no memory.      
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_mblk2beroctetstring(ut_mblk mem, u8 *dest);

/* Function:    <asn1_beroctetstring2mblk>
 * Summary:     Reads a DER-encoded OCTET STRING from a buffer into a ut_mblk.
 * Syntax:      u8 * rval = asn1_beroctetstring2mblk(u8 *src, ut_mblk *mem);
 * Description: The asn1_beroctetstring2mblk() function reads a DER-encoded
 *              ASN.1 OCTET STRING from src, writes the data to mem->data and
 *              writes the length of the data to mem->size and mem->used.
 *              It allocates memory at mem->data using ut_ensure_mem(), so if
 *              there is no memory at mem->data on input, it must be 
 *              initialized to 0.
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if the data
 *              at src is not a DER-encoded OCTET STRING type, if there were
 *              memory allocation problems, or (in debug mode) if src or mem 
 *              is NULL.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(mem->data);
 *           (/code)
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_beroctetstring2mblk(u8 *src, ut_mblk *mem);


/* Function:    <asn1_stream_beroctetstring2mblk>
 * Summary:     Reads a DER-encoded OCTET STRING from a stream into a ut_mblk.
 * Syntax:      int rval = asn1_stream_beroctetstring2mblk(int (*stre)(void *),
 *                void *par, ut_mblk *mem);
 * Description: The asn1_stream_beroctetstring2mblk() function reads a 
 *              DER-encoded ASN.1 OCTET STRING from stre, writes the
 *              data to mem->data and writes the length of the data to
 *              mem->size and mem->used. It allocates memory at
 *              mem->data using ut_ensure_mem(), so if there is no
 *              memory at mem->data on input, it must be initialized to
 *              0.
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Returns      This function returns 0 on success or -1 on failure.
 *              It fails if stre couldn't read from params, if the data
 *              at src is not a DER-encoded OCTET STRING type, if there
 *              were memory allocation problems, or (in debug mode) if
 *              src or mem is NULL.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(mem->data);
 *           (/code)
 */
extern int
asn1_stream_beroctetstring2mblk(int (*stre)(void *), void *par, ut_mblk *mem);

/* Function:    <asn1_sizeof_mblk2berbitstring>
 * Summary:     Gets the length of a ut_mblk, DER-encoded as a BIT STRING.
 * Syntax:      off_t rval = asn1_sizeof_mblk2berbitstring(ut_mblk mem);
 * Description: The asn1_sizeof_mblk2berbitstring() function returns the 
 *              number of octets of memory needed to store mem.used octets of
 *              data as a DER-encoded ASN.1 BIT STRING type.
 *
 *              It aborts in debug mode if the mblk is suspicious-looking (no
 *              data, 0 size, or used larger than size).
 * Memory:      This function allocates no memory.
 */
extern sec_off_t 
CST32EXPORTTYPE CST16EXPORTTYPE
asn1_sizeof_mblk2berbitstring(ut_mblk mem);

/* Function:    <asn1_mblk2berbitstring>
 * Summary:     DER-encodes the data field of a ut_mblk as a BIT STRING.
 * Syntax:      u8 * rval = asn1_mblk2berbitstring(ut_mblk mem, u8 *dest);
 * Description: The asn1_mblk2berbitstring() function DER-encodes mem.data
 *              as an ASN.1 BIT STRING type of length mem.used and writes 
 *              the result to dest. At least asn1_sizeof_mblk2berbitstring()
 *              octets of memory must have been allocated at dest.
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              by suspicious-looking parameters in debug mode: no data,
 *              0 size or mem.used larger than mem.size).
 * Memory:      This function allocates no memory.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_mblk2berbitstring(ut_mblk mem, u8 *dest);


/* Function:    <asn1_berbitstring2mblk>
 * Summary:     Reads a DER-encoded BIT STRING and puts it in a ut_mblk.
 * Syntax:      u8 * rval = asn1_berbitstring2mblk(u8 *src, ut_mblk *mem);
 * Description: The asn1_berbitstring2mblk() function reads a DER-encoded
 *              ASN.1 BIT STRING from src, writes the data to mem->data and
 *              writes the length of the data to mem->size and mem->used.
 *              It allocates memory at mem->data using ut_ensure_mem(), so if
 *              there is no memory at mem->data on input, it must be 
 *              initialized to 0.
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if the data
 *              at src is not a DER-encoded BIT STRING type, if there were
 *              memory allocation problems or (in debug mode) if src or mem 
 *              is NULL.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(mem->data);
 *           (/code)
 * Notes:       This function expects the bit string to occupy an integral
 *              number of octets (as written by asn1_mblk2berbitstring()).
 *              This defeats the purpose of bit strings, but many standards use
 *              bit strings in this way.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_berbitstring2mblk(u8 *src, ut_mblk *mem);


/* Function:    <asn1_stream_berbitstring2mblk>
 * Summary:     Reads a DER-encoded BIT STRING from a stream into a ut_mblk.
 * Syntax:      int rval = asn1_stream_berbitstring2mblk(int (*stre)(void *),
 *                void *par, ut_mblk *mem);
 * Description: The asn1_stream_berbitstring2mblk() function reads a 
 *              DER-encoded ASN.1 BIT STRING from stre, writes the
 *              data to mem->data and writes the length of the data to
 *              mem->size and mem->used. It allocates memory at
 *              mem->data using ut_ensure_mem(), so if there is no
 *              memory at mem->data on input, it must be initialized to
 *              0.             
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Returns:     This function returns 0 on success or -1 on failure.
 *              It fails if stre couldn't read from params, if the data
 *              at src is not a DER-encoded BIT STRING type, if there
 *              were memory allocation problems or (in debug mode) if
 *              src or mem is NULL.
 * Memory:      Dispose of the memory allocated by this function
 *              as follows:
 *           (code)
 *              ut_dispose_mem(mem->data);
 *           (/code)
 */
extern int
asn1_stream_berbitstring2mblk(int (*stre)(void *), void *par, ut_mblk *mem);


/* Function:    <asn1_sizeof_s322berinteger>
 * Summary:     Gets the size of an s32 as a DER-encoded INTEGER.
 * Syntax:      off_t rval = asn1_sizeof_s322berinteger(s32 num);
 * Description: The asn1_sizeof_s322berinteger() function returns the number
 *              of octets of memory needed to store num as as ASN.1 INTEGER
 *              type.
 *
 *              It aborts if num is outside the range [-2147483648,
 *              +2147483647].
 * Memory:      This function allocates no memory.
 */
extern sec_off_t 
CST32EXPORTTYPE CST16EXPORTTYPE
asn1_sizeof_s322berinteger(s32 num);


/* Function:    <asn1_s322berinteger>
 * Summary:     DER-encodes an s32 as an INTEGER.
 * Syntax:      u8 * rval = asn1_s322berinteger(s32 num, u8 *dest);
 * Description: The asn1_s322berinteger() function DER-encodes the 
 *              indicated num and writes the result to dest. At least 
 *              asn1_sizeof_s322berinteger() octets of memory must have been
 *              allocated at dest.
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              by null parameters in debug mode or num outside the range 
 *              [-2147483648, +2147483647].
 * Memory:      This function allocates no memory.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_s322berinteger(s32 num, u8 *dest);

/* Function:    <asn1_berinteger2s32>
 * Summary:     Reads a short DER-encoded integer from a buffer.
 * Syntax:      u8 * rval = asn1_berinteger2s32(u8 *src, s32 *num);
 * Description: The asn1_berenum2enum() function reads a DER-encoded ASN.1
 *              INTEGER type from src and writes the value to num.
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if the data
 *              at src is not a DER-encoded INTEGER type, if the encoded
 *              INTEGER is outside the range [-2147483648, +2147483647] or
 *              (in debug mode) if src or num is NULL.
 * Memory:      This function allocates no memory.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_berinteger2s32(u8 *src, s32 *num);

/* Function:    <asn1_stream_berinteger2s32>
 * Summary:     Reads a short DER-encoded integer from a stream.
 * Syntax:      int rval = asn1_stream_berinteger2s32(int (*stre)(void *), 
 *                void *par, s32 *num);
 * Description: The asn1_stream_berinteger2s32() function reads a
 *              DER-encoded ASN.1 INTEGER type from stre and writes the
 *              value to num.
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Returns:     This function returns 0 on success or -1 on failure.
 *              It fails if stre couldn't read from params, if the data
 *              at src is not a DER-encoded INTEGER type, if the encoded
 *              INTEGER is outside the range [-2147483648, +2147483647],
 *              if there were memory allocation problems or (in debug
 *              mode) if num is NULL.
 * Memory:      This function allocates no memory.
 */
extern int
asn1_stream_berinteger2s32(int (*stre)(void *), void *par, s32 *num);

/* Function:    <asn1_sizeof_u322berbitstring>
 * Summary:     Gets the size of an integer encoded as a BIT STRING.
 * Syntax:      off_t rval = asn1_sizeof_u322berbitstring(u32 data); 
 * Description: The asn1_sizeof_u322berbitstring() function returns the
 *              number of octets of memory necessary to hold the BER encoding
 *              of data.
 * Memory:      This function allocates no memory.
 */
extern sec_off_t asn1_sizeof_u322berbitstring(u32 data);

/* Function:    <asn1_u322berbitstring>
 * Summary:     DER-encodes an integer as a BIT STRING.
 * Syntax:      u8 *rval = asn1_u322berbitstring(u32 data, u8 *dest); 
 * Description: The asn1_u322berbitstring() function DER-encodes data
 *              as an ASN.1 type BIT STRING and writes it to dest.
 *              At least asn1_sizeof_u322berbitstring octets of memory
 *              must have been allocated at dest.
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              only by null parameters in debug mode).
 * Memory:      This function allocates no memory.
 */
extern u8 *asn1_u322berbitstring(u32 data, u8 *dest);

/* Function:    <asn1_berbitstring2u32>
 * Summary:     Reads a DER-encoded bit string from a buffer into an integer.
 * Syntax:      u8 *rval = asn1_berbitstring2u32(u8 *s, u32 *u); 
 * Description: The *asn1_berbitstring2u32() function reads a DER-encoded
 *              BIT STRING from s and writes the value as an unsigned long
 *              into u. 
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if s does
 *              not point to a BIT STRING type, if the BIT STRING pointed to
 *              is too long to store in an unsigned long or (in debug mode)
 *              if s or u is NULL.
 * Memory:      This function allocates no memory.
 */
extern u8 *
asn1_berbitstring2u32(u8 *s, u32 *u);

/* Function:    <asn1_stream_berbitstring2u32>
 * Summary:     Reads a DER-encoded bit string from a stream into an integer.
 * Syntax:      int rval = asn1_stream_berbitstring2u32(int (*stre)(void *), 
 *                void *par, u32 *num);
 * Description: The asn1_stream_berbitstring2u32() function reads a
 *              DER-encoded ASN.1 BIT STRING type from stre and writes the
 *              value as an unsigned long into num.
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Returns:     This function returns 0 on success or -1 on failure.
 *              It fails if stre couldn't read from params, if s does
 *              not point to a BIT STRING type, if the BIT STRING pointed to
 *              is too long to store in an unsigned long, if the encoded
 *              INTEGER is outside the range [-2147483648, +2147483647],
 *              if there were memory allocation problems or (in debug
 *              mode) if num is NULL.
 * Memory:      This function allocates no memory.
 */
extern int
asn1_stream_berbitstring2u32(int (*stre)(void *), void *par, u32 *num);

/* Function:    <asn1_sizeof_enum2berenum>
 * Summary:     Gets the size of a DER-encoded enum.
 * Syntax:      off_t rval = asn1_sizeof_enum2berenum(int enm); 
 * Description: The asn1_sizeof_enum2berenum() function returns the number of
 *              octets of memory necessary to hold enm as a DER-encoded ASN.1
 *              ENUMERATED type.
 * Memory:      This function allocates no memory.
 * Example:     The following code gives an example of the use of this
 *              function.
 */
extern sec_off_t asn1_sizeof_enum2berenum(int enm);


/* Function:    <asn1_enum2berenum>
 * Summary:     DER-encodes an enum and writes to a buffer.
 * Syntax:      u8 *rval = asn1_enum2berenum(int enm, u8 *dest); 
 * Description: The asn1_enum2berenum() function DER-encodes enm as an ASN.1
 *              ENUMERATED type and writes the result to dest. At least 
 *              asn1_sizeof_enum2berenum() octets of memory must have been
 *              allocated at dest.
 * Returns:     The function returns a pointer to the octet after the
 *              last octet written on success or 0 on failure (caused
 *              only by null parameters in debug mode).
 * Memory:      This function allocates no memory.
 */
extern u8 *asn1_enum2berenum(int enm, u8 *dest);


/* Function:    <asn1_berenum2enum>
 * Summary:     Reads a DER-encoded enum from a buffer.
 * Syntax:      u8 * rval = asn1_berenum2enum(u8 *src, int *enm);
 * Description: The asn1_berenum2enum() function reads a DER-encoded ASN.1
 *              ENUMERATED type from src and writes the value to enm.
 * Returns:     The function returns a pointer to the octet after the last
 *              octet read on success or 0 on failure. It fails if the data
 *              at src is not a DER-encoded ENUMERATED type or (in DEBUG 
 *              mode) if src or enm is NULL
 * Memory:      This function allocates no memory.
 */
extern u8 *
asn1_berenum2enum(u8 *src, int *enm);

/* Function:    <asn1_stream_berenum2enum>
 * Summary:     Reads a DER-encoded bit string from a stream into an integer.
 * Syntax:      int rval = asn1_stream_berenum2enum(int (*stre)(void *), 
 *                void *par, int *enm);
 * Description: The asn1_stream_berenum2enum() function reads a
 *              DER-encoded ASN.1 BIT STRING type from stre and writes the
 *              value as an unsigned long into enm.
 *
 *              The function stre is a streamer function that takes a 
 *              single parameter, param. It reads from the location
 *              specified in param and returns a single byte cast as an
 *              int, or -1 on error. See asn1_stream_bertag2type() for
 *              an example of a streamer function that reads from a
 *              file.
 * Returns:     This function returns 0 on success or -1 on failure.
 *              It fails if stre couldn't read from params, if the
 *              data is not a DER-encoded ENUMERATED TYPE or (in DEBUG
 *              mode) if enm is NULL.
 * Memory:      This function allocates no memory.
 */
extern int
asn1_stream_berenum2enum(int (*stre)(void *), void *par, int *enm);

/* Function:    <asn1_cmp_beroctetstring>
 * Summary:     Compares two DER-encoded OCTET STRINGs.
 * Syntax:      int rval = asn1_cmp_beroctetstring(u8 *o0, u8 *o1);
 * Description: The asn1_cmp_beroctetstring() function compares the two 
 *              DER-encoded ASN.1 OCTET STRINGs o0 and o1. It returns 0 if 
 *              their contents are equal, -1 if o0 is lexicographically less 
 *              than o1, or +1 if greater. If the data at o0 or o1 is not an
 *              OCTET STRING, the function returns -2.
 * Memory:      This function allocates no memory.
 */
extern int 
CST32EXPORTTYPE CST16EXPORTTYPE
asn1_cmp_beroctetstring(u8 *o0, u8 *o1);

/* Function:    <asn1_size2sizeoftype>
 * Summary:     Deprecated. Use asn1_sizeof_type() instead.
 */
extern sec_off_t asn1_size2sizeoftype(sec_off_t len, asn1_asn1type type);

/* Function:    <asn1_innerberlen2size>
 * Summary:     Called by asn1_berlen2size().
 * Syntax:      u8 * rval = asn1_innerberlen2size(u8 *src, off_t *size);
 * Description: The asn1_innerberlen2size() function is exactly the same
 *              as asn1_berlen2size(), except that it throws an error on
 *              indefinite-length encoded data.
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_innerberlen2size(u8 *src, sec_off_t *size);


typedef void *asn1_rdbstr_id;

typedef enum {
  ASN1_RDBSTR_LITERAL = 0,
  ASN1_RDBSTR_CONTENTS,
  ASN1_RDBSTR_NOINDEF
} asn1_rdbstr_fmt;

typedef enum {
  ASN1_RDBSTR_INTRNL = -1,
  ASN1_RDBSTR_UNFINISHED = 0,
  ASN1_RDBSTR_DONE,
  ASN1_RDBSTR_NOMATCH,
  ASN1_RDBSTR_NOPARAM
} asn1_rdbstr_result;

/* Function:    <asn1_read_berstring>
 * Summary:     Reads BER-encoded ASN.1 from a buffer.
 * Syntax:      end = asn1_read_berstring(src, srclen, srctype, format, 
 *              dest, &state, &nextByte, &result);
 * Description: Reads BER-encoded ASN.1 from src and puts it into dest.
 *              Returns a pointer to the byte after the last byte
 *              written or 0 on failure. The function takes the 
 *              following arguments:
 *            src -- the source string; must contain at least srclen
 *              bytes of data.
 *            srclen -- the length of data to be read in from src.
 *            srctype -- the expected ASN.1 type of the data. On the
 *              first read from the string, the type is checked and we
 *              return 0 if it doesn't correspond to the type given in
 *              srctype. This type can be an ASN.1 type or a
 *              context-specific tag. If srctype == 0 or *srctype == 0, 
 *              we check only to see that we can parse the tag and
 *              return 0 if the tag is completely unrecognized. On
 *              success, srctype contains the tag of the inner sequence.
 *            format -- a asn1_rdbstr_fmt value which says how we
 *              are to output to dest.
 *              ASN1_RDBSTR_LITERAL:     outputs the string literally,
 *                making no change to the contents at all.
 *              ASN1_RDBSTR_CONTENTS:     strips off the header data
 *                from the start of the BER string before outputting it
 *                to dest.
 *              ASN1_RDBSTR_NOINDEF:     strips off the header data
 *                from the start of the BER string and if the data is
 *                indefinite-length encoded, strips out the
 *                intermediate tag-and-length bytes. Only use this
 *                on constructed OCTET STRINGs and BIT STRINGs.
 *            dest -- the address to write the output to. Should have at
 *              least srclen bytes of data allocated. If dest is 0,
 *              asn1_read_berstring will not write the output
 *              and will return a nonzero value on success or
 *              0 on failure.
 *            state -- a pointer to a void *. This maintains state
 *              information about the read so the data need not be read
 *              in all at once. When asn1_read_berstring is called for the
 *              first time, set state = 0 and pass in &state. On failure
 *              the internal state is automatically reset and state is
 *              returned to being 0. If a nonzero state is passed in
 *              for the first read, an error will result.
 *            nextByte -- contains a pointer to the byte after the last
 *              byte _read_. This is useful when a read terminates
 *              successfully.
 *            result -- an asn1_rdbstr_result value that
 *              indicates whether we need to make another call to
 *              asn1_read_berstring or have finished reading.
 *              ASN1_RDBSTR_INTRNL:     indicates an internal failure
 *                (asn1_read_berstring will have returned 0).
 *              ASN1_RDBSTR_UNFINISHED:     specifies that more data remains 
 *                to be read from the input stream (we haven't reached the end 
 *                of a definite-length encoded string or the terminating "00
 *                00" of an indefinite-length encoded string).
 *              ASN1_RDBSTR_DONE:     indicates that we've successfully reached
 *                the end of the BER-encoded object.
 *              ASN1_RDBSTR_NOMATCH:     indicates that he tag on the 
 *                BER-encoded object didn't match the expected tag 
 *                (asn1_read_berstring will have returned 0).
 *              ASN1_RDBSTR_NOPARAM:     specifies (in debug mode only) 
 *                null parameters.
 * Returns:     Returns 0 on failure. 
 * Example:     The following code shows how to use this function to
 *            read an ASN.1-encoded SEQUENCE from a file and write the
 *            sequence data, minus the SEQUENCE header, to another file.
 *            In this example the input file contains additional data
 *            after the end of the sequence, so we expect fread not to
 *            return 0 until well after we've finished using
 *            asn1_read_berstring.
 *           (code)
 *             FILE              *inp, *outp;
 *             u8                 inbuf[BUFSIZ], outbuf[BUFSIZ], *u8inptr,
 *                                *u8outptr;
 *             asn1_rdbstr_result   result;
 *             off_t             len;
 *             asn1_rdbstr_id      *state = 0;
 *             ...
 *             do {
 *               len = fread (inbuf, sizeof(u8), BUFSIZ, inp);
 *
 *               if (!(u8outptr = asn1_read_berstring(inbuf, len, 
 *                 ASN1_SEQUENCE, 0, ASN1_RDBSTR_CONTENTS, outbuf, &state,
 *                 &u8inptr, &result) {
 *                  [handle error and exit...]
 *               }
 *
 *               fwrite(outbuf, sizeof(u8), (u8outptr - outbuf), outbuf);
 *               
 *             } while (!result);
 *
 *             [Handle remaining input data from u8inptr to the end of
 *              inbuf...]
 *             ...
 *             [Carry on reading from inp and handle that data.]
 *           (/code)
 */
extern u8
CST32EXPORTTYPE * CST16EXPORTTYPE
asn1_read_berstring(u8 *src, sec_off_t srclen, asn1_asn1type *srctype,
  asn1_rdbstr_fmt format, u8 *dest, void **state, u8 **nextByte, 
  asn1_rdbstr_result *result);


/* macros for backward compatibility */
#define asn1_strdup(in)       (ut_strdup((in)))
#define asn1_t_b64(in, out)   (ut_t_b64((in), (out)))
#define asn1_f_b64(in, out)   (ut_f_b64((in), (out)))


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _ASN1_H */

