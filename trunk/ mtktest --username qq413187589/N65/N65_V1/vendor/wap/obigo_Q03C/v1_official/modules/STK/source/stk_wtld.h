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








#ifndef _stk_wtld_h
#define _stk_wtld_h

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif

#ifndef _stk_cfg_h
#include "stk_cfg.h"
#endif

#ifndef _stk_wtls_h
#include "stk_wtls.h"
#endif

#ifndef _stk_sig_h
#include "stk_sig.h"
#endif

#ifndef _sec_if_h
#include "sec_if.h"
#endif

#ifndef _sec_lib_h
#include "sec_lib.h"
#endif




#define STK_WTLS_MAC(alg, bearer, n)    STK_CFG_WTLS_MAC_ ## alg ## _ ## bearer ## _ ## n






#define STK_WTLS_PROTOCOL_VERSION   1


#define STK_WTLS_STATE_NULL                           0x00
#define STK_WTLS_STATE_OPEN                           0x01
#define STK_WTLS_STATE_OPENING                        0x02
#define STK_WTLS_STATE_HANDSHAKE_IN_PROGRESS          0x03
#define STK_WTLS_STATE_TERMINATING                    0x04
#define STK_WTLS_STATE_WAIT_INITIALISE_RESPONSE       0x05
#define STK_WTLS_STATE_WAIT_HELLO_REQUEST             0x06
#define STK_WTLS_STATE_RECEIVED_HELLO_REQUEST         0x07
#define STK_WTLS_STATE_OPENING_NO_DATA                0x08


#define STK_WTLS_STATE_KEY_REFRESH_NULL               0x00
#define STK_WTLS_STATE_KEY_REFRESH_1                  0x01
#define STK_WTLS_STATE_KEY_REFRESH_2                  0x02
#define STK_WTLS_STATE_KEY_REFRESH_3                  0x03





#define STK_WTLS_ALERT_LEVEL_WARNING   1
#define STK_WTLS_ALERT_LEVEL_CRITICAL  2
#define STK_WTLS_ALERT_LEVEL_FATAL     3





#define STK_WTLS_ALERT_DESC_CONNECTION_CLOSE_NOTIFY       0
#define STK_WTLS_ALERT_DESC_SESSION_CLOSE_NOTIFY          1
#define STK_WTLS_ALERT_DESC_NO_CONNECTION                 5
#define STK_WTLS_ALERT_DESC_UNEXPECTED_MESSAGE           10
#define STK_WTLS_ALERT_DESC_TIME_REQUIRED                11
#define STK_WTLS_ALERT_DESC_BAD_RECORD_MAC               20
#define STK_WTLS_ALERT_DESC_DECRYPTION_FAILED            21
#define STK_WTLS_ALERT_DESC_RECORD_OVERFLOW              22
#define STK_WTLS_ALERT_DESC_DECOMPRESSION_FAILURE        30
#define STK_WTLS_ALERT_DESC_HANDSHAKE_FAILURE            40
#define STK_WTLS_ALERT_DESC_BAD_CERTIFICATE              42
#define STK_WTLS_ALERT_DESC_UNSUPPORTED_CERTIFICATE      43
#define STK_WTLS_ALERT_DESC_CERTIFICATE_REVOKED          44
#define STK_WTLS_ALERT_DESC_CERTIFICATE_EXPIRED          45
#define STK_WTLS_ALERT_DESC_CERTIFICATE_UNKNOWN          46
#define STK_WTLS_ALERT_DESC_ILLEGAL_PARAMETER            47
#define STK_WTLS_ALERT_DESC_UNKNOWN_CA                   48
#define STK_WTLS_ALERT_DESC_ACCESS_DENIED                49
#define STK_WTLS_ALERT_DESC_DECODE_ERROR                 50
#define STK_WTLS_ALERT_DESC_DECRYPT_ERROR                51
#define STK_WTLS_ALERT_DESC_UNKNOWN_KEY_ID               52
#define STK_WTLS_ALERT_DESC_DISABLED_KEY_ID              53
#define STK_WTLS_ALERT_DESC_KEY_EXCHANGE_DISABLED        54
#define STK_WTLS_ALERT_DESC_SESSION_NOT_READY            55
#define STK_WTLS_ALERT_DESC_UNKNOWN_PARAMETER_INDEX      56
#define STK_WTLS_ALERT_DESC_DUPLICATE_FINISHED_RECEIVED  57
#define STK_WTLS_ALERT_DESC_EXPORT_RESTRICTION           60
#define STK_WTLS_ALERT_DESC_PROTOCOL_VERSION             70
#define STK_WTLS_ALERT_DESC_INSUFFICIENT_SECURITY        71
#define STK_WTLS_ALERT_DESC_INTERNAL_ERROR               80
#define STK_WTLS_ALERT_DESC_USER_CANCELED                90
#define STK_WTLS_ALERT_DESC_NO_RENEGOTIATION            100




 
typedef struct {
  MSF_UINT8  level;
  MSF_UINT8  description;
  MSF_UINT32 checksum;
} stk_wtls_alert_t;


