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












#ifndef _sec_h
#define _sec_h

 
#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_log_h
#include "msf_log.h"
#endif
#ifndef _msf_lib_h
#include "msf_lib.h"
#endif
#ifndef _sec_sig_h
#include "sec_sig.h"  
#endif
#ifndef _sec_if_h
#include "sec_if.h"
#endif
#ifndef _sec_cfg_h
#include "sec_cfg.h"  
#endif
#ifndef _sec_ati_h
#include "sec_ati.h" 
#endif

#define URL_MAX_SIZE 255





extern int step;
extern int wantsToRun;
extern int sec_initialised;





extern jmp_buf sec_jmp_buf;
extern int     sec_inside_run;






#define SEC_MAIN_SIG_TERMINATE   										W_SIG_DST_SEC_MAIN + 1
#define SEC_MAIN_SIG_GET_METHODS      							W_SIG_DST_SEC_MAIN + 2
#define SEC_MAIN_SIG_WTLS_KEY_EXCHANGE         			W_SIG_DST_SEC_MAIN + 3
#define SEC_MAIN_SIG_WTLS_PRF												W_SIG_DST_SEC_MAIN + 4
#define SEC_MAIN_SIG_WTLS_VERIFY_CERTIFICATE_CHAIN  W_SIG_DST_SEC_MAIN + 5
#define SEC_MAIN_SIG_WTLS_GET_CLIENT_CERT						W_SIG_DST_SEC_MAIN + 6
#define SEC_MAIN_SIG_WTLS_COMPUTE_SIGNATURE					W_SIG_DST_SEC_MAIN + 7
#define SEC_MAIN_SIG_GET_CIPHER_SUITES							W_SIG_DST_SEC_MAIN + 8
#define SEC_MAIN_SIG_TLS_KEY_EXCHANGE								W_SIG_DST_SEC_MAIN + 9
#define SEC_MAIN_SIG_TLS_PRF												W_SIG_DST_SEC_MAIN + 10
#define SEC_MAIN_SIG_TLS_VERIFY_CERTIFICATE_CHAIN		W_SIG_DST_SEC_MAIN + 11
#define SEC_MAIN_SIG_TLS_GET_CLIENT_CERT						W_SIG_DST_SEC_MAIN + 12
#define SEC_MAIN_SIG_TLS_COMPUTE_SIGNATURE					W_SIG_DST_SEC_MAIN + 13
#define SEC_MAIN_SIG_HASH_UPDATE_W_MASTER_SEC       W_SIG_DST_SEC_MAIN + 14
#define SEC_MAIN_SIG_SIGN_TEXT											W_SIG_DST_SEC_MAIN + 15
#define SEC_MAIN_SIG_CONNECTION_ESTABLISHED					W_SIG_DST_SEC_MAIN + 16
#define SEC_MAIN_SIG_CONNECTION_TERMINATED					W_SIG_DST_SEC_MAIN + 17
#define SEC_MAIN_SIG_PEER_DELETE_LINKS							W_SIG_DST_SEC_MAIN + 18
#define SEC_MAIN_SIG_PEER_LINK_TO_SESSION						W_SIG_DST_SEC_MAIN + 19
#define SEC_MAIN_SIG_PEER_LOOKUP										W_SIG_DST_SEC_MAIN + 20
#define SEC_MAIN_SIG_SESSION_ACTIVE									W_SIG_DST_SEC_MAIN + 21
#define SEC_MAIN_SIG_SESSION_INVALIDATE							W_SIG_DST_SEC_MAIN + 22
#define SEC_MAIN_SIG_SESSION_FETCH									W_SIG_DST_SEC_MAIN + 23
#define SEC_MAIN_SIG_SESSION_UPDATE                 W_SIG_DST_SEC_MAIN + 24
#if( ((!(defined(SEC_CFG_WTLS_CLASS_1))) && (defined(SEC_CFG_WTLS))) || defined(SEC_CFG_TLS) || defined(SEC_CFG_CAN_SIGN_TEXT) )
#define SEC_MAIN_SIG_STORE_CERT                     W_SIG_DST_SEC_MAIN + 25
#define SEC_MAIN_SIG_TRUSTED_CA_INFO                W_SIG_DST_SEC_MAIN + 26
#define SEC_MAIN_SIG_CERT_DELIVERY                  W_SIG_DST_SEC_MAIN + 27
#define SEC_MAIN_SIG_VIEW_CERT_NAMES                W_SIG_DST_SEC_MAIN + 28
#define SEC_MAIN_SIG_GET_CERT_IDS                   W_SIG_DST_SEC_MAIN + 29
#define SEC_MAIN_SIG_GET_NBR_CERTS                  W_SIG_DST_SEC_MAIN + 30
#define SEC_MAIN_SIG_VERIFY_CERT_CHAIN              W_SIG_DST_SEC_MAIN + 31
#endif 
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS) || defined(SEC_CFG_CAN_SIGN_TEXT) )
#define SEC_MAIN_SIG_GENERATE_KEY_PAIR              W_SIG_DST_SEC_MAIN + 32
#define SEC_MAIN_SIG_DEL_KEYS_USER_CERTS            W_SIG_DST_SEC_MAIN + 33
#define SEC_MAIN_SIG_GET_USER_PUB_KEY               W_SIG_DST_SEC_MAIN + 34
#define SEC_MAIN_SIG_CHANGE_PIN                     W_SIG_DST_SEC_MAIN + 35
#ifdef SEC_CFG_PUK 
#define SEC_MAIN_SIG_VERIFY_PUK                     W_SIG_DST_SEC_MAIN + 36
#endif 
#endif 
#define SEC_MAIN_SIG_VIEW_CURRENT_CERT              W_SIG_DST_SEC_MAIN + 37
#define SEC_MAIN_SIG_VIEW_SESSION_INFO              W_SIG_DST_SEC_MAIN + 38
#define SEC_MAIN_SIG_GET_CURRENT_SEC_CLASS          W_SIG_DST_SEC_MAIN + 39
#define SEC_MAIN_SIG_SESSION_CLEAR                  W_SIG_DST_SEC_MAIN + 40
#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)) )
#define SEC_MAIN_SIG_VIEW_CONTRACTS                 W_SIG_DST_SEC_MAIN + 41
#endif 
#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT))
#define SEC_MAIN_SIG_GET_CERT                       W_SIG_DST_SEC_MAIN + 42
#define SEC_MAIN_SIG_GET_CERT_RESPONSE              W_SIG_DST_SEC_MAIN + 43
#define SEC_MAIN_SIG_DELETE_CERT                    W_SIG_DST_SEC_MAIN + 44
#define SEC_MAIN_SIG_DELETE_CERT_RESPONSE           W_SIG_DST_SEC_MAIN + 45
#endif 
#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
#define SEC_MAIN_SIG_GET_CONTRACTS                  W_SIG_DST_SEC_MAIN + 46
#define SEC_MAIN_SIG_DELETE_CONTRACT                W_SIG_DST_SEC_MAIN + 47
#define SEC_MAIN_SIG_DELETE_CONTRACT_RESPONSE       W_SIG_DST_SEC_MAIN + 48
#endif 
#define SEC_MAIN_SIG_EXECUTE_COMMAND                W_SIG_DST_SEC_MAIN + 49
#define SEC_MAIN_SIG_WIDGET_ACTION                  W_SIG_DST_SEC_MAIN + 50
#define SEC_MAIN_SIG_PIPE_NOTIFY                    W_SIG_DST_SEC_MAIN + 51         
#define SEC_MAIN_SIG_STORE_CERT_RESPONSE            W_SIG_DST_SEC_MAIN + 52
#define SEC_MAIN_SIG_TRUSTED_CA_INFO_RESPONSE       W_SIG_DST_SEC_MAIN + 53
#define SEC_MAIN_SIG_CERT_DELIVERY_RESPONSE         W_SIG_DST_SEC_MAIN + 54

