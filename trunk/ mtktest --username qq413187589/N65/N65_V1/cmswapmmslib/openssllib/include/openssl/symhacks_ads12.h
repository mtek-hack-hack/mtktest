/****************************************************************************/
/*                                                                          */
/*   MOBILESOFT CHINA (CMS) SYSTEMS, INC.                                   */
/*                WIRELESS APPLICATION DESIGN CENTER (NANJING CHINA)        */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*   CMS CONFIDENTIAL AND PROPRIETARY                                       */
/*                                                                          */
/*   This source is the sole property of CMS Systems, Inc. Reproduction     */
/*   or utilization of this source in whole or in part is forbidden without */
/*   the written consent of CMS Systems, Inc.                               */
/*                                                                          */
/*   (c) Copyright CMS Systems, Inc., 2000.  All Rights Reserved.           */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*   cmsSSL_Alert.c                                                         */
/*                                                                          */
/****************************************************************************/
/*--------------------------------------------------------------------------*/
/*   Date       |  author         |   Description |   version               */
/*--------------------------------------------------------------------------*/
/*   27/12/04   |  Liang Li       |   Creation    |   0.1.1                 */
/*--------------------------------------------------------------------------*/
/****************************************************************************/
#ifndef __HEADER_SYMHACKS_ADS12_H__
#define __HEADER_SYMHACKS_ADS12_H__

#ifndef HEADER_SYMHACKS_H
#	error do not include this file in your project.
#endif

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "../../inc/cms_time.h"		/* symhack time functions. */

#ifndef OPENSSL_NO_KRB5
#	define OPENSSL_NO_KRB5
#endif

#ifndef OPENSSL_NO_ENGINE
#	define OPENSSL_NO_ENGINE
#endif

#ifndef OPENSSL_NO_ERR
#	define OPENSSL_NO_ERR
#endif

#ifndef OPENSSL_NO_SOCK
#	define OPENSSL_NO_SOCK
#endif

#ifndef GETPID_IS_MEANINGLESS
#	define GETPID_IS_MEANINGLESS
#endif

#ifndef OPENSSL_NO_LOCKING
#	define OPENSSL_NO_LOCKING
#endif