typedef struct {
  MSF_UINT8         length;
  unsigned char id[8];
} stk_wtls_session_id;


typedef unsigned char stk_wtls_random_t[16];




#define CONTENT_TYPE_EMPTY           0
#define CONTENT_TYPE_CCS             1
#define CONTENT_TYPE_ALERT           2
#define CONTENT_TYPE_HANDSHAKE       3
#define CONTENT_TYPE_DATA            4
#define CONTENT_TYPE_HELLO_REQUEST  10
#define CONTENT_TYPE_ERROR          15


#define RECTYPE_CONTENT_TYPE  0x0f
#define RECTYPE_USE_CS        0x20
#define RECTYPE_SEQNUM        0x40
#define RECTYPE_LENGTH_FIELD  0x80

typedef struct stk_wtls_rec_st {
  struct stk_wtls_rec_st *next;     

  MSF_UINT8          rec_type;  
  MSF_UINT16         seqnum;    
  MSF_UINT16         length;    
  unsigned char *fragment;  
} stk_wtls_record_t;


#define IDENTIFIER_NULL           0
#define IDENTIFIER_TEXT           1
#define IDENTIFIER_BINARY         2
#define IDENTIFIER_KEY_HASH_SHA 254
#define IDENTIFIER_X509_NAME    255

typedef struct {
  MSF_UINT8 identifier_type;
  union {
    struct {
      MSF_UINT16         character_set;
      MSF_UINT8          namelen;
      unsigned char *name;
    } text;
    struct {
      MSF_UINT8          idlen;
      unsigned char *identifier;
    } binary;
    struct {
      unsigned char *key_hash;
    } key_hash_SHA;
    struct {
      MSF_UINT8          namelen;
      unsigned char *distinguished_name;
    } x509_name;
  } _u;
} stk_wtls_identifier_t;


typedef MSF_UINT8 stk_wtls_MAC_algorithm;


#define COMPRESS_NULL           0



#define STK_WTLS_CIPHER_TYPE_STREAM   1
#define STK_WTLS_CIPHER_TYPE_BLOCK    2

typedef struct {
  MSF_UINT8 cipher_alg;
  MSF_UINT8 mac_alg;
} stk_wtls_cipher_suite;

typedef struct {
  MSF_UINT8              key_exchange_suite;
  sec_wtls_param_specifier parameter_specifier;
  stk_wtls_identifier_t  identifier;
} stk_wtls_key_exchange_id;




#define HANDSHK_HELLO_REQUEST           0
#define HANDSHK_CLIENT_HELLO            1
#define HANDSHK_SERVER_HELLO            2
#define HANDSHK_CERTIFICATE            11
#define HANDSHK_SERVER_KEY_EXCHANGE    12
#define HANDSHK_CERTIFICATE_REQUEST    13
#define HANDSHK_SERVER_HELLO_DONE      14
#define HANDSHK_CERTIFICATE_VERIFY     15
#define HANDSHK_CLIENT_KEY_EXCHANGE    16
#define HANDSHK_FINISHED               20
#define HANDSHK_ERROR                  90
#define HANDSHK_EMPTY                  99