enum FUNCTION_ID {
  SP_NONE,
  INITIALISE,
  CONNECTION_ESTABLISHED,
  CONNECTION_TERMINATED,
#ifdef SEC_CFG_WTLS
  GET_METHODS,
	WTLS_KEY_EXCHANGE,
	WTLS_PRF,
	WTLS_VERIFY_CERTIFICATE_CHAIN,
#ifdef SEC_CFG_WTLS_CLASS_3
  WTLS_GET_CLIENT_CERTIFICATE,
	WTLS_COMPUTE_SIGNATURE,
#endif	
#endif
#ifdef SEC_CFG_TLS
  GET_CIPHER_SUITES,
  TLS_KEY_EXCHANGE,
  TLS_PRF,
	TLS_VERIFY_CERTIFICATE_CHAIN,
	TLS_GET_CLIENT_CERTIFICATE,
	TLS_COMPUTE_SIGNATURE,
#endif
  KEY_EXCHANGE,
  PRF,
	COMPUTE_SIGNATURE,
  VERIFY_CERTIFICATE_CHAIN,
  VERIFY_USER_CERTIFICATE_CHAIN,
  VERIFY_ROOT_CERT,
  FIND_PRIV_KEY,
  SESSION_INIT,
  SESSION_CLOSE,
  PEER_DELETE_LINKS,
  PEER_LINK_TO_SESSION,
  PEER_LOOKUP,
  SESSION_ACTIVE,
  SESSION_INVALIDATE,
  SESSION_CLEAR,
  SESSION_FETCH,
  SESSION_UPDATE,
  GENERATE_RANDOM,
  HASH,
  HASH_INIT,
  HASH_UPDATE,
  HASH_FINAL,
  HMAC_INIT,
  HMAC_UPDATE,
  HMAC_FINAL,
  ENCRYPT,
  DECRYPT,
  ENCRYPT_INIT,
  ENCRYPT_UPDATE,
  ENCRYPT_FINAL,
  DECRYPT_INIT,
  DECRYPT_UPDATE,
  DECRYPT_FINAL,
#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  STORE_CA_CERT,
  STORE_USER_CERT,
  STORE_CERT,
  TRUSTED_CA_INFO,
	HASH_VERIFICATION,
	SIGNATURE_VERIFICATION,
	CERT_DELIVERY,
	VIEW_CERT_NAMES,
	GET_NBR_CERTS,
  VERIFY_CERT_CHAIN,
  GET_CERT_NAMES,
  GET_CERT_NAMES_CONN,
  GET_CHAIN_OF_CERT,
  GET_CERT_IDS,
	GET_CERT,
  GET_CERT_RESPONSE,
	DELETE_CERT,
  DELETE_CERT_RESPONSE,
	CHOOSE_CERT_BY_FRIENDLYNAME,
	SELFSIGNED_CERT,
	CERT_ALREADY_EXISTS,
  STORE_USER_CERT_DATA,
	STORE_CERTIFICATE_DIALOG,
#endif
	CONFIRM_DIALOG,	
	GET_LATEST_VERIFIED_CERT,
	VIEW_CURRENT_CERT,
	VIEW_SESSION_INFO,
  GET_CURRENT_SEC_CLASS,
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) ||defined(SEC_CFG_TLS) ||defined(SEC_CFG_CAN_SIGN_TEXT) )
	GET_USER_CERT,
	GET_USER_CERT_AND_SIGNED_KEY,
