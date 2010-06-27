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







#ifndef _sec_str_h
#define _sec_str_h

#ifndef _sec_h
#include "sec.h"
#endif
#ifndef _sec_ati_h 
#include "sec_ati.h" 
#endif
#ifndef _sec_cfg_h
#include "sec_cfg.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif


#define MAX_NBR_CONNECTIONS SEC_SESSION_CACHE_SIZE

struct sec_st {
  enum FUNCTION_ID type;
};

struct ti_st {
  enum FUNCTION_ID type;
};

struct wim_st {
  enum FUNCTION_ID type;
};


void sec_freeSecSt(struct sec_st *p);
void sec_freeTiSt(struct ti_st *p);
void sec_freeWimSt(struct wim_st *p);
void sec_freeSt(struct parameterStruct *p);






#ifdef SEC_CFG_TLS
struct sec_st_getSocketInfoResponse {
  enum FUNCTION_ID type;
	int id;
	int result;
	unsigned char *address;
	int addressLen;
	unsigned char *domain;
	int domainLen;
};
#endif





 struct ti_st_confirm_dialog_response {
  enum FUNCTION_ID type;
	MSF_UINT8 answer;
};

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)) && (defined(SEC_CFG_WTLS)))) || (defined(SEC_CFG_TLS))|| (defined(SEC_CFG_CAN_SIGN_TEXT)) )
  struct ti_st_store_cert_dialog_response {
    enum FUNCTION_ID type;
	  MSF_UINT8 answer;
	  unsigned char *certFriendlyName;
	  MSF_UINT16 friendlyNameLen;
	  MSF_INT16 charSet;
 };

  struct ti_st_choose_cert_by_friendly_name_response{
  	enum FUNCTION_ID type;
    int certId;
    sec_ti_return_val_t result;
  };
#endif

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1))) && (defined(SEC_CFG_WTLS))) || defined(SEC_CFG_TLS)|| defined(SEC_CFG_CAN_SIGN_TEXT) )
  struct ti_st_pin_dialog_result {
	  enum FUNCTION_ID type;
	  sec_ti_return_val_t result;
  };
#endif

#if( ((defined(SEC_CFG_WTLS_CLASS_3)) && (defined(SEC_CFG_WTLS))) || (defined(SEC_CFG_TLS)) || (defined(SEC_CFG_CAN_SIGN_TEXT)) )
  struct ti_st_verify_pin {
	  enum FUNCTION_ID type;
	  MSF_UINT8 keyType;
	  char *pin;
  };

  struct ti_st_change_pin {
	  enum FUNCTION_ID type;
	  MSF_UINT8 keyType;
	  char *oldPin;
	  char *newPin;
  };

  struct ti_st_generate_pin_response {
	  enum FUNCTION_ID type;
	  sec_ti_return_val_t result;
	  char *pin;
  };
#endif 

struct ti_st_verify_hash {
  enum FUNCTION_ID type;
  int dialogId;
  MSF_UINT8 *hash;
};






struct wim_st_init_response {
  enum FUNCTION_ID type;
  int id;
  int result;
};

struct wim_st_wtls_get_methods_resp {
  enum FUNCTION_ID type;
  int objectId;
  int result;
  unsigned char *cipherMethods;
  int cipherMethodsLen;
  unsigned char *keyExchangeIds;
  int keyExchangeIdsLen;
  unsigned char *trustedKeyIds;
  int trustedKeyIdsLen;
};

struct wim_st_get_ciphersuites_resp {
  enum FUNCTION_ID type;
 	int objectId; 
 	int result;
  unsigned char *cipherSuites;
  int cipherSuitesLen;
};

struct wim_st_keyexch_resp {
  enum FUNCTION_ID type;
  int objectId;
  int result;
  int masterSecretId;
  unsigned char *publicValue;
  int publicValueLen;
};