typedef struct {
  MSF_UINT8  msg_type;
  MSF_UINT16 length;
} stk_wtls_hello_request, stk_wtls_server_hello_done;

typedef struct {
  MSF_UINT8 msg_type;
  MSF_UINT16           length;
  MSF_UINT8            client_version;
  stk_wtls_random_t    random;
  stk_wtls_session_id  session_id;
  MSF_UINT16           client_key_id_len;
  unsigned char   *client_key_ids;
  MSF_UINT16           trusted_key_id_len;
  unsigned char   *trusted_key_ids;
  MSF_UINT8            cipher_suites_len;
  unsigned char   *cipher_suites;
  MSF_UINT8            num_compression_methods;
  MSF_UINT8            *compression_methods;
  MSF_UINT8            seqnum_mode;
  MSF_UINT8            key_refresh_rate;
} stk_wtls_client_hello;

typedef struct {
  MSF_UINT8  msg_type;
  MSF_UINT16            length;
  MSF_UINT8             server_version;
  stk_wtls_random_t     random;
  stk_wtls_session_id   session_id;
  MSF_UINT8             client_key_id;
  stk_wtls_cipher_suite cipher_suite;
  MSF_UINT8             compression_method;
  MSF_UINT8             seqnum_mode;
  MSF_UINT8             key_refresh_rate;
} stk_wtls_server_hello;

typedef struct {
  MSF_UINT8 msg_type;
  MSF_UINT16         length;
  MSF_UINT16         buflen;
  unsigned char *buf;
} stk_wtls_server_certificate, stk_wtls_client_certificate;

typedef struct {
  MSF_UINT8              msg_type;
  MSF_UINT16             length;
  sec_wtls_param_specifier parameter_specifier;
  sec_wtls_public_key          public_key;
} stk_wtls_server_key_exchange;

typedef struct {
  MSF_UINT8          msg_type;
  MSF_UINT16         length;
  MSF_UINT16         buflen;
  unsigned char *buf;
} stk_wtls_certificate_request;

typedef struct {
  MSF_UINT8          msg_type;
  MSF_UINT16         length;
  union {
    MSF_UINT16       len16;
    MSF_UINT8        len8;
  } buflen;
  unsigned char *buf;
} stk_wtls_client_key_exchange;

typedef struct {
  MSF_UINT8          msg_type;
  MSF_UINT16         length;
  MSF_UINT16         siglen;
  unsigned char *signature;
} stk_wtls_certificate_verify;

typedef struct {
  MSF_UINT8         msg_type;
  MSF_UINT16        length;
  unsigned char verify_data[12];
} stk_wtls_finished;

typedef struct {
  stk_wtls_session_id session_id;
  MSF_UINT8         cipher_alg;
  MSF_UINT8         mac_alg;
  MSF_UINT8         hash_alg;
  MSF_UINT8         compression_alg;
  stk_wtls_random_t client_hello_random;
  stk_wtls_random_t server_hello_random;
  MSF_UINT8         key_refresh_rate;
  MSF_UINT8         seqnum_mode;
  int           master_secret_id;
} stk_wtls_pending_state;


#define MAX_NUM_HANDSHAKE_MESSAGES      11

typedef struct {
  unsigned char *buf;
  MSF_UINT16         buflen;
} stk_wtls_handshake_msg;

#define BIT_CLIENT_HELLO                   0x1
#define BIT_SERVER_HELLO                   0x2
#define BIT_SERVER_CERTIFICATE             0x4
#define BIT_SERVER_KEY_EXCHANGE            0x8
#define BIT_SERVER_CERTIFICATE_REQUEST    0x10
#define BIT_SERVER_HELLO_DONE             0x20
#define BIT_CLIENT_CERTIFICATE            0x40
#define BIT_CLIENT_KEY_EXCHANGE           0x80
#define BIT_CLIENT_CERTIFICATE_VERIFY    0x100
#define BIT_CLIENT_FINISHED              0x200
#define BIT_SERVER_FINISHED              0x400