#endif
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
	GET_USER_CERTIFICATE,
#endif
	
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
	GENERATE_KEY_PAIR,
	DELETE_KEYS_CERTS,
	GET_USER_PUB_KEY,
	PIN_DIALOG,
	PIN_INFO,
	VERIFY_PIN,
	CHANGE_PIN,
	CHANGE_PIN_DIALOG,
	GENERATE_PIN,
#ifdef SEC_CFG_PUK
	VERIFY_PUK,
	CHANGE_PIN_PUK,
#endif
#endif
#ifdef SEC_CFG_CAN_SIGN_TEXT
	MMI_SIGN_TEXT,
	GET_SIGN_TEXT_MATCHES,
#endif
#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
	VIEW_CONTRACTS,
	GET_CONTRACTS_RESPONSE,
	GET_CONTRACTS,
	DELETE_CONTRACT,
	DELETE_CONTRACT_RESPONSE,
	STORE_CONTRACT_RESPONSE,
#endif
#ifdef SEC_CFG_TLS
	GET_SOCKET_INFO,
#endif
#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  MIME_RESPONSE,
#endif
	READ_VIEWS_CERTS,
	HASH_DIALOG,
	VERIFY_HASH
};






struct parameterStruct {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
};


#ifdef SEC_CFG_WTLS
struct sec_st_wtls_get_methods {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_wtls_get_methods_t *strct;
};

struct sec_st_wtls_keyexch {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_wtls_key_exchange_t *strct;
};

struct sec_st_wtls_prf {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_wtls_prf_t *strct;
};

struct sec_st_wtls_verify_cert_chain {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_wtls_verify_cert_chain_t *strct;
};

#ifdef SEC_CFG_WTLS_CLASS_3
struct sec_st_wtls_get_client_cert{
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_wtls_get_client_cert_t *strct;
};

struct sec_st_wtls_compute_sig{
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
 	sec_wtls_compute_signature_t *strct;
};
#endif
#endif



#ifdef SEC_CFG_TLS
struct sec_st_tls_get_ciphersuites {
 	enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_tls_get_cipher_suites_t *strct;
};
                  
struct sec_st_tls_keyexch {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_tls_key_exchange_t *strct;
};
                       
struct sec_st_tls_prf {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_tls_prf_t *strct;
};

struct sec_st_tls_verify_cert_chain{
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_tls_verify_cert_chain_t *strct;
};
    
struct sec_st_tls_get_client_cert{
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_tls_get_client_cert_t *strct;
};
                     
struct sec_st_tls_compute_sig{
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_tls_compute_signature_t *strct;
};
#endif 



#ifdef SEC_CFG_CAN_SIGN_TEXT
  struct sec_st_sign_text{
    enum FUNCTION_ID type;
    struct parameterStruct *prev;
    struct parameterStruct *next;
    sec_sign_text_t *strct;
  };
#endif




