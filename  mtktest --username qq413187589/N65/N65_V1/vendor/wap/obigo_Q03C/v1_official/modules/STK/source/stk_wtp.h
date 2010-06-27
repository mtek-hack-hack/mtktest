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
#ifndef _stk_wtp_h
#define _stk_wtp_h

#ifdef STK_CONFIG_WTP






#define STK_WTP_TRANSACTION_CLASS_0     0
#define STK_WTP_TRANSACTION_CLASS_1     1
#define STK_WTP_TRANSACTION_CLASS_2     2







#define STK_WTP_SIG_INVOKE_REQ              STK_MODULE_WTP + 0
#define STK_WTP_SIG_INVOKE_RES              STK_MODULE_WTP + 1
#define STK_WTP_SIG_RESULT_RES              STK_MODULE_WTP + 2
#define STK_WTP_SIG_ABORT_REQ               STK_MODULE_WTP + 3
#define STK_WTP_SIG_ACK_REQ                 STK_MODULE_WTP + 4











#define STK_WTP_SIG_INVOKE_CNF              STK_MODULE_WTP + 5
#define STK_WTP_SIG_INVOKE_IND              STK_MODULE_WTP + 6
#define STK_WTP_SIG_RESULT_IND              STK_MODULE_WTP + 7
#define STK_WTP_SIG_ABORT_IND               STK_MODULE_WTP + 8
#define STK_WTP_SIG_ACK_IND                 STK_MODULE_WTP + 9














typedef struct {
  int   request_id;
  int   ack_type;      
  int   tr_class;      
  char *data;
  int   datalen;
  int   offset;        
} stk_wtp_invoke_ind_t;

typedef struct {
  int        request_id;
  int        ack_type;      
  MSF_UINT8  tr_class;      
  char      *data;
  int        datalen;
  int        datasource;
} stk_wtp_invoke_req_t;

typedef struct {
  int   request_id;
  char *data;          
  int   datalen;       
  int   offset;        
  int   segmented_result;
} stk_wtp_result_ind_t;









void
stk_wtp_init (void);




void
stk_wtp_terminate (void);




void
stk_wtp_delete_connection (int cidx);




void
stk_wtp_recv_error (int cidx, stk_wtp_transaction_t *tr, int error_code);




void
stk_wtp_send_pdu (stk_cmgr_connection_t *conn, void *buf, int buflen);




void
stk_wtp_send_ack_pdu (int cidx, stk_wtp_transaction_t *tr, int tidve, int resend);




void
stk_wtp_send_invoke_pdu (int cidx, stk_wtp_transaction_t *tr, int resend);




void
stk_wtp_generate_result_ind (int cidx, stk_wtp_transaction_t *tr,
                             void *data, int datalen, int offset,
                             int segmented_result);




void
stk_wtp_generate_invoke_cnf (int cidx, stk_wtp_transaction_t *tr);




void
stk_wtp_generate_abort_ind (int cidx, int request_id, int abort_code);




void
stk_wtp_tr_delete (int cidx, stk_wtp_transaction_t *tr);




void
stk_wtp_tr_wait_timeout (stk_wtp_transaction_t *tr);

stk_wtp_transaction_t *
stk_wtp_tr_find_by_datasource (int cidx, int datasource);







stk_wtp_transaction_t *
stk_wtp_tr_find_by_request_id (int cidx, int request_id);

#endif
#endif
