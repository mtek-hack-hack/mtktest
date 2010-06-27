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










#ifndef _stk_wtps_h
#define _stk_wtps_h

#ifdef STK_CONFIG_WTP_SAR





MSF_UINT32
stk_wtp_get_uintn (MSF_UINT8 *p, int len);






void
stk_wtp_sar_handle_notify (stk_wtp_transaction_t *tr, int event_type);




void
stk_wtp_create_group (stk_wtp_transaction_t *tr);




void
stk_wtp_sar_send_group(stk_wtp_transaction_t *tr);




void
stk_wtp_delete_group (stk_wtp_transaction_t *tr);






stk_wtp_segment_t *
stk_wtp_get_next_segment (stk_wtp_transaction_t *tr,
                          int *group_done,
                          int *msg_done);





int
stk_wtp_get_and_send_last_segment (stk_wtp_transaction_t *tr);





void
stk_wtp_sar_send_invoke_pdu (stk_wtp_transaction_t *tr, 
                             stk_wtp_segment_t *iseg, int resend);






int
stk_wtp_sar_recv_ack (stk_wtp_transaction_t *tr, void *buf, int buflen);







int
stk_wtp_sar_unpack_ack_pdu (stk_wtp_transaction_t *tr,
                            void *data,
                            int data_len,
                            MSF_UINT32 *delay_time);






void
stk_wtp_sar_unpack_nack_pdu (stk_wtp_transaction_t *tr, void *data, int data_len);






stk_wtp_segment_t *
stk_wtp_next_missing_segment (stk_wtp_transaction_t *tr);




void
stk_wtp_delete_segment (stk_wtp_segment_t *seg);




void
stk_wtp_delete_missing_segments (stk_wtp_transaction_t *tr);

void
stk_wtp_sar_delete_transaction (stk_wtp_transaction_t *tr);







void
stk_wtp_sar_select (int cidx, int request_id);

int
stk_wtp_sar_read (int cidx, int request_id, void *buf, int buflen);






MSF_UINT8
stk_wtp_get_last_recv_seqnum (stk_wtp_transaction_t *tr);




void
stk_wtp_sar_recv_result (int cidx, stk_wtp_transaction_t *tr,
                         void *data, int data_len);






void
stk_wtp_sar_send_ack (stk_wtp_transaction_t *tr, MSF_UINT8 segnum,
                      int resend, int no_tpis);




void
stk_wtp_delete_segment_list (stk_wtp_segment_t *seg);

#endif
#endif