struct sec_st_conn_established {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_connection_established_t *strct;
};

struct sec_st_conn_terminated {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_connection_terminated_t *strct;
};
								
struct sec_st_peer_delete_links {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_peer_delete_links_t *strct;
};

struct sec_st_peer_link_to_session {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_peer_link_to_session_t *strct;
};

struct sec_st_peer_lookup {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_peer_lookup_t *strct;
};

struct sec_st_session_active {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_session_active_t *strct;
};

struct sec_st_session_invalidate {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_session_invalidate_t *strct;
};

struct sec_st_session_fetch {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_session_fetch_t *strct;
};

struct sec_st_session_update {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_session_update_t *strct;
};



#if( ((!(defined(SEC_CFG_WTLS_CLASS_1))) && (defined(SEC_CFG_WTLS))) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )

struct sec_st_cert_store_cert {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_store_cert_t *strct;
};

struct sec_st_cert_trusted_ca_info {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_trusted_ca_info_t *strct;
};

struct sec_st_cert_cert_delivery {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_cert_delivery_t *strct;
};

struct sec_st_mime_response {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_store_cert_response_t *strct;
};

struct sec_st_cert_view_cert_names {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_view_cert_names_t *strct;
};

struct sec_st_cert_get_cert_ids {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_get_cert_ids_t *strct;
};

struct sec_st_cert_get_nbr_certs {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_get_nbr_certs_t *strct;
};

struct sec_st_verify_cert_chain {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_verify_cert_chain_t *strct;
  unsigned char *buf;
  MSF_UINT32 bufLen;
};

#endif 

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )

struct sec_st_cert_generate_key_pair {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_generate_key_pair_t *strct;
};

struct sec_st_cert_delete_keys_user_certs {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_del_keys_user_certs_t *strct;
};

struct sec_st_cert_get_user_pub_key {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_get_user_pub_key_t *strct;
};

struct sec_st_cert_change_pin {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_change_pin_t *strct;
};

#ifdef SEC_CFG_PUK

struct sec_st_cert_verify_puk {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_verify_puk_t *strct;
};

#endif 
#endif 

struct sec_st_cert_view_current_cert {
  enum FUNCTION_ID         type;
  struct parameterStruct  *prev;
  struct parameterStruct  *next;
  sec_view_current_cert_t *strct;  
  int                      options;
};

struct sec_st_cert_view_session_info {
  enum FUNCTION_ID         type;
  struct parameterStruct  *prev;
  struct parameterStruct  *next;
  sec_view_session_info_t *strct;
  int                      options;
};

struct sec_st_cert_get_current_sec_class {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_get_current_sec_class_t *strct;
};

struct sec_st_cert_session_clear {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_session_clear_t *strct;
};

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))

struct sec_st_cert_view_contracts {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_view_contracts_t *strct;
};

#endif 



#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT))

struct sec_st_cert_get_cert {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_view_and_get_cert_t *strct;
  int options;
};

struct sec_st_cert_get_cert_response {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_view_and_get_cert_response_t *strct;
};

struct sec_st_cert_delete_cert {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_delete_cert_t *strct;
};

struct sec_st_cert_delete_cert_response {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_delete_cert_response_t *strct;
};

#endif 

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))

struct sec_st_cert_get_contracts {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_get_contracts_t *strct;
};

struct sec_st_cert_delete_contract {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_delete_contract_t *strct;
};

struct sec_st_cert_delete_contract_response {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  sec_delete_contract_response_t *strct;
};
#endif 






void sec_queueInsert(struct parameterStruct *node);
int sec_queueIsEmpty(void);





void sec_runInternal(void);
void
sec_init (void);
void sec_cleanup(void);
void sec_handle_cancel(sec_cancel_t *p);
int sec_runWimInitialise(int id, int puk);
int sec_runVerifyUser(int id, sec_pin_cause_t pinCause);
int sec_runOldRootCertHandling(int tooOldRootCertId);

int sec_getPublicKeyRSA(unsigned char *cert, sec_pub_key_rsa *pubKey);
#ifdef SEC_CFG_DHE_DSS
int sec_getPublicKeyDSA(unsigned char *cert, 
                        unsigned char **publicKey, MSF_UINT16 *publicKeyLen,
												unsigned char **dsaParams, MSF_UINT16 *dsaParamsLen);
#endif
int sec_getCertItemsForTi(unsigned char *cert, MSF_INT16 *issuercharSet, 
                            void **in_issuer, int *in_issuerLen, 
                            MSF_INT16 *subjectcharSet, 
                            void **in_subject, int *in_subjectLen, 
                            MSF_UINT32 *valid_not_before, 
                            MSF_UINT32 *valid_not_after,
                            unsigned char *fingerprint, int *fingerprintLen);

#endif