typedef struct {
  MSF_UINT8                state;
  stk_wtls_pending_state pending;  

  stk_wtls_key_exchange_id key_exch;  
  MSF_UINT8                need_client_key_exchange;
  unsigned char            *key_id;
  MSF_UINT16               key_idlen;
  MSF_UINT8                abortable; 

  MSF_INT32                security_id;
  MSF_UINT8                security_class;


  

  stk_wtls_client_hello        client_hello;
  stk_wtls_server_hello        server_hello;
  stk_wtls_server_certificate  server_certificate;
  stk_wtls_server_key_exchange server_key_exchange;
  stk_wtls_certificate_request certificate_request;
  stk_wtls_server_hello_done   server_hello_done;
  stk_wtls_client_certificate  client_certificate;
  stk_wtls_client_key_exchange client_key_exchange;
  stk_wtls_certificate_verify  certificate_verify;
  stk_wtls_finished            client_finished;
  stk_wtls_finished            server_finished;

  

  stk_wtls_handshake_msg       hm[MAX_NUM_HANDSHAKE_MESSAGES];
  MSF_UINT8                    num_handshake_msgs;
  MSF_UINT32                   msgs;
} stk_wtls_handshake_t;


typedef struct {
  MSF_UINT8 cipher_alg;
  MSF_UINT8 is_exportable;
  MSF_UINT8 type;
  MSF_UINT8 key_material_length;
  MSF_UINT8 key_size;
  MSF_UINT8 iv_size;
  MSF_UINT8 block_size;
} cipher_alg_info_t;

extern const cipher_alg_info_t cipher_alg_info[];

typedef struct {
  MSF_UINT8 mac_alg;
  MSF_UINT8 mac_key_size;
  MSF_UINT8 mac_size;
  MSF_UINT8 full_mac_size;
  MSF_UINT8 mac_block_size;
} mac_alg_info_t;

extern const mac_alg_info_t MAC_alg_info[];


#define CONSTATE_READ            1
#define CONSTATE_WRITE           2


#define SEQNUMMODE_OFF          0
#define SEQNUMMODE_IMPLICIT     1
#define SEQNUMMODE_EXPLICIT     2

#define MAX_SEQNUM             0xffffU  




#define MAX_KEY_SIZE            24      
#define MAX_IV_SIZE              8
#define MAX_HASH_MAC_SIZE       20
#define MAX_HASH_KEY_SIZE       20
#define MAX_HASH_BLOCK_SIZE     64

typedef struct {
  stk_wtls_session_id     session_id;
  unsigned char       mac_secret[MAX_HASH_KEY_SIZE];
  unsigned char       encryption_key[MAX_KEY_SIZE];
  unsigned char       iv[MAX_IV_SIZE];
  stk_wtls_random_t       client_hello_random;
  stk_wtls_random_t       server_hello_random;
  MSF_UINT16              seqnum;             
  MSF_UINT8               key_refresh_rate;   
  MSF_UINT16              last_refresh;     
  MSF_UINT8               use_cipher_spec;  
  MSF_UINT8               cipher_alg;
  stk_wtls_MAC_algorithm  mac_alg;
  MSF_UINT8               hash_alg;
  sec_hash_handle          hash_handle;
  sec_hmac_handle          hmac_handle;
  MSF_UINT8               compression_alg;
  MSF_UINT8               seqnum_mode;
  int                 master_secret_id;
} stk_wtls_connection_state;




typedef struct stk_wtls_connection_st stk_wtls_connection_t;

typedef void stk_wtls_continue_func (stk_wtls_connection_t *conn,
                                 stk_wtls_record_t *rec);

struct stk_wtls_connection_st {
  int            cidx;
  MSF_INT32      object_id;
  int            module;
  long           socket_id;  
  MSF_UINT8      state;
  int            error_code;
  msf_sockaddr_t addr;       

  stk_signal_t  *saved_signals_first;
  stk_signal_t  *saved_signals_last;
  stk_wtls_record_t *saved_rec;

  stk_wtls_record_t *msgs_out;   
  stk_wtls_record_t *msgs_in;    
  stk_wtls_record_t *out_records;    

  MSF_UINT8               key_refresh_state;
  MSF_UINT8               key_refresh_cstate;
  stk_wtls_continue_func *continue_after_key_refresh;

