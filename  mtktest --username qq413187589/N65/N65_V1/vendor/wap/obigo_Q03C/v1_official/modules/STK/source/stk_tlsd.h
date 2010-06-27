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








#ifndef _stk_tlsd_h
#define _stk_tlsd_h

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif

#ifndef _stk_sig_h
#include "stk_sig.h"
#endif

#ifndef _stk_tls_h
#include "stk_tls.h"
#endif

#ifndef _sec_if_h
#include "sec_if.h"
#endif

#ifndef _sec_lib_h
#include "sec_lib.h"
#endif






#define STK_TLS_BUF_SIZE                              1024





#define STK_TLS_PROTOCOL_VERSION_MAJOR                3
#define STK_TLS_PROTOCOL_VERSION_MINOR                1

#define STK_TLS_UINT24 MSF_UINT32




#define STK_TLS_ALERT_LEVEL_WARNING                   1
#define STK_TLS_ALERT_LEVEL_FATAL                     2





#define STK_TLS_ALERT_DESC_CLOSE_NOTIFY               0
#define STK_TLS_ALERT_DESC_UNEXPECTED_MESSAGE         10
#define STK_TLS_ALERT_DESC_BAD_RECORD_MAC             20
#define STK_TLS_ALERT_DESC_DECRYPTION_FAILED          21
#define STK_TLS_ALERT_DESC_RECORD_OVERFLOW            22
#define STK_TLS_ALERT_DESC_DECOMPRESSION_FAILURE      30
#define STK_TLS_ALERT_DESC_HANDSHAKE_FAILURE          40
#define STK_TLS_ALERT_DESC_BAD_CERTIFICATE            42
#define STK_TLS_ALERT_DESC_UNSUPPORTED_CERTIFICATE    43
#define STK_TLS_ALERT_DESC_CERTIFICATE_REVOKED        44
#define STK_TLS_ALERT_DESC_CERTIFICATE_EXPIRED        45
#define STK_TLS_ALERT_DESC_CERTIFICATE_UNKNOWN        46
#define STK_TLS_ALERT_DESC_ILLEGAL_PARAMETER          47
#define STK_TLS_ALERT_DESC_UNKNOWN_CA                 48
#define STK_TLS_ALERT_DESC_ACCESS_DENIED              49
#define STK_TLS_ALERT_DESC_DECODE_ERROR               50
#define STK_TLS_ALERT_DESC_DECRYPT_ERROR              51
#define STK_TLS_ALERT_DESC_EXPORT_RESTRICTION         60
#define STK_TLS_ALERT_DESC_PROTOCOL_VERSION           70
#define STK_TLS_ALERT_DESC_INSUFFICIENT_SECURITY      71
#define STK_TLS_ALERT_DESC_INTERNAL_ERROR             80
#define STK_TLS_ALERT_DESC_USER_CANCELED              90
#define STK_TLS_ALERT_DESC_NO_RENEGOTIATION           100


#define STK_TLS_CIPHER_NULL                           SEC_CIPHER_NULL
#define STK_TLS_CIPHER_IDEA_CBC                       SEC_CIPHER_IDEA_CBC
#define STK_TLS_CIPHER_RC2_CBC_40                     SEC_CIPHER_RC2_CBC_40
#define STK_TLS_CIPHER_RC4_40                         SEC_CIPHER_RC4_40
#define STK_TLS_CIPHER_RC4_128                        SEC_CIPHER_RC4_128
#define STK_TLS_CIPHER_DES40_CBC                      SEC_CIPHER_DES_CBC_40
#define STK_TLS_CIPHER_DES_CBC                        SEC_CIPHER_DES_CBC
#define STK_TLS_CIPHER_3DES_EDE_CBC                   SEC_CIPHER_3DES_CBC_EDE


#define STK_TLS_HASH_NULL                             0
#define STK_TLS_HASH_MD5                              SEC_HASH_MD5
#define STK_TLS_HASH_SHA                              SEC_HASH_SHA


#define STK_TLS_COMPRESSION_NULL                      0


