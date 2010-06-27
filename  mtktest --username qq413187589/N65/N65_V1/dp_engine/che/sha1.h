/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    sha1.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   SHA1 Engine
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * code review. remove unused definitions.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SHA1_H__
#define __SHA1_H__

#define BITS8  unsigned char
#define BITS16 unsigned short
#define BITS32 unsigned long
#define ARGCARGV
#define PROTOTYPES



/* Defines common to everything */

#define SHF_DIGESTSIZE 20
/* Put out a digest of this size in bytes */
#define SHF_DIGESTWORDSIZE 5
/* and words */

#define SHF_BLOCKSIZE  64
#define SHF_BLOCKWORDSIZE 16
/* Process messages in this block size */

/* Structure for storing SHF info */

typedef BITS32 shadigest[SHF_DIGESTWORDSIZE];
typedef BITS8  sha1_digest[SHF_DIGESTSIZE];

typedef struct {
  BITS32    data [SHF_BLOCKWORDSIZE];     /* SHS data buffer */
  BITS32    countLo;       /* Count (64 bits in              */
  BITS32    countHi;       /* 2 32 bit words)                */
  shadigest digest;        /* Message digest                 */
  int       kind;          /* Which type of SHA?             */
  int       thisword;      /* Which word are we processing?  */
  int       thisbyte;      /* Which byte in that word?       */
  int		length; //Julie1213
} sha1_context, *sha1_context_ptr;

/* These routines all take a context, so that multiple streams can be
 * handled.  If you pass NULL, then a single package wide canned context
 * will be used.
 */

/* Initialize a stream */
void CHE_sha1_Init       (sha1_context_ptr context);
/* Version 0 - Original NIST version (Obsolete) */
/*             (30 January 1995) */
/* Version 1 - lastest NIST modifications    */

/* Add a buffer's worth of characters to the current hash. */
void CHE_sha1_append     (sha1_context_ptr context, BITS8 *buffer, int count);

/* Add a string's worth of characters to the current hash. */
void CHE_shaStrUpdate  (sha1_context_ptr context, char *input);

/* Done, report the final hash. */
void CHE_sha1_finish      (sha1_context_ptr context, sha1_digest adigest);

/* And for all you bit twiddlers out there, the machine independent
 * Digest to digest string routines.
 */
 
/* digest from context */
void CHE_shaBytes (sha1_context_ptr context, sha1_digest adigest);
/* string from digest */
void CHE_shaString (sha1_digest adigest, char *outputstring);

/* hash of a buffer */
/* This returns directly the SHA digest of the characters in a buffer. */
void CHE_shaHash (int version, BITS8 *buffer, int count, sha1_digest adigest);

void CHE_sha1_hmac( unsigned char *key, int keylen,
                unsigned char *input, int ilen,
                unsigned char output[20] );


#endif /* __SHA1_H__ */