  MSF_UINT8          wait_for_new_state; 



  stk_wtls_handshake_t *handshake;  



  stk_wtls_connection_state read;     
  stk_wtls_connection_state write;    

  MSF_UINT32      read_cksum;         
  MSF_UINT32      write_cksum[4];     
  MSF_UINT16      num_cksums;         

  MSF_UINT32      mask;               


  MSF_UINT8       rcr;
  MSF_UINT8       max_retransmissions;
  MSF_UINT16      retransmission_interval;
  MSF_UINT8       recvd_warnings;
};






int
stk_wtls_cvt_alert (msf_dcvt_t *obj, stk_wtls_alert_t *p);

int
stk_wtls_cvt_identifier (msf_dcvt_t *obj, stk_wtls_identifier_t *p);

int
stk_wtls_cvt_parameter_specifier (msf_dcvt_t *obj, sec_wtls_param_specifier *p);

int
stk_wtls_cvt_public_key (msf_dcvt_t *obj, MSF_UINT8 kes, sec_wtls_public_key *p);

int
stk_wtls_cvt_key_exchange_id (msf_dcvt_t *obj, stk_wtls_key_exchange_id *p);

int
stk_wtls_cvt_client_hello (msf_dcvt_t *obj, stk_wtls_client_hello *p);

int
stk_wtls_cvt_server_hello (msf_dcvt_t *obj, stk_wtls_server_hello *p);

int
stk_wtls_cvt_server_certificate (msf_dcvt_t *obj,
                             stk_wtls_server_certificate *p);

int
stk_wtls_cvt_server_key_exchange (msf_dcvt_t *obj, MSF_UINT8 kes,
                              stk_wtls_server_key_exchange *p);

int
stk_wtls_cvt_certificate_request (msf_dcvt_t *obj,
                              stk_wtls_certificate_request *p);

int
stk_wtls_cvt_server_hello_done (msf_dcvt_t *obj, stk_wtls_server_hello_done *p);

int
stk_wtls_cvt_client_certificate (msf_dcvt_t *obj, stk_wtls_client_certificate *p);

int
stk_wtls_cvt_client_key_exchange (msf_dcvt_t *obj, MSF_UINT8 kes,
                              stk_wtls_client_key_exchange *p);

int
stk_wtls_cvt_certificate_verify (msf_dcvt_t *obj, stk_wtls_certificate_verify *p);

int
stk_wtls_cvt_finished (msf_dcvt_t *obj, stk_wtls_finished *p);

int
stk_wtls_cvt_record (msf_dcvt_t *obj, stk_wtls_record_t *p);





MSF_UINT32
stk_wtls_alert_compute_checksum (unsigned char *msg, MSF_UINT32 msglen);





#define STK_WTLS_CONNECTION_GET(cidx) ((((cidx) < 0) || ((cidx) >= STK_CFG_MAX_CONNECTIONS)) ? NULL : stk_wtls_connection_table[(cidx)])

extern stk_wtls_connection_t *stk_wtls_connection_table[STK_CFG_MAX_CONNECTIONS];

void
stk_wtls_connection_init (void);

void
stk_wtls_connection_terminate (void);

stk_wtls_connection_t *
stk_wtls_connection_new (int cidx);

void
stk_wtls_connection_delete (int cidx);

void
stk_wtls_connection_state_init (stk_wtls_connection_state *cstate);

void
stk_wtls_pending_state_init (stk_wtls_pending_state *pstate);

void
stk_wtls_pending_state_install (stk_wtls_connection_state *cstate,
                            stk_wtls_pending_state *pstate);

void
stk_wtls_install_pending_read (stk_wtls_connection_t *conn);

void
stk_wtls_install_pending_write (stk_wtls_connection_t *conn);





sec_hash_alg
stk_wtls_crypto_MAC_to_hash_alg (stk_wtls_MAC_algorithm alg);

int
stk_wtls_crypto_encrypt (stk_wtls_connection_state *cstate,
                     unsigned char *key, unsigned char *iv,
                     unsigned char *buf, int buflen,
                     unsigned char *outbuf);