#ifdef  __cplusplus
extern "C" {
#endif

void *			cms_memset(void *pObject,int value, unsigned int count);
void *			cms_memcpy(void *pTarget, const void *pSource, unsigned int count);
void *			cms_memmove(void *pTarget, const void *pSource, unsigned int count);

char *			cms_strcpy	( char *pTarget, const char *pSource );
unsigned int	cms_strlen	(const char *str );
char *			cms_strstr	( const char *p_string, const char *p_charset );
char *			cms_strcat	(char *dest, const char *src );
int				cms_strcmp	(const char *pTarget,const char *pSource);
int				cms_strncmp	(const char *pTarget,const char *pSource,int len);
char *			cms_strchr	(const char *p_string,char ch);
char *			cms_strrchr	(const char *p_string,char ch);
char*			cms_strncat	( char* dst , const char* src , size_t sz );
int				cms_stricmp	(const char * str , const char * str2 );
int				cms_strnicmp(const char * str , const char * str2 , size_t sz );
char*			cms_stristr	(const char * lstr,const char * rstr);
char*			cms_strirstr( const char * lstr , const char * rstr );

#define memset			cms_memset
#define memcpy			cms_memcpy
#define memmove			cms_memmove

#define strcpy			cms_strcpy	
#define	strlen			cms_strlen	
#define strstr			cms_strstr	
#define strcat			cms_strcat	
#define strcmp			cms_strcmp	
#define strncmp			cms_strncmp	
#define strchr			cms_strchr	
#define strrchr			cms_strrchr	
#define strncat			cms_strncat	
#define stricmp			cms_stricmp	
#define strnicmp		cms_strnicmp
#define stristr			cms_stristr	
#define strirstr		cms_strirstr

/* symhack BN lib */
#define BN_value_one			cms_BN_value_one
#define	BN_options				cms_BN_options
#define BN_CTX_new				cms_BN_CTX_new
#define BN_CTX_init				cms_BN_CTX_init

#define BN_CTX_free				cms_BN_CTX_free

#define BN_CTX_start 			cms_BN_CTX_start
#define BN_CTX_get 				cms_BN_CTX_get
#define BN_CTX_end 				cms_BN_CTX_end
#define BN_rand 				cms_BN_rand
#define BN_pseudo_rand 			cms_BN_pseudo_rand
#define BN_rand_range 			cms_BN_rand_range
#define BN_pseudo_rand_range 	cms_BN_pseudo_rand_range
#define BN_num_bits 			cms_BN_num_bits
#define BN_num_bits_word 		cms_BN_num_bits_word
#define BN_new 					cms_BN_new
#define BN_init 				cms_BN_init
#define BN_clear_free 			cms_BN_clear_free
#define BN_copy 				cms_BN_copy
#define BN_swap 				cms_BN_swap
#define BN_bin2bn 				cms_BN_bin2bn
#define BN_bn2bin 				cms_BN_bn2bin
#define BN_mpi2bn 				cms_BN_mpi2bn
#define BN_bn2mpi 				cms_BN_bn2mpi
#define BN_sub 					cms_BN_sub
#define BN_usub 				cms_BN_usub
#define BN_uadd 				cms_BN_uadd
#define BN_add 					cms_BN_add
#define BN_mul					cms_BN_mul
#define BN_sqr					cms_BN_sqr

#define BN_div 					cms_BN_div
#define BN_nnmod				cms_BN_nnmod
#define BN_mod_add				cms_BN_mod_add
#define BN_mod_add_quick 		cms_BN_mod_add_quick
#define BN_mod_sub				cms_BN_mod_sub
#define BN_mod_sub_quick 		cms_BN_mod_sub_quick
#define BN_mod_mul				cms_BN_mod_mul
#define BN_mod_sqr 				cms_BN_mod_sqr
#define BN_mod_lshift1			cms_BN_mod_lshift1
#define BN_mod_lshift1_quick 	cms_BN_mod_lshift1_quick
#define BN_mod_lshift 			cms_BN_mod_lshift
#define BN_mod_lshift_quick 	cms_BN_mod_lshift_quick

#define BN_mod_word 			cms_BN_mod_word
#define BN_div_word 			cms_BN_div_word
#define BN_mul_word 			cms_BN_mul_word
#define BN_add_word 			cms_BN_add_word
#define BN_sub_word 			cms_BN_sub_word
#define BN_set_word 			cms_BN_set_word
#define BN_get_word 			cms_BN_get_word

#define BN_cmp					cms_BN_cmp
#define BN_free 				cms_BN_free
#define BN_is_bit_set			cms_BN_is_bit_set
#define BN_lshift				cms_BN_lshift
#define BN_lshift1 				cms_BN_lshift1
#define BN_exp					cms_BN_exp

#define BN_mod_exp 				cms_BN_mod_exp
#define BN_mod_exp_mont 		cms_BN_mod_exp_mont
#define BN_mod_exp_mont_word 	cms_BN_mod_exp_mont_word
#define BN_mod_exp2_mont 		cms_BN_mod_exp2_mont
#define BN_mod_exp_simple 		cms_BN_mod_exp_simple

#define BN_mask_bits 			cms_BN_mask_bits
#define BN_print_fp 			cms_BN_print_fp
#define BN_reciprocal 			cms_BN_reciprocal
#define BN_rshift 				cms_BN_rshift
#define BN_rshift1				cms_BN_rshift1
#define BN_clear 				cms_BN_clear
#define BN_dup					cms_BN_dup
#define BN_ucmp 				cms_BN_ucmp
#define BN_set_bit 				cms_BN_set_bit
#define BN_clear_bit			cms_BN_clear_bit
#define BN_bn2hex 				cms_BN_bn2hex
#define BN_bn2dec 				cms_BN_bn2dec
#define BN_hex2bn 				cms_BN_hex2bn
#define BN_dec2bn 				cms_BN_dec2bn
#define BN_gcd					cms_BN_gcd
#define BN_kronecker 			cms_BN_kronecker 
#define BN_mod_inverse			cms_BN_mod_inverse
#define BN_mod_sqrt 			cms_BN_mod_sqrt
#define BN_generate_prime 		cms_BN_generate_prime
#define BN_is_prime 			cms_BN_is_prime
#define BN_is_prime_fasttest 	cms_BN_is_prime_fasttest

#define BN_MONT_CTX_new 		cms_BN_MONT_CTX_new
#define BN_MONT_CTX_init 		cms_BN_MONT_CTX_init
#define BN_mod_mul_montgomery 	cms_BN_mod_mul_montgomery

#define BN_from_montgomery		cms_BN_from_montgomery
#define BN_MONT_CTX_free 		cms_BN_MONT_CTX_free
#define BN_MONT_CTX_set 		cms_BN_MONT_CTX_set
#define BN_MONT_CTX_copy 		cms_BN_MONT_CTX_copy

#define BN_BLINDING_new 		cms_BN_BLINDING_new
#define BN_BLINDING_free 		cms_BN_BLINDING_free
#define BN_BLINDING_update 		cms_BN_BLINDING_update
#define BN_BLINDING_convert 	cms_BN_BLINDING_convert
#define BN_BLINDING_invert 		cms_BN_BLINDING_invert

#define BN_set_params 			cms_BN_set_params
#define BN_get_params  			cms_BN_get_params 

#define BN_RECP_CTX_init 		cms_BN_RECP_CTX_init
#define BN_RECP_CTX_new 		cms_BN_RECP_CTX_new
#define BN_RECP_CTX_free 		cms_BN_RECP_CTX_free
#define BN_RECP_CTX_set 		cms_BN_RECP_CTX_set
#define BN_mod_mul_reciprocal 	cms_BN_mod_mul_reciprocal
#define BN_mod_exp_recp 		cms_BN_mod_exp_recp
#define BN_div_recp 			cms_BN_div_recp


#define bn_expand2 				cms_bn_expand2
#define bn_dup_expand 			cms_bn_dup_expand

#define bn_mul_add_words 		cms_bn_mul_add_words
#define bn_mul_words 			cms_bn_mul_words
#define bn_sqr_words 			cms_bn_sqr_words
#define bn_div_words 			cms_bn_div_words
#define bn_add_words 			cms_bn_add_words
#define bn_sub_words 			cms_bn_sub_words

#define BN_bntest_rand			cms_BN_bntest_rand
#define ERR_load_BN_strings		cms_ERR_load_BN_strings

#ifdef  __cplusplus
};
#endif

#endif