struct wim_st_prf_resp {
  enum FUNCTION_ID type;
  int objectId;
  int result;
  unsigned char *buf;
  int bufLen;
};

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  struct wim_st_gen_rsa_keypair_resp{
	  enum FUNCTION_ID type;
	  int id;
	  int result;
	  MSF_UINT8 keyType;
	  unsigned char *publicKey;
	  int publicKeyLen;
	  unsigned char *sig;
	  int sigLen;
  };

  struct wim_st_del_keys_ucerts_by_type_resp {
    enum FUNCTION_ID type;
    int id;
    int result;
  };
#endif 

struct wim_st_verify_cert_chain_resp {
  enum FUNCTION_ID type;
  int id;
  int result;
	MSF_UINT16 keyExchKeyLen;
	int certTooOld;
	int certTooOldId;
};

struct wim_st_verify_user_cert_resp {
  enum FUNCTION_ID type;
  int id;
  int result;
  unsigned char *caCert;
  MSF_UINT16 caCertLen;
	MSF_UINT8 alg;
	int rootCertTooOld;
	int rootCertTooOldId;
};

struct wim_st_verify_root_cert_resp {
  enum FUNCTION_ID type;
  int id;
  int result;
};

struct wim_st_compute_sig_resp{
  enum FUNCTION_ID type;
  int id;
  int result;
  unsigned char *sig;
  int sigLen;
};


struct wim_st_find_privkey_resp{
  enum FUNCTION_ID type;
  int id;
  int result;
	MSF_UINT32 keyId; 
	int keyCount;
	MSF_UINT8 keyUsage;
};

struct wim_st_peer_delete_links_resp {
  enum FUNCTION_ID type;
  int result;
};

struct wim_st_peer_link_to_session_resp {
  enum FUNCTION_ID type;
  int result;
};

struct wim_st_session_active_resp {
  enum FUNCTION_ID type;
  int result;
};

struct wim_st_session_invalidate_resp {
  enum FUNCTION_ID type;
  int result;
};

struct wim_st_session_clear_resp {
  enum FUNCTION_ID type;
  int result;
};

struct wim_st_session_update_resp {
  enum FUNCTION_ID type;
  int result;
};

struct wim_st_peer_lookup_resp {
  enum FUNCTION_ID type;
  int id;
  int result;
  MSF_UINT8 connectionType;
  int masterSecretId;
	int deletedIndex;
};

struct wim_st_session_fetch_resp {
  enum FUNCTION_ID type;
  int id;
  int result;
  MSF_UINT8 sessionOptions;
  unsigned char *sessionId;
  MSF_UINT8 sessionIdLen;
  MSF_UINT8 cipherSuite[2];
  MSF_UINT8 compressionAlg;
  unsigned char *privateKeyId;
  MSF_UINT32 creationTime;
};

#if( ((!(defined(SEC_CFG_WTLS_CLASS_1)))&& defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  struct wim_st_cert_already_exists_resp {
    enum FUNCTION_ID type;
	  int id;
	  int result;
	  MSF_UINT8 exists;
	  MSF_UINT32 new_valid_not_before; 
	  MSF_UINT32 new_valid_not_after;
	  MSF_UINT32 old_valid_not_before; 
	  MSF_UINT32 old_valid_not_after;
	  int file_id;
  };

  struct wim_st_selfsigned_cert_resp {
    enum FUNCTION_ID type;
	  int id;
	  int result;
	  MSF_UINT8 selfsigned;
  };

  struct wim_st_store_cert_resp {
    enum FUNCTION_ID type;
	  int id;
	  int result;
	  int certId;
	  MSF_UINT32 certCount;
	  int URLCount;
	  int nameCount;
  };

  struct wim_st_store_ucert_data_resp {
    enum FUNCTION_ID type;
	  int id;
	  int result;
 };

  struct wim_st_delete_cert_resp {
    enum FUNCTION_ID type;
	  int certId; 
	  int result;
  };

  struct wim_st_get_cert_resp {
    enum FUNCTION_ID type;
    int result;
	  unsigned char *cert;
    MSF_UINT16 certLen;
    unsigned char *trustedUsage;
    MSF_UINT16 trustedUsageLen;
  };

  struct wim_st_cert_names_resp {
    enum FUNCTION_ID type;
    int  result;
	  int  nbrOfCerts;
    sec_cert_name_t *certNames;
  };

   struct wim_st_cert_names_conn_resp {
    enum FUNCTION_ID type;
    int  result;
	  int  nbrOfCerts;
    sec_cert_name_t *certNames;
    MSF_INT8 *chainDepth;
    MSF_UINT32 **certChainIds;
  };

   struct wim_st_tls_get_chain_of_certs_resp {
    enum FUNCTION_ID type;
    int  result;
	  int  nbrOfCerts;
    unsigned char **certs;
    MSF_UINT16 *certLen;
  };

  struct wim_st_get_cert_ids_resp {
    enum FUNCTION_ID type;
    int  result;
	  int nbrOfCerts;
	  MSF_UINT8 *certificateIds;
  };

  struct wim_st_get_nbr_certs_resp {
    enum FUNCTION_ID type;
    int id;
    int result;
	  int nbrCerts;
  };