int
stk_wtls_crypto_decrypt (stk_wtls_connection_state *cstate,
                     unsigned char *key, unsigned char *iv,
                     unsigned char *buf, int buflen,
                     unsigned char *outbuf);
int
stk_wtls_crypto_hash (stk_wtls_connection_state *cstate,
                  unsigned char *buf, int buflen, unsigned char *digest);

int
stk_wtls_crypto_hash_init (stk_wtls_connection_state *cstate);

int
stk_wtls_crypto_hash_update (stk_wtls_connection_state *cstate,
                         unsigned char *buf, int buflen);

int
stk_wtls_crypto_hash_final (stk_wtls_connection_state *cstate, unsigned char *digest);

int
stk_wtls_crypto_HMAC_init (stk_wtls_connection_state *cstate,
                       unsigned char *key, int keylen);

int
stk_wtls_crypto_HMAC_update (stk_wtls_connection_state *cstate,
                         unsigned char *data, int datalen);

int
stk_wtls_crypto_HMAC_final (stk_wtls_connection_state *cstate, unsigned char *result);

int
stk_wtls_crypto_MAC (stk_wtls_connection_state *cstate, unsigned char *mac_secret,
                 unsigned char *buf, int buflen,
                 MSF_UINT16 seqnum, MSF_UINT8 rec_type,
                 unsigned char *mac);

int
stk_wtls_crypto_needs_key_refresh (stk_wtls_connection_t *conn, stk_wtls_record_t *rec,
                               int state);

void
stk_wtls_crypto_key_refresh_0 (stk_wtls_connection_t *conn, int state);

void
stk_wtls_crypto_key_refresh_1 (stk_wtls_connection_t *conn,
                           unsigned char *buf, int buflen);

void
stk_wtls_crypto_key_refresh_2 (stk_wtls_connection_t *conn,
                           unsigned char *buf, int buflen);

void
stk_wtls_crypto_key_refresh_3 (stk_wtls_connection_t *conn,
                           unsigned char *buf, int buflen);




void
stk_wtls_rec_init (void);

stk_wtls_record_t *
stk_wtls_rec_create_record (MSF_UINT8 content_type, unsigned char *buf, int buflen);

stk_wtls_record_t *
stk_wtls_rec_create_alert (stk_wtls_connection_t *conn,
                       MSF_UINT8 alert_level, MSF_UINT8 alert_desc);

int
stk_wtls_rec_encrypt_record (stk_wtls_connection_t *conn, stk_wtls_record_t *rec);

int
stk_wtls_rec_decrypt_record (stk_wtls_connection_t *conn, stk_wtls_record_t *rec);

int
stk_wtls_rec_needs_key_refresh (stk_wtls_connection_t *conn, stk_wtls_record_t *rec,
                            MSF_UINT8 state);

void
stk_wtls_rec_send_record (stk_wtls_connection_t *conn, stk_wtls_record_t *rec);

void
stk_wtls_rec_send_record_and_buffer (stk_wtls_connection_t *conn, stk_wtls_record_t *rec);

void
stk_wtls_rec_send_buffer (stk_wtls_connection_t *conn);

void
stk_wtls_rec_clear_buffer (stk_wtls_connection_t *conn);

void
stk_wtls_rec_list_append (stk_wtls_record_t *rec, stk_wtls_record_t **rec_list);

void
stk_wtls_rec_list_delete (stk_wtls_record_t **rlist);

stk_wtls_record_t *
stk_wtls_rec_list_pop (stk_wtls_record_t **rec_list);

void
stk_wtls_rec_delete_record (stk_wtls_record_t *rec);

stk_wtls_record_t *
stk_wtls_rec_next_msg (stk_wtls_connection_t *conn);

int
stk_wtls_rec_check_decrypted_record (stk_wtls_connection_t *conn,
                                 stk_wtls_record_t *rec,
                                 stk_wtls_alert_t *alert);




void
stk_wtls_err (stk_wtls_connection_t *conn, int errcode,
          MSF_UINT8 send_alert, MSF_UINT8 alert_level, MSF_UINT8 alert_description);

void
stk_wtls_err_check (stk_wtls_connection_t *conn);

#endif