#define STK_TLS_STATE_NULL                            0x00
#define STK_TLS_STATE_OPEN                            0x01
#define STK_TLS_STATE_HANDSHAKE_INITIATED             0x02
#define STK_TLS_STATE_HANDSHAKE_IN_PROGRESS           0x03
#define STK_TLS_STATE_CLOSING                         0x04




#define STK_TLS_FLAG_ESTABLISHED                      0x01

#define STK_TLS_INPUT_STATE_START                     1
#define STK_TLS_INPUT_STATE_READING_HEADER            2
#define STK_TLS_INPUT_STATE_READING_DATA              3
#define STK_TLS_INPUT_STATE_WAIT_CCS_PROCESSED        4
#define STK_TLS_INPUT_STATE_WAIT_HTTP_READY           5

#define STK_TLS_RECORD_HEADER_SIZE                    5
#define STK_TLS_HANDSHAKE_HEADER_SIZE                 4


#define STK_TLS_CONTENT_TYPE_CCS                      20
#define STK_TLS_CONTENT_TYPE_ALERT                    21
#define STK_TLS_CONTENT_TYPE_HANDSHAKE                22
#define STK_TLS_CONTENT_TYPE_DATA                     23




#define STK_TLS_HANDSHK_HELLO_REQUEST                 0
#define STK_TLS_HANDSHK_CLIENT_HELLO                  1
#define STK_TLS_HANDSHK_SERVER_HELLO                  2
#define STK_TLS_HANDSHK_CERTIFICATE                   11
#define STK_TLS_HANDSHK_SERVER_KEY_EXCHANGE           12
#define STK_TLS_HANDSHK_CERTIFICATE_REQUEST           13
#define STK_TLS_HANDSHK_SERVER_HELLO_DONE             14
#define STK_TLS_HANDSHK_CERTIFICATE_VERIFY            15
#define STK_TLS_HANDSHK_CLIENT_KEY_EXCHANGE           16
#define STK_TLS_HANDSHK_FINISHED                      20




#define STK_TLS_FLAG_FULL_HANDSHAKE                   0x01
#define STK_TLS_FLAG_NEED_CERT_VERIFY                 0x02
#define STK_TLS_FLAG_IS_SSL                           0x04
#define STK_TLS_FLAG_SSL_CLIENT_HELLO                 0x08


#define MAX_NUM_HANDSHAKE_MESSAGES                11



#define BIT_CLIENT_HELLO                          0x1
#define BIT_SERVER_HELLO                          0x2
#define BIT_SERVER_CERTIFICATE                    0x4
#define BIT_SERVER_KEY_EXCHANGE                   0x8
#define BIT_SERVER_CERTIFICATE_REQUEST            0x10
#define BIT_SERVER_HELLO_DONE                     0x20
#define BIT_CLIENT_CERTIFICATE                    0x40
#define BIT_CLIENT_KEY_EXCHANGE                   0x80
#define BIT_CLIENT_CERTIFICATE_VERIFY             0x100
#define BIT_CLIENT_FINISHED                       0x200
#define BIT_SERVER_FINISHED                       0x400




#define STK_TLS_MAX_KEY_SIZE                          24
#define STK_TLS_MAX_IV_SIZE                           8
#define STK_TLS_MAX_HASH_SIZE                         20
#define STK_TLS_MAX_HASH_KEY_SIZE                     20
#define STK_TLS_MAX_HASH_BLOCK_SIZE                   64




#define STK_TLS_CIPHER_TYPE_STREAM   1
#define STK_TLS_CIPHER_TYPE_BLOCK    2






#define STK_TLS_CONNECTION_GET(cidx) ((((cidx) < 0) || ((cidx) >= STK_CFG_MAX_CONNECTIONS)) ? NULL : stk_tls_connection_table[(cidx)])







typedef struct {
  MSF_UINT8          length;
  unsigned char  id[32];
} stk_tls_session_id_t;

typedef unsigned char stk_tls_random_t[32];

typedef struct {
  MSF_UINT8 major;
  MSF_UINT8 minor;
} stk_tls_protocol_version_t;