#endif 

#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) ||defined(SEC_CFG_TLS) ||defined(SEC_CFG_CAN_SIGN_TEXT) )
  struct wim_st_get_ucert_signedkey_resp {
    enum FUNCTION_ID type;
    int result;
	  unsigned char *cert;
    MSF_UINT16 certLen;
    unsigned char *sig;
    int sigLen;
		MSF_UINT8 alg;
  };
#endif


#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  struct wim_st_get_ucert_keyid_resp {
    enum FUNCTION_ID type;
    int result;
	  unsigned char *cert;
    int certLen;
    unsigned char *keyId;
    int keyIdLen;
  };
#endif

struct wim_st_read_views_certs_resp {
  enum FUNCTION_ID type;
  int  result;
	unsigned char *data;
  int len;
};
																		
#ifdef SEC_CFG_CAN_SIGN_TEXT
  struct wim_st_text_signed{
	  enum FUNCTION_ID type;
    int id; 
    int signId; 
    int algorithm; 
    char *signature;
    int sigLen; 
    char *hashedKey;
    int hashedKeyLen;
    char *certificate;
    int certificateLen;
    int certificateType; 
    int err;
  };
#endif

#ifdef SEC_CFG_CAN_SIGN_TEXT
  struct wim_st_get_signtext_matches_resp{
	  enum FUNCTION_ID type;
    int objectId; 
    int signId; 
    int result; 
    int nbrMatches;
    sec_cert_name_t certNames[SEC_USER_CERT_MAX_SIZE];
  };
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
  struct wim_st_get_contracts_resp{
	  enum FUNCTION_ID type;
    int id; 
    int result; 
    int nbrContracts;
    sec_contract_info_t *contracts;
		int *contractsLen;
  };
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
  struct wim_st_store_contracts_resp{
	  enum FUNCTION_ID type;
    int id; 
    int result; 
  };
#endif

#if( (defined(SEC_CFG_CAN_SIGN_TEXT) && defined(SEC_CFG_STORE_CONTRACTS)))
  struct wim_st_delete_contracts_resp{
	  enum FUNCTION_ID type;
    int contractId; 
    int result; 
  };
#endif
		
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
  struct wim_st_pin_resp {
	  enum FUNCTION_ID type;
	  int id;
	  int result;
  };

#ifdef SEC_CFG_PUK
  struct wim_st_verify_puk_resp {
	  enum FUNCTION_ID type;
	  int id;
	  int result;
  };
#endif

#ifdef SEC_CFG_PUK
  struct wim_st_verify_pin_with_puk_resp {
	  enum FUNCTION_ID type;
	  int id;
	  int result;
  };
#endif

#endif 

	struct wim_st_sig_verification_resp{
  enum FUNCTION_ID type;
  int id; 
  int result; 
};






struct st_initialise {
  enum FUNCTION_ID type;
  struct parameterStruct *prev;
  struct parameterStruct *next;
  int id;
};

#endif 