typedef struct stk_tls_record_st {
  struct stk_tls_record_st  *next;      

  MSF_UINT32                 seqnum;
  MSF_UINT8                  content_type;
  stk_tls_protocol_version_t protocol_version;
  MSF_UINT16                 length;    
  unsigned char             *fragment;  
} stk_tls_record_t;

typedef unsigned char stk_tls_cipher_suite_t[2];




typedef struct {
  stk_tls_protocol_version_t client_version;
  stk_tls_random_t           random;
  stk_tls_session_id_t       session_id;
  MSF_UINT16                 cipher_suites_len;
  unsigned char             *cipher_suites;
  MSF_UINT8                  num_compression_methods;
  MSF_UINT8                  compression_methods[1];
} stk_tls_client_hello_t;

typedef struct {
  stk_tls_protocol_version_t server_version;
  stk_tls_random_t           random;
  stk_tls_session_id_t       session_id;
  stk_tls_cipher_suite_t     cipher_suite;
  MSF_UINT8                  compression_method;
} stk_tls_server_hello_t;

typedef struct {
  MSF_UINT8                 num_certificates;
  sec_tls_asn1_certificate *certificates;
} stk_tls_server_certificate_t;

typedef struct {
  sec_tls_key_exch_params params;
} stk_tls_server_key_exchange_t;

typedef struct {
  MSF_UINT8                   num_certificate_types;
  unsigned char              *certificate_types;
  MSF_UINT16                  num_certificate_authorities;
  sec_tls_distinguished_name *certificate_authorities;
} stk_tls_certificate_request_t;

typedef struct {
  MSF_UINT8                 num_certificates;
  sec_tls_asn1_certificate *certificates;
} stk_tls_client_certificate_t;

typedef struct {
  MSF_UINT16         siglen;
  unsigned char     *signature;
} stk_tls_certificate_verify_t;

typedef struct {
  MSF_UINT16 cipher_suite;
  MSF_UINT8  is_exportable;
  MSF_UINT8  key_exchange_method;
  MSF_UINT8  cipher_alg;
  MSF_UINT8  hash_alg;
} stk_tls_cipher_suite_info_t;

typedef struct {
  MSF_UINT8 cipher_alg;
  MSF_UINT8 is_exportable;
  MSF_UINT8 type;
  MSF_UINT8 key_material_length;
  MSF_UINT8 key_size;
  MSF_UINT8 iv_size;
  MSF_UINT8 block_size;
} stk_tls_cipher_info_t;

typedef struct {
  MSF_UINT8 hash_alg;
  MSF_UINT8 hash_size;
  MSF_UINT8 whatever;
} stk_tls_hash_info_t;

typedef struct {
  MSF_UINT8                     state;

  MSF_UINT8                     flags;
  stk_tls_random_t              client_random;
  stk_tls_random_t              server_random;
  stk_tls_session_id_t          session_id;
  MSF_UINT16                    cipher_suites_len;
  unsigned char                *cipher_suites;
  unsigned char                *pub_key_hash;
  MSF_UINT8                     key_exchange_method;
  MSF_UINT16                    cipher_suite;
  stk_tls_server_certificate_t  server_certificate;
  stk_tls_server_key_exchange_t server_key_exchange;
  stk_tls_certificate_request_t certificate_request;
  unsigned char                *key_exch_pub_value;
  MSF_UINT16                    key_exch_pub_value_len;
  unsigned char                 server_verify_data[12];
  MSF_UINT8                     security_class;
  MSF_INT32                     security_id;

  

  sec_hash_handle               client_md5_handle;
  sec_hash_handle               client_sha_handle;
  sec_hash_handle               server_md5_handle;
  sec_hash_handle               server_sha_handle;
  sec_hash_handle               verify_md5_handle;
  sec_hash_handle               verify_sha_handle;

  
  MSF_UINT32                    msgs;
} stk_tls_handshake_t;

typedef struct {
  MSF_UINT8                 cipher_alg;
  MSF_UINT8                 hash_alg;
  MSF_UINT8                 hash_size;
  MSF_UINT8                 compression_alg;
  int                       master_secret_id;
  unsigned char             mac_secret[STK_TLS_MAX_HASH_KEY_SIZE];
  unsigned char             encryption_key[STK_TLS_MAX_KEY_SIZE];
  unsigned char             iv[STK_TLS_MAX_IV_SIZE];
  sec_cipher_handle         cipher_handle;
  MSF_UINT32                seqnum;
} stk_tls_connection_state_t;




typedef struct stk_tls_connection_st {
  int                 cidx;
  MSF_INT32           object_id;
  int                 channel_id;
  long                socket_id;
  MSF_UINT8           state;
  MSF_UINT8           flags;
  int                 dst_in_stk; 


  stk_tls_record_t    recv_rec;     
  stk_tls_record_t   *send_recs;    

  MSF_UINT8           tcp_send_ready;
  MSF_UINT8           http_recv_select;
  MSF_UINT8           http_send_processing;
  MSF_UINT8           http_send_select;
  MSF_UINT16          recv_rec_start_pos;
                      
  
  MSF_UINT8           input_state;
  int                 input_bytes_required;
  int                 input_bytes_read;
  unsigned char      *input_buf;
  int                 input_bytes_left;
  int                 input_buf_pos;
  int                 data_source;
                      
  unsigned char      *output_buf;
  int                 output_bytes_left;
  int                 output_buf_pos;

  unsigned char       input_header_buf[STK_TLS_RECORD_HEADER_SIZE];
  stk_signal_t       *saved_signals_first;
  stk_signal_t       *saved_signals_last;

  
  MSF_UINT8           hm_input_state;
  int                 hm_input_bytes_required;
  int                 hm_input_bytes_read;
  unsigned char       hm_input_header_buf[4];
  unsigned char      *hm_input_msg;
  STK_TLS_UINT24      hm_input_msg_len;

  stk_tls_protocol_version_t  protocol_version;
  stk_tls_handshake_t        *handshake;  


  stk_tls_connection_state_t  read;       
  stk_tls_connection_state_t  write;      
  stk_tls_connection_state_t *pending_read;  
  stk_tls_connection_state_t *pending_write;
} stk_tls_connection_t;






extern stk_tls_connection_t *stk_tls_connection_table[STK_CFG_MAX_CONNECTIONS];






void
stk_tls_rec_list_delete (stk_tls_record_t **rlist);




int
stk_tls_cvt_uint24 (msf_dcvt_t *obj, STK_TLS_UINT24 *p);

int
stk_tls_cvt_client_hello (msf_dcvt_t *obj, stk_tls_client_hello_t *p);

int
stk_tls_cvt_server_hello (msf_dcvt_t *obj, stk_tls_server_hello_t *p);

int
stk_tls_cvt_server_certificate (msf_dcvt_t *obj, stk_tls_server_certificate_t *p);

int
stk_tls_cvt_server_key_exchange (msf_dcvt_t *obj, int key_exchange_algorithm,
                             stk_tls_server_key_exchange_t *p);

int
stk_tls_cvt_certificate_request (msf_dcvt_t *obj,
                             stk_tls_certificate_request_t *p);

int
stk_tls_cvt_client_certificate (msf_dcvt_t *obj, stk_tls_client_certificate_t *p);

int
stk_tls_cvt_certificate_verify (msf_dcvt_t *obj, stk_tls_certificate_verify_t *p);

int
stk_tls_cvt_record (msf_dcvt_t *obj, stk_tls_record_t *p);





void
stk_tls_connection_init (void);

void
stk_tls_connection_terminate (void);

stk_tls_connection_t *
stk_tls_connection_new (int cidx);

void
stk_tls_connection_delete (int cidx);

void
stk_tls_connection_state_init (stk_tls_connection_state_t *cstate);





const stk_tls_cipher_suite_info_t *
stk_tls_crypto_find_cipher_suite (MSF_UINT16 cipher_suite);

const stk_tls_cipher_info_t *
stk_tls_crypto_find_cipher (int cipher_alg);

const stk_tls_hash_info_t *
stk_tls_crypto_find_hash (int hash_alg);

#endif
